<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php $rows = $view->style_plugin->rendered_fields; ?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
    <div class="views-field views-field-title">
      <span class="field-content">
        <!-- <a href="<?php print $row['field_url']; ?>"> -->
        <div class="editor-title click-title">
          <div class="editor-pick">
            <div class="ed-img"></div>
            <span><?php print $row['title']; ?></span>
          </div>
        </div>
      <!--   </a> -->
      </span>
    </div>
    <div class="views-popup-container"><?php print views_embed_view('popup_views','block_1', $row['nid']); ?></div>
  </div>
<?php endforeach; ?>