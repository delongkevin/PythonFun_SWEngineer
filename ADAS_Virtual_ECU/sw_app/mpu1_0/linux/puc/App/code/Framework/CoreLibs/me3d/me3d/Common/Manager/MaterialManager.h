//--------------------------------------------------------------------------                                                                                                           
/// @file MaterialManager.h                                                                         
/// @brief Manages all available materials
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_MATERIAL_MANAGER_H
#define ME3D_MATERIAL_MANAGER_H

#include "IManager.h"

#include "Common/Materials/MaterialTypes.h"
#include "Utilities/GUIDGenerator.h"

#include "RenderEngineCfg.h"

namespace me3d
{
  class Material;
}

namespace me3d
{

class MaterialManager : public IManager
{
public:
  MaterialManager();
  virtual ~MaterialManager();

  // IManager interface
  virtual bool create_b(RenderEngine* b_RenderEngine_po);
  virtual bool_t isEnabled_b();
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();

  Material* createMaterial_po(const MEString& i_Name_ro);
  static Material* createMaterial_po(const MaterialDesc_s& i_Desc_rs);

  void releaseMaterial_v(Material* b_Material_po);


protected:
  RenderEngine*            renderEngine_po;
  std::vector<Material*>   materials_t;
};

} // namespace me3d

#endif // BUFFERMANAGER_H