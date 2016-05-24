<?php
	global $base_url;
	$register_link = '';
	$flag_dest = '';
	$get_destination = drupal_get_destination();
	if(isset($get_destination['destination']) && !empty($get_destination['destination'])) {
		$flag_dest = $get_destination['destination'];
	}

	if($user->uid) {
	  $register_link = flag_create_link('company_follow_unflollow', arg(2));
	}
	else {
	  $register_link =  l(t('REGISTER (free)'), 'user/register', array('query'=> array('destination' => $flag_dest)));
	}
?>

<div class="register-container login-form">
	<div class="register-text login-text">Welcome to MortgageSpeak.com!</div>
		<div class="login-left">			
			<span class="login-title">Log in</span>
			<?php print $name; // Display username field ?>
			<?php print $pass; // Display Password field ?>
			<?php print $rendered; // Display hidden elements (required for successful login) ?> 
			<?php print $submit; // Display submit button ?>
			<div class="forget-links">
			    <span class="passlink"><a href="/user/password">Forgot?</a></span>
			</div>
		</div>
		<div class="login-right">
			<?php $block = module_invoke('block', 'block_view', '14');
				print render($block['content']);;
			?>
			<div class="register-free"><?php print $register_link; ?></div> 
		</div>
	</div>
</div>