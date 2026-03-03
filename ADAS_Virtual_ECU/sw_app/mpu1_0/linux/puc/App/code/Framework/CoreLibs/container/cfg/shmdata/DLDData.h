//--------------------------------------------------------------------------
/// @file DLDData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_DLD_DATA_H
#define CONTAINER_DLD_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

namespace container
{

class DLDData : public DataContainer
{
public:
  DLDData();
  virtual ~DLDData();

  sint32_t getSomeData_s32();
  void setSomeData_v(sint32_t i_SomeData_s32);
  void setDLDThreadRuntime(uint32_t u_Runtime_u32);
  void setDLDRuntime(uint32_t u_Runtime_u32);
  uint32_t getDLDThreadRuntime(void);
  uint32_t getDLDRuntime(void);
  
private:
  osal::Mutex mutex_o;
  sint32_t someData_s32;
  uint32_t m_DLD_rt_data;
  uint32_t m_DLDThread_rt_data;
};

} // namespace container

#endif // CONTAINER_DLD_DATA_H
