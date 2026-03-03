#include "Common/Renderer/GUIRenderer.h"

#include "Common/RenderEngine.h"
#include "Common/Device/Device3D.h"
#include "Common/Manager/ShaderManager.h"
#include "Common/Manager/GUIManager.h"
#include "Common/Resources/Texture.h"
#include "Common/Resources/VertexBuffer.h"
#include "Common/Effect/EffectFileRenderStateBlock.h"

namespace me3d
{

GUIRenderer::GUIRenderer()
  : IRenderer()
  , renderEngine_po(NULL)
  , effect_po(NULL)
  , constantGUITexture_po(NULL)
  , constantHasTexture_po(NULL)
  , constantColor_po(NULL)
{
}

GUIRenderer::~GUIRenderer()
{
}

bool_t GUIRenderer::isEnabled_b()
{
  return renderEngine_po->isEnabled_b(e_EftGui);
}

bool GUIRenderer::create_b(RenderEngine* b_RenderEngine_po)
{
  renderEngine_po = b_RenderEngine_po;

  // create effect 
  effect_po             = renderEngine_po->getShaderManager_po()->createShader_po(e_ShaderGui);

  // Enable alpha blending for this effect
  EffectFileRenderStateBlock* v_Efrsb_po = renderEngine_po->getShaderManager_po()->createRenderStateBlock_po();
  v_Efrsb_po->addState_b(EffectFileRenderState_s(e_EfstAlphaBlendEnable, EffectFileStateValue_s(e_EfsvTrue), 0));    
  v_Efrsb_po->addState_b(EffectFileRenderState_s(e_EfstSrcBlend, EffectFileStateValue_s(e_EfsvSrcAlpha), 0));
  v_Efrsb_po->addState_b(EffectFileRenderState_s(e_EfstDestBlend, EffectFileStateValue_s(e_EfsvOneMinusSrcAlpha), 0));
  effect_po->setRenderStateBlock_v(v_Efrsb_po);

  // and set constants
  constantGUITexture_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuiSampler2d", e_CtTexture, 1U));
  constantHasTexture_po = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cHasTexture", e_CtInt1, 1U));
  constantColor_po      = renderEngine_po->getConstantsManager_po()->getSharedConstant_po(ConstantDesc_s("cGuiColor", e_CtFloat4, 1U));

  return true;
}

void GUIRenderer::release_v()
{
  effect_po             = NULL;
  constantGUITexture_po = NULL;
  constantHasTexture_po = NULL;
  constantColor_po      = NULL;
}

void GUIRenderer::onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32)
{

}

void GUIRenderer::beginFrame_v()
{
}

void GUIRenderer::reset_v()
{

}

void GUIRenderer::render_v()const
{
  renderGuiObjects_v();
  renderTexts_v();
}

void GUIRenderer::renderGuiObjects_v() const
{
  // Bind the VBO
  VertexBuffer* v_VertexBuffer_po = renderEngine_po->getGUIManager_po()->getVertexBuffer_po(); 
  v_VertexBuffer_po->set_v(0);

  // Render all valid gui objects
  for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxGuiObjects_u32; ++v_I_u32)
  {
    GuiObject_s* v_GuiObject_ps = renderEngine_po->getGUIManager_po()->getGuiObject_ps(v_I_u32);

    // only draw the used ones
    if (true == v_GuiObject_ps->used_b)
    {
      bool v_HasTexture_b = (NULL != v_GuiObject_ps->texture_po);
      constantHasTexture_po->setData_v(&v_HasTexture_b);

      const Color& c_Col_ro = v_GuiObject_ps->desc_s.color_o;
      Vector4f v_ColVec4_o(c_Col_ro[0], c_Col_ro[1], c_Col_ro[2], c_Col_ro[3]);
      constantColor_po->setData_v(&v_ColVec4_o);

      constantGUITexture_po->setData_v(v_GuiObject_ps->texture_po, e_TcbColor);

      // Begin Rendering
      effect_po->beginPass_b();

      // Draw all GUI objects 
      renderEngine_po->getDevice_po()->draw_v(e_PtTriangleStrip, c_NumQuadVertices_u32, v_I_u32 * c_NumQuadVertices_u32);

      // end Rendering
      effect_po->endPass_v();
    }

  }

  renderEngine_po->getDevice_po()->resetVertexBuffer_v(0);
}

void GUIRenderer::renderTexts_v() const
{
  Font* v_Font_po = renderEngine_po->getGUIManager_po()->getFont_po();

  if (NULL != v_Font_po)
  {
    // Render all valid text objects
    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_MaxTextObjects_u32; ++v_I_u32)
    {
      TextObject_s* v_Text_ps = renderEngine_po->getGUIManager_po()->getText_po(v_I_u32);

      // only draw the used ones
      if (true == v_Text_ps->used_b)
      {
        v_Font_po->render_v(v_Text_ps->c_Text_pc, v_Text_ps->pos_o, v_Text_ps->scale_o, v_Text_ps->color_o);
      }
    }
  }
}

} // namespace me3d
