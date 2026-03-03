#include "Camera.h"

#include "Utilities/InputHandler.h"
#include "MeclCfg.h"
#include "Common/Device/Device3DTypes.h"
#include "Common/RenderEngine.h"
#include "Math/MathLib.h"
#include "Common/Device/Device3D.h"

namespace me3d
{

Camera::Camera()
  : renderEngine_po(NULL)
  , viewDesc_s()
  , projDesc_s()
  , matView_o()
  , matViewInv_o()
  , matProj_o()
  , matProjInv_o()
  , matViewProj_o()
  , matViewProjInv_o()
  , updateFrustum_b (true)
{
  viewDesc_s.from_o = Vector3f( 10.921753F,   227.80615F,    164.17328F);
  viewDesc_s.at_o   = Vector3f( 10.832291F,   227.04008F,    163.53677F);
  viewDesc_s.up_o   = Vector3f(- 0.10660730F, 0.64278722F,    -0.75859040F);
  viewDesc_s.direction_o  = viewDesc_s.at_o - viewDesc_s.from_o;
  viewDesc_s.direction_o  = normalize_o(viewDesc_s.direction_o);
}

Camera::~Camera()
{

}


void Camera::init_v(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;
}

void Camera::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  mecl::core::UnusedParameter(i_Width_u32);
  mecl::core::UnusedParameter(i_Height_u32);

  updateFrustum_b  = true;

  updateMatrices_v();
  updateFrustum_v();
}

void Camera::update_v(const ViewDesc_s& i_ViewDesc_rs, const float32_t* i_FoV_pf32 /*=NULL*/)
{
  viewDesc_s = i_ViewDesc_rs;

  if (NULL != i_FoV_pf32)
  {
    projDesc_s.foV_f32 = *i_FoV_pf32;
  }

  updateFrustum_b  = true;

  updateMatrices_v();
  updateFrustum_v();
}

void Camera::update_v(const ViewDesc_s& i_ViewDesc_rs, const ProjectionDesc_s& i_ProjDesc_rs)
{
  viewDesc_s = i_ViewDesc_rs;
  projDesc_s = i_ProjDesc_rs;

  updateFrustum_b = true;

  updateMatrices_v();
  updateFrustum_v();

  updateInput_v();
}

void Camera::updateInput_v()
{
  Vector3f v_Movement_o;
  const float32_t c_SpeedModifier_f32 = 2.0F; //0.05F;
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyW))
  {
    v_Movement_o.setPosX(c_SpeedModifier_f32);
  }
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyS))
  {
    v_Movement_o.setPosX(-c_SpeedModifier_f32);
  }
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyA))
  {
    v_Movement_o.setPosY(c_SpeedModifier_f32);
  }
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyD))
  {
    v_Movement_o.setPosY(-c_SpeedModifier_f32);
  }
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyQ))
  {
    v_Movement_o.setPosZ(c_SpeedModifier_f32);
  }
  if (SingletonInput::getInstance_rx().isKeyDown_b(e_KeyE))
  {
    v_Movement_o.setPosZ(-c_SpeedModifier_f32);
  }

  if (mecl::math::unequal_x(v_Movement_o.getPosX(), 0.0F) ||
      mecl::math::unequal_x(v_Movement_o.getPosY(), 0.0F) ||
      mecl::math::unequal_x(v_Movement_o.getPosZ(), 0.0F) )
  {
    move_v(v_Movement_o.getPosX(), v_Movement_o.getPosY(), v_Movement_o.getPosZ());
  }

  if (SingletonInput::getInstance_rx().isButtonDown_b(e_ButtonRight))
  {
    float32_t v_MouseDeltaX_f32 = SingletonInput::getInstance_rx().getMouseDeltaX_f32();
    float32_t v_MouseDeltaY_f32 = SingletonInput::getInstance_rx().getMouseDeltaY_f32();

    
    if (mecl::math::unequal_x(v_MouseDeltaX_f32, 0.0F) || 
        mecl::math::unequal_x(v_MouseDeltaY_f32, 0.0F))
    {
      rotate_v(v_MouseDeltaX_f32, v_MouseDeltaY_f32, 0.0F);
    }
  }

  float32_t v_MouseWheelDelta_f32 = SingletonInput::getInstance_rx().getMouseWheelDelta_f32();
  if (mecl::math::unequal_x(v_MouseWheelDelta_f32, 0.0F))
  {
    zoom_v(v_MouseWheelDelta_f32 * 2.0F);
  }
  SingletonInput::getInstance_rx().resetMouseDelta_v();
}

void Camera::move_v(float32_t i_Forward_f32, float32_t i_Sideward_f32, float32_t i_Upward_f32)
{
  Vector3f v_NormalForward_o  = normalize_o(Vector3f(viewDesc_s.direction_o.getPosX(), viewDesc_s.direction_o.getPosY(), viewDesc_s.direction_o.getPosZ()));
  Vector3f v_NormalSideward_o = viewDesc_s.up_o.cross(v_NormalForward_o);
  Vector3f v_Translation_o    = static_cast<Vector3f>(v_NormalForward_o  * i_Forward_f32  + 
                                                      v_NormalSideward_o * i_Sideward_f32 + 
                                                      viewDesc_s.up_o    * i_Upward_f32   );

  viewDesc_s.from_o     += v_Translation_o;
  viewDesc_s.at_o       += v_Translation_o;

  Vector3f v_Direction_o = static_cast<Vector3f>(viewDesc_s.at_o - viewDesc_s.from_o);
  viewDesc_s.direction_o = normalize_o(v_Direction_o);

  updateFrustum_b  = true;
}

void Camera::rotate_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
{
  Vector3f v_NormalForward_o  = normalize_o(Vector3f(viewDesc_s.direction_o.getPosX(), viewDesc_s.direction_o.getPosY(), viewDesc_s.direction_o.getPosZ()));
  Vector3f v_NormalSideward_o = viewDesc_s.up_o.cross(v_NormalForward_o);

  Quaternionf v_XRot_o;
  v_XRot_o.fromAngleAxis(mecl::math::toRadians_x(-i_Y_f32),  v_NormalSideward_o);
  Quaternionf v_YRot_o;
  v_YRot_o.fromAngleAxis(mecl::math::toRadians_x(i_X_f32),  Vector3f(0.0F, 1.0F, 0.0F));
  Quaternionf v_ZRot_o;
  v_ZRot_o.fromAngleAxis(mecl::math::toRadians_x(i_Z_f32),  Vector3f(0.0F, 0.0F, 1.0F));

  Quaternionf v_Rotation_o = v_YRot_o * v_XRot_o * v_ZRot_o;

  Vector3f v_TransformedDirection_o = static_cast<Vector3f>(viewDesc_s.from_o - viewDesc_s.at_o);
  v_TransformedDirection_o = static_cast<Vector3f>(Quaternionf::transform(v_TransformedDirection_o, v_Rotation_o));
  viewDesc_s.from_o = normalize_o(v_TransformedDirection_o) + viewDesc_s.at_o;
  viewDesc_s.up_o = static_cast<Vector3f>(Quaternionf::transform(viewDesc_s.up_o, v_Rotation_o));

  Vector3f v_Direction_o = static_cast<Vector3f>(viewDesc_s.at_o - viewDesc_s.from_o);
  viewDesc_s.direction_o = normalize_o(v_Direction_o);

  updateFrustum_b  = true;
}

void Camera::zoom_v(float32_t i_Factor_f32)
{
  Vector3f v_NormalForward_o = normalize_o(Vector3f(viewDesc_s.direction_o.getPosX(), viewDesc_s.direction_o.getPosY(), viewDesc_s.direction_o.getPosZ()));
  Vector3f v_Translation_o   = static_cast<Vector3f>(v_NormalForward_o  * i_Factor_f32);

  viewDesc_s.from_o += v_Translation_o;
  viewDesc_s.at_o   += v_Translation_o;

  updateFrustum_b  = true;
}

void Camera::getMouseRay_v(Vector3f& o_RayStart_ro, Vector3f& b_RayDirection_ro, Vector3f& b_RayEndPos_ro, const Vector2f& i_MousePos_ro)
{
  updateMatrices_v();

  ViewPortDesc_s v_VP_s;
  renderEngine_po->getDevice_po()->getViewPort_b(v_VP_s);
  
  transformScreenToWorldRay_v(i_MousePos_ro, 
                              v_VP_s.width_u32, 
                              v_VP_s.height_u32, 
                              matProjInv_o, 
                              matViewInv_o, 
                              o_RayStart_ro, 
                              b_RayDirection_ro,
                              &b_RayEndPos_ro);
}

void Camera::updateMatrices_v()
{
  ViewPortDesc_s v_VpDesc_s;
  renderEngine_po->getDevice_po()->getViewPort_b(v_VpDesc_s);

  projDesc_s.aspectRatio_f32 = static_cast<float32_t>(v_VpDesc_s.width_u32) / static_cast<float32_t>(v_VpDesc_s.height_u32);
  matProj_o = Matrix4f::createPerspectiveRH(projDesc_s.foV_f32, projDesc_s.aspectRatio_f32, projDesc_s.nearClip_f32, projDesc_s.farClip_f32);
  matProjInv_o = matrixInvert_o(matProj_o);

  // create view matrix
  matView_o = Matrix4f::createViewRH(viewDesc_s.from_o, viewDesc_s.at_o, viewDesc_s.up_o);
  matViewInv_o = matrixInvert_o(matView_o);

  // create view projection matrix
  matViewProj_o = matView_o.mmulFast(matProj_o);
  matViewProjInv_o = matrixInvert_o(matViewProj_o);
}

void Camera::updateFrustum_v()
{
  if (true == updateFrustum_b)
  {
    updateFrustum_b = false;

    

     // TODO: implement
  }
}

}; // namespace me3d