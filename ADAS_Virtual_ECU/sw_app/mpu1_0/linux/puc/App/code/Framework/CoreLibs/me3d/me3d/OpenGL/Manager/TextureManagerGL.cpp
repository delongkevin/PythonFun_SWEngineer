#include "OpenGL/Manager/TextureManagerGL.h"

#include "OpenGL/Resources/TextureGL.h"
#include "OpenGL/Resources/RenderTargetGL.h"
#include "OpenGL/Resources/MultipleRenderTargetGL.h"

#include "OpenGL/Effect/EffectFileSamplerStateBlockGL.h"


// PRQA S 5118 EOF // C++ 14 Autosar standard permits

namespace me3d
{

TextureManagerGL::TextureManagerGL()
  : TextureManager()
  , defaultSamplerStates_po(NULL)
{
  
}

TextureManagerGL::~TextureManagerGL()
{

}

bool_t TextureManagerGL::create_b(RenderEngine* b_RenderEngine_po)
{
  bool_t v_Created_b = TextureManager::create_b(b_RenderEngine_po);
  
  if (true == v_Created_b)
  {
    createDefaultSamplerStates_v();
  }

  return v_Created_b;
}

void TextureManagerGL::commitDefaultSamplerStates_v(GLenum i_TextureType_e , GLuint i_TextureId_u32)const
{
  Assert(i_TextureId_u32 != 0);
  Assert(NULL != defaultSamplerStates_po);

  if (NULL != defaultSamplerStates_po)
  {
    defaultSamplerStates_po->commitStates_v(i_TextureType_e, i_TextureId_u32);
  }

}

Texture* TextureManagerGL::createTexture_po()
{
  return new TextureGL();
}

RenderTarget* TextureManagerGL::createRenderTarget_po()
{
  return new RenderTargetGL();
}

MultipleRenderTarget* TextureManagerGL::createMultipleRenderTarget_po()
{
  return new MultipleRenderTargetGL();
}

void TextureManagerGL::createDefaultSamplerStates_v()
{
  if (NULL == defaultSamplerStates_po)
  {
    defaultSamplerStates_po = new EffectFileSamplerStateBlockGL();
  }

  defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstFilter, getRenderStateDefaultValue_s(e_EfstFilter)));
  defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstAddress, getRenderStateDefaultValue_s(e_EfstAddress)));
 
}

} // namespace me3d
