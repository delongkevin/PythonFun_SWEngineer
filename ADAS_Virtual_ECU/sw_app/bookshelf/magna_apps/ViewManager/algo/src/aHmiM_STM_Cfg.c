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


/* ######################################################################################################
 * --- MODULE VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_CFG_D_VERSION_ID_C "$Id: aHmiM_STM_Cfg.c 1.1.3.1 2021/04/05 22:25:13IST Gopinath Ramanathan (gopirama) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */

/* PRQA S 0342 EOF */ /* Suppress warning "Using the glue operator '##'." - This is needed for this STM */
/* PRQA S 0881 EOF */ /* Suppress warning "Using multiple ## operators in the same macro definition." - This is needed for this STM */
/* PRQA S 3453 EOF */ /* Suppress warning "A function could probably be used instead of this function-like macro." - This is needed for this STM */
/* PRQA S 3635 EOF */ /* Suppress warning "Function identifier used as a pointer without a preceding & operator." - This is needed for this STM */
/* PRQA S 0617 EOF */ /* Suppress warning "[C99] 'const' qualifier has been duplicated." - This is needed for this STM */
/* PRQA S 1053 EOF */ /* Suppress warning "[C99] Designators have been used in this initialization list." - This is needed for this STM */
/* PRQA S 3205 EOF */ /* Suppress warning "The identifier 'xxx' is not used and could be removed." - This is needed for this STM */

/* ######################################################################################################
 * --- include files ---
 * ###################################################################################################### */
#define   AHMIM_STM_CFG_C_
#include  "aHmiM_STM.h"
#undef    AHMIM_STM_CFG_C_ /* PRQA S 0841 ++*/ /* Suppress warning "Using '#undef'." */
/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- DEFINE FUNCTION AND ENUM LIST in dependency between STATE and FUNCTION ---
 * ###################################################################################################### */
#define aHmiM_STM_Cfg_d_FX_LIST_NotInit(STATE_ENUM,DEF_NAME)                        /* JUMP to Init */                           aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_TransitionNotInitToInit_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_Init(STATE_ENUM,DEF_NAME)                           /* JUMP to CheckInactiveMode */              aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_TransitionInitToCheckInactiveMode_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_CheckInactiveMode(STATE_ENUM,DEF_NAME)              /* JUMP to End */                            aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_InactiveModeRequested_b),     \
                                                                                    /* JUMP to CheckView */                      aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_NoModeRequested_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_CheckView(STATE_ENUM,DEF_NAME)                      /* JUMP to CheckOvl */                       aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_TransitionCheckViewToCheckOvl_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_CheckOvl(STATE_ENUM,DEF_NAME)                       /* JUMP to CheckFailsafe */                  aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_TransitionCheckOvlToCheckFailsafe_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_CheckFailsafe(STATE_ENUM,DEF_NAME)                  /* JUMP to CheckInactiveMode */              aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_ScreenNotChanged_b),          \
                                                                                    /* JUMP to RequestScreenOnZynq */            aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_ScreenChanged_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_RequestScreenOnZynq(STATE_ENUM,DEF_NAME)            /* JUMP to WaitForRequestedScreenOnZynq */   aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_TransitionRequestScreenOnZynqToWaitForRequestedScreenOnZynq_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_WaitForRequestedScreenOnZynq(STATE_ENUM,DEF_NAME)   /* JUMP to LockOutWait */                    aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_WaitForScreenTimerExpired_b), \
                                                                                    /* JUMP to LockOutWait */                    aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_ScreenIsActiveOnZynq_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_LockOutWait(STATE_ENUM,DEF_NAME)                    /* JUMP to CheckInactiveMode */              aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_LockOutWaitTimerExpired_b)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_FX_LIST_End(STATE_ENUM,DEF_NAME)                            /* JUMP to CheckInactiveMode */              aHmiM_STM_D_DEFINE_##DEF_NAME(STATE_ENUM,        aHmiM_STM_f_ActiveModeRequested_b)
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- DEFINE STATE CONDITIONS (bit pattern) in dependency between STATE and FUNCTION ---
 * ###################################################################################################### */
                                                                                                     /* Always Jump from NotInit to Init */
#define aHmiM_STM_Cfg_d_ST_ITEM_NotInit_2_Init(FX_FILTER)                                            aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_NotInit,                             aHmiM_STM_f_TransitionNotInitToInit_b,                                      1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Always Jump from Init to CheckInactiveMode */
#define aHmiM_STM_Cfg_d_ST_ITEM_Init_2_CheckInactiveMode(FX_FILTER)                                  aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_Init,                                aHmiM_STM_f_TransitionInitToCheckInactiveMode_b,                            1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Jump to End if Inactive Mode is Requested */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckInactiveMode_2_End(FX_FILTER)                                   aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckInactiveMode,                   aHmiM_STM_f_InactiveModeRequested_b,                                        1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Jump to CheckView if Inactive Mode was not Requested */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckInactiveMode_2_CheckView(FX_FILTER)                             aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckInactiveMode,                   aHmiM_STM_f_NoModeRequested_b,                                              1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Jump back to Init if Active Mode was requested */
#define aHmiM_STM_Cfg_d_ST_ITEM_End_2_Init(FX_FILTER)                                                aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_End,                                 aHmiM_STM_f_ActiveModeRequested_b,                                          1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Always Jump from CheckView to CheckOvl */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckView_2_CheckOvl(FX_FILTER)                                      aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckView,                           aHmiM_STM_f_TransitionCheckViewToCheckOvl_b,                                1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Always Jump from CheckView to CheckOvl */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckOvl_2_CheckFailsafe(FX_FILTER)                                  aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckOvl,                            aHmiM_STM_f_TransitionCheckOvlToCheckFailsafe_b,                                1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* Jump to CheckInactiveMode if Overlays AND View didn't change */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckFailsafe_2_CheckInactiveMode(FX_FILTER)                         aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckFailsafe,                       aHmiM_STM_f_ScreenNotChanged_b,                                             1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* CheckOvl to RequestScreenOnZynq */
#define aHmiM_STM_Cfg_d_ST_ITEM_CheckFailsafe_2_RequestScreenOnZynq(FX_FILTER)                       aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_CheckFailsafe,                       aHmiM_STM_f_ScreenChanged_b,                                                1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* RequestScreenOnZynq to WaitForRequestedScreenOnZynq */
#define aHmiM_STM_Cfg_d_ST_ITEM_RequestScreenOnZynq_2_WaitForRequestedScreenOnZynq(FX_FILTER)        aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_RequestScreenOnZynq,                 aHmiM_STM_f_TransitionRequestScreenOnZynqToWaitForRequestedScreenOnZynq_b,  1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* WaitForRequestedScreenOnZynq to LockOutWait */
#define aHmiM_STM_Cfg_d_ST_ITEM_WaitForRequestedScreenOnZynq_2_LockOutWait(FX_FILTER)                aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq,        aHmiM_STM_f_WaitForScreenTimerExpired_b,                                    1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* WaitForRequestedScreenOnZynq to LockOutWait */
#define aHmiM_STM_Cfg_d_ST_ITEM_WaitForRequestedScreenOnZynq_2_LockOutWait2(FX_FILTER)               aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq,        aHmiM_STM_f_ScreenIsActiveOnZynq_b,                                         1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */
                                                                                                     /* LockOutWait to CheckInactiveMode */
#define aHmiM_STM_Cfg_d_ST_ITEM_LockOutWait_2_CheckInactiveMode(FX_FILTER)                           aHmiM_STM_D_DEFINE_STATE_CONDITION(aHmiM_STM_E_ST_LockOutWait,                         aHmiM_STM_f_LockOutWaitTimerExpired_b,                                      1,  FX_FILTER)
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- DEFINE STATE LIST / TRANSITIONs in dependency between STATE and FUNCTION ---
 * ###################################################################################################### */
#define aHmiM_STM_Cfg_d_ST_LIST_NotInit                            /* JUMP to Init */                                                                                                                                                \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_Init,                                 aHmiM_STM_Cfg_d_ST_ITEM_NotInit_2_Init)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_Init                               /* JUMP to CheckInactiveMode */                                                                                                                                   \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckInactiveMode,                    aHmiM_STM_Cfg_d_ST_ITEM_NotInit_2_Init)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_CheckInactiveMode                  /* JUMP to CheckView */                                                                                                                                           \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckView,                            aHmiM_STM_Cfg_d_ST_ITEM_CheckInactiveMode_2_CheckView),                        \
                                                                   /* JUMP to End */                                                                                                                                                 \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_End,                                  aHmiM_STM_Cfg_d_ST_ITEM_CheckInactiveMode_2_End)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_End                                /* JUMP to CheckInactiveMode */                                                                                                                                   \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_Init,                                 aHmiM_STM_Cfg_d_ST_ITEM_End_2_Init)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_CheckView                          /* JUMP to CheckOvl */                                                                                                                                            \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckOvl,                             aHmiM_STM_Cfg_d_ST_ITEM_CheckView_2_CheckOvl)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_CheckOvl                           /* JUMP to CheckFailsafe */                                                                                                                                       \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckFailsafe,                        aHmiM_STM_Cfg_d_ST_ITEM_CheckOvl_2_CheckFailsafe)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_CheckFailsafe                      /* JUMP to CheckInactiveMode */                                                                                                                                   \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckInactiveMode,                    aHmiM_STM_Cfg_d_ST_ITEM_CheckFailsafe_2_CheckInactiveMode),                    \
                                                                   /* JUMP to RequestScreenOnZynq */                                                                                                                                 \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_RequestScreenOnZynq,                  aHmiM_STM_Cfg_d_ST_ITEM_CheckFailsafe_2_RequestScreenOnZynq)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_RequestScreenOnZynq                  /* JUMP to WaitForRequestedScreenOnZynq */                                                                                                                      \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq,         aHmiM_STM_Cfg_d_ST_ITEM_RequestScreenOnZynq_2_WaitForRequestedScreenOnZynq)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_WaitForRequestedScreenOnZynq       /* JUMP to LockOutWait */                                                                                                                                         \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_LockOutWait,                          aHmiM_STM_Cfg_d_ST_ITEM_WaitForRequestedScreenOnZynq_2_LockOutWait),           \
                                                                   /* JUMP to LockOutWait */                                                                                                                                         \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_LockOutWait,                          aHmiM_STM_Cfg_d_ST_ITEM_WaitForRequestedScreenOnZynq_2_LockOutWait2)
/* ------------------------------------------------------------------------------------------------------ */
#define aHmiM_STM_Cfg_d_ST_LIST_LockOutWait                          /* JUMP to CheckInactiveMode */                                                                                                                                 \
                                                                   aHmiM_STM_D_DEFINE_STATE_ITEM(aHmiM_STM_E_ST_CheckInactiveMode,                    aHmiM_STM_Cfg_d_ST_ITEM_LockOutWait_2_CheckInactiveMode)
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
  * --- CREATE state, function and description array in dependency between STATE and FUNCTION ---
  * ###################################################################################################### */
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_NotInit,                            aHmiM_STM_Cfg_d_FX_LIST_NotInit,                            aHmiM_STM_Cfg_d_ST_LIST_NotInit)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_Init,                               aHmiM_STM_Cfg_d_FX_LIST_Init,                               aHmiM_STM_Cfg_d_ST_LIST_Init)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_CheckInactiveMode,                  aHmiM_STM_Cfg_d_FX_LIST_CheckInactiveMode,                  aHmiM_STM_Cfg_d_ST_LIST_CheckInactiveMode)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_CheckView,                          aHmiM_STM_Cfg_d_FX_LIST_CheckView,                          aHmiM_STM_Cfg_d_ST_LIST_CheckView)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_CheckOvl,                           aHmiM_STM_Cfg_d_FX_LIST_CheckOvl,                           aHmiM_STM_Cfg_d_ST_LIST_CheckOvl)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_CheckFailsafe,                      aHmiM_STM_Cfg_d_FX_LIST_CheckFailsafe,                      aHmiM_STM_Cfg_d_ST_LIST_CheckFailsafe)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_RequestScreenOnZynq,                aHmiM_STM_Cfg_d_FX_LIST_RequestScreenOnZynq,                aHmiM_STM_Cfg_d_ST_LIST_RequestScreenOnZynq)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq,       aHmiM_STM_Cfg_d_FX_LIST_WaitForRequestedScreenOnZynq,       aHmiM_STM_Cfg_d_ST_LIST_WaitForRequestedScreenOnZynq)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_LockOutWait,                        aHmiM_STM_Cfg_d_FX_LIST_LockOutWait,                        aHmiM_STM_Cfg_d_ST_LIST_LockOutWait)
aHmiM_STM_D_CREATE_FX_LIST_EXT(aHmiM_STM_E_ST_End,                                aHmiM_STM_Cfg_d_FX_LIST_End,                                aHmiM_STM_Cfg_d_ST_LIST_End)

/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- module global constants ---
 * ###################################################################################################### */
const aHmiM_STM_S_StateDescriptor_t aHmiM_STM_C_StateDiscriptorList_as[aHmiM_STM_E_ST_NumStates] =
{ 
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_NotInit,                            aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_Init,                               aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_CheckInactiveMode,                  aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_CheckView,                          aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_CheckOvl,                           aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_CheckFailsafe,                      aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_RequestScreenOnZynq,                aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq,       aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_LockOutWait,                        aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v),
  aHmiM_STM_D_DEFINE_STATE_DESCRIPTOR_ITEM(aHmiM_STM_E_ST_End,                                aHmiM_STM_f_OnEntry_v,  aHmiM_STM_f_OnRun_v,      aHmiM_STM_f_OnExit_v)
};
/* ------------------------------------------------------------------------------------------------------ */


/* === End Of Source File ================================================= */

