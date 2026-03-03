//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileVertexDeclarationGL.h                                                                         
/// @brief OpenGL EffectFileVertexDeclaration implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_VERTEX_DECLARATION_GL_H
#define EFFECT_FILE_VERTEX_DECLARATION_GL_H

#include "Common/Effect/EffectFileVertexDeclaration.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class EffectFilePassGL;

class EffectFileVertexDeclarationGL : public EffectFileVertexDeclaration
{
public: 
  EffectFileVertexDeclarationGL();
  virtual ~EffectFileVertexDeclarationGL();

  virtual void release_v();

  virtual bool create_b(EffectFilePass* b_Pass_po, EffectFile* b_Effect_po);

  // Update shader declaration depending on currently bound vertex buffer
  virtual bool set_b();

  virtual void reset_v();

private:
  EffectFilePassGL* pass_po;
};

} // namespace me3d

#endif
