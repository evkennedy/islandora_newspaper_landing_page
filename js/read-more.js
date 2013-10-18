/**
 * @file
* Handles the 'Read More...' link generated for About on right side bar.
 */

var $el, $ps, $up, totalHeight;

jQuery(document).ready(function(){

  jQuery(".more").click(function(){

  totalHeight = 0
  $el = jQuery(this);
  $p  = $el.parent();
  $up = $p.parent();
  $ps = $up.find("p:not('.read-more')");

  // Measure how high inside by adding together heights of all inside paragraphs (except read-more).
  $ps.each(function() {
    totalHeight += jQuery(this).outerHeight();
  });

  $up
    .css({
      // Set height to prevent instant jump down when max height is removed.
      "height": ($up.height() + 150),
      "max-height": 9999
    })
      .animate({
        "height": totalHeight
    });

    // Fade out read-more.
    $p.fadeOut();

    return false;
    })
});