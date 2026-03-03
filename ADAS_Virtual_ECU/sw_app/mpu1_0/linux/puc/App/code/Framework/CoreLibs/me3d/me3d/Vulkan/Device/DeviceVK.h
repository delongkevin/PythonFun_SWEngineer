//--------------------------------------------------------------------------                                                                                                           
/// @file DeviceVK.h                                                                         
/// @brief Vulkan implementation for Device3D
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DEVICE_VK_H
#define DEVICE_VK_H

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Common/Device/Device3D.h"
#include "Vulkan/VKIncludes.h"
#include "Vulkan/Device/SwapChainVK.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{
  typedef mepl::vector<VkQueueFamilyProperties> QueueFamiliyPropertiesList_t;
  typedef mepl::vector<mepl::string> ExtensionsList_t;

  struct QueueFamilyIndices_s 
  {
    uint32_t graphics_u32;
    uint32_t compute_u32;
    uint32_t transfer_u32;

    QueueFamilyIndices_s()
      : graphics_u32(0U)
      , compute_u32(0U)
      , transfer_u32(0U)
    {
    }
  };

  struct DepthStencil_s
  {
    VkImage         image_t;
    VkDeviceMemory  mem_t;
    VkImageView     view_t;

    DepthStencil_s()
      : image_t(VK_NULL_HANDLE)
      , mem_t(VK_NULL_HANDLE)
      , view_t(VK_NULL_HANDLE)
    {
    }
  };

  class DeviceVK : public Device3D
  {
  public:
    DeviceVK();
    virtual ~DeviceVK();

    virtual bool create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs);
    virtual void release_v();

    virtual void beginFrame_v();
    virtual void endFrame_v();

    virtual bool setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs);
    virtual bool getViewPort_b(ViewPortDesc_s& o_ViewPort_rs);

    virtual void clearScreen_v(uint32_t i_ClearFlags_u32, const Color& i_ClearColor_ro, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32);

    virtual void draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32);
    virtual void drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32);

    virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32);
    virtual bool setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32);

    uint32_t getMemoryType_u32(uint32_t i_TypeBits_u32, VkMemoryPropertyFlags i_Properties_e, VkBool32* b_MemTypeFound_pb = NULL);

  protected:
    // enable specific features here
    void getEnabledFeatures_v();

  private:
    bool createInstance_b();
    bool createPhysicalDevice_b();
    bool createLogicalDevice_b(const mepl::vector<const char_t*>& i_EnabledExtensions_ro, bool i_UseSwapChain_b, VkQueueFlags i_RequestedQueueTypes_t);
    uint32_t getQueueFamilyIndex_u32(VkQueueFlagBits i_QueueFlags_t);
    bool isExtensionSupported_b(const mepl::string& i_Extension_t);
    bool getSupportedDepthFormat_b();

    // prepare
    void setupSwapChain_v();
    void createCommandBuffers_v();
    void destroyCommandBuffers_v();
    // Setup default depth and stencil views
    void createDepthStencil_v();
    void destroyDepthStencil_v();
    // Create framebuffers for all requested swap chain images
    void createFrameBuffers_v();
    void destroyFrameBuffers_v();

    void setupRenderPass_v();
    void buildCommandBuffers_v();


  private:
    VkInstance                        instance_t;                 ///< Vulkan instance, stores all per-application states
    VkPhysicalDevice                  physicalDevice_t;           ///< Physical device (GPU) that Vulkan will use
    VkPhysicalDeviceProperties        properties_t;               ///< Stores physical device properties (for e.g. checking device limits)
    VkPhysicalDeviceFeatures          features_t;                 ///< Stores the features available on the selected physical device (for e.g. checking if a feature is available)
    VkPhysicalDeviceFeatures          enabledFeatures_t;          ///< Features that have been enabled for use on the physical device
    VkPhysicalDeviceMemoryProperties  memoryProperties_t;         ///< Stores all available memory (type) properties for the physical device
    QueueFamiliyPropertiesList_t      queueFamilyProperties_t;    ///< Queue family properties of the physical device
    ExtensionsList_t                  supportedExtensions_t;      ///< List of extensions supported by the device
    VkDevice                          logicalDevice_t;            ///< Logical device representation (application's view of the device)
    QueueFamilyIndices_s              queueFamilyIndices_s;       ///< Contains queue family indices
    bool_t                            enableDebugMarkers_b;       ///< False by default, Set to true when the debug marker extension is detected
    VkCommandPool                     graphicsCommandPool_t;      ///< Default command pool for the graphics queue family index
    VkQueue                           queue_t;                    ///< Handle to the device graphics queue that command buffers are submitted to
    VkFormat                          depthFormat_t;              ///< Depth buffer format (selected during Vulkan initialization)
    SwapChainVK                       swapChain_o;                ///< Encapsulates the Vulkan SwapChain
    VkSemaphore                       semaphorePresentComplete_t; ///< Swap chain image presentation
    VkSemaphore                       semaphoreRenderComplete_t;  ///< Command buffer submission and execution

    // Vulkan objects the whole Engine will need access to.
    VkCommandPool                     cmdPool_t;                  ///< Command buffer pool, used to create Command buffers
    mepl::vector<VkCommandBuffer>     drawCmdBuffers_at;          ///< Command buffers used for rendering
    mepl::vector<VkFence>             waitFences_at;              ///< Wait fences to sync command buffer access
    DepthStencil_s                    depthStencil_s;             ///< Depth Stencil
    VkRenderPass                      renderPass_t;               ///< Global render pass for frame buffer writes
    VkPipelineCache                   pipelineCache_t;            ///< Pipeline cache object
    mepl::vector<VkFramebuffer>       frameBuffers_at;            ///< List of available frame buffers (same as number of swap chain images)
    uint32_t                          currentBuffer_u32;          ///< active frame buffer index
  };

} // namespace me3d

#endif // RE_USE_VULKAN

#endif // DEVICEGLES_H