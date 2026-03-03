//--------------------------------------------------------------------------                                                                                                           
/// @file MathLib.h                                                                         
/// @brief Provides useful Vector, Quaternion and Matrix functions
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef MATH_LIB_H
#define MATH_LIB_H

#include "MeclTypeDefs.h"

namespace me3d
{
  Matrix4f matrixInvert_o(const Matrix4f& i_Mat_ro);

  void matrixRotate_v(Matrix3f& b_Out_ro, float32_t i_AngleRadians_f32);
  void matrixTranslate_v(Matrix3f& b_out_ro, float32_t i_X_f32, float32_t i_Y_f32);
  void matrixScale_v(Matrix3f& b_Out_ro, float32_t i_X_f32, float32_t i_Y_f32);

  float32_t lerp_f32(float32_t i_F1_f32, float32_t i_F2_f32, float32_t i_S_f32);
  Vector3f lerp_o(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro, float32_t i_s_f32);

  Vector3f normalize_o(const Vector3f& i_v_ro);
  Vector2f normalize_o(const Vector2f& i_v_ro);
  float32_t getLength_f32(const Vector3f& i_v1_ro);
  float32_t getAngle_f32(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro);
  float32_t getAngle_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro);
  float32_t dotProduct_f32(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro);
  float32_t dotProduct_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro);
  Vector3f  crossProduct_o(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro);
  float32_t crossProduct_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro);
  float32_t distance_f32(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro);
  float32_t distance_f32(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro);
  Vector3f vectorMin_o(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro);
  Vector2f vectorMin_o(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro);
  Vector3f vectorMax_o(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro);
  Vector2f vectorMax_o(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro);

  void     transformScreenToWorldRay_v(const Vector2f& i_ScreenPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_ProjInv_ro, const Matrix4f& i_ViewInv_ro, Vector3f& o_RayStart_ro, Vector3f& o_RayDirection_ro, Vector3f* o_RayEndPos_po = NULL);
  Vector3f transformScreenToWorld_o(const Vector3f& i_ScreenPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_ProjInv_ro, const Matrix4f& i_ViewInv_ro);
  Vector3f transformWorldToScreen_o(const Vector3f& i_WorldPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_Proj_ro, const Matrix4f& i_View_ro);

  Vector3f transformDivW_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro);
  Vector3f transformDivAbsW_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro);
  Vector3f transformVector_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro);
  Vector2f transformVector_o(const Vector2f& i_v_ro, const Matrix3f& i_m_ro);
  Vector3f transformVector_o(const Vector3f& i_V_ro, const Quaternionf& i_Rotation_ro);
  Vector3f transformInverse_o(Vector3f i_v_o, const Vector3f& i_Translation_ro, const Quaternionf& i_Rotation_ro, float32_t i_Scale_f32);

  Vector3f rotateVectorInverse_o(const Vector3f& i_V_ro, const Quaternionf& i_Rotation_ro);

  Vector3f meclToGl_o(const Vector3f& i_MeclVector_ro);
  Matrix3f meclToGl_o(const Matrix3f& i_MeclMat_ro);
  Vector3f glToMecl_o(const Vector3f& i_GlVector_ro);
  Matrix3f glToMecl_o(const Matrix3f& i_GlMat_ro);

  Vector4f meclToGlProjection_o(const Vector3f& i_MeclVector_ro, const Vector3f& i_ProjScale_ro, uint32_t i_Xlength_u32, uint32_t i_YLength_u32, uint32_t i_Zlength_u32);
  Vector4f glToMeclProjection_o(const Vector3f& i_GlVector_ro, const Vector3f& i_ProjScale_ro, uint32_t i_Xlength_u32, uint32_t i_YLength_u32, uint32_t i_Zlength_u32);


  Quaternionf quaternionSlerp(const Quaternionf& i_q1_ro, const Quaternionf& i_q2_ro, float32_t i_t_f32);
  //caution: o_Axis_ro No unit vector 
  void        quaternionToAngleAxis_v(const Quaternionf& q, float32_t& o_Angle_rf32, Vector3f& o_Axis_ro);
  Quaternionf quaternionFromAxes_o(const Vector3f& axis1, const Vector3f& axis2);
  Quaternionf quaternionFromUnitAxes_o(const Vector3f& unitAxis1, const Vector3f& unitAxis2);
  float32_t   quaternionDot_f32(const Quaternionf& b, const Quaternionf& a);

  me3d::Vector3f calcPlaneNormal_o(const me3d::Vector3f& v1, const me3d::Vector3f& v2, const me3d::Vector3f& v3);

  // Bezier Point calculation. http://devmag.org.za/2011/04/05/bzier-curves-a-tutorial/
  void calculateBezierPoint4_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, const Vector3f& i_p3_ro, Vector3f& o_Path_ro);
  void calculateBezierPoint3_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, Vector3f& o_Path_ro);
  void calculateCatmullRom_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, const Vector3f& i_p3_ro, Vector3f& o_Path_ro);

  // cubic interpolation
  float32_t cubicInterpolation_f32(float32_t i_V0_f32, float32_t i_V1_f32, float32_t i_V2_f32, float32_t i_V3_f32, float32_t i_T_f32);

  // Intersections
  bool intersectRayAABB_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayDir_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, float32_t* o_Distance_po = NULL, Vector3f* o_Intersection_po = NULL);
  bool intersectRaySphere_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayEnd_ro, const Vector3f& i_SphereCenter_ro, float32_t i_SphereRadius_f32, Vector3f* o_Intersection_po);
  bool intersectRaySphere_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayDirNormalized_ro, const Vector3f& i_SphereCenter_ro, float32_t i_SphereRadius_f32, float32_t* o_Distance_po = NULL, Vector3f* o_Intersection_po = NULL);
  bool intersectRayPlane_b(const Vector3f& rayStart, const Vector3f& secondPointOnRay, const Vector3f& planePosition, const Vector3f& planeNormal, Vector3f* o_Intersection_po = NULL);

  bool intersectLineTriangle_b(const Vector3f& lineStart, const Vector3f& lineDirection, Vector3f& v0, Vector3f& v1, Vector3f& v2, float32_t& distance, float32_t& u, float32_t& v);


  // Distance functions
  float32_t distancePointLineSeg_f32(const Vector2f& point, const Vector2f& lineStart, const Vector2f& lineEnd, Vector2f& pointOnLine);

  void getFrustumPoints_v(const Matrix4f& i_Mat_ro, Vector3f* io_Frustum_po);

  template<typename T>
  static T getSign_x(const T& i_Val_rx)
  {
    return (mecl::math::constants<T>::zero_x() > i_Val_rx) ? mecl::math::constants<T>::minusOne_x() : mecl::math::constants<T>::one_x();
  }

  float32_t roundToZero_f32(float32_t i_Value_f32);

} // namespace me3d

#endif
