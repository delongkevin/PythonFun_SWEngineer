#include "VertexBufferVK.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

namespace me3d
{
  VertexBufferVK::VertexBufferVK()
    : VertexBuffer()
  {

  }

  VertexBufferVK::~VertexBufferVK()
  {

  }

  bool VertexBufferVK::create_b(RenderEngine* b_RenderEngine_po, const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
  {
    bool v_Success_b = VertexBuffer::create_b(b_RenderEngine_po, i_Desc_rs);


    return v_Success_b;
  }

  void VertexBufferVK::release_v()
  {

  }

  void VertexBufferVK::bind_v() const
  {

  }

  uint32_t VertexBufferVK::getID_u32() const
  {


    return 0;
  }

  void VertexBufferVK::updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv)
  {

  }

} // namespace me3d

#endif // RE_USE_VULKAN