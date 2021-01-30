/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 AMT_Drv.h	  
*Version:      1.0
*update:       2011-12-06
*Description:
  		   这个文件是对AMT应用驱动提供接口:

  		   
*History:  yshuizhou   2011/12/06    1.0    build  this  moudle
******************************************************************************/
#ifndef _AMT_DRV_H__
#define _AMT_DRV_H__



#ifdef _AMT_DRV_C_
#define AMTDRV_EXTERN_   
#else
#define AMTDRV_EXTERN_ extern
#endif

#include "SystemConfig.h"
#include "AMT630A_Video_Lib_Interface.h"
#include "AMTIO_Lib_Interface.h"
#include "AMT6XX_SPI_Lib_Interface.h"

#define OsdIndexRamSize   512
#define COLOR(foreColor,backColor) ((backColor<<4)|foreColor)

#define OSD_MODE            	0
#define OSD_BITMAP_MODE     	1

#define OSD_BLENDING        	0
#define OSD_BACK_BLENDING   	1

#define OSD_DISP_NORMAL     	0
#define OSD_DISP_H_MIRROR     1
#define OSD_DISP_V_MIRROR     2
#define OSD_DISP_HV_MIRROR    3

#define IsPal()                (XBYTE[0XFE28] & 0X04)
#define SetAUX0ENA()       	{ADC_CTRL_L = (ADC_CTRL_L & 0X87)|0X08;}
#define SetAUX0CMD()        	{ADC_CTRL_M = (ADC_CTRL_M & 0X0F) |0X20;}
#define CheckAUX0ValInt()    	{while((ADC_INT_STATUS_L & _BIT2) != _BIT2);}


#define SetAUX1ENA()        	{ADC_CTRL_L = (ADC_CTRL_L & 0X87)|0X10;}
#define SetAUX1CMD()        	{ADC_CTRL_M = (ADC_CTRL_M & 0X0F)|0X40;}
#define CheckAUX1ValInt()    	{while((ADC_INT_STATUS_L & _BIT5) != _BIT5);}


#define SetAUX2ENA()       	{ADC_CTRL_L = (ADC_CTRL_L & 0X87)|0X20;}
#define SetAUX2CMD()      		{ADC_CTRL_M = (ADC_CTRL_M & 0X0F)|0X80;}
#define CheckAUX2ValInt()  	{while((ADC_INT_STATUS_H & _BIT0) != _BIT0);}


#define SetAUX3ENA()       	{ADC_CTRL_L = (ADC_CTRL_L & 0X87)|0X40;}
#define SetAUX3CMD()      		{ADC_CTRL_H = (ADC_CTRL_H & 0XFE)|0X01;}
#define CheckAUX3ValInt()  	{while((ADC_INT_STATUS_H & _BIT3) != _BIT3);}


#define ClearAUXValInt()   	{ADC_INT_STATUS_L = 0X00;ADC_INT_STATUS_H = 0X00;}


typedef struct
{
     UINT block0Size;
	 UINT block1Size;
	 UINT block2Size;
	 UINT block3Size;
	 UINT block4Size;
}OsdCtrlerType;

AMTDRV_EXTERN_ OsdCtrlerType  XDATA g_OsdContrller;

AMTDRV_EXTERN_ void InitGlobalPara();
AMTDRV_EXTERN_ void InitRemote(void);
AMTDRV_EXTERN_ UINT  Abs(UINT tmpVal1,UINT tmpVal2);
AMTDRV_EXTERN_ UCHAR DataCurve(UCHAR minDat,UCHAR ideaDat,UCHAR maxDat,UCHAR currentDat,UCHAR len);
AMTDRV_EXTERN_ UCHAR TintCurve(UCHAR currentDat,UCHAR len);
AMTDRV_EXTERN_ void TurnOnBackLight(void);
AMTDRV_EXTERN_ void TurnOffBackLight(void);
AMTDRV_EXTERN_ void EnterLowPowerMode(void);
AMTDRV_EXTERN_ void ExitLowPowerMode(void);
AMTDRV_EXTERN_ void SetAudioMute(void);
AMTDRV_EXTERN_ void SelAudioInputSource(InputSourceType curSource);
AMTDRV_EXTERN_ void SelVideoDevice(InputSourceType curSource);
AMTDRV_EXTERN_ void SetVDETestSwitch(UCHAR ScreeSw);
AMTDRV_EXTERN_ void SetNoSignalSnow(void);
AMTDRV_EXTERN_ void OpenAudio(void);
AMTDRV_EXTERN_ void TurnOnDevicePower(InputSourceType curSource);
AMTDRV_EXTERN_ void TurnOffDevicePower(InputSourceType curSource);
AMTDRV_EXTERN_ void ConfigCrtlMode(UCHAR CtrlMode);
AMTDRV_EXTERN_ UINT POS_GetIrKeyVal(void);
AMTDRV_EXTERN_ void InitAdc(void);
AMTDRV_EXTERN_ void InitCarReversing(void);
AMTDRV_EXTERN_ void SetPWM0(ULONG Freq,UCHAR Duty);
AMTDRV_EXTERN_ void SetPWM1(ULONG Freq,UCHAR Duty);
AMTDRV_EXTERN_ void SetPWM2(ULONG Freq,UCHAR Duty);
AMTDRV_EXTERN_ void SetPWM3(ULONG Freq,UCHAR Duty);
AMTDRV_EXTERN_ void SetSpDat(UCHAR Data);
AMTDRV_EXTERN_ void SetSpClk(UCHAR Data);
AMTDRV_EXTERN_ void SetSpEna(UCHAR Data);
AMTDRV_EXTERN_ void SetReset(UCHAR Data);
AMTDRV_EXTERN_ void SetBuzzerOn(void);
AMTDRV_EXTERN_ void POS_AdjustSpiReg(void);
AMTDRV_EXTERN_ void POS_RecUartSpiInfor(void); 
AMTDRV_EXTERN_ void SetI2CDebug(void);
AMTDRV_EXTERN_ void SetUartPrint(void);
AMTDRV_EXTERN_ void  GetProCompielTime(void);
AMTDRV_EXTERN_ BOOL POS_SysTimeDriver(void);
AMTDRV_EXTERN_ void POS_SendNecIrData(UCHAR DataWith,ULONG SendData);
AMTDRV_EXTERN_ void POS_SelectKeyDevice(void);
AMTDRV_EXTERN_ void SetIRABSwitch(UCHAR Val);
AMTDRV_EXTERN_ void CtrlVolumeByPWM(UCHAR tmpVolume);
AMTDRV_EXTERN_ UINT POS_EnableChipAdc(AdcChannelType Channel);  


//====================================================================================
//                           OSD boot driver
//====================================================================================
AMTDRV_EXTERN_ void InitOsdBlock(void);
AMTDRV_EXTERN_ void InitOSD(void);
AMTDRV_EXTERN_ void OsdBlockHide(UCHAR ucOsdBlockId);
AMTDRV_EXTERN_ void OsdClear(void);
AMTDRV_EXTERN_ void OsdBlockClear(UCHAR ucOsdBlockId);
AMTDRV_EXTERN_ void OsdConfigBlockColor(UCHAR fbColor);
AMTDRV_EXTERN_ void OsdConfigWndPosition(UINT xPos, UINT yPos);
AMTDRV_EXTERN_ void OsdDrawStr(UCHAR starRow,UCHAR starLine,UCHAR fbColor, UCHAR *str);
AMTDRV_EXTERN_ void OsdDrawIcon(UCHAR starRow,UCHAR starLine,UCHAR xSize,UCHAR ySize,UCHAR BackColor,UINT *pIconStr);
AMTDRV_EXTERN_ void OsdWriteCharToFontram(BYTE indexAddr, UCHAR *pCharData);
AMTDRV_EXTERN_ void LoadMulCharToFontram(BYTE indexAddr, UCHAR Size,UCHAR *pCharData);
AMTDRV_EXTERN_ void OsdDrawNum(UCHAR starRow,UCHAR starLine,UCHAR fbColor,SWORD value);
AMTDRV_EXTERN_ void OsdDrawGuage(UCHAR starRow, UCHAR starLine, UCHAR length,UCHAR fbColor, UCHAR value);
AMTDRV_EXTERN_ void OsdDrawHex(UCHAR starRow,UCHAR starLine,UCHAR fbColor,SWORD value);
AMTDRV_EXTERN_ void OsdConfigScaler(UCHAR zoom);
AMTDRV_EXTERN_ void OsdConfigWndSize(BYTE width, BYTE height);
AMTDRV_EXTERN_ void OsdBlockShow(UCHAR ucOsdBlockId);
AMTDRV_EXTERN_ void OsdHide(void);
AMTDRV_EXTERN_ void OsdConfigColorChangWndSize(UINT Length,UINT Width);
AMTDRV_EXTERN_ void OsdConfigColorChangWndPosition(UINT XPos, UINT YPos);
AMTDRV_EXTERN_ void OsdColorChangeSwitch(UCHAR operatDat);
AMTDRV_EXTERN_ void OsdConfigColorChangeRGB(UCHAR R,UCHAR G,UCHAR B);
AMTDRV_EXTERN_ void OsdCofigPalette(void);
AMTDRV_EXTERN_ void OsdConfigAlpha(UCHAR enFlg,UCHAR mode,UCHAR alphaLev);
AMTDRV_EXTERN_ void OsdConfigBright(UCHAR brightLev);
AMTDRV_EXTERN_ void OsdConfigDispMode(UCHAR dispMode,UCHAR  mirrorMode);
AMTDRV_EXTERN_ void OsdConfigBitmapStarIndex(UCHAR starIndexAddr);
AMTDRV_EXTERN_ void OsdConfigBitmapPalette(UCHAR *paletColor);
AMTDRV_EXTERN_ UINT OsdConfigBlockIndexStarAddr(UCHAR blockId,UINT starAddr);
AMTDRV_EXTERN_ void OsdWndClear(UCHAR starRow,UCHAR starLine,UCHAR endRow,UCHAR endLine);
AMTDRV_EXTERN_ void DMALoadFontRam(ULONG SrcAddr,UINT DstAddr,UINT numOper);
AMTDRV_EXTERN_ void LoadBitMapToFontRam(UCHAR indexAddr,UCHAR BitMapSize,UCHAR *pBitMapData);
AMTDRV_EXTERN_ void OsdBlockEnable(UCHAR ucOsdBlockId);
AMTDRV_EXTERN_ void OsdIconSize(UCHAR Size_X,UCHAR Size_Y);

#endif   
