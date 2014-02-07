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
  );

  $form['newspaper_landing_page_admin']['sort_field'] = array(
    '#type' => 'textfield',
    '#title' => t('Sort Field'),
    '#size' => 35,
    '#autocomplete_path' => 'islandora_solr/luke',
    '#default_value' => variable_get('islandora_newspaper_landing_page_sort_field', "PARENT_dateIssued_dt"),
    '#description' => t('Set the sort field of the "All front pages" search result'),
  );

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
 * Implements hook_validate().
 */
function islandora_newspaper_landing_page_admin_settings_validate($form, &$form_state) {
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

      drupal_set_message(t('The configuration options have been saved.'));
      break;
  }
}