//--------------------------------------------------------------------------                                                                                                           
/// @file GuideLineRenderer.h                                                                         
/// @brief Used to render guidelines which were defined by GuideLineManager
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GUIDE_LINE_RENDERER_H
#define GUIDE_LINE_RENDERER_H

#include "Common/Renderer/IRenderer.h"
#include "Common/Manager/ConstantsManager.h"

#include "MeclTypeDefs.h"

namespace me3d
{

class EffectFile;
class EffectFileRenderStateBlock;

class GuideLineRenderer : public IRenderer
{
public:
  GuideLineRenderer();
  virtual ~GuideLineRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  void renderAll_v() const;

private:
  RenderEngine*                 renderEngine_po;
  EffectFile*                   effect_po;
  EffectFileRenderStateBlock*   renderStateBlock_po;

  Constant*                     constantGuideLineWVP_po;
  Constant*                     constantColor_po;
};

} // namespace me3d

#endif //SVG_RENDERER_H
