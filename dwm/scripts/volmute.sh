#!/bin/bash

pactl set-sink-mute @DEFAULT_SINK@ toggle
kill -44 $(pidof dwmblocks)
