//--------------------------------------------------------------------------                                                                                                           
/// @file KTXTypes.h                                                                         
/// @brief Defines structs and constant unsed in KTXFile class. For more information, see
///        https://www.khronos.org/opengles/sdk/tools/KTX/file_format_spec/
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef KTX_TYPES_H
#define KTX_TYPES_H

#include <platform/PlatformAPI.h>

#include "Common/Device/Device3DTypes.h"

namespace me3d
{
  const uint32_t c_KTXEndianRef_u32       = 0x04030201U;  // big endian
  const uint32_t c_KTXEndianRefRev_u32    = 0x01020304U;  // little endian
  const uint32_t c_KTXHeaderSize_u32      = 64U;
  const uint32_t c_KTXIdentifierSize_u32  = 12U;

  struct KTXHeader_s
  {
    uint8_t  identifier[c_KTXIdentifierSize_u32];
    uint32_t endianness;
    uint32_t glType;
    uint32_t glTypeSize;
    uint32_t glFormat;
    uint32_t glInternalFormat;
    uint32_t glBaseInternalFormat;
    uint32_t pixelWidth;
    uint32_t pixelHeight;
    uint32_t pixelDepth;
    uint32_t numberOfArrayElements;
    uint32_t numberOfFaces;
    uint32_t numberOfMipmapLevels;
    uint32_t bytesOfKeyValueData;
  };

  struct KTXTexInfo_s
  {
    uint32_t textureDimensions;
    TextureType_e glTarget;
    uint32_t compressed;
    uint32_t generateMipmaps;
  };

} // namespace me3d

#endif