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

  

});

});