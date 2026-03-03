#ifndef DEBUG_INTERFACE_H
#define DEBUG_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Model/ModelTypes.h"
#include "Math/BBox3D.h"
#include "Math/Color.h"

namespace me3d
{
  class DebugRenderer;

  class DebugInterface
  {
  public:
    DebugInterface();
    ~DebugInterface();

    void create_v(DebugRenderer* b_DebugRenderer_po);

    // Draws unit axes at the Origin
    void msgDrawUnitAxes_v()const;
    // Draws a 3D line
    void msgDrawLine_v(const Matrix4f& i_World_ro, const Vector3f& i_Start_ro, const Vector3f& i_End_ro, const Color& i_Color_ro)const;
    // Draws wire frame box
    void msgDrawBox_v(const Matrix4f& i_World_ro, const Vector3f& i_Center_ro, const Vector3f& i_Extents_ro, const Color& i_Color_ro)const;
    // Draws a solid box
    void msgDrawBoxSolid_v(const Matrix4f& i_World_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, const Color& i_Color_ro)const;
    // Draws a PLane
    void msgDrawPlane_v(const Matrix4f& i_World_ro, float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, const Color& i_Color_ro)const;
    // Draw circle with given radius
    void msgDrawCircle_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)const;
    // Draw arc lines given 2 radi and angles
    void msgDrawArcLines_v(const Matrix4f& i_World_ro, float32_t i_Radius1_f32, float32_t i_Radius2_f32, float32_t i_Angle1_f32, float32_t i_Angle2_f32, const Color& i_Color_ro)const;
    // Draw wire frame sphere
    void msgDrawSphere_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)const;
    // Draw wire frame cylinder
    void msgDrawCylinder_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)const;
    // Draw wire frame capsule
    void msgDrawCapsule_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)const;
    // Draw wire frame cone
    void msgDrawCone_v(const Matrix4f& i_World_ro, float32_t i_Angle_f32, float32_t i_Height_f32, const Color& i_Color_ro)const;
    // Draw list of triangles, supports indices, too
    void msgDrawTriangles_v(const Matrix4f& i_World_ro, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Color& i_Color_ro)const;

  private:
    DebugRenderer* debugRenderer_po;
  };
}

#endif