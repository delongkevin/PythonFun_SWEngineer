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

#ifndef SYSMON_IDATAPROVIDERSYSMON_H_
#define SYSMON_IDATAPROVIDERSYSMON_H_

#include <cfg/IDataProvider.h>
#include <variants/Assets.h>

namespace sysmon
{
  /// Data provider for System Monitor interface definition
  class IDataProviderSysMon
  {
  public:
    explicit IDataProviderSysMon() { }
    virtual ~IDataProviderSysMon() { }

    virtual void setCurrentSoCTemperature(const float32_t& i_CurrentSoCTemperature_rf32) = 0;
    virtual void setME_Proxi_MPU1_0_to_MCU1_0(const ME_Proxi_MPU1_0_to_MCU1_0_t& i_ME_Proxi_MPU1_0_to_MCU1_0_t) = 0;
    virtual ME_Proxi_MPU1_0_to_MCU1_0_t getME_Proxi_MPU1_0_to_MCU1_0() = 0;
    virtual void setSSM_QNX_CoreStatus_v(const SSM_QNX_CoreStatus& i_SSM_QNX_CoreStatus_rt) = 0;
    virtual void setETFS_mount_status(const uint8_t&) = 0;
    virtual uint8_t getETFS_mount_status(void) = 0;
    virtual PerformanceStatsEnable_t getPerformanceStatsEnable_t(void) = 0;
    virtual void setRunTimeStats_MPU1_0_v(const RunTimeStats_MPU1_0_t& i_RunTimeStats_MPU1_0_rt) = 0;
    virtual uint32_t getCALSMRuntime(void) = 0;
    virtual uint32_t getCALSMThreadRuntime(void) = 0;
    virtual uint32_t getDLDRuntime(void) = 0;
    virtual uint32_t getDLDThreadRuntime(void) = 0;
    virtual uint32_t getEOLRuntime(void) = 0;
    virtual uint32_t getEOLThreadRuntime(void) = 0;
    virtual uint32_t getOCRuntime(void) = 0;
    virtual uint32_t getOCThreadRuntime(void) = 0;
    virtual uint32_t getOVL3DRuntime(void) = 0;
    virtual uint32_t getTAD2Runtime(void) = 0;
    virtual uint32_t getTAD2ThreadRuntime(void) = 0;
    virtual uint32_t getRenderThreadRuntime(void) = 0;
    virtual uint32_t getTHARuntime(void) = 0;
    virtual uint32_t getTHAThreadRuntime(void) = 0;
    virtual uint32_t getTIOVXThreadRuntime(void) = 0;
    virtual uint32_t getTIOVXRuntime(void) = 0;
    virtual uint32_t getCamCalibRuntime(void) = 0;
    virtual uint32_t getAppMRuntime(void) = 0;
    virtual uint32_t getLogMRuntime(void) = 0;
    virtual uint32_t getKeepAliveRuntime(void) = 0;
    virtual uint32_t getMsgSndrRuntime(void) = 0;
    virtual uint32_t getSigMRuntime(void) = 0;
    virtual uint32_t getThSigMRuntime(void) = 0;
    // virtual uint32_t getSysRuntime(void) = 0;
    virtual uint32_t getSysMonRuntime(void) = 0;
    virtual uint32_t getVarMRuntime(void) = 0;
    virtual uint32_t getAlgoViewRuntime(void) = 0;
    virtual void setSysMonRuntime(uint32_t u_Runtime_u32) = 0;
  };

} // namespace sysmon

#endif // SYSMON_IDATAPROVIDERSYSMON_H_
