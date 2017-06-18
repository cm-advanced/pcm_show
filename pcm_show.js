(function ($) {
  Drupal.behaviors.pcmShow = {
    attach: function (context, settings) { 
      ////////////////////////////////////////////////////////////////////////
      //ON READY FUNCTION
      $(document).ready(function() {
	var show_nid = $("#pcm_show_nid_div_cache").text();
	var episode_number = $("#pcm_episode_number_div_cache").text();
	var special_and_hidden = 
	  $("#pcm_show_is_special_and_hidden_div_cache").text();
	
	$("#edit-field-episode-number-und-0-value").val(episode_number);

	$("#pcm_show_nid_div_cache").hide();
	$("#pcm_episode_number_div_cache").hide();

	$("#edit-field-show-is-special-und").parent().
	  append($("#pcm_airing_wrapper"));
	if ($("#edit-field-show-is-special-und").is(":checked")) {
	  $("#pcm_airing_wrapper").hide();
	}
	else {
	  $("#pcm_airing_wrapper").show();
	}
	if (special_and_hidden == 'yes') {
	  $("#edit-field-episode-number").hide();
	}
	if ($("#edit-field-show-is-special-und").is(":checked")) {
	  $('#node_cm_show_form_group_show_playback_preferences').show();
	}
	else {
	  //$('#node_cm_show_form_group_show_playback_preferences').hide();
	}

	var is_series = $("#pcm_show_is_series_div_cache").text();

	if ($("#pcm_show_is_series_div_cache").text() == 'yes') {
	  	console.log('yee');
	  $('#node_cm_show_form_group_show_playback_preferences').hide();
	}

	$(".field-name-field-show-is-special").
	  not('.field-widget-options-onoff').hide();

	//display field
	//field field-name-field-show-is-special field-type-list-boolean field-label-inline clearfix

	//edit field
	//field-type-list-boolean field-name-field-show-is-special field-widget-options-onoff form-wrapper
      });

      ////////////////////////////////////////////////////////////////////////
      //ON CHANGE FUNCTION FOR THE is-special FIELD
      $("#edit-field-show-is-special-und", context).change(function() {
	var show_nid = $("#pcm_show_nid_div_cache").text();
	var episode_number = $("#pcm_episode_number_div_cache").text();

	if ($("#edit-field-show-is-special-und").is(":checked")) {
	  $("#pcm_airing_wrapper").hide();
	  $("#edit-field-episode-number-und-0-value").val("");
	  $('#node_cm_show_form_group_show_playback_preferences').show();
	}
	else {
	  $("#pcm_airing_wrapper").show();
	  $("#edit-field-episode-number-und-0-value").val(episode_number);
	  $('#node_cm_show_form_group_show_playback_preferences').hide();
	}
      });
    }};  
}) (jQuery);
