#define _OSD_BRIGHTNESS_MENU_C_



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
UCHAR* CODE BrightnessMenuStr[]=
{
    "BRIGHTNESS",  
    "LUMINOSIT\x072",
    "LUMINOSIT\x06B",
    "BRILHO",
    "HELLIGKEIT",
    "BRILHO",
    "HELDER",
    "\x01F\x024\x010\x0B7\x025\x0B8\x028",
    "#\x064#\x003",
    "#\x086#\x06F#\x070",
    "\x01F\x025\x010\x024\x0B8\x027",
    "JASNO\x000\x001",
    "PARlAKlIK"
};




/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE BrightnessMenu_TitelStr(void)
{   
    return BrightnessMenuStr[g_sysSetting.Osd.curlanguage];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType BrightnessMenu_CheckCondition (void)
{
    AdjustType XDATA adjust = {0,0,0};
	if(g_ucOsdEixt & OsdMenu)
	{  
	   adjust.Flags |= osdVisible;
	}
	else
	{
	  adjust.Flags |= osdInvisible;
	}
	g_ucOsdEixt &= ~OsdMenu;
	g_ucOsdEixt |= OsdSource;
	
	adjust.XPos= g_sysSetting.Osd.xOffset;
	adjust.YPos= g_sysSetting.Osd.yOffset;
	//printfStr("BrightnessMenu_CheckCondition");
	return adjust;
}


BOOL BrightnessMenuItem_DrawStyle(void)
{
	//printfStr("BrightnessMenuItem_DrawStyle");
    OsdWndClear(0X00, 0X00, 0X00, 0X11);
	return 0;
}


SWORD GetBrightnessVal(void)
{
     //printfStr("GetBrightnessVal");
     return g_sysSetting.Video.brigthness;
}


BOOL AdjustBrightness(UCHAR opratComd)
{	
    if(opratComd == COMD_IncValue)
    {
		  if(g_sysSetting.Video.brigthness<MAX_VALUE)
		  {
		      g_sysSetting.Video.brigthness++;
		  } 
    }
	if(opratComd == COMD_DecValue)
	{
		  if(g_sysSetting.Video.brigthness>0)
		  {
		      g_sysSetting.Video.brigthness--;
		  } 
	}
	if(opratComd == COMD_Brightness)
    {     
		  g_sysSetting.Video.brigthness++;
		  if(g_sysSetting.Video.brigthness >MAX_VALUE)
		  {
		     g_sysSetting.Video.brigthness = 0;
		  }
		  //printf("brigthness Adjust Value = %d",g_sysSetting.Video.brigthness);
	}
	return 1;
}


BOOL ExectBrightness(void)
{
   //printfStr("ExectBrightness");
   UpdataPicPara(); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_Brightness[]=
{
    {0,14,RED,TRANSPARENCE,RED,TRANSPARENCE, GetBrightnessVal,osdDecNum|osdEnd},
};

DrawGuageType CODE Gugae_Brightness[]=
{
    {1,0,WHITE,TRANSPARENCE,WHITE,TRANSPARENCE, MAX_VALUE,GetBrightnessVal,osdEnd},
};

ItemValueType CODE BrightnessMenuItemVal_Brightness[]=
{
     {
	      Number_Brightness,
	      Gugae_Brightness,
	      NULL,   
	      osdEnd,
     },
};


/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE BrightnessMenuItem_BrightnessTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,BrightnessMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
