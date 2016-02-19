<?php

/**
 * @file
 * SimpleAds fields.
 */

/**
 * Implements hook_field_formatter_info().
 */
function simpleads_field_formatter_info() {
  $formatters = array(
    'advertisement_dates' => array(
      'label' => t('Advertisement Dates'),
      'field types' => array('datetime'),
    ),
  );
  return $formatters;
}

/**
 * Implements hook_field_formatter_view().
 */
function simpleads_field_formatter_view($entity_type, $entity, $field, $instance, $langcode, $items, $display) {

  $element = array();
  $settings = $display['settings'];
  $formatter = $display['type'];

  $entity_status = isset($entity->status) ? $entity->status : NULL;

  $variables = array(
    'entity' => $entity,
    'entity_type' => $entity_type,
    'field' => $field,
    'instance' => $instance,
    'langcode' => $langcode,
    'items' => $items,
    'display' => $display,
    'dates' => array(),
    'attributes' => array(),
    'rdf_mapping' => array(),
    'add_rdf' => module_exists('rdf'),
  );

  // If there is an RDf mapping for this date field, pass it down to the theme.
  $rdf_mapping = array();
  if (!empty($entity->rdf_mapping) && function_exists('rdf_rdfa_attributes')) {
    if (!empty($entity->rdf_mapping[$field['field_name']])) {
      $variables['rdf_mapping'] = $rdf_mapping = $entity->rdf_mapping[$field['field_name']];
    }
  }

  // See if we are only supposed to display a selected
  // item from multiple value date fields.
  $selected_deltas = array();
  if (!empty($entity->date_id)) {
    foreach ((array) $entity->date_id as $key => $id) {
      list($module, $nid, $field_name, $selected_delta, $other) = explode('.', $id . '.');
      if ($field_name == $field['field_name']) {
        $selected_deltas[] = $selected_delta;
      }
    }
  }

  switch ($display['type']) {
    case 'advertisement_dates':
    default:
      foreach ($items as $delta => $item) {

        if (!empty($entity->date_id) && !in_array($delta, $selected_deltas)) {
          continue;
        }
        else {
          if (empty($item['value2']) || $item['value'] == $item['value2']) {
            $element[$delta] = array(
              '#markup' => _simpleads_ad_dates($item['value'], $item['value'], $entity_status),
            );
          }
          else {
            $element[$delta] = array(
              '#markup' => _simpleads_ad_dates($item['value'], $item['value2'], $entity_status),
            );
          }
        }
      }
      break;
  }
  return $element;
}
