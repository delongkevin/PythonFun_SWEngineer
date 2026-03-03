#include "Common/Resources/MultipleRenderTarget.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Resources/RenderTarget.h"

// PRQA S 3054 EOF // flag handling
// PRQA S 3710 EOF // flag handling

namespace me3d
{

MultipleRenderTarget::MultipleRenderTarget()
  : renderEngine_po(NULL)
{
  for (uint32_t v_RenderTarget_u32 = 0U; v_RenderTarget_u32 < MAX_MRT_COLOR_RTS; ++v_RenderTarget_u32)
  {
    colorRenderTargets_apo[v_RenderTarget_u32] = NULL;
  }

  depthRenderTarget_po = 0;

  face_u32 = 0U;
  level_u32 = 0U;
  depthBufferSetMode_e = e_DbsSetDepthBuffer;
}

MultipleRenderTarget::~MultipleRenderTarget()
{

}

bool_t MultipleRenderTarget::create_b(RenderEngine* i_RenEng_po, RenderTargetDesc_s** i_ColorDesc_pps, RenderTargetDesc_s* i_DepthDesc_ps)
{
  renderEngine_po = i_RenEng_po;

  return true;
}

void MultipleRenderTarget::release_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < MAX_MRT_COLOR_RTS; ++v_I_u32)
  {
    RenderTarget* v_Current_po = colorRenderTargets_apo[v_I_u32];

    if (NULL != v_Current_po)
    {
      renderEngine_po->getTextureManager_po()->releaseRenderTarget_v(v_Current_po);
      
      v_Current_po = NULL;
    }
  }

  if (NULL != depthRenderTarget_po)
  {
    renderEngine_po->getTextureManager_po()->releaseRenderTarget_v(depthRenderTarget_po);

    depthRenderTarget_po = NULL;
  }
}

void MultipleRenderTarget::createBackBufferMRT_v(Device3D* i_Device_po)
{

}

void MultipleRenderTarget::releaseBackBufferMRT_v()
{

}

void MultipleRenderTarget::onLostDevice_v()
{

}

void MultipleRenderTarget::onResetDevice_v()
{

}

bool_t MultipleRenderTarget::setMRTResources_b(uint32_t i_Face_u32, uint32_t i_Level_u32, DepthBufferSetMode_e i_Mode_e /*= e_DbsSetDepthBuffer*/)
{
  face_u32             = i_Face_u32;
  level_u32            = i_Level_u32;
  depthBufferSetMode_e = i_Mode_e;

  return true;
}

bool_t MultipleRenderTarget::setMultipleRenderTargets_b(uint32_t i_ClearFlags_u32 , Color i_ClearColor_o, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32,
	uint32_t i_Face_u32, uint32_t i_Level_u32, const ViewPortDesc_s* i_ViewPort_ps, DepthBufferSetMode_e i_DepthBufferSetMode_e)
{
  bool v_Result_b = true;

  if ((colorRenderTargets_apo[0] == NULL) && (depthRenderTarget_po == NULL))
  {
    v_Result_b = false;
  }

  if ((depthBufferSetMode_e != e_DbsNoDepthBuffer) && (level_u32 > 0))
  {
    Assert(false);

    v_Result_b = false;
  }

  if (true == v_Result_b)
  {
    // Push the view port onto the stack.
    // Maybe a resource to the device already changed 

    v_Result_b = renderEngine_po->getDevice_po()->pushViewPort_b();
  }

  if (true == v_Result_b)
  {
    const RenderTargetDesc_s* c_MainDesc_ps = getMainDesc_ps();

    // None cube map render targets always use Face zero
    i_Face_u32 = (c_MainDesc_ps->type_e != e_TtCube) ? 0 : i_Face_u32;

    // push render target on stack
    renderEngine_po->getDevice_po()->pushMultipleRenderTarget_b(this);

    // Set the resources (Direct3D surfaces, OpenGL Buffers, etc) as new targets to the device
    v_Result_b = setMRTResources_b(i_Face_u32, i_Level_u32, i_DepthBufferSetMode_e);

    if (false == v_Result_b)
    {
      renderEngine_po->getDevice_po()->popMultipleRenderTarget_v();
      renderEngine_po->getDevice_po()->popViewPort_b();
    }
  }

  // set a new Viewport
  if (true == v_Result_b)
  {
    ViewPortDesc_s v_ViewPortDesc_s;

    // check if viewport is assigned 
    if (NULL != i_ViewPort_ps)
    {
      // and if so, use it
      memcpy(&v_ViewPortDesc_s, i_ViewPort_ps, sizeof(ViewPortDesc_s)); 
    }
    else
    {
      // and if not, take a view port suitable to the size of the render target
      v_ViewPortDesc_s.topLeftX_u32 = 0U;
      v_ViewPortDesc_s.topLeftY_u32 = 0U;
      v_ViewPortDesc_s.minDepth_f32 = 0.0F;
      v_ViewPortDesc_s.maxDepth_f32 = 1.0F;

      // Get virtual Size (even if it differs from actual size)
      getSize_v(v_ViewPortDesc_s.width_u32, v_ViewPortDesc_s.height_u32, true);
    }

    // set the new viewport to the device
    v_Result_b = renderEngine_po->getDevice_po()->setViewPort_b(v_ViewPortDesc_s);

    if (false == v_Result_b)
    {
      renderEngine_po->getDevice_po()->popMultipleRenderTarget_v();
      renderEngine_po->getDevice_po()->popViewPort_b();
    }

    // clear the newly set renderTargets
    if (i_ClearFlags_u32 != 0)
    {
      renderEngine_po->getDevice_po()->clearScreen_v(i_ClearFlags_u32, i_ClearColor_o, i_ClearDepth_f32, i_ClearStencil_u32, 0);
    }

  }


  return v_Result_b;
}

void MultipleRenderTarget::restoreMultipleRenderTargets_v(uint32_t i_ResolveFlags_u32 /*= e_RtfResolveNone*/)const
{
  // 1.) Resolve the current target
  if (i_ResolveFlags_u32 != e_RtfResolveNone)
  {
    resolve_v(i_ResolveFlags_u32);
  }

  // 2. Restore the previously set MRTs
  renderEngine_po->getDevice_po()->popMultipleRenderTarget_v();

  // 3. Restore the view port
  renderEngine_po->getDevice_po()->popViewPort_b();
}

void MultipleRenderTarget::resolve_v(uint32_t i_ResolveFlags_u32)const
{
  if (i_ResolveFlags_u32 & e_RtfResolveColor)
  {
    for (uint32_t v_I_u32 = 0; v_I_u32 < MAX_MRT_COLOR_RTS; v_I_u32++)
    {
      if (colorRenderTargets_apo[v_I_u32])
      {
        colorRenderTargets_apo[v_I_u32]->resolve_v(i_ResolveFlags_u32 & e_RtfResolveColor, v_I_u32);
      }
    }
  }

  if ((i_ResolveFlags_u32) && (i_ResolveFlags_u32 & e_RtfResolveDepth))
  {
    depthRenderTarget_po->resolve_v(i_ResolveFlags_u32 & e_RtfResolveDepth);
  }
}

void MultipleRenderTarget::generateMipMaps_v()const
{
  for (uint32_t v_RenderTarget_u32 = 0U; v_RenderTarget_u32 < MAX_MRT_COLOR_RTS; ++v_RenderTarget_u32)
  {
    RenderTarget* v_ColorRenderTarget_po = colorRenderTargets_apo[v_RenderTarget_u32];
    if (NULL != v_ColorRenderTarget_po)
    {
      v_ColorRenderTarget_po->generateMipMaps_v();
    }
  }
}

RenderTarget* MultipleRenderTarget::getColorRenderTarget_po(uint32_t i_index_u32 /*= 0U*/)const
{
  RenderTarget* v_ColorRenderTarget_po = NULL;

  if (i_index_u32 < MAX_MRT_COLOR_RTS)
  {
    v_ColorRenderTarget_po = colorRenderTargets_apo[i_index_u32];
  }

  return v_ColorRenderTarget_po;
}

RenderTarget* MultipleRenderTarget::getDepthRenderTarget_po()const
{
  return depthRenderTarget_po;
}

const RenderTargetDesc_s* MultipleRenderTarget::getMainDesc_ps()const
{
  const RenderTargetDesc_s* c_Desc_rs = NULL;

  if (colorRenderTargets_apo[0])
  {
    c_Desc_rs = &colorRenderTargets_apo[0]->getDesc_rs();
  }
  else
  {
    c_Desc_rs = &depthRenderTarget_po->getDesc_rs();
  }

  return c_Desc_rs;
}

uint32_t MultipleRenderTarget::GetFace_u32()const
{
  return face_u32;
}

uint32_t MultipleRenderTarget::getLevel_u32()const
{
  return level_u32;
}

DepthBufferSetMode_e MultipleRenderTarget::getDepthBufferSetMode_e()const
{
  return depthBufferSetMode_e;
}

void MultipleRenderTarget::getSize_v(uint32_t& o_Width_u32, uint32_t& o_Height_u32, bool_t i_UsedViewport_b)const
{
  const RenderTarget* c_MainRenderTarget_po = colorRenderTargets_apo[0] ? colorRenderTargets_apo[0] : depthRenderTarget_po;

  if (NULL != c_MainRenderTarget_po)
  {
    const RenderTargetDesc_s& c_MainDesc_rs = c_MainRenderTarget_po->getDesc_rs();
  
    if ((i_UsedViewport_b) && (c_MainDesc_rs.flags_u32 & e_RtrUseCroppedViewport))
    {
      // check if needed
      Assert(false);
      //c_MainRenderTarget_po->getUsed
      o_Width_u32  = c_MainDesc_rs.width_u32;
      o_Height_u32 = c_MainDesc_rs.height_u32;
    }
    else
    {
      // set physical size
      o_Width_u32  = c_MainDesc_rs.width_u32;
      o_Height_u32 = c_MainDesc_rs.height_u32;
    }
  }
  else
  {
    o_Width_u32  = 0U;
    o_Height_u32 = 0U;
  }

}

} // namespace me3d