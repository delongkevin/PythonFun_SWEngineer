//--------------------------------------------------------------------------
/// @file AP.cpp
/// @brief Contains Wrapper for Low Speed Feature
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
#include "AP.h"

#ifdef __cplusplus
extern "C" {
#endif

using namespace AP;

static AP::DataProviderAP m_APDataProvider;
static AP::JobAP m_APJob((IDataProviderAP *)&m_APDataProvider);

void F_AP_Init_v()
{
  m_APJob.onInit_b();
}

void F_AP_Run_v()
{
  m_APJob.onRun_b();
}

#ifdef __cplusplus
}
#endif
