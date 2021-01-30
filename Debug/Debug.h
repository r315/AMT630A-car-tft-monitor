/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� Debug.h	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		    ���Դ�ӡͷ�ļ���
  		  
*History:  Jordan.chen   2011/12/16    1.0    build  this  moudle
******************************************************************************/
#ifndef  _DEBUG_H__
#define  _DEBUG_H__

#ifdef  _DEBUG_C_
#define _DEBUG_EXTERN_ 
#else
#define _DEBUG_EXTERN_  extern
#endif

#ifdef UartPrintfEn	

_DEBUG_EXTERN_ void printf(char *str, WORD value);
_DEBUG_EXTERN_ void printfStr(char *str);
_DEBUG_EXTERN_ void IrqPrintf(char *str, WORD value);
_DEBUG_EXTERN_ void IrqPutstr(UCHAR *pFmt);
#else
#define printf(x, y) 
#define printfStr(x)
#define IrqPrintf(x,y)
#define IrqPutstr(x)
#endif

#endif