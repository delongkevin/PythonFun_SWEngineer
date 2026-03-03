//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileShaderGL.h                                                                         
/// @brief OpenGL EffectFileShader implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECTFILE_SHADER_GL_H 
#define EFFECTFILE_SHADER_GL_H

#include "Common/Effect/EffectFileShader.h"
#include "OpenGL/GLIncludes.h"


// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class EffectFileShaderGL : public EffectFileShader
{
public:
  EffectFileShaderGL();
  virtual ~EffectFileShaderGL();

  virtual void release_v();

  virtual bool compile_b(const char* i_ShaderSource_pc, EffectFileType_e i_EffectFileType_e);
  
  GLuint getShaderID_u32() const;

private:
  GLuint shaderID_u32;
};

}

#endif
