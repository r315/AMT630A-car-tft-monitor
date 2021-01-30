/*
此文件主要对ARK的一些视频处理函数进行声明。
*/
#ifndef _VIDEO_CHIP_H__
#define _VIDEO_CHIP_H__

#ifdef _VIDEO_CHIP_C_
  #define _VIDEO_EXTERN_   
#else
  #define _VIDEO_EXTERN_ extern
#endif


_VIDEO_EXTERN_ void InitARKChip(void);
_VIDEO_EXTERN_ void SelVideoInputSource(InputSourceType curSource);
_VIDEO_EXTERN_ void ConfigVideoInputSource(InputSourceType curSource);
_VIDEO_EXTERN_ BOOL CheckColorSys(void);
_VIDEO_EXTERN_ UCHAR SelNextVideoSource(UCHAR curSource);
#endif