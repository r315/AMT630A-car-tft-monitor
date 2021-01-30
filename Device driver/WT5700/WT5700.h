/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 WT5700.h  
*Version:      1.0
*update:       2012-05-22
*Description:
  		   此文件是对WT5700处理头文件。

*History:  yshuizhou  2012/05/22    1.0    build  this  moudle
******************************************************************************/

#ifndef _WT5700_H__
#define _WT5700_H__



#ifdef _WT5700_C_
#define _WT5700_EXTERN_  
#else
#define _WT5700_EXTERN_  extern
#endif


_WT5700_EXTERN_ void DelayKeyI2c(UINT delayTime);
_WT5700_EXTERN_ void KeyI2CStart(void);
_WT5700_EXTERN_ void KeyI2CStop(void);
_WT5700_EXTERN_ FLAG KeyACKCheck(void);
_WT5700_EXTERN_ void KeyNACKSend(void);
_WT5700_EXTERN_ void KeyI2CWrite(UCHAR tempdata);
_WT5700_EXTERN_ UCHAR KeyI2CRead(void);


_WT5700_EXTERN_ void WriteWT5700(UCHAR Address,UCHAR Data);
_WT5700_EXTERN_ UCHAR ReadWT5700(UCHAR subAddr);
_WT5700_EXTERN_ void Initial_WT5700(void);

#endif
