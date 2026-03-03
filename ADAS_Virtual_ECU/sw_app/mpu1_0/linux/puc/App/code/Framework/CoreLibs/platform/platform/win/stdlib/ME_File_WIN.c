//--------------------------------------------------------------------------
/// @file ME_File_WIN.c
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
#include "platform/stdlib/ME_File.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/stdlib/ME_Assert.h"

#include <errno.h>

void createFileArguments_v(uint32_t i_OpenFlags_u32, uint32_t* b_DesiredAccess_pu32, uint32_t* b_CreationDisposition_pu32, uint32_t* b_FlagsAndAttributes_pu32)
{
  *b_DesiredAccess_pu32        = 0;
  *b_CreationDisposition_pu32  = 0;
  *b_FlagsAndAttributes_pu32   = FILE_ATTRIBUTE_NORMAL | FILE_FLAG_SEQUENTIAL_SCAN;

  if (i_OpenFlags_u32 & e_FomRead)
  {
    *b_DesiredAccess_pu32 |= GENERIC_READ;

    if (!(i_OpenFlags_u32 & e_FomWrite))
    {
      *b_CreationDisposition_pu32 |= OPEN_EXISTING;
    }
  }

  if (i_OpenFlags_u32 & e_FomWrite)
  {
    *b_DesiredAccess_pu32 |= GENERIC_WRITE;

    if (i_OpenFlags_u32 & e_FomAppend)
    {
      *b_CreationDisposition_pu32 |= OPEN_ALWAYS;
    }
    else
    {
      *b_CreationDisposition_pu32 |= CREATE_ALWAYS;
    }
  }
}

PlatformError_t ME_File_Open_t(FileHandle_s* b_Handle_ps, const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  // Create Open flags to create File arguments
  uint32_t v_DesiredAccess_u32;
  uint32_t v_CreationDisposition_u32;
  uint32_t v_FlagsAndAttributes_u32;

  createFileArguments_v(i_OpenFlags_u32, &v_DesiredAccess_u32, &v_CreationDisposition_u32, &v_FlagsAndAttributes_u32);

  // Now open file
  if (NULL != b_Handle_ps)
  {
    b_Handle_ps->winFileHandle_po = CreateFile(
      i_FileName_pc, 
      v_DesiredAccess_u32, 
      FILE_SHARE_READ, 
      NULL, 
      v_CreationDisposition_u32, 
      v_FlagsAndAttributes_u32, 
      NULL);

    if (INVALID_HANDLE_VALUE == b_Handle_ps->winFileHandle_po)
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

uint64_t ME_File_Read_u64(FileHandle_s* i_Handle_ps, void* i_Buffer_pv, uint64_t i_BufferSize_u64)
{
  uint64_t v_NumBytesRead_u64 = 0;
  uint32_t v_NumBytesRead_u32 = 0;

  if (i_Handle_ps == NULL)
  {
    // Invalid arguments
    Assert(false);
  }
  else
  {
    if (0 == ReadFile(i_Handle_ps->winFileHandle_po, i_Buffer_pv, (uint32_t)i_BufferSize_u64, (LPDWORD)&v_NumBytesRead_u32, NULL))
    {
      ME_GetPlatformError_t(-1);
    }
    else
    {
      v_NumBytesRead_u64 = v_NumBytesRead_u32;
    }
  }

  return v_NumBytesRead_u64;
}

uint64_t ME_File_Write_u64(const FileHandle_s* i_Handle_ps, void* i_Buffer_pv, uint64_t i_BufferSize_u64)
{
  uint64_t v_NumBytesWritten_u64 = 0;
  uint32_t v_NumBytesWritten_u32 = 0;

  if (i_Handle_ps == NULL)
  {
    Assert(false);
  }
  else
  {
    if (0 == WriteFile(i_Handle_ps->winFileHandle_po, i_Buffer_pv, (uint32_t)i_BufferSize_u64, (LPDWORD)&v_NumBytesWritten_u32, NULL))
    {
      ME_GetPlatformError_t(-1);
      Assert(false);
    }
    else
    {
      v_NumBytesWritten_u64 = v_NumBytesWritten_u32;
    }
  }

  return v_NumBytesWritten_u64;
}

uint64_t ME_File_SetPointer_u64(FileHandle_s* i_Handle_ps, sint64_t i_DistanceToMove_s64, FilePointer_t i_StartingPoint_e)
{
  uint64_t v_NewFilePointer_u64 = 0;

  if (NULL == i_Handle_ps)
  {
    Assert(false);
  }
  else
  {
    const uint32_t c_MoveMethodMapping_au32[] =
    {
      FILE_BEGIN,    // e_FpBegin
      FILE_CURRENT,  // e_FpCurrent
      FILE_END,      // e_FpEnd
    };

    LARGE_INTEGER v_DistanceLarge_t;
    LARGE_INTEGER v_NewPointerLarge_t;

    v_DistanceLarge_t.QuadPart = i_DistanceToMove_s64;

    if (SetFilePointerEx(i_Handle_ps->winFileHandle_po, v_DistanceLarge_t, &v_NewPointerLarge_t, c_MoveMethodMapping_au32[i_StartingPoint_e]) != TRUE)
    {
      ME_GetPlatformError_t(-1);
    }
    else
    {
      v_NewFilePointer_u64 = v_NewPointerLarge_t.QuadPart;
    }
  }

  return v_NewFilePointer_u64;
}

uint64_t ME_File_GetSize_u64(FileHandle_s* i_Handle_ps)
{
  uint64_t v_FileSize_u64 = 0;

  if (NULL == i_Handle_ps)
  {
    Assert(false);
  }
  else
  {
    LARGE_INTEGER v_LargeFileSize_t;

    if (TRUE != GetFileSizeEx(i_Handle_ps->winFileHandle_po, &v_LargeFileSize_t))
    {
      ME_GetPlatformError_t(-1);
      Assert(false);
    }
    else
    {
      v_FileSize_u64 = (v_LargeFileSize_t.u.HighPart << 32) | v_LargeFileSize_t.u.LowPart;
    }
  }

  return v_FileSize_u64;
}

PlatformError_t ME_File_Close_t(const FileHandle_s* b_Handle_ps)
{
  PlatformError_t v_Error_t = e_PeOk;
  sint32_t v_Result_s32     = 0;

  if (NULL == b_Handle_ps)
  {
    v_Error_t = e_PeInvalid;
  }
  else if(ME_INVALID_FILE_HANDLE != b_Handle_ps->winFileHandle_po)
  {
    if (0 == CloseHandle(b_Handle_ps->winFileHandle_po))
    {
      v_Error_t = ME_GetPlatformError_t(-1);
      Assert(false);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_File_Delete_t(const char_t* i_FileName_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  if (false == DeleteFile(i_FileName_pc))
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
