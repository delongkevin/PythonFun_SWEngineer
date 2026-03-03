#include "Common/Effect/EffectFilePass.h"

#include "Common/Effect/EffectFile.h"
#include "Common/Effect/EffectFileShader.h"
#include "Common/Effect/EffectFileVertexDeclaration.h"
#include "Common/Effect/EffectFileConstantBlock.h"

#include "Common/RenderEngine.h"
#include "Common/Manager/ShaderManager.h"

#include <platform/PlatformAPI.h>
 

namespace me3d
{

EffectFilePass::EffectFilePass()
  : vertexDeclaration_po(NULL)
  , constantBlock_po(NULL)
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_EftCount; ++v_I_u32)
  {
    shaders_apo[v_I_u32] = NULL;
  }
}

EffectFilePass::~EffectFilePass()
{

}

void EffectFilePass::release_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_EftCount; ++v_I_u32)
  {
    shaders_apo[v_I_u32] = NULL;
  }

  if (NULL != vertexDeclaration_po)
  {
    vertexDeclaration_po->release_v();
    vertexDeclaration_po = NULL;
  }

  if (NULL != constantBlock_po)
  {
    constantBlock_po->release_v();
    constantBlock_po = NULL;
  }
}

bool EffectFilePass::create_b(EffectFileShader* i_Shaders_ap[/*e_EFT_Count*/], EffectFile* b_EffectFile_po)
{
  bool v_Success_b = false;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < e_EftCount; ++v_I_u32)
  {
    // PRQA S 3706 1 // subscript operator ensured by enum e_EftCount
    shaders_apo[v_I_u32] = i_Shaders_ap[v_I_u32];

    if (shaders_apo[v_I_u32])
    {
      EffectFileType_e v_EffectFileType_e = static_cast<EffectFileType_e>(v_I_u32);
      v_Success_b = shaders_apo[v_I_u32]->compile_b(b_EffectFile_po->getSourceCode_pc(v_EffectFileType_e), v_EffectFileType_e);
      Assert(v_Success_b);
    }
  }

  if (NULL == constantBlock_po)
  {
    constantBlock_po = b_EffectFile_po->getRenderEngine_po()->getShaderManager_po()->createConstantBlock_po();
  }

  if (NULL == vertexDeclaration_po)
  {
    vertexDeclaration_po = b_EffectFile_po->getRenderEngine_po()->getShaderManager_po()->createVertexDeclaration_po();
  }

  v_Success_b = vertexDeclaration_po->create_b(this, b_EffectFile_po);
  Assert(v_Success_b);

  if (true == v_Success_b)
  {
    v_Success_b = constantBlock_po->create_v(this, b_EffectFile_po);
    Assert(v_Success_b);
  }

  return v_Success_b;
}

bool EffectFilePass::begin_b()
{
  Assert(vertexDeclaration_po);
  Assert(constantBlock_po);
  Assert(shaders_apo[e_EftVertex]);
  Assert(shaders_apo[e_EftPixel]);

  // Bind Resources and Commit constants
  constantBlock_po->commit_v();
  
  // Update Vertex Declaration
  bool v_Success_b = vertexDeclaration_po->set_b();
  Assert(v_Success_b);

  return v_Success_b;
}

void EffectFilePass::end_v()
{
  if (NULL != vertexDeclaration_po)
  {
    vertexDeclaration_po->reset_v();
  }
}

} // namespace me3d