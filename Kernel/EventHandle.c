/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� ArkRun.c
*Version:    ��0.1
*Author:       cjinzong
*update:       2011-11-26

*Description:
              ϵͳ��ģ�������߼���
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
          �����û���Ϣ����Ҫ�ǰ�����ң������
          ��Ҫ���Ǵ˴���OSD�Ľӿڣ����ҿ���ʵ��OSD�ķ���л���
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
          �����źŵ���Ϣ����Ҫ�д����źŵ����źţ������źŵ����ź�
          ��������Ϣ���ź����ȼ���Ϣ �ȵȡ���
*history:
                                
************************************************************/
void  SignalMsgHandle(MSG curMsg)
{
    if(curMsg == MSG_SIGNAL_OK)
    { 	  
		  /*��ʾ���ź�*/
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
	      /*��ʾ���ź�*/
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
         ����ͼ��Ч����Ϣ����Ҫ�Ǹ��ݵ�ǰͨ����ͼ����ʽ������
         ��Ӧ��ͼ������� 
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
         ����ϵͳ����ʱ����Ϣ����Ҫ�� ��ʱ���ػ�����ʱ˯��ģʽ��
         
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
         ����ϵͳ��ص�ʵʱ��ѹ��Ϣ��
         
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
        �����û��Զ�����Ϣ
         
*history:
                                
************************************************************/
void  UserDefinedMsgHandle(MSG curMsg)
{
    /*�ػ�״̬���޵���*/
    if(MSG_CAR_POF_GO_AHEAD ==  curMsg)
    {
         printfStr("MSG_CAR_POF_GO_AHEAD");
		 g_sysSetting.Car.DetecMode = AV_CAR_NO_SIGANL; 
         g_sysSetting.Car.status = CAR_POF_GO_AHEAD;
		 g_sysSetting.Video.curSource = g_sysSetting.Car.RemberSource;
		 SetPowerOn();
         ExectComd(COMD_Power); 
    }

	/*����״̬���޵���*/
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

	/*�ػ�״̬�µ���*/
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

	/*����״̬�µ���*/
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
		
	/*�ϵ�״̬����*/
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
        �����������ӡ��ͷţ��������Ҷ���Ϣ��
         
*history:
                                
************************************************************/
#ifdef BTEn
void  BTMsgHandle(MSG curMsg)
{
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
}
#endif


/***********************************************************
*name:       MiscMsgHandle(MSG curMsg)
*input:      curMsg
*output:     void 

*update:     2011-11-27 
*state:      allright

*description:   
        ����һЩ���÷������Ϣ��
         
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

	#ifdef UartTerminal
	if(MSG_SERIAL == curMsg){
		TERM_Handler();
	}
	#endif  
}
