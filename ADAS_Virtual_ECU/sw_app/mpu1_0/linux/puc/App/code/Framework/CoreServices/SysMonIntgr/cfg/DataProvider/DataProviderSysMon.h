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

#ifndef SYSMON_DATAPROVIDERSYSMON_H_
#define SYSMON_DATAPROVIDERSYSMON_H_

#include "sysmon/IDataProviderSysMon.h"

namespace sysmon
{

  /// Data provider for SysMon implementation
  class DataProviderSysMon : public IDataProviderSysMon
  {
  public:
    /// Used for VdgData output
    explicit DataProviderSysMon(container::IDataProvider& b_DataProvider_ro);
    virtual ~DataProviderSysMon();

    virtual void setCurrentSoCTemperature(const float32_t& i_CurrentSoCTemperature_rf32) ME_OVERRIDE;
    virtual void setME_Proxi_MPU1_0_to_MCU1_0(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t) ME_OVERRIDE;
    virtual ME_Proxi_MPU1_0_to_MCU1_0_t getME_Proxi_MPU1_0_to_MCU1_0() ME_OVERRIDE;
    virtual void setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt) ME_OVERRIDE;
    virtual void setETFS_mount_status(const uint8_t&) ME_OVERRIDE;
    virtual uint8_t getETFS_mount_status(void) ME_OVERRIDE;
    virtual PerformanceStatsEnable_t getPerformanceStatsEnable_t(void) ME_OVERRIDE;
    virtual void setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt) ME_OVERRIDE;
    virtual uint32_t getCALSMRuntime(void) ME_OVERRIDE;
    virtual uint32_t getCALSMThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getDLDRuntime(void) ME_OVERRIDE;
    virtual uint32_t getDLDThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getEOLRuntime(void) ME_OVERRIDE;
    virtual uint32_t getEOLThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getOCRuntime(void) ME_OVERRIDE;
    virtual uint32_t getOCThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getOVL3DRuntime(void) ME_OVERRIDE;
    virtual uint32_t getRenderThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getTAD2Runtime(void) ME_OVERRIDE;
    virtual uint32_t getTAD2ThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getTHARuntime(void) ME_OVERRIDE;
    virtual uint32_t getTHAThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getTIOVXThreadRuntime(void) ME_OVERRIDE;
    virtual uint32_t getTIOVXRuntime(void) ME_OVERRIDE;
    virtual uint32_t getCamCalibRuntime(void) ME_OVERRIDE;
    virtual uint32_t getAppMRuntime(void) ME_OVERRIDE;
    virtual uint32_t getLogMRuntime(void) ME_OVERRIDE;
    virtual uint32_t getKeepAliveRuntime(void) ME_OVERRIDE;
    virtual uint32_t getMsgSndrRuntime(void) ME_OVERRIDE;
    virtual uint32_t getSigMRuntime(void) ME_OVERRIDE;
    virtual uint32_t getThSigMRuntime(void) ME_OVERRIDE;
    // virtual uint32_t getSysRuntime(void) ME_OVERRIDE;
    virtual uint32_t getSysMonRuntime(void) ME_OVERRIDE;
    virtual uint32_t getVarMRuntime(void) ME_OVERRIDE;
    virtual uint32_t getAlgoViewRuntime(void) ME_OVERRIDE;
    virtual void setSysMonRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
  private:
    container::IDataProvider& dataProvider_ro;
  };

} // namespace sysmon

#endif // SYSMON_DATAPROVIDERSYSMON_H_
