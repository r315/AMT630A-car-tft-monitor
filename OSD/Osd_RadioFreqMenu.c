#define _OSD_RADIOFREQ_MENU_C_



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
#include "Kt0803l.h"


SWORD GetRadioFreqVal(void);

/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE RadioFreqMenuStr[]=
{
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
    "FM",
};


UCHAR* CODE RadioFreqStr[]=
{
  "  OFF  ",
  "87.7MHZ",
  "87.9MHZ",
  "88.1MHZ",
  "88.3MHZ",
  "88.5MHZ",
  "88.7MHZ",
  "88.9MHZ",
  "89.1MHZ"
};




/*****************************************************************
                            String
*****************************************************************/
UCHAR * RadioFreqMenu_TitelStr(void)
{
    return RadioFreqMenuStr[g_sysSetting.Osd.curlanguage];
}


UCHAR * CODE DispRadioFreqStr(void)
{
      return RadioFreqStr[GetRadioFreqVal()];  
}



/*****************************************************************
                           Function
*****************************************************************/
AdjustType RadioFreqMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};

	if(ON == g_sysSetting.Factory.radiofreqswitch)
	{
	    adjust.Flags |= osdVisible; 
		//printfStr("RadioFreq Visibla");
	}
	else
	{
	    adjust.Flags |= osdInvisible; 
		//printfStr("RadioFreq Invisible");
	}
	
	//printfStr("RadioFreqMenu_CheckCondition");
	return adjust;
}



SWORD GetRadioFreqVal(void)
{
     //printfStr("GetRadioFreqVal");
     return g_sysSetting.RadioFreq.RadioFreqVal;
}





BOOL RadioFreqMenuItem_DrawStyle(void)
{
    //printfStr("RadioFreqMenuItem_DrawStyle");
	OsdWndClear(0X00, 0X00, 0X00, 0X11);
	OsdWndClear(0X01, 0X00, 0X01, 0X11);
    return 0;
}


BOOL AdjustRadioFreq(UCHAR opratComd)
{    

	if(opratComd == COMD_IncValue)
    {
		  if(g_sysSetting.RadioFreq.RadioFreqVal<MHZ_891)
		  {
		      g_sysSetting.RadioFreq.RadioFreqVal++;
		  } 
          else	 
	      {
		     g_sysSetting.RadioFreq.RadioFreqVal = RFOFF;
		  }
    }
	if(opratComd == COMD_DecValue)
	{
	    
		  if(g_sysSetting.RadioFreq.RadioFreqVal>RFOFF)
		  {
		      g_sysSetting.RadioFreq.RadioFreqVal--;
		  } 
		  else
		  {
		    g_sysSetting.RadioFreq.RadioFreqVal = MHZ_891;
		  }
	}
	//printf("the AdjustRF Val is %x",g_sysSetting.RadioFreq.SendRfVal);
	return 1;
}


BOOL ExectRadioFreq(void)
{
   //printfStr("ExectRadioFreq");
   
   #ifdef FmSendEn
   #if(FM_CHIP == KT0803l)
   switch(g_sysSetting.RadioFreq.RadioFreqVal)
	{
	   case MHZ_877:
	        KT_TXTune(8770);
			break;
			
	   case MHZ_879:
	        KT_TXTune(8790);
			break;
			
       case MHZ_881:
	        KT_TXTune(8810);
			break;

	   case MHZ_883:
	        KT_TXTune(8830);
			break;

	   case MHZ_885:
	        KT_TXTune(8850);
			break;

	   case MHZ_887:
	        KT_TXTune(8870);
			break;
			
	   case MHZ_889:
	        KT_TXTune(8890);
			break;

	   case MHZ_891:
	        KT_TXTune(8910); 
			break;
			
	  default:
	        KT_TXTune(8660);
			break;
	}
	#endif
	#endif
	
   return 1;
}


/*****************************************************************
                          Item value table
*****************************************************************/
DrawOptionType CODE Option_RadioFreq[]=
{
    {1,5,RED,TRANSPARENCE,RED,TRANSPARENCE, GetRadioFreqVal,DispRadioFreqStr,osdEnd},
};
ItemValueType CODE RadioFreqMenuItemVal_RadioFreq[]=
{
     {
	      NULL,
	      NULL,
	      Option_RadioFreq,   
	      osdEnd,
     },
};


/*****************************************************************
                          Item Icon table
*****************************************************************/




/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE RadioFreqMenuItem_RadioFreqTitelTab[]=
{
   {0,7,RED,TRANSPARENCE,RED,TRANSPARENCE,DWT_Text,RadioFreqMenu_TitelStr,osdEnd},
};



/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/


