#include "FileUtils.h"

namespace me3d
{
  MEString FileUtils::getExtension_o(const MEString& i_String_ro)
  {
    MEString v_Extension_o;

    uint32_t v_Length_u32 = i_String_ro.getLength_u32();

    uint32_t v_DotIndex_u32 = i_String_ro.getLength_u32();
    v_DotIndex_u32 = i_String_ro.reverseFind_u32('.');
    if (MEString::c_Npos_u32 != v_DotIndex_u32)
    {
      for (uint32_t v_I_u32 = v_DotIndex_u32 + 1; v_I_u32 < v_Length_u32; ++v_I_u32)
      {
        v_Extension_o += i_String_ro.getAt_c(v_I_u32);
      }
    }

    return v_Extension_o;
  }

  MEString FileUtils::getFileName_o(const MEString& i_String_ro, bool i_NoExtension_b, char i_PathSeparator_c)
  {
    MEString v_FileName_o;

    uint32_t v_Length_u32 = i_String_ro.getLength_u32();
    uint32_t v_LastSeparator_u32 = i_String_ro.reverseFind_u32(i_PathSeparator_c);

    if (MEString::c_Npos_u32 != v_LastSeparator_u32)
    {
      v_LastSeparator_u32 += 1U;
    }
    else
    {
      v_LastSeparator_u32 = 0U;
    }

    uint32_t v_LastIndex_u32 = v_Length_u32;
    if (true == i_NoExtension_b)
    {
      uint32_t v_DotIndex_u32 = i_String_ro.reverseFind_u32('.');

      if (MEString::c_Npos_u32 != v_DotIndex_u32)
      {
        v_LastIndex_u32 = v_DotIndex_u32;
      }
    }

    for (uint32_t v_I_u32 = v_LastSeparator_u32; v_I_u32 < v_LastIndex_u32; ++v_I_u32)
    {
      v_FileName_o += i_String_ro.getAt_c(v_I_u32); 
    }

    return v_FileName_o;
  }

} // namespace me3d


