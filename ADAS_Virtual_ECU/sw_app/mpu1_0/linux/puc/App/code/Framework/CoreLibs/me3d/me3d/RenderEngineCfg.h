//--------------------------------------------------------------------------                                                                                                           
/// @file RenderEngineCfg.h                                                                         
/// @brief Configure Render Engine Buffer size
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef RENDERENGINE_CFG_H
#define RENDERENGINE_CFG_H

#include <platform/PlatformAPI.h>

namespace me3d
{
  const char_t   c_PathSeparator_c                  = '/';

  // Device3D
  const uint32_t c_MaxBoundVertexBuffers_u32        = 16U;

  // VertexBuffer
  const uint32_t c_MaxBufferLayoutElements_u32      = 6U;

  // BufferManager
  const uint32_t c_MaxVertexBuffers_u32             = 512U;
  const uint32_t c_MaxIndexBuffers_u32              = 256U;

  // ConstantsManager
  const uint32_t c_MaxFloat32Constants_u32          = 16U;
  const uint32_t c_MaxMatrix4x4Constants_u32        = 64U;
  const uint32_t c_MaxMatrix3x3Constants_u32        = 8U;
  const uint32_t c_MaxVector4fConstants_u32         = 16U;
  const uint32_t c_MaxVector3fConstants_u32         = 16U;
  const uint32_t c_MaxSint32Constants_u32           = 8U;
  const uint32_t c_MaxUint32Constants_u32           = 8U;
  const uint32_t c_MaxTextureConstants_u32          = 16U;
  const uint32_t c_MaxBoolConstants_u32             = 8U;
  const uint32_t c_MaxBoneMatrices_u32              = 64U;

  // Light Manager
  const uint32_t c_MaxLights_u32                    = 1U;

  // View Manager
  const uint32_t c_MaxViews_u32                     = 8U;

  // GUI Manager
  const uint32_t c_MaxGuiObjects_u32                = 8U;  
  const uint32_t c_MaxTextObjects_u32               = 16U;
  const uint32_t c_MaxFonts_u32                     = 1U;

  // Guide Line Manager
  const uint32_t c_MaxGuideLineObjects_u32          = 16U;

  // Shader Manager
  const uint32_t c_MaxEffectFilePasses_u32          = 16U;
  const uint32_t c_MaxEffectFileShaders_u32         = c_MaxEffectFilePasses_u32 * 2U;
  const uint32_t c_MaxEffectFileDeclarations_u32    = c_MaxEffectFilePasses_u32;
  const uint32_t c_MaxEffectFileConstantBlocks_u32  = c_MaxEffectFilePasses_u32;
  const uint32_t c_MaxEffectFileRenderBlocks_u32    = c_MaxEffectFilePasses_u32;
  const uint32_t c_MaxEffectFileLength_u32          = 19666U;

  // Texture Manager
  const uint32_t c_MaxTextures_u32                  = 128U;

  // Model Manager
  const uint32_t c_MaxModels_u32                    = 16U;

  // Material Manager
  const uint32_t c_MaxMaterials_u32                 = 16U;

  // Animation
  const uint32_t c_MaxNodeChildren_u32              = 64U;
  const uint32_t c_MaxNodes_u32                     = 512U;
  const uint32_t c_MaxBones_u32                     = 256U;
  const uint32_t c_MaxChannels_u32                  = 128U;
  const uint32_t c_MaxAnimations_u32                = 16U;
  const uint32_t c_MaxChannelKeys_u32               = 256U;

  // Debug Renderer
  const uint32_t c_MaxDebugRenderObjects_u32        = 256U;
  const uint32_t c_MaxDebugVertexBufferSize_u32     = 1024U;
  const uint32_t c_MaxDebugIndexBufferSize_u32      = 512U;


} // namespace me3d

#endif
