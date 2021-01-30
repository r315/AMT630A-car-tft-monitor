/*******************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� ConfigLcdPara.c	  
*Version:      1.0
*update:       2011-11-16
*Description:
  		  �������Ρ�
  		  
*History:  yshuizhou   2011/12/06    1.0    build  this  moudle
******************************************************************************/
#define _CONFIGLCDPARA_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "ConfigLcdPara.h"
#include "delay.h"
#include "debug.h"
#include "AMT_Reg.h"
#include "LcdPannelList.c" 
#include "AMT_Drv.h"
#include "AMT_Mcu.h"




/****************************************************************************
name:   DataCurve(UCHAR minDat,UCHAR ideaDat,UCHAR maxDat,UCHAR currentDat,UCHAR len)
input:   
        ideaDat    ��׼ģʽʱд���Ĵ�����ֵ  
	    maxDat     д���Ĵ��������ֵ
        minDat     д���Ĵ�������Сֵ
	    currentDat OSD��ʾ��ֵ��Ч��Χ 0 - 100 
	    len        �ܹ����ڵ����ֵ
	    
*output: ����д���Ĵ����е�ʵ��ֵ��

*description:
      �������������������ȡ��Աȶȡ�ɫ�ȣ�����ʵ����д���Ĵ��������ֵ����׼ֵ����ǰOSD��ֵ����һ��д���Ĵ�����ֵ��

*history: yshuizhou   2011/12/06    0.1    transplant   this  function
*****************************************************************************/
UCHAR DataCurve(UCHAR minDat,UCHAR ideaDat,UCHAR maxDat,UCHAR currentDat,UCHAR len)		
{
    UCHAR XDATA regVal;
   
    if(ideaDat >= 10)
    {
          if((currentDat>=0)&&(currentDat<((len>>1)-2)))
	      {
	   	     regVal=(UINT)((ideaDat - (minDat+10))*currentDat)/((len>>1)-2) + minDat;
		     return(regVal);
	      }
		  else if((currentDat>=((len>>1)-2))&&(currentDat<=((len>>1)+2)))
		  {  
		   	  regVal= ideaDat+currentDat-(len>>1);		  
			  return(regVal);
		  }
		  else
		  {
		   	  regVal= ideaDat+10+(UINT)((maxDat-10-ideaDat)*(currentDat-((len>>1)+2)))/((len>>1)-2);
			  return(regVal);
		  }
    }
   return(ideaDat);
}



/****************************************************************************
name:   UCHAR TintCurve(UCHAR currentDat,UCHAR len)
input:  currentDat OSD��ʾ��ֵ   ��Ч��Χ 0 - 100        
*output: ����д���Ĵ����е�ʵ��ֵ��

*description:
      ����������������ɫ�������ݵ�ǰOSD��ֵ����һ��д���Ĵ�����ֵ��

*history: yshuizhou   2011/12/06    1.0    transplant   this  function
*****************************************************************************/
UCHAR TintCurve(UCHAR currentDat,UCHAR len)
{
   UCHAR XDATA regVal;
   if(currentDat == (len>>1))
   {
        regVal = 0x00;
   }
   else if((currentDat < (len>>1))&&(currentDat >= 0))
   {   
        regVal = ((UCHAR)(20 - (WORD)(20 * currentDat)/(len>>1)) | 0x80);
   }
   else if((currentDat > (len>>1))&&(currentDat <= len))
   {
        regVal = ((UCHAR)((WORD)(30 * currentDat)/(len>>1) - 30) & 0x7f);
   }
   return regVal;
}



/***********************************************************
*name:     	GetSourceID(UCHAR CurretSource)
*input:     CurretSource
*output:    non
*update:    2011-11-18
*state:     allright

*description:  
         ��������ǻ�ȡ��ǰͨ��������ID�š�      

*History:  yshuizhou   2011/12/06    1.0    build  this  function
************************************************************/
UCHAR GetSourceID(UCHAR CurretSource)
{
    UCHAR XDATA i;
	
	for(i=0;i<(sizeof(VideoChannelPara)/sizeof(VideoChannelPara[0]));i++)
	{
	      if(VideoChannelPara[i].INPUT_ID == CurretSource)
	      {
	          return i;
	      }
	 }
	 return 0;
}



/***********************************************************
*name:    ConfigStaticPara() 
*input:     CurretSource
*output:    non
*Update:    2011-11-18
*state:     allright

*description:  
         ������������ò�ͬͨ���ľ�̬������      

*History:  yshuizhou   2011/12/06    1.0    build  this  function
************************************************************/
void ConfigStaticPara(UCHAR CurretSource)
{     
     UINT  XDATA i;
	 UCHAR XDATA ucSourceIndex;
		
	 ucSourceIndex = GetSourceID(CurretSource);
	 
     for(i=0; i<STATIC_NUM;i++)
	 {     
		 XBYTE[VideoChannelPara[ucSourceIndex].VideoPara.pVideoStaicPara[i].addr] = VideoChannelPara[ucSourceIndex].VideoPara.pVideoStaicPara[i].dat;
	 }

	 #ifdef NoSignalBLOffEn
	 XBYTE[0XFFB0] = 0X07;
	 #endif

	 #ifdef DithingEn
	 XBYTE[0XFFCB] = 0X00;
	 XBYTE[0XFFCC] = 0X2A;
	 XBYTE[0XFFCD] = 0X00;
	 #endif
}



/***********************************************************
*name:    ConfigPadMuxPara() 
*input:   non
*output:  non
*Update:  2011-11-18
*state:   allright

*description:  
         ������������ò�ͬͨ���ľ�̬������      

*History:  yshuizhou   2011/12/06    1.0    build  this  function
************************************************************/
void ConfigPadMuxPara(void)
{    
     UINT  XDATA i;
     for(i=0; i<PAD_MUX_NUM;i++)
	 {     
         XBYTE[AMT_PadMuxStaticPara[i].addr] = AMT_PadMuxStaticPara[i].dat;
	 }
}


/***********************************************************
*name:     	ConfigUserParaSetting(void) 
*input:     void
*output:    void
*update:    2013-03-28
*state:     allright

*description:  
         ������������������ͬ�ͻ���һЩ�������ò�����

*History:  Jordan��chen   2013/03/28    0.1    build  this  function
************************************************************/
void ConfigUserParaSetting(void)
{
    ConfigUserPara();
}


/***********************************************************
*name:     	ConfigColorSysDynPara(UCHAR currentSys) 
*input:     currentSys
*output:    non
*update:    2011-11-18
*state:     allright

*description:  
         ���������ʵʱ���ò�ͬͼ����ʽ������      

*History:  yshuizhou   2011/12/06    1.0    build  this  function
************************************************************/
void ConfigColorSysDynPara(UCHAR currentSys) 
{    
	 UCHAR XDATA i;
	 UCHAR XDATA ucSourceIndex;

	 ucSourceIndex = GetSourceID(g_sysSetting.Video.curSource);
	 
	 for(i=0; i<SYS_DYN_NUM;i++)    
	 {		 
         XBYTE[VideoChannelPara[ucSourceIndex].VideoPara.pVideoSysDynPara[i].addr] = VideoChannelPara[ucSourceIndex].VideoPara.pVideoSysDynPara[i].dat_sysDyn[currentSys];
	 }	
	 
	 g_ucbrightness = BRIGHT_REG;
	 g_ucContrast = CONTRAST_REG;
	 g_ucSaturation = SATURATION_REG;
	 g_ucTint = TINT_REG;
	
     g_ucbrightness =  DataCurve(BRIGHT_MIN,g_ucbrightness,BRIGHT_MAX, g_sysSetting.Video.brightnessOffset,MAX_VALUE);
	 g_ucContrast = DataCurve(CONTRAST_MIN,g_ucContrast,CONTRAST_MAX, g_sysSetting.Video.contrastOffset,MAX_VALUE);
	 g_ucSaturation=  DataCurve(SATURATION_MIN,g_ucSaturation,SATURATION_MAX, g_sysSetting.Video.saturationOffset,MAX_VALUE);
	 UpdataPicPara();
}




/***********************************************************
*name:     	ConfigDispZoomDynPara(UCHAR currentmode) 
*input:     currentmode
*output:    non
*update:    2011-11-18
*state:     allright

*description:  
         ������������ò�ͬͨ��16:9/4:3��ʾ�Ĳ�����      

*History:  yshuizhou   2011/12/06    1.0    build  this  function
************************************************************/
void ConfigDispZoomDynPara(UCHAR currentmode) 
{    
	  UCHAR XDATA i;

	  EA = OFF;
	  SCALER_HSYNC_UPDATE |= _BIT6;
	  for(i=0; i<POS_DYN_NUM;i++)
	  {
			XBYTE[VideoChannelPara[GetSourceID(g_sysSetting.Video.curSource)].VideoPara.pVideoPosDynPara[i].addr] = VideoChannelPara[GetSourceID(g_sysSetting.Video.curSource)].VideoPara.pVideoPosDynPara[i].dat_posDyn[currentmode];
	  }	 
	  HFZ_LR_BLANK_WR = 0X00;
	  EA = ON;
}



/***********************************************************
*name:     	ConfigPannelSfrDisp(void) 
*input:     void
*output:    non
*update:    2012-05-22
*state:     allright

*description:  
         ����������������ķ�ת��    

*History:  yshuizhou   2012/05/22    1.0    build  this  function
************************************************************/
void ConfigPannelSfrDisp(void) 
{  
    #ifdef PannelSfrDispEn
    switch(g_sysSetting.Disp.flipMode)
    {
     case FilpLeft:
	 	  printfStr("FilpLeft");
	 	  hw_turnToLeft();
	 	  break;
		  
	 case FilpRight:
	 	  printfStr("FilpRight");
	 	  hw_turnToRight();
	 	  break;
		  
	 case FilpUp:
	 	  printfStr("FilpUp");
	 	  hw_turnToUp();
	 	  break;
		  
	 case FilpDown:
	 	  printfStr("FilpDown");
	 	  hw_turnToDown();
	 	  break;
		  
	default:
		  printfStr("Default FilpLeft");
		  hw_turnToLeft();
		  break;
   }
   #endif
}





/*************************************************************************
*name:  UpdataPicPara(void) 
*input: currentSys
*update:  2011-11-16
state:   allright
*description: 
                 ���²�ͬͨ�����ȡ��Աȶȡ�ɫ�ȡ�ɫ������  
                 
*History:  yshuizhou   2011/12/06    1.0    build  this  function
**************************************************************************/
void UpdataPicPara(void) 
{   
	BRIGHT_REG    =  DataCurve(BRIGHT_MIN,g_ucbrightness,BRIGHT_MAX,  g_sysSetting.Video.brigthness,MAX_VALUE);
	CONTRAST_REG  =  DataCurve(CONTRAST_MIN,g_ucContrast,CONTRAST_MAX,  g_sysSetting.Video.contrast,MAX_VALUE);
	SATURATION_REG=  DataCurve(SATURATION_MIN,g_ucSaturation,SATURATION_MAX,  g_sysSetting.Video.saturation,MAX_VALUE);
	TINT_REG      =  TintCurve(g_sysSetting.Video.tint,MAX_VALUE);

	switch(VCOMDC_TYPE)
	{
	   case PWM0:
	   	    SetPWM0(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;
			
	   case PWM1:
            SetPWM1(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;

	   case PWM2:
            SetPWM2(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;

	   case PWM3:
            SetPWM3(DEFAULT_VCOMDCFREQ,g_sysSetting.Video.vcomDC);
			break;
			
	  default:
			break;
	}
}


