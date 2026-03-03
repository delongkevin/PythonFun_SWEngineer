#include "InOut.h"

namespace osal
{
  InOut::InOut()
    : file_po(NULL)
    , loading_b(false)
  {

  }

  InOut::~InOut()
  {
    file_po   = NULL;
    loading_b = false;
  }

  bool_t InOut::create_b(IFile* b_File_po, bool i_IsLoading_b)
  {
    file_po   = b_File_po;
    loading_b = i_IsLoading_b;

    Assert(file_po);
    return NULL != file_po;
  }

  bool_t InOut::isLoading_b() const
  {
    return loading_b;
  }

  void InOut::serializeString_v(osal::String& b_Value_ro) const
  {
    uint32_t v_Length_u32 = 0U;
    if (true == isLoading_b())
    {
      serialize_v(v_Length_u32);
    }
    else
    {
      v_Length_u32 = b_Value_ro.getLength_u32();
      serialize_v(v_Length_u32);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < v_Length_u32; ++v_I_u32)
    {
      if (true == isLoading_b())
      {
        char_t v_Char_c;
        serialize_v(v_Char_c);
        b_Value_ro += v_Char_c;

        if ((v_I_u32 + 1) >= v_Length_u32)
        {
          b_Value_ro += '\0';
        }

      }
      else
      {
        char_t v_Char_c = b_Value_ro.getAt_c(v_I_u32);
        serialize_v(v_Char_c);
      }
    }
  }
} // namespace osal
