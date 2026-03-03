//--------------------------------------------------------------------------                                                                                                           
/// @file GUIManager.h                                                                         
/// @brief Manages GUIObjects and Fonts
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include "Common/Manager/IManager.h"

#include "RenderEngineCfg.h"

#include "Common/GUI/Font.h"
#include "Common/GUI/GuiTypes.h"

// PRQA S 2100 EOF // public members used here by design.
// PRQA S 2128 EOF // Autosar c++14 standard permits.

namespace me3d
{

class VertexBuffer;
class Texture;
struct VertexPosTex_s;


class GUIManager : public IManager
{
public:
  GUIManager();
  virtual ~GUIManager();

  // IManager
  virtual bool_t isEnabled_b(); 
  virtual bool_t create_b(RenderEngine* b_RenderEngine_po);
  virtual void   release_v();
  virtual void   onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
  virtual void   beginFrame_v();
  virtual void   preRender_v();
  virtual void   reset_v();


  void          createFont_v(const MEString& i_FileName_ro);
  TextObject_s* addText_ps(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro);
  static void          removeText_v(TextObject_s* b_TextObject_ps);
  TextObject_s* getText_po(uint32_t i_Index_u32);
  Font*         getFont_po();

  GuiObject_s*  addGuiObject_ps(const GuiObjectDesc_s& i_Desc_rs);
  static void   removeGuiObject_v(const GuiObject_s* b_GuiObject_ps);
  GuiObject_s*  getGuiObject_ps(uint32_t i_Index_u32);

  VertexBuffer* getVertexBuffer_po() const;

protected:
  static void getVertices_v(const GuiObject_s* i_GuiObject_ps, VertexPosTex_s* b_Vertices_ps);

private:
  RenderEngine* renderEngine_po;
  VertexBuffer* vertexBuffer_po;
  Font          font_o;

  GuiObject_s*  guiObjectsRenderList[c_MaxGuiObjects_u32];
  GuiObject_s   guiObjects_as[c_MaxGuiObjects_u32];
  TextObject_s  textObjects_as[c_MaxTextObjects_u32];
};

} // namespace me3d

#endif // GUI_MANAGER_H
