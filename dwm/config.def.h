/* See LICENSE file for copyright and license details. */

/* alt-tab configuration */
static const unsigned int tabModKey = 0x40;	  /* if this key is hold the alt-tab functionality stays acitve. This key must be the same as key that is used to active functin altTabStart `*/
static const unsigned int tabCycleKey = 0x17; /* if this key is hit the alt-tab program moves one position forward in clients stack. This key must be the same as key that is used to active functin altTabStart */
static const unsigned int tabPosY = 1;		  /* tab position on Y axis, 0 = bottom, 1 = center, 2 = top */
static const unsigned int tabPosX = 1;		  /* tab position on X axis, 0 = left, 1 = center, 2 = right */
static const unsigned int maxWTab = 600;	  /* tab menu width */
static const unsigned int maxHTab = 200;	  /* tab menu height */

/* appearance */
static const unsigned int borderpx = 2; /* border pixel of windows */
static const unsigned int snap = 32;	/* snap pixel */
static const unsigned int gappx = 12;
static const unsigned int systraypinning = 0; /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 1;  /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2; /* systray spacing */

static const int systraypinningfailfirst = 1; /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray = 1;			  /* 0 means no systray */
static const int showbar = 1;				  /* 0 means no bar */
static const int topbar = 1;				  /* 0 means bottom bar */
static const int horizpadbar        = 0;        /* horizontal padding for statusbar */
static const int vertpadbar         = 0;        /* vertical padding for statusbar */
static const char *barlayout = "tln|s";
static const char *fonts[] = { /* "FiraCode Nerd Font Mono:size=10", */ "JetBrainsMono NF:size=9", "monospace:size=10"};
static const char dmenufont[] = "monospace:size=10";

// ring
static const char col_gray1[]       = "#212121";
static const char col_gray2[]       = "#282a36";
static const char col_gray3[]       = "#96b5b4";
static const char col_gray4[]       = "#ffffff";
static const char col_cyan[]        = "#e46f22";

static const char *colors[][3] = {
	/*               fg         bg         border   */
	[SchemeNorm] = {col_gray3, col_gray1, col_gray2},
	[SchemeSel] = {col_gray4, col_cyan, col_cyan},
};

/* tagging */
static const char *tags[] = {"www", "sys", "dev", "msg", "msc", "doc", "bkg", "res", "misc"};
static const char *alttags[] = {"_www", "_sys", "_dev", "_msg", "_msc", "_doc", "_bkg", "_res", "_misc"};
// static const char *tags[] = {"󰈹", "", "", "󰙯", "", "", "", "", ""};
// static const char *alttags[] = {"󰈹", "", "", "󰙯", "", "", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{"Gimp", NULL, NULL, 0, 1, -1},
	{"Firefox", NULL, NULL, 1 << 8, 0, -1},
};

/* layout(s) */
static const float mfact = 0.5;		 /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;		 /* number of clients in master area */
static const int resizehints = 1;	 /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "layouts.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{"[]=", tile}, /* first entry is default */
	{"><>", NULL}, /* no layout function means floating behavior */
	{"[M]", monocle},
	{"HHH", grid},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                          \
	{MODKEY, KEY, view, {.ui = 1 << TAG}},                         \
		{MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}}, \
		{MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},          \
		{MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                     \
	{                                  \
		.v = (const char *[])          \
		{                              \
			"/bin/sh", "-c", cmd, NULL \
		}                              \
	}

/* commands */
static const char *dmenucmd[] = {"dmenu_run", "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL};
static const char *text_e[] = {"alacritty", "-e", "nvim", NULL};
static const char *logout[] = {"/home/wizard/Configurations/scripts/dm-logout.sh", NULL};
static const char *termcmd[] = {"alacritty", NULL};
static const char *scrot[] = {"/bin/sh", "-c", "scrot '/tmp/%Y-%m-%d_$wx$h.png' -a $(slop -f '%x,%y,%w,%h') -e 'xclip -selection clipboard -t image/png -i $f && rm $f'", NULL};
static const char *scrot_save[] = {"/bin/sh", "-c", "scrot '/home/wizard/Pictures/screenshot/%Y-%m-%d_$wx$h.png' -a $(slop -f '%x,%y,%w,%h') -e 'xclip -selection clipboard -t image/png -i $f'", NULL};
static const char *btopcmd[] = {"alacritty", "-e", "btop", NULL};
static const char *web[] = {"firedragon", NULL};
static const char *nm[] = {"/home/wizard/Apps/dwm-config/network_manager", NULL};

static const Key keys[] = {
	/* modifier                     key        function        argument */

	{MODKEY, XK_F12, spawn, {.v = text_e}},
	{MODKEY, XK_space, spawn, {.v = dmenucmd}},
	{MODKEY | ShiftMask, XK_s, spawn, {.v = scrot}},
	{MODKEY | ShiftMask | ControlMask, XK_s, spawn, {.v = scrot_save}},
	{MODKEY | ShiftMask, XK_n, spawn, {.v = nm}},
	{MODKEY, XK_Return, spawn, {.v = termcmd}},
	{MODKEY, XK_w, spawn, {.v = web}},
	{MODKEY, XK_b, togglebar, {0}},
	{MODKEY | ShiftMask, XK_j, rotatestack, {.i = +1}},
	{MODKEY | ShiftMask, XK_k, rotatestack, {.i = -1}},
	{MODKEY, XK_j, focusstack, {.i = +1}},
	{MODKEY, XK_k, focusstack, {.i = -1}},
	{MODKEY, XK_i, incnmaster, {.i = +1}},
	{MODKEY, XK_d, incnmaster, {.i = -1}},
	{MODKEY, XK_h, setmfact, {.f = -0.05}},
	{MODKEY, XK_l, setmfact, {.f = +0.05}},
	{MODKEY | ControlMask, XK_Return, zoom, {0}},
	{MODKEY, XK_q, view, {0}},
	{MODKEY | ShiftMask, XK_c, killclient, {0}},
	{MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
	{MODKEY, XK_f, setlayout, {.v = &layouts[1]}},
	{MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
	/* { MODKEY|ShiftMask,             XK_space,  setlayout,      {0} }, */
	{MODKEY | ShiftMask, XK_space, togglefloating, {0}},
	{MODKEY | ShiftMask, XK_f, togglefullscr, {0}},
	{MODKEY, XK_0, view, {.ui = ~0}},
	{MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},
	{MODKEY, XK_comma, focusmon, {.i = -1}},
	{MODKEY, XK_period, focusmon, {.i = +1}},
	{MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
	{MODKEY, XK_g, setlayout, {.v = &layouts[3]}},
	{MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},
	{MODKEY, XK_minus, setgaps, {.i = -1}},
	{MODKEY, XK_equal, setgaps, {.i = +1}},
	{MODKEY | ShiftMask, XK_equal, setgaps, {.i = 0}},
	TAGKEYS(XK_1, 0)
	TAGKEYS(XK_2, 1)
	TAGKEYS(XK_3, 2)
	TAGKEYS(XK_4, 3)
	TAGKEYS(XK_5, 4)
	TAGKEYS(XK_6, 5)
	TAGKEYS(XK_7, 6)
	TAGKEYS(XK_8, 7)
	TAGKEYS(XK_9, 8){MODKEY | ShiftMask, XK_q, spawn, {.v = logout}},
	{MODKEY | ControlMask | ShiftMask, XK_q, quit, {1}},
	{Mod1Mask, XK_Tab, altTabStart, {0}},
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ClkTagBar, MODKEY, Button1, tag, {0}},
	{ClkTagBar, MODKEY, Button3, toggletag, {0}},
	{ClkWinTitle, 0, Button2, zoom, {0}},
	{ClkStatusText, 0, Button1, spawn, {.v = btopcmd}},
	{ClkClientWin, MODKEY, Button1, movemouse, {0}},
	{ClkClientWin, MODKEY, Button2, togglefloating, {0}},
	{ClkClientWin, MODKEY, Button3, resizemouse, {0}},
	{ClkTagBar, 0, Button1, view, {0}},
	{ClkTagBar, 0, Button3, toggleview, {0}},
	{ClkTagBar, MODKEY, Button1, tag, {0}},
	{ClkTagBar, MODKEY, Button3, toggletag, {0}},
};
