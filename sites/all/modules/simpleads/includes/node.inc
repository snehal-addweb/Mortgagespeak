<?php

/**
 * @file
 * SimpleAds node.
 */

/**
 * Implements hook_node_info().
 */
function simpleads_node_info() {
  return array(
    'simpleads' => array(
      'title_label' => t('Title'),
      'name' => t('Advertisement'),
      'base' => 'simpleads',
      'description' => t('Advertisements can be randomly displayed to visitors of your website.'),
    ),
  );
}

/**
 * Implements hook_form().
 */
function simpleads_form($node, $form_state) {
  return node_content_form($node, $form_state);
}

/**
 * Implements hook_node_access().
 */
function simpleads_node_access($node, $op, $account) {
  if (isset($node->type) && $node->type == 'simpleads' && $op == 'view' && !user_access('access advertisement node', $account)) {
    return NODE_ACCESS_DENY;
  }
}

/**
 * Implements hook_node_load().
 */
function simpleads_node_load($nodes, $types) {

  foreach ( $nodes as $node ) {
    if ($node->type == 'simpleads') {

      $stats = new stdClass();
      $s = simpleads_load_stats($node->nid);
      $sp = simpleads_pure_stats($node->nid);

      // All time clicks.
      $stats->clicks = $s->unique_clicks + $sp->unique_clicks;

      // All time impressions.
      $stats->impressions = $s->unique_impressions + $sp->unique_impressions;

      $click_though_rate = 0;
      if ( $stats->clicks > 0 && $stats->impressions > 0 ) {
        $click_though_rate = ( $stats->clicks / $stats->impressions ) * 100;
      }

      // Click-through rate.
      $stats->ctr = number_format($click_though_rate, 4, '.', '');

      $node->simpleads = $stats;

    }
  }

}

/**
 * Implements hook_node_presave().
 */
function simpleads_node_presave($node) {

  // Make sure this advertisement not in campaign.
  if ( !isset($node->field_adcamp_list[$node->language][0]) ) {

    if ( isset($node->field_ad_date[$node->language]) && isset($node->field_ad_date[$node->language][0]) ) {

      // Advertisement start date.
      $start_date = strtotime($node->field_ad_date[$node->language][0]['value']);
      // Advertisetment end date.
      $end_date = strtotime($node->field_ad_date[$node->language][0]['value2']);
      // Show end date indicator.
      $show_to_date = isset($node->field_ad_date[$node->language][0]['show_todate']) ? $node->field_ad_date[$node->language][0]['show_todate'] : FALSE;

      // Change node status if start date already occured.
      if ( $start_date < REQUEST_TIME && $node->status == 0 ) {
        $node->status = 1;
      }

      // If advertisement start date in the future, unpublish it and wait when the start date occurs.
      if ( $start_date > REQUEST_TIME && $node->status == 1 ) {
        $node->status = 0;
      }

      // Unpublish advertisement if end date occured.
      if ( $end_date < REQUEST_TIME && $node->status == 1 && $show_to_date ) {
        $node->status = 0;
      }

    }

  }

}

/**
 * Implements hook_form_FORM_ID_alter().
 * Main node form.
 */
function simpleads_form_simpleads_node_form_alter(&$form, &$form_state, $form_id) {

  $form['#attached']['js'][] = drupal_get_path('module', 'simpleads') . '/js/node.js';
  $form['#attached']['css'][] = drupal_get_path('module', 'simpleads') . '/css/node.css';

  $form['field_ad_category']['#weight'] = -4;
  $form['field_ad_type']['#weight'] = -2;
  $form['field_ad_image']['#weight'] = 2;
  $form['field_ad_flash']['#weight'] = 4;
  $form['field_ad_text']['#weight'] = 6;
  $form['field_ad_url']['#weight'] = 8;
  $form['field_ad_date']['#weight'] = 10;

}
