//--------------------------------------------------------------------------
/// @file IDataProviderDLD.h
/// @brief Contains interface for DLD Dataprovider
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/DLD specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------
#ifndef I_DATA_PROVIDER_DLD_H_
#define I_DATA_PROVIDER_DLD_H_

#include <cfg/DataProvider.h>
#include "algo/inc/DLDOutput.h"
#include "algo/inc/JobDLDInput.h"
#include "algo/common/DLDDef.h"

namespace dld
{
class IDataProviderDLD
{
public:
  explicit IDataProviderDLD()
  {
  }

  virtual ~IDataProviderDLD()
  {
  }
   
  virtual const JobDLDInput_s getDLDInput(DLD_Camera_ID camId) = 0;
  virtual void setDLDOutput(DLDOutput_s& outputDLD) = 0;
  virtual const JobDLDVehicleInput_s getVehicleInput(void) = 0;
  virtual const JobDLDFIDs_t getDLDFIDs(void) = 0;
  virtual ME_ProxiToMPU1_0_Def_t* getProxiSettings(void) = 0;
  virtual void setInputPadSizes(uint32_t inPadL, uint32_t inPadT, uint32_t inPadR, uint32_t inPadB) = 0;

  // Get SC, THA and APA status value
  virtual bool_t isFeatureAllowedToRun() = 0;
  virtual void setDLDThreadRuntime(uint32_t u_Runtime_u32) = 0;
  virtual void setDLDRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;

};
} // namespace dld

#endif // I_DATA_PROVIDER_DLD_H_
