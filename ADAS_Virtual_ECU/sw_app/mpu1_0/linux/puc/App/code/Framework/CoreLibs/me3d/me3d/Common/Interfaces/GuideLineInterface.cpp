#include "Common/Interfaces/GuideLineInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Manager/GuideLineManager.h"

namespace me3d
{
  GuideLineInterface::GuideLineInterface()
    : renderInterface_po(NULL)
  {
  }

  GuideLineInterface::~GuideLineInterface()
  {
  }

  void GuideLineInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
  }

  uint32_t GuideLineInterface::msgCreate_u32(const GuideLineObjectDesc_s& i_Desc_rs)const
  {
    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    GuideLineObject* v_GuideLineObject_ps = renderInterface_po->renderEngine_o.getGuideLineManager_po()->createGuideLine_po(i_Desc_rs);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_GuideLineObject_ps), e_OtGuideLine);

    return v_ID_u32;
  }

  bool_t GuideLineInterface::msgRelease_b(uint32_t i_Id_u32)const
  {
    bool v_Success_b = false;

    if (i_Id_u32 != RenderInterface::c_InvalidGUID_u32)
    {
      GuideLineObject* v_GuideLineObject_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtGuideLine));

      if (NULL != v_GuideLineObject_po)
      {
        renderInterface_po->renderEngine_o.getGuideLineManager_po()->releaseGuideLine_v(v_GuideLineObject_po);

        v_Success_b = true;
      }
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgUpdatePath_b(uint32_t i_Id_u32, const mepl::vector<Vector3f>& i_Path_rs)const
  {
    bool v_Success_b = false;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    if (NULL != v_GuideLine_po)
    {
      v_Success_b = v_GuideLine_po->updatePath_b(i_Path_rs);
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgSetUseOrthoProj_b(uint32_t i_Id_u32, bool_t i_UseOrthoProj_b)const
  {
    bool v_Success_b = false;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    if (NULL != v_GuideLine_po)
    {
      v_GuideLine_po->setUseOrthoProj_v(i_UseOrthoProj_b);
      v_GuideLine_po->update_b(e_GlufConstants);
      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgSetWorldMatrix_b(uint32_t i_Id_u32, const me3d::Matrix4f& i_World_ro)const
  {
    bool v_Success_b = false;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    if (NULL != v_GuideLine_po)
    {
      v_Success_b = true;
      v_GuideLine_po->setWorldMatrix_v(i_World_ro);
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgSetColor_b(uint32_t i_Id_u32, const me3d::Color& i_Color_ro)const
  {
    bool v_Success_b = false;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    if (NULL != v_GuideLine_po)
    {
      v_Success_b = true;
      v_GuideLine_po->setColor_v(i_Color_ro);
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgGetBoundingBox_b(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const
  {
    bool v_Success_b = false;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    if (NULL != v_GuideLine_po)
    {
      v_Success_b = true;
      o_Bounds_ro = v_GuideLine_po->getBounds_ro();
    }

    return v_Success_b;
  }

  bool_t GuideLineInterface::msgRender_b(uint32_t i_Id_u32)const
  {
    bool v_Success_b = true;

    GuideLineObject* v_GuideLine_po = reinterpret_cast<GuideLineObject*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtGuideLine));

    Assert(NULL != v_GuideLine_po);

    renderInterface_po->renderEngine_o.getGuideLineManager_po()->setRender_v(v_GuideLine_po);

    return v_Success_b;
  }

  
} // namespace me3d