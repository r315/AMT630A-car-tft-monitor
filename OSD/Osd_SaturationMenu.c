#define _OSD_SATURATION_MENU_C_



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
UCHAR* CODE SaturationMenuStr[]=
{
    "SATURATION",
    "SATURATION",
    "SATURAZIONE",
    "SATURACI\x099N",
    "S\x089TTIGUNG",
    "SATURA\x0AD\x088O",
    "KLEUR",
    "\x017\x009\x00C\x0B8\x013\x0B7\x025\x0B8\x028",
    "#\x000#\x003",
    "#\x052#\x003",
    "\x017\x009\x01F\x027",
    "SATURATION",
    "SATURATION"
};




/*****************************************************************
                            String
*****************************************************************/
UCHAR * SaturationMenu_TitelStr(void)
{
    return SaturationMenuStr[g_sysSetting.Osd.curlanguage];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType SaturationMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
    adjust.Flags |= osdVisible;
	//printfStr("SaturationMenu_CheckCondition");
	return adjust;
}





BOOL SaturationMenuItem_DrawStyle(void)
{
    //printfStr("SaturationMenuItem_DrawStyle");
    OsdWndClear(0X00, 0X00, 0X00, 0X11);
    return 0;
}


SWORD GetSaturationVal(void)
{
     //printfStr("GetSaturationVal");
     return g_sysSetting.Video.saturation;
}


BOOL AdjustSaturation(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		  if(g_sysSetting.Video.saturation<MAX_VALUE)
		  {
		      g_sysSetting.Video.saturation++;
		  } 
		  //printf("Inc Value ++ = %d",g_sysSetting.Video.contrast);
    }
	if(opratComd == COMD_DecValue)
	{
		  if(g_sysSetting.Video.saturation>0)
		  {
		      g_sysSetting.Video.saturation--;
		  } 
		 //printf("Dec Value -- =%d",g_sysSetting.Video.contrast);
	}
	if(opratComd == COMD_Saturation)
    {     
		g_sysSetting.Video.saturation++;
		if(g_sysSetting.Video.saturation >MAX_VALUE)
		{
		   g_sysSetting.Video.saturation = 0;
		}
	    //printf("saturation Adjust Value = %d",g_sysSetting.Video.saturation);
    }
	return 1;
}


BOOL ExectSaturation(void)
{
   UpdataPicPara(); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_Saturation[]=
{
    {0,14,RED,TRANSPARENCE,RED,TRANSPARENCE, GetSaturationVal,osdDecNum|osdEnd},
};

DrawGuageType CODE Gugae_Saturation[]=
{
    {1,0,WHITE,TRANSPARENCE,WHITE,TRANSPARENCE, MAX_VALUE,GetSaturationVal,osdEnd},
};

ItemValueType CODE SaturationMenuItemVal_Saturation[]=
{
     {
	      Number_Saturation,
	      Gugae_Saturation,
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
TitelType CODE SaturationMenuItem_SaturationTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,SaturationMenu_TitelStr,osdEnd},
};

/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
