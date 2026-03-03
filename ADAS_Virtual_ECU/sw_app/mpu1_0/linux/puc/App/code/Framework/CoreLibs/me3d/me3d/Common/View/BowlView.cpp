#include "Common/View/BowlView.h"

 

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

BowlView::BowlView()
  : BaseBowlView()
  , indexCount_u32(0U)
  , effect_po(NULL)
  , vertexBuffer_po(NULL)
  , indexBuffer_po(NULL)
  , constantWVP_po(NULL)
  , constantTex0_po(NULL)
  , constantTex1_po(NULL)
  , constantTex2_po(NULL)
  , constantTex3_po(NULL)
  , constantRealCamTransLeft_po(NULL)
  , constantRealCamTransRight_po(NULL)
  , constantRealCamTransFront_po(NULL)
  , constantRealCamTransRear_po(NULL)
  , constantW2iPolyLeft_po(NULL)
  , constantW2iPolyRight_po(NULL)
  , constantW2iPolyFront_po(NULL)
  , constantW2iPolyRear_po(NULL)
  , constantPppPszLeft_po(NULL)
  , constantPppPszRight_po(NULL)
  , constantPppPszRear_po(NULL)
  , constantPppPszFront_po(NULL)
  , constantImageSizeProjScale_po(NULL)
  , constantDimsAndCoordOffset_po(NULL)
  , vertices_as(NULL)
  , indices_au16(NULL)
{

}

BowlView::~BowlView()
{

}

VertexBowlView_s* BowlView::getVertex_ps(float32_t i_X_f32, float32_t i_Z_f32)
{
  VertexBowlView_s* v_Result_ps = NULL;

  uint32_t v_Index_u32;
  if (getVertexIndex_b(i_X_f32, i_Z_f32, v_Index_u32))
  {
    v_Result_ps = &vertices_as[v_Index_u32];
  }

  return v_Result_ps;
}

bool BowlView::getHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t& o_Height_rf32)
{
  VertexBowlView_s* v_Vertex_ps = getVertex_ps(i_X_f32, i_Z_f32);

  bool v_Valid_b = v_Vertex_ps != NULL;

  if (v_Valid_b)
  {
    o_Height_rf32 = v_Vertex_ps->position_af32[1];
  }
  else
  {
    o_Height_rf32 = 0.0F;
  }

  return v_Valid_b;
}

bool BowlView::setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32)
{
  VertexBowlView_s* v_Vertex_ps = getVertex_ps(i_X_f32, i_Z_f32);

  bool v_Valid_b = v_Vertex_ps != NULL;

  if (v_Valid_b)
  {
    v_Vertex_ps->position_af32[1] += i_Height_f32;
  }

  return v_Valid_b;
}

bool BowlView::intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)
{
  Vector3f v_RayOrigin_o = i_RayOrigin_ro;
  Vector3f v_RayDir_o    = static_cast<Vector3f>(i_RayDir_ro * 10000.0F);

  float32_t v_HeightAtStartingPoint_f32;
  getHeight_b(v_RayOrigin_o.getPosX(), v_RayOrigin_o.getPosZ(), v_HeightAtStartingPoint_f32);


  float32_t v_Accuracy_f32 = 0.01F;
  float32_t v_CurrentError_f32 = v_RayOrigin_o.getPosY() - v_HeightAtStartingPoint_f32;
  uint32_t v_Cnt_u32 = 0U;

  // PRQA S 4234 1 // need the precision here
  while ((v_CurrentError_f32 > v_Accuracy_f32))
  {
    if (v_Cnt_u32 >= 1000U)
    {
      break;
    }

    v_RayDir_o *= 0.5F;
    Vector3f v_NextPoint_o = static_cast<Vector3f>(v_RayOrigin_o + v_RayDir_o);
    float32_t v_HeightAtNextPoint_f32; 
    getHeight_b(v_NextPoint_o.getPosX(), v_NextPoint_o.getPosZ(), v_HeightAtNextPoint_f32);

    if (v_NextPoint_o(1) > v_HeightAtNextPoint_f32)
    {
      v_RayOrigin_o = v_NextPoint_o;
      v_CurrentError_f32 = v_RayOrigin_o(1) - v_HeightAtNextPoint_f32;
    }

    ++v_Cnt_u32;
  }

  o_Intersection_ro = v_RayOrigin_o;

  return v_Cnt_u32 != 1000U;
}

bool_t BowlView::create_b(const BowlViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po)
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

  constantRealCamTransLeft_po     = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cRealCamTransLeft", e_CtMatrix4, 1U));
  constantRealCamTransRight_po    = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cRealCamTransRight", e_CtMatrix4, 1U));
  constantRealCamTransRear_po     = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cRealCamTransRear", e_CtMatrix4, 1U));
  constantRealCamTransFront_po    = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cRealCamTransFront", e_CtMatrix4, 1U));

  constantW2iPolyLeft_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cW2iPolyLeft", e_CtMatrix3, 1U));
  constantW2iPolyRight_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cW2iPolyRight", e_CtMatrix3, 1U));
  constantW2iPolyRear_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cW2iPolyRear", e_CtMatrix3, 1U));
  constantW2iPolyFront_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cW2iPolyFront", e_CtMatrix3, 1U));

  constantPppPszLeft_po           = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cPppPszLeft", e_CtFloat4, 1U));
  constantPppPszRight_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cPppPszRight", e_CtFloat4, 1U));
  constantPppPszRear_po           = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cPppPszRear", e_CtFloat4, 1U));
  constantPppPszFront_po          = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cPppPszFront", e_CtFloat4, 1U));

  constantImageSizeProjScale_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cImageSizeProjScale", e_CtFloat3, 1U));
  constantDimsAndCoordOffset_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cDimsCoordOffset", e_CtFloat4, 1U));


  // Enable face culling
  EffectFileRenderStateBlock* v_EnableCulling_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
  v_EnableCulling_po->addState_b(EffectFileRenderState_s(e_EfstCullMode, EffectFileStateValue_s(e_EfsvCW), 0));    
  effect_po->setRenderStateBlock_v(v_EnableCulling_po);



  // Create all data
  update_v(e_VufAll);

  return true;
}

void BowlView::release_v()
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
}

void BowlView::render_v()
{
  if ((NULL != vertexBuffer_po) &&
      (NULL != indexBuffer_po))
  {
    // Set constants
    const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();
    Matrix4f v_WVP_o;
    v_WVP_o = transform_o.getWorldMatrix_ro().mmulFast(c_VP_ro);
    constantWVP_po->setData_v(&v_WVP_o);

    updateConstants_v();

    vertexBuffer_po->set_v(0);
    indexBuffer_po->set_v();

    // begin rendering
    effect_po->beginPass_b();

    renderEngine_po->getDevice_po()->drawIndexed_v(e_PtTriangleStrip, indexCount_u32, 0U);

    // end rendering
    effect_po->endPass_v();
  }

  renderStitching_v();
}

void BowlView::createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b)
{
  if ((true == i_ResizeBuffers_b) && (NULL != vertexBuffer_po))
  {
    renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
    vertexBuffer_po = NULL;
  }

  if (NULL != vertexBuffer_po)
  {
    // update
    vertexBuffer_po->updateSubData_v(0, desc_s.xlength_u32 * desc_s.ylength_u32 * sizeof(VertexBowlView_s), vertices_as);
  }
  else
  {
    // Create Vertex buffer
    VertexBufferDesc_s v_VbDesc_s;
    v_VbDesc_s.size_u32 = desc_s.xlength_u32 * desc_s.ylength_u32 * sizeof(VertexBowlView_s);
    v_VbDesc_s.stride_u32 = sizeof(VertexBowlView_s);
    v_VbDesc_s.c_Layout_pc = "P3f_T4f";
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
      v_IbDesc_s.size_u32 = indexCount_u32 * sizeof(uint16_t);
      indexBuffer_po = renderEngine_po->getBufferManager_po()->createIndexBuffer_po(v_IbDesc_s, indices_au16);
    }
  }
}


void BowlView::update_v(uint32_t i_Flags_u32)
{
  Vector2f v_FrontAxisOffset = getFrontAxisOffset_o();
  desc_s.frontAxisOffsetX_f32 = v_FrontAxisOffset.getPosX();
  desc_s.frontAxisOffsetY_f32 = v_FrontAxisOffset.getPosY();

  if (i_Flags_u32 & e_VufConstants)
  {
    updateConstants_v();
  }

  if (i_Flags_u32 & e_VufVertices)
  {
    createVertices_v();
  }

  if (i_Flags_u32 & e_VufIndices)
  {
    createIndices_v();
  }

  if (i_Flags_u32 & e_VufCamBounds)
  {
    createCameraBounds_v();
  }

  if (i_Flags_u32 & e_VufDefaultStitching)
  {
    createDefaultStitchingLines_v();
  }

  if (i_Flags_u32 & e_VufStitching)
  {
    createStitching_v();
  }

  if ((i_Flags_u32 & e_VufVertices ) ||
      (i_Flags_u32 & e_VufIndices  ) ||
      (i_Flags_u32 & e_VufStitching)   )
  {
    bool v_UpdateIndices_b = (i_Flags_u32 & e_VufIndices)       == e_VufIndices;
    bool v_ResizeBuffers_b = (i_Flags_u32 & e_VufResizeBuffers) == e_VufResizeBuffers;

    createBuffers_v(v_UpdateIndices_b, v_ResizeBuffers_b);
  }
}




Matrix4f BowlView::getCameraTransform_o(RealCamera_e i_Camera_e) const
{
  Matrix4f rotMat4;

  if (NULL != desc_s.realCams_apo[i_Camera_e])
  {
    mecl::model::Pinhole<float32_t>& pinHole = mecl::model::Pinhole<float32_t>::get_rx(desc_s.realCams_apo[i_Camera_e]->getImager_rx());
    pinHole.init_v();
    Matrix3f rotMat3 = pinHole.getRotationMatrix_x();

    Vector3f translation = pinHole.getTranslationVector_x(rotMat3);
    mecl::core::Matrix<float32_t, 3, 4> proj = rotMat3 | translation;

    float32_t arr[4] = {0.0F, 0.0F, 0.0F, 1.0F};
    rotMat4 = (proj & mecl::core::Matrix<float32_t, 1, 4>(arr, 4));

    Matrix4f v_K_o;
    v_K_o.setEye();
    v_K_o(0, 0) = 1.0F / (static_cast<float32_t>(desc_s.xlength_u32) / desc_s.projectionScale_o.getPosX());
    v_K_o(1, 1) = 1.0F / (static_cast<float32_t>(desc_s.ylength_u32) / desc_s.projectionScale_o.getPosY());
    v_K_o(2, 2) = 1.0F / (static_cast<float32_t>(desc_s.xlength_u32) / desc_s.projectionScale_o.getPosZ());
    rotMat4 = rotMat4.mmulFast(v_K_o);

  }


  return rotMat4;
}

Matrix3f BowlView::getCameraPolyWorld2Image_o(RealCamera_e i_Camera_e) const
{
  Matrix3f v_LensW2I_o;

  if (NULL != desc_s.realCams_apo[i_Camera_e])
  {
    // set world 2 image polynom
    const LensRadialf& c_RadialLens_ro = LensRadialf::get_rx(desc_s.realCams_apo[i_Camera_e]->getLens_rx());
    LensRadialf::Config_s cfg;
    c_RadialLens_ro.copyConfig_v(cfg);

    // TODO: Remove hack, get real poly size when mecl is updated
    uint32_t v_PolySizeHack_u32 = (sizeof(cfg.world2image_x)) / (sizeof(float32_t));
    for (uint32_t v_I_u32 = 0U; v_I_u32 < v_PolySizeHack_u32; ++v_I_u32)
    {
      v_LensW2I_o(v_I_u32) = cfg.world2image_x[v_I_u32];
    }
  }

  return v_LensW2I_o;
}

Vector4f BowlView::getPrincipalPointAndPixelSize_o(RealCamera_e i_Camera_e) const
{
  Vector4f v_PpPsz_o;

  if (NULL != desc_s.realCams_apo[i_Camera_e])
  {
    const mecl::model::ISensor<float32_t>& c_Sensor_ro = desc_s.realCams_apo[i_Camera_e]->getSensor_rx();
    const Vector2f& c_Ppp_ro = c_Sensor_ro.getPpp_rx();
    const Vector2f& c_Psz_ro = c_Sensor_ro.getPsz_rx();
    v_PpPsz_o = Vector4f(c_Ppp_ro.getPosX(), c_Ppp_ro.getPosY(), c_Psz_ro.getPosX(), c_Psz_ro.getPosY());
  }

  return v_PpPsz_o;
}

Shaders_e BowlView::getShader_e()
{
  return e_ShaderBowlView;
}

void BowlView::createStitching_v()
{
  uint32_t v_Offset_u32 = 0U;

  for (uint32_t v_Y_u32 = 0U; v_Y_u32 < desc_s.ylength_u32; ++v_Y_u32)
  {
    for (uint32_t v_X_u32 = 0U; v_X_u32 < desc_s.xlength_u32; ++v_X_u32)
    {
      Assert(v_Offset_u32 < (desc_s.xlength_u32 * desc_s.ylength_u32));

      VertexBowlView_s* v_Vertex_ps = &vertices_as[v_Offset_u32];
      Vector2f v_Pos_o(v_Vertex_ps->position_af32[0], v_Vertex_ps->position_af32[2]);

      v_Vertex_ps->stitchingValues_af32[e_RcLeft]  = -1.0F;
      v_Vertex_ps->stitchingValues_af32[e_RcRight] = -1.0F;
      v_Vertex_ps->stitchingValues_af32[e_RcFront] = -1.0F;
      v_Vertex_ps->stitchingValues_af32[e_RcRear]  = -1.0F;

      // Front
      bool v_FrontLeft_b  = stitchingAreas_as[e_SaFrontLeft].bounds_o.intersect_b(v_Pos_o);
      bool v_FrontRight_b = stitchingAreas_as[e_SaFrontRight].bounds_o.intersect_b(v_Pos_o);
      bool v_RearLeft_b   = stitchingAreas_as[e_SaRearLeft].bounds_o.intersect_b(v_Pos_o);
      bool v_RearRight_b  = stitchingAreas_as[e_SaRearRight].bounds_o.intersect_b(v_Pos_o);

      // check if we have left/right intersection
      if (cameraBounds_as[e_RcLeft].intersect_b(v_Pos_o))
      {
        v_Vertex_ps->stitchingValues_af32[e_RcLeft] = 1.0F;
      }
      else if (cameraBounds_as[e_RcRight].intersect_b(v_Pos_o))
      {
        v_Vertex_ps->stitchingValues_af32[e_RcRight] = 1.0F;
      }
	  else
	  {
		  //Do nothing
	  }

      // Front
      if (cameraBounds_as[e_RcFront].intersect_b(v_Pos_o) || v_FrontLeft_b || v_FrontRight_b)
      {
        // Front Left
        if (v_FrontLeft_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaFrontLeft].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaFrontLeft].line1_o.getY_f32(v_Pos_o.getPosX());

          if (v_Pos_o.getPosY() > v_Line0Y_f32)
          { 
            v_Vertex_ps->stitchingValues_af32[e_RcLeft]  = 1.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = 0.0F;
          }
          else if (v_Pos_o.getPosY() < v_Line1Y_f32)
          {
            v_Vertex_ps->stitchingValues_af32[e_RcLeft]  = 0.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = 1.0F;
          }
          else
          {
            float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);

            v_Vertex_ps->stitchingValues_af32[e_RcLeft]  = 1.0F - v_Distance_f32;
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = v_Distance_f32;
          }
        }
        // Front Right
        else if (v_FrontRight_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaFrontRight].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaFrontRight].line1_o.getY_f32(v_Pos_o.getPosX());

          if (v_Pos_o.getPosY() < v_Line0Y_f32)
          { 
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = 1.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRight] = 0.0F;
          }
          else if (v_Pos_o.getPosY() > v_Line1Y_f32)
          {
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = 0.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRight] = 1.0F;
          }
          else
          {
            float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);

            v_Vertex_ps->stitchingValues_af32[e_RcRight] = v_Distance_f32;
            v_Vertex_ps->stitchingValues_af32[e_RcFront] = 1.0F - v_Distance_f32;
          }
        }
        else
        {
          v_Vertex_ps->stitchingValues_af32[e_RcFront] = 1.0F;
        }
      }
      // Rear
      else if (cameraBounds_as[e_RcRear].intersect_b(v_Pos_o) || v_RearLeft_b || v_RearRight_b)
      {
        // Rear Left
        if (v_RearLeft_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaRearLeft].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaRearLeft].line1_o.getY_f32(v_Pos_o.getPosX());

          if (v_Pos_o.getPosY() < v_Line0Y_f32)
          { 
            v_Vertex_ps->stitchingValues_af32[e_RcLeft] = 1.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRear] = 0.0F;
          }
          else if (v_Pos_o.getPosY() > v_Line1Y_f32)
          {
            v_Vertex_ps->stitchingValues_af32[e_RcLeft] = 0.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRear] = 1.0F;
          }
          else
          {
            float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);

            v_Vertex_ps->stitchingValues_af32[e_RcLeft]  = 1.0F - v_Distance_f32;
            v_Vertex_ps->stitchingValues_af32[e_RcRear] = v_Distance_f32;
          }
        }
        // Rear Right
        else if (v_RearRight_b)
        {
          float32_t v_Line0Y_f32 = stitchingAreas_as[e_SaRearRight].line0_o.getY_f32(v_Pos_o.getPosX());
          float32_t v_Line1Y_f32 = stitchingAreas_as[e_SaRearRight].line1_o.getY_f32(v_Pos_o.getPosX());

          if (v_Pos_o.getPosY() > v_Line0Y_f32)
          { 
            v_Vertex_ps->stitchingValues_af32[e_RcRear ] = 1.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRight] = 0.0F;
          }
          else if (v_Pos_o.getPosY() < v_Line1Y_f32)
          {
            v_Vertex_ps->stitchingValues_af32[e_RcRear ] = 0.0F;
            v_Vertex_ps->stitchingValues_af32[e_RcRight] = 1.0F;
          }
          else
          {
            float32_t v_Distance_f32 = (v_Pos_o.getPosY() - v_Line0Y_f32) / (v_Line1Y_f32 - v_Line0Y_f32);

            v_Vertex_ps->stitchingValues_af32[e_RcRear ] = 1.0F - v_Distance_f32;
            v_Vertex_ps->stitchingValues_af32[e_RcRight] = v_Distance_f32;
          }
        }
        else 
        {
          v_Vertex_ps->stitchingValues_af32[e_RcRear] = 1.0F;
        }
      }
	  else
	  {
		  //Do nothing
	  }

      ++v_Offset_u32;

    } // x
  } //  y
}

void BowlView::updateConstants_v()
{
  constantTex0_po->setData_v(desc_s.textures_apo[e_RcLeft] );
  constantTex1_po->setData_v(desc_s.textures_apo[e_RcRight]);
  constantTex2_po->setData_v(desc_s.textures_apo[e_RcFront]);
  constantTex3_po->setData_v(desc_s.textures_apo[e_RcRear] );

  // set camera transforms
  Matrix4f v_Transform_o = getCameraTransform_o(e_RcLeft);
  constantRealCamTransLeft_po->setData_v(&v_Transform_o);

  v_Transform_o = getCameraTransform_o(e_RcRight);
  constantRealCamTransRight_po->setData_v(&v_Transform_o);

  v_Transform_o = getCameraTransform_o(e_RcFront);
  constantRealCamTransFront_po->setData_v(&v_Transform_o);

  v_Transform_o = getCameraTransform_o(e_RcRear);
  constantRealCamTransRear_po->setData_v(&v_Transform_o);

  // set world 2 image polynoms

  Matrix3f v_Poly_o = getCameraPolyWorld2Image_o(e_RcLeft);
  constantW2iPolyLeft_po->setData_v(&v_Poly_o);

  v_Poly_o = getCameraPolyWorld2Image_o(e_RcRight);
  constantW2iPolyRight_po->setData_v(&v_Poly_o);

  v_Poly_o = getCameraPolyWorld2Image_o(e_RcFront);
  constantW2iPolyFront_po->setData_v(&v_Poly_o);

  v_Poly_o = getCameraPolyWorld2Image_o(e_RcRear);
  constantW2iPolyRear_po->setData_v(&v_Poly_o);

  // set principal point and pixelSize

  Vector4f v_Sizes_o = getPrincipalPointAndPixelSize_o(e_RcLeft);
  constantPppPszLeft_po->setData_v(&v_Sizes_o);

  v_Sizes_o = getPrincipalPointAndPixelSize_o(e_RcRight);
  constantPppPszRight_po->setData_v(&v_Sizes_o);

  v_Sizes_o = getPrincipalPointAndPixelSize_o(e_RcFront);
  constantPppPszFront_po->setData_v(&v_Sizes_o);

  v_Sizes_o = getPrincipalPointAndPixelSize_o(e_RcRear);
  constantPppPszRear_po->setData_v(&v_Sizes_o);

  // set image and grid size
  Vector3f v_ImageSizeProjScale_o(desc_s.imageWidth_f32, desc_s.imageHeight_f32, static_cast<float32_t>(desc_s.xlength_u32) / desc_s.projectionScale_o.getPosX());
  constantImageSizeProjScale_po->setData_v(&v_ImageSizeProjScale_o);

  // set dimensions (x and y length), coordinate offset x (x - Distance between Car Pivot and Terrain Pivot)
  Vector4f v_DimsAndCoordOffset_o(static_cast<float32_t>(desc_s.xlength_u32), static_cast<float32_t>(desc_s.ylength_u32), desc_s.frontAxisOffsetX_f32, desc_s.frontAxisOffsetY_f32);
  constantDimsAndCoordOffset_po->setData_v(&v_DimsAndCoordOffset_o);
}


void BowlView::createVertices_v()
{
  bounds_s.init_v();

  if (NULL != vertices_as)
  {
    delete[] vertices_as;
    vertices_as = NULL;
  }
  vertices_as = new VertexBowlView_s[desc_s.xlength_u32 * desc_s.ylength_u32]; 

  uint32_t v_VertexCnt_u32 = 0U;

  sint32_t v_HalfLengthY_s32 = (desc_s.ylength_u32) / 2U;
  sint32_t v_HalfLengthX_s32 = (desc_s.xlength_u32) / 2U;
  
  for (sint32_t v_Y_s32 = -v_HalfLengthY_s32; v_Y_s32 < v_HalfLengthY_s32; ++v_Y_s32)
  {
    for (sint32_t v_X_s32 = -v_HalfLengthX_s32; v_X_s32 < v_HalfLengthX_s32; ++v_X_s32)
    {
       float32_t v_X_f32      = static_cast<float32_t>(v_X_s32);
       float32_t v_Y_f32      = static_cast<float32_t>(v_Y_s32);
       float32_t v_Height_f32 = 0.0F;
  
       float32_t v_Region_f32 = (v_X_f32 * v_X_f32) / (desc_s.ellipseA_f32 * desc_s.ellipseA_f32) +
                                (v_Y_f32 * v_Y_f32) / (desc_s.ellipseB_f32 * desc_s.ellipseB_f32);
  
       if ( v_Region_f32 <= 1.0F)
       {
         v_Height_f32 = 0.0F;
       }
       else
       {
         v_Height_f32 = desc_s.ellipseK_f32 * ((sqrtf(v_Region_f32) - 1.0F) * (sqrtf(v_Region_f32) - 1.0F)); 
       }
  
       v_Height_f32 = mecl::math::clamp_x<float32_t>(v_Height_f32, 0.0F, 255.0F);
  
       vertices_as[v_VertexCnt_u32].position_af32[0] = v_X_f32; 
       vertices_as[v_VertexCnt_u32].position_af32[1] = v_Height_f32;
       vertices_as[v_VertexCnt_u32].position_af32[2] = v_Y_f32;
  
       ++v_VertexCnt_u32;
  
       // update bounding box
       bounds_s.update_v(Vector3f(v_X_f32, v_Height_f32, v_Y_f32));
    } // x
  } //  y
}

void BowlView::createIndices_v()
{
  uint32_t v_Offset_u32 = 0U;

  if (NULL != indices_au16)
  {
    delete[] indices_au16;
    indices_au16 = NULL;
  }

  const uint32_t c_NumStripsRequired_u32 = desc_s.ylength_u32 - 1U;
  const uint32_t c_NumDegensRequired_u32 = 2U * (c_NumStripsRequired_u32 - 1U);
  const uint32_t c_VerticesPerStrip_u32  = 2U * desc_s.xlength_u32;
  const uint32_t c_NumIndices_u32 = (c_VerticesPerStrip_u32 * c_NumStripsRequired_u32) + c_NumDegensRequired_u32;

  indices_au16 = new uint16_t[c_NumIndices_u32];

  for (uint32_t v_Y_u32 = 0U; v_Y_u32 < (desc_s.ylength_u32 - 1U); ++v_Y_u32) 
  {
    if (v_Y_u32 > 0U) 
    {
      // Degenerate begin: repeat first vertex
      indices_au16[v_Offset_u32] = static_cast<uint16_t>(v_Y_u32 * desc_s.xlength_u32);
      ++v_Offset_u32;
    }

    for (uint32_t v_X_u32 = 0U; v_X_u32 < desc_s.xlength_u32; ++v_X_u32) 
    {
      // One part of the strip
      indices_au16[v_Offset_u32] = static_cast<uint16_t>((v_Y_u32 * desc_s.xlength_u32) + v_X_u32);
      ++v_Offset_u32;

      indices_au16[v_Offset_u32] = static_cast<uint16_t>(((v_Y_u32 + 1) * desc_s.xlength_u32) + v_X_u32);
      ++v_Offset_u32;
    }

    if (v_Y_u32 < (desc_s.ylength_u32 - 2)) 
    {
      // Degenerate end: repeat last vertex
      indices_au16[v_Offset_u32] = static_cast<uint16_t>(((v_Y_u32 + 1) * desc_s.xlength_u32) + (desc_s.xlength_u32 - 1));
      ++v_Offset_u32;
    }
  }

  indexCount_u32 = v_Offset_u32;
}


} // namespace me3d
