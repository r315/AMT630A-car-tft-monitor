#define _OSD_FACTORYPIC_MENU_C_



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


#ifdef FactoryEn

/*****************************************************************
                            Text
*****************************************************************/
UCHAR* CODE FactoryPicMenu_VcomDcStr[]=
{
    "VCOMDC                   ",
};

UCHAR* CODE FactoryPicMenu_BrightnessStr[]=
{
    "BRIGHTNESS               ",  
};

UCHAR* CODE FactoryPicMenu_ContrastStr[]=
{
    "CONTRAST                ",  
};


UCHAR* CODE FactoryPicMenu_SaturationStr[]=
{
    "SATURATION              ",  
};


UCHAR* CODE FactoryPicMenu_OsdPosXOffsetStr[]=
{
    "OSDPOSXOFFSET              ",  
};


UCHAR* CODE FactoryPicMenu_OsdPosYOffsetStr[]=
{
    "OSDPOSYOFFSET              ",  
};

UCHAR* CODE FactoryPicMenu_0XStr[]=
{
    "0X",  
};

/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE FactoryPicMenu_VcomDcTitel(void)
{
    return FactoryPicMenu_VcomDcStr[0];
}

UCHAR * CODE FactoryPicMenu_BrightnessTitel(void)
{
    return FactoryPicMenu_BrightnessStr[0];
}

UCHAR * CODE FactoryPicMenu_ContrastTitel(void)
{
    return FactoryPicMenu_ContrastStr[0];
}

UCHAR * CODE FactoryPicMenu_SaturationTitel(void)
{
    return FactoryPicMenu_SaturationStr[0];
}

UCHAR * CODE FactoryPicMenu_OsdPosXOffsetTitel(void)
{
    return FactoryPicMenu_OsdPosXOffsetStr[0];
}


UCHAR * CODE FactoryPicMenu_OsdPosYOffsetTitel(void)
{
    return FactoryPicMenu_OsdPosYOffsetStr[0];
}

UCHAR * CODE FactoryPicMenu_0XTitel(void)
{
    return FactoryPicMenu_0XStr[0];
}

/*****************************************************************
                           Function
*****************************************************************/
AdjustType FactoryPicMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
    printfStr("FactoryPicMenu_CheckCondition");
	adjust.Flags |= osdVisible;
	return adjust;
}


BOOL AdjustVideoVcomDc(UCHAR opratComd)
{
  	 if(opratComd == COMD_IncValue)
     {
	  	  if(g_sysSetting.Video.vcomDC<100) 
	  	  {
	  	      g_sysSetting.Video.vcomDC++;
	  	  } 
     }
     if(opratComd == COMD_DecValue)
     {
	  	  if(g_sysSetting.Video.vcomDC>0) 
	  	  {
	  	      g_sysSetting.Video.vcomDC--;
	  	  } 
     }
	 return 1;
}


BOOL AdjustVideoBrightness(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		if(g_sysSetting.Video.brightnessOffset < (MAX_VALUE/2+0X14))
		{
		   g_sysSetting.Video.brightnessOffset++;
		}
    }
	if(opratComd == COMD_DecValue)
	{
	    if(g_sysSetting.Video.brightnessOffset > (MAX_VALUE/2-0X14))
		{
		   g_sysSetting.Video.brightnessOffset--;
		}
	}
	return 1;
}


BOOL AdjustVideoContrast(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		if(g_sysSetting.Video.contrastOffset < (MAX_VALUE/2+0X14))
		{
		   g_sysSetting.Video.contrastOffset++;
		}
    }
	if(opratComd == COMD_DecValue)
	{
	    if(g_sysSetting.Video.contrastOffset > (MAX_VALUE/2-0X14))
		{
		   g_sysSetting.Video.contrastOffset--;
		}
	}
	return 1;
}


BOOL AdjustVideoSaturation(UCHAR opratComd)
{

    if(opratComd == COMD_IncValue)
    {
		if(g_sysSetting.Video.saturationOffset < (MAX_VALUE/2+0X14))
		{
		   g_sysSetting.Video.saturationOffset++;
		}
    }
	if(opratComd == COMD_DecValue)
	{
		if(g_sysSetting.Video.saturationOffset > (MAX_VALUE/2-0X14))
		{
		   g_sysSetting.Video.saturationOffset--;
		}
    }
	return 1;
}


BOOL AdjustVideoOsdXOffSet(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		if(g_sysSetting.Osd.xOffset < MAX_OFFSETVALUE)
		{
		   g_sysSetting.Osd.xOffset++;
		}
    }
	if(opratComd == COMD_DecValue)
	{
	    if(g_sysSetting.Osd.xOffset > -MAX_OFFSETVALUE)
		{
		   g_sysSetting.Osd.xOffset--;
		}
	}
	return 1;
}


BOOL AdjustVideoOsdYOffSet(UCHAR opratComd)
{
    if(opratComd == COMD_IncValue)
    {
		if(g_sysSetting.Osd.yOffset < MAX_OFFSETVALUE)
		{
		   g_sysSetting.Osd.yOffset++;
		}
    }
	if(opratComd == COMD_DecValue)
	{
	    if(g_sysSetting.Osd.yOffset > -MAX_OFFSETVALUE)
		{
		   g_sysSetting.Osd.yOffset--;
		}
	}
	return 1;
}


BOOL ExectVideoVcomDc(void)
{
   //printfStr("ExectVideoVcomDc");
    switch(VCOMDC_TYPE)
	{
	   case PWM0:
	   	    SetPWM0(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;
			
	   case PWM1:
            SetPWM1(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;

	   case PWM2:
            SetPWM2(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;

	   case PWM3:
            SetPWM3(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;
			
	  default:
			break;
	}
   return 1;
}


BOOL ExectVideoBrightness(void)
{
   //printfStr("ExectVideoBrightness");
   return 1;
}


BOOL ExectVideoContrast(void)
{
   //printfStr("ExectVideoContrast");
   return 1;
}


BOOL ExectVideoSaturation(void)
{
   //printfStr("ExectVideoSaturation");
   return 1;
}


BOOL ExectVideoOsdXOffSet(void)
{
   //printfStr("ExectVideoOsdXOffSet");
   return 1;
}


BOOL ExectVideoOsdYOffSet(void)
{
   //printfStr("ExectVideoOsdYOffSet");
   return 1;
}


SWORD FactoryPicMenu_GetVcomDcVal(void)
{
     //printfStr("FactoryPicMenu_GetVcomDcVal");
     return g_sysSetting.Video.vcomDC;
}


SWORD FactoryPicMenu_GetBrightnessVal(void)
{
     //printfStr("FactoryPicMenu_GetBrightnessVal");
     return g_sysSetting.Video.brightnessOffset;
}


SWORD FactoryPicMenu_GetContrastVal(void)
{
     //printfStr("FactoryPicMenu_GetContrastVal");
     return g_sysSetting.Video.contrastOffset;
}


SWORD FactoryPicMenu_GetSaturationVal(void)
{
     //printfStr("FactoryPicMenu_GetSaturationVal");
     return g_sysSetting.Video.saturationOffset;
}


SWORD FactoryPicMenu_GetOsdPosXOffsetVal(void)
{
     //printfStr("FactoryPicMenu_GetOsdPosXOffsetVal");
     return g_sysSetting.Osd.xOffset;
}


SWORD FactoryPicMenu_GetOsdPosYOffsetVal(void)
{
     //printfStr("FactoryPicMenu_GetOsdPosYOffsetVal");
     return g_sysSetting.Osd.yOffset;
}

/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_FactoryPicMenu_VcomDcVal[]=
{
    {2,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetVcomDcVal,osdHexNum|osdEnd},
};

DrawOptionType CODE Option_FactoryPicMenu_VcomDc[]=
{
    {2,25,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactoryPicMenu_0XTitel,osdEnd},
};

DrawNumberType CODE Number_FactoryPicMenu_BrightnessVal[]=
{
    {3,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetBrightnessVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryPicMenu_ContrastVal[]=
{
    {4,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetContrastVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryPicMenu_SaturationVal[]=
{
    {5,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetSaturationVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryPicMenu_OsdPosXOffsetVal[]=
{
    {6,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetOsdPosXOffsetVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryPicMenu_OsdPosYOffsetVal[]=
{
    {7,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, FactoryPicMenu_GetOsdPosYOffsetVal,osdDecNum|osdEnd},
};


ItemValueType CODE FactoryPicMenu_VcomDcVal[]=
{
     {
	      Number_FactoryPicMenu_VcomDcVal,
	      NULL,
	      Option_FactoryPicMenu_VcomDc,   
	      osdEnd,
     },
};

ItemValueType CODE FactoryPicMenu_BrightnessVal[]=
{
     {
	      Number_FactoryPicMenu_BrightnessVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};

ItemValueType CODE FactoryPicMenu_ContrastVal[]=
{
     {
	      Number_FactoryPicMenu_ContrastVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};


ItemValueType CODE FactoryPicMenu_SaturationVal[]=
{
     {
	      Number_FactoryPicMenu_SaturationVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};


ItemValueType CODE FactoryPicMenu_OsdPosXOffsetVal[]=
{
     {
	      Number_FactoryPicMenu_OsdPosXOffsetVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};


ItemValueType CODE FactoryPicMenu_OsdPosYOffsetVal[]=
{
     {
	      Number_FactoryPicMenu_OsdPosYOffsetVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};

/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE FactoryPicMenuItem_VcomDcTitelTab[]=
{   
   {2,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_VcomDcTitel,osdEnd},
};

TitelType CODE FactoryPicMenuItem_BrightnessTitelTab[]=
{
   {3,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_BrightnessTitel,osdEnd},
};

TitelType CODE FactoryPicMenuItem_ContrastTitelTab[]=
{   
   {4,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_ContrastTitel,osdEnd},
};

TitelType CODE FactoryPicMenuItem_SaturationTitelTab[]=
{
   {5,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_SaturationTitel,osdEnd},
};


TitelType CODE FactoryPicMenuItem_OsdPosXOffsetTab[]=
{
   {6,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_OsdPosXOffsetTitel,osdEnd},
};


TitelType CODE FactoryPicMenuItem_OsdPosYOffsetTab[]=
{
   {7,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryPicMenu_OsdPosYOffsetTitel,osdEnd},
};
/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
#endif

