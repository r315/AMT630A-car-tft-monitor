/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� SysConfigure.h
*Version:    ��0.1
*Author:       cjinzong
*update:       2009-06-11

*Description:
             ����ļ���ϵͳ�����ļ�����Ҫ������һЩƽʱ�仯���Ĳ����� 
     ���磺  OSDλ��
             ϵͳ��ģ������
             �ȵȡ�����
*History:
************************************************************************/
#ifndef SYSCONFIGURE_H__
#define SYSCONFIGURE_H__ 

/* ===========================================================
ϵͳ�����汾���ã�
����˵��:
Release_Ver:��ʾ���������汾����Ҫʹ���ڿͻ�����ʱӦ�á�
==============================================================*/
//#define Release_Ver  



/*=============================================================
ARK-DEBUG ����ʹ�ܿ��أ�����˿���ʹ�ܣ���ô����ͨ����λ������
����ֱ���ù��߽��к�����ͨѶ��������ԡ�
===============================================================*/
#ifndef Release_Ver
//#define UartPrintfEn
#endif




/*=============================================================
Ӳ��ϵͳ��Ϣ����ʾ������ϵͳ��֧�ֵ�Ӳ���豸ID��
==============================================================*/
#include "hardware.h"


/*=============================================================
�趨��ǰ��Ч����
˵��: ����Ӧ��ÿ���ͻ���ÿ�����Ӷ�Ӧ�ý���������Ӧ�������ļ���
      �����������Ƕ���Ŀ�Ĺ�������ά����
===============================================================*/
//#define PRJ_AMT_43D_SDK_DEMO   
//#define PRJ_AMT_7D_SDK_DEMO
#define PRJ_AMT_5D_SDK_DEMO
	 
#ifdef PRJ_AMT_43D_SDK_DEMO 
#include "Prj_AMT_43D_SDK_DEMO.h"
#endif

#ifdef PRJ_AMT_5D_SDK_DEMO 
#include "Prj_AMT_5D_SDK_DEMO.h"
#endif

#ifdef PRJ_AMT_7D_SDK_DEMO 
#include "Prj_AMT_7D_SDK_DEMO.h"
#endif


#endif


