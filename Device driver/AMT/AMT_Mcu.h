/**************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　  AMT_Mcu.h 
*Version:    　 1.0
*Author:      　cjinzong
*Update:        2009-03-24
* 
*Description:
*          8052的头文件

*History:
*
****************************************************************/
#ifndef _AMT_MCU_H__
#define _AMT_MCU_H__


sfr MCU_CFG_REG = 0xc6;


// BYTE Registers
sfr P0     = 0x80;
sfr P1     = 0x90;
sfr P2     = 0xA0;
sfr P3     = 0xB0;

sfr PSW    = 0xD0;      //Program Status Word
sfr ACC    = 0xE0;      //Accumulator
sfr B      = 0xF0;      //Accumulator B
sfr SP     = 0x81;      //Stack Pointer
sfr DPL    = 0x82;      //Data Pointer0 Low Bytes
sfr DPH    = 0x83;      //Data Pointer0 High Bytes
sfr PCON   = 0x87;
sfr TCON   = 0x88;      //Timer0/1 Control Reg.
sfr TMOD   = 0x89;      //Timer0/1 Mode Reg.
sfr TL0    = 0x8A;      //Timer 0 Low 8 bits
sfr TL1    = 0x8B;      //Timer 1 Low 8 bits
sfr TH0    = 0x8C;      //Timer 0 High 8 bits
sfr TH1    = 0x8D;      //Timer 1 High 8 bits
sfr IE     = 0xA8;      //Interrrupt Enable Reg.
sfr IP     = 0xB8;      //Interrrupt Priority
sfr SCON   = 0x98;
sfr SBUF   = 0x99;

sfr DPL1   = 0x84;      //Data Pointer1 Low Bytes
sfr DPH1   = 0x85;      //Data Pointer1 High Bytes
sfr DPS    = 0x86;      //Data Pointer Select
sfr CKCON  = 0x8E;      //Clock Control of External RAM Timing
sfr EXIF   = 0x91;      //Extend Interrupt Flag Reg.2
sfr SCON1  = 0xC0;
sfr SBUF1  = 0xC1;
sfr STATUS = 0xC5;
sfr TA     = 0xC7;
sfr T2CON  = 0xC8;      //Timer2 Control Reg.
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;      //Capture Timer2 Low
sfr RCAP2H = 0xCB;      //Capture Timer2 High
sfr TL2    = 0xCC;      //Timer 2 Low 8 bits
sfr TH2    = 0xCD;      //Timer 2 High 8 bits
sfr EICON  = 0xD8;      //Extend Interrupt Control Reg.2
sfr EIE    = 0xE8;      //Extend Interrupt Enable Reg.
sfr EIP    = 0xF8;      //Extend Interrrupt Priority


//Ark1859 EXTENSIONS
sfr P0_OEN     = 0xE9;
sfr P1_OEN     = 0xEA;
sfr P2_OEN     = 0xEB;
sfr P3_OEN     = 0xEC;
sfr P0_IEN     = 0xED;
sfr P1_IEN     = 0xEE;
sfr P2_IEN     = 0xEF;
sfr P3_IEN     = 0xF4;


sfr I2CEN      = 0xF5;
sfr BOOTEN     = 0xF6;

/* I2C REGISTER */
sfr I2CM_SHIFT  = 0xc7;
sfr I2CM_CLK    = 0xc2;
sfr I2CM_CTRL   = 0xc4; 
sfr I2C_ACKC    = 0xc3;
sfr I2CM_CTRL1  = 0xc5;


// WATCHDOG REGISTER
sfr WDT_COUNTL 	= 0xbc;
sfr WDT_COUNTH  	= 0xbd;
sfr WDT_RSTEN  	= 0xba;
sfr WDT_CLR    		= 0xbb;
sfr MCU_CLK_REG	= 0xb9;
sfr WDT_UPDATE_EN 	= 0xbe;

/* TIMER34 REGISTER */
sfr T3_CNTL 		= 0xb1;
sfr T3_CNTH 		= 0xb2;
sfr T4_CNTL 		= 0xb3;
sfr T4_CNTH 		= 0xb4;
sfr WDTIRQ  		= 0xb5;
sfr WDTIEN  		= 0xb6;

// BIT Registers
// PSW
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit FL    = PSW^1;
sbit P     = PSW^0;
// TCON
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;
// IE
sbit EA    = IE^7;
sbit ES1   = IE^6;
sbit ET2   = IE^5;
sbit ES    = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;
// IP
sbit PS1   = IP^6;
sbit PT2   = IP^5;
sbit PS0   = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;


// P0
sbit LED2  = P0^7;
sbit LED1  = P0^6;		 
sbit TXD   = P0^3;
sbit RXD   = P0^2;
sbit REMOTE   = P0^1;
sbit BOOT_SEL = P0^0;


// P1
sbit INT4  = P1^5;
sbit INT3  = P1^4;
sbit T2    = P1^3;
sbit T2EX  = P1^2;
sbit T1    = P1^1;
sbit T0    = P1^0;


// SCON
sbit SM0   = SCON^7; /* alternative SM0_FE_0 */
sbit SM1   = SCON^6; /* alternative SM1_0 */
sbit SM2   = SCON^5; /* alternative SM2_0 */
sbit REN   = SCON^4; /* alternative REN_0 */
sbit TB8   = SCON^3; /* alternative TB8_0 */
sbit RB8   = SCON^2; /* alternative RB8_0 */
sbit TI    = SCON^1; /* alternative TI_0  */
sbit RI    = SCON^0; /* alternative RI_0  */

// SCON1
sbit SM01  = SCON1^7; /* alternative SM0_FE_1  */
sbit SM11  = SCON1^6; /* alternative SM1_1  */
sbit SM21  = SCON1^5; /* alternative SM2_1  */
sbit REN1  = SCON1^4; /* alternative REN_1  */
sbit TB81  = SCON1^3; /* alternative TB8_1  */
sbit RB81  = SCON1^2; /* alternative RB8_1  */
sbit TI1   = SCON1^1; /* alternative TI_1   */
sbit RI1   = SCON1^0; /* alternative RI_1   */

// T2CON
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;

// EICON
sbit SMOD_1 = EICON^7;
sbit EPFI   = EICON^5;
sbit PFI    = EICON^4;
sbit WDTI   = EICON^3;

// EIE
sbit EWDI  = EIE^4;
sbit EX5   = EIE^3;
sbit EX4   = EIE^2;
sbit EX3   = EIE^1;
sbit EX2   = EIE^0;

// EIP
sbit PWDI  = EIP^4;
sbit PX5   = EIP^3;
sbit PX4   = EIP^2;
sbit PX3   = EIP^1;
sbit PX2   = EIP^0;

// Port 0
sbit P0_0  = P0^0;
sbit P0_1  = P0^1;
sbit P0_2  = P0^2;
sbit P0_3  = P0^3;
sbit P0_4  = P0^4;
sbit P0_5  = P0^5;
sbit P0_6  = P0^6;
sbit P0_7  = P0^7;

// Port 1
sbit P1_0  = P1^0;
sbit P1_1  = P1^1;
sbit P1_2  = P1^2;
sbit P1_3  = P1^3;
sbit P1_4  = P1^4;
sbit P1_5  = P1^5;
sbit P1_6  = P1^6;
sbit P1_7  = P1^7;

// Port 2
sbit P2_0   = P2^0;
sbit P2_1   = P2^1;
sbit P2_2   = P2^2;
sbit P2_3   = P2^3;
sbit P2_4   = P2^4;
sbit P2_5   = P2^5;
sbit P2_6   = P2^6;
sbit P2_7   = P2^7;

// Port 3
sbit P3_0  = P3^0;
sbit P3_1  = P3^1;
sbit P3_2  = P3^2;
sbit P3_3  = P3^3;
sbit P3_4  = P3^4;
sbit P3_5  = P3^5;
sbit P3_6  = P3^6;
sbit P3_7  = P3^7;

/*****************************REMOTE REG*********************************/
sfr R_BUFF1 		= 0xe1;
sfr R_BUFF0 		= 0xe2;
sfr R_VALUE 		= 0xe3;
sfr R_KEY_VALUE 	= 0xe4;
sfr R_FLAG 			= 0xe5;

#endif
