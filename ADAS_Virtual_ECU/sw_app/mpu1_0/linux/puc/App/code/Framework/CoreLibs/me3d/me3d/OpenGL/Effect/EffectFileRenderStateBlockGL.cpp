#include "OpenGL/Effect/EffectFileRenderStateBlockGL.h"

#include "OpenGL/Effect/EffectFileTypesGL.h"

// PRQA S 4054 EOF // variables are initialized, but we don't use initializer lists her to make the code more readable

namespace me3d
{


EffectFileRenderStateBlockGL::EffectFileRenderStateBlockGL()
  : EffectFileRenderStateBlock()
  , combinedRenderStates_o()
{

}

EffectFileRenderStateBlockGL::~EffectFileRenderStateBlockGL()
{

}

void EffectFileRenderStateBlockGL::release_v()
{
  EffectFileRenderStateBlock::release_v();

  // reset combined states to default values
  combinedRenderStates_o = CombinedRenderStates();
}

bool_t EffectFileRenderStateBlockGL::addState_b(const EffectFileRenderState_s& i_State_rs)
{
  bool_t v_Added_b = EffectFileRenderStateBlock::addState_b(i_State_rs);

  if (true == v_Added_b)
  {
    combinedRenderStates_o.addIfCombinedType_v(i_State_rs);
  }
  
  return v_Added_b;
}

void EffectFileRenderStateBlockGL::commit_v(uint32_t* i_StencilRef_pu32)
{
  size_t v_size = states_ao.size();
  for (size_t v_i_t = 0U; v_i_t < v_size; ++v_i_t)
  {
    // single states are set, combined ignored
    EffectFileRenderState_s& v_State_rs = states_ao[v_i_t];

    commitIfSeparateRenderState_v(v_State_rs.type_e, v_State_rs.value_s);
  }

  combinedRenderStates_o.commitStates_v(i_StencilRef_pu32);
}

void EffectFileRenderStateBlockGL::restoreChangedStates_v()
{
  combinedRenderStates_o.restoreChangedStates_v();

  size_t v_size = states_ao.size();
  for (size_t v_i_t = 0U; v_i_t < v_size; ++v_i_t)
  {
    // single states are set, combined ignored
    EffectFileRenderState_s& v_State_rs = states_ao[v_i_t];

    commitIfSeparateRenderState_v(v_State_rs.type_e, getRenderStateDefaultValue_s(v_State_rs.type_e));
  }
}

void EffectFileRenderStateBlockGL::commitIfSeparateRenderState_v(EffectFileStateType_e i_StateType_e, const EffectFileStateValue_s& i_StateValue_rs)
{
  bool_t v_CheckForError_b = true;

  switch (i_StateType_e)
  {
  case e_EfstNull:
    {
      v_CheckForError_b = false;
      Assert(false);
      break;
    }
  case e_EfstZEnable:
  case e_EfstZWriteEnable:
    {
      // handled by combined states
      v_CheckForError_b = false;
    }
    break;
  case e_EfstZFunc:
    {
      glDepthFunc(effectFileStateValueTypesToGLEnums_u32(i_StateValue_rs.enum_e));
      break;
    }
  case e_EfstFillMode:
    {
      // glPolygonMode() not available in GL ES 
      v_CheckForError_b = false;
      break;
    }
  case e_EfstCullMode:
    {
      switch (i_StateValue_rs.enum_e)
      {
      case e_EfsvCW:
      case e_EfsvCCW:
        {
          glEnable(GL_CULL_FACE);
          glCullFace(effectFileStateValueTypesToGLEnums_u32(i_StateValue_rs.enum_e));
          break;
        }
      case e_EfsvNone:
        {
          glDisable(GL_CULL_FACE);
          break;
        }
      default:
        {
          ME_Debugger_F_Printf_v("Invalid State value");
          break;
        }
        
      } 

      break;
    }
  case e_EfstAlphaBlendEnable:
    {
      if (i_StateValue_rs.enum_e == e_EfsvTrue)
      {
        glEnable(GL_BLEND);
      }
      else
      {
        // check for invalid state value
        Assert(i_StateValue_rs.enum_e == e_EfsvFalse);

        glDisable(GL_BLEND);
      }

      break;
    }
  case e_EfstIndependentBlendEnable:
    {
      if (i_StateValue_rs.enum_e != e_EfsvFalse)
      {
        ME_Debugger_F_Printf_v("Independent Blend-Modes are not supported before OpenGL 4.0");
        Assert(false);
      }
      v_CheckForError_b = false;
      break;
    }
  case e_EfstAlphaToCoverageEnable:
    {
      if (i_StateValue_rs.enum_e == e_EfsvTrue)
      {
        glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
      }
      else
      {
        Assert(i_StateValue_rs.enum_e == e_EfsvFalse);

        glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE);
      }
      break;
    }

  case e_EfstSeparateAlphaBlendEnable:  // fall through
  case e_EfstSrcBlend:                  // fall through
  case e_EfstDestBlend:                 // fall through
  case e_EfstBlendOp:                   // fall through
  case e_EfstSrcBlendAlpha:             // fall through
  case e_EfstDestBlendAlpha:            // fall through
  case e_EfstBlendOpAlpha:              
    {
      v_CheckForError_b = false;
      break;
    }

  case e_EfstStencilEnable:
    {
      if (i_StateValue_rs.enum_e == e_EfsvTrue)
      {
        glEnable(GL_STENCIL_TEST);
      }
      else
      {
        Assert(i_StateValue_rs.enum_e == e_EfsvFalse);

        glDisable(GL_STENCIL_TEST);
      }
      break;
    }
  case e_EfstTwoSidedStencilMode:     // fall through
  case e_EfstStencilFail:             // fall through
  case e_EfstStencilZFail:            // fall through
  case e_EfstStencilPass:             // fall through
  case e_EfstStencilFunc:             // fall through
  case e_EfstStencilRef:              // fall through
  case e_EfstStencilMask:             
    {
      // handled by combined states
      v_CheckForError_b = false;
      break;
    }

  case e_EfstStencilWriteMask:
    {
      glStencilMask(i_StateValue_rs.uint_u32);
      break;
    }

  case e_EfstCCWStencilFail:
  case e_EfstCCWStencilZFail:
  case e_EfstCCWStencilPass:
  case e_EfstCCWStencilFunc:
    {
      // handled by combined states
      v_CheckForError_b = false;
      break;
    }
  case e_EfstMultisampleAntialias:
    {
      if (i_StateValue_rs.enum_e == e_EfsvTrue)
      {
        glEnable(GL_MULTISAMPLES_NV);
      }
      else
      {
        Assert(i_StateValue_rs.enum_e == e_EfsvFalse);

        glDisable(GL_MULTISAMPLES_NV);
      }
      break;
    }
  case e_EfstMultisampleMask:
    {
      // only supported for OpenGL ES 3.1
      Assert(false);
      v_CheckForError_b = false;
    
      break;
    }
  case e_EfstScissorTestEnable:
    {
      if (i_StateValue_rs.enum_e == e_EfsvTrue)
      {
        glEnable(GL_SCISSOR_TEST);
      }
      else
      {
        // check for Invalid state Value
        Assert(i_StateValue_rs.enum_e == e_EfsvFalse);

        glDisable(GL_SCISSOR_TEST);
      }
      break;
    }
  case e_EfstSlopeScaleDepthBias:   // fall through
  case e_EfstDepthBias:
    {
      // handled by combined states
      v_CheckForError_b = false;
      break;
    }
  case e_EfstColorWriteEnable:
    {
      glColorMask(i_StateValue_rs.uint_u32 & 0x1, 
                  i_StateValue_rs.uint_u32 & 0x2, 
                  i_StateValue_rs.uint_u32 & 0x4, 
                  i_StateValue_rs.uint_u32 & 0x8);
      break;
    }
  default:
    {
      ME_Debugger_F_Printf_v("unknown render state \n");
      Assert(false);
      break;
    }
  } 

  if (true == v_CheckForError_b)
  {
    Assert(getGLError_b() == false);
  }

}

// --- CombinedRenderStates ---

EffectFileRenderStateBlockGL::CombinedRenderStates::BlendFunc_s::BlendFunc_s()
{
  separate_b = (getRenderStateDefaultValue_s(e_EfstSeparateAlphaBlendEnable).enum_e == e_EfsvTrue) ? true : false;
  src_u32    = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstSrcBlend).enum_e);
  dst_u32    = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstDestBlend).enum_e);
  srcA_u32   = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstSrcBlendAlpha).enum_e);
  dstA_u32   = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstDestBlendAlpha).enum_e);
}

EffectFileRenderStateBlockGL::CombinedRenderStates::BlendOp_s::BlendOp_s()
{
  separate_b = (getRenderStateDefaultValue_s(e_EfstSeparateAlphaBlendEnable).enum_e == e_EfsvTrue) ? true : false;
  op_u32     = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstBlendOp).enum_e);
  opA_u32    = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstBlendOpAlpha).enum_e);
}

EffectFileRenderStateBlockGL::CombinedRenderStates::StencilOp_s::StencilOp_s()
{
  separate_b    = (getRenderStateDefaultValue_s(e_EfstTwoSidedStencilMode).enum_e == e_EfsvTrue) ? true : false;
  sFail_u32     = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstStencilFail).enum_e);
  zFail_u32     = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstStencilZFail).enum_e);
  sPass_u32     = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstStencilPass).enum_e);
  sFailCCW_u32  = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstCCWStencilFail).enum_e);
  zFailCCW_u32  = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstCCWStencilZFail).enum_e);
  sPassCCW_u32  = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstCCWStencilPass).enum_e);
}

EffectFileRenderStateBlockGL::CombinedRenderStates::StencilFunc_s::StencilFunc_s()
{
  separate_b    = (getRenderStateDefaultValue_s(e_EfstTwoSidedStencilMode).enum_e == e_EfsvTrue) ? true : false;
  fun_u32       = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstStencilFunc).enum_e);
  ref_u32       = getRenderStateDefaultValue_s(e_EfstStencilRef).uint_u32;
  mask_u32      = getRenderStateDefaultValue_s(e_EfstStencilMask).uint_u32;
  funCCW_u32    = effectFileStateValueTypesToGLEnums_u32(getRenderStateDefaultValue_s(e_EfstCCWStencilFunc).enum_e);
}

EffectFileRenderStateBlockGL::CombinedRenderStates::DepthBias_s::DepthBias_s()
{
  constant_s32  = getRenderStateDefaultValue_s(e_EfstDepthBias).uint_u32; 
  slope_f32     = getRenderStateDefaultValue_s(e_EfstSlopeScaleDepthBias).float_f32;
}

EffectFileRenderStateBlockGL::CombinedRenderStates::DepthTestAndWrite_s::DepthTestAndWrite_s()
{
  enableDepthTest_b   = (getRenderStateDefaultValue_s(e_EfstZEnable).enum_e == e_EfsvTrue) ? true : false; 
  enableDepthWrite_b  = (getRenderStateDefaultValue_s(e_EfstZEnable).enum_e == e_EfsvTrue) ? true : false;
}

void EffectFileRenderStateBlockGL::CombinedRenderStates::addIfCombinedType_v(const EffectFileRenderState_s& i_State_rs)
{
  // different blend func / ops for different rendertargets not supported until OpenGL 4.0
  Assert(i_State_rs.slot_u32 == 0);

  switch (i_State_rs.type_e)
  {
  case e_EfstZEnable:
    {
      depthTestAndWrite_s.enableDepthTest_b = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      depthTestAndWrite_s.wasSet_b          = true;
      break;
    }
  case e_EfstZWriteEnable:
    {
      depthTestAndWrite_s.enableDepthWrite_b = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      depthTestAndWrite_s.wasSet_b           = true;
      break;
    }
  case e_EfstSeparateAlphaBlendEnable:
    {
      blendFunc_s.separate_b = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      blendFunc_s.wasSet_b   = true;

      blendOp_s.separate_b   = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      blendOp_s.wasSet_b     = true;
      break;
    }
  case e_EfstSrcBlend:  
    {
      blendFunc_s.src_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstDestBlend:
    {
      blendFunc_s.dst_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstSrcBlendAlpha:
    {
      blendFunc_s.srcA_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendFunc_s.wasSet_b  = true;
      break;
    }
  case e_EfstDestBlendAlpha:
    {
      blendFunc_s.dstA_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstBlendOp:
    {
      blendOp_s.op_u32   = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendOp_s.wasSet_b = true;
      break;
    }
  case e_EfstBlendOpAlpha:
    {
      blendOp_s.opA_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      blendOp_s.wasSet_b = true;
      break;
    }
  case e_EfstTwoSidedStencilMode:
    {
      stencilFunc_s.separate_b = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      stencilFunc_s.wasSet_b   = true;

      stencilOp_s.separate_b   = (i_State_rs.value_s.enum_e == e_EfsvTrue) ? true : false;
      stencilOp_s.wasSet_b     = true;
      break;
    }
  case e_EfstStencilFail:
    {
      stencilOp_s.sFail_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b  = true;
      break;
    }
  case e_EfstStencilZFail:
    {
      stencilOp_s.zFail_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b  = true;
      break;
    }
    
  case e_EfstStencilPass:
    {
      stencilOp_s.sPass_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b   = true;
      break;
    }
  case e_EfstStencilFunc:
    {
      stencilFunc_s.fun_u32  = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstStencilRef:
    {
      stencilFunc_s.ref_u32  = i_State_rs.value_s.uint_u32;
      stencilFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstStencilMask:
    {
      stencilFunc_s.mask_u32 = i_State_rs.value_s.uint_u32;
      stencilFunc_s.wasSet_b = true;
      break;
    }
  case e_EfstCCWStencilFail:
    {
      stencilOp_s.sFailCCW_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b     = true;
      break;
    }
  case e_EfstCCWStencilZFail:
    {
      stencilOp_s.zFailCCW_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b     = true;
      break;
    }
  case e_EfstCCWStencilPass:
    {
      stencilOp_s.sPassCCW_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilOp_s.wasSet_b     = true;
      break;
    }
  case e_EfstCCWStencilFunc:
    {
      stencilFunc_s.funCCW_u32 = effectFileStateValueTypesToGLEnums_u32(i_State_rs.value_s.enum_e);
      stencilFunc_s.wasSet_b   = true;
      break;
    }
  case e_EfstDepthBias:
    {
      depthBias_s.constant_s32 = i_State_rs.value_s.uint_u32;
      depthBias_s.wasSet_b     = true;
      break;
    }
  case e_EfstSlopeScaleDepthBias:
	  {
		depthBias_s.slope_f32 = i_State_rs.value_s.float_f32;
		depthBias_s.wasSet_b  = true;
		break;
	  }

  default:
	  {
		// no compound state
		break;
	  }
  }

}

void EffectFileRenderStateBlockGL::CombinedRenderStates::commitStates_v(const uint32_t* i_StencilRef_pu32)
{
  commitStates_v(false, i_StencilRef_pu32);
}

void EffectFileRenderStateBlockGL::CombinedRenderStates::restoreChangedStates_v()
{
  commitStates_v(true, NULL);
}

void EffectFileRenderStateBlockGL::CombinedRenderStates::commitStates_v(bool_t i_DefaultStates_b, const uint32_t* i_StencilRef_pu32 /*= NULL*/)
{
  // internally stored states
  BlendFunc_s         v_BlendFunc_s         = blendFunc_s;
  BlendOp_s           v_BlendOp_s           = blendOp_s;
  StencilOp_s         v_StencilOp_s         = stencilOp_s;
  StencilFunc_s       v_StencilFunc_s       = stencilFunc_s;
  DepthBias_s         v_DepthBias_s         = depthBias_s;
  DepthTestAndWrite_s v_DepthTestAndWrite_s = depthTestAndWrite_s;

  if (true == i_DefaultStates_b)
  {
    // set to default states
    v_BlendFunc_s           = BlendFunc_s();
    v_BlendOp_s             = BlendOp_s();
    v_StencilOp_s           = StencilOp_s();
    v_StencilFunc_s         = StencilFunc_s();
    v_DepthBias_s           = DepthBias_s();
    v_DepthTestAndWrite_s   = DepthTestAndWrite_s();

    // adopt dirty bit, only reset those that were set
    v_BlendFunc_s.wasSet_b          = blendFunc_s.wasSet_b;                 
    v_BlendOp_s.wasSet_b            = blendOp_s.wasSet_b;           
    v_StencilOp_s.wasSet_b          = stencilOp_s.wasSet_b;
    v_StencilFunc_s.wasSet_b        = stencilFunc_s.wasSet_b;
    v_DepthBias_s.wasSet_b          = depthBias_s.wasSet_b;
    v_DepthTestAndWrite_s.wasSet_b  = depthTestAndWrite_s.wasSet_b;
  }

  if (true == v_BlendFunc_s.wasSet_b)
  {
    if (true == v_BlendFunc_s.separate_b)
    {
      glBlendFuncSeparate(v_BlendFunc_s.src_u32, v_BlendFunc_s.dst_u32, v_BlendFunc_s.srcA_u32, v_BlendFunc_s.dstA_u32);
    }
    else
    {
      glBlendFunc(v_BlendFunc_s.src_u32, v_BlendFunc_s.dst_u32);
    }

    Assert(getGLError_b() == false);
  }

  if (true == v_BlendOp_s.wasSet_b)
  {
    if (true == v_BlendOp_s.separate_b)
    {
      glBlendEquationSeparate(v_BlendOp_s.op_u32, v_BlendOp_s.opA_u32);
    }
    else
    {
      glBlendEquation(v_BlendOp_s.op_u32);
    }

    Assert(getGLError_b() == false);
  }

  if (true == v_StencilOp_s.wasSet_b)
  {
    if (true == v_StencilOp_s.separate_b)
    {
      glStencilOpSeparate(GL_BACK,  v_StencilOp_s.sFail_u32,    v_StencilOp_s.zFail_u32,    v_StencilOp_s.sPass_u32);
      glStencilOpSeparate(GL_FRONT, v_StencilOp_s.sFailCCW_u32, v_StencilOp_s.zFailCCW_u32, v_StencilOp_s.sPassCCW_u32);
    }
    else
    {
      glStencilOp(v_StencilOp_s.sFail_u32, v_StencilOp_s.zFail_u32, v_StencilOp_s.sPass_u32);
    }

    Assert(getGLError_b() == false);
  }

  if (true == v_StencilFunc_s.wasSet_b)
  {
    if (true == v_StencilFunc_s.separate_b)
    {
      glStencilFuncSeparate(GL_BACK,  v_StencilFunc_s.fun_u32,    v_StencilFunc_s.ref_u32, v_StencilFunc_s.mask_u32);
      glStencilFuncSeparate(GL_FRONT, v_StencilFunc_s.funCCW_u32, v_StencilFunc_s.ref_u32, v_StencilFunc_s.mask_u32);
    }
    else
    {
      uint32_t v_StencilRef_u32 = (NULL != i_StencilRef_pu32) ? *i_StencilRef_pu32 : v_StencilFunc_s.ref_u32;

      glStencilFunc(v_StencilFunc_s.fun_u32, v_StencilRef_u32, v_StencilFunc_s.mask_u32);
    }

    Assert(getGLError_b() == false);
  }

  if (true == v_DepthBias_s.wasSet_b)
  {

    // PRQA S 3270 1 // fine here because the default value is well defined (0.0F)
    if ((0.0F == v_DepthBias_s.slope_f32) && (0 == v_DepthBias_s.constant_s32))
    {
      // no depth bias
      glDisable(GL_POLYGON_OFFSET_FILL);
    }
    else
    {
      glEnable(GL_POLYGON_OFFSET_FILL);
    }

    glPolygonOffset(v_DepthBias_s.slope_f32, static_cast<float32_t>(v_DepthBias_s.constant_s32));
    Assert(getGLError_b() == false);
  }

  if (true == v_DepthTestAndWrite_s.wasSet_b)
  {
    if (v_DepthTestAndWrite_s.enableDepthTest_b /*|| v_DepthTestAndWrite_s.enableDepthWrite_b*/)
    {
      glEnable(GL_DEPTH_TEST);
    }
    else
    {
      glDisable(GL_DEPTH_TEST);
    }

    if (true == v_DepthTestAndWrite_s.enableDepthWrite_b)
    {
      glDepthMask(GL_TRUE);
    }
    else
    {
      glDepthMask(GL_FALSE);
    }

    Assert(getGLError_b() == false);
  }

}

} // namespace me3d
