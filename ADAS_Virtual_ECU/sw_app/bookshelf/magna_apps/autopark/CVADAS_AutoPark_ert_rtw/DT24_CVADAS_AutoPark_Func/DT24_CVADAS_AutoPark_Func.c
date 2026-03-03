/*
 * File: DT24_CVADAS_AutoPark_Func.c
 *
 * Code generated for Simulink model 'DT24_CVADAS_AutoPark_Func'.
 *
 * Model version                  : 1.340
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:12:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "DT24_CVADAS_AutoPark_Func.h"
#include "DT24_CVADAS_AutoPark_Func_private.h"

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T MeAP_k_PerpNoseIn;           /* '<S1>/StateMachine_Controller' */
uint8_T PSType;                        /* '<S1>/StateMachine_Controller' */
uint8_T parkout_perp_left;             /* '<S1>/StateMachine_Controller' */
MdlrefDW_DT24_CVADAS_AutoPark_Func_T DT24_CVADAS_AutoPark_Func_MdlrefDW;

/* Block signals (default storage) */
B_DT24_CVADAS_AutoPark_Func_c_T DT24_CVADAS_AutoPark_Func_B;

/* Block states (default storage) */
DW_DT24_CVADAS_AutoPark_Func_f_T DT24_CVADAS_AutoPark_Func_DW;

/* System initialize for referenced model: 'DT24_CVADAS_AutoPark_Func' */
void DT24_CVADAS_AutoPark_Func_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S1>/Unit Delay5' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay5_DSTATE =
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON;

  /* SystemInitialize for ModelReference generated from: '<S1>/StateMachine_Controller' */
  SWC_AP_StateMachine_Init();

  /* SystemInitialize for ModelReference generated from: '<S1>/APA_Controller' */
  SWC_APA_Init();

  /* SystemInitialize for ModelReference generated from: '<S1>/VC_Controller' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetY'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetY'
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRL'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRR'
   */
  SWC_VC_Init();
}

/* Disable for referenced model: 'DT24_CVADAS_AutoPark_Func' */
void DT24_CVADAS_AutoPark_Func_Disable(void)
{
  /* Disable for ModelReference generated from: '<S1>/APA_Controller' */
  SWC_APA_Disable();

  /* Disable for ModelReference generated from: '<S1>/VC_Controller' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetY'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetY'
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRL'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRR'
   */
  SWC_VC_Disable();
}

/* Start for referenced model: 'DT24_CVADAS_AutoPark_Func' */
void DT24_CVADAS_AutoPark_Func_Start(void)
{
  /* Start for ModelReference generated from: '<S1>/VC_Controller' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetY'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetY'
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRL'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRR'
   */
  SWC_VC_Start();
}

/* Output and update for referenced model: 'DT24_CVADAS_AutoPark_Func' */
void DT24_CVADAS_AutoPark_Func(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ReadParam *rtu_MbNVM_ReadParam, const
  TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const TbUSS_DiagFlag
  *rtu_MbUSS_DiagFlag, const IJobFPAOutput_t *rtu_LwSpd_FPA_Output, const
  TeTHA_e_RearBrkSupprInfo *rtu_MeTHA_e_RearBrkSupprInfo, const int16_T
  *rtu_MeAP_I_WhlPosRR, const int16_T *rtu_MeAP_I_WhlPosRL, const uint8_T
  *rtu_MeAP_I_GearRpt, const US_S_PointMapOutputBuff_t *rtu_USS_2DPointMap,
  const real32_T *rtu_MeAP_cm_CDminDist, const TeTRSC_e_TRSCSts
  *rtu_IeTRSC_e_TRSCSts, const boolean_T *rtu_IeVBII_b_ActvParkMode, const
  boolean_T *rtu_MeAP_b_ObjInPath, const boolean_T
  *rtu_IbFID_PA_MeAP_b_ExternalFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_SystemFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FPADisable, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPADisable, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPAActvTrlr_29, const boolean_T
  *rtu_IbFID_PA_MeAP_b_PAVolDefMed, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FPAVolDefMed, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPAVolDefMed, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FrntSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FrntSenorBlock, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RearSenorBlock, const boolean_T
  *rtu_IbFID_PARB_MeAP_b_PARBActv4LOW, const boolean_T
  *rtu_IbFID_PARB_MeAP_b_PARBDiable, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MbDiag_TestModeForceOn, const int16_T *rtu_MeAP_cm_FrntCenterMinXDist,
  const int16_T *rtu_MeAP_cm_FrntLeftMinXDist, const int16_T
  *rtu_MeAP_cm_FrntRightMinXDist, const int16_T *rtu_MeAP_cm_RearCenterMinXDist,
  const int16_T *rtu_MeAP_cm_RearLeftMinXDist, const int16_T
  *rtu_MeAP_cm_RearRightMinXDist, const boolean_T *rtu_MeAP_b_ObjPrestFC, const
  boolean_T *rtu_MeAP_b_ObjPrestRC, const int16_T *rtu_IeVBII_deg_StrWhlSpd,
  const boolean_T *rtu_MbDiag_PlantModeOn, const TeTRSC_e_TRSCPopupDispInfo
  *rtu_IeTRSC_e_TRSCPopupDispInfo, const uint8_T
  *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront, const
  uint8_T *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL, const
  uint8_T *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR, const
  uint8_T *rtu_MeAP_b_IsWall, const int16_T *rtu_MeAP_cm_WallFrntCenterDist,
  const int16_T *rtu_MeAP_cm_WallRearCenterDist, boolean_T *rty_MeAP_b_FPAStatus,
  boolean_T *rty_MeAP_b_RPAStatus, TeAP_e_ParkAssistStatus
  *rty_MeAP_e_ParkAssistStatus, TeAutoPark_e_ScanDir *rty_IeAutoPark_e_ScanDir,
  TeAP_e_PAMSystemFault *rty_IeAP_e_PAMSystemFault, TeAP_e_PAMOffStatus2BT
  *rty_MeAP_e_PAMOffStatus2BT, TeAP_e_FrntSnsrStatus *rty_MeAP_e_FrntSnsrStatus,
  TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus, boolean_T
  *rty_MeAP_b_DisableDiag, boolean_T *rty_MeAP_b_AutoParkEnblSwtStuckStatus,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_SPMLatCtrlReqSts
  *rty_IeAP_e_SPMLatCtrlReqSts, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_MeAP_b_SystemFail,
  boolean_T *rty_MeAP_b_ExternalFail, boolean_T *rty_MeAP_b_RPAwithBrkDisable,
  boolean_T *rty_MeAP_b_RPADisable, boolean_T *rty_MeAP_b_FPADisable,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_Alert
  *rty_MeAP_e_AlertCHF, TeAP_e_Alert *rty_MeAP_e_AlertLHF, TeAP_e_Alert
  *rty_MeAP_e_AlertRHF, TeAP_e_Alert *rty_MeAP_e_AlertCHR, TeAP_e_Alert
  *rty_MeAP_e_AlertLHR, TeAP_e_Alert *rty_MeAP_e_AlertRHR,
  TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHF, TeAP_e_GraphicFlshRate
  *rty_MeAP_e_GraphicLHF, TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHF,
  TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHR, TeAP_e_GraphicFlshRate
  *rty_MeAP_e_GraphicLHR, TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHR,
  boolean_T *rty_MeAP_b_ChimeActvLHF, boolean_T *rty_MeAP_b_ChimeActvRHF,
  boolean_T *rty_MeAP_b_ChimeActvLHR, boolean_T *rty_MeAP_b_ChimeActvRHR,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRate, TeAP_e_PAMVolume
  *rty_MeAP_e_PAMVolume, TeAP_e_PAMLedCtrlStatus
  *rty_MeAP_e_FrntPAMLedCtrlStatus, TeAP_e_PAMLedCtrlStatus
  *rty_MeAP_e_RearPAMLedCtrlStatus, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTyp,
  TeAP_e_PAMPopUpReq *rty_MeAP_e_PAMPopUpReq, boolean_T
  *rty_MeAP_b_PAMBrkReqStatus, real32_T *rty_MeAP_cm_RearDist, boolean_T
  *rty_MeAP_b_PAMStopCtrlStatus, real32_T *rty_MeAP_deg_StrCmd, real32_T
  *rty_MeAP_a_BrkCmd, real32_T *rty_MeAP_a_ThrtlCmd, int32_T
  *rty_IeAP_e_TurnIndicReq, real32_T *rty_IeAP_nm_StrwTrqReq, real32_T
  *rty_IeAP_a_DecelMax, real32_T *rty_IeAP_a_DecelMin, real32_T
  *rty_IeAP_a_JerkDecelMax, real32_T *rty_IeAP_a_JerkDecelMin, real32_T
  *rty_IeAP_a_AcclMin, real32_T *rty_IeAP_a_AcclMax, real32_T
  *rty_IeAP_da_JerkAcclMax, real32_T *rty_IeAP_da_JerkAcclMin, boolean_T
  *rty_IeAP_b_StandstillReq1, real32_T *rty_IeAP_cm_TrgtDist, boolean_T
  *rty_MeAP_b_ManeuverAbort, boolean_T *rty_MeAP_b_ManeuverSuccess, int8_T
  *rty_MeAP_e_PP_state, real32_T *rty_MeAP_e_Park_state, real32_T
  rty_MaAP_m_PlannerWayPointsX[250], real32_T rty_MaAP_m_PlannerWayPointsY[250],
  boolean_T *rty_MeAP_b_PosMet, boolean_T *rty_MeAP_b_SteerActionReq, real32_T
  *rty_IeAP_kph_TrgtVehSpd, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, TeAP_e_USSSupplyPwrSt
  *rty_MeAP_e_USSSupplyPwrSt, TeAP_e_USSSystemMode *rty_MeAP_e_USSSystemMode,
  TeAP_e_USSSystemState *rty_MeAP_e_USSSystemState, uint8_T
  *rty_MeAP_e_USSFiringMode, boolean_T *rty_MeAP_b_USSReInit, boolean_T
  *rty_MeAP_b_ScanSts, uint16_T *rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar,
  uint16_T *rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_APInitSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_DriverOverride, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_StandStill, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VehCndSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl, real32_T *rty_IbVC_DebugOut_X_MABx,
  real32_T *rty_IbVC_DebugOut_Y_MABx, real32_T *rty_IbVC_DebugOut_heading_MABx,
  real32_T *rty_IbVC_DebugOut_Str_Trq_CMD, real32_T
  *rty_IbVC_DebugOut_VC_RemainingDist, real32_T *rty_IbVC_DebugOut_VC_PathDev,
  real32_T *rty_IbVC_DebugOut_VC_Head_Dev, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBY, uint8_T
  *rty_IbVC_DebugOut_PM_CurrentSweep, boolean_T *rty_IbVC_DebugOut_PM_RegenPath)
{
  /* UnitDelay: '<S1>/Unit Delay' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay2' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay2 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay2_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay3' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay3 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay1' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay1 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay4' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay4 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay4_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay5' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay5 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay5_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay6' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay6 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay6_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay7' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay7 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay7_DSTATE;

  /* UnitDelay: '<S1>/Unit Delay8' */
  DT24_CVADAS_AutoPark_Func_B.UnitDelay8 =
    DT24_CVADAS_AutoPark_Func_DW.UnitDelay8_DSTATE;

  /* ModelReference generated from: '<S1>/StateMachine_Controller' */
  SWC_AP_StateMachine(rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide,
                      rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter,
                      rtu_MbDiag_PlantModeOn, rtu_MbDiag_TestModeForceOn,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay2,
                      rtu_IbVBII_VehState_LowSpd, rtu_MbNVM_ReadParam,
                      rtu_MbNVM_ProxyParam, rtu_MbUSS_DiagFlag,
                      rtu_LwSpd_FPA_Output,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay1,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay4,
                      rtu_MeAP_b_ObjInPath, rtu_IbFID_PA_MeAP_b_FrntSenorFail,
                      rtu_IbFID_PA_MeAP_b_FrntSenorBlock,
                      rtu_IbFID_PA_MeAP_b_RearSenorFail,
                      rtu_IbFID_PA_MeAP_b_RearSenorBlock,
                      rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr,
                      rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW,
                      rtu_IbFID_PPPA_MeAP_b_PPPADisable,
                      rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd,
                      rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd,
                      rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
                      rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur,
                      rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur,
                      rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur,
                      rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn,
                      rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt,
                      rtu_MeAP_b_ObjPrestFC, rtu_MeAP_b_ObjPrestRC,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay5,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay6,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay7,
                      &DT24_CVADAS_AutoPark_Func_B.UnitDelay8,
                      rtu_MeTHA_e_RearBrkSupprInfo,
                      &DT24_CVADAS_AutoPark_Func_B.IeAP_e_FrntSnsrStatus,
                      &DT24_CVADAS_AutoPark_Func_B.IeAP_e_RearSnsrStatus,
                      rty_MeAP_b_DisableDiag,
                      rty_MeAP_b_AutoParkEnblSwtStuckStatus,
                      rty_IeAP_e_InterfaceBSM, rty_IeAP_e_SPMLatCtrlReqSts,
                      rty_IeAP_e_ParKMnvrActv, rty_MeAP_e_HMIPopUp,
                      rty_IeAP_e_SPMLedSts, rty_IeAP_b_SPMFailSts,
                      rty_IeAP_b_SPMFaultSts, rty_IeAP_e_SPMActvStat,
                      rty_IeAP_b_VehMnvrDirSPM, rty_IeAP_b_StandstillReq,
                      rty_MeAP_b_VCOpPaused, rty_IeAP_e_GearShiftReq,
                      rty_MeAP_e_PAMVolSigSVM, rty_MeAP_b_ChimeActvReqLHFSVM,
                      rty_MeAP_b_ChimeActvReqLHRSVM,
                      rty_MeAP_b_ChimeActvReqRHFSVM,
                      rty_MeAP_b_ChimeActvReqRHRSVM, rty_MeAP_e_PAMChimeTypSVM,
                      rty_MeAP_e_PAMChimeRepnRateSVM, (&(parkout_perp_left)),
                      &DT24_CVADAS_AutoPark_Func_B.MeAP_b_VCActive,
                      (&(MeAP_k_PerpNoseIn)), (&(PSType)),
                      &DT24_CVADAS_AutoPark_Func_B.MeAP_b_ParkOut,
                      &DT24_CVADAS_AutoPark_Func_B.MeAP_b_ResetVCKM,
                      rty_MeAP_e_USSSupplyPwrSt, rty_MeAP_e_USSSystemMode,
                      rty_MeAP_e_USSSystemState, rty_MeAP_e_USSFiringMode,
                      rty_MeAP_b_USSReInit, rty_MeAP_b_ScanSts,
                      rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar,
                      rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar,
                      rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused,
                      rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout,
                      rty_IbAP_SMDebugOut_MeAP_b_APInitSts,
                      rty_IbAP_SMDebugOut_MeAP_b_DriverOverride,
                      rty_IbAP_SMDebugOut_MeAP_b_StandStill,
                      rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv,
                      rty_IbAP_SMDebugOut_MeAP_b_VehCndSts,
                      rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl,
                      &DT24_CVADAS_AutoPark_Func_B.MeAP_b_StandStill);

  /* ModelReference generated from: '<S1>/APA_Controller' */
  SWC_APA(&rtu_IbVBII_VehState_LowSpd->IeVBII_e_CmdIgnSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_FrntParkAsstReq,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_ParkAsstReq,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_RemoteStartActvSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_SnowPlowAttached,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrailerConnectionSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TrlrPrsntSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_degC_ExtTemp,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_BrkStat,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_VehEPBSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TCaseRangeSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_EssEngState,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_PamChimeVolFrnt,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_PamChimeVolRear,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_RearBrkAsst,
          &rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdTrgtGear,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TransSailingTst,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_a_VehLatAcc,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_a_VehLongAcc,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_kph_VehSpeedVSOSig,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_ddeg_VehYawRate,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_cnt_LhfPulseCtr,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_LhfWhlSpnSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_kph_LhfWhlSpd,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_cnt_LhrPulseCtr,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_kph_LhrWhlSpd,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_cnt_RhfPulseCtr,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_RhfWhlSpnSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_kph_RhfWhlSpd,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_cnt_RhrPulseCtr,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_kph_RhrWhlSpd,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_deg_StrWhlAng,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_deg_StrWhlSpd,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_ShifterAutoconnectSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ShiftLvrPosReq,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_AutoParkEnblSwt,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TurnIndicSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_DriverDoorSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRL,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorP,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_TrnkStatus,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_DoorRR,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_EngineSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_per_PdlPosAct,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_ActvParkMode,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_LanguageSeln,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TGWCamDispSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TchScrSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TchXCoord,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_TchYCoord,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_GearShiftReqAccept,
          &rtu_IbVBII_VehState_LowSpd->MeAP_e_FiltdGearRptState,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ACCSysSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_nm_BrkTrqAct,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingIntrvntionSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_HandsOnRecog,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_SPMLatCtrlRespSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_M_StrWhlTrq,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_VehLatAccFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_VehLongAccFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_VehYawRateFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_LHFWhlSnsrFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_LHRWhlSnsrFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_RHFWhlSnsrFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_RHRWhlSnsrFailSts,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_PAMBrkReqRespStatus,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ShiftLvrPos,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_nm_BrkTrqDriver,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ExtBrkReqDisabled,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_ParkingGearShiftReq,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_pct_Slope,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_DriverReqAxleTrqEnabled,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_e_BrkPdlStat,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_Override,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_TrqEnblReqAllowed,
          &rtu_IbVBII_VehState_LowSpd->IeVBII_b_ParkProxChime,
          &rtu_MbNVM_ProxyParam->KeAP_b_CanNode67DTCM,
          &rtu_MbNVM_ProxyParam->KeAP_b_CanNode63TTM,
          &rtu_MbNVM_ProxyParam->KeAP_b_StopAndStrt,
          &rtu_MbNVM_ProxyParam->KeAP_mm_TyreSz,
          &rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp,
          &rtu_MbNVM_ProxyParam->KeAP_e_DrvTypVrnt,
          &rtu_MbNVM_ProxyParam->KeAP_e_GbTyp,
          &rtu_MbNVM_ProxyParam->KeAP_e_PAMTunSet,
          &rtu_MbNVM_ProxyParam->KeAP_e_VehLineCfg,
          &rtu_MbNVM_ProxyParam->KeAP_e_CtryCod,
          &rtu_MbNVM_ProxyParam->KeAP_e_HybTyp,
          &rtu_MbNVM_ProxyParam->KeAP_e_WhlBas,
          &rtu_MbNVM_ProxyParam->KeAP_b_ParkWithStop,
          &rtu_MbNVM_ProxyParam->KeAP_b_PAMCfg,
          &rtu_MbNVM_ProxyParam->KeAP_e_RadioDispTyp,
          &rtu_MbNVM_ProxyParam->KeAP_b_CanNode95ITBMTCM,
          &rtu_MbNVM_ProxyParam->KeAP_b_DrvSide,
          &rtu_MbNVM_ProxyParam->KeAP_b_SemiAutoPrkgSys,
          &rtu_MbNVM_ProxyParam->KeAP_e_MdlYr,
          &rtu_MbNVM_ProxyParam->KeAP_b_PullOutCtrlPres,
          &rtu_MbNVM_ProxyParam->KeAP_b_FullAutoPrkgSys,
          &rtu_MbNVM_ProxyParam->KeAP_b_TrlrHitchAsstPres,
          &rtu_MbNVM_ProxyParam->KeAP_b_TrlrRvsSteerPres,
          &rtu_MbNVM_ProxyParam->KeAP_b_SVSPresent,
          &rtu_MbNVM_ProxyParam->KeAP_k_VariantID,
          rtu_IbFID_PA_MeAP_b_ExternalFail, rtu_IbFID_PA_MeAP_b_SystemFail,
          rtu_IbFID_PA_MeAP_b_FPADisable, rtu_IbFID_PA_MeAP_b_RPADisable,
          rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27, rtu_IbFID_PA_MeAP_b_RPAActvTrlr_29,
          rtu_IbFID_PA_MeAP_b_PAVolDefMed, rtu_IbFID_PA_MeAP_b_FPAVolDefMed,
          rtu_IbFID_PA_MeAP_b_RPAVolDefMed, rtu_IbFID_PA_MeAP_b_FrntSenorFail,
          rtu_IbFID_PA_MeAP_b_FrntSenorBlock, rtu_IbFID_PA_MeAP_b_RearSenorFail,
          rtu_IbFID_PA_MeAP_b_RearSenorBlock, rtu_IbFID_PARB_MeAP_b_PARBActv4LOW,
          rtu_IbFID_PARB_MeAP_b_PARBDiable, rtu_MbNVM_ReadParam,
          rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd,
          rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd,
          rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd,
          rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd,
          rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep,
          rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6,
          rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj,
          rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn,
          rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk,
          rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView,
          rtu_USS_2DPointMap, rty_IeAP_e_SPMLatCtrlReqSts,
          rty_IeAP_e_ParKMnvrActv, rtu_IeTRSC_e_TRSCSts,
          rtu_MeTHA_e_RearBrkSupprInfo, rtu_MbDiag_TestModeForceOn,
          rtu_MeAP_cm_FrntCenterMinXDist, rtu_MeAP_cm_FrntLeftMinXDist,
          rtu_MeAP_cm_FrntRightMinXDist, rtu_MeAP_cm_RearCenterMinXDist,
          rtu_MeAP_cm_RearLeftMinXDist, rtu_MeAP_cm_RearRightMinXDist,
          rtu_MbDiag_PlantModeOn, rtu_IeTRSC_e_TRSCPopupDispInfo,
          rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront,
          rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL,
          rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR,
          rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear,
          rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL,
          rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR,
          rtu_MeAP_b_IsWall, rtu_MeAP_cm_WallFrntCenterDist,
          rtu_MeAP_cm_WallRearCenterDist, rty_MeAP_e_AlertCHF,
          rty_MeAP_e_AlertLHF, rty_MeAP_e_AlertRHF, rty_MeAP_e_AlertCHR,
          rty_MeAP_e_AlertLHR, rty_MeAP_e_AlertRHR, rty_MeAP_e_GraphicCHF,
          rty_MeAP_e_GraphicLHF, rty_MeAP_e_GraphicRHF, rty_MeAP_e_GraphicCHR,
          rty_MeAP_e_GraphicLHR, rty_MeAP_e_GraphicRHR, rty_MeAP_b_ChimeActvLHF,
          rty_MeAP_b_ChimeActvRHF, rty_MeAP_b_ChimeActvLHR,
          rty_MeAP_b_ChimeActvRHR, rty_MeAP_e_PAMChimeRepnRate,
          rty_MeAP_e_PAMVolume, rty_MeAP_e_FrntPAMLedCtrlStatus,
          rty_MeAP_e_RearPAMLedCtrlStatus, rty_MeAP_e_PAMChimeTyp,
          rty_MeAP_e_PAMPopUpReq, rty_MeAP_b_PAMBrkReqStatus,
          rty_MeAP_cm_RearDist, rty_MeAP_b_PAMStopCtrlStatus,
          rty_MeAP_e_ParkAssistStatus, rty_MeAP_b_FPAStatus,
          rty_MeAP_b_RPAStatus, rty_IeAP_e_PAMSystemFault,
          rty_MeAP_e_PAMOffStatus2BT, rty_MeAP_b_SystemFail,
          rty_MeAP_b_ExternalFail, rty_MeAP_b_RPAwithBrkDisable,
          rty_MeAP_b_RPADisable, rty_MeAP_b_FPADisable, rty_IeAutoPark_e_ScanDir,
          rty_MeAP_e_FrntSnsrStatus, rty_IeAP_e_RearSnsrStatus);

  /* ModelReference generated from: '<S1>/VC_Controller' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetY'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderX'
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderY'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetX'
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetY'
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRL'
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRR'
   */
  SWC_VC(rtu_MeAP_I_WhlPosRR, rtu_MeAP_I_WhlPosRL, rtu_MeAP_I_GearRpt,
         &DT24_CVADAS_AutoPark_Func_B.MeAP_b_VCActive,
         &DT24_CVADAS_AutoPark_Func_B.MeAP_b_ParkOut,
         &DT24_CVADAS_AutoPark_Func_B.MeAP_b_ResetVCKM, rtu_MbNVM_ProxyParam,
         rtu_MeAP_cm_CDminDist, rty_MeAP_b_VCOpPaused, rtu_IeVBII_b_ActvParkMode,
         rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth,
         rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj,
         rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj,
         rtu_IeVBII_deg_StrWhlSpd, rty_MeAP_deg_StrCmd, rty_MeAP_a_BrkCmd,
         rty_MeAP_a_ThrtlCmd, rty_IeAP_e_TurnIndicReq, rty_IeAP_nm_StrwTrqReq,
         rty_IeAP_a_DecelMax, rty_IeAP_a_DecelMin, rty_IeAP_a_JerkDecelMax,
         rty_IeAP_a_JerkDecelMin, rty_IeAP_a_AcclMin, rty_IeAP_a_AcclMax,
         rty_IeAP_da_JerkAcclMax, rty_IeAP_da_JerkAcclMin,
         rty_IeAP_b_StandstillReq1, rty_IeAP_cm_TrgtDist,
         rty_MeAP_b_ManeuverAbort, rty_MeAP_b_ManeuverSuccess,
         rty_MeAP_e_PP_state, rty_MeAP_e_Park_state,
         &rty_MaAP_m_PlannerWayPointsX[0], &rty_MaAP_m_PlannerWayPointsY[0],
         rty_MeAP_b_PosMet, rty_MeAP_b_SteerActionReq, rty_IeAP_kph_TrgtVehSpd,
         &DT24_CVADAS_AutoPark_Func_B.MeAP_e_GearCmd_j, rty_IbVC_DebugOut_X_MABx,
         rty_IbVC_DebugOut_Y_MABx, rty_IbVC_DebugOut_heading_MABx,
         rty_IbVC_DebugOut_Str_Trq_CMD, rty_IbVC_DebugOut_VC_RemainingDist,
         rty_IbVC_DebugOut_VC_PathDev, rty_IbVC_DebugOut_VC_Head_Dev,
         rty_IbVC_DebugOut_Ma_AP_I_PSLimFSX, rty_IbVC_DebugOut_Ma_AP_I_PSLimFSY,
         rty_IbVC_DebugOut_Ma_AP_I_PSLimFBX, rty_IbVC_DebugOut_Ma_AP_I_PSLimFBY,
         rty_IbVC_DebugOut_Ma_AP_I_PSLimRSX, rty_IbVC_DebugOut_Ma_AP_I_PSLimRSY,
         rty_IbVC_DebugOut_Ma_AP_I_PSLimRBX, rty_IbVC_DebugOut_Ma_AP_I_PSLimRBY,
         rty_IbVC_DebugOut_PM_CurrentSweep, rty_IbVC_DebugOut_PM_RegenPath);

  /* Update for UnitDelay: '<S1>/Unit Delay' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay_DSTATE = *rty_MeAP_b_PosMet;

  /* Update for UnitDelay: '<S1>/Unit Delay2' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay2_DSTATE = *rty_MeAP_b_SteerActionReq;

  /* Update for UnitDelay: '<S1>/Unit Delay3' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay3_DSTATE = *rty_MeAP_b_ManeuverSuccess;

  /* Update for UnitDelay: '<S1>/Unit Delay1' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay1_DSTATE =
    DT24_CVADAS_AutoPark_Func_B.MeAP_e_GearCmd_j;

  /* Update for UnitDelay: '<S1>/Unit Delay4' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay4_DSTATE = *rty_MeAP_b_ManeuverAbort;

  /* Update for UnitDelay: '<S1>/Unit Delay5' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay5_DSTATE = *rty_MeAP_e_PAMOffStatus2BT;

  /* Update for UnitDelay: '<S1>/Unit Delay6' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay6_DSTATE = *rty_IeAP_cm_TrgtDist;

  /* Update for UnitDelay: '<S1>/Unit Delay7' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay7_DSTATE = *rty_IeAP_kph_TrgtVehSpd;

  /* Update for UnitDelay: '<S1>/Unit Delay8' */
  DT24_CVADAS_AutoPark_Func_DW.UnitDelay8_DSTATE = *rty_IeAP_nm_StrwTrqReq;
}

/* Model initialize function */
void DT24_CVADAS_AutoPark_Func_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_DT24_CVADAS_AutoPark_Func_T *const DT24_CVADAS_AutoPark_Func_M =
    &(DT24_CVADAS_AutoPark_Func_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(DT24_CVADAS_AutoPark_Func_M, rt_errorStatus);

  /* block I/O */
  {
    DT24_CVADAS_AutoPark_Func_B.StateMachine_Controller_o12 =
      TeAutoPark_e_GearCmd_Drive;
    DT24_CVADAS_AutoPark_Func_B.IeAP_e_SemiParkSysSts = ((uint8_T)1U);
    DT24_CVADAS_AutoPark_Func_B.APA_Controller_o33 = true;
    DT24_CVADAS_AutoPark_Func_B.MeAP_b_ParkSlotDetctSts = true;
    DT24_CVADAS_AutoPark_Func_B.IeAP_b_MnvPosOk = true;
  }

  /* Model Initialize function for ModelReference Block: '<S1>/APA_Controller' */
  SWC_APA_initialize(rtmGetErrorStatusPointer(DT24_CVADAS_AutoPark_Func_M));

  /* Model Initialize function for ModelReference Block: '<S1>/StateMachine_Controller' */
  SWC_AP_StateMachine_initialize(rtmGetErrorStatusPointer
    (DT24_CVADAS_AutoPark_Func_M));

  /* Model Initialize function for ModelReference Block: '<S1>/VC_Controller' */
  SWC_VC_initialize(rtmGetErrorStatusPointer(DT24_CVADAS_AutoPark_Func_M));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
