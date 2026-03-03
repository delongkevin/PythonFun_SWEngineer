#include "Math/MathLib.h"


// PRQA S 4020 EOF // Makes code more readable, less cyclomatic complexity
// PRQA S 3222 EOF // totally fine here.
// PRQA S 3270 EOF // fine.
// PRQA S 3082 EOF // function style casts are ok for PODs
// PRQA S 3223 EOF // fine.
// PRQA S 4107 EOF // makes math code more readable.
// PRQA S 3706 EOF // performance
// PRQA S 1052 EOF // This is ASCII art, no code
// PRQA S 3340 EOF // This is ASCII art, no code


namespace me3d
{

Matrix4f matrixInvert_o(const Matrix4f& i_Mat_ro)
{
  Matrix4f out;

  float32_t tmp0 = (i_Mat_ro(2, 2) * i_Mat_ro(0, 3)) - (i_Mat_ro(0, 2) * i_Mat_ro(2, 3));
  float32_t tmp1 = (i_Mat_ro(3, 2) * i_Mat_ro(1, 3)) - (i_Mat_ro(1, 2) * i_Mat_ro(3, 3));
  float32_t tmp2 = (i_Mat_ro(0, 1) * i_Mat_ro(2, 2)) - (i_Mat_ro(2, 1) * i_Mat_ro(0, 2));
  float32_t tmp3 = (i_Mat_ro(1, 1) * i_Mat_ro(3, 2)) - (i_Mat_ro(3, 1) * i_Mat_ro(1, 2));
  float32_t tmp4 = (i_Mat_ro(2, 1) * i_Mat_ro(0, 3)) - (i_Mat_ro(0, 1) * i_Mat_ro(2, 3));
  float32_t tmp5 = (i_Mat_ro(3, 1) * i_Mat_ro(1, 3)) - (i_Mat_ro(1, 1) * i_Mat_ro(3, 3));

  out(0, 0) = ((i_Mat_ro(2, 1) * tmp1) - (i_Mat_ro(2, 3) * tmp3)) - (i_Mat_ro(2, 2) * tmp5);
  out(0, 1) = ((i_Mat_ro(3, 1) * tmp0) - (i_Mat_ro(3, 3) * tmp2)) - (i_Mat_ro(3, 2) * tmp4);
  out(0, 2) = ((i_Mat_ro(0, 3) * tmp3) + (i_Mat_ro(0, 2) * tmp5)) - (i_Mat_ro(0, 1) * tmp1);
  out(0, 3) = ((i_Mat_ro(1, 3) * tmp2) + (i_Mat_ro(1, 2) * tmp4)) - (i_Mat_ro(1, 1) * tmp0);

  float32_t det = i_Mat_ro(0, 0) * out(0, 0) + i_Mat_ro(1, 0) * out(0, 1) + i_Mat_ro(2, 0) * out(0, 2) + i_Mat_ro(3, 0) * out(0, 3);

  if (det == 0)
  {
    return Matrix4f();
  }

  float32_t detInv = (1.0f / det);

  out(0, 0) *= detInv;
  out(0, 1) *= detInv;
  out(0, 2) *= detInv;
  out(0, 3) *= detInv;

  out(1, 0) = i_Mat_ro(2, 0) * tmp1;
  out(1, 1) = i_Mat_ro(3, 0) * tmp0;
  out(1, 2) = i_Mat_ro(0, 0) * tmp1;
  out(1, 3) = i_Mat_ro(1, 0) * tmp0;
  out(3, 0) = i_Mat_ro(2, 0) * tmp3;
  out(3, 1) = i_Mat_ro(3, 0) * tmp2;
  out(3, 2) = i_Mat_ro(0, 0) * tmp3;
  out(3, 3) = i_Mat_ro(1, 0) * tmp2;
  out(2, 0) = i_Mat_ro(2, 0) * tmp5;
  out(2, 1) = i_Mat_ro(3, 0) * tmp4;
  out(2, 2) = i_Mat_ro(0, 0) * tmp5;
  out(2, 3) = i_Mat_ro(1, 0) * tmp4;

  tmp0 = ((i_Mat_ro(2, 0) * i_Mat_ro(0, 1)) - (i_Mat_ro(0, 0) * i_Mat_ro(2, 1)));
  tmp1 = ((i_Mat_ro(3, 0) * i_Mat_ro(1, 1)) - (i_Mat_ro(1, 0) * i_Mat_ro(3, 1)));
  tmp2 = ((i_Mat_ro(2, 0) * i_Mat_ro(0, 3)) - (i_Mat_ro(0, 0) * i_Mat_ro(2, 3)));
  tmp3 = ((i_Mat_ro(3, 0) * i_Mat_ro(1, 3)) - (i_Mat_ro(1, 0) * i_Mat_ro(3, 3)));
  tmp4 = ((i_Mat_ro(2, 0) * i_Mat_ro(0, 2)) - (i_Mat_ro(0, 0) * i_Mat_ro(2, 2)));
  tmp5 = ((i_Mat_ro(3, 0) * i_Mat_ro(1, 2)) - (i_Mat_ro(1, 0) * i_Mat_ro(3, 2)));

  out(1, 0) = ((i_Mat_ro(2, 2) * tmp3) - (i_Mat_ro(2, 3) * tmp5)) - out(1, 0); out(1, 0) *= detInv;
  out(1, 1) = ((i_Mat_ro(3, 2) * tmp2) - (i_Mat_ro(3, 3) * tmp4)) - out(1, 1); out(1, 1) *= detInv;
  out(1, 2) = ((i_Mat_ro(0, 3) * tmp5) - (i_Mat_ro(0, 2) * tmp3)) + out(1, 2); out(1, 2) *= detInv;
  out(1, 3) = ((i_Mat_ro(1, 3) * tmp4) - (i_Mat_ro(1, 2) * tmp2)) + out(1, 3); out(1, 3) *= detInv;
  out(2, 0) = ((i_Mat_ro(2, 3) * tmp1) - (i_Mat_ro(2, 1) * tmp3)) + out(2, 0); out(2, 0) *= detInv;
  out(2, 1) = ((i_Mat_ro(3, 3) * tmp0) - (i_Mat_ro(3, 1) * tmp2)) + out(2, 1); out(2, 1) *= detInv;
  out(2, 2) = ((i_Mat_ro(0, 1) * tmp3) - (i_Mat_ro(0, 3) * tmp1)) - out(2, 2); out(2, 2) *= detInv;
  out(2, 3) = ((i_Mat_ro(1, 1) * tmp2) - (i_Mat_ro(1, 3) * tmp0)) - out(2, 3); out(2, 3) *= detInv;
  out(3, 0) = ((i_Mat_ro(2, 1) * tmp5) - (i_Mat_ro(2, 2) * tmp1)) + out(3, 0); out(3, 0) *= detInv;
  out(3, 1) = ((i_Mat_ro(3, 1) * tmp4) - (i_Mat_ro(3, 2) * tmp0)) + out(3, 1); out(3, 1) *= detInv;
  out(3, 2) = ((i_Mat_ro(0, 2) * tmp1) - (i_Mat_ro(0, 1) * tmp5)) - out(3, 2); out(3, 2) *= detInv;
  out(3, 3) = ((i_Mat_ro(1, 2) * tmp0) - (i_Mat_ro(1, 1) * tmp4)) - out(3, 3); out(3, 3) *= detInv;

  return out;
}

void matrixRotate_v(Matrix3f& b_Out_ro, float32_t i_AngleRadians_f32)
{
  float32_t v_a2_f32 =  mecl::math::trigonometry<float32_t>::cos_x(i_AngleRadians_f32);
  float32_t v_d2_f32 = -mecl::math::trigonometry<float32_t>::sin_x(i_AngleRadians_f32);
  float32_t v_b2_f32 =  mecl::math::trigonometry<float32_t>::sin_x(i_AngleRadians_f32);
  float32_t v_e2_f32 =  mecl::math::trigonometry<float32_t>::cos_x(i_AngleRadians_f32);

  float32_t v_A_f32 = b_Out_ro(0, 0) * v_a2_f32 + b_Out_ro(1, 0) * v_b2_f32;
  float32_t v_D_f32 = b_Out_ro(0, 0) * v_d2_f32 + b_Out_ro(1, 0) * v_e2_f32;
  float32_t v_B_f32 = b_Out_ro(0, 1) * v_a2_f32 + b_Out_ro(1, 1) * v_b2_f32;
  float32_t v_E_f32 = b_Out_ro(0, 1) * v_d2_f32 + b_Out_ro(1, 1) * v_e2_f32;

  b_Out_ro(0, 0) = v_A_f32;
  b_Out_ro(0, 1) = v_B_f32;
  b_Out_ro(1, 0) = v_D_f32;
  b_Out_ro(1, 1) = v_E_f32;
}

void matrixTranslate_v(Matrix3f& b_out_ro, float32_t i_X_f32, float32_t i_Y_f32)
{
  b_out_ro(2, 0) = b_out_ro(0, 0) * i_X_f32 + b_out_ro(1, 0) * i_Y_f32 + b_out_ro(2, 0);
  b_out_ro(2, 1) = b_out_ro(0, 1) * i_X_f32 + b_out_ro(1, 1) * i_Y_f32 + b_out_ro(2, 1);
}

void matrixScale_v(Matrix3f& b_Out_ro, float32_t i_X_f32, float32_t i_Y_f32)
{
  b_Out_ro(0, 0) = b_Out_ro(0, 0) * i_X_f32;
  b_Out_ro(0, 1) = b_Out_ro(0, 1) * i_X_f32;
  b_Out_ro(1, 0) = b_Out_ro(1, 0) * i_Y_f32;
  b_Out_ro(1, 1) = b_Out_ro(1, 1) * i_Y_f32;
}

float32_t lerp_f32(float32_t i_F1_f32, float32_t i_F2_f32, float32_t i_S_f32)
{
  return (1.0F - i_S_f32) * i_F1_f32 + i_S_f32 * i_F2_f32;
}

Vector3f lerp_o(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro, float32_t i_s_f32)
{
  return Vector3f((1.0F - i_s_f32) * i_v1_ro(0) + i_s_f32 * i_v2_ro(0),
                  (1.0F - i_s_f32) * i_v1_ro(1) + i_s_f32 * i_v2_ro(1),
                  (1.0F - i_s_f32) * i_v1_ro(2) + i_s_f32 * i_v2_ro(2));
}

Vector3f normalize_o(const Vector3f& i_v_ro)
{
  Vector3f v_Out_o = i_v_ro;

  float32_t v_Length_f32 = i_v_ro.norm();

  if (v_Length_f32 > mecl::math::constants<float32_t>::zero_x())
  {
    float32_t invLength = 1.0F / v_Length_f32;
    v_Out_o *= invLength;
  }

  return v_Out_o;
}

Vector2f normalize_o(const Vector2f& i_v_ro)
{
  Vector2f v_Out_o = i_v_ro;

  float32_t v_Length_f32 = i_v_ro.norm();

  if (v_Length_f32 > mecl::math::constants<float32_t>::zero_x())
  {
    float32_t invLength = 1.0F / v_Length_f32;
    v_Out_o *= invLength;
  }

  return v_Out_o;
}

float32_t getLength_f32(const Vector3f& i_v1_ro)
{
  return i_v1_ro.norm();
}

float32_t getAngle_f32(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro)
{
  return acosf(dotProduct_f32(i_v1_ro, i_v2_ro) / (getLength_f32(i_v1_ro) * getLength_f32(i_v2_ro)));
}

float32_t getAngle_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro)
{
  return atan2f(crossProduct_f32(i_v1_ro, i_v2_ro), dotProduct_f32(i_v1_ro, i_v2_ro));
}

float32_t dotProduct_f32(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro)
{
  return ((i_v1_ro(0) * i_v2_ro(0)) + 
          (i_v1_ro(1) * i_v2_ro(1)) + 
          (i_v1_ro(2) * i_v2_ro(2)));
}

float32_t dotProduct_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro)
{
  return ((i_v1_ro(0) * i_v2_ro(0)) + 
          (i_v1_ro(1) * i_v2_ro(1)));
}

Vector3f crossProduct_o(const Vector3f& i_v1_ro, const Vector3f& i_v2_ro)
{
  Vector3f v_vRes_o(i_v1_ro.getPosY()*i_v2_ro.getPosZ() - i_v1_ro.getPosZ()*i_v2_ro.getPosY(), 
                    i_v1_ro.getPosZ()*i_v2_ro.getPosX() - i_v1_ro.getPosX()*i_v2_ro.getPosZ(), 
                    i_v1_ro.getPosX()*i_v2_ro.getPosY() - i_v1_ro.getPosY()*i_v2_ro.getPosX());

  return v_vRes_o;
}

float32_t crossProduct_f32(const Vector2f& i_v1_ro, const Vector2f& i_v2_ro)
{
  return i_v1_ro.getPosX() * i_v2_ro.getPosY() - 
         i_v1_ro.getPosY() * i_v2_ro.getPosX();
}

float32_t distance_f32(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro)
{
  Vector3f v_Diff_o = static_cast<Vector3f>(i_V2_ro - i_V1_ro);
  return v_Diff_o.norm();
}

float32_t distance_f32(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro)
{
  Vector2f v_Diff_o = static_cast<Vector2f>(i_V2_ro - i_V1_ro);
  return v_Diff_o.norm();
}

Vector3f vectorMin_o(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro)
{
  return Vector3f(mecl::math::min_x<float32_t>(i_V1_ro(0), i_V2_ro(0)),
                  mecl::math::min_x<float32_t>(i_V1_ro(1), i_V2_ro(1)),
                  mecl::math::min_x<float32_t>(i_V1_ro(2), i_V2_ro(2)));
}

Vector2f vectorMin_o(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro)
{
  return Vector2f(mecl::math::min_x<float32_t>(i_V1_ro(0), i_V2_ro(0)),
                  mecl::math::min_x<float32_t>(i_V1_ro(1), i_V2_ro(1)));
}

Vector3f vectorMax_o(const Vector3f& i_V1_ro, const Vector3f& i_V2_ro)
{
  return Vector3f(mecl::math::max_x<float32_t>(i_V1_ro(0), i_V2_ro(0)),
                  mecl::math::max_x<float32_t>(i_V1_ro(1), i_V2_ro(1)),
                  mecl::math::max_x<float32_t>(i_V1_ro(2), i_V2_ro(2)));
}

Vector2f vectorMax_o(const Vector2f& i_V1_ro, const Vector2f& i_V2_ro)
{
  return Vector2f(mecl::math::max_x<float32_t>(i_V1_ro(0), i_V2_ro(0)),
                  mecl::math::max_x<float32_t>(i_V1_ro(1), i_V2_ro(1)));
}

void transformScreenToWorldRay_v(const Vector2f& i_ScreenPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_ProjInv_ro, const Matrix4f& i_ViewInv_ro, Vector3f& o_RayStart_ro, Vector3f& o_RayDirection_ro, Vector3f* o_RayEndPos_po /*= NULL*/)
{
  // Transform near clip plane point (z = 0)
  Vector3f v_RayStart_o = transformScreenToWorld_o(Vector3f(i_ScreenPos_ro(0), i_ScreenPos_ro(1), 0.0F), i_ScreenSizeX_u32, i_ScreenSizeY_u32, i_ProjInv_ro, i_ViewInv_ro);

  // Transform far clip plane point  (z = 1)
  Vector3f v_RayEnd_o = transformScreenToWorld_o(Vector3f(i_ScreenPos_ro(0), i_ScreenPos_ro(1), 1.0F), i_ScreenSizeX_u32, i_ScreenSizeY_u32, i_ProjInv_ro, i_ViewInv_ro);

  o_RayStart_ro = v_RayStart_o;

  o_RayDirection_ro = normalize_o(static_cast<Vector3f>(v_RayEnd_o - v_RayStart_o));

  if (NULL != o_RayEndPos_po)
  {
    *o_RayEndPos_po = v_RayEnd_o;
  }

}

Vector3f transformScreenToWorld_o(const Vector3f& i_ScreenPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_ProjInv_ro, const Matrix4f& i_ViewInv_ro)
{
  Vector3f v_PosProjSpace_o;

  v_PosProjSpace_o(0) = (i_ScreenPos_ro(0) / static_cast<float32_t>(i_ScreenSizeX_u32)) * 2.0F - 1.0F;
  v_PosProjSpace_o(1) = (i_ScreenPos_ro(1) / static_cast<float32_t>(i_ScreenSizeY_u32)) * 2.0F - 1.0F;
  v_PosProjSpace_o(2) =  i_ScreenPos_ro(2);

  v_PosProjSpace_o(1) = -v_PosProjSpace_o(1);   // Flip y


  Vector3f v_PosViewSpace_o = transformDivW_o(v_PosProjSpace_o, i_ProjInv_ro);

  Vector3f v_PosWorldSpace_o = transformVector_o(v_PosViewSpace_o, i_ViewInv_ro);

  return v_PosWorldSpace_o;
}

Vector3f transformWorldToScreen_o(const Vector3f& i_WorldPos_ro, uint32_t i_ScreenSizeX_u32, uint32_t i_ScreenSizeY_u32, const Matrix4f& i_Proj_ro, const Matrix4f& i_View_ro)
{
  Vector3f v_PosViewSpace_o = transformVector_o(i_WorldPos_ro, i_View_ro);
  
  Vector3f v_PosProjSpace_o = transformDivW_o(v_PosViewSpace_o, i_Proj_ro);

  v_PosProjSpace_o(1) = -v_PosProjSpace_o(1); // flip y

  Vector3f v_PosScreenSpace_o;

  v_PosScreenSpace_o(0) = (v_PosProjSpace_o(0) * 0.5F + 0.5F) * static_cast<float32_t>(i_ScreenSizeX_u32);
  v_PosScreenSpace_o(1) = (v_PosProjSpace_o(1) * 0.5F + 0.5F) * static_cast<float32_t>(i_ScreenSizeY_u32);
  v_PosScreenSpace_o(2) = v_PosProjSpace_o(2);

  return v_PosScreenSpace_o;
}

Vector3f transformDivW_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro)
{
  float32_t v_x_f32 = ((i_v_ro(0) * i_m_ro(0, 0)) + (i_v_ro(1) * i_m_ro(1, 0)) + (i_v_ro(2) * i_m_ro(2, 0))) + i_m_ro(3, 0);
  float32_t v_y_f32 = ((i_v_ro(0) * i_m_ro(0, 1)) + (i_v_ro(1) * i_m_ro(1, 1)) + (i_v_ro(2) * i_m_ro(2, 1))) + i_m_ro(3, 1);
  float32_t v_z_f32 = ((i_v_ro(0) * i_m_ro(0, 2)) + (i_v_ro(1) * i_m_ro(1, 2)) + (i_v_ro(2) * i_m_ro(2, 2))) + i_m_ro(3, 2);
  float32_t v_w_f32 = ((i_v_ro(0) * i_m_ro(0, 3)) + (i_v_ro(1) * i_m_ro(1, 3)) + (i_v_ro(2) * i_m_ro(2, 3))) + i_m_ro(3, 3);

  return Vector3f(v_x_f32 / v_w_f32, v_y_f32 / v_w_f32, v_z_f32 / v_w_f32);
}

Vector3f transformDivAbsW_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro)
{
  float32_t v_x_f32 = ((i_v_ro(0) * i_m_ro(0, 0)) + (i_v_ro(1) * i_m_ro(1, 0)) + (i_v_ro(2) * i_m_ro(2, 0))) + i_m_ro(3, 0);
  float32_t v_y_f32 = ((i_v_ro(0) * i_m_ro(0, 1)) + (i_v_ro(1) * i_m_ro(1, 1)) + (i_v_ro(2) * i_m_ro(2, 1))) + i_m_ro(3, 1);
  float32_t v_z_f32 = ((i_v_ro(0) * i_m_ro(0, 2)) + (i_v_ro(1) * i_m_ro(1, 2)) + (i_v_ro(2) * i_m_ro(2, 2))) + i_m_ro(3, 2);
  float32_t v_w_f32 = ((i_v_ro(0) * i_m_ro(0, 3)) + (i_v_ro(1) * i_m_ro(1, 3)) + (i_v_ro(2) * i_m_ro(2, 3))) + i_m_ro(3, 3);

  v_w_f32 = mecl::math::abs_x<float32_t>(v_w_f32);

  return Vector3f(v_x_f32 / v_w_f32, v_y_f32 / v_w_f32, v_z_f32 / v_w_f32);
}

Vector3f transformVector_o(const Vector3f& i_v_ro, const Matrix4f& i_m_ro)
{
  return Vector3f(((i_v_ro(0) * i_m_ro(0,0)) + (i_v_ro(1) * i_m_ro(1,0)) + (i_v_ro(2) * i_m_ro(2,0))) + i_m_ro(3,0),
                  ((i_v_ro(0) * i_m_ro(0,1)) + (i_v_ro(1) * i_m_ro(1,1)) + (i_v_ro(2) * i_m_ro(2,1))) + i_m_ro(3,1),
                  ((i_v_ro(0) * i_m_ro(0,2)) + (i_v_ro(1) * i_m_ro(1,2)) + (i_v_ro(2) * i_m_ro(2,2))) + i_m_ro(3,2));
}

Vector2f transformVector_o(const Vector2f& i_v_ro, const Matrix3f& i_M_ro)
{
  return Vector2f(i_v_ro(0) * i_M_ro(0, 0) + i_v_ro(1) * i_M_ro(1, 0) + i_M_ro(2, 0),
                  i_v_ro(0) * i_M_ro(0, 1) + i_v_ro(1) * i_M_ro(1, 1) + i_M_ro(2, 1));
}

Vector3f transformVector_o(const Vector3f& i_V_ro, const Quaternionf& i_Rotation_ro)
{
  return Quaternionf::transform(i_V_ro, i_Rotation_ro);
}

Vector3f transformInverse_o(Vector3f i_v_o, const Vector3f& i_Translation_ro, const Quaternionf& i_Rotation_ro, float32_t i_Scale_f32)
{
  i_v_o -= i_Translation_ro;

  Vector3f v_Rotated_o = Quaternionf::transform(i_v_o, Quaternionf::inverse(i_Rotation_ro), i_Rotation_ro);

  v_Rotated_o /= i_Scale_f32;

  return v_Rotated_o;
}

Vector3f rotateVectorInverse_o(const Vector3f& i_V_ro, const Quaternionf& i_Rotation_ro)
{
  return Quaternionf::transform(i_V_ro, Quaternionf::inverse(i_Rotation_ro), i_Rotation_ro);
}

Vector3f meclToGl_o(const Vector3f& i_MeclVector_ro)
{
  // Mecl Coords
  //  Z   -X
  //  |  /
  //  | /
  //  |/
  //  +--------Y

  return Vector3f(i_MeclVector_ro.getPosY(),   // X =  Y   // pitch = yaw
                  i_MeclVector_ro.getPosZ(),   // Y =  Z   // yaw   = roll
                  i_MeclVector_ro.getPosX());  // Z =  X   // roll  = pitch
}

Matrix3f meclToGl_o(const Matrix3f& i_MeclMat_ro)
{
  Matrix3f v_GL_o;

  v_GL_o(0, 0) =  i_MeclMat_ro(0, 1);
  v_GL_o(1, 0) =  i_MeclMat_ro(1, 1);
  v_GL_o(2, 0) = -i_MeclMat_ro(2, 1);

  v_GL_o(0, 1) =  i_MeclMat_ro(0, 2);
  v_GL_o(1, 1) =  i_MeclMat_ro(1, 2);
  v_GL_o(2, 1) = -i_MeclMat_ro(2, 2);

  v_GL_o(0, 2) =  i_MeclMat_ro(0, 0);
  v_GL_o(1, 2) =  i_MeclMat_ro(1, 0);
  v_GL_o(2, 2) = -i_MeclMat_ro(2, 0);

  return v_GL_o;
}

Vector3f glToMecl_o(const Vector3f& i_GlVector_ro)
{
  // GL Coords
  //  Y   Z
  //  |  /
  //  | /
  //  |/
  //  +--------X

  return Vector3f(i_GlVector_ro.getPosZ(),    // X =  Z
                  i_GlVector_ro.getPosX(),    // Y =  X
                  i_GlVector_ro.getPosY());   // Z =  Y
}

Matrix3f glToMecl_o(const Matrix3f& i_GlMat_ro)
{
  Matrix3f v_Mecl_o;

  // pitch
  v_Mecl_o(0, 0) =  i_GlMat_ro(0, 2);
  v_Mecl_o(1, 0) =  i_GlMat_ro(1, 2);
  v_Mecl_o(2, 0) = -i_GlMat_ro(2, 2);

  v_Mecl_o(0, 1) =  i_GlMat_ro(0, 0);
  v_Mecl_o(1, 1) =  i_GlMat_ro(1, 0);
  v_Mecl_o(2, 1) = -i_GlMat_ro(2, 0);

  v_Mecl_o(0, 2) =  i_GlMat_ro(0, 1);
  v_Mecl_o(1, 2) =  i_GlMat_ro(1, 1);
  v_Mecl_o(2, 2) = -i_GlMat_ro(2, 1);

  return v_Mecl_o;
}

Vector4f meclToGlProjection_o(const Vector3f& i_MeclVector_ro, const Vector3f& i_ProjScale_ro, uint32_t i_Xlength_u32, uint32_t i_YLength_u32, uint32_t i_Zlength_u32)
{
  float32_t v_ScaleX_f32 = float32_t(i_Xlength_u32) / i_ProjScale_ro.getPosX();
  float32_t v_ScaleY_f32 = float32_t(i_YLength_u32) / i_ProjScale_ro.getPosY();
  float32_t v_ScaleZ_f32 = float32_t(i_Zlength_u32) / i_ProjScale_ro.getPosZ();

  return Vector4f(i_MeclVector_ro.getPosY() * v_ScaleZ_f32,           // X = Y
                  i_MeclVector_ro.getPosZ() * v_ScaleX_f32,           // Y = Z
                  i_MeclVector_ro.getPosX() * v_ScaleY_f32,           // Z = X
                  1.0);
}

Vector4f glToMeclProjection_o(const Vector3f& i_GlVector_ro, const Vector3f& i_ProjScale_ro, uint32_t i_Xlength_u32, uint32_t i_YLength_u32, uint32_t i_Zlength_u32)
{
  float32_t v_ScaleX_f32 = float32_t(i_Xlength_u32) / i_ProjScale_ro.getPosX();
  float32_t v_ScaleY_f32 = float32_t(i_YLength_u32) / i_ProjScale_ro.getPosY();
  float32_t v_ScaleZ_f32 = float32_t(i_Zlength_u32) / i_ProjScale_ro.getPosZ();

  return Vector4f(i_GlVector_ro.getPosZ() / v_ScaleX_f32, // X = Z
                  i_GlVector_ro.getPosX() / v_ScaleY_f32, // Y = X
                  i_GlVector_ro.getPosY() / v_ScaleZ_f32, // Z = Y
                  1.0);
}

Quaternionf quaternionSlerp(const Quaternionf& i_q1_ro, const Quaternionf& i_q2_ro, float32_t i_t_f32)
{
  Vector4f v_V1_o = i_q1_ro;
  Vector4f v_V2_o = i_q2_ro;

  float32_t v_Cosine_f32 = v_V2_o.dot(v_V1_o);

  Quaternionf actualQ2 = i_q2_ro;

  if (v_Cosine_f32 < 0.0F)
  {
    v_Cosine_f32  = -v_Cosine_f32;
    actualQ2      = -i_q2_ro;
  }

  if ((1.0F - v_Cosine_f32) <= mecl::math::numeric_limits<float32_t>::epsilon_x())
  {
    return (i_q1_ro * (1.0F - i_t_f32) + actualQ2 * i_t_f32);
  }

  float32_t v_Theta_f32 = acosf(v_Cosine_f32);

  return (i_q1_ro * sinf((1.0F - i_t_f32) * v_Theta_f32) + actualQ2 * sinf(i_t_f32 * v_Theta_f32)) / sinf(v_Theta_f32);
}

void quaternionToAngleAxis_v(const Quaternionf& q, float32_t& o_Angle_rf32, Vector3f& o_Axis_ro)
{
  Quaternionf qNorm = q;
  qNorm.normalize();

  o_Angle_rf32  = mecl::math::trigonometry<float32_t>::acos_x(qNorm.getW()) * 2.0F;
  o_Axis_ro     = Vector3f(qNorm.getX(), qNorm.getY(), qNorm.getZ());
}

me3d::Quaternionf quaternionFromAxes_o(const Vector3f& axis1, const Vector3f& axis2)
{
  Vector3f p1 = normalize_o(axis1);
  Vector3f p2 = normalize_o(axis2);

  return quaternionFromUnitAxes_o(p1, p2);
}

me3d::Quaternionf quaternionFromUnitAxes_o(const Vector3f& unitAxis1, const Vector3f& unitAxis2)
{
  Vector3f finalAxis;

  // get dot product of two vectors
  float32_t dot = dotProduct_f32(unitAxis1, unitAxis2);

  if (dot > 0.9999999f) // check if parallel
  {
    return Quaternionf(0.0F, 0.0F, 0.0F, 1.0F);
  }
  else if (dot < -0.9999999f) // check if opposite
  {
    // check if we can use cross product of from vector with [1, 0, 0]
    finalAxis = Vector3f(0.0F, unitAxis1(0), -unitAxis1(1));

    float32_t len = sqrtf(finalAxis(1) * finalAxis(1) + finalAxis(2) * finalAxis(2));

    if (len < 1e-6f)
    {
      // nope! we need cross product of from vector with [0, 1, 0]
      finalAxis = Vector3f(-unitAxis1(2), 0.0F, unitAxis1(0));
    }

    finalAxis = normalize_o(finalAxis);

    return Quaternionf(finalAxis(0), finalAxis(1), finalAxis(2), 0.0F);
  }
  else
  {
    // misra else
  }


  Vector3f half = normalize_o(static_cast<Vector3f>(unitAxis1 + unitAxis2));

  finalAxis = unitAxis1.cross(half);

  return Quaternionf(finalAxis(0), finalAxis(1), finalAxis(2), dotProduct_f32(unitAxis1, half));
}

float32_t quaternionDot_f32(const Quaternionf& b, const Quaternionf& a)
{
  return b.getX() * a.getX() + b.getY() * a.getY() + b.getZ() * a.getZ() + b.getW() * a.getW();
}

me3d::Vector3f calcPlaneNormal_o(const Vector3f& v1, const Vector3f& v2, const Vector3f& v3)
{
  me3d::Vector3f normal;

  normal(0) = ((v1(1) - v2(1)) * (v1(2) - v3(2))) - ((v1(2) - v2(2)) * (v1(1) - v3(1)));
  normal(1) = ((v1(2) - v2(2)) * (v1(0) - v3(0))) - ((v1(0) - v2(0)) * (v1(2) - v3(2)));
  normal(2) = ((v1(0) - v2(0)) * (v1(1) - v3(1))) - ((v1(1) - v2(1)) * (v1(0) - v3(0)));

  return normal;
}

void calculateBezierPoint4_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, const Vector3f& i_p3_ro, Vector3f& o_Path_ro)
{
  float32_t u = (1.0F - v_t_f32);
  float32_t tt = v_t_f32 * v_t_f32;
  float32_t uu = u * u;
  float32_t uuu = uu * u;
  float32_t ttt = tt * v_t_f32;

  o_Path_ro =  (i_p0_ro * uuu);
  o_Path_ro += (i_p1_ro * v_t_f32  * 3.0F * uu);
  o_Path_ro += (i_p2_ro * tt * 3.0F * u);
  o_Path_ro += (i_p3_ro * ttt);
}

void calculateBezierPoint3_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, Vector3f& o_Path_ro)
{
  float32_t v_u_f32 = (1.0F - v_t_f32);
  float32_t v_uu_f32 = v_u_f32 * v_u_f32;
  float32_t v_tt_f32 = v_t_f32 * v_t_f32;

  o_Path_ro =  (i_p0_ro * v_uu_f32);
  o_Path_ro += (i_p1_ro * v_t_f32 * 2.0F * v_u_f32);
  o_Path_ro += (i_p2_ro * v_tt_f32);
}

void calculateCatmullRom_v(float32_t v_t_f32, const Vector3f& i_p0_ro, const Vector3f& i_p1_ro, const Vector3f& i_p2_ro, const Vector3f& i_p3_ro, Vector3f& o_Path_ro)
{
  float32_t tt = v_t_f32 * v_t_f32;
  float32_t ttt = tt * v_t_f32;

  o_Path_ro = (i_p0_ro * (-1.0F) + i_p1_ro * 3.0F - i_p2_ro * 3.0F + i_p3_ro) * ttt / 2.0F;
  o_Path_ro += (i_p0_ro * 2.0F - i_p1_ro * 5.0F + i_p2_ro * 4.0F - i_p3_ro) * tt / 2.0F;
  o_Path_ro += (i_p0_ro * (-1.0F) + i_p2_ro) * v_t_f32 / 2.0F;
  o_Path_ro += i_p1_ro;
}

float32_t cubicInterpolation_f32(float32_t i_V0_f32, float32_t i_V1_f32, float32_t i_V2_f32, float32_t i_V3_f32, float32_t i_T_f32)
{
  float32_t v_P_f32 = (i_V3_f32 - i_V2_f32) - (i_V0_f32 - i_V1_f32);
  float32_t v_Q_f32 = (i_V0_f32 - i_V1_f32) -  v_P_f32;
  float32_t v_R_f32 =  i_V2_f32 - i_V0_f32;
  float32_t v_S_f32 =  i_V1_f32;

  float32_t v_T2_f32 = i_T_f32  * i_T_f32;
  float32_t v_T3_f32 = v_T2_f32 * i_T_f32;

  return v_P_f32 * v_T3_f32 + v_Q_f32 * v_T2_f32 + v_R_f32 * i_T_f32 + v_S_f32;
}

bool intersectRayAABB_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayDir_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, float32_t* o_Distance_po /*= NULL*/, Vector3f* o_Intersection_po /*= NULL*/)
{
  Vector3f v_InvDir_o = static_cast<Vector3f>(Vector3f::ones() / i_RayDir_ro);

  Vector3f v_t1_o = static_cast<Vector3f>((i_Min_ro - i_RayStart_ro) * v_InvDir_o);
  Vector3f v_t2_o = static_cast<Vector3f>((i_Max_ro - i_RayStart_ro) * v_InvDir_o);

  float32_t v_tmin_f32 = mecl::math::max_x(mecl::math::max_x(mecl::math::min_x(v_t1_o(0), v_t2_o(0)), mecl::math::min_x(v_t1_o(1), v_t2_o(1))), mecl::math::min_x(v_t1_o(2), v_t2_o(2)));
  float32_t v_tmax_f32 = mecl::math::min_x(mecl::math::min_x(mecl::math::max_x(v_t1_o(0), v_t2_o(0)), mecl::math::max_x(v_t1_o(1), v_t2_o(1))), mecl::math::max_x(v_t1_o(2), v_t2_o(2)));

  // case if line intersects the bounding box behind i_RayStart_ro
  if (v_tmax_f32 < 0.0F)
  {
    return false;
  }

  if (v_tmin_f32 > v_tmax_f32)
  {
    return false;
  }


  // Ray may start inside the AABB, so return 0.0f (ray start) in this case
  float32_t v_t_f32 = mecl::math::max_x(v_tmin_f32, 0.0F);

  if (o_Distance_po)
  {
    *o_Distance_po = v_t_f32;
  }

  if (o_Intersection_po)
  {
    *o_Intersection_po = static_cast<Vector3f>(i_RayStart_ro + static_cast<Vector3f>(i_RayDir_ro * v_t_f32));
  }

  return true;
}


bool intersectRaySphere_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayEnd_ro, const Vector3f& i_SphereCenter_ro, float32_t i_SphereRadius_f32, Vector3f* o_Intersection_po)
{
  float32_t v_Distance_f32;
  Vector3f v_RayDir_o = normalize_o(static_cast<Vector3f>(i_RayEnd_ro - i_RayStart_ro));

  return intersectRaySphere_b(i_RayStart_ro, v_RayDir_o, i_SphereCenter_ro, i_SphereRadius_f32, &v_Distance_f32, o_Intersection_po);
}

bool intersectRaySphere_b(const Vector3f& i_RayStart_ro, const Vector3f& i_RayDirNormalized_ro, const Vector3f& i_SphereCenter_ro, float32_t i_SphereRadius_f32, float32_t* o_Distance_po /*= NULL*/, Vector3f* o_Intersection_po /*= NULL*/)
{
  Vector3f L;
  float32_t L2, D, R2, M2, Q;

  L  = i_SphereCenter_ro - i_RayStart_ro;
  D  = i_RayDirNormalized_ro.dot(L);
  L2 = L.dot(L);
  R2 = i_SphereRadius_f32 * i_SphereRadius_f32;

  if ((D < 0) && (L2 > R2))
  {
    return false;
  }

  M2 = L2 - (D * D);

  if (M2 > R2)
  {
    return false;
  }

  Q = sqrtf(R2 - M2);

  if (NULL != o_Distance_po)
  {
    if (L2 > R2)
    {
      *o_Distance_po = D - Q;
    }
    else
    {
      *o_Distance_po = D + Q;
    }

    if (o_Intersection_po)
    {
      *o_Intersection_po = i_RayStart_ro + (i_RayDirNormalized_ro * (*o_Distance_po));
    }
  }

  return true;

}


bool intersectRayPlane_b(const Vector3f& rayStart, const Vector3f& secondPointOnRay, const Vector3f& planePosition, const Vector3f& planeNormal, Vector3f* o_Intersection_po /*= NULL*/)
{
  Vector3f rayDir       = static_cast<Vector3f>(secondPointOnRay - rayStart);
  Vector3f lineToPlane  = static_cast<Vector3f>(planePosition - rayStart);

  float32_t projectedLineToPlane = dotProduct_f32(lineToPlane, static_cast<Vector3f>(-planeNormal));
  float32_t projectedRayDir      = dotProduct_f32(rayDir, static_cast<Vector3f>(-planeNormal));

  if (projectedRayDir <= 0.0f)
  {
    // == 0 : Ray runs parallel to the plane => no intersection
    // <  0 : Ray goes in same direction as plane-normal (hits from behind or does not hit at all)
    return false;
  }

  if (projectedLineToPlane < 0.0f)
  {
    // ray start lies behind plane (not in normal-direction)
    return false;
  }

  float32_t percentage = projectedLineToPlane / projectedRayDir;

  *o_Intersection_po = rayStart + (rayDir * percentage);

  return true;
}

bool intersectLineTriangle_b(const Vector3f& lineStart, const Vector3f& lineDirection, Vector3f& v0, Vector3f& v1, Vector3f& v2, float32_t& distance, float32_t& u, float32_t& v)
{
  // Find vectors for two edges sharing vert0
  Vector3f edge1 = static_cast<Vector3f>(v1 - v0);
  Vector3f edge2 = static_cast<Vector3f>(v2 - v0);

  // Begin calculating determinant - also used to calculate u parameter
  Vector3f pvec = lineDirection.cross(edge2);

  // If determinant is near zero, ray lies in plane of triangle
  float32_t det = dotProduct_f32(edge1, pvec);

  Vector3f tvec;

  if (det > 0)
  {
    tvec = lineStart - v0;
  }
  else
  {
    tvec = v0 - lineStart;
    det = -det;
  }

  if (det < 0.0001f)
  {
    return false;
  }

  // Calculate u parameter and test bounds
  u = dotProduct_f32(tvec, pvec);

  if ((u < 0.0F) || (u > det))
  {
    return false;
  }

  // Prepare to test v parameter
  Vector3f qvec = tvec.cross(edge1);

  // Calculate v parameter and test bounds
  v = dotProduct_f32(lineDirection, qvec);

  if ((v < 0.0F) || ((u + v) > det))
  {
    return false;
  }

  // Calculate distance (scale parameter), which extents the line to the intersection point
  distance = dotProduct_f32(edge2, qvec);

  float32_t invDet = 1.0f / det;

  distance *= invDet;
  u        *= invDet;
  v        *= invDet;

  return true;
}

float32_t distancePointLineSeg_f32(const Vector2f& point, const Vector2f& lineStart, const Vector2f& lineEnd, Vector2f& pointOnLine)
{
  Vector2f lineDirection = static_cast<Vector2f>(lineEnd - lineStart);

  float32_t   l = lineDirection.norm();
  Vector2f    d = static_cast<Vector2f>(point - lineStart);
  float32_t   u = dotProduct_f32(d, lineDirection) / (l * l);

  if ((u >= 0.0F) && (u <= 1.0F))
  {
    pointOnLine = lineStart + lineDirection * u;
  }
  else if (u < 0.0F)
  {
    pointOnLine = lineStart;
  }
  else
  {
    pointOnLine = lineEnd;
  }

  return (point - pointOnLine).norm();
}

void getFrustumPoints_v(const Matrix4f& i_Mat_ro, Vector3f* io_Frustum_po/*[8]*/)
{
  //         4  _________  5
  //           /       .´|
  //          /     .´   |
  //      0  /___.´1     |
  //        |    |       |
  //        |____|. -  '   6
  //      3      2
  //
  io_Frustum_po[0] = Vector3f(-1.0f, 1.0f, 0.0f);
  io_Frustum_po[1] = Vector3f( 1.0f, 1.0f, 0.0f);
  io_Frustum_po[2] = Vector3f( 1.0f,-1.0f, 0.0f);
  io_Frustum_po[3] = Vector3f(-1.0f,-1.0f, 0.0f);

  io_Frustum_po[4] = Vector3f(-1.0f, 1.0f, 1.0f); 
  io_Frustum_po[5] = Vector3f( 1.0f, 1.0f, 1.0f); 
  io_Frustum_po[6] = Vector3f( 1.0f,-1.0f, 1.0f); 
  io_Frustum_po[7] = Vector3f(-1.0f,-1.0f, 1.0f);

  Matrix4f mtxInv = matrixInvert_o(i_Mat_ro);

  for (uint32_t i = 0; i < 8; ++i)
  {
    io_Frustum_po[i] = transformDivAbsW_o(io_Frustum_po[i], mtxInv);
  }
}


float32_t roundToZero_f32(float32_t i_Value_f32)
{
  const float32_t c_Epsilon_f32 = 5.0e-4F;

  float32_t v_RetVal_f32 = i_Value_f32;

  if (i_Value_f32 < c_Epsilon_f32 && i_Value_f32 > -c_Epsilon_f32)
  {
    v_RetVal_f32 = 0.0F;
  }

  return v_RetVal_f32;
}

} // namespace me3d