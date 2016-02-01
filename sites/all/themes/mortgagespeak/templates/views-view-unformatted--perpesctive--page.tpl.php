<?php
 /*
 * 
 * @file * Default simple view template to display a list of rows. 
 * * @ingroup views_templates 
 */ 
 ?>


<?php $rows = $view->style_plugin->rendered_fields; ?>
<?php 
	global $base_url;
	global $user;
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): 
	$title = $row['title'];
	$body = $row['body'];
	$nid = $row['nid'];
	$url = $fullurl . '/' . drupal_get_path_alias('node/' . $row['nid']);
	$strFinal  =  $row['title']. '   ' . $row['body'];
	$strFinal = str_replace("\"", "'", $strFinal);
	$url = urlencode(html_entity_decode($url, ENT_COMPAT, 'UTF-8'));
?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
		<div class="views-field views-field-php">
			<span class="field-content"><?php print $row['php']; ?></span>
		</div> 

		<div class="views-field views-field-created">
			<span class="field-content"><?php print $row['created']; ?></span>  
		</div>

		<div class="views-field views-field views-field-title">        
			<span class="field-content">
				<a href="<?php print $base_url;?>/popup-views/<?php print $nid;?>" class="simple-dialog" rel="width:900;resizable:false;position:[center,60]" name="block-views-popup-views-block-1" title="My Dialog Title"><?php print $title; ?></a>
		</div> 

		<div class="views-field views-field-body">
	    <span class="field-content">
	    	<?php print $row['body']; ?>
	    </span>
		</div>

		<div class="views-field views-field-field-alpha-news-topics">    
			<span class="views-label views-label-field-alpha-news-topics">Topic:</span>    
			<div class="field-content">
				<?php print $row['field_alpha_news_topics']; ?>
			</div>  
		</div> 

		<?php if(in_array('News Intelligence', $user->roles) || in_array('administrator', $user->roles)) {?>
			<div class="views-field views-field-field-company-tag">    
				<span class="views-label views-label-field-company-tag">Company: </span>    
				<div class="field-content"><?php print $row['field_company_tag']; ?></div>  
			</div><?php
		 } ?>

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