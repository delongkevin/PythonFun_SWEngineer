//--------------------------------------------------------------------------                                                                                                           
/// @file DebugRenderer.h                                                                         
/// @brief Used to render Debug data (Position and Color only). 
///        Caution: low performance. Buffers are re-created every frame
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEBUG_RENDERER_H
#define DEBUG_RENDERER_H

#include "IRenderer.h"


#include "MeclCfg.h"
#include "RenderEngineCfg.h"
#include "Math/Color.h"
#include "Utilities/DebugHelper.h"
#include "Common/Effect/EffectFile.h"
#include "Common/Camera/Camera.h"
#include "Common/Device/Device3DTypes.h"
#include "Common/Resources/IndexBuffer.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Resources/Constant.h"
#include "Common/Debug/DebugRenderObject.h"

namespace me3d
{


class DebugRenderer : public IRenderer
{
public:
  DebugRenderer();
  virtual ~DebugRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  // default rendering (just immediate for now)
  void renderDefault_v();


  void drawUnitAxes_v();
  void drawLine_v(const Matrix4f& i_World_ro, const Vector3f& i_Start_ro, const Vector3f& i_End_ro, const Color& i_Color_ro);
  void drawBox_v(const Matrix4f& i_World_ro, const Vector3f& i_Center_ro, const Vector3f& i_Extents_ro, const Color& i_Color_ro);
  void drawBoxSolid_v(const Matrix4f& i_World_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, const Color& i_Color_ro);
  void drawPlane_v(const Matrix4f& i_World_ro, float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, const Color& i_Color_ro);
  void drawCircle_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro);
  void drawArcLines_v(const Matrix4f& i_World_ro, float32_t i_Radius1_f32, float32_t i_Radius2_f32, float32_t i_Angle1_f32, float32_t i_Angle2_f32, const Color& i_Color_ro);
  void drawSphere_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro);
  void drawCylinder_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro);
  void drawCapsule_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro);
  void drawCone_v(const Matrix4f& i_World_ro, float32_t i_Angle_f32, float32_t i_Height_f32, const Color& i_Color_ro);
  void drawTriangles_v(const Matrix4f& i_World_ro, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Color& i_Color_ro);
  void drawPrimitive_v(PrimitiveType_e i_Mode_e, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Matrix4f& i_World_ro, const Color& i_Color_ro);

private:
  RenderEngine*       renderEngine_po;
  EffectFile*         debugEffect_po;

  Constant*           constantWVP_po;
  Constant*           constantColor_po;

  uint32_t            numDebugObjects_u32;
  DebugRenderObject   debugObjects_ao[c_MaxDebugRenderObjects_u32];

  float32_t           vertexBuffer_af32[c_MaxDebugVertexBufferSize_u32];
  uint16_t            indexBuffer_au16[c_MaxDebugIndexBufferSize_u32];
};

} // namespace me3d

#endif // DEBUG_RENDERER_H
