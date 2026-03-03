//--------------------------------------------------------------------------                                                                                                           
/// @file ModelRenderer.h                                                                         
/// @brief Used to render Models
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "MeclTypeDefs.h"
#include "Common/Renderer/IRenderer.h"
#include "Common/Resources/Constant.h"
#include "RenderEngineCfg.h"

namespace me3d
{
  class ITextureConstantData;
  class EffectFile;
  class EffectFileRenderStateBlock;
}

namespace me3d
{

class ModelRenderer : public IRenderer
{
public:
  ModelRenderer();
  virtual ~ModelRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  void renderDefault_v()const;
  void renderTransparent_v()const;

  void renderModels_v(bool i_Transparent_b) const;

private:
  RenderEngine*                 renderEngine_po;
  EffectFileRenderStateBlock*   renderStateBlock_po;
  Constant*                     constantWVP_po;
  Constant*                     constantWorld_po;
  Constant*                     constantWorldInverse_po;
  Constant*                     materialAmbient_po;
  Constant*                     materialDiffuse_po;
  Constant*                     materialSpecular_po;
  Constant*                     materialOpacity_po;
  Constant*                     materialShininess_po;
  Constant*                     materialMetallic_po;
  Constant*                     materialAlbedoTex_po;
  Constant*                     materialNormalex_po;
  Constant*                     materialMetallicTex_po;
  Constant*                     materialRoughnessTex_po;
  Constant*                     materialAoTex_po;
  Constant*                     constantBones_po;

};

} // namespace me3d

#endif
