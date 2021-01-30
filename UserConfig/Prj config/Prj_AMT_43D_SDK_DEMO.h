/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Prj_AMT_43D_SDK_DEMO.h
*Version:    　0.1
*Author:       cjinzong
*update:       20111208

*Description:
            
*History:
************************************************************************/
#ifndef AMT_PRJ_CONFIG_H__
#define AMT_PRJ_CONFIG_H__


/*=======================================================
<<<<<<<<<<<<<<<<<<<    项目信息概述>>><<>>>>>>>>>>>>>>>>
========================================================*/
/*
>>客户名称: ARK

>>屏型号:SAT043CM40DMY0

>>效果要求:ARK通用图像效果。

>>OSD风格:ARK通用OSD风格。

>>软件功能要求: 
   

>>硬件功能要求:
    1.传统车载常规功能硬件需求。

>>特殊功能要求:无。

>>备注:

*/



/*========================================================
<<<<<<<<<<<<<<<<<<<<<   芯片型号配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/
//[AMT chip type]
#define AMT_TYPE       AMT630A
#define WebSite        "www.arkmicro.com"



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<   屏显示配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/   
//[LCD pannel parameter list]  
#define P_SAT043CM40DMY0_AMT630A_STD_20141202_EN   	ENABLE

//[VcomDC type]
#define VCOMDC_TYPE    									NULL_PWM  
#define DEFAULT_VCOMDCFREQ	                            0
#define DEFAULT_VCOMDCVAL                                 0

/*========================================================
<<<<<<<<<<<<<<<<<< 软件库配置>>>>>>>>>>>>>>>>>
=========================================================*/
#define VD_EN           _BIT0  //数字AGC使能开关 DAGC_0XFE90 
#define PDF_EN          _BIT1 //锁相环使能开关  PDFC3_0XFE35、PDFC2_0XFE34 
#define VL_EN           _BIT3 //行锁使能开关   0XFEA7、0XFE2E 

#define VdLibCmd        VD_EN|PDF_EN|VL_EN
#define ConfigUserPara() {}



/*========================================================
<<<<<<<<<<<<<<<<<<<<   图像显示配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Video Channel]
//[Video Channel]
#define AV1                    CVBS1   //av
#define AV2                    CVBS3  //car detect
#define AV3                    CVBS4  //reserve

#if(AV1 == CVBS1)
#define SelAv1Channel()    	hw_SelChannelToCVBS1()
#define SelAvSOGIn()       	hw_SelSOG1In()   
#elif(AV1 == CVBS2)
#define SelAv1Channel()    	hw_SelChannelToCVBS2()
#define SelAvSOGIn()       	hw_SelSOG2In()   
#elif(AV1 == CVBS3)
#define SelAv1Channel()    	hw_SelChannelToCVBS3()
#define SelAvSOGIn()       	hw_SelSOG3In()  
#endif

#if(AV2 == CVBS1)
#define SelCarChannel()    	hw_SelChannelToCVBS1()
#define SelCarSOGIn()       	hw_SelSOG1In()  
#elif(AV2 == CVBS2)
#define SelCarChannel()    	hw_SelChannelToCVBS2()
#define SelCarSOGIn()       	hw_SelSOG2In()    
#elif(AV2 == CVBS3)
#define SelCarChannel()    	hw_SelChannelToCVBS3()
#define SelCarSOGIn()       	hw_SelSOG3In() 
#endif

#define SelAv2Channel()    	hw_SelChannelToNULL() 
#define SelNullChannel()      	hw_SelChannelToNULL() 
#define SelSOGNULLIn()   		hw_SelSOGNULLIn()

//[Video Channel List]
#define SourceOrderBuf      	{INPUT_AV1,INPUT_CAMERA_Car} 
#define DefaultSource          INPUT_AV1


//[PIC display value]
#define BRIGHT_MIN           	0X49   //亮度调节最小值
#define	BRIGHT_MAX          	0XA9   //亮度调节最大值                                     
#define	CONTRAST_MIN        	0X00   //对比度调节最小值           
#define	CONTRAST_MAX        	0XB0   //对比度调节最大值                                                   
#define	SATURATION_MIN      	0X00  //色度调节最小值
#define	SATURATION_MAX     	0X44  //色度调节最大值



/*========================================================
<<<<<<<<<<<<<<<<<<<<   背光控制配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Backlight ctrl]
#define BacklightEn          		//背光控制使能开关

#ifdef BacklightEn
#define BACKLIGHT_CTRL_MODE     DC_PWM0_CTRL // DC_PWM0_CTRL、DC_PWM1_CTRL、DC_PWM2_CTRL、DC_PWM3_CTRL、GPIO_CTRL 

#if BACKLIGHT_CTRL_MODE == GPIO_CTRL  
#define hw_setBacklight()    	SetP3_5(1)
#define hw_clrBacklight()    	SetP3_5(0)
#define hw_setBIASEn()    		SetP3_6(1)
#define hw_clrBIASEn()        	SetP3_6(0)      
#endif

#if BACKLIGHT_CTRL_MODE == DC_PWM0_CTRL
#define hw_setBacklight() 		(PWM_CTRL |= _BIT0)
#define hw_clrBacklight() 		(PWM_CTRL &= ~_BIT0)
#define hw_setBIASEn()    	
#define hw_clrBIASEn()  
#endif

#if BACKLIGHT_CTRL_MODE == DC_PWM1_CTRL
#define hw_setBacklight() 		(PWM_CTRL |= _BIT1)
#define hw_clrBacklight() 		(PWM_CTRL &= ~_BIT1)
#define hw_setBIASEn()    	
#define hw_clrBIASEn()  
#endif

#if BACKLIGHT_CTRL_MODE == DC_PWM2_CTRL
#define hw_setBacklight() 		(PWM_CTRL |= _BIT2)
#define hw_clrBacklight() 		(PWM_CTRL &= ~_BIT2)
#define hw_setBIASEn()    	
#define hw_clrBIASEn()  
#endif

#if BACKLIGHT_CTRL_MODE == DC_PWM3_CTRL
#define hw_setBacklight() 		(PWM_CTRL |= _BIT3)
#define hw_clrBacklight() 		(PWM_CTRL &= ~_BIT3)
#define hw_setBIASEn()    	
#define hw_clrBIASEn()  
#endif

#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   按键功能配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Key detect Ctrl]
//#define KeyDetectEn            //按键检测使能开关

#ifdef KeyDetectEn 
#define hw_upResistance      			12000     //上拉电阻值  12k
#define hw_downResistance    			0        // 0:表示无下拉电阻
#define hw_keyVoltage        			3.3  
#define ADC_CH_LIST         			{CH2} //{CH0,CH1,CH2} //通道列表   
#define hw_Key_getSDA_input()     	GetP1_0()      //SDA
#define hw_Key_setSDA_output(x)   	SetP1_0(x)    //SDA
#define hw_Key_setSCL_output(x)   	SetP1_1(x)  //SCL

#define ADCKEY_PAD_ID        			KP_ARK_DEBUG_V01  //按键板
#define I2CKEY_PAD_ID        			KP_ZYD_909K_V10  //I2C 按键板

#define KEY_OFFSET           			0X0A         //按键的偏移量
#define RepeatTime           			0X15        //连续按键响应时间
#define SpRepeatTime         			0X50        //特殊长按转义命令
#endif//#ifdef KeyDetectEn 



/*========================================================
<<<<<<<<<<<<<<<<<<<<   IR功能配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[IR detect Ctrl]
//#define IrDetectEn           		//遥控检测使能开关

#ifdef IrDetectEn
#define IR_TYPE          		NEC  
#define IR_DECODE_MODE       	IR_HARDWARE
#define IR_ID                 	CR2025_6KEY
#define IR_Delta_DATA        	0X05
#define IR_Delta_96ms        	0X0F	
#endif  //#ifdef IrDetectEn



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  OSD 功能配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[OSD Icon Size And ScalerRatio]
#define ICON_SIZE							SIZE_12X16   //SIZE_16X22

#if(ICON_SIZE == SIZE_12X16)
#define ICON_SIZE_X                       	12     //ICON 水平像素点数
#define ICON_SIZE_Y                       	16    //ICON 垂直行数
#define OsdScalerRatio						2 
#define NoSignalScalerRatio              	4
#elif(ICON_SIZE == SIZE_16X22)
#define ICON_SIZE_X                    	16    //ICON 水平像素点数
#define ICON_SIZE_Y                       	22    //ICON 垂直行数
#define OsdScalerRatio						1 
#define NoSignalScalerRatio              	2
#endif

//[OSD style]
#define OSD_STYLE_TYPE         			OSD_STYLE_ARK

//[Osd bar lenght]
#define MAX_VALUE               			100    //最大值

//[OSD menu X Y position]
#define MAINMENU_START_X_POS   			0X0080     //MAIN MENU 菜单的X起始位置
#define MAINMENU_START_Y_POS   			0X00ED    //MAIN MENU 菜单的Y起始位置

#define SOURCEMENU_START_X_POS 			0X01D6   //SOURCE MENU 菜单的X起始位置
#define SOURCEMENU_START_Y_POS 			0X0002   //SOURCE MENU 菜单的Y起始位置

#define SOURCE_43_START_X_SHIFT          0X3F      //SOURCE MENU 菜单4:3模式 与16:9模式的X差值

#define NOSIGNALMENU_START_X_POS 		0x007E   //NOSIGNAL MENU 菜单的X起始位置
#define NOSIGNALMENU_START_Y_POS 		0x007D   //NOSIGNAL MENU 菜单的Y起始位置

#define BTMENU_START_X_POS 				0x0000   //BT MENU 菜单的X起始位置
#define BTMENU_START_Y_POS    			0x000A   //BT MENU 菜单的Y起始位置

#define BTCALLERMENU_START_X_POS 		0x0055   //BTCALLER MENU 菜单的X起始位置
#define BTCALLERMENU_START_Y_POS 		0x0090   //BTCALLER MENU 菜单的Y起始位置

#define BATTERYADCMENU_START_X_POS 		0x0015   //BATTERYADC MENU 菜单的X起始位置
#define BATTERYADCMENU_START_Y_POS 		0x0000   //BATTERYADC MENU 菜单的Y起始位置

#define MUTEMENU_START_X_POS   			0X0018   //MUTE MENU 菜单的X起始位置
#define MUTEMENU_START_Y_POS   			0X0020   //MUTE MENU 菜单的Y起始位置
		
#define FACTORYMENU_START_X_POS  			0X00AC   //FACTORY MENU 菜单的X起始位置
#define FACTORYMENU_START_Y_POS  			0X008A   //FACTORY MENU 菜单的Y起始位置

//[OSD default language]
#define DEFAULT_LANGUAGE        			ENGLISH  //OSD 默认语言

//[OSD display timeout]
#define OSD_DISP_TIME           			200     //OSD 显示时间
#define OSD_STORAGE_TIME           		100     //OSD 记忆显示时间

//[OSD Position Offset]
#define MAX_OFFSETVALUE         			50    //最大值



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  LOGO 功能配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Logo enable]
//#define LogoEn                    					//Logo模块开关

//[Logo display mode]
#define LOGO_DISP_MODE          			POWER_ON_DISP_LOGO


//[Logo display backcolor]
#define LOGO_DISP_BACKCOLOR               WHITE     //LOGO显示背景颜色


//[Logo menu X Y position]
#define LOGO1MENU_START_X_POS 		    0X0070   //LOGO1 MENU 菜单的X起始位置
#define LOGO1MENU_START_Y_POS 		    0X0055   //LOGO1 MENU 菜单的Y起始位置

#define LOGO2MENU_START_X_POS 		    0X0070   //LOGO2 MENU 菜单的X起始位置
#define LOGO2MENU_START_Y_POS 		    0X0055   //LOGO2 MENU 菜单的Y起始位置

#define LOGO3MENU_START_X_POS 		    0X0070   //LOGO3 MENU 菜单的X起始位置
#define LOGO3MENU_START_Y_POS 		    0X0055   //LOGO3 MENU 菜单的Y起始位置

#define LOGO4MENU_START_X_POS 		    0X0070   //LOGO4 MENU 菜单的X起始位置
#define LOGO4MENU_START_Y_POS 		    0X0055   //LOGO4 MENU 菜单的Y起始位置

#define LOGO5MENU_START_X_POS 		    0X0070   //LOGO5 MENU 菜单的X起始位置
#define LOGO5MENU_START_Y_POS 		    0X0055   //LOGO5 MENU 菜单的Y起始位置



/*========================================================
<<<<<<<<<<<<<<<<<<<<  倒车检测配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#define CarBackEn            		//倒车使能开关

#ifdef CarBackEn

//#define CarReversingIODetectEn    	   //IO 检测倒车使能
#define CarReversingSignalDetectEn     //信号检测倒车使能

#ifdef CarReversingIODetectEn
#define hw_setCarBackAheadStatus  	1     		//正常状态倒车脚状态
#define hw_getCarBackPinStatus()   	GetP1_5()   //倒车脚位
#endif

#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   屏特殊显示配置>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define PannelSfrDispEn      		//屏特殊显示使能开关 (翻转)

#ifdef PannelSfrDispEn
#define hw_SfrDisp_PinRL(x)	SetP0_5(x) 
#define hw_SfrDisp_PinUD(x)	SetP0_4(x) 

#define hw_turnToLeft()     	{hw_SfrDisp_PinRL(1); hw_SfrDisp_PinUD(0);}
#define hw_turnToRight() 	 	{hw_SfrDisp_PinRL(0); hw_SfrDisp_PinUD(0);}
#define hw_turnToUp()	     	{hw_SfrDisp_PinRL(0); hw_SfrDisp_PinUD(1);}
#define hw_turnToDown()	 	{hw_SfrDisp_PinRL(1); hw_SfrDisp_PinUD(1);}
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   屏SPI初始化配置>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[SPI Inital Pannel Ctrl]
//#define SpiInitPannelEn       //SPI 屏初始化使能开关

#ifdef SpiInitPannelEn

//#define SpiAdjRegEn  //串口调试屏SPI寄存器使能开关

#define hw_setCs(x)    SetP1_7(x)
#define hw_setClk(x)   SetP0_6(x) 
#define hw_setDout(x)  SetP1_6(x)
#define hw_setReset(x) SetGPIO12(x)

#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   CPU 屏初始化配置>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define CpuInitPannelEn          //Cpu 屏初始化使能开关



/*========================================================
<<<<<<<<<<<<<<<<<<<<   Audio 功能配置>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Audio Ctrl]
//#define AudioCtrlEn          		//音量控制使能开关

#ifdef AudioCtrlEn
#define AUDIO_CTRL               	VOLUME_PWM_CTRL

#define hw_setAudioMute()      	//SetP2_6(1)
#define hw_clrAudioMute()      	//SetP2_6(0)

#define hw_AudioSel_PinA(x)		//SetGPIO4(x) 
#define hw_AudioSel_PinB(x)		//SetGPIO5(x)   

#define hw_SetAudioSelToAv1() 	{hw_AudioSel_PinA(1); hw_AudioSel_PinB(1);}
#define hw_SetAudioSelToAv2() 	{hw_AudioSel_PinA(1); hw_AudioSel_PinB(0);}
#define hw_SetAudioSelToBt()	    {hw_AudioSel_PinA(0); hw_AudioSel_PinB(0);}



#if AUDIO_CTRL == VOLUME_PWM_CTRL  
#define    VOL_PWM_CTRL    PWM1_CTRL 
#define    VOL_PWM_RATE    PWM1_RATE 
#define    VOL_PWM_TYPE    PWM1
#endif

#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   FM 发射配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define FmSendEn            //Fm发射使能开关

#ifdef FmSendEn
#define FM_CHIP                        KT0803l

#define hw_FmSend_getSDA_input()     GetSdaIn()      
#define hw_FmSend_setSDA_output(x)   SetSdaOut(x)    
#define hw_FmSend_setSCL_output(x)   SetSclOut(x) 
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   BT配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define BTEn                //蓝牙使能开关

#ifdef BTEn
#define BT_Module           BlueSoleil_i50e
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   程序存储配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#define FlashEn 



/*========================================================
<<<<<<<<<<<<<<<<<<   电源LED 指示配置>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Power LED]
//#define PowerLedEn             //电源指示灯使能开关 

#ifdef PowerLedEn
#define hw_setRedLEDOn()             SetGPIO6(1) 
#define hw_setRedLEDOff()            SetGPIO6(0) 

#define hw_setGreenLEDOn()           SetP2_6(1)
#define hw_setGreenLEDOff()          SetP2_6(0)
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<   背光过压保护配置>>>>>>>>>>>>>>>>>>>
=========================================================*/        
//#define BL_OvpSoftProtecEn     //背光过压软件保护 

#ifdef BL_OvpSoftProtecEn 
#define ADC_DETEC_CH           CH0
#define ProtecVolte            2.0
#define ProtecVolteAdcVal(x)  (4096*x)/3.3
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<   电池电量检测配置>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define LowBaterryDetecEn     //电池电量不足

#ifdef LowBaterryDetecEn 
#define BATTER_DETEC_CH      	CH2
#define BatterLowVolte       	1.7   
#define BatterMidVolte         
#define BatterMaxVolte 
#define BatterVolteAdcVal(x) 	(64*x)/3.3
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<   蜂鸣器配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define BuzzerEn              	//蜂鸣器使能开关

#ifdef BuzzerEn
#define hw_turnOnBuzzer()   SetP2_2(1)
#define hw_BuzzerTime()     DelayMs(50)
#define hw_turnOffBuzzer()  SetP2_2(0)
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<  IRAB IO配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define IrABCtrlEn          //IrAB 使能开关

#ifdef IrABCtrlEn
#define hw_setAPort()     SetP1_5(0)
#define hw_setBPort()     SetP1_5(1) 
#define hw_turnOffIRAB()  
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<  IR 发射配置>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define IrSendEn            //红外发送使能开关



/*========================================================
<<<<<<<<<<<<<<<<<<  工厂菜单配置>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//#define FactoryEn                //工厂模式开关

//[Factory PassWord]
#ifdef FactoryEn
#define PassWordBuf             {COMD_SelSource,COMD_SelMode,COMD_LEFT,COMD_RIGHT,COMD_RedrawMenu}
#endif



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  软件功能配置>>>>>>>>>>>>>>>>>>>>
=========================================================*/
//[Software function enable]
//#define NoSignalEn               //NoSignal模块开关
//#define NoSignalBLOffEn        //无信号关背光开关
//#define NoSignalPowerOffEn     //无信号一段时间自动关机开关
//#define QuickParaSaveEn        //快速参数保存开关
//#define NoSignalSnowEn         //无信号出雪花开关
//#define DithingEn             //Dithing使能开关
//#define ColorSysChangeBLOffEn //制式切换黑屏开关


/*====================================================================================
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     系统测试点(TP)   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
======================================================================================*/
/*TP: Test Point，测试点都是通过串口打印来监测相应测试变量，
所以需要使能串口打印测试才能有效。
*/
#define  TP0_ADC    DISABLE  /*ADC 底层采样值(不经过滤波)*/
#define  TP1_ADC    DISABLE  /*ADC 经过滤波处理后的值*/
#define  TP2_ADC    DISABLE  /*ADC Key 返回给应用层的按键值*/
#define  TP3_ADC    DISABLE   /*ADC Key 返回给应用层对应的命令值*/

#define  TP1_KEY    DISABLE  /*Key 返回给应用层对应的消息*/

#define  TP0_RM     DISABLE  /*Remote 底层采样红外值*/   
#define  TP1_RM     DISABLE  /*Remote 按键值对应的消息值*/
#endif

