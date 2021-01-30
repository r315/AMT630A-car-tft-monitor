#define _OSD_MODE_MENU_C_



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
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"



SWORD GetModeVal(void);



/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE ModeMenuStr[]=
{
    "ZOOM",
    "ZOOM",
    "ZOOM",
    "ZOOM",
    "ZOOM",
    "ZOOM",
    "ZOOM",
    "\x015\x009\x00C\x011\x00E\x018\x00C\x013\x00E\x00C",
    "#\x02E#\x02F", 
    "#\x082#\x069#\x06D",
    "ZOOM",
    "ZOOM",
    "ZOOM",
};


UCHAR* CODE  ModeStr[]=
{
    "16:9", 
	" 4:3"
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * ModeMenu_TitelStr(void)
{
    return ModeMenuStr[g_sysSetting.Osd.curlanguage];
}


UCHAR * CODE DispModeStr(void)
{
      return ModeStr[GetModeVal()];  
}


/*****************************************************************
                           Function
*****************************************************************/
AdjustType ModeMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
	
	if(ON == g_sysSetting.Factory.scalerswitch)
	{
		adjust.Flags |= osdVisible;
		//printfStr("Mode Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("Mode Invisible");
	}
    adjust.XPos= g_sysSetting.Osd.xOffset;
	adjust.YPos= g_sysSetting.Osd.yOffset;
	//printfStr("ModeMenu_CheckCondition");
	return adjust;
}





BOOL ModeMenuItem_DrawStyle(void)
{
    //printfStr("ModeMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}


SWORD GetModeVal(void)
{
     //printf("GetModeVal= %x",g_sysSetting.Disp.zoomMode);
	 return g_sysSetting.Disp.zoomMode;
}


BOOL AdjustMode(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue)||(opratComd == COMD_SelMode))  
    {     
       (g_sysSetting.Disp.zoomMode == DISP_16_9)?(g_sysSetting.Disp.zoomMode = DISP_4_3):(g_sysSetting.Disp.zoomMode = DISP_16_9);
	   //printf("AdjustMode Value = %d",g_sysSetting.Disp.zoomMode);
    }
	return 1;
}


BOOL ExectMode(void)
{
   ConfigDispZoomDynPara(g_sysSetting.Disp.zoomMode); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_Mode[]=
{
    {1,7,RED,TRANSPARENCE,RED,TRANSPARENCE, GetModeVal,DispModeStr,osdEnd},
};


ItemValueType CODE ModeMenuItemVal_Mode[]=
{
     {
	      NULL,
	      NULL,
	      Option_Mode,   
	      osdEnd,
     },
};



/*****************************************************************
                          Item Icon table
*****************************************************************/




/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE ModeMenuItem_ModeTitelTab[]=
{
   {0,7,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,ModeMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
