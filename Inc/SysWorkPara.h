/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� SysWorkPara.h
*Version:    ��0.1
*Author:       Jordan.chen
*update:       2011-12-19

*Description:
            ��Ҫ��ϵͳ���ò����Ĺ���
*History:  

************************************************************************/
#ifndef _SYS_WORK_PARA_H__
#define _SYS_WORK_PARA_H__

#ifdef _SYS_WORK_PARA_C_
#define _WORK_PARA_EXTERN_ 
#else
#define _WORK_PARA_EXTERN_ extern
#endif

   



_WORK_PARA_EXTERN_ BOOL ReadSetting(void);
_WORK_PARA_EXTERN_ void SaveSetting(void);
_WORK_PARA_EXTERN_ void ResetSetting(void);

#endif
