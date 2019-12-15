<?php

/**          
 * @file
* Contains the Crew Node argument default plugin.
*/

/**
* Default argument plugin to filter on current Crew Node.
*
* @ingroup views_argument_default_plugins
*/
class pcm_show_argument_date_range extends views_plugin_argument_default {
  function get_argument() {
    //will return a date range similar to "2000-01-01--2024-04-07"
    $date_range = pcm_menu_get_dashboard_season_end_date();
    return $date_range;
  }
}                