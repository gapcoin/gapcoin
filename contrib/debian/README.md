
Debian
====================
This directory contains files used to package gapcoind/gapcoin-qt
for Debian-based Linux systems. If you compile gapcoind/gapcoin-qt yourself, there are some useful files here.

## gapcoin: URI support ##


gapcoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install gapcoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your gapcoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/gapcoin128.png` to `/usr/share/pixmaps`

gapcoin-qt.protocol (KDE)

