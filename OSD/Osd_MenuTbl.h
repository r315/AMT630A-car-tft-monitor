#ifndef _MENU_TBL_H__
#define _MENU_TBL_H__


#include "sysPower.h" 
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "Osd_MenuKeyInterface.h"
#include "Osd_LogoFontDat.h"
#include "Osd_LogoList.c"


///////////////////////////Power Off Page///////////////////////////////////
MenuItemType CODE  PowerOffMenu_ItemTab[]=
{
   {
   	  "PowerOffMenuItem_PowerOff" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   NULL,   // ItemValue
   	
   	   NULL,   // adjust 
   	   PowerOffSystem,   // exect    
   	   
   	   NULL,   // key comd map
       NULL, //KEY comd count
   	   osdSel,      // flags
   },
};

MenuPageType CODE PowerOffMenu =
{
		"Osd_PowerOffMenu",
		NULL,NULL, //xpos ypos
		NULL,NULL,  //xsize ysize
		NULL,NULL, //foreColor backColor
		NULL,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_PowerOffMenu,    //currentPage
		Osd_RootMenu,   //NextPage
		
		NULL,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		PowerOffMenu_ItemTab, //items
		sizeof(PowerOffMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdInvisible,//flags
};



///////////////////////////Power On Page///////////////////////////////////
MenuItemType CODE  PowerOnMenu_ItemTab[]=
{
   {
   	  "PowerOnMenuItem_PowerOn" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   PowerOnMenuItemVal_PowerOn,   // ItemValue
   	
   	   NULL,   // adjust 
   	   PowerOnSystem,   // exect    
   	   
   	   NULL,   // key comd map
       NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE PowerOnMenu =
{
		"Osd_PowerOnMenu",
		SOURCEMENU_START_X_POS,SOURCEMENU_START_Y_POS, //xpos ypos
		0x03,0x01,  //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock2,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_PowerOnMenu,    //currentPage
		Osd_RootMenu,   //NextPage
		
		PowerOnMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		PowerOnMenu_ItemTab, //items
		sizeof(PowerOnMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};



///////////////////////////Root Page///////////////////////////////////
MenuItemType CODE  RootMenu_ItemTab[]=
{
   {
   	  "RootMenuItem" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   NULL,   // ItemValue
	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   RootMenuItem_KeyComdMap,   // key comd map
   	   sizeof(RootMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE RootMenu =
{
		"Osd_RootMenu",
		NULL,NULL, //xpos ypos
		NULL,NULL,  //xsize ysize
		NULL,NULL, //foreColor backColor
		NULL,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_RootMenu,   //currentPage
		Osd_RootMenu,   //NextPage
		
		NULL,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		RootMenu_ItemTab, //items
		sizeof(RootMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdInvisible,//flags
};



///////////////////////////Logo Page///////////////////////////////////
#ifdef LogoEn
MenuItemType CODE  LogoMenu_ItemTabl[]=
{
   {
   	  "LogoMenuItem_Logo" ,
	   NULL,NULL,    //xpos ypos
   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   NULL,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};

MenuPageType CODE LOGO1Menu =
{
		"Osd_Logo1Menu",
		LOGO1MENU_START_X_POS,LOGO1MENU_START_Y_POS, //xpos ypos
		LogoWidth_LOGO1   ,LogoHeighth_LOGO1   , //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_LOGO1Menu, //currentPage
		Osd_RootMenu,   //NextPage
		
		LogoMenu_CheckCondition,//check conditions
		NULL,//style
		LOGO1LogoMenu_IconTab,  //ICON
		NULL,//titel
		LogoMenu_ItemTabl, //items
		sizeof(LogoMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};


MenuPageType CODE LOGO2Menu =
{
		"Osd_Logo2Menu",
		LOGO2MENU_START_X_POS,LOGO2MENU_START_Y_POS, //xpos ypos
		LogoWidth_LOGO2   ,LogoHeighth_LOGO2   , //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_LOGO2Menu, //currentPage
		Osd_RootMenu,   //NextPage
		
		LogoMenu_CheckCondition,//check conditions
		NULL,//style
		LOGO2LogoMenu_IconTab,  //ICON
		NULL,//titel
		LogoMenu_ItemTabl, //items
		sizeof(LogoMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};

MenuPageType CODE LOGO3Menu =
{
		"Osd_Logo3Menu",
		LOGO3MENU_START_X_POS,LOGO3MENU_START_Y_POS, //xpos ypos
		LogoWidth_LOGO3   ,LogoHeighth_LOGO3   , //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_LOGO3Menu, //currentPage
		Osd_RootMenu,   //NextPage
		
		LogoMenu_CheckCondition,//check conditions
		NULL,//style
		LOGO3LogoMenu_IconTab,  //ICON
		NULL,//titel
		LogoMenu_ItemTabl, //items
		sizeof(LogoMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};


MenuPageType CODE LOGO4Menu =
{
		"Osd_Logo4Menu",
		LOGO4MENU_START_X_POS,LOGO4MENU_START_Y_POS, //xpos ypos
		LogoWidth_LOGO4   ,LogoHeighth_LOGO4   , //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_LOGO4Menu, //currentPage
		Osd_RootMenu,   //NextPage
		
		LogoMenu_CheckCondition,//check conditions
		NULL,//style
		LOGO4LogoMenu_IconTab,  //ICON
		NULL,//titel
		LogoMenu_ItemTabl, //items
		sizeof(LogoMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};

MenuPageType CODE LOGO5Menu =
{
		"Osd_Logo5Menu",
		LOGO5MENU_START_X_POS,LOGO5MENU_START_Y_POS, //xpos ypos
		LogoWidth_LOGO5   ,LogoHeighth_LOGO5   , //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_LOGO5Menu, //currentPage
		Osd_RootMenu,   //NextPage
		
		LogoMenu_CheckCondition,//check conditions
		NULL,//style
		LOGO5LogoMenu_IconTab,  //ICON
		NULL,//titel
		LogoMenu_ItemTabl, //items
		sizeof(LogoMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};
#endif




///////////////////////////NoSignal Page///////////////////////////////////
#ifdef NoSignalEn
MenuItemType CODE  NoSignalMenu_ItemTabl[]=
{
   {
   	  "NoSignalMenuItem_NoSignal" ,
	   NULL,NULL,    //xpos ypos
   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NoSignalMenuItem_NoSignalTitelTab, //titel 
   	   NULL,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};

MenuPageType CODE NoSignalMenu =
{
		"Osd_NoSignalMenu",
		NOSIGNALMENU_START_X_POS,NOSIGNALMENU_START_Y_POS, //xpos ypos
		0x0A,0x01, //xsize ysize
		RED,TRANSPARENCE, //foreColor backColor
		OsdBlock3,  //osd block id  
		
		Osd_RootMenu,   //PrevPage
		Osd_NoSignalMenu, //currentPage
		Osd_RootMenu,   //NextPage
		
		NoSignalMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		NoSignalMenu_ItemTabl, //items
		sizeof(NoSignalMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};
#endif




///////////////////////////BatteryAdc Page///////////////////////////////////
#ifdef LowBaterryDetecEn 
MenuItemType CODE  BatteryAdcMenu_ItemTab[]=
{
   {
   	  "BatteryAdcMenu_ItemTab",
	   NULL,NULL,    //xpos ypos
       NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   BatteryAdcMenuItemVal_BatteryAdc,   // ItemValue
   	
   	   AdjustBatteryAdc,   // adjust 
   	   NULL,               // exect    
   	   
   	   NULL,           //key comd map
   	   NULL,          //KEY comd count
   	   osdSel,      // flags
   },
};
MenuPageType CODE BatteryAdcMenu =
{
		"Osd_BatteryAdcMenu",
		BATTERYADCMENU_START_X_POS,BATTERYADCMENU_START_Y_POS, //xpos ypos
		0x03,0x01,  //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock0,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_BatteryAdcMenu,    //currentPage
		Osd_RootMenu,        //NextPage
		
		BatteryAdcMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		BatteryAdcMenu_ItemTab, //items
		sizeof(BatteryAdcMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible|osdRedraw,//flags
};
#endif


///////////////////////////BT Page///////////////////////////////////
#ifdef BTEn
MenuItemType CODE  BTMenu_ItemTabl[]=
{
   {
   	  "BTMenuItem_BT" ,
	   NULL,NULL,    //xpos ypos
   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   BTMenuItem_BTTitelTab, //titel 
   	   NULL,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};

MenuPageType CODE BTMenu =
{
			"Osd_BTMenu",
			BTMENU_START_X_POS,BTMENU_START_Y_POS, //xpos ypos
			0x05,0x01, //xsize ysize
			GREEN,TRANSPARENCE, //foreColor backColor
			OsdBlock0,  //osd block id  
			
			Osd_RootMenu,   //PrevPage
			Osd_BTMenu, //currentPage
			Osd_RootMenu,   //NextPage
			
			BTMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			BTMenu_ItemTabl, //items
			sizeof(BTMenu_ItemTabl)/sizeof(MenuItemType), //item count
			NULL,  //exe
			NULL,  //time out
			osdVisible|osdRedraw,//flags
};


///////////////////////////BT Caller Page///////////////////////////////////
MenuItemType CODE  BTCallerMenu_ItemTabl[]=
{
   {
   	  "BTCallerMenuItem_BTCaller" ,
	   NULL,NULL,    //xpos ypos
   
   	   NULL,//check condition
   	   BTCallerMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   BTCallerMenuItem_BTCallerTitelTab, //titel 
   	   NULL,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   BTCallerMenuItem_KeyComdMap,   // key comd map
   	   sizeof(BTCallerMenuItem_KeyComdMap)/sizeof(KeyComdInterface),//KEY comd count
   	   osdSel,      // flags
   },
};

MenuPageType CODE BTCallerMenu =
{
			"Osd_BTCallerMenu",
			BTCALLERMENU_START_X_POS,BTCALLERMENU_START_Y_POS, //xpos ypos
			0x0E,0x01, //xsize ysize
			RED,TRANSPARENCE, //foreColor backColor
			OsdBlock2,  //osd block id  
			
			Osd_RootMenu,   //PrevPage
			Osd_BTCallerMenu, //currentPage
			Osd_RootMenu,   //NextPage
			
			BTCallerMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			BTCallerMenu_ItemTabl, //items
			sizeof(BTCallerMenu_ItemTabl)/sizeof(MenuItemType), //item count
			NULL,  //exe
			NULL,  //time out
			osdVisible|osdRedraw,//flags
};
#endif


///////////////////////////QuicklySource Page///////////////////////////////////
MenuItemType CODE  QuicklySourceMenu_ItemTabl[]=
{
   {
   	  "QuicklySourceMenuItem_QuicklySource" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   QuicklySourceMenuItemVal_QuicklySource,   // ItemValue
   	
   	   AdjustQuicklySource,   // adjust 
   	   ExectQuicklySource,   // exect    
   	   
   	   NULL, // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE QuicklySourceMenu =
{
		"Osd_QuicklySourceMenu",
		SOURCEMENU_START_X_POS,SOURCEMENU_START_Y_POS, //xpos ypos
		0x03,0x01,  //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock2,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_QuicklySource, //currentPage
		Osd_RootMenu,   //NextPage
		
		QuicklySourceMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		QuicklySourceMenu_ItemTabl, //items
		sizeof(QuicklySourceMenu_ItemTabl)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};




///////////////////////////Quicky Mute Page///////////////////////////////////
MenuItemType CODE  QuickyMuteMenu_ItemTab[]=
{
   {
   	  "QuickyMuteMenuItem_QuickyMute" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   NULL, //titel 
   	   QuicklyMuteMenuItemVal_QuicklyMute,   // ItemValue
   	
   	   AdjustQuicklyMute,   // adjust 
   	   ExectQuicklyMute,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE  QuickyMuteMenu =
{
		"Osd_ QuickyMuteMenu",
		MUTEMENU_START_X_POS,MUTEMENU_START_Y_POS, //xpos ypos
		0x02,0x01,  //xsize ysize
		GREEN,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_QuicklyMute, //currentPage
		Osd_RootMenu,   //NextPage
		
		QuicklyMuteMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		QuickyMuteMenu_ItemTab, //items
		sizeof(QuickyMuteMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME ,  //time out
		osdVisible|osdRedraw,//flags
};


///////////////////////////Quicky Volume Page///////////////////////////////////
MenuItemType CODE  QuicklyVolumeMenu_ItemTab[]=
{
   {
   	  "QuicklyVolumeMenuItem_QuicklyVolume" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   VolumeMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   VolumeMenuItem_VolumeTitelTab, //titel 
   	   VolumeMenuItemVal_Volume,   // ItemValue
   	
   	   AdjustVolume,   // adjust 
   	   ExectVolume,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE QuicklyVolumeMenu =
{
		"Osd_QuicklyVolumeMenu",
		MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
		0x12,0x02,  //xsize ysize
		RED,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_QuicklyVolume,    //currentPage
		Osd_RootMenu,   //NextPage
		
		VolumeMenu_CheckCondition,//check conditions
		NULL, //style
		NULL,  //ICON
		NULL,//titel
		QuicklyVolumeMenu_ItemTab, //items
		sizeof(QuicklyVolumeMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};


///////////////////////////Quicky Mode Page///////////////////////////////////
MenuItemType CODE  QuicklyModeMenu_ItemTab[]=
{
   {
   	  "QuicklyModeMenuItem_QuicklyMode" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   ModeMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   ModeMenuItem_ModeTitelTab, //titel 
   	   ModeMenuItemVal_Mode,   // ItemValue
   	
   	   AdjustMode,   // adjust 
   	   ExectMode,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE QuicklyModeMenu =
{
		"Osd_QuicklyModeMenu",
		MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
		0x12,0x02,  //xsize ysize
		RED,TRANSPARENCE, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_QuicklyMode,    //currentPage
		Osd_RootMenu,   //NextPage
		
		ModeMenu_CheckCondition,//check conditions
		NULL,  //style
		NULL,  //ICON
		NULL,//titel
		QuicklyModeMenu_ItemTab, //items
		sizeof(QuicklyModeMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};



///////////////////////////Quicky Sys Page///////////////////////////////////
MenuItemType CODE  QuicklySysMenu_ItemTab[]=
{
   {
   	  "QuicklySysMenuItem_QuicklySys" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   SysMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   SysMenuItem_SysTitelTab, //titel 
   	   SysMenuItemVal_Sys,   // ItemValue
   	
   	   AdjustSys,   // adjust 
   	   ExectSys,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE QuicklySysMenu =
{
       "Osd_QuicklySysMenu",
       MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
       0x12,0x02,  //xsize ysize
       RED,TRANSPARENCE, //foreColor backColor
       OsdBlock1,  //osd block id
       
       Osd_RootMenu,   //PrevPage
       Osd_QuicklySys,    //currentPage
       Osd_RootMenu,   //NextPage
       
       SysMenu_CheckCondition,//check conditions
       NULL,  //style
       NULL,  //ICON
       NULL,//titel
       QuicklySysMenu_ItemTab, //items
       sizeof(QuicklySysMenu_ItemTab)/sizeof(MenuItemType), //item count
       NULL,  //exe
       OSD_DISP_TIME,  //time out
       osdVisible|osdRedraw,//flags
};



///////////////////////////Quickly Brightness Page///////////////////////////////////
MenuItemType CODE  QuicklyBrightnessMenu_ItemTab[]=
{
   {
   	  "QuicklyBrightnessMenuItem_QuicklyBrightness" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   BrightnessMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   BrightnessMenuItem_BrightnessTitelTab, //titel 
   	   BrightnessMenuItemVal_Brightness,   // ItemValue
   	
   	   AdjustBrightness,   // adjust 
   	   ExectBrightness,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE QuicklyBrightnessMenu =
{
			"Osd_QuicklyBrightnessMenu",
			MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
            0x12,0x02,  //xsize ysize
            RED,TRANSPARENCE,  //foreColor backColor
            OsdBlock1,  //osd block id
			
			Osd_RootMenu,   //PrevPage
			Osd_QuicklyBrightness,    //currentPage
			Osd_RootMenu,   //NextPage
			
			BrightnessMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			QuicklyBrightnessMenu_ItemTab, //items
			sizeof(QuicklyBrightnessMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible|osdRedraw,//flags
};



///////////////////////////Quickly Contrast Page///////////////////////////////////
MenuItemType CODE  QuicklyContrastMenu_ItemTab[]=
{
   {
   	  "QuicklyContrastMenuItem_QuicklyContrast" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   ContrastMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   ContrastMenuItem_ContrastTitelTab, //titel 
   	   ContrastMenuItemVal_Contrast,   // ItemValue
   	
   	   AdjustContrast,   // adjust 
   	   ExectContrast,   // exect    
   	   
   	   NULL,     // key comd map
   	   NULL,    //KEY comd count
   	   osdSel,  // flags
   },
};



MenuPageType CODE QuicklyContrastMenu =
{
			"Osd_QuicklyContrastMenu",
			MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
            0x12,0x02,  //xsize ysize
            RED,TRANSPARENCE,  //foreColor backColor
            OsdBlock1,  //osd block id
			
			Osd_RootMenu,   //PrevPage
			Osd_QuicklyContrast,    //currentPage
			Osd_RootMenu,    //Osd_RootMenu,   //NextPage
			
			ContrastMenu_CheckCondition,//check conditions
			NULL,  //style
			NULL,  //ICON
			NULL,//titel
			QuicklyContrastMenu_ItemTab, //items
			sizeof(QuicklyContrastMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible|osdRedraw,//flags
};



///////////////////////////Quickly Saturation Page///////////////////////////////////
MenuItemType CODE  QuicklySaturationMenu_ItemTab[]=
{
   {
   	  "QuicklySaturationMenuItem_QuicklySaturation" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   SaturationMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   SaturationMenuItem_SaturationTitelTab, //titel 
   	   SaturationMenuItemVal_Saturation,   // ItemValue
   	
   	   AdjustSaturation,   // adjust 
   	   ExectSaturation,   // exect    
   	   
   	   NULL,   // key comd map
   	   NULL, //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE QuicklySaturationMenu =
{
		"Osd_QuicklySaturationMenu",
		MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
        0x12,0x02,  //xsize ysize
        RED,TRANSPARENCE,  //foreColor backColor
        OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_QuicklySaturation,    //currentPage
		Osd_RootMenu,        //NextPage
		
		SaturationMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		QuicklySaturationMenu_ItemTab, //items
		sizeof(QuicklySaturationMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};




///////////////////////////Brightness Page///////////////////////////////////
MenuItemType CODE  BrightnessMenu_ItemTab[]=
{
   {
   	  "BrightnessMenuItem_Brightness" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   BrightnessMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   BrightnessMenuItem_BrightnessTitelTab, //titel 
   	   BrightnessMenuItemVal_Brightness,   // ItemValue
   	
   	   AdjustBrightness,// adjust 
   	   ExectBrightness,// exect    
   	   
   	   BrightnessMenuItem_KeyComdMap,   // key comd map
   	   sizeof(BrightnessMenuItem_KeyComdMap)/sizeof(KeyComdInterface),//KEY comd count
   	   osdSel,   // flags
   },
};


MenuPageType CODE BrightnessMenu =
{
		"Osd_BrightnessMenu",
		MAINMENU_START_X_POS,MAINMENU_START_Y_POS, //xpos ypos
		0x12,0x02,  //xsize ysize
		RED,TRANSPARENCE,  //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_RootMenu,   //PrevPage
		Osd_BrightnessMenu,    //currentPage
		Osd_ContrastMenu,   //NextPage
		
		BrightnessMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		BrightnessMenu_ItemTab, //items
		sizeof(BrightnessMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible|osdRedraw,//flags
};


///////////////////////////Contrast Page///////////////////////////////////
MenuItemType CODE  ContrastMenu_ItemTab[]=
{
   {
   	  "ContrastMenuItem_Contrast" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   ContrastMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   ContrastMenuItem_ContrastTitelTab, //titel 
   	   ContrastMenuItemVal_Contrast,   // ItemValue
   	
   	   AdjustContrast,   // adjust 
   	   ExectContrast,   // exect    
   	   
   	   ContrastMenuItem_KeyComdMap,   // key comd map
   	   sizeof(ContrastMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE ContrastMenu =
{
			"Osd_ContrastMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_BrightnessMenu,   //PrevPage
			Osd_ContrastMenu,    //currentPage
			Osd_SaturationMenu,   //NextPage
			
			ContrastMenu_CheckCondition,//check conditions
			NULL,  //style
			NULL,  //ICON
			NULL,//titel
			ContrastMenu_ItemTab, //items
			sizeof(ContrastMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,   //flags
};


/////////////////////////// Saturation Page///////////////////////////////////
MenuItemType CODE  SaturationMenu_ItemTab[]=
{
   {
   	  "SaturationMenuItem_Saturation" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   SaturationMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   SaturationMenuItem_SaturationTitelTab, //titel 
   	   SaturationMenuItemVal_Saturation,   // ItemValue
   	
   	   AdjustSaturation,   // adjust 
   	   ExectSaturation,   // exect    
   	   
   	   SaturationMenuItem_KeyComdMap,   // key comd map
   	   sizeof(SaturationMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE SaturationMenu =
{
			"Osd_SaturationMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_ContrastMenu,   //PrevPage
			Osd_SaturationMenu,    //currentPage
			Osd_TintMenu,       //NextPage
			
			SaturationMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			SaturationMenu_ItemTab, //items
			sizeof(SaturationMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,   //flags
};



///////////////////////////Tint Page///////////////////////////////////
MenuItemType CODE  TintMenu_ItemTab[]=
{
   {
   	  "TintMenuItem_Tint" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   TintMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   TintMenuItem_TintTitelTab, //titel 
   	   TintMenuItemVal_Tint,   // ItemValue
   	
   	   AdjustTint,   // adjust 
   	   ExectTint,   // exect    
   	   
   	   TintMenuItem_KeyComdMap,   // key comd map
   	   sizeof(TintMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE TintMenu =
{
		"Osd_TintMenu",
		NULL,NULL, //xpos ypos
		NULL,NULL,  //xsize ysize
		NULL,NULL, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_SaturationMenu,   //PrevPage
		Osd_TintMenu,    //currentPage
		Osd_VolumeMenu,   //NextPage
		
		TintMenu_CheckCondition,//check conditions
		NULL,//style
		NULL,  //ICON
		NULL,//titel
		TintMenu_ItemTab, //items
		sizeof(TintMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible,   //flags
};



///////////////////////////Volume Page///////////////////////////////////
MenuItemType CODE  VolumeMenu_ItemTab[]=
{
   {
   	  "VolumeMenuItem_Volume" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   VolumeMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   VolumeMenuItem_VolumeTitelTab, //titel 
   	   VolumeMenuItemVal_Volume,   // ItemValue
   	
   	   AdjustVolume,   // adjust 
   	   ExectVolume,   // exect    
   	   
   	   VolumeMenuItem_KeyComdMap,   // key comd map
   	   sizeof(VolumeMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE VolumeMenu =
{
		"Osd_VolumeMenu",
		NULL,NULL, //xpos ypos
		NULL,NULL,  //xsize ysize
		NULL,NULL, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_TintMenu,   //PrevPage
		Osd_VolumeMenu,    //currentPage
		Osd_ModeMenu,   //NextPage
		
		VolumeMenu_CheckCondition,//check conditions
		NULL, //style
		NULL,  //ICON
		NULL,//titel
		VolumeMenu_ItemTab, //items
		sizeof(VolumeMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		OSD_DISP_TIME,  //time out
		osdVisible,//flags
};



///////////////////////////Mode Page///////////////////////////////////
MenuItemType CODE  ModeMenu_ItemTab[]=
{
   {
   	  "ModeMenuItem_Mode" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   ModeMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   ModeMenuItem_ModeTitelTab, //titel 
   	   ModeMenuItemVal_Mode,   // ItemValue
   	
   	   AdjustMode,   // adjust 
   	   ExectMode,   // exect    
   	   
   	   ModeMenuItem_KeyComdMap,   // key comd map
   	   sizeof(ModeMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE ModeMenu =
{
			"Osd_ModeMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_TintMenu,   //PrevPage
			Osd_ModeMenu,    //currentPage
			Osd_SysMenu,   //NextPage
			
			ModeMenu_CheckCondition,//check conditions
			NULL,  //style
			NULL,  //ICON
			NULL,//titel
			ModeMenu_ItemTab, //items
			sizeof(ModeMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,//flags
};





///////////////////////////Sys Page///////////////////////////////////
MenuItemType CODE  SysMenu_ItemTab[]=
{
   {
   	  "SysMenuItem_Sys" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   SysMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   SysMenuItem_SysTitelTab, //titel 
   	   SysMenuItemVal_Sys,   // ItemValue
   	
   	   AdjustSys,   // adjust 
   	   ExectSys,   // exect    
   	   
   	   SysMenuItem_KeyComdMap,   // key comd map
   	   sizeof(SysMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE SysMenu =
{
			"Osd_SysMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_ModeMenu,   //PrevPage
			Osd_SysMenu,    //currentPage
			Osd_LanguageMenu,   //NextPage
			
			SysMenu_CheckCondition,//check conditions
			NULL,  //style
			NULL,  //ICON
			NULL,//titel
			SysMenu_ItemTab, //items
			sizeof(SysMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,//flags
};


///////////////////////////Language Page///////////////////////////////////
MenuItemType CODE  LanguageMenu_ItemTab[]=
{
   {
   	  "LanguageMenuItem_Language" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   LanguageMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   LanguageMenuItem_LanguageTitelTab, //titel 
   	   NULL,    // ItemValue
   	
   	   AdjustLanguage,   // adjust 
   	   ExectLanguage,   // exect    
   	   
   	   LanguageMenuItem_KeyComdMap,   // key comd map
   	   sizeof(LanguageMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE LanguageMenu =
{
			"Osd_LanguageMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_SysMenu,   //PrevPage
			Osd_LanguageMenu,    //currentPage
			Osd_IRABMenu,   //NextPage
			
			LanguageMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			LanguageMenu_ItemTab, //items
			sizeof(LanguageMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,//flags
};




///////////////////////////IRAB Page///////////////////////////////////
MenuItemType CODE  IRABMenu_ItemTab[]=
{
   {
   	  "IRABMenuItem_IRAB" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   IRABMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   IRABMenuItem_IRABTitelTab, //titel 
   	   IRABMenuItemVal_IRAB,   // ItemValue
   	
   	   AdjustIRAB,   // adjust 
   	   ExectIRAB,   // exect    
   	   
   	   IRABMenuItem_KeyComdMap,   // key comd map
   	   sizeof(IRABMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE IRABMenu =
{
			"Osd_IRABMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_LanguageMenu,   //PrevPage
			Osd_IRABMenu,    //currentPage
			Osd_RadioFreqMenu,   //NextPage
			
			IRABMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			IRABMenu_ItemTab, //items
			sizeof(IRABMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,   //flags
};


///////////////////////////RadioFreq Page///////////////////////////////////
MenuItemType CODE  RadioFreqMenu_ItemTab[]=
{
   {
   	  "RadioFreqMenuItem_RadioFreq" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   RadioFreqMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   RadioFreqMenuItem_RadioFreqTitelTab, //titel 
   	   RadioFreqMenuItemVal_RadioFreq,   // ItemValue
   	
   	   AdjustRadioFreq,   // adjust 
   	   ExectRadioFreq,   // exect    
   	   
   	   RadioFreqMenuItem_KeyComdMap,   // key comd map
   	   sizeof(RadioFreqMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE RadioFreqMenu =
{
			"Osd_RadioFreqMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_IRABMenu,   //PrevPage
			Osd_RadioFreqMenu,    //currentPage
			Osd_ResetMenu,   //NextPage
			
			RadioFreqMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			RadioFreqMenu_ItemTab, //items
			sizeof(RadioFreqMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,   //flags
};


///////////////////////////Reset Page///////////////////////////////////
MenuItemType CODE  ResetMenu_ItemTab[]=
{
   {
   	  "ResetMenuItem_Reset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   ResetMenuItem_DrawStyle, //draw style
   	   NULL,  //icon 
   	   ResetMenuItem_LanguageTitelTab, //titel 
   	   ResetMenuItemVal_Reset,   // ItemValue
   	
   	   NULL,   // adjust 
   	   ExectReset,   // exect    
   	   
   	   ResetMenuItem_KeyComdMap,   // key comd map
   	   sizeof(ResetMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};



MenuPageType CODE ResetMenu =
{
			"Osd_ResetMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_IRABMenu,   //PrevPage
			Osd_ResetMenu,    //currentPage
			Osd_RootMenu,   //NextPage
			
			ResetMenu_CheckCondition,//check conditions
			NULL,//style
			NULL,  //ICON
			NULL,//titel
			ResetMenu_ItemTab, //items
			sizeof(ResetMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			OSD_DISP_TIME,  //time out
			osdVisible,//flags
};



#ifdef FactoryEn
///////////////////////////Factory Page///////////////////////////////////

MenuItemType CODE  FactoryMenu_ItemTab[]=
{  
    // 1 PIC
	{
   	  "FactoryMenuItem_PIC" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryMenuItem_PicTab, //titel 
   	   FactoryMenuPicItem_Val,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactoryMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 2 SWITCH
   {
   	  "FactoryMenuItem_SWITCH" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryMenuItem_SwitchTab, //titel 
   	   FactoryMenuSwitchItem_Val,   // ItemValue
   	
   	   NULL,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactoryMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE FactoryMenu =
{
			"Osd_FactoryMenu",
			FACTORYMENU_START_X_POS,FACTORYMENU_START_Y_POS, //xpos ypos
			0x20,0x0B,  //xsize ysize
			WHITE,TRANSPARENCE, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_RootMenu,   //PrevPage
			Osd_FactoryMenu,    //currentPage
			Osd_FactoryPicMenu,   //NextPage
			
			FactoryMenu_CheckCondition,//check conditions
			NULL, //style
			NULL,  //ICON
			FactoryMenu_TitelTab,//titel
			FactoryMenu_ItemTab, //items
			sizeof(FactoryMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			NULL,  //time out
			osdVisible|osdRedraw,   //flags
};



///////////////////////////FactoryPic Page///////////////////////////////////

MenuItemType CODE  FactoryPicMenu_ItemTab[]=
{  
    // 1 VcomDc
	{
   	  "FactoryPicMenuItem_VcomDc" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryPicMenuItem_VcomDcTitelTab, //titel 
   	   FactoryPicMenu_VcomDcVal,   // ItemValue
   	
   	   AdjustVideoVcomDc,   // adjust 
   	   ExectVideoVcomDc,   // exect    
   	   
   	   FactoryPicMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
   
   // 2 BrightnessOffset
   {
   	  "FactoryPicMenuItem_BrightnessOffset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryPicMenuItem_BrightnessTitelTab, //titel 
   	   FactoryPicMenu_BrightnessVal,   // ItemValue
   	
   	   AdjustVideoBrightness,   // adjust 
   	   ExectVideoBrightness,   // exect   
   	   
   	   FactoryPicMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

  // 3 ContrastOffset
  {
	  "FactoryPicMenuItem_ContrastOffset" ,
	   NULL,NULL,    //xpos ypos
	   
	   NULL,//check condition
	   NULL, //draw style
	   NULL,  //icon 
	   FactoryPicMenuItem_ContrastTitelTab, //titel 
	   FactoryPicMenu_ContrastVal,   // ItemValue

	   AdjustVideoContrast,   // adjust 
	   ExectVideoContrast,   // exect    
	   
	   FactoryPicMenuItem_KeyComdMap,   // key comd map
	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
	   osdSel,      // flags
   },

   // 4 SaturationOffset
   {
   	  "FactoryPicMenuItem_SaturationOffset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryPicMenuItem_SaturationTitelTab, //titel 
   	   FactoryPicMenu_SaturationVal,   // ItemValue
   	
   	   AdjustVideoSaturation,   // adjust 
   	   ExectVideoSaturation,   // exect    
   	   
   	   FactoryPicMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 5 OsdPosXOffset
   {
   	  "FactoryPicMenuItem_OsdPosXOffset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryPicMenuItem_OsdPosXOffsetTab, //titel 
   	   FactoryPicMenu_OsdPosXOffsetVal,   // ItemValue
   	
   	   AdjustVideoOsdXOffSet,   // adjust 
   	   ExectVideoOsdXOffSet,   // exect    
   	   
   	   FactoryPicMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 6 OsdPosYOffset
   {
   	  "FactoryPicMenuItem_OsdPosYOffset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactoryPicMenuItem_OsdPosYOffsetTab, //titel 
   	   FactoryPicMenu_OsdPosYOffsetVal,   // ItemValue
   	
   	   AdjustVideoOsdYOffSet,   // adjust 
   	   ExectVideoOsdYOffSet,   // exect    
   	   
   	   FactoryPicMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactoryPicMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE FactoryPicMenu =
{
		"Osd_FactoryPicMenu",
		NULL,NULL, //xpos ypos
		NULL,NULL,  //xsize ysize
		NULL,NULL, //foreColor backColor
		OsdBlock1,  //osd block id
		
		Osd_FactoryMenu,   //PrevPage
		Osd_FactoryPicMenu,    //currentPage
		Osd_FactorySwitchMenu,   //NextPage
		
		FactoryPicMenu_CheckCondition,//check conditions
		NULL, //style
		NULL,  //ICON
		NULL,//titel
		FactoryPicMenu_ItemTab, //items
		sizeof(FactoryPicMenu_ItemTab)/sizeof(MenuItemType), //item count
		NULL,  //exe
		NULL,  //time out
		osdVisible,   //flags
};




///////////////////////////FactorySwitch Page///////////////////////////////////
MenuItemType CODE  FactorySwitchMenu_ItemTab[]=
{
    // 1 VolumeSwitch
    {
   	  "FactorySwitchMenuItem_Volume" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_VolumeTitelTab, //titel 
   	   VolumeSwitchVal,   // ItemValue
   	
   	   AdjustVideoVolumeSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
   // 2 ScalerSwitch
    {
   	  "FactorySwitchMenuItem_Scaler" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_ScalerTitelTab, //titel 
   	   ScalerSwitchVal,   // ItemValue
   	
   	   AdjustVideoScalerSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

    // 3 FlipSwitch
    {
   	  "FactorySwitchMenuItem_Flip" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_FlipTitelTab, //titel 
   	   FlipSwitchVal,   // ItemValue
   	
   	   AdjustVideoFlipSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 4 ResetSwitch
	{
   	  "FactorySwitchMenuItem_Reset" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_ResetTitelTab, //titel 
   	   ResetSwitchVal,   // ItemValue
   	
   	   AdjustVideoResetSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 5 IRABSwitch
   {
   	  "FactorySwitchMenuItem_IRAB" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_IRABTitelTab, //titel 
   	   IRABSwitchVal,   // ItemValue
   	
   	   AdjustVideoIRABSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 6 RadioFreqSwitch
   {
   	  "FactorySwitchMenuItem_RadioFreq" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_RadioFreqTitelTab, //titel 
   	   RadioFreqSwitchVal,   // ItemValue
   	
   	   AdjustVideoRadioFreqSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
   
   // 7 PowerSwitch
	{
   	  "FactorySwitchMenuItem_Power" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_PowerTitelTab, //titel 
   	   PowerSwitchVal,   // ItemValue
   	
   	   AdjustSystemPowerSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },

   // 8 LogoIdSwitch
	{
   	  "FactorySwitchMenuItem_LogoId" ,
	   NULL,NULL,    //xpos ypos
   	   
   	   NULL,//check condition
   	   NULL, //draw style
   	   NULL,  //icon 
   	   FactorySwitchMenuItem_LogoIdTitelTab, //titel 
   	   LogoIdSwitchVal,   // ItemValue
   	
   	   AdjustSystemLogoIdSwitch,   // adjust 
   	   NULL,   // exect    
   	   
   	   FactorySwitchMenuItem_KeyComdMap,   // key comd map
   	   sizeof(FactorySwitchMenuItem_KeyComdMap)/sizeof(KeyComdInterface), //KEY comd count
   	   osdSel,      // flags
   },
};


MenuPageType CODE FactorySwitchMenu =
{
			"Osd_FactorySwitchMenu",
			NULL,NULL, //xpos ypos
			NULL,NULL,  //xsize ysize
			NULL,NULL, //foreColor backColor
			OsdBlock1,  //osd block id
			
			Osd_FactoryPicMenu,   //PrevPage
			Osd_FactorySwitchMenu,    //currentPage
			Osd_RootMenu,   //NextPage
			
			FactorySwitchMenu_CheckCondition,//check conditions
			NULL, //style
			NULL,  //ICON
			NULL,//titel
			FactorySwitchMenu_ItemTab, //items
			sizeof(FactorySwitchMenu_ItemTab)/sizeof(MenuItemType), //item count
			NULL,  //exe
			NULL,  //time out
			osdVisible,   //flags
};
#endif


//////////////////////////////////////System Menu List//////////////////////////////
MenuPageType* CODE tblMenus[]=
{
		&PowerOffMenu,
	    &PowerOnMenu,
        &RootMenu,

		#ifdef LogoEn
		&LOGO1Menu,
		&LOGO2Menu,
		&LOGO3Menu,
		&LOGO4Menu,
		&LOGO5Menu,
		#endif

		#ifdef LowBaterryDetecEn 
		&BatteryAdcMenu,
		#endif

		#ifdef NoSignalEn
        &NoSignalMenu,
        #endif

		#ifdef BTEn
		&BTMenu,
		&BTCallerMenu,
		#endif
		
		&QuicklySourceMenu,
		&QuickyMuteMenu,
		&QuicklyVolumeMenu,
		&QuicklyModeMenu,
        &QuicklySysMenu,
        &QuicklyBrightnessMenu,
		&QuicklyContrastMenu,
		&QuicklySaturationMenu,
		
		&BrightnessMenu,
		&ContrastMenu,
		&SaturationMenu,
		&TintMenu,
		&VolumeMenu,
		&ModeMenu,
		&SysMenu,
		&LanguageMenu,
		&IRABMenu,
		&RadioFreqMenu,		
		&ResetMenu,
				
        #ifdef FactoryEn
		&FactoryMenu,
		&FactoryPicMenu,
		&FactorySwitchMenu,
	    #endif
};


#define MenuCount sizeof(tblMenus)/sizeof(MenuPageType*)
#endif
