//--------------------------------------------------------------------------
/// @file APDiagDataTypes.h
/// @brief Contains Interfaces for APFusion input and output structs
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
///
//  --------------------------------------------------------------------------

#ifndef OSHOOKSSTRUCT_H_INCGUARD
#define OSHOOKSSTRUCT_H_INCGUARD

#include "PlatformDataTypes.h"
#ifdef BUILD_MCU1_0

#define RESETMGR_MAX_STACK_LEN          (10U)

typedef enum{
	Reset_Abort_mode,
    Reset_Undef_mode,
    Reset_default_mode,
	Max_Resetmode
}Resetmode_E;

typedef struct{
	uint32_t FD14_1_OsRegMCU_Link; 								/* Return address - address of instruction where fault occured */
	uint32_t FD14_1_OsRegMCU_SPSR; 								/* Saved CPSR Register*/
	uint32_t FD14_1_OsRegMCU_DFSR; 								/* Data fault Status Register*/
	uint32_t FD14_1_OsRegMCU_IFSR; 								/* Instruction Fault status Register */
    uint32_t FD14_1_OsRegMCU_ADFSR; 							/* Auxiliary Data Fault Status Register */
    uint32_t FD14_1_OsRegMCU_AIFSR; 							/* Auxiliary Instruction Fault Status Register */
    uint32_t FD14_1_OsRegMCU_DFAR; 								/* Data Fault Address Register */
    uint32_t FD14_1_OsRegMCU_IFAR; 								/* Instruction Fault address register */
	uint32_t FD14_1_OsRegMCU_Stack[RESETMGR_MAX_STACK_LEN]; 	/* Stack information of the mode indicated by SPSR */
}__attribute__ ((packed)) CortexR5ExceptionRegs_t;

typedef struct ME_OsHookDebugData
{
    uint8 FD14_1_Hook_Type_MCU1_0;
    uint8 FD14_1_Hook_Error_MCU1_0;
    uint8 FD14_1_Hook_actTsk_MCU1_0;
    uint8 FD14_1_Hook_fatalErr_MCU1_0;
    uint16 FD14_1_Hook_DtErr_MCU1_0;
    uint16 FD14_1_Hook_Service_MCU1_0;
    uint32 FD14_1_Hook_PresentPtr_MCU1_0;
    uint8 NVM_WriteAll_Fail_Status;
	uint16 NVM_WriteAll_Pattern;
	CortexR5ExceptionRegs_t OsExceptionHandler;
}ME_OsHookDebugData_t;


#endif
#endif
