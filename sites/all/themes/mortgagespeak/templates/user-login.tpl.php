<div class="register-container login-form">
	<div class="register-text login-text">Welcome to MortgageSpeak.com!</div>
		<div class="login-left">			
			<span class="login-title">Log in</span>
			<?php print $name; // Display username field ?>
			<?php print $pass; // Display Password field ?>
			<?php print $rendered; // Display hidden elements (required for successful login) ?> 
			<?php print $submit; // Display submit button ?>
			<div class="forget-links">
			    <span class="passlink"><a href="/user/password">Forget?</a></span>
			</div>
		</div>
		<div class="login-right">
			<div class="register-free">Or <a href="/user/register">REGISTER (free)</a></div> 
		</div>
	</div>
</div>