<?php
global $base_url;

?>
<div class="register-container">
<div class="register-text">Register for <span class="green-text">free</span> here! Already have an account? <a href="<?php print $base_url; ?>/user" class="blue-text">Log in here.</a></div>
<?php

print render($form['account']['name']);
print render($form['account']['mail']);
print render ($form['account']['pass']);
print render($form['field_news_topics']);

print drupal_render($form['actions']);
print drupal_render($form['form_build_id']);
print drupal_render($form['form_id']);

?>
<div class="register-bottom-text"><span>By Clicking the button, you agree to our terms and conditions</span><span>Already have an account? <a href="<?php print $base_url; ?>/user">Log in here.</a></span></div>
</div>