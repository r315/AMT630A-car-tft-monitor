/**************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 E2pI2C.C	  
*Version:    　0.01
*Author:       cjinzong
*Update:       2009-03-25
*State：       try out
* 
*Description:
*    这个文件是用来定义i2c 的一些基本的操作。

*History:
*
****************************************************************/

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "AMT_Drv.h"


#ifdef E2promEn

#define SetSdaOutput() ;  
#define SetSdaInput()  GetSda()
#define SetSclOutput() ;

#define GetSda()   hw_E2p_getSDA_input()
#define SetSda(x)  hw_E2p_setSDA_output(x)
#define SetScl(x)  hw_E2p_setSCL_output(x)
					 
/***********************************************************
*name:    DelayE2pI2c()
*input:   uchar delayTime   // 确定延时时间
*output:  non
*update:  2009-03-25

*description:   iic 延时程序
*history:
************************************************************/
void DelayE2pI2c(UINT delayTime)	
{
	while(delayTime) 
	{
	    delayTime = delayTime - 1;
    }   
} 
/**********************************************************
*name:    I2CStart(void)
*input:   non
*output:  发送START
*update:  2009-03-25

*description:   iic的start信号函数,表示将要开始进行数据传输
          start : 14*1.085=15.9u

*history:
***********************************************************/
void E2pI2CStart(void)
{  
	SetSdaOutput();
    SetSclOutput();

	DelayE2pI2c(5);
						//___
	SetSda(1);			//	 |
	SetScl(1);			//	 |___SDA
	DelayE2pI2c(10);		//____	
	SetSda(0);			//	  |
	DelayE2pI2c(10);		//	  |__SCL
	SetScl(0);	
	DelayE2pI2c(10);

}
/***********************************************************
*name:    I2CStop(void)
*input:   non
*output:  发送STOP
*update:  2009-03-25

*description:   iic的stop 信号函数，说明数据传输完毕

            stop : 13*1.085 = 14.1u
*history:
************************************************************/
void E2pI2CStop(void)
{   
    SetSdaOutput();
                      //    ___SDA
	SetSda(0);		  //   |
	SetScl(1);			  //___|
	DelayE2pI2c(5);	  //_______SCL
	SetSda(1);		  //
	DelayE2pI2c(5);	  //

}
/***********************************************************
*name:    ACKCheck(void)
*input:   non
*output:  bit      //FLAG 就是bit   在general.h 文件中定义
*update:  2009-03-25

*description:   iic的ack 信号检测函数  
                ACKCheck = 14u
*history:
************************************************************/
FLAG E2pACKCheck(void)
{
    UCHAR loop = 200;
	
    SetSdaInput();
	
	DelayE2pI2c(2);								   
	SetScl(1);
	do
	{
	    DelayE2pI2c(2);
		if(GetSda() == 0)
		{
		   SetScl(0);									   
	       return(0);    //这里说明有ACK信号  
		}
		else
		{
		   if(loop == 1)
		   {
		        SetScl(0);									   
	            return(1);   
		   }
		}
	}while(--loop) ;
    return 1;	
}
/***********************************************************
*name:   ACKSend(void)
*input:  non
*output: ACK 发送
*update: 2009-03-25

*description:   iic的ack 信号发送函数
*history:
************************************************************/
void E2pACKSend(void)
{
    SetSdaOutput();
	
	SetSda(0);            //"发送应答位"
	DelayE2pI2c(1);
	SetScl(1);	
	DelayE2pI2c(1);
	SetScl(0);	
	DelayE2pI2c(1);
	SetSda(1);	
}

/***********************************************************
*name:N ACKSend(void)
*input:  non
*output: NACK send
*update: 2009-03-25

*description:   iic的nack 信号发送函数
*history:
************************************************************/
void E2pNACKSend(void)
{
    SetSdaOutput();
	
	SetSda(1);           //"发送非应答位"
	DelayE2pI2c(2);
	SetScl(1);	
	DelayE2pI2c(2);
	SetScl(0);	
	DelayE2pI2c(2);
	SetSda(1);	
}


/***********************************************************
*name:    I2CWrite(UCHAR tempdata)
*input:   UCHAR tempdata
*output:  对相应的空间写一个字节数据
*update:  2009-03-25

*description:   iic的write一个字节函数 
                100u
*history:
************************************************************/
void E2pI2CWrite(UCHAR tempdata)
{
	UCHAR XDATA num;                           //"发送数据位数"
	
	SetSdaOutput();
	
	for(num = 0;num < 8;num ++)
	{
		SetSda((tempdata >> (7-num)) & 1);	//"先发高位"
		DelayE2pI2c(2);
		SetScl(1);                        //下降缘 读取
		DelayE2pI2c(2);
		SetScl(0);
		DelayE2pI2c(2);	
	}
	SetSda(1);
}


/***********************************************************
*name:    I2CRead(void)
*input:   non
*output:  返回读出的字节
*update:  2009-03-25

*description:   iic的read一个字节 数据函数
*history:
************************************************************/
UCHAR E2pI2CRead(void)
{

	UCHAR XDATA temp = 0xff;
	UCHAR XDATA num;         //"接收数据位数"

	SetSdaInput();

	for(num = 0;num < 8;num ++)
	{
	  
		SetScl(1);
		DelayE2pI2c(2);
		temp = temp << 1;//"先接收高位"

		if(GetSda() == 1)
		{
			temp = temp | 0x01;
		}

		if(GetSda() == 0)
		{
			temp = temp & 0xfe;
		}

		SetScl(0);
		DelayE2pI2c(2);
	}

	return (temp);
}
#endif



