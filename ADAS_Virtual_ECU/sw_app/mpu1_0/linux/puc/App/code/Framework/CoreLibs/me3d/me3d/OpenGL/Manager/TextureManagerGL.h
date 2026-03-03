//--------------------------------------------------------------------------                                                                                                           
/// @file TextureManagerGL.h                                                                         
/// @brief OpenGL TextureManager implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 


// PRQA S 2128 EOF // we are using c++14 autsoar standard, overriding non pure base class virtual fuinctions is allowed
// PRQA S 2121 EOF // c++14 autsoar standard permits

#ifndef TEXTUREMANAGER_GL_H
#define TEXTUREMANAGER_GL_H

#include "Common/Manager/TextureManager.h"

#include "OpenGL/GLIncludes.h"

namespace me3d
{

class Texture;
class RenderTarget;
class MultipleRenderTarget;
class EffectFileSamplerStateBlockGL;

class TextureManagerGL : public TextureManager
{
public:
  TextureManagerGL();
  virtual ~TextureManagerGL();

  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);

  void commitDefaultSamplerStates_v(GLenum i_TextureType_e , GLuint i_TextureId_u32)const;

public:
  virtual MultipleRenderTarget* createMultipleRenderTarget_po();

protected:
  virtual Texture* createTexture_po();
  virtual RenderTarget* createRenderTarget_po();

  void createDefaultSamplerStates_v();

  EffectFileSamplerStateBlockGL* defaultSamplerStates_po;

};

} // namespace me3d

#endif
