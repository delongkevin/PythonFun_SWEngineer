#ifndef BOWL_VIEW_INTERFACE_H
#define BOWL_VIEW_INTERFACE_H

#include "Common/View/ViewTypes.h"

namespace me3d
{
  class RenderInterface;
  class Transform;

  struct BowlViewDesc_s;
  struct BBox3D_s;

  class BowlViewInterface
  {
  public:
    BowlViewInterface();
    ~BowlViewInterface();

    // Create Interface
    void create_v(RenderInterface* b_RenderInterface_po);

    // Create View via Descriptor
    uint32_t msgCreate_u32(const BowlViewDesc_s& i_Desc_rs)const;

    // Release View
    bool msgRelease_b(uint32_t i_Id_u32)const;

    // Render View
    bool msgRender_b(uint32_t i_Id_u32)const;

    // Set static Bowl Parameters
    // X = Bowl Radius Lateral
    // Y = Bowl Radius Longitudinal
    // Z = Bowl Bending Radius steepness
    bool msgSetBowlParameters_b(uint32_t i_Id_u32, const Vector3f& i_Params_ro)const;

    // Get static Bowl Parameters
    bool msgGetBowlParameters_b(uint32_t i_Id_u32, Vector3f& o_Params_ro)const;

    // Get or set the bowl deformation method, ellipse based is the default method.
    bool msgSetBowlDeformationMethod_b(uint32_t i_Id_u32, BowlDeformationMethod_e i_Bdm_e);
    bool msgGetBowlDeformationMethod_b(uint32_t i_Id_u32, BowlDeformationMethod_e& o_Bdm_e);

    // Sets the controlpoints for spline based bowl deformation method.
    bool msgSetControlPoints_b(uint32_t i_Id_u32, bool i_LeftRight_b, const Vector3f& i_P0_ro, const Vector3f& i_P1_ro, const Vector3f& i_P2_ro, const Vector3f& i_P3_ro) const;
    bool msgGetControlPoints_b(uint32_t i_Id_u32, bool i_LeftRight_b, Vector3f& o_P0_ro, Vector3f& o_P1_ro, Vector3f& o_P2_ro, Vector3f& o_P3_ro) const;

    // Set the Projection scale
    bool msgSetProjectionScale_b(uint32_t i_Id_u32, const Vector3f& i_Scale_ro)const;

    // Get the Projection scale
    bool msgGetProjectionScale_b(uint32_t i_Id_u32, Vector3f& o_Scale_ro)const;

    // Get the View's Bounding box
    bool msgGetBoundingBox_b(uint32_t i_Id_u32, BBox3D_s& o_Bounds_ro)const;

    // Gets the obscuration zone
    bool msgGetObscurationZone_b(uint32_t i_Id_u32, BBox2D_s& o_Bounds_ro) const;

    // Sets the obscuration zone
    bool msgSetObscurationZone_b(uint32_t i_Id_u32, const BBox2D_s& i_Bounds_ro) const;

    // Update certain parts of the View via flags, see ViewUpdateFlag_e in ViewTypes.h
    bool msgUpdate_b(uint32_t i_Id_u32, uint32_t i_Flags_u32)const;

    // Set Real Camera Textures
    bool msgSetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, uint32_t i_TextureId_u32)const;
    bool msgSetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, const MEString& i_Name_ro)const;
    bool msgGetTexture_b(uint32_t i_Id_u32, RealCamera_e i_RealCamera_e, MEString& o_Name_ro)const;

    // set the View's transform
    bool msgSetTransform_b(uint32_t i_Id_u32, const Transform& i_Transform_ro)const;

    // set stitching area parameter
    bool msgSetStitchingArea_b(uint32_t i_Id_u32, StitchingArea_e i_StitchingAreaType_e, const StitchingArea_s& i_Area_rs)const;

    // get stitching area parameter
    bool msgGetStitchingArea_b(uint32_t i_Id_u32, StitchingArea_e i_StitchingAreaType_e, StitchingArea_s& o_Area_rs)const;

    // Ray View Intersection
    bool msgIntersectRay_b(uint32_t i_Id_u32, const Vector3f& i_RayOrigin_ro, const Vector3f& i_RayDir_ro, Vector3f& o_Intersection_ro)const;

    // Get Offset from vehicle coordinate system origin (front axis) to View Origin
    bool msgGetFrontAxisOffset_b(uint32_t i_Id_u32, float32_t& o_Offset_f32)const;

    // Set View Dimensions
    bool msgSetDimensions_b(uint32_t i_Id_u32, const Vector2f& i_Dimensions_ro)const;

    // Get View dimensions
    bool msgGetDimensions_b(uint32_t i_Id_u32, Vector2f& o_Dimensions_ro)const;

    // set real camera pointer to associate with this View id
    bool msgSetRealCamera_b(uint32_t i_Id_u32, RealCamera_e i_RealCam_e, Cameraf* i_Camera_po)const;

    // Get real camera pointer associated with this View id
    bool msgGetRealCamera_b(uint32_t i_Id_u32, RealCamera_e i_RealCam_e, Cameraf** o_Camera_po)const;

    // set if stitching shall be rendered
    bool msgSetRenderStitching_b(uint32_t i_Id_u32, bool_t i_RenderStitching_b)const;

    // get if stitching shall be rendered
    bool msgGetRenderStitching_b(uint32_t i_Id_u32, bool_t& o_RenderStitching_b)const;

    bool msgProject_b(uint32_t i_Id_u32, const Vector3f& i_GlPosition_ro, Vector3f& o_MeclPosition_ro)const;
    bool msgUnProject_b(uint32_t i_Id_u32, const Vector3f& i_MeclPosition_ro, Vector3f& o_GlPosition_ro)const;

  private:
    RenderInterface* renderInterface_po;

  };

} // namespace me3d

#endif
