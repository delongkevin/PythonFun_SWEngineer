#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Manager/GUIManager.h"

namespace me3d
{
  struct GuiObjectDesc_s;

  class RenderInterface;

  class GuiInterface
  {
  public:
    GuiInterface();
    ~GuiInterface();

    void create_v(RenderInterface* b_RenderInterface_po);

    void msgObjectRelease_v(uint32_t i_Id_u32)const;
    uint32_t msgObjectCreate_u32(const GuiObjectDesc_s& i_Desc_rs, sint32_t i_RenderTargetID_s32 = -1)const;
    void msgFontCreate_v(const char* i_FontName_pc)const;
    uint32_t msgTextCreate_u32(const char* i_Text_pc, const Vector3f& i_Pos_ro, const Vector2f& i_Scale_ro, const Vector4f& i_Color_ro)const;
    void msgTextRelease_v(uint32_t i_Id_u32)const;

  private:
    RenderInterface* renderInterface_po;
  };

} // namespace me3d

#endif
