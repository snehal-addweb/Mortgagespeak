<?php
 /*
 * 
 * @file * Default simple view template to display a list of rows. 
 * * @ingroup views_templates 
 */ 
 ?>


<?php $rows = $view->style_plugin->rendered_fields; 
//$block = block_load('block',8);
//$output = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
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
	<?php foreach ($rows as $id => $row): 
		$title = $row['title'];
		$body = $row['body'];
		$nid = $row['nid'];
		if(!empty($row['url'])){
			$url = $row['url'];
		}
		else{
			$url = $fullurl . '/' . drupal_get_path_alias('node/' . $row['nid']);
		}
		$strFinal  =  $row['title']. '   ' . $row['body'];
		$strFinal = str_replace("\"", "'", $strFinal);
		$url = urlencode(html_entity_decode($url, ENT_COMPAT, 'UTF-8'));
		?>

	  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
			<div class="views-field views-field-body">
			    <span class="field-content">
			    	<?php print $row['field_pop_up']; ?>
			    </span>
			</div>
			<div class="views-field views-field-sharethis">    
			  <span class="views-label views-label-sharethis">More: </span>    
			  <span class="field-content">
				  <div class="sharethis-wrapper">

						<span class="chicklets linkedin">
							<a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>&summary=<?php print $body; ?>" class="linkedinshare"><img src="/sites/all/themes/mortgage_new_theme/images/link.png"/></a>
						</span>

						<span class="chicklets facebook">
							<a href='http://www.facebook.com/sharer.php?u=<?php print $url; ?>&t=<?php echo $title; ?>' class="facebook"><img src="/sites/all/themes/mortgage_new_theme/images/facebook1.png" /></a>
						</span>

						<span class="chicklets twitter">
							<a href="https://twitter.com/share?&text=<?php print $strFinal; ?>&url=<?php print $url; ?>" class="twitter-share-button" data-via="MortgageSpeak" data-count="none"><img src="/sites/all/themes/mortgage_new_theme/images/twitter1.png" /></a>
						</span>

						<span class="chicklets googleplus">
							<a href="https://plus.google.com/share?url=<?php print ($url); ?>&body=<?php print $body; ?>" class="google"><img src="/sites/all/themes/mortgage_new_theme/images/google1.png" /></a>
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
	<?php endforeach; ?>
	<div class="custom-ads"><?php print "Google Ads"; ?></div>
</div>