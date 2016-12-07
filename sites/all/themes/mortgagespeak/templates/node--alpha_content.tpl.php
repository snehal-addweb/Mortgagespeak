<script type="text/javascript" src="https://apis.google.com/js/plusone.js"></script>
<div id="fb-root"></div>
<script>(function(d, s, id) {
	var js, fjs = d.getElementsByTagName(s)[0];
	if (d.getElementById(id)) return;
	js = d.createElement(s); js.id = id;
	js.src = "//connect.facebook.net/en_US/all.js#xfbml=1";
	fjs.parentNode.insertBefore(js, fjs);
}(document, 'script', 'facebook-jssdk'));</script>

<?php $current_url = 'http://' .$_SERVER['HTTP_HOST'] .$_SERVER['REQUEST_URI']; ?>

<?php if ($page == 0): ?>
	<div><?php print l($node->title, 'node/'.$node->nid); ?> </div>
<?php else : ?>

<?php
	global $base_url;
	global $user;
	$body = '';
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
	$url = $fullurl . '/' . drupal_get_path_alias('node/' . $node->nid);
  $strFinal  =  $node->title;
  $strFinal = urlencode(html_entity_decode($strFinal, ENT_COMPAT, 'UTF-8'));
	if(!empty($node->body['und']) && isset($node->body['und'])){
		$node_body = $node->body['und'][0]['value'];
		$body = strip_tags($node_body);
    $nodedata = truncate_utf8($body, 150, FALSE, TRUE, 1); 
    $share_linked_data = urlencode(html_entity_decode($nodedata, ENT_COMPAT, 'UTF-8'));

	}
	$flag_link = '';
  $flag_dest = '';

  $get_destination = drupal_get_destination();
  if(isset($get_destination['destination']) && !empty($get_destination['destination'])) {
    $flag_dest = $get_destination['destination'];
  }

  if($user->uid) {
    $flag_link = flag_create_link('saved_articles', $node->nid);
  }
  else {
    $flag_link =  '<a href="user/?destination='. $flag_dest .'" title="Click to save content" class="flag flag-action flag-link-toggle flag-processed" rel="nofollow"><img src="'.$save_img.'"></a>';
  }
?>

<?php // Copy to clipboard script ?>
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

<div class="node-main-container">
	<!-- <div class="view-header"></div> -->
	<h2><?php print $node->title; ?></h2>
	<div class="node-share-content">
		<div class="share-title">
			<div class="share-title-sub">
				<span>Share this</span>
			</div>
		</div>
		<div class="share-icons">
			<div class="share-icon facebook-share">
				<a href="http://www.facebook.com/sharer.php?u=<?php echo $url; ?>&t=<?php echo $strFinal ?>" class="prfacebook" target="_blank" title="Share on Facebook">fb</a>
			</div>

			<div class="share-icon twitter-share">
				<a href="https://twitter.com/share?&text=<?php print $strFinal;?>&url=<?php print $url; ?>" target="_blank" class="prtwitter-share-button" data-via="MortgageSpeak" data-count="none" title="Share on Twitter">twitter</a>
			</div>

			<div class="share-icon linkedin-share" title="Share on LinkedIN">
				<!-- <script src="http://platform.linkedin.com/in.js" type="text/javascript"></script>
				<script type="IN/Share"></script> -->
        <a href="http://www.linkedin.com/shareArticle?mini=true&url=<?php print $url; ?>&summary=<?php print $share_linked_data; ?>" target="_blank" class="linkedinshare" title="Share on LinkedIN">twitter</a>
			</div>

			<div class="share-icon google-plus-share">
				<a href="https://plus.google.com/share?url=<?php print $url; ?>&body=<?php print $body; ?>" target="_blank" class="prgoogle" title="Share on Google+"><img src="/sites/all/themes/mortgage_new_theme/images/g+.png" /></a>
			</div>
			
			<div class="share-icon copy-to-clipboard">
				<textarea class="js-copytextarea" id="copytext_<?php print $node->nid;?>"><?php print $url; ?></textarea>
	      <a href="javascript:void(0)" class="js-textareacopybtn" title="Copy link to clipboard" onclick="customCopyText('copytext_<?php print $node->nid; ?>');">Copy Textarea</a>
      </div>
			
			<div class="share-icon save-flag">
				<?php print $flag_link; ?>
			</div>
	</div>

	<div class="alpha-content-body">
		<?php print $node_body;?>
	</div>

	<div class="pdf-upload-document"><?php 
		if(isset($node->field_upload_document['und']) && !empty($node->field_upload_document['und'] )) { ?>

		<div class="document-presc">
		<?php     
		$pdf_url = file_create_url($node->field_upload_document['und'][0]['uri']);
		$html = theme('pdf_reader', array('file' => array('uri' => $pdf_url), 'settings' => array(
		'renderer' => 'google',
		)));
		print('<a target="_blank" href="' . $pdf_url . '">Click here to download the PDF file.</a> <br />');
		print $html;
		?>
		</div><?php 
	} 
	?>	
	</div>
  <div><?php
  if(isset($node->field_url[LANGUAGE_NONE]) && !empty($node->field_url[LANGUAGE_NONE])) {
    $ext_url = $node->field_url[LANGUAGE_NONE][0]['value'];
    ?>
      <div class="ext-read-more"><a href="<?php print $ext_url?>" target="_blank">Read full article</a></div>
    <?php
  }
  ?></div>
  <div class="alpha-comments-container">
		<div class="node-comments" id="node-comments"><?php print 'Comments   <span class="dot"></span><span class="comment-count">'. $comment_count .'</span>'; ?></div>
		<div id="goal-comments-wrapper" class="goal-comment-wrapper">
			<?php 
			$nid = $node->nid;
			$comment = new stdClass;
			$comment->nid = $nid;
			$node = node_load($nid);
			$form = drupal_get_form('comment_form', $comment);
			//print render($form);
			//$node = node_load($id);
			$node_view = node_view($node);
			$node_view['comments'] = comment_node_page_additions($node);
			print drupal_render($node_view['comments']);
			?>
		</div>
  </div>
</div>
<?php endif; ?>

