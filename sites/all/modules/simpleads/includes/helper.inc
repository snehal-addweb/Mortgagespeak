<?php

/**
 * @file
 * Helper functions.
 */

/**
 * Ad types.
 * Used in ad type field.
 */
function _simpleads_ad_types() {

  $types = array(
    'graphic' => t('Image advertisement'),
    'text' => t('Text advertisement'),
    'flash' => t('Flash advertisement'),
  );

  drupal_alter('simpleads_types', $types);

  return $types;

}

/**
 * Load aggregated advertisement statistics.
 */
function simpleads_load_stats($nid) {

  $result = db_query("SELECT
    SUM(s.clicks) AS clicks,
    SUM(s.clicks_unique) AS unique_clicks,
    SUM(s.impressions) AS impressions,
    SUM(s.impressions_unique) AS unique_impressions
    FROM {simpleads_stats} s
    WHERE s.nid = :nid", array(':nid' => $nid))
  ->fetchObject();

  return $result;

}

/**
 * Load non-aggregated advertisement statistics.
 */
function simpleads_pure_stats($nid) {

  $result = db_query("SELECT
    COUNT(si.nid) AS impressions,
    COUNT(DISTINCT si.ip_address) AS unique_impressions,
    COUNT(sc.nid) AS clicks,
    COUNT(DISTINCT sc.ip_address) AS unique_clicks
    FROM {simpleads_impressions} si
    JOIN {simpleads_clicks} sc ON sc.nid = si.nid
    WHERE si.nid = :nid", array(':nid' => $nid))
  ->fetchObject();

  return $result;

}

/**
 * Check advertisement active dates.
 */
function _simpleads_ad_dates($date1, $date2, $entity_status = NULL) {

  $result = "";
  $current_timestamp = REQUEST_TIME;

  $status = $entity_status ? t('Active') . ', ' : t('Inactive') . ', ';
  $status = '<em>' . $status . '</em>';

  if ( empty($date1) || $date1 == $date2 ) {
    $timestamp = strtotime($date1);
    if ( $timestamp > $current_timestamp ) {
      $result = t('!status starting on <b>!start-date</b>', array('!status' => $status, '!start-date' => $date1));
    }
    else {
      $result = t('!status Expired on <b>!start-date</b>', array('!status' => $status, '!start-date' => $date1));
    }
  }
  else {
    $timestamp1 = strtotime($date1);
    $timestamp2 = strtotime($date2);
    if ( $timestamp1 > $current_timestamp && $current_timestamp < $timestamp2 ) {
      $result = t('!status starts on <b>!start-date</b> and expires on <b>!end-date</b>', array('!status' => $status, '!start-date' => $date1, '!end-date' => $date2));
    }
    elseif ( $timestamp1 < $current_timestamp && $current_timestamp < $timestamp2 ) {
      $result = t('!status started on <b>!start-date</b> and expires on <b>!end-date</b>', array('!status' => $status, '!start-date' => $date1, '!end-date' => $date2));
    }
    else {
      $result = t('!status Expired on <b>!end-date</b>', array('!status' => $status, '!start-date' => $date1, '!end-date' => $date2));
    }
  }

  return $result;

}

/**
 * Get advertisement groups.
 */
function _simpleads_get_groups() {

  $groups = array();

  $vocabulary_vid = db_select('taxonomy_vocabulary', 'tv')
  ->fields('tv', array('vid'))
  ->condition('machine_name', 'simpleads_groups')
  ->execute()
  ->fetchField();

  $terms = db_select('taxonomy_term_data', 't')
  ->fields('t')
  ->condition('t.vid', $vocabulary_vid)
  ->orderBy('t.name', 'ASC')
  ->execute();

  foreach ( $terms as $term ) {
    $groups[$term->tid] = check_plain($term->name);
  }

  return $groups;

}

/**
 * Get all available Views and make sure a display has style plugin = SimpleAds.
 */
function _simpleads_get_views_list() {

  $result = array();

  $views = views_get_all_views();

  foreach ( $views as $view ) {
    $style_found = FALSE;
    foreach ( $view->display as $display_id => $display ) {
      if ( isset($display->display_options['style_plugin']) && $display->display_options['style_plugin'] == 'simpleads' ) {
        $style_found = TRUE;
      }
    }
    if ( $style_found ) {
      $result[$view->name] = check_plain($view->human_name);
    }
  }

  if ( count($result) == 0 ) {
    drupal_set_message(t('Please create a View that contains a SimpleAds plugin style.'), 'warning');
  }

  drupal_alter('simpleads_views_list', $result);

  return $result;

}

/**
 * Get all available Views displays
 */
function _simpleads_get_views_displays($view_name) {

  $result = array();

  $view = views_get_view($view_name);

  if (isset($view->display)) {
    foreach ( $view->display as $display_id => $display ) {
      if ( $display_id != 'default' ) {
        $result[$display_id] = check_plain($display->display_title);
      }
    }
  }

  drupal_alter('simpleads_views_displays', $result);

  return $result;

}

/**
 * Check if block exists.
 */
function _simpleads_check_block($machine_name) {

  $machine_name = db_select('simpleads_blocks', 'b')
  ->fields('b', array('machine_name'))
  ->condition('b.machine_name', $machine_name)
  ->execute()
  ->fetchField();

  if ( empty($machine_name) ) {
    return FALSE;
  }
  else {
    return TRUE;
  }

}

/**
 * Check if block exists.
 */
function _simpleads_load_block($machine_name) {

  $block = db_select('simpleads_blocks', 'b')
  ->fields('b')
  ->condition('b.machine_name', $machine_name)
  ->execute()
  ->fetchObject();

  if ( isset($block->bid) ) {

    return array(
      'bid' => $block->bid,
      'delta' => $block->machine_name,
      'name' => check_plain($block->name),
      'view_name' => $block->view_name,
      'view_display_id' => $block->view_display_id,
      'settings' => unserialize($block->settings),
    );

  }

  return FALSE;

}

/**
 * Insert new block.
 */
function _simpleads_insert_block($record) {
  return db_insert('simpleads_blocks')
    ->fields($record)
    ->execute();
}

/**
 * Update block.
 */
function _simpleads_update_block($record = array(), $machine_name = '') {
  return db_update('simpleads_blocks')
    ->fields($record)
    ->condition('machine_name', $machine_name)
    ->execute();
}

/**
 * Delete block.
 */
function _simpleads_delete_block($machine_name = '') {
  return db_delete('simpleads_blocks')
    ->condition('machine_name', $machine_name)
    ->execute();
}

/**
 * Get advertisement blocks list.
 */
function _simpleads_get_blocks_list() {

  $blocks = array();

  $result = db_select('simpleads_blocks', 'b')
  ->fields('b')
  ->orderBy('b.name', 'ASC')
  ->execute();

  foreach ( $result as $block ) {
    $blocks[$block->machine_name] = array(
      'bid' => $block->bid,
      'delta' => $block->machine_name,
      'name' => check_plain($block->name),
      'view_name' => $block->view_name,
      'view_display_id' => $block->view_display_id,
      'settings' => unserialize($block->settings),
    );
  }

  return $blocks;

}

/**
 * Preprocess helper.
 */
function _simpleads_theme_preprocess_helper(&$vars) {

  $vars['attributes_array'] = array();
  $vars['title_attributes_array'] = array();
  $vars['content_attributes_array'] = array();
  $vars['classes_array'] = array('');
  $entity = $vars['entity'];
  $tids = array();

  if ( $entity->field_ad_category[LANGUAGE_NONE] ) {
    $terms = array_values($entity->field_ad_category[LANGUAGE_NONE]);
    foreach ( $terms as $row ) {
      $tids[] = $row['tid'];
    }
  }

  if ( count($tids) ) {
    $vars['theme_hook_suggestions'][] = 'simpleads_type_' . $vars['type'] . '__' . join('_', $tids);
    foreach ( $tids as $tid ) {
      $vars['theme_hook_suggestions'][] = 'simpleads_type_' . $vars['type'] . '__' . $tid;
    }
  }

}

/**
 * Check HTTP referer and make sure this is a local action
 */
function _simpleads_is_valid_referer() {

  $server = !empty($_SERVER['HTTP_HOST']) ? $_SERVER['HTTP_HOST'] : $_ENV['HOSTNAME'];
  if ( isset($_SERVER['HTTP_REFERER']) && strpos($_SERVER['HTTP_REFERER'], $server) !== FALSE ) {
    return TRUE;
  }
  else {
    return FALSE;
  }

}

/**
 * Return TRUE if the visitor is a bot.
 */
function _simpleads_is_bot_detected() {

  if (isset($_SERVER['HTTP_USER_AGENT']) && preg_match('/bot|crawl|slurp|spider/i', $_SERVER['HTTP_USER_AGENT'])) {
    return TRUE;
  }
  else {
    return FALSE;
  }

}
