#define _OSD_RESET_MENU_C_



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





/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE ResetMenuStr[]=
{
    "RESET",
    "RESET",
    "RESET",
    "RESET",
    "RESET",
    "RESET",
    "RESET",
    "\x025\x008\x024\x0B7\x025\x00E\x0B8\x028",
    " #\x01D#\x04D",
    "#\x081#\x082#\x076#\x06D",
    "\x014\x025\x024\x015\x018\x009\x007\x013\x00C",
    "RESET",
    "RESET"
};


UCHAR* CODE ResetStr[]=
{
  "\x029\x02B", 
};


/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE ResetMenu_TitelStr(void)
{
    return ResetMenuStr[g_sysSetting.Osd.curlanguage];
}


UCHAR * CODE DispResetStr(void)
{
      return ResetStr[0];  
}


/*****************************************************************
                           Function
*****************************************************************/
AdjustType ResetMenu_CheckCondition(void)
{
    AdjustType XDATA adjust = {0,0,0};
	
    if(ON == g_sysSetting.Factory.resetswitch)
	{
	    adjust.Flags |= osdVisible; 
		//printfStr("Reset Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("Reset Invisible");
	}
	//printfStr("ResetMenu_CheckCondition");
	return adjust;
}



BOOL ResetMenuItem_DrawStyle(void)
{
    //printfStr("ResetMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}



BOOL ExectReset(void)
{
   //printfStr("ExectReset");
   g_sysSetting.Video.brigthness = MAX_VALUE/2;
   g_sysSetting.Video.saturation= MAX_VALUE/2;
   g_sysSetting.Video.contrast= MAX_VALUE/2;
   g_sysSetting.Video.tint= MAX_VALUE/2;
   g_sysSetting.Audio.volVal = MAX_VALUE/2;
   g_sysSetting.Disp.zoomMode = DISP_16_9;
   g_sysSetting.IRAB.IRABVal = IROFF;
   ConfigDispZoomDynPara(g_sysSetting.Disp.zoomMode);  
   UpdataPicPara(); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_Reset[]=
{
    {1,8,RED,TRANSPARENCE,RED,TRANSPARENCE, NULL,DispResetStr,osdEnd},
};


ItemValueType CODE ResetMenuItemVal_Reset[]=
{
     {
	      NULL,
	      NULL,
	      Option_Reset,   
	      osdEnd,
     },
};


/*****************************************************************
                          Item Icon table
*****************************************************************/


/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE ResetMenuItem_LanguageTitelTab[]=
{
   {0,7,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,ResetMenu_TitelStr,osdEnd},
};

/*****************************************************************
                          Menu Icon table
*****************************************************************/


/*****************************************************************
                         Menu  Titel table
*****************************************************************/


