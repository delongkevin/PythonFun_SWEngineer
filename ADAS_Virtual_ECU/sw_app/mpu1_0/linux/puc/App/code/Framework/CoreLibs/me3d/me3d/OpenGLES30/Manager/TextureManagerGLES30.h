//--------------------------------------------------------------------------                                                                                                           
/// @file TextureManagerGLES30.h                                                                         
/// @brief OpenGL TextureManager OpenGL ES 3.0 implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifdef RE_USE_OPENGLES30

#ifndef TEXTUREMANAGER_GLES30_H
#define TEXTUREMANAGER_GLES30_H

#include "OpenGL/Manager/TextureManagerGL.h"

namespace me3d
{

class Texture;
class RenderTarget;
class MultipleRenderTarget;

class TextureManagerGLES30 : public TextureManagerGL
{
public:
  TextureManagerGLES30();
  virtual ~TextureManagerGLES30();

protected:
  virtual Texture* createTexture_po();
};

} // namespace me3d

#endif // TEXTUREMANAGER_GLES30_H

#endif // RE_USE_OPENGLES30
