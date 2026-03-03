#include "TextureVK.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include <math.h>
#include <mecl/math/Math.h>


#include "Common/RenderEngine.h"
#include "OpenGL/Device/DeviceGLTypes.h"
#include "OpenGL/Manager/TextureManagerGL.h"



// PRQA S 1051 EOF // Vulkan port still WIP
// PRQA S 5118 EOF // c++14 autosar standard permits

namespace me3d
{


  TextureVK::TextureVK()
    : Texture()
    , textureID_u32(0U)
  {
  }

  TextureVK::~TextureVK()
  {
    // PRQA S 4261 2 // This function doesn't throw any exceptions.
    // PRQA S 4631 1 // This function doesn't throw any exceptions.
    release_v();
  }

  bool TextureVK::isValid_b() const
  {
    return textureID_u32 != 0;
  }

  void* TextureVK::getTexture_pv(TextureConstantBufferType_e i_BufferType_e)
  {
    Assert(i_BufferType_e == e_TcbColor);

    return reinterpret_cast<void*>(&textureID_u32);
  }

  bool TextureVK::create_b(RenderEngine* i_RenEng_po, const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitialData_pu8)
  {
    release_v();

    bool v_Success_b = Texture::create_b(i_RenEng_po, i_Desc_rs, i_InitialData_pu8);

//     if (v_Success_b)
//     {
//       glGenTextures(1, &textureID_u32);
//       Assert(getGLError_b() == false);
// 
//       updateData_v(i_InitialData_pu8);
// 
//       GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);
// 
// 
//       TextureManagerGL* v_TexManGL_po = static_cast<TextureManagerGL*>(renderEngine_po->getTextureManager_po());
//       v_TexManGL_po->commitDefaultSamplerStates_v(v_TextureType_e, textureID_u32);
// 
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//       //Assert(getGLError_b() == false);
//       //
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//       //Assert(getGLError_b() == false);
//       //
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//       //Assert(getGLError_b() == false);
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//       //Assert(getGLError_b() == false);
//       //
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_WRAP_S, GL_REPEAT);
//       //Assert(getGLError_b() == false);
//       //
//       //glTexParameteri(v_TextureType_e, GL_TEXTURE_WRAP_T, GL_REPEAT);
//       //Assert(getGLError_b() == false);
//       //
//       //
//       //if (e_TtCube == desc_s.type_e)
//       //{
//       //  glTexParameteri(v_TextureType_e, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//       //  Assert(getGLError_b() == false);
//       //
//       //  glTexParameteri(v_TextureType_e, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//       //  Assert(getGLError_b() == false);
//       //}
// 
//       // Generate mipmaps on the fly if there are no mipmaps in the data ptr
//       if ( (true == desc_s.numMipMaps_u32 <= 1) && 
//         (e_TtCube != desc_s.type_e )        )
//       {
//         glGenerateMipmap(v_TextureType_e);
//         Assert(getGLError_b() == false);
//       }
//     }

    return v_Success_b;
  }

  void TextureVK::updateSubData_v(const uint8_t* i_Data_pv)
  {
//     // bin the texture
//     GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);
//     glBindTexture(v_TextureType_e, textureID_u32);
// 
//     // get initial data pointer
//     const uint8_t* v_ImageData_pu8 = i_Data_pv;
// 
//     // get initial texture dimensions
//     uint32_t v_Width_u32  = desc_s.width_u32;
//     uint32_t v_Height_u32 = desc_s.height_u32;
//     uint32_t v_Depth_u32  = desc_s.depth_u32; 
// 
//     // first, loop all the mip map levels
//     for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.numMipMaps_u32; ++v_Level_u32)
//     {
//       // then loop all the faces we may have (important for cubemaps)
//       for (uint32_t v_Face_u32 = 0U; v_Face_u32 < desc_s.numFaces_u32; ++v_Face_u32)
//       {
//         // upload the image data
//         uploadSubImageData_v(v_Level_u32, v_Face_u32, v_ImageData_pu8);
// 
//         // advance image data pointer
//         if (NULL != v_ImageData_pu8)
//         {
//           uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);
// 
//           v_ImageData_pu8 += v_Size_u32;
//         }
//       }
// 
//       // calculate next mip map level
//       v_Width_u32  = mecl::math::max_x<uint32_t>((v_Width_u32  >> 1U), 1U);
//       v_Height_u32 = mecl::math::max_x<uint32_t>((v_Height_u32 >> 1U), 1U);
//       v_Depth_u32  = mecl::math::max_x<uint32_t>((v_Depth_u32  >> 1U), 1U);
//     }
// 
//     if ( (true == desc_s.numMipMaps_u32 <= 1) && 
//       (e_TtCube != desc_s.type_e )        )
//     {
//       glGenerateMipmap(v_TextureType_e);
//       Assert(getGLError_b() == false);
//     }
  }

  void TextureVK::updateData_v(const uint8_t* i_Data_pv)
  {
//     // bin the texture
//     GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);
//     glBindTexture(v_TextureType_e, textureID_u32);
// 
//     // get initial data pointer
//     const uint8_t* v_ImageData_pu8 = i_Data_pv;
// 
//     // get initial texture dimensions
//     uint32_t v_Width_u32  = desc_s.width_u32;
//     uint32_t v_Height_u32 = desc_s.height_u32;
//     uint32_t v_Depth_u32  = desc_s.depth_u32; 
// 
//     // first, loop all the mip map levels
//     for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.numMipMaps_u32; ++v_Level_u32)
//     {
//       // then loop all the faces we may have (important for cubemaps)
//       for (uint32_t v_Face_u32 = 0U; v_Face_u32 < desc_s.numFaces_u32; ++v_Face_u32)
//       {
//         // upload the image data
//         uploadImageData_v(v_Level_u32, v_Face_u32, v_ImageData_pu8);
// 
//         // advance image data pointer
//         if (NULL != v_ImageData_pu8)
//         {
//           uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);
// 
//           v_ImageData_pu8 += v_Size_u32;
//         }
//       }
// 
//       // calculate next mip map level
//       v_Width_u32  = mecl::math::max_x<uint32_t>((v_Width_u32  >> 1U), 1U);
//       v_Height_u32 = mecl::math::max_x<uint32_t>((v_Height_u32 >> 1U), 1U);
//       v_Depth_u32  = mecl::math::max_x<uint32_t>((v_Depth_u32  >> 1U), 1U);
//     }
// 
//     if ( (true == desc_s.numMipMaps_u32 <= 1) && 
//       (e_TtCube != desc_s.type_e )        )
//     {
//       glGenerateMipmap(v_TextureType_e);
//       Assert(getGLError_b() == false);
//     }
  }

  void TextureVK::release_v()
  {
    Texture::release_v();

    //glDeleteTextures(1, &textureID_u32);
  }


} // namespace me3d

#endif // RE_USE_VULKAN
