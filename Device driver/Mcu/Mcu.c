/**************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� MCU8052.c
*Version:    ��0.2
*Author:       cjinzong
*Update:       2010-05-28
*State��       allright
 
*Description:
*          ����ļ���ϵͳ��Ƭ�������ã���Ƭ�����������ö�������ļ������ã�
     ϵͳ���жϷ������Ҳ��������ļ��С�
	       1����Ƭ����I/O�ڳ�ʼ�� 
           2��ϵͳʱ�ӵ�����
		   3����������
		   4����ʱ�жϵ�
		   5: ���Ź���
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
*output:     ϵͳIO����Ӧ����ֵ
*update:     2009-03-23
*state:      allright

*description:   
            mcu805x ��IO ��ʼ������:
		    1.�������������
		    2.��������������©������
		    3.ϵͳ�ϵ�Ĭ��ֵ������
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
*output:     ����TIMER�Ĺ�����ʽ�ͳ�ֵ
*update:     2009-03-23  
*state:      allright

*description:   
          mcu805x ��timer ������
		  1.timer �Ĺ�����ʽ
		  2.timer �ĳ�ֵ����
		  3.�����ʵ�����
		  4.reserve

mcu ����Ƶ�ʣ�11.0592MHz   1/11.0592= 0.09us
mcu Ƶ�ʣ�    11.0592MHz   T3 = 256 *(1/11.0592M)  =  23us    256��Ƶ     23us ��1
mcu Ƶ�ʣ�    11.0592MHz   T4 = 1024 *(1/11.0592M) =  92us    1024��Ƶ


mcu Ƶ�ʣ�25MHz   T3 = 1024 *(1/25M) = 40.96us    256*4��Ƶ        40.96us ��1
mcu Ƶ�ʣ�25MHz   T4 = 4096 *(1/25M) = 163.84us   1024*4��Ƶ       163.84us ��1

mcu Ƶ�ʣ�24MHz   T3 = 1024 *(1/24M) = 42.66us    256*4��Ƶ        42.66us ��1
mcu Ƶ�ʣ�24MHz   T4 = 4096 *(1/24M) = 170.66us   1024*4��Ƶ       170.66us ��1

*history:
************************************************************/
void InitialTimer(void)
{
    /*�ر�ʱ��*/
    TR0  = OFF;
	TR1  = OFF;
	
    /*T0 T1 ģʽ����*/
    TMOD = 0x11;              //��ʱ��0��ʽ1��16λ���� ,��ʱ��1 ��ʽ1 16������ʽ
	SetTimer0(_us(560));
	SetTimer1(_ms(5));
    SetTimer3(0);
	SetTimer4(0);

	/*T0 T1�жϿ���*/
    ET0  = OFF;           //TO�ж�����
    ET1  = ON;		     //T1�ж�����

	/*��ʱ��/��������������*/ 
    TR0  = OFF;
	TR1  = ON;
}

/***********************************************************
*name:       SetT2BaudRate(Brate)
*input:      Brate ������
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     �����ʵ�����,ע�� ������ʱ������T2��������
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
		     �����ʵ�����,ע�� ������ʱ������T2��������
*history:
************************************************************/
void InitialSerialPort(void)
{
    TR2  = OFF;
	
	SetT2BaudRate(57600); 
	TR2  = ON;  
    ET2  = OFF;		     //T2�жϽ�ֹ
    
	TI = 0;
	RI = 0;
	
	/*�����ж�����*/
	ES   = OFF;		     // Serial  interrupt disable
}



/***********************************************************
*name:       DisableWatchdog()
*input:      non
*output:     
*update:     2009-03-23  
*state:      allright

*description:   
		     ��ֹ���Ź�
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
		     ���Ź�����
*history:
************************************************************/
void InitialWatchDog(void)
{
    /*watchdog Setting*/ 
	WDT_UPDATE_EN = 0X55;
    MCU_CLK_REG = 0x03;      // 4��Ƶ  
    WDT_COUNTH  = 0xFF;     // 4��Ƶ  65535* 85.36us = 5.6s  
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
		     ������Ź�����
*history:
************************************************************/
void POS_ClearWatchDog(void)
{
    WDT_UPDATE_EN = 0X55;
    WDT_CLR    = 0xbb;            // ��WatchDog�������壬5.6s ��λ��ι��  
  	WDT_CLR    =~WDT_CLR;
    WDT_CLR    = 0x00; 
	WDT_UPDATE_EN = 0XAA;
}



/***********************************************************
*name:     	Initial805xInterrupt()
*input:      non
*output:     ����ϵͳ���ж�ʹ��
*update:     2009-03-23   
*state:      allright

*description:   
            mcu805x ���ж����ó�ʼ��
    		1.�ⲿ�ж����� 
			2.timer�ж�����
			3.�����ж����� 
			4.reserve

*history:
************************************************************/
void InitialExtInterrupt(void)
{
	IP = 0X00; 
	        
    /*�ⲿ�ж�0����*/
    IT0 = 1;             //�ⲿ�ж�����1���ش���,�˱��ش����ᵼ��IE1 = 1.(8118 ERROR)
    IE0 = 0;             //һ�ϵ���IT0 ���� IE0 = 1

	/*�ⲿ�ж�2����*/
	EXIF = EXIF&0xEF;	//IE2 = 0

	/*�ⲿ�ж�3����*/
	EXIF = EXIF&0xDF; //IE3 = 0

	/*�ⲿ�ж�4����*/
	EXIF = EXIF&0xBF;	//IE4 = 0
	
    /*�ⲿ�ж�5����*/
	EXIF = EXIF&0x7F; //IE5 = 0

    /*�����ⲿ�ж�2���ȼ�*/
	PX2 = 0; //��Ҫʹ���ⲿ�ж�2����Ҫ��Ϊ1

	/*�����ⲿ�ж�3���ȼ�*/
	PX3 = 0; //��Ҫʹ���ⲿ�ж�3����Ҫ��Ϊ1
	
	/*�����ⲿ�ж�4���ȼ�*/
	PX4 = 0; //��Ҫʹ���ⲿ�ж�4����Ҫ��Ϊ1

	/*�����ⲿ�ж�5���ȼ�*/
	PX5 = 0; //��Ҫʹ���ⲿ�ж�5����Ҫ��Ϊ1

	
    /*�ⲿ�жϿ���*/
	#ifdef IrDetectEn
    EX0 = ON;          //IR  interrupt enable
    #else
	EX0 = OFF;          //IR  interrupt disable
	#endif
	
	EX2 = OFF;		   //ADC  interrupt enable
    EX3 = OFF;
	EX4 = OFF;
    EX5 = OFF;        //OSD VSYN interrupt enable

    /*���ж�DISABLE*/
	EA  = OFF;          
}



/***********************************************************
*name:       InitMcu(void);
*input:      non
*output:     ��ʼ��MCU ��IO TIMER INT
*update:     2009-03-23   
*state:      allright

*description:   805x�ĳ�ʼ��
                1.IO��ʼ��
				2.������/��ʱ�������ڳ�ʼ��
				3.�ж�ʹ�ܳ�ʼ��
				4.��ʼ������
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
	TERM_Init();
	printfStr("-----------------------------------------------------------\n");
	printfStr("Mcu init ok!\n");
}
