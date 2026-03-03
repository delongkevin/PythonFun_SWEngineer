/*
 * File: THAFeatureOutputs.h
 *
 * Code generated for Simulink model 'THA_SWC'.
 *
 * Model version                  : 1.1595
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:43:08 2025
 */

#ifndef RTW_HEADER_THAFeatureOutputs_h_
#define RTW_HEADER_THAFeatureOutputs_h_
#include "TeTHA_e_THAState.h"
#include "TeTHA_e_THASpdLimReq.h"
#include "TeTHA_e_PamVol.h"
#include "TeTHA_e_PamChimeTyp.h"
#include "TeTHA_e_PamChimeRepRateSts.h"
#include "TeTHA_e_THASteerTrqReq.h"
#include "TeTHA_e_THARmpUpDwnSpd.h"
#include "TeTHA_e_EPBReq.h"
#include "TeTHA_e_THAStateInfo.h"
#include "TeTHA_e_ScreenRequest.h"
#include "TeTHA_e_RearBrkSupprInfo.h"
#include "rtwtypes.h"

/* THA SM VC output bus. */
typedef struct {
  /* THA Steering Torque in Nm. */
  real32_T IeTHA_M_THASteerTrqInfo;

  /* THA Steering Damping */
  real32_T IeTHA_pct_THAStrDamp;
  real32_T MeTHA_deg_RoadWhlAng;

  /* Current trailer hitch assist maneuver state
     0 = Initial
     1 = Idle
     2 = Enabled
     3 = Engaged
     4 = Complete
     5 = Faulted
     7 = SNA */
  TeTHA_e_THAState IeTHA_e_THAState;

  /* THA requested speed limit
     0 = No_Request
     1 = Requested
     3 = SNA */
  TeTHA_e_THASpdLimReq IeTHA_e_THASpdLimReq;

  /* Pam Volume signal
     0 = None
     1 = Low
     2 = Medium
     3 = High */
  TeTHA_e_PamVol IeTHA_e_PamVol;

  /* Pam chime type
     0 = None
     1 = Type_1
     2 = Type_2
     3 = Type_3
     4 = Type_4
     5 = Type_5
     6 = Type_6
     7 = Type_7
     8 = Type_8
     9 = Type_9
     10 = Type_10
     11 = Type_11
     12 = Type_12
     13 = Type_13
     14 = Type_14
     15 = Type_15 */
  TeTHA_e_PamChimeTyp IeTHA_e_PamChimeTyp;

  /* PAM chime repetition rate
     0 = Continuous_0_Hz
     2 = Slow_2_Hz
     3 = Slow_3_Hz
     4 = Fast_4_Hz
     5 = Fast_5_Hz */
  TeTHA_e_PamChimeRepRateSts IeTHA_e_PamChimeRepRateSts;

  /* Trailer Hitch Assist steering torque request
     0 = False
     1 = True
     3 = SNA */
  TeTHA_e_THASteerTrqReq IeTHA_e_THASteerTrqReq;

  /* This signal indicates the ramp up and down speed */
  TeTHA_e_THARmpUpDwnSpd IeTHA_e_THARmpUpDwnSpd;

  /* THA EPB securement request.
     No_Request (0)
     EPB_Requested (1)
     SNA (3) */
  TeTHA_e_EPBReq IeTHA_e_EPBReq;

  /* THA States internal signal.
     0 -> Off
     1 -> Initial
     2 -> Idle
     3 -> Enabled
     4 -> Enabled Selection
     5 -> Engaged
     6 -> Engaged Delta
     7 -> Engaged Inquiry
     8 -> Complete
     9 -> Faulted
     10 -> SNA */
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;

  /* Trigger from THA Main SM to THA HMI & Detection.
     THA_Default = 0
     THA_Enable,
     THA_TCS_Msg1,
     THA_TCS_Msg2,
     THA_TCS_Msg3,
     THA_TCS_Msg4,
     THA_TCS_Msg5,
     THA_SM_Msg1,
     THA_SM_Msg2,
     THA_CM_Msg1,
     THA_CM_Msg2,
     THA_CM_Msg3,
     THA_CM_Msg4,
     THA_CM_Msg5,
     THA_CM_Msg6,
     THA_CM_Msg7,
     THA_CM_Msg8,
     THA_CM_Msg9,
     THA_CM_Msg10,
     THA_EOM_Msg1,
     THA_EOM_Msg2,
     THA_EOM_Msg3,
     THA_EOM_Msg4,
     THA_ERR_Msg1,
     THA_ERR_Msg2 */
  TeTHA_e_ScreenRequest MeTHA_e_ScreenRequest;

  /* THA Rear Braking Supression Info.
     0 - Invalid,
     1 - No_Suppression,
     2 - Suppress_Rear_Braking */
  TeTHA_e_RearBrkSupprInfo MeTHA_e_RearBrkSupprInfo;

  /* This signal indicates the chime activation request for the left hand, front audio speaker, or rear hardwired buzzer. */
  boolean_T IeTHA_b_ChimeActvLhf;

  /* This signal indicates the chime activation request for the right hand, front audio speaker, or rear hardwired buzzer. */
  boolean_T IeTHA_b_ChimeActvRhf;

  /* This signal indicates the chime activation request for the left hand, rear audio speaker, or rear hardwired buzzer. */
  boolean_T IeTHA_b_ChimeActvLhr;

  /* This signal indicates the chime activation request for the right hand, rear audio speaker, or rear hardwired buzzer. */
  boolean_T IeTHA_b_ChimeActvRhr;

  /* Enable Rear Park Assist signal from THA. */
  boolean_T MeTHA_b_EnblRearParkAsstTrg;

  /* Hitch confirmation by user from HMI. */
  boolean_T MeTHA_b_UsrHitchCnfm;

  /* Coupler selection confirmation by user from HMI. */
  boolean_T MeTHA_b_UsrCplrSelCnfm;

  /* Trailer Coupler Reached to Hitch location Status. */
  boolean_T MeTHA_b_TrlrCplrStatus;

  /* THA feature abort status. */
  boolean_T MeTHA_b_THAAbortStatus;
} TbTHASmVc_FeatureOutputs_t;

/* THA SM VC output bus. */
typedef struct {
  /* Longitudinal Pixel Y difference from hitch to coupler when THA is engaged. */
  int32_T MeTHA_px_HitchCplrPixDiffLongAtStrt;
  real32_T MeTHA_deg_RoadWhlAng;

  /* THA requested speed limit
     0 = No_Request
     1 = Requested
     3 = SNA */
  TeTHA_e_THASpdLimReq MeTHA_e_THASpdLimReq;

  /* Trailer Hitch Assist steering torque request
     0 = False
     1 = True
     3 = SNA */
  TeTHA_e_THASteerTrqReq MeTHA_e_THASteerTrqReq;

  /* This signal indicates the ramp up and down speed */
  TeTHA_e_THARmpUpDwnSpd MeTHA_e_THARmpUpDwnSpd;

  /* THA EPB securement request.
     No_Request (0)
     EPB_Requested (1)
     SNA (3) */
  TeTHA_e_EPBReq MeTHA_e_EPBReq;

  /* THA States internal signal.
     0 -> Off
     1 -> Initial
     2 -> Idle
     3 -> Enabled
     4 -> Enabled Selection
     5 -> Engaged
     6 -> Engaged Delta
     7 -> Engaged Inquiry
     8 -> Complete
     9 -> Faulted
     10 -> SNA */
  TeTHA_e_THAStateInfo MeTHA_e_THAStateInfo;

  /* Coupler selection confirmation by user from HMI. */
  boolean_T MeTHA_b_UsrCplrSelCnfm;

  /* Trailer Coupler Reached to Hitch location Status. */
  boolean_T MeTHA_b_TrlrCplrStatus;

  /* THA feature abort status. */
  boolean_T MeTHA_b_THAAbortStatus;

  /* Coupler selection confirmation by user from HMI. */
  boolean_T MeTHA_b_UsrInputTimeOut;

  /* THA feature abort status. */
  boolean_T MeTHA_b_ViewZoomSts;

  /* Trailer Coupler Reached to Hitch location Status. */
  boolean_T MeTHA_b_CamOccluLoLi;
} TbTHASmVc_DiagMgr_t;

#endif                                 /* RTW_HEADER_THAFeatureOutputs_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
