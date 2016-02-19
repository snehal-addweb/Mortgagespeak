<?php

/**
 * @file
 * Helper functions.
 */

/**
 * Ad campaign types.
 * Used in ad campaign type field.
 */
function _simpleads_campaigns_types() {

  $types = array(
    'impressions' => t('Impressions'),
    'clicks' => t('Clicks'),
    'date' => t('Date'),
  );

  drupal_alter('ad_campaign_types', $types);

  return $types;

}

/**
 * Ad campaigns.
 */
function _simpleads_campaigns_list() {

  $campaigns = array();

  $result = db_query("SELECT
      n.nid,
      n.title,
      IFNULL(c.field_adcamp_clicks_value, 0) AS clicks,
      IFNULL(i.field_adcamp_impressions_value, 0) AS impressions,
      d.field_adcamp_date_value AS date1,
      d.field_adcamp_date_value2 AS date2
    FROM {node} n
    LEFT JOIN {field_data_field_adcamp_impressions} i ON i.entity_id = n.nid
    LEFT JOIN {field_data_field_adcamp_clicks} c ON c.entity_id = n.nid
    LEFT JOIN {field_data_field_adcamp_date} d ON d.entity_id = n.nid
    WHERE n.type = 'simpleads_campaigns' ORDER BY n.nid");

  foreach ( $result as $row ) {

    $campaigns[$row->nid] = array(
      'nid' => $row->nid,
      'title' => $row->title,
      'clicks' => $row->clicks,
      'impressions' => $row->impressions,
      'date1' => $row->date1,
      'date2' => $row->date2,
    );
  }

  drupal_alter('ad_campaigns_list', $campaigns);

  return $campaigns;

}

/**
 * Get ad campaigns list
 * We need this to display title and nid only.
 * Used in Simpleads Campaigns dropdown list.
 */
function _simpleads_field_adcamp_list() {

  $campaigns = _simpleads_campaigns_list();
  $result = array();
  foreach ($campaigns as $nid => $info) {
    $result[$nid] = check_plain($info['title']);
  }

  return $result;

}
