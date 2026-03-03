
#ifdef RE_USE_OPENGLES30

#include "OpenGLES30/Resources/TextureGLES30.h"

#include "OpenGL/Device/DeviceGLTypes.h"

namespace me3d
{
  TextureGLES30::TextureGLES30()
    : TextureGL()
  {

  }

  TextureGLES30::~TextureGLES30()
  {

  }

  void TextureGLES30::updateSubData_v(const uint8_t* i_Data_pv)
  {
    // bin the texture
    GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);
    glBindTexture(v_TextureType_e, textureID_u32);

    // get initial data pointer
    const uint8_t* v_ImageData_pu8 = i_Data_pv;

    // get initial texture dimensions
    uint32_t v_Width_u32  = desc_s.width_u32;
    uint32_t v_Height_u32 = desc_s.height_u32;
    uint32_t v_Depth_u32  = desc_s.depth_u32; 

    GLuint pboId_u32;   
    glGenBuffers(1, &pboId_u32);
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, pboId_u32);

    // first, loop all the mip map levels
    for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.numMipMaps_u32; ++v_Level_u32)
    {
      // then loop all the faces we may have (important for cubemaps)
      for (uint32_t v_Face_u32 = 0U; v_Face_u32 < desc_s.numFaces_u32; ++v_Face_u32)
      {
        uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);

        glBufferData(GL_PIXEL_UNPACK_BUFFER, v_Size_u32, 0, GL_STREAM_DRAW);

        uint8_t* v_PixelBufferMemory_pu8 = (uint8_t*)glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, (GLintptr)0, v_Size_u32, GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);
        // map the buffer object into client's memory
        Assert(getGLError_b() == false);
        if(v_PixelBufferMemory_pu8)
        {
          memcpy(v_PixelBufferMemory_pu8, v_ImageData_pu8, v_Size_u32);

          glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);
        }

        // upload the image data
        uploadSubImageData_v(v_Level_u32, v_Face_u32, 0);

        // advance image data pointer
        if (NULL != v_ImageData_pu8)
        {

          v_ImageData_pu8 += v_Size_u32;
        }
      }

      // calculate next mip map level
      v_Width_u32  = mecl::math::max_x<uint32_t>((v_Width_u32  >> 1U), 1U);
      v_Height_u32 = mecl::math::max_x<uint32_t>((v_Height_u32 >> 1U), 1U);
      v_Depth_u32  = mecl::math::max_x<uint32_t>((v_Depth_u32  >> 1U), 1U);
    }

    if ( (true == desc_s.numMipMaps_u32 <= 1) && 
      (e_TtCube != desc_s.type_e )        )
    {
      glGenerateMipmap(v_TextureType_e);
      Assert(getGLError_b() == false);
    }

    // it is good idea to release PBOs with ID 0 after use.Once bound with 0, all pixel operations behave normal ways.
    glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);
    Assert(getGLError_b() == false);


    glDeleteBuffers(1, &pboId_u32);
    Assert(getGLError_b() == false);
  }

} // namespace me3d

#endif // RE_USE_OPENGLES30