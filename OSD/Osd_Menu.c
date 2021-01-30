#define _OSD_MENU_C

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
#include "mcu.h"
#include "interrupt.h"
#include "AMT_REG.H"
#include "AMT_Drv.h"
#include "AMT_MCU.h"
#include "BT_UartRec.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "Osd_MenuTbl.h"
#include "IrMap.h"
#include "Ir.h"


#if OSD_STYLE_TYPE != OSD_STYLE_ARK
  "当前OSD风格不匹配，请设置为ARK OSD风格。"
#endif//OSD_STYLE_TYPE == OSD_STYLE_ARK


UCHAR KeyMsgProcess(MSG curMsg)
{
     UCHAR ucComd = COMD_Nothing;
	 
     switch(curMsg)
     {
	   case MSG_UPK_UP:
	   	    printfStr("MSG_UPK_UP");
	   	    SetSaveFlagEn();
	   	    
	   	    #ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_DOWN:
	   	    printfStr("MSG_UPK_DOWN");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_LEFT:
	   	    printfStr("MSG_UPK_LEFT");
	   	    SetSaveFlagEn();

		    #ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_RIGHT:
	   	    printfStr("MSG_UPK_RIGHT");
	   	    SetSaveFlagEn();

		    #ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_MENU:
	   	    printfStr("MSG_UPK_MENU");

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
			
	     	break;
			
	   case MSG_UPK_VOLUME_INC:
	   	    printfStr("MSG_UPK_VOLUME_INC");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_VOLUME_DEC:
	   	    printfStr("MSG_UPK_VOLUME_DEC");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_BRIGHTNESS:
            printfStr("MSG_UPK_BRIGHTNESS");
	   	    SetSaveFlagEn();
			
			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif			
	     	break;

	   case MSG_UPK_CONTRAST:
            printfStr("MSG_UPK_CONTRAST");
	   	    SetSaveFlagEn();
			
			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif			
	     	break;

	   case MSG_UPK_SATURATION:
            printfStr("MSG_UPK_SATURATION");
	   	    SetSaveFlagEn();
			
			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif			
	     	break;
			
	   case MSG_UPK_MUTEONOFF:
	   	    printfStr("MSG_UPK_MUTEONOFF");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif
	     	break;
			
	   case MSG_UPK_MODE:
            printfStr("MSG_UPK_MODE");
	   	    SetSaveFlagEn(); 
			
			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif		
	     	break;

	   case MSG_UPK_SYS:
            printfStr("MSG_UPK_SYS");
	   	    SetSaveFlagEn();

			if(OFF == g_sysSetting.Factory.flipswitch)
			{
			   return COMD_Nothing;
			}
			
			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif		
	     	break;
			
	   case MSG_UPK_SOURCE_SWITCH:
	   	    printfStr("MSG_UPK_SOURCE_SWITCH");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{
			   	if(IsPowerOn())  
				{				  
				   if(inputPress == g_UserInputInfo.Status)
				   { 
					 SetBuzzerOn();
				   }
			    }
			}
		    #endif

	   	    if((g_sysSetting.Car.status == CAR_PON_REVERSING) || (g_sysSetting.Car.status == CAR_POF_REVERSING))
	   	    {
	   	        return COMD_Nothing;
	   	    }
	     	break;
			
	   case MSG_UPK_POWER:
	   	    printfStr("MSG_UPK_POWER");
	   	    SetSaveFlagEn();

			#ifdef BuzzerEn
			if(g_UserInputInfo.Type & KeyType)
			{  
			   if(inputPress == g_UserInputInfo.Status)
			   { 
					 SetBuzzerOn();
			   }
			}
            #endif

	   	    if((g_sysSetting.Car.status == CAR_PON_REVERSING) || (g_sysSetting.Car.status == CAR_POF_REVERSING))
	   	    {
	   	        return COMD_Nothing;
	   	    }
	     	break;
			
		default:
			break;
     }
	 
     //按键OSD处理:
	 ucComd = FindComdInCurMenuItem(curMsg);	 
	 return ucComd;
}

/***********************************************************
*name:     	 FindComdInCurMenuItem(MSG curMsg)
*input:      curMsg
*output:     comd 
*update:     2012-01-13
*state:      allright

*description:   
           从当前的Item 找到相应的输入命令，并返回此命令值.(MSG -> COMD) 

*history:
************************************************************/
UCHAR FindComdInCurMenuItem(MSG curMsg)
{ 
    UCHAR XDATA ucComd = COMD_Nothing;	
    UCHAR XDATA ucIndex;
	
#define CheckInputSource ((CurrentMenuItem.KeyComdMap[ucIndex].Source == g_sysSetting.Video.curSource)||(CurrentMenuItem.KeyComdMap[ucIndex].Source == ALL_INPUT_SOURCE))

FindComdAgain:

	for(ucIndex=0;ucIndex<CurrentMenuItem.ComdCount; ucIndex++)
	{
	    if((CurrentMenuItem.KeyComdMap[ucIndex].Msg == curMsg)&&CheckInputSource)
	    {   
			if(CurrentMenuItem.KeyComdMap[ucIndex].cConditions & g_UserInputInfo.Status)
			{
				ucComd = CurrentMenuItem.KeyComdMap[ucIndex].Comd;  
				return ucComd;
			}
			else
			{   
                if(FindMenuPageIndex(Osd_RootMenu) == g_ucMenuPageIndex)
                {
                   continue; 
                }
				else
				{
				   return COMD_Nothing;
				}
			}
	    }
	}
    /*表示此按键信息在当前菜单中无效，切换到根菜单*/
	if(FindMenuPageIndex(Osd_RootMenu) != g_ucMenuPageIndex)
	{   
		g_ucMenuPageIndex = FindMenuPageIndex(Osd_RootMenu);
		g_ucMenuItemIndex = 0; 
		goto FindComdAgain;
	}
	return COMD_Nothing;	
}


BOOL ExectComd(ComdType OpratComd)
{
    BOOL OpratComdFlg = TRUE;
	
    while(OpratComdFlg)
    {
        OpratComdFlg = FALSE;
		
      	switch (OpratComd)
        {
			case COMD_IncValue:
			case COMD_DecValue:
		        if(CurrentMenuItem.AdjustFunction)
		        {
		             if(CurrentMenuItem.AdjustFunction(OpratComd))
		             {
		                  DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
		             }
		        }
				if(CurrentMenuItem.ExecFunction)
				{
					CurrentMenuItem.ExecFunction();
				}
				break;

			case COMD_NextItem:
			case COMD_PrevItem:
				 DrawOsdMenuItem(&CurrentMenuItem, osdDraw);
				 if(OpratComd == COMD_NextItem)
				 {
				      g_ucMenuItemIndex = GetNextItem();  
					  //printf("netx g_ucMenuItemIndex = %x", g_ucMenuItemIndex);
				 }
				 else
				 {
					  g_ucMenuItemIndex = GetPrevItem();
					  //printf("prev g_ucMenuItemIndex = %x", g_ucMenuItemIndex);
				 }
                 if(FindMenuPageIndex(Osd_FactoryMenu) ==g_ucMenuPageIndex)  
				 { 
				     g_ucFactoryMenuItemIndex = g_ucMenuItemIndex;
				 }
				DrawOsdMenuItem(&CurrentMenuItem, osdSel);	
				break;

			case COMD_EnterFactoryItem:
				if(FindMenuPageIndex(Osd_FactoryMenu) ==g_ucMenuPageIndex)  
				{  
				   switch(g_ucMenuItemIndex)
				   {
				     case FactoryPic:
					 	   SetMenuIndex(Osd_FactoryPicMenu);
					 	   break;
						   
					 case FactorySwitch:
					 	   SetMenuIndex(Osd_FactorySwitchMenu);
					 	   break;
						   
					 default:
					 	   SetMenuIndex(Osd_FactoryPicMenu);
					 	   break;
				   }
				}
				DrawOsdMenuItem(&CurrentMenuItem, osdDraw);
				DrawOsdMenuItem(&CurrentMenuItem, osdSel);	
				break;
				
			case COMD_NextMenu:
			case COMD_PrevMenu:
				if(OpratComd == COMD_NextMenu)
				{
				      g_ucMenuPageIndex = GetNextMenu();
					  //printf("netx g_ucMenuPageIndex = %x", g_ucMenuPageIndex);
				}
				else
				{
				 	  g_ucMenuPageIndex = GetPreMenu();
					  //printf("prev g_ucMenuPageIndex = %x", g_ucMenuPageIndex);
				}
			case COMD_RedrawMenu:
				if(FindMenuPageIndex(Osd_RootMenu) == g_ucMenuPageIndex)
				{   
					SetMenuIndex(Osd_BrightnessMenu);
				}
				//printf("g_ucMenuPageIndex = %x", g_ucMenuPageIndex);
				OsdBlockEnable(CurrentBlock);
				OsdConfigScaler(OsdScalerRatio);
				DrawOsdMenu();		
				g_ucOsdEixt |= (OsdMode|OsdSys);
				break;

		  case COMD_RedrawFactoryMenu:
		  	    printfStr("COMD_RedrawFactoryMenu");
				OsdBlockEnable(CurrentBlock);
				OsdConfigScaler(OsdScalerRatio);  
				DrawOsdMenu();	
				DrawOsdMenuItem(&CurrentMenuItem, osdDraw);	
				SetMenuIndex(Osd_FactoryMenu);
				g_ucMenuItemIndex = g_ucFactoryMenuItemIndex;
				break;

			case COMD_SelPowerOnMode:
				if(IsAllPowerOn())
				{
				    SetAllPowerOn();
				}
				else if(IsAllPowerOff())
				{
				    SetAllPowerOff(); 
				}
				else if(IsPowerSave())
				{
				    SetPowerSave();
				}

			case COMD_Power:
				if(IsPowerOn())
				{
				    printfStr("Osd_PowerOffMenu");
				    SetMenuIndex(Osd_PowerOffMenu);
				}
				else
				{
				    printfStr("Osd_PowerOnMenu");
				    SetMenuIndex(Osd_PowerOnMenu);
				}

				if(CurrentMenuItem.ExecFunction)
				{   
				    printfStr("ExecFunction");
				    CurrentMenuItem.ExecFunction();
				}	

				#ifdef LogoEn 
				#if (LOGO_DISP_MODE == POWER_ON_DISP_LOGO)
				g_bLogoFlg = TRUE;
				if(IsPowerOn())
				{
				    if(g_sysSetting.Car.DetecMode != AV_SIGNAL_OK) //上电的时候有倒车信号不显示LOGO
				   	{
						printfStr("Osd_LogoMenu");
						SetVDETestSwitch(LOGO_DISP_BACKCOLOR);
						switch(g_sysSetting.Logo.logoID)
						{
						  case LOGO1:
						  	   printfStr("Osd_Logo1Menu");
						  	   SetMenuIndex(Osd_LOGO1Menu);
						  	   break;
							   
						  case LOGO2:
						  	   printfStr("Osd_Logo2Menu");
						  	   SetMenuIndex(Osd_LOGO2Menu);
						  	   break;
							   
						  case LOGO3:
						  	   printfStr("Osd_Logo3Menu");
						  	   SetMenuIndex(Osd_LOGO3Menu);
						  	   break;

						  case LOGO4:
						  	   printfStr("Osd_Logo4Menu");
						  	   SetMenuIndex(Osd_LOGO4Menu);
						  	   break;
							   
						 case LOGO5:
						  	   printfStr("Osd_Logo5Menu");
						  	   SetMenuIndex(Osd_LOGO5Menu);
						  	   break;	
							   
						 default:
						  	  printfStr("default Osd_Logo1Menu");
						  	  SetMenuIndex(Osd_LOGO1Menu);
						  	  break;
						}
						InitLogoMenuDat();
						OsdBlockEnable(CurrentBlock);
						OsdConfigScaler(OsdScalerRatio);
						DrawOsdMenu();
						TurnOnBackLight();
						POS_ClearWatchDog();
						DelayMs(4000);
						HideMenu();
						SetVDETestSwitch(VDE_CLOSE);
						ResetMenuIndex();
						InitOSD();	
						SetMenuIndex(Osd_PowerOnMenu);
				   }
				}
				g_bLogoFlg = FALSE;
				g_ucRemoteKeyVal = IR_NULL_KEY;
				#endif
				#endif
				break;

			case COMD_RedrawLogo:
				 SetVDETestSwitch(LOGO_DISP_BACKCOLOR);
				 switch(g_sysSetting.Logo.logoID)
				 {
					  case LOGO1:
					  	   printfStr("Osd_Logo1Menu");
					  	   SetMenuIndex(Osd_LOGO1Menu);
					  	   break;
						   
					  case LOGO2:
					  	   printfStr("Osd_Logo2Menu");
					  	   SetMenuIndex(Osd_LOGO2Menu);
					  	   break;
						   
					  case LOGO3:
					  	   printfStr("Osd_Logo3Menu");
					  	   SetMenuIndex(Osd_LOGO3Menu);
					  	   break;

					  case LOGO4:
					  	   printfStr("Osd_Logo4Menu");
					  	   SetMenuIndex(Osd_LOGO4Menu);
					  	   break;
						   
					 case LOGO5:
					  	   printfStr("Osd_Logo5Menu");
					  	   SetMenuIndex(Osd_LOGO5Menu);
					  	   break;	
						   
					 default:
					  	  printfStr("default Osd_Logo1Menu");
					  	  SetMenuIndex(Osd_LOGO1Menu);
					  	  break;
				 }
				
				#ifdef LogoEn
				InitLogoMenuDat();
				#endif
				
				OsdBlockEnable(CurrentBlock);
				OsdConfigScaler(OsdScalerRatio);
				DrawOsdMenu();
				break;

			case COMD_ClearLogo:
				 //printfStr("COMD_ClearLogo");
				 HideMenu();
				 SetVDETestSwitch(VDE_CLOSE);
				 ResetMenuIndex();
				 InitOSD();	
				 break;

			case COMD_RedrawSnow:
				 printfStr("COMD_RedrawSnow");
				 #ifdef NoSignalSnowEn
				 SetNoSignalSnow();
				 #endif
				 break;
				 
			case COMD_ClearNoSignal:
				 printfStr("COMD_ClearNoSignal");
				 if(!IsFactoryEn())
				 {
				    SetMenuIndex(Osd_NoSignalMenu);
				    OsdBlockHide(CurrentBlock);
				 }
				 break;

		    case COMD_TurnOnBacklight:
				 printfStr("COMD_TurnOnBacklight");				 
				 if(!g_bBackLightFlg)
				 {
				     TurnOnBackLight();

                     #ifdef AudioCtrlEn
					 if((IsSignalOk()))
					 {
					     OpenAudio();   
					 }
                     #endif
				 }
				 break;
				 
           case COMD_TurnOffBacklight:
				 printfStr("COMD_TurnOffBacklight");
				 if(g_bBackLightFlg)
				 {
					TurnOffBackLight(); 
					SaveSetting();
				 }				 
				break;

			case COMD_SelReset:
			case COMD_SelSource:
				if(COMD_SelReset == OpratComd)
				{
				  SetMenuIndex(Osd_ResetMenu);
				}
				else
				{
				  SetMenuIndex(Osd_QuicklySource);
				}
				if(CurrentMenuItem.AdjustFunction)
				{
				    CurrentMenuItem.AdjustFunction(OpratComd);
				}
				if(CurrentMenuItem.ExecFunction)
				{
				    CurrentMenuItem.ExecFunction();
				}
			case COMD_ShowSource:
				printfStr("COMD_ShowSource");
				if(!IsFactoryEn())
				{
					SetMenuIndex(Osd_QuicklySource);
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);
					DrawOsdMenu();
					SetMenuIndex(Osd_RootMenu);
				}
				break;
				
			case COMD_IncVolume:
			case COMD_DecVolume:
				printfStr("Osd_QuicklyVolume");
				if(OFF == g_sysSetting.Factory.volumeswitch)
				{
				     return FALSE;
				}
				SetMenuIndex(Osd_QuicklyVolume);
				if(g_ucOsdEixt & OsdVolume)
				{
				   OsdBlockEnable(CurrentBlock);
				   OsdConfigScaler(OsdScalerRatio);
				   DrawOsdMenu();
				   g_ucOsdEixt &= ~OsdVolume;
				   g_ucOsdEixt |= (OsdMenu|OsdSource|OsdMode|OsdSys);
				}
				if(CurrentMenuItem.AdjustFunction)
				{
				   if(CurrentMenuItem.AdjustFunction(OpratComd))
				   {
					  DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
				   }
				}
				if(CurrentMenuItem.ExecFunction)
				{
					  CurrentMenuItem.ExecFunction();
				}
				break;
				  
			case COMD_SelMode:
				  printfStr("COMD_SelMode");
				  if(OFF == g_sysSetting.Factory.scalerswitch)
				  {
				     return FALSE;
				  }
				  SetMenuIndex(Osd_QuicklyMode);
                  if(CurrentMenuItem.AdjustFunction)
				  {
					   if(CurrentMenuItem.AdjustFunction(OpratComd))
					   {
						  DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
					   }
				  }
				  if(CurrentMenuItem.ExecFunction)
				  {
				       CurrentMenuItem.ExecFunction();
				  }
            case COMD_Mode:
				 printfStr("Osd_QuicklyMode");
				 if(g_ucOsdEixt & OsdMode)
				 {
					 OsdBlockEnable(CurrentBlock);
					 OsdConfigScaler(OsdScalerRatio);
					 DrawOsdMenu();
					 g_ucOsdEixt &= ~OsdMode;
					 g_ucOsdEixt |= (OsdMenu|OsdSource|OsdVolume|OsdSys);
				 }
				 SetMenuIndex(Osd_RootMenu);
				 break;
			
			case COMD_SelMuteOnOff:
				printfStr("COMD_SelMuteOnOff");
				SetMenuIndex(Osd_QuicklyMute);
				if(CurrentMenuItem.AdjustFunction)
				{
				    CurrentMenuItem.AdjustFunction(OpratComd);
				}
				if(CurrentMenuItem.ExecFunction)
				{
				    CurrentMenuItem.ExecFunction();
				}
			case COMD_ShowMuteOnOff:
				printfStr("COMD_ShowMuteOnOff");
				SetMenuIndex(Osd_QuicklyMute);
				OsdBlockEnable(CurrentBlock);
				OsdConfigScaler(OsdScalerRatio);
				DrawOsdMenu();
				SetMenuIndex(Osd_RootMenu);
				break;

			case COMD_SelSys:
				 printfStr("COMD_SelSys");
				 if(OFF == g_sysSetting.Factory.flipswitch)
				 {
				     return FALSE;
				 }
				 SetMenuIndex(Osd_QuicklySys);
                 if(CurrentMenuItem.AdjustFunction)
				 {
				    if(CurrentMenuItem.AdjustFunction(OpratComd))
					{
					    DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
					}
				 }
				 if(CurrentMenuItem.ExecFunction)
				 {
				    CurrentMenuItem.ExecFunction();
				 }
            case COMD_Sys:
				 printfStr("Osd_QuicklySys");
				 if(g_ucOsdEixt & OsdSys)
				 {
				    OsdBlockEnable(CurrentBlock);
				    OsdConfigScaler(OsdScalerRatio);
				    DrawOsdMenu();
					g_ucOsdEixt &= ~OsdSys;
					g_ucOsdEixt |= (OsdMenu|OsdSource|OsdVolume|OsdMode);
				 }
				 break;
				 
		    case COMD_Brightness:
				printfStr("COMD_Brightness");
				SetMenuIndex(Osd_QuicklyBrightness);
				if(g_ucOsdEixt & OsdBrightness)
				{
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);
					DrawOsdMenu();
					g_ucOsdEixt &= ~OsdBrightness;
					g_ucOsdEixt |= OsdContrast;
					g_ucOsdEixt |= OsdSaturation;
				}
				if(CurrentMenuItem.AdjustFunction)
				{
				   if(CurrentMenuItem.AdjustFunction(OpratComd))
				   {
					  DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
				   }
				}
				if(CurrentMenuItem.ExecFunction)
				{
					  CurrentMenuItem.ExecFunction();
				}
				break;

			case COMD_Contrast:
				printfStr("COMD_Contrast");
				SetMenuIndex(Osd_QuicklyContrast);
				if(g_ucOsdEixt & OsdContrast)
				{
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);
					DrawOsdMenu();
					g_ucOsdEixt |= OsdBrightness;
					g_ucOsdEixt &= ~OsdContrast;
					g_ucOsdEixt |= OsdSaturation;
				}
				if(CurrentMenuItem.AdjustFunction)
				{
				   if(CurrentMenuItem.AdjustFunction(OpratComd))
				   {
					    DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel); 
				   }
				}
				if(CurrentMenuItem.ExecFunction)
				{
					   CurrentMenuItem.ExecFunction();
				}				
				break;

			case COMD_Saturation:
				printfStr("COMD_Saturation");
				SetMenuIndex(Osd_QuicklySaturation);
				if(g_ucOsdEixt & OsdSaturation)
				{
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);
					DrawOsdMenu();
					g_ucOsdEixt |= OsdBrightness;
					g_ucOsdEixt |= OsdContrast;
					g_ucOsdEixt &= ~OsdSaturation;
				}
				if(CurrentMenuItem.AdjustFunction)
				{
				   if(CurrentMenuItem.AdjustFunction(OpratComd))
				   {
					   DrawOsdMenuItemValue(CurrentMenuItem.ItemValue,osdSel);
				   }
				}
				if(CurrentMenuItem.ExecFunction)
				{
				      CurrentMenuItem.ExecFunction();
				}				
				break;
				
			case COMD_FactoryMenu:
				 printfStr("COMD_FactoryMenu");
				 SetFactoryEn();
                 SetPowerOn();
				 SelVideoInputSource(g_sysSetting.Video.curSource);
				 ExitLowPowerMode();
				 TurnOnBackLight(); 
				 SetMenuIndex(Osd_FactoryMenu);
				 OsdBlockEnable(CurrentBlock);
				 OsdConfigScaler(OsdScalerRatio);
				 DrawOsdMenu();
				 DrawOsdMenuItem(&CurrentMenuItem, osdSel);	
				 break;

			case COMD_OsdExit:
				printfStr("COMD_OsdExit");
				HideMenu();
				  
				#ifdef NoSignalEn
				if(!IsSignalOk())  
				{
				  SetMenuIndex(Osd_NoSignalMenu);
				  OsdBlockEnable(CurrentBlock);
				  OsdConfigScaler(NoSignalScalerRatio);				  
				  DrawOsdMenu();
				}
				#endif
				
				ResetMenuIndex();
				SaveSetting();					
				return FALSE;
				break;

		  case COMD_OsdStorage:
				printfStr("COMD_OsdStorage");
		        SaveSetting();
				return FALSE;
				break;
				
			case COMD_ExitFactoryMenu:
				 printfStr("COMD_ExitFactoryMenu");
				 ClrFactoryEn() ;
				 SetPowerOff();
				 TurnOffBackLight(); 
				 HideMenu();
				 ResetMenuIndex();
				 SaveSetting();
	             TurnOffDevicePower(g_sysSetting.Video.curSource);   
				 EnterLowPowerMode();
				 return FALSE;
				 break;

		    case COMD_BatteryAdc:
				 //printfStr("COMD_BatteryAdc");
				 SetMenuIndex(Osd_BatteryAdcMenu);
				 if(CurrentMenuItem.AdjustFunction)
				 {
				    CurrentMenuItem.AdjustFunction(OpratComd);
				 }
				 if(CurrentMenuItem.ExecFunction)
				 {
				    CurrentMenuItem.ExecFunction();
				 }
				 OsdBlockEnable(CurrentBlock);
				 OsdConfigScaler(OsdScalerRatio);
				 DrawSpecialOsdMenu();				 
				 break;

			#ifdef BTEn
			case COMD_BTConn:
			case COMD_BTDisc:
				if(!IsCameraCar())
				{
					SetMenuIndex(Osd_BTMenu);
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);				  
					DrawOsdMenu();
				}
				break;

			case COMD_BTCallerID:
				if(!g_bCallAnswerFlg)
				{
				    if(!g_bBackLightFlg)
					{					   
                       #ifdef BacklightEn
                       hw_setBIASEn();
                       #endif
                       
                       DelayMs(100);	
					   
					   #ifdef BacklightEn
	                   hw_setBacklight();
		               #endif
					}
					SetMenuIndex(Osd_BTCallerMenu);
					OsdBlockEnable(CurrentBlock);
					OsdConfigScaler(OsdScalerRatio);				  
					DrawSpecialOsdMenu();
				}
				break;

			case COMD_BTCallAnswer:
				printfStr("COMD_BTCallAnswer");
				if(!g_bCallAnswerFlg)
				{
				  printfStr("CALL_ANSWER");
				  g_bCallAnswerFlg = TRUE;
				  POS_UartSendCmd(CALL_ANSWER);
				}
				else
				{
				  printfStr("CALL_REJECTED");
				  g_bCallAnswerFlg = FALSE;
				  POS_UartSendCmd(CALL_REJECTED);
				}
				break;

			case COMD_BTCallerDrop:
				 OsdBlockHide(OsdBlock2);
				 ResetMenuIndex();
				 if(g_bBackLightFlg)
				 {
				    #ifdef BacklightEn
                    hw_clrBacklight(); 
	                #endif
					
					DelayMs(100);

                    #ifdef BacklightEn
                    hw_clrBIASEn();
                    #endif
				 }
				return FALSE;
				break;
			#endif

	  	    default:
	            return FALSE;
	      	    break;
        }
    }
	return 1;
}

void MenuProcessKey(BYTE OpratComd)
{
  	if (OpratComd)
  	{   
		if(IsPowerOff()&&(g_sysSetting.Car.status != CAR_POF_REVERSING))
		{   
            if((OpratComd!=COMD_SelPowerOnMode) && (OpratComd!=COMD_Power)&&(inputPress == g_UserInputInfo.Status))
			{  
                #ifdef FactoryEn				
					static UCHAR  CODE  PassWord[] = PassWordBuf;
					static UCHAR  XDATA PassWordId = 0;
					static BYTE   XDATA PreOpratComd = COMD_Nothing;

					if(PreOpratComd != OpratComd)
					{
					   PreOpratComd = OpratComd;
					   if(OpratComd == PassWord[PassWordId])
					   {
					     if(++PassWordId == sizeof(PassWord))
						 {  
						   PassWordId = 0;
						   OpratComd = COMD_FactoryMenu;
						 }
						 else
						 {
						    OpratComd=COMD_Nothing;
						 }
					   }
					   else
					   {
					        PassWordId = 0;
					        OpratComd=COMD_Nothing;
					   }
					}
				#else
				OpratComd=COMD_Nothing;
                #endif 
			}
		}		
		if (ExectComd(OpratComd))
		{   
			g_sysSetting.Osd.dispTime= CurrentMenu->TimeOut;
		}
  	}
}




//========================================================
//               Draw Menu functions
//========================================================

void InitOsdBlock(void)
{
    ConfigOsdBlockStarIndexAddr();
}

void InitOSD(void) 
{  
    printfStr("InitOSD\n");
	OsdHide();
	OsdClear();
	OsdCofigPalette();
	OsdIconSize(ICON_SIZE_X,ICON_SIZE_Y);
	OsdConfigAlpha(DISABLE,OSD_BLENDING,0);
	OsdConfigBitmapStarIndex(ICONBITMAP_SATRT_INDEX);	
	OsdConfigBright(7);
	#if(ICON_SIZE == SIZE_12X16)
	DMALoadFontRam((ULONG)AMT630FontLib&0X000FFFF,0<<4,5440);  // 170
	LoadMulCharToFontram(170,3,AMT630Font_Char);
	#elif(ICON_SIZE == SIZE_16X22)
	LoadMulCharToFontram(0,3,FontRam_Char);
	#endif
}


/******************************************************************
*Name: void DrawOsdTitel(TitelType *pTitel)
*input:  pTitel  标题指针
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画标题函数。

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdTitel(TitelType *pTitel,UINT status) reentrant
{
    UCHAR ucForeColor,ucBackColor;
	
    //printfStr("DrawOsdTitel");
    while(1)
    {
         if(pTitel == NULL)
         {
            break;
         }
		 if(status&osdDraw)
		 {
			 ucForeColor = pTitel->ForeColor;
			 ucBackColor = pTitel->BackColor;
		 }
		 if(status&osdSel)
		 {
			 ucForeColor = pTitel->SelForeColor;
			 ucBackColor = pTitel->SelBackColor;
		 }
		 
	    if(pTitel->DisplayText)
	    {
	         OsdDrawStr(pTitel->XPos, pTitel->YPos,COLOR(ucForeColor,ucBackColor),pTitel->DisplayText());
	    }
		if(pTitel->Flags & osdEnd)
		{
		      break;
		}
		pTitel++;
    }
   
}

/******************************************************************
*Name: void DrawOsdIcon(IconType* pIcon,UCHAR status)
*input:  pIcon  画ICON 指针
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画icon函数。

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdIcon(IconType* pIcon,UINT status)
{
    UCHAR XDATA ucBackColor;
	
    //printfStr("DrawOsdIcon");
    while(1)
    { 
         if(pIcon == NULL)
         {
             break;
         }
		 
		 if(status&osdDraw)
		 {
			 ucBackColor = pIcon->BackColor;
		 }
		 if(status&osdSel)
		 {
			 ucBackColor = pIcon->SelBackColor;
		 }
	    if(pIcon->DispalyIcon)
	    {   
	        OsdDrawIcon(pIcon->XPos, pIcon->YPos,pIcon->XSize, pIcon->YSize,ucBackColor, pIcon->DispalyIcon());
	    }  
		
		if(pIcon->Flags & osdEnd)
		{
		      break;
		}
		pIcon++;
		
    }
}


/******************************************************************
*Name: void DrawOsdMenuItemNumber(DrawNumberType *pNumberItem,UCHAR status)
*input:  pNumberItem  画数字指针
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画数字

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenuItemNumber(DrawNumberType *pNumberItem,UINT status)
{
    UCHAR XDATA ucForeColor,ucBackColor;
	
    //printfStr("DrawOsdMenuItemNumber");
	if(pNumberItem!=NULL)
	{
	     if(status&osdDraw)
		 {
			 ucForeColor = pNumberItem->ForeColor;
			 ucBackColor = pNumberItem->BackColor;
		 }
		 if(status&osdSel)
		 {
			 ucForeColor = pNumberItem->SelForeColor;
			 ucBackColor = pNumberItem->SelBackColor;
		 }
		 
	     if(pNumberItem->Flags & osdDecNum)
	     {
	          OsdDrawNum(pNumberItem->XPos,pNumberItem->YPos,COLOR(ucForeColor,ucBackColor),pNumberItem->GetValue());
	     }
		 if(pNumberItem->Flags & osdHexNum)
		 {
		      OsdDrawHex(pNumberItem->XPos,pNumberItem->YPos,COLOR(ucForeColor,ucBackColor),pNumberItem->GetValue());
		 }
	}
}

/******************************************************************
*Name: void DrawOsdMenuItemGuage(DrawGuageType *pGaugeItem,UCHAR status)
*input:  pNumberItem  画进度条
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画进度条

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenuItemGuage(DrawGuageType *pGaugeItem,UINT status)
{
    UCHAR XDATA ucForeColor,ucBackColor;
	
 	//printfStr("DrawOsdMenuItemGuage"); 
	if(pGaugeItem != NULL)
	{  
	     if(status&osdDraw)
		 {
			 ucForeColor = pGaugeItem->ForeColor;
			 ucBackColor = pGaugeItem->BackColor;
		 }
		 if(status&osdSel)
		 {
			 ucForeColor = pGaugeItem->SelForeColor;
			 ucBackColor = pGaugeItem->SelBackColor;
		 }
	    if(pGaugeItem->GetValue)
	    { 
	        OsdDrawGuage(pGaugeItem->XPos, pGaugeItem->YPos, pGaugeItem->Length, COLOR(ucForeColor,ucBackColor),pGaugeItem->GetValue());
	    }	
	}
}
  
/******************************************************************
*Name: void DrawOsdMenuItemOption(DrawOptionType *radioItem,UCHAR status)
*input:  pNumberItem  画选项(text)
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画选项(text)

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenuItemOption(DrawOptionType *pOptionItem,UINT status)
{   

    UCHAR XDATA ucForeColor,ucBackColor;

	//printfStr("DrawOsdMenuItemOption");
	if(pOptionItem != NULL)
	{   
	     if(status&osdDraw)
		 {
			 ucForeColor = pOptionItem->ForeColor;
			 ucBackColor = pOptionItem->BackColor;
		 }
		 if(status&osdSel)
		 {
			 ucForeColor = pOptionItem->SelForeColor;
			 ucBackColor = pOptionItem->SelBackColor;
		 }
		 if(pOptionItem->DisplayText)
		 {   
		 	 OsdDrawStr(pOptionItem->XPos, pOptionItem->YPos, COLOR(ucForeColor,ucBackColor),pOptionItem->DisplayText());
		 }
	}
}
/******************************************************************
*Name: void DrawOsdMenuItemValue(ItemValueType* pItemValue,UINT status)
*input:  pItemValue  画ITEM 的值 包括: 数字，进度条 ，选项
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画ITEM 的值 包括: 数字，进度条 ，选项

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenuItemValue(ItemValueType* pItemValue,UINT status)
{
    if(pItemValue == NULL)
    {
         return;
    }
		
    while(1)
    {
        if(pItemValue->DrawNumber)
        {
            DrawOsdMenuItemNumber(pItemValue->DrawNumber,status);
        }
        if(pItemValue->DrawGuage)
        {    
            DrawOsdMenuItemGuage(pItemValue->DrawGuage,status);
        }
        if(pItemValue->DrawOption)
        {
            DrawOsdMenuItemOption(pItemValue->DrawOption,status);
        }
        if(pItemValue->Flags&osdEnd)
        {
        	break;
        }    
        pItemValue++;
    }
}
/******************************************************************
*Name: DrawOsdMenuItem(MenuItemType *pMenuItem,UINT status)
*input:  pMenuItem  菜单条目指针，
         status     状态: 画状态， 选择状态， 
*output: void
      
*Description: 画菜单条目

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenuItem(MenuItemType *pMenuItem,UINT status) reentrant
{
    AdjustType  wcDrawItemCdtion;

	//首先判断画此菜单的条件。
    if(pMenuItem->CheckCondition)
    {
        wcDrawItemCdtion = pMenuItem->CheckCondition();
    }

    //判断是否有个性风格
	if(pMenuItem->DrawItemStyle)
	{
	    pMenuItem->DrawItemStyle();
	}

    if(pMenuItem->ItemIcons)
    {   
    	DrawOsdIcon(pMenuItem->ItemIcons,status);
    }
	if(pMenuItem->ItemTitels)
	{
		DrawOsdTitel(pMenuItem->ItemTitels,status);
	}	
    DrawOsdMenuItemValue(pMenuItem->ItemValue,status);
	
}

/******************************************************************
*Name: void DrawOsdMenu(void)
*input:  void
*output: void
      
*Description: 画菜单

*history: 1.Jordan.chen   2012/02/21    1.0    buil   this  function
*******************************************************************/
void DrawOsdMenu(void)
{
    AdjustType XDATA wcDrawMenuCdtion;
	UCHAR XDATA i;

	printfStr(CurrentMenu->MenuName);

	//首先判断画此菜单的条件。
    if(CurrentMenu->CheckCondition)
    {
        wcDrawMenuCdtion = CurrentMenu->CheckCondition();
	}
    //判断是否需要隐藏。
	if(CurrentMenu->Flags & osdInvisible)
	{
	    HideMenu();
		//printfStr("hide osd\n");
	}
	else
	{
	    //判断是否需要初始化:重新设定大小等。。
	    if((CurrentMenu->Flags & osdRedraw)&&(wcDrawMenuCdtion.Flags & osdVisible))
		{
	        //printfStr("redraw osd menu");
		    HideMenu();
			OsdBlockClear(CurrentBlock);	
			OsdConfigWndSize(CurrentMenu->XSize,CurrentMenu->YSize);
			OsdConfigWndPosition(CurrentMenu->XPos+wcDrawMenuCdtion.XPos, CurrentMenu->YPos+wcDrawMenuCdtion.YPos);
			OsdConfigBlockColor(COLOR(CurrentMenu->ForeColor,CurrentMenu->BackColor));			
		    if(CurrentMenu->DrawMenuStyle)
			{
	     		 CurrentMenu->DrawMenuStyle();
			}
		}	
		
		if(CurrentMenu->MenuIcons)
		{   
			DrawOsdIcon(CurrentMenu->MenuIcons,osdDraw);
		}
		
	    if(CurrentMenu->MenuTitels)
	    {
	    	DrawOsdTitel(CurrentMenu->MenuTitels,osdDraw);
	    }
		
		for(i=0; i<CurrentMenuItemCount; i++)
		{   
		    DrawOsdMenuItem(&CurrentMenu->MenuItems[i],osdDraw);
		}
		OsdBlockShow(CurrentBlock);
	}
}



void DrawSpecialOsdMenu(void)
{
    AdjustType XDATA wcDrawMenuCdtion;
	UCHAR XDATA i;

	printfStr(CurrentMenu->MenuName);

	//首先判断画此菜单的条件。
    if(CurrentMenu->CheckCondition)
    {
        wcDrawMenuCdtion = CurrentMenu->CheckCondition();
	}
    //判断是否需要隐藏。
	if(CurrentMenu->Flags & osdInvisible)
	{
	    HideMenu();
		printfStr("hide osd\n");
	}
	else
	{
	    //判断是否需要初始化:重新设定大小等。。
	    if((CurrentMenu->Flags & osdRedraw)&&(wcDrawMenuCdtion.Flags & osdVisible))
		{
	        printfStr("redraw special osd menu");
			OsdBlockClear(CurrentBlock);	
			OsdConfigWndSize(CurrentMenu->XSize,CurrentMenu->YSize);
			OsdConfigWndPosition(CurrentMenu->XPos+wcDrawMenuCdtion.XPos, CurrentMenu->YPos+wcDrawMenuCdtion.YPos);
			OsdConfigBlockColor(COLOR(CurrentMenu->ForeColor,CurrentMenu->BackColor));			
		    if(CurrentMenu->DrawMenuStyle)
			{
	     		 CurrentMenu->DrawMenuStyle();
			}
		}	
		
		if(CurrentMenu->MenuIcons)
		{   
			DrawOsdIcon(CurrentMenu->MenuIcons,osdDraw);
		}
		
	    if(CurrentMenu->MenuTitels)
	    {
	    	DrawOsdTitel(CurrentMenu->MenuTitels,osdDraw);
	    }
		
		for(i=0; i<CurrentMenuItemCount; i++)
		{   
		    DrawOsdMenuItem(&CurrentMenu->MenuItems[i],osdDraw);
		}
		OsdBlockShow(CurrentBlock);
	}
}


UCHAR GetPrevItem(void)
{
    UCHAR XDATA ucTempItemIndex,ucPrevItemIndex;

	ucTempItemIndex = g_ucMenuItemIndex;
    ucPrevItemIndex = g_ucMenuItemIndex;

	while(1)
	{
		if(g_ucMenuItemIndex>0)
		{
		     g_ucMenuItemIndex--;
		}
		else
		{
		     g_ucMenuItemIndex =  CurrentMenuItemCount - 1;
		}
		if(CurrentMenuItem.Flags & osdSel)
		{	
			if(CurrentMenuItem.CheckCondition)
			{
				if(CurrentMenuItem.CheckCondition().Flags & osdVisible)
				{
					ucPrevItemIndex = g_ucMenuItemIndex;
					g_ucMenuItemIndex = ucTempItemIndex;
					return ucPrevItemIndex;
				} 
			}
			else
			{
				ucPrevItemIndex = g_ucMenuItemIndex;
				g_ucMenuItemIndex = ucTempItemIndex;
				return ucPrevItemIndex;
			}
		}
		if(ucTempItemIndex == g_ucMenuItemIndex)
		{
			break;
		}
	}
    return ucPrevItemIndex;
}

UCHAR GetNextItem(void)
{
    UCHAR XDATA ucTempItemIndex,ucPrevItemIndex;

	ucTempItemIndex = g_ucMenuItemIndex;
    ucPrevItemIndex = g_ucMenuItemIndex;
	
	while(1)
	{
		if(g_ucMenuItemIndex<(CurrentMenuItemCount - 1))
		{
		     g_ucMenuItemIndex++;  
		}
		else
		{
		     g_ucMenuItemIndex =  0;
		}
	
		if(CurrentMenuItem.Flags & osdSel)
		{	
			if(CurrentMenuItem.CheckCondition)
			{
				if(CurrentMenuItem.CheckCondition().Flags & osdVisible)
				{
					ucPrevItemIndex = g_ucMenuItemIndex;
					g_ucMenuItemIndex = ucTempItemIndex;
					return ucPrevItemIndex;
				} 
			}
			else
			{
				ucPrevItemIndex = g_ucMenuItemIndex;
				g_ucMenuItemIndex = ucTempItemIndex;
				return ucPrevItemIndex;
			}
		}
	
		if(ucTempItemIndex == g_ucMenuItemIndex)
		{
			break;
		}
	}
    return ucPrevItemIndex;
}


UCHAR GetNextMenu(void)
{
    UCHAR XDATA ucNextPage, ucIndex;
	
	ucNextPage = CurrentMenu->NextPage;
	ucIndex = g_ucMenuPageIndex;

	//printf("ucIndex = %x", ucIndex);
	//printf("MenuCount = %x", (MenuCount));
			 
    while(1)
    {
         if(g_ucMenuPageIndex<(MenuCount))
         {
             g_ucMenuPageIndex++;
         }
		 else
		 {
		     g_ucMenuPageIndex = 0;
		 }		
		 if(CurrentMenu->CurrentPage == ucNextPage)
		 { 
			if(CurrentMenu->Flags & osdVisible)
			{	
				if(CurrentMenu->CheckCondition)
				{
					if(CurrentMenu->CheckCondition().Flags & osdVisible)
					{    
					     return g_ucMenuPageIndex;
					} 
					else
					{    
					     ucNextPage = CurrentMenu->NextPage;
					}
				}
				else
				{
					return g_ucMenuPageIndex;
				}
			}
		 }	 
		 if(g_ucMenuPageIndex == ucIndex)
		 {   
			 SetMenuIndex(Osd_QuicklySource);			 
		     break;
		 }
    }
	return g_ucMenuPageIndex;
}

UCHAR GetPreMenu(void)
{
    UCHAR XDATA ucPrePage, ucIndex;
	
	ucPrePage = CurrentMenu->PrevPage;
	ucIndex = g_ucMenuPageIndex;
    while(1)
    {
         if(g_ucMenuPageIndex>0)
         {
             g_ucMenuPageIndex--;
         }
		 else
		 {
		     g_ucMenuPageIndex = (MenuCount-1);
		 }
		 if(CurrentMenu->CurrentPage == ucPrePage)
		 {
			 if(CurrentMenu->Flags & osdVisible)
			 {	
				if(CurrentMenu->CheckCondition)
				{
					if(CurrentMenu->CheckCondition().Flags & osdVisible)
					{
						return g_ucMenuPageIndex;
					} 
					else
					{
					     ucPrePage = CurrentMenu->PrevPage;
					}
				}
				else
				{
				    return g_ucMenuPageIndex;
				}
			 }
		 }
		 
		 if(g_ucMenuPageIndex == ucIndex)
		 {
		     break;
		 }
    }
	return g_ucMenuPageIndex;
}

UCHAR FindMenuPageIndex(UCHAR menuPage)
{
    UCHAR XDATA i=0;
	
    //printf("menu count = %x", (MenuCount));
    
	for(i=0;i<MenuCount;i++)
	{
	      if((tblMenus[i]->CurrentPage) == menuPage)
	      {
	           return i;
	      }
	}
	return 0;
}

void ConfigOsdBlockStarIndexAddr(void)
{
     UCHAR XDATA i;
	 UINT  XDATA Block0MaxSize=0;
	 UINT  XDATA Block1MaxSize=0;
	 UINT  XDATA Block2MaxSize=0;
	 UINT  XDATA Block3MaxSize=0;
	 UINT  XDATA Block4MaxSize=0;
	 
     for(i=0;i<MenuCount;i++)
     {
          switch(tblMenus[i]->OsdBlockId)
          {
                case OsdBlock0:
					if(Block0MaxSize<(tblMenus[i]->XSize*tblMenus[i]->YSize))
					{
					    Block0MaxSize = tblMenus[i]->XSize*tblMenus[i]->YSize;
					}
					break;
				case OsdBlock1:
					if(Block1MaxSize<(tblMenus[i]->XSize*tblMenus[i]->YSize))
					{
					    Block1MaxSize = tblMenus[i]->XSize*tblMenus[i]->YSize;
					}
					break;
				case OsdBlock2:
					if(Block2MaxSize<(tblMenus[i]->XSize*tblMenus[i]->YSize))
					{
					    Block2MaxSize = tblMenus[i]->XSize*tblMenus[i]->YSize;
					}
					break;
				case OsdBlock3:
					if(Block3MaxSize<(tblMenus[i]->XSize*tblMenus[i]->YSize))
					{
					    Block3MaxSize = tblMenus[i]->XSize*tblMenus[i]->YSize;
					}
					break;
				case OsdBlock4:
					if(Block4MaxSize<(tblMenus[i]->XSize*tblMenus[i]->YSize))
					{
					    Block4MaxSize = tblMenus[i]->XSize*tblMenus[i]->YSize;
					}
					break;
					
				default:
					break;
          }
     }
	 if((Block0MaxSize+Block1MaxSize+Block2MaxSize+Block3MaxSize+Block4MaxSize)<OsdIndexRamSize)
	 {
		 g_OsdContrller.block0Size = Block0MaxSize;
		 g_OsdContrller.block1Size = Block1MaxSize;
		 g_OsdContrller.block2Size = Block2MaxSize;
		 g_OsdContrller.block3Size = Block3MaxSize;
		 g_OsdContrller.block4Size = Block4MaxSize;

		 //printf("g_OsdContrller.block0Size = %d", g_OsdContrller.block0Size);
		 //printf("g_OsdContrller.block1Size = %d", g_OsdContrller.block1Size);
		 //printf("g_OsdContrller.block2Size = %d", g_OsdContrller.block2Size);
		 //printf("g_OsdContrller.block3Size = %d", g_OsdContrller.block3Size);
	     //printf("g_OsdContrller.block4Size = %d", g_OsdContrller.block4Size);
		
	     OsdConfigBlockIndexStarAddr(OsdBlock1,Block0MaxSize);
		 OsdConfigBlockIndexStarAddr(OsdBlock2,Block0MaxSize+Block1MaxSize);
		 OsdConfigBlockIndexStarAddr(OsdBlock3,Block0MaxSize+Block1MaxSize+Block2MaxSize);
		 OsdConfigBlockIndexStarAddr(OsdBlock4,Block0MaxSize+Block1MaxSize+Block2MaxSize+Block3MaxSize);
     }
	 else
	 {
	     printfStr("Osd Block Size Error!!!!");
		 printfStr("block all size add > 512");
	 }
	
	 
}

void HideMenu(void)
{
    OsdHide();
	OsdColorChangeSwitch(OFF);
}

void ResetMenuIndex(void)
{
    SetMenuIndex(Osd_RootMenu);
	g_ucMenuPageIndex = 0;
    g_ucOsdEixt = OsdMenu|OsdSource|OsdBrightness|OsdContrast|OsdSaturation|OsdVolume|OsdMode|OsdSys;
}


void SetMenuIndex(UCHAR menuPage)
{
	if(FindMenuPageIndex(menuPage) != g_ucMenuPageIndex) 
	{   
		g_ucMenuPageIndex = FindMenuPageIndex(menuPage);
		g_ucMenuItemIndex = 0;
	}
}
