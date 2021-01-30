/**************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� E2pI2C.C	  
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


#ifdef E2promEn

#define SetSdaOutput() ;  
#define SetSdaInput()  GetSda()
#define SetSclOutput() ;

#define GetSda()   hw_E2p_getSDA_input()
#define SetSda(x)  hw_E2p_setSDA_output(x)
#define SetScl(x)  hw_E2p_setSCL_output(x)
					 
/***********************************************************
*name:    DelayE2pI2c()
*input:   uchar delayTime   // ȷ����ʱʱ��
*output:  non
*update:  2009-03-25

*description:   iic ��ʱ����
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
*output:  ����START
*update:  2009-03-25

*description:   iic��start�źź���,��ʾ��Ҫ��ʼ�������ݴ���
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
*output:  ����STOP
*update:  2009-03-25

*description:   iic��stop �źź�����˵�����ݴ������

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
*output:  bit      //FLAG ����bit   ��general.h �ļ��ж���
*update:  2009-03-25

*description:   iic��ack �źż�⺯��  
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
*name:   ACKSend(void)
*input:  non
*output: ACK ����
*update: 2009-03-25

*description:   iic��ack �źŷ��ͺ���
*history:
************************************************************/
void E2pACKSend(void)
{
    SetSdaOutput();
	
	SetSda(0);            //"����Ӧ��λ"
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

*description:   iic��nack �źŷ��ͺ���
*history:
************************************************************/
void E2pNACKSend(void)
{
    SetSdaOutput();
	
	SetSda(1);           //"���ͷ�Ӧ��λ"
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
*output:  ����Ӧ�Ŀռ�дһ���ֽ�����
*update:  2009-03-25

*description:   iic��writeһ���ֽں��� 
                100u
*history:
************************************************************/
void E2pI2CWrite(UCHAR tempdata)
{
	UCHAR XDATA num;                           //"��������λ��"
	
	SetSdaOutput();
	
	for(num = 0;num < 8;num ++)
	{
		SetSda((tempdata >> (7-num)) & 1);	//"�ȷ���λ"
		DelayE2pI2c(2);
		SetScl(1);                        //�½�Ե ��ȡ
		DelayE2pI2c(2);
		SetScl(0);
		DelayE2pI2c(2);	
	}
	SetSda(1);
}


/***********************************************************
*name:    I2CRead(void)
*input:   non
*output:  ���ض������ֽ�
*update:  2009-03-25

*description:   iic��readһ���ֽ� ���ݺ���
*history:
************************************************************/
UCHAR E2pI2CRead(void)
{

	UCHAR XDATA temp = 0xff;
	UCHAR XDATA num;         //"��������λ��"

	SetSdaInput();

	for(num = 0;num < 8;num ++)
	{
	  
		SetScl(1);
		DelayE2pI2c(2);
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
		DelayE2pI2c(2);
	}

	return (temp);
}
#endif



