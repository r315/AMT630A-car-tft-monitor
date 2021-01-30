#ifndef _MENU_PAGE_H__
#define _MENU_PAGE_H__


/*
系统所有的菜单页及相关的资源
*/
#define _MENU_PAGE_ extern


/*
常用字符
*/
_MENU_PAGE_ UCHAR CODE AMT630FontLib[];
_MENU_PAGE_ UCHAR CODE AMT630Font_Char[];
_MENU_PAGE_ UCHAR CODE FontRam_Char[];


/*
关机页
*/
_MENU_PAGE_ MenuPageType CODE PowerOffMenu;


/*
开机页
*/
_MENU_PAGE_ MenuPageType CODE PowerOnMenu;
_MENU_PAGE_ ItemValueType CODE PowerOnMenuItemVal_PowerOn[];
_MENU_PAGE_ AdjustType PowerOnMenu_CheckCondition (void);



/*
系统页
*/
_MENU_PAGE_ MenuPageType CODE RootMenu;




/*
Logo页
*/
_MENU_PAGE_ void InitLogoMenuDat(void);
_MENU_PAGE_ AdjustType LogoMenu_CheckCondition (void);



/*BatteryAdc页
*/
_MENU_PAGE_ ItemValueType CODE BatteryAdcMenuItemVal_BatteryAdc[];
_MENU_PAGE_ MenuPageType CODE BatteryAdcMenu;
_MENU_PAGE_ AdjustType BatteryAdcMenu_CheckCondition (void);
_MENU_PAGE_ BOOL AdjustBatteryAdc(UCHAR opratComd);


/*
No Signal页
*/
_MENU_PAGE_ MenuPageType CODE NoSignalMenu;
_MENU_PAGE_ TitelType CODE NoSignalMenuItem_NoSignalTitelTab[];
_MENU_PAGE_ AdjustType NoSignalMenu_CheckCondition (void);



/*
BT页
*/
_MENU_PAGE_ MenuPageType CODE BTMenu;
_MENU_PAGE_ TitelType CODE BTMenuItem_BTTitelTab[];
_MENU_PAGE_ AdjustType BTMenu_CheckCondition (void);



/*
BT Caller页
*/
_MENU_PAGE_ MenuPageType CODE BTCallerMenu;
_MENU_PAGE_ TitelType CODE BTCallerMenuItem_BTCallerTitelTab[];
_MENU_PAGE_ AdjustType BTCallerMenu_CheckCondition (void);
_MENU_PAGE_ BOOL BTCallerMenuItem_DrawStyle(void);



/*
Source页
*/
_MENU_PAGE_ ItemValueType CODE QuicklySourceMenuItemVal_QuicklySource[];
_MENU_PAGE_ MenuPageType CODE  QuicklySourceMenu;
_MENU_PAGE_ AdjustType QuicklySourceMenu_CheckCondition (void);
_MENU_PAGE_ BOOL AdjustQuicklySource(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectQuicklySource(void);



/*
Mute页
*/
_MENU_PAGE_ MenuPageType CODE QuicklyMuteMenu;
_MENU_PAGE_ ItemValueType CODE QuicklyMuteMenuItemVal_QuicklyMute[];
_MENU_PAGE_ BOOL AdjustQuicklyMute(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectQuicklyMute(void);
_MENU_PAGE_ AdjustType QuicklyMuteMenu_CheckCondition (void);



/*
亮度页
*/
_MENU_PAGE_ TitelType CODE BrightnessMenuItem_BrightnessTitelTab[];
_MENU_PAGE_ TitelType CODE QuicklyBrightnessMenuItem_QuicklyBrightnessTitelTab[];
_MENU_PAGE_ ItemValueType CODE BrightnessMenuItemVal_Brightness[];
_MENU_PAGE_ ItemValueType CODE QuicklyBrightnessMenuItemVal_QuicklyBrightness[];
_MENU_PAGE_ MenuPageType CODE BrightnessMenu;
_MENU_PAGE_ MenuPageType CODE QuicklyBrightnessMenu;
_MENU_PAGE_ AdjustType BrightnessMenu_CheckCondition (void);
_MENU_PAGE_ AdjustType QuicklyBrightnessMenu_CheckCondition (void);
_MENU_PAGE_ BOOL BrightnessMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL QuicklyBrightnessMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustBrightness(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustQuicklyBrightness(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectBrightness(void);
_MENU_PAGE_ BOOL ExectQuicklyBrightness(void);



/*
对比度页
*/
_MENU_PAGE_ TitelType CODE ContrastMenuItem_ContrastTitelTab[];
_MENU_PAGE_ TitelType CODE QuicklyContrastMenuItem_QuicklyContrastTitelTab[];
_MENU_PAGE_ ItemValueType CODE ContrastMenuItemVal_Contrast[];
_MENU_PAGE_ ItemValueType CODE QuicklyContrastMenuItemVal_QuicklyContrast[];
_MENU_PAGE_ MenuPageType CODE ContrastMenu;
_MENU_PAGE_ MenuPageType CODE QuicklyContrastMenu;

_MENU_PAGE_ AdjustType ContrastMenu_CheckCondition(void);
_MENU_PAGE_ AdjustType QuicklyContrastMenu_CheckCondition(void);
_MENU_PAGE_ BOOL ContrastMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL QuicklyContrastMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustContrast(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustQuicklyContrast(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectContrast(void);
_MENU_PAGE_ BOOL ExectQuicklyContrast(void);



/*
色度页
*/
_MENU_PAGE_ TitelType CODE SaturationMenuItem_SaturationTitelTab[];
_MENU_PAGE_ TitelType CODE QuicklySaturationMenuItem_QuicklySaturationTitelTab[];
_MENU_PAGE_ ItemValueType CODE SaturationMenuItemVal_Saturation[];
_MENU_PAGE_ ItemValueType CODE QuicklySaturationMenuItemVal_QuicklySaturation[];
_MENU_PAGE_ MenuPageType CODE SaturationMenu;
_MENU_PAGE_ MenuPageType CODE QuicklySaturationMenu;

_MENU_PAGE_ AdjustType SaturationMenu_CheckCondition(void);
_MENU_PAGE_ AdjustType QuicklySaturationMenu_CheckCondition(void);
_MENU_PAGE_ BOOL SaturationMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL QuicklySaturationMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustSaturation(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustQuicklySaturation(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectSaturation(void);
_MENU_PAGE_ BOOL ExectQuicklySaturation(void);



/*
色调页
*/
_MENU_PAGE_ TitelType CODE TintMenuItem_TintTitelTab[];
_MENU_PAGE_ ItemValueType CODE TintMenuItemVal_Tint[];
_MENU_PAGE_ MenuPageType CODE TintMenu;
_MENU_PAGE_ AdjustType TintMenu_CheckCondition(void);
_MENU_PAGE_ BOOL TintMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustTint(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectTint(void);




/*
音量页
*/
_MENU_PAGE_ MenuPageType CODE VolumeMenu;
_MENU_PAGE_ TitelType CODE VolumeMenuItem_VolumeTitelTab[];
_MENU_PAGE_ ItemValueType CODE VolumeMenuItemVal_Volume[];
_MENU_PAGE_ AdjustType VolumeMenu_CheckCondition(void);
_MENU_PAGE_ BOOL VolumeMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustVolume(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectVolume(void);



/*
显示模式页
*/
_MENU_PAGE_ TitelType CODE ModeMenuItem_ModeTitelTab[];
_MENU_PAGE_ ItemValueType CODE ModeMenuItemVal_Mode[];
_MENU_PAGE_ MenuPageType CODE ModeMenu;
_MENU_PAGE_ AdjustType ModeMenu_CheckCondition(void);
_MENU_PAGE_ BOOL ModeMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustMode(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectMode(void);



/*
翻转页
*/
_MENU_PAGE_ TitelType CODE SysMenuItem_SysTitelTab[];
_MENU_PAGE_ ItemValueType CODE SysMenuItemVal_Sys[];
_MENU_PAGE_ MenuPageType CODE SysMenu;
_MENU_PAGE_ AdjustType SysMenu_CheckCondition(void);
_MENU_PAGE_ BOOL SysMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustSys(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectSys(void);



/*
语言页
*/
_MENU_PAGE_ TitelType CODE LanguageMenuItem_LanguageTitelTab[];
_MENU_PAGE_ MenuPageType CODE LanguageMenu;
_MENU_PAGE_ AdjustType LanguageMenu_CheckCondition(void);
_MENU_PAGE_ BOOL LanguageMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustLanguage(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectLanguage(void);



/*
IR页
*/
_MENU_PAGE_ TitelType CODE IRABMenuItem_IRABTitelTab[];
_MENU_PAGE_ ItemValueType CODE IRABMenuItemVal_IRAB[];
_MENU_PAGE_ MenuPageType CODE IRABMenu;
_MENU_PAGE_ AdjustType IRABMenu_CheckCondition(void);
_MENU_PAGE_ BOOL IRABMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustIRAB(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectIRAB(void);



/*
发射频率页
*/
_MENU_PAGE_ TitelType CODE  RadioFreqMenuItem_RadioFreqTitelTab[];
_MENU_PAGE_ ItemValueType CODE RadioFreqMenuItemVal_RadioFreq[];
_MENU_PAGE_ MenuPageType CODE RadioFreqMenu;
_MENU_PAGE_ AdjustType RadioFreqMenu_CheckCondition(void);
_MENU_PAGE_ BOOL RadioFreqMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL AdjustRadioFreq(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectRadioFreq(void);



/*
复位页
*/
_MENU_PAGE_ TitelType CODE ResetMenuItem_LanguageTitelTab[];
_MENU_PAGE_ ItemValueType CODE ResetMenuItemVal_Reset[];
_MENU_PAGE_ MenuPageType CODE ResetMenu;
_MENU_PAGE_ AdjustType ResetMenu_CheckCondition(void);
_MENU_PAGE_ BOOL ResetMenuItem_DrawStyle(void);
_MENU_PAGE_ BOOL ExectReset(void);



/*
工厂菜单页
*/

_MENU_PAGE_ TitelType CODE FactoryMenu_TitelTab[];
_MENU_PAGE_ TitelType CODE FactoryMenuItem_PicTab[];
_MENU_PAGE_ TitelType CODE FactoryMenuItem_SwitchTab[];
_MENU_PAGE_ TitelType CODE FactoryMenuItem_PositionTab[];
_MENU_PAGE_ TitelType CODE FactoryMenuItem_SystemTab[];
_MENU_PAGE_ TitelType CODE FactoryMenuItem_UserTab[];

_MENU_PAGE_ ItemValueType CODE FactoryMenuPicItem_Val[];
_MENU_PAGE_ ItemValueType CODE FactoryMenuSwitchItem_Val[];
_MENU_PAGE_ ItemValueType CODE FactorySystemMenu_Val[];
_MENU_PAGE_ ItemValueType CODE FactoryUserMenu_Val[];

_MENU_PAGE_ MenuPageType CODE FactoryMenu;
_MENU_PAGE_ AdjustType FactoryMenu_CheckCondition(void);



/*
工厂菜单PIC页
*/
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_VcomDcTitelTab[];
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_BrightnessTitelTab[];
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_ContrastTitelTab[];
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_SaturationTitelTab[];
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_OsdPosXOffsetTab[];
_MENU_PAGE_ TitelType CODE FactoryPicMenuItem_OsdPosYOffsetTab[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_VcomDcVal[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_BrightnessVal[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_ContrastVal[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_SaturationVal[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_OsdPosXOffsetVal[];
_MENU_PAGE_ ItemValueType CODE FactoryPicMenu_OsdPosYOffsetVal[];

_MENU_PAGE_ MenuPageType CODE FactoryPicMenu;

_MENU_PAGE_ AdjustType FactoryPicMenu_CheckCondition(void);
_MENU_PAGE_ BOOL AdjustVideoVcomDc(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoBrightness(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoContrast(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoSaturation(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoOsdXOffSet(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoOsdYOffSet(UCHAR opratComd);
_MENU_PAGE_ BOOL ExectVideoVcomDc(void);
_MENU_PAGE_ BOOL ExectVideoBrightness(void);
_MENU_PAGE_ BOOL ExectVideoContrast(void);
_MENU_PAGE_ BOOL ExectVideoSaturation(void);
_MENU_PAGE_ BOOL ExectVideoOsdXOffSet(void);
_MENU_PAGE_ BOOL ExectVideoOsdYOffSet(void);



/*
工厂菜单SWITCH页
*/
_MENU_PAGE_ ItemValueType CODE VolumeSwitchVal[];
_MENU_PAGE_ ItemValueType CODE ScalerSwitchVal[];
_MENU_PAGE_ ItemValueType CODE FlipSwitchVal[];
_MENU_PAGE_ ItemValueType CODE ResetSwitchVal[];
_MENU_PAGE_ ItemValueType CODE IRABSwitchVal[];
_MENU_PAGE_ ItemValueType CODE RadioFreqSwitchVal[];
_MENU_PAGE_ ItemValueType CODE PowerSwitchVal[];
_MENU_PAGE_ ItemValueType CODE LogoIdSwitchVal[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_VolumeTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_ScalerTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_FlipTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_ResetTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_IRABTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_RadioFreqTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_PowerTitelTab[];
_MENU_PAGE_ TitelType CODE FactorySwitchMenuItem_LogoIdTitelTab[];

_MENU_PAGE_ MenuPageType CODE FactorySwitchMenu;

_MENU_PAGE_ AdjustType FactorySwitchMenu_CheckCondition(void);
_MENU_PAGE_ BOOL AdjustVideoVolumeSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoScalerSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoFlipSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoResetSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoIRABSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustVideoRadioFreqSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustSystemPowerSwitch(UCHAR opratComd);
_MENU_PAGE_ BOOL AdjustSystemLogoIdSwitch(UCHAR opratComd);



extern MenuPageType* CODE tblMenus[];
#define CurrentMenu		     tblMenus[g_ucMenuPageIndex]
#define PrevMenuPage		 CurrentMenu->PrevPage
#define CurrentMenuItems	 CurrentMenu->MenuItems
#define CurrentMenuItemCount CurrentMenu->ItemCount
#define CurrentMenuItem		 CurrentMenu->MenuItems[g_ucMenuItemIndex]
#define CurrentBlock         CurrentMenu->OsdBlockId
#define CurrentMenuTimeOut	 CurrentMenu->TimeOut


#define NextMenuPage		 CurrentMenuItem.NextPage
#define CurrentMenuItemFunc  CurrentMenuItem.KeyFunction
#endif


