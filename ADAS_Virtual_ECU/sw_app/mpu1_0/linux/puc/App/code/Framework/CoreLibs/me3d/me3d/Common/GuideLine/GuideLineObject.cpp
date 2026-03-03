#include "GuideLineObject.h"


#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Resources/VertexDeclarationTypes.h"

// PRQA S 5118 EOF // C++ 14 Autosar standard permits.
// PRQA S 3054 EOF // Flag handling.
// PRQA S 3710 EOF // Flag handling.
// PRQA S 3222 EOF // no modification
// PRQA S 3706 EOF // used to create vertices and indices

namespace me3d
{

  GuideLineObject::GuideLineObject()
    : renderEngine_po(NULL)
    , vertexBuffer_po(NULL)
    , indexBuffer_po(NULL)
    , indices_au16(NULL)
    , vertices_as(NULL)
    , indexCount_u32(0U)
    , bounds_s()
  {
  }

  GuideLineObject::~GuideLineObject()
  {

  }

  bool_t GuideLineObject::create_b(RenderEngine* b_RenEng_po, const GuideLineObjectDesc_s& i_Desc_rs)
  {
    renderEngine_po = b_RenEng_po;
    desc_s = i_Desc_rs;

    return update_b(e_GlufAll);
  }

  void GuideLineObject::release_v()
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

    if (NULL != vertices_as)
    {
      delete[] vertices_as;
      vertices_as = NULL;
    }

    if (NULL != indices_au16)
    {
      delete[] indices_au16;
      indices_au16 = NULL;
    }
  }

  bool_t GuideLineObject::update_b(uint32_t i_Flags_u32)
  {
    bool_t v_ValidInput_b = ((desc_s.path_ao.size() % 2) == 0) && (desc_s.path_ao.size() >= 4); 

    if (true == v_ValidInput_b)
    {
      if (i_Flags_u32 & e_GlufVertices)
      {
        createVertices_v();
      }

      if (i_Flags_u32 & e_GlufIndices)
      {
        createIndices_v();
      }

      if ((i_Flags_u32 & e_GlufVertices ) || (i_Flags_u32 & e_GlufIndices))
      {
        bool v_UpdateIndices_b = (i_Flags_u32 & e_GlufIndices)       == e_GlufIndices;
        bool v_ResizeBuffers_b = (i_Flags_u32 & e_GlufResizeBuffers) == e_GlufResizeBuffers;

        createBuffers_v(v_UpdateIndices_b, v_ResizeBuffers_b);
      }
    }

    return v_ValidInput_b;
  }

  bool_t GuideLineObject::updatePath_b(const mepl::vector<Vector3f>& i_Path_ro)
  {
    uint32_t v_Flags_u32 = e_GlufVertices;

    if (desc_s.path_ao.size() != i_Path_ro.size())
    {
      v_Flags_u32 |= e_GlufIndices;
      v_Flags_u32 |= e_GlufResizeBuffers;
    }

    desc_s.path_ao = i_Path_ro;

    return update_b(v_Flags_u32);
  }

  void GuideLineObject::createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b)
  {
    if ((true == i_ResizeBuffers_b) && (NULL != vertexBuffer_po))
    {
      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
      vertexBuffer_po = NULL;
    }

    if (NULL != vertexBuffer_po)
    {
      // update
      vertexBuffer_po->updateSubData_v(0, desc_s.path_ao.size() * sizeof(VertexPos_s), vertices_as);
    }
    else
    {
      // Create Vertex buffer
      VertexBufferDesc_s v_VbDesc_s;
      v_VbDesc_s.resourceUsage_e = e_RuDynamic;
      v_VbDesc_s.size_u32 = desc_s.path_ao.size() * sizeof(VertexPos_s);
      v_VbDesc_s.stride_u32 = sizeof(VertexPos_s);
      v_VbDesc_s.c_Layout_pc = "P3f";
      vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_VbDesc_s, vertices_as);
    }

    if (i_Indices_b)
    {
      if ((true == i_ResizeBuffers_b) && (NULL != indexBuffer_po))
      {
        renderEngine_po->getBufferManager_po()->releaseIndexBuffer_v(indexBuffer_po);
        indexBuffer_po = NULL;
      }

      if (NULL != indexBuffer_po)
      {
        // update old one
        indexBuffer_po->updateSubData_v(0, indexCount_u32 * sizeof(uint16_t), indices_au16);
      }
      else
      {
        // Create Index buffer
        IndexBufferDesc_s v_IbDesc_s;
        v_IbDesc_s.resourceUsage_e = e_RuStatic;
        v_IbDesc_s.size_u32 = indexCount_u32 * sizeof(uint16_t);
        indexBuffer_po = renderEngine_po->getBufferManager_po()->createIndexBuffer_po(v_IbDesc_s, indices_au16);
      }
    }
  }

  void GuideLineObject::createVertices_v()
  {
    size_t v_Length_t = desc_s.path_ao.size();
    size_t v_HalfLength_t = v_Length_t / 2;
    size_t v_StartPos_u32 = 0;
    sint32_t v_Iterator_s32 = 1;
    bounds_s.init_v();

    if (NULL != vertices_as)
    {
      delete[] vertices_as;
      vertices_as = NULL;
    }

    if(v_Length_t >= 4)
    {
      // only approximation, does not handle all cases -> check Y for singleView and Z for BowlView
      // Better solution -> calculate direction vector
      if(((desc_s.path_ao[1].getPosY() - desc_s.path_ao[0].getPosY()) > 0 )
      || ((desc_s.path_ao[1].getPosZ() - desc_s.path_ao[0].getPosZ()) < 0))
      {
        v_Iterator_s32 = -1;
        v_StartPos_u32 = v_HalfLength_t - 1;
      }
    }

    vertices_as = new VertexPos_s[desc_s.path_ao.size()]; 

    for (size_t v_I_u32 = 0; v_I_u32 < v_HalfLength_t; v_I_u32++)
    {
      const Vector3f& v_PathPoint_ro = desc_s.path_ao[v_StartPos_u32 + v_I_u32 * v_Iterator_s32];

      // begin vertex
      vertices_as[v_I_u32].position_af32[0] = v_PathPoint_ro.getPosX(); 
      vertices_as[v_I_u32].position_af32[1] = v_PathPoint_ro.getPosY();
      vertices_as[v_I_u32].position_af32[2] = v_PathPoint_ro.getPosZ();

      const Vector3f& v_PathPoint2_ro = desc_s.path_ao[(v_StartPos_u32 + v_HalfLength_t) + v_I_u32 * v_Iterator_s32];

      // begin vertex
      vertices_as[v_HalfLength_t + v_I_u32].position_af32[0] = v_PathPoint2_ro.getPosX(); 
      vertices_as[v_HalfLength_t + v_I_u32].position_af32[1] = v_PathPoint2_ro.getPosY();
      vertices_as[v_HalfLength_t + v_I_u32].position_af32[2] = v_PathPoint2_ro.getPosZ();

      // update bounds
      bounds_s.update_v(v_PathPoint_ro);
      bounds_s.update_v(v_PathPoint2_ro);
    }
  }

  void GuideLineObject::createIndices_v()
  {
    uint32_t v_Offset_u32 = 0U;

    if (NULL != indices_au16)
    {
      delete[] indices_au16;
      indices_au16 = NULL;
    }

    const uint32_t c_XLength_u32 = desc_s.path_ao.size();
    const uint32_t c_HalfLength_u32 = desc_s.path_ao.size() / 2U;
    const uint32_t c_NumIndices_u32 = c_XLength_u32 + 1; // + 1 for degeneration of last index

    indices_au16 = new uint16_t[c_NumIndices_u32];

    for (uint32_t v_X_u32 = 0U; v_X_u32 < c_HalfLength_u32; ++v_X_u32) 
    {
      uint16_t v_LastIdx_u16 = static_cast<uint16_t>((c_XLength_u32 - 1) - v_X_u32);     // 8 - 1 - 0 = 7, 8 - 1 - 1 = 6
      indices_au16[v_Offset_u32] = v_LastIdx_u16;
      ++v_Offset_u32;

      // One part of the strip
      indices_au16[v_Offset_u32] = static_cast<uint16_t>(v_X_u32);
      ++v_Offset_u32;

      // degenerate
      if (c_HalfLength_u32 == v_LastIdx_u16)
      {
        indices_au16[v_Offset_u32] = v_LastIdx_u16;
        ++v_Offset_u32;
      }
    }

    indexCount_u32 = v_Offset_u32;
  }

} // namespace me3d
