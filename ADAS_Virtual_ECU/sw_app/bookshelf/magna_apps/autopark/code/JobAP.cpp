//--------------------------------------------------------------------------
/// @file JobAP.cpp
/// @brief Contains Low Speed Feature Job implementation
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Kedar Naphad (kedar.naphad@magna.com)
///
//  --------------------------------------------------------------------------
#include "JobAP.h"
#include "ti\osal\TimerP.h"
#include "ti\osal\osal.h"
#include <UART_stdio.h>

#if DEBUG_PRINTS
static int frameCount_i32 = 0;
#endif //DEBUG_PRINTS


namespace AP
{
    JobAP::JobAP(
        IDataProviderAP *b_DPAP_ro)
    {
        dataProvider_ro = b_DPAP_ro;
    }

    JobAP::~JobAP()
    {
    }

    bool_t JobAP::onInit_b()
    {
#if DEBUG_PRINTS
        UART_printf("Auto Park onInit\n");
#endif //DEBUG_PRINTS        
        DT24_CVADAS_AP_CodGen_initialize();
        return true;
    }

    void JobAP::onVariantChanged_v(bool_t i_FirstTime_b)
    {
    }

    bool_t JobAP::onRun_b()
    {
        start_v();
        execute_v();
        end_v();
        return true;
    }

    void JobAP::onCleanup_v()
    {
    }

    void JobAP::start_v(void)
    {
        return;
    }

    bool_t JobAP::hasNext_b()
    {
        bool out = true;
        return out;
    }
	/*
    * Name: ParkAssist
    * Remarks: DD-ID: {D6AE8CA1-A768-40f3-B632-1ADCC88656B3}
    */
    void JobAP::execute_v()
    {
#if AP_PROFILE        
        uint64_t u64StartTime = TimerP_getTimeInUsecs();
        static uint64_t u64PrevStartTime = 0;
#endif           
        DT24_CVADAS_AP_CodGen_step();
#if AP_PROFILE
        uint64_t u64EndTime = TimerP_getTimeInUsecs();
        static uint32_t u32Summation[2] = {0};
        static uint32_t u32Average[2] = {0};
        static uint32_t u32AvgFrms = 0;
        u32Summation[0] = u32Summation[0] + (uint32_t)(u64StartTime - u64PrevStartTime);
        u32Summation[1] = u32Summation[1] + (uint32_t)(u64EndTime - u64StartTime);
        u32AvgFrms++;
        if (30 == u32AvgFrms)
        {
            u32Average[0] = u32Summation[0] / u32AvgFrms;
            u32Average[1] = u32Summation[1] / u32AvgFrms;
            UART_printf("AP: %d, %d us\n", u32Average[0], u32Average[1]);
            u32AvgFrms = 0;
            u32Summation[0] = u32Summation[1] = 0;
        }
        u64PrevStartTime = u64StartTime;
#endif 

#if DEBUG_PRINTS
        UART_printf("AP frame number %d \n", frameCount_i32);
        frameCount_i32++;
#endif
        return;
    }

    void JobAP::end_v()
    {
        DT24_CVADAS_AP_CodGen_terminate();
    }

    void JobAP::dump_v()
    {
    }
} // namespace AP
