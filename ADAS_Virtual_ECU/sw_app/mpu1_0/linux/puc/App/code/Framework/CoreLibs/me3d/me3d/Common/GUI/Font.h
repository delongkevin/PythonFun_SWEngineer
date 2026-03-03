//--------------------------------------------------------------------------                                                                                                           
/// @file Font.h                                                                         
/// @brief TODO: Rework
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef FONT_H
#define FONT_H

#include "MeclTypeDefs.h"
#include "Common/GUI/FontTypes.h"
#include "Common/Resources/Constant.h"

namespace me3d
{

class VertexBuffer;
class EffectFile;
class Texture;
class ITextureConstantData;
class RenderEngine;

class Font
{
public: 
  Font();
  ~Font();

  void create_v(const MEString& i_FileName_ro, RenderEngine* i_RenderEngine_po);
  void release_v();

  void render_v(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro);

private:
  RenderEngine*  renderEngine_po;
  FontData_s     fontData_s;
  VertexBuffer*  vertexBuffer_po;
  EffectFile*    effect_po;
  Texture*       texture_po;
  Constant*      textureConstant_po;
  Constant*      colorConstant_po;
};

} // namespace me3d

#endif
