#include "Math/Transform.h"
#include "Math/MathLib.h"

#include "Utilities/InOut.h"

namespace me3d
{

// PRQA S 4054 1 // Ok here, reset_v() inits all members
Transform::Transform()
{
  reset_v();
}

Transform::~Transform()
{

}

void Transform::reset_v()
{
  parent_po = NULL;
  scale_o = Vector3f(1.0F, 1.0F, 1.0F);
  rotation_o = Quaternionf(0.0F, 0.0F, 0.0F, 1.0F);
  translation_o = Vector3f(0.0F, 0.0F, 0.0F);
  worldMatrix_o.setEye();
  computeMatrix_b = true;
}

void Transform::setParent_v(Transform* b_Parent_po)
{
  parent_po = b_Parent_po;

  computeMatrix_b = true;
}

Transform* Transform::getParent_po() const
{
  return parent_po;
}

Vector3f Transform::calcTranslation_o(const Vector3f& i_Translation_ro) const
{
  Vector3f v_NewPos_o;

  if (NULL != parent_po)
  {
    // get the inverse rotation, else we will move towards the parent's rotation
    Quaternionf v_InverseRotation_o = Quaternionf::inverse(parent_po->getGlobalRotation_o());
    v_NewPos_o  = transformVector_o(i_Translation_ro, v_InverseRotation_o); 

    // scale movement based on parent's scale. 
    v_NewPos_o /= parent_po->getGlobalScale_o();

    // add the local translation
    v_NewPos_o += getTranslation_ro();
  }
  else
  {
    v_NewPos_o = getTranslation_ro();
    v_NewPos_o += i_Translation_ro;
  }
  
  return v_NewPos_o;
}

Vector3f Transform::getGlobalTranslation_o() const
{
  Vector3f v_GlobalTranslation_o = translation_o;

  if (NULL != parent_po)
  {
    v_GlobalTranslation_o *= parent_po->getGlobalScale_o(); 
    v_GlobalTranslation_o = Quaternionf::transform(v_GlobalTranslation_o, parent_po->getGlobalRotation_o());
    v_GlobalTranslation_o += parent_po->getGlobalTranslation_o();
  }

  return v_GlobalTranslation_o;
}

const Vector3f& Transform::getTranslation_ro() const
{
  return translation_o;
}

void Transform::setTranslation_v(const Vector3f& i_Translation_ro)
{
  if (i_Translation_ro != translation_o)
  {
    translation_o = i_Translation_ro;

    computeMatrix_b = true;
  }
}

void Transform::setTranslation_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
{
  setTranslation_v(me3d::Vector3f(i_X_f32, i_Y_f32, i_Z_f32));
}

Quaternionf Transform::getGlobalRotation_o() const
{
  Quaternionf v_GlobalRotation_o = rotation_o;

  if (NULL != parent_po)
  {
    v_GlobalRotation_o *= parent_po->getGlobalRotation_o();
  }

  return v_GlobalRotation_o;
}

const Quaternionf& Transform::getRotation_ro() const
{
  return rotation_o;
}

Vector3f Transform::getEulerAngles_o() const
{
  Quaternionf v_NormalizedQuat_o = rotation_o;
  v_NormalizedQuat_o.normalize();
  Quaternionf::EulerAngles_s v_EulerAngles_s = v_NormalizedQuat_o.calcEulerAngles_s();

  return Vector3f(v_EulerAngles_s.pitch_x, v_EulerAngles_s.yaw_x, v_EulerAngles_s.roll_x);
}

me3d::Vector3f Transform::getEulerAnglesDegrees_o() const
{
  Quaternionf v_NormalizedQuat_o = rotation_o;
  v_NormalizedQuat_o.normalize();
  Quaternionf::EulerAngles_s v_EulerAngles_s = v_NormalizedQuat_o.calcEulerAngles_s();

  return Vector3f(
    mecl::math::toDegrees_x(v_EulerAngles_s.pitch_x), 
    mecl::math::toDegrees_x(v_EulerAngles_s.yaw_x), 
    mecl::math::toDegrees_x(v_EulerAngles_s.roll_x));
}

Matrix4f Transform::getRotationMatrix_o() const
{
  return rotation_o.toMatrix4x4();
}

void Transform::setRotation_v(const Quaternionf& i_Rotation_ro)
{
  rotation_o = i_Rotation_ro;

  computeMatrix_b = true;
}

void Transform::setRotation_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
{
  Quaternionf v_Xrot_o;
  v_Xrot_o.fromAngleAxis(mecl::math::toRadians_x(i_X_f32), Vector3f(1.0F, 0.0F, 0.0F));
  Quaternionf v_Yrot_o;
  v_Yrot_o.fromAngleAxis(mecl::math::toRadians_x(i_Y_f32), Vector3f(0.0F, 1.0F, 0.0F));
  Quaternionf v_Zrot_o;
  v_Zrot_o.fromAngleAxis(mecl::math::toRadians_x(i_Z_f32), Vector3f(0.0F, 0.0F, 1.0F));

  rotation_o = v_Yrot_o * v_Xrot_o * v_Zrot_o;

  computeMatrix_b = true;
}

me3d::Vector3f Transform::getGlobalScale_o() const
{
  Vector3f v_Scale_o = scale_o;

  if (NULL != parent_po)
  {
    v_Scale_o *= parent_po->getGlobalScale_o();
  }

  return v_Scale_o;
}

const Vector3f& Transform::getScale_ro() const
{
  return scale_o;
}

void Transform::setScale_v(const Vector3f& i_Scale_ro)
{
  scale_o = i_Scale_ro;

  computeMatrix_b = true;
}

void Transform::setScale_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32)
{
  scale_o(0) = i_X_f32;
  scale_o(1) = i_Y_f32;
  scale_o(2) = i_Z_f32;

  computeMatrix_b = true;
}

void Transform::toViewDesc_v(ViewDesc_s& b_Desc_rs) const
{
  b_Desc_rs.from_o = getGlobalTranslation_o();

  Quaternionf v_GlobalRot_o = getGlobalRotation_o();

  Vector3f v_Forward_o = Quaternionf::transform(Vector3f(0.0F, 0.0F, 1.0F), v_GlobalRot_o);
  b_Desc_rs.at_o = b_Desc_rs.from_o + v_Forward_o;

  b_Desc_rs.up_o = Quaternionf::transform(Vector3f(0.0F, 1.0F, 0.0F), v_GlobalRot_o);

  Vector3f v_Direction_o = static_cast<Vector3f>(b_Desc_rs.at_o - b_Desc_rs.from_o);
  b_Desc_rs.direction_o = normalize_o(v_Direction_o);
}

const Matrix4f& Transform::getWorldMatrix_ro()
{
  // PRQA S 1051 1 //  TODO: optimize
  //if (true == computeMatrix_b)
  {  
    worldMatrix_o = Matrix4f::createScale_o(scale_o.getPosX(), scale_o.getPosY(), scale_o.getPosZ());
    worldMatrix_o = worldMatrix_o.mmulFast(rotation_o.toMatrix4x4());
    worldMatrix_o = worldMatrix_o.mmulFast(Matrix4f::createTranslation_o(translation_o.getPosX(), translation_o.getPosY(), translation_o.getPosZ()));

    if (NULL != parent_po)
    {
      worldMatrix_o = worldMatrix_o.mmulFast(parent_po->getWorldMatrix_ro());
    }

    computeMatrix_b = false;
  }

  return worldMatrix_o;
}




void Transform::serialize_v(me3d::InOut& b_IO_ro)
{
  b_IO_ro.serialize_v(translation_o);
  b_IO_ro.serialize_v(rotation_o);
  b_IO_ro.serialize_v(scale_o);

  if (b_IO_ro.isLoading_b())
  {
    computeMatrix_b = true;
    getWorldMatrix_ro();
  }

}

} // namespace me3d