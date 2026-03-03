/*
 * File: TRSC_SM_VC_Int.c
 *
 * Code generated for Simulink model 'TRSC_SM_VC_Int'.
 *
 * Model version                  : 1.337
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:53:44 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "TRSC_SM_VC_Int.h"
#include "TRSC_SM_VC_Int_private.h"
#include "TRSC_VC.h"
#include "ti/osal/TimerP.h"


#include "../code/TRSC_SMVC_Defines.h"
#if ((!TRSC_SIGM_TESTING) || (PRINT_TUNABLE_PARAMS) || (TRSC_PRINT_SMVC_INPUT_OUTPUTS) || (TRSC_DEBUG_IPC_PRINTS))
#include <UART_stdio.h>
#include "../simulation/TRSC_Simulation.h"
#endif

volatile real32_T plot_IeTRSC_M_TRSCStrTrq = 0.0f;

extern B_TRSC_VC_c_T TRSC_VC_B;

ME_VehOut_TRSC_t TRSC_SM_VC_Int_rtZME_VehOut_TRSC_t = {
  TeTRSC_e_SpdLmtReq_NotLim,           /* IeTRSC_e_SpdLmtReq */
  TeTRSC_e_VehStpReq_False,            /* IeTRSC_e_VehStpReq */
  TeTRSC_e_TRSCLedSts_Off,             /* IeTRSC_e_TRSCLedSts */
  TeTRSC_e_TRSCPopupDispInfo_Disp0,    /* IeTRSC_e_TRSCPopupDispInfo */
  TeTRSC_e_TRSCSts_Standby,            /* IeTRSC_e_TRSCSts */
  TeTRSC_e_TRSCStrTrqActvReq_False,    /* IeTRSC_e_TRSCStrTrqActvReq */
  TeTRSC_e_TrlrHitchLightCtrl_OFF,     /* IeTRSC_e_TrlrHitchLightCtrl */
  0.0F,                                /* IeTRSC_M_TRSCStrTrq */
  0.0F,                                /* IeTRSC_pct_TRSCStrDmp */
  0U,                                  /* IeTRSC_deg_TADAngAct */
  TeTRSC_e_TADAngActSign_None,         /* IeTRSC_e_TADAngActSign */
  TeTRSC_e_TrlrCalInfo_NotCalibrated,  /* IeTRSC_e_TrlrCalInfo */
  false,                               /* IeTRSC_b_MoreCamReqSts */
  0.0F,                                /* IeTRSC_kph_SpdLmtReq_DID */
  TeTRSC_e_VehStpReq_DID_NotActive     /* IeTRSC_e_VehStpReq_DID */
} ;                                    /* ME_VehOut_TRSC_t ground */

TRSCtoDiagMgr_t TRSC_SM_VC_Int_rtZTRSCtoDiagMgr_t = {
  TeVBII_e_EnblBtnSts_NotPressed,      /* IeTRSC_e_TRSKMBtnSts */
  TeTRSC_e_TRSKMBtnSts_DID_NotPressed, /* IeTRSC_e_TRSKMBtnSts_DID */
  TeVBII_e_CenterBtnSts_NotPressed,    /* IeTRSC_e_TRSKMCenBtnSts */
  TeTRSC_e_TRSKMCenBtnSts_DID_NotPressed,/* IeTRSC_e_TRSKMCenBtnSts_DID */
  TeTRSC_e_TRSKMSts_NotEnabled,        /* IeTRSC_e_TRSKMSts */
  TeTRSC_e_TRSKMSts_DID_NotEnabled,    /* IeTRSC_e_TRSKMSts_DID */
  TeVBII_e_GearEngagedForDsply_Initialize,/* IeTRSC_e_GearShiftSts */
  TeTRSC_e_GearShiftSts_DID_P,         /* IeTRSC_e_GearShiftSts_DID */
  0U,                                  /* IeTRSC_e_TRSCUnavailReas */
  TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present,/* IeTRSC_e_TRSCUnavailReas_DID */
  0U,                                  /* IeTRSC_e_TRSCAbortReas */
  TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present,/* IeTRSC_e_TRSCAbortReas_DID */
  0.0F,                                /* IeTRSC_kph_VehSpeedVSOSig */
  0.0F,                                /* IeTRSC_m_TrlrWhlBaseEff */
  0.0F,                                /* IeTRSC_deg_FrntWhlAng */
  0.0F,                                /* IeTRSC_deg_TrlrAngKnob */
  0.0F,                                /* IeTRSC_deg_JackknifeThrAngle */
  0.0F,                                /* IeTRSC_M_TRSCStrTrq */
  0U,                                  /* IeTRSC_cnt_KnobPos */
  TeTRSC_e_DispView2_DID_Off,          /* MeSVS_e_DispView2Info_DID */
  TeTRSC_e_GraphicOverlay_Sts_Inactive /* IeTRSC_e_GraphicOverlay_Sts */
} ;                                    /* TRSCtoDiagMgr_t ground */

/* Exported block signals */
TbTRSC_InpBus IbTRSC_InpBus;           /* '<Root>/TRSC_Int_InpAdapter'
                                        * IbTRSC_InpBus : TRSC state Machine Input signal bus , having following buses combined together:

                                          - Bus: TbTRSC_VehInpFromCAN2
                                          - Bus: TbTRSC_VehInpFromCAN14
                                          - Bus: TbTRSC_TrailerDetInp
                                          - Bus: TbTRSC_MEProxiToIpc
                                          - Bus: TbTRSC_SVStoTRSC

                                        */
uint32_T IeTRSC_e_TRSCUnavailReas;     /* '<Root>/TRSC_IntModel'
                                        * Decimal value shall be converted to binary to understand bit set or resetted for below values:

                                          DID Value for TRSC Unavailable/ not able to engage TRSC Reason:
                                          No response or invalid from Engine Controller,
                                          No response or invalid from Brake Systems Module,
                                          No response or invalid from Electric Power steering Module,
                                          No response or invalid from Transmission Controller,
                                          No response or invalid from ORC Module,
                                          No response or invalid from Radio,
                                          Ignition not in RUN,
                                          Rear tailgate open,
                                          Engine status signal says engine OFF,
                                          Driver door Open,
                                          Vehicle not in 'P',
                                          Camera calibration is unknown,
                                          Trailer not detected by the system,
                                          Trailer Angle to the vehicle too steep to engage the TRSC feature,
                                          Trailer Calibration Failure,
                                          No Response or invalid data received from TRSKM Knob module,
                                          CVADAS ECU supply Voltage lower or higher than operating range,
                                          CVADAS ECU in plant mode,
                                          Invalid Proxi Parameter(out of range)/Vehicle Configuration mismatch,
                                          Fail not present,
                                          SNA - When internal fault present and parameter not available
                                        */
uint32_T IeTRSC_e_TRSCAbortReas;       /* '<Root>/TRSC_IntModel'
                                        * Decimal value shall be converted to binary to understand bit set or resetted for below values:

                                          DID Value for Abort/Cancellation Reason:
                                          No response or invalid from Engine Controller,
                                          No response or invalid from Brake Systems Module,
                                          No response or invalid from Electric Power steering Module,
                                          No response or invalid from Transmission Controller,
                                          No response or invalid from ORC Module,
                                          No response or invalid from Radio,
                                          Ignition not in RUN,
                                          Rear tailgate open,
                                          Engine status signal says engine OFF,
                                          Driver door Open,
                                          Exceed speed in forward direction above 25 MPH,
                                          Trailer image in Camera view - lost in the field of view,
                                          Driver steering override,
                                          No user feedback for 600 Sec,
                                          TRSC button pressed on the TRSKM or radio screen,
                                          No Response or invalid data received from TRSKM Knob module,
                                          CVADAS ECU supply Voltage lower or higher than operating range,
                                          Trailer Angle too steep,
                                          Vehicle Speed exceeds the speed requested by CVADAS module during the maneuver,
                                          Invalid Proxi Parameter(out of range)/Vehicle Configuration mismatch,
                                          Fail not present,
                                          SNA - When internal fault present and parameter not available
                                        */
real32_T MeTRSC_deg_TADAngleSMVC;      /* '<Root>/TRSC_Int_InpAdapter'
                                        * TAD Angle
                                        */
real32_T IeTRSC_M_TRSCStrTrq;          /* '<Root>/TRSC_IntModel'
                                        * TRSC steering torque overlay request  information
                                        */
real32_T IeTRSC_pct_TRSCStrDmp;        /* '<Root>/TRSC_IntModel'
                                        * TRSC Steering damping percentage
                                        */
real32_T MeTRSC_deg_JackKnifeAngle;    /* '<Root>/TRSC_IntModel' */
real32_T MeTRSC_m_TrailerBeamLen;      /* '<Root>/TRSC_IntModel' */
real32_T MeTRSC_deg_JackknifeThrAngle; /* '<Root>/TRSC_IntModel' */
real32_T MeTRSC_deg_MaxAllowedTADAngle;/* '<Root>/TRSC_IntModel' */
real32_T MeTRSC_deg_KnobAngle;         /* '<Root>/TRSC_IntModel' */
real32_T IeTRSC_kph_VehSpeedVSOSig;    /* '<Root>/TRSC_IntModel'
                                        * It is the average vehicle speed calculated
                                        */
real32_T IeTRSC_m_TrlrWhlBaseEff;      /* '<Root>/TRSC_IntModel'
                                        * DID value of Trailer Wheel Base effective
                                        */
real32_T IeTRSC_deg_FrntWhlAng;        /* '<Root>/TRSC_IntModel'
                                        * DID Value of Front Road wheel angle
                                        */
real32_T IeTRSC_deg_TrlrAngKnob;       /* '<Root>/TRSC_IntModel'
                                        * DID Value of Trailer Angle requested by the knob
                                        */
real32_T IeTRSC_deg_JackknifeThrAngle; /* '<Root>/TRSC_IntModel'
                                        * DID Value of JackknifeThresholdAngle
                                        */
real32_T IeTRSC_deg_TADAngAct;         /* '<Root>/TRSC_IntModel'
                                        * IeTRSC_deg_TADAngAct signal output from TRSC SM
                                        */
real32_T MeTRSC_deg_StrCMD;            /* '<Root>/TRSC_IntModel'
                                        * Steering Angle command in degree
                                        */
real32_T IeTRSC_kph_SpdLmtReq_DID;     /* '<Root>/TRSC_IntModel'
                                        * Speed limit request DID
                                        */
TeVBII_e_GearEngagedForDsply IeTRSC_e_GearShiftSts;/* '<Root>/TRSC_IntModel'
                                                    * DID Value of Shifter Position status read from bus:
                                                      Initialize(0)
                                                      Gear1(1)
                                                      Gear2(2)
                                                      Gear3(3)
                                                      Gear4(4)
                                                      Gear5(5)
                                                      Gear6(6)
                                                      Gear7(7)
                                                      Gear8(8)
                                                      Gear9(9)
                                                      NotUsed1(10)
                                                      NotUsed2(11)
                                                      P(12)
                                                      N(13)
                                                      R(14)
                                                      D(15)
                                                      L(16)
                                                      M(17)
                                                      S(18)
                                                      SNA(31)
                                                    */
TeVBII_e_EnblBtnSts IeTRSC_e_TRSKMBtnSts;/* '<Root>/TRSC_IntModel'
                                          * DID Value of TRSKM Button Status
                                            NotPressed(0)
                                            Pressed(1)
                                            SNA(2)
                                          */
TeVBII_e_CenterBtnSts IeTRSC_e_TRSKMCenBtnSts;/* '<Root>/TRSC_IntModel'
                                               * DID Value of TRSKM Push to Center Button Status:
                                                 NotPressed(0)
                                                 Pressed(1)
                                                 SNA(2)
                                               */
TeTRSC_e_VehStpReq_DID IeTRSC_e_VehStpReq_DID;/* '<Root>/TRSC_IntModel'
                                               * TRSC break activation request DID
                                               */
TeTRSC_e_VehStpReq IeTRSC_e_VehStpReq; /* '<Root>/TRSC_IntModel'
                                        * TRSC break activation request
                                        */
TeTRSC_e_TrlrPrsntInfo MeTRSC_e_TrlrPrsntInfoCAN;/* '<Root>/TRSC_IntModel'
                                                  * MeTRSC_e_TrlrPrsntInfoCAN signal output from TRSC SM
                                                  */
TeTRSC_e_TrlrHitchLightCtrl IeTRSC_e_TrlrHitchLightCtrl;/* '<Root>/TRSC_IntModel'
                                                         * Trailer Hitch light Control when trailer is connected
                                                         */
TeTRSC_e_TrlrCalInfo MeTRSC_e_TrlrCalInfoSMVC;/* '<Root>/TRSC_Int_InpAdapter'
                                               * Trailer Calibration Information
                                                 0 -> Not Calibrated,
                                                 1 - >Calibrated
                                                 2 ->undefined
                                               */
TeTRSC_e_TrlrCalInfo IeTRSC_e_TrlrCalInfo;/* '<Root>/TRSC_IntModel'
                                           * Trailer Calibration Information
                                             0 -> Not Calibrated,
                                             1 - >Calibrated
                                             2 ->undefined
                                           */
TeTRSC_e_TRSKMSts_DID IeTRSC_e_TRSKMSts_DID;/* '<Root>/TRSC_IntModel'
                                             * DID Value of TRSKM Module status:
                                               Enabled,
                                               Not Enabled,
                                               SNA - No confirmation received by TRSKM
                                             */
TeTRSC_e_TRSKMSts IeTRSC_e_TRSKMSts;   /* '<Root>/TRSC_IntModel'
                                        * DID Value of TRSKM Module status:
                                          Enabled,
                                          Not Enabled,
                                          SNA - No confirmation received by TRSKM
                                        */
TeTRSC_e_TRSKMCenBtnSts_DID IeTRSC_e_TRSKMCenBtnSts_DID;/* '<Root>/TRSC_IntModel'
                                                         * DID Value of TRSKM Push to Center Button Status:
                                                           NotPressed(0)
                                                           Pressed(1)
                                                           SNA(2)
                                                         */
TeTRSC_e_TRSKMBtnSts_DID IeTRSC_e_TRSKMBtnSts_DID;/* '<Root>/TRSC_IntModel'
                                                   * DID Value of TRSKM Button Status
                                                     NotPressed(0)
                                                     Pressed(1)
                                                     SNA(2)
                                                   */
TeTRSC_e_TRSCUnavailReas_DID IeTRSC_e_TRSCUnavailReas_DID;/* '<Root>/TRSC_IntModel'
                                                           * TRSC Unavailable reasons DID
                                                           */
TeTRSC_e_TRSCSts IeTRSC_e_TRSCSts;     /* '<Root>/TRSC_IntModel'
                                        * TRSC Status
                                        */
TeTRSC_e_TRSCStrTrqActvReq IeTRSC_e_TRSCStrTrqActvReq;/* '<Root>/TRSC_IntModel'
                                                       * TRSC steering torque overlay activation request
                                                       */
TeTRSC_e_TRSCStat MeTRSC_e_TRSCStat;   /* '<Root>/TRSC_IntModel'
                                        * Internal Current State of TRSC feature
                                        */
TeTRSC_e_TRSCPopupDispInfo IeTRSC_e_TRSCPopupDispInfo;/* '<Root>/TRSC_IntModel'
                                                       * TRSC Cluster PopUp Request
                                                       */
TeTRSC_e_TRSCLedSts IeTRSC_e_TRSCLedSts;/* '<Root>/TRSC_IntModel'
                                         * TRSKM LED request
                                         */
TeTRSC_e_TRSCAbortReason_DID IeTRSC_e_TRSCAbortReas_DID;/* '<Root>/TRSC_IntModel'
                                                         * TRSC Abort reasons DID
                                                         */
TeTRSC_e_TADAngActSign IeTRSC_e_TADAngActSign;/* '<Root>/TRSC_IntModel'
                                               * IeTRSC_e_TADAngActSign signal output from TRSC SM
                                               */
TeTRSC_e_SpdLmtReq IeTRSC_e_SpdLmtReq; /* '<Root>/TRSC_IntModel'
                                        * TRSC ECM Speed limit request
                                        */
TeTRSC_e_GraphicOverlay_Sts IeTRSC_e_GraphicOverlay_Sts;/* '<Root>/TRSC_IntModel'
                                                         * Graphical Overlay DID
                                                         */
TeTRSC_e_GearShiftSts_DID IeTRSC_e_GearShiftSts_DID;/* '<Root>/TRSC_IntModel'
                                                     * Gear shift status DID
                                                     */
TeTRSC_e_DispView2_DID MeSVS_e_DispView2Info_DID;/* '<Root>/TRSC_IntModel'
                                                  * CVPM Display view2 status from HMI
                                                  */
uint16_T IeTRSC_cnt_KnobPos;           /* '<Root>/TRSC_IntModel'
                                        * DID Value of TRSKM Knob Position
                                        */
boolean_T IeTRSC_b_MoreCamReqSts;      /* '<Root>/TRSC_IntModel'
                                        * Status of More Camera request Input from HMI SoftButton, ( 0 -> NotPressed, 1 -> Pressed)
                                        */
boolean_T MeTRSC_b_MoreCamSoftButtEnbl;/* '<Root>/TRSC_IntModel'
                                        * More Camera Enable Soft Button Input
                                        */
boolean_T MeTRSC_b_TRSCSwitchPressed;  /* '<Root>/TRSC_IntModel' */
boolean_T MeTRSC_b_TrlrRevSteeringStsInfo;/* '<Root>/TRSC_IntModel' */
boolean_T MeTRSC_b_OTBLReset;          /* '<Root>/TRSC_IntModel'
                                        * OTBL Reset flag
                                        */
boolean_T MeTRSC_b_TBLComputationDone; /* '<Root>/TRSC_IntModel' */
boolean_T MeTRSC_b_TrlrCalibPopInfo;   /* '<Root>/TRSC_IntModel'
                                        * Trailer Calibration Popup information
                                        */

/* Block signals (default storage) */
B_TRSC_SM_VC_Int_T TRSC_SM_VC_Int_B;

/* Real-time model */
RT_MODEL_TRSC_SM_VC_Int_T TRSC_SM_VC_Int_M_;
RT_MODEL_TRSC_SM_VC_Int_T *const TRSC_SM_VC_Int_M = &TRSC_SM_VC_Int_M_;

/* Model step function */
void TRSC_SM_VC_Int_step(void)
{
  static uint16_t TRSCcounter = 0;
  int32_t isNewMessage = 0;
  uint64_t u64StartTime = TimerP_getTimeInUsecs();
  uint64_t u64EndTime = 0;
  static uint64_t u64PrevStartTime = 0;
  ME_CanDebugRIDStatus_t debugStatus_s;
  /* SignalConversion: '<Root>/Signal Conversion1' incorporates:
   *  Inport: '<Root>/IbTrailerDet_TrailerDetInpBus'
   */
  SigMgr_PpTrscTrlrDet_TRSC_Inputs_from_TrailerDetection_t_Get(&TRSC_SM_VC_Int_B.IbTrailerDet_TrailerDetInpBus);

  /* SignalConversion: '<Root>/Signal Conversion3' incorporates:
   *  Inport: '<Root>/IbSVS_SVStoTRSC'
   */
  SVStoTRSCSMVC_t SVStoTRSCSMVC_data;
  SigMgr_data_SVStoTRSCSMVC_t_Get(&SVStoTRSCSMVC_data);
  TRSC_SM_VC_Int_B.IbSVS_SVStoTRSC.MeSVS_b_MoreCamReq = SVStoTRSCSMVC_data.MeSVS_b_MoreCamReq;
  TRSC_SM_VC_Int_B.IbSVS_SVStoTRSC.MeSVS_e_DispView2Info = SVStoTRSCSMVC_data.MeSVS_e_DispView2Info;

  /* SignalConversion: '<Root>/Signal Conversion4' incorporates:
   *  Inport: '<Root>/IbTRSC_MEVehInpFromCAN14IpcSignals'
   */
  static ME_VehInp_to_IpcSignals_t CANSignals;
  SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&CANSignals);


  TRSC_SM_VC_Int_B.IbTRSC_MEVehInpFromCAN14IpcSignals = CANSignals.CAN14_to_IPC;

  /* SignalConversion: '<Root>/Signal Conversion5' incorporates:
   *  Inport: '<Root>/IbTRSC_MEVehInpFromCAN2IpcSignals'
   */
 TRSC_SM_VC_Int_B.IbTRSC_MEVehInpFromCAN2IpcSignals = CANSignals.CAN2_to_IPC;

  /* SignalConversion: '<Root>/Signal Conversion6' incorporates:
   *  Inport: '<Root>/IbTRSC_MEProxiToIpcSignals'
   */
  static bool_t validProxyReceived_b = FALSE;
  if (FALSE == validProxyReceived_b)
  {
    SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get (&TRSC_SM_VC_Int_B.IbTRSC_MEProxiToIpcSignals);
    if (TRUE == TRSC_SM_VC_Int_B.IbTRSC_MEProxiToIpcSignals.PRX_bValid_b)
    {
      validProxyReceived_b = TRUE;
    }
  }

  /* SignalConversion: '<Root>/Signal Conversion7' incorporates:
   *  Inport: '<Root>/IbDDC_DegManagerDefSignals'
   */
  SigMgr_Data_FID_STRUCT_QM_Get(&TRSC_SM_VC_Int_B.IbDDC_DegManagerDefSignals);     
  /* SignalConversion: '<Root>/Signal Conversion8' incorporates:
   *  Inport: '<Root>/IbTRSCSmVc_TunParam'
   */

#if READ_TUNABLE_PARAMS
  static bool_t bFirst = true;
  if (true == bFirst)
  {
    TRSC_Calibration_data_MCU2_1_t TRSC_Calibration_data;
    SigMgr_Data_TRSC_Calibration_data_MCU2_1_t_Get(&TRSC_Calibration_data);
    if (TRUE == TRSC_Calibration_data.bValid)
    {
      TRSC_SM_VC_Int_B.IbTRSCSmVc_TunParam = TRSC_Calibration_data.CalData;
      bFirst = false;
    }
    else
    {
      KeTRSC_b_BypTunParam = 1;
    }
  }
#endif

  /* ModelReference: '<Root>/TRSC_Int_InpAdapter' */
  TRSC_InputAdapter(&TRSC_SM_VC_Int_B.IbTrailerDet_TrailerDetInpBus,
                    &TRSC_SM_VC_Int_B.IbSVS_SVStoTRSC,
                    &TRSC_SM_VC_Int_B.IbTRSC_MEVehInpFromCAN14IpcSignals,
                    &TRSC_SM_VC_Int_B.IbTRSC_MEVehInpFromCAN2IpcSignals,
                    &TRSC_SM_VC_Int_B.IbTRSC_MEProxiToIpcSignals,
                    &TRSC_SM_VC_Int_B.IbDDC_DegManagerDefSignals,
                    &TRSC_SM_VC_Int_B.IbTRSCSmVc_TunParam, &IbTRSC_InpBus);

  /* ModelReference: '<Root>/TRSC_IntModel' */
  TRSC_SM_VC();

  /* ModelReference: '<Root>/TRSC_Int_OutAdapter' */
  TRSC_OutputAdapter(&IeTRSC_e_SpdLmtReq, &IeTRSC_e_VehStpReq,
                     &IeTRSC_e_TRSCLedSts, &IeTRSC_e_TRSCPopupDispInfo,
                     &IeTRSC_e_TRSCSts, &IeTRSC_M_TRSCStrTrq,
                     &IeTRSC_e_TRSCStrTrqActvReq, &IeTRSC_pct_TRSCStrDmp,
                     &IeTRSC_b_MoreCamReqSts, &MeTRSC_e_TRSCStat,
                     &MeTRSC_b_MoreCamSoftButtEnbl, &MeTRSC_deg_JackKnifeAngle,
                     &MeTRSC_m_TrailerBeamLen, &MeTRSC_deg_JackknifeThrAngle,
                     &MeTRSC_deg_MaxAllowedTADAngle, &MeTRSC_deg_KnobAngle,
                     &MeTRSC_b_TRSCSwitchPressed,
                     &MeTRSC_b_TrlrRevSteeringStsInfo, &IeTRSC_e_TRSKMBtnSts,
                     &IeTRSC_cnt_KnobPos, &IeTRSC_e_TRSKMCenBtnSts,
                     &IeTRSC_e_TRSKMSts, &IeTRSC_e_GearShiftSts,
                     &IeTRSC_kph_VehSpeedVSOSig, &IeTRSC_e_TRSCUnavailReas,
                     &IeTRSC_e_TRSCAbortReas, &IeTRSC_m_TrlrWhlBaseEff,
                     &IeTRSC_deg_FrntWhlAng, &IeTRSC_deg_TrlrAngKnob,
                     &IeTRSC_deg_JackknifeThrAngle, &IeTRSC_e_TrlrHitchLightCtrl,
                     &MeTRSC_e_TrlrPrsntInfoCAN, &IeTRSC_deg_TADAngAct,
                     &IeTRSC_e_TADAngActSign, &IeTRSC_e_TrlrCalInfo,
                     &MeTRSC_b_OTBLReset, &MeTRSC_b_TBLComputationDone,
                     &MeTRSC_deg_StrCMD, &MeTRSC_b_TrlrCalibPopInfo,
                     &IeTRSC_kph_SpdLmtReq_DID, &MeSVS_e_DispView2Info_DID,
                     &IeTRSC_e_TRSKMBtnSts_DID, &IeTRSC_e_TRSKMCenBtnSts_DID,
                     &IeTRSC_e_TRSKMSts_DID, &IeTRSC_e_GearShiftSts_DID,
                     &IeTRSC_e_VehStpReq_DID, &IeTRSC_e_GraphicOverlay_Sts,
                     &IeTRSC_e_TRSCAbortReas_DID, &IeTRSC_e_TRSCUnavailReas_DID,
                     &MeTRSC_deg_TADAngleSMVC,
                     &TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC,
                     &TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS,
                     &TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC,
                     &TRSC_SM_VC_Int_B.IbTRSC_TRSCtoDiagMgr,
                     &TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5);

#if TRSC_SMVC_IPC_TEST
  Simulate_TRSC_SMVC_Output();
#endif

#if (TRSC_SIGM_TESTING)
  /* DataStoreWrite: '<Root>/Data Store Write' */
  // Send IPC message only if there is difference in current and previous message
  static ME_VehOut_TRSC_t IbTRSC_ME_VehOut_TRSC_prev;
  isNewMessage = memcmp((void*)&TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC,
                             (void*)&IbTRSC_ME_VehOut_TRSC_prev,
                             sizeof(ME_VehOut_TRSC_t));
  if (isNewMessage != 0)
  {
    SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(&TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC);
    memcpy((void*)&IbTRSC_ME_VehOut_TRSC_prev,
        (void*)&TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC,
        sizeof(ME_VehOut_TRSC_t));
  }

  /* Update debug signals */
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.ReservedSignal1 = 10.0f * TRSCcounter; /* Dummy value for testing*/
  TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS.ReservedSignal2 = 20.0f * TRSCcounter; /* Dummy value for testing*/
  /* DataStoreWrite: '<Root>/Data Store Write1' */
  // Send IPC message only if there is difference in current and previous message
  static TRSCSMVCtoSVS_t IbTRSC_TRSCtoSVS_prev;
  isNewMessage = memcmp((void*)&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS,
                             (void*)&IbTRSC_TRSCtoSVS_prev,
                             sizeof(TRSCSMVCtoSVS_t));
  if (isNewMessage != 0)
  {
    SigMgr_PpTrscSmvctoSvs_TRSCSMVCtoSVS_t_Put(&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS);
    memcpy((void*)&IbTRSC_TRSCtoSVS_prev,
        (void*)&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoSVS,
        sizeof(TRSCSMVCtoSVS_t));
  }

  /* DataStoreWrite: '<Root>/Data Store Write2' */
  // Send IPC message only if there is difference in current and previous message
  static Detection_Inputs_from_TRSC_t IbTRSC_DetInp_from_TRSC_prev;
  isNewMessage = memcmp((void*)&TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC,
                             (void*)&IbTRSC_DetInp_from_TRSC_prev,
                             sizeof(Detection_Inputs_from_TRSC_t));
  if (isNewMessage != 0)
  {
    SigMgr_PpDetInpTrsc_Detection_Inputs_from_TRSC_t_Put(&TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC);
    memcpy((void*)&IbTRSC_DetInp_from_TRSC_prev,
        (void*)&TRSC_SM_VC_Int_B.IbTRSC_DetInp_from_TRSC,
        sizeof(Detection_Inputs_from_TRSC_t));
  }

  /* DataStoreWrite: '<Root>/Data Store Write3' */
  SigMgr_Data_ME_CanDebugRIDStatus_t_Get(&debugStatus_s);
  // Send Debug IPC message only when enabled via RID
  if (Debug_Mode == debugStatus_s.CanDebugMode)
  {
    static TRSCtoDiagMgr_t IbTRSC_TRSCtoDiagMgr_prev;
    isNewMessage = memcmp((void*)&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoDiagMgr,
                              (void*)&IbTRSC_TRSCtoDiagMgr_prev,
                              sizeof(TRSCtoDiagMgr_t));
    // Send IPC message only if there is difference in current and previous message
    if (isNewMessage != 0)
    {
      SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoDiagMgr);
      memcpy((void*)&IbTRSC_TRSCtoDiagMgr_prev,
          (void*)&TRSC_SM_VC_Int_B.IbTRSC_TRSCtoDiagMgr,
          sizeof(TRSCtoDiagMgr_t));
    }
    /* DataStoreWrite: '<Root>/Data Store Write4' */
    TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5.MeTRSC_cnt_TRSCAliveCounter = TRSCcounter;
    TRSCcounter++;
    if (15 == TRSCcounter)
    {
        TRSCcounter = 0;
    }

    /* Update debug signals*/
    u64EndTime = TimerP_getTimeInUsecs();
    TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5.MeTRSC_s_TRSCTimeTaken = (uint16_t)(u64EndTime - u64StartTime);
    TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5.MeTRSC_s_TRSCPeriodicity = (uint16_t)(u64StartTime - u64PrevStartTime)/1000.0f;
    TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5.ReservedTRSCSig1 = 1.0f * TRSCcounter;
    TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5.ReservedTRSCSig2 = 2.0f * TRSCcounter;
    u64PrevStartTime = u64StartTime;

    static TRSCSMVCtoDebugCAN_t TRSC_Int_OutAdapter_o5_prev;
    isNewMessage = memcmp((void*)&TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5,
                              (void*)&TRSC_Int_OutAdapter_o5_prev,
                              sizeof(TRSCSMVCtoDebugCAN_t));
    // Send IPC message only if there is difference in current and previous message
    if (isNewMessage != 0)
    {
      SigMgr_PpTRSCSMVCtoDebug_TRSCSMVCtoDebugCAN_t_Put(&TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5);
      memcpy((void*)&TRSC_Int_OutAdapter_o5_prev,
          (void*)&TRSC_SM_VC_Int_B.TRSC_Int_OutAdapter_o5,
          sizeof(TRSCSMVCtoDebugCAN_t));
    }
  }
#endif
}

/* Model initialize function */
void TRSC_SM_VC_Int_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    TRSC_SM_VC_Int_B.IbTRSC_TRSCtoDiagMgr = TRSC_SM_VC_Int_rtZTRSCtoDiagMgr_t;
    TRSC_SM_VC_Int_B.IbTRSC_ME_VehOut_TRSC = TRSC_SM_VC_Int_rtZME_VehOut_TRSC_t;
  }

  /* exported global signals */
  IeTRSC_e_VehStpReq_DID = TeTRSC_e_VehStpReq_DID_NotActive;
  IeTRSC_e_TrlrHitchLightCtrl = TeTRSC_e_TrlrHitchLightCtrl_OFF;
  IeTRSC_e_TRSKMSts_DID = TeTRSC_e_TRSKMSts_DID_NotEnabled;
  IeTRSC_e_TRSCUnavailReas_DID = TeTRSC_e_TRSCUnavailReas_DID_Fail_Not_Present;
  IeTRSC_e_TRSCAbortReas_DID = TeTRSC_e_TRSCAbortReason_DID_Fail_Not_Present;

  /* Model Initialize function for ModelReference Block: '<Root>/TRSC_IntModel' */
  TRSC_SM_VC_initialize(rtmGetErrorStatusPointer(TRSC_SM_VC_Int_M));

  /* Model Initialize function for ModelReference Block: '<Root>/TRSC_Int_InpAdapter' */
  TRSC_InputAdapter_initialize(rtmGetErrorStatusPointer(TRSC_SM_VC_Int_M));

  /* Model Initialize function for ModelReference Block: '<Root>/TRSC_Int_OutAdapter' */
  TRSC_OutputAdapter_initialize(rtmGetErrorStatusPointer(TRSC_SM_VC_Int_M));

  /* Start for ModelReference: '<Root>/TRSC_IntModel' */
  TRSC_SM_VC_Start();

  /* Start for DataStoreMemory: '<Root>/Data Store Memory' */
  SigMgr_PpTRSC_ME_VehOut_TRSC_t_Put(&TRSC_SM_VC_Int_rtZME_VehOut_TRSC_t);

  /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
  SigMgr_PpTrscToDiag_TRSCtoDiagMgr_t_Put(&TRSC_SM_VC_Int_rtZTRSCtoDiagMgr_t);

  /* SystemInitialize for ModelReference: '<Root>/TRSC_IntModel' */
  TRSC_SM_VC_Init();
}

/* Model terminate function */
void TRSC_SM_VC_Int_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
