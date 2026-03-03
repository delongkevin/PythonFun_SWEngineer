#include "Common/Debug/DebugRenderObject.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"

namespace me3d
{

DebugRenderObject::DebugRenderObject()
  : vertexBuffer_po(NULL)
  , indexBuffer_po(NULL)
  , numVertices_u32(0U)
  , numIndices_u32(0U)
  , primitiveType_e(e_PtCount)
  , world_o()
  , color_o()
{

}

DebugRenderObject::~DebugRenderObject()
{
}

void DebugRenderObject::release_v(const RenderEngine* i_RenEng_po)
{
  Assert(NULL != i_RenEng_po);
  releaseVertexBuffer_v(i_RenEng_po);
  releaseIndexBuffer_v(i_RenEng_po);

  numVertices_u32 = 0U;
  numIndices_u32  = 0U;
}

void DebugRenderObject::releaseVertexBuffer_v(const RenderEngine* i_RenEng_po)
{
  Assert(NULL != i_RenEng_po);
  if (NULL != vertexBuffer_po)
  {
    i_RenEng_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
    vertexBuffer_po = NULL;
  }
}

void DebugRenderObject::releaseIndexBuffer_v(const RenderEngine* i_RenEng_po)
{
  Assert(NULL != i_RenEng_po);
  if (NULL != indexBuffer_po)
  {
    i_RenEng_po->getBufferManager_po()->releaseIndexBuffer_v(indexBuffer_po);
    indexBuffer_po = NULL;
  }
}

void DebugRenderObject::fillVertexBuffer_v(const RenderEngine* i_RenEng_po, const float32_t* i_Vertices_pf32, uint32_t i_NumVertices_u32)
{
  numVertices_u32 = i_NumVertices_u32;

  VertexBufferDesc_s v_Desc_s;
  v_Desc_s.c_Layout_pc  = "P3f";
  v_Desc_s.stride_u32 = 3 * sizeof(float32_t);
  v_Desc_s.size_u32   = numVertices_u32 * v_Desc_s.stride_u32;
  
  releaseVertexBuffer_v(i_RenEng_po);

  vertexBuffer_po = i_RenEng_po->getBufferManager_po()->createVertexBuffer_po(v_Desc_s, i_Vertices_pf32);
}

void DebugRenderObject::fillIndexBuffer_v(const RenderEngine* i_RenEng_po, const uint16_t* i_Indices_pu16, uint32_t i_NumIndices_u32)
{
  numIndices_u32 = i_NumIndices_u32;

  IndexBufferDesc_s v_Desc_s;
  v_Desc_s.size_u32   = numIndices_u32 * sizeof(uint16_t);

  releaseIndexBuffer_v(i_RenEng_po);

  indexBuffer_po = i_RenEng_po->getBufferManager_po()->createIndexBuffer_po(v_Desc_s, i_Indices_pu16);
}

void DebugRenderObject::setParams_v(const Matrix4f& i_World_ro, const Color& i_Color_ro, PrimitiveType_e i_PrimType_e)
{
  world_o         = i_World_ro;
  color_o         = i_Color_ro;
  primitiveType_e = i_PrimType_e;
}

} // namespace me3d