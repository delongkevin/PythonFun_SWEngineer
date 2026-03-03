//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileShader.h                                                                         
/// @brief Represents a Vertex, Pixel or Geometry Shader
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECTFILE_SHADER_H 
#define EFFECTFILE_SHADER_H

#include "EffectFileTypes.h"

// PRQA S 2127 EOF // virtual function overload used here by design.

namespace me3d
{

class EffectFileShader
{
public:
  EffectFileShader();
  virtual ~EffectFileShader();

  virtual void release_v();

  virtual bool compile_b(const char* i_ShaderSource_pc, EffectFileType_e i_EffectFileType_e);


private:
  EffectFileType_e  effectFileType_e;
};

} // namespace me3d

#endif
