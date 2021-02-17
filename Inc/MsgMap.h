/*
ϵͳ���е���Ϣ���嶼�ڴ�MAP�ļ�
*/
#ifndef MSG_MAP_H__
#define MSG_MAP_H__

typedef enum _sysMsg
{
  //�û��������MSG (�����尴����ң�ذ���)  UPK: user press key
   MSG_UPK_UP,    
   MSG_UPK_DOWN,
   MSG_UPK_LEFT,
   MSG_UPK_RIGHT,
   MSG_UPK_MENU,
   MSG_UPK_VOLUME_INC,
   MSG_UPK_VOLUME_DEC,
   MSG_UPK_MUTEONOFF,
   MSG_UPK_MODE,
   MSG_UPK_SYS,
   MSG_UPK_SOURCE_SWITCH,
   MSG_UPK_POWER,
   MSG_UPK_BRIGHTNESS,
   MSG_UPK_CONTRAST,
   MSG_UPK_SATURATION,

   //�ź����MSG
   MSG_CONFIG_COLOR_SYS,
   MSG_SIGNAL_OK,
   MSG_NO_SIGNAL,
   MSG_NOSIGNALPOWEROFF,
   
   //OSD ���MSG
   MSG_OSD_EXIT,
   MSG_OSD_STORAGE,

   //�������MSG
   MSG_CAR_PON_REVERSING,
   MSG_CAR_PON_GO_AHEAD,
   
   MSG_CAR_POF_REVERSING,
   MSG_CAR_POF_GO_AHEAD,

   MSG_PON_REVERSING,
   
   //������ص�MSG
   MSG_BT_CONN,
   MSG_BT_DISC,
   MSG_BT_CALLERID,
   MSG_BT_CALLERDROP,
   
   //�������MSG
   MSG_TURNOFF_BACKLIGHT,
   MSG_TURNON_BACKLIGHT,
   
   //������MSG
   MSG_BATTERYADC,

   MSG_SERIAL,
   
   MSG_NULL = -1,
}MSG;


typedef enum _MacroKeyVal
{
	KEY_POWER=0,           	
	KEY_LEFT,            	        
	KEY_RIGHT,           	       
	KEY_VOL_INC,         	   
	KEY_VOL_DEC,          	   
	KEY_MENU,               
	KEY_SOURCE_SWITCH,
	KEY_MODE,
	KEY_xxxx,
	KEY_NULL = -1,               
}MacroKeyVal;

#endif
