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
#ifdef ME_PLATFORM_AUTOSARTODO

// stdlib header include
#include "platform/stdlib/ME_Process.h"
#include "platform/stdlib/ME_Thread.h"
#include "platform/stdlib/ME_String.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#include <process.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h> // PRQA S 5123 // use sigxxset
#include <errno.h>

#define ME_PROCESS_D_LIST_LENGTH 32

ProcessID_t ME_Process_GetCurrentID_t(void)
{
  return getpid();
}

PlatformError_t ME_Process_WaitForProcessToEnd_t(ProcessID_t i_ProcessID_t)
{
  sint32_t v_Status_s32 = EOK;
  pid_t v_EndId_s32;

  do
  {
    (void)ME_Thread_Sleep_t(1);

    // WNOHANG    - return immediately if there are no children to wait for.
    // WUNTRACED  - report the status of a stopped child process.
    // WCONTINUED - return the status for any child that was stopped and has been continued.
    // WEXITED    - wait for the process(es) to exit.
    v_EndId_s32 = waitpid(i_ProcessID_t, &v_Status_s32, WUNTRACED | WEXITED);
    if (-1 == v_EndId_s32)
    {
      break; // An error occurred
    }

    if (WIFEXITED(v_Status_s32)) // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib
    {
      ME_Debugger_F_Printf_v("Child ended normally.\n");
    }
    else if (WIFSIGNALED(v_Status_s32)) // PRQA S 4130 // PRQA S 3400 // PRQA S 3397 // PRQA S 2995 // The result of this logical operation is always 'true'. => v_Status_s32 is used as return value of waitpid()
    {
      ME_Debugger_F_Printf_v("Child ended because of an uncaught signal.\n");
    }
    else if (WIFSTOPPED(v_Status_s32)) // PRQA S 3400 // PRQA S 3397 // PRQA S 2995 // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib
    {
      ME_Debugger_F_Printf_v("Child process has stopped.\n");
    }
    else
    {
      /* do nothing */
    }
  }
  while ((!WIFEXITED(v_Status_s32)) && (!WIFSIGNALED(v_Status_s32))); // PRQA S 2995 // PRQA S 3400 // PRQA S 3397 // PRQA S 4130 // Bitwise operations on signed data will give implementation defined results. => QNX lib

  return getPlatformError_t(v_Status_s32);
}

PlatformError_t ME_Process_WaitForSigTerm_t(void)
{
  sint32_t v_Result_s32;
  PlatformError_t v_Error_t;
  sigset_t v_sigset_t;
  sint32_t v_received_s32 = 0;

  v_Result_s32 = sigemptyset(&v_sigset_t);
  v_Error_t = getPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  v_Result_s32 = sigaddset(&v_sigset_t, SIGTERM);
  v_Error_t = getPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  v_Result_s32 = sigaddset(&v_sigset_t, SIGKILL);
  v_Error_t = getPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  v_Result_s32 = sigprocmask(SIG_BLOCK, &v_sigset_t, NULL);
  v_Error_t = getPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  v_Result_s32 = sigwait(&v_sigset_t, &v_received_s32);
  v_Error_t = getPlatformError_t(v_Result_s32);
  Assert(v_Error_t == e_PeOk);

  return e_PeOk;
}

PlatformError_t ME_Process_Kill_t(ProcessID_t i_ProcessID_t)
{
  sint32_t v_Status_s32 = 0;

  if(getpgid(i_ProcessID_t) >= 0)
  {
    // only kill, if process exists
    // Returns: Zero, or -1 if an error occurs (errno is set).
    v_Status_s32 = kill(i_ProcessID_t, SIGTERM);
  }

  return getPlatformError_t(v_Status_s32);
}

PlatformError_t ME_Process_EnumProcesses_t(ProcessID_t* b_ProcessList_pt, uint32_t i_ListSize_u32)
{
  PlatformError_t v_Error_t = e_PeOk;
  FILE* v_Output_po = popen("pidin a | awk {'print$1'}", "r");
  char_t v_Result_ac[64] = { 0x0 };
  uint32_t v_CurrListSize_u32 = 0;
  sint32_t v_Result_s32;
  char_t* v_EndPtr_pc = NULL;

  if((NULL != v_Output_po) && (NULL != b_ProcessList_pt))
  {
    // Read line by line and convert the string into an unsigned integer
    while (fgets(v_Result_ac, sizeof(v_Result_ac), v_Output_po) != NULL )
    {
      sint32_t v_CurrProcessID_s32;

      // To distinguish success/failure after call
      errno = 0;

      v_CurrProcessID_s32 = strtol(v_Result_ac, &v_EndPtr_pc, 10);

      // Check for overflow
      if((errno == ERANGE) && (v_CurrProcessID_s32 == LONG_MAX)) // PRQA S 2992, 2996, 2880 // errno is set by QNX system
      {
        continue; // PRQA S 770 // A 'continue' statement has been used. => skip invalid entry lines, OK // PRQA S 2880 // errno is set by QNX system
      }

      // Check for errors
      if((errno != 0) && (v_CurrProcessID_s32 == 0))
      {
        continue; // PRQA S 770 // A 'continue' statement has been used. => skip invalid entry lines, OK
      }

      // Check if digits are converted
      if (v_EndPtr_pc == v_Result_ac)
      {
        continue; // PRQA S 770 // A 'continue' statement has been used. => skip invalid entry lines, OK
      }

      // add to list if it's big enough
      if (v_CurrListSize_u32 < i_ListSize_u32)
      {
        b_ProcessList_pt[v_CurrListSize_u32] = v_CurrProcessID_s32; // PRQA S 492 // range check is done above
        ++v_CurrListSize_u32;
      }
      else
      {
        v_Error_t = e_PeNoMemory;
        ME_Debugger_F_Printf_v("ProcessList Placeholder too small\n");
        break; // break out of while
      }
    }

    v_Result_s32 = pclose(v_Output_po);
    if(e_PeOk == v_Error_t)
    {
      // only assign the new result if no error occurred
      v_Error_t = getPlatformError_t(v_Result_s32);
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Process_GetName_t(ProcessID_t i_ProcessID_t, char_t* o_Name_pc, uint32_t i_NameLength_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(NULL != o_Name_pc)
  {
    char_t v_ProcExe_ac[ME_PROCESS_D_LIST_LENGTH];
    char_t v_Result_ac[64] = { 0x0 };
    FILE* v_Output_po;

    (void)sprintf(&v_ProcExe_ac[0], "/proc/%d/exefile", i_ProcessID_t);

    v_Output_po = fopen(&v_ProcExe_ac[0], "r");
    if(NULL != v_Output_po)
    {
      // Read line by line and convert the string into an unsigned integer
      while (fgets(&v_Result_ac[0], sizeof(v_Result_ac), v_Output_po) != NULL )
      {
        // fin last slash occurrence
        char_t* v_LastSlash_pc = strrchr(&v_Result_ac[0], '/');

        if(NULL != v_LastSlash_pc)
        {
          // copy and null terminate
          (void)strcpy(o_Name_pc, &v_LastSlash_pc[1]); // use index[1] to remove slash // PRQA S 491
          o_Name_pc[i_NameLength_u32 - 1] = '\0'; // PRQA S 492 // range check is done above
        }
      }
    }
    else
    {
      v_Error_t = e_PeNoEntry;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Process_ExecuteCommand_t(ProcessHandle_s* b_Process_ps, char_t* i_CmdLine_pc, const char_t* i_WorkingDir_pc)
{
  PlatformError_t v_Error_t;

  char_t command[ME_MAX_PATH_LENGTH];

  if(NULL != b_Process_ps)
  {
    if(i_WorkingDir_pc == NULL)
    {
      // The command must look like this: "./script"
      (void)ME_String_Sprintf_s32(command, "./%s", i_CmdLine_pc);
    }
    else
    {
      // The command must look like this: "cd /somewhere/else; ./script"
      (void)ME_String_Sprintf_s32(command, "cd %s; ./%s", i_WorkingDir_pc, i_CmdLine_pc);
    }
#if 1
    b_Process_ps->file_po = popen(command, "w"); // get output to current console
#else
    b_Process_ps->file_po = popen(command, "r"); // output must be read via ME_Process_ReadOutput_t(...)
#endif
    if(NULL != b_Process_ps->file_po)
    {
      b_Process_ps->created_b = true;
      v_Error_t = getPlatformError_t(0);
    }
    else
    {
      b_Process_ps->created_b = false;
      v_Error_t = getPlatformError_t(-1);
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Process_CloseHandle_t(ProcessHandle_s* b_Process_ps)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Process_ps)
  {
    v_Result_s32 = pclose(b_Process_ps->file_po);
    v_Error_t = getPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_Process_ReadOutput_t(ProcessHandle_s* b_Process_ps, char_t* i_Buffer_pc, uint16_t i_Length_u16)
{
  PlatformError_t v_Error_t;

  if((NULL != b_Process_ps) && (NULL != i_Buffer_pc))
  {
    if(true == b_Process_ps->created_b)
    {
      char_t* v_RetVal;
      // returns: The same pointer as buf, or NULL if the stream is at the end-of-file or an error occurs (errno is set).
      v_RetVal = fgets(i_Buffer_pc, i_Length_u16, b_Process_ps->file_po); // PRQA S 3748 // int(4) is larger then u16(2)
      if(NULL != v_RetVal)
      {
        v_Error_t = e_PeOk;
      }
      else
      {
        v_Error_t = getPlatformError_t(-1);
      }
    }
    else
    {
      v_Error_t = e_PeInvalid;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

ProcessID_t ME_Process_Fork_t(void)
{
  ProcessID_t b_ChildID_t;

  b_ChildID_t = fork();

  return b_ChildID_t;
}

#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined

