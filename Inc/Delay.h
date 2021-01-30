/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Delay.h	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		    延时时间函数的定义。
  		  
*History:  Jordan.chen   2011/12/16    1.0    build  this  moudle
******************************************************************************/
#ifndef _DELAY_H__
#define _DELAY_H__


#ifdef _DELAY_C_
#define _DELAY_EXTERN_ 
#else
#define _DELAY_EXTERN_ extern
#endif


_DELAY_EXTERN_ void DelayMs(UINT contTime);

#endif