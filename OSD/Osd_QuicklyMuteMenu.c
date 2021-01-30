#define _OSD_QUICKLY_MUTE_MENU_C_


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



SWORD GetQuicklyMuteVal(void);



/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE  QuicklyMuteStr[]=
{
    "\x024", 
	"\x025"
};


/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE DispQuicklyMuteStr(void)
{
      return QuicklyMuteStr[GetQuicklyMuteVal()];
}


/*****************************************************************
                           Function
*****************************************************************/
AdjustType QuicklyMuteMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};
	adjust.Flags |= osdVisible;
	g_ucOsdEixt = OsdMenu|OsdSource;
	//printfStr("QuicklyMuteMenu_CheckCondition");
	return adjust;
}

SWORD GetQuicklyMuteVal(void)
{
	 return g_sysSetting.Audio.status;
}


BOOL AdjustQuicklyMute(UCHAR opratComd)
{    	 
     if(opratComd == COMD_SelMuteOnOff)
     {
         (g_sysSetting.Audio.status == MUTE_ON)?(g_sysSetting.Audio.status = MUTE_OFF):(g_sysSetting.Audio.status = MUTE_ON);
          //printf("g_sysSetting.Audio.status = %d",g_sysSetting.Audio.status);
	 }
	 return 1;
}


BOOL ExectQuicklyMute(void)
{   
    if (g_sysSetting.Audio.status == MUTE_ON)
    {
       #ifdef AudioCtrlEn
       SetAudioMute();
	   #endif
    }
	else
	{  
	   #ifdef AudioCtrlEn
	   OpenAudio();	
	   #endif
	}
	return 1;
}

/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_QuicklyMute[]=
{    
    {0,1,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, GetQuicklyMuteVal,DispQuicklyMuteStr,osdEnd}, 
};
ItemValueType CODE QuicklyMuteMenuItemVal_QuicklyMute[]=
{
     {
	      NULL,
	      NULL,
	      Option_QuicklyMute,   
	      osdEnd,
     },
};

/*****************************************************************
                          Item Icon table
*****************************************************************/


/*****************************************************************
                         Item  Titel table
*****************************************************************/


/*****************************************************************
                          Menu Icon table
*****************************************************************/


/*****************************************************************
                         Menu  Titel table
*****************************************************************/

