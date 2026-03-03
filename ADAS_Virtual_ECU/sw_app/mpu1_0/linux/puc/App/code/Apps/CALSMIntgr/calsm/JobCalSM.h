//--------------------------------------------------------------------------
/// @file JobCalSM.h
/// @brief Contains the definition of VPCS Job 
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (ananda.kavrady@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOBCALSM_H
#define JOBCALSM_H

#include <variants/Enums.h>
#include <osal/threading/Thread.h>
#include "container/JobBase.h"
#include "IDataProviderCALSM.h"

namespace calsm
{

  class CALSMThreadRunnable: public osal::IRunnable
  {

  public:
    explicit CALSMThreadRunnable(IDataProviderCALSM &b_DPCalSm_ro);
    virtual ~CALSMThreadRunnable();

    virtual void init_v() ME_OVERRIDE;
    virtual bool_t run_b() ME_OVERRIDE;
    virtual void cleanup_v() ME_OVERRIDE;

  private:
    void start_v();
    void execute_v();
    void end_v();

    IDataProviderCALSM &dataProvider_ro;
  };

  class JobCalSM: public container::JobBase<IDataProviderCALSM>
  {
  public:

    JobCalSM(container::JobDesc_s& b_JobDesc_rs, IDataProviderCALSM& b_DPCalSm_ro);

    virtual ~JobCalSM();

    virtual bool_t onInit_b() ME_OVERRIDE;
    virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
    virtual bool_t onRun_b() ME_OVERRIDE;
    virtual void   onCleanup_v() ME_OVERRIDE;

  private:
    osal::Thread        m_CALSMThread_o;
    CALSMThreadRunnable m_CALSMThreadRunnable_o;
  };

}

#endif  //JOBCALSM_H
