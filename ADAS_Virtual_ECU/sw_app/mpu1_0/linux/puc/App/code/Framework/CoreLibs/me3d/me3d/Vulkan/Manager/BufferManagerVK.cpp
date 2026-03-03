#include "BufferManagerVK.h"

// PRQA S 1051 EOF // C++ comments remind me for todos Vulakn port not implemented yet

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

namespace me3d
{
  BufferManagerVK::BufferManagerVK()
    : BufferManager()
  {

  }

  BufferManagerVK::~BufferManagerVK()
  {

  }

  void BufferManagerVK::release_v()
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxVertexBuffers_u32; ++v_I_u32) 
    {
      vertexBufferPool_ao[v_I_u32].release_v();
    }

    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxIndexBuffers_u32; ++v_I_u32) 
    {
      indexBufferPool_ao[v_I_u32].release_v();
    }
  }

  void BufferManagerVK::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
  {

  }

  void BufferManagerVK::beginFrame_v()
  {

  }

  void BufferManagerVK::preRender_v()
  {

  }

  VertexBuffer* BufferManagerVK::getNewVertexBuffer_po()
  {
    VertexBuffer* v_NewBuffer_po = NULL;

    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxVertexBuffers_u32; ++v_I_u32) 
    {
      VertexBufferVK* v_Current_po = &vertexBufferPool_ao[v_I_u32];

      if (v_Current_po->getID_u32() == 0U)
      {
        v_NewBuffer_po = v_Current_po;
        break;
      }
    }

    Assert(NULL != v_NewBuffer_po);
    return v_NewBuffer_po;
  }

  IndexBuffer* BufferManagerVK::getNewIndexBuffer_po()
  {
    IndexBuffer* v_NewBuffer_po = NULL;

    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxIndexBuffers_u32; ++v_I_u32)
    {
      IndexBufferVK* v_Current_po = &indexBufferPool_ao[v_I_u32];

      // TODO VULKAN: Implement
      Assert(false);
      //if (v_Current_po->getID_u32() == 0U)
      {
        v_NewBuffer_po = v_Current_po;
        break;
      }
    }

    Assert(NULL != v_NewBuffer_po);
    return v_NewBuffer_po;
  }

} // namespace me3d

#endif // RE_USE_VULKAN