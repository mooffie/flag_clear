<?php

/**
 * Implementation of hook_views_data_alter().
 */
function flag_clear_views_data_alter(&$data) {
  $data['flag_counts']['reset_link'] = array(
    'title' => t('Reset link'),
    'help' => t('Displays a link for clearing all the flaggings for an item.'),
    'field' => array(
      'handler' => 'flag_clear_handler_field_link_reset',
    ),
  );
  $data['flag_content']['remove_link'] = array(
    'title' => t('Remove link'),
    'help' => t('Displays a link for removing a single flagging.'),
    'field' => array(
      'handler' => 'flag_clear_handler_field_link_remove',
    ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function flag_clear_views_handlers() {
  return array(
    'handlers' => array(
      'flag_clear_handler_field_link_reset' => array(
        'parent' => 'views_handler_field',
        'file' => 'flag_clear.views_links.inc',
      ),
      'flag_clear_handler_field_link_remove' => array(
        'parent' => 'views_handler_field',
        'file' => 'flag_clear.views_links.inc',
      ),
    ),
  );
}
