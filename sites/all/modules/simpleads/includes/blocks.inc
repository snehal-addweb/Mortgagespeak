<?php

/**
 * @file
 * SimpleAds blocks.
 */

/**
 * Implements hook_form_FORM_ID_alter().
 * Add Delete link next to the Advertisement block.
 */
function simpleads_form_block_admin_display_form_alter(&$form, &$form_state, $form_id) {

  foreach ( _simpleads_get_blocks_list() AS $delta => $block ) {
    $form['blocks']['simpleads_' . $delta]['delete'] = array('#type' => 'link', '#title' => t('delete'), '#href' => 'admin/structure/block/simpleads/delete/' . $delta);
  }

}

/**
 * Implements hook_block_info().
 */
function simpleads_block_info() {

  $blocks = array();

  foreach ( _simpleads_get_blocks_list() as $delta => $block ) {
    $blocks[$delta] = array(
      'info' => t('Advertisement block: @name', array('@name' => $block['name'])),
    );
  }

  return $blocks;

}

/**
 * Implements hook_block_configure().
 */
function simpleads_block_configure($delta = '') {

  $form = array();

  foreach ( _simpleads_get_blocks_list() as $block_delta => $block ) {

    if ($delta == $block_delta) {

      $form['#attached'] = array(
        'js' => array(drupal_get_path('module', 'simpleads') . '/js/block.js'),
      );

      $form['name'] = array(
        '#type' => 'textfield',
        '#title' => 'Administrative name',
        '#description' => 'Visible to administrators only',
        '#default_value' => $block['name'],
        '#required' => TRUE,
      );

      $form['machine_name'] = array(
        '#type' => 'hidden',
        '#value' => $block['delta'],
      );

      $form['advertisement_groups'] = array(
        '#type' => 'radios',
        '#title' => 'Advertisement group',
        '#options' => _simpleads_get_groups(),
        '#default_value' => $block['settings']['advertisement_groups'],
        '#required' => TRUE,
      );

      $advertisement_views = _simpleads_get_views_list();
      $groups_default = $block['view_name'];

      $form['views'] = array(
        '#markup' => t('<strong>Advertisement View:</strong> @name', array('@name' => $groups_default)),
      );

      $form['views_display_id'] = array(
        '#type' => 'select',
        '#title' => 'Advertisement View Display',
        '#options' => _simpleads_get_views_displays($groups_default),
        '#description' => 'Please select a display that pulls advertisements for this block.',
        '#prefix' => '<div id="views-display-id">',
        '#suffix' => '</div>',
        '#default_value' => isset($form_state['values']['views_display_id']) ? $form_state['values']['views_display_id'] : $block['view_display_id'],
      );

    }

  }

  return $form;

}

/**
 * Implements hook_block_save().
 */
function simpleads_block_save($delta = '', $edit = array()) {

  foreach ( _simpleads_get_blocks_list() as $block_delta => $block  ) {

    if ($delta == $block_delta) {

      $settings = array(
        'advertisement_groups' => $edit['advertisement_groups'],
      );

      $record = array(
        'machine_name' => $edit['machine_name'],
        'name' => $edit['name'],
        'view_display_id' => $edit['views_display_id'],
        'settings' => serialize($settings),
      );

      _simpleads_update_block($record, $edit['machine_name']);

    }

  }

}

/**
 * Implements hook_block_view().
 */
function simpleads_block_view($delta = '') {

  $block = array();

  foreach ( _simpleads_get_blocks_list() as $block_delta => $block_data  ) {

    if ($delta == $block_delta) {

      $block_data = _simpleads_load_block($delta);

      $arguments = array();
      $arguments[] = $block_data['view_name'];
      $arguments[] = $block_data['view_display_id'];

      if ( isset($block_data['settings']['advertisement_groups']) ) {
        $arguments[] = $block_data['settings']['advertisement_groups'];
      }

      $block['subject'] = '';

      ob_start();
      print call_user_func_array('views_embed_view', $arguments);
      $content = ob_get_contents();
      ob_end_clean();

      $block['content'] = isset($content) ? $content : '';

    }

  }

  return $block;

}
