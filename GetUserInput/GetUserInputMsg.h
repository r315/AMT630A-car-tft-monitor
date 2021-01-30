#ifndef _GET_USER_INPUT_MSG_H__
#define _GET_USER_INPUT_MSG_H__

#ifdef _GET_USER_MSG_C_
#define _GET_USER_MSG_EXTERN_ 
#else
#define _GET_USER_MSG_EXTERN_ extern
#endif

_GET_USER_MSG_EXTERN_ MSG POS_GetIrMsg(void);
_GET_USER_MSG_EXTERN_ MSG POS_GetKeyPadMsg(void);
_GET_USER_MSG_EXTERN_ FLAG POS_CheckKeyPadRelease(void);
_GET_USER_MSG_EXTERN_ KeyInfor POS_TransferKeyMsg(UCHAR KeyCmd);
_GET_USER_MSG_EXTERN_ UCHAR POS_TransferI2CKeyCmd(KeyInfor Key);
_GET_USER_MSG_EXTERN_ UCHAR POS_TransferAdcKeyCmd(KeyInfor Key);

#endif

