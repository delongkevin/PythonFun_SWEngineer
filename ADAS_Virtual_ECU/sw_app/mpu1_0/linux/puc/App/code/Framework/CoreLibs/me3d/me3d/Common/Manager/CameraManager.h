//--------------------------------------------------------------------------                                                                                                           
/// @file CameraManager.h                                                                         
/// @brief Manages the current Camera and updates the Camera Constants
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef CAMERA_MANAGER_H
#define CAMERA_MANAGER_H

#include "Common/Manager/IManager.h"
#include "Common/Camera/Camera.h"
#include "Common/Resources/Constant.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

struct CameraConstants_s
{
  Constant* viewProj_po;
  Constant* view_po;
  Constant* proj_po;
  Constant* position_po;

  CameraConstants_s()
    : viewProj_po(NULL)
    , view_po(NULL)
    , proj_po(NULL)
    , position_po(NULL)
  {
  }

  void release_v()
  {
    viewProj_po = NULL;
    view_po     = NULL;
    proj_po     = NULL;
    position_po = NULL;
  }
};

class CameraManager : public IManager
{
public:
  CameraManager();
  virtual ~CameraManager();

  // IManager 
  virtual bool_t isEnabled_b(); 
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();

  inline Camera& getCamera_ro() { return camera_o; }

private:
  void updateConstants_v();



private:
  Camera camera_o;
  CameraConstants_s constants_s;
};

} // namespace me3d


#endif
