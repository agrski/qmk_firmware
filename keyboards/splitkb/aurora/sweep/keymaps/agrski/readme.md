# Aurora Sweep's Default Keymap

A chord-based keymap for effective typing
===

While the default keymap makes heavy use of held keys as layer switches, this keymap instead prioritises chords.
It uses set keys to navigate up and down layers and emphasises the thumb keys as modifiers.
The idea is to avoid having to hold keys for extended periods or have too many layers to remember.

It makes the _super_ modifier always available for use with i3wm or equivalent window managers.

Layer map
---

The thumb buttons are similar in all layers for consistent access to modifiers.
This keymap is not designed around one-handed use.

### Base layer: typing

This base layer is intended for a convenient typing experience which provides alphabetic characters and whitespace in an accessible manner.

### Numeric layer

Numbers are accessed via the left ring finger.
It is common to need access to numbers, whether for general typing, calculations, window manager commands, or suchlike.

### Symbol layer

Symbols are accessed via the right ring finger.
These are intended for use in general typing, Vim, and shell scripting.

### Navigation

QMK supports mouse emulation.
This layer makes use of that and other navigation tools, such as arrow keys.

### Function keys

The assumption is that function keys, whilst useful, are used infrequently and thus can be relegated to a less accessible layer.
This layer also controls the RGB LEDs, if available.

### KiTTY terminal

Kitty commands are often invoked with Control + Shift.
This is slightly awkward, so there is a special layer for them.
