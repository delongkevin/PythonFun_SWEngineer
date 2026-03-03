/*
 * File: RearStop_Release.c
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

#include "RearStop_Release.h"

/* Include model header file for global data */
#include "SWC_APA.h"
#include "SWC_APA_private.h"

/* Includes for objects with custom storage classes. */
#include "SWC_APA.h"

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

/* System initialize for atomic system: '<S6>/RPAwithBrk' */
void SWC_APA_RPAwithBrk_Init(void)
{
  /* InitializeConditions for Delay: '<S652>/Delay' */
  SWC_APA_DW.icLoad = 1U;

  /* InitializeConditions for UnitDelay: '<S651>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE = 1023.0F;

  /* InitializeConditions for UnitDelay: '<S661>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_a = 1023.0F;

  /* SystemInitialize for ModelReference generated from: '<S57>/Rear_ObjectDetection' */
  Rear_ObjectDection_Init(&SWC_APA_B.MeAP_cm_RearDist,
    &SWC_APA_B.MeAP_cm_RearDist_Int);
}

/* Disable for atomic system: '<S6>/RPAwithBrk' */
void SWC_APA_RPAwithBrk_Disable(void)
{
  /* Disable for ModelReference generated from: '<S57>/Rear_ObjectDetection' */
  Rear_ObjectDection_Disable(&SWC_APA_B.MeAP_cm_RearDist,
    &SWC_APA_B.MeAP_b_ObjInPath, &SWC_APA_B.MeAP_cm_RearDist_Int);
}

/* Output and update for atomic system: '<S6>/RPAwithBrk' */
void SWC_APA_RPAwithBrk(void)
{
  /* RelationalOperator: '<S652>/Relational Operator' incorporates:
   *  Constant: '<S665>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts !=
     TeVBII_e_TCaseRangeSts_LOW);

  /* Logic: '<S652>/Logical Operator14' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
    (*SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBActv4LOW));

  /* Logic: '<S652>/Logical Operator' */
  SWC_APA_B.RelationalOperator2_j =
    ((*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM) &&
     SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S652>/Logical Operator12' */
  SWC_APA_B.Compare_k = !*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM;

  /* Logic: '<S652>/Logical Operator11' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S652>/Logical Operator16' */
  SWC_APA_B.RelationalOperator2_j =
    !*SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus;

  /* RelationalOperator: '<S652>/Relational Operator7' incorporates:
   *  Constant: '<S670>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*SWC_APA_rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_Active);

  /* RelationalOperator: '<S652>/Relational Operator8' incorporates:
   *  Constant: '<S672>/Constant'
   */
  SWC_APA_B.RelationalOperator8_e = (*SWC_APA_rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* Logic: '<S652>/Logical Operator7' */
  SWC_APA_B.LogicalOperator1_d = !*SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBDiable;

  /* UnitDelay: '<S57>/Unit Delay' */
  SWC_APA_B.RelationalOperator_jv = SWC_APA_B.MeAP_b_DisableRearBrarking;

  /* Logic: '<S652>/Logical Operator8' */
  SWC_APA_B.RelationalOperator_jv = !SWC_APA_B.RelationalOperator_jv;

  /* RelationalOperator: '<S652>/Relational Operator3' incorporates:
   *  Constant: '<S669>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rtu_MeTHA_e_RearBrkSupprInfo !=
    TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking);

  /* Logic: '<S652>/Logical Operator5' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Constant: '<S652>/Constant'
   */
  SWC_APA_B.MeAP_b_PAMStopCtrlStatus = (SWC_APA_B.RelationalOperator7 &&
    SWC_APA_B.RelationalOperator8_e && KeAP_b_RPAwithBrk && true &&
    SWC_APA_B.MeAP_b_TrlrNotConnected && SWC_APA_B.LogicalOperator1_d &&
    SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator_jv &&
    SWC_APA_B.RelationalOperator1_e1 && SWC_APA_B.RelationalOperator2_j);

  /* DataTypeConversion: '<S650>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_c = (uint8_T)
    *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_GbTyp;

  /* RelationalOperator: '<S650>/Relational Operator3' incorporates:
   *  Constant: '<S650>/Constant1'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.DataTypeConversion_c ==
    KeAP_e_GbTypAT);

  /* Delay: '<S652>/Delay' */
  if (SWC_APA_DW.icLoad != 0) {
    SWC_APA_DW.Delay_DSTATE =
      SWC_APA_rtu_MbNVM_ReadParam->IeNVM_b_PAMRearCtrlSts;
  }

  *SWC_APA_rty_MeAP_b_PAMStopCtrlStatus = SWC_APA_DW.Delay_DSTATE;

  /* End of Delay: '<S652>/Delay' */

  /* RelationalOperator: '<S650>/Relational Operator1' incorporates:
   *  Constant: '<S655>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*SWC_APA_rtu_IeAP_e_ParKMnvrActv !=
    TeAP_e_ParKMnvrActv_Engaged_Full);

  /* Logic: '<S650>/Logical Operator2' */
  *SWC_APA_rty_MeAP_b_PAMBrkReqStatus = ((*SWC_APA_rty_MeAP_b_PAMStopCtrlStatus)
    && (*SWC_APA_rty_MeAP_b_RPAStatus) && SWC_APA_B.RelationalOperator1_e1 &&
    (*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop) &&
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst) &&
    SWC_APA_B.RelationalOperator2_j);

  /* UnitDelay: '<S654>/Delay Input1'
   *
   * Block description for '<S654>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S654>/FixPt Relational Operator' */
  SWC_APA_B.FixPtRelationalOperator = (uint8_T)((int32_T)
    *SWC_APA_rty_MeAP_b_PAMBrkReqStatus > (int32_T)
    SWC_APA_B.RelationalOperator1_e1);

  /* BusCreator generated from: '<S57>/Rear_ObjectDetection' */
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_CmdIgnSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_FrntParkAsstReq
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_ParkAsstReq
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_RemoteStartActvSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_SnowPlowAttached
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TrailerConnectionSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TrlrPrsntSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_degC_ExtTemp
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_BrkStat
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkStat;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_VehEPBSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TCaseRangeSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_EssEngState
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EssEngState;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_PamChimeVolFrnt
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_PamChimeVolRear
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_RearBrkAsst
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.MeAP_e_FiltdTrgtGear
    = *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TransSailingTst
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_a_VehLatAcc
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_a_VehLongAcc
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_kph_VehSpeedVSOSig
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_ddeg_VehYawRate
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_cnt_LhfPulseCtr
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_LhfWhlSpnSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_kph_LhfWhlSpd
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_cnt_LhrPulseCtr
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_kph_LhrWhlSpd
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_cnt_RhfPulseCtr
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_RhfWhlSpnSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_kph_RhfWhlSpd
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_cnt_RhrPulseCtr
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_kph_RhrWhlSpd
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_deg_StrWhlAng
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_deg_StrWhlSpd
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_ShifterAutoconnectSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ShiftLvrPosReq
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_AutoParkEnblSwt
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TurnIndicSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_DriverDoorSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_DoorRL
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRL;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_DoorP
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorP;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_TrnkStatus
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_DoorRR
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRR;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_EngineSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EngineSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_per_PdlPosAct
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_ActvParkMode
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_LanguageSeln
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TGWCamDispSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TchScrSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchScrSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TchXCoord
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchXCoord;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_TchYCoord
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchYCoord;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_GearShiftReqAccept
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.MeAP_e_FiltdGearRptState
    = *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ACCSysSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_nm_BrkTrqAct
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ParkingIntrvntionSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_HandsOnRecog
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_SPMLatCtrlRespSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_M_StrWhlTrq
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_VehLatAccFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_VehLongAccFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_VehYawRateFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_LHFWhlSnsrFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_LHRWhlSnsrFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_RHFWhlSnsrFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_RHRWhlSnsrFailSts
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_PAMBrkReqRespStatus
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ShiftLvrPos
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_nm_BrkTrqDriver
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ExtBrkReqDisabled
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_ParkingGearShiftReq
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_pct_Slope
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_pct_Slope;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_DriverReqAxleTrqEnabled
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_e_BrkPdlStat
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_Override
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_Override;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_TrqEnblReqAllowed
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1.IeVBII_b_ParkProxChime
    = *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime;

  /* BusCreator generated from: '<S57>/Rear_ObjectDetection' */
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_CanNode67DTCM
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_CanNode63TTM
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_StopAndStrt
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_mm_TyreSz
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_SteerRatRackPinionTyp
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_DrvTypVrnt
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_GbTyp
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_GbTyp;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_PAMTunSet
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_VehLineCfg
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_CtryCod
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_CtryCod;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_HybTyp
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_HybTyp;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_WhlBas
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_WhlBas;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_ParkWithStop
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_PAMCfg
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_RadioDispTyp
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_CanNode95ITBMTCM
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_DrvSide
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_DrvSide;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_SemiAutoPrkgSys
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_e_MdlYr
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_MdlYr;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_PullOutCtrlPres
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_FullAutoPrkgSys
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_TrlrHitchAsstPres
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_TrlrRvsSteerPres
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_b_SVSPresent
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent;
  SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1.KeAP_k_VariantID
    = *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_k_VariantID;

  /* ModelReference generated from: '<S57>/Rear_ObjectDetection' */
  Rear_ObjectDection
    (&SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1,
     SWC_APA_rtu_USS_2DPointMap,
     SWC_APA_rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth,
     SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj,
     &SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1,
     &SWC_APA_B.FixPtRelationalOperator, SWC_APA_rty_MeAP_b_PAMBrkReqStatus,
     &SWC_APA_B.MeAP_cm_RearDist, &SWC_APA_B.MeAP_b_ObjInPath,
     &SWC_APA_B.MeAP_cm_RearDist_Int);

  /* DataTypeConversion: '<S651>/Data Type Conversion1' */
  SWC_APA_B.DataTypeConversion1 = SWC_APA_B.MeAP_cm_RearDist_Int;

  /* RelationalOperator: '<S657>/Compare' incorporates:
   *  Constant: '<S657>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.DataTypeConversion1 <
    KeAP_cm_RearBrkDistChngLwThresh);

  /* UnitDelay: '<S651>/Unit Delay' */
  SWC_APA_B.DataTypeConversion_i = SWC_APA_DW.UnitDelay_DSTATE;

  /* RelationalOperator: '<S656>/Compare' incorporates:
   *  Constant: '<S656>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.DataTypeConversion_i > 1022.0F);

  /* Logic: '<S651>/Logical Operator' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.RelationalOperator1_e1);

  /* UnitDelay: '<S660>/Unit Delay3' */
  SWC_APA_B.UnitDelay3 = SWC_APA_B.Switch5;

  /* Switch: '<S660>/Switch5' incorporates:
   *  Constant: '<S660>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator2_j) {
    SWC_APA_B.Switch5 = true;
  } else {
    /* RelationalOperator: '<S651>/Relational Operator' incorporates:
     *  Constant: '<S659>/Constant'
     */
    SWC_APA_B.EnableRearBraking =
      (*SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear !=
       TeAP_e_FiltdGearState_ReverseGear);

    /* Switch: '<S660>/Switch6' incorporates:
     *  Constant: '<S660>/Constant3'
     */
    if (SWC_APA_B.EnableRearBraking) {
      SWC_APA_B.Switch6_d = false;
    } else {
      SWC_APA_B.Switch6_d = SWC_APA_B.UnitDelay3;
    }

    /* End of Switch: '<S660>/Switch6' */
    SWC_APA_B.Switch5 = SWC_APA_B.Switch6_d;
  }

  /* End of Switch: '<S660>/Switch5' */

  /* SignalConversion: '<S651>/Signal Conversion' */
  SWC_APA_B.MeAP_b_DisableRearBrarking = SWC_APA_B.Switch5;

  /* UnitDelay: '<S661>/Unit Delay' */
  SWC_APA_B.UnitDelay = SWC_APA_DW.UnitDelay_DSTATE_a;

  /* DataTypeConversion: '<S653>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_n = SWC_APA_B.MeAP_cm_RearDist;

  /* Chart: '<S653>/RearDistHold' */
  if (SWC_APA_DW.is_active_c16_SWC_APA == 0U) {
    SWC_APA_DW.is_active_c16_SWC_APA = 1U;
    SWC_APA_B.MeAP_cm_RearDist_Out = ((int16_T)CeAP_cm_DefaultRearDistInt16);
    SWC_APA_DW.RearDistHoldCount = ((uint8_T)CeAP_k_Uint8Zero);
    SWC_APA_DW.RearDistHold = false;
    if ((SWC_APA_B.MeAP_cm_RearDist_Out < ((int16_T)CeAP_cm_EnRaebDistHoldThsd))
        && (SWC_APA_B.DataTypeConversion_n > SWC_APA_B.MeAP_cm_RearDist_Out) &&
        (SWC_APA_B.DataTypeConversion_n != ((int16_T)
          CeAP_cm_DefaultRearDistInt16)) &&
        (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus !=
         TeVBII_e_PAMBrkReqRespStatus_Active) && ((!SWC_APA_DW.RearDistHold) ||
         (SWC_APA_DW.RearDistHoldCount <= ((uint8_T)CeAP_ms_RaebThsdHold1)))) {
      SWC_APA_DW.RearDistHold = true;
      SWC_APA_DW.RearDistHoldCount = (uint8_T)((uint32_T)
        SWC_APA_DW.RearDistHoldCount + (uint8_T)CeAP_ms_SampleTime);
    } else {
      SWC_APA_DW.RearDistHold = false;
    }

    if ((SWC_APA_B.MeAP_cm_RearDist_Out != ((int16_T)
          CeAP_cm_DefaultRearDistInt16)) && (SWC_APA_B.DataTypeConversion_n ==
         ((int16_T)CeAP_cm_DefaultRearDistInt16)) && ((!SWC_APA_DW.RearDistHold1)
         || (SWC_APA_DW.RearDistHoldCount1 <= ((uint8_T)CeAP_ms_RaebThsdHold2))))
    {
      SWC_APA_DW.RearDistHold1 = true;
      SWC_APA_DW.RearDistHoldCount1 = (uint8_T)((uint32_T)
        SWC_APA_DW.RearDistHoldCount1 + (uint8_T)CeAP_ms_SampleTime);
    } else {
      SWC_APA_DW.RearDistHold1 = false;
      SWC_APA_DW.RearDistHoldCount1 = ((uint8_T)CeAP_k_Uint8Zero);
    }

    if ((SWC_APA_B.DataTypeConversion_n < SWC_APA_B.MeAP_cm_RearDist_Out) ||
        ((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus !=
          TeVBII_e_PAMBrkReqRespStatus_Active) && (!SWC_APA_DW.RearDistHold) &&
         (!SWC_APA_DW.RearDistHold1))) {
      SWC_APA_B.MeAP_cm_RearDist_Out = SWC_APA_B.DataTypeConversion_n;
    } else {
      if (((!(*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus ==
              TeVBII_e_PAMBrkReqRespStatus_Active)) && (!SWC_APA_DW.RearDistHold)
           && (!SWC_APA_DW.RearDistHold1)) || (!(SWC_APA_B.DataTypeConversion_n >
            SWC_APA_B.MeAP_cm_RearDist_Out)) ||
          (!*SWC_APA_rty_MeAP_b_PAMBrkReqStatus) ||
          (!(*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
             TeVBII_e_CmdIgnSts_RUN))) {
        SWC_APA_B.MeAP_cm_RearDist_Out = SWC_APA_B.DataTypeConversion_n;
      }
    }
  } else {
    if ((SWC_APA_B.MeAP_cm_RearDist_Out < ((int16_T)CeAP_cm_EnRaebDistHoldThsd))
        && (SWC_APA_B.DataTypeConversion_n > SWC_APA_B.MeAP_cm_RearDist_Out) &&
        (SWC_APA_B.DataTypeConversion_n != ((int16_T)
          CeAP_cm_DefaultRearDistInt16)) &&
        (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus !=
         TeVBII_e_PAMBrkReqRespStatus_Active) && ((!SWC_APA_DW.RearDistHold) ||
         (SWC_APA_DW.RearDistHoldCount <= ((uint8_T)CeAP_ms_RaebThsdHold1)))) {
      SWC_APA_DW.RearDistHold = true;
      SWC_APA_DW.RearDistHoldCount = (uint8_T)((uint32_T)
        SWC_APA_DW.RearDistHoldCount + (uint8_T)CeAP_ms_SampleTime);
    } else {
      SWC_APA_DW.RearDistHold = false;
      SWC_APA_DW.RearDistHoldCount = ((uint8_T)CeAP_k_Uint8Zero);
    }

    if ((SWC_APA_B.MeAP_cm_RearDist_Out != ((int16_T)
          CeAP_cm_DefaultRearDistInt16)) && (SWC_APA_B.DataTypeConversion_n ==
         ((int16_T)CeAP_cm_DefaultRearDistInt16)) && ((!SWC_APA_DW.RearDistHold1)
         || (SWC_APA_DW.RearDistHoldCount1 <= ((uint8_T)CeAP_ms_RaebThsdHold2))))
    {
      SWC_APA_DW.RearDistHold1 = true;
      SWC_APA_DW.RearDistHoldCount1 = (uint8_T)((uint32_T)
        SWC_APA_DW.RearDistHoldCount1 + (uint8_T)CeAP_ms_SampleTime);
    } else {
      SWC_APA_DW.RearDistHold1 = false;
      SWC_APA_DW.RearDistHoldCount1 = ((uint8_T)CeAP_k_Uint8Zero);
    }

    if ((SWC_APA_B.DataTypeConversion_n < SWC_APA_B.MeAP_cm_RearDist_Out) ||
        ((*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus !=
          TeVBII_e_PAMBrkReqRespStatus_Active) && (!SWC_APA_DW.RearDistHold) &&
         (!SWC_APA_DW.RearDistHold1))) {
      SWC_APA_B.MeAP_cm_RearDist_Out = SWC_APA_B.DataTypeConversion_n;
    } else {
      if (((!(*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus ==
              TeVBII_e_PAMBrkReqRespStatus_Active)) && (!SWC_APA_DW.RearDistHold)
           && (!SWC_APA_DW.RearDistHold1)) || (!(SWC_APA_B.DataTypeConversion_n >
            SWC_APA_B.MeAP_cm_RearDist_Out)) ||
          (!*SWC_APA_rty_MeAP_b_PAMBrkReqStatus) ||
          (!(*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
             TeVBII_e_CmdIgnSts_RUN))) {
        SWC_APA_B.MeAP_cm_RearDist_Out = SWC_APA_B.DataTypeConversion_n;
      }
    }
  }

  /* End of Chart: '<S653>/RearDistHold' */

  /* DataTypeConversion: '<S651>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion_i = SWC_APA_B.MeAP_cm_RearDist_Out;

  /* RelationalOperator: '<S662>/Compare' incorporates:
   *  Constant: '<S662>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.UnitDelay >
    KeAP_cm_RearBrkDistChngUpThresh);

  /* RelationalOperator: '<S663>/Compare' incorporates:
   *  Constant: '<S663>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.UnitDelay < 1023.0F);

  /* RelationalOperator: '<S664>/Compare' incorporates:
   *  Constant: '<S664>/Constant'
   */
  SWC_APA_B.Compare_k = (SWC_APA_B.DataTypeConversion_i <
    KeAP_cm_RearBrkDistChngLwThresh);

  /* Logic: '<S661>/Logical Operator1' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 &&
    SWC_APA_B.RelationalOperator2_j && SWC_APA_B.Compare_k);

  /* Switch: '<S661>/Switch' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    /* Sum: '<S661>/Sum1' incorporates:
     *  Constant: '<S661>/Constant3'
     */
    SWC_APA_B.Sum1 = SWC_APA_B.UnitDelay - 10.0F;
    SWC_APA_B.Switch = SWC_APA_B.Sum1;
  } else {
    SWC_APA_B.Switch = SWC_APA_B.DataTypeConversion_i;
  }

  /* End of Switch: '<S661>/Switch' */

  /* Switch: '<S651>/Switch1' incorporates:
   *  Constant: '<S651>/Constant'
   */
  if (SWC_APA_B.MeAP_b_DisableRearBrarking) {
    *SWC_APA_rty_MeAP_cm_RearDist = 1023.0F;
  } else {
    *SWC_APA_rty_MeAP_cm_RearDist = SWC_APA_B.Switch;
  }

  /* End of Switch: '<S651>/Switch1' */

  /* RelationalOperator: '<S658>/Compare' incorporates:
   *  Constant: '<S658>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 = (*SWC_APA_rty_MeAP_cm_RearDist < 1023.0F);

  /* Switch: '<S651>/Switch' incorporates:
   *  Constant: '<S651>/Constant1'
   */
  if (SWC_APA_B.RelationalOperator1_e1) {
    SWC_APA_B.MeAP_b_PAMBrkReqStatus = SWC_APA_B.MeAP_b_ObjInPath;
  } else {
    SWC_APA_B.MeAP_b_PAMBrkReqStatus = false;
  }

  /* End of Switch: '<S651>/Switch' */

  /* RelationalOperator: '<S652>/Relational Operator4' incorporates:
   *  Constant: '<S668>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts !=
     TeVBII_e_TrailerConnectionSts_Connected);

  /* Logic: '<S652>/Logical Operator13' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
    (*SWC_APA_rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27));

  /* Logic: '<S652>/Logical Operator3' */
  SWC_APA_B.RelationalOperator1_e1 =
    ((*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM) &&
     SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S652>/Logical Operator9' */
  SWC_APA_B.RelationalOperator2_j =
    !*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;

  /* Logic: '<S652>/Logical Operator2' */
  SWC_APA_B.LogicalOperator2 = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.RelationalOperator1_e1);

  /* RelationalOperator: '<S652>/Relational Operator9' incorporates:
   *  Constant: '<S671>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts !=
     TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S652>/Logical Operator15' */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.RelationalOperator1_e1 ||
    (*SWC_APA_rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27));

  /* Logic: '<S652>/Logical Operator6' */
  SWC_APA_B.RelationalOperator1_e1 =
    ((*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM) &&
     SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S652>/Logical Operator10' */
  SWC_APA_B.RelationalOperator2_j =
    !*SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;

  /* Logic: '<S652>/Logical Operator4' */
  SWC_APA_B.LogicalOperator4 = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.RelationalOperator1_e1);

  /* RelationalOperator: '<S652>/Relational Operator1' incorporates:
   *  Constant: '<S666>/Constant'
   */
  SWC_APA_B.RelationalOperator1_e1 =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus ==
     TeVBII_e_PAMBrkReqRespStatus_NotActive);

  /* RelationalOperator: '<S652>/Relational Operator2' incorporates:
   *  Constant: '<S667>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j =
    (*SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus ==
     TeVBII_e_PAMBrkReqRespStatus_Active);

  /* Logic: '<S652>/Logical Operator1' */
  SWC_APA_B.LogicalOperator1 = (SWC_APA_B.RelationalOperator1_e1 ||
    SWC_APA_B.RelationalOperator2_j);

  /* Update for Delay: '<S652>/Delay' */
  SWC_APA_DW.icLoad = 0U;
  SWC_APA_DW.Delay_DSTATE = SWC_APA_B.MeAP_b_PAMStopCtrlStatus;

  /* Update for UnitDelay: '<S654>/Delay Input1'
   *
   * Block description for '<S654>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SWC_APA_DW.DelayInput1_DSTATE = *SWC_APA_rty_MeAP_b_PAMBrkReqStatus;

  /* Update for UnitDelay: '<S651>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE = SWC_APA_B.DataTypeConversion1;

  /* Update for UnitDelay: '<S661>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_a = SWC_APA_B.Switch;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
