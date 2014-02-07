/**
 * @file
* Handles the 'Read More...' link generated for About section on right side bar.
 */

jQuery(document).ready(function(){

    jQuery(".more").click(function(){

      jQuery( ".more" ).css( "display", "none" );

      jQuery( ".right-sidebar" )
        .css({
          overflow : 'visible',
          'max-height' : '9999px'
        });

      jQuery( ".right-sidebar" ).animate({ "height": "auto" });

      return false;
    })
});