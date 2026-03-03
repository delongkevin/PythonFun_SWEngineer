#include "Common/Effect/EffectFileRenderStateBlock.h"

namespace me3d
{

EffectFileRenderStateBlock::EffectFileRenderStateBlock()
  : name_o("Uninitialized")
{

}

EffectFileRenderStateBlock::~EffectFileRenderStateBlock()
{
  // PRQA S 4261 2 // fine here
  // PRQA S 4631 1 // no exception...
  release_v();
}

void EffectFileRenderStateBlock::release_v()
{
  states_ao.resize(0);
}

bool_t EffectFileRenderStateBlock::initialize_b()
{
  return true;
}

bool_t EffectFileRenderStateBlock::addState_b(const EffectFileRenderState_s& i_State_rs)
{
  bool_t v_Added_b = (i_State_rs.type_e < e_EfstCount);

  if (true == v_Added_b)
  {
    states_ao.push_back(i_State_rs);
  }

  return v_Added_b;
}

const EffectFileRenderStateList_t& EffectFileRenderStateBlock::getStates_ro()const
{
  return states_ao;
}

void EffectFileRenderStateBlock::setName_v(const MEString& i_Name_ro)
{
  name_o = i_Name_ro;
}

const MEString& EffectFileRenderStateBlock::getName_ro() const
{
  return name_o;
}

bool_t EffectFileRenderStateBlock::isDefaultValue_b(const EffectFileRenderState_s& i_State_rs)
{
  bool_t v_IsDefault_b = false;

  EffectFileStateValueFormat_e v_Format_e = getEffectFileStateValueFormat_e(i_State_rs.type_e);

  switch (v_Format_e)
  {
  case e_EfsvfEnum: 
    {
      v_IsDefault_b = (i_State_rs.value_s.enum_e == getRenderStateDefaultValue_s(i_State_rs.type_e).enum_e);
      break;
    }
  case e_EfsvfFloat:
    {
      // PRQA S 3270 1 // fine here
      v_IsDefault_b = (i_State_rs.value_s.float_f32 == getRenderStateDefaultValue_s(i_State_rs.type_e).float_f32);
      break;
    }
  case e_EfsvfUint:
    {
      v_IsDefault_b = (i_State_rs.value_s.uint_u32 == getRenderStateDefaultValue_s(i_State_rs.type_e).uint_u32);
      break;
    }
  case e_EfsvfUnknown:  // fall through
  case e_EfsvfCount:    // fall through
  default:              { Assert(false); } break;
  }

  return v_IsDefault_b;
}

} // namespace me3d