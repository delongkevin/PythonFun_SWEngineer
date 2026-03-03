#include "DeviceVK.h"

// PRQA S 1051 EOF // Work in Progress.

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Common/RenderEngineTypes.h"

namespace me3d
{

  DeviceVK::DeviceVK()
    : Device3D()
    , instance_t(VkInstance())
    , physicalDevice_t(VkPhysicalDevice())
    , properties_t(VkPhysicalDeviceProperties())
    , features_t(VkPhysicalDeviceFeatures())
    , enabledFeatures_t(VkPhysicalDeviceFeatures())
    , memoryProperties_t(VkPhysicalDeviceMemoryProperties())
    , queueFamilyProperties_t()
    , supportedExtensions_t()
    , logicalDevice_t(VkDevice())
    , queueFamilyIndices_s()
    , enableDebugMarkers_b(false)
    , graphicsCommandPool_t(VK_NULL_HANDLE)
    , queue_t()
    , depthFormat_t()
    , swapChain_o()
  {

    currentBuffer_u32 = 0U;
  }

  DeviceVK::~DeviceVK()
  {


  }

  bool DeviceVK::create_b(RenderEngine* i_RenderEngine_po, const Device3DDesc_s& i_Desc_rs)
  {
    bool v_Success_b = Device3D::create_b(i_RenderEngine_po, i_Desc_rs);
    Assert(v_Success_b);

    if (true == v_Success_b)
    {
      v_Success_b = createInstance_b();
    }
    else
    {
      ME_Debugger_F_Printf_v("DeviceVK::createInstance_b failed \n");
    }

    if (true == v_Success_b)
    {
      v_Success_b = createPhysicalDevice_b();
    }
    else
    {
      ME_Debugger_F_Printf_v("DeviceVK::createPhysicalDevice_b failed \n");
    }

    if (true == v_Success_b)
    {
      // no device extensions, use swapchain and get Graphics and Compute queue
      mepl::vector<const char*> v_EnabledDeviceExtensions_t;
      v_Success_b = createLogicalDevice_b(v_EnabledDeviceExtensions_t, true, VK_QUEUE_GRAPHICS_BIT | VK_QUEUE_COMPUTE_BIT);
    }
    else
    {
      ME_Debugger_F_Printf_v("DeviceVK::createLogicalDevice_b failed \n");
    }

    if (true == v_Success_b)
    {
      // Get a graphics queue from the device
      vkGetDeviceQueue(logicalDevice_t, queueFamilyIndices_s.graphics_u32, 0, &queue_t);

      // Find a suitable depth format
      v_Success_b = getSupportedDepthFormat_b();
      Assert(v_Success_b);
    }
    else
    {
      ME_Debugger_F_Printf_v("DeviceVK::getSupportedDepthFormat_b failed \n");
    }

    if (true == v_Success_b)
    {
      v_Success_b = swapChain_o.connect_b(instance_t, physicalDevice_t, logicalDevice_t);
    }
    else
    {
      ME_Debugger_F_Printf_v("swapChain_o.connect_b failed \n");
    }

    if (true == v_Success_b)
    {
      // Create Semaphores
      VkSemaphoreCreateInfo v_SemaphoreCreateInfo_t = {};
      v_SemaphoreCreateInfo_t.sType                 = VK_STRUCTURE_TYPE_SEMAPHORE_CREATE_INFO;
      v_SemaphoreCreateInfo_t.pNext                 = NULL; 
      v_SemaphoreCreateInfo_t.flags                 = 0;     

      // Create a semaphore used to synchronize image presentation
      // Ensures that the image is displayed before we start submitting new commands to the queu
      VK_CHECK_RESULT(vkCreateSemaphore(logicalDevice_t, &v_SemaphoreCreateInfo_t, NULL, &semaphorePresentComplete_t));

      // Create a semaphore used to synchronize command submission
      // Ensures that the image is not presented until all commands have been sumbitted and executed
      VK_CHECK_RESULT(vkCreateSemaphore(logicalDevice_t, &v_SemaphoreCreateInfo_t, NULL, &semaphoreRenderComplete_t));


      // Set up submit info structure Semaphores will stay the same during application lifetime
      // Command buffer submission info is set by each Manager/renderer
      VkPipelineStageFlags v_SubmitPipelineStages_t = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
      VkSubmitInfo v_SubmitInfo_t           = {};
      v_SubmitInfo_t.sType                  = VK_STRUCTURE_TYPE_SUBMIT_INFO;
      v_SubmitInfo_t.pWaitDstStageMask      = &v_SubmitPipelineStages_t;
      v_SubmitInfo_t.waitSemaphoreCount     = 1;
      v_SubmitInfo_t.pWaitSemaphores        = &semaphorePresentComplete_t;
      v_SubmitInfo_t.signalSemaphoreCount   = 1;
      v_SubmitInfo_t.pSignalSemaphores      = &semaphoreRenderComplete_t;
    }

    // --- prepare ---

    // 1.) init swapchain
    swapChain_o.initSurface_v(device3DDesc_s.deviceHandle_pv, device3DDesc_s.windowHandle_pv);

    // 2.) create Command pool
    VkCommandPoolCreateInfo cmdPoolInfo = {};
    cmdPoolInfo.sType = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
    cmdPoolInfo.queueFamilyIndex = swapChain_o.getQueueFamilyIndex_u32(); 
    cmdPoolInfo.flags = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;
    VK_CHECK_RESULT(vkCreateCommandPool(logicalDevice_t, &cmdPoolInfo, NULL, &cmdPool_t));

    // 3.) setupSwapChain
    setupSwapChain_v();

    // 4.) createCommandBuffers for each swap chain image and reuse for rendering
    createCommandBuffers_v();

    // createSynchronizationPrimitives
    // Wait fences to sync command buffer access
    VkFenceCreateInfo fenceCreateInfo = {};
    fenceCreateInfo.sType = VK_STRUCTURE_TYPE_FENCE_CREATE_INFO;
    fenceCreateInfo.flags = VK_FENCE_CREATE_SIGNALED_BIT;

    waitFences_at.resize(drawCmdBuffers_at.size());
    for (mepl::vector<VkFence>::iterator it = waitFences_at.begin(); it != waitFences_at.end(); ++it)
    {
      VK_CHECK_RESULT(vkCreateFence(logicalDevice_t, &fenceCreateInfo, NULL, &(*it)));
    }

    // setupDepthStencil
    createDepthStencil_v();

    // setupRenderPass
    setupRenderPass_v();

    // createPipelineCache
    VkPipelineCacheCreateInfo pipelineCacheCreateInfo = {};
    pipelineCacheCreateInfo.sType = VK_STRUCTURE_TYPE_PIPELINE_CACHE_CREATE_INFO;
    VK_CHECK_RESULT(vkCreatePipelineCache(logicalDevice_t, &pipelineCacheCreateInfo, NULL, &pipelineCache_t));

    // setupFrameBuffer
    createFrameBuffers_v();


    buildCommandBuffers_v();

    return v_Success_b;
  }

  void DeviceVK::release_v()
  {
    // Flush device to make sure all resources can be freed
    if (logicalDevice_t != VK_NULL_HANDLE) 
    {
      vkDeviceWaitIdle(logicalDevice_t);
    }

     // Clean up Vulkan resources
     swapChain_o.release_v();
//     if (descriptorPool != VK_NULL_HANDLE)
//     {
//       vkDestroyDescriptorPool(device, descriptorPool, nullptr);
//     }
     destroyCommandBuffers_v();
     vkDestroyRenderPass(logicalDevice_t, renderPass_t, NULL);

     destroyFrameBuffers_v();
// 
//     for (auto& shaderModule : shaderModules)
//     {
//       vkDestroyShaderModule(logicalDevice_t, shaderModule, nullptr);
//     }
// 
     destroyDepthStencil_v();
 
     vkDestroyPipelineCache(logicalDevice_t, pipelineCache_t, NULL);
 
     vkDestroyCommandPool(logicalDevice_t, cmdPool_t, NULL);
 
     vkDestroySemaphore(logicalDevice_t, semaphorePresentComplete_t, NULL);
     vkDestroySemaphore(logicalDevice_t, semaphoreRenderComplete_t, NULL);

     for (mepl::vector<VkFence>::iterator it = waitFences_at.begin(); it != waitFences_at.end(); ++it)
     {
       vkDestroyFence(logicalDevice_t, (*it), NULL);
     }

    // logical device
    if (graphicsCommandPool_t)
    {
      vkDestroyCommandPool(logicalDevice_t, graphicsCommandPool_t, NULL);
    }
    if (logicalDevice_t)
    {
      vkDestroyDevice(logicalDevice_t, NULL);
    }

#ifdef ME_DEBUG
    freeDebugCallback(instance_t);
#endif // ME_DEBUG

    vkDestroyInstance(instance_t, NULL);
  }

  void DeviceVK::beginFrame_v()
  {
    Device3D::beginFrame_v();
  }

  void DeviceVK::endFrame_v()
  {
    // Get next image in the swap chain (back/front buffer)
    VK_CHECK_RESULT(swapChain_o.acquireNextImage_e(semaphorePresentComplete_t, &currentBuffer_u32));

    // Use a fence to wait until the command buffer has finished execution before using it again
    VK_CHECK_RESULT(vkWaitForFences(logicalDevice_t, 1, &waitFences_at[currentBuffer_u32], VK_TRUE, UINT64_MAX));
    VK_CHECK_RESULT(vkResetFences(logicalDevice_t, 1, &waitFences_at[currentBuffer_u32]));


    // Pipeline stage at which the queue submission will wait (via pWaitSemaphores)
    VkPipelineStageFlags waitStageMask = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    // The submit info structure specifices a command buffer queue submission batch
    VkSubmitInfo v_SubmitInfo_t = {};
    v_SubmitInfo_t.sType = VK_STRUCTURE_TYPE_SUBMIT_INFO;
    v_SubmitInfo_t.pWaitDstStageMask = &waitStageMask;									      // Pointer to the list of pipeline stages that the semaphore waits will occur at
    v_SubmitInfo_t.pWaitSemaphores = &semaphorePresentComplete_t;							// Semaphore(s) to wait upon before the submitted command buffer starts executing
    v_SubmitInfo_t.waitSemaphoreCount = 1;												            // One wait semaphore																				
    v_SubmitInfo_t.pSignalSemaphores = &semaphoreRenderComplete_t;						// Semaphore(s) to be signaled when command buffers have completed
    v_SubmitInfo_t.signalSemaphoreCount = 1;											            // One signal semaphore
    v_SubmitInfo_t.pCommandBuffers = &drawCmdBuffers_at[currentBuffer_u32];	  // Command buffers(s) to execute in this batch (submission)
    v_SubmitInfo_t.commandBufferCount = 1;												            // One command buffer

    // Submit to the graphics queue passing a wait fence
    VK_CHECK_RESULT(vkQueueSubmit(queue_t, 1, &v_SubmitInfo_t, waitFences_at[currentBuffer_u32]));

    // Present the current buffer to the swap chain
    // Pass the semaphore signaled by the command buffer submission from the submit info as the wait semaphore for swap chain presentation
    // This ensures that the image is not presented to the windowing system until all commands have been submitted
    VK_CHECK_RESULT(swapChain_o.queuePresent_e(queue_t, currentBuffer_u32, semaphoreRenderComplete_t));
  }

  bool DeviceVK::setViewPort_b(const ViewPortDesc_s& i_ViewPort_rs)
  {
    // on resize

    // Ensure all operations on the device have been finished before destroying resources
    vkDeviceWaitIdle(logicalDevice_t);

    // Recreate swap chain
    device3DDesc_s.screenWidth_u32 = i_ViewPort_rs.width_u32;
    device3DDesc_s.screenHeight_u32 = i_ViewPort_rs.height_u32;
    setupSwapChain_v();

    // Recreate the frame buffers
    destroyDepthStencil_v();
    createDepthStencil_v();	

    destroyFrameBuffers_v();
    createFrameBuffers_v();

    // Command buffers need to be recreated as they may store references to the recreated frame buffer
    destroyCommandBuffers_v();
    createCommandBuffers_v();
    buildCommandBuffers_v();

    vkDeviceWaitIdle(logicalDevice_t);

    return Device3D::setViewPort_b(i_ViewPort_rs);
  }

  bool DeviceVK::getViewPort_b(ViewPortDesc_s& o_ViewPort_rs)
  {
//     // get x, y, width, height
//     GLint v_ViewPort_ai[4];
//     glGetIntegerv(GL_VIEWPORT, &v_ViewPort_ai[0]);
//     Assert(getGLError_b() == false);
// 
//     o_ViewPort_rs.topLeftX_u32 = v_ViewPort_ai[0];
//     o_ViewPort_rs.topLeftY_u32 = v_ViewPort_ai[1];
//     o_ViewPort_rs.width_u32    = v_ViewPort_ai[2];
//     o_ViewPort_rs.height_u32   = v_ViewPort_ai[3];
// 
//     // get depth range
//     GLfloat v_DepthRange_af32[2];
//     glGetFloatv(GL_DEPTH_RANGE, &v_DepthRange_af32[0]);
//     Assert(getGLError_b() == false);
// 
//     o_ViewPort_rs.minDepth_f32 = v_DepthRange_af32[0];
//     o_ViewPort_rs.maxDepth_f32 = v_DepthRange_af32[1];

    return true;
  }

  void DeviceVK::clearScreen_v(uint32_t i_ClearFlags_u32, const Color& i_ClearColor_ro, float32_t i_ClearDepth_f32, uint32_t i_ClearStencil_u32, uint32_t i_Index_u32)
  {
//     uint32_t v_Flags_u32  = (e_RtfClearDepth   & i_ClearFlags_u32) ? GL_DEPTH_BUFFER_BIT   : 0;
//     v_Flags_u32 |= (e_RtfClearStencil & i_ClearFlags_u32) ? GL_STENCIL_BUFFER_BIT : 0;
//     v_Flags_u32 |= (e_RtfClearColor   & i_ClearFlags_u32) ? GL_COLOR_BUFFER_BIT   : 0;
// 
//     if (v_Flags_u32)
//     {
//       if (GL_COLOR_BUFFER_BIT & v_Flags_u32)
//       {
//         glClearColor(i_ClearColor_ro[0], i_ClearColor_ro[1], i_ClearColor_ro[2], i_ClearColor_ro[3]);
//         Assert(getGLError_b() == false);
//       }
// 
//       if (GL_STENCIL_BUFFER_BIT & v_Flags_u32)
//       {
//         glClearStencil(i_ClearStencil_u32);
//         Assert(getGLError_b() == false);
//       }
// 
//       if (GL_DEPTH_BUFFER_BIT & v_Flags_u32)
//       {
//         glClearDepthf(i_ClearDepth_f32);
//         Assert(getGLError_b() == false);
//       }
// 
//       glClear(v_Flags_u32);
//       Assert(getGLError_b() == false);
//     }
  }

  void DeviceVK::draw_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_VertexCnt_u32, uint32_t i_VertexOffset_u32)
  {
//     Device3D::draw_v(i_PrimitiveType_e, i_VertexCnt_u32, i_VertexOffset_u32);
// 
//     glDrawArrays(getGLPrimitiveType_e(i_PrimitiveType_e), i_VertexOffset_u32, i_VertexCnt_u32);
//     Assert(getGLError_b() == false);
  }

  void DeviceVK::drawIndexed_v(PrimitiveType_e i_PrimitiveType_e, uint32_t i_IndexCnt_u32, uint32_t i_IndexOffset_u32)
  {
//     Device3D::drawIndexed_v(i_PrimitiveType_e, i_IndexCnt_u32, i_IndexOffset_u32);
// 
//     // unsigned short stride is hardcoded atm
//     uint32_t v_IndexOffsetBytes_u32 = 2 * i_IndexOffset_u32;
// 
//     glDrawElements(getGLPrimitiveType_e(i_PrimitiveType_e), i_IndexCnt_u32, GL_UNSIGNED_SHORT, (char*)NULL + v_IndexOffsetBytes_u32);
//     Assert(getGLError_b() == false);
  }

  bool DeviceVK::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32)
  {
    bool v_Success_b = Device3D::setVertexBuffer_b(i_Buffer_po, i_Slot_u32, i_Offset_u32);

//     if (NULL != i_Buffer_po)
//     {
//       glBindBuffer(GL_ARRAY_BUFFER, i_Buffer_po->getID_u32());
//       Assert(getGLError_b() == false);
//     }
//     else
//     {
//       glBindBuffer(GL_ARRAY_BUFFER, 0U);
//     }

    return v_Success_b;
  }

  bool DeviceVK::setVertexBuffer_b(const VertexBuffer* i_Buffer_po, uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32)
  {
    bool v_Success_b = Device3D::setVertexBuffer_b(i_Buffer_po, i_Slot_u32, i_Offset_u32, i_Stride_u32);

//     if (NULL != i_Buffer_po)
//     {
//       glBindBuffer(GL_ARRAY_BUFFER, i_Buffer_po->getID_u32());
//       Assert(getGLError_b() == false);
//     }
//     else
//     {
//       glBindBuffer(GL_ARRAY_BUFFER, 0U);
//     }

    return v_Success_b;
  }

  uint32_t DeviceVK::getMemoryType_u32(uint32_t i_TypeBits_u32, VkMemoryPropertyFlags i_Properties_e, VkBool32* b_MemTypeFound_pb /*= NULL*/)
  {
    for (uint32_t i = 0; i < memoryProperties_t.memoryTypeCount; i++)
    {
      if ((i_TypeBits_u32 & 1) == 1)
      {
        if ((memoryProperties_t.memoryTypes[i].propertyFlags & i_Properties_e) == i_Properties_e)
        {
          if (b_MemTypeFound_pb)
          {
            *b_MemTypeFound_pb = true;
          }
          return i;
        }
      }
      i_TypeBits_u32 >>= 1;
    }

    if (b_MemTypeFound_pb)
    {
      *b_MemTypeFound_pb = false;
      return 0;
    }
    else
    {
      return UINT_MAX;
    }
  }

  void DeviceVK::getEnabledFeatures_v()
  {
    if (features_t.geometryShader) 
    {
      enabledFeatures_t.geometryShader = VK_TRUE;
    }
    else 
    {
      ME_Debugger_F_Printf_v("Selected GPU does not support geometry shaders! \n");
      Assert(false);
    }
  }

  bool DeviceVK::createInstance_b()
  {
    VkApplicationInfo v_AppInfo_t   = {};
    v_AppInfo_t.sType               = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    v_AppInfo_t.pApplicationName    = "Hello Vulkan";
    v_AppInfo_t.applicationVersion  = VK_MAKE_VERSION(1, 0, 0);
    v_AppInfo_t.pEngineName         = "View Engine";
    v_AppInfo_t.engineVersion       = VK_MAKE_VERSION(1, 0, 0);
    v_AppInfo_t.apiVersion          = VK_API_VERSION_1_0;

    const uint32_t c_NumMaxInstanceExtensions_u32 = 3;
    const char* c_InstanceExtensions_apc[c_NumMaxInstanceExtensions_u32];

    uint32_t v_InstExtCnt_u32 = 0;
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_SURFACE_EXTENSION_NAME;

#if defined(VK_USE_PLATFORM_WIN32_KHR)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_WIN32_SURFACE_EXTENSION_NAME;
#elif defined(VK_USE_PLATFORM_ANDROID_KHR)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_ANDROID_SURFACE_EXTENSION_NAME;
#elif defined(_DIRECT2DISPLAY)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_DISPLAY_EXTENSION_NAME;
#elif defined(VK_USE_PLATFORM_WAYLAND_KHR)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_WAYLAND_SURFACE_EXTENSION_NAME;
#elif defined(VK_USE_PLATFORM_XCB_KHR)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_KHR_XCB_SURFACE_EXTENSION_NAME;
#elif defined(VK_USE_PLATFORM_IOS_MVK)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_MVK_IOS_SURFACE_EXTENSION_NAME;
#elif defined(VK_USE_PLATFORM_MACOS_MVK)
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_MVK_MACOS_SURFACE_EXTENSION_NAME;
#endif

#ifdef ME_DEBUG
    c_InstanceExtensions_apc[v_InstExtCnt_u32++] = VK_EXT_DEBUG_REPORT_EXTENSION_NAME;
#endif


    VkInstanceCreateInfo v_CreateInfo_t     = {};
    v_CreateInfo_t.sType                    = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    v_CreateInfo_t.pNext                    = NULL;
    v_CreateInfo_t.pApplicationInfo         = &v_AppInfo_t;
    v_CreateInfo_t.enabledExtensionCount    = v_InstExtCnt_u32;
    v_CreateInfo_t.ppEnabledExtensionNames  = &c_InstanceExtensions_apc[0];

#ifdef ME_DEBUG

#if !defined(__ANDROID__)
    // On desktop the LunarG loaders exposes a meta layer that contains all layers
    uint32_t validationLayerCount = 1;
    const char *validationLayerNames[] = 
    {
      "VK_LAYER_LUNARG_standard_validation"
    };
#else
    // On Android we need to explicitly select all layers
    uint32_t validationLayerCount = 6;
    const char *validationLayerNames[] = 
    {
      "VK_LAYER_GOOGLE_threading",
      "VK_LAYER_LUNARG_parameter_validation",
      "VK_LAYER_LUNARG_object_tracker",
      "VK_LAYER_LUNARG_core_validation",
      "VK_LAYER_LUNARG_swapchain",
      "VK_LAYER_GOOGLE_unique_objects"
    };
#endif

    v_CreateInfo_t.enabledLayerCount        = validationLayerCount;
    v_CreateInfo_t.ppEnabledLayerNames      = validationLayerNames;

#endif // ME_DEBUG

    VkResult result = vkCreateInstance(&v_CreateInfo_t, NULL, &instance_t);

#ifdef ME_DEBUG
    // The report flags determine what type of messages for the layers will be displayed
    // For validating (debugging) an appplication the error and warning bits should suffice
    VkDebugReportFlagsEXT v_DebugReportFlags_t = VK_DEBUG_REPORT_ERROR_BIT_EXT | VK_DEBUG_REPORT_WARNING_BIT_EXT;
    // Additional flags include performance info, loader and layer debug messages, etc.
    setupDebugging(instance_t, v_DebugReportFlags_t, VK_NULL_HANDLE);

#endif // ME_DEBUG

    return (result == VK_SUCCESS);
  }

  bool DeviceVK::createPhysicalDevice_b()
  {
    // Select Physical Device
    uint32_t v_GpuCount_u32 = 0;

    // Get number of available physical devices
    VK_CHECK_RESULT(vkEnumeratePhysicalDevices(instance_t, &v_GpuCount_u32, NULL));
    ME_Debugger_F_Printf_v("Found %d GPU devices: \n", v_GpuCount_u32);
    Assert(v_GpuCount_u32 > 0);

    // Get the actual devices
    mepl::vector<VkPhysicalDevice> v_PhysicalDevices_t;
    v_PhysicalDevices_t.resize(v_GpuCount_u32);
    VK_CHECK_RESULT(vkEnumeratePhysicalDevices(instance_t, &v_GpuCount_u32, v_PhysicalDevices_t.data()));

#ifdef ME_DEBUG
    for (uint32_t v_I_u32 = 0; v_I_u32 < v_GpuCount_u32; v_I_u32++) 
    {
      VkPhysicalDeviceProperties v_DeviceProperties_t;
      vkGetPhysicalDeviceProperties(v_PhysicalDevices_t[v_I_u32], &v_DeviceProperties_t);
      ME_Debugger_F_Printf_v("Device[%d] : %s \nType: %d \nAPI: %d.%d.%d \n", 
        v_I_u32, 
        &v_DeviceProperties_t.deviceName[0],
        static_cast<sint32_t>(v_DeviceProperties_t.deviceType), 
        (v_DeviceProperties_t.apiVersion >> 22),
        ((v_DeviceProperties_t.apiVersion >> 12) & 0x3ff),
        (v_DeviceProperties_t.apiVersion & 0xfff) 
        );
    }
#endif


    // Defaults to the first device unless specified else (TODO)
    uint32_t v_SelectedDevice_u32 = 0;
    physicalDevice_t = v_PhysicalDevices_t[v_SelectedDevice_u32];

    // Store Properties features, limits and (sparse) properties of the physical device for later use
    vkGetPhysicalDeviceProperties(physicalDevice_t, &properties_t);

    // Features should be checked before using them
    vkGetPhysicalDeviceFeatures(physicalDevice_t, &features_t);

    // Memory properties are used regularly for creating all kinds of buffers
    vkGetPhysicalDeviceMemoryProperties(physicalDevice_t, &memoryProperties_t);


    // Get Required Extensions
    getEnabledFeatures_v();


    // Queue family properties, used for setting up requested queues upon device creation
    uint32_t v_QueueFamilyCount_u32;
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice_t, &v_QueueFamilyCount_u32, NULL);
    Assert(v_QueueFamilyCount_u32 > 0U);
    queueFamilyProperties_t.resize(v_QueueFamilyCount_u32);
    vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice_t, &v_QueueFamilyCount_u32, queueFamilyProperties_t.data());

    // Get list of supported extensions
    uint32_t v_ExtensionsCount_u32 = 0;
    vkEnumerateDeviceExtensionProperties(physicalDevice_t, NULL, &v_ExtensionsCount_u32, NULL);

    if (v_ExtensionsCount_u32 > 0)
    {
      mepl::vector<VkExtensionProperties> v_Extensions_t;
      v_Extensions_t.resize(v_ExtensionsCount_u32);
      if (vkEnumerateDeviceExtensionProperties(physicalDevice_t, NULL, &v_ExtensionsCount_u32, &v_Extensions_t.front()) == VK_SUCCESS)
      {
        for (size_t v_I_u32 = 0U; v_I_u32 < v_Extensions_t.size(); ++v_I_u32)
        {
          supportedExtensions_t.push_back(v_Extensions_t[v_I_u32].extensionName);
        }
      }
    }

#ifdef ME_DEBUG
    // print supported extensions
    ME_Debugger_F_Printf_v(" %d Extensions found: \n ", supportedExtensions_t.size());
    for (size_t v_I_u32 = 0U; v_I_u32 < supportedExtensions_t.size(); ++v_I_u32)
    {
      ME_Debugger_F_Printf_v("[%d] %s \n ", v_I_u32, supportedExtensions_t[v_I_u32].c_str());
    }
#endif

    return true;
  }


  bool DeviceVK::createLogicalDevice_b(const mepl::vector<const char_t*>& i_EnabledExtensions_ro, bool i_UseSwapChain_b, VkQueueFlags i_RequestedQueueTypes_t)
  {
    // 1.) Check Queues
    mepl::vector<VkDeviceQueueCreateInfo> v_QueueCreateInfos_t;
    const float32_t c_DefaultQueuePriority_f32 = 0.0F;

    // Graphics queue
    if (i_RequestedQueueTypes_t & VK_QUEUE_GRAPHICS_BIT)
    {
      queueFamilyIndices_s.graphics_u32 = getQueueFamilyIndex_u32(VK_QUEUE_GRAPHICS_BIT);

      VkDeviceQueueCreateInfo queueInfo = {};
      queueInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
      queueInfo.pNext                   = NULL;
      queueInfo.flags                   = 0;
      queueInfo.queueFamilyIndex        = queueFamilyIndices_s.graphics_u32;
      queueInfo.queueCount              = 1;
      queueInfo.pQueuePriorities        = &c_DefaultQueuePriority_f32;

      v_QueueCreateInfos_t.push_back(queueInfo);
    }
    else
    {
      queueFamilyIndices_s.graphics_u32 = VK_NULL_HANDLE;
    }

    // Compute queue
    if (i_RequestedQueueTypes_t & VK_QUEUE_COMPUTE_BIT)
    {
      queueFamilyIndices_s.compute_u32 = getQueueFamilyIndex_u32(VK_QUEUE_COMPUTE_BIT);

      if (queueFamilyIndices_s.compute_u32 != queueFamilyIndices_s.graphics_u32)
      {
        // If compute family index differs, we need an additional queue create info for the compute queue
        VkDeviceQueueCreateInfo queueInfo = {};
        queueInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueInfo.pNext                   = NULL;
        queueInfo.flags                   = 0;
        queueInfo.queueFamilyIndex        = queueFamilyIndices_s.compute_u32;
        queueInfo.queueCount              = 1;
        queueInfo.pQueuePriorities        = &c_DefaultQueuePriority_f32;

        v_QueueCreateInfos_t.push_back(queueInfo);
      }
    }
    else
    {
      // Else we use the same queue
      queueFamilyIndices_s.compute_u32 = queueFamilyIndices_s.graphics_u32;
    }

    // Transfer queue
    if (i_RequestedQueueTypes_t & VK_QUEUE_TRANSFER_BIT)
    {
      queueFamilyIndices_s.transfer_u32 = getQueueFamilyIndex_u32(VK_QUEUE_TRANSFER_BIT);

      if ((queueFamilyIndices_s.transfer_u32 != queueFamilyIndices_s.graphics_u32) && (queueFamilyIndices_s.transfer_u32 != queueFamilyIndices_s.compute_u32))
      {
        // If compute family index differs, we need an additional queue create info for the compute queue
        VkDeviceQueueCreateInfo queueInfo = {};
        queueInfo.sType                   = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
        queueInfo.pNext                   = NULL;
        queueInfo.flags                   = 0;
        queueInfo.queueFamilyIndex        = queueFamilyIndices_s.transfer_u32;
        queueInfo.queueCount              = 1;
        queueInfo.pQueuePriorities        = &c_DefaultQueuePriority_f32;

        v_QueueCreateInfos_t.push_back(queueInfo);
      }
    }
    else
    {
      // Else we use the same queue
      queueFamilyIndices_s.transfer_u32 = queueFamilyIndices_s.graphics_u32;
    }

    // 2.) Create the logical Device representation
    mepl::vector<const char*> deviceExtensions(i_EnabledExtensions_ro);
    if (i_UseSwapChain_b)
    {
      // If the device will be used for presenting to a display via a swapchain we need to request the swapchain extension
      deviceExtensions.push_back(VK_KHR_SWAPCHAIN_EXTENSION_NAME);
    }

    VkDeviceCreateInfo deviceCreateInfo   = {};
    deviceCreateInfo.sType                = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;
    deviceCreateInfo.queueCreateInfoCount = static_cast<uint32_t>(v_QueueCreateInfos_t.size());;
    deviceCreateInfo.pQueueCreateInfos    = v_QueueCreateInfos_t.data();
    deviceCreateInfo.pEnabledFeatures     = &enabledFeatures_t;

    // Enable the debug marker extension if it is present (likely meaning a debugging tool is present)
    if (isExtensionSupported_b(VK_EXT_DEBUG_MARKER_EXTENSION_NAME))
    {
      deviceExtensions.push_back(VK_EXT_DEBUG_MARKER_EXTENSION_NAME);
      enableDebugMarkers_b = true;
    }

    if (deviceExtensions.size() > 0)
    {
      deviceCreateInfo.enabledExtensionCount    = (uint32_t)deviceExtensions.size();
      deviceCreateInfo.ppEnabledExtensionNames  = deviceExtensions.data();
    }

    VkResult result = vkCreateDevice(physicalDevice_t, &deviceCreateInfo, NULL, &logicalDevice_t);
    VK_CHECK_RESULT(result)

    // 3.) Create a default command pool for graphics
    if (result == VK_SUCCESS)
    {
      // Create a default command pool for graphics command buffers
      VkCommandPoolCreateInfo cmdPoolInfo = {};
      cmdPoolInfo.sType                   = VK_STRUCTURE_TYPE_COMMAND_POOL_CREATE_INFO;
      cmdPoolInfo.queueFamilyIndex        = queueFamilyIndices_s.graphics_u32;
      cmdPoolInfo.flags                   = VK_COMMAND_POOL_CREATE_RESET_COMMAND_BUFFER_BIT;

      result = vkCreateCommandPool(logicalDevice_t, &cmdPoolInfo, NULL, &graphicsCommandPool_t);

      VK_CHECK_RESULT(result);
    }

    return (result == VK_SUCCESS);
  }

  uint32_t DeviceVK::getQueueFamilyIndex_u32(VkQueueFlagBits i_QueueFlags_t)
  {
    // Try to find a queue family index that supports compute but not graphics
    if (i_QueueFlags_t & VK_QUEUE_COMPUTE_BIT)
    {
      for (uint32_t v_I_u32 = 0; v_I_u32 < static_cast<uint32_t>(queueFamilyProperties_t.size()); ++v_I_u32)
      {
        if ((queueFamilyProperties_t[v_I_u32].queueFlags & i_QueueFlags_t) && 
           ((queueFamilyProperties_t[v_I_u32].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0))
        {
          return v_I_u32;
          break;
        }
      }
    }

    // Try to find a queue family index that supports transfer but not graphics and compute
    if (i_QueueFlags_t & VK_QUEUE_TRANSFER_BIT)
    {
      for (uint32_t v_I_u32 = 0; v_I_u32 < static_cast<uint32_t>(queueFamilyProperties_t.size()); ++v_I_u32)
      {
        if ((queueFamilyProperties_t[v_I_u32].queueFlags & i_QueueFlags_t) && 
           ((queueFamilyProperties_t[v_I_u32].queueFlags & VK_QUEUE_GRAPHICS_BIT) == 0) && 
           ((queueFamilyProperties_t[v_I_u32].queueFlags & VK_QUEUE_COMPUTE_BIT) == 0))
        {
          return v_I_u32;
          break;
        }
      }
    }

    // For other queue types or if no separate compute queue is present, return the first one to support the requested flags
    for (uint32_t v_I_u32 = 0; v_I_u32 < static_cast<uint32_t>(queueFamilyProperties_t.size()); ++v_I_u32)
    {
      if (queueFamilyProperties_t[v_I_u32].queueFlags & i_QueueFlags_t)
      {
        return v_I_u32;
        break;
      }
    }

    ME_Debugger_F_Printf_v("Could not find a matching queue family index \n");
    Assert(false);

    return 0;
  }

  bool DeviceVK::isExtensionSupported_b(const mepl::string& i_Extension_t)
  {
    return (std::find(supportedExtensions_t.begin(), supportedExtensions_t.end(), i_Extension_t) != supportedExtensions_t.end());
  }

  bool DeviceVK::getSupportedDepthFormat_b()
  {
    // Since all depth formats may be optional, we need to find a suitable depth format to use
    // Start with the highest precision packed format+
    const uint32_t c_DepthFormatCnt_u32 = 5U;
    VkFormat depthFormats[c_DepthFormatCnt_u32] = 
    {
      VK_FORMAT_D32_SFLOAT_S8_UINT,
      VK_FORMAT_D32_SFLOAT,
      VK_FORMAT_D24_UNORM_S8_UINT,
      VK_FORMAT_D16_UNORM_S8_UINT,
      VK_FORMAT_D16_UNORM
    };

    for (uint32_t v_I_u32 = 0U; v_I_u32 < c_DepthFormatCnt_u32; ++v_I_u32)
    {
      VkFormat v_Format_t = depthFormats[v_I_u32];

      VkFormatProperties v_FormatProps_t;
      vkGetPhysicalDeviceFormatProperties(physicalDevice_t, v_Format_t, &v_FormatProps_t);
      // Format must support depth stencil attachment for optimal tiling
      if (v_FormatProps_t.optimalTilingFeatures & VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT)
      {
        depthFormat_t = v_Format_t;
        return true;
      }
    }

    return false;
  }

  void DeviceVK::setupSwapChain_v()
  {
    swapChain_o.create_b(&device3DDesc_s.screenWidth_u32, &device3DDesc_s.screenHeight_u32, false);
  }

  void DeviceVK::createCommandBuffers_v()
  {
    drawCmdBuffers_at.resize(swapChain_o.getImageCount_u32());

    VkCommandBufferAllocateInfo v_CmdBufAllocateInfo_t  = {};
    v_CmdBufAllocateInfo_t.sType                        = VK_STRUCTURE_TYPE_COMMAND_BUFFER_ALLOCATE_INFO;
    v_CmdBufAllocateInfo_t.commandPool                  = cmdPool_t;
    v_CmdBufAllocateInfo_t.level                        = VK_COMMAND_BUFFER_LEVEL_PRIMARY;
    v_CmdBufAllocateInfo_t.commandBufferCount           = static_cast<uint32_t>(drawCmdBuffers_at.size());

    VK_CHECK_RESULT(vkAllocateCommandBuffers(logicalDevice_t, &v_CmdBufAllocateInfo_t, drawCmdBuffers_at.data()));
  }

  void DeviceVK::destroyCommandBuffers_v()
  {
    vkFreeCommandBuffers(logicalDevice_t, cmdPool_t, static_cast<uint32_t>(drawCmdBuffers_at.size()), drawCmdBuffers_at.data());
  }

  void DeviceVK::createDepthStencil_v()
  {
    VkExtent3D v_Extent3D_t;
    v_Extent3D_t.width  = device3DDesc_s.screenWidth_u32;
    v_Extent3D_t.height = device3DDesc_s.screenHeight_u32;
    v_Extent3D_t.depth  = 1;

    VkImageCreateInfo imageCI = {};
    imageCI.sType             = VK_STRUCTURE_TYPE_IMAGE_CREATE_INFO;
    imageCI.imageType         = VK_IMAGE_TYPE_2D;
    imageCI.format            = depthFormat_t;
    imageCI.extent            = v_Extent3D_t;
    imageCI.mipLevels         = 1;
    imageCI.arrayLayers       = 1;
    imageCI.samples           = VK_SAMPLE_COUNT_1_BIT;
    imageCI.tiling            = VK_IMAGE_TILING_OPTIMAL;
    imageCI.usage             = VK_IMAGE_USAGE_DEPTH_STENCIL_ATTACHMENT_BIT | VK_IMAGE_USAGE_TRANSFER_SRC_BIT;
    VK_CHECK_RESULT(vkCreateImage(logicalDevice_t, &imageCI, NULL, &depthStencil_s.image_t));

    VkMemoryRequirements v_MemReqs_t = {};
    vkGetImageMemoryRequirements(logicalDevice_t, depthStencil_s.image_t, &v_MemReqs_t);

    VkMemoryAllocateInfo v_MemAllloc_t = {};
    v_MemAllloc_t.sType                = VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_INFO;
    v_MemAllloc_t.allocationSize       = v_MemReqs_t.size;
    v_MemAllloc_t.memoryTypeIndex      = getMemoryType_u32(v_MemReqs_t.memoryTypeBits, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT);
    VK_CHECK_RESULT(vkAllocateMemory(logicalDevice_t, &v_MemAllloc_t, NULL, &depthStencil_s.mem_t));
    VK_CHECK_RESULT(vkBindImageMemory(logicalDevice_t, depthStencil_s.image_t, depthStencil_s.mem_t, 0));

    VkImageViewCreateInfo v_ImageViewCI_t           = {};
    v_ImageViewCI_t.sType                           = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
    v_ImageViewCI_t.viewType                        = VK_IMAGE_VIEW_TYPE_2D;
    v_ImageViewCI_t.image                           = depthStencil_s.image_t;
    v_ImageViewCI_t.format                          = depthFormat_t;
    v_ImageViewCI_t.subresourceRange.baseMipLevel   = 0;
    v_ImageViewCI_t.subresourceRange.levelCount     = 1;
    v_ImageViewCI_t.subresourceRange.baseArrayLayer = 0;
    v_ImageViewCI_t.subresourceRange.layerCount     = 1;
    v_ImageViewCI_t.subresourceRange.aspectMask     = VK_IMAGE_ASPECT_DEPTH_BIT;

    // Stencil aspect should only be set on depth + stencil formats (VK_FORMAT_D16_UNORM_S8_UINT..VK_FORMAT_D32_SFLOAT_S8_UINT
    if (depthFormat_t >= VK_FORMAT_D16_UNORM_S8_UINT) 
    {
      v_ImageViewCI_t.subresourceRange.aspectMask |= VK_IMAGE_ASPECT_STENCIL_BIT;
    }
    VK_CHECK_RESULT(vkCreateImageView(logicalDevice_t, &v_ImageViewCI_t, NULL, &depthStencil_s.view_t));
  }

  void DeviceVK::destroyDepthStencil_v()
  {
    vkDestroyImageView(logicalDevice_t, depthStencil_s.view_t, NULL);
    vkDestroyImage(logicalDevice_t, depthStencil_s.image_t, NULL);
    vkFreeMemory(logicalDevice_t, depthStencil_s.mem_t, NULL);
  }

  void DeviceVK::createFrameBuffers_v()
  {
    VkImageView v_Attachments_at[2];

    // Depth/Stencil attachment is the same for all frame buffers
    v_Attachments_at[1] = depthStencil_s.view_t;

    VkFramebufferCreateInfo frameBufferCreateInfo = {};
    frameBufferCreateInfo.sType                   = VK_STRUCTURE_TYPE_FRAMEBUFFER_CREATE_INFO;
    frameBufferCreateInfo.pNext                   = NULL;
    frameBufferCreateInfo.renderPass              = renderPass_t;
    frameBufferCreateInfo.attachmentCount         = 2;
    frameBufferCreateInfo.pAttachments            = &v_Attachments_at[0];
    frameBufferCreateInfo.width                   = device3DDesc_s.screenWidth_u32;
    frameBufferCreateInfo.height                  = device3DDesc_s.screenHeight_u32;
    frameBufferCreateInfo.layers                  = 1;

    // Create frame buffers for every swap chain image
    frameBuffers_at.resize(swapChain_o.getImageCount_u32());
    for (uint32_t v_I_u32 = 0; v_I_u32 < frameBuffers_at.size(); v_I_u32++)
    {
      v_Attachments_at[0] = swapChain_o.getBuffers_t()[v_I_u32].view_t;
      VK_CHECK_RESULT(vkCreateFramebuffer(logicalDevice_t, &frameBufferCreateInfo, NULL, &frameBuffers_at[v_I_u32]));
    }
  }

  void DeviceVK::destroyFrameBuffers_v()
  {
    for (uint32_t i = 0; i < frameBuffers_at.size(); i++) 
    {
      vkDestroyFramebuffer(logicalDevice_t, frameBuffers_at[i], NULL);
    }
  }

  void DeviceVK::setupRenderPass_v()
  {
    mepl::vector<VkAttachmentDescription> attachments;
    attachments.resize(2);

    // Color attachment
    attachments[0].format         = swapChain_o.getColorFormat_t();
    attachments[0].samples        = VK_SAMPLE_COUNT_1_BIT;
    attachments[0].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[0].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[0].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_DONT_CARE;
    attachments[0].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[0].initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
    attachments[0].finalLayout    = VK_IMAGE_LAYOUT_PRESENT_SRC_KHR;

    // Depth attachment
    attachments[1].format         = depthFormat_t;
    attachments[1].samples        = VK_SAMPLE_COUNT_1_BIT;
    attachments[1].loadOp         = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].storeOp        = VK_ATTACHMENT_STORE_OP_STORE;
    attachments[1].stencilLoadOp  = VK_ATTACHMENT_LOAD_OP_CLEAR;
    attachments[1].stencilStoreOp = VK_ATTACHMENT_STORE_OP_DONT_CARE;
    attachments[1].initialLayout  = VK_IMAGE_LAYOUT_UNDEFINED;
    attachments[1].finalLayout    = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkAttachmentReference colorReference = {};
    colorReference.attachment            = 0;
    colorReference.layout                = VK_IMAGE_LAYOUT_COLOR_ATTACHMENT_OPTIMAL;

    VkAttachmentReference depthReference = {};
    depthReference.attachment            = 1;
    depthReference.layout                = VK_IMAGE_LAYOUT_DEPTH_STENCIL_ATTACHMENT_OPTIMAL;

    VkSubpassDescription subpassDescription     = {};
    subpassDescription.pipelineBindPoint        = VK_PIPELINE_BIND_POINT_GRAPHICS;
    subpassDescription.colorAttachmentCount     = 1;
    subpassDescription.pColorAttachments        = &colorReference;
    subpassDescription.pDepthStencilAttachment  = &depthReference;
    subpassDescription.inputAttachmentCount     = 0;
    subpassDescription.pInputAttachments        = NULL;
    subpassDescription.preserveAttachmentCount  = 0;
    subpassDescription.pPreserveAttachments     = NULL;
    subpassDescription.pResolveAttachments      = NULL;

    // Subpass dependencies for layout transitions
    mepl::vector<VkSubpassDependency> dependencies;
    dependencies.resize(2);

    dependencies[0].srcSubpass      = VK_SUBPASS_EXTERNAL;
    dependencies[0].dstSubpass      = 0;
    dependencies[0].srcStageMask    = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    dependencies[0].dstStageMask    = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependencies[0].srcAccessMask   = VK_ACCESS_MEMORY_READ_BIT;
    dependencies[0].dstAccessMask   = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    dependencies[0].dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;

    dependencies[1].srcSubpass      = 0;
    dependencies[1].dstSubpass      = VK_SUBPASS_EXTERNAL;
    dependencies[1].srcStageMask    = VK_PIPELINE_STAGE_COLOR_ATTACHMENT_OUTPUT_BIT;
    dependencies[1].dstStageMask    = VK_PIPELINE_STAGE_BOTTOM_OF_PIPE_BIT;
    dependencies[1].srcAccessMask   = VK_ACCESS_COLOR_ATTACHMENT_READ_BIT | VK_ACCESS_COLOR_ATTACHMENT_WRITE_BIT;
    dependencies[1].dstAccessMask   = VK_ACCESS_MEMORY_READ_BIT;
    dependencies[1].dependencyFlags = VK_DEPENDENCY_BY_REGION_BIT;

    VkRenderPassCreateInfo renderPassInfo = {};
    renderPassInfo.sType                  = VK_STRUCTURE_TYPE_RENDER_PASS_CREATE_INFO;
    renderPassInfo.attachmentCount        = static_cast<uint32_t>(attachments.size());
    renderPassInfo.pAttachments           = attachments.data();
    renderPassInfo.subpassCount           = 1;
    renderPassInfo.pSubpasses             = &subpassDescription;
    renderPassInfo.dependencyCount        = static_cast<uint32_t>(dependencies.size());
    renderPassInfo.pDependencies          = dependencies.data();

    VK_CHECK_RESULT(vkCreateRenderPass(logicalDevice_t, &renderPassInfo, NULL, &renderPass_t));
  }

  void DeviceVK::buildCommandBuffers_v()
  {
    VkCommandBufferBeginInfo cmdBufInfo = {}; 
    cmdBufInfo.sType = VK_STRUCTURE_TYPE_COMMAND_BUFFER_BEGIN_INFO;

    VkClearDepthStencilValue depthClear;
    depthClear.depth = 1.0F;
    depthClear.stencil = 0U;

    VkClearColorValue defaultClearColor = { { 0.425f, 0.425f, 0.425f, 1.0f } };

    VkClearValue clearValues[2];
    clearValues[0].color = defaultClearColor;
    clearValues[1].depthStencil = depthClear;

    VkRenderPassBeginInfo renderPassBeginInfo     = {};
    renderPassBeginInfo.sType                     = VK_STRUCTURE_TYPE_RENDER_PASS_BEGIN_INFO;
    renderPassBeginInfo.renderPass                = renderPass_t;
    renderPassBeginInfo.renderArea.offset.x       = 0;
    renderPassBeginInfo.renderArea.offset.y       = 0;
    renderPassBeginInfo.renderArea.extent.width   = device3DDesc_s.screenWidth_u32;
    renderPassBeginInfo.renderArea.extent.height  = device3DDesc_s.screenHeight_u32;
    renderPassBeginInfo.clearValueCount           = 2;
    renderPassBeginInfo.pClearValues              = clearValues;

    for (uint32_t i = 0; i < drawCmdBuffers_at.size(); ++i)
    {
      renderPassBeginInfo.framebuffer = frameBuffers_at[i];

      VK_CHECK_RESULT(vkBeginCommandBuffer(drawCmdBuffers_at[i], &cmdBufInfo));

      vkCmdBeginRenderPass(drawCmdBuffers_at[i], &renderPassBeginInfo, VK_SUBPASS_CONTENTS_INLINE);
    }

    for (uint32_t i = 0; i < drawCmdBuffers_at.size(); ++i)
    {

      // Update dynamic viewport state
      VkViewport viewport = {};
      viewport.height = (float)device3DDesc_s.screenWidth_u32;
      viewport.width = (float)device3DDesc_s.screenHeight_u32;
      viewport.minDepth = (float) 0.0f;
      viewport.maxDepth = (float) 1.0f;
      vkCmdSetViewport(drawCmdBuffers_at[i], 0, 1, &viewport);

      // Update dynamic scissor state
      VkRect2D scissor = {};
      scissor.extent.width =  device3DDesc_s.screenWidth_u32;
      scissor.extent.height = device3DDesc_s.screenHeight_u32;
      scissor.offset.x = 0;
      scissor.offset.y = 0;
      vkCmdSetScissor(drawCmdBuffers_at[i], 0, 1, &scissor);
    }


    for (uint32_t i = 0; i < drawCmdBuffers_at.size(); ++i)
    {
      vkCmdEndRenderPass(drawCmdBuffers_at[i]);

      VK_CHECK_RESULT(vkEndCommandBuffer(drawCmdBuffers_at[i]));
    }

  }

} // namespace me3d

#endif // RE_USE_VULKAN
