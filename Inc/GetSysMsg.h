/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� GetSysMsg.h
*Version:    ��0.1
*Author:       cjinzong
*update:       2011-12-09

*Description:
             ���ļ���ϵͳ�ɼ���Ϣͷ�ļ���
*History:  

************************************************************************/
#ifndef _GET_SYS_MSG_H__
#define _GET_SYS_MSG_H__

#ifdef _GET_MSG_C_
#define _GET_MSG_EXTERN_
#else
#define _GET_MSG_EXTERN_ extern
#endif


 
_GET_MSG_EXTERN_ MSG POS_GetUserInputMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetSignalMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetColorSysMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetTimeMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetBatteryAdcMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetUserDefinedMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetBTMsg(FLAG timer);
_GET_MSG_EXTERN_ MSG POS_GetMiscMsg(FLAG timer);

#endif
