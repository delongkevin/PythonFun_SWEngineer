//--------------------------------------------------------------------------                                                                                                           
/// @file BaseBowlView.h                                                                         
/// @brief Base class for Bowl View classes
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 3223 EOF // no modification for bounds

#include "Math/Color.h"
#include "Math/MathLib.h"
#include "Common/View/BaseBowlView.h"
#include "Common/RenderEngine.h"
#include "Common/Renderer/DebugRenderer.h"

namespace me3d
{
  BaseBowlView::BaseBowlView()
    : BaseView()
    , renderEngine_po(NULL)
    , desc_s()
    , bounds_s()
    , renderStitching_b(false)
    , transform_o()
  {

  }

  BaseBowlView::~BaseBowlView()
  {

  }

  BowlViewDesc_s* BaseBowlView::getDesc_ps()
  {
    return &desc_s;
  }

  const BBox3D_s& BaseBowlView::getBounds_ro() const
  {
    return bounds_s;
  }

  void BaseBowlView::setRenderStitching_v(bool_t i_RenderStitching_b)
  {
    renderStitching_b = i_RenderStitching_b;
  }

  bool_t BaseBowlView::getRenderStitching_b() const
  {
    return renderStitching_b;
  }

  void BaseBowlView::setStitchingArea_v(StitchingArea_e i_StitchingAreaType_e, const StitchingArea_s& i_Area_rs)
  {
    stitchingAreas_as[i_StitchingAreaType_e] = i_Area_rs;
  }

  const StitchingArea_s& BaseBowlView::getStitchingArea_rs(StitchingArea_e i_StitchingAreaType_e)const
  {
    return stitchingAreas_as[i_StitchingAreaType_e];
  }

  Vector3f BaseBowlView::project_o(const Vector3f& i_GLPosition_ro)
  {
    Vector4f v_Vec4_o = project4_o(i_GLPosition_ro);

    return Vector3f(v_Vec4_o.getPosX(), v_Vec4_o.getPosY(), v_Vec4_o.getPosZ());
  }

  Vector4f BaseBowlView::project4_o(const Vector3f& i_GLPosition_ro)
  {
    Vector4f v_MeclPos_o = glToMeclProjection_o(i_GLPosition_ro, desc_s.projectionScale_o, desc_s.xlength_u32, desc_s.ylength_u32, desc_s.xlength_u32);

    v_MeclPos_o(0) -= (desc_s.frontAxisOffsetX_f32);
    v_MeclPos_o(1) -= (desc_s.frontAxisOffsetY_f32);

    return v_MeclPos_o;
  }

  Vector3f BaseBowlView::unProject_o(const Vector3f& i_MeclPosition_ro)
  {
    Vector3f v_OffsettedPos_o = i_MeclPosition_ro;

    v_OffsettedPos_o(0) += (desc_s.frontAxisOffsetX_f32);
    v_OffsettedPos_o(1) += (desc_s.frontAxisOffsetY_f32);

    Vector4f v_MeclPos_o = meclToGlProjection_o(v_OffsettedPos_o, desc_s.projectionScale_o, desc_s.xlength_u32, desc_s.ylength_u32, desc_s.xlength_u32);

    return Vector3f(v_MeclPos_o.getPosX(), v_MeclPos_o.getPosY(), v_MeclPos_o.getPosZ());
  }

  void BaseBowlView::onResize_v()
  {

  }


  void BaseBowlView::setTransform_v(const Transform& i_Transform_ro)
  {
    transform_o = i_Transform_ro;
  }

  bool BaseBowlView::getVertexIndex_b(float32_t i_X_f32, float32_t i_Z_f32, uint32_t& o_Index_ru32) const
  {
    bool v_Valid_b = false;

    i_X_f32 += static_cast<float32_t>(desc_s.xlength_u32 / 2U);
    i_Z_f32 += static_cast<float32_t>(desc_s.ylength_u32 / 2U);

    i_X_f32 += transform_o.getTranslation_ro().getPosX();
    i_Z_f32 += transform_o.getTranslation_ro().getPosZ();

    if ((i_X_f32 > 0.0F                ) &&
        (i_Z_f32 > 0.0F                ) &&
        (i_X_f32 < static_cast<float32_t>(desc_s.xlength_u32 - 1U)) &&
        (i_Z_f32 < static_cast<float32_t>(desc_s.ylength_u32 - 1U)))
    {
      v_Valid_b    = true;
      o_Index_ru32 = (static_cast<uint32_t>(i_Z_f32) * desc_s.xlength_u32) + static_cast<uint32_t>(i_X_f32); 
    }

    return v_Valid_b;
  }

  void BaseBowlView::renderStitching_v()
  {
    if (true == renderStitching_b)
    {
      for (uint32_t v_I_u32 = 0U; v_I_u32 < e_SaCount; ++v_I_u32)
      {
        Color v_Color_o;
        switch (static_cast<StitchingArea_e>(v_I_u32))
        {
        case e_SaFrontLeft:
			{
				v_Color_o = Color::Green;
				break;

			}
          
        case e_SaFrontRight:
			{
				v_Color_o = Color(1.0F, 1.0F, 0.0F, 1.0F);
				break;
			}

        case e_SaRearLeft:
			{
				v_Color_o = Color::Blue;
				break;
			}
          
        case e_SaRearRight:
			{
				v_Color_o = Color::Red;
				break;
			}
          
        case e_SaCount: // fall through
        default:
			{
				Assert(false);
				break;
			}
      
        }

        const StitchingArea_s& c_Area_rs = stitchingAreas_as[v_I_u32];

        // draw bounds
        const BBox3D_s& c_Bounds_ro = stitchingAreas_as[v_I_u32].bounds_o;
        renderEngine_po->getDebugRenderer_po()->drawBox_v(transform_o.getWorldMatrix_ro(), c_Bounds_ro.getCenter_o(), c_Bounds_ro.getExtent_o(), v_Color_o);

        // Draw line 0
        const Vector3f& c_Start0_ro = Vector3f(c_Area_rs.line0_o.getStart_ro().getPosX(), 0.0F, c_Area_rs.line0_o.getStart_ro().getPosY());
        const Vector3f& c_End0_ro   = Vector3f(c_Area_rs.line0_o.getEnd_ro().getPosX(), 0.0F, c_Area_rs.line0_o.getEnd_ro().getPosY());
        renderEngine_po->getDebugRenderer_po()->drawLine_v(transform_o.getWorldMatrix_ro(), c_Start0_ro, c_End0_ro, v_Color_o);

        // Draw line 1
        const Vector3f& c_Start1_ro = Vector3f(c_Area_rs.line1_o.getStart_ro().getPosX(), 0.0F, c_Area_rs.line1_o.getStart_ro().getPosY());
        const Vector3f& c_End1_ro   = Vector3f(c_Area_rs.line1_o.getEnd_ro().getPosX(), 0.0F, c_Area_rs.line1_o.getEnd_ro().getPosY());
        renderEngine_po->getDebugRenderer_po()->drawLine_v(transform_o.getWorldMatrix_ro(), c_Start1_ro, c_End1_ro, v_Color_o);
      }
    }
  }

  Vector3f BaseBowlView::getCameraPosition_o(RealCamera_e i_Camera_e) const
  {
    me3d::Vector3f v_CamPos_o;

    if (NULL != desc_s.realCams_apo[i_Camera_e])
    {
      mecl::model::Pinhole<float32_t>& pinHole = mecl::model::Pinhole<float32_t>::get_rx(desc_s.realCams_apo[i_Camera_e]->getImager_rx());
      me3d::Pinholef::Config_s v_PinHoleConfig_s;
      pinHole.copyConfig_v(v_PinHoleConfig_s);
      v_CamPos_o = me3d::Vector3f(v_PinHoleConfig_s.extrinsic_s.pos_x);
    }

    return v_CamPos_o;
  }

  Vector2f BaseBowlView::getFrontAxisOffset_o() const
  {
    Vector3f v_FrontPos_o = getCameraPosition_o(e_RcFront);
    Vector3f v_RearPos_o  = getCameraPosition_o(e_RcRear );

    Vector2f v_Offset_o;
    v_Offset_o(0) = ( v_FrontPos_o.getPosX() + v_RearPos_o.getPosX() ) * -0.5F;
    return v_Offset_o;
  }

  void BaseBowlView::createCameraBounds_v()
  {
    for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RcCount; ++v_I_u32)
    {
      // Get camera position
      RealCamera_e v_Camera_e = static_cast<RealCamera_e>(v_I_u32);

      if (NULL == desc_s.realCams_apo[v_Camera_e])
      {
        continue;
      }

      mecl::model::Pinhole<float32_t>& pinHole = mecl::model::Pinhole<float32_t>::get_rx(desc_s.realCams_apo[v_Camera_e]->getImager_rx());
      Vector3f v_CamCenterMecl_o = pinHole.getCameraCenter_x();

      Vector3f v_CamCenterGL_o = unProject_o(v_CamCenterMecl_o);

      float32_t v_HalfXLength_f32 = static_cast<float32_t>(desc_s.xlength_u32) / 2.0F;
      float32_t v_HalfYLength_f32 = static_cast<float32_t>(desc_s.ylength_u32) / 2.0F;

      Vector2f v_Min_o(0.0F, 0.0F);
      Vector2f v_Max_o(0.0F, 0.0F);

      // create bounding boxes for each camera
      switch (v_Camera_e)
      {
      case e_RcLeft:
        {
          v_Min_o(0) = -v_HalfXLength_f32;
          v_Min_o(1) = -v_HalfYLength_f32;

          v_Max_o(0) = v_CamCenterGL_o.getPosX();
          v_Max_o(1) = v_HalfYLength_f32;

          break;
        }

      case e_RcRight:
        {
          v_Min_o(0) = v_CamCenterGL_o.getPosX();
          v_Min_o(1) = -v_HalfYLength_f32;

          v_Max_o(0) = v_HalfXLength_f32;
          v_Max_o(1) = v_HalfYLength_f32;

          break;
        }

      case e_RcFront:
        {
          v_Min_o(0) = -v_HalfXLength_f32;
          v_Min_o(1) = -v_HalfYLength_f32;

          v_Max_o(0) = v_HalfXLength_f32;
          v_Max_o(1) = v_CamCenterGL_o.getPosZ();

          break;
        }

      case e_RcRear:
        {
          v_Min_o(0) = -v_HalfXLength_f32;
          v_Min_o(1) = v_CamCenterGL_o.getPosZ();

          v_Max_o(0) = v_HalfXLength_f32;
          v_Max_o(1) = v_HalfYLength_f32;

          break;
        }

      case e_RcCount: // fall through
      default:
        {
          Assert(false);
          break;
        }
      }

      cameraBounds_as[v_Camera_e].min_o = v_Min_o;
      cameraBounds_as[v_Camera_e].max_o = v_Max_o;

      Assert(cameraBounds_as[v_Camera_e].isEmpty_b() == false);

    }

  }


  void BaseBowlView::createDefaultStitchingLines_v()
  {
    // get Box reference for shorter access
    const BBox2D_s& c_Left_rs  = cameraBounds_as[e_RcLeft ];
    const BBox2D_s& c_Right_rs = cameraBounds_as[e_RcRight];
    const BBox2D_s& c_Front_rs = cameraBounds_as[e_RcFront];
    const BBox2D_s& c_Rear_rs  = cameraBounds_as[e_RcRear ];

    // overlap all the bounding boxes
    BBox2D_s v_RL_s = BBox2D_s::overlap_s( c_Rear_rs,  c_Left_rs);
    BBox2D_s v_FL_s = BBox2D_s::overlap_s(c_Front_rs,  c_Left_rs);
    BBox2D_s v_FR_s = BBox2D_s::overlap_s(c_Front_rs, c_Right_rs);
    BBox2D_s v_RR_s = BBox2D_s::overlap_s( c_Rear_rs, c_Right_rs);

    stitchingAreas_as[e_SaRearLeft  ].bounds_o    = v_RL_s;
    stitchingAreas_as[e_SaFrontLeft ].bounds_o    = v_FL_s;
    stitchingAreas_as[e_SaFrontRight].bounds_o    = v_FR_s;
    stitchingAreas_as[e_SaRearRight ].bounds_o    = v_RR_s;

    stitchingAreas_as[e_SaRearLeft  ].bounds_o.max_o.setPosX(stitchingAreas_as[e_SaRearLeft  ].bounds_o.max_o.getPosX() - 0.25F);
    stitchingAreas_as[e_SaFrontLeft ].bounds_o.max_o.setPosX(stitchingAreas_as[e_SaFrontLeft ].bounds_o.max_o.getPosX() - 0.25F);
    stitchingAreas_as[e_SaRearRight ].bounds_o.max_o.setPosX(stitchingAreas_as[e_SaRearRight ].bounds_o.max_o.getPosX() + 0.25F);
    stitchingAreas_as[e_SaFrontRight].bounds_o.max_o.setPosX(stitchingAreas_as[e_SaFrontRight].bounds_o.max_o.getPosX() + 0.25F);

    // make sure we have valid boxes
    if ((true == v_RL_s.isEmpty_b()) ||
        (true == v_FL_s.isEmpty_b()) ||
        (true == v_FR_s.isEmpty_b()) ||
        (true == v_RR_s.isEmpty_b())  )
    {
      ME_Debugger_F_Printf_v("BowlView - Invalid Camera Config, createDefaultStitchingLines_v failed \n");
    }

    // now get the stitching line for each stitching area
    float32_t v_EndOffset_f32 = 20.0F;
    float32_t v_StartOffset_f32 = 1.0F;

    // Left = Rear Left
    Vector2f v_Line0Start_o = Vector2f(v_RL_s.max_o(0) - v_StartOffset_f32, v_RL_s.min_o(1));
    Vector2f v_Line1Start_o = Vector2f(v_RL_s.max_o(0),                     v_RL_s.min_o(1) + v_StartOffset_f32);
    Vector2f v_Line0End_o   = Vector2f(v_RL_s.min_o(0),                     v_RL_s.max_o(1) - v_EndOffset_f32);
    Vector2f v_Line1End_o   = Vector2f(v_RL_s.min_o(0) + v_EndOffset_f32,   v_RL_s.max_o(1));

    stitchingAreas_as[e_SaRearLeft].line0_o.set_v(v_Line0Start_o, v_Line0End_o);
    stitchingAreas_as[e_SaRearLeft].line1_o.set_v(v_Line1Start_o, v_Line1End_o);

#if 0
    stitchingAreas_as[e_SaRearLeft].line0_o.setAngle_f32(170.0F);
    stitchingAreas_as[e_SaRearLeft].line1_o.setAngle_f32(150.0F);

    stitchingAreas_as[e_SaRearLeft].line1_o.setLength_f32(100.0F);
    stitchingAreas_as[e_SaRearLeft].line0_o.setLength_f32(100.0F);
#endif

    // Front = Front Left
    v_Line0Start_o = Vector2f(v_FL_s.max_o(0) - v_StartOffset_f32,  v_FL_s.max_o(1));
    v_Line1Start_o = Vector2f(v_FL_s.max_o(0),                      v_FL_s.max_o(1) - v_StartOffset_f32);
    v_Line0End_o   = Vector2f(v_FL_s.min_o(0),                      v_FL_s.min_o(1) + v_EndOffset_f32);
    v_Line1End_o   = Vector2f(v_FL_s.min_o(0) + v_EndOffset_f32,    v_FL_s.min_o(1));

    stitchingAreas_as[e_SaFrontLeft].line0_o.set_v(v_Line0Start_o, v_Line0End_o);
    stitchingAreas_as[e_SaFrontLeft].line1_o.set_v(v_Line1Start_o, v_Line1End_o);

#if 0
    stitchingAreas_as[e_SaFrontLeft].line0_o.setAngle_f32(190.0F);
    stitchingAreas_as[e_SaFrontLeft].line1_o.setAngle_f32(210.0F);

    stitchingAreas_as[e_SaFrontLeft].line1_o.setLength_f32(100.0F);
    stitchingAreas_as[e_SaFrontLeft].line0_o.setLength_f32(100.0F);
#endif

    // Right = Front Right
    v_Line0Start_o = Vector2f(v_FR_s.min_o(0),                      v_FR_s.max_o(1) - v_StartOffset_f32);
    v_Line1Start_o = Vector2f(v_FR_s.min_o(0) + v_StartOffset_f32,  v_FR_s.max_o(1));
    v_Line0End_o   = Vector2f(v_FR_s.max_o(0) - v_EndOffset_f32,    v_FR_s.min_o(1));
    v_Line1End_o   = Vector2f(v_FR_s.max_o(0),                      v_FR_s.min_o(1) + v_EndOffset_f32);

    stitchingAreas_as[e_SaFrontRight].line0_o.set_v(v_Line0Start_o, v_Line0End_o);
    stitchingAreas_as[e_SaFrontRight].line1_o.set_v(v_Line1Start_o, v_Line1End_o);

#if 0
    stitchingAreas_as[e_SaFrontRight].line0_o.setAngle_f32(330.0F);
    stitchingAreas_as[e_SaFrontRight].line1_o.setAngle_f32(350.0F);

    stitchingAreas_as[e_SaFrontRight].line1_o.setLength_f32(100.0F);
    stitchingAreas_as[e_SaFrontRight].line0_o.setLength_f32(100.0F);
#endif

    // Rear = Rear Right
    v_Line0Start_o = Vector2f(v_RR_s.min_o(0),                      v_RR_s.min_o(1) + v_StartOffset_f32);
    v_Line1Start_o = Vector2f(v_RR_s.min_o(0) + v_StartOffset_f32,  v_RR_s.min_o(1));
    v_Line0End_o   = Vector2f(v_RR_s.max_o(0) - v_EndOffset_f32,    v_RR_s.max_o(1));
    v_Line1End_o   = Vector2f(v_RR_s.max_o(0),                      v_RR_s.max_o(1) - v_EndOffset_f32);

    stitchingAreas_as[e_SaRearRight].line0_o.set_v(v_Line0Start_o, v_Line0End_o);
    stitchingAreas_as[e_SaRearRight].line1_o.set_v(v_Line1Start_o, v_Line1End_o);

#if 0
    stitchingAreas_as[e_SaRearRight].line0_o.setAngle_f32(30.0F);
    stitchingAreas_as[e_SaRearRight].line1_o.setAngle_f32(10.0F);

    stitchingAreas_as[e_SaRearRight].line1_o.setLength_f32(100.0F);
    stitchingAreas_as[e_SaRearRight].line0_o.setLength_f32(100.0F);
#endif
  }



} // namespace me3d

