<?php

/**
 * @file
 * SimpleAds cron.
 */

/**
 * Implements hook_cron().
 */
function simpleads_cron() {

  // Aggregate impression statistics.
  $result = db_query("SELECT
      UNIX_TIMESTAMP(FROM_UNIXTIME(s.timestamp, '%Y%m%d')) AS date,
      s.nid, COUNT(*) AS all_count,
      COUNT(DISTINCT s.ip_address) AS unique_count
    FROM {simpleads_impressions} s
    WHERE FROM_UNIXTIME(s.timestamp, '%Y-%m-%d') BETWEEN CURDATE() - INTERVAL 1 DAY AND CURDATE() - INTERVAL 1 SECOND
    GROUP BY date, s.nid");

  $nids = array();

  foreach ( $result as $row ) {

    db_insert('simpleads_stats')
    ->fields(array(
      'nid' => $row->nid,
      'date' => $row->date,
      'clicks' => 0,
      'clicks_unique' => 0,
      'impressions' => $row->all_count,
      'impressions_unique' => $row->unique_count,
    ))
    ->execute();

    if ( !in_array($row->nid, $nids) ) {
      $nids[] = $row->nid;
    }

  }

  // Aggregate click statistics.
  $result = db_query("SELECT
      UNIX_TIMESTAMP(FROM_UNIXTIME(s.timestamp, '%Y%m%d')) as date,
      s.nid,
      COUNT(*) as all_count,
      COUNT(DISTINCT s.ip_address) as unique_count
    FROM {simpleads_clicks} s
    WHERE FROM_UNIXTIME(s.timestamp, '%Y-%m-%d') BETWEEN CURDATE() - INTERVAL 1 DAY AND CURDATE() - INTERVAL 1 SECOND
    GROUP BY date, s.nid");

  foreach ( $result as $row ) {

    db_update('simpleads_stats')
    ->fields(array(
      'clicks' => $row->all_count,
      'clicks_unique' => $row->unique_count,
    ))
    ->condition('date', $row->date)
    ->condition('nid', $row->nid)
    ->execute();

    if ( !in_array($row->nid, $nids) ) {
      $nids[] = $row->nid;
    }

  }

  // Delete already aggregated statistics.
  if ( count($nids) ) {

    db_delete('simpleads_impressions')
    ->condition('nid', $nids, 'IN')
    ->execute();

    db_delete('simpleads_clicks')
    ->condition('nid', $nids, 'IN')
    ->execute();

  }

  // Load all advertisement nodes.
  $advertisement_nodes = db_query("SELECT n.nid FROM {node} n WHERE n.type = 'simpleads' ORDER BY n.created ASC");

  foreach ( $advertisement_nodes as $row ) {

    // Load advertisement node object.
    $node = node_load($row->nid);

    // Check if this advertisement assigned to a campaign and ignore publishing/unpublishing dates.
    if ( module_exists('simpleads_campaigns') && isset($node->field_adcamp_list[$node->language]) ) {

      // Load campaign node object.
      $campaign = node_load($node->field_adcamp_list[$node->language][0]['value']);

      if ( isset($campaign->field_adcamp_type[$campaign->language]) && !empty($campaign->field_adcamp_type[$campaign->language][0]['value']) ) {

        foreach ( $campaign->field_adcamp_type[$campaign->language] as $i => $data ) {

          $type = $data['value'];

          // Check impressions limit per campaign.
          if ( $type == 'impressions' ) {

            $impressions_limit = 0;
            if ( isset($campaign->field_adcamp_impressions[$campaign->language]) && !empty($campaign->field_adcamp_impressions[$campaign->language][0]['value']) ) {
              $impressions_limit = $campaign->field_adcamp_impressions[$campaign->language][0]['value'];
            }

            if ($node->simpleads->impressions >= $impressions_limit && $impressions_limit > 0 && $node->status == 1) {
              // Trigger all hook_simpleads_expired() hooks.
              module_invoke_all('simpleads_expired', $node);
              // Trigger all hook_simpleads_campgaign_complete() hooks.
              module_invoke_all('simpleads_campaign_complete', $node, $campaign);
            }

          }
          // Check clicks limit per campaign.
          elseif ( $type == 'clicks' ) {

            $clicks_limit = 0;
            if ( isset($campaign->field_adcamp_clicks[$campaign->language]) && !empty($campaign->field_adcamp_clicks[$campaign->language][0]['value']) ) {
              $impressions_limit = $campaign->field_adcamp_clicks[$campaign->language][0]['value'];
            }

            if ($node->simpleads->clicks >= $clicks_limit && $clicks_limit > 0 && $node->status == 1) {
              // Trigger all hook_simpleads_expired() hooks.
              module_invoke_all('simpleads_expired', $node);
              // Trigger all hook_simpleads_campgaign_complete() hooks.
              module_invoke_all('simpleads_campaign_complete', $node, $campaign);
            }

          }
          // Check campaign dates.
          elseif ( $type == 'date' ) {

            // Publish scheduled advertisement.

            $result = db_query("SELECT d.entity_id FROM {field_data_field_adcamp_date} d
              WHERE d.field_adcamp_date_value < d.field_adcamp_date_value2
                AND d.field_adcamp_date_value2 < NOW()
                AND d.field_adcamp_date_value > NOW()
                AND d.entity_id = :nid", array(':nid' => $node->nid))
              ->fetchObject();

            if ( isset($result->entity_id) && !empty($result->entity_id) && $node->status == 0 ) {
              // Trigger all hook_simpleads_activate() hooks.
              module_invoke_all('simpleads_activate', $node);
            }

            // Unpublish if the ad expired.

            $result = db_query("SELECT d.entity_id FROM {field_data_field_adcamp_date} d
              WHERE d.field_adcamp_date_value < d.field_adcamp_date_value2
                AND d.field_adcamp_date_value2 < NOW()
                AND d.entity_id = :nid", array(':nid' => $node->nid))
              ->fetchObject();

            if ( isset($result->entity_id) && !empty($result->entity_id) && $node->status == 1 ) {
              // Trigger all hook_simpleads_expired() hooks.
              module_invoke_all('simpleads_expired', $node);
              // Trigger all hook_simpleads_campgaign_complete() hooks.
              module_invoke_all('simpleads_campaign_complete', $node, $campaign);
            }

          }

        }

      }

    }
    // Check publishing/unpublishing dates.
    else {

      // Publish scheduled advertisement.

      $result = db_query("SELECT d.entity_id FROM {field_data_field_ad_date} d
        WHERE d.field_ad_date_value < d.field_ad_date_value2
          AND d.field_ad_date_value2 < NOW()
          AND d.field_ad_date_value > NOW()
          AND d.entity_id = :nid", array(':nid' => $node->nid))
        ->fetchObject();

      if ( isset($result->entity_id) && !empty($result->entity_id) && $node->status == 0 ) {
        // Trigger all hook_simpleads_activate() hooks.
        module_invoke_all('simpleads_activate', $node);
      }

      // Unpublish if the ad expired.

      $result = db_query("SELECT d.entity_id FROM {field_data_field_ad_date} d
        WHERE d.field_ad_date_value < d.field_ad_date_value2
          AND d.field_ad_date_value2 < NOW()
          AND d.entity_id = :nid", array(':nid' => $node->nid))
        ->fetchObject();

      if ( isset($result->entity_id) && !empty($result->entity_id) && $node->status == 1 ) {
        // Trigger all hook_simpleads_expired() hooks.
        module_invoke_all('simpleads_expired', $node);
      }

    }

  }

}
