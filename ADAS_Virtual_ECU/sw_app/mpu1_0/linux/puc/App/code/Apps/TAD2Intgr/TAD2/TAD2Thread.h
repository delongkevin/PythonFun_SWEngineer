//--------------------------------------------------------------------------
/// @file TAD2Thread.h
/// @brief Contains the definition of TIOVX handling thread.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
//  --------------------------------------------------------------------------

#ifndef TAD2_THREAD_H_
#define TAD2_THREAD_H_

#include <platform/PlatformAPI.h>
#include <container/JobBase.h>
#include <osal/threading/IRunnable.h>
#include <variants/Enums.h>
#include "../cfg/DataProvider/IDataProviderTAD2.h"

#include "algo/inc/JobTADOutput.h"
#include "algo/inc/TADAlgoObject.h"

#ifdef APP_TIDL_TRACE_DUMP
#include <tivx_utils_tidl_trace.h>
#endif

#include "stdlib.h"
#include <variants/Components.h>
#include <variants/Assets.h>
#include "osal/system/Clock.h"

extern "C" {
#include <app_init.h>
}

namespace TAD2
{
class IDataProviderTAD2;

class TAD2ThreadRunnable: public osal::IRunnable
{

public:
  explicit TAD2ThreadRunnable(IDataProviderTAD2 &b_DataProvider_ro);
  virtual ~TAD2ThreadRunnable();

  virtual void init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void cleanup_v() ME_OVERRIDE;
  void reset_b();
  static void stop_v();
private:

  void startTAD2();
  void executeTAD2();
  void endTAD2();
  void tadNVMSanity();
#if UART_PRINT_TAD2_OUTPUT
  uint64_t startTime, executeTime, endTime, periodicity;
#endif

  IDataProviderTAD2 &dataProvider_ro;
  bool_t m_TAD2_Reload_Calib;
  bool_t m_initialized;
  TAD2::TADAlgoObject m_TADAlgoObject;
  TAD2::JobTADOutput m_jobOutput;
  TAD2::JobTADInput* m_jobInput;
  TAD2::RawVehicleData v_VehData;
  TAD2::VehicleControlData v_VehCtrlData;
  TAD2::RawKinematicData v_KMData;
  tad2config::TADConfigData m_config;
  JobTADDebugOutput m_JobTADDebugOutput;
  variants::ViewId_t viewID_t;
  osal::Clock m_clock_s;
  TeTRSC_e_TADState previousState;
  Detection_Inputs_from_TRSC_t inputsFromTRSCSMVC;
  ME_ProxiToMPU1_0_Def_t* proxy_TAD2;
  TeTRSC_e_TrailerCalibMemClearResponse_t TRSCCalibClearResponse;
};

} //namespace TAD2

#endif // TAD2_THREAD_H_
