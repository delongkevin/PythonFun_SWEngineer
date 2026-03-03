//--------------------------------------------------------------------------
/// @file JobTRSC.h
/// @brief Contains TRSC Job implementation
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef _JOB_TRSC_STATE_MACHINE_
#define _JOB_TRSC_STATE_MACHINE_

#include "PlatformDataTypes.h"

#define TRSC_DEBUG_PRINTS   0
#define PROFILE_TRSC_SMVC   0
#define VC_DEBUG_PRINTS     0

namespace TRSC
{

class JobTRSC
{
public:
    JobTRSC();
    virtual ~JobTRSC();
    virtual bool_t onInit_b();
    virtual void onVariantChanged_v(bool_t i_FirstTime_b);
    virtual bool_t onRun_b();
    virtual void onCleanup_v();

private:
    void start_v();
    bool_t hasNext_b();
    void execute_v();
    void end_v();
    void dump_v();

#if DEBUG_EMB_PROFILE
            FILE *fp_TRSCOP;
#endif
}; //JobTRSC

}// namespace TRSC

#endif //_JOB_TRSC_STATE_MACHINE_
