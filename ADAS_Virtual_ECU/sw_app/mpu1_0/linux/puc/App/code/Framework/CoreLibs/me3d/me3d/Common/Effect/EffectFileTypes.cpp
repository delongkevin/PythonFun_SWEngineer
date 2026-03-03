#include "EffectFileTypes.h"
#include <float.h>

namespace me3d
{

EffectFileStateValueFormat_e getEffectFileStateValueFormat_e(EffectFileStateType_e i_Type_e)
{
  EffectFileStateValueFormat_e v_Fmt_e = e_EfsvfUnknown;

  switch (i_Type_e)
  {
  case e_EfstNull:                      { v_Fmt_e = e_EfsvfUnknown; } break;

  case e_EfstZEnable:                   { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstZFunc:                     { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstZWriteEnable:              { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstFillMode:                  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstCullMode:                  { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstAlphaBlendEnable:          { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstSeparateAlphaBlendEnable:  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstIndependentBlendEnable:    { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstAlphaToCoverageEnable:     { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstSrcBlend:                  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstDestBlend:                 { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstBlendOp:                   { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstSrcBlendAlpha:             { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstDestBlendAlpha:            { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstBlendOpAlpha:              { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstStencilEnable:             { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstTwoSidedStencilMode:       { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstStencilFail:               { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstStencilZFail:              { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstStencilPass:               { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstStencilFunc:               { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstStencilRef:                { v_Fmt_e = e_EfsvfUint;    } break;
  case e_EfstStencilMask:               { v_Fmt_e = e_EfsvfUint;    } break;
  case e_EfstStencilWriteMask:          { v_Fmt_e = e_EfsvfUint;    } break;

  case e_EfstCCWStencilFail:            { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstCCWStencilZFail:           { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstCCWStencilPass:            { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstCCWStencilFunc:            { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstMultisampleAntialias:      { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstMultisampleMask:           { v_Fmt_e = e_EfsvfUint;    } break;

  case e_EfstScissorTestEnable:         { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstSlopeScaleDepthBias:       { v_Fmt_e = e_EfsvfFloat;   } break;
  case e_EfstDepthBias:                 { v_Fmt_e = e_EfsvfUint;    } break;

  case e_EfstColorWriteEnable:          { v_Fmt_e = e_EfsvfUint;    } break;

  case e_EfstFilter:                    { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstAddress:                   { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstAddressU:                  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstAddressV:                  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstAddressW:                  { v_Fmt_e = e_EfsvfEnum;    } break;
  case e_EfstMaxAnisotropy:             { v_Fmt_e = e_EfsvfUint;    } break;
  case e_EfstComparisonFunc:            { v_Fmt_e = e_EfsvfEnum;    } break;

  case e_EfstMipLodBias:                { v_Fmt_e = e_EfsvfFloat;   } break;
  case e_EfstMinLod:                    { v_Fmt_e = e_EfsvfFloat;   } break;
  case e_EfstMaxLod:                    { v_Fmt_e = e_EfsvfFloat;   } break;
  case e_EfstCount:                     { v_Fmt_e = e_EfsvfUnknown; } break;
  default:                              { v_Fmt_e = e_EfsvfUnknown; } break;
  }

  Assert(v_Fmt_e != e_EfsvfUnknown);
  return v_Fmt_e;
}

EffectFileStateValue_s getRenderStateDefaultValue_s(EffectFileStateType_e i_Type_e)
{
  EffectFileStateValue_s v_Val_s;

  switch (i_Type_e)
  {
  case e_EfstNull:                        { v_Val_s.enum_e = e_EfsvNone;      } break;

  case e_EfstZEnable:                     { v_Val_s.enum_e = e_EfsvTrue;      } break;
  case e_EfstZFunc:                       { v_Val_s.enum_e = e_EfsvLess;      } break;
  case e_EfstZWriteEnable:                { v_Val_s.enum_e = e_EfsvTrue;      } break;

  case e_EfstFillMode:                    { v_Val_s.enum_e = e_EfsvSolid;     } break;
  case e_EfstCullMode:                    { v_Val_s.enum_e = e_EfsvCCW;       } break;

  case e_EfstAlphaBlendEnable:            { v_Val_s.enum_e = e_EfsvFalse;     } break;
  case e_EfstSeparateAlphaBlendEnable:    { v_Val_s.enum_e = e_EfsvFalse;     } break;
  case e_EfstIndependentBlendEnable:      { v_Val_s.enum_e = e_EfsvFalse;     } break;
  case e_EfstAlphaToCoverageEnable:       { v_Val_s.enum_e = e_EfsvFalse;     } break;

  case e_EfstSrcBlend:                    { v_Val_s.enum_e = e_EfsvOne;       } break;
  case e_EfstDestBlend:                   { v_Val_s.enum_e = e_EfsvZero;      } break;
  case e_EfstBlendOp:                     { v_Val_s.enum_e = e_EfsvAdd;       } break;

  case e_EfstSrcBlendAlpha:               { v_Val_s.enum_e = e_EfsvOne;       } break;
  case e_EfstDestBlendAlpha:              { v_Val_s.enum_e = e_EfsvZero;      } break;
  case e_EfstBlendOpAlpha:                { v_Val_s.enum_e = e_EfsvAdd;       } break;

  case e_EfstStencilEnable:               { v_Val_s.enum_e = e_EfsvFalse;     } break;
  case e_EfstTwoSidedStencilMode:         { v_Val_s.enum_e = e_EfsvFalse;     } break;

  case e_EfstStencilFail:                 { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstStencilZFail:                { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstStencilPass:                 { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstStencilFunc:                 { v_Val_s.enum_e = e_EfsvAlways;    } break;

  case e_EfstStencilRef:                  { v_Val_s.uint_u32 = 0U;            } break;
  case e_EfstStencilMask:                 { v_Val_s.uint_u32 = 0xFFFFFFFFU;   } break;
  case e_EfstStencilWriteMask:            { v_Val_s.uint_u32 = 0xFFFFFFFFU;   } break;

  case e_EfstCCWStencilFail:              { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstCCWStencilZFail:             { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstCCWStencilPass:              { v_Val_s.enum_e = e_EfsvKeep;      } break;
  case e_EfstCCWStencilFunc:              { v_Val_s.enum_e = e_EfsvAlways;    } break;
  case e_EfstMultisampleAntialias:        { v_Val_s.enum_e = e_EfsvTrue;      } break;
  case e_EfstMultisampleMask:             { v_Val_s.uint_u32 = 0xFFFFFFFFU;   } break;
  
  case e_EfstScissorTestEnable:           { v_Val_s.enum_e = e_EfsvFalse;     } break;
  case e_EfstSlopeScaleDepthBias:         { v_Val_s.float_f32 = 0.0F;         } break;
  case e_EfstDepthBias:                   { v_Val_s.uint_u32 = 0U;            } break;

  case e_EfstColorWriteEnable:            { v_Val_s.uint_u32 = 0x0000000F;    } break;

  case e_EfstFilter:                      { v_Val_s.enum_e = e_EfsvLinear;    } break;
  case e_EfstAddress:                     { v_Val_s.enum_e = e_EfsvWrap;      } break;
  case e_EfstAddressU:                    { v_Val_s.enum_e = e_EfsvWrap;      } break;
  case e_EfstAddressV:                    { v_Val_s.enum_e = e_EfsvWrap;      } break;
  case e_EfstAddressW:                    { v_Val_s.enum_e = e_EfsvWrap;      } break;

  case e_EfstMaxAnisotropy:               { v_Val_s.uint_u32 = 16U;           } break;
  case e_EfstComparisonFunc:              { v_Val_s.enum_e = e_EfsvAlways;    } break;
  case e_EfstMipLodBias:                  { v_Val_s.float_f32 = 0.0F;         } break;
  case e_EfstMinLod:                      { v_Val_s.float_f32 = -FLT_MAX;     } break;
  case e_EfstMaxLod:                      { v_Val_s.float_f32 = FLT_MAX;      } break;
  case e_EfstCount:                       // fall through
  default:                                { Assert(false);                    } break;
  }

  return v_Val_s;
}

} // namespace me3d