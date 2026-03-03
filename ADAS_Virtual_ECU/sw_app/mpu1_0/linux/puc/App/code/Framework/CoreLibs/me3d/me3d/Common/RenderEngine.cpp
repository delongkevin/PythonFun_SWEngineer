#include "RenderEngine.h"

#include "Common/Resources/MultipleRenderTarget.h"

#include "Common/Device/Device3D.h"

#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Manager/MaterialManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/LightManager.h"
#include "Common/Manager/GUIManager.h"
#include "Common/Manager/CameraManager.h"
#include "Common/Manager/ModelManager.h"
#include "Common/Manager/ViewManager.h"
#include "Common/Manager/GuideLineManager.h"

#include "Common/Renderer/DebugRenderer.h"
#include "Common/Renderer/ModelRenderer.h"
#include "Common/Renderer/ViewRenderer.h"
#include "Common/Renderer/CubeMapRenderer.h"
#include "Common/Renderer/GUIRenderer.h"
#include "Common/Renderer/GuideLineRenderer.h"


// PRQA S 3223 EOF // this is howl STL works
// PRQA S 5118 EOF // c++14 autosar standard permits
// PRQA S 4020 EOF // makes code more readable
// PRQA S 3706 EOF // performance
// PRQA S 4327 EOF // TODO: used for pre-compiled shaders which still needs to be implemented
// PRQA S 4213 EOF // used by design, need non const access

namespace me3d
{

RenderEngine::RenderEngine()
  : renderEngineDesc_s()
  , device3D_po(NULL)
  , finalMRT_po(NULL)
  , enableFlags_u32(e_EftAll)
  , renderTargetFlags_u32(e_RfRenderTargetNull)
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    manager_apo[v_I_u32] = NULL;
  }

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    renderer_apo[v_I_u32] = NULL;
  }
}

RenderEngine::~RenderEngine()
{
}

bool RenderEngine::create_b(const RenderEngineDesc_s& i_Desc_rs)
{
  // 1) assign description
  renderEngineDesc_s = i_Desc_rs;

  ME_Debugger_F_Printf_v("RenderEngine - Create device \n");
  // 2) Create Device
  device3D_po = createDevice_po();
  device3D_po->create_b(this, renderEngineDesc_s.deviceDesc_s);


  ME_Debugger_F_Printf_v("RenderEngine - Create all managers \n");
  // 3) create all Managers
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    manager_apo[v_I_u32] = createManager_po(static_cast<ManagerType_e>(v_I_u32));
  }

  ME_Debugger_F_Printf_v("RenderEngine - Call create for all manager \n");
  // 3.1) Now call create for all Managers
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    if (NULL != manager_apo[v_I_u32])
    {
      manager_apo[v_I_u32]->create_b(this);
    }
  }

  ME_Debugger_F_Printf_v("RenderEngine - Create back buffer MRT \n");
  // create back buffer MRT
  device3D_po->createBackBufferMRT_v();

  ME_Debugger_F_Printf_v("RenderEngine - Create all renderer \n");
  // 4) create all renderer
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    renderer_apo[v_I_u32] = createRenderer_po(static_cast<RendererType_e>(v_I_u32));
  }

  ME_Debugger_F_Printf_v("RenderEngine - Call create for all renderer \n");
  // 4.1) Now call create for all renderer
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    renderer_apo[v_I_u32]->create_b(this);
  }

  // 5.) Define the render sequences (In which order do we render all the different objects?)
  defineRenderSequences_v();

  device3D_po->setViewPort_b(renderEngineDesc_s.deviceDesc_s.screenWidth_u32, renderEngineDesc_s.deviceDesc_s.screenHeight_u32);

  return true;
}

void RenderEngine::release_v()
{
#ifdef RE_USE_VULKAN
  // release device
  if (NULL != device3D_po)
  {
    device3D_po->release_v();

    delete device3D_po;
    device3D_po = NULL;
  }
  return;
#endif


  if (NULL != device3D_po)
  {
    device3D_po->releaseBackBufferMRT_v();
  }

  releaseRenderSequences_v();

  // release all renderer in reverse order
  for (sint32_t v_I_s32 = (static_cast<sint32_t>(e_RtCount) - 1); v_I_s32 >= 0; --v_I_s32)
  {
    renderer_apo[v_I_s32]->release_v();
  }

  for (sint32_t v_I_s32 = (static_cast<sint32_t>(e_RtCount) - 1); v_I_s32 >= 0; --v_I_s32)
  {
    delete renderer_apo[v_I_s32];
    renderer_apo[v_I_s32] = NULL;
  }
  
  // release all Manager in reverse order
  for (sint32_t v_I_s32 = (static_cast<sint32_t>(e_MtCount) - 1); v_I_s32 >= 0; --v_I_s32)
  {
    if (NULL != manager_apo[v_I_s32])
    {
      manager_apo[v_I_s32]->release_v();
    }
  }

  for (sint32_t v_I_s32 = (static_cast<sint32_t>(e_MtCount) - 1); v_I_s32 >= 0; --v_I_s32)
  {
    if (NULL != manager_apo[v_I_s32])
    {
      delete manager_apo[v_I_s32];
      manager_apo[v_I_s32] = NULL;
    }
  }

  // release device
  if (NULL != device3D_po)
  {
    device3D_po->release_v();

    delete device3D_po;
    device3D_po = NULL;
  }
}

void RenderEngine::serialize_v(InOut& b_IO_ro)
{

}

void RenderEngine::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32) const
{
  device3D_po->onResize_v(i_Width_u32, i_Height_u32);

  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    if (NULL != manager_apo[v_I_u32])
    {
      manager_apo[v_I_u32]->onResize_v(i_Width_u32, i_Height_u32);
    }
  }

  for (uint32_t v_I_u32 = 0; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    renderer_apo[v_I_u32]->onResize_v(i_Width_u32, i_Height_u32);
  }
}

void RenderEngine::beginFrame_v(MultipleRenderTarget* i_MRT_po)
{
  device3D_po->beginFrame_v();

  finalMRT_po = i_MRT_po;

  if (NULL != finalMRT_po)
  {
    // don't call with any clear flags
    finalMRT_po->setMultipleRenderTargets_b(e_RtfClearAll);
  }


  // call begin frame for all manager
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    IManager* v_Manager_po = manager_apo[v_I_u32];

    if ((NULL != v_Manager_po) &&
        (true == v_Manager_po->isEnabled_b()))
    {
       v_Manager_po->beginFrame_v();
    }
  }

  // call begin frame for all renderer
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    IRenderer* v_Render_po = renderer_apo[v_I_u32];

    if ((NULL != v_Render_po) && 
        (true == v_Render_po->isEnabled_b()))
    {
      v_Render_po->beginFrame_v();
    }
  }
}

void RenderEngine::endFrame_v()
{

  // manager pre render (add Pre Render Targets)
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    if ((NULL != manager_apo[v_I_u32]) && 
        (manager_apo[v_I_u32]->isEnabled_b()))
    {
      manager_apo[v_I_u32]->preRender_v();
    }
  }

  // Render into all pre-render targets
  if (false == preRenderTargets_t.empty())
  {
    renderToRenderTargets_v(&preRenderTargets_t[0], static_cast<uint32_t>(preRenderTargets_t.size()));
  }

  // Render the Sequence to backBuffer
  overwriteRenderTargetFlags_v(e_RfRenderTargetBackBuffer);
  renderSequence_v();


  // Call Managers PostRender

  // Call Renderers PostRender


  // Reset renderer
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_RtCount; ++v_I_u32)
  {
    renderer_apo[v_I_u32]->reset_v();
  }

  // Reset Manager
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_MtCount; ++v_I_u32)
  {
    if (NULL != manager_apo[v_I_u32])
    {
      manager_apo[v_I_u32]->reset_v();
    }
  }


  // Only present to swap chain when rendering to back buffer
  if (NULL == finalMRT_po)
  {
    
  }

  // clear pre render target list
  preRenderTargets_t.resize(0);

   // Restore the back buffer
  if (NULL != finalMRT_po)
  {
    finalMRT_po->restoreMultipleRenderTargets_v();
  
    finalMRT_po = NULL;
  }
}

void RenderEngine::defineRenderSequences_v()
{
  // Render just the standard Sequence. TODO: optimize for overdraw
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtCubeMap,   std::bind(&CubeMapRenderer::render_v,           getCubeMapRenderer_po()),   "Cube");
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtModel,     std::bind(&ModelRenderer::renderDefault_v,      getModelRenderer_po()),     "Model");
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtView,      std::bind(&ViewRenderer::renderAll_v,           getViewRenderer_po()),      "View");
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtGuideLine, std::bind(&GuideLineRenderer::renderAll_v,      getGuideLineRenderer_po()), "GuideLine");
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtModel,     std::bind(&ModelRenderer::renderTransparent_v,  getModelRenderer_po()),     "Transparent Model");
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtDebug,     std::bind(&DebugRenderer::renderDefault_v,      getDebugRenderer_po()),     "Debug");

  // Compute post-effects and output them to the back buffer and render the GUI
  addRenderSequenceEntry_v(e_RfRenderTargetBackBuffer, e_RtGui,       std::bind(&GUIRenderer::render_v,               getGUIRenderer_po()),       "GUI");
}

void RenderEngine::releaseRenderSequences_v()
{
  for (sint32_t v_i_s32 = static_cast<sint32_t>(renderSequences_t.size()) - 1; v_i_s32 >= 0; v_i_s32--)
  {
    if (NULL != renderSequences_t[v_i_s32])
    {
      delete renderSequences_t[v_i_s32];
    }
  }

  renderSequences_t.clear();
}

void RenderEngine::addRenderSequenceEntry_v(RenderEngineRenderTargetFlag_e i_TargetFlag_e, RendererType_e i_Type_e, RenderFunction_t i_Function_t, const char_t* i_FunctionName_pc /*= NULL*/)
{
  uint32_t v_Index_u32 = getRenderSequenceIndex_u32(i_TargetFlag_e);

  // Maybe create a new renderer sequence for the target flag
  if (v_Index_u32 >= static_cast<uint32_t>(renderSequences_t.size()))
  {
    renderSequences_t.resize(v_Index_u32 + 1);
  }

  if (renderSequences_t[v_Index_u32] == NULL)
  {
    renderSequences_t[v_Index_u32] = new std::vector<RenderSequenceEntry_s>();
  }

  // Add the new sequence entry
  renderSequences_t[v_Index_u32]->push_back(RenderSequenceEntry_s(i_Type_e, i_Function_t, i_FunctionName_pc));
}

uint32_t RenderEngine::getRenderSequenceIndex_u32(uint32_t renderTargetFlags)
{
  // Compute index (render target flag bit position) inside the sequence array
  return static_cast<sint32_t>(log(static_cast<float32_t>(renderTargetFlags)) / log(2.0F));
}

void RenderEngine::addPreRenderTarget_v(RenderEngineRenderTargetFlag_e i_RenderFlag_e, ManagerType_e i_ManagerType_e)
{
  // Add new pre-render target
  preRenderTargets_t.resize(preRenderTargets_t.size() + 1);

  size_t indexVal = preRenderTargets_t.size() - 1;

  // Set flag and pointer to the manager
  preRenderTargets_t[indexVal].RenderFlag_e = i_RenderFlag_e;
  preRenderTargets_t[indexVal].Manager_e = i_ManagerType_e;
}

void RenderEngine::renderToRenderTargets_v(PreRenderTarget_s* i_List_ps, uint32_t i_Size_u32)
{
  // Store color buffers and depth-stencil buffer
  if (i_Size_u32 == 0U)
  {
    return;
  }

  for (uint32_t v_I_u32 = 0; v_I_u32 < i_Size_u32; v_I_u32++)
  {
    ManagerType_e v_ManagerType_e = i_List_ps[v_I_u32].Manager_e;
    IManager* v_Manager_po = manager_apo[v_ManagerType_e];

    // Set flag (must be called before BeginScene())
    overwriteRenderTargetFlags_v(i_List_ps[v_I_u32].RenderFlag_e);

    // Set pre-render target
    if ((NULL == v_Manager_po) || ( false == v_Manager_po->beginScene_b()))
    {
      removeRenderTargetFlags_v(i_List_ps[v_I_u32].RenderFlag_e);
    }
    else
    {
      // Render all renderer into the new pre-render target
      renderSequence_v();

      // Restore the old render target
      v_Manager_po->endScene_v();
    }
  }
}

void RenderEngine::renderSequence_v()
{
  if (renderTargetFlags_u32 <= 0)
  {
    return;
  }

  // Get renderer sequence to the current render target
  uint32_t v_Sequenceindex_u32 = getRenderSequenceIndex_u32(renderTargetFlags_u32);

  if (static_cast<size_t>(v_Sequenceindex_u32) >= renderSequences_t.size())
  {
    return;
  }

  std::vector<RenderSequenceEntry_s>* v_RenderSequence_pt = renderSequences_t[v_Sequenceindex_u32];

  if (NULL != v_RenderSequence_pt)
  {
    size_t sequenceCount = v_RenderSequence_pt->size();

    for (size_t v_I_t = 0; v_I_t < sequenceCount; v_I_t++)
    {
      RenderSequenceEntry_s& v_SequenceEntry_rs = v_RenderSequence_pt->at(v_I_t);

      if (renderer_apo[v_SequenceEntry_rs.Type_e] && renderer_apo[v_SequenceEntry_rs.Type_e]->isEnabled_b())
      {
        // Call the render function of the sequence
        v_SequenceEntry_rs.Function_t();
      }
    }
  }
}

IManager* RenderEngine::createManager_po(ManagerType_e i_Type_e)
{
  IManager* v_Manager_po = NULL;

  switch (i_Type_e)
  {
    case e_MtBuffer:  
		{
		v_Manager_po = NULL;                   
		break;
		}
    case e_MtTexture: 
		{
		v_Manager_po = NULL;                    
		break;
		}
    case e_MtShader: 
		{
		v_Manager_po = NULL;                   
		break;
		}
    case e_MtConstants:
		{
		v_Manager_po = new ConstantsManager();  
		break;
		}
    case e_MtLight: 
		{
		v_Manager_po = new LightManager();     
		break;
		}
    case e_MtCamera: 
		{
		v_Manager_po = new CameraManager();     
		break;
		}
    case e_MtMaterial: 
		{
		v_Manager_po = new MaterialManager();   
		break;
		}
    case e_MtModel:  
		{
		v_Manager_po = new ModelManager();     
		break;
		}
    case e_MtView:
		{
		v_Manager_po = new ViewManager();      
		break;
		}
    case e_MtGui: 
		{
		v_Manager_po = new GUIManager();        
		break;
		}
    case e_MtGuideLine: 
		{
		v_Manager_po = new GuideLineManager(); 
		break;
		}
    case e_MtCount:     // fall through
    default:
		{
      Assert(false);
      break;
		}
  }

  return v_Manager_po;
}

IRenderer* RenderEngine::createRenderer_po(RendererType_e i_Type_e)
{
  IRenderer* v_Renderer_po = NULL;

  switch (i_Type_e)
  {
    case e_RtModel: 
		{
		v_Renderer_po = new ModelRenderer();      
		break;
		}
    case e_RtView: 
		{
		v_Renderer_po = new ViewRenderer();      
		break;
		}
    case e_RtCubeMap:   
		{
		v_Renderer_po = new CubeMapRenderer();   
		break;
		}
    case e_RtGui:
		{
		v_Renderer_po = new GUIRenderer();       
		break;
		}
    case e_RtGuideLine:
		{
		v_Renderer_po = new GuideLineRenderer();  
		break;
		}
    case e_RtDebug:  
		{
		v_Renderer_po = new DebugRenderer();     
		break;
		}
    case e_RtCount:   // fall through
    default:
		{
      break;
		}
  }

  return v_Renderer_po;
}

} // namespace me3D
