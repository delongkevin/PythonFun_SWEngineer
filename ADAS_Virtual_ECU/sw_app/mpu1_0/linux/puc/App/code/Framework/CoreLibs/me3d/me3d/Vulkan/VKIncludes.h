//--------------------------------------------------------------------------                                                                                                           
/// @file VKIncludes.h                                                                         
/// @brief Bundles all Vulkan includes
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef VK_INCLUDES_H
#define VK_INCLUDES_H

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include <platform/PlatformAPI.h>

// Determine the current platform
#ifdef ME_PLATFORM_WIN
#define VK_USE_PLATFORM_WIN32_KHR
#endif

// After that, include vulkan
#include "vulkan/vulkan.h"


#define VK_CHECK_RESULT(f)																				\
{																										\
  VkResult res = (f);																					\
  if (res != VK_SUCCESS)																				\
  {																									\
  ME_Debugger_F_Printf_v("Fatal : VkResult is %d \"\n", res); \
  Assert(res == VK_SUCCESS);																		\
  }																									\
}


// util debug functions
namespace me3d
{
  static PFN_vkCreateDebugReportCallbackEXT CreateDebugReportCallback = VK_NULL_HANDLE;
  static PFN_vkDestroyDebugReportCallbackEXT DestroyDebugReportCallback = VK_NULL_HANDLE;
  static PFN_vkDebugReportMessageEXT dbgBreakCallback = VK_NULL_HANDLE;

  static VkDebugReportCallbackEXT msgCallback = VK_NULL_HANDLE;

  static VKAPI_ATTR VkBool32 VKAPI_CALL messageCallback(
    VkDebugReportFlagsEXT flags,
    VkDebugReportObjectTypeEXT objType,
    uint64_t srcObject,
    size_t location,
    int32_t msgCode,
    const char* pLayerPrefix,
    const char* pMsg,
    void* pUserData)
  {
    // Select prefix depending on flags passed to the callback
    // Note that multiple flags may be set for a single validation message
    std::string prefix("");

    // Error that may result in undefined behaviour
    if (flags & VK_DEBUG_REPORT_ERROR_BIT_EXT)
    {
      prefix += "ERROR:";
    };
    // Warnings may hint at unexpected / non-spec API usage
    if (flags & VK_DEBUG_REPORT_WARNING_BIT_EXT)
    {
      prefix += "WARNING:";
    };
    // May indicate sub-optimal usage of the API
    if (flags & VK_DEBUG_REPORT_PERFORMANCE_WARNING_BIT_EXT)
    {
      prefix += "PERFORMANCE:";
    };
    // Informal messages that may become handy during debugging
    if (flags & VK_DEBUG_REPORT_INFORMATION_BIT_EXT)
    {
      prefix += "INFO:";
    }
    // Diagnostic info from the Vulkan loader and layers
    // Usually not helpful in terms of API usage, but may help to debug layer and loader problems 
    if (flags & VK_DEBUG_REPORT_DEBUG_BIT_EXT)
    {
      prefix += "DEBUG:";
    }

    ME_Debugger_F_Printf_v("%s [%s] Code %d : %s", prefix.c_str(), pLayerPrefix, msgCode, pMsg);
    //debugMessage << prefix << " [" << pLayerPrefix << "] Code " << msgCode << " : " << pMsg;
    //fflush(stdout);

    // The return value of this callback controls wether the Vulkan call that caused the validation message will be aborted or not
    // We return VK_FALSE as we DON'T want Vulkan calls that cause a validation message (and return a VkResult) to abort
    // If you instead want to have calls abort, pass in VK_TRUE and the function will return VK_ERROR_VALIDATION_FAILED_EXT 
    return VK_FALSE;
  }

  static void setupDebugging(VkInstance instance, VkDebugReportFlagsEXT flags, VkDebugReportCallbackEXT callBack)
  {
    CreateDebugReportCallback = reinterpret_cast<PFN_vkCreateDebugReportCallbackEXT>(vkGetInstanceProcAddr(instance, "vkCreateDebugReportCallbackEXT"));
    DestroyDebugReportCallback = reinterpret_cast<PFN_vkDestroyDebugReportCallbackEXT>(vkGetInstanceProcAddr(instance, "vkDestroyDebugReportCallbackEXT"));
    dbgBreakCallback = reinterpret_cast<PFN_vkDebugReportMessageEXT>(vkGetInstanceProcAddr(instance, "vkDebugReportMessageEXT"));

    VkDebugReportCallbackCreateInfoEXT dbgCreateInfo = {};
    dbgCreateInfo.sType = VK_STRUCTURE_TYPE_DEBUG_REPORT_CREATE_INFO_EXT;
    dbgCreateInfo.pfnCallback = (PFN_vkDebugReportCallbackEXT)messageCallback;
    dbgCreateInfo.flags = flags;

    VkResult err = CreateDebugReportCallback(
      instance,
      &dbgCreateInfo,
      NULL,
      (callBack != VK_NULL_HANDLE) ? &callBack : &msgCallback);
    Assert(!err);
  }

  static void freeDebugCallback(VkInstance instance)
  {
    if (msgCallback != VK_NULL_HANDLE)
    {
      DestroyDebugReportCallback(instance, msgCallback, nullptr);
    }
  }

}


#endif // RE_USE_VULKAN

#endif // DEVICEGLES_H