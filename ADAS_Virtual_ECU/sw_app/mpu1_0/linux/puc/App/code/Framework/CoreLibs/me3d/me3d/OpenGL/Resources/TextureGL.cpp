#include "TextureGL.h"

#include <math.h>
#include <mecl/math/Math.h>
 

#include "Common/RenderEngine.h"
#include "OpenGL/Device/DeviceGLES.h"
#include "OpenGL/Device/DeviceGLTypes.h"
#include "OpenGL/Manager/TextureManagerGL.h"


// PRQA S 2642 EOF // by design
// PRQA S 3048 EOF // EGL API Handling
// PRQA S 3080 EOF // EGL API Handling
// PRQA S 3060 EOF // used by design
// PRQA S 3076 EOF // used by design


namespace me3d
{
	static PFNEGLCREATEIMAGEKHRPROC eglCreateImageKHR = NULL;
	static PFNEGLDESTROYIMAGEKHRPROC eglDestroyImageKHR = NULL;
	static PFNGLEGLIMAGETARGETTEXTURE2DOESPROC eglImageTargetTexture2DOES = NULL;

  inline void initExtensions_v()
  {
    
      eglCreateImageKHR = (PFNEGLCREATEIMAGEKHRPROC) eglGetProcAddress("eglCreateImageKHR");
      eglDestroyImageKHR = (PFNEGLDESTROYIMAGEKHRPROC) eglGetProcAddress("eglDestroyImageKHR");
      eglImageTargetTexture2DOES = (PFNGLEGLIMAGETARGETTEXTURE2DOESPROC) eglGetProcAddress("glEGLImageTargetTexture2DOES");

      if ((eglCreateImageKHR == NULL) || (eglDestroyImageKHR == NULL) || (eglImageTargetTexture2DOES == NULL))
      {
        ME_Debugger_F_Printf_v("GL_OES_EGL_image_external functions not found\n");
      }
    
  }

TextureGL::TextureGL()
  : Texture()
  , textureID_u32(0U)
  , egl_image(0)
{
  initExtensions_v();
}

TextureGL::~TextureGL()
{
  // PRQA S 4261 2 // This function doesn't throw any exceptions.
  // PRQA S 4631 1 // This function doesn't throw any exceptions.
  release_v();
}

bool TextureGL::isValid_b() const
{
  return textureID_u32 != 0;
}

void* TextureGL::getTexture_pv(TextureConstantBufferType_e i_BufferType_e)
{
  Assert(i_BufferType_e == e_TcbColor);

  return reinterpret_cast<void*>(&textureID_u32);
}

bool TextureGL::create_b(RenderEngine* i_RenEng_po, const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitialData_pu8)
{
  release_v();

  bool v_Success_b = Texture::create_b(i_RenEng_po, i_Desc_rs, i_InitialData_pu8);

  if (v_Success_b)
  {
    glGenTextures(1, &textureID_u32);
    Assert(getGLError_b() == false);

    if ((desc_s.type_e == e_TtExternal) && (eglCreateImageKHR != NULL))
    {
      EGLDisplay display = ((DeviceGLES*)i_RenEng_po->getDevice_po())->getDisplay_t();

        //Create the EGLImage from the screen pixmap
        egl_image = eglCreateImageKHR(display, EGL_NO_CONTEXT, EGL_NATIVE_PIXMAP_KHR, (EGLNativePixmapType)i_InitialData_pu8, NULL);
        if (egl_image == EGL_NO_IMAGE_KHR)
        {
          EGLint v_Error_s32 = eglGetError();
          ME_Debugger_F_Printf_v("eglCreateImageKHR failed: %i (0x%.4x)\n", v_Error_s32, v_Error_s32);

            Assert(false);
        }
        else
        {

          GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);
          glBindTexture(v_TextureType_e, textureID_u32);

          if (eglImageTargetTexture2DOES != NULL)
          {
            eglImageTargetTexture2DOES(GL_TEXTURE_EXTERNAL_OES, egl_image);
          }
        }


        // no mip mapping
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_EXTERNAL_OES, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    }
    else
    {
      updateData_v(i_InitialData_pu8);


      GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);


      TextureManagerGL* v_TexManGL_po = static_cast<TextureManagerGL*>(renderEngine_po->getTextureManager_po());
      v_TexManGL_po->commitDefaultSamplerStates_v(v_TextureType_e, textureID_u32);

      // Generate mipmaps on the fly if there are no mipmaps in the data ptr
      if ( (desc_s.numMipMaps_u32 <= 1) &&
           (e_TtCube != desc_s.type_e )         &&
           (e_TtExternal != desc_s.type_e ))
      {
        glGenerateMipmap(v_TextureType_e);
        Assert(getGLError_b() == false);
      }
    }

  }

  return v_Success_b;
}

void TextureGL::updateSubData_v(const uint8_t* i_Data_pv)
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

  // first, loop all the mip map levels
  for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.numMipMaps_u32; ++v_Level_u32)
  {
    // then loop all the faces we may have (important for cubemaps)
    for (uint32_t v_Face_u32 = 0U; v_Face_u32 < desc_s.numFaces_u32; ++v_Face_u32)
    {
      // upload the image data
      uploadSubImageData_v(v_Level_u32, v_Face_u32, v_ImageData_pu8);

      // advance image data pointer
      if (NULL != v_ImageData_pu8)
      {
        uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);

        v_ImageData_pu8 += v_Size_u32;
      }
    }

    // calculate next mip map level
    v_Width_u32  = mecl::math::max_x<uint32_t>((v_Width_u32  >> 1U), 1U);
    v_Height_u32 = mecl::math::max_x<uint32_t>((v_Height_u32 >> 1U), 1U);
    v_Depth_u32  = mecl::math::max_x<uint32_t>((v_Depth_u32  >> 1U), 1U);
  }

  if ( (desc_s.numMipMaps_u32 <= 1) && 
    (e_TtCube != desc_s.type_e )        )
  {
    glGenerateMipmap(v_TextureType_e);
    Assert(getGLError_b() == false);
  }
}

void TextureGL::updateData_v(const uint8_t* i_Data_pv)
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

  // first, loop all the mip map levels
  for (uint32_t v_Level_u32 = 0U; v_Level_u32 < desc_s.numMipMaps_u32; ++v_Level_u32)
  {
    // then loop all the faces we may have (important for cubemaps)
    for (uint32_t v_Face_u32 = 0U; v_Face_u32 < desc_s.numFaces_u32; ++v_Face_u32)
    {
      // upload the image data
      uploadImageData_v(v_Level_u32, v_Face_u32, v_ImageData_pu8);

      // advance image data pointer
      if (NULL != v_ImageData_pu8)
      {
        uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);

        v_ImageData_pu8 += v_Size_u32;
      }
    }

    // calculate next mip map level
    v_Width_u32  = mecl::math::max_x<uint32_t>((v_Width_u32  >> 1U), 1U);
    v_Height_u32 = mecl::math::max_x<uint32_t>((v_Height_u32 >> 1U), 1U);
    v_Depth_u32  = mecl::math::max_x<uint32_t>((v_Depth_u32  >> 1U), 1U);
  }

  if ( (desc_s.numMipMaps_u32 <= 1) && 
    (e_TtCube != desc_s.type_e )        )
  {
    glGenerateMipmap(v_TextureType_e);
    Assert(getGLError_b() == false);
  }
}

void TextureGL::release_v()
{
  Texture::release_v();

  glDeleteTextures(1, &textureID_u32);
}


void TextureGL::uploadImageData_v(uint32_t i_Level_u32, uint32_t i_ArraySlice_u32, const uint8_t* i_Data_pu8)
{
  uint32_t v_Width_u32  = mecl::math::max_x<uint32_t>((desc_s.width_u32  >> i_Level_u32), 1U);
  uint32_t v_Height_u32 = mecl::math::max_x<uint32_t>((desc_s.height_u32 >> i_Level_u32), 1U);
  uint32_t v_Depth_u32  = mecl::math::max_x<uint32_t>((desc_s.depth_u32  >> i_Level_u32), 1U);

  uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);

  GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);

  glBindTexture(v_TextureType_e, textureID_u32);
  Assert(getGLError_b() == false);

  if (desc_s.format_e == mepl::e_RfEtc1)
  {
    // ETC 1 needs an unpack alignment of 4
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    Assert(getGLError_b() == false);

    switch (desc_s.type_e)
    {
    case e_Tt1D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_Tt2D:
      {
        glCompressedTexImage2D(
          v_TextureType_e, 
          i_Level_u32, 
          getGLTextureResourceFormat_e(desc_s.format_e),
          v_Width_u32, 
          v_Height_u32, 
          0,
          v_Size_u32,
          i_Data_pu8);
        break;
      }
    case e_Tt3D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_TtCube:
      {
        glCompressedTexImage2D(
          GL_TEXTURE_CUBE_MAP_POSITIVE_X + i_ArraySlice_u32, 
          i_Level_u32, 
          getGLTextureResourceFormat_e(desc_s.format_e),
          v_Width_u32, 
          v_Height_u32, 
          0,
          v_Size_u32,
          i_Data_pu8);
      }
      break;
    case e_Tt2DMultisample:
      {
        // Render Targets Not yet implemented
        Assert(false);
      }
      break;
    case e_TtUnknown: // fall through
    default:
		{
      Assert(false);
      break;
		}
    } // switch texture type
  }
  else
  {
    // All other formats are ok with unpack alignment of 1 for now
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    Assert(getGLError_b() == false);

    switch (desc_s.type_e)
    {
    case e_Tt1D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_Tt2D:
      {
        glTexImage2D(
          v_TextureType_e, 
          i_Level_u32, 
          getGLTextureResourceFormat_e(desc_s.format_e), 
          v_Width_u32, 
          v_Height_u32, 
          0, 
          getGLPixelFormat_e(desc_s.format_e), 
          getGLPixelType_e(desc_s.format_e), 
          i_Data_pu8);
        break;
      }
    case e_Tt3D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_TtCube:
      {
        glTexImage2D(
          GL_TEXTURE_CUBE_MAP_POSITIVE_X + i_ArraySlice_u32,
          i_Level_u32,
          getGLTextureResourceFormat_e(desc_s.format_e),
          v_Width_u32, 
          v_Height_u32,
          0,
          getGLPixelFormat_e(desc_s.format_e), 
          getGLPixelType_e(desc_s.format_e),
          i_Data_pu8);
      }
      break;
    case e_Tt2DMultisample:
      {
        // Render Targets Not yet implemented
        Assert(false);
      }
      break;
    case e_TtUnknown: // fall through
    default:
		{
		Assert(false);
		break;
		}
    } // switch texture type
  }
  Assert(getGLError_b() == false);
}

void TextureGL::uploadSubImageData_v(uint32_t i_Level_u32, uint32_t i_ArraySlice_u32, const uint8_t* i_Data_pu8)
{
  uint32_t v_Width_u32  = mecl::math::max_x<uint32_t>((desc_s.width_u32  >> i_Level_u32), 1U);
  uint32_t v_Height_u32 = mecl::math::max_x<uint32_t>((desc_s.height_u32 >> i_Level_u32), 1U);
  uint32_t v_Depth_u32  = mecl::math::max_x<uint32_t>((desc_s.depth_u32  >> i_Level_u32), 1U);

  uint32_t v_Size_u32 = getImageSize_u32(v_Width_u32, v_Height_u32, v_Depth_u32, desc_s.format_e);

  GLenum v_TextureType_e = getGLTextureType_e(desc_s.type_e);


  if (desc_s.format_e == mepl::e_RfEtc1)
  {
    // ETC 1 needs an unpack alignment of 4
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
    Assert(getGLError_b() == false);

    switch (desc_s.type_e)
    {
    case e_Tt1D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_Tt2D:
      {
        glCompressedTexSubImage2D(
          v_TextureType_e, 
          i_Level_u32, 
          0,
          0,
          v_Width_u32, 
          v_Height_u32,
          getGLTextureResourceFormat_e(desc_s.format_e),
          v_Size_u32,
          i_Data_pu8);
        break;
      }
    case e_Tt3D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_TtCube:
      {
        glCompressedTexSubImage2D(
          GL_TEXTURE_CUBE_MAP_POSITIVE_X + i_ArraySlice_u32, 
          i_Level_u32, 
          0,
          0,
          v_Width_u32, 
          v_Height_u32,
          getGLTextureResourceFormat_e(desc_s.format_e),
          v_Size_u32,
          i_Data_pu8);
      }
      break;
    case e_Tt2DMultisample:
      {
        // Render Targets Not yet implemented
        Assert(false);
      }
      break;
    case e_TtUnknown: // fall through
    default:
		{
		Assert(false);
		break;
		}
    } // switch texture type
  }
  else
  {
    // All other formats are ok with unpack alignment of 1 for now
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    Assert(getGLError_b() == false);

    switch (desc_s.type_e)
    {
    case e_Tt1D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_Tt2D:
      {
        glTexSubImage2D(
          v_TextureType_e, 
          i_Level_u32, 
          0,
          0,
          v_Width_u32, 
          v_Height_u32,
          getGLTextureResourceFormat_e(desc_s.format_e),
          getGLPixelType_e(desc_s.format_e),
          i_Data_pu8);
        break;
      }
    case e_Tt3D:
      {
        // Not supported
        Assert(false);
        break;
      }
    case e_TtCube:
      {
        glTexSubImage2D(
          GL_TEXTURE_CUBE_MAP_POSITIVE_X + i_ArraySlice_u32,
          i_Level_u32, 
          0,
          0,
          v_Width_u32, 
          v_Height_u32,
          getGLTextureResourceFormat_e(desc_s.format_e),
          getGLPixelType_e(desc_s.format_e),
          i_Data_pu8);
      }
      break;
    case e_Tt2DMultisample:
      {
        // Render Targets Not yet implemented
        Assert(false);
      }
      break;
    case e_TtExternal: // don't update external textures, just ignore, no assert
    {
      break;
    }
    case e_TtUnknown: // fall through
    default:
		{
		Assert(false);
		break;
		}
    } // switch texture type
  }
  Assert(getGLError_b() == false);
}


} // namespace me3d
