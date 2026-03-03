#include "DebugRenderer.h"

 
#include <mecl/model/Camera.h>
#include <mecl/model/Pinhole.h>
#include <mecl/core/RotationMatrix.h>

#include "Math/MathLib.h"
#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Manager/ShaderManager.h"

namespace me3d
{

DebugRenderer::DebugRenderer()
  : IRenderer()
  , renderEngine_po(NULL)
  , debugEffect_po(NULL)
  , constantWVP_po(NULL)
  , constantColor_po(NULL)
  , numDebugObjects_u32(0U)
{
   for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxDebugVertexBufferSize_u32; ++v_I_u32)
   {
     vertexBuffer_af32[v_I_u32] = 0.0F;
   }

   for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxDebugIndexBufferSize_u32; ++v_I_u32)
   {
     indexBuffer_au16[v_I_u32] = 0;
   }
}

DebugRenderer::~DebugRenderer()
{

}

bool_t DebugRenderer::isEnabled_b()
{
  return true;
}

bool DebugRenderer::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  debugEffect_po   = renderEngine_po->getShaderManager_po()->createShader_po(e_ShaderDebug);
  constantWVP_po   = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cWVPMatrix", e_CtMatrix4, 1U));
  constantColor_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("diffuseColor", e_CtFloat4, 1U));

  return true;
}

void DebugRenderer::release_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxDebugRenderObjects_u32; ++v_I_u32)
  {
    DebugRenderObject* v_Obj_po = &debugObjects_ao[v_I_u32];
  
    if (NULL != v_Obj_po)
    {
      v_Obj_po->release_v(renderEngine_po);
      v_Obj_po = NULL;
    }
  }

  debugEffect_po   = NULL;
  constantWVP_po   = NULL;
  constantColor_po = NULL;
}

void DebugRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void DebugRenderer::beginFrame_v()
{

}

void DebugRenderer::reset_v()
{

  for (uint32_t v_I_u32 = 0U; v_I_u32 < numDebugObjects_u32; ++v_I_u32)
  {
    // release vertex and index buffers
    DebugRenderObject* v_Obj_po = &debugObjects_ao[v_I_u32];
    v_Obj_po->release_v(renderEngine_po);
  }

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxDebugVertexBufferSize_u32; ++v_I_u32)
  {
    vertexBuffer_af32[v_I_u32] = 0.0F;
  }

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxDebugIndexBufferSize_u32; ++v_I_u32)
  {
    indexBuffer_au16[v_I_u32] = 0;
  }

  // reset debug objects
  numDebugObjects_u32 = 0U;
}

void DebugRenderer::renderDefault_v()
{
  renderEngine_po->getDevice_po()->clearScreen_v(e_RtfClearDepth);

  // Set constants
  const Matrix4f& c_VP_ro = renderEngine_po->getCameraManager_po()->getCamera_ro().getViewProjMat_ro();

  for (uint32_t v_I_u32 = 0U; v_I_u32 < numDebugObjects_u32; ++v_I_u32)
  {
    DebugRenderObject* v_Obj_po = &debugObjects_ao[v_I_u32];

    // Set World * View * Projection Matrix
    const Matrix4f& c_World_ro = v_Obj_po->getWorldMatrix_ro();
    Matrix4f v_WVP_o = c_World_ro.mmulFast(c_VP_ro);
    constantWVP_po->setData_v(&v_WVP_o);

    // Set color
    constantColor_po->setData_v(&v_Obj_po->getColor_ro());

    // Set VertexBuffer and Indexbuffer (if necessary)
    v_Obj_po->getVertexBuffer_po()->set_v(0);

    bool v_HasIndices_b = NULL != v_Obj_po->getIndexBuffer_po();
    if (v_HasIndices_b)
    {
      v_Obj_po->getIndexBuffer_po()->set_v();
    }

    // begin rendering
    debugEffect_po->beginPass_b();

    if (v_HasIndices_b)
    {
      renderEngine_po->getDevice_po()->drawIndexed_v(v_Obj_po->getPrimitiveTye_e(), v_Obj_po->getNumIndices_u32(), 0);
    }
    else
    {
      renderEngine_po->getDevice_po()->draw_v(v_Obj_po->getPrimitiveTye_e(), v_Obj_po->getNumVertices_u32(), 0U);
    }

    // end rendering
    debugEffect_po->endPass_v();

  }
}

void DebugRenderer::drawUnitAxes_v()
{
  // get arrow lines for axes
  uint32_t v_NumVerts_u32 = getArrowLines_v(0.25F, 2.0F, &vertexBuffer_af32[0]);

  // red X Axis
  Quaternionf v_XaxisRot_o;
  v_XaxisRot_o.fromAngleAxis(mecl::math::toRadians_x(-90.0F), Vector3f(0.0F, 0.0F, 1.0F));
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, v_XaxisRot_o.toMatrix4x4(), Color::Red);

  // green Y Axis
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, Matrix4f(), Color::Green);

  // blue Z Axis
  Quaternionf v_ZaxisRot_o;
  v_ZaxisRot_o.fromAngleAxis(mecl::math::toRadians_x(90.0F), Vector3f(1.0F, 0.0F, 0.0F));
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, v_ZaxisRot_o.toMatrix4x4(), Color::Blue);
}

void DebugRenderer::drawBox_v(const Matrix4f& i_World_ro, const Vector3f& i_Center_ro, const Vector3f& i_Extents_ro, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = 0U;
  uint32_t v_NumInds_u32  = 0U;

  getBoxLines_v(
    i_Center_ro.getPosX(), 
    i_Center_ro.getPosY(), 
    i_Center_ro.getPosZ(), 
    i_Extents_ro.getPosX(), 
    i_Extents_ro.getPosY(), 
    i_Extents_ro.getPosZ(), 
    &vertexBuffer_af32[0], 
    &indexBuffer_au16[0], 
    v_NumVerts_u32, 
    v_NumInds_u32);

  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], &indexBuffer_au16[0], v_NumVerts_u32, v_NumInds_u32, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawBoxSolid_v(const Matrix4f& i_World_ro, const Vector3f& i_Min_ro, const Vector3f& i_Max_ro, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = 0U;
  uint32_t v_NumInds_u32  = 0U;

  getBoxTriangles_v(
    i_Min_ro.getPosX(), 
    i_Min_ro.getPosY(),
    i_Min_ro.getPosZ(), 
    i_Max_ro.getPosX(), 
    i_Max_ro.getPosY(), 
    i_Max_ro.getPosZ(), 
    &vertexBuffer_af32[0], 
    &indexBuffer_au16[0], 
    v_NumVerts_u32, 
    v_NumInds_u32);

  drawPrimitive_v(e_PtTriangleStrip, &vertexBuffer_af32[0], &indexBuffer_au16[0], v_NumVerts_u32, v_NumInds_u32, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawPlane_v(const Matrix4f& i_World_ro, float32_t i_ExtentsX_f32, float32_t i_ExtentsY_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getPLaneLines_v(i_ExtentsX_f32, i_ExtentsY_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawCircle_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getCircleLines_v(i_Radius_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawArcLines_v(const Matrix4f& i_World_ro, float32_t i_Radius1_f32, float32_t i_Radius2_f32, float32_t i_Angle1_f32, float32_t i_Angle2_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getArcLines_v(i_Radius1_f32, i_Radius2_f32, i_Angle1_f32, i_Angle2_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawSphere_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getSphereLines_v(i_Radius_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawCylinder_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getCylinderLines_v(i_Radius_f32, i_Height_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawCapsule_v(const Matrix4f& i_World_ro, float32_t i_Radius_f32, float32_t i_Height_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getCapsuleLines_v(i_Radius_f32, i_Height_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawCone_v(const Matrix4f& i_World_ro, float32_t i_Angle_f32, float32_t i_Height_f32, const Color& i_Color_ro)
{
  uint32_t v_NumVerts_u32 = getConeLines_v(i_Angle_f32, i_Height_f32, &vertexBuffer_af32[0]);
  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, v_NumVerts_u32, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawLine_v(const Matrix4f& i_World_ro, const Vector3f& i_Start_ro, const Vector3f& i_End_ro, const Color& i_Color_ro)
{
  vertexBuffer_af32[0] = i_Start_ro.getPosX();
  vertexBuffer_af32[1] = i_Start_ro.getPosY();
  vertexBuffer_af32[2] = i_Start_ro.getPosZ();

  vertexBuffer_af32[3] = i_End_ro.getPosX();
  vertexBuffer_af32[4] = i_End_ro.getPosY();
  vertexBuffer_af32[5] = i_End_ro.getPosZ();

  drawPrimitive_v(e_PtLines, &vertexBuffer_af32[0], NULL, 6, 0, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawTriangles_v(const Matrix4f& i_World_ro, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Color& i_Color_ro)
{
  drawPrimitive_v(e_PtTriangleList, i_Vertices_pf32, i_Indices_pu16, i_VertexCount_u32, i_IndexCount_u32, i_World_ro, i_Color_ro);
}

void DebugRenderer::drawPrimitive_v(PrimitiveType_e i_Mode_e, const float32_t* i_Vertices_pf32, const uint16_t* i_Indices_pu16, uint32_t i_VertexCount_u32, uint32_t i_IndexCount_u32, const Matrix4f& i_World_ro, const Color& i_Color_ro)
{
  Assert(numDebugObjects_u32 < c_MaxDebugRenderObjects_u32);
  
  DebugRenderObject* v_Obj_po = &debugObjects_ao[numDebugObjects_u32];

  v_Obj_po->release_v(renderEngine_po);

  v_Obj_po->setParams_v(i_World_ro, i_Color_ro, i_Mode_e);
  v_Obj_po->fillVertexBuffer_v(renderEngine_po, i_Vertices_pf32, i_VertexCount_u32);

  if (NULL != i_Indices_pu16)
  {
    v_Obj_po->fillIndexBuffer_v(renderEngine_po, i_Indices_pu16, i_IndexCount_u32);
  }

  ++numDebugObjects_u32;
}

} // namespace me3d
