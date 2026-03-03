#include "Common/GUI/Font.h"

#include "Common/ResourceHandler/ResourceHandler.h"
#include "Common/RenderEngine.h"
#include "Common/Manager/BufferManager.h"
#include "Common/Manager/ConstantsManager.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Resources/Texture.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Effect/EffectFile.h"
#include "Common/Device/Device3D.h"

#include "MeclTypeDefs.h"

// TODO: Rework Fonts!
#include "OpenGL/GLIncludes.h"


// PRQA S 1051 EOF // TODO: Rework Fonts, currently only used in editor!
// PRQA S 3054 EOF // TODO: Rework Fonts, currently only used in editor!
// PRQA S 3706 EOF // TODO: Rework Fonts, currently only used in editor!
// PRQA S 3361 EOF // TODO: Rework Fonts, currently only used in editor!
// PRQA S 1590 EOF // TODO: Rework Fonts, currently only used in editor!
// PRQA S 3011 EOF // TODO: Rework Fonts, currently only used in editor!

namespace me3d
{
  Font::Font()
    : renderEngine_po(NULL)
    , fontData_s()
    , vertexBuffer_po(NULL)
    , effect_po(NULL)
    , texture_po(NULL)
    , textureConstant_po(NULL)
    , colorConstant_po(NULL)
  {
  }

  Font::~Font()
  {
  }

  void Font::create_v(const MEString& i_FileName_ro, RenderEngine* i_RenderEngine_po)
  {
    renderEngine_po = i_RenderEngine_po;

    FontResource_s* v_FontResource_po = ResourceHandler::get_po()->findResourceByName_po<FontResource_s>(i_FileName_ro);
    fontData_s.charInfos_ps       = v_FontResource_po->characters_ps;
    fontData_s.numCharacters_u32  = v_FontResource_po->numCharacters_u32;
    fontData_s.width_u32          = v_FontResource_po->width_u32;
    fontData_s.height_u32         = v_FontResource_po->height_u32;

    me3d::TextureDesc_s texDesc;
    texDesc.width_u32   = fontData_s.width_u32;
    texDesc.height_u32  = fontData_s.height_u32;
    texDesc.format_e    = mepl::e_RfR8;
    texDesc.type_e      = e_Tt2D;
    texDesc.fileName_o  = i_FileName_ro;

    texture_po = renderEngine_po->getTextureManager_po()->createTexture_po(texDesc, NULL);

    for (uint32_t v_i_u32 = 0; v_i_u32 < fontData_s.numCharacters_u32; ++v_i_u32)
    {  
      // TODO: Fonts via Svg
      //texture_po->updateSubData_v(
      //  fontData_s.charInfos_ps[v_i_u32].xOffset_s32, 
      //  fontData_s.charInfos_ps[v_i_u32].yOffset_s32, 
      //  fontData_s.charInfos_ps[v_i_u32].bufferWidth_s32, 
      //  fontData_s.charInfos_ps[v_i_u32].bufferHeight_s32, 
      //  fontData_s.charInfos_ps[v_i_u32].buffer_pu8);
    }

    // create Text effect and constants
    effect_po           = renderEngine_po->getShaderManager_po()->createShader_po(e_ShaderText);
    textureConstant_po  = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cFontTexture", e_CtTexture, 1U));
    colorConstant_po    = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cFontColor", e_CtFloat4, 1U));
  }

  void Font::release_v()
  {
    if (NULL != texture_po)
    {
      renderEngine_po->getTextureManager_po()->releaseTexture_v(texture_po);
      texture_po = NULL;
    }

  }

  void Font::render_v(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro)
  {
    // TODO: EffectFileRenderStateBlock
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    if (NULL != fontData_s.charInfos_ps)
    {
      const uint32_t v_BufferLength_u32 = 256;
      Assert(strnlen(i_Text_pc, v_BufferLength_u32) < v_BufferLength_u32);

      VertexPosTex_s v_Vertices_as[v_BufferLength_u32]; 
      uint32_t v_Count_u32 = 0U;

      float32_t v_x_f32 = i_Pos_ro.getPosX();
      float32_t v_y_f32 = i_Pos_ro.getPosY();
      float32_t v_z_f32 = i_Pos_ro.getPosZ();

      // Loop through all characters 
      for (const char *p = i_Text_pc; *p; p++) 
      {
        sint32_t v_Index_s32 = static_cast<sint32_t>(*p);

        // Calculate the vertex and texture coordinates 
        float32_t x2 = v_x_f32 + fontData_s.charInfos_ps[v_Index_s32].bl_f32 * i_Scale_ro.getPosX();
        float32_t y2 = -v_y_f32 - fontData_s.charInfos_ps[v_Index_s32].bt_f32 * i_Scale_ro.getPosY();
        float32_t w = fontData_s.charInfos_ps[v_Index_s32].bw_f32 * i_Scale_ro.getPosX();
        float32_t h = fontData_s.charInfos_ps[v_Index_s32].bh_f32 * i_Scale_ro.getPosY();

        // Advance the cursor to the start of the next character
        v_x_f32 += fontData_s.charInfos_ps[v_Index_s32].ax_f32 * i_Scale_ro.getPosX();
        v_y_f32 += fontData_s.charInfos_ps[v_Index_s32].ay_f32 * i_Scale_ro.getPosY();

        // Skip glyphs that have no pixels
        if ((!w) || (!h))
        {
          continue;
        }

        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2,     -y2,     v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32                                            , fontData_s.charInfos_ps[v_Index_s32].ty_f32);
        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2 + w, -y2,     v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32 + fontData_s.charInfos_ps[v_Index_s32].bw_f32 / fontData_s.width_u32, fontData_s.charInfos_ps[v_Index_s32].ty_f32);
        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2,     -y2 - h, v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32                                            , fontData_s.charInfos_ps[v_Index_s32].ty_f32 + fontData_s.charInfos_ps[v_Index_s32].bh_f32 / fontData_s.height_u32);
        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2 + w, -y2,     v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32 + fontData_s.charInfos_ps[v_Index_s32].bw_f32 / fontData_s.width_u32, fontData_s.charInfos_ps[v_Index_s32].ty_f32);
        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2,     -y2 - h, v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32                                            , fontData_s.charInfos_ps[v_Index_s32].ty_f32 + fontData_s.charInfos_ps[v_Index_s32].bh_f32 / fontData_s.height_u32);
        v_Vertices_as[v_Count_u32++] = VertexPosTex_s(x2 + w, -y2 - h, v_z_f32, fontData_s.charInfos_ps[v_Index_s32].tx_f32 + fontData_s.charInfos_ps[v_Index_s32].bw_f32 / fontData_s.width_u32, fontData_s.charInfos_ps[v_Index_s32].ty_f32 + fontData_s.charInfos_ps[v_Index_s32].bh_f32 / fontData_s.height_u32);
      }


      VertexBufferDesc_s v_Desc_s;
      v_Desc_s.c_Layout_pc = "P3f_T2f";
      v_Desc_s.size_u32 = sizeof(VertexPosTex_s) * v_Count_u32;
      v_Desc_s.stride_u32 = sizeof(VertexPosTex_s);
      vertexBuffer_po = renderEngine_po->getBufferManager_po()->createVertexBuffer_po(v_Desc_s, v_Vertices_as);

      vertexBuffer_po->set_v(0);

      textureConstant_po->setData_v(texture_po);
      colorConstant_po->setData_v(&i_Color_ro);

      effect_po->beginPass_b();

      renderEngine_po->getDevice_po()->draw_v(e_PtTriangleList, v_Count_u32, 0U);

      effect_po->endPass_v();

      renderEngine_po->getBufferManager_po()->releaseVertexBuffer_v(vertexBuffer_po);
    }

    // TODO: EffectFileRenderStateBlock
    glDisable(GL_BLEND);

  }

} // namespace me3d
