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

#ifndef CONTAINER_VARM_DATA_H
#define CONTAINER_VARM_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"


namespace container
{

class VarMData : public DataContainer
{
public:
  VarMData();
  virtual ~VarMData();

  uint32_t getLanguageID_u32() const ;
  void setLanguageID_v(uint32_t i_Data_u32);
  uint32_t getVarMRuntime(void);
  void setVarMRuntime(uint32_t u_Runtime_u32);

private:
  osal::Mutex mutex_o;
  uint32_t LanguageID_u32;
  uint32_t m_VarM_rt_data;
};

} // namespace container

#endif // CONTAINER_VARM_DATA_H
