//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFile.h                                                                         
/// @brief Used to get Attributes and define their locations in the vertex shader source code
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_PARSER_H
#define EFFECT_FILE_PARSER_H

#include "Common/Effect/EffectFileTypes.h"
#include "Common/Manager/ShaderManager.h"
#include "RenderEngineCfg.h"

// PRQA S 2101 EOF // protected members used here by design
// PRQA S 2127 EOF // virtual function overload used here by design.

namespace me3d
{
  class RenderEngine;

  class EffectFileParser
  {
  public:
    EffectFileParser();
    virtual ~EffectFileParser();

    virtual bool create_b(RenderEngine* b_RenderEngine_po, const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc);

    virtual bool onParseAttributes_b() = 0;

    const ShaderInput_s* getAttributes_ps() const;

    const char* getSourceCode_pc(EffectFileType_e i_EffectFileType_e) const;


  protected:
    bool parseIncludes_b(const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc);

    bool parseIncludes_b(char* b_SourceCode_pc, ShaderInclude_s* b_Includes_aps[e_SiCount])const;

  protected:
    ShaderInput_s     attributes_s;
    RenderEngine*     renderEngine_po;
    ShaderInclude_s*  vertexIncludes_aps[e_SiCount];
    ShaderInclude_s*  pixelIncludes_aps[e_SiCount];
    char              vertexShaderSrc_ac[c_MaxEffectFileLength_u32];
    char              pixelShaderSrc_ac[c_MaxEffectFileLength_u32];
  };

} // namespace me3d

#endif
