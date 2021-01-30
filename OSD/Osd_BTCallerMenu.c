#define _OSD_BTCALLER_MENU_C_



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




/*****************************************************************
                            String
*****************************************************************/

UCHAR * CODE BTCallerMenu_TitelStr(void)
{
    return g_ucCallerIDBuf;
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType BTCallerMenu_CheckCondition (void)
{
	AdjustType XDATA adjust = {0,0,0};
	adjust.Flags |= osdVisible;
	
	//printfStr("BTCallerMenu_CheckCondition");
	return adjust;
}


void SwitchAsciiBuf(UCHAR AsciiBuflen,UCHAR *pAsciiBufData)
{
   UCHAR CODE DatBuf[] = {'0','1','2','3','4','5','6','7','8','9'};
   UCHAR XDATA i;

   for(i= 0;i<AsciiBuflen;i++)
   {   
       if((*(pAsciiBufData+i) >= 0x30)&&(*(pAsciiBufData+i) <= 0x39))
       {
          g_ucCallerIDBuf[i] = DatBuf[*(pAsciiBufData+i)-0x30];
       }
	   else
	   {
	     g_ucCallerIDBuf[i]=' ';
	   }
	   //printf("g_ucCallerIDBuf[i] is %x",g_ucCallerIDBuf[i]);
   }
   g_ucCallerIDBuf[i]='\0';
}


BOOL BTCallerMenuItem_DrawStyle(void)
{
	//printfStr("BTCallerMenuItem_DrawStyle");
	SwitchAsciiBuf(g_ucCallerIDLen,g_ucCallerIDAsciiBuf);
	return 0;
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
TitelType CODE BTCallerMenuItem_BTCallerTitelTab[]=
{
   {0,0,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,BTCallerMenu_TitelStr,osdEnd},
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

