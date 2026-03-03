//--------------------------------------------------------------------------
/// file THA_SM.c
/// brief Contains
///
/// DataProvider is an interface between THA_SM module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// author Afshan Shaikh
///
//  --------------------------------------------------------------------------

#include "THA_SM.h"
#include  "../THA_SWC_ert_rtw/THA_SWC.h"
#include "ti/osal/TimerP.h"
#include "ti/osal/osal.h"
#include <UART_stdio.h>

#define THA_SM_VC_DEBUG_PRINT 	(0u)
#define THA_PROFILE  (0u)
#define THA_UART_PRINT (0u)

#ifdef THA_SM_VC_OFFLINE_TESTING
#include <UART_stdio.h>
#include "../simulation/DataProviderTHA_SM.h"
static uint32_t v_StepCntr_u32 = 0; 
#endif

void F_THA_SM_Init(void)
{
  THA_SWC_initialize();
  #if  THA_UART_PRINT
  UART_printf("\n ### THA Init done ");
  #endif
}

void F_THA_SM_Run(void)
{
  #ifdef THA_SM_VC_OFFLINE_TESTING
    THA_SWC_step();
		//0,1,2,3,.....99
		if (v_StepCntr_u32 == (THAArrTimeInst_u32[V_FrameNoTHA_u8]))//99, 199, 
		{
			printTHAoutput();
		}
		if (v_StepCntr_u32 == (THAArrTimeInst_u32[V_FrameNoTHA_u8+1]-1))//99, 199, 
		{
			V_FrameNoTHA_u8++;
			if (V_FrameNoTHA_u8 >= 33)
			{
				V_FrameNoTHA_u8 = 32;
			}
		}
		v_StepCntr_u32++;
    UART_printf("\n THA: v_StepCntr_u32 = %d", v_StepCntr_u32);
  #endif
  #if THA_SM_VC_DEBUG_PRINT
     UART_printf("\n *****************THASMVC F_THA_SM_Run()***************** \n");
  #endif
  #if THA_PROFILE        
	uint64_t u64StartTime = TimerP_getTimeInUsecs();
	static uint64_t u64PrevStartTime = 0;
  #endif 
    THA_SWC_step();
  #if THA_PROFILE
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
		UART_printf("THA : %d, %d us\n", u32Average[0], u32Average[1]);
		u32AvgFrms = 0;
		u32Summation[0] = u32Summation[1] = 0;
	}
	u64PrevStartTime = u64StartTime;
  #endif
}
