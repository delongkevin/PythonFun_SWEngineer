//--------------------------------------------------------------------------                                                                                                           
/// @file RenderEngineGL.h                                                                         
/// @brief OpenGL RenderEngine implementation
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef RENDERENGINE_VK_H
#define RENDERENGINE_VK_H

#include "Common/RenderEngine.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

  class RenderEngineVK : public RenderEngine
  {
  public:
    RenderEngineVK();
    virtual ~RenderEngineVK();

    virtual Device3D* createDevice_po();

  protected:
    virtual IManager* createManager_po(ManagerType_e i_Type_e); 

  };

} // namespace me3d

#endif // RE_USE_VULKAN

#endif // RENDERENGINEGL_H
