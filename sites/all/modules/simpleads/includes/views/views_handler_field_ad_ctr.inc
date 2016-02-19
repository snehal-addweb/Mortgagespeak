<?php

/**
 * @file
 * Definition of views_handler_field_ad_ctr.
 */

/**
 * Field handler to present Click-thorugh rate value.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_ad_ctr extends views_handler_field {

   function query() {
     // do nothing -- to override the parent query.
   }

  /**
   * Render value.
   */
  function render($values) {
    $stats = is_object($values) ? $values : new stdClass();
    $click_though_rate = 0;

    if (isset($stats->simpleads_stats_clicks_unique) && isset($stats->simpleads_stats_impressions_unique)) {

      if ( $stats->simpleads_stats_clicks_unique > 0 && $stats->simpleads_stats_impressions_unique > 0 ) {
        $click_though_rate = ( $stats->simpleads_stats_clicks_unique / $stats->simpleads_stats_impressions_unique ) * 100;
      }

    }

    return number_format($click_though_rate, 4, '.', '') . '%';
  }

}
