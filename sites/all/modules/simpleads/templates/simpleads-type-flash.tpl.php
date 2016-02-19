<?php

/**
 * @file
 * Flash advertisement
 * simpleads-type-flash.tpl.php
 */

?>
<div class="<?php print $css_classes; ?>" data-id="<?php print $entity->nid; ?>">
  <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000" codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=6,0,40,0" width="<?php print $width; ?>" height="<?php print $height; ?>" id="ad-<?php print $entity->nid; ?>">

    <param name="movie" value="<?php print $src; ?>" />
    <param name="quality" value="high" />
    <param name="bgcolor" value="#ffffff" />
    <param name="wmode" value="transparent" />

    <?php if ($url) : ?>
      <param value="clickTAG=<?php print $url; ?>" name="flashvars" />
    <?php endif; ?>

    <embed src="<?php print $src; ?>" quality="high" bgcolor="#ffffff" width="<?php print $width; ?>" height="<?php print $height; ?>" name="ad-<?php print $entity->nid; ?>" align="" type="application/x-shockwave-flash" pluginspage="http://www.macromedia.com/go/getflashplayer"></embed>

  </object>
</div>
