#include "BowlViewInterface.h"
#include "Common/Manager/ViewManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/RenderInterface.h"
#include "Common/RenderEngine.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/View/BowlView.h"
#include "Common/Resources/Texture.h"

// PRQA S 3103 EOF // needed for fast object lut
// PRQA S 3706 EOF // to access descriptor values

namespace me3d
{
  BowlViewInterface::BowlViewInterface()
    : renderInterface_po(NULL)
  {

  }

  BowlViewInterface::~BowlViewInterface()
  {

  }

  void BowlViewInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
  }

  uint32_t BowlViewInterface::msgCreate_u32(const BowlViewDesc_s& i_Desc_rs)const
  {
    BaseView* v_BowlView_po = renderInterface_po->renderEngine_o.getViewManager_po()->createBowlView_po(i_Desc_rs);

    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    Assert(NULL != v_BowlView_po);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_BowlView_po), e_OtBowlView);

    return v_ID_u32;
  }

  bool BowlViewInterface::msgRelease_b(uint32_t i_Id_u32)const
  {
    bool v_Success_b = false;

    if (i_Id_u32 != RenderInterface::c_InvalidGUID_u32)
    {
      BaseView* v_BowlView_po = reinterpret_cast<BaseView*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtBowlView));

      if (NULL != v_BowlView_po)
      {
        renderInterface_po->renderEngine_o.getViewManager_po()->releaseView_v(v_BowlView_po);

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgRender_b(uint32_t i_Id_u32)const
  {
    BaseView* v_BowlView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    Assert(NULL != v_BowlView_po);

    renderInterface_po->renderEngine_o.getViewManager_po()->setRender_v(v_BowlView_po);

    return true;
  }

  bool BowlViewInterface::msgSetBowlParameters_b(uint32_t i_Id_u32, const Vector3f& i_Params_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->getDesc_ps()->ellipseA_f32 = i_Params_ro.getPosX();
      v_BowlView_po->getDesc_ps()->ellipseB_f32 = i_Params_ro.getPosY();
      v_BowlView_po->getDesc_ps()->ellipseK_f32 = i_Params_ro.getPosZ();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetBowlParameters_b(uint32_t i_Id_u32, Vector3f& o_Params_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Params_ro.setPosX(v_BowlView_po->getDesc_ps()->ellipseA_f32);
      o_Params_ro.setPosY(v_BowlView_po->getDesc_ps()->ellipseB_f32);
      o_Params_ro.setPosZ(v_BowlView_po->getDesc_ps()->ellipseK_f32);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetBowlDeformationMethod_b(uint32_t i_Id_u32, BowlDeformationMethod_e i_Bdm_e)
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->getDesc_ps()->bowlDeformationMethod_e = i_Bdm_e;

      v_Success_b = true;
    }
  
    return v_Success_b;
  }

  bool BowlViewInterface::msgGetBowlDeformationMethod_b(uint32_t i_Id_u32, BowlDeformationMethod_e& o_Bdm_e)
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Bdm_e = v_BowlView_po->getDesc_ps()->bowlDeformationMethod_e;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetControlPoints_b(uint32_t i_Id_u32, bool i_LeftRight_b, const Vector3f& i_P0_ro, const Vector3f& i_P1_ro, const Vector3f& i_P2_ro, const Vector3f& i_P3_ro) const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      if (true == i_LeftRight_b)
      {
        v_BowlView_po->getDesc_ps()->controlPointLeftRight0_o = i_P0_ro;
        v_BowlView_po->getDesc_ps()->controlPointLeftRight1_o = i_P1_ro;
        v_BowlView_po->getDesc_ps()->controlPointLeftRight2_o = i_P2_ro;
        v_BowlView_po->getDesc_ps()->controlPointLeftRight3_o = i_P3_ro;
      }
      else
      {
        v_BowlView_po->getDesc_ps()->controlPointFrontRear0_o = i_P0_ro;
        v_BowlView_po->getDesc_ps()->controlPointFrontRear1_o = i_P1_ro;
        v_BowlView_po->getDesc_ps()->controlPointFrontRear2_o = i_P2_ro;
        v_BowlView_po->getDesc_ps()->controlPointFrontRear3_o = i_P3_ro;
      }


      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetControlPoints_b(uint32_t i_Id_u32, bool i_LeftRight_b, Vector3f& o_P0_ro, Vector3f& o_P1_ro, Vector3f& o_P2_ro, Vector3f& o_P3_ro) const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      if (true == i_LeftRight_b)
      {
        o_P0_ro = v_BowlView_po->getDesc_ps()->controlPointLeftRight0_o;
        o_P1_ro = v_BowlView_po->getDesc_ps()->controlPointLeftRight1_o;
        o_P2_ro = v_BowlView_po->getDesc_ps()->controlPointLeftRight2_o;
        o_P3_ro = v_BowlView_po->getDesc_ps()->controlPointLeftRight3_o;
      }
      else
      {
        o_P0_ro = v_BowlView_po->getDesc_ps()->controlPointFrontRear0_o;
        o_P1_ro = v_BowlView_po->getDesc_ps()->controlPointFrontRear1_o;
        o_P2_ro = v_BowlView_po->getDesc_ps()->controlPointFrontRear2_o;
        o_P3_ro = v_BowlView_po->getDesc_ps()->controlPointFrontRear3_o;
      }


      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetProjectionScale_b(uint32_t i_Id_u32, const Vector3f& i_Scale_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->getDesc_ps()->projectionScale_o = i_Scale_ro;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetProjectionScale_b(uint32_t i_Id_u32, Vector3f& o_Scale_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Scale_ro = v_BowlView_po->getDesc_ps()->projectionScale_o;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetBoundingBox_b(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Bounds_ro = v_BowlView_po->getBounds_ro();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetObscurationZone_b(uint32_t i_Id_u32, BBox2D_s& o_Bounds_ro) const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Bounds_ro = v_BowlView_po->getObscurationZone_rs();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetObscurationZone_b(uint32_t i_Id_u32, const BBox2D_s& i_Bounds_ro) const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->setObscurationZone_v(i_Bounds_ro);
      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgUpdate_b(uint32_t i_Id_u32, uint32_t i_Flags_u32)const
  {
    bool v_Success_b = false;

    BaseView* v_BaseView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BaseView_po)
    {
      v_BaseView_po->update_v(i_Flags_u32);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, const MEString& i_Name_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      Texture* v_Texture_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createTexture_po(i_Name_ro);
      if (v_Texture_po)
      {
        v_BowlView_po->getDesc_ps()->textures_apo[i_RealCamera_e] = v_Texture_po;

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, uint32_t i_TextureId_u32)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BaseBowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BaseBowlView_po)
    {
      Texture* v_Texture_po = reinterpret_cast<Texture*>(renderInterface_po->getAtID_pv(i_TextureId_u32, e_OtTexture));
      
      if (v_Texture_po != NULL)
      {
        v_BaseBowlView_po->getDesc_ps()->textures_apo[i_RealCamera_e] = v_Texture_po;
        
        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, MEString& o_Name_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BaseBowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BaseBowlView_po)
    {
      Texture* v_Texture_po = v_BaseBowlView_po->getDesc_ps()->textures_apo[i_RealCamera_e];

      if (NULL != v_Texture_po)
      {
        o_Name_ro = v_Texture_po->getFilename_ro();
      }

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetTransform_b(uint32_t i_Id_u32, const Transform& i_Transform_ro)const
  {
    bool v_Success_b = false;

    BaseView* v_BowlView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->setTransform_v(i_Transform_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetStitchingArea_b(uint32_t i_Id_u32, StitchingArea_e i_StitchingAreaType_e, const StitchingArea_s& i_Area_rs)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->setStitchingArea_v(i_StitchingAreaType_e, i_Area_rs);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetStitchingArea_b(uint32_t i_Id_u32, StitchingArea_e i_StitchingAreaType_e, StitchingArea_s& o_Area_rs)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Area_rs = v_BowlView_po->getStitchingArea_rs(i_StitchingAreaType_e);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgIntersectRay_b(uint32_t i_Id_u32, const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)const
  {
    bool v_Intersect_b = false;

    BaseView* v_BowlView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_Intersect_b = v_BowlView_po->intersectRay_b(i_RayOrigin_ro, i_RayDir_ro, o_Intersection_ro);
    }

    return v_Intersect_b;
  }

  bool BowlViewInterface::msgGetFrontAxisOffset_b(uint32_t i_Id_u32, float32_t& o_Offset_f32)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Offset_f32 = v_BowlView_po->getDesc_ps()->frontAxisOffsetX_f32;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetDimensions_b(uint32_t i_Id_u32, const Vector2f& i_Dimensions_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->getDesc_ps()->xlength_u32 = static_cast<uint32_t>(i_Dimensions_ro.getPosX());
      v_BowlView_po->getDesc_ps()->ylength_u32 = static_cast<uint32_t>(i_Dimensions_ro.getPosY());

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetDimensions_b(uint32_t i_Id_u32, Vector2f& o_Dimensions_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_Dimensions_ro(0) = static_cast<float32_t>(v_BowlView_po->getDesc_ps()->xlength_u32);
      o_Dimensions_ro(1) = static_cast<float32_t>(v_BowlView_po->getDesc_ps()->ylength_u32);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetRealCamera_b(uint32_t i_Id_u32, RealCamera_e i_RealCam_e, Cameraf* i_Camera_po)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if ((NULL != v_BowlView_po) && (i_RealCam_e != e_RcCount))
    {
      v_BowlView_po->getDesc_ps()->realCams_apo[i_RealCam_e] = i_Camera_po;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetRealCamera_b(uint32_t i_Id_u32, RealCamera_e i_RealCam_e, Cameraf** o_Camera_po)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if ((NULL != v_BowlView_po) && (i_RealCam_e != e_RcCount))
    {
      *o_Camera_po = v_BowlView_po->getDesc_ps()->realCams_apo[i_RealCam_e];

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgSetRenderStitching_b(uint32_t i_Id_u32, bool_t i_RenderStitching_b)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      v_BowlView_po->setRenderStitching_v(i_RenderStitching_b);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgGetRenderStitching_b(uint32_t i_Id_u32, bool_t& o_RenderStitching_b)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_RenderStitching_b = v_BowlView_po->getRenderStitching_b();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgProject_b(uint32_t i_Id_u32, const Vector3f& i_GlPosition_ro, Vector3f& o_MeclPosition_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_MeclPosition_ro = v_BowlView_po->project_o(i_GlPosition_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool BowlViewInterface::msgUnProject_b(uint32_t i_Id_u32, const Vector3f& i_MeclPosition_ro, Vector3f& o_GlPosition_ro)const
  {
    bool v_Success_b = false;

    BaseBowlView* v_BowlView_po = reinterpret_cast<BaseBowlView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtBowlView));

    if (NULL != v_BowlView_po)
    {
      o_GlPosition_ro = v_BowlView_po->unProject_o(i_MeclPosition_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

} // namespace me3d
