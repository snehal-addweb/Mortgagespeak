<?php

/**
 * @file
 * views-simpleads.tpl.php
 */

?>
<?php if ( isset($rows) ) : ?>
<div data-fx="<?php print $options['transition_effect']; ?>" data-speed="<?php print $options['speed']; ?>" class="simpleads-wrapper">

  <?php if (isset($options['items_per_slide']) && $options['items_per_slide'] > 1) : ?>

    <?php $chunks = array_chunk($rows, $options['items_per_slide']); ?>

    <?php foreach ($chunks as $rows): ?>

      <div class="simpleads-chunk-item">

        <?php foreach ($rows as $id => $row): ?>

          <?php print theme('simpleads_type_' . $type[$id], array('output' => $row, 'type' => $type[$id], 'entity' => $entity[$id], 'options' => $options, 'css_classes' => $classes_array[$id])); ?>

        <?php endforeach; ?>

      </div>

    <?php endforeach; ?>

  <?php else : ?>

    <?php foreach ($rows as $id => $row): ?>

      <?php print theme('simpleads_type_' . $type[$id], array('output' => $row, 'type' => $type[$id], 'entity' => $entity[$id], 'options' => $options, 'css_classes' => $classes_array[$id])); ?>

    <?php endforeach; ?>

  <?php endif; ?>

</div>
<?php endif; ?>
