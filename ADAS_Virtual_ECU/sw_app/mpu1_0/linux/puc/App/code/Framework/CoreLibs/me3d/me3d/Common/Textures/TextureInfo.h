#ifndef TEXTURE_INFO_H
#define TEXTURE_INFO_H

#include <platform/PlatformAPI.h>


// PRQA S 1025 EOF // we are using c++14 autsoar standard, overriding non pure base class virtual fuinctions is allowed
// PRQA S 1034 EOF // we are using c++14 autsoar standard, overriding non pure base class virtual fuinctions is allowed

namespace me3d
{

#define ONE_MIPMAP_LEVEL            0xFFFF        // Create only one mip map level
#define ALL_MIPMAP_LEVEL            0xDFFF        // Create mip map levels up to 1x1
#define USE_MIPMAP_COUNT            0xCFFF        // Use the level count instead of the minimum mip map size to compute the level count

class TextureInfo
{
public:
  TextureInfo();
  ~TextureInfo();


  // Computes the number of mip map levels (from the min mip map size) to the assigned texture width and height
  static void computeMipMapLevelCount_v(uint32_t& o_LevelCount_u32, uint32_t i_MinMipMapSize_u32, uint32_t i_Width_u32, uint32_t i_Height_u32);
};

} // namespace me3d

#endif
