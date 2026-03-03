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

/* PRQA S 2814 EOF */ /* Suppress warning: "Possible: Dereference of NULL pointer." Only module internal calls which are verified that there will be no NULL pointer passed */

/* ######################################################################################################
 * --- MODULE VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_D_VERSION_ID_C "$Id: aHmiM_STM.c 1.1.3.1 2021/04/05 22:25:13IST Gopinath Ramanathan (gopirama) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- include files ---
 * ###################################################################################################### */
#define   AHMIM_STM_C_
#include  "aHmiM_STM.h"
#undef    AHMIM_STM_C_  /* PRQA S 0841 ++*/ /* Suppress warning "Using '#undef'." */
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- local enums ---
 * ###################################################################################################### */
typedef enum  aHmiM_STM_e_FX_EventCntrl_e
{ 
  aHmiM_STM_e_FX_OnEntry = 0,
  aHmiM_STM_e_FX_OnRun,
  aHmiM_STM_e_FX_OnExit
} aHmiM_STM_e_FX_EventCntrl_t;                /* define the new sub type for all states */
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- local variables ---
 * ###################################################################################################### */
static aHmiM_STM_e_FX_EventCntrl_t     aHmiM_STM_v_FX_EventCntrl_e;
static aHmiM_STM_E_StateMachineList_t  aHmiM_STM_v_StateMachine_e;
static aHmiM_STM_Error_t               aHmiM_STM_v_CurrentError_t;
/* ------------------------------------------------------------------------------------------------------ */


/* ######################################################################################################
 * --- local functions ---
 * ###################################################################################################### */
static BOOL aHmiM_STM_f_CheckConditions_b(const aHmiM_STM_S_StateDescriptor_t   *STDescriptor_ps,
                                                      aHmiM_STM_FX_ConditionPattern_t *FX_ConditionPattern_pt,
                                                      aHmiM_STM_E_StateMachineList_t  ST_CurrState_e);
static BOOL aHmiM_STM_f_SwitchState_b    (const aHmiM_STM_S_StateDescriptor_t   *STDescriptor_ps,
                                                      aHmiM_STM_FX_ConditionPattern_t FX_ConditionPattern_t,
                                                      aHmiM_STM_E_StateMachineList_t  *NewState_pe);
/* ------------------------------------------------------------------------------------------------------ */



/* ##############################################################################
 * ##############################################################################
 * ### GLOBAL FUNCTIONS #########################################################
 * ##############################################################################
 * ############################################################################## */



/* ===============================================================
 * Purpose  : initialize HMI manager module
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
void aHmiM_STM_F_Init_v(void)
{
  /* DD-ID: {B41110DA-76C3-4136-B6E3-9B3112F004C0}*/
  //appLogPrintf("\n ###### Inside aHmiM_STM_F_Init_v  ###### \n");
  aHmiM_STM_v_FX_EventCntrl_e = aHmiM_STM_e_FX_OnEntry;   /* initialize state event to OnStart    */
  aHmiM_STM_v_StateMachine_e  = aHmiM_STM_E_ST_NotInit;   /* initialize start position            */
  aHmiM_STM_v_CurrentError_t  = aHmiM_STM_D_NO_ERROR;       /* no errors on module                  */
  aHmiM_STM_F_InitCfg_v();                                  /* initialize data in config sub module */
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */


/* ===============================================================
 * Purpose  : cyclicaly calling handler
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
void aHmiM_STM_F_Task10msec_v(void)
{
  /* DD-ID: {95F95E56-C010-4ded-9B64-AB080DC1F9A5}*/
  /* --- declarations --- */
  const aHmiM_STM_S_StateDescriptor_t    *STDescriptor_ps;
        aHmiM_STM_FX_ConditionPattern_t  v_FX_ConditionPattern_t;
        aHmiM_STM_E_StateMachineList_t   ST_NewState_e;
        aHmiM_STM_E_StateMachineList_t   ST_CurrState_e;
        u8                               ST_DeadLockCounter_u8 = 10;
        BOOL                             ST_Change_b;
  /* --- declarations --- */

  /* ############################################################## */
  aHmiM_STM_F_OnModuleCall_v(aHmiM_STM_v_StateMachine_e);                             /* -> run at every module call  */
  /* ############################################################## */ 

  do
  { 
    ST_Change_b = FALSE;                                                              /* -> reset state change identifier                   */    
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    if( aHmiM_STM_v_StateMachine_e < aHmiM_STM_E_ST_NumStates )                       /* ?? state index within state machine                */
    { /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      ST_CurrState_e  = aHmiM_STM_v_StateMachine_e;                                   /* -> store current state machine position            */
      STDescriptor_ps = &aHmiM_STM_C_StateDiscriptorList_as[ST_CurrState_e];          /* -> set pointer to an indexed state descriptor      */
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      /* --- FX Event OnStart --- */
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      if( aHmiM_STM_v_FX_EventCntrl_e == aHmiM_STM_e_FX_OnEntry )                     /* ?? is fx event state set to OnEnter                */
      {
        aHmiM_STM_v_FX_EventCntrl_e = aHmiM_STM_e_FX_OnRun;                           /* -> switch event OnEnter to OnRun                   */
        if( STDescriptor_ps->FX_OnStartEvent_pf != NULL )                             /* ?? is OnEnter function valid                       */
        { 
          (void)STDescriptor_ps->FX_OnStartEvent_pf(ST_CurrState_e);  }               /* -> call OnEnter function                           */
        else
        { /* do nothing */ }
      }
      else                                                                            /* !! any other state is currently active             */
      { /* do nothing */ }
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      /* --- StateMachine Kernel --- */
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      if( STDescriptor_ps->FX_ConditionList_pabf != NULL )                            /* ?? functions pointer valid                         */
      {                                                                               /* ?? run sub function to detect all fail conditions  */
        if(TRUE == aHmiM_STM_f_CheckConditions_b(STDescriptor_ps, &v_FX_ConditionPattern_t, ST_CurrState_e) )
        {                                                                             /* ?? run sub function to detect new state            */
          if(TRUE == aHmiM_STM_f_SwitchState_b(STDescriptor_ps, v_FX_ConditionPattern_t, &ST_NewState_e) )
          { 
            if( aHmiM_STM_v_StateMachine_e != ST_NewState_e )                         /* ?? switch to a new state */
            {
              aHmiM_STM_v_StateMachine_e  = ST_NewState_e;                            /* -> change current state to a new one */
              aHmiM_STM_v_FX_EventCntrl_e = aHmiM_STM_e_FX_OnExit;                    /* -> change fx event to OnStop         */
              ST_Change_b               = TRUE;                                       /* -> state change detected             */
            }
            else                                                                      /* !! same state  */
            { /* do nothing */ }                                                                     /* -> do nothing  */
          }
          else                                                                        /* !! detection failed  */
          { /* do nothing */ }
        }
        else                                                                          /* !! detection failed or no changes needed */
        { /* do nothing */ }
      }
      else
      { /* do nothing */ }
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      /* --- FX Event OnRun --- */
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      if(       aHmiM_STM_v_FX_EventCntrl_e == aHmiM_STM_e_FX_OnRun   )               /* ?? is fx event state set to OnRun                  */
      {
        if( STDescriptor_ps->FX_OnRunEvent_pf != NULL )                               /* ?? is OnRun function valid                         */
        { 
          (void)STDescriptor_ps->FX_OnRunEvent_pf(ST_CurrState_e);   }                 /* -> call OnRun function                             */
        else
        { /* do nothing */ }
      }
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      /* --- FX Event OnStop --- */
      /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      else if(  aHmiM_STM_v_FX_EventCntrl_e == aHmiM_STM_e_FX_OnExit  )               /* ?? is fx event state set to OnStop                 */
      { 
        aHmiM_STM_v_FX_EventCntrl_e = aHmiM_STM_e_FX_OnEntry;                         /* -> switch event OnStop to OnEnter                  */
        if( STDescriptor_ps->FX_OnStopEvent_pf != NULL )                              /* ?? is OnEnter function valid                       */
        { (void)STDescriptor_ps->FX_OnStopEvent_pf(ST_CurrState_e);  }                /* -> call OnEnter function                           */
        else
        { /* do nothing */ }
      }
      else                                                                            /* -> should never happen                             */
      { aHmiM_STM_v_FX_EventCntrl_e = aHmiM_STM_e_FX_OnEntry; }
    } /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    else                                                                              /* !! state index outside limits */
    { aHmiM_STM_v_CurrentError_t = aHmiM_STM_D_INTERNAL_IDX_ERROR;  }                 /* -> set module error  */
    /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
  } while( (--ST_DeadLockCounter_u8 > 0) && (TRUE == ST_Change_b) );                  /* ?? a changed state detected AND dead look counter OK */ /* PRQA S 3440 */ /* Suppress Level 4 Warning: Using the value resulting from a ++ or -- operation. */
  /* ############################################################## */
  aHmiM_STM_F_OnModuleReturn_v(aHmiM_STM_v_StateMachine_e);                           /* -> run at every module return  */
  /* ############################################################## */
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */



/* ===============================================================
 * Purpose  : return last module error
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : aHmiM_STM_Error_t
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
aHmiM_STM_Error_t aHmiM_STM_F_GetLastError_t(void)
{
  /* DD-ID: {697CCBCB-B8E0-453b-A83D-9EFBEB0C58DF}*/
  return aHmiM_STM_v_CurrentError_t;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */


/* ===============================================================
 * Purpose  : return current state 
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : none
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : aHmiM_STM_v_StateMachine_e
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
aHmiM_STM_E_StateMachineList_t aHmiM_STM_F_GetCurrentState_e(void)
{
  /* DD-ID: {68E51815-D11E-41ac-BB66-9870D49483D1}*/
  return aHmiM_STM_v_StateMachine_e;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Request Inactivation Mode of StateMachine
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Successful or Failed
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_RequestInactivation_e(void)
{
  /* DD-ID: {C2E074FB-6396-443a-A814-AA6F0DA55EDE}*/
  aHmiM_STM_F_RequestInact_v(aHmiM_STM_v_StateMachine_e);
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Request Normal Operation Mode of StateMachine
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Successful or Failed
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_RequestNormalOperation_e(void)
{
  /* DD-ID: {CC22335D-9591-49e6-A06D-9E2C5C8ADAE2}*/
  aHmiM_STM_F_RequestNormalOp_v(aHmiM_STM_v_StateMachine_e);
  return;
}

void aHmiM_STM_F_Reset_CurrentViewOnZynqM_v(void)
{
  /* DD-ID: {88202D5E-6D36-4d9b-8562-50D9AFEFE231}*/
  aHmiM_STM_F_Reset_CurrentViewOnZynqM__v();
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */


/* ##############################################################################
 * ##############################################################################
 * ### LOCAL SUB FUNCTIONS ######################################################
 * ##############################################################################
 * ############################################################################## */



/* ===============================================================
 * Purpose  : this function executes list functions for the 
 *          : current active state and returns result as a pattern
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : STDescriptor_ps : current active state
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : FX_ConditionPattern_pt: function patttern
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckConditions_b( const  aHmiM_STM_S_StateDescriptor_t     *STDescriptor_ps,
                                                  aHmiM_STM_FX_ConditionPattern_t   *FX_ConditionPattern_pt,
                                                  aHmiM_STM_E_StateMachineList_t    ST_CurrState_e)
{
  /* DD-ID: {99E8392E-DE43-486a-BC8F-3F6865A88C9F}*/
  /* --- declarations --- */
  BOOL  Result_b = TRUE;
  u8 fx_idx_u8;
  /* --- declarations --- */
  *FX_ConditionPattern_pt=(aHmiM_STM_FX_ConditionPattern_t)0UL;
  for(  fx_idx_u8 = 0u;
        fx_idx_u8 < STDescriptor_ps->FX_ConditionListLength_u8; 
        fx_idx_u8++ )         
  { /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    if( NULL != STDescriptor_ps->FX_ConditionList_pabf[fx_idx_u8] )                   /* is valid function index stored  */  /* PRQA S 0491 2 */ /* Suppress warning: "Array subscripting applied to an object of pointer type." -> This is used only for internal used data which size is known */
    {
      if( TRUE == STDescriptor_ps->FX_ConditionList_pabf[fx_idx_u8](ST_CurrState_e) ) /* run condition function */
      { *FX_ConditionPattern_pt |= (0x01u << (fx_idx_u8));  }                         /* -> result condition is TRUE */
      else                                                                            /* !! result condition is FALSE */
      { /* do nothing */ }
    } /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    else                                                                              /* !! index is outside of the FX limits */
    {
      aHmiM_STM_v_CurrentError_t = aHmiM_STM_D_INTERNAL_IDX_ERROR;                    /* -> set error */
      Result_b                 = FALSE;                                               /* -> return negative result  */
      break;
    }
  }

  return  Result_b;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */


/* ===============================================================
 * Purpose  : this fuction compares the function pattern with
 *          : defined state list and returns a new state as result
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : STDescriptor_ps: current active state
 *          : FX_ConditionPattern_t: function pattern
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : NewState_pe : new state
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 06-December-2012 => function created        DONE
 * =============================================================== */
static BOOL aHmiM_STM_f_SwitchState_b (const  aHmiM_STM_S_StateDescriptor_t   *STDescriptor_ps,
                                              aHmiM_STM_FX_ConditionPattern_t FX_ConditionPattern_t,
                                              aHmiM_STM_E_StateMachineList_t  *NewState_pe)
{
  /* DD-ID: {22E75F11-1A88-4405-BC33-91A151B7974C}*/
  /* --- declarations --- */
  const  aHmiM_STM_S_StateCondition_t   *StateCondition_ps;
         BOOL                           Result_b = FALSE;
         u8                             st_idx_u8;
  /* --- declarations --- */

  if( NULL != STDescriptor_ps->ST_ConditionList_pas )                           /* ?? pointer valid */
  { /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
    for( StateCondition_ps = STDescriptor_ps->ST_ConditionList_pas,             /* -> get pointer to first element */ /* PRQA S 3418 3 */ /* Suppress warning: "The comma operator has been used in a 'for' statement." -> This is intended here */
         st_idx_u8 = 0u; 
         st_idx_u8 < STDescriptor_ps->ST_ConditionListLength_u8;
         st_idx_u8++,
         StateCondition_ps++ )                                                  /* -> run through all items */        /* PRQA S 0489 */ /* Suppress warning: "The integer value 1 is being added or subtracted from a pointer." -> This is intended here */
    { /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      if( (StateCondition_ps->FX_FilterPattern_t & FX_ConditionPattern_t) ==
           StateCondition_ps->FX_ConditionPattern_t  )                          /* ?? fitted pattern detected */
      { /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
        if( StateCondition_ps->NewState_e < aHmiM_STM_E_ST_NumStates )          /* ?? is stored state valid */
        {
          *NewState_pe  = StateCondition_ps->NewState_e;                        /* -> yes, and store new state  */
          Result_b      = TRUE;                                                 /* -> return with positive result */
        }
        else                                                                    /* !! illegal state */
        { /* do nothing */ }
        break;
      } /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
      else
      { /* do nothing */ }
    }
  } /* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
  else                                                                          /* !! illegal pointer value */
  {
    aHmiM_STM_v_CurrentError_t = aHmiM_STM_D_INTERNAL_IDX_ERROR;                /* -> set error */
  }

  return  Result_b;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */


/* === End Of Source File ================================================= */

