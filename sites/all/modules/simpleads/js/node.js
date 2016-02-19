/**
 * @file
 * SimpleAds node JS.
 */

(function ($) {
  Drupal.behaviors.simpleadsNode = {
    attach: function(context) {

      var advertisementType = $('#edit-field-ad-type select[id^=edit-field-ad-type]', context);
      var ad_type = advertisementType.val();

      _simpelads_switch_form(ad_type);

      advertisementType.change(function(){
        ad_type = $(this).val();
        _simpelads_switch_form(ad_type);
      });

    }
  };
}(jQuery));

/**
 * Show/hide form elements.
 */
function _simpelads_switch_form(ad_type) {

  (function ($) {

    el_image = $('form#simpleads-node-form #edit-field-ad-image');
    el_flash = $('form#simpleads-node-form #edit-field-ad-flash');
    el_text = $('form#simpleads-node-form #edit-field-ad-text');

    if (ad_type == 'graphic') {

      el_image.show();
      el_flash.hide();
      el_text.hide();

    }
    else if (ad_type == 'text') {

      el_text.show();
      el_image.hide();
      el_flash.hide();

    }
    else if (ad_type == 'flash') {

      el_flash.show();
      el_image.hide();
      el_text.hide();

    }

  }(jQuery));

}