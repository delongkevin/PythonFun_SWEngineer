#include "OpenGL/Manager/BufferManagerGL.h"

 

namespace me3d
{

BufferManagerGL::BufferManagerGL()
  : BufferManager()
{

}

BufferManagerGL::~BufferManagerGL()
{

}

void BufferManagerGL::release_v()
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

void BufferManagerGL::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void BufferManagerGL::beginFrame_v()
{

}

void BufferManagerGL::preRender_v()
{

}

VertexBuffer* BufferManagerGL::getNewVertexBuffer_po()
{
  VertexBuffer* v_NewBuffer_po = NULL;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxVertexBuffers_u32; ++v_I_u32) 
  {
    VertexBufferGL* v_Current_po = &vertexBufferPool_ao[v_I_u32];

    if (v_Current_po->getID_u32() == 0U)
    {
      v_NewBuffer_po = v_Current_po;
      break;
    }
  }

  Assert(NULL != v_NewBuffer_po);
  return v_NewBuffer_po;
}

IndexBuffer* BufferManagerGL::getNewIndexBuffer_po()
{
  IndexBuffer* v_NewBuffer_po = NULL;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxIndexBuffers_u32; ++v_I_u32)
  {
    IndexBufferGL* v_Current_po = &indexBufferPool_ao[v_I_u32];

    if (v_Current_po->getID_u32() == 0U)
    {
      v_NewBuffer_po = v_Current_po;
      break;
    }
  }

  Assert(NULL != v_NewBuffer_po);
  return v_NewBuffer_po;
}

} // namespace me3d