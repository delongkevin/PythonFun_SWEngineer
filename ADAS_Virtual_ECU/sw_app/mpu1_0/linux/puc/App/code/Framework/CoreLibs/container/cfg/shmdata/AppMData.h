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

#ifndef CONTAINER_APPM_DATA_H
#define CONTAINER_APPM_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"


namespace container
{

class AppMData : public DataContainer
{
public:
  AppMData();
  virtual ~AppMData();

  sint32_t getSomeData_s32();
  uint32_t getFrameID_u32();
  uint8_t getBootState_u8();

  void setSomeData_v(sint32_t i_SomeData_s32);
  void setFrameID_v(uint32_t i_FrameID_u32);
  void setBootState_v(uint8_t i_BootState_u8);
  uint32_t getAppMRuntime(void);
  void setAppMRuntime(uint32_t u_Runtime_val);

private:
  osal::Mutex mutex_o;
  sint32_t someData_s32;
  uint32_t FrameID_u32;
  uint8_t BootState_u8;
  uint32_t m_AppM_rt_data;
};

} // namespace container

#endif // CONTAINER_APPM_DATA_H
