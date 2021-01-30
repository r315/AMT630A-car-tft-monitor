/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� SysPower.C
*Version:    ��0.1
*Author:       Jordan.chen
*update:       2011-12-07

*Description:
           ���ļ�Ϊϵͳ��Դ����ģ�顣
*History:  

************************************************************************/
#define _POWER_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "configlcdpara.h"
#include "Debug.h"
#include "sysWorkPara.h"
#include "Videoproc.h"
#include "Delay.h"
#include "interrupt.h"
#include "AMT_Drv.h"
#include "AMT_REG.h"
#include "MsgMap.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "sysPower.h"
#include "Ir.h"



/****************************************************************************
*name:   PowerOnSystem(void)
*input:  void              
*output: void  

*description:
      ϵͳ����������ִ�д˺��������ϵͳ�Ѿ����뿪��״̬������ʾ������

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
BOOL PowerOnSystem(void)
{	
    printfStr("PowerOnSystem\n");

	#ifdef PowerLedEn
	hw_setGreenLEDOn();
	hw_setRedLEDOff();
	#endif

	SetPowerOn();
	
	#ifdef AudioCtrlEn
	SetAudioMute(); 	
	SelAudioInputSource(g_sysSetting.Video.curSource);
	#endif

	ExitLowPowerMode();

	#ifdef CarBackEn
	#ifdef CarReversingSignalDetectEn
	SelVideoInputSource(INPUT_CAMERA_Car);
	DelayMs(200);
	if(IsSignalOk())
	{
	   g_sysSetting.Car.DetecMode = PON_CAR_SIGNAL_OK;
	}
	else
	{  
	   SelVideoInputSource(g_sysSetting.Video.curSource);
       DelayMs(200);

	   if(IsSignalOk())
       {
         g_sysSetting.Car.DetecMode = AV_SIGNAL_OK; 
       }
	   
	   #ifndef LogoEn 
	   #ifdef NoSignalBLOffEn
	   if(IsSignalOk())
	   {
		  TurnOnBackLight();
	   }
	   else
	   {
	      EnterLowPowerMode();
	   }
	   #else
	   TurnOnBackLight();
	   #endif	//	   #ifdef NoSignalBLOffEn
	   #endif  //	   #ifndef LogoEn 
	}
	#endif  //	#ifdef CarReversingSignalDetectEn
	
	#ifdef CarReversingIODetectEn
	SelVideoInputSource(g_sysSetting.Video.curSource);
	if(hw_getCarBackPinStatus() == hw_setCarBackAheadStatus)
	{ 
	   DelayMs(200);
	   #ifndef LogoEn 
	   #ifdef NoSignalBLOffEn
	   if(IsSignalOk())
	   {
		  TurnOnBackLight();
	   }
	   else
	   {
	      EnterLowPowerMode();
	   }
	   #else
	   TurnOnBackLight();
	   #endif	//#ifdef NoSignalBLOffEn
	   #endif  //#ifndef LogoEn 
	}
	#endif  //	#ifdef CarReversingIODetectEn
	
	#else //#ifndef CarBackEn
	SelVideoInputSource(g_sysSetting.Video.curSource);
	DelayMs(200);
	
	#ifndef LogoEn 
	#ifdef NoSignalBLOffEn
	if(IsSignalOk())
	{
	   TurnOnBackLight();
	}
    else
    {
      EnterLowPowerMode();
    }
	#else
	TurnOnBackLight();
	#endif	//#ifdef NoSignalBLOffEn
	#endif //	#ifndef LogoEn 
	#endif  // 	#ifdef CarBackEn
	
	g_sysSetting.Car.status = CAR_PON_GO_AHEAD;
	g_bSignalFlg = IsSignalOk();
    g_bBLCtrlEnFlg = TRUE;
	g_ucRemoteKeyVal = IR_NULL_KEY; 
	
	return 1;
}


/****************************************************************************
*name:   PowerOffSystem(void)
*input:  void              
*output: void  

*description:
      ϵͳ�ػ���������ʾ�ػ�ʱ��Ҫִ�ж�����

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
BOOL PowerOffSystem(void)
{	 
    printfStr("PowerOffSystem\n");
	
    #ifdef PowerLedEn
	hw_setRedLEDOn();
	hw_setGreenLEDOff();
	#endif

	SetPowerOff();
	
	#ifdef AudioCtrlEn
	SetAudioMute(); 
	#endif
		
	TurnOffBackLight(); 	
	SaveSetting();
	TurnOffDevicePower(g_sysSetting.Video.curSource);   
	EnterLowPowerMode();
	
	HideMenu();
	DelayMs(500);	
	g_ucRemoteKeyVal = IR_NULL_KEY;
	return 1;
}
