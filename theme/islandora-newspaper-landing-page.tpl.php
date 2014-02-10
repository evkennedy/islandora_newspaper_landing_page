<?php
/**
 * @file
 * Load the newspaper landing page.
 */

?>

<div class="islandora-content-wrapper">

  <!-- Left side bar begins. -->
  <div class="left-sidebar">

    <?php if (strlen($variables['mods']['title']) > 0): ?>
      <div class="element">
        <div class="attribute">Title:</div>
        <div class="value"><?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['place']) > 0): ?>
      <div class="element">
        <div class="attribute">Place of Publication:</div>
        <div class="value"><?php print $variables['mods']['place']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['geographic']) > 0): ?>
      <div class="element">
        <div class="attribute">Geographic Coverage:</div>
        <div class="value"><?php print $variables['mods']['geographic']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['publisher']) > 0): ?>
      <div class="element">
        <div class="attribute">Publisher:</div>
        <div class="value"><?php print $variables['mods']['publisher']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['pubDate']) > 0): ?>
      <div class="element">
        <div class="attribute">Date of Publication:</div>
        <div class="value"><?php print $variables['mods']['pubDate']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['frequency']) > 0): ?>
      <div class="element">
        <div class="attribute">Frequency:</div>
        <div class="value"><?php print $variables['mods']['frequency']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['language']) > 0): ?>
      <div class="element">
        <div class="attribute">Language:</div>
        <div class="value"><?php print $variables['mods']['language']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['geographic']) > 0 OR strlen($variables['mods']['topic']) > 0 OR strlen($variables['mods']['temporal']) > 0): ?>
      <div class="element">
        <div class="attribute">Subject(s):</div>
        <div class="value">
          <?php if (strlen($variables['mods']['geographic']) > 0): ?>
            <?php print $variables['mods']['geographic']; ?>
            <?php if (strlen($variables['mods']['topic']) > 0): ?>
              <?php print " --<br/>" . $variables['mods']['topic']; ?>
            <?php endif; ?>
            <?php if (strlen($variables['mods']['temporal']) > 0): ?>
              <?php print "--<br/>" . $variables['mods']['temporal']; ?>
            <?php endif; ?>
          <?php elseif (strlen($variables['mods']['topic']) > 0): ?>
            <?php print $variables['mods']['topic']; ?>
            <?php if (strlen($variables['mods']['temporal']) > 0): ?>
              <?php print "--<br/>" . $variables['mods']['temporal']; ?>
            <?php endif; ?>
          <?php elseif (strlen($variables['mods']['temporal']) > 0): ?>
            <?php print $variables['mods']['temporal']; ?>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['note']) > 0): ?>
      <div class="element">
        <div class="attribute">Notes:</div>
        <div class="value"><?php print $variables['mods']['note']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (strlen($variables['mods']['issn']) > 0): ?>
      <div class="element">
        <div class="attribute">ISSN:</div>
        <div class="value"><?php print $variables['mods']['issn']; ?></div>
      </div>
    <?php endif; ?>

    <?php if (isset($variables['mods']['preceding'])): ?>
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
    <?php endif; ?>

    <?php if (isset($variables['mods']['succeeding'])): ?>
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
    <?php endif; ?>

    <?php if (strlen($variables['mods']['credit']) > 0): ?>
      <div class="element">
        <div class="attribute">Credit:</div>
        <div class="value">
          <?php print $variables['mods']['credit']; ?>
        </div>
        </div>
    <?php endif; ?>

  </div>
  <!-- Left side bar ends. -->

  <!-- Right side bar header begins. -->
  <div class="right-sidebar-header">

    <div class="widget-1">
      <img src="<?php print $variables['front_cover_image'] ?>" />
    </div>

    <div class="widget-2">

      <div class="widget-2-title"><?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></div>

      <?php if (isset($variables['num_issues'])): ?>
        <div class="widget-2-content">
          <div class="widget-2-image" id="widget-calendar"></div>
          <a href="<?php print $variables['view_path'] ?>">Calendar view</a>
        </div>

        <div class="widget-2-content">
          <div class="widget-2-image" id="widget-pages"></div>
          <a href="<?php print $variables['front_pages_path'] ?>">All front pages</a>
        </div>

        <!-- Only show first issue link if at least 1 issue and only show last issue link if > 1 issue. -->
        <div class="widget-2-content">
          <a href="<?php print $variables['first_issue_path']; ?>">First Issue</a>
          <?php if ($variables['num_issues'] > 1): ?>
            <?php print "&nbsp;&nbsp;|&nbsp;&nbsp;"; ?>
            <a href="<?php print $variables['last_issue_path']; ?>">Last Issue</a>
          <?php endif; ?>
        </div>
      <?php endif; ?>
    </div>

  </div>
  <!-- Right side bar header ends. -->

  <!-- Right side bar begins, if prospectus text available. -->
  <?php if (strlen($variables['mods']['prospectus']) > 1): ?>
    <div class="right-sidebar">
      <p>
        <b>About <?php if ($variables['mods']['non_sort'] != "") {print $variables['mods']['non_sort'] . " ";} print $variables['mods']['title']; ?></b>
        <br/>
        <?php print $variables['mods']['prospectus']; ?>
      </p>
    </div>
    <?php if (strlen($variables['mods']['prospectus']) > 475): ?>
      <div class="readandmore">
        <a href="#" class="more">Read more...</a>
      </div>
    <?php endif; ?>
  <?php endif; ?>
  <!-- Right side bar ends. -->

</div>