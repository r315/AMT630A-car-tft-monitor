/*
  OSD的主头文件。
*/
#ifndef _OSD_MENU_H__
#define _OSD_MENU_H__

#ifdef _OSD_MENU_C
#define _OSD_MENU_EXTERN_ 
#else
#define _OSD_MENU_EXTERN_  extern
#endif


#define FONT_RAM_INDEX_STAR_ADDR 0X2E0
#define ICONBITMAP_SATRT_INDEX   40
#define LOGOBITMAP_SATRT_INDEX   0


typedef enum 
{
	ENGLISH  = 0,         
	FRENCH,   
	ITALIAN,   
	SPANISH,	
	GERMAN,      
	PUTOYA,
	DUTCH, 		 
	RUSSIAN, 
	CHINESE,    
	JAPANESE,  
	BULGARIAN,	//保加利亚语
	POLISH,	  //波兰语
	TURK,    //土耳其语
	
	MIN_LAG = ENGLISH,
	MAX_LANG = JAPANESE,
}MultLanguageType;

typedef enum
{
	TRANSPARENCE = 0,             
	RED,          
	GREEN,          
	CYAN ,         
	YELLOW ,            
	GRAY ,  
	WHITE,     
	BLACK,
	MAX_COLOR = -1,
} ColorType;

typedef enum
{ 
	Osd_PowerOffMenu=0, 
	Osd_PowerOnMenu,	
	Osd_RootMenu, 
	
	/*一下是用户自定义菜单*/
	Osd_LOGO1Menu,
    Osd_LOGO2Menu,
    Osd_LOGO3Menu,
    Osd_LOGO4Menu,
    Osd_LOGO5Menu,
    
    Osd_BatteryAdcMenu,
    Osd_NoSignalMenu,
    Osd_BTMenu,
    Osd_BTCallerMenu,
	Osd_QuicklySource,
	Osd_QuicklyMute,
	Osd_QuicklyVolume,
    Osd_QuicklyMode,
    Osd_QuicklySys,
    
    Osd_QuicklyBrightness,
    Osd_QuicklyContrast,
    Osd_QuicklySaturation,
    
    Osd_BrightnessMenu,
    Osd_ContrastMenu,
    Osd_SaturationMenu,
    Osd_TintMenu,
    Osd_VolumeMenu,
    Osd_ModeMenu,
    Osd_SysMenu, 
    Osd_LanguageMenu, 
    Osd_IRABMenu, 
    Osd_RadioFreqMenu, 
    Osd_ResetMenu,

    Osd_FactoryMenu,
    Osd_FactoryPicMenu,
    Osd_FactorySwitchMenu,
	Osd_MaxMenu
} MenuPageIndexType;

typedef enum
{
    OsdBlock0,
   	OsdBlock1,
   	OsdBlock2,
   	OsdBlock3,
   	OsdBlock4,
}OsdBlockType;




typedef enum  _CommandType
{ 
  COMD_Nothing,

  COMD_NextMenu,	
  COMD_PrevMenu, 
  COMD_PrevItem,
  COMD_NextItem,
  COMD_FactoryPreItem,
  COMD_FactoryNextItem,
  COMD_EnterFactoryItem,
  
  COMD_OsdExit, 
  COMD_OsdStorage,
  COMD_IncValue, 
  COMD_DecValue,
  COMD_LEFT,
  COMD_RIGHT,

  COMD_ExecFunc,
  COMD_InvIncValue,
  COMD_InvDecValue,
  COMD_RedrawMenu,
  COMD_RedrawFactoryMenu,
  COMD_SelReset,
  COMD_SelSource,
  COMD_ShowSource,
  COMD_SelPowerOnMode,
  COMD_Power, 
  COMD_TurnOffBacklight,
  COMD_TurnOnBacklight,
  COMD_SelMuteOnOff,
  COMD_ShowMuteOnOff,
  COMD_SelMode,
  COMD_Mode,
  COMD_SelSys,
  COMD_Sys,
  COMD_Brightness,
  COMD_Contrast,
  COMD_Saturation,
  COMD_IncVolume,
  COMD_DecVolume,
  COMD_FactoryMenu,
  COMD_ExitFactoryMenu,
  COMD_ClearNoSignal,
  COMD_RedrawLogo,
  COMD_ClearLogo,
  COMD_RedrawSnow,
  COMD_BatteryAdc,
  COMD_BTConn,
  COMD_BTDisc,
  COMD_BTCallerID,
  COMD_BTCallAnswer,
  COMD_BTCallerDrop,
} ComdType;

#define osdInvisible    _BIT0
#define osdVisible      _BIT1
#define osdRedraw       _BIT2
#define osdEnd 		    _BIT3
#define osdDecNum       _BIT4
#define osdHexNum       _BIT5
#define osdSel          _BIT6
#define osdDraw         _BIT7


typedef struct
{
    UCHAR Flags; 
	CHAR XPos,YPos; 
}AdjustType;

typedef UCHAR* (*fpDisplayText)(void);
typedef BOOL (*fpExecFunc)(void);
typedef BYTE (*fpItemIndex)(void);
typedef BOOL (*fpAdjustValue)(ComdType opratComd);
typedef SINT (*fpGetValue)(void);
typedef UINT (*fpGetMaxValue)(void);
typedef UINT (*fpSetMaxValue)(void);
typedef UINT* (*fpDisplayIcon)(void);
typedef AdjustType (*fpCheckCondition)(void);
typedef BOOL (*fpDrawStyle)(void);



typedef enum
{ 
	DWT_Nothing,
	DWT_Text,
	DWT_FullText,
	DWT_CenterText,
	DWT_FullCenterText,
	DWT_None
} DrawTitelType;


typedef struct
{
    UCHAR       cConditions;           
    ComdType    Comd;     
    MSG         Msg;
    UCHAR       Source;
} KeyComdInterface;



typedef struct
{ 
	UCHAR XPos, YPos;
	UCHAR ForeColor, BackColor;
	UCHAR SelForeColor, SelBackColor;
	fpGetValue GetValue;   
	UINT  Flags;	
} DrawNumberType;

typedef struct
{ 	
	UCHAR XPos, YPos;
	UCHAR ForeColor, BackColor;
	UCHAR SelForeColor, SelBackColor;
	UCHAR Length;
	fpGetValue GetValue;
	UINT  Flags;	
} DrawGuageType;


typedef struct
{ 	
	UCHAR XPos, YPos;
	UCHAR ForeColor, BackColor;
	UCHAR SelForeColor, SelBackColor;
	fpGetValue GetValue;
	fpDisplayText DisplayText;    
	UINT  Flags;	
} DrawOptionType;

typedef struct
{ 
	DrawNumberType* DrawNumber;
	DrawGuageType*  DrawGuage;
	DrawOptionType* DrawOption;	
	UINT  Flags;
} ItemValueType;

typedef struct
{
	UCHAR  XPos , YPos;
	UCHAR  ForeColor, BackColor;
	UCHAR  SelForeColor, SelBackColor;
	DrawTitelType DrawTitelMethod;
	fpDisplayText  DisplayText; 
    UINT  Flags;
}TitelType;


typedef struct
{
	UCHAR  XPos , YPos;
	UCHAR  XSize, YSize;
	UCHAR  BackColor;
	UCHAR  SelBackColor;
	fpDisplayIcon  DispalyIcon; 
	UINT   Flags;
}IconType;

typedef struct
{
	CHAR* ItemName;
    UCHAR XPos , YPos;
	
	fpCheckCondition CheckCondition;  //检查条件,并返回相应校正系数。
	fpDrawStyle    DrawItemStyle;     //条目风格
	IconType*      ItemIcons;	      //条目图标
	TitelType*     ItemTitels;         //条目标题
	ItemValueType* ItemValue;         //条目的值(数字，进度条，选项)
	
	fpAdjustValue AdjustFunction;
	fpExecFunc    ExecFunction;
	
	KeyComdInterface* KeyComdMap;	
	UCHAR  ComdCount;
	
	UINT  Flags;
} MenuItemType;

typedef struct
{ 
    CHAR* MenuName;
    UINT  XPos , YPos;
	UCHAR  XSize, YSize;
	UCHAR  ForeColor, BackColor;
	UCHAR  OsdBlockId;
	
	UCHAR  PrevPage;
	UCHAR  CurrentPage;
	UCHAR  NextPage;

	
	
    fpCheckCondition CheckCondition;  //检查条件,并返回相应校正系数。
	fpDrawStyle   DrawMenuStyle;      //菜单个性风格
	IconType*     MenuIcons;          //菜单图标
	TitelType*    MenuTitels;         //菜单标题
	MenuItemType* MenuItems;          //菜单条目
	UCHAR ItemCount;
	
	fpExecFunc   ExecFunction;        //菜单执行函数,对底层的驱动。 
   	
	UINT   TimeOut;
	UINT  Flags;
} MenuPageType;

_OSD_MENU_EXTERN_ BYTE XDATA g_ucMenuPageIndex;
_OSD_MENU_EXTERN_ BYTE XDATA g_ucMenuItemIndex;
_OSD_MENU_EXTERN_ BYTE XDATA g_ucFactoryMenuItemIndex;

_OSD_MENU_EXTERN_ UCHAR KeyMsgProcess(MSG curMsg);
_OSD_MENU_EXTERN_ void  MenuProcessKey(BYTE OpratComd);

//===============================================================
_OSD_MENU_EXTERN_ void  DrawOsdMenu(void);
_OSD_MENU_EXTERN_ void  DrawSpecialOsdMenu(void);
_OSD_MENU_EXTERN_ void  DrawOsdMenuItemValue(ItemValueType* pItemValue,UINT status);
_OSD_MENU_EXTERN_ UCHAR GetPrevItem(void);
_OSD_MENU_EXTERN_ UCHAR GetNextItem(void);
_OSD_MENU_EXTERN_ UCHAR GetPreMenu(void);
_OSD_MENU_EXTERN_ UCHAR GetNextMenu(void);
_OSD_MENU_EXTERN_ void  DrawOsdMenuItem(MenuItemType *pMenuItem,UINT status) reentrant;
_OSD_MENU_EXTERN_ void DrawOsdTitel(TitelType *pTitel,UINT status)reentrant;
_OSD_MENU_EXTERN_ void DrawOsdMenuItemOption(DrawOptionType *pOptionItem,UINT status);
_OSD_MENU_EXTERN_ UCHAR FindMenuPageIndex(UCHAR menuPage);
_OSD_MENU_EXTERN_ void  ConfigOsdBlockStarIndexAddr(void);
_OSD_MENU_EXTERN_ UCHAR FindComdInCurMenuItem(MSG curMsg);
_OSD_MENU_EXTERN_ void HideMenu(void);
_OSD_MENU_EXTERN_ void ResetMenuIndex(void);
_OSD_MENU_EXTERN_ void SetMenuIndex(UCHAR menuPage);
_OSD_MENU_EXTERN_ BOOL ExectComd(ComdType OpratComd);

#endif
