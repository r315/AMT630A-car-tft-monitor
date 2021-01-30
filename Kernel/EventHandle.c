/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 ArkRun.c
*Version:    　0.1
*Author:       cjinzong
*update:       2011-11-26

*Description:
              系统各模块运行逻辑。
*History:  

************************************************************************/
#define _EVENT_HANDLE_C_

/* include head files*/
#include "DataType.h"
#include "systemConfig.h"
#include "Global.h"
#include "MsgMap.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "configLcdPara.h"
#include "EventHandle.h"
#include "Debug.h"
#include "Delay.h"
#include "VideoProc.h"
#include "sysPower.h" 
#include "AMT_REG.h"
#include "AMT_Drv.h"
#include "AMT_MCU.h"



/***********************************************************
*name:       OsdMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
          处理用户消息，主要是按键和遥控器。
          需要考虑此处是OSD的接口，并且可以实现OSD的风格切换。
*history:
                                
************************************************************/
void  OsdMsgHandle(MSG curMsg)
{
    UCHAR ucComd= COMD_Nothing;
	
    ucComd = KeyMsgProcess(curMsg);	
	
	#ifdef QuickParaSaveEn 
	if(ucComd!= COMD_Nothing)
	{
      g_sysSetting.Osd.storageTime = 0;
	}
	#endif//QuickParaSaveEn

	#ifdef NoSignalPowerOffEn
	if(ucComd!= COMD_Nothing)
	{
       g_ucContNoSignalSecond = 0X00;
	}
	#endif
	
    MenuProcessKey(ucComd);
}

/***********************************************************
*name:       SignalMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
          处理信号的消息，主要有从无信号到有信号，从有信号到无信号
          产生的消息，信号优先级消息 等等。。
*history:
                                
************************************************************/
void  SignalMsgHandle(MSG curMsg)
{
    if(curMsg == MSG_SIGNAL_OK)
    { 	  
		  /*表示有信号*/
	      printfStr("MSG_SIGNAL_OK");

	      #ifdef NoSignalEn
	      ExectComd(COMD_ClearNoSignal); 
	      #endif//NoSignalEn

          #ifdef LogoEn 
          #if (LOGO_DISP_MODE == NOSIGNAL_DISP_LOGO)
          ExectComd(COMD_ClearLogo); 
          #endif
          #endif

		  #ifdef AudioCtrlEn
		  OpenAudio();   
	      #endif//AudioCtrlEn 

		  if(IsPowerOn())
		  {
		     MenuProcessKey(COMD_ShowSource);
		  }
    }

	
	if(curMsg == MSG_NO_SIGNAL)
	{
	      /*表示无信号*/
		  printfStr("MSG_NO_SIGNAL");
		  
		  #ifdef NoSignalSnowEn
		  ExectComd(COMD_RedrawSnow); 
		  #endif

          #ifdef LogoEn 
          #if (LOGO_DISP_MODE == NOSIGNAL_DISP_LOGO)
          ExectComd(COMD_RedrawLogo); 
          #endif
          #endif

		  #ifdef AudioCtrlEn
	      SetAudioMute();
	      #endif//AudioCtrlEn

		  if(IsPowerOn())
		  {
		     MenuProcessKey(COMD_ShowSource);
		  }	 
	}
}

/***********************************************************
*name:       ColorSysMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
         处理图像效果消息，主要是根据当前通道的图像制式来配置
         相应的图像参数。 
*history:
                                
************************************************************/
void  ColorSysMsgHandle(MSG curMsg)
{
     if(curMsg == MSG_CONFIG_COLOR_SYS)
     {
		 ConfigColorSysDynPara(g_sysSetting.Video.colorSys); 
     }
}

/***********************************************************
*name:       TimeMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
         处理系统设置时间消息，主要有 定时开关机，定时睡眠模式。
         
*history:
                                
************************************************************/
void  TimeMsgHandle(MSG curMsg)
{
			
    if(MSG_OSD_EXIT == curMsg) 
    {   
        printfStr("MSG_OSD_EXIT");
        MenuProcessKey(COMD_OsdExit);
    }

	if(MSG_OSD_STORAGE == curMsg) 
    {   
        printfStr("MSG_OSD_STORAGE");
        MenuProcessKey(COMD_OsdStorage);
    }
		
	if(MSG_NOSIGNALPOWEROFF == curMsg) 
    {   
        printfStr("MSG_NOSIGNALPOWEROFF");
        MenuProcessKey(COMD_Power);
    }
}


/***********************************************************
*name:       BatteryAdcMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
         处理系统电池的实时电压消息。
         
*history:
                                
************************************************************/
void  BatteryAdcMsgHandle(MSG curMsg)
{
    if(MSG_BATTERYADC == curMsg) 
    {
        printfStr("MSG_BATTERYADC");
        MenuProcessKey(COMD_BatteryAdc);
    }
}


/***********************************************************
*name:       UserDefinedMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
        处理用户自定义消息
         
*history:
                                
************************************************************/
void  UserDefinedMsgHandle(MSG curMsg)
{
    /*关机状态下无倒车*/
    if(MSG_CAR_POF_GO_AHEAD ==  curMsg)
    {
         printfStr("MSG_CAR_POF_GO_AHEAD");
		 g_sysSetting.Car.DetecMode = AV_CAR_NO_SIGANL; 
         g_sysSetting.Car.status = CAR_POF_GO_AHEAD;
		 g_sysSetting.Video.curSource = g_sysSetting.Car.RemberSource;
		 SetPowerOn();
         ExectComd(COMD_Power); 
    }

	/*开机状态下无倒车*/
	if(MSG_CAR_PON_GO_AHEAD ==  curMsg)
    {
         printfStr("MSG_CAR_PON_GO_AHEAD");
		 g_sysSetting.Car.DetecMode = AV_CAR_NO_SIGANL; 
         g_sysSetting.Car.status = CAR_PON_GO_AHEAD;
		 g_sysSetting.Video.curSource = g_sysSetting.Car.RemberSource; 
		 SetCarReversingEn();
		 MenuProcessKey(COMD_SelSource);
		 ClrCarReversingEn();
		 if(IsSignalOk())
		 {
		    g_sysSetting.Car.DetecMode = AV_SIGNAL_OK; 
		 }
    }

	/*关机状态下倒车*/
	if(MSG_CAR_POF_REVERSING ==  curMsg)
    {
         printfStr("MSG_CAR_POF_REVERSING");
         g_sysSetting.Video.curSource = INPUT_CAMERA_Car;
		 g_sysSetting.Car.DetecMode = CAR_SIGNAL_OK;
         g_sysSetting.Car.status = CAR_POF_REVERSING;
         SetCarReversingEn();
         ExectComd(COMD_SelSource);
		 ClrCarReversingEn();
		 g_sysSetting.Osd.dispTime= CurrentMenu->TimeOut;
    }

	/*开机状态下倒车*/
	if(MSG_CAR_PON_REVERSING ==  curMsg)
    {
         printfStr("MSG_CAR_PON_REVERSING");
         g_sysSetting.Video.curSource = INPUT_CAMERA_Car;
		 g_sysSetting.Car.DetecMode = CAR_SIGNAL_OK;
         g_sysSetting.Car.status = CAR_PON_REVERSING;
		 SetCarReversingEn();
         MenuProcessKey(COMD_SelSource);
		 ClrCarReversingEn();
	}
		
	/*上电状态倒车*/
	if(MSG_PON_REVERSING ==  curMsg)  
	{  
        printfStr("MSG_PON_REVERSING");
	    g_sysSetting.Video.curSource = INPUT_CAMERA_Car;
	    g_sysSetting.Car.DetecMode = CAR_SIGNAL_OK;
        g_sysSetting.Car.status = CAR_PON_REVERSING;
		SetCarReversingEn();
	    MenuProcessKey(COMD_ShowSource);
		ClrCarReversingEn();
	    TurnOnBackLight();
    }
}



/***********************************************************
*name:       BTMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
        处理蓝牙连接、释放，接听、挂断消息。
         
*history:
                                
************************************************************/
void  BTMsgHandle(MSG curMsg)
{
    #ifdef BTEn
  	if(MSG_BT_CONN ==  curMsg)
	{
	    printfStr("MSG_BT_CONN");
		g_bBTConnFlg = FALSE;
	    ExectComd(COMD_BTConn);
	}

	if(MSG_BT_DISC ==  curMsg)
	{
	    printfStr("MSG_BT_DISC");
		g_bBTDiscFlg = FALSE;
	    ExectComd(COMD_BTDisc);
	}

	if(MSG_BT_CALLERID ==  curMsg)
	{
	    printfStr("MSG_BT_CALLERID");
		g_bBTCinFlg = FALSE;
	    ExectComd(COMD_BTCallerID);
	}

	if(MSG_BT_CALLERDROP ==  curMsg)
	{
	    printfStr("MSG_BT_CALLERDROP");
		g_bBTCdropFlg = FALSE;
	    ExectComd(COMD_BTCallerDrop);
	}
	#endif
}



/***********************************************************
*name:       MiscMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
        处理一些不好分类的消息。
         
*history:
                                
************************************************************/
void  MiscMsgHandle(MSG curMsg)
{   
    if(MSG_TURNON_BACKLIGHT == curMsg) 
    {
        printfStr("MSG_TURNON_BACKLIGHT");		
        ExectComd(COMD_TurnOnBacklight);
    }
	
	if(MSG_TURNOFF_BACKLIGHT == curMsg) 
    {   
        printfStr("MSG_TURNOFF_BACKLIGHT");
        ExectComd(COMD_TurnOffBacklight);
    }  
}
