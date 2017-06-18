<?

/**
 * This module contains functions that will return content to PHP fields in
 * views
 *
 */

 /**
 * @param $row - a row field for a view result from the view 
 * airings_missing_show_content and shows_producer_dashboard/
 * @return $field 
 */
function pcm_show_producer_dashboard_shows_premiere_date_field($row) {
  $show = isset($row->nid) ? node_load($row->nid) : NULL;
  $airing = pcm_show_get_premiere_airing($row->nid);
  if ($airing) {
    $airing_start_date = 
      ($airing->field_data_field_airing_date_field_airing_date_value);
      
    if (isset($airing_start_date) && $airing_start_date) {
      $premiere_object = 
	new DateTime($airing_start_date, 
		       new DateTimeZone('UTC'));
      $premiere_object->setTimeZone(new DateTimeZone('America/Los_Angeles'));


      $premiere_date = $premiere_object->format('m/d/Y h:ia');
    }      
      
    $field = $premiere_date;
  }
  else {
    $field = "Not Scheduled";
  }
  return $field;
}


 /**
 * @param $row - a row for a view result from the view 
 * shows_producer_dashboard
 * @return boolean - TRUE remove row; FALSE do not remove row
 */
 /** USING A CONTEXTUAL FILTER INSTEAD
function pcm_show_producer_dashboard_shows_is_next_season_field(
                                            $row, $view, $handler) {
                                        
//if ($row->field_tv_guide_title == 14699) {
//  dpm($view, 'view');
//  dpm($handler, 'handler');
//}
  $airing = pcm_show_get_premiere_airing($row->nid);
  $airing_start_date = $airing ?
    $airing->field_data_field_airing_date_field_airing_date_value :
    NULL;

    if (isset($airing_start_date) && $airing_start_date) {
      $premiere_object = 
	new DateTime($airing_start_date, 
		       new DateTimeZone('UTC'));
      $premiere_object->setTimeZone(new DateTimeZone('America/Los_Angeles'));


      $premiere_date = $premiere_object->format('Y-m-d H:i:s');
    }

    
  // Fetch season
  $next_season = timespan_next(CM_SERIES_REQUEST_SEASON_TIMESPAN_NAME); 
  $is_next_season = strtotime($premiere_date) >= strtotime($next_season['start']) ?
      TRUE : FALSE;
 
  $roles = 
    array(CM_SERIES_REQUEST_PROGRAMMING_STAFF_ROLE,
		   CM_SERIES_REQUEST_SYS_ADMIN_ROLE,
       CM_SERIES_REQUEST_SITE_ADMIN_ROLE,
       CM_SERIES_REQUEST_SERIES_RENEWED_ROLE,
    );
  $is_staff = cm_series_request_user_has_role($roles) ?
    TRUE : FALSE;
    
$is_staff = false;    
 
  $display = variable_get(CM_SERIES_REQUEST_UPCOMING_AIRINGS_STATUS);  

  if (!$display && $is_next_season && !$is_staff)  {
    return TRUE; // remove     
  } 

  return FALSE; // do not remove 
}
**/