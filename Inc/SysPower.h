/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� SysPower.h
*Version:    ��0.1
*Author:       Jordan.chen
*update:       2011-12-07

*Description:
           ���ļ�Ϊϵͳ��Դģ��ͷ�ļ���
*History:  

************************************************************************/
#ifndef _SYSPOWER_H__
#define _SYSPOWER_H__


#ifdef _POWER_C_
  #define _POWER_EXTERN_   
#else
  #define _POWER_EXTERN_ extern
#endif




/*=========================��Դ����==========================*/

#define IsPowerOn() 		(g_sysSetting.Power.status== POWER_ON)
#define IsPowerOff()		(g_sysSetting.Power.status == POWER_OFF)
#define IsAllPowerOn() 	(g_sysSetting.Factory.powerswitch ==ON)
#define IsAllPowerOff() 	(g_sysSetting.Factory.powerswitch ==OFF)
#define IsPowerSave() 		(g_sysSetting.Factory.powerswitch ==SAVE)

#define SetPowerOn() 		(g_sysSetting.Power.status = POWER_ON)
#define SetPowerOff() 		(g_sysSetting.Power.status = POWER_OFF)
#define SetAllPowerOn() 	(g_sysSetting.Power.status = POWER_OFF)
#define SetAllPowerOff() 	(g_sysSetting.Power.status = POWER_ON)
#define SetPowerSave()  	if(IsPowerOn()){SetPowerOff();}else if(IsPowerOff()){SetPowerOn();}


_POWER_EXTERN_ BOOL PowerOnSystem(void);
_POWER_EXTERN_ BOOL PowerOffSystem(void);
#endif
