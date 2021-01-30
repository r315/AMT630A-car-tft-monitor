#define _OSD_BT_MENU_C_



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




#ifdef BTEn
/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE BTMenuStr[]=
{
    "\x065", //Link
    " ", //Release
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE BTMenu_TitelStr(void)
{
    return BTMenuStr[g_ucBTStatus];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType BTMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};
	adjust.Flags |= osdVisible;
	
	//printfStr("BTMenu_CheckCondition");
	return adjust;
}



/*****************************************************************
                          Item value table
*****************************************************************/



/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE BTMenuItem_BTTitelTab[]=
{
   {0,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,BTMenu_TitelStr,osdEnd},
};



/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/



/*****************************************************************
                           Item table
*****************************************************************/
#endif

