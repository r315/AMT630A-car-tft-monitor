/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 if_hardware.h
*Version:    　0.1
*Author:       cjinzong
*update:       20100128

*Description:
           这个文件是用来定义本软件可以支持的硬件资源。
*History:
************************************************************************/
#ifndef _IF_HARDWARE_H__
#define _IF_HARDWARE_H__



/*<<<<<<<<<<<<<<<<<<<<< AMT CHIP >>>>>>>>>>>>>>>>>>>>>*/
#define AMT630A                       	0



/*<<<<<<<<<<<<<<<<<<<<< video channel define >>>>>>>>>>>>>>>>>>>>>*/
#define CVBS1               			0
#define CVBS2                          	1
#define CVBS3                          	2
#define CVBS4                        	3



/*<<<<<<<<<<<<<<<<<<<<< icon size define >>>>>>>>>>>>>>>>>>>>>*/
#define SIZE_12X16             		0
#define SIZE_16X22              		1



/*<<<<<<<<<<<<<<<<<<<<<<<<<RGB data format define>>>>>>>>>>>>>>*/
#define CCIR656          				0
#define CCIR656_640RGB   				1
#define CCIR656_720RGB  				2
#define CCIR601          				3
#define _8BIT_RGB_HV   				4
#define _8BIT_RGB_DEN  				5
#define _18BIT_RGB_HV     				6
#define _18BIT_RGB_DEN    				7
#define _24BIT_RGB_HV     				8
#define _24BIT_RGB_DEN    				9



/*<<<<<<<<<<<<<<<<<<<<<<<<<Ir data format define>>>>>>>>>>>>>>*/
#define _8BIT_WITH         			0
#define _16BIT_WITH        			1
#define _24BIT_WITH        			2
#define _32BIT_WITH        			3



/*<<<<<<<<<<<<<<<<<<<<<<<<IR   define>>>>>>>>>>>>>>>>>>>>>*/
#define CR2025_6KEY              		1
#define CR2025_18KEY             		2


/*<<<<<<<<<<<<<<<<<<<<<<<<Key type define >>>>>>>>>>>>>>>>*/
#define ADC_KEY                   		0
#define IIC_KEY                   		1


/*<<<<<<<<<<<<<<<<<<<<<<<<KeyPad define>>>>>>>>>>>>>>>>>>*/
#define KP_ARK_DEBUG_V01   	   		1
#define KP_ZYD_909K_V10         		2


/*<<<<<<<<<<<<<<<<<<<<<<<<<fm chip define>>>>>>>>>>>>>>>>>>>>>*/
#define NULL_FMCHIP              		0
#define KT0803l                  		1



/*<<<<<<<<<<<<<<<<<<<<<<<<PWM  type  define>>>>>>>>>>>>>>>>>>*/
#define PWM0                       		0
#define PWM1                       		1
#define PWM2                         	2
#define PWM3                           	3
#define NULL_PWM            	        4 


/*<<<<<<<<<<<<<<<<<<<<<<<<Volume define>>>>>>>>>>>>>>>>>>>*/
#define _NULL_VOLUME_               	0
#define VOLUME_PT2259_CTRL          	1
#define VOLUME_PT2337_CTRL          	2
#define VOLUME_PWM_CTRL             	3


/*<<<<<<<<<<<<<<<<<<<<<<<<<Bt module define>>>>>>>>>>>>>>>>>>>>>*/
#define NULL_BTMODULE               0
#define BlueSoleil_i50e             1  


/*<<<<<<<<<<<<<<<<<<<<<<<<Back Light>>>>>>>>>>>>>>>>>>>>>>*/
#define _NULL_BL_                   	0
#define DC_PWM0_CTRL                 	1
#define DC_PWM1_CTRL                 	2
#define DC_PWM2_CTRL                	3
#define DC_PWM3_CTRL                	4
#define GPIO_CTRL                 		5


/*<<<<<<<<<<<<<<<<<<<<<<<<OSD style >>>>>>>>>>>>>>>>>>>>>>*/
#define OSD_STYLE_ARK               	0  //ARK OSD 风格


/*<<<<<<<<<<<<<<<<<<<<<<LOGO disp mode >>>>>>>>>>>>>>>>>>>*/
#define POWER_ON_DISP_LOGO         	0
#define NOSIGNAL_DISP_LOGO         	1

#endif

