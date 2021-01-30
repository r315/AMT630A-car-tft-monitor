#define _OSD_IRAB_MENU_C_



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


SWORD GetIRABVal(void);


/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE IRABMenuStr[]=
{
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
    "IR A&\x003B",
};


UCHAR* CODE IRABStr[3]=
{
  "   IR OFF  ",
  "A:2.3M&\x0032.8M",
  "B:3.2M&\x0033.8M"
};



/*****************************************************************
                            String
*****************************************************************/
UCHAR * IRABMenu_TitelStr(void)
{
    return IRABMenuStr[g_sysSetting.Osd.curlanguage];
}

UCHAR * CODE DispIRABStr(void)
{
      return IRABStr[GetIRABVal()];  
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType IRABMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
	
	if(ON == g_sysSetting.Factory.irabswitch)
	{
	    adjust.Flags |= osdVisible; 
		//printfStr("IRAB Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("IRAB Invisible");
	}
	//printfStr("IRABMenu_CheckCondition");
	return adjust;
}



SWORD GetIRABVal(void)
{
     //printfStr("GetIRABVal");
     return g_sysSetting.IRAB.IRABVal;
}





BOOL IRABMenuItem_DrawStyle(void)
{
    //printfStr("IRABMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}


BOOL AdjustIRAB(UCHAR opratComd)
{    

	if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {    
		if(IROFF == g_sysSetting.IRAB.IRABVal)
        {
           g_sysSetting.IRAB.IRABVal = IRA;
        }
		else if(IRA == g_sysSetting.IRAB.IRABVal)
		{
		   g_sysSetting.IRAB.IRABVal = IRB;
		}
		else if(IRB == g_sysSetting.IRAB.IRABVal)
		{
		     g_sysSetting.IRAB.IRABVal = IROFF;
		}
	   //printf("AdjustIRAB Value = %d",g_sysSetting.IRAB.IRABVal);
    }
	return 1;
}


BOOL ExectIRAB(void)
{
	#ifdef IrABCtrlEn
	SetIRABSwitch(g_sysSetting.IRAB.IRABVal);
	#endif
	
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/

DrawOptionType CODE Option_IRAB[]=
{
    {1,3,RED,TRANSPARENCE,RED,TRANSPARENCE, GetIRABVal,DispIRABStr,osdEnd},
};
ItemValueType CODE IRABMenuItemVal_IRAB[]=
{
     {
	      NULL,
	      NULL,
	      Option_IRAB,   
	      osdEnd,
     },
};


/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE IRABMenuItem_IRABTitelTab[]=
{
   {0,6,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,IRABMenu_TitelStr,osdEnd},
};



/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/


