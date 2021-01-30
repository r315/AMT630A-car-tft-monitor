/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 KeypadMap.h
*Version:    　0.2
*Author:       yshuizhou
*update:      2011-12-30

*Description:
            
*History:
************************************************************************/
#ifndef KEY_PAD_MAP_H__
#define KEY_PAD_MAP_H__

#ifdef KeyDetectEn 

#if hw_upResistance 
#define hw_keyAdcVal(rVal)  ((UINT)(4096*((float)rVal*hw_keyVoltage/(((float)rVal+hw_upResistance)*3.3))))>>4
#endif

#if hw_downResistance
#define hw_keyAdcVal(rVal)  ((UINT)(4096*((float)hw_downResistance*hw_keyVoltage/(((float)rVal+hw_downResistance)*3.3))))>>4
#endif


#if(ADCKEY_PAD_ID == KP_ARK_DEBUG_V01)
//key val : adcCh + adcVal
#define hw_KEY_POWER    	makeUint16 (CH2, hw_keyAdcVal(0))
#define hw_KEY_SOURCE     	makeUint16 (CH2, hw_keyAdcVal(27000))
#define hw_KEY_MENU   		makeUint16 (CH2, hw_keyAdcVal(56000))
#define hw_KEY_LEFT     	makeUint16 (CH2, hw_keyAdcVal(8200))
#define hw_KEY_RIGHT    	makeUint16 (CH2, hw_keyAdcVal(15000))


//ADC Key Cmd Map
#define AdcKeyCmdMap {hw_KEY_POWER,     KEY_POWER        },\
	                  {hw_KEY_SOURCE,    KEY_SOURCE_SWITCH},\
                      {hw_KEY_LEFT ,	   KEY_LEFT       },\
                      {hw_KEY_MENU,      KEY_MENU         },\
                      {hw_KEY_RIGHT ,	   KEY_RIGHT      },


#endif// #if(ADCKEY_PAD_ID == KP_ARK_DEBUG_V01)

#if(I2CKEY_PAD_ID == KP_ZYD_909K_V10)
//key val
#define hw_I2CKEY_POWER       			0X0001
#define hw_I2CKEY_SOURCE    	    	0X0002
#define hw_I2CKEY_LEFT         		0X0008
#define hw_I2CKEY_MENU        	   	 	0X0100
#define hw_I2CKEY_RIGHT            	0X0400


//I2C Key Cmd Map
#define I2cKeyCmdMap	{hw_I2CKEY_POWER,     KEY_POWER        },\
	                  	{hw_I2CKEY_SOURCE,    KEY_SOURCE_SWITCH},\
	                  	{hw_I2CKEY_LEFT ,	   	KEY_LEFT         },\
	                  	{hw_I2CKEY_MENU,      KEY_MENU         },\
	                  	{hw_I2CKEY_RIGHT ,	KEY_RIGHT        },
	                  
#endif //#if(I2CKEY_PAD_ID == KP_ZYD_909K_V10)

/* 按键对应的消息映射表*/
#define GeneralKeyMsgMap  {MSG_UPK_POWER, 		KEY_POWER 	       },\
							{MSG_UPK_SOURCE_SWITCH, KEY_SOURCE_SWITCH  },\
			                {MSG_UPK_LEFT,  		KEY_LEFT  	       },\
			                {MSG_UPK_MENU, 		    KEY_MENU		   },\
							{MSG_UPK_RIGHT, 		KEY_RIGHT	       },
							
#endif//#ifdef KeyDetectEn 
#endif// end KEY_PAD_MAP_H__





