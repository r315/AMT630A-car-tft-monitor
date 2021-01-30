/*******************************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 Debug.c	  
*Version:      1.0
*update:       2011-12-16
*Description:
  		    调试打印文件。
  		  
*History:  Jordan.chen   2011/12/16    1.0    build  this  moudle
******************************************************************************/
#define _DEBUG_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "AMT_Drv.h"
#include "AMT_MCU.h"


#ifdef UartPrintfEn

#define _EOS_ '\0' 

void putSIOChar(unsigned char sendData)
{
	TI = 0; 
	SBUF = sendData; 
	while(!TI);
}


void putchar(UCHAR ucVal)
{
	TI = 0;
	SBUF = ucVal; 
	while(!TI);
}

void IrqPutstr(UCHAR *pFmt)
{
    UCHAR XDATA ucBff; 

	SetUartPrint();

    while(1)
    {
         ucBff = *pFmt; 
         if (ucBff == _EOS_)
             break;

         putchar(ucBff); 

         pFmt++; 
    } 
	SetI2CDebug();
}


void printfStr(char *str)
{
    BYTE XDATA ucBff;

	SetUartPrint();

  	putSIOChar((char)'\r');
  	putSIOChar((char)'\n');

    while(1)
    {
         ucBff = *str;
         if (ucBff == _EOS_)
             break;
         putSIOChar(ucBff);
         str++;
    }
    SetI2CDebug();
}
void IrqPrintf(char *str, WORD value)
{
	char XDATA sendData;

	SetUartPrint();

  	while(sendData=*(str++))
    {
    	if (sendData==(char)'%') 
        {
        	sendData=*(str++);
          	if (sendData==(char)'d' || sendData==(char)'x') 
            {
            	if (value)
                {
                	BOOL noneZero=FALSE;
                  	WORD XDATA divider=10000;
                  	char XDATA dispValue;

                  	if (sendData==(char)'x')
		    			divider=0x1000;
                  	while (divider)
				    {
				    	dispValue=value/divider;
				      	value-=dispValue*divider;
		            	if (dispValue)
		          			noneZero=TRUE;
		            	if (noneZero)
		                {
		                	if (dispValue>9)
		     					dispValue+=55;
		   					else
		        				dispValue+=0x30;
		 					putSIOChar(dispValue);
		  				}
						if (sendData==(char)'d')
		      				divider/=10;
		      			else
		     				divider/=0x10;
		    		}
                }
              	else
              	{
              		putSIOChar('0');
              	}	
  	    	}
  		}
      	else
        	putSIOChar(sendData);
    }
	SetI2CDebug();
}

void printf(char *str, WORD value)
{
	char XDATA sendData;

	SetUartPrint();

  	putSIOChar((char)'\r');
  	putSIOChar((char)'\n');
	
  	while(sendData=*(str++))
    {
    	if (sendData==(char)'%') 
        {
        	sendData=*(str++);
          	if (sendData==(char)'d' || sendData==(char)'x') 
            {
            	if (value)
                {
                	BOOL noneZero=FALSE;
                  	WORD divider=10000;
                  	char dispValue;

                  	if (sendData==(char)'x')
		    			divider=0x1000;
                  	while (divider)
				    {
				    	dispValue=value/divider;
				      	value-=dispValue*divider;
		            	if (dispValue)
		          			noneZero=TRUE;
		            	if (noneZero)
		                {
		                	if (dispValue>9)
		     					dispValue+=55;
		   					else
		        				dispValue+=0x30;
		 					putSIOChar(dispValue);
		  				}
						if (sendData==(char)'d')
		      				divider/=10;
		      			else
		     				divider/=0x10;
		    		}
                }
              	else
              	{
              		putSIOChar('0');
              	}	
  	    	}
  		}
      	else
        	putSIOChar(sendData);
    }
	SetI2CDebug();
}
#endif

