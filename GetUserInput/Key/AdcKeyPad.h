/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� AdcKeyPad.h  
*Version:      1.0
*update:       2011-12-08
*Description:
  		   ���ļ��Ƕ�ADC �����Ĳɼ��봦��ͷ�ļ���

*History:  Jordan.chen   2011/12/08    1.0    build  this  moudle
******************************************************************************/
#ifndef  _ADC_KEY_PAD_H__
#define  _ADC_KEY_PAD_H__

#ifdef KeyDetectEn 

#ifdef _ADC_KEY_PAD_C_
#define _ADC_KP_EXTERN_ 
#else
#define _ADC_KP_EXTERN_ extern
#endif


#define KeyOkFlg                _BIT15  //����OK��־
#define AdcChannelBit           (_BIT12|_BIT13) //����ͨ����־


_ADC_KP_EXTERN_ UINT POS_GetBestAdcKeyVal(UINT* AdcBuf, UCHAR Length);
_ADC_KP_EXTERN_ UINT  POS_FilterAdcKeyVal(UINT * AdcValueBuf,UCHAR len);
_ADC_KP_EXTERN_ KeyInfor  POS_ReleaseAdcKey(UINT AdcKeyVal);
_ADC_KP_EXTERN_ KeyInfor  POS_GetAdcKeyValue(void);

#endif   //#ifdef KeyDetectEn 
#endif   // #ifndef  _ADC_KEY_PAD_H__
