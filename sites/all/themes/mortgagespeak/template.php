<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

function mortgagespeak_theme(&$existing, $type, $theme, $path){
  $items = array();
   // Make user-register.tpl.php available
  $items['user_register_form'] = array (
     'render element' => 'form',
     'path' => drupal_get_path('theme','mortgagespeak'),
     'template' => 'templates/user-register',
     'preprocess functions' => array('mortgagespeak_preprocess_user_register_form'),
  );
  
  $items['user_login_block'] = array(
     'path' => drupal_get_path('theme','mortgagespeak'),
     'template' => 'templates/user-login-block',
     'render element' => 'form',
  );
  
  $items['user_login'] = array(
     'render element' => 'form',
     'path' => drupal_get_path('theme','mortgagespeak'),
     'template' => 'templates/user-login',
     'preprocess functions' => array('mortgagespeak_preprocess_user_login'),
   );
  return $items;
}

function mortgagespeak_preprocess_user_register_form(&$vars) {
  $args = func_get_args();
  array_shift($args);
  $form_state['build_info']['args'] = $args; 
  $vars['form'] = drupal_build_form('user_register_form', $form_state['build_info']['args']);
}

function mortgagespeak_preprocess_user_login(&$vars) {
  $vars['name'] = render($vars['form']['name']);
  $vars['pass'] = render($vars['form']['pass']);
  $vars['submit'] = render($vars['form']['actions']['submit']);
  $vars['rendered'] = drupal_render_children($vars['form']);
}

function mortgagespeak_preprocess_user_login_block(&$vars) {
  $vars['name'] = render($vars['form']['name']);
  $vars['pass'] = render($vars['form']['pass']);
  $vars['submit'] = render($vars['form']['actions']['submit']);
  $vars['rendered'] = drupal_render_children($vars['form']);
}

function mortgagespeak_preprocess_page(&$variables) {
  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="content-area col-lg-8 col-md-8 col-sm-8 col-xs-12"';
  }
  elseif (!empty($variables['page']['sidebar_first']) || !empty($variables['page']['sidebar_second'])) {
    $variables['content_column_class'] = ' class="content-area col-lg-10 col-md-10 col-sm-10 col-xs-12"';
  }
  else {
    $variables['content_column_class'] = ' class="content-area col-lg-12 col-md-12 col-sm-12 col-xs-12"';
  }
}


function mortgagespeak_menu_link(array $variables) {
  global $user;
  $show_purple_tooltip = 0;
  $user_info = user_load($user->uid);
  if (isset($user_info->field_show_got_it_box) && !empty($user_info->field_show_got_it_box)) {
    $show_purple_tooltip = $user_info->field_show_got_it_box['und'][0]['value'];
  }
  $sub_menu = '';
  $element = $variables['element'];
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $variables['element']['#attributes']['class'][] = 'active active-trail';
  $variables['element']['#localized_options']['attributes']['class'][] = 'active active-trail';

  $output = l($element['#title'], $element['#href'], $options = $element['#localized_options']);
  
  if ($show_purple_tooltip == 1) {
    if ($element['#original_link']['menu_name'] == 'main-menu' && $element['#href'] == 'my-page/tracked-news') {
       return '<li' . drupal_attributes($element['#attributes']) . '>' . $output  . "<div id='purple-tooltip' class='purple-main-container'><div class='purple-inner'><div class='purple-text'>Access your Custom News Page here.</div><div class='purple-button'>ok, Got it</div></div></div></li>\n"; 
    } 
    else{
         return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu ."</li>\n";
    }
  }
  else {
    return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu ."</li>\n";
  }
}