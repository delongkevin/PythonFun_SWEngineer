//--------------------------------------------------------------------------
/// @file THAData.h
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

#ifndef CONTAINER_THA_DATA_H
#define CONTAINER_THA_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

namespace container
{

class THAData : public DataContainer
{
public:
  THAData();
  virtual ~THAData();

  sint32_t getSomeData_s32();
  void setSomeData_v(sint32_t i_SomeData_s32);
  void set_THA_SM_status(bool_t &i_SMToAlgo);
  bool_t get_THA_SM_status();
  bool_t bTHA_SM_status;
  uint32_t getTHARuntime(void);

  void setTHARuntime(uint32_t u_Runtime_u32);

  uint32_t getTHAThreadRuntime(void);

  void setTHAThreadRuntime(uint32_t u_Runtime_u32);

private:
  osal::Mutex mutex_o;
  sint32_t someData_s32;
  uint32_t m_THA_rt_data;
  uint32_t m_THAThread_rt_data;
};

} // namespace container

#endif // CONTAINER_THA_DATA_H
