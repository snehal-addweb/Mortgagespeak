<?php

/**
 * @file
 * SimpleAds Features integration.
 */

function simpleads_features_api() {
  return array(
    'mycomponent' => array(
      'default_hook' => 'mycomponent_defaults',
      'default_file' => FEATURES_DEFAULTS_INCLUDED,
      'feature_source' => TRUE,
      'file' => drupal_get_path('module', 'simpleads') .'/features/simpleads.features.inc',
    ),
  );
}