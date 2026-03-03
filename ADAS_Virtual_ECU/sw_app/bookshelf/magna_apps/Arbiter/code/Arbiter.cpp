//--------------------------------------------------------------------------
/// @file Arbiter.cpp
/// @brief Contains Wrapper for Low Speed Feature
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
#include "Arbiter.h"

#ifdef __cplusplus
extern "C" {
#endif

using namespace Arbiter;

static Arbiter::DataProviderArbiter m_ArbiterDataProvider;
static Arbiter::JobArbiter m_ArbiterJob((IDataProviderArbiter *)&m_ArbiterDataProvider);

void F_Arbiter_Init_v()
{
  m_ArbiterJob.onInit_b();
}

void F_Arbiter_Run_v()
{
  m_ArbiterJob.onRun_b();
}

#ifdef __cplusplus
}
#endif
