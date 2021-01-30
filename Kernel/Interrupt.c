/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Interrupt.c	  
*Version:      1.0
*update:       2011-12-10
*Description:
  		   系统中断处理。
  		   
*History:  jordan.chen  2011/12/10    1.0    build  this  moudle
******************************************************************************/
#define _INTERRUPT_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Debug.h"
#include "mcu.h"
#include "MsgMap.h"
#include "Ir.h"
#include "delay.h"
#include "AMT_MCU.h"
#include "AMT_Drv.h"
#include "AMT_REG.h"
#include "BT_UartRec.h"
#include "interrupt.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"



void POS_IrqServerExt0(void) interrupt 0 //ext 0  IR  interrupt
{
#ifdef IrDetectEn
    /*通讯协议选择*/
    #if IR_DECODE_MODE == IR_HARDWARE
    #if IR_TYPE == NEC
	g_ucRemoteKeyVal = POS_GetIrKeyVal();
	#endif
	#endif
#endif
}


void POS_IrqServerRec(void) interrupt 4  //Uart Receive interrupt
{
   #ifdef BTEn
   POS_BTUartRec();
   #endif

   #ifdef SpiInitPannelEn
   #ifdef SpiAdjRegEn
   POS_RecUartSpiInfor();
   #endif
   #endif

}

void POS_IrqServerExt2(void) interrupt 8//ext 2  ADC  interrupt
{   
	/*外部中断2设置*/
	EXIF = EXIF&0xEF;	//IE2 = 0

    //adc status
	ADC_INT_STATUS_L =0X00;
    ADC_INT_STATUS_H =0X00;
}



void POS_IrqServerExt3(void) interrupt 9//ext 3
{   
	/*外部中断3设置*/
	EXIF = EXIF&0xDF; //IE3 = 0
}


void POS_IrqServerExt4(void) interrupt 10//ext 4
{   
    /*外部中断4设置*/
	EXIF = EXIF&0xBF;	//IE4 = 0
}



void POS_IrqServerExt5(void) interrupt 11//ext 5  OSD VSYN interrupt
{   
    /*外部中断5设置*/
	EXIF = EXIF&0x7F; //IE5 = 0
}


void POS_IrqServerTimer0(void) interrupt 1  //timer 0
{   
    TR0  = OFF;
	SetTimer0(_us(560)); 
	TR0  = ON;	
}


/***********************************************************
*name:       IrqServerTimer1(void)
*input:      non
*output:     对系统的实时事件进行检测.
*update:     2011-12-23 
*state:      try out

*description:  
         对系统的实时事件进行检测，并置事件标志。
*NOTE:
         这个计数器可以从0-255分频
*history:
************************************************************/
void POS_IrqServerTimer1(void) interrupt 3	   //timer 1
{  
    static UCHAR s_ucContsyncStable = 0; 
    static UCHAR s_ucSysTimer;
	
    TR1  = OFF;
	SetTimer1(_ms(5));
	TR1  = ON;

	s_ucSysTimer++;	
	
	/**********弱信号处理*********/
	POS_VideoProcess(VdLibCmd);

	if(Is5ms(s_ucSysTimer)) 
	{
	   HFZ_LR_BLANK_WR = 0X00;
	}
	
	if(Is10ms(s_ucSysTimer)) 
	{  
	    g_bGetUserInputFlg = 1;
		g_bGetBatteryAdcFlg = 1;
	    g_bGetSignalFlg = 1;   

		#ifdef CarBackEn
		#ifdef CarReversingIODetectEn 
	    g_bGetUserDefFlg = 1;
		#endif
		#endif
	}
	
	if(Is20ms(s_ucSysTimer))
	{   
	    g_bGetColorSysFlg = 1;
		g_bGetMiscFlg = 1;
		g_bGetBTFlg = 1;
	}
	
	if(Is30ms(s_ucSysTimer))
	{
	    g_bGetTimeFlg = 1;
	}

	if(Is100ms(s_ucSysTimer))
	{   
		#ifdef CarBackEn
		#ifdef CarReversingSignalDetectEn
		g_bGetUserDefFlg = 1;   
        #endif
		#endif
	}
	
	/**********图像制式消息处理*********/
	if(g_bGetColorSysFlg)
	{
        #define StableTimes   20

		static UCHAR  s_ucPreSys = PAL;
		UCHAR  ucCurSys;
	
	    if(IsSignalOk()||(0XFF == g_ucColorSys))
		{
		   ucCurSys = GetSignalSys();
		   if(ucCurSys != s_ucPreSys)
	       {
	          s_ucPreSys = ucCurSys;
	          g_ucStableTime = 0;
	       }
		   else
		   {
		       if(g_ucStableTime < StableTimes)
			   {
	               if(++g_ucStableTime == StableTimes)
	               {
	                  switch(ucCurSys)
	                  {
	                      case 0X00:
						  	 ucCurSys = NTSC;
							 break;

						  case 0X01:
						  	 ucCurSys = PAL;
						  	 break;

						  default:
						  	 ucCurSys = PAL;
						  	 break;
	                  }
					 g_ucColorSys = ucCurSys;
	               }
		       }
		   }
		}
		else
		{
		   g_ucStableTime = 0X00;
		}
	}

	#ifdef ColorSysChangeBLOffEn
	#define ContBackLightOff   		10
	#define ContSyncStableTimes       2

	if(g_bBLCtrlEnFlg)
	{   			
	    if(g_bSignalFlg != IsSignalOk())
	    {		
	         if(s_ucContsyncStable <ContSyncStableTimes)
	         {
	             s_ucContsyncStable++;
				 if(s_ucContsyncStable == ContSyncStableTimes)
				 {   	
				      IrqPutstr("bl off\n");
                      #ifdef BacklightEn
					  hw_clrBacklight(); 
					  hw_clrBIASEn();
					  g_bBackLightFlg = OFF;
                      #endif
					  
	                  OSD_1CON &= 0xe1;
					  g_ucContBLOn = ContBackLightOff; 
					  s_ucContsyncStable = 0;
					  g_bSignalFlg = !g_bSignalFlg;
				 }
	         }
		}
		else
		{
		     s_ucContsyncStable = 0;
		}
	}
	#endif
}


