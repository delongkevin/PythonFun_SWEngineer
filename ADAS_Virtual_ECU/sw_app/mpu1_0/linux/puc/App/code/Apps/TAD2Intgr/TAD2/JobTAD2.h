//--------------------------------------------------------------------------
/// @file JobTAD2.h
/// @brief Contains The TAD job definition.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_TAD2_H_
#define JOB_TAD2_H_


#include <container/JobBase.h>
#include "../cfg/DataProvider/IDataProviderTAD2.h"
#include  "mecl/core/MeclTypes.h"
#include "algo/common/CANData.h"
#include "algo/inc/JobTADOutput.h"
#include "algo/inc/TADAlgoObject.h"
#include "TAD2Thread.h"
#include <osal/threading/Thread.h>

namespace TAD2
{
  class JobTAD2 : public container::JobBase<IDataProviderTAD2>
  {
    public:

      explicit JobTAD2( container::JobDesc_s& b_JobDesc_rs , IDataProviderTAD2& b_DPTAD_ro );
      virtual ~JobTAD2();

      virtual bool_t onInit_b() ME_OVERRIDE;

      virtual void   onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;

      virtual bool_t onRun_b() ME_OVERRIDE;

      virtual void   onCleanup_v() ME_OVERRIDE;
    
    private:
#if ENABLE_TAD2_THREAD
      osal::Thread      TAD2Thread_o;
      TAD2ThreadRunnable TAD2ThreadRunnable_o;
#endif
  };
}

#endif // JOB_TAD_H_
