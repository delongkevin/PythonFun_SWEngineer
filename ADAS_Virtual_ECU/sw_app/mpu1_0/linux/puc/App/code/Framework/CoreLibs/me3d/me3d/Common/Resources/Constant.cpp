#include "Constant.h"

#include "Common/Resources/ConstantBuffer.h"

// PRQA S 5118 EOF // C++14 Autosar Standard permits
// PRQA S 3060 EOF // fine here
// PRQA S 3080 EOF // fine here
// PRQA S 3103 EOF // fine here
// PRQA S 3103 EOF // fine here
// PRQA S 3106 EOF // performance
// PRQA S 3706 EOF // performance

namespace me3d
{

static uint32_t S_ConstantSizeTypes_u32[e_CtCount] =
{
  0,                          // e_CtUnkown

  sizeof(float32_t),          // e_CtFloat1
  sizeof(Vector2f),           // e_CtFloat2
  sizeof(Vector3f),           // e_CtFloat3
  sizeof(Vector4f),           // e_CtFloat4

  sizeof(sint32_t),           // e_CtInt1
  sizeof(Vector2i),           // e_CtInt2
  sizeof(Vector3i),           // e_CtInt3
  sizeof(Vector4i),           // e_CtInt4

  sizeof(Matrix3f),           // e_CtMatrix3
  sizeof(Matrix4f),           // e_CtMatrix4

  sizeof(TextureConstant_s),  // e_CtTexture
  0,                          // e_CtRawData
};



  Constant::Constant()
    : data_pv(NULL)
    , usedCount_u32(0U)
    , modification_u32(0U)
    , parentConstantBuffer_po(NULL)
  {
  }

  Constant::~Constant()
  {
    // PRQA S 4631 1 // does not throw exceptions
    release_v();
  }

  void Constant::create_v(const ConstantDesc_s& i_Desc_rs, ConstantBuffer* b_ParentConstantBuffer_po)
  {
    desc_s                  = i_Desc_rs;
    usedCount_u32           = 0;
    parentConstantBuffer_po = b_ParentConstantBuffer_po;

    if (NULL == data_pv)
    {
      // calculate size
      uint32_t v_MaxUsedSize_u32 = getMaxUsedSize_u32();

      // allocate
      data_pv = malloc(v_MaxUsedSize_u32);

      // Fill with zeros
      memset(data_pv, 0, v_MaxUsedSize_u32);
    }
    else
    {
      AssertFunction(false, "Constant::create_v - Tried to allocate already existing data");
    }
  }

  void Constant::release_v()
  {
    usedCount_u32     = 0U;
    modification_u32  = 0U;

    if (NULL != data_pv)
    {
      free(data_pv);

      data_pv = NULL;
    }
  }

  void Constant::setData_v(const bool_t* i_Value_b, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtInt1)
    {
      copyData_v(i_Value_b, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const float32_t* i_Value_pf32, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtFloat1)
    {
      copyData_v(i_Value_pf32, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const Vector2f* i_Value_po, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtFloat2)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const Vector3f* i_Value_po, uint32_t i_Count_u32 /*= 1*/)
  {
    if (desc_s.type_e == e_CtFloat3)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }  
  
  void Constant::setData_v(const Vector4f* i_Value_po, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtFloat4)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const Color* i_Value_po, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtFloat4)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const Matrix3f* i_Value_po, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtMatrix3)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  void Constant::setData_v(const Matrix4f* i_Value_po, uint32_t i_Count_u32 /*= 1U*/)
  {
    if (desc_s.type_e == e_CtMatrix4)
    {
      copyData_v(i_Value_po, i_Count_u32);
    }
    else
    {
      ME_Debugger_F_Printf_v("%s: Value given to Constant::setData_v is not consistent with constant type\n", (desc_s.name_o.getString_pc() != NULL) ? desc_s.name_o.getString_pc() : "");
    }
  }

  uint32_t Constant::getArrayStride_u32() const
  {
    AssertFunction(desc_s.count_u32 > 1, "Padding per element only required for array-type-constants");

    // All elements within array are 16-padded
    return apply16Padding_u32(S_ConstantSizeTypes_u32[desc_s.type_e]);
  }

  uint32_t Constant::getMaxUsedSize_u32() const
  {
    uint32_t v_MaxUsedSize_u32 = 0U;

    if (desc_s.count_u32 > 1U)
    {
      v_MaxUsedSize_u32 = getArrayStride_u32() * desc_s.count_u32; 
    }
    else
    {
      v_MaxUsedSize_u32 = S_ConstantSizeTypes_u32[desc_s.type_e];
    }

    return v_MaxUsedSize_u32;
  }

  uint32_t Constant::getUsedSize_u32() const
  {
    uint32_t v_UsedSize_u32 = 0U;

    if (desc_s.count_u32 > 1U)
    {
      v_UsedSize_u32 = getArrayStride_u32() * usedCount_u32; 
    }
    else
    {
      v_UsedSize_u32 = S_ConstantSizeTypes_u32[desc_s.type_e];
    }

    return v_UsedSize_u32;
  }

  uint32_t Constant::apply16Padding_u32(uint32_t i_Bytes_u32)
  {
    // Constant buffer packing pads each array-constant to float4 blocks
    sint32_t v_NeededPaddinBytes_s32 = i_Bytes_u32 % 16;

    if (v_NeededPaddinBytes_s32 != 0)
    {
      // need to pad each element
      i_Bytes_u32 += (16 - v_NeededPaddinBytes_s32);
    }

    return i_Bytes_u32;
  }

  // PRQA S 4213 1 // may be modified by other API implementations
  bool_t Constant::reset_b(ITextureConstantData* pTextureConstantData)const
  {
    bool_t v_Ret_b = false;

    if (e_CtTexture == desc_s.type_e)
    {
      TextureConstant_s* v_TexConstant_po = reinterpret_cast<TextureConstant_s*>(data_pv);
      if ( (NULL != v_TexConstant_po) && (v_TexConstant_po->object_po == pTextureConstantData) )
      {
        v_TexConstant_po->object_po = NULL;

        v_Ret_b = true;
      }
    }

    return v_Ret_b;
  }

  void Constant::onUpdateData_v(uint32_t i_Count_u32)
  {
    usedCount_u32 = i_Count_u32;

    Assert(usedCount_u32 <= desc_s.count_u32);

    // increase modification
    ++modification_u32;

    if (parentConstantBuffer_po)
    {
      parentConstantBuffer_po->signalCommitNeeded_v();
    }
  }

  void Constant::copyData_v(const void* i_Data_pv, uint32_t i_Count_u32)
  {
    if (NULL == data_pv)
    {
      AssertFunction(false, "Constant::copyData_v - data is NULL");
    }
    else
    {
      sint32_t v_UnpaddedSizePerElement_s32 = S_ConstantSizeTypes_u32[desc_s.type_e];

      // is per element padding needed? 
      bool_t v_PaddingNeeded_b = (i_Count_u32 > 1U) && ((v_UnpaddedSizePerElement_s32 % 16) != 0);

      sint32_t v_TotalSize_s32 = i_Count_u32 * (v_PaddingNeeded_b ? getArrayStride_u32() : v_UnpaddedSizePerElement_s32);

      // copy the data
      if (NULL != i_Data_pv)
      {
        if (true == v_PaddingNeeded_b)
        {
          // Input data is tightly packed, e.g. imagine a Vec3[2]:
          // Input: [|x0|y0|z0|x1|y1|z1]
          // Dst:   [|x0|y0|z0|__|x1|y1|z1|__]
          for (uint32_t v_I_u32 = 0U; v_I_u32 < i_Count_u32; ++v_I_u32)
          {
            uint8_t*  v_DataSrc_pu8 = (uint8_t*) i_Data_pv;
            Vector4f* v_DataDest_po = reinterpret_cast<Vector4f*>(data_pv);

            // PRQA S 3105 1 // fine here
            memcpy(&v_DataDest_po[v_I_u32], &v_DataSrc_pu8[v_I_u32 * v_UnpaddedSizePerElement_s32], v_UnpaddedSizePerElement_s32);
          }
        }
        else
        {
          // Non-array or tightly packed array
          memcpy(data_pv, i_Data_pv, v_TotalSize_s32);
        }
      }
      else
      {
        if (desc_s.type_e != e_CtTexture)
        {
          ME_Debugger_F_Printf_v("Calling Constant::copyData_v without data for non-texture-constant %s\n", desc_s.name_o.getData_ro().c_str());
        }

        memset(data_pv, 0, static_cast<size_t>(v_TotalSize_s32));
      }

      onUpdateData_v(i_Count_u32);
    }
  }

} // namespace me3d
