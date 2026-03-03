//--------------------------------------------------------------------------
/// @file TRSC.cpp
/// @brief Contains Wrapper for TRSC
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

#include "JobTRSC.h"
#include "TRSC.h"

#ifdef __cplusplus
extern "C" {
#endif

using namespace TRSC;

static TRSC::JobTRSC m_TRSCJob;

/* Model initialize function */

/*
*	Name: TRSC::F_TRSC_Init_v
*	Remarks: DD-ID: {45C085E7-5F31-44ba-A607-A81FD4187D23}
*/
void F_TRSC_Init_v()
{
  m_TRSCJob.onInit_b();
  return;
}

/* Model step function */

/*
*	Name: TRSC::F_TRSC_Run_v
*	Remarks: DD-ID: {2CF4D7B9-FD2A-4da8-B031-9ABF04ED030F}
*/
void F_TRSC_Run_v()
{
  m_TRSCJob.onRun_b();
  return;
}

#ifdef __cplusplus
}
#endif
