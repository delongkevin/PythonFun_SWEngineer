#include "ImageLoader.h"

#ifdef USE_DEVIL_AND_FREETYPE


#include <iostream>
// #include <ios>
// #include <iosfwd>
// #include <iomanip>



namespace tsdk
{

ImageLoader::ImageLoader()
  : imageID_u32(0U)
  , width_u32(0U)
  , height_u32(0U)
  , bytesPerPixel_s32(0U)
  , size_u32(0U)
  , data_pu8(0U)
  , fileName_o()
  , hasAlphaValue_b(false)
{
  ilInit();
  iluInit();
}

ImageLoader::~ImageLoader()
{
  clear_v();
}

void ImageLoader::clear_v()
{
  // free image data
  ilDeleteImage(imageID_u32);
  data_pu8 = 0U;
}

bool ImageLoader::load_b(const char* i_Name, bool i_HasAlpha_b /* = false */)
{
  clear_v();

  ilGenImages(1, &imageID_u32);
  checkError_v();

  ilBindImage(imageID_u32);
  checkError_v();

  ILboolean v_success_b = ilLoadImage(i_Name);
  checkError_v();

  hasAlphaValue_b = i_HasAlpha_b;

  bytesPerPixel_s32 = ilGetInteger(IL_IMAGE_BPP);
  checkError_v();

  if (bytesPerPixel_s32 != 1)
  {
    if (bytesPerPixel_s32 == 4)
    {
      ilConvertImage(IL_RGBA, IL_UNSIGNED_BYTE);
    }
    else
    {
      ilConvertImage(IL_RGB, IL_UNSIGNED_BYTE);
    }
    checkError_v();
  }

  width_u32 = ilGetInteger(IL_IMAGE_WIDTH);
  checkError_v();

  height_u32 = ilGetInteger(IL_IMAGE_HEIGHT);
  checkError_v();



  data_pu8 = ilGetData();
  checkError_v();

  // calc size
  size_u32 = width_u32 * height_u32 * bytesPerPixel_s32 * sizeof(uint8_t);

  fileName_o = i_Name;

  //Assert(IL_TRUE == v_success_b);
  return IL_TRUE == v_success_b;
}

void ImageLoader::save_v(const char* i_Name_pc)
{
  Assert(imageID_u32 > 0);

  ilBindImage(imageID_u32);
  checkError_v();

  ilSaveImage(i_Name_pc);
  checkError_v();
}

void ImageLoader::exportCode_v(const char* i_FileName_pc, const char* i_NameSpace_pc)
{
  if (NULL == data_pu8)
  {
    return;
  }

  //for (uint32_t v_i_u32 = 0U; v_i_u32 < size_u32; v_i_u32 += 4)
  //{
  //  uint8_t valR = data_pu8[v_i_u32     ];
  //  uint8_t valG = data_pu8[v_i_u32 + 1U];
  //  uint8_t valB = data_pu8[v_i_u32 + 2U];
  //  uint8_t valA = data_pu8[v_i_u32 + 3U];
  //
  //  data_pu8[v_i_u32] = valB;
  //  data_pu8[v_i_u32 + 2U] = valR; 
  //}

  CodeWriter writer;

  std::vector<std::string> v_Includes_o;
  v_Includes_o.push_back("#include <platform/PlatformAPI.h>");
  v_Includes_o.push_back("#include <Common/ResourceHandler/ResourceHandler.h>");


  writer.begin_b(i_FileName_pc, i_NameSpace_pc, false, &v_Includes_o);

  std::vector<ImageHexValue_s> imageHexValues_o;
  imageHexValues_o.resize(size_u32);
  for(uint32_t i = 0; i < size_u32; i++) 
  {
    imageHexValues_o[i].val = data_pu8[i];
  }

  writer.setMaxArrayEntriesPerRow(width_u32);

  std::string imageSizeName = "C_ImageSize_u32";
  writer.writeValue(imageSizeName, size_u32, true, true);

  std::string imageDataName = "C_ImageData_au8";

  std::string arrayTypeName = "uint8_t";
  writer.writeArray(imageDataName, imageHexValues_o, &arrayTypeName, false, false, &imageSizeName);

  std::string imageWidthName = "C_ImageWidth_u32";
  writer.writeValue(imageWidthName, width_u32, true, true);

  std::string imageHeightName = "C_ImageHeight_u32";
  writer.writeValue(imageHeightName, height_u32, true, true);

  std::string fileNameName = "C_FileName_pc";
  writer.writeValue(fileNameName, i_NameSpace_pc, true, true);

  std::string hasAlphaName = "C_HasAlpha_b";
  writer.writeValue(hasAlphaName, hasAlphaValue_b, true, true);

  std::vector<std::string> registerParameters;
  registerParameters.push_back(imageDataName);
  registerParameters.push_back(imageSizeName);
  registerParameters.push_back(imageWidthName);
  registerParameters.push_back(imageHeightName);
  registerParameters.push_back(hasAlphaName);
  registerParameters.push_back(fileNameName);

  writer.declareVariable("S_RegisterTexture_o", "me3d::ResourceHandler", &registerParameters, false, true);

  writer.end_b();
}

uint32_t ImageLoader::getWidth_u32() const
{
  return width_u32;
}

uint32_t ImageLoader::getHeight_u32() const
{
  return height_u32;
}

sint32_t ImageLoader::getBytesPerPixel_s32() const
{
  return bytesPerPixel_s32;
}

uint32_t ImageLoader::getSize_u32() const
{
  return size_u32;
}

uint8_t* ImageLoader::getData_pu8() const
{
  return data_pu8;
}

const std::string& ImageLoader::getName_ro() const
{
  return fileName_o;
}

bool ImageLoader::hasAlpha_b() const
{
  return hasAlphaValue_b;
}

void ImageLoader::checkError_v() const
{
  ILenum Error = IL_NO_ERROR;
  while ((Error = ilGetError()) != IL_NO_ERROR) 
  {
    const char* errorString = iluErrorString(Error);
    printf("%d: %s/n", Error, errorString); 
    //OutputDebugString(iluErrorString(Error));
    //Assert(false);
  }

}

} // namespace tsdk

#endif
