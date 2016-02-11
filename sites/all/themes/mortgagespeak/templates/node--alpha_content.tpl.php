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
	$body = '';
	$fullurl = 'http://' .$_SERVER['HTTP_HOST'];
	$url = $fullurl . '/' . drupal_get_path_alias('node/' . $node->nid);
	if(!empty($node->body['und']) && isset($node->body['und'])){
		$body = $node->body['und'][0]['value'];
	}
?>


<div class="node-main-container content-lists">
<div class="view-header"></div>
	<h2><?php print $node->title; ?></h2>
	<div class="node-share-content">
		<div class="share-title">
			<div class="share-title-sub">
				<span>Share this</span>
			</div>
		</div>
		<div class="share-icons">
			<div class="share-icon facebook-share">
				<a href="http://www.facebook.com/sharer.php?u=<?php echo $url; ?>&t=<?php echo $node->title; ?>" class="prfacebook">fb</a>
			</div>

			<div class="share-icon twitter-share">
				<a href="https://twitter.com/share?&text=<?php print $node->title;?>&url=<?php print $url; ?>" class="prtwitter-share-button" data-via="MortgageSpeak" data-count="none">twitter</a>
			</div>

			<div class="share-icon linkedin-share">
				<script src="http://platform.linkedin.com/in.js" type="text/javascript"></script>
				<script type="IN/Share"></script>
			</div>

			<div class="share-icon google-plus-share">
				<a href="https://plus.google.com/share?url=<?php print $url; ?>&body=<?php print $body; ?>" class="prgoogle"><img src="/sites/all/themes/mortgage_new_theme/images/g+.png" /></a>
			</div>

			<div class="share-icon contribute-share">
				<a href="<?php print $base_url; ?>/upload" target="_blank">Submit</a>
			</div>
	</div>

	<div class="alpha-content-body">
		<?php print $body;?>
	</div>

	<div class="pdf-upload-document"><?php 
		if(isset($node->field_upload_document['und']) && !empty($node->field_upload_document['und'] )){ ?>

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

</div>
<?php endif; ?>

