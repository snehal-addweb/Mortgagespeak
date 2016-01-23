jQuery(document).ready(function() {
  /* JS Code for Custom checkbox design */
  jQuery('input[type="radio"], input[type="checkbox"]').wrap('<div class="input-rc"></div>');
  jQuery('.input-rc').append('<span class="input-rc-span"></span>');
  /* End */
  var loc = window.location.pathname;
  if(loc == '/user'){
    jQuery('.tabs--primary').find('a[href="/user/register"]').addClass('hide-register');
    jQuery('.tabs--primary').find('a[href="/user/password"]').addClass('hide-pass');
  }
});