<?php
/**
 * @file
 * Load the newspaper landing page.
 */

?>

<div class="islandora-content-wrapper">

  <!-- Left side bar begins. -->
  <div class="left-sidebar">

    <div class="element">
      <div class="attribute">Title:</div>
      <div class="value"><?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Place of Publication:</div>
      <div class="value"><?php print $variables['mods']['place']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Geographic Coverage:</div>
      <div class="value"><?php print $variables['mods']['geographic']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Publisher:</div>
      <div class="value"><?php print $variables['mods']['publisher']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Date of Publication:</div>
      <div class="value"><?php print $variables['mods']['pubDate']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Frequency:</div>
      <div class="value"><?php print $variables['mods']['frequency']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Language:</div>
      <div class="value"><?php print $variables['mods']['language']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Subject(s):</div>
      <div class="value">
        <?php print $variables['mods']['geographic'] ? $variables['mods']['geographic'] . " -- " : ""; ?>
        <?php print $variables['mods']['topic'] ? $variables['mods']['topic'] . " -- " : ""; print $variables['mods']['temporal']; ?>
      </div>
    </div>

    <div class="element">
      <div class="attribute">Notes:</div>
      <div class="value"><?php print $variables['mods']['note']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">ISSN:</div>
      <div class="value"><?php print $variables['mods']['issn']; ?></div>
    </div>

    <div class="element">
      <div class="attribute">Preceding Titles:</div>
      <div class="value">
        <?php
          if (isset($variables['mods']['preceding'])) {
            foreach ($variables['mods']['preceding'] as $title) {
              print $title . "<br />";
            }
          }
        ?>
      </div>
    </div>

    <div class="element">
      <div class="attribute">Succeeding Titles:</div>
      <div class="value">
        <?php
          if (isset($variables['mods']['succeeding'])) {
            foreach ($variables['mods']['succeeding'] as $title) {
              print $title . "<br />";
            }
          }
        ?>
      </div>
    </div>

    <div class="element">
      <div class="attribute">Credit:</div>
      <div class="value">
        <?php print $variables['mods']['credit']; ?>
      </div>
    </div>
  </div>
  <!-- Left side bar ends. -->

  <!-- Right side bar header begins. -->
  <div class="right-sidebar-header">

    <div class="widget-1">
      <img src="<?php print $variables['front_cover_image'] ?>" />
    </div>

    <div class="widget-2">
      <div class="widget-2-title"><?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></div>
      <div class="widget-2-content">
        <div class="widget-2-image" id="widget-calendar"></div>
        <a href="<?php print $variables['view_path'] ?>">Calendar view</a>
      </div>

      <div class="widget-2-content">
        <div class="widget-2-image" id="widget-pages"></div>
        <a href="<?php print $variables['front_pages_path'] ?>">All front pages</a>
      </div>

      <!-- Only show first issue link if at least 1 issue and only show last issue link if > 1 issue. -->
      <?php if (isset($variables['num_issues'])): ?>
        <div class="widget-2-content">
          <a href="<?php print $variables['first_issue_path']; ?>">First Issue</a>
          <?php if ($variables['num_issues'] > 1): ?>
            | <a href="<?php print $variables['last_issue_path']; ?>">Last Issue</a>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </div>
  </div>
  <!-- Right side bar header ends. -->

  <!-- Right side bar begins, if prospectus text available. -->
  <?php if (strlen($variables['mods']['prospectus']) > 1): ?>
    <div class="right-sidebar">
        <!--
        <div class="attribute">
          About <?php //if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?>
        </div>
        -->
      <p>
        <b>About <?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></b>
        <br/>
        <?php print $variables['mods']['prospectus']; ?>
      </p>
      <!-- Only show read more link if character count > 1335. -->
      <?php if (strlen($variables['mods']['prospectus']) > 1335): ?>
        <p class="read-more">
          <a href="#" class="more">Read more...</a>
        </p>
        <br /><br />
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <!-- Right side bar ends. -->

</div>