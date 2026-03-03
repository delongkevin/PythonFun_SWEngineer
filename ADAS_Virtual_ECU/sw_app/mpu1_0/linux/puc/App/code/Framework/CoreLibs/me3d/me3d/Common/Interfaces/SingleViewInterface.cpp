#include "SingleViewInterface.h"
#include "Common/Manager/ViewManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/RenderInterface.h"
#include "Common/RenderEngine.h"
#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/View/SingleView.h"
#include "Common/Resources/Texture.h"

// PRQA S 3103 EOF // by design

namespace me3d
{
  SingleViewInterface::SingleViewInterface()
    : renderInterface_po(NULL)
  {

  }

  SingleViewInterface::~SingleViewInterface()
  {

  }

  void SingleViewInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
  }

  uint32_t SingleViewInterface::msgCreate_u32(const SingleViewDesc_s& i_Desc_rs)const
  {
    BaseView* v_SingleView_po = renderInterface_po->renderEngine_o.getViewManager_po()->createSingleView_po(i_Desc_rs);

    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    Assert(NULL != v_SingleView_po);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_SingleView_po), e_OtSingleView);

    return v_ID_u32;
  }

  bool SingleViewInterface::msgRelease_b(uint32_t i_Id_u32)const
  {
    bool v_Success_b = false;

    if (i_Id_u32 != RenderInterface::c_InvalidGUID_u32)
    {
      BaseView* v_SingleView_po = reinterpret_cast<BaseView*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtSingleView));

      if (NULL != v_SingleView_po)
      {
        renderInterface_po->renderEngine_o.getViewManager_po()->releaseView_v(v_SingleView_po);

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgRender_b(uint32_t i_Id_u32)const
  {
    BaseView* v_SingleView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    Assert(NULL != v_SingleView_po);

    renderInterface_po->renderEngine_o.getViewManager_po()->setRender_v(v_SingleView_po);

    return true;
  }

  bool SingleViewInterface::msgUpdate_b(uint32_t i_Id_u32, uint32_t i_Flags_u32)const
  {
    bool v_Success_b = false;

    BaseView* v_SingleView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->update_v(i_Flags_u32);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetTexture_b(uint32_t i_Id_u32, const MEString& i_Name_ro)const 
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      Texture* v_Texture_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createTexture_po(i_Name_ro);
      if (v_Texture_po != NULL)
      {
        v_SingleView_po->getDesc_ps()->texture_po = v_Texture_po;

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetSingleViewTexture_b(uint32_t i_Id_u32, uint32_t i_TextureId_u32)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      Texture* v_Texture_po = reinterpret_cast<Texture*>(renderInterface_po->getAtID_pv(i_TextureId_u32, e_OtTexture));

      if (v_Texture_po != NULL)
      {
        v_SingleView_po->getDesc_ps()->texture_po = v_Texture_po;

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgGetSingleViewDesc_b(uint32_t i_Id_u32, me3d::SingleViewDesc_s& o_SingleViewDesc_rs)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      o_SingleViewDesc_rs = *v_SingleView_po->getDesc_ps();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetTransform_b(uint32_t i_Id_u32, const Transform& i_Transform_ro)const
  {
    bool v_Success_b = false;

    BaseView* v_SingleView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->setTransform_v(i_Transform_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgIntersectRay_b(uint32_t i_Id_u32, const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)const
  {
    bool v_Intersect_b = false;

    BaseView* v_SingleView_po = reinterpret_cast<BaseView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_Intersect_b = v_SingleView_po->intersectRay_b(i_RayOrigin_ro, i_RayDir_ro, o_Intersection_ro);
    }

    return v_Intersect_b;
  }

  bool SingleViewInterface::msgSetDimensions_b(uint32_t i_Id_u32, const Vector2f& i_Dimensions_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->getDesc_ps()->numVerticesX_u32 = static_cast<uint32_t>(i_Dimensions_ro.getPosX());
      v_SingleView_po->getDesc_ps()->numVerticesY_u32 = static_cast<uint32_t>(i_Dimensions_ro.getPosY());

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgGetDimensions_b(uint32_t i_Id_u32, Vector2f& o_Dimensions_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      o_Dimensions_ro(0) = static_cast<float32_t>(v_SingleView_po->getDesc_ps()->numVerticesX_u32);
      o_Dimensions_ro(1) = static_cast<float32_t>(v_SingleView_po->getDesc_ps()->numVerticesY_u32);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetRealCamera_b(uint32_t i_Id_u32, Cameraf* i_Camera_po)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->getDesc_ps()->realCam_po = i_Camera_po;
      v_SingleView_po->updateSingleView_v();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetSyntheticCamera_b(uint32_t i_Id_u32, Cameraf* i_Camera_po) const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->getDesc_ps()->syntCam_po = i_Camera_po;
      v_SingleView_po->updateSingleView_v();

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgSetSize_b(uint32_t i_Id_u32, const Vector2f& i_Size_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      v_SingleView_po->getDesc_ps()->width_f32 = i_Size_ro(0);
      v_SingleView_po->getDesc_ps()->height_f32 = i_Size_ro(1);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgGetSize_b(uint32_t i_Id_u32, Vector2f& o_Size_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      o_Size_ro(0) = v_SingleView_po->getDesc_ps()->width_f32;
      o_Size_ro(1) = v_SingleView_po->getDesc_ps()->height_f32;

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgProject_b(uint32_t i_Id_u32, const Vector3f& i_GlPosition_ro, Vector3f& o_MeclPosition_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      o_MeclPosition_ro = v_SingleView_po->project_o(i_GlPosition_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool SingleViewInterface::msgUnProject_b(uint32_t i_Id_u32, const Vector3f& i_MeclPosition_ro, Vector3f& o_GlPosition_ro)const
  {
    bool v_Success_b = false;

    SingleView* v_SingleView_po = reinterpret_cast<SingleView*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtSingleView));

    if (NULL != v_SingleView_po)
    {
      o_GlPosition_ro = v_SingleView_po->unProject_o(i_MeclPosition_ro);

      v_Success_b = true;
    }

    return v_Success_b;
  }

} // namespace me3d
