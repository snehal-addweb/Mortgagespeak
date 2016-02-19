<?php

/**
 * @file
 * SimpleAds theme.
 */

/**
 * Implements hook_theme().
 */
function simpleads_theme($existing, $type, $theme, $path) {

  $templates = array();

  $templates_path = $path . '/templates';
  $docroot = DRUPAL_ROOT . base_path() . $templates_path;

  foreach ( _simpleads_ad_types() as $type => $name ) {

    if ( file_exists($docroot . '/simpleads-type-' . $type . '.tpl.php') ) {

      $templates['simpleads_type_' . $type] = array(
        'variables' => array(
          'output' => NULL,
          'type' => NULL,
          'entity' => NULL,
          'options' => NULL,
          'css_classes' => NULL
        ),
        'template' => 'simpleads-type-' . $type,
        'path' => $templates_path,
        'preprocess functions' => array(
          'simpleads_type_' . $type . '_preprocess'
        ),
      );

    }

  }

  return $templates;

}

/**
 * Preprocess for simpleads-type-graphic.tpl.php.
 */
function simpleads_type_graphic_preprocess(&$vars) {

  $entity = $vars['entity'];
  _simpleads_theme_preprocess_helper($vars);

}

/**
 * Preprocess for simpleads-type-text.tpl.php.
 */
function simpleads_type_text_preprocess(&$vars) {

  $entity = $vars['entity'];
  _simpleads_theme_preprocess_helper($vars);

}

/**
 * Preprocess for simpleads-type-flash.tpl.php.
 */
function simpleads_type_flash_preprocess(&$vars) {

  $entity = $vars['entity'];
  _simpleads_theme_preprocess_helper($vars);

  $vars['width'] = $vars['options']['width'];
  $vars['height'] = $vars['options']['height'];
  $vars['url'] = '';
  $vars['target'] = '';
  $vars['src'] = '';

  if ( isset($entity->field_ad_url[LANGUAGE_NONE]) ) {
    $vars['url'] = url('node/' . $entity->nid . '/stats/redirect');
    $vars['target'] = link_cleanup_url($entity->field_ad_url[LANGUAGE_NONE][0]['attributes']['target']);
  }

  if ( isset($entity->field_ad_flash[LANGUAGE_NONE]) ) {
    $vars['src'] = file_create_url($entity->field_ad_flash[LANGUAGE_NONE][0]['uri']);
  }

}

/**
 * Preprocess for SimpleAds Views template.
 * views-simpleads.tpl.php
 */
function template_preprocess_views_simpleads(&$vars) {

  $view = $vars['view'];
  $rows = $vars['rows'];
  $style = $view->style_plugin;
  $options = $style->options;

  if ( $options['plugin'] == 'jquery.cycle' ) {
    $jquery_cycle = libraries_get_path($options['plugin']);
    drupal_add_js($jquery_cycle . '/jquery.cycle.all.js');
    drupal_add_js(drupal_get_path('module', 'simpleads') . '/js/simpleads.cycle.js');
  }

  $vars['classes_array'] = array();
  $vars['classes'] = array();
  $vars['node_id'] = array();
  $vars['type'] = array();
  $vars['entity'] = array();

  // View options
  $vars['options'] = $options;

  $default_row_class = isset($options['default_row_class']) ? $options['default_row_class'] : FALSE;
  $row_class_special = isset($options['row_class_special']) ? $options['row_class_special'] : FALSE;

  // Set up striping values.
  $count = 0;
  $max = count($rows);

  foreach ($rows as $id => $row) {

    $count++;

    $vars['classes'][$id][] = 'simpleads-item';
    $vars['classes'][$id][] = 'simpleads-item-' . $count;

    $vars['node_id'][$id] = $view->result[$id]->nid;
    // Get entity language
    $language = isset($view->result[$id]->_field_data['nid']['entity']->language) ? $view->result[$id]->_field_data['nid']['entity']->language : LANGUAGE_NONE;
    $vars['type'][$id] = $view->result[$id]->_field_data['nid']['entity']->field_ad_type[$language][0]['value'];
    $vars['entity'][$id] = $view->result[$id]->_field_data['nid']['entity'];

    if ($row_class_special) {
      $vars['classes'][$id][] = 'simpleads-item-' . ($count % 2 ? 'odd' : 'even');
    }

    if ($count == 1) {
      $vars['classes'][$id][] = 'first';
    }
    if ($count == $max) {
      $vars['classes'][$id][] = 'last';
    }

    if ($row_class = $view->style_plugin->get_row_class($id)) {
      $vars['classes'][$id][] = $row_class;
    }

    // Flatten the classes to a string for each row for the template file.
    $vars['classes_array'][$id] = isset($vars['classes'][$id]) ? implode(' ', $vars['classes'][$id]) : '';

  }

}
