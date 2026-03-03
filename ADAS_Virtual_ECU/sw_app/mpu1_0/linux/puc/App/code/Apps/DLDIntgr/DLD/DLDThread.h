/// --------------------------------------------------------------------------
/// @file DLDThread.h
/// @brief Contains DLDThread class is an algorithm container to separate algo and framework
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#ifndef DLD_THREAD_H_
#define DLD_THREAD_H_

#include <platform/PlatformAPI.h>
#include <container/JobBase.h>
#include <osal/threading/IRunnable.h>
#include <variants/Enums.h>
#include "IDataProviderDLD.h"

#ifdef APP_TIDL_TRACE_DUMP
#include <tivx_utils_tidl_trace.h>
#endif

#include "TI/tivx_debug.h"
//#include "stdlib.h"
#include <variants/Components.h>
#include <variants/Assets.h>
#include "osal/system/Clock.h"

#include "algo/inc/DLDAlgo.h"
#include "algo/inc/DLDOutput.h"
#include "algo/inc/JobDLDInput.h"
#include "algo/inc/DLDStateMachine.h"

namespace dld
{
class IDataProviderDLD;

class DLDThreadRunnable: public osal::IRunnable
{

public:
  explicit DLDThreadRunnable(IDataProviderDLD &b_DataProvider_ro);
  virtual ~DLDThreadRunnable();

  virtual void init_v() ME_OVERRIDE;
  virtual bool_t run_b() ME_OVERRIDE;
  virtual void cleanup_v() ME_OVERRIDE;
  static void stop_v();

private:
  void startDLD();
  void executeDLD();
  void endDLD();
  void clearCamera(DLD_Camera_ID camId);

  DLD_Camera_ID    m_currCamId;
  JobDLDInput_s    m_jobDLDInput;
  DLDOutput_s      m_jobDLDOutput;
  IDataProviderDLD &m_dataProvider_ro;
  DLDStateMachine  m_stateMachine;
  DLDAlgo          m_dldAlgo;
  ME_ProxiToMPU1_0_Def_t* proxy;
};

} //namespace dld

#endif // DLD_THREAD_H_
