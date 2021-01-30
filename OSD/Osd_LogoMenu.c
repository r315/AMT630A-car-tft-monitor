#define _OSD_LOGO_MENU_C_



#include "DataType.h"
#include "SystemConfig.h"
#include "Global.h"
#include "MsgMap.h"
#include "sysWorkPara.h"
#include "sysPower.h" 
#include "videoProc.h"
#include "configLCDPara.h"
#include "Debug.h"
#include "Delay.h"
#include "AMT_REG.H"
#include "AMT_Drv.h"
#include "AMT_MCU.h"
#include "Flash.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "Osd_LogoFontDat.h"
#include "Osd_LogoList.h"


#ifdef LogoEn
/*****************************************************************
                           Function
*****************************************************************/
AdjustType LogoMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};

	adjust.Flags |= osdVisible;
	
	//printfStr("LogoMenu_CheckCondition");
	return adjust;
}


void InitLogoMenuDat(void)
{  

    UINT XDATA IconSize = 0x00;
	UCHAR XDATA BitMapPattleSize = 0x00;
	UINT XDATA FontRamNum = 0x00;
	ULONG XDATA StartAddr = 0x00;
    UCHAR  XDATA  LogoBitMapPattle[32]={0x00};

	printfStr("InitLogoMenuDat");
	FontRamNum = LogoList[g_sysSetting.Logo.logoID].FontRamNum;
	StartAddr = FLASH_LOGO_ADDR + LogoList[g_sysSetting.Logo.logoID].StarAddr;
	
	if(LogoList[g_sysSetting.Logo.logoID].ColorMode)
	{  
	   IconSize = 0xC0;
	   BitMapPattleSize = 0x20;
	   OsdConfigDispMode(OSD_BITMAP_MODE,OSD_DISP_NORMAL);	
	   ReadFlashSysPara(StartAddr, (UCHAR *)&LogoBitMapPattle, 32); 
	}
	else
	{
	  IconSize = 0x30;
	  BitMapPattleSize = 0x01;
	  OsdConfigDispMode(OSD_MODE,OSD_DISP_NORMAL);	
	  
	}
    OsdConfigBitmapStarIndex(LOGOBITMAP_SATRT_INDEX);
    OsdConfigBitmapPalette(LogoBitMapPattle);
    DMALoadFontRam(StartAddr+BitMapPattleSize,LOGOBITMAP_SATRT_INDEX<<4,IconSize*FontRamNum);  

}


#endif

