#ifndef AMT630A_VIDEO_LIB_INTERFACE_H__
#define  AMT630A_VIDEO_LIB_INTERFACE_H__


extern UCHAR DetectSignalSys(InputSourceType curSource);
extern char* GetLibCreatTime(void);
extern char* GetLibCreatDate(void);
extern char* GeLibVersion(void);
extern void POS_VideoProcess(UCHAR SpecialRegCtrlEn); 
extern void InitYCDVD(void);
extern void InitITU656(void);
extern void InitCVBSDVD(void);
extern void InitCVBSDoorbellCamera(void);
extern void InitCVBSCarCamera(void);
extern void InitDigitalPanl(void);
extern void InitATCONPanl(void);
extern void InitAMT(void);
extern void InitPannel_RGB_7D_800x480(void);


#endif
