<?php

/**
 * @file
 * Admin settings.
 * @TODO Working/experiment with this.
 */

/**
 * Admin form building function.
 */
function islandora_newspaper_landing_page_admin_settings($form, &$form_state) {
  // Include admin CSS file.
  //$admin_css = drupal_get_path('module', 'islandora_newspaper_landing_page') . '/css/islandora_newspaper_landing_page.admin.css';
  //drupal_add_css($admin_css);

  //Includes functions for connecting to Solr and Luke.
  module_load_include('inc', 'islandora_solr_search', 'includes/luke.inc');

  $form['newspaper_landing_page_admin'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
  );

  // Fields.
  $form['newspaper_landing_page_admin']['fields_data'] = array(
    '#type' => 'item',
    '#title' => t('Newspaper Landing Page Settings'),
    '#description' => t('Configure settings for the Islandora Newspaper Landing Page module.'),
    //'#tree' => TRUE,
    //'#theme' => 'islandora_newspaper_landing_page_admin_form',
  );

  // Get fields from variable.
  //$fields_data = variable_get('islandora_solr_facet_pages_fields_data', array());

  // Add 3 empty fields.
  //for ($i = 1; $i <= 3; $i++) {
  //  $fields_data[] = array('');
  //}

  /*
  $fields = array();
  foreach ($fields_data as $key => $value) {
    $field = array(
      'solr_field' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['solr_field']) ? $value['solr_field'] : '',
      ),
      'label' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['label']) ? $value['label'] : '',
      ),
      'path' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['path']) ? $value['path'] : '',
      ),
      'filter_field' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['filter_field']) ? $value['filter_field'] : '',
      ),
      'filter_value' => array(
        '#type' => 'textfield',
        '#default_value' => isset($value['filter_value']) ? $value['filter_value'] : '',
      ),
      'facet_count' => array(
        '#type' => 'checkbox',
        '#default_value' => isset($value['facet_count']) ? $value['facet_count'] : '',
      ),
      'link_object' => array(
        '#type' => 'checkbox',
        '#default_value' => isset($value['link_object']) ? $value['link_object'] : '',
      ),
    );
    $fields[] = $field;
  }
  */

  // Add fields.
  //$form['facet_pages']['islandora_solr_facet_pages_fields_data']['fields'] = $fields;

  /*
  $form['newspaper_landing_page_admin']['sort_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Sort Field'),
    '#size' => 35,
    '#default_value' => variable_get('islandora_newspaper_landing_page_sort_field', "PARENT_dateIssued_dt"),
    '#description' => t('Set the sort field of the "All front pages" search result'),
  );
  */

  $form['newspaper_landing_page_admin']['sort_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Sort Field'),
    '#size' => 35,
    '#autocomplete_path' => 'islandora_solr/luke',
    //'#default_value' => '',
    '#default_value' => variable_get('islandora_newspaper_landing_page_sort_field', "PARENT_dateIssued_dt"),
    '#description' => t('Set the sort field of the "All front pages" search result'),
  );

  /*
  $terms['add_solr_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Add another item'),
    '#size' => 45,
    '#autocomplete_path' => 'islandora_solr/luke',
    '#default_value' => '',
  );
  */

  $form['newspaper_landing_page_admin']['sort_order'] = array(
    '#type' => 'select',
    '#title' => t('Sort Order'),
    '#options' => array(
      'asc' => t('Ascending'),
      'desc' => t('Descending'),
    ),
    '#default_value' => variable_get('islandora_newspaper_landing_page_sort_order', 0),
    '#description' => t('Set the sort order of the "All front pages" search result'),
  );

/*
  foreach ($options as $o) {
    $form['facet_pages']['islandora_solr_facet_pages_facet_limit']['#options'][$o] = number_format($o);
  }

*/
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 50,
  );
  $form['buttons']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#weight' => 51,
  );

  return $form;
}

/**
 * Theme callback.
 */
/*
function theme_islandora_solr_facet_pages_admin_table(&$vars) {
  // Set variable.
  $rows = array();
  $form = $vars['form'];

  // Render islandora_solr_primary_display_table.
  foreach ($form['fields'] as $key => $elements) {

    $row = array();
    // Check if $key is really the array we need. we shouldn't select the
    // #parent array for example.
    if (is_array($elements) && element_child($key)) {

      $row[] = array('data' => drupal_render($form['fields'][$key]['solr_field']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['label']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['path']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['filter_field']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['filter_value']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['facet_count']));
      $row[] = array('data' => drupal_render($form['fields'][$key]['link_object']));
      $rows[] = $row;
    }
  }

  // Individual table headers.
  $header = array();
  $header[] = array('data' => t('Solr Field'));
  $header[] = array('data' => t('Label'));
  $header[] = array('data' => t('Path'));
  $header[] = array('data' => t('Filter Field'));
  $header[] = array('data' => t('Filter Value'));
  $header[] = array('data' => t('Facet Count'));
  $header[] = array('data' => t('Link Object'));

  // Render table.
  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array(
      'id' => 'islandora-solr-facet-pages-admin-table',
    ),
  ));

  return $output;
}
*/

/**
 * Implements hook_validate().
 */
function islandora_newspaper_landing_page_admin_settings_validate($form, &$form_state) {

  // On save.
  if ($form_state['clicked_button']['#id'] == 'edit-submit') {

    // Check for valid paths.
    //foreach ($form_state['values']['islandora_solr_facet_pages_fields_data']['fields'] as $key => $value) {
    //  if (!preg_match("/^[a-zA-Z0-9-_]*$/", $value['path'])) {
    //    form_set_error('islandora_solr_facet_pages_fields_data][fields][' . $key . '][path', t('The path can only contain the following characters: a-z, A-Z, 0-9, - and _'));
    //  }

      //TESTING
    //  if($value['facet_count'])
    //    $form_state['values']['islandora_solr_facet_pages_fields_data']['fields'][$key]['link_object'] = 0;
    //}

    // Get limit value.
    //$limit = $form_state['values']['islandora_solr_facet_pages_limit'];
    //$limit = trim($limit);
    // Check numeric.
    //if (!is_numeric($limit)) {
    //  form_set_error('islandora_solr_facet_pages_limit', t('Exposed results must be numeric.'));
    //}
    // Check for no decimals.
    //if (strpos($limit, '.')) {
    //  form_set_error('islandora_solr_facet_pages_limit', t('Exposed results cannot be decimals.'));
    //}
  }
}

/**
 * Implements hook_submit().
 */
function islandora_newspaper_landing_page_admin_settings_submit($form, &$form_state) {

  // Get operation.
  $op = $form_state['triggering_element']['#id'];

  switch ($op) {
    case 'edit-submit':
      // Set variables.
      variable_set('islandora_newspaper_landing_page_sort_field', trim($form_state['values']['sort_field']));
      variable_set('islandora_newspaper_landing_page_sort_order', $form_state['values']['sort_order']);
      //$fields_data = $form_state['values']['islandora_solr_facet_pages_fields_data']['fields'];
      //foreach ($fields_data as $key => $value) {
      //  if (empty($value['solr_field']) AND empty($value['label']) AND empty($value['path'])
      //    AND empty($value['filter_field']) AND empty($value['filter_value'])) {
      //    unset($fields_data[$key]);
      //  }
      //}
      //variable_set('islandora_solr_facet_pages_fields_data', $fields_data);
      //variable_set('islandora_solr_facet_pages_limit', trim($form_state['values']['islandora_solr_facet_pages_limit']));
      //variable_set('islandora_solr_facet_pages_facet_limit', $form_state['values']['islandora_solr_facet_pages_facet_limit']);

      drupal_set_message(t('The configuration options have been saved.'));
      break;

    //case 'edit-reset':
      // Empty variables.
      // Remove variables.
      //$variables = array(
        //'islandora_solr_facet_pages_fields_data',
        //'islandora_solr_facet_pages_limit',
        //'islandora_solr_facet_pages_facet_limit',
      //);
      //foreach ($variables as $variable) {
        //variable_del($variable);
      //}

      //drupal_set_message(t('The configuration options have been reset to their default values.'));
      //break;
  }
}

/**
 * Admin autocomplete callback which returns solr fields from Luke.
 *
 * @param string $string
 *   String filled out in the autocomplete textfield.
 * @return json
 *   A json array containing the Solr luke values that contain the given string.
 */
function _islandora_solr_autocomplete_luke($string = '') {

  $luke = islandora_solr_get_luke();
  $result = array();
  // loop over luke fields
  foreach ($luke['fields'] as $term => $value) {
    // if string is found in the solr term
    if (stripos($term, $string) !== FALSE) {
      // add strong elements to highlight the found string. Search case
      // insensitive, but keep the case on replace.
      // http://stackoverflow.com/a/3489768/477949
      $term_str = preg_replace("/$string/i", "<strong>\$0</strong>", $term);
      $result[$term] = $term_str . '<strong style="position: absolute; right: 5px;">(' . $value['type'] . ')</strong>';
    }
  }
  // sort alphabetically
  ksort($result);

  drupal_json_output($result);
  exit();
}
