//--------------------------------------------------------------------------
/// @file MemoryFile.cpp
/// @brief Contains the implementation for MemoryFile files
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (mark.reichert2@magna.com)
///
//  --------------------------------------------------------------------------


// PRQA S 3706 EOF // Using subscript operator here is intended.

#include "MemoryFile.h"

namespace osal
{

  MemoryFile::MemoryFile()
    : IFile()
    , dataSize_u64(0U)
    , data_pu8(NULL)
    , position_u64(0U)
    , swapEndian_b(true)
  {
    
  }

  MemoryFile::~MemoryFile()
  {
  }

  bool_t MemoryFile::open_b(uint8_t* b_Data_u8, uint64_t i_Size_u64, bool_t i_SwapEndian_b)
  {
    close_b();

    data_pu8     = b_Data_u8;
    dataSize_u64 = i_Size_u64;
    position_u64 = 0;
    swapEndian_b  = i_SwapEndian_b;

    return (NULL != data_pu8) && (0 < dataSize_u64);
  }

  bool_t MemoryFile::close_b()
  {
    data_pu8     = NULL;
    dataSize_u64 = 0;
    position_u64 = 0;

    // close doesn't make sense for memory files
    return e_PeOk;
  }

  uint64_t MemoryFile::write_u64(const void* i_Buffer_pv, uint64_t i_BufferSize_u64)
  {
    uint64_t v_NumBytesWritten_u64 = 0;

    if (NULL != data_pu8)
    {
      AssertFunction(false, "File::write_u64 - Not yet Implemented!");
    }
    else
    {
      AssertFunction(false, "File::write_u64 - open file before writing to it!");
    }

    position_u64 += v_NumBytesWritten_u64;

    return v_NumBytesWritten_u64;
  }

  uint64_t MemoryFile::read_u64(void* b_Buffer_pv, uint64_t i_BufferSize_u64)
  {
    uint64_t v_NumBytesRead_u64 = 0;

    if (NULL != data_pu8)
    {
      // get current data from actual position
      uint8_t* v_CurrDataPos_pu8 = &data_pu8[position_u64];
      
      // don't read out of index
      Assert((position_u64 + i_BufferSize_u64) <= dataSize_u64);

      // convert to uint8 buffer so we can advanced byte-wise
      uint8_t* v_InputBuffer_pu8 = reinterpret_cast<uint8_t*>(b_Buffer_pv);

      sint64_t v_MaxBufferSize_s64 = static_cast<sint64_t>(i_BufferSize_u64) - 1;

      if (true == swapEndian_b)
      {
        // we assume little endian here
        for (sint64_t v_I_s64 = 0; v_I_s64 <= v_MaxBufferSize_s64; ++v_I_s64)
        {
          // assign data
          v_InputBuffer_pu8[v_NumBytesRead_u64] = v_CurrDataPos_pu8[v_I_s64];

          // advance number of bytes
          ++v_NumBytesRead_u64;
        }
      }
      else
      {
        // we assume big endian here
        for (sint64_t v_I_s64 = v_MaxBufferSize_s64; v_I_s64 >= 0; --v_I_s64)
        {
          // assign data
          v_InputBuffer_pu8[v_NumBytesRead_u64] = v_CurrDataPos_pu8[v_I_s64];

          // advance number of bytes
          ++v_NumBytesRead_u64;
        }
      }
    }
    else
    {
      AssertFunction(false, "MemoryFile::read_u64 - Invalid Pointer!");
    }

    position_u64 += v_NumBytesRead_u64;

    return v_NumBytesRead_u64;
  }

  uint64_t MemoryFile::seek_u64(sint64_t i_DistanceToMove_s64, FilePointer_e i_Origin_e)
  {
    uint64_t v_NewPos_u64 = 0;

    if (NULL != data_pu8)
    {
      AssertFunction(false, "File::write_u64 - Not yet Implemented!");
    }
    else
    {
      AssertFunction(false, "MemoryFile::seek_u64 - Invalid Pointer!");
    }

    return v_NewPos_u64;
  }

  uint64_t MemoryFile::getPosition_u64(void)
  {
    uint64_t v_CurrentPos_u64 = 0;

    if (NULL != data_pu8)
    {
      v_CurrentPos_u64 = position_u64;
    }
    else
    {
      AssertFunction(false, "MemoryFile::getPosition_u64 - Invalid Pointer!");
    }

    return v_CurrentPos_u64;
  }

  uint64_t MemoryFile::getSize_u64(void)
  {
    uint64_t v_Size_u64 = 0;

    if (NULL != data_pu8)
    {
      v_Size_u64 = dataSize_u64;
    }
    else
    {
      AssertFunction(false, "MemoryFile::read_u64 - Invalid Pointer!");
    }

    return v_Size_u64;
  }

} // namespace osal
