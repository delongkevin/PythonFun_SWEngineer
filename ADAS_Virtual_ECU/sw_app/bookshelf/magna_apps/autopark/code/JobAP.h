//--------------------------------------------------------------------------
/// @file JobAP.h
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

#ifndef _JOB_AP_H_
#define _JOB_AP_H_

#include <stdbool.h>
#include <iostream>
#include "DataProviderAP.h"

#define AP_PROFILE  (0u)

namespace AP
{
    class JobAP
    {
    public:
        JobAP(IDataProviderAP *);
        virtual ~JobAP();
        virtual bool_t onInit_b();
        virtual void onVariantChanged_v(bool_t i_FirstTime_b);
        virtual bool_t onRun_b();
        virtual void onCleanup_v();

    private:
        bool_t initDone_b;
        void start_v();
        bool_t hasNext_b();
        void execute_v();
        void end_v();
        void dump_v();
        void reset_v();

        IDataProviderAP *dataProvider_ro;
    }; // JobAP

} // namespace AP

#endif //_JOB_AP_H_
