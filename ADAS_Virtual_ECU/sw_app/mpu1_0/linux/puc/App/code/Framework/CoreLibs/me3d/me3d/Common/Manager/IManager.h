//--------------------------------------------------------------------------                                                                                                           
/// @file IManager.h                                                                         
/// @brief Manager Interface
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2127 EOF // Introducing virtual function without the pure specifier is intended here, no every manager needs reset, endscene and begin scene

#ifndef IMANAGER_H
#define IMANAGER_H

#include <platform/PlatformAPI.h>

namespace me3d
{

class RenderEngine;

class IManager
{
public:
  virtual ~IManager() {}

  // Returns true if the manager is enabled
  virtual bool_t isEnabled_b() = 0;

  // create the manager
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po) = 0;
  
  // release the manager
  virtual void   release_v() = 0;

  // called when window is resized
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32) = 0;
  
  // Called first in a frame
  virtual void   beginFrame_v() = 0;

  // Called before rendering of the renderer 
  virtual void   preRender_v() = 0;

  /// Reset manager at the end of a frame
  virtual void reset_v() {}

  /// Start rendering into a pre-render target, return false if no pre render target is needed
  virtual bool_t beginScene_b() { return false; }

  /// End rendering into a pre-render target
  virtual void endScene_v() {}
};

} // namespace me3d

#endif // IMANAGER_H
