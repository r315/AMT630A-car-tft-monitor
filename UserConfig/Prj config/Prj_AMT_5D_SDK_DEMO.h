/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� Prj_AMT_7D_SDK_DEMO.h
*Version:    ��0.1
*Author:       cjinzong
*update:       20111208

*Description:
            
*History:
************************************************************************/
#ifndef AMT_PRJ_CONFIG_H__
#define AMT_PRJ_CONFIG_H__

/*========================================================
<<<<<<<<<<<<<<<<<<<<<<                >>>>>>>>>>>>>>>>>>>>
=========================================================*/
//[Hardware function enable]
#define BacklightEn          	//�������ʹ�ܿ���
#define KeyDetectEn             //�������ʹ�ܿ���
//#define IrDetectEn           	//ң�ؼ��ʹ�ܿ���
//#define LogoEn                //Logoģ�鿪��
//#define CarBackEn            	//����ʹ�ܿ���
//#define PannelSfrDispEn      	//��������ʾʹ�ܿ��� (��ת)
//#define SpiInitPannelEn       //SPI ����ʼ��ʹ�ܿ���
//#define CpuInitPannelEn       //Cpu ����ʼ��ʹ�ܿ���
//#define AudioCtrlEn          	//��������ʹ�ܿ���
//#define FmSendEn              //Fm����ʹ�ܿ���
//#define BTEn                  //����ʹ�ܿ���
//#define FlashEn 
//#define PowerLedEn            //��Դָʾ��ʹ�ܿ��� 
//#define BL_OvpSoftProtecEn    //�����ѹ�������� 
//#define LowBaterryDetecEn     //��ص�������
//#define BuzzerEn              //������ʹ�ܿ���
//#define IrABCtrlEn            //IrAB ʹ�ܿ���
//#define IrSendEn              //���ⷢ��ʹ�ܿ���
//#define FactoryEn             //����ģʽ����

/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  ������������>>>>>>>>>>>>>>>>>>>>
=========================================================*/
//[Software function enable]
#define NoSignalEn               //NoSignalģ�鿪��
//#define NoSignalBLOffEn        //���źŹر��⿪��
//#define NoSignalPowerOffEn     //���ź�һ��ʱ���Զ��ػ�����
//#define QuickParaSaveEn        //���ٲ������濪��
//#define NoSignalSnowEn         //���źų�ѩ������
//#define DithingEn             //Dithingʹ�ܿ���
//#define ColorSysChangeBLOffEn //��ʽ�л���������
#define UartTerminal
/*========================================================
<<<<<<<<<<<<<<<<<<<<<   оƬ�ͺ�����>>>>>>>>>>>>>>>>>>>>>
=========================================================*/
//[AMT chip type]
#define AMT_TYPE       AMT630A
#define WebSite        "www.arkmicro.com"



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<   ����ʾ����>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/   
//[LCD pannel parameter list]  
#define P_HDSA191106PFW_EN      ENABLED

//[VcomDC type]
#define VCOMDC_TYPE    			NULL_PWM  
#define DEFAULT_VCOMDCFREQ	    0
#define DEFAULT_VCOMDCVAL       0

/*========================================================
<<<<<<<<<<<<<<<<<< ����������>>>>>>>>>>>>>>>>>
=========================================================*/
#define VD_EN                   _BIT0  //����AGCʹ�ܿ��� DAGC_0XFE90 
#define PDF_EN                  _BIT1 //���໷ʹ�ܿ���  PDFC3_0XFE35��PDFC2_0XFE34 
#define VL_EN                   _BIT3 //����ʹ�ܿ���   0XFEA7��0XFE2E 

#define VdLibCmd                VD_EN|PDF_EN|VL_EN
#define ConfigUserPara()

/*========================================================
<<<<<<<<<<<<<<<<<<<<   ͼ����ʾ����>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Video Channel]
#define AV1                     CVBS1   //av
#define AV2                     CVBS3   //car detect
#define AV3                     CVBS4   //reserve

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
#define BRIGHT_MIN           	0X49   //���ȵ�����Сֵ
#define	BRIGHT_MAX          	0XA9   //���ȵ������ֵ                                     
#define	CONTRAST_MIN        	0X00   //�Աȶȵ�����Сֵ           
#define	CONTRAST_MAX        	0XB0   //�Աȶȵ������ֵ                                                   
#define	SATURATION_MIN      	0X00  //ɫ�ȵ�����Сֵ
#define	SATURATION_MAX     	    0X44  //ɫ�ȵ������ֵ



/*========================================================
<<<<<<<<<<<<<<<<<<<<   �����������>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Backlight ctrl]

#ifdef BacklightEn
#define BACKLIGHT_CTRL_MODE     DC_PWM0_CTRL // DC_PWM0_CTRL��DC_PWM1_CTRL��DC_PWM2_CTRL��DC_PWM3_CTRL��GPIO_CTRL 

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
<<<<<<<<<<<<<<<<<<<<   ������������>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Key detect Ctrl]

#ifdef KeyDetectEn 
#define hw_upResistance      			12000     //��������ֵ  12k
#define hw_downResistance    			0        // 0:��ʾ����������
#define hw_keyVoltage        			3.3  
#define ADC_CH_LIST         			{CH2} //{CH0,CH1,CH2} //ͨ���б�   
#define hw_Key_getSDA_input()     	GetP1_0()      //SDA
#define hw_Key_setSDA_output(x)   	SetP1_0(x)    //SDA
#define hw_Key_setSCL_output(x)   	SetP1_1(x)  //SCL

#define ADCKEY_PAD_ID        			KP_ARK_DEBUG_V01  //������
#define I2CKEY_PAD_ID        			KP_ZYD_909K_V10  //I2C ������

#define KEY_OFFSET           			0X0A         //������ƫ����
#define RepeatTime           			0X15        //����������Ӧʱ��
#define SpRepeatTime         			0X50        //���ⳤ��ת������
#endif//#ifdef KeyDetectEn 



/*========================================================
<<<<<<<<<<<<<<<<<<<<   IR��������>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[IR detect Ctrl]

#ifdef IrDetectEn
#define IR_TYPE          		NEC  
#define IR_DECODE_MODE       	IR_HARDWARE
#define IR_ID                 	CR2025_6KEY
#define IR_Delta_DATA        	0X05
#define IR_Delta_96ms        	0X0F	
#endif  //#ifdef IrDetectEn

/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  OSD ��������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[OSD Icon Size And ScalerRatio]
#define ICON_SIZE							SIZE_12X16//SIZE_16X22   SIZE_12X16

#if(ICON_SIZE == SIZE_12X16)
#define ICON_SIZE_X                       	12     //ICON ˮƽ���ص���
#define ICON_SIZE_Y                       	16    //ICON ��ֱ����
#define OsdScalerRatio						2 
#define NoSignalScalerRatio              	4
#elif(ICON_SIZE == SIZE_16X22)
#define ICON_SIZE_X                       	16    //ICON ˮƽ���ص���
#define ICON_SIZE_Y                       	22    //ICON ��ֱ����
#define OsdScalerRatio						1 
#define NoSignalScalerRatio              	2
#endif

//[OSD style]
#define OSD_STYLE_TYPE         			OSD_STYLE_ARK

//[OSD bar lenght]
#define MAX_VALUE               			100    //���ֵ

//[OSD menu X Y position]
#define MAINMENU_START_X_POS   			0X014C      //MAIN MENU �˵���X��ʼλ��
#define MAINMENU_START_Y_POS   			0X01BA     //MAIN MENU �˵���Y��ʼλ��

#define SOURCEMENU_START_X_POS 			0X032A   //SOURCE MENU �˵���X��ʼλ��
#define SOURCEMENU_START_Y_POS 			0X001C   //SOURCE MENU �˵���Y��ʼλ��

#define SOURCE_43_START_X_SHIFT          0X65      //SOURCE MENU �˵�4:3ģʽ ��16:9ģʽ��X��ֵ

#define NOSIGNALMENU_START_X_POS 		0x014B   //NOSIGNAL MENU �˵���X��ʼλ��
#define NOSIGNALMENU_START_Y_POS 		0x00E2   //NOSIGNAL MENU �˵���Y��ʼλ��

#define BTMENU_START_X_POS 				0x0000   //BT MENU �˵���X��ʼλ��
#define BTMENU_START_Y_POS    			0x000A   //BT MENU �˵���Y��ʼλ��

#define BTCALLERMENU_START_X_POS 		0x0055   //BTCALLER MENU �˵���X��ʼλ��
#define BTCALLERMENU_START_Y_POS 		0x0090   //BTCALLER MENU �˵���Y��ʼλ��

#define BATTERYADCMENU_START_X_POS 		0x0015   //BATTERYADC MENU �˵���X��ʼλ��
#define BATTERYADCMENU_START_Y_POS 		0x0000   //BATTERYADC MENU �˵���Y��ʼλ��

#define MUTEMENU_START_X_POS   			0X0018   //MUTE MENU �˵���X��ʼλ��
#define MUTEMENU_START_Y_POS   			0X0020   //MUTE MENU �˵���Y��ʼλ��
        
#define FACTORYMENU_START_X_POS  			0X00AC   //FACTORY MENU �˵���X��ʼλ��
#define FACTORYMENU_START_Y_POS  			0X008A   //FACTORY MENU �˵���Y��ʼλ��

//[OSD default language]
#define DEFAULT_LANGUAGE        			JAPANESE//CHINESE//ENGLISH  //OSD Ĭ������

//[OSD display timeout]
#define OSD_DISP_TIME           		200     //OSD ��ʾʱ��
#define OSD_STORAGE_TIME           		100     //OSD ������ʾʱ��

//[OSD Position Offset]
#define MAX_OFFSETVALUE         		50    //���ֵ



/*========================================================
<<<<<<<<<<<<<<<<<<<<<<  LOGO ��������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Logo enable]

//[Logo display mode]
#define LOGO_DISP_MODE          		POWER_ON_DISP_LOGO


//[Logo display backcolor]
#define LOGO_DISP_BACKCOLOR             WHITE     //LOGO��ʾ������ɫ

//[Logo menu X Y position]
#define LOGO1MENU_START_X_POS 		    0X0070   //LOGO1 MENU �˵���X��ʼλ��
#define LOGO1MENU_START_Y_POS 		    0X0055   //LOGO1 MENU �˵���Y��ʼλ��

#define LOGO2MENU_START_X_POS 		    0X0070   //LOGO2 MENU �˵���X��ʼλ��
#define LOGO2MENU_START_Y_POS 		    0X0055   //LOGO2 MENU �˵���Y��ʼλ��

#define LOGO3MENU_START_X_POS 		    0X0070   //LOGO3 MENU �˵���X��ʼλ��
#define LOGO3MENU_START_Y_POS 		    0X0055   //LOGO3 MENU �˵���Y��ʼλ��

#define LOGO4MENU_START_X_POS 		    0X0070   //LOGO4 MENU �˵���X��ʼλ��
#define LOGO4MENU_START_Y_POS 		    0X0055   //LOGO4 MENU �˵���Y��ʼλ��

#define LOGO5MENU_START_X_POS 		    0X0070   //LOGO5 MENU �˵���X��ʼλ��
#define LOGO5MENU_START_Y_POS 		    0X0055   //LOGO5 MENU �˵���Y��ʼλ��



/*========================================================
<<<<<<<<<<<<<<<<<<<<  �����������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef CarBackEn

//#define CarReversingIODetectEn    	   //IO ��⵹��ʹ��
#define CarReversingSignalDetectEn     //�źż�⵹��ʹ��

#ifdef CarReversingIODetectEn
#define hw_setCarBackAheadStatus  	1     		//����״̬������״̬
#define hw_getCarBackPinStatus()   	GetP1_5()   //������λ
#endif

#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   ��������ʾ����>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef PannelSfrDispEn
#define hw_SfrDisp_PinRL(x)	SetP0_5(x) 
#define hw_SfrDisp_PinUD(x)	SetP0_4(x) 

#define hw_turnToLeft()     	{hw_SfrDisp_PinRL(1); hw_SfrDisp_PinUD(0);}
#define hw_turnToRight() 	 	{hw_SfrDisp_PinRL(0); hw_SfrDisp_PinUD(0);}
#define hw_turnToUp()	     	{hw_SfrDisp_PinRL(0); hw_SfrDisp_PinUD(1);}
#define hw_turnToDown()	 	{hw_SfrDisp_PinRL(1); hw_SfrDisp_PinUD(1);}
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   ��SPI��ʼ������>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[SPI Inital Pannel Ctrl]
#ifdef SpiInitPannelEn
//#define SpiAdjRegEn  //���ڵ�����SPI�Ĵ���ʹ�ܿ���
#define hw_setCs(x)    SetP1_7(x)
#define hw_setClk(x)   SetP0_6(x) 
#define hw_setDout(x)  SetP1_6(x)
#define hw_setReset(x) SetGPIO12(x)
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   CPU ����ʼ������>>>>>>>>>>>>>>>>>>>
=========================================================*/ 

/*========================================================
<<<<<<<<<<<<<<<<<<<<   Audio ��������>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Audio Ctrl]
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
<<<<<<<<<<<<<<<<<<<<   FM ��������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef FmSendEn
#define FM_CHIP                        KT0803l

#define hw_FmSend_getSDA_input()     GetSdaIn()      
#define hw_FmSend_setSDA_output(x)   SetSdaOut(x)    
#define hw_FmSend_setSCL_output(x)   SetSclOut(x) 
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   BT����>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef BTEn
#define BT_Module           BlueSoleil_i50e
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   ����洢����>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 

/*========================================================
<<<<<<<<<<<<<<<<<<   ��ԴLED ָʾ����>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Power LED]
#ifdef PowerLedEn
#define hw_setRedLEDOn()             SetGPIO6(1) 
#define hw_setRedLEDOff()            SetGPIO6(0) 

#define hw_setGreenLEDOn()           SetP2_6(1)
#define hw_setGreenLEDOff()          SetP2_6(0)
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<   �����ѹ��������>>>>>>>>>>>>>>>>>>>
=========================================================*/        
#ifdef BL_OvpSoftProtecEn 
#define ADC_DETEC_CH           CH0
#define ProtecVolte            2.0
#define ProtecVolteAdcVal(x)  (4096*x)/3.3
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<   ��ص����������>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef LowBaterryDetecEn 
#define BATTER_DETEC_CH      	CH2
#define BatterLowVolte       	1.7   
#define BatterMidVolte         
#define BatterMaxVolte 
#define BatterVolteAdcVal(x) 	(64*x)/3.3
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<   ����������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef BuzzerEn
#define hw_turnOnBuzzer()   SetP2_2(1)
#define hw_BuzzerTime()     DelayMs(50)
#define hw_turnOffBuzzer()  SetP2_2(0)
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<  IRAB IO����>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
#ifdef IrABCtrlEn
#define hw_setAPort()     SetP1_5(0)
#define hw_setBPort()     SetP1_5(1) 
#define hw_turnOffIRAB()  
#endif
/*========================================================
<<<<<<<<<<<<<<<<<<<<  IR ��������>>>>>>>>>>>>>>>>>>>>>>
=========================================================*/ 

/*========================================================
<<<<<<<<<<<<<<<<<<  �����˵�����>>>>>>>>>>>>>>>>>>>
=========================================================*/ 
//[Factory PassWord]
#ifdef FactoryEn
#define PassWordBuf             {COMD_SelSource,COMD_SelMode,COMD_LEFT,COMD_RIGHT,COMD_RedrawMenu}
#endif

/*====================================================================================
<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<     ϵͳ���Ե�(TP)   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
======================================================================================*/
/*TP: Test Point�����Ե㶼��ͨ�����ڴ�ӡ�������Ӧ���Ա�����
������Ҫʹ�ܴ��ڴ�ӡ���Բ�����Ч��
*/
#define  TP0_ADC    DISABLE  /*ADC �ײ����ֵ(�������˲�)*/
#define  TP1_ADC    DISABLE  /*ADC �����˲��������ֵ*/
#define  TP2_ADC    DISABLE  /*ADC Key ���ظ�Ӧ�ò�İ���ֵ*/
#define  TP3_ADC    DISABLE   /*ADC Key ���ظ�Ӧ�ò��Ӧ������ֵ*/

#define  TP1_KEY    DISABLE  /*Key ���ظ�Ӧ�ò��Ӧ����Ϣ*/

#define  TP0_RM     DISABLE  /*Remote �ײ��������ֵ*/   
#define  TP1_RM     DISABLE  /*Remote ����ֵ��Ӧ����Ϣֵ*/
#endif

