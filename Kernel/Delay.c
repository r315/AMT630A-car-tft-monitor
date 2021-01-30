/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Delay.c	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		    延时时间函数的定义。
  		  
*History:  Jordan.chen   2011/12/16    1.0    build  this  moudle
******************************************************************************/
#define _DELAY_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"


void Delay(UINT cont_time)
{
    while(cont_time--)
	{
	  _nop_();
	}
}

void DelayMs(UINT contTime)
{
	while(contTime--)
	{
	  Delay(400);
	}
}

