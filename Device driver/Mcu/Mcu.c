/**************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 MCU8052.c
*Version:    　0.2
*Author:       cjinzong
*Update:       2010-05-28
*State：       allright
 
*Description:
*          这个文件是系统单片机的设置，单片机的所有设置都在这个文件中设置，
     系统的中断服务程序也是在这个文件中。
	       1：单片机的I/O口初始化 
           2：系统时钟的设置
		   3：串口设置
		   4：定时中断等
		   5: 看门狗。
*History:
*
****************************************************************/
#define _MCU_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Debug.h"
#include "AMT_MCU.h"
#include "AMT_Drv.h"
#include "AMT_Reg.h"
#include "mcu.h"
#include "ConfigLcdPara.h"



/***********************************************************
*name:     	 InitialPPort()
*input:      non
*output:     系统IO的相应设置值
*update:     2009-03-23
*state:      allright

*description:   
            mcu805x 的IO 初始化函数:
		    1.输入输出的设置
		    2.开上拉和下拉或开漏的设置
		    3.系统上电默认值得设置
		    4.reserve

*history:
************************************************************/
void InitialPPort(void)
{
   	#ifdef BacklightEn
	#if BACKLIGHT_CTRL_MODE == DC_PWM0_CTRL
    SelPWM0 |= (_BIT0|_BIT1);	 
    SelPWM0 &=~_BIT2;
	#endif

	#if BACKLIGHT_CTRL_MODE == DC_PWM1_CTRL
    SelPWM1 |= (_BIT4|_BIT5);	 
    SelPWM1 &=~_BIT6;
	#endif

	#if BACKLIGHT_CTRL_MODE == DC_PWM2_CTRL
    SelPWM2 |= (_BIT0|_BIT1);	 
    SelPWM2 &=~_BIT2;
	#endif

	#if BACKLIGHT_CTRL_MODE == DC_PWM3_CTRL
    SelPWM3 |= (_BIT4|_BIT5);	 
    SelPWM3 &=~_BIT6;
	#endif

	hw_clrBacklight(); 
    g_bBackLightFlg = OFF;
	hw_clrBIASEn();
    #endif
   
    #ifdef BuzzerEn
    hw_turnOffBuzzer();
    #endif

    #ifdef AudioCtrlEn
    SetAudioMute();
    #endif

    #ifdef UartPrintfEn  
    SetUartPrint();
    #endif
}



/***********************************************************
*name:     	Initial805xTimer()
*input:      non
*output:     设置TIMER的工作方式和初值
*update:     2009-03-23  
*state:      allright

*description:   
          mcu805x 的timer 的设置
		  1.timer 的工作方式
		  2.timer 的初值设置
		  3.波特率的设置
		  4.reserve

mcu 晶振频率：11.0592MHz   1/11.0592= 0.09us
mcu 频率：    11.0592MHz   T3 = 256 *(1/11.0592M)  =  23us    256分频     23us 加1
mcu 频率：    11.0592MHz   T4 = 1024 *(1/11.0592M) =  92us    1024分频


mcu 频率：25MHz   T3 = 1024 *(1/25M) = 40.96us    256*4分频        40.96us 加1
mcu 频率：25MHz   T4 = 4096 *(1/25M) = 163.84us   1024*4分频       163.84us 加1

mcu 频率：24MHz   T3 = 1024 *(1/24M) = 42.66us    256*4分频        42.66us 加1
mcu 频率：24MHz   T4 = 4096 *(1/24M) = 170.66us   1024*4分频       170.66us 加1

*history:
************************************************************/
void InitialTimer(void)
{
    /*关闭时钟*/
    TR0  = OFF;
	TR1  = OFF;
	
    /*T0 T1 模式设置*/
    TMOD = 0x11;              //定时器0方式1，16位计数 ,定时器1 方式1 16计数方式
	SetTimer0(_us(560));
	SetTimer1(_ms(5));
    SetTimer3(0);
	SetTimer4(0);

	/*T0 T1中断开关*/
    ET0  = OFF;           //TO中断允许
    ET1  = ON;		     //T1中断允许

	/*定时器/计数器开关设置*/ 
    TR0  = OFF;
	TR1  = ON;
}

/***********************************************************
*name:       SetT2BaudRate(Brate)
*input:      Brate 波特率
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     波特率的设置,注意 波特率时钟是由T2来产生。
*history:
************************************************************/
void SetT2BaudRate(ULONG Brate)  
{
    T2CON   = 0x30;      	 //27MHZ  TF2,EXF2,RCLK,TCLK,EXEN2,TR2,C/T2,CP/RL2  
    SCON    = 0x50;

	#ifdef MCU_CLOCK_27M
	RCAP2H  = (UCHAR)(((65536-(MCU_CLK/(Brate*32)))>>8)&0xff);
	RCAP2L  = (UCHAR)((65536-(MCU_CLK/(Brate*32)))& 0xff);
	#endif
}

/***********************************************************
*name:       InitialSerialPort()
*input:      non
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     波特率的设置,注意 波特率时钟是由T2来产生。
*history:
************************************************************/
void InitialSerialPort(void)
{
    TR2  = OFF;
	
	SetT2BaudRate(57600); 
	TR2  = ON;  
    ET2  = OFF;		     //T2中断禁止
    
	TI = 0;
	RI = 0;
	
	/*串口中断设置*/
	ES   = OFF;		     // Serial  interrupt disable
}



/***********************************************************
*name:       DisableWatchdog()
*input:      non
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     禁止看门狗
*history:
************************************************************/
void DisableWatchdog(void)
{
    /*watchdog Setting*/ 
	WDT_UPDATE_EN = 0X55;
    WDT_RSTEN   = DISABLE;   // reset mcu disable
    WDT_UPDATE_EN = 0XAA;
}



/***********************************************************
*name:       InitialWatchdog()
*input:      non
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     看门狗设置
*history:
************************************************************/
void InitialWatchDog(void)
{
    /*watchdog Setting*/ 
	WDT_UPDATE_EN = 0X55;
    MCU_CLK_REG = 0x03;      // 4分频  
    WDT_COUNTH  = 0xFF;     // 4分频  65535* 85.36us = 5.6s  
    WDT_COUNTL  = 0xFF; 
    WDT_RSTEN   = DISABLE;   // reset mcu enable
    WDT_UPDATE_EN = 0XAA;
}



/***********************************************************
*name:       POS_ClearWatchDog()
*input:      non
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     清除看门狗设置
*history:
************************************************************/
void POS_ClearWatchDog(void)
{
    WDT_UPDATE_EN = 0X55;
    WDT_CLR    = 0xbb;            // 清WatchDog，若不清，5.6s 复位。喂狗  
  	WDT_CLR    =~WDT_CLR;
    WDT_CLR    = 0x00; 
	WDT_UPDATE_EN = 0XAA;
}



/***********************************************************
*name:     	Initial805xInterrupt()
*input:      non
*output:     设置系统的中断使能
*update:     2009-03-23   
*state:      allright

*description:   
            mcu805x 的中断设置初始化
    		1.外部中断设置 
			2.timer中断设置
			3.串口中断设置 
			4.reserve

*history:
************************************************************/
void InitialExtInterrupt(void)
{
	IP = 0X00; 
	        
    /*外部中断0设置*/
    IT0 = 1;             //外部中断请求1边沿触发,此边沿触发会导致IE1 = 1.(8118 ERROR)
    IE0 = 0;             //一上电由IT0 引起 IE0 = 1

	/*外部中断2设置*/
	EXIF = EXIF&0xEF;	//IE2 = 0

	/*外部中断3设置*/
	EXIF = EXIF&0xDF; //IE3 = 0

	/*外部中断4设置*/
	EXIF = EXIF&0xBF;	//IE4 = 0
	
    /*外部中断5设置*/
	EXIF = EXIF&0x7F; //IE5 = 0

    /*设置外部中断2优先级*/
	PX2 = 0; //若要使用外部中断2，则要置为1

	/*设置外部中断3优先级*/
	PX3 = 0; //若要使用外部中断3，则要置为1
	
	/*设置外部中断4优先级*/
	PX4 = 0; //若要使用外部中断4，则要置为1

	/*设置外部中断5优先级*/
	PX5 = 0; //若要使用外部中断5，则要置为1

	
    /*外部中断开关*/
	#ifdef IrDetectEn
    EX0 = ON;          //IR  interrupt enable
    #else
	EX0 = OFF;          //IR  interrupt disable
	#endif
	
	EX2 = OFF;		   //ADC  interrupt enable
    EX3 = OFF;
	EX4 = OFF;
    EX5 = OFF;        //OSD VSYN interrupt enable

    /*总中断DISABLE*/
	EA  = OFF;          
}



/***********************************************************
*name:       InitMcu(void);
*input:      non
*output:     初始化MCU 的IO TIMER INT
*update:     2009-03-23   
*state:      allright

*description:   805x的初始化
                1.IO初始化
				2.计数器/定时器，串口初始化
				3.中断使能初始化
				4.初始化串口
				4.reserve
*history:
                                
************************************************************/
void InitMcu(void)
{
	InitialPPort();
	InitialTimer();
	InitialSerialPort();
	InitialWatchDog();
	InitialExtInterrupt();
	printfStr("Mcu init ok!\n");
}
