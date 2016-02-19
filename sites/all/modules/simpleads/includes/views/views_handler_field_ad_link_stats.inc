<?php

/**
 * @file
 * Definition of views_handler_field_ad_link_stats.
 */

/**
 * Field handler to present a advertisement statistics page.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_ad_link_stats extends views_handler_field_node_link {

  /**
   * Renders the link.
   */
  function render_link($node, $values) {

    // Ensure user has access to edit this node.
    if (!user_access('access advertisement statistics')) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "node/$node->nid/stats";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('stats');
    return $text;

  }

}
