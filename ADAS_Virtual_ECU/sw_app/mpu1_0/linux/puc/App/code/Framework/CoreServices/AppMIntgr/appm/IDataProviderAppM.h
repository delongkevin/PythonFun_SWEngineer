//--------------------------------------------------------------------------
/// @file IDataProviderAppM.h
/// @brief Contains
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
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------
#ifndef IDATAPROVIDERAPPM_H_
#define IDATAPROVIDERAPPM_H_

#include <platform/PlatformSpecs.h>

#include "cfg/shmdata/AppMData.h"
#include <cfg/IDataProvider.h>

namespace appm
{


class IDataProviderAppM
{
public:
  explicit IDataProviderAppM()
  {}

  virtual ~IDataProviderAppM()
  {}

  //----------------------------------------------------------------------------------------
  // // Data Input (only getter)
  //---------------------------------------------------------------------------------------

  virtual uint32_t                            getFrameID_u32() const = 0;


  //----------------------------------------------------------------------------------------
  // Data Output (only setter)
  //----------------------------------------------------------------------------------------

  virtual void                                setFrameID_v(uint32_t i_FrameID_u32) = 0;
  virtual void                                setBootState_v(uint8_t i_BootState_u8) = 0;
  virtual void                                setAppMRuntime(uint32_t u_Runtime_u32) = 0;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) = 0;
};


} // namespace appm

#endif // IDATAPROVIDERAPPM_H_
