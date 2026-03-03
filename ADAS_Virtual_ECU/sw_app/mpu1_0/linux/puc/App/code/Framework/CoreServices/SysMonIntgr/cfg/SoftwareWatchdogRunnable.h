//--------------------------------------------------------------------------
/// @file SoftwareWatchdogRunnable.h
/// @brief Contains the Software watchdog runnable definitions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>
#include <osal/threading/IRunnable.h>

namespace sysmon
{

class SoftwareWatchdogRunnable : public osal::IRunnable
{
public:

  explicit SoftwareWatchdogRunnable();

  virtual ~SoftwareWatchdogRunnable();

  virtual void   init_v() ME_OVERRIDE;

  virtual bool_t run_b() ME_OVERRIDE;

  virtual void   cleanup_v() ME_OVERRIDE;

public:

  void           checkAliveState_v();

private:

  bool_t         isRunning_b;

};

}  // namespace sysmon
