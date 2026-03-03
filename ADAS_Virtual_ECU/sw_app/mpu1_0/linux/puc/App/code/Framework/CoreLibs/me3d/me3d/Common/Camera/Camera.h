//--------------------------------------------------------------------------                                                                                                           
/// @file Camera.h                                                                         
/// @brief Holds the view and projection matrices. Calculates camera frustum (in the future)
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CAMERA_H
#define CAMERA_H

#include "Common/Camera/CameraTypes.h"

namespace me3d
{

class RenderEngine;

class Camera
{
public:
  Camera();
  ~Camera();

  void init_v(RenderEngine* b_RenderEngine_po);

  void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);

  void update_v(const ViewDesc_s& i_ViewDesc_rs, const float32_t* i_FoV_pf32 = NULL);
  void update_v(const ViewDesc_s& i_ViewDesc_rs, const ProjectionDesc_s& i_ProjDesc_rs);
  void updateInput_v();

  void move_v(float32_t i_Forward_f32, float32_t i_Sideward_f32, float32_t i_Upward_f32);

  void rotate_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32);

  void zoom_v(float32_t i_Factor_f32);

  void getMouseRay_v(Vector3f& o_RayStart_ro, Vector3f& b_RayDirection_ro, Vector3f& b_RayEndPos_ro, const Vector2f& i_MousePos_ro);

  inline const Matrix4f& getProjMat_ro()
  {
    updateMatrices_v();

    return matProj_o;
  }

  inline const Matrix4f& getViewMat_ro()
  {
    updateMatrices_v();

    return matView_o;
  }

  inline const Matrix4f& getViewProjMat_ro()
  {
    updateMatrices_v();

    return matViewProj_o;
  }

  inline const Vector3f& getPos_ro() const
  { 
    return viewDesc_s.from_o; 
  }

  inline const Vector3f& getLookAt_ro() const
  { 
    return viewDesc_s.at_o; 
  }

  inline const ViewDesc_s& getViewDesc_rs() const
  {
    return viewDesc_s;
  }

  inline float32_t getFoV_f32() const
  {
    return projDesc_s.foV_f32;
  }

protected:
  void updateMatrices_v();
  void updateFrustum_v();

private:
  RenderEngine*     renderEngine_po;
  ViewDesc_s        viewDesc_s; 
  ProjectionDesc_s  projDesc_s;

  Matrix4f          matView_o;
  Matrix4f          matViewInv_o;

  Matrix4f          matProj_o;
  Matrix4f          matProjInv_o;

  Matrix4f          matViewProj_o;
  Matrix4f          matViewProjInv_o;

  bool              updateFrustum_b;
};

} // namespace me3d

#endif