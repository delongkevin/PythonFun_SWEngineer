//--------------------------------------------------------------------------
/// @file ME_Process.h
/// @brief Interface to abstract standard-library Process
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

#ifndef ME_PROCESS_H
#define ME_PROCESS_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

// --------------------------------------------------------------------------
/// Returns the process id for the calling process.
///
/// @return ID of the current process
// --------------------------------------------------------------------------
ProcessID_t ME_Process_GetCurrentID_t(void);

// --------------------------------------------------------------------------
/// Wait for a process to end.
///
/// For more details refer to the respective OS versions of this function.
///
/// @param  i_ProcessID_t PID
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_WaitForProcessToEnd_t(ProcessID_t i_ProcessID_t);

// --------------------------------------------------------------------------
/// Blocking wait on signal \c SIGTERM.
///
/// For more details refer to the respective OS versions of this function.
///
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_WaitForSigTerm_t(void);

// --------------------------------------------------------------------------
/// Kill a process.
///
/// For more details refer to the respective OS versions of this function.
///
/// @param[in] i_ProcessID_t PID of the process to be killed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_Kill_t(ProcessID_t i_ProcessID_t);

// --------------------------------------------------------------------------
/// Return list of PIDs of all running processes.
///
/// @param[in,out] b_ProcessList_pt Buffer the PIDs have to be stored to
/// @param[in]     i_ListSize_u32   Size of the buffer the PIDs have to be stored to
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_EnumProcesses_t(ProcessID_t* b_ProcessList_pt, uint32_t i_ListSize_u32);

// --------------------------------------------------------------------------
/// Return name of a process.
///
/// @param[in]     i_ProcessID_t    PID of the process whose name has to be returned
/// @param[in,out] o_Name_pc        Character buffer process' name has to stored to
/// @param[in]     i_NameLength_u32 Length of the character buffer process' name has to stored to
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_GetName_t(ProcessID_t i_ProcessID_t, char_t* o_Name_pc, uint32_t i_NameLength_u32);

// --------------------------------------------------------------------------
/// Execute a sequence of commands.
///
/// @param[in,out] b_Process_ps    Pointer to the process handle created for the commands to be executed
/// @param[in]     i_CmdLine_pc    \c ; separated sequence of commands to be executed
/// @param[in]     i_WorkingDir_pc Path to the working directory
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_ExecuteCommand_t(ProcessHandle_s* b_Process_ps, char_t* i_CmdLine_pc, const char_t* i_WorkingDir_pc);

// --------------------------------------------------------------------------
/// Close a process handle.
///
/// @param[in,out] b_Process_ps Pointer to the process handle to be closed
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_CloseHandle_t(ProcessHandle_s* b_Process_ps);

// --------------------------------------------------------------------------
/// Read output of a process executed before.
///
/// @param[in,out] b_Process_ps Pointer to the process handle whose output has to be read
/// @param[in]     i_Buffer_pc  Buffer the output has to be written to
/// @param[in]     i_Length_u16 Length of the buffer the output has to be written to
/// @return Platform error representing result of the operation
// --------------------------------------------------------------------------
PlatformError_t ME_Process_ReadOutput_t(ProcessHandle_s* b_Process_ps, char_t* i_Buffer_pc, uint16_t i_Length_u16);

// --------------------------------------------------------------------------
/// Fork a process.
///
/// For more details refer to the respective OS versions of this function.
///
/// @return PID returned by the fork operation.
// --------------------------------------------------------------------------
ProcessID_t ME_Process_Fork_t(void);

// --------------------------------------------------------------------------
// TODO: implement me
// --------------------------------------------------------------------------
PlatformError_t ME_Process_GetNameW_t(ProcessID_t i_ProcessID_t, wchar_t* o_Name_pc, uint32_t i_NameLength_u32);


#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_PROCESS_H
