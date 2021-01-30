/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Global.c
*Version:    　0.1
*Author:       cjinzong
*update:       2010-05-23

*Description:
             主要包括一些系统初始化函数和一些全局又不好分类的函数。
*History:  

************************************************************************/
#define _GLOBAL_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "mcu.h"
#include "videoProc.h"
#include "Debug.h"
#include "sysWorkPara.h"
#include "MsgMap.h"
#include "Osd_menu.h"
#include "Flash.h"
#include "E2prom.h"
#include "interrupt.h"
#include "Ir.h"
#include "sysPower.h"
#include "ConfigLcdPara.h"
#include "AMT_MCU.h"
#include "AMT_Drv.h"
#include "AMT_Reg.h"
#include "AdcKeyPad.h"
#include "WT5700.h"
#include "Kt0803l.h"

/***********************************************************
*name:       ConfigMcuCtrl(void)
*input:      void
             
*output:     void
*update:     2011-11-27 
*state:      allright

*description:   
          配置为MCU控制模块
*history:
                                
************************************************************/
void ConfigMcuCtrl(void)
{
    ConfigCrtlMode(MCU);
	ENH_PLL = 0X20;
}


/***********************************************************
*name:       InitGlobalVariables(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           初始化全局变量。
*history:
                                
************************************************************/
void InitGlobalVariables(void)
{
    UINT XDATA i;

    for(i = 0; i < 0x800; i++)
    {
       XBYTE[i] = 0xff;
    }
	
    printfStr("InitGlobalVariables\n");
    
    g_ucColorSys = 0XFF;
    g_ucPreColorSys = 0XFF;
    g_ucRemoteKeyVal = 0XFF;
    g_ucContBufSecond = 0X00;
    g_ucContNoSignalSecond = 0X00;
    g_ucFactoryMenuItemIndex = 0X00;
    g_ucBatteryAdcLev = BatterAdc_Lev0;
    g_ucSelKeyDevice =ADC_KEY;
	g_ucStableTime = 0X00;
	g_ucContBLOn = 0X00;
    g_bVideoChSelOk = FALSE;
    g_bSignalFlg = FALSE;
	g_bBLCtrlEnFlg = FALSE;
    g_bReleaseAdcKeyFlg = FALSE;
    g_bLogoFlg = FALSE;
    PreKey.KeyVal = NULL_KEY;
    PreKey.KeyMsg = MSG_NULL;
    PreKey.Holdtime = NULL_TIME;
    PreKey.Status = KEYRELEASE;
    CurrentKey.KeyVal = NULL_KEY;
    CurrentKey.KeyMsg = MSG_NULL;
    CurrentKey.Holdtime = NULL_TIME;
    CurrentKey.Status = KEYRELEASE;
    g_ucOsdEixt = OsdMenu|OsdSource|OsdBrightness|OsdContrast|OsdSaturation|OsdVolume|OsdMode|OsdSys;
    ClrCarReversingEn();
    ClrFactoryEn();
    SetMenuIndex(Osd_RootMenu); 
}

/***********************************************************
*name:       PrjVersionMsg(void)
*input:      void 
*output:     void
*update:     2011-11-27 
*state:      allright

*description:   
          打印工程信息，主要工程的编译时间和工程名和软件版本号。
*history:
                                
************************************************************/
void PrjVersionMsg(void)
{
    printfStr("\r\nLib Version :\n");
    printfStr(GeLibVersion());
    printfStr("\r\nLib create date :\n");
    printfStr(GetLibCreatDate());
    printfStr("\r\nLib create time :\n");
    printfStr(GetLibCreatTime());
    printfStr("Inital end.\n");
}

/***********************************************************
*name:       InitExtDevices(void)
*input:      void 
*output:     void
*update:     2011-11-27 
*state:      allright

*description:   
        初始化外围设备，例如tuner,声音的控制，电源指示灯的状态。
*history:
                                
************************************************************/
void InitExtDevices(void)
{
    //Led
    
    //Tuner
    
    //Aduio

   //Spi Pannel
   #ifdef SpiInitPannelEn
   SPI_TM035KDH08_Pannel_Initial(_24BIT_RGB_DEN,0x75);//interface:24BIT_RGB_DEN(default),default VcomVal:0x75
   #endif

   #ifdef CpuInitPannelEn
   CPU_HX8357C_16Bit_Pannel_Initial();
   #endif

   //Key Device
   #ifdef KeyDetectEn
   
   /*
    note:此函数是为了兼容I2C KEY与ADC KEY按键接口，
    若两种类型按键不是统一接口，需屏蔽此函数
   */
   
   //POS_SelectKeyDevice();
   #endif

   #ifdef FmSendEn
   //Kt0803l
   #if(FM_CHIP == KT0803l)
   KT_TXPreInit();
   KT_TXInit();
   KT_TXInitTune(g_sysSetting.SendRf.SendRfVal);
   #endif
   #endif
   
   #ifdef IrABCtrlEn
   SetIRABSwitch(g_sysSetting.IRAB.IRABVal);
   #endif
   
   printfStr("InitExtDevices\n");
}




/***********************************************************
*name:       InitSysWorkVariable(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           初始化系统工作变量。
*history:
                                
************************************************************/

void InitSysWorkVariable(void)
{  
     printfStr("**********InitSysWorkVariable*********\n");

	 InitGlobalVariables();
		 
	 #ifdef FlashEn
	 AutoDetectFlashType();
	 #endif

     if(ReadSetting())
     {
         g_sysSetting.Video.curSource = g_sysSetting.Car.RemberSource;
     }
	 else
	 {
	     g_sysSetting.Car.RemberSource =  g_sysSetting.Video.curSource;
	 }
	 g_sysSetting.Car.DetecMode = AV_CAR_NO_SIGANL;
	 g_sysSetting.Car.status = CAR_PON_GO_AHEAD;
}


/***********************************************************
*name:       InitSystem(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           初始化系统。
*history:
                                
************************************************************/
void InitSystem(void)
{	
	ConfigMcuCtrl();
	
	InitMcu();

	InitSysWorkVariable(); 

	InitExtDevices();
		
	InitARKChip();
	
	PrjVersionMsg();

	GetProCompielTime();
	
    MainInterruptEn();
}


