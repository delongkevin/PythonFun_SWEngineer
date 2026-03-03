//--------------------------------------------------------------------------
/// @file DataProviderSysMon.h
/// @brief Contains the System Monitor data provider class definition.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGM_DATAPROVIDERLOGM_H_
#define LOGM_DATAPROVIDERLOGM_H_

#include "logm/IDataProviderLogM.h"

namespace logm
{

  /// Data provider for SysMon implementation
  class DataProviderLogM : public IDataProviderLogM
  {
  public:
    /// Used for VdgData output
    explicit DataProviderLogM(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderLogM();
    virtual void setLogMRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

  private:
    container::IDataProvider& dataProvider_ro;
  };

} // namespace sysmon

#endif // LOGM_DATAPROVIDERLOGM_H_
