#include "Common/Manager/CameraManager.h"

#include "Common/RenderEngine.h"
#include "Common/Manager/ConstantsManager.h"

namespace me3d
{

CameraManager::CameraManager()
  : IManager()
  , camera_o()
  , constants_s()
{

}

CameraManager::~CameraManager()
{

}

bool_t CameraManager::isEnabled_b()
{
  return true;
}

bool CameraManager::create_b(RenderEngine* b_RenderEngine_po)
{
  camera_o.init_v(b_RenderEngine_po);

  constants_s.viewProj_po = b_RenderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMtxViewProj", e_CtMatrix4, 1U));
  constants_s.view_po     = b_RenderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMtxView", e_CtMatrix4, 1U));
  constants_s.proj_po     = b_RenderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cMtxProj", e_CtMatrix4, 1U));
  constants_s.position_po = b_RenderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cCamPos", e_CtFloat3, 1U));


  return true;
}

void CameraManager::release_v()
{

}

void CameraManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  camera_o.onResize_v(i_Width_u32, i_Height_u32);
}

void CameraManager::beginFrame_v()
{
  camera_o.updateInput_v();

  updateConstants_v();
}

void CameraManager::preRender_v()
{

}

void CameraManager::updateConstants_v()
{
  const Matrix4f& c_ViewProjMat_ro = camera_o.getViewProjMat_ro();
  constants_s.viewProj_po->setData_v(&c_ViewProjMat_ro);

  const Matrix4f& c_ViewMat_ro = camera_o.getViewMat_ro();
  constants_s.view_po->setData_v(&c_ViewMat_ro);

  const Matrix4f& c_ProjMat_ro = camera_o.getProjMat_ro();
  constants_s.proj_po->setData_v(&c_ProjMat_ro);

  constants_s.position_po->setData_v(&camera_o.getPos_ro());
}


} // namespace me3d
