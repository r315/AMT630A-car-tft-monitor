#define _OSD_TINT_MENU_C_



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
UCHAR* CODE TintMenuStr[]=
{
    "TINT", 
    "TINT",
    "TINTA",
    "TINTE",
    "TINT",
    "TINT",
    "TINT",
    "\x010\x024\x007\x025\x010\x007",
    "#\x000#\x00C",
    "#\x000&\x000#\x071",
    "TINT", 
    "TINT", 
    "TINT"
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE TintMenu_TitelStr(void)
{
    return TintMenuStr[g_sysSetting.Osd.curlanguage];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType TintMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};

	if(IsPal())
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("Pal");
	}
	else
	{
       	 adjust.Flags |= osdVisible; 
		//printfStr("Ntsc");
	}
	//printfStr("TintMenu_CheckCondition");
	return adjust;
}



BOOL TintMenuItem_DrawStyle(void)
{
    //printfStr("TintMenuItem_DrawStyle");
    OsdWndClear(0X00, 0X00, 0X00, 0X11);
    return 0;
}


SWORD GetTintVal(void)
{
     //printfStr("GetHueVal");
     return g_sysSetting.Video.tint;
}


BOOL AdjustTint(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
        
		  if(g_sysSetting.Video.tint<MAX_VALUE)
		  {
		      g_sysSetting.Video.tint++;
		  } 
		  //printf("Inc Value ++ = %d",g_sysSetting.Video.hue);
    }
	if(opratComd == COMD_DecValue)
	{
	    
		  if(g_sysSetting.Video.tint>0)
		  {
		      g_sysSetting.Video.tint--;
		  } 
		 //printf("Dec Value -- =%d",g_sysSetting.Video.hue);
	}
	return 1;
}


BOOL ExectTint(void)
{
   UpdataPicPara(); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_Tint[]=
{
    {0,14,RED,TRANSPARENCE,RED,TRANSPARENCE, GetTintVal,osdDecNum|osdEnd},
};


DrawGuageType CODE Gugae_Tint[]=
{
    {1,0,WHITE,TRANSPARENCE,WHITE,TRANSPARENCE, MAX_VALUE,GetTintVal,osdEnd},
};

ItemValueType CODE TintMenuItemVal_Tint[]=
{
     {
	      Number_Tint,
	      Gugae_Tint,
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
TitelType CODE TintMenuItem_TintTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,TintMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/


