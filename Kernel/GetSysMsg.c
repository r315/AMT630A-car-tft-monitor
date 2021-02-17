/***********************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� GetSysMsg.c
*Version:    ��0.1
*Author:       cjinzong
*update:       2011-12-09

*Description:
             ���ļ���ϵͳ�ɼ���Ϣ��ϵͳ���е���Ϣ�������ɴ��ļ�������
*History:  

************************************************************************/
#define _GET_MSG_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "MsgMap.h"
#include "debug.h"
#include "mcu.h"
#include "GetUserInputMsg.h"
#include "GetSysMsg.h"
#include "ConfigLcdPara.h"
#include "interrupt.h"
#include "delay.h"
#include "Osd_Menu.h"
#include "Osd_MenuPage.h"
#include "sysPower.h"
#include "AMT_REG.h"
#include "AMT_Drv.h"
#include "AMT_MCU.h"
#include "BatteryAdc.h"
#include "BT_UartRec.h"


/***********************************************************
*name:       POS_GetUserInputMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡ�û�������Ϣ����Ҫ�а�����ң��������Ϣ��
          
*history:

************************************************************/
MSG POS_GetUserInputMsg(FLAG timer)
{
    MSG XDATA curInputMsg = MSG_NULL;
	
	if(timer)
	{
	    g_bGetUserInputFlg = 0;
		
	    #ifdef IrDetectEn
		curInputMsg = POS_GetIrMsg();
		if(curInputMsg != MSG_NULL)
		{
		    return curInputMsg;
		}
		#endif
		
		#ifdef KeyDetectEn
		curInputMsg = POS_GetKeyPadMsg();
		if(curInputMsg != MSG_NULL)
		{  			
		    return curInputMsg;
		}
		#endif
	}
	return MSG_NULL;
}



/***********************************************************
*name:       POS_GetSignalMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡ�ź�״̬��Ϣ����Ҫ�Ǽ���ź����ޣ��ź�ǿ����״̬��
          
*history:

************************************************************/
MSG POS_GetSignalMsg(FLAG timer)
{
#define DetecTimes   20

	static UCHAR XDATA ucCont = 0;
	static FLAG   bSignalFlg = FALSE;
	
	if(timer)
	{
	    g_bGetSignalFlg = 0;
		
        //�����źż��
		if(bSignalFlg == ((COLOR_SYS_TV_ACTIVE&_BIT1)>>1))
		{   
			if(ucCont<DetecTimes)
			{
			    ucCont++; 
				if(ucCont == DetecTimes)
				{
				     if(bSignalFlg)
				     {   
				         return MSG_SIGNAL_OK; //�ɿ����ź�
				     }
					 else
					 {   
					     return MSG_NO_SIGNAL;//���ź�
					 }
				}
			}
		}
		else
		{
		    ucCont = 0; 
		    bSignalFlg = (COLOR_SYS_TV_ACTIVE&_BIT1)>>1;
		}
	}
	return MSG_NULL;
}


/***********************************************************
*name:       POS_GetColorSysMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡͼ����ʽ��Ϣ������PAL/NTSC/SECAM���л�������ͼ��Ч����
          
*history:

************************************************************/
MSG POS_GetColorSysMsg(FLAG timer)
{
	if(timer)
	{
		g_bGetColorSysFlg = 0;
		
	    if((g_ucColorSys != g_ucPreColorSys))
	    {
	        g_ucPreColorSys = g_ucColorSys;
			if(g_ucColorSys != NULL_SYS)  
	        {
	        	g_sysSetting.Video.colorSys = g_ucColorSys;
				printf("g_sysSetting.Video.colorSys =%x", g_sysSetting.Video.colorSys);
				if(g_sysSetting.Video.colorSys < AUTO)
				{
				     return MSG_CONFIG_COLOR_SYS; 
	            }
				else
				{
				     return MSG_NULL;
				}
	        }
	    }
	}
	return MSG_NULL;    
}



/***********************************************************
*name:       POS_GetTimeMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡϵͳʱ����Ϣ�����綨ʱ����
          
*history:

************************************************************/
MSG POS_GetTimeMsg(FLAG timer)
{
#define NoSyncTime          10

	if(timer)
	{  
		g_bGetTimeFlg = 0;
		
		if(g_sysSetting.Osd.dispTime>0)
		{   
		    if(--g_sysSetting.Osd.dispTime == 0)
		    {    
		         /*�ڴ��ж��Ƿ���Ҫ�˳�OSD ������Ҫ��ʾLOGO�������˵�*/
                 return MSG_OSD_EXIT;
		    }
		}

		#ifdef QuickParaSaveEn 
        if(g_sysSetting.Osd.storageTime < OSD_STORAGE_TIME)  
        {
			if(++g_sysSetting.Osd.storageTime == OSD_STORAGE_TIME)
            {
                /*�ڴ��ж��Ƿ���Ҫ����OSD����*/
                return(MSG_OSD_STORAGE);
            }
        }
		#endif
		
		#ifdef NoSignalPowerOffEn
		#define NoSignalSecond          2
		if(IsPowerOn()&&!IsSignalOk())
		{
			if(POS_SysTimeDriver())
			{
			    if(g_ucContBufSecond >= 60)
			    {
			        g_ucContBufSecond -= 60;
					g_ucContNoSignalSecond++;

				    if(g_ucContNoSignalSecond >= NoSignalSecond)
					{
					    return MSG_NOSIGNALPOWEROFF;
					}
			    }
			}
		}
		else
		{
		    g_ucContNoSignalSecond = 0X00;
		}
		#endif
	}
	return MSG_NULL;       
}


/***********************************************************
*name:       POS_GetBatteryAdcMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡϵͳ��ص�ʵʱ��ѹ��Ϣ��
          
*history:

************************************************************/
MSG POS_GetBatteryAdcMsg(FLAG timer)
{

	UINT  XDATA curBatteryAdcVal = NULL_BATTERYADC;

    if(timer)
    {
        g_bGetBatteryAdcFlg = 0;
		
		#ifdef LowBaterryDetecEn 
		curBatteryAdcVal = POS_GetBatteryAdcValue();
		if(NULL_BATTERYADC != curBatteryAdcVal)
		{
             g_ucBatteryAdcVal = curBatteryAdcVal & 0X00FF; 
             return MSG_BATTERYADC;
		}
		#endif
		
    }
    return MSG_NULL;  
}


/***********************************************************
*name:       POS_GetUserDefinedMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
         ��ȡ�û��Զ�����Ϣ������һЩIO��״̬ �ȵ�ʵʱ������Ϣ��
          
*history:

************************************************************/
MSG POS_GetUserDefinedMsg(FLAG timer)
{
#define IsCarReversing()      		((COMPHV_DETECT & _BIT6) == _BIT6)

	#ifdef CarReversingSignalDetectEn
    static FLAG   s_bAvCarNoSignalFlg = TRUE;
	#endif
		
	if((timer)&&(!IsFactoryEn()))
	{
		#ifdef CarBackEn
		#ifdef CarReversingSignalDetectEn
		g_bGetUserDefFlg = 0;
        
		if(g_sysSetting.Car.RemberSource == INPUT_CAMERA_Car)  //����ͨ��
		{
             if(IsCarReversing())
             {
	             SelVideoDevice(INPUT_CAMERA_Car);
				 if(g_sysSetting.Power.status == POWER_OFF)
				 {
		             if(g_sysSetting.Car.status != CAR_POF_REVERSING)
		             {
		                  return MSG_CAR_POF_REVERSING;
		             }
				 }
				 else
				 {
				     if(g_sysSetting.Car.status != CAR_PON_REVERSING)
		             {   
		                  return MSG_CAR_PON_REVERSING;
		             }
				 }
             }
             else
             {
	             if(!IsSignalOk())
	             {
	               SelCarSOGIn();
				   SelNullChannel();
				   if(g_sysSetting.Power.status == POWER_OFF)
				   {
		               if(g_sysSetting.Car.status != CAR_POF_GO_AHEAD)
		               {  
		                   s_bAvCarNoSignalFlg = TRUE;
		                   return MSG_CAR_POF_GO_AHEAD;
		               }
				   }
				   else
				   {
				       if(g_sysSetting.Car.status != CAR_PON_GO_AHEAD)
		               {
		                  s_bAvCarNoSignalFlg = TRUE;
		                  return MSG_CAR_PON_GO_AHEAD;
		               }
				   }
	             }
				 else
				 {
				       if(g_sysSetting.Power.status == POWER_OFF)
                       {
	                        if(g_sysSetting.Car.status != CAR_POF_REVERSING)
	                        {
	                            return MSG_CAR_POF_REVERSING;
	                        }
                       }
 					   else
                       {
	                       if(g_sysSetting.Car.status != CAR_PON_REVERSING)
	                       {   
	                           return MSG_CAR_PON_REVERSING;
	                       }
                       }
				 }
             }
		}
		else //�ǵ���ͨ��
		{
			switch(g_sysSetting.Car.DetecMode)
			{
				case AV_CAR_NO_SIGANL:	
					  if(s_bAvCarNoSignalFlg)
 					  {
 					    s_bAvCarNoSignalFlg = FALSE;
 	                    if(IsCarReversing())
 	                    {
                           g_sysSetting.Car.DetecMode = AV_SIGNAL_OK;
                           SelVideoDevice(INPUT_AV1);
						   
						   #ifdef NoSignalBLOffEn 
						   ExitLowPowerMode();
						   TurnOnBackLight();
						   #else
						   DelayMs(400);	
						   #endif
 	                    }
 						else
 						{  
 						   SelCarSOGIn();
 						   SelAv1Channel();
 						}
 					   }
					  else
					  {
					    s_bAvCarNoSignalFlg = TRUE;
					    SelCarSOGIn();
					    SelAv1Channel();
					    if(IsCarReversing())
					    {    
							 if(g_sysSetting.Power.status == POWER_ON)
							 {								 
                                 g_sysSetting.Car.status = CAR_PON_REVERSING;
                                 g_sysSetting.Car.DetecMode = CAR_SIGNAL_OK;
                                 g_sysSetting.Video.curSource = INPUT_CAMERA_Car;
                                 SelVideoDevice(INPUT_CAMERA_Car);
								 
                                 #ifdef NoSignalBLOffEn 
								 OsdHide();
                                 ExitLowPowerMode();
                                 TurnOnBackLight();
                                 #else
                                 DelayMs(400);	
                                 #endif
							 }
							 else
							 {
								 return MSG_CAR_POF_REVERSING;
							 }
					    }
					    else
					    {
					      SelAvSOGIn();
						  SelCarChannel();
					    }
					 }
					break;

			  case AV_SIGNAL_OK:	
					SelCarSOGIn();
				    SelAv1Channel();
					if(IsCarReversing())
					{
						 if(g_sysSetting.Power.status == POWER_ON)
						 {
							 return MSG_CAR_PON_REVERSING;
						 }
						 else
						 {
							 return MSG_CAR_POF_REVERSING;
						 }
					}
					else
					{  	
						if(!IsSignalOk())
						{	
						    g_sysSetting.Car.DetecMode = AV_CAR_NO_SIGANL;
							
						    #ifdef NoSignalBLOffEn 
	                        TurnOffBackLight();
							EnterLowPowerMode();
	                        #endif
						}
					}					
					break;
					
			   case CAR_SIGNAL_OK:
					 if(!IsSignalOk())
					 {
						if(g_sysSetting.Power.status == POWER_ON)
						{
							if(g_sysSetting.Car.RemberSource != g_sysSetting.Video.curSource)
							{     
							     s_bAvCarNoSignalFlg = TRUE;
								 return MSG_CAR_PON_GO_AHEAD;	
							}
						}
						else
						{
							if(g_sysSetting.Car.RemberSource != g_sysSetting.Video.curSource)
							{   
							     s_bAvCarNoSignalFlg = TRUE;
								 return MSG_CAR_POF_GO_AHEAD;	  
							}
						}
					 }
					 break;
				 
			   case PON_CAR_SIGNAL_OK:
					 return MSG_PON_REVERSING; 
					 break;
			 
			   default:
					break;
						
			}

		}		
		#endif
		
		#ifdef CarReversingIODetectEn
		#define ContIOState   10
	    static FLAG LastIOState = hw_setCarBackAheadStatus;  
	    static UCHAR XDATA IOStateCnt=ContIOState;
	    FLAG   CurrentIOStatus;

		g_bGetUserDefFlg = 0;
		
		CurrentIOStatus = hw_getCarBackPinStatus();
		
		if(CurrentIOStatus != LastIOState)
		{
		   LastIOState = CurrentIOStatus;
           IOStateCnt = 0;
		}
        else
		{
            if(IOStateCnt < ContIOState)
		    {
               if(++IOStateCnt == ContIOState)
			   {
               
                  if(CurrentIOStatus != hw_setCarBackAheadStatus)
				  {
                     //printfStr("CarReversing......");
                     if(g_sysSetting.Power.status == POWER_ON)
				     {   
                         return MSG_CAR_PON_REVERSING;
				     }
					 else
					 {   
					     return MSG_CAR_POF_REVERSING;
					 }
				  }
				  else
				  {
					    //printfStr("Go Ahead......");
					    if(g_sysSetting.Power.status == POWER_ON)
					    {
						   return MSG_CAR_PON_GO_AHEAD;	
						}
					   else
					   {
	                       return MSG_CAR_POF_GO_AHEAD;	
					   }
				  }					
		        }
            }
        }
		#endif  
		#else
		g_bGetUserDefFlg = 0;
		#endif
	}
	return MSG_NULL;  
}




/***********************************************************
*name:       POS_GetBTMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡBT���ӡ��ͷţ��������Ҷϵ���Ϣ��
          
*history:

************************************************************/
MSG POS_GetBTMsg(FLAG timer)
{
   if(timer)
   {
       g_bGetBTFlg = 0;
	   
       #ifdef BTEn
       if(g_bBTConnFlg)
       {
        return MSG_BT_CONN;
       }
       
       if(g_bBTDiscFlg)
       {
        return MSG_BT_DISC;
       }
       
       if(g_bBTCinFlg)
       {
        return MSG_BT_CALLERID;
       }
       
       if(g_bBTCdropFlg)
       {
        return MSG_BT_CALLERDROP;
       }
	   #endif
   }
   return MSG_NULL; 
}



/***********************************************************
*name:       POS_GetMiscMsg(timeflg)
*input:      timeflg  //��ʱʱ���־
*output:     void 
*update:     2011-11-27 
*state:      allright

*description:   
          ��ȡ������Ϣ����Ҫ��һЩ���ܷ������Ϣ��
          
*history:

************************************************************/
MSG POS_GetMiscMsg(FLAG timer)
{
	if(timer)
	{
		g_bGetMiscFlg = 0;

		#ifdef ColorSysChangeBLOffEn
		if(g_ucContBLOn > 0)
		{   
	        g_ucContBLOn--;
			if(g_ucContBLOn == 0)
			{
	          return MSG_TURNON_BACKLIGHT;
			}
		}
        #endif
		
		#ifdef BL_OvpSoftProtecEn 
		if(g_bReleaseAdcKeyFlg)
		{
		    #define BLOvpSofProtec    3
		    static UCHAR XDATA BLOvpSofProtecStateCnt = 0;
			
		    if(POS_EnableChipAdc(ADC_DETEC_CH) > ProtecVolteAdcVal(ProtecVolte))
			{
			    BLOvpSofProtecStateCnt++;
			}
			else
			{
			   BLOvpSofProtecStateCnt = 0;
			}
            if(BLOvpSofProtecStateCnt >= BLOvpSofProtec)
            {
               return MSG_TURNOFF_BACKLIGHT;
            }
		}
		#endif

		#ifdef UartTerminal
			if(TERM_HasData()){
				return MSG_SERIAL;
			}
		#endif
	}
	return MSG_NULL;  
}



