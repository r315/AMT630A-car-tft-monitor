/*
E2prom的头文件
*/

#ifndef _E2P_H__
#define _E2P_H__



#ifdef _E2P_C_
#define _E2P_EXTERN_  
#else
#define _E2P_EXTERN_  extern
#endif

#define E2P_DAT_ADDR      0x1000
#define E2P_COPY_ADDR     0x1100


_E2P_EXTERN_ void E2pDelayI2c(UINT delayTime);
_E2P_EXTERN_ void E2pI2CStart(void);
_E2P_EXTERN_ void E2pI2CStop(void);
_E2P_EXTERN_ FLAG E2pACKCheck(void);
_E2P_EXTERN_ void E2pACKSend(void);
_E2P_EXTERN_ void E2pNACKSend(void);
_E2P_EXTERN_ void E2pI2CWrite(UCHAR tempdata);
_E2P_EXTERN_ UCHAR E2pI2CRead(void);

_E2P_EXTERN_ void WriteE2promMultByte(ULONG address, UCHAR * dataPt, WORD number);
_E2P_EXTERN_ void ReadE2promMultiple(ULONG subAddr, UCHAR * dataPt, UINT rdNum);
_E2P_EXTERN_ BOOL VerifyE2promDate(ULONG stAddr);

#endif
