//--------------------------------------------------------------------------
/// @file Context.h
/// @brief Contains the System job definition for setting up jobs and constructing context.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------


#include <platform/PlatformAPI.h>

#include <cfg/DataProvider.h>
#include <cfg/DataProvider/DataProviderSigM.h>
#include <cfg/DataProvider/DataProviderVarM.h>
#include <cfg/DataProvider/DataProviderAppM.h>
#include <cfg/DataProvider/DataProviderOvl3D.h>
#include <cfg/DataProvider/DataProviderEol.h>
#include <cfg/DataProvider/DataProviderSysMon.h>
#include <cfg/DataProvider/DataProviderLogM.h>
#include <cfg/DataProvider/DataProviderOC.h>
#include <cfg/DataProvider/DataProviderTIOVX.h>
#include <cfg/DataProvider/DataProviderCALSM.h>
#include <cfg/DataProvider/DataProviderTHA.h>
#include <cfg/DataProvider/DataProviderTAD2.h>
#include <cfg/DataProvider/DataProviderDLD.h>
#include <osal/threading/IRunnable.h>
#include <osal/threading/Thread.h>

#include <container/JobContext.h>
#include <container/IMessageHandler.h>
#include <container/MessageDispatcher.h>
#include <container/Message.h>

#include <cfg/ContextTypes.h>

namespace sys
{

class JobSystem : public osal::IRunnable, container::IMessageHandler
{
public:
  explicit JobSystem(container::JobContext& b_JobContext_ro);
  virtual ~JobSystem();

  virtual void   init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void   cleanup_v() ME_OVERRIDE;

  virtual void handleMessage_v(const container::Message& b_Msg_ro) ME_OVERRIDE;

  void triggerShutdown_v();

private:

  JobSystem();

  void        createAllJobs_v();

  sint32_t    createJob_u32(variants::Job_e i_JobId_e);

  void        restartJob_v(variants::Job_e i_JobId_e);

  static void shutdownAllJobs_v();

  static void shutdownJob_v(variants::Job_e i_JobId_e);

  void        waitForAllJobs_v() const;

  void        waitForJob_v(variants::Job_e i_JobId_e) const;

  void        killAllJobs_v();

  void        killJob_v(variants::Job_e i_JobId_e);

private:

  // used for all Jobs to share data via DataProvider
  container::DataProvider     dataProvider_o;

  // all data providers for each Core Service
  varm::DataProviderVarM      dataProviderVarM_o;
  sigm::DataProviderSigM      dataProviderSigM_o;
  appm::DataProviderAppM      dataProviderAppM_o;
  sysmon::DataProviderSysMon  dataProviderSysMon_o;
  logm::DataProviderLogM      dataProviderLogM_o;

  // all data providers for each Application
  ovl3d::DataProviderOvl3D    dataProviderOvl3D_o;
  eol::DataProviderEol        dataProviderEol_o;
  oc::DataProviderOC         dataProviderOC_o;
  tiovx::DataProviderTIOVX    dataProviderTiovx_o;
  calsm::DataProviderCALSM    dataProviderCALSM_o;
  tha::DataProviderTHA        dataProviderTHA_o;
  TAD2::DataProviderTAD2        dataProviderTAD2_o;
  dld::DataProviderDLD        dataProviderDLD_o;
  container::MessageDispatcher dispatcher_o;

  ProcessID_t processIds_at[variants::e_JobCount];

  osal::Thread threadIds_at[variants::e_JobCount];

  ProcessID_t FatherPID;

  bool_t isRunning_b;
};

} // namespace sys
