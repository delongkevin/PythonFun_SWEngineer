
// PRQA S 2100 EOF // public members used here by design.
// PRQA S 2128 EOF // C++14 Autosar Standard permits

#ifndef EFFECT_FILE_SAMPLER_STATE_BLOCK_GL_H
#define EFFECT_FILE_SAMPLER_STATE_BLOCK_GL_H

#include "Common/Effect/EffectFileTypes.h"
#include "Common/Effect/EffectFileSamplerStateBlock.h"
#include "OpenGL/GLIncludes.h"

namespace me3d
{

class EffectFileSamplerStateBlockGL : public EffectFileSamplerStateBlock
{
public:
  EffectFileSamplerStateBlockGL();
  virtual ~EffectFileSamplerStateBlockGL();

  // releases the sampler state block
  virtual void release_v();

  // adds a new state to the sampler state block. Returns true if state was valid
  virtual bool_t addState_b(const EffectFileSamplerState_s& i_State_rs);

  // commits all states of the state block to the device
  void commitStates_v(GLenum i_TextureType_u32, GLuint i_TextureId_u32);

  // Resets all states that were set by commitStates_v();
  void restoreChangedStates_v(GLenum i_TextureType_u32, GLuint i_TextureId_u32);

protected:
  // commits a single state
  static void commitState_v(GLenum i_TextureType_u32, EffectFileStateType_e i_Type_e, const EffectFileStateValue_s& i_Value_rs);


  // Anisotropy and Filter Type should be handled together.
  struct FilterState_s
  {
    FilterState_s();
    void commitStatesIfNecessary_v(GLenum i_TextureType_u32)const;

    bool_t                 filterTypeWasSet_b;
    EffectFileStateValue_s filterType_s;
    uint32_t               anisotropyLevel_u32;
  } filterState_s;


};

} // namespace me3d

#endif