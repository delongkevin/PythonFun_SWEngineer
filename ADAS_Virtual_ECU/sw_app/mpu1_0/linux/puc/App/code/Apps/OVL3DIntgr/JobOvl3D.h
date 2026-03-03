//--------------------------------------------------------------------------
/// @file JobOvl.h
/// @brief Job for 3D Bowl View / Single View / ViewGen functionality
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_OVL_3D_H
#define JOB_OVL_3D_H

#include <container/JobBase.h>

#include "IDataProviderOvl3D.h"
#include "RenderThreadRunnable.h"
#include <osal/threading/Thread.h>


namespace ovl3d
{
  class JobOvl3D : public container::JobBase<IDataProviderOvl3D>
  {
  public:
    JobOvl3D(container::JobDesc_s& b_JobDesc_rs, IDataProviderOvl3D& b_DPOvl_ro);
    virtual ~JobOvl3D();

    virtual bool_t onInit_b() ME_OVERRIDE;
    virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
    virtual bool_t onRun_b() ME_OVERRIDE;
    virtual void   onCleanup_v() ME_OVERRIDE;

  private:
    osal::Thread         renderThread_o;
    RenderThreadRunnable renderThreadRunnable_o;
    IDataProviderOvl3D&  dataProvider_ro;
  };
}

#endif // JOBOVL_H_
