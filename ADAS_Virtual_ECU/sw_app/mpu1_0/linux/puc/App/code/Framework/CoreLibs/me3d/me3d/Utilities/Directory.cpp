#include "Utilities/Directory.h"

#include <string.h>

// PRQA S 3706 EOF // subscript operator ok here

namespace me3d
{
  char  Directory::texturePath_ac   [c_MaxPathLength_u32];
  char  Directory::shaderPath_ac    [c_MaxPathLength_u32];
  char  Directory::modelsPath_ac    [c_MaxPathLength_u32];
  char  Directory::materialsPath_ac [c_MaxPathLength_u32];
  char  Directory::scenesPath_ac    [c_MaxPathLength_u32];
  char  Directory::resourceFile_ac  [c_MaxPathLength_u32];

  char* Directory::contentPath_pc   = NULL;
  bool  Directory::initialized_b    = false;

  void Directory::initialize_v()
  {
    if (false == initialized_b)
    {
      initialized_b = true;

      // Get environment variable for the content path
      if (NULL == contentPath_pc)
      {
        
#ifdef ME_PLATFORM_WIN
        const char* targetPath = "C:/_mks/me3d/content";
#elif defined(ME_PLATFORM_QNX)
        const char* targetPath = "/usr/content";
#elif defined(ME_PLATFORM_LINUX)
        const char* targetPath = "/home/martin/git/PuC/App/code/OS/BSP/prebuilt/aarch64le/usr/content";
#elif defined(ME_PLATFORM_RTOS)
        const char* targetPath = "/home/martin/git/PuC/App/code/OS/BSP/prebuilt/aarch64le/usr/content";
#else
#error "Platform not supported"
#endif
        contentPath_pc = strdup(targetPath);

        uint32_t v_PathLength_u32 = strnlen(contentPath_pc, 1024U);
        for (uint32_t v_I_u32 = 0U; v_I_u32 < v_PathLength_u32; ++v_I_u32)
        {
          if (contentPath_pc[v_I_u32] == '\\')
          {
            contentPath_pc[v_I_u32] = '/';
          }
        }

      }

      if (NULL != contentPath_pc)
      {
        // Textures
        strncpy(&texturePath_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&texturePath_ac[0], "/textures", c_MaxPathLength_u32);

        // Shaders
        strncpy(&shaderPath_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&shaderPath_ac[0], "/Shaders", c_MaxPathLength_u32);

        // Models
        strncpy(&modelsPath_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&modelsPath_ac[0], "/models", c_MaxPathLength_u32);

        // Materials
        strncpy(&materialsPath_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&materialsPath_ac[0], "/materials", c_MaxPathLength_u32);

        // Scenes
        strncpy(&scenesPath_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&scenesPath_ac[0], "/scenes", c_MaxPathLength_u32);

        // Resource Files
        strncpy(&resourceFile_ac[0], contentPath_pc, c_MaxPathLength_u32);
        strncat(&resourceFile_ac[0], "/Resources", c_MaxPathLength_u32);

      }
    }
  }

  void Directory::setContentPath_v(const char* i_ContentPath_pc)
  {
    Assert(NULL != i_ContentPath_pc);
    contentPath_pc = strdup(i_ContentPath_pc);

    initialized_b = false;
  }


  const char* Directory::getResourceFile_pc()
  {
    initialize_v();

    return resourceFile_ac;
  }

  const char* Directory::getContentPath_pc()
  {
    initialize_v();

    return contentPath_pc;
  }

  const char* Directory::getTexturePath_pc()
  {
    initialize_v();

    return &texturePath_ac[0];
  }

  const char* Directory::getModelsPath_pc()
  {
    initialize_v();

    return &modelsPath_ac[0];
  }

  const char* Directory::getMaterialsPath_pc()
  {
    initialize_v();

    return &materialsPath_ac[0];
  }

  const char* Directory::getScenesPath_pc()
  {
    initialize_v();

    return &scenesPath_ac[0];
  }

  const char* Directory::getShadersPath_pc()
  {
    initialize_v();

    return &shaderPath_ac[0];
  }

  void Directory::createShaderFilePath_pc(char* i_Buffer_pc, const char* i_FileName_pc)
  {
    initialize_v();

    strncpy(i_Buffer_pc, &shaderPath_ac[0], c_MaxPathLength_u32);
    strncat(i_Buffer_pc, "/", c_MaxPathLength_u32);
    strncat(i_Buffer_pc, i_FileName_pc, c_MaxPathLength_u32);
  }

} // namespace me3d
