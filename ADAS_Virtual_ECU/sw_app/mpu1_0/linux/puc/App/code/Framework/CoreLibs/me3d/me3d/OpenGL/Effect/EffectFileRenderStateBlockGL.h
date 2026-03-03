#ifndef EFFECT_FILE_RENDER_STATE_BLOCK_GL_H
#define EFFECT_FILE_RENDER_STATE_BLOCK_GL_H

//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileRenderStateBlockGL.h                                                                         
/// @brief OpenGL specific class for controlling Render States
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
// PRQA S 2128 EOF // C++14 Autosar Standard permits

#include "Common/Effect/EffectFileRenderStateBlock.h"

#include "OpenGL/GLIncludes.h"

namespace me3d
{

class EffectFileRenderStateBlockGL : public EffectFileRenderStateBlock
{
public:
  EffectFileRenderStateBlockGL();
  virtual ~EffectFileRenderStateBlockGL();

  // Releases the state block
  virtual void release_v();

  // adds a new state to the Render State Block
  virtual bool_t addState_b(const EffectFileRenderState_s& i_State_rs);

  // commit all states to the state blocck to the device
  virtual void commit_v(uint32_t* i_StencilRef_pu32);

  // Restores all states that were set by commit_v();
  virtual void restoreChangedStates_v();

protected:
  // If the render state can be treated separately, it is set. Otherwise it is ignored
  static void commitIfSeparateRenderState_v(EffectFileStateType_e i_StateType_e, const EffectFileStateValue_s& i_StateValue_rs);

private:
  // manages sets of Render States, which are needed together when a glFunction is called.
  class CombinedRenderStates
  {
    // each combined render state has a dirty flag
    struct CombinedRenderState_s
    {
      CombinedRenderState_s() : wasSet_b(false) { }
      bool_t wasSet_b;
    };

    // manages the call to glBlendFunc / glBlendFuncSeparate
    struct BlendFunc_s : public CombinedRenderState_s
    {
      BlendFunc_s();
     
      bool_t separate_b;  // glBlendFunc / glBlendFuncSeparate
      GLenum src_u32;     // Src         / SrcRGB
      GLenum dst_u32;     // Dst         / DstRGB
      GLenum srcA_u32;    //  -          / SrcA
      GLenum dstA_u32;    //  -          / DstA

    } blendFunc_s;

    // manages the call to glBlendEquation / glBlendEquationSeparate
    struct BlendOp_s : public CombinedRenderState_s
    {
      BlendOp_s();

      bool_t separate_b;  // glBlendEquation / glBlendEquationSeparate
      GLenum op_u32;      // OpRGBA          / OpRGB
      GLenum opA_u32;     // -               / OpA
    
    } blendOp_s;

     // manages the call to glStencilOp / glStencilOpSeparate
    struct StencilOp_s : public CombinedRenderState_s
    {
      StencilOp_s();

      bool_t separate_b;   // glStencilOp    / glStencilOpSeparate
      GLenum sFail_u32;    // CCW and CW     / CW  (GL_BACK)
      GLenum zFail_u32;    // CCW and CW     / CW  (GL_BACK)
      GLenum sPass_u32;    // CCW and CW     / CW  (GL_BACK)
      GLenum sFailCCW_u32; // -              / CCW (GL_FRONT)
      GLenum zFailCCW_u32; // -              / CCW (GL_FRONT)
      GLenum sPassCCW_u32; // -              / CCW (GL_FRONT)

    } stencilOp_s;

    // manages the call to glStencilFunc / glStencilFunSeparate
    struct StencilFunc_s : public CombinedRenderState_s
    {
      StencilFunc_s();

      bool_t    separate_b; // glStencilFunc   / glStencilFuncSeparate
      GLenum    fun_u32;    // CCW and CW      / CW  (GL_BACK)
      uint32_t  ref_u32;    // CCW and CW      / CCW and CW
      uint32_t  mask_u32;   // CCW and CW      / CCW and CW
      GLenum    funCCW_u32; // -               / CCW (GL_FRONT) 

    } stencilFunc_s;

    // manages the call to glPolygonOffset
    struct DepthBias_s : public CombinedRenderState_s
    {
      DepthBias_s();

      sint32_t  constant_s32; // constant depth bias
      float32_t slope_f32;    // multiplied with depth slope

    } depthBias_s;

    // manages the call to glEnable(GL_DEPTH_TEST) and glDepthMask
    struct DepthTestAndWrite_s : public CombinedRenderState_s
    {
      DepthTestAndWrite_s();

      bool_t enableDepthTest_b;   // enable the depth test?
      bool_t enableDepthWrite_b;  // enable writing to depth buffer?

    } depthTestAndWrite_s;

  public:
    // PRQA S 4054 1 // intended.
    CombinedRenderStates() {}

    // if necessary, the state affects the corresponding CombinedRenderStates.
    void addIfCombinedType_v(const EffectFileRenderState_s& i_State_rs);

    // commit all combined render states
    void commitStates_v(const uint32_t* i_StencilRef_pu32);

    // restores all render states that were changed by commitStates_v
    // PRQA S 2505 1 // intended.
    void restoreChangedStates_v();

  private:
    void commitStates_v(bool_t i_DefaultStates_b, const uint32_t* i_StencilRef_pu32 = NULL);
  };

  CombinedRenderStates combinedRenderStates_o;
};

} // namespace me3d

#endif
