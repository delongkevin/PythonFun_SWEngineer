//--------------------------------------------------------------------------                                                                                                           
/// @file BaseView.h                                                                         
/// @brief Base class for View Classes (Single or Surround View)
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BASE_VIEW_H
#define BASE_VIEW_H

#include "Common/View/ViewTypes.h"
#include "Math/Transform.h"

namespace me3d
{
  class RenderEngine;

  class BaseView
  {
  public:
    BaseView() {}
    virtual ~BaseView() {}

    virtual void                release_v() = 0;

    virtual void                setTransform_v(const Transform& i_Transform_ro) = 0;

    virtual void                update_v(uint32_t i_Flags_u32) = 0;
    virtual void                createBuffers_v(bool i_Indices_b, bool i_ResizeBuffers_b) = 0;

    // project position to view (GL to Mecl conversion, including scale, etc)
    virtual Vector3f            project_o(const Vector3f& i_GLPosition_ro) = 0;
    virtual Vector4f            project4_o(const Vector3f& i_GLPosition_ro) = 0;

    // unproject position from view (Mecl to GL conversion, including scale, etc)
    virtual Vector3f            unProject_o(const Vector3f& i_MeclPosition_ro) = 0;

    virtual bool_t              intersectRay_b(const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro) = 0;
    virtual bool_t              setHeight_b(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32) = 0;

    virtual void                render_v() = 0;
                                
    virtual void                onResize_v() = 0;
  };

} // namespace me3d

#endif
