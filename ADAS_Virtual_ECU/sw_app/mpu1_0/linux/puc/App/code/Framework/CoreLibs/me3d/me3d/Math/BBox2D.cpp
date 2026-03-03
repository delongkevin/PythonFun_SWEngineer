#include "Math/BBox2D.h"
#include "MathLib.h"
#include "Transform.h"

#include <float.h>

namespace me3d
{

  // PRQA S 4054 2 // No initializer list due to performance reasons, because init_v() already assigns members
  BBox2D_s::BBox2D_s()
  {
    init_v();
  }

  BBox2D_s::BBox2D_s(const Vector2f& i_Min_ro, const Vector2f& i_Max_ro)
    : min_o(i_Min_ro)
    , max_o(i_Max_ro)
  {
  }

  void BBox2D_s::init_v()
  {
    min_o = Vector2f( FLT_MAX,  FLT_MAX);
    max_o = Vector2f(-FLT_MAX, -FLT_MAX);
  }

  Vector2f BBox2D_s::getCenter_o() const
  {
    return static_cast<Vector2f>((min_o + max_o) * 0.5F);
  }

  Vector2f BBox2D_s::getExtent_o() const
  {
    return static_cast<Vector2f>((max_o - min_o) * 0.5F);
  }

  void BBox2D_s::update_v(const Vector2f& i_P_ro)
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
  }

  bool BBox2D_s::intersect_b(const Vector2f& i_P_ro) const
  {
    bool v_Intersect_b = true;

    if ((i_P_ro(0) < min_o(0)) || (i_P_ro(0) > max_o(0)) ||
        (i_P_ro(1) < min_o(1)) || (i_P_ro(1) > max_o(1)))
    {
      v_Intersect_b = false;
    }
    else
    {
      v_Intersect_b = true;
    }

    return v_Intersect_b;
  }

  bool BBox2D_s::isEmpty_b() const
  {
    return (min_o(0) >= max_o(0)) && 
           (min_o(1) >= max_o(1));
  }

  BBox2D_s BBox2D_s::union_s(const BBox2D_s& i_Box1_rs, const BBox2D_s& i_Box2_rs)
  {
    Vector2f v_UnionMin_o = vectorMin_o(i_Box1_rs.min_o, i_Box2_rs.min_o);
    Vector2f v_UnionMax_o = vectorMax_o(i_Box1_rs.max_o, i_Box2_rs.max_o);

    return BBox2D_s(v_UnionMin_o, v_UnionMax_o);
  }

  BBox2D_s BBox2D_s::overlap_s(const BBox2D_s& i_Box1_rs, const BBox2D_s& i_Box2_rs)
  {
    Vector2f v_UnionMin_o = vectorMax_o(i_Box1_rs.min_o, i_Box2_rs.min_o);
    Vector2f v_UnionMax_o = vectorMin_o(i_Box1_rs.max_o, i_Box2_rs.max_o);

    return BBox2D_s(v_UnionMin_o, v_UnionMax_o);
  }

} // namespace me3d
