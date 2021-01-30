#define _OSD_VOLUME_MENU_C_



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
UCHAR* CODE VolumeMenuStr[]=
{
    "VOLUME",
	"VOLUME",
	"VOLUME",
	"VOLUME",
    "LAUTST\x093RKE",
	"VOLUME",
	"VOLUME",
	"\x00A\x024\x0B7\x012\x010\x0B7\x025\x0B8\x028",
	"#\x056#\x063",
	"#\x056#\x063",
	"VOLUME",
	"VOLUME",
	"VOLUME",
};




/*****************************************************************
                            String
*****************************************************************/
UCHAR * VolumeMenu_TitelStr(void)
{
    return VolumeMenuStr[g_sysSetting.Osd.curlanguage];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType VolumeMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};

	if(ON == g_sysSetting.Factory.volumeswitch)
	{   
		adjust.Flags |= osdVisible;
		//printfStr("Volume Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("Volume Invisible");
	}
	adjust.XPos= g_sysSetting.Osd.xOffset;
	adjust.YPos= g_sysSetting.Osd.yOffset;
	
	//printfStr("VolumeMenu_CheckCondition");
	return adjust;
}




BOOL VolumeMenuItem_DrawStyle(void)
{
    //printfStr("VolumeMenuItem_DrawStyle");
    OsdWndClear(0X00, 0X00, 0X00, 0X11);
    return 0;
}


SWORD GetVolumeVal(void)
{
     //printfStr("GetVolumeVal");
     return g_sysSetting.Audio.volVal;
}


BOOL AdjustVolume(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue)||(opratComd == COMD_IncVolume))
    {
		  if(g_sysSetting.Audio.volVal<MAX_VALUE)
		  {
		      g_sysSetting.Audio.volVal++;
		  } 
		  //printf("volVal Inc Value ++ = %d",g_sysSetting.Audio.volVal);
    }
	if((opratComd == COMD_DecValue)||(opratComd == COMD_DecVolume))
	{
	    
		  if(g_sysSetting.Audio.volVal>0)
		  {
		      g_sysSetting.Audio.volVal--;
		  } 
		 //printf("volVal Dec Value -- =%d",g_sysSetting.Audio.volVal);
	}
	return 1;
}


BOOL ExectVolume(void)
{
   //printfStr("ExectVolume");
   #ifdef AudioCtrlEn
   #if AUDIO_CTRL == VOLUME_PWM_CTRL
   CtrlVolumeByPWM(g_sysSetting.Audio.volVal);
   #endif
   #endif
   
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_Volume[]=
{
    {0,14,RED,TRANSPARENCE,RED,TRANSPARENCE, GetVolumeVal,osdDecNum|osdEnd},
};

DrawGuageType CODE Gugae_Volume[]=
{
    {1,0,WHITE,TRANSPARENCE,WHITE,TRANSPARENCE, MAX_VALUE,GetVolumeVal,osdEnd},
};


ItemValueType CODE VolumeMenuItemVal_Volume[]=
{
     {
	      Number_Volume,
	      Gugae_Volume,
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
TitelType CODE VolumeMenuItem_VolumeTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,VolumeMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/

