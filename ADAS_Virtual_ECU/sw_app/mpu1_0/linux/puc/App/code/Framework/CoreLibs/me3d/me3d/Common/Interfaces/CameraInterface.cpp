#include "Common/Interfaces/CameraInterface.h"

#include "Common/RenderInterface.h"
#include "Common/Manager/CameraManager.h"

namespace me3d
{
  CameraInterface::CameraInterface()
    : cameraManager_po(NULL)
  {
  }

  CameraInterface::~CameraInterface()
  {
  }

  void CameraInterface::create_v(CameraManager* b_CamManager_po)
  {
    cameraManager_po = b_CamManager_po;
  }

  void CameraInterface::msgSet_v(const ViewDesc_s& i_ViewDesc_rs, const float32_t* i_FoV_pf32 /*= NULL*/)const
  {
    cameraManager_po->getCamera_ro().update_v(i_ViewDesc_rs, i_FoV_pf32);
  }

  void CameraInterface::msgSet_v(const ViewDesc_s& i_ViewDesc_rs, const ProjectionDesc_s& i_ProjDesc_rs)const
  {
    cameraManager_po->getCamera_ro().update_v(i_ViewDesc_rs, i_ProjDesc_rs);
  }

  void CameraInterface::msgGet_v(ViewDesc_s& b_ViewDesc_rs)const
  {
    b_ViewDesc_rs = cameraManager_po->getCamera_ro().getViewDesc_rs();
  }

  void CameraInterface::msgGetMouseRay_v(Vector3f& o_RayStart_ro, Vector3f& b_RayDirection_ro, Vector3f& b_RayEndPos_ro, const Vector2f& i_MousePos_ro)const
  {
    cameraManager_po->getCamera_ro().getMouseRay_v(o_RayStart_ro, b_RayDirection_ro, b_RayEndPos_ro, i_MousePos_ro);
  }

} // namespace me3d