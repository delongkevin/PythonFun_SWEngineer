//--------------------------------------------------------------------------                                                                                                           
/// @file ShaderManagerVK.h                                                                         
/// @brief Vulkan ShaderManager implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef SHADERMANAGER_VK_H
#define SHADERMANAGER_VK_H

#include "OpenGL/Manager/ShaderManagerGL.h"
#include "OpenGL/Effect/EffectFilePassGL.h"
#include "OpenGL/Effect/EffectFileShaderGL.h"
#include "OpenGL/Effect/EffectFileVertexDeclarationGL.h"
#include "OpenGL/Effect/EffectFileConstantBlockGL.h"
#include "OpenGL/Effect/EffectFileParserGL.h"

// PRQA S 2128 EOF // Autosar c++14 standard permits

namespace me3d
{

class ShaderManagerVK : public ShaderManager
{
public:
  ShaderManagerVK();
  virtual ~ShaderManagerVK();

  virtual void release_v();

  virtual EffectFilePass*              createPass_po();
  virtual EffectFileShader*            createEffectFileShader_po();  
  virtual EffectFileVertexDeclaration* createVertexDeclaration_po();
  virtual EffectFileConstantBlock*     createConstantBlock_po();
  virtual EffectFileParser*            createParser_po();
  virtual EffectFileRenderStateBlock*  createRenderStateBlock_po();

private:
  uint32_t effectFilePassCnt_u32;
  uint32_t effectFileShaderCnt_u32;
  uint32_t effectFileDeclarationCnt_u32;
  uint32_t effectFileCBcnt_u32;
  uint32_t effectFileParserCnt_u32;
  uint32_t effectFileRenderCnt_u32;

  EffectFilePassGL              passPool_ao[c_MaxEffectFilePasses_u32];
  EffectFileShaderGL            shaderPool_ao[c_MaxEffectFileShaders_u32];
  EffectFileVertexDeclarationGL declarationPool_ao[c_MaxEffectFileDeclarations_u32];
  EffectFileConstantBlockGL     constantBlockPool_ao[c_MaxEffectFileConstantBlocks_u32];
  EffectFileRenderStateBlockGL  renderStatePool_ao[c_MaxEffectFileRenderBlocks_u32];
  EffectFileParserGL            parserPool_ao[e_ShaderCount];
};

} // namespace me3d

#endif