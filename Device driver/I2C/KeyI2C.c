/**************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 KeyI2C.C	  
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


#ifdef KeyDetectEn 

#define SetSdaOutput() ;  
#define SetSdaInput()  GetSda()
#define SetSclOutput() ;

#define GetSda()   hw_Key_getSDA_input()
#define SetSda(x)  hw_Key_setSDA_output(x)
#define SetScl(x)  hw_Key_setSCL_output(x)


/***********************************************************
*name:    DelayI2c()
*input:   uchar delayTime   // 确定延时时间
*output:  non
*update:  2009-03-25

*description:   iic 延时程序
*history:
************************************************************/
void DelayKeyI2c(UINT delayTime)	
{
	while(delayTime) 
	{
	    delayTime = delayTime - 1;
    }   
} 
/**********************************************************
*name:    KeyI2CStart(void)
*input:   non
*output:  发送START
*update:  2009-03-25

*description:   iic的start信号函数,表示将要开始进行数据传输
          start : 14*1.085=15.9u

*history:
***********************************************************/
void KeyI2CStart(void)
{  
	SetSdaOutput();
    SetSclOutput();

	DelayKeyI2c(5);
						//___
	SetSda(1);			//	 |
	SetScl(1);			//	|___SDA
	DelayKeyI2c(20);    //____	
	SetSda(0);			//	  |
	DelayKeyI2c(20);  //	 |__SCL
	SetScl(0);	
	DelayKeyI2c(20);

}
/***********************************************************
*name:    KeyI2CStop(void)
*input:   non
*output:  发送STOP
*update:  2009-03-25

*description:   iic的stop 信号函数，说明数据传输完毕

            stop : 13*1.085 = 14.1u
*history:
************************************************************/
void KeyI2CStop(void)
{   
    SetSdaOutput();
                      //    ___SDA
	SetSda(0);		  //   |
	SetScl(1);			  //___|
	DelayKeyI2c(20);	  //_______SCL
	SetSda(1);		  //
	DelayKeyI2c(20);	  //

}
/***********************************************************
*name:    KeyACKCheck(void)
*input:   non
*output:  FLAG     
*update:  2009-03-25

*description:   iic的ack 信号检测函数  
                ACKCheck = 14u
*history:
************************************************************/
FLAG KeyACKCheck(void)
{
    UCHAR loop = 200;
	
    SetSdaInput();
	
	DelayKeyI2c(2);								   
	SetScl(1);
	do
	{
	    DelayKeyI2c(10);
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
*name:   KeyNACKSend(void)
*input:  non
*output: NACK send
*update: 2009-03-25

*description:   iic的nack 信号发送函数
*history:
************************************************************/
void KeyNACKSend(void)
{
    SetSdaOutput();
	
	SetSda(1);           //"发送非应答位"
	DelayKeyI2c(10);
	SetScl(1);	
	DelayKeyI2c(10);
	SetScl(0);	
	DelayKeyI2c(10);
	SetSda(1);	
}


/***********************************************************
*name:    KeyI2CWrite(UCHAR tempdata)
*input:   UCHAR tempdata
*output:  对相应的空间写一个字节数据
*update:  2009-03-25

*description:   iic的write一个字节函数 
                100u
*history:
************************************************************/
void KeyI2CWrite(UCHAR tempdata)
{
	UCHAR XDATA num;                           //"发送数据位数"
	
	SetSdaOutput();
	
	for(num = 0;num < 8;num ++)
	{
		SetSda((tempdata >> (7-num)) & 1);	//"先发高位"
		DelayKeyI2c(20);
		SetScl(1);                        //下降缘 读取
		DelayKeyI2c(20);
		SetScl(0);
		DelayKeyI2c(20);	
	}
	SetSda(1);
}


/***********************************************************
*name:    KeyI2CRead(void)
*input:   non
*output:  返回读出的字节
*update:  2009-03-25

*description:   iic的read一个字节 数据函数
*history:
************************************************************/
UCHAR KeyI2CRead(void)
{

	UCHAR XDATA temp = 0xff;
	UCHAR XDATA num;         //"接收数据位数"

	SetSdaInput();

	for(num = 0;num < 8;num ++)
	{
	  
		SetScl(1);
		DelayKeyI2c(20);
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
		DelayKeyI2c(20);
	}

	return (temp);
}
#endif


