//--------------------------------------------------------------------------                                                                                                           
/// @file IndexBufferVK.h                                                                         
/// @brief Vulkan IndexBuffer implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef INDEXBUFFER_VK_H
#define INDEXBUFFER_VK_H

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Common/Resources/IndexBuffer.h"
#include "Vulkan/VKIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.

namespace me3d
{

  class IndexBufferVK : public IndexBuffer
  {
  public:
    IndexBufferVK();
    virtual ~IndexBufferVK();

    virtual bool_t create_b(const IndexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv = NULL);

    virtual void release_v();

    virtual void set_v();

    virtual void updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv);

  private:

  };

} // namespace me3d

#endif // RE_USE_VULKAN

#endif
