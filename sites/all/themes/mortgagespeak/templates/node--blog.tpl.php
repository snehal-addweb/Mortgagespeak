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

</div>
<?php endif; ?>
