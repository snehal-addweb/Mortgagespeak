<?php

/**
 * @file
 * Default theme implementation for comments.
 *
 * Available variables:
 * - $author: Comment author. Can be link or plain text.
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $created: Formatted date and time for when the comment was created.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->created variable.
 * - $changed: Formatted date and time for when the comment was last changed.
 *   Preprocess functions can reformat it by calling format_date() with the
 *   desired parameters on the $comment->changed variable.
 * - $new: New comment marker.
 * - $permalink: Comment permalink.
 * - $submitted: Submission information created from $author and $created during
 *   template_preprocess_comment().
 * - $picture: Authors picture.
 * - $signature: Authors signature.
 * - $status: Comment status. Possible values are:
 *   comment-unpublished, comment-published or comment-preview.
 * - $title: Linked title.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - comment: The current template type, i.e., "theming hook".
 *   - comment-by-anonymous: Comment by an unregistered user.
 *   - comment-by-node-author: Comment by the author of the parent node.
 *   - comment-preview: When previewing a new or edited comment.
 *   The following applies only to viewers who are registered users:
 *   - comment-unpublished: An unpublished comment visible only to administrators.
 *   - comment-by-viewer: Comment by the user currently viewing the page.
 *   - comment-new: New comment since last the visit.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * These two variables are provided for context:
 * - $comment: Full comment object.
 * - $node: Node object the comments are attached to.
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_comment()
 * @see template_process()
 * @see theme_comment()
 *
 * @ingroup themeable
 */

  $time_ago = $comment->created;
  $cur_time   = time();
  $time_elapsed   = $cur_time - $time_ago;
  $seconds  = $time_elapsed ;
  $minutes  = round($time_elapsed / 60 );
  $hours    = round($time_elapsed / 3600);
  $days     = round($time_elapsed / 86400 );
  $weeks    = round($time_elapsed / 604800);
  $months   = round($time_elapsed / 2600640 );
  $years    = round($time_elapsed / 31207680 );
  // Seconds
  if($seconds <= 60){
    $left_time =  "$seconds seconds ago";
  }
  //Minutes
  else if($minutes <=60){
    if($minutes==1){
      $left_time =  "one minute ago";
    }
    else{
      $left_time =  "$minutes minutes ago";
    }
  }
  //Hours
  else if($hours <=24){
    if($hours==1){
      $left_time =  "an hour ago";
    }else{
      $left_time =  "$hours hours ago";
    }
  }
  //Days
  else if($days <= 7){
    if($days==1){
      $left_time =  "yesterday";
    }else{
      $left_time =  "$days days ago";
    }
  }
  //Weeks
  else if($weeks <= 4.3){
    if($weeks==1){
      $left_time =  "a week ago";
    }else{
      $left_time =  "$weeks weeks ago";
    }
  }
  //Months
  else if($months <=12){
    if($months==1){
      $left_time =  "a month ago";
    }else{
      $left_time =  "$months months ago";
    }
  }
  //Years
  else{
    if($years==1){
      $left_time =  "one year ago";
    }else{
      $left_time =  "$years years ago";
    }
  }




$uid = user_load($comment->uid);
$user_fname = $uid->field_first_name['und'][0]['value'];
$user_lname = $uid->field_last_name['und'][0]['value'];

if(!empty($comment->uid)) {
  $author_name = $user_fname . " " . $user_lname;
}
else {
  $author_name = $author;
}

?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
  <?php print $picture ?>
  
  <?php print render($title_prefix); ?>
  <h3<?php print $title_attributes; ?>><?php print $title ?></h3>
  <?php print render($title_suffix); ?>

  <div class="submitted">
    <?php print $permalink; ?>
    <span class="cmt-user"><?php print $author_name; ?></span>
    <span class="cmt-created"><?php print $left_time; ?></span>
  </div>

  <div class="content"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['links']);
      print render($content);
    ?>
    <?php if ($signature): ?>
    <div class="user-signature clearfix">
      <?php print $signature ?>
    </div>
    <?php endif; ?>
  </div>

  <?php print render($content['links']) ?>
</div>
