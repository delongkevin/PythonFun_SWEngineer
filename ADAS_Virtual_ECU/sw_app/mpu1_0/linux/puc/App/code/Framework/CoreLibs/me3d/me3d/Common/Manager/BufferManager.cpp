#include "BufferManager.h"

namespace me3d
{

BufferManager::BufferManager()
  : IManager()
{
}

BufferManager::~BufferManager()
{
}

bool BufferManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  return (NULL != renderEngine_po);
}

bool_t BufferManager::isEnabled_b()
{
  return true;
}

VertexBuffer* BufferManager::createVertexBuffer_po(const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv /*= NULL*/)
{
  VertexBuffer* v_VertexBuffer_po = getNewVertexBuffer_po(); 

  bool v_Success_b = v_VertexBuffer_po->create_b(renderEngine_po, i_Desc_rs, i_InitialData_pv);
  Assert(v_Success_b);

  return v_VertexBuffer_po;
}

IndexBuffer* BufferManager::createIndexBuffer_po(const IndexBufferDesc_s& i_Desc_rs, const void* i_InititalData_pv /*= NULL*/)
{
  IndexBuffer* v_IndexBuffer_po = getNewIndexBuffer_po(); 

  bool v_Success_b = v_IndexBuffer_po->create_b(i_Desc_rs, i_InititalData_pv);
  Assert(v_Success_b);

  return v_IndexBuffer_po;
}

void BufferManager::releaseVertexBuffer_v(VertexBuffer* b_VertexBuffer_po)
{
  Assert(NULL != b_VertexBuffer_po);

  b_VertexBuffer_po->release_v();
}

void BufferManager::releaseIndexBuffer_v(IndexBuffer* b_IndexBuffer_po)
{
  Assert(NULL != b_IndexBuffer_po);

  b_IndexBuffer_po->release_v();
}

} // namspace me3d