//--------------------------------------------------------------------------                                                                                                           
/// @file GuiTypes.h                                                                         
/// @brief Types used by GuiManager / Renderer
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef ME3D_GUI_TYPES_H
#define ME3D_GUI_TYPES_H

#include <platform/PlatformAPI.h>
#include "MeclTypeDefs.h"
#include "Math/Color.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{
  class ITextureConstantData;

  struct GuiObjectDesc_s
  {
    Vector2f  bottomLeft_o;
    Vector2f  bottomRight_o;
    Vector2f  topLeft_o;
    Vector2f  topRight_o;
    MEString  texture_o;
    Color     color_o;    
    float32_t depth_f32;
    ITextureConstantData* textureData_po;

    GuiObjectDesc_s()
      : bottomLeft_o()
      , bottomRight_o()
      , topLeft_o()
      , topRight_o()
      , texture_o("")
      , color_o(Color::White)
      , depth_f32(0.0F)
      , textureData_po(NULL)
    {
    }
  };

  struct GuiObject_s
  {
    GuiObjectDesc_s       desc_s;
    bool                  used_b;                 // don't touch this
    ITextureConstantData* texture_po;

    GuiObject_s()
      : desc_s()
      , used_b(false)
      , texture_po(NULL)
    {
    }
  };

  struct TextObject_s
  {
    Vector4f    color_o;
    Vector2f    scale_o;
    Vector3f    pos_o;
    const char* c_Text_pc;
    bool        used_b;   // don't touch this

    TextObject_s()
      : color_o()
      , scale_o()
      , pos_o()
      , c_Text_pc(NULL)
      , used_b(false)
    {
    }
  };

  const uint32_t c_NumQuadVertices_u32 = 4U; // 4 vertices define the quad


} // namespace me3d

#endif // ME3D_GUI_TYPES_H