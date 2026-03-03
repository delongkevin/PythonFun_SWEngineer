//--------------------------------------------------------------------------                                                                                                           
/// @file CameraTypes.h                                                                         
/// @brief Holds the structures needed by Camera class
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CAMERA_TYPES_H
#define CAMERA_TYPES_H

#include "MeclTypeDefs.h"

#include <Utilities/InOut.h>

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{
  struct ViewDesc_s
  {
    Vector3f from_o;
    Vector3f at_o;
    Vector3f up_o;
    Vector3f direction_o;

    ViewDesc_s()
      : from_o      (      100.0F,       100.0F, 0.0F)
      , at_o        (        0.0F,         0.0F, 0.0F)
      , up_o        (        0.0F,         1.0F, 0.0F)
      , direction_o (-0.70710677F, -0.70710677F, 0.0F)
    {
    }

    void serialize_v(me3d::InOut& b_InOut_ro)
    {
      b_InOut_ro.serialize_v(from_o);
      b_InOut_ro.serialize_v(at_o);
      b_InOut_ro.serialize_v(up_o);
      b_InOut_ro.serialize_v(direction_o);
    }
  };

  struct ProjectionDesc_s
  {
    float32_t foV_f32;
    float32_t nearClip_f32;
    float32_t farClip_f32;
    float32_t aspectRatio_f32;

    ProjectionDesc_s()
      : foV_f32(mecl::math::constants<float32_t>::pi_x() / 4.0F)
      , nearClip_f32(1.0F)
      , farClip_f32(1000.0F)
      , aspectRatio_f32(4.0F / 3.0F)
    {
    }

    void serialize_v(me3d::InOut& b_InOut_ro)
    {
      b_InOut_ro.serialize_v(foV_f32);
      b_InOut_ro.serialize_v(nearClip_f32);
      b_InOut_ro.serialize_v(farClip_f32);
      b_InOut_ro.serialize_v(aspectRatio_f32);
    }
  };

  struct CameraKeyFrame_s
  {
    ViewDesc_s       viewDesc_s;
    float32_t        fov_f32;

    CameraKeyFrame_s()
      : viewDesc_s()
      , fov_f32(mecl::math::constants<float32_t>::pi_x() / 4.0F)
    {
    }

    void serialize_v(me3d::InOut& b_InOut_ro)
    {
      viewDesc_s.serialize_v(b_InOut_ro);

      b_InOut_ro.serialize_v(fov_f32);
    }
  };

} // namespace me3d

#endif // CAMERA_PATH_H