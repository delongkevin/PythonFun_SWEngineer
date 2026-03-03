#include "FontLoader.h"

#ifdef USE_DEVIL_AND_FREETYPE

#include "CodeWriter.h"
#include "StringUtils.h"

#include <mecl/math/Math.h>

#include <string.h>
#include <sstream>

namespace tsdk
{


FontLoader::FontLoader()
  : fileName_o()
  , fontAtlasWidth_u32(0U)
  , fontAtlasHeight_u32(0U)
{

}

FontLoader::~FontLoader()
{

}

bool FontLoader::load_b(const std::string& i_FileName_ro)
{
  fileName_o = i_FileName_ro;

  // init freetype library
  FT_Library ft;
  if (FT_Init_FreeType(&ft))
  {
    return false;
  }

  // init a new font
  FT_Face face;
  if (FT_New_Face(ft, i_FileName_ro.c_str(), 0, &face))
  {
    return false;
  }

  FT_Set_Pixel_Sizes(face, 0, 48);

  FT_GlyphSlot glyph = face->glyph;

  uint32_t rowWidth_u32   = 0U;
  uint32_t rowHeight_u32  = 0U;

  const uint32_t c_MaxWidth_u32 = 1024U;

  uint32_t roww = 0;
  uint32_t rowh = 0;


  /* Find minimum size for a texture holding all visible ASCII characters */
  for (int i = 0; i < c_MaxCharaters_u32; i++) 
  {
    if (FT_Load_Char(face, i, FT_LOAD_RENDER)) 
    {
      fprintf(stderr, "Loading character %c failed!\n", i);
      continue;
    }
    if (roww + glyph->bitmap.width + 1 >= c_MaxWidth_u32) 
    {
      fontAtlasWidth_u32 = mecl::math::max_x<uint32_t>(fontAtlasWidth_u32, roww);
      fontAtlasHeight_u32 += rowh;
      roww = 0;
      rowh = 0;
    }
    roww += glyph->bitmap.width + 1;
    rowh = mecl::math::max_x<uint32_t>(rowh, glyph->bitmap.rows);
  }

  fontAtlasWidth_u32 = mecl::math::max_x<uint32_t>(fontAtlasWidth_u32, roww);
  fontAtlasHeight_u32 += rowh;

  /* Clamping to edges is important to prevent artifacts when scaling */
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
  //Assert((glGetError()) == GL_NO_ERROR);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
  //Assert((glGetError()) == GL_NO_ERROR);
  //
  ///* Linear filtering usually looks best for text */
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  //Assert((glGetError()) == GL_NO_ERROR);
  //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //Assert((glGetError()) == GL_NO_ERROR);



  /* Paste all glyph bitmaps into the texture, remembering the offset */
  int ox = 0;
  int oy = 0;

  rowHeight_u32 = 0;

  for (uint32_t v_i_u32 = 0; v_i_u32 < c_MaxCharaters_u32; ++v_i_u32)
  {
    if (FT_Load_Char(face, v_i_u32, FT_LOAD_RENDER)) 
    {
      continue;
    }

    if (ox + glyph->bitmap.width + 1 >= c_MaxWidth_u32) 
    {
      oy += rowHeight_u32;
      rowHeight_u32 = 0;
      ox = 0;
    }

    charInfos_as[v_i_u32].xOffset_s32 = ox;
    charInfos_as[v_i_u32].yOffset_s32 = oy;

    charInfos_as[v_i_u32].buffer_pu8 = new uint8_t[glyph->bitmap.width * glyph->bitmap.rows];
    memcpy(charInfos_as[v_i_u32].buffer_pu8, glyph->bitmap.buffer, glyph->bitmap.width * glyph->bitmap.rows * sizeof(uint8_t));
 
    charInfos_as[v_i_u32].bufferWidth_s32 = glyph->bitmap.width;
    charInfos_as[v_i_u32].bufferHeight_s32 = glyph->bitmap.rows;
    charInfos_as[v_i_u32].ax_f32 = (float32_t)(glyph->advance.x >> 6);
    charInfos_as[v_i_u32].ay_f32 = (float32_t)(glyph->advance.y >> 6);
    charInfos_as[v_i_u32].bw_f32 = (float32_t)(glyph->bitmap.width);
    charInfos_as[v_i_u32].bh_f32 = (float32_t)(glyph->bitmap.rows);
    charInfos_as[v_i_u32].bl_f32 = (float32_t)(glyph->bitmap_left);
    charInfos_as[v_i_u32].bt_f32 = (float32_t)(glyph->bitmap_top);
    charInfos_as[v_i_u32].tx_f32 = ox / (float)fontAtlasWidth_u32;
    charInfos_as[v_i_u32].ty_f32 = oy / (float)fontAtlasHeight_u32;

    rowHeight_u32 = mecl::math::max_x<uint32_t>(rowHeight_u32, (uint32_t)glyph->bitmap.rows);
    ox += glyph->bitmap.width + 1;
  }

  return true;
}

void FontLoader::export_v()
{
  CodeWriter writer;

  std::string v_FileName_o = tsdk::StringUtils::getFileName_o(fileName_o);
  v_FileName_o = tsdk::StringUtils::removeExtension_o(v_FileName_o);

  std::vector<std::string> v_Includes_o;
  v_Includes_o.push_back("#include <platform/PlatformAPI.h>");
  v_Includes_o.push_back("#include <Common/ResourceHandler/ResourceHandler.h>");
  v_Includes_o.push_back("#include <Common/GUI/FontTypes.h>");

  writer.begin_b(v_FileName_o, v_FileName_o, false, &v_Includes_o);

  struct FontExportData_s
  {
    std::string imageDataName;
  };

  std::vector<FontExportData_s> fontExportData;
  fontExportData.resize(c_MaxCharaters_u32);

  // write image data
  for (uint32_t v_i_u32 = 0U; v_i_u32 < c_MaxCharaters_u32; ++v_i_u32)
  {
    std::string index = std::to_string((unsigned long long)v_i_u32);

    CharacterInfo_s* v_CharInfo_ps = &charInfos_as[v_i_u32];

    // write size
    std::string imageSizeName = "c_BufferSize" + index + "_u32";
    uint32_t v_Size_u32 = v_CharInfo_ps->bufferWidth_s32 * v_CharInfo_ps->bufferHeight_s32;
    if (v_Size_u32 != 0U)
    {
      writer.writeValue(imageSizeName, v_Size_u32, true, true);

      // write hex image data 
      std::vector<ImageHexValue_s> v_ImageHexData_o;
      v_ImageHexData_o.resize(v_Size_u32);

      for (uint32_t v_Pixel_u32 = 0U; v_Pixel_u32 < v_Size_u32; ++v_Pixel_u32)
      {
        v_ImageHexData_o[v_Pixel_u32].val = v_CharInfo_ps->buffer_pu8[v_Pixel_u32];
      }

      std::string imageDataName = "C_Buffer" + index + "_au8"; 
      std::string imageDataTypeName = "uint8_t";

      writer.setMaxArrayEntriesPerRow(v_CharInfo_ps->bufferWidth_s32);
      writer.writeArray(imageDataName , v_ImageHexData_o, &imageDataTypeName, false, false, &imageSizeName);

      fontExportData[v_i_u32].imageDataName = imageDataName;
    }
    else
    {
      fontExportData[v_i_u32].imageDataName = std::string("NULL");
    }
  }

  std::string maxCharInfosName = "C_MaxCharaters_u32";
  writer.writeValue(maxCharInfosName, c_MaxCharaters_u32, true, true);

  std::string characterInfosName = "C_CharacterInfos_as";
  writer.write("me3d::CharacterInfo_s " + characterInfosName + "[" + maxCharInfosName + "] = \n{\n");

  // write character info data
  std::stringstream stream;

  for (uint32_t v_i_u32 = 0U; v_i_u32 < c_MaxCharaters_u32; ++v_i_u32)
  {
    CharacterInfo_s* v_Data_ps = &charInfos_as[v_i_u32];

    stream << "  me3d::CharacterInfo_s(";
    stream << std::fixed;
    stream << v_Data_ps->ax_f32 << "F, " << v_Data_ps->ay_f32 << "F, " << v_Data_ps->bw_f32 << "F, " << v_Data_ps->bh_f32 << "F, ";
    stream << v_Data_ps->bl_f32 << "F, " << v_Data_ps->bt_f32 << "F, " << v_Data_ps->tx_f32 << "F, " << v_Data_ps->ty_f32 << "F, ";
    stream << v_Data_ps->xOffset_s32 << ", " << v_Data_ps->yOffset_s32 << ", ";
    stream << v_Data_ps->bufferWidth_s32 << ", " << v_Data_ps->bufferHeight_s32 << ", ";
    stream << fontExportData[v_i_u32].imageDataName;
    stream << "), \n";
  }

  writer.write(stream.str());

  writer.write("};", true);

  writer.newLine();

  std::string fontAtlasWidthName = "C_FontAtlasWidth_u32";
  writer.writeValue(fontAtlasWidthName, fontAtlasWidth_u32, true, true);

  std::string fontAtlasHeightName = "C_FontAtlasHeight_u32";
  writer.writeValue(fontAtlasHeightName, fontAtlasHeight_u32, true, true);

  std::string fileNameName = "C_FileName_pc";
  writer.writeValue(fileNameName, fileName_o.c_str(), true, true);

  std::vector<std::string> registerParameters;
  registerParameters.push_back(characterInfosName);
  registerParameters.push_back(maxCharInfosName);
  registerParameters.push_back(fontAtlasWidthName);
  registerParameters.push_back(fontAtlasHeightName);
  registerParameters.push_back(fileNameName);

  writer.declareVariable("S_RegisterFont_o", "me3d::ResourceHandler", &registerParameters, false, true);

  writer.end_b();
}

} // namespace tsdk

#endif
