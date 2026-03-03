/*
 * File: SWC_APA_types.h
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

#ifndef RTW_HEADER_SWC_APA_types_h_
#define RTW_HEADER_SWC_APA_types_h_
#include "rtwtypes.h"
#include "PlatformDataTypes.h"
#include "LwSpd_SimulinkAdaptation.h"
#include "stdint.h"
#include "TeVBII_e_CmdIgnSts.h"
#include "TeVBII_e_TrailerConnectionSts.h"
#include "TeVBII_e_TrlrPrsntSts.h"
#include "TeVBII_e_BrkStat.h"
#include "TeVBII_e_VehEPBSts.h"
#include "TeVBII_e_TCaseRangeSts.h"
#include "TeVBII_e_EssEngState.h"
#include "TeVBII_e_PamChimeVol.h"
#include "TeAP_e_FiltdGearState.h"
#include "TeVBII_e_TransSailingTst.h"
#include "TeVBII_e_WhlSpnSts.h"
#include "TeVBII_e_ShiftLvrPosReq.h"
#include "TeVBII_e_TurnIndicSts.h"
#include "TeVBII_e_EngineSts.h"
#include "TeVBII_e_LanguageSeln.h"
#include "TeVBII_e_TGWCamDispSts.h"
#include "TeVBII_e_TchScrSts.h"
#include "TeVBII_e_ACCSysSts.h"
#include "TeVBII_e_ParkingIntrvntionSts.h"
#include "TeVBII_e_SPMLatCtrlRespSts.h"
#include "TeVBII_e_PAMBrkReqRespStatus.h"
#include "TeVBII_e_ShiftLvrPos.h"
#include "TeVBII_e_ExtBrkReqDisabled.h"
#include "TeVBII_e_ParkingGearShiftReq.h"
#include "TeVBII_e_DriverReqAxleTrqEnabled.h"
#include "TeVBII_e_BrkPdlStat.h"
#include "TeAP_e_SteerRatRackPinionTyp.h"
#include "TeAP_e_DrvTypVrnt.h"
#include "TeAP_e_GbTyp.h"
#include "TeAP_e_PAMTunSet.h"
#include "TeAP_e_CtryCod.h"
#include "TeAP_e_HybTyp.h"
#include "TeAP_e_WhlBas.h"
#include "TeAP_e_RadioDispTyp.h"
#include "TeAP_e_PAMOffStatus2BT.h"
#include "US_Interface_Output.h"
#include "TeAutoPark_e_AutoParkStatus.h"
#include "TeTHA_e_RearBrkSupprInfo.h"
#include "TeTRSC_e_TRSCPopupDispInfo.h"
#include "TeAutoPark_e_ScanDir.h"
#include "TeTRSC_e_TRSCSts.h"
#include "TeAP_e_FrntSnsrStatus.h"
#include "TeAP_e_RearSnsrStatus.h"
#include "TeAP_e_ParKMnvrActv.h"
#include "TeAP_e_ParkAssistStatus.h"
#include "TeAP_e_PAMSystemFault.h"
#include "TeAP_e_PAMChimeRepnRate.h"
#include "TeAP_e_Alert.h"
#include "TeAP_e_PAMLedCtrlStatus.h"
#include "TeAP_e_GraphicFlshRate.h"
#include "TeAP_e_PAMChimeTyp.h"
#include "TeAP_e_PAMPopUpReq.h"
#include "TeAP_e_SPMLatCtrlReqSts.h"
#include "TeAP_e_PAMVolume.h"
#ifndef DEFINED_TYPEDEF_FOR_TbVBIA_VehState_AP_
#define DEFINED_TYPEDEF_FOR_TbVBIA_VehState_AP_

typedef struct {
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;
  boolean_T IeVBII_b_FrntParkAsstReq;
  boolean_T IeVBII_b_ParkAsstReq;
  boolean_T IeVBII_b_RemoteStartActvSts;
  boolean_T IeVBII_b_SnowPlowAttached;
  TeVBII_e_TrailerConnectionSts IeVBII_e_TrailerConnectionSts;
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;
  real32_T IeVBII_degC_ExtTemp;
  TeVBII_e_BrkStat IeVBII_e_BrkStat;
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;
  TeVBII_e_TCaseRangeSts IeVBII_e_TCaseRangeSts;
  TeVBII_e_EssEngState IeVBII_e_EssEngState;
  TeVBII_e_PamChimeVol IeVBII_e_PamChimeVolFrnt;
  TeVBII_e_PamChimeVol IeVBII_e_PamChimeVolRear;
  boolean_T IeVBII_b_RearBrkAsst;
  TeAP_e_FiltdGearState MeAP_e_FiltdTrgtGear;
  TeVBII_e_TransSailingTst IeVBII_e_TransSailingTst;
  real32_T IeVBII_a_VehLatAcc;
  real32_T IeVBII_a_VehLongAcc;
  real32_T IeVBII_kph_VehSpeedVSOSig;
  real32_T IeVBII_ddeg_VehYawRate;
  uint8_T IeVBII_cnt_LhfPulseCtr;
  TeVBII_e_WhlSpnSts IeVBII_e_LhfWhlSpnSts;
  real32_T IeVBII_kph_LhfWhlSpd;
  uint8_T IeVBII_cnt_LhrPulseCtr;
  real32_T IeVBII_kph_LhrWhlSpd;
  uint8_T IeVBII_cnt_RhfPulseCtr;
  TeVBII_e_WhlSpnSts IeVBII_e_RhfWhlSpnSts;
  real32_T IeVBII_kph_RhfWhlSpd;
  uint8_T IeVBII_cnt_RhrPulseCtr;
  real32_T IeVBII_kph_RhrWhlSpd;
  real32_T IeVBII_deg_StrWhlAng;
  real32_T IeVBII_deg_StrWhlSpd;
  boolean_T IeVBII_b_ShifterAutoconnectSts;
  TeVBII_e_ShiftLvrPosReq IeVBII_e_ShiftLvrPosReq;
  boolean_T IeVBII_b_AutoParkEnblSwt;
  TeVBII_e_TurnIndicSts IeVBII_e_TurnIndicSts;
  boolean_T IeVBII_b_DriverDoorSts;
  boolean_T IeVBII_b_DoorRL;
  boolean_T IeVBII_b_DoorP;
  boolean_T IeVBII_b_TrnkStatus;
  boolean_T IeVBII_b_DoorRR;
  TeVBII_e_EngineSts IeVBII_e_EngineSts;
  real32_T IeVBII_per_PdlPosAct;
  boolean_T IeVBII_b_ActvParkMode;
  TeVBII_e_LanguageSeln IeVBII_e_LanguageSeln;
  TeVBII_e_TGWCamDispSts IeVBII_e_TGWCamDispSts;
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;
  uint16_T IeVBII_e_TchXCoord;
  uint16_T IeVBII_e_TchYCoord;
  boolean_T IeVBII_b_GearShiftReqAccept;
  TeAP_e_FiltdGearState MeAP_e_FiltdGearRptState;
  TeVBII_e_ACCSysSts IeVBII_e_ACCSysSts;
  uint32_T IeVBII_nm_BrkTrqAct;
  TeVBII_e_ParkingIntrvntionSts IeVBII_e_ParkingIntrvntionSts;
  boolean_T IeVBII_b_HandsOnRecog;
  TeVBII_e_SPMLatCtrlRespSts IeVBII_e_SPMLatCtrlRespSts;
  real32_T IeVBII_M_StrWhlTrq;
  boolean_T IeVBII_b_VehLatAccFailSts;
  boolean_T IeVBII_b_VehLongAccFailSts;
  boolean_T IeVBII_b_VehYawRateFailSts;
  boolean_T IeVBII_b_LHFWhlSnsrFailSts;
  boolean_T IeVBII_b_LHRWhlSnsrFailSts;
  boolean_T IeVBII_b_RHFWhlSnsrFailSts;
  boolean_T IeVBII_b_RHRWhlSnsrFailSts;
  TeVBII_e_PAMBrkReqRespStatus IeVBII_e_PAMBrkReqRespStatus;
  TeVBII_e_ShiftLvrPos IeVBII_e_ShiftLvrPos;
  uint32_T IeVBII_nm_BrkTrqDriver;
  TeVBII_e_ExtBrkReqDisabled IeVBII_e_ExtBrkReqDisabled;
  TeVBII_e_ParkingGearShiftReq IeVBII_e_ParkingGearShiftReq;
  int16_T IeVBII_pct_Slope;
  TeVBII_e_DriverReqAxleTrqEnabled IeVBII_e_DriverReqAxleTrqEnabled;
  TeVBII_e_BrkPdlStat IeVBII_e_BrkPdlStat;
  boolean_T IeVBII_b_Override;
  boolean_T IeVBII_b_TrqEnblReqAllowed;
  boolean_T IeVBII_b_ParkProxChime;
} TbVBIA_VehState_AP;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbNVM_ProxyCalibParam_
#define DEFINED_TYPEDEF_FOR_TbNVM_ProxyCalibParam_

typedef struct {
  boolean_T KeAP_b_CanNode67DTCM;
  boolean_T KeAP_b_CanNode63TTM;
  boolean_T KeAP_b_StopAndStrt;
  uint16_T KeAP_mm_TyreSz;
  TeAP_e_SteerRatRackPinionTyp KeAP_e_SteerRatRackPinionTyp;
  TeAP_e_DrvTypVrnt KeAP_e_DrvTypVrnt;
  TeAP_e_GbTyp KeAP_e_GbTyp;
  TeAP_e_PAMTunSet KeAP_e_PAMTunSet;
  uint8_T KeAP_e_VehLineCfg;
  TeAP_e_CtryCod KeAP_e_CtryCod;
  TeAP_e_HybTyp KeAP_e_HybTyp;
  TeAP_e_WhlBas KeAP_e_WhlBas;
  boolean_T KeAP_b_ParkWithStop;
  boolean_T KeAP_b_PAMCfg;
  TeAP_e_RadioDispTyp KeAP_e_RadioDispTyp;
  boolean_T KeAP_b_CanNode95ITBMTCM;
  boolean_T KeAP_b_DrvSide;
  boolean_T KeAP_b_SemiAutoPrkgSys;
  uint16_T KeAP_e_MdlYr;
  boolean_T KeAP_b_PullOutCtrlPres;
  boolean_T KeAP_b_FullAutoPrkgSys;
  boolean_T KeAP_b_TrlrHitchAsstPres;
  boolean_T KeAP_b_TrlrRvsSteerPres;
  boolean_T KeAP_b_SVSPresent;
  uint8_T KeAP_k_VariantID;
} TbNVM_ProxyCalibParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbFID_PA_
#define DEFINED_TYPEDEF_FOR_TbFID_PA_

typedef struct {
  boolean_T MeAP_b_ExternalFail;
  boolean_T MeAP_b_SystemFail;
  boolean_T MeAP_b_FPADisable;
  boolean_T MeAP_b_RPADisable;
  boolean_T MeAP_b_RPAActvTrlr_27;
  boolean_T MeAP_b_RPAActvTrlr_29;
  boolean_T MeAP_b_PAVolDefMed;
  boolean_T MeAP_b_FPAVolDefMed;
  boolean_T MeAP_b_RPAVolDefMed;
  boolean_T MeAP_b_FrntSenorFail;
  boolean_T MeAP_b_FrntSenorBlock;
  boolean_T MeAP_b_RearSenorFail;
  boolean_T MeAP_b_RearSenorBlock;
} TbFID_PA;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbFID_PARB_
#define DEFINED_TYPEDEF_FOR_TbFID_PARB_

typedef struct {
  boolean_T MeAP_b_PARBActvTrlr_27;
  boolean_T MeAP_b_PARBActvTrlr_29;
  boolean_T MeAP_b_PARBActv4LOW;
  boolean_T MeAP_b_PARBDiable;
} TbFID_PARB;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbNVM_ReadParam_
#define DEFINED_TYPEDEF_FOR_TbNVM_ReadParam_

typedef struct {
  TeAP_e_PAMOffStatus2BT IeNVM_e_FrntRearParkSts;
  boolean_T IeNVM_b_PAMRearCtrlSts;
  uint8_T Dtc_B12852A_Status;
} TbNVM_ReadParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbAP_InputVrntTunParam_t_
#define DEFINED_TYPEDEF_FOR_TbAP_InputVrntTunParam_t_

typedef struct {
  real32_T KeAP_degC_OperatingTempThd;
  real32_T KeAP_kph_EnblHysThd;
  real32_T KeAP_kph_FrntWarnMaxSpdThd;
  real32_T KeAP_kph_ParkMnvThd;
  real32_T KeAP_kph_PSDOffThd;
  real32_T KeAP_kph_PSDOnThd;
  real32_T KeAP_kph_RearWarnMaxSpdThd;
  real32_T KeAP_kph_USSActiveSpdThd;
  real32_T K_e_RAEB_VehicleWidth;
  real32_T K_Overlap_Thrsld_RAEB[5];
  real32_T KeTOS_s_InTurnDbncTm;
  real32_T KeTOS_s_StrDrvDbncTm;
  real32_T KeTOS_s_TurnExitDbncTm;
  real32_T KeTOS_x_InTurnThd;
  real32_T KeTOS_x_TurnExitThd;
  real32_T keVehParam_m_DistWhlBse;
  real32_T Obj_DistTable[5];
  real32_T Overlap_Thrsld_Switch;
  real32_T RAEB_Envelope_Offset;
  real32_T RAEB_Lateral_Distance_Notification;
  real32_T RAEB_Minimum_Object_Heigh;
  real32_T sampling_time;
  real32_T keVehParam_e_VehSteerRatioTable[19];
  real32_T keVehParam_e_StrWhlRatioBrkPnts[19];
  real32_T keInpAdptr_e_StWhOffset;
  real32_T Straight_Driving_Thresold_rads2;
  real32_T Steering_Angle_DeadZone_Start;
  real32_T Steering_Angle_DeadZone_End;
  real32_T KeAP_k_PathSepaMinSpd;
  real32_T KeAP_k_PathSepaSpdRampGrd;
  real32_T KeAP_k_DetWP_PreviewTime;
  real32_T KeAP_k_LatPathDevPGain;
  real32_T KeAP_k_LatPathDevIGain;
  real32_T KeAP_k_LatPathDevDGain;
  real32_T KeAP_k_LatHeadDevPGain;
  real32_T KeAP_k_LatHeadDevIGain;
  real32_T KeAP_k_LatHeadDevDGain;
  real32_T KeAP_k_SteerUpperLimit;
  real32_T KeAP_k_SteerLowerLimit;
  real32_T KeAP_k_CtrlOutCollDetActivate;
  real32_T KeAP_k_CtrlOutRemainDistNA;
  real32_T KeAP_k_CtrlOutCollDetCollDistLimit;
  real32_T KeAP_k_CtrlOutCollDetRedStopVal;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotSteer;
  real32_T KeAP_k_BrakePGain;
  real32_T KeAP_k_BrakeIGain;
  real32_T KeAP_k_BrakeUpperLimit;
  real32_T KeAP_k_BrakeLowerLimit;
  real32_T KeAP_k_CtrlOutGearDrive;
  real32_T KeAP_k_CtrlOutGearReverse;
  real32_T KeAP_k_CtrlOutGearPark;
  real32_T KeAP_k_WhlCircum;
  uint16_T KeAP_cnt_ChimeVolChgAlert;
  uint16_T KeAP_cnt_FrntChimeDisTimeThd;
  uint16_T KeAP_cnt_HalfSecChimeAlert;
  uint16_T KeAP_cnt_LEDBlinkTimeThd;
  uint16_T KeAP_cnt_VehKeyOnTimeThd;
  uint16_T KeAP_Cnt_GearFiltTimeThd;
  uint16_T KeAP_cnt_TimeStep;
  uint16_T KeAP_cm_ObjPrestFCDistThd;
  uint16_T KeAP_cm_ObjPrestRCDistThd;
  uint16_T KeAP_cm_VehicleWidth;
  uint16_T KeAP_Cnt_GearOverrideTimeThd;
  uint16_T KeAP_cnt_SwtStuckTimeThd;
  uint16_T KeAP_s_BSMInterfaceCntTimeout;
  uint16_T KeAP_s_CamHandshakeDur;
  uint16_T KeAP_s_EPSInterfaceCntTimeout;
  uint16_T KeAP_s_GearShiftWaitCntTimeout;
  uint16_T KeAP_s_MaxStandstillTimeThd;
  uint16_T KeAP_s_ObjInPathTimeoutDur;
  uint16_T KeAP_s_PausedPressBtnTimeoutDur;
  uint16_T KeAP_s_SeekPhaseTimeoutDur;
  uint16_T KeAP_s_SpdExceedDur;
  uint16_T KeAP_cnt_SPMBlinkLEDDur;
  int16_T KeAP_cm_VehContour_FSL_x;
  int16_T KeAP_cm_VehContour_FOL_x;
  int16_T KeAP_cm_VehContour_FIL_x;
  int16_T KeAP_cm_VehContour_FIR_x;
  int16_T KeAP_cm_VehContour_FOR_x;
  int16_T KeAP_cm_VehContour_FSR_x;
  int16_T KeAP_cm_VehContour_FSL_y;
  int16_T KeAP_cm_VehContour_FOL_y;
  int16_T KeAP_cm_VehContour_FIL_y;
  int16_T KeAP_cm_VehContour_FIR_y;
  int16_T KeAP_cm_VehContour_FOR_y;
  int16_T KeAP_cm_VehContour_FSR_y;
  int16_T KeAP_cm_VehContour_RSR_x;
  int16_T KeAP_cm_VehContour_ROR_x;
  int16_T KeAP_cm_VehContour_RIR_x;
  int16_T KeAP_cm_VehContour_RIL_x;
  int16_T KeAP_cm_VehContour_ROL_x;
  int16_T KeAP_cm_VehContour_RSL_x;
  int16_T KeAP_cm_VehContour_RSR_y;
  int16_T KeAP_cm_VehContour_ROR_y;
  int16_T KeAP_cm_VehContour_RIR_y;
  int16_T KeAP_cm_VehContour_RIL_y;
  int16_T KeAP_cm_VehContour_ROL_y;
  int16_T KeAP_cm_VehContour_RSL_y;
  int16_T KeAP_cm_DistZone1;
  int16_T KeAP_cm_DistZone2;
  int16_T KeAP_cm_DistZone3;
  int16_T KeAP_cm_DistZone4;
  int16_T KeAP_cm_DistZone5;
  int16_T KeAP_cm_DistZone6;
  int16_T KeAP_cnt_DebounceTimeThd;
  int16_T KeAP_cm_FrntLongDistAdj;
  int16_T KeAP_cm_HalfVehicleWidth;
  int16_T KeAP_cm_HookDistOffset;
  int16_T KeAP_cm_MaxNoObjDetctDist;
  int16_T KeAP_cm_RearLongDistAdj;
  int16_T KeAP_cm_WarnOffset;
  uint8_T KeAP_e_GbTypAT;
  uint8_T KeAP_pct_ObjConfidenceThd;
  uint8_T Reverse_Gr_num;
  boolean_T KeAP_b_AutoParkEn;
  boolean_T KeAP_b_FPAEn;
  boolean_T KeAP_b_FullAutoPark;
  boolean_T KeAP_b_HookConnected;
  boolean_T KeAP_b_RPAwithBrk;
  boolean_T KeAP_b_RPAwithSurroundView;
  boolean_T KeAP_b_SteerOnlyAutoPark;
  boolean_T KeCMbB_b_EnblOncObjDbnc;
  uint16_T KeAP_cnt_EngagedFullWaitCnt;
} TbAP_InputVrntTunParam_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbAP_FrontHighPointsPresent_
#define DEFINED_TYPEDEF_FOR_TbAP_FrontHighPointsPresent_

typedef struct {
  uint8_T MeAP_b_HighPointsPresentFront;
  uint8_T MeAP_b_HighPointsPresentFL;
  uint8_T MeAP_b_HighPointsPresentFR;
} TbAP_FrontHighPointsPresent;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbAP_RearHighPointsPresent_
#define DEFINED_TYPEDEF_FOR_TbAP_RearHighPointsPresent_

typedef struct {
  uint8_T MeAP_b_HighPointsPresentRear;
  uint8_T MeAP_b_HighPointsPresentRL;
  uint8_T MeAP_b_HighPointsPresentRR;
} TbAP_RearHighPointsPresent;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_SWC_APA_T RT_MODEL_SWC_APA_T;

#endif                                 /* RTW_HEADER_SWC_APA_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
