jQuery(document).ready(function() {

  // JS Code for Custom checkbox design
  jQuery('input[type="radio"], input[type="checkbox"]').wrap('<div class="input-rc"></div>');
  jQuery('.input-rc').append('<span class="input-rc-span"></span>');
  // End

  // Add class in form pages
  var loc = window.location.pathname;
  if(loc == '/user'){
    jQuery('.tabs--primary').find('a[href="/user/register"]').addClass('hide-register');
    jQuery('.tabs--primary').find('a[href="/user/password"]').addClass('hide-pass');
  }
  // End

  // Select all
  jQuery('#edit-select-all--2').change(function(){
    var check = this.checked;
    if(check == true){
       jQuery('.field-type-taxonomy-term-reference #edit-field-news-topics-und--2 .form-type-checkbox .form-checkbox').prop('checked', true);  
    }
    else{
       jQuery('.field-type-taxonomy-term-reference #edit-field-news-topics-und--2 .form-type-checkbox .form-checkbox').prop('checked', false);
    }
  });
  // End

  jQuery('.page-my-page-tracked-companies ul.menu li:nth-child(2)').addClass('active-trail active');
  jQuery('.page-my-page-tracked-companies ul.menu li:nth-child(2) a').addClass('active-trail active');
  jQuery('.page-my-page-saved-articles ul.menu li:nth-child(2)').addClass('active-trail active');
  jQuery('.page-my-page-saved-articles ul.menu li:nth-child(2) a').addClass('active-trail active');

  /* Popup design */
  jQuery('body').click(function() {
    jQuery('.content-lists .content-list .views-popup-container').removeClass('open-popup');
  });

  jQuery('.content-lists .content-list .views-popup-container').click(function(e) {
    e.stopPropagation();
  });

  jQuery('.content-lists .content-list > .views-field-title').click(function(e) {
    e.stopPropagation();
    if(jQuery(this).parent().children('.content-lists .content-list .views-popup-container').hasClass('open-popup')) {
        jQuery(this).parent().children('.open-popup').removeClass('open-popup');
    }
    else {
      jQuery('.content-lists .content-list .views-popup-container').removeClass('open-popup');
      jQuery(this).parent().children('.content-lists .content-list .views-popup-container').addClass('open-popup');
    }
  });

  jQuery('.views-popup-container .popup-header .close-popup').click(function() {
    jQuery('.content-lists .content-list .views-popup-container').removeClass('open-popup');
  });

    jQuery(document).keydown(function(e) {
    if (e.keyCode == 27) {
        /*window.close();*/
        jQuery('.content-lists .content-list .views-popup-container').removeClass('open-popup');
    }
  });
  /* End */

  /* Custom input type file design */
  jQuery('input[type="file"]').wrap('<div class="input-file"><div class="input-file-sub"></div></div>');
  jQuery('.input-file').append('<span class="input-file-name">No file chosen</span>');
  jQuery('.input-file-sub input').change(function() {
    var filename = jQuery(this).val();
    jQuery(this).parent().parent().children(".input-file-name").text(filename);
  });
  /* End */

  /* Change Upload Text in Upload webform*/
  jQuery('#webform-client-form-42 .attach-content .form-managed-file button').text('Upload File');

  jQuery(document).ajaxComplete(function() {
    jQuery('#webform-client-form-42 .attach-content .form-managed-file button').text('Upload File');
  });
  /* End */

  /* Add class to view if it is empty */
  if (jQuery('.view.content-lists').find('.view-empty').length == 1) {   
    jQuery('.view.content-lists').addClass('content-lists-empty');
  }
  /* End */

  /* Reset Button for Search view */
  jQuery( "#edit-reset" ).click(function( event ) {
    event.preventDefault();
    jQuery('#edit-search-api-views-fulltext').val('');
  });
  /* End */

  jQuery('.page-my-page-tracked-companies #edit-company-tag').change(function() {
      jQuery('.page-my-page-tracked-companies #edit-company-tag1').find('option:first').attr('selected', 'selected');
  });

  jQuery('.page-my-page-tracked-companies #edit-company-tag1').change(function() {
      jQuery('.page-my-page-tracked-companies #edit-company-tag').find('option:first').attr('selected', 'selected');
  });

  jQuery( "#views-exposed-form-tracked-companies-page .views-exposed-widgets select" ).change(function() {
    var current_val = jQuery(this).val();                                                          
    jQuery("#views-exposed-form-tracked-companies-page .views-exposed-widgets select").val("All");
    jQuery(this).val(current_val);
  });
});

/* Set Max height to Sidebar and Content */
jQuery(window).bind("load", function() {
  //alert('sdaf');
  var leftsideHeight = 0;
  var contentHeight = 0;
  var hightlightedHeight = 0;

  leftsideHeight = jQuery('.left-sidebar').outerHeight() + 30;
  contentHeight = jQuery('.content-area').outerHeight();
  region_content = jQuery('.region-content').outerHeight() + 30;

  var new_contentHeight = leftsideHeight - (contentHeight - region_content);
  //var content_border = contentHeight - hightlightedHeight;

  console.log('left'+leftsideHeight);
  console.log('content'+contentHeight);
  console.log('region_content'+region_content);
  console.log('new_contentHeight'+new_contentHeight);

  if (leftsideHeight > contentHeight) {
    console.log('if');
    jQuery('.content-lists, .webform-client-form, .page-user #block-system-main form, .login-upload-page, #block-block-15').css('min-height', new_contentHeight);
    jQuery('.left-sidebar').css('min-height', leftsideHeight);
  }
  else if (leftsideHeight < contentHeight) {
    console.log('else');
    jQuery('.left-sidebar').css('min-height', contentHeight);
    jQuery('.content-lists, .webform-client-form, .page-user #block-system-main form').css('min-height', new_contentHeight);
  }
});
/* End */
