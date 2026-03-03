//--------------------------------------------------------------------------                                                                                                           
/// @file Texture.h                                                                         
/// @brief Used to upload Vertices and its declaration to GPU. Always call set()
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H

#include "RenderEngineCfg.h"

#include "Common/Device/Device3DTypes.h"
#include "Common/Effect/EffectFileTypes.h"

// PRQA S 2100 EOF // public members used here by design. 
// PRQA S 2101 EOF // protected members used here by design.
// PRQA S 2127 EOF // virtual function without pure specifier used here by design.

namespace me3d
{

struct BufferLayoutElement_s
{
  ShaderClassification_e  classification_e;
  ShaderSemanticType_e    semanticType_e;
  ShaderSemanticFormat_e  semanticFormat_e;
  uint32_t                alignedByteOffset_u32;
  uint32_t                size_u32;
  uint32_t                componentCount_u32;     // Size / Count of the attribute values (e.g. 3 floats)

  BufferLayoutElement_s()
    : classification_e(e_ScCount)
    , semanticType_e(e_SstCount)
    , semanticFormat_e(e_SsfInvalid)
    , alignedByteOffset_u32(0U)
    , size_u32(0U)
    , componentCount_u32(0U)
  {
  }
};

struct BufferLayout_s
{
  uint32_t usedElements_u32;
  BufferLayoutElement_s elements_as[c_MaxBufferLayoutElements_u32];

  BufferLayout_s()
    : usedElements_u32(0U)
  {
  }
};

class RenderEngine;

class VertexBuffer
{
public:
  VertexBuffer();
  virtual ~VertexBuffer();

  virtual bool create_b(RenderEngine* b_RenderEngine_po, const VertexBufferDesc_s& i_Desc_rs, const void* i_InitialData_pv = NULL);

  virtual void release_v();

  virtual void updateSubData_v(uint32_t i_Offset_u32, uint32_t i_Size_u32, const void* i_Data_pv) = 0;

  virtual void bind_v() const = 0;

  virtual uint32_t getID_u32() const = 0;

  void set_v(uint32_t i_Slot_u32, uint32_t i_Offset_u32 = 0U) const;
  void set_v(uint32_t i_Slot_u32, uint32_t i_Offset_u32, uint32_t i_Stride_u32) const;

  const BufferLayout_s&     getBufferLayout_rs() const;
  const VertexBufferDesc_s& getDesc_rs() const;

private:
  bool createBufferLayout_b();

  static ShaderSemanticType_e    getSemanticType_e(char i_C0_c);
  static ShaderSemanticFormat_e  getSemanticFormat_e(char i_C1_c, char i_C2_c);
  static uint32_t                getSemanticFormatStride_u32(char i_C1_c, char i_C2_c);
  static uint32_t                getSemanticComponentCount_u32(char i_C1_c);

protected:
  RenderEngine*       renderEngine_po;
  VertexBufferDesc_s  desc_s;
  BufferLayout_s      layout_s;
};

} // namespace me3d

#endif
