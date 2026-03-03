//--------------------------------------------------------------------------
/// @file JobTRSC.cpp
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


#include"JobTRSC.h"
#include "../TRSC_SM_VC_Int_ert_rtw/TRSC_SM_VC_Int.h"
#include <UART_stdio.h>

extern "C" {

#if PROFILE_TRSC_SMVC
#include "ti/osal/TimerP.h"
#endif
};

namespace TRSC
{


JobTRSC::JobTRSC()
{
}

JobTRSC::~JobTRSC()
{
}

/*
	*	Name: JobTRSC::onInit_b
	*	Remarks: DD-ID: {78150873-0D5F-4531-9239-C3DEEEEE9E71}
	*/
bool_t JobTRSC::onInit_b()
{
#if TRSC_DEBUG_PRINTS
	UART_printf("JobTRSC::onInit_b()\n");
#endif
	TRSC_SM_VC_Int_initialize();
    return true;
}

/*
	*	Name: JobTRSC::onVariantChanged_v
	*	Remarks: DD-ID: {44764AAF-AC62-4ae9-A8F8-E1C1CB1E0689}
	*/	
void JobTRSC::onVariantChanged_v(bool_t i_FirstTime_b)
{
	return;
}

/*
	*	Name: JobTRSC::onRun_b
	*	Remarks: DD-ID: {6E672310-1C63-483b-B115-8F5CE012C0CF}
	*/
bool_t JobTRSC::onRun_b()
{

#if TRSC_DEBUG_PRINTS
    UART_printf("JobTRSC::onRun_b()\n");
#endif
#if PROFILE_TRSC_SMVC
  static uint32_t count = 0;
	count++;
  uint64_t u64StartTime = TimerP_getTimeInUsecs();
#endif
	start_v();
	execute_v();
	end_v();
#if PROFILE_TRSC_SMVC
	uint64_t u64EndTime = TimerP_getTimeInUsecs();
	if (!(count % 100))
	{
		UART_printf("%d: %d, %u \n", count, (uint32_t)(u64StartTime), (uint32_t)(u64EndTime - u64StartTime));
	}
#endif
    return true;
}

/*
	*	Name: JobTRSC::onCleanup_v
	*	Remarks: DD-ID: {C32F6907-35FA-463d-B7A2-145F93CBA7A8}
	*/
void JobTRSC::onCleanup_v()
{
	return;
}

/*
	*	Name: JobTRSC::start_v
	*	Remarks: DD-ID: {13574626-7FF9-414e-95F2-1CF38615C4C4}
	*/
void JobTRSC::start_v(void)
{
    return;
}

/*
	*	Name: JobTRSC::hasNext_b
	*	Remarks: DD-ID: {99BC621D-539C-47ac-8B1E-0ECD138C857B}
	*/
bool_t JobTRSC::hasNext_b()
{
	
	return true;
}

/*
	*	Name: JobTRSC::execute_v
	*	Remarks: DD-ID: {7254E281-A959-4922-B7A1-DE48FA08FE81}
	*/
/*
	*	Name: TRSC SM VC
	*	Remarks: DD-ID: {8562EDB8-DF51-4f44-B761-819E567ADEA8}
	*/	
void JobTRSC::execute_v()
{
	TRSC_SM_VC_Int_step();
  return;
}

/*
	*	Name: JobTRSC::end_v
	*	Remarks: DD-ID: {CE837DDC-736E-4fb4-A18A-FA46DD02A9EA}
	*/
void JobTRSC::end_v()
{
	TRSC_SM_VC_Int_terminate();
	return;    
}

/*
	*	Name: JobTRSC::dump_v
	*	Remarks: DD-ID: {42016FF3-7822-4f7c-8C0E-01BF183EDBF4}
	*/
void JobTRSC::dump_v()
{
    return;	
}

} // namespace TRSC
