<?php

/**
 * @file
 * Contains the list style plugin.
 */

/**
 * Style plugin to render SimpleAds.
 *
 * @ingroup views_style_plugins
 */
class views_simpleads_plugin extends views_plugin_style {

  /**
   * Set default options
   */
    function option_definition() {

      $options = parent::option_definition();
      $options['plugin'] = array('default' => 'jquery.cycle');
      $options['transition_effect'] = array('default' => 'fade');
      $options['speed'] = array('default' => 1000);
      $options['width'] = array('default' => 100);
      $options['height'] = array('default' => 100);
      $options['items_per_slide'] = array('default' => 1);

    return $options;

  }

  /**
   * Provide a form for setting options.
   *
   * @param array $form
   * @param array $form_state
   */
  function options_form(&$form, &$form_state) {

    $form['plugin'] = array(
      '#type' => 'select',
      '#title' => t('Plugin'),
      '#options' => array(
        'jquery.cycle' => t('JQuery Cycle Plugin'),
      ),
      '#default_value' => $this->options['plugin'],
    );

    $form['transition_effect'] = array(
      '#type' => 'select',
      '#title' => t('Transition effect'),
      '#options' => array(
        'fade' => t('fade'),
        'scrollUp' => t('scrollUp'),
        'shuffle' => t('shuffle'),
      ),
      '#default_value' => $this->options['transition_effect'],
    );

    $form['speed'] = array(
      '#type' => 'textfield',
      '#title' => t('Speed of the transition'),
      '#default_value' => $this->options['speed'],
      '#description' => t('Any valid fx speed value.'),
    );

    $form['width'] = array(
      '#type' => 'textfield',
      '#title' => t('Width'),
      '#default_value' => $this->options['width'],
    );

    $form['height'] = array(
      '#type' => 'textfield',
      '#title' => t('Height'),
      '#default_value' => $this->options['height'],
    );

    $form['items_per_slide'] = array(
      '#type' => 'select',
      '#title' => t('Items per slide'),
      '#options' => range(1, 20),
      '#default_value' => $this->options['items_per_slide'],
    );

  }

}