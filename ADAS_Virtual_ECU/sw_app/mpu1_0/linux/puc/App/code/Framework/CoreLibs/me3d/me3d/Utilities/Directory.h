#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <platform/PlatformAPI.h>

#include <stdlib.h>

namespace me3d
{
  const uint32_t c_MaxPathLength_u32 = 256;

class Directory
{

private:
  static void initialize_v();

public:
  static void setContentPath_v(const char* i_ContentPath_pc);
  static const char* getResourceFile_pc();
  static const char* getContentPath_pc();
  static const char* getTexturePath_pc();
  static const char* getShadersPath_pc();
  static const char* getModelsPath_pc();
  static const char* getMaterialsPath_pc();
  static const char* getScenesPath_pc();

  static void createShaderFilePath_pc(char* i_Buffer_pc, const char* i_FileName_pc);

private:
  static char     texturePath_ac  [c_MaxPathLength_u32];
  static char     shaderPath_ac   [c_MaxPathLength_u32];
  static char     materialsPath_ac[c_MaxPathLength_u32];
  static char     modelsPath_ac   [c_MaxPathLength_u32];
  static char     scenesPath_ac   [c_MaxPathLength_u32];
  static char     resourceFile_ac [c_MaxPathLength_u32];

  
  static char*    contentPath_pc;
  static bool     initialized_b;
};

} // namespace me3d

#endif
