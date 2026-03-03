#include "KTXFile.h"

#include <mecl/math/Math.h>

#include <osal/io/File.h>

// PRQA S 5118 EOF // C++14 Autosar standard permits
// PRQA S 4020 EOF // by design
// PRQA S 3700 EOF // by design
// PRQA S 3361 EOF // intended

namespace me3d
{
  KTXFile::KTXFile()
    : header_s()
    , texInfo_s()
    , data_pu8(NULL)
    , dataSize_u32(0U)
  {

  }

  KTXFile::~KTXFile()
  {
    // PRQA S 4631 1 // no exceptions
    release_v();
  }

  bool KTXFile::load_b(const char* i_FileName_pc)
  {
    release_v();

    osal::File v_File_o;
    // PRQA S 3710 1 // flag handling as intended by osal
    bool v_Success_b = v_File_o.open_b(i_FileName_pc, e_FomRead | e_FomBinary);

    if (v_Success_b)
    {
      v_File_o.read_u64(&header_s, c_KTXHeaderSize_u32);
      
      v_Success_b = checkHeader_b();
      Assert(true == v_Success_b);

      // just skip the bytes of key value data, we don't care!
      v_File_o.seek_u64(header_s.bytesOfKeyValueData, e_FpCurrent);

      // allocate image data
    // PRQA S 3222 1 // this is fine here
      dataSize_u32 = static_cast<uint32_t>(v_File_o.getSize_u64() - v_File_o.getPosition_u64());
      data_pu8 = new uint8_t[dataSize_u32];
      uint8_t* v_CurrData_pu8 = data_pu8;
      uint32_t v_TotalDataSize_s32 = 0;

      // loop mip map levels
      for (uint32_t v_Level_u32 = 0U; v_Level_u32 < header_s.numberOfMipmapLevels; ++v_Level_u32)
      {
        uint32_t v_FaceLodSize_u32;
        v_File_o.read_u64(&v_FaceLodSize_u32, sizeof(uint32_t));

        if (header_s.endianness == c_KTXEndianRefRev_u32)
        {
          swapEndian32_v(&v_FaceLodSize_u32, 1);
        }

        uint32_t v_FaceLodSizeRounded_u32 = (v_FaceLodSize_u32 + 3) & ~static_cast<uint32_t>(3);

        // loop faces
        for (uint32_t v_Face_u32 = 0U; v_Face_u32 < header_s.numberOfFaces; ++v_Face_u32)
        {
          // advance data pointer
          v_TotalDataSize_s32 += v_FaceLodSizeRounded_u32;

          if (dataSize_u32 < v_TotalDataSize_s32)
          {
            break;
          }

          // Read face data
          v_File_o.read_u64(v_CurrData_pu8, v_FaceLodSizeRounded_u32);

          /* Perform endianness conversion on texture data */
          if ((header_s.endianness == c_KTXEndianRefRev_u32) && (header_s.glTypeSize == 2))
          {
            swapEndian16_v(reinterpret_cast<uint16_t*>(v_CurrData_pu8), v_FaceLodSize_u32 / 2);
          }
          else if ((header_s.endianness == c_KTXEndianRefRev_u32) && (header_s.glTypeSize == 4))
          {
            swapEndian32_v(reinterpret_cast<uint32_t*>(v_CurrData_pu8), v_FaceLodSize_u32 / 4);
          }
		  else
		  {
			  //Do nothing
		  }

          v_CurrData_pu8 += v_FaceLodSizeRounded_u32;


        } // for face
      } // for level

      
    } // if file 

    return v_Success_b;
  }

  void KTXFile::release_v()
  {
    if (NULL != data_pu8)
    {
      delete[] data_pu8;
      data_pu8 = NULL;
    }

    dataSize_u32 = 0U;
  }

  void KTXFile::getTextureDesc_v(TextureDesc_s& b_Desc_rs)const
  {
    b_Desc_rs.format_e          = getResourceFormat_e();
    b_Desc_rs.type_e            = texInfo_s.glTarget;
    b_Desc_rs.width_u32         = header_s.pixelWidth;
    b_Desc_rs.height_u32        = header_s.pixelHeight;
    b_Desc_rs.depth_u32         = header_s.pixelDepth;
    b_Desc_rs.numMipMaps_u32    = header_s.numberOfMipmapLevels;
    b_Desc_rs.numFaces_u32      = header_s.numberOfFaces;
  }

  uint8_t* KTXFile::getData_pu8() const
  {
    return data_pu8;
  }

  uint32_t KTXFile::getDataSize_u32() const
  {
    return dataSize_u32;
  }

  bool KTXFile::checkHeader_b()
  {
    bool v_Success_b = true;

    // Check if this is a ktx file
    uint8_t v_IdentifierRef_au8[c_KTXIdentifierSize_u32] = 
    {
      0xAB, 0x4B, 0x54, 0x58, 0x20, 0x31, 0x31, 0xBB, 0x0D, 0x0A, 0x1A, 0x0A
    };

    if (memcmp(header_s.identifier, &v_IdentifierRef_au8[0], c_KTXIdentifierSize_u32) != 0U)
    {
      v_Success_b = false;
    }

    if (header_s.endianness == c_KTXEndianRefRev_u32)
    {
      // Convert endianness of header fields.
      swapEndian32_v(&header_s.glType, 12);

      if ((header_s.glTypeSize != 1) &&
          (header_s.glTypeSize != 2) &&
          (header_s.glTypeSize != 4))
      {
        // Only 8-, 16-, and 32-bit types supported so far.
        v_Success_b = false;
      }
    }
    else if (header_s.endianness != c_KTXEndianRef_u32)
    {
      v_Success_b = false;
    }
	else
	{
		//Do nothing
	}
    
    // Check glType and glFormat
    texInfo_s.compressed = 0;
    if ((header_s.glType == 0) || (header_s.glFormat == 0))
    {
      if ((header_s.glType + header_s.glFormat) != 0)
      {
        // Either both or none of glType, glFormat must be zero.
        v_Success_b = false;
      }

      texInfo_s.compressed = 1;
    }

    // Check texture dimensions. KTX files can store 8 types of textures:
    // 1D, 2D, 3D, cube, and array variants of these. There is currently no GL extension for 3D array textures.
    if ((header_s.pixelWidth == 0) ||
        ((header_s.pixelDepth > 0) && (header_s.pixelHeight == 0)))
    {
      // texture must have width 
      // texture must have height if it has depth
      v_Success_b = false; 
    }

    texInfo_s.textureDimensions = 1;
    texInfo_s.glTarget = e_Tt1D;
    texInfo_s.generateMipmaps = 0;
    if (header_s.pixelHeight > 0)
    {
      texInfo_s.textureDimensions = 2;
      texInfo_s.glTarget = e_Tt2D;
    }
    if (header_s.pixelDepth > 0)
    {
      texInfo_s.textureDimensions = 3;
      texInfo_s.glTarget = e_Tt3D;
    }

    if (header_s.numberOfFaces == 6)
    {
      if (texInfo_s.textureDimensions == 2)
      {
        texInfo_s.glTarget = e_TtCube;
      }
      else
      {
        // cube map needs 2D faces
        v_Success_b = false;
      }
    }
    else if (header_s.numberOfFaces != 1)
    {
      // numberOfFaces must be either 1 or 6
      v_Success_b = false;
    }
	else
	{
		//Do nothing
	}

    // Check number of mipmap levels
    if (header_s.numberOfMipmapLevels == 0)
    {
      texInfo_s.generateMipmaps = 1;
      header_s.numberOfMipmapLevels = 1;
    }
    // This test works for arrays too because height or depth will be 0.
    uint32_t max_dim = mecl::math::max_x(mecl::math::max_x(header_s.pixelWidth, header_s.pixelHeight), header_s.pixelDepth);
    if (max_dim < (static_cast<uint32_t>(1) << (header_s.numberOfMipmapLevels - 1)))
    {
      // Can't have more mip levels than 1 + log2(max(width, height, depth))
      v_Success_b = false;
    }

    return v_Success_b;
  }

  mepl::PixelFormat_e KTXFile::getResourceFormat_e() const
  {
    using namespace mepl;
    // use hardcoded values here, because we don't want to include any OpeNGL header here to stay API-Independent.
    uint32_t v_GlFormat_u32 = header_s.glInternalFormat;

    // caution: use hex values here to avoid openGL header dependency
    switch (v_GlFormat_u32)
    {
    case 0x1907:
		{return e_RfR8G8B8; }   // GL_RGB
    case 0x1908:
		{return e_RfR8G8B8A8;}  // GL_RGBA
    case 0x8D64:
		{return e_RfEtc1;  }    // GL_ETC1_RGB8_OES
    case 0x1906:
		{return e_RfR8;   }     // GL_ALPHA
    case 0x1909:
		{return e_RfR8;  }      // GL_LUMINANCE
    case 0x881A:
		{return e_RfR16F;  }    // GL_R16F_EXT
    case 0x8051:
		{return e_RfR8G8B8;  }  // GL_RGB8_OES
    case 0x8058:
		{return e_RfR8G8B8A8;}  // GL_RGBA8_OES
    case 0x8040:
		{return e_RfR8;  }      // GL_LUMINANCE8_OES

    default:
		{
			Assert(false);
			return e_RfUnknown;
		}
    }
  }


  void KTXFile::swapEndian16_v(uint16_t* b_Data_pu16, sint32_t i_Count_u32)
  {
    for (sint32_t v_I_s32 = 0; v_I_s32 < i_Count_u32; ++v_I_s32)
    {
      uint16_t x = *b_Data_pu16;
      *b_Data_pu16++ = (x << 8) | (x >> 8);
    }
  }

  void KTXFile::swapEndian32_v(uint32_t* b_Data_pu32, sint32_t i_Count_u32)
  {
    for (sint32_t v_I_s32 = 0; v_I_s32 < i_Count_u32; ++v_I_s32)
    {
      uint32_t x = *b_Data_pu32;
      *b_Data_pu32++ = (x << 24) | ((x & 0xFF00) << 8) | ((x & 0xFF0000) >> 8) | (x >> 24);
    }
  }

} // namespace me3d