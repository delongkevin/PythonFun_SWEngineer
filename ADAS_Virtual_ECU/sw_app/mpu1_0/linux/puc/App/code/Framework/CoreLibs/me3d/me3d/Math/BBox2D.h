//--------------------------------------------------------------------------                                                                                                           
/// @file BBox2D.h                                                                         
/// @brief Bounding Box 2D                                               
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BBOX2D_H
#define BBOX2D_H

#include "MeclTypeDefs.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 4222 EOF // Intended due to performance.

namespace me3d
{

  struct BBox2D_s
  {
    Vector2f min_o;
    Vector2f max_o;

    BBox2D_s();
    BBox2D_s(const Vector2f& i_Min_ro, const Vector2f& i_Max_ro);

    void     init_v();
    Vector2f getCenter_o() const;
    Vector2f getExtent_o() const;
    void     update_v(const Vector2f& i_P_ro);
    bool     intersect_b(const Vector2f& i_P_ro) const;
    bool     isEmpty_b() const;

    // returns the union Box of two bounding boxes
    static BBox2D_s union_s(const BBox2D_s& i_Box1_rs, const BBox2D_s& i_Box2_rs);

    // returns the overlapping Box of two bounding boxes
    static BBox2D_s overlap_s(const BBox2D_s& i_Box1_rs, const BBox2D_s& i_Box2_rs);

    inline void operator += (const Vector2f& i_P_ro)
    {
      update_v(i_P_ro);
    }

    inline BBox2D_s operator + (const Vector2f& i_P_ro)
    {
      BBox2D_s v_Merged_s;

      v_Merged_s.min_o.setPosX(mecl::math::min_x<float32_t>(this->min_o(0), i_P_ro(0)));
      v_Merged_s.min_o.setPosY(mecl::math::min_x<float32_t>(this->min_o(1), i_P_ro(1)));

      v_Merged_s.max_o.setPosX(mecl::math::max_x<float32_t>(this->max_o(0), i_P_ro(0)));
      v_Merged_s.max_o.setPosY(mecl::math::max_x<float32_t>(this->max_o(1), i_P_ro(1)));

      return v_Merged_s;
    }

    inline BBox2D_s operator + (const BBox2D_s& i_BBox_ro)
    {
      BBox2D_s v_Merged_s;

      v_Merged_s.min_o.setPosX(mecl::math::min_x<float32_t>(this->min_o(0), i_BBox_ro.min_o(0)));
      v_Merged_s.min_o.setPosY(mecl::math::min_x<float32_t>(this->min_o(1), i_BBox_ro.min_o(1)));

      v_Merged_s.max_o.setPosX(mecl::math::max_x<float32_t>(this->max_o(0), i_BBox_ro.max_o(0)));
      v_Merged_s.max_o.setPosY(mecl::math::max_x<float32_t>(this->max_o(1), i_BBox_ro.max_o(1)));

      return v_Merged_s;
    }
  };

} // namespace me3d

#endif
