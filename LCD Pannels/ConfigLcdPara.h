/***********************************************************************
*Copyright (C) 2011 深圳艾科创新有限公司产品应用四部
* All rights reserved.

*File name: 　 ConfigLcdPara.h
*Version:    　0.1
*update:       2011-11-28

*Description:
             这个文件是提供对屏参操作的接口。
             
*History:  yshuizhou   2011/12/06    1.0    build  this  moudle
************************************************************************/
#ifndef _CONFIGLCDPARA_H_
#define _CONFIGLCDPARA_H_


#ifdef _CONFIGLCDPARA_C_
#define CONFIGLCDPARA_EXTERN_   
#else
#define CONFIGLCDPARA_EXTERN_ extern
#endif


CONFIGLCDPARA_EXTERN_ UCHAR XDATA g_ucbrightness;
CONFIGLCDPARA_EXTERN_ UCHAR XDATA g_ucContrast;
CONFIGLCDPARA_EXTERN_ UCHAR XDATA g_ucSaturation;
CONFIGLCDPARA_EXTERN_ UCHAR XDATA g_ucTint;

CONFIGLCDPARA_EXTERN_ void UpdataPicPara();
CONFIGLCDPARA_EXTERN_ void ConfigDispZoomDynPara(UCHAR currentmode);
CONFIGLCDPARA_EXTERN_ void ConfigColorSysDynPara(UCHAR currentSys);
CONFIGLCDPARA_EXTERN_ void ConfigStaticPara(UCHAR CurretSource);
CONFIGLCDPARA_EXTERN_ UCHAR GetSourceID(UCHAR CurretSource);
CONFIGLCDPARA_EXTERN_ void ConfigPadMuxPara(void);
CONFIGLCDPARA_EXTERN_ void ConfigPannelSfrDisp(void); 
CONFIGLCDPARA_EXTERN_ void ConfigUserParaSetting(void);

#endif

