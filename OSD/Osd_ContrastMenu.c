#define _OSD_CONTRAST_MENU_C_



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
UCHAR* CODE ContrastMenuStr[]=
{
    "CONTRAST", 
    "CONTRASTE",
    "CONTRASTO",
    "CONTRASTE",
    "KONTRAST",
    "CONTRASTE",
    "CONTRAST",
    "\x010\x0B7\x013\x0B8\x024\x007\x025\x0B8\x013\x0B7\x025\x0B8\x028",
    "#\x014#\x015#\x003",
    "#\x06B#\x06C#\x06D#\x065#\x06E#\x06D",
    "\x010\x024\x013\x027\x025\x007\x0B8\x027",
    "KONTRAST",
    "KONTRAST"
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE ContrastMenu_TitelStr(void)
{
    return ContrastMenuStr[g_sysSetting.Osd.curlanguage];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType ContrastMenu_CheckCondition(void)
{
    AdjustType XDATA adjust ={0,0,0};
	adjust.Flags |= osdVisible;
	//printfStr("ContrastMenu_CheckCondition");
	return adjust;
}




BOOL ContrastMenuItem_DrawStyle(void)
{
    //printfStr("ContrastMenuItem_DrawStyle");
    OsdWndClear(0X00, 0X00, 0X00, 0X11);
    return 0;
}


SWORD GetContrastVal(void)
{
     //printfStr("GetContrastVal");
     return g_sysSetting.Video.contrast;
}


BOOL AdjustContrast(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		  if(g_sysSetting.Video.contrast<MAX_VALUE)
		  {
		      g_sysSetting.Video.contrast++;
		  } 
		  //printf("Inc Value ++ = %d",g_sysSetting.Video.contrast);
    }
	if(opratComd == COMD_DecValue)
	{
		  if(g_sysSetting.Video.contrast>0)
		  {
		      g_sysSetting.Video.contrast--;
		  } 
		 //printf("Dec Value -- =%d",g_sysSetting.Video.contrast);
	}
	if(opratComd == COMD_Contrast)
    {     
		  g_sysSetting.Video.contrast++;
		  if(g_sysSetting.Video.contrast >MAX_VALUE)
		  {
		     g_sysSetting.Video.contrast = 0;
		  }
		  //printf("contrast Adjust Value = %d",g_sysSetting.Video.contrast);
    }
	return 1;
}


BOOL ExectContrast(void)
{
   UpdataPicPara(); 
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_Contrast[]=
{
    {0,14,RED,TRANSPARENCE,RED,TRANSPARENCE, GetContrastVal,osdDecNum|osdEnd},
};

DrawGuageType CODE Gugae_Contrast[]=
{
    {1,0,WHITE,TRANSPARENCE,WHITE,TRANSPARENCE, MAX_VALUE,GetContrastVal,osdEnd},
};

ItemValueType CODE ContrastMenuItemVal_Contrast[]=
{
     {
	      Number_Contrast,
	      Gugae_Contrast,
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
TitelType CODE ContrastMenuItem_ContrastTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,ContrastMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
