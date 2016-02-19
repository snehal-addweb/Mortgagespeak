<?php

/**
 * @file
 * simpleads.admin.inc
 */

/**
 * New advertisement block form.
 */
function simpleads_new_block_form($form, &$form_state) {

  $library = libraries_detect('jquery.cycle');

  if ( empty($library['installed']) ) {
    drupal_set_message(t('jQuery Cycle plugin is not installed. Please <a href="!download-url" target="_blank">download plugin</a> to site/all/libraries/jquery.cycle directory.', array('!download-url' => $library['download url'])), 'warning');
  }

  $form['#attached'] = array(
    'js' => array(drupal_get_path('module', 'simpleads') . '/js/block.js'),
  );

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => 'Administrative name',
    '#description' => 'Visible to administrators only',
    '#required' => TRUE,
  );

  $form['machine_name'] = array(
    '#type' => 'machine_name',
    '#title' => 'Machine Name',
    '#required' => TRUE,
    '#description' => t('Machine-friendly name.'),
    '#size' => 20,
    '#maxlength' => 20,
    '#machine_name' => array(
      'exists' => '_simpleads_machine_name_check_duplicates',
      'source' => array('name'),
    ),
  );

  $form['advertisement_groups'] = array(
    '#type' => 'radios',
    '#title' => 'Advertisement groups',
    '#options' => _simpleads_get_groups(),
    '#required' => TRUE,
  );

  $advertisement_views = _simpleads_get_views_list();
  $groups_default = isset($form_state['values']['views']) ? $form_state['values']['views'] : key($advertisement_views);

  $form['views'] = array(
    '#type' => 'select',
    '#title' => 'Advertisement View',
    '#options' => $advertisement_views,
    '#description' => 'Please select a View from the list.',
    '#ajax' => array(
      'event' => 'change',
      'callback' => '_simpleads_get_views_list_select',
      'wrapper' => 'views-display-id',
    ),
    '#default_value' => $groups_default,
  );

  $form['views_display_id'] = array(
    '#type' => 'select',
    '#title' => 'Advertisement View Display',
    '#options' => _simpleads_get_views_displays($groups_default),
    '#description' => 'Please select a display that pulls advertisements for this block.',
    '#prefix' => '<div id="views-display-id">',
    '#suffix' => '</div>',
    '#default_value' => isset($form_state['values']['views_display_id']) ? $form_state['values']['views_display_id'] : '',
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Create a block',
  );

  return $form;
}

/**
 * AJAX callback for Views select drop-down list.
 */
function _simpleads_get_views_list_select($form, $form_state) {
  return $form['views_display_id'];
}

/**
 * Machine name callback.
 */
function _simpleads_machine_name_check_duplicates($machine_name) {
  return _simpleads_check_block($machine_name);
}

/**
 * Save new advertisement block.
 */
function simpleads_new_block_form_submit($form, &$form_state) {

  $settings = array(
    'advertisement_groups' => $form_state['values']['advertisement_groups'],
  );

  $record = array(
    'machine_name' => $form_state['values']['machine_name'],
    'name' => $form_state['values']['name'],
    'view_name' => $form_state['values']['views'],
    'view_display_id' => $form_state['values']['views_display_id'],
    'settings' => serialize($settings),
  );

  _simpleads_insert_block($record);

  cache_clear_all(NULL, 'cache_block', '*');
  drupal_set_message(t('The Advertisement block has been created.'));
  $form_state['redirect'] = 'admin/structure/block';

  return;

}

/**
 * Delete advertisement block form.
 */
function simpleads_delete_block_form($form, &$form_state, $machine_name) {

  $block = _simpleads_load_block($machine_name);

  $form['block_title'] = array('#type' => 'hidden', '#value' => $block['name']);
  $form['delta'] = array('#type' => 'hidden', '#value' => $block['delta']);

  return confirm_form($form, t('Are you sure you want to delete the "%name" advertisement block?', array('%name' => $block['name'])), 'admin/structure/block', NULL, t('Delete'), t('Cancel'));

}

/**
 * Save new advertisement block.
 */
function simpleads_delete_block_form_submit($form, &$form_state) {

  _simpleads_delete_block($form_state['values']['delta']);

  db_delete('block')
    ->condition('module', 'simpleads')
    ->condition('delta', $form_state['values']['delta'])
    ->execute();

  drupal_set_message(t('The advertisement block "%name" has been removed.', array('%name' => $form_state['values']['block_title'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';

  return;
}
