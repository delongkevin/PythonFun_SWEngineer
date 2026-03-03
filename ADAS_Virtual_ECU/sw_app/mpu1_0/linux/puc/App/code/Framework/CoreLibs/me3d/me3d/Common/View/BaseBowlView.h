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

#ifndef BASE_BOWL_VIEW_H
#define BASE_BOWL_VIEW_H

#include "Common/View/ViewTypes.h"
#include "Common/View/BaseView.h"
#include "Math/Transform.h"
#include "Math/BBox3D.h"

namespace me3d
{
  class RenderEngine;

  class BaseBowlView : public BaseView
  {
  public:
    BaseBowlView();
    virtual ~BaseBowlView();

    BowlViewDesc_s* getDesc_ps();
    const BBox3D_s& getBounds_ro() const;

    void setRenderStitching_v(bool_t i_RenderStitching_b);
    bool_t getRenderStitching_b() const;

    void setStitchingArea_v(StitchingArea_e i_StitchingAreaType_e, const StitchingArea_s& i_Area_rs);
    const StitchingArea_s& getStitchingArea_rs(StitchingArea_e i_StitchingAreaType_e) const;

    // Interface to Get and set the obscuration zone.  return a member variable to return a default reference here.
    virtual const BBox2D_s& getObscurationZone_rs() const { return cameraBounds_as[0]; }
    virtual void setObscurationZone_v(const BBox2D_s& i_Bounds_rs) { }

    // project position to view (GL to Mecl conversion, including scale, etc)
    virtual Vector3f project_o(const Vector3f& i_GLPosition_ro) ME_OVERRIDE;
    virtual Vector4f project4_o(const Vector3f& i_GLPosition_ro) ME_OVERRIDE;

    // unproject position from view (Mecl to GL conversion, including scale, etc)
    virtual Vector3f unProject_o(const Vector3f& i_MeclPosition_ro) ME_OVERRIDE;

    // BaseView implementation
    virtual void onResize_v() ME_OVERRIDE;
    virtual void setTransform_v(const Transform& i_Transform_ro) ME_OVERRIDE;

  protected:
    bool getVertexIndex_b(float32_t i_X_f32, float32_t i_Z_f32, uint32_t& o_Index_ru32) const;
    void renderStitching_v();

    Vector3f getCameraPosition_o(RealCamera_e i_Camera_e) const;
    Vector2f  getFrontAxisOffset_o() const;
    void createCameraBounds_v();
    void createDefaultStitchingLines_v();

  protected:
    RenderEngine*     renderEngine_po;
    BowlViewDesc_s    desc_s;
    BBox3D_s          bounds_s;
    bool_t            renderStitching_b;
    Transform         transform_o;
    BBox2D_s          cameraBounds_as[e_RcCount];
    StitchingArea_s   stitchingAreas_as[e_SaCount];
  };

} // namespace me3d

#endif
