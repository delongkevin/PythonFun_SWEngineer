//--------------------------------------------------------------------------
/// @file JobAppM.h
/// @brief Contains the job definition for the signal manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Marcel Engelhardt (Marcel.Engelhardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_APP_M_H
#define JOB_APP_M_H

#include "IDataProviderAppM.h"
#include "JobScheduler.h"

#include <platform/PlatformAPI.h>

#include <container/MessageDispatcher.h>
#include <container/IMessageHandler.h>
#include <container/JobContext.h>

#include <osal/threading/IRunnable.h>

#include <logging/Logger.h>

// including cfg specific header is ok here
#include <cfg/ContextTypes.h>
#include <cfg/Context.h>

#include <variants/Assets.h>

namespace appm
{

// JobID -> (MessageID : List of subscribed Jobs)
typedef mepl::vector<variants::Job_e> JobVector_t;
typedef mepl::map<container::OpCodeDataChanged_e, JobVector_t> DataChangedMap_t;

class JobAppM : public osal::IRunnable, public container::IMessageHandler
{
public:

  void stateMachine_v();

  JobAppM(container::JobContext& i_Context_ro, IDataProviderAppM& b_DataProvider_ro);
  virtual ~JobAppM();

  void         initSchedulingSchemes_v();

  // JobBase implementation
  virtual void   init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void   cleanup_v() ME_OVERRIDE;

  // Override this method to react on Messages.
  virtual void handleMessage_v(const container::Message& i_Msg_ro) ME_OVERRIDE;

protected:
  void         handleFrameworkMessage_v(const container::Message& i_Msg_ro);

  bool_t       isAllAppsInitialized_b();

  bool_t       isChangeVariantConfig_b()const;

private:

  container::JobContext& context_ro;

  // Massage Dispatcher which handles the messaging
  container::MessageDispatcher dispatcher_o;
  IDataProviderAppM&           dataProvider_ro;

  // State machine
  uint32_t             frameID_u32;
  variants::AppState_t appState_e;

  bool_t isRunning_b;
  bool_t changeVariantConfig_b;
  bool_t allAppsInitialized_b;

  bool_t initializedJobs_ab[variants::e_JobCount];

  // Scheduling
  JobScheduler     scheduler_o;
  SchedulderList_t schedulingSchemes_at[variants::e_AppStateCount];


  logging::Logger  logger_o;
};
}
#endif // JOB_APP_M_H

