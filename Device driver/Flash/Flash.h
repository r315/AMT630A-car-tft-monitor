/*
 FLASH Í·ÎÄ¼þ¡£
*/
#ifndef _FLASH_H__
#define _FLASH_H__



#ifdef _FLASH_C_
#define _FLASH_EXTERN_
#else
#define _FLASH_EXTERN_    extern
#endif


#define FLASH_INT_EN            	0X80
#define FLASH_CLEAR_STATUS 	 	0X00 
#define FLASH_ERASE_EN          	0X08
#define FLASH_PROGRAM_EN        	0X80
#define FLASH_READ_EN           	0x10
#define FLASH_READ_END          	0X10
#define FLASH_WRITE_DISABLE_EN 	0x04


#define FLASH_LOGO_ADDR      0X10000
#define FLASH_DAT_ADDR       0X0F000  
#define FLASH_COPY_ADDR      0X0E000


typedef struct
{
   UCHAR   FLASH_UNPROTECTED_EN;		
   UCHAR   FLASH_ERASE_4K;	   
}FLASH_COMD;


extern FLASH_COMD CODE Flash_comd[];	


_FLASH_EXTERN_ UCHAR XDATA  g_ucFlashTpye;


_FLASH_EXTERN_ void AutoDetectFlashType(void);
_FLASH_EXTERN_ BOOL VerifyFlashDate(ULONG stAddr);
_FLASH_EXTERN_ void WriteFlashSysPara(ULONG stAddr,UINT ramdataAddr,UINT numOper);
_FLASH_EXTERN_ void ReadFlashSysPara(ULONG stAddr, UCHAR *pSysPara,UINT numOper);


#endif
