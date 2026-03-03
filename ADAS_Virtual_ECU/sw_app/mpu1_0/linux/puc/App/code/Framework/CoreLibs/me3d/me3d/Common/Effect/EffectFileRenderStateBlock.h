// PRQA S 2100 EOF // public members used here by design.
// PRQA S 2128 EOF // C++14 Autosar Standard permits
// PRQA S 2127 EOF // C++14 Autosar Standard permits


#ifndef EFFECT_FILE_RENDER_STATE_BLOCK_H
#define EFFECT_FILE_RENDER_STATE_BLOCK_H

//--------------------------------------------------------------------------                                                                                                           
/// @file EffectFileRenderStateBlock.h                                                                         
/// @brief API independent base class for controlling a list of Render States
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#include "MeclTypeDefs.h"
#include "Common/Effect/EffectFileTypes.h"

 

namespace me3d
{

struct EffectFileRenderState_s
{
  // PRQA S 4054 1 // intended (performance).
  EffectFileRenderState_s() {}
  EffectFileRenderState_s(EffectFileStateType_e i_Type_e, const EffectFileStateValue_s& i_Value_rs, uint32_t i_Slot_u32)
    : type_e(i_Type_e)
    , value_s(i_Value_rs)
    , slot_u32(i_Slot_u32)
  {
  }

  EffectFileStateType_e   type_e;
  EffectFileStateValue_s  value_s;
  uint32_t                slot_u32;
};

// typedef for the render state list
typedef mepl::vector<EffectFileRenderState_s> EffectFileRenderStateList_t;

class EffectFileRenderStateBlock
{
public:
  EffectFileRenderStateBlock();
  virtual ~EffectFileRenderStateBlock();

  // releases the Render State Block
  virtual void release_v();

  // initializes the Render State Block
  virtual bool_t initialize_b();

  // adds a new state to the Render State Block
  virtual bool_t addState_b(const EffectFileRenderState_s& i_State_rs);

  // Gets a list of all render states
  const EffectFileRenderStateList_t& getStates_ro() const;

  // sets the name for the Render State Block
  void setName_v(const MEString& i_Name_ro);

  // gets the name of the Render State Block
  const MEString& getName_ro() const;

  // Set all states of the state block to the device
  virtual void commit_v(uint32_t* i_StencilRef_pu32) = 0;

  // Restore all states that were overwritten by commit_v()  to default states
  virtual void restoreChangedStates_v() = 0;

  // Returns true if the state is equal to the default value
  static bool_t isDefaultValue_b(const EffectFileRenderState_s& i_State_rs);

protected:
  // Name of the State Block
  MEString                     name_o;

  // List of all states associated with this block
  EffectFileRenderStateList_t states_ao;

};


} // namespace m3d

#endif
