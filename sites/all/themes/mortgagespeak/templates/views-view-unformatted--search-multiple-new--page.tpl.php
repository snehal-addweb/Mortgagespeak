<?php
 /*
 * 
 * @file * Default simple view template to display a list of rows. 
 * * @ingroup views_templates 
 */ 
 ?>


<?php $rows = $view->style_plugin->rendered_fields;?>
<?php 
	global $base_url;
	global $user;
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): 
	$title = $row['node_title'];
	$body = strip_tags($row['node_body_value']);
	$nid = $row['node_nid'];
	if(!empty($row['node_field_url'])){
		$url1 = $row['node_field_url'];
	}
	else{
		$url1 = $fullurl . '/' . drupal_get_path_alias('node/' . $row['node_nid']);
	}
	$strFinal  =  $row['node_title'];	//. '   ' . $body;
	$strFinal = str_replace("\"", "'", $strFinal);
	$url = urlencode(html_entity_decode($url1, ENT_COMPAT, 'UTF-8'));
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

  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
		<div class="views-field views-field-created">
			<span class="field-content"><?php print $row['node_created']; ?></span>  
		</div>

		<div class="views-field views-field views-field-title">        
			<span class="field-content">
				<?php print $title; ?>
		</div> 

		<div class="views-field views-field-body">
	    <span class="field-content">
	    	<?php print $row['node_body_value']; ?>
	    </span>
		</div>

		<div class="views-field views-field-field-alpha-news-topics">    
			<span class="views-label views-label-field-alpha-news-topics">Mortgage Topic:</span>    
			<div class="field-content">
				<?php print $row['node_field_alpha_news_topics']; ?>
			</div>  
		</div><?php 
		if(!empty($row['node_field_company_tag'])) { 
			if(in_array('administrator', $user->roles) || in_array('News Intelligence', $user->roles)) {
				?><div class="views-field views-field-field-company-tag">    
					<span class="views-label views-label-field-company-tag">Company: </span>    
					<div class="field-content"><?php print $row['node_field_company_tag']; ?></div>  
				</div><?php
			}
		}
		?><div class="views-field views-field-sharethis">    
		  <span class="views-label views-label-sharethis">More: </span>    
		  <span class="field-content">
			  <div class="sharethis-wrapper">

					<span class="chicklets linkedin">
						<a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>&summary=<?php print $strFinal; ?>" target="_blank" class="linkedinshare" title="Share on LinkedIN"><img src="/sites/all/themes/mortgage_new_theme/images/link.png"/></a>
					</span>

					<span class="chicklets facebook">
						<a href='http://www.facebook.com/sharer.php?u=<?php print $url; ?>&t=<?php echo $strFinal; ?>' target="_blank" class="facebook" title="Share on Facebook"><img src="/sites/all/themes/mortgage_new_theme/images/facebook1.png" /></a>
					</span>

					<span class="chicklets twitter">
						<a href="https://twitter.com/share?&text=<?php print $strFinal; ?>&url=<?php print $url; ?>" target="_blank" class="twitter-share-button" data-via="MortgageSpeak" data-count="none" title="Share on Twitter"><img src="/sites/all/themes/mortgage_new_theme/images/twitter1.png" /></a>
					</span>

					<span class="chicklets googleplus">
						<a href="https://plus.google.com/share?url=<?php print ($url); ?>&body=<?php print $strFinal; ?>" target="_blank" class="google" title="Share on Google+"><img src="/sites/all/themes/mortgage_new_theme/images/google1.png" /></a>
					</span>

					<span class="chicklets email">
						<a href='mailto:Article@MortgageSpeak.com?subject=<?php echo $title; ?>&body=I wanted to share this article with you: <?php print ($url. '     ' .$body); ?>' class="email" target="_blank" title="Email this content"><img src="/sites/all/themes/mortgage_new_theme/images/mail1.png" /></a>
					</span>

					<span class="chicklets copy-to-clipboard">
					  <textarea class="js-copytextarea" style="display:none;" id="copytext_<?php print $nid; ?>"><?php print $url1; ?></textarea>
				    <a href="javascript:void(0)" class="copy-link js-textareacopybtn" title="Copy to Clipboard" onclick="customCopyText('copytext_<?php print $nid; ?>');">Copy Textarea</a>
    			</span>
    			
				</div> 
				 <!-- Flag link-->
				 <?php //print $row['ops'];?>
			</span>  
		</div> 
		<div class="views-popup-container"><?php print views_embed_view('popup_views','block_1', $nid); ?></div>
  </div>
<?php endforeach; ?>
