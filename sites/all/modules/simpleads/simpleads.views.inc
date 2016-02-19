<?php

/**
 * @file
 * SimpleAds Views.
 */

/**
 * Implements hook_date_views_fields().
 */
function simpleads_date_views_fields($field) {

  $values = array(
    // The type of date: DATE_UNIX, DATE_ISO, DATE_DATETIME.
    'sql_type' => DATE_UNIX,
    // Timezone handling options: 'none', 'site', 'date', 'utc' .
    'tz_handling' => 'site',
    // Needed only for dates that use 'date' tz_handling.
    'timezone_field' => '',
    // Needed only for dates that use 'date' tz_handling.
    'offset_field' => '',
    // Array of "table.field" values for related fields that should be
    // loaded automatically in the Views SQL.
    'related_fields' => array(),
    // Granularity of this date field's db data.
    'granularity' => array('year', 'month', 'day'),
  );

  switch ($field) {
    case 'simpleads_stats.date':
      return $values;
  }

}

/**
 * Implements hook_views_api().
 */
function simpleads_views_api() {
  return array(
    'api' => 3,
    'path' => drupal_get_path('module', 'simpleads') . '/includes',
    'template path' => drupal_get_path('module', 'simpleads') . '/templates',
  );
}

/**
 * Implements hook_views_plugins().
 */
function simpleads_views_plugins() {

  return array(
    'style' => array( //declare the views_json style plugin
      'simpleads' => array(
        'title' => t('SimpleAds'),
        'help' => t('Displays advertisements in blocks.'),
        'handler' => 'views_simpleads_plugin',
        'theme' => 'views_simpleads',
        'theme path' => drupal_get_path('module', 'simpleads') . '/templates',
        'theme file' => 'views-simpleads.tpl.php',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
    'row' => array( //declare the unformatted row plugin
      'unformatted' => array(
        'title' => t('Unformatted'),
        'help' => t('(Displays the unformatted data for each row from the views query with each row on a new line.'),
        'handler' => 'views_plugin_row_unformatted',
        'theme' => 'views_view_row_unformatted',
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
      ),
    ),
  );

}

/**
 * Implements hook_views_data().
 */
function simpleads_views_data() {

  $data['node']['stats_link']['moved to'] = array('views_entity_node', 'stats_link');
  $data['views_entity_node']['stats_link'] = array(
    'field' => array(
      'title' => t('Advertisements stats'),
      'help' => t('Provide a simple link to advertisement stats page.'),
      'handler' => 'views_handler_field_ad_link_stats',
    ),
  );

  $data['simpleads_stats']['ctr_value'] = array(
    'title' => t('Advertisement click-through rate'),
    'help' => t('Display advertisement click-through rate.'),
    'field' => array(
      'handler' => 'views_handler_field_ad_ctr',
    ),
  );

  // Simpleads stats DB table
  $data['simpleads_stats']['table']['group'] = t('SimpleAds Statistics');

  $data['simpleads_stats']['table']['base'] = array(
    'field' => 'nid',
    'title' => t('SimpleAds Statistics'),
    'help' => t("Daily statistics: clicks, unique clicks, impressions, unique impressions."),
  );

  $data['simpleads_stats']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
    ),
  );

  $data['simpleads_stats']['nid'] = array(
    'title' => t('Advertisement node ID'),
    'help' => t('References to SimpleAd node.'),
    'relationship' => array(
      'base' => 'node',
      'field' => 'nid',
      'handler' => 'views_handler_relationship',
      'label' => t('SimpleAds node'),
    ),
  );

  $data['simpleads_stats']['clicks'] = array(
    'title' => t('Clicks'),
    'help' => t('Advertisement clicks.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['simpleads_stats']['clicks_unique'] = array(
    'title' => t('Unique clicks'),
    'help' => t('Advertisement unique clicks.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['simpleads_stats']['impressions'] = array(
    'title' => t('Impressions'),
    'help' => t('Advertisement impressions.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['simpleads_stats']['impressions_unique'] = array(
    'title' => t('Unique impressions'),
    'help' => t('Advertisement unique impressions.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['simpleads_stats']['date'] = array(
    'title' => t('Date'),
    'help' => t('Statistics aggregated date.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_default_views().
 */
function simpleads_views_default_views() {

  $view = new view();
  $view->name = 'advertisements';
  $view->description = 'Advertisements related views.';
  $view->tag = 'SimpleAds';
  $view->base_table = 'node';
  $view->human_name = 'Advertisements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advertisements';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'title' => 'title',
    'field_ad_category' => 'field_ad_category',
    'created' => 'created',
    'status' => 'status',
    'stats_link' => 'stats_link',
    'delete_node' => 'delete_node',
    'edit_node_1' => 'edit_node_1',
    'edit_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_ad_category' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'stats_link' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no advertisements.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Advertisement groups */
  $handler->display->display_options['fields']['field_ad_category']['id'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['table'] = 'field_data_field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['field'] = 'field_ad_category';
  $handler->display->display_options['fields']['field_ad_category']['label'] = 'Groups';
  $handler->display->display_options['fields']['field_ad_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ad_category']['delta_offset'] = '0';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Advertisements stats */
  $handler->display->display_options['fields']['stats_link']['id'] = 'stats_link';
  $handler->display->display_options['fields']['stats_link']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['stats_link']['field'] = 'stats_link';
  $handler->display->display_options['fields']['stats_link']['label'] = '';
  $handler->display->display_options['fields']['stats_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['stats_link']['element_label_colon'] = FALSE;
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
  $handler->display->display_options['fields']['delete_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_node']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node_1']['id'] = 'edit_node_1';
  $handler->display->display_options['fields']['edit_node_1']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node_1']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node_1']['label'] = '';
  $handler->display->display_options['fields']['edit_node_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node_1']['element_label_colon'] = FALSE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '[stats_link] [edit_node_1] [delete_node]';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simpleads' => 'simpleads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Advertisements (page) */
  $handler = $view->new_display('page', 'Advertisements (page)', 'advertisements_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['path'] = 'admin/content/advertisements';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Advertisements';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Individual stats (block) */
  $handler = $view->new_display('block', 'Individual stats (block)', 'individual_statistics_block');
  $handler->display->display_options['defaults']['use_ajax'] = FALSE;
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '31';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'date' => 'date',
    'clicks' => 'clicks',
    'clicks_unique' => 'clicks_unique',
    'impressions' => 'impressions',
    'impressions_unique' => 'impressions_unique',
  );
  $handler->display->display_options['style_options']['default'] = 'date';
  $handler->display->display_options['style_options']['info'] = array(
    'date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clicks' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'clicks_unique' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'impressions' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'impressions_unique' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: SimpleAds Statistics: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'm-d-Y';
  /* Field: SimpleAds Statistics: Clicks */
  $handler->display->display_options['fields']['clicks']['id'] = 'clicks';
  $handler->display->display_options['fields']['clicks']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['clicks']['field'] = 'clicks';
  /* Field: SimpleAds Statistics: Unique clicks */
  $handler->display->display_options['fields']['clicks_unique']['id'] = 'clicks_unique';
  $handler->display->display_options['fields']['clicks_unique']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['clicks_unique']['field'] = 'clicks_unique';
  /* Field: SimpleAds Statistics: Impressions */
  $handler->display->display_options['fields']['impressions']['id'] = 'impressions';
  $handler->display->display_options['fields']['impressions']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['impressions']['field'] = 'impressions';
  /* Field: SimpleAds Statistics: Unique impressions */
  $handler->display->display_options['fields']['impressions_unique']['id'] = 'impressions_unique';
  $handler->display->display_options['fields']['impressions_unique']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['impressions_unique']['field'] = 'impressions_unique';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: SimpleAds Statistics: Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'simpleads_stats';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  $handler->display->display_options['sorts']['date']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simpleads' => 'simpleads',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Stats summary (attachment) */
  $handler = $view->new_display('attachment', 'Stats summary (attachment)', 'stats_block_attachment');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Total</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<h2>Daily statistics</h2>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: SimpleAds Statistics: Clicks */
  $handler->display->display_options['fields']['clicks']['id'] = 'clicks';
  $handler->display->display_options['fields']['clicks']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['clicks']['field'] = 'clicks';
  $handler->display->display_options['fields']['clicks']['group_type'] = 'sum';
  /* Field: SimpleAds Statistics: Unique clicks */
  $handler->display->display_options['fields']['clicks_unique']['id'] = 'clicks_unique';
  $handler->display->display_options['fields']['clicks_unique']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['clicks_unique']['field'] = 'clicks_unique';
  $handler->display->display_options['fields']['clicks_unique']['group_type'] = 'sum';
  /* Field: SimpleAds Statistics: Impressions */
  $handler->display->display_options['fields']['impressions']['id'] = 'impressions';
  $handler->display->display_options['fields']['impressions']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['impressions']['field'] = 'impressions';
  $handler->display->display_options['fields']['impressions']['group_type'] = 'sum';
  /* Field: SimpleAds Statistics: Unique impressions */
  $handler->display->display_options['fields']['impressions_unique']['id'] = 'impressions_unique';
  $handler->display->display_options['fields']['impressions_unique']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['impressions_unique']['field'] = 'impressions_unique';
  $handler->display->display_options['fields']['impressions_unique']['group_type'] = 'sum';
  /* Field: SimpleAds Statistics: Advertisement click-through rate */
  $handler->display->display_options['fields']['ctr_value']['id'] = 'ctr_value';
  $handler->display->display_options['fields']['ctr_value']['table'] = 'simpleads_stats';
  $handler->display->display_options['fields']['ctr_value']['field'] = 'ctr_value';
  $handler->display->display_options['fields']['ctr_value']['label'] = 'Click-through rate';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['displays'] = array(
    'individual_statistics_block' => 'individual_statistics_block',
    'default' => 0,
    'advertisements_page' => 0,
  );

  // Add CSV export Views displays if Views Data Export module enabled.
  if (module_exists('views_data_export')) {

    /* Display: Export individual stats (CSV) */
    $handler = $view->new_display('views_data_export', 'Export individual stats (CSV)', 'simpleads_individual_stats_export_csv');
    $handler->display->display_options['defaults']['group_by'] = FALSE;
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
    $handler->display->display_options['style_options']['provide_file'] = 1;
    $handler->display->display_options['style_options']['filename'] = '%1-title.csv';
    $handler->display->display_options['style_options']['parent_sort'] = 0;
    $handler->display->display_options['style_options']['quote'] = 1;
    $handler->display->display_options['style_options']['trim'] = 0;
    $handler->display->display_options['style_options']['replace_newlines'] = 0;
    $handler->display->display_options['style_options']['header'] = 1;
    $handler->display->display_options['style_options']['keep_html'] = 0;
    $handler->display->display_options['defaults']['empty'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = 'Advertisement Title';
    $handler->display->display_options['fields']['title']['exclude'] = TRUE;
    $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
    /* Field: SimpleAds Statistics: Date */
    $handler->display->display_options['fields']['date']['id'] = 'date';
    $handler->display->display_options['fields']['date']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['date']['field'] = 'date';
    $handler->display->display_options['fields']['date']['date_format'] = 'custom';
    $handler->display->display_options['fields']['date']['custom_date_format'] = 'm-d-Y';
    /* Field: SimpleAds Statistics: Clicks */
    $handler->display->display_options['fields']['clicks']['id'] = 'clicks';
    $handler->display->display_options['fields']['clicks']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['clicks']['field'] = 'clicks';
    /* Field: SimpleAds Statistics: Unique clicks */
    $handler->display->display_options['fields']['clicks_unique']['id'] = 'clicks_unique';
    $handler->display->display_options['fields']['clicks_unique']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['clicks_unique']['field'] = 'clicks_unique';
    /* Field: SimpleAds Statistics: Impressions */
    $handler->display->display_options['fields']['impressions']['id'] = 'impressions';
    $handler->display->display_options['fields']['impressions']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['impressions']['field'] = 'impressions';
    /* Field: SimpleAds Statistics: Unique impressions */
    $handler->display->display_options['fields']['impressions_unique']['id'] = 'impressions_unique';
    $handler->display->display_options['fields']['impressions_unique']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['impressions_unique']['field'] = 'impressions_unique';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    /* Contextual filter: Content: Nid */
    $handler->display->display_options['arguments']['nid']['id'] = 'nid';
    $handler->display->display_options['arguments']['nid']['table'] = 'node';
    $handler->display->display_options['arguments']['nid']['field'] = 'nid';
    $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
    $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
    $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
    $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
    $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
    $handler->display->display_options['path'] = 'admin/content/advertisements/export';
    $handler->display->display_options['displays'] = array(
      'individual_statistics_block' => 'individual_statistics_block',
      'default' => 0,
      'advertisements_page' => 0,
    );

    /* Display: Export all stats (CSV) */
    $handler = $view->new_display('views_data_export', 'Export all stats (CSV)', 'simpleads_all_stats_export_csv');
    $handler->display->display_options['defaults']['group_by'] = FALSE;
    $handler->display->display_options['group_by'] = TRUE;
    $handler->display->display_options['pager']['type'] = 'some';
    $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
    $handler->display->display_options['style_options']['provide_file'] = 1;
    $handler->display->display_options['style_options']['filename'] = '%timestamp-full.csv';
    $handler->display->display_options['style_options']['parent_sort'] = 0;
    $handler->display->display_options['style_options']['quote'] = 1;
    $handler->display->display_options['style_options']['trim'] = 0;
    $handler->display->display_options['style_options']['replace_newlines'] = 0;
    $handler->display->display_options['style_options']['header'] = 1;
    $handler->display->display_options['style_options']['keep_html'] = 0;
    $handler->display->display_options['defaults']['empty'] = FALSE;
    $handler->display->display_options['defaults']['fields'] = FALSE;
    /* Field: Content: Nid */
    $handler->display->display_options['fields']['nid']['id'] = 'nid';
    $handler->display->display_options['fields']['nid']['table'] = 'node';
    $handler->display->display_options['fields']['nid']['field'] = 'nid';
    $handler->display->display_options['fields']['nid']['label'] = 'Node ID';
    /* Field: Content: Title */
    $handler->display->display_options['fields']['title']['id'] = 'title';
    $handler->display->display_options['fields']['title']['table'] = 'node';
    $handler->display->display_options['fields']['title']['field'] = 'title';
    $handler->display->display_options['fields']['title']['label'] = 'Advertisement Title';
    $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
    /* Field: SimpleAds Statistics: Clicks */
    $handler->display->display_options['fields']['clicks']['id'] = 'clicks';
    $handler->display->display_options['fields']['clicks']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['clicks']['field'] = 'clicks';
    $handler->display->display_options['fields']['clicks']['group_type'] = 'sum';
    /* Field: SimpleAds Statistics: Unique clicks */
    $handler->display->display_options['fields']['clicks_unique']['id'] = 'clicks_unique';
    $handler->display->display_options['fields']['clicks_unique']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['clicks_unique']['field'] = 'clicks_unique';
    $handler->display->display_options['fields']['clicks_unique']['group_type'] = 'sum';
    /* Field: SimpleAds Statistics: Impressions */
    $handler->display->display_options['fields']['impressions']['id'] = 'impressions';
    $handler->display->display_options['fields']['impressions']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['impressions']['field'] = 'impressions';
    $handler->display->display_options['fields']['impressions']['group_type'] = 'sum';
    /* Field: SimpleAds Statistics: Unique impressions */
    $handler->display->display_options['fields']['impressions_unique']['id'] = 'impressions_unique';
    $handler->display->display_options['fields']['impressions_unique']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['impressions_unique']['field'] = 'impressions_unique';
    $handler->display->display_options['fields']['impressions_unique']['group_type'] = 'sum';
    /* Field: SimpleAds Statistics: Advertisement click-through rate */
    $handler->display->display_options['fields']['ctr_value']['id'] = 'ctr_value';
    $handler->display->display_options['fields']['ctr_value']['table'] = 'simpleads_stats';
    $handler->display->display_options['fields']['ctr_value']['field'] = 'ctr_value';
    $handler->display->display_options['fields']['ctr_value']['label'] = 'Click-through rate';
    $handler->display->display_options['defaults']['sorts'] = FALSE;
    /* Sort criterion: Content: Title */
    $handler->display->display_options['sorts']['title']['id'] = 'title';
    $handler->display->display_options['sorts']['title']['table'] = 'node';
    $handler->display->display_options['sorts']['title']['field'] = 'title';
    $handler->display->display_options['defaults']['arguments'] = FALSE;
    $handler->display->display_options['path'] = 'admin/content/advertisements/export-all';
    $handler->display->display_options['displays'] = array(
      'advertisements_page' => 'advertisements_page',
      'default' => 0,
      'individual_statistics_block' => 0,
    );

  }

  $views[$view->name] = $view;

  $view = new view();
  $view->name = 'advertisement_blocks';
  $view->description = '';
  $view->tag = 'SimpleAds';
  $view->base_table = 'node';
  $view->human_name = 'Advertisement blocks';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Advertisement blocks';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'simpleads';
  $handler->display->display_options['style_options']['speed'] = '1000';
  $handler->display->display_options['style_options']['width'] = '100';
  $handler->display->display_options['style_options']['height'] = '100';
  $handler->display->display_options['style_options']['items_per_slide'] = '0';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Image advertisement */
  $handler->display->display_options['fields']['field_ad_image']['id'] = 'field_ad_image';
  $handler->display->display_options['fields']['field_ad_image']['table'] = 'field_data_field_ad_image';
  $handler->display->display_options['fields']['field_ad_image']['field'] = 'field_ad_image';
  $handler->display->display_options['fields']['field_ad_image']['label'] = '';
  $handler->display->display_options['fields']['field_ad_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_ad_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Text advertisement */
  $handler->display->display_options['fields']['field_ad_text']['id'] = 'field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['table'] = 'field_data_field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['field'] = 'field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['label'] = '';
  $handler->display->display_options['fields']['field_ad_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_text']['element_label_colon'] = FALSE;
  /* Field: Content: Flash advertisement */
  $handler->display->display_options['fields']['field_ad_flash']['id'] = 'field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['table'] = 'field_data_field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['field'] = 'field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['label'] = '';
  $handler->display->display_options['fields']['field_ad_flash']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_flash']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_flash']['click_sort_column'] = 'fid';
  /* Field: Content: URL Address */
  $handler->display->display_options['fields']['field_ad_url']['id'] = 'field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['table'] = 'field_data_field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['field'] = 'field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['label'] = '';
  $handler->display->display_options['fields']['field_ad_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ad_url']['alter']['text'] = '<a href="[field_ad_url-url]" target="_blank" [field_ad_url-attributes]>[field_ad_image][field_ad_text]</a>';
  $handler->display->display_options['fields']['field_ad_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_url']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_ad_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_ad_url']['type'] = 'link_plain';
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  /* Contextual filter: Content: Advertisement groups (field_ad_category) */
  $handler->display->display_options['arguments']['field_ad_category_tid']['id'] = 'field_ad_category_tid';
  $handler->display->display_options['arguments']['field_ad_category_tid']['table'] = 'field_data_field_ad_category';
  $handler->display->display_options['arguments']['field_ad_category_tid']['field'] = 'field_ad_category_tid';
  $handler->display->display_options['arguments']['field_ad_category_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_ad_category_tid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['field_ad_category_tid']['default_argument_options']['index'] = '0';
  $handler->display->display_options['arguments']['field_ad_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_ad_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_ad_category_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'simpleads' => 'simpleads',
  );

  /* Display: Block (default) */
  $handler = $view->new_display('block', 'Block (default)', 'simpleads_default_block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;

  $views[$view->name] = $view;

  return $views;

}
