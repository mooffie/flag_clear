<?php

/**
 * Base class from with the "Reset" and "Remove" links inherit.
 */
class flag_clear_handler_field_link extends views_handler_field {

  function query() {
    $this->ensure_my_table();
    // The field isn't a DB column, so no need to load it, but we do need to load any 'additional fields'.
    $this->add_additional_fields();
  }

  function option_definition() {
    $options = parent::option_definition();
    $options['text'] = array('default' => '', 'translatable' => TRUE);
    return $options;
  }

  // Make these links available to admins only.
  function access() {
    return user_access('administer flags');
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display for the link'),
      '#default_value' => $this->options['text'],
    );
  }
}

class flag_clear_handler_field_link_remove extends flag_clear_handler_field_link {

  function construct() {
    parent::construct();
    $this->additional_fields['fcid'] = 'fcid';
  }

  function render($values) {
    $fcid = $values->{$this->aliases['fcid']};

    // We show the link only when the flagging exists. When $fcid is NULL, it means the
    // flagging doesn't exist (and we're on the right side of a LEFT JOIN).
    if ($fcid) {
      $text = !empty($this->options['text']) ? $this->options['text'] : t('Remove this flagging');
      return l($text, 'flag/remove/' . $fcid, array('query' => drupal_get_destination()));
    }
  }
}

class flag_clear_handler_field_link_reset extends flag_clear_handler_field_link {

  function construct() {
    parent::construct();
    $this->additional_fields += array(
      'count'      => 'count',
      'fid'        => 'fid',
      'content_id' => 'content_id',
    );
  }

  function render($values) {
    $count      = $values->{$this->aliases['count']};
    $fid        = $values->{$this->aliases['fid']};
    $content_id = $values->{$this->aliases['content_id']};

    // See "LEFT JOIN" comment above.
    if ($count) {
      $flag = flag_get_flag(NULL, $fid);
      $text = !empty($this->options['text']) ? $this->options['text'] : t('Remove all the flaggings (@count exist)', array('@count' => $count));
      return l($text, 'flag/reset/' . $flag->name . '/' . $content_id, array('query' => drupal_get_destination()));
    }
  }
}
