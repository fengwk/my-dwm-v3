/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel of windows */
static unsigned int gappx = 25;                 /* gap pixel between windows */
static unsigned int fgappx = 0;                 /* gap pixel between windows */
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
// static const char col_gray1[]       = "#222222"; // normbgcolor hidselbgcolor
// static const char col_gray2[]       = "#444444"; // normbordercolor
// static const char col_gray3[]       = "#bbbbbb"; // normfgcolor
// static const char col_gray4[]       = "#eeeeee"; // selfgcolor
// static const char col_cyan[]        = "#444444"; // selbgcolor hidselfgcolor hidbordercolor
// static const char col_sboard[]      = "#bbbbbb"; // selbgcolor
// 复古黑灰
// static const char col_gray1[]       = "#1F1F1F"; // normbgcolor hidselbgcolor
// static const char col_gray2[]       = "#363635"; // normbordercolor
// static const char col_gray3[]       = "#E1E3E5"; // normfgcolor
// static const char col_gray4[]       = "#E1E3E5"; // selfgcolor
// static const char col_cyan[]        = "#444444"; // selbgcolor hidselfgcolor hidbordercolor
// static const char col_sboard[]      = "#bbbbbb"; // selbgcolor
// catppuccin
// static const char col_gray1[]       = "#1E1E2E"; // 与背景色不同，下面的col_gray1与背景色一致可以营造无边框的感觉
static const char col_gray1[]       = "#24273A"; // normbgcolor hidselbgcolor
static const char col_gray2[]       = "#414559"; // normbordercolor
static const char col_gray3[]       = "#CAD3F5"; // normfgcolor
static const char col_gray4[]       = "#CAD3F5"; // selfgcolor
static const char col_cyan[]        = "#414559"; // selbgcolor hidselfgcolor hidbordercolor
static const char col_sboard[]      = "#F5BDE6"; // selbordercolor
// gruvbox-flat
// // static const char col_gray1[]       = "#1d2021"; // normbgcolor hidselbgcolor
// static const char col_gray1[]       = "#282828"; // normbgcolor hidselbgcolor
// static const char col_gray2[]       = "#3c3836"; // normbordercolor
// static const char col_gray3[]       = "#d4be98"; // normfgcolor
// static const char col_gray4[]       = "#d4be98"; // selfgcolor
// static const char col_cyan[]        = "#3c3836"; // selbgcolor hidselfgcolor hidbordercolor
// static const char col_sboard[]      = "#d3869b"; // selbordercolor
static const char *colors[][3]      = {
  /*                 fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2  },
	[SchemeSel]  = { col_gray4, col_cyan,  col_sboard },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan   },
};

static const int movewinthresholdv  = 12; /* 垂直：这个阈值越大movewin操作改变的范围越小 */
static const int movewinthresholdh  = 16; /* 水平：这个阈值越大movewin操作改变的范围越小 */
static const int resizewinthresholdv= 20; /* 垂直：这个阈值越大resizewin操作改变的范围越小 */
static const int resizewinthresholdh= 40; /* 水平：这个阈值越大resizewin操作改变的范围越小 */

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

// overview tag
static const char *overviewtag = "OVERVIEW";

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
  { "jetbrains-studio", "" },
  { "Genymotion", "󰀲" },
  { "Genymotion Player", "󰀲" },
  { "anbox", "󰀲" },
  { "code-oss", "" },
  { "com-xk72-charles-gui-MainWithClassLoader", "" },
  { "popo", "﫢" },
  { "wechat.exe", "" },
  { "Postman", "󰰚" },
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
  { "yesplaymusic", "" },
  { "QQ", "" },
  { "VirtualBox Manager", "練" },
  { "VirtualBox Machine", "練" },
  { "VirtualBox", "練" },
  { "Tor Browser", "" },
  { "Clash for Windows", "" },
  { "draw.io", "" },
  { "Drawio", "" },
  { "feh", "" },
  { "Gimp*", "󰽉" },
  { "Plasticity", "" },
  { "com.xunlei.download", "" },
  { "FreeCAD", "󰻬" },
  { "Creality Print", "" },
};

/* scratchpads */
#define SP0 "#sp0"
#define SP1 "#sp1"
#define SP2 "#sp2"
#define SP3 "#sp3"
const char *spcmd0[] = { "dwm-sp0", SP0, NULL };
const char *spcmd1[] = { "dwm-sp1", SP1, NULL };
const char *spcmd2[] = { "dwm-sp2", SP2, NULL };
const char *spcmd3[] = { "dwm-sp3", SP3, NULL };
static Sp scratchpads[] = {
	/* name    cmd  */
	  {SP0,    spcmd0},
	  {SP1,    spcmd1},
	  {SP2,    spcmd2},
	  {SP3,    spcmd3},
};

/* rules */
#define RULE_FXY_NO -1
#define RULE_FXY_CENTER -2
#define RULE_FXY_POSOFFSET 0
#define RULE_FXY_NEGOFFSET 1000000
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                 instance     title         tags mask    isfloating     monitor    hideborder    fx               fy */
	{ NULL,                  SP0,         NULL,         SPTAG(0),    1,             -1,        0,            RULE_FXY_CENTER, RULE_FXY_CENTER },
	{ NULL,                  SP1,         NULL,         SPTAG(1),    1,             -1,        0,            RULE_FXY_CENTER, RULE_FXY_CENTER },
	{ NULL,                  SP2,         NULL,         SPTAG(2),    1,             -1,        0,            RULE_FXY_CENTER, RULE_FXY_CENTER },
	{ NULL,                  SP3,         NULL,         SPTAG(3),    1,             -1,        0,            RULE_FXY_CENTER, RULE_FXY_CENTER },
 	{ "Peek",                NULL,        NULL,         0,           1,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "popo",                NULL,        NULL,         0,           1,             -1,        1,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "wechat.exe",          NULL,        NULL,         0,           1,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "QQ",                  NULL,        NULL,         0,           1,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "feh",                 NULL,        NULL,         0,           1,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "XMind",               NULL,        NULL,         0,           0,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "xiaoyi_assistant",    NULL,        NULL,         1<<8,        0,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ NULL,                  "MusicVPN",  NULL,         1<<8,        0,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "jetbrains-idea",      NULL,        NULL,         0,           0,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "jetbrains-idea-ce",   NULL,        NULL,         0,           0,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "netease-cloud-music", NULL,        NULL,         0,           1,             -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "Xfce4-power-manager-settings", NULL, NULL,       0,           1,             -1,        0,            RULE_FXY_CENTER, RULE_FXY_CENTER },
 	{ "Google-chrome", "crx_ikhdkkncnoglghljlkmcimlnlhkeamad", NULL, 0, 1,          -1,        0,       RULE_FXY_NO,     RULE_FXY_NO     },
 	{ "com-xk72-charles-gui-MainWithClassLoader", NULL, "Find in Session 1", 0, 1,  -1,        0,            RULE_FXY_NO,     RULE_FXY_NO     },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function    append */
	{ "[]=",      tile,               0 },    /* first entry is default */
	{ "[M]",      monocle,            0 },
	{ "###",      grid,               1 },    /* 网格布局 */
	{ "><>",      NULL,               0 },    /* no layout function means floating behavior */
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
static const char *rofi_run[] = { "dwm-rofirun", NULL };
static const char *rofi_browser[] = { "dwm-rofisearch", "search", NULL };
static const char *rofi_clipster[] = { "dwm-roficlipster", NULL };

/* monitor */
static const char *switchmonitor1[] = { "dwm-switchmonitor", "1", NULL };
static const char *switchmonitor2[] = { "dwm-switchmonitor", "2", NULL };

/* flameshot */
static const char *flameshotcmd[] = { "dwm-flameshot", "gui", NULL };
static const char *flameshotocrcmd[] = { "dwm-flameshotocr", NULL };

/* 鼠标控制 */
static const char *mouseclick1[] = { "xdotool", "click", "1", NULL }; // 鼠标左键点击
static const char *mouseclick2[] = { "xdotool", "click", "2", NULL }; // 鼠标中键点击
static const char *mouseclick3[] = { "xdotool", "click", "3", NULL }; // 鼠标右键点击

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
	{ Mod4Mask,                     XK_j,      focusstackhid,  {.i = +1 } },
	{ Mod4Mask,                     XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	// { MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} }, // 平铺布局
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[3]} }, // 浮动布局
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[1]} }, // monocle布局
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[2]} }, // grid布局
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	{ MODKEY|ShiftMask,             XK_j,      viewtoleft,     {0} }, // 切换到左侧tag
	{ MODKEY|ShiftMask,             XK_k,      viewtoright,    {0} }, // 切换到右侧tag

	{ MODKEY,                       XK_Tab,    switchprevclient,{.ui = SWITCH_DIFF_TAG} },    // 切换到上一个不同tag的聚焦窗口
	{ Mod4Mask,                     XK_Tab,    switchprevclient,{.ui = SWITCH_SAME_TAG} },    // 切换到上一个相同tag的聚焦窗口

	/* overview */
	{ Mod4Mask,                     XK_space,  toggleoverview, {0} }, // overview

	/* monitor */
	{ Mod4Mask,                     XK_1,      spawn,          {.v = switchmonitor1 } }, // 屏幕检测，单监视器
	{ Mod4Mask,                     XK_2,      spawn,          {.v = switchmonitor2 } }, // 屏幕检测，双监视器

	/* flameshot */
	{ MODKEY|ShiftMask,             XK_a,      spawn,           {.v = flameshotocrcmd } }, // 截图ocr
	{ MODKEY,                       XK_a,      spawn,           {.v = flameshotcmd } },    // 截图

	/* scratchpads */
	{ MODKEY,                       XK_grave,  togglescratch,   {.ui = 0 } },
	{ MODKEY,                       XK_q,      togglescratch,   {.ui = 1 } },
	{ MODKEY,                       XK_w,      togglescratch,   {.ui = 2 } },
	{ MODKEY,                       XK_e,      togglescratch,   {.ui = 3 } },

	/* 鼠标控制 */
	{ MODKEY|ControlMask,           XK_z,         spawn,           {.v = mouseclick1} },  // 鼠标左键点击
	{ MODKEY|ControlMask,           XK_x,         spawn,           {.v = mouseclick2} },  // 鼠标中键点击
	{ MODKEY|ControlMask,           XK_c,         spawn,           {.v = mouseclick3} },  // 鼠标右键点击
	{ MODKEY|ControlMask,           XK_f,         mousefocus,      {0} },                 // 鼠标聚焦到当前选中窗口
	{ MODKEY|ControlMask,           XK_k,         mousemove,       {.ui = MOUSE_UP} },    // 向上移动鼠标光标
	{ MODKEY|ControlMask,           XK_l,         mousemove,       {.ui = MOUSE_RIGHT} }, // 向右移动鼠标光标
	{ MODKEY|ControlMask,           XK_j,         mousemove,       {.ui = MOUSE_DOWM} },  // 向下移动鼠标光标
	{ MODKEY|ControlMask,           XK_h,         mousemove,       {.ui = MOUSE_LEFT} },  // 向左移动鼠标光标

	/* 窗口控制 */
	{ Mod4Mask,                     XK_c,         togglehide,      {0} },                  // 窗口隐藏开关
	{ Mod4Mask,                     XK_f,         togglefloatingacenter,  {0} },           // 窗口浮动开关
	{ Mod4Mask|ControlMask,         XK_Up,        movewin,         {.ui = WIN_UP} },       // 向上移动窗口
	{ Mod4Mask|ControlMask,         XK_Down,      movewin,         {.ui = WIN_DOWN} },     // 向下移动窗口
	{ Mod4Mask|ControlMask,         XK_Left,      movewin,         {.ui = WIN_LEFT} },     // 向左移动窗口
	{ Mod4Mask|ControlMask,         XK_Right,     movewin,         {.ui = WIN_RIGHT} },    // 向右移动窗口
	{ Mod4Mask|ControlMask,         XK_k,         movewin,         {.ui = WIN_UP} },       // 向上移动窗口
	{ Mod4Mask|ControlMask,         XK_j,         movewin,         {.ui = WIN_DOWN} },     // 向下移动窗口
	{ Mod4Mask|ControlMask,         XK_h,         movewin,         {.ui = WIN_LEFT} },     // 向左移动窗口
	{ Mod4Mask|ControlMask,         XK_l,         movewin,         {.ui = WIN_RIGHT} },    // 向右移动窗口
	{ Mod4Mask|ShiftMask,           XK_k,         resizewin,       {.ui = V_REDUCE} },     // 垂直减少窗口大小
	{ Mod4Mask|ShiftMask,           XK_j,         resizewin,       {.ui = V_EXPAND} },     // 垂直增加窗口大小
	{ Mod4Mask|ShiftMask,           XK_h,         resizewin,       {.ui = H_REDUCE} },     // 水平减少窗口大小
	{ Mod4Mask|ShiftMask,           XK_l,         resizewin,       {.ui = H_EXPAND} },     // 水平增加窗口大小
	{ Mod4Mask|ShiftMask,           XK_Up,        resizewin,       {.ui = V_REDUCE} },     // 垂直减少窗口大小
	{ Mod4Mask|ShiftMask,           XK_Down,      resizewin,       {.ui = V_EXPAND} },     // 垂直增加窗口大小
	{ Mod4Mask|ShiftMask,           XK_Left,      resizewin,       {.ui = H_REDUCE} },     // 水平减少窗口大小
	{ Mod4Mask|ShiftMask,           XK_Right,     resizewin,       {.ui = H_EXPAND} },     // 水平增加窗口大小

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask        button          function        argument */
	{ ClkTagOV,             0,                Button1,        toggleoverview, {0} },
	{ ClkTagBar,            0,                Button1,        view,           {0} },
	{ ClkTagBar,            0,                Button3,        toggleview,     {0} },
	{ ClkTagBar,            0,                Button4,        viewtoleft,     {0} },       // 在tag栏上鼠标上滚切换到上一个tag
	{ ClkTagBar,            0,                Button5,        viewtoright,    {0} },       // 在tag栏上鼠标上滚切换到下一个tag
	{ ClkTagBar,            MODKEY,           Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,           Button3,        toggletag,      {0} },
	{ ClkLtSymbol,          0,                Button1,        setlayout,      {0} },
	{ ClkWinTitle,          0,                Button1,        focuswin,       {0} },
	{ ClkWinTitle,          0,                Button2,        zoom,           {0} },
	{ ClkWinTitle,          0,                Button3,        titlemenu,      {0} },
	{ ClkWinTitle,          0,                Button4,        focusstackvis,  {.i = -1} }, // 在标题栏上鼠标上滚切换到上一个客户端
	{ ClkWinTitle,          0,                Button5,        focusstackvis,  {.i = +1} }, // 在标题栏上鼠标上滚切换到下一个客户端
	{ ClkStatusText,        0,                Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,           Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,           Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,           Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,        rootmenu,       {0} },
	{ ClkRootWin,           0,                Button3,        rootmenu,       {0} },
	{ ClkRootWin,           0,                Button4,        viewtoleft,     {0} },
	{ ClkRootWin,           0,                Button5,        viewtoright,    {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signame> [<type> <value>]"` */
static Signal signals[] = {
	/* signum              function */
	{ "setmfact",          setmfact },
	{ "quit",              quit },
	{ "setgappx",          setgappx },
	{ "togglesmartgap",    togglesmartgap },
	{ "showall",           showall },
	{ "setrofimode",       setrofimode },
	{ "viewtoleft",        viewtoleft },
	{ "viewtoright",       viewtoright },
	{ "setoverview",       setoverview },
	{ "togglefullscrwin",  togglefullscrwin },
	{ "killclientwin",     killclientwin },
	{ "togglehide",        togglehide },
	{ "focusstackvis",     focusstackvis },
	{ "switchtoclientwin", switchtoclientwin },
	{ "clearurgentwin",    clearurgentwin },
	{ "pullurgentwin",     pullurgentwin },
};
