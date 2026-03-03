//--------------------------------------------------------------------------                                                                                                           
/// @file ShaderTypesGL.h                                                                         
/// @brief Maps OpenGL Specific enumerations to me3d enumerations
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef SHADER_TYPES_GL_H
#define SHADER_TYPES_GL_H

#include "Common/Effect/EffectFileTypes.h"

// PRQA S 1067 EOF // Intended here Implemented in Header for better readability/accessibility.

namespace me3d
{

  GLenum getFormatGLType_e(ShaderSemanticFormat_e i_Format_e)
  {
    GLenum v_FormatGL_e = GL_FALSE;

    switch(i_Format_e)
    {
    case e_SsfFloat1 : { v_FormatGL_e = GL_FLOAT;          break; }
    case e_SsfFloat2 : { v_FormatGL_e = GL_FLOAT;          break; }
    case e_SsfFloat3 : { v_FormatGL_e = GL_FLOAT;          break; }
    case e_SsfFloat4 : { v_FormatGL_e = GL_FLOAT;          break; }
    case e_SsfUint   : { v_FormatGL_e = GL_UNSIGNED_BYTE;  break; }
    case e_SsfCount  : { Assert(false);                    break; }
    default           : { Assert(false);                    break; }
    }

    Assert(v_FormatGL_e != GL_FALSE);
    return v_FormatGL_e;
  }
  
  GLboolean getFormatGLNormalized_b(ShaderSemanticFormat_e i_Format_e)
  {
    GLboolean v_Normalized_b = GL_FALSE;

    switch(i_Format_e)
    {
    case e_SsfFloat1 : { v_Normalized_b = GL_FALSE;          break; }
    case e_SsfFloat2 : { v_Normalized_b = GL_FALSE;          break; }
    case e_SsfFloat3 : { v_Normalized_b = GL_FALSE;          break; }
    case e_SsfFloat4 : { v_Normalized_b = GL_FALSE;          break; }
    case e_SsfUint   : { v_Normalized_b = GL_TRUE;           break; }
    case e_SsfCount  : { Assert(false);                      break; }
    default           : { Assert(false);                      break; }
    }

    return v_Normalized_b;
  }

} // namespace me3d

#endif
