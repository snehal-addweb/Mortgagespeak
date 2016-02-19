/**
 * @file
 * Simpleads Campaigns node JS.
 */

(function ($) {
  Drupal.behaviors.simpleadsCampaignsNode = {
    attach: function(context) {

       _simpelads_campaigns_switch_form();

      $('#edit-field-adcamp-type input[name*=field_adcamp_type]').bind('click', function(){
         _simpelads_campaigns_switch_form();
      });

    }
  };
}(jQuery));

/**
 * Show/hide form elements.
 */
function _simpelads_campaigns_switch_form() {

  (function ($) {

    $('form#simpleads-campaigns-node-form #edit-field-adcamp-impressions').hide();
    $('form#simpleads-campaigns-node-form #edit-field-adcamp-clicks').hide();
    $('form#simpleads-campaigns-node-form #edit-field-adcamp-date').hide();

    $('#edit-field-adcamp-type input[name*=field_adcamp_type]').filter(':checked').each(function(){
      $('form#simpleads-campaigns-node-form #edit-field-adcamp-' + $(this).val()).show();
    });


  }(jQuery));

}