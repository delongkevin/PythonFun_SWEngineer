/*
 * File: FrontParkAssist.c
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

#include "FrontParkAssist.h"

/* Include model header file for global data */
#include "SWC_APA.h"
#include "SWC_APA_private.h"

/* Includes for objects with custom storage classes. */
#include "SWC_APA.h"
#include "LookUp_U16_real32_T.h"
#include "look1_iflftu16Df_binlcpw.h"

/* Named constants for Chart: '<S83>/AlertFilterCHF' */
#define SWC_APA_IN_HOLD_OUTPUT         ((uint8_T)1U)
#define SWC_APA_IN_UPDATE_OUTPUT       ((uint8_T)2U)

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
static real_T SWC_APA_CheckHystDistZoneInc(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneDec(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneInc_m(real_T ArcZone, real_T DistRaw);
static real_T SWC_APA_CheckHystDistZoneDec_l(real_T ArcZone, real_T DistRaw);

/* Function for Chart: '<S83>/AlertFilterCHF' */
static real_T SWC_APA_CheckHystDistZoneInc(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  real_T tmp;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    if (SWC_APA_B.Zone1 < 32768.0F) {
      if (SWC_APA_B.Zone1 >= -32768.0F) {
        DistDiff = (int16_T)SWC_APA_B.Zone1;
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
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone2);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 3.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone6);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 10;
}

/* Function for Chart: '<S83>/AlertFilterCHF' */
static real_T SWC_APA_CheckHystDistZoneDec(real_T ArcZone, real_T DistRaw)
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
    if (SWC_APA_B.Zone1 < 32768.0F) {
      if (SWC_APA_B.Zone1 >= -32768.0F) {
        DistDiff = (int16_T)SWC_APA_B.Zone1;
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
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone2);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 5;
}

/* Function for Chart: '<S83>/AlertFilterLHF' */
static real_T SWC_APA_CheckHystDistZoneInc_m(real_T ArcZone, real_T DistRaw)
{
  int16_T DistDiff;
  real_T tmp;
  int32_T tmp_0;
  DistDiff = 0;
  if (ArcZone == 1.0) {
    tmp_0 = KeAP_cm_FrntDistZone1 - ((int16_T)CeAP_cm_FrntSideArc1Adj);
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
    tmp_0 = KeAP_cm_FrntDistZone2 - ((int16_T)CeAP_cm_FrntSideArc2Adj);
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
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone3);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 4.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone4);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone5);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone6);
    if (tmp < 32768.0) {
      DistDiff = (int16_T)tmp;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 10;
}

/* Function for Chart: '<S83>/AlertFilterLHF' */
static real_T SWC_APA_CheckHystDistZoneDec_l(real_T ArcZone, real_T DistRaw)
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
    tmp = KeAP_cm_FrntDistZone1 - ((int16_T)CeAP_cm_FrntSideArc1Adj);
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
    tmp = KeAP_cm_FrntDistZone2 - ((int16_T)CeAP_cm_FrntSideArc2Adj);
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
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone3);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 5.0) {
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone4);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  if (ArcZone == 6.0) {
    tmp_0 = fabs(DistRaw - (real_T)KeAP_cm_FrntDistZone5);
    if (tmp_0 < 32768.0) {
      DistDiff = (int16_T)tmp_0;
    } else {
      DistDiff = MAX_int16_T;
    }
  }

  return DistDiff > 5;
}

/* System initialize for atomic system: '<S6>/FPA' */
void SWC_APA_FPA_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S194>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_g = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S79>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_g = TeAP_e_FiltdGearState_Neutral;

  /* InitializeConditions for UnitDelay: '<S79>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_i = TeAP_e_FiltdGearState_Neutral;

  /* InitializeConditions for UnitDelay: '<S195>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_p = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S193>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_pp = ((uint16_T)200U);

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_jd = true;

  /* InitializeConditions for UnitDelay: '<S81>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_j = TeVBII_e_PamChimeVol_Medium;

  /* InitializeConditions for UnitDelay: '<S109>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_bv = true;

  /* SystemInitialize for Enabled SubSystem: '<S52>/FPA_GraphicAlertGen' */
  /* SystemInitialize for Chart: '<S157>/DNNCheck' */
  SWC_APA_B.MeAP_e_AlertCHF_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertLHF_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertRHF_Raw = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_DW.IsDnnHeightLow_prev = SWC_APA_DW.IsDnnHeightLow;
  SWC_APA_DW.IsDnnHeightLow_start = SWC_APA_DW.IsDnnHeightLow;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_AlertCHF' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertCHF = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_GraphicCHF' */
  SWC_APA_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SNA;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_AlertLHF' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertLHF = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_GraphicLHF' */
  SWC_APA_B.MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SNA;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_AlertRHF' */
  SWC_APA_B.OutportBufferForMeAP_e_AlertRHF = TeAP_e_Alert_SNA;

  /* SystemInitialize for Outport: '<S82>/MeAP_e_GraphicRHF' */
  SWC_APA_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SNA;

  /* End of SystemInitialize for SubSystem: '<S52>/FPA_GraphicAlertGen' */

  /* SystemInitialize for Chart: '<S83>/AlertFilterCHF' */
  SWC_APA_DW.LastChanged_Alert_Raw_c = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertCHF = TeAP_e_Alert_NoObjectDetected;

  /* SystemInitialize for Chart: '<S83>/AlertFilterLHF' */
  SWC_APA_DW.LastChanged_Alert_Raw_i = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertLHF = TeAP_e_Alert_NoObjectDetected;

  /* SystemInitialize for Chart: '<S83>/AlertFilterRHF' */
  SWC_APA_DW.LastChanged_Alert_Raw_a = TeAP_e_Alert_NoObjectDetected;
  SWC_APA_B.MeAP_e_AlertRHF = TeAP_e_Alert_NoObjectDetected;
}

/* Disable for atomic system: '<S6>/FPA' */
void SWC_APA_FPA_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S52>/FPA_GraphicAlertGen' */
  if (SWC_APA_DW.FPA_GraphicAlertGen_MODE) {
    /* Disable for Outport: '<S82>/MeAP_e_AlertCHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHF = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S82>/MeAP_e_GraphicCHF' */
    SWC_APA_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SNA;

    /* Disable for Outport: '<S82>/MeAP_e_AlertLHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHF = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S82>/MeAP_e_GraphicLHF' */
    SWC_APA_B.MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SNA;

    /* Disable for Outport: '<S82>/MeAP_e_AlertRHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHF = TeAP_e_Alert_SNA;

    /* Disable for Outport: '<S82>/MeAP_e_GraphicRHF' */
    SWC_APA_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SNA;
    SWC_APA_DW.FPA_GraphicAlertGen_MODE = false;
  }

  /* End of Disable for SubSystem: '<S52>/FPA_GraphicAlertGen' */

  /* Disable for Enabled SubSystem: '<S52>/FPA_ChimeAlertGen' */
  if (SWC_APA_DW.FPA_ChimeAlertGen_MODE) {
    /* Disable for Outport: '<S80>/MeAP_b_ChimeActvLHF' */
    SWC_APA_B.MeAP_b_ChimeActvLHF_h = false;

    /* Disable for Outport: '<S80>/MeAP_b_ChimeActvRHF' */
    SWC_APA_B.MeAP_b_ChimeActvRHF_k = false;

    /* Disable for Outport: '<S80>/MeAP_e_LtFrntChimeRepnRate' */
    SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_l =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;

    /* Disable for Outport: '<S80>/MeAP_e_RtFrntChimeRepnRate' */
    SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_n =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    SWC_APA_DW.FPA_ChimeAlertGen_MODE = false;
  }

  /* End of Disable for SubSystem: '<S52>/FPA_ChimeAlertGen' */
}

/* Output and update for atomic system: '<S6>/FPA' */
void SWC_APA_FPA(void)
{
  int32_T tmp;
  boolean_T RelationalOperator4_m_tmp;
  boolean_T guard1 = false;

  /* Outputs for Enabled SubSystem: '<S52>/FPA_GraphicAlertGen' incorporates:
   *  EnablePort: '<S82>/Enable'
   */
  if (*SWC_APA_rty_MeAP_b_FPAStatus) {
    SWC_APA_DW.FPA_GraphicAlertGen_MODE = true;

    /* RelationalOperator: '<S156>/Relational Operator3' incorporates:
     *  Constant: '<S156>/Constant3'
     */
    SWC_APA_B.RelationalOperator3_o = (*SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist <=
      KeAP_cm_FrntDistZone4);

    /* RelationalOperator: '<S156>/Relational Operator2' incorporates:
     *  Constant: '<S156>/Constant2'
     */
    SWC_APA_B.RelationalOperator2_a = (*SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist <=
      KeAP_cm_FrntDistZone3);

    /* RelationalOperator: '<S156>/Relational Operator1' incorporates:
     *  Constant: '<S156>/Constant1'
     */
    SWC_APA_B.RelationalOperator1_py = (*SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist <=
      KeAP_cm_FrntDistZone2);

    /* RelationalOperator: '<S170>/Relational Operator4' incorporates:
     *  Constant: '<S170>/Constant5'
     */
    SWC_APA_B.RelationalOperator1_mc = (*SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist <=
      100.0F);

    /* Logic: '<S170>/Logical Operator1' */
    SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.RelationalOperator1_mc;

    /* Lookup_n-D: '<S170>/1-D Lookup Table' */
    SWC_APA_B.uDLookupTable_p = look1_iflftu16Df_binlcpw
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig,
       rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData, 5U);

    /* S-Function (sfix_bitop): '<S156>/Bitwise Operator' */
    SWC_APA_B.IsFrntWall = (uint8_T)(*SWC_APA_rtu_MeAP_b_IsWall & ((uint8_T)1U));

    /* Logic: '<S170>/Logical Operator' */
    SWC_APA_B.LogicalOperator_k = ((SWC_APA_B.IsFrntWall != 0) &&
      SWC_APA_B.RelationalOperator1_mc);

    /* Outputs for Atomic SubSystem: '<S170>/Turn On Delay Time' */
    /* Logic: '<S172>/OR1' */
    SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.LogicalOperator_k;

    /* Outputs for Atomic SubSystem: '<S172>/EdgeRising1' */
    /* UnitDelay: '<S173>/Unit Delay' */
    SWC_APA_B.RelationalOperator4_m = SWC_APA_DW.UnitDelay_DSTATE_n;

    /* Logic: '<S173>/OR1' */
    SWC_APA_B.RelationalOperator4_m = !SWC_APA_B.RelationalOperator4_m;

    /* Logic: '<S173>/AND' */
    SWC_APA_B.AND_pp = (SWC_APA_B.LogicalOperator_k &&
                        SWC_APA_B.RelationalOperator4_m);

    /* Update for UnitDelay: '<S173>/Unit Delay' */
    SWC_APA_DW.UnitDelay_DSTATE_n = SWC_APA_B.LogicalOperator_k;

    /* End of Outputs for SubSystem: '<S172>/EdgeRising1' */

    /* Logic: '<S172>/OR' */
    SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
      SWC_APA_B.AND_pp);

    /* UnitDelay: '<S172>/Unit Delay' */
    SWC_APA_B.UnitDelay_kx = SWC_APA_B.Switch1_gi;

    /* Switch: '<S172>/Switch1' incorporates:
     *  Constant: '<S172>/Constant Value1'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.Switch1_gi = ((uint16_T)0U);
    } else {
      /* Sum: '<S172>/Summation' incorporates:
       *  Constant: '<S170>/Constant4'
       */
      SWC_APA_B.Summation_p = (uint16_T)((uint32_T)((uint16_T)30U) +
        SWC_APA_B.UnitDelay_kx);

      /* MinMax: '<S172>/Minimum' */
      if (SWC_APA_B.uDLookupTable_p < SWC_APA_B.Summation_p) {
        SWC_APA_B.Minimum_l = SWC_APA_B.uDLookupTable_p;
      } else {
        SWC_APA_B.Minimum_l = SWC_APA_B.Summation_p;
      }

      /* End of MinMax: '<S172>/Minimum' */
      SWC_APA_B.Switch1_gi = SWC_APA_B.Minimum_l;
    }

    /* End of Switch: '<S172>/Switch1' */

    /* RelationalOperator: '<S172>/Greater  Than' */
    SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch1_gi >=
      SWC_APA_B.uDLookupTable_p);

    /* Logic: '<S172>/AND' */
    SWC_APA_B.AND_kt = (SWC_APA_B.LogicalOperator_k &&
                        SWC_APA_B.RelationalOperator1_mc);

    /* End of Outputs for SubSystem: '<S170>/Turn On Delay Time' */

    /* UnitDelay: '<S171>/Unit Delay' */
    SWC_APA_B.UnitDelay_dh = SWC_APA_DW.UnitDelay_DSTATE_gq;

    /* Switch: '<S171>/Switch5' incorporates:
     *  Constant: '<S171>/Constant'
     *  Switch: '<S171>/Switch6'
     */
    if (SWC_APA_B.LogicalOperator2_n) {
      SWC_APA_B.Switch5_a3 = false;
    } else {
      if (SWC_APA_B.AND_kt) {
        /* Switch: '<S171>/Switch6' incorporates:
         *  Constant: '<S171>/Constant1'
         */
        SWC_APA_B.Switch6_l = true;
      } else {
        /* Switch: '<S171>/Switch6' */
        SWC_APA_B.Switch6_l = SWC_APA_B.UnitDelay_dh;
      }

      SWC_APA_B.Switch5_a3 = SWC_APA_B.Switch6_l;
    }

    /* End of Switch: '<S171>/Switch5' */

    /* Logic: '<S156>/Logical Operator' incorporates:
     *  Constant: '<S156>/Constant5'
     */
    SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch5_a3 &&
      KeAP_b_EnWallAcurracy);

    /* Switch: '<S156>/Switch5' incorporates:
     *  Constant: '<S156>/Constant4'
     *  Switch: '<S156>/Switch4'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.Switch7 = *SWC_APA_rtu_MeAP_cm_WallFrntCenterDist;

      /* Sum: '<S156>/Subtract' incorporates:
       *  Constant: '<S156>/Constant4'
       *  Constant: '<S156>/Constant9'
       */
      SWC_APA_B.Subtract_mz = (real32_T)KeAP_cm_FrntDistZone1 -
        KeAP_cm_FrntWallZone1Adj;
      SWC_APA_B.Zone1 = SWC_APA_B.Subtract_mz;
    } else {
      SWC_APA_B.Switch7 = *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist;
      SWC_APA_B.Zone1 = KeAP_cm_FrntDistZone1;
    }

    /* End of Switch: '<S156>/Switch5' */

    /* RelationalOperator: '<S156>/Relational Operator' */
    SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch7 <= SWC_APA_B.Zone1);

    /* Switch generated from: '<S156>/Switch' incorporates:
     *  Constant: '<S166>/Constant'
     *  Switch generated from: '<S156>/Switch1'
     *  Switch generated from: '<S156>/Switch2'
     *  Switch generated from: '<S156>/Switch3'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.MeAP_e_AlertCHF_p = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_py) {
        /* Switch generated from: '<S156>/Switch1' incorporates:
         *  Constant: '<S160>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertCHF_h = TeAP_e_Alert_Arc2;
      } else {
        if (SWC_APA_B.RelationalOperator2_a) {
          /* Switch generated from: '<S156>/Switch2' incorporates:
           *  Constant: '<S163>/Constant'
           *  Switch generated from: '<S156>/Switch1'
           */
          SWC_APA_B.MeAP_e_AlertCHF_b = TeAP_e_Alert_Arc3;
        } else {
          if (SWC_APA_B.RelationalOperator3_o) {
            /* Switch generated from: '<S156>/Switch3' incorporates:
             *  Constant: '<S165>/Constant'
             *  Switch generated from: '<S156>/Switch1'
             *  Switch generated from: '<S156>/Switch2'
             */
            SWC_APA_B.MeAP_e_AlertCHF_f = TeAP_e_Alert_Arc4;
          } else {
            /* Switch generated from: '<S156>/Switch3' incorporates:
             *  Constant: '<S169>/Constant'
             *  Switch generated from: '<S156>/Switch1'
             *  Switch generated from: '<S156>/Switch2'
             */
            SWC_APA_B.MeAP_e_AlertCHF_f = TeAP_e_Alert_NoObjectDetected;
          }

          /* Switch generated from: '<S156>/Switch2' incorporates:
           *  Switch generated from: '<S156>/Switch1'
           */
          SWC_APA_B.MeAP_e_AlertCHF_b = SWC_APA_B.MeAP_e_AlertCHF_f;
        }

        /* Switch generated from: '<S156>/Switch1' incorporates:
         *  Switch generated from: '<S156>/Switch2'
         *  Switch generated from: '<S156>/Switch3'
         */
        SWC_APA_B.MeAP_e_AlertCHF_h = SWC_APA_B.MeAP_e_AlertCHF_b;
      }

      SWC_APA_B.MeAP_e_AlertCHF_p = SWC_APA_B.MeAP_e_AlertCHF_h;
    }

    /* RelationalOperator: '<S158>/Relational Operator' incorporates:
     *  Constant: '<S158>/Constant'
     */
    SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist <=
      KeAP_cm_FrntDistZone1);

    /* RelationalOperator: '<S158>/Relational Operator1' incorporates:
     *  Constant: '<S158>/Constant1'
     */
    SWC_APA_B.RelationalOperator1_cr = (*SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist <=
      KeAP_cm_FrntDistZone2);

    /* Switch generated from: '<S158>/Switch' incorporates:
     *  Constant: '<S178>/Constant'
     *  Switch generated from: '<S158>/Switch1'
     */
    if (SWC_APA_B.LogicalOperator2_n) {
      SWC_APA_B.MeAP_e_AlertLHF_i = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_cr) {
        /* Switch generated from: '<S158>/Switch1' incorporates:
         *  Constant: '<S175>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertLHF_o = TeAP_e_Alert_Arc2;
      } else {
        /* Switch generated from: '<S158>/Switch1' incorporates:
         *  Constant: '<S180>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertLHF_o = TeAP_e_Alert_NoObjectDetected;
      }

      SWC_APA_B.MeAP_e_AlertLHF_i = SWC_APA_B.MeAP_e_AlertLHF_o;
    }

    /* RelationalOperator: '<S159>/Relational Operator' incorporates:
     *  Constant: '<S159>/Constant'
     */
    SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rtu_MeAP_cm_FrntRightMinXDist <=
      KeAP_cm_FrntDistZone1);

    /* RelationalOperator: '<S159>/Relational Operator1' incorporates:
     *  Constant: '<S159>/Constant1'
     */
    SWC_APA_B.RelationalOperator1_i = (*SWC_APA_rtu_MeAP_cm_FrntRightMinXDist <=
      KeAP_cm_FrntDistZone2);

    /* Switch generated from: '<S159>/Switch' incorporates:
     *  Constant: '<S184>/Constant'
     *  Switch generated from: '<S159>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator4_m) {
      SWC_APA_B.MeAP_e_AlertRHF_n = TeAP_e_Alert_Arc1;
    } else {
      if (SWC_APA_B.RelationalOperator1_i) {
        /* Switch generated from: '<S159>/Switch1' incorporates:
         *  Constant: '<S181>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertRHF_b = TeAP_e_Alert_Arc2;
      } else {
        /* Switch generated from: '<S159>/Switch1' incorporates:
         *  Constant: '<S186>/Constant'
         */
        SWC_APA_B.MeAP_e_AlertRHF_b = TeAP_e_Alert_NoObjectDetected;
      }

      SWC_APA_B.MeAP_e_AlertRHF_n = SWC_APA_B.MeAP_e_AlertRHF_b;
    }

    /* Chart: '<S157>/DNNCheck' */
    SWC_APA_DW.IsDnnHeightLow_prev = SWC_APA_DW.IsDnnHeightLow_start;
    SWC_APA_DW.IsDnnHeightLow_start = SWC_APA_DW.IsDnnHeightLow;
    SWC_APA_DW.MeAP_b_HighPointsPresentFront_prev =
      SWC_APA_DW.MeAP_b_HighPointsPresentFront_start;
    SWC_APA_DW.MeAP_b_HighPointsPresentFront_start =
      *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront;
    if (!SWC_APA_DW.doneDoubleBufferReInit_o) {
      SWC_APA_DW.doneDoubleBufferReInit_o = true;
      SWC_APA_DW.MeAP_b_HighPointsPresentFront_prev =
        *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront;
    }
	//Keep++
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertCHF_p,3);
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertLHF_i,4);
    UssOD_setArcSignal(SWC_APA_B.MeAP_e_AlertRHF_n,5);
	  //Keep--
    SWC_APA_B.MeAP_e_AlertCHF_Raw = SWC_APA_B.MeAP_e_AlertCHF_p;
    SWC_APA_B.MeAP_e_AlertLHF_Raw = SWC_APA_B.MeAP_e_AlertLHF_i;
    SWC_APA_B.MeAP_e_AlertRHF_Raw = SWC_APA_B.MeAP_e_AlertRHF_n;
    SWC_APA_DW.IsDnnHeightLow = UssOD_bIsLowObject(US_D_PHYS_GRP_FRNT);//Keep

    /* UssOD_bIsLowObject(US_D_PHYS_GRP_FRNT) */
    if (((SWC_APA_DW.IsDnnHeightLow_prev != SWC_APA_DW.IsDnnHeightLow_start) &&
         (SWC_APA_DW.IsDnnHeightLow_start == 1)) ||
        ((SWC_APA_DW.MeAP_b_HighPointsPresentFront_prev !=
          SWC_APA_DW.MeAP_b_HighPointsPresentFront_start) &&
         (SWC_APA_DW.MeAP_b_HighPointsPresentFront_start == 0))) {
      SWC_APA_DW.prev_AlertCHF = (uint32_T)SWC_APA_B.MeAP_e_AlertCHF_p;
      SWC_APA_DW.DNN_Latch_d = true;
    }

    /*   */
    SWC_APA_DW.DNN_Latch_d = (((!SWC_APA_DW.DNN_Latch_d) ||
      ((SWC_APA_DW.prev_AlertCHF - (uint32_T)SWC_APA_B.MeAP_e_AlertCHF_p < 2U) &&
       (SWC_APA_DW.IsDnnHeightLow != 0) &&
       (*SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront
        != 1))) && SWC_APA_DW.DNN_Latch_d);
    if ((SWC_APA_DW.IsDnnHeightLow == 1) && (!SWC_APA_DW.DNN_Latch_d) &&
        (*SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront
         == 0)) {
      /* Ignore DNN Flag for center */
      SWC_APA_B.MeAP_e_AlertCHF_Raw = TeAP_e_Alert_NoObjectDetected;
    }

    if (SWC_APA_DW.IsDnnHeightLow == 1) {
      if ((KePA_b_EnHeightFlagFrontSideArcs != 0) &&
          (*SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL
           == 0)) {
        SWC_APA_B.MeAP_e_AlertLHF_Raw = TeAP_e_Alert_NoObjectDetected;
      }

      if ((KePA_b_EnHeightFlagFrontSideArcs != 0) &&
          (*SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR
           == 0)) {
        SWC_APA_B.MeAP_e_AlertRHF_Raw = TeAP_e_Alert_NoObjectDetected;
      }
    }

    /* End of Chart: '<S157>/DNNCheck' */

    /* SignalConversion generated from: '<S82>/MeAP_e_AlertCHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHF = SWC_APA_B.MeAP_e_AlertCHF_Raw;

    /* SignalConversion generated from: '<S82>/MeAP_e_AlertLHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHF = SWC_APA_B.MeAP_e_AlertLHF_Raw;

    /* SignalConversion generated from: '<S82>/MeAP_e_AlertRHF' */
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHF = SWC_APA_B.MeAP_e_AlertRHF_Raw;

    /* Switch generated from: '<S159>/Switch' incorporates:
     *  Constant: '<S185>/Constant'
     *  Switch generated from: '<S159>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator4_m) {
      SWC_APA_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_i) {
        /* Switch generated from: '<S159>/Switch1' incorporates:
         *  Constant: '<S183>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicRHF_i = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        /* Switch generated from: '<S159>/Switch1' incorporates:
         *  Constant: '<S182>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicRHF_i = TeAP_e_GraphicFlshRate_None;
      }

      SWC_APA_B.MeAP_e_GraphicRHF = SWC_APA_B.MeAP_e_GraphicRHF_i;
    }

    /* Switch generated from: '<S158>/Switch' incorporates:
     *  Constant: '<S179>/Constant'
     *  Switch generated from: '<S158>/Switch1'
     */
    if (SWC_APA_B.LogicalOperator2_n) {
      SWC_APA_B.MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_cr) {
        /* Switch generated from: '<S158>/Switch1' incorporates:
         *  Constant: '<S177>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicLHF_j = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        /* Switch generated from: '<S158>/Switch1' incorporates:
         *  Constant: '<S176>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicLHF_j = TeAP_e_GraphicFlshRate_None;
      }

      SWC_APA_B.MeAP_e_GraphicLHF = SWC_APA_B.MeAP_e_GraphicLHF_j;
    }

    /* Switch generated from: '<S156>/Switch' incorporates:
     *  Constant: '<S167>/Constant'
     *  Switch generated from: '<S156>/Switch1'
     *  Switch generated from: '<S156>/Switch2'
     *  Switch generated from: '<S156>/Switch3'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SlowFlash;
    } else {
      if (SWC_APA_B.RelationalOperator1_py) {
        /* Switch generated from: '<S156>/Switch1' incorporates:
         *  Constant: '<S162>/Constant'
         */
        SWC_APA_B.MeAP_e_GraphicCHF_a = TeAP_e_GraphicFlshRate_SlowFlash;
      } else {
        if (SWC_APA_B.RelationalOperator2_a) {
          /* Switch generated from: '<S156>/Switch2' incorporates:
           *  Constant: '<S164>/Constant'
           *  Switch generated from: '<S156>/Switch1'
           */
          SWC_APA_B.MeAP_e_GraphicCHF_l = TeAP_e_GraphicFlshRate_SlowFlash;
        } else {
          if (SWC_APA_B.RelationalOperator3_o) {
            /* Switch generated from: '<S156>/Switch3' incorporates:
             *  Constant: '<S168>/Constant'
             *  Switch generated from: '<S156>/Switch1'
             *  Switch generated from: '<S156>/Switch2'
             */
            SWC_APA_B.MeAP_e_GraphicCHF_i = TeAP_e_GraphicFlshRate_Solid;
          } else {
            /* Switch generated from: '<S156>/Switch3' incorporates:
             *  Constant: '<S161>/Constant'
             *  Switch generated from: '<S156>/Switch1'
             *  Switch generated from: '<S156>/Switch2'
             */
            SWC_APA_B.MeAP_e_GraphicCHF_i = TeAP_e_GraphicFlshRate_None;
          }

          /* Switch generated from: '<S156>/Switch2' incorporates:
           *  Switch generated from: '<S156>/Switch1'
           */
          SWC_APA_B.MeAP_e_GraphicCHF_l = SWC_APA_B.MeAP_e_GraphicCHF_i;
        }

        /* Switch generated from: '<S156>/Switch1' incorporates:
         *  Switch generated from: '<S156>/Switch2'
         *  Switch generated from: '<S156>/Switch3'
         */
        SWC_APA_B.MeAP_e_GraphicCHF_a = SWC_APA_B.MeAP_e_GraphicCHF_l;
      }

      SWC_APA_B.MeAP_e_GraphicCHF = SWC_APA_B.MeAP_e_GraphicCHF_a;
    }

    /* Update for UnitDelay: '<S171>/Unit Delay' */
    SWC_APA_DW.UnitDelay_DSTATE_gq = SWC_APA_B.Switch5_a3;
  } else {
    if (SWC_APA_DW.FPA_GraphicAlertGen_MODE) {
      /* Disable for Outport: '<S82>/MeAP_e_AlertCHF' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertCHF = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S82>/MeAP_e_GraphicCHF' */
      SWC_APA_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SNA;

      /* Disable for Outport: '<S82>/MeAP_e_AlertLHF' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertLHF = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S82>/MeAP_e_GraphicLHF' */
      SWC_APA_B.MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SNA;

      /* Disable for Outport: '<S82>/MeAP_e_AlertRHF' */
      SWC_APA_B.OutportBufferForMeAP_e_AlertRHF = TeAP_e_Alert_SNA;

      /* Disable for Outport: '<S82>/MeAP_e_GraphicRHF' */
      SWC_APA_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SNA;
      SWC_APA_DW.FPA_GraphicAlertGen_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S52>/FPA_GraphicAlertGen' */

  /* Chart: '<S83>/AlertFilterCHF' */
  SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev = SWC_APA_DW.MeAP_e_AlertCHF_Raw_start;
  SWC_APA_DW.MeAP_e_AlertCHF_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
  if (SWC_APA_DW.is_active_c7_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
    SWC_APA_DW.is_active_c7_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw_c = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c7_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
    SWC_APA_B.MeAP_e_AlertCHF = SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
  } else if (SWC_APA_DW.is_c7_SWC_APA == SWC_APA_IN_HOLD_OUTPUT) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertCHF_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF !=
                SWC_APA_DW.LastChanged_Alert_Raw_c) &&
               (SWC_APA_DW.LastChanged_Alert_Raw_c !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c7_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
      SWC_APA_DW.LastChanged_Alert_Raw_c =
        SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
      SWC_APA_DW.count_k = 0U;
    } else if ((SWC_APA_DW.count_k >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertCHF !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw_c ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertCHF != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertCHF != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count_k >= 5)
                && (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
                    1.0F))) {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count_k + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count_k = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c7_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertCHF = SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF > SWC_APA_B.MeAP_e_AlertCHF)
         && (SWC_APA_CheckHystDistZoneInc((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertCHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertCHF < SWC_APA_B.MeAP_e_AlertCHF)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertCHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHF_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c7_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertCHF = SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF >
            SWC_APA_B.MeAP_e_AlertCHF) && (SWC_APA_CheckHystDistZoneInc((real_T)
             (int32_T)SWC_APA_B.MeAP_e_AlertCHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertCHF_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertCHF_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertCHF_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertCHF_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertCHF != TeAP_e_Alert_Arc4)) ||
          ((SWC_APA_B.MeAP_e_AlertCHF == TeAP_e_Alert_Arc4) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertCHF ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertCHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist) != 0.0))) {
        SWC_APA_DW.is_c7_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
        SWC_APA_DW.LastChanged_Alert_Raw_c =
          SWC_APA_B.OutportBufferForMeAP_e_AlertCHF;
        SWC_APA_DW.count_k = 0U;
      }
    }
  }

  /* End of Chart: '<S83>/AlertFilterCHF' */

  /* Chart: '<S83>/AlertFilterLHF' */
  SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev = SWC_APA_DW.MeAP_e_AlertLHF_Raw_start;
  SWC_APA_DW.MeAP_e_AlertLHF_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
  if (SWC_APA_DW.is_active_c9_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
    SWC_APA_DW.is_active_c9_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw_i = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c9_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
    SWC_APA_B.MeAP_e_AlertLHF = SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
  } else if (SWC_APA_DW.is_c9_SWC_APA == SWC_APA_IN_HOLD_OUTPUT) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertLHF_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF !=
                SWC_APA_DW.LastChanged_Alert_Raw_i) &&
               (SWC_APA_DW.LastChanged_Alert_Raw_i !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c9_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
      SWC_APA_DW.LastChanged_Alert_Raw_i =
        SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
      SWC_APA_DW.count_b = 0U;
    } else if ((SWC_APA_DW.count_b >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertLHF !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw_i ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertLHF != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertLHF != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count_b >= 5)
                && (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
                    1.0F))) {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count_b + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count_b = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c9_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertLHF = SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF > SWC_APA_B.MeAP_e_AlertLHF)
         && (SWC_APA_CheckHystDistZoneInc_m((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertLHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertLHF < SWC_APA_B.MeAP_e_AlertLHF)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec_l
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHF_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c9_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertLHF = SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF >
            SWC_APA_B.MeAP_e_AlertLHF) && (SWC_APA_CheckHystDistZoneInc_m
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertLHF_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertLHF_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertLHF_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertLHF_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertLHF != TeAP_e_Alert_Arc2)) ||
          ((SWC_APA_B.MeAP_e_AlertLHF == TeAP_e_Alert_Arc2) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertLHF ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc_m
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertLHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist) != 0.0))) {
        SWC_APA_DW.is_c9_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
        SWC_APA_DW.LastChanged_Alert_Raw_i =
          SWC_APA_B.OutportBufferForMeAP_e_AlertLHF;
        SWC_APA_DW.count_b = 0U;
      }
    }
  }

  /* End of Chart: '<S83>/AlertFilterLHF' */

  /* Chart: '<S83>/AlertFilterRHF' */
  SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev = SWC_APA_DW.MeAP_e_AlertRHF_Raw_start;
  SWC_APA_DW.MeAP_e_AlertRHF_Raw_start =
    SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
  if (SWC_APA_DW.is_active_c14_SWC_APA == 0U) {
    SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev =
      SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
    SWC_APA_DW.is_active_c14_SWC_APA = 1U;
    SWC_APA_DW.LastChanged_Alert_Raw_a = TeAP_e_Alert_SNA;
    SWC_APA_DW.is_c14_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
    SWC_APA_B.MeAP_e_AlertRHF = SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
  } else if (SWC_APA_DW.is_c14_SWC_APA == SWC_APA_IN_HOLD_OUTPUT) {
    guard1 = false;
    if ((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
         SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
        (SWC_APA_DW.MeAP_e_AlertRHF_Raw_start == TeAP_e_Alert_SNA)) {
      guard1 = true;
    } else if ((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
                SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
               (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF !=
                SWC_APA_DW.LastChanged_Alert_Raw_a) &&
               (SWC_APA_DW.LastChanged_Alert_Raw_a !=
                TeAP_e_Alert_NoObjectDetected)) {
      SWC_APA_DW.is_c14_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
      SWC_APA_DW.LastChanged_Alert_Raw_a =
        SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
      SWC_APA_DW.count_f = 0U;
    } else if ((SWC_APA_DW.count_f >= 60) ||
               ((((SWC_APA_B.OutportBufferForMeAP_e_AlertRHF !=
                   TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_DW.LastChanged_Alert_Raw_a ==
                   TeAP_e_Alert_NoObjectDetected)) ||
                 ((SWC_APA_B.MeAP_e_AlertRHF != TeAP_e_Alert_NoObjectDetected) &&
                  (SWC_APA_B.MeAP_e_AlertRHF != TeAP_e_Alert_Arc1) &&
                  (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF ==
                   TeAP_e_Alert_NoObjectDetected))) && (SWC_APA_DW.count_f >= 5)
                && (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
                    1.0F))) {
      guard1 = true;
    } else {
      tmp = SWC_APA_DW.count_f + 3;
      if (tmp > 255) {
        tmp = 255;
      }

      SWC_APA_DW.count_f = (uint8_T)tmp;
    }

    if (guard1) {
      SWC_APA_DW.is_c14_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertRHF = SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
    }
  } else {
    /* case IN_UPDATE_OUTPUT: */
    if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 1.0F) &&
         (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF > SWC_APA_B.MeAP_e_AlertRHF)
         && (SWC_APA_CheckHystDistZoneInc_m((real_T)(int32_T)
           SWC_APA_B.MeAP_e_AlertRHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist) != 0.0)) ||
        ((SWC_APA_B.OutportBufferForMeAP_e_AlertRHF < SWC_APA_B.MeAP_e_AlertRHF)
         && (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF !=
             TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneDec_l
          ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHF, (real_T)
           *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist) != 0.0)) ||
        (((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHF_Raw_start == TeAP_e_Alert_SNA)) ||
         ((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
           SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
          (SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev == TeAP_e_Alert_NoObjectDetected))))
    {
      SWC_APA_DW.is_c14_SWC_APA = SWC_APA_IN_UPDATE_OUTPUT;
      SWC_APA_B.MeAP_e_AlertRHF = SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
    } else {
      if (((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 1.0F) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF >
            SWC_APA_B.MeAP_e_AlertRHF) && (SWC_APA_CheckHystDistZoneInc_m
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist) != 0.0)) ||
          ((SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
            SWC_APA_DW.MeAP_e_AlertRHF_Raw_start) &&
           (SWC_APA_DW.MeAP_e_AlertRHF_Raw_start ==
            TeAP_e_Alert_NoObjectDetected) &&
           ((!(SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev !=
               SWC_APA_DW.MeAP_e_AlertRHF_Raw_start)) ||
            (!(SWC_APA_DW.MeAP_e_AlertRHF_Raw_prev == TeAP_e_Alert_SNA))) &&
           (SWC_APA_B.MeAP_e_AlertRHF != TeAP_e_Alert_Arc2)) ||
          ((SWC_APA_B.MeAP_e_AlertRHF == TeAP_e_Alert_Arc2) &&
           (SWC_APA_B.OutportBufferForMeAP_e_AlertRHF ==
            TeAP_e_Alert_NoObjectDetected) && (SWC_APA_CheckHystDistZoneInc_m
            ((real_T)(int32_T)SWC_APA_B.MeAP_e_AlertRHF, (real_T)
             *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist) != 0.0))) {
        SWC_APA_DW.is_c14_SWC_APA = SWC_APA_IN_HOLD_OUTPUT;
        SWC_APA_DW.LastChanged_Alert_Raw_a =
          SWC_APA_B.OutportBufferForMeAP_e_AlertRHF;
        SWC_APA_DW.count_f = 0U;
      }
    }
  }

  /* End of Chart: '<S83>/AlertFilterRHF' */

  /* UnitDelay: '<S194>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_g;

  /* UnitDelay: '<S194>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_B.Switch5_ct;

  /* Switch: '<S194>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch4_c = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S194>/Relational Operator1' incorporates:
     *  Constant: '<S194>/Constant'
     */
    SWC_APA_B.RelationalOperator1_mwk =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S194>/Relational Operator5' incorporates:
     *  Constant: '<S222>/Constant'
     */
    SWC_APA_B.RelationalOperator5_c =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S194>/Relational Operator4' incorporates:
     *  Constant: '<S221>/Constant'
     */
    SWC_APA_B.LogicalOperator_e =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S194>/Logical Operator' */
    SWC_APA_B.LogicalOperator_e = (SWC_APA_B.LogicalOperator_e &&
      SWC_APA_B.RelationalOperator5_c && SWC_APA_B.RelationalOperator1_mwk);

    /* Switch: '<S194>/Switch3' incorporates:
     *  Constant: '<S194>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_e) {
      SWC_APA_B.Switch3_o = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S194>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S194>/Constant5'
       *  Constant: '<S194>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S194>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic_d),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.Switch3_o = SWC_APA_B.LookupTableDynamic_d;
    }

    /* End of Switch: '<S194>/Switch3' */
    SWC_APA_B.Switch4_c = SWC_APA_B.Switch3_o;
  }

  /* End of Switch: '<S194>/Switch4' */

  /* RelationalOperator: '<S194>/Relational Operator' incorporates:
   *  Constant: '<S218>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_e_AlertRHF ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S194>/Relational Operator2' incorporates:
   *  Constant: '<S219>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.MeAP_e_AlertRHF == TeAP_e_Alert_SNA);

  /* Logic: '<S194>/Logical Operator1' */
  SWC_APA_B.LogicalOperator1_l = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S194>/Unit Delay' */
  SWC_APA_B.UnitDelay_km = SWC_APA_DW.UnitDelay_DSTATE_pz;

  /* UnitDelay: '<S225>/Unit Delay' */
  SWC_APA_B.UnitDelay_cf = SWC_APA_DW.UnitDelay_DSTATE_ge;

  /* Switch: '<S225>/Switch5' incorporates:
   *  Constant: '<S225>/Constant'
   */
  if (SWC_APA_B.LogicalOperator1_l) {
    SWC_APA_B.Switch5_ct = false;
  } else {
    /* Logic: '<S194>/OR1' */
    SWC_APA_B.AND_j = !SWC_APA_B.LogicalOperator1_l;

    /* Logic: '<S194>/AND' */
    SWC_APA_B.AND_j = (SWC_APA_B.UnitDelay_km && SWC_APA_B.AND_j);

    /* Switch: '<S225>/Switch6' incorporates:
     *  Constant: '<S225>/Constant1'
     */
    if (SWC_APA_B.AND_j) {
      SWC_APA_B.Switch6_gd = true;
    } else {
      SWC_APA_B.Switch6_gd = SWC_APA_B.UnitDelay_cf;
    }

    /* End of Switch: '<S225>/Switch6' */
    SWC_APA_B.Switch5_ct = SWC_APA_B.Switch6_gd;
  }

  /* End of Switch: '<S225>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S194>/Turn On Delay Time' */
  /* Logic: '<S226>/OR1' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.Switch5_ct;

  /* Outputs for Atomic SubSystem: '<S226>/EdgeRising1' */
  /* UnitDelay: '<S227>/Unit Delay' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay_DSTATE_or;

  /* Logic: '<S227>/OR1' */
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S227>/AND' */
  SWC_APA_B.AND_e = (SWC_APA_B.Switch5_ct && SWC_APA_B.LogicalOperator2_n);

  /* Update for UnitDelay: '<S227>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_or = SWC_APA_B.Switch5_ct;

  /* End of Outputs for SubSystem: '<S226>/EdgeRising1' */

  /* Logic: '<S226>/OR' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.AND_e);

  /* UnitDelay: '<S226>/Unit Delay' */
  SWC_APA_B.UnitDelay_e = SWC_APA_B.Switch1_nh;

  /* Switch: '<S226>/Switch1' incorporates:
   *  Constant: '<S226>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch1_nh = ((uint16_T)0U);
  } else {
    /* Sum: '<S226>/Summation' incorporates:
     *  Constant: '<S194>/Constant4'
     */
    SWC_APA_B.Summation_jx = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_e);

    /* MinMax: '<S226>/Minimum' */
    if (SWC_APA_B.Switch4_c < SWC_APA_B.Summation_jx) {
      SWC_APA_B.Minimum_b0 = SWC_APA_B.Switch4_c;
    } else {
      SWC_APA_B.Minimum_b0 = SWC_APA_B.Summation_jx;
    }

    /* End of MinMax: '<S226>/Minimum' */
    SWC_APA_B.Switch1_nh = SWC_APA_B.Minimum_b0;
  }

  /* End of Switch: '<S226>/Switch1' */

  /* RelationalOperator: '<S226>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch1_nh >=
    SWC_APA_B.Switch4_c);

  /* Logic: '<S226>/AND' */
  SWC_APA_B.AND_n = (SWC_APA_B.Switch5_ct && SWC_APA_B.RelationalOperator1_mc);

  /* End of Outputs for SubSystem: '<S194>/Turn On Delay Time' */

  /* Switch: '<S194>/Switch' incorporates:
   *  Constant: '<S194>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S194>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_dn = !SWC_APA_B.Switch5_ct;

    /* Logic: '<S194>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_dn = (SWC_APA_B.AND_n ||
      SWC_APA_B.LogicalOperator2_dn);

    /* Switch: '<S194>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_dn) {
      SWC_APA_B.Switch1_ix = SWC_APA_B.MeAP_e_AlertRHF;
    } else {
      /* RelationalOperator: '<S194>/Relational Operator3' incorporates:
       *  Constant: '<S220>/Constant'
       */
      SWC_APA_B.RelationalOperator3_g = (SWC_APA_B.MeAP_e_AlertRHF !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S194>/Switch2' incorporates:
       *  Constant: '<S223>/Constant'
       *  Constant: '<S224>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_g) {
        SWC_APA_B.Switch2_jt = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_jt = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S194>/Switch2' */
      SWC_APA_B.Switch1_ix = SWC_APA_B.Switch2_jt;
    }

    /* End of Switch: '<S194>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertRHF = SWC_APA_B.Switch1_ix;
  } else {
    *SWC_APA_rty_MeAP_e_AlertRHF = SWC_APA_B.MeAP_e_AlertRHF;
  }

  /* End of Switch: '<S194>/Switch' */

  /* UnitDelay: '<S79>/Unit Delay2' */
  SWC_APA_B.UnitDelay1_nu = SWC_APA_DW.UnitDelay2_DSTATE_g;

  /* RelationalOperator: '<S79>/Relational Operator4' incorporates:
   *  Constant: '<S112>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.UnitDelay1_nu ==
    TeAP_e_FiltdGearState_Parking);

  /* RelationalOperator: '<S79>/Relational Operator5' incorporates:
   *  Constant: '<S113>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n =
    (*SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
     TeAP_e_FiltdGearState_ReverseGear);

  /* Logic: '<S79>/Logical Operator1' */
  SWC_APA_B.MeAP_e_FiltdGearP2R = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S79>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_nu = SWC_APA_DW.UnitDelay1_DSTATE_i;

  /* RelationalOperator: '<S79>/Relational Operator1' incorporates:
   *  Constant: '<S110>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.UnitDelay1_nu ==
    TeAP_e_FiltdGearState_Drive);

  /* RelationalOperator: '<S79>/Relational Operator2' incorporates:
   *  Constant: '<S114>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n =
    (*SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
     TeAP_e_FiltdGearState_ReverseGear);

  /* Logic: '<S79>/Logical Operator2' */
  SWC_APA_B.MeAP_e_FiltdGearD2R = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* RelationalOperator: '<S79>/Relational Operator3' incorporates:
   *  Constant: '<S111>/Constant'
   */
  SWC_APA_B.MeAP_e_FiltdGearToDrive =
    (*SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
     TeAP_e_FiltdGearState_Drive);

  /* UnitDelay: '<S195>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_p;

  /* UnitDelay: '<S195>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_B.Switch5_a0;

  /* Switch: '<S195>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch4_esz = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S195>/Relational Operator1' incorporates:
     *  Constant: '<S195>/Constant'
     */
    SWC_APA_B.RelationalOperator1_k =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S195>/Relational Operator5' incorporates:
     *  Constant: '<S232>/Constant'
     */
    SWC_APA_B.RelationalOperator5_d =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S195>/Relational Operator4' incorporates:
     *  Constant: '<S231>/Constant'
     */
    SWC_APA_B.LogicalOperator_j =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S195>/Logical Operator' */
    SWC_APA_B.LogicalOperator_j = (SWC_APA_B.LogicalOperator_j &&
      SWC_APA_B.RelationalOperator5_d && SWC_APA_B.RelationalOperator1_k);

    /* Switch: '<S195>/Switch3' incorporates:
     *  Constant: '<S195>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_j) {
      SWC_APA_B.Switch3_m = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S195>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S195>/Constant5'
       *  Constant: '<S195>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S195>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic_m),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.Switch3_m = SWC_APA_B.LookupTableDynamic_m;
    }

    /* End of Switch: '<S195>/Switch3' */
    SWC_APA_B.Switch4_esz = SWC_APA_B.Switch3_m;
  }

  /* End of Switch: '<S195>/Switch4' */

  /* RelationalOperator: '<S195>/Relational Operator' incorporates:
   *  Constant: '<S228>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_e_AlertCHF ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S195>/Relational Operator2' incorporates:
   *  Constant: '<S229>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.MeAP_e_AlertCHF == TeAP_e_Alert_SNA);

  /* Logic: '<S195>/Logical Operator1' */
  SWC_APA_B.LogicalOperator1_lz = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S195>/Unit Delay' */
  SWC_APA_B.UnitDelay_i = SWC_APA_DW.UnitDelay_DSTATE_fc;

  /* UnitDelay: '<S235>/Unit Delay' */
  SWC_APA_B.UnitDelay_o4 = SWC_APA_DW.UnitDelay_DSTATE_mc;

  /* Switch: '<S235>/Switch5' incorporates:
   *  Constant: '<S235>/Constant'
   */
  if (SWC_APA_B.LogicalOperator1_lz) {
    SWC_APA_B.Switch5_a0 = false;
  } else {
    /* Logic: '<S195>/OR1' */
    SWC_APA_B.AND_pf = !SWC_APA_B.LogicalOperator1_lz;

    /* Logic: '<S195>/AND' */
    SWC_APA_B.AND_pf = (SWC_APA_B.UnitDelay_i && SWC_APA_B.AND_pf);

    /* Switch: '<S235>/Switch6' incorporates:
     *  Constant: '<S235>/Constant1'
     */
    if (SWC_APA_B.AND_pf) {
      SWC_APA_B.Switch6_c = true;
    } else {
      SWC_APA_B.Switch6_c = SWC_APA_B.UnitDelay_o4;
    }

    /* End of Switch: '<S235>/Switch6' */
    SWC_APA_B.Switch5_a0 = SWC_APA_B.Switch6_c;
  }

  /* End of Switch: '<S235>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S195>/Turn On Delay Time' */
  /* Logic: '<S236>/OR1' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.Switch5_a0;

  /* Outputs for Atomic SubSystem: '<S236>/EdgeRising1' */
  /* UnitDelay: '<S237>/Unit Delay' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay_DSTATE_jt;

  /* Logic: '<S237>/OR1' */
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S237>/AND' */
  SWC_APA_B.AND_i = (SWC_APA_B.Switch5_a0 && SWC_APA_B.LogicalOperator2_n);

  /* Update for UnitDelay: '<S237>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_jt = SWC_APA_B.Switch5_a0;

  /* End of Outputs for SubSystem: '<S236>/EdgeRising1' */

  /* Logic: '<S236>/OR' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.AND_i);

  /* UnitDelay: '<S236>/Unit Delay' */
  SWC_APA_B.UnitDelay_c = SWC_APA_B.Switch1_jq;

  /* Switch: '<S236>/Switch1' incorporates:
   *  Constant: '<S236>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch1_jq = ((uint16_T)0U);
  } else {
    /* Sum: '<S236>/Summation' incorporates:
     *  Constant: '<S195>/Constant4'
     */
    SWC_APA_B.Summation_i = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_c);

    /* MinMax: '<S236>/Minimum' */
    if (SWC_APA_B.Switch4_esz < SWC_APA_B.Summation_i) {
      SWC_APA_B.Minimum_k = SWC_APA_B.Switch4_esz;
    } else {
      SWC_APA_B.Minimum_k = SWC_APA_B.Summation_i;
    }

    /* End of MinMax: '<S236>/Minimum' */
    SWC_APA_B.Switch1_jq = SWC_APA_B.Minimum_k;
  }

  /* End of Switch: '<S236>/Switch1' */

  /* RelationalOperator: '<S236>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch1_jq >=
    SWC_APA_B.Switch4_esz);

  /* Logic: '<S236>/AND' */
  SWC_APA_B.AND_d = (SWC_APA_B.Switch5_a0 && SWC_APA_B.RelationalOperator1_mc);

  /* End of Outputs for SubSystem: '<S195>/Turn On Delay Time' */

  /* Switch: '<S195>/Switch' incorporates:
   *  Constant: '<S195>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S195>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_be = !SWC_APA_B.Switch5_a0;

    /* Logic: '<S195>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_be = (SWC_APA_B.AND_d ||
      SWC_APA_B.LogicalOperator2_be);

    /* Switch: '<S195>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_be) {
      SWC_APA_B.Switch1_a2 = SWC_APA_B.MeAP_e_AlertCHF;
    } else {
      /* RelationalOperator: '<S195>/Relational Operator3' incorporates:
       *  Constant: '<S230>/Constant'
       */
      SWC_APA_B.RelationalOperator3_e = (SWC_APA_B.MeAP_e_AlertCHF !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S195>/Switch2' incorporates:
       *  Constant: '<S233>/Constant'
       *  Constant: '<S234>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_e) {
        SWC_APA_B.Switch2_cc = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_cc = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S195>/Switch2' */
      SWC_APA_B.Switch1_a2 = SWC_APA_B.Switch2_cc;
    }

    /* End of Switch: '<S195>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertCHF = SWC_APA_B.Switch1_a2;
  } else {
    *SWC_APA_rty_MeAP_e_AlertCHF = SWC_APA_B.MeAP_e_AlertCHF;
  }

  /* End of Switch: '<S195>/Switch' */

  /* UnitDelay: '<S193>/Unit Delay1' */
  SWC_APA_B.Switch3_co = SWC_APA_DW.UnitDelay1_DSTATE_pp;

  /* UnitDelay: '<S193>/Unit Delay2' */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_B.Switch5_ht;

  /* Switch: '<S193>/Switch4' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch4_f = SWC_APA_B.Switch3_co;
  } else {
    /* RelationalOperator: '<S193>/Relational Operator1' incorporates:
     *  Constant: '<S193>/Constant'
     */
    SWC_APA_B.RelationalOperator1_ip =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <= 0.4F);

    /* RelationalOperator: '<S193>/Relational Operator5' incorporates:
     *  Constant: '<S212>/Constant'
     */
    SWC_APA_B.RelationalOperator5_k =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S193>/Relational Operator4' incorporates:
     *  Constant: '<S211>/Constant'
     */
    SWC_APA_B.LogicalOperator_l =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S193>/Logical Operator' */
    SWC_APA_B.LogicalOperator_l = (SWC_APA_B.LogicalOperator_l &&
      SWC_APA_B.RelationalOperator5_k && SWC_APA_B.RelationalOperator1_ip);

    /* Switch: '<S193>/Switch3' incorporates:
     *  Constant: '<S193>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator_l) {
      SWC_APA_B.Switch3_hv = KeAP_cnt_ArcBlipStandstillTimer;
    } else {
      /* S-Function (sfix_look1_dyn): '<S193>/Lookup Table Dynamic' incorporates:
       *  Constant: '<S193>/Constant5'
       *  Constant: '<S193>/Constant6'
       */
      /* Dynamic Look-Up Table Block: '<S193>/Lookup Table Dynamic'
       * Input0  Data Type:  Floating Point real32_T
       * Input1  Data Type:  Floating Point real32_T
       * Input2  Data Type:  Integer        U16
       * Output0 Data Type:  Integer        U16
       * Lookup Method: Linear_Endpoint
       *
       */
      LookUp_U16_real32_T( &(SWC_APA_B.LookupTableDynamic_f),
                          &KeAP_cnt_ArcBlipVehInMotTimer[0],
                          (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig),
                          &KeAP_cnt_ArcBlipVehSpdThd[0], 5U);
      SWC_APA_B.Switch3_hv = SWC_APA_B.LookupTableDynamic_f;
    }

    /* End of Switch: '<S193>/Switch3' */
    SWC_APA_B.Switch4_f = SWC_APA_B.Switch3_hv;
  }

  /* End of Switch: '<S193>/Switch4' */

  /* RelationalOperator: '<S193>/Relational Operator' incorporates:
   *  Constant: '<S208>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_e_AlertLHF ==
    TeAP_e_Alert_NoObjectDetected);

  /* RelationalOperator: '<S193>/Relational Operator2' incorporates:
   *  Constant: '<S209>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.MeAP_e_AlertLHF == TeAP_e_Alert_SNA);

  /* Logic: '<S193>/Logical Operator1' */
  SWC_APA_B.LogicalOperator1_l5 = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S193>/Unit Delay' */
  SWC_APA_B.UnitDelay_bl = SWC_APA_DW.UnitDelay_DSTATE_bq;

  /* UnitDelay: '<S215>/Unit Delay' */
  SWC_APA_B.UnitDelay_ka = SWC_APA_DW.UnitDelay_DSTATE_av;

  /* Switch: '<S215>/Switch5' incorporates:
   *  Constant: '<S215>/Constant'
   */
  if (SWC_APA_B.LogicalOperator1_l5) {
    SWC_APA_B.Switch5_ht = false;
  } else {
    /* Logic: '<S193>/OR1' */
    SWC_APA_B.AND_it = !SWC_APA_B.LogicalOperator1_l5;

    /* Logic: '<S193>/AND' */
    SWC_APA_B.AND_it = (SWC_APA_B.UnitDelay_bl && SWC_APA_B.AND_it);

    /* Switch: '<S215>/Switch6' incorporates:
     *  Constant: '<S215>/Constant1'
     */
    if (SWC_APA_B.AND_it) {
      SWC_APA_B.Switch6_o = true;
    } else {
      SWC_APA_B.Switch6_o = SWC_APA_B.UnitDelay_ka;
    }

    /* End of Switch: '<S215>/Switch6' */
    SWC_APA_B.Switch5_ht = SWC_APA_B.Switch6_o;
  }

  /* End of Switch: '<S215>/Switch5' */

  /* Outputs for Atomic SubSystem: '<S193>/Turn On Delay Time' */
  /* Logic: '<S216>/OR1' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.Switch5_ht;

  /* Outputs for Atomic SubSystem: '<S216>/EdgeRising1' */
  /* UnitDelay: '<S217>/Unit Delay' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay_DSTATE_jk;

  /* Logic: '<S217>/OR1' */
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S217>/AND' */
  SWC_APA_B.AND_dj = (SWC_APA_B.Switch5_ht && SWC_APA_B.LogicalOperator2_n);

  /* Update for UnitDelay: '<S217>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_jk = SWC_APA_B.Switch5_ht;

  /* End of Outputs for SubSystem: '<S216>/EdgeRising1' */

  /* Logic: '<S216>/OR' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.AND_dj);

  /* UnitDelay: '<S216>/Unit Delay' */
  SWC_APA_B.UnitDelay_cz = SWC_APA_B.Switch1_b;

  /* Switch: '<S216>/Switch1' incorporates:
   *  Constant: '<S216>/Constant Value1'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch1_b = ((uint16_T)0U);
  } else {
    /* Sum: '<S216>/Summation' incorporates:
     *  Constant: '<S193>/Constant4'
     */
    SWC_APA_B.Summation_m = (uint16_T)((uint32_T)((uint16_T)30U) +
      SWC_APA_B.UnitDelay_cz);

    /* MinMax: '<S216>/Minimum' */
    if (SWC_APA_B.Switch4_f < SWC_APA_B.Summation_m) {
      SWC_APA_B.Minimum_gh = SWC_APA_B.Switch4_f;
    } else {
      SWC_APA_B.Minimum_gh = SWC_APA_B.Summation_m;
    }

    /* End of MinMax: '<S216>/Minimum' */
    SWC_APA_B.Switch1_b = SWC_APA_B.Minimum_gh;
  }

  /* End of Switch: '<S216>/Switch1' */

  /* RelationalOperator: '<S216>/Greater  Than' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch1_b >= SWC_APA_B.Switch4_f);

  /* Logic: '<S216>/AND' */
  SWC_APA_B.AND_a = (SWC_APA_B.Switch5_ht && SWC_APA_B.RelationalOperator1_mc);

  /* End of Outputs for SubSystem: '<S193>/Turn On Delay Time' */

  /* Switch: '<S193>/Switch' incorporates:
   *  Constant: '<S193>/Constant2'
   */
  if (KeAP_b_EnVehStandstillArcBlip) {
    /* Logic: '<S193>/Logical Operator3' */
    SWC_APA_B.LogicalOperator2_j = !SWC_APA_B.Switch5_ht;

    /* Logic: '<S193>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_j = (SWC_APA_B.AND_a ||
      SWC_APA_B.LogicalOperator2_j);

    /* Switch: '<S193>/Switch1' */
    if (SWC_APA_B.LogicalOperator2_j) {
      SWC_APA_B.Switch1_l = SWC_APA_B.MeAP_e_AlertLHF;
    } else {
      /* RelationalOperator: '<S193>/Relational Operator3' incorporates:
       *  Constant: '<S210>/Constant'
       */
      SWC_APA_B.RelationalOperator3_p = (SWC_APA_B.MeAP_e_AlertLHF !=
        TeAP_e_Alert_SNA);

      /* Switch: '<S193>/Switch2' incorporates:
       *  Constant: '<S213>/Constant'
       *  Constant: '<S214>/Constant'
       */
      if (SWC_APA_B.RelationalOperator3_p) {
        SWC_APA_B.Switch2_p = TeAP_e_Alert_NoObjectDetected;
      } else {
        SWC_APA_B.Switch2_p = TeAP_e_Alert_SNA;
      }

      /* End of Switch: '<S193>/Switch2' */
      SWC_APA_B.Switch1_l = SWC_APA_B.Switch2_p;
    }

    /* End of Switch: '<S193>/Switch1' */
    *SWC_APA_rty_MeAP_e_AlertLHF = SWC_APA_B.Switch1_l;
  } else {
    *SWC_APA_rty_MeAP_e_AlertLHF = SWC_APA_B.MeAP_e_AlertLHF;
  }

  /* End of Switch: '<S193>/Switch' */

  /* Outputs for Enabled SubSystem: '<S52>/FPA_ChimeAlertGen' incorporates:
   *  EnablePort: '<S80>/Enable'
   */
  if (*SWC_APA_rty_MeAP_b_FPAStatus) {
    SWC_APA_DW.FPA_ChimeAlertGen_MODE = true;

    /* RelationalOperator: '<S116>/Relational Operator' incorporates:
     *  Constant: '<S132>/Constant'
     */
    SWC_APA_B.RelationalOperator1_mc = (*SWC_APA_rty_MeAP_e_AlertCHF ==
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S116>/Relational Operator1' incorporates:
     *  Constant: '<S133>/Constant'
     */
    SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rty_MeAP_e_AlertLHF ==
      TeAP_e_Alert_Arc1);

    /* Logic: '<S116>/Logical Operator' */
    SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
      SWC_APA_B.LogicalOperator2_n);

    /* RelationalOperator: '<S116>/Relational Operator2' incorporates:
     *  Constant: '<S134>/Constant'
     */
    SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rty_MeAP_e_AlertCHF ==
      TeAP_e_Alert_Arc2);

    /* RelationalOperator: '<S116>/Relational Operator3' incorporates:
     *  Constant: '<S135>/Constant'
     */
    SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_MeAP_e_AlertLHF ==
      TeAP_e_Alert_Arc2);

    /* Logic: '<S116>/Logical Operator1' */
    SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
      SWC_APA_B.RelationalOperator4_m);

    /* RelationalOperator: '<S116>/Relational Operator9' incorporates:
     *  Constant: '<S130>/Constant'
     */
    SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_MeAP_e_AlertRHF !=
      TeAP_e_Alert_Arc1);

    /* Logic: '<S116>/Logical Operator2' */
    SWC_APA_B.MeAP_b_IsLeftChimeZone2 = (SWC_APA_B.LogicalOperator2_n &&
      SWC_APA_B.RelationalOperator4_m);

    /* Switch generated from: '<S116>/Switch' incorporates:
     *  Constant: '<S116>/Constant2'
     *  Switch generated from: '<S116>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.MeAP_b_ChimeActvLHF_d = true;
    } else {
      if (SWC_APA_B.MeAP_b_IsLeftChimeZone2) {
        /* Switch generated from: '<S116>/Switch1' incorporates:
         *  Constant: '<S116>/Constant3'
         */
        SWC_APA_B.MeAP_b_ChimeActvLHF_b = true;
      } else {
        /* Switch generated from: '<S116>/Switch1' incorporates:
         *  Constant: '<S116>/Constant4'
         */
        SWC_APA_B.MeAP_b_ChimeActvLHF_b = false;
      }

      SWC_APA_B.MeAP_b_ChimeActvLHF_d = SWC_APA_B.MeAP_b_ChimeActvLHF_b;
    }

    /* RelationalOperator: '<S117>/Relational Operator' incorporates:
     *  Constant: '<S139>/Constant'
     */
    SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rty_MeAP_e_AlertCHF ==
      TeAP_e_Alert_Arc1);

    /* RelationalOperator: '<S117>/Relational Operator1' incorporates:
     *  Constant: '<S140>/Constant'
     */
    SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_MeAP_e_AlertRHF ==
      TeAP_e_Alert_Arc1);

    /* Logic: '<S117>/Logical Operator' */
    SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
      SWC_APA_B.RelationalOperator4_m);

    /* RelationalOperator: '<S117>/Relational Operator2' incorporates:
     *  Constant: '<S141>/Constant'
     */
    SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_MeAP_e_AlertCHF ==
      TeAP_e_Alert_Arc2);

    /* RelationalOperator: '<S117>/Relational Operator3' incorporates:
     *  Constant: '<S142>/Constant'
     */
    SWC_APA_B.MeAP_b_FrontSwitchPressed = (*SWC_APA_rty_MeAP_e_AlertRHF ==
      TeAP_e_Alert_Arc2);

    /* Logic: '<S117>/Logical Operator1' */
    SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
      SWC_APA_B.MeAP_b_FrontSwitchPressed);

    /* RelationalOperator: '<S117>/Relational Operator8' incorporates:
     *  Constant: '<S144>/Constant'
     */
    SWC_APA_B.MeAP_b_FrontSwitchPressed = (*SWC_APA_rty_MeAP_e_AlertLHF !=
      TeAP_e_Alert_Arc1);

    /* Logic: '<S117>/Logical Operator2' */
    SWC_APA_B.MeAP_b_IsLeftChimeZone2_a = (SWC_APA_B.RelationalOperator4_m &&
      SWC_APA_B.MeAP_b_FrontSwitchPressed);

    /* Switch generated from: '<S117>/Switch' incorporates:
     *  Constant: '<S117>/Constant2'
     *  Switch generated from: '<S117>/Switch1'
     */
    if (SWC_APA_B.LogicalOperator2_n) {
      SWC_APA_B.MeAP_b_ChimeActvRHF_m = true;
    } else {
      if (SWC_APA_B.MeAP_b_IsLeftChimeZone2_a) {
        /* Switch generated from: '<S117>/Switch1' incorporates:
         *  Constant: '<S117>/Constant3'
         */
        SWC_APA_B.MeAP_b_ChimeActvRHF_e = true;
      } else {
        /* Switch generated from: '<S117>/Switch1' incorporates:
         *  Constant: '<S117>/Constant4'
         */
        SWC_APA_B.MeAP_b_ChimeActvRHF_e = false;
      }

      SWC_APA_B.MeAP_b_ChimeActvRHF_m = SWC_APA_B.MeAP_b_ChimeActvRHF_e;
    }

    /* Logic: '<S121>/Logical Operator6' */
    SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.MeAP_b_ChimeActvLHF_d ||
      SWC_APA_B.MeAP_b_ChimeActvRHF_m);

    /* RelationalOperator: '<S121>/Relational Operator4' incorporates:
     *  Constant: '<S127>/Constant'
     */
    SWC_APA_B.MeAP_b_FrontSwitchPressed =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts !=
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S121>/Relational Operator5' incorporates:
     *  Constant: '<S128>/Constant'
     */
    SWC_APA_B.RelationalOperator8_er =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts !=
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S121>/Logical Operator7' */
    SWC_APA_B.MeAP_b_FrontSwitchPressed = (SWC_APA_B.MeAP_b_FrontSwitchPressed ||
      SWC_APA_B.RelationalOperator8_er);

    /* Logic: '<S121>/Logical Operator5' */
    SWC_APA_B.MeAP_b_VehMoving = (SWC_APA_B.RelationalOperator4_m &&
      SWC_APA_B.MeAP_b_FrontSwitchPressed);

    /* UnitDelay: '<S120>/Unit Delay2' */
    SWC_APA_B.UnitDelay2_m = SWC_APA_B.Switch3_ca;

    /* Logic: '<S119>/Logical Operator2' incorporates:
     *  Logic: '<S118>/Logical Operator6'
     *  Switch: '<S120>/Switch3'
     */
    RelationalOperator4_m_tmp = (SWC_APA_B.MeAP_b_ChimeActvLHF_d ||
      SWC_APA_B.MeAP_b_ChimeActvRHF_m);
    SWC_APA_B.RelationalOperator4_m = RelationalOperator4_m_tmp;

    /* RelationalOperator: '<S119>/Relational Operator1' incorporates:
     *  Constant: '<S124>/Constant'
     */
    SWC_APA_B.MeAP_b_FrontSwitchPressed =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* RelationalOperator: '<S119>/Relational Operator2' incorporates:
     *  Constant: '<S125>/Constant'
     */
    SWC_APA_B.RelationalOperator8_er =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
       TeVBII_e_WhlSpnSts_StandStill);

    /* Logic: '<S119>/Logical Operator3' */
    SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.MeAP_e_FiltdGearToDrive ||
      SWC_APA_B.MeAP_e_FiltdGearP2R);

    /* Logic: '<S119>/Logical Operator' */
    SWC_APA_B.FrontChimeTimerStart = (SWC_APA_B.RelationalOperator4_m &&
      SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er &&
      SWC_APA_B.RelationalOperator6_p);

    /* UnitDelay: '<S126>/Unit Delay1' */
    SWC_APA_B.RelationalOperator4_m = SWC_APA_DW.UnitDelay1_DSTATE_nm;

    /* Logic: '<S126>/Logical Operator9' */
    SWC_APA_B.RelationalOperator4_m = !SWC_APA_B.RelationalOperator4_m;

    /* Logic: '<S126>/Logical Operator8' */
    SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.FrontChimeTimerStart &&
      SWC_APA_B.RelationalOperator4_m);

    /* Switch: '<S120>/Switch3' */
    if (SWC_APA_B.RelationalOperator4_m) {
      SWC_APA_B.Switch3_ca =
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd;
    } else {
      /* RelationalOperator: '<S120>/Relational Operator' */
      SWC_APA_B.ElapseTimer_f =
        (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
         SWC_APA_B.UnitDelay2_m);

      /* RelationalOperator: '<S118>/Relational Operator5' incorporates:
       *  Constant: '<S123>/Constant'
       */
      SWC_APA_B.RelationalOperator5_km =
        (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts ==
         TeVBII_e_WhlSpnSts_StandStill);

      /* Logic: '<S118>/Logical Operator6' */
      SWC_APA_B.LogicalOperator1_f = RelationalOperator4_m_tmp;

      /* RelationalOperator: '<S118>/Relational Operator4' incorporates:
       *  Constant: '<S122>/Constant'
       */
      SWC_APA_B.RelationalOperator4_l =
        (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts ==
         TeVBII_e_WhlSpnSts_StandStill);

      /* Logic: '<S118>/Logical Operator5' */
      SWC_APA_B.LogicalOperator1_f = (SWC_APA_B.LogicalOperator1_f &&
        SWC_APA_B.RelationalOperator4_l && SWC_APA_B.RelationalOperator5_km &&
        SWC_APA_B.MeAP_e_FiltdGearD2R);

      /* Logic: '<S115>/Logical Operator6' */
      SWC_APA_B.LogicalOperator1_f = (SWC_APA_B.MeAP_b_VehMoving ||
        SWC_APA_B.LogicalOperator1_f);

      /* Logic: '<S120>/Logical Operator1' */
      SWC_APA_B.LogicalOperator1_f = !SWC_APA_B.LogicalOperator1_f;

      /* Logic: '<S120>/Logical Operator3' */
      SWC_APA_B.ElapseTimer_f = (SWC_APA_B.ElapseTimer_f &&
        SWC_APA_B.LogicalOperator1_f);

      /* Switch: '<S120>/Switch1' incorporates:
       *  Constant: '<S120>/Constant'
       */
      if (SWC_APA_B.ElapseTimer_f) {
        /* Sum: '<S120>/Subtract' */
        SWC_APA_B.Subtract_d = (uint16_T)(SWC_APA_B.UnitDelay2_m -
          *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_APA_B.Switch1_dc = SWC_APA_B.Subtract_d;
      } else {
        SWC_APA_B.Switch1_dc = ((uint16_T)0U);
      }

      /* End of Switch: '<S120>/Switch1' */
      SWC_APA_B.Switch3_ca = SWC_APA_B.Switch1_dc;
    }

    /* RelationalOperator: '<S120>/Relational Operator1' */
    SWC_APA_B.RelationalOperator4_m =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep >
       SWC_APA_B.Switch3_ca);

    /* Logic: '<S120>/Logical Operator4' */
    SWC_APA_B.RelationalOperator4_m = !SWC_APA_B.RelationalOperator4_m;

    /* Logic: '<S115>/Logical Operator2' */
    SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
      SWC_APA_B.MeAP_b_VehMoving);

    /* Logic: '<S115>/Logical Operator1' */
    SWC_APA_B.MeAP_b_ChimeActvLHF_h = (SWC_APA_B.MeAP_b_ChimeActvLHF_d &&
      SWC_APA_B.RelationalOperator4_m);

    /* Logic: '<S115>/Logical Operator3' */
    SWC_APA_B.MeAP_b_ChimeActvRHF_k = (SWC_APA_B.MeAP_b_ChimeActvRHF_m &&
      SWC_APA_B.RelationalOperator4_m);

    /* Switch generated from: '<S117>/Switch' incorporates:
     *  Constant: '<S143>/Constant'
     *  Switch generated from: '<S117>/Switch1'
     */
    if (SWC_APA_B.LogicalOperator2_n) {
      SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_n =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    } else {
      if (SWC_APA_B.MeAP_b_IsLeftChimeZone2_a) {
        /* Switch generated from: '<S117>/Switch1' incorporates:
         *  Constant: '<S137>/Constant'
         */
        SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_m =
          TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
      } else {
        /* Switch generated from: '<S117>/Switch1' incorporates:
         *  Constant: '<S138>/Constant'
         */
        SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_m =
          TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      }

      SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_n =
        SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_m;
    }

    /* Switch generated from: '<S116>/Switch' incorporates:
     *  Constant: '<S136>/Constant'
     *  Switch generated from: '<S116>/Switch1'
     */
    if (SWC_APA_B.RelationalOperator1_mc) {
      SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_l =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    } else {
      if (SWC_APA_B.MeAP_b_IsLeftChimeZone2) {
        /* Switch generated from: '<S116>/Switch1' incorporates:
         *  Constant: '<S129>/Constant'
         */
        SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_a =
          TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
      } else {
        /* Switch generated from: '<S116>/Switch1' incorporates:
         *  Constant: '<S131>/Constant'
         */
        SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_a =
          TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      }

      SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_l =
        SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_a;
    }

    /* Update for UnitDelay: '<S126>/Unit Delay1' */
    SWC_APA_DW.UnitDelay1_DSTATE_nm = SWC_APA_B.FrontChimeTimerStart;
  } else {
    if (SWC_APA_DW.FPA_ChimeAlertGen_MODE) {
      /* Disable for Outport: '<S80>/MeAP_b_ChimeActvLHF' */
      SWC_APA_B.MeAP_b_ChimeActvLHF_h = false;

      /* Disable for Outport: '<S80>/MeAP_b_ChimeActvRHF' */
      SWC_APA_B.MeAP_b_ChimeActvRHF_k = false;

      /* Disable for Outport: '<S80>/MeAP_e_LtFrntChimeRepnRate' */
      SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_l =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;

      /* Disable for Outport: '<S80>/MeAP_e_RtFrntChimeRepnRate' */
      SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_n =
        TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
      SWC_APA_DW.FPA_ChimeAlertGen_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S52>/FPA_ChimeAlertGen' */

  /* Logic: '<S81>/Logical Operator1' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_b_ChimeActvLHF_h ||
    SWC_APA_B.MeAP_b_ChimeActvRHF_k);

  /* Logic: '<S81>/Logical Operator2' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* UnitDelay: '<S81>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_h = SWC_APA_DW.UnitDelay1_DSTATE_jd;

  /* UnitDelay: '<S155>/Unit Delay1' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay1_DSTATE_lo;

  /* Logic: '<S155>/Logical Operator9' */
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S155>/Logical Operator8' */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.UnitDelay1_h &&
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S151>/Unit Delay1' */
  SWC_APA_B.RelationalOperator4_m = SWC_APA_B.Switch2_k2;

  /* Switch: '<S151>/Switch2' */
  SWC_APA_B.Switch2_k2 = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* UnitDelay: '<S151>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_e = SWC_APA_B.Switch4_l;

  /* Switch: '<S151>/Switch3' incorporates:
   *  Constant: '<S81>/Constant7'
   */
  if (SWC_APA_B.LogicalOperator2_n) {
    SWC_APA_B.Switch3_p = KeAP_cnt_BootupTimeThd;
  } else {
    /* RelationalOperator: '<S151>/Relational Operator' incorporates:
     *  Constant: '<S81>/Constant6'
     */
    SWC_APA_B.RelationalOperator_dc = (KeAP_cnt_TimeStep <=
      SWC_APA_B.UnitDelay2_e);

    /* Switch: '<S151>/Switch1' incorporates:
     *  Constant: '<S151>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_dc) {
      /* Sum: '<S151>/Subtract' incorporates:
       *  Constant: '<S81>/Constant6'
       */
      SWC_APA_B.Subtract_p = SWC_APA_B.UnitDelay2_e - (real_T)KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1_d = SWC_APA_B.Subtract_p;
    } else {
      SWC_APA_B.Switch1_d = 0.0;
    }

    /* End of Switch: '<S151>/Switch1' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch1_d;
  }

  /* End of Switch: '<S151>/Switch3' */

  /* RelationalOperator: '<S151>/Relational Operator1' incorporates:
   *  Constant: '<S81>/Constant6'
   */
  SWC_APA_B.RelationalOperator1_p = (KeAP_cnt_TimeStep > SWC_APA_B.Switch3_p);

  /* UnitDelay: '<S154>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_lo = SWC_APA_B.Switch5_jv;

  /* Switch: '<S154>/Switch5' incorporates:
   *  Constant: '<S154>/Constant1'
   */
  if (SWC_APA_B.LogicalOperator2_n) {
    SWC_APA_B.Switch5_jv = true;
  } else {
    /* Logic: '<S151>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_g = (SWC_APA_B.Switch2_k2 &&
      SWC_APA_B.RelationalOperator1_p);

    /* Switch: '<S154>/Switch6' incorporates:
     *  Constant: '<S154>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_g) {
      SWC_APA_B.Switch6_p = false;
    } else {
      SWC_APA_B.Switch6_p = SWC_APA_B.UnitDelay3_lo;
    }

    /* End of Switch: '<S154>/Switch6' */
    SWC_APA_B.Switch5_jv = SWC_APA_B.Switch6_p;
  }

  /* End of Switch: '<S154>/Switch5' */

  /* UnitDelay: '<S81>/Unit Delay' */
  SWC_APA_B.UnitDelay_k = SWC_APA_DW.UnitDelay_DSTATE_j;

  /* Switch: '<S81>/Switch' incorporates:
   *  Constant: '<S81>/Constant1'
   */
  if (SWC_APA_B.Switch5_jv) {
    SWC_APA_B.LogicalOperator2_n = false;
  } else {
    /* RelationalOperator: '<S81>/Relational Operator' */
    SWC_APA_B.RelationalOperator_l =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt !=
       SWC_APA_B.UnitDelay_k);
    SWC_APA_B.LogicalOperator2_n = SWC_APA_B.RelationalOperator_l;
  }

  /* End of Switch: '<S81>/Switch' */

  /* RelationalOperator: '<S81>/Relational Operator1' incorporates:
   *  Constant: '<S146>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt ==
     TeVBII_e_PamChimeVol_Low);

  /* RelationalOperator: '<S81>/Relational Operator2' incorporates:
   *  Constant: '<S148>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt ==
     TeVBII_e_PamChimeVol_Medium);

  /* RelationalOperator: '<S81>/Relational Operator3' incorporates:
   *  Constant: '<S149>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt ==
     TeVBII_e_PamChimeVol_High);

  /* Logic: '<S81>/Logical Operator3' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    SWC_APA_B.MeAP_b_FrontSwitchPressed || SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S81>/Logical Operator4' */
  SWC_APA_B.LogicalOperator4_i = (SWC_APA_B.LogicalOperator2_n &&
    SWC_APA_B.RelationalOperator4_m);

  /* UnitDelay: '<S153>/Unit Delay1' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay1_DSTATE_m3;

  /* Logic: '<S153>/Logical Operator9' */
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S153>/Logical Operator8' */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator4_i &&
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S150>/Unit Delay1' */
  SWC_APA_B.RelationalOperator4_m = SWC_APA_B.Switch2_m;

  /* Switch: '<S150>/Switch2' */
  SWC_APA_B.Switch2_m = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* UnitDelay: '<S150>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_b = SWC_APA_B.Switch4_e;

  /* Switch: '<S150>/Switch3' */
  if (SWC_APA_B.LogicalOperator2_n) {
    SWC_APA_B.Switch3 =
      *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert;
  } else {
    /* RelationalOperator: '<S150>/Relational Operator' */
    SWC_APA_B.RelationalOperator_m1 =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_b);

    /* Switch: '<S150>/Switch1' incorporates:
     *  Constant: '<S150>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_m1) {
      /* Sum: '<S150>/Subtract' */
      SWC_APA_B.Subtract_pq = SWC_APA_B.UnitDelay2_b - (real_T)
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1_h = SWC_APA_B.Subtract_pq;
    } else {
      SWC_APA_B.Switch1_h = 0.0;
    }

    /* End of Switch: '<S150>/Switch1' */
    SWC_APA_B.Switch3 = SWC_APA_B.Switch1_h;
  }

  /* End of Switch: '<S150>/Switch3' */

  /* RelationalOperator: '<S150>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_d5 =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3);

  /* UnitDelay: '<S152>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_h = SWC_APA_B.Switch5_nn;

  /* Switch: '<S152>/Switch5' incorporates:
   *  Constant: '<S152>/Constant1'
   */
  if (SWC_APA_B.LogicalOperator2_n) {
    SWC_APA_B.Switch5_nn = true;
  } else {
    /* Logic: '<S150>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_d = (SWC_APA_B.Switch2_m &&
      SWC_APA_B.RelationalOperator1_d5);

    /* Switch: '<S152>/Switch6' incorporates:
     *  Constant: '<S152>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_d) {
      SWC_APA_B.Switch6_ab = false;
    } else {
      SWC_APA_B.Switch6_ab = SWC_APA_B.UnitDelay3_h;
    }

    /* End of Switch: '<S152>/Switch6' */
    SWC_APA_B.Switch5_nn = SWC_APA_B.Switch6_ab;
  }

  /* End of Switch: '<S152>/Switch5' */

  /* Logic: '<S81>/Logical Operator' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch5_nn &&
    SWC_APA_B.RelationalOperator1_mc);

  /* Switch generated from: '<S81>/Switch2' incorporates:
   *  Constant: '<S145>/Constant'
   *  Constant: '<S147>/Constant'
   *  Constant: '<S81>/Constant4'
   *  Constant: '<S81>/Constant5'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.MeAP_b_ChimeActvLHF = true;
    SWC_APA_B.MeAP_b_ChimeActvRHF = true;
    SWC_APA_B.MeAP_e_LtFrntChimeRepnRate =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
    SWC_APA_B.MeAP_e_RtFrntChimeRepnRate =
      TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  } else {
    SWC_APA_B.MeAP_b_ChimeActvLHF = SWC_APA_B.MeAP_b_ChimeActvLHF_h;
    SWC_APA_B.MeAP_b_ChimeActvRHF = SWC_APA_B.MeAP_b_ChimeActvRHF_k;
    SWC_APA_B.MeAP_e_LtFrntChimeRepnRate =
      SWC_APA_B.MeAP_e_LtFrntChimeRepnRate_l;
    SWC_APA_B.MeAP_e_RtFrntChimeRepnRate =
      SWC_APA_B.MeAP_e_RtFrntChimeRepnRate_n;
  }

  /* End of Switch generated from: '<S81>/Switch2' */

  /* Switch: '<S150>/Switch4' incorporates:
   *  Constant: '<S150>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1_d5) {
    SWC_APA_B.Switch4_e = 0.0;
  } else {
    SWC_APA_B.Switch4_e = SWC_APA_B.Switch3;
  }

  /* End of Switch: '<S150>/Switch4' */

  /* Switch: '<S151>/Switch4' incorporates:
   *  Constant: '<S151>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1_p) {
    SWC_APA_B.Switch4_l = 0.0;
  } else {
    SWC_APA_B.Switch4_l = SWC_APA_B.Switch3_p;
  }

  /* End of Switch: '<S151>/Switch4' */

  /* DataTypeConversion: '<S191>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_h = (uint8_T)*SWC_APA_rty_MeAP_e_AlertLHF;

  /* MultiPortSwitch: '<S191>/Multiport Switch' incorporates:
   *  Constant: '<S200>/Constant'
   *  Constant: '<S201>/Constant'
   *  Constant: '<S202>/Constant'
   *  Constant: '<S203>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_h) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S191>/Multiport Switch' */

  /* DataTypeConversion: '<S190>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_eb = (uint8_T)*SWC_APA_rty_MeAP_e_AlertCHF;

  /* MultiPortSwitch: '<S190>/Multiport Switch' incorporates:
   *  Constant: '<S196>/Constant'
   *  Constant: '<S197>/Constant'
   *  Constant: '<S198>/Constant'
   *  Constant: '<S199>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_eb) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S190>/Multiport Switch' */

  /* DataTypeConversion: '<S192>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_pb = (uint8_T)*SWC_APA_rty_MeAP_e_AlertRHF;

  /* MultiPortSwitch: '<S192>/Multiport Switch' incorporates:
   *  Constant: '<S204>/Constant'
   *  Constant: '<S205>/Constant'
   *  Constant: '<S206>/Constant'
   *  Constant: '<S207>/Constant'
   */
  switch (SWC_APA_B.DataTypeConversion_pb) {
   case 0:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_None;
    break;

   case 1:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 2:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 3:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SlowFlash;
    break;

   case 4:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 5:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   case 6:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_Solid;
    break;

   default:
    *SWC_APA_rty_MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S192>/Multiport Switch' */

  /* RelationalOperator: '<S78>/Relational Operator4' incorporates:
   *  Constant: '<S99>/Constant'
   */
  SWC_APA_B.RelationalOperator4_e = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_TemporaryFailure);

  /* RelationalOperator: '<S78>/Relational Operator11' incorporates:
   *  Constant: '<S89>/Constant'
   */
  SWC_APA_B.RelationalOperator1_mc = (*SWC_APA_rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S78>/Relational Operator10' incorporates:
   *  Constant: '<S88>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S78>/Relational Operator1' incorporates:
   *  Constant: '<S84>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_SNA);

  /* Logic: '<S78>/Logical Operator5' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n || SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S78>/Relational Operator13' incorporates:
   *  Constant: '<S91>/Constant'
   */
  SWC_APA_B.LogicalOperator2_n = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* RelationalOperator: '<S78>/Relational Operator12' incorporates:
   *  Constant: '<S90>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S78>/Logical Operator6' */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m || SWC_APA_B.RelationalOperator4_e);

  /* Logic: '<S78>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FrntSysFault = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S109>/Unit Delay1' */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.UnitDelay1_DSTATE_bv;

  /* Logic: '<S109>/Logical Operator9' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* RelationalOperator: '<S109>/Relational Operator4' */
  SWC_APA_B.RelationalOperator1_mc = (MeAP_b_FPASwtStatus ==
    SWC_APA_B.RelationalOperator1_mc);

  /* UnitDelay: '<S108>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_gm = SWC_APA_B.Switch3_k;

  /* Switch: '<S108>/Switch3' incorporates:
   *  Constant: '<S105>/Constant'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch3_k = KeAP_cnt_BtnPressPopUpTimeThd;
  } else {
    /* RelationalOperator: '<S108>/Relational Operator' */
    SWC_APA_B.ElapseTimer_p =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_gm);

    /* Logic: '<S108>/Logical Operator3' */
    SWC_APA_B.ElapseTimer_p = (SWC_APA_B.ElapseTimer_p &&
      SWC_APA_ConstB.LogicalOperator1_a);

    /* Switch: '<S108>/Switch1' incorporates:
     *  Constant: '<S108>/Constant'
     */
    if (SWC_APA_B.ElapseTimer_p) {
      /* Sum: '<S108>/Subtract' */
      SWC_APA_B.Subtract_da = (uint16_T)(SWC_APA_B.UnitDelay2_gm -
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_gn = SWC_APA_B.Subtract_da;
    } else {
      SWC_APA_B.Switch1_gn = ((uint16_T)0U);
    }

    /* End of Switch: '<S108>/Switch1' */
    SWC_APA_B.Switch3_k = SWC_APA_B.Switch1_gn;
  }

  /* End of Switch: '<S108>/Switch3' */

  /* RelationalOperator: '<S108>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_mc =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_k);

  /* Logic: '<S108>/Logical Operator4' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* Logic: '<S78>/Logical Operator7' */
  SWC_APA_B.LogicalOperator7_i = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.MeAP_b_FrntSysFault);

  /* UnitDelay: '<S107>/Unit Delay1' */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.UnitDelay1_DSTATE_dv3;

  /* Logic: '<S107>/Logical Operator9' */
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* Logic: '<S107>/Logical Operator8' */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.LogicalOperator7_i &&
    SWC_APA_B.RelationalOperator1_mc);

  /* UnitDelay: '<S104>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_c = SWC_APA_B.Switch4_a;

  /* Switch: '<S104>/Switch3' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    /* Switch: '<S78>/Switch' incorporates:
     *  Constant: '<S78>/Constant2'
     */
    if (SWC_APA_B.RelationalOperator4_e) {
      SWC_APA_B.Switch_b = KeAP_cnt_PlntModeLEDBlinkTimeThd;
    } else {
      SWC_APA_B.Switch_b =
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd;
    }

    /* End of Switch: '<S78>/Switch' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch_b;
  } else {
    /* RelationalOperator: '<S104>/Relational Operator' */
    SWC_APA_B.RelationalOperator_oc =
      (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
       SWC_APA_B.UnitDelay2_c);

    /* Switch: '<S104>/Switch1' incorporates:
     *  Constant: '<S104>/Constant'
     */
    if (SWC_APA_B.RelationalOperator_oc) {
      /* Sum: '<S104>/Subtract' */
      SWC_APA_B.Subtract_g = SWC_APA_B.UnitDelay2_c - (real_T)
        *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
      SWC_APA_B.Switch1_o = SWC_APA_B.Subtract_g;
    } else {
      SWC_APA_B.Switch1_o = 0.0;
    }

    /* End of Switch: '<S104>/Switch1' */
    SWC_APA_B.Switch3_p = SWC_APA_B.Switch1_o;
  }

  /* End of Switch: '<S104>/Switch3' */

  /* RelationalOperator: '<S104>/Relational Operator1' */
  SWC_APA_B.RelationalOperator1_jd =
    (*SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_p);

  /* UnitDelay: '<S104>/Unit Delay1' */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_B.Switch2_oo;

  /* Switch: '<S104>/Switch2' */
  SWC_APA_B.Switch2_oo = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* UnitDelay: '<S106>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_g = SWC_APA_B.Switch5_no;

  /* Switch: '<S106>/Switch5' incorporates:
   *  Constant: '<S106>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    SWC_APA_B.Switch5_no = true;
  } else {
    /* Logic: '<S104>/Logical Operator8' */
    SWC_APA_B.LogicalOperator8_dy = (SWC_APA_B.Switch2_oo &&
      SWC_APA_B.RelationalOperator1_jd);

    /* Switch: '<S106>/Switch6' incorporates:
     *  Constant: '<S106>/Constant3'
     */
    if (SWC_APA_B.LogicalOperator8_dy) {
      SWC_APA_B.Switch6_e0 = false;
    } else {
      SWC_APA_B.Switch6_e0 = SWC_APA_B.UnitDelay3_g;
    }

    /* End of Switch: '<S106>/Switch6' */
    SWC_APA_B.Switch5_no = SWC_APA_B.Switch6_e0;
  }

  /* End of Switch: '<S106>/Switch5' */

  /* UnitDelay: '<S78>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_n = SWC_APA_DW.UnitDelay1_DSTATE_h;

  /* Switch: '<S78>/Switch2' incorporates:
   *  Constant: '<S98>/Constant'
   */
  if (SWC_APA_B.Switch5_no) {
    *SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus =
      TeAP_e_PAMLedCtrlStatus_BlinkingLight;
  } else {
    /* RelationalOperator: '<S78>/Relational Operator17' incorporates:
     *  Constant: '<S94>/Constant'
     */
    SWC_APA_B.IgnRun_i = (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
                          TeVBII_e_CmdIgnSts_RUN);

    /* RelationalOperator: '<S78>/Relational Operator14' incorporates:
     *  Constant: '<S93>/Constant'
     */
    SWC_APA_B.RelationalOperator14_i =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_ACC);

    /* RelationalOperator: '<S78>/Relational Operator3' incorporates:
     *  Constant: '<S92>/Constant'
     */
    SWC_APA_B.RelationalOperator3_n =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_START);

    /* RelationalOperator: '<S78>/Relational Operator2' incorporates:
     *  Constant: '<S97>/Constant'
     */
    SWC_APA_B.LogicalOperator10_n =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_IGN_LK);

    /* RelationalOperator: '<S78>/Relational Operator18' incorporates:
     *  Constant: '<S96>/Constant'
     */
    SWC_APA_B.RelationalOperator6_k =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts !=
       TeVBII_e_CmdIgnSts_Initialization);

    /* RelationalOperator: '<S78>/Relational Operator16' incorporates:
     *  Constant: '<S95>/Constant'
     */
    SWC_APA_B.LogicalOperator9_h =
      (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_RUN);

    /* Logic: '<S78>/Logical Operator2' */
    SWC_APA_B.LogicalOperator9_h = (SWC_APA_B.LogicalOperator9_h &&
      SWC_APA_B.RelationalOperator6_k && SWC_APA_B.LogicalOperator10_n &&
      SWC_APA_B.RelationalOperator3_n && SWC_APA_B.RelationalOperator14_i);

    /* Logic: '<S78>/Logical Operator17' */
    SWC_APA_B.LogicalOperator9_h = (SWC_APA_B.LogicalOperator9_h ||
      SWC_APA_B.IgnRun_i);

    /* Logic: '<S78>/Logical Operator18' */
    SWC_APA_B.LogicalOperator9_h = (SWC_APA_B.LogicalOperator9_h &&
      SWC_APA_B.MeAP_b_FrntSysFault);

    /* RelationalOperator: '<S78>/Relational Operator6' incorporates:
     *  Constant: '<S102>/Constant'
     */
    SWC_APA_B.RelationalOperator6_k = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
      TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

    /* RelationalOperator: '<S78>/Relational Operator5' incorporates:
     *  Constant: '<S101>/Constant'
     */
    SWC_APA_B.LogicalOperator10_n = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
      TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

    /* Logic: '<S78>/Logical Operator8' */
    SWC_APA_B.LogicalOperator10_n = (SWC_APA_B.LogicalOperator10_n ||
      SWC_APA_B.RelationalOperator6_k);

    /* Logic: '<S78>/Logical Operator11' */
    SWC_APA_B.LogicalOperator10_n = !SWC_APA_B.LogicalOperator10_n;

    /* Logic: '<S78>/Logical Operator10' */
    SWC_APA_B.LogicalOperator10_n = (SWC_APA_B.LogicalOperator10_n &&
      SWC_APA_B.IgnRun_i);

    /* Logic: '<S78>/Logical Operator9' */
    SWC_APA_B.LogicalOperator9_h = (SWC_APA_B.LogicalOperator9_h ||
      SWC_APA_B.LogicalOperator10_n);

    /* Switch: '<S78>/Switch3' incorporates:
     *  Constant: '<S103>/Constant'
     */
    if (SWC_APA_B.LogicalOperator9_h) {
      SWC_APA_B.Switch3_a = TeAP_e_PAMLedCtrlStatus_ContinousLight;
    } else {
      /* RelationalOperator: '<S78>/Relational Operator9' incorporates:
       *  Constant: '<S100>/Constant'
       */
      SWC_APA_B.RelationalOperator9_c = (*SWC_APA_rtu_IeAP_e_ParKMnvrActv ==
        TeAP_e_ParKMnvrActv_Engaged_Full);

      /* Logic: '<S78>/Logical Operator13' */
      SWC_APA_B.LogicalOperator13_k = !SWC_APA_B.MeAP_b_FrntSysFault;

      /* RelationalOperator: '<S78>/Relational Operator8' incorporates:
       *  Constant: '<S86>/Constant'
       */
      SWC_APA_B.LogicalOperator15 = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
        TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

      /* RelationalOperator: '<S78>/Relational Operator7' incorporates:
       *  Constant: '<S85>/Constant'
       */
      SWC_APA_B.LogicalOperator3_e = (*SWC_APA_rty_MeAP_e_PAMOffStatus2BT ==
        TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

      /* Logic: '<S78>/Logical Operator12' */
      SWC_APA_B.LogicalOperator3_e = (SWC_APA_B.LogicalOperator3_e ||
        SWC_APA_B.LogicalOperator15);

      /* Logic: '<S78>/Logical Operator14' */
      SWC_APA_B.LogicalOperator3_e = (SWC_APA_B.LogicalOperator3_e &&
        SWC_APA_B.LogicalOperator13_k);

      /* Logic: '<S78>/Logical Operator4' */
      SWC_APA_B.LogicalOperator3_e = (SWC_APA_B.LogicalOperator3_e ||
        SWC_APA_B.RelationalOperator9_c);

      /* Logic: '<S78>/Logical Operator15' */
      SWC_APA_B.LogicalOperator15 = !SWC_APA_B.IgnRun_i;

      /* Logic: '<S78>/Logical Operator3' */
      SWC_APA_B.LogicalOperator3_e = (SWC_APA_B.LogicalOperator3_e ||
        SWC_APA_B.LogicalOperator15);

      /* Switch: '<S78>/Switch4' incorporates:
       *  Constant: '<S87>/Constant'
       */
      if (SWC_APA_B.LogicalOperator3_e) {
        SWC_APA_B.Switch4_ap = TeAP_e_PAMLedCtrlStatus_Off;
      } else {
        SWC_APA_B.Switch4_ap = SWC_APA_B.UnitDelay1_n;
      }

      /* End of Switch: '<S78>/Switch4' */
      SWC_APA_B.Switch3_a = SWC_APA_B.Switch4_ap;
    }

    /* End of Switch: '<S78>/Switch3' */
    *SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus = SWC_APA_B.Switch3_a;
  }

  /* End of Switch: '<S78>/Switch2' */

  /* Switch: '<S104>/Switch4' incorporates:
   *  Constant: '<S104>/Constant2'
   */
  if (SWC_APA_B.RelationalOperator1_jd) {
    SWC_APA_B.Switch4_a = 0.0;
  } else {
    SWC_APA_B.Switch4_a = SWC_APA_B.Switch3_p;
  }

  /* End of Switch: '<S104>/Switch4' */

  /* Update for UnitDelay: '<S194>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_g = SWC_APA_B.Switch4_c;

  /* Update for UnitDelay: '<S194>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_pz = SWC_APA_B.LogicalOperator1_l;

  /* Update for UnitDelay: '<S225>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_ge = SWC_APA_B.Switch5_ct;

  /* Update for UnitDelay: '<S79>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_g =
    *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;

  /* Update for UnitDelay: '<S79>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_i =
    *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;

  /* Update for UnitDelay: '<S195>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_p = SWC_APA_B.Switch4_esz;

  /* Update for UnitDelay: '<S195>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_fc = SWC_APA_B.LogicalOperator1_lz;

  /* Update for UnitDelay: '<S235>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_mc = SWC_APA_B.Switch5_a0;

  /* Update for UnitDelay: '<S193>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_pp = SWC_APA_B.Switch4_f;

  /* Update for UnitDelay: '<S193>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_bq = SWC_APA_B.LogicalOperator1_l5;

  /* Update for UnitDelay: '<S215>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_av = SWC_APA_B.Switch5_ht;

  /* Update for UnitDelay: '<S81>/Unit Delay1' incorporates:
   *  Constant: '<S81>/Constant'
   */
  SWC_APA_DW.UnitDelay1_DSTATE_jd = false;

  /* Update for UnitDelay: '<S155>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_lo = SWC_APA_B.UnitDelay1_h;

  /* Update for UnitDelay: '<S81>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_j =
    *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;

  /* Update for UnitDelay: '<S153>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_m3 = SWC_APA_B.LogicalOperator4_i;

  /* Update for UnitDelay: '<S109>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_bv = MeAP_b_FPASwtStatus;

  /* Update for UnitDelay: '<S107>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_dv3 = SWC_APA_B.LogicalOperator7_i;

  /* Update for UnitDelay: '<S78>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_h = *SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
