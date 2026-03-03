//--------------------------------------------------------------------------
/// @file TAD2Data.cpp
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#include "TAD2Data.h"

namespace container
{

TAD2Data::TAD2Data()
  : DataContainer()
  , mutex_o()
  , someData_s32(0)
{

}

TAD2Data::~TAD2Data()
{

}

sint32_t TAD2Data::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void TAD2Data::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

uint32_t TAD2Data::getTAD2Runtime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_TAD_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void TAD2Data::setTADRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_TAD_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t TAD2Data::getTAD2ThreadRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_TADThread_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void TAD2Data::setTADThreadRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_TADThread_rt_data = u_Runtime_u32;
  mutex_o.give_v();
} 
} // namespace container
