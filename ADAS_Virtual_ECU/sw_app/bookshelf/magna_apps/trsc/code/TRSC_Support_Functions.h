//--------------------------------------------------------------------------
/// @file TRSC_Support_Functions.h
/// @brief Contains hand coded support functions for TRSC SMVC
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

#ifndef _TRSC_SUPPORT_FUNCTIONS_H_
#define _TRSC_SUPPORT_FUNCTIONS_H_

#include "TRSC_SMVC_Defines.h"
#include "PlatformDataTypes.h"
#include "ME_VehOut_TRSC.h"
#include "TRSCSMVCtoSVS.h"
#include "Detection_Inputs_from_TRSC.h"
#include "TRSCtoDiagMgr.h"
#include "TRSCSMVCtoDebugCAN.h"
#include "VehicleInputAdapterDataTypes.h"

#include <string.h>

#if TRSC_SMVC_IPC_TEST
void Simulate_TRSC_SMVC_Output();
#endif

#if TRSC_SMVC_IPC_TEST
void printTRSCInputs(const ME_VehInp_FromCAN14_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN14IpcSignals,
                     const ME_VehInp_FromCAN2_IpcSignals *rtu_IbTRSC_MEVehInpFromCAN2IpcSignals);
#endif

#endif //_TRSC_SUPPORT_FUNCTIONS_H_

