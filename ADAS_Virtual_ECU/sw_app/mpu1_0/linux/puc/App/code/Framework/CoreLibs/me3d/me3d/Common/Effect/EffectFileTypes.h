//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileTypes.h                                                                         
/// @brief Provides structs used by EffectFile classes
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef EFFECT_FILE_TYPES_H
#define EFFECT_FILE_TYPES_H

#include <string.h>
#include <platform/PlatformAPI.h>

#include "RenderEngineCfg.h"

// PRQA S 2100 EOF // public members used here by design.

namespace me3d
{

// Type of shaders 
enum Shaders_e
{
  e_ShaderDebug = 0,
  e_ShaderGui,
  e_ShaderGuideLine,
  e_ShaderText,
  e_ShaderPhongSolid,
  e_ShaderPhongTextured,
  e_ShaderGoraudSolid,
  e_ShaderGoraudTextured,
  e_ShaderPBRSolid,
  e_ShaderPBRTextured,
  e_ShaderModelAnimated,
  e_ShaderBowlView,
  e_ShaderBowlViewCPU,
  e_ShaderSingleView,
  e_ShaderCubeMap,
  e_ShaderCount
};


// Types of Render States
enum EffectFileStateType_e
{
  e_EfstNull = 0,

  e_EfstZEnable,
  e_EfstZFunc,
  e_EfstZWriteEnable,

  e_EfstFillMode,
  e_EfstCullMode,

  e_EfstAlphaBlendEnable,
  e_EfstSeparateAlphaBlendEnable,
  e_EfstIndependentBlendEnable,
  e_EfstAlphaToCoverageEnable,

  e_EfstSrcBlend,
  e_EfstDestBlend,
  e_EfstBlendOp,

  e_EfstSrcBlendAlpha,
  e_EfstDestBlendAlpha,
  e_EfstBlendOpAlpha,

  e_EfstStencilEnable,
  e_EfstTwoSidedStencilMode,

  e_EfstStencilFail,
  e_EfstStencilZFail,
  e_EfstStencilPass,
  e_EfstStencilFunc,
  e_EfstStencilRef,
  e_EfstStencilMask,
  e_EfstStencilWriteMask,

  e_EfstCCWStencilFail,
  e_EfstCCWStencilZFail,
  e_EfstCCWStencilPass,
  e_EfstCCWStencilFunc,

  e_EfstMultisampleAntialias,
  e_EfstMultisampleMask,

  e_EfstScissorTestEnable,

  e_EfstSlopeScaleDepthBias,
  e_EfstDepthBias,

  e_EfstColorWriteEnable,

  // Sampler State types
  e_EfstFilter,
  e_EfstAddress,
  e_EfstAddressU,
  e_EfstAddressV,
  e_EfstAddressW,
  e_EfstMaxAnisotropy,
  e_EfstComparisonFunc,
  e_EfstMipLodBias,
  e_EfstMinLod,
  e_EfstMaxLod,

  e_EfstCount
};

enum EffectFileStateValueType_e
{
  e_EfsvFalse = 0, // must be zero
  e_EfsvTrue,

  // Alpha function / Comparison Function
  e_EfsvNever,
  e_EfsvLess,
  e_EfsvEqual,
  e_EfsvLEqual,
  e_EfsvGreater,
  e_EfsvNotEqual,
  e_EfsvGEqual,
  e_EfsvAlways,

  // Blending operations
  e_EfsvAdd,
  e_EfsvSubtract,
  e_EfsvRevSubtract,
  e_EfsvMin,
  e_EfsvMax,

  // Blending Factor
  e_EfsvZero,
  e_EfsvOne,
  e_EfsvSrcColor,
  e_EfsvOneMinusSrcColor,
  e_EfsvSrcAlpha,
  e_EfsvOneMinusSrcAlpha,
  e_EfsvDstAlpha,
  e_EfsvOneMinusDstAlpha,
  e_EfsvDstColor,
  e_EfsvOneMinusDstColor,
  e_EfsvSrcAlphaSaturate,

  // CullFace Mode
  e_EfsvCW,   // cull clockwise
  e_EfsvCCW,  // cull counter clockwise
  e_EfsvNone, // cull none

  // Stencil Operation
  e_EfsvKeep,
  e_EfsvReplace,
  e_EfsvIncr,
  e_EfsvDecr,
  e_EfsvInvert,

  // Fill Mode
  e_EfsvSolid,
  e_EfsvWireFrame,

  // Address Mode
  e_EfsvWrap,
  e_EfsvClamp,
  e_EfsvMirror,
  e_EfsvBorder,

  // Filter
  e_EfsvPoint,
  e_EfsvLinear,
  e_EfsvAnisotropic,

  e_EfsvCount
};

struct EffectFileStateValue_s
{
  // PRQA S 4054 1 // intended (performance). Default constructor doesn't make sense
  EffectFileStateValue_s() {}
  explicit EffectFileStateValue_s(EffectFileStateValueType_e i_Enum_e) : enum_e   (i_Enum_e)    { }
  explicit EffectFileStateValue_s(float32_t i_Float_f32)               : float_f32(i_Float_f32) { }
  explicit EffectFileStateValue_s(uint32_t i_Uint_u32)                 : uint_u32 (i_Uint_u32)  { }

  EffectFileStateValueType_e enum_e;
  float32_t                  float_f32;
  uint32_t                   uint_u32;
};

// Value format type for effect file state value object
enum EffectFileStateValueFormat_e
{
  e_EfsvfUnknown,
  e_EfsvfEnum,
  e_EfsvfFloat,
  e_EfsvfUint,

  e_EfsvfCount
};

// return State Value Format for State Type
EffectFileStateValueFormat_e getEffectFileStateValueFormat_e(EffectFileStateType_e i_Type_e);

// return Default value for State Type
EffectFileStateValue_s getRenderStateDefaultValue_s(EffectFileStateType_e i_Type_e);

// Shader Types
enum ShaderSemanticType_e
{
  e_SstPosition = 0,
  e_SstNormal,
  e_SstTangent,
  e_SstBinormal,
  e_SstTexCoord,
  e_SstColor,
  e_SstWeights, ///< Blend weights
  e_SstIndices, ///< Blend Indices

  e_SstCount
};

enum ShaderSemanticFormat_e
{
  e_SsfInvalid = 0,
  e_SsfFloat1,
  e_SsfFloat2,
  e_SsfFloat3,
  e_SsfFloat4,
  e_SsfUint,
  e_SsfCount
};

enum ShaderClassification_e
{
  e_ScPerVertexData = 0,
  e_ScPerInstanceData,

  e_ScCount
};

// <attribute> <mediump> <vec3> <Pos> e.g. attribute mediump vec3 Pos               
struct ShaderInputElement_s
{
  static const uint32_t   c_NameLength_u32 = 16U;
  char                    name_ac[c_NameLength_u32];    // Shader uniform name in effect file
  ShaderSemanticFormat_e  format_e;                     // data format
  ShaderSemanticType_e    type_e;                       // semantic type
  uint32_t                index_u32;                    // semantic type index

  void setName_v(const char* i_Text_pc)
  {
    Assert(strnlen(i_Text_pc, c_NameLength_u32) < c_NameLength_u32);
    strncpy(&name_ac[0], i_Text_pc, c_NameLength_u32);
  }

  ShaderInputElement_s()
    : format_e(e_SsfCount)
    , type_e(e_SstCount)
    , index_u32(0U)
  {
    setName_v("");
  }
};

// List of ShaderInputs
struct ShaderInput_s
{
  ShaderInputElement_s elements_as[c_MaxBufferLayoutElements_u32];
  uint32_t numElements_u32;

  ShaderInput_s()
    : elements_as()
    , numElements_u32(0U)
  {
  }

  void addElement_v(const ShaderInputElement_s& i_Element_rs)
  {
    Assert(numElements_u32 < c_MaxBufferLayoutElements_u32);
    if (numElements_u32 < c_MaxBufferLayoutElements_u32)
    {
      elements_as[numElements_u32].format_e   = i_Element_rs.format_e;
      elements_as[numElements_u32].index_u32  = i_Element_rs.index_u32;
      elements_as[numElements_u32].type_e     = i_Element_rs.type_e;
      elements_as[numElements_u32].setName_v(&i_Element_rs.name_ac[0]);

      ++numElements_u32;
    }
    else
    {
      ME_Debugger_F_Printf_v("ShaderInput_s::addElement_v failed");
    }
  }
};

enum EffectFileType_e
{
  e_EftVertex = 0,
  e_EftPixel,

  e_EftCount,
  e_EftInvalid
};

} // namespace me3d


#endif
