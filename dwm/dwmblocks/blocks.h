//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/

  { "", "/home/wizard/Configurations/dwm/cpu.sh",        5 , 0  },
  { "", "/home/wizard/Configurations/dwm/battery.sh",    10, 0  },
  { "", "/home/wizard/Configurations/dwm/mem.sh",        5 , 0  },
  { "", "/home/wizard/Configurations/dwm/ssd.sh",        60, 0  },
  { "", "/home/wizard/Configurations/dwm/caps.sh",       0 , 11 }, // 45
  { "", "/home/wizard/Configurations/dwm/numlock.sh",    0 , 12 }, // 46
  { "", "/home/wizard/Configurations/dwm/brightness.sh", 0 , 13 }, // 47
  { "", "/home/wizard/Configurations/dwm/vol.sh",        0 , 10 }, // 44
  { "", "date +'%a, %b %d %I:%M'",                       5 , 0  },
};

//sets delimeter between status commands. NULL character ('\0') means no delimeter.
static char delim[] = " | ";
static unsigned int delimLen = 5;
