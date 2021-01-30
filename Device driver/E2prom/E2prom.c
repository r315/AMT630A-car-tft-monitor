/****************************************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 drv_E2prom.c
*Version:    　0.01
*Author:       cjinzong
*Finish date:  2009-04-16

*Description:
*           这个文件是对系统的主要参数进行保存到E2PROM的函数定义。 

*History:
*
***************************************************************************************************/
#define _E2P_C_
#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "E2prom.h"
#include "debug.h"
#include "AMT_REG.h"
#include "AMT_Drv.h"
#include "AMT_MCU.h"



#ifdef E2promEn

/***********************************************************
*name:      E2promReadMultiple(UCHAR page, UCHAR subAddr, UCHAR rdNum, UCHAR * dataPt)
*input:     UCHAR page
            UCHAR subAddr 
            UCHAR rdNum
            UCHAR * dataPt
                 
*output:    dataPt
*return:     non    

*description:   在e2prom中读出多个字节的数据 
*history:
************************************************************/
void ReadE2promMultiple(ULONG subAddr, UCHAR * dataPt, UINT rdNum)
{
  UINT XDATA i=0;

start:

  #if 1
  E2pI2CStart(); 
  E2pI2CWrite(0xa0);
#if 1
	if(E2pACKCheck() == 1)
	{
	    goto start;
	}
#endif
 
  E2pI2CWrite((subAddr>>8)&0xff);
  E2pACKCheck();
  E2pI2CWrite(subAddr&0xff);
  E2pACKCheck();

  E2pI2CStart(); 
  E2pI2CWrite(0xa1);
  E2pACKCheck();
 
  for(i=0; i<rdNum; i++)
  {
    dataPt[i] = E2pI2CRead(); 
    E2pACKSend();	
  }
  dataPt[i] = E2pI2CRead(); 
  E2pNACKSend();  
  E2pI2CStop();
  #endif

}
/***********************************************************
*name:    E2WriteByte(WORD address,BYTE WrData)
*input:            
*output:    non
*return:     tmpResult
*description:   对e2prom 写入多个数据
*history:
************************************************************/
void WriteE2promMultByte(ULONG address, UCHAR * dataPt, WORD number)
{   	 
	UINT XDATA pos = 0;

	while(number>0)
	{
	    UCHAR j;
		
start:		
	    E2pI2CStart();
	    E2pI2CWrite(0xa0); 
		#if 1
		if(E2pACKCheck() == 1)
		{ 
		    goto start;
		}
		#endif
		
		E2pI2CWrite((UCHAR)((address>>8)&0xff));
		E2pACKCheck();

		E2pI2CWrite((UCHAR)(address&0xff));
		E2pACKCheck();

		if(number >= 32)
		{
			for(j=0;j<32;j++,pos++)
			{
				E2pI2CWrite(dataPt[pos]);
		        E2pACKCheck(); 
				number--;
			}
		    E2pI2CStop();	
			address =  address + 32;
		}
		else
		{
		    for(;number>0;number--)
		    {
start1:
				E2pI2CStart();
				E2pI2CWrite(0xa0); 
#if 1
				if(E2pACKCheck() == 1)
				{ 
				goto start1;
				}
#endif
				E2pI2CWrite((UCHAR)((address>>8)&0xff));
				E2pACKCheck();

				E2pI2CWrite((UCHAR)(address&0xff));
				E2pACKCheck();
				
				E2pI2CWrite(dataPt[pos]);
				E2pACKCheck(); 
			    E2pI2CStop();
				
				address++;
				pos++;	
		    }
		}
	}
}


BOOL VerifyE2promDate(ULONG stAddr)
{
    UCHAR XDATA i;
	
    for(i=0;i<3;i++)
    {
		ReadE2promMultiple(stAddr, (UCHAR *)&g_sysSetting, sizeof(SysWorkParaType)); 
		if((g_sysSetting.OXAA == 0xaa) && (g_sysSetting.OX55 == 0x55))
		{
		     return TRUE;
		}
    }
	return FALSE;
}
#endif

