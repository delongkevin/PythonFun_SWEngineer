//--------------------------------------------------------------------------                                                                                                           
/// @file IRenderer.h                                                                         
/// @brief Renderer Interface
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef IRENDERER_H
#define IRENDERER_H

#include <platform/PlatformAPI.h>

namespace me3d
{

class RenderEngine;

class IRenderer
{
public:

  virtual ~IRenderer() {}

  // returns if the renderer is enabled
  virtual bool_t isEnabled_b() = 0;

  // create the renderer
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po) = 0;

  // release the renderer
  virtual void   release_v() = 0;

  // called if window is resized
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32) = 0;

  // Called first during a frame
  virtual void   beginFrame_v() = 0;

  // Reset renderer at the end of a frame
  virtual void   reset_v() = 0;
};

} // namespace me3d

#endif // IRENDERER_H
