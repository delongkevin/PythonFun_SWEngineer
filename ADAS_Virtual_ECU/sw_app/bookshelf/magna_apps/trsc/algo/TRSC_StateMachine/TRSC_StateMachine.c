/*
 * File: TRSC_StateMachine.c
 *
 * Code generated for Simulink model 'TRSC_StateMachine'.
 *
 * Model version                  : 1.1744
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:51:14 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_StateMachine.h"
#include "TRSC_StateMachine_private.h"

/* Named constants for Chart: '<S2>/Chart' */
#define TRSC_StateMachine_IN_Active    ((uint8_T)1U)
#define TRSC_StateMachine_IN_ActiveHoldOver ((uint8_T)2U)
#define TRSC_StateMachine_IN_ButtonOff ((uint8_T)1U)
#define TRSC_StateMachine_IN_ButtonOn  ((uint8_T)2U)
#define TRSC_StateMachine_IN_CalFailed ((uint8_T)1U)
#define TRSC_StateMachine_IN_Calibration ((uint8_T)3U)
#define TRSC_StateMachine_IN_Calibration_Steps ((uint8_T)1U)
#define TRSC_StateMachine_IN_ClearDisp10 ((uint8_T)1U)
#define TRSC_StateMachine_IN_ClearDisp11 ((uint8_T)2U)
#define TRSC_StateMachine_IN_ClearDisp12 ((uint8_T)3U)
#define TRSC_StateMachine_IN_ClearDisp13 ((uint8_T)4U)
#define TRSC_StateMachine_IN_ClearDisp15 ((uint8_T)5U)
#define TRSC_StateMachine_IN_ClearDisp19 ((uint8_T)6U)
#define TRSC_StateMachine_IN_ClearDisp20 ((uint8_T)7U)
#define TRSC_StateMachine_IN_ClearDisp21 ((uint8_T)8U)
#define TRSC_StateMachine_IN_ClearDisp22 ((uint8_T)9U)
#define TRSC_StateMachine_IN_ClearDisp23 ((uint8_T)10U)
#define TRSC_StateMachine_IN_ClearDisp3 ((uint8_T)11U)
#define TRSC_StateMachine_IN_ClearDisp5 ((uint8_T)12U)
#define TRSC_StateMachine_IN_ClearDisp6 ((uint8_T)13U)
#define TRSC_StateMachine_IN_ClearDisp7 ((uint8_T)14U)
#define TRSC_StateMachine_IN_ClearDisp8 ((uint8_T)15U)
#define TRSC_StateMachine_IN_ClearDisp9 ((uint8_T)16U)
#define TRSC_StateMachine_IN_ClearSNA  ((uint8_T)17U)
#define TRSC_StateMachine_IN_Complete  ((uint8_T)2U)
#define TRSC_StateMachine_IN_Default   ((uint8_T)2U)
#define TRSC_StateMachine_IN_Disp3     ((uint8_T)3U)
#define TRSC_StateMachine_IN_Disp5     ((uint8_T)4U)
#define TRSC_StateMachine_IN_Disp_15   ((uint8_T)5U)
#define TRSC_StateMachine_IN_Disp_16   ((uint8_T)6U)
#define TRSC_StateMachine_IN_Disp_17_or_18 ((uint8_T)7U)
#define TRSC_StateMachine_IN_Disp_21   ((uint8_T)8U)
#define TRSC_StateMachine_IN_Disp_23   ((uint8_T)9U)
#define TRSC_StateMachine_IN_Faulted   ((uint8_T)4U)
#define TRSC_StateMachine_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define TRSC_StateMachine_IN_OFF       ((uint8_T)5U)
#define TRSC_StateMachine_IN_OutputAsNormal ((uint8_T)18U)
#define TRSC_StateMachine_IN_PreActive ((uint8_T)6U)
#define TRSC_StateMachine_IN_STANDBY   ((uint8_T)7U)
#define TRSC_StateMachine_IN_WaitForFallingEdge ((uint8_T)3U)

/* Named constants for Chart: '<S2>/Chart3' */
#define TRSC_StateMachine_IN_DELAY     ((uint8_T)1U)
#define TRSC_StateMachine_IN_OFF_d     ((uint8_T)2U)
#define TRSC_StateMachine_IN_ON        ((uint8_T)3U)

/* Exported block signals */
boolean_T MeTRSC_b_ExternalFault;      /* '<S31>/Logical Operator1'
                                        * TRSC External Fault signal comprising following CAN  signals:

                                          1. m_QM_FID_TRSC_DISABLED
                                          2. m_QM_FID_TRSC_CAM_CAL_ABORT

                                        */
MdlrefDW_TRSC_StateMachine_T TRSC_StateMachine_MdlrefDW;

/* Block signals (default storage) */
B_TRSC_StateMachine_c_T TRSC_StateMachine_B;

/* Block states (default storage) */
DW_TRSC_StateMachine_f_T TRSC_StateMachine_DW;

/* Forward declaration for local functions */
static void TRSC_StateMachine_ResetM20Disp(void);
static void TRSC_StateMachine_enter_atomic_STANDBY(void);
static void TRSC_StateMachine_inner_default_STANDBY(void);
static void TRSC_StateMachine_inner_default_Active(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp);
static void TRSC_StateMachine_inner_default_Faulted(void);
static void TRSC_StateMachine_inner_default_ActiveHoldOver(void);
static void TRSC_StateMachine_Active(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp);
static void TRSC_StateMachine_exit_internal_Calibration(void);
static void TRSC_StateMachine_enter_atomic_PreActive(void);
static void TRSC_StateMachine_inner_default_PreActive(void);
static void TRSC_StateMachine_enter_atomic_Calibration(void);
static void TRSC_StateMachine_enter_atomic_Active(void);
static void TRSC_StateMachine_Disp3(void);
static void TRSC_StateMachine_Calibration_Steps(void);
static void TRSC_StateMachine_Default(void);
static void TRSC_StateMachine_Calibration(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp);
static void TRSC_StateMachine_MainStateMachine(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp);
static void TRSC_StateMachine_OutputAsNormal(void);
static void TRSC_StateMachine_ClearPopupDispInfo(void);

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_ResetM20Disp(void)
{
  if ((MeTRSC_e_TrlrPrsntInfoCAN != TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce) {
    TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

    /* Defect22615086 fix for Disp20 show it only once, 21st Feb2025  */
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_enter_atomic_STANDBY(void)
{
  TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Standby;

  /*  HD SRS Req: 20675062, 20675199, 20674291
     MeTRSC_e_TrlrState = 1 ; %[Standby]
     MeTRSC_e_TrlrPrsntInfo = 0; %[Unknown] : output from TrailerDetection
     MeTRSC_e_TrlrCalInfo = 0 ; %[Not Calibrated] : output from TrailerDetection
     MeTRSC_cnt_TrlrCalibFailCntInfo = 0; %[0] */
  TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;

  /*  HD SRS Req: 20674978
     MeTRSC_b_TrlrCalibDelayInfo = false;  /$ Req: 16039103 : NA Req *
     MeTRSC_s_Timer =  0; /$ Req :16039124 $/  */
  TRSC_StateMachine_DW.MeTRSC_s_Timer2 = 0.0F;

  /*  HD SRS Req: 20674855, 20674177, 20674772, 20674781, 20675475, 20675473, 20675483, 20674758, 20674751, 20674749, 20674768   */
  TRSC_StateMachine_DW.MeTRSC_s_Timer3 = 0.0F;

  /*  HD SRS Req: 20675230 */
  TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

  /*  HD SRS Req: 20675199  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
    TeTRSC_e_TRSCStrTrqActvReq_False;

  /*  HD SRS Req: 20674290  */
  TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

  /*  HD SRS Req: 20674271  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

  /*  Req: 16068650  */
  TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;
  TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
  TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink = CeTRSC_s_TRSCLpTm;

  /* Added to fix LED blinking reset, 3rd July 2025
     MeTRSC_s_CalibTimer = 0;
     MeTRSC_s_Disp8HldTmr = 0; */
  TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
  TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo_Unknown;

  /*  HD SRS Req: 20675038
     MeTRSC_e_SmTrlrCalInfo = TeTRSC_e_TrlrCalInfo.NotCalibrated; Req : 16039037, commented as Fix for Defect#20419328  */
  TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo = 0U;

  /*  HD SRS Req: 20675008  */
  /*  HD SRS Req: 20674655 */
  TRSC_StateMachine_DW.MeTRSC_b_ExitActvStat = false;

  /*  Added MeTRSC_b_ExitActvStat to exit Active State only after Disp 8 popup output once TRSC SW pressed, Kamlesh Thakur 19Aug2022  */
  TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

  /*  HD SRS Req: 20684655  */
  TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k = TeTRSC_e_SpdLmtReq_NotLim;

  /*  HD SRS Req: 20674231  */
  TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
  TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;

  /* Fix for Disp22 not showing on consecutive button press events 20 Oct 2024 */
  TRSC_StateMachine_ResetM20Disp();
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_inner_default_STANDBY(void)
{
  real32_T tmp;
  boolean_T tmp_0;
  boolean_T tmp_1;

  /*  { MeTRSC_s_ParkGrTmr = 0 ;}  */
  /*  HD SRS Req: 20674260  */
  if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
      TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
    /*  HD SRS Req: 20674260  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20674267, 20674662
     Defect Fix 22926124, 25th Mar 2025 */
  if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts ==
        TeVBII_e_TrlrPrsntSts_TRLR_PRSNT) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts ==
        TeVBII_e_TrailerConnectionSts_Connected)) &&
      (TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i == TeTRSC_e_TRSCSts_Calibrating))
  {
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_ON;
    TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
  } else {
    /*  HD SRS Req: 20674267, 20674662  */
    if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts ==
         TeVBII_e_TrlrPrsntSts_TRLR_PRSNT) ||
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts ==
         TeVBII_e_TrailerConnectionSts_Connected)) {
      if (TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer <
          KeTRSC_s_FifteenSecTh) {
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_ON;
        TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer +=
          CeTRSC_s_TRSCLpTm;
      } else {
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_OFF;
      }
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
    }
  }

  if (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_NoTrlr) {
    TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec += CeTRSC_s_TRSCLpTm;

    /*  28-Feb-24 */
  } else {
    /* Fix for Disp22 not showing on consecutive button press events 20 Oct 2024 */
    TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
       TeTRSC_e_TADState_Idle) && TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
    /*  March 20 2025 */
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_SNA;
  }

  /*  Added Speed Threshold condition for TRSC activation,17th Feb 2025
     Driver Door Status OR with Driver Seat status,25th Feb2025 */
  tmp = fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle);
  tmp_1 = !IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts;
  if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
       TeVBII_e_GearEngagedForDsply_R) &&
      (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
       TeTRSC_e_TrlrCalInfo_Calibrated) && (MeTRSC_e_TrlrPrsntInfoCAN ==
       TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
       TeTRSC_e_TrlrRecogInfo_Known) && (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts
       || (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
           TeTRSC_e_TRSCPopupDispInfo_Disp15)) &&
      ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
        TeVBII_e_EngineSts_Engine_Off) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
        TeVBII_e_EngineSts_Engine_On) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
        TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
       TRSC_StateMachine_B.Switch_TAD_des_Final1) && (tmp_1 ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts ==
        TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
       TeVBII_e_EscTrscBrkResp_Off) &&
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
       TeVBII_e_StrTrqResp_Off) &&
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
       TeVBII_e_EcmTrscResp_Off) && TRSC_StateMachine_B.RelationalOperator_l &&
      (!TRSC_StateMachine_B.RelationalOperator3)) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp11;
  } else {
    /*  To cover transition from Trailer Detection to Angle Detection, 29th Jan 2025
       Defect22615086 fix for Disp20 show it only once, 21st Feb2025
       Triler detection complete is updated based on TAD State 23 Apr 2025
       Button Press condition added 28th May, 2025  */
    tmp_0 = !TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce;
    if ((MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_TrailerRecognition) &&
        TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts && tmp_0) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp20;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;
    } else {
      /*  HD SRS Req: 20684672
         Fix for Disp22 not showing on consecutive button press events 20 Oct 2024   */
      if ((MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_NoTrlr) &&
          (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
           TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
           TeTRSC_e_TrlrRecogInfo_Unknown) &&
          TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts !=
           TeVBII_e_EngineSts_SNA) &&
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
           TeVBII_e_GearEngagedForDsply_SNA)) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp22;

        /*  HD SRS Req: 20684672  */
        TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;

        /* Added defect fix 23080144, 13th Aug, 2025 8 */
      } else {
        /*  HD SRS Req: 20684683  Defect Fix 22116304 4Sep2024,
           TRSC activation condition for corner case is added, 20th Jan 2025
           Added Speed Threshold condition for TRSC activation,17th Feb 2025
           Driver Door Status OR with Driver Seat status,25th Feb2025  */
        if ((MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_Calibrated) &&
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
             TeTRSC_e_TrlrRecogInfo_Known) && tmp_0 &&
            TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
            ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Off) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_On) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Cranking)) &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
             TeVBII_e_GearEngagedForDsply_SNA) && ((tmp_1 ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
               == TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
              TeVBII_e_EscTrscBrkResp_Off) &&
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
              TeVBII_e_StrTrqResp_Off) &&
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
              TeVBII_e_EcmTrscResp_Off)) && (tmp <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            TRSC_StateMachine_B.RelationalOperator_l) {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp20;

          /*  HD SRS Req: 20684683  */
          TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

          /*  HD SRS Req: 20684683  */
        } else {
          /*  HD SRS Req: 20674263, 20674264
             Defect Fix 21928224 24July2023
             Defect fix 22920362, 25th Jun 2025 */
          if ((((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                 TeVBII_e_EngineSts_SNA) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                  != TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
                 TeVBII_e_EscTrscBrkResp_SNA) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                 TeVBII_e_StrTrqResp_SNA) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
                 TeVBII_e_EcmTrscResp_SNA)) &&
               TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) ||
              ((TRSC_StateMachine_DW.MeTRSC_s_LedTmr > 0.0F) &&
               (TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b ==
                TeTRSC_e_TRSCLedSts_Blink) &&
               (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                TeTRSC_e_TRSCPopupDispInfo_SNA))) {
            /* (MeTRSC_e_TrlrPrsntInfo == TeTRSC_e_TrlrPrsntInfo.NoTrlr && MeTRSC_b_TRSCBtnSts == true) || ... */
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_SNA;
            if (TRSC_StateMachine_DW.MeTRSC_s_LedTmr > KeTRSC_s_FiveSecTh) {
              TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                TeTRSC_e_TRSCLedSts_Off;
              TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

              /* Defect fix 22947915, 30June, 2025 */
            } else {
              TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                TeTRSC_e_TRSCLedSts_Blink;
              TRSC_StateMachine_DW.MeTRSC_s_LedTmr += CeTRSC_s_TRSCLpTm;
            }
          } else {
            /*  HD SRS Req: 20674736
               Unit Testing Fix for LED Blinking 11Jan2025 */
            if ((TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp19) ||
                 ((TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec > 0.0F) &&
                  (TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b ==
                   TeTRSC_e_TRSCLedSts_Blink) &&
                  (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                   TeTRSC_e_TRSCPopupDispInfo_Disp15))) &&
                ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Off) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_On) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Cranking)) &&
                (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 != TeVBII_e_GearEngagedForDsply_SNA) &&
                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                 TeTRSC_e_TADState_TrailerDetection)) {
              /*  Req: update for HD  */
              TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;

              /* Req : 16068656  uncommented on15 May 2025
                 IeTRSC_e_TRSCLedSts = TeTRSC_e_TRSCLedSts.Blink ; /$ Req : 16068658 $/ */
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp19;

              /*  HD SRS Req: 20674736  */
              if (TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec >
                  TRSC_StateMachine_B.SignalConversion.KeTRSC_s_TrlrUnkwnSet) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Off;
                TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
              } else {
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Blink;

                /*  HD SRS Req: 20675424 */
                TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec += CeTRSC_s_TRSCLpTm;
              }

              if (TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec >
                  KeTRSC_s_TwoSecTh) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp15;

                /*  28-Feb-24 */
              } else {
                TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec += CeTRSC_s_TRSCLpTm;
              }
            } else {
              /*  HD SRS Req: 21157781, 21157779, 20674294 27July2023
                 Added condition when TAD state becomes 0 or 1,3rd Mar 2025  */
              if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                  (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt)
                  && (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                      TeTRSC_e_TrlrRecogInfo_Unknown) &&
                  TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                  ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                    TeVBII_e_EngineSts_Engine_Off) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                    TeVBII_e_EngineSts_Engine_On) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                    TeVBII_e_EngineSts_Engine_Cranking)) &&
                  (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState !=
                   TeTRSC_e_TADState_Idle) &&
                  (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState !=
                   TeTRSC_e_TADState_TrailerDetection)) {
                TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Blink;
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp3;
              }

              if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i) {
                /*  HD SRS Req: 20674302  */
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Blink;
              }

              /*  HD SRS Req: 20674307  */
              if ((TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink > 0.0F) &&
                  (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
                   (TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b ==
                    TeTRSC_e_TRSCLedSts_Blink))) {
                if (TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink >
                    TRSC_StateMachine_B.SignalConversion.KeTRSC_s_TrlrUnkwnSet)
                {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                    TeTRSC_e_TRSCLedSts_Off;
                  TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink = 0.0F;
                } else {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                    TeTRSC_e_TRSCLedSts_Blink;
                  TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink += CeTRSC_s_TRSCLpTm;
                }
              } else {
                if ((!TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) &&
                    (TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink == 0.0F)) {
                  TRSC_StateMachine_DW.MeTRSC_s_LedTmrBlink = CeTRSC_s_TRSCLpTm;
                }
              }

              /*  HD SRS Req: 20674667 */
              if ((MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt)
                  && (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                      TeTRSC_e_TrlrRecogInfo_Unknown) &&
                  (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                  TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                  ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                    TeVBII_e_EngineSts_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                     != TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp
                    == TeVBII_e_EscTrscBrkResp_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                    TeVBII_e_StrTrqResp_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
                    TeVBII_e_EcmTrscResp_SNA))) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_SNA;
              } else {
                /*  HD SRS Req: 20674238
                   TRSC activation condition for corner case is added, 20th Jan 2025
                   Driver Door Status OR with Driver Seat status,25th Feb2025  */
                if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                     != TeVBII_e_GearEngagedForDsply_R) &&
                    (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                     TeTRSC_e_TrlrCalInfo_Calibrated) &&
                    (MeTRSC_e_TrlrPrsntInfoCAN ==
                     TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                     TeTRSC_e_TrlrRecogInfo_Known) &&
                    TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                    ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Off) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_On) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
                     TRSC_StateMachine_B.Switch_TAD_des_Final1) && (tmp_1 ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                      == TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp
                     == TeVBII_e_EscTrscBrkResp_Off) &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                     TeVBII_e_StrTrqResp_Off) &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
                     TeVBII_e_EcmTrscResp_Off) &&
                    TRSC_StateMachine_B.RelationalOperator_l) {
                  /*  HD SRS Req: 20674238  */
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp9;
                  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                    TeTRSC_e_TRSCLedSts_Solid;
                } else {
                  /*  HD SRS Req: 20674323
                     TRSC activation condition for corner case is added, 20th Jan 2025
                     Added Speed Threshold condition for TRSC activation, 14th Feb 2025 */
                  if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                       TeTRSC_e_TRSCPopupDispInfo_Disp9) &&
                      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                       == TeVBII_e_GearEngagedForDsply_R) && (tmp <=
                       TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                      TRSC_StateMachine_B.RelationalOperator_l &&
                      TRSC_StateMachine_B.RelationalOperator3) {
                    /*  HD SRS Req: 20674323  */
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp6;
                  } else {
                    /*  Fix for capped JK angle in SM for activation, deactivation 28 Oct 2024  */
                    if (((tmp > TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
                         (!TRSC_StateMachine_B.RelationalOperator_l)) &&
                        (MeTRSC_e_TrlrPrsntInfoCAN ==
                         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                         TeTRSC_e_TrlrCalInfo_Calibrated) &&
                        TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                        TeTRSC_e_TRSCPopupDispInfo_Disp10;
                    } else {
                      /*  HD SRS Req: 20674329
                         TRSC activation condition for corner case is added, 20th Jan 2025
                         Added Speed Threshold condition for TRSC activation, 14th Feb 2025
                         Driver Door Status OR with Driver Seat status,25th Feb2025 */
                      if ((TRSC_StateMachine_B.Gain7 <= CeConst_k_SnglTen) &&
                          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                           == TeVBII_e_GearEngagedForDsply_R) &&
                          (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                           TeTRSC_e_TrlrCalInfo_Calibrated) &&
                          (MeTRSC_e_TrlrPrsntInfoCAN ==
                           TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo
                           == TeTRSC_e_TrlrRecogInfo_Known) &&
                          TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                          ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                            == TeVBII_e_EngineSts_Engine_Off) ||
                           (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                            == TeVBII_e_EngineSts_Engine_On) ||
                           (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                            == TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
                           TRSC_StateMachine_B.Switch_TAD_des_Final1) && (tmp_1 ||
                           (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                            == TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
                          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp
                           == TeVBII_e_EscTrscBrkResp_Off) &&
                          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp
                           == TeVBII_e_StrTrqResp_Off) &&
                          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp
                           == TeVBII_e_EcmTrscResp_Off) &&
                          TRSC_StateMachine_B.RelationalOperator_l &&
                          TRSC_StateMachine_B.RelationalOperator3) {
                        /*  HD SRS Req: 20674329  */
                        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                          TeTRSC_e_TRSCPopupDispInfo_Disp6;
                        TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                          TeTRSC_e_TRSCLedSts_Solid;
                      } else {
                        /*  22Nov2023: Added check in Standby again based on Jyothi's Suggestion to observe Disp13
                           Req:  16126701, Fix for Defect#20695207, 02Nov2023, DLD CamBlock Enum values :0: Normal, 1: Blockage, 2: Low_Luminance, 10: Unknown"  */
                        if ((TRSC_StateMachine_B.MeTRSC_e_CamBlockSts ==
                             CeConst_k_ConstOneUint8) &&
                            (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
                             TeTRSC_e_TRSCPopupDispInfo_Disp0)) {
                          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                            TeTRSC_e_TRSCPopupDispInfo_Disp13;
                        } else {
                          /*  Vehicle Test Observation : output TRSM_FD_1\TRSC_STAT =Standy when Pre-Calibrated trailer is connected in Standby state  */
                          if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                == TeVBII_e_EngineSts_Engine_Off) ||
                               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                == TeVBII_e_EngineSts_Engine_On) ||
                               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                == TeVBII_e_EngineSts_Engine_Cranking)) &&
                              (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                               TeTRSC_e_TrlrCalInfo_Calibrated) &&
                              (MeTRSC_e_TrlrPrsntInfoCAN ==
                               TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                              (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo
                               == TeTRSC_e_TrlrRecogInfo_Known)) {
                            TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i =
                              TeTRSC_e_TRSCSts_Standby;
                            TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                              TeTRSC_e_TRSCLedSts_Off;
                          } else {
                            /*  PTC Task #20133267 : output TRSM_FD_1\TRSC_STAT =Calibrating in Standby state  */
                            if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                  == TeVBII_e_EngineSts_Engine_Off) ||
                                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                  == TeVBII_e_EngineSts_Engine_On) ||
                                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts
                                  == TeVBII_e_EngineSts_Engine_Cranking)) &&
                                (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                                 TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                                (MeTRSC_e_TrlrPrsntInfoCAN ==
                                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo
                                 == TeTRSC_e_TrlrRecogInfo_Unknown)) {
                              /*  #Defect 21691829 fix, 21st May 2024  */
                              if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus)
                              {
                                TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i =
                                  TeTRSC_e_TRSCSts_Standby;
                              } else {
                                TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i =
                                  TeTRSC_e_TRSCSts_Calibrating;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_inner_default_Active(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  StrTrqCtrlActv, HD SRS Req: 20674666, Task#18936596  */
  if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp !=
       TeVBII_e_StrTrqResp_Active) &&
      (!TRSC_StateMachine_DW.MeTRSC_b_StrTrqCtrlActv)) {
    /*  HD SRS Req: 20674666  */
    TRSC_StateMachine_DW.MeTRSC_s_EpsRespDbncTmr += CeTRSC_s_TRSCLpTm;
    if (TRSC_StateMachine_DW.MeTRSC_s_EpsRespDbncTmr >=
        TRSC_StateMachine_B.SignalConversion.KeTRSC_s_EpsRespTmOut) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp8;

      /*  HD SRS Req: 20674666, 20674965  */
    }
  } else {
    /*  Req : 16126618  */
    TRSC_StateMachine_DW.MeTRSC_s_EpsRespDbncTmr = 0.0F;

    /*  Check for Req : 16123056, Task#18936596  */
    TRSC_StateMachine_DW.MeTRSC_b_StrTrqCtrlActv = true;

    /* HD SRS Req: 20674443, 20674442 Fix for Defect#20695207, 22260905, 02Nov2023, 24Oct2024  DLD CamBlock Enum values :0: Normal, 1: Blockage, 2: Low_Luminance, 10: Unknown"  */
    if ((TRSC_StateMachine_B.MeTRSC_e_CamBlockSts == CeConst_k_ConstOneUint8) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_Trackinglost)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp13;

      /*  Fix for Defect 20695207, 02Nov2023   */
    } else {
      /*  {MeTRSC_s_DispViewTimer  = 0 ;} : Commented for NA req as per Post 2A  */
      /*  HD SRS Req: 20674933 */
      if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
            TeVBII_e_GearEngagedForDsply_N) ||
           (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
            TeVBII_e_GearEngagedForDsply_D)) && (TRSC_StateMachine_B.Gain7 >
           CeConst_mph_VehSpeedThr)) {
        /* {MeTRSC_s_RevGearDbncTmr += CeTRSC_s_TRSCLpTm ; } */
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp8;

        /*  HD SRS Req: 20674933  */
      } else {
        /* { MeTRSC_s_RevGearDbncTmr = 0; } */
        /*  HD SRS Req: 20674957, 20675241  */
        guard1 = false;
        guard2 = false;
        if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
            TeVBII_e_GearEngagedForDsply_P) {
          TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr += CeTRSC_s_TRSCLpTm;
          if (TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr >= KeTRSC_s_TenMinTh)
          {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp8;

            /*  HD SRS Req: 20674981, 20674957, 20675241  */
          } else {
            guard2 = true;
          }
        } else {
          guard2 = true;
        }

        if (guard2) {
          if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
               != TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp8;

            /*  HD SRS Req: 20674981, 20674957, 20675241  */
          } else {
            /*  HD SRS Req: 20674974, 20674972, 20674941, 20674938, 20674931, 20674954  */
            if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                 TeVBII_e_EngineSts_SNA) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
                 TeVBII_e_EscTrscBrkResp_SNA) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
                 TeVBII_e_EscTrscBrkResp_BrkOverHeated) ||
                ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                  TeVBII_e_StrTrqResp_SNA) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                  TeVBII_e_StrTrqResp_Off)) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
                 TeVBII_e_EcmTrscResp_SNA) ||
                TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
              if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                /*  Added MeTRSC_b_ExitActvStat to exit Active State only after Disp 8 popup output once TRSC SW pressed, Kamlesh Thakur 19Aug2022  */
                TRSC_StateMachine_DW.MeTRSC_b_ExitActvStat = true;
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp8;

                /*  HD SRS Req: 20674974, 20674972, 20674941, 20674938, 20674931, 20674954  */
              } else {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp8;

                /*  Req: 16123052, 16123054, 16123056, 16123058,  16123066, 16123062  */
              }
            } else if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus)
            {
              /*  HD SRS Req: 20675244 */
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp8;

              /*  Req: 16123052, 16123054, 16123056, 16123058,  16123066, 16123062  */
            } else {
              /*  uncommented for vehicle Test EPS tuning session, 11Sept2023  */
              if ((*rtu_MeTRSC_b_StrTwitchComplete) &&
                  TRSC_StateMachine_B.Switch5_o) {
                /* HD SRS Req: 20674914
                   Added fix for defect 22262296 and 22262295 */
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp12;
                TRSC_StateMachine_B.MeTRSC_b_DriverOverride = true;
              } else if
                  (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                   TeVBII_e_StrTrqResp_Active) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Active;

                /*  HD SRS Req: 20674677  */
                TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
                  IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

                /*  HD SRS Req: 20674659  */
                /*  HD SRS Req: 20674659  */
                TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n =
                  *rtu_MeTRSC_M_TRSCStrTrq;

                /*  Req: HD SRS Req: 20674673, 20674236 but Tslew TBD, 16356127 but Tslew TBD  */
                TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k =
                  *rtu_MeTRSC_e_SpdLmtReq;

                /*  HD SRS Req: 20674179  */
                TRSC_StateMachine_B.IeTRSC_pct_TRSCStrDmp_b =
                  *rtu_MeTRSC_pct_TRSCStrDmp;

                /*  HD SRS Req: 20674164, 20675087  */
                if (TRSC_StateMachine_B.Gain7 >
                    ((TRSC_StateMachine_B.DataTypeConversion26 +
                      CeConst_k_ConstThree) +
                     TRSC_StateMachine_B.SignalConversion.KeTRSC_kph_DeactivationSpd)
                    * 0.62137) {
                  /*  Added offset of +3 to get SpdLimReq value in Kph, Updated Speed limit threshold 26th Dec, 2024  */
                  if (TRSC_StateMachine_B.RelationalOperator_f) {
                    /* Threshold based on Max speed lim req */
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp11;
                  } else {
                    TRSC_StateMachine_DW.MeTRSC_s_VehOverSpdTmr +=
                      CeTRSC_s_TRSCLpTm;

                    /*  HD SRS Req: 20674950  */
                    if (TRSC_StateMachine_DW.MeTRSC_s_VehOverSpdTmr >=
                        KeTRSC_s_DeactSpdTime) {
                      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                        TeTRSC_e_TRSCPopupDispInfo_Disp11;
                    } else {
                      guard1 = true;
                    }
                  }
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }
            }
          }
        }

        if (guard1) {
          if ((fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) >
               TRSC_StateMachine_B.SignalConversion.KeTRSC_pct_TrlrJackKnifePerc
               / 100.0F * *rtu_MeTRSC_deg_JackKnifeAngle) &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
               TeVBII_e_StrTrqResp_Active) && (!TRSC_StateMachine_B.Switch5_o))
          {
            TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_True;

            /* Req For HD */
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp10;

            /*  HD SRS Req: 20674499, 20675386 */
          }
        }
      }
    }
  }

  /* End of Update for Inport: '<Root>/IbTRSC_InpBus' */
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_inner_default_Faulted(void)
{
  /*  Req : 16127572  */
  if (TRSC_StateMachine_DW.MeTRSC_s_LedTmr > KeTRSC_s_FiveSecTh) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
  } else {
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
    TRSC_StateMachine_DW.MeTRSC_s_LedTmr += CeTRSC_s_TRSCLpTm;
  }

  /*  Req: 16127576  */
  if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_SNA;
    if (TRSC_StateMachine_DW.MeTRSC_s_LedTmr > KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

      /* Defect fix 22947915, 30June, 2025 */
    }
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  Req : 16127562  */
  if (IbTRSC_InpBus.MeTRSC_b_InternalFault) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_SNA;
    TRSC_StateMachine_DW.MeTRSC_s_Timer2 = 0.0F;
    TRSC_StateMachine_DW.MeTRSC_s_Timer3 = 0.0F;
  }

  /* End of Update for Inport: '<Root>/IbTRSC_InpBus' */
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_inner_default_ActiveHoldOver(void)
{
  boolean_T guard1 = false;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20674869, 20674378  */
  guard1 = false;
  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
      TeVBII_e_GearEngagedForDsply_P) {
    TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr += CeTRSC_s_TRSCLpTm;
    if (TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr >= KeTRSC_s_TenMinTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp8;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    /*  HD SRS Req: 20674871, 20674858, 20674854, 20674852, 20674863, 20674861, 20674378
       Added fix for defect 21108369 25Jan2024
       Added fix for defect 22116289, 03Sept2024 */
    if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts || (TRSC_StateMachine_B.Gain7 >=
         CeConst_mph_VehSpeedThr) ||
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts !=
          TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
        ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
          TeVBII_e_EscTrscBrkResp_SNA) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
          TeVBII_e_EscTrscBrkResp_BrkOverHeated)) ||
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
         TeVBII_e_StrTrqResp_SNA) ||
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
         TeVBII_e_EcmTrscResp_SNA) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_Idle) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_TrailerDetection) ||
        TRSC_StateMachine_B.RelationalOperator_g) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp8;
    }
  }

  if (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
      TeTRSC_e_TADState_Trackinglost) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp13;
  }

  /*  Req : 16101565 , 16101567  */
  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
      TeVBII_e_GearEngagedForDsply_R) {
    TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr += CeTRSC_s_TRSCLpTm;

    /* Fix for capped JK angle in SM for activation, deactivation 28 Oct 2024,
       TRSC activation condition for corner case is added, 20th Jan 2025 */
    if (((fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) >
          TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
         (!TRSC_StateMachine_B.RelationalOperator_l)) &&
        (TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr >=
         TRSC_StateMachine_B.SignalConversion.KeTRSC_s_GearDbncTh)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp10;
    }
  }

  /* End of Update for Inport: '<Root>/IbTRSC_InpBus' */
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_Active(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp)
{
  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20675016, 20674207, 20674180, 20674439, 20675204  */
  if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_RUN) &&
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_START)) {
    /*  HD SRS Req: 20674693
       IeTRSC_e_TRSCSts = TeTRSC_e_TRSCSts.Active; /$ 16122800 $/ */
    TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
      TeTRSC_e_TRSCStrTrqActvReq_False;
    TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n = 0.0F;
    TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

    /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

    /* [Off]
       Req : 15842421  */
    TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

    /* HD SRS Req: 20675042  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

    /* Off  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /* HD SRS Req: 20675425
       Clearing PopupDispInfo in Off state based on customer feedback */
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp0;
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_OFF;
    TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
    TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

    /* Fix for Disp20 show it only once  */
  } else {
    /*  HD SRS Req: 20674432, 20675205  */
    if (IbTRSC_InpBus.MeTRSC_b_InternalFault || MeTRSC_b_ExternalFault) {
      /*  HD SRS Req: 20674693
         IeTRSC_e_TRSCSts = TeTRSC_e_TRSCSts.Active; /$ 16122800 $/ */
      TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n = 0.0F;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp8;
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Faulted;
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

      /*  HD SRS Req: 20674652  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Fault;

      /*  HD SRS Req: 20675193 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
        TeTRSC_e_TRSCStrTrqActvReq_False;

      /*  HD SRS Req: 20674652  */
      TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

      /*  Req : 16127568  */
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

      /*  Req : 16127572  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* Defect Fix 22893168,25th June 2025 */
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_inner_default_Faulted();
    } else {
      /*  HD SRS Req: 20675242, 20674506  */
      if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
           TeVBII_e_GearEngagedForDsply_N) ||
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
           TeVBII_e_GearEngagedForDsply_D) ||
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
           TeVBII_e_GearEngagedForDsply_P) ||
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
           TeVBII_e_GearEngagedForDsply_R)) {
        /*  HD SRS Req: 20674693
           IeTRSC_e_TRSCSts = TeTRSC_e_TRSCSts.Active; /$ 16122800 $/ */
        TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n = 0.0F;
        TRSC_StateMachine_DW.is_MainStateMachine =
          TRSC_StateMachine_IN_ActiveHoldOver;
        TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p =
          TeTRSC_e_TRSCStat_ActiveHoldOvr;

        /*  /$ HD SRS Req: 20674883 $/ */
        TRSC_StateMachine_DW.MeTRSC_s_Timer3 = 0.0F;

        /*  HD SRS Req: 20674894, 20674829 */
        TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_PreActive;

        /*  HD SRS Req: 20674867  */
        TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
          TeTRSC_e_TRSCStrTrqActvReq_False;

        /*  HD SRS Req: 20674866  */
        TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

        /*  Req : 16127205
           Req: update for HD  */
        TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

        /*  HD SRS Req: 20674876  */
        TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr = 0.0F;
        TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = true;

        /* HD SRS Req: 20685918 */
        TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr = 0.0F;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp9;

        /*  HD SRS Req: 20674874  */
        TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
          IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

        /*  Req : 16575524, 16101535
           01Nov2023  */
        /*  Req: 16572683 , 16101535
           01Nov2023  */
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_OFF;
        TRSC_StateMachine_inner_default_ActiveHoldOver();
      } else {
        /*  HD SRS Req: 20674530, 20674525, 20674490, 20674487, 20674505, 20674503, 20674500, 20674497
           20674479, 20674477, 20674853, 20674474, 20674486, 20674485, 20675348, 20674467,
           20674464, 20674461, 20674472, 20674471, 20674452, 20674449, 20674448, 20674445,
           20674459, 20674457, 20674335, 20675367, 20674455, 20674453, 20674441, 20674443
           Added reset logic for state machine when CustTrlrType changes conventional to non-conventional or Viceversa 4Dec2024
           Added condition when TAD state becomes 0 or 1,3rd Mar 2025    */
        if ((TRSC_StateMachine_DW.MeTRSC_s_EpsRespDbncTmr >=
             TRSC_StateMachine_B.SignalConversion.KeTRSC_s_EpsRespTmOut) ||
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
              != TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) ||
            (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
             TeTRSC_e_TRSCPopupDispInfo_Disp11) ||
            TRSC_StateMachine_DW.MeTRSC_b_ExitActvStat ||
            (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
               TeVBII_e_EngineSts_SNA) ||
              ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
                TeVBII_e_EscTrscBrkResp_SNA) ||
               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
                TeVBII_e_EscTrscBrkResp_BrkOverHeated)) ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
               TeVBII_e_EcmTrscResp_SNA) ||
              (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
               TeTRSC_e_TADState_Trackinglost) ||
              ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                TeVBII_e_StrTrqResp_Off) ||
               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                TeVBII_e_StrTrqResp_SNA))) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) ||
            (TRSC_StateMachine_B.Switch5_o &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp12)) ||
            (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_N) ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_D)) && (TRSC_StateMachine_B.Gain7 >
              CeConst_k_SnglTen) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) ||
            ((TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i ==
              TeTRSC_e_VehStpReq_True) &&
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_VehStandStillSts ==
              TeVBII_e_VehStandStillSts_True)) ||
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) ||
            ((TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr >= KeTRSC_s_TenMinTh)
             && (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                 TeTRSC_e_TRSCPopupDispInfo_Disp8)) ||
            (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
             TeTRSC_e_TRSCPopupDispInfo_Disp13) ||
            (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
             TeTRSC_e_TRSCPopupDispInfo_Disp10) ||
            TRSC_StateMachine_B.RelationalOperator_g ||
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
             TeTRSC_e_TADState_Idle) ||
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
             TeTRSC_e_TADState_TrailerDetection)) {
          /*  HD SRS Req: 20674693
             IeTRSC_e_TRSCSts = TeTRSC_e_TRSCSts.Active; /$ 16122800 $/ */
          TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n = 0.0F;
          TRSC_StateMachine_DW.is_MainStateMachine =
            TRSC_StateMachine_IN_STANDBY;
          TRSC_StateMachine_enter_atomic_STANDBY();
          TRSC_StateMachine_inner_default_STANDBY();
        } else {
          TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

          /*  HD SRS Req: 20674969  */
          TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
            IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

          /*  Req : HD SRS Req: 20675113  */
          /*  HD SRS Req: 20674416  */
          TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Active;

          /*  16356127 , StrTrq Overlay Req TBD */
          TRSC_StateMachine_inner_default_Active(rtu_MeTRSC_deg_JackKnifeAngle,
            rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
            rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
        }
      }
    }
  }

  /* End of Update for Inport: '<Root>/IbTRSC_InpBus' */
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_exit_internal_Calibration(void)
{
  TRSC_StateMachine_DW.is_Calibration_Steps =
    TRSC_StateMachine_IN_NO_ACTIVE_CHILD;
  TRSC_StateMachine_DW.is_Calibration = TRSC_StateMachine_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_enter_atomic_PreActive(void)
{
  TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_PreActive;

  /*  HD SRS Req: 20674212  */
  TRSC_StateMachine_DW.MeTRSC_s_Timer2 = 0.0F;

  /*  HD SRS Req: 20674193 */
  TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

  /* HD SRS Req: 20674250  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
    TeTRSC_e_TRSCStrTrqActvReq_False;

  /*  HD SRS Req: 20674194  */
  TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

  /*  Req : 16101551
     Req: update for HD  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_PreActive;

  /* HD SRS Req: 20674185  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

  /*  HD SRS Req: 20674183  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
    TeTRSC_e_TRSCPopupDispInfo_Disp9;

  /*  HD SRS Req: 20674184  */
  TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts = false;

  /* Req : 16126751  */
  TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr = 0.0F;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /* Req : 16101565  */
  TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

  /*  HD SRS Req: 20675094  */
  /*  HD SRS Req: 20674419  */
  TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr = 0.0F;

  /* Req : 17716920  */
  TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = true;

  /*  HD SRS Req: 20684858 */
  TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
    TeTRSC_e_TrlrHitchLightCtrl_OFF;
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_inner_default_PreActive(void)
{
  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  { MeTRSC_s_GearDbncTmr = 0; } : Commented for NA Req Post 2A  */
  /*  HD SRS Req: 20674187  */
  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
      TeVBII_e_GearEngagedForDsply_R) {
    TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr += CeTRSC_s_TRSCLpTm;

    /* Fix for capped JK angle in SM for activation, deactivation 28 Oct 2024,
       TRSC activation condition for corner case is added, 20th Jan 2025 */
    if (((fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) >
          TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
         (!TRSC_StateMachine_B.RelationalOperator_l)) &&
        (TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr >=
         TRSC_StateMachine_B.SignalConversion.KeTRSC_s_GearDbncTh)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp10;
    }
  } else {
    TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr = 0.0F;
  }

  /*  HD SRS Req: 20684868  */
  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
      TeVBII_e_ShiftLvrPos_P) {
    TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr += CeTRSC_s_TRSCLpTm;
  } else {
    TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr = 0.0F;
  }

  /* HD SRS Req: 20674250  */
  if ((TRSC_StateMachine_B.Gain7 > CeConst_k_SnglTen) &&
      (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
       TeTRSC_e_TrlrCalInfo_Calibrated) &&
      TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts && (MeTRSC_e_TrlrPrsntInfoCAN ==
       TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt)) {
    if (TRSC_StateMachine_DW.MeTRSC_s_LedTmr > KeTRSC_s_TwoSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr += CeTRSC_s_TRSCLpTm;
    }
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20674191, 20674840, 20674816, 20674814, 20674810, 20674807, 20674824, 20675493, 20675509, 20675009   */
  if ((TRSC_StateMachine_DW.MeTRSC_s_Timer2 > KeTRSC_s_TenMinTh) ||
      (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
       ((TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b != TeTRSC_e_TRSCLedSts_Blink)
        || (TRSC_StateMachine_B.Gain7 < CeConst_k_SnglTen))) ||
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
       TeVBII_e_EngineSts_SNA) ||
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts !=
        TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
      ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
        TeVBII_e_EscTrscBrkResp_SNA) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
        TeVBII_e_EscTrscBrkResp_BrkOverHeated)) ||
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
       TeVBII_e_StrTrqResp_SNA) ||
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
       TeVBII_e_EcmTrscResp_SNA) ||
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus ||
      (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
         TeVBII_e_ShiftLvrPos_D) ||
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
         TeVBII_e_ShiftLvrPos_N)) && (TRSC_StateMachine_B.Gain7 >=
        CeConst_mph_VehSpeedThr)) ||
      (TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr > KeTRSC_s_TenMinTh) ||
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
       TeTRSC_e_TADState_Idle) ||
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
       TeTRSC_e_TADState_TrailerDetection) ||
      TRSC_StateMachine_B.RelationalOperator_g) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp8;
  }

  if (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
      TeTRSC_e_TADState_Trackinglost) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp13;
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_enter_atomic_Calibration(void)
{
  TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Calibrating;

  /*  HD SRS Req: 20675401  */
  TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Calibrating;

  /*  HD SRS Req: 20674217, 20675398
     MeTRSC_b_TrlrCalibDelayInfo = false; /$ Req: 16068731 $/ */
  TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
    TeTRSC_e_TRSCStrTrqActvReq_False;

  /*  HD SRS Req: 20675403  */
  TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

  /*  Req : 16082923
     Req: update for HD  */
  TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr = 0.0F;

  /*  HD SRS Req: 20674240  */
  TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo = MeTRSC_e_TrlrPrsntInfoCAN;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20675358  */
  TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

  /*  HD SRS Req: 21157777, 20675106  */
  TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo;

  /*  HD SRS Req: 20674649  */
  TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k = TeTRSC_e_SpdLmtReq_NotLim;

  /*  HD SRS Req: 20674599  */
  TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

  /*  HD SRS Req: 20684743 */
  TRSC_StateMachine_DW.MeTRSC_b_Disp23 = true;
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_enter_atomic_Active(void)
{
  /*  HD SRS Req: 20674187, 20674693  */
  TRSC_StateMachine_DW.MeTRSC_s_Timer2 = 0.0F;

  /*  HD SRS Req: 20674188
     MeTRSC_s_Timer3 = 0; /$ Req : 16127233 : Commented for NA req as per Post 2A$/  */
  TRSC_StateMachine_DW.MeTRSC_s_EpsRespDbncTmr = 0.0F;

  /* Req : 16126618  */
  /*  Req: 16126622  */
  TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr = 0.0F;

  /*  Req: 16126679  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
    TeTRSC_e_TRSCPopupDispInfo_Disp6;

  /*  HD SRS Req: 20674995  */
  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20674969  */
  TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

  /*  HD SRS Req: 20675113  */
  /*  HD SRS Req: 20674416  */
  TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Active;

  /*  HD SRS Req: 20674693
     IeTRSC_e_TRSCSts = TeTRSC_e_TRSCSts.Active; /$ 16122800 $/ */
  TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
    TeTRSC_e_TRSCStrTrqActvReq_True;

  /*  HD SRS Req: 20674666  */
  TRSC_StateMachine_DW.MeTRSC_b_ExitActvStat = false;

  /*  Added MeTRSC_b_ExitActvStat to exit Active State only after Disp 8 popup output once TRSC SW pressed, Kamlesh Thakur 19Aug2022  */
  TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts = false;

  /*  Fix added to resolve Test findings of exiting Active state due to previous button press event  */
  TRSC_StateMachine_DW.MeTRSC_b_StrTrqCtrlActv = false;

  /*  Check for Req : 16123056, Task#18936596  */
  TRSC_StateMachine_DW.MeTRSC_s_ParkGearDbncTmr = 0.0F;
  TRSC_StateMachine_DW.MeTRSC_s_VehOverSpdTmr = 0.0;
  TRSC_StateMachine_B.MeTRSC_b_DriverOverride = false;

  /* Reset flag for Streering Override */
  TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
    TeTRSC_e_TrlrHitchLightCtrl_OFF;
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_Disp3(void)
{
  if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
      (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
       TeTRSC_e_TRSCPopupDispInfo_SNA)) {
    TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp3;

    /*  HD SRS Req: 20674312, 20674309, 20674311  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp3;
  } else if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
              TeTRSC_e_TADState_Calibration) &&
             ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
               == TeTRSC_e_TADCalibrationSubstate_DriveStraight) ||
              IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo ||
              (TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr >= KeTRSC_s_TwoSecTh)) &&
             (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
              TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
             (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
              TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
    TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_15;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp15;

    /* CR task 21964473 24July2023 */
    TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
      TeTRSC_e_TrlrPrsntInfo_NoTrlr);
  } else if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
              TeTRSC_e_TADState_Calibration) &&
             (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
              == TeTRSC_e_TADCalibrationSubstate_TurnLeftOrRight) &&
             (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
              TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
             (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
              TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
    TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_16;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp16;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng >= 0.0F) {
      TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Left;

      /* Left Direction */
    } else {
      TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Right;

      /* Right Direction */
    }

    /* CR task 21964473 24July2023 */
    TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
      TeTRSC_e_TrlrPrsntInfo_NoTrlr);
  } else {
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024
       Added fix for, if TAD_State change to 6 24Jan2025 */
    if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_Turnaround) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_AngleDetection)) {
      if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
            TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
           (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
            TeTRSC_e_TrlrCalInfo_Calibrated)) ||
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_AngleDetection)) {
        TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_23;
        TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp23;
        TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

        /* CR task 2196447324July2023 */
        TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
          TeTRSC_e_TrlrPrsntInfo_NoTrlr);
      } else if ((((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                    TeTRSC_e_TADState_Turnaround) &&
                   (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState
                    == TeTRSC_e_TurnAroundSubState_DriveStraight)) ||
                  IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo)
                 && (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                     TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                 (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                  TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
        TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_21;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp21;

        /* CR task 21964473 24July2023 */
        TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
          TeTRSC_e_TrlrPrsntInfo_NoTrlr);
      } else {
        /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024 */
        if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
             TeTRSC_e_TADState_Turnaround) &&
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState ==
             TeTRSC_e_TurnAroundSubState_TurnLeftOrRight) &&
            (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
             TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
            (!IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo)) {
          TRSC_StateMachine_DW.is_Calibration_Steps =
            TRSC_StateMachine_IN_Disp_17_or_18;
          if (TRSC_StateMachine_DW.MeTRSC_e_Direction == TeVBII_e_Direction_Left)
          {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp18;
          } else {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp17;
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_Calibration_Steps(void)
{
  real32_T tmp;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20674216
     TRSC activation condition for corner case is added, 20th Jan 2025 */
  tmp = fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle);
  if (((tmp > TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
       (!TRSC_StateMachine_B.RelationalOperator_l)) &&
      (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
       TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
      (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
       TeTRSC_e_TrlrCalInfo_Calibrated) &&
      TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp10;
  } else {
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /*  HD SRS Req: 20674298, 20674301
       TRSC activation condition for corner case is added, 20th Jan 2025     */
    if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
         TeTRSC_e_TrlrCalInfo_Calibrated) &&
        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
         TeTRSC_e_TrlrRecogInfo_Known) &&
        TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
        ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_Off) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_On) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
         TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
        TRSC_StateMachine_B.RelationalOperator_l &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
         TeVBII_e_GearEngagedForDsply_R)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp9;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;
    } else {
      /*  HD SRS Req: 20674254
         TRSC activation condition for corner case is added, 20th Jan 2025
         Added Speed Threshold condition for TRSC activation, 14th Feb 2025  */
      if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
           TeTRSC_e_TRSCPopupDispInfo_Disp9) &&
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
           TeVBII_e_GearEngagedForDsply_R) && (tmp <=
           TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
          TRSC_StateMachine_B.RelationalOperator_l &&
          TRSC_StateMachine_B.RelationalOperator3) {
        /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
        if (!TRSC_StateMachine_B.RelationalOperator3) {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp11;
        } else {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp6;
        }
      } else {
        /*  HD SRS Req: 20674634
           [(IeVBII_kph_VehSpeedVSOSig <= CeConst_k_SnglTen) && (IeVBII_e_GearEngagedForDsply == TeVBII_e_GearEngagedForDsply.R)]
           Req : 17699327, Fix for Customer Observation DISP_6 pop-up , even when trlr is not calibrated, 20Oct2023
           TRSC activation condition for corner case is added, 20th Jan 2025 */
        if ((TRSC_StateMachine_B.Gain7 <= CeConst_k_SnglTen) &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
             TeVBII_e_GearEngagedForDsply_R) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_Calibrated) && (MeTRSC_e_TrlrPrsntInfoCAN ==
             TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
             TeTRSC_e_TrlrRecogInfo_Known) &&
            TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
            ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Off) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_On) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            TRSC_StateMachine_B.RelationalOperator_l) {
          /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
          if (!TRSC_StateMachine_B.RelationalOperator3) {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp11;
          } else {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp6;
            TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
              TeTRSC_e_TRSCLedSts_Solid;
          }
        } else {
          /*  HD SRS Req: 20674233, 20674243
             TRSC activation condition for corner case is added, 20th Jan 2025 */
          if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
              (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
               TeTRSC_e_TrlrCalInfo_Calibrated) && (tmp <=
               TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
              TRSC_StateMachine_B.RelationalOperator_l) {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp9;
            TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;

            /*  27July2023  */
          } else {
            /*  HD SRS Req: 20674241  */
            if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                 TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
                 TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) &&
                TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp5;
            }
          }
        }
      }
    }
  }

  switch (TRSC_StateMachine_DW.is_Calibration_Steps) {
   case TRSC_StateMachine_IN_CalFailed:
    if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp3;

      /*  HD SRS Req: 20674312, 20674309, 20674311  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp3;
    } else {
      TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;

      /* IeTRSC_e_TRSCPopupDispInfo = TeTRSC_e_TRSCPopupDispInfo.Disp3; */
    }
    break;

   case TRSC_StateMachine_IN_Complete:
    break;

   case TRSC_StateMachine_IN_Disp3:
    TRSC_StateMachine_Disp3();
    break;

   case TRSC_StateMachine_IN_Disp5:
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp5;
    break;

   case TRSC_StateMachine_IN_Disp_15:
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_Calibration) &&
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate ==
         TeTRSC_e_TADCalibrationSubstate_TurnLeftOrRight) &&
        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
         TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_16;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp16;
      if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng >= 0.0F) {
        TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Left;

        /* Left Direction */
      } else {
        TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Right;

        /* Right Direction */
      }

      /* CR task 21964473 24July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else if (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
               TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp5;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp5;
    } else if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                 TeTRSC_e_TrlrCalInfo_Calibrated)) ||
               (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                TeTRSC_e_TADState_AngleDetection)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_23;
      TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp23;
      TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

      /* CR task 2196447324July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp15;

      /* CR task 21964473 24July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    }
    break;

   case TRSC_StateMachine_IN_Disp_16:
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if ((((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_Turnaround) &&
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState ==
           TeTRSC_e_TurnAroundSubState_DriveStraight)) ||
         IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo) &&
        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
         TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_21;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp21;

      /* CR task 21964473 24July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else {
      /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024 */
      if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_Turnaround) &&
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState ==
           TeTRSC_e_TurnAroundSubState_TurnLeftOrRight) &&
          (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
           TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
          (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
           TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
          (!IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo)) {
        TRSC_StateMachine_DW.is_Calibration_Steps =
          TRSC_StateMachine_IN_Disp_17_or_18;
        if (TRSC_StateMachine_DW.MeTRSC_e_Direction == TeVBII_e_Direction_Left)
        {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp18;
        } else {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp17;
        }
      } else if (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
                 TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) {
        TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp5;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp5;
      } else if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                   TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                  (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_Calibrated)) ||
                 (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                  TeTRSC_e_TADState_AngleDetection)) {
        TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_23;
        TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp23;
        TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

        /* CR task 2196447324July2023 */
        TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
          TeTRSC_e_TrlrPrsntInfo_NoTrlr);
      } else if (TRSC_StateMachine_B.LogicalOperator) {
        TRSC_StateMachine_DW.is_Calibration_Steps =
          TRSC_StateMachine_IN_CalFailed;
        TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
        TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp3;
      } else {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp16;
        if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng >= 0.0F) {
          TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Left;

          /* Left Direction */
        } else {
          TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Right;

          /* Right Direction */
        }

        /* CR task 21964473 24July2023 */
        TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
          TeTRSC_e_TrlrPrsntInfo_NoTrlr);
      }
    }
    break;

   case TRSC_StateMachine_IN_Disp_17_or_18:
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
          TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
         (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
          TeTRSC_e_TrlrCalInfo_Calibrated)) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_AngleDetection)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_23;
      TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp23;
      TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

      /* CR task 2196447324July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else if (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
               TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp5;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp5;
    } else if (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_21;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp21;

      /* CR task 21964473 24July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else if (TRSC_StateMachine_B.LogicalOperator) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_CalFailed;
      TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp3;
    } else if (TRSC_StateMachine_DW.MeTRSC_e_Direction ==
               TeVBII_e_Direction_Left) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp18;
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp17;
    }
    break;

   case TRSC_StateMachine_IN_Disp_21:
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
          TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
         (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
          TeTRSC_e_TrlrCalInfo_Calibrated)) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_AngleDetection)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp_23;
      TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp23;
      TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

      /* CR task 2196447324July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    } else if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                TeTRSC_e_TADState_Turnaround) &&
               (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState ==
                TeTRSC_e_TurnAroundSubState_TurnLeftOrRight) &&
               (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
               (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
               (!IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo))
    {
      TRSC_StateMachine_DW.is_Calibration_Steps =
        TRSC_StateMachine_IN_Disp_17_or_18;
      if (TRSC_StateMachine_DW.MeTRSC_e_Direction == TeVBII_e_Direction_Left) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp18;
      } else {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp17;
      }
    } else if (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
               TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp5;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp5;
    } else if (TRSC_StateMachine_B.LogicalOperator) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_CalFailed;
      TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp3;
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp21;

      /* CR task 21964473 24July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    }
    break;

   default:
    /* case IN_Disp_23: */
    if ((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
         TeTRSC_e_TrlrCalInfo_Calibrated) &&
        (TRSC_StateMachine_DW.temporalCounter_i1 >= 67U)) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Complete;
      TRSC_StateMachine_DW.MeTRSC_b_Disp23 = true;
    } else if (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
               TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) {
      TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp5;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp5;
    } else {
      /*  HD SRS Req: 20684764, 20684767, 20684769  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp23;
      TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;

      /* CR task 2196447324July2023 */
      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
        TeTRSC_e_TrlrPrsntInfo_NoTrlr);
    }
    break;
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_Default(void)
{
  real32_T tmp;
  boolean_T guard1 = false;

  /*  HD SRS Req: 20674340  */
  if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i) {
    /*  HD SRS Req: 20674340  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts ==
        TeVBII_e_TrlrPrsntSts_TRLR_PRSNT) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts ==
        TeVBII_e_TrailerConnectionSts_Connected)) &&
      (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
       TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
    /*  HD SRS Req: 20675363, 20675346  */
    /*  HD SRS Req: 20675363, 20675346  */
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_ON;
  }

  /*  HD SRS Req: 20674340  */
  if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
      TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
    /*  HD SRS Req: 20674340  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;
  }

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  Defect #21691797 fix, 27th May2024
     Req : 16083082, 16083084  */
  if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
        TeVBII_e_EngineSts_SNA) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts !=
         TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
        TeVBII_e_EscTrscBrkResp_SNA) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
        TeVBII_e_StrTrqResp_SNA) ||
       (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
        TeVBII_e_EcmTrscResp_SNA)) && (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
       TRSC_StateMachine_DW.MeTRSC_b_MesgClearance ||
       ((TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr > 0.0F) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b == TeTRSC_e_TRSCLedSts_Blink)
        && (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
            TeTRSC_e_TRSCPopupDispInfo_SNA)))) {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_SNA;

    /* Removed for post 2A SRS Req :
       MeTRSC_b_TrlrCalibPopInfo = false; */
    if (TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr > KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
      TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr = 0.0F;
    } else {
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
      TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr += CeTRSC_s_TRSCLpTm;
    }
  } else {
    /*  HD SRS Req: 20674312, 20674309, 20674311  */
    guard1 = false;
    if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
         TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
        (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
         (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
          TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
         (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
          TeTRSC_e_TRSCPopupDispInfo_Disp15) ||
         (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
          TeTRSC_e_TRSCPopupDispInfo_Disp19)) &&
        ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_Off) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_On) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
          TeVBII_e_EngineSts_Engine_Cranking)) &&
        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
         TeTRSC_e_TrlrRecogInfo_Unknown) &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
         TeVBII_e_GearEngagedForDsply_SNA)) {
      /*  ((IeVBII_kph_VehSpeedVSOSig > CeConst_k_ConstOne) &&(IeVBII_kph_VehSpeedVSOSig <= CeConst_k_SnglTen)) &&... /$ Req: update for HD $/ */
      /*  Added fix for Disp15, due button press event while TAD is in detection state
         TRSC SM stucked in Disp15 20Dec2024 */
      if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
           TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
          (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
           TeTRSC_e_TRSCPopupDispInfo_Disp0)) {
        TRSC_StateMachine_DW.is_Calibration =
          TRSC_StateMachine_IN_Calibration_Steps;
        TRSC_StateMachine_DW.is_Calibration_Steps = TRSC_StateMachine_IN_Disp3;

        /*  HD SRS Req: 20674312, 20674309, 20674311  */
        TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
        TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Blink;
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp3;
      } else {
        /*  Added fix for Disp15, due button press event while TAD is in detection state
           TRSC SM stucked in Disp15 20Dec2024
           [(IeTRSC_e_TRSCPopupDispInfo != TeTRSC_e_TRSCPopupDispInfo.Disp3) ||(IeTRSC_e_TRSCPopupDispInfo != TeTRSC_e_TRSCPopupDispInfo.Disp0)] */
        if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
             TeTRSC_e_TADState_Calibration) &&
            ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
              == TeTRSC_e_TADCalibrationSubstate_DriveStraight) ||
             IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo ||
             (TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr >= KeTRSC_s_TwoSecTh)) &&
            (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
             TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
          TRSC_StateMachine_DW.is_Calibration =
            TRSC_StateMachine_IN_Calibration_Steps;
          TRSC_StateMachine_DW.is_Calibration_Steps =
            TRSC_StateMachine_IN_Disp_15;
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp15;

          /* CR task 21964473 24July2023 */
          TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
            TeTRSC_e_TrlrPrsntInfo_NoTrlr);
        } else if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                    TeTRSC_e_TADState_Calibration) &&
                   (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
                    == TeTRSC_e_TADCalibrationSubstate_TurnLeftOrRight) &&
                   (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                    TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                   (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                    TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
          TRSC_StateMachine_DW.is_Calibration =
            TRSC_StateMachine_IN_Calibration_Steps;
          TRSC_StateMachine_DW.is_Calibration_Steps =
            TRSC_StateMachine_IN_Disp_16;
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp16;
          if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng >= 0.0F)
          {
            TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Left;

            /* Left Direction */
          } else {
            TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Right;

            /* Right Direction */
          }

          /* CR task 21964473 24July2023 */
          TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = (MeTRSC_e_TrlrPrsntInfoCAN ==
            TeTRSC_e_TrlrPrsntInfo_NoTrlr);
        } else {
          /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024
             Added fix for, if TAD_State change to 6 24Jan2025 */
          if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
               TeTRSC_e_TADState_Turnaround) ||
              (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
               TeTRSC_e_TADState_AngleDetection)) {
            if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                  TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                 (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                  TeTRSC_e_TrlrCalInfo_Calibrated)) ||
                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                 TeTRSC_e_TADState_AngleDetection)) {
              TRSC_StateMachine_DW.is_Calibration =
                TRSC_StateMachine_IN_Calibration_Steps;
              TRSC_StateMachine_DW.is_Calibration_Steps =
                TRSC_StateMachine_IN_Disp_23;
              TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp23;
              TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

              /* CR task 2196447324July2023 */
              TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_NoTrlr);
            } else if ((((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                          TeTRSC_e_TADState_Turnaround) &&
                         (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState
                          == TeTRSC_e_TurnAroundSubState_DriveStraight)) ||
                        IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo)
                       && (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                           TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                       (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                        TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
              TRSC_StateMachine_DW.is_Calibration =
                TRSC_StateMachine_IN_Calibration_Steps;
              TRSC_StateMachine_DW.is_Calibration_Steps =
                TRSC_StateMachine_IN_Disp_21;
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp21;

              /* CR task 21964473 24July2023 */
              TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_NoTrlr);
            } else {
              /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024 */
              if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                   TeTRSC_e_TADState_Turnaround) &&
                  (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState
                   == TeTRSC_e_TurnAroundSubState_TurnLeftOrRight) &&
                  (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                   TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                  (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                  (!IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo))
              {
                TRSC_StateMachine_DW.is_Calibration =
                  TRSC_StateMachine_IN_Calibration_Steps;
                TRSC_StateMachine_DW.is_Calibration_Steps =
                  TRSC_StateMachine_IN_Disp_17_or_18;
                if (TRSC_StateMachine_DW.MeTRSC_e_Direction ==
                    TeVBII_e_Direction_Left) {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp18;
                } else {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp17;
                }
              } else {
                guard1 = true;
              }
            }
          } else {
            guard1 = true;
          }
        }
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      /*  HD SRS Req: 20674216
         TRSC activation condition for corner case is added, 20th Jan 2025 */
      tmp = fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle);
      if (((tmp > TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
           (!TRSC_StateMachine_B.RelationalOperator_l)) &&
          (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
           TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
          (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
           TeTRSC_e_TrlrCalInfo_Calibrated) &&
          TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp10;
      } else {
        /*  HD SRS Req: 20674298, 20674301
           TRSC activation condition for corner case is added, 20th Jan 2025     */
        if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_Calibrated) &&
            (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
             TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
             TeTRSC_e_TrlrRecogInfo_Known) &&
            TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
            ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Off) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_On) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            TRSC_StateMachine_B.RelationalOperator_l &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
             TeVBII_e_GearEngagedForDsply_R)) {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp9;
          TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Solid;
        } else {
          /*  HD SRS Req: 20674254
             TRSC activation condition for corner case is added, 20th Jan 2025
             Added Speed Threshold condition for TRSC activation, 14th Feb 2025  */
          if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp9) &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_R) && (tmp <=
               TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
              TRSC_StateMachine_B.RelationalOperator_l &&
              TRSC_StateMachine_B.RelationalOperator3) {
            /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
            if (!TRSC_StateMachine_B.RelationalOperator3) {
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp11;
            } else {
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp6;
            }
          } else {
            /*  HD SRS Req: 20674634
               [(IeVBII_kph_VehSpeedVSOSig <= CeConst_k_SnglTen) && (IeVBII_e_GearEngagedForDsply == TeVBII_e_GearEngagedForDsply.R)]
               Req : 17699327, Fix for Customer Observation DISP_6 pop-up , even when trlr is not calibrated, 20Oct2023
               TRSC activation condition for corner case is added, 20th Jan 2025 */
            if ((TRSC_StateMachine_B.Gain7 <= CeConst_k_SnglTen) &&
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_R) &&
                (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                 TeTRSC_e_TrlrCalInfo_Calibrated) && (MeTRSC_e_TrlrPrsntInfoCAN ==
                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                 TeTRSC_e_TrlrRecogInfo_Known) &&
                TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Off) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_On) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
                 TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                TRSC_StateMachine_B.RelationalOperator_l) {
              /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
              if (!TRSC_StateMachine_B.RelationalOperator3) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp11;
              } else {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp6;
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Solid;
              }
            } else {
              /*  HD SRS Req: 20674233, 20674243
                 TRSC activation condition for corner case is added, 20th Jan 2025 */
              if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                  (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_Calibrated) && (tmp <=
                   TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                  TRSC_StateMachine_B.RelationalOperator_l) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_Disp9;
                TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;

                /*  27July2023  */
              } else {
                /*  HD SRS Req: 20674241  */
                if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                    (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                     TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                    (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                     TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                    (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
                     TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt) &&
                    TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp5;
                }
              }
            }
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_Calibration(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp)
{
  real32_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

  /* Update for Inport: '<Root>/IbTRSC_InpBus' */
  /*  HD SRS Req: 20675016, 20674207, 20674180, 20674439, 20675204  */
  if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_RUN) &&
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_START)) {
    TRSC_StateMachine_exit_internal_Calibration();
    TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

    /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

    /* [Off]
       Req : 15842421  */
    TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

    /* HD SRS Req: 20675042  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

    /* Off  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /* HD SRS Req: 20675425
       Clearing PopupDispInfo in Off state based on customer feedback */
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp0;
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_OFF;
    TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
    TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

    /* Fix for Disp20 show it only once  */
  } else {
    /*  HD SRS Req: 20674636, 20674203  */
    if (IbTRSC_InpBus.MeTRSC_b_InternalFault || MeTRSC_b_ExternalFault) {
      if (!(TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
            TeTRSC_e_TRSCPopupDispInfo_Disp8)) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp0;
      }

      TRSC_StateMachine_exit_internal_Calibration();
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Faulted;
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

      /*  HD SRS Req: 20674652  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Fault;

      /*  HD SRS Req: 20675193 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
        TeTRSC_e_TRSCStrTrqActvReq_False;

      /*  HD SRS Req: 20674652  */
      TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

      /*  Req : 16127568  */
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

      /*  Req : 16127572  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* Defect Fix 22893168,25th June 2025 */
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_inner_default_Faulted();
    } else {
      /*  HD SRS Req: 20674846, 20684836, 20684839
         CR task 21964473 24July2023
         Added reset logic for state machine when CustTrlrType changes conventional to non-conventional or Viceversa 4Dec2024 */
      if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
           TeVBII_e_EngineSts_SNA) ||
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrWhlAngleType ==
           TeVBII_e_StrWhlAngleType_SNA) ||
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng == 65535.0)
          || ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp23) &&
              TRSC_StateMachine_DW.MeTRSC_b_NoTrailer) ||
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_Idle) || TRSC_StateMachine_B.RelationalOperator_g)
      {
        TRSC_StateMachine_exit_internal_Calibration();
        TRSC_StateMachine_DW.MeTRSC_b_NoTrailer = false;
        TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_STANDBY;
        TRSC_StateMachine_enter_atomic_STANDBY();
        TRSC_StateMachine_inner_default_STANDBY();
      } else {
        /*  HD SRS Req: 20674225, 20674415
           Fix for capped JK angle in SM for activation, deactivation 28 Oct 2024
           TRSC activation condition for corner case is added, 20th Jan 2025  */
        tmp = fabsf(IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle);
        guard1 = false;
        guard2 = false;
        guard3 = false;
        if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Off) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_On) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            ((!IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts ==
              TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
            TRSC_StateMachine_DW.MeTRSC_b_Disp23 &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
             TeVBII_e_EscTrscBrkResp_Off) &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
             TeVBII_e_StrTrqResp_Off) &&
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
             TeVBII_e_EcmTrscResp_Off) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_Calibrated) &&
            TRSC_StateMachine_B.RelationalOperator_l) {
          /*   && (IeTRSC_e_TRSCPopupDispInfo == TeTRSC_e_TRSCPopupDispInfo.Disp23), 23 April 2024: Removeed dependency of Popup's
             &&( MeTRSC_b_TRSCBtnSts == true ) , 9th-Nov-23 : as per Jyothi's discussion with customer,button pressed is not checked  */
          /*  HD SRS Req: 20674225, 20674415
             Fix for defect 21952296 24July2023 */
          if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_P) ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_D) ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_N) ||
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply ==
               TeVBII_e_GearEngagedForDsply_L)) {
            TRSC_StateMachine_exit_internal_Calibration();
            TRSC_StateMachine_DW.is_MainStateMachine =
              TRSC_StateMachine_IN_PreActive;
            TRSC_StateMachine_enter_atomic_PreActive();
            TRSC_StateMachine_inner_default_PreActive();
          } else {
            /*  HD SRS Req: 20674225, 20674415
             /$Added Speed Threshold condition for TRSC activation, 14th Feb 2025$/ */
            if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_R) &&
                TRSC_StateMachine_B.RelationalOperator3) {
              TRSC_StateMachine_exit_internal_Calibration();
              TRSC_StateMachine_DW.is_MainStateMachine =
                TRSC_StateMachine_IN_Active;
              TRSC_StateMachine_enter_atomic_Active();
              TRSC_StateMachine_inner_default_Active
                (rtu_MeTRSC_deg_JackKnifeAngle, rtu_MeTRSC_b_StrTwitchComplete,
                 rtu_MeTRSC_M_TRSCStrTrq, rtu_MeTRSC_e_SpdLmtReq,
                 rtu_MeTRSC_pct_TRSCStrDmp);
            } else {
              guard3 = true;
            }
          }
        } else {
          guard3 = true;
        }

        if (guard3) {
          /* Added action when TAD state becomes Idle,28thFeb 2025 */
          if (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
              TeTRSC_e_TADState_TrailerDetection) {
            TRSC_StateMachine_exit_internal_Calibration();
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
              TeTRSC_e_TRSCPopupDispInfo_Disp0;
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp0;
            TRSC_StateMachine_DW.is_MainStateMachine =
              TRSC_StateMachine_IN_Calibration;
            TRSC_StateMachine_enter_atomic_Calibration();
            TRSC_StateMachine_DW.is_Calibration = TRSC_StateMachine_IN_Default;
          } else {
            /* Added TRSCLedSts Off PopInfo false for pop up clearence 15May 2025 */
            if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp15) ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp16) ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp17) ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp18) ||
                 (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                  TeTRSC_e_TRSCPopupDispInfo_Disp21))) {
              TRSC_StateMachine_exit_internal_Calibration();
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
                TeTRSC_e_TRSCPopupDispInfo_Disp0;
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp0;
              TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;
              TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = true;
              TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                TeTRSC_e_TRSCLedSts_Off;
              TRSC_StateMachine_DW.is_MainStateMachine =
                TRSC_StateMachine_IN_Calibration;
              TRSC_StateMachine_enter_atomic_Calibration();
              TRSC_StateMachine_DW.is_Calibration = TRSC_StateMachine_IN_Default;
            } else {
              TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo =
                MeTRSC_e_TrlrPrsntInfoCAN;

              /*  HD SRS Req: 20675358 */
              TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
                IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

              /*  HD SRS Req: 21157777, 20675106 */
              TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo =
                IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo;

              /*  HD SRS Req: 20674649  */
              /*  HD SRS Req: 20674340  */
              if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i) {
                /*  HD SRS Req: 20674340  */
                TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                  TeTRSC_e_TRSCLedSts_Blink;
              }

              if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts ==
                    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts
                    == TeVBII_e_TrailerConnectionSts_Connected)) &&
                  (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                   TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
                /*  HD SRS Req: 20675363, 20675346  */
                /*  HD SRS Req: 20675363, 20675346  */
                TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
                  TeTRSC_e_TrlrHitchLightCtrl_ON;
              }

              /*  HD SRS Req: 20674340  */
              if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                  TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                /*  HD SRS Req: 20674340  */
                TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;
              }

              /*  Defect #21691797 fix, 27th May2024
                 Req : 16083082, 16083084  */
              if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                    TeVBII_e_EngineSts_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                     != TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp
                    == TeVBII_e_EscTrscBrkResp_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
                    TeVBII_e_StrTrqResp_SNA) ||
                   (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
                    TeVBII_e_EcmTrscResp_SNA)) &&
                  (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
                   TRSC_StateMachine_DW.MeTRSC_b_MesgClearance ||
                   ((TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr > 0.0F) &&
                    (TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b ==
                     TeTRSC_e_TRSCLedSts_Blink) &&
                    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                     TeTRSC_e_TRSCPopupDispInfo_SNA)))) {
                TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                  TeTRSC_e_TRSCPopupDispInfo_SNA;

                /* Removed for post 2A SRS Req :
                   MeTRSC_b_TrlrCalibPopInfo = false; */
                if (TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr >
                    KeTRSC_s_FiveSecTh) {
                  TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
                  TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr = 0.0F;
                } else {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                    TeTRSC_e_TRSCLedSts_Blink;
                  TRSC_StateMachine_DW.MeTRSC_s_CalibLedTmr += CeTRSC_s_TRSCLpTm;
                }

                guard1 = true;
              } else {
                /*  HD SRS Req: 20674312, 20674309, 20674311  */
                if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                     TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                    (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
                     (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                      TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
                     (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                      TeTRSC_e_TRSCPopupDispInfo_Disp15) ||
                     (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                      TeTRSC_e_TRSCPopupDispInfo_Disp19)) &&
                    ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Off) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_On) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Cranking)) &&
                    (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                     TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                     TeTRSC_e_TrlrRecogInfo_Unknown) &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                     != TeVBII_e_GearEngagedForDsply_SNA)) {
                  /*  ((IeVBII_kph_VehSpeedVSOSig > CeConst_k_ConstOne) &&(IeVBII_kph_VehSpeedVSOSig <= CeConst_k_SnglTen)) &&... /$ Req: update for HD $/ */
                  /*  Added fix for Disp15, due button press event while TAD is in detection state
                     TRSC SM stucked in Disp15 20Dec2024 */
                  if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                       TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
                      (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                       TeTRSC_e_TRSCPopupDispInfo_Disp0)) {
                    TRSC_StateMachine_exit_internal_Calibration();
                    TRSC_StateMachine_DW.is_Calibration =
                      TRSC_StateMachine_IN_Calibration_Steps;
                    TRSC_StateMachine_DW.is_Calibration_Steps =
                      TRSC_StateMachine_IN_Disp3;

                    /*  HD SRS Req: 20674312, 20674309, 20674311  */
                    TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = true;
                    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                      TeTRSC_e_TRSCLedSts_Blink;
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp3;
                  } else {
                    /*  Added fix for Disp15, due button press event while TAD is in detection state
                       TRSC SM stucked in Disp15 20Dec2024
                       [(IeTRSC_e_TRSCPopupDispInfo != TeTRSC_e_TRSCPopupDispInfo.Disp3) ||(IeTRSC_e_TRSCPopupDispInfo != TeTRSC_e_TRSCPopupDispInfo.Disp0)] */
                    if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                         TeTRSC_e_TADState_Calibration) &&
                        ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
                          == TeTRSC_e_TADCalibrationSubstate_DriveStraight) ||
                         IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo
                         || (TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr >=
                             KeTRSC_s_TwoSecTh)) &&
                        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                         TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
                      TRSC_StateMachine_exit_internal_Calibration();
                      TRSC_StateMachine_DW.is_Calibration =
                        TRSC_StateMachine_IN_Calibration_Steps;
                      TRSC_StateMachine_DW.is_Calibration_Steps =
                        TRSC_StateMachine_IN_Disp_15;
                      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                        TeTRSC_e_TRSCPopupDispInfo_Disp15;

                      /* CR task 21964473 24July2023 */
                      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                        (MeTRSC_e_TrlrPrsntInfoCAN ==
                         TeTRSC_e_TrlrPrsntInfo_NoTrlr);
                    } else if
                        ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                          TeTRSC_e_TADState_Calibration) &&
                         (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADCalibrationSubstate
                          == TeTRSC_e_TADCalibrationSubstate_TurnLeftOrRight) &&
                         (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                          TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                         (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                          TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
                      TRSC_StateMachine_exit_internal_Calibration();
                      TRSC_StateMachine_DW.is_Calibration =
                        TRSC_StateMachine_IN_Calibration_Steps;
                      TRSC_StateMachine_DW.is_Calibration_Steps =
                        TRSC_StateMachine_IN_Disp_16;
                      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                        TeTRSC_e_TRSCPopupDispInfo_Disp16;
                      if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng
                          >= 0.0F) {
                        TRSC_StateMachine_DW.MeTRSC_e_Direction =
                          TeVBII_e_Direction_Left;

                        /* Left Direction */
                      } else {
                        TRSC_StateMachine_DW.MeTRSC_e_Direction =
                          TeVBII_e_Direction_Right;

                        /* Right Direction */
                      }

                      /* CR task 21964473 24July2023 */
                      TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                        (MeTRSC_e_TrlrPrsntInfoCAN ==
                         TeTRSC_e_TrlrPrsntInfo_NoTrlr);
                    } else {
                      /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024
                         Added fix for, if TAD_State change to 6 24Jan2025 */
                      if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                           TeTRSC_e_TADState_Turnaround) ||
                          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                           TeTRSC_e_TADState_AngleDetection)) {
                        if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                              TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                             (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                              TeTRSC_e_TrlrCalInfo_Calibrated)) ||
                            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState
                             == TeTRSC_e_TADState_AngleDetection)) {
                          TRSC_StateMachine_exit_internal_Calibration();
                          TRSC_StateMachine_DW.is_Calibration =
                            TRSC_StateMachine_IN_Calibration_Steps;
                          TRSC_StateMachine_DW.is_Calibration_Steps =
                            TRSC_StateMachine_IN_Disp_23;
                          TRSC_StateMachine_DW.temporalCounter_i1 = 0U;
                          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                            TeTRSC_e_TRSCPopupDispInfo_Disp23;
                          TRSC_StateMachine_DW.MeTRSC_b_Disp23 = false;

                          /* CR task 2196447324July2023 */
                          TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                            (MeTRSC_e_TrlrPrsntInfoCAN ==
                             TeTRSC_e_TrlrPrsntInfo_NoTrlr);
                        } else if
                            ((((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState
                                == TeTRSC_e_TADState_Turnaround) &&
                               (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState
                                == TeTRSC_e_TurnAroundSubState_DriveStraight)) ||
                              IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo)
                             && (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                             (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                              TeTRSC_e_TrlrCalInfo_NotCalibrated)) {
                          TRSC_StateMachine_exit_internal_Calibration();
                          TRSC_StateMachine_DW.is_Calibration =
                            TRSC_StateMachine_IN_Calibration_Steps;
                          TRSC_StateMachine_DW.is_Calibration_Steps =
                            TRSC_StateMachine_IN_Disp_21;
                          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                            TeTRSC_e_TRSCPopupDispInfo_Disp21;

                          /* CR task 21964473 24July2023 */
                          TRSC_StateMachine_DW.MeTRSC_b_NoTrailer =
                            (MeTRSC_e_TrlrPrsntInfoCAN ==
                             TeTRSC_e_TrlrPrsntInfo_NoTrlr);
                        } else {
                          /* Added fix for, if User press button at TAD_State =5, we should display Disp21 or Disp17. 20Dec2024 */
                          if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState
                               == TeTRSC_e_TADState_Turnaround) &&
                              (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TurnAroundSubState
                               == TeTRSC_e_TurnAroundSubState_TurnLeftOrRight) &&
                              (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                               TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                              (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                               TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                              (!IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_b_TrlrCalibDelayInfo))
                          {
                            TRSC_StateMachine_exit_internal_Calibration();
                            TRSC_StateMachine_DW.is_Calibration =
                              TRSC_StateMachine_IN_Calibration_Steps;
                            TRSC_StateMachine_DW.is_Calibration_Steps =
                              TRSC_StateMachine_IN_Disp_17_or_18;
                            if (TRSC_StateMachine_DW.MeTRSC_e_Direction ==
                                TeVBII_e_Direction_Left) {
                              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                                TeTRSC_e_TRSCPopupDispInfo_Disp18;
                            } else {
                              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                                TeTRSC_e_TRSCPopupDispInfo_Disp17;
                            }
                          } else {
                            guard2 = true;
                          }
                        }
                      } else {
                        guard2 = true;
                      }
                    }
                  }
                } else {
                  guard2 = true;
                }
              }
            }
          }
        }

        if (guard2) {
          /*  HD SRS Req: 20674216
             TRSC activation condition for corner case is added, 20th Jan 2025 */
          if (((tmp > TRSC_StateMachine_B.Switch_TAD_des_Final1) ||
               (!TRSC_StateMachine_B.RelationalOperator_l)) &&
              (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
               TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
              (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
               TeTRSC_e_TrlrCalInfo_Calibrated) &&
              TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
            TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
              TeTRSC_e_TRSCPopupDispInfo_Disp10;
          } else {
            /*  HD SRS Req: 20674298, 20674301
               TRSC activation condition for corner case is added, 20th Jan 2025     */
            if ((TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                 TeTRSC_e_TrlrCalInfo_Calibrated) &&
                (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                 TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                 TeTRSC_e_TrlrRecogInfo_Known) &&
                TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Off) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_On) ||
                 (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                  TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
                 TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                TRSC_StateMachine_B.RelationalOperator_l &&
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 != TeVBII_e_GearEngagedForDsply_R)) {
              TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                TeTRSC_e_TRSCPopupDispInfo_Disp9;
              TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                TeTRSC_e_TRSCLedSts_Solid;
            } else {
              /*  HD SRS Req: 20674254
                 TRSC activation condition for corner case is added, 20th Jan 2025
                 Added Speed Threshold condition for TRSC activation, 14th Feb 2025  */
              if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                   TeTRSC_e_TRSCPopupDispInfo_Disp9) &&
                  (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                   == TeVBII_e_GearEngagedForDsply_R) && (tmp <=
                   TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                  TRSC_StateMachine_B.RelationalOperator_l &&
                  TRSC_StateMachine_B.RelationalOperator3) {
                /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
                if (!TRSC_StateMachine_B.RelationalOperator3) {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp11;
                } else {
                  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                    TeTRSC_e_TRSCPopupDispInfo_Disp6;
                }
              } else {
                /*  HD SRS Req: 20674634
                   [(IeVBII_kph_VehSpeedVSOSig <= CeConst_k_SnglTen) && (IeVBII_e_GearEngagedForDsply == TeVBII_e_GearEngagedForDsply.R)]
                   Req : 17699327, Fix for Customer Observation DISP_6 pop-up , even when trlr is not calibrated, 20Oct2023
                   TRSC activation condition for corner case is added, 20th Jan 2025 */
                if ((TRSC_StateMachine_B.Gain7 <= CeConst_k_SnglTen) &&
                    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                     == TeVBII_e_GearEngagedForDsply_R) &&
                    (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                     TeTRSC_e_TrlrCalInfo_Calibrated) &&
                    (MeTRSC_e_TrlrPrsntInfoCAN ==
                     TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
                     TeTRSC_e_TrlrRecogInfo_Known) &&
                    TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts &&
                    ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Off) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_On) ||
                     (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                      TeVBII_e_EngineSts_Engine_Cranking)) && (tmp <=
                     TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                    TRSC_StateMachine_B.RelationalOperator_l) {
                  /*  Added Speed Threshold condition for TRSC activation,17th Jan 2025 */
                  if (!TRSC_StateMachine_B.RelationalOperator3) {
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp11;
                  } else {
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp6;
                    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b =
                      TeTRSC_e_TRSCLedSts_Solid;
                  }
                } else {
                  /*  HD SRS Req: 20674233, 20674243
                     TRSC activation condition for corner case is added, 20th Jan 2025 */
                  if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                      (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                       TeTRSC_e_TrlrCalInfo_Calibrated) && (tmp <=
                       TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
                      TRSC_StateMachine_B.RelationalOperator_l) {
                    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                      TeTRSC_e_TRSCPopupDispInfo_Disp9;
                    TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i = false;

                    /*  27July2023  */
                  } else {
                    /*  HD SRS Req: 20674241  */
                    if (TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i &&
                        (TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
                         TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
                        (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
                         TeTRSC_e_TrlrCalInfo_NotCalibrated) &&
                        (TRSC_StateMachine_DW.MeTRSC_cnt_SmTrlrCalibFailCntInfo >=
                         TRSC_StateMachine_B.SignalConversion.KeTRSC_Cnt_FailedCnt)
                        && TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
                        TeTRSC_e_TRSCPopupDispInfo_Disp5;
                    }
                  }
                }
              }
            }
          }

          guard1 = true;
        }

        if (guard1) {
          if (TRSC_StateMachine_DW.is_Calibration ==
              TRSC_StateMachine_IN_Calibration_Steps) {
            TRSC_StateMachine_Calibration_Steps();
          } else {
            /* case IN_Default: */
            TRSC_StateMachine_Default();
          }
        }
      }
    }
  }

  /* End of Update for Inport: '<Root>/IbTRSC_InpBus' */
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_MainStateMachine(const real32_T
  *rtu_MeTRSC_deg_JackKnifeAngle, const boolean_T
  *rtu_MeTRSC_b_StrTwitchComplete, const real32_T *rtu_MeTRSC_M_TRSCStrTrq,
  const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq, const real32_T
  *rtu_MeTRSC_pct_TRSCStrDmp)
{
  boolean_T guard1 = false;
  guard1 = false;
  switch (TRSC_StateMachine_DW.is_MainStateMachine) {
   case TRSC_StateMachine_IN_Active:
    /* Chart: '<S2>/Chart' */
    TRSC_StateMachine_Active(rtu_MeTRSC_deg_JackKnifeAngle,
      rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
      rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
    break;

   case TRSC_StateMachine_IN_ActiveHoldOver:
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = true;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /*  HD SRS Req: 20675016, 20674207, 20674180, 20674439, 20675204  */
    if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_RUN) &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_START)) {
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

      /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

      /* [Off]
         Req : 15842421  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

      /* HD SRS Req: 20675042  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

      /* Off  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* HD SRS Req: 20675425
         Clearing PopupDispInfo in Off state based on customer feedback */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

      /* Fix for Disp20 show it only once  */
    } else {
      /*  HD SRS Req: 20674432, 20675205  */
      if (IbTRSC_InpBus.MeTRSC_b_InternalFault || MeTRSC_b_ExternalFault) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp8;
        TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Faulted;
        TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Fault;

        /*  HD SRS Req: 20675193 */
        TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
          TeTRSC_e_TRSCStrTrqActvReq_False;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

        /*  Req : 16127568  */
        TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

        /*  Req : 16127572  */
        TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

        /* Defect Fix 22893168,25th June 2025 */
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_OFF;
        TRSC_StateMachine_inner_default_Faulted();
      } else {
        /*  HD SRS Req: 20674859, 20675225, 20675221
           TRSC activation condition for corner case is added, 20th Jan 2025 */
        if ((TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr >
             TRSC_StateMachine_B.SignalConversion.KeTRSC_s_GearDbncTh) && (fabsf
             (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            TRSC_StateMachine_B.RelationalOperator_l) {
          TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Active;
          TRSC_StateMachine_enter_atomic_Active();

          /* Chart: '<S2>/Chart' */
          TRSC_StateMachine_inner_default_Active(rtu_MeTRSC_deg_JackKnifeAngle,
            rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
            rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
        } else {
          /*  HD SRS Req: 20675233, 20675231, 20675228, 20675226, 20675209, 20675208, 20675206,
             20674389, 20675220, 20675216, 20675215, 20675213, 20675202, 20675198, 20675197, 20674397
             Added reset logic for state machine when CustTrlrType changes conventional to non-conventional or Viceversa 4Dec2024
             Added condition when TAD state becomes 0 or 1,3rd Mar 2025 */
          if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp8) ||
              (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp10) ||
              (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp13)) {
            TRSC_StateMachine_DW.is_MainStateMachine =
              TRSC_StateMachine_IN_STANDBY;
            TRSC_StateMachine_enter_atomic_STANDBY();
            TRSC_StateMachine_inner_default_STANDBY();
          } else {
            TRSC_StateMachine_DW.MeTRSC_s_Timer3 += CeTRSC_s_TRSCLpTm;

            /*  Req : 16127199 , 16159508   */
            TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
              IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

            /*  Req : 16575524, 16101535
               01Nov2023  */
            /*  Req: 16572683 , 16101535
               01Nov2023  */
            TRSC_StateMachine_inner_default_ActiveHoldOver();
          }
        }
      }
    }
    break;

   case TRSC_StateMachine_IN_Calibration:
    /* Chart: '<S2>/Chart' */
    TRSC_StateMachine_Calibration(rtu_MeTRSC_deg_JackKnifeAngle,
      rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
      rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
    break;

   case TRSC_StateMachine_IN_Faulted:
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /*  HD SRS Req: 20675016, 20674218 */
    if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_RUN) &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_START)) {
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

      /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

      /* [Off]
         Req : 15842421  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

      /* HD SRS Req: 20675042  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

      /* Off  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* HD SRS Req: 20675425
         Clearing PopupDispInfo in Off state based on customer feedback */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

      /* Fix for Disp20 show it only once  */
    } else {
      /*  Req : 16127580, 18129223, 18939956  */
      if ((!IbTRSC_InpBus.MeTRSC_b_InternalFault) && (!MeTRSC_b_ExternalFault))
      {
        TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_STANDBY;
        TRSC_StateMachine_enter_atomic_STANDBY();
        TRSC_StateMachine_inner_default_STANDBY();
      } else {
        /* MeTRSC_s_LedTmr += CeTRSC_s_TRSCLpTm;  /$ Req : 16127572 $/ /$ 23Aug2022, Raviraj M $/ */
        TRSC_StateMachine_inner_default_Faulted();
      }
    }
    break;

   case TRSC_StateMachine_IN_OFF:
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /*  HD SRS Req: 20675018
       Added Condition to Check TRSC Present Proxi 4th Nov, 2024, Box Delete Proxi check added 2nd Apr, 2025 */
    if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts ==
          TeVBII_e_CmdIgnSts_RUN) ||
         (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts ==
          TeVBII_e_CmdIgnSts_START)) &&
        IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_b_TRSCPresent &&
        (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_BoxDelete ==
         CeConst_k_ConstZeroUint8)) {
      /*  HD SRS Req: 20675021 ,Fix for Defect#20419328 */
      TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
        TeTRSC_e_TrlrCalInfo_NotCalibrated;
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_STANDBY;
      TRSC_StateMachine_enter_atomic_STANDBY();
      TRSC_StateMachine_inner_default_STANDBY();
    }
    break;

   case TRSC_StateMachine_IN_PreActive:
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = true;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /*  HD SRS Req: 20675016, 20674207, 20674180, 20674439, 20675204  */
    if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_RUN) &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_START)) {
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

      /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

      /* [Off]
         Req : 15842421  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

      /* HD SRS Req: 20675042  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

      /* Off  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* HD SRS Req: 20675425
         Clearing PopupDispInfo in Off state based on customer feedback */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

      /* Fix for Disp20 show it only once  */
    } else {
      /*  Fix for Defect 21874311  */
      /*  HD SRS Req: 20674432, 20675205  */
      if (IbTRSC_InpBus.MeTRSC_b_InternalFault || MeTRSC_b_ExternalFault) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
          TeTRSC_e_TRSCPopupDispInfo_Disp8;
        TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Faulted;
        TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Fault;

        /*  HD SRS Req: 20675193 */
        TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
          TeTRSC_e_TRSCStrTrqActvReq_False;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

        /*  Req : 16127568  */
        TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

        /*  Req : 16127572  */
        TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

        /* Defect Fix 22893168,25th June 2025 */
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_OFF;
        TRSC_StateMachine_inner_default_Faulted();
      } else {
        /*  HD SRS Req: 20674188, 20674187,
           TRSC activation condition for corner case is added, 20th Jan 2025 */
        if ((TRSC_StateMachine_DW.MeTRSC_s_RevGearDbncTmr >
             TRSC_StateMachine_B.SignalConversion.KeTRSC_s_GearDbncTh) &&
            (TRSC_StateMachine_DW.MeTRSC_s_Timer2 < KeTRSC_s_TenMinTh) &&
            (!IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus) &&
            (TRSC_StateMachine_B.Gain7 < CeConst_mph_VehSpeedThr) && (fabsf
             (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) <=
             TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
            TRSC_StateMachine_B.RelationalOperator_l) {
          TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Active;
          TRSC_StateMachine_enter_atomic_Active();

          /* Chart: '<S2>/Chart' */
          TRSC_StateMachine_inner_default_Active(rtu_MeTRSC_deg_JackKnifeAngle,
            rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
            rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
        } else {
          /* HD SRS Req: 20674175, 20674796, 20674793, 20684864, 20684866, 20684868, 20674805, 20674803,
             20674779, 20674776, 20674177
             Added fix for defect 21108369 25Jan2024
             Added reset logic for state machine when CustTrlrType changes conventional to non-conventional
             or Viceversa 4Dec2024
             Added condition when TAD state becomes 0 or 1,3rd Mar 2025 */
          if ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp8) ||
              (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp10) ||
              (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
               TeTRSC_e_TRSCPopupDispInfo_Disp13)) {
            TRSC_StateMachine_DW.is_MainStateMachine =
              TRSC_StateMachine_IN_STANDBY;
            TRSC_StateMachine_enter_atomic_STANDBY();
            TRSC_StateMachine_inner_default_STANDBY();
          } else {
            TRSC_StateMachine_DW.MeTRSC_s_Timer2 += CeTRSC_s_TRSCLpTm;

            /* HD SRS Req: 20675460  */
            TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
              IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

            /*  HD SRS Req: 20675094  */
            /*  HD SRS Req: 20674419  */
            TRSC_StateMachine_inner_default_PreActive();
          }
        }
      }
    }
    break;

   default:
    /* case IN_STANDBY: */
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /*  HD SRS Req: 20675016, 20674218 */
    if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_RUN) &&
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
         TeVBII_e_CmdIgnSts_START)) {
      /*  HD SRS Req: 20675245  */
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;
      TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
      TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
      TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
      TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

      /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

      /* [Off]
         Req : 15842421  */
      TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

      /* HD SRS Req: 20675042  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

      /* Off  */
      TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

      /* HD SRS Req: 20675425
         Clearing PopupDispInfo in Off state based on customer feedback */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
        TeTRSC_e_TrlrHitchLightCtrl_OFF;
      TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

      /* Fix for Disp20 show it only once  */
    } else {
      /*  HD SRS Req: 20674228  */
      if (IbTRSC_InpBus.MeTRSC_b_InternalFault || MeTRSC_b_ExternalFault) {
        if (!(TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) {
          TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
            TeTRSC_e_TRSCPopupDispInfo_Disp0;
        }

        /*  HD SRS Req: 20675245  */
        TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
        TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
        TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
        TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
        TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_Faulted;
        TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Fault;

        /*  HD SRS Req: 20675193 */
        TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
          TeTRSC_e_TRSCStrTrqActvReq_False;

        /*  HD SRS Req: 20674652  */
        TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;

        /*  Req : 16127568  */
        TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;

        /*  Req : 16127572  */
        TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

        /* Defect Fix 22893168,25th June 2025 */
        TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
          TeTRSC_e_TrlrHitchLightCtrl_OFF;
        TRSC_StateMachine_inner_default_Faulted();
      } else {
        /*  HD SRS Req: 20674244, 20674242   */
        if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Off) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_On) ||
             (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
              TeVBII_e_EngineSts_Engine_Cranking)) &&
            (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
             TeTRSC_e_TrlrCalInfo_NotCalibrated) && (MeTRSC_e_TrlrPrsntInfoCAN ==
             TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
             TeTRSC_e_TrlrRecogInfo_Unknown) &&
            ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp3) ||
             (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
              TeTRSC_e_TADState_Calibration))) {
          /*  17-Nov-22: Req for HD
             Added these checks to ensure necessary actions
             are taken first before switching to next state
             28-Feb-24 */
          /*  HD SRS Req: 20675245  */
          TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;
          TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
          TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
          TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
          TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
          TRSC_StateMachine_DW.is_MainStateMachine =
            TRSC_StateMachine_IN_Calibration;
          TRSC_StateMachine_enter_atomic_Calibration();
          TRSC_StateMachine_DW.is_Calibration = TRSC_StateMachine_IN_Default;
        } else {
          /*  HD SRS Req: 20674917, 20674219, 20674491
             Fix for capped JK angle in SM for activation, deactivation 28 Oct 2024,
             TRSC activation condition for corner case is added, 20th Jan 2025
             Defect22615086 fix for Disp20 show it only once, 21st Feb2025  */
          if (((IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                TeVBII_e_EngineSts_Engine_Off) ||
               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                TeVBII_e_EngineSts_Engine_On) ||
               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                TeVBII_e_EngineSts_Engine_Cranking)) &&
              ((!IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts) ||
               (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts
                == TeVBII_e_SBR1RowDriverSeatSts_SeatBeltFasten)) &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
               TeVBII_e_EscTrscBrkResp_Off) &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
               TeVBII_e_StrTrqResp_Off) &&
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
               TeVBII_e_EcmTrscResp_Off) &&
              (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
               TeTRSC_e_TrlrCalInfo_Calibrated) &&
              (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts ||
               ((TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
                 TeTRSC_e_TRSCPopupDispInfo_Disp20) &&
                TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce)) &&
              (MeTRSC_e_TrlrPrsntInfoCAN == TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
              (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrRecogInfo ==
               TeTRSC_e_TrlrRecogInfo_Known) && (fabsf
               (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle) <=
               TRSC_StateMachine_B.Switch_TAD_des_Final1) &&
              TRSC_StateMachine_B.RelationalOperator_l) {
            /*  HD SRS Req: 20674225, 20674415
               Fix for defect 21952296 24July2023 */
            if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_P) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_D) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_N) ||
                (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                 == TeVBII_e_GearEngagedForDsply_L)) {
              /*  HD SRS Req: 20675245  */
              TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
              TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
              TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
              TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
              TRSC_StateMachine_DW.is_MainStateMachine =
                TRSC_StateMachine_IN_PreActive;
              TRSC_StateMachine_enter_atomic_PreActive();
              TRSC_StateMachine_inner_default_PreActive();
            } else {
              /*  HD SRS Req: 20674225, 20674415
               /$Added Speed Threshold condition for TRSC activation, 14th Feb 2025$/ */
              if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply
                   == TeVBII_e_GearEngagedForDsply_R) &&
                  TRSC_StateMachine_B.RelationalOperator3) {
                /*  HD SRS Req: 20675245  */
                TRSC_StateMachine_DW.MeTRSC_s_LedTmr = 0.0F;
                TRSC_StateMachine_DW.MeTRSC_s_LedTmr10Sec = 0.0F;
                TRSC_StateMachine_DW.MeTRSC_s_TrlrHitchLightCtrlTimer = 0.0F;
                TRSC_StateMachine_DW.MeTRSC_s_Disp22Tmr8Sec = 0.0;
                TRSC_StateMachine_DW.MeTRSC_s_Disp19Tmr2Sec = 0.0;
                TRSC_StateMachine_DW.is_MainStateMachine =
                  TRSC_StateMachine_IN_Active;
                TRSC_StateMachine_enter_atomic_Active();

                /* Chart: '<S2>/Chart' */
                TRSC_StateMachine_inner_default_Active
                  (rtu_MeTRSC_deg_JackKnifeAngle, rtu_MeTRSC_b_StrTwitchComplete,
                   rtu_MeTRSC_M_TRSCStrTrq, rtu_MeTRSC_e_SpdLmtReq,
                   rtu_MeTRSC_pct_TRSCStrDmp);
              } else {
                guard1 = true;
              }
            }
          } else {
            guard1 = true;
          }
        }
      }
    }
    break;
  }

  if (guard1) {
    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    /* Added action when TAD state becomes Idle,28thFeb 2025
       Added conditions when TAD state becomes Idle,28thFeb 2025
       disp13 timout adjusted, 6th June 2025
       Defect fix #22917827, 17th June 2025 */
    if ((IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_Idle) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld !=
         TeTRSC_e_TRSCPopupDispInfo_Disp0) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld !=
         TeTRSC_e_TRSCPopupDispInfo_Disp13) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld !=
         TeTRSC_e_TRSCPopupDispInfo_Disp8) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld !=
         TeTRSC_e_TRSCPopupDispInfo_Disp22) &&
        (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld !=
         TeTRSC_e_TRSCPopupDispInfo_SNA)) {
      /*  HD SRS Req: 20675245  */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
        IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;
      TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_STANDBY;
      TRSC_StateMachine_enter_atomic_STANDBY();
      TRSC_StateMachine_inner_default_STANDBY();
    } else {
      /* Defect22615086 fix for Disp20 show it only once, 21st Feb2025
         MeTRSC_s_Timer +=  CeTRSC_s_TRSCLpTm; /$ Req: 16039895, 16129844 $/ */
      TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
        IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo;

      /*  HD SRS Req: 20675111  */
      TRSC_StateMachine_inner_default_STANDBY();
    }
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_OutputAsNormal(void)
{
  if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
         TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
      (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
       TeTRSC_e_TRSCPopupDispInfo_Disp5)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp5;
    TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp6)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp6;

    /* MeTRSC_s_Disp6HldTmr = single(0); */
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp6HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp6HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp7)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp7;
    TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp8)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp8;
    TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp9)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp9;
    TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_SNA)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearSNA;
    TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp10)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp10;
    TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp11)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp11;
    TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp12)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp12;
    TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp13)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp13;
    TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp19)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp19;
    TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr >=
        TRSC_StateMachine_B.SignalConversion.KeTRSC_s_TrlrUnkwnSet) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp20)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp20;
    TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr >= KeTRSC_s_TwoSecTh) {
      /*  Led Status updated to Off 15May 2025 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp22)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp22;
    TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr >= KeTRSC_s_FiveSecTh) {
      /* Fix for Disp22 not showing on consecutive button press events 20 Oct 2024 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp23)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp23;
    TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr >= KeTRSC_s_TwoSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp3)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo = TRSC_StateMachine_IN_ClearDisp3;
    TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr = 0.0F;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    if (TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr >= KeTRSC_s_TwoSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr += CeTRSC_s_TRSCLpTm;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp21)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp21;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
          TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
         (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
          TeTRSC_e_TrlrCalInfo_Calibrated)) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_AngleDetection)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    }
  } else if ((!(TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
                TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start)) &&
             (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
              TeTRSC_e_TRSCPopupDispInfo_Disp15)) {
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_ClearDisp15;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;

    /* Update for Inport: '<Root>/IbTRSC_InpBus' */
    if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
          TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
         (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
          TeTRSC_e_TrlrCalInfo_Calibrated)) ||
        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
         TeTRSC_e_TADState_AngleDetection)) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    }
  } else {
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
  }
}

/* Function for Chart: '<S2>/Chart' */
static void TRSC_StateMachine_ClearPopupDispInfo(void)
{
  switch (TRSC_StateMachine_DW.is_ClearPopupDispInfo) {
   case TRSC_StateMachine_IN_ClearDisp10:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp10) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp10HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp11:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp11) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp11HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp12:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp12) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp12HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp13:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp13) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp13HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp15:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp15) {
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else {
      if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
            TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
           (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
            TeTRSC_e_TrlrCalInfo_Calibrated)) ||
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_AngleDetection)) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
          TeTRSC_e_TRSCPopupDispInfo_Disp0;
      }
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp19:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp19) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr >=
               TRSC_StateMachine_B.SignalConversion.KeTRSC_s_TrlrUnkwnSet) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp19HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp20:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp20) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr >= KeTRSC_s_TwoSecTh)
    {
      /*  Led Status updated to Off 15May 2025 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = true;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp20HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp21:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp21) {
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else {
      if (((TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo ==
            TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt) &&
           (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
            TeTRSC_e_TrlrCalInfo_Calibrated)) ||
          (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
           TeTRSC_e_TADState_AngleDetection)) {
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
          TeTRSC_e_TRSCPopupDispInfo_Disp0;
      }
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp22:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp22) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr >= KeTRSC_s_FiveSecTh)
    {
      /* Fix for Disp22 not showing on consecutive button press events 20 Oct 2024 */
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp22HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp23:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp23) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr >= KeTRSC_s_TwoSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp23HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp3:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp3) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr >= KeTRSC_s_TwoSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp3HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp5:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp5) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp5HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp6:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp6) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp6HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp6HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp6HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp7:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp7) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp7HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp8:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp8) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp8HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearDisp9:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_Disp9) {
      TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr >= KeTRSC_s_FiveSecTh)
    {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_Disp9HldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   case TRSC_StateMachine_IN_ClearSNA:
    if (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e !=
        TeTRSC_e_TRSCPopupDispInfo_SNA) {
      TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr = 0.0F;
      TRSC_StateMachine_DW.is_ClearPopupDispInfo =
        TRSC_StateMachine_IN_OutputAsNormal;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
    } else if (TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr >= KeTRSC_s_FiveSecTh) {
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
        TeTRSC_e_TRSCPopupDispInfo_Disp0;
      TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
    } else {
      TRSC_StateMachine_DW.MeTRSC_s_SNAHldTmr += CeTRSC_s_TRSCLpTm;
    }
    break;

   default:
    /* case IN_OutputAsNormal: */
    TRSC_StateMachine_OutputAsNormal();
    break;
  }
}

/* System initialize for referenced model: 'TRSC_StateMachine' */
void TRSC_StateMachine_Init(void)
{
  /* SystemInitialize for Enabled SubSystem: '<S2>/OverSpeed_Check' */
  /* InitializeConditions for UnitDelay: '<S36>/UnitDelay3' */
  TRSC_StateMachine_DW.UnitDelay3_DSTATE_a = 0.0F;

  /* InitializeConditions for UnitDelay: '<S37>/UnitDelay3' */
  TRSC_StateMachine_DW.UnitDelay3_DSTATE_my = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S2>/OverSpeed_Check' */

  /* SystemInitialize for Chart: '<S2>/Chart' */
  TRSC_StateMachine_DW.MeTRSC_e_SmTrlrPrsntInfo = TeTRSC_e_TrlrPrsntInfo_NoTrlr;
  TRSC_StateMachine_DW.MeTRSC_e_Direction = TeVBII_e_Direction_Straight;
  TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Standby;
  TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;
  TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i =
    TeTRSC_e_TRSCStrTrqActvReq_False;
  TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i = TeTRSC_e_VehStpReq_False;
  TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;
  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
    TeTRSC_e_TRSCPopupDispInfo_Disp0;
  TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k = TeTRSC_e_SpdLmtReq_NotLim;
  TRSC_StateMachine_B.IeTRSC_pct_TRSCStrDmp_b = 0.0F;
  TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n = 0.0F;
  TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
    TeTRSC_e_TrlrHitchLightCtrl_OFF;
  TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo =
    TeTRSC_e_TrlrCalInfo_NotCalibrated;
  TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
    TeTRSC_e_TRSCPopupDispInfo_Disp0;
  TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev =
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
  TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start =
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
}

/* Disable for referenced model: 'TRSC_StateMachine' */
void TRSC_StateMachine_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S2>/OverSpeed_Check' */
  if (TRSC_StateMachine_DW.OverSpeed_Check_MODE) {
    /* Disable for Outport: '<S16>/MaxSpdLimThr' */
    TRSC_StateMachine_B.RelationalOperator_f = false;
    TRSC_StateMachine_DW.OverSpeed_Check_MODE = false;
  }

  /* End of Disable for SubSystem: '<S2>/OverSpeed_Check' */
}

/* Output and update for referenced model: 'TRSC_StateMachine' */
void TRSC_StateMachine(const real32_T *rtu_MeTRSC_deg_JackKnifeAngle, const
  boolean_T *rtu_MeTRSC_b_StrTwitchComplete, const real32_T
  *rtu_MeTRSC_M_TRSCStrTrq, const TeTRSC_e_SpdLmtReq *rtu_MeTRSC_e_SpdLmtReq,
  const real32_T *rtu_MeTRSC_pct_TRSCStrDmp, const real32_T
  *rtu_MeTRSC_m_TrailerBeamLen)
{
  int32_T k;
  uint8_T tmp;

  /* Delay: '<S2>/Delay One Step2' */
  TRSC_StateMachine_B.DelayOneStep2 = TRSC_StateMachine_B.Compare;

  /* Delay: '<S2>/Delay One Step1' */
  TRSC_StateMachine_B.LogicalOperator_k =
    TRSC_StateMachine_DW.DelayOneStep1_DSTATE;

  /* Logic: '<S2>/NOT2' */
  TRSC_StateMachine_B.LogicalOperator_k = !TRSC_StateMachine_B.LogicalOperator_k;

  /* Logic: '<S2>/AND1' */
  TRSC_StateMachine_B.AND1 = (TRSC_StateMachine_B.DelayOneStep2 &&
    TRSC_StateMachine_B.LogicalOperator_k);

  /* DataTypeConversion: '<S2>/Data Type Conversion25' */
  TRSC_StateMachine_B.DataTypeConversion25_a = (uint8_T)*rtu_MeTRSC_e_SpdLmtReq;

  /* Outputs for Enabled SubSystem: '<S2>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (TRSC_StateMachine_B.DelayOneStep2) {
    /* MATLAB Function: '<S14>/MATLAB Function2' */
    if ((!TRSC_StateMachine_DW.buffer_not_empty) || TRSC_StateMachine_B.AND1) {
      memset(&TRSC_StateMachine_DW.buffer[0], 0, 100U * sizeof(uint8_T));
      TRSC_StateMachine_DW.buffer_not_empty = true;
      TRSC_StateMachine_DW.index = 1U;
    }

    TRSC_StateMachine_DW.buffer[TRSC_StateMachine_DW.index - 1] =
      TRSC_StateMachine_B.DataTypeConversion25_a;
    k = (int32_T)((uint8_T)((uint32_T)TRSC_StateMachine_DW.index - (uint8_T)
      (TRSC_StateMachine_DW.index / 100U * 100U)) + 1U);
    if ((uint32_T)k > 255U) {
      k = 255;
    }

    TRSC_StateMachine_DW.index = (uint8_T)k;
    TRSC_StateMachine_B.max_val = TRSC_StateMachine_DW.buffer[0];
    for (k = 0; k < 99; k++) {
      tmp = TRSC_StateMachine_DW.buffer[k + 1];
      if (TRSC_StateMachine_B.max_val < tmp) {
        TRSC_StateMachine_B.max_val = tmp;
      }
    }

    memcpy(&TRSC_StateMachine_B.buffer_out[0], &TRSC_StateMachine_DW.buffer[0],
           100U * sizeof(uint8_T));

    /* End of MATLAB Function: '<S14>/MATLAB Function2' */
  }

  /* End of Outputs for SubSystem: '<S2>/Enabled Subsystem' */

  /* Saturate: '<S2>/Saturation' */
  if (TRSC_StateMachine_B.max_val > ((uint8_T)7U)) {
    TRSC_StateMachine_B.UnitDelay_h = ((uint8_T)7U);
  } else if (TRSC_StateMachine_B.max_val < ((uint8_T)1U)) {
    TRSC_StateMachine_B.UnitDelay_h = ((uint8_T)1U);
  } else {
    TRSC_StateMachine_B.UnitDelay_h = TRSC_StateMachine_B.max_val;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* DataTypeConversion: '<S2>/Data Type Conversion26' */
  TRSC_StateMachine_B.DataTypeConversion26 = TRSC_StateMachine_B.UnitDelay_h;

  /* Gain: '<Root>/Gain7' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.Gain7 = 0.62137F *
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_kph_VehSpeedVSOSig;

  /* SignalConversion: '<Root>/Signal Conversion' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.SignalConversion = IbTRSC_InpBus.IbTRSCSmVc_TunParam;

  /* UnitDelay: '<S3>/Unit Delay' */
  TRSC_StateMachine_B.Switch7 = TRSC_StateMachine_DW.UnitDelay_DSTATE;

  /* RelationalOperator: '<S3>/Relational Operator' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo >
     TRSC_StateMachine_B.Switch7);

  /* UnitDelay: '<S3>/Unit Delay1' */
  TRSC_StateMachine_B.LogicalOperator_k = TRSC_StateMachine_DW.UnitDelay1_DSTATE;

  /* Logic: '<S3>/Logical Operator' */
  TRSC_StateMachine_B.LogicalOperator = (TRSC_StateMachine_B.RelationalOperator ||
    TRSC_StateMachine_B.LogicalOperator_k);

  /* RelationalOperator: '<S19>/Relational Operator' incorporates:
   *  Constant: '<S44>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_k =
    (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_RadDsplyTyp ==
     TeTRSC_e_RadDsplyTyp_two);

  /* RelationalOperator: '<S19>/Relational Operator1' incorporates:
   *  Constant: '<S45>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_RadDsplyTyp ==
     TeTRSC_e_RadDsplyTyp_seven);

  /* RelationalOperator: '<S19>/Relational Operator2' incorporates:
   *  Constant: '<S46>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator3 =
    (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_RadDsplyTyp ==
     TeTRSC_e_RadDsplyTyp_nine);

  /* Logic: '<S19>/Logical Operator' */
  TRSC_StateMachine_B.LogicalOperator_k = (TRSC_StateMachine_B.LogicalOperator_k
    || TRSC_StateMachine_B.RelationalOperator_lc ||
    TRSC_StateMachine_B.LogicalOperator3);

  /* Logic: '<S19>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   */
  TRSC_StateMachine_B.LogicalOperator_k = (TRSC_StateMachine_B.LogicalOperator_k
    || KeTRSC_b_BypassRadDsplyTyp);

  /* Switch: '<S19>/Switch' incorporates:
   *  Constant: '<S43>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_StateMachine_B.LogicalOperator_k) {
    TRSC_StateMachine_B.Switch_d =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrscEnblBtnSts;
  } else {
    TRSC_StateMachine_B.Switch_d = TeVBII_e_TrscEnblBtnSts_NotPressed;
  }

  /* End of Switch: '<S19>/Switch' */

  /* RelationalOperator: '<S18>/Relational Operator7' incorporates:
   *  Constant: '<S41>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator3 =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrlrPrsntSts ==
     TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S18>/Logical Operator15' incorporates:
   *  Constant: '<S18>/Constant1'
   */
  TRSC_StateMachine_B.LogicalOperator3 = (true &&
    TRSC_StateMachine_B.LogicalOperator3);

  /* RelationalOperator: '<S18>/Relational Operator8' incorporates:
   *  Constant: '<S42>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* Logic: '<S18>/Logical Operator13' incorporates:
   *  Constant: '<S18>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = (true &&
    TRSC_StateMachine_B.RelationalOperator_lc);

  /* Logic: '<S18>/Logical Operator14' */
  TRSC_StateMachine_B.LogicalOperator3 = (TRSC_StateMachine_B.LogicalOperator3 ||
    TRSC_StateMachine_B.RelationalOperator_lc);

  /* Switch: '<S18>/Switch3' incorporates:
   *  Constant: '<S39>/Constant'
   *  Constant: '<S40>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator3) {
    TRSC_StateMachine_B.Switch3_kh = TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt;
  } else {
    TRSC_StateMachine_B.Switch3_kh = TeTRSC_e_TrlrPrsntInfo_NoTrlr;
  }

  /* End of Switch: '<S18>/Switch3' */

  /* DataTypeConversion: '<S18>/Data Type Conversion' */
  MeTRSC_e_TrlrPrsntInfoCAN = TRSC_StateMachine_B.Switch3_kh;

  /* Chart: '<S2>/Chart3' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_StateMachine_DW.is_active_c1_TRSC_StateMachine == 0U) {
    TRSC_StateMachine_DW.is_active_c1_TRSC_StateMachine = 1U;
    TRSC_StateMachine_DW.is_c1_TRSC_StateMachine = TRSC_StateMachine_IN_OFF_d;
    TRSC_StateMachine_B.StrTchDctc = false;
  } else {
    switch (TRSC_StateMachine_DW.is_c1_TRSC_StateMachine) {
     case TRSC_StateMachine_IN_DELAY:
      if (!IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts) {
        TRSC_StateMachine_DW.is_c1_TRSC_StateMachine =
          TRSC_StateMachine_IN_OFF_d;
        TRSC_StateMachine_B.StrTchDctc = false;
      } else if (TRSC_StateMachine_DW.t > KeTRSC_cnt_DrvOvrdTurnOnDlyTime) {
        TRSC_StateMachine_DW.is_c1_TRSC_StateMachine = TRSC_StateMachine_IN_ON;
        TRSC_StateMachine_B.StrTchDctc = true;
      } else {
        TRSC_StateMachine_DW.t += CeTRA_sec_SampleTime;
      }
      break;

     case TRSC_StateMachine_IN_OFF_d:
      TRSC_StateMachine_B.StrTchDctc = false;
      if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts) {
        TRSC_StateMachine_DW.is_c1_TRSC_StateMachine =
          TRSC_StateMachine_IN_DELAY;
        TRSC_StateMachine_DW.t = 0.0F;
      }
      break;

     default:
      /* case IN_ON: */
      TRSC_StateMachine_B.StrTchDctc = true;
      if (!IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts) {
        TRSC_StateMachine_DW.is_c1_TRSC_StateMachine =
          TRSC_StateMachine_IN_OFF_d;
        TRSC_StateMachine_B.StrTchDctc = false;
      }
      break;
    }
  }

  /* End of Chart: '<S2>/Chart3' */

  /* Delay: '<S2>/Delay2' incorporates:
   *  Constant: '<S2>/Constant9'
   */
  if (KeTRSC_cnt_AvgSampleCnt <= 0) {
    TRSC_StateMachine_B.Delay2 = *rtu_MeTRSC_M_TRSCStrTrq;
  } else {
    TRSC_StateMachine_B.Delay2 = TRSC_StateMachine_DW.Delay2_DSTATE[(uint8_T)
      (255U - KeTRSC_cnt_AvgSampleCnt)];
  }

  /* End of Delay: '<S2>/Delay2' */

  /* Abs: '<S2>/Abs' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.Gain7_c = fabsf
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng);

  /* RelationalOperator: '<S15>/Relational Operator3' incorporates:
   *  Constant: '<S15>/Constant9'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator3 =
    (IbTRSC_InpBus.IbTRSC_MEProxiToIpc.IePRX_e_StrRackPinTyp ==
     TeTRSC_e_StrRackPinTyp_Type2);

  /* Switch: '<S15>/Switch' incorporates:
   *  Constant: '<S15>/Constant1'
   *  Constant: '<S15>/Constant5'
   */
  if (TRSC_StateMachine_B.LogicalOperator3) {
    TRSC_StateMachine_B.Sum_k = KeTRSC_deg_MaxStrAngTyp2;
  } else {
    TRSC_StateMachine_B.Sum_k = KeTRSC_deg_MaxStrAngTyp1;
  }

  /* End of Switch: '<S15>/Switch' */

  /* Product: '<S2>/Product' incorporates:
   *  Constant: '<S2>/Constant10'
   */
  TRSC_StateMachine_B.Sum_k *= KeTRSC_k_StrTrqPercThresholdForDrvOvrd;

  /* RelationalOperator: '<S2>/Relational Operator4' */
  TRSC_StateMachine_B.LogicalOperator3 = (TRSC_StateMachine_B.Gain7_c >=
    TRSC_StateMachine_B.Sum_k);

  /* Logic: '<S2>/Logical Operator8' incorporates:
   *  Constant: '<S2>/Constant8'
   */
  TRSC_StateMachine_B.LogicalOperator3 = (KeTRSC_b_EnblDrvDctcOvrd &&
    TRSC_StateMachine_B.LogicalOperator3);

  /* Switch: '<S2>/Switch5' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_StateMachine_B.LogicalOperator3) {
    /* DataTypeConversion: '<S2>/Data Type Conversion28' incorporates:
     *  Constant: '<S2>/Constant5'
     */
    TRSC_StateMachine_B.DataTypeConversion28 = KeTRSC_cnt_AvgSampleCnt;

    /* Sum: '<S2>/Add2' */
    TRSC_StateMachine_B.Abs2 = *rtu_MeTRSC_M_TRSCStrTrq -
      TRSC_StateMachine_B.Delay2;

    /* Product: '<S2>/Divide2' incorporates:
     *  Constant: '<S2>/Constant6'
     */
    TRSC_StateMachine_B.Abs2 = TRSC_StateMachine_B.Abs2 / CeTRA_sec_SampleTime /
      TRSC_StateMachine_B.DataTypeConversion28;

    /* Abs: '<S2>/Abs2' */
    TRSC_StateMachine_B.Abs2 = fabsf(TRSC_StateMachine_B.Abs2);

    /* RelationalOperator: '<S2>/Relational Operator1' incorporates:
     *  Constant: '<S2>/Constant7'
     */
    TRSC_StateMachine_B.RelationalOperator1_e = (TRSC_StateMachine_B.Abs2 <
      KeTRSC_dM_StrTrqCmdRateLmtForDrvOvrd);

    /* Logic: '<S2>/Logical Operator7' */
    TRSC_StateMachine_B.LogicalOperator7 = (TRSC_StateMachine_B.StrTchDctc &&
      TRSC_StateMachine_B.RelationalOperator1_e);
    TRSC_StateMachine_B.Switch5_o = TRSC_StateMachine_B.LogicalOperator7;
  } else {
    TRSC_StateMachine_B.Switch5_o =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts;
  }

  /* End of Switch: '<S2>/Switch5' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.MeTRSC_e_CamBlockSts = IbTRSC_InpBus.MeTRSC_e_CamBlockSts;

  /* Logic: '<S31>/Logical Operator1' incorporates:
   *  Constant: '<S31>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  MeTRSC_b_ExternalFault =
    (IbTRSC_InpBus.IbDDC_DegMgrToTRSC.IeDDC_b_TRSCDisabled &&
     KeTRSC_b_EnblExtFault);

  /* DataTypeConversion: '<S2>/Data Type Conversion24' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.IeVBII_e_CustTrlrType = (uint8_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CustTrlrType;

  /* UnitDelay: '<S2>/Unit Delay' */
  TRSC_StateMachine_B.UnitDelay_h = TRSC_StateMachine_DW.UnitDelay_DSTATE_i;

  /* RelationalOperator: '<S2>/Relational Operator' */
  TRSC_StateMachine_B.RelationalOperator_g =
    (TRSC_StateMachine_B.IeVBII_e_CustTrlrType !=
     TRSC_StateMachine_B.UnitDelay_h);

  /* Gain: '<S2>/Gain1' incorporates:
   *  Constant: '<S2>/KeTRSC_pct_JackKnifePerc1'
   */
  TRSC_StateMachine_B.Sum_k = 0.01F * KeTRSC_pct_JackKnifePerc;

  /* Product: '<S2>/Product3' */
  TRSC_StateMachine_B.Product3 = *rtu_MeTRSC_deg_JackKnifeAngle *
    TRSC_StateMachine_B.Sum_k;

  /* RelationalOperator: '<S2>/Relational Operator5' incorporates:
   *  Constant: '<S2>/KeTRSC_m_DesAnglScaleTBLThr1'
   */
  TRSC_StateMachine_B.LogicalOperator3 = (*rtu_MeTRSC_m_TrailerBeamLen <
    KeTRSC_m_DesAnglScaleTBLThrSM);

  /* Switch: '<S2>/Switch_TAD_des_Final1' */
  if (TRSC_StateMachine_B.LogicalOperator3) {
    /* Product: '<S2>/Product2' incorporates:
     *  Constant: '<S2>/KeTRSC_ddeg_TadDesRateLim2'
     */
    TRSC_StateMachine_B.Product2 = TRSC_StateMachine_B.Product3 *
      KeTRSC_pct_TrlrAngScaleDwnPctSM;
    TRSC_StateMachine_B.Switch_TAD_des_Final1 = TRSC_StateMachine_B.Product2;
  } else {
    TRSC_StateMachine_B.Switch_TAD_des_Final1 = TRSC_StateMachine_B.Product3;
  }

  /* End of Switch: '<S2>/Switch_TAD_des_Final1' */

  /* RelationalOperator: '<S13>/Compare' incorporates:
   *  Constant: '<S13>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator3 =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng <=
     KeTRSC_k_PosSteerWheelThreshold);

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_deg_StrWhlAng >=
     KeTRSC_k_NegSteerWheelThreshold);

  /* Logic: '<S2>/Logical Operator6' */
  TRSC_StateMachine_B.LogicalOperator3 = (TRSC_StateMachine_B.LogicalOperator3 &&
    TRSC_StateMachine_B.RelationalOperator_lc);

  /* RelationalOperator: '<S10>/Compare' incorporates:
   *  Constant: '<S10>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle >=
     KeTRSC_k_NegativeTadAngleThreshold);

  /* RelationalOperator: '<S9>/Compare' incorporates:
   *  Constant: '<S9>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_k =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle <=
     KeTRSC_k_PositiveTadAngleThreshold);

  /* Logic: '<S2>/Logical Operator4' */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.RelationalOperator_lc &&
     TRSC_StateMachine_B.LogicalOperator_k);

  /* Logic: '<S2>/Logical Operator3' */
  TRSC_StateMachine_B.LogicalOperator3 = (TRSC_StateMachine_B.LogicalOperator3 &&
    TRSC_StateMachine_B.RelationalOperator_lc);

  /* Logic: '<S2>/Logical Operator5' */
  TRSC_StateMachine_B.RelationalOperator_lc =
    !TRSC_StateMachine_B.LogicalOperator3;

  /* UnitDelay: '<S34>/UnitDelay3' */
  TRSC_StateMachine_B.Sum_k = TRSC_StateMachine_B.MinMax_c;

  /* Switch: '<S34>/Switch1' incorporates:
   *  Constant: '<S34>/Constant4'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Sum_k = 0.0F;
  }

  /* End of Switch: '<S34>/Switch1' */

  /* Sum: '<S34>/Sum1' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  TRSC_StateMachine_B.Gain7_c = KeTRSC_s_TRSCCornerCasAtc -
    TRSC_StateMachine_B.Sum_k;

  /* Gain: '<S34>/Gain' incorporates:
   *  Constant: '<S2>/Constant3'
   */
  TRSC_StateMachine_B.Switch3_i = 0.99F * CeTRSC_s_TRSCLpTm;

  /* RelationalOperator: '<S34>/Relational Operator' */
  TRSC_StateMachine_B.RelationalOperator_l = (TRSC_StateMachine_B.Gain7_c <
    TRSC_StateMachine_B.Switch3_i);

  /* RelationalOperator: '<S2>/Relational Operator3' incorporates:
   *  Constant: '<S2>/KeTRSC_mph_SpdThrActivation'
   */
  TRSC_StateMachine_B.RelationalOperator3 = (TRSC_StateMachine_B.Gain7 <
    KeTRSC_mph_SpdThrActivation);

  /* Delay: '<S2>/Delay One Step3' */
  TRSC_StateMachine_B.DelayOneStep3 = TRSC_StateMachine_B.Compare_n;

  /* Outputs for Enabled SubSystem: '<S2>/OverSpeed_Check' incorporates:
   *  EnablePort: '<S16>/Enable'
   */
  if (TRSC_StateMachine_B.DelayOneStep3) {
    if (!TRSC_StateMachine_DW.OverSpeed_Check_MODE) {
      /* InitializeConditions for UnitDelay: '<S36>/UnitDelay3' */
      TRSC_StateMachine_DW.UnitDelay3_DSTATE_a = 0.0F;

      /* InitializeConditions for UnitDelay: '<S37>/UnitDelay3' */
      TRSC_StateMachine_DW.UnitDelay3_DSTATE_my = 0.0F;
      TRSC_StateMachine_DW.OverSpeed_Check_MODE = true;
    }

    /* Gain: '<S36>/Gain' incorporates:
     *  Constant: '<S16>/Constant1'
     */
    TRSC_StateMachine_B.Switch3_i = 0.99F * CeTRSC_s_TRSCLpTm;

    /* Product: '<S16>/Product1' incorporates:
     *  Constant: '<S16>/Constant2'
     *  Constant: '<S16>/Constant3'
     */
    TRSC_StateMachine_B.Gain7_c = CeTRSC_s_TRSCLpTm * KeTRSC_cnt_ResetOvrSpdThr;

    /* Gain: '<S16>/Gain1' incorporates:
     *  Constant: '<S16>/Constant13'
     */
    TRSC_StateMachine_B.Sum = 0.62137F * KeTRSC_kph_MaxSpdLimThr;

    /* RelationalOperator: '<S16>/Relational Operator5' */
    TRSC_StateMachine_B.LogicalOperator_m = (TRSC_StateMachine_B.Gain7 >=
      TRSC_StateMachine_B.Sum);

    /* UnitDelay: '<S36>/UnitDelay3' */
    TRSC_StateMachine_B.Sum = TRSC_StateMachine_DW.UnitDelay3_DSTATE_a;

    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S36>/Constant4'
     */
    if (TRSC_StateMachine_B.LogicalOperator_m) {
      TRSC_StateMachine_B.Sum = 0.0F;
    }

    /* End of Switch: '<S36>/Switch1' */

    /* Sum: '<S36>/Sum1' */
    TRSC_StateMachine_B.Gain_e = TRSC_StateMachine_B.Gain7_c -
      TRSC_StateMachine_B.Sum;

    /* RelationalOperator: '<S36>/Relational Operator' */
    TRSC_StateMachine_B.RelationalOperator_lc = (TRSC_StateMachine_B.Gain_e <
      TRSC_StateMachine_B.Switch3_i);

    /* UnitDelay: '<S37>/UnitDelay3' */
    TRSC_StateMachine_B.Gain_e = TRSC_StateMachine_DW.UnitDelay3_DSTATE_my;

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant4'
     */
    if (TRSC_StateMachine_B.RelationalOperator_lc) {
      TRSC_StateMachine_B.Gain_e = 0.0F;
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Switch: '<S37>/Switch3' incorporates:
     *  Constant: '<S16>/Constant11'
     *  Constant: '<S37>/Constant2'
     */
    if (TRSC_StateMachine_B.LogicalOperator_m) {
      TRSC_StateMachine_B.Switch3_i = CeTRSC_s_TRSCLpTm;
    } else {
      TRSC_StateMachine_B.Switch3_i = 0.0F;
    }

    /* End of Switch: '<S37>/Switch3' */

    /* Sum: '<S37>/Sum' */
    TRSC_StateMachine_B.Switch3_i += TRSC_StateMachine_B.Gain_e;

    /* Product: '<S16>/Product2' incorporates:
     *  Constant: '<S16>/Constant12'
     *  Constant: '<S16>/Constant14'
     */
    TRSC_StateMachine_B.Switch3_k = CeTRSC_s_TRSCLpTm * KeTRSC_cnt_OvrSpdThr;

    /* MinMax: '<S37>/MinMax' */
    TRSC_StateMachine_B.MinMax_h = fminf(TRSC_StateMachine_B.Switch3_i,
      TRSC_StateMachine_B.Switch3_k);

    /* Sum: '<S37>/Sum1' */
    TRSC_StateMachine_B.Switch3_k -= TRSC_StateMachine_B.Gain_e;

    /* Gain: '<S37>/Gain' incorporates:
     *  Constant: '<S16>/Constant11'
     */
    TRSC_StateMachine_B.Gain_e = 0.99F * CeTRSC_s_TRSCLpTm;

    /* RelationalOperator: '<S37>/Relational Operator' */
    TRSC_StateMachine_B.RelationalOperator_f = (TRSC_StateMachine_B.Switch3_k <
      TRSC_StateMachine_B.Gain_e);

    /* Logic: '<S16>/Logical Operator9' */
    TRSC_StateMachine_B.LogicalOperator_m =
      !TRSC_StateMachine_B.LogicalOperator_m;

    /* Switch: '<S36>/Switch3' incorporates:
     *  Constant: '<S16>/Constant1'
     *  Constant: '<S36>/Constant2'
     */
    if (TRSC_StateMachine_B.LogicalOperator_m) {
      TRSC_StateMachine_B.Switch3_k = CeTRSC_s_TRSCLpTm;
    } else {
      TRSC_StateMachine_B.Switch3_k = 0.0F;
    }

    /* End of Switch: '<S36>/Switch3' */

    /* Sum: '<S36>/Sum' */
    TRSC_StateMachine_B.Sum += TRSC_StateMachine_B.Switch3_k;

    /* MinMax: '<S36>/MinMax' */
    TRSC_StateMachine_B.MinMax_f = fminf(TRSC_StateMachine_B.Sum,
      TRSC_StateMachine_B.Gain7_c);

    /* Update for UnitDelay: '<S36>/UnitDelay3' */
    TRSC_StateMachine_DW.UnitDelay3_DSTATE_a = TRSC_StateMachine_B.MinMax_f;

    /* Update for UnitDelay: '<S37>/UnitDelay3' */
    TRSC_StateMachine_DW.UnitDelay3_DSTATE_my = TRSC_StateMachine_B.MinMax_h;
  } else {
    if (TRSC_StateMachine_DW.OverSpeed_Check_MODE) {
      /* Disable for Outport: '<S16>/MaxSpdLimThr' */
      TRSC_StateMachine_B.RelationalOperator_f = false;
      TRSC_StateMachine_DW.OverSpeed_Check_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S2>/OverSpeed_Check' */

  /* Chart: '<S2>/Chart' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_StateMachine_DW.temporalCounter_i1 < 127U) {
    TRSC_StateMachine_DW.temporalCounter_i1++;
  }

  TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev =
    TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start;
  TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start =
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
  TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_prev =
    TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_start;
  TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_start =
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts;
  TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_prev =
    TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_start;
  TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_start =
    TRSC_StateMachine_B.Switch_d;
  if (TRSC_StateMachine_DW.is_active_c3_TRSC_StateMachine == 0U) {
    TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_prev =
      IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts;
    TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_prev =
      TRSC_StateMachine_B.Switch_d;
    TRSC_StateMachine_DW.is_active_c3_TRSC_StateMachine = 1U;
    TRSC_StateMachine_DW.is_ButtonProcessor = TRSC_StateMachine_IN_ButtonOff;
    TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts = false;
    TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed = false;
    TRSC_StateMachine_DW.is_MainStateMachine = TRSC_StateMachine_IN_OFF;

    /* IeTRSC_e_TRSCSts as Off when in Off state, 5th Nov,2024  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i = TeTRSC_e_TRSCSts_Off;

    /* [Off]
       Req : 15842421  */
    TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p = TeTRSC_e_TRSCStat_Off;

    /* HD SRS Req: 20675042  */
    TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b = TeTRSC_e_TRSCLedSts_Off;

    /* Off  */
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f = false;

    /* HD SRS Req: 20675425
       Clearing PopupDispInfo in Off state based on customer feedback */
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e =
      TeTRSC_e_TRSCPopupDispInfo_Disp0;
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_OFF;
    TRSC_StateMachine_DW.MeTRSC_b_MesgClearance = false;
    TRSC_StateMachine_DW.MeTRSC_b_Disp20ShownOnce = false;

    /* Fix for Disp20 show it only once  */
    TRSC_StateMachine_DW.is_ClearPopupDispInfo =
      TRSC_StateMachine_IN_OutputAsNormal;
    TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld =
      TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e;
  } else {
    switch (TRSC_StateMachine_DW.is_ButtonProcessor) {
     case TRSC_StateMachine_IN_ButtonOff:
      if ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts ==
           TeVBII_e_EnblBtnSts_Pressed) || (TRSC_StateMachine_B.Switch_d ==
           TeVBII_e_TrscEnblBtnSts_Pressed) ||
          ((TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_prev !=
            TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_start) &&
           (TRSC_StateMachine_DW.IeVBII_e_EnblBtnSts_start ==
            TeVBII_e_EnblBtnSts_Pressed)) ||
          ((TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_prev !=
            TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_start) &&
           (TRSC_StateMachine_DW.IeVBII_e_TrscEnblBtnSts_start ==
            TeVBII_e_TrscEnblBtnSts_Pressed))) {
        TRSC_StateMachine_DW.is_ButtonProcessor =
          TRSC_StateMachine_IN_WaitForFallingEdge;
        TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed =
          ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts ==
            TeVBII_e_EnblBtnSts_Pressed) ||
           TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed);
        TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed =
          ((TRSC_StateMachine_B.Switch_d == TeVBII_e_TrscEnblBtnSts_Pressed) ||
           TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed);
      }
      break;

     case TRSC_StateMachine_IN_ButtonOn:
      if ((TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_prev !=
           TRSC_StateMachine_DW.IeTRSC_e_TRSCPopupDispInfo_start) ||
          (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfo_e ==
           TeTRSC_e_TRSCPopupDispInfo_Disp8)) {
        /*  [ ((~hasChangedTo(IeTRSC_e_TRSCPopupDispInfo, TeTRSC_e_TRSCPopupDispInfo.Disp9)) &&hasChanged(IeTRSC_e_TRSCPopupDispInfo))]  */
        TRSC_StateMachine_DW.is_ButtonProcessor = TRSC_StateMachine_IN_ButtonOff;
        TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts = false;
        TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed = false;
      }
      break;

     default:
      /* case IN_WaitForFallingEdge: */
      if ((TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed &&
           (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts ==
            TeVBII_e_EnblBtnSts_NotPressed)) ||
          (TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed &&
           (TRSC_StateMachine_B.Switch_d == TeVBII_e_TrscEnblBtnSts_NotPressed)))
      {
        TRSC_StateMachine_DW.is_ButtonProcessor = TRSC_StateMachine_IN_ButtonOn;
        TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts = true;
        TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed = false;
        TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed = false;
      } else {
        TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed =
          ((IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts ==
            TeVBII_e_EnblBtnSts_Pressed) ||
           TRSC_StateMachine_DW.MeTRSC_b_EnblBtnStsPressed);
        TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed =
          ((TRSC_StateMachine_B.Switch_d == TeVBII_e_TrscEnblBtnSts_Pressed) ||
           TRSC_StateMachine_DW.MeTRSC_b_TrscEnblBtnStsPressed);
      }
      break;
    }

    TRSC_StateMachine_MainStateMachine(rtu_MeTRSC_deg_JackKnifeAngle,
      rtu_MeTRSC_b_StrTwitchComplete, rtu_MeTRSC_M_TRSCStrTrq,
      rtu_MeTRSC_e_SpdLmtReq, rtu_MeTRSC_pct_TRSCStrDmp);
    TRSC_StateMachine_ClearPopupDispInfo();
  }

  /* End of Chart: '<S2>/Chart' */

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  TRSC_StateMachine_B.Compare = (TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p ==
    TeTRSC_e_TRSCStat_Active);

  /* Switch: '<S2>/Switch4' incorporates:
   *  Constant: '<S2>/KeTRSC_ddeg_TrqRateLim'
   *  Constant: '<S2>/KeTRSC_ddeg_TrqRateLim1'
   */
  if (TRSC_StateMachine_B.Compare) {
    TRSC_StateMachine_B.Switch3_i = KeTRSC_k_TrqConstRateLim;
  } else {
    TRSC_StateMachine_B.Switch3_i = KeTRSC_ddeg_SmTrqRateLimNonActv;
  }

  /* End of Switch: '<S2>/Switch4' */

  /* Gain: '<S2>/Gain7' */
  TRSC_StateMachine_B.Gain7_c = (-1.0F) * TRSC_StateMachine_B.Switch3_i;

  /* SampleTimeMath: '<S17>/sample time'
   *
   * About '<S17>/sample time':
   *  y = K where K = ( w * Ts )
   */
  TRSC_StateMachine_B.sampletime = 0.03F;

  /* Product: '<S17>/delta fall limit' */
  TRSC_StateMachine_B.deltafalllimit = TRSC_StateMachine_B.Gain7_c *
    TRSC_StateMachine_B.sampletime;

  /* UnitDelay: '<S17>/Delay Input2'
   *
   * Block description for '<S17>/Delay Input2':
   *
   *  Store in Global RAM
   */
  TRSC_StateMachine_B.Yk1 = TRSC_StateMachine_B.DifferenceInputs2;

  /* Sum: '<S17>/Difference Inputs1'
   *
   * Block description for '<S17>/Difference Inputs1':
   *
   *  Add in CPU
   */
  TRSC_StateMachine_B.UkYk1 = TRSC_StateMachine_B.IeTRSC_M_TRSCStrTrq_n -
    TRSC_StateMachine_B.Yk1;

  /* RelationalOperator: '<S38>/UpperRelop' */
  TRSC_StateMachine_B.RelationalOperator_lc = (TRSC_StateMachine_B.UkYk1 <
    TRSC_StateMachine_B.deltafalllimit);

  /* Switch: '<S38>/Switch' */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch = TRSC_StateMachine_B.deltafalllimit;
  } else {
    TRSC_StateMachine_B.Switch = TRSC_StateMachine_B.UkYk1;
  }

  /* End of Switch: '<S38>/Switch' */

  /* Product: '<S17>/delta rise limit' */
  TRSC_StateMachine_B.deltariselimit = TRSC_StateMachine_B.Switch3_i *
    TRSC_StateMachine_B.sampletime;

  /* RelationalOperator: '<S38>/LowerRelop1' */
  TRSC_StateMachine_B.RelationalOperator_lc = (TRSC_StateMachine_B.UkYk1 >
    TRSC_StateMachine_B.deltariselimit);

  /* Switch: '<S38>/Switch2' */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch2_n = TRSC_StateMachine_B.deltariselimit;
  } else {
    TRSC_StateMachine_B.Switch2_n = TRSC_StateMachine_B.Switch;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* Sum: '<S17>/Difference Inputs2'
   *
   * Block description for '<S17>/Difference Inputs2':
   *
   *  Add in CPU
   */
  TRSC_StateMachine_B.DifferenceInputs2 = TRSC_StateMachine_B.Switch2_n +
    TRSC_StateMachine_B.Yk1;

  /* RelationalOperator: '<S11>/Compare' incorporates:
   *  Constant: '<S11>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp !=
     TeVBII_e_StrTrqResp_Active);

  /* Logic: '<S2>/Logical Operator1' */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.RelationalOperator_lc &&
     TRSC_StateMachine_B.MeTRSC_b_DriverOverride);

  /* Switch: '<S2>/Switch3' incorporates:
   *  Constant: '<S2>/Zero'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.TrqCMD = CeConst_k_ConstZero;
  } else {
    TRSC_StateMachine_B.TrqCMD = TRSC_StateMachine_B.DifferenceInputs2;
  }

  /* End of Switch: '<S2>/Switch3' */

  /* Switch: '<S2>/Switch1' */
  if (TRSC_StateMachine_B.Compare) {
    TRSC_StateMachine_B.TrqCMD_gb =
      TRSC_StateMachine_B.IeTRSC_e_TRSCStrTrqActvReq_i;
  } else {
    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S7>/Constant'
     */
    TRSC_StateMachine_B.LogicalOperator_h = (TRSC_StateMachine_B.TrqCMD == 0.0F);

    /* Logic: '<S2>/Logical Operator' */
    TRSC_StateMachine_B.LogicalOperator_h =
      (TRSC_StateMachine_B.MeTRSC_b_DriverOverride ||
       TRSC_StateMachine_B.LogicalOperator_h);

    /* Switch: '<S2>/Switch2' incorporates:
     *  Constant: '<S2>/KeTRSC_ddeg_TrqRateLim2'
     *  Constant: '<S2>/KeTRSC_ddeg_TrqRateLim3'
     */
    if (TRSC_StateMachine_B.LogicalOperator_h) {
      TRSC_StateMachine_B.TrqCMD_g = TeTRSC_e_TRSCStrTrqActvReq_False;
    } else {
      TRSC_StateMachine_B.TrqCMD_g = TeTRSC_e_TRSCStrTrqActvReq_True;
    }

    /* End of Switch: '<S2>/Switch2' */
    TRSC_StateMachine_B.TrqCMD_gb = TRSC_StateMachine_B.TrqCMD_g;
  }

  /* End of Switch: '<S2>/Switch1' */

  /* DataTypeConversion: '<S2>/Data Type Conversion7' */
  IeTRSC_e_TRSCStrTrqActvReq = TRSC_StateMachine_B.TrqCMD_gb;

  /* DataTypeConversion: '<S2>/Data Type Conversion6' */
  IeTRSC_M_TRSCStrTrq = TRSC_StateMachine_B.TrqCMD;

  /* RelationalOperator: '<S12>/Compare' incorporates:
   *  Constant: '<S12>/Constant'
   */
  TRSC_StateMachine_B.Compare_n = (TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i ==
    TeTRSC_e_TRSCSts_Active);

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  IeTRSC_e_SpdLmtReq = TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k;

  /* DataTypeConversion: '<S2>/Data Type Conversion10' */
  MeTRSC_e_TRSCStat = TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p;

  /* DataTypeConversion: '<S2>/Data Type Conversion11' */
  MeTRSC_b_MoreCamSoftButtEnbl =
    (TRSC_StateMachine_B.MeTRSC_b_MoreCamSoftButtEnbl_o != 0.0F);

  /* DataTypeConversion: '<S2>/Data Type Conversion2' */
  IeTRSC_e_VehStpReq = TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i;

  /* RelationalOperator: '<S128>/Compare' incorporates:
   *  Constant: '<S128>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
     TeVBII_e_CmdIgnSts_RUN);

  /* Switch: '<S30>/Switch1' incorporates:
   *  Constant: '<S30>/Constant4'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR3' incorporates:
     *  Constant: '<S30>/Constant3'
     */
    TRSC_StateMachine_B.BitwiseOR3 = 64U | 0U;
    TRSC_StateMachine_B.Switch7 = TRSC_StateMachine_B.BitwiseOR3;
  } else {
    TRSC_StateMachine_B.Switch7 = 0U;
  }

  /* End of Switch: '<S30>/Switch1' */

  /* RelationalOperator: '<S129>/Compare' incorporates:
   *  Constant: '<S129>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus > (int32_T)false);

  /* Switch: '<S30>/Switch2' incorporates:
   *  Constant: '<S30>/Constant6'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR4' incorporates:
     *  Constant: '<S30>/Constant5'
     */
    TRSC_StateMachine_B.BitwiseOR4 = 128U | 0U;
    TRSC_StateMachine_B.Switch6 = TRSC_StateMachine_B.BitwiseOR4;
  } else {
    TRSC_StateMachine_B.Switch6 = 0U;
  }

  /* End of Switch: '<S30>/Switch2' */

  /* RelationalOperator: '<S130>/Compare' incorporates:
   *  Constant: '<S130>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts ==
     TeVBII_e_CmdIgnSts_Initialization);

  /* Switch: '<S30>/Switch3' incorporates:
   *  Constant: '<S30>/Constant7'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR5' incorporates:
     *  Constant: '<S30>/Constant2'
     */
    TRSC_StateMachine_B.BitwiseOR5 = 256U | 0U;
    TRSC_StateMachine_B.Switch5 = TRSC_StateMachine_B.BitwiseOR5;
  } else {
    TRSC_StateMachine_B.Switch5 = 0U;
  }

  /* End of Switch: '<S30>/Switch3' */

  /* RelationalOperator: '<S131>/Compare' incorporates:
   *  Constant: '<S131>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts > (int32_T)false);

  /* Switch: '<S30>/Switch4' incorporates:
   *  Constant: '<S30>/Constant9'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR6' incorporates:
     *  Constant: '<S30>/Constant8'
     */
    TRSC_StateMachine_B.BitwiseOR6 = 512U | 0U;
    TRSC_StateMachine_B.Switch4 = TRSC_StateMachine_B.BitwiseOR6;
  } else {
    TRSC_StateMachine_B.Switch4 = 0U;
  }

  /* End of Switch: '<S30>/Switch4' */

  /* RelationalOperator: '<S132>/Compare' incorporates:
   *  Constant: '<S132>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply !=
     TeVBII_e_GearEngagedForDsply_P);

  /* Switch: '<S30>/Switch5' incorporates:
   *  Constant: '<S30>/Constant11'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR7' incorporates:
     *  Constant: '<S30>/Constant10'
     */
    TRSC_StateMachine_B.BitwiseOR7 = 1024U | 0U;
    TRSC_StateMachine_B.Switch3 = TRSC_StateMachine_B.BitwiseOR7;
  } else {
    TRSC_StateMachine_B.Switch3 = 0U;
  }

  /* End of Switch: '<S30>/Switch5' */

  /* RelationalOperator: '<S133>/Compare' incorporates:
   *  Constant: '<S133>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = (MeTRSC_e_TrlrPrsntInfoCAN ==
    TeTRSC_e_TrlrPrsntInfo_NoTrlr);

  /* Switch: '<S30>/Switch6' incorporates:
   *  Constant: '<S30>/Constant13'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR8' incorporates:
     *  Constant: '<S30>/Constant12'
     */
    TRSC_StateMachine_B.BitwiseOR8 = 8192U | 0U;
    TRSC_StateMachine_B.Switch2 = TRSC_StateMachine_B.BitwiseOR8;
  } else {
    TRSC_StateMachine_B.Switch2 = 0U;
  }

  /* End of Switch: '<S30>/Switch6' */

  /* RelationalOperator: '<S134>/Compare' incorporates:
   *  Constant: '<S134>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
     TeTRSC_e_TRSCPopupDispInfo_Disp10);

  /* Switch: '<S30>/Switch7' incorporates:
   *  Constant: '<S30>/Constant15'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR9' incorporates:
     *  Constant: '<S30>/Constant14'
     */
    TRSC_StateMachine_B.BitwiseOR9 = 16384U | 0U;
    TRSC_StateMachine_B.Switch9 = TRSC_StateMachine_B.BitwiseOR9;
  } else {
    TRSC_StateMachine_B.Switch9 = 0U;
  }

  /* End of Switch: '<S30>/Switch7' */

  /* RelationalOperator: '<S135>/Compare' incorporates:
   *  Constant: '<S135>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.MeTRSC_b_InternalFault > (int32_T)false);

  /* Switch: '<S30>/Switch8' incorporates:
   *  Constant: '<S30>/Constant17'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    /* S-Function (sfix_bitop): '<S30>/Bitwise OR10' incorporates:
     *  Constant: '<S30>/Constant16'
     */
    TRSC_StateMachine_B.BitwiseOR10 = 4194304U | 0U;
    TRSC_StateMachine_B.Switch1 = TRSC_StateMachine_B.BitwiseOR10;
  } else {
    TRSC_StateMachine_B.Switch1 = 0U;
  }

  /* End of Switch: '<S30>/Switch8' */

  /* S-Function (sfix_bitop): '<S30>/Bitwise OR2' */
  TRSC_StateMachine_B.BitwiseOR2 = TRSC_StateMachine_B.Switch7 |
    TRSC_StateMachine_B.Switch6 | TRSC_StateMachine_B.Switch5 |
    TRSC_StateMachine_B.Switch4 | TRSC_StateMachine_B.Switch3 |
    TRSC_StateMachine_B.Switch2 | TRSC_StateMachine_B.Switch9 |
    TRSC_StateMachine_B.Switch1;

  /* RelationalOperator: '<S93>/Compare' incorporates:
   *  Constant: '<S93>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
     TeTRSC_e_TRSCPopupDispInfo_Disp11);

  /* Switch: '<S28>/Switch1' incorporates:
   *  Constant: '<S28>/Constant3'
   *  Constant: '<S28>/Constant4'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch1 = 64U;
  } else {
    TRSC_StateMachine_B.Switch1 = 0U;
  }

  /* End of Switch: '<S28>/Switch1' */

  /* RelationalOperator: '<S92>/Compare' incorporates:
   *  Constant: '<S92>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
     TeVBII_e_CmdIgnSts_RUN);

  /* Switch: '<S28>/Switch9' incorporates:
   *  Constant: '<S28>/Constant17'
   *  Constant: '<S28>/Constant18'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch9 = 256U;
  } else {
    TRSC_StateMachine_B.Switch9 = 0U;
  }

  /* End of Switch: '<S28>/Switch9' */

  /* RelationalOperator: '<S86>/Compare' incorporates:
   *  Constant: '<S86>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus > (int32_T)false);

  /* Switch: '<S28>/Switch2' incorporates:
   *  Constant: '<S28>/Constant5'
   *  Constant: '<S28>/Constant6'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch2 = 512U;
  } else {
    TRSC_StateMachine_B.Switch2 = 0U;
  }

  /* End of Switch: '<S28>/Switch2' */

  /* RelationalOperator: '<S87>/Compare' incorporates:
   *  Constant: '<S87>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts ==
     TeVBII_e_CmdIgnSts_Initialization);

  /* Switch: '<S28>/Switch3' incorporates:
   *  Constant: '<S28>/Constant2'
   *  Constant: '<S28>/Constant7'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch3 = 1024U;
  } else {
    TRSC_StateMachine_B.Switch3 = 0U;
  }

  /* End of Switch: '<S28>/Switch3' */

  /* RelationalOperator: '<S84>/Compare' incorporates:
   *  Constant: '<S84>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
     TeTRSC_e_TRSCPopupDispInfo_Disp12);

  /* Switch: '<S28>/Switch4' incorporates:
   *  Constant: '<S28>/Constant8'
   *  Constant: '<S28>/Constant9'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch4 = 2048U;
  } else {
    TRSC_StateMachine_B.Switch4 = 0U;
  }

  /* End of Switch: '<S28>/Switch4' */

  /* RelationalOperator: '<S88>/Compare' incorporates:
   *  Constant: '<S88>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
     TeTRSC_e_TRSCPopupDispInfo_Disp8);

  /* Switch: '<S28>/Switch5' incorporates:
   *  Constant: '<S28>/Constant10'
   *  Constant: '<S28>/Constant11'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch5 = 4096U;
  } else {
    TRSC_StateMachine_B.Switch5 = 0U;
  }

  /* End of Switch: '<S28>/Switch5' */

  /* RelationalOperator: '<S90>/Compare' incorporates:
   *  Constant: '<S90>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts ==
     TeVBII_e_EnblBtnSts_Pressed);

  /* Switch: '<S28>/Switch6' incorporates:
   *  Constant: '<S28>/Constant12'
   *  Constant: '<S28>/Constant13'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch6 = 8192U;
  } else {
    TRSC_StateMachine_B.Switch6 = 0U;
  }

  /* End of Switch: '<S28>/Switch6' */

  /* RelationalOperator: '<S89>/Compare' incorporates:
   *  Constant: '<S89>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts > (int32_T)false);

  /* Switch: '<S28>/Switch7' incorporates:
   *  Constant: '<S28>/Constant1'
   *  Constant: '<S28>/Constant14'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch7 = 32768U;
  } else {
    TRSC_StateMachine_B.Switch7 = 0U;
  }

  /* End of Switch: '<S28>/Switch7' */

  /* RelationalOperator: '<S91>/Compare' incorporates:
   *  Constant: '<S91>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
     TeTRSC_e_TRSCPopupDispInfo_Disp10);

  /* Switch: '<S28>/Switch8' incorporates:
   *  Constant: '<S28>/Constant15'
   *  Constant: '<S28>/Constant16'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch8 = 1048576U;
  } else {
    TRSC_StateMachine_B.Switch8 = 0U;
  }

  /* End of Switch: '<S28>/Switch8' */

  /* RelationalOperator: '<S85>/Compare' incorporates:
   *  Constant: '<S85>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc = ((int32_T)
    IbTRSC_InpBus.MeTRSC_b_InternalFault > (int32_T)false);

  /* Switch: '<S28>/Switch10' incorporates:
   *  Constant: '<S28>/Constant19'
   *  Constant: '<S28>/Constant20'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.DataTypeConversion30 = 8388608U;
  } else {
    TRSC_StateMachine_B.DataTypeConversion30 = 0U;
  }

  /* End of Switch: '<S28>/Switch10' */

  /* S-Function (sfix_bitop): '<S28>/Bitwise OR2' */
  TRSC_StateMachine_B.BitwiseOR2_p = TRSC_StateMachine_B.Switch1 |
    TRSC_StateMachine_B.Switch9 | TRSC_StateMachine_B.Switch2 |
    TRSC_StateMachine_B.Switch3 | TRSC_StateMachine_B.Switch4 |
    TRSC_StateMachine_B.Switch5 | TRSC_StateMachine_B.Switch6 |
    TRSC_StateMachine_B.Switch7 | TRSC_StateMachine_B.Switch8 |
    TRSC_StateMachine_B.DataTypeConversion30;

  /* DataTypeConversion: '<S2>/Data Type Conversion21' */
  IeTRSC_e_TRSCAbortReas = TRSC_StateMachine_B.BitwiseOR2_p;

  /* DataTypeConversion: '<S2>/Data Type Conversion20' */
  IeTRSC_e_TRSCUnavailReas = TRSC_StateMachine_B.BitwiseOR2;

  /* DataTypeConversion: '<S2>/Data Type Conversion22' */
  IeTRSC_e_TrlrHitchLightCtrl =
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e;

  /* DataTypeConversion: '<S2>/Data Type Conversion23' */
  IeTRSC_e_TrlrCalInfo = TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo;

  /* RelationalOperator: '<S101>/Compare' incorporates:
   *  Constant: '<S101>/Constant'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p == TeTRSC_e_TRSCStat_ActiveHoldOvr);

  /* RelationalOperator: '<S107>/Compare' incorporates:
   *  Constant: '<S107>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_k =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
     TeVBII_e_ShiftLvrPos_P);

  /* Logic: '<S29>/Logical Operator' */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (TRSC_StateMachine_B.RelationalOperator_lc &&
     TRSC_StateMachine_B.LogicalOperator_k);

  /* Logic: '<S29>/Logical Operator5' */
  TRSC_StateMachine_B.LogicalOperator_k =
    !TRSC_StateMachine_B.RelationalOperator_lc;

  /* UnitDelay: '<S127>/UnitDelay3' */
  TRSC_StateMachine_B.Switch3_i = TRSC_StateMachine_B.MinMax;

  /* Switch: '<S127>/Switch1' incorporates:
   *  Constant: '<S127>/Constant4'
   */
  if (TRSC_StateMachine_B.LogicalOperator_k) {
    TRSC_StateMachine_B.Switch1_a = 0.0F;
  } else {
    TRSC_StateMachine_B.Switch1_a = TRSC_StateMachine_B.Switch3_i;
  }

  /* End of Switch: '<S127>/Switch1' */

  /* DataTypeConversion: '<S33>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.DataTypeConversion_a =
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_k_KnobAngl;

  /* RelationalOperator: '<S162>/Compare' incorporates:
   *  Constant: '<S162>/Constant'
   */
  TRSC_StateMachine_B.LogicalOperator_k =
    (TRSC_StateMachine_B.DataTypeConversion_a <= ((uint16_T)359U));

  /* RelationalOperator: '<S163>/Compare' incorporates:
   *  Constant: '<S163>/Constant'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (TRSC_StateMachine_B.DataTypeConversion_a >= ((uint16_T)0U));

  /* Logic: '<S33>/Logical Operator' */
  TRSC_StateMachine_B.LogicalOperator_k = (TRSC_StateMachine_B.LogicalOperator_k
    && TRSC_StateMachine_B.LogicalOperator_m);

  /* UnitDelay: '<S33>/Unit Delay' */
  TRSC_StateMachine_B.UnitDelay = TRSC_StateMachine_DW.UnitDelay_DSTATE_j;

  /* Switch: '<S33>/Switch' incorporates:
   *  Constant: '<S166>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator_k) {
    TRSC_StateMachine_B.Switch_j = TeTRSC_e_TRSKMSts_Enabled;
  } else {
    /* RelationalOperator: '<S165>/Compare' incorporates:
     *  Constant: '<S165>/Constant'
     */
    TRSC_StateMachine_B.Compare_f = (TRSC_StateMachine_B.DataTypeConversion_a <
      ((uint16_T)511U));

    /* RelationalOperator: '<S164>/Compare' incorporates:
     *  Constant: '<S164>/Constant'
     */
    TRSC_StateMachine_B.LogicalOperator1 =
      (TRSC_StateMachine_B.DataTypeConversion_a > ((uint16_T)359U));

    /* Logic: '<S33>/Logical Operator1' */
    TRSC_StateMachine_B.LogicalOperator1 = (TRSC_StateMachine_B.LogicalOperator1
      && TRSC_StateMachine_B.Compare_f);

    /* Switch: '<S33>/Switch1' incorporates:
     *  Constant: '<S167>/Constant'
     */
    if (TRSC_StateMachine_B.LogicalOperator1) {
      TRSC_StateMachine_B.Switch1_b = TeTRSC_e_TRSKMSts_NotEnabled;
    } else {
      TRSC_StateMachine_B.Switch1_b = TRSC_StateMachine_B.UnitDelay;
    }

    /* End of Switch: '<S33>/Switch1' */
    TRSC_StateMachine_B.Switch_j = TRSC_StateMachine_B.Switch1_b;
  }

  /* End of Switch: '<S33>/Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion17' */
  IeTRSC_e_TRSKMSts = TRSC_StateMachine_B.Switch_j;

  /* RelationalOperator: '<S95>/Compare' incorporates:
   *  Constant: '<S95>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
     TeVBII_e_EcmTrscResp_SNA);

  /* Switch: '<S29>/Switch11' incorporates:
   *  Constant: '<S123>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    TRSC_StateMachine_B.Switch11_i =
      TeTRSC_e_TRSCAbortReason_DID_No_Or_InvalidResp_Engine_Controller;
  } else {
    /* RelationalOperator: '<S96>/Compare' incorporates:
     *  Constant: '<S96>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_StateMachine_B.Compare_o2 =
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
       TeVBII_e_EscTrscBrkResp_SNA);

    /* Switch: '<S29>/Switch12' incorporates:
     *  Constant: '<S109>/Constant'
     */
    if (TRSC_StateMachine_B.Compare_o2) {
      TRSC_StateMachine_B.Switch12_i =
        TeTRSC_e_TRSCAbortReason_DID_No_Or_InvalidResp_Brake_Systems;
    } else {
      /* RelationalOperator: '<S97>/Compare' incorporates:
       *  Constant: '<S97>/Constant'
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_StateMachine_B.Compare_h =
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
         TeVBII_e_StrTrqResp_SNA);

      /* Switch: '<S29>/Switch13' incorporates:
       *  Constant: '<S118>/Constant'
       */
      if (TRSC_StateMachine_B.Compare_h) {
        TRSC_StateMachine_B.Switch13_c =
          TeTRSC_e_TRSCAbortReason_DID_No_Or_InvalidResp_Electric_Power_Steering;
      } else {
        /* RelationalOperator: '<S98>/Compare' incorporates:
         *  Constant: '<S98>/Constant'
         *  Inport: '<Root>/IbTRSC_InpBus'
         */
        TRSC_StateMachine_B.Compare_c =
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
           TeVBII_e_ShiftLvrPos_SNA);

        /* Switch: '<S29>/Switch14' incorporates:
         *  Constant: '<S120>/Constant'
         */
        if (TRSC_StateMachine_B.Compare_c) {
          TRSC_StateMachine_B.Switch14_n =
            TeTRSC_e_TRSCAbortReason_DID_No_Or_Transmission_Controller;
        } else {
          /* RelationalOperator: '<S94>/Compare' incorporates:
           *  Constant: '<S94>/Constant'
           *  Inport: '<Root>/IbTRSC_InpBus'
           */
          TRSC_StateMachine_B.Compare_j =
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts ==
             TeVBII_e_SBR1RowDriverSeatSts_SNA);

          /* Switch: '<S29>/Switch1' incorporates:
           *  Constant: '<S121>/Constant'
           */
          if (TRSC_StateMachine_B.Compare_j) {
            TRSC_StateMachine_B.Switch1_i =
              TeTRSC_e_TRSCAbortReason_DID_No_Or_InvalidResp_ORC_Module;
          } else {
            /* RelationalOperator: '<S99>/Compare' incorporates:
             *  Constant: '<S99>/Constant'
             */
            TRSC_StateMachine_B.Compare_gk = (TRSC_StateMachine_B.Gain7 >=
              CeConst_k_SnglTwentyFive);

            /* Switch: '<S29>/Switch17' incorporates:
             *  Constant: '<S122>/Constant'
             */
            if (TRSC_StateMachine_B.Compare_gk) {
              TRSC_StateMachine_B.Switch17 =
                TeTRSC_e_TRSCAbortReason_DID_Speed_Above_25mph;
            } else {
              /* RelationalOperator: '<S100>/Compare' incorporates:
               *  Constant: '<S100>/Constant'
               *  Inport: '<Root>/IbTRSC_InpBus'
               */
              TRSC_StateMachine_B.Compare_l =
                (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState ==
                 TeTRSC_e_TADState_Trackinglost);

              /* Switch: '<S29>/Switch19' incorporates:
               *  Constant: '<S124>/Constant'
               */
              if (TRSC_StateMachine_B.Compare_l) {
                TRSC_StateMachine_B.Switch19 =
                  TeTRSC_e_TRSCAbortReason_DID_Trailer_Lost_From_FoV;
              } else {
                /* RelationalOperator: '<S102>/Compare' incorporates:
                 *  Constant: '<S102>/Constant'
                 *  Inport: '<Root>/IbTRSC_InpBus'
                 */
                TRSC_StateMachine_B.Compare_hq =
                  (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
                   TeVBII_e_CmdIgnSts_RUN);

                /* Switch: '<S29>/Switch20' incorporates:
                 *  Constant: '<S125>/Constant'
                 */
                if (TRSC_StateMachine_B.Compare_hq) {
                  TRSC_StateMachine_B.Switch20_m =
                    TeTRSC_e_TRSCAbortReason_DID_Ignition_Not_Run;
                } else {
                  /* RelationalOperator: '<S103>/Compare' incorporates:
                   *  Constant: '<S103>/Constant'
                   *  Inport: '<Root>/IbTRSC_InpBus'
                   */
                  TRSC_StateMachine_B.Compare_mz = ((int32_T)
                    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus >
                    (int32_T)false);

                  /* Switch: '<S29>/Switch21' incorporates:
                   *  Constant: '<S126>/Constant'
                   */
                  if (TRSC_StateMachine_B.Compare_mz) {
                    TRSC_StateMachine_B.Switch21_j =
                      TeTRSC_e_TRSCAbortReason_DID_Rear_Tailgate_Open;
                  } else {
                    /* RelationalOperator: '<S104>/Compare' incorporates:
                     *  Constant: '<S104>/Constant'
                     *  Inport: '<Root>/IbTRSC_InpBus'
                     */
                    TRSC_StateMachine_B.Compare_i =
                      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                       TeVBII_e_EngineSts_Engine_Off);

                    /* Switch: '<S29>/Switch22' incorporates:
                     *  Constant: '<S110>/Constant'
                     *  Inport: '<Root>/IbTRSC_InpBus'
                     *  Switch: '<S29>/Switch23'
                     */
                    if (TRSC_StateMachine_B.Compare_i) {
                      TRSC_StateMachine_B.Switch22_i =
                        TeTRSC_e_TRSCAbortReason_DID_Engine_Off;
                    } else {
                      if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_b_StrTchSts)
                      {
                        /* Switch: '<S29>/Switch23' incorporates:
                         *  Constant: '<S111>/Constant'
                         */
                        TRSC_StateMachine_B.Switch23_o =
                          TeTRSC_e_TRSCAbortReason_DID_Driver_Steering_Override;
                      } else {
                        /* Gain: '<S127>/Gain' incorporates:
                         *  Constant: '<S29>/Constant3'
                         *  Switch: '<S29>/Switch23'
                         */
                        TRSC_StateMachine_B.Gain = 0.99F * CeTRSC_s_TRSCLpTm;

                        /* Sum: '<S127>/Sum1' incorporates:
                         *  Constant: '<S29>/Constant4'
                         *  Switch: '<S29>/Switch23'
                         */
                        TRSC_StateMachine_B.Sum1 = KeTRSC_s_TenMinTh -
                          TRSC_StateMachine_B.Switch1_a;

                        /* RelationalOperator: '<S127>/Relational Operator' incorporates:
                         *  Switch: '<S29>/Switch23'
                         */
                        TRSC_StateMachine_B.RelationalOperator_b =
                          (TRSC_StateMachine_B.Sum1 < TRSC_StateMachine_B.Gain);

                        /* Switch: '<S29>/Switch4' incorporates:
                         *  Constant: '<S112>/Constant'
                         *  Switch: '<S29>/Switch23'
                         *  Switch: '<S29>/Switch5'
                         */
                        if (TRSC_StateMachine_B.RelationalOperator_b) {
                          TRSC_StateMachine_B.Switch4_h =
                            TeTRSC_e_TRSCAbortReason_DID_No_User_Feedback;
                        } else {
                          if (TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts) {
                            /* Switch: '<S29>/Switch5' incorporates:
                             *  Constant: '<S113>/Constant'
                             */
                            TRSC_StateMachine_B.Switch5_f =
                              TeTRSC_e_TRSCAbortReason_DID_TRSC_Btn_Pressed;
                          } else {
                            /* RelationalOperator: '<S108>/Compare' incorporates:
                             *  Constant: '<S108>/Constant'
                             *  Switch: '<S29>/Switch5'
                             */
                            TRSC_StateMachine_B.Compare_nc =
                              (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld
                               == TeTRSC_e_TRSCPopupDispInfo_Disp11);

                            /* Switch: '<S29>/Switch6' incorporates:
                             *  Constant: '<S114>/Constant'
                             *  Inport: '<Root>/IbTRSC_InpBus'
                             *  Switch: '<S29>/Switch5'
                             *  Switch: '<S29>/Switch7'
                             */
                            if (TRSC_StateMachine_B.Compare_nc) {
                              TRSC_StateMachine_B.Switch6_h =
                                TeTRSC_e_TRSCAbortReason_DID_Vehicle_Speed_exceeded;
                            } else {
                              if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts)
                              {
                                /* Switch: '<S29>/Switch7' incorporates:
                                 *  Constant: '<S115>/Constant'
                                 */
                                TRSC_StateMachine_B.Switch7_f =
                                  TeTRSC_e_TRSCAbortReason_DID_Driver_Door_Open;
                              } else {
                                /* RelationalOperator: '<S105>/Compare' incorporates:
                                 *  Constant: '<S105>/Constant'
                                 *  Switch: '<S29>/Switch7'
                                 */
                                TRSC_StateMachine_B.Compare_p =
                                  (IeTRSC_e_TRSKMSts == TeTRSC_e_TRSKMSts_SNA);

                                /* Switch: '<S29>/Switch26' incorporates:
                                 *  Constant: '<S116>/Constant'
                                 *  Switch: '<S29>/Switch7'
                                 */
                                if (TRSC_StateMachine_B.Compare_p) {
                                  TRSC_StateMachine_B.Switch26 =
                                    TeTRSC_e_TRSCAbortReason_DID_TRSKMKnob_Module_No_Response;
                                } else {
                                  /* RelationalOperator: '<S106>/Compare' incorporates:
                                   *  Constant: '<S106>/Constant'
                                   */
                                  TRSC_StateMachine_B.Compare_ig =
                                    (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld
                                     == TeTRSC_e_TRSCPopupDispInfo_Disp10);

                                  /* Switch: '<S29>/Switch27' incorporates:
                                   *  Constant: '<S117>/Constant'
                                   *  Constant: '<S119>/Constant'
                                   */
                                  if (TRSC_StateMachine_B.Compare_ig) {
                                    TRSC_StateMachine_B.Switch27_h =
                                      TeTRSC_e_TRSCAbortReason_DID_Trailer_Angle_Too_Steep;
                                  } else {
                                    TRSC_StateMachine_B.Switch27_h =
                                      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
                                  }

                                  /* End of Switch: '<S29>/Switch27' */
                                  TRSC_StateMachine_B.Switch26 =
                                    TRSC_StateMachine_B.Switch27_h;
                                }

                                /* End of Switch: '<S29>/Switch26' */

                                /* Switch: '<S29>/Switch7' */
                                TRSC_StateMachine_B.Switch7_f =
                                  TRSC_StateMachine_B.Switch26;
                              }

                              TRSC_StateMachine_B.Switch6_h =
                                TRSC_StateMachine_B.Switch7_f;
                            }

                            /* End of Switch: '<S29>/Switch6' */

                            /* Switch: '<S29>/Switch5' */
                            TRSC_StateMachine_B.Switch5_f =
                              TRSC_StateMachine_B.Switch6_h;
                          }

                          TRSC_StateMachine_B.Switch4_h =
                            TRSC_StateMachine_B.Switch5_f;
                        }

                        /* End of Switch: '<S29>/Switch4' */

                        /* Switch: '<S29>/Switch23' */
                        TRSC_StateMachine_B.Switch23_o =
                          TRSC_StateMachine_B.Switch4_h;
                      }

                      TRSC_StateMachine_B.Switch22_i =
                        TRSC_StateMachine_B.Switch23_o;
                    }

                    /* End of Switch: '<S29>/Switch22' */
                    TRSC_StateMachine_B.Switch21_j =
                      TRSC_StateMachine_B.Switch22_i;
                  }

                  /* End of Switch: '<S29>/Switch21' */
                  TRSC_StateMachine_B.Switch20_m =
                    TRSC_StateMachine_B.Switch21_j;
                }

                /* End of Switch: '<S29>/Switch20' */
                TRSC_StateMachine_B.Switch19 = TRSC_StateMachine_B.Switch20_m;
              }

              /* End of Switch: '<S29>/Switch19' */
              TRSC_StateMachine_B.Switch17 = TRSC_StateMachine_B.Switch19;
            }

            /* End of Switch: '<S29>/Switch17' */
            TRSC_StateMachine_B.Switch1_i = TRSC_StateMachine_B.Switch17;
          }

          /* End of Switch: '<S29>/Switch1' */
          TRSC_StateMachine_B.Switch14_n = TRSC_StateMachine_B.Switch1_i;
        }

        /* End of Switch: '<S29>/Switch14' */
        TRSC_StateMachine_B.Switch13_c = TRSC_StateMachine_B.Switch14_n;
      }

      /* End of Switch: '<S29>/Switch13' */
      TRSC_StateMachine_B.Switch12_i = TRSC_StateMachine_B.Switch13_c;
    }

    /* End of Switch: '<S29>/Switch12' */
    TRSC_StateMachine_B.Switch11_i = TRSC_StateMachine_B.Switch12_i;
  }

  /* End of Switch: '<S29>/Switch11' */

  /* DataTypeConversion: '<S2>/Data Type Conversion29' */
  IeTRSC_e_TRSCAbortReas_DID = TRSC_StateMachine_B.Switch11_i;

  /* DataTypeConversion: '<S25>/Data Type Conversion25' */
  TRSC_StateMachine_B.DataTypeConversion25 = (uint32_T)IeTRSC_e_TRSKMSts;

  /* MultiPortSwitch: '<S25>/Multiport Switch' incorporates:
   *  Constant: '<S67>/Constant'
   *  Constant: '<S68>/Constant'
   *  Constant: '<S69>/Constant'
   */
  switch (TRSC_StateMachine_B.DataTypeConversion25) {
   case 0:
    IeTRSC_e_TRSKMSts_DID = TeTRSC_e_TRSKMSts_DID_Enabled;
    break;

   case 1:
    IeTRSC_e_TRSKMSts_DID = TeTRSC_e_TRSKMSts_DID_NotEnabled;
    break;

   default:
    IeTRSC_e_TRSKMSts_DID = TeTRSC_e_TRSKMSts_DID_NotEnabled;
    break;
  }

  /* End of MultiPortSwitch: '<S25>/Multiport Switch' */

  /* Switch: '<S127>/Switch3' incorporates:
   *  Constant: '<S127>/Constant2'
   *  Constant: '<S29>/Constant3'
   */
  if (TRSC_StateMachine_B.RelationalOperator_lc) {
    TRSC_StateMachine_B.Switch3_i = CeTRSC_s_TRSCLpTm;
  } else {
    TRSC_StateMachine_B.Switch3_i = 0.0F;
  }

  /* End of Switch: '<S127>/Switch3' */

  /* Sum: '<S127>/Sum' */
  TRSC_StateMachine_B.Switch3_i += TRSC_StateMachine_B.Switch1_a;

  /* MinMax: '<S127>/MinMax' incorporates:
   *  Constant: '<S29>/Constant4'
   */
  TRSC_StateMachine_B.MinMax = fminf(TRSC_StateMachine_B.Switch3_i,
    KeTRSC_s_TenMinTh);

  /* DataTypeConversion: '<S2>/Data Type Conversion3' */
  IeTRSC_e_TRSCLedSts = TRSC_StateMachine_B.IeTRSC_e_TRSCLedSts_b;

  /* RelationalOperator: '<S137>/Compare' incorporates:
   *  Constant: '<S137>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EcmTrscResp ==
     TeVBII_e_EcmTrscResp_SNA);

  /* Switch: '<S32>/Switch11' incorporates:
   *  Constant: '<S159>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    TRSC_StateMachine_B.Switch11 =
      TeTRSC_e_TRSCUnavailReas_DID_No_Or_InvalidResp_Engine_Controller;
  } else {
    /* RelationalOperator: '<S138>/Compare' incorporates:
     *  Constant: '<S138>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_StateMachine_B.Compare_g =
      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EscTrscBrkResp ==
       TeVBII_e_EscTrscBrkResp_SNA);

    /* Switch: '<S32>/Switch12' incorporates:
     *  Constant: '<S148>/Constant'
     */
    if (TRSC_StateMachine_B.Compare_g) {
      TRSC_StateMachine_B.Switch12 =
        TeTRSC_e_TRSCUnavailReas_DID_No_Or_InvalidResp_Brake_Systems;
    } else {
      /* RelationalOperator: '<S139>/Compare' incorporates:
       *  Constant: '<S139>/Constant'
       *  Inport: '<Root>/IbTRSC_InpBus'
       */
      TRSC_StateMachine_B.Compare_b =
        (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_StrTrqResp ==
         TeVBII_e_StrTrqResp_SNA);

      /* Switch: '<S32>/Switch13' incorporates:
       *  Constant: '<S155>/Constant'
       */
      if (TRSC_StateMachine_B.Compare_b) {
        TRSC_StateMachine_B.Switch13 =
          TeTRSC_e_TRSCUnavailReas_DID_No_Or_InvalidResp_Electric_Power_Steering;
      } else {
        /* RelationalOperator: '<S140>/Compare' incorporates:
         *  Constant: '<S140>/Constant'
         *  Inport: '<Root>/IbTRSC_InpBus'
         */
        TRSC_StateMachine_B.Compare_a =
          (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos ==
           TeVBII_e_ShiftLvrPos_SNA);

        /* Switch: '<S32>/Switch14' incorporates:
         *  Constant: '<S157>/Constant'
         */
        if (TRSC_StateMachine_B.Compare_a) {
          TRSC_StateMachine_B.Switch14 =
            TeTRSC_e_TRSCUnavailReas_DID_No_Or_InvalidResp_Transmission_Controller;
        } else {
          /* RelationalOperator: '<S136>/Compare' incorporates:
           *  Constant: '<S136>/Constant'
           *  Inport: '<Root>/IbTRSC_InpBus'
           */
          TRSC_StateMachine_B.Compare_az =
            (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_SBR1RowDriverSeatSts ==
             TeVBII_e_SBR1RowDriverSeatSts_SNA);

          /* Switch: '<S32>/Switch1' incorporates:
           *  Constant: '<S158>/Constant'
           */
          if (TRSC_StateMachine_B.Compare_az) {
            TRSC_StateMachine_B.Switch1_az =
              TeTRSC_e_TRSCUnavailReas_DID_No_Or_InvalidResp_ORC_Module;
          } else {
            /* RelationalOperator: '<S142>/Compare' incorporates:
             *  Constant: '<S142>/Constant'
             *  Inport: '<Root>/IbTRSC_InpBus'
             */
            TRSC_StateMachine_B.Compare_fv =
              (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CmdIgnSts !=
               TeVBII_e_CmdIgnSts_RUN);

            /* Switch: '<S32>/Switch20' incorporates:
             *  Constant: '<S160>/Constant'
             */
            if (TRSC_StateMachine_B.Compare_fv) {
              TRSC_StateMachine_B.Switch20 =
                TeTRSC_e_TRSCUnavailReas_DID_Ignition_Not_Run;
            } else {
              /* RelationalOperator: '<S143>/Compare' incorporates:
               *  Constant: '<S143>/Constant'
               *  Inport: '<Root>/IbTRSC_InpBus'
               */
              TRSC_StateMachine_B.Compare_bb = ((int32_T)
                IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_TrnkStatus >
                (int32_T)false);

              /* Switch: '<S32>/Switch21' incorporates:
               *  Constant: '<S161>/Constant'
               */
              if (TRSC_StateMachine_B.Compare_bb) {
                TRSC_StateMachine_B.Switch21 =
                  TeTRSC_e_TRSCUnavailReas_DID_Rear_Tailgate_Open;
              } else {
                /* RelationalOperator: '<S144>/Compare' incorporates:
                 *  Constant: '<S144>/Constant'
                 *  Inport: '<Root>/IbTRSC_InpBus'
                 */
                TRSC_StateMachine_B.Compare_o =
                  (IbTRSC_InpBus.IbTRSC_VehInpFromCAN14.IeVBII_e_EngineSts ==
                   TeVBII_e_EngineSts_Engine_Off);

                /* Switch: '<S32>/Switch22' incorporates:
                 *  Constant: '<S149>/Constant'
                 *  Inport: '<Root>/IbTRSC_InpBus'
                 *  Switch: '<S32>/Switch7'
                 */
                if (TRSC_StateMachine_B.Compare_o) {
                  TRSC_StateMachine_B.Switch22 =
                    TeTRSC_e_TRSCUnavailReas_DID_Engine_Off;
                } else {
                  if (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_b_DriverDoorSts)
                  {
                    /* Switch: '<S32>/Switch7' incorporates:
                     *  Constant: '<S153>/Constant'
                     */
                    TRSC_StateMachine_B.Switch7_e =
                      TeTRSC_e_TRSCUnavailReas_DID_Driver_Door_Open;
                  } else {
                    /* RelationalOperator: '<S147>/Compare' incorporates:
                     *  Constant: '<S147>/Constant'
                     *  Inport: '<Root>/IbTRSC_InpBus'
                     *  Switch: '<S32>/Switch7'
                     */
                    TRSC_StateMachine_B.Compare_gn =
                      (IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos
                       != TeVBII_e_ShiftLvrPos_P);

                    /* Switch: '<S32>/Switch23' incorporates:
                     *  Constant: '<S150>/Constant'
                     *  Switch: '<S32>/Switch7'
                     */
                    if (TRSC_StateMachine_B.Compare_gn) {
                      TRSC_StateMachine_B.Switch23 =
                        TeTRSC_e_TRSCUnavailReas_DID_Vehicle_NotIn_Park;
                    } else {
                      /* RelationalOperator: '<S141>/Compare' incorporates:
                       *  Constant: '<S141>/Constant'
                       *  Inport: '<Root>/IbTRSC_InpBus'
                       */
                      TRSC_StateMachine_B.Compare_ff =
                        (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TADState <=
                         TeTRSC_e_TADState_TrailerDetection);

                      /* Switch: '<S32>/Switch4' incorporates:
                       *  Constant: '<S151>/Constant'
                       */
                      if (TRSC_StateMachine_B.Compare_ff) {
                        TRSC_StateMachine_B.Switch4_m =
                          TeTRSC_e_TRSCUnavailReas_DID_Trailer_Not_Detected;
                      } else {
                        /* RelationalOperator: '<S145>/Compare' incorporates:
                         *  Constant: '<S145>/Constant'
                         */
                        TRSC_StateMachine_B.Compare_k =
                          (TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld ==
                           TeTRSC_e_TRSCPopupDispInfo_Disp10);

                        /* Switch: '<S32>/Switch27' incorporates:
                         *  Constant: '<S154>/Constant'
                         */
                        if (TRSC_StateMachine_B.Compare_k) {
                          TRSC_StateMachine_B.Switch27 =
                            TeTRSC_e_TRSCUnavailReas_DID_Trailer_Angle_Too_Steep;
                        } else {
                          /* RelationalOperator: '<S146>/Compare' incorporates:
                           *  Constant: '<S146>/Constant'
                           *  Inport: '<Root>/IbTRSC_InpBus'
                           */
                          TRSC_StateMachine_B.Compare_m =
                            (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo
                             >= 1U);

                          /* Switch: '<S32>/Switch6' incorporates:
                           *  Constant: '<S152>/Constant'
                           *  Constant: '<S156>/Constant'
                           */
                          if (TRSC_StateMachine_B.Compare_m) {
                            TRSC_StateMachine_B.Switch6_n =
                              TeTRSC_e_TRSCUnavailReas_DID_Trailer_Calibration_Failure;
                          } else {
                            TRSC_StateMachine_B.Switch6_n =
                              TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
                          }

                          /* End of Switch: '<S32>/Switch6' */
                          TRSC_StateMachine_B.Switch27 =
                            TRSC_StateMachine_B.Switch6_n;
                        }

                        /* End of Switch: '<S32>/Switch27' */
                        TRSC_StateMachine_B.Switch4_m =
                          TRSC_StateMachine_B.Switch27;
                      }

                      /* End of Switch: '<S32>/Switch4' */
                      TRSC_StateMachine_B.Switch23 =
                        TRSC_StateMachine_B.Switch4_m;
                    }

                    /* End of Switch: '<S32>/Switch23' */

                    /* Switch: '<S32>/Switch7' */
                    TRSC_StateMachine_B.Switch7_e = TRSC_StateMachine_B.Switch23;
                  }

                  TRSC_StateMachine_B.Switch22 = TRSC_StateMachine_B.Switch7_e;
                }

                /* End of Switch: '<S32>/Switch22' */
                TRSC_StateMachine_B.Switch21 = TRSC_StateMachine_B.Switch22;
              }

              /* End of Switch: '<S32>/Switch21' */
              TRSC_StateMachine_B.Switch20 = TRSC_StateMachine_B.Switch21;
            }

            /* End of Switch: '<S32>/Switch20' */
            TRSC_StateMachine_B.Switch1_az = TRSC_StateMachine_B.Switch20;
          }

          /* End of Switch: '<S32>/Switch1' */
          TRSC_StateMachine_B.Switch14 = TRSC_StateMachine_B.Switch1_az;
        }

        /* End of Switch: '<S32>/Switch14' */
        TRSC_StateMachine_B.Switch13 = TRSC_StateMachine_B.Switch14;
      }

      /* End of Switch: '<S32>/Switch13' */
      TRSC_StateMachine_B.Switch12 = TRSC_StateMachine_B.Switch13;
    }

    /* End of Switch: '<S32>/Switch12' */
    TRSC_StateMachine_B.Switch11 = TRSC_StateMachine_B.Switch12;
  }

  /* End of Switch: '<S32>/Switch11' */

  /* DataTypeConversion: '<S2>/Data Type Conversion32' */
  IeTRSC_e_TRSCUnavailReas_DID = TRSC_StateMachine_B.Switch11;

  /* DataTypeConversion: '<S2>/Data Type Conversion4' */
  IeTRSC_e_TRSCPopupDispInfo = TRSC_StateMachine_B.IeTRSC_e_TRSCPopupDispInfoHld;

  /* DataTypeConversion: '<S2>/Data Type Conversion5' */
  IeTRSC_e_TRSCSts = TRSC_StateMachine_B.IeTRSC_e_TRSCSts_i;

  /* RelationalOperator: '<S20>/Relational Operator6' incorporates:
   *  Constant: '<S20>/Constant13'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k == TeTRSC_e_SpdLmtReq_NotLim);

  /* Switch: '<S20>/Switch6' incorporates:
   *  Constant: '<S20>/Constant14'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    IeTRSC_kph_SpdLmtReq_DID = 0.0F;
  } else {
    /* RelationalOperator: '<S20>/Relational Operator' incorporates:
     *  Constant: '<S20>/Constant2'
     */
    TRSC_StateMachine_B.RelationalOperator_i =
      (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k == TeTRSC_e_SpdLmtReq_Spd4);

    /* Switch: '<S20>/Switch' incorporates:
     *  Constant: '<S20>/Constant'
     */
    if (TRSC_StateMachine_B.RelationalOperator_i) {
      TRSC_StateMachine_B.Switch_b = 4.0F;
    } else {
      /* RelationalOperator: '<S20>/Relational Operator1' incorporates:
       *  Constant: '<S20>/Constant3'
       */
      TRSC_StateMachine_B.RelationalOperator1_g =
        (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k == TeTRSC_e_SpdLmtReq_Spd5);

      /* Switch: '<S20>/Switch1' incorporates:
       *  Constant: '<S20>/Constant1'
       */
      if (TRSC_StateMachine_B.RelationalOperator1_g) {
        TRSC_StateMachine_B.Switch1_j = 5.0F;
      } else {
        /* RelationalOperator: '<S20>/Relational Operator2' incorporates:
         *  Constant: '<S20>/Constant5'
         */
        TRSC_StateMachine_B.RelationalOperator2_h =
          (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k == TeTRSC_e_SpdLmtReq_Spd6);

        /* Switch: '<S20>/Switch2' incorporates:
         *  Constant: '<S20>/Constant4'
         */
        if (TRSC_StateMachine_B.RelationalOperator2_h) {
          TRSC_StateMachine_B.Switch2_f = 6.0F;
        } else {
          /* RelationalOperator: '<S20>/Relational Operator3' incorporates:
           *  Constant: '<S20>/Constant7'
           */
          TRSC_StateMachine_B.RelationalOperator3_g =
            (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k == TeTRSC_e_SpdLmtReq_Spd7);

          /* Switch: '<S20>/Switch3' incorporates:
           *  Constant: '<S20>/Constant6'
           */
          if (TRSC_StateMachine_B.RelationalOperator3_g) {
            TRSC_StateMachine_B.Switch3_j = 7.0F;
          } else {
            /* RelationalOperator: '<S20>/Relational Operator4' incorporates:
             *  Constant: '<S20>/Constant9'
             */
            TRSC_StateMachine_B.RelationalOperator4 =
              (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k ==
               TeTRSC_e_SpdLmtReq_Spd8);

            /* Switch: '<S20>/Switch4' incorporates:
             *  Constant: '<S20>/Constant8'
             */
            if (TRSC_StateMachine_B.RelationalOperator4) {
              TRSC_StateMachine_B.Switch4_d = 8.0F;
            } else {
              /* RelationalOperator: '<S20>/Relational Operator5' incorporates:
               *  Constant: '<S20>/Constant11'
               */
              TRSC_StateMachine_B.RelationalOperator5 =
                (TRSC_StateMachine_B.IeTRSC_e_SpdLmtReq_k ==
                 TeTRSC_e_SpdLmtReq_Spd9);

              /* Switch: '<S20>/Switch5' incorporates:
               *  Constant: '<S20>/Constant10'
               *  Constant: '<S20>/Constant12'
               */
              if (TRSC_StateMachine_B.RelationalOperator5) {
                TRSC_StateMachine_B.Switch5_p = 9.0F;
              } else {
                TRSC_StateMachine_B.Switch5_p = 10.0F;
              }

              /* End of Switch: '<S20>/Switch5' */
              TRSC_StateMachine_B.Switch4_d = TRSC_StateMachine_B.Switch5_p;
            }

            /* End of Switch: '<S20>/Switch4' */
            TRSC_StateMachine_B.Switch3_j = TRSC_StateMachine_B.Switch4_d;
          }

          /* End of Switch: '<S20>/Switch3' */
          TRSC_StateMachine_B.Switch2_f = TRSC_StateMachine_B.Switch3_j;
        }

        /* End of Switch: '<S20>/Switch2' */
        TRSC_StateMachine_B.Switch1_j = TRSC_StateMachine_B.Switch2_f;
      }

      /* End of Switch: '<S20>/Switch1' */
      TRSC_StateMachine_B.Switch_b = TRSC_StateMachine_B.Switch1_j;
    }

    /* End of Switch: '<S20>/Switch' */
    IeTRSC_kph_SpdLmtReq_DID = TRSC_StateMachine_B.Switch_b;
  }

  /* End of Switch: '<S20>/Switch6' */

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (TRSC_StateMachine_B.MeTRSC_e_SmTrlrCalInfo ==
     TeTRSC_e_TrlrCalInfo_Calibrated);

  /* Switch: '<S23>/Switch17' incorporates:
   *  Constant: '<S56>/Constant'
   *  Constant: '<S57>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    IeTRSC_e_GraphicOverlay_Sts = TeTRSC_e_GraphicOverlay_Sts_Active;
  } else {
    IeTRSC_e_GraphicOverlay_Sts = TeTRSC_e_GraphicOverlay_Sts_Inactive;
  }

  /* End of Switch: '<S23>/Switch17' */

  /* DataTypeConversion: '<S26>/Data Type Conversion' */
  TRSC_StateMachine_B.DataTypeConversion = (uint32_T)
    TRSC_StateMachine_B.IeTRSC_e_VehStpReq_i;

  /* MultiPortSwitch: '<S26>/Multiport Switch' incorporates:
   *  Constant: '<S70>/Constant'
   *  Constant: '<S71>/Constant'
   *  Constant: '<S72>/Constant'
   *  Constant: '<S73>/Constant'
   */
  switch (TRSC_StateMachine_B.DataTypeConversion) {
   case 0:
    IeTRSC_e_VehStpReq_DID = TeTRSC_e_VehStpReq_DID_NotActive;
    break;

   case 1:
    IeTRSC_e_VehStpReq_DID = TeTRSC_e_VehStpReq_DID_Active;
    break;

   case 2:
    IeTRSC_e_VehStpReq_DID = TeTRSC_e_VehStpReq_DID_SNA;
    break;

   default:
    IeTRSC_e_VehStpReq_DID = TeTRSC_e_VehStpReq_DID_NotActive;
    break;
  }

  /* End of MultiPortSwitch: '<S26>/Multiport Switch' */

  /* RelationalOperator: '<S27>/Relational Operator3' incorporates:
   *  Constant: '<S83>/Constant'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (TRSC_StateMachine_B.MeTRSC_e_TRSCStat_p == TeTRSC_e_TRSCStat_Calibrating);

  /* RelationalOperator: '<S27>/Relational Operator2' incorporates:
   *  Constant: '<S77>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator2 =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo ==
     TeTRSC_e_TrlrCalInfo_NotCalibrated);

  /* Logic: '<S27>/Logical Operator2' */
  TRSC_StateMachine_B.LogicalOperator_m =
    (TRSC_StateMachine_B.RelationalOperator2 ||
     TRSC_StateMachine_B.LogicalOperator_m);

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S27>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    TRSC_StateMachine_B.Switch3_i = CeConst_k_SnglZero;
  } else {
    TRSC_StateMachine_B.Switch3_i =
      IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle;
  }

  /* End of Switch: '<S27>/Switch3' */

  /* DataTypeConversion: '<S27>/Data Type Conversion1' */
  IeTRSC_deg_TADAngAct = TRSC_StateMachine_B.Switch3_i;

  /* RelationalOperator: '<S74>/Compare' incorporates:
   *  Constant: '<S74>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.LogicalOperator_m =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle > 0.0F);

  /* RelationalOperator: '<S27>/Relational Operator' incorporates:
   *  Constant: '<S79>/Constant'
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.RelationalOperator_lc =
    (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo ==
     TeTRSC_e_TrlrCalInfo_Calibrated);

  /* Logic: '<S27>/Logical Operator' */
  TRSC_StateMachine_B.LogicalOperator_m = (TRSC_StateMachine_B.LogicalOperator_m
    && TRSC_StateMachine_B.RelationalOperator_lc);

  /* Switch: '<S27>/Switch' incorporates:
   *  Constant: '<S76>/Constant'
   */
  if (TRSC_StateMachine_B.LogicalOperator_m) {
    TRSC_StateMachine_B.Switch_b0 = TeTRSC_e_TADAngActSign_Positive;
  } else {
    /* RelationalOperator: '<S27>/Relational Operator1' incorporates:
     *  Constant: '<S78>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_StateMachine_B.RelationalOperator1 =
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_e_TrlrCalInfo ==
       TeTRSC_e_TrlrCalInfo_Calibrated);

    /* RelationalOperator: '<S75>/Compare' incorporates:
     *  Constant: '<S75>/Constant'
     *  Inport: '<Root>/IbTRSC_InpBus'
     */
    TRSC_StateMachine_B.LogicalOperator1_a =
      (IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_deg_TADAngle < 0.0F);

    /* Logic: '<S27>/Logical Operator1' */
    TRSC_StateMachine_B.LogicalOperator1_a =
      (TRSC_StateMachine_B.LogicalOperator1_a &&
       TRSC_StateMachine_B.RelationalOperator1);

    /* Switch: '<S27>/Switch1' incorporates:
     *  Constant: '<S80>/Constant'
     *  Switch: '<S27>/Switch2'
     */
    if (TRSC_StateMachine_B.LogicalOperator1_a) {
      TRSC_StateMachine_B.Switch1_g = TeTRSC_e_TADAngActSign_Negative;
    } else {
      if (TRSC_StateMachine_B.RelationalOperator2) {
        /* Switch: '<S27>/Switch2' incorporates:
         *  Constant: '<S81>/Constant'
         */
        TRSC_StateMachine_B.Switch2_c = TeTRSC_e_TADAngActSign_None;
      } else {
        /* Switch: '<S27>/Switch2' incorporates:
         *  Constant: '<S82>/Constant'
         */
        TRSC_StateMachine_B.Switch2_c = TeTRSC_e_TADAngActSign_None;
      }

      TRSC_StateMachine_B.Switch1_g = TRSC_StateMachine_B.Switch2_c;
    }

    /* End of Switch: '<S27>/Switch1' */
    TRSC_StateMachine_B.Switch_b0 = TRSC_StateMachine_B.Switch1_g;
  }

  /* End of Switch: '<S27>/Switch' */

  /* DataTypeConversion: '<S27>/Data Type Conversion' */
  IeTRSC_e_TADAngActSign = TRSC_StateMachine_B.Switch_b0;

  /* DataTypeConversion: '<S2>/Data Type Conversion12' */
  MeTRSC_b_TRSCSwitchPressed = TRSC_StateMachine_B.MeTRSC_b_TRSCBtnSts;

  /* DataTypeConversion: '<S2>/Data Type Conversion13' */
  MeTRSC_b_TrlrRevSteeringStsInfo =
    TRSC_StateMachine_B.MeTRSC_b_TrlrRevSteeringStsInfo_f;

  /* DataTypeConversion: '<S2>/Data Type Conversion27' */
  MeTRSC_b_TrlrCalibPopInfo = TRSC_StateMachine_B.MeTRSC_b_TrlrCalibPopInfo_i;

  /* DataTypeConversion: '<S2>/Data Type Conversion9' */
  IeTRSC_b_MoreCamReqSts = TRSC_StateMachine_B.IeTRSC_b_MoreCamReqSts_f;

  /* DataTypeConversion: '<S2>/Data Type Conversion8' */
  IeTRSC_pct_TRSCStrDmp = TRSC_StateMachine_B.IeTRSC_pct_TRSCStrDmp_b;

  /* Switch: '<S34>/Switch3' incorporates:
   *  Constant: '<S2>/Constant3'
   *  Constant: '<S34>/Constant2'
   */
  if (TRSC_StateMachine_B.LogicalOperator3) {
    TRSC_StateMachine_B.Switch3_i = CeTRSC_s_TRSCLpTm;
  } else {
    TRSC_StateMachine_B.Switch3_i = 0.0F;
  }

  /* End of Switch: '<S34>/Switch3' */

  /* Sum: '<S34>/Sum' */
  TRSC_StateMachine_B.Sum_k += TRSC_StateMachine_B.Switch3_i;

  /* MinMax: '<S34>/MinMax' incorporates:
   *  Constant: '<S2>/Constant4'
   */
  TRSC_StateMachine_B.MinMax_c = fminf(TRSC_StateMachine_B.Sum_k,
    KeTRSC_s_TRSCCornerCasAtc);

  /* DataTypeConversion: '<S21>/Data Type Conversion25' */
  TRSC_StateMachine_B.DataTypeConversion25_d = (uint32_T)
    TRSC_StateMachine_B.Switch_d;

  /* MultiPortSwitch: '<S21>/Multiport Switch' incorporates:
   *  Constant: '<S47>/Constant'
   *  Constant: '<S48>/Constant'
   *  Constant: '<S49>/Constant'
   *  Constant: '<S50>/Constant'
   */
  switch (TRSC_StateMachine_B.DataTypeConversion25_d) {
   case 0:
    IeTRSC_e_TRSKMBtnSts_DID = TeTRSC_e_TRSKMBtnSts_DID_NotPressed;
    break;

   case 1:
    IeTRSC_e_TRSKMBtnSts_DID = TeTRSC_e_TRSKMBtnSts_DID_Pressed;
    break;

   case 3:
    IeTRSC_e_TRSKMBtnSts_DID = TeTRSC_e_TRSKMBtnSts_DID_SNA;
    break;

   default:
    IeTRSC_e_TRSKMBtnSts_DID = TeTRSC_e_TRSKMBtnSts_DID_NotPressed;
    break;
  }

  /* End of MultiPortSwitch: '<S21>/Multiport Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion19' */
  IeTRSC_kph_VehSpeedVSOSig = TRSC_StateMachine_B.Gain7;

  /* DataTypeConversion: '<S2>/Data Type Conversion14' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  IeTRSC_e_TRSKMBtnSts = IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_EnblBtnSts;

  /* DataTypeConversion: '<S2>/Data Type Conversion15' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  IeTRSC_cnt_KnobPos = IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_k_KnobAngl;

  /* DataTypeConversion: '<S2>/Data Type Conversion18' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  IeTRSC_e_GearShiftSts =
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_GearEngagedForDsply;

  /* DataTypeConversion: '<S2>/Data Type Conversion30' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.DataTypeConversion30 = (uint32_T)
    IbTRSC_InpBus.IbTRSC_SVStoTRSC.MeSVS_e_DispView2Info;

  /* DataTypeConversion: '<S2>/Data Type Conversion31' */
  MeSVS_e_DispView2Info_DID = (TeTRSC_e_DispView2_DID)
    TRSC_StateMachine_B.DataTypeConversion30;

  /* DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.DataTypeConversion_n = (uint32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_ShiftLvrPos;

  /* MultiPortSwitch: '<S24>/Multiport Switch' incorporates:
   *  Constant: '<S58>/Constant'
   *  Constant: '<S59>/Constant'
   *  Constant: '<S60>/Constant'
   *  Constant: '<S61>/Constant'
   *  Constant: '<S62>/Constant'
   *  Constant: '<S63>/Constant'
   *  Constant: '<S64>/Constant'
   *  Constant: '<S65>/Constant'
   *  Constant: '<S66>/Constant'
   */
  switch (TRSC_StateMachine_B.DataTypeConversion_n) {
   case 1:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_P;
    break;

   case 2:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_R;
    break;

   case 3:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_N;
    break;

   case 4:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_D;
    break;

   case 5:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_L;
    break;

   case 7:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_M;
    break;

   case 9:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_S;
    break;

   case 15:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_SNA;
    break;

   default:
    IeTRSC_e_GearShiftSts_DID = TeTRSC_e_GearShiftSts_DID_P;
    break;
  }

  /* End of MultiPortSwitch: '<S24>/Multiport Switch' */

  /* DataTypeConversion: '<S2>/Data Type Conversion16' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  IeTRSC_e_TRSKMCenBtnSts =
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CenterBtnSts;

  /* DataTypeConversion: '<S22>/Data Type Conversion25' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_B.DataTypeConversion25_e = (uint32_T)
    IbTRSC_InpBus.IbTRSC_VehInpFromCAN2.IeVBII_e_CenterBtnSts;

  /* MultiPortSwitch: '<S22>/Multiport Switch' incorporates:
   *  Constant: '<S51>/Constant'
   *  Constant: '<S52>/Constant'
   *  Constant: '<S53>/Constant'
   *  Constant: '<S54>/Constant'
   */
  switch (TRSC_StateMachine_B.DataTypeConversion25_e) {
   case 0:
    IeTRSC_e_TRSKMCenBtnSts_DID = TeTRSC_e_TRSKMCenBtnSts_DID_NotPressed;
    break;

   case 1:
    IeTRSC_e_TRSKMCenBtnSts_DID = TeTRSC_e_TRSKMCenBtnSts_DID_Pressed;
    break;

   case 3:
    IeTRSC_e_TRSKMCenBtnSts_DID = TeTRSC_e_TRSKMCenBtnSts_DID_SNA;
    break;

   default:
    IeTRSC_e_TRSKMCenBtnSts_DID = TeTRSC_e_TRSKMCenBtnSts_DID_NotPressed;
    break;
  }

  /* End of MultiPortSwitch: '<S22>/Multiport Switch' */

  /* Update for Delay: '<S2>/Delay One Step1' */
  TRSC_StateMachine_DW.DelayOneStep1_DSTATE = TRSC_StateMachine_B.DelayOneStep2;

  /* Update for UnitDelay: '<S3>/Unit Delay' incorporates:
   *  Inport: '<Root>/IbTRSC_InpBus'
   */
  TRSC_StateMachine_DW.UnitDelay_DSTATE =
    IbTRSC_InpBus.IbTRSC_TrailerDetInp.MeTRSC_cnt_TrlrCalibFailCntInfo;

  /* Update for UnitDelay: '<S3>/Unit Delay1' */
  TRSC_StateMachine_DW.UnitDelay1_DSTATE =
    TRSC_StateMachine_B.RelationalOperator;

  /* Update for Delay: '<S2>/Delay2' */
  for (k = 0; k < 254; k++) {
    TRSC_StateMachine_DW.Delay2_DSTATE[k] = TRSC_StateMachine_DW.Delay2_DSTATE[k
      + 1];
  }

  TRSC_StateMachine_DW.Delay2_DSTATE[254] = *rtu_MeTRSC_M_TRSCStrTrq;

  /* End of Update for Delay: '<S2>/Delay2' */

  /* Update for UnitDelay: '<S2>/Unit Delay' */
  TRSC_StateMachine_DW.UnitDelay_DSTATE_i =
    TRSC_StateMachine_B.IeVBII_e_CustTrlrType;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  TRSC_StateMachine_DW.UnitDelay_DSTATE_j = TRSC_StateMachine_B.Switch_j;
}

/* Model initialize function */
void TRSC_StateMachine_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_TRSC_StateMachine_T *const TRSC_StateMachine_M =
    &(TRSC_StateMachine_MdlrefDW.rtm);

  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatusPointer(TRSC_StateMachine_M, rt_errorStatus);

  /* block I/O */
  {
    TRSC_StateMachine_B.IeTRSC_e_TrlrHitchLightCtrl_e =
      TeTRSC_e_TrlrHitchLightCtrl_OFF;
    TRSC_StateMachine_B.Switch12 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch13 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch14 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch1_az =
      TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch20 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch21 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch22 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch7_e =
      TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch23 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch4_m =
      TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch27 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch6_n =
      TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch11 = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch12_i =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch13_c =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch14_n =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch1_i =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch17 = TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch19 = TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch20_m =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch21_j =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch22_i =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch23_o =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch4_h =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch5_f =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch6_h =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch7_f =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch26 = TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch27_h =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
    TRSC_StateMachine_B.Switch11_i =
      TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
