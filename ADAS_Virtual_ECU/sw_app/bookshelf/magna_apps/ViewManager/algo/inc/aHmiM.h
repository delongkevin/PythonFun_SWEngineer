/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       HMI Manager
 * DESIGN:      2014
 * DESCRIPTION: 
 * ======================================================================== */

/**
 * \file     aHmiM.h
 * \brief    handles the behavior in normal operation of Hydra 2 system
 * \author   Stephan Fries
 * \version  $Revision: 1.1.3.1 $
 * \details  h file public description of module
 */

#ifndef AHMIM_H_
#define AHMIM_H_


/* --- Public Typedefinitions, Enumerations, Defines ------------------------------- */
#define AHMIM_D_VERSION_ID_H "$Id: aHmiM.h 1.1.3.1 2021/04/05 22:25:12IST Gopinath Ramanathan (gopirama) Draft  $"  /**< \brief short c-file private description of lFoo_D_VERSION_ID_C */

#include "ME_hydra2defs_OEM.h"

/* Possible States for the StateMachine */


typedef enum aHmiM_E_RequestedMode_e
{
  aHmiM_E_NoModeRequested               = 0u,
  aHmiM_E_NormalOperationModeRequested  = 1u,
  aHmiM_E_InactiveModeRequested         = 2u
}aHmiM_E_RequestedMode_t;

/* --- Public Function Declarations ------------------------------------------------ */

void aHmiM_F_Init_v(void);
void aHmiM_F_DeInit_v(void);
void aHmiM_F_Task10msec_v(void);
/* Kept for later use */
/*aHmiM_E_RequestedMode_t aHmiM_F_GetModuleState_e(void);*/
aHmiM_E_ModuleState_t aHmiM_F_GetModuleState_e(void);
Std_E_ReturnType_t aHmiM_F_IsInactive_e(void);
Std_E_ReturnType_t aHmiM_F_RequestInactivation_e(void);
Std_E_ReturnType_t aHmiM_F_RequestNormalOperation_e(void);

BOOL aHmiM_F_IsHmiWorkingProperly_b(void);

u32 aHmiM_F_GetRestartCount_u32(void);
u32 aHmiM_F_GetRestartThreshold_u32(void);
u32 aHmiM_F_GetScreenRequestTimeoutCountThreshold_u32(void);

void aHmiM_F_SetRestartCount_v(u32 value);
void aHmiM_F_SetRestartThreshold_v(u32 value);
void aHmiM_F_SetScreenRequestTimeoutCountThreshold_v(u32 value);


/* --------------------------------------------------------------------------------- */
#endif /* AHMIM_H_ */

/* --------------------------------------------------------------------------------- */
/* END OF FILE: aHmiM.h */

