//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileParserGL.h                                                                         
/// @brief OpenGL EffectFileParser implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_PARSER_GL_H
#define EFFECT_FILE_PARSER_GL_H

#include "Common/Effect/EffectFileParser.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class EffectFileParserGL : public EffectFileParser
{
public:
  EffectFileParserGL();
  virtual ~EffectFileParserGL();

  virtual bool onParseAttributes_b();
};

} // namespace me3d

#endif
