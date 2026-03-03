//--------------------------------------------------------------------------                                                                                                           
/// @file ViewRenderer.h                                                                         
/// @brief Used to render Views
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef VIEW_RENDERER_H
#define VIEW_RENDERER_H

#include "Common/Renderer/IRenderer.h"
#include "Common/Resources/Constant.h"
#include "Common/View/BowlView.h"

namespace me3d
{

class EffectFile;

class ViewRenderer : public IRenderer
{
public:
  ViewRenderer();
  virtual ~ViewRenderer();

  // IRenderer
  virtual bool_t isEnabled_b();
  virtual bool   create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   reset_v();

  void renderAll_v()const;

private:
  RenderEngine* renderEngine_po;
};

} // namespace me3d

#endif
