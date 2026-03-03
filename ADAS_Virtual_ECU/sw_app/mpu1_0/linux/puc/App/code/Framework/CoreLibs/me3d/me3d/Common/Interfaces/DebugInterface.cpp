#include "Common/Interfaces/DebugInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Renderer/DebugRenderer.h"

namespace me3d
{

  DebugInterface::DebugInterface()
    : debugRenderer_po(NULL)
  {

  }

  DebugInterface::~DebugInterface()
  {

  }

  void DebugInterface::create_v(DebugRenderer* b_DebugRenderer_po)
  {
    debugRenderer_po = b_DebugRenderer_po;
  }

  void DebugInterface::msgDrawUnitAxes_v()const
  {
    debugRenderer_po->drawUnitAxes_v();
  }

  void DebugInterface::msgDrawLine_v(const Matrix4f& i_World_ro, const Vector3f& i_Start_ro, const Vector3f& i_End_ro, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawLine_v(i_World_ro, i_Start_ro, i_End_ro, i_Color_ro);
  }

  void DebugInterface::msgDrawBox_v(const Matrix4f& i_World_ro, const Vector3f& i_Center_ro, const Vector3f& i_Extents_ro, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawBox_v(i_World_ro, i_Center_ro, i_Extents_ro, i_Color_ro);
  }

  void DebugInterface::msgDrawBoxSolid_v(const Matrix4f& i_World_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawBoxSolid_v(i_World_ro, i_Min_ro, i_Max_ro, i_Color_ro);
  }

  void DebugInterface::msgDrawPlane_v(const Matrix4f& i_World_ro, float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawPlane_v(i_World_ro, i_ExtentsX_f32, i_ExtentsY_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawCircle_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawCircle_v(i_World_ro, i_Radius_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawArcLines_v(const Matrix4f& i_World_ro, float32_t i_Radius1_f32, float32_t i_Radius2_f32, float32_t i_Angle1_f32, float32_t i_Angle2_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawArcLines_v(i_World_ro, i_Radius1_f32, i_Radius2_f32, i_Angle1_f32, i_Angle2_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawSphere_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawSphere_v(i_World_ro, i_Radius_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawCylinder_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawCylinder_v(i_World_ro, i_Radius_f32, i_Height_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawCapsule_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawCapsule_v(i_World_ro, i_Radius_f32, i_Height_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawCone_v(const Matrix4f& i_World_ro, float32_t i_Angle_f32, float32_t i_Height_f32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawCone_v(i_World_ro, i_Angle_f32, i_Height_f32, i_Color_ro);
  }

  void DebugInterface::msgDrawTriangles_v(const Matrix4f& i_World_ro, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Color& i_Color_ro)const
  {
    debugRenderer_po->drawTriangles_v(i_World_ro, i_Vertices_pf32, i_Indices_pu16, i_VertexCount_u32, i_IndexCount_u32, i_Color_ro);
  }

} // namespace me3d