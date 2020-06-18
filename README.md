README
======

Description
-----------

Small program for bspwm to keep track of keyboard layouts for different windows on bspwm.
It reads events from bspc through pipe and keeps track of window layout once you switch to it.

Dependencies
------------

-docopt.cpp (https://github.com/docopt/docopt.cpp)

Compilation and installation
----------------------------

	make
	make install

Usage
-----

	bspc subscribe node_focus node_remove | xkb-node

### Options

- `-d, --default`		Set default layout to all new windows

Credits
-------

All credits for XKeyboard.h goes to https://github.com/nonpop/xkblayout-state

I just used this guy's codebase to switch layouts.
