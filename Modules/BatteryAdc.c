/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� BatteryAdc.c	  
*Version:      0.1
*update:       2011-12-08
*Description:
  		   ���ļ��ǶԵ�ص�ѹADC�Ĳɼ��봦��

*History:  yshuizhou  2012/10/30   0.1    build  this  moudle
******************************************************************************/
#define _BATTERY_ADC_C_

#include "DataType.h"
#include "global.h"
#include "MsgMap.h"
#include "systemConfig.h"
#include "Debug.h"
#include "BatteryAdc.h"
#include "AMT_Reg.h"
#include "AMT_Drv.h"


#ifdef LowBaterryDetecEn 

/*************************************************************************
name:    GetBestBatteryAdcVal(UCHAR* AdcBuf, UCHAR Length)
input:   AdcBuf  //���˲�������ָ�롣
         Length  //���˲������ݳ��ȡ�
output:	 ����ƽ������ƽ���˲�������ݡ�
update�� 2012-10-30
state��  try out
description: ����ƽ������ƽ���˲�������ݡ�

*History:  yshuizhou  2012/10/30   0.1    build  this  moudle
*************************************************************************/
UINT POS_GetBestBatteryAdcVal( UINT * AdcBuf, UCHAR Length)
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
name:    FilterBatteryAdcVal(UINT * AdcValueBuf,UCHAR len)
input:   AdcValueBuf��len��
output:	 ����ƽ������ƽ���˲�������ݡ�
update�� 2012-10-30
state��  try out
description:  ���������ADC���͵İ����˲������������޸��˲�������Ӧ�İ���ֵ�� 

*History:  yshuizhou  2012/10/30   0.1    build  this  moudle
*************************************************************************/
UINT POS_FilterBatteryAdcVal(UINT * AdcValueBuf,UCHAR len)
{   

#define  BufferSize 4

	static UCHAR XDATA Index = 0;
	UINT  XDATA TheBetterBatteryAdcVal;
	static UINT XDATA BatteryAdcBuffer[BufferSize];

	if(Index < BufferSize)
	{  
        BatteryAdcBuffer[Index] = POS_GetBestBatteryAdcVal(AdcValueBuf,len);
		Index ++;
		return NULL_BATTERYADC;
	}

	Index = 0;
	TheBetterBatteryAdcVal = POS_GetBestBatteryAdcVal(BatteryAdcBuffer, BufferSize);
	return TheBetterBatteryAdcVal;	
}



/***********************************************************
*name:     GetAdcKeyValue(void)
*input:    non
*return:   ���ص�ǰͨ���ɼ����ð���ֵ��
update�� 2012-10-30
*state:   try out
*description:   
         ���������ʱ��ȡADC����ͨ���İ���ֵ�� 

         
*History:  yshuizhou  2012/10/30   0.1    build  this  moudle
************************************************************/
UINT POS_GetBatteryAdcValue(void)
{   

#define BatteryAdcOffSet          	2
#define BatteryAdcChInit         	0
#define BatteryAdcChScan         	1


	static UINT     XDATA BatteryAdcValBuf[] = {0XFFFF,0XFFFF,0XFFFF,0XFFFF};
	static UCHAR    XDATA Index = 0;
	static UINT     XDATA PreBatteryAdcVal = 0XFFFF;
	static UCHAR    XDATA BatteryChStatus = BatteryAdcChInit;

	UINT  XDATA CurBatterAdcVal;

	
    BatteryAdcValBuf[Index] = POS_EnableChipAdc(BATTER_DETEC_CH)>>4;
	Index++;
	
	if(Index >= (sizeof(BatteryAdcValBuf)/2)) //note:����������Ϊint 
	{  
	   Index = 0; 
	   CurBatterAdcVal = POS_FilterBatteryAdcVal(BatteryAdcValBuf,sizeof(BatteryAdcValBuf)/2);
       if(NULL_BATTERYADC == CurBatterAdcVal)
	   {
		    return NULL_BATTERYADC;
	   }
	   else
	   {
		  CurBatterAdcVal >>=2;  //�˲���ȡ��6λ
	   }
	}
	else
	{
	      return NULL_BATTERYADC;
	}

	switch(BatteryChStatus)
	{
	  case 	BatteryAdcChInit:
	  	    PreBatteryAdcVal = CurBatterAdcVal;
			BatteryChStatus = BatteryAdcChScan;
			return CurBatterAdcVal;
	  		break;

	  case 	BatteryAdcChScan:
	  	    if(Abs(CurBatterAdcVal &0X00FF,PreBatteryAdcVal &0X00FF) > BatteryAdcOffSet)
	        {
	             PreBatteryAdcVal = CurBatterAdcVal;
				 return CurBatterAdcVal;
	        }
	  	   	break;

	  default:
	  	    break;
	}
	return NULL_BATTERYADC; 
}

#endif   //#ifdef LowBaterryDetecEn 

