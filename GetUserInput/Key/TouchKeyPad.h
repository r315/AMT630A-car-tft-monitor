/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� AdcKeyPad.h  
*Version:      1.0
*update:       2011-12-08
*Description:
  		   ���ļ��Ƕ�I2C �����Ĳɼ��봦��ͷ�ļ���

*History:  Jordan.chen   2011/12/08    1.0    build  this  moudle
******************************************************************************/
#ifndef  _I2C_KEY_PAD_H__
#define  _I2C_KEY_PAD_H__

#ifdef KeyDetectEn 

#ifdef _I2C_KEY_PAD_C_
#define _I2C_KP_EXTERN_ 
#else
#define _I2C_KP_EXTERN_ extern
#endif


_I2C_KP_EXTERN_ KeyInfor POS_GetI2CKeyValue(void);


#endif   //#ifdef KeyDetectEn 
#endif   // _I2C_KEY_PAD_H__
