<?php
 /*
 * 
 * @file * Default simple view template to display a list of rows. 
 * * @ingroup views_templates 
 */ 
 ?>


<?php $rows = $view->style_plugin->rendered_fields; 
    //$block = module_invoke('randomblocks', 'block_view', 'pop_up_tab');  
    //$block = module_invoke('block', 'block_view', '8');  
?>
<?php 
	global $base_url;
	global $user;
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
	$save_img = $base_url . '/sites/all/themes/mortgagespeak/images/star-blank-sm.png';
?>

<script type="text/javascript">
  function customCopyText(objId) {
    var copyTextarea = document.querySelector('#' + objId);
    copyTextarea.select();
    try {
      var successful = document.execCommand('copy');
      var msg = successful ? 'successful' : 'unsuccessful';
      console.log('Copying text command was ' + msg);
    }
    catch (err) {
      console.log('Oops, unable to copy');
    }
  }
</script>

<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="popup-main-container">
<div class="popup-header">
	<div class="popup-title">Excerpt</div>
	<div class="tooltips">
		<div class="whats-this">(<span>What's this?</span>)</div>
		<div class="tooltip-content">Save time. Article key point.</div>
	</div>
	<a href="javascript:void(0);" class="close-popup">x</a>
</div>
	<?php foreach ($rows as $id => $row): 
		$title = $row['title'];
		$body = $row['body'];
		$nid = $row['nid'];

		$flag_link = '';
		$flag_dest = '';

		$get_destination = drupal_get_destination();
		if(isset($get_destination['destination']) && !empty($get_destination['destination'])) {
		  $flag_dest = $get_destination['destination'];
		}

		if($user->uid) {
		  $flag_link = $row['ops'];
		}
		else {
		  $flag_link =  '<a href="user/?destination='. $flag_dest .'" title="Click to save content" class="flag flag-action flag-link-toggle flag-processed" rel="nofollow"><img src="'.$save_img.'"></a>';
		}

  	$title_link = $base_url .'/'. drupal_get_path_alias('node/' . $row['nid']);
		$url1 = $fullurl .'/'. drupal_get_path_alias('node/' . $row['nid']);

		if(!empty($row['field_upload_document'])){
			//$title_link = 'https://docs.google.com/viewerng/viewer?url=' .$row['field_upload_document'];
			$pop_title_link = $base_url .'/'. drupal_get_path_alias('node/' . $row['nid']);
			//$url1 = $fullurl .'/'. drupal_get_path_alias('node/' . $row['nid']);
		}
		else if(!empty($row['field_url'])){
			//$url1 = $row['field_url'];
			$pop_title_link = $row['field_url'];
		}
		else{
			//$url1 = $fullurl .'/'. drupal_get_path_alias('node/' . $row['nid']);
			$pop_title_link = $base_url .'/'. drupal_get_path_alias('node/' . $row['nid']);
		}

		$strFinal  =  $row['title'];	//. '   ' . $row['body'];
		$strFinal = str_replace("\"", "'", $strFinal);
		$url = urlencode(html_entity_decode($url1, ENT_COMPAT, 'UTF-8'));
		?>

	  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
	  
			<div class="pop-up-content">
				<div class="views-field views-field views-field-title">        
					<a href="<?php print $pop_title_link;?>" target="_blank"><?php print $title; ?>
					</a>
				</div>
				<div class="views-field views-field-sharethis">
					<div class="view-on-web"><a href="<?php print $pop_title_link;?>" target="_blank">View on web</a></div>
					<div class="sharethis-content">
					  <span class="field-content">
						  <div class="sharethis-wrapper">

								<span class="chicklets linkedin">
									<a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>&summary=<?php print $strFinal; ?>" target='_blank' class="linkedinshare" title="Share on LinkedIN"><img src="/sites/all/themes/mortgage_new_theme/images/link.png"/></a>
								</span>

								<span class="chicklets facebook">
									<a href='http://www.facebook.com/sharer.php?u=<?php print $url; ?>&t=<?php echo $strFinal; ?>' target='_blank' class="facebook" title="Share on Facebook"><img src="/sites/all/themes/mortgage_new_theme/images/facebook1.png" /></a>
								</span>

								<span class="chicklets twitter">
									<a href="https://twitter.com/share?&text=<?php print $strFinal; ?>&url=<?php print $url; ?>" target='_blank' class="twitter-share-button" data-via="MortgageSpeak" data-count="none" title="Share on Twitter"><img src="/sites/all/themes/mortgage_new_theme/images/twitter1.png" /></a>
								</span>

								<span class="chicklets googleplus">
									<a href="https://plus.google.com/share?url=<?php print ($url); ?>&body=<?php print $strFinal; ?>" target='_blank' class="google" title="Share on Google+"><img src="/sites/all/themes/mortgage_new_theme/images/google1.png" /></a>
								</span>

								<span class="chicklets email">
									<a href='mailto:Article@MortgageSpeak.com?subject=<?php echo $title; ?>&body=I wanted to share this article with you: <?php print ($url. '     ' .$body); ?>' class="email" target="_blank" title="Email this content"><img src="/sites/all/themes/mortgage_new_theme/images/mail1.png" /></a>
								</span>

								<span class="chicklets copy-to-clipboard">
								  <textarea class="js-copytextarea" id="copypopuptext_<?php print $nid; ?>"><?php print $title_link; ?></textarea>
							    <a href="javascript:void(0)" class="copy-link js-textareacopybtn" title="Copy link to clipboard" onclick="customCopyText('copypopuptext_<?php print $nid; ?>');">Copy Textarea</a>
			    			</span>

							</div> 
							 <!-- Flag link-->
							 <?php print $flag_link; ?>
						</span>
					</div>
				</div>
				<div class="views-field views-field-body">
					<span class="field-content quote">
						<?php print $row['field_pop_up']; ?>
					</span>
				</div>
			</div>
			<div class="custom-ads"><?php print views_embed_view('custom_ads_for_pr_and_perpesctive','block_6', $nid); ?></div>
	  </div>
	<?php endforeach; ?>
</div>