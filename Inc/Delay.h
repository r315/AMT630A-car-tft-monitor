/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� Delay.h	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		    ��ʱʱ�亯���Ķ��塣
  		  
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