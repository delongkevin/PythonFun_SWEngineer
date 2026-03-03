//--------------------------------------------------------------------------                                                                                                           
/// @file BufferManagerVK.h                                                                         
/// @brief Vulkan BufferManager implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef BUFFERMANAGER_VK_H
#define BUFFERMANAGER_VK_H


// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Common/Manager/BufferManager.h"

#include "Vulkan/Resources/VertexBufferVK.h"
#include "Vulkan/Resources/IndexBufferVK.h"

namespace me3d
{

  class BufferManagerVK : public BufferManager
  {
  public:
    BufferManagerVK();
    virtual ~BufferManagerVK();

    // IManager
    virtual void release_v();
    virtual void onResize_v(uint32_t i_Width_u32, uint32_t i_Height_u32);
    virtual void beginFrame_v();
    virtual void preRender_v();

  protected:
    VertexBuffer* getNewVertexBuffer_po();
    IndexBuffer*  getNewIndexBuffer_po();

  private:
    VertexBufferVK vertexBufferPool_ao[c_MaxVertexBuffers_u32];
    IndexBufferVK  indexBufferPool_ao [c_MaxIndexBuffers_u32];
  };


} // namespace me3d

#endif // RE_USE_VULKAN

#endif
