//--------------------------------------------------------------------------                                                                                                           
/// @file RenderInterface.h                                                                         
/// @brief Render Functions provided by me3d library
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef RENDER_INTERFACE_H
#define RENDER_INTERFACE_H

#include "Common/Interfaces/RenderInterfaceTypes.h"
#include "Common/Interfaces/ModelInterface.h"
#include "Common/Interfaces/DebugInterface.h"
#include "Common/Interfaces/CameraInterface.h"
#include "Common/Interfaces/GuiInterface.h"
#include "Common/Interfaces/GuideLineInterface.h"
#include "Common/Interfaces/DeviceInterface.h"
#include "Common/Interfaces/DebugInterface.h"
#include "Common/Interfaces/LightInterface.h"
#include "Common/Interfaces/BowlViewInterface.h"
#include "Common/Interfaces/SingleViewInterface.h"
#include "Common/Interfaces/TextureInterface.h"
#include "Common/Interfaces/MaterialInterface.h"
#include "Common/RenderEngineTypes.h"

#if defined RE_USE_OPENGLES30
#include "OpenGLES30/RenderEngineGLES30.h"
#elif defined RE_USE_VULKAN
#include "Vulkan/RenderEngineVK.h"
#else 
#include "OpenGL/RenderEngineGL.h"
#endif        

#include "Utilities/GUIDGenerator.h"


namespace me3d
{
const uint32_t c_MaxLutSize_u32 = 128U;

class RenderInterface
{
public:
  static const uint32_t c_InvalidGUID_u32 = me3d::GUIDGenerator<>::c_InvalidGUID_u32;

public:
  RenderInterface();
  ~RenderInterface();

  bool create_b(const RenderEngineDesc_s& i_Desc_rs);
  void release_v();

  void msgBeginFrame_v(uint32_t i_RenderTargetId_u32 = c_InvalidGUID_u32);
  void msgEndFrame_v();

  void msgResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);

  ME_INLINE ModelInterface*       getModelInterface_po()       { return &modelInterface_o;        }
  ME_INLINE DebugInterface*       getDebugInterface_po()       { return &debugInterface_o;        }
  ME_INLINE CameraInterface*      getCameraInterface_po()      { return &cameraInterface_o;       }
  ME_INLINE GuiInterface*         getGuiInterface_po()         { return &guiInterface_o;          }
  ME_INLINE GuideLineInterface*   getGuideLineInterface_po()   { return &guideLineInterface_o;    }
  ME_INLINE DeviceInterface*      getDeviceInterface_po()      { return &deviceInterface_o;       }
  ME_INLINE LightInterface*       getLightInterface_po()       { return &lightInterface_o;        }
  ME_INLINE BowlViewInterface*    getBowlViewInterface_po()    { return &bowlViewInterface_o;     }
  ME_INLINE SingleViewInterface*  getSingleViewInterface_po()  { return &singleViewInterface_o;   }
  ME_INLINE TextureInterface*     getTextureInterface_po()     { return &textureInterface_o;      }
  ME_INLINE MaterialInterface*    getMaterialInterface_po()    { return &materialInterface_o;     }


  // --- CubeMap Interface --- TODO: GUids
  bool createCubeMap_b(const MEString& i_FileName_ro);

  // --- BowlView Interface --- TODO: GUids
  void BowlViewModifyHeight_v(float32_t i_X_f32, float32_t i_Z_f32, float32_t i_Height_f32, float32_t i_Radius_f32);

private:
  void  setAtID_v(uint32_t i_ID_u32, void* i_Object_pv, uint8_t i_Type_u8);
  void* getAtID_pv(uint32_t i_ID_u32, uint8_t i_Type_e)const;
  void* clearID_pv(uint32_t i_ID_u32, uint8_t i_Type_e);

private:
  GUIDGenerator<>     guidGenerator_o;
  ModelInterface      modelInterface_o;
  DebugInterface      debugInterface_o;
  CameraInterface     cameraInterface_o;
  GuiInterface        guiInterface_o;
  GuideLineInterface  guideLineInterface_o;
  DeviceInterface     deviceInterface_o;
  LightInterface      lightInterface_o;
  BowlViewInterface   bowlViewInterface_o;
  SingleViewInterface singleViewInterface_o;
  TextureInterface    textureInterface_o;
  MaterialInterface   materialInterface_o;

#if defined RE_USE_OPENGLES30
  RenderEngineGLES30  renderEngine_o;      
#elif defined RE_USE_VULKAN
  RenderEngineVK      renderEngine_o;  
#else 
  RenderEngineGL      renderEngine_o; 
#endif        

  uint8_t             typeLut_apu8[c_MaxLutSize_u32];
  void*               objectLut_apv[c_MaxLutSize_u32];

public:
  friend class ModelInterface;
  friend class CameraInterface;
  friend class GuiInterface;
  friend class GuideLineInterface;
  friend class DeviceInterface;
  friend class BowlViewInterface;
  friend class SingleViewInterface;
  friend class TextureInterface;
  friend class MaterialInterface;
};


} // namespace me3d

#endif
