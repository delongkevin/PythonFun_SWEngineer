//--------------------------------------------------------------------------                                                                                                           
/// @file TextureVK.h                                                                         
/// @brief Vulkan Texture implementation  
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef TEXTURE_VK_H
#define TEXTURE_VK_H

// Compile this file for Vulkan only
#ifdef RE_USE_VULKAN

#include "Common/Resources/Texture.h"
#include "Vulkan/VKIncludes.h"

// PRQA S 2128 EOF // overriding non-pure base class virtual function used here by design.
// PRQA S 1051 EOF // Still working on complete vulkan port, this is a reminder to implement these functions

namespace me3d
{

  class TextureVK : public Texture
  {
  public:
    TextureVK();
    virtual ~TextureVK();

    virtual bool isValid_b() const;

    virtual void* getTexture_pv(TextureConstantBufferType_e i_BufferType_e);

    virtual bool create_b(RenderEngine* i_RenEng_po, const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitialData_pu8);

    virtual void updateSubData_v(const uint8_t* i_Data_pv);

    virtual void updateData_v(const uint8_t* i_Data_pv);

    virtual void release_v();


  protected:
    //void uploadImageData_v(uint32_t i_Level_u32, uint32_t i_ArraySlice_u32, const uint8_t* i_Data_pu8);
    //void uploadSubImageData_v(uint32_t i_Level_u32, uint32_t i_ArraySlice_u32, const uint8_t* i_Data_pu8);


  protected:
    uint32_t textureID_u32;
  };

} // namespace me3d

#endif // RE_USE_VULKAN

#endif
