<?php
 /*
 * 
 * @file * Default simple view template to display a list of rows. 
 * * @ingroup views_templates 
 */ 
 ?>


<?php $rows = $view->style_plugin->rendered_fields; 
    $block = module_invoke('block', 'block_view', '8');    
?>
<?php 
	global $base_url;
	global $user;
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<div class="popup-main-container">
<div class="popup-header">
	<div class="popup-title">Excerpt Time-Saver</div>
	<div class="tooltips">
		<div class="whats-this">( What's this? )</div>
		<div class="tooltip-content">Save time. Article key point.</div>
	</div>
	<a href="#" class="close-popup">x</a>
</div>
	<?php foreach ($rows as $id => $row): 
		$title = $row['title'];
		$body = $row['body'];
		$nid = $row['nid'];
		if(!empty($row['field_upload_document'])){
			$title_link = 'https://docs.google.com/viewerng/viewer?url=' .$row['field_upload_document'];
			$url = $fullurl .'/'. drupal_get_path_alias('node/' . $row['nid']);
		}
		else if(!empty($row['field_url'])){
			$url = $row['field_url'];
			$title_link = $row['field_url'];
		}
		else{
			$url = $fullurl .'/'. drupal_get_path_alias('node/' . $row['nid']);
			$title_link = $base_url .'/'. drupal_get_path_alias('node/' . $row['nid']);
		}

		$strFinal  =  $row['title']. '   ' . $row['body'];
		$strFinal = str_replace("\"", "'", $strFinal);
		$url = urlencode(html_entity_decode($url, ENT_COMPAT, 'UTF-8'));
		?>

	  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
			<div class="views-field views-field views-field-title">        
				<a href="<?php print $title_link;?>" target="_blank"><?php print $title; ?>
				</a>
			</div> 

			<div class="views-field views-field-sharethis">
				<div class="sharethis-content">
				  <span class="field-content">
					  <div class="sharethis-wrapper">

							<span class="chicklets linkedin">
								<a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>&summary=<?php print $body; ?>" target='_blank' class="linkedinshare"><img src="/sites/all/themes/mortgage_new_theme/images/link.png"/></a>
							</span>

							<span class="chicklets facebook">
								<a href='http://www.facebook.com/sharer.php?u=<?php print $url; ?>&t=<?php echo $title; ?>' target='_blank' class="facebook"><img src="/sites/all/themes/mortgage_new_theme/images/facebook1.png" /></a>
							</span>

							<span class="chicklets twitter">
								<a href="https://twitter.com/share?&text=<?php print $strFinal; ?>&url=<?php print $url; ?>" target='_blank' class="twitter-share-button" data-via="MortgageSpeak" data-count="none"><img src="/sites/all/themes/mortgage_new_theme/images/twitter1.png" /></a>
							</span>

							<span class="chicklets googleplus">
								<a href="https://plus.google.com/share?url=<?php print ($url); ?>&body=<?php print $body; ?>" target='_blank' class="google"><img src="/sites/all/themes/mortgage_new_theme/images/google1.png" /></a>
							</span>

							<span class="chicklets email">
								<a href='mailto:Article@MortgageSpeak.com?subject=<?php echo $title; ?>&body=I wanted to share this article with you: <?php print ($url. '     ' .$body); ?>' class="email" target="_blank"><img src="/sites/all/themes/mortgage_new_theme/images/mail1.png" /></a>
							</span>
						</div> 
						 <!-- Flag link-->
						 <?php print $row['ops'];?>
					</span>
				</div>
			</div>
			<div class="views-field views-field-body">
				<span class="field-content quote">
					<?php print $row['field_pop_up']; ?>
				</span>
			</div> 
			<div class="custom-ads"><?php print render($block['content']); ?></div>
	  </div>
	<?php endforeach; ?>
</div>