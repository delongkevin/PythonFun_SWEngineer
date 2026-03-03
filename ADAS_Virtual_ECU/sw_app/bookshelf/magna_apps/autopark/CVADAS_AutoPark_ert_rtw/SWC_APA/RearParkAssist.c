/*
 * File: RearParkAssist.c
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.594
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:11:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "RearParkAssist.h"

/* Include model header file for global data */
#include "SWC_APA.h"
#include "SWC_APA_private.h"

/* Includes for objects with custom storage classes. */
#include "SWC_APA.h"
#include "LookUp_U16_real32_T.h"
#include "look1_iflftu16Df_binlcpw.h"

/* Named constants for Chart: '<S484>/AlertFilterCHR' */
#define SWC_APA_IN_HOLD_OUTPUT_o       ((uint8_T)1U)
#define SWC_APA_IN_UPDATE_OUTPUT_j     ((uint8_T)2U)
//Keep++
#define US_D_PHYS_GRP_FRNT 0u
#define US_D_PHYS_GRP_REAR 1u
extern uint8_T UssOD_bIsLowObject(uint8_T u_phys_grp);
extern void UssOD_setArcSignal(uint32_t arcs_from_feature, uint8_t current_arc);
//Keep--
/* Extern declarations from model 'SWC_APA' */
extern const TeVBII_e_CmdIgnSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TrailerConnectionSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TrlrPrsntSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_BrkStat *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkStat;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_VehEPBSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TCaseRangeSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_EssEngState
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EssEngState;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_PamChimeVol
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_PamChimeVol
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst;/* '<Root>/IbVBIA_VehState' */
extern const TeAP_e_FiltdGearState
  *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TransSailingTst
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate;/* '<Root>/IbVBIA_VehState' */
extern const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_WhlSpnSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd;/* '<Root>/IbVBIA_VehState' */
extern const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd;/* '<Root>/IbVBIA_VehState' */
extern const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_WhlSpnSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd;/* '<Root>/IbVBIA_VehState' */
extern const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ShiftLvrPosReq
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TurnIndicSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRL;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorP;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRR;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_EngineSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EngineSts;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_LanguageSeln
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TGWCamDispSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_TchScrSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchScrSts;/* '<Root>/IbVBIA_VehState' */
extern const uint16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchXCoord;/* '<Root>/IbVBIA_VehState' */
extern const uint16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchYCoord;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept;/* '<Root>/IbVBIA_VehState' */
extern const TeAP_e_FiltdGearState
  *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ACCSysSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts;/* '<Root>/IbVBIA_VehState' */
extern const uint32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ParkingIntrvntionSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_SPMLatCtrlRespSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts;/* '<Root>/IbVBIA_VehState' */
extern const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_PAMBrkReqRespStatus
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ShiftLvrPos
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos;/* '<Root>/IbVBIA_VehState' */
extern const uint32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ExtBrkReqDisabled
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_ParkingGearShiftReq
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq;/* '<Root>/IbVBIA_VehState' */
extern const int16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_pct_Slope;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_DriverReqAxleTrqEnabled
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled;/* '<Root>/IbVBIA_VehState' */
extern const TeVBII_e_BrkPdlStat
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_Override;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime;/* '<Root>/IbVBIA_VehState' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt;/* '<Root>/MbNVM_ProxyParam' */
extern const uint16_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_SteerRatRackPinionTyp
  *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_DrvTypVrnt *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_GbTyp *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_GbTyp;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_PAMTunSet *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet;/* '<Root>/MbNVM_ProxyParam' */
extern const uint8_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_CtryCod *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_CtryCod;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_HybTyp *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_HybTyp;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_WhlBas *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_WhlBas;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg;/* '<Root>/MbNVM_ProxyParam' */
extern const TeAP_e_RadioDispTyp
  *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_DrvSide;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys;/* '<Root>/MbNVM_ProxyParam' */
extern const uint16_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_MdlYr;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent;/* '<Root>/MbNVM_ProxyParam' */
extern const uint8_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_k_VariantID;/* '<Root>/MbNVM_ProxyParam' */
extern const boolean_T *SWC_APA_rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27;/* '<Root>/IbFID_PA' */
extern const boolean_T *SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBActv4LOW;/* '<Root>/IbFID_PARB' */
extern const boolean_T *SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBDiable;/* '<Root>/IbFID_PARB' */
extern const TbNVM_ReadParam *SWC_APA_rtu_MbNVM_ReadParam;/* '<Root>/MbNVM_ReadParam' */
extern const real32_T *SWC_APA_rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth;/* '<Root>/IbAP_InputVrntTunParam' */
extern const uint16_T
  *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert;/* '<Root>/IbAP_InputVrntTunParam' */
extern const uint16_T
  *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd;/* '<Root>/IbAP_InputVrntTunParam' */
extern const uint16_T
  *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd;/* '<Root>/IbAP_InputVrntTunParam' */
extern const uint16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6;/* '<Root>/IbAP_InputVrntTunParam' */
extern const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj;/* '<Root>/IbAP_InputVrntTunParam' */
extern const US_S_PointMapOutputBuff_t *SWC_APA_rtu_USS_2DPointMap;/* '<Root>/USS_2DPointMap' */
extern const TeAP_e_ParKMnvrActv *SWC_APA_rtu_IeAP_e_ParKMnvrActv;/* '<Root>/IeAP_e_ParKMnvrActv' */
extern const TeTHA_e_RearBrkSupprInfo *SWC_APA_rtu_MeTHA_e_RearBrkSupprInfo;/* '<Root>/MeTHA_e_RearBrkSupprInfo' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist;/* '<Root>/MeAP_cm_FrntCenterMinXDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist;/* '<Root>/MeAP_cm_FrntLeftMinXDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist;/* '<Root>/MeAP_cm_FrntRightMinXDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist;/* '<Root>/MeAP_cm_RearCenterMinXDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist;/* '<Root>/MeAP_cm_RearLeftMinXDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_RearRightMinXDist;/* '<Root>/MeAP_cm_RearRightMinXDist' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
extern const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
extern const uint8_T *SWC_APA_rtu_MeAP_b_IsWall;/* '<Root>/MeAP_b_IsWall' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_WallFrntCenterDist;/* '<Root>/MeAP_cm_WallFrntCenterDist' */
extern const int16_T *SWC_APA_rtu_MeAP_cm_WallRearCenterDist;/* '<Root>/MeAP_cm_WallRearCenterDist' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertCHF;/* '<Root>/MeAP_e_AlertCHF' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertLHF;/* '<Root>/MeAP_e_AlertLHF' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertRHF;/* '<Root>/MeAP_e_AlertRHF' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertCHR;/* '<Root>/MeAP_e_AlertCHR' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertLHR;/* '<Root>/MeAP_e_AlertLHR' */
extern TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertRHR;/* '<Root>/MeAP_e_AlertRHR' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicCHF;/* '<Root>/MeAP_e_GraphicCHF' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicLHF;/* '<Root>/MeAP_e_GraphicLHF' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicRHF;/* '<Root>/MeAP_e_GraphicRHF' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicCHR;/* '<Root>/MeAP_e_GraphicCHR' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicLHR;/* '<Root>/MeAP_e_GraphicLHR' */
extern TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicRHR;/* '<Root>/MeAP_e_GraphicRHR' */
extern TeAP_e_PAMLedCtrlStatus *SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus;
                                      /* '<Root>/MeAP_e_FrntPAMLedCtrlStatus' */
extern TeAP_e_PAMLedCtrlStatus *SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus;
                                      /* '<Root>/MeAP_e_RearPAMLedCtrlStatus' */
extern boolean_T *SWC_APA_rty_MeAP_b_PAMBrkReqStatus;/* '<Root>/MeAP_b_PAMBrkReqStatus' */
extern real32_T *SWC_APA_rty_MeAP_cm_RearDist;/* '<Root>/MeAP_cm_RearDist' */
extern boolean_T *SWC_APA_rty_MeAP_b_PAMStopCtrlStatus;/* '<Root>/MeAP_b_PAMStopCtrlStatus' */
extern boolean_T *SWC_APA_rty_MeAP_b_FPAStatus;/* '<Root>/MeAP_b_FPAStatus' */
extern boolean_T *SWC_APA_rty_MeAP_b_RPAStatus;/* '<Root>/MeAP_b_RPAStatus' */
extern TeAP_e_PAMSystemFault *SWC_APA_rty_IeAP_e_PAMSystemFault;/* '<Root>/IeAP_e_PAMSystemFault' */
extern TeAP_e_PAMOffStatus2BT *SWC_APA_rty_MeAP_e_PAMOffStatus2BT;/* '<Root>/MeAP_e_PAMOffStatus2BT' */
extern TeAP_e_FrntSnsrStatus *SWC_APA_rty_IeAP_e_FrntSnsrStatus;/* '<Root>/IeAP_e_FrntSnsrStatus' */
extern TeAP_e_RearSnsrStatus *SWC_APA_rty_IeAP_e_RearSnsrStatus;/* '<Root>/IeAP_e_RearSnsrStatus' */

/* Forward declaration for local functions */
static real_T SWC_APA_CheckHystDistZoneInc_k(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneDec_c(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneInc_b(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneDec_p(real_T ArcZone, real_T DistRaw);

/* Function for Chart: '<S484>/AlertFilterCHR' */
static real_T SWC_APA_CheckHystDistZoneInc_k(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  real_T tmp;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    if (SWC_APA_B.Switch6 < 32768.0F) {
      if (SWC_APA_B.Switch6 >= -32768.0F) {
        DistDiff = (int16_T)SWC_APA_B.Switch6;
      } else {
        DistDiff = MIN_int16_T;
      }
    } else {
      DistDiff = MAX_int16_T;
    }

    tmp = fabs(DistRaw - (real_T)DistDiff);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 2.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone2);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 3.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone6);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 10;
}

/* Function for Chart: '<S484>/AlertFilterCHR' */
static real_T SWC_APA_CheckHystDistZoneDec_c(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  real_T tmp;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    tmp = fabs(DistRaw);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 2.0) {
    if (SWC_APA_B.Switch6 < 32768.0F) {
      if (SWC_APA_B.Switch6 >= -32768.0F) {
        DistDiff = (int16_T)SWC_APA_B.Switch6;
      } else {
        DistDiff = MIN_int16_T;
      }
    } else {
      DistDiff = MAX_int16_T;
    }

    tmp = fabs(DistRaw - (real_T)DistDiff);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 3.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone2);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 5;
}

/* Function for Chart: '<S484>/AlertFilterLHR' */
static real_T SWC_APA_CheckHystDistZoneInc_b(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  real_T tmp;
  int32_T tmp_0;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    tmp_0 = KeAP_cm_DistZone1 - ((int16_T)CeAP_cm_SideArc1Adj);
    if (tmp_0 > 32767) {
      tmp_0 = 32767;
    } else {
      if (tmp_0 < -32768) {
        tmp_0 = -32768;
      }
    }

    tmp = fabs(DistRaw - (real_T)tmp_0);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 2.0) {
    tmp_0 = KeAP_cm_DistZone2 - ((int16_T)CeAP_cm_SideArc2Adj);
    if (tmp_0 > 32767) {
      tmp_0 = 32767;
    } else {
      if (tmp_0 < -32768) {
        tmp_0 = -32768;
      }
    }

    tmp = fabs(DistRaw - (real_T)tmp_0);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 3.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_DistZone6);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 10;
}

/* Function for Chart: '<S484>/AlertFilterLHR' */
static real_T SWC_APA_CheckHystDistZoneDec_p(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  int32_T tmp;
  real_T tmp_0;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    tmp_0 = fabs(DistRaw);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 2.0) {
    tmp = KeAP_cm_DistZone1 - ((int16_T)CeAP_cm_SideArc1Adj);
    if (tmp > 32767) {
      tmp = 32767;
    } else {
      if (tmp < -32768) {
        tmp = -32768;
      }
    }

    tmp_0 = fabs(DistRaw - (real_T)tmp);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 3.0) {
    tmp = KeAP_cm_DistZone2 - ((int16_T)CeAP_cm_SideArc2Adj);
    if (tmp > 32767) {
      tmp = 32767;
    } else {
      if (tmp < -32768) {
        tmp = -32768;
      }
    }

    tmp_0 = fabs(DistRaw - (real_T)tmp);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_DistZone3);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_DistZone4);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_DistZone5);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 5;
}

/* System initialize for atomic system: '<S6>/RPA' */
void SWC_APA_RPA_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S607>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_k = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S605>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_f = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S606>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_h5 = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S482>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_j = true;

  /* InitializeConditions for UnitDelay: '<S482>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_p = TeVBII_e_PamChimeVol_Medium;

  /* InitializeConditions for UnitDelay: '<S510>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_et = true;

  /* SystemInitialize for Enabled SubSystem: '<S56>/RPA_GraphicAlertGen' */
  /* SystemInitialize for Chart: '<S565>/DNNCheck' */
  SWC_APA_B.MeAP_e_AlertCHR_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertLHR_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertRHR_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_DW.IsDnnHeightLow_prev_m = SWC_APA_DW.IsDnnHeightLow_f;
  SWC_APA_DW.IsDnnHeightLow_start_f = SWC_APA_DW.IsDnnHeightLow_f;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_AlertCHR' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertCHR = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_GraphicCHR' */
  SWC_APA_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SNA;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_AlertLHR' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertLHR = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_GraphicLHR' */
  SWC_APA_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SNA;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_AlertRHR' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertRHR = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S483>/MeAP_e_GraphicRHR' */
  SWC_APA_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SNA;

  /* End of SystemInitialize for SubSystem: '<S56>/RPA_GraphicAlertGen' */

  /* SystemInitialize for Chart: '<S484>/AlertFilterCHR' */
  SWC_APA_DW.LastChanged_Alert_Raw_oq = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertCHR = TeAP_e_Alert_NoObjectDetected;

  /* SystemInitialize for Chart: '<S484>/AlertFilterLHR' */
  SWC_APA_DW.LastChanged_Alert_Raw_o = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertLHR = TeAP_e_Alert_NoObjectDetected;

  /* SystemInitialize for Chart: '<S484>/AlertFilterRHR' */
  SWC_APA_DW.LastChanged_Alert_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertRHR = TeAP_e_Alert_NoObjectDetected;

  /* SystemInitialize for Enabled SubSystem: '<S56>/RPA_ChimeAlertGen' */
  /* InitializeConditions for UnitDelay: '<S532>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_a = false;

  /* InitializeConditions for UnitDelay: '<S530>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_d = false;

  /* InitializeConditions for UnitDelay: '<S530>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_go = ((uint16_T)0U);

  /* InitializeConditions for UnitDelay: '<S531>/Unit Delay3' */
  SWC_APA_DW.UnitDelay3_DSTATE_h = false;

  /* InitializeConditions for UnitDelay: '<S552>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_mi = false;

  /* InitializeConditions for UnitDelay: '<S550>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_l = false;

  /* InitializeConditions for UnitDelay: '<S550>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_i = ((uint16_T)0U);

  /* InitializeConditions for UnitDelay: '<S551>/Unit Delay3' */
  SWC_APA_DW.UnitDelay3_DSTATE_o = false;

  /* End of SystemInitialize for SubSystem: '<S56>/RPA_ChimeAlertGen' */
}

/* Disable for atomic system: '<S6>/RPA' */
void SWC_APA_RPA_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S56>/RPA_GraphicAlertGen' */
  if (SWC_APA_DW.RPA_GraphicAlertGen_MODE) {
    /* Disable for Outport: '<S483>/MeAP_e_AlertCHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHR = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S483>/MeAP_e_GraphicCHR' */
    SWC_APA_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SNA;

    /* Disable for Outport: '<S483>/MeAP_e_AlertLHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHR = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S483>/MeAP_e_GraphicLHR' */
    SWC_APA_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SNA;

    /* Disable for Outport: '<S483>/MeAP_e_AlertRHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHR = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S483>/MeAP_e_GraphicRHR' */
    SWC_APA_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SNA;
    SWC_APA_DW.RPA_GraphicAlertGen_MODE = false;
  }

  /* End of Disable for SubSystem: '<S56>/RPA_GraphicAlertGen' */

  /* Disable for Enabled SubSystem: '<S56>/RPA_ChimeAlertGen' */
  if (SWC_APA_DW.RPA_ChimeAlertGen_MODE) {
    /* Disable for Outport: '<S481>/MeAP_b_ChimeActvLHR' */
    SWC_APA_B.MeAP_b_ChimeActvLHR_Raw = false;

    /* Disable for Outport: '<S481>/IeAP_b_ChimeActvRHR' */
    SWC_APA_B.MeAP_b_ChimeActvRHR_Raw = false;

    /* Disable for Outport: '<S481>/MeAP_e_LtRearChimeRepnRate' */
    SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;

    /* Disable for Outport: '<S481>/MeAP_e_RtRearChimeRepnRate' */
    SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    SWC_APA_DW.RPA_ChimeAlertGen_MODE = false;
  }

  /* End of Disable for SubSystem: '<S56>/RPA_ChimeAlertGen' */
}

/* Output and update for atomic system: '<S6>/RPA' */
void SWC_APA_RPA(void)
{
  int32_T tmp;
  boolean_T guard1 = false;

  /* Outputs for Enabled SubSystem: '<S56>/RPA_GraphicAlertGen' incorporates:
   *  EnablePort: '<S483>/Enable'
   */
  if (*SWC_APA_rty_MeAP_b_RPAStatus) {
    SWC_APA_DW.RPA_GraphicAlertGen_MODE = true;

    /* S-Function (sfix_bitop): '<S564>/Bitwise Operator' */
    SWC_APA_B.BitwiseOperator_k = (uint8_T)(*SWC_APA_rtu_MeAP_b_IsWall &
      ((uint8_T)2U));

    /* RelationalOperator: '<S582>/Relational Operator4' incorporates:
     *  Constant: '<S582>/Constant5'
     */
    SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <=
      100.0F);

    /* Logic: '<S582>/Logical Operator' */
    SWC_APA_B.LogicalOperator = ((SWC_APA_B.BitwiseOperator_k != 0) &&
      SWC_APA_B.RelationalOperator1_e1);

    /* Lookup_n-D: '<S582>/1-D Lookup Table' */
    SWC_APA_B.uDLookupTable = look1_iflftu16Df_binlcpw
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig,
       rtCP_uDLookupTable_bp01Data_o, rtCP_uDLookupTable_tableData_d, 5U);

    /* Outputs for Atomic SubSystem: '<S582>/Turn On Delay Time' */
    /* Logic: '<S584>/OR1' */
    SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.LogicalOperator;

    /* Outputs for Atomic SubSystem: '<S584>/EdgeRising1' */
    /* UnitDelay: '<S585>/Unit Delay' */
    SWC_APA_B.Compare_k = SWC_APA_DW.UnitDelay_DSTATE_i5;

    /* Logic: '<S585>/OR1' */
    SWC_APA_B.Compare_k = !SWC_APA_B.Compare_k;

    /* Logic: '<S585>/AND' */
    SWC_APA_B.AND_p = (SWC_APA_B.LogicalOperator && SWC_APA_B.Compare_k);

    /* Update for UnitDelay: '<S585>/Unit Delay' */
    SWC_APA_DW.UnitDelay_DSTATE_i5 = SWC_APA_B.LogicalOperator;

    /* End of Outputs for SubSystem: '<S584>/EdgeRising1' */

    /* Logic: '<S584>/OR' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
      SWC_APA_B.AND_p);

    /* UnitDelay: '<S584>/Unit Delay' */
    SWC_APA_B.UnitDelay_pz = SWC_APA_B.Switch1_lb;

    /* Switch: '<S584>/Switch1' incorporates:
     *  Constant: '<S584>/Constant Value1'
     */
    if (SWC_APA_B.RelationalOperator2_j) {
      SWC_APA_B.Switch1_lb = ((uint16_T)0U);
    } else {
      /* Sum: '<S584>/Summation' incorporates:
       *  Constant: '<S582>/Constant4'
       */
      SWC_APA_B.Summation_l = (uint16_T)((uint32_T)((uint16_T)30U) +
        SWC_APA_B.UnitDelay_pz);

      /* MinMax: '<S584>/Minimum' */
      if (SWC_APA_B.uDLookupTable < SWC_APA_B.Summation_l) {
        SWC_APA_B.Minimum_c = SWC_APA_B.uDLookupTable;
      } else {
        SWC_APA_B.Minimum_c = SWC_APA_B.Summation_l;
      }

      /* End of MinMax: '<S584>/Minimum' */
      SWC_APA_B.Switch1_lb = SWC_APA_B.Minimum_c;
    }

    /* End of Switch: '<S584>/Switch1' */

    /* RelationalOperator: '<S584>/Greater  Than' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.Switch1_lb >=
      SWC_APA_B.uDLookupTable);

    /* Logic: '<S584>/AND' */
    SWC_APA_B.AND_c = (SWC_APA_B.LogicalOperator &&
                       SWC_APA_B.RelationalOperator2_j);

    /* End of Outputs for SubSystem: '<S582>/Turn On Delay Time' */

    /* UnitDelay: '<S583>/Unit Delay' */
    SWC_APA_B.UnitDelay_e0 = SWC_APA_DW.UnitDelay_DSTATE_m0;

    /* Logic: '<S582>/Logical Operator1' */
    SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

    /* Switch: '<S583>/Switch5' incorporates:
     *  Constant: '<S583>/Constant'
     *  Switch: '<S583>/Switch6'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.Switch5_a = false;
    } else {
      if (SWC_APA_B.AND_c) {
        /* Switch: '<S583>/Switch6' incorporates:
         *  Constant: '<S583>/Constant1'
         */
        SWC_APA_B.Switch6_g = true;
      } else {
        /* Switch: '<S583>/Switch6' */
        SWC_APA_B.Switch6_g = SWC_APA_B.UnitDelay_e0;
      }

      SWC_APA_B.Switch5_a = SWC_APA_B.Switch6_g;
    }

    /* End of Switch: '<S583>/Switch5' */

    /* Logic: '<S564>/Logical Operator' incorporates:
     *  Constant: '<S564>/Constant5'
     */
    SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch5_a &&
      KeAP_b_EnWallAcurracy);

    /* Switch: '<S564>/Switch7' incorporates:
     *  Switch: '<S564>/Switch6'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.Switch7 = *SWC_APA_rtu_MeAP_cm_WallRearCenterDist;

      /* Sum: '<S564>/Subtract' incorporates:
       *  Constant: '<S564>/Constant14'
       */
      SWC_APA_B.Subtract_h = (real32_T)
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1 -
        KeAP_cm_RearWallZone1Adj;
      SWC_APA_B.Switch6 = SWC_APA_B.Subtract_h;
    } else {
      SWC_APA_B.Switch7 = *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist;
      SWC_APA_B.Switch6 = *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1;
    }

    /* End of Switch: '<S564>/Switch7' */

    /* RelationalOperator: '<S564>/Relational Operator' */
    SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch7 <= SWC_APA_B.Switch6);

    /* RelationalOperator: '<S564>/Relational Operator1' */
    SWC_APA_B.RelationalOperator1_m = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <=
      *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2);

    /* RelationalOperator: '<S564>/Relational Operator2' */
    SWC_APA_B.RelationalOperator2 = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3);

    /* RelationalOperator: '<S564>/Relational Operator3' */
    SWC_APA_B.RelationalOperator3 = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4);

    /* RelationalOperator: '<S564>/Relational Operator4' */
    SWC_APA_B.RelationalOperator4 = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5);

    /* RelationalOperator: '<S564>/Relational Operator5' */
    SWC_APA_B.RelationalOperator5 = (*SWC_APA_rtu_MeAP_cm_RearCenterMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6);

    /* Switch generated from: '<S564>/Switch' incorporates:
     *  Constant: '<S578>/Constant'
     *  Switch generated from: '<S564>/Switch1'
     *  Switch generated from: '<S564>/Switch2'
     *  Switch generated from: '<S564>/Switch3'
     *  Switch generated from: '<S564>/Switch4'
     *  Switch generated from: '<S564>/Switch5'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.MeAP_e_AlertCHR_p = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_m) {
        /* Switch generated from: '<S564>/Switch1' incorporates:
         *  Constant: '<S568>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertCHR_o = TeAP_e_Alert_Arc2;
      } else {
        if (SWC_APA_B.RelationalOperator2) {
          /* Switch generated from: '<S564>/Switch2' incorporates:
           *  Constant: '<S575>/Constant'
           *  Switch generated from: '<S564>/Switch1'
           */
          SWC_APA_B.MeAP_e_AlertCHR_l = TeAP_e_Alert_Arc3;
        } else {
          if (SWC_APA_B.RelationalOperator3) {
            /* Switch generated from: '<S564>/Switch3' incorporates:
             *  Constant: '<S577>/Constant'
             *  Switch generated from: '<S564>/Switch1'
             *  Switch generated from: '<S564>/Switch2'
             */
            SWC_APA_B.MeAP_e_AlertCHR_d = TeAP_e_Alert_Arc4;
          } else {
            if (SWC_APA_B.RelationalOperator4) {
              /* Switch generated from: '<S564>/Switch4' incorporates:
               *  Constant: '<S570>/Constant'
               *  Switch generated from: '<S564>/Switch1'
               *  Switch generated from: '<S564>/Switch2'
               *  Switch generated from: '<S564>/Switch3'
               */
              SWC_APA_B.MeAP_e_AlertCHR_j = TeAP_e_Alert_Arc5;
            } else {
              if (SWC_APA_B.RelationalOperator5) {
                /* Switch generated from: '<S564>/Switch5' incorporates:
                 *  Constant: '<S572>/Constant'
                 *  Switch generated from: '<S564>/Switch1'
                 *  Switch generated from: '<S564>/Switch2'
                 *  Switch generated from: '<S564>/Switch3'
                 *  Switch generated from: '<S564>/Switch4'
                 */
                SWC_APA_B.MeAP_e_AlertCHR_a = TeAP_e_Alert_Arc6;
              } else {
                /* Switch generated from: '<S564>/Switch5' incorporates:
                 *  Constant: '<S581>/Constant'
                 *  Switch generated from: '<S564>/Switch1'
                 *  Switch generated from: '<S564>/Switch2'
                 *  Switch generated from: '<S564>/Switch3'
                 *  Switch generated from: '<S564>/Switch4'
                 */
                SWC_APA_B.MeAP_e_AlertCHR_a = TeAP_e_Alert_NoObjectDetected;
              }

              /* Switch generated from: '<S564>/Switch4' incorporates:
               *  Switch generated from: '<S564>/Switch1'
               *  Switch generated from: '<S564>/Switch2'
               *  Switch generated from: '<S564>/Switch3'
               */
              SWC_APA_B.MeAP_e_AlertCHR_j = SWC_APA_B.MeAP_e_AlertCHR_a;
            }

            /* Switch generated from: '<S564>/Switch3' incorporates:
             *  Switch generated from: '<S564>/Switch1'
             *  Switch generated from: '<S564>/Switch2'
             *  Switch generated from: '<S564>/Switch4'
             *  Switch generated from: '<S564>/Switch5'
             */
            SWC_APA_B.MeAP_e_AlertCHR_d = SWC_APA_B.MeAP_e_AlertCHR_j;
          }

          /* Switch generated from: '<S564>/Switch2' incorporates:
           *  Switch generated from: '<S564>/Switch1'
           *  Switch generated from: '<S564>/Switch3'
           *  Switch generated from: '<S564>/Switch4'
           *  Switch generated from: '<S564>/Switch5'
           */
          SWC_APA_B.MeAP_e_AlertCHR_l = SWC_APA_B.MeAP_e_AlertCHR_d;
        }

        /* Switch generated from: '<S564>/Switch1' incorporates:
         *  Switch generated from: '<S564>/Switch2'
         *  Switch generated from: '<S564>/Switch3'
         *  Switch generated from: '<S564>/Switch4'
         *  Switch generated from: '<S564>/Switch5'
         */
        SWC_APA_B.MeAP_e_AlertCHR_o = SWC_APA_B.MeAP_e_AlertCHR_l;
      }

      SWC_APA_B.MeAP_e_AlertCHR_p = SWC_APA_B.MeAP_e_AlertCHR_o;
    }

    /* RelationalOperator: '<S566>/Relational Operator' */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rtu_MeAP_cm_RearLeftMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1);

    /* RelationalOperator: '<S566>/Relational Operator1' */
    SWC_APA_B.RelationalOperator1_f = (*SWC_APA_rtu_MeAP_cm_RearLeftMinXDist <= *
      SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2);

    /* Switch generated from: '<S566>/Switch' incorporates:
     *  Constant: '<S590>/Constant'
     *  Switch generated from: '<S566>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator2_j) {
      SWC_APA_B.MeAP_e_AlertLHR_o = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_f) {
        /* Switch generated from: '<S566>/Switch1' incorporates:
         *  Constant: '<S587>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertLHR_l = TeAP_e_Alert_Arc2;
      } else {
        /* Switch generated from: '<S566>/Switch1' incorporates:
         *  Constant: '<S592>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertLHR_l = TeAP_e_Alert_NoObjectDetected;
      }

      SWC_APA_B.MeAP_e_AlertLHR_o = SWC_APA_B.MeAP_e_AlertLHR_l;
    }

    /* RelationalOperator: '<S567>/Relational Operator' */
    SWC_APA_B.Compare_k = (*SWC_APA_rtu_MeAP_cm_RearRightMinXDist <=
      *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1);

    /* RelationalOperator: '<S567>/Relational Operator1' */
    SWC_APA_B.RelationalOperator1_j = (*SWC_APA_rtu_MeAP_cm_RearRightMinXDist <=
      *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2);

    /* Switch generated from: '<S567>/Switch' incorporates:
     *  Constant: '<S596>/Constant'
     *  Switch generated from: '<S567>/Switch1'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.MeAP_e_AlertRHR_h = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_j) {
        /* Switch generated from: '<S567>/Switch1' incorporates:
         *  Constant: '<S593>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertRHR_hd = TeAP_e_Alert_Arc2;
      } else {
        /* Switch generated from: '<S567>/Switch1' incorporates:
         *  Constant: '<S598>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertRHR_hd = TeAP_e_Alert_NoObjectDetected;
      }

      SWC_APA_B.MeAP_e_AlertRHR_h = SWC_APA_B.MeAP_e_AlertRHR_hd;
    }

    /* Chart: '<S565>/DNNCheck' */
    SWC_APA_DW.IsDnnHeightLow_prev_m = SWC_APA_DW.IsDnnHeightLow_start_f;
    SWC_APA_DW.IsDnnHeightLow_start_f = SWC_APA_DW.IsDnnHeightLow_f;
    SWC_APA_DW.MeAP_b_HighPointsPresentRear_prev =
      SWC_APA_DW.MeAP_b_HighPointsPresentRear_start;
    SWC_APA_DW.MeAP_b_HighPointsPresentRear_start =
      *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear;
    if (!SWC_APA_DW.doneDoubleBufferReInit) {
      SWC_APA_DW.doneDoubleBufferReInit = true;
      SWC_APA_DW.MeAP_b_HighPointsPresentRear_prev =
        *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear;
    }
    //Keep++
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertCHR_p,3);
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertLHR_o,4);
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertRHR_h,5); 
	  //Keep--
    SWC_APA_B.MeAP_e_AlertCHR_Raw = SWC_APA_B.MeAP_e_AlertCHR_p;
    SWC_APA_B.MeAP_e_AlertLHR_Raw = SWC_APA_B.MeAP_e_AlertLHR_o;
    SWC_APA_B.MeAP_e_AlertRHR_Raw = SWC_APA_B.MeAP_e_AlertRHR_h;
    SWC_APA_DW.IsDnnHeightLow_f = UssOD_bIsLowObject(US_D_PHYS_GRP_REAR);//Keep

    /* UssOD_bIsLowObject(US_D_PHYS_GRP_REAR) */
    if (((SWC_APA_DW.IsDnnHeightLow_prev_m != SWC_APA_DW.IsDnnHeightLow_start_f)
         && SWC_APA_DW.IsDnnHeightLow_start_f) ||
        ((SWC_APA_DW.MeAP_b_HighPointsPresentRear_prev !=
          SWC_APA_DW.MeAP_b_HighPointsPresentRear_start) &&
         (SWC_APA_DW.MeAP_b_HighPointsPresentRear_start == 0))) {
      SWC_APA_DW.prev_AlertCHR = (uint32_T)SWC_APA_B.MeAP_e_AlertCHR_p;
      SWC_APA_DW.DNN_Latch = true;
    }

    /*   */
    SWC_APA_DW.DNN_Latch = (((!SWC_APA_DW.DNN_Latch) ||
      ((SWC_APA_DW.prev_AlertCHR - (uint32_T)SWC_APA_B.MeAP_e_AlertCHR_p < 2U) &&
       SWC_APA_DW.IsDnnHeightLow_f &&
       (*SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear
        != 1))) && SWC_APA_DW.DNN_Latch);
    if (SWC_APA_DW.IsDnnHeightLow_f && (!SWC_APA_DW.DNN_Latch) &&
        (*SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear ==
         0)) {
      /* Ignore DNN Flag for center */
      SWC_APA_B.MeAP_e_AlertCHR_Raw = TeAP_e_Alert_NoObjectDetected;
    }

    if (SWC_APA_DW.IsDnnHeightLow_f) {
      if ((KePA_b_EnHeightFlagRearSideArcs != 0) &&
          (*SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL ==
           0)) {
        SWC_APA_B.MeAP_e_AlertLHR_Raw = TeAP_e_Alert_NoObjectDetected;
      }

      if ((KePA_b_EnHeightFlagRearSideArcs != 0) &&
          (*SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR ==
           0)) {
        SWC_APA_B.MeAP_e_AlertRHR_Raw = TeAP_e_Alert_NoObjectDetected;
      }
    }

    /* End of Chart: '<S565>/DNNCheck' */

    /* SignalConversion generated from: '<S483>/MeAP_e_AlertCHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHR = SWC_APA_B.MeAP_e_AlertCHR_Raw;

    /* SignalConversion generated from: '<S483>/MeAP_e_AlertLHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHR = SWC_APA_B.MeAP_e_AlertLHR_Raw;

    /* SignalConversion generated from: '<S483>/MeAP_e_AlertRHR' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHR = SWC_APA_B.MeAP_e_AlertRHR_Raw;

    /* Switch generated from: '<S567>/Switch' incorporates:
     *  Constant: '<S597>/Constant'
     *  Switch generated from: '<S567>/Switch1'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_j) {
        /* Switch generated from: '<S567>/Switch1' incorporates:
         *  Constant: '<S595>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicRHR_b = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        /* Switch generated from: '<S567>/Switch1' incorporates:
         *  Constant: '<S594>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicRHR_b = TeAP_e_GraphicFlshRate_None;
      }

      SWC_APA_B.MeAP_e_GraphicRHR = SWC_APA_B.MeAP_e_GraphicRHR_b;
    }

    /* Switch generated from: '<S566>/Switch' incorporates:
     *  Constant: '<S591>/Constant'
     *  Switch generated from: '<S566>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator2_j) {
      SWC_APA_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_f) {
        /* Switch generated from: '<S566>/Switch1' incorporates:
         *  Constant: '<S589>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicLHR_i = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        /* Switch generated from: '<S566>/Switch1' incorporates:
         *  Constant: '<S588>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicLHR_i = TeAP_e_GraphicFlshRate_None;
      }

      SWC_APA_B.MeAP_e_GraphicLHR = SWC_APA_B.MeAP_e_GraphicLHR_i;
    }

    /* Switch generated from: '<S564>/Switch' incorporates:
     *  Constant: '<S579>/Constant'
     *  Switch generated from: '<S564>/Switch1'
     *  Switch generated from: '<S564>/Switch2'
     *  Switch generated from: '<S564>/Switch3'
     *  Switch generated from: '<S564>/Switch4'
     *  Switch generated from: '<S564>/Switch5'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_m) {
        /* Switch generated from: '<S564>/Switch1' incorporates:
         *  Constant: '<S574>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicCHR_h = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        if (SWC_APA_B.RelationalOperator2) {
          /* Switch generated from: '<S564>/Switch2' incorporates:
           *  Constant: '<S576>/Constant'
           *  Switch generated from: '<S564>/Switch1'
           */
          SWC_APA_B.MeAP_e_GraphicCHR_j = TeAP_e_GraphicFlshRate_SlowFlash;
        } else {
          if (SWC_APA_B.RelationalOperator3) {
            /* Switch generated from: '<S564>/Switch3' incorporates:
             *  Constant: '<S580>/Constant'
             *  Switch generated from: '<S564>/Switch1'
             *  Switch generated from: '<S564>/Switch2'
             */
            SWC_APA_B.MeAP_e_GraphicCHR_f = TeAP_e_GraphicFlshRate_Solid;
          } else {
            if (SWC_APA_B.RelationalOperator4) {
              /* Switch generated from: '<S564>/Switch4' incorporates:
               *  Constant: '<S571>/Constant'
               *  Switch generated from: '<S564>/Switch1'
               *  Switch generated from: '<S564>/Switch2'
               *  Switch generated from: '<S564>/Switch3'
               */
              SWC_APA_B.MeAP_e_GraphicCHR_p = TeAP_e_GraphicFlshRate_Solid;
            } else {
              if (SWC_APA_B.RelationalOperator5) {
                /* Switch generated from: '<S564>/Switch5' incorporates:
                 *  Constant: '<S573>/Constant'
                 *  Switch generated from: '<S564>/Switch1'
                 *  Switch generated from: '<S564>/Switch2'
                 *  Switch generated from: '<S564>/Switch3'
                 *  Switch generated from: '<S564>/Switch4'
                 */
                SWC_APA_B.MeAP_e_GraphicCHR_l = TeAP_e_GraphicFlshRate_Solid;
              } else {
                /* Switch generated from: '<S564>/Switch5' incorporates:
                 *  Constant: '<S569>/Constant'
                 *  Switch generated from: '<S564>/Switch1'
                 *  Switch generated from: '<S564>/Switch2'
                 *  Switch generated from: '<S564>/Switch3'
                 *  Switch generated from: '<S564>/Switch4'
                 */
                SWC_APA_B.MeAP_e_GraphicCHR_l = TeAP_e_GraphicFlshRate_None;
              }

              /* Switch generated from: '<S564>/Switch4' incorporates:
               *  Switch generated from: '<S564>/Switch1'
               *  Switch generated from: '<S564>/Switch2'
               *  Switch generated from: '<S564>/Switch3'
               */
              SWC_APA_B.MeAP_e_GraphicCHR_p = SWC_APA_B.MeAP_e_GraphicCHR_l;
            }

            /* Switch generated from: '<S564>/Switch3' incorporates:
             *  Switch generated from: '<S564>/Switch1'
             *  Switch generated from: '<S564>/Switch2'
             *  Switch generated from: '<S564>/Switch4'
             *  Switch generated from: '<S564>/Switch5'
             */
            SWC_APA_B.MeAP_e_GraphicCHR_f = SWC_APA_B.MeAP_e_GraphicCHR_p;
          }

          /* Switch generated from: '<S564>/Switch2' incorporates:
           *  Switch generated from: '<S564>/Switch1'
           *  Switch generated from: '<S564>/Switch3'
           *  Switch generated from: '<S564>/Switch4'
           *  Switch generated from: '<S564>/Switch5'
           */
          SWC_APA_B.MeAP_e_GraphicCHR_j = SWC_APA_B.MeAP_e_GraphicCHR_f;
        }

        /* Switch generated from: '<S564>/Switch1' incorporates:
         *  Switch generated from: '<S564>/Switch2'
         *  Switch generated from: '<S564>/Switch3'
         *  Switch generated from: '<S564>/Switch4'
         *  Switch generated from: '<S564>/Switch5'
         */
        SWC_APA_B.MeAP_e_GraphicCHR_h = SWC_APA_B.MeAP_e_GraphicCHR_j;
      }

      SWC_APA_B.MeAP_e_GraphicCHR = SWC_APA_B.MeAP_e_GraphicCHR_h;
    }

    /* Update for UnitDelay: '<S583>/Unit Delay' */
    SWC_APA_DW.UnitDelay_DSTATE_m0 = SWC_APA_B.Switch5_a;
  } else {
    if (SWC_APA_DW.RPA_GraphicAlertGen_MODE) {
      /* Disable for Outport: '<S483>/MeAP_e_AlertCHR' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertCHR = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S483>/MeAP_e_GraphicCHR' */
      SWC_APA_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SNA;

      /* Disable for Outport: '<S483>/MeAP_e_AlertLHR' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertLHR = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S483>/MeAP_e_GraphicLHR' */
      SWC_APA_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SNA;

      /* Disable for Outport: '<S483>/MeAP_e_AlertRHR' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertRHR = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S483>/MeAP_e_GraphicRHR' */
      SWC_APA_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SNA;
      SWC_APA_DW.RPA_GraphicAlertGen_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S56>/RPA_GraphicAlertGen' */

  /* Chart: '<S484>/AlertFilterCHR' */
  SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev = SWC_APA_DW.MeAP_e_AlertCHR_Raw_start;
  SWC_APA_DW.MeAP_e_AlertCHR_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
  if (SWC_APA_DW.is_active_c11_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
    SWC_APA_DW.is_active_c11_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw_oq = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c11_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
    SWC_APA_B.MeAP_e_AlertCHR = SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
  } else if (SWC_APA_DW.is_c11_SWC_APA == SWC_APA_IN_HOLD_OUTPUT_o) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertCHR_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR !=
                SWC_APA_DW.LastChanged_Alert_Raw_oq) &&
               (SWC_APA_DW.LastChanged_Alert_Raw_oq !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c11_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
      SWC_APA_DW.LastChanged_Alert_Raw_oq =
        SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
      SWC_APA_DW.count_of = 0U;
    } else if ((SWC_APA_DW.count_of >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertCHR !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw_oq ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertCHR != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertCHR != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count_of >= 5)
                && (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
                    1.0F))) {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count_of + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count_of = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c11_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertCHR = SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR > SWC_APA_B.MeAP_e_AlertCHR)
         && (SWC_APA_CheckHystDistZoneInc_k((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertCHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertCHR < SWC_APA_B.MeAP_e_AlertCHR)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec_c
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertCHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHR_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c11_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertCHR = SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR >
            SWC_APA_B.MeAP_e_AlertCHR) && (SWC_APA_CheckHystDistZoneInc_k
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertCHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertCHR_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertCHR_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertCHR_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertCHR_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertCHR != TeAP_e_Alert_Arc6)) ||
          ((SWC_APA_B.MeAP_e_AlertCHR == TeAP_e_Alert_Arc6) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertCHR ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc_k
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertCHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist) != 0.0))) {
        SWC_APA_DW.is_c11_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
        SWC_APA_DW.LastChanged_Alert_Raw_oq =
          SWC_APA_B.OutportBufferForMeAP_e_AlertCHR;
        SWC_APA_DW.count_of = 0U;
      }
    }
  }

  /* End of Chart: '<S484>/AlertFilterCHR' */

  /* Chart: '<S484>/AlertFilterLHR' */
  SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev = SWC_APA_DW.MeAP_e_AlertLHR_Raw_start;
  SWC_APA_DW.MeAP_e_AlertLHR_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
  if (SWC_APA_DW.is_active_c12_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
    SWC_APA_DW.is_active_c12_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw_o = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c12_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
    SWC_APA_B.MeAP_e_AlertLHR = SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
  } else if (SWC_APA_DW.is_c12_SWC_APA == SWC_APA_IN_HOLD_OUTPUT_o) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertLHR_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR !=
                SWC_APA_DW.LastChanged_Alert_Raw_o) &&
               (SWC_APA_DW.LastChanged_Alert_Raw_o !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c12_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
      SWC_APA_DW.LastChanged_Alert_Raw_o =
        SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
      SWC_APA_DW.count_o = 0U;
    } else if ((SWC_APA_DW.count_o >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertLHR !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw_o ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertLHR != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertLHR != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count_o >= 5)
                && (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
                    1.0F))) {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count_o + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count_o = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c12_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertLHR = SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR > SWC_APA_B.MeAP_e_AlertLHR)
         && (SWC_APA_CheckHystDistZoneInc_b((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertLHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertLHR < SWC_APA_B.MeAP_e_AlertLHR)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec_p
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHR_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c12_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertLHR = SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR >
            SWC_APA_B.MeAP_e_AlertLHR) && (SWC_APA_CheckHystDistZoneInc_b
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertLHR_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertLHR_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertLHR_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertLHR_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertLHR != TeAP_e_Alert_Arc2)) ||
          ((SWC_APA_B.MeAP_e_AlertLHR == TeAP_e_Alert_Arc2) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertLHR ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc_b
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist) != 0.0))) {
        SWC_APA_DW.is_c12_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
        SWC_APA_DW.LastChanged_Alert_Raw_o =
          SWC_APA_B.OutportBufferForMeAP_e_AlertLHR;
        SWC_APA_DW.count_o = 0U;
      }
    }
  }

  /* End of Chart: '<S484>/AlertFilterLHR' */

  /* Chart: '<S484>/AlertFilterRHR' */
  SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev = SWC_APA_DW.MeAP_e_AlertRHR_Raw_start;
  SWC_APA_DW.MeAP_e_AlertRHR_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
  if (SWC_APA_DW.is_active_c13_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
    SWC_APA_DW.is_active_c13_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c13_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
    SWC_APA_B.MeAP_e_AlertRHR = SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
  } else if (SWC_APA_DW.is_c13_SWC_APA == SWC_APA_IN_HOLD_OUTPUT_o) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertRHR_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR !=
                SWC_APA_DW.LastChanged_Alert_Raw) &&
               (SWC_APA_DW.LastChanged_Alert_Raw !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c13_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
      SWC_APA_DW.LastChanged_Alert_Raw =
        SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
      SWC_APA_DW.count = 0U;
    } else if ((SWC_APA_DW.count >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertRHR !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertRHR != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertRHR != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count >= 5) &&
                (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F)))
    {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c13_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertRHR = SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR > SWC_APA_B.MeAP_e_AlertRHR)
         && (SWC_APA_CheckHystDistZoneInc_b((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertRHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearRightMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertRHR < SWC_APA_B.MeAP_e_AlertRHR)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec_p
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHR, (real_T)
           *SWC_APA_rtu_MeAP_cm_RearRightMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHR_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c13_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT_j;
      SWC_APA_B.MeAP_e_AlertRHR = SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR >
            SWC_APA_B.MeAP_e_AlertRHR) && (SWC_APA_CheckHystDistZoneInc_b
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearRightMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertRHR_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertRHR_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertRHR_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertRHR_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertRHR != TeAP_e_Alert_Arc2)) ||
          ((SWC_APA_B.MeAP_e_AlertRHR == TeAP_e_Alert_Arc2) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertRHR ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc_b
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHR, (real_T)
             *SWC_APA_rtu_MeAP_cm_RearRightMinXDist) != 0.0))) {
        SWC_APA_DW.is_c13_SWC_APA = SWC_APA_IN_HOLD_OUTPUT_o;
        SWC_APA_DW.LastChanged_Alert_Raw =
          SWC_APA_B.OutportBufferForMeAP_e_AlertRHR;
        SWC_APA_DW.count = 0U;
      }
    }
  }

  /* End of Chart: '<S484>/AlertFilterRHR' */

  /* UnitDelay: '<S607>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_k;

  /* UnitDelay: '<S607>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_B.Switch5_n;

  /* Switch: '<S607>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.timerValue = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S607>/Relational Operator1' incorporates:
     *  Constant: '<S607>/Constant'
     */
    SWC_APA_B.RelationalOperator1_mw =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S607>/Relational Operator5' incorporates:
     *  Constant: '<S644>/Constant'
     */
    SWC_APA_B.RelationalOperator5_b =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S607>/Relational Operator4' incorporates:
     *  Constant: '<S643>/Constant'
     */
    SWC_APA_B.LogicalOperator_i =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S607>/Logical Operator' */
    SWC_APA_B.LogicalOperator_i = (SWC_APA_B.LogicalOperator_i &&
      SWC_APA_B.RelationalOperator5_b && SWC_APA_B.RelationalOperator1_mw);

    /* Switch: '<S607>/Switch3' incorporates:
     *  Constant: '<S607>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_i) {
      SWC_APA_B.timerValue_e = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S607>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S607>/Constant5'
       *  Constant: '<S607>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S607>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.timerValue_e = SWC_APA_B.LookupTableDynamic;
    }

    /* End of Switch: '<S607>/Switch3' */
    SWC_APA_B.timerValue = SWC_APA_B.timerValue_e;
  }

  /* End of Switch: '<S607>/Switch4' */

  /* RelationalOperator: '<S607>/Relational Operator' incorporates:
   *  Constant: '<S640>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.MeAP_e_AlertRHR ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S607>/Relational Operator2' incorporates:
   *  Constant: '<S641>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.MeAP_e_AlertRHR ==
    TeAP_e_Alert_SNA);

  /* Logic: '<S607>/Logical Operator1' */
  SWC_APA_B.arcJump = (SWC_APA_B.RelationalOperator1_e1 ||
                       SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S607>/Unit Delay' */
  SWC_APA_B.UnitDelay_a = SWC_APA_DW.UnitDelay_DSTATE_ej;

  /* UnitDelay: '<S647>/Unit Delay' */
  SWC_APA_B.UnitDelay_j = SWC_APA_DW.UnitDelay_DSTATE_go;

  /* Switch: '<S647>/Switch5' incorporates:
   *  Constant: '<S647>/Constant'
   */
  if (SWC_APA_B.arcJump) {
    SWC_APA_B.Switch5_n = false;
  } else {
    /* Logic: '<S607>/OR1' */
    SWC_APA_B.AND_ne = !SWC_APA_B.arcJump;

    /* Logic: '<S607>/AND' */
    SWC_APA_B.AND_ne = (SWC_APA_B.UnitDelay_a && SWC_APA_B.AND_ne);

    /* Switch: '<S647>/Switch6' incorporates:
     *  Constant: '<S647>/Constant1'
     */
    if (SWC_APA_B.AND_ne) {
      SWC_APA_B.Switch6_k = true;
    } else {
      SWC_APA_B.Switch6_k = SWC_APA_B.UnitDelay_j;
    }

    /* End of Switch: '<S647>/Switch6' */
    SWC_APA_B.Switch5_n = SWC_APA_B.Switch6_k;
  }

  /* End of Switch: '<S647>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S607>/Turn On Delay Time' */
  /* Logic: '<S648>/OR1' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.Switch5_n;

  /* Outputs for Atomic SubSystem: '<S648>/EdgeRising1' */
  /* UnitDelay: '<S649>/Unit Delay' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay_DSTATE_mt;

  /* Logic: '<S649>/OR1' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S649>/AND' */
  SWC_APA_B.AND_k = (SWC_APA_B.Switch5_n && SWC_APA_B.RelationalOperator2_j);

  /* Update for UnitDelay: '<S649>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_mt = SWC_APA_B.Switch5_n;

  /* End of Outputs for SubSystem: '<S648>/EdgeRising1' */

  /* Logic: '<S648>/OR' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.AND_k);

  /* UnitDelay: '<S648>/Unit Delay' */
  SWC_APA_B.UnitDelay_d = SWC_APA_B.Switch1_ii;

  /* Switch: '<S648>/Switch1' incorporates:
   *  Constant: '<S648>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.Switch1_ii = ((uint16_T)0U);
  } else {
    /* Sum: '<S648>/Summation' incorporates:
     *  Constant: '<S607>/Constant4'
     */
    SWC_APA_B.Summation = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_d);

    /* MinMax: '<S648>/Minimum' */
    if (SWC_APA_B.timerValue < SWC_APA_B.Summation) {
      SWC_APA_B.Minimum = SWC_APA_B.timerValue;
    } else {
      SWC_APA_B.Minimum = SWC_APA_B.Summation;
    }

    /* End of MinMax: '<S648>/Minimum' */
    SWC_APA_B.Switch1_ii = SWC_APA_B.Minimum;
  }

  /* End of Switch: '<S648>/Switch1' */

  /* RelationalOperator: '<S648>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch1_ii >=
    SWC_APA_B.timerValue);

  /* Logic: '<S648>/AND' */
  SWC_APA_B.AND = (SWC_APA_B.Switch5_n && SWC_APA_B.RelationalOperator1_e1);

  /* End of Outputs for SubSystem: '<S607>/Turn On Delay Time' */

  /* Switch: '<S607>/Switch' incorporates:
   *  Constant: '<S607>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S607>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_b = !SWC_APA_B.Switch5_n;

    /* Logic: '<S607>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_b = (SWC_APA_B.AND ||
      SWC_APA_B.LogicalOperator2_b);

    /* Switch: '<S607>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_b) {
      SWC_APA_B.Switch1_g = SWC_APA_B.MeAP_e_AlertRHR;
    } else {
      /* RelationalOperator: '<S607>/Relational Operator3' incorporates:
       *  Constant: '<S642>/Constant'
       */
      SWC_APA_B.RelationalOperator3_h = (SWC_APA_B.MeAP_e_AlertRHR !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S607>/Switch2' incorporates:
       *  Constant: '<S645>/Constant'
       *  Constant: '<S646>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_h) {
        SWC_APA_B.Switch2_i = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_i = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S607>/Switch2' */
      SWC_APA_B.Switch1_g = SWC_APA_B.Switch2_i;
    }

    /* End of Switch: '<S607>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertRHR = SWC_APA_B.Switch1_g;
  } else {
    *SWC_APA_rty_MeAP_e_AlertRHR = SWC_APA_B.MeAP_e_AlertRHR;
  }

  /* End of Switch: '<S607>/Switch' */

  /* UnitDelay: '<S605>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_f;

  /* UnitDelay: '<S605>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_B.Switch5_l;

  /* Switch: '<S605>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.timerValue_k = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S605>/Relational Operator1' incorporates:
     *  Constant: '<S605>/Constant'
     */
    SWC_APA_B.RelationalOperator1_e =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S605>/Relational Operator5' incorporates:
     *  Constant: '<S624>/Constant'
     */
    SWC_APA_B.RelationalOperator5_f =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S605>/Relational Operator4' incorporates:
     *  Constant: '<S623>/Constant'
     */
    SWC_APA_B.LogicalOperator_d =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S605>/Logical Operator' */
    SWC_APA_B.LogicalOperator_d = (SWC_APA_B.LogicalOperator_d &&
      SWC_APA_B.RelationalOperator5_f && SWC_APA_B.RelationalOperator1_e);

    /* Switch: '<S605>/Switch3' incorporates:
     *  Constant: '<S605>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_d) {
      SWC_APA_B.timerValue_gk = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S605>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S605>/Constant5'
       *  Constant: '<S605>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S605>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic_j),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.timerValue_gk = SWC_APA_B.LookupTableDynamic_j;
    }

    /* End of Switch: '<S605>/Switch3' */
    SWC_APA_B.timerValue_k = SWC_APA_B.timerValue_gk;
  }

  /* End of Switch: '<S605>/Switch4' */

  /* RelationalOperator: '<S605>/Relational Operator' incorporates:
   *  Constant: '<S620>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.MeAP_e_AlertCHR ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S605>/Relational Operator2' incorporates:
   *  Constant: '<S621>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.MeAP_e_AlertCHR ==
    TeAP_e_Alert_SNA);

  /* Logic: '<S605>/Logical Operator1' */
  SWC_APA_B.arcJump_i = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S605>/Unit Delay' */
  SWC_APA_B.UnitDelay_ef = SWC_APA_DW.UnitDelay_DSTATE_c;

  /* UnitDelay: '<S627>/Unit Delay' */
  SWC_APA_B.UnitDelay_l = SWC_APA_DW.UnitDelay_DSTATE_a4;

  /* Switch: '<S627>/Switch5' incorporates:
   *  Constant: '<S627>/Constant'
   */
  if (SWC_APA_B.arcJump_i) {
    SWC_APA_B.Switch5_l = false;
  } else {
    /* Logic: '<S605>/OR1' */
    SWC_APA_B.AND_og = !SWC_APA_B.arcJump_i;

    /* Logic: '<S605>/AND' */
    SWC_APA_B.AND_og = (SWC_APA_B.UnitDelay_ef && SWC_APA_B.AND_og);

    /* Switch: '<S627>/Switch6' incorporates:
     *  Constant: '<S627>/Constant1'
     */
    if (SWC_APA_B.AND_og) {
      SWC_APA_B.Switch6_j = true;
    } else {
      SWC_APA_B.Switch6_j = SWC_APA_B.UnitDelay_l;
    }

    /* End of Switch: '<S627>/Switch6' */
    SWC_APA_B.Switch5_l = SWC_APA_B.Switch6_j;
  }

  /* End of Switch: '<S627>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S605>/Turn On Delay Time' */
  /* Logic: '<S628>/OR1' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.Switch5_l;

  /* Outputs for Atomic SubSystem: '<S628>/EdgeRising1' */
  /* UnitDelay: '<S629>/Unit Delay' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay_DSTATE_e4;

  /* Logic: '<S629>/OR1' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S629>/AND' */
  SWC_APA_B.AND_oq = (SWC_APA_B.Switch5_l && SWC_APA_B.RelationalOperator2_j);

  /* Update for UnitDelay: '<S629>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_e4 = SWC_APA_B.Switch5_l;

  /* End of Outputs for SubSystem: '<S628>/EdgeRising1' */

  /* Logic: '<S628>/OR' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.AND_oq);

  /* UnitDelay: '<S628>/Unit Delay' */
  SWC_APA_B.UnitDelay_b = SWC_APA_B.Switch1_k;

  /* Switch: '<S628>/Switch1' incorporates:
   *  Constant: '<S628>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.Switch1_k = ((uint16_T)0U);
  } else {
    /* Sum: '<S628>/Summation' incorporates:
     *  Constant: '<S605>/Constant4'
     */
    SWC_APA_B.Summation_j = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_b);

    /* MinMax: '<S628>/Minimum' */
    if (SWC_APA_B.timerValue_k < SWC_APA_B.Summation_j) {
      SWC_APA_B.Minimum_g = SWC_APA_B.timerValue_k;
    } else {
      SWC_APA_B.Minimum_g = SWC_APA_B.Summation_j;
    }

    /* End of MinMax: '<S628>/Minimum' */
    SWC_APA_B.Switch1_k = SWC_APA_B.Minimum_g;
  }

  /* End of Switch: '<S628>/Switch1' */

  /* RelationalOperator: '<S628>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch1_k >=
    SWC_APA_B.timerValue_k);

  /* Logic: '<S628>/AND' */
  SWC_APA_B.AND_g = (SWC_APA_B.Switch5_l && SWC_APA_B.RelationalOperator1_e1);

  /* End of Outputs for SubSystem: '<S605>/Turn On Delay Time' */

  /* Switch: '<S605>/Switch' incorporates:
   *  Constant: '<S605>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S605>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_d = !SWC_APA_B.Switch5_l;

    /* Logic: '<S605>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_d = (SWC_APA_B.AND_g ||
      SWC_APA_B.LogicalOperator2_d);

    /* Switch: '<S605>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_d) {
      SWC_APA_B.Switch1_nm = SWC_APA_B.MeAP_e_AlertCHR;
    } else {
      /* RelationalOperator: '<S605>/Relational Operator3' incorporates:
       *  Constant: '<S622>/Constant'
       */
      SWC_APA_B.RelationalOperator3_a = (SWC_APA_B.MeAP_e_AlertCHR !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S605>/Switch2' incorporates:
       *  Constant: '<S625>/Constant'
       *  Constant: '<S626>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_a) {
        SWC_APA_B.Switch2_j = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_j = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S605>/Switch2' */
      SWC_APA_B.Switch1_nm = SWC_APA_B.Switch2_j;
    }

    /* End of Switch: '<S605>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertCHR = SWC_APA_B.Switch1_nm;
  } else {
    *SWC_APA_rty_MeAP_e_AlertCHR = SWC_APA_B.MeAP_e_AlertCHR;
  }

  /* End of Switch: '<S605>/Switch' */

  /* UnitDelay: '<S606>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_h5;

  /* UnitDelay: '<S606>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_B.Switch5_b;

  /* Switch: '<S606>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.timerValue_g = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S606>/Relational Operator1' incorporates:
     *  Constant: '<S606>/Constant'
     */
    SWC_APA_B.RelationalOperator1_lp =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S606>/Relational Operator5' incorporates:
     *  Constant: '<S634>/Constant'
     */
    SWC_APA_B.RelationalOperator5_i =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S606>/Relational Operator4' incorporates:
     *  Constant: '<S633>/Constant'
     */
    SWC_APA_B.LogicalOperator_f =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S606>/Logical Operator' */
    SWC_APA_B.LogicalOperator_f = (SWC_APA_B.LogicalOperator_f &&
      SWC_APA_B.RelationalOperator5_i && SWC_APA_B.RelationalOperator1_lp);

    /* Switch: '<S606>/Switch3' incorporates:
     *  Constant: '<S606>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_f) {
      SWC_APA_B.timerValue_e2 = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S606>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S606>/Constant5'
       *  Constant: '<S606>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S606>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic_g),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.timerValue_e2 = SWC_APA_B.LookupTableDynamic_g;
    }

    /* End of Switch: '<S606>/Switch3' */
    SWC_APA_B.timerValue_g = SWC_APA_B.timerValue_e2;
  }

  /* End of Switch: '<S606>/Switch4' */

  /* RelationalOperator: '<S606>/Relational Operator' incorporates:
   *  Constant: '<S630>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.MeAP_e_AlertLHR ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S606>/Relational Operator2' incorporates:
   *  Constant: '<S631>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.MeAP_e_AlertLHR ==
    TeAP_e_Alert_SNA);

  /* Logic: '<S606>/Logical Operator1' */
  SWC_APA_B.arcJump_p = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S606>/Unit Delay' */
  SWC_APA_B.UnitDelay_ow = SWC_APA_DW.UnitDelay_DSTATE_ke;

  /* UnitDelay: '<S637>/Unit Delay' */
  SWC_APA_B.UnitDelay_m = SWC_APA_DW.UnitDelay_DSTATE_p4;

  /* Switch: '<S637>/Switch5' incorporates:
   *  Constant: '<S637>/Constant'
   */
  if (SWC_APA_B.arcJump_p) {
    SWC_APA_B.Switch5_b = false;
  } else {
    /* Logic: '<S606>/OR1' */
    SWC_APA_B.AND_ag = !SWC_APA_B.arcJump_p;

    /* Logic: '<S606>/AND' */
    SWC_APA_B.AND_ag = (SWC_APA_B.UnitDelay_ow && SWC_APA_B.AND_ag);

    /* Switch: '<S637>/Switch6' incorporates:
     *  Constant: '<S637>/Constant1'
     */
    if (SWC_APA_B.AND_ag) {
      SWC_APA_B.Switch6_h = true;
    } else {
      SWC_APA_B.Switch6_h = SWC_APA_B.UnitDelay_m;
    }

    /* End of Switch: '<S637>/Switch6' */
    SWC_APA_B.Switch5_b = SWC_APA_B.Switch6_h;
  }

  /* End of Switch: '<S637>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S606>/Turn On Delay Time' */
  /* Logic: '<S638>/OR1' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.Switch5_b;

  /* Outputs for Atomic SubSystem: '<S638>/EdgeRising1' */
  /* UnitDelay: '<S639>/Unit Delay' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay_DSTATE_l;

  /* Logic: '<S639>/OR1' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S639>/AND' */
  SWC_APA_B.AND_k2 = (SWC_APA_B.Switch5_b && SWC_APA_B.RelationalOperator2_j);

  /* Update for UnitDelay: '<S639>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_l = SWC_APA_B.Switch5_b;

  /* End of Outputs for SubSystem: '<S638>/EdgeRising1' */

  /* Logic: '<S638>/OR' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.AND_k2);

  /* UnitDelay: '<S638>/Unit Delay' */
  SWC_APA_B.UnitDelay_o = SWC_APA_B.Switch1_cy;

  /* Switch: '<S638>/Switch1' incorporates:
   *  Constant: '<S638>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.Switch1_cy = ((uint16_T)0U);
  } else {
    /* Sum: '<S638>/Summation' incorporates:
     *  Constant: '<S606>/Constant4'
     */
    SWC_APA_B.Summation_o = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_o);

    /* MinMax: '<S638>/Minimum' */
    if (SWC_APA_B.timerValue_g < SWC_APA_B.Summation_o) {
      SWC_APA_B.Minimum_b = SWC_APA_B.timerValue_g;
    } else {
      SWC_APA_B.Minimum_b = SWC_APA_B.Summation_o;
    }

    /* End of MinMax: '<S638>/Minimum' */
    SWC_APA_B.Switch1_cy = SWC_APA_B.Minimum_b;
  }

  /* End of Switch: '<S638>/Switch1' */

  /* RelationalOperator: '<S638>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch1_cy >=
    SWC_APA_B.timerValue_g);

  /* Logic: '<S638>/AND' */
  SWC_APA_B.AND_o = (SWC_APA_B.Switch5_b && SWC_APA_B.RelationalOperator1_e1);

  /* End of Outputs for SubSystem: '<S606>/Turn On Delay Time' */

  /* Switch: '<S606>/Switch' incorporates:
   *  Constant: '<S606>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S606>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_f = !SWC_APA_B.Switch5_b;

    /* Logic: '<S606>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_f = (SWC_APA_B.AND_o ||
      SWC_APA_B.LogicalOperator2_f);

    /* Switch: '<S606>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_f) {
      SWC_APA_B.Switch1_jc = SWC_APA_B.MeAP_e_AlertLHR;
    } else {
      /* RelationalOperator: '<S606>/Relational Operator3' incorporates:
       *  Constant: '<S632>/Constant'
       */
      SWC_APA_B.RelationalOperator3_i = (SWC_APA_B.MeAP_e_AlertLHR !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S606>/Switch2' incorporates:
       *  Constant: '<S635>/Constant'
       *  Constant: '<S636>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_i) {
        SWC_APA_B.Switch2_c = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_c = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S606>/Switch2' */
      SWC_APA_B.Switch1_jc = SWC_APA_B.Switch2_c;
    }

    /* End of Switch: '<S606>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertLHR = SWC_APA_B.Switch1_jc;
  } else {
    *SWC_APA_rty_MeAP_e_AlertLHR = SWC_APA_B.MeAP_e_AlertLHR;
  }

  /* End of Switch: '<S606>/Switch' */

  /* Outputs for Enabled SubSystem: '<S56>/RPA_ChimeAlertGen' incorporates:
   *  EnablePort: '<S481>/Enable'
   */
  if (*SWC_APA_rty_MeAP_b_RPAStatus) {
    if (!SWC_APA_DW.RPA_ChimeAlertGen_MODE) {
      /* InitializeConditions for UnitDelay: '<S532>/Unit Delay1' */
      SWC_APA_DW.UnitDelay1_DSTATE_a = false;

      /* InitializeConditions for UnitDelay: '<S530>/Unit Delay1' */
      SWC_APA_DW.UnitDelay1_DSTATE_d = false;

      /* InitializeConditions for UnitDelay: '<S530>/Unit Delay2' */
      SWC_APA_DW.UnitDelay2_DSTATE_go = ((uint16_T)0U);

      /* InitializeConditions for UnitDelay: '<S531>/Unit Delay3' */
      SWC_APA_DW.UnitDelay3_DSTATE_h = false;

      /* InitializeConditions for UnitDelay: '<S552>/Unit Delay1' */
      SWC_APA_DW.UnitDelay1_DSTATE_mi = false;

      /* InitializeConditions for UnitDelay: '<S550>/Unit Delay1' */
      SWC_APA_DW.UnitDelay1_DSTATE_l = false;

      /* InitializeConditions for UnitDelay: '<S550>/Unit Delay2' */
      SWC_APA_DW.UnitDelay2_DSTATE_i = ((uint16_T)0U);

      /* InitializeConditions for UnitDelay: '<S551>/Unit Delay3' */
      SWC_APA_DW.UnitDelay3_DSTATE_o = false;
      SWC_APA_DW.RPA_ChimeAlertGen_MODE = true;
    }

    /* RelationalOperator: '<S511>/Relational Operator8' incorporates:
     *  Constant: '<S520>/Constant'
     */
    SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rty_MeAP_e_AlertRHR !=
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S511>/Relational Operator9' incorporates:
     *  Constant: '<S521>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertRHR !=
      TeAP_e_Alert_Arc2);

    /* Logic: '<S511>/Logical Operator3' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator1_e1 &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S511>/Relational Operator6' incorporates:
     *  Constant: '<S518>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc5);

    /* Logic: '<S511>/Logical Operator6' */
    SWC_APA_B.MeAP_b_IsRearLeftChimeZone5 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S511>/Relational Operator7' incorporates:
     *  Constant: '<S519>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc6);

    /* Logic: '<S511>/Logical Operator7' */
    SWC_APA_B.MeAP_b_IsRearLeftChimeZone6 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* UnitDelay: '<S532>/Unit Delay1' */
    SWC_APA_B.Compare_k = SWC_APA_DW.UnitDelay1_DSTATE_a;

    /* Logic: '<S532>/Logical Operator9' */
    SWC_APA_B.Compare_k = !SWC_APA_B.Compare_k;

    /* Logic: '<S532>/Logical Operator8' */
    SWC_APA_B.Compare_k = (SWC_APA_B.MeAP_b_IsRearLeftChimeZone6 &&
      SWC_APA_B.Compare_k);

    /* UnitDelay: '<S530>/Unit Delay1' */
    SWC_APA_B.RelationalOperator7 = SWC_APA_DW.UnitDelay1_DSTATE_d;

    /* Switch: '<S530>/Switch2' */
    SWC_APA_B.Switch2_jb = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7);

    /* UnitDelay: '<S530>/Unit Delay2' */
    SWC_APA_B.UnitDelay2_g = SWC_APA_DW.UnitDelay2_DSTATE_go;

    /* Switch: '<S530>/Switch3' incorporates:
     *  Constant: '<S511>/Constant13'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.Switch3_co = ((uint8_T)50U);
    } else {
      /* RelationalOperator: '<S530>/Relational Operator' incorporates:
       *  Constant: '<S511>/Constant14'
       */
      SWC_APA_B.RelationalOperator_fq = (((uint16_T)3U) <=
        SWC_APA_B.UnitDelay2_g);

      /* Switch: '<S530>/Switch1' incorporates:
       *  Constant: '<S530>/Constant'
       */
      if (SWC_APA_B.RelationalOperator_fq) {
        /* Sum: '<S530>/Subtract' incorporates:
         *  Constant: '<S511>/Constant14'
         */
        SWC_APA_B.Subtract_gg = (uint16_T)(SWC_APA_B.UnitDelay2_g - ((uint16_T)
          3U));
        SWC_APA_B.Switch1_f = SWC_APA_B.Subtract_gg;
      } else {
        SWC_APA_B.Switch1_f = ((uint16_T)0U);
      }

      /* End of Switch: '<S530>/Switch1' */
      SWC_APA_B.Switch3_co = SWC_APA_B.Switch1_f;
    }

    /* End of Switch: '<S530>/Switch3' */

    /* RelationalOperator: '<S530>/Relational Operator1' incorporates:
     *  Constant: '<S511>/Constant14'
     */
    SWC_APA_B.RelationalOperator1_a = (((uint16_T)3U) > SWC_APA_B.Switch3_co);

    /* UnitDelay: '<S531>/Unit Delay3' */
    SWC_APA_B.UnitDelay3_a = SWC_APA_DW.UnitDelay3_DSTATE_h;

    /* Switch: '<S531>/Switch5' incorporates:
     *  Constant: '<S531>/Constant1'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.Switch5_k = true;
    } else {
      /* Logic: '<S530>/Logical Operator8' */
      SWC_APA_B.LogicalOperator8_j = (SWC_APA_B.Switch2_jb &&
        SWC_APA_B.RelationalOperator1_a);

      /* Switch: '<S531>/Switch6' incorporates:
       *  Constant: '<S531>/Constant3'
       */
      if (SWC_APA_B.LogicalOperator8_j) {
        SWC_APA_B.Switch6_bv = false;
      } else {
        SWC_APA_B.Switch6_bv = SWC_APA_B.UnitDelay3_a;
      }

      /* End of Switch: '<S531>/Switch6' */
      SWC_APA_B.Switch5_k = SWC_APA_B.Switch6_bv;
    }

    /* End of Switch: '<S531>/Switch5' */

    /* RelationalOperator: '<S511>/Relational Operator5' incorporates:
     *  Constant: '<S517>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc4);

    /* Logic: '<S511>/Logical Operator5' */
    SWC_APA_B.MeAP_b_IsRearLeftChimeZone4 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S511>/Relational Operator4' incorporates:
     *  Constant: '<S516>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc3);

    /* Logic: '<S511>/Logical Operator4' */
    SWC_APA_B.MeAP_b_IsRearLeftChimeZone3 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S511>/Relational Operator2' incorporates:
     *  Constant: '<S514>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertCHR ==
      TeAP_e_Alert_Arc2);

    /* RelationalOperator: '<S511>/Relational Operator3' incorporates:
     *  Constant: '<S515>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertLHR == TeAP_e_Alert_Arc2);

    /* Logic: '<S511>/Logical Operator1' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
      SWC_APA_B.Compare_k);

    /* Logic: '<S511>/Logical Operator2' */
    SWC_APA_B.MeAP_b_IsRearLeftChimeZone2 = (SWC_APA_B.RelationalOperator2_j &&
      SWC_APA_B.RelationalOperator1_e1);

    /* RelationalOperator: '<S511>/Relational Operator' incorporates:
     *  Constant: '<S528>/Constant'
     */
    SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rty_MeAP_e_AlertCHR ==
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S511>/Relational Operator1' incorporates:
     *  Constant: '<S529>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertLHR ==
      TeAP_e_Alert_Arc1);

    /* Logic: '<S511>/Logical Operator' */
    SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
      SWC_APA_B.RelationalOperator2_j);

    /* Switch generated from: '<S511>/Switch' incorporates:
     *  Constant: '<S511>/Constant2'
     *  Constant: '<S527>/Constant'
     *  Switch generated from: '<S511>/Switch1'
     *  Switch generated from: '<S511>/Switch2'
     *  Switch generated from: '<S511>/Switch3'
     *  Switch generated from: '<S511>/Switch4'
     *  Switch generated from: '<S511>/Switch5'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.MeAP_b_ChimeActvLHR_Raw = true;
      SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    } else {
      if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone2) {
        /* Switch generated from: '<S511>/Switch1' incorporates:
         *  Constant: '<S511>/Constant3'
         */
        SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_h = true;

        /* Switch generated from: '<S511>/Switch1' incorporates:
         *  Constant: '<S513>/Constant'
         */
        SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_k =
          TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
      } else {
        if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone3) {
          /* Switch generated from: '<S511>/Switch2' incorporates:
           *  Constant: '<S511>/Constant6'
           *  Switch generated from: '<S511>/Switch1'
           */
          SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_o = true;
        } else {
          if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone4) {
            /* Switch generated from: '<S511>/Switch3' incorporates:
             *  Constant: '<S511>/Constant8'
             *  Switch generated from: '<S511>/Switch1'
             *  Switch generated from: '<S511>/Switch2'
             */
            SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_j = true;
          } else {
            if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone5) {
              /* Switch generated from: '<S511>/Switch4' incorporates:
               *  Constant: '<S511>/Constant10'
               *  Switch generated from: '<S511>/Switch1'
               *  Switch generated from: '<S511>/Switch2'
               *  Switch generated from: '<S511>/Switch3'
               */
              SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_n = true;
            } else {
              if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone6) {
                /* SignalConversion: '<S511>/Signal Conversion' incorporates:
                 *  Switch generated from: '<S511>/Switch1'
                 *  Switch generated from: '<S511>/Switch2'
                 *  Switch generated from: '<S511>/Switch3'
                 *  Switch generated from: '<S511>/Switch4'
                 *  Switch generated from: '<S511>/Switch5'
                 */
                SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_p = SWC_APA_B.Switch5_k;

                /* Switch generated from: '<S511>/Switch5' incorporates:
                 *  Switch generated from: '<S511>/Switch1'
                 *  Switch generated from: '<S511>/Switch2'
                 *  Switch generated from: '<S511>/Switch3'
                 *  Switch generated from: '<S511>/Switch4'
                 */
                SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_b =
                  SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_p;
              } else {
                /* Switch generated from: '<S511>/Switch5' incorporates:
                 *  Constant: '<S511>/Constant4'
                 *  Switch generated from: '<S511>/Switch1'
                 *  Switch generated from: '<S511>/Switch2'
                 *  Switch generated from: '<S511>/Switch3'
                 *  Switch generated from: '<S511>/Switch4'
                 */
                SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_b = false;
              }

              /* Switch generated from: '<S511>/Switch4' incorporates:
               *  Switch generated from: '<S511>/Switch1'
               *  Switch generated from: '<S511>/Switch2'
               *  Switch generated from: '<S511>/Switch3'
               */
              SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_n =
                SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_b;
            }

            /* Switch generated from: '<S511>/Switch3' incorporates:
             *  Switch generated from: '<S511>/Switch1'
             *  Switch generated from: '<S511>/Switch2'
             *  Switch generated from: '<S511>/Switch4'
             *  Switch generated from: '<S511>/Switch5'
             */
            SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_j =
              SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_n;
          }

          /* Switch generated from: '<S511>/Switch2' incorporates:
           *  Switch generated from: '<S511>/Switch1'
           *  Switch generated from: '<S511>/Switch3'
           *  Switch generated from: '<S511>/Switch4'
           *  Switch generated from: '<S511>/Switch5'
           */
          SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_o =
            SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_j;
        }

        /* Switch generated from: '<S511>/Switch1' incorporates:
         *  Switch generated from: '<S511>/Switch2'
         *  Switch generated from: '<S511>/Switch3'
         *  Switch generated from: '<S511>/Switch4'
         *  Switch generated from: '<S511>/Switch5'
         */
        SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_h =
          SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_o;

        /* Switch generated from: '<S511>/Switch2' incorporates:
         *  Constant: '<S523>/Constant'
         *  Switch generated from: '<S511>/Switch1'
         *  Switch generated from: '<S511>/Switch3'
         *  Switch generated from: '<S511>/Switch4'
         *  Switch generated from: '<S511>/Switch5'
         */
        if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone3) {
          SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_l =
            TeAP_e_PAMChimeRepnRate_Fast_4_Hz;
        } else {
          if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone4) {
            /* Switch generated from: '<S511>/Switch3' incorporates:
             *  Constant: '<S524>/Constant'
             */
            SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_ku =
              TeAP_e_PAMChimeRepnRate_Slow_3_Hz;
          } else {
            if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone5) {
              /* Switch generated from: '<S511>/Switch4' incorporates:
               *  Constant: '<S525>/Constant'
               *  Switch generated from: '<S511>/Switch3'
               */
              SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_a =
                TeAP_e_PAMChimeRepnRate_Slow_2_Hz;
            } else {
              if (SWC_APA_B.MeAP_b_IsRearLeftChimeZone6) {
                /* Switch generated from: '<S511>/Switch5' incorporates:
                 *  Constant: '<S526>/Constant'
                 *  Switch generated from: '<S511>/Switch3'
                 *  Switch generated from: '<S511>/Switch4'
                 */
                SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_n =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              } else {
                /* Switch generated from: '<S511>/Switch5' incorporates:
                 *  Constant: '<S522>/Constant'
                 *  Switch generated from: '<S511>/Switch3'
                 *  Switch generated from: '<S511>/Switch4'
                 */
                SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_n =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              }

              /* Switch generated from: '<S511>/Switch4' incorporates:
               *  Switch generated from: '<S511>/Switch3'
               */
              SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_a =
                SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_n;
            }

            /* Switch generated from: '<S511>/Switch3' incorporates:
             *  Switch generated from: '<S511>/Switch4'
             *  Switch generated from: '<S511>/Switch5'
             */
            SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_ku =
              SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_a;
          }

          SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_l =
            SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_ku;
        }

        /* Switch generated from: '<S511>/Switch1' */
        SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_k =
          SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_l;
      }

      SWC_APA_B.MeAP_b_ChimeActvLHR_Raw = SWC_APA_B.MeAP_b_ChimeActvLHR_Raw_h;
      SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw =
        SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw_k;
    }

    /* End of Switch generated from: '<S511>/Switch' */

    /* Switch: '<S530>/Switch4' incorporates:
     *  Constant: '<S530>/Constant2'
     */
    if (SWC_APA_B.RelationalOperator1_a) {
      SWC_APA_B.Switch4_b = ((uint16_T)0U);
    } else {
      SWC_APA_B.Switch4_b = SWC_APA_B.Switch3_co;
    }

    /* End of Switch: '<S530>/Switch4' */

    /* RelationalOperator: '<S512>/Relational Operator10' incorporates:
     *  Constant: '<S540>/Constant'
     */
    SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rty_MeAP_e_AlertLHR !=
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S512>/Relational Operator11' incorporates:
     *  Constant: '<S541>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertLHR !=
      TeAP_e_Alert_Arc2);

    /* Logic: '<S512>/Logical Operator3' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator1_e1 &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S512>/Relational Operator6' incorporates:
     *  Constant: '<S538>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc5);

    /* Logic: '<S512>/Logical Operator6' */
    SWC_APA_B.MeAP_b_IsRearRightChimeZone5 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S512>/Relational Operator7' incorporates:
     *  Constant: '<S539>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc6);

    /* Logic: '<S512>/Logical Operator7' */
    SWC_APA_B.MeAP_b_IsRearRightChimeZone6 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* UnitDelay: '<S552>/Unit Delay1' */
    SWC_APA_B.Compare_k = SWC_APA_DW.UnitDelay1_DSTATE_mi;

    /* Logic: '<S552>/Logical Operator9' */
    SWC_APA_B.Compare_k = !SWC_APA_B.Compare_k;

    /* Logic: '<S552>/Logical Operator8' */
    SWC_APA_B.Compare_k = (SWC_APA_B.MeAP_b_IsRearRightChimeZone6 &&
      SWC_APA_B.Compare_k);

    /* UnitDelay: '<S550>/Unit Delay1' */
    SWC_APA_B.RelationalOperator7 = SWC_APA_DW.UnitDelay1_DSTATE_l;

    /* Switch: '<S550>/Switch2' */
    SWC_APA_B.Switch2_k = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7);

    /* UnitDelay: '<S550>/Unit Delay2' */
    SWC_APA_B.UnitDelay2_cy = SWC_APA_DW.UnitDelay2_DSTATE_i;

    /* Switch: '<S550>/Switch3' incorporates:
     *  Constant: '<S512>/Constant13'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.Switch3_co = ((uint8_T)50U);
    } else {
      /* RelationalOperator: '<S550>/Relational Operator' incorporates:
       *  Constant: '<S512>/Constant14'
       */
      SWC_APA_B.RelationalOperator_n = (((uint16_T)3U) <=
        SWC_APA_B.UnitDelay2_cy);

      /* Switch: '<S550>/Switch1' incorporates:
       *  Constant: '<S550>/Constant'
       */
      if (SWC_APA_B.RelationalOperator_n) {
        /* Sum: '<S550>/Subtract' incorporates:
         *  Constant: '<S512>/Constant14'
         */
        SWC_APA_B.Subtract_a = (uint16_T)(SWC_APA_B.UnitDelay2_cy - ((uint16_T)
          3U));
        SWC_APA_B.Switch1_p = SWC_APA_B.Subtract_a;
      } else {
        SWC_APA_B.Switch1_p = ((uint16_T)0U);
      }

      /* End of Switch: '<S550>/Switch1' */
      SWC_APA_B.Switch3_co = SWC_APA_B.Switch1_p;
    }

    /* End of Switch: '<S550>/Switch3' */

    /* RelationalOperator: '<S550>/Relational Operator1' incorporates:
     *  Constant: '<S512>/Constant14'
     */
    SWC_APA_B.RelationalOperator1_c = (((uint16_T)3U) > SWC_APA_B.Switch3_co);

    /* UnitDelay: '<S551>/Unit Delay3' */
    SWC_APA_B.UnitDelay3_k = SWC_APA_DW.UnitDelay3_DSTATE_o;

    /* Switch: '<S551>/Switch5' incorporates:
     *  Constant: '<S551>/Constant1'
     */
    if (SWC_APA_B.Compare_k) {
      SWC_APA_B.Switch5_h = true;
    } else {
      /* Logic: '<S550>/Logical Operator8' */
      SWC_APA_B.LogicalOperator8_e = (SWC_APA_B.Switch2_k &&
        SWC_APA_B.RelationalOperator1_c);

      /* Switch: '<S551>/Switch6' incorporates:
       *  Constant: '<S551>/Constant3'
       */
      if (SWC_APA_B.LogicalOperator8_e) {
        SWC_APA_B.Switch6_kn = false;
      } else {
        SWC_APA_B.Switch6_kn = SWC_APA_B.UnitDelay3_k;
      }

      /* End of Switch: '<S551>/Switch6' */
      SWC_APA_B.Switch5_h = SWC_APA_B.Switch6_kn;
    }

    /* End of Switch: '<S551>/Switch5' */

    /* RelationalOperator: '<S512>/Relational Operator5' incorporates:
     *  Constant: '<S537>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc4);

    /* Logic: '<S512>/Logical Operator5' */
    SWC_APA_B.MeAP_b_IsRearRightChimeZone4 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S512>/Relational Operator4' incorporates:
     *  Constant: '<S536>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertCHR == TeAP_e_Alert_Arc3);

    /* Logic: '<S512>/Logical Operator4' */
    SWC_APA_B.MeAP_b_IsRearRightChimeZone3 = (SWC_APA_B.Compare_k &&
      SWC_APA_B.RelationalOperator2_j);

    /* RelationalOperator: '<S512>/Relational Operator2' incorporates:
     *  Constant: '<S534>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertCHR ==
      TeAP_e_Alert_Arc2);

    /* RelationalOperator: '<S512>/Relational Operator3' incorporates:
     *  Constant: '<S535>/Constant'
     */
    SWC_APA_B.Compare_k = (*SWC_APA_rty_MeAP_e_AlertRHR == TeAP_e_Alert_Arc2);

    /* Logic: '<S512>/Logical Operator1' */
    SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
      SWC_APA_B.Compare_k);

    /* Logic: '<S512>/Logical Operator2' */
    SWC_APA_B.MeAP_b_IsRearRightChimeZone2 = (SWC_APA_B.RelationalOperator2_j &&
      SWC_APA_B.RelationalOperator1_e1);

    /* RelationalOperator: '<S512>/Relational Operator8' incorporates:
     *  Constant: '<S548>/Constant'
     */
    SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rty_MeAP_e_AlertCHR ==
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S512>/Relational Operator1' incorporates:
     *  Constant: '<S549>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_MeAP_e_AlertRHR ==
      TeAP_e_Alert_Arc1);

    /* Logic: '<S512>/Logical Operator' */
    SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
      SWC_APA_B.RelationalOperator2_j);

    /* Switch generated from: '<S512>/Switch' incorporates:
     *  Constant: '<S512>/Constant2'
     *  Constant: '<S547>/Constant'
     *  Switch generated from: '<S512>/Switch1'
     *  Switch generated from: '<S512>/Switch2'
     *  Switch generated from: '<S512>/Switch3'
     *  Switch generated from: '<S512>/Switch4'
     *  Switch generated from: '<S512>/Switch5'
     */
    if (SWC_APA_B.RelationalOperator1_e1) {
      SWC_APA_B.MeAP_b_ChimeActvRHR_Raw = true;
      SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    } else {
      if (SWC_APA_B.MeAP_b_IsRearRightChimeZone2) {
        /* Switch generated from: '<S512>/Switch1' incorporates:
         *  Constant: '<S512>/Constant3'
         */
        SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_p = true;

        /* Switch generated from: '<S512>/Switch1' incorporates:
         *  Constant: '<S533>/Constant'
         */
        SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_l =
          TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
      } else {
        if (SWC_APA_B.MeAP_b_IsRearRightChimeZone3) {
          /* Switch generated from: '<S512>/Switch2' incorporates:
           *  Constant: '<S512>/Constant6'
           *  Switch generated from: '<S512>/Switch1'
           */
          SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c = true;
        } else {
          if (SWC_APA_B.MeAP_b_IsRearRightChimeZone4) {
            /* Switch generated from: '<S512>/Switch3' incorporates:
             *  Constant: '<S512>/Constant8'
             *  Switch generated from: '<S512>/Switch1'
             *  Switch generated from: '<S512>/Switch2'
             */
            SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_o = true;
          } else {
            if (SWC_APA_B.MeAP_b_IsRearRightChimeZone5) {
              /* Switch generated from: '<S512>/Switch4' incorporates:
               *  Constant: '<S512>/Constant10'
               *  Switch generated from: '<S512>/Switch1'
               *  Switch generated from: '<S512>/Switch2'
               *  Switch generated from: '<S512>/Switch3'
               */
              SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_b = true;
            } else {
              if (SWC_APA_B.MeAP_b_IsRearRightChimeZone6) {
                /* SignalConversion: '<S512>/Signal Conversion' incorporates:
                 *  Switch generated from: '<S512>/Switch1'
                 *  Switch generated from: '<S512>/Switch2'
                 *  Switch generated from: '<S512>/Switch3'
                 *  Switch generated from: '<S512>/Switch4'
                 *  Switch generated from: '<S512>/Switch5'
                 */
                SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_a = SWC_APA_B.Switch5_h;

                /* Switch generated from: '<S512>/Switch5' incorporates:
                 *  Switch generated from: '<S512>/Switch1'
                 *  Switch generated from: '<S512>/Switch2'
                 *  Switch generated from: '<S512>/Switch3'
                 *  Switch generated from: '<S512>/Switch4'
                 */
                SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c1 =
                  SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_a;
              } else {
                /* Switch generated from: '<S512>/Switch5' incorporates:
                 *  Constant: '<S512>/Constant4'
                 *  Switch generated from: '<S512>/Switch1'
                 *  Switch generated from: '<S512>/Switch2'
                 *  Switch generated from: '<S512>/Switch3'
                 *  Switch generated from: '<S512>/Switch4'
                 */
                SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c1 = false;
              }

              /* Switch generated from: '<S512>/Switch4' incorporates:
               *  Switch generated from: '<S512>/Switch1'
               *  Switch generated from: '<S512>/Switch2'
               *  Switch generated from: '<S512>/Switch3'
               */
              SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_b =
                SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c1;
            }

            /* Switch generated from: '<S512>/Switch3' incorporates:
             *  Switch generated from: '<S512>/Switch1'
             *  Switch generated from: '<S512>/Switch2'
             *  Switch generated from: '<S512>/Switch4'
             *  Switch generated from: '<S512>/Switch5'
             */
            SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_o =
              SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_b;
          }

          /* Switch generated from: '<S512>/Switch2' incorporates:
           *  Switch generated from: '<S512>/Switch1'
           *  Switch generated from: '<S512>/Switch3'
           *  Switch generated from: '<S512>/Switch4'
           *  Switch generated from: '<S512>/Switch5'
           */
          SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c =
            SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_o;
        }

        /* Switch generated from: '<S512>/Switch1' incorporates:
         *  Switch generated from: '<S512>/Switch2'
         *  Switch generated from: '<S512>/Switch3'
         *  Switch generated from: '<S512>/Switch4'
         *  Switch generated from: '<S512>/Switch5'
         */
        SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_p =
          SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_c;

        /* Switch generated from: '<S512>/Switch2' incorporates:
         *  Constant: '<S543>/Constant'
         *  Switch generated from: '<S512>/Switch1'
         *  Switch generated from: '<S512>/Switch3'
         *  Switch generated from: '<S512>/Switch4'
         *  Switch generated from: '<S512>/Switch5'
         */
        if (SWC_APA_B.MeAP_b_IsRearRightChimeZone3) {
          SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_a =
            TeAP_e_PAMChimeRepnRate_Fast_4_Hz;
        } else {
          if (SWC_APA_B.MeAP_b_IsRearRightChimeZone4) {
            /* Switch generated from: '<S512>/Switch3' incorporates:
             *  Constant: '<S544>/Constant'
             */
            SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_k =
              TeAP_e_PAMChimeRepnRate_Slow_3_Hz;
          } else {
            if (SWC_APA_B.MeAP_b_IsRearRightChimeZone5) {
              /* Switch generated from: '<S512>/Switch4' incorporates:
               *  Constant: '<S545>/Constant'
               *  Switch generated from: '<S512>/Switch3'
               */
              SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_g =
                TeAP_e_PAMChimeRepnRate_Slow_2_Hz;
            } else {
              if (SWC_APA_B.MeAP_b_IsRearRightChimeZone6) {
                /* Switch generated from: '<S512>/Switch5' incorporates:
                 *  Constant: '<S546>/Constant'
                 *  Switch generated from: '<S512>/Switch3'
                 *  Switch generated from: '<S512>/Switch4'
                 */
                SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_j =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              } else {
                /* Switch generated from: '<S512>/Switch5' incorporates:
                 *  Constant: '<S542>/Constant'
                 *  Switch generated from: '<S512>/Switch3'
                 *  Switch generated from: '<S512>/Switch4'
                 */
                SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_j =
                  TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
              }

              /* Switch generated from: '<S512>/Switch4' incorporates:
               *  Switch generated from: '<S512>/Switch3'
               */
              SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_g =
                SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_j;
            }

            /* Switch generated from: '<S512>/Switch3' incorporates:
             *  Switch generated from: '<S512>/Switch4'
             *  Switch generated from: '<S512>/Switch5'
             */
            SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_k =
              SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_g;
          }

          SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_a =
            SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_k;
        }

        /* Switch generated from: '<S512>/Switch1' */
        SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_l =
          SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_a;
      }

      SWC_APA_B.MeAP_b_ChimeActvRHR_Raw = SWC_APA_B.MeAP_b_ChimeActvRHR_Raw_p;
      SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw =
        SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw_l;
    }

    /* End of Switch generated from: '<S512>/Switch' */

    /* Switch: '<S550>/Switch4' incorporates:
     *  Constant: '<S550>/Constant2'
     */
    if (SWC_APA_B.RelationalOperator1_c) {
      SWC_APA_B.Switch4_n = ((uint16_T)0U);
    } else {
      SWC_APA_B.Switch4_n = SWC_APA_B.Switch3_co;
    }

    /* End of Switch: '<S550>/Switch4' */

    /* Update for UnitDelay: '<S532>/Unit Delay1' */
    SWC_APA_DW.UnitDelay1_DSTATE_a = SWC_APA_B.MeAP_b_IsRearLeftChimeZone6;

    /* Update for UnitDelay: '<S530>/Unit Delay1' */
    SWC_APA_DW.UnitDelay1_DSTATE_d = SWC_APA_B.Switch2_jb;

    /* Update for UnitDelay: '<S530>/Unit Delay2' */
    SWC_APA_DW.UnitDelay2_DSTATE_go = SWC_APA_B.Switch4_b;

    /* Update for UnitDelay: '<S531>/Unit Delay3' */
    SWC_APA_DW.UnitDelay3_DSTATE_h = SWC_APA_B.Switch5_k;

    /* Update for UnitDelay: '<S552>/Unit Delay1' */
    SWC_APA_DW.UnitDelay1_DSTATE_mi = SWC_APA_B.MeAP_b_IsRearRightChimeZone6;

    /* Update for UnitDelay: '<S550>/Unit Delay1' */
    SWC_APA_DW.UnitDelay1_DSTATE_l = SWC_APA_B.Switch2_k;

    /* Update for UnitDelay: '<S550>/Unit Delay2' */
    SWC_APA_DW.UnitDelay2_DSTATE_i = SWC_APA_B.Switch4_n;

    /* Update for UnitDelay: '<S551>/Unit Delay3' */
    SWC_APA_DW.UnitDelay3_DSTATE_o = SWC_APA_B.Switch5_h;
  } else {
    if (SWC_APA_DW.RPA_ChimeAlertGen_MODE) {
      /* Disable for Outport: '<S481>/MeAP_b_ChimeActvLHR' */
      SWC_APA_B.MeAP_b_ChimeActvLHR_Raw = false;

      /* Disable for Outport: '<S481>/IeAP_b_ChimeActvRHR' */
      SWC_APA_B.MeAP_b_ChimeActvRHR_Raw = false;

      /* Disable for Outport: '<S481>/MeAP_e_LtRearChimeRepnRate' */
      SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;

      /* Disable for Outport: '<S481>/MeAP_e_RtRearChimeRepnRate' */
      SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      SWC_APA_DW.RPA_ChimeAlertGen_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S56>/RPA_ChimeAlertGen' */

  /* Logic: '<S482>/Logical Operator1' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.MeAP_b_ChimeActvLHR_Raw ||
    SWC_APA_B.MeAP_b_ChimeActvRHR_Raw);

  /* Logic: '<S482>/Logical Operator2' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

  /* UnitDelay: '<S482>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_j = SWC_APA_DW.UnitDelay1_DSTATE_j;

  /* UnitDelay: '<S563>/Unit Delay1' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay1_DSTATE_fa;

  /* Logic: '<S563>/Logical Operator9' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S563>/Logical Operator8' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.UnitDelay1_j &&
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S559>/Unit Delay1' */
  SWC_APA_B.Compare_k = SWC_APA_B.Switch2_l;

  /* Switch: '<S559>/Switch2' */
  SWC_APA_B.Switch2_l = (SWC_APA_B.RelationalOperator2_j || SWC_APA_B.Compare_k);

  /* UnitDelay: '<S559>/Unit Delay2' */
  SWC_APA_B.UnitDelay2 = SWC_APA_B.Switch4_g;

  /* Switch: '<S559>/Switch3' incorporates:
   *  Constant: '<S482>/Constant7'
   */
  if (SWC_APA_B.RelationalOperator2_j) {
    SWC_APA_B.Switch3 = KeAP_cnt_BootupTimeThd;
  } else {
    /* RelationalOperator: '<S559>/Relational Operator' incorporates:
     *  Constant: '<S482>/Constant6'
     */
    SWC_APA_B.RelationalOperator_e = (KeAP_cnt_TimeStep <= SWC_APA_B.UnitDelay2);

    /* Switch: '<S559>/Switch1' incorporates:
     *  Constant: '<S559>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_e) {
      /* Sum: '<S559>/Subtract' incorporates:
       *  Constant: '<S482>/Constant6'
       */
      SWC_APA_B.Subtract = SWC_APA_B.UnitDelay2 - (real_T)KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1 = SWC_APA_B.Subtract;
    } else {
      SWC_APA_B.Switch1 = 0.0;
    }

    /* End of Switch: '<S559>/Switch1' */
    SWC_APA_B.Switch3 = SWC_APA_B.Switch1;
  }

  /* End of Switch: '<S559>/Switch3' */

  /* RelationalOperator: '<S559>/Relational Operator1' incorporates:
   *  Constant: '<S482>/Constant6'
   */
  SWC_APA_B.RelationalOperator1 = (KeAP_cnt_TimeStep > SWC_APA_B.Switch3);

  /* UnitDelay: '<S562>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_b = SWC_APA_B.Switch5_m;

  /* Switch: '<S562>/Switch5' incorporates:
   *  Constant: '<S562>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator2_j) {
    SWC_APA_B.Switch5_m = true;
  } else {
    /* Logic: '<S559>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_n = (SWC_APA_B.Switch2_l &&
      SWC_APA_B.RelationalOperator1);

    /* Switch: '<S562>/Switch6' incorporates:
     *  Constant: '<S562>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_n) {
      SWC_APA_B.Switch6_b = false;
    } else {
      SWC_APA_B.Switch6_b = SWC_APA_B.UnitDelay3_b;
    }

    /* End of Switch: '<S562>/Switch6' */
    SWC_APA_B.Switch5_m = SWC_APA_B.Switch6_b;
  }

  /* End of Switch: '<S562>/Switch5' */

  /* UnitDelay: '<S482>/Unit Delay' */
  SWC_APA_B.UnitDelay_p = SWC_APA_DW.UnitDelay_DSTATE_p;

  /* Switch: '<S482>/Switch' incorporates:
   *  Constant: '<S482>/Constant1'
   */
  if (SWC_APA_B.Switch5_m) {
    SWC_APA_B.RelationalOperator2_j = false;
  } else {
    /* RelationalOperator: '<S482>/Relational Operator' */
    SWC_APA_B.RelationalOperator =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear !=
       SWC_APA_B.UnitDelay_p);
    SWC_APA_B.RelationalOperator2_j = SWC_APA_B.RelationalOperator;
  }

  /* End of Switch: '<S482>/Switch' */

  /* RelationalOperator: '<S482>/Relational Operator1' incorporates:
   *  Constant: '<S554>/Constant'
   */
  SWC_APA_B.Compare_k = (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear ==
    TeVBII_e_PamChimeVol_Low);

  /* RelationalOperator: '<S482>/Relational Operator2' incorporates:
   *  Constant: '<S556>/Constant'
   */
  SWC_APA_B.RelationalOperator7 =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear ==
     TeVBII_e_PamChimeVol_Medium);

  /* RelationalOperator: '<S482>/Relational Operator3' incorporates:
   *  Constant: '<S557>/Constant'
   */
  SWC_APA_B.RelationalOperator8_e =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear ==
     TeVBII_e_PamChimeVol_High);

  /* Logic: '<S482>/Logical Operator3' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S482>/Logical Operator4' */
  SWC_APA_B.LogicalOperator4_c = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.Compare_k);

  /* UnitDelay: '<S561>/Unit Delay1' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay1_DSTATE_m;

  /* Logic: '<S561>/Logical Operator9' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S561>/Logical Operator8' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.LogicalOperator4_c &&
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S558>/Unit Delay1' */
  SWC_APA_B.Compare_k = SWC_APA_B.Switch2_d;

  /* Switch: '<S558>/Switch2' */
  SWC_APA_B.Switch2_d = (SWC_APA_B.RelationalOperator2_j || SWC_APA_B.Compare_k);

  /* UnitDelay: '<S558>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_o = SWC_APA_B.Switch4;

  /* Switch: '<S558>/Switch3' */
  if (SWC_APA_B.RelationalOperator2_j) {
    SWC_APA_B.Switch3_p =
      *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert;
  } else {
    /* RelationalOperator: '<S558>/Relational Operator' */
    SWC_APA_B.RelationalOperator_f =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_o);

    /* Switch: '<S558>/Switch1' incorporates:
     *  Constant: '<S558>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_f) {
      /* Sum: '<S558>/Subtract' */
      SWC_APA_B.Subtract_e = SWC_APA_B.UnitDelay2_o - (real_T)
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1_c = SWC_APA_B.Subtract_e;
    } else {
      SWC_APA_B.Switch1_c = 0.0;
    }

    /* End of Switch: '<S558>/Switch1' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch1_c;
  }

  /* End of Switch: '<S558>/Switch3' */

  /* RelationalOperator: '<S558>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_d =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_p);

  /* UnitDelay: '<S560>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_j = SWC_APA_B.Switch5_j;

  /* Switch: '<S560>/Switch5' incorporates:
   *  Constant: '<S560>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator2_j) {
    SWC_APA_B.Switch5_j = true;
  } else {
    /* Logic: '<S558>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_pb = (SWC_APA_B.Switch2_d &&
      SWC_APA_B.RelationalOperator1_d);

    /* Switch: '<S560>/Switch6' incorporates:
     *  Constant: '<S560>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_pb) {
      SWC_APA_B.Switch6_a = false;
    } else {
      SWC_APA_B.Switch6_a = SWC_APA_B.UnitDelay3_j;
    }

    /* End of Switch: '<S560>/Switch6' */
    SWC_APA_B.Switch5_j = SWC_APA_B.Switch6_a;
  }

  /* End of Switch: '<S560>/Switch5' */

  /* Logic: '<S482>/Logical Operator' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.Switch5_j &&
    SWC_APA_B.RelationalOperator1_e1);

  /* Switch generated from: '<S482>/Switch2' incorporates:
   *  Constant: '<S482>/Constant4'
   *  Constant: '<S482>/Constant5'
   *  Constant: '<S553>/Constant'
   *  Constant: '<S555>/Constant'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.MeAP_b_ChimeActvLHR = true;
    SWC_APA_B.MeAP_b_ChimeActvRHR = true;
    SWC_APA_B.MeAP_e_LtRearChimeRepnRate =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    SWC_APA_B.MeAP_e_RtRearChimeRepnRate =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  } else {
    SWC_APA_B.MeAP_b_ChimeActvLHR = SWC_APA_B.MeAP_b_ChimeActvLHR_Raw;
    SWC_APA_B.MeAP_b_ChimeActvRHR = SWC_APA_B.MeAP_b_ChimeActvRHR_Raw;
    SWC_APA_B.MeAP_e_LtRearChimeRepnRate =
      SWC_APA_B.MeAP_e_LtRearChimeRepnRate_Raw;
    SWC_APA_B.MeAP_e_RtRearChimeRepnRate =
      SWC_APA_B.MeAP_e_RtRearChimeRepnRate_Raw;
  }

  /* End of Switch generated from: '<S482>/Switch2' */

  /* Switch: '<S558>/Switch4' incorporates:
   *  Constant: '<S558>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1_d) {
    SWC_APA_B.Switch4 = 0.0;
  } else {
    SWC_APA_B.Switch4 = SWC_APA_B.Switch3_p;
  }

  /* End of Switch: '<S558>/Switch4' */

  /* Switch: '<S559>/Switch4' incorporates:
   *  Constant: '<S559>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1) {
    SWC_APA_B.Switch4_g = 0.0;
  } else {
    SWC_APA_B.Switch4_g = SWC_APA_B.Switch3;
  }

  /* End of Switch: '<S559>/Switch4' */

  /* DataTypeConversion: '<S603>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_p = (uint8_T)*SWC_APA_rty_MeAP_e_AlertLHR;

  /* MultiPortSwitch: '<S603>/Multiport Switch' incorporates:
   *  Constant: '<S612>/Constant'
   *  Constant: '<S613>/Constant'
   *  Constant: '<S614>/Constant'
   *  Constant: '<S615>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_p) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S603>/Multiport Switch' */

  /* DataTypeConversion: '<S602>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_g = (uint8_T)*SWC_APA_rty_MeAP_e_AlertCHR;

  /* MultiPortSwitch: '<S602>/Multiport Switch' incorporates:
   *  Constant: '<S608>/Constant'
   *  Constant: '<S609>/Constant'
   *  Constant: '<S610>/Constant'
   *  Constant: '<S611>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_g) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S602>/Multiport Switch' */

  /* DataTypeConversion: '<S604>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_e = (uint8_T)*SWC_APA_rty_MeAP_e_AlertRHR;

  /* MultiPortSwitch: '<S604>/Multiport Switch' incorporates:
   *  Constant: '<S616>/Constant'
   *  Constant: '<S617>/Constant'
   *  Constant: '<S618>/Constant'
   *  Constant: '<S619>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_e) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S604>/Multiport Switch' */

  /* RelationalOperator: '<S480>/Relational Operator11' incorporates:
   *  Constant: '<S490>/Constant'
   */
  SWC_APA_B.RelationalOperator11 = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_TemporaryFailure);

  /* Logic: '<S480>/Logical Operator' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.MeAP_b_TrlrNotConnected;

  /* RelationalOperator: '<S480>/Relational Operator1' incorporates:
   *  Constant: '<S485>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S480>/Relational Operator12' incorporates:
   *  Constant: '<S491>/Constant'
   */
  SWC_APA_B.Compare_k = (*SWC_APA_rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S480>/Relational Operator13' incorporates:
   *  Constant: '<S492>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*SWC_APA_rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_SNA);

  /* RelationalOperator: '<S480>/Relational Operator10' incorporates:
   *  Constant: '<S489>/Constant'
   */
  SWC_APA_B.RelationalOperator8_e = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* RelationalOperator: '<S480>/Relational Operator4' incorporates:
   *  Constant: '<S500>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S480>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RearSysFault = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator1_e1 || SWC_APA_B.RelationalOperator8_e ||
    SWC_APA_B.LogicalOperator1_d || SWC_APA_B.RelationalOperator11);

  /* UnitDelay: '<S510>/Unit Delay1' */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_DW.UnitDelay1_DSTATE_et;

  /* Logic: '<S510>/Logical Operator9' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

  /* RelationalOperator: '<S510>/Relational Operator4' */
  SWC_APA_B.RelationalOperator1_e1 = (MeAP_b_RPASwtStatus ==
    SWC_APA_B.RelationalOperator1_e1);

  /* UnitDelay: '<S509>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_n = SWC_APA_B.Switch3_h;

  /* Switch: '<S509>/Switch3' incorporates:
   *  Constant: '<S506>/Constant'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.Switch3_h = KeAP_cnt_BtnPressPopUpTimeThd;
  } else {
    /* RelationalOperator: '<S509>/Relational Operator' */
    SWC_APA_B.ElapseTimer =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_n);

    /* Logic: '<S509>/Logical Operator3' */
    SWC_APA_B.ElapseTimer = (SWC_APA_B.ElapseTimer &&
      SWC_APA_ConstB.LogicalOperator1);

    /* Switch: '<S509>/Switch1' incorporates:
     *  Constant: '<S509>/Constant'
     */
    if (SWC_APA_B.ElapseTimer) {
      /* Sum: '<S509>/Subtract' */
      SWC_APA_B.Subtract_py = (uint16_T)(SWC_APA_B.UnitDelay2_n -
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_am = SWC_APA_B.Subtract_py;
    } else {
      SWC_APA_B.Switch1_am = ((uint16_T)0U);
    }

    /* End of Switch: '<S509>/Switch1' */
    SWC_APA_B.Switch3_h = SWC_APA_B.Switch1_am;
  }

  /* End of Switch: '<S509>/Switch3' */

  /* RelationalOperator: '<S509>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_e1 =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_h);

  /* Logic: '<S509>/Logical Operator4' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

  /* Logic: '<S480>/Logical Operator7' */
  SWC_APA_B.LogicalOperator7 = (SWC_APA_B.RelationalOperator1_e1 &&
    SWC_APA_B.MeAP_b_RearSysFault);

  /* UnitDelay: '<S508>/Unit Delay1' */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_DW.UnitDelay1_DSTATE_o;

  /* Logic: '<S508>/Logical Operator9' */
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

  /* Logic: '<S508>/Logical Operator8' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.LogicalOperator7 &&
    SWC_APA_B.RelationalOperator1_e1);

  /* UnitDelay: '<S505>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_i = SWC_APA_B.Switch4_k;

  /* Switch: '<S505>/Switch3' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    /* Switch: '<S480>/Switch' incorporates:
     *  Constant: '<S480>/Constant2'
     */
    if (SWC_APA_B.RelationalOperator11) {
      SWC_APA_B.Switch_a = KeAP_cnt_PlntModeLEDBlinkTimeThd;
    } else {
      SWC_APA_B.Switch_a =
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd;
    }

    /* End of Switch: '<S480>/Switch' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch_a;
  } else {
    /* RelationalOperator: '<S505>/Relational Operator' */
    SWC_APA_B.RelationalOperator_k =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_i);

    /* Switch: '<S505>/Switch1' incorporates:
     *  Constant: '<S505>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_k) {
      /* Sum: '<S505>/Subtract' */
      SWC_APA_B.Subtract_m = SWC_APA_B.UnitDelay2_i - (real_T)
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1_e = SWC_APA_B.Subtract_m;
    } else {
      SWC_APA_B.Switch1_e = 0.0;
    }

    /* End of Switch: '<S505>/Switch1' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch1_e;
  }

  /* End of Switch: '<S505>/Switch3' */

  /* RelationalOperator: '<S505>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_l =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_p);

  /* UnitDelay: '<S505>/Unit Delay1' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_B.Switch2_o;

  /* Switch: '<S505>/Switch2' */
  SWC_APA_B.Switch2_o = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S507>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_f = SWC_APA_B.Switch5_c;

  /* Switch: '<S507>/Switch5' incorporates:
   *  Constant: '<S507>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.Switch5_c = true;
  } else {
    /* Logic: '<S505>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_c = (SWC_APA_B.Switch2_o &&
      SWC_APA_B.RelationalOperator1_l);

    /* Switch: '<S507>/Switch6' incorporates:
     *  Constant: '<S507>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_c) {
      SWC_APA_B.Switch6_e = false;
    } else {
      SWC_APA_B.Switch6_e = SWC_APA_B.UnitDelay3_f;
    }

    /* End of Switch: '<S507>/Switch6' */
    SWC_APA_B.Switch5_c = SWC_APA_B.Switch6_e;
  }

  /* End of Switch: '<S507>/Switch5' */

  /* UnitDelay: '<S480>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_m = SWC_APA_DW.UnitDelay1_DSTATE_e;

  /* Switch: '<S480>/Switch2' incorporates:
   *  Constant: '<S499>/Constant'
   */
  if (SWC_APA_B.Switch5_c) {
    *SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus =
      TeAP_e_PAMLedCtrlStatus_BlinkingLight;
  } else {
    /* RelationalOperator: '<S480>/Relational Operator17' incorporates:
     *  Constant: '<S495>/Constant'
     */
    SWC_APA_B.IgnRun = (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
                        TeVBII_e_CmdIgnSts_RUN);

    /* RelationalOperator: '<S480>/Relational Operator3' incorporates:
     *  Constant: '<S498>/Constant'
     */
    SWC_APA_B.RelationalOperator3_f =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_ACC);

    /* RelationalOperator: '<S480>/Relational Operator14' incorporates:
     *  Constant: '<S497>/Constant'
     */
    SWC_APA_B.RelationalOperator14 =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_START);

    /* RelationalOperator: '<S480>/Relational Operator2' incorporates:
     *  Constant: '<S496>/Constant'
     */
    SWC_APA_B.LogicalOperator10 =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_IGN_LK);

    /* RelationalOperator: '<S480>/Relational Operator18' incorporates:
     *  Constant: '<S494>/Constant'
     */
    SWC_APA_B.RelationalOperator6 =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_Initialization);

    /* RelationalOperator: '<S480>/Relational Operator16' incorporates:
     *  Constant: '<S493>/Constant'
     */
    SWC_APA_B.LogicalOperator9 =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_RUN);

    /* Logic: '<S480>/Logical Operator2' */
    SWC_APA_B.LogicalOperator9 = (SWC_APA_B.LogicalOperator9 &&
      SWC_APA_B.RelationalOperator6 && SWC_APA_B.LogicalOperator10 &&
      SWC_APA_B.RelationalOperator14 && SWC_APA_B.RelationalOperator3_f);

    /* Logic: '<S480>/Logical Operator6' */
    SWC_APA_B.LogicalOperator9 = (SWC_APA_B.LogicalOperator9 || SWC_APA_B.IgnRun);

    /* Logic: '<S480>/Logical Operator17' */
    SWC_APA_B.LogicalOperator9 = (SWC_APA_B.LogicalOperator9 &&
      SWC_APA_B.MeAP_b_RearSysFault);

    /* RelationalOperator: '<S480>/Relational Operator6' incorporates:
     *  Constant: '<S503>/Constant'
     */
    SWC_APA_B.RelationalOperator6 = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
      TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

    /* RelationalOperator: '<S480>/Relational Operator5' incorporates:
     *  Constant: '<S502>/Constant'
     */
    SWC_APA_B.LogicalOperator10 = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
      TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

    /* Logic: '<S480>/Logical Operator8' */
    SWC_APA_B.LogicalOperator10 = (SWC_APA_B.LogicalOperator10 ||
      SWC_APA_B.RelationalOperator6);

    /* Logic: '<S480>/Logical Operator11' */
    SWC_APA_B.LogicalOperator10 = !SWC_APA_B.LogicalOperator10;

    /* Logic: '<S480>/Logical Operator10' */
    SWC_APA_B.LogicalOperator10 = (SWC_APA_B.LogicalOperator10 &&
      SWC_APA_B.IgnRun);

    /* Logic: '<S480>/Logical Operator9' */
    SWC_APA_B.LogicalOperator9 = (SWC_APA_B.LogicalOperator9 ||
      SWC_APA_B.LogicalOperator10);

    /* Switch: '<S480>/Switch3' incorporates:
     *  Constant: '<S504>/Constant'
     */
    if (SWC_APA_B.LogicalOperator9) {
      SWC_APA_B.Switch3_c = TeAP_e_PAMLedCtrlStatus_ContinousLight;
    } else {
      /* Logic: '<S480>/Logical Operator5' */
      SWC_APA_B.LogicalOperator5_h = !SWC_APA_B.IgnRun;

      /* RelationalOperator: '<S480>/Relational Operator9' incorporates:
       *  Constant: '<S501>/Constant'
       */
      SWC_APA_B.RelationalOperator9 = (*SWC_APA_rtu_IeAP_e_ParKMnvrActv ==
        TeAP_e_ParKMnvrActv_Engaged_Full);

      /* Logic: '<S480>/Logical Operator13' */
      SWC_APA_B.LogicalOperator13 = !SWC_APA_B.MeAP_b_RearSysFault;

      /* RelationalOperator: '<S480>/Relational Operator8' incorporates:
       *  Constant: '<S487>/Constant'
       */
      SWC_APA_B.RelationalOperator8 = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
        TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

      /* RelationalOperator: '<S480>/Relational Operator7' incorporates:
       *  Constant: '<S486>/Constant'
       */
      SWC_APA_B.LogicalOperator3_n = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
        TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

      /* Logic: '<S480>/Logical Operator12' */
      SWC_APA_B.LogicalOperator3_n = (SWC_APA_B.LogicalOperator3_n ||
        SWC_APA_B.RelationalOperator8);

      /* Logic: '<S480>/Logical Operator14' */
      SWC_APA_B.LogicalOperator3_n = (SWC_APA_B.LogicalOperator3_n &&
        SWC_APA_B.LogicalOperator13);

      /* Logic: '<S480>/Logical Operator4' */
      SWC_APA_B.LogicalOperator3_n = (SWC_APA_B.LogicalOperator3_n ||
        SWC_APA_B.RelationalOperator9);

      /* Logic: '<S480>/Logical Operator3' */
      SWC_APA_B.LogicalOperator3_n = (SWC_APA_B.LogicalOperator3_n ||
        SWC_APA_B.LogicalOperator5_h);

      /* Switch: '<S480>/Switch4' incorporates:
       *  Constant: '<S488>/Constant'
       */
      if (SWC_APA_B.LogicalOperator3_n) {
        SWC_APA_B.Switch4_es = TeAP_e_PAMLedCtrlStatus_Off;
      } else {
        SWC_APA_B.Switch4_es = SWC_APA_B.UnitDelay1_m;
      }

      /* End of Switch: '<S480>/Switch4' */
      SWC_APA_B.Switch3_c = SWC_APA_B.Switch4_es;
    }

    /* End of Switch: '<S480>/Switch3' */
    *SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus = SWC_APA_B.Switch3_c;
  }

  /* End of Switch: '<S480>/Switch2' */

  /* Switch: '<S505>/Switch4' incorporates:
   *  Constant: '<S505>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1_l) {
    SWC_APA_B.Switch4_k = 0.0;
  } else {
    SWC_APA_B.Switch4_k = SWC_APA_B.Switch3_p;
  }

  /* End of Switch: '<S505>/Switch4' */

  /* Update for UnitDelay: '<S607>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_k = SWC_APA_B.timerValue;

  /* Update for UnitDelay: '<S607>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_ej = SWC_APA_B.arcJump;

  /* Update for UnitDelay: '<S647>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_go = SWC_APA_B.Switch5_n;

  /* Update for UnitDelay: '<S605>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_f = SWC_APA_B.timerValue_k;

  /* Update for UnitDelay: '<S605>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_c = SWC_APA_B.arcJump_i;

  /* Update for UnitDelay: '<S627>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_a4 = SWC_APA_B.Switch5_l;

  /* Update for UnitDelay: '<S606>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_h5 = SWC_APA_B.timerValue_g;

  /* Update for UnitDelay: '<S606>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_ke = SWC_APA_B.arcJump_p;

  /* Update for UnitDelay: '<S637>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_p4 = SWC_APA_B.Switch5_b;

  /* Update for UnitDelay: '<S482>/Unit Delay1' incorporates:
   *  Constant: '<S482>/Constant'
   */
  SWC_APA_DW.UnitDelay1_DSTATE_j = false;

  /* Update for UnitDelay: '<S563>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_fa = SWC_APA_B.UnitDelay1_j;

  /* Update for UnitDelay: '<S482>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_p =
    *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;

  /* Update for UnitDelay: '<S561>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_m = SWC_APA_B.LogicalOperator4_c;

  /* Update for UnitDelay: '<S510>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_et = MeAP_b_RPASwtStatus;

  /* Update for UnitDelay: '<S508>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_o = SWC_APA_B.LogicalOperator7;

  /* Update for UnitDelay: '<S480>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_e = *SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
