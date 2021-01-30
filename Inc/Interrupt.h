/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Interrupt.h
*Version:    　0.1
*Author:       cjinzong
*update:       2012-01-09

*Description:
            
*History:
************************************************************************/
#ifndef _INTERRUPT_H__
#define _INTERRUPT_H__

#ifdef _INTERRUPT_C_
#define _IRQ_EXTERN_  
#else
#define _IRQ_EXTERN_  extern
#endif


//此定时器为5ms 为一个基准。
#define Is5ms(timer)   ((timer%TIME_5MS) == 0)
#define Is10ms(timer)  ((timer%TIME_10MS) == 0)
#define Is15ms(timer)  ((timer%TIME_15MS) == 0)
#define Is20ms(timer)  ((timer%TIME_20MS) == 0)
#define Is25ms(timer)  ((timer%TIME_25MS) == 0)
#define Is30ms(timer)  ((timer%TIME_30MS) == 0)
#define Is35ms(timer)  ((timer%TIME_35MS) == 0) 
#define Is50ms(timer)  ((timer%TIME_50MS) == 0) 
#define Is100ms(timer) ((timer%TIME_100MS)== 0)
#define Is110ms(timer) ((timer%TIME_110MS)== 0)
#define Is160ms(timer) ((timer%TIME_160MS)== 0)
#define Is200ms(timer) ((timer%TIME_200MS)== 0)
#define Is210ms(timer) ((timer%TIME_21OMS)== 0)
#define Is220ms(timer) ((timer%TIME_22OMS)== 0)
#define Is225ms(timer) ((timer%TIME_225MS)== 0) 
#define Is230ms(timer) ((timer%TIME_23OMS)== 0)
#define Is320ms(timer) ((timer%TIME_320MS)== 0)
#define Is500ms(timer) ((timer%TIME_500MS)== 0)
#define Is510ms(timer) ((timer%TIME_510MS)== 0)
#define Is640ms(timer) ((timer%TIME_640MS)== 0)
#define Is15s(timer)   ((timer%TIME_15S)  == 0)  

_IRQ_EXTERN_ UCHAR XDATA g_ucColorSys;
_IRQ_EXTERN_ UCHAR XDATA g_ucPreColorSys;
_IRQ_EXTERN_ FLAG   g_bGetUserInputFlg;
_IRQ_EXTERN_ FLAG   g_bGetSignalFlg;
_IRQ_EXTERN_ FLAG   g_bGetColorSysFlg;
_IRQ_EXTERN_ FLAG   g_bGetTimeFlg;
_IRQ_EXTERN_ FLAG   g_bGetBatteryAdcFlg;
_IRQ_EXTERN_ FLAG   g_bGetUserDefFlg;
_IRQ_EXTERN_ FLAG   g_bGetBTFlg;
_IRQ_EXTERN_ FLAG   g_bGetMiscFlg;
_IRQ_EXTERN_ FLAG   g_bVideoChSelOk;
#endif
