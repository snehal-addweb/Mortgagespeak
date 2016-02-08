<div class="register-container login-form">
  <div class="register-text login-text">Upload: To upload your content and minimize SPAM submissions, please <a href="/user/login">log in</a> or <a href="/user/register">register</a>.</div>
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
      <div class="register-free"><?php $block = module_invoke('block', 'block_view', '13');
        print render($block['content']);
      ?></div> 
    </div>
  </div>
</div>