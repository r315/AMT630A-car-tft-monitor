#ifndef _MENUKEY_INTERFACE_H__
#define _MENUKEY_INTERFACE_H__


/*
系统所有的菜单页能够响应的CMD
*/

/*
关机页
*/


/*
开机页
*/


/*
系统页
*/
KeyComdInterface CODE RootMenuItem_KeyComdMap[]=
{ 
//       Conditions              Quickly Comd         Msg                      Source
        {inputPress ,            COMD_RedrawMenu,     MSG_UPK_MENU,            ALL_INPUT_SOURCE},
        {inputPress ,            COMD_SelSource ,     MSG_UPK_SOURCE_SWITCH,   ALL_INPUT_SOURCE},
        {inputPress ,            COMD_SelMode ,       MSG_UPK_MODE,            ALL_INPUT_SOURCE},
        {inputPress ,            COMD_SelSys,   	  MSG_UPK_SYS,  		   ALL_INPUT_SOURCE},
        {inputPress ,            COMD_Power,          MSG_UPK_POWER,           ALL_INPUT_SOURCE},
        {inputPress ,            COMD_DecVolume,      MSG_UPK_VOLUME_DEC,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_IncVolume,      MSG_UPK_VOLUME_INC,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_LEFT,           MSG_UPK_LEFT,            ALL_INPUT_SOURCE},
        {inputPress ,            COMD_RIGHT,          MSG_UPK_RIGHT,           ALL_INPUT_SOURCE},
        {inputPress ,            COMD_SelMuteOnOff,   MSG_UPK_MUTEONOFF,       ALL_INPUT_SOURCE},
        {inputHold|inputPress ,  COMD_Brightness,     MSG_UPK_BRIGHTNESS,      ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_Contrast,       MSG_UPK_CONTRAST,        ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_Saturation,     MSG_UPK_SATURATION,      ALL_INPUT_SOURCE},
};



/*
Logo页
*/


/*
No Signal页
*/


/*
BT Caller页
*/
KeyComdInterface CODE BTCallerMenuItem_KeyComdMap[]=
{ 
//       Conditions         Comd              Msg            Source
        {inputPress ,  COMD_BTCallAnswer,    MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
Source页
*/


/*
Mute页
*/


/*
亮度页
*/
KeyComdInterface CODE BrightnessMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
对比度页
*/
KeyComdInterface CODE ContrastMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
色度页
*/
KeyComdInterface CODE SaturationMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
色调页
*/
KeyComdInterface CODE TintMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
音量页
*/
KeyComdInterface CODE VolumeMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_VOLUME_INC,ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_VOLUME_DEC,ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
显示模式页
*/
KeyComdInterface CODE ModeMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
翻转页
*/
KeyComdInterface CODE SysMenuItem_KeyComdMap[]=
{ 
//       Conditions      Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
语言页
*/
KeyComdInterface CODE LanguageMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
IR页
*/
KeyComdInterface CODE IRABMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
发射频率页
*/
KeyComdInterface CODE RadioFreqMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
复位页
*/
KeyComdInterface CODE ResetMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_SelReset,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_SelReset,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_ShowSource, MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
工厂菜单页
*/
KeyComdInterface CODE FactoryMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd                  Msg                 Source
        {inputHold|inputPress ,  COMD_NextItem,        MSG_UPK_RIGHT,          ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_PrevItem,        MSG_UPK_LEFT,           ALL_INPUT_SOURCE},
        {inputPress ,            COMD_ExitFactoryMenu, MSG_UPK_MENU,           ALL_INPUT_SOURCE},
        {inputPress,   			 COMD_EnterFactoryItem,MSG_UPK_MODE,           ALL_INPUT_SOURCE},
        {inputPress,             COMD_Nothing,         MSG_UPK_SOURCE_SWITCH,  ALL_INPUT_SOURCE},
        {inputPress,             COMD_Nothing,         MSG_UPK_POWER,          ALL_INPUT_SOURCE},
};

/*
工厂菜单Pic页
*/
KeyComdInterface CODE FactoryPicMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd                  Msg                 Source
        {inputHold|inputPress ,  COMD_IncValue,       MSG_UPK_RIGHT,          ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,       MSG_UPK_LEFT,           ALL_INPUT_SOURCE},
        {inputPress ,            COMD_RedrawFactoryMenu,MSG_UPK_MENU,           ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_PrevItem,       MSG_UPK_SOURCE_SWITCH,  ALL_INPUT_SOURCE},
        {inputPress,             COMD_Nothing,          MSG_UPK_POWER,          ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_NextItem,       MSG_UPK_MODE,           ALL_INPUT_SOURCE},
};


/*
工厂菜单Switch页
*/
KeyComdInterface CODE FactorySwitchMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd                  Msg                 Source
        {inputHold|inputPress ,  COMD_IncValue,         MSG_UPK_RIGHT,          ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,         MSG_UPK_LEFT,           ALL_INPUT_SOURCE},
        {inputPress ,            COMD_RedrawFactoryMenu,MSG_UPK_MENU,           ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_PrevItem,         MSG_UPK_SOURCE_SWITCH,  ALL_INPUT_SOURCE},
        {inputPress,             COMD_Nothing,          MSG_UPK_POWER,          ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_NextItem,         MSG_UPK_MODE,           ALL_INPUT_SOURCE},
};
#endif


