//--------------------------------------------------------------------------                                                                                                           
/// @file RenderEngineGLES30.h                                                                         
/// @brief OpenGL RenderEngine OpenGL ES 3.0 implementation
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifdef RE_USE_OPENGLES30

#ifndef RENDER_ENGINE_GLES30_H
#define RENDER_ENGINE_GLES30_H

#include "OpenGL/RenderEngineGL.h"


// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class IManager;

class RenderEngineGLES30 : public RenderEngineGL
{
public:
  RenderEngineGLES30();
  virtual ~RenderEngineGLES30();

protected:
  IManager* createManager_po(ManagerType_e i_Type_e);
};

} // namespace me3d


#endif // RENDERENGINE_GLES30_H

#endif // defined USE_OPENGL30
