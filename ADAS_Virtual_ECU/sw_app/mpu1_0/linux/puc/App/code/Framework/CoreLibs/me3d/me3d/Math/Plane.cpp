#include "Math/Plane.h"

namespace me3d
{
  Plane_s::Plane_s()
    : normal_o()
    , distance_f32(0.0F)
  {
  }

  Plane_s::Plane_s(float32_t i_A_f32, float32_t i_B_f32, float32_t i_C_f32, float32_t i_D_f32)
    : distance_f32(i_D_f32)
  {
    normal_o.setPosX(i_A_f32);
    normal_o.setPosY(i_B_f32);
    normal_o.setPosZ(i_C_f32);
  }

  Plane_s::Plane_s(const Vector3f& i_Normal_ro, float32_t i_Distance_f32)
    : normal_o(i_Normal_ro)
    , distance_f32(i_Distance_f32)
  {
  }

} // namespace me3d