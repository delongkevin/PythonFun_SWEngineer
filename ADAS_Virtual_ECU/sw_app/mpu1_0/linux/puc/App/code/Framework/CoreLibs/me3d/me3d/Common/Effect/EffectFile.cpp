#include "EffectFile.h"

#include <osal/io/File.h>
 
#include "Common/RenderEngine.h"
#include "Common/Effect/EffectFilePass.h"
#include "Common/Effect/EffectFileShader.h"
#include "Common/Effect/EffectFileParser.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"

// PRQA S 3710 EOF // Flag handling, I'm aware of it

namespace me3d
{

EffectFile::EffectFile()
  : renderEngine_po(NULL)
  , pass_po(NULL)
  , parser_po(NULL)
  , renderStateBlock_po(NULL)
{
  for (uint32_t v_i_u32 = 0U; v_i_u32 < e_EftCount; ++v_i_u32)
  {
    c_SourceCodes_apc[v_i_u32] = NULL;
    shaders_apo[v_i_u32]       = NULL;
  }
}

EffectFile::~EffectFile()
{
  // PRQA S 4631 1 // This function doesn't throw any exceptions
  release_v();
}

bool EffectFile::create_b(RenderEngine* i_RenderEngine_po, const MEString& i_FileName_ro)
{
  bool v_Success_b = false;

  MEString v_VsFileName_o = i_FileName_ro;
  v_VsFileName_o += ".vp";

  osal::File vertexShaderFile_o;
  v_Success_b = vertexShaderFile_o.open_b(v_VsFileName_o.getString_pc(), e_FomRead | e_FomBinary);
  Assert(true == v_Success_b);

  if (true == v_Success_b)
  {
    MEString v_PsFileName_o = i_FileName_ro;
    v_PsFileName_o += ".fp";

    osal::File pixelShaderFile_o;
    v_Success_b = pixelShaderFile_o.open_b(v_PsFileName_o.getString_pc(), e_FomRead | e_FomBinary);
    Assert(true == v_Success_b);

    if (true == v_Success_b)
    {
      char v_VsBuffer_ac[c_MaxEffectFileLength_u32];
      uint64_t v_VsLength_u64 = vertexShaderFile_o.getSize_u64();
      vertexShaderFile_o.read_u64(v_VsBuffer_ac, v_VsLength_u64);
      v_VsBuffer_ac[v_VsLength_u64] = '\0';

      char v_PsBuffer_ac[c_MaxEffectFileLength_u32];
      uint64_t v_PsLength_u64 = static_cast<uint32_t>(pixelShaderFile_o.getSize_u64());
      pixelShaderFile_o.read_u64(v_PsBuffer_ac, v_PsLength_u64);
      v_PsBuffer_ac[v_PsLength_u64] = '\0';

      v_Success_b = create_b(i_RenderEngine_po, &v_VsBuffer_ac[0], &v_PsBuffer_ac[0]);
      Assert(true == v_Success_b);

      vertexShaderFile_o.close_b();
      pixelShaderFile_o.close_b();

    }
  }

  return v_Success_b;
}

bool EffectFile::create_b(RenderEngine* i_RenderEngine_po, const char* i_VertexShaderSrc_pc, const char* i_PixelShaderSrc_pc)
{
  renderEngine_po = i_RenderEngine_po;

  if (NULL == parser_po)
  {
    parser_po = renderEngine_po->getShaderManager_po()->createParser_po();
  }
  parser_po->create_b(i_RenderEngine_po, i_VertexShaderSrc_pc, i_PixelShaderSrc_pc);

  c_SourceCodes_apc[e_EftVertex] = parser_po->getSourceCode_pc(e_EftVertex);
  c_SourceCodes_apc[e_EftPixel]  = parser_po->getSourceCode_pc(e_EftPixel);

  // Create Shaders
  for (uint32_t v_i_u32 = 0U; v_i_u32 < e_EftCount; ++v_i_u32)
  {
    if (NULL == shaders_apo[v_i_u32])
    {
      shaders_apo[v_i_u32] = renderEngine_po->getShaderManager_po()->createEffectFileShader_po();
    }
  }

  // Create pass
  if (NULL == pass_po)
  {
    pass_po = renderEngine_po->getShaderManager_po()->createPass_po();
  }

  bool v_Success_b = pass_po->create_b(&shaders_apo[0], this);

  return v_Success_b;
}

void EffectFile::release_v()
{
  if (NULL != pass_po)
  {
    pass_po->release_v();
    pass_po = NULL;
  }

  // release all shaders, this is used in dynamic reload
  for (uint32_t v_i_u32 = 0U; v_i_u32 < e_EftCount; ++v_i_u32)
  {
    EffectFileShader* v_Shader_po = shaders_apo[v_i_u32];
    if (NULL != v_Shader_po)
    {
      v_Shader_po->release_v();
    }
  }
}

void EffectFile::setRenderStateBlock_v(EffectFileRenderStateBlock* b_RenderStateBlock_po)
{
  renderStateBlock_po = b_RenderStateBlock_po;
}

bool EffectFile::beginPass_b() const
{
  if (NULL != renderStateBlock_po)
  {
    renderStateBlock_po->commit_v(NULL);
  }


  bool v_Success_b = pass_po->begin_b();
  Assert(v_Success_b);

  return v_Success_b;
}

void EffectFile::endPass_v() const
{
  pass_po->end_v();

  if (NULL != renderStateBlock_po)
  {
    renderStateBlock_po->restoreChangedStates_v();
  }

}

const char* EffectFile::getSourceCode_pc(EffectFileType_e i_EffectFileType_e) const
{
  return c_SourceCodes_apc[i_EffectFileType_e];
}

} // namespace me3d