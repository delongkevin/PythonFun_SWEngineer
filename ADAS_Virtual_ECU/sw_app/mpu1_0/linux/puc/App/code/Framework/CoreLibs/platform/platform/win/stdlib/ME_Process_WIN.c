//--------------------------------------------------------------------------
/// @file ME_Process_WIN.c
/// @brief Windows implementation for standard-library File
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

// compile this file for WIN only
#ifdef ME_PLATFORM_WIN

// stdlib header include
#include "platform/stdlib/ME_Process.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"
#include "platform/win/WinInclude.h"

#include <psapi.h>
#include <TlHelp32.h>

#include <winnt.h>
#include <winternl.h>
#include <stdio.h>
#include <errno.h>
#include <assert.h>
#include <process.h>
#include <signal.h>

#pragma comment(lib, "psapi.lib")
//
//
//#define RTL_CLONE_PROCESS_FLAGS_CREATE_SUSPENDED 1
//#define RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES  2
//#define RTL_CLONE_PROCESS_FLAGS_NO_SYNCHRONIZE   4
//
//#ifndef STATUS_SUCCESS
//#define STATUS_SUCCESS                  ((NTSTATUS) 0)
//#endif
//#define STATUS_PROCESS_CLONED           ((NTSTATUS) 0x00000129)
//
//typedef struct _CLIENT_ID
//{
//  ULONG UniqueProcess;
//  ULONG UniqueThread;
//} CLIENT_ID, *PCLIENT_ID;
//
//typedef struct _SECTION_IMAGE_INFORMATION {
//  PVOID EntryPoint;
//  ULONG StackZeroBits;
//  ULONG StackReserved;
//  ULONG StackCommit;
//  ULONG ImageSubsystem;
//  WORD SubsystemVersionLow;
//  WORD SubsystemVersionHigh;
//  ULONG Unknown1;
//  ULONG ImageCharacteristics;
//  ULONG ImageMachineType;
//  ULONG Unknown2[3];
//} SECTION_IMAGE_INFORMATION, *PSECTION_IMAGE_INFORMATION;
//
//typedef struct _RTL_USER_PROCESS_INFORMATION
//{
//  ULONG Length;
//  HANDLE Process;
//  HANDLE Thread;
//  CLIENT_ID ClientId;
//  SECTION_IMAGE_INFORMATION ImageInformation;
//} RTL_USER_PROCESS_INFORMATION, *PRTL_USER_PROCESS_INFORMATION;

//typedef struct _PROCESS_BASIC_INFORMATION
//{
//  DWORD_PTR ExitStatus;
//  PVOID PebBaseAddress;
//  DWORD_PTR AffinityMask;
//  DWORD_PTR BasePriority;
//  ULONG_PTR UniqueProcessId;
//  ULONG_PTR InheritedFromUniqueProcessId;
//} PROCESS_BASIC_INFORMATION, *PPROCESS_BASIC_INFORMATION;

//typedef enum _PROCESSINFOCLASS {
//  ProcessBasicInformation = 0
//} PROCESSINFOCLASS;

//typedef NTSTATUS (NTAPI
//  *RtlCloneUserProcess_f) (ULONG, PSECURITY_DESCRIPTOR, PSECURITY_DESCRIPTOR,
//  HANDLE, PRTL_USER_PROCESS_INFORMATION);
//typedef NTSTATUS (NTAPI *NtQueryInformationProcess_f)(HANDLE, PROCESSINFOCLASS, PVOID,
//  ULONG, PULONG);

//typedef NTSTATUS (__stdcall *queryInformationProcess_f)(
//  HANDLE ProcessHandle,
//  PROCESSINFOCLASS ProcessInformationClass,
//  PVOID ProcessInformation,
//  ULONG ProcessInformationLength,
//  PULONG ReturnLength
//  );


ProcessID_t ME_Process_GetCurrentID_t()
{
  return GetCurrentProcessId();
}

PlatformError_t ME_Process_WaitForProcessToEnd_t(ProcessID_t i_ProcessID_t)
{
  PlatformError_t v_Error_t = e_PeOk;
  bool_t v_Ok_b = false;
  uint32_t v_Ret_u32;
  HANDLE v_Process_t;

  do
  {
    Sleep(1);

    v_Process_t = OpenProcess(SYNCHRONIZE, FALSE, i_ProcessID_t);

    v_Ret_u32 = WaitForSingleObject(v_Process_t, 0);

    v_Ok_b = CloseHandle(v_Process_t);
  }
  while (v_Ret_u32 == WAIT_TIMEOUT);

  if (true == v_Ok_b)
  {
    v_Error_t = e_PeOk;
  }
  else
  {
    v_Error_t = ME_GetPlatformError_t(-1);
  }

  return v_Error_t;
}

PlatformError_t ME_Process_WaitForSigTerm_t(void)
{
  //TODO: test it! (currently it cannot be tested, because we don't use Processes for each job under windows)
  
  signal(SIGTERM, NULL);
  return e_PeOk;
}

PlatformError_t ME_Process_Kill_t(ProcessID_t i_ProcessID_t)
{
  HANDLE v_ProcessHandle_t = OpenProcess(PROCESS_TERMINATE, FALSE, i_ProcessID_t);
  
  if (v_ProcessHandle_t == INVALID_HANDLE_VALUE)
  {
    Assert(false);
  }
  else
  {
    TerminateProcess(v_ProcessHandle_t, 0);

    CloseHandle(v_ProcessHandle_t);
  }

  return ME_GetPlatformError_t(-1);
}

PlatformError_t ME_Process_EnumProcesses_t(ProcessID_t* b_ProcessList_pt, uint32_t i_ListSize_u32)
{
  HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
  uint32_t v_idx_u32;
  bool_t v_run_b = true;

  if (hSnapshot != INVALID_HANDLE_VALUE)
  {
    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    Process32First(hSnapshot, &processEntry);
    b_ProcessList_pt[0] = processEntry.th32ProcessID;

    v_run_b = Process32Next(hSnapshot, &processEntry);
    for(v_idx_u32 = 1; v_idx_u32 < i_ListSize_u32 && v_run_b == true; v_idx_u32++)
    {
      b_ProcessList_pt[v_idx_u32] = processEntry.th32ProcessID;
      v_run_b = Process32Next(hSnapshot, &processEntry);
    }

    CloseHandle(hSnapshot);

    return e_PeOk;
  }

  CloseHandle(hSnapshot);

  return e_PeInvalid;
}

PlatformError_t ME_Process_GetName_t(ProcessID_t i_ProcessID_t, char_t* o_Name_pc, uint32_t i_NameLength_u32)
{
  PlatformError_t v_Error_t;
  HMODULE  v_ModuleHandle_t;
  uint32_t v_bytesReturned_u32;
  HANDLE   v_ProcessHandle_t;
    
  v_ProcessHandle_t = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, i_ProcessID_t);
  if (v_ProcessHandle_t)
  {
    if (EnumProcessModulesEx(v_ProcessHandle_t, &v_ModuleHandle_t, sizeof(v_ModuleHandle_t), (DWORD*)&v_bytesReturned_u32, LIST_MODULES_ALL))
    {
      if (GetModuleBaseNameA(v_ProcessHandle_t, v_ModuleHandle_t, o_Name_pc, i_NameLength_u32) != 0)
      {
        CloseHandle(v_ProcessHandle_t);
        v_Error_t = e_PeOk;
      }
      else
      {
        v_Error_t = e_PeNoEntry;
      }
    }
    else
    {
      v_Error_t = e_PeNoEntry;
    }
  }
  else
  {
    v_Error_t = e_PeNoEntry;
  }

  return v_Error_t;
}

PlatformError_t ME_Process_ExecuteCommand_t(ProcessHandle_s* b_Process_ps, char_t* i_CmdLine_pc, const char_t* i_WorkingDir_pc)
{
  HANDLE v_Input_t;
  HANDLE v_Output_t;

  STARTUPINFO v_StartupInfo_t;
  PROCESS_INFORMATION v_ProcessInformation_t;

  SECURITY_ATTRIBUTES v_ProcessAttributes_t;
  SECURITY_ATTRIBUTES v_ThreadAttributes_t;
  SECURITY_ATTRIBUTES v_PipeAttributes_t;

  char v_DefaultWorkingDir_ac[] = ".\\";

  if (i_WorkingDir_pc == NULL)
  {
    i_WorkingDir_pc = v_DefaultWorkingDir_ac;
  }

  // We don't use any special security settings
  v_ProcessAttributes_t.nLength              = sizeof(SECURITY_ATTRIBUTES);
  v_ProcessAttributes_t.lpSecurityDescriptor = NULL;
  v_ProcessAttributes_t.bInheritHandle       = true;

  // We don't use any special security settings
  v_ThreadAttributes_t.nLength              = sizeof(SECURITY_ATTRIBUTES);
  v_ThreadAttributes_t.lpSecurityDescriptor = NULL;
  v_ThreadAttributes_t.bInheritHandle       = true;

  // We don't use any special security settings
  v_PipeAttributes_t.nLength                = sizeof(SECURITY_ATTRIBUTES);
  v_PipeAttributes_t.lpSecurityDescriptor   = NULL;
  v_PipeAttributes_t.bInheritHandle         = true;

  if (CreatePipe(&v_Input_t, &v_Output_t, &v_PipeAttributes_t, 0))
  {
    if (!DuplicateHandle(GetCurrentProcess(), v_Input_t, GetCurrentProcess(), NULL, 0, false, DUPLICATE_SAME_ACCESS))
    {
      // Error
      CloseHandle(v_Input_t);
      CloseHandle(v_Output_t);

      Assert(false);
    }
    else
    {
      memset(&v_StartupInfo_t, 0, sizeof(STARTUPINFO));

      v_StartupInfo_t.cb            = sizeof(STARTUPINFO);
      v_StartupInfo_t.dwFlags        = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
      v_StartupInfo_t.wShowWindow = SW_HIDE;
      v_StartupInfo_t.hStdError   = v_Output_t;
      v_StartupInfo_t.hStdInput    = NULL;
      v_StartupInfo_t.hStdOutput  = v_Output_t;


      if (!CreateProcess(NULL, i_CmdLine_pc, &v_ProcessAttributes_t, &v_ThreadAttributes_t, true, NORMAL_PRIORITY_CLASS,
        NULL, i_WorkingDir_pc, &v_StartupInfo_t, &v_ProcessInformation_t))
      {
        CloseHandle(v_Input_t);
        CloseHandle(v_Output_t);

        Assert(false);
      }
      else
      {
        CloseHandle(v_Output_t);
        CloseHandle(v_ProcessInformation_t.hProcess);
        CloseHandle(v_ProcessInformation_t.hThread);

        if (b_Process_ps == NULL)
        {
          Assert(false);
        }
        else
        {
          b_Process_ps->processHandle_po  = v_Input_t;
          b_Process_ps->created_b         = true;
        }
      }
    }
  }
  else
  {
    Assert(false);
  }

  return ME_GetPlatformError_t(-1);
}

PlatformError_t ME_Process_CloseHandle_t(ProcessHandle_s* b_Process_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (NULL == b_Process_ps)
  {
    v_Error_t = e_PeInvalid;
  }
  else
  {
    if (true == CloseHandle(b_Process_ps->processHandle_po))
    {
      v_Error_t = e_PeOk;
    }
    else
    {
      v_Error_t = ME_GetPlatformError_t(-1);
    }
  }
  return v_Error_t;
}

PlatformError_t ME_Process_ReadOutput_t(ProcessHandle_s* b_Process_ps, char_t* i_Buffer_pc, uint16_t i_Length_u16)
{
  DWORD v_Count_u32;
  
  if (NULL != b_Process_ps && true == b_Process_ps->created_b)
  {
    if (!ReadFile(b_Process_ps->processHandle_po, i_Buffer_pc, i_Length_u16 - 1, &v_Count_u32, NULL))
    {
      CloseHandle(b_Process_ps->processHandle_po);

      b_Process_ps->processHandle_po  = NULL;
      b_Process_ps->created_b         = false;

      Assert(false);
    }

    i_Buffer_pc[v_Count_u32] = 0;

    if (v_Count_u32 == 0)
    {
      CloseHandle(b_Process_ps->processHandle_po);

      b_Process_ps->processHandle_po  = NULL;
      b_Process_ps->created_b         = false;
    }
    else
    {
      // Alright
    }
  }
  else
  {
    // Invalid Parameter
    Assert(false);
  }

  return ME_GetPlatformError_t(-1);
}

ProcessID_t ME_Process_Fork_t(void)
{
  //HANDLE maph = NULL;
  //HMODULE mod;
  //char *map = NULL;
  //NTSTATUS status;
  //RTL_USER_PROCESS_INFORMATION process_info;
  //RtlCloneUserProcess_f clone_p;
  //NtQueryInformationProcess_f queryInformationProcess_p;

  //return ECHILD; // return, as fork does not work // TODO

  //setvbuf (stdout, NULL, _IONBF, 0);
  //setvbuf (stderr, NULL, _IONBF, 0);

  //mod = GetModuleHandle("ntdll.dll");
  //if (!mod)
  //  return -ENOSYS;


  //clone_p = (RtlCloneUserProcess_f)GetProcAddress(mod, "RtlCloneUserProcess");
  //if (clone_p == NULL)
  //  return -ENOSYS;

  //queryInformationProcess_p = (NtQueryInformationProcess_f)GetProcAddress(mod, "NtQueryInformationProcess");
  //if(queryInformationProcess_p == NULL)
  //  return -ENOSYS;

  ///* lets do this */
  //status = clone_p(RTL_CLONE_PROCESS_FLAGS_INHERIT_HANDLES | RTL_CLONE_PROCESS_FLAGS_CREATE_SUSPENDED,
  //  NULL, NULL, NULL, &process_info);

  //switch (status)
  //{
  //case STATUS_SUCCESS:
  //  //ME_Debugger_F_Printf_v("Ich bin dein Vater: PID(getCurrentId) %d\n", ME_Process_GetCurrentID_t());
  //  {
  //    HANDLE me, hp, ht, hcp = 0;
  //    DWORD pi, ti;
  //    me = GetCurrentProcess();
  //    pi = (DWORD)process_info.ClientId.UniqueProcess;
  //    ti = (DWORD)process_info.ClientId.UniqueThread;

  //    assert(hp = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pi));
  //    assert(ht = OpenThread(THREAD_ALL_ACCESS, FALSE, ti));

  //    ResumeThread(ht);
  //    CloseHandle(ht);
  //    CloseHandle(hp);
  //    return pi;
  //  }
  //  break;
  //case STATUS_PROCESS_CLONED:
  //  AllocConsole();
  //  //ME_Debugger_F_Printf_v("Ich bin dein Kind: PID %d\n", ME_Process_GetCurrentID_t());
  //  /* fix stdio */
  //  /*status = NtQueryInformationProcess (GetCurrentProcess (),
  //  ProcessBasicInformation,
  //  &pbi, sizeof pbi, NULL);
  //  if (!NT_SUCCESS (status))
  //  {
  //  fprintf (stderr, "NtQueryInformationProcess failed, status 0x%08lx\n",
  //  status);
  //  printf ("RtlCloneUserProcess in child  %lu\n",
  //  GetCurrentProcessId ());
  //  }
  //  else
  //  printf ("RtlCloneUserProcess in child  %lu, parent pid = %lu\n",
  //  GetCurrentProcessId (), pbi.InheritedFromUniqueProcessId)*/
  //    return 0;
  //  break;
  //default:
  // // ME_Debugger_F_Printf_v (stderr, "RtlCloneUserProcess failed, status 0x%08lx\n", status);
  //  break;
  //}
  return 0;
}

PlatformError_t ME_Process_GetNameW_t(ProcessID_t i_ProcessID_t, wchar_t* o_Name_pc, uint32_t i_NameLength_u32)
{
  HMODULE  v_ModuleHandle_t;
  uint32_t v_BytesReturned_u32;
  HANDLE v_ProcessHandle_t = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, i_ProcessID_t);
  if (v_ProcessHandle_t)
  {
    if (EnumProcessModulesEx(v_ProcessHandle_t, &v_ModuleHandle_t, sizeof(v_ModuleHandle_t), (DWORD*)&v_BytesReturned_u32, LIST_MODULES_ALL))
    {
      if (GetModuleBaseNameW(v_ProcessHandle_t, v_ModuleHandle_t, o_Name_pc, i_NameLength_u32) != 0)
      {
        CloseHandle(v_ProcessHandle_t);
      }
    }

    CloseHandle(v_ProcessHandle_t);
  }

  return ME_GetPlatformError_t(-1);
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
