#include "SingleView.h"

#include "Common/Manager/BufferManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Resources/Texture.h"
#include "Math/MathLib.h"

// PRQA S 5118 EOF // C++14 Autosar Standard permits
// PRQA S 3706 EOF // Subscript operator is used to fill vertices and indices.
// PRQA S 3054 EOF // Implicit bool conversion is fine for flags
// PRQA S 3710 EOF // Enum as operand intended
// PRQA S 3222 EOF // mecl vector design
// PRQA S 3223 EOF // mecl design

namespace me3d
{
  SingleView::SingleView()
    : BaseView()
    , effect_po(NULL)
    , vertexBuffer_po(NULL)
    , indexBuffer_po(NULL)
    , vertices_as(NULL)
    , indices_au16(NULL)
    , indexCount_u32(0)
    , singleViewDesc_s()
    , renderEngine_po(NULL)
    , constantTex_po(NULL)
    , fullResolutionRatio_o(0.0f, 0.0f)
    , viewSizeRatio_o(0.0f, 0.0f)
  {
  }

  SingleView::~SingleView()
  {

  }


  void SingleView::updateSingleView_v()
  {
    if ( (NULL != singleViewDesc_s.realCam_po) && 
         (NULL != singleViewDesc_s.syntCam_po) )
    {
      singleView_o.setRealCam_v(*singleViewDesc_s.realCam_po);
      singleView_o.setSyntCam_v(*singleViewDesc_s.syntCam_po);
      singleView_o.init_v();
    }
    else
    {
      singleView_o = SingleViewf();
    }
  }

  bool_t SingleView::create_b(const SingleViewDesc_s& i_Desc_rs, RenderEngine* b_RenderEngine_po)
  {
    bool_t v_Result_b = false;
    singleViewDesc_s = i_Desc_rs;
    renderEngine_po = b_RenderEngine_po;

    if(renderEngine_po != NULL)
    {
      // create effect and Texture constants
      effect_po              = renderEngine_po->getShaderManager_po()->createShader_po(getShader_e());
      constantTex_po         = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cSingleViewTex", e_CtTexture, 1U));

      update_v(e_VufAll);
    }

    return v_Result_b;
  }

  void SingleView::release_v()
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

  SingleViewDesc_s* SingleView::getDesc_ps()
  {
    return &singleViewDesc_s;
  }

  void SingleView::setTransform_v(const Transform& i_Transform_ro)
  {
    ME_Debugger_F_Printf_v("The method setTransform_v for SingleView is not implemented.\n");
  }

  Vector3f SingleView::project_o(const Vector3f& i_GLPosition_ro)
  {
    Vector4f v_MeclCoord_o = project4_o(i_GLPosition_ro);
    return Vector3f(v_MeclCoord_o.getPosX(), v_MeclCoord_o.getPosY(), v_MeclCoord_o.getPosZ());
  }

  Vector4f SingleView::project4_o(const Vector3f& i_GLPosition_ro)
  {
    Vector2f v_XY_o(0.0f, 0.0f);
    Vector4f v_MeclCoords_o;

    if(singleView_o.isConfigured_b() == true)
    {
      sint32_t v_X_s32 = static_cast<sint32_t>(i_GLPosition_ro.getPosX());
      sint32_t v_Y_s32 = static_cast<sint32_t>(i_GLPosition_ro.getPosY());

      v_MeclCoords_o(0) = (static_cast<float32_t>(v_X_s32) * fullResolutionRatio_o(0));
      v_MeclCoords_o(1) = (static_cast<float32_t>(v_Y_s32) * fullResolutionRatio_o(1));
      v_MeclCoords_o(2) = 0.0f;
      v_MeclCoords_o(3) = 0.0f;
    }

    return v_MeclCoords_o;
  }

  Vector3f SingleView::unProject_o(const Vector3f& i_MeclPosition_ro)
  {
    Vector4f v_P3d_o;
    v_P3d_o.setPosX(i_MeclPosition_ro.getPosX());
    v_P3d_o.setPosY(i_MeclPosition_ro.getPosY());
    v_P3d_o.setPosZ(i_MeclPosition_ro.getPosZ());
    v_P3d_o.setW(1.0f);

    Vector3f v_PCamCoords_o;
    Vector2f v_P2d_o;
    Vector3f v_GlCoords_o(0.0f, 0.0f, 0.0f);
    if(singleView_o.isConfigured_b() == true)
    {
      singleView_o.getSyntheticCamera_px()->applyProjectionW2I_v(v_P3d_o, v_PCamCoords_o);

      if (mecl::math::abs_x(v_PCamCoords_o(2)) > mecl::math::numeric_limits<float32_t>::epsilon_x())
      {
        singleView_o.getSyntheticCamera_px()->applyNormalization_v(v_PCamCoords_o, 1.0f, v_P2d_o);

        // TODO: check, no normalization before needed 
       // singleView_o.getSyntheticCamera_px()->applyDistortion_v(v_PCamCoords_o, v_P2d_o);

        singleView_o.getSyntheticCamera_px()->metricToPixel_v(v_P2d_o, v_P2d_o);
        v_GlCoords_o(0) = v_P2d_o(0) / fullResolutionRatio_o(0) * viewSizeRatio_o(0);
        v_GlCoords_o(1) = v_P2d_o(1) / fullResolutionRatio_o(1) * viewSizeRatio_o(1);
        v_GlCoords_o(2) = 0.0f;
      }
      
    }

    return v_GlCoords_o;
  }

  void SingleView::update_v(uint32_t i_Flags_u32)
  {
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

    if ((i_Flags_u32 & e_VufVertices ) ||
      (i_Flags_u32 & e_VufIndices))
    {
      bool v_UpdateIndices_b = (i_Flags_u32 & e_VufIndices)       == e_VufIndices;
      bool v_ResizeBuffers_b = (i_Flags_u32 & e_VufResizeBuffers) == e_VufResizeBuffers;

      createBuffers_v(v_UpdateIndices_b, v_ResizeBuffers_b);
    }
  }

  void SingleView::createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b)
  {
    if ((true == i_ResizeBuffers_b) && (NULL != vertexBuffer_po))
    {
      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
      vertexBuffer_po = NULL;
    }

    if (NULL != vertexBuffer_po)
    {
      // update
      vertexBuffer_po->updateSubData_v(0, singleViewDesc_s.numVerticesX_u32 * singleViewDesc_s.numVerticesY_u32 * sizeof(VertexSingleView_s), vertices_as);
    }
    else
    {
      // Create Vertex buffer
      VertexBufferDesc_s v_VbDesc_s;
      v_VbDesc_s.size_u32 = singleViewDesc_s.numVerticesX_u32 * singleViewDesc_s.numVerticesY_u32 * sizeof(VertexSingleView_s);
      v_VbDesc_s.stride_u32 = sizeof(VertexSingleView_s);
      v_VbDesc_s.c_Layout_pc = "P2f_T2f";
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

  bool_t SingleView::intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)
  {
    ME_Debugger_F_Printf_v("The method intersectRay_b for SingleView is not implemented.\n");
    return false;
  }

  bool_t SingleView::setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32)
  {
    ME_Debugger_F_Printf_v("The method setHeight_b for SingleView is not implemented.\n");
    return false;
  }

  void SingleView::render_v()
  {
    if ((NULL != vertexBuffer_po) &&
      (NULL != indexBuffer_po))
    {
      updateConstants_v();

      vertexBuffer_po->set_v(0);
      indexBuffer_po->set_v();

      // begin rendering
      effect_po->beginPass_b();

      renderEngine_po->getDevice_po()->drawIndexed_v(e_PtTriangleStrip, indexCount_u32, 0U);

      // end rendering
      effect_po->endPass_v();
    }
  }

  void SingleView::onResize_v()
  {
    update_v(e_VufVertices);
  }

  me3d::Shaders_e SingleView::getShader_e()
  {
    return e_ShaderSingleView;
  }

  void SingleView::createIndices_v()
  {
    uint32_t v_Offset_u32 = 0U;

    if (NULL != indices_au16)
    {
      delete[] indices_au16;
      indices_au16 = NULL;
    }

    const uint32_t c_NumStripsRequired_u32 = singleViewDesc_s.numVerticesY_u32 - 1U;
    const uint32_t c_NumDegensRequired_u32 = 2U * (c_NumStripsRequired_u32 - 1U);
    const uint32_t c_VerticesPerStrip_u32  = 2U * singleViewDesc_s.numVerticesX_u32;
    const uint32_t c_NumIndices_u32 = (c_VerticesPerStrip_u32 * c_NumStripsRequired_u32) + c_NumDegensRequired_u32;

    indices_au16 = new uint16_t[c_NumIndices_u32];

    for (uint32_t v_Y_u32 = 0U; v_Y_u32 < (singleViewDesc_s.numVerticesY_u32 - 1U); ++v_Y_u32) 
    {
      if (v_Y_u32 > 0U) 
      {
        // Degenerate begin: repeat first vertex
        indices_au16[v_Offset_u32] = static_cast<uint16_t>(v_Y_u32 * singleViewDesc_s.numVerticesX_u32);
        ++v_Offset_u32;
      }

      for (uint32_t v_X_u32 = 0U; v_X_u32 < singleViewDesc_s.numVerticesX_u32; ++v_X_u32) 
      {

        indices_au16[v_Offset_u32] = static_cast<uint16_t>(((v_Y_u32 + 1) * singleViewDesc_s.numVerticesX_u32) + v_X_u32);
        ++v_Offset_u32;

        // One part of the strip
        indices_au16[v_Offset_u32] = static_cast<uint16_t>((v_Y_u32 * singleViewDesc_s.numVerticesX_u32) + v_X_u32);
        ++v_Offset_u32;
      }

      if (v_Y_u32 < (singleViewDesc_s.numVerticesY_u32 - 2)) 
      {
        // Degenerate end: repeat last vertex
        indices_au16[v_Offset_u32] = static_cast<uint16_t>((v_Y_u32 * singleViewDesc_s.numVerticesX_u32) + (singleViewDesc_s.numVerticesX_u32 - 1));
        ++v_Offset_u32;
      }
    }

    indexCount_u32 = v_Offset_u32;
  }
  
  void SingleView::createVertices_v()
  {
    if (NULL != vertices_as)
    {
      delete[] vertices_as;
      vertices_as = NULL;
    }

    updateSingleView_v();
    updateRatios_v();

    vertices_as = new VertexSingleView_s[singleViewDesc_s.numVerticesX_u32 * singleViewDesc_s.numVerticesY_u32]; 

    bool_t v_Applicable_b = false;

    uint32_t v_VertexCnt_u32 = 0U;

    float32_t v_X_f32 = 0.0f;
    float32_t v_Y_f32 = 0.0f;

    for (uint32_t v_Y_s32 = 0; v_Y_s32 < singleViewDesc_s.numVerticesY_u32; ++v_Y_s32)
    {
      for (uint32_t v_X_s32 = 0; v_X_s32 < singleViewDesc_s.numVerticesX_u32; ++v_X_s32)
      {
        v_X_f32 = static_cast<float32_t>(v_X_s32);
        v_Y_f32 = static_cast<float32_t>(v_Y_s32);

        // Create vertex coordinate
        vertices_as[v_VertexCnt_u32].position_af32[0] = v_X_f32 * viewSizeRatio_o(0); 
        vertices_as[v_VertexCnt_u32].position_af32[1] = v_Y_f32 * viewSizeRatio_o(1);

        // Create MECL texture coordinate
        const Vector3f v_VertexCoord_o(v_X_f32, v_Y_f32, 0.0f);
        Vector3f v_MeclCoord_o = project_o(v_VertexCoord_o);

        Vector2f v_Tex_o;
        Vector2f v_UV_o;
        if(singleView_o.isConfigured_b() == true)
        {
          singleView_o.getSyntheticCamera_px()->pixelToMetric_v(Vector2f(v_MeclCoord_o(0), v_MeclCoord_o(1)), v_UV_o);

          // calculation undistortion of synthetic camera 
          Vector3f v_SynthCamUndistorted_o;
          singleView_o.getSyntheticCamera_px()->applyUndistortion_v(v_UV_o, v_SynthCamUndistorted_o);

          // which is the input for the homography calculation from the single view
          Vector3f v_PRealCamUnistorted_o;
          Vector2f v_PRealCamDistorted_o;
          singleView_o.applyHomography_v(*singleView_o.getSyntheticCamera_px(), *singleView_o.getRealCamera_px(), v_SynthCamUndistorted_o, v_PRealCamUnistorted_o);

          // apply real camera distortion based on homography
          singleView_o.getRealCamera_px()->applyDistortion_v(v_PRealCamUnistorted_o, 0.0f, v_PRealCamDistorted_o, v_Applicable_b);

          if(v_Applicable_b == true)
          {
            singleView_o.getRealCamera_px()->metricToPixel_v(v_PRealCamDistorted_o, v_Tex_o);
          }
          else
          {
            v_Tex_o(0) = 0.0f;
            v_Tex_o(1) = 0.0f;
          }         
        }

        if ((singleViewDesc_s.texture_po != NULL))
        {
          vertices_as[v_VertexCnt_u32].texCoords_af32[0] = (v_Tex_o.getPosX() / static_cast<float32_t>(singleViewDesc_s.texture_po->getWidth_u32()));
          vertices_as[v_VertexCnt_u32].texCoords_af32[1] = (v_Tex_o.getPosY() / static_cast<float32_t>(singleViewDesc_s.texture_po->getHeight_u32()));
        }

        ++v_VertexCnt_u32;

      } // x
    } //  y
  }
  
  void SingleView::updateConstants_v()const
  {
    if(singleViewDesc_s.texture_po != NULL)
    {
      constantTex_po->setData_v(singleViewDesc_s.texture_po);
    }
  }

  void SingleView::updateRatios_v()
  {
    float32_t v_NumVerticesX_f32 = static_cast<float32_t>(singleViewDesc_s.numVerticesX_u32);
    float32_t v_NumVerticesY_f32 = static_cast<float32_t>(singleViewDesc_s.numVerticesY_u32);

    if(singleViewDesc_s.texture_po != NULL)
    {
	  float32_t v_ImageWidth_f32 = 0.0f;
	  float32_t v_ImageHeight_f32 = 0.0f;

      v_ImageWidth_f32 = static_cast<float32_t>(singleViewDesc_s.texture_po->getWidth_u32());
      v_ImageHeight_f32 = static_cast<float32_t>(singleViewDesc_s.texture_po->getHeight_u32());

      fullResolutionRatio_o.setPosX(v_ImageWidth_f32 / (v_NumVerticesX_f32 - 1.0f));
      fullResolutionRatio_o.setPosY(v_ImageHeight_f32 / (v_NumVerticesY_f32 - 1.0f));

      viewSizeRatio_o(0) = (singleViewDesc_s.width_f32 / (v_NumVerticesX_f32 - 1.0f));
      viewSizeRatio_o(1) = (singleViewDesc_s.height_f32 / (v_NumVerticesY_f32 - 1.0f));
    }
  }

} // namespace me3d
