<?php
/**
 * @file
 * simple_ad_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function simple_ad_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['randomblocks-all_page_ads'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'all_page_ads',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php
if (arg(0) == \'welcome\') {
	return FALSE;
  }
if (arg(0) == \'node\' && is_numeric(arg(1)))
  {
      $nid = arg(1);
      $node = node_load($nid);
      if (isset($node->field_assign_customas[LANGUAGE_NONE]) && !empty ($node->field_assign_customas[LANGUAGE_NONE]))
      {
         return FALSE;
      }
  }
  return TRUE;
?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => -37,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 2,
  );

  $export['randomblocks-left_block_1'] = array(
    'cache' => -1,
    'css_class' => 'all-page-ads',
    'custom' => 0,
    'delta' => 'left_block_1',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php

if (arg(0) == \'welcome\' || (arg(0) == \'node\' && is_numeric(arg(1)))) {
	return FALSE;
  }
return TRUE;

?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'mortgagespeak',
        'weight' => -31,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['randomblocks-left_block_2'] = array(
    'cache' => -1,
    'css_class' => 'all-page-ads',
    'custom' => 0,
    'delta' => 'left_block_2',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php

if (arg(0) == \'welcome\' || (arg(0) == \'node\' && is_numeric(arg(1)))) {
	return FALSE;
  }
return TRUE;

?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'mortgagespeak',
        'weight' => -30,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['randomblocks-left_block_3'] = array(
    'cache' => -1,
    'css_class' => 'all-page-ads',
    'custom' => 0,
    'delta' => 'left_block_3',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php

if (arg(0) == \'welcome\' || (arg(0) == \'node\' && is_numeric(arg(1)))) {
	return FALSE;
  }
return TRUE;

?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'mortgagespeak',
        'weight' => -29,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['randomblocks-left_skyscraper'] = array(
    'cache' => -1,
    'css_class' => 'all-page-ads',
    'custom' => 0,
    'delta' => 'left_skyscraper',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php

if (arg(0) == \'welcome\' || (arg(0) == \'node\' && is_numeric(arg(1)))) {
	return FALSE;
  }
return TRUE;

?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'mortgagespeak',
        'weight' => -32,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['randomblocks-pop_up_tab'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'pop_up_tab',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['randomblocks-top_page'] = array(
    'cache' => -1,
    'css_class' => 'all-page-ads',
    'custom' => 0,
    'delta' => 'top_page',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '<?php

if (arg(0) == \'welcome\') {
	return FALSE;
}

if (arg(0) == \'node\' && is_numeric(arg(1)))
  {
      $nid = arg(1);
      $node = node_load($nid);

      if ($node->type == "alpha_content")
      {
         return FALSE;
      }
      else {
      	return TRUE;
      }
}
return TRUE;

?>',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => 'highlighted',
        'status' => 1,
        'theme' => 'mortgagespeak',
        'weight' => -38,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 2,
  );

  $export['randomblocks-welcome_page'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'welcome_page',
    'module' => 'randomblocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_1'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_1',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_2'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_2',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_3'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_3',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_4'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_4',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_5'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_5',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_6'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_6',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  $export['views-simple_ads_placements-block_7'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'delta' => 'simple_ads_placements-block_7',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bartik' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bartik',
        'weight' => 0,
      ),
      'mortgagespeak' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'mortgagespeak',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '',
    'visibility' => 0,
  );

  return $export;
}
