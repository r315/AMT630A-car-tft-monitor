/**************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� KeyI2C.C	  
*Version:    ��0.01
*Author:       cjinzong
*Update:       2009-03-25
*State��       try out
* 
*Description:
*    ����ļ�����������i2c ��һЩ�����Ĳ�����

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
*input:   uchar delayTime   // ȷ����ʱʱ��
*output:  non
*update:  2009-03-25

*description:   iic ��ʱ����
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
*output:  ����START
*update:  2009-03-25

*description:   iic��start�źź���,��ʾ��Ҫ��ʼ�������ݴ���
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
*output:  ����STOP
*update:  2009-03-25

*description:   iic��stop �źź�����˵�����ݴ������

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

*description:   iic��ack �źż�⺯��  
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
	       return(0);    //����˵����ACK�ź�  
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

*description:   iic��nack �źŷ��ͺ���
*history:
************************************************************/
void KeyNACKSend(void)
{
    SetSdaOutput();
	
	SetSda(1);           //"���ͷ�Ӧ��λ"
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
*output:  ����Ӧ�Ŀռ�дһ���ֽ�����
*update:  2009-03-25

*description:   iic��writeһ���ֽں��� 
                100u
*history:
************************************************************/
void KeyI2CWrite(UCHAR tempdata)
{
	UCHAR XDATA num;                           //"��������λ��"
	
	SetSdaOutput();
	
	for(num = 0;num < 8;num ++)
	{
		SetSda((tempdata >> (7-num)) & 1);	//"�ȷ���λ"
		DelayKeyI2c(20);
		SetScl(1);                        //�½�Ե ��ȡ
		DelayKeyI2c(20);
		SetScl(0);
		DelayKeyI2c(20);	
	}
	SetSda(1);
}


/***********************************************************
*name:    KeyI2CRead(void)
*input:   non
*output:  ���ض������ֽ�
*update:  2009-03-25

*description:   iic��readһ���ֽ� ���ݺ���
*history:
************************************************************/
UCHAR KeyI2CRead(void)
{

	UCHAR XDATA temp = 0xff;
	UCHAR XDATA num;         //"��������λ��"

	SetSdaInput();

	for(num = 0;num < 8;num ++)
	{
	  
		SetScl(1);
		DelayKeyI2c(20);
		temp = temp << 1;//"�Ƚ��ո�λ"

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


