#!/bin/bash

# compositor
picom &

# wallpapaer
nitrogen --restore &

# notifications
dunst &

# keybindings
xbindkeys &

# status bar
$HOME/.dwm/dwmblocks/dwmblocks
