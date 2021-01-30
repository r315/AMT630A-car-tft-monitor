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
#include "AMT_Reg.h"
#include "AMT_Drv.h"
#include "AMT_Mcu.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"



#ifdef LowBaterryDetecEn 
/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE BatteryAdcStr[]=
{
  "\x0F7\x0F8\x0FC",
  "\x0F7\x0F9\x0FC",
  "\x0F7\x0FA\x0FC",
  "\x0F7\x0FB\x0FC",
};

/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE BatteryAdcMenuStr(void)
{     
      return BatteryAdcStr[g_ucBatteryAdcLev];  
}

/*****************************************************************
                           Function
*****************************************************************/
AdjustType BatteryAdcMenu_CheckCondition (void)
{
	AdjustType XDATA adjust={0,0,0};
	adjust.Flags |= osdVisible;
	return adjust;
}


BOOL AdjustBatteryAdc(UCHAR opratComd)
{
    if(opratComd == COMD_BatteryAdc)
	{
	    #ifdef LowBaterryDetecEn 
		if(g_ucBatteryAdcVal < BatterVolteAdcVal(BatterLowVolte))
		{
			g_ucBatteryAdcLev = BatterAdc_Lev0;
		}
	    else if(g_ucBatteryAdcVal < BatterVolteAdcVal(BatterMidVolte))
		{
			g_ucBatteryAdcLev = BatterAdc_Lev1;
		}
	    else if(g_ucBatteryAdcVal < BatterVolteAdcVal(BatterMaxVolte))
		{
			g_ucBatteryAdcLev = BatterAdc_lev2;
	    }
		else 
		{
		   g_ucBatteryAdcLev = BatterAdc_Lev3;
		}
        #endif //#ifdef LowBaterryDetecEn 
	}		  
	return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_BatteryAdc[]=
{
	{0,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,BatteryAdcMenuStr,osdEnd},
};

ItemValueType CODE BatteryAdcMenuItemVal_BatteryAdc[]=
{
     {
	      NULL,
	      NULL,
	      Option_BatteryAdc,   
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


/*****************************************************************
                           Menu 
*****************************************************************/

#endif
