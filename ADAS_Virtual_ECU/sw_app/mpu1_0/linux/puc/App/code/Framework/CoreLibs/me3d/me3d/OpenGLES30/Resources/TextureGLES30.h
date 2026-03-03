//--------------------------------------------------------------------------                                                                                                           
/// @file TextureGL.h                                                                         
/// @brief OpenGL Texture implementation  
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

#ifndef TEXTURE_GLES30_H
#define TEXTURE_GLES30_H

#include "OpenGL/Resources/TextureGL.h"
#include "OpenGL/GLIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{
  class TextureGLES30 : public TextureGL
  {
  public:
    TextureGLES30();
    virtual ~TextureGLES30();

    virtual void updateSubData_v(const uint8_t* i_Data_pv);
  };

} // namespace me3d

#endif // TEXTURE_GLES30_H

#endif // RE_USE_OPENGLES30