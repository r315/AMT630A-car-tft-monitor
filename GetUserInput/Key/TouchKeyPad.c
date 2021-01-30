/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 AdcKeyPad.c	  
*Version:      1.0
*update:       2011-12-08
*Description:
  		   此文件是对ADC 按键的采集与处理。

*History:  Jordan.chen   2011/12/08    1.0    build  this  moudle
******************************************************************************/
#define _I2C_KEY_PAD_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "MsgMap.h"
#include "Debug.h"
#include "WT5700.h"
#include "TouchKeyPad.h"



#ifdef KeyDetectEn 

/***********************************************************
*name:     	 GetI2CKeyValue(void)
*input:      void
*output:     返回当前采集到按键值。
*update:     2012-01-06

*description: 返回当前采集到按键值。
*history:yshuizhou   2012/01/012   0.2    build  this  function	
************************************************************/
KeyInfor POS_GetI2CKeyValue(void)
{   
	UINT  XDATA CurrentKeyVal;
	UCHAR XDATA tmpKeyVal;
	KeyInfor XDATA tmpKey = {NULL_KEY,MSG_NULL,NULL_TIME,KEYRELEASE};

	tmpKeyVal = ReadWT5700(0X08)&0X0F;
	CurrentKeyVal = ((UINT)tmpKeyVal)<<8;
	CurrentKeyVal |=ReadWT5700(0X09);
	 
	if(CurrentKeyVal == 0x0000)
    {
		CurrentKey.KeyVal = NULL_KEY;
		if(CurrentKey.KeyVal != PreKey.KeyVal)
		{
		   //printfStr("Release I2C Key");
		   tmpKey.KeyVal = PreKey.KeyVal;
		   tmpKey.Holdtime = CurrentKey.Holdtime;
		   tmpKey.Status = KEYPRESS;
		}
		CurrentKey.Holdtime = NULL_TIME;
		PreKey.KeyVal = NULL_KEY;
		
    }
	else
	{   
	    //printfStr("InputPress I2C Key");
		CurrentKey.KeyVal = CurrentKeyVal;
		PreKey.KeyVal = CurrentKeyVal;

		if(CurrentKey.Holdtime <= 0XFF)
		{
		   CurrentKey.Holdtime++;
		}

		tmpKey.KeyVal = CurrentKey.KeyVal;
		tmpKey.Holdtime = CurrentKey.Holdtime;
		tmpKey.Status = KEYHOLD;
	}
	return tmpKey;
}


#endif   //#ifdef KeyDetectEn 
