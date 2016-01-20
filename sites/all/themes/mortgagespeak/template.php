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