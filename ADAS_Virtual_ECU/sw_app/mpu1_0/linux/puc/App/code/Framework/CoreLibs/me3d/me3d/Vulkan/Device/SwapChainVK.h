//--------------------------------------------------------------------------                                                                                                           
/// @file SwapChainVK.h                                                                         
/// @brief Vulkan implementation for Swap Chain
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef SWAP_CHAIN_VK
#define SWAP_CHAIN_VK

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Vulkan/VKIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{
  struct SwapChainBuffer_s 
  {
    VkImage image_t;
    VkImageView view_t;
  };

  typedef mepl::vector<VkImage> ImageVector_t;
  typedef mepl::vector<SwapChainBuffer_s> SwapChainBufferVector_t;

  // Class wrapping access to the swap chain
  class SwapChainVK
  {
  public:
    SwapChainVK();
    virtual ~SwapChainVK();

    // --------------------------------------------------------------------------
    /// Set instance, physical and logical device to use for the swapchain and get all required function pointers
    ///
    /// @param[in] i_Instance_t Vulkan instance to use
    /// @param[in] i_PhysicalDevice_t Physical device used to query properties and formats relevant to the swapchain
    /// @param[in] i_LogicalDevice_t Logical representation of the device to create the swapchain for
    /// @return true if succeeded
    // --------------------------------------------------------------------------
    bool connect_b(VkInstance i_Instance_t, VkPhysicalDevice i_PhysicalDevice_t, VkDevice i_LogicalDevice_t);

    // --------------------------------------------------------------------------
    /// Create the swapchain and get it's images with given width and height
    ///
    /// @param[in,out] i_Width_pu32 Pointer to the width of the swapchain (may be adjusted to fit the requirements of the swapchain)
    /// @param[in,out] i_Height_pu32 Pointer to the height of the swapchain (may be adjusted to fit the requirements of the swapchain)
    /// @param[in] i_UseVSync_b Can be used to force vsync'd rendering (by using VK_PRESENT_MODE_FIFO_KHR as presentation mode)
    /// @return true if succeeded
    // --------------------------------------------------------------------------
    bool create_b(uint32_t* i_Width_pu32, uint32_t* i_Height_pu32, bool i_UseVSync_b);

    // --------------------------------------------------------------------------
    /// Destroy and free Vulkan resources used for the SwapChain
    // --------------------------------------------------------------------------
    void release_v();

    // --------------------------------------------------------------------------
    /// Acquires the next image in the swap chain
    ///
    /// @note The function will always wait until the next image has been acquired by setting timeout to UINT64_MAX
    /// 
    /// @param[in] i_PresentCompleteSemaphore_t Semaphore that is signaled when the image is ready for use
    /// @param[in,out] i_ImageIndex_pu32 Pointer to the image index that will be increased if the next image could be acquired
    /// @return VkResult VkResult of the image acquisition
    // --------------------------------------------------------------------------
    VkResult acquireNextImage_e(VkSemaphore i_PresentCompleteSemaphore_t, uint32_t* i_ImageIndex_pu32);

    // --------------------------------------------------------------------------
    /// Queues an image for presentation
    ///
    /// @param[in] i_Queue_t Presentation queue for presenting the image
    /// @param[in] i_ImageIndex_u32 Index of the swapchain image to queue for presentation
    /// @param[in] i_WaitSemaphore_t Semaphore that is waited on before the image is presented (only used if != VK_NULL_HANDLE)
    /// @return VkResult of the queue presentation
    // --------------------------------------------------------------------------
    VkResult queuePresent_e(VkQueue i_Queue_t, uint32_t i_ImageIndex_u32, VkSemaphore i_WaitSemaphore_t);

    // --------------------------------------------------------------------------
    // Creates the platform specific surface abstraction of the native platform window used for presentation
    // --------------------------------------------------------------------------
    void initSurface_v(void* i_PlatformHandle_pc, void* i_PlatformWindow_pv);

    // --------------------------------------------------------------------------
    // Queue family index of the detected graphics and presenting device queue
    // --------------------------------------------------------------------------
    uint32_t getQueueFamilyIndex_u32() const;

    // --------------------------------------------------------------------------
    // return the number of images in swap chain
    // --------------------------------------------------------------------------
    uint32_t getImageCount_u32() const;

    VkFormat getColorFormat_t() const;

    const SwapChainBufferVector_t& getBuffers_t() const;

  private:
    VkInstance                instance_t;       ///< Vulkan instance, stores all per-application states
    VkPhysicalDevice          physicalDevice_t; ///< Physical device used to query properties and formats relevant to the swapchain
    VkDevice                  logicalDevice_t;  ///< Logical representation of the device to create the swapchain for
    VkSurfaceKHR              surface_t;        ///< Vulkan Surface, operating system independent
    VkFormat                  colorFormat_t;
    VkColorSpaceKHR           colorSpace_t;
    VkSwapchainKHR            swapChain_t;	      ///< Handle to the current swap chain, required for recreation
    uint32_t                  imageCount_u32;
    ImageVector_t             images_t;
    SwapChainBufferVector_t   buffers_t;
    uint32_t                  queueFamilyIndex_u32; ///< Queue family index of the detected graphics and presenting device queue

  private:
    // swap chain related function pointers
    PFN_vkGetPhysicalDeviceSurfaceSupportKHR      fpGetPhysicalDeviceSurfaceSupportKHR;
    PFN_vkGetPhysicalDeviceSurfaceCapabilitiesKHR fpGetPhysicalDeviceSurfaceCapabilitiesKHR; 
    PFN_vkGetPhysicalDeviceSurfaceFormatsKHR      fpGetPhysicalDeviceSurfaceFormatsKHR;
    PFN_vkGetPhysicalDeviceSurfacePresentModesKHR fpGetPhysicalDeviceSurfacePresentModesKHR;
    PFN_vkCreateSwapchainKHR                      fpCreateSwapchainKHR;
    PFN_vkDestroySwapchainKHR                     fpDestroySwapchainKHR;
    PFN_vkGetSwapchainImagesKHR                   fpGetSwapchainImagesKHR;
    PFN_vkAcquireNextImageKHR                     fpAcquireNextImageKHR;
    PFN_vkQueuePresentKHR                         fpQueuePresentKHR;

  };

} // namespace me3d

#endif // RE_USE_VULKAN

#endif // SWAP_CHAIN_VK