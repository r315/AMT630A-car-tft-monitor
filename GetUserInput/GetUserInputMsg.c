/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 GetUserIputMsg.c
*Version:    　0.1
*Author:       cjinzong
*update:       2011-12-09

*Description:
            此文件用来获取按键板和遥控信息。
*History:  

************************************************************************/
#define _GET_USER_MSG_C_


#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "MsgMap.h"
#include "debug.h"
#include "KeypadMap.h"
#include "AdcKeyPad.h"
#include "TouchKeyPad.h"
#include "Ir.h"
#include "GetUserInputMsg.h"
#include "AMT_Drv.h"
#include "Delay.h"


#ifdef KeyDetectEn
KeyCmdMap CODE SysAdcKeyCmdMap[] =
{
   AdcKeyCmdMap
};


KeyCmdMap CODE SysI2cKeyCmdMap[] =
{
   I2cKeyCmdMap
};


KeyMsgMap CODE SysKeyMsgMap[] =
{
   GeneralKeyMsgMap
};
#endif


/***********************************************************
*name:       GetIrMsg(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           获取IR 的按键值。
*history:
                                
************************************************************/
#ifdef IrDetectEn
MSG POS_GetIrMsg(void)
{
	MSG  XDATA curIrMsg = MSG_NULL; 
	UINT XDATA curIrKeyVal = IR_NULL_KEY;

	curIrKeyVal = POS_GetRemoteKeyVal(g_ucRemoteKeyVal);

	if(IR_NULL_KEY !=curIrKeyVal)
	{
		g_UserInputInfo.Type = IrType;
		
		curIrMsg = POS_TransferIrKeyMsg(curIrKeyVal);	
		
		#if TP1_RM
		printf("TP1_RM >> the ir Msg %x:\r\n",curIrMsg);
		#endif
	}
	
	return curIrMsg;
}
#endif

/***********************************************************
*name:       GetKeyPadMsg(void)
*input:      void
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
           获取按键板的按键值。
*history:
                                
************************************************************/
#ifdef KeyDetectEn
MSG POS_GetKeyPadMsg(void)
{
	UCHAR curKeyCmd  = NULL_CMD;
	KeyInfor curKey = {NULL_KEY,MSG_NULL,NULL_TIME,KEYRELEASE}; 
	MSG curKeyMsg;


    switch(g_ucSelKeyDevice)
    {
        case ADC_KEY:
			 //ADC按键采集到的实际的按键值
			  curKey = POS_GetAdcKeyValue();
				
			 //转出宏命令
			 if(KEYRELEASE != curKey.Status)
			 {
				g_bReleaseAdcKeyFlg = FALSE;
				curKeyCmd = POS_TransferAdcKeyCmd(curKey);
			 }
			 else
			 {
				g_bReleaseAdcKeyFlg = TRUE;
			 }
			 break;

		case IIC_KEY:
			  
			 //I2C按键采集到的实际的按键值
		     curKey = POS_GetI2CKeyValue();

			 //转出宏命令
			 if(KEYRELEASE != curKey.Status)
			 {
		 	   curKeyCmd = POS_TransferI2CKeyCmd(curKey);
			 }
			 break;

		default:
			 break;
    }
	
	//转换为应用层的消息
	if(NULL_CMD != curKeyCmd)
	{   
	    g_UserInputInfo.Type = KeyType;
	   	curKey  = POS_TransferKeyMsg(curKeyCmd); 
	}	
	
	curKeyMsg = curKey.KeyMsg;
	return curKeyMsg;
}



/***********************************************************
*name:     	 TransferAdcKeyMsg(UINT AdcKeyVal)
*input:      AdcKeyVal
*output:     返回对应按键值的消息
*update:     2011-12-22

*description:   
         这个函数是根据当前按键值在SysKeyMap映射表中查找相应的按键消息。
*history:yshuizhou   2012/01/06    0.2    build  this  function	
************************************************************/
KeyInfor POS_TransferKeyMsg(UCHAR KeyCmd)
{    
     UCHAR XDATA i;
	 KeyInfor XDATA Key ={NULL_KEY,MSG_NULL,NULL_TIME,KEYRELEASE};
	 
	for(i = 0; i < sizeof(SysKeyMsgMap)/sizeof(SysKeyMsgMap[0]); i++)  
    {
        if(SysKeyMsgMap[i].KeyCmd == NULL_CMD)
        {
            continue;
        }

	    if(KeyCmd == SysKeyMsgMap[i].KeyCmd)
	    {    
	       Key.KeyMsg = SysKeyMsgMap[i].KeyMsg;
		}
	}
	
	#if TP1_KEY
    printf("TP1_KEY >> the KeyMsg is %x:\r\n",Key.KeyMsg);				 
	#endif
	
	return Key;
}



/***********************************************************
*name:     	 TransferAdcKeyCmd(UINT AdcKeyVal)
*input:      AdcKeyVal
*output:     返回对应按键值的宏命令。
*update:     2011-12-22

*description:   
         这个函数是根据当前按键值在SysKeyCmdMap映射表中查找相应的按键命令。
*history:yshuizhou   2012/01/06    0.2    build  this  function	
************************************************************/
UCHAR POS_TransferAdcKeyCmd(KeyInfor Key)
{
     UCHAR XDATA i,j;
	 UCHAR XDATA KeyCmd  = NULL_CMD;
	 
	 for(i = 0; i < sizeof(SysAdcKeyCmdMap)/sizeof(SysAdcKeyCmdMap[0]); i++)
	 {
	    if(NULL_KEY == SysAdcKeyCmdMap[i].KeyVal)
	    {
	        continue;
	    }
			
		if(readFlg(SysAdcKeyCmdMap[i].KeyVal,AdcChannelBit) == readFlg(Key.KeyVal,AdcChannelBit))
		{   			

			if(0X00 == Key.KeyVal)
			{
			    for(j = 0; j < sizeof(SysAdcKeyCmdMap)/sizeof(SysAdcKeyCmdMap[0]); j++)
			   	{
				     if(NULL_KEY == SysAdcKeyCmdMap[j].KeyVal)
				     {
				        continue;
				     }
					if(Key.KeyVal == SysAdcKeyCmdMap[j].KeyVal)
					{
				        g_ucPreChannel = (UCHAR)(readFlg(Key.KeyVal,AdcChannelBit)>>12);
		                KeyCmd =  SysAdcKeyCmdMap[j].KeyCmd;

					    if(Key.Status == KEYPRESS)
						{					 
						     if(Key.Holdtime < RepeatTime)
							 {    
							    g_UserInputInfo.Status = inputPress;
							 }
							 g_UserInputInfo.Status &=(~inputSpHold);
							 g_UserInputInfo.Status &= (~inputHold);
						}
	                    else if(Key.Status == KEYHOLD)
		                {					
		                   	g_UserInputInfo.Status &= (~inputPress);
							
							if(Key.Holdtime == RepeatTime)
							{
							   g_UserInputInfo.Status = inputHold;
						       g_UserInputInfo.Status &= (~inputSpHold);
							}
							else if(Key.Holdtime == SpRepeatTime)
							{
							   g_UserInputInfo.Status =(inputSpHold |inputHold);				
							}
		                }
					 
                        #if TP3_ADC
						printf("Special Zero TP3_ADC >> Adc Key Macro val = %x", KeyCmd);
                        #endif

						break;
					}
			   	}
			}
			else
			{
			    if(Abs(SysAdcKeyCmdMap[i].KeyVal,Key.KeyVal) < KEY_OFFSET)
				{    				 
				     g_ucPreChannel = (UCHAR)(readFlg(Key.KeyVal,AdcChannelBit)>>12);
		             KeyCmd =  SysAdcKeyCmdMap[i].KeyCmd;

					 if(Key.Status == KEYPRESS)
					 {					 
					     if(Key.Holdtime < RepeatTime)
						 {    
						    g_UserInputInfo.Status = inputPress;
						 }
						 g_UserInputInfo.Status &=(~inputSpHold);
						 g_UserInputInfo.Status &= (~inputHold);
					 }
	                 else if(Key.Status == KEYHOLD)
	                 {					
	                   	g_UserInputInfo.Status &= (~inputPress);
						
						if(Key.Holdtime == RepeatTime)
						{
						   g_UserInputInfo.Status = inputHold;
					       g_UserInputInfo.Status &= (~inputSpHold);
						}
						else if(Key.Holdtime == SpRepeatTime)
						{
						   g_UserInputInfo.Status =(inputSpHold |inputHold);				
						}
	                 }				  
					 
					 #if TP3_ADC
					 printf("TP3_ADC >> Adc Key Macro val = %x", KeyCmd);
					 #endif
					 break;
				}
		}
	 }
   }
   return KeyCmd;
}


/***********************************************************
*name:     	 TransferI2CKeyCmd(UINT KeyVal)
*input:      KeyVal
*output:     返回对应按键值的宏命令。
*update:     2012-01-06

*description:   
         这个函数是根据当前按键值在SysKeyCmdMap映射表中查找相应的按键命令。
*history:yshuizhou   2012/01/06    0.2    build  this  function	
************************************************************/
UCHAR POS_TransferI2CKeyCmd(KeyInfor Key)
{
     UCHAR XDATA i;
	 UCHAR XDATA KeyCmd  = NULL_CMD;

	 for(i = 0; i < sizeof(SysI2cKeyCmdMap)/sizeof(SysI2cKeyCmdMap[0]); i++)
	 {
	    if(NULL_KEY == SysI2cKeyCmdMap[i].KeyVal)
	    {
	        continue;
	    }

		if(Key.KeyVal == SysI2cKeyCmdMap[i].KeyVal)
		{    			
	        KeyCmd =  SysI2cKeyCmdMap[i].KeyCmd;
			if(Key.Status == KEYPRESS)
			{							 
			     if(Key.Holdtime < RepeatTime)
				 {    
				    g_UserInputInfo.Status = inputPress;
				 }
				 g_UserInputInfo.Status &=(~inputSpHold);
				 g_UserInputInfo.Status &= (~inputHold);
			}
			else if(Key.Status == KEYHOLD)
           {		
	           	g_UserInputInfo.Status &= (~inputPress);
				if(Key.Holdtime == RepeatTime)
				{
				   g_UserInputInfo.Status = inputHold;
				   g_UserInputInfo.Status &= (~inputSpHold);
				}
				else if(Key.Holdtime == SpRepeatTime)
				{
				   g_UserInputInfo.Status =(inputSpHold |inputHold);				
				}
            }

            #if TP3_ADC
			printf("TP3_ADC >> I2C Key Macro val = %x", KeyCmd);
            #endif
		    break;
		}
	 }
   return KeyCmd;
}


#endif

