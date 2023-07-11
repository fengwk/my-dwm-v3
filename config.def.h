/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 5;        /* border pixel of windows */
static unsigned int gappx = 10;                 /* gap pixel between windows */
static unsigned int smartgap = 1;               /* 是否在单个客户端的平铺布局时移除gap */
static const unsigned int snap = 32;            /* snap pixel */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const int windowfollow       = 1;        /* 是否使窗口跟随client移动 */
static const char *fonts[]          = { "SauceCodePro Nerd Font:pixelsize=32" };
static const char dmenufont[]       = "SauceCodePro Nerd Font:pixelsize=32";
// 淡灰配色
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#444444";
static const char col_sboard[]      = "#bbbbbb";
static const char *colors[][3]      = {
  /*                 fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2  },
	[SchemeSel]  = { col_gray4, col_cyan,  col_sboard },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan   },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const char ptagf[] = "%s %s"; /* format of a tag label */
static const char etagf[] = "%s"; /* format of an empty tag */
static const char *taglabels[][2] = {
  { "st-256color", "" },
  { "Alacritty", "" },
  { "Google-chrome", "󰊯" },
  { "Google-chrome-unstable", "󰊯" },
  { "Microsoft-edge-dev", "󰇩" },
  { "Microsoft-edge", "󰇩" },
  { "jetbrains-idea", "" },
  { "jetbrains-idea-ce", "" },
  { "code-oss", "" },
  { "com-xk72-charles-gui-MainWithClassLoader", "" },
  { "popo", "﫢" },
  { "wechat.exe", "" },
  { "Postman", "" },
  { "XMind", "" },
  { "Xmind", "" },
  { "Java", "" },
  { "Eclipse", "" },
  { "xiaoyi_assistant", "嬨" },
  { "vlc", "嗢" },
  { "baidunetdisk", "" },
  { "Baidunetdisk", "" },
  { "Dragon-drop", "" },
  { "et", "" },
  { "wps", "" },
  { "wpp", "" },
  { "obs", "辶" },
  { "Shotcut", "難" },
  { "Optimus Manager Qt", "" },
  { "Nm-connection-editor", "" },
  { "Xfce4-power-manager-settings", "" },
  { "freedesktop", "" },
  { "Lxappearance", "" },
  { "qt5ct", "" },
  { "fcitx5-config-qt", "" },
  { "pavucontrol-qt", "" },
  { "Pavucontrol", "" },
  { "Tlp-UI", "" },
  { "flameshot", "" },
  { "Peek", "" },
  { "Parcellite", "" },
  { "thunderbird", "" },
  { "Typora", "" },
  { "Timeshift-gtk", "" },
  { "pdf", "" },
  { "netease-cloud-music", "" },
  { "QQ", "" },
  { "VirtualBox Manager", "練" },
  { "VirtualBox Machine", "練" },
  { "VirtualBox", "練" },
  { "Tor Browser", "" },
  { "Clash for Windows", "" },
  { "draw.io", "" },
  { "feh", "" },
};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                 instance    title         tags mask    isfloating     monitor    hideborder */
 	{ "Peek",                NULL,       NULL,         0,           1,             -1,        0},
 	{ "popo",                NULL,       NULL,         0,           1,             -1,        1},
 	{ "wechat.exe",          NULL,       NULL,         0,           1,             -1,        0},
 	{ "QQ",                  NULL,       NULL,         0,           1,             -1,        0},
 	{ "feh",                 NULL,       NULL,         0,           1,             -1,        0},
 	{ "XMind",               NULL,       NULL,         0,           0,             -1,        0},
 	{ "xiaoyi_assistant",    NULL,       NULL,         1<<8,        0,             -1,        0},
 	{ "jetbrains-idea",      NULL,       NULL,         0,           0,             -1,        0},
 	{ "jetbrains-idea-ce",   NULL,       NULL,         0,           0,             -1,        0},
 	{ "netease-cloud-music", NULL,       NULL,         0,           1,             -1,        0},
 	{ "Alacritty",           NULL,       "#todolist",  0,           1,             -1,        0},
 	{ "com-xk72-charles-gui-MainWithClassLoader", NULL, "Find in Session 1", 0, 1, -1,        0},
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
// static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "dwm-termcmd", NULL };

/* rofi commands */
static const char *rofi_run[] = { "rofi-wrapper.sh", "-show", "combi", "-combi-modes", "window,drun,run", "-modes", "combi", NULL };
static const char *rofi_browser[] = { "rofi-broswer", NULL };
static const char *rofi_clipster[] = { "rofi-clipster", NULL };

/* monitor */
static const char *switchmonitor1[] = { "dwm-switchmonitor", "1", NULL };
static const char *switchmonitor2[] = { "dwm-switchmonitor", "2", NULL };

/* flameshot */
static const char *flameshotcmd[] = { "dwm-flameshot", "gui", NULL };
static const char *flameshotocrcmd[] = { "dwm-flameshotocr", NULL };

/*
 * xev命令可以获取keycode
 * xmodmap命令可以查看所有modkey
 *
 * Mod1Mask 是alt键
 * Mod4Mask 是win键
 */
static const Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = rofi_run } },
	{ MODKEY,                       XK_s,      spawn,          {.v = rofi_browser } },
	{ MODKEY,                       XK_v,      spawn,          {.v = rofi_clipster } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ Mod4Mask,                     XK_h,      togglehide,     {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

    /* monitor */
    { Mod4Mask,                     XK_1,      spawn,          {.v = switchmonitor1 } }, // 屏幕检测，单监视器
    { Mod4Mask,                     XK_2,      spawn,          {.v = switchmonitor2 } }, // 屏幕检测，双监视器

	/* flameshot */
	{ MODKEY|ShiftMask,             XK_a,      spawn,           {.v = flameshotocrcmd } }, // 截图ocr
	{ MODKEY,                       XK_a,      spawn,           {.v = flameshotcmd } },    // 截图
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum              function */
	{ "setmfact",          setmfact },
	{ "incnmaster",        incnmaster },
	{ "quit",              quit },
	{ "switchenternotify", switchenternotify },
	{ "setgappx",          setgappx },
	{ "togglesmartgap",    togglesmartgap },
	{ "showall",           showall },
};
