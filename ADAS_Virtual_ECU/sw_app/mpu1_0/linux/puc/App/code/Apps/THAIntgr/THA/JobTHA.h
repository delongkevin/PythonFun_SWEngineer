//--------------------------------------------------------------------------
/// @file JobTHA.h
/// @brief Contains JobTHA class is an algorithm container to separate algo and framework
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Afshan Shaikh (afshan.shaikh@magna.com)
//  --------------------------------------------------------------------------

#ifndef JOB_THA_H
#define JOB_THA_H

#include <container/JobBase.h>
#include "IDataProviderTHA.h"
#include "THAThread.h"
#include <osal/threading/Thread.h>

namespace tha
{

class JobTHA: public container::JobBase<IDataProviderTHA>
{

public:
  explicit JobTHA(container::JobDesc_s &b_JobDesc_rs, IDataProviderTHA &b_DataProvider_ro);
  virtual ~JobTHA();

  // JobBase implementation
  virtual bool_t onInit_b() ME_OVERRIDE;
  virtual void onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t onRun_b() ME_OVERRIDE;
  virtual void onCleanup_v() ME_OVERRIDE;

private:
  osal::Thread      THAThread_o;
  THAThreadRunnable THAThreadRunnable_o;
};

} // namespace tha

#endif // JOB_THA_H

