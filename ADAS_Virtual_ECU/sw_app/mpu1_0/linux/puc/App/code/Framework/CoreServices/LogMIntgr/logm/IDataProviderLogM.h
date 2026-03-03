//--------------------------------------------------------------------------
/// @file IDataProviderSysMon.h
/// @brief Contains the System Monitor data provider interface definition.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGM_IDATAPROVIDERLOGM_H_
#define LOGM_IDATAPROVIDERLOGM_H_

#include <cfg/IDataProvider.h>
#include <variants/Assets.h>

namespace logm
{
  /// Data provider for System Monitor interface definition
  class IDataProviderLogM
  {
  public:
    explicit IDataProviderLogM() { }
    virtual ~IDataProviderLogM() { }
    virtual void setLogMRuntime(uint32_t u_Runtime_u32) = 0;
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;

  };

} // namespace logm

#endif // LOGM_IDATAPROVIDERLOGM_H_
