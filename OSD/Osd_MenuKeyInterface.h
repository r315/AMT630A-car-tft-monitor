#ifndef _MENUKEY_INTERFACE_H__
#define _MENUKEY_INTERFACE_H__


/*
ϵͳ���еĲ˵�ҳ�ܹ���Ӧ��CMD
*/

/*
�ػ�ҳ
*/


/*
����ҳ
*/


/*
ϵͳҳ
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
Logoҳ
*/


/*
No Signalҳ
*/


/*
BT Callerҳ
*/
KeyComdInterface CODE BTCallerMenuItem_KeyComdMap[]=
{ 
//       Conditions         Comd              Msg            Source
        {inputPress ,  COMD_BTCallAnswer,    MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
Sourceҳ
*/


/*
Muteҳ
*/


/*
����ҳ
*/
KeyComdInterface CODE BrightnessMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
�Աȶ�ҳ
*/
KeyComdInterface CODE ContrastMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
ɫ��ҳ
*/
KeyComdInterface CODE SaturationMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
ɫ��ҳ
*/
KeyComdInterface CODE TintMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
����ҳ
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
��ʾģʽҳ
*/
KeyComdInterface CODE ModeMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
��תҳ
*/
KeyComdInterface CODE SysMenuItem_KeyComdMap[]=
{ 
//       Conditions      Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
����ҳ
*/
KeyComdInterface CODE LanguageMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
IRҳ
*/
KeyComdInterface CODE IRABMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
����Ƶ��ҳ
*/
KeyComdInterface CODE RadioFreqMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputPress ,  COMD_IncValue,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputPress,   COMD_DecValue,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,  COMD_NextMenu,   MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};


/*
��λҳ
*/
KeyComdInterface CODE ResetMenuItem_KeyComdMap[]=
{ 
//       Conditions                  Comd              Msg            Source
        {inputHold|inputPress ,  COMD_SelReset,   MSG_UPK_RIGHT,     ALL_INPUT_SOURCE},
        {inputHold|inputPress,   COMD_SelReset,   MSG_UPK_LEFT,      ALL_INPUT_SOURCE},
        {inputPress ,            COMD_ShowSource, MSG_UPK_MENU,      ALL_INPUT_SOURCE},
};



/*
�����˵�ҳ
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
�����˵�Picҳ
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
�����˵�Switchҳ
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


