//--------------------------------------------------------------------------                                                                                                           
/// @file TextureManagerVK.h                                                                         
/// @brief Vulkan TextureManager implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


// PRQA S 1051 EOF // Still working on complete vulkan port, this is a reminder to implement these functions


#ifndef TEXTUREMANAGER_VK_H
#define TEXTUREMANAGER_VK_H


// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN


#include "Common/Manager/TextureManager.h"

#include "Vulkan/VKIncludes.h"

namespace me3d
{

class Texture;
class RenderTarget;
class MultipleRenderTarget;
class EffectFileSamplerStateBlock;

class TextureManagerVK : public TextureManager
{
public:
  TextureManagerVK();
  virtual ~TextureManagerVK();

  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);

  //void commitDefaultSamplerStates_v(GLenum i_TextureType_e , GLuint i_TextureId_u32);

public:
  virtual MultipleRenderTarget* createMultipleRenderTarget_po();

protected:
  virtual Texture* createTexture_po();
  virtual RenderTarget* createRenderTarget_po();

  void createDefaultSamplerStates_v();

  EffectFileSamplerStateBlock* defaultSamplerStates_po;

};

} // namespace me3d

#endif

#endif // RE_USE_VULKAN
