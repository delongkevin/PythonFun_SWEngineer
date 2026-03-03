//--------------------------------------------------------------------------
/// @file MOTData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kedar Naphad (kedar.naphad@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_MOT_DATA_H
#define CONTAINER_MOT_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

namespace container
{

class MOTData : public DataContainer
{
public:
  MOTData();
  virtual ~MOTData();

  sint32_t getSomeData_s32();
  void setSomeData_v(sint32_t i_SomeData_s32);

private:
  osal::Mutex mutex_o;
  sint32_t someData_s32;
};

} // namespace container

#endif // CONTAINER_MOT_DATA_H
