
#include "DataType.h"
#include "systemConfig.h"
#include "ConfigLcdPara.h"
#include "Global.h"
#include "Debug.h"
#include "Mcu.h"
#include "AMT_Mcu.h"
#include "AMT_Drv.h"


#ifdef SpiInitPannelEn
#ifdef SpiAdjRegEn

UCHAR   g_ucSpiRecStep = 0; 
FLAG    g_bSpiRec = 0; 
UINT    g_uiDataRec = 0; 
UINT    g_uiAddressRec = 0; 
 
void POS_AdjustSpiReg(void)
{   

    if(g_bSpiRec)  
    {
         while(1)
	    { 
	        if(g_bSpiRec) 
	        {  
	           printf("the g_uiAddressRec is %x",g_uiAddressRec);
			   printf("the g_uiDataRec is %x",g_uiDataRec);

			   /*
			   此函数需要根据不同屏SPI初始化替换。
			   */
	           WriteTM035KDH08Reg(g_uiAddressRec,g_uiDataRec);
			   g_bSpiRec = 0;
			   g_uiAddressRec = 0;
			   g_uiDataRec = 0;
	        }
	    }
    }
}


void POS_RecUartSpiInfor(void) 
{
   UCHAR  tmpRec = 0;

   if(RI)
   {
     tmpRec = SBUF;
     RI = 0;
	 
	 switch(g_ucSpiRecStep)
	 {
	   case ProtocolData0: 
	   	    g_ucSpiRecStep = ProtocolData0;
			if(tmpRec == 0x55)
		    {
		      g_ucSpiRecStep = ProtocolData1;
		    }
			break;
			
	   case ProtocolData1:
	  	    if(tmpRec == 0xAA)
		    {
		      g_ucSpiRecStep = AddressDataH;
		    }
			else
			{
			  g_ucSpiRecStep = ProtocolData0;
			}
			break;
			
	   case AddressDataH:
	   	    g_uiAddressRec = tmpRec*256;
            g_ucSpiRecStep = AddressDataL;
	   	    break;

	   case AddressDataL:
	   	    g_uiAddressRec += tmpRec;
		    g_ucSpiRecStep = WriteDataH;
			break;
			
	   case WriteDataH:
	   	    g_uiDataRec = tmpRec*256;
            g_ucSpiRecStep = WriteDataL;
			break;

	  case WriteDataL:
	  	   g_uiDataRec += tmpRec;
		   g_bSpiRec = 1;
           g_ucSpiRecStep = ProtocolData0;
		   break;
	  
	  default:
	       g_ucSpiRecStep = ProtocolData0;
	  	   break;
	 }
   }
}
#endif
#endif

