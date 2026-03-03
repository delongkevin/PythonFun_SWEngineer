#include "SwapChainVK.h"

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

namespace me3d
{
  SwapChainVK::SwapChainVK()
    : instance_t()       
    , physicalDevice_t()  
    , logicalDevice_t()   
    , surface_t()
    , colorFormat_t()
    , colorSpace_t()
    , swapChain_t(VK_NULL_HANDLE)
    , imageCount_u32()
    , images_t()
    , buffers_t()
    , queueFamilyIndex_u32(UINT32_MAX)
    , fpGetPhysicalDeviceSurfaceSupportKHR(NULL)
    , fpGetPhysicalDeviceSurfaceCapabilitiesKHR(NULL)
    , fpGetPhysicalDeviceSurfaceFormatsKHR(NULL)
    , fpGetPhysicalDeviceSurfacePresentModesKHR(NULL)
    , fpCreateSwapchainKHR(NULL)
    , fpDestroySwapchainKHR(NULL)
    , fpGetSwapchainImagesKHR(NULL)
    , fpAcquireNextImageKHR(NULL)
    , fpQueuePresentKHR(NULL)
  {
  }

  SwapChainVK::~SwapChainVK()
  {

  }

  bool SwapChainVK::connect_b(VkInstance i_Instance_t, VkPhysicalDevice i_PhysicalDevice_t, VkDevice i_LogicalDevice_t)
  {
    instance_t = i_Instance_t;
    physicalDevice_t = i_PhysicalDevice_t;
    logicalDevice_t = i_LogicalDevice_t;

    fpGetPhysicalDeviceSurfaceSupportKHR      = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceSupportKHR>     (vkGetInstanceProcAddr(instance_t, "vkGetPhysicalDeviceSurfaceSupportKHR"));
    fpGetPhysicalDeviceSurfaceCapabilitiesKHR = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR>(vkGetInstanceProcAddr(instance_t, "vkGetPhysicalDeviceSurfaceCapabilitiesKHR"));
    fpGetPhysicalDeviceSurfaceFormatsKHR      = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfaceFormatsKHR>     (vkGetInstanceProcAddr(instance_t, "vkGetPhysicalDeviceSurfaceFormatsKHR"));
    fpGetPhysicalDeviceSurfacePresentModesKHR = reinterpret_cast<PFN_vkGetPhysicalDeviceSurfacePresentModesKHR>(vkGetInstanceProcAddr(instance_t, "vkGetPhysicalDeviceSurfacePresentModesKHR"));

    fpCreateSwapchainKHR    = reinterpret_cast<PFN_vkCreateSwapchainKHR>    (vkGetDeviceProcAddr(logicalDevice_t, "vkCreateSwapchainKHR"));
    fpDestroySwapchainKHR   = reinterpret_cast<PFN_vkDestroySwapchainKHR>   (vkGetDeviceProcAddr(logicalDevice_t, "vkDestroySwapchainKHR"));
    fpGetSwapchainImagesKHR = reinterpret_cast<PFN_vkGetSwapchainImagesKHR> (vkGetDeviceProcAddr(logicalDevice_t, "vkGetSwapchainImagesKHR"));
    fpAcquireNextImageKHR   = reinterpret_cast<PFN_vkAcquireNextImageKHR>   (vkGetDeviceProcAddr(logicalDevice_t, "vkAcquireNextImageKHR"));
    fpQueuePresentKHR       = reinterpret_cast<PFN_vkQueuePresentKHR>       (vkGetDeviceProcAddr(logicalDevice_t, "vkQueuePresentKHR"));


    bool v_Success_b = (NULL != fpGetPhysicalDeviceSurfaceSupportKHR);
    v_Success_b     &= (NULL != fpGetPhysicalDeviceSurfaceCapabilitiesKHR);
    v_Success_b     &= (NULL != fpGetPhysicalDeviceSurfaceFormatsKHR);
    v_Success_b     &= (NULL != fpGetPhysicalDeviceSurfacePresentModesKHR);

    v_Success_b     &= (NULL != fpCreateSwapchainKHR);
    v_Success_b     &= (NULL != fpDestroySwapchainKHR);
    v_Success_b     &= (NULL != fpGetSwapchainImagesKHR);
    v_Success_b     &= (NULL != fpAcquireNextImageKHR);
    v_Success_b     &= (NULL != fpQueuePresentKHR);

    return v_Success_b;
  }

  bool SwapChainVK::create_b(uint32_t* i_Width_pu32, uint32_t* i_Height_pu32, bool i_UseVSync_b)
  {
    VkSwapchainKHR oldSwapchain = swapChain_t;

    // Get physical device surface properties and formats
    VkSurfaceCapabilitiesKHR surfCaps;
    VK_CHECK_RESULT(fpGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice_t, surface_t, &surfCaps));

    // Get available present modes
    uint32_t presentModeCount;
    VK_CHECK_RESULT(fpGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice_t, surface_t, &presentModeCount, NULL));
    Assert(presentModeCount > 0);

    mepl::vector<VkPresentModeKHR> presentModes;
    presentModes.resize(presentModeCount);
    VK_CHECK_RESULT(fpGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice_t, surface_t, &presentModeCount, presentModes.data()));

    VkExtent2D swapchainExtent = {};
    // If width (and height) equals the special value 0xFFFFFFFF, the size of the surface will be set by the swapchain
    if (surfCaps.currentExtent.width == (uint32_t)-1)
    {
      // If the surface size is undefined, the size is set to
      // the size of the images requested.
      swapchainExtent.width = *i_Width_pu32;
      swapchainExtent.height = *i_Height_pu32;
    }
    else
    {
      // If the surface size is defined, the swap chain size must match
      swapchainExtent = surfCaps.currentExtent;
      *i_Width_pu32 = surfCaps.currentExtent.width;
      *i_Height_pu32 = surfCaps.currentExtent.height;
    }


    // Select a present mode for the swapchain

    // The VK_PRESENT_MODE_FIFO_KHR mode must always be present as per spec
    // This mode waits for the vertical blank ("v-sync")
    VkPresentModeKHR swapchainPresentMode = VK_PRESENT_MODE_FIFO_KHR;

    // If v-sync is not requested, try to find a mailbox mode
    // It's the lowest latency non-tearing present mode available
    if (!i_UseVSync_b)
    {
      for (size_t i = 0; i < presentModeCount; i++)
      {
        if (presentModes[i] == VK_PRESENT_MODE_MAILBOX_KHR)
        {
          swapchainPresentMode = VK_PRESENT_MODE_MAILBOX_KHR;
          break;
        }
        if ((swapchainPresentMode != VK_PRESENT_MODE_MAILBOX_KHR) && (presentModes[i] == VK_PRESENT_MODE_IMMEDIATE_KHR))
        {
          swapchainPresentMode = VK_PRESENT_MODE_IMMEDIATE_KHR;
        }
      }
    }

    // Determine the number of images
    uint32_t desiredNumberOfSwapchainImages = surfCaps.minImageCount + 1;
    if ((surfCaps.maxImageCount > 0) && (desiredNumberOfSwapchainImages > surfCaps.maxImageCount))
    {
      desiredNumberOfSwapchainImages = surfCaps.maxImageCount;
    }

    // Find the transformation of the surface
    VkSurfaceTransformFlagsKHR preTransform;
    if (surfCaps.supportedTransforms & VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR)
    {
      // We prefer a non-rotated transform
      preTransform = VK_SURFACE_TRANSFORM_IDENTITY_BIT_KHR;
    }
    else
    {
      preTransform = surfCaps.currentTransform;
    }

    // Find a supported composite alpha format (not all devices support alpha opaque)
    VkCompositeAlphaFlagBitsKHR compositeAlpha = VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR;
    // Simply select the first composite alpha format available
    std::vector<VkCompositeAlphaFlagBitsKHR> compositeAlphaFlags;
    compositeAlphaFlags.push_back(VK_COMPOSITE_ALPHA_OPAQUE_BIT_KHR);
    compositeAlphaFlags.push_back(VK_COMPOSITE_ALPHA_PRE_MULTIPLIED_BIT_KHR);
    compositeAlphaFlags.push_back(VK_COMPOSITE_ALPHA_POST_MULTIPLIED_BIT_KHR);
    compositeAlphaFlags.push_back(VK_COMPOSITE_ALPHA_INHERIT_BIT_KHR);


    for (std::vector<VkCompositeAlphaFlagBitsKHR>::iterator it = compositeAlphaFlags.begin(); it != compositeAlphaFlags.end(); ++it)
    {
      if (surfCaps.supportedCompositeAlpha & (*it)) 
      {
        compositeAlpha = (*it);
        break;
      };
    }

    VkExtent2D v_ImgExtent_t;
    v_ImgExtent_t.width = swapchainExtent.width;
    v_ImgExtent_t.height = swapchainExtent.height;

    VkSwapchainCreateInfoKHR swapchainCI = {};
    swapchainCI.sType = VK_STRUCTURE_TYPE_SWAPCHAIN_CREATE_INFO_KHR;
    swapchainCI.pNext = NULL;
    swapchainCI.surface = surface_t;
    swapchainCI.minImageCount = desiredNumberOfSwapchainImages;
    swapchainCI.imageFormat = colorFormat_t;
    swapchainCI.imageColorSpace = colorSpace_t;
    swapchainCI.imageExtent = v_ImgExtent_t;
    swapchainCI.imageUsage = VK_IMAGE_USAGE_COLOR_ATTACHMENT_BIT;
    swapchainCI.preTransform = (VkSurfaceTransformFlagBitsKHR)preTransform;
    swapchainCI.imageArrayLayers = 1;
    swapchainCI.imageSharingMode = VK_SHARING_MODE_EXCLUSIVE;
    swapchainCI.queueFamilyIndexCount = 0;
    swapchainCI.pQueueFamilyIndices = NULL;
    swapchainCI.presentMode = swapchainPresentMode;
    swapchainCI.oldSwapchain = oldSwapchain;
    // Setting clipped to VK_TRUE allows the implementation to discard rendering outside of the surface area
    swapchainCI.clipped = VK_TRUE;
    swapchainCI.compositeAlpha = compositeAlpha;

    // Enable transfer source on swap chain images if supported
    if (surfCaps.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_SRC_BIT) 
    {
      swapchainCI.imageUsage |= VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    }

    // Enable transfer destination on swap chain images if supported
    if (surfCaps.supportedUsageFlags & VK_IMAGE_USAGE_TRANSFER_DST_BIT) 
    {
      swapchainCI.imageUsage |= VK_IMAGE_USAGE_TRANSFER_DST_BIT;
    }

    VK_CHECK_RESULT(fpCreateSwapchainKHR(logicalDevice_t, &swapchainCI, NULL, &swapChain_t));

    // If an existing swap chain is re-created, destroy the old swap chain
    // This also cleans up all the presentable images
    if (oldSwapchain != VK_NULL_HANDLE) 
    { 
      for (uint32_t i = 0; i < imageCount_u32; i++)
      {
        vkDestroyImageView(logicalDevice_t, buffers_t[i].view_t, NULL);
      }
      fpDestroySwapchainKHR(logicalDevice_t, oldSwapchain, NULL);
    }
    VK_CHECK_RESULT(fpGetSwapchainImagesKHR(logicalDevice_t, swapChain_t, &imageCount_u32, NULL));

    // Get the swap chain images
    images_t.resize(imageCount_u32);
    VK_CHECK_RESULT(fpGetSwapchainImagesKHR(logicalDevice_t, swapChain_t, &imageCount_u32, images_t.data()));

    // Get the swap chain buffers containing the image and imageview
    buffers_t.resize(imageCount_u32);
    for (uint32_t i = 0; i < imageCount_u32; i++)
    {
      VkImageViewCreateInfo v_ColorAttachmentView_t = {};
      v_ColorAttachmentView_t.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
      v_ColorAttachmentView_t.pNext = NULL;
      v_ColorAttachmentView_t.format = colorFormat_t;
      v_ColorAttachmentView_t.components.r = VK_COMPONENT_SWIZZLE_R;
      v_ColorAttachmentView_t.components.g = VK_COMPONENT_SWIZZLE_G;
      v_ColorAttachmentView_t.components.b = VK_COMPONENT_SWIZZLE_B;
      v_ColorAttachmentView_t.components.a = VK_COMPONENT_SWIZZLE_A;
      v_ColorAttachmentView_t.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
      v_ColorAttachmentView_t.subresourceRange.baseMipLevel = 0;
      v_ColorAttachmentView_t.subresourceRange.levelCount = 1;
      v_ColorAttachmentView_t.subresourceRange.baseArrayLayer = 0;
      v_ColorAttachmentView_t.subresourceRange.layerCount = 1;
      v_ColorAttachmentView_t.viewType = VK_IMAGE_VIEW_TYPE_2D;
      v_ColorAttachmentView_t.flags = 0;

      buffers_t[i].image_t = images_t[i];

      v_ColorAttachmentView_t.image = buffers_t[i].image_t;

      VK_CHECK_RESULT(vkCreateImageView(logicalDevice_t, &v_ColorAttachmentView_t, NULL, &buffers_t[i].view_t));
    }

    return true;
  }

  void SwapChainVK::release_v()
  {
    if (VK_NULL_HANDLE != swapChain_t)
    {
      for (uint32_t v_I_u32 = 0; v_I_u32 < imageCount_u32; v_I_u32++)
      {
        vkDestroyImageView(logicalDevice_t, buffers_t[v_I_u32].view_t, NULL);
      }
    }

    if (VK_NULL_HANDLE != surface_t)
    {
      fpDestroySwapchainKHR(logicalDevice_t, swapChain_t, NULL);
      vkDestroySurfaceKHR(instance_t, surface_t, NULL);
    }

    surface_t   = VK_NULL_HANDLE;
    swapChain_t = VK_NULL_HANDLE;
  }

  VkResult SwapChainVK::acquireNextImage_e(VkSemaphore i_PresentCompleteSemaphore_t, uint32_t* i_ImageIndex_pu32)
  {
    // By setting timeout to UINT64_MAX we will always wait until the next image has been acquired or an actual error is thrown
    // With that we don't have to handle VK_NOT_READY
    return fpAcquireNextImageKHR(logicalDevice_t, swapChain_t, UINT64_MAX, i_PresentCompleteSemaphore_t, (VkFence)NULL, i_ImageIndex_pu32);
  }

  VkResult SwapChainVK::queuePresent_e(VkQueue i_Queue_t, uint32_t i_ImageIndex_u32, VkSemaphore i_WaitSemaphore_t)
  {
    VkPresentInfoKHR v_PresentInfo_t = {};
    v_PresentInfo_t.sType = VK_STRUCTURE_TYPE_PRESENT_INFO_KHR;
    v_PresentInfo_t.pNext = NULL;
    v_PresentInfo_t.swapchainCount = 1;
    v_PresentInfo_t.pSwapchains = &swapChain_t;
    v_PresentInfo_t.pImageIndices = &i_ImageIndex_u32;
    // Check if a wait semaphore has been specified to wait for before presenting the image
    if (i_WaitSemaphore_t != VK_NULL_HANDLE)
    {
      v_PresentInfo_t.pWaitSemaphores = &i_WaitSemaphore_t;
      v_PresentInfo_t.waitSemaphoreCount = 1;
    }

    return fpQueuePresentKHR(i_Queue_t, &v_PresentInfo_t);
  }

  void SwapChainVK::initSurface_v(void* i_PlatformHandle_pc, void* i_PlatformWindow_pv)
  {
    VkResult err = VK_SUCCESS;

    // Create the os-specific surface
#if defined(VK_USE_PLATFORM_WIN32_KHR)
    VkWin32SurfaceCreateInfoKHR v_SurfaceCreateInfo_t = {};
    v_SurfaceCreateInfo_t.sType = VK_STRUCTURE_TYPE_WIN32_SURFACE_CREATE_INFO_KHR;
    v_SurfaceCreateInfo_t.hwnd = (HWND)i_PlatformWindow_pv;
    v_SurfaceCreateInfo_t.hinstance = (HINSTANCE)GetWindowLong(v_SurfaceCreateInfo_t.hwnd, GWL_HINSTANCE);
    err = vkCreateWin32SurfaceKHR(instance_t, &v_SurfaceCreateInfo_t, NULL, &surface_t);
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
    VkAndroidSurfaceCreateInfoKHR v_SurfaceCreateInfo_t = {};
    v_SurfaceCreateInfo_t.sType = VK_STRUCTURE_TYPE_ANDROID_SURFACE_CREATE_INFO_KHR;
    v_SurfaceCreateInfo_t.window = i_PlatformWindow_pv;
    err = vkCreateAndroidSurfaceKHR(instance_t, &v_SurfaceCreateInfo_t, NULL, &surface_t);
#endif

    VK_CHECK_RESULT(err);


    // Get available queue family properties
    uint32_t v_QueueCount_u32;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice_t, &v_QueueCount_u32, NULL);
    Assert(v_QueueCount_u32 >= 1U);

    mepl::vector<VkQueueFamilyProperties> v_QueueProps_t;
    v_QueueProps_t.resize(v_QueueCount_u32);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice_t, &v_QueueCount_u32, v_QueueProps_t.data());

    // Iterate over each queue to learn whether it supports presenting:
    // Find a queue with present support Will be used to present the swap chain images to the windowing system
    mepl::vector<VkBool32> v_SupportsPresent_at;
    v_SupportsPresent_at.resize(v_QueueCount_u32);
    for (uint32_t v_I_u32 = 0; v_I_u32 < v_QueueCount_u32; ++v_I_u32) 
    {
      fpGetPhysicalDeviceSurfaceSupportKHR(physicalDevice_t, v_I_u32, surface_t, &v_SupportsPresent_at[v_I_u32]);
    }


    // Search for a graphics and a present queue in the array of queue families, try to find one that supports both
    uint32_t v_GraphicsQueueNodeIndex_u32 = UINT32_MAX;
    uint32_t v_PresentQueueNodeIndex_u32  = UINT32_MAX;
    for (uint32_t i = 0; i < v_QueueCount_u32; ++i) 
    {
      if ((v_QueueProps_t[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) != 0) 
      {
        if (v_GraphicsQueueNodeIndex_u32 == UINT32_MAX) 
        {
          v_GraphicsQueueNodeIndex_u32  = i;
        }

        if (v_SupportsPresent_at[i] == VK_TRUE) 
        {
          v_GraphicsQueueNodeIndex_u32  = i;
          v_PresentQueueNodeIndex_u32   = i;
          break;
        }
      }
    }
    if (v_PresentQueueNodeIndex_u32 == UINT32_MAX) 
    {	
      // If there's no queue that supports both present and graphics try to find a separate present queue
      for (uint32_t i = 0; i < v_QueueCount_u32; ++i) 
      {
        if (v_SupportsPresent_at[i] == VK_TRUE) 
        {
          v_PresentQueueNodeIndex_u32 = i;
          break;
        }
      }
    }

    // Exit if either a graphics or a presenting queue hasn't been found
    if (v_GraphicsQueueNodeIndex_u32 == UINT32_MAX || v_PresentQueueNodeIndex_u32 == UINT32_MAX) 
    {
      ME_Debugger_F_Printf_v("Could not find a graphics and/or presenting queue! \n");
      Assert(false);
    }

    // todo : Add support for separate graphics and presenting queue
    if (v_GraphicsQueueNodeIndex_u32 != v_PresentQueueNodeIndex_u32) 
    {
      ME_Debugger_F_Printf_v("Separate graphics and presenting queues are not supported yet!");
      Assert(false);
    }

    queueFamilyIndex_u32 = v_GraphicsQueueNodeIndex_u32;

    // Get list of supported surface formats and spaces
    uint32_t v_FormatCount_u32;
    VK_CHECK_RESULT(fpGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice_t, surface_t, &v_FormatCount_u32, NULL));
    Assert(v_FormatCount_u32 > 0U);

    mepl::vector<VkSurfaceFormatKHR> surfaceFormats;
    surfaceFormats.resize(v_FormatCount_u32);
    VK_CHECK_RESULT(fpGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice_t, surface_t, &v_FormatCount_u32, surfaceFormats.data()));

    // If the surface format list only includes one entry with VK_FORMAT_UNDEFINED, there is no preferred format, so we assume VK_FORMAT_B8G8R8A8_UNORM
    if ((v_FormatCount_u32 == 1) && (surfaceFormats[0].format == VK_FORMAT_UNDEFINED))
    {
      colorFormat_t = VK_FORMAT_B8G8R8A8_UNORM;
      colorSpace_t = surfaceFormats[0].colorSpace;
    }
    else
    {
      // iterate over the list of available surface format and check for the presence of VK_FORMAT_B8G8R8A8_UNORM
      bool v_Found_B8G8R8A8_UNORM_b = false;
      for (mepl::vector<VkSurfaceFormatKHR>::iterator it = surfaceFormats.begin(); it != surfaceFormats.end(); ++it)
      {
        if ((*it).format == VK_FORMAT_B8G8R8A8_UNORM)
        {
          colorFormat_t = (*it).format;
          colorSpace_t = (*it).colorSpace;
          v_Found_B8G8R8A8_UNORM_b = true;
          break;
        }
      }

      // in case VK_FORMAT_B8G8R8A8_UNORM is not available select the first available color format
      if (!v_Found_B8G8R8A8_UNORM_b)
      {
        colorFormat_t = surfaceFormats[0].format;
        colorSpace_t = surfaceFormats[0].colorSpace;
      }
    }

  }

  uint32_t SwapChainVK::getQueueFamilyIndex_u32() const
  {
    return queueFamilyIndex_u32;
  }

  uint32_t SwapChainVK::getImageCount_u32() const
  {
    return imageCount_u32;
  }

  VkFormat SwapChainVK::getColorFormat_t() const
  {
    return colorFormat_t;
  }

  const SwapChainBufferVector_t& SwapChainVK::getBuffers_t() const
  {
    return buffers_t;
  }

} // namespace me3d

#endif // RE_USE_VULKAN

