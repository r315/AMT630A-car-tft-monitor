#define _OSD_QUICKLY_SOURCE_MENU_C_



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
#include "ir.h"


SWORD GetQuicklyInputSource(void);


/*****************************************************************
                            Text
*****************************************************************/


UCHAR* CODE  QuicklySourceStr[]=
{
  "AV1","AV2", "AV3"
};


/*****************************************************************
                            String
*****************************************************************/

UCHAR * CODE DispQuicklySourceStr(void)
{
      return QuicklySourceStr[GetQuicklyInputSource()];
}


/*****************************************************************
                           Function
*****************************************************************/
AdjustType QuicklySourceMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};
	
	if(g_ucOsdEixt & OsdSource)
	{  
	   adjust.Flags |= osdVisible;
	}
	else
	{
	  adjust.Flags |= osdInvisible;
	}
    g_ucOsdEixt &= ~OsdSource;
	g_ucOsdEixt |= OsdMenu|OsdBrightness|OsdContrast|OsdSaturation|OsdVolume|OsdMode|OsdSys;

	if(g_sysSetting.Disp.zoomMode == DISP_4_3)
	{
	   adjust.XPos -= SOURCE_43_START_X_SHIFT;
	}
	else
	{
	   adjust.XPos -= 0X00;
	}
	//printfStr("QuicklySourceMenu_CheckCondition");
	return adjust;
}


SWORD GetQuicklyInputSource(void)
{   	 
     switch(g_sysSetting.Video.curSource)
     {
		 case INPUT_AV1:
		 	  return 0;
			  
		 case INPUT_AV2:
		 case INPUT_CAMERA_Car:
		 	  return 1;
			  
		 default:
		 	  return 0;
     }
}

BOOL AdjustQuicklySource(UCHAR opratComd)
{
     opratComd = opratComd;

	 if(!IsCarReversingEn())
	 {
        g_sysSetting.Video.curSource = SelNextVideoSource(g_sysSetting.Car.RemberSource);
	    g_sysSetting.Car.RemberSource = g_sysSetting.Video.curSource; //记忆倒车通道 
	 }
	 return 1;
}

BOOL ExectQuicklySource(void)
{ 
   	if(!IsCarReversingEn())
   	{
		#ifdef AudioCtrlEn
		SetAudioMute(); 
		SelAudioInputSource(g_sysSetting.Video.curSource);
	    #endif
		
		TurnOffBackLight();
		ExitLowPowerMode();
		HideMenu();
	    SelVideoInputSource(g_sysSetting.Video.curSource);
        DelayMs(200);
		
		#ifdef NoSignalBLOffEn 
		if(IsSignalOk())
		{  
	      TurnOnBackLight();
		}
		#else
	    TurnOnBackLight();
		#endif
   	}
	else
	{
	    if(!IsCarRemCameraSource())
	    {				
			#ifdef AudioCtrlEn
			SetAudioMute(); 
			SelAudioInputSource(g_sysSetting.Video.curSource);
		    #endif

			TurnOffBackLight();
			
            #ifdef NoSignalBLOffEn
			ExitLowPowerMode();
			#else
			if(IsPowerOff())
			{
			   ExitLowPowerMode();
			}
			#endif
			
			HideMenu();
		    SelVideoInputSource(g_sysSetting.Video.curSource);
            DelayMs(200);
			
			#ifdef NoSignalBLOffEn 
			if(IsSignalOk())
			{ 
	          TurnOnBackLight();
			}
			#else
	        TurnOnBackLight();
			#endif
   	    }
		else
		{				
		    if(IsPowerOff())
		    {
			   ExitLowPowerMode();
			   DelayMs(400);
               #ifdef NoSignalBLOffEn 
			   if(IsSignalOk())
			   {  
	             TurnOnBackLight();
			   }
			   #else
	           TurnOnBackLight();
			   #endif
		    }
			else
			{   				
			    #ifdef NoSignalBLOffEn
				TurnOffBackLight();
			    ExitLowPowerMode();
				DelayMs(200);
				if(IsSignalOk())
			    {  
	              TurnOnBackLight();
			    }
				else
				{				   
			       EnterLowPowerMode();
				}
				#else
                TurnOffBackLight();
                ExitLowPowerMode();
                HideMenu();
                SelVideoInputSource(g_sysSetting.Video.curSource);				
				DelayMs(200);
				TurnOnBackLight();
				#endif
			}
		}
	}
	g_ucRemoteKeyVal = IR_NULL_KEY;
	return 1;
}

/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_QuicklySource[]=
{
    {0,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, GetQuicklyInputSource,DispQuicklySourceStr,osdEnd},
};

ItemValueType CODE QuicklySourceMenuItemVal_QuicklySource[]=
{
     {
	      NULL,
	      NULL,
	      Option_QuicklySource,   
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


