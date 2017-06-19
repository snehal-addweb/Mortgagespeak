<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */
?>
<?php  

  $company_tags = 'No';
  $random_top_display = 'Yes';
  $block = $left_skyscraper = $left_block_1 = $left_block_2 = $left_block_3 ='';


  if (arg(0) == 'welcome') {
   $random_top_display = 'No';
  }

  if (arg(0) == 'node' && is_numeric(arg(1)))
  {
    $nid = arg(1);
    $node = node_load($nid);

    if ($node->type == "alpha_content")
    {
      $random_top_display = 'No';
    }
    else {
      $random_top_display = 'Yes';
    }
  }

  if(arg(0) == 'taxonomy' && arg(1) == 'term' && is_numeric(arg(2))) {
    $tid = arg(2);
    $page_url = drupal_get_path_alias('taxonomy/term/' . arg(2)); 
    $term = taxonomy_term_load($tid);
    if ($term->vocabulary_machine_name == "company_tags")
    {
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'taxonomy_term')
      ->fieldCondition('field_page_url', 'value', $page_url, '=');
      $result = $query->execute();

      if(isset($result['taxonomy_term'])) {
        foreach ($result['taxonomy_term'] as $tidKey => $arrVal) {
          $term_info = taxonomy_term_load($arrVal->tid);
          if(isset($term_info->field_ads_company_tags) && !empty($term_info->field_ads_company_tags)) {
            if($term_info->field_ads_company_tags[LANGUAGE_NONE][0]['value'] == 'Yes') {
              $company_tags = 'Yes';
            }
          }
        }
      } 
    }
  }

// Render blocks for company tags taxonomy page and other.
  if($company_tags == 'Yes') {
    $block = block_load('views', '899f64e208d341b1043e1a20395c2073');
  }
  else {
    if($random_top_display == 'Yes') {
      $block = block_load('randomblocks', 'top_page');
    }
  }

// Render Left Skyscraper for company tags taxonomy page and other.

  if($company_tags == 'Yes') {
    $left_skyscraper = block_load('views', '42101e343498326f9dd68eaf990a394d');
  }
  else {
    if($random_top_display == 'Yes') {
     $left_skyscraper = block_load('randomblocks', 'left_skyscraper');
    }
  }
  
// Render Left Block 1 for company tags taxonomy page and other.
  if($company_tags == 'Yes') {
    $left_block_1 = block_load('views', 'd1eb806732708cacc3ca61f050433b0b');
  }
  else {
    if($random_top_display == 'Yes') {
      $left_block_1 = block_load('randomblocks', 'left_block_1');
    }
  }

// Render Left Block 2 for company tags taxonomy page and other.
  if($company_tags == 'Yes') {
    $left_block_2 = block_load('views', '081393740e200cfc34eeaa39f22a517d');
  }
  else {
    if($random_top_display == 'Yes') {
      $left_block_2 = block_load('randomblocks', 'left_block_2');
    }
  }


// Render Left Block 3 for company tags taxonomy page and other.
  if($company_tags == 'Yes') {
    $left_block_3 = block_load('views', 'eb34806d60cd56170767ff3f3b731561');
  }
  else {
    if($random_top_display == 'Yes') {
      $left_block_3 = block_load('randomblocks', 'left_block_3');
    }
  }



?>


<div class="top-header">
  <div class="container">
    <?php if (!empty($page['top_header'])): ?>
      <div>
        <?php print render($page['top_header']); ?>
      </div>
    <?php endif; ?>
  </div>
</div>

<header id="navbar" role="banner" class="navbar<?php /*print $navbar_classes;*/ ?>">
  <div class="nav-container <?php /*print $container_class;*/ ?>">
    <div class="navbar-header">
      <?php if ($logo): ?>
        <a class="logo navbar-btn pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
          <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
        </a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
        <a class="name navbar-brand" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a>
      <?php endif; ?>

      <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
        <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
          <span class="sr-only"><?php print t('Toggle navigation'); ?></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
          <span class="icon-bar"></span>
        </button>
      <?php endif; ?>
    </div>

    <?php if (!empty($primary_nav) || !empty($secondary_nav) || !empty($page['navigation'])): ?>
      <div class="navbar-collapse collapse">
        <nav role="navigation">
          <?php if (!empty($primary_nav)): ?>
            <?php print render($primary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($secondary_nav)): ?>
            <?php print render($secondary_nav); ?>
          <?php endif; ?>
          <?php if (!empty($page['navigation'])): ?>
            <?php print render($page['navigation']); ?>
          <?php endif; ?>
        </nav>
      </div>
    <?php endif; ?>
  </div>
</header>

<div class="main-container <?php print $container_class; ?>">  <!-- container-fluid p0 -->

  <header role="banner" id="page-header">
    <?php if (!empty($site_slogan)): ?>
      <p class="lead"><?php print $site_slogan; ?></p>
    <?php endif; ?>

    <?php print render($page['header']); ?>
  </header> <!-- /#page-header -->

  <div class="row"> <!-- m0 -->
    <?php if (!empty($page['sidebar_first'])): ?>
      <aside class="left-sidebar col-lg-2 col-md-2 col-sm-2 col-xs-12 p0" role="complementary">
        <?php print render($page['sidebar_first']); ?>

          <?php 
            if(!empty($left_skyscraper)) {
              $left_sky_render_array = _block_get_renderable_array(_block_render_blocks(array($left_skyscraper)));
              $output_left_sky = drupal_render($left_sky_render_array);
              print render($output_left_sky);
            }

            if(!empty($left_block_1)) {
              $left_block_1_render_array = _block_get_renderable_array(_block_render_blocks(array($left_block_1)));
              $output_left_block_1 = drupal_render($left_block_1_render_array);
              print render($output_left_block_1);
            }

            if(!empty($left_block_2)) {
              $left_block_2_render_array = _block_get_renderable_array(_block_render_blocks(array($left_block_2)));
              $output_left_block_2 = drupal_render($left_block_2_render_array);
              print render($output_left_block_2);
            }

            if(!empty($left_block_3)) {
              $left_block_3_render_array = _block_get_renderable_array(_block_render_blocks(array($left_block_3)));
              $output_left_block_3 = drupal_render($left_block_3_render_array);
              print render($output_left_block_3);
            }

          ?>
      </aside>  <!-- /#sidebar-first -->
    <?php endif; ?>

    <section<?php print $content_column_class; ?>>
      <?php if (!empty($page['highlighted'])): ?>
        <div class="highlighted">
          <?php 
            if(!empty($block)) {
              $render_array = _block_get_renderable_array(_block_render_blocks(array($block)));
              $output = drupal_render($render_array);
              print render($output);
            }
          ?>

        <?php print render($page['highlighted']); ?>
        </div>
      <?php endif; ?>
      <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>
      <a id="main-content"></a>
      <?php print render($title_prefix); ?>
      <?php if (!empty($title)): ?>
        <h1 class="page-header"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php print $messages; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
      <?php if (!empty($page['help'])): ?>
        <?php print render($page['help']); ?>
      <?php endif; ?>
      <?php if (!empty($action_links)): ?>
        <ul class="action-links"><?php print render($action_links); ?></ul>
      <?php endif; ?>
      <?php print render($page['content']); ?>
    </section>

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside class="right-sidebar col-lg-2 col-md-2 col-sm-2 col-xs-12 p0" role="complementary">
        <?php print render($page['sidebar_second']); ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>
  </div>

</div>

<?php if (!empty($page['footer'])): ?>
  <footer class="footer <?php /*print $container_class;*/ ?>">
    <?php print render($page['footer']); ?>
  </footer>
<?php endif; ?>
