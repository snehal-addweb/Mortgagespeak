<?php
/**
 * @file
 * simple_ad_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function simple_ad_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'simple_ads_placements';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Simple ads placements';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'simpleads';
  $handler->display->display_options['style_options']['speed'] = '1000';
  $handler->display->display_options['style_options']['width'] = '100';
  $handler->display->display_options['style_options']['height'] = '100';
  $handler->display->display_options['style_options']['items_per_slide'] = '1';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Top Banner -->
<ins class="adsbygoogle"
     style="display:inline-block;width:970px;height:90px"
     data-ad-client="ca-pub-9613794206213062"
     data-ad-slot="6473612637"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'assign_ad' => 'assign_ad',
    'ad_groups' => 0,
    'company_tags' => 0,
    'news_topics' => 0,
    'newsletter' => 0,
    'simpleads_groups' => 0,
    'tab_placement' => 0,
    'tags' => 0,
    'upload_content_types' => 0,
    'upload_tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
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
  /* Field: Content: Flash advertisement */
  $handler->display->display_options['fields']['field_ad_flash']['id'] = 'field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['table'] = 'field_data_field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['field'] = 'field_ad_flash';
  $handler->display->display_options['fields']['field_ad_flash']['label'] = '';
  $handler->display->display_options['fields']['field_ad_flash']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_flash']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_flash']['click_sort_column'] = 'fid';
  /* Field: Content: Text advertisement */
  $handler->display->display_options['fields']['field_ad_text']['id'] = 'field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['table'] = 'field_data_field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['field'] = 'field_ad_text';
  $handler->display->display_options['fields']['field_ad_text']['label'] = '';
  $handler->display->display_options['fields']['field_ad_text']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_ad_text']['element_label_colon'] = FALSE;
  /* Field: Content: URL Address */
  $handler->display->display_options['fields']['field_ad_url']['id'] = 'field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['table'] = 'field_data_field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['field'] = 'field_ad_url';
  $handler->display->display_options['fields']['field_ad_url']['label'] = '';
  $handler->display->display_options['fields']['field_ad_url']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ad_url']['alter']['text'] = '<a href="[field_ad_url-url]" target="_blank" [field_ad_url-attributes]>[field_ad_image][field_ad_text][field_ad_flash]</a>';
  $handler->display->display_options['fields']['field_ad_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ad_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_ad_url']['type'] = 'link_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['tid']['default_argument_options']['code'] = '$page_url = arg(0);

$tid = \'\';

if (arg(0) == \'taxonomy\') {
	$page_url = drupal_get_path_alias(\'taxonomy/term/\' . arg(2));	
}

if (arg(0) == \'node\') {
	$page_url = drupal_get_path_alias(\'node/\' . arg(1));
}


$query = new EntityFieldQuery();
$query->entityCondition(\'entity_type\', \'taxonomy_term\')
	->fieldCondition(\'field_page_url\', \'value\', $page_url, \'=\');
$result = $query->execute();

if(isset($result[\'taxonomy_term\'])) {
	foreach ($result[\'taxonomy_term\'] as $tidKey => $arrVal) {
		$tid = $arrVal->tid;
	}
}	

return $tid;';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    173 => '173',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'simple-ads-placements';

  /* Display: Welcome Page */
  $handler = $view->new_display('block', 'Welcome Page', 'block_1');

  /* Display: Top Page */
  $handler = $view->new_display('block', 'Top Page', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    174 => '174',
  );

  /* Display: Left Skyscraper */
  $handler = $view->new_display('block', 'Left Skyscraper', 'block_3');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Vertical Banner Ad -->
<ins class="adsbygoogle"
     style="display:inline-block;width:160px;height:600px"
     data-ad-client="ca-pub-9613794206213062"
     data-ad-slot="7783091034"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    175 => '175',
  );

  /* Display: Left Block 1 */
  $handler = $view->new_display('block', 'Left Block 1', 'block_4');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Link Unit #1 -->
<ins class="adsbygoogle"
     style="display:inline-block;width:160px;height:90px"
     data-ad-client="ca-pub-9613794206213062"
     data-ad-slot="9399425035"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    176 => '176',
  );

  /* Display: Left Block 2 */
  $handler = $view->new_display('block', 'Left Block 2', 'block_5');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Link Unit #2 -->
<ins class="adsbygoogle"
     style="display:inline-block;width:160px;height:90px"
     data-ad-client="ca-pub-9613794206213062"
     data-ad-slot="1876158236"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    177 => '177',
  );

  /* Display: Left Block 3 */
  $handler = $view->new_display('block', 'Left Block 3', 'block_6');
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
<!-- Link Unit #3 -->
<ins class="adsbygoogle"
     style="display:inline-block;width:160px;height:90px"
     data-ad-client="ca-pub-9613794206213062"
     data-ad-slot="3352891432"></ins>
<script>
(adsbygoogle = window.adsbygoogle || []).push({});
</script';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    178 => '178',
  );

  /* Display: Pop Up Tab */
  $handler = $view->new_display('block', 'Pop Up Tab', 'block_7');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: Campaign (field_adcamp_list) */
  $handler->display->display_options['filters']['field_adcamp_list_value']['id'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['table'] = 'field_data_field_adcamp_list';
  $handler->display->display_options['filters']['field_adcamp_list_value']['field'] = 'field_adcamp_list_value';
  $handler->display->display_options['filters']['field_adcamp_list_value']['value'] = array(
    179 => '179',
  );
  $export['simple_ads_placements'] = $view;

  return $export;
}
