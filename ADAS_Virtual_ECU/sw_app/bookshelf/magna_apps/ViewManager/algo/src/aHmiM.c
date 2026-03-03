/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 * This document in its entirety is CONFIDENTIAL and may not be disclosed,
 * disseminated or distributed to parties outside MAGNA Electronics
 * without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:       HMI Manager
 * DESIGN:      2014
 * DESCRIPTION: Handles the behavior of HMI in normal operation
 * ======================================================================== */

/**
 * \file     aHmiM.c
 * \brief    Handles the behavior of HMI in normal operation
 * \author   Stephan Fries
 * \version  $Revision: 1.1.4.1 $
 * \details  c file private description of module
 */
/* --- Defines, Includes ----------------------------------------------------------- */
#define AHMIM_D_VERSION_ID_C "$Id: aHmiM.c 1.1.4.1 2021/04/05 22:25:12IST Gopinath Ramanathan (gopirama) Draft  $"  /**< \brief short c-file private description of lFoo_D_VERSION_ID_C */

#include "aHmiM.h"
#include "aHmiM_STM.h"
/* --------------------------------------------------------------------------------- */

/* PRQA S 3218 EOF */ /* suppresses QAC warning for accessing statemachine variable */

/* --- Private Typedefinitions, Enumerations, Defines ------------------------------ */

/* State Variables for the State Machines - these may only be changed with the call of the respective RunState() Function */
static aHmiM_E_ModuleState_t aHmiM_v_ModuleState_e = aHmiM_E_NotInit;

static aHmiM_E_RequestedMode_t aHmiM_v_RequestedMode_e = aHmiM_E_NoModeRequested;

/* Statefunction Type needed for the Main STM State Table - Typedefinition of Function Pointer for StateMachine */
typedef aHmiM_E_ModuleState_t (*aHmiM_fp_StateFunction_t)(void);



#define AHMIM_D_HMIM_SCREENREQ_TIMEOUTCOUNT_THRESHOLD    3
#define AHMIM_D_HMIM_RESTART_THRESHOLD                   2

static u32 aHmiM_v_MonitorHMI_ScreenRequestTimeoutCountThreshold_u32 = AHMIM_D_HMIM_SCREENREQ_TIMEOUTCOUNT_THRESHOLD;
static u32 aHmiM_v_MonitorHMI_RestartThreshold_u32 = AHMIM_D_HMIM_RESTART_THRESHOLD;
static u32 aHmiM_v_MonitorHMI_RestartCount_u32 = 0;

/* --- Private Macros -------------------------------------------------------------- */

/* --- Private Function Declarations ----------------------------------------------- */
static void aHmiM_f_MonitorHMI_v(void);



/* Run Function for the Main State Machine called in 10msec Task */
static aHmiM_E_ModuleState_t aHmiM_f_RunState_e(aHmiM_E_ModuleState_t cur_state);
/* State Functions for the Main STM */
static aHmiM_E_ModuleState_t aHmiM_f_DoState_NotInit_e(void);
static aHmiM_E_ModuleState_t aHmiM_f_DoState_Init_e(void);
static aHmiM_E_ModuleState_t aHmiM_f_DoState_NormalOperation_e(void);
static aHmiM_E_ModuleState_t aHmiM_f_DoState_Inactive_e(void);

/* State Table for the Main STM */
static aHmiM_fp_StateFunction_t const aHmiM_a_StateTable[aHmiM_E_NumStates] =
{
  &aHmiM_f_DoState_NotInit_e,
  &aHmiM_f_DoState_Init_e,
  &aHmiM_f_DoState_NormalOperation_e,
  &aHmiM_f_DoState_Inactive_e
};

/* --- Private Function Definitions ------------------------------------------------ */
static void aHmiM_f_MonitorHMI_v(void)
{
  /* DD-ID: {E97721D7-F2B7-416d-9B63-17864E9FF059}*/
  u32 ScreenRequestTimeoutCount_u32 = aHmiM_STM_F_GetScreenRequestTimeoutCount_u32();

  if((ScreenRequestTimeoutCount_u32 >= aHmiM_v_MonitorHMI_ScreenRequestTimeoutCountThreshold_u32) && (aHmiM_v_MonitorHMI_RestartCount_u32 < aHmiM_v_MonitorHMI_RestartThreshold_u32))
  {
    aHmiM_v_MonitorHMI_RestartCount_u32++;
    aHmiM_STM_F_ResetScreenRequestTimeoutCount_v();
  }
  else
  {
    /* do nothing */
  }

  return;
}

/* ######################################################################################################
 * --- Main State Machine ---
 * ###################################################################################################### */
static aHmiM_E_ModuleState_t aHmiM_f_RunState_e(aHmiM_E_ModuleState_t cur_state)
{
  /* DD-ID: {EA450381-B237-423c-A52F-B7286F77E45C}*/
  return aHmiM_a_StateTable[cur_state](); /* call of State Function */
}

static aHmiM_E_ModuleState_t aHmiM_f_DoState_NotInit_e(void)
{
  /* DD-ID: {4DD91D08-3641-416a-B151-13714DFC3185}*/
  return aHmiM_E_NotInit; /* stay in this state */
}

static aHmiM_E_ModuleState_t aHmiM_f_DoState_Init_e(void)
{
  /* DD-ID: {A4F7AFDB-F014-4fd9-AD67-EF8B2D5CC2DF}*/
  /* do all necessary inits here */
  return aHmiM_E_NormalOperation;
}

static aHmiM_E_ModuleState_t aHmiM_f_DoState_NormalOperation_e(void)
{
  /* DD-ID: {7B35F3E1-555D-411a-A7A2-6808229F0800}*/
  aHmiM_E_ModuleState_t retState = aHmiM_v_ModuleState_e;

  if(aHmiM_E_InactiveModeRequested == aHmiM_v_RequestedMode_e)
  {
    aHmiM_STM_F_RequestInactivation_e();
    if(aHmiM_STM_E_ST_End ==  aHmiM_STM_F_GetCurrentState_e())
    {
      /* If the NormalOperationSTM has gone to End State, then also set the Superior STM to inactive */
      retState = aHmiM_E_Inactive;
      /* Reset the Requested Mode to NoModeRequested */
      aHmiM_v_RequestedMode_e = aHmiM_E_NoModeRequested;
    }
    else
    {
      /* Last in NormalOperation State till SubSTM is in End State */
      retState = aHmiM_E_NormalOperation;
    }
  }
  else
  {
    retState = aHmiM_E_NormalOperation;
  }
  return retState;
}

static aHmiM_E_ModuleState_t aHmiM_f_DoState_Inactive_e(void)
{
  /* DD-ID: {3F252FDA-D976-481b-B857-0310A4F406F2}*/
  aHmiM_E_ModuleState_t retState = aHmiM_v_ModuleState_e;
  /* If the NormalOperationSTM isn't in End State anymore, then also set the Superior STM to back to NormalOperation */
  if(aHmiM_E_NormalOperationModeRequested == aHmiM_v_RequestedMode_e)
  {
    aHmiM_STM_F_RequestNormalOperation_e();
    if(aHmiM_STM_E_ST_End !=  aHmiM_STM_F_GetCurrentState_e())
    {
      /* If the NormalOperationSTM isn't in End State anymore, then also set the Superior STM back to Active */
      retState = aHmiM_E_NormalOperation;
      /* Reset the Requested Mode to NoModeRequested */
      aHmiM_v_RequestedMode_e = aHmiM_E_NoModeRequested;
    }
    else
    {
      /* Last in Inactive State till SubSTM isn't in End State anymore */
      retState = aHmiM_E_Inactive;
    }
  }
  else
  {
    retState = aHmiM_E_Inactive;
  }
  return retState;
}

/* --- Public Function Definitions ------------------------------------------------- */
void aHmiM_F_Init_v(void)
{
  /* DD-ID: {9CE60432-E680-4f55-8D75-D2C615881969}*/
  /* This Function should only be called once when the software starts up */
  aHmiM_v_ModuleState_e = aHmiM_E_Init; /* first valid state */
  aHmiM_v_ModuleState_e = aHmiM_f_RunState_e(aHmiM_v_ModuleState_e);

  aHmiM_v_MonitorHMI_ScreenRequestTimeoutCountThreshold_u32 = AHMIM_D_HMIM_SCREENREQ_TIMEOUTCOUNT_THRESHOLD;

  aHmiM_v_MonitorHMI_RestartThreshold_u32 = AHMIM_D_HMIM_RESTART_THRESHOLD;
  aHmiM_v_MonitorHMI_RestartCount_u32 = 0;

  return;
}

void aHmiM_F_DeInit_v(void)
{
  /* DD-ID: {F71C85C9-95C6-4723-B67C-50AA8C40177A}*/
  /* Be careful with this Function Call! This will hard reset the STM! */
  aHmiM_v_ModuleState_e = aHmiM_E_NotInit;
  return;
}

void aHmiM_F_Task10msec_v(void)
{
  /* DD-ID: {F6D68D50-F25D-43df-9299-51A965E67BCC}*/
  aHmiM_v_ModuleState_e = aHmiM_f_RunState_e(aHmiM_v_ModuleState_e); /* Run the State Machine */
  aHmiM_f_MonitorHMI_v();
  return;
}

aHmiM_E_ModuleState_t aHmiM_F_GetModuleState_e(void)
{
  /* DD-ID: {0AA0BB19-99A0-427e-B35F-ED53B99F404B}*/
  return aHmiM_v_ModuleState_e;
}

Std_E_ReturnType_t aHmiM_F_IsInactive_e(void)
{
  /* DD-ID: {0B8F2919-5328-49b1-B1A4-172E9ADB00EA}*/
  Std_E_ReturnType_t retVal;

  if(aHmiM_E_Inactive == aHmiM_v_ModuleState_e)
  {
    retVal = Std_E_RetType_Successful;
  }
  else
  {
    retVal = Std_E_RetType_Failed;
  }

  return retVal;
}

Std_E_ReturnType_t aHmiM_F_RequestInactivation_e(void)
{
  /* DD-ID: {DBBFA4CD-BD06-43f2-B631-53005C223376}*/
  Std_E_ReturnType_t retVal = Std_E_RetType_Successful;

  if(aHmiM_E_NormalOperation == aHmiM_v_ModuleState_e)
  {
    aHmiM_v_RequestedMode_e = aHmiM_E_InactiveModeRequested;
  }
  if(aHmiM_E_Inactive == aHmiM_v_ModuleState_e)
  {
    /* OK */
  }
  else
  {
    /* Only Request Inactive Mode if Module is in NormalOperation State */
    retVal = Std_E_RetType_Failed;
  }
  return retVal;
}

Std_E_ReturnType_t aHmiM_F_RequestNormalOperation_e(void)
{
  /* DD-ID: {4E67BFE0-9E80-4dc8-9294-ED17BD1AE7CB}*/
  Std_E_ReturnType_t retVal = Std_E_RetType_Successful;

  if(aHmiM_E_Inactive == aHmiM_v_ModuleState_e)
  {
    aHmiM_v_RequestedMode_e = aHmiM_E_NormalOperationModeRequested;
  }
  else if(aHmiM_E_NormalOperation == aHmiM_v_ModuleState_e)
  {
    /* OK */
  }
  else
  {
    /* Only Request Normal Operation Mode if Module is in Inactive State */
    retVal = Std_E_RetType_Failed;
  }
  return retVal;
}

BOOL aHmiM_F_IsHmiWorkingProperly_b(void)
{
  /* DD-ID: {744B8974-A8C0-452c-9D80-75B82E589C4A}*/
  BOOL bRet;

  if(TRUE == aHmiM_STM_F_IsScreenRequestTimedOut_b())
  {
    bRet = FALSE;
  }
  else
  {
    bRet = TRUE;
  }
  return bRet;
}

u32 aHmiM_F_GetRestartCount_u32(void)
{
  /* DD-ID: {9882CECE-7BCA-4c21-AB98-507CBAD050CF}*/
  return aHmiM_v_MonitorHMI_RestartCount_u32;
}

u32 aHmiM_F_GetRestartThreshold_u32(void)
{
  /* DD-ID: {6344A354-5854-4356-B68E-FF3DCF0B6678}*/
  return aHmiM_v_MonitorHMI_RestartThreshold_u32;
}

u32 aHmiM_F_GetScreenRequestTimeoutCountThreshold_u32(void)
{
  /* DD-ID: {E84E9B04-FFB4-4ac7-BD76-ACBE4CB36542}*/
  return aHmiM_v_MonitorHMI_ScreenRequestTimeoutCountThreshold_u32;
}

void aHmiM_F_SetRestartCount_v(u32 value)
{
  /* DD-ID: {7EBF4C46-53F2-4fcc-98C1-0103D26C63B8}*/
  aHmiM_v_MonitorHMI_RestartCount_u32 = value;
  return;
}

void aHmiM_F_SetRestartThreshold_v(u32 value)
{
  /* DD-ID: {3348D37C-6C83-43f8-98F6-38FDA08960ED}*/
  aHmiM_v_MonitorHMI_RestartThreshold_u32 = value;
  return;
}

void aHmiM_F_SetScreenRequestTimeoutCountThreshold_v(u32 value)
{
  /* DD-ID: {6ADB9547-C97F-49fa-8A51-6722F2D8B2CA}*/
  aHmiM_v_MonitorHMI_ScreenRequestTimeoutCountThreshold_u32 = value;
  return;
}

/* --------------------------------------------------------------------------------- */
/* END OF FILE: aHmiM.c */

