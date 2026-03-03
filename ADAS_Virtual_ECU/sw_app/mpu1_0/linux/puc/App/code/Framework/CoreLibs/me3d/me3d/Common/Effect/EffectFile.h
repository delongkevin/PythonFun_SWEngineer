//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFile.h                                                                         
/// @brief Represents a Shader file
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_H 
#define EFFECT_FILE_H

#include "MeclTypeDefs.h"
#include "EffectFileTypes.h"

#include <platform/PlatformAPI.h>

namespace me3d
{

class RenderEngine;
class EffectFilePass;
class EffectFileShader;
class EffectFileParser;
class EffectFileRenderStateBlock;

class EffectFile
{
public:
  EffectFile();
  ~EffectFile();

  bool create_b(RenderEngine* i_RenderEngine_po, const MEString& i_FileName_ro);
  bool create_b(RenderEngine* i_RenderEngine_po, const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc);
  void release_v();

  void setRenderStateBlock_v(EffectFileRenderStateBlock* b_RenderStateBlock_po);

  bool beginPass_b() const;

  // end the current pass and restore changed states, etc
  void endPass_v() const;

  const char* getSourceCode_pc(EffectFileType_e i_EffectFileType_e) const;

  inline const EffectFileParser* getParser_po() const { Assert(parser_po); return parser_po; }

  inline RenderEngine* getRenderEngine_po() const { return renderEngine_po; }

private:
  RenderEngine*                 renderEngine_po;
  EffectFilePass*               pass_po;
  EffectFileParser*             parser_po;
  EffectFileRenderStateBlock*   renderStateBlock_po;
  const char*                   c_SourceCodes_apc[e_EftCount];
  EffectFileShader*             shaders_apo[e_EftCount]; 
};

} // namespace me3d

#endif
