//--------------------------------------------------------------------------
/// @file JobArbiter.cpp
/// @brief Contains Low Speed Feature Job implementation
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Dipti Natu (dipti.natu@magna.com)
///
//  --------------------------------------------------------------------------
#include "JobArbiter.h"
#include "ti\osal\TimerP.h"
#include "ti\osal\osal.h"

#if DEBUG_PRINTS
#include <UART_stdio.h>

static int frameCount_i32 = 0;
#endif //DEBUG_PRINTS


namespace Arbiter
{
    JobArbiter::JobArbiter(
        IDataProviderArbiter *b_DPArb_ro)
    {
        dataProvider_ro = b_DPArb_ro;
    }

    JobArbiter::~JobArbiter()
    {
    }

    bool_t JobArbiter::onInit_b()
    {
#if DEBUG_PRINTS
        UART_printf("Arbiter onInit\n");
#endif //DEBUG_PRINTS        
        FeatureArbiter_initialize();
        return true;
    }

    void JobArbiter::onVariantChanged_v(bool_t i_FirstTime_b)
    {
    }

    bool_t JobArbiter::onRun_b()
    {
        start_v();
        execute_v();
        end_v();
        return true;
    }

    void JobArbiter::onCleanup_v()
    {
    }

    void JobArbiter::start_v(void)
    {
        return;
    }

    bool_t JobArbiter::hasNext_b()
    {
        bool out = true;
        return out;
    }

    void JobArbiter::execute_v()
    {
#ifdef ARB_PROFILE        
        uint64_t u64StartTime = TimerP_getTimeInUsecs();
#endif           
        FeatureArbiter_step();
#ifdef ARB_PROFILE        
        uint64_t u64EndTime = TimerP_getTimeInUsecs();
        UART_printf("Arbiter: %d, %u secs\n", (uint32_t)(u64EndTime - u64StartTime), (uint32_t)(u64EndTime - u64StartTime));
#endif 

#if DEBUG_PRINTS
        UART_printf("Arbiter frame number %d \n", frameCount_i32);
        frameCount_i32++;
#endif
        return;
    }

    void JobArbiter::end_v()
    {
        #if DEBUG_PRINTS
        UART_printf("Arbiter end_v() \n");
        #endif
    }

    void JobArbiter::dump_v()
    {
    }
} // namespace Arbiter
