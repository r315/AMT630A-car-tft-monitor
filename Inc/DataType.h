/***********************************************************************
*Copyright (C) 2005 深圳艾科创新有限公司产品应用一部
* All rights reserved.

*File name: 　 dataType.h
*Version:    　0.1
*Author:       cjinzong
*update:       20100129

*Description:
       数据类型定义头文件
*History:
************************************************************************/
#ifndef _DATA_TYPE_H__
#define _DATA_TYPE_H__

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<公共类型定义>>>>>>>>>>>>>>>>>>>>>>>>>>> */
typedef bit 			FLAG;
typedef bit             BIT;
typedef bit             BOOL;

typedef char            CHAR;

typedef unsigned char	UCHAR;
typedef unsigned char   BYTE;
typedef unsigned char   UINT8;

typedef unsigned int    UINT;
typedef unsigned int    WORD;
typedef unsigned int    UINT16;

typedef unsigned long 	ULONG;
typedef unsigned long   DWORD;
typedef unsigned long   UINT32;

typedef signed char	    SCHAR;
typedef signed char     SBYTE;
typedef signed char     INT8;

typedef signed int	    SINT;
typedef	signed int      SWORD;
typedef signed int      INT16;

typedef signed long	    SLONG;
typedef signed long     SDWORD;
typedef signed long     INT32;

typedef unsigned char   *PUCHAR;
typedef BYTE            *PBYTE;
typedef UINT            *PUINT;
typedef WORD            *PWORD;
typedef ULONG           *PULONG;
typedef DWORD           *PDWORD;
typedef void            *PVOID;

#define DATA            data
#define BDATA           bdata
#define IDATA           idata
#define PDATA           pdata
#define XDATA           xdata
#define CODE            code

/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<BIT DEFINE>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#define _BIT0	0x0001
#define _BIT1	0x0002
#define _BIT2	0x0004
#define _BIT3	0x0008
#define _BIT4	0x0010
#define _BIT5	0x0020
#define _BIT6	0x0040
#define _BIT7	0x0080
#define _BIT8	0x0100
#define _BIT9	0x0200
#define _BIT10	0x0400
#define _BIT11	0x0800
#define _BIT12	0x1000
#define _BIT13	0x2000
#define _BIT14	0x4000
#define _BIT15	0x8000
#define _BIT16	0x10000
#define _BIT17	0x20000
#define _BIT18	0x40000
#define _BIT19	0x80000

#define _bit0_(val)  ((bit)(val & _BIT0))
#define _bit1_(val)  ((bit)(val & _BIT1))
#define _bit2_(val)  ((bit)(val & _BIT2))
#define _bit3_(val)  ((bit)(val & _BIT3))
#define _bit4_(val)  ((bit)(val & _BIT4))
#define _bit5_(val)  ((bit)(val & _BIT5))
#define _bit6_(val)  ((bit)(val & _BIT6))
#define _bit7_(val)  ((bit)(val & _BIT7))
#define _bit8_(val)  ((bit)(val & _BIT8))
#define _bit9_(val)  ((bit)(val & _BIT9))
#define _bit10_(val) ((bit)(val & _BIT10))
#define _bit11_(val) ((bit)(val & _BIT11))
#define _bit12_(val) ((bit)(val & _BIT12))
#define _bit13_(val) ((bit)(val & _BIT13))
#define _bit14_(val) ((bit)(val & _BIT14))
#define _bit15_(val) ((bit)(val & _BIT15))


#define CBYTE ((unsigned char volatile code  *) 0)
#define DBYTE ((unsigned char volatile data  *) 0)
#define PBYTE ((unsigned char volatile pdata *) 0)
#define XBYTE ((unsigned char volatile xdata *) 0)

#define CWORD ((unsigned int volatile code  *) 0)
#define DWORD ((unsigned int volatile data  *) 0)
#define PWORD ((unsigned int volatile pdata *) 0)
#define XWORD ((unsigned int volatile xdata *) 0)


#ifdef __CX51__
#define FVAR(object, addr)   (*((object volatile far *) (addr)))
#define FARRAY(object, base) ((object volatile far *) (base))
#define FCVAR(object, addr)   (*((object const far *) (addr)))
#define FCARRAY(object, base) ((object const far *) (base))
#else
#define FVAR(object, addr)    (*((object volatile far *) ((addr)+0x10000L)))
#define FCVAR(object, addr)   (*((object const far *) ((addr)+0x810000L)))
#define FARRAY(object, base)  ((object volatile far *) ((base)+0x10000L))
#define FCARRAY(object, base) ((object const far *) ((base)+0x810000L))
#endif


#define makeUint16(h,l)     ((((UINT)h)<<12)| l) 
#define getLowe8bit(x)      ((UCHAR)x&0xff)
#define getHigh8bit(x)      ((UCHAR)x>>8)
#define setFlg(dat,flgBit)  (dat|(flgBit))
#define clrFlg(dat,flgBit)  (dat&(~flgBit))
#define readFlg(dat,flgBit) (dat&(flgBit))
#define max(a, b)           (((a) > (b)) ? (a) : (b))
#define min(a ,b)           (((a) < (b)) ? (a) : (b))
#define SetBit(dat,flgBit)  (dat = (dat|(flgBit)))
#define ClrBit(dat,flgBit)  (dat = (dat&(~flgBit)))








/*<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<事件开关>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>*/
#define    OFF      0
#define    ON       1
#define    SAVE     2

#define    ENABLE   1
#define    DISABLE  0

#define    OPEN	    1
#define    CLOSE	0

#define    TRUE     1
#define    FALSE    0

#define    INC      1
#define    DEC      0

#define    OUT      1               
#define    IN       0  

#define    UP       1
#define    DOWN     0 

#define    RIGHT    1
#define    LEFT     0   

#define    MUTE_ON  1
#define    MUTE_OFF 0

#define    V_3V     1
#define    V_0V     0


#endif
