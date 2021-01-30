/****************************************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 WT5700.c
*Version:    　0.01
*Author:       yshuizhou
*Update:       2012-05-22

*Description:
*          这个文件是初始化WT5700。 
*History:
*
***************************************************************************************************/
#define _WT5700_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "WT5700.h"
#include "debug.h"
#include "AMT_Reg.h"
#include "AMT_Drv.h"
#include "AMT_Mcu.h"

#define I2C_ACCESS_LOOP_TIME   		  20
#define I2C_NON_ACK                      1

#ifdef KeyDetectEn 

void WriteWT5700(UCHAR Address,UCHAR Data)
{
    UCHAR XDATA ucLoop;
	ucLoop = I2C_ACCESS_LOOP_TIME;
	
	while(ucLoop--)
	{
	    KeyI2CStart();    
	    DelayKeyI2c(2);
	    KeyI2CWrite(0XE0);
	    DelayKeyI2c(1);
		if(KeyACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}
	    KeyI2CWrite(0X00);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		   continue;
		}
	    KeyI2CWrite(Address);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		   continue;
		}
	    KeyI2CWrite(Data);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		   continue;
		}
		break;
	}
    KeyI2CStop();		
}



UCHAR ReadWT5700(UCHAR subAddr)
{
    UCHAR XDATA tmpRd;
    UCHAR XDATA ucLoop;
	ucLoop = I2C_ACCESS_LOOP_TIME;

	while(ucLoop--)
	{
	    KeyI2CStart();    
	    DelayKeyI2c(2);
	    KeyI2CWrite(0XE0);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		   continue;
		}
	    KeyI2CWrite(0X00);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		   continue;
		}
	    KeyI2CWrite(subAddr);
	    DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		  continue;
		}
		DelayKeyI2c(1);
		KeyI2CStop();
		DelayKeyI2c(1);
		KeyI2CStart();    
	    DelayKeyI2c(2);
	    KeyI2CWrite(0XE1);
		DelayKeyI2c(1);
		if(KeyACKCheck()== I2C_NON_ACK)
		{
		  continue;
		}
		tmpRd = KeyI2CRead(); 
	    DelayKeyI2c(1);
	    KeyNACKSend();
		break;
	}
    KeyI2CStop();		
    return(tmpRd);
}


void Initial_WT5700(void)
{
	WriteWT5700(0x00,0x72);//system control reg
	WriteWT5700(0x02,0x13); //SI[7,11}->0x13 20 Clock,0x14 32 Clock
	WriteWT5700(0x03,0x03); //SI[0,6}->0x03 20 Clock,0x04 32 Clock
}
#endif  //#ifdef KeyDetectEn 

