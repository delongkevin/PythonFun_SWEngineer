#include "IndexBufferVK.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

namespace me3d
{
  IndexBufferVK::IndexBufferVK()
    : IndexBuffer()
  {

  }

  IndexBufferVK::~IndexBufferVK()
  {

  }

  bool_t IndexBufferVK::create_b(const IndexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
  {


    return true;
  }

  void IndexBufferVK::release_v()
  {

  }

  void IndexBufferVK::set_v()
  {

  }

  void IndexBufferVK::updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv)
  {

  }

} // namespace me3d

#endif // RE_USE_VULKAN