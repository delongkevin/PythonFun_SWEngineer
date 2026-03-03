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

#ifndef RENDERENGINEGL_H
#define RENDERENGINEGL_H

#include "Common/RenderEngine.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

class RenderEngineGL : public RenderEngine
{
public:
  RenderEngineGL();
  virtual ~RenderEngineGL();

  virtual Device3D* createDevice_po();

protected:
  virtual IManager* createManager_po(ManagerType_e i_Type_e); 

};

} // namespace me3d


#endif // RENDERENGINEGL_H
