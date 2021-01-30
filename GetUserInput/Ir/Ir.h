/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Prj_ARK18X9_SDK_DEMO.h
*Version:    　0.1
*Author:       cjinzong
*update:       20111208

*Description:
            
*History:
************************************************************************/
#ifndef _IR_H__
#define _IR_H__

/*
note: 必须在此处定义该头文件。
*/
#include "global.h"


#ifdef _IR_C_
#define _IR_C_EXTERN_ 
#else
#define _IR_C_EXTERN_ extern
#endif

/*
ir protocol:
*/
#define NEC     0
#define RC5     1
#define RC6     2
#define SANYC   3
/*
ir decode mode:
*/
#define IR_HARDWARE     0
#define IR_SOFTWARE     1

#define IR_NULL_KEY             0xFFFF        //无效键
#define CheckRepeatFlg()       (R_FLAG & _BIT1)
#define CheckReleaseFlg()      (R_FLAG & _BIT0)
#define ClrReleaseFlg()        (R_FLAG &= (~_BIT0))

_IR_C_EXTERN_ UINT XDATA g_uwCustomCode;
_IR_C_EXTERN_ MSG POS_TransferIrKeyMsg(UINT IrKeyVal);
_IR_C_EXTERN_ UINT POS_GetRemoteKeyVal(UINT IrVal);
_IR_C_EXTERN_ UINT XDATA g_ucRemoteKeyVal;


#endif

