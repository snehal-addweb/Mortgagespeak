jQuery(document).ready(function(){
	var loc = window.location.pathname;
	if(loc == '/user'){
		jQuery('.tabs--primary').find('a[href="/user/register"]').addClass('hide-register');
		jQuery('.tabs--primary').find('a[href="/user/password"]').addClass('hide-pass');
	}
});