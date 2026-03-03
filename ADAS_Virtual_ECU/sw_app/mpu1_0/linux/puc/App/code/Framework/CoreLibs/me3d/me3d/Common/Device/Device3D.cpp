#include "Device3D.h"

#include "Common/RenderEngineTypes.h"
#include "Common/Resources/MultipleRenderTarget.h"
#include "Common/Manager/TextureManager.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/ConstantsManager.h"

// PRQA S 5118 EOF // C++14 Autosar Standard permits

namespace me3d
{

Device3D::Device3D()
  : renderEngine_po(NULL) 
  , device3DDesc_s()
  , backBufferviewPort_s()
  , constantOrthoWVP_po(NULL)
{
}

Device3D::~Device3D()
{
  // PRQA S 4260 1 // It's intended to call the virtual function here
  // PRQA S 4261 2 // This function doesn't throw exceptions
  // PRQA S 4631 1 // This function doesn't throw exceptions
  release_v();
}

bool Device3D::create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs)
{
  renderEngine_po = i_RenderEngine_po;
  device3DDesc_s = i_Desc_rs;

  backBufferviewPort_s.width_u32    = device3DDesc_s.screenWidth_u32;
  backBufferviewPort_s.height_u32   = device3DDesc_s.screenHeight_u32;
  backBufferviewPort_s.minDepth_f32 = 0.0F;
  backBufferviewPort_s.maxDepth_f32 = 100.0F;
  backBufferviewPort_s.topLeftX_u32 = 0U;
  backBufferviewPort_s.topLeftY_u32 = 0U;

  return true;
}

void Device3D::release_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxBoundVertexBuffers_u32; ++v_I_u32)
  {
    vertexBuffers_as[v_I_u32].stride_u32 = 0U;
    vertexBuffers_as[v_I_u32].offset_u32 = 0U;
  }

  constantOrthoWVP_po   = NULL;
}

void Device3D::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{
  device3DDesc_s.screenWidth_u32 = i_Width_u32;
  device3DDesc_s.screenHeight_u32 = i_Height_u32;

  setViewPort_b(device3DDesc_s.screenWidth_u32, device3DDesc_s.screenHeight_u32, 0U, 0U); 
}

void Device3D::beginFrame_v()
{

}

void Device3D::endFrame_v()
{
}

bool_t Device3D::pushViewPort_b()
{
  ViewPortDesc_s v_ViewPort_s;
  bool_t v_ViewPortPushed_b = false;

  if (true == getViewPort_b(v_ViewPort_s))
  {
    viewPortStack.push(v_ViewPort_s);

    v_ViewPortPushed_b = true;
  }

  return v_ViewPortPushed_b;
}

bool_t Device3D::popViewPort_b()
{
  bool_t v_ViewPortPopped_b = false;

  if (viewPortStack.size() > 0)
  {
    setViewPort_b(viewPortStack.top());
    
    viewPortStack.pop();

    v_ViewPortPopped_b = true;
  }

  return v_ViewPortPopped_b;
}

bool Device3D::setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs)
{
  // commit constants for shader
  if (renderEngine_po->getConstantsManager_po())
  {
    // Query Viewport-Constant. Can't do in create, because ConstantManager is created after Device3D
    if (NULL == constantOrthoWVP_po)
    {
      constantOrthoWVP_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cOrthoWVP", e_CtMatrix4, 1U));
    }

    // update data based on new viewPort
    if (constantOrthoWVP_po)
    {
      // Commit orthographic matrix
      Matrix4f v_WVP_o = Matrix4f::createOrtho(0.0F, static_cast<float32_t>(i_ViewPort_rs.width_u32), 
                                               0.0F, static_cast<float32_t>(i_ViewPort_rs.height_u32), 
                                               -100.0F, 100.0F); 
      constantOrthoWVP_po->setData_v(&v_WVP_o);
    }
  }

  return true;
}

bool Device3D::setViewPort_b(uint32_t i_Width_u32, uint32_t i_Height_u32, uint32_t i_TopLeftX_u32 /*= 0U*/, uint32_t i_TopLeftY_u32 /*= 0U*/)
{
  ViewPortDesc_s v_ViewPort_s;
  
  bool v_SetViewPort_b = false;

  if (getViewPort_b(v_ViewPort_s))
  {
    v_ViewPort_s.width_u32    = i_Width_u32;
    v_ViewPort_s.height_u32   = i_Height_u32;
    v_ViewPort_s.topLeftX_u32 = i_TopLeftX_u32;
    v_ViewPort_s.topLeftY_u32 = i_TopLeftY_u32;

    v_SetViewPort_b = setViewPort_b(v_ViewPort_s);
  }

  return v_SetViewPort_b;
}

bool Device3D::getViewPort_b(ViewPortDesc_s& o_ViewPort_rs)
{
  return true;
}

void Device3D::getBackBufferSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32)
{
  o_Width_u32  = device3DDesc_s.screenWidth_u32;
  o_Height_u32 = device3DDesc_s.screenHeight_u32;
}

void Device3D::clearScreen_v(uint32_t i_ClearFlags_u32)
{
  clearScreen_v(i_ClearFlags_u32, device3DDesc_s.clearColor_o, 1.0F, 0, 0);
}

void Device3D::clearScreen_v(uint32_t i_ClearFlags_u32, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32)
{
  clearScreen_v(i_ClearFlags_u32, device3DDesc_s.clearColor_o, i_ClearDepth_f32, i_ClearStencil_u32, i_Index_u32);
}

bool_t Device3D::pushMultipleRenderTarget_b(MultipleRenderTarget* i_MRT_po)
{
  bool_t v_PushedMRT_b = true;

  if ( (NULL == i_MRT_po) || mrtStack.empty())
  {
    v_PushedMRT_b = false;
  }
  else
  {
    mrtStack.push(i_MRT_po);
  }

  return v_PushedMRT_b;
}

void Device3D::popMultipleRenderTarget_v()
{
  bool_t v_Failure_b = false;

  // Back buffer MRT must always exist
  if (mrtStack.size() <= 1)
  {
    // Too many pop's on the multiple render target stack!
    Assert(false);
  
    v_Failure_b = true;
  }

  // Remove current mrt from stack
  if (false == v_Failure_b)
  {
    mrtStack.pop();

    // bind previous multiple render target
    MultipleRenderTarget* v_PrevMRT_po = mrtStack.top();

    if (NULL == v_PrevMRT_po)
    {
      Assert(false);
      v_Failure_b = true;
    }
    else
    {
      v_PrevMRT_po->setMRTResources_b(v_PrevMRT_po->GetFace_u32(), v_PrevMRT_po->getLevel_u32(), v_PrevMRT_po->getDepthBufferSetMode_e());
    }

  }

}

void Device3D::createBackBufferMRT_v()
{
  // Retrieves the current color and depth stencil buffer and adds them
  // to the stack. The back buffer must be the first entry on the stack!
  Assert(mrtStack.empty());

  if (mrtStack.empty())
  {
    MultipleRenderTarget* v_MRT_po = renderEngine_po->getTextureManager_po()->createMultipleRenderTarget_po();

    v_MRT_po->createBackBufferMRT_v(this);

    mrtStack.push(v_MRT_po);
  }
}

void Device3D::releaseBackBufferMRT_v()
{
  // Removes the color and depth stencil buffer from the stack.
  // Important: The back buffer is the first entry on the stack!
  size_t v_Size_t = mrtStack.size();
  Assert(v_Size_t == 1);

  if (v_Size_t == 1)
  {
    MultipleRenderTarget* v_MRT_po = mrtStack.top();

    v_MRT_po->releaseBackBufferMRT_v();

    delete v_MRT_po;

    mrtStack.pop();
  }
}

void Device3D::draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32)
{
  // TODOopt: statistics
}

void Device3D::drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32)
{
  // TODOopt: statistics
}

bool Device3D::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32)
{
  // TODO: support multiple slots
  Assert(i_Slot_u32 == 0U);

  bool v_Success_b = i_Slot_u32 < c_MaxBoundVertexBuffers_u32;
  Assert(v_Success_b);

  if (v_Success_b)
  {
    vertexBuffers_as[i_Slot_u32].c_Buffer_po = i_Buffer_po;
    vertexBuffers_as[i_Slot_u32].offset_u32  = i_Offset_u32;
    vertexBuffers_as[i_Slot_u32].stride_u32  = 0U;
  }

  return v_Success_b;
}

bool Device3D::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32)
{
  // TODO: support multiple slots
  Assert(i_Slot_u32 == 0U);

  bool v_Success_b = i_Slot_u32 < c_MaxBoundVertexBuffers_u32;
  Assert(v_Success_b);

  if (v_Success_b)
  {
    vertexBuffers_as[i_Slot_u32].c_Buffer_po = i_Buffer_po;
    vertexBuffers_as[i_Slot_u32].offset_u32  = i_Offset_u32;
    vertexBuffers_as[i_Slot_u32].stride_u32  = i_Stride_u32;
  }

  return v_Success_b;
}

void Device3D::resetVertexBuffer_v(uint32_t i_Slot_u32)
{
  setVertexBuffer_b(NULL, 0U, 0U);
}

} // namespace me3d