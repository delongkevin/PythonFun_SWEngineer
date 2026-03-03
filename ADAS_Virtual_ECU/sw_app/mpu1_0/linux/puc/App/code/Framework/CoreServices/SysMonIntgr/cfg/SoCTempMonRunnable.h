//--------------------------------------------------------------------------
/// @file SoCTempMonRunnable.h
/// @brief Contains the SoC temperature monitor component definitions.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>
#include <osal/threading/IRunnable.h>

#include <cfg/DataProvider/DataProviderSysMon.h>

namespace sysmon
{

namespace sysmonconsts
{
  static const uint16_t c_SysMomTempMeasurementSleepTime_u16 = 2000U;
  static const uint16_t c_SysMomTempADCReadingSleepTime_u16  = 5U;
} // namespace sysmonconsts

class SoCTempMonRunnable : public osal::IRunnable
{
public:
  SoCTempMonRunnable();
  virtual ~SoCTempMonRunnable();

  virtual void   init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void   cleanup_v() ME_OVERRIDE;

  void           terminate_v();

  uint32_t       getSoCTemperature_u32();

private:

  virtual void performSoCTempMeasurement_v();

private:

  osal::Mutex                   mutex_o;

  bool_t                        isRunning_b;

  uint32_t                      averageAdcValue_u32;

};

}  // namespace sysmon
