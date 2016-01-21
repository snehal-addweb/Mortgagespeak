<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function mortgagespeak_theme(&$existing, $type, $theme, $path){
  $hooks = array();
   // Make user-register.tpl.php available
  $hooks['user_register_form'] = array (
     'render element' => 'form',
     'path' => drupal_get_path('theme','mortgagespeak'),
     'template' => 'templates/user-register',
     'preprocess functions' => array('mortgagespeak_preprocess_user_register_form'),
  );
  return $hooks;
}

function mortgagespeak_preprocess_user_register_form(&$vars) {
  $args = func_get_args();
  array_shift($args);
  $form_state['build_info']['args'] = $args; 
  $vars['form'] = drupal_build_form('user_register_form', $form_state['build_info']['args']);
}

function mortgagespeak_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="content-area col-lg-8 col-md-8 col-sm-8 col-xs-12 p0"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="content-area col-lg-10 col-md-10 col-sm-10 col-xs-12 p0"';
  }
  else {
    $variables['content_column_class'] = ' class="content-area col-lg-12 col-md-12 col-sm-12 col-xs-12 p0"';
  }
}