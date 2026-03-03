#include "Common/Manager/GUIManager.h"

#include "Common/RenderEngine.h"

#include "Common/Resources/VertexDeclarationTypes.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/TextureManager.h"

namespace me3d
{

GUIManager::GUIManager()
  : IManager()
  , renderEngine_po(NULL)
  , vertexBuffer_po(NULL)
  , font_o()
{
}

GUIManager::~GUIManager()
{
}

bool_t GUIManager::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftGui);
}

bool GUIManager::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  // Allocate maximum number of vertices and update sub data in addGuiObject method
  VertexBufferDesc_s v_VbDesc_s;

  v_VbDesc_s.size_u32     = c_NumQuadVertices_u32 * c_MaxGuiObjects_u32 * sizeof(VertexPosTex_s);
  v_VbDesc_s.stride_u32   = sizeof(VertexPosTex_s);
  v_VbDesc_s.c_Layout_pc  = "P3f_T2f";
  vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_VbDesc_s, NULL);

  return true;
}

void GUIManager::release_v()
{
  font_o.release_v();

  if (NULL != vertexBuffer_po)
  {
    renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
    vertexBuffer_po = NULL;
  }

}

void GUIManager::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void GUIManager::beginFrame_v()
{

}

void GUIManager::preRender_v()
{

}


void GUIManager::reset_v()
{
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxGuiObjects_u32; ++ v_I_u32)
  {
    guiObjects_as[v_I_u32].used_b = false;
  }
}

void GUIManager::createFont_v(const MEString& i_FileName_ro)
{
  font_o.create_v(i_FileName_ro, renderEngine_po);
}

TextObject_s* GUIManager::addText_ps(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro)
{
  // find next free index in the pool
  uint32_t v_NextFreeIndex_u32 = c_MaxTextObjects_u32;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxTextObjects_u32; ++ v_I_u32)
  {
    if (false == textObjects_as[v_I_u32].used_b)
    {
      v_NextFreeIndex_u32 = v_I_u32;
      textObjects_as[v_I_u32].c_Text_pc = i_Text_pc;
      textObjects_as[v_I_u32].pos_o     = i_Pos_ro;
      textObjects_as[v_I_u32].scale_o   = i_Scale_ro;
      textObjects_as[v_I_u32].color_o   = i_Color_ro;
      textObjects_as[v_I_u32].used_b    = true;
      break;
    }
  }

  return getText_po(v_NextFreeIndex_u32);
}

void GUIManager::removeText_v(TextObject_s* b_TextObject_ps)
{
  Assert(NULL != b_TextObject_ps);

  b_TextObject_ps->used_b = false;
}

TextObject_s* GUIManager::getText_po(uint32_t i_Index_u32)
{
  Assert(i_Index_u32 < c_MaxTextObjects_u32);
  return &textObjects_as[i_Index_u32];
}

Font* GUIManager::getFont_po()
{
  return &font_o;
}

GuiObject_s* GUIManager::addGuiObject_ps(const GuiObjectDesc_s& i_Desc_rs)
{
  // find next free index in the pool
  uint32_t v_NextFreeIndex_u32 = 0U;

  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxGuiObjects_u32; ++ v_I_u32)
  {
    if (guiObjects_as[v_I_u32].used_b == false)
    {
      v_NextFreeIndex_u32 = v_I_u32;
      guiObjects_as[v_NextFreeIndex_u32].desc_s = i_Desc_rs;  // flat copy ok here
      guiObjects_as[v_NextFreeIndex_u32].used_b = true;

      if (i_Desc_rs.texture_o.isEmpty_b())
      {
        guiObjects_as[v_NextFreeIndex_u32].texture_po = NULL;
      }
      else
      {
        guiObjects_as[v_NextFreeIndex_u32].texture_po = reinterpret_cast<ITextureConstantData*>(renderEngine_po->getTextureManager_po()->createTexture_po(i_Desc_rs.texture_o));
      }

      if (i_Desc_rs.textureData_po)
      {
        guiObjects_as[v_NextFreeIndex_u32].texture_po = i_Desc_rs.textureData_po;
      }

      
      break;
    }
    else
    {
      ++v_NextFreeIndex_u32;
    }
  }

  Assert(v_NextFreeIndex_u32 < c_MaxGuiObjects_u32);
  if (v_NextFreeIndex_u32 < c_MaxGuiObjects_u32)
  {
    // get the vertices for the current gui object
    VertexPosTex_s v_Vertices_as[c_NumQuadVertices_u32];
    getVertices_v(&guiObjects_as[v_NextFreeIndex_u32], &v_Vertices_as[0]);

    uint32_t v_Size_u32   = sizeof(VertexPosTex_s) * c_NumQuadVertices_u32;
    uint32_t v_Offset_u32 = v_NextFreeIndex_u32 * v_Size_u32;

    Assert(NULL != vertexBuffer_po);
    vertexBuffer_po->updateSubData_v(v_Offset_u32, v_Size_u32, v_Vertices_as);
  }
  else
  {
    // Misra else
  }

  return getGuiObject_ps(v_NextFreeIndex_u32);
}

void GUIManager::removeGuiObject_v(const GuiObject_s* b_GuiObject_ps)
{
  
  if (NULL != b_GuiObject_ps)
  {
   //Do Nothing
  }
}

GuiObject_s* GUIManager::getGuiObject_ps(uint32_t i_Index_u32)
{
  Assert(i_Index_u32 < c_MaxGuiObjects_u32);
  return &guiObjects_as[i_Index_u32];
}

VertexBuffer* GUIManager::getVertexBuffer_po() const
{
  Assert(NULL != vertexBuffer_po);
  return vertexBuffer_po;
}

// PRQA S 3706 EOF // subscript operator to a pointer value. size is defined by c_NumQuadVertices_u32. incrementing 4 times in this function

void GUIManager::getVertices_v(const GuiObject_s* i_GuiObject_ps, VertexPosTex_s* b_Vertices_ps)
{
  uint32_t v_Cnt_u32 = 0U;

  // position and Texcoord 0
  b_Vertices_ps[v_Cnt_u32].position_af32[0]  = i_GuiObject_ps->desc_s.bottomLeft_o.getPosX(); 
  b_Vertices_ps[v_Cnt_u32].position_af32[1]  = i_GuiObject_ps->desc_s.bottomLeft_o.getPosY();
  b_Vertices_ps[v_Cnt_u32].position_af32[2]  = i_GuiObject_ps->desc_s.depth_f32;
  b_Vertices_ps[v_Cnt_u32].texCoords_af32[0] = 0.0F; 
  b_Vertices_ps[v_Cnt_u32].texCoords_af32[1] = 0.0F;

  ++v_Cnt_u32;

  // position and Texcoord 1
   b_Vertices_ps[v_Cnt_u32].position_af32[0]  = i_GuiObject_ps->desc_s.bottomRight_o.getPosX(); 
   b_Vertices_ps[v_Cnt_u32].position_af32[1]  = i_GuiObject_ps->desc_s.bottomRight_o.getPosY();
   b_Vertices_ps[v_Cnt_u32].position_af32[2]  = i_GuiObject_ps->desc_s.depth_f32;
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[0] = 1.0F; 
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[1] = 0.0F;

  ++v_Cnt_u32;

  // position and Texcoord 2
   b_Vertices_ps[v_Cnt_u32].position_af32[0]  = i_GuiObject_ps->desc_s.topLeft_o.getPosX(); 
   b_Vertices_ps[v_Cnt_u32].position_af32[1]  = i_GuiObject_ps->desc_s.topLeft_o.getPosY();
   b_Vertices_ps[v_Cnt_u32].position_af32[2]  = i_GuiObject_ps->desc_s.depth_f32;
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[0] = 0.0F; 
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[1] = 1.0F;

  ++v_Cnt_u32;

  // position and Texcoord 3
   b_Vertices_ps[v_Cnt_u32].position_af32[0]  = i_GuiObject_ps->desc_s.topRight_o.getPosX(); 
   b_Vertices_ps[v_Cnt_u32].position_af32[1]  = i_GuiObject_ps->desc_s.topRight_o.getPosY();
   b_Vertices_ps[v_Cnt_u32].position_af32[2]  = i_GuiObject_ps->desc_s.depth_f32;
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[0] = 1.0F; 
   b_Vertices_ps[v_Cnt_u32].texCoords_af32[1] = 1.0F;
}

} // namespace me3d


