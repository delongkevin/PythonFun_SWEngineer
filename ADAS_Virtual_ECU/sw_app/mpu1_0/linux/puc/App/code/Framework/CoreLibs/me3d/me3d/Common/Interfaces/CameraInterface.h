#ifndef CAMERA_INTERFACE_H
#define CAMERA_INTERFACE_H

#include "Common/Camera/CameraTypes.h"

namespace me3d
{
  class CameraManager;

  class CameraInterface
  {
  public:
    CameraInterface();
    ~CameraInterface();

    void create_v(CameraManager* b_CamManager_po);
  
    void msgSet_v(const ViewDesc_s& i_ViewDesc_rs, const float32_t* i_FoV_pf32 = NULL)const;
    void msgSet_v(const ViewDesc_s& i_ViewDesc_rs, const ProjectionDesc_s& i_ProjDesc_rs)const;
    void msgGet_v(ViewDesc_s& b_ViewDesc_rs)const;
    void msgGetMouseRay_v(Vector3f& o_RayStart_ro, Vector3f& b_RayDirection_ro, Vector3f& b_RayEndPos_ro, const Vector2f& i_MousePos_ro)const;

  private:
    CameraManager* cameraManager_po;
  };

} // namespace me3d

#endif
