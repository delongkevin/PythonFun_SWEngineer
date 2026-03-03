/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   aHmiM_STM_Cfg
 * DESIGN:  Fries S.
 * DESCRIPTION:
 *    Normal Operation Sub State Machine for the aHmiM Module
 * ======================================================================== */


#ifndef AHMIM_STM_CFG_H_
#define AHMIM_STM_CFG_H_


/* ######################################################################################################
 * --- HEADER VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_CFG_D_VERSION_ID_H "$Id: aHmiM_STM_Cfg.h 1.1.3.1 2021/04/05 22:25:13IST Gopinath Ramanathan (gopirama) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- global macros ---
 * ###################################################################################################### */

/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- module global typedef ENUMs ---
 * ###################################################################################################### */
typedef enum  aHmiM_STM_E_StateMachineList_e
{
  aHmiM_STM_E_ST_NotInit                          = 0u,
  aHmiM_STM_E_ST_Init                             = 1u,
  aHmiM_STM_E_ST_CheckInactiveMode                = 2u,
  aHmiM_STM_E_ST_CheckView                        = 3u,
  aHmiM_STM_E_ST_CheckOvl                         = 4u,
  aHmiM_STM_E_ST_CheckFailsafe                    = 5u,
  aHmiM_STM_E_ST_RequestScreenOnZynq              = 6u,
  aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq     = 7u,
  aHmiM_STM_E_ST_LockOutWait                      = 8u,
  aHmiM_STM_E_ST_End                              = 9u,
  aHmiM_STM_E_ST_NumStates                        = 10u
} aHmiM_STM_E_StateMachineList_t;                 /* state machine list */

/* ------------------------------------------------------------------------------------------------------ */


#if defined(AHMIM_STM_C_) || defined(AHMIM_STM_CFG_C_) || defined(AHMIM_STM_FUNCTIONS_C_)
  /* ######################################################################################################
   * --- HMI MODULE GLOBAL ONLY  ---
   * ###################################################################################################### */
    extern void             aHmiM_STM_F_InitCfg_v(void);
    extern void             aHmiM_STM_F_OnModuleCall_v(aHmiM_STM_E_StateMachineList_t     ST_CurrState_e);
    extern void             aHmiM_STM_F_OnModuleReturn_v(aHmiM_STM_E_StateMachineList_t   ST_CurrState_e);
    extern void             aHmiM_STM_F_RequestInact_v(aHmiM_STM_E_StateMachineList_t     ST_CurrState_e);
    extern void             aHmiM_STM_F_RequestNormalOp_v(aHmiM_STM_E_StateMachineList_t  ST_CurrState_e);
    extern void             aHmiM_STM_F_Reset_CurrentViewOnZynqM__v(void);
  /* ------------------------------------------------------------------------------------------------------ */
  #if defined(AHMIM_STM_CFG_C_) || defined(AHMIM_STM_FUNCTIONS_C_)
    /* ######################################################################################################
     * --- local function prototypes ---
     * ###################################################################################################### */
    extern void             aHmiM_STM_f_OnEntry_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                     /* common event function OnEntry */
    extern void             aHmiM_STM_f_OnRun_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                       /* common event function OnRun   */
    extern void             aHmiM_STM_f_OnExit_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                      /* common event function OnExit  */
    /* ~~~ System ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    extern BOOL             aHmiM_STM_f_TransitionNotInitToInit_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                      /* Always TRUE */
    extern BOOL             aHmiM_STM_f_TransitionInitToCheckInactiveMode_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                            /* Always TRUE */
    extern BOOL             aHmiM_STM_f_InactiveModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                        /* CheckInactiveMode to End */
    extern BOOL             aHmiM_STM_f_NoModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                              /* CheckInactiveMode to CheckView */
    extern BOOL             aHmiM_STM_f_ActiveModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                          /* End to CheckInactiveMode */
    extern BOOL             aHmiM_STM_f_TransitionCheckViewToCheckOvl_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                /* Always TRUE */
    extern BOOL             aHmiM_STM_f_TransitionCheckOvlToCheckFailsafe_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                            /* Always TRUE */
    extern BOOL             aHmiM_STM_f_ScreenChanged_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                                /* If Screen Changed switch to Request Screen */
    extern BOOL             aHmiM_STM_f_ScreenNotChanged_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                             /* If Screen did not change switch to CheckInactiveMode */
    extern BOOL             aHmiM_STM_f_TransitionRequestScreenOnZynqToWaitForRequestedScreenOnZynq_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);  /* Always TRUE */
    extern BOOL             aHmiM_STM_f_WaitForScreenTimerExpired_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                    /* WaitForRequestedScreenOnZynq to LockOutWait */
    extern BOOL             aHmiM_STM_f_ScreenIsActiveOnZynq_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                         /* WaitForRequestedScreenOnZynq to LockOutWait */
    extern BOOL             aHmiM_STM_f_LockOutWaitTimerExpired_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e);                                      /* TRUE When LockOut Timer has expired */
    /* --------------------------------------------------------------------------- */
  #endif
/* ------------------------------------------------------------------------------------------------------ */
#endif


/* ######################################################################################################
  * --- global functions ---
  * ###################################################################################################### */

/* ------------------------------------------------------------------------------------------------------ */


/* === End Of Header File ================================================= */
#else
 // #error Multiple include of aHmiM_STM_Cfg.h
 //Commented For Porting 
#endif /* AHMIM_STM_CFG_H_ */

