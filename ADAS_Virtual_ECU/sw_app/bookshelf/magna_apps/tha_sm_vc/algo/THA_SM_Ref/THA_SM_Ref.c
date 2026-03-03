/*
 * File: THA_SM_Ref.c
 *
 * Code generated for Simulink model 'THA_SM_Ref'.
 *
 * Model version                  : 1.1861
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:07 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "THA_SM_Ref.h"
#include "THA_SM_Ref_private.h"

/* Named constants for Chart: '<S157>/Chart2' */
#define THA_SM_Ref_IN_Idle             ((uint8_T)1U)
#define THA_SM_Ref_IN_NO_ACTIVE_CHILD  ((uint8_T)0U)
#define THA_SM_Ref_IN_Standby          ((uint8_T)2U)

/* Named constants for Chart: '<S35>/Chart2' */
#define THA_SM_Ref_IN_Idle_f0zo        ((uint8_T)1U)
#define THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e ((uint8_T)0U)
#define THA_SM_Ref_IN_Standby_e4zz     ((uint8_T)2U)

/* Named constants for Chart: '<S6>/THA_HMI_Logic_Flow' */
#define THA_SM_Ref_IN_Active           ((uint8_T)1U)
#define THA_SM_Ref_IN_AngleTooSteep    ((uint8_T)1U)
#define THA_SM_Ref_IN_CnfrmComManuver  ((uint8_T)1U)
#define THA_SM_Ref_IN_CoulperDetection ((uint8_T)1U)
#define THA_SM_Ref_IN_CoulperLocSelected ((uint8_T)2U)
#define THA_SM_Ref_IN_CoulperNotPresent ((uint8_T)1U)
#define THA_SM_Ref_IN_CouplerHeightConfirmation ((uint8_T)3U)
#define THA_SM_Ref_IN_CplrSelCnfrm     ((uint8_T)2U)
#define THA_SM_Ref_IN_DisplayDistCount ((uint8_T)2U)
#define THA_SM_Ref_IN_Enabled          ((uint8_T)2U)
#define THA_SM_Ref_IN_Engaged          ((uint8_T)3U)
#define THA_SM_Ref_IN_EngagedSuppression ((uint8_T)3U)
#define THA_SM_Ref_IN_HitchDetection   ((uint8_T)3U)
#define THA_SM_Ref_IN_HitchNotPresent  ((uint8_T)4U)
#define THA_SM_Ref_IN_Idle_cuxx        ((uint8_T)2U)
#define THA_SM_Ref_IN_Init             ((uint8_T)4U)
#define THA_SM_Ref_IN_NotInZone        ((uint8_T)5U)
#define THA_SM_Ref_IN_ReachSelPt       ((uint8_T)4U)
#define THA_SM_Ref_IN_RemHandandReverse ((uint8_T)5U)
#define THA_SM_Ref_IN_THA_Complete     ((uint8_T)5U)
#define THA_SM_Ref_IN_THA_Fault        ((uint8_T)1U)
#define THA_SM_Ref_IN_THA_Normal       ((uint8_T)2U)

/* Named constants for Chart: '<S99>/CplrDetStsHyst' */
#define THA_SM_Ref_IN_counter_state    ((uint8_T)1U)
#define THA_SM_Ref_IN_init_state       ((uint8_T)2U)

/* Named constants for Chart: '<S7>/THA_MainStateMachine' */
#define THA_SM_Ref_IN_Completed        ((uint8_T)1U)
#define THA_SM_Ref_IN_Enabled_Selection ((uint8_T)2U)
#define THA_SM_Ref_IN_Enabled_armw     ((uint8_T)1U)
#define THA_SM_Ref_IN_Engaged_Delta    ((uint8_T)2U)
#define THA_SM_Ref_IN_Engaged_Inquiry  ((uint8_T)3U)
#define THA_SM_Ref_IN_Engaged_Main     ((uint8_T)3U)
#define THA_SM_Ref_IN_Engaged_Suppression ((uint8_T)4U)
#define THA_SM_Ref_IN_Engaged_ejok     ((uint8_T)1U)
#define THA_SM_Ref_IN_Fault            ((uint8_T)1U)
#define THA_SM_Ref_IN_Initial          ((uint8_T)3U)
#define THA_SM_Ref_IN_Off              ((uint8_T)4U)
#define THA_SM_Ref_IN_THA_Activ_Process ((uint8_T)5U)

/* Exported block signals */
real32_T MeTHA_deg_CplrAng;            /* '<S2>/SignalCopy2'
                                        * Coupler angle.
                                        */
int32_T MeTHA_px_HitchCplrPixDiffLong; /* '<S2>/SignalCopy3'
                                        * Longitudinal Pixel Y difference from hitch to coupler.
                                        */
int32_T MeTHA_px_HitchCplrPixDiffLat;  /* '<S2>/SignalCopy4'
                                        * Longitudinal Pixel X difference from hitch to coupler.
                                        */
TeTHA_e_ScreenRequest MeSVS_e_THAScrResp;/* '<S2>/SignalCopy7'
                                          * THA screen request acknowledgement from HMI.
                                          */
TeTHA_e_HitchDetctStatus MeTHA_e_HitchDetctStatus;/* '<S2>/SignalCopy'
                                                   * Hitch detection status.
                                                     0 - Not_Valid
                                                     1 - Not_Detected
                                                     2 - Detected
                                                   */
TeTHA_e_CplrDetctStatus MeTHA_e_CplrDetctStatus;/* '<S2>/SignalCopy1'
                                                 * Coupler detection status.
                                                   0 - Not valid
                                                   1 - Not_Detected
                                                   2 - Detected
                                                 */
boolean_T MeSVS_b_THASftBtnPrsdStsToTHA;/* '<S2>/SignalCopy5'
                                         * THA soft button pressed status.
                                         */
boolean_T MeSVS_b_ImgDefeatReqSts;     /* '<S2>/SignalCopy8'
                                        * Cancel Button
                                        */
boolean_T MeSVS_b_IsConfirmBtnPrsd;    /* '<S2>/SignalCopy6'
                                        * Confirm button pressed.
                                        */
boolean_T MeTHA_b_FidDisabled;         /* '<S2>/SignalCopy49' */
boolean_T MeTHA_b_FidCamCalAbort;      /* '<S2>/SignalCopy53' */
boolean_T MePRX_b_CanNod63;            /* '<S2>/SignalCopy51'
                                        * PROXI parameter CAN node 63 (TTM).
                                        */
boolean_T MePRX_b_CanNod95;            /* '<S2>/SignalCopy52'
                                        * PROXI parameter CAN node 95 (ITBM/ITCM).
                                        */
boolean_T MeTHA_b_ActivTrns;           /* '<S93>/LogicalOperator9'
                                        * THA activation condition transition model internal signal.
                                        */
boolean_T MeTHA_b_AbortSteerTrqReq;    /* '<S109>/LogicalOperator6'
                                        * THA abort request due to EPS, model internal signal.
                                        */
boolean_T MeTHA_b_AbortSpdLimReq;      /* '<S108>/LogicalOperator4'
                                        * THA abort request due to BSM or ECM, model internal signal.
                                        */
boolean_T MeTHA_b_AbortCndnFaulted;    /* '<S19>/LogicalOperator12'
                                        * THA abort condition faulted model internal signal.
                                        */
boolean_T MeTHA_b_FidDLDAbort;         /* '<S2>/SignalCopy40' */
boolean_T MeTHA_b_FeatureOverride;     /* '<S17>/Logical Operator3'
                                        * THA abort condition if any other Driver Assist feature takes over actuation.
                                        */
boolean_T MeTHA_b_AbortCndnEnabled;    /* '<S5>/Logical Operator'
                                        * THA abort condition Enabled model internal signal.
                                        */
boolean_T MeTHA_b_OverSpeedAbort;      /* '<S44>/RelationalOperator'
                                        * THA abort condition if vehicle speed exceeds beyond specified limit.
                                        */
boolean_T MeTHA_b_AbortCndnEngaged;    /* '<S5>/Logical Operator1'
                                        * THA abort condition Engaged model internal signal.
                                        */
boolean_T MeSVS_b_ViewZoomSts;         /* '<S2>/SignalCopy9'
                                        * HMI view zoom status.
                                          0 - Normal view
                                          1- Zoomed view
                                        */
boolean_T MeSVS_b_THAScrTchSts;        /* '<S2>/SignalCopy11'
                                        * THA screen touch status.
                                        */
boolean_T MeSVS_b_THAAbortReq;         /* '<S2>/SignalCopy39'
                                        * THA feature abort request from HMI.
                                        */
boolean_T MeTHA_b_THACompleteHMITrig;  /* '<S75>/LogicalOperator'
                                        * THA complete HMI trigger model internal signal.
                                        */
boolean_T MePRX_b_ParkWithStop;        /* '<S2>/SignalCopy48'
                                        * Park with stop.
                                        */
boolean_T MeSVS_b_THAMnvrStartBtnPrsd; /* '<S2>/SignalCopy10'
                                        * THA start manuever button pressed status.
                                        */

/* Block signals (default storage) */
B_THA_SM_Ref_caua_T THA_SM_Ref_B;

/* Block states (default storage) */
DW_THA_SM_Ref_fwu4_T THA_SM_Ref_DW;

/* Forward declaration for local functions */
static void THA_SM_Ref_THA_Activ_Process(TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo);
static void THA_SM_Ref_exit_internal_Enabled(void);
static void THA_SM_Ref_exit_internal_THA_Normal(void);
static void THA_SM_Ref_Enabled(TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm);
static void THA_SM_Ref_THA_Normal(TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm, boolean_T
  *rty_MeTHA_b_UsrInputTimeOut);

/*
 * System initialize for atomic system:
 *    '<S157>/Chart2'
 *    '<S158>/Chart2'
 *    '<S159>/Chart2'
 */
void THA_SM_Ref_Chart2_Init(boolean_T *rty_switchOut)
{
  *rty_switchOut = false;
}

/*
 * System reset for atomic system:
 *    '<S157>/Chart2'
 *    '<S158>/Chart2'
 *    '<S159>/Chart2'
 */
void THA_SM_Ref_Chart2_Reset(boolean_T *rty_switchOut, DW_Chart2_THA_SM_Ref_T
  *localDW)
{
  localDW->temporalCounter_i1 = 0U;
  localDW->is_active_c12_THA_SM_Ref = 0U;
  localDW->is_c12_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD;
  *rty_switchOut = false;
}

/*
 * Output and update for atomic system:
 *    '<S157>/Chart2'
 *    '<S158>/Chart2'
 *    '<S159>/Chart2'
 */
void THA_SM_Ref_Chart2(const boolean_T *rtu_Trigger, real32_T
  rtu_KeTHA_s_HmiFaultPopUpDur, boolean_T *rty_switchOut, DW_Chart2_THA_SM_Ref_T
  *localDW)
{
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S157>/Chart2' */
  if ((uint32_T)localDW->is_active_c12_THA_SM_Ref == 0U) {
    localDW->is_active_c12_THA_SM_Ref = 1U;
    localDW->is_c12_THA_SM_Ref = THA_SM_Ref_IN_Idle;
    *rty_switchOut = false;
  } else if ((uint32_T)localDW->is_c12_THA_SM_Ref == THA_SM_Ref_IN_Idle) {
    *rty_switchOut = false;
    if (*rtu_Trigger) {
      localDW->is_c12_THA_SM_Ref = THA_SM_Ref_IN_Standby;
      localDW->temporalCounter_i1 = 0U;
      *rty_switchOut = true;
    }
  } else {
    /* case IN_Standby: */
    *rty_switchOut = true;
    if ((real32_T)(uint32_T)(int32_T)((int32_T)localDW->temporalCounter_i1 * 3) >=
        rtu_KeTHA_s_HmiFaultPopUpDur * 100.0F) {
      localDW->is_c12_THA_SM_Ref = THA_SM_Ref_IN_Idle;
      *rty_switchOut = false;
    }
  }

  /* End of Chart: '<S157>/Chart2' */
}

/* Function for Chart: '<S7>/THA_MainStateMachine' */
static void THA_SM_Ref_THA_Activ_Process(TeTHA_e_THAState *rty_IeTHA_e_THAState,
  TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo)
{
  if (MeTHA_b_AbortCndnFaulted || MeTHA_b_FidDisabled) {
    THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Fault;
    THA_SM_Ref_DW.temporalCounter_i1 = 0U;

    /* Chart: '<S7>/THA_MainStateMachine' */
    *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Faulted;
    *rty_IeTHA_e_THAState = TeTHA_e_THAState_Faulted;
  } else {
    switch (THA_SM_Ref_DW.is_THA_Activ_Process) {
     case THA_SM_Ref_IN_Completed:
      if ((THA_SM_Ref_B.MeTHA_e_ScreenRequestPrev ==
           TeTHA_e_ScreenRequest_THA_Default) ||
          (!THA_SM_Ref_B.MeTHA_b_IgnitionRunStart)) {
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Idle_cuxx;

        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
      } else {
        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Complete;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Complete;
      }
      break;

     case THA_SM_Ref_IN_Enabled:
      if (MeSVS_b_ImgDefeatReqSts || MeTHA_b_AbortCndnEnabled) {
        THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Fault;
        THA_SM_Ref_DW.temporalCounter_i1 = 0U;

        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Faulted;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Faulted;
      } else {
        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Enabled;
        if ((uint32_T)THA_SM_Ref_DW.is_Enabled == THA_SM_Ref_IN_Enabled_armw) {
          if (THA_SM_Ref_B.MeTHA_b_EnabledSelectionTrns) {
            THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_Enabled_Selection;

            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Enabled_Selection;
          } else {
            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Enabled;
          }
        } else {
          /* case IN_Enabled_Selection: */
          if (THA_SM_Ref_B.MeTHA_e_ScreenRequestPrev ==
              TeTHA_e_ScreenRequest_THA_CM_Msg8) {
            THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_THA_Activ_Process =
              THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Idle_cuxx;

            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
            *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
          } else if (THA_SM_Ref_B.LogicalOperator_efqh) {
            THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_Engaged_Main;

            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_IeTHA_e_THAState = TeTHA_e_THAState_Engaged;
            THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_Engaged_ejok;

            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged;
          } else {
            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Enabled_Selection;
          }
        }
      }
      break;

     default:
      /* case IN_Engaged_Main: */
      if (THA_SM_Ref_B.MeTHA_e_ScreenRequestPrev ==
          TeTHA_e_ScreenRequest_THA_CM_Msg8) {
        THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Idle_cuxx;

        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
      } else if (THA_SM_Ref_B.MeTHA_b_CompleteTrns) {
        THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_Completed;

        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Complete;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Complete;
      } else if (MeSVS_b_ImgDefeatReqSts ||
                 THA_SM_Ref_B.MeTHA_b_AbortStrTrqSpdLimReq ||
                 MeTHA_b_AbortCndnEngaged) {
        THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Fault;
        THA_SM_Ref_DW.temporalCounter_i1 = 0U;

        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Faulted;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Faulted;
      } else {
        /* Chart: '<S7>/THA_MainStateMachine' */
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Engaged;
        if (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
            TeVBII_e_GearEngagedForDsply_P) {
          THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_Engaged_Suppression;
        } else {
          switch (THA_SM_Ref_DW.is_Engaged_Main) {
           case THA_SM_Ref_IN_Engaged_ejok:
            if (THA_SM_Ref_B.MeTHA_b_EngagedDeltaTrns) {
              THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_Engaged_Delta;

              /* Chart: '<S7>/THA_MainStateMachine' */
              *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged_Delta;
            } else {
              /* Chart: '<S7>/THA_MainStateMachine' */
              *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged;
            }
            break;

           case THA_SM_Ref_IN_Engaged_Delta:
            if (THA_SM_Ref_B.MeTHA_b_EngagedInquiryTrns) {
              THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_Engaged_Inquiry;

              /* Chart: '<S7>/THA_MainStateMachine' */
              *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged_Inquiry;
            } else {
              /* Chart: '<S7>/THA_MainStateMachine' */
              *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged_Delta;
            }
            break;

           case THA_SM_Ref_IN_Engaged_Inquiry:
            /* Chart: '<S7>/THA_MainStateMachine' */
            *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged_Inquiry;
            break;

           default:
            /* Chart: '<S7>/THA_MainStateMachine' */
            /* case IN_Engaged_Suppression: */
            if ((THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                 TeVBII_e_GearEngagedForDsply_R) && (*rty_MeTHA_e_THAStateInfo ==
                 TeTHA_e_THAStateInfo_Engaged_Inquiry)) {
              THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_Engaged_Inquiry;
              *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Engaged_Inquiry;
            } else {
              if (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                  TeVBII_e_GearEngagedForDsply_R) {
                THA_SM_Ref_DW.is_Engaged_Main =
                  THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
                THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_Enabled;
                *rty_IeTHA_e_THAState = TeTHA_e_THAState_Enabled;
                THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_Enabled_Selection;
                *rty_MeTHA_e_THAStateInfo =
                  TeTHA_e_THAStateInfo_Enabled_Selection;
              }
            }
            break;
          }
        }
      }
      break;
    }
  }
}

/* Function for Chart: '<S6>/THA_HMI_Logic_Flow' */
static void THA_SM_Ref_exit_internal_Enabled(void)
{
  switch (THA_SM_Ref_DW.is_Enabled_dfuo) {
   case THA_SM_Ref_IN_CplrSelCnfrm:
    if ((uint32_T)THA_SM_Ref_DW.is_CplrSelCnfrm ==
        THA_SM_Ref_IN_CoulperDetection) {
      THA_SM_Ref_DW.cplr_det_wait = 0.0F;
      THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    } else {
      THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    }

    THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    break;

   case THA_SM_Ref_IN_HitchDetection:
    THA_SM_Ref_DW.hitch_det_wait = 0.0F;
    THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    break;

   default:
    THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    break;
  }
}

/* Function for Chart: '<S6>/THA_HMI_Logic_Flow' */
static void THA_SM_Ref_exit_internal_THA_Normal(void)
{
  if ((uint32_T)THA_SM_Ref_DW.is_THA_Normal == THA_SM_Ref_IN_Enabled) {
    THA_SM_Ref_exit_internal_Enabled();
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  } else {
    THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  }
}

/* Function for Chart: '<S6>/THA_HMI_Logic_Flow' */
static void THA_SM_Ref_Enabled(TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm)
{
  int32_T tmp;
  if (*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Idle) {
    THA_SM_Ref_exit_internal_Enabled();
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
    THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
    *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
    *rty_MeTHA_b_UsrHitchCnfm = false;
    *rty_MeTHA_b_UsrCplrSelCnfm = false;
  } else if ((THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered ==
              TeTHA_e_CplrDetctStatus_Not_Detected) ||
             (THA_SM_Ref_DW.cplr_det_wait >= KeTHA_s_HitchCplrDetctTimeout)) {
    THA_SM_Ref_exit_internal_Enabled();
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_CoulperNotPresent;
    THA_SM_Ref_DW.temporalCounter_i1_gafy = 0U;
    *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg8;
  } else {
    switch (THA_SM_Ref_DW.is_Enabled_dfuo) {
     case THA_SM_Ref_IN_AngleTooSteep:
      /* Constant: '<S6>/Constant3' */
      if ((real32_T)(uint32_T)(int32_T)((int32_T)
           THA_SM_Ref_DW.temporalCounter_i1_gafy * 3) >=
          KeTHA_s_HmiFaultPopUpDur * 100.0F) {
        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NotInZone;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;
      } else {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_ERR_Msg1;

        /* Coupler Angle too Severe. Please Readjust */
      }

      /* End of Constant: '<S6>/Constant3' */
      break;

     case THA_SM_Ref_IN_CplrSelCnfrm:
      if (THA_SM_Ref_B.IeVBII_e_VehStandStillSts ==
          TeVBII_e_VehStandStillSts_False) {
        *rty_MeTHA_b_UsrCplrSelCnfm = false;
        if ((uint32_T)THA_SM_Ref_DW.is_CplrSelCnfrm ==
            THA_SM_Ref_IN_CoulperDetection) {
          THA_SM_Ref_DW.cplr_det_wait = 0.0F;
          THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        } else {
          THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        }

        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NotInZone;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;
      } else {
        switch (THA_SM_Ref_DW.is_CplrSelCnfrm) {
         case THA_SM_Ref_IN_CoulperDetection:
          if (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered < 0) {
            if (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered <= MIN_int32_T)
            {
              tmp = MAX_int32_T;
            } else {
              tmp = -THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered;
            }
          } else {
            tmp = THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered;
          }

          if (KeTHA_b_EnblEngageRejectReq &&
              (THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered ==
               TeTHA_e_CplrDetctStatus_Detected) &&
              ((THA_SM_Ref_B.MeTHA_b_CplrAngFound && (THA_SM_Ref_B.Abs >
                 KeTHA_deg_VehTrlrInitAngMax) && (tmp <
                 KeTHA_px_EngageRejLatpxdiff)) || MeSVS_b_THAAbortReq)) {
            *rty_MeTHA_b_UsrCplrSelCnfm = false;
            THA_SM_Ref_DW.cplr_det_wait = 0.0F;
            THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_AngleTooSteep;
            THA_SM_Ref_DW.temporalCounter_i1_gafy = 0U;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_ERR_Msg1;
          } else if ((THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered ==
                      TeTHA_e_CplrDetctStatus_Detected) &&
                     (THA_SM_Ref_B.MeTHA_b_CplrAngFound ||
                      (THA_SM_Ref_DW.cplr_det_wait >=
                       KeTHA_s_CplrAngFoundTimeout))) {
            THA_SM_Ref_DW.cplr_det_wait = 0.0F;
            THA_SM_Ref_DW.is_CplrSelCnfrm =
              THA_SM_Ref_IN_CouplerHeightConfirmation;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg4;
          } else {
            /* Constant: '<S6>/Constant1' */
            THA_SM_Ref_DW.cplr_det_wait += KeTHA_s_ThaSampleTime;

            /* Waiting for THA Detection to send
               Coupler detection status */
          }
          break;

         case THA_SM_Ref_IN_CoulperLocSelected:
          if (MeSVS_b_THAAbortReq) {
            THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NotInZone;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;
          } else {
            if (MeSVS_b_THAScrTchSts) {
              *rty_MeTHA_b_UsrCplrSelCnfm = true;
              THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_CoulperDetection;

              /* Constant: '<S6>/Constant1' */
              THA_SM_Ref_DW.cplr_det_wait = KeTHA_s_ThaSampleTime;
            }
          }
          break;

         default:
          /* case IN_CouplerHeightConfirmation: */
          if (MeSVS_b_IsConfirmBtnPrsd && (MeSVS_e_THAScrResp ==
               TeTHA_e_ScreenRequest_THA_TCS_Msg4) && (*rty_MeTHA_e_THAStateInfo
               == TeTHA_e_THAStateInfo_Engaged)) {
            THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
            THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Engaged;
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_RemHandandReverse;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_SM_Msg1;
          } else {
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg4;

            /* Confirm coupler has clearance over hitch */
          }
          break;
        }
      }
      break;

     case THA_SM_Ref_IN_HitchDetection:
      if (THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered ==
          TeTHA_e_HitchDetctStatus_Detected) {
        THA_SM_Ref_DW.hitch_det_wait = 0.0F;
        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NotInZone;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;
      } else if ((THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered ==
                  TeTHA_e_HitchDetctStatus_Not_Detected) ||
                 (THA_SM_Ref_DW.hitch_det_wait >= KeTHA_s_HitchCplrDetctTimeout))
      {
        THA_SM_Ref_DW.hitch_det_wait = 0.0F;
        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_HitchNotPresent;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_ERR_Msg2;
      } else {
        /* Constant: '<S6>/Constant1' */
        THA_SM_Ref_DW.hitch_det_wait += KeTHA_s_ThaSampleTime;

        /* Waiting for THA Detection to send
           Hitch detection status */
      }
      break;

     case THA_SM_Ref_IN_HitchNotPresent:
      if (MeSVS_b_IsConfirmBtnPrsd) {
        *rty_MeTHA_b_UsrHitchCnfm = true;
        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NotInZone;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;
      } else {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_ERR_Msg2;

        /* Hitch not detected.
           Press CONFIRM to continue or X to exit */
      }
      break;

     default:
      /* case IN_NotInZone: */
      if (MeSVS_e_THAScrResp == TeTHA_e_ScreenRequest_THA_TCS_Msg1) {
        THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_CplrSelCnfrm;
        THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_CoulperLocSelected;

        /* MeTHA_e_ScreenRequest= TeTHA_e_ScreenRequest.THA_TCS_Msg2;
           Press the location of the coupler */
      } else {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg1;

        /* Back up slowly until coupler enters zone.
           Press the location of the coupler */
      }
      break;
    }
  }
}

/* Function for Chart: '<S6>/THA_HMI_Logic_Flow' */
static void THA_SM_Ref_THA_Normal(TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
  TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
  *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm, boolean_T
  *rty_MeTHA_b_UsrInputTimeOut)
{
  /* Chart: '<S6>/THA_HMI_Logic_Flow' incorporates:
   *  Constant: '<S6>/Constant1'
   *  Constant: '<S6>/Constant3'
   */
  if ((*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Faulted) &&
      (!MeSVS_b_ImgDefeatReqSts)) {
    THA_SM_Ref_exit_internal_THA_Normal();
    THA_SM_Ref_DW.is_c1_THA_SM_Ref = THA_SM_Ref_IN_THA_Fault;
    THA_SM_Ref_DW.temporalCounter_i1_gafy = 0U;
    if (MeTHA_b_AbortCndnFaulted || MeTHA_b_FidCamCalAbort ||
        MeTHA_b_FidDLDAbort || THA_SM_Ref_B.MeTHA_b_AbortStrTrqSpdLimReq) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg1;

      /* Trailer Hitch Assist Unavailable:
         Service Required */
    } else if (THA_SM_Ref_B.IeVBII_b_TrnkStatus) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg3;

      /* Trailer Hitch Assist Unavailable:
         Rear tailgate open. */
    } else if ((THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                TeVBII_e_GearEngagedForDsply_R) && ((int32_T)
                THA_SM_Ref_B.IeVBII_e_EpsTHADrvTrqOvrd != 0)) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg4;

      /* Trailer Hitch Assist Unavailable:
         Driver steering override. */
    } else if (*rty_MeTHA_b_UsrInputTimeOut) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg5;

      /* Trailer Hitch Assist Unavailable:
         System timeout. */
    } else if (MeTHA_b_OverSpeedAbort) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg6;

      /* Trailer Hitch Assist Unavailable:
         Speed override. */
    } else if (THA_SM_Ref_B.IeVBII_b_DrvDoorSts &&
               (THA_SM_Ref_B.IeVBII_e_VehStandStillSts ==
                TeVBII_e_VehStandStillSts_False)) {
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg7;

      /* Trailer Hitch Assist Unavailable:
         Driver door open. */
    } else {
      if (MeTHA_b_FeatureOverride) {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg9;

        /* Trailer Hitch Assist Unavailable:
           Driver assist feature active. */
      }
    }
  } else if (MeSVS_b_ImgDefeatReqSts) {
    THA_SM_Ref_exit_internal_THA_Normal();
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
    THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
    *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
    *rty_MeTHA_b_UsrHitchCnfm = false;
    *rty_MeTHA_b_UsrCplrSelCnfm = false;
  } else {
    switch (THA_SM_Ref_DW.is_THA_Normal) {
     case THA_SM_Ref_IN_CoulperNotPresent:
      if ((real32_T)(uint32_T)(int32_T)((int32_T)
           THA_SM_Ref_DW.temporalCounter_i1_gafy * 3) >=
          KeTHA_s_HmiFaultPopUpDur * 100.0F) {
        THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
        THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
        *rty_MeTHA_b_UsrHitchCnfm = false;
        *rty_MeTHA_b_UsrCplrSelCnfm = false;
      } else {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg8;

        /* Trailer Hitch Assist Unavailable: No coupler detected */
      }
      break;

     case THA_SM_Ref_IN_Enabled:
      THA_SM_Ref_Enabled(rty_MeTHA_e_THAStateInfo, rty_MeTHA_e_ScreenRequest,
                         rty_MeTHA_b_UsrHitchCnfm, rty_MeTHA_b_UsrCplrSelCnfm);
      break;

     case THA_SM_Ref_IN_Engaged:
      if (*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Complete) {
        THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_THA_Complete;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg3;
      } else if ((THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered !=
                  TeTHA_e_CplrDetctStatus_Detected) &&
                 ((*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Engaged) ||
                  (*rty_MeTHA_e_THAStateInfo ==
                   TeTHA_e_THAStateInfo_Engaged_Delta))) {
        THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
        THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_CoulperNotPresent;
        THA_SM_Ref_DW.temporalCounter_i1_gafy = 0U;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_CM_Msg8;
      } else if (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                 TeVBII_e_GearEngagedForDsply_P) {
        THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_EngagedSuppression;
      } else {
        switch (THA_SM_Ref_DW.is_Engaged) {
         case THA_SM_Ref_IN_CnfrmComManuver:
          if (!THA_SM_Ref_B.RelationalOperator) {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_ReachSelPt;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg1;
          } else {
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg2;

            /* Trailer Coupler Reached.Press Confirm to continue. */
          }
          break;

         case THA_SM_Ref_IN_DisplayDistCount:
          if (*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Engaged_Inquiry)
          {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_ReachSelPt;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg1;
          } else {
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_SM_Msg2;

            /* Keep speed at or below 5 mph */
          }
          break;

         case THA_SM_Ref_IN_EngagedSuppression:
          if ((THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_R) && (*rty_MeTHA_e_THAStateInfo ==
               TeTHA_e_THAStateInfo_Engaged_Inquiry)) {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_ReachSelPt;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg1;
          } else {
            if (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                TeVBII_e_GearEngagedForDsply_R) {
              THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
              THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Enabled;
              THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_CplrSelCnfrm;
              THA_SM_Ref_DW.is_CplrSelCnfrm =
                THA_SM_Ref_IN_CouplerHeightConfirmation;
              *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_TCS_Msg4;
            }
          }
          break;

         case THA_SM_Ref_IN_ReachSelPt:
          if (THA_SM_Ref_B.RelationalOperator) {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_CnfrmComManuver;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg2;
          } else {
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg1;

            /* Fully apply brakes when aligned. */
          }
          break;

         default:
          /* case IN_RemHandandReverse: */
          if (*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Engaged_Inquiry)
          {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_ReachSelPt;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg1;
          } else if (THA_SM_Ref_B.IeVBII_e_VehStandStillSts ==
                     TeVBII_e_VehStandStillSts_False) {
            THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_DisplayDistCount;
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_SM_Msg2;
          } else {
            *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_SM_Msg1;

            /* Remove hands from wheel and move backwards */
          }
          break;
        }
      }
      break;

     case THA_SM_Ref_IN_Init:
      if ((uint32_T)THA_SM_Ref_DW.is_Init == THA_SM_Ref_IN_Active) {
        if (*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Enabled) {
          THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
          THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Enabled;
          THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_HitchDetection;
          THA_SM_Ref_DW.hitch_det_wait = KeTHA_s_ThaSampleTime;
        } else if ((*rty_MeTHA_e_THAStateInfo != TeTHA_e_THAStateInfo_Idle) || (
                    !MeTHA_b_ActivTrns) ||
                   (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply !=
                    TeVBII_e_GearEngagedForDsply_R)) {
          THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
          *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
          *rty_MeTHA_b_UsrHitchCnfm = false;
          *rty_MeTHA_b_UsrCplrSelCnfm = false;
        } else {
          *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Enable;

          /* THA Soft button Enable */
        }
      } else {
        /* case IN_Idle: */
        if ((*rty_MeTHA_e_THAStateInfo == TeTHA_e_THAStateInfo_Idle) &&
            MeTHA_b_ActivTrns && (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
             TeVBII_e_GearEngagedForDsply_R)) {
          THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Active;
          *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Enable;
        } else {
          *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
          *rty_MeTHA_b_UsrHitchCnfm = false;
          *rty_MeTHA_b_UsrCplrSelCnfm = false;

          /* THA Soft button Disable */
        }
      }
      break;

     default:
      /* case IN_THA_Complete: */
      if (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply !=
          TeVBII_e_GearEngagedForDsply_R) {
        THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
        THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
        *rty_MeTHA_b_UsrHitchCnfm = false;
        *rty_MeTHA_b_UsrCplrSelCnfm = false;
      } else {
        *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_EOM_Msg3;

        /* Shift to Park to Secure Vehicle. */
      }
      break;
    }
  }

  /* End of Chart: '<S6>/THA_HMI_Logic_Flow' */
}

/* System initialize for referenced model: 'THA_SM_Ref' */
void THA_SM_Ref_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S16>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_hgbb = 0U;

  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_co0c = TeTHA_e_THAStateInfo_Off;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_jxgs = 0;

  /* InitializeConditions for UnitDelay: '<S90>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_fbjp = false;

  /* InitializeConditions for UnitDelay: '<S96>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S109>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_d5cr = false;

  /* InitializeConditions for UnitDelay: '<S127>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_kgyy = false;

  /* InitializeConditions for UnitDelay: '<S126>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_bz1l = 0.0F;

  /* InitializeConditions for UnitDelay: '<S116>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_ipup = 0.0F;

  /* InitializeConditions for UnitDelay: '<S117>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_hyrp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_cn3d = TeVBII_e_GearEngagedForDsply_Initialize;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_kwqb = TeVBII_e_TchScrSts_TCH_NOT_PSD;

  /* InitializeConditions for UnitDelay: '<S36>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_fkls = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_gjgb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S44>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_dasz = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_lybn = TeTHA_e_ScreenRequest_THA_Default;

  /* InitializeConditions for UnitDelay: '<S16>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_fw4h = false;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S150>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_mxty = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_ggez = TeTHA_e_THAStateInfo_Off;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_coxe = 0;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_gih2 = false;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_bhgc = 0;

  /* InitializeConditions for UnitDelay: '<S43>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_nlty = 0.0F;

  /* SystemInitialize for Chart: '<S99>/CplrDetStsHyst' */
  THA_SM_Ref_DW.local_status_nrep = TeTHA_e_CplrDetctStatus_Not_Valid;
  THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered = TeTHA_e_CplrDetctStatus_Not_Valid;

  /* SystemInitialize for Chart: '<S157>/Chart2' */
  THA_SM_Ref_Chart2_Init(&THA_SM_Ref_B.switchOut_efwl);

  /* SystemInitialize for Chart: '<S158>/Chart2' */
  THA_SM_Ref_Chart2_Init(&THA_SM_Ref_B.switchOut_lh0v);

  /* SystemInitialize for Chart: '<S159>/Chart2' */
  THA_SM_Ref_Chart2_Init(&THA_SM_Ref_B.switchOut);

  /* SystemInitialize for Chart: '<S99>/HitchDetStsHyst' */
  THA_SM_Ref_DW.local_status = TeTHA_e_HitchDetctStatus_Not_Valid;
  THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered = TeTHA_e_HitchDetctStatus_Not_Valid;
}

/* System reset for referenced model: 'THA_SM_Ref' */
void THA_SM_Ref_Reset(TeTHA_e_THAState *rty_IeTHA_e_THAState,
                      TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
                      TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest,
                      boolean_T *rty_MeTHA_b_UsrHitchCnfm, boolean_T
                      *rty_MeTHA_b_UsrCplrSelCnfm)
{
  /* InitializeConditions for UnitDelay: '<S16>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_hgbb = 0U;

  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_co0c = TeTHA_e_THAStateInfo_Off;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_jxgs = 0;

  /* InitializeConditions for UnitDelay: '<S90>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_fbjp = false;

  /* InitializeConditions for UnitDelay: '<S96>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S109>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_d5cr = false;

  /* InitializeConditions for UnitDelay: '<S127>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_kgyy = false;

  /* InitializeConditions for UnitDelay: '<S126>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_bz1l = 0.0F;

  /* InitializeConditions for UnitDelay: '<S116>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_ipup = 0.0F;

  /* InitializeConditions for UnitDelay: '<S117>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_hyrp = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_cn3d = TeVBII_e_GearEngagedForDsply_Initialize;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_kwqb = TeVBII_e_TchScrSts_TCH_NOT_PSD;

  /* InitializeConditions for UnitDelay: '<S36>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_fkls = 0.0F;

  /* InitializeConditions for UnitDelay: '<S22>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_gjgb = 0.0F;

  /* InitializeConditions for UnitDelay: '<S44>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_dasz = 0.0F;

  /* InitializeConditions for UnitDelay: '<S1>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_lybn = TeTHA_e_ScreenRequest_THA_Default;

  /* InitializeConditions for UnitDelay: '<S16>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_fw4h = false;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE = 0;

  /* InitializeConditions for UnitDelay: '<S99>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE = 0.0F;

  /* InitializeConditions for UnitDelay: '<S150>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_mxty = 0.0F;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_ggez = TeTHA_e_THAStateInfo_Off;

  /* InitializeConditions for UnitDelay: '<S9>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_coxe = 0;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_gih2 = false;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_bhgc = 0;

  /* InitializeConditions for UnitDelay: '<S43>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_nlty = 0.0F;

  /* SystemReset for Chart: '<S99>/CplrDetStsHyst' */
  THA_SM_Ref_DW.is_active_c3_THA_SM_Ref = 0U;
  THA_SM_Ref_DW.is_c3_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.time_count_kisl = 0.0F;
  THA_SM_Ref_DW.local_status_nrep = TeTHA_e_CplrDetctStatus_Not_Valid;
  THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered = TeTHA_e_CplrDetctStatus_Not_Valid;

  /* SystemReset for Chart: '<S157>/Chart2' */
  THA_SM_Ref_Chart2_Reset(&THA_SM_Ref_B.switchOut_efwl,
    &THA_SM_Ref_DW.sf_Chart2_gkm0);

  /* SystemReset for Chart: '<S158>/Chart2' */
  THA_SM_Ref_Chart2_Reset(&THA_SM_Ref_B.switchOut_lh0v,
    &THA_SM_Ref_DW.sf_Chart2_kfbv);

  /* SystemReset for Chart: '<S159>/Chart2' */
  THA_SM_Ref_Chart2_Reset(&THA_SM_Ref_B.switchOut, &THA_SM_Ref_DW.sf_Chart2_g3d0);

  /* SystemReset for Chart: '<S35>/Chart2' */
  THA_SM_Ref_DW.temporalCounter_i1_bsnb = 0U;
  THA_SM_Ref_DW.is_active_c9_THA_SM_Ref = 0U;
  THA_SM_Ref_DW.is_c9_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_B.switchOut_gy5o = false;

  /* SystemReset for Chart: '<S7>/THA_MainStateMachine' */
  THA_SM_Ref_DW.temporalCounter_i1 = 0U;
  THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_Engaged_Main = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_active_c5_THA_SM_Ref = 0U;
  THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
  *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;

  /* SystemReset for Chart: '<S74>/LateralOffsetCheck' */
  THA_SM_Ref_B.MeTHA_b_EngageRejectReq_al0i = false;

  /* SystemReset for Chart: '<S99>/HitchDetStsHyst' */
  THA_SM_Ref_DW.is_active_c2_THA_SM_Ref = 0U;
  THA_SM_Ref_DW.is_c2_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.time_count = 0.0F;
  THA_SM_Ref_DW.local_status = TeTHA_e_HitchDetctStatus_Not_Valid;
  THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered = TeTHA_e_HitchDetctStatus_Not_Valid;

  /* SystemReset for Chart: '<S6>/THA_HMI_Logic_Flow' */
  THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_Enabled_dfuo = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.temporalCounter_i1_gafy = 0U;
  THA_SM_Ref_DW.is_CplrSelCnfrm = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_Engaged = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.is_active_c1_THA_SM_Ref = 0U;
  THA_SM_Ref_DW.is_c1_THA_SM_Ref = THA_SM_Ref_IN_NO_ACTIVE_CHILD_nh3e;
  THA_SM_Ref_DW.cplr_det_wait = 0.0F;
  THA_SM_Ref_DW.hitch_det_wait = 0.0F;
  *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
  *rty_MeTHA_b_UsrHitchCnfm = false;
  *rty_MeTHA_b_UsrCplrSelCnfm = false;
}

/* Start for referenced model: 'THA_SM_Ref' */
void THA_SM_Ref_Start(boolean_T *rty_IeTHA_b_ChimeActvLhr, boolean_T
                      *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeRepRateSts
                      *rty_IeTHA_e_PamChimeRepRateSts)
{
  /* Start for Constant: '<S3>/Constant2' */
  *rty_IeTHA_b_ChimeActvLhr = false;

  /* Start for Constant: '<S3>/Constant3' */
  *rty_IeTHA_b_ChimeActvRhr = false;

  /* Start for Constant: '<S12>/Constant' */
  *rty_IeTHA_e_PamChimeRepRateSts = TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz;
}

/* Output and update for referenced model: 'THA_SM_Ref' */
void THA_SM_Ref(const TbTHASmVc_InputFromThaDet_t *rtu_MbTHA_ThaDetOutData,
                const TbTHASmVc_InputFromHmiSvs_t *rtu_MbTHA_HmiSvsOutData,
                const TbTHASmVc_InputFromVehInp_t *rtu_MbTHA_VehInpOutData,
                const TbTHASmVc_InputFromProxiMgr_t *rtu_MbTHA_ProxiMgrOutData,
                const TbTHASmVc_InputFromDegMgr_t *rtu_MbTHA_DegradMgrOutData,
                const TbTHASmVc_InputFromApSmPa_t *rtu_MbTHA_ApSmOutData, const
                TbTHASmVc_InputFromTRSC_t *rtu_MbTHA_TrscSmVcOutData, const
                TbTHASmVc_InputVrntTunParam_t *rtu_MbTHA_VrntTunParamOutData,
                const TeTHA_e_THARmpUpDwnSpd *rtu_IeTHA_e_THARmpUpDwnSpdPrev,
                const TeTHA_e_THASteerTrqReq *rtu_IeTHA_e_THASteerTrqReqPrev,
                TeTHA_e_THAState *rty_IeTHA_e_THAState, TeTHA_e_THASpdLimReq
                *rty_IeTHA_e_THASpdLimReq, TeTHA_e_PamVol *rty_IeTHA_e_PamVol,
                boolean_T *rty_IeTHA_b_ChimeActvLhf, boolean_T
                *rty_IeTHA_b_ChimeActvRhf, boolean_T *rty_IeTHA_b_ChimeActvLhr,
                boolean_T *rty_IeTHA_b_ChimeActvRhr, TeTHA_e_PamChimeTyp
                *rty_IeTHA_e_PamChimeTyp, TeTHA_e_PamChimeRepRateSts
                *rty_IeTHA_e_PamChimeRepRateSts, TeTHA_e_THASteerTrqReq
                *rty_MeTHA_e_THASteerTrqReq, TeTHA_e_EPBReq *rty_IeTHA_e_EPBReq,
                TeTHA_e_THAStateInfo *rty_MeTHA_e_THAStateInfo,
                TeTHA_e_ScreenRequest *rty_MeTHA_e_ScreenRequest, boolean_T
                *rty_MeTHA_b_EnblRearParkAsstTrg, TeTHA_e_RearBrkSupprInfo
                *rty_MeTHA_e_RearBrkSupprInfo, boolean_T
                *rty_MeTHA_b_UsrHitchCnfm, boolean_T *rty_MeTHA_b_UsrCplrSelCnfm,
                boolean_T *rty_MeTHA_b_TrlrCplrStatus, boolean_T
                *rty_MeTHA_b_THAAbortStatus, boolean_T
                *rty_MeTHA_b_UsrInputTimeOut, boolean_T *rty_MeTHA_b_ViewZoomSts,
                boolean_T *rty_MeTHA_b_CamOccluLoLi, int32_T
                *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt)
{
  real32_T Sum_jetc_tmp;
  boolean_T RelationalOperator2_hq3h_tmp;

  /* UnitDelay: '<S16>/UnitDelay' */
  THA_SM_Ref_B.UnitDelay = THA_SM_Ref_DW.UnitDelay_DSTATE_hgbb;

  /* SignalConversion: '<S2>/SignalCopy5' */
  MeSVS_b_THASftBtnPrsdStsToTHA =
    rtu_MbTHA_HmiSvsOutData->MeSVS_b_THASftBtnPrsdStsToTHA;

  /* SignalConversion: '<S2>/SignalCopy8' */
  MeSVS_b_ImgDefeatReqSts = rtu_MbTHA_HmiSvsOutData->MeSVS_b_ImgDefeatReqSts;

  /* SignalConversion: '<S2>/SignalCopy6' */
  MeSVS_b_IsConfirmBtnPrsd = rtu_MbTHA_HmiSvsOutData->MeSVS_b_IsConfirmBtnPrsd;

  /* UnitDelay: '<S1>/UnitDelay2' */
  THA_SM_Ref_B.UnitDelay1_kl5n = THA_SM_Ref_DW.UnitDelay2_DSTATE_co0c;

  /* RelationalOperator: '<S99>/RelationalOperator5' incorporates:
   *  Constant: '<S105>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator5 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Enabled_Selection);

  /* RelationalOperator: '<S99>/RelationalOperator1' incorporates:
   *  Constant: '<S101>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged);

  /* RelationalOperator: '<S99>/RelationalOperator2' incorporates:
   *  Constant: '<S102>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Delta);

  /* RelationalOperator: '<S99>/RelationalOperator3' incorporates:
   *  Constant: '<S103>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* Logic: '<S99>/Logical Operator' */
  THA_SM_Ref_B.LogicalOperator = (THA_SM_Ref_B.RelationalOperator3_lwkl ||
    THA_SM_Ref_B.LogicalOperator7 || THA_SM_Ref_B.RelationalOperator1_ibmm);

  /* Switch: '<S99>/Switch' incorporates:
   *  Constant: '<S99>/Constant16'
   *  Switch: '<S99>/Switch2'
   */
  if (THA_SM_Ref_B.RelationalOperator5) {
    THA_SM_Ref_B.Switch_kz4h = KeTHA_s_CplrDetStsBufEnabled;
  } else {
    if (THA_SM_Ref_B.LogicalOperator) {
      /* Switch: '<S99>/Switch2' incorporates:
       *  Constant: '<S99>/Constant1'
       */
      THA_SM_Ref_B.Switch2 = KeTHA_s_CplrDetStsBufEngaged;
    } else {
      /* Switch: '<S99>/Switch2' incorporates:
       *  Constant: '<S99>/Constant5'
       */
      THA_SM_Ref_B.Switch2 = 0.0F;
    }

    THA_SM_Ref_B.Switch_kz4h = THA_SM_Ref_B.Switch2;
  }

  /* End of Switch: '<S99>/Switch' */

  /* Saturate: '<S99>/Saturation' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  if (KeTHA_s_ThaSampleTime > 0.1F) {
    THA_SM_Ref_B.Saturation = 0.1F;
  } else if (KeTHA_s_ThaSampleTime < 0.0001F) {
    THA_SM_Ref_B.Saturation = 0.0001F;
  } else {
    THA_SM_Ref_B.Saturation = KeTHA_s_ThaSampleTime;
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* SignalConversion: '<S2>/SignalCopy1' */
  MeTHA_e_CplrDetctStatus = rtu_MbTHA_ThaDetOutData->MeTHA_e_CplrDetctStatus;

  /* Chart: '<S99>/CplrDetStsHyst' */
  if ((uint32_T)THA_SM_Ref_DW.is_active_c3_THA_SM_Ref == 0U) {
    THA_SM_Ref_DW.is_active_c3_THA_SM_Ref = 1U;
    THA_SM_Ref_DW.is_c3_THA_SM_Ref = THA_SM_Ref_IN_init_state;
    THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered = MeTHA_e_CplrDetctStatus;
    THA_SM_Ref_DW.local_status_nrep = MeTHA_e_CplrDetctStatus;
  } else if ((uint32_T)THA_SM_Ref_DW.is_c3_THA_SM_Ref ==
             THA_SM_Ref_IN_counter_state) {
    if ((THA_SM_Ref_DW.time_count_kisl >= THA_SM_Ref_B.Switch_kz4h) ||
        (MeTHA_e_CplrDetctStatus != TeTHA_e_CplrDetctStatus_Not_Detected)) {
      THA_SM_Ref_DW.is_c3_THA_SM_Ref = THA_SM_Ref_IN_init_state;
      THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered = MeTHA_e_CplrDetctStatus;
      THA_SM_Ref_DW.local_status_nrep = MeTHA_e_CplrDetctStatus;
    } else {
      THA_SM_Ref_DW.time_count_kisl += THA_SM_Ref_B.Saturation;
    }
  } else {
    /* case IN_init_state: */
    if (MeTHA_e_CplrDetctStatus == TeTHA_e_CplrDetctStatus_Not_Detected) {
      THA_SM_Ref_DW.is_c3_THA_SM_Ref = THA_SM_Ref_IN_counter_state;
      THA_SM_Ref_DW.local_status_nrep = MeTHA_e_CplrDetctStatus;
      THA_SM_Ref_DW.time_count_kisl = THA_SM_Ref_B.Saturation;
    } else {
      if (MeTHA_e_CplrDetctStatus != THA_SM_Ref_DW.local_status_nrep) {
        THA_SM_Ref_DW.is_c3_THA_SM_Ref = THA_SM_Ref_IN_init_state;
        THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered = MeTHA_e_CplrDetctStatus;
        THA_SM_Ref_DW.local_status_nrep = MeTHA_e_CplrDetctStatus;
      }
    }
  }

  /* End of Chart: '<S99>/CplrDetStsHyst' */

  /* RelationalOperator: '<S7>/Relational Operator' incorporates:
   *  Constant: '<S7>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm =
    (THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered == TeTHA_e_CplrDetctStatus_Detected);

  /* Logic: '<S7>/Logical Operator' */
  THA_SM_Ref_B.LogicalOperator_efqh = (MeSVS_b_IsConfirmBtnPrsd &&
    THA_SM_Ref_B.RelationalOperator1_ibmm);

  /* SignalConversion: '<S2>/SignalCopy46' */
  THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply =
    rtu_MbTHA_VehInpOutData->IeVBII_e_GearEngagedForDsply;

  /* Chart: '<S157>/Chart2' incorporates:
   *  Constant: '<S157>/Constant2'
   */
  THA_SM_Ref_Chart2(&rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidDisabled,
                    KeTHA_s_HmiFaultPopUpDur, &THA_SM_Ref_B.switchOut_efwl,
                    &THA_SM_Ref_DW.sf_Chart2_gkm0);

  /* Switch: '<S157>/Switch' */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.switchOut_efwl ||
    rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidDisabled);

  /* SignalConversion: '<S2>/SignalCopy49' */
  MeTHA_b_FidDisabled = THA_SM_Ref_B.RelationalOperator1_ibmm;

  /* Chart: '<S158>/Chart2' incorporates:
   *  Constant: '<S158>/Constant2'
   */
  THA_SM_Ref_Chart2(&rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidCamCalAbort,
                    KeTHA_s_HmiFaultPopUpDur, &THA_SM_Ref_B.switchOut_lh0v,
                    &THA_SM_Ref_DW.sf_Chart2_kfbv);

  /* Switch: '<S158>/Switch' */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.switchOut_lh0v ||
    rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidCamCalAbort);

  /* SignalConversion: '<S2>/SignalCopy53' */
  MeTHA_b_FidCamCalAbort = THA_SM_Ref_B.RelationalOperator1_ibmm;

  /* SignalConversion: '<S2>/SignalCopy15' */
  THA_SM_Ref_B.IeVBII_e_CmdIgnSts = rtu_MbTHA_VehInpOutData->IeVBII_e_CmdIgnSts;

  /* RelationalOperator: '<S92>/RelationalOperator9' incorporates:
   *  Constant: '<S133>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S92>/RelationalOperator1' incorporates:
   *  Constant: '<S132>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_START);

  /* Logic: '<S92>/LogicalOperator' */
  THA_SM_Ref_B.MeTHA_b_IgnitionRunStart = (THA_SM_Ref_B.RelationalOperator1_ibmm
    || THA_SM_Ref_B.LogicalOperator7);

  /* Logic: '<S93>/Logical Operator1' */
  THA_SM_Ref_B.RelationalOperator1_ibmm = !MeTHA_b_FidDisabled;

  /* Logic: '<S93>/Logical Operator' */
  THA_SM_Ref_B.LogicalOperator7 = !MeTHA_b_FidCamCalAbort;

  /* SignalConversion: '<S2>/SignalCopy51' */
  MePRX_b_CanNod63 = rtu_MbTHA_ProxiMgrOutData->MePRX_b_CanNod63;

  /* SignalConversion: '<S2>/SignalCopy52' */
  MePRX_b_CanNod95 = rtu_MbTHA_ProxiMgrOutData->MePRX_b_CanNod95;

  /* Logic: '<S93>/LogicalOperator2' */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (MePRX_b_CanNod63 || MePRX_b_CanNod95);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S143>/Constant'
   *  RelationalOperator: '<S93>/RelationalOperator3'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.UnitDelay1_kl5n !=
    TeTHA_e_THAStateInfo_SNA);

  /* Logic: '<S93>/LogicalOperator3' */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.RelationalOperator1_ibmm
    && THA_SM_Ref_B.LogicalOperator7 && THA_SM_Ref_B.RelationalOperator3_lwkl &&
    THA_SM_Ref_B.LogicalOperator2_npvg);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S134>/Constant'
   *  RelationalOperator: '<S93>/RelationalOperator'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* SignalConversion: '<S2>/SignalCopy45' */
  THA_SM_Ref_B.IeVBII_e_VehStandStillSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_VehStandStillSts;

  /* RelationalOperator: '<S93>/RelationalOperator1' incorporates:
   *  Constant: '<S135>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_VehStandStillSts ==
    TeVBII_e_VehStandStillSts_True);

  /* SignalConversion: '<S2>/SignalCopy36' */
  THA_SM_Ref_B.IeVBII_b_DrvDoorSts =
    rtu_MbTHA_VehInpOutData->IeVBII_b_DriverDoorSts;

  /* Logic: '<S93>/LogicalOperator' */
  THA_SM_Ref_B.RelationalOperator3_lwkl = !THA_SM_Ref_B.IeVBII_b_DrvDoorSts;

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Logic: '<S93>/LogicalOperator4'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.LogicalOperator2_npvg &&
    THA_SM_Ref_B.LogicalOperator7 && THA_SM_Ref_B.RelationalOperator3_lwkl);

  /* SignalConversion: '<S2>/SignalCopy38' */
  THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp =
    rtu_MbTHA_VehInpOutData->IeVBII_e_BsmTHABrkResp;

  /* RelationalOperator: '<S93>/RelationalOperator9' incorporates:
   *  Constant: '<S139>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp ==
    TeVBII_e_BsmTHABrkResp_Off);

  /* SignalConversion: '<S2>/SignalCopy43' */
  THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp =
    rtu_MbTHA_VehInpOutData->IeVBII_e_EpsTHASteerTrqResp;

  /* RelationalOperator: '<S93>/RelationalOperator6' incorporates:
   *  Constant: '<S136>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl =
    (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp !=
     TeVBII_e_EpsTHASteerTrqResp_Temp_NA);

  /* RelationalOperator: '<S93>/RelationalOperator7' incorporates:
   *  Constant: '<S137>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp !=
    TeVBII_e_EpsTHASteerTrqResp_Perm_NA);

  /* RelationalOperator: '<S93>/RelationalOperator2' incorporates:
   *  Constant: '<S142>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp
    != TeVBII_e_EpsTHASteerTrqResp_SNA);

  /* Logic: '<S93>/LogicalOperator6' */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.LogicalOperator7 &&
    THA_SM_Ref_B.RelationalOperator3_lwkl && THA_SM_Ref_B.LogicalOperator4 &&
    THA_SM_Ref_B.LogicalOperator3_edxj);

  /* SignalConversion: '<S2>/SignalCopy42' */
  THA_SM_Ref_B.IeVBII_e_EcmTHAResp =
    rtu_MbTHA_VehInpOutData->IeVBII_e_EcmTHAResp;

  /* RelationalOperator: '<S93>/RelationalOperator8' incorporates:
   *  Constant: '<S138>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.IeVBII_e_EcmTHAResp ==
    TeVBII_e_EcmTHAResp_Off);

  /* SignalConversion: '<S2>/SignalCopy37' */
  THA_SM_Ref_B.IeVBII_b_TrnkStatus =
    rtu_MbTHA_VehInpOutData->IeVBII_b_TrnkStatus;

  /* Logic: '<S93>/LogicalOperator8' */
  THA_SM_Ref_B.LogicalOperator4 = !THA_SM_Ref_B.IeVBII_b_TrnkStatus;

  /* SignalConversion: '<S2>/SignalCopy17' */
  THA_SM_Ref_B.IeVBII_e_TrlrPrsntSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_TrlrPrsntSts;

  /* RelationalOperator: '<S93>/RelationalOperator11' incorporates:
   *  Constant: '<S140>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.IeVBII_e_TrlrPrsntSts !=
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* SignalConversion: '<S2>/SignalCopy16' */
  THA_SM_Ref_B.TeVBII_e_TrailerConnectionSts_jp0t =
    rtu_MbTHA_VehInpOutData->IeVBII_e_TrailerConnectionSts;

  /* RelationalOperator: '<S93>/RelationalOperator12' incorporates:
   *  Constant: '<S141>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator4 =
    (THA_SM_Ref_B.TeVBII_e_TrailerConnectionSts_jp0t !=
     TeVBII_e_TrailerConnectionSts_Connected);

  /* Logic: '<S93>/LogicalOperator7' */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.LogicalOperator3_edxj &&
    THA_SM_Ref_B.LogicalOperator4 && THA_SM_Ref_B.RelationalOperator3_lwkl &&
    THA_SM_Ref_B.RelationalOperator4);

  /* Logic: '<S93>/LogicalOperator9' */
  MeTHA_b_ActivTrns = (THA_SM_Ref_B.RelationalOperator1_ibmm &&
                       THA_SM_Ref_B.LogicalOperator2_npvg &&
                       THA_SM_Ref_B.LogicalOperator7 &&
                       THA_SM_Ref_B.LogicalOperator3_edxj);

  /* SignalConversion: '<S2>/SignalCopy63' */
  THA_SM_Ref_B.IeSVS_e_DispView2 = rtu_MbTHA_HmiSvsOutData->IeSVS_e_DispView2;

  /* RelationalOperator: '<S89>/RelationalOperator9' incorporates:
   *  Constant: '<S98>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator4 = (THA_SM_Ref_B.IeSVS_e_DispView2 ==
    TeSVS_e_DispView2_View_1);

  /* RelationalOperator: '<S89>/RelationalOperator1' incorporates:
   *  Constant: '<S97>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.IeSVS_e_DispView2 ==
    TeSVS_e_DispView2_View_5);

  /* Logic: '<S89>/LogicalOperator' */
  THA_SM_Ref_B.MeTHA_b_EnabledSelectionTrns = (THA_SM_Ref_B.RelationalOperator4 ||
    THA_SM_Ref_B.LogicalOperator3_edxj);

  /* UnitDelay: '<S99>/Unit Delay' */
  THA_SM_Ref_B.UnitDelay_i52v = THA_SM_Ref_DW.UnitDelay_DSTATE_jxgs;

  /* RelationalOperator: '<S99>/Relational Operator1' incorporates:
   *  Constant: '<S104>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator4 = (THA_SM_Ref_B.MeTHA_e_CplrDetStsFiltered !=
    TeTHA_e_CplrDetctStatus_Not_Detected);

  /* RelationalOperator: '<S99>/Relational Operator' incorporates:
   *  Constant: '<S104>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator3_edxj = (MeTHA_e_CplrDetctStatus ==
    TeTHA_e_CplrDetctStatus_Not_Detected);

  /* Logic: '<S99>/Logical Operator1' */
  THA_SM_Ref_B.RelationalOperator4 = (THA_SM_Ref_B.RelationalOperator4 &&
    THA_SM_Ref_B.LogicalOperator3_edxj);

  /* SignalConversion: '<S2>/SignalCopy3' */
  MeTHA_px_HitchCplrPixDiffLong =
    rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchCplrPixDiffLong;

  /* Switch: '<S99>/Switch4' */
  if (THA_SM_Ref_B.RelationalOperator4) {
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered =
      THA_SM_Ref_B.UnitDelay_i52v;
  } else {
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered =
      MeTHA_px_HitchCplrPixDiffLong;
  }

  /* End of Switch: '<S99>/Switch4' */

  /* SignalConversion: '<S2>/SignalCopy58' */
  THA_SM_Ref_B.MbTHASmVc_InputsFromVrntTunParam = *rtu_MbTHA_VrntTunParamOutData;

  /* RelationalOperator: '<S90>/RelationalOperator1' */
  THA_SM_Ref_B.MeTHA_b_EngagedDeltaTrns =
    (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered <=
     THA_SM_Ref_B.MbTHASmVc_InputsFromVrntTunParam.KeTHA_px_HitchCplrDeltaThd1);

  /* UnitDelay: '<S90>/Unit Delay' */
  THA_SM_Ref_B.MeTHA_b_EngagedInquiryTrns = THA_SM_Ref_DW.UnitDelay_DSTATE_fbjp;

  /* RelationalOperator: '<S88>/RelationalOperator5' incorporates:
   *  Constant: '<S94>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.IeVBII_e_VehStandStillSts ==
    TeVBII_e_VehStandStillSts_True);

  /* RelationalOperator: '<S88>/RelationalOperator11' incorporates:
   *  Constant: '<S95>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* Logic: '<S88>/LogicalOperator3' */
  THA_SM_Ref_B.LogicalOperator3_edxj = (THA_SM_Ref_B.LogicalOperator3_edxj &&
    THA_SM_Ref_B.LogicalOperator4);

  /* Logic: '<S88>/LogicalOperator2' */
  THA_SM_Ref_B.LogicalOperator4 = !THA_SM_Ref_B.LogicalOperator3_edxj;

  /* UnitDelay: '<S96>/UnitDelay3' */
  THA_SM_Ref_B.Sum = THA_SM_Ref_DW.UnitDelay3_DSTATE;

  /* Switch: '<S96>/Switch1' incorporates:
   *  Constant: '<S96>/Constant4'
   */
  if (THA_SM_Ref_B.LogicalOperator4) {
    THA_SM_Ref_B.Sum = 0.0F;
  }

  /* End of Switch: '<S96>/Switch1' */

  /* Sum: '<S96>/Sum1' incorporates:
   *  Constant: '<S88>/Constant7'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_Standstill - THA_SM_Ref_B.Sum;

  /* Gain: '<S96>/Gain' incorporates:
   *  Constant: '<S88>/Constant3'
   *  Gain: '<S116>/Gain'
   *  Gain: '<S117>/Gain'
   *  Gain: '<S126>/Gain'
   *  Gain: '<S36>/Gain'
   */
  THA_SM_Ref_B.Sum_njfy = 0.99F * KeTHA_s_ThaSampleTime;
  THA_SM_Ref_B.Sum_jetc = THA_SM_Ref_B.Sum_njfy;

  /* RelationalOperator: '<S96>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator = (THA_SM_Ref_B.Sum1 < THA_SM_Ref_B.Sum_jetc);

  /* Logic: '<S88>/LogicalOperator1' */
  THA_SM_Ref_B.MeTHA_b_CompleteTrns = (THA_SM_Ref_B.RelationalOperator &&
    MeSVS_b_IsConfirmBtnPrsd);

  /* RelationalOperator: '<S109>/RelationalOperator9' incorporates:
   *  Constant: '<S124>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp ==
    TeVBII_e_EpsTHASteerTrqResp_TOI_Available);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S120>/Constant'
   *  RelationalOperator: '<S109>/RelationalOperator8'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.IeVBII_e_EcmTHAResp ==
    TeVBII_e_EcmTHAResp_Off);

  /* RelationalOperator: '<S109>/RelationalOperator2' incorporates:
   *  Constant: '<S121>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm =
    (THA_SM_Ref_B.IeVBII_e_VehStandStillSts == TeVBII_e_VehStandStillSts_True);

  /* SignalConversion: '<S2>/SignalCopy21' */
  THA_SM_Ref_B.IeVBII_e_LhrWhlSpnSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_LhfWhlSpnSts;

  /* RelationalOperator: '<S109>/RelationalOperator3' incorporates:
   *  Constant: '<S122>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_LhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_StandStill);

  /* SignalConversion: '<S2>/SignalCopy27' */
  THA_SM_Ref_B.IeVBII_e_RhrWhlSpnSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_RhfWhlSpnSts;

  /* RelationalOperator: '<S109>/RelationalOperator4' incorporates:
   *  Constant: '<S123>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.IeVBII_e_RhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S110>/RelationalOperator11' incorporates:
   *  Constant: '<S128>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator6 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged);

  /* RelationalOperator: '<S110>/RelationalOperator3' incorporates:
   *  Constant: '<S131>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* RelationalOperator: '<S110>/RelationalOperator2' incorporates:
   *  Constant: '<S130>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_m1ul = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Delta);

  /* Logic: '<S110>/LogicalOperator1' */
  THA_SM_Ref_B.LogicalOperator6 = (THA_SM_Ref_B.LogicalOperator6 ||
    THA_SM_Ref_B.RelationalOperator3_anin || THA_SM_Ref_B.LogicalOperator2_m1ul);

  /* RelationalOperator: '<S110>/RelationalOperator1' incorporates:
   *  Constant: '<S129>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_m1ul =
    (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply == TeVBII_e_GearEngagedForDsply_R);

  /* Logic: '<S110>/LogicalOperator' */
  THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp = (THA_SM_Ref_B.LogicalOperator6 &&
    THA_SM_Ref_B.LogicalOperator2_m1ul);

  /* Logic: '<S109>/LogicalOperator1' */
  THA_SM_Ref_B.LogicalOperator1 = (THA_SM_Ref_B.LogicalOperator2_npvg &&
    THA_SM_Ref_B.RelationalOperator1_ibmm && THA_SM_Ref_B.LogicalOperator7 &&
    THA_SM_Ref_B.RelationalOperator3_lwkl &&
    THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp);

  /* UnitDelay: '<S109>/UnitDelay' */
  THA_SM_Ref_B.LogicalOperator2_m1ul = THA_SM_Ref_DW.UnitDelay_DSTATE_d5cr;

  /* Logic: '<S109>/LogicalOperator11' */
  THA_SM_Ref_B.LogicalOperator2_m1ul = !THA_SM_Ref_B.LogicalOperator2_m1ul;

  /* Logic: '<S109>/LogicalOperator7' */
  THA_SM_Ref_B.LogicalOperator2_m1ul = (THA_SM_Ref_B.LogicalOperator1 &&
    THA_SM_Ref_B.LogicalOperator2_m1ul);

  /* UnitDelay: '<S127>/UnitDelay' */
  THA_SM_Ref_B.UnitDelay_ewqi = THA_SM_Ref_DW.UnitDelay_DSTATE_kgyy;

  /* Switch: '<S127>/Switch' */
  if (THA_SM_Ref_B.LogicalOperator2_m1ul) {
    THA_SM_Ref_B.Switch_a0h1 = THA_SM_Ref_B.LogicalOperator2_m1ul;
  } else {
    /* Logic: '<S109>/LogicalOperator5' */
    THA_SM_Ref_B.LogicalOperator5_flx5 = !THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp;

    /* Switch: '<S127>/Switch1' */
    if (THA_SM_Ref_B.LogicalOperator5_flx5) {
      /* Logic: '<S127>/LogicalOperator' */
      THA_SM_Ref_B.LogicalOperator_fazu = !THA_SM_Ref_B.LogicalOperator5_flx5;
      THA_SM_Ref_B.Switch1_ggdu = THA_SM_Ref_B.LogicalOperator_fazu;
    } else {
      THA_SM_Ref_B.Switch1_ggdu = THA_SM_Ref_B.UnitDelay_ewqi;
    }

    /* End of Switch: '<S127>/Switch1' */
    THA_SM_Ref_B.Switch_a0h1 = THA_SM_Ref_B.Switch1_ggdu;
  }

  /* End of Switch: '<S127>/Switch' */

  /* SignalConversion: '<S2>/SignalCopy14' */
  THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig =
    rtu_MbTHA_VehInpOutData->IeVBII_kph_VehSpeedVSOSig;

  /* DataTypeConversion: '<S109>/DataTypeConversion' incorporates:
   *  DataTypeConversion: '<S108>/DataTypeConversion'
   *  DataTypeConversion: '<S18>/DataTypeConversion'
   */
  Sum_jetc_tmp = (real32_T)(int32_T)*rtu_IeTHA_e_THARmpUpDwnSpdPrev;
  THA_SM_Ref_B.Sum_jetc = Sum_jetc_tmp;

  /* Sum: '<S109>/Add1' incorporates:
   *  Constant: '<S109>/Constant4'
   */
  THA_SM_Ref_B.Sum_jetc += KeTHA_kph_ActvSpdThd;

  /* RelationalOperator: '<S109>/RelationalOperator7' */
  THA_SM_Ref_B.LogicalOperator2_m1ul = (THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig <=
    THA_SM_Ref_B.Sum_jetc);

  /* RelationalOperator: '<S109>/RelationalOperator1' incorporates:
   *  Constant: '<S118>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin = (*rtu_IeTHA_e_THARmpUpDwnSpdPrev !=
    TeTHA_e_THARmpUpDwnSpd_No_Request);

  /* Logic: '<S109>/LogicalOperator2' */
  THA_SM_Ref_B.LogicalOperator2_m1ul = (THA_SM_Ref_B.Switch_a0h1 &&
    THA_SM_Ref_B.LogicalOperator2_m1ul && THA_SM_Ref_B.RelationalOperator3_anin);

  /* Logic: '<S109>/LogicalOperator' */
  THA_SM_Ref_B.RelationalOperator3_anin = !THA_SM_Ref_B.LogicalOperator2_m1ul;

  /* UnitDelay: '<S126>/UnitDelay3' */
  THA_SM_Ref_B.Sum_jetc = THA_SM_Ref_DW.UnitDelay3_DSTATE_bz1l;

  /* Switch: '<S126>/Switch1' incorporates:
   *  Constant: '<S126>/Constant4'
   */
  if (THA_SM_Ref_B.RelationalOperator3_anin) {
    THA_SM_Ref_B.Sum_jetc = 0.0F;
  }

  /* End of Switch: '<S126>/Switch1' */

  /* Sum: '<S126>/Sum1' incorporates:
   *  Constant: '<S109>/Constant16'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_EpsHandshake - THA_SM_Ref_B.Sum_jetc;

  /* Gain: '<S126>/Gain' */
  THA_SM_Ref_B.Sum_jrtb = THA_SM_Ref_B.Sum_njfy;

  /* RelationalOperator: '<S126>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.Sum1 <
    THA_SM_Ref_B.Sum_jrtb);

  /* Logic: '<S109>/LogicalOperator4' */
  THA_SM_Ref_B.RelationalOperator3_anin = !THA_SM_Ref_B.RelationalOperator3_anin;

  /* Logic: '<S109>/LogicalOperator6' */
  MeTHA_b_AbortSteerTrqReq = ((!THA_SM_Ref_B.LogicalOperator4) &&
    (!THA_SM_Ref_B.RelationalOperator3_anin));

  /* RelationalOperator: '<S108>/RelationalOperator8' incorporates:
   *  Constant: '<S115>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.IeVBII_e_EcmTHAResp ==
    TeVBII_e_EcmTHAResp_Active);

  /* DataTypeConversion: '<S108>/DataTypeConversion' */
  THA_SM_Ref_B.Sum_jrtb = Sum_jetc_tmp;

  /* Sum: '<S108>/Add1' incorporates:
   *  Constant: '<S108>/Constant4'
   */
  THA_SM_Ref_B.Sum_jrtb += KeTHA_kph_ActvSpdThd;

  /* RelationalOperator: '<S108>/RelationalOperator7' */
  THA_SM_Ref_B.LogicalOperator6 = (THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig >=
    THA_SM_Ref_B.Sum_jrtb);

  /* RelationalOperator: '<S108>/RelationalOperator2' incorporates:
   *  Constant: '<S112>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (*rtu_IeTHA_e_THARmpUpDwnSpdPrev !=
    TeTHA_e_THARmpUpDwnSpd_No_Request);

  /* Logic: '<S108>/LogicalOperator6' */
  THA_SM_Ref_B.LogicalOperator6 = (THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp &&
    THA_SM_Ref_B.LogicalOperator6 && THA_SM_Ref_B.LogicalOperator4);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Logic: '<S108>/LogicalOperator1'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = !THA_SM_Ref_B.LogicalOperator6;
  THA_SM_Ref_B.LogicalOperator4 = THA_SM_Ref_B.LogicalOperator2_npvg;

  /* UnitDelay: '<S116>/UnitDelay3' */
  THA_SM_Ref_B.Sum_jrtb = THA_SM_Ref_DW.UnitDelay3_DSTATE_ipup;

  /* Switch: '<S116>/Switch1' incorporates:
   *  Constant: '<S116>/Constant4'
   */
  if (THA_SM_Ref_B.LogicalOperator4) {
    THA_SM_Ref_B.Sum_jrtb = 0.0F;
  }

  /* End of Switch: '<S116>/Switch1' */

  /* Sum: '<S116>/Sum1' incorporates:
   *  Constant: '<S108>/Constant16'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_EcmHandshake - THA_SM_Ref_B.Sum_jrtb;

  /* Gain: '<S116>/Gain' */
  THA_SM_Ref_B.Sum_ndvb = THA_SM_Ref_B.Sum_njfy;

  /* RelationalOperator: '<S116>/RelationalOperator' */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.Sum1 < THA_SM_Ref_B.Sum_ndvb);

  /* Logic: '<S108>/LogicalOperator8' */
  THA_SM_Ref_B.LogicalOperator4 = !THA_SM_Ref_B.LogicalOperator4;

  /* Logic: '<S108>/LogicalOperator13' */
  THA_SM_Ref_B.RelationalOperator3_anin =
    ((!THA_SM_Ref_B.RelationalOperator3_anin) && (!THA_SM_Ref_B.LogicalOperator4));

  /* RelationalOperator: '<S108>/RelationalOperator1' incorporates:
   *  Constant: '<S111>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp ==
    TeVBII_e_BsmTHABrkResp_Active);

  /* UnitDelay: '<S117>/UnitDelay3' */
  THA_SM_Ref_B.Sum_ndvb = THA_SM_Ref_DW.UnitDelay3_DSTATE_hyrp;

  /* Switch: '<S117>/Switch1' incorporates:
   *  Constant: '<S117>/Constant4'
   */
  if (THA_SM_Ref_B.LogicalOperator2_npvg) {
    THA_SM_Ref_B.Sum_ndvb = 0.0F;
  }

  /* End of Switch: '<S117>/Switch1' */

  /* Sum: '<S117>/Sum1' incorporates:
   *  Constant: '<S108>/Constant1'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_BsmHandshake - THA_SM_Ref_B.Sum_ndvb;

  /* Gain: '<S117>/Gain' */
  THA_SM_Ref_B.Sum_oetd = THA_SM_Ref_B.Sum_njfy;

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Logic: '<S108>/LogicalOperator2'
   *  RelationalOperator: '<S117>/RelationalOperator'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.Sum1 <
    THA_SM_Ref_B.Sum_oetd);
  THA_SM_Ref_B.LogicalOperator2_npvg = !THA_SM_Ref_B.LogicalOperator2_npvg;

  /* Logic: '<S108>/LogicalOperator3' */
  THA_SM_Ref_B.LogicalOperator4 = ((!THA_SM_Ref_B.LogicalOperator4) &&
    (!THA_SM_Ref_B.LogicalOperator2_npvg));

  /* Logic: '<S108>/LogicalOperator4' */
  MeTHA_b_AbortSpdLimReq = (THA_SM_Ref_B.RelationalOperator3_anin ||
    THA_SM_Ref_B.LogicalOperator4);

  /* Logic: '<S107>/LogicalOperator2' */
  THA_SM_Ref_B.MeTHA_b_AbortStrTrqSpdLimReq = (MeTHA_b_AbortSteerTrqReq ||
    MeTHA_b_AbortSpdLimReq);

  /* SignalConversion: '<S2>/SignalCopy20' */
  THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr =
    rtu_MbTHA_VehInpOutData->IeVBII_cnt_LhfPulseCtr;

  /* RelationalOperator: '<S19>/RelationalOperator6' incorporates:
   *  Constant: '<S19>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator3_anin =
    (THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr == KeTHA_cnt_FastPlsCntrSNA);

  /* SignalConversion: '<S2>/SignalCopy18' */
  THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr =
    rtu_MbTHA_VehInpOutData->IeVBII_cnt_LhrPulseCtr;

  /* RelationalOperator: '<S19>/RelationalOperator8' incorporates:
   *  Constant: '<S19>/Constant4'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr ==
    KeTHA_cnt_FastPlsCntrSNA);

  /* SignalConversion: '<S2>/SignalCopy26' */
  THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr =
    rtu_MbTHA_VehInpOutData->IeVBII_cnt_RhfPulseCtr;

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S19>/Constant6'
   *  RelationalOperator: '<S19>/RelationalOperator13'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr ==
    KeTHA_cnt_FastPlsCntrSNA);

  /* SignalConversion: '<S2>/SignalCopy24' */
  THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr =
    rtu_MbTHA_VehInpOutData->IeVBII_cnt_RhrPulseCtr;

  /* RelationalOperator: '<S19>/RelationalOperator14' incorporates:
   *  Constant: '<S19>/Constant8'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm =
    (THA_SM_Ref_B.IeVBII_cnt_RhrFastPlsCntr == KeTHA_cnt_FastPlsCntrSNA);

  /* Logic: '<S19>/LogicalOperator4' */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.RelationalOperator3_anin
    || THA_SM_Ref_B.LogicalOperator4 || THA_SM_Ref_B.LogicalOperator2_npvg ||
    THA_SM_Ref_B.RelationalOperator1_ibmm);

  /* RelationalOperator: '<S19>/RelationalOperator11' incorporates:
   *  Constant: '<S46>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.IeVBII_e_LhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_SNA);

  /* SignalConversion: '<S2>/SignalCopy19' */
  THA_SM_Ref_B.IeVBII_e_LhrWhlSpnSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_LhrWhlSpnSts;

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S62>/Constant'
   *  RelationalOperator: '<S19>/RelationalOperator18'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.IeVBII_e_LhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_SNA);

  /* RelationalOperator: '<S19>/RelationalOperator22' incorporates:
   *  Constant: '<S50>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.IeVBII_e_RhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_SNA);

  /* SignalConversion: '<S2>/SignalCopy30' */
  THA_SM_Ref_B.IeVBII_e_RhrWhlSpnSts =
    rtu_MbTHA_VehInpOutData->IeVBII_e_RhrWhlSpnSts;

  /* RelationalOperator: '<S19>/RelationalOperator25' incorporates:
   *  Constant: '<S51>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_RhrWhlSpnSts ==
    TeVBII_e_WhlSpnSts_SNA);

  /* Logic: '<S19>/LogicalOperator5' */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.LogicalOperator4 ||
    THA_SM_Ref_B.LogicalOperator2_npvg || THA_SM_Ref_B.RelationalOperator1_ibmm ||
    THA_SM_Ref_B.LogicalOperator7);

  /* SignalConversion: '<S2>/SignalCopy22' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_kph_LhfWhlSpd;

  /* Sum: '<S64>/Subtract' incorporates:
   *  Constant: '<S19>/Constant2'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_kph_WhlSpdSNA;

  /* Abs: '<S64>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Constant: '<S64>/Constant1'
   *  RelationalOperator: '<S64>/RelationalOperator10'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy25' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_kph_LhrWhlSpd;

  /* Sum: '<S73>/Subtract' incorporates:
   *  Constant: '<S19>/Constant5'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_kph_WhlSpdSNA;

  /* Abs: '<S73>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S73>/RelationalOperator10' incorporates:
   *  Constant: '<S73>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy23' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_kph_RhfWhlSpd;

  /* Sum: '<S72>/Subtract' incorporates:
   *  Constant: '<S19>/Constant7'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_kph_WhlSpdSNA;

  /* Abs: '<S72>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S72>/RelationalOperator10' incorporates:
   *  Constant: '<S72>/Constant1'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy31' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_kph_RhrWhlSpd;

  /* Sum: '<S71>/Subtract' incorporates:
   *  Constant: '<S19>/Constant9'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_kph_WhlSpdSNA;

  /* Abs: '<S71>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S71>/RelationalOperator10' incorporates:
   *  Constant: '<S71>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Logic: '<S19>/LogicalOperator6'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.LogicalOperator2_npvg ||
    THA_SM_Ref_B.RelationalOperator1_ibmm || THA_SM_Ref_B.LogicalOperator7 ||
    THA_SM_Ref_B.RelationalOperator3_lwkl);

  /* RelationalOperator: '<S19>/RelationalOperator4' incorporates:
   *  Constant: '<S57>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm =
    (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp == TeVBII_e_EpsTHASteerTrqResp_SNA);

  /* RelationalOperator: '<S19>/RelationalOperator1' incorporates:
   *  Constant: '<S45>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp ==
    TeVBII_e_EpsTHASteerTrqResp_Temp_NA);

  /* RelationalOperator: '<S19>/RelationalOperator15' incorporates:
   *  Constant: '<S48>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl =
    (THA_SM_Ref_B.IeVBII_e_EpsTHASteerTrqResp ==
     TeVBII_e_EpsTHASteerTrqResp_Perm_NA);

  /* Logic: '<S19>/LogicalOperator9' */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (THA_SM_Ref_B.RelationalOperator1_ibmm
    || THA_SM_Ref_B.LogicalOperator7 || THA_SM_Ref_B.RelationalOperator3_lwkl);

  /* SignalConversion: '<S2>/SignalCopy50' */
  THA_SM_Ref_B.IeVBII_e_VehEPBSts = rtu_MbTHA_VehInpOutData->IeVBII_e_VehEPBSts;

  /* RelationalOperator: '<S19>/RelationalOperator7' incorporates:
   *  Constant: '<S61>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.IeVBII_e_VehEPBSts ==
    TeVBII_e_VehEPBSts_SNA);

  /* SignalConversion: '<S2>/SignalCopy35' */
  THA_SM_Ref_B.IeVBII_e_LwsAngTyp =
    rtu_MbTHA_VehInpOutData->IeVBII_e_LwsAngleType;

  /* RelationalOperator: '<S19>/RelationalOperator12' incorporates:
   *  Constant: '<S53>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.IeVBII_e_LwsAngTyp ==
    TeVBII_e_LwsAngleType_SNA);

  /* SignalConversion: '<S2>/SignalCopy13' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_ddeg_VehYawRate;

  /* Sum: '<S68>/Subtract' incorporates:
   *  Constant: '<S19>/Constant13'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_ddeg_YawRateBsmSNA;

  /* Abs: '<S68>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S68>/RelationalOperator10' incorporates:
   *  Constant: '<S68>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* Logic: '<S19>/LogicalOperator7' */
  THA_SM_Ref_B.LogicalOperator7 = (THA_SM_Ref_B.LogicalOperator7 ||
    THA_SM_Ref_B.RelationalOperator3_lwkl || THA_SM_Ref_B.RelationalOperator2);

  /* SignalConversion: '<S2>/SignalCopy32' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_a_VehLatAccOffset;

  /* Sum: '<S70>/Subtract' incorporates:
   *  Constant: '<S19>/Constant11'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_a_AcclOfstBsmSNA;

  /* Abs: '<S70>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S70>/RelationalOperator10' incorporates:
   *  Constant: '<S70>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy28' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_a_VehLongAccOffset;

  /* Sum: '<S69>/Subtract' incorporates:
   *  Constant: '<S19>/Constant10'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_a_AcclOfstBsmSNA;

  /* Abs: '<S69>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S69>/RelationalOperator10' incorporates:
   *  Constant: '<S69>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy56' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_a_VehLatAcc;

  /* Sum: '<S66>/Subtract' incorporates:
   *  Constant: '<S19>/Constant15'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_a_VehAccSNA;

  /* Abs: '<S66>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S66>/RelationalOperator10' incorporates:
   *  Constant: '<S66>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* SignalConversion: '<S2>/SignalCopy57' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_a_VehLongAcc;

  /* Sum: '<S67>/Subtract' incorporates:
   *  Constant: '<S19>/Constant17'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_a_VehAccSNA;

  /* Abs: '<S67>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S67>/RelationalOperator10' incorporates:
   *  Constant: '<S67>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* Logic: '<S19>/LogicalOperator8' */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.RelationalOperator2 ||
    THA_SM_Ref_B.RelationalOperator3_lwkl || THA_SM_Ref_B.RelationalOperator19 ||
    THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* RelationalOperator: '<S19>/RelationalOperator19' incorporates:
   *  Constant: '<S55>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h =
    (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
     TeVBII_e_GearEngagedForDsply_SNA);

  /* SignalConversion: '<S2>/SignalCopy34' */
  THA_SM_Ref_B.IeVBII_e_EssEngState =
    rtu_MbTHA_VehInpOutData->IeVBII_e_EssEngState;

  /* RelationalOperator: '<S19>/RelationalOperator9' incorporates:
   *  Constant: '<S60>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.IeVBII_e_EssEngState ==
    TeVBII_e_EssEngState_SNA);

  /* SignalConversion: '<S2>/SignalCopy33' */
  THA_SM_Ref_B.IeVBII_e_EngineSts = rtu_MbTHA_VehInpOutData->IeVBII_e_EngineSts;

  /* RelationalOperator: '<S19>/RelationalOperator17' incorporates:
   *  Constant: '<S59>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.IeVBII_e_EngineSts ==
    TeVBII_e_EngineSts_SNA);

  /* SignalConversion: '<S2>/SignalCopy44' */
  THA_SM_Ref_B.IeVBII_e_THASteerTouchStatus =
    rtu_MbTHA_VehInpOutData->IeVBII_e_THASteerTouchStatus;

  /* RelationalOperator: '<S19>/RelationalOperator5' incorporates:
   *  Constant: '<S49>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_a3nq =
    (THA_SM_Ref_B.IeVBII_e_THASteerTouchStatus ==
     TeVBII_e_THASteerTouchStatus_SNA);

  /* Logic: '<S19>/LogicalOperator3' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.RelationalOperator2_hq3h
    || THA_SM_Ref_B.RelationalOperator19 ||
    THA_SM_Ref_B.RelationalOperator3_lwkl || THA_SM_Ref_B.LogicalOperator2_a3nq);

  /* SignalConversion: '<S2>/SignalCopy29' */
  THA_SM_Ref_B.Sum_oetd = rtu_MbTHA_VehInpOutData->IeVBII_deg_StrWhlAng;

  /* Sum: '<S65>/Subtract' incorporates:
   *  Constant: '<S19>/Constant3'
   */
  THA_SM_Ref_B.Sum_oetd -= KeTHA_deg_StrWhlAngSNA;

  /* Abs: '<S65>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S65>/RelationalOperator10' incorporates:
   *  Constant: '<S65>/Constant1'
   */
  THA_SM_Ref_B.LogicalOperator2_a3nq = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* Sum: '<S63>/Subtract' incorporates:
   *  Constant: '<S19>/Constant12'
   */
  THA_SM_Ref_B.Sum_oetd = THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig -
    KeTHA_kph_VehSpdVSOSigSNA;

  /* Abs: '<S63>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S63>/RelationalOperator10' incorporates:
   *  Constant: '<S63>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* RelationalOperator: '<S19>/RelationalOperator10' incorporates:
   *  Constant: '<S52>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl =
    (THA_SM_Ref_B.IeVBII_e_VehStandStillSts == TeVBII_e_VehStandStillSts_SNA);

  /* Logic: '<S19>/LogicalOperator2' */
  THA_SM_Ref_B.LogicalOperator2_a3nq = (THA_SM_Ref_B.LogicalOperator2_a3nq ||
    THA_SM_Ref_B.RelationalOperator19 || THA_SM_Ref_B.RelationalOperator3_lwkl ||
    MeTHA_b_FidDisabled);

  /* RelationalOperator: '<S19>/RelationalOperator2' incorporates:
   *  Constant: '<S54>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp ==
    TeVBII_e_BsmTHABrkResp_SNA);

  /* RelationalOperator: '<S19>/RelationalOperator3' incorporates:
   *  Constant: '<S56>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_lwkl = (THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp ==
    TeVBII_e_BsmTHABrkResp_BrakesOverheated);

  /* SignalConversion: '<S2>/SignalCopy47' */
  THA_SM_Ref_B.IeVBII_e_EpsTHADrvTrqOvrd =
    rtu_MbTHA_VehInpOutData->IeVBII_e_EpsTHADrvTrqOvrd;

  /* RelationalOperator: '<S19>/RelationalOperator21' incorporates:
   *  Constant: '<S47>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco =
    (THA_SM_Ref_B.IeVBII_e_EpsTHADrvTrqOvrd == TeVBII_e_EpsTHADrvTrqOvrd_SNA);

  /* RelationalOperator: '<S19>/RelationalOperator20' incorporates:
   *  Constant: '<S58>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_ehda = (THA_SM_Ref_B.IeVBII_e_EcmTHAResp ==
    TeVBII_e_EcmTHAResp_SNA);

  /* Logic: '<S19>/LogicalOperator1' */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.RelationalOperator19 ||
    THA_SM_Ref_B.RelationalOperator3_lwkl ||
    THA_SM_Ref_B.RelationalOperator7_jqco || THA_SM_Ref_B.LogicalOperator2_ehda);

  /* Logic: '<S19>/LogicalOperator12' */
  MeTHA_b_AbortCndnFaulted = (THA_SM_Ref_B.RelationalOperator3_anin ||
    THA_SM_Ref_B.LogicalOperator4 || THA_SM_Ref_B.LogicalOperator2_npvg ||
    THA_SM_Ref_B.RelationalOperator1_ibmm || THA_SM_Ref_B.LogicalOperator7 ||
    THA_SM_Ref_B.RelationalOperator2 || THA_SM_Ref_B.RelationalOperator2_hq3h ||
    THA_SM_Ref_B.LogicalOperator2_a3nq || THA_SM_Ref_B.RelationalOperator19);

  /* Chart: '<S159>/Chart2' incorporates:
   *  Constant: '<S159>/Constant2'
   */
  THA_SM_Ref_Chart2(&rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidDLDAbort,
                    KeTHA_s_HmiFaultPopUpDur, &THA_SM_Ref_B.switchOut,
                    &THA_SM_Ref_DW.sf_Chart2_g3d0);

  /* UnitDelay: '<S17>/Unit Delay' */
  THA_SM_Ref_B.Sum_oetd = THA_SM_Ref_DW.UnitDelay_DSTATE;

  /* Sum: '<S34>/Subtract' */
  THA_SM_Ref_B.Sum_oetd = THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig -
    THA_SM_Ref_B.Sum_oetd;

  /* Abs: '<S34>/Abs' */
  THA_SM_Ref_B.Sum_oetd = fabsf(THA_SM_Ref_B.Sum_oetd);

  /* RelationalOperator: '<S34>/RelationalOperator10' incorporates:
   *  Constant: '<S34>/Constant1'
   */
  THA_SM_Ref_B.LogicalOperator2_ehda = (THA_SM_Ref_B.Sum_oetd < 0.0001F);

  /* UnitDelay: '<S17>/Unit Delay1' */
  THA_SM_Ref_B.UnitDelay1 = THA_SM_Ref_DW.UnitDelay1_DSTATE_cn3d;

  /* RelationalOperator: '<S17>/RelationalOperator19' */
  THA_SM_Ref_B.RelationalOperator7_jqco =
    (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply == THA_SM_Ref_B.UnitDelay1);

  /* SignalConversion: '<S2>/SignalCopy59' */
  THA_SM_Ref_B.IeVBII_e_TchScrSts = rtu_MbTHA_VehInpOutData->IeVBII_e_TchScrSts;

  /* UnitDelay: '<S17>/Unit Delay2' */
  THA_SM_Ref_B.UnitDelay2 = THA_SM_Ref_DW.UnitDelay2_DSTATE_kwqb;

  /* RelationalOperator: '<S17>/RelationalOperator12' */
  THA_SM_Ref_B.LogicalOperator2_a3nq = (THA_SM_Ref_B.IeVBII_e_TchScrSts ==
    THA_SM_Ref_B.UnitDelay2);

  /* RelationalOperator: '<S17>/RelationalOperator11' incorporates:
   *  Constant: '<S30>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Enabled);

  /* RelationalOperator: '<S17>/RelationalOperator7' incorporates:
   *  Constant: '<S33>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Enabled_Selection);

  /* RelationalOperator: '<S17>/RelationalOperator5' incorporates:
   *  Constant: '<S31>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged);

  /* RelationalOperator: '<S17>/RelationalOperator9' incorporates:
   *  Constant: '<S24>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Delta);

  /* RelationalOperator: '<S17>/RelationalOperator10' incorporates:
   *  Constant: '<S25>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.UnitDelay1_kl5n ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* Logic: '<S17>/LogicalOperator3' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.RelationalOperator2_hq3h
    || THA_SM_Ref_B.RelationalOperator19 || THA_SM_Ref_B.RelationalOperator2 ||
    THA_SM_Ref_B.RelationalOperator3_anin || THA_SM_Ref_B.LogicalOperator4);

  /* Logic: '<S17>/Logical Operator2' */
  THA_SM_Ref_B.LogicalOperator2_ehda = (THA_SM_Ref_B.LogicalOperator2_ehda &&
    THA_SM_Ref_B.RelationalOperator7_jqco && THA_SM_Ref_B.LogicalOperator2_a3nq &&
    THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* Logic: '<S17>/LogicalOperator2' */
  THA_SM_Ref_B.RelationalOperator7_jqco = !THA_SM_Ref_B.LogicalOperator2_ehda;

  /* UnitDelay: '<S36>/UnitDelay3' */
  THA_SM_Ref_B.Sum_oetd = THA_SM_Ref_DW.UnitDelay3_DSTATE_fkls;

  /* Switch: '<S36>/Switch1' incorporates:
   *  Constant: '<S36>/Constant4'
   */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    THA_SM_Ref_B.Sum_oetd = 0.0F;
  }

  /* End of Switch: '<S36>/Switch1' */

  /* Sum: '<S36>/Sum1' incorporates:
   *  Constant: '<S17>/Constant22'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_MnvTimeout - THA_SM_Ref_B.Sum_oetd;

  /* RelationalOperator: '<S36>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator_ibvb = (THA_SM_Ref_B.Sum1 <
    THA_SM_Ref_B.Sum_njfy);

  /* Chart: '<S35>/Chart2' incorporates:
   *  Constant: '<S35>/Constant2'
   */
  if (THA_SM_Ref_DW.temporalCounter_i1_bsnb < MAX_uint32_T) {
    THA_SM_Ref_DW.temporalCounter_i1_bsnb++;
  }

  if ((uint32_T)THA_SM_Ref_DW.is_active_c9_THA_SM_Ref == 0U) {
    THA_SM_Ref_DW.is_active_c9_THA_SM_Ref = 1U;
    THA_SM_Ref_DW.is_c9_THA_SM_Ref = THA_SM_Ref_IN_Idle_f0zo;
    THA_SM_Ref_B.switchOut_gy5o = false;
  } else if ((uint32_T)THA_SM_Ref_DW.is_c9_THA_SM_Ref == THA_SM_Ref_IN_Idle_f0zo)
  {
    THA_SM_Ref_B.switchOut_gy5o = false;
    if (THA_SM_Ref_B.RelationalOperator_ibvb) {
      THA_SM_Ref_DW.is_c9_THA_SM_Ref = THA_SM_Ref_IN_Standby_e4zz;
      THA_SM_Ref_DW.temporalCounter_i1_bsnb = 0U;
      THA_SM_Ref_B.switchOut_gy5o = true;
    }
  } else {
    /* case IN_Standby: */
    THA_SM_Ref_B.switchOut_gy5o = true;
    if ((real32_T)(uint32_T)(int32_T)((int32_T)
         THA_SM_Ref_DW.temporalCounter_i1_bsnb * 3) >= KeTHA_s_HmiFaultPopUpDur *
        100.0F) {
      THA_SM_Ref_DW.is_c9_THA_SM_Ref = THA_SM_Ref_IN_Idle_f0zo;
      THA_SM_Ref_B.switchOut_gy5o = false;
    }
  }

  /* End of Chart: '<S35>/Chart2' */

  /* Switch: '<S159>/Switch' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.switchOut ||
    rtu_MbTHA_DegradMgrOutData->MeTHA_b_FidDLDAbort);

  /* SignalConversion: '<S2>/SignalCopy40' */
  MeTHA_b_FidDLDAbort = THA_SM_Ref_B.RelationalOperator7_jqco;

  /* RelationalOperator: '<S17>/RelationalOperator6' incorporates:
   *  Constant: '<S29>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.IeVBII_e_CmdIgnSts !=
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S17>/RelationalOperator8' incorporates:
   *  Constant: '<S32>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_a3nq =
    (THA_SM_Ref_B.TeVBII_e_TrailerConnectionSts_jp0t ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* SignalConversion: '<S2>/SignalCopy12' */
  THA_SM_Ref_B.IeAP_e_AutoParkStatus =
    rtu_MbTHA_ApSmOutData->IeAP_e_AutoParkStatus;

  /* RelationalOperator: '<S17>/RelationalOperator1' incorporates:
   *  Constant: '<S23>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.IeAP_e_AutoParkStatus ==
    TeAP_e_AutoParkStatus_Active);

  /* RelationalOperator: '<S17>/RelationalOperator4' incorporates:
   *  Constant: '<S28>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.IeAP_e_AutoParkStatus ==
    TeAP_e_AutoParkStatus_Complete);

  /* Logic: '<S17>/Logical Operator1' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.RelationalOperator2_hq3h
    || THA_SM_Ref_B.RelationalOperator19);

  /* SignalConversion: '<S2>/SignalCopy55' */
  THA_SM_Ref_B.IeTRSC_e_TRSCSts = rtu_MbTHA_TrscSmVcOutData->IeTRSC_e_TRSCSts;

  /* RelationalOperator: '<S17>/RelationalOperator2' incorporates:
   *  Constant: '<S26>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.IeTRSC_e_TRSCSts ==
    TeTRSC_e_TRSCSts_PreActive);

  /* RelationalOperator: '<S17>/RelationalOperator3' incorporates:
   *  Constant: '<S27>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.IeTRSC_e_TRSCSts ==
    TeTRSC_e_TRSCSts_Active);

  /* Logic: '<S17>/Logical Operator' */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.RelationalOperator19 ||
    THA_SM_Ref_B.RelationalOperator2);

  /* Logic: '<S17>/Logical Operator3' */
  MeTHA_b_FeatureOverride = (THA_SM_Ref_B.RelationalOperator2_hq3h ||
    THA_SM_Ref_B.RelationalOperator19);

  /* Switch: '<S35>/Switch' */
  *rty_MeTHA_b_UsrInputTimeOut = (THA_SM_Ref_B.switchOut_gy5o ||
    THA_SM_Ref_B.RelationalOperator_ibvb);

  /* Logic: '<S17>/LogicalOperator' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (MeTHA_b_FidDisabled ||
    MeTHA_b_FidCamCalAbort || MeTHA_b_FidDLDAbort ||
    THA_SM_Ref_B.IeVBII_b_TrnkStatus || THA_SM_Ref_B.RelationalOperator7_jqco ||
    THA_SM_Ref_B.LogicalOperator2_a3nq || MeTHA_b_FeatureOverride ||
    (*rty_MeTHA_b_UsrInputTimeOut));

  /* RelationalOperator: '<S5>/RelationalOperator2' incorporates:
   *  Constant: '<S21>/Constant'
   */
  THA_SM_Ref_B.LogicalOperator2_a3nq =
    (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply != TeVBII_e_GearEngagedForDsply_R);

  /* Logic: '<S5>/Logical Operator' */
  MeTHA_b_AbortCndnEnabled = (THA_SM_Ref_B.RelationalOperator7_jqco ||
    THA_SM_Ref_B.LogicalOperator2_a3nq);

  /* RelationalOperator: '<S5>/RelationalOperator1' incorporates:
   *  Constant: '<S20>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h =
    (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply != TeVBII_e_GearEngagedForDsply_P);

  /* Logic: '<S5>/Logical Operator2' */
  THA_SM_Ref_B.LogicalOperator2_a3nq = (THA_SM_Ref_B.LogicalOperator2_a3nq &&
    THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* Logic: '<S5>/LogicalOperator2' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = !THA_SM_Ref_B.LogicalOperator2_a3nq;

  /* Gain: '<S96>/Gain' incorporates:
   *  UnitDelay: '<S22>/UnitDelay3'
   */
  THA_SM_Ref_B.Sum_njfy = THA_SM_Ref_DW.UnitDelay3_DSTATE_gjgb;

  /* Switch: '<S22>/Switch1' */
  if (THA_SM_Ref_B.RelationalOperator2_hq3h) {
    /* Gain: '<S96>/Gain' incorporates:
     *  Constant: '<S22>/Constant4'
     */
    THA_SM_Ref_B.Sum_njfy = 0.0F;
  }

  /* End of Switch: '<S22>/Switch1' */

  /* Sum: '<S22>/Sum1' incorporates:
   *  Constant: '<S5>/Constant22'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_GearEnggConfDur - THA_SM_Ref_B.Sum_njfy;

  /* Gain: '<S22>/Gain' incorporates:
   *  Constant: '<S5>/Constant3'
   */
  THA_SM_Ref_B.Gain = 0.99F * KeTHA_s_ThaSampleTime;

  /* RelationalOperator: '<S22>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.Sum1 < THA_SM_Ref_B.Gain);

  /* RelationalOperator: '<S18>/RelationalOperator19' incorporates:
   *  Constant: '<S41>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator19 = (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply
    == TeVBII_e_GearEngagedForDsply_R);

  /* RelationalOperator: '<S18>/RelationalOperator21' incorporates:
   *  Constant: '<S39>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.IeVBII_e_EpsTHADrvTrqOvrd ==
    TeVBII_e_EpsTHADrvTrqOvrd_True);

  /* Logic: '<S18>/LogicalOperator1' */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.RelationalOperator19 &&
    THA_SM_Ref_B.RelationalOperator2);

  /* RelationalOperator: '<S18>/RelationalOperator10' incorporates:
   *  Constant: '<S40>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin =
    (THA_SM_Ref_B.IeVBII_e_VehStandStillSts == TeVBII_e_VehStandStillSts_False);

  /* Logic: '<S18>/LogicalOperator3' */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.RelationalOperator3_anin
    && THA_SM_Ref_B.IeVBII_b_DrvDoorSts);

  /* Sum: '<S42>/Subtract' incorporates:
   *  Constant: '<S18>/Constant12'
   */
  THA_SM_Ref_B.Gain = THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig -
    KeTHA_kph_VehSpdVSOSigSNA;

  /* Abs: '<S42>/Abs' */
  THA_SM_Ref_B.Gain = fabsf(THA_SM_Ref_B.Gain);

  /* RelationalOperator: '<S42>/RelationalOperator10' incorporates:
   *  Constant: '<S42>/Constant1'
   */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.Gain < 0.0001F);

  /* Logic: '<S18>/Logical Operator1' */
  THA_SM_Ref_B.LogicalOperator4 = !THA_SM_Ref_B.LogicalOperator4;

  /* DataTypeConversion: '<S18>/DataTypeConversion' */
  THA_SM_Ref_B.Gain = Sum_jetc_tmp;

  /* Sum: '<S18>/Add' incorporates:
   *  Constant: '<S18>/Constant21'
   */
  THA_SM_Ref_B.Gain += KeTHA_kph_ActvSpdThd;

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  RelationalOperator: '<S18>/RelationalOperator3'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = (THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig >
    THA_SM_Ref_B.Gain);

  /* RelationalOperator: '<S18>/RelationalOperator1' incorporates:
   *  Constant: '<S38>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1_ibmm = (*rtu_IeTHA_e_THARmpUpDwnSpdPrev !=
    TeTHA_e_THARmpUpDwnSpd_No_Request);

  /* Logic: '<S18>/LogicalOperator4' */
  THA_SM_Ref_B.LogicalOperator4 = (THA_SM_Ref_B.RelationalOperator19 &&
    THA_SM_Ref_B.LogicalOperator4 && THA_SM_Ref_B.LogicalOperator2_npvg &&
    THA_SM_Ref_B.RelationalOperator1_ibmm);

  /* Logic: '<S108>/LogicalOperator5' incorporates:
   *  Logic: '<S18>/Logical Operator2'
   */
  THA_SM_Ref_B.LogicalOperator2_npvg = !THA_SM_Ref_B.LogicalOperator4;

  /* UnitDelay: '<S44>/UnitDelay3' */
  THA_SM_Ref_B.Gain = THA_SM_Ref_DW.UnitDelay3_DSTATE_dasz;

  /* Switch: '<S44>/Switch1' incorporates:
   *  Constant: '<S44>/Constant4'
   */
  if (THA_SM_Ref_B.LogicalOperator2_npvg) {
    THA_SM_Ref_B.Gain = 0.0F;
  }

  /* End of Switch: '<S44>/Switch1' */

  /* Sum: '<S44>/Sum1' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_SpdOvrdTimeout - THA_SM_Ref_B.Gain;

  /* Gain: '<S44>/Gain' incorporates:
   *  Constant: '<S18>/Constant4'
   */
  THA_SM_Ref_B.Switch3_ajqq = 0.99F * KeTHA_s_ThaSampleTime;

  /* RelationalOperator: '<S44>/RelationalOperator' */
  MeTHA_b_OverSpeedAbort = (THA_SM_Ref_B.Sum1 < THA_SM_Ref_B.Switch3_ajqq);

  /* Logic: '<S18>/LogicalOperator2' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.RelationalOperator7_jqco
    || THA_SM_Ref_B.RelationalOperator2 || THA_SM_Ref_B.RelationalOperator3_anin
    || MeTHA_b_OverSpeedAbort);

  /* Logic: '<S5>/Logical Operator1' */
  MeTHA_b_AbortCndnEngaged = (THA_SM_Ref_B.RelationalOperator2_hq3h ||
    THA_SM_Ref_B.RelationalOperator7_jqco);

  /* UnitDelay: '<S1>/UnitDelay1' */
  THA_SM_Ref_B.MeTHA_e_ScreenRequestPrev = THA_SM_Ref_DW.UnitDelay1_DSTATE_lybn;

  /* Chart: '<S7>/THA_MainStateMachine' incorporates:
   *  Constant: '<S7>/Constant3'
   */
  if (THA_SM_Ref_DW.temporalCounter_i1 < MAX_uint32_T) {
    THA_SM_Ref_DW.temporalCounter_i1++;
  }

  if ((uint32_T)THA_SM_Ref_DW.is_active_c5_THA_SM_Ref == 0U) {
    THA_SM_Ref_DW.is_active_c5_THA_SM_Ref = 1U;
    THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Off;
    *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;
    *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
  } else {
    switch (THA_SM_Ref_DW.is_c5_THA_SM_Ref) {
     case THA_SM_Ref_IN_Fault:
      if ((real32_T)(uint32_T)(int32_T)((int32_T)
           THA_SM_Ref_DW.temporalCounter_i1 * 3) >= KeTHA_s_HmiFaultPopUpDur *
          100.0F) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Idle_cuxx;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
      } else {
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Faulted;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Faulted;
      }
      break;

     case THA_SM_Ref_IN_Idle_cuxx:
      if (MeTHA_b_FidCamCalAbort) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Initial;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Initial;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      } else if (!THA_SM_Ref_B.MeTHA_b_IgnitionRunStart) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Off;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      } else if ((THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply ==
                  TeVBII_e_GearEngagedForDsply_R) && MeTHA_b_ActivTrns &&
                 MeSVS_b_THASftBtnPrsdStsToTHA) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_THA_Activ_Process;
        THA_SM_Ref_DW.is_THA_Activ_Process = THA_SM_Ref_IN_Enabled;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Enabled;
        THA_SM_Ref_DW.is_Enabled = THA_SM_Ref_IN_Enabled_armw;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Enabled;
      } else {
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
      }
      break;

     case THA_SM_Ref_IN_Initial:
      if (!THA_SM_Ref_B.MeTHA_b_IgnitionRunStart) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Off;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      } else if (!MeTHA_b_FidCamCalAbort) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Idle_cuxx;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Idle;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Idle;
      } else {
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Initial;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      }
      break;

     case THA_SM_Ref_IN_Off:
      if (THA_SM_Ref_B.MeTHA_b_IgnitionRunStart) {
        THA_SM_Ref_DW.is_c5_THA_SM_Ref = THA_SM_Ref_IN_Initial;
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Initial;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      } else {
        *rty_MeTHA_e_THAStateInfo = TeTHA_e_THAStateInfo_Off;
        *rty_IeTHA_e_THAState = TeTHA_e_THAState_Initial;
      }
      break;

     default:
      /* case IN_THA_Activ_Process: */
      THA_SM_Ref_THA_Activ_Process(rty_IeTHA_e_THAState,
        rty_MeTHA_e_THAStateInfo);
      break;
    }
  }

  /* End of Chart: '<S7>/THA_MainStateMachine' */

  /* RelationalOperator: '<S3>/RelationalOperator1' incorporates:
   *  Constant: '<S13>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator1 = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Complete);

  /* UnitDelay: '<S16>/UnitDelay1' */
  THA_SM_Ref_B.RelationalOperator7_jqco = THA_SM_Ref_DW.UnitDelay1_DSTATE_fw4h;

  /* Logic: '<S16>/LogicalOperator1' */
  THA_SM_Ref_B.RelationalOperator7_jqco = !THA_SM_Ref_B.RelationalOperator7_jqco;

  /* Logic: '<S16>/LogicalOperator' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.RelationalOperator1 &&
    THA_SM_Ref_B.RelationalOperator7_jqco);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant2'
   *  MinMax: '<S16>/Max'
   */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    /* MinMax: '<S16>/Max1' incorporates:
     *  Constant: '<S16>/Constant3'
     *  Constant: '<S3>/Constant7'
     */
    THA_SM_Ref_B.Max1 = fmaxf(KeTHA_s_ThaSampleTime, 1.0E-5F);

    /* Product: '<S16>/Divide' incorporates:
     *  Constant: '<S3>/Constant6'
     */
    THA_SM_Ref_B.Divide = (uint32_T)roundf(KeTHA_s_ChimeActvTime /
      THA_SM_Ref_B.Max1);
    THA_SM_Ref_B.Switch = THA_SM_Ref_B.Divide;
  } else {
    if (1U > THA_SM_Ref_B.UnitDelay) {
      /* MinMax: '<S16>/Max' incorporates:
       *  Constant: '<S16>/Constant2'
       */
      THA_SM_Ref_B.Max = 1U;
    } else {
      /* MinMax: '<S16>/Max' */
      THA_SM_Ref_B.Max = THA_SM_Ref_B.UnitDelay;
    }

    /* Sum: '<S16>/Add' incorporates:
     *  Constant: '<S16>/Constant2'
     */
    THA_SM_Ref_B.Add = THA_SM_Ref_B.Max - 1U;
    THA_SM_Ref_B.Switch = THA_SM_Ref_B.Add;
  }

  /* End of Switch: '<S16>/Switch' */

  /* RelationalOperator: '<S16>/RelationalOperator' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.Switch > 0U);

  /* Switch: '<S3>/Switch1' incorporates:
   *  Constant: '<S10>/Constant'
   *  Constant: '<S11>/Constant'
   *  Constant: '<S14>/Constant'
   *  Constant: '<S15>/Constant'
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Switch: '<S3>/Switch'
   *  Switch: '<S3>/Switch2'
   *  Switch: '<S3>/Switch5'
   */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    *rty_IeTHA_b_ChimeActvLhf = true;
    *rty_IeTHA_e_PamVol = TeTHA_e_PamVol_Medium;
    *rty_IeTHA_b_ChimeActvRhf = true;
    *rty_IeTHA_e_PamChimeTyp = TeTHA_e_PamChimeTyp_Type_11;
  } else {
    *rty_IeTHA_b_ChimeActvLhf = false;
    *rty_IeTHA_e_PamVol = TeTHA_e_PamVol_None;
    *rty_IeTHA_b_ChimeActvRhf = false;
    *rty_IeTHA_e_PamChimeTyp = TeTHA_e_PamChimeTyp_None;
  }

  /* End of Switch: '<S3>/Switch1' */

  /* UnitDelay: '<S99>/Unit Delay1' */
  THA_SM_Ref_B.UnitDelay_i52v = THA_SM_Ref_DW.UnitDelay1_DSTATE;

  /* SignalConversion: '<S2>/SignalCopy4' */
  MeTHA_px_HitchCplrPixDiffLat =
    rtu_MbTHA_ThaDetOutData->MeTHA_px_HitchCplrPixDiffLat;

  /* Switch: '<S99>/Switch5' */
  if (THA_SM_Ref_B.RelationalOperator4) {
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered =
      THA_SM_Ref_B.UnitDelay_i52v;
  } else {
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered =
      MeTHA_px_HitchCplrPixDiffLat;
  }

  /* End of Switch: '<S99>/Switch5' */

  /* Abs: '<S74>/Abs' */
  if (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered < 0) {
    if (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered <= MIN_int32_T) {
      THA_SM_Ref_B.Abs_cit4 = MAX_int32_T;
    } else {
      THA_SM_Ref_B.Abs_cit4 = -THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered;
    }
  } else {
    THA_SM_Ref_B.Abs_cit4 = THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered;
  }

  /* End of Abs: '<S74>/Abs' */

  /* Chart: '<S74>/LateralOffsetCheck' */
  THA_SM_Ref_B.MeTHA_b_EngageRejectReq_al0i = false;
  THA_SM_Ref_B.MeTHA_b_EngageRejectReq_al0i =
    (((THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered < 116) &&
      (THA_SM_Ref_B.Abs_cit4 > KsTHA_px_EngageRejLatOffset[0])) ||
     (((THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered >= 116) &&
       (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered < 156) &&
       (THA_SM_Ref_B.Abs_cit4 > KsTHA_px_EngageRejLatOffset[1])) ||
      (((THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered >= 156) &&
        (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered < 175) &&
        (THA_SM_Ref_B.Abs_cit4 > KsTHA_px_EngageRejLatOffset[2])) ||
       (((THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered >= 175) &&
         (THA_SM_Ref_B.Abs_cit4 > KsTHA_px_EngageRejLatOffset[3])) ||
        THA_SM_Ref_B.MeTHA_b_EngageRejectReq_al0i))));

  /* Switch: '<S99>/Switch1' incorporates:
   *  Constant: '<S99>/Constant2'
   *  Switch: '<S99>/Switch3'
   */
  if (THA_SM_Ref_B.RelationalOperator5) {
    THA_SM_Ref_B.Switch1 = KeTHA_s_HitchDetStsBufEnabled;
  } else {
    if (THA_SM_Ref_B.LogicalOperator) {
      /* Switch: '<S99>/Switch3' incorporates:
       *  Constant: '<S99>/Constant6'
       */
      THA_SM_Ref_B.Switch3 = KeTHA_s_HitchDetStsBufEngaged;
    } else {
      /* Switch: '<S99>/Switch3' incorporates:
       *  Constant: '<S99>/Constant7'
       */
      THA_SM_Ref_B.Switch3 = 0.0F;
    }

    THA_SM_Ref_B.Switch1 = THA_SM_Ref_B.Switch3;
  }

  /* End of Switch: '<S99>/Switch1' */

  /* SignalConversion: '<S2>/SignalCopy' */
  MeTHA_e_HitchDetctStatus = rtu_MbTHA_ThaDetOutData->MeTHA_e_HitchDetctStatus;

  /* Chart: '<S99>/HitchDetStsHyst' */
  if ((uint32_T)THA_SM_Ref_DW.is_active_c2_THA_SM_Ref == 0U) {
    THA_SM_Ref_DW.is_active_c2_THA_SM_Ref = 1U;
    THA_SM_Ref_DW.is_c2_THA_SM_Ref = THA_SM_Ref_IN_init_state;
    THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered = MeTHA_e_HitchDetctStatus;
    THA_SM_Ref_DW.local_status = MeTHA_e_HitchDetctStatus;
  } else if ((uint32_T)THA_SM_Ref_DW.is_c2_THA_SM_Ref ==
             THA_SM_Ref_IN_counter_state) {
    if ((THA_SM_Ref_DW.time_count >= THA_SM_Ref_B.Switch1) ||
        (MeTHA_e_HitchDetctStatus != TeTHA_e_HitchDetctStatus_Not_Detected)) {
      THA_SM_Ref_DW.is_c2_THA_SM_Ref = THA_SM_Ref_IN_init_state;
      THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered = MeTHA_e_HitchDetctStatus;
      THA_SM_Ref_DW.local_status = MeTHA_e_HitchDetctStatus;
    } else {
      THA_SM_Ref_DW.time_count += THA_SM_Ref_B.Saturation;
    }
  } else {
    /* case IN_init_state: */
    if (MeTHA_e_HitchDetctStatus == TeTHA_e_HitchDetctStatus_Not_Detected) {
      THA_SM_Ref_DW.is_c2_THA_SM_Ref = THA_SM_Ref_IN_counter_state;
      THA_SM_Ref_DW.local_status = MeTHA_e_HitchDetctStatus;
      THA_SM_Ref_DW.time_count = THA_SM_Ref_B.Saturation;
    } else {
      if (MeTHA_e_HitchDetctStatus != THA_SM_Ref_DW.local_status) {
        THA_SM_Ref_DW.is_c2_THA_SM_Ref = THA_SM_Ref_IN_init_state;
        THA_SM_Ref_B.MeTHA_e_HitchDetStsFiltered = MeTHA_e_HitchDetctStatus;
        THA_SM_Ref_DW.local_status = MeTHA_e_HitchDetctStatus;
      }
    }
  }

  /* End of Chart: '<S99>/HitchDetStsHyst' */

  /* SignalConversion: '<S2>/SignalCopy9' */
  MeSVS_b_ViewZoomSts = rtu_MbTHA_HmiSvsOutData->MeSVS_b_ViewZoomSts;

  /* UnitDelay: '<S99>/Unit Delay2' */
  THA_SM_Ref_B.Switch3_ajqq = THA_SM_Ref_DW.UnitDelay2_DSTATE;

  /* SignalConversion: '<S2>/SignalCopy2' */
  MeTHA_deg_CplrAng = rtu_MbTHA_ThaDetOutData->MeTHA_deg_CplrAng;

  /* Switch: '<S99>/Switch6' */
  if (THA_SM_Ref_B.RelationalOperator4) {
    THA_SM_Ref_B.MeTHA_deg_CplrAngFiltered = THA_SM_Ref_B.Switch3_ajqq;
  } else {
    THA_SM_Ref_B.MeTHA_deg_CplrAngFiltered = MeTHA_deg_CplrAng;
  }

  /* End of Switch: '<S99>/Switch6' */

  /* Abs: '<S6>/Abs' */
  THA_SM_Ref_B.Abs = fabsf(THA_SM_Ref_B.MeTHA_deg_CplrAngFiltered);

  /* SignalConversion: '<S2>/SignalCopy11' */
  MeSVS_b_THAScrTchSts = rtu_MbTHA_HmiSvsOutData->MeSVS_b_THAScrTchSts;

  /* SignalConversion: '<S2>/SignalCopy7' */
  MeSVS_e_THAScrResp = rtu_MbTHA_HmiSvsOutData->MeSVS_e_THAScrResp;

  /* SignalConversion: '<S2>/SignalCopy39' */
  MeSVS_b_THAAbortReq = rtu_MbTHA_HmiSvsOutData->MeSVS_b_THAAbortReq;

  /* SignalConversion: '<S2>/SignalCopy41' */
  THA_SM_Ref_B.MeTHA_b_CplrAngFound =
    rtu_MbTHA_ThaDetOutData->MeTHA_b_CplrAngFound;

  /* Chart: '<S6>/THA_HMI_Logic_Flow' incorporates:
   *  Constant: '<S6>/Constant3'
   */
  if (THA_SM_Ref_DW.temporalCounter_i1_gafy < MAX_uint32_T) {
    THA_SM_Ref_DW.temporalCounter_i1_gafy++;
  }

  if ((uint32_T)THA_SM_Ref_DW.is_active_c1_THA_SM_Ref == 0U) {
    THA_SM_Ref_DW.is_active_c1_THA_SM_Ref = 1U;
    THA_SM_Ref_DW.is_c1_THA_SM_Ref = THA_SM_Ref_IN_THA_Normal;
    THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
    THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
    *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
    *rty_MeTHA_b_UsrHitchCnfm = false;
    *rty_MeTHA_b_UsrCplrSelCnfm = false;
  } else if ((uint32_T)THA_SM_Ref_DW.is_c1_THA_SM_Ref == THA_SM_Ref_IN_THA_Fault)
  {
    if (((THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply !=
          TeVBII_e_GearEngagedForDsply_R) &&
         (THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply !=
          TeVBII_e_GearEngagedForDsply_SNA) && (*rty_MeTHA_e_THAStateInfo !=
          TeTHA_e_THAStateInfo_Faulted)) || ((real32_T)(uint32_T)(int32_T)
         ((int32_T)THA_SM_Ref_DW.temporalCounter_i1_gafy * 3) >=
         KeTHA_s_HmiFaultPopUpDur * 100.0F)) {
      THA_SM_Ref_DW.is_c1_THA_SM_Ref = THA_SM_Ref_IN_THA_Normal;
      THA_SM_Ref_DW.is_THA_Normal = THA_SM_Ref_IN_Init;
      THA_SM_Ref_DW.is_Init = THA_SM_Ref_IN_Idle_cuxx;
      *rty_MeTHA_e_ScreenRequest = TeTHA_e_ScreenRequest_THA_Default;
      *rty_MeTHA_b_UsrHitchCnfm = false;
      *rty_MeTHA_b_UsrCplrSelCnfm = false;
    }
  } else {
    /* case IN_THA_Normal: */
    THA_SM_Ref_THA_Normal(rty_MeTHA_e_THAStateInfo, rty_MeTHA_e_ScreenRequest,
                          rty_MeTHA_b_UsrHitchCnfm, rty_MeTHA_b_UsrCplrSelCnfm,
                          rty_MeTHA_b_UsrInputTimeOut);
  }

  /* End of Chart: '<S6>/THA_HMI_Logic_Flow' */

  /* SignalConversion: '<S4>/SignalCopy19' */
  *rty_MeTHA_b_ViewZoomSts = MeSVS_b_ViewZoomSts;

  /* RelationalOperator: '<S74>/RelationalOperator5' incorporates:
   *  Constant: '<S77>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Enabled_Selection);

  /* Logic: '<S74>/Logical Operator' incorporates:
   *  Constant: '<S74>/Constant16'
   */
  THA_SM_Ref_B.MeTHA_b_EngageRejectReq = (KeTHA_b_EnblEngageRejectReq &&
    THA_SM_Ref_B.RelationalOperator7_jqco &&
    THA_SM_Ref_B.MeTHA_b_EngageRejectReq_al0i);

  /* RelationalOperator: '<S75>/RelationalOperator5' incorporates:
   *  Constant: '<S85>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Complete);

  /* RelationalOperator: '<S75>/RelationalOperator1' incorporates:
   *  Constant: '<S79>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.IeVBII_e_VehEPBSts ==
    TeVBII_e_VehEPBSts_Applied);

  /* Logic: '<S75>/LogicalOperator2' */
  THA_SM_Ref_B.RelationalOperator2 = !THA_SM_Ref_B.RelationalOperator2_hq3h;

  /* Logic: '<S75>/LogicalOperator1' */
  THA_SM_Ref_B.RelationalOperator2 = (THA_SM_Ref_B.RelationalOperator7_jqco &&
    THA_SM_Ref_B.RelationalOperator2);

  /* Switch: '<S75>/Switch5' incorporates:
   *  Constant: '<S83>/Constant'
   *  Constant: '<S84>/Constant'
   */
  if (THA_SM_Ref_B.RelationalOperator2) {
    *rty_IeTHA_e_EPBReq = TeTHA_e_EPBReq_EPB_Requested;
  } else {
    *rty_IeTHA_e_EPBReq = TeTHA_e_EPBReq_No_Request;
  }

  /* End of Switch: '<S75>/Switch5' */

  /* RelationalOperator: '<S75>/RelationalOperator2' incorporates:
   *  Constant: '<S80>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2 = (*rtu_IeTHA_e_THASteerTrqReqPrev ==
    TeTHA_e_THASteerTrqReq_False);

  /* RelationalOperator: '<S75>/RelationalOperator3' incorporates:
   *  Constant: '<S81>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator3_anin = (THA_SM_Ref_B.IeVBII_e_BsmTHABrkResp ==
    TeVBII_e_BsmTHABrkResp_Off);

  /* RelationalOperator: '<S75>/RelationalOperator4' incorporates:
   *  Constant: '<S82>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator4 = (THA_SM_Ref_B.IeVBII_e_EcmTHAResp ==
    TeVBII_e_EcmTHAResp_Off);

  /* Logic: '<S75>/LogicalOperator' */
  MeTHA_b_THACompleteHMITrig = (THA_SM_Ref_B.RelationalOperator7_jqco &&
    THA_SM_Ref_B.RelationalOperator2_hq3h && THA_SM_Ref_B.RelationalOperator2 &&
    THA_SM_Ref_B.RelationalOperator3_anin && THA_SM_Ref_B.RelationalOperator4);

  /* RelationalOperator: '<S8>/RelationalOperator3' incorporates:
   *  Constant: '<S149>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Complete);

  /* Logic: '<S8>/LogicalOperator5' */
  THA_SM_Ref_B.LogicalOperator5 = (THA_SM_Ref_B.RelationalOperator7_jqco ||
    THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp);

  /* SignalConversion: '<S2>/SignalCopy54' */
  THA_SM_Ref_B.IeAP_e_FrntRearParkSts =
    rtu_MbTHA_ApSmOutData->IeAP_e_FrntRearParkSts;

  /* RelationalOperator: '<S8>/RelationalOperator5' incorporates:
   *  Constant: '<S144>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.IeAP_e_FrntRearParkSts ==
    TeAP_e_FrntRearParkSts_FT_OFF_RR_ON);

  /* RelationalOperator: '<S8>/RelationalOperator2' incorporates:
   *  Constant: '<S148>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.IeAP_e_FrntRearParkSts ==
    TeAP_e_FrntRearParkSts_FT_ON_RR_ON);

  /* Logic: '<S8>/LogicalOperator' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.RelationalOperator7_jqco
    || THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* SignalConversion: '<S2>/SignalCopy48' */
  MePRX_b_ParkWithStop = rtu_MbTHA_ProxiMgrOutData->MePRX_b_ParkWithStop;

  /* Logic: '<S8>/LogicalOperator1' */
  *rty_MeTHA_b_EnblRearParkAsstTrg = (MePRX_b_ParkWithStop &&
    THA_SM_Ref_B.RelationalOperator7_jqco);

  /* RelationalOperator: '<S8>/RelationalOperator1' */
  THA_SM_Ref_B.RelationalOperator7_jqco =
    (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered <=
     THA_SM_Ref_B.MbTHASmVc_InputsFromVrntTunParam.KeTHA_px_RearBrkSuppDist);

  /* Logic: '<S8>/LogicalOperator6' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = !THA_SM_Ref_B.RelationalOperator7_jqco;

  /* UnitDelay: '<S150>/UnitDelay3' */
  THA_SM_Ref_B.Switch3_ajqq = THA_SM_Ref_DW.UnitDelay3_DSTATE_mxty;

  /* Switch: '<S150>/Switch1' incorporates:
   *  Constant: '<S150>/Constant4'
   */
  if (THA_SM_Ref_B.RelationalOperator2_hq3h) {
    THA_SM_Ref_B.Switch3_ajqq = 0.0F;
  }

  /* End of Switch: '<S150>/Switch1' */

  /* Sum: '<S150>/Sum1' incorporates:
   *  Constant: '<S8>/Constant7'
   */
  THA_SM_Ref_B.Sum1 = KeTHA_s_DistConfDur - THA_SM_Ref_B.Switch3_ajqq;

  /* Gain: '<S150>/Gain' incorporates:
   *  Constant: '<S8>/Constant3'
   */
  THA_SM_Ref_B.Switch3_pas4 = 0.99F * KeTHA_s_ThaSampleTime;

  /* RelationalOperator: '<S150>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator_h4jm = (THA_SM_Ref_B.Sum1 <
    THA_SM_Ref_B.Switch3_pas4);

  /* Logic: '<S8>/LogicalOperator2' incorporates:
   *  Logic: '<S8>/LogicalOperator3'
   *  Switch: '<S8>/Switch'
   */
  RelationalOperator2_hq3h_tmp = (THA_SM_Ref_B.LogicalOperator5 &&
    (*rty_MeTHA_b_EnblRearParkAsstTrg));
  THA_SM_Ref_B.RelationalOperator2_hq3h = (RelationalOperator2_hq3h_tmp &&
    THA_SM_Ref_B.RelationalOperator_h4jm);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S145>/Constant'
   */
  if (THA_SM_Ref_B.RelationalOperator2_hq3h) {
    *rty_MeTHA_e_RearBrkSupprInfo =
      TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking;
  } else {
    /* Logic: '<S8>/LogicalOperator4' */
    THA_SM_Ref_B.LogicalOperator3 = !THA_SM_Ref_B.RelationalOperator_h4jm;

    /* Logic: '<S8>/LogicalOperator3' */
    THA_SM_Ref_B.LogicalOperator3 = (RelationalOperator2_hq3h_tmp &&
      THA_SM_Ref_B.LogicalOperator3);

    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S146>/Constant'
     *  Constant: '<S147>/Constant'
     */
    if (THA_SM_Ref_B.LogicalOperator3) {
      THA_SM_Ref_B.Switch1_oaul = TeTHA_e_RearBrkSupprInfo_No_Suppression;
    } else {
      THA_SM_Ref_B.Switch1_oaul = TeTHA_e_RearBrkSupprInfo_Invalid;
    }

    /* End of Switch: '<S8>/Switch1' */
    *rty_MeTHA_e_RearBrkSupprInfo = THA_SM_Ref_B.Switch1_oaul;
  }

  /* Switch: '<S150>/Switch3' incorporates:
   *  Constant: '<S150>/Constant2'
   *  Constant: '<S8>/Constant3'
   */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S150>/Switch3' */

  /* Sum: '<S150>/Sum' */
  THA_SM_Ref_B.Switch3_ajqq += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S150>/MinMax' incorporates:
   *  Constant: '<S8>/Constant7'
   */
  THA_SM_Ref_B.MinMax = fminf(THA_SM_Ref_B.Switch3_ajqq, KeTHA_s_DistConfDur);

  /* RelationalOperator: '<S9>/RelationalOperator5' incorporates:
   *  Constant: '<S151>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged_Inquiry);

  /* RelationalOperator: '<S9>/RelationalOperator1' incorporates:
   *  Constant: '<S152>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Complete);

  /* Logic: '<S9>/Logical Operator' */
  *rty_MeTHA_b_TrlrCplrStatus = (THA_SM_Ref_B.RelationalOperator7_jqco ||
    THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* RelationalOperator: '<S9>/RelationalOperator4' incorporates:
   *  Constant: '<S154>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator7_jqco = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Engaged);

  /* UnitDelay: '<S9>/Unit Delay1' */
  THA_SM_Ref_B.UnitDelay1_kl5n = THA_SM_Ref_DW.UnitDelay1_DSTATE_ggez;

  /* RelationalOperator: '<S9>/RelationalOperator3' incorporates:
   *  Constant: '<S154>/Constant'
   */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (THA_SM_Ref_B.UnitDelay1_kl5n !=
    TeTHA_e_THAStateInfo_Engaged);

  /* Logic: '<S9>/Logical Operator1' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (THA_SM_Ref_B.RelationalOperator7_jqco
    && THA_SM_Ref_B.RelationalOperator2_hq3h);

  /* UnitDelay: '<S9>/Unit Delay' */
  THA_SM_Ref_B.UnitDelay_esis = THA_SM_Ref_DW.UnitDelay_DSTATE_coxe;

  /* Switch: '<S9>/Switch' */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt =
      THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered;
  } else {
    /* RelationalOperator: '<S9>/RelationalOperator7' incorporates:
     *  Constant: '<S156>/Constant'
     */
    THA_SM_Ref_B.RelationalOperator7 = (*rty_MeTHA_e_THAStateInfo !=
      TeTHA_e_THAStateInfo_Engaged_Inquiry);

    /* RelationalOperator: '<S9>/RelationalOperator6' incorporates:
     *  Constant: '<S155>/Constant'
     */
    THA_SM_Ref_B.RelationalOperator6 = (*rty_MeTHA_e_THAStateInfo !=
      TeTHA_e_THAStateInfo_Engaged_Delta);

    /* RelationalOperator: '<S9>/RelationalOperator8' incorporates:
     *  Constant: '<S154>/Constant'
     */
    THA_SM_Ref_B.LogicalOperator2 = (*rty_MeTHA_e_THAStateInfo !=
      TeTHA_e_THAStateInfo_Engaged);

    /* Logic: '<S9>/Logical Operator2' */
    THA_SM_Ref_B.LogicalOperator2 = (THA_SM_Ref_B.LogicalOperator2 &&
      THA_SM_Ref_B.RelationalOperator6 && THA_SM_Ref_B.RelationalOperator7);

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant'
     */
    if (THA_SM_Ref_B.LogicalOperator2) {
      THA_SM_Ref_B.Switch1_hemj = 0;
    } else {
      THA_SM_Ref_B.Switch1_hemj = THA_SM_Ref_B.UnitDelay_esis;
    }

    /* End of Switch: '<S9>/Switch1' */
    *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt = THA_SM_Ref_B.Switch1_hemj;
  }

  /* End of Switch: '<S9>/Switch' */

  /* RelationalOperator: '<S9>/RelationalOperator2' incorporates:
   *  Constant: '<S153>/Constant'
   */
  *rty_MeTHA_b_THAAbortStatus = (*rty_MeTHA_e_THAStateInfo ==
    TeTHA_e_THAStateInfo_Faulted);

  /* Switch: '<S44>/Switch3' incorporates:
   *  Constant: '<S18>/Constant4'
   *  Constant: '<S44>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator4) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S44>/Switch3' */

  /* Sum: '<S44>/Sum' */
  THA_SM_Ref_B.Gain += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S44>/MinMax' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  THA_SM_Ref_B.MinMax_nhme = fminf(THA_SM_Ref_B.Gain, KeTHA_s_SpdOvrdTimeout);

  /* UnitDelay: '<S18>/Unit Delay1' */
  THA_SM_Ref_B.RelationalOperator7_jqco = THA_SM_Ref_DW.UnitDelay1_DSTATE_gih2;

  /* Logic: '<S18>/Logical Operator' */
  THA_SM_Ref_B.RelationalOperator7_jqco = !THA_SM_Ref_B.RelationalOperator7_jqco;

  /* UnitDelay: '<S18>/Unit Delay' */
  THA_SM_Ref_B.UnitDelay_i52v = THA_SM_Ref_DW.UnitDelay_DSTATE_bhgc;

  /* RelationalOperator: '<S18>/RelationalOperator2' */
  THA_SM_Ref_B.RelationalOperator2_hq3h = (MeTHA_px_HitchCplrPixDiffLong <
    THA_SM_Ref_B.UnitDelay_i52v);

  /* UnitDelay: '<S43>/UnitDelay3' */
  THA_SM_Ref_B.Switch3_pas4 = THA_SM_Ref_DW.UnitDelay3_DSTATE_nlty;

  /* Switch: '<S43>/Switch1' incorporates:
   *  Constant: '<S43>/Constant4'
   */
  if (THA_SM_Ref_B.RelationalOperator2_hq3h) {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S43>/Switch1' */

  /* Sum: '<S43>/Sum1' incorporates:
   *  Constant: '<S18>/Constant22'
   */
  THA_SM_Ref_B.Switch3_ajqq = KeTHA_s_TrajLostDur - THA_SM_Ref_B.Switch3_pas4;

  /* Gain: '<S43>/Gain' incorporates:
   *  Constant: '<S18>/Constant3'
   */
  THA_SM_Ref_B.Gain = 0.99F * KeTHA_s_ThaSampleTime;

  /* RelationalOperator: '<S43>/RelationalOperator' */
  THA_SM_Ref_B.RelationalOperator_g1ma = (THA_SM_Ref_B.Switch3_ajqq <
    THA_SM_Ref_B.Gain);

  /* Logic: '<S18>/LogicalOperator5' */
  THA_SM_Ref_B.LogicalOperator5_gtpq = (THA_SM_Ref_B.RelationalOperator19 &&
    THA_SM_Ref_B.RelationalOperator7_jqco &&
    THA_SM_Ref_B.RelationalOperator_g1ma);

  /* RelationalOperator: '<S18>/RelationalOperator7' */
  THA_SM_Ref_B.RelationalOperator7_jqco = (MeTHA_px_HitchCplrPixDiffLong >
    THA_SM_Ref_B.UnitDelay_i52v);

  /* Switch: '<S43>/Switch3' incorporates:
   *  Constant: '<S18>/Constant3'
   *  Constant: '<S43>/Constant2'
   */
  if (THA_SM_Ref_B.RelationalOperator7_jqco) {
    THA_SM_Ref_B.Switch3_ajqq = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_ajqq = 0.0F;
  }

  /* End of Switch: '<S43>/Switch3' */

  /* Sum: '<S43>/Sum' */
  THA_SM_Ref_B.Switch3_pas4 += THA_SM_Ref_B.Switch3_ajqq;

  /* MinMax: '<S43>/MinMax' incorporates:
   *  Constant: '<S18>/Constant22'
   */
  THA_SM_Ref_B.MinMax_owtc = fminf(THA_SM_Ref_B.Switch3_pas4,
    KeTHA_s_TrajLostDur);

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S22>/Constant2'
   *  Constant: '<S5>/Constant3'
   */
  if (THA_SM_Ref_B.LogicalOperator2_a3nq) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S22>/Switch3' */

  /* Gain: '<S96>/Gain' incorporates:
   *  Sum: '<S22>/Sum'
   */
  THA_SM_Ref_B.Sum_njfy += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S22>/MinMax' incorporates:
   *  Constant: '<S5>/Constant22'
   */
  THA_SM_Ref_B.MinMax_doph = fminf(THA_SM_Ref_B.Sum_njfy,
    KeTHA_s_GearEnggConfDur);

  /* SignalConversion: '<S4>/SignalCopy1' */
  *rty_MeTHA_b_CamOccluLoLi = MeTHA_b_FidDLDAbort;

  /* Switch: '<S36>/Switch3' incorporates:
   *  Constant: '<S17>/Constant3'
   *  Constant: '<S36>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator2_ehda) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S36>/Switch3' */

  /* Sum: '<S36>/Sum' */
  THA_SM_Ref_B.Sum_oetd += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S36>/MinMax' incorporates:
   *  Constant: '<S17>/Constant22'
   */
  THA_SM_Ref_B.MinMax_pkc0 = fminf(THA_SM_Ref_B.Sum_oetd, KeTHA_s_MnvTimeout);

  /* Switch: '<S117>/Switch3' incorporates:
   *  Constant: '<S108>/Constant3'
   *  Constant: '<S117>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator6) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S117>/Switch3' */

  /* Sum: '<S117>/Sum' */
  THA_SM_Ref_B.Sum_ndvb += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S117>/MinMax' incorporates:
   *  Constant: '<S108>/Constant1'
   */
  THA_SM_Ref_B.MinMax_mgiu = fminf(THA_SM_Ref_B.Sum_ndvb, KeTHA_s_BsmHandshake);

  /* Switch: '<S116>/Switch3' incorporates:
   *  Constant: '<S108>/Constant2'
   *  Constant: '<S116>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator6) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S116>/Switch3' */

  /* Sum: '<S116>/Sum' */
  THA_SM_Ref_B.Sum_jrtb += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S116>/MinMax' incorporates:
   *  Constant: '<S108>/Constant16'
   */
  THA_SM_Ref_B.MinMax_mfsu = fminf(THA_SM_Ref_B.Sum_jrtb, KeTHA_s_EcmHandshake);

  /* Switch: '<S126>/Switch3' incorporates:
   *  Constant: '<S109>/Constant3'
   *  Constant: '<S126>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator2_m1ul) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S126>/Switch3' */

  /* Sum: '<S126>/Sum' */
  THA_SM_Ref_B.Sum_jetc += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S126>/MinMax' incorporates:
   *  Constant: '<S109>/Constant16'
   */
  THA_SM_Ref_B.MinMax_bt4j = fminf(THA_SM_Ref_B.Sum_jetc, KeTHA_s_EpsHandshake);

  /* Switch: '<S109>/Switch1' incorporates:
   *  Constant: '<S119>/Constant'
   *  Constant: '<S125>/Constant'
   */
  if (THA_SM_Ref_B.Switch_a0h1) {
    *rty_MeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_True;
  } else {
    *rty_MeTHA_e_THASteerTrqReq = TeTHA_e_THASteerTrqReq_False;
  }

  /* End of Switch: '<S109>/Switch1' */

  /* Switch: '<S108>/Switch1' incorporates:
   *  Constant: '<S113>/Constant'
   *  Constant: '<S114>/Constant'
   */
  if (THA_SM_Ref_B.MeTHA_b_THAEnggdNotSupp) {
    *rty_IeTHA_e_THASpdLimReq = TeTHA_e_THASpdLimReq_Requested;
  } else {
    *rty_IeTHA_e_THASpdLimReq = TeTHA_e_THASpdLimReq_No_Request;
  }

  /* End of Switch: '<S108>/Switch1' */

  /* Switch: '<S96>/Switch3' incorporates:
   *  Constant: '<S88>/Constant3'
   *  Constant: '<S96>/Constant2'
   */
  if (THA_SM_Ref_B.LogicalOperator3_edxj) {
    THA_SM_Ref_B.Switch3_pas4 = KeTHA_s_ThaSampleTime;
  } else {
    THA_SM_Ref_B.Switch3_pas4 = 0.0F;
  }

  /* End of Switch: '<S96>/Switch3' */

  /* Sum: '<S96>/Sum' */
  THA_SM_Ref_B.Sum += THA_SM_Ref_B.Switch3_pas4;

  /* MinMax: '<S96>/MinMax' incorporates:
   *  Constant: '<S88>/Constant7'
   */
  THA_SM_Ref_B.MinMax_aayr = fminf(THA_SM_Ref_B.Sum, KeTHA_s_Standstill);

  /* RelationalOperator: '<S90>/RelationalOperator3' */
  THA_SM_Ref_B.RelationalOperator3 =
    (THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered <=
     THA_SM_Ref_B.MbTHASmVc_InputsFromVrntTunParam.KeTHA_px_HitchCplrDeltaThd2);

  /* Constant: '<S3>/Constant2' */
  *rty_IeTHA_b_ChimeActvLhr = false;

  /* Constant: '<S3>/Constant3' */
  *rty_IeTHA_b_ChimeActvRhr = false;

  /* Constant: '<S12>/Constant' */
  *rty_IeTHA_e_PamChimeRepRateSts = TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz;

  /* SignalConversion: '<S2>/SignalCopy10' */
  MeSVS_b_THAMnvrStartBtnPrsd =
    rtu_MbTHA_HmiSvsOutData->MeSVS_b_THAMnvrStartBtnPrsd;

  /* Update for UnitDelay: '<S16>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_hgbb = THA_SM_Ref_B.Switch;

  /* Update for UnitDelay: '<S1>/UnitDelay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_co0c = *rty_MeTHA_e_THAStateInfo;

  /* Update for UnitDelay: '<S99>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_jxgs =
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLongFiltered;

  /* Update for UnitDelay: '<S90>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_fbjp = THA_SM_Ref_B.RelationalOperator3;

  /* Update for UnitDelay: '<S96>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE = THA_SM_Ref_B.MinMax_aayr;

  /* Update for UnitDelay: '<S109>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_d5cr = THA_SM_Ref_B.LogicalOperator1;

  /* Update for UnitDelay: '<S127>/UnitDelay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_kgyy = THA_SM_Ref_B.Switch_a0h1;

  /* Update for UnitDelay: '<S126>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_bz1l = THA_SM_Ref_B.MinMax_bt4j;

  /* Update for UnitDelay: '<S116>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_ipup = THA_SM_Ref_B.MinMax_mfsu;

  /* Update for UnitDelay: '<S117>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_hyrp = THA_SM_Ref_B.MinMax_mgiu;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE = THA_SM_Ref_B.IeVBII_kph_VehSpeedVSOSig;

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_cn3d =
    THA_SM_Ref_B.IeVBII_e_GearEngagedForDsply;

  /* Update for UnitDelay: '<S17>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE_kwqb = THA_SM_Ref_B.IeVBII_e_TchScrSts;

  /* Update for UnitDelay: '<S36>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_fkls = THA_SM_Ref_B.MinMax_pkc0;

  /* Update for UnitDelay: '<S22>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_gjgb = THA_SM_Ref_B.MinMax_doph;

  /* Update for UnitDelay: '<S44>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_dasz = THA_SM_Ref_B.MinMax_nhme;

  /* Update for UnitDelay: '<S1>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_lybn = *rty_MeTHA_e_ScreenRequest;

  /* Update for UnitDelay: '<S16>/UnitDelay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_fw4h = THA_SM_Ref_B.RelationalOperator1;

  /* Update for UnitDelay: '<S99>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE =
    THA_SM_Ref_B.MeTHA_px_HitchCplrPixDiffLatFiltered;

  /* Update for UnitDelay: '<S99>/Unit Delay2' */
  THA_SM_Ref_DW.UnitDelay2_DSTATE = THA_SM_Ref_B.MeTHA_deg_CplrAngFiltered;

  /* Update for UnitDelay: '<S150>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_mxty = THA_SM_Ref_B.MinMax;

  /* Update for UnitDelay: '<S9>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_ggez = *rty_MeTHA_e_THAStateInfo;

  /* Update for UnitDelay: '<S9>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_coxe = *rty_MeTHA_px_HitchCplrPixDiffLongAtStrt;

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  THA_SM_Ref_DW.UnitDelay1_DSTATE_gih2 = THA_SM_Ref_B.RelationalOperator_g1ma;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  THA_SM_Ref_DW.UnitDelay_DSTATE_bhgc = MeTHA_px_HitchCplrPixDiffLong;

  /* Update for UnitDelay: '<S43>/UnitDelay3' */
  THA_SM_Ref_DW.UnitDelay3_DSTATE_nlty = THA_SM_Ref_B.MinMax_owtc;
}

/* Model initialize function */
void THA_SM_Ref_initialize(void)
{
  /* Registration code */

  /* block I/O */
  {
    THA_SM_Ref_B.IeVBII_e_VehStandStillSts = TeVBII_e_VehStandStillSts_False;
    THA_SM_Ref_B.IeVBII_e_EssEngState = TeVBII_e_EssEngState_ENS_STOPPED;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
