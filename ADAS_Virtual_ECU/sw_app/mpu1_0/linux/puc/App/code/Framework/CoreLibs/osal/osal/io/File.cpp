//--------------------------------------------------------------------------
/// @file File.cpp
/// @brief Contains the implementation for FileSystem files
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (mark.reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "File.h"

namespace osal
{

  File::File()
    : IFile()
    , fileHandle_s()
    , fileFlags_u32(0U)
    , fileOpened_b(false)
  {
    
  }

  File::~File()
  {
  }

  bool_t File::open_b(const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32)
  {
    close_b();
    fileFlags_u32 = i_OpenFlags_u32;

    if(NULL == i_FileName_pc)
    {
      fileOpened_b = false;
    }
    else
    {
      // open the file
      PlatformError_t v_Error_t = ME_File_Open_t(&fileHandle_s, i_FileName_pc, fileFlags_u32);

      // and check if any error occurred
      fileOpened_b = (e_PeOk == v_Error_t);
    }

    return fileOpened_b;
  }

  bool_t File::close_b()
  {
    PlatformError_t v_Error_t = e_PeOk;

    if (true == fileOpened_b)
    {
      v_Error_t = ME_File_Close_t(&fileHandle_s);

      fileOpened_b = false;
    }

    return (e_PeOk == v_Error_t);
  }

  uint64_t File::write_u64(const void* i_Buffer_pv, uint64_t i_BufferSize_u64)
  {
    uint64_t v_NumBytesWritten_u64 = 0;

    if (true == fileOpened_b)
    {
      v_NumBytesWritten_u64 = ME_File_Write_u64(&fileHandle_s, i_Buffer_pv, i_BufferSize_u64);
    }
    else
    {
      AssertFunction(false, "File::write_u64 - open file before writing to it!");
    }

    return v_NumBytesWritten_u64;
  }

  uint64_t File::read_u64(void* b_Buffer_pv, uint64_t i_BufferSize_u64)
  {
    uint64_t v_NumBytesRead_u64 = 0;

    if (true == fileOpened_b)
    {
      v_NumBytesRead_u64 = ME_File_Read_u64(&fileHandle_s, b_Buffer_pv, i_BufferSize_u64);
    }
    else
    {
      AssertFunction(false, "File::read_u64 - open file before writing to it!");
    }

    return v_NumBytesRead_u64;
  }

  uint64_t File::seek_u64(sint64_t i_DistanceToMove_s64, FilePointer_e i_Origin_e)
  {
    uint64_t v_NewPos_u64 = 0;

    if (true == fileOpened_b)
    {
      v_NewPos_u64 = ME_File_SetPointer_u64(&fileHandle_s, i_DistanceToMove_s64, i_Origin_e);
    }
    else
    {
      AssertFunction(false, "File::read_u64 - open file before writing to it!");
    }

    return v_NewPos_u64;
  }

  uint64_t File::getPosition_u64(void)
  {
    uint64_t v_CurrentPos_u64 = 0;

    if (true == fileOpened_b)
    {
      v_CurrentPos_u64 = ME_File_SetPointer_u64(&fileHandle_s, 0, e_FpCurrent);
    }
    else
    {
      AssertFunction(false, "File::read_u64 - open file before writing to it!");
    }

    return v_CurrentPos_u64;
  }

  uint64_t File::getSize_u64(void)
  {
    uint64_t v_Size_u64 = 0;

    if (true == fileOpened_b)
    {
      v_Size_u64 = ME_File_GetSize_u64(&fileHandle_s);
    }
    else
    {
      AssertFunction(false, "File::read_u64 - open file before writing to it!");
    }

    return v_Size_u64;
  }

} // namespace osal
