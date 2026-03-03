//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFilePassGL.h                                                                         
/// @brief OpenGL EffectFilePass implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_PASS_GL_H
#define EFFECT_FILE_PASS_GL_H

#include "Common/Effect/EffectFilePass.h"

#include "OpenGL/GLIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class EffectFilePassGL : public EffectFilePass
{
public:
  EffectFilePassGL();
  virtual ~EffectFilePassGL();

  virtual void release_v();

  virtual bool create_b(EffectFileShader* i_Shaders_ap[], EffectFile* b_EffectFile_po);

  virtual bool begin_b();

  virtual void end_v();


  uint32_t getProgramID_u32() const;

private:
  GLuint programID_u32;
};


} // namespace me3d

#endif
