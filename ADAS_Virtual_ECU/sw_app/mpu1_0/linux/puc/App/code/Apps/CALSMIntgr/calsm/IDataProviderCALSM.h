//--------------------------------------------------------------------------
/// @file IDataProviderCALSM.h
/// @brief Contains interface for CALSM Dataprovider
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (ananda.kavrady@magna.com)
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDER_CALSM_H_
#define I_DATA_PROVIDER_CALSM_H_

#include <platform/PlatformAPI.h>
#include "SVSCamCalibSM.h"
#include <cfg/IDataProvider.h>

namespace calsm
{
  class IDataProviderCALSM
  {
  public:

    explicit IDataProviderCALSM() {}
    virtual ~IDataProviderCALSM() {}

    virtual void get_calib_vehicle_signal_input(void) = 0;
    virtual void get_shutdown_input()    = 0;
    virtual void get_calib_diagmgr_input()   = 0;
    virtual void get_calib_nvmmgr_input()    = 0;
    virtual void get_calib_algo_input()      = 0;
    virtual void get_HmiScreen()             = 0;

    virtual void set_calib_algo_input()      = 0;
    virtual void set_NVM_CalibData()         = 0;
    virtual void set_DiagMgr_CalibData()     = 0;
    virtual void set_TscScreen()             = 0;

    virtual void Get_EOLSM_CalibData() = 0;
    virtual void Get_SCSM_CalibData() = 0;
    virtual void Get_OCSM_CalibData() = 0 ;
    virtual void Get_Calib_FIDs() = 0;
    virtual void Get_FunctionalSettings() = 0;
    virtual void setCALSMRuntime(uint32_t u_CALSMRuntime_u32) = 0;
    virtual void setCALSMThreadRuntime(uint32_t u_CALSMRuntime_u32) = 0;
    virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;

  };


} // namespace calsm

#endif // I_DATA_PROVIDER_CALSM_H_
