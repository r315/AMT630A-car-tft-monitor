/**************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　  AMTReg.h 
*Version:    　 1.0
*update:        2009-03-24
*Description:
*          这个文件是AMT 的特殊寄存器及其地址的定义. 

*History:  yshuizhou   2011/12/06    1.0    build  this  moudle
****************************************************************/


#ifndef _AMT630A_REG_H__
#define _AMT630A_REG_H__


/***************************** ADC **************************************/
#define ADC_CLOCK    	            	XBYTE[0XFD17]
#define ADC_CTRL_H                  	XBYTE[0xFDB2]
#define ADC_CTRL_M                  	XBYTE[0xFDB1]
#define ADC_CTRL_L                  	XBYTE[0xFDB0]
#define ADC_CFG_L                   	XBYTE[0xFDB4]
#define ADC_CFG_H                   	XBYTE[0xFDB5]
#define ADC_INT_M_L                 	XBYTE[0xFDB6]
#define ADC_INT_M_H                 	XBYTE[0xFDB7]
#define ADC_DBNCE_CNT_L            	XBYTE[0xFDC8]
#define ADC_DBNCE_CNT_M            	XBYTE[0xFDC9]
#define ADC_DBNCE_CNT_H            	XBYTE[0xFDCA]
#define ADC_CH0_DATA_L             	XBYTE[0xFDBC]
#define ADC_CH0_DATA_H             	XBYTE[0xFDBD]
#define ADC_CH1_DATA_L             	XBYTE[0xFDBE]
#define ADC_CH1_DATA_H             	XBYTE[0xFDBF]
#define ADC_CH2_DATA_L             	XBYTE[0xFDC0]
#define ADC_CH2_DATA_H             	XBYTE[0xFDC1]
#define ADC_CH3_DATA_L             	XBYTE[0xFDC2]
#define ADC_CH3_DATA_H             	XBYTE[0xFDC3]
#define ADC_INTER_TIME_L           	XBYTE[0xFDCC]
#define ADC_INTER_TIME_H           	XBYTE[0xFDCD]
#define ADC_INT_STATUS_L            	XBYTE[0xFDB8]
#define ADC_INT_STATUS_H            	XBYTE[0xFDB9]




/****************************OSD******************************************/
#define INDEX_RAM_ADD_L				XBYTE[0XFB00]
#define INDEX_RAM_ADD_H				XBYTE[0XFB0D]
#define INDEX_RAM_DATA_L				XBYTE[0XFB01]
#define INDEX_RAM_DATA_H				XBYTE[0XFB0E]
#define FONT_RAM_ADD_L  				XBYTE[0XFB02]
#define FONT_RAM_ADD_H  				XBYTE[0XFB0F]
#define FONT_RAM_DATA_H     			XBYTE[0XFB04]
#define FONT_RAM_DATA_L      			XBYTE[0XFB03]
#define OSD_1CON		       	    	XBYTE[0XFB05]
#define OSD_2CON		       			XBYTE[0XFB06]
#define OSD_SIZE_X_BK0 		        XBYTE[0XFB07]
#define OSD_SIZE_Y_BK0					XBYTE[0XFB08]
#define OSD_SIZE_X_BK1 		        XBYTE[0XFB12]
#define OSD_SIZE_Y_BK1					XBYTE[0XFB13]
#define OSD_SIZE_X_BK2 		        XBYTE[0XFB18]
#define OSD_SIZE_Y_BK2					XBYTE[0XFB19]
#define OSD_SIZE_X_BK3 		        XBYTE[0XFB1E]
#define OSD_SIZE_Y_BK3					XBYTE[0XFB1F]
#define OSD_SIZE_X_BK4 		        XBYTE[0XFB24]
#define OSD_SIZE_Y_BK4					XBYTE[0XFB25]
#define OSD_POS_XY_H_BK0				XBYTE[0XFB09]
#define OSD_POS_X_L_BK0 		    	XBYTE[0XFB0A]
#define OSD_POS_Y_L_BK0 		    	XBYTE[0XFB0B]
#define OSD_POS_XY_H_BK1				XBYTE[0XFB14]
#define OSD_POS_X_L_BK1 		    	XBYTE[0XFB15]
#define OSD_POS_Y_L_BK1 		    	XBYTE[0XFB16]
#define OSD_POS_XY_H_BK2				XBYTE[0XFB1A]
#define OSD_POS_X_L_BK2 		    	XBYTE[0XFB1B]
#define OSD_POS_Y_L_BK2 		    	XBYTE[0XFB1C]
#define OSD_POS_XY_H_BK3				XBYTE[0XFB20]
#define OSD_POS_X_L_BK3 		    	XBYTE[0XFB21]
#define OSD_POS_Y_L_BK3 		    	XBYTE[0XFB22]
#define OSD_POS_XY_H_BK4				XBYTE[0XFB26]
#define OSD_POS_X_L_BK4 		    	XBYTE[0XFB27]
#define OSD_POS_Y_L_BK4 		    	XBYTE[0XFB28]
#define INDEXRAM_ADD_BK1_START      	XBYTE[0XFB17]
#define INDEXRAM_ADD_BK2_START      	XBYTE[0XFB1D]
#define INDEXRAM_ADD_BK3_START      	XBYTE[0XFB23]
#define INDEXRAM_ADD_BK4_START      	XBYTE[0XFB29]
#define OSD_alpha_bright    	    	XBYTE[0XFB0C]
#define EACH_ICON_COLOR             	XBYTE[0XFB10]
#define BITMAP_SATRT_L_ICON        	XBYTE[0XFB11]
#define BITMAP_SATRT_H_ICON        	XBYTE[0XFB70]

#define OSD_BLINK0_Y_START			XBYTE[0xFB79]
#define OSD_BLINK0_Y_STOP				XBYTE[0xFB7A]
#define OSD_BLINK0_X_START			XBYTE[0xFB7B]
#define OSD_BLINK0_X_STOP				XBYTE[0xFB7C]

#define OSD_BLINK1_Y_START		    XBYTE[0xFB7F]
#define OSD_BLINK1_Y_STOP		    	XBYTE[0xFB80]
#define OSD_BLINK1_X_START		    XBYTE[0xFB81]
#define OSD_BLINK1_X_STOP		    	XBYTE[0xFB82]

#define OSD_BLINK2_Y_START		    XBYTE[0xFB85]
#define OSD_BLINK2_Y_STOP		    	XBYTE[0xFB86]
#define OSD_BLINK2_X_START		    XBYTE[0xFB87]
#define OSD_BLINK2_X_STOP		    	XBYTE[0xFB88]

#define OSD_COLOR		        		XBYTE[0xFB2A]

#define	OSD_V_SCALE_L_BK0				XBYTE[0xFB2B]
#define	OSD_V_SCALE_M_BK0		        XBYTE[0xFB2C]
#define	OSD_V_SCALE_H_BK0		    	XBYTE[0xFB2D]
#define	OSD_H_SCALE_L_BK0				XBYTE[0xFB2F]
#define	OSD_H_SCALE_M_BK0	      		XBYTE[0xFB30]
#define	OSD_H_SCALE_H_BK0				XBYTE[0xFB31]
#define	OSD_H_SCALE_H_V_COEF      	XBYTE[0xFB32]
#define HV_SCALE_COEF_BK1_BK2     	XBYTE[0xFB33]
#define HV_SCALE_COEF_BK3_BK4     	XBYTE[0xFB34]
#define OSD_MIRROR_SET            		XBYTE[0xFB78]

#define CHAR_SIZE_X             		XBYTE[0xFB76]
#define CHAR_SIZE_Y             		XBYTE[0xFB77]

#define ICON_CR1_H                		XBYTE[0xFB56]
#define ICON_CR1_L                		XBYTE[0xFB57]
#define ICON_CR2_H                		XBYTE[0xFB58]
#define ICON_CR2_L                		XBYTE[0xFB59]
#define ICON_CR3_H                		XBYTE[0xFB5A]
#define ICON_CR3_L                		XBYTE[0xFB5B]
#define ICON_CR4_H                		XBYTE[0xFB5C]
#define ICON_CR4_L                		XBYTE[0xFB5D]
#define ICON_CR5_H                		XBYTE[0xFB5E]
#define ICON_CR5_L                		XBYTE[0xFB5F]
#define ICON_CR6_H                		XBYTE[0xFB60]
#define ICON_CR6_L                		XBYTE[0xFB61]

#define OSD_CHANGE_CON   				XBYTE[0XFB62]
#define OSD_CHANGE_HVSYN 				XBYTE[0XFB63]
#define OSD_CHANGE_R    				XBYTE[0XFB64]
#define OSD_CHANGE_G		    		XBYTE[0XFB65]
#define OSD_CHANGE_B		    		XBYTE[0XFB66]


#define OSD_CHANGE_X_START_L 			XBYTE[0XFB68]
#define OSD_CHANGE_Y_START_L			XBYTE[0XFB69]
#define OSD_CHANGE_XY_START_H 		XBYTE[0XFB67]
#define OSD_CHANGE_LENGTH_L			XBYTE[0XFB6B]
#define OSD_CHANGE_WIDTH_L	    	XBYTE[0XFB6C]
#define OSD_CHANGE_LENGTH_WIDTH_H 	XBYTE[0XFB6A]

#define OSD_CHANGE_R_STEP				XBYTE[0XFB6D]
#define OSD_CHANGE_G_STEP				XBYTE[0XFB6E]
#define OSD_CHANGE_B_STEP				XBYTE[0XFB6F]



/*****************************SPI FLASH *********************/
#define INSTR_D0                       XBYTE[0xFDD0]
#define WRDATA_D1                      XBYTE[0xFDD1]
#define RDDATA_D2                      XBYTE[0xFDD2]
#define FETCH_ID0_D3                  	XBYTE[0xFDD3]
#define FETCH_ID1_D4                  	XBYTE[0xFDD4]
#define FETCH_ID2_D5                  	XBYTE[0xFDD5]
#define FADDR_REG0_D6                 	XBYTE[0xFDD6]
#define FADDR_REG1_D7                 	XBYTE[0xFDD7]
#define FADDR_REG2_D8                 	XBYTE[0xFDD8]
#define DADDR_REG0_D9                 	XBYTE[0xFDD9]
#define DADDR_REG1_DA                 	XBYTE[0xFDDA]
#define LOAD_LENGTH0_DB               	XBYTE[0xFDDB]
#define LOAD_LENGTH1_DC               	XBYTE[0xFDDC]
#define STATUS_DD						XBYTE[0xFDDD]
#define CTRL_DE                        XBYTE[0xFDDE]
#define IDLE_DF                        XBYTE[0xFDDF]
#define RD_CMD_E0                      XBYTE[0xFDE0]
#define WR_CMD_E1                      XBYTE[0xFDE1]
#define RD_STA_CMD_E2                 	XBYTE[0xFDE2]
#define WR_STA_CMD_E3                 	XBYTE[0xFDE3]
#define ERASE_CMD_E4                  	XBYTE[0xFDE4]
#define RD_ID_CMD_E5                  	XBYTE[0xFDE5]
#define WR_EN_CMD_E6                  	XBYTE[0xFDE6]

#define CACHE_SIZE_F0                 	XBYTE[0xFDF0]
#define BANK_SWITCH_F1                	XBYTE[0xFDF1]




/*************************************VP CONTROL REG*********************************/
#define VP_EN_REG                      XBYTE[0XFFB0]
#define BRIGHT_REG               		XBYTE[0XFFD4]
#define CONTRAST_REG            		XBYTE[0XFFD3]   
#define SATURATION_REG          		XBYTE[0XFFD6]
#define TINT_REG                       XBYTE[0XFFD5]
#define VDE_REG                    		XBYTE[0XFFD2]
#define SNOW_BIG_SEL                  	XBYTE[0XFFDA] 


/****************************************Global *******************************/
#define ENH_PLL                        XBYTE[0XFD0E]
#define CLK_GATE0_EN                  	XBYTE[0XFD11]
#define CLK_GATE1_EN                  	XBYTE[0XFD12]
#define CLK_GATE2_EN                  	XBYTE[0XFD13]
#define PWM_CLK_SRC                  	XBYTE[0XFD19]
#define PWM_CTRL                 		XBYTE[0XFD1F] 
#define PWM0_CTRL0                		XBYTE[0XFD20] 
#define PWM0_CTRL1               		XBYTE[0XFD21]
#define PWM1_CTRL0              		XBYTE[0XFD22]
#define PWM1_CTRL1                  	XBYTE[0XFD23]
#define PWM2_CTRL0                  	XBYTE[0XFD24]
#define PWM2_CTRL1                 	XBYTE[0XFD25]
#define PWM3_CTRL0             		XBYTE[0XFD26]
#define PWM3_CTRL1        				XBYTE[0XFD27]
#define PWM0_DUTY0              		XBYTE[0XFD28]
#define PWM0_DUTY1                  	XBYTE[0XFD29]
#define PWM1_DUTY0               		XBYTE[0XFD2A]
#define PWM1_DUTY1                  	XBYTE[0XFD2B]
#define PWM2_DUTY0                  	XBYTE[0XFD2C]
#define PWM2_DUTY1                 	XBYTE[0XFD2D]
#define PWM3_DUTY0                 	XBYTE[0XFD2E]
#define PWM3_DUTY1                  	XBYTE[0XFD2F]
#define PWM0_CTRL                   	XBYTE[0XFD20] 
#define PWM0_RATE                 		XBYTE[0XFD28] 
#define PWM1_CTRL                		XBYTE[0XFD22] 
#define PWM1_RATE                   	XBYTE[0XFD2A] 
#define PWM2_CTRL                   	XBYTE[0XFD24] 
#define PWM2_RATE                 		XBYTE[0XFD2C] 
#define PWM3_CTRL                   	XBYTE[0XFD26] 
#define PWM3_RATE                   	XBYTE[0XFD2E] 
#define SelRXD                      	XBYTE[0XFD30]
#define SelTXD                   		XBYTE[0XFD30]
#define SelPWM3                      	XBYTE[0XFD31]
#define SelPWM0                      	XBYTE[0XFD42]
#define SelPWM1                      	XBYTE[0XFD42]
#define SelPWM2                      	XBYTE[0XFD43]
#define SelBOOTUART              		XBYTE[0XFD43] 
#define Variable_Year0                	XBYTE[0XFD5C] 
#define Variable_Year1					XBYTE[0XFD5D] 
#define Variable_Month					XBYTE[0XFD5E] 
#define Variable_Date					XBYTE[0XFD5F] 
#define Variable_Hour					XBYTE[0XFFDB] 
#define Variable_Minute				XBYTE[0XFFDC] 


/*****************************************Decoder *******************************/
#define COLOR_SYS_TV_ACTIVE          	XBYTE[0XFE26]
#define COMPHV_DETECT_EN              XBYTE[0XFE01]
#define COMPHV_EXIT_THR            	XBYTE[0XFE04]
#define COMPHV_HDIFF           		XBYTE[0XFE05]
#define COMPHV_DETECT          		XBYTE[0XFE2A]
#define TRIM_VT_SOG                 	XBYTE[0XFED8]
#define TRIM_VIN2_SOG                 	XBYTE[0XFED9]
#define TRIM_VREF1_SOG                	XBYTE[0XFEDB]
#define VIDEO_LINE_625_525         	XBYTE[0XFE28]
#define AUTO_TV_STANDARD              XBYTE[0XFE2A]
#define DECODER_RST                  	XBYTE[0XFEA0]

/*****************************************Scaler *******************************/
#define SCALER_HSYNC_UPDATE   		XBYTE[0XFCE4]
#define HFZ_LR_BLANK_WR        		XBYTE[0XFCEA]


/*****************************************Video Channel*********************************/
#define VIDEO_SOG_EN              		XBYTE[0XFED7]
#define VIDEO_SOG_SEL               	XBYTE[0XFED8]
#define VIDEO_CH_D0                 	XBYTE[0XFEDC]


#endif

