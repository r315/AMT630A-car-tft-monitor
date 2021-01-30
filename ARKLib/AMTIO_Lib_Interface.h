/*
Author:scott.jiang
Date: 2014年10月22日17:27:18
Description: 
   AMTIOLib 函数接口。
*/

#ifndef AMTIO_LIB_INTERFACE_H__
#define  AMTIO_LIB_INTERFACE_H__

//P0 
extern void SetP0_0(UCHAR Val) reentrant;
extern void SetP0_1(UCHAR Val) reentrant;
extern void SetP0_2(UCHAR Val) reentrant;
extern void SetP0_3(UCHAR Val) reentrant;
extern void SetP0_4(UCHAR Val) reentrant;
extern void SetP0_5(UCHAR Val) reentrant;
extern void SetP0_6(UCHAR Val) reentrant;
extern void SetP0_7(UCHAR Val) reentrant;

extern FLAG GetP0_0(void) reentrant;
extern FLAG GetP0_1(void) reentrant;
extern FLAG GetP0_2(void) reentrant;
extern FLAG GetP0_3(void) reentrant;
extern FLAG GetP0_4(void) reentrant;
extern FLAG GetP0_5(void) reentrant;
extern FLAG GetP0_6(void) reentrant;
extern FLAG GetP0_7(void) reentrant;

//P1
extern void SetP1_0(UCHAR Val) reentrant;
extern void SetP1_1(UCHAR Val) reentrant;
extern void SetP1_2(UCHAR Val) reentrant;
extern void SetP1_3(UCHAR Val) reentrant;
extern void SetP1_4(UCHAR Val) reentrant;
extern void SetP1_5(UCHAR Val) reentrant;
extern void SetP1_6(UCHAR Val) reentrant;
extern void SetP1_7(UCHAR Val) reentrant;

extern FLAG GetP1_0(void) reentrant;
extern FLAG GetP1_1(void) reentrant;
extern FLAG GetP1_2(void) reentrant;
extern FLAG GetP1_3(void) reentrant;
extern FLAG GetP1_4(void) reentrant;
extern FLAG GetP1_5(void) reentrant;
extern FLAG GetP1_6(void) reentrant;
extern FLAG GetP1_7(void) reentrant;

//P2
extern void SetP2_0(UCHAR Val) reentrant;
extern void SetP2_1(UCHAR Val) reentrant;
extern void SetP2_2(UCHAR Val) reentrant;
extern void SetP2_3(UCHAR Val) reentrant;
extern void SetP2_4(UCHAR Val) reentrant;
extern void SetP2_5(UCHAR Val) reentrant;
extern void SetP2_6(UCHAR Val) reentrant;
extern void SetP2_7(UCHAR Val) reentrant;

extern FLAG GetP2_0(void) reentrant;
extern FLAG GetP2_1(void) reentrant;
extern FLAG GetP2_2(void) reentrant;
extern FLAG GetP2_3(void) reentrant;
extern FLAG GetP2_4(void) reentrant;
extern FLAG GetP2_5(void) reentrant;
extern FLAG GetP2_6(void) reentrant;
extern FLAG GetP2_7(void) reentrant;

//P3
extern void SetP3_0(UCHAR Val) reentrant;
extern void SetP3_1(UCHAR Val) reentrant;
extern void SetP3_2(UCHAR Val) reentrant;
extern void SetP3_3(UCHAR Val) reentrant;
extern void SetP3_4(UCHAR Val) reentrant;
extern void SetP3_5(UCHAR Val) reentrant;
extern void SetP3_6(UCHAR Val) reentrant;
extern void SetP3_7(UCHAR Val) reentrant;

extern FLAG GetP3_0(void) reentrant;
extern FLAG GetP3_1(void) reentrant;
extern FLAG GetP3_2(void) reentrant;
extern FLAG GetP3_3(void) reentrant;
extern FLAG GetP3_4(void) reentrant;
extern FLAG GetP3_5(void) reentrant;
extern FLAG GetP3_6(void) reentrant;
extern FLAG GetP3_7(void) reentrant;

// GPIO0 - GPIO10
extern void SetGPIO0(UCHAR Val) reentrant;
extern void SetGPIO1(UCHAR Val) reentrant;
extern void SetGPIO2(UCHAR Val) reentrant;
extern void SetGPIO3(UCHAR Val) reentrant;
extern void SetGPIO4(UCHAR Val) reentrant;
extern void SetGPIO5(UCHAR Val) reentrant;
extern void SetGPIO6(UCHAR Val) reentrant;
extern void SetGPIO7(UCHAR Val) reentrant;
extern void SetGPIO8(UCHAR Val) reentrant;
extern void SetGPIO9(UCHAR Val) reentrant;
extern void SetGPIO10(UCHAR Val) reentrant;

extern FLAG GetGPIO0(void) reentrant;
extern FLAG GetGPIO1(void) reentrant;
extern FLAG GetGPIO2(void) reentrant;
extern FLAG GetGPIO3(void) reentrant;
extern FLAG GetGPIO4(void) reentrant;
extern FLAG GetGPIO5(void) reentrant;
extern FLAG GetGPIO6(void) reentrant;
extern FLAG GetGPIO7(void) reentrant;
extern FLAG GetGPIO8(void) reentrant;
extern FLAG GetGPIO9(void) reentrant;
extern FLAG GetGPIO10(void) reentrant;

#endif

