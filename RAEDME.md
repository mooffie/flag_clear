Overview
--------

The [Flag][1] module has one omission: when an item is flagged by
several users (assuming it's a non-global flag), there's no easy way to
unclear all these flaggings at once. This module provides a "Reset link"
field for Views for doing this.

Note: This module does **not** display this link under each node, but
you can install the [Custom Links][2] module to achieve this: set your
link to `flag/reset/bookmarks/[nid]`.

This module also provides a "Remove flagging" link, for Views, for
clearing a [specific flagging][3].

Usage
-----

After enabling this module you'll find two new pseudo fields in your
Views admin interface:

  Flag: Remove link

This removes a single flagging (The "relationship" record).

  Flag: Reset link

This removes all the flaggings for this content id. This field sits on
the "Flag counter" relationship so you'll have to bring in this counter
relationship first.

(And see the note above, about Custom Links, for displaying a reset link
under each node.)

[1]: http://drupal.org/project/flag
[2]: http://drupal.org/project/custom_links
[3]: http://drupal.org/node/889874

