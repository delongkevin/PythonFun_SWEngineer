/*---------------------------------------------------------------------------*/
/* @file JobHMI.h                                                            */
/* @brief Contains HMI Job implementation                                    */
/* --------------------------------------------------------------------------*/
/* @copyright MAGNA Electronics - C O N F I D E N T I A L <br>               */
/* This document in its entirety is CONFIDENTIAL and may not be disclosed,   */
/* disseminated or distributed to parties outside MAGNA Electronics          */
/* without written permission from MAGNA Electronics.                        */
/*                                                                           */
/* @author Pravin Pawar (pravin.pawar@magna.com)                             */
/*                                                                           */
/*  -------------------------------------------------------------------------*/

#ifndef _JOB_HMI_STATE_MACHINE_
#define _JOB_HMI_STATE_MACHINE_

#include "IDataProviderHMI.h"
#include "DataProviderHMI.h"
#include "PlatformDataTypes.h"

namespace HMI
{

class JobHMI
{
public:
    JobHMI(IDataProviderHMI*);
    virtual ~JobHMI();
    virtual bool onInit_b();
    virtual void onVariantChanged_v(bool_t i_FirstTime_b);
    virtual bool onRun_b();
    virtual void onCleanup_v();

private:

    void start_v();
    bool hasNext_b();
    void execute_v();
    void end_v();
    void dump_v();


#if DEBUG_EMB_PROFILE
            FILE *fp_HMIOP;
#endif
    IDataProviderHMI *dataProvider_ro;
}; //JobHMI

}// namespace HMI

#endif //_JOB_HMI_STATE_MACHINE_
