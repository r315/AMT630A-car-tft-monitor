/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 BT_i50eUartRec.h	  
*Version:      1.0
*update:       2012-05-09
*Description:
  		    BT串口接收相关定义。
  		  
*History:  yshuizhou  2014/04/14   1.0    build  this  moudle
******************************************************************************/
#ifndef _BTUARTREC_H__
#define _BTUARTREC_H__

#ifdef BTEn
#if(BT_Module == BlueSoleil_i50e)

#ifdef _BT_UARTREC_C
#define _BTUARTREC_EXTERN_ 
#else
#define _BTUARTREC_EXTERN_ extern
#endif


#define ATSTART_ASCIIBUF  {0X41,0X54,0X2D,0X42} //AT-B
#define INIT_ASCIIBUF    	{0X49,0X4E,0X49,0X54} //INIT
#define HFCONN_ASCIIBUF   	{0X48,0X46,0X43,0X4F,0X4E,0X4E} //HFCONN
#define HFDISC_ASCIIBUF   	{0X48,0X46,0X44,0X49,0X53,0X43}//HFDISC
#define HFCCIN_ASCIIBUF   	{0X48,0X46,0X43,0X43,0X49,0X4E} //HFCCIN
#define HFCLCC_ASCIIBUF   	{0X48,0X46,0X43,0X4C,0X43,0X43} //HFCLCC

#define ATEDN_ASCII   		0X0D
#define NULL_ASCII      	0X20

#define	INIT_CONNSUCCESS 	0X30
#define HFP_CONNSUCCESS  	0X30
#define HFP_DISCSUCCESS  	0X30
#define HFP_SUCCESS     	0X30

#define CALL_ANSWER		0X00
#define CALL_REJECTED		0X01

_BTUARTREC_EXTERN_ FLAG   g_bBTConnFlg;
_BTUARTREC_EXTERN_ FLAG   g_bBTDiscFlg;
_BTUARTREC_EXTERN_ FLAG   g_bBTCinFlg;
_BTUARTREC_EXTERN_ FLAG   g_bBTCdropFlg;
_BTUARTREC_EXTERN_ FLAG   g_bBTCanswerFlg;
_BTUARTREC_EXTERN_ FLAG   g_bCallAnswerFlg;
_BTUARTREC_EXTERN_ UCHAR  XDATA g_ucBTStatus;
_BTUARTREC_EXTERN_ UCHAR  XDATA g_ucCallerIDLen;
_BTUARTREC_EXTERN_ UCHAR  XDATA g_ucCallerIDAsciiBuf[40];
_BTUARTREC_EXTERN_ UCHAR  XDATA g_ucCallerIDBuf[40];


_BTUARTREC_EXTERN_ void POS_BTUartRec(void); 
_BTUARTREC_EXTERN_ void POS_UartSendCmd(UCHAR Val);

#endif
#endif
#endif
