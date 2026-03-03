//--------------------------------------------------------------------------
/// @file DLDData.cpp
/// @brief Contains the base functions for all DLD data
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
///
//  --------------------------------------------------------------------------

#include "DLDData.h"

namespace container
{

DLDData::DLDData()
  : DataContainer()
  , mutex_o()
  , someData_s32(0)
{

}

DLDData::~DLDData()
{

}

sint32_t DLDData::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void DLDData::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

uint32_t DLDData::getDLDRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_DLD_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void DLDData::setDLDRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_DLD_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t DLDData::getDLDThreadRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_DLDThread_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void DLDData::setDLDThreadRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_DLDThread_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

} // namespace container
