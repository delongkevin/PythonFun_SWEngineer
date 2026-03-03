/*
 * File: TeVBII_e_SPMLatCtrlRespSts.h
 */

#ifndef RTW_HEADER_TeVBII_e_SPMLatCtrlRespSts_h_
#define RTW_HEADER_TeVBII_e_SPMLatCtrlRespSts_h_

typedef enum {
  TeVBII_e_SPMLatCtrlRespSts_Idle = 0, /* Default value */
  TeVBII_e_SPMLatCtrlRespSts_PermNotAvail = 1,
  TeVBII_e_SPMLatCtrlRespSts_TempNotAvail = 2,
  TeVBII_e_SPMLatCtrlRespSts_HasOpen = 3,
  TeVBII_e_SPMLatCtrlRespSts_HasOpenBackup = 4,
  TeVBII_e_SPMLatCtrlRespSts_Init = 5,
  TeVBII_e_SPMLatCtrlRespSts_DampedExit = 6,
  TeVBII_e_SPMLatCtrlRespSts_Faulted = 7,
  TeVBII_e_SPMLatCtrlRespSts_Dummy = 2147483647
} TeVBII_e_SPMLatCtrlRespSts;

#endif                            /* RTW_HEADER_TeVBII_e_SPMLatCtrlRespSts_h_ */
