//--------------------------------------------------------------------------                                                                                                           
/// @file BBox3D.h                                                                         
/// @brief Bounding Box                                                
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BBOX3D_H
#define BBOX3D_H

#include "MeclTypeDefs.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 4222 EOF // Intended due to performance.

namespace me3d
{
  class Transform;
}

namespace me3d
{

struct BBox2D_s;

struct BBox3D_s
{
  Vector3f min_o;
  Vector3f max_o;

  BBox3D_s();
  // PRQA S 2180 1 // implicit conversion is intended here to support.
  BBox3D_s(const BBox2D_s& i_Box2D_rs);
  BBox3D_s(const Vector3f& i_Min_ro, const Vector3f& i_Max_ro);

  void     init_v();
  Vector3f getCenter_o() const;
  Vector3f getExtent_o() const;
  void     update_v(const Vector3f& i_P_ro);
  bool     intersect_b(const Vector3f& i_P_ro) const;
  bool     isEmpty_b() const;

  // returns the union Box of two bounding boxes
  static BBox3D_s union_s(const BBox3D_s& i_Box1_rs, const BBox3D_s& i_Box2_rs);

  // returns the overlapping Box of two bounding boxes
  static BBox3D_s overlap_s(const BBox3D_s& i_Box1_rs, const BBox3D_s& i_Box2_rs);

  inline void operator += (const Vector3f& i_P_ro)
  {
    update_v(i_P_ro);
  }

  inline BBox3D_s operator + (const Vector3f& i_P_ro)
  {
    BBox3D_s v_Merged_s;

    v_Merged_s.min_o.setPosX(mecl::math::min_x<float32_t>(this->min_o(0), i_P_ro(0)));
    v_Merged_s.min_o.setPosY(mecl::math::min_x<float32_t>(this->min_o(1), i_P_ro(1)));
    v_Merged_s.min_o.setPosZ(mecl::math::min_x<float32_t>(this->min_o(2), i_P_ro(2)));

    v_Merged_s.max_o.setPosX(mecl::math::max_x<float32_t>(this->max_o(0), i_P_ro(0)));
    v_Merged_s.max_o.setPosY(mecl::math::max_x<float32_t>(this->max_o(1), i_P_ro(1)));
    v_Merged_s.max_o.setPosZ(mecl::math::max_x<float32_t>(this->max_o(2), i_P_ro(2)));

    return v_Merged_s;
  }

  inline BBox3D_s operator + (const BBox3D_s& i_BBox_ro)
  {
    BBox3D_s v_Merged_s;

    v_Merged_s.min_o.setPosX(mecl::math::min_x<float32_t>(this->min_o(0), i_BBox_ro.min_o(0)));
    v_Merged_s.min_o.setPosY(mecl::math::min_x<float32_t>(this->min_o(1), i_BBox_ro.min_o(1)));
    v_Merged_s.min_o.setPosZ(mecl::math::min_x<float32_t>(this->min_o(2), i_BBox_ro.min_o(2)));

    v_Merged_s.max_o.setPosX(mecl::math::max_x<float32_t>(this->max_o(0), i_BBox_ro.max_o(0)));
    v_Merged_s.max_o.setPosY(mecl::math::max_x<float32_t>(this->max_o(1), i_BBox_ro.max_o(1)));
    v_Merged_s.max_o.setPosZ(mecl::math::max_x<float32_t>(this->max_o(2), i_BBox_ro.max_o(2)));

    return v_Merged_s;
  }

  // this will break the axis-alignment if i_Transform_ro contains rotations
  void transformMinMax_v(const Matrix4f& i_Transform_ro);

  // transform keeping axis-alignment
  // This is not optimal (AABB-wise), we'll get lots of empty space, but performance-wise, it's better than recomputing the AABB of the whole mesh.
  BBox3D_s transform_s(const Matrix4f& i_Transform_ro) const;
};

} // namespace me3d

#endif
