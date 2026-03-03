//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileConstantBlockGL.h                                                                         
/// @brief OpenGL EffectFileConstantBlock implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2100 EOF // public members used here by design.

#ifndef EFFECT_FILE_CONSTANT_BLOCK_GL_H 
#define EFFECT_FILE_CONSTANT_BLOCK_GL_H

#include "Common/Effect/EffectFileConstantBlock.h"
#include "OpenGL/GLIncludes.h"

namespace me3d
{

class EffectFileConstantBlockGL : public EffectFileConstantBlock
{
public:
  EffectFileConstantBlockGL();
  virtual ~EffectFileConstantBlockGL();

  virtual void release_v();

  virtual bool initialize_b(EffectFilePass* b_Pass_po, EffectFile* b_EffectFile_po);

  virtual void commit_v();


private:
  GLuint programID_u32;
};

} // namespace me3d

#endif
