/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� GetUserIputMsg.c
*Version:    ��0.1
*Author:       cjinzong
*update:       2011-12-09

*Description:
            ���ļ�������ȡ�������ң����Ϣ��
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
           ��ȡIR �İ���ֵ��
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
           ��ȡ������İ���ֵ��
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
			 //ADC�����ɼ�����ʵ�ʵİ���ֵ
			  curKey = POS_GetAdcKeyValue();
				
			 //ת��������
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
			  
			 //I2C�����ɼ�����ʵ�ʵİ���ֵ
		     curKey = POS_GetI2CKeyValue();

			 //ת��������
			 if(KEYRELEASE != curKey.Status)
			 {
		 	   curKeyCmd = POS_TransferI2CKeyCmd(curKey);
			 }
			 break;

		default:
			 break;
    }
	
	//ת��ΪӦ�ò����Ϣ
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
*output:     ���ض�Ӧ����ֵ����Ϣ
*update:     2011-12-22

*description:   
         ��������Ǹ��ݵ�ǰ����ֵ��SysKeyMapӳ����в�����Ӧ�İ�����Ϣ��
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
*output:     ���ض�Ӧ����ֵ�ĺ����
*update:     2011-12-22

*description:   
         ��������Ǹ��ݵ�ǰ����ֵ��SysKeyCmdMapӳ����в�����Ӧ�İ������
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
*output:     ���ض�Ӧ����ֵ�ĺ����
*update:     2012-01-06

*description:   
         ��������Ǹ��ݵ�ǰ����ֵ��SysKeyCmdMapӳ����в�����Ӧ�İ������
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

