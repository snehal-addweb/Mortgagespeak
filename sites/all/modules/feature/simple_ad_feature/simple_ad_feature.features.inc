<?php
/**
 * @file
 * simple_ad_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function simple_ad_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function simple_ad_feature_node_info() {
  $items = array(
    'alpha_content' => array(
      'name' => t('Alpha-Content'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
