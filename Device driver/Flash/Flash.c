/****************************************************************************************************
*Copyright (C) 2005 ���ڰ��ƴ������޹�˾��ƷӦ��һ��
* All rights reserved.

*File name: �� Flash.c
*Version:    ��0.1
*Author:       cjinzong
*Finish date:  2008-09-03

*Description:
*           ����ļ��Ƕ�ϵͳ����Ҫ�������б��浽FLASH�ĺ������塣 

*History:
*
***************************************************************************************************/
#define _FLASH_C_

#include "DataType.h"
#include "systemConfig.h"
#include "global.h"
#include "Flash.h"
#include "debug.h"
#include "AMT_REG.h"
#include "AMT_Drv.h"
#include "AMT_MCU.h"



#ifdef FlashEn

FLASH_COMD CODE Flash_comd[]=
{
	{0x39,0x20},
	{0x06,0xD7},
	{0x06,0xD8},
	{0x06,0x20},
};             

/************************************************************************
*name:       CheckIdle(void)
*input:      non
*output:     non
*return:     void

*description: 
           ����������������FLASH�Ƿ���ڿ���״̬
		   �ǣ�  �˳�
		   ���ǣ��ȴ� 
*history:  
*************************************************************************/
void CheckIdle(void)
{
    while(!(IDLE_DF&0x80));
}


void SoftwareBlockProtect(void)
{
    CheckIdle();
	STATUS_DD = 0x00;
	CTRL_DE = FLASH_INT_EN;
	WRDATA_D1 = 0x0c;
	INSTR_D0  = 0x04;
	while(!STATUS_DD);
	CheckIdle();
}

void SoftwareBlockUnprotect(void)
{
    CheckIdle();
	STATUS_DD = 0x00;
	CTRL_DE = FLASH_INT_EN;
	WRDATA_D1 = 0x00;
	INSTR_D0  = 0x04;
	while(!STATUS_DD);
	CheckIdle();
}




/************************************************************************
*name:       WriteDisable(void)
*input:      non
*output:     non
*return:     void
*update:     20090927

*description: 
           ���������������FLASHд������Ϻ� �ر�дʹ�ܡ������ݸ��ȶ�����ȫ�� 
*history:  
*************************************************************************/
void WriteDisable(void)
{
	CheckIdle();
	CTRL_DE = FLASH_INT_EN;	
	ERASE_CMD_E4 = FLASH_WRITE_DISABLE_EN;  //burning-commond	 lj 2008.09.09	
	INSTR_D0 = FLASH_ERASE_EN;	
	CheckIdle();
}


/************************************************************************
*name:       void EnableFlashUnprotected(ULONG stAddr)
*input:      stAddr   flashĿ���ַ
*output:     non
*return:     void

*description: 
          �������������ʹ��flash unprotected sector.
*history:  
*************************************************************************/
void EnableFlashUnprotected(ULONG stAddr)
{
     while((stAddr != FLASH_DAT_ADDR)&&(stAddr != FLASH_COPY_ADDR))
     {
        _nop_();
     }


	 if(FLASH_DAT_ADDR == stAddr)
	 {
			SoftwareBlockUnprotect();

			CheckIdle();
			CTRL_DE = FLASH_INT_EN;
			STATUS_DD = FLASH_CLEAR_STATUS; 

			FADDR_REG0_D6 = (UCHAR)FLASH_DAT_ADDR;
			FADDR_REG1_D7 = (UCHAR)(FLASH_DAT_ADDR>>8);
			FADDR_REG2_D8 = (UCHAR)(FLASH_DAT_ADDR>>16);

			ERASE_CMD_E4 = g_sysSetting.Flash.unprotectedComd;   
			INSTR_D0 = FLASH_ERASE_EN;
			while(!(STATUS_DD));
			CheckIdle();
	 }

	 if(FLASH_COPY_ADDR == stAddr)
	 {
			SoftwareBlockUnprotect();

			CheckIdle();
			CTRL_DE = FLASH_INT_EN;
			STATUS_DD = FLASH_CLEAR_STATUS; 

			FADDR_REG0_D6 = (UCHAR)FLASH_COPY_ADDR;
			FADDR_REG1_D7 = (UCHAR)(FLASH_COPY_ADDR>>8);
			FADDR_REG2_D8 = (UCHAR)(FLASH_COPY_ADDR>>16);

			ERASE_CMD_E4 = g_sysSetting.Flash.unprotectedComd;   
			INSTR_D0 = FLASH_ERASE_EN;
			while(!(STATUS_DD));
			CheckIdle();
	 }
}


/************************************************************************
*name:       void EraseFlashSector(ULONG stAddr)
*input:      stAddr   flashĿ���ַ
*output:     non
*return:     void

*description: 
          �������������ʹ��flash unprotected sector.
*history:  
*************************************************************************/
void EraseFlashSector(ULONG stAddr)
{

     while((stAddr != FLASH_DAT_ADDR)&&(stAddr != FLASH_COPY_ADDR))
     {
        _nop_();
     }
	 
     if(FLASH_DAT_ADDR == stAddr)
     {
			CheckIdle();
			CTRL_DE = FLASH_INT_EN;
			STATUS_DD = FLASH_CLEAR_STATUS; 

			FADDR_REG0_D6 = (UCHAR)FLASH_DAT_ADDR;
			FADDR_REG1_D7 = (UCHAR)(FLASH_DAT_ADDR>>8);
			FADDR_REG2_D8 = (UCHAR)(FLASH_DAT_ADDR>>16);

			ERASE_CMD_E4 = g_sysSetting.Flash.erase4kComd;
			INSTR_D0 = FLASH_ERASE_EN;
			while(!(STATUS_DD));
			CheckIdle();
     }

	 if(FLASH_COPY_ADDR == stAddr)
     {
			CheckIdle();
			CTRL_DE = FLASH_INT_EN;
			STATUS_DD = FLASH_CLEAR_STATUS; 

			FADDR_REG0_D6 = (UCHAR)FLASH_COPY_ADDR;
			FADDR_REG1_D7 = (UCHAR)(FLASH_COPY_ADDR>>8);
			FADDR_REG2_D8 = (UCHAR)(FLASH_COPY_ADDR>>16);

			ERASE_CMD_E4 = g_sysSetting.Flash.erase4kComd;
			INSTR_D0 = FLASH_ERASE_EN;
			while(!(STATUS_DD));
			CheckIdle();
     }
}


/************************************************************************
*name:    ReadFlashSysPara(ULONG stAddr, UCHAR *pSysPara,UINT numOper)
*input:   non   
*output:  non  
*return:  void 

*description:   
     	���������������flash��ϵͳ�������ж�ȡ�� 
*history:  
*************************************************************************/
void ReadFlashSysPara(ULONG stAddr, UCHAR *pSysPara,UINT numOper)
{
	UINT i;
	UCHAR j;

	WriteDisable();
    SoftwareBlockProtect();
	CheckIdle();	
	CTRL_DE = FLASH_INT_EN;	                            

	for(i=0; i<numOper; i++)
	{
	    STATUS_DD = FLASH_CLEAR_STATUS;                  
	
	    FADDR_REG0_D6 = (UCHAR)(stAddr);
	    FADDR_REG1_D7 = (UCHAR)(stAddr>>8);
	    FADDR_REG2_D8 = (UCHAR)(stAddr>>16);

	    INSTR_D0 = FLASH_READ_EN;                         //flash data read enable

	    for(j = 0; j < 20; j++)
		{
		    if(STATUS_DD == FLASH_READ_END)
			{
				pSysPara[i] = RDDATA_D2;
			    break;
			}
		}
	    stAddr++;
	    CheckIdle();
	}
}

/************************************************************************
*name:       WriteFlashSysData(ULONG stAddr,UINT ramdataAddr,UINT numOper)
*input:      stAddr	              flash��Ŀ���ַ
             ramdataAddr		  Ram��Դ��ַ
			 numOper			  д�����ݵĸ���

*output:     non
*return:     void

*description: 
            ���ģ���ǶԶ�E2�ı����������Ӧ��ϵͳ�ռ�
			  1.ϵͳ����
			  2.Ƶ���Ķ�ӦƵ��
			  3.����    
*history:  
*************************************************************************/
void WriteFlashSysPara(ULONG stAddr,UINT ramdataAddr,UINT numOper)
{   
	UINT  Length;
	UINT maxOperNum = 0xffff;                         //���ֵ�Ĵ�С������FLASH���ͺ�������       
	
	EnableFlashUnprotected(stAddr);
	EraseFlashSector(stAddr);

	while(numOper > 0)
	{
	    CheckIdle();
	
	    CTRL_DE = FLASH_INT_EN;	                    
	    STATUS_DD = FLASH_CLEAR_STATUS;                  
	
	    FADDR_REG0_D6 = (UCHAR)stAddr;
	    FADDR_REG1_D7 = (UCHAR)(stAddr>>8);
	    FADDR_REG2_D8 = (UCHAR)(stAddr>>16);

	    DADDR_REG0_D9 = (UCHAR)ramdataAddr;
	    DADDR_REG1_DA = (UCHAR)(ramdataAddr/256);
	    DADDR_REG1_DA |= 0x80;					             //data ram

	    if(numOper <= maxOperNum)
	    {
		    Length = numOper;
	    }
	    else
	    {
		    Length = maxOperNum;
	    }

        if(Length >= 256)   //ÿ��дһ��page
        {
            Length = 256;
        }

	    LOAD_LENGTH0_DB = Length - 1;             
	    LOAD_LENGTH1_DC = 0;

	    INSTR_D0 = FLASH_PROGRAM_EN;

	    stAddr += Length;
	    ramdataAddr += Length;
	    numOper -= Length;

	}
	
	SoftwareBlockProtect();
	WriteDisable();
}



BOOL VerifyFlashDate(ULONG stAddr)
{
    UCHAR XDATA i;
	
    for(i=0;i<3;i++)
    {
		ReadFlashSysPara(stAddr, (UCHAR *)&g_sysSetting, sizeof(SysWorkParaType)); 
		if((g_sysSetting.OXAA == 0xaa) && (g_sysSetting.OX55 == 0x55))
		{
		     return TRUE;
		}
    }
	return FALSE;
}

void AutoDetectFlashType(void)
{
    UCHAR XDATA i;
	
	printfStr("AutoDetectFlashType");

    if(!VerifyFlashDate(FLASH_DAT_ADDR)) 
  	{		
  	    for(i=0;i<5;i++)
  	    {
           g_sysSetting.Flash.erase4kComd = Flash_comd[i].FLASH_ERASE_4K;
           g_sysSetting.Flash.unprotectedComd = Flash_comd[i].FLASH_UNPROTECTED_EN;
		   g_sysSetting.OX55 = 0x55;
		   g_sysSetting.OXAA = 0xaa;
		   WriteFlashSysPara(FLASH_DAT_ADDR, (UCHAR *)&g_sysSetting, sizeof(SysWorkParaType));
		   if(VerifyFlashDate(FLASH_DAT_ADDR)) 
		   {
			    EnableFlashUnprotected(FLASH_DAT_ADDR);
			    EraseFlashSector(FLASH_DAT_ADDR);

			    if(!VerifyFlashDate(FLASH_DAT_ADDR))
			  	{   
			  	    g_ucFlashTpye = i;
					break;
			  	}
				else
				{ 
				    g_ucFlashTpye = 0;
				}
		   }
  	    }
  	}
}

#endif

