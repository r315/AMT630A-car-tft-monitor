/****************************************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Kt0803.c
*Version:    　0.01
*Author:       yshuizhou
*Update:       2012-05-22

*Description:
*          这个文件是初始化Kt0803l。 
*History:
*
***************************************************************************************************/
#define _Kt0806l_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Kt0803l.h"
#include "debug.h"
#include "Delay.h"
#include "AMT_Reg.h"
#include "AMT_Drv.h"
#include "AMT_Mcu.h"


#define I2C_ACCESS_LOOP_TIME   		  20
#define I2C_NON_ACK                      1


#ifdef FmSendEn
#if(FM_CHIP == KT0803l)
void WriteKt0803l(UCHAR Address,UCHAR Data)
{  
     UCHAR XDATA ucLoop;
	 ucLoop = I2C_ACCESS_LOOP_TIME;

	 while(ucLoop--)
	 {
		Kt0803lI2CStart();    
		DelayKt0803lI2c(2);
		Kt0803lI2CWrite(0X7C);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}
    
		Kt0803lI2CWrite(Address);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}

		Kt0803lI2CWrite(Data);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}
		break;
	 }	
	 Kt0803lI2CStop();
}


UCHAR ReadKt0803l(UCHAR subAddr)
{
	UCHAR tmpRd;
    UCHAR XDATA ucLoop;
	ucLoop = I2C_ACCESS_LOOP_TIME;

	while(ucLoop--)
	{
		Kt0803lI2CStart();    
		DelayKt0803lI2c(2);
		Kt0803lI2CWrite(0X7C);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}

		Kt0803lI2CWrite(subAddr);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}

		Kt0803lI2CStart();    
		DelayKt0803lI2c(2);
		Kt0803lI2CWrite(0X7D);
		DelayKt0803lI2c(1);
		if(Kt0803lACKCheck()==I2C_NON_ACK)
		{
		  continue;
		}

		tmpRd = Kt0803lI2CRead(); 
		DelayKt0803lI2c(1);
		Kt0803lNACKSend();
		break;
	}

	Kt0803lI2CStop();		
	return(tmpRd);
}



void KT_Bus_Write(UCHAR Register_Address, UCHAR Byte_Data)
{
	WriteKt0803l(Register_Address,Byte_Data);
}

UCHAR KT_Bus_Read(UCHAR Register_Address)
{
	return( ReadKt0803l(Register_Address));
}

BOOL KT_TXPreInit(void)
{
	BYTE i,reg10;

    #ifdef PA_CTRL
	BYTE reg13;
	reg13=KT_Bus_Read(0x13);
	KT_Bus_Write(0x13,reg13 | 0x04);
    #endif

	for (i=0;i<INIT_FAIL_TH;i++)
	{
		DelayMs(5);
		reg10=KT_Bus_Read(0x22);
		//if (reg10!=0x01) continue;
		break;
	}
  	if (i==INIT_FAIL_TH) return(0);

    #ifdef X32P768K
	KT_Bus_Write(0x1E,0x40);
	reg10=KT_Bus_Read(0x17);
	KT_Bus_Write(0x17,reg10 & 0xF7);
    #endif

    #ifdef X7P6M
	KT_Bus_Write(0x1E,0x42);
	reg10=KT_Bus_Read(0x17);
	KT_Bus_Write(0x17,reg10 | 0x08);
    #endif

    #ifdef R7P6M
	KT_Bus_Write(0x1E,0x62);
    #endif

    #ifdef R7P6MPIN2
	reg10=KT_Bus_Read(0x17);
	KT_Bus_Write(0x17,reg10 | 0x08);
	KT_Bus_Write(0x1E,0x42);
	reg10=KT_Bus_Read(0x0D);
	KT_Bus_Write(0x0D,reg10 | 0x02);
    #endif

    #ifdef R12M
	KT_Bus_Write(0x1E,0x63);
    #endif

    #ifdef R12MPIN2
	reg10=KT_Bus_Read(0x17);
	KT_Bus_Write(0x17,reg10 | 0x08);
	KT_Bus_Write(0x1E,0x43);
	reg10=KT_Bus_Read(0x0D);
	KT_Bus_Write(0x0D,reg10 | 0x02);
    #endif

    #ifdef R24M
	KT_Bus_Write(0x1E,0x67);
    #endif
	
	return(1);
}



void KT_TXMono (BYTE forcemono)		// setting mono or stereo
{
	BYTE reg4;
	reg4 = KT_Bus_Read( 0x04);
	KT_Bus_Write( 0x04, (reg4 & 0xBF) | (forcemono<<6) ); 							
}


void KT_TXPETCS (BYTE Pre_Emphasis_Value)		// KT0806 Pre-Emphasis Time-Constant Set
{
	BYTE reg2;

	reg2 = KT_Bus_Read( 0x02);
	if( Pre_Emphasis_Value == 50 )
	{
		KT_Bus_Write( 0x02, reg2 | 0x01);		// Pre-Emphasis Time-Constant = 50us
	}
	if( Pre_Emphasis_Value == 75 )
	{
		KT_Bus_Write( 0x02, reg2 & 0xFE);					// Pre-Emphasis Time-Constant = 75us
	}
}



void KT_TXAudio_PGA (BYTE PGA_Value)		// Audio Gain range is 0-27
{
	BYTE reg1,reg4,temp;
	if(PGA_Value <= 15)
	{
		temp = 15 - PGA_Value;
		reg1 = KT_Bus_Read( 0x01);
		KT_Bus_Write( 0x01, (reg1 & 0xC7) | ((temp & 0x1C) << 1));
		reg4 = KT_Bus_Read( 0x04);
		KT_Bus_Write( 0x04, (reg4 & 0xCF) | ((temp & 0x03) << 4));
	}
	else
	{
		temp = 4 + PGA_Value;
		reg1 = KT_Bus_Read( 0x01);
		KT_Bus_Write( 0x01, (reg1 & 0xC7) | ((temp & 0x1C) << 1));
		reg4 = KT_Bus_Read( 0x04);
		KT_Bus_Write( 0x04, (reg4 & 0xCF) | ((temp & 0x03) << 4));
	}
}



void KT_TXRFGAIN (BYTE rf_gain, BYTE pa_bias)		// RF Gain range is 0-15
{
	BYTE reg1,reg2,regE,reg13;
	regE = KT_Bus_Read( 0x0E);
	KT_Bus_Write( 0x0E, (regE & 0xFD) | pa_bias<<1);

	reg1 = KT_Bus_Read( 0x01);
	KT_Bus_Write( 0x01, (reg1 & 0x3F) | ((rf_gain & 0x03) << 6) );

	reg13 = KT_Bus_Read( 0x13);
	KT_Bus_Write( 0x13, (reg13 & 0x7F) | ((rf_gain & 0x04) << 5));

	reg2 = KT_Bus_Read( 0x02);
	KT_Bus_Write( 0x02,	(reg2 & 0xBF) | ((rf_gain & 0x08) << 3));
}


BOOL KT_TXInit (void)
{ 
	BYTE i,reg10;

   for (i=0;i<INIT_FAIL_TH;i++)
	{
    	DelayMs(500);
  	    reg10=KT_Bus_Read(0x0F);			//Read power-up indicator
 		if ((reg10&0x50)!=0x50) continue;
		break;
    }
  	if (i==INIT_FAIL_TH) return(0);
	reg10 = KT_Bus_Read( 0x10);		// PGA Mode = 1dB step 
	KT_Bus_Write( 0x10, (reg10 & 0xFE) | 0x01);

	KT_TXMono(STEREO);
	KT_TXPETCS(75);							// Pre-Emphasis Time-Constant is 75us
	KT_TXAudio_PGA(IAL);						// Audio PGA is -15dB
	KT_TXRFGAIN(TRL,PA_BIAS);					// RF Gain is Max level
	
	return(1);
	
}	


#if 0
BOOL KT_TXStandby(void)
{
	BYTE regB;
	regB = KT_Bus_Read (0x0B);
	KT_Bus_Write(0x0B, regB | 0x80);
	return(1);
}

BOOL KT_TXWakeUp(void)
{
	BYTE regB;
	regB = KT_Bus_Read (0x0B);
	KT_Bus_Write(0x0B, regB & 0x7F);
	return(KT_TXInit());
}

void KT_TXMute (void)
{
	BYTE reg2;
	reg2 = KT_Bus_Read( 0x02);
	KT_Bus_Write( 0x02, reg2 | 0x08);
}

void KT_TXUnMute (void)
{
	BYTE reg2;
	reg2 = KT_Bus_Read( 0x02);
	KT_Bus_Write( 0x02, reg2 & 0xF7);
}

void KT_TXBass (BYTE bass_value)	 // setting KT0806 Bass level (0-3)
{
	BYTE reg4;
	reg4 = KT_Bus_Read( 0x04);
	KT_Bus_Write( 0x04, (reg4 & 0xFC) | bass_value); 							
}
#endif


void KT_TXTune (WORD Frequency)		// Exemple :91.55MHz---> *Freqency = 9155;
{
	BYTE reg1,reg2;
	Frequency = Frequency / 5;
	KT_Bus_Write( 0x00, (Frequency & 0x01FE) >>1);
	reg1 = KT_Bus_Read( 0x01);
	KT_Bus_Write( 0x01, (reg1 & 0xF8 ) | ((Frequency & 0x0E00) >> 9) );
	reg2 = KT_Bus_Read( 0x02);

	if ( Frequency & 0x0001)			// if frequency = XX.X5 MHz
	{
		KT_Bus_Write( 0x02, reg2 | 0x80);
	}
	else
	{
		KT_Bus_Write( 0x02, reg2 & 0x7F);	
	}	
}


void KT_TXInitTune(UCHAR RFVal)
{
	  switch(RFVal)
	{
	   case MHZ_877:
	        KT_TXTune(8770);
			break;
			
	   case MHZ_879:
	        KT_TXTune(8790);
			break;
			
       case MHZ_881:
	        KT_TXTune(8810);
			break;

	   case MHZ_883:
	        KT_TXTune(8830);
			break;

	   case MHZ_885:
	        KT_TXTune(8850);
			break;

	   case MHZ_887:
	        KT_TXTune(8870);
			break;
			
	   case MHZ_889:
	        KT_TXTune(8890);
			break;

	   case MHZ_891:
	        KT_TXTune(8910); 
			break;
			
	  default:
	        KT_TXTune(8660);
			break;
	}
}
#endif  //#if(FM_CHIP == KT0803l)
#endif //#ifdef FmSendEn
