//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileVertexDeclaration.h                                                                         
/// @brief Upload shader declaration to GPU depending on currently bound vertex buffer
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_VERTEX_DECLARATION_H
#define EFFECT_FILE_VERTEX_DECLARATION_H

// PRQA S 2101 EOF // protected members used here by design.
// PRQA S 2127 EOF // virtual function overload used here by design.

namespace me3d
{

class EffectFile;
class EffectFilePass;

class EffectFileVertexDeclaration
{
public: 
  EffectFileVertexDeclaration();
  virtual ~EffectFileVertexDeclaration();

  virtual void release_v();

  virtual bool create_b(EffectFilePass* b_Pass_po, EffectFile* b_Effect_po);

  // Update shader declaration depending on currently bound vertex buffer
  virtual bool set_b() = 0;

  virtual void reset_v() = 0;

protected:
  EffectFile* effectFile_po;
};

} // namespace me3d

#endif
