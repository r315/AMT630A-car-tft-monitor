#define _OSD_FACTORY_MENU_C_


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
#include "Osd_LogoStr.h"


#ifdef FactoryEn
SWORD FactoryMenuSwitchItem_GetVolumeVal(void);
SWORD FactoryMenuSwitchItem_GetScalerVal(void);
SWORD FactoryMenuSwitchItem_GetFlipVal(void);
SWORD FactoryMenuSwitchItem_GetResetVal(void);
SWORD FactoryMenuSwitchItem_GetIRABVal(void);
SWORD FactoryMenuSwitchItem_GetRadioFreqVal(void);
SWORD FactoryMenuSwitchItem_GetPowerVal(void);
SWORD FactoryMenuSwitchItem_GetLogoIdVal(void);


/*****************************************************************
                            Text
*****************************************************************/

UCHAR* CODE FactoryMenuVerStr[]=
{
    " VER1.4: "__DATE__" " __TIME__" ",
};


UCHAR* CODE FactoryMenu_PicStr[]=
{
    "PIC ",
};


UCHAR* CODE FactoryMenu_SwitchStr[]=
{
    "SWITCH",
};

UCHAR* CODE Pic_VcomDcStr[]=
{
    "VCOMDC                    ",
};

UCHAR* CODE Pic_BrightnessStr[]=
{
    "BRIGHTNESS                  ",  
};


UCHAR* CODE Pic_ContrastStr[]=
{
    "CONTRAST                    ",  
};


UCHAR* CODE Pic_SaturationStr[]=
{
    "SATURATION                  ",  
};


UCHAR* CODE Pic_OsdPosXOffsetStr[]=
{
    "OSDPOSXOFFSET              ",  
};


UCHAR* CODE Pic_OsdPosYOffsetStr[]=
{
    "OSDPOSYOFFSET              ",  
};


UCHAR* CODE Switch_VolumeStr[]=
{
    "VOLUME                     ",
};


UCHAR* CODE Switch_ScalerStr[]=
{
    "SCALER                     ",
};


UCHAR* CODE Switch_FlipStr[]=
{
    "FLIP                     ",
};


UCHAR* CODE Switch_ResetStr[]=
{
    "RESET                      ",
};


UCHAR* CODE Switch_IRABStr[]=
{
    "IRAB                       ",
};


UCHAR* CODE Switch_RadioFreqStr[]=
{
    "RADIOFREQ                   ",
};


UCHAR* CODE Switch_PowerStr[]=
{
    "POWER                      ",
};


UCHAR* CODE Switch_LogoIdStr[]=
{
    "LOGOID                     ",
};


UCHAR* CODE Switch_SelectStr[]=
{
    " OFF",
	"  ON",
	"SAVE"
};

UCHAR* CODE OX_Str[]=
{
    "0X",  
};

UCHAR* CODE BLANK_Str[]=
{
    "                               ",
};


/*****************************************************************
                            String
*****************************************************************/
UCHAR * CODE FactoryMenu_VerStr(void)
{
    return FactoryMenuVerStr[0];
}

UCHAR * CODE FactoryMenu_PicTitelStr(void)
{
    return FactoryMenu_PicStr[0];
}

UCHAR * CODE FactoryMenu_SwitchTitelStr(void)
{
    return FactoryMenu_SwitchStr[0];
}

UCHAR * CODE FactoryMenu_PicItem_VcomDcTitel(void)
{
    return Pic_VcomDcStr[0];
}

UCHAR * CODE FactoryMenu_PicItem_BrightnessTitel(void)
{
    return Pic_BrightnessStr[0];
}

UCHAR * CODE FactoryMenu_PicItem_ContrastTitel(void)
{
    return Pic_ContrastStr[0];
}

UCHAR * CODE FactoryMenu_PicItem_SaturationTitel(void)
{
    return Pic_SaturationStr[0];
}


UCHAR * CODE FactoryMenu_PicItem_OsdPosXOffsetTitel(void)
{
    return Pic_OsdPosXOffsetStr[0];
}


UCHAR * CODE FactoryMenu_PicItem_OsdPosYOffsetTitel(void)
{
    return Pic_OsdPosYOffsetStr[0];
}


UCHAR * CODE FactoryMenu_SwitchItem_VolumeStr(void)
{
    return Switch_VolumeStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_ScalerStr(void)
{
    return Switch_ScalerStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_FlipStr(void)
{
    return Switch_FlipStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_ResetStr(void)
{
    return Switch_ResetStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_IRABStr(void)
{
    return Switch_IRABStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_RadioFreqStr(void)
{
    return Switch_RadioFreqStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_PowerStr(void)
{
    return Switch_PowerStr[0];
}


UCHAR * CODE FactoryMenu_SwitchItem_LogoIDStr(void)
{
    return Switch_LogoIdStr[0];
}

UCHAR * CODE FactoryMenu_SwitchItem_VolumeSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetVolumeVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_ScalerSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetScalerVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_FlipSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetFlipVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_ResetSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetResetVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_IRABSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetIRABVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_RadioFreqSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetRadioFreqVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_PowerSwitchStr(void)
{
     return Switch_SelectStr[FactoryMenuSwitchItem_GetPowerVal()];
}

UCHAR * CODE FactoryMenu_SwitchItem_LogoIdSwitchStr(void)
{
     return Switch_SelectLogoIdStr[FactoryMenuSwitchItem_GetLogoIdVal()];
}

UCHAR * CODE FactoryMenu_OXStr(void)
{
    return OX_Str[0];
}

UCHAR * CODE FactoryMenu_BlankStr(void)
{
    return BLANK_Str[0];
}

/*****************************************************************
                           Function
*****************************************************************/
AdjustType FactoryMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
	
    //printfStr("FactoryMenu_CheckCondition");
	adjust.Flags |= osdVisible;
	return adjust;
}


SWORD FactoryMenuPicItem_GetVcomDcVal(void)
{
     //printfStr("FactoryMenuPicItem_GetVcomDcVal");
     return g_sysSetting.Video.vcomDC;
}

SWORD FactoryMenuPicItem_GetBrightnessVal(void)
{
     //printfStr("FactoryMenuPicItem_GetBrightnessVal");
     return g_sysSetting.Video.brightnessOffset;
}

SWORD FactoryMenuPicItem_GetContrastVal(void)
{
     //printfStr("FactoryMenuPicItem_GetContrastVal");
     return g_sysSetting.Video.contrastOffset;
}


SWORD FactoryMenuPicItem_GetSaturationVal(void)
{
     //printfStr("FactoryMenuPicItem_GetSaturationVal");
     return g_sysSetting.Video.saturationOffset;
}

SWORD FactoryMenuPicItem_GetOsdXOffsetVal(void)
{
     //printfStr("FactoryMenuPicItem_GetOsdXOffsetVal");
     return g_sysSetting.Osd.xOffset;
}


SWORD FactoryMenuPicItem_GetOsdYOffsetVal(void)
{
     //printfStr("FactoryMenuPicItem_GetOsdYOffsetVal");
     return g_sysSetting.Osd.yOffset;
}

SWORD FactoryMenuSwitchItem_GetVolumeVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetVolumeVal");
     return g_sysSetting.Factory.volumeswitch;
}


SWORD FactoryMenuSwitchItem_GetScalerVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetScalerVal");
     return g_sysSetting.Factory.scalerswitch;
}


SWORD FactoryMenuSwitchItem_GetFlipVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetHorizontalVal");
     return g_sysSetting.Factory.flipswitch; 
}


SWORD FactoryMenuSwitchItem_GetResetVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetResetVal");
     return g_sysSetting.Factory.resetswitch; 
}


SWORD FactoryMenuSwitchItem_GetIRABVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetIRABVal");
     return g_sysSetting.Factory.irabswitch; 
}


SWORD FactoryMenuSwitchItem_GetRadioFreqVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetRadioFreqVal");
     return g_sysSetting.Factory.radiofreqswitch; 
}

SWORD FactoryMenuSwitchItem_GetPowerVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetPowerVal");
     return g_sysSetting.Factory.powerswitch;
}


SWORD FactoryMenuSwitchItem_GetLogoIdVal(void)
{
     //printfStr("FactoryMenuSwitchItem_GetLogoIdVal");
     return g_sysSetting.Logo.logoID;
}



/*****************************************************************
                          Item value table
*****************************************************************/
DrawNumberType CODE Number_FactoryMenuPicItem_VcomDcVal[]=
{
    {2,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetVcomDcVal,osdHexNum|osdEnd},
};

DrawOptionType CODE Option_FactoryMenuPicItem_VcomDc[]=
{
    {2,25,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_OXStr,osdEnd},
};

DrawNumberType CODE Number_FactoryMenuPicItem_BrightnessVal[]=
{
    {3,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetBrightnessVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryMenuPicItem_ContrastVal[]=
{
    {4,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetContrastVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryMenuPicItem_SaturationVal[]=
{
    {5,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetSaturationVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryMenuPicItem_OsdPosXOffsetVal[]=
{
    {6,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetOsdXOffsetVal,osdDecNum|osdEnd},
};

DrawNumberType CODE Number_FactoryMenuPicItem_OsdPosYOffsetVal[]=
{
    {7,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, FactoryMenuPicItem_GetOsdYOffsetVal,osdDecNum|osdEnd},
};



ItemValueType CODE FactoryMenuPicItem_Val[]=
{
     {
	      Number_FactoryMenuPicItem_VcomDcVal,
	      NULL,
	      Option_FactoryMenuPicItem_VcomDc,   
	      0,
     },
     
	{
	      Number_FactoryMenuPicItem_BrightnessVal,
	      NULL,
	      NULL,   
	      0,
     },

	{
	      Number_FactoryMenuPicItem_ContrastVal,
	      NULL,
	      NULL,   
	      0,
     },

	 {
	      Number_FactoryMenuPicItem_SaturationVal,
	      NULL,
	      NULL,   
	      0,
     },

	{
	      Number_FactoryMenuPicItem_OsdPosXOffsetVal,
	      NULL,
	      NULL,   
	      0,
     },
     
	{
	      Number_FactoryMenuPicItem_OsdPosYOffsetVal,
	      NULL,
	      NULL,   
	      osdEnd,
     },
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_Volume[]=
{
    {2,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_VolumeSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_Scaler[]=
{
    {3,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_ScalerSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_Flip[]=
{
    {4,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_FlipSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_Reset[]=
{
    {5,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_ResetSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_IRAB[]=
{
    {6,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_IRABSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_RadioFreq[]=
{
    {7,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_RadioFreqSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_Power[]=
{
    {8,27,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_PowerSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FactoryMenuSwitchItem_LogoID[]=
{
    {9,23,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE, NULL,FactoryMenu_SwitchItem_LogoIdSwitchStr,osdEnd},
};

ItemValueType CODE FactoryMenuSwitchItem_Val[]=
{
     {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_Volume,   
	      0,
     },
     
    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_Scaler,   
	      0,
    },
    
    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_Flip,   
	      0,
    }, 

    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_Reset,   
	      0,
    },

    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_IRAB,   
	      0,
    },

    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_RadioFreq,   
	      0,
    },
    
    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_Power,   
	      0,
    },

    {
	      NULL,
	      NULL,
	      Option_FactoryMenuSwitchItem_LogoID,   
	      osdEnd,
    },
};


/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE FactoryMenuItem_PicTab[]=
{  
   {1,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryMenu_PicTitelStr,0},
   {2,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_VcomDcTitel,0},
   {3,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_BrightnessTitel,0},
   {4,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_ContrastTitel,0},
   {5,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_SaturationTitel,0},
   {6,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_OsdPosXOffsetTitel,0},
   {7,0,GREEN,TRANSPARENCE,GREEN,TRANSPARENCE,DWT_Text,FactoryMenu_PicItem_OsdPosYOffsetTitel,0},
   {8,0,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,DWT_Text,FactoryMenu_BlankStr,0},
   {9,0,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,DWT_Text,FactoryMenu_BlankStr,0},
   {10,0,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,DWT_Text,FactoryMenu_BlankStr,osdEnd},

};

TitelType CODE FactoryMenuItem_SwitchTab[]=
{   
   {1,4,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactoryMenu_SwitchTitelStr,0},
   {2,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_VolumeStr,0},
   {3,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_ScalerStr,0},
   {4,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_FlipStr,0},
   {5,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_ResetStr,0},
   {6,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_IRABStr,0},
   {7,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_RadioFreqStr,0},
   {8,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_PowerStr,0},
   {9,0,GREEN,TRANSPARENCE,GREEN, TRANSPARENCE,DWT_Text,FactoryMenu_SwitchItem_LogoIDStr,0},
   {10,0,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,DWT_Text,FactoryMenu_BlankStr,osdEnd},
};


/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/
TitelType CODE FactoryMenu_TitelTab[]=
{   
   {0,0,RED,TRANSPARENCE,TRANSPARENCE,TRANSPARENCE,DWT_Text,FactoryMenu_VerStr,osdEnd},
};
#endif

