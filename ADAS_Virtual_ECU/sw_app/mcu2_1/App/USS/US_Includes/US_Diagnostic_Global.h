/*
 * US_Diagnostic_Global.h
 *
 *  Created on: May 7, 2021
 *      Author: e39960
 */

#ifndef SRC_US_DIAGNOSTIC_US_DIAGNOSTIC_H_
#define SRC_US_DIAGNOSTIC_US_DIAGNOSTIC_H_

#include "US_SnrData_Typedefs_Global.h"
#include "US_Interface_Output.h"

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)
    #define US_DIAGNOSTIC_MAX_COUNTER	(uint16_t)(0x10)
    #define US_DIAGNOSTIC_MIN_COUNTER 	(uint16_t)(0x00)  /*may change if signed counter used*/
#else
    #define US_DIAGNOSTIC_MAX_COUNTER   (ONE)
    #define US_DIAGNOSTIC_MIN_COUNTER   (ONE)  /*may change if signed counter used*/
#endif

typedef void (* fnSnrDiagFaultCallBack_t)(uint8_t ,uint16_t);

typedef struct US_S_DiagFlagParms_s
{
	uint16_t SetDebounceCounter;
	uint16_t ClearDebounceCounter;
    uint16_t ExtendedSetDebouncecounter;
	/* Currently Callback functions are commented these can be enabled in future base on the requirement in future */

/* comment out	fnSnrDiagFaultCallBack_t fnSnrDiagSetFaultCallBack;
	fnSnrDiagFaultCallBack_t fnSnrDiagClearFaultCallBack;*/
}US_S_DiagFlagParms_t;
/*comment out extern uint16_t	James_Debug[32];*/

uint32_t US_Diagnostic_IsSnrFaultFlagPending(US_E_SnrFaultReason_t SnrFlagType);
uint32_t US_Diagnostic_GetSnrMapFaultFlag(US_E_SnrFaultReason_t SnrFlagType);

#if (US_D_FAULT_DEBOUNCE_BY_TIME == ME_TRUE)

void US_Diagnostic_SetSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint32_t SnrMap);
void US_Diagnostic_ClrSnrFaultFlag(US_E_SnrFaultReason_t SnrFlagType, uint32_t SnrMap);

void US_ECUDiagFlagCheckMain(void);
void US_SnrDiagFlagCheckMain(void);

#else

void US_Diagnostic_SetSnrFaultFlagByIdx(US_E_SnrFaultReason_t uSnrFlagType, uint8_t uSnrIdx);
void US_Diagnostic_ClrSnrFaultFlagByIdx(US_E_SnrFaultReason_t uSnrFlagType, uint8_t uSnrIdx);

#endif

bool_t US_Diagnostics_GetSnrFaultFlagStatus(US_E_SnrFaultReason_t SnrFlagType,uint8_t SnrIdx);
void US_Diagnostic_SetECUFlag(US_E_ECUFaultReason_t EcuFlagType);
bool_t USDiagnostic_GetECUFlag(US_E_ECUFaultReason_t EcuFlagType);
void US_Diagnostic_ClrECUFlag(US_E_ECUFaultReason_t EcuFlagType);
uint32_t US_Diagnostics_GetSnrFaultConfirmedFlagStatus(US_E_SnrFaultReason_t SnrFlagType);

void US_Diagnostic_Init(void);

void US_ECUDiagnostic_Init(void);
/* function prototypes PLEASE*/
#endif /* SRC_US_DIAGNOSTIC_US_DIAGNOSTIC_H_ */
