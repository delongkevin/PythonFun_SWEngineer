//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFilePass.h                                                                         
/// @brief Creates and links EffectFileShaders (Vertex, Pixel and maybe in future Geometry Shaders)
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_PASS_H
#define EFFECT_FILE_PASS_H

#include "Common/Effect/EffectFileTypes.h"

// PRQA S 2101 EOF // protected members used here by design
// PRQA S 2127 EOF // virtual function overload used here by design.

namespace me3d
{

class EffectFile;
class EffectFileShader;
class EffectFileVertexDeclaration;
class EffectFileConstantBlock;

class EffectFilePass
{
public:
  EffectFilePass();
  virtual ~EffectFilePass();

  virtual void release_v();
  virtual bool create_b(EffectFileShader* i_Shaders_ap[/*e_EFT_Count*/], EffectFile* b_EffectFile_po);

  virtual bool begin_b();
  virtual void end_v();

protected:
  EffectFileShader*            shaders_apo[e_EftCount];
  EffectFileVertexDeclaration* vertexDeclaration_po;
  EffectFileConstantBlock*     constantBlock_po;
};

} // namespace me3d

#endif
