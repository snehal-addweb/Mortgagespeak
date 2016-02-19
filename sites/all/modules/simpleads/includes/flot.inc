<?php

/**
 * @file
 * SimpleAds flot integration.
 */

function simpleads_individual_stats_flot() {

  $d1 = new flotData(array(array(0, 1), array(4, 8), array(8, 5)));
  $d1->label = t('Example data 1');

  $d2 = new flotData(array(array(0, 8), array(3, 5), array(8, 0.5)));
  $d2->label = t('Example data 2');

  $variables = array(
    'data' => array($d1, $d2),
    'element' => array(
      'id' => 'flot-example-normal',
      'class' => 'flot-example',
      'style' => "width:500px; height:300px",
    ),
    'legend' => TRUE,
    'zoom' => FALSE,
  );
  return theme('flot_graph', $variables);

}
