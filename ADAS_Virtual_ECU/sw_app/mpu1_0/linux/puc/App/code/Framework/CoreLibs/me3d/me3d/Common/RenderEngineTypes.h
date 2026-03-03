//--------------------------------------------------------------------------                                                                                                           
/// @file RenderEngineTypes.h                                                                         
/// @brief Provides the Managers, Renderer and RenderEngine descriptor
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef RENDER_ENGINE_TYPES_H
#define RENDER_ENGINE_TYPES_H

#include <platform/PlatformAPI.h>

#include "Math/Color.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

struct Device3DDesc_s
{
  void*    windowHandle_pv;
  void*    deviceHandle_pv;
  uint32_t screenWidth_u32;
  uint32_t screenHeight_u32;
  Color    clearColor_o;

  Device3DDesc_s()
    : windowHandle_pv(NULL)
    , deviceHandle_pv(NULL)
    , screenWidth_u32(800U)
    , screenHeight_u32(600U)
  {
    clearColor_o = Color::Red;
  }
};

struct RenderEngineDesc_s
{
  Device3DDesc_s deviceDesc_s;
};

enum RendererType_e
{
  e_RtModel = 0,
  e_RtView,    
  e_RtCubeMap, 
  e_RtGui,
  e_RtGuideLine,
  e_RtDebug,
  e_RtCount
};

enum ManagerType_e
{
  e_MtBuffer = 0,
  e_MtTexture,
  e_MtShader,
  e_MtConstants,
  e_MtLight,        // Uses Constants
  e_MtCamera,       // Uses Constants
  e_MtMaterial,     // Uses Constants, Shaders, Textures
  e_MtModel,        // Uses Constants, Shaders, Textures, Buffers
  e_MtView,         // Uses Constants, Shaders, Textures, Buffers
  e_MtGui,          // Uses Constants, Shaders, Textures, Buffers
  e_MtGuideLine,    // Uses Constants, Shaders, Textures, Buffers
  e_MtCount
};

// Flags to control certrain render features each frame
enum EnableFlagType_e
{
  e_EftGui        = 0x00000001,
  e_EftGuideLine  = 0x00000002,
  e_EftModel      = 0x00000004,
  e_EftCubeMap    = 0x00000008, 
  e_EftBowlView   = 0x00000010,

  // PRQA S 3604 1 // force unsigned intended
  e_EftAll        = 0xFFFFFFFF
};

// Render Target Handling

// The structure defines a pre-render target (shadow map, reflection map, ...) which is set from the manager. 
// After the target is set, the render engine render the complete scene into the new render target. But before rendering the new render flag is set.
// Render target flags must begin by 1 and continuous increase
	enum RenderEngineRenderTargetFlag_e
	{
		e_RfRenderTargetNull        = 0x00000000,        ///< Uninitialized state
		e_RfRenderTargetBackBuffer  = 0x00000001,        ///< Rendering to the backbuffer (Result of the posteffect and GUI rendering)
		e_RfRenderTargetDefault     = 0x00000002,        ///< Result of the forward rendering (models, transparent objects, particle effects, ...)
    e_RfRenderTarget3DView      = 0x00000004,        ///< Result of 3D View Rendering
    e_RfRenderTargetSingleView  = 0x00000008         ///< Result of Single View Rendering
	};


  struct PreRenderTarget_s
  {
    RenderEngineRenderTargetFlag_e RenderFlag_e;     ///< The Render Target Flag
    ManagerType_e                  Manager_e;        ///< Manager which sets/resets the pre-render target
  };

  typedef std::function<void()> RenderFunction_t;

  // Renderer sequence entry
  struct RenderSequenceEntry_s
  {
    RendererType_e        Type_e;           ///< Renderer Type for this sequence
    RenderFunction_t      Function_t;       ///< The Render function for this Renderer Type
    const char_t*         FunctionName_pc;  ///< Name of the Render Sequence

    // PRQA S 4054 1 // initialization list is not needed, this default constructor is just needed for stl container
    RenderSequenceEntry_s()
    : Type_e(e_RtModel)
    , FunctionName_pc(NULL)
    {
    }

    // PRQA S 4054 1 // it's okay here
    RenderSequenceEntry_s(RendererType_e i_Type_e, RenderFunction_t& i_Function_t, const char_t* i_FunctionName_pc = NULL)
    {
      Type_e = i_Type_e;
      Function_t = i_Function_t;
      FunctionName_pc = i_FunctionName_pc;
    }
  };

} // namespace me3d

#endif // RENDER_ENGINE_TYPES_H
