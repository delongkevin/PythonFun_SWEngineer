#include "Common/Interfaces/GuiInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Resources/MultipleRenderTarget.h"
#include "Common/Resources/RenderTarget.h"

namespace me3d
{
  GuiInterface::GuiInterface()
    : renderInterface_po(NULL)
  {
  }

  GuiInterface::~GuiInterface()
  {
  }

  void GuiInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
  }

  void GuiInterface::msgObjectRelease_v(uint32_t i_Id_u32)const
  {
    GuiObject_s* v_GuiObject_ps = reinterpret_cast<GuiObject_s*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtGui));

    renderInterface_po->renderEngine_o.getGUIManager_po()->removeGuiObject_v(v_GuiObject_ps);
  }

  uint32_t GuiInterface::msgObjectCreate_u32(const GuiObjectDesc_s& i_Desc_rs, sint32_t i_RenderTargetID_s32 /*= -1*/)const
  {
    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    GuiObject_s* v_GuiObject_ps = renderInterface_po->renderEngine_o.getGUIManager_po()->addGuiObject_ps(i_Desc_rs);

    if (-1 != i_RenderTargetID_s32)
    {
      MultipleRenderTarget* v_MRT_po = reinterpret_cast<MultipleRenderTarget*>(renderInterface_po->getAtID_pv(i_RenderTargetID_s32, e_OtRenderTarget));

      if (NULL != v_MRT_po)
      {
        v_GuiObject_ps->texture_po = v_MRT_po->getColorRenderTarget_po(0U);  
      }
    }

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_GuiObject_ps), e_OtGui);

    return v_ID_u32;
  }

  void GuiInterface::msgFontCreate_v(const char* i_FontName_pc)const
  {
    renderInterface_po->renderEngine_o.getGUIManager_po()->createFont_v(i_FontName_pc);
  }

  uint32_t GuiInterface::msgTextCreate_u32(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro)const
  {
    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    TextObject_s* v_TextObject_ps = renderInterface_po->renderEngine_o.getGUIManager_po()->addText_ps(i_Text_pc, i_Pos_ro, i_Scale_ro, i_Color_ro);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_TextObject_ps), e_OtText);

    return v_ID_u32;
  }

  void GuiInterface::msgTextRelease_v(uint32_t i_Id_u32)const
  {
    TextObject_s* v_TextObject_ps = reinterpret_cast<TextObject_s*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtText));

    renderInterface_po->renderEngine_o.getGUIManager_po()->removeText_v(v_TextObject_ps);
  }

} // namespace me3d