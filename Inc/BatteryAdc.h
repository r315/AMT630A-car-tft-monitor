/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 AdcKeyPad.h  
*Version:      0.1
*update:       2011-12-08
*Description:
  		   此文件是对BATTERY ADC的采集与处理头文件。

*History:  yshuizhou   2012/10/31    0.1    build  this  moudle
******************************************************************************/
#ifndef  _BATTERY_ADC_H__
#define  _BATTERY_ADC_H__

#ifdef LowBaterryDetecEn 

#ifdef _BATTERY_ADC_C_
#define _BATTERY_ADC_EXTERN_ 
#else
#define _BATTERY_ADC_EXTERN_ extern
#endif

_BATTERY_ADC_EXTERN_ UINT POS_GetBestBatteryAdcVal( UINT * AdcBuf, UCHAR Length);
_BATTERY_ADC_EXTERN_ UINT POS_FilterBatteryAdcVal(UINT * AdcValueBuf,UCHAR len);
_BATTERY_ADC_EXTERN_ UINT POS_GetBatteryAdcValue(void);

#endif   //#ifdef LowBaterryDetecEn 
#endif   // #ifndef  _BATTERY_ADC_H__

