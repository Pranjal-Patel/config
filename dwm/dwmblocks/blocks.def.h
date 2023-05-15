//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  { "", "$HOME/.dwm/scripts/cpu.sh",        5 , 0  },
  { "", "$HOME/.dwm/scripts/battery.sh",    10, 0  },
  { "", "$HOME/.dwm/scripts/mem.sh",        5 , 0  },
  { "", "$HOME/.dwm/scripts/ssd.sh",        60, 0  },
  { "", "$HOME/.dwm/scripts/caps.sh",       0 , 11 }, // 45
  { "", "$HOME/.dwm/scripts/numlock.sh",    0 , 12 }, // 46
  { "", "$HOME/.dwm/scripts/brightness.sh", 0 , 13 }, // 47
  { "", "$HOME/.dwm/scripts/vol.sh",        0 , 10 }, // 44
  { "", "date +'%a, %b %d %I:%M'",                       5 , 0  },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
