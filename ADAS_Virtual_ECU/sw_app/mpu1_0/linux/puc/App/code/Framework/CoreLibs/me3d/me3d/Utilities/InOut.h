#ifndef IN_OUT_H
#define IN_OUT_H

#include <platform/PlatformAPI.h>
#include <osal/io/IFile.h>

namespace me3d
{


class InOut
{
public:
  InOut();
  ~InOut();

  void create_b(osal::IFile* i_File_po, bool i_IsLoading_b);
  void release_b();

  bool isLoading_b() const;

  template <typename T>
  void serialize_v(T& b_Value_rx);

  template <typename T>
  void serializeVector_v(mepl::vector<T>& b_Vector_ro)
  {
    uint32_t v_Size_u32 = b_Vector_ro.size();
    serialize_v(v_Size_u32);

    if (true == loading_b)
    {
      b_Vector_ro.resize(v_Size_u32);
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < v_Size_u32; ++v_I_u32)
    {
      serialize_v(b_Vector_ro[v_I_u32]);
    }
  }

  template<typename T>
  void serializeArray_v(T* i_Array_px, uint32_t i_Size_u32)
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < i_Size_u32; ++v_I_u32)
    {

      // PRQA S 3706 1 // intended here to use subscript operator.
      serialize_v(i_Array_px[v_I_u32]);
    }
  }

  void serializeFixedArray_v(uint8_t* i_Array_pu8, uint32_t i_Size_u32);

  template <typename T>
  void serializeEnum_v(T& b_Value_rx)
  {
    sint32_t v_EnumValue_s32 = static_cast<sint32_t>(b_Value_rx);
    serialize_v(v_EnumValue_s32);

    if (true == loading_b)
    {
      b_Value_rx = static_cast<T>(v_EnumValue_s32);
    }
  }


private:
   template <typename T>
   void serializeDefault_v(T& b_Value_rx)
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

private:
  osal::IFile* file_po;
  bool loading_b;

};

} // namespace me3d

#endif //IN_OUT_H
