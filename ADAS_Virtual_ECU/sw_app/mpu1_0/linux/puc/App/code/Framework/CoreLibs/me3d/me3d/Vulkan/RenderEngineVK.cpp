#include "RenderEngineVK.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Vulkan/Device/DeviceVK.h"
#include "Vulkan/Manager/ShaderManagerVK.h"
#include "Vulkan/Manager/TextureManagerVK.h"
#include "Vulkan/Manager/BufferManagerVK.h"


// PRQA S 5118 EOF // c++14 autosar standard permits

namespace me3d
{

  RenderEngineVK::RenderEngineVK()
    : RenderEngine()
  {

  }

  RenderEngineVK::~RenderEngineVK()
  {

  }

  Device3D* RenderEngineVK::createDevice_po()
  {
    return new DeviceVK();
  }

  IManager* RenderEngineVK::createManager_po(ManagerType_e i_Type_e)
  {
    IManager* v_Manager_po = NULL;

    switch (i_Type_e)
    {
     case e_MtBuffer:  v_Manager_po = new BufferManagerVK();   break;
     case e_MtTexture: v_Manager_po = new TextureManagerVK();  break;
     case e_MtShader:  v_Manager_po = new ShaderManagerVK();   break;
    }

    if (NULL == v_Manager_po)
    {
      v_Manager_po = RenderEngine::createManager_po(i_Type_e);
    }

    return v_Manager_po;
  }

} // namespace me3d


#endif // RE_USE_VULKAN


