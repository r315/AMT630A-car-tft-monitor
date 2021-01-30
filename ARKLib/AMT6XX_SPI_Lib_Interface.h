/*
Author:yshuizhou
Date: 20130704
Description: 
AMT6XX 目前已经初始化成功的CPU屏、传统小尺寸数字屏、SRGB屏接口。
*/
#ifndef AMT6XX_SPI_LIB_INTERFACE_H__
#define  AMT6XX_SPI_LIB_INTERFACE_H__

//CPU屏
extern void CPU_HX8357C_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_ILI9341_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_ILI9342C_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_ILI9486L_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_RM61581B_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_RM68130_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_OTM4001A_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_ILI9488_18Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_HX8352CT_16Bit_Pannel_Initial(UCHAR AmtType);
extern void CPU_HX8352CN_18Bit_Pannel_Initial(UCHAR AmtType);


//传统SPI屏
extern void SPI_TM035KDH08_Pannel_Initial(UCHAR Interface,UINT VcomVal);//interface:24BIT_RGB_DEN(default),default VcomVal:0x75
extern void WriteTM035KDH08Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LQ035NC111_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:0x65
extern void WriteLQ035NC111Reg(UINT RegAddr,UINT RegDat);
extern void SPI_KD035G6_54NT_A1_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:0x65
extern void WriteKD035G6_54NT_A1Reg(UINT RegAddr,UINT RegDat);
extern void SPI_KD040G1_54NC_A2_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:NULL
extern void WriteKD040G1_54NC_A2Reg(UINT RegAddr,UINT RegDat);
extern void SPI_XY20810350050003RegWrite_Pannel_Initial(UCHAR Interface,UINT VcomVal);//interface:24BIT_RGB_HV,default VcomVal:0x00F8
extern void WriteXY20810350050003Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LD035H3_54NM_A1_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:0x00dd
extern void WriteLD035H3_54NM_A1Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LTV350QV_F09_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal: NULL
extern void WriteLTV350QV_F09Reg(UINT RegAddr,UINT RegDat);
extern void SPI_ILI9322_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:0x47
extern void WriteILI9322Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LQ035Q1DH01_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:24BIT_RGB_HV,default VcomVal:0x00a7
extern void WriteLQ035Q1DH01Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LQ035Q1DH02_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:18BIT_RGB_HV,default VcomVal:NULL
extern void WriteLQ035Q1DH02Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LQ035Q1DG01_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:18BIT_RGB_HV,default VcomVal:NULL
extern void WriteLQ035Q1DG01Reg(UINT RegAddr,UINT RegDat);
extern void WriteLQ035Q1DG01Dat(UINT RegAdr);
extern void SPI_AO35QN05_V0_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:8BIT_RGB_HV,default VcomVal:0x4d
extern void WriteAO35QN05_V0Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LQ035NC012_Pannel_Initial(UCHAR Interface,UINT VcomVal);//interface:24BIT_RGB_HV  default VcomVal:0X164 
extern void WriteLQ035NC012Reg(UINT Data);
extern void SPI_NT35582_Pannel_Initial(UCHAR Interface,UINT VcomVal);//interface:24BIT_RGB_SPI,default VcomVal:NULL
extern void WriteNT35582Reg(UINT RegAddr,UINT RegDat);
extern void SPI_PT035TN01_Pannel_Initial(UCHAR Interface,UINT VcomVal);   //interface:24BIT_RGB_HV,default VcomVal:NULL
extern void WritePT035TN01Reg(UINT RegAddr,UINT RegDat);


//SRGB屏
extern void SPI_AO35QN05_V0_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:8BIT_RGB_HV,default VcomVal:0x4d
extern void WriteAO35QN05_V0Reg(UINT RegAddr,UINT RegDat);
extern void SPI_LS025A8DZXX_Pannel_Initial(UCHAR Interface,UINT VcomVal);//interface:8BIT_RGB_HV,default VcomVal:NULL
extern void WriteLS025A8DZXXReg(UINT RegAddr,UINT RegDat);
extern void SPI_WK25QV00_Pannel_Initial(UCHAR Interface,UINT VcomVal); //interface:8BIT_RGB_HV,default VcomVal:NULL
extern void WriteWK25QV00Reg(UINT RegAddr,UINT RegDat);


#endif
