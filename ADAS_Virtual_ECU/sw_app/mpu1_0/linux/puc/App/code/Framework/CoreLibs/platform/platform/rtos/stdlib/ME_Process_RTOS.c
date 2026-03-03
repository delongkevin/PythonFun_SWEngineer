/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Process_AUTOSAR.c
/// @brief AUTOSAR implementation for standard-library Process
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

// stdlib header include
#include "platform/stdlib/ME_Process.h"
#include "platform/stdlib/ME_Thread.h"
#include "platform/stdlib/ME_String.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#define ME_PROCESS_D_LIST_LENGTH 32

ProcessID_t ME_Process_GetCurrentID_t(void)
{
  return 0U;
}

PlatformError_t ME_Process_WaitForProcessToEnd_t(ProcessID_t i_ProcessID_t)
{
  sint32_t v_Status_s32 = 0;

  return ME_GetPlatformError_t(v_Status_s32);
}

PlatformError_t ME_Process_WaitForSigTerm_t(void)
{
  return e_PeOk;
}

PlatformError_t ME_Process_Kill_t(ProcessID_t i_ProcessID_t)
{
  sint32_t v_Status_s32 = 0;

  return ME_GetPlatformError_t(v_Status_s32);
}

PlatformError_t ME_Process_EnumProcesses_t(ProcessID_t* b_ProcessList_pt, uint32_t i_ListSize_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Process_GetName_t(ProcessID_t i_ProcessID_t, char_t* o_Name_pc, uint32_t i_NameLength_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Process_ExecuteCommand_t(ProcessHandle_s* b_Process_ps, char_t* i_CmdLine_pc, const char_t* i_WorkingDir_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_Process_CloseHandle_t(ProcessHandle_s* b_Process_ps)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

PlatformError_t ME_Process_ReadOutput_t(ProcessHandle_s* b_Process_ps, char_t* i_Buffer_pc, uint16_t i_Length_u16)
{
  PlatformError_t v_Error_t = e_PeOk;
  return v_Error_t;
}

ProcessID_t ME_Process_Fork_t(void)
{
  ProcessID_t b_ChildID_t = 0U;

  return b_ChildID_t;
}

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined

