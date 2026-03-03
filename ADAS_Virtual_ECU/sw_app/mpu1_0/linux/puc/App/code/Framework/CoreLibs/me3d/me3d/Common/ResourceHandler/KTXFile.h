//--------------------------------------------------------------------------                                                                                                           
/// @file ETC1Loader.h                                                                         
/// @brief Loads KTX Files. See loader.c in KtxLib https://github.com/KhronosGroup/KTX/tree/master/lib
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef KTX_FILE_H
#define KTX_FILE_H

#include "Common/ResourceHandler/KTXTypes.h"

namespace me3d
{
  class KTXFile
  {
  public:
    KTXFile();
    ~KTXFile();

    // loads ktx from file name
    bool load_b(const char* i_FileName_pc);

    // release data buffer
    void release_v();

    // fills the texture descriptor
    void getTextureDesc_v(TextureDesc_s& b_Desc_rs)const;

    // returns the pointer to image data
    uint8_t* getData_pu8() const;

    // returns the number of bytes for getData_pu8
    uint32_t getDataSize_u32() const;

  private:
    // Reads the KTX file header and performs some sanity checking on the values
    bool checkHeader_b();

    // map GL resource format to me3d resource format
    mepl::PixelFormat_e getResourceFormat_e() const;

    // Swaps endianness in an array of 16-bit values
    static void swapEndian16_v(uint16_t* b_Data_pu16, sint32_t i_Count_u32);

    // Swaps endianness in an array of 32-bit values
    static  void swapEndian32_v(uint32_t* b_Data_pu32, sint32_t i_Count_u32);

  private:
    KTXHeader_s   header_s;
    KTXTexInfo_s  texInfo_s;
    uint8_t*      data_pu8;
    uint32_t      dataSize_u32;
  };
} // namespace me3d

#endif