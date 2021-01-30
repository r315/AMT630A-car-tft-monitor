#define _OSD_SYS_MENU_C_



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


SWORD GetSysVal(void);



/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE SysMenuStr[]=
{
    "ROTATE",
    "ROTATE",
    "ROTATE",
    "ROTATE",
    "ROTATE",
    "ROTATE",
    "ROTATE",
    "\x0B7\x008\x0B7\x024\x0B7\x0B8",
    "#\x037#\x038",
    "&\x001&\x002",
    "ROTATE",
    "ROTATE",
    "ROTATE",
};


UCHAR* CODE  SysStr[]=
{
	"*DL  DR  UL  UR", 
	" DL *DR  UL  UR", 
	" DL  DR *UL  UR", 
	" DL  DR  UL *UR"
};


/*****************************************************************
                            String
*****************************************************************/
UCHAR * SysMenu_TitelStr(void)
{
    return SysMenuStr[g_sysSetting.Osd.curlanguage];
}



UCHAR * CODE DispSysStr(void)
{
      return SysStr[GetSysVal()];  
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType SysMenu_CheckCondition(void)
{
    AdjustType XDATA adjust = {0,0,0};
    if(ON == g_sysSetting.Factory.flipswitch)
	{
		adjust.Flags |= osdVisible;
	   //printfStr("Sys Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("Sys Invisible");
	}
	adjust.XPos= g_sysSetting.Osd.xOffset;
	adjust.YPos= g_sysSetting.Osd.yOffset;
	//printfStr("SysMenu_CheckCondition");
	return adjust;
}


BOOL SysMenuItem_DrawStyle(void)
{
    //printfStr("SysMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}


SWORD GetSysVal(void)
{
     //printf("GetModeVal= %x",g_sysSetting.Disp.flipMode);
	 return g_sysSetting.Disp.flipMode;
}


BOOL AdjustSys(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue)||(opratComd == COMD_SelSys)) 
    {     
       switch(g_sysSetting.Disp.flipMode)
       {
         case FilpLeft:
		 	  g_sysSetting.Disp.flipMode = FilpRight;
		 	  break;
			  
		 case FilpRight:
		 	 g_sysSetting.Disp.flipMode = FilpUp;
		 	  break;
			  
		 case FilpUp:
		 	  g_sysSetting.Disp.flipMode = FilpDown;
		 	  break;
			  
		 case FilpDown:
		 	  g_sysSetting.Disp.flipMode = FilpLeft;
		 	  break;
			  
		default:
			  g_sysSetting.Disp.flipMode = FilpLeft;
			  break;
       }
	   //printf("AdjustSys Value = %d",g_sysSetting.Disp.flipMode);
    }
	return 1;
}


BOOL ExectSys(void)
{
   ConfigPannelSfrDisp();
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_Sys[]=
{
    {1,2,RED,TRANSPARENCE,RED,TRANSPARENCE, GetSysVal,DispSysStr,osdEnd},
};


ItemValueType CODE SysMenuItemVal_Sys[]=
{
     {
	      NULL,
	      NULL,
	      Option_Sys,   
	      osdEnd,
     },
};



/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE SysMenuItem_SysTitelTab[]=
{
   {0,6,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,SysMenu_TitelStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/

