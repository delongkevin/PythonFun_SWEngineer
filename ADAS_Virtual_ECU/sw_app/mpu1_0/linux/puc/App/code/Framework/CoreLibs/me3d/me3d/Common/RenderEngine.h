//--------------------------------------------------------------------------                                                                                                           
/// @file RenderEngine.h                                                                         
/// @brief Contains all API independent Manager, Renderer and the Device
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H

#include <platform/PlatformAPI.h>

#include "Common/RenderEngineTypes.h"
#include "Utilities/GUIDGenerator.h"


// PRQA S 2101 EOF // protected members used here by design, providing easy manager and renderer access for derived classes
// PRQA S 2127 EOF // virtual function overload used here by design.
// PRQA S 4628 EOF // Returning a non const handle to data pointed to by a member is intended here. 
// PRQA S 3077 EOF // downcast is intended 
// PRQA S 3076 EOF // downcast is intended

namespace me3d
{

class Device3D;
class MultipleRenderTarget;

class IManager;
class ShaderManager;
class TextureManager; 
class BufferManager; 
class ConstantsManager;
class ModelManager;   
class GUIManager;     
class GuideLineManager;     
class CameraManager;  
class ViewManager; 
class LightManager;   
class MaterialManager;

class IRenderer;
class DebugRenderer;
class ModelRenderer;
class ViewRenderer;
class CubeMapRenderer;
class GUIRenderer;
class GuideLineRenderer;


class RenderEngine
{
public:
  RenderEngine();
  virtual ~RenderEngine();

  bool create_b(const RenderEngineDesc_s& i_Desc_rs);
  void release_v();

  static void serialize_v(InOut& b_IO_ro);

  void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32) const;

  void beginFrame_v(MultipleRenderTarget* i_MRT_po);
  void endFrame_v();

  // --- Device access ---
  inline Device3D*          getDevice_po()           const { return device3D_po; }

  // --- Manager access ---
  ME_INLINE ShaderManager*     getShaderManager_po()    const { return reinterpret_cast<ShaderManager*>    (manager_apo[e_MtShader]);    }
  ME_INLINE TextureManager*    getTextureManager_po()   const { return reinterpret_cast<TextureManager*>   (manager_apo[e_MtTexture]);   }
  ME_INLINE BufferManager*     getBufferManager_po()    const { return reinterpret_cast<BufferManager*>    (manager_apo[e_MtBuffer]);    }
  ME_INLINE ConstantsManager*  getConstantsManager_po() const { return reinterpret_cast<ConstantsManager*> (manager_apo[e_MtConstants]); }
  ME_INLINE ModelManager*      getModelManager_po()     const { return reinterpret_cast<ModelManager*>     (manager_apo[e_MtModel]);     }
  ME_INLINE GUIManager*        getGUIManager_po()       const { return reinterpret_cast<GUIManager*>       (manager_apo[e_MtGui]);       }
  ME_INLINE GuideLineManager*  getGuideLineManager_po() const { return reinterpret_cast<GuideLineManager*> (manager_apo[e_MtGuideLine]);       }
  ME_INLINE CameraManager*     getCameraManager_po()    const { return reinterpret_cast<CameraManager*>    (manager_apo[e_MtCamera]);    }
  ME_INLINE ViewManager*       getViewManager_po()      const { return reinterpret_cast<ViewManager*>      (manager_apo[e_MtView]);      }
  ME_INLINE LightManager*      getLightManager_po()     const { return reinterpret_cast<LightManager*>     (manager_apo[e_MtLight]);     }
  ME_INLINE MaterialManager*   getMaterialManager_po()  const { return reinterpret_cast<MaterialManager*>  (manager_apo[e_MtMaterial]);  }

  // --- Renderer access ---
  ME_INLINE DebugRenderer*     getDebugRenderer_po()      const { return reinterpret_cast<DebugRenderer*>     (renderer_apo[e_RtDebug]);     }
  ME_INLINE ModelRenderer*     getModelRenderer_po()      const { return reinterpret_cast<ModelRenderer*>     (renderer_apo[e_RtModel]);     }
  ME_INLINE GUIRenderer*       getGUIRenderer_po()        const { return reinterpret_cast<GUIRenderer*>       (renderer_apo[e_RtGui]);       }
  ME_INLINE GuideLineRenderer* getGuideLineRenderer_po()  const { return reinterpret_cast<GuideLineRenderer*> (renderer_apo[e_RtGuideLine]); }
  ME_INLINE CubeMapRenderer*   getCubeMapRenderer_po()    const { return reinterpret_cast<CubeMapRenderer*>   (renderer_apo[e_RtCubeMap]);   }
  ME_INLINE ViewRenderer*      getViewRenderer_po()       const { return reinterpret_cast<ViewRenderer*>      (renderer_apo[e_RtView]);      }

  // --- Enable Flags Handling ---

  // Returns true if the specified flags are set
  ME_INLINE bool_t isEnabled_b(uint32_t i_Flags_u32) const
  {
    // PRQA S 3054 1 // implicit conversion to bool is understood and intended
    return (enableFlags_u32 & i_Flags_u32) ? true : false;
  }

  // Add the specified enable flags
  ME_INLINE void addEnableFlags_v(uint32_t i_Flags_u32)
  {
    enableFlags_u32 |= i_Flags_u32;
  }

  // removes the specified enable flags
  ME_INLINE void removeEnableFlags_v(uint32_t i_Flags_u32)
  {
    enableFlags_u32 &= ~i_Flags_u32;
  }

  // overrides all enable flags by specified flags
  ME_INLINE void overrideEnableFlags_v(uint32_t i_Flags_u32)
  {
    enableFlags_u32 = i_Flags_u32;
  }

  // --- Render Target Handling ---

  // Returns true if the specified render target flag is set, false if not
  ME_INLINE bool_t isRenderTargetFlagSet_b(uint32_t i_Flags_u32) const
  {
    // PRQA S 3054 1 // implicit conversion to bool is understood and intended
    return (renderTargetFlags_u32 & i_Flags_u32) ? true : false;
  }

  // Adds the specified render target flags
  ME_INLINE void addRenderTargetFlags_v(uint32_t i_Flags_u32)
  {
    renderTargetFlags_u32 |= i_Flags_u32;
  }

  // Removes the specified render target flags
  ME_INLINE void removeRenderTargetFlags_v(uint32_t i_Flags_u32)
  {
    renderTargetFlags_u32 &= ~i_Flags_u32;
  }

  // Overwrite all render target flags
  ME_INLINE void overwriteRenderTargetFlags_v(uint32_t i_Flags_u32)
  {
    renderTargetFlags_u32 = i_Flags_u32;
  }

  // Define the renderer sequences for each render target flag
  void defineRenderSequences_v();

  // Release all renderer sequences
  void releaseRenderSequences_v();

  /// Add new entry to the renderer sequence
  void addRenderSequenceEntry_v(RenderEngineRenderTargetFlag_e i_TargetFlag_e, RendererType_e i_Type_e, RenderFunction_t i_Function_t, const char_t* i_FunctionName_pc = NULL);
 
  /// Return the render sequence array index of the assigned render target flag
  static uint32_t getRenderSequenceIndex_u32(uint32_t renderTargetFlags);

  /// Add new pre-render target (e. g. shadow map, reflection map, ...)
  void addPreRenderTarget_v(RenderEngineRenderTargetFlag_e i_RenderFlag_e, ManagerType_e i_ManagerType_e);

  /// Render the scene into the pre-render targets
  void renderToRenderTargets_v(PreRenderTarget_s* i_List_ps, uint32_t i_Size_u32);

  /// Render the complete render sequence. set an suitable sequence flag
  void renderSequence_v();

protected:
  virtual Device3D*  createDevice_po() = 0;

  virtual IManager*  createManager_po(ManagerType_e i_Type_e); 
  virtual IRenderer* createRenderer_po(RendererType_e i_Type_e);

protected:
  RenderEngineDesc_s                                  renderEngineDesc_s;       ///< Render Engine Descriptor which contains the configuration
  Device3D*                                           device3D_po;              ///< Pointer to Device
  MultipleRenderTarget*                               finalMRT_po;              ///< The final MRT, the scene is rendered to instead of to the back buffer. Null if rendering to back buffer
  uint32_t                                            enableFlags_u32;          ///< Enable/disable certain Renderers
  uint32_t                                            renderTargetFlags_u32;    ///< Render target flags (combination of RenderEngineRenderTargetFlag flags)
  mepl::vector<std::vector<RenderSequenceEntry_s>*>   renderSequences_t;        ///< The renderer sequence define, at which time and how often a renderer calls render()
  mepl::vector<PreRenderTarget_s>                     preRenderTargets_t;       ///< Contains all currently added pre-render-targets (e.g. reflection map)
  IManager*                                           manager_apo [e_MtCount];  ///< Contains all Managers
  IRenderer*                                          renderer_apo[e_RtCount];  ///< Contains all Renderers
};

} // namespace me3d
 
#endif // RENDER_ENGINE_H
