/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 ArkRun.h
*Version:    　0.1
*Author:       cjinzong
*update:       2011-12-16

*Description:
              系统各模块运行逻辑。
*History:  

************************************************************************/
#ifndef _EVENT_HANDLE_H__
#define _EVENT_HANDLE_H__

#ifdef _EVENT_HANDLE_C_
#define _HANDLE_EXTERN_
#else
#define _HANDLE_EXTERN_  extern
#endif

_HANDLE_EXTERN_ void  OsdMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  SignalMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  ColorSysMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  TimeMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  BatteryAdcMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  UserDefinedMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  BTMsgHandle(MSG curMsg);
_HANDLE_EXTERN_ void  MiscMsgHandle(MSG curMsg);
#endif
