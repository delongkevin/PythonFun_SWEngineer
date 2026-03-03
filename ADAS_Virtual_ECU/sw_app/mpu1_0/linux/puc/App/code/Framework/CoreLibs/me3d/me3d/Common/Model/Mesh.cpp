#include "Common/Model/Mesh.h"

#include "Common/Device/Device3DTypes.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/MaterialManager.h"

namespace me3d
{

  Mesh::Mesh()
    : renderEngine_po(NULL)
    , vertexBuffer_po(NULL)
    , indexBuffer_po(NULL)
    , vertexCount_u32(0U)
    , indexCount_u32(0U)
  {

  }

  Mesh::~Mesh()
  {

  }

  void Mesh::init_v(RenderEngine* b_RenderEngine_po, const MeshData_s& i_MeshData_rs)
  {
    renderEngine_po = b_RenderEngine_po;
    vertexCount_u32 = i_MeshData_rs.vertexCount_u32;
    indexCount_u32  = i_MeshData_rs.indexCount_u32;

    Assert(NULL != renderEngine_po);
    Assert(vertexCount_u32 > 0U);
    Assert(indexCount_u32 > 0U);

    // Vertex Buffer
    if (NULL == vertexBuffer_po)
    {
      VertexBufferDesc_s v_VbDesc_s;
      v_VbDesc_s.stride_u32 = i_MeshData_rs.getStride_u32();
      v_VbDesc_s.size_u32 = vertexCount_u32 * i_MeshData_rs.getStride_u32();
      v_VbDesc_s.c_Layout_pc = i_MeshData_rs.getLayout_pc();

      // don't copy vertices for now
      vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_VbDesc_s, i_MeshData_rs.getVertices_pv());
    }

    // Index Buffer
    if (NULL == indexBuffer_po)
    {
      IndexBufferDesc_s v_IbDesc_s;
      v_IbDesc_s.size_u32 = indexCount_u32 * sizeof(uint16_t);

      indexBuffer_po = renderEngine_po->getBufferManager_po()->createIndexBuffer_po(v_IbDesc_s, i_MeshData_rs.indices_pu16);
    }

    // update bounding box
    for (uint32_t v_I_u32 = 0U; v_I_u32 < vertexCount_u32; ++v_I_u32)
    {
      bounds_s.update_v(i_MeshData_rs.getPosition_o(v_I_u32));
    }
  }

  void Mesh::release_v()
  {
    if (NULL != vertexBuffer_po)
    {
      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
      vertexBuffer_po = NULL;
    }

    if (NULL != indexBuffer_po)
    {
      renderEngine_po->getBufferManager_po()->releaseIndexBuffer_v(indexBuffer_po);
      indexBuffer_po = NULL;
    }

    vertexCount_u32 = 0;
    indexCount_u32 = 0;

    // TODO: Material Ref
 

  }

  void Mesh::set_v()const
  {
    Assert(NULL != vertexBuffer_po);
    Assert(NULL != indexBuffer_po);
    Assert(0 != indexCount_u32);
    Assert(0 != vertexCount_u32);

    vertexBuffer_po->set_v(0);
    indexBuffer_po->set_v();

  }

} // namespace me3d
