<?php

/**
 * @file
 * simpleads.pages.inc
 */

/**
 * Advertisement statistics page.
 */
function simpleads_node_stats_tab($node) {

  $output = "";

  if ( module_exists('flot') && variable_get('simpleads_display_graphs', 1)) {

    module_load_include('inc', 'simpleads', 'includes/flot');

    //$output .= simpleads_individual_stats_flot();

  }

  $output .= views_embed_view('advertisements', 'individual_statistics_block', $node->nid);

  return $output;

}

/**
 * Count clicks.
 */
function simpleads_node_stats_count_clicks($node) {

  drupal_page_is_cacheable(FALSE);

  $ip_address = ip_address();

  if ( !_simpleads_is_bot_detected() && _simpleads_is_valid_referer()) {

    module_invoke_all('insert_click', $node, $ip_address);

    db_insert('simpleads_clicks')
    ->fields(array(
      'nid' => $node->nid,
      'timestamp' => REQUEST_TIME,
      'ip_address' => $ip_address,
    ))
    ->execute();

  }

  exit;

}

/**
 * Count impressions.
 */
function simpleads_node_stats_count_impressions($node) {

  drupal_page_is_cacheable(FALSE);

  $ip_address = ip_address();

  if ( !_simpleads_is_bot_detected() && _simpleads_is_valid_referer() ) {

    module_invoke_all('insert_impression', $node, $ip_address);

    db_insert('simpleads_impressions')
    ->fields(array(
      'nid' => $node->nid,
      'timestamp' => REQUEST_TIME,
      'ip_address' => $ip_address,
    ))
    ->execute();

  }

  exit;

}

/**
 * Redirect
 */
function simpleads_node_stats_redirect($node) {

  drupal_page_is_cacheable(FALSE);

  if ( isset($node->field_ad_url[LANGUAGE_NONE]) ) {
    $url = link_cleanup_url($node->field_ad_url[LANGUAGE_NONE][0]['url']);
    drupal_goto($url);
  }

}