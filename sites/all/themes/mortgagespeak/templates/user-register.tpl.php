<?php
global $base_url;
?>
<div class="register-container">
<div class="register-text">Register for <span class="green-text">free</span> here! Already have an account? <a href="<?php print $base_url; ?>/user" class="blue-text">Log in here.</a></div>

<div class="user-register-pic">
  <div class="register-my-details">
  <div class="my-details-header">My Details</div>
    <?php

    print render($form['account']['name']);?>
    <div class="field-type-wrap"><?php
      print render ($form['field_first_name']);
      print render ($form['field_last_name']);
    ?></div><?php
      print render($form['account']['mail']);
      print render ($form['account']['pass']);
    ?>
    <hr/>
  </div>

  <div class="user-pic-reg">
    <div class="def-img-text">
      <div class="default-img"><img src="<?php print $base_url; ?>/sites/default/files/Default-Headshot.png"></div>
      <div class="def-text"><span>Image will be resized to fit:</span><span>65w X 65h pixels</span></div>
    </div>
    <?php print render($form['picture']); ?>
  </div>
  
</div>

<div class="register-my-page-details">
  <div class="my-page-details-header">"My Page" Details

  </div>
  <span class="news-text">Follow these "news topics" Tracked in your custom page.

  </span>

  <?php 
    print render($form['select_all']);
    print render($form['field_news_topics']);
  ?>
    <hr/>
</div>

<?php 
  print render($form['captcha']);

  print drupal_render($form['actions']);
  print drupal_render($form['form_build_id']);
  print drupal_render($form['form_id']);
?>

<div class="register-bottom-text"><span>By clicking the button, you agree to our <a href="<?php print $base_url; ?>/terms-and-conditions">terms and conditions</a>.</span><span>Already have an account? <a href="<?php print $base_url; ?>/user">Log in here.</a></span></div>
</div>