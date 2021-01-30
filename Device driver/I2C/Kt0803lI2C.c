/**************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� KT0803LI2C.C	  
*Version:    ��0.01
*Author:       cjinzong
*Update:       2009-03-25
*State��       try out
* 
*Description:
*    ����ļ�����������KT0803LI2C ��һЩ�����Ĳ�����

*History:
*
****************************************************************/

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "AMT_Drv.h"


#ifdef FmSendEn
#if(FM_CHIP == KT0803l)

#define SetSdaOutput() ;  
#define SetSdaInput()  GetSda()
#define SetSclOutput() ;

#define GetSda()   hw_FmSend_getSDA_input()
#define SetSda(x)  hw_FmSend_setSDA_output(x)
#define SetScl(x)  hw_FmSend_setSCL_output(x)


/***********************************************************
*name:    DelayKt0803lI2c()
*input:   UINT delayTime   // ȷ����ʱʱ��
*output:  non
*update:  2009-03-25

*description:   iic ��ʱ����
*history:
************************************************************/
void DelayKt0803lI2c(UINT delayTime)	
{
	while(delayTime) 
	{
	    delayTime = delayTime - 1;
    }   
} 
/**********************************************************
*name:    Kt0803lI2CStart(void)
*input:   non
*output:  ����START
*update:  2009-03-25

*description:   iic��start�źź���,��ʾ��Ҫ��ʼ�������ݴ���
          start : 14*1.085=15.9u

*history:
***********************************************************/
void Kt0803lI2CStart(void)
{  
	SetSdaOutput();
    SetSclOutput();

	DelayKt0803lI2c(5);
						//___
	SetSda(1);			//	 |
	SetScl(1);			//	|___SDA
	DelayKt0803lI2c(10);    //____	
	SetSda(0);			//	  |
	DelayKt0803lI2c(10);  //	 |__SCL
	SetScl(0);	
	DelayKt0803lI2c(10);

}
/***********************************************************
*name:    Kt0803lI2CStop(void)
*input:   non
*output:  ����STOP
*update:  2009-03-25

*description:   iic��stop �źź�����˵�����ݴ������

            stop : 13*1.085 = 14.1u
*history:
************************************************************/
void Kt0803lI2CStop(void)
{   
    SetSdaOutput();
                      //    ___SDA
	SetSda(0);		  //   |
	SetScl(1);			  //___|
	DelayKt0803lI2c(5);	  //_______SCL
	SetSda(1);		  //
	DelayKt0803lI2c(5);	  //

}
/***********************************************************
*name:    Kt0803lACKCheck(void)
*input:   non
*output:  bit      //FLAG ����bit   ��general.h �ļ��ж���
*update:  2009-03-25

*description:   iic��ack �źż�⺯��  
                ACKCheck = 14u
*history:
************************************************************/
FLAG Kt0803lACKCheck(void)
{
    UCHAR loop = 200;
	
    SetSdaInput();
	
	DelayKt0803lI2c(2);								   
	SetScl(1);
	do
	{
	    DelayKt0803lI2c(2);
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
*name:   Kt0803lNACKSend(void)
*input:  non
*output: NACK send
*update: 2009-03-25

*description:   iic��nack �źŷ��ͺ���
*history:
************************************************************/
void Kt0803lNACKSend(void)
{
    SetSdaOutput();
	
	SetSda(1);           //"���ͷ�Ӧ��λ"
	DelayKt0803lI2c(2);
	SetScl(1);	
	DelayKt0803lI2c(2);
	SetScl(0);	
	DelayKt0803lI2c(2);
	SetSda(1);	
}


/***********************************************************
*name:    Kt0803lI2CWrite(UCHAR tempdata)
*input:   UCHAR tempdata
*output:  ����Ӧ�Ŀռ�дһ���ֽ�����
*update:  2009-03-25

*description:   iic��writeһ���ֽں��� 
                100u
*history:
************************************************************/
void Kt0803lI2CWrite(UCHAR tempdata)
{
	UCHAR XDATA num;                           //"��������λ��"
	
	SetSdaOutput();
	
	for(num = 0;num < 8;num ++)
	{
		SetSda((tempdata >> (7-num)) & 1);	//"�ȷ���λ"
		DelayKt0803lI2c(2);
		SetScl(1);                        //�½�Ե ��ȡ
		DelayKt0803lI2c(2);
		SetScl(0);
		DelayKt0803lI2c(2);	
	}
	SetSda(1);
}


/***********************************************************
*name:    Kt0803lI2CRead(void)
*input:   non
*output:  ���ض������ֽ�
*update:  2009-03-25

*description:   iic��readһ���ֽ� ���ݺ���
*history:
************************************************************/
UCHAR Kt0803lI2CRead(void)
{

	UCHAR XDATA temp = 0xff;
	UCHAR XDATA num;         //"��������λ��"

	SetSdaInput();

	for(num = 0;num < 8;num ++)
	{
	  
		SetScl(1);
		DelayKt0803lI2c(2);
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
		DelayKt0803lI2c(2);
	}

	return (temp);
}
#endif
#endif
