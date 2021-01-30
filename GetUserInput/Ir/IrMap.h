/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 IrMap.h
*Version:    　0.2
*Author:       yshuizhou
*update:      2011-12-30

*Description:
            
*History:
************************************************************************/
#ifndef IR_MAP_H__
#define IR_MAP_H__

#define IrKeyVal(customCode,keyVal)  ((customCode&0XFF00)|keyVal)

#ifdef IrDetectEn 
#if(IR_ID == CR2025_6KEY)
#define IR_CUSTOM_CODE  0X6B86

typedef enum _IrKeyVal
{	
   IR_LEFT=IrKeyVal(IR_CUSTOM_CODE,0x04),
   IR_RIGHT=IrKeyVal(IR_CUSTOM_CODE,0x06),
   IR_MENU=IrKeyVal(IR_CUSTOM_CODE,0x05),
   IR_SOURCE_SWITCH = IrKeyVal(IR_CUSTOM_CODE,0x1b),
   IR_POWER=IrKeyVal(IR_CUSTOM_CODE,0x12),
   IR_MODE=IrKeyVal(IR_CUSTOM_CODE,0x1a),
}IrKeyVal;


/* 红外对应的消息映射表*/
#define IrKeyMsgMap 	{MSG_UPK_LEFT,  		IR_LEFT  	    },\
				  	 	{MSG_UPK_RIGHT, 		IR_RIGHT	    },\
				     	{MSG_UPK_POWER, 		IR_POWER        },\
				     	{MSG_UPK_MENU, 		IR_MENU 	    },\
				     	{MSG_UPK_SOURCE_SWITCH,IR_SOURCE_SWITCH},\
                     	{MSG_UPK_MODE,         IR_MODE         },
#endif //#if(IR_ID == CR2025_6KEY)
#endif //#ifdef IrDetectEn 
#endif //end IR_MAP_H__






