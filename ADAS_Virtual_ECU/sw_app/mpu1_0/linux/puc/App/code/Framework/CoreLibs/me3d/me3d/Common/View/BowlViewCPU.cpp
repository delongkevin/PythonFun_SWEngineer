#include "Common/View/BowlViewCPU.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Renderer/DebugRenderer.h"

#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/Resources/Texture.h"
#include "Math/MathLib.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"

// PRQA S 5118 EOF // C++14 Autosar Standard permits
// PRQA S 3706 EOF // Subscript operator is used to fill vertices and indices.
// PRQA S 3054 EOF // Implicit bool conversion is fine for flags
// PRQA S 3710 EOF // Enum as operand intended


namespace me3d
{

BowlViewCPU::BowlViewCPU()
  : BaseBowlView()
  , effect_po(NULL)
  , renderStateAlphaBlend_po(NULL)
  , renderStateDisableDepth_po(NULL)
  , constantWVP_po(NULL)
  , constantTex0_po(NULL)
  , constantTex1_po(NULL)
  , constantTex2_po(NULL)
  , constantTex3_po(NULL)
{

}

BowlViewCPU::~BowlViewCPU()
{

}

VertexBowlViewCPU_s* BowlViewCPU::getVertex_ps(float32_t i_X_f32, float32_t i_Z_f32)
{
  VertexBowlViewCPU_s* v_Result_ps = NULL;

  mepl::UnusedParameter(i_X_f32);
  mepl::UnusedParameter(i_Z_f32);
 
  ME_Debugger_F_Printf_v("BowlViewCPU - Implement getVertex \n");

  return v_Result_ps;
}

bool BowlViewCPU::getHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t& o_Height_rf32)
{
  VertexBowlViewCPU_s* v_Vertex_ps = getVertex_ps(i_X_f32, i_Z_f32);

  bool v_Valid_b = v_Vertex_ps != NULL;
  if (true == v_Valid_b)
  {
    o_Height_rf32 = v_Vertex_ps->position_af32[1];
  }

  return v_Valid_b;
}

bool BowlViewCPU::setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32)
{
  VertexBowlViewCPU_s* v_Vertex_ps = getVertex_ps(i_X_f32, i_Z_f32);

  bool v_Valid_b = v_Vertex_ps != NULL;

  return v_Valid_b;
}

bool BowlViewCPU::intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)
{

  uint32_t v_Cnt_u32 = 0U;

  return v_Cnt_u32 != 1000U;
}

bool_t BowlViewCPU::create_b(const BowlViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po, EffectFileRenderStateBlock* i_RSBAlpha_po, EffectFileRenderStateBlock* i_RSBNoDepth_po)
{
  desc_s = i_Desc_rs;
  renderEngine_po = b_RenderEngine_po;

  // create effect and Texture constants
  effect_po                       = renderEngine_po->getShaderManager_po()->createShader_po(getShader_e());
  constantWVP_po                  = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWVPMatrix", e_CtMatrix4, 1U));
  constantTex0_po                 = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cBowlViewTex0", e_CtTexture, 1U));
  constantTex1_po                 = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cBowlViewTex1", e_CtTexture, 1U));
  constantTex2_po                 = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cBowlViewTex2", e_CtTexture, 1U));
  constantTex3_po                 = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cBowlViewTex3", e_CtTexture, 1U));

  // obscuration zone, re-use guide line shader
  obscurationZone_s.effect_po               = renderEngine_po->getShaderManager_po()->createShader_po(e_ShaderGuideLine);
  obscurationZone_s.constantColor_po        = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuideLineColor", e_CtFloat4, 1U));
  obscurationZone_s.constantGuideLineWVP_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuideLineWVP", e_CtMatrix4, 1U));

  renderStateAlphaBlend_po    = i_RSBAlpha_po;
  renderStateDisableDepth_po  = i_RSBNoDepth_po;


  // Create all data
  update_v(e_VufAll);

  return true;
}

void BowlViewCPU::release_v()
{
  if (NULL != obscurationZone_s.vertexBuffer_po)
  {
    renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(obscurationZone_s.vertexBuffer_po);
    obscurationZone_s.vertexBuffer_po = NULL;
  }

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    if (NULL != v_Segment_ps->vertexBuffer_po)
    {
      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(v_Segment_ps->vertexBuffer_po);
      v_Segment_ps->vertexBuffer_po = NULL;
    }

    if (NULL != v_Segment_ps->indexBuffer_po)
    {
      renderEngine_po->getBufferManager_po()->releaseIndexBuffer_v(v_Segment_ps->indexBuffer_po);
      v_Segment_ps->indexBuffer_po = NULL;
    }

    if (NULL != v_Segment_ps->vertices_as)
    {
      delete[] v_Segment_ps->vertices_as;
      v_Segment_ps->vertices_as = NULL;
    }

    if (NULL != v_Segment_ps->indices_au16)
    {
      delete[] v_Segment_ps->indices_au16;
      v_Segment_ps->indices_au16 = NULL;
    }

    v_Segment_ps->realCamera_po = NULL;
  }
}

void BowlViewCPU::render_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    if ((NULL != v_Segment_ps->vertexBuffer_po) &&
        (NULL != v_Segment_ps->indexBuffer_po))
    {
      // Set constants
      const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();
      Matrix4f v_WVP_o;
      v_WVP_o = transform_o.getWorldMatrix_ro().mmulFast(c_VP_ro);
      constantWVP_po->setData_v(&v_WVP_o);

      constantTex0_po->setData_v(desc_s.textures_apo[v_I_u32]);

      v_Segment_ps->vertexBuffer_po->set_v(0);
      v_Segment_ps->indexBuffer_po->set_v();

      // front and rear will be alpha blended. left/right are drawn first
      if ((v_I_u32 == e_RcFront) || (v_I_u32 == e_RcRear))
      {
        effect_po->setRenderStateBlock_v(renderStateAlphaBlend_po);
      }
      else
      {
        effect_po->setRenderStateBlock_v(NULL);
      }

      // begin rendering
      effect_po->beginPass_b();

      renderEngine_po->getDevice_po()->drawIndexed_v(e_PtTriangleStrip, v_Segment_ps->indexCount_u32, 0U);

      // end rendering
      effect_po->endPass_v();
    }
  }

#if 0

  // render obscuration zone
  if ((NULL != obscurationZone_s.effect_po) &&
      (NULL != obscurationZone_s.vertexBuffer_po))
  {
    Color v_ObscurationColor_o = Color::Black;
    obscurationZone_s.constantColor_po->setData_v(&v_ObscurationColor_o);

    const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();
    Matrix4f v_WVP_o;
    v_WVP_o = transform_o.getWorldMatrix_ro().mmulFast(c_VP_ro);
    obscurationZone_s.constantGuideLineWVP_po->setData_v(&v_WVP_o);


    obscurationZone_s.vertexBuffer_po->set_v(0);

    // begin rendering


    obscurationZone_s.effect_po->setRenderStateBlock_v(renderStateDisableDepth_po);
    obscurationZone_s.effect_po->beginPass_b();

    renderEngine_po->getDevice_po()->draw_v(e_PtTriangleList, ObscurationZone_s::c_NumObscurationVertices_u32, 0U);

    // end rendering
    obscurationZone_s.effect_po->endPass_v();
  }

#endif

  if (true == renderStitching_b)
  {
    renderStitching_v();

    // draw obscuration bounds
    BBox3D_s v_ObscurBounds3D_s = BBox3D_s(Vector3f(obscurationZone_s.bounds_s.min_o(0), 0.0F, obscurationZone_s.bounds_s.min_o(1)),
                                           Vector3f(obscurationZone_s.bounds_s.max_o(0), 1.0F, obscurationZone_s.bounds_s.max_o(1)));
    renderEngine_po->getDebugRenderer_po()->drawBox_v(transform_o.getWorldMatrix_ro(), v_ObscurBounds3D_s.getCenter_o(), v_ObscurBounds3D_s.getExtent_o(), Color::White);
  }
}

void BowlViewCPU::createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b)
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
    sint32_t v_EndX_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

    sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
    sint32_t v_EndY_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

    v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
    v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

    uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
    uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);

    uint32_t v_NewSize_u32 = v_XLength_u32 * v_YLength_u32 * sizeof(VertexBowlViewCPU_s);

    if (NULL != v_Segment_ps->vertexBuffer_po)
    {
      uint32_t v_OldSize_u32 = v_Segment_ps->vertexBuffer_po->getDesc_rs().size_u32;
      i_ResizeBuffers_b = v_NewSize_u32 != v_OldSize_u32;

      i_Indices_b = true;
    }

    if ((true == i_ResizeBuffers_b) && (NULL != v_Segment_ps->vertexBuffer_po))
    {
      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(v_Segment_ps->vertexBuffer_po);
      v_Segment_ps->vertexBuffer_po = NULL;
    }

    if (NULL != v_Segment_ps->vertexBuffer_po)
    {
      // update
      v_Segment_ps->vertexBuffer_po->updateSubData_v(0, v_NewSize_u32, v_Segment_ps->vertices_as);
    }
    else
    {
      // Create Vertex buffer
      VertexBufferDesc_s v_VbDesc_s;
      v_VbDesc_s.size_u32 = v_NewSize_u32;
      v_VbDesc_s.stride_u32 = sizeof(VertexBowlViewCPU_s);
      v_VbDesc_s.c_Layout_pc = "P3f_T3f";
      v_Segment_ps->vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_VbDesc_s, v_Segment_ps->vertices_as);
    }

    if (i_Indices_b)
    {
      if ((true == i_ResizeBuffers_b) && (NULL != v_Segment_ps->indexBuffer_po))
      {
        renderEngine_po->getBufferManager_po()->releaseIndexBuffer_v(v_Segment_ps->indexBuffer_po);
        v_Segment_ps->indexBuffer_po = NULL;
      }

      if (NULL != v_Segment_ps->indexBuffer_po)
      {
        // update old one
        v_Segment_ps->indexBuffer_po->updateSubData_v(0, v_Segment_ps->indexCount_u32 * sizeof(uint16_t), v_Segment_ps->indices_au16);
      }
      else
      {
        // Create Index buffer
        IndexBufferDesc_s v_IbDesc_s;
        v_IbDesc_s.size_u32 = v_Segment_ps->indexCount_u32 * sizeof(uint16_t);
        v_Segment_ps->indexBuffer_po = renderEngine_po->getBufferManager_po()->createIndexBuffer_po(v_IbDesc_s, v_Segment_ps->indices_au16);
      }
    }
  }
}


// PRQA S 4020 1 // One more exit points makes this code more readable - don't compute if no valid real camera pointers are present.
void BowlViewCPU::update_v(uint32_t i_Flags_u32)
{
  Vector2f v_FrontAxisOffset = getFrontAxisOffset_o();
  desc_s.frontAxisOffsetX_f32 = v_FrontAxisOffset.getPosX();
  desc_s.frontAxisOffsetY_f32 = v_FrontAxisOffset.getPosY();

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];
    v_Segment_ps->realCamera_po = desc_s.realCams_apo[v_I_u32];

    if (NULL == v_Segment_ps->realCamera_po)
    {
      return;
    }
  }



  if (i_Flags_u32 & e_VufCamBounds)
  {
    createCameraBounds_v();

    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
    {
      BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];
      v_Segment_ps->bounds_o.min_o = cameraBounds_as[v_I_u32].min_o;
      v_Segment_ps->bounds_o.max_o = cameraBounds_as[v_I_u32].max_o;
    }
  }

  if (i_Flags_u32 & e_VufDefaultStitching)
  {
    createDefaultStitchingLines_v();
  }

  if (i_Flags_u32 & e_VufVertices)
  {
    createVertices_v();
  }

  if (i_Flags_u32 & e_VufDefaultObscuration)
  {
    createObscurationZone_v(true);
  }

  if (i_Flags_u32 & e_VufIndices)
  {
    createIndices_v();
  }

  if (i_Flags_u32 & e_VufStitching)
  {
    createStitching_v();
  }

  if ((i_Flags_u32 & e_VufVertices ) ||
      (i_Flags_u32 & e_VufIndices  ) ||
      (i_Flags_u32 & e_VufStitching)   )
  {
    createTexCoords_v();

    bool v_UpdateIndices_b = (i_Flags_u32 & e_VufIndices)       == e_VufIndices;
    bool v_ResizeBuffers_b = (i_Flags_u32 & e_VufResizeBuffers) == e_VufResizeBuffers;

    createBuffers_v(v_UpdateIndices_b, v_ResizeBuffers_b);
  }
}

void BowlViewCPU::setObscurationZone_v(const BBox2D_s& i_Bounds_rs)
{
  obscurationZone_s.bounds_s = i_Bounds_rs;

  createObscurationZone_v(false);
}

const BBox2D_s& BowlViewCPU::getObscurationZone_rs() const
{
  return obscurationZone_s.bounds_s;
}

Shaders_e BowlViewCPU::getShader_e()
{
  return e_ShaderBowlViewCPU;
}

void BowlViewCPU::createStitching_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    RealCamera_e v_CurrCam_e = static_cast<RealCamera_e>(v_I_u32);

    uint32_t v_Offset_u32 = 0U;

    sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
    sint32_t v_EndX_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

    sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
    sint32_t v_EndY_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

    v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
    v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

    uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
    uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);


    for (sint32_t v_Y_s32 = v_StartY_s32; v_Y_s32 < v_EndY_s32; ++v_Y_s32)
    {
      for (sint32_t v_X_s32 = v_StartX_s32; v_X_s32 < v_EndX_s32; ++v_X_s32)
      {
        Assert(v_Offset_u32 < (v_YLength_u32 * v_XLength_u32));

        VertexBowlViewCPU_s* v_Vertex_ps = &v_Segment_ps->vertices_as[v_Offset_u32];
        Vector2f v_Pos_o(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[2]);

        // Front
        bool v_FrontLeft_b  = stitchingAreas_as[e_SaFrontLeft].bounds_o.intersect_b(v_Pos_o);
        bool v_FrontRight_b = stitchingAreas_as[e_SaFrontRight].bounds_o.intersect_b(v_Pos_o);
        bool v_RearLeft_b   = stitchingAreas_as[e_SaRearLeft].bounds_o.intersect_b(v_Pos_o);
        bool v_RearRight_b  = stitchingAreas_as[e_SaRearRight].bounds_o.intersect_b(v_Pos_o);


        if (true == v_FrontLeft_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaFrontLeft].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaFrontLeft].line1_o.getY_f32(v_Pos_o.getPosX());

          float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);
          v_Vertex_ps->texCoords_af32[2] = v_Distance_f32;

        }
        else if (true == v_FrontRight_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaFrontRight].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaFrontRight].line1_o.getY_f32(v_Pos_o.getPosX());

          float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);
          v_Vertex_ps->texCoords_af32[2] = 1.0F - v_Distance_f32;
        }
        else if (true == v_RearLeft_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaRearLeft].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaRearLeft].line1_o.getY_f32(v_Pos_o.getPosX());

          float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);
          v_Vertex_ps->texCoords_af32[2] = v_Distance_f32;
        }
        else if (true == v_RearRight_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaRearRight].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaRearRight].line1_o.getY_f32(v_Pos_o.getPosX());

          float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);
          v_Vertex_ps->texCoords_af32[2] = 1.0F - v_Distance_f32;

        }
        else if ((e_RcFront == v_CurrCam_e) || (e_RcRear == v_CurrCam_e))
        {
          if (cameraBounds_as[v_CurrCam_e].intersect_b(v_Pos_o))
          {
            v_Vertex_ps->texCoords_af32[2] = 1.0F;
          }
          else
          {
            v_Vertex_ps->texCoords_af32[2] = 0.0F;
          }
        }
		    else
		    {
		    	//Do nothing
		    }

        if ((v_CurrCam_e == e_RcLeft) || (v_CurrCam_e == e_RcRight))
        {
          v_Vertex_ps->texCoords_af32[2] = 1.0F;
        }

        ++v_Offset_u32;

      } // x
    } //  y
  }
}

void BowlViewCPU::createVertices_v()
{
  bounds_s.init_v();

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    if (NULL != v_Segment_ps->vertices_as)
    {
      delete[] v_Segment_ps->vertices_as;
      v_Segment_ps->vertices_as = NULL;
    }

    sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
    sint32_t v_EndX_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

    sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
    sint32_t v_EndY_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

    v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
    v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

    uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
    uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);

    v_Segment_ps->vertices_as = new VertexBowlViewCPU_s[v_XLength_u32 * v_YLength_u32];

    uint32_t v_VertexCnt_u32 = 0U;

    for (sint32_t v_Y_s32 = v_StartY_s32; v_Y_s32 < v_EndY_s32; ++v_Y_s32)
    {

      for (sint32_t v_X_s32 = v_StartX_s32; v_X_s32 < v_EndX_s32; ++v_X_s32)
      {
         float32_t v_X_f32      = static_cast<float32_t>(v_X_s32);
         float32_t v_Y_f32      = static_cast<float32_t>(v_Y_s32);
         float32_t v_Height_f32 = 0.0F;
  
         if (e_BdmEllipseParameters == desc_s.bowlDeformationMethod_e)
         {
           float32_t v_Region_f32 = (v_X_f32 * v_X_f32) / (desc_s.ellipseA_f32 * desc_s.ellipseA_f32) +
                                    (v_Y_f32 * v_Y_f32) / (desc_s.ellipseB_f32 * desc_s.ellipseB_f32);

           if (v_Region_f32 <= 1.0F)
           {
             v_Height_f32 = 0.0F;
           }
           else
           {
             v_Height_f32 = desc_s.ellipseK_f32 * ((sqrtf(v_Region_f32) - 1.0F) * (sqrtf(v_Region_f32) - 1.0F));
           }

           v_Height_f32 = mecl::math::clamp_x<float32_t>(v_Height_f32, 0.0F, 255.0F);
         }

         v_Segment_ps->vertices_as[v_VertexCnt_u32].position_af32[0] = v_X_f32; 
         v_Segment_ps->vertices_as[v_VertexCnt_u32].position_af32[1] = v_Height_f32;
         v_Segment_ps->vertices_as[v_VertexCnt_u32].position_af32[2] = v_Y_f32;
  
         ++v_VertexCnt_u32;
  
         // update bounding box
         bounds_s.update_v(Vector3f(v_X_f32, v_Height_f32, v_Y_f32));
      } // x
    } //  y
  }

  if ((e_BdmEllipseSpline == desc_s.bowlDeformationMethod_e) ||
      (e_BdmTwoSplines    == desc_s.bowlDeformationMethod_e) )
  {
    // height adjustment based on spline
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
    {
      BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

      if ((NULL == v_Segment_ps) || (NULL == v_Segment_ps->vertices_as))
      {
        continue;
      }

      sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
      sint32_t v_EndX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

      sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
      sint32_t v_EndY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

      v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
      v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

      uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
      uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);

      uint32_t v_NumVertices_u32 = v_XLength_u32 * v_YLength_u32;

      for (uint32_t v_VertexIndex_u32 = 0U; v_VertexIndex_u32 < v_NumVertices_u32; ++v_VertexIndex_u32)
      {
        Vector3f v_PathX_o(0.0F, 0.0F, 0.0F);
        Vector3f v_PathZ_o(0.0F, 0.0F, 0.0F);

        float32_t v_X_f32 = v_Segment_ps->vertices_as[v_VertexIndex_u32].position_af32[0];
        float32_t v_Z_f32 = v_Segment_ps->vertices_as[v_VertexIndex_u32].position_af32[2];

        float32_t v_BoundsXLength_f32 = bounds_s.getExtent_o().getPosX();
        float32_t v_BoundsZLength_f32 = bounds_s.getExtent_o().getPosZ();

        // control curves with 2 splines
        if (e_BdmTwoSplines == desc_s.bowlDeformationMethod_e)
        {
          float32_t v_SplineLengthNormalizedX_f32 = fabs(v_X_f32) / (v_BoundsXLength_f32);
          float32_t v_SplineLengthNormalizedZ_f32 = fabs(v_Z_f32) / (v_BoundsZLength_f32);

          calculateCatmullRom_v(v_SplineLengthNormalizedX_f32, desc_s.controlPointLeftRight0_o, desc_s.controlPointLeftRight1_o, desc_s.controlPointLeftRight2_o, desc_s.controlPointLeftRight3_o, v_PathX_o);
          calculateCatmullRom_v(v_SplineLengthNormalizedZ_f32, desc_s.controlPointFrontRear0_o, desc_s.controlPointFrontRear1_o, desc_s.controlPointFrontRear2_o, desc_s.controlPointFrontRear3_o, v_PathZ_o);
          v_Segment_ps->vertices_as[v_VertexIndex_u32].position_af32[1] = ((v_PathX_o.getPosY() * v_SplineLengthNormalizedX_f32) + (v_PathZ_o.getPosY() * (v_SplineLengthNormalizedZ_f32)));
        }
        else if (e_BdmEllipseSpline == desc_s.bowlDeformationMethod_e)
        {
          // ellipse based spline deformation
          float32_t v_MaxRegion_f32 = (v_BoundsXLength_f32 * v_BoundsXLength_f32) / (desc_s.ellipseA_f32 * desc_s.ellipseA_f32) +
                                      (v_BoundsZLength_f32 * v_BoundsZLength_f32) / (desc_s.ellipseB_f32 * desc_s.ellipseB_f32);

          float32_t v_Region_f32 = (v_X_f32 * v_X_f32) / (desc_s.ellipseA_f32 * desc_s.ellipseA_f32) +
                                   (v_Z_f32 * v_Z_f32) / (desc_s.ellipseB_f32 * desc_s.ellipseB_f32);

          float32_t v_Normalized_f32 = (v_Region_f32 / v_MaxRegion_f32);

          calculateCatmullRom_v(v_Normalized_f32, desc_s.controlPointLeftRight0_o, desc_s.controlPointLeftRight1_o, desc_s.controlPointLeftRight2_o, desc_s.controlPointLeftRight3_o, v_PathX_o);
          v_Segment_ps->vertices_as[v_VertexIndex_u32].position_af32[1] = v_PathX_o.getPosY();
        }
        else
        {
          // misra else
        }

      }
    }
  }
}

void BowlViewCPU::createIndices_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    uint32_t v_Offset_u32 = 0U;

    if (NULL != v_Segment_ps->indices_au16)
    {
      delete[] v_Segment_ps->indices_au16;
      v_Segment_ps->indices_au16 = NULL;
    }

    sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
    sint32_t v_EndX_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

    sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
    sint32_t v_EndY_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

    v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
    v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

    uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
    uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);


    const uint32_t c_NumStripsRequired_u32 = v_YLength_u32 - 1U;
    const uint32_t c_NumDegensRequired_u32 = 2U * (c_NumStripsRequired_u32 - 1U);
    const uint32_t c_VerticesPerStrip_u32  = 2U * v_XLength_u32;
    const uint32_t c_NumIndices_u32 = (c_VerticesPerStrip_u32 * c_NumStripsRequired_u32) + c_NumDegensRequired_u32;

    v_Segment_ps->indices_au16 = new uint16_t[c_NumIndices_u32];

    for (uint32_t v_Y_u32 = 0U; v_Y_u32 < (v_YLength_u32 - 1U); ++v_Y_u32) 
    {
      if (v_Y_u32 > 0U) 
      {
        // Degenerate begin: repeat first vertex
        v_Segment_ps->indices_au16[v_Offset_u32] = static_cast<uint16_t>(v_Y_u32 * v_XLength_u32);
        ++v_Offset_u32;
      }

      for (uint32_t v_X_u32 = 0U; v_X_u32 < v_XLength_u32; ++v_X_u32) 
      {
        // One part of the strip
        v_Segment_ps->indices_au16[v_Offset_u32] = static_cast<uint16_t>((v_Y_u32 * v_XLength_u32) + v_X_u32);
        ++v_Offset_u32;

        v_Segment_ps->indices_au16[v_Offset_u32] = static_cast<uint16_t>(((v_Y_u32 + 1) * v_XLength_u32) + v_X_u32);
        ++v_Offset_u32;
      }

      if (v_Y_u32 < (v_YLength_u32 - 2)) 
      {
        // Degenerate end: repeat last vertex
        v_Segment_ps->indices_au16[v_Offset_u32] = static_cast<uint16_t>(((v_Y_u32 + 1) * v_XLength_u32) + (v_XLength_u32 - 1));
        ++v_Offset_u32;
      }
    }

    v_Segment_ps->indexCount_u32 = v_Offset_u32;
  }
}


void BowlViewCPU::createTexCoords_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
  {
    BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];

    uint32_t v_Offset_u32 = 0U;

    sint32_t v_StartX_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(0));
    sint32_t v_EndX_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(0));

    sint32_t v_StartY_s32 = static_cast<sint32_t>(v_Segment_ps->bounds_o.min_o(1));
    sint32_t v_EndY_s32   = static_cast<sint32_t>(v_Segment_ps->bounds_o.max_o(1));

    v_EndX_s32 > 0.0F ? --v_EndX_s32 : ++v_EndX_s32;
    v_EndY_s32 > 0.0F ? --v_EndY_s32 : ++v_EndY_s32;

    uint32_t v_XLength_u32 = mepl::abs_x(v_EndX_s32 - v_StartX_s32);
    uint32_t v_YLength_u32 = mepl::abs_x(v_EndY_s32 - v_StartY_s32);


    for (sint32_t v_Y_s32 = v_StartY_s32; v_Y_s32 < v_EndY_s32; ++v_Y_s32)
    {
      for (sint32_t v_X_s32 = v_StartX_s32; v_X_s32 < v_EndX_s32; ++v_X_s32)
      {
        Assert(v_Offset_u32 < (v_YLength_u32 * v_XLength_u32));

        VertexBowlViewCPU_s* v_Vertex_ps = &v_Segment_ps->vertices_as[v_Offset_u32];

        // calculate scale (Projection scale is in metric (millimeters)
        Vector3f v_VertexPos_o(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[1], v_Vertex_ps->position_af32[2]);
        Vector4f v_MeclPos_o = project4_o(v_VertexPos_o); 

        Vector2f v_TexCoords_o;
        bool_t v_Applicable_b = false;
        bool_t v_Visible_b = false;

        v_Segment_ps->realCamera_po->applyFullProjection_v(v_MeclPos_o, v_TexCoords_o, v_Applicable_b, v_Visible_b);

        // divide by width and height if applicable and visible
        if ((true == v_Applicable_b) && (true == v_Visible_b))
        {
          v_Vertex_ps->texCoords_af32[0] = v_TexCoords_o.getPosX() / v_Segment_ps->realCamera_po->getSensor_rx().getLowerRight_x().getPosX();
          v_Vertex_ps->texCoords_af32[1] = v_TexCoords_o.getPosY() / v_Segment_ps->realCamera_po->getSensor_rx().getLowerRight_x().getPosY();
        }

        ++v_Offset_u32;

      } // x
    } //  y
  }
}

void BowlViewCPU::createObscurationZone_v(bool_t i_GenerateBounds_b)
{
  // 1.) check if we need to generate the obscuration zone, or use the extisting one
  if (true == i_GenerateBounds_b)
  {
    // get the overlapping 2D box for all segments
    obscurationZone_s.bounds_s = BBox2D_s(Vector2f(bounds_s.min_o.getPosX(), bounds_s.min_o.getPosZ()),
                                          Vector2f(bounds_s.max_o.getPosX(), bounds_s.max_o.getPosZ()));

    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
    {
      BowlSegment_s* v_Segment_ps = &segments_as[v_I_u32];
      obscurationZone_s.bounds_s = BBox2D_s::overlap_s(obscurationZone_s.bounds_s, v_Segment_ps->bounds_o);
    }
  }

  // 2.) create vertices
  float32_t v_MinX_f32 = obscurationZone_s.bounds_s.min_o.getPosX();
  float32_t v_MinZ_f32 = obscurationZone_s.bounds_s.min_o.getPosY();

  float32_t v_MaxX_f32 = obscurationZone_s.bounds_s.max_o.getPosX();
  float32_t v_MaxZ_f32 = obscurationZone_s.bounds_s.max_o.getPosY();


  // bottom left
  obscurationZone_s.vertices_as[0].position_af32[0] = v_MinX_f32;
  obscurationZone_s.vertices_as[0].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[0].position_af32[2] = v_MaxZ_f32;

  // bottom right
  obscurationZone_s.vertices_as[1].position_af32[0] = v_MaxX_f32;
  obscurationZone_s.vertices_as[1].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[1].position_af32[2] = v_MaxZ_f32;

  // Top left
  obscurationZone_s.vertices_as[2].position_af32[0] = v_MinX_f32;
  obscurationZone_s.vertices_as[2].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[2].position_af32[2] = v_MinZ_f32;


  // bottom right
  obscurationZone_s.vertices_as[3].position_af32[0] = v_MaxX_f32;
  obscurationZone_s.vertices_as[3].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[3].position_af32[2] = v_MaxZ_f32;

  // top right
  obscurationZone_s.vertices_as[4].position_af32[0] = v_MaxX_f32;
  obscurationZone_s.vertices_as[4].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[4].position_af32[2] = v_MinZ_f32;

  // Top left
  obscurationZone_s.vertices_as[5].position_af32[0] = v_MinX_f32;
  obscurationZone_s.vertices_as[5].position_af32[1] = 0.01F;
  obscurationZone_s.vertices_as[5].position_af32[2] = v_MinZ_f32;



  // 3.) (re-)create vertex buffer
  if (NULL != obscurationZone_s.vertexBuffer_po)
  {
    // release
    renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(obscurationZone_s.vertexBuffer_po);
    obscurationZone_s.vertexBuffer_po = NULL;
  }

  // Create Vertex buffer
  VertexBufferDesc_s v_VbDesc_s;
  v_VbDesc_s.size_u32     = sizeof(VertexPos_s) * ObscurationZone_s::c_NumObscurationVertices_u32;
  v_VbDesc_s.stride_u32   = sizeof(VertexPos_s);
  v_VbDesc_s.c_Layout_pc  = "P3f";

  obscurationZone_s.vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_VbDesc_s, &obscurationZone_s.vertices_as[0]);

}

} // namespace me3d
