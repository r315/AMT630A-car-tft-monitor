/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� SysWorkPara.c
*Version:    ��0.1
*Author:       Jordan.chen
*update:       2011-12-19

*Description:
            ��Ҫ��ϵͳ���ò����Ĺ�����
*History:  

************************************************************************/
#define _SYS_WORK_PARA_C_
#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Debug.h"
#include "Delay.h"
#include "Flash.h"
#include "E2prom.h"
#include "MsgMap.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "sysWorkPara.h"
#include "ConfigLcdPara.h"
#include "AMT_Reg.h"


UCHAR ContSysCheckSum(UCHAR *pSysPara, UINT numOper)
{
    UINT XDATA i;
	UCHAR  XDATA tmpCheckSum = 0x00;
	 
	for(i = 0; i < numOper; i++)
	{
	    tmpCheckSum ^= pSysPara[i];
	}
	return(tmpCheckSum);  
}

/************************************************************************
*name:    CheckSetting(void)
*input:   non   
*output:  non  

*description:   
     	 ��������������ϵͳ�������ٽ�ֵ,���һ�������г��������ݣ��ͻ�
		 �������������ݻָ�ΪĬ��ֵ�� 
*history:  
*************************************************************************/
void CheckSetting(void)
{
	printfStr("CheckSetting");
	if(g_sysSetting.Video.curSource >= MAX_VIDEO_CHANNEL)
	{
	     g_sysSetting.Video.curSource  = DefaultSource; 
	}
	if( g_sysSetting.Car.RemberSource >= MAX_VIDEO_CHANNEL)
	{
	     g_sysSetting.Car.RemberSource  = DefaultSource; 
	}
	if(g_sysSetting.Video.brigthness>MAX_VALUE)
	{
	     g_sysSetting.Video.brigthness = MAX_VALUE/2;
	}
	if(g_sysSetting.Video.saturation>MAX_VALUE)
	{
	     g_sysSetting.Video.saturation = MAX_VALUE/2;
	}
	if(g_sysSetting.Video.contrast>MAX_VALUE)
	{
	     g_sysSetting.Video.contrast = MAX_VALUE/2;
	}
    if(g_sysSetting.Video.tint>MAX_VALUE)
	{
	     g_sysSetting.Video.tint = MAX_VALUE/2;
	}
	if(g_sysSetting.Audio.volVal>MAX_VALUE)
	{
	     g_sysSetting.Audio.volVal = MAX_VALUE/2;
	}	
	if(g_sysSetting.Disp.zoomMode>DISP_4_3)
	{
	     g_sysSetting.Disp.zoomMode = DISP_16_9;
	}
	if(g_sysSetting.Disp.flipMode>FilpDown)
	{
	    g_sysSetting.Disp.flipMode = FilpLeft;
	}
	if(g_sysSetting.Osd.curlanguage>MAX_LANG)
	{
	   g_sysSetting.Osd.curlanguage = DEFAULT_LANGUAGE;
	}
	if(g_sysSetting.Osd.xOffset>MAX_OFFSETVALUE)
	{
	   g_sysSetting.Osd.xOffset = 0;
	}
	if(g_sysSetting.Osd.yOffset>MAX_OFFSETVALUE)
	{
	   g_sysSetting.Osd.yOffset = 0;
	}	
	if(g_sysSetting.IRAB.IRABVal>IRB)
	{
	   g_sysSetting.IRAB.IRABVal = IROFF;
	}
    if(g_sysSetting.IRAB.IRABVal>IRB)
	{
	   g_sysSetting.IRAB.IRABVal = IROFF;
	}
	if(g_sysSetting.RadioFreq.RadioFreqVal>MHZ_891)
	{
	   g_sysSetting.RadioFreq.RadioFreqVal = RFOFF;
	}
	if(g_sysSetting.Audio.status>MUTE_ON)
	{
	   g_sysSetting.Audio.status = MUTE_OFF;	
	}
	if(g_sysSetting.Factory.volumeswitch>ON)
	{
	   	g_sysSetting.Factory.volumeswitch = ON;	
	}
	if(g_sysSetting.Factory.scalerswitch>ON)
	{
	   	g_sysSetting.Factory.scalerswitch = ON;	
	}
	if(g_sysSetting.Factory.flipswitch>ON)
	{
	   	g_sysSetting.Factory.flipswitch = ON;	
	}
    if(g_sysSetting.Factory.resetswitch>ON)
	{
	    g_sysSetting.Factory.resetswitch = ON;	
	}
	if(g_sysSetting.Factory.irabswitch>ON)
	{
	    g_sysSetting.Factory.irabswitch = ON;	
	}
	if(g_sysSetting.Power.status>POWER_ON)
	{
	   g_sysSetting.Power.status = POWER_ON;
	}
	if(g_sysSetting.Factory.powerswitch>SAVE)
	{
	   g_sysSetting.Factory.powerswitch = SAVE;
	}
	if(g_sysSetting.Factory.radiofreqswitch>ON)
	{
	   g_sysSetting.Factory.radiofreqswitch = ON;
	}
	if(g_sysSetting.Logo.logoID>LogoIDMax)
	{
	   g_sysSetting.Logo.logoID = LogoIDMax;
	}
	if(g_sysSetting.Video.ScreeSw > MAX_VDECOLOR)
	{
		g_sysSetting.Video.ScreeSw = MAX_VDECOLOR;
	}
}
/***********************************************************
*name:       VerifySetting(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           У��ϵͳ���á�
*history:
                                
************************************************************/
BOOL VerifySetting(UCHAR *pSysPara, UINT numOper, UCHAR sysCheckSum)
{
    
    UINT XDATA i;
	UCHAR XDATA tmpCheckSum = 0x00;
	BIT res = 0;
	
    printfStr("Verify Settings: ");
	 
    if((g_sysSetting.OX55 == 0x55) && (g_sysSetting.OXAA == 0xaa))
    {
		for(i = 0; i < numOper; i++)
		{
		 	tmpCheckSum ^= pSysPara[i];
		}

		if(sysCheckSum == tmpCheckSum)
		{
			res = 1;
		}		
    }	
	
	if(res){
		printfStr("  Valid");
	}else{
		printfStr("  Invalid");
	}

	return res;
}


/***********************************************************
*name:       SaveSetting(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           ����ϵͳ���ò���
*history:
                                
************************************************************/
void SaveSetting(void)
{

    printfStr("SaveSetting");
	
	/*ע�⣺ֻ����Ҫ��ϵͳ������������У��*/
	CheckSetting();

	/*���ݱ�־*/
	g_sysSetting.OX55 = 0x55;
	g_sysSetting.OXAA = 0xaa;
	g_sysSetting.xorSum = ContSysCheckSum((UCHAR *)&g_sysSetting, (sizeof(SysWorkParaType) - sizeof(UCHAR))); 

    #ifdef FlashEn
	if(ReadSaveFlagEn())
	{   
	    printfStr("Come to into Saving");
		ClrSaveFlagEn();
		WriteFlashSysPara(FLASH_DAT_ADDR, (UCHAR *)&g_sysSetting, sizeof(SysWorkParaType));
		DelayMs(100);
		WriteFlashSysPara(FLASH_COPY_ADDR,(UCHAR *)&g_sysSetting, sizeof(SysWorkParaType));   
	}
    #endif 	
}



/***********************************************************
*name:       ResetSetting(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           ����Ĭ�����ò�����
*history:
                                
************************************************************/
void ResetSetting(void)
{   
    printfStr("ResetSetting");
    g_sysSetting.Video.curSource = DefaultSource;
	g_sysSetting.Car.RemberSource = DefaultSource;
	g_sysSetting.Video.brigthness = MAX_VALUE/2;
	g_sysSetting.Video.saturation= MAX_VALUE/2;
	g_sysSetting.Video.contrast= MAX_VALUE/2;
	g_sysSetting.Video.tint= MAX_VALUE/2;
	g_sysSetting.Video.ScreeSw = VDE_CLOSE;
	g_sysSetting.Video.colorSys= PAL;
	g_sysSetting.Video.vcomDC= DEFAULT_VCOMDCVAL;
	g_sysSetting.Audio.volVal = MAX_VALUE/2;
	g_sysSetting.Audio.status = MUTE_OFF;
	g_sysSetting.Disp.zoomMode = DISP_16_9;
	g_sysSetting.Disp.flipMode =FilpLeft;
	g_sysSetting.Osd.curlanguage = DEFAULT_LANGUAGE;
	g_sysSetting.Osd.dispTime  = 0;
	g_sysSetting.Power.status = POWER_ON; 	
	g_sysSetting.Logo.logoID  = LOGO1;
	g_sysSetting.IRAB.IRABVal = IROFF;
	g_sysSetting.RadioFreq.RadioFreqVal = RFOFF;
	g_sysSetting.Factory.volumeswitch = OFF;
	g_sysSetting.Factory.scalerswitch = ON;
	g_sysSetting.Factory.flipswitch = ON;
	g_sysSetting.Factory.resetswitch = ON;
	g_sysSetting.Factory.irabswitch = OFF;
	g_sysSetting.Factory.radiofreqswitch = OFF;
	g_sysSetting.Factory.powerswitch = SAVE; 
    g_sysSetting.Video.brightnessOffset= g_sysSetting.Video.brigthness;
	g_sysSetting.Video.contrastOffset= g_sysSetting.Video.contrast;
	g_sysSetting.Video.saturationOffset= g_sysSetting.Video.saturation;
	g_sysSetting.Osd.xOffset = 0;
	g_sysSetting.Osd.yOffset =0;	
}


/***********************************************************
*name:       ReadSetting(void)
*input:      void
*output:     BOOL 
*update:     2011-11-27 
*state:      allright

*description:   
           ��ȡϵͳ���ò���
*history:
                                
************************************************************/
BOOL ReadSetting(void)
{
	
    #ifdef FlashEn
	VerifyFlashDate(FLASH_DAT_ADDR);
    #endif
	
    if(VerifySetting((UCHAR *)&g_sysSetting, (sizeof(SysWorkParaType) - sizeof(UCHAR)), g_sysSetting.xorSum)) 
    {
        CheckSetting();
		return 1;
    }
	else
	{		
		#ifdef FlashEn
		VerifyFlashDate(FLASH_COPY_ADDR);
	    #endif
		
		if(VerifySetting((UCHAR *)&g_sysSetting, (sizeof(SysWorkParaType) - sizeof(UCHAR)), g_sysSetting.xorSum)) 
		{
			CheckSetting();
			return 1;
		}
		else
		{	
		    ResetSetting();
			
			#ifdef FlashEn
			g_sysSetting.Flash.erase4kComd = Flash_comd[g_ucFlashTpye].FLASH_ERASE_4K;
            g_sysSetting.Flash.unprotectedComd = Flash_comd[g_ucFlashTpye].FLASH_UNPROTECTED_EN;
			#endif

			SetSaveFlagEn();
		    SaveSetting();

			return 0;
		}
	}
}

