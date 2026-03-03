//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh(afshan.shaikh@magna.com)
///
//  --------------------------------------------------------------------------

#include "THAData.h"

namespace container
{

THAData::THAData()
  : DataContainer()
  , mutex_o()
  , someData_s32(0)
{

}

THAData::~THAData()
{

}

sint32_t THAData::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void THAData::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

void THAData::set_THA_SM_status(bool_t &i_SMToAlgo)
{
  mutex_o.take_b();
  bTHA_SM_status = i_SMToAlgo;
  mutex_o.give_v();
}

bool_t THAData::get_THA_SM_status()
{
  bool_t o_THA_SM_status;
  mutex_o.take_b();
  o_THA_SM_status = bTHA_SM_status;
  mutex_o.give_v();

  return o_THA_SM_status;
}

uint32_t THAData::getTHARuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_THA_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void THAData::setTHARuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_THA_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t THAData::getTHAThreadRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_THAThread_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void THAData::setTHAThreadRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_THAThread_rt_data = u_Runtime_u32;
  mutex_o.give_v();
} 

} // namespace container
