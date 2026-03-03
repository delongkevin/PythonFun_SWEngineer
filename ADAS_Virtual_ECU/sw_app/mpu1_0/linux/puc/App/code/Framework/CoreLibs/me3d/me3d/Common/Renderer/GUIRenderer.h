//--------------------------------------------------------------------------                                                                                                           
/// @file GuiRenderer.h                                                                         
/// @brief Used to render Fonts and Textures via Orthogonal Projection
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GUI_RENDERER_H
#define GUI_RENDERER_H

#include "Common/Renderer/IRenderer.h"
#include "Common/Manager/ConstantsManager.h"

#include "MeclTypeDefs.h"

namespace me3d
{

class EffectFile;

class GUIRenderer : public IRenderer
{
public:
  GUIRenderer();
  virtual ~GUIRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  void render_v()const;

  void renderGuiObjects_v() const;
  void renderTexts_v() const;

private:
  RenderEngine* renderEngine_po;
  EffectFile*   effect_po;
  Constant*     constantGUITexture_po;
  Constant*     constantHasTexture_po;
  Constant*     constantColor_po;
};

} // namespace me3d

#endif
