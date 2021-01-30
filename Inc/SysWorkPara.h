/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 SysWorkPara.h
*Version:    　0.1
*Author:       Jordan.chen
*update:       2011-12-19

*Description:
            主要是系统配置参数的管理。
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
