/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 IR.c
*Version:    　0.1
*Author:       cjinzong
*update:       2011-12-10

*Description:
*History:
************************************************************************/
#define _IR_C_

#include "DataType.h"
#include "systemConfig.h"
#include "MsgMap.h"
#include "Debug.h"
#include "Ir.h"
#include "AMT_REG.h"
#include "AMT_MCU.h"




#ifdef IrDetectEn
#include "IrMap.h"


/*********************Ir Msg Map******************/

IrMsgMap CODE SysIrMsgMap[] =
{
   IrKeyMsgMap
};



/***********************************************************
*name:     	 GetRemoteKeyValue(UINT IrVal)
*input:      IrValue
*output:     返回当前Ir的值。
*state:      allright
*Update:     2011-12-30

*description:   
            查询当前Ir的值。
*history:   yshuizhou   2011/12/30    0.2    build  this  function	
************************************************************/
UINT POS_GetRemoteKeyVal(UINT IrVal)
{    
     UINT XDATA CurrentIr = IR_NULL_KEY;

     if(CheckReleaseFlg())
     {
		  ClrReleaseFlg();
     }
	
	 if((IrVal != IR_NULL_KEY)&&(!g_bLogoFlg))
     {    
          g_ucRemoteKeyVal = IR_NULL_KEY;
		  
          if(CheckRepeatFlg())
	      {
	           //printfStr("repeat");
	           g_UserInputInfo.Status = inputHold;
	      }	 
		  else
		  {
		       //printfStr("no repeat");
		       g_UserInputInfo.Status = inputPress;
		  }
          CurrentIr = IrVal;
		  //printf("boot current key val =%x", CurrentIr);
     }
	 return CurrentIr;
}



/***********************************************************
*name:     	 TransferIrKeyMsg(UINT IrKeyVal)
*input:      IrKeyVal
*output:     返回对应按键值的消息
*update:     2011-12-22

*description:   
         这个函数是根据当前按键值在SysIrMap映射表中查找相应的按键消息。
*history:yshuizhou   2011/12/30    0.2    build  this  function	
************************************************************/
MSG POS_TransferIrKeyMsg(UINT IrKeyVal)
{
     UCHAR XDATA i;
	 MSG XDATA IrMsg =MSG_NULL;
	 
	for(i = 0; i < sizeof(SysIrMsgMap)/sizeof(SysIrMsgMap[0]); i++)
    {
       if(SysIrMsgMap[i].IrVal == IrKeyVal)	   
       {  
             IrMsg = SysIrMsgMap[i].IrMsg;
       } 
    }
    return IrMsg;	
}
#endif


