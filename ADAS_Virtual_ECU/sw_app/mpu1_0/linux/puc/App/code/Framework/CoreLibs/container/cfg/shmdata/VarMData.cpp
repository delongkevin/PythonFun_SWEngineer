//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "VarMData.h"

namespace container
{

VarMData::VarMData()
  : DataContainer()
  , mutex_o()
  , LanguageID_u32(0)
{

}

VarMData::~VarMData()
{

}

uint32_t VarMData::getLanguageID_u32(void) const
{
  return LanguageID_u32;
}

void VarMData::setLanguageID_v(uint32_t i_Data_u32)
{
  mutex_o.take_b();
  LanguageID_u32 = i_Data_u32;
  mutex_o.give_v();
}

uint32_t VarMData::getVarMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_VarM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void VarMData::setVarMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_VarM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

} // namespace container
