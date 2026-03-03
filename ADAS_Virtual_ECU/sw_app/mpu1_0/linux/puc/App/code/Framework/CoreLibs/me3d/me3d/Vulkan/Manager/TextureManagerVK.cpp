#include "Vulkan/Manager/TextureManagerVK.h"


// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN


#include "Vulkan/Resources/TextureVK.h"
#include "OpenGL/Resources/RenderTargetGL.h"
#include "OpenGL/Resources/MultipleRenderTargetGL.h"
#include "OpenGL/Effect/EffectFileSamplerStateBlockGL.h"



// PRQA S 1051 EOF // Vulkan port still WIP
// PRQA S 5118 EOF // c++14 autosar standard permits

namespace me3d
{

TextureManagerVK::TextureManagerVK()
  : TextureManager()
  , defaultSamplerStates_po(NULL)
{
  
}

TextureManagerVK::~TextureManagerVK()
{

}

bool_t TextureManagerVK::create_b(RenderEngine* b_RenderEngine_po)
{
  bool_t v_Created_b = TextureManager::create_b(b_RenderEngine_po);
  
  if (true == v_Created_b)
  {
    createDefaultSamplerStates_v();
  }

  return v_Created_b;
}

// void TextureManagerVK::commitDefaultSamplerStates_v(GLenum i_TextureType_e , GLuint i_TextureId_u32)
// {
//   Assert(i_TextureId_u32 != 0);
//   Assert(NULL != defaultSamplerStates_po);
// 
//   if (NULL != defaultSamplerStates_po)
//   {
//     defaultSamplerStates_po->commitStates_v(i_TextureType_e, i_TextureId_u32);
//   }
// 
// }

Texture* TextureManagerVK::createTexture_po()
{
  // TODO VULKAN
  return new TextureVK();
}

RenderTarget* TextureManagerVK::createRenderTarget_po()
{
  // TODO VULKAN
  return new RenderTargetGL();
}

MultipleRenderTarget* TextureManagerVK::createMultipleRenderTarget_po()
{
  // TODO VULKAN
  return new MultipleRenderTargetGL();
}

void TextureManagerVK::createDefaultSamplerStates_v()
{
  if (NULL == defaultSamplerStates_po)
  {
    defaultSamplerStates_po = new EffectFileSamplerStateBlockGL();
  }

  defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstFilter, getRenderStateDefaultValue_s(e_EfstFilter)));
  defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstAddress, getRenderStateDefaultValue_s(e_EfstAddress)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstAddressU, getRenderStateDefaultValue_s(e_EfstAddressU)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstAddressV, getRenderStateDefaultValue_s(e_EfstAddressV)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstAddressW, getRenderStateDefaultValue_s(e_EfstAddressW)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstMaxAnisotropy, getRenderStateDefaultValue_s(e_EfstMaxAnisotropy)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstComparisonFunc, getRenderStateDefaultValue_s(e_EfstComparisonFunc)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstMipLodBias, getRenderStateDefaultValue_s(e_EfstMipLodBias)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstMinLod, getRenderStateDefaultValue_s(e_EfstMinLod)));
  //defaultSamplerStates_po->addState_b(EffectFileSamplerState_s(e_EfstMaxLod, getRenderStateDefaultValue_s(e_EfstMaxLod)));
}

} // namespace me3d

#endif // RE_USE_VULKAN