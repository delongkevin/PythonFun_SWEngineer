//--------------------------------------------------------------------------
/// @file JobLogM.h
/// @brief Job for logging administration
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_LOGM_H
#define JOB_LOGM_H

#include <platform/PlatformAPI.h>

#include "IDataProviderLogM.h"

#include <container/JobBase.h>

#include <osal/threading/Thread.h>


namespace logm
{
  class JobLogM : public container::JobBase<IDataProviderLogM>
  {
  public:

    static  void   initLogModes_v();
    IDataProviderLogM& dataProvider_ro;

  public:

    JobLogM(container::JobDesc_s& b_JobDesc_rs, IDataProviderLogM& b_DataProviderLogM_ro);

    virtual ~JobLogM();

    virtual bool_t onInit_b() ME_OVERRIDE;
    virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
    virtual bool_t onRun_b() ME_OVERRIDE;
    virtual void   onCleanup_v() ME_OVERRIDE;

  };
}

#endif // JOB_LOGM_H
