<?php

/**
 * @file
 * Customize the display of a complete webform.
 *
 * This file may be renamed "webform-form-[nid].tpl.php" to target a specific
 * webform on your site. Or you can leave it "webform-form.tpl.php" to affect
 * all webforms on your site.
 *
 * Available variables:
 * - $form: The complete form array.
 * - $nid: The node ID of the Webform.
 *
 * The $form array contains two main pieces:
 * - $form['submitted']: The main content of the user-created form.
 * - $form['details']: Internal information stored by Webform.
 *
 * If a preview is enabled, these keys will be available on the preview page:
 * - $form['preview_message']: The preview message renderable.
 * - $form['preview']: A renderable representing the entire submission preview.
 */
?>
<?php

/*  // Print out the progress bar at the top of the page
  print drupal_render($form['progressbar']);

  // Print out the preview message if on the preview page.
  if (isset($form['preview_message'])) {
    print '<div class="messages warning">';
    print drupal_render($form['preview_message']);
    print '</div>';
  }

  // Print out the main part of the form.
  // Feel free to break this up and move the pieces within the array.
  print drupal_render($form['submitted']);

  // Always print out the entire $form. This renders the remaining pieces of the
  // form that haven't yet been rendered above (buttons, hidden elements, etc).*/
global $base_url;
?>
<div class="upload-main-container">
	<div class="upload-upper-contain">
		<label>Upload</label>
	</div>

	<div class="upload-below-contain">
		<div class="upload-type">
		<label>1. What Are You Uploading?</label><?php 
			print render($form['submitted']['upload_type']); 
		?></div>
		
		<div class="attach-content">
			<label>2. Attach Content</label>
			<?php print render($form['submitted']['attach_content']);?>
			<div class="description">
				<div>File must be less than <span>6MB</span></div>
				<div class="allowed-files">Allowed file types: <span>pdf doc docx</span></div>
			</div>
		</div>
		
		<div class="upload-email-noti">
			<label>3. Email Notification/Record</label>
			<div><?php print render($form['submitted']['send_me_a_link']);?></div>
			<div><?php print render($form['submitted']['email']);?></div>
		</div>
	</div>
	<div class="upload-submit">
		<div><?php print drupal_render_children($form);?></div>
		<label>By clicking "Submit" you agree to our <a href="<?php print $base_url; ?>/terms-and-conditions">terms and conditions</a>.</label>
	</div>
</div>



