//--------------------------------------------------------------------------                                                                                                           
/// @file LightManager.h                                                                         
/// @brief Manages the one and only Point Light (for now) and updates the Constants
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef LIGHT_MANAGER_H
#define LIGHT_MANAGER_H

#include "Common/Manager/IManager.h"
#include "Common/Resources/Constant.h"
#include "MeclTypeDefs.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{
  class Color;
}

namespace me3d
{

struct LightConstants_s
{
  Constant* ambient_po;
  Constant* diffuse_po;
  Constant* specular_po;
  Constant* position_po;

  LightConstants_s()
    : ambient_po(NULL)
    , diffuse_po(NULL)
    , specular_po(NULL)
    , position_po(NULL)
  {
  }
};

class LightManager : public IManager
{
public:
  LightManager();
  virtual ~LightManager();

  // IManager
  virtual bool_t isEnabled_b(); 
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();

  void setAmbientColor_v(const Color& i_Color_ro) const;
  void setDiffuseColor_v(const Color& i_Color_ro) const;
  void setSpecularColor_v(const Color& i_Color_ro) const;
  void setLightPos_v(const Vector3f& i_LightPos_ro) const;

  Color getAmbientColor_o() const;
  Color getDiffuseColor_o() const;
  Color getSpecularColor_o() const;

private:
  RenderEngine*    renderEngine_po;
  LightConstants_s lightConstants_s;

};

} // namespace me3d

#endif
