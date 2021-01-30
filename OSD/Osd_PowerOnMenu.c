#define _OSD_POWERON_MENU_C_



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



SWORD GetPowerOnInputSource(void);


/*****************************************************************
                            Text
*****************************************************************/

UCHAR* CODE  PowerOnStr[]=
{
  "AV1","AV2", "AV3"
};




/*****************************************************************
                            String
*****************************************************************/

UCHAR * CODE DispPowerOnStr(void)
{
      return PowerOnStr[GetPowerOnInputSource()];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType PowerOnMenu_CheckCondition (void)
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
	g_ucOsdEixt |= OsdMenu;

	if(g_sysSetting.Disp.zoomMode == DISP_4_3)
	{
	   adjust.XPos -= SOURCE_43_START_X_SHIFT;
	}
	else
	{
	   adjust.XPos -= 0X00;
	}
	printfStr("PowerOnMenu_CheckCondition");
	return adjust;
}



SWORD GetPowerOnInputSource(void)
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




/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_PowerOn[]=
{
    {0,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, GetPowerOnInputSource,DispPowerOnStr,osdEnd},
};


ItemValueType CODE PowerOnMenuItemVal_PowerOn[]=
{
     {
	      NULL,
	      NULL,
	      Option_PowerOn,   
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


/*****************************************************************
                           Item table
*****************************************************************/

