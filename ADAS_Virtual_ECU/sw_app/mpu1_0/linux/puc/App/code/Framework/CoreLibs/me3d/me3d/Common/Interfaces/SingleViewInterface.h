#ifndef SINGLE_VIEW_INTERFACE_H
#define SINGLE_VIEW_INTERFACE_H

#include "Common/View/ViewTypes.h"
#include "Common/Device/Device3DTypes.h"

namespace me3d
{
  class RenderInterface;
  class Transform;

  class SingleViewInterface
  {
  public:
    SingleViewInterface();
    ~SingleViewInterface();

    // Create Interface
    void create_v(RenderInterface* b_RenderInterface_po);

    // Create View via Descriptor
    uint32_t msgCreate_u32(const SingleViewDesc_s& i_Desc_rs)const;

    // Release View
    bool msgRelease_b(uint32_t i_Id_u32)const;

    // Render View
    bool msgRender_b(uint32_t i_Id_u32)const;

    // Update certain parts of the View via flags, see ViewUpdateFlag_e in ViewTypes.h
    bool msgUpdate_b(uint32_t i_Id_u32, uint32_t i_Flags_u32)const;

    // Set Real Camera Textures
    bool msgSetTexture_b(uint32_t i_Id_u32, const MEString& i_Name_ro)const;

    bool msgGetSingleViewDesc_b(uint32_t i_Id_u32, me3d::SingleViewDesc_s& o_SingleViewDesc_rs)const;

    bool msgSetSingleViewTexture_b(uint32_t i_Id_u32, uint32_t i_TextureId_u32)const;

    // set the View's transform
    bool msgSetTransform_b(uint32_t i_Id_u32, const Transform& i_Transform_ro)const;

    // Ray View Intersection
    bool msgIntersectRay_b(uint32_t i_Id_u32, const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)const;

    // Set View Dimensions
    bool msgSetDimensions_b(uint32_t i_Id_u32, const Vector2f& i_Dimensions_ro)const;

    // Get View dimensions
    bool msgGetDimensions_b(uint32_t i_Id_u32, Vector2f& o_Dimensions_ro)const;

    // Set Real Camera for Single View
    bool msgSetRealCamera_b(uint32_t i_Id_u32, Cameraf* i_Camera_po)const;

    // Set Synthetic Camera for Single View
    bool msgSetSyntheticCamera_b(uint32_t i_Id_u32, Cameraf* i_Camera_po)const;

    // set (single view) width and height
    bool msgSetSize_b(uint32_t i_Id_u32, const Vector2f& i_Size_ro)const;

    // get (single view) width and height
    bool msgGetSize_b(uint32_t i_Id_u32, Vector2f& o_Size_ro)const;

    // project a GL coordinate onto a MECL coordinate 
    bool msgProject_b(uint32_t i_Id_u32, const Vector3f& i_GlPosition_ro, Vector3f& o_MeclPosition_ro)const;

    // project a MECL coordinate onto a GL coordinate
    bool msgUnProject_b(uint32_t i_Id_u32, const Vector3f& i_MeclPosition_ro, Vector3f& o_GlPosition_ro)const;

  private:
    RenderInterface* renderInterface_po;

  };

} // namespace me3d

#endif
