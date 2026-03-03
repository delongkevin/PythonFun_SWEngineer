//--------------------------------------------------------------------------                                                                                                           
/// @file GuideLineInterface.h                                                                         
/// @brief Forwards an interface to handle Guide Lines
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GUIDE_LINE_INTERFACE_H
#define GUIDE_LINE_INTERFACE_H

#include "MeclTypeDefs.h"

#include "Common/GuideLine/GuideLineTypes.h"

namespace me3d
{

  class RenderInterface;

  class GuideLineInterface
  {
  public:
    GuideLineInterface();
    ~GuideLineInterface();

    /// Create interface
    void create_v(RenderInterface* b_RenderInterface_po);

    /// Create GuideLine Object.
    /// Rules: must be multiple of 2
    /// path must contain at least 4 entries
    /// path Points is in OpenGL Coordinates
    uint32_t msgCreate_u32(const GuideLineObjectDesc_s& i_Desc_rs)const;

    bool_t msgRelease_b(uint32_t i_Id_u32)const;

    bool_t msgSetUseOrthoProj_b(uint32_t i_Id_u32, bool_t i_UseOrthoProj_b)const;

    /// Same rules as create, updates the data and flushes to GPU
    bool_t msgUpdatePath_b(uint32_t i_Id_u32, const mepl::vector<Vector3f>& i_Path_rs)const;

    /// Sets the World matrix
    bool_t msgSetWorldMatrix_b(uint32_t i_Id_u32, const me3d::Matrix4f& i_World_ro)const;

    /// Sets the color
    bool_t msgSetColor_b(uint32_t i_Id_u32, const me3d::Color& i_Color_ro)const;

    /// gets bounding box
    bool_t msgGetBoundingBox_b(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const;

    /// must be called each frame
    bool_t msgRender_b(uint32_t i_Id_u32)const;

  private:
    RenderInterface* renderInterface_po;
  };

} // namespace me3d

#endif // SVG_INTERFACE_H
