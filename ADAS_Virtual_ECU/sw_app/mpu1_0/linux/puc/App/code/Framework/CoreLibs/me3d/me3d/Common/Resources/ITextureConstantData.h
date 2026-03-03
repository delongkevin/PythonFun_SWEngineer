//--------------------------------------------------------------------------                                                                                                           
/// @file ITextureConstantData.h                                                                         
/// @brief texture constants Interface
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

// PRQA S 2100 EOF // public members used here by design.

#ifndef ITEXTURE_CONSTANT_DATA_H
#define ITEXTURE_CONSTANT_DATA_H

#include "Common/Device/Device3DTypes.h"

namespace me3d
{

// enum of classes deriving from ITextureConstantData
enum TextureConstantDataType_e
{
  e_TcdtTexture,
  e_TcdtRenderTarget,
  e_TcdtCount
};

// Type of constant buffer
enum TextureConstantBufferType_e
{
  e_TcbColor,
  e_TcbDepth,
  e_TcbStencil
};

class ITextureConstantData;
struct TextureConstant_s
{
  ITextureConstantData*       object_po;
  TextureConstantBufferType_e bufferType_e;

  TextureConstant_s()
    : object_po(NULL)
    , bufferType_e(e_TcbColor)
  {
  }

  TextureConstant_s(ITextureConstantData* i_Object_po, TextureConstantBufferType_e i_Type_e)
    : object_po(i_Object_po)
    , bufferType_e(i_Type_e)
  {
  }
};


class ITextureConstantData
{
public:
  ITextureConstantData() {}

  // Returns true if the resource has been loaded or failed to load. Returns false if it hasn't been loaded yet.
  virtual bool isValid_b() const = 0;

  // Returns the a pointer to the platform-specific texture, e.g. ID3D11ShaderResourceView* on D3D11 or uint32_t for OpenGL
  virtual void* getTexture_pv(TextureConstantBufferType_e i_BufferType_e) = 0;

  // Gets the texture type (e.g. 2D, Cube, etc)
  virtual TextureType_e getTextureType_e() const = 0;

  // Returns the derived class type
  virtual TextureConstantDataType_e getDataType_e() const = 0;

  // Get width in pixels
  virtual uint32_t getWidth_u32() const = 0;

  // Get height in pixels
  virtual uint32_t getHeight_u32() const = 0;

  // get filename
  virtual const MEString& getFilename_ro() const = 0;
};

} // namespace me3d

#endif
