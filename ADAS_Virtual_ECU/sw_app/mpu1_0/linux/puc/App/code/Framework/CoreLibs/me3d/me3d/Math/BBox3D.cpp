#include "Math/BBox3D.h"
#include "Math/BBox2D.h"
#include "Math/MathLib.h"
#include "Math/Transform.h"

#include <float.h>

namespace me3d
{

// PRQA S 4054 2 // No initializer list due to performance reasons, because init_v() already assigns members
BBox3D_s::BBox3D_s()
{
  init_v();
}

BBox3D_s::BBox3D_s(const Vector3f& i_Min_ro, const Vector3f& i_Max_ro)
  : min_o(i_Min_ro)
  , max_o(i_Max_ro)
{
}

BBox3D_s::BBox3D_s(const BBox2D_s& i_Box2D_rs)
  : min_o(Vector3f(i_Box2D_rs.min_o.getPosX(), 0.0F, i_Box2D_rs.min_o.getPosY()))
  , max_o(Vector3f(i_Box2D_rs.max_o.getPosX(), 0.0F, i_Box2D_rs.max_o.getPosY()))
{

}

void BBox3D_s::init_v()
{
  min_o = Vector3f( FLT_MAX,  FLT_MAX,  FLT_MAX);
  max_o = Vector3f(-FLT_MAX, -FLT_MAX, -FLT_MAX);
}

Vector3f BBox3D_s::getCenter_o() const
{
  return static_cast<Vector3f>((min_o + max_o) * 0.5F);
}

Vector3f BBox3D_s::getExtent_o() const
{
  return static_cast<Vector3f>((max_o - min_o) * 0.5F);
}

void BBox3D_s::update_v(const Vector3f& i_P_ro)
{
  // Update x component
  if (i_P_ro(0) < min_o(0))
  {
    min_o(0) = i_P_ro(0);
  }

  if (i_P_ro(0) > max_o(0))
  {
    max_o(0) = i_P_ro(0);
  }

  // Update y component
  if (i_P_ro(1) < min_o(1))
  {
    min_o(1) = i_P_ro(1);
  }

  if (i_P_ro(1) > max_o(1))
  {
    max_o(1) = i_P_ro(1);
  }

  // Update z component
  if (i_P_ro(2) < min_o(2))
  {
    min_o(2) = i_P_ro(2);
  }

  if (i_P_ro(2) > max_o(2))
  {
    max_o(2) = i_P_ro(2);
  }
}

bool BBox3D_s::intersect_b(const Vector3f& i_P_ro) const
{
  bool v_Intersect_b = true;

  if ((i_P_ro(0) < min_o(0)) || (i_P_ro(0) > max_o(0)) ||
      (i_P_ro(1) < min_o(1)) || (i_P_ro(1) > max_o(1)) ||
      (i_P_ro(2) < min_o(2)) || (i_P_ro(2) > max_o(2)))
  {
    v_Intersect_b = false;
  }
  else
  {
    v_Intersect_b = true;
  }

  return v_Intersect_b;
}

bool BBox3D_s::isEmpty_b() const
{
  return (min_o(0) >= max_o(0)) && 
         (min_o(1) >= max_o(1)) && 
         (min_o(2) >= max_o(2));
}

BBox3D_s BBox3D_s::union_s(const BBox3D_s& i_Box1_rs, const BBox3D_s& i_Box2_rs)
{
  Vector3f v_UnionMin_o = vectorMin_o(i_Box1_rs.min_o, i_Box2_rs.min_o);
  Vector3f v_UnionMax_o = vectorMax_o(i_Box1_rs.max_o, i_Box2_rs.max_o);

  return BBox3D_s(v_UnionMin_o, v_UnionMax_o);
}

me3d::BBox3D_s BBox3D_s::overlap_s(const BBox3D_s& i_Box1_rs, const BBox3D_s& i_Box2_rs)
{
  Vector3f v_UnionMin_o = vectorMax_o(i_Box1_rs.min_o, i_Box2_rs.min_o);
  Vector3f v_UnionMax_o = vectorMin_o(i_Box1_rs.max_o, i_Box2_rs.max_o);

  return BBox3D_s(v_UnionMin_o, v_UnionMax_o);
}

void BBox3D_s::transformMinMax_v(const Matrix4f& i_Transform_ro)
{
  min_o = transformVector_o(min_o, i_Transform_ro);
  max_o = transformVector_o(max_o, i_Transform_ro);
}

BBox3D_s BBox3D_s::transform_s(const Matrix4f& i_Transform_ro) const
{
  Vector3f v_TransformedMin_o;
  Vector3f v_TransformedMax_o;
  const Matrix4f& c_Mat_ro = i_Transform_ro;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < 3U; ++v_I_u32)
  {
    // set translation
    v_TransformedMin_o(v_I_u32) = c_Mat_ro(3, v_I_u32);
    v_TransformedMax_o(v_I_u32) = c_Mat_ro(3, v_I_u32);

    // add extents
    for (uint32_t v_J_u32 = 0U; v_J_u32 < 3U; ++v_J_u32)
    {
      float32_t v_E_f32 = c_Mat_ro(v_J_u32, v_I_u32) * min_o(v_J_u32);
      float32_t v_F_f32 = c_Mat_ro(v_J_u32, v_I_u32) * max_o(v_J_u32);

      if (v_E_f32 < v_F_f32)
      {
        v_TransformedMin_o(v_I_u32) += v_E_f32;
        v_TransformedMax_o(v_I_u32) += v_F_f32;
      }
      else
      {
        v_TransformedMin_o(v_I_u32) += v_F_f32;
        v_TransformedMax_o(v_I_u32) += v_E_f32;
      }
    }
  }

  return BBox3D_s(v_TransformedMin_o, v_TransformedMax_o);
}

} // namespace me3d
