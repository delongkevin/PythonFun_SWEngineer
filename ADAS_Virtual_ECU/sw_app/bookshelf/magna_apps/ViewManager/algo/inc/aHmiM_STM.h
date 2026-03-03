/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   aHmiM_STM
 * DESIGN:  Fries S.
 * DESCRIPTION:
 *    Normal Operation Sub State Machine for the aHmiM Module
 * ======================================================================== */


#ifndef AHMIM_STM_H_
#define AHMIM_STM_H_


/* ######################################################################################################
 * --- HEADER VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_D_VERSION_ID_H "$Id: aHmiM_STM.h 1.1.3.1 2021/04/05 22:25:13IST Gopinath Ramanathan (gopirama) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */

          
/* ######################################################################################################
 * --- include files ---
 * ###################################################################################################### */
#include "ME_hydra2defs_OEM.h"
#include  "aHmiM_STM_Cfg.h"
#include  "aHmiM_STM_Types.h"
/* ------------------------------------------------------------------------------------------------------ */


#if defined(AHMIM_STM_C_) || defined(AHMIM_STM_CFG_C_)
/* ######################################################################################################
 * --- module global constants ---
 * ###################################################################################################### */
extern const aHmiM_STM_S_StateDescriptor_t aHmiM_STM_C_StateDiscriptorList_as[aHmiM_STM_E_ST_NumStates];
/* ------------------------------------------------------------------------------------------------------ */
#endif

/* ######################################################################################################
 * --- local defines ---
 * ###################################################################################################### */
#define aHmiM_STM_d_BitshiftOVL                      0u
#define aHmiM_STM_d_BitshiftView                    25u
/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- global functions ---
 * ###################################################################################################### */
extern void                           aHmiM_STM_F_Init_v(void);
extern void                           aHmiM_STM_F_Task10msec_v(void);
extern aHmiM_STM_Error_t              aHmiM_STM_F_GetLastError_t(void);
extern aHmiM_STM_E_StateMachineList_t aHmiM_STM_F_GetCurrentState_e(void);
extern u32                            aHmiM_STM_F_GetCurrentView_u32(void);
extern void                           aHmiM_STM_F_RequestInactivation_e(void);
extern void                           aHmiM_STM_F_RequestNormalOperation_e(void);
extern void                           aHmiM_STM_F_Reset_CurrentViewOnZynqM_v(void);
extern u32                            aHmiM_STM_F_GetScreenRequestTimeout_u32(void);
extern void                           aHmiM_STM_F_SetScreenRequestTimeout_v(u32 value);
extern u32                            aHmiM_STM_F_GetScreenRequestTimeoutCount_u32(void);
extern void                           aHmiM_STM_F_ResetScreenRequestTimeoutCount_v(void);
extern BOOL                           aHmiM_STM_F_IsScreenRequestTimedOut_b(void);
/* ------------------------------------------------------------------------------------------------------ */


/* === End Of Header File ================================================= */
#else
  #error Multiple include of aHmiM_STM.h
#endif /* AHMIM_STM_H_ */

