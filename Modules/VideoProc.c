/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 VideoProc.c	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		   视频处理文件
  		  
*History:  Jordan.chen   2011/12/16    1.0    build  this  moudle
******************************************************************************/
#define _VIDEO_CHIP_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "configlcdpara.h"
#include "Videoproc.h"
#include "Debug.h"
#include "interrupt.h"
#include "Delay.h"
#include "MsgMap.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "AMT_Drv.h"
#include "AMT_Reg.h"
#include "AMT_MCU.h"



/****************************************************************************
*name:   ConfigVideoInputSource(InputSourceType curSource)
*input:  curSource      
*output: void

*description:
      此函数选择视频通道并配置此通道的静态参数。

*history: yshuizhou   2011/12/06    1.0    buil   this  function
*****************************************************************************/
void ConfigVideoInputSource(InputSourceType curSource)
{
     ConfigStaticPara(curSource);
}

/****************************************************************************
*name:  CheckColorSys(void)
*input:   void      
*output: void

*description:

*history: Jordan.chen   2011/12/06    1.0    buil   this  function
*****************************************************************************/
BOOL CheckColorSys(void)
{
    UCHAR XDATA i;
	
	g_ucColorSys = 0XFF;
    g_ucStableTime = 0X00;

	for(i=0;i<40;i++)
	{   
	    DelayMs(5);
		if(g_ucColorSys != 0XFF)
		{  
			return TRUE;
			break;
		}
		
	}
	return FALSE;
}


UCHAR SelNextVideoSource(UCHAR curSource)
{
    UCHAR XDATA ucSourceIndex;
	UCHAR CODE  ucSourceInputBuf[]= SourceOrderBuf;

	for(ucSourceIndex = 0; ucSourceIndex < MAX_VIDEO_CHANNEL;ucSourceIndex++)
	{
	    if(ucSourceInputBuf[ucSourceIndex] == curSource)
	    {
	        break;
	    }
	}

    return(ucSourceInputBuf[(++ucSourceIndex)%sizeof(ucSourceInputBuf)]);
}

/****************************************************************************
*name:   SelVideoInputSource(InputSourceType curSource)
*input:     
*output: void

*description:
      此函数对选择通道进行相应的视频处理和相应IO处理。

*history: Jordan.chen   2011/12/07    1.0    buil   this  function
*****************************************************************************/	
void SelVideoInputSource(InputSourceType curSource)
{ 
    TurnOnDevicePower(curSource);
	
	//ConfigVideoInputSource(curSource);

	SelVideoDevice(curSource);

	g_bVideoChSelOk = TRUE;
		
    ConfigDispZoomDynPara(g_sysSetting.Disp.zoomMode);  
	
    ConfigPannelSfrDisp();

	DelayMs(200);
	
	if(CheckColorSys())
	{   
	    g_ucPreColorSys = g_ucColorSys;
		ConfigColorSysDynPara(g_ucColorSys); 
	}
}


/****************************************************************************
*name:   InitARKChip(void)
*input:  void      
*output: void

*description:
      初始化ARK CHIP 函数。

*history: Jordan.chen   2011/12/07    1.0    buil   this  function
*****************************************************************************/	
void InitARKChip(void)
{
	printfStr("**********InitARKChip*********\n");
	
	InitGlobalPara();
	
	InitOsdBlock();
		
	InitOSD();

	#ifdef IrDetectEn
	InitRemote();
	#endif
	
	InitAdc();

	#ifdef CarBackEn
	#ifdef CarReversingSignalDetectEn 
	InitCarReversing();
	#endif
	#endif
}



