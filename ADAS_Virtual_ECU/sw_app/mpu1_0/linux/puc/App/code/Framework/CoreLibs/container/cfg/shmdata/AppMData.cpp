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

#include "AppMData.h"
#include <variants/VariantHelper.h>

namespace container
{

AppMData::AppMData()
  : DataContainer()
  , mutex_o()
//  , someData_s32(0)
//  , FrameID_u32(0)
//  , BootState_u8(static_cast<uint8_t>(variants::e_PerfMBootStateSNA))
{

}

AppMData::~AppMData()
{

}
#if 1
sint32_t AppMData::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}


uint32_t AppMData::getFrameID_u32()
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = FrameID_u32;
  mutex_o.give_v();
  return v_DataCopy_u32;
}

uint8_t AppMData::getBootState_u8()
{
  uint8_t v_DataCopy_u8 = 0;
  mutex_o.take_b();
  v_DataCopy_u8 = BootState_u8;
  mutex_o.give_v();
  return v_DataCopy_u8;
}

void AppMData::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

void AppMData::setFrameID_v(uint32_t i_FrameID_u32)
{
  mutex_o.take_b();
  FrameID_u32 = i_FrameID_u32;
  mutex_o.give_v();
}

void AppMData::setBootState_v(uint8_t i_BootState_u8)
{
  mutex_o.take_b();
  BootState_u8 = i_BootState_u8;
  mutex_o.give_v();
}

uint32_t AppMData::getAppMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_AppM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void AppMData::setAppMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_AppM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}
#endif
} // namespace container
