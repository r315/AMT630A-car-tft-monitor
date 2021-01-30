#define _OSD_NOSIGNAL_MENU_C_



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




#ifdef NoSignalEn
/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE NoSignalMenuStr[]=
{
    "NO SIGNAL",
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE NoSignalMenu_TitelStr(void)
{
    return NoSignalMenuStr[0];
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType NoSignalMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};
	adjust.Flags |= osdVisible;
	//printfStr("NoSignalMenu_CheckCondition");
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
TitelType CODE NoSignalMenuItem_NoSignalTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,NoSignalMenu_TitelStr,osdEnd},
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


