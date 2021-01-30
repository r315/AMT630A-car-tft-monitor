/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 AdcKeyPad.c	  
*Version:      1.0
*update:       2011-12-08
*Description:
  		   此文件是对ADC 按键的采集与处理。

*History:  Jordan.chen   2011/12/08    1.0    build  this  moudle
******************************************************************************/
#define _ADC_KEY_PAD_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "MsgMap.h"
#include "Debug.h"
#include "AdcKeyPad.h"
#include "AMT_Reg.h"
#include "AMT_Drv.h"


#ifdef KeyDetectEn 


/*************************************************************************
name:    GetBestAdcKeyVal(UCHAR* AdcBuf, UCHAR Length)
input:   AdcBuf  //需滤波的数据指针。
         Length  //需滤波的数据长度。
output:	 返回平均数据平均滤波后的数据。
update： 2011-12-07
state：  try out
description: 返回平均数据平均滤波后的数据。

history: yshuizhou   2011/12/20    0.2    build  this  function
*************************************************************************/
UINT POS_GetBestAdcKeyVal( UINT * AdcBuf, UCHAR Length)
{
	UCHAR XDATA i,j,index;
	UINT XDATA s_offset1 = 0,s_offset2 = 0;
	
	 for(i=0; i<Length; i++)
	 {
	    s_offset1 += Abs(AdcBuf[i], AdcBuf[0]);
	 }
	index = 0;
	for(i=1; i<Length; i++)
	{
	    for(j=0; j<Length;j++)
	    {
	        s_offset2 += Abs(AdcBuf[i], AdcBuf[j]);
	    }
	    if(s_offset1 > s_offset2)
	    {
	        s_offset1 = s_offset2;
		    index = i;
	    }
	    s_offset2 = 0;	
	}	
	return AdcBuf[index];
}


/*************************************************************************
name:    FilterAdcKeyVal(UINT * AdcValueBuf,UCHAR len)
input:   AdcValueBuf、len。
output:	 返回平均数据平均滤波后的数据。
update： 2011-11-28
state：  try out
description:  这个函数是ADC类型的按键滤波函数，经过限副滤波返回相应的按键值。 

history: yshuizhou   2011/12/20    0.2    build  this  function
*************************************************************************/
UINT POS_FilterAdcKeyVal(UINT * AdcValueBuf,UCHAR len)
{    

	 UCHAR XDATA  i,j;
	 UINT  XDATA CurrentKey = NULL_KEY;
	 FLAG  Keyok = TRUE;
	 
	for(i=0;i<(len-1);i++)
 	{
		for(j=i+1;j<len;j++)
		 {
			 if(Abs(AdcValueBuf[i],AdcValueBuf[j]) > 13)   //相邻两次ADC 采集电压不能超过0.1V
			 {
				Keyok = FALSE;
				break;
			 }
		 }
		if(!Keyok)
		{
		   break;
		}
    }
	
	if(Keyok)
 	{
 	     CurrentKey = POS_GetBestAdcKeyVal(AdcValueBuf,len);
		 CurrentKey = setFlg(CurrentKey,KeyOkFlg);
 	}
    else
    {
		 CurrentKey = clrFlg(CurrentKey,KeyOkFlg);
    }
	return(CurrentKey);		
	
}



/*************************************************************************
name:    ReleaseAdcKey(UINT AdcKeyVal)
input:   AdcKeyVal
output:	 NULL_KEY
update： 2011-12-07
state：  try out
description: ADC按键释放，执行相关的操作。

history: yshuizhou   2011/12/07    0.2    build  this  function
*************************************************************************/
KeyInfor POS_ReleaseAdcKey(UINT AdcKeyVal)
{
    KeyInfor XDATA tmpKey = {NULL_KEY,MSG_NULL,NULL_TIME,KEYRELEASE};
	 
    if((readFlg(AdcKeyVal,AdcChannelBit)>>12) == g_ucPreChannel)
    {
      //printfStr("Release Adc Key");
	  CurrentKey.KeyVal = NULL_KEY;
	  
	  if(CurrentKey.KeyVal != PreKey.KeyVal)
	  {
	     tmpKey.KeyVal = PreKey.KeyVal;
		 tmpKey.Holdtime = CurrentKey.Holdtime;
		 tmpKey.Status = KEYPRESS;
	  }
	  CurrentKey.Holdtime = NULL_TIME;
	  PreKey.KeyVal = NULL_KEY;
    }
	return tmpKey;
}



/***********************************************************
*name:     GetAdcKeyValue(void)
*input:    non
*return:   返回当前通道采集到得按键值。
*update:   2011-12-22
*state:   try out
*description:   
         这个函数定时获取ADC各个通道的按键值。 

         
*history:yshuizhou   2011/12/20    0.2    build  this  function	
************************************************************/
KeyInfor POS_GetAdcKeyValue(void)
{   
    static UCHAR    CODE  ChannelBuf[] = ADC_CH_LIST;
	static UINT     XDATA AdcKeyValBuf[] = {0XFFFF,0XFFFF,0XFFFF,0XFFFF};
    static UCHAR    XDATA AdcChannel = 0;
	static UCHAR    XDATA Index = 0;	
	KeyInfor XDATA tmpKey = {NULL_KEY,MSG_NULL,NULL_TIME,KEYRELEASE};
	UINT  XDATA CurrentAdcVal;
    
	
    AdcKeyValBuf[Index] = POS_EnableChipAdc(ChannelBuf[AdcChannel])>>4;
	Index++;
	
	if(Index >= (sizeof(AdcKeyValBuf)/2)) //note:该数组类型为int 
	{  
	   Index = 0; 
	   CurrentAdcVal = POS_FilterAdcKeyVal(AdcKeyValBuf,sizeof(AdcKeyValBuf)/2);
	   CurrentAdcVal |= (((UINT)(ChannelBuf[AdcChannel]))<<12);//添加通道信息。

	   if(readFlg(CurrentAdcVal, KeyOkFlg) == KeyOkFlg)
	   {    
		   #if TP1_ADC
		   printf("TP1_ADC >> the KeyValue is %x:\r\n",clrFlg(CurrentAdcVal , KeyOkFlg));				 
           #endif

		   #if hw_upResistance
	       if((CurrentAdcVal &0X00FF) >=0X00F0) // 弹起状态   (上拉接法)
	       #endif
			   
		   #if hw_downResistance
		   if((CurrentAdcVal &0X00FF) == 0X0000) // 弹起状态 (下拉接法)
		   #endif
		   {
				AdcChannel++;

				if(AdcChannel >= (sizeof(ChannelBuf))) 
				{
				  AdcChannel = 0;
				}
				return (POS_ReleaseAdcKey(clrFlg(CurrentAdcVal, KeyOkFlg)));
           }
		   else
		   {
		       CurrentKey.KeyVal = clrFlg(CurrentAdcVal , KeyOkFlg);
			   PreKey.KeyVal = clrFlg(CurrentAdcVal , KeyOkFlg);
			   
			   if(CurrentKey.Holdtime <= 0XFF)
			   {
			     CurrentKey.Holdtime++;
			   }
			   
			   tmpKey.KeyVal = CurrentKey.KeyVal;
               tmpKey.Holdtime = CurrentKey.Holdtime;
			   tmpKey.Status = KEYHOLD;
			   return tmpKey;
           }
	   }
	}
	return tmpKey;
}

#endif   //#ifdef KeyDetectEn 
