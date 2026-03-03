#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#ifdef USE_DEVIL_AND_FREETYPE

#include "CodeWriter.h"

#include <platform/PlatformAPI.h>

#include <IL/il.h>
#include <IL/ilu.h>

namespace tsdk
{

class ImageLoader
{
public:
  ImageLoader();
  ~ImageLoader();

  void clear_v();

  bool load_b(const char* i_Name_pc, bool i_Alpha_b = false);
  void save_v(const char* i_Name_pc);
  void exportCode_v(const char* i_FileName_pc, const char* i_NameSpace_pc);

  uint32_t getWidth_u32() const;
  uint32_t getHeight_u32() const;
  sint32_t getBytesPerPixel_s32() const;
  uint32_t getSize_u32() const;
  uint8_t* getData_pu8() const;
  const std::string& getName_ro() const;

  bool     hasAlpha_b() const;

private:
  void checkError_v() const;

private:
  ILuint imageID_u32;
  uint32_t width_u32;
  uint32_t height_u32;
  sint32_t bytesPerPixel_s32;
  uint32_t size_u32;
  uint8_t* data_pu8;
  std::string fileName_o;
  bool hasAlphaValue_b;
};

} // namespace tsdk

#endif

#endif
