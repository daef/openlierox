/////////////////////////////////////////
//
//             OpenLieroX
//
// code under LGPL, based on JasonBs work,
// enhanced by Dark Charlie and Albert Zeyer
//
//
/////////////////////////////////////////


// Graphics header file
// Created 30/6/02
// Jason Boettcher


#include "LieroX.h"
#include "GfxPrimitives.h"
#include "Graphics.h"
#include "Cursor.h"
#include "ConfigHandler.h"


gfxgui_t	gfxGUI;
gfxgame_t	gfxGame;

///////////////////
// Load the graphics
int LoadGraphics(void)
{
	// Initialize the colours
	tLX->clChatText = MakeColour(128,255,128);
	tLX->clSubHeading = MakeColour(143,176,207);
	tLX->clHeading = MakeColour(0,138,251);
	tLX->clNetworkText = MakeColour(200,200,200);
	tLX->clNormalLabel = tLX->clWhite;
	tLX->clNotice = MakeColour(200,200,200);
	tLX->clNormalText = tLX->clWhite;
	tLX->clDropDownText = tLX->clWhite;
	tLX->clDisabled = MakeColour(96,96,96);
	tLX->clListView = tLX->clWhite;
	tLX->clTextBox = tLX->clWhite;
	tLX->clMouseOver = tLX->clWhite;
	tLX->clError = MakeColour(200,50,50);
	tLX->clCredits1 = MakeColour(150,150,150);
	tLX->clCredits2 = MakeColour(96,96,96);
	tLX->clPopupMenu = tLX->clWhite;
	tLX->clWaiting = tLX->clWhite;
	tLX->clReady = MakeColour(0,255,0);
	tLX->clPlayerName = MakeColour(255,255,255);
	tLX->clBoxDark = MakeColour(60,60,60);
	tLX->clBoxLight = MakeColour(130,130,130);
	tLX->clWinBtnBody = MakeColour(128,128,128);
	tLX->clWinBtnDark = MakeColour(64,64,64);
	tLX->clWinBtnLight = MakeColour(192,192,192);
	tLX->clMPlayerSong = tLX->clBlack;
	tLX->clMPlayerTime = tLX->clBlack;
	tLX->clDialogBackground = tLX->clBlack;
	tLX->clGameBackground = tLX->clBlack;
	tLX->clViewportSplit = tLX->clBlack;
	tLX->clScrollbarBack = MakeColour(0,66,100);
	tLX->clScrollbarFront = MakeColour(0,100,180);
	tLX->clScrollbarHighlight = MakeColour(25,155,255);
	tLX->clScrollbarBackLight = MakeColour(0,75,113);
	tLX->clScrollbarShadow = MakeColour(0,40,65);
	tLX->clSliderDark = MakeColour(90,90,90);
	tLX->clSliderLight = MakeColour(115,115,115);
	tLX->clChatBoxBackground = tLX->clBlack;
	tLX->clScoreBackground = tLX->clBlack;
	tLX->clCurrentSettingsBg = tLX->clBlack;
	tLX->clDialogCaption = MakeColour(0,0,64);
	tLX->clPlayerDividingLine = MakeColour(64,64,64);
	tLX->clLine = tLX->clWhite;
	tLX->clProgress = MakeColour(0,136,250);
	tLX->clListviewSelected = MakeColour(0,66,102);
	tLX->clMenuBackground = tLX->clBlack;
	tLX->clMenuSelected = MakeColour(0,66,102);
	tLX->clGameChatter = tLX->clWhite;
	tLX->clSelection = MakeColour(0, 100, 150);
	tLX->clTextboxCursor = MakeColour(50, 150, 200);
	tLX->clGameChatCursor = tLX->clWhite;
	tLX->clConsoleCursor = tLX->clWhite;
	tLX->clConsoleNormal = tLX->clWhite;
	tLX->clConsoleNotify = MakeColour(200,200,200);
	tLX->clConsoleError = MakeColour(255,0,0);
	tLX->clConsoleWarning = MakeColour(200,128,128);
	tLX->clConsoleDev = MakeColour(100,100,255);
	tLX->clConsoleChat = MakeColour(100,255,100);
	tLX->clReturningToLobby = MakeColour(200,200,200);
	tLX->clTeamColors[0] = MakeColour(2, 184, 252);  // Blue
	tLX->clTeamColors[1] = MakeColour(255, 2, 2); // Red
	tLX->clTeamColors[2] = MakeColour(32, 253, 0); // Green
	tLX->clTeamColors[3] = MakeColour(253, 244, 0); // Yellow
	tLX->clHealthLabel = MakeColour(0, 222, 0);
	tLX->clWeaponLabel = MakeColour(0, 0, 222);
	tLX->clLivesLabel = MakeColour(0, 222, 0);
	tLX->clKillsLabel = MakeColour(222, 0, 0);
	tLX->clFPSLabel = tLX->clWhite;
	tLX->clPingLabel = tLX->clWhite;
	tLX->clSpecMsgLabel = tLX->clWhite;


	LOAD_IMAGE(gfxGUI.bmpScrollbar,"data/frontend/scrollbar.png");
	LOAD_IMAGE(gfxGUI.bmpSliderBut,"data/frontend/sliderbut.png");

	LOAD_IMAGE(gfxGame.bmpCrosshair,"data/gfx/crosshair.bmp");
	LOAD_IMAGE(gfxGame.bmpMuzzle,"data/gfx/muzzle.bmp");
	LOAD_IMAGE(gfxGame.bmpExplosion,"data/gfx/explosion.png");
	LOAD_IMAGE(gfxGame.bmpSmoke,"data/gfx/smoke.png");
	LOAD_IMAGE(gfxGame.bmpChemSmoke,"data/gfx/chemsmoke.png");
	LOAD_IMAGE(gfxGame.bmpSpawn,"data/gfx/spawn.png");
	LOAD_IMAGE(gfxGame.bmpHook,"data/gfx/hook.bmp");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpGameover,"data/gfx/gameover.png");
	LOAD_IMAGE(gfxGame.bmpInGame,"data/gfx/ingame.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpScoreboard,"data/gfx/scoreboard.png");
    LOAD_IMAGE(gfxGame.bmpViewportMgr,"data/gfx/viewportmgr.png");
	LOAD_IMAGE(gfxGame.bmpSparkle, "data/gfx/sparkle.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpInfinite,"data/gfx/infinite.png");
	LOAD_IMAGE(gfxGame.bmpLag, "data/gfx/lag.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpTeamColours[0], "data/frontend/team_1.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpTeamColours[1], "data/frontend/team_2.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpTeamColours[2], "data/frontend/team_3.png");
	LOAD_IMAGE_WITHALPHA(gfxGame.bmpTeamColours[3], "data/frontend/team_4.png");

	LOAD_IMAGE(gfxGame.bmpBonus, "data/gfx/bonus.png");
	LOAD_IMAGE(gfxGame.bmpHealth, "data/gfx/health.png");

	// These files don't have to be present (backward compatibility)
	gfxGame.bmpGameNetBackground = LoadImage("data/frontend/background_netgame.png",false);
	gfxGame.bmpGameLocalBackground = LoadImage("data/frontend/background_localgame.png",false);
	gfxGame.bmpGameTopBar = LoadImage("data/frontend/top_bar.png",false);

	// Cursors
	if (!InitializeCursors())
		return false;

	tLX->cOutlineFont.SetOutline(true);
	tLX->cOutlineFont.SetSpacing(0);
	tLX->cOutlineFontGrey.SetSpacing(0);

	if(!tLX->cFont.Load("data/gfx/font.png",true))
		return false;
	if(!tLX->cOutlineFont.Load("data/gfx/out_font.png",true))
		return false;
	if(!tLX->cOutlineFontGrey.Load("data/gfx/out_fontgrey.png",false))
		return false;

	// Set the colour keys
	SetColorKey(gfxGame.bmpCrosshair);
	SetColorKey(gfxGame.bmpMuzzle);
	SetColorKey(gfxGame.bmpExplosion);
	SetColorKey(gfxGame.bmpSmoke);
	SetColorKey(gfxGame.bmpChemSmoke);
	SetColorKey(gfxGame.bmpSpawn);
	SetColorKey(gfxGame.bmpHook);
	SetColorKey(gfxGame.bmpBonus);
	SetColorKey(gfxGame.bmpHealth);
	SetColorKey(gfxGame.bmpSparkle);
    SetColorKey(gfxGame.bmpViewportMgr);

	// Load the colours from a file
	const std::string colorfile = "data/frontend/colours.cfg";
	ReadColour(colorfile,"Colours","ChatText",		 &tLX->clChatText,		tLX->clChatText);
	ReadColour(colorfile,"Colours","Credits1",		 &tLX->clCredits1,		tLX->clCredits1);
	ReadColour(colorfile,"Colours","Credits2",		 &tLX->clCredits2,		tLX->clCredits2);
	ReadColour(colorfile,"Colours","Disabled",		 &tLX->clDisabled,		tLX->clDisabled);
	ReadColour(colorfile,"Colours","DropDownText",	 &tLX->clDropDownText,	tLX->clDropDownText);
	ReadColour(colorfile,"Colours","Error",			 &tLX->clError,			tLX->clError);
	ReadColour(colorfile,"Colours","Heading",		 &tLX->clHeading,		tLX->clHeading);
	ReadColour(colorfile,"Colours","ListView",		 &tLX->clListView,		tLX->clListView);
	ReadColour(colorfile,"Colours","MouseOver",		 &tLX->clMouseOver,		tLX->clMouseOver);
	ReadColour(colorfile,"Colours","NetworkText",	 &tLX->clNetworkText,	tLX->clNetworkText);
	ReadColour(colorfile,"Colours","NormalLabel",	 &tLX->clNormalLabel,	tLX->clNormalLabel);
	ReadColour(colorfile,"Colours","NormalText",	 &tLX->clNormalText,	tLX->clNormalText);
	ReadColour(colorfile,"Colours","Notice",		 &tLX->clNotice,		tLX->clNotice);
	ReadColour(colorfile,"Colours","PopupMenu",		 &tLX->clPopupMenu,		tLX->clPopupMenu);
	ReadColour(colorfile,"Colours","SubHeading",	 &tLX->clSubHeading,	tLX->clSubHeading);
	ReadColour(colorfile,"Colours","TextBox",		 &tLX->clTextBox,		tLX->clTextBox);
	ReadColour(colorfile,"Colours","Waiting",		 &tLX->clWaiting,		tLX->clWaiting);
	ReadColour(colorfile,"Colours","Ready",			 &tLX->clReady,			tLX->clReady);
	ReadColour(colorfile,"Colours","PlayerName",	 &tLX->clPlayerName,	tLX->clPlayerName);
	ReadColour(colorfile,"Colours","BoxDark",		 &tLX->clBoxDark,		tLX->clBoxDark);
	ReadColour(colorfile,"Colours","BoxLight",		 &tLX->clBoxLight,		tLX->clBoxLight);
	ReadColour(colorfile,"Colours","WinButtonBody",	 &tLX->clWinBtnBody,	tLX->clWinBtnBody);
	ReadColour(colorfile,"Colours","WinButtonDark",  &tLX->clWinBtnDark,	tLX->clWinBtnDark);
	ReadColour(colorfile,"Colours","WinButtonLight", &tLX->clWinBtnLight,	tLX->clWinBtnLight);
	ReadColour(colorfile,"Colours","MPlayerSongTime",&tLX->clMPlayerTime,	tLX->clMPlayerTime);
	ReadColour(colorfile,"Colours","MPlayerSongName",&tLX->clMPlayerSong,	tLX->clMPlayerSong);
	ReadColour(colorfile,"Colours","DialogBackground",	&tLX->clDialogBackground,	tLX->clDialogBackground);
	ReadColour(colorfile,"Colours","GameBackground",	&tLX->clGameBackground,		tLX->clGameBackground);
	ReadColour(colorfile,"Colours","ViewportSplit",		&tLX->clViewportSplit,		tLX->clViewportSplit);
	ReadColour(colorfile,"Colours","ScrollbarBack",		&tLX->clScrollbarBack,		tLX->clScrollbarBack);
	ReadColour(colorfile,"Colours","ScrollbarBackLight",&tLX->clScrollbarBackLight,	tLX->clScrollbarBackLight);
	ReadColour(colorfile,"Colours","ScrollbarFront",	&tLX->clScrollbarFront,		tLX->clScrollbarFront);
	ReadColour(colorfile,"Colours","ScrollbarHighlight",&tLX->clScrollbarHighlight,	tLX->clScrollbarHighlight);
	ReadColour(colorfile,"Colours","ScrollbarShadow",	&tLX->clScrollbarShadow,	tLX->clScrollbarShadow);
	ReadColour(colorfile,"Colours","ChatBoxBackground", &tLX->clChatBoxBackground,	tLX->clChatBoxBackground);
	ReadColour(colorfile,"Colours","ScoreBack",			&tLX->clScoreBackground,	tLX->clScoreBackground);
	ReadColour(colorfile,"Colours","CurrentSettBack",	&tLX->clCurrentSettingsBg,	tLX->clCurrentSettingsBg);
	ReadColour(colorfile,"Colours","DialogCaption",		&tLX->clDialogCaption,		tLX->clDialogCaption);
	ReadColour(colorfile,"Colours","SliderLight",		&tLX->clSliderLight,		tLX->clSliderLight);
	ReadColour(colorfile,"Colours","SliderDark",		&tLX->clSliderDark,			tLX->clSliderDark);
	ReadColour(colorfile,"Colours","PlayerDividingLine",&tLX->clPlayerDividingLine,	tLX->clPlayerDividingLine);
	ReadColour(colorfile,"Colours","Line",				&tLX->clLine,				tLX->clLine);
	ReadColour(colorfile,"Colours","Progress",			&tLX->clProgress,			tLX->clProgress);
	ReadColour(colorfile,"Colours","ListviewSelected",	&tLX->clListviewSelected,	tLX->clListviewSelected);
	ReadColour(colorfile,"Colours","MenuBackground",	&tLX->clMenuBackground,		tLX->clMenuBackground);
	ReadColour(colorfile,"Colours","MenuSelected",		&tLX->clMenuSelected,		tLX->clMenuSelected);
	ReadColour(colorfile,"Colours","GameChatter",		&tLX->clGameChatter,		tLX->clGameChatter);
	ReadColour(colorfile,"Colours","Selection",			&tLX->clSelection,			tLX->clSelection);
	ReadColour(colorfile,"Colours","TextboxCursor",		&tLX->clTextboxCursor,		tLX->clTextboxCursor);
	ReadColour(colorfile,"Colours","GameChatCursor",	&tLX->clGameChatCursor,		tLX->clGameChatCursor);
	ReadColour(colorfile,"Colours","ConsoleCursor",		&tLX->clConsoleCursor,		tLX->clConsoleCursor);
	ReadColour(colorfile,"Colours","ConsoleNormal",		&tLX->clConsoleNormal,		tLX->clConsoleNormal);
	ReadColour(colorfile,"Colours","ConsoleNotify",		&tLX->clConsoleNotify,		tLX->clConsoleNotify);
	ReadColour(colorfile,"Colours","ConsoleError",		&tLX->clConsoleError,		tLX->clConsoleError);
	ReadColour(colorfile,"Colours","ConsoleWarning",	&tLX->clConsoleWarning,		tLX->clConsoleWarning);
	ReadColour(colorfile,"Colours","ConsoleDev",		&tLX->clConsoleDev,			tLX->clConsoleDev);
	ReadColour(colorfile,"Colours","ConsoleChat",		&tLX->clConsoleChat,		tLX->clConsoleChat);
	ReadColour(colorfile,"Colours","ReturningToLobby",	&tLX->clReturningToLobby,	tLX->clReturningToLobby);
	ReadColour(colorfile,"Colours","Team1",				&tLX->clTeamColors[0],		tLX->clTeamColors[0]);
	ReadColour(colorfile,"Colours","Team2",				&tLX->clTeamColors[1],		tLX->clTeamColors[1]);
	ReadColour(colorfile,"Colours","Team3",				&tLX->clTeamColors[2],		tLX->clTeamColors[2]);
	ReadColour(colorfile,"Colours","Team4",				&tLX->clTeamColors[3],		tLX->clTeamColors[3]);
	ReadColour(colorfile,"Colours","HealthLabel",		&tLX->clHealthLabel,		tLX->clHealthLabel);
	ReadColour(colorfile,"Colours","WeaponLabel",		&tLX->clWeaponLabel,		tLX->clWeaponLabel);
	ReadColour(colorfile,"Colours","LivesLabel",		&tLX->clLivesLabel,			tLX->clLivesLabel);
	ReadColour(colorfile,"Colours","KillsLabel",		&tLX->clKillsLabel,			tLX->clKillsLabel);
	ReadColour(colorfile,"Colours","FPSLabel",			&tLX->clFPSLabel,			tLX->clFPSLabel);
	ReadColour(colorfile,"Colours","PingLabel",			&tLX->clPingLabel,			tLX->clPingLabel);
	ReadColour(colorfile,"Colours","SpecialMsgLabel",	&tLX->clSpecMsgLabel,		tLX->clSpecMsgLabel);


	return true;
}


///////////////////
// Shutdown the graphics
void ShutdownGraphics(void)
{
	ShutdownCursors();
	tLX->cFont.Shutdown();
	tLX->cOutlineFont.Shutdown();
	tLX->cOutlineFontGrey.Shutdown();
}
