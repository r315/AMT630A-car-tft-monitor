#define _OSD_LANGUAGE_MENU_C_



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



SWORD GetLanguageVal(void);



/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE LanguageMenuStr[]=
{
   "LANGUAGE",
   "LANGUE",
   "LANGUA",
   "IDIOMA",
   "SPRACHE",
   "IDIOMA",
   "TAAL",
   "\x01F\x00D\x01C\x010",
   "#\x00E#\x00F", 
   "#\x00F#\x085", 
   "\x00C\x00D\x00E\x010",
   "J\x006Z\x015\x010",
   "DIL"
};


UCHAR* CODE LanguageStr[]=
{
  "ENGLISH",
  "FRANCAIS",
  "ITALIANO",
  "ESPA\x085OL",
  "DEUTSCH",
  "PORTUGU\x073SE",
  "ENGELS",
  "\x024\x015\x025\x025\x010\x00E\x00F",
  "#\x059#\x043#\x05A#\x05B", 
  "#\x083#\x084#\x085",    
  "\x008\x029\x011\x00A\x007\x025\x0B8\x010\x013",
  "POLSKI",
  "T\x0A8RK"
};




/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE LanguageMenu_TitelStr(void)
{
    return LanguageMenuStr[GetLanguageVal()];
}


UCHAR * CODE DispLanguageStr(void)
{     
      return LanguageStr[GetLanguageVal()];  
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType LanguageMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
	adjust.Flags |= osdVisible;
	//printfStr("LanguageMenu_CheckCondition");
	return adjust;
}





BOOL LanguageMenuItem_DrawStyle(void)
{
    //printfStr("LanguageMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}


SWORD GetLanguageVal(void)
{
     //printfStr("GetLanguageVal");
     return g_sysSetting.Osd.curlanguage;
}


BOOL AdjustLanguage(UCHAR opratComd)
{
	if(opratComd == COMD_IncValue)
    {     
		  if(g_sysSetting.Osd.curlanguage <MAX_LANG)
		  {
		      g_sysSetting.Osd.curlanguage++;
		  } 
		  else
		  {
		  	 g_sysSetting.Osd.curlanguage = MIN_LAG;
		  }
		  //printf("curlanguage Inc Value ++ = %d", g_sysSetting.Osd.curlanguage);
    }
	if(opratComd == COMD_DecValue)
	{
		  if(g_sysSetting.Osd.curlanguage>MIN_LAG)
		  {
		      g_sysSetting.Osd.curlanguage--;
		  } 
		  else
		  {
		  	 g_sysSetting.Osd.curlanguage = MAX_LANG;
		  }
		 //printf("curlanguage Dec Value -- =%d",g_sysSetting.Osd.curlanguage);		  
	}
	return 1;
}


BOOL ExectLanguage(void)
{
   //printfStr("ExectLanguage");
   OsdWndClear(0X00, 0X00, 0X00, 0X11);
   OsdWndClear(0X01, 0X00, 0X01, 0X11);
   DrawOsdTitel(CurrentMenuItem.ItemTitels,osdDraw);
   return 1;
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
TitelType CODE LanguageMenuItem_LanguageTitelTab[]=
{
	{0,5,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,LanguageMenu_TitelStr,0},
    {1,5,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,DispLanguageStr,osdEnd},
};

/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
