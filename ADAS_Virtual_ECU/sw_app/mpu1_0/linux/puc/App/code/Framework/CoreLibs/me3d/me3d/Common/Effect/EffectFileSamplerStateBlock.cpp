#include "Common/Effect/EffectFileSamplerStateBlock.h"

// PRQA S 4054 EOF // fine here

namespace me3d
{

EffectFileSamplerStateBlock::EffectFileSamplerStateBlock()
{

}

EffectFileSamplerStateBlock::~EffectFileSamplerStateBlock()
{
  // PRQA S 4261 2 // fine here
  // PRQA S 4631 1 // no exception
  release_v();
}

void EffectFileSamplerStateBlock::release_v()
{
  states_o.resize(0);
}

bool_t EffectFileSamplerStateBlock::initialize_b()
{
  return true;
}

bool_t EffectFileSamplerStateBlock::addState_b(const EffectFileSamplerState_s& i_State_rs)
{
  bool_t v_Added_b = (i_State_rs.type_e < e_EfstCount);

  if (true == v_Added_b)
  {
    states_o.push_back(i_State_rs);
  }

  return v_Added_b;
}

const SamplerStateList_t& EffectFileSamplerStateBlock::getStates_ro() const
{
  return states_o;
}

void EffectFileSamplerStateBlock::setName_v(const MEString& i_Name_ro)
{
  name_o = i_Name_ro;
}

const MEString& EffectFileSamplerStateBlock::getName_ro() const
{
  return name_o;
}

bool_t EffectFileSamplerStateBlock::isDeaultValue_b(const EffectFileSamplerState_s& i_State_rs)
{
  bool_t v_IsDefault_b = false;
  EffectFileStateValueFormat_e v_Fmt_e = getEffectFileStateValueFormat_e(i_State_rs.type_e);

  switch (v_Fmt_e)
  {
  case e_EfsvfEnum:
    {
      v_IsDefault_b = (i_State_rs.value_s.enum_e == getRenderStateDefaultValue_s(i_State_rs.type_e).enum_e);
      break;
    }
  case e_EfsvfFloat:
    {
      // PRQA S 3270 1 // fine for default value, no need for epsilon compare
      v_IsDefault_b = (i_State_rs.value_s.float_f32 == getRenderStateDefaultValue_s(i_State_rs.type_e).float_f32);
      break;
    }
  case e_EfsvfUint: 
    {
      v_IsDefault_b = (i_State_rs.value_s.uint_u32 == getRenderStateDefaultValue_s(i_State_rs.type_e).uint_u32);
      break;
    }
  case e_EfsvfUnknown: // fall through
  case e_EfsvfCount:   // fall through
  default:             
    { 
      Assert(false); 
      break;
    }
  }

  return v_IsDefault_b;
}

} // namespace me3d