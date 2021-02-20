/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� AMT_Drv.c	  
*Version:      1.0
*update:       2011-12-06
*Description:
  		   ����ļ��Ƕ�AMTӦ�������Ķ���:

  		   
*History:  yshuizhou   2011/12/06    1.0    build  this  moudle
******************************************************************************/
#define _AMT_DRV_C_
#include "Global.h"
#include "AMT_Mcu.h"
#include "AMT_Drv.h"
#include "AMT_Reg.h"
#include "WT5700.h"
#include "SystemConfig.h"


#ifdef SpiInitPannelEn

/****************************************************************************
*name:   SetSda(void)
*input:  non              
*output: non  

*description: ����SPI��Sda��״̬
*history:   yshuizhou   2013/07/06    1.0    build   this  function
*****************************************************************************/
void SetSpDat(UCHAR Data)
{
	  if(Data)
	  {
	    hw_setDout(1);
	  }
	  else
	  {
	    hw_setDout(0);
	  }
}


/****************************************************************************
*name:   SetScl(void)
*input:  non              
*output: non  

*description: ����SPI��Scl��״̬
*history:   yshuizhou   2013/07/06    1.0    build   this  function
*****************************************************************************/
void SetSpClk(UCHAR Data)
{
	  if(Data)
	  {
	    hw_setClk(1);
	  }
	  else
	  {
	    hw_setClk(0);
	  }
}


/****************************************************************************
*name:   SetCs(void)
*input:  non              
*output: non  

*description: ����SPI��Cs��״̬
*history:   yshuizhou   2013/07/06    1.0    build   this  function
*****************************************************************************/
void SetSpEna(UCHAR Data)
{
	  if(Data)
	  {
	    hw_setCs(1);
	  }
	  else
	  {
	    hw_setCs(0);
	  }
}

/****************************************************************************
*name:   SetReset(void)
*input:  non              
*output: non  

*description: ����SPI��Reset��״̬
*history:   yshuizhou   2013/07/06    1.0    build   this  function
*****************************************************************************/
void SetReset(UCHAR Data)
{
	  if(Data)
	  {
	    hw_setReset(1);
	  }
	  else
	  {
	    hw_setReset(0);
	  }
}

#endif


#ifdef BuzzerEn
/****************************************************************************
*name:   SetBuzzerOn(void)
*input:  Buzzertime              
*output: non  

*description: ���÷�������
*history:   yshuizhou   2014/02/13    1.0    build   this  function
*****************************************************************************/
void SetBuzzerOn(void)
{
#define Buzzertime   50

   UCHAR XDATA i;

   EA = OFF;
   for(i = 0;i<Buzzertime;i++)
   {
      hw_turnOnBuzzer();
      hw_BuzzerTime();
      hw_turnOffBuzzer();
      hw_BuzzerTime();
   }
   EA = ON;
}
#endif



/****************************************************************************
*name:   SetI2CDebug(void)
*input:  non              
*output: non  

*description: �˺�������SCL��SDAʹ�ܡ�
*history:   yshuizhou   2014/10/23    1.0    build   this  function
*****************************************************************************/
#ifdef UartPrintfEn  
void SetI2CDebug(void)
{
   I2C_SCL();
   I2C_SDA();
}
#endif


/****************************************************************************
*name:   SetUartPrint(void)
*input:  non              
*output: non  

*description: �˺�������Rxd��Txdʹ��
*history:   yshuizhou   2014/10/23    1.0    build   this  function
*****************************************************************************/
#ifdef UartPrintfEn  
void SetUartPrint(void)
{
   Uart_RXD();
   Uart_TXD();
}
#endif


/*************************************************************************
name:    Abs(UINT tmpVal1,UINT tmpVal2)
input:   tmpVal1��tmpVal2
output:	 ���ص�ǰ����ֵ��
update�� 2011-12-07
state��  try out
description: ���ص�ǰ����ֵ��

history: yshuizhou   2011/12/20   0.2    build  this  function
*************************************************************************/
UINT Abs(UINT tmpVal1,UINT tmpVal2)
{
   if(tmpVal1 >= tmpVal2)
   {
        return (tmpVal1-tmpVal2);
   }
   else
   {
        return (tmpVal2-tmpVal1);
   }
}


/****************************************************************************
*name:  SelectKeyDevice(void)
*input:  void              
*output: void  

*description: ѡ�����밴������(I2C KEY��ADC KEY)��

*history: yshuizhou   2012/07/16    1.0    build   this  function
*****************************************************************************/
#ifdef KeyDetectEn 
void POS_SelectKeyDevice(void)
{
#define I2C_ACCESS_LOOP_TIME       10
#define I2C_NON_ACK                 1

    UCHAR XDATA CheckAckCnt=0;
    UCHAR XDATA ucLoop;
	ucLoop = I2C_ACCESS_LOOP_TIME;

	DelayMs(100);  
	while(ucLoop--)
	{
		KeyI2CStart();    
		DelayKeyI2c(2);
		KeyI2CWrite(0XE0);
		DelayKeyI2c(1);
		if(KeyACKCheck()!=I2C_NON_ACK)
		{
           CheckAckCnt++;
		}
		DelayKeyI2c(1);
	}
	KeyI2CStop();
	if(CheckAckCnt >= I2C_ACCESS_LOOP_TIME/2)
	{   
	    printfStr("Select IIC_KEY KeyDevice");
	    g_ucSelKeyDevice =IIC_KEY;
		DelayKeyI2c(1);
		Initial_WT5700();
	}
	else
	{
	    g_ucSelKeyDevice =ADC_KEY;
		
		/*
		�ָ�P1_0Ϊ�����
		*/
		P1_IEN &= ~_BIT0;
		P1_OEN |=  _BIT0;	
	}
}
#endif


/****************************************************************************
*name:   SetIRABSwitch(UCHAR Val)
*input:  Val              
*output: void  

*description:
            �˺������ƶ�IRAB��ѡ��
*history:   yshuizhou   2013/03/07    1.0    build   this  function
*****************************************************************************/
#ifdef IrABCtrlEn
void SetIRABSwitch(UCHAR Val)
{
   switch(Val)
   {
      case IROFF:
	  	   hw_turnOffIRAB();
	  	   break;

	  case IRA:
	  	   hw_setAPort();
	  	   break;

	  case IRB:
	  	   hw_turnOffIRAB();
	  	   break;

	  default:
	  	  break;
   }
}
#endif




/****************************************************************************
*name:   SetPWM0(UINT Freq,UCHAR Duty)
*input:  Freq, Duty             
*output: void  

*description:
*history:   yshuizhou   2014/10/25    1.0    build   this  function
*****************************************************************************/
void SetPWM0(ULONG Freq,UCHAR Duty)
{
   ULONG XDATA tmpfreq;
   ULONG XDATA tmpduty;
   UCHAR XDATA tmppercent;
   
   tmpfreq = (UINT) (27000000/Freq);
   tmppercent = (UCHAR)(100/Duty);
   tmpduty = (UINT)(tmpfreq/tmppercent);
   
   PWM_CLK_SRC &=~_BIT6;
   PWM_CLK_SRC |= _BIT3;
   SelPWM0 |= (_BIT0|_BIT1);	 
   SelPWM0 &=~_BIT2;

   PWM_CTRL &=~_BIT4;
   PWM_CTRL |=  _BIT0;
   PWM0_CTRL0 = (UCHAR)(tmpfreq&0xff);
   PWM0_CTRL1 = (UCHAR)(tmpfreq>>8);
   PWM0_DUTY0 = ((UCHAR)(tmpduty&0xff));
   PWM0_DUTY1 = ((UCHAR)(tmpduty>>8));
}



/****************************************************************************
*name:   SetPWM1(UINT Freq,UCHAR Duty)
*input:  Val              
*output: void  

*description:
*history:   yshuizhou   2014/10/25    1.0    build   this  function
*****************************************************************************/
void SetPWM1(ULONG Freq,UCHAR Duty)
{
   ULONG XDATA tmpfreq;
   ULONG XDATA tmpduty;
   UCHAR XDATA tmppercent;
   
   tmpfreq = (UINT) (27000000/Freq);
   tmppercent = (UCHAR)(100/Duty);
   tmpduty = (UINT)(tmpfreq/tmppercent);
   
   PWM_CLK_SRC &=~_BIT6;
   PWM_CLK_SRC |= _BIT3;
   SelPWM1 |= (_BIT4|_BIT5);	 
   SelPWM1 &=~_BIT6;

   PWM_CTRL &=~_BIT5;
   PWM_CTRL |=  _BIT1;
   PWM1_CTRL0 = (UCHAR)(tmpfreq&0xff);
   PWM1_CTRL1 = (UCHAR)(tmpfreq>>8);
   PWM1_DUTY0 = ((UCHAR)(tmpduty&0xff));
   PWM1_DUTY1 = ((UCHAR)(tmpduty>>8));
}



/****************************************************************************
*name:   SetPWM2(UINT Val)
*input:  Val              
*output: void  

*description:
*history:   yshuizhou   2014/10/25    1.0    build   this  function
*****************************************************************************/
void SetPWM2(ULONG Freq,UCHAR Duty)
{
   ULONG XDATA tmpfreq;
   ULONG XDATA tmpduty;
   UCHAR XDATA tmppercent;
   
   tmpfreq = (UINT) (27000000/Freq);
   tmppercent = (UCHAR)(100/Duty);
   tmpduty = (UINT)(tmpfreq/tmppercent);
   
   PWM_CLK_SRC &=~_BIT6;
   PWM_CLK_SRC |= _BIT3;
   SelPWM2 |= (_BIT0|_BIT1);	 
   SelPWM2 &=~_BIT2;

   PWM_CTRL &=~_BIT6;
   PWM_CTRL |=  _BIT2;
   PWM2_CTRL0 = (UCHAR)(tmpfreq&0xff);
   PWM2_CTRL1 = (UCHAR)(tmpfreq>>8);
   PWM2_DUTY0 = ((UCHAR)(tmpduty&0xff));
   PWM2_DUTY1 = ((UCHAR)(tmpduty>>8));
}




/****************************************************************************
*name:   SetPWM3(UINT Val)
*input:  Val              
*output: void  

*description:
*history:   yshuizhou   2014/10/25    1.0    build   this  function
*****************************************************************************/
void SetPWM3(ULONG Freq,UCHAR Duty)
{
   ULONG XDATA tmpfreq;
   ULONG XDATA tmpduty;
   UCHAR XDATA tmppercent;
   
   tmpfreq = (UINT) (27000000/Freq);
   tmppercent = (UCHAR)(100/Duty);
   tmpduty = (UINT)(tmpfreq/tmppercent);
   
   PWM_CLK_SRC &=~_BIT6;
   PWM_CLK_SRC |= _BIT3;
   SelPWM3 |= (_BIT4|_BIT5);	 
   SelPWM3 &=~_BIT6;

   PWM_CTRL &=~_BIT7;
   PWM_CTRL |=  _BIT3;
   PWM3_CTRL0 = (UCHAR)(tmpfreq&0xff);
   PWM3_CTRL1 = (UCHAR)(tmpfreq>>8);
   PWM3_DUTY0 = ((UCHAR)(tmpduty&0xff));
   PWM3_DUTY1 = ((UCHAR)(tmpduty>>8));
}



/****************************************************************************
*name:   GetProCompielTime(void)
*input:  void              
*output: void  

*description:
*history:   yshuizhou   2015/1/27    1.0    build   this  function
*****************************************************************************/
extern char strcmp (char *s1, char *s2);
extern int   atoi (char *s1);
void  GetProCompielTime(void)
{
    static UCHAR CODE *MonthsBuf[] ={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug","Sep", "Oct", "Nov", "Dec"};
    UCHAR XDATA tmpDate[] = __DATE__;
	UCHAR XDATA tmpTime[] =__TIME__;
	UCHAR XDATA tmpYear,tmpMonth,tmpDay;
	UCHAR XDATA tmpHour,tmpMinute;
	UCHAR XDATA i;

	tmpYear = atoi(tmpDate + 9);
	*(tmpDate + 6) = 0;
	tmpDay = atoi(tmpDate + 4);
	*(tmpDate + 3) = 0;
    
	for (i = 0; i < 12; i++)
    {
	    if (!strcmp(tmpDate, MonthsBuf[i]))
	    {
	      tmpMonth = i + 1;
	      break;
	    }
    }
	tmpHour = atoi(tmpTime + 0);
	tmpMinute = atoi(tmpTime + 3);

    Variable_Year0 = 0X14;
    Variable_Year1 = tmpYear;
    Variable_Month = tmpMonth;
    Variable_Date  = tmpDay;
    Variable_Hour  = tmpHour;	
    Variable_Minute = tmpMinute;
}

/****************************************************************************
*name:   SysTimeDriver(void)
*input:  void            
*output: 

*description:
            ���������ϵͳʱ������������ϵͳʱ�䡣 
*history:   yshuizhou   2012/07/16    1.0    build   this  function
*****************************************************************************/
BOOL POS_SysTimeDriver(void)
{
   static UINT XDATA currenTime3Cont = 0;
   static UINT XDATA preTime3Cont = 0;
   UINT   XDATA tempValBuf;
   
   /**********��T3�ĸߵ�λ****************/
   currenTime3Cont = T3_CNTH;
   currenTime3Cont <<= 8;
   currenTime3Cont |= T3_CNTL;

   if(currenTime3Cont > preTime3Cont)
   {
        tempValBuf = currenTime3Cont - preTime3Cont;
        if(tempValBuf >= 0x5b91)                   // 1s ->0x5b91 ����ֵ
        {
            tempValBuf =tempValBuf - 0x5b91;
            currenTime3Cont -= tempValBuf;
            preTime3Cont =  currenTime3Cont;    //����
            //�����Ҫ��ʱ�Ӽ�һ��
            if(++g_ucContBufSecond >=60)
            {
               return TRUE;
            }
        }
    }
    else
    {
        tempValBuf = 0xffff - preTime3Cont;
        tempValBuf += currenTime3Cont;
        if(tempValBuf >= 0x5b91)
        {
            tempValBuf = tempValBuf - 0x5b91;
            currenTime3Cont -= tempValBuf;
            preTime3Cont =  currenTime3Cont;       //����
            //�����Ҫ��ʱ�Ӽ�һ��
            if(++g_ucContBufSecond >=60)
            {
               return TRUE;
            }
        }
    }
	return FALSE;
}




/****************************************************************************
*name:   SendNecIrData(ULONG SendData)   
*input:  CustomCode��DataCode             
*output: void  

*description:
            �˺���ר�����ڷ���NEC IR��
*history:   yshuizhou   2012/06/26    1.0    build   this  function
*****************************************************************************/
#ifdef IrSendEn
void POS_SendNecIrData(UCHAR DataWith,ULONG SendData)
{
#define _9MS_L_WITH_    		0X762
#define _4_5MS_H_WITH_  		0X3B1
#define _ONE_L_WITH_     		0X75
#define _ONE_H_WITH_     		0X160
#define _ZERO_L_WITH_    		0X75
#define _ZERO_H_WITH_    		0X75


     UINT XDATA Head_L;
     UINT XDATA head_H;
	 UINT XDATA One_L;
	 UINT XDATA One_H;
	 UINT XDATA Zero_L;
	 UINT XDATA Zero_H;

	 Head_L = _9MS_L_WITH_;
	 head_H = _4_5MS_H_WITH_;
	 One_L = _ONE_L_WITH_;
	 One_H = _ONE_H_WITH_;
	 Zero_L = _ZERO_L_WITH_;
	 Zero_H = _ZERO_H_WITH_;

	 printfStr("POS_SendNecIrData\n");
	 
	 XBYTE[0xFD31]&=~(_BIT0|_BIT2);
     XBYTE[0xFD31]|=_BIT1;

	 XBYTE[0XFF62] = 0X3F;
     XBYTE[0XFF92] = 0X00;

	 switch(DataWith)
	 {
	    case _8BIT_WITH:
			 XBYTE[0XFFA0] = (SendData&0xff);
			 XBYTE[0XFF9F] = 0X08;
			 break;

		case _16BIT_WITH:
             XBYTE[0XFFA0] = (SendData&0xff);
             XBYTE[0XFFA1] = ((SendData>>8)&0xff);
			 XBYTE[0XFF9F] = 0X10;
			 break;

		case _24BIT_WITH:
             XBYTE[0XFFA0] = (SendData&0xff);
             XBYTE[0XFFA1] = ((SendData>>8)&0xff);
             XBYTE[0XFFA2] = ((SendData>>16)&0xff);
			 XBYTE[0XFF9F] = 0X18;
		     break;

		case _32BIT_WITH:
             XBYTE[0XFFA0] = (SendData&0xff);
             XBYTE[0XFFA1] = ((SendData>>8)&0xff);
             XBYTE[0XFFA2] = ((SendData>>16)&0xff);
             XBYTE[0XFFA3] = ((SendData>>24)&0xff);
			 XBYTE[0XFF9F] = 0X20;
			 break;

		default:
			 break;
	 }     
     XBYTE[0XFF93] = (Head_L&0xff);
     XBYTE[0XFF94] = (Head_L>>8);
     XBYTE[0XFF95] = (head_H&0xff);
     XBYTE[0XFF96] = (head_H>>8);
     XBYTE[0XFF97] = (Zero_L&0xff);
     XBYTE[0XFF98] = (Zero_L>>8);
     XBYTE[0XFF99] = ((Zero_L+Zero_H)&0xff);
     XBYTE[0XFF9A] = ((Zero_L+Zero_H)>>8);
     XBYTE[0XFF9B] = (One_L&0xff);
     XBYTE[0XFF9C] = (One_L>>8);
     XBYTE[0XFF9D] = ((One_L+One_H)&0xff);
     XBYTE[0XFF9E] = ((One_L+One_H)>>8);
	 XBYTE[0XFF91]=0XFF;
}
#endif


/*************************************************************************
*name:    EnableChipAdc(AdcChannelType ADchanel)
*input:   ADchanel    ADC ͨ��ѡ��  
*output:  ���ص�ǰѡ��ͨ����ADCֵ   
*update:  2011-12-07
*state:   try out

*description:  ���ص�ǰѡ��ͨ����ADCֵ   
            
*history:  yshuizhou   2011/12/20    0.2    build  this  function	
**************************************************************************/
UINT POS_EnableChipAdc(AdcChannelType Channel)  
{
	 UINT  XDATA CurrentADC = 0XFFFF;  

	 switch(Channel)
	 {
	   case CH0:
	   	    #if AMT_TYPE == AMT630A
			P0_OEN |=  _BIT0;	
			P0_IEN |=  _BIT0;	
            #endif //AMT_TYPE == AMT630A
            SetAUX0ENA();
			SetAUX0CMD();
            CheckAUX0ValInt();		
			CurrentADC = ADC_CH0_DATA_H;
		    CurrentADC <<= 8;
		    CurrentADC |= ADC_CH0_DATA_L;			
			ClearAUXValInt();	
			break;

	  case CH1:
            #if AMT_TYPE == AMT630A
			P0_OEN |=  _BIT1; 
			P0_IEN |=  _BIT1; 
            #endif //AMT_TYPE == AMT630A
			SetAUX1ENA();
			SetAUX1CMD();
			CheckAUX1ValInt();			
		    CurrentADC = ADC_CH1_DATA_H;
		    CurrentADC <<= 8;
		    CurrentADC |= ADC_CH1_DATA_L;			
			ClearAUXValInt();
			break;

  	  case CH2:
            #if AMT_TYPE == AMT630A
			P0_OEN |=  _BIT2;
			P0_IEN |=  _BIT2;   
            #endif //AMT_TYPE == AMT630A
            SetAUX2ENA();
			SetAUX2CMD();
			CheckAUX2ValInt();						
  	        CurrentADC = ADC_CH2_DATA_H;
	        CurrentADC <<= 8;
	        CurrentADC |= ADC_CH2_DATA_L;
			ClearAUXValInt();
			break;	

#if AMT_TYPE != AMT630A
	   case CH3:
            SetAUX3ENA();
			SetAUX3CMD();
			CheckAUX3ValInt();						
  	        CurrentADC = ADC_CH3_DATA_H;
	        CurrentADC <<= 8;
	        CurrentADC |= ADC_CH3_DATA_L;
			ClearAUXValInt();
			break;
#endif

	  default:
	  	   ClearAUXValInt();
	  	   break;
	 }   	 

	 #if TP0_ADC
	 printf("TP0_ADC >> the ADC Val is = %x\n",CurrentADC);
	 #endif

     return CurrentADC;
}

/****************************************************************************
*name:   ConfigCrtlMode(UCHAR CtrlMode)
*input:  CtrlMode              
*output: void  

*description:
      MCU: ��ʾMCU������Ƶģ��,ARKchip ΪMaterģʽ.
      IIC: ��ʾIIC���ƣ�ARKchipΪSlaveģʽ��

*history: Jordan.chen   2012/01/03    1.0    transplant   this  function
*****************************************************************************/
void ConfigCrtlMode(UCHAR CtrlMode)
{
	if(CtrlMode == MCU)
	{
		MCU_CFG_REG  |= _BIT7; 
	}
	
	if(CtrlMode == IIC)
	{
		MCU_CFG_REG  &= (~_BIT7);
	}
}

/****************************************************************************
*name:   TurnOffBackLight(void)
*input:  void              
*output: void  

*description:
      �رձ��⺯����

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void TurnOffBackLight(void)
{   
    printfStr("TurnOffBackLight");
	if(g_bBackLightFlg)
	{
	    g_bBackLightFlg = OFF;
		
		#ifdef BacklightEn
	    hw_clrBacklight(); 
		#endif
		
		DelayMs(100);
		
        #ifdef BacklightEn
        hw_clrBIASEn();
        #endif

	}
}




/****************************************************************************
*name:	 TurnOnBackLight(void)
*input:  void			   
*output: void  

*description:
	  �򿪱��⺯����

*history: Jordan.chen	2011/12/16	  1.0	 transplant   this	function
*****************************************************************************/
void TurnOnBackLight(void)
{   
    printfStr("TurnOnBackLight");
	if(!g_bBackLightFlg)
	{   
		g_bBackLightFlg = ON;

        #ifdef BacklightEn
        hw_setBIASEn();
        #endif
		
		DelayMs(100);	

		#ifdef BacklightEn
	    hw_setBacklight();
		#endif
	}
}




/****************************************************************************
*name:   EnterLowPowerMode(void)
*input:  void              
*output: void  

*description:
      �����͹��ĺ���

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void EnterLowPowerMode(void)
{
    printfStr("EnterLowPowerMode\n");

    CLK_GATE0_EN &=~(_BIT7|_BIT6|_BIT5);
	CLK_GATE1_EN &=~(_BIT7|_BIT6|_BIT5|_BIT2|_BIT1|_BIT0);
	CLK_GATE2_EN &=~(_BIT7|_BIT6|_BIT5|_BIT4|_BIT3|_BIT2|_BIT1|_BIT0);
	ENH_PLL &=~(_BIT3|_BIT2);
	VIDEO_SOG_EN &=~(_BIT1|_BIT0);
}


/****************************************************************************
*name:   ExitLowPowerMode(void)
*input:  void              
*output: void  

*description:
      �˳������͹��ĺ���

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void ExitLowPowerMode(void)
{
	printfStr("ExitLowPowerMode\n");

    CLK_GATE0_EN |=(_BIT7|_BIT6|_BIT5);
	CLK_GATE1_EN |=(_BIT7|_BIT6|_BIT5|_BIT2|_BIT1|_BIT0);
	CLK_GATE2_EN |=(_BIT7|_BIT6|_BIT5|_BIT4|_BIT3|_BIT2|_BIT1|_BIT0);
	ENH_PLL |=(_BIT3|_BIT2);
	VIDEO_SOG_EN |=(_BIT1|_BIT0);
	DelayMs(200);
}



/****************************************************************************
*name:   SetAudioMute(void)
*input:  void              
*output: void  

*description:
      ��������

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
#ifdef AudioCtrlEn
void SetAudioMute(void)
{
   printfStr("SetAudioMute");

   #if AUDIO_CTRL == VOLUME_PWM_CTRL
   CtrlVolumeByPWM(0);
   #endif
   
   DelayMs(300); 
   hw_setAudioMute();
}
#endif



/****************************************************************************
*name:   OpenAudio(void)
*input:  void              
*output: void  

*description:
      ������

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
#ifdef AudioCtrlEn
void OpenAudio(void)
{
    printfStr("OpenAudio");
	
    if(g_bBackLightFlg)
    {
        hw_clrAudioMute();

		#if AUDIO_CTRL == VOLUME_PWM_CTRL
		CtrlVolumeByPWM(g_sysSetting.Audio.volVal);
	    #endif
    }
}
#endif




/*************************************************************************
*name:    CtrlVolumeByPWM(UCHAR tmpVolume)
*input:   tmpVolume
*output:  void

*description: ��������
            
*history:     yshuizhou   2012/06/26    1.0    build   this  function
**************************************************************************/
#ifdef AudioCtrlEn
#if AUDIO_CTRL == VOLUME_PWM_CTRL  
void CtrlVolumeByPWM(UCHAR tmpVolume)
{   
									
   static CODE UCHAR soundWave[101] = {255,200,150,63,47,45,45,43,43,42,42,42,42,40,40,40,40,37,37,37,37,35,35,35,35,32,32,32,32,32,29,29,\
                                         29,29,29,27,27,27,27,27,25,25,25,25,25,23,23,23,23,23,20,20,20,20,20,17,17,17,17,17,15,15,15,\
                                         15,15,13,13,13,13,13,11,11,11,11,11,9,9,9,9,9,7,7,7,7,7,5,5,5,5,5,3,3,3,3,3,2,2,2,2,1,0};
   switch(VOL_PWM_TYPE)
   {
      case PWM0:
	  	   PWM_CTRL |= _BIT0; 
	  	   break;
		   
	  case PWM1:
	  	   PWM_CTRL |= _BIT1; 
	  	   break;

	  case PWM2:
	  	   PWM_CTRL |= _BIT2; 
	  	   break;

	  case PWM3:
	  	   PWM_CTRL |= _BIT3; 
	  	   break;
		   
	  default:
	  	   break;
   }
   VOL_PWM_CTRL = 0XFF;
   VOL_PWM_RATE = soundWave[tmpVolume];
}
#endif
#endif



/****************************************************************************
*name:   SelAudioInputSource(InputSourceType curSource)
*input:  curSource  ��ǰ�ź�Դ              
*output: void  

*description:

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
#ifdef AudioCtrlEn
void SelAudioInputSource(InputSourceType curSource)
{
    switch(curSource)
    {
       case INPUT_AV1:
	   	    hw_SetAudioSelToAv1();
	   	    break;
	   
       case INPUT_AV2:
	   	    hw_SetAudioSelToAv2();
	   	    break;

	   case INPUT_CAMERA_Car:
	   		hw_SetAudioSelToAv2();
	   	    break;
	   
	   	default:
	   	   break;
    }
}
#endif





/****************************************************************************
*name:   SetVDETestSwitch(UCHAR blueScreeSw)
*input:  blueScreeSw               
*output: void  

*description:
      ����ͼѡ��

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/	
void SetVDETestSwitch(UCHAR ScreeSw)
{    
     switch(ScreeSw)
	 {
	   case VDE_RED:
	   	    VDE_REG = 0X50;
	   	    break;

	   case VDE_GREEN:
	   	    VDE_REG = 0X51;
	   	    break;

	   case VDE_BLUE:
	   	    VDE_REG = 0X52;
	   	    break;

	   case VDE_GRAY:
	   	    VDE_REG = 0X53;
	   	    break;
			
	   case VDE_BLACK:
	   	    VDE_REG = 0X54;
	   	    break;

	   case VDE_WHITE:
	   	    VDE_REG = 0X55;
	   	    break;
			
       case VDE_CLOSE:
	   	    VDE_REG = 0X4F;
	   	    break;
			 
	   default:
	   	   break;
	 }
	 DelayMs(100);
}


/****************************************************************************
*name:   SetNoSignalSnow(void)
*input:  void               
*output: void  

*description:
      ���ź�ѩ����

*history: yshuizhou   2014/11/03    1.0    transplant   this  function
*****************************************************************************/	
#ifdef NoSignalSnowEn
void SetNoSignalSnow(void)
{
   VP_EN_REG |= _BIT7;
   SNOW_BIG_SEL = 0X6C;
}
#endif


/****************************************************************************
*name:   TurnOnDevicePower(InputSourceType curSource)
*input:  curSource  ��ǰ�ź�Դ              
*output: void  

*description:
       ����Χ�豸��Դ

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void TurnOnDevicePower(InputSourceType curSource)
{
	switch(curSource)
    {
       case INPUT_AV1:
	   	    break;
	   
       case INPUT_AV2:
	   	    break;

	   case INPUT_CAMERA_Car:			 
	   	    break;
	   
	   	default:
	   	   break;
    }
}


/****************************************************************************
*name:   SelVideoDevice(InputSourceType curSource)
*input:  curSource  ��ǰ�ź�Դ              
*output: void  

*description:
      ��������

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void SelVideoDevice(InputSourceType curSource)
{
	switch(curSource)
    {
       case INPUT_AV1:
	   	    #if(AV2 == CVBS1)
			hw_SelSOG1In()
			#elif(AV2 == CVBS2)
            hw_SelSOG2In();
			#elif(AV2 == CVBS3)
            hw_SelSOG3In();
			#endif

	   	    SelAv1Channel();
	   	    break;
	   
       case INPUT_AV2:
	   	    SelSOGNULLIn();
	   	    SelAv2Channel();
	   	    break;
			
	   case INPUT_CAMERA_Car:
			#if(AV1 == CVBS1)
			hw_SelSOG1In()
			#elif(AV1 == CVBS2)
            hw_SelSOG2In();
			#elif(AV1 == CVBS3)
            hw_SelSOG3In();
			#endif
			
	   	    SelCarChannel();
	   	    break;
	   
		case INPUT_NULL:
	   	default:
			SelSOGNULLIn();
			SelNullChannel();
	   	   break;
    }
}
/****************************************************************************
*name:   TurnOffDevicePower(InputSourceType curSource)
*input:  curSource  ��ǰ�ź�Դ              
*output: void  

*description:
       �ر���Χ�豸��Դ

*history: Jordan.chen   2011/12/16    1.0    transplant   this  function
*****************************************************************************/
void TurnOffDevicePower(InputSourceType curSource)
{
	switch(curSource)
    {
       case INPUT_AV1:
	   	    break;
	   
       case INPUT_AV2:
	   	    break;

	   case INPUT_CAMERA_Car:
	   	    break;
	   
	   	default:
	   	   break;
    }
}


/****************************************************************************
*name:   InitRemote(void)
*input:  void              
*output: void  

*description:
      ARK�����ʼ������

*history: 
   1.Jordan.chen   2011/12/10    1.0    buil   this  function
*****************************************************************************/
#ifdef IrDetectEn
void InitRemote(void)
{ 

#define REPEAT_CODE1_L 	0X76
#define REPEAT_CODE1_H 	0X1C
#define REPEAT_CODE2_L 	0X08
#define REPEAT_CODE2_H 	0xF5
#define _9MS_L_WITH    	0X76
#define _4_5MS_H_WITH  	0X3B
#define ONE_L_WITH     	0X08
#define ONE_H_WITH     	0X15
#define ZERO_L_WITH    	0X07
#define ZERO_H_WITH    	0X08

    P0_IEN &= ~_BIT3;  
    P0_OEN |=  _BIT3;
	
	#if IR_DECODE_MODE == IR_HARDWARE
    #if IR_TYPE == NEC
	//ϵͳ���ã��û�һ�㲻��Ҫ�޸�һ�¼Ĵ���ֵ��
	XBYTE[0XFF82] = 0X01;//����Э�����ͣ����ݼ��ԣ����弫�ԡ�
    XBYTE[0XFF62] = 0x3f;//ʱ�ӷ�Ƶ ��27M��Ƶ��
	XBYTE[0XFF63] = 0x10;//ë���˲�
	XBYTE[0XFF64] = 0x04;//ѡ��ʱ����Чλ����
    XBYTE[0XFF6B] = 0x00;//
    XBYTE[0XFF6C] = 0x00;//
    XBYTE[0XFF6D] = 0x00;//
    XBYTE[0XFF6E] = 0x00;//
	XBYTE[0XFF79] = 0x01;//�����жϺ�����
    XBYTE[0XFF7A] = 0x73;//���ú������ģʽ �������Ƿ��жϿͻ���
    XBYTE[0XFF7B] = 0xff;//
    XBYTE[0XFF7C] = 0x02;// 
    XBYTE[0XFF77] = 0x59;//�ͷ�ʱ�������
	XBYTE[0XFF78] = 0x00;
    
    //�û���Ҫ�����޸ĵļĴ���
    XBYTE[0XFF65] = _9MS_L_WITH;//start 9ms  
    XBYTE[0XFF66] = _4_5MS_H_WITH;//start 4.5ms
    XBYTE[0XFF67] = ONE_L_WITH;//"1" 560us  
    XBYTE[0XFF68] = ONE_H_WITH;//"1" 1.68ms
	XBYTE[0XFF69] = ZERO_L_WITH;// "0" 560us
	XBYTE[0XFF6A] = ZERO_H_WITH;// "0" 560us
	
    XBYTE[0XFF6F] = REPEAT_CODE1_L;
    XBYTE[0XFF70] = REPEAT_CODE1_H; 
    XBYTE[0XFF71] = REPEAT_CODE2_L; 
    XBYTE[0XFF72] = REPEAT_CODE2_H;
    
    XBYTE[0XFF61] = IR_Delta_DATA;//delta :����ֵΪ�� repeat �ܳ������ݵ�delta.	
    XBYTE[0XFF7D] = IR_Delta_96ms;//delta :ר���ṩ��repeat����һ���������õġ�
	#endif
	#endif

	#if IR_DECODE_MODE == IR_SOFTWARE
	XBYTE[0XFF82] = 0X01;//����Э�����ͣ����ݼ��ԣ����弫�ԡ�
    XBYTE[0XFF62] = 0x3f;//ʱ�ӷ�Ƶ ��24M��Ƶ��
	XBYTE[0XFF63] = 0x10;//ë���˲�
	XBYTE[0XFF64] = 0x04;//ѡ��ʱ����Чλ����
	XBYTE[0XFF79] = 0x01;//�����жϺ�����
    XBYTE[0XFF7A] = 0x01;//����Ϊ��������ģʽ��   
	#endif

	printfStr("InitRemote\n");

}
#endif

/****************************************************************************
*name:   POS_GetIrKeyVal(void)
*input:  void              
*output: curIrKey  

*description:
      ��ȡIr����ֵ

*history: 
   1.Jordan.chen   2011/12/19    1.0    buil   this  function
*****************************************************************************/
#ifdef IrDetectEn
UINT POS_GetIrKeyVal(void)
{
	g_uwCustomCode = XBYTE[0XFF85];
	g_uwCustomCode <<= 8;
	g_uwCustomCode |= XBYTE[0XFF83];

	#if TP0_RM
	IrqPrintf("\nTP0_RM >> custom code = %x \n", g_uwCustomCode);
	IrqPrintf("TP0_RM >> Ir key val = %x \n", R_KEY_VALUE);
	#endif
	
	if(g_uwCustomCode == IR_CUSTOM_CODE)
	{
		g_ucRemoteKeyVal = (g_uwCustomCode&0XFF00)|R_KEY_VALUE;
        R_KEY_VALUE = 0XFF;
	}
	else
	{
        R_KEY_VALUE = 0XFF;
		g_ucRemoteKeyVal = 0xFFFF;
	}

	return g_ucRemoteKeyVal;
}
#endif

/****************************************************************************
*name:   InitAdc(void)
*input:  void              
*output: void  

*description:
      ��ʼ��ADC 

*history: 
   1.Jordan.chen   2012/01/06    1.0    buil   this  function
*****************************************************************************/
void InitAdc(void)
{		
    //adc clock:
    ADC_CLOCK = 0X18;//0x18 -> 1Mhz,0x0B  -> 2Mhz,0x08 -> 3Mhz,0x06 -> 4Mhz,0x04 -> 6Mhz
	
	//adc mode:
	ADC_CTRL_H = 0X20;  
	ADC_CTRL_M = 0X0F; 
	ADC_CTRL_L = 0X00;
	
	//adc config
	ADC_CFG_L = 0X22;
	ADC_CFG_H = 0X37;
	
	//adc debounce counter
	ADC_DBNCE_CNT_L = 0XFF;
	ADC_DBNCE_CNT_M = 0X0F;
	ADC_DBNCE_CNT_H = 0X00;

	//adc transform interval
	ADC_INTER_TIME_L=0xFF;
	ADC_INTER_TIME_H=0x0F; 

	//adc status
	ADC_INT_STATUS_L =0X00;
    ADC_INT_STATUS_H =0X00 ;
	
   	//adc interupt mask
	ADC_INT_M_L = 0XFF; 
	ADC_INT_M_H = 0XFF;
	
	printfStr("InitAdc");
}


/****************************************************************************
*name:   InitCarReversing(void)
*input:    void              
*output:  void  

*description:
        ��ʼ���������ģ��

*history: 
   1.Jordan.chen   2011/12/19    1.0    buil   this  function
*****************************************************************************/
#ifdef CarBackEn
#ifdef CarReversingSignalDetectEn 
void InitCarReversing(void)
{
	VIDEO_SOG_EN |=(_BIT4|_BIT2); 
	VIDEO_SOG_EN |=_BIT3; 
	TRIM_VT_SOG |=(_BIT4|_BIT3|_BIT1|_BIT0);
	TRIM_VT_SOG &=~(_BIT5|_BIT2);
	TRIM_VIN2_SOG &=~(_BIT5|_BIT4);
	TRIM_VIN2_SOG |=_BIT6;
	TRIM_VREF1_SOG &=~_BIT7; 
	COMPHV_DETECT_EN |=_BIT4;
	COMPHV_EXIT_THR = 0X30;
	COMPHV_HDIFF = 0X40;
}
#endif
#endif
/****************************************************************************
*name:   InitiaGlobalClk(void)
*input:  void              
*output: void  

*description:
      ARK ��ʼ��ģ��ʱ�ӡ�

*history: 
   1.Jordan.chen   2011/12/19    1.0    buil   this  function
*****************************************************************************/
void InitGlobalPara()
{
    printfStr("InitGlobalPara");
	
	InitAMT();  
	ConfigPadMuxPara();
	ConfigStaticPara(g_sysSetting.Video.curSource); 
	SelVideoDevice(INPUT_NULL); 
	ConfigDispZoomDynPara(DISP_16_9);
	ConfigColorSysDynPara(PAL);
	ConfigUserParaSetting();
	ENH_PLL = 0X2C;  
	DelayMs(100); 
	DECODER_RST |=_BIT0;
	DelayMs(10); 
	DECODER_RST &=~_BIT0;
}

