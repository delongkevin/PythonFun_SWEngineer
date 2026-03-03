#ifndef TEXTURE_INTERFACE_H
#define TEXTURE_INTERFACE_H

#include "MeclTypeDefs.h"
#include "Common/Device/Device3DTypes.h"

namespace me3d
{
  class RenderInterface;
  struct TextureDesc_s;

  class TextureInterface
  {
  public:
    TextureInterface();
    ~TextureInterface();

    void                  create_v(RenderInterface* b_RenderInterface_po);

    // --- Texture Interface ---

    // Create Texture from Description
    uint32_t              msgTextureCreate_u32(const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitalData_pu8)const;
    
    // Create Texture from FileName
    uint32_t              msgTextureCreate_u32(const MEString& i_FileName_ro)const;

    // Update Texture Data
    bool_t                msgTextureUpdate_b(uint32_t i_Id_u32, const uint8_t* i_Data_pu8)const;

    // Get the texture descriptor with given Texture ID
    bool_t                msgGetDimensions_b(uint32_t i_Id_u32, uint32_t& o_Width_ru32, uint32_t& o_Height_ru32)const;

    // Get the texture descriptor with given Texture Name
    bool_t                msgGetDimensions_b(const MEString& i_Name_ro, uint32_t& o_Width_ru32, uint32_t& o_Height_ru32)const;

    // Get texture name
    bool_t                msgGetName_b(uint32_t i_Id_u32, MEString& o_Name_ro)const;

    // --- Render Target Interface ---

    // Create RenderTarget. If width == -1 and height == -1 the back buffer size is used.
    uint32_t              msgRenderTargetCreate_u32(const char_t* i_Name_pc, sint32_t i_Width_s32, sint32_t i_Height_s32, mepl::PixelFormat_e i_ColorFormat_e = mepl::e_RfR8G8B8A8, mepl::PixelFormat_e i_DepthFormat_e = mepl::e_RfD16)const;

    // Delete Render Target
    bool_t                msgRenderTargetDelete_b(uint32_t i_Id_u32)const;

  private:
    RenderInterface* renderInterface_po;
  };

} // namespace me3d

#endif
