#include "InOut.h"

#include <osal/io/IFile.h>

#include "MeclTypeDefs.h"
#include "Math/Color.h"
#include "mecl/math/Math.h"

namespace me3d
{

InOut::InOut()
  : file_po(NULL)
  , loading_b(false)
{

}

InOut::~InOut()
{

}

void InOut::create_b(osal::IFile* i_File_po, bool i_IsLoading_b)
{
  file_po   = i_File_po;
  loading_b = i_IsLoading_b;
}

void InOut::release_b()
{
  file_po     = NULL;
  loading_b = false;
}

bool InOut::isLoading_b() const
{
  return loading_b;
}

void InOut::serializeFixedArray_v(uint8_t* i_Array_pu8, uint32_t i_Size_u32)
{
  uint64_t v_Offset_u32 = 0U;
  uint64_t total_bytes_written = 0;

  uint64_t v_ChunkSize_u32 = 4096U;

  uint8_t* v_Pos_pu8 = i_Array_pu8;


  while (v_Offset_u32 < i_Size_u32)
  {
    uint32_t v_BytesWritten_u32 = 0U;

    uint32_t bytes_to_write = mecl::math::min_x(v_ChunkSize_u32, (uint64_t)i_Size_u32 - total_bytes_written);

    if (true == loading_b)
    {
      v_BytesWritten_u32 = file_po->read_u64(v_Pos_pu8, bytes_to_write);
    }
    else
    {
      v_BytesWritten_u32 = file_po->write_u64(v_Pos_pu8, bytes_to_write);
    }

    v_Offset_u32 += v_BytesWritten_u32;
    v_Pos_pu8 += v_BytesWritten_u32;
    total_bytes_written += v_BytesWritten_u32;
  }
}

template <>
void InOut::serialize_v<bool>(bool& b_Value_rb)
{
  serializeDefault_v(b_Value_rb);
}

template <>
void InOut::serialize_v<char>(char& b_Value_rc)
{
  serializeDefault_v(b_Value_rc);
}

template <>
void InOut::serialize_v<sint8_t>(sint8_t& b_Value_rs8)
{
  serializeDefault_v(b_Value_rs8);
}

template <>
void InOut::serialize_v<sint16_t>(sint16_t& b_Value_rs16)
{
  serializeDefault_v(b_Value_rs16);
}

template <>
void InOut::serialize_v<sint32_t>(sint32_t& b_Value_rs32)
{
  serializeDefault_v(b_Value_rs32);
}

template <>
void InOut::serialize_v<sint64_t>(sint64_t& b_Value_rs64)
{
  serializeDefault_v(b_Value_rs64);
}

template <>
void InOut::serialize_v<uint8_t>(uint8_t& b_Value_ru8)
{
  serializeDefault_v(b_Value_ru8);
}

template <>
void InOut::serialize_v<uint16_t>(uint16_t& b_Value_ru16)
{
  serializeDefault_v(b_Value_ru16);
}

template <>
void InOut::serialize_v<uint32_t>(uint32_t& b_Value_ru32)
{
  serializeDefault_v(b_Value_ru32);
}

template <>
void InOut::serialize_v<uint64_t>(uint64_t& b_Value_ru64)
{
  serializeDefault_v(b_Value_ru64);
}

template <>
void InOut::serialize_v<float32_t>(float32_t& b_Value_rf32)
{
  serializeDefault_v(b_Value_rf32);
}

template <>
void InOut::serialize_v<float64_t>(float64_t& b_Value_rf64)
{
  serializeDefault_v(b_Value_rf64);
}

// mecl data types
template <>
void InOut::serialize_v<MEString>(MEString& b_Value_ro)
{
  uint32_t v_Length_u32 = 0U;
  if (true == isLoading_b())
  {
    serialize_v(v_Length_u32);
  }
  else
  {
    v_Length_u32 = b_Value_ro.getSize_t();
    serialize_v(v_Length_u32);
  }

  for (uint32_t v_I_u32 = 0U; v_I_u32 < v_Length_u32; ++v_I_u32)
  {
    if (true == isLoading_b())
    {
      char_t v_Char_c;
      serializeDefault_v(v_Char_c);
      b_Value_ro.setAt_v(v_I_u32, v_Char_c);

      if (v_I_u32 + 1 >= v_Length_u32)
      {
        b_Value_ro.setAt_v(v_I_u32 + 1, '\0');
      }

    }
    else
    {
      char_t v_Char_c = b_Value_ro.getAt_c(v_I_u32);
      serializeDefault_v(v_Char_c);
    }
  }
}

template <>
void InOut::serialize_v<Vector2f>(Vector2f& b_Value_ro)
{
  serialize_v(b_Value_ro(0));
  serialize_v(b_Value_ro(1));
}

template <>
void InOut::serialize_v<Vector2f::Config_s>(Vector2f::Config_s& b_Value_ro)
{
  serialize_v(b_Value_ro.cVal_ax[0]);
  serialize_v(b_Value_ro.cVal_ax[1]);
}

template <>
void InOut::serialize_v<Vector3f>(Vector3f& b_Value_ro)
{
  serialize_v(b_Value_ro(0));
  serialize_v(b_Value_ro(1));
  serialize_v(b_Value_ro(2));
}

template <>
void InOut::serialize_v<Vector3f::Config_s>(Vector3f::Config_s& b_Value_ro)
{
  serialize_v(b_Value_ro.cVal_ax[0]);
  serialize_v(b_Value_ro.cVal_ax[1]);
  serialize_v(b_Value_ro.cVal_ax[2]);
}

template <>
void InOut::serialize_v<Vector4f>(Vector4f& b_Value_ro)
{
  serialize_v(b_Value_ro(0));
  serialize_v(b_Value_ro(1));
  serialize_v(b_Value_ro(2));
  serialize_v(b_Value_ro(3));
}

template <>
void InOut::serialize_v<Color>(Color& b_Value_ro)
{
  serialize_v(b_Value_ro[0]);
  serialize_v(b_Value_ro[1]);
  serialize_v(b_Value_ro[2]);
  serialize_v(b_Value_ro[3]);
}

template <>
void InOut::serialize_v<Quaternionf>(Quaternionf& b_Value_ro)
{
  float32_t v_X_f32 = b_Value_ro.getX();
  float32_t v_Y_f32 = b_Value_ro.getY();
  float32_t v_Z_f32 = b_Value_ro.getZ();
  float32_t v_W_f32 = b_Value_ro.getW();

  serialize_v(v_X_f32);
  serialize_v(v_Y_f32);
  serialize_v(v_Z_f32);
  serialize_v(v_W_f32);

  if (true == loading_b)
  {
    b_Value_ro = Quaternionf(v_X_f32, v_Y_f32, v_Z_f32, v_W_f32);
  }

}

template <>
void InOut::serialize_v<Matrix4f>(Matrix4f& b_Value_ro)
{
  serialize_v(b_Value_ro(0, 0));
  serialize_v(b_Value_ro(0, 1));
  serialize_v(b_Value_ro(0, 2));
  serialize_v(b_Value_ro(0, 3));

  serialize_v(b_Value_ro(1, 0));
  serialize_v(b_Value_ro(1, 1));
  serialize_v(b_Value_ro(1, 2));
  serialize_v(b_Value_ro(1, 3));

  serialize_v(b_Value_ro(2, 0));
  serialize_v(b_Value_ro(2, 1));
  serialize_v(b_Value_ro(2, 2));
  serialize_v(b_Value_ro(2, 3));

  serialize_v(b_Value_ro(3, 0));
  serialize_v(b_Value_ro(3, 1));
  serialize_v(b_Value_ro(3, 2));
  serialize_v(b_Value_ro(3, 3));
}


} // namespace me3d
