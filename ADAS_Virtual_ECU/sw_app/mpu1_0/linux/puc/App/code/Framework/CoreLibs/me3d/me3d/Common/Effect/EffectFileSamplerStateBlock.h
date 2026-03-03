
// PRQA S 2100 EOF // public members used here by design.
// PRQA S 2127 EOF // C++14 Autosar Standard permits

#ifndef EFFECT_FILE_SAMPLER_STATE_BLOCK_H
#define EFFECT_FILE_SAMPLER_STATE_BLOCK_H

#include "MeclTypeDefs.h"
#include "Common/Effect/EffectFileTypes.h"

namespace me3d
{

struct EffectFileSamplerState_s
{
  // PRQA S 4054 1 // intended (performance). Default constructor doesn't make sense
  EffectFileSamplerState_s() {}
  EffectFileSamplerState_s(EffectFileStateType_e i_StateType_e, const EffectFileStateValue_s& i_StateValue_rs)
    : type_e(i_StateType_e)
    , value_s(i_StateValue_rs)
  {
  }

  // sampler state type
  EffectFileStateType_e type_e;
  
  // sampler state value
  EffectFileStateValue_s value_s;
};

// typedef for the sampler state list
typedef mepl::vector<EffectFileSamplerState_s> SamplerStateList_t;

class EffectFileSamplerStateBlock
{
public:
  EffectFileSamplerStateBlock();
  virtual ~EffectFileSamplerStateBlock();

  // releases the sampler state block
  virtual void release_v();

  // Creates the sampler state block
  virtual bool_t initialize_b();

  // adds a new state to the sampler state block. Returns true if state was valid
  virtual bool_t addState_b(const EffectFileSamplerState_s& i_State_rs);

  // returns all sampler states 
  const SamplerStateList_t& getStates_ro() const;

  // Sets a new name for the state block
  void setName_v(const MEString& i_Name_ro);

  // Gets the sampler state block's name
  const MEString& getName_ro() const;

  // Returns true when the state is equal  to the default state
  static bool_t isDeaultValue_b(const EffectFileSamplerState_s& i_State_rs);

protected:
  // the name of the state block
  MEString            name_o;

  // list holding all added states
  SamplerStateList_t  states_o;
};


} // namespace me3d

#endif
