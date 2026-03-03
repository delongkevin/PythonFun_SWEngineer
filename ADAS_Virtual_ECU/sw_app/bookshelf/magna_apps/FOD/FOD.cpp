//--------------------------------------------------------------------------
/// @file FOD.cpp
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

#include "JobFOD.h"
#include "FOD.h"
#include "DataProviderFOD.h"

#ifdef __cplusplus
extern "C" {
#endif

#define DEBUG_PROFILE_TIME 0
#if DEBUG_PROFILE_TIME
#include "ti\osal\TimerP.h"
#include <UART_stdio.h>
#endif
using namespace fod;
static FODCONFIGData FOD_config;
static Job_Inputs_t FOD_jobInput;
static JobFODOutput_t FOD_jobFodOutput_s;
static TbFOD_VrntTunParam_t FOD_tuningParam;
static fod::DataProviderFOD m_FODDataProvider(FOD_config, FOD_tuningParam, FOD_jobInput, FOD_jobFodOutput_s);
static fod::JobFOD m_FODJob((IDataProviderFOD *)&m_FODDataProvider);

void F_FOD_Init_v()
{
  m_FODJob.init_v();
}

void F_FOD_Run_v()
{
#if DEBUG_PROFILE_TIME
  uint64_t u_StartTime, u_TimeExec, u_TimeEnd, u_TimeLast;
  u_StartTime = TimerP_getTimeInUsecs();
#endif
  
  m_FODJob.start_v();

#if DEBUG_PROFILE_TIME
  u_TimeExec = TimerP_getTimeInUsecs();
#endif

  m_FODJob.execute_v();

#if DEBUG_PROFILE_TIME
  u_TimeEnd = TimerP_getTimeInUsecs();
#endif

  m_FODJob.end_v();
#if DEBUG_PROFILE_TIME
  u_TimeLast = TimerP_getTimeInUsecs();

  UART_printf("FOD: %d, %u secs\n", (uint32_t)(u_TimeLast - u_StartTime), (uint32_t)(u_TimeLast - u_StartTime));
#endif
  

}

#ifdef __cplusplus
}
#endif
