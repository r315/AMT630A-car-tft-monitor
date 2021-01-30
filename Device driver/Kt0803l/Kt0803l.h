/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Kt0803l.h  
*Version:      1.0
*update:       2012-05-22
*Description:
  		   此文件是对Kt0803l处理头文件。

*History:  yshuizhou  2012/05/22    1.0    build  this  moudle
******************************************************************************/

#ifndef _Kt0803l_H__
#define _Kt0803l_H__



#ifdef _Kt0806l_C_
#define _KT0803L_EXTERN_  
#else
#define _KT0803L_EXTERN_  extern
#endif


//#define PA_CTRL


#define INIT_FAIL_TH 3
#define PA_BIAS	      1		
//#define PA_BIAS	  0		  

#define STEREO 		  0
#define MONO   		  1
#define IAL          0xBB	// Input Audio Level
#define TRL          0xBB


#define X32P768K
//#define R32P768K
//#define X7P6M
//#define R7P6M
//#define R7P6MPIN2
//#define X15P2M
//#define R15P2M
//#define R12M
//#define R12MPIN2
//#define R24M



_KT0803L_EXTERN_ void DelayKt0803lI2c(UINT delayTime);	
_KT0803L_EXTERN_ void Kt0803lI2CStart(void);
_KT0803L_EXTERN_ void Kt0803lI2CStop(void);
_KT0803L_EXTERN_ FLAG Kt0803lACKCheck(void);
_KT0803L_EXTERN_ void Kt0803lNACKSend(void);
_KT0803L_EXTERN_ void Kt0803lI2CWrite(UCHAR tempdata);
_KT0803L_EXTERN_ UCHAR Kt0803lI2CRead(void);


_KT0803L_EXTERN_ void KT_Bus_Write(UCHAR Register_Address, UCHAR Byte_Data);
_KT0803L_EXTERN_ UCHAR KT_Bus_Read(UCHAR Register_Address);
_KT0803L_EXTERN_ BOOL KT_TXPreInit(void);
_KT0803L_EXTERN_ BOOL KT_TXInit (void);
_KT0803L_EXTERN_ void KT_TXTune (WORD Frequency);
_KT0803L_EXTERN_ void KT_TXInitTune(UCHAR RFVal);

#endif
