//--------------------------------------------------------------------------                                                                                                           
/// @file Texture.h                                                                         
/// @brief Used to create and upload texture data to GPU
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef TEXTURE_H
#define TEXTURE_H

#include "mecl/core/MeclTypes.h"
#include "ITextureConstantData.h"

// PRQA S 2127 EOF // virtual function without pure specifier used here by design.
// PRQA S 2101 EOF // protected members used here by design

namespace me3d
{

class RenderEngine;

class Texture : public ITextureConstantData
{
public:
  Texture();
  virtual ~Texture();

  virtual bool create_b(RenderEngine* i_RenEng_po, const TextureDesc_s& i_Desc_rs, const uint8_t* i_InitialData_pu8);

  virtual void updateSubData_v(const uint8_t* i_Data_pv) = 0;

  virtual void updateData_v(const uint8_t* i_Data_pv) = 0;

  virtual void release_v();

  // Inherited from ITextureConstantData
  virtual TextureType_e getTextureType_e() const;

  // Inherited from ITextureConstantData
  virtual TextureConstantDataType_e getDataType_e() const;

  // Inherited from ITextureConstantData
  virtual uint32_t getWidth_u32() const;

  // Inherited from ITextureConstantData
  virtual uint32_t getHeight_u32() const;

  // Inherited from ITextureConstantData
  virtual const MEString& getFilename_ro() const;
  
  bool hasAlpha_b() const;

  const TextureDesc_s& getDesc_rs() const;

  static uint32_t getImageSize_u32(uint32_t i_Width_u32, uint32_t i_Height_u32, uint32_t i_Depth_u32, mepl::PixelFormat_e i_Format_e);

protected:
  RenderEngine* renderEngine_po;
  TextureDesc_s desc_s;

};

} // namespace me3d


#endif
