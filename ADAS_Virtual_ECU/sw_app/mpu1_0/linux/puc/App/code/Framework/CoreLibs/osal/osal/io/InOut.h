//--------------------------------------------------------------------------
/// @file InOutBinary.h
/// @brief Serialization from Binary Data via File Interface
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (mark.reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_IN_OUT_BINARY_H
#define OSAL_IN_OUT_BINARY_H

#include <platform/PlatformAPI.h>
#include "IFile.h"
#include "osal/system/String.h"

namespace osal
{

class InOut
{
public:
  InOut();
  ~InOut();

  bool_t create_b(IFile* b_File_po, bool i_IsLoading_b);
  bool_t isLoading_b() const;

  template <typename T>
  void serialize_v(T& b_Value_rx) const
  {
    if (true == loading_b)
    {
      file_po->read_u64(&b_Value_rx, sizeof(T));
    }
    else
    {
      file_po->write_u64(&b_Value_rx, sizeof(T));
    }
  }

  template <typename T>
  void serializeEnum_v(T& b_Value_rx) const
  {
    // always force enum seialization size to 4 bytes
    uint32_t v_DummyData_u32 = 0;

    if (true == loading_b)
    {
      file_po->read_u64(&v_DummyData_u32, sizeof(v_DummyData_u32));
      Assert(v_DummyData_u32 <= 255); // for R7, only 1 bite enums supported
      b_Value_rx = static_cast<T>(v_DummyData_u32);
    }
    else
    {
      v_DummyData_u32 = static_cast<uint32_t>(b_Value_rx);
      file_po->write_u64(&v_DummyData_u32, sizeof(v_DummyData_u32));
    }
  }

  template<typename T>
  void serializeArray_v(T* b_Array_px, uint32_t& b_Size_u32) const
  {
    serialize_v(b_Size_u32);

    for (uint32_t v_I_u32 = 0U; (v_I_u32 < b_Size_u32); ++v_I_u32)
    {
      serialize_v(b_Array_px[v_I_u32]); //PRQA S 3706 // subscript operator necessary here
    }
  }

  template<typename T>
  void serializeFixedArray_v(T* b_Array_px, uint32_t i_Size_u32) const
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < i_Size_u32; ++v_I_u32)
    {
      serialize_v(b_Array_px[v_I_u32]); //PRQA S 3706 // subscript operator necessary here
    }
  }

  // osal data types
  void serializeString_v(osal::String& b_Value_ro) const;


  private:
    IFile* file_po;
    bool_t loading_b;
};


} // namespace osal


#endif // OSAL_IN_OUT_BINARY_H
