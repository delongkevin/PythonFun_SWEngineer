//--------------------------------------------------------------------------
/// @file TRSC.h
/// @brief Contains Wrapper for TRSC
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _TRSC_SMVC_DEFINES_H_
#define _TRSC_SMVC_DEFINES_H_

#define TRSC_SIGM_TESTING               1
#define READ_TUNABLE_PARAMS             1

#define TAD_HARDCODING_FOR_TEST		      0
#define VC_DEBUG_PRINTS                 0
#define SM_DEBUG_PRINTS                 0
#define TRSC_PRINT_SMVC_INPUT_OUTPUTS   0
#define TRSC_DEBUG_IPC_PRINTS           0
#define TRSC_SMVC_IPC_TEST              0
#define TRSC_SMVC_IPC_PRINTS            0

typedef enum TrscSMVCIpcStructureType_e
{
  ME_VehOut_TRSC_t_ID = 0,
  TRSCSMVCtoSVS_t_ID = 1,
  Detection_Inputs_from_TRSC_t_ID = 2,
  TRSCtoDiagMgr_t_ID = 3,
  TRSCSMVCtoDebugCAN_t_ID = 4
}TrscSMVCIpcStructureType;

#endif //_TRSC_SMVC_DEFINES_H_

