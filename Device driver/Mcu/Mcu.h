/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Mcu.h
*Version:    　0.2
*Author:       cjinzong
*update:       2010-05-28

*Description:
           这个文件是MCU模块头文件，主要是作为MCU模块的接口文件。
*History:  

************************************************************************/
#ifndef _MCU_H__
#define _MCU_H__

#ifdef _MCU_C_
  #define MCU_EXTERN_   
#else
  #define MCU_EXTERN_ extern
#endif

#define MCU_CLK   27000000ul

#define MCU_CLOCK_27M       //system colock
#ifdef MCU_CLOCK_27M        
#define _1us    2           
#define _1ms    2000  
#define _ms(x)  (x*_1ms)
#define _us(x)  (x*_1us)
#define SetTimer0(x)  {TH0  = (65535 - x) >> 8;TL0  = (65535 - x) & 0xff;}
#define SetTimer1(x)  {TH1  = (65535 - x) >> 8;TL1  = (65535 - x) & 0xff;}	
#define SetTimer3(x)  {T3_CNTL = x;  T3_CNTH = x;}         
#define SetTimer4(x)  {T4_CNTL = x;  T4_CNTH = x;}   
#endif

#define MainInterruptEn()   EA = ON


MCU_EXTERN_ void InitMcu(void);
MCU_EXTERN_ void DisableWatchdog(void);
MCU_EXTERN_ void InitialWatchDog(void);
MCU_EXTERN_ void POS_ClearWatchDog(void);

#endif
