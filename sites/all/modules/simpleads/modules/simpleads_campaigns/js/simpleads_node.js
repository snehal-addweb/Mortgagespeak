/**
 * @file
 * Simpleads Campaigns node JS.
 */

(function ($) {
  Drupal.behaviors.simpleadsCampaignsListNode = {
    attach: function(context) {

      var selectCampaigns = $('form#simpleads-node-form #edit-field-adcamp-list select', context);

       _simpelads_campaigns_list(selectCampaigns, context);

      selectCampaigns.bind('change', function(){
         _simpelads_campaigns_list($(this), context);
      });

    }
  };
}(jQuery));

/**
 * Show/hide form elements.
 */
function _simpelads_campaigns_list(obj, context) {

  (function ($) {

    var campaign = obj.find('option:selected').val();
    var dateField = $('form#simpleads-node-form #edit-field-ad-date', context);

    if ( campaign != '_none' ) {
      dateField.hide();
    }
    else {
      dateField.show();
    }


  }(jQuery));

}
