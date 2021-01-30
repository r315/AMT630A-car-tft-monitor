/********************************************
[PannelName]
SAT070AT50DHY0
[PannelType]
D_RGB888
[PannelResolution]
 800
 480
1056
 525
  20
  10
  46
  23
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
  -1
Update date:Friday, February 06, 2015
Update time:15:02:53
History:







 * Jordan.chen/2014.10.22-19:56/建立AMT630A 标准屏参V1.0



































********************************************/

typedef struct _PanlstaticPara
{
    unsigned int addr;
    unsigned char dat;
}PanlstaticPara;

typedef struct _PanlPosDynPara
{
    unsigned int addr;
    unsigned char dat_posDyn[6];
}PanlPosDynPara;

typedef struct _PanlSysDynPara
{
    unsigned int addr;
    unsigned char dat_sysDyn[8];
}PanlSysDynPara;



/*==============start===============*/
/*AV1
[VideoChannel]
AV1
[VideoType]
CVBS
[VideoPI]
VIDEO_P
[VideoPicSys]
PAL
[VideoData]
13500000
 690
 280
 864
 312

Update date:Friday, February 06, 2015
Update time:15:02:53
*/
PanlstaticPara code AV1_staticPara[]=
{
//GLOBAL
    {0XFD0A,0XA4}, 
    {0XFD0B,0X40}, 
    {0XFD0D,0XE0}, 
    {0XFD0F,0X09}, 
    {0XFD10,0X04}, 
    {0XFD14,0X01}, 
    {0XFD15,0X04}, 
    {0XFD16,0X0A}, 
    {0XFD1A,0X04}, 
//DECODER
    {0XFE83,0X7F}, 
//VP
    {0XFFB0,0X27}, 
    {0XFFB1,0X0F}, 
    {0XFFB2,0X10}, 
    {0XFFB3,0X10}, 
    {0XFFB4,0X10}, 
    {0XFFF0,0X1A}, 
    {0XFFF1,0XE9}, 
    {0XFFF2,0XFD}, 
    {0XFFF3,0XF5}, 
    {0XFFF4,0XFD}, 
    {0XFFF5,0X0E}, 
    {0XFFF6,0XFD}, 
    {0XFFF7,0XF5}, 
    {0XFFF8,0XE9}, 
    {0XFFF9,0XFD}, 
    {0XFFFA,0X23}, 
    {0XFFFB,0X81}, 
//TCON
    {0XFC00,0X00}, 
//SCALE
    {0XFC90,0XC2}, 
    {0XFC91,0X01}, 
    {0XFC92,0X04}, 
    {0XFC93,0X00}, 
    {0XFC98,0XE9}, 
    {0XFC99,0X01}, 
    {0XFC9A,0XA1}, 
    {0XFC9B,0X03}, 
    {0XFC9C,0X03}, 
    {0XFC9D,0X00}, 
    {0XFC9E,0X06}, 
    {0XFC9F,0X00}, 
    {0XFCA0,0X5B}, 
    {0XFCA1,0X00}, 
    {0XFCA2,0X7F}, 
    {0XFCA3,0X03}, 
    {0XFCA4,0X06}, 
    {0XFCA5,0X00}, 
    {0XFCA6,0X0B}, 
    {0XFCA7,0X00}, 
    {0XFCA8,0X21}, 
    {0XFCA9,0X00}, 
    {0XFCAA,0X01}, 
    {0XFCAB,0X02}, 
    {0XFCB7,0X28}, 
    {0XFCB8,0X02}, 
    {0XFCBB,0X20}, 
    {0XFCBC,0X02}, 
    {0XFCBD,0X01}, 
    {0XFCBE,0X00}, 
    {0XFCBF,0X00}, 
    {0XFCC4,0X4E}, 
    {0XFCC5,0X02}, 
    {0XFCC6,0X69}, 
    {0XFCC7,0X04}, 
    {0XFCC8,0X02}, 
    {0XFCC9,0X00}, 
    {0XFCCA,0X06}, 
    {0XFCCB,0X00}, 
    {0XFCCC,0X54}, 
    {0XFCCD,0X00}, 
    {0XFCCE,0X7A}, 
    {0XFCCF,0X03}, 
    {0XFCD1,0X00}, 
    {0XFCD2,0X0A}, 
    {0XFCD3,0X00}, 
    {0XFCD4,0X21}, 
    {0XFCD5,0X00}, 
    {0XFCD6,0X01}, 
    {0XFCD7,0X02}, 
    {0XFCD0,0X02}, 
//GAMMA
    {0XFF00,0X03}, 
    {0XFF01,0X03}, 
    {0XFF02,0X07}, 
    {0XFF03,0X0C}, 
    {0XFF04,0X11}, 
    {0XFF05,0X18}, 
    {0XFF06,0X20}, 
    {0XFF07,0X29}, 
    {0XFF08,0X33}, 
    {0XFF09,0X3D}, 
    {0XFF0A,0X47}, 
    {0XFF0B,0X52}, 
    {0XFF0C,0X5D}, 
    {0XFF0D,0X69}, 
    {0XFF0E,0X75}, 
    {0XFF0F,0X81}, 
    {0XFF10,0X8D}, 
    {0XFF11,0X9A}, 
    {0XFF12,0XA6}, 
    {0XFF13,0XB2}, 
    {0XFF14,0XBD}, 
    {0XFF15,0XC8}, 
    {0XFF16,0XD1}, 
    {0XFF17,0XDA}, 
    {0XFF18,0XE2}, 
    {0XFF19,0XE8}, 
    {0XFF1A,0XEE}, 
    {0XFF1B,0XF2}, 
    {0XFF1C,0XF5}, 
    {0XFF1D,0XF8}, 
    {0XFF1E,0XFB}, 
    {0XFF1F,0XFD}, 
    {0XFF20,0X03}, 
    {0XFF21,0X07}, 
    {0XFF22,0X0C}, 
    {0XFF23,0X11}, 
    {0XFF24,0X18}, 
    {0XFF25,0X20}, 
    {0XFF26,0X29}, 
    {0XFF27,0X33}, 
    {0XFF28,0X3D}, 
    {0XFF29,0X47}, 
    {0XFF2A,0X52}, 
    {0XFF2B,0X5D}, 
    {0XFF2C,0X69}, 
    {0XFF2D,0X75}, 
    {0XFF2E,0X81}, 
    {0XFF2F,0X8D}, 
    {0XFF30,0X9A}, 
    {0XFF31,0XA6}, 
    {0XFF32,0XB2}, 
    {0XFF33,0XBD}, 
    {0XFF34,0XC8}, 
    {0XFF35,0XD1}, 
    {0XFF36,0XDA}, 
    {0XFF37,0XE2}, 
    {0XFF38,0XE8}, 
    {0XFF39,0XEE}, 
    {0XFF3A,0XF2}, 
    {0XFF3B,0XF5}, 
    {0XFF3C,0XF8}, 
    {0XFF3D,0XFB}, 
    {0XFF3E,0XFD}, 
    {0XFF3F,0X03}, 
    {0XFF40,0X07}, 
    {0XFF41,0X0C}, 
    {0XFF42,0X11}, 
    {0XFF43,0X18}, 
    {0XFF44,0X20}, 
    {0XFF45,0X29}, 
    {0XFF46,0X33}, 
    {0XFF47,0X3D}, 
    {0XFF48,0X47}, 
    {0XFF49,0X52}, 
    {0XFF4A,0X5D}, 
    {0XFF4B,0X69}, 
    {0XFF4C,0X75}, 
    {0XFF4D,0X81}, 
    {0XFF4E,0X8D}, 
    {0XFF4F,0X9A}, 
    {0XFF50,0XA6}, 
    {0XFF51,0XB2}, 
    {0XFF52,0XBD}, 
    {0XFF53,0XC8}, 
    {0XFF54,0XD1}, 
    {0XFF55,0XDA}, 
    {0XFF56,0XE2}, 
    {0XFF57,0XE8}, 
    {0XFF58,0XEE}, 
    {0XFF59,0XF2}, 
    {0XFF5A,0XF5}, 
    {0XFF5B,0XF8}, 
    {0XFF5C,0XFB}, 
    {0XFF5D,0XFD}, 
};
PanlPosDynPara code AV1_posDynPara[]=
{
//dispmode:  16:9  4:3  DM_EX0  DM_EX1  DM_EX2  DM_EX3
//GLOBAL
//PAD MUX
//PWM
//GPIO
//DECODER
//VP
//TCON
//SCALE
    {0XFC96,{0X70,0XA5,0X70,0X70,0X70,0X70}},
    {0XFC97,{0X03,0X04,0X03,0X03,0X03,0X03}},
    {0XFCAC,{0X1D,0X1D,0X00,0X00,0X00,0X00}},
    {0XFCAD,{0X00,0X69,0X00,0X00,0X00,0X00}},
    {0XFCAE,{0X00,0X6E,0X00,0X00,0X00,0X00}},
    {0XFCAF,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCB0,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCC2,{0X7A,0XA7,0X67,0X67,0X67,0X67}},
    {0XFCC3,{0X03,0X04,0X03,0X03,0X03,0X03}},
    {0XFCD8,{0X08,0X0C,0X00,0X00,0X00,0X00}},
    {0XFCD9,{0X02,0X67,0X00,0X00,0X00,0X00}},
    {0XFCDA,{0X00,0X6D,0X00,0X00,0X00,0X00}},
    {0XFCDB,{0X00,0X00,0X00,0X00,0X00,0X00}},
    {0XFCDC,{0X00,0X00,0X00,0X00,0X00,0X00}},
//GAMMA
};
PanlSysDynPara code AV1_sysDynPara[]=
{
//picSys:   PAL  PAL-N  PAL-M  NTSC SECAM PAL-60 NTSC-J NTSC-4.43
//GLOBAL
//PAD MUX
//PWM
//GPIO
//DECODER
//VP
    {0XFFD3,{0X80, 0X80, 0X80, 0X80, 0X80, 0X80, 0X80, 0X80}},
    {0XFFD4,{0X80, 0X8C, 0X8C, 0X8C, 0X8C, 0X8C, 0X8C, 0X8C}},
    {0XFFD5,{0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00}},
    {0XFFD6,{0X3E, 0X36, 0X36, 0X36, 0X36, 0X36, 0X36, 0X36}},
//TCON
//SCALE
//GAMMA
};
/*============== end ===============*/



/*点屏 PAD MUX 参数*/
PanlstaticPara code AMT_PadMuxStaticPara[]=
{
//PAD MUX
    {0XFD32,0X11}, 
    {0XFD33,0X11}, 
    {0XFD34,0X11}, 
    {0XFD35,0X11}, 
    {0XFD36,0X11}, 
    {0XFD37,0X11}, 
    {0XFD38,0X11}, 
    {0XFD39,0X11}, 
    {0XFD3A,0X11}, 
    {0XFD3B,0X11}, 
    {0XFD3C,0X11}, 
    {0XFD3D,0X11}, 
    {0XFD3E,0X11}, 
    {0XFD3F,0X11}, 
    {0XFD40,0X11}, 
    {0XFD41,0X11}, 
    {0XFD44,0X01}, 
    {0XFD45,0X00}, 
    {0XFD46,0X00}, 
    {0XFD47,0X00}, 
    {0XFD48,0X00}, 
    {0XFD49,0X00}, 
    {0XFD4A,0X00}, 
    {0XFD4B,0X00}, 
    {0XFD50,0X0F}, 
};



/*屏参参数相关的结构体*/
typedef struct _PannelPara
{
   PanlstaticPara  *pVideoStaicPara;
   PanlPosDynPara *pVideoPosDynPara;
   PanlSysDynPara  *pVideoSysDynPara;
}PannelPara;
typedef struct _VideoChannel
{
   unsigned char INPUT_ID;
   PannelPara    VideoPara;
}VideoChannel;
/*不同通道屏参的定义、初始化*/
VideoChannel code VideoChannelPara[]=
{
{ INPUT_AV1,{AV1_staticPara,AV1_posDynPara,AV1_sysDynPara}},
};
#define STATIC_NUM 173
#define POS_DYN_NUM 14
#define SYS_DYN_NUM 4
#define PAD_MUX_NUM 25
#define VCOM_AC_Def 0X00
#define VCOM_DC_Def 0X00
#define PWMA_VAL 0X0000
#define PWMB_VAL 0X0000


