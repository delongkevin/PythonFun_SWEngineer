#include "Common/Interfaces/TextureInterface.h"
#include "Common/RenderInterface.h"
#include "Common/Manager/TextureManager.h"
#include "Common/Resources/Texture.h"


// PRQA S 3103 EOF // by design
// PRQA S 3710 EOF // flag handling

namespace me3d
{

  TextureInterface::TextureInterface()
    : renderInterface_po(NULL)
  {

  }

  TextureInterface::~TextureInterface()
  {

  }

  void TextureInterface::create_v(RenderInterface* b_RenderInterface_po)
  {
    renderInterface_po = b_RenderInterface_po;
    Assert(NULL != renderInterface_po);
  }

  uint32_t TextureInterface::msgTextureCreate_u32(const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitalData_pu8)const
  {
    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    Texture* v_Texture_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createTexture_po(i_Desc_rs, i_InitalData_pu8);

    Assert(NULL != v_Texture_po);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_Texture_po), e_OtTexture);

    return v_ID_u32;
  }

  uint32_t TextureInterface::msgTextureCreate_u32(const MEString& i_FileName_ro)const
  {
    uint32_t v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();

    Texture* v_Texture_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createTexture_po(i_FileName_ro);

    Assert(NULL != v_Texture_po);

    renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_Texture_po), e_OtTexture);

    return v_ID_u32;
  }

  bool_t TextureInterface::msgTextureUpdate_b(uint32_t i_Id_u32, const uint8_t* i_Data_pu8)const
  {
    bool_t v_Success_b = false;

    Texture* v_Texture_po = reinterpret_cast<Texture*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtTexture));
    if (NULL != v_Texture_po)
    {
      v_Texture_po->updateSubData_v(i_Data_pu8);
      v_Success_b = true;
    }

    return v_Success_b;
  }

  bool_t TextureInterface::msgGetDimensions_b(uint32_t i_Id_u32, uint32_t& o_Width_ru32, uint32_t& o_Height_ru32)const
  {
    bool_t v_Result_b = false;

    Texture* v_Texture_po = reinterpret_cast<Texture*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtTexture));

    if(v_Texture_po != NULL)
    {
      o_Width_ru32 = v_Texture_po->getWidth_u32();
      o_Height_ru32 = v_Texture_po->getHeight_u32();

      v_Result_b = true;
    }

    return v_Result_b;
  }

  bool_t TextureInterface::msgGetDimensions_b(const MEString& i_Name_ro, uint32_t& o_Width_ru32, uint32_t& o_Height_ru32)const
  {
    bool_t v_Result_b = false;

    Texture* v_Texture_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createTexture_po(i_Name_ro);

    if(v_Texture_po != NULL)
    {
      o_Width_ru32 = v_Texture_po->getWidth_u32();
      o_Height_ru32 = v_Texture_po->getHeight_u32();

      v_Result_b = true;
    }

    return v_Result_b;
  }

  bool_t TextureInterface::msgGetName_b(uint32_t i_Id_u32, MEString& o_Name_ro)const
  {
    bool_t v_Result_b = false;

    Texture* v_Texture_po = reinterpret_cast<Texture*>(renderInterface_po->getAtID_pv(i_Id_u32, e_OtTexture));

    if(v_Texture_po != NULL)
    {
      o_Name_ro = v_Texture_po->getFilename_ro();

      v_Result_b = true;
    }

    return v_Result_b;
  }

  uint32_t TextureInterface::msgRenderTargetCreate_u32(const char_t* i_Name_pc, sint32_t i_Width_s32, sint32_t i_Height_s32, mepl::PixelFormat_e i_ColorFormat_e /*= e_RfR8G8B8A8*/, mepl::PixelFormat_e i_DepthFormat_e /*= e_RfD16*/)const
  {
    RenderTargetDesc_s v_ColorDesc_s;
    RenderTargetDesc_s v_DepthDesc_s;

    v_ColorDesc_s.colorFormat_e = i_ColorFormat_e;
    v_DepthDesc_s.depthFormat_e = i_DepthFormat_e;
    
    v_ColorDesc_s.name_o = i_Name_pc;
    v_ColorDesc_s.name_o += "_Color";

    v_DepthDesc_s.name_o = i_Name_pc;
    v_DepthDesc_s.name_o += "_Depth";

    if ((i_Width_s32 <= 0) || (i_Height_s32 <= 0))
    {
      // use Back Buffer size
      v_ColorDesc_s.flags_u32 |= e_RtrBackBufferSize;
      v_DepthDesc_s.flags_u32 |= e_RtrBackBufferSize;

      v_ColorDesc_s.width_u32  = 1;
      v_ColorDesc_s.height_u32 = 1;

      v_DepthDesc_s.width_u32  = 1;
      v_DepthDesc_s.height_u32 = 1;
    }
    else
    {
      v_ColorDesc_s.width_u32  = static_cast<uint32_t>(i_Width_s32);
      v_ColorDesc_s.height_u32 = static_cast<uint32_t>(i_Height_s32);

      v_DepthDesc_s.width_u32  = static_cast<uint32_t>(i_Width_s32);
      v_DepthDesc_s.height_u32 = static_cast<uint32_t>(i_Height_s32);
    }

    uint32_t v_ID_u32 = RenderInterface::c_InvalidGUID_u32;
    MultipleRenderTarget* v_MRT_po = renderInterface_po->renderEngine_o.getTextureManager_po()->createMultipleRenderTarget_po(&v_ColorDesc_s, &v_DepthDesc_s);

    Assert(NULL != v_MRT_po);
    if (NULL != v_MRT_po)
    {
      v_ID_u32 = renderInterface_po->guidGenerator_o.getFreeID_u32();
      renderInterface_po->setAtID_v(v_ID_u32, reinterpret_cast<void*>(v_MRT_po), e_OtRenderTarget);
    }

    return v_ID_u32;
  }

  bool_t TextureInterface::msgRenderTargetDelete_b(uint32_t i_Id_u32)const
  {
    MultipleRenderTarget* v_MRT_po = reinterpret_cast<MultipleRenderTarget*>(renderInterface_po->clearID_pv(i_Id_u32, e_OtRenderTarget));

    bool_t v_Success_b = (NULL != v_MRT_po);

    if (true == v_Success_b)
    {
      renderInterface_po->renderEngine_o.getTextureManager_po()->releaseMultipleRenderTarget_v(v_MRT_po);
    }

    return v_Success_b;
  }

} // namespace me3d