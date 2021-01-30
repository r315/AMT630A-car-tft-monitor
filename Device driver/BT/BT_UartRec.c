#define _BT_UARTREC_C

#include "DataType.h"
#include <absacc.h>
#include <intrins.h>
#include "systemConfig.h"
#include "ConfigLcdPara.h"
#include "global.h"
#include "debug.h"
#include "BT_UartRec.h"
#include "AMT_Mcu.h"
#include "interrupt.h"
#include "Mcu.h"



#ifdef BTEn
#if(BT_Module == BlueSoleil_i50e)

UCHAR CODE BT_Cmd_table[]=
{
    //A    T    +     B         H     F    A     N    S     W   
    0X41,0X54,0X2B,0X42,0X20,0X48,0X46,0X41,0X4E,0X53,0X57,0X0D, //AT-B HFANSW

    //A    T    +     B         H     F    C     H    U     P   
    0X41,0X54,0X2B,0X42,0X20,0X48,0X46,0X43,0X48,0X55,0X50,0X0D, //AT-B HFCHUP 
};

UCHAR  XDATA g_ucCallerIDAsciiBuf[40] = NULL_ASCII;
UCHAR  XDATA g_ucCallerIDBuf[40] = NULL_ASCII;
UCHAR  XDATA g_ucBTStatus = BT_RELEASE;
UCHAR  XDATA g_ucCallerIDLen = 0;

FLAG   g_bBTConnFlg 		= FALSE;
FLAG   g_bBTDiscFlg		= FALSE;
FLAG   g_bBTCinFlg  		= FALSE;
FLAG   g_bBTCdropFlg  		= FALSE;
FLAG   g_bBTCanswerFlg		= FALSE;
FLAG   g_bCallAnswerFlg	= FALSE;


void POS_BTUartRec(void) 
{
   static UCHAR CODE  StartAsciiBuf[] = ATSTART_ASCIIBUF;
   static UCHAR CODE  BTInitAsciiBuf[] = INIT_ASCIIBUF;
   static UCHAR CODE  BTConnAsciiBuf[]= HFCONN_ASCIIBUF;
   static UCHAR CODE  BTDiscAsciiBuf[]= HFDISC_ASCIIBUF;
   static UCHAR CODE  BTCinAsciiBuf[]= HFCCIN_ASCIIBUF;
   static UCHAR CODE  BTCdropAsciiBuf[]= HFCLCC_ASCIIBUF;
   static UCHAR XDATA UartRecAsciiBuf[255] = NULL_ASCII;
   static UCHAR UartRecCnt = 0;  
   static UCHAR BTLccCmdCnt =0;
   static FLAG  BTInitFlg = FALSE;
   FLAG   StartFlg = TRUE;
   FLAG   BTInitCmdFlg  =  TRUE;
   FLAG   BTConnCmdFlg  = 	TRUE;
   FLAG   BTDiscCmdFlg  = 	TRUE;
   FLAG   BTCinCmdFlg   = 	TRUE;
   FLAG   BTCdropCmdFlg = 	TRUE;
   UCHAR  i;
   UCHAR  tmpRec;
   UCHAR  HFPStatus;
   UCHAR  INITStatus;

   if(RI)
   {
     tmpRec = SBUF;
     RI = 0;	
	 
	 if(tmpRec != ATEDN_ASCII)
	 {
	    UartRecAsciiBuf[UartRecCnt] = tmpRec;  	  
        UartRecCnt++;
	 }
	 else
	 {
	    UartRecAsciiBuf[UartRecCnt] = tmpRec; 
		
		//判断是否为AT-B起始
	    for(i=0;i<sizeof(StartAsciiBuf);i++)
	    {  				 
	       if(UartRecAsciiBuf[i] != StartAsciiBuf[i]) //判断是否为AT指令的起始
	       {
	         StartFlg = FALSE;
	       }
	    }
	   	if(StartFlg)
		{    
		    //判断是否为初始化指令
		    for(i=0;i<sizeof(BTInitAsciiBuf);i++)
			{
			   	if(UartRecAsciiBuf[i+5] != BTInitAsciiBuf[i]) 
			   	{
			   	   BTInitCmdFlg = FALSE;
			   	}
			}
            if(BTInitCmdFlg) //确认为Init命令
            {
              INITStatus = UartRecAsciiBuf[10];  //INIT Status Val
              if(INIT_CONNSUCCESS == INITStatus)
              {
                 BTInitFlg = TRUE;
              }
			  UartRecCnt = 0;
              return;
            }

			if(BTInitFlg)
			{
		        //判断是否为连接指令
			    for(i=0;i<sizeof(BTConnAsciiBuf);i++)
				{
				   	if(UartRecAsciiBuf[i+5] != BTConnAsciiBuf[i]) 
				   	{
				   	   BTConnCmdFlg = FALSE;
				   	}
				}
			    if(BTConnCmdFlg) //确认为Conn命令
				{
				    HFPStatus = UartRecAsciiBuf[12];  //HFP Connect Status Val
					if(HFP_CONNSUCCESS == HFPStatus)
					{
					    g_bBTConnFlg = TRUE;
	                    g_bBTDiscFlg = FALSE;
						g_ucBTStatus = BT_LINK;
					}
					UartRecCnt = 0;
	                return;
				}
			
			    //判断是否为断开指令
			    for(i=0;i<sizeof(BTDiscAsciiBuf);i++)
				{
				   	if(UartRecAsciiBuf[i+5] != BTDiscAsciiBuf[i]) 
				   	{
				   	   BTDiscCmdFlg = FALSE;
				   	}
				}
				if(BTDiscCmdFlg) //确认为Disc命令
				{
					HFPStatus = UartRecAsciiBuf[12];  //HFP Disc Status Val
					if(HFP_DISCSUCCESS == HFPStatus)
					{
					   g_bBTDiscFlg = TRUE;
					   g_bBTConnFlg = FALSE;
					   g_ucBTStatus = BT_RELEASE;
					}
					UartRecCnt = 0;
		            return;
				}

				//判断是否为来电命令
			    for(i=0;i<sizeof(BTCinAsciiBuf);i++)
				{
				   	if(UartRecAsciiBuf[i+5] != BTCinAsciiBuf[i]) 
				   	{
				   	   BTCinCmdFlg = FALSE;
				   	}
				}
				if(BTCinCmdFlg) //确认为Cin命令
				{   
				    g_ucCallerIDLen = 0;
					
					for(i= 24; i<UartRecCnt;i++) //接收Caller ID
					{
					   if((UartRecAsciiBuf[i] >= 0X30)&&(UartRecAsciiBuf[i] <= 0X39))
					   {  
					      g_ucCallerIDAsciiBuf[g_ucCallerIDLen] = UartRecAsciiBuf[i];
						  g_ucCallerIDLen++;
					   }
					   else
					   {
					     UartRecCnt = 0;
						 return;
					   }
					}
					g_bBTCinFlg = TRUE;
					BTLccCmdCnt = 0;
					UartRecCnt  = 0;
		            return;
				}

				//判断是否为挂断命令
				for(i=0;i<sizeof(BTCdropAsciiBuf);i++)
				{
				   	if(UartRecAsciiBuf[i+5] != BTCdropAsciiBuf[i]) 
				   	{
				   	   BTCdropCmdFlg = FALSE;
				   	}
				}
				if(BTCdropCmdFlg) //确认为Lcc命令
				{
					HFPStatus = UartRecAsciiBuf[12];  //HFP Lcc Status Val  
					if(HFP_SUCCESS == HFPStatus)
					{
					   ++BTLccCmdCnt;
					   if(BTLccCmdCnt == 0X02)
					   { 
					     g_bBTCdropFlg = TRUE;
						 BTLccCmdCnt = 0;
					   }
					}
					UartRecCnt = 0;
		            return;
				}
		  }
		}	
		UartRecCnt = 0;
	 }
   }
}


void PutBTChar(UCHAR Val)
{	
	TI = 0; 
	SBUF = Val; 
	while(!TI);
}


void POS_UartSendCmd(UCHAR Val)
{
    UCHAR XDATA i;
	UCHAR XDATA num;
	
	num = Val*12;
	
	for(i=0;i<12;i++)
    {
	  PutBTChar(BT_Cmd_table[num+i]);
	}
}
#endif
#endif
