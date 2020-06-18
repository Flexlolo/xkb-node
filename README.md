README
======

Description
-----------

Small program for bspwm to keep track of keyboard layouts for different windows on bspwm.
It reads events from bspc through pipe and keeps track of window layout once you switch to it.

Compilation and installation
----------------------------

	make
	make install

Usage
-----

	bspc subscribe node_focus node_remove | xkb-node

Credits
-------

All credits for XKeyboard.h goes to https://github.com/nonpop/xkblayout-state

I just used this guy's codebase to switch layouts.