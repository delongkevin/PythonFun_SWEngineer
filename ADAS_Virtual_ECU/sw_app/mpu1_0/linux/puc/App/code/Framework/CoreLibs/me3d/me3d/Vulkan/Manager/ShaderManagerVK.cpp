#include "ShaderManagerVK.h"

#include "OpenGL/Effect/EffectFilePassGL.h"

 

namespace me3d
{

ShaderManagerVK::ShaderManagerVK()
  : ShaderManager()
  , effectFilePassCnt_u32(0U)
  , effectFileShaderCnt_u32(0U)
  , effectFileDeclarationCnt_u32(0U)
  , effectFileCBcnt_u32(0U)
  , effectFileParserCnt_u32(0U)
  , effectFileRenderCnt_u32(0U)
{
}

ShaderManagerVK::~ShaderManagerVK()
{
}


void ShaderManagerVK::release_v()
{
  for (uint32_t v_I_u32 = 0; v_I_u32 < e_ShaderCount; ++v_I_u32)
  {
    effects_as[v_I_u32].effectFile_o.release_v();
  }
}

EffectFilePass* ShaderManagerVK::createPass_po()
{
  Assert(effectFilePassCnt_u32 < c_MaxEffectFilePasses_u32);

  EffectFilePass* v_Pass_po = &passPool_ao[effectFilePassCnt_u32];

  ++effectFilePassCnt_u32;

  return v_Pass_po;
}

EffectFileShader* ShaderManagerVK::createEffectFileShader_po()
{
  Assert(effectFileShaderCnt_u32 < c_MaxEffectFileShaders_u32);

  EffectFileShader* v_Shader_po = &shaderPool_ao[effectFileShaderCnt_u32];

  ++effectFileShaderCnt_u32;

  return v_Shader_po;
}

EffectFileVertexDeclaration* ShaderManagerVK::createVertexDeclaration_po()
{
  Assert(effectFileDeclarationCnt_u32 < c_MaxEffectFileDeclarations_u32);

  EffectFileVertexDeclarationGL* v_Declaration_po = &declarationPool_ao[effectFileDeclarationCnt_u32];

  ++effectFileDeclarationCnt_u32;

  return v_Declaration_po;
}

EffectFileConstantBlock* ShaderManagerVK::createConstantBlock_po()
{
  Assert(effectFileCBcnt_u32 < c_MaxEffectFileConstantBlocks_u32);

  EffectFileConstantBlockGL* v_Block_po = &constantBlockPool_ao[effectFileCBcnt_u32];

  ++effectFileCBcnt_u32;

  return v_Block_po;
}

EffectFileParser* ShaderManagerVK::createParser_po()
{
  Assert(effectFileParserCnt_u32 < e_ShaderCount);

  EffectFileParserGL* v_Parser_po = &parserPool_ao[effectFileParserCnt_u32];

  ++effectFileParserCnt_u32;

  return v_Parser_po;
}

EffectFileRenderStateBlock* ShaderManagerVK::createRenderStateBlock_po()
{
  Assert(effectFileRenderCnt_u32 < e_ShaderCount);

  EffectFileRenderStateBlockGL* v_RenderStateBlock_po = &renderStatePool_ao[effectFileRenderCnt_u32];

  ++effectFileRenderCnt_u32;

  return v_RenderStateBlock_po;
}

} // namespace me3d