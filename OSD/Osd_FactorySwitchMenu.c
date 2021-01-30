#define _OSD_FACTORYSWITCH_MENU_C_



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
#include "Osd_LogoName.h"
#include "Osd_LogoFontDat.h"


#ifdef FactoryEn

SWORD GetVolumeSwitchVal(void);
SWORD GetScalerSwitchVal(void);
SWORD GetFlipSwitchVal(void);
SWORD GetResetSwitchVal(void);
SWORD GetIRABSwitchVal(void);
SWORD GetRadioFreqSwitchVal(void);
SWORD GetPowerSwitchVal(void);
SWORD GetLogoIdSwitchVal(void);


/*****************************************************************
                            Text
*****************************************************************/

UCHAR* CODE FactorySwitchMenu_VolumeStr[]=
{
    "VOLUME                    ",
};


UCHAR* CODE FactorySwitchMenu_ScalerStr[]=
{
    "SCALER                     ",
};

UCHAR* CODE FactorySwitchMenu_FlipStr[]=
{
    "FLIP                       ",
};


UCHAR* CODE FactorySwitchMenu_ResetStr[]=
{
    "RESET                      ",
};


UCHAR* CODE FactorySwitchMenu_IRABStr[]=
{
    "IRAB                       ",
};


UCHAR* CODE FactorySwitchMenu_RadioFreqStr[]=
{
    "RADIOFREQ                   ",
};


UCHAR* CODE FactorySwitchMenu_PowerStr[]=
{
    "POWER                      ",
};


UCHAR* CODE FactorySwitchMenu_LogoIdStr[]=
{
    "LOGOID                     ",
};


UCHAR* CODE FactorySwitchMenu_SwitchStr[]=
{
    " OFF",
	"  ON",
	"SAVE"
};


/*****************************************************************
                            String
*****************************************************************/

UCHAR * CODE FactorySwitchMenu_VolumeTitel(void)
{
    return FactorySwitchMenu_VolumeStr[0];
}

UCHAR * CODE FactorySwitchMenu_ScalerTitel(void)
{
    return FactorySwitchMenu_ScalerStr[0];
}

UCHAR * CODE FactorySwitchMenu_FlipTitel(void)
{
    return FactorySwitchMenu_FlipStr[0];
}

UCHAR * CODE FactorySwitchMenu_ResetTitel(void)
{
    return FactorySwitchMenu_ResetStr[0];
}

UCHAR * CODE FactorySwitchMenu_IRABTitel(void)
{
    return FactorySwitchMenu_IRABStr[0];
}

UCHAR * CODE FactorySwitchMenu_RadioFreqTitel(void)
{
    return FactorySwitchMenu_RadioFreqStr[0];
}

UCHAR * CODE FactorySwitchMenu_PowerTitel(void)
{
    return FactorySwitchMenu_PowerStr[0];
}

UCHAR * CODE FactorySwitchMenu_LogoIdTitel(void)
{
    return FactorySwitchMenu_LogoIdStr[0];
}

UCHAR * CODE FactorySwitchMenu_VolumeSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetVolumeSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_ScalerSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetScalerSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_FlipSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetFlipSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_ResetSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetResetSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_IRABSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetIRABSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_RadioFreqSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetRadioFreqSwitchVal()];
}

UCHAR * CODE FactorySwitchMenu_PowerSwitchStr(void)
{
     return FactorySwitchMenu_SwitchStr[GetPowerSwitchVal()];
}


UCHAR * CODE FactorySwitchMenu_LogoIdSwitchStr(void)
{
     return FactorySwitchMenu_SwitchLogoIdStr[GetLogoIdSwitchVal()];
}

/*****************************************************************
                           Function
*****************************************************************/
AdjustType FactorySwitchMenu_CheckCondition(void)
{
	AdjustType XDATA adjust = {0,0,0};
    printfStr("FactorySwitchMenu_CheckCondition");
	adjust.Flags |= osdVisible;
	return adjust;
}


BOOL AdjustVideoVolumeSwitch(UCHAR opratComd)
{
	if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.volumeswitch == ON)?(g_sysSetting.Factory.volumeswitch  = OFF):(g_sysSetting.Factory.volumeswitch  = ON);
	   //printf("AdjustVolumeSwitch Value = %d",g_sysSetting.Factory.volumeswitch );
    }
	return 1;
}


BOOL AdjustVideoScalerSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.scalerswitch == ON)?(g_sysSetting.Factory.scalerswitch = OFF):(g_sysSetting.Factory.scalerswitch = ON);
	   //printf("AdjustScalerSwitch Value = %d",g_sysSetting.Factory.scalerswitch);
    }
	return 1;
}


BOOL AdjustVideoFlipSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.flipswitch == ON)?(g_sysSetting.Factory.flipswitch = OFF):(g_sysSetting.Factory.flipswitch = ON);
	   //printf("AdjustVideoFlipSwitch Value = %d",g_sysSetting.Factory.flipswitch);
    }
	return 1;
}


BOOL AdjustVideoResetSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.resetswitch == ON)?(g_sysSetting.Factory.resetswitch = OFF):(g_sysSetting.Factory.resetswitch = ON);
	   //printf("AdjustResetswitch Value = %d",g_sysSetting.Factory.resetswitch);
    }
	return 1;
}


BOOL AdjustVideoIRABSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.irabswitch == ON)?(g_sysSetting.Factory.irabswitch = OFF):(g_sysSetting.Factory.irabswitch = ON);
	   //printf("Adjustirabswitch Value = %d",g_sysSetting.Factory.irabswitch);
    }
	return 1;
}


BOOL AdjustVideoRadioFreqSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {     
       (g_sysSetting.Factory.radiofreqswitch == ON)?(g_sysSetting.Factory.radiofreqswitch = OFF):(g_sysSetting.Factory.radiofreqswitch = ON);
	   //printf("Adjustradiofreqswitch Value = %d",g_sysSetting.Factory.radiofreqswitch);
    }
	return 1;
}


BOOL AdjustSystemPowerSwitch(UCHAR opratComd)
{
    if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
    {   
       switch(g_sysSetting.Factory.powerswitch)
       {
		    case OFF:
				 g_sysSetting.Factory.powerswitch = ON;
			     break;
			
			case ON:
				 g_sysSetting.Factory.powerswitch = SAVE;
			     break;
			
			case SAVE:
				 g_sysSetting.Factory.powerswitch = OFF;
			     break;
				 
			default:
				g_sysSetting.Factory.powerswitch = ON;
				break;
       }	   
	  //printf("AdjustPowerSwitch Value = %d",g_sysSetting.Factory.powerswitch);
    }
	return 1;
}


BOOL AdjustSystemLogoIdSwitch(UCHAR opratComd)
{
     if((opratComd == COMD_IncValue) ||(opratComd == COMD_DecValue))
     {
            switch(g_sysSetting.Logo.logoID)
			{
				case LOGO1:
				     g_sysSetting.Logo.logoID = LOGO2;
				     break;

				case LOGO2:
				     g_sysSetting.Logo.logoID = LOGO3;
				     break;
					 
				case LOGO3:
				     g_sysSetting.Logo.logoID = LOGO4;
				     break;
					 
				case LOGO4:
				     g_sysSetting.Logo.logoID = LOGO5;
				     break;
					 
				case LOGO5:
				     g_sysSetting.Logo.logoID = LOGO1;
				     break;
					 
				default:
				     g_sysSetting.Logo.logoID = LOGO1;
				     break;
			}

		    if(g_sysSetting.Logo.logoID >(LOGOMAX-1))
			{
			   g_sysSetting.Logo.logoID = LOGO1;
			}
     }
	 return 1;
}


SWORD GetVolumeSwitchVal(void)
{
     //printfStr("GetVolumeSwitchVal");
     return g_sysSetting.Factory.volumeswitch;
}


SWORD GetScalerSwitchVal(void)
{
     //printfStr("GetScalerSwitchVal");
     return g_sysSetting.Factory.scalerswitch;
}


SWORD GetFlipSwitchVal(void)
{
     //printfStr("GetHorizontalSwitchVal");
     return g_sysSetting.Factory.flipswitch;
}


SWORD GetResetSwitchVal(void)
{
     //printfStr("GetResetSwitchVal");
     return g_sysSetting.Factory.resetswitch; 
}

SWORD GetIRABSwitchVal(void)
{
     //printfStr("GetResetSwitchVal");
     return g_sysSetting.Factory.irabswitch; 
}


SWORD GetRadioFreqSwitchVal(void)
{
     //printfStr("GetSendRfSwitchVal");
     return g_sysSetting.Factory.radiofreqswitch; 
}


SWORD GetPowerSwitchVal(void)
{
     //printfStr("GetPowerSwitchVal");
     return g_sysSetting.Factory.powerswitch;
}


SWORD GetLogoIdSwitchVal(void)
{
     //printfStr("GetPowerSwitchVal");
     return g_sysSetting.Logo.logoID;
}


/*****************************************************************
                          Item value table
*****************************************************************/

DrawOptionType CODE Option_VolumeSwitch[]=
{
    {2,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_VolumeSwitchStr,osdEnd},
};


DrawOptionType CODE Option_ScalerSwitch[]=
{
    {3,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_ScalerSwitchStr,osdEnd},
};


DrawOptionType CODE Option_FlipSwitch[]=
{
    {4,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_FlipSwitchStr,osdEnd},
};


DrawOptionType CODE Option_ResetSwitch[]=
{
    {5,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_ResetSwitchStr,osdEnd},
};


DrawOptionType CODE Option_IRABSwitch[]=
{
    {6,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_IRABSwitchStr,osdEnd},
};


DrawOptionType CODE Option_RadioFreqSwitch[]=
{
    {7,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_RadioFreqSwitchStr,osdEnd},
};


DrawOptionType CODE Option_PowerSwitch[]=
{
    {8,27,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_PowerSwitchStr,osdEnd},
};

DrawOptionType CODE Option_LogoIdSwitch[]=
{
    {9,23,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE, NULL,FactorySwitchMenu_LogoIdSwitchStr,osdEnd},
};


ItemValueType CODE VolumeSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_VolumeSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE ScalerSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_ScalerSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE FlipSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_FlipSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE ResetSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_ResetSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE IRABSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_IRABSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE RadioFreqSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_RadioFreqSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE PowerSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_PowerSwitch,   
	      osdEnd,
     },
};


ItemValueType CODE LogoIdSwitchVal[]=
{
     {
	      NULL,
	      NULL,
	      Option_LogoIdSwitch,   
	      osdEnd,
     },
};

/*****************************************************************
                          Item Icon table
*****************************************************************/



/*****************************************************************
                         Item  Titel table
*****************************************************************/
TitelType CODE FactorySwitchMenuItem_VolumeTitelTab[]=
{
   {2,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_VolumeTitel,osdEnd},
};

TitelType CODE FactorySwitchMenuItem_ScalerTitelTab[]=
{   
   {3,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_ScalerTitel,osdEnd},
};

TitelType CODE FactorySwitchMenuItem_FlipTitelTab[]=
{
   {4,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_FlipTitel,osdEnd},
};

TitelType CODE FactorySwitchMenuItem_ResetTitelTab[]=
{
   {5,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_ResetTitel,osdEnd},
};

TitelType CODE FactorySwitchMenuItem_IRABTitelTab[]=
{
   {6,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_IRABTitel,osdEnd},
};


TitelType CODE FactorySwitchMenuItem_RadioFreqTitelTab[]=
{
   {7,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_RadioFreqTitel,osdEnd},
};


TitelType CODE FactorySwitchMenuItem_PowerTitelTab[]=
{   
   {8,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_PowerTitel,osdEnd},
};


TitelType CODE FactorySwitchMenuItem_LogoIdTitelTab[]=
{   
   {9,0,GREEN,TRANSPARENCE,YELLOW,TRANSPARENCE,DWT_Text,FactorySwitchMenu_LogoIdTitel,osdEnd},
};

/*****************************************************************
                          Menu Icon table
*****************************************************************/



/*****************************************************************
                         Menu  Titel table
*****************************************************************/

#endif
