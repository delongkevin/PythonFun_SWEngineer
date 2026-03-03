//--------------------------------------------------------------------------                                                                                                           
/// @file Transform.h                                                                         
/// @brief Combines Position, Rotation and Scale to create a World Matrix
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <MeclTypeDefs.h>
#include "Common/Camera/CameraTypes.h"

namespace me3d
{

class InOut;

class Transform
{
public:
  Transform();
  ~Transform();

  void reset_v();
  void setParent_v(Transform* b_Parent_po);
  Transform* getParent_po() const;

  Vector3f calcTranslation_o(const Vector3f& i_Translation_ro) const;
  Vector3f getGlobalTranslation_o() const;
  const Vector3f& getTranslation_ro() const;
  void setTranslation_v(const Vector3f& i_Translation_ro);
  void setTranslation_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32);

  Quaternionf getGlobalRotation_o() const;
  const Quaternionf& getRotation_ro() const;
  Vector3f getEulerAngles_o() const;
  Vector3f getEulerAnglesDegrees_o() const;
  Matrix4f getRotationMatrix_o() const;
  void setRotation_v(const Quaternionf& i_Rotation_ro);
  void setRotation_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32);

  Vector3f getGlobalScale_o() const;
  const Vector3f& getScale_ro() const;
  void setScale_v(const Vector3f& i_Scale_ro);
  void setScale_v(float32_t i_X_f32, float32_t i_Y_f32, float32_t i_Z_f32);

  void toViewDesc_v(ViewDesc_s& b_Desc_rs) const;

  const Matrix4f& getWorldMatrix_ro();



  void serialize_v(me3d::InOut& b_IO_ro);

private:
  Transform*  parent_po;
  Vector3f    translation_o;
  Quaternionf rotation_o;
  Vector3f    scale_o;
  Matrix4f    worldMatrix_o;
  bool        computeMatrix_b; 
};

} // namespace me3d


#endif
