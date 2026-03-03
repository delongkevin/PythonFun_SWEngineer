//--------------------------------------------------------------------------                                                                                                           
/// @file Constant.h                                                                         
/// @brief Constant holds a name, data type and the value.
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

#ifndef CONSTANT_H
#define CONSTANT_H

#include <platform/PlatformAPI.h>
 

#include "MeclTypeDefs.h"
#include "Common/Resources/ITextureConstantData.h"


namespace me3d
{
  class ConstantBuffer;
  class Texture;
  class Color;
}

namespace me3d
{

enum ConstantType_e
{
  e_CtUnkown,

  e_CtFloat1,
  e_CtFloat2,
  e_CtFloat3,
  e_CtFloat4,

  e_CtInt1,
  e_CtInt2,
  e_CtInt3,
  e_CtInt4,

  e_CtMatrix3,
  e_CtMatrix4,

  e_CtTexture,
  e_CtRawData,

  e_CtCount
};



struct ConstantDesc_s
{
  MEString        name_o;
  ConstantType_e  type_e;
  uint32_t        count_u32;

  ConstantDesc_s()
    : name_o("")
    , type_e(e_CtUnkown)
    , count_u32(0U)
  {
  }

  ConstantDesc_s(const MEString& i_Name_ro, ConstantType_e i_Type_e, uint32_t i_Count_u32)
    : name_o(i_Name_ro)
    , type_e(i_Type_e)
    , count_u32(i_Count_u32)
  {
  }
};


class Constant
{
public:
  Constant();

  ~Constant();

  void create_v(const ConstantDesc_s& i_Desc_rs, ConstantBuffer* b_ParentConstantBuffer_po);

  void release_v();

  // set data for each type
  void setData_v(const bool_t*    i_Value_b,    uint32_t i_Count_u32 = 1U);
  void setData_v(const float32_t* i_Value_pf32, uint32_t i_Count_u32 = 1U);
  void setData_v(const Vector2f*  i_Value_po,   uint32_t i_Count_u32 = 1U);
  void setData_v(const Vector3f*  i_Value_po,   uint32_t i_Count_u32 = 1U);
  void setData_v(const Vector4f*  i_Value_po,   uint32_t i_Count_u32 = 1U);
  void setData_v(const Color*     i_Value_po,   uint32_t i_Count_u32 = 1U);
  void setData_v(const Matrix3f*  i_Value_po,   uint32_t i_Count_u32 = 1U);
  void setData_v(const Matrix4f*  i_Value_po,   uint32_t i_Count_u32 = 1U);

  // set  texture constant data value
  void setData_v(ITextureConstantData* i_TextureConstant_po, TextureConstantBufferType_e i_BufferType_e)
  {
    if (e_CtTexture == desc_s.type_e)
    {
      TextureConstant_s v_TexConstant_s;

      v_TexConstant_s.object_po     = i_TextureConstant_po;
      v_TexConstant_s.bufferType_e  = i_BufferType_e;

      if (NULL != i_TextureConstant_po)
      {
        copyData_v(&v_TexConstant_s, 1);
      }
      else
      {
        // Reset Texture
        copyData_v(NULL, 1);
      }
    }
  }

  /// Sets a ITexture constant (just a convenient function as ITextures are always TCB_COLOR)
  ME_INLINE void setData_v(Texture* pTexture)
  {
    setData_v(reinterpret_cast<ITextureConstantData*>(pTexture), e_TcbColor);
  }

  // return the constant descriptor
  ME_INLINE const ConstantDesc_s& getDesc_rs() const
  {
    return desc_s;
  }

  // Returns the constant's type (Vector, Matrix, Texture, etc)
  ME_INLINE ConstantType_e getType_e() const
  {
    return desc_s.type_e;
  }

  // Returns the capacity of the constant array (or 1 if it's not an array)
  ME_INLINE uint32_t getMaxCount_u32() const
  {
    return desc_s.count_u32;
  }

  // Returns the name of the constant
  ME_INLINE const MEString& getName_ro() const
  {
    return desc_s.name_o;
  }

  // Returns a pointer to the data of the constant
  ME_INLINE const void* getData_pv() const
  {
    return data_pv;
  }

  // Returns the amount of elements of the constant array that are actually set
  ME_INLINE uint32_t getUsedCount_u32() const
  {
    return usedCount_u32;
  }

  // Returns the number of performed modifications
  ME_INLINE uint32_t getModification_u32() const
  {
    return modification_u32;
  }

  // get array stride in bytes, this is the size reserverd per element)
  uint32_t getArrayStride_u32() const;

  // Returns the size of bytes of maximum used data. 
  // This is the amount of data needed on CPU side to store the constant's data.
  // In General not equivalent to reserved size in constant buffer
  // Example: A float in D3D -> |1|?|?|?| -> Used size = 1 * sizeof(float), reserved size = 1-4 * sizeof(float) (depends on following constants)
  uint32_t getMaxUsedSize_u32() const;

  uint32_t getUsedSize_u32() const;

  // Applies padding to multiple of 16, e.g. 3->16, 16->16, 17->32
  static uint32_t apply16Padding_u32(uint32_t i_Bytes_u32);

   // Sets the constant to null if it references this texture constant data
  bool_t reset_b(ITextureConstantData* pTextureConstantData) const;

protected:
  void onUpdateData_v(uint32_t i_Count_u32);
  
  void copyData_v(const void* i_Data_pv, uint32_t i_Count_u32);


private:
  ConstantDesc_s  desc_s;                   ///< description like size, name, type of the constant
  void*           data_pv;                  ///< pointer to data memory
  uint32_t        usedCount_u32;            ///< how many array elements are valid
  uint32_t        modification_u32;         ///< number of performed modifications
  ConstantBuffer* parentConstantBuffer_po;  ///< Parent constant buffer
};

} // namespace me3d

#endif
