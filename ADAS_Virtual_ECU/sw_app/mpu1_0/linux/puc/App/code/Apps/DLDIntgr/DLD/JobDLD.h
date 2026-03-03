//--------------------------------------------------------------------------
/// @file JobDLD.h
/// @brief Contains JobDLD class is an algorithm container to separate algo and framework
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#ifndef JOB_DLD_H
#define JOB_DLD_H

#include <container/JobBase.h>
#include "IDataProviderDLD.h"
#include "DLDThread.h"
#include <osal/threading/Thread.h>

namespace dld
{

class JobDLD: public container::JobBase<IDataProviderDLD>
{

public:
  explicit JobDLD(container::JobDesc_s &b_JobDesc_rs, IDataProviderDLD &b_DataProvider_ro);
  virtual ~JobDLD();

  // JobBase implementation
  virtual bool_t onInit_b() ME_OVERRIDE;
  virtual void onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t onRun_b() ME_OVERRIDE;
  virtual void onCleanup_v() ME_OVERRIDE;

private:
#if ENABLE_DLD_THREAD
  osal::Thread      m_DLDThread_o;
  DLDThreadRunnable m_DLDThreadRunnable_o;
#endif
};

} // namespace dld

#endif // JOB_DLD_H

