/*
 * File: SWC_APA.c
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

#include "SWC_APA.h"
#include "SWC_APA_private.h"

/* Named constants for Chart: '<S5>/APA_StateMachine' */
#define SWC_APA_IN_ACTIVE              ((uint8_T)1U)
#define SWC_APA_IN_DisableFPA          ((uint8_T)1U)
#define SWC_APA_IN_DisableRPA          ((uint8_T)1U)
#define SWC_APA_IN_FPA_Degradded       ((uint8_T)1U)
#define SWC_APA_IN_INIT                ((uint8_T)2U)
#define SWC_APA_IN_NO_ACTIVE_CHILD_im  ((uint8_T)0U)
#define SWC_APA_IN_OFF                 ((uint8_T)1U)
#define SWC_APA_IN_ON                  ((uint8_T)2U)
#define SWC_APA_IN_Off                 ((uint8_T)2U)
#define SWC_APA_IN_Off_e               ((uint8_T)1U)
#define SWC_APA_IN_On                  ((uint8_T)3U)
#define SWC_APA_IN_On_f                ((uint8_T)2U)
#define SWC_APA_IN_PA_FAULT            ((uint8_T)1U)
#define SWC_APA_IN_PA_NO_FAULT         ((uint8_T)2U)
#define SWC_APA_IN_RPA_Degradded       ((uint8_T)3U)
#define SWC_APA_IN_STANDBY             ((uint8_T)3U)
#define SWC_APA_IN_SpeedExceed         ((uint8_T)2U)

const TbVBIA_VehState_AP SWC_APA_rtZTbVBIA_VehState_AP = {
  TeVBII_e_CmdIgnSts_Initialization,   /* IeVBII_e_CmdIgnSts */
  false,                               /* IeVBII_b_FrntParkAsstReq */
  false,                               /* IeVBII_b_ParkAsstReq */
  false,                               /* IeVBII_b_RemoteStartActvSts */
  false,                               /* IeVBII_b_SnowPlowAttached */
  TeVBII_e_TrailerConnectionSts_NotConnected,/* IeVBII_e_TrailerConnectionSts */
  TeVBII_e_TrlrPrsntSts_NO_TRLR,       /* IeVBII_e_TrlrPrsntSts */
  0.0F,                                /* IeVBII_degC_ExtTemp */
  TeVBII_e_BrkStat_Idle,               /* IeVBII_e_BrkStat */
  TeVBII_e_VehEPBSts_Released,         /* IeVBII_e_VehEPBSts */
  TeVBII_e_TCaseRangeSts_HIGH,         /* IeVBII_e_TCaseRangeSts */
  TeVBII_e_EssEngState_SNA,            /* IeVBII_e_EssEngState */
  TeVBII_e_PamChimeVol_Medium,         /* IeVBII_e_PamChimeVolFrnt */
  TeVBII_e_PamChimeVol_Medium,         /* IeVBII_e_PamChimeVolRear */
  false,                               /* IeVBII_b_RearBrkAsst */
  TeAP_e_FiltdGearState_SNA,           /* MeAP_e_FiltdTrgtGear */
  TeVBII_e_TransSailingTst_Sailing_Not_Possible,/* IeVBII_e_TransSailingTst */
  0.0F,                                /* IeVBII_a_VehLatAcc */
  0.0F,                                /* IeVBII_a_VehLongAcc */
  0.0F,                                /* IeVBII_kph_VehSpeedVSOSig */
  0.0F,                                /* IeVBII_ddeg_VehYawRate */
  0U,                                  /* IeVBII_cnt_LhfPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_LhfWhlSpnSts */
  0.0F,                                /* IeVBII_kph_LhfWhlSpd */
  0U,                                  /* IeVBII_cnt_LhrPulseCtr */
  0.0F,                                /* IeVBII_kph_LhrWhlSpd */
  0U,                                  /* IeVBII_cnt_RhfPulseCtr */
  TeVBII_e_WhlSpnSts_StandStill,       /* IeVBII_e_RhfWhlSpnSts */
  0.0F,                                /* IeVBII_kph_RhfWhlSpd */
  0U,                                  /* IeVBII_cnt_RhrPulseCtr */
  0.0F,                                /* IeVBII_kph_RhrWhlSpd */
  0.0F,                                /* IeVBII_deg_StrWhlAng */
  0.0F,                                /* IeVBII_deg_StrWhlSpd */
  false,                               /* IeVBII_b_ShifterAutoconnectSts */
  TeVBII_e_ShiftLvrPosReq_No_Selection_Active_Or_Available,/* IeVBII_e_ShiftLvrPosReq */
  false,                               /* IeVBII_b_AutoParkEnblSwt */
  TeVBII_e_TurnIndicSts_Centre,        /* IeVBII_e_TurnIndicSts */
  false,                               /* IeVBII_b_DriverDoorSts */
  false,                               /* IeVBII_b_DoorRL */
  false,                               /* IeVBII_b_DoorP */
  false,                               /* IeVBII_b_TrnkStatus */
  false,                               /* IeVBII_b_DoorRR */
  TeVBII_e_EngineSts_Engine_Off,       /* IeVBII_e_EngineSts */
  0.0F,                                /* IeVBII_per_PdlPosAct */
  false,                               /* IeVBII_b_ActvParkMode */
  TeVBII_e_LanguageSeln_Italian,       /* IeVBII_e_LanguageSeln */
  TeVBII_e_TGWCamDispSts_DISP_NON_CAMERA,/* IeVBII_e_TGWCamDispSts */
  TeVBII_e_TchScrSts_TCH_NOT_PSD,      /* IeVBII_e_TchScrSts */
  0U,                                  /* IeVBII_e_TchXCoord */
  0U,                                  /* IeVBII_e_TchYCoord */
  false,                               /* IeVBII_b_GearShiftReqAccept */
  TeAP_e_FiltdGearState_SNA,           /* MeAP_e_FiltdGearRptState */
  TeVBII_e_ACCSysSts_Off,              /* IeVBII_e_ACCSysSts */
  0U,                                  /* IeVBII_nm_BrkTrqAct */
  TeVBII_e_ParkingIntrvntionSts_NotActive,/* IeVBII_e_ParkingIntrvntionSts */
  false,                               /* IeVBII_b_HandsOnRecog */
  TeVBII_e_SPMLatCtrlRespSts_Idle,     /* IeVBII_e_SPMLatCtrlRespSts */
  0.0F,                                /* IeVBII_M_StrWhlTrq */
  false,                               /* IeVBII_b_VehLatAccFailSts */
  false,                               /* IeVBII_b_VehLongAccFailSts */
  false,                               /* IeVBII_b_VehYawRateFailSts */
  false,                               /* IeVBII_b_LHFWhlSnsrFailSts */
  false,                               /* IeVBII_b_LHRWhlSnsrFailSts */
  false,                               /* IeVBII_b_RHFWhlSnsrFailSts */
  false,                               /* IeVBII_b_RHRWhlSnsrFailSts */
  TeVBII_e_PAMBrkReqRespStatus_NotActive,/* IeVBII_e_PAMBrkReqRespStatus */
  TeVBII_e_ShiftLvrPos_No_Selection_Active_Or_Available,/* IeVBII_e_ShiftLvrPos */
  0U,                                  /* IeVBII_nm_BrkTrqDriver */
  TeVBII_e_ExtBrkReqDisabled_NoRequest,/* IeVBII_e_ExtBrkReqDisabled */
  TeVBII_e_ParkingGearShiftReq_Idle,   /* IeVBII_e_ParkingGearShiftReq */
  0,                                   /* IeVBII_pct_Slope */
  TeVBII_e_DriverReqAxleTrqEnabled_No_Req,/* IeVBII_e_DriverReqAxleTrqEnabled */
  TeVBII_e_BrkPdlStat_UPSTOP,          /* IeVBII_e_BrkPdlStat */
  false,                               /* IeVBII_b_Override */
  false,                               /* IeVBII_b_TrqEnblReqAllowed */
  false                                /* IeVBII_b_ParkProxChime */
} ;                                    /* TbVBIA_VehState_AP ground */

const TbNVM_ProxyCalibParam SWC_APA_rtZTbNVM_ProxyCalibParam = {
  false,                               /* KeAP_b_CanNode67DTCM */
  false,                               /* KeAP_b_CanNode63TTM */
  false,                               /* KeAP_b_StopAndStrt */
  0U,                                  /* KeAP_mm_TyreSz */
  TeAP_e_SteerRatRackPinionTyp_Type_1, /* KeAP_e_SteerRatRackPinionTyp */
  TeAP_e_DrvTypVrnt_FWD,               /* KeAP_e_DrvTypVrnt */
  TeAP_e_GbTyp_ATX,                    /* KeAP_e_GbTyp */
  TeAP_e_PAMTunSet_Base,               /* KeAP_e_PAMTunSet */
  0U,                                  /* KeAP_e_VehLineCfg */
  TeAP_e_CtryCod_World,                /* KeAP_e_CtryCod */
  TeAP_e_HybTyp_Not_Applicable,        /* KeAP_e_HybTyp */
  TeAP_e_WhlBas_Type_1,                /* KeAP_e_WhlBas */
  false,                               /* KeAP_b_ParkWithStop */
  false,                               /* KeAP_b_PAMCfg */
  TeAP_e_RadioDispTyp_Type_0,          /* KeAP_e_RadioDispTyp */
  false,                               /* KeAP_b_CanNode95ITBMTCM */
  false,                               /* KeAP_b_DrvSide */
  false,                               /* KeAP_b_SemiAutoPrkgSys */
  0U,                                  /* KeAP_e_MdlYr */
  false,                               /* KeAP_b_PullOutCtrlPres */
  false,                               /* KeAP_b_FullAutoPrkgSys */
  false,                               /* KeAP_b_TrlrHitchAsstPres */
  false,                               /* KeAP_b_TrlrRvsSteerPres */
  false,                               /* KeAP_b_SVSPresent */
  0U                                   /* KeAP_k_VariantID */
} ;                                    /* TbNVM_ProxyCalibParam ground */

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T MeAP_b_FPASwtStuckStatus;    /* '<S16>/Logical Operator' */
boolean_T MeAP_b_FrntParkAssistStatus; /* '<S14>/Logical Operator' */
boolean_T MeAP_b_FrontParkAssistEnbl;  /* '<S12>/Logical Operator5' */
boolean_T MeAP_b_RPASwtStuckStatus;    /* '<S17>/Logical Operator' */
boolean_T MeAP_b_RearParkAssistEnbl;   /* '<S15>/Logical Operator1' */
boolean_T MeAP_b_RearParkAssistStatus; /* '<S14>/Logical Operator1' */
MdlrefDW_SWC_APA_T SWC_APA_MdlrefDW;

/* Block signals (default storage) */
B_SWC_APA_c_T SWC_APA_B;

/* Block states (default storage) */
DW_SWC_APA_f_T SWC_APA_DW;

/* Forward declaration for local functions */
static void SWC_APA_exit_internal_ACTIVE(void);
static void SWC_APA_ACTIVE(const TeAP_e_FiltdGearState
  *rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear, const real32_T
  *rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FPADisable, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPADisable, const TeAP_e_ParKMnvrActv
  *rtu_IeAP_e_ParKMnvrActv, const TeTHA_e_RearBrkSupprInfo
  *rtu_MeTHA_e_RearBrkSupprInfo, const boolean_T *rtu_MbDiag_TestModeForceOn,
  TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus, boolean_T
  *rty_MeAP_b_FPAStatus, boolean_T *rty_MeAP_b_RPAStatus, TeAP_e_PAMOffStatus2BT
  *rty_MeAP_e_PAMOffStatus2BT, TeAP_e_FrntSnsrStatus *rty_IeAP_e_FrntSnsrStatus,
  TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus);
static void SWC_APA_inner_default_PA_FAULT(const boolean_T
  *rtu_IbFID_PA_MeAP_b_ExternalFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_SystemFail, const boolean_T *rtu_MbDiag_PlantModeOn,
  TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus, TeAP_e_PAMSystemFault
  *rty_IeAP_e_PAMSystemFault);

/* Declare global variables for system: model 'SWC_APA' */
const TeVBII_e_CmdIgnSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TrailerConnectionSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TrlrPrsntSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_BrkStat *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkStat;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_VehEPBSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TCaseRangeSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_EssEngState *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EssEngState;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_PamChimeVol *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_PamChimeVol *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst;/* '<Root>/IbVBIA_VehState' */
const TeAP_e_FiltdGearState *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TransSailingTst
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate;/* '<Root>/IbVBIA_VehState' */
const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_WhlSpnSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd;/* '<Root>/IbVBIA_VehState' */
const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd;/* '<Root>/IbVBIA_VehState' */
const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_WhlSpnSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd;/* '<Root>/IbVBIA_VehState' */
const uint8_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ShiftLvrPosReq
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TurnIndicSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRL;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorP;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRR;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_EngineSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EngineSts;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_LanguageSeln *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TGWCamDispSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_TchScrSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchScrSts;/* '<Root>/IbVBIA_VehState' */
const uint16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchXCoord;/* '<Root>/IbVBIA_VehState' */
const uint16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchYCoord;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept;/* '<Root>/IbVBIA_VehState' */
const TeAP_e_FiltdGearState
  *SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ACCSysSts *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts;/* '<Root>/IbVBIA_VehState' */
const uint32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ParkingIntrvntionSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_SPMLatCtrlRespSts
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts;/* '<Root>/IbVBIA_VehState' */
const real32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_PAMBrkReqRespStatus
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ShiftLvrPos *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos;/* '<Root>/IbVBIA_VehState' */
const uint32_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ExtBrkReqDisabled
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_ParkingGearShiftReq
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq;/* '<Root>/IbVBIA_VehState' */
const int16_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_pct_Slope;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_DriverReqAxleTrqEnabled
  *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled;/* '<Root>/IbVBIA_VehState' */
const TeVBII_e_BrkPdlStat *SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_Override;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime;/* '<Root>/IbVBIA_VehState' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt;/* '<Root>/MbNVM_ProxyParam' */
const uint16_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_SteerRatRackPinionTyp
  *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_DrvTypVrnt *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_GbTyp *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_GbTyp;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_PAMTunSet *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet;/* '<Root>/MbNVM_ProxyParam' */
const uint8_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_CtryCod *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_CtryCod;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_HybTyp *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_HybTyp;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_WhlBas *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_WhlBas;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg;/* '<Root>/MbNVM_ProxyParam' */
const TeAP_e_RadioDispTyp *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_DrvSide;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys;/* '<Root>/MbNVM_ProxyParam' */
const uint16_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_MdlYr;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent;/* '<Root>/MbNVM_ProxyParam' */
const uint8_T *SWC_APA_rtu_MbNVM_ProxyParam_KeAP_k_VariantID;/* '<Root>/MbNVM_ProxyParam' */
const boolean_T *SWC_APA_rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27;/* '<Root>/IbFID_PA' */
const boolean_T *SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBActv4LOW;/* '<Root>/IbFID_PARB' */
const boolean_T *SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBDiable;/* '<Root>/IbFID_PARB' */
const TbNVM_ReadParam *SWC_APA_rtu_MbNVM_ReadParam;/* '<Root>/MbNVM_ReadParam' */
const real32_T *SWC_APA_rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth;/* '<Root>/IbAP_InputVrntTunParam' */
const uint16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert;/* '<Root>/IbAP_InputVrntTunParam' */
const uint16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd;/* '<Root>/IbAP_InputVrntTunParam' */
const uint16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd;/* '<Root>/IbAP_InputVrntTunParam' */
const uint16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6;/* '<Root>/IbAP_InputVrntTunParam' */
const int16_T *SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj;/* '<Root>/IbAP_InputVrntTunParam' */
const US_S_PointMapOutputBuff_t *SWC_APA_rtu_USS_2DPointMap;/* '<Root>/USS_2DPointMap' */
const TeAP_e_ParKMnvrActv *SWC_APA_rtu_IeAP_e_ParKMnvrActv;/* '<Root>/IeAP_e_ParKMnvrActv' */
const TeTHA_e_RearBrkSupprInfo *SWC_APA_rtu_MeTHA_e_RearBrkSupprInfo;/* '<Root>/MeTHA_e_RearBrkSupprInfo' */
const int16_T *SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist;/* '<Root>/MeAP_cm_FrntCenterMinXDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist;/* '<Root>/MeAP_cm_FrntLeftMinXDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_FrntRightMinXDist;/* '<Root>/MeAP_cm_FrntRightMinXDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_RearCenterMinXDist;/* '<Root>/MeAP_cm_RearCenterMinXDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_RearLeftMinXDist;/* '<Root>/MeAP_cm_RearLeftMinXDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_RearRightMinXDist;/* '<Root>/MeAP_cm_RearRightMinXDist' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR;
                                    /* '<Root>/MeAP_b_HighPointsPresentFront' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
const uint8_T
  *SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR;
                                     /* '<Root>/MeAP_b_HighPointsPresentRear' */
const uint8_T *SWC_APA_rtu_MeAP_b_IsWall;/* '<Root>/MeAP_b_IsWall' */
const int16_T *SWC_APA_rtu_MeAP_cm_WallFrntCenterDist;/* '<Root>/MeAP_cm_WallFrntCenterDist' */
const int16_T *SWC_APA_rtu_MeAP_cm_WallRearCenterDist;/* '<Root>/MeAP_cm_WallRearCenterDist' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertCHF;/* '<Root>/MeAP_e_AlertCHF' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertLHF;/* '<Root>/MeAP_e_AlertLHF' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertRHF;/* '<Root>/MeAP_e_AlertRHF' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertCHR;/* '<Root>/MeAP_e_AlertCHR' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertLHR;/* '<Root>/MeAP_e_AlertLHR' */
TeAP_e_Alert *SWC_APA_rty_MeAP_e_AlertRHR;/* '<Root>/MeAP_e_AlertRHR' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicCHF;/* '<Root>/MeAP_e_GraphicCHF' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicLHF;/* '<Root>/MeAP_e_GraphicLHF' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicRHF;/* '<Root>/MeAP_e_GraphicRHF' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicCHR;/* '<Root>/MeAP_e_GraphicCHR' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicLHR;/* '<Root>/MeAP_e_GraphicLHR' */
TeAP_e_GraphicFlshRate *SWC_APA_rty_MeAP_e_GraphicRHR;/* '<Root>/MeAP_e_GraphicRHR' */
TeAP_e_PAMLedCtrlStatus *SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus;
                                      /* '<Root>/MeAP_e_FrntPAMLedCtrlStatus' */
TeAP_e_PAMLedCtrlStatus *SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus;
                                      /* '<Root>/MeAP_e_RearPAMLedCtrlStatus' */
boolean_T *SWC_APA_rty_MeAP_b_PAMBrkReqStatus;/* '<Root>/MeAP_b_PAMBrkReqStatus' */
real32_T *SWC_APA_rty_MeAP_cm_RearDist;/* '<Root>/MeAP_cm_RearDist' */
boolean_T *SWC_APA_rty_MeAP_b_PAMStopCtrlStatus;/* '<Root>/MeAP_b_PAMStopCtrlStatus' */
boolean_T *SWC_APA_rty_MeAP_b_FPAStatus;/* '<Root>/MeAP_b_FPAStatus' */
boolean_T *SWC_APA_rty_MeAP_b_RPAStatus;/* '<Root>/MeAP_b_RPAStatus' */
TeAP_e_PAMSystemFault *SWC_APA_rty_IeAP_e_PAMSystemFault;/* '<Root>/IeAP_e_PAMSystemFault' */
TeAP_e_PAMOffStatus2BT *SWC_APA_rty_MeAP_e_PAMOffStatus2BT;/* '<Root>/MeAP_e_PAMOffStatus2BT' */
TeAP_e_FrntSnsrStatus *SWC_APA_rty_IeAP_e_FrntSnsrStatus;/* '<Root>/IeAP_e_FrntSnsrStatus' */
TeAP_e_RearSnsrStatus *SWC_APA_rty_IeAP_e_RearSnsrStatus;/* '<Root>/IeAP_e_RearSnsrStatus' */

/* Function for Chart: '<S5>/APA_StateMachine' */
static void SWC_APA_exit_internal_ACTIVE(void)
{
  SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
  SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_NO_ACTIVE_CHILD_im;
  SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
  SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_NO_ACTIVE_CHILD_im;
}

/* Function for Chart: '<S5>/APA_StateMachine' */
static void SWC_APA_ACTIVE(const TeAP_e_FiltdGearState
  *rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear, const real32_T
  *rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig, const boolean_T
  *rtu_IbFID_PA_MeAP_b_FPADisable, const boolean_T
  *rtu_IbFID_PA_MeAP_b_RPADisable, const TeAP_e_ParKMnvrActv
  *rtu_IeAP_e_ParKMnvrActv, const TeTHA_e_RearBrkSupprInfo
  *rtu_MeTHA_e_RearBrkSupprInfo, const boolean_T *rtu_MbDiag_TestModeForceOn,
  TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus, boolean_T
  *rty_MeAP_b_FPAStatus, boolean_T *rty_MeAP_b_RPAStatus, TeAP_e_PAMOffStatus2BT
  *rty_MeAP_e_PAMOffStatus2BT, TeAP_e_FrntSnsrStatus *rty_IeAP_e_FrntSnsrStatus,
  TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus)
{
  boolean_T tmp;

  /* Constant: '<S11>/Constant' */
  if (!true) {
    SWC_APA_B.MeAP_TransitionDebugVar = 25U;
    SWC_APA_exit_internal_ACTIVE();
    SWC_APA_DW.is_ON = SWC_APA_IN_STANDBY;

    /* Chart: '<S5>/APA_StateMachine' */
    *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Standby;
    *rty_MeAP_b_FPAStatus = false;
    *rty_MeAP_b_RPAStatus = false;
    SWC_APA_B.MeAP_TransitionDebugVar = 5U;
  } else {
    switch (SWC_APA_DW.is_FPA_ACTIVE) {
     case SWC_APA_IN_FPA_Degradded:
      /* Chart: '<S5>/APA_StateMachine' */
      if (((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON) &&
           (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Semi) &&
           (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Full)) || ((
            !(*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_Drive)) &&
           (!(*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_ReverseGear))) ||
          (*rty_IeAP_e_FrntSnsrStatus != TeAP_e_FrntSnsrStatus_Active)) {
        SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
        SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_Off;
        *rty_MeAP_b_FPAStatus = false;
        SWC_APA_B.MeAP_TransitionDebugVar = 8U;
      } else if (SWC_APA_DW.is_FPA_Degradded == SWC_APA_IN_DisableFPA) {
        *rty_MeAP_b_FPAStatus = false;
        tmp = !*rtu_IbFID_PA_MeAP_b_FPADisable;
        if ((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
             SWC_APA_B.Saturation1) &&
            (!(*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 511.875F)) &&
            tmp) {
          SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_SpeedExceed;
          *rty_MeAP_b_FPAStatus = false;
        } else {
          if (tmp || (*rtu_MbDiag_TestModeForceOn)) {
            SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
            SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_On;
            *rty_MeAP_b_FPAStatus = true;
            SWC_APA_B.MeAP_TransitionDebugVar = 10U;
          }
        }
      } else {
        /* case IN_SpeedExceed: */
        *rty_MeAP_b_FPAStatus = false;

        /* ((IeVBII_kph_VehSpeedVSOSig < (KeAP_kph_FrntWarnMaxSpdThd-KeAP_kph_EnblHysThd) &&FPA_SpeedExceed) || !FPA_SpeedExceed) &&... */
        if (*rtu_IbFID_PA_MeAP_b_FPADisable) {
          SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_DisableFPA;
          *rty_MeAP_b_FPAStatus = false;
        } else {
          if ((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
               SWC_APA_B.Saturation1 - SWC_APA_B.Saturation) ||
              (*rtu_MbDiag_TestModeForceOn)) {
            SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
            SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_On;
            *rty_MeAP_b_FPAStatus = true;
            SWC_APA_B.MeAP_TransitionDebugVar = 10U;
          }
        }
      }
      break;

     case SWC_APA_IN_Off:
      /* Chart: '<S5>/APA_StateMachine' */
      *rty_MeAP_b_FPAStatus = false;

      /*  Enabling Conditions OR ECU Test Mode */
      if ((((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF)
            || (*rty_MeAP_e_PAMOffStatus2BT ==
                TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON) || (*rtu_IeAP_e_ParKMnvrActv
             == TeAP_e_ParKMnvrActv_Engaged_Semi) || (*rtu_IeAP_e_ParKMnvrActv ==
             TeAP_e_ParKMnvrActv_Engaged_Full)) &&
           ((*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
             TeAP_e_FiltdGearState_Drive) ||
            (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
             TeAP_e_FiltdGearState_ReverseGear)) &&
           (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
            SWC_APA_B.Saturation1) && (*rty_IeAP_e_FrntSnsrStatus ==
            TeAP_e_FrntSnsrStatus_Active) && (!*rtu_IbFID_PA_MeAP_b_FPADisable))
          || (*rtu_MbDiag_TestModeForceOn)) {
        SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_On;
        *rty_MeAP_b_FPAStatus = true;
        SWC_APA_B.MeAP_TransitionDebugVar = 10U;
      }
      break;

     default:
      /* Chart: '<S5>/APA_StateMachine' */
      /* case IN_On: */
      *rty_MeAP_b_FPAStatus = true;

      /*   */
      tmp = !*rtu_MbDiag_TestModeForceOn;
      if ((((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON)
            && (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Semi) &&
            (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Full)) ||
           ((!(*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_Drive)) &&
            (!(*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
               TeAP_e_FiltdGearState_ReverseGear))) ||
           (*rty_IeAP_e_FrntSnsrStatus != TeAP_e_FrntSnsrStatus_Active)) && tmp)
      {
        SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_Off;
        *rty_MeAP_b_FPAStatus = false;
        SWC_APA_B.MeAP_TransitionDebugVar = 8U;
      } else {
        if ((((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
               SWC_APA_B.Saturation1) &&
              (!(*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 511.875F))) ||
             (*rtu_IbFID_PA_MeAP_b_FPADisable)) && tmp) {
          SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_FPA_Degradded;
          SWC_APA_B.MeAP_TransitionDebugVar = 13U;
          SWC_APA_DW.is_FPA_Degradded = SWC_APA_IN_SpeedExceed;
          *rty_MeAP_b_FPAStatus = false;
        }
      }
      break;
    }

    switch (SWC_APA_DW.is_RPA_ACTIVE) {
     case SWC_APA_IN_Off_e:
      /* Chart: '<S5>/APA_StateMachine' */
      *rty_MeAP_b_RPAStatus = false;

      /*  Enabling Conditions or ECU Test Mode */
      if ((((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON)
            || (*rty_MeAP_e_PAMOffStatus2BT ==
                TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON) || (*rtu_IeAP_e_ParKMnvrActv
             == TeAP_e_ParKMnvrActv_Engaged_Semi) || (*rtu_IeAP_e_ParKMnvrActv ==
             TeAP_e_ParKMnvrActv_Engaged_Full)) &&
           (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
            TeAP_e_FiltdGearState_ReverseGear) &&
           (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
            SWC_APA_B.Saturation2) && (*rty_IeAP_e_RearSnsrStatus ==
            TeAP_e_RearSnsrStatus_Active) && (*rtu_MeTHA_e_RearBrkSupprInfo !=
            TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking) &&
           (!*rtu_IbFID_PA_MeAP_b_RPADisable)) || (*rtu_MbDiag_TestModeForceOn))
      {
        SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_On_f;
        *rty_MeAP_b_RPAStatus = true;
        SWC_APA_B.MeAP_TransitionDebugVar = 18U;
      }
      break;

     case SWC_APA_IN_On_f:
      /* Chart: '<S5>/APA_StateMachine' */
      *rty_MeAP_b_RPAStatus = true;
      tmp = !*rtu_MbDiag_TestModeForceOn;
      if ((((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF)
            && (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Semi) &&
            (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Full)) || (*
            rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear !=
            TeAP_e_FiltdGearState_ReverseGear) || (*rty_IeAP_e_RearSnsrStatus !=
            TeAP_e_RearSnsrStatus_Active) || (*rtu_MeTHA_e_RearBrkSupprInfo ==
            TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking)) && tmp) {
        SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_Off_e;
        *rty_MeAP_b_RPAStatus = false;
        SWC_APA_B.MeAP_TransitionDebugVar = 16U;
      } else {
        if ((((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
               SWC_APA_B.Saturation2) &&
              (!(*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 511.875F))) ||
             (*rtu_IbFID_PA_MeAP_b_RPADisable)) && tmp) {
          SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_RPA_Degradded;
          SWC_APA_B.MeAP_TransitionDebugVar = 21U;
          SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_SpeedExceed;
          *rty_MeAP_b_RPAStatus = false;
        }
      }
      break;

     default:
      /* Chart: '<S5>/APA_StateMachine' */
      /* case IN_RPA_Degradded: */
      if (((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF) &&
           (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Semi) &&
           (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Full)) ||
          (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear !=
           TeAP_e_FiltdGearState_ReverseGear) || (*rty_IeAP_e_RearSnsrStatus !=
           TeAP_e_RearSnsrStatus_Active) || (*rtu_MeTHA_e_RearBrkSupprInfo ==
           TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking)) {
        SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
        SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_Off_e;
        *rty_MeAP_b_RPAStatus = false;
        SWC_APA_B.MeAP_TransitionDebugVar = 16U;
      } else if (SWC_APA_DW.is_RPA_Degradded == SWC_APA_IN_DisableRPA) {
        *rty_MeAP_b_RPAStatus = false;
        tmp = !*rtu_IbFID_PA_MeAP_b_RPADisable;
        if ((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig >
             SWC_APA_B.Saturation2) &&
            (!(*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > 511.875F)) &&
            tmp) {
          SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_SpeedExceed;
          *rty_MeAP_b_RPAStatus = false;
        } else {
          if (tmp || (*rtu_MbDiag_TestModeForceOn)) {
            SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
            SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_On_f;
            *rty_MeAP_b_RPAStatus = true;
            SWC_APA_B.MeAP_TransitionDebugVar = 18U;
          }
        }
      } else {
        /* case IN_SpeedExceed: */
        *rty_MeAP_b_RPAStatus = false;

        /* ((IeVBII_kph_VehSpeedVSOSig < (KeAP_kph_RearWarnMaxSpdThd-KeAP_kph_EnblHysThd) &&RPA_SpeedExceed) || !RPA_SpeedExceed) &&... */
        if (*rtu_IbFID_PA_MeAP_b_RPADisable) {
          SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_DisableRPA;
          *rty_MeAP_b_RPAStatus = false;
        } else {
          if ((*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
               SWC_APA_B.Saturation2 - SWC_APA_B.Saturation) ||
              (*rtu_MbDiag_TestModeForceOn)) {
            SWC_APA_DW.is_RPA_Degradded = SWC_APA_IN_NO_ACTIVE_CHILD_im;
            SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_On_f;
            *rty_MeAP_b_RPAStatus = true;
            SWC_APA_B.MeAP_TransitionDebugVar = 18U;
          }
        }
      }
      break;
    }
  }

  /* End of Constant: '<S11>/Constant' */
}

/* Function for Chart: '<S5>/APA_StateMachine' */
static void SWC_APA_inner_default_PA_FAULT(const boolean_T
  *rtu_IbFID_PA_MeAP_b_ExternalFail, const boolean_T
  *rtu_IbFID_PA_MeAP_b_SystemFail, const boolean_T *rtu_MbDiag_PlantModeOn,
  TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus, TeAP_e_PAMSystemFault
  *rty_IeAP_e_PAMSystemFault)
{
  /* Chart: '<S5>/APA_StateMachine' */
  *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Sensor_Fault;
  if (*rtu_MbDiag_PlantModeOn) {
    *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_TemporaryFailure;
    SWC_APA_B.MeAP_TransitionDebugVar = 38U;
  } else if (*rtu_IbFID_PA_MeAP_b_ExternalFail) {
    *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_ExternalFailure;
    SWC_APA_B.MeAP_TransitionDebugVar = 37U;
  } else if (*rtu_IbFID_PA_MeAP_b_SystemFail) {
    *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_SystemFailure;
    SWC_APA_B.MeAP_TransitionDebugVar = 36U;
  } else {
    *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_False;
  }

  /* End of Chart: '<S5>/APA_StateMachine' */
}

/* System initialize for referenced model: 'SWC_APA' */
void SWC_APA_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S7>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_e = true;

  /* SystemInitialize for Atomic SubSystem: '<S4>/APA_EnablingCondition' */
  /* InitializeConditions for Delay: '<S16>/Delay1' */
  SWC_APA_DW.icLoad_e = 1U;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_bh = true;

  /* InitializeConditions for Delay: '<S17>/Delay1' */
  SWC_APA_DW.icLoad_h = 1U;

  /* InitializeConditions for UnitDelay: '<S27>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_jj = true;

  /* End of SystemInitialize for SubSystem: '<S4>/APA_EnablingCondition' */

  /* SystemInitialize for Enabled SubSystem: '<S7>/SavePreviousFrntStatus' */
  /* InitializeConditions for UnitDelay: '<S685>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_m = TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON;

  /* SystemInitialize for Outport: '<S685>/MeAP_e_FeatStsBeforeTrlr' */
  SWC_APA_B.MeAP_e_FeatStsBeforeTrlr_h = TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON;

  /* End of SystemInitialize for SubSystem: '<S7>/SavePreviousFrntStatus' */

  /* SystemInitialize for Atomic SubSystem: '<S2>/Rear_Front_ParkAssist' */
  /* InitializeConditions for UnitDelay: '<S58>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_k = true;

  /* InitializeConditions for UnitDelay: '<S58>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE = TeVBII_e_CmdIgnSts_SNA;

  /* InitializeConditions for UnitDelay: '<S58>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_l = true;

  /* SystemInitialize for Atomic SubSystem: '<S6>/FPA' */
  SWC_APA_FPA_Init();

  /* End of SystemInitialize for SubSystem: '<S6>/FPA' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/RPA' */
  SWC_APA_RPA_Init();

  /* End of SystemInitialize for SubSystem: '<S6>/RPA' */

  /* SystemInitialize for Enabled SubSystem: '<S58>/SavePreviousFrntStatus' */
  /* SystemInitialize for Outport: '<S676>/MeAP_b_PrevIgnCyclFrntSts' */
  SWC_APA_B.MeAP_b_PrevIgnCyclFrntSts = true;

  /* End of SystemInitialize for SubSystem: '<S58>/SavePreviousFrntStatus' */

  /* SystemInitialize for Enabled SubSystem: '<S58>/SavePreviousRearStatus' */
  /* SystemInitialize for Outport: '<S677>/MeAP_b_PrevIgnCyclRearSts' */
  SWC_APA_B.MeAP_b_PrevIgnCyclRearSts = true;

  /* End of SystemInitialize for SubSystem: '<S58>/SavePreviousRearStatus' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/PAMPopUpReq_Gen' */
  /* InitializeConditions for UnitDelay: '<S244>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_kd = TeAP_e_PAMPopUpReq_SNA;

  /* End of SystemInitialize for SubSystem: '<S6>/PAMPopUpReq_Gen' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/RPAwithBrk' */
  SWC_APA_RPAwithBrk_Init();

  /* End of SystemInitialize for SubSystem: '<S6>/RPAwithBrk' */
  /* End of SystemInitialize for SubSystem: '<S2>/Rear_Front_ParkAssist' */
}

/* Disable for referenced model: 'SWC_APA' */
void SWC_APA_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S2>/Rear_Front_ParkAssist' */
  /* Disable for Atomic SubSystem: '<S6>/FPA' */
  SWC_APA_FPA_Disable();

  /* End of Disable for SubSystem: '<S6>/FPA' */

  /* Disable for Atomic SubSystem: '<S6>/RPA' */
  SWC_APA_RPA_Disable();

  /* End of Disable for SubSystem: '<S6>/RPA' */

  /* Disable for Atomic SubSystem: '<S6>/RPAwithBrk' */
  SWC_APA_RPAwithBrk_Disable();

  /* End of Disable for SubSystem: '<S6>/RPAwithBrk' */
  /* End of Disable for SubSystem: '<S2>/Rear_Front_ParkAssist' */
}

/* Output and update for referenced model: 'SWC_APA' */
void SWC_APA(const TeVBII_e_CmdIgnSts *rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts,
             const boolean_T *rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq,
             const boolean_T *rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq, const
             boolean_T *rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts, const
             boolean_T *rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached, const
             TeVBII_e_TrailerConnectionSts
             *rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts, const
             TeVBII_e_TrlrPrsntSts *rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts,
             const real32_T *rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp, const
             TeVBII_e_BrkStat *rtu_IbVBIA_VehState_IeVBII_e_BrkStat, const
             TeVBII_e_VehEPBSts *rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts, const
             TeVBII_e_TCaseRangeSts *rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts,
             const TeVBII_e_EssEngState
             *rtu_IbVBIA_VehState_IeVBII_e_EssEngState, const
             TeVBII_e_PamChimeVol *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt,
             const TeVBII_e_PamChimeVol
             *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst, const
             TeAP_e_FiltdGearState *rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear,
             const TeVBII_e_TransSailingTst
             *rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate, const uint8_T
             *rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr, const
             TeVBII_e_WhlSpnSts *rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts,
             const real32_T *rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd, const
             uint8_T *rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd, const uint8_T
             *rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr, const
             TeVBII_e_WhlSpnSts *rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts,
             const real32_T *rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd, const
             uint8_T *rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts, const
             TeVBII_e_ShiftLvrPosReq
             *rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt, const
             TeVBII_e_TurnIndicSts *rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts,
             const boolean_T *rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts, const
             boolean_T *rtu_IbVBIA_VehState_IeVBII_b_DoorRL, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_DoorP, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_DoorRR, const TeVBII_e_EngineSts
             *rtu_IbVBIA_VehState_IeVBII_e_EngineSts, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode, const
             TeVBII_e_LanguageSeln *rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln,
             const TeVBII_e_TGWCamDispSts
             *rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts, const
             TeVBII_e_TchScrSts *rtu_IbVBIA_VehState_IeVBII_e_TchScrSts, const
             uint16_T *rtu_IbVBIA_VehState_IeVBII_e_TchXCoord, const uint16_T
             *rtu_IbVBIA_VehState_IeVBII_e_TchYCoord, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept, const
             TeAP_e_FiltdGearState *rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState,
             const TeVBII_e_ACCSysSts *rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts,
             const uint32_T *rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct, const
             TeVBII_e_ParkingIntrvntionSts
             *rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog, const
             TeVBII_e_SPMLatCtrlRespSts
             *rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts, const real32_T
             *rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts, const
             TeVBII_e_PAMBrkReqRespStatus
             *rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus, const
             TeVBII_e_ShiftLvrPos *rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos,
             const uint32_T *rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver, const
             TeVBII_e_ExtBrkReqDisabled
             *rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled, const
             TeVBII_e_ParkingGearShiftReq
             *rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq, const int16_T
             *rtu_IbVBIA_VehState_IeVBII_pct_Slope, const
             TeVBII_e_DriverReqAxleTrqEnabled
             *rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled, const
             TeVBII_e_BrkPdlStat *rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat, const
             boolean_T *rtu_IbVBIA_VehState_IeVBII_b_Override, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed, const boolean_T
             *rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt, const uint16_T
             *rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz, const
             TeAP_e_SteerRatRackPinionTyp
             *rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp, const
             TeAP_e_DrvTypVrnt *rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt, const
             TeAP_e_GbTyp *rtu_MbNVM_ProxyParam_KeAP_e_GbTyp, const
             TeAP_e_PAMTunSet *rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet, const
             uint8_T *rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg, const
             TeAP_e_CtryCod *rtu_MbNVM_ProxyParam_KeAP_e_CtryCod, const
             TeAP_e_HybTyp *rtu_MbNVM_ProxyParam_KeAP_e_HybTyp, const
             TeAP_e_WhlBas *rtu_MbNVM_ProxyParam_KeAP_e_WhlBas, const boolean_T *
             rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg, const TeAP_e_RadioDispTyp
             *rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_DrvSide, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys, const uint16_T
             *rtu_MbNVM_ProxyParam_KeAP_e_MdlYr, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres, const boolean_T
             *rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent, const uint8_T
             *rtu_MbNVM_ProxyParam_KeAP_k_VariantID, const boolean_T
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
             *rtu_IbFID_PARB_MeAP_b_PARBDiable, const TbNVM_ReadParam
             *rtu_MbNVM_ReadParam, const real32_T
             *rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd, const
             real32_T *rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd, const
             real32_T *rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd,
             const real32_T
             *rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd, const
             real32_T *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const
             uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert,
             const uint16_T
             *rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd, const
             uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd,
             const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd,
             const uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const
             uint16_T *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd,
             const int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6, const
             int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const
             boolean_T *rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn, const boolean_T
             *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk, const boolean_T
             *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView, const
             US_S_PointMapOutputBuff_t *rtu_USS_2DPointMap, const
             TeAP_e_SPMLatCtrlReqSts *rtu_IeAP_e_SPMLatCtrlReqSts, const
             TeAP_e_ParKMnvrActv *rtu_IeAP_e_ParKMnvrActv, const
             TeTRSC_e_TRSCSts *rtu_IeTRSC_e_TRSCSts, const
             TeTHA_e_RearBrkSupprInfo *rtu_MeTHA_e_RearBrkSupprInfo, const
             boolean_T *rtu_MbDiag_TestModeForceOn, const int16_T
             *rtu_MeAP_cm_FrntCenterMinXDist, const int16_T
             *rtu_MeAP_cm_FrntLeftMinXDist, const int16_T
             *rtu_MeAP_cm_FrntRightMinXDist, const int16_T
             *rtu_MeAP_cm_RearCenterMinXDist, const int16_T
             *rtu_MeAP_cm_RearLeftMinXDist, const int16_T
             *rtu_MeAP_cm_RearRightMinXDist, const boolean_T
             *rtu_MbDiag_PlantModeOn, const TeTRSC_e_TRSCPopupDispInfo
             *rtu_IeTRSC_e_TRSCPopupDispInfo, const uint8_T
             *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront,
             const uint8_T
             *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL,
             const uint8_T
             *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR,
             const uint8_T
             *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear,
             const uint8_T
             *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL, const
             uint8_T
             *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR, const
             uint8_T *rtu_MeAP_b_IsWall, const int16_T
             *rtu_MeAP_cm_WallFrntCenterDist, const int16_T
             *rtu_MeAP_cm_WallRearCenterDist, TeAP_e_Alert *rty_MeAP_e_AlertCHF,
             TeAP_e_Alert *rty_MeAP_e_AlertLHF, TeAP_e_Alert
             *rty_MeAP_e_AlertRHF, TeAP_e_Alert *rty_MeAP_e_AlertCHR,
             TeAP_e_Alert *rty_MeAP_e_AlertLHR, TeAP_e_Alert
             *rty_MeAP_e_AlertRHR, TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHF,
             TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicLHF,
             TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHF,
             TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHR,
             TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicLHR,
             TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHR, boolean_T
             *rty_MeAP_b_ChimeActvLHF, boolean_T *rty_MeAP_b_ChimeActvRHF,
             boolean_T *rty_MeAP_b_ChimeActvLHR, boolean_T
             *rty_MeAP_b_ChimeActvRHR, TeAP_e_PAMChimeRepnRate
             *rty_MeAP_e_PAMChimeRepnRate, TeAP_e_PAMVolume
             *rty_MeAP_e_PAMVolume, TeAP_e_PAMLedCtrlStatus
             *rty_MeAP_e_FrntPAMLedCtrlStatus, TeAP_e_PAMLedCtrlStatus
             *rty_MeAP_e_RearPAMLedCtrlStatus, TeAP_e_PAMChimeTyp
             *rty_MeAP_e_PAMChimeTyp, TeAP_e_PAMPopUpReq *rty_MeAP_e_PAMPopUpReq,
             boolean_T *rty_MeAP_b_PAMBrkReqStatus, real32_T
             *rty_MeAP_cm_RearDist, boolean_T *rty_MeAP_b_PAMStopCtrlStatus,
             TeAP_e_ParkAssistStatus *rty_MeAP_e_ParkAssistStatus, boolean_T
             *rty_MeAP_b_FPAStatus, boolean_T *rty_MeAP_b_RPAStatus,
             TeAP_e_PAMSystemFault *rty_IeAP_e_PAMSystemFault,
             TeAP_e_PAMOffStatus2BT *rty_MeAP_e_PAMOffStatus2BT, boolean_T
             *rty_MeAP_b_SystemFail, boolean_T *rty_MeAP_b_ExternalFail,
             boolean_T *rty_MeAP_b_RPAwithBrkDisable, boolean_T
             *rty_MeAP_b_RPADisable, boolean_T *rty_MeAP_b_FPADisable,
             TeAutoPark_e_ScanDir *rty_IeAutoPark_e_ScanDir,
             TeAP_e_FrntSnsrStatus *rty_IeAP_e_FrntSnsrStatus,
             TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus)
{
  real_T tmp;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts =
    rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq =
    rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq =
    rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts =
    rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached =
    rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts =
    rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts =
    rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp =
    rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkStat =
    rtu_IbVBIA_VehState_IeVBII_e_BrkStat;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts =
    rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts =
    rtu_IbVBIA_VehState_IeVBII_e_TCaseRangeSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EssEngState =
    rtu_IbVBIA_VehState_IeVBII_e_EssEngState;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt =
    rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear =
    rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst =
    rtu_IbVBIA_VehState_IeVBII_b_RearBrkAsst;
  SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear =
    rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst =
    rtu_IbVBIA_VehState_IeVBII_e_TransSailingTst;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc =
    rtu_IbVBIA_VehState_IeVBII_a_VehLatAcc;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc =
    rtu_IbVBIA_VehState_IeVBII_a_VehLongAcc;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig =
    rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate =
    rtu_IbVBIA_VehState_IeVBII_ddeg_VehYawRate;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr =
    rtu_IbVBIA_VehState_IeVBII_cnt_LhfPulseCtr;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts =
    rtu_IbVBIA_VehState_IeVBII_e_LhfWhlSpnSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd =
    rtu_IbVBIA_VehState_IeVBII_kph_LhfWhlSpd;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr =
    rtu_IbVBIA_VehState_IeVBII_cnt_LhrPulseCtr;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd =
    rtu_IbVBIA_VehState_IeVBII_kph_LhrWhlSpd;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr =
    rtu_IbVBIA_VehState_IeVBII_cnt_RhfPulseCtr;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts =
    rtu_IbVBIA_VehState_IeVBII_e_RhfWhlSpnSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd =
    rtu_IbVBIA_VehState_IeVBII_kph_RhfWhlSpd;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr =
    rtu_IbVBIA_VehState_IeVBII_cnt_RhrPulseCtr;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd =
    rtu_IbVBIA_VehState_IeVBII_kph_RhrWhlSpd;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng =
    rtu_IbVBIA_VehState_IeVBII_deg_StrWhlAng;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd =
    rtu_IbVBIA_VehState_IeVBII_deg_StrWhlSpd;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts =
    rtu_IbVBIA_VehState_IeVBII_b_ShifterAutoconnectSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq =
    rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPosReq;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt =
    rtu_IbVBIA_VehState_IeVBII_b_AutoParkEnblSwt;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts =
    rtu_IbVBIA_VehState_IeVBII_e_TurnIndicSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts =
    rtu_IbVBIA_VehState_IeVBII_b_DriverDoorSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRL =
    rtu_IbVBIA_VehState_IeVBII_b_DoorRL;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorP =
    rtu_IbVBIA_VehState_IeVBII_b_DoorP;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus =
    rtu_IbVBIA_VehState_IeVBII_b_TrnkStatus;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_DoorRR =
    rtu_IbVBIA_VehState_IeVBII_b_DoorRR;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_EngineSts =
    rtu_IbVBIA_VehState_IeVBII_e_EngineSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct =
    rtu_IbVBIA_VehState_IeVBII_per_PdlPosAct;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode =
    rtu_IbVBIA_VehState_IeVBII_b_ActvParkMode;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln =
    rtu_IbVBIA_VehState_IeVBII_e_LanguageSeln;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts =
    rtu_IbVBIA_VehState_IeVBII_e_TGWCamDispSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchScrSts =
    rtu_IbVBIA_VehState_IeVBII_e_TchScrSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchXCoord =
    rtu_IbVBIA_VehState_IeVBII_e_TchXCoord;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_TchYCoord =
    rtu_IbVBIA_VehState_IeVBII_e_TchYCoord;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept =
    rtu_IbVBIA_VehState_IeVBII_b_GearShiftReqAccept;
  SWC_APA_rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState =
    rtu_IbVBIA_VehState_MeAP_e_FiltdGearRptState;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts =
    rtu_IbVBIA_VehState_IeVBII_e_ACCSysSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct =
    rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqAct;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts =
    rtu_IbVBIA_VehState_IeVBII_e_ParkingIntrvntionSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog =
    rtu_IbVBIA_VehState_IeVBII_b_HandsOnRecog;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts =
    rtu_IbVBIA_VehState_IeVBII_e_SPMLatCtrlRespSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq =
    rtu_IbVBIA_VehState_IeVBII_M_StrWhlTrq;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_VehLatAccFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_VehLongAccFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_VehYawRateFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_LHFWhlSnsrFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_LHRWhlSnsrFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_RHFWhlSnsrFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts =
    rtu_IbVBIA_VehState_IeVBII_b_RHRWhlSnsrFailSts;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus =
    rtu_IbVBIA_VehState_IeVBII_e_PAMBrkReqRespStatus;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos =
    rtu_IbVBIA_VehState_IeVBII_e_ShiftLvrPos;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver =
    rtu_IbVBIA_VehState_IeVBII_nm_BrkTrqDriver;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled =
    rtu_IbVBIA_VehState_IeVBII_e_ExtBrkReqDisabled;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq =
    rtu_IbVBIA_VehState_IeVBII_e_ParkingGearShiftReq;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_pct_Slope =
    rtu_IbVBIA_VehState_IeVBII_pct_Slope;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled =
    rtu_IbVBIA_VehState_IeVBII_e_DriverReqAxleTrqEnabled;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat =
    rtu_IbVBIA_VehState_IeVBII_e_BrkPdlStat;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_Override =
    rtu_IbVBIA_VehState_IeVBII_b_Override;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed =
    rtu_IbVBIA_VehState_IeVBII_b_TrqEnblReqAllowed;
  SWC_APA_rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime =
    rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM =
    rtu_MbNVM_ProxyParam_KeAP_b_CanNode67DTCM;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM =
    rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt =
    rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz =
    rtu_MbNVM_ProxyParam_KeAP_mm_TyreSz;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp =
    rtu_MbNVM_ProxyParam_KeAP_e_SteerRatRackPinionTyp;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt =
    rtu_MbNVM_ProxyParam_KeAP_e_DrvTypVrnt;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_GbTyp = rtu_MbNVM_ProxyParam_KeAP_e_GbTyp;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet =
    rtu_MbNVM_ProxyParam_KeAP_e_PAMTunSet;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg =
    rtu_MbNVM_ProxyParam_KeAP_e_VehLineCfg;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_CtryCod =
    rtu_MbNVM_ProxyParam_KeAP_e_CtryCod;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_HybTyp =
    rtu_MbNVM_ProxyParam_KeAP_e_HybTyp;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_WhlBas =
    rtu_MbNVM_ProxyParam_KeAP_e_WhlBas;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop =
    rtu_MbNVM_ProxyParam_KeAP_b_ParkWithStop;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg =
    rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp =
    rtu_MbNVM_ProxyParam_KeAP_e_RadioDispTyp;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM =
    rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_DrvSide =
    rtu_MbNVM_ProxyParam_KeAP_b_DrvSide;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys =
    rtu_MbNVM_ProxyParam_KeAP_b_SemiAutoPrkgSys;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_e_MdlYr = rtu_MbNVM_ProxyParam_KeAP_e_MdlYr;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres =
    rtu_MbNVM_ProxyParam_KeAP_b_PullOutCtrlPres;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys =
    rtu_MbNVM_ProxyParam_KeAP_b_FullAutoPrkgSys;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres =
    rtu_MbNVM_ProxyParam_KeAP_b_TrlrHitchAsstPres;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres =
    rtu_MbNVM_ProxyParam_KeAP_b_TrlrRvsSteerPres;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent =
    rtu_MbNVM_ProxyParam_KeAP_b_SVSPresent;
  SWC_APA_rtu_MbNVM_ProxyParam_KeAP_k_VariantID =
    rtu_MbNVM_ProxyParam_KeAP_k_VariantID;
  SWC_APA_rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27 =
    rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27;
  SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBActv4LOW =
    rtu_IbFID_PARB_MeAP_b_PARBActv4LOW;
  SWC_APA_rtu_IbFID_PARB_MeAP_b_PARBDiable = rtu_IbFID_PARB_MeAP_b_PARBDiable;
  SWC_APA_rtu_MbNVM_ReadParam = rtu_MbNVM_ReadParam;
  SWC_APA_rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth =
    rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert =
    rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd =
    rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd =
    rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep =
    rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6 =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6;
  SWC_APA_rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj =
    rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj;
  SWC_APA_rtu_USS_2DPointMap = rtu_USS_2DPointMap;
  SWC_APA_rtu_IeAP_e_ParKMnvrActv = rtu_IeAP_e_ParKMnvrActv;
  SWC_APA_rtu_MeTHA_e_RearBrkSupprInfo = rtu_MeTHA_e_RearBrkSupprInfo;
  SWC_APA_rtu_MeAP_cm_FrntCenterMinXDist = rtu_MeAP_cm_FrntCenterMinXDist;
  SWC_APA_rtu_MeAP_cm_FrntLeftMinXDist = rtu_MeAP_cm_FrntLeftMinXDist;
  SWC_APA_rtu_MeAP_cm_FrntRightMinXDist = rtu_MeAP_cm_FrntRightMinXDist;
  SWC_APA_rtu_MeAP_cm_RearCenterMinXDist = rtu_MeAP_cm_RearCenterMinXDist;
  SWC_APA_rtu_MeAP_cm_RearLeftMinXDist = rtu_MeAP_cm_RearLeftMinXDist;
  SWC_APA_rtu_MeAP_cm_RearRightMinXDist = rtu_MeAP_cm_RearRightMinXDist;
  SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront =
    rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront;
  SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL =
    rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL;
  SWC_APA_rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR =
    rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR;
  SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear =
    rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear;
  SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL =
    rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL;
  SWC_APA_rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR =
    rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR;
  SWC_APA_rtu_MeAP_b_IsWall = rtu_MeAP_b_IsWall;
  SWC_APA_rtu_MeAP_cm_WallFrntCenterDist = rtu_MeAP_cm_WallFrntCenterDist;
  SWC_APA_rtu_MeAP_cm_WallRearCenterDist = rtu_MeAP_cm_WallRearCenterDist;
  SWC_APA_rty_MeAP_e_AlertCHF = rty_MeAP_e_AlertCHF;
  SWC_APA_rty_MeAP_e_AlertLHF = rty_MeAP_e_AlertLHF;
  SWC_APA_rty_MeAP_e_AlertRHF = rty_MeAP_e_AlertRHF;
  SWC_APA_rty_MeAP_e_AlertCHR = rty_MeAP_e_AlertCHR;
  SWC_APA_rty_MeAP_e_AlertLHR = rty_MeAP_e_AlertLHR;
  SWC_APA_rty_MeAP_e_AlertRHR = rty_MeAP_e_AlertRHR;
  SWC_APA_rty_MeAP_e_GraphicCHF = rty_MeAP_e_GraphicCHF;
  SWC_APA_rty_MeAP_e_GraphicLHF = rty_MeAP_e_GraphicLHF;
  SWC_APA_rty_MeAP_e_GraphicRHF = rty_MeAP_e_GraphicRHF;
  SWC_APA_rty_MeAP_e_GraphicCHR = rty_MeAP_e_GraphicCHR;
  SWC_APA_rty_MeAP_e_GraphicLHR = rty_MeAP_e_GraphicLHR;
  SWC_APA_rty_MeAP_e_GraphicRHR = rty_MeAP_e_GraphicRHR;
  SWC_APA_rty_MeAP_e_FrntPAMLedCtrlStatus = rty_MeAP_e_FrntPAMLedCtrlStatus;
  SWC_APA_rty_MeAP_e_RearPAMLedCtrlStatus = rty_MeAP_e_RearPAMLedCtrlStatus;
  SWC_APA_rty_MeAP_b_PAMBrkReqStatus = rty_MeAP_b_PAMBrkReqStatus;
  SWC_APA_rty_MeAP_cm_RearDist = rty_MeAP_cm_RearDist;
  SWC_APA_rty_MeAP_b_PAMStopCtrlStatus = rty_MeAP_b_PAMStopCtrlStatus;
  SWC_APA_rty_MeAP_b_FPAStatus = rty_MeAP_b_FPAStatus;
  SWC_APA_rty_MeAP_b_RPAStatus = rty_MeAP_b_RPAStatus;
  SWC_APA_rty_IeAP_e_PAMSystemFault = rty_IeAP_e_PAMSystemFault;
  SWC_APA_rty_MeAP_e_PAMOffStatus2BT = rty_MeAP_e_PAMOffStatus2BT;
  SWC_APA_rty_IeAP_e_FrntSnsrStatus = rty_IeAP_e_FrntSnsrStatus;
  SWC_APA_rty_IeAP_e_RearSnsrStatus = rty_IeAP_e_RearSnsrStatus;

  /* SignalConversion generated from: '<Root>/MeAP_b_ExternalFail' */
  *rty_MeAP_b_ExternalFail = *rtu_IbFID_PA_MeAP_b_ExternalFail;

  /* Outputs for Atomic SubSystem: '<S4>/APA_EnablingCondition' */
  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  DataTypeConversion: '<S12>/Data Type Conversion'
   *  Logic: '<S12>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator1_mc = *rtu_MbDiag_PlantModeOn;
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S12>/Logical Operator1'
   */
  SWC_APA_B.LogicalOperator2_n = !*rtu_IbVBIA_VehState_IeVBII_b_SnowPlowAttached;

  /* Logic: '<S12>/Logical Operator5' */
  MeAP_b_FrontParkAssistEnbl = ((*rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn) &&
    SWC_APA_B.LogicalOperator2_n && (*rtu_MbNVM_ProxyParam_KeAP_b_PAMCfg) &&
    SWC_APA_B.RelationalOperator1_mc);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S20>/Constant'
   *  RelationalOperator: '<S16>/Relational Operator'
   */
  SWC_APA_B.RelationalOperator1_mc =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S19>/Constant'
   *  RelationalOperator: '<S16>/Relational Operator1'
   */
  SWC_APA_B.LogicalOperator2_n = (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* Logic: '<S16>/Logical Operator2' */
  SWC_APA_B.LogicalOperator2_e = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* Delay: '<S16>/Delay1' */
  if (SWC_APA_DW.icLoad_e != 0) {
    SWC_APA_DW.Delay1_DSTATE = SWC_APA_B.LogicalOperator2_e;
  }

  SWC_APA_B.Delay1 = SWC_APA_DW.Delay1_DSTATE;

  /* End of Delay: '<S16>/Delay1' */

  /* Logic: '<S21>/Logical Operator2' incorporates:
   *  Logic: '<S22>/Logical Operator'
   */
  SWC_APA_B.reset = !*rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S21>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_B.reset;

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  UnitDelay: '<S21>/Unit Delay'
   */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay_DSTATE_pa;

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S21>/Logical Operator3'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  UnitDelay: '<S22>/Unit Delay'
   */
  SWC_APA_B.LogicalOperator2_n = SWC_APA_DW.UnitDelay_DSTATE_bh;

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S16>/Logical Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* RelationalOperator: '<S16>/Relational Operator2' incorporates:
   *  Constant: '<S18>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S16>/Logical Operator3' incorporates:
   *  Constant: '<S16>/Constant2'
   */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    KeAP_b_SwitchOldAlgo);

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = *rtu_MbDiag_PlantModeOn;

  /* Logic: '<S16>/Logical Operator5' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = !SWC_APA_B.MeAP_b_FrontSwitchPressed;

  /* Logic: '<S16>/Logical Operator6' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator1_mc && SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* Switch: '<S16>/Switch1' */
  if (SWC_APA_B.RelationalOperator4_m) {
    /* Logic: '<S16>/Logical Operator7' */
    SWC_APA_B.LogicalOperator7_g = !SWC_APA_B.Delay1;
    SWC_APA_B.MeAP_b_FPAEnablingCond = SWC_APA_B.LogicalOperator7_g;
  } else {
    SWC_APA_B.MeAP_b_FPAEnablingCond = SWC_APA_B.Delay1;
  }

  /* End of Switch: '<S16>/Switch1' */

  /* RelationalOperator: '<S14>/Relational Operator' incorporates:
   *  Constant: '<S28>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S14>/Logical Operator' */
  MeAP_b_FrntParkAssistStatus = (SWC_APA_B.MeAP_b_FPAEnablingCond &&
    MeAP_b_FrontParkAssistEnbl && SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S17>/Relational Operator' incorporates:
   *  Constant: '<S25>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* RelationalOperator: '<S17>/Relational Operator1' incorporates:
   *  Constant: '<S24>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
     TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* Logic: '<S17>/Logical Operator2' */
  SWC_APA_B.LogicalOperator2_ex = (SWC_APA_B.MeAP_b_FrontSwitchPressed ||
    SWC_APA_B.RelationalOperator8_er);

  /* Delay: '<S17>/Delay1' */
  if (SWC_APA_DW.icLoad_h != 0) {
    SWC_APA_DW.Delay1_DSTATE_d = SWC_APA_B.LogicalOperator2_ex;
  }

  SWC_APA_B.Delay1_h = SWC_APA_DW.Delay1_DSTATE_d;

  /* End of Delay: '<S17>/Delay1' */

  /* Logic: '<S26>/Logical Operator2' incorporates:
   *  Logic: '<S27>/Logical Operator'
   */
  SWC_APA_B.reset_h = !*rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;
  SWC_APA_B.MeAP_b_FrontSwitchPressed = SWC_APA_B.reset_h;

  /* UnitDelay: '<S26>/Unit Delay' */
  SWC_APA_B.RelationalOperator8_er = SWC_APA_DW.UnitDelay_DSTATE_em;

  /* Logic: '<S26>/Logical Operator3' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (SWC_APA_B.MeAP_b_FrontSwitchPressed &&
    SWC_APA_B.RelationalOperator8_er);

  /* UnitDelay: '<S27>/Unit Delay' */
  SWC_APA_B.RelationalOperator8_er = SWC_APA_DW.UnitDelay_DSTATE_jj;

  /* Logic: '<S17>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (SWC_APA_B.MeAP_b_FrontSwitchPressed &&
    SWC_APA_B.RelationalOperator8_er);

  /* RelationalOperator: '<S17>/Relational Operator2' incorporates:
   *  Constant: '<S23>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S17>/Logical Operator6' incorporates:
   *  Constant: '<S17>/Constant2'
   */
  SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.RelationalOperator6_p ||
    KeAP_b_SwitchOldAlgo);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  Logic: '<S15>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator1_e1 =
    ((*rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk) ||
     (*rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView));

  /* Logic: '<S15>/Logical Operator15' */
  SWC_APA_B.RelationalOperator2_j = !*rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM;

  /* RelationalOperator: '<S15>/Relational Operator8' incorporates:
   *  Constant: '<S35>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts !=
    TeVBII_e_TrailerConnectionSts_Connected);

  /* Logic: '<S15>/Logical Operator14' */
  SWC_APA_B.RelationalOperator7 = ((*rtu_MbNVM_ProxyParam_KeAP_b_CanNode63TTM) &&
    SWC_APA_B.Compare_k);

  /* Logic: '<S15>/Logical Operator13' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.RelationalOperator7);

  /* RelationalOperator: '<S15>/Relational Operator4' incorporates:
   *  Constant: '<S37>/Constant'
   */
  SWC_APA_B.RelationalOperator7 =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* Logic: '<S15>/Logical Operator7' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator7 &&
    (*rtu_IbFID_PA_MeAP_b_RPAActvTrlr_27));

  /* Logic: '<S15>/Logical Operator6' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.RelationalOperator7);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S15>/Logical Operator12'
   */
  SWC_APA_B.RelationalOperator8_e =
    !*rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM;

  /* Logic: '<S15>/Logical Operator11' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.Compare_k);

  /* RelationalOperator: '<S15>/Relational Operator5' incorporates:
   *  Constant: '<S36>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts !=
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* RelationalOperator: '<S15>/Relational Operator6' incorporates:
   *  Constant: '<S38>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S15>/Logical Operator9' */
  SWC_APA_B.LogicalOperator1_d = (SWC_APA_B.LogicalOperator1_d &&
    (*rtu_IbFID_PA_MeAP_b_RPAActvTrlr_29));

  /* Logic: '<S15>/Logical Operator16' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k || SWC_APA_B.LogicalOperator1_d);

  /* Logic: '<S15>/Logical Operator10' */
  SWC_APA_B.RelationalOperator7 =
    ((*rtu_MbNVM_ProxyParam_KeAP_b_CanNode95ITBMTCM) &&
     SWC_APA_B.RelationalOperator7 && SWC_APA_B.Compare_k);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S15>/Logical Operator8'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e ||
    SWC_APA_B.RelationalOperator7);

  /* Logic: '<S15>/Logical Operator5' */
  SWC_APA_B.MeAP_b_TrlrNotConnected = (SWC_APA_B.RelationalOperator1_e1 &&
    SWC_APA_B.RelationalOperator2_j && SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S17>/Data Type Conversion'
   *  Logic: '<S17>/Logical Operator7'
   *  Logic: '<S17>/Logical Operator8'
   */
  SWC_APA_B.RelationalOperator1_e1 = *rtu_MbDiag_PlantModeOn;
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.MeAP_b_TrlrNotConnected &&
    SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S17>/Logical Operator3' */
  SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.RelationalOperator6_p &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator1_e1);

  /* Switch: '<S17>/Switch1' */
  if (SWC_APA_B.RelationalOperator6_p) {
    /* Logic: '<S17>/Logical Operator5' */
    SWC_APA_B.LogicalOperator5 = !SWC_APA_B.Delay1_h;
    SWC_APA_B.MeAP_b_RPAEnablingCond = SWC_APA_B.LogicalOperator5;
  } else {
    SWC_APA_B.MeAP_b_RPAEnablingCond = SWC_APA_B.Delay1_h;
  }

  /* End of Switch: '<S17>/Switch1' */

  /* RelationalOperator: '<S15>/Relational Operator1' incorporates:
   *  Constant: '<S33>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IeTRSC_e_TRSCSts !=
    TeTRSC_e_TRSCSts_PreActive);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  Constant: '<S34>/Constant'
   *  RelationalOperator: '<S15>/Relational Operator3'
   */
  SWC_APA_B.RelationalOperator1_e1 = (*rtu_IeTRSC_e_TRSCSts !=
    TeTRSC_e_TRSCSts_Active);

  /* Logic: '<S15>/Logical Operator3' */
  SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.RelationalOperator6_p &&
    SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  DataTypeConversion: '<S15>/Data Type Conversion'
   *  Logic: '<S15>/Logical Operator4'
   */
  SWC_APA_B.RelationalOperator1_e1 = *rtu_MbDiag_PlantModeOn;
  SWC_APA_B.RelationalOperator1_e1 = !SWC_APA_B.RelationalOperator1_e1;

  /* Logic: '<S15>/Logical Operator1' */
  MeAP_b_RearParkAssistEnbl = (SWC_APA_B.MeAP_b_TrlrNotConnected &&
    SWC_APA_B.RelationalOperator6_p && SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S14>/Logical Operator1' */
  MeAP_b_RearParkAssistStatus = (SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_RPAEnablingCond && MeAP_b_RearParkAssistEnbl);

  /* Logic: '<S14>/Logical Operator2' */
  SWC_APA_B.RelationalOperator4_m = (MeAP_b_FrntParkAssistStatus &&
    MeAP_b_RearParkAssistStatus);

  /* Logic: '<S14>/Logical Operator5' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    (*rtu_MbDiag_TestModeForceOn));

  /* Switch: '<S14>/Switch' incorporates:
   *  Constant: '<S29>/Constant'
   */
  if (SWC_APA_B.RelationalOperator4_m) {
    *rty_MeAP_e_PAMOffStatus2BT = TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON;
  } else {
    /* Logic: '<S14>/Logical Operator4' */
    SWC_APA_B.LogicalOperator3_m = !MeAP_b_RearParkAssistStatus;

    /* Logic: '<S14>/Logical Operator3' */
    SWC_APA_B.LogicalOperator3_m = (MeAP_b_FrntParkAssistStatus &&
      SWC_APA_B.LogicalOperator3_m);

    /* Switch: '<S14>/Switch1' incorporates:
     *  Constant: '<S30>/Constant'
     */
    if (SWC_APA_B.LogicalOperator3_m) {
      SWC_APA_B.Switch1_j = TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF;
    } else {
      /* Logic: '<S14>/Logical Operator7' */
      SWC_APA_B.LogicalOperator6 = !MeAP_b_FrntParkAssistStatus;

      /* Logic: '<S14>/Logical Operator6' */
      SWC_APA_B.LogicalOperator6 = (SWC_APA_B.LogicalOperator6 &&
        MeAP_b_RearParkAssistStatus);

      /* Switch: '<S14>/Switch2' incorporates:
       *  Constant: '<S31>/Constant'
       *  Constant: '<S32>/Constant'
       */
      if (SWC_APA_B.LogicalOperator6) {
        SWC_APA_B.Switch2_h = TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON;
      } else {
        SWC_APA_B.Switch2_h = TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF;
      }

      /* End of Switch: '<S14>/Switch2' */
      SWC_APA_B.Switch1_j = SWC_APA_B.Switch2_h;
    }

    /* End of Switch: '<S14>/Switch1' */
    *rty_MeAP_e_PAMOffStatus2BT = SWC_APA_B.Switch1_j;
  }

  /* End of Switch: '<S14>/Switch' */

  /* Delay: '<S17>/Delay' */
  SWC_APA_B.Delay = SWC_APA_DW.Delay_DSTATE_l;

  /* Switch: '<S17>/Switch' */
  if (SWC_APA_B.MeAP_b_FrontSwitchPressed) {
    /* Logic: '<S17>/Logical Operator4' */
    SWC_APA_B.LogicalOperator4_cj = !SWC_APA_B.Delay;
    MeAP_b_RPASwtStatus = SWC_APA_B.LogicalOperator4_cj;
  } else {
    MeAP_b_RPASwtStatus = SWC_APA_B.Delay;
  }

  /* End of Switch: '<S17>/Switch' */

  /* Logic: '<S17>/Logical Operator' */
  MeAP_b_RPASwtStuckStatus = !SWC_APA_B.RelationalOperator8_er;

  /* Delay: '<S16>/Delay' */
  SWC_APA_B.Delay_g = SWC_APA_DW.Delay_DSTATE_f;

  /* Switch: '<S16>/Switch' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    /* Logic: '<S16>/Logical Operator4' */
    SWC_APA_B.LogicalOperator4_k = !SWC_APA_B.Delay_g;
    MeAP_b_FPASwtStatus = SWC_APA_B.LogicalOperator4_k;
  } else {
    MeAP_b_FPASwtStatus = SWC_APA_B.Delay_g;
  }

  /* End of Switch: '<S16>/Switch' */

  /* Logic: '<S16>/Logical Operator' */
  MeAP_b_FPASwtStuckStatus = !SWC_APA_B.LogicalOperator2_n;

  /* UnitDelay: '<S22>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_a = SWC_APA_B.Switch3_iv;

  /* UnitDelay: '<S22>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_hq = SWC_APA_DW.UnitDelay1_DSTATE_fy;

  /* Switch: '<S22>/Switch3' incorporates:
   *  Constant: '<S22>/Constant1'
   *  Switch: '<S22>/Switch1'
   */
  if (SWC_APA_B.reset) {
    tmp = floor(0.0);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    SWC_APA_B.Switch3_iv = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  } else {
    if (SWC_APA_B.UnitDelay1_hq) {
      /* Switch: '<S22>/Switch1' */
      SWC_APA_B.Switch1_m = *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd;
    } else {
      /* RelationalOperator: '<S22>/Relational Operator' incorporates:
       *  Switch: '<S22>/Switch1'
       */
      SWC_APA_B.RelationalOperator_mv = (SWC_APA_B.UnitDelay2_a <=
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

      /* Switch: '<S22>/Switch2' incorporates:
       *  Constant: '<S22>/Constant'
       *  Switch: '<S22>/Switch1'
       */
      if (SWC_APA_B.RelationalOperator_mv) {
        SWC_APA_B.Switch2_f = 0.0;
      } else {
        /* Sum: '<S22>/Subtract' */
        SWC_APA_B.Subtract_mh = (uint16_T)(SWC_APA_B.UnitDelay2_a -
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_APA_B.Switch2_f = SWC_APA_B.Subtract_mh;
      }

      /* End of Switch: '<S22>/Switch2' */

      /* Switch: '<S22>/Switch1' */
      SWC_APA_B.Switch1_m = SWC_APA_B.Switch2_f;
    }

    tmp = floor(SWC_APA_B.Switch1_m);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    SWC_APA_B.Switch3_iv = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S22>/Switch3' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S22>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch3_iv >=
    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

  /* Logic: '<S22>/Logical Operator8' */
  SWC_APA_B.LogicalOperator8 = (SWC_APA_B.reset ||
    SWC_APA_B.RelationalOperator1_mc);

  /* UnitDelay: '<S27>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_ed = SWC_APA_B.Switch3_j;

  /* UnitDelay: '<S27>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_mb = SWC_APA_DW.UnitDelay1_DSTATE_c;

  /* Switch: '<S27>/Switch3' incorporates:
   *  Constant: '<S27>/Constant1'
   *  Switch: '<S27>/Switch1'
   */
  if (SWC_APA_B.reset_h) {
    tmp = floor(0.0);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    SWC_APA_B.Switch3_j = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  } else {
    if (SWC_APA_B.UnitDelay1_mb) {
      /* Switch: '<S27>/Switch1' */
      SWC_APA_B.Switch1_i = *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd;
    } else {
      /* RelationalOperator: '<S27>/Relational Operator' incorporates:
       *  Switch: '<S27>/Switch1'
       */
      SWC_APA_B.RelationalOperator_j = (SWC_APA_B.UnitDelay2_ed <=
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

      /* Switch: '<S27>/Switch2' incorporates:
       *  Constant: '<S27>/Constant'
       *  Switch: '<S27>/Switch1'
       */
      if (SWC_APA_B.RelationalOperator_j) {
        SWC_APA_B.Switch2 = 0.0;
      } else {
        /* Sum: '<S27>/Subtract' */
        SWC_APA_B.Subtract_ka = (uint16_T)(SWC_APA_B.UnitDelay2_ed -
          *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
        SWC_APA_B.Switch2 = SWC_APA_B.Subtract_ka;
      }

      /* End of Switch: '<S27>/Switch2' */

      /* Switch: '<S27>/Switch1' */
      SWC_APA_B.Switch1_i = SWC_APA_B.Switch2;
    }

    tmp = floor(SWC_APA_B.Switch1_i);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 65536.0);
    }

    SWC_APA_B.Switch3_j = (uint16_T)(tmp < 0.0 ? (int32_T)(uint16_T)-(int16_T)
      (uint16_T)-tmp : (int32_T)(uint16_T)tmp);
  }

  /* End of Switch: '<S27>/Switch3' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S27>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.Switch3_j >=
    *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);

  /* Logic: '<S27>/Logical Operator8' */
  SWC_APA_B.LogicalOperator8_p = (SWC_APA_B.reset_h ||
    SWC_APA_B.RelationalOperator1_mc);

  /* Update for Delay: '<S16>/Delay1' */
  SWC_APA_DW.icLoad_e = 0U;
  SWC_APA_DW.Delay1_DSTATE = SWC_APA_B.MeAP_b_FPAEnablingCond;

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_pa = *rtu_IbVBIA_VehState_IeVBII_b_FrntParkAsstReq;

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_bh = SWC_APA_B.LogicalOperator8;

  /* Update for Delay: '<S17>/Delay1' */
  SWC_APA_DW.icLoad_h = 0U;
  SWC_APA_DW.Delay1_DSTATE_d = SWC_APA_B.MeAP_b_RPAEnablingCond;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_em = *rtu_IbVBIA_VehState_IeVBII_b_ParkAsstReq;

  /* Update for UnitDelay: '<S27>/Unit Delay' */
  SWC_APA_DW.UnitDelay_DSTATE_jj = SWC_APA_B.LogicalOperator8_p;

  /* Update for Delay: '<S17>/Delay' */
  SWC_APA_DW.Delay_DSTATE_l = MeAP_b_RPASwtStatus;

  /* Update for Delay: '<S16>/Delay' */
  SWC_APA_DW.Delay_DSTATE_f = MeAP_b_FPASwtStatus;

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_fy = SWC_APA_B.reset;

  /* Update for UnitDelay: '<S27>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_c = SWC_APA_B.reset_h;

  /* End of Outputs for SubSystem: '<S4>/APA_EnablingCondition' */

  /* UnitDelay: '<S7>/Unit Delay' */
  SWC_APA_B.ECUPwrd = SWC_APA_DW.UnitDelay_DSTATE_e;

  /* RelationalOperator: '<S7>/Relational Operator2' incorporates:
   *  Constant: '<S684>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  SWC_APA_B.LogicalOperator1_d = *rtu_MbDiag_PlantModeOn;

  /* Logic: '<S7>/Logical Operator' */
  SWC_APA_B.LogicalOperator1_d = !SWC_APA_B.LogicalOperator1_d;

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator1' */
  SWC_APA_B.BitwiseOperator1_j = (SWC_APA_B.RelationalOperator_jv &&
    SWC_APA_B.LogicalOperator1_d);

  /* S-Function (sfix_bitop): '<S7>/Bitwise Operator' */
  SWC_APA_B.BitwiseOperator_g = (SWC_APA_B.ECUPwrd ||
    SWC_APA_B.BitwiseOperator1_j);

  /* Outputs for Enabled SubSystem: '<S7>/SavePreviousFrntStatus' incorporates:
   *  EnablePort: '<S685>/Enable'
   */
  if (SWC_APA_B.BitwiseOperator_g) {
    /* UnitDelay: '<S685>/Unit Delay' */
    SWC_APA_B.MeAP_e_FeatStsBeforeTrlrPrev = SWC_APA_DW.UnitDelay_DSTATE_m;

    /* If: '<S685>/If' */
    if (SWC_APA_B.ECUPwrd) {
      /* Outputs for IfAction SubSystem: '<S685>/UpdateBothFeatureSts' incorporates:
       *  ActionPort: '<S686>/Action Port'
       */
      /* SignalConversion: '<S686>/Signal Conversion' */
      SWC_APA_B.MeAP_e_FeatStsBeforeTrlr =
        rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts;

      /* End of Outputs for SubSystem: '<S685>/UpdateBothFeatureSts' */
    } else if (SWC_APA_B.MeAP_b_TrlrNotConnected) {
      /* Outputs for IfAction SubSystem: '<S685>/UpdateFPASts1' incorporates:
       *  ActionPort: '<S688>/Action Port'
       */
      /* SignalConversion: '<S688>/Signal Conversion' */
      SWC_APA_B.MeAP_e_FeatStsBeforeTrlr = *rty_MeAP_e_PAMOffStatus2BT;

      /* End of Outputs for SubSystem: '<S685>/UpdateFPASts1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S685>/UpdateFPASts' incorporates:
       *  ActionPort: '<S687>/Action Port'
       */
      /* DataTypeConversion: '<S687>/Data Type Conversion' */
      SWC_APA_B.DataTypeConversion_ebm = (uint8_T)*rty_MeAP_e_PAMOffStatus2BT;

      /* DataTypeConversion: '<S687>/Data Type Conversion1' */
      SWC_APA_B.DataTypeConversion1_p = (uint8_T)
        SWC_APA_B.MeAP_e_FeatStsBeforeTrlrPrev;

      /* S-Function (sfix_bitop): '<S687>/Bitwise Operator1' */
      SWC_APA_B.BitwiseOperator1 = (uint8_T)(SWC_APA_B.DataTypeConversion1_p &
        ((uint8_T)1U));

      /* S-Function (sfix_bitop): '<S687>/Bitwise Operator' */
      SWC_APA_B.BitwiseOperator = (uint8_T)(SWC_APA_B.DataTypeConversion_ebm |
        SWC_APA_B.BitwiseOperator1);

      /* DataTypeConversion: '<S687>/Data Type Conversion2' */
      SWC_APA_B.MeAP_e_FeatStsBeforeTrlr = (TeAP_e_PAMOffStatus2BT)
        SWC_APA_B.BitwiseOperator;

      /* End of Outputs for SubSystem: '<S685>/UpdateFPASts' */
    }

    /* End of If: '<S685>/If' */

    /* SignalConversion generated from: '<S685>/MeAP_e_FeatStsBeforeTrlr' */
    SWC_APA_B.MeAP_e_FeatStsBeforeTrlr_h = SWC_APA_B.MeAP_e_FeatStsBeforeTrlr;

    /* Update for UnitDelay: '<S685>/Unit Delay' */
    SWC_APA_DW.UnitDelay_DSTATE_m = SWC_APA_B.MeAP_e_FeatStsBeforeTrlr;
  }

  /* End of Outputs for SubSystem: '<S7>/SavePreviousFrntStatus' */

  /* Switch: '<S39>/Switch' incorporates:
   *  Constant: '<S41>/Constant'
   */
  if (*rtu_IbFID_PA_MeAP_b_FrntSenorFail) {
    *rty_IeAP_e_FrntSnsrStatus = TeAP_e_FrntSnsrStatus_NotActive_Failure;
  } else {
    /* RelationalOperator: '<S39>/Relational Operator' incorporates:
     *  Constant: '<S39>/Constant1'
     */
    SWC_APA_B.LogicalOperator_ev =
      (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
       KeAP_kph_FrntWarnMaxSpdThd);

    /* Logic: '<S39>/Logical Operator' */
    SWC_APA_B.LogicalOperator_ev = ((*rtu_IbFID_PA_MeAP_b_FrntSenorBlock) &&
      SWC_APA_B.LogicalOperator_ev);

    /* Switch: '<S39>/Switch1' incorporates:
     *  Constant: '<S42>/Constant'
     */
    if (SWC_APA_B.LogicalOperator_ev) {
      SWC_APA_B.Switch1_oo = TeAP_e_FrntSnsrStatus_NotActive_Blocked;
    } else {
      SWC_APA_B.Switch1_oo = SWC_APA_ConstB.Switch2_h;
    }

    /* End of Switch: '<S39>/Switch1' */
    *rty_IeAP_e_FrntSnsrStatus = SWC_APA_B.Switch1_oo;
  }

  /* End of Switch: '<S39>/Switch' */

  /* Switch: '<S40>/Switch' incorporates:
   *  Constant: '<S45>/Constant'
   */
  if (*rtu_IbFID_PA_MeAP_b_RearSenorFail) {
    *rty_IeAP_e_RearSnsrStatus = TeAP_e_RearSnsrStatus_NotActive_Failure;
  } else {
    /* RelationalOperator: '<S40>/Relational Operator' incorporates:
     *  Constant: '<S40>/Constant1'
     */
    SWC_APA_B.LogicalOperator_lt =
      (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
       KeAP_kph_RearWarnMaxSpdThd);

    /* Logic: '<S40>/Logical Operator' */
    SWC_APA_B.LogicalOperator_lt = ((*rtu_IbFID_PA_MeAP_b_RearSenorBlock) &&
      SWC_APA_B.LogicalOperator_lt);

    /* Switch: '<S40>/Switch1' incorporates:
     *  Constant: '<S46>/Constant'
     */
    if (SWC_APA_B.LogicalOperator_lt) {
      SWC_APA_B.Switch1_n = TeAP_e_RearSnsrStatus_NotActive_Blocked;
    } else {
      SWC_APA_B.Switch1_n = SWC_APA_ConstB.Switch2;
    }

    /* End of Switch: '<S40>/Switch1' */
    *rty_IeAP_e_RearSnsrStatus = SWC_APA_B.Switch1_n;
  }

  /* End of Switch: '<S40>/Switch' */

  /* Outputs for Atomic SubSystem: '<S4>/VehCndCheck' */
  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S11>/Relational Operator'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp >
    *rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S11>/Constant1'
   *  RelationalOperator: '<S11>/Relational Operator3'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp <
    (-40.0F));

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S11>/Logical Operator9'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.LogicalOperator2_n);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S11>/Constant5'
   *  Logic: '<S11>/Logical Operator7'
   *  RelationalOperator: '<S11>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_IeVBII_degC_ExtTemp >
    170.0F);
  SWC_APA_B.LogicalOperator2_n = !SWC_APA_B.LogicalOperator2_n;

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S11>/Logical Operator10'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* Logic: '<S11>/Logical Operator11' */
  SWC_APA_B.LogicalOperator11 = !SWC_APA_B.RelationalOperator1_mc;

  /* End of Outputs for SubSystem: '<S4>/VehCndCheck' */

  /* Saturate: '<S5>/Saturation' */
  if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd > 5.0F) {
    SWC_APA_B.Saturation = 5.0F;
  } else if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd < 0.0F) {
    SWC_APA_B.Saturation = 0.0F;
  } else {
    SWC_APA_B.Saturation = *rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd;
  }

  /* End of Saturate: '<S5>/Saturation' */

  /* Saturate: '<S5>/Saturation1' */
  if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd > 20.0F) {
    SWC_APA_B.Saturation1 = 20.0F;
  } else if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd < 0.0F) {
    SWC_APA_B.Saturation1 = 0.0F;
  } else {
    SWC_APA_B.Saturation1 =
      *rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd;
  }

  /* End of Saturate: '<S5>/Saturation1' */

  /* Saturate: '<S5>/Saturation2' */
  if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd > 20.0F) {
    SWC_APA_B.Saturation2 = 20.0F;
  } else if (*rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd < 0.0F) {
    SWC_APA_B.Saturation2 = 0.0F;
  } else {
    SWC_APA_B.Saturation2 =
      *rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd;
  }

  /* End of Saturate: '<S5>/Saturation2' */

  /* Chart: '<S5>/APA_StateMachine' incorporates:
   *  Constant: '<S11>/Constant'
   *  Constant: '<S2>/Constant4'
   */
  if (SWC_APA_DW.is_active_c25_SWC_APA == 0U) {
    SWC_APA_DW.is_active_c25_SWC_APA = 1U;
    SWC_APA_DW.is_PA_FEAT_STATUS = SWC_APA_IN_OFF;
    *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Off;
    *rty_MeAP_b_FPAStatus = false;
    *rty_MeAP_b_RPAStatus = false;
    SWC_APA_B.MeAP_TransitionDebugVar = 0U;
    SWC_APA_DW.is_PA_FAULT_STATUS = SWC_APA_IN_PA_NO_FAULT;
    *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_False;
  } else {
    if (SWC_APA_DW.is_PA_FEAT_STATUS == SWC_APA_IN_OFF) {
      *rty_MeAP_b_FPAStatus = false;
      *rty_MeAP_b_RPAStatus = false;
      if ((*rty_MeAP_e_PAMOffStatus2BT != TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF) ||
          (*rtu_IeAP_e_ParKMnvrActv == TeAP_e_ParKMnvrActv_Engaged_Semi) ||
          (*rtu_IeAP_e_ParKMnvrActv == TeAP_e_ParKMnvrActv_Engaged_Full) ||
          (*rtu_MbDiag_TestModeForceOn)) {
        SWC_APA_DW.is_PA_FEAT_STATUS = SWC_APA_IN_ON;
        SWC_APA_DW.is_ON = SWC_APA_IN_INIT;
        *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Initialize;
        *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_False;
        *rty_MeAP_b_FPAStatus = false;
        *rty_MeAP_b_RPAStatus = false;
        SWC_APA_B.MeAP_TransitionDebugVar = 3U;
      }
    } else {
      /* case IN_ON: */
      if ((((*rty_MeAP_e_PAMOffStatus2BT == TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF)
            && (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Semi) &&
            (*rtu_IeAP_e_ParKMnvrActv != TeAP_e_ParKMnvrActv_Engaged_Full)) || (*
            rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts != TeVBII_e_CmdIgnSts_RUN)) &&
          ((*rtu_MbDiag_PlantModeOn) || (!*rtu_MbDiag_TestModeForceOn))) {
        SWC_APA_B.MeAP_TransitionDebugVar = 2U;
        SWC_APA_exit_internal_ACTIVE();
        SWC_APA_DW.is_ON = SWC_APA_IN_NO_ACTIVE_CHILD_im;
        SWC_APA_DW.is_PA_FEAT_STATUS = SWC_APA_IN_OFF;
        *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Off;
        *rty_MeAP_b_FPAStatus = false;
        *rty_MeAP_b_RPAStatus = false;
        *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_False;
        SWC_APA_B.MeAP_TransitionDebugVar = 0U;
      } else {
        switch (SWC_APA_DW.is_ON) {
         case SWC_APA_IN_ACTIVE:
          SWC_APA_ACTIVE(rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear,
                         rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig,
                         rtu_IbFID_PA_MeAP_b_FPADisable,
                         rtu_IbFID_PA_MeAP_b_RPADisable, rtu_IeAP_e_ParKMnvrActv,
                         rtu_MeTHA_e_RearBrkSupprInfo,
                         rtu_MbDiag_TestModeForceOn, rty_MeAP_e_ParkAssistStatus,
                         rty_MeAP_b_FPAStatus, rty_MeAP_b_RPAStatus,
                         rty_MeAP_e_PAMOffStatus2BT, rty_IeAP_e_FrntSnsrStatus,
                         rty_IeAP_e_RearSnsrStatus);
          break;

         case SWC_APA_IN_INIT:
          *rty_MeAP_b_FPAStatus = false;
          *rty_MeAP_b_RPAStatus = false;
          if (true) {
            SWC_APA_DW.is_ON = SWC_APA_IN_STANDBY;
            *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Standby;
            *rty_MeAP_b_FPAStatus = false;
            *rty_MeAP_b_RPAStatus = false;
            SWC_APA_B.MeAP_TransitionDebugVar = 5U;
          } else {
            /* ECU Test Mode */
            if (*rtu_MbDiag_TestModeForceOn) {
              SWC_APA_DW.is_ON = SWC_APA_IN_ACTIVE;
              *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Active;
              SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_Off;
              *rty_MeAP_b_FPAStatus = false;
              SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_Off_e;
              *rty_MeAP_b_RPAStatus = false;
              SWC_APA_B.MeAP_TransitionDebugVar = 16U;
            }
          }
          break;

         default:
          /* case IN_STANDBY: */
          *rty_MeAP_b_FPAStatus = false;
          *rty_MeAP_b_RPAStatus = false;
          if (true) {
            SWC_APA_DW.is_ON = SWC_APA_IN_ACTIVE;
            *rty_MeAP_e_ParkAssistStatus = TeAP_e_ParkAssistStatus_Active;
            SWC_APA_DW.is_FPA_ACTIVE = SWC_APA_IN_Off;
            *rty_MeAP_b_FPAStatus = false;
            SWC_APA_DW.is_RPA_ACTIVE = SWC_APA_IN_Off_e;
            *rty_MeAP_b_RPAStatus = false;
            SWC_APA_B.MeAP_TransitionDebugVar = 16U;
          }
          break;
        }
      }
    }

    if (SWC_APA_DW.is_PA_FAULT_STATUS == SWC_APA_IN_PA_FAULT) {
      if ((!*rtu_IbFID_PA_MeAP_b_SystemFail) &&
          (!*rtu_IbFID_PA_MeAP_b_ExternalFail) && (!*rtu_MbDiag_PlantModeOn)) {
        SWC_APA_DW.is_PA_FAULT_STATUS = SWC_APA_IN_PA_NO_FAULT;
        *rty_IeAP_e_PAMSystemFault = TeAP_e_PAMSystemFault_False;
      } else {
        SWC_APA_inner_default_PA_FAULT(rtu_IbFID_PA_MeAP_b_ExternalFail,
          rtu_IbFID_PA_MeAP_b_SystemFail, rtu_MbDiag_PlantModeOn,
          rty_MeAP_e_ParkAssistStatus, rty_IeAP_e_PAMSystemFault);
      }
    } else {
      /* case IN_PA_NO_FAULT: */
      if ((*rtu_IbFID_PA_MeAP_b_SystemFail) ||
          (*rtu_IbFID_PA_MeAP_b_ExternalFail) || (*rtu_MbDiag_PlantModeOn)) {
        SWC_APA_DW.is_PA_FAULT_STATUS = SWC_APA_IN_PA_FAULT;
        SWC_APA_inner_default_PA_FAULT(rtu_IbFID_PA_MeAP_b_ExternalFail,
          rtu_IbFID_PA_MeAP_b_SystemFail, rtu_MbDiag_PlantModeOn,
          rty_MeAP_e_ParkAssistStatus, rty_IeAP_e_PAMSystemFault);
      }
    }
  }

  /* End of Chart: '<S5>/APA_StateMachine' */

  /* Outputs for Atomic SubSystem: '<S2>/Rear_Front_ParkAssist' */
  /* Outputs for Atomic SubSystem: '<S6>/FPA' */
  SWC_APA_FPA();

  /* End of Outputs for SubSystem: '<S6>/FPA' */

  /* Outputs for Atomic SubSystem: '<S6>/RPA' */
  SWC_APA_RPA();

  /* End of Outputs for SubSystem: '<S6>/RPA' */

  /* RelationalOperator: '<S51>/Relational Operator5' incorporates:
   *  Constant: '<S73>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rty_MeAP_e_AlertCHR != TeAP_e_Alert_Arc1);

  /* RelationalOperator: '<S51>/Relational Operator4' incorporates:
   *  Constant: '<S74>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rty_MeAP_e_AlertLHR != TeAP_e_Alert_Arc1);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S70>/Constant'
   *  RelationalOperator: '<S51>/Relational Operator6'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_MeAP_e_AlertRHR != TeAP_e_Alert_Arc1);

  /* Logic: '<S51>/Logical Operator4' */
  SWC_APA_B.LogicalOperator1_d = (SWC_APA_B.LogicalOperator1_d &&
    SWC_APA_B.RelationalOperator_jv && SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S71>/Constant'
   *  RelationalOperator: '<S51>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_MeAP_e_AlertCHF == TeAP_e_Alert_Arc1);

  /* RelationalOperator: '<S51>/Relational Operator2' incorporates:
   *  Constant: '<S72>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rty_MeAP_e_AlertLHF == TeAP_e_Alert_Arc1);

  /* RelationalOperator: '<S51>/Relational Operator3' incorporates:
   *  Constant: '<S65>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rty_MeAP_e_AlertRHF == TeAP_e_Alert_Arc1);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S51>/Logical Operator'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e ||
    SWC_APA_B.RelationalOperator_jv || SWC_APA_B.RelationalOperator7);

  /* Logic: '<S51>/Logical Operator3' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator8_e &&
    SWC_APA_B.LogicalOperator1_d);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S51>/Logical Operator9'
   */
  SWC_APA_B.RelationalOperator8_e = !SWC_APA_B.RelationalOperator8_e;

  /* RelationalOperator: '<S51>/Relational Operator10' incorporates:
   *  Constant: '<S67>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rty_MeAP_e_AlertCHF == TeAP_e_Alert_Arc2);

  /* RelationalOperator: '<S51>/Relational Operator11' incorporates:
   *  Constant: '<S66>/Constant'
   */
  SWC_APA_B.Compare_k = (*rty_MeAP_e_AlertLHF == TeAP_e_Alert_Arc2);

  /* RelationalOperator: '<S51>/Relational Operator12' incorporates:
   *  Constant: '<S68>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rty_MeAP_e_AlertRHF == TeAP_e_Alert_Arc2);

  /* Logic: '<S51>/Logical Operator8' */
  SWC_APA_B.RelationalOperator_jv = (SWC_APA_B.RelationalOperator_jv ||
    SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S51>/Logical Operator10'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e &&
    SWC_APA_B.RelationalOperator_jv);

  /* RelationalOperator: '<S51>/Relational Operator8' incorporates:
   *  Constant: '<S76>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rty_MeAP_e_AlertCHR != TeAP_e_Alert_Arc2);

  /* RelationalOperator: '<S51>/Relational Operator7' incorporates:
   *  Constant: '<S75>/Constant'
   */
  SWC_APA_B.Compare_k = (*rty_MeAP_e_AlertLHR != TeAP_e_Alert_Arc2);

  /* RelationalOperator: '<S51>/Relational Operator9' incorporates:
   *  Constant: '<S77>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rty_MeAP_e_AlertRHR != TeAP_e_Alert_Arc2);

  /* Logic: '<S51>/Logical Operator5' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator_jv);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S51>/Logical Operator11'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e &&
    SWC_APA_B.LogicalOperator1_d && SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S51>/Logical Operator1' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.MeAP_b_ChimeActvLHR ||
    SWC_APA_B.MeAP_b_ChimeActvRHR);

  /* Logic: '<S51>/Logical Operator2' */
  SWC_APA_B.RelationalOperator2_j = !SWC_APA_B.RelationalOperator2_j;

  /* Logic: '<S51>/Logical Operator12' */
  SWC_APA_B.LogicalOperator12 = (SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e || SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S51>/Logical Operator7' */
  SWC_APA_B.RelationalOperator2_j = !*rtu_IbVBIA_VehState_IeVBII_b_ParkProxChime;

  /* RelationalOperator: '<S51>/Relational Operator14' incorporates:
   *  Constant: '<S69>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Engaged_Full);

  /* Logic: '<S51>/Logical Operator6' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.Compare_k);

  /* Switch generated from: '<S51>/Switch1' incorporates:
   *  Constant: '<S51>/Constant4'
   *  Constant: '<S51>/Constant5'
   *  Constant: '<S51>/Constant6'
   *  Constant: '<S51>/Constant7'
   *  Switch generated from: '<S51>/Switch'
   */
  if (SWC_APA_B.RelationalOperator2_j) {
    *rty_MeAP_b_ChimeActvLHF = false;
    *rty_MeAP_b_ChimeActvRHF = false;
    *rty_MeAP_b_ChimeActvLHR = false;
    *rty_MeAP_b_ChimeActvRHR = false;
  } else {
    if (SWC_APA_B.LogicalOperator12) {
      /* SignalConversion: '<S51>/Signal Conversion' incorporates:
       *  Switch generated from: '<S51>/Switch'
       */
      SWC_APA_B.MeAP_b_ChimeActv_LHF_g = SWC_APA_B.MeAP_b_ChimeActvLHF;

      /* Switch generated from: '<S51>/Switch' */
      SWC_APA_B.MeAP_b_ChimeActv_LHF = SWC_APA_B.MeAP_b_ChimeActv_LHF_g;

      /* SignalConversion: '<S51>/Signal Conversion1' incorporates:
       *  Switch generated from: '<S51>/Switch'
       */
      SWC_APA_B.MeAP_b_ChimeActv_RHF_o = SWC_APA_B.MeAP_b_ChimeActvRHF;

      /* Switch generated from: '<S51>/Switch' */
      SWC_APA_B.MeAP_b_ChimeActv_RHF = SWC_APA_B.MeAP_b_ChimeActv_RHF_o;
    } else {
      /* Switch generated from: '<S51>/Switch' incorporates:
       *  Constant: '<S51>/Constant2'
       */
      SWC_APA_B.MeAP_b_ChimeActv_LHF = false;

      /* Switch generated from: '<S51>/Switch' incorporates:
       *  Constant: '<S51>/Constant3'
       */
      SWC_APA_B.MeAP_b_ChimeActv_RHF = false;
    }

    *rty_MeAP_b_ChimeActvLHF = SWC_APA_B.MeAP_b_ChimeActv_LHF;
    *rty_MeAP_b_ChimeActvRHF = SWC_APA_B.MeAP_b_ChimeActv_RHF;

    /* Switch generated from: '<S51>/Switch' incorporates:
     *  Constant: '<S51>/Constant'
     *  Constant: '<S51>/Constant1'
     */
    if (SWC_APA_B.LogicalOperator12) {
      SWC_APA_B.MeAP_b_ChimeActv_LHR = false;
      SWC_APA_B.MeAP_b_ChimeActv_RHR = false;
    } else {
      /* SignalConversion: '<S51>/Signal Conversion2' */
      SWC_APA_B.MeAP_b_ChimeActv_LHR_f = SWC_APA_B.MeAP_b_ChimeActvLHR;
      SWC_APA_B.MeAP_b_ChimeActv_LHR = SWC_APA_B.MeAP_b_ChimeActv_LHR_f;

      /* SignalConversion: '<S51>/Signal Conversion3' */
      SWC_APA_B.MeAP_b_ChimeActv_RHR_n = SWC_APA_B.MeAP_b_ChimeActvRHR;
      SWC_APA_B.MeAP_b_ChimeActv_RHR = SWC_APA_B.MeAP_b_ChimeActv_RHR_n;
    }

    *rty_MeAP_b_ChimeActvLHR = SWC_APA_B.MeAP_b_ChimeActv_LHR;
    *rty_MeAP_b_ChimeActvRHR = SWC_APA_B.MeAP_b_ChimeActv_RHR;
  }

  /* End of Switch generated from: '<S51>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S6>/PAMVolumeGen' */
  /* Outputs for Atomic SubSystem: '<S6>/PAMChimeTypeUpdate' */
  /* Outputs for Atomic SubSystem: '<S6>/CalPAMChimeRepnRate' */
  /* Logic: '<S50>/Logical Operator' incorporates:
   *  Logic: '<S53>/Logical Operator2'
   *  Logic: '<S55>/Logical Operator2'
   *  Switch: '<S53>/Switch'
   */
  SWC_APA_B.RelationalOperator1_e1 = ((*rty_MeAP_b_ChimeActvLHF) ||
    (*rty_MeAP_b_ChimeActvRHF));

  /* End of Outputs for SubSystem: '<S6>/PAMChimeTypeUpdate' */
  /* End of Outputs for SubSystem: '<S6>/PAMVolumeGen' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S50>/Logical Operator'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.RelationalOperator1_e1 ||
    (*rty_MeAP_b_ChimeActvRHR) || (*rty_MeAP_b_ChimeActvLHR));

  /* Switch: '<S50>/Switch' incorporates:
   *  Constant: '<S64>/Constant'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    /* Switch: '<S50>/Switch4' incorporates:
     *  Constant: '<S63>/Constant'
     */
    if (*rty_MeAP_b_ChimeActvRHR) {
      SWC_APA_B.Switch1_jn = SWC_APA_B.MeAP_e_RtRearChimeRepnRate;
    } else {
      SWC_APA_B.Switch1_jn = TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
    }

    /* End of Switch: '<S50>/Switch4' */

    /* DataTypeConversion: '<S50>/Data Type Conversion3' */
    SWC_APA_B.DataTypeConversion3 = (uint8_T)SWC_APA_B.Switch1_jn;

    /* Switch: '<S50>/Switch3' incorporates:
     *  Constant: '<S62>/Constant'
     */
    if (*rty_MeAP_b_ChimeActvLHR) {
      SWC_APA_B.Switch1_jn = SWC_APA_B.MeAP_e_LtRearChimeRepnRate;
    } else {
      SWC_APA_B.Switch1_jn = TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
    }

    /* End of Switch: '<S50>/Switch3' */

    /* DataTypeConversion: '<S50>/Data Type Conversion2' */
    SWC_APA_B.DataTypeConversion2 = (uint8_T)SWC_APA_B.Switch1_jn;

    /* Switch: '<S50>/Switch2' incorporates:
     *  Constant: '<S61>/Constant'
     */
    if (*rty_MeAP_b_ChimeActvRHF) {
      SWC_APA_B.Switch1_jn = SWC_APA_B.MeAP_e_RtFrntChimeRepnRate;
    } else {
      SWC_APA_B.Switch1_jn = TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
    }

    /* End of Switch: '<S50>/Switch2' */

    /* DataTypeConversion: '<S50>/Data Type Conversion1' */
    SWC_APA_B.DataTypeConversion1_i3 = (uint8_T)SWC_APA_B.Switch1_jn;

    /* Switch: '<S50>/Switch1' incorporates:
     *  Constant: '<S60>/Constant'
     */
    if (*rty_MeAP_b_ChimeActvLHF) {
      SWC_APA_B.Switch1_jn = SWC_APA_B.MeAP_e_LtFrntChimeRepnRate;
    } else {
      SWC_APA_B.Switch1_jn = TeAP_e_PAMChimeRepnRate_Fast_5_Hz;
    }

    /* End of Switch: '<S50>/Switch1' */

    /* MinMax: '<S50>/MinMax' incorporates:
     *  DataTypeConversion: '<S50>/Data Type Conversion'
     */
    SWC_APA_B.MinMax = (uint8_T)SWC_APA_B.Switch1_jn;
    if (SWC_APA_B.MinMax >= SWC_APA_B.DataTypeConversion1_i3) {
      SWC_APA_B.MinMax = SWC_APA_B.DataTypeConversion1_i3;
    }

    if (SWC_APA_B.MinMax >= SWC_APA_B.DataTypeConversion2) {
      SWC_APA_B.MinMax = SWC_APA_B.DataTypeConversion2;
    }

    if (SWC_APA_B.MinMax >= SWC_APA_B.DataTypeConversion3) {
      SWC_APA_B.MinMax = SWC_APA_B.DataTypeConversion3;
    }

    /* End of MinMax: '<S50>/MinMax' */

    /* DataTypeConversion: '<S50>/Data Type Conversion5' */
    SWC_APA_B.DataTypeConversion5 = (TeAP_e_PAMChimeRepnRate)SWC_APA_B.MinMax;
    *rty_MeAP_e_PAMChimeRepnRate = SWC_APA_B.DataTypeConversion5;
  } else {
    *rty_MeAP_e_PAMChimeRepnRate = TeAP_e_PAMChimeRepnRate_Continous_0_Hz;
  }

  /* End of Switch: '<S50>/Switch' */
  /* End of Outputs for SubSystem: '<S6>/CalPAMChimeRepnRate' */

  /* Outputs for Atomic SubSystem: '<S6>/PAMVolumeGen' */
  /* Outputs for Atomic SubSystem: '<S6>/PAMChimeTypeUpdate' */
  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S55>/Logical Operator4'
   *  Switch: '<S55>/Switch'
   */
  SWC_APA_B.RelationalOperator1_mc = ((*rty_MeAP_b_ChimeActvLHR) ||
    (*rty_MeAP_b_ChimeActvRHR));

  /* End of Outputs for SubSystem: '<S6>/PAMVolumeGen' */

  /* Switch: '<S53>/Switch' incorporates:
   *  Constant: '<S238>/Constant'
   */
  if (SWC_APA_B.RelationalOperator1_mc) {
    *rty_MeAP_e_PAMChimeTyp = TeAP_e_PAMChimeTyp_Type4;
  } else {
    /* Logic: '<S53>/Logical Operator2' */
    SWC_APA_B.LogicalOperator2_i = SWC_APA_B.RelationalOperator1_e1;

    /* Switch: '<S53>/Switch1' incorporates:
     *  Constant: '<S239>/Constant'
     *  Constant: '<S240>/Constant'
     */
    if (SWC_APA_B.LogicalOperator2_i) {
      SWC_APA_B.Switch1_dd = TeAP_e_PAMChimeTyp_Type5;
    } else {
      SWC_APA_B.Switch1_dd = TeAP_e_PAMChimeTyp_None;
    }

    /* End of Switch: '<S53>/Switch1' */
    *rty_MeAP_e_PAMChimeTyp = SWC_APA_B.Switch1_dd;
  }

  /* End of Outputs for SubSystem: '<S6>/PAMChimeTypeUpdate' */

  /* Outputs for Atomic SubSystem: '<S6>/PAMVolumeGen' */
  /* Switch: '<S55>/Switch' */
  if (SWC_APA_B.RelationalOperator1_e1) {
    /* Logic: '<S55>/Logical Operator1' */
    SWC_APA_B.LogicalOperator1_k = ((*rtu_IbFID_PA_MeAP_b_PAVolDefMed) ||
      (*rtu_IbFID_PA_MeAP_b_FPAVolDefMed));

    /* Switch: '<S55>/Switch2' incorporates:
     *  Constant: '<S470>/Constant'
     */
    if (SWC_APA_B.LogicalOperator1_k) {
      SWC_APA_B.MeAP_e_PAMVolume = TeAP_e_PAMVolume_Medium;
    } else {
      /* DataTypeConversion: '<S55>/Data Type Conversion' */
      SWC_APA_B.DataTypeConversion_gm = (uint8_T)
        *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolFrnt;

      /* MultiPortSwitch: '<S55>/Multiport Switch1' incorporates:
       *  Constant: '<S476>/Constant'
       *  Constant: '<S477>/Constant'
       *  Constant: '<S478>/Constant'
       *  Constant: '<S479>/Constant'
       */
      switch (SWC_APA_B.DataTypeConversion_gm) {
       case 0:
        SWC_APA_B.MultiportSwitch1 = TeAP_e_PAMVolume_Low;
        break;

       case 1:
        SWC_APA_B.MultiportSwitch1 = TeAP_e_PAMVolume_Medium;
        break;

       case 2:
        SWC_APA_B.MultiportSwitch1 = TeAP_e_PAMVolume_High;
        break;

       default:
        SWC_APA_B.MultiportSwitch1 = TeAP_e_PAMVolume_None;
        break;
      }

      /* End of MultiPortSwitch: '<S55>/Multiport Switch1' */
      SWC_APA_B.MeAP_e_PAMVolume = SWC_APA_B.MultiportSwitch1;
    }

    /* End of Switch: '<S55>/Switch2' */
    *rty_MeAP_e_PAMVolume = SWC_APA_B.MeAP_e_PAMVolume;
  } else {
    /* Logic: '<S55>/Logical Operator4' */
    SWC_APA_B.LogicalOperator4_j = SWC_APA_B.RelationalOperator1_mc;

    /* Switch: '<S55>/Switch1' incorporates:
     *  Constant: '<S472>/Constant'
     */
    if (SWC_APA_B.LogicalOperator4_j) {
      /* Logic: '<S55>/Logical Operator3' */
      SWC_APA_B.LogicalOperator3 = ((*rtu_IbFID_PA_MeAP_b_PAVolDefMed) ||
        (*rtu_IbFID_PA_MeAP_b_RPAVolDefMed));

      /* Switch: '<S55>/Switch3' incorporates:
       *  Constant: '<S471>/Constant'
       */
      if (SWC_APA_B.LogicalOperator3) {
        SWC_APA_B.Switch3_i = TeAP_e_PAMVolume_Medium;
      } else {
        /* DataTypeConversion: '<S55>/Data Type Conversion1' */
        SWC_APA_B.DataTypeConversion1_i = (uint8_T)
          *rtu_IbVBIA_VehState_IeVBII_e_PamChimeVolRear;

        /* MultiPortSwitch: '<S55>/Multiport Switch' incorporates:
         *  Constant: '<S469>/Constant'
         *  Constant: '<S473>/Constant'
         *  Constant: '<S474>/Constant'
         *  Constant: '<S475>/Constant'
         */
        switch (SWC_APA_B.DataTypeConversion1_i) {
         case 0:
          SWC_APA_B.MultiportSwitch = TeAP_e_PAMVolume_Low;
          break;

         case 1:
          SWC_APA_B.MultiportSwitch = TeAP_e_PAMVolume_Medium;
          break;

         case 2:
          SWC_APA_B.MultiportSwitch = TeAP_e_PAMVolume_High;
          break;

         default:
          SWC_APA_B.MultiportSwitch = TeAP_e_PAMVolume_None;
          break;
        }

        /* End of MultiPortSwitch: '<S55>/Multiport Switch' */
        SWC_APA_B.Switch3_i = SWC_APA_B.MultiportSwitch;
      }

      /* End of Switch: '<S55>/Switch3' */
      SWC_APA_B.Switch1_a = SWC_APA_B.Switch3_i;
    } else {
      SWC_APA_B.Switch1_a = TeAP_e_PAMVolume_None;
    }

    /* End of Switch: '<S55>/Switch1' */
    *rty_MeAP_e_PAMVolume = SWC_APA_B.Switch1_a;
  }

  /* End of Outputs for SubSystem: '<S6>/PAMVolumeGen' */

  /* S-Function (sfix_bitop): '<S59>/Bitwise Operator1' */
  SWC_APA_B.BitwiseOperator1_e = (uint8_T)
    (rtu_MbNVM_ReadParam->Dtc_B12852A_Status & ((uint8_T)2U));

  /* RelationalOperator: '<S683>/Compare' incorporates:
   *  Constant: '<S683>/Constant'
   */
  SWC_APA_B.Compare = (SWC_APA_B.BitwiseOperator1_e != ((uint8_T)0U));

  /* S-Function (sfix_bitop): '<S59>/Bitwise Operator' */
  SWC_APA_B.BitwiseOperator_e = (uint8_T)
    (rtu_MbNVM_ReadParam->Dtc_B12852A_Status & ((uint8_T)1U));

  /* RelationalOperator: '<S682>/Compare' incorporates:
   *  Constant: '<S682>/Constant'
   */
  SWC_APA_B.Compare_b = (SWC_APA_B.BitwiseOperator_e != ((uint8_T)0U));

  /* UnitDelay: '<S58>/Unit Delay' */
  SWC_APA_B.RelationalOperator2_j = SWC_APA_DW.UnitDelay_DSTATE_k;

  /* UnitDelay: '<S58>/Unit Delay1' */
  SWC_APA_B.UnitDelay1 = SWC_APA_DW.UnitDelay1_DSTATE;

  /* RelationalOperator: '<S58>/Relational Operator2' incorporates:
   *  Constant: '<S675>/Constant'
   */
  SWC_APA_B.Compare_k = (SWC_APA_B.UnitDelay1 == TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S58>/Relational Operator1' incorporates:
   *  Constant: '<S674>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S58>/Logical Operator1' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator7);

  /* S-Function (sfix_bitop): '<S58>/Bitwise Operator' */
  SWC_APA_B.BitwiseOperator_l = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.Compare_k);

  /* Outputs for Enabled SubSystem: '<S58>/SavePreviousFrntStatus' incorporates:
   *  EnablePort: '<S676>/Enable'
   */
  if (SWC_APA_B.BitwiseOperator_l) {
    /* RelationalOperator: '<S676>/Relational Operator1' incorporates:
     *  Constant: '<S678>/Constant'
     */
    SWC_APA_B.RelationalOperator7 =
      (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
       TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

    /* Logic: '<S275>/Logical Operator2' incorporates:
     *  Constant: '<S679>/Constant'
     *  RelationalOperator: '<S676>/Relational Operator'
     */
    SWC_APA_B.RelationalOperator8_e =
      (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
       TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

    /* Logic: '<S676>/Logical Operator2' */
    SWC_APA_B.MeAP_b_PrevIgnCyclFrntSts = (SWC_APA_B.RelationalOperator8_e ||
      SWC_APA_B.RelationalOperator7);
  }

  /* End of Outputs for SubSystem: '<S58>/SavePreviousFrntStatus' */

  /* UnitDelay: '<S58>/Unit Delay2' */
  SWC_APA_B.RelationalOperator7 = SWC_APA_DW.UnitDelay2_DSTATE_l;

  /* Logic: '<S58>/Logical Operator2' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator7);

  /* S-Function (sfix_bitop): '<S58>/Bitwise Operator1' */
  SWC_APA_B.BitwiseOperator1_n = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.Compare_k);

  /* Outputs for Enabled SubSystem: '<S58>/SavePreviousRearStatus' incorporates:
   *  EnablePort: '<S677>/Enable'
   */
  if (SWC_APA_B.BitwiseOperator1_n) {
    /* RelationalOperator: '<S677>/Relational Operator1' incorporates:
     *  Constant: '<S680>/Constant'
     */
    SWC_APA_B.RelationalOperator2_j =
      (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
       TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

    /* RelationalOperator: '<S677>/Relational Operator' incorporates:
     *  Constant: '<S681>/Constant'
     */
    SWC_APA_B.Compare_k = (rtu_MbNVM_ReadParam->IeNVM_e_FrntRearParkSts ==
      TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

    /* Logic: '<S677>/Logical Operator2' */
    SWC_APA_B.MeAP_b_PrevIgnCyclRearSts = (SWC_APA_B.Compare_k ||
      SWC_APA_B.RelationalOperator2_j);
  }

  /* End of Outputs for SubSystem: '<S58>/SavePreviousRearStatus' */

  /* Outputs for Atomic SubSystem: '<S6>/PAMPopUpReq_Gen' */
  /* DataTypeConversion: '<S250>/Data Type Conversion1' */
  SWC_APA_B.DataTypeConversion1_d = (uint8_T)*rty_MeAP_e_AlertCHF;

  /* MultiPortSwitch: '<S250>/Multiport Switch' */
  if (SWC_APA_B.DataTypeConversion1_d == 0) {
    /* MinMax: '<S241>/Min' */
    SWC_APA_B.DataTypeConversion_c = SWC_APA_ConstB.DataTypeConversion2;
  } else {
    /* MinMax: '<S241>/Min' */
    SWC_APA_B.DataTypeConversion_c = SWC_APA_B.DataTypeConversion1_d;
  }

  /* End of MultiPortSwitch: '<S250>/Multiport Switch' */

  /* DataTypeConversion: '<S251>/Data Type Conversion1' */
  SWC_APA_B.DataTypeConversion1_g = (uint8_T)*rty_MeAP_e_AlertLHF;

  /* MultiPortSwitch: '<S251>/Multiport Switch' */
  if (SWC_APA_B.DataTypeConversion1_g == 0) {
    SWC_APA_B.MultiportSwitch_l = SWC_APA_ConstB.DataTypeConversion2_m;
  } else {
    SWC_APA_B.MultiportSwitch_l = SWC_APA_B.DataTypeConversion1_g;
  }

  /* End of MultiPortSwitch: '<S251>/Multiport Switch' */

  /* DataTypeConversion: '<S252>/Data Type Conversion1' */
  SWC_APA_B.DataTypeConversion1_n = (uint8_T)*rty_MeAP_e_AlertRHF;

  /* MultiPortSwitch: '<S252>/Multiport Switch' */
  if (SWC_APA_B.DataTypeConversion1_n == 0) {
    SWC_APA_B.MultiportSwitch_m = SWC_APA_ConstB.DataTypeConversion2_l;
  } else {
    SWC_APA_B.MultiportSwitch_m = SWC_APA_B.DataTypeConversion1_n;
  }

  /* End of MultiPortSwitch: '<S252>/Multiport Switch' */

  /* MinMax: '<S241>/Min' */
  if (SWC_APA_B.DataTypeConversion_c >= SWC_APA_B.MultiportSwitch_l) {
    SWC_APA_B.DataTypeConversion_c = SWC_APA_B.MultiportSwitch_l;
  }

  if (SWC_APA_B.DataTypeConversion_c >= SWC_APA_B.MultiportSwitch_m) {
    SWC_APA_B.DataTypeConversion_c = SWC_APA_B.MultiportSwitch_m;
  }

  /* DataTypeConversion: '<S241>/Data Type Conversion1' */
  SWC_APA_B.FrontObjMinZoneEnum = (TeAP_e_Alert)SWC_APA_B.DataTypeConversion_c;

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  Constant: '<S253>/Constant'
   *  RelationalOperator: '<S241>/Relational Operator'
   */
  SWC_APA_B.RelationalOperator1_e1 = (SWC_APA_B.FrontObjMinZoneEnum !=
    TeAP_e_Alert_SNA);

  /* RelationalOperator: '<S336>/Relational Operator1' incorporates:
   *  Constant: '<S346>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S336>/Relational Operator4' incorporates:
   *  Constant: '<S351>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Drive);

  /* RelationalOperator: '<S336>/Relational Operator2' incorporates:
   *  Constant: '<S349>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S350>/Constant'
   *  RelationalOperator: '<S336>/Relational Operator3'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S336>/Logical Operator' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S348>/Constant'
   *  RelationalOperator: '<S336>/Relational Operator15'
   */
  SWC_APA_B.RelationalOperator8_e = (*rtu_IeAP_e_SPMLatCtrlReqSts ==
    TeAP_e_SPMLatCtrlReqSts_SPM_Request);

  /* RelationalOperator: '<S336>/Relational Operator14' incorporates:
   *  Constant: '<S347>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rtu_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Engaged_Semi);

  /* RelationalOperator: '<S336>/Relational Operator7' incorporates:
   *  Constant: '<S353>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rtu_IeAP_e_ParKMnvrActv ==
    TeAP_e_ParKMnvrActv_Engaged_Full);

  /* Logic: '<S336>/Logical Operator2' */
  SWC_APA_B.LogicalOperator1_d = (SWC_APA_B.LogicalOperator1_d ||
    SWC_APA_B.RelationalOperator_jv);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S336>/Logical Operator6'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e &&
    SWC_APA_B.LogicalOperator1_d);

  /* Logic: '<S336>/Logical Operator7' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S336>/Constant'
   *  RelationalOperator: '<S336>/Relational Operator5'
   */
  SWC_APA_B.RelationalOperator8_e =
    (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
     KeAP_kph_RearWarnMaxSpdThd);

  /* RelationalOperator: '<S336>/Relational Operator6' incorporates:
   *  Constant: '<S352>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts !=
    TeVBII_e_VehEPBSts_Applied);

  /* Logic: '<S336>/Logical Operator1' */
  SWC_APA_B.MeAP_b_CarGraphicCond2 = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.RelationalOperator1_e1 && SWC_APA_B.Compare_k &&
    SWC_APA_B.RelationalOperator7 && SWC_APA_B.RelationalOperator8_e &&
    SWC_APA_B.LogicalOperator1_d);

  /* RelationalOperator: '<S335>/Relational Operator1' incorporates:
   *  Constant: '<S339>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S335>/Relational Operator2' incorporates:
   *  Constant: '<S340>/Constant'
   */
  SWC_APA_B.Compare_k = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S335>/Relational Operator3' incorporates:
   *  Constant: '<S341>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S344>/Constant'
   *  RelationalOperator: '<S335>/Relational Operator7'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* RelationalOperator: '<S335>/Relational Operator8' incorporates:
   *  Constant: '<S345>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S335>/Logical Operator' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e || SWC_APA_B.LogicalOperator1_d);

  /* RelationalOperator: '<S335>/Relational Operator4' incorporates:
   *  Constant: '<S342>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_ReverseGear);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S335>/Constant'
   *  RelationalOperator: '<S335>/Relational Operator5'
   */
  SWC_APA_B.RelationalOperator8_e =
    (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
     KeAP_kph_RearWarnMaxSpdThd);

  /* RelationalOperator: '<S335>/Relational Operator6' incorporates:
   *  Constant: '<S343>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts !=
    TeVBII_e_VehEPBSts_Applied);

  /* Logic: '<S335>/Logical Operator1' */
  SWC_APA_B.MeAP_b_CarGraphicCond1 = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator7 &&
    SWC_APA_B.RelationalOperator8_e && SWC_APA_B.LogicalOperator1_d);

  /* RelationalOperator: '<S337>/Relational Operator1' incorporates:
   *  Constant: '<S354>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S337>/Relational Operator2' incorporates:
   *  Constant: '<S361>/Constant'
   */
  SWC_APA_B.Compare_k = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S337>/Relational Operator3' incorporates:
   *  Constant: '<S362>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S365>/Constant'
   *  RelationalOperator: '<S337>/Relational Operator7'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S337>/Logical Operator' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7 ||
    SWC_APA_B.RelationalOperator8_e);

  /* RelationalOperator: '<S337>/Relational Operator4' incorporates:
   *  Constant: '<S363>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_ReverseGear);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Constant: '<S366>/Constant'
   *  RelationalOperator: '<S337>/Relational Operator5'
   */
  SWC_APA_B.RelationalOperator8_e = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S337>/Relational Operator8' incorporates:
   *  Constant: '<S367>/Constant'
   */
  SWC_APA_B.LogicalOperator1_d = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S337>/Relational Operator9' incorporates:
   *  Constant: '<S368>/Constant'
   */
  SWC_APA_B.RelationalOperator_jv = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_SNA);

  /* RelationalOperator: '<S337>/Relational Operator10' incorporates:
   *  Constant: '<S355>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S337>/Relational Operator11' incorporates:
   *  Constant: '<S356>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S337>/Relational Operator12' incorporates:
   *  Constant: '<S357>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_SNA);

  /* RelationalOperator: '<S337>/Relational Operator13' incorporates:
   *  Constant: '<S358>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_TemporaryFailure);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S359>/Constant'
   *  RelationalOperator: '<S337>/Relational Operator14'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S360>/Constant'
   *  RelationalOperator: '<S337>/Relational Operator15'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* Logic: '<S337>/Logical Operator3' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    SWC_APA_B.LogicalOperator2_n || SWC_APA_B.RelationalOperator1_mc);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S337>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator8_e = (SWC_APA_B.RelationalOperator8_e ||
    SWC_APA_B.LogicalOperator1_d || SWC_APA_B.RelationalOperator_jv ||
    SWC_APA_B.RelationalOperator6_p || SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.MeAP_b_FrontSwitchPressed || SWC_APA_B.RelationalOperator4_m);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S364>/Constant'
   *  RelationalOperator: '<S337>/Relational Operator6'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_VehEPBSts !=
    TeVBII_e_VehEPBSts_Applied);

  /* Logic: '<S337>/Logical Operator1' */
  SWC_APA_B.MeAP_b_CarGraphicCond3 = (SWC_APA_B.RelationalOperator2_j &&
    SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator7 &&
    SWC_APA_B.RelationalOperator8_e && SWC_APA_B.RelationalOperator1_mc);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  UnitDelay: '<S54>/Unit Delay'
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_B.RelationalOperator_d;

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S243>/Constant'
   *  RelationalOperator: '<S54>/Relational Operator1'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S54>/Logical Operator1' */
  SWC_APA_B.RelationalOperator4_m =
    !*rtu_IbVBIA_VehState_IeVBII_b_RemoteStartActvSts;

  /* Logic: '<S54>/Logical Operator' */
  SWC_APA_B.VehKeyDetected = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S468>/Logical Operator8'
   *  Logic: '<S468>/Logical Operator9'
   *  UnitDelay: '<S468>/Unit Delay1'
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.UnitDelay1_DSTATE_ko;
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.VehKeyDetected &&
    SWC_APA_B.RelationalOperator1_mc);

  /* UnitDelay: '<S467>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_it = SWC_APA_B.Switch3_po;

  /* UnitDelay: '<S54>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_nc = SWC_APA_B.MeAP_b_StrtUpPopUp_l;

  /* Switch: '<S467>/Switch3' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    /* Sum: '<S249>/Add' */
    SWC_APA_B.Add = (uint16_T)((uint32_T)
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd +
      *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd);
    SWC_APA_B.Switch3_po = SWC_APA_B.Add;
  } else {
    /* Logic: '<S467>/Logical Operator1' */
    SWC_APA_B.LogicalOperator1_m = !SWC_APA_B.UnitDelay2_nc;

    /* RelationalOperator: '<S467>/Relational Operator' */
    SWC_APA_B.ElapseTimer_h = (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
      SWC_APA_B.UnitDelay2_it);

    /* Logic: '<S467>/Logical Operator3' */
    SWC_APA_B.ElapseTimer_h = (SWC_APA_B.ElapseTimer_h &&
      SWC_APA_B.LogicalOperator1_m);

    /* Switch: '<S467>/Switch1' incorporates:
     *  Constant: '<S467>/Constant'
     */
    if (SWC_APA_B.ElapseTimer_h) {
      /* Sum: '<S467>/Subtract' */
      SWC_APA_B.Subtract_c = (uint16_T)(SWC_APA_B.UnitDelay2_it -
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_mh = SWC_APA_B.Subtract_c;
    } else {
      SWC_APA_B.Switch1_mh = ((uint16_T)0U);
    }

    /* End of Switch: '<S467>/Switch1' */
    SWC_APA_B.Switch3_po = SWC_APA_B.Switch1_mh;
  }

  /* End of Switch: '<S467>/Switch3' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S467>/Logical Operator4'
   *  RelationalOperator: '<S467>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc =
    (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_po);
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S424>/Constant'
   *  RelationalOperator: '<S383>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S383>/Relational Operator3' incorporates:
   *  Constant: '<S425>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S383>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S383>/Relational Operator4' incorporates:
   *  Constant: '<S426>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S383>/Relational Operator8' incorporates:
   *  Constant: '<S427>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S383>/Relational Operator10' incorporates:
   *  Constant: '<S423>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_Active);

  /* Logic: '<S383>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_WipeStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S441>/Constant'
   *  RelationalOperator: '<S387>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S387>/Relational Operator3' incorporates:
   *  Constant: '<S442>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S387>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S387>/Relational Operator4' incorporates:
   *  Constant: '<S443>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S387>/Relational Operator8' incorporates:
   *  Constant: '<S444>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_Active);

  /* RelationalOperator: '<S387>/Relational Operator10' incorporates:
   *  Constant: '<S440>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* Logic: '<S387>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_WipeStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S420>/Constant'
   *  RelationalOperator: '<S382>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S382>/Relational Operator4' incorporates:
   *  Constant: '<S421>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S382>/Relational Operator8' incorporates:
   *  Constant: '<S422>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S382>/Relational Operator10' incorporates:
   *  Constant: '<S419>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* Logic: '<S382>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Wipe_RR_WipeStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S404>/Constant'
   *  RelationalOperator: '<S378>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S378>/Relational Operator3' incorporates:
   *  Constant: '<S405>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S378>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S378>/Relational Operator4' incorporates:
   *  Constant: '<S406>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S378>/Relational Operator8' incorporates:
   *  Constant: '<S407>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S378>/Relational Operator10' incorporates:
   *  Constant: '<S403>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_Active);

  /* Logic: '<S378>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_SrvStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S429>/Constant'
   *  RelationalOperator: '<S384>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S384>/Relational Operator3' incorporates:
   *  Constant: '<S430>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S384>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S384>/Relational Operator4' incorporates:
   *  Constant: '<S431>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S384>/Relational Operator8' incorporates:
   *  Constant: '<S432>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_Active);

  /* RelationalOperator: '<S384>/Relational Operator10' incorporates:
   *  Constant: '<S428>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* Logic: '<S384>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_SrvStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S392>/Constant'
   *  RelationalOperator: '<S375>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S375>/Relational Operator1' incorporates:
   *  Constant: '<S390>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S375>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S375>/Relational Operator4' incorporates:
   *  Constant: '<S393>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S375>/Relational Operator8' incorporates:
   *  Constant: '<S394>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S375>/Relational Operator10' incorporates:
   *  Constant: '<S391>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* Logic: '<S375>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Srv_RR_SrvStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S412>/Constant'
   *  RelationalOperator: '<S380>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S380>/Relational Operator4' incorporates:
   *  Constant: '<S413>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S380>/Relational Operator8' incorporates:
   *  Constant: '<S414>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S380>/Relational Operator10' incorporates:
   *  Constant: '<S411>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* Logic: '<S380>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Wipe_RR_SrvStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S400>/Constant'
   *  RelationalOperator: '<S377>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S377>/Relational Operator4' incorporates:
   *  Constant: '<S401>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S377>/Relational Operator8' incorporates:
   *  Constant: '<S402>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S377>/Relational Operator10' incorporates:
   *  Constant: '<S399>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* Logic: '<S377>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Srv_RR_WipeStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S438>/Constant'
   *  RelationalOperator: '<S386>/Relational Operator4'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S386>/Relational Operator8' incorporates:
   *  Constant: '<S439>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_Active);

  /* RelationalOperator: '<S386>/Relational Operator10' incorporates:
   *  Constant: '<S437>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S386>/Relational Operator1' incorporates:
   *  Constant: '<S436>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts
    == TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S386>/Logical Operator2' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (SWC_APA_B.MeAP_b_FrontSwitchPressed ||
    SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S386>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_TrlrStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.MeAP_b_PrevIgnCyclRearSts && SWC_APA_B.LogicalOperator2_n &&
    SWC_APA_B.RelationalOperator4_m && SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S381>/Logical Operator3'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.MeAP_b_PrevIgnCyclFrntSts &&
    SWC_APA_B.MeAP_b_PrevIgnCyclRearSts);

  /* RelationalOperator: '<S376>/Relational Operator4' incorporates:
   *  Constant: '<S397>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S376>/Relational Operator8' incorporates:
   *  Constant: '<S398>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S376>/Relational Operator10' incorporates:
   *  Constant: '<S396>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S376>/Relational Operator1' incorporates:
   *  Constant: '<S395>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S376>/Logical Operator2' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S376>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Srv_RR_TrlrStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* RelationalOperator: '<S381>/Relational Operator4' incorporates:
   *  Constant: '<S417>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S381>/Relational Operator8' incorporates:
   *  Constant: '<S418>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S381>/Relational Operator10' incorporates:
   *  Constant: '<S416>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S381>/Relational Operator1' incorporates:
   *  Constant: '<S415>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S381>/Logical Operator2' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S381>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Wipe_RR_TrlrStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S445>/Constant'
   *  RelationalOperator: '<S388>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S388>/Relational Operator3' incorporates:
   *  Constant: '<S446>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* RelationalOperator: '<S388>/Relational Operator7' incorporates:
   *  Constant: '<S448>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S388>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m || SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* RelationalOperator: '<S388>/Relational Operator4' incorporates:
   *  Constant: '<S447>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* Logic: '<S388>/Logical Operator1' */
  SWC_APA_B.MeAP_b_Sys_FailStartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S449>/Constant'
   *  RelationalOperator: '<S389>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S389>/Relational Operator3' incorporates:
   *  Constant: '<S450>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* RelationalOperator: '<S389>/Relational Operator7' incorporates:
   *  Constant: '<S452>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S389>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m || SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* RelationalOperator: '<S389>/Relational Operator4' incorporates:
   *  Constant: '<S451>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S389>/Logical Operator2' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = !SWC_APA_B.Compare;

  /* Logic: '<S389>/Logical Operator3' */
  SWC_APA_B.RelationalOperator8_er = !SWC_APA_B.Compare_b;

  /* Logic: '<S389>/Logical Operator1' */
  SWC_APA_B.MeAP_b_Sys_Temp_NA_StartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed && SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S408>/Constant'
   *  RelationalOperator: '<S379>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S379>/Relational Operator3' incorporates:
   *  Constant: '<S409>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S379>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S379>/Relational Operator4' incorporates:
   *  Constant: '<S410>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S379>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_Temp_NA_StartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.Compare);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S433>/Constant'
   *  RelationalOperator: '<S385>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S385>/Relational Operator3' incorporates:
   *  Constant: '<S434>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S385>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S385>/Relational Operator4' incorporates:
   *  Constant: '<S435>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S385>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_Temp_NA_StartUp = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.Compare_b);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S454>/Constant'
   *  RelationalOperator: '<S453>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S456>/Constant'
   *  RelationalOperator: '<S453>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S453>/Relational Operator3' incorporates:
   *  Constant: '<S457>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* RelationalOperator: '<S453>/Relational Operator5' incorporates:
   *  Constant: '<S460>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S453>/Logical Operator'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m || SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* RelationalOperator: '<S453>/Relational Operator4' incorporates:
   *  Constant: '<S458>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S453>/Relational Operator8' incorporates:
   *  Constant: '<S453>/Constant1'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed =
    (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig > KeAP_kph_RearWarnMaxSpdThd);

  /* UnitDelay: '<S462>/Unit Delay3' */
  SWC_APA_B.UnitDelay3_l = SWC_APA_B.Switch5_jw;

  /* Switch: '<S462>/Switch5' incorporates:
   *  Constant: '<S462>/Constant1'
   */
  if (SWC_APA_B.MeAP_b_FrontSwitchPressed) {
    SWC_APA_B.Switch5_jw = true;
  } else {
    /* RelationalOperator: '<S453>/Relational Operator9' incorporates:
     *  Constant: '<S453>/Constant2'
     */
    SWC_APA_B.RelationalOperator9_d =
      (*rtu_IbVBIA_VehState_IeVBII_kph_VehSpeedVSOSig <=
       KeAP_kph_RearWarnMaxSpdThd - KeAP_kph_EnblHysThd);

    /* Switch: '<S462>/Switch6' incorporates:
     *  Constant: '<S462>/Constant3'
     */
    if (SWC_APA_B.RelationalOperator9_d) {
      SWC_APA_B.Switch6_bd = false;
    } else {
      SWC_APA_B.Switch6_bd = SWC_APA_B.UnitDelay3_l;
    }

    /* End of Switch: '<S462>/Switch6' */
    SWC_APA_B.Switch5_jw = SWC_APA_B.Switch6_bd;
  }

  /* End of Switch: '<S462>/Switch5' */

  /* RelationalOperator: '<S453>/Relational Operator7' incorporates:
   *  Constant: '<S461>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_Active);

  /* RelationalOperator: '<S453>/Relational Operator10' incorporates:
   *  Constant: '<S455>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_Active);

  /* RelationalOperator: '<S453>/Relational Operator6' incorporates:
   *  Constant: '<S459>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* Logic: '<S453>/Logical Operator1' */
  SWC_APA_B.MeAP_b_SpeedTooHigh = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.Switch5_jw && SWC_APA_B.MeAP_b_FrontSwitchPressed &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S369>/Constant'
   *  RelationalOperator: '<S338>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S372>/Constant'
   *  RelationalOperator: '<S338>/Relational Operator4'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear !=
    TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S338>/Relational Operator2' incorporates:
   *  Constant: '<S370>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S338>/Relational Operator3' incorporates:
   *  Constant: '<S371>/Constant'
   */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* RelationalOperator: '<S338>/Relational Operator7' incorporates:
   *  Constant: '<S373>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* RelationalOperator: '<S338>/Relational Operator8' incorporates:
   *  Constant: '<S374>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S338>/Logical Operator' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    SWC_APA_B.MeAP_b_FrontSwitchPressed || SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* UnitDelay: '<S464>/Unit Delay1' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = SWC_APA_DW.UnitDelay1_DSTATE_jm;

  /* RelationalOperator: '<S464>/Relational Operator' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = (MeAP_b_FPASwtStatus !=
    SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* UnitDelay: '<S463>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_ib = SWC_APA_B.Switch3_f;

  /* UnitDelay: '<S54>/Unit Delay1' */
  SWC_APA_B.UnitDelay1_k = SWC_APA_B.MeAP_b_BtnPrssPopUp;

  /* Switch: '<S463>/Switch3' incorporates:
   *  Constant: '<S247>/Constant'
   */
  if (SWC_APA_B.MeAP_b_FrontSwitchPressed) {
    SWC_APA_B.Switch3_f = KeAP_cnt_BtnPressPopUpTimeThd;
  } else {
    /* Logic: '<S463>/Logical Operator1' */
    SWC_APA_B.LogicalOperator1_lf = !SWC_APA_B.UnitDelay1_k;

    /* RelationalOperator: '<S463>/Relational Operator' */
    SWC_APA_B.ElapseTimer_hg = (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
      SWC_APA_B.UnitDelay2_ib);

    /* Logic: '<S463>/Logical Operator3' */
    SWC_APA_B.ElapseTimer_hg = (SWC_APA_B.ElapseTimer_hg &&
      SWC_APA_B.LogicalOperator1_lf);

    /* Switch: '<S463>/Switch1' incorporates:
     *  Constant: '<S463>/Constant'
     */
    if (SWC_APA_B.ElapseTimer_hg) {
      /* Sum: '<S463>/Subtract' */
      SWC_APA_B.Subtract_k = (uint16_T)(SWC_APA_B.UnitDelay2_ib -
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_kq = SWC_APA_B.Subtract_k;
    } else {
      SWC_APA_B.Switch1_kq = ((uint16_T)0U);
    }

    /* End of Switch: '<S463>/Switch1' */
    SWC_APA_B.Switch3_f = SWC_APA_B.Switch1_kq;
  }

  /* End of Switch: '<S463>/Switch3' */

  /* RelationalOperator: '<S463>/Relational Operator1' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed =
    (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_f);

  /* Logic: '<S463>/Logical Operator4' */
  SWC_APA_B.MeAP_b_FrontSwitchPressed = !SWC_APA_B.MeAP_b_FrontSwitchPressed;

  /* UnitDelay: '<S466>/Unit Delay1' */
  SWC_APA_B.RelationalOperator8_er = SWC_APA_DW.UnitDelay1_DSTATE_oc;

  /* RelationalOperator: '<S466>/Relational Operator' */
  SWC_APA_B.RelationalOperator8_er = (MeAP_b_RPASwtStatus !=
    SWC_APA_B.RelationalOperator8_er);

  /* UnitDelay: '<S465>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_h = SWC_APA_B.Switch3_b;

  /* Switch: '<S465>/Switch3' incorporates:
   *  Constant: '<S248>/Constant'
   */
  if (SWC_APA_B.RelationalOperator8_er) {
    SWC_APA_B.Switch3_b = KeAP_cnt_BtnPressPopUpTimeThd;
  } else {
    /* Logic: '<S465>/Logical Operator1' */
    SWC_APA_B.LogicalOperator1_i = !SWC_APA_B.UnitDelay1_k;

    /* RelationalOperator: '<S465>/Relational Operator' */
    SWC_APA_B.ElapseTimer_e = (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
      SWC_APA_B.UnitDelay2_h);

    /* Logic: '<S465>/Logical Operator3' */
    SWC_APA_B.ElapseTimer_e = (SWC_APA_B.ElapseTimer_e &&
      SWC_APA_B.LogicalOperator1_i);

    /* Switch: '<S465>/Switch1' incorporates:
     *  Constant: '<S465>/Constant'
     */
    if (SWC_APA_B.ElapseTimer_e) {
      /* Sum: '<S465>/Subtract' */
      SWC_APA_B.Subtract_pb = (uint16_T)(SWC_APA_B.UnitDelay2_h -
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_nq = SWC_APA_B.Subtract_pb;
    } else {
      SWC_APA_B.Switch1_nq = ((uint16_T)0U);
    }

    /* End of Switch: '<S465>/Switch1' */
    SWC_APA_B.Switch3_b = SWC_APA_B.Switch1_nq;
  }

  /* End of Switch: '<S465>/Switch3' */

  /* RelationalOperator: '<S465>/Relational Operator1' */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_b);

  /* Logic: '<S465>/Logical Operator4' */
  SWC_APA_B.RelationalOperator8_er = !SWC_APA_B.RelationalOperator8_er;

  /* SignalConversion: '<S248>/Signal Conversion' */
  SWC_APA_B.MeAP_b_RearSwitchPressed = SWC_APA_B.RelationalOperator8_er;

  /* Logic: '<S338>/Logical Operator2' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.MeAP_b_FrontSwitchPressed ||
    SWC_APA_B.MeAP_b_RearSwitchPressed);

  /* Logic: '<S338>/Logical Operator1' */
  SWC_APA_B.MeAP_b_CarGraphicCond4 = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S268>/Constant'
   *  RelationalOperator: '<S262>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IeTRSC_e_TRSCPopupDispInfo !=
    TeTRSC_e_TRSCPopupDispInfo_Disp0);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S269>/Constant'
   *  RelationalOperator: '<S262>/Relational Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IeTRSC_e_TRSCPopupDispInfo !=
    TeTRSC_e_TRSCPopupDispInfo_SNA);

  /* Logic: '<S262>/Logical Operator' */
  SWC_APA_B.MeAP_b_IDLE_HMI = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n);

  /* Truth Table: '<S54>/PopUpPriority1' incorporates:
   *  Constant: '<S263>/Constant'
   *  Constant: '<S263>/Constant1'
   *  Constant: '<S263>/Constant2'
   *  Constant: '<S263>/Constant3'
   *  Constant: '<S263>/Constant4'
   *  Constant: '<S263>/Constant5'
   *  Constant: '<S263>/Constant6'
   *  Constant: '<S263>/Constant7'
   */
  /*  IDLE_HMI */
  /*  PAM_SYS_TEMP_NA_BUTTONPRESS */
  /*  PAM_SYS_TEMP_NA_STARTUP */
  /*  PAM_RR_TEMP_NA_STARTUP */
  /*  PAM_FT_TEMP_NA_STARTUP */
  /*  PAM_SYS_FAIL_STARTUP */
  /*  PAM_FT_FAIL_BUTTONPRESS */
  /*  PAM_RR_FAIL_BUTTONPRESS */
  /*  SPEED_TOO_HIGH */
  /*  PAM_FT_SRV_RR_SRV_STARTUP */
  /*  PAM_FT_WIPE_RR_SRV_STARTUP */
  /*  PAM_FT_SRV_RR_WIPE_STARTUP */
  /*  PAM_FT_SRV_RR_TRLR_STARTUP */
  /*  PAM_FT_WIPE_RR_WIPE_STARTUP */
  /*  PAM_FT_WIPE_RR_TRLR_STARTUP */
  /*  PAM_FT_SRV_STARTUP */
  /*  PAM_FT_SRV_STARTUP */
  /*  PAM_RR_WIPE_STARTUP */
  /*  PAM_FT_WIPE_STARTUP */
  /*  PAM_RR_TRLR_STARTUP */
  /*  PAM_RR_SRV_BUTTONPRESS */
  /*  PAM_FT_SRV_BUTTONPRESS */
  /*  PAM_RR_WIPE_BUTTONPRESS */
  /*  PAM_FT_WIPE_BUTTONPRESS */
  /*  PAM_RR_TRLR_BUTTONPRESS */
  /*  CAR_GRAPHIC Condition 1 */
  /*  CAR_GRAPHIC Condition 2 */
  /*  CAR_GRAPHIC Condition 3 */
  /*  CAR_GRAPHIC Condition 4 */
  if (SWC_APA_B.MeAP_b_IDLE_HMI) {
    /*  TM0 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM0;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM4 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM4;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_Sys_Temp_NA_StartUp) {
    /*  TM2 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM2;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_RR_Temp_NA_StartUp) {
    /*  TM38 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM38;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Temp_NA_StartUp) {
    /*  TM39 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM39;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_Sys_FailStartUp) {
    /*  TM5 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM5;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (false) {
    /*  TM7 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM7;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM40 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM40;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_SpeedTooHigh) {
    /*  TM30 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM30;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_FT_Srv_RR_SrvStartUp) {
    /*  TM13 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM13;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Wipe_RR_SrvStartUp) {
    /*  TM22 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM22;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Srv_RR_WipeStartUp) {
    /*  TM24 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM24;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Srv_RR_TrlrStartUp) {
    /*  TM28 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM28;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Wipe_RR_WipeStartUp) {
    /*  TM20 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM20;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_Wipe_RR_TrlrStartUp) {
    /*  TM26 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM26;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_RR_SrvStartUp) {
    /*  TM8 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM8;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_SrvStartUp) {
    /*  TM11 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM11;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_RR_WipeStartUp) {
    /*  TM15 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM15;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_FT_WipeStartUp) {
    /*  TM18 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM18;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (SWC_APA_B.MeAP_b_RR_TrlrStartUp) {
    /*  TM35 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM35;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = true;
  } else if (false) {
    /*  TM10 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM10;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM12 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM12;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM17 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM17;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM19 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM19;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (false) {
    /*  TM37 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM37;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_CarGraphicCond1) {
    /*  TM1 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM1;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_CarGraphicCond2) {
    /*  TM1 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM1;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_CarGraphicCond3) {
    /*  TM1 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM1;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else if (SWC_APA_B.MeAP_b_CarGraphicCond4) {
    /*  TM1 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM1;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = true;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  } else {
    /*  Default */
    /*  TM0 */
    SWC_APA_B.MeAP_e_PAMPopUpReq = TeAP_e_PAMPopUpReq_TM0;
    SWC_APA_B.MeAP_b_BtnPrssPopUp = false;
    SWC_APA_B.MeAP_b_StrtUpPopUp_l = false;
  }

  /* End of Truth Table: '<S54>/PopUpPriority1' */

  /* UnitDelay: '<S244>/Unit Delay2' */
  SWC_APA_B.MeAP_e_PAMPopUpReqPrev = SWC_APA_DW.UnitDelay2_DSTATE_kd;

  /* UnitDelay: '<S260>/Unit Delay2' */
  SWC_APA_B.UnitDelay2_nd = SWC_APA_B.Switch3_fy;

  /* UnitDelay: '<S244>/Unit Delay3' */
  SWC_APA_B.MeAP_b_StrtUpPopUp = SWC_APA_DW.UnitDelay3_DSTATE_g;

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  UnitDelay: '<S244>/Unit Delay1'
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.UnitDelay1_DSTATE_b;

  /* Logic: '<S244>/Logical Operator1' */
  SWC_APA_B.MeAP_b_PopUpHold = (SWC_APA_B.RelationalOperator1_mc ||
    SWC_APA_B.MeAP_b_StrtUpPopUp);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S261>/Logical Operator8'
   *  Logic: '<S261>/Logical Operator9'
   *  UnitDelay: '<S261>/Unit Delay1'
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.UnitDelay1_DSTATE_pn;
  SWC_APA_B.RelationalOperator1_mc = !SWC_APA_B.RelationalOperator1_mc;
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_b_PopUpHold &&
    SWC_APA_B.RelationalOperator1_mc);

  /* Switch: '<S260>/Switch3' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    /* Switch: '<S257>/Switch' incorporates:
     *  Constant: '<S257>/Constant'
     */
    if (SWC_APA_B.MeAP_b_StrtUpPopUp) {
      SWC_APA_B.Switch_h = *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd;
    } else {
      SWC_APA_B.Switch_h = KeAP_cnt_BtnPressPopUpTimeThd;
    }

    /* End of Switch: '<S257>/Switch' */
    SWC_APA_B.Switch3_fy = SWC_APA_B.Switch_h;
  } else {
    /* RelationalOperator: '<S260>/Relational Operator' */
    SWC_APA_B.ElapseTimer_n = (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep <=
      SWC_APA_B.UnitDelay2_nd);

    /* RelationalOperator: '<S244>/Relational Operator' */
    SWC_APA_B.RelationalOperator_o = (SWC_APA_B.MeAP_e_PAMPopUpReq !=
      SWC_APA_B.MeAP_e_PAMPopUpReqPrev);

    /* RelationalOperator: '<S244>/Relational Operator2' incorporates:
     *  Constant: '<S258>/Constant'
     */
    SWC_APA_B.RelationalOperator2_ae = (SWC_APA_B.MeAP_e_PAMPopUpReq !=
      TeAP_e_PAMPopUpReq_TM1);

    /* RelationalOperator: '<S244>/Relational Operator1' incorporates:
     *  Constant: '<S259>/Constant'
     */
    SWC_APA_B.LogicalOperator1_is = (TeAP_e_PAMPopUpReq_TM0 !=
      SWC_APA_B.MeAP_e_PAMPopUpReq);

    /* Logic: '<S244>/Logical Operator' */
    SWC_APA_B.LogicalOperator1_is = (SWC_APA_B.LogicalOperator1_is &&
      SWC_APA_B.RelationalOperator2_ae && SWC_APA_B.RelationalOperator_o);

    /* Logic: '<S260>/Logical Operator1' */
    SWC_APA_B.LogicalOperator1_is = !SWC_APA_B.LogicalOperator1_is;

    /* Logic: '<S260>/Logical Operator3' */
    SWC_APA_B.ElapseTimer_n = (SWC_APA_B.ElapseTimer_n &&
      SWC_APA_B.LogicalOperator1_is);

    /* Switch: '<S260>/Switch1' incorporates:
     *  Constant: '<S260>/Constant'
     */
    if (SWC_APA_B.ElapseTimer_n) {
      /* Sum: '<S260>/Subtract' */
      SWC_APA_B.Subtract_pa = (uint16_T)(SWC_APA_B.UnitDelay2_nd -
        *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep);
      SWC_APA_B.Switch1_iu = SWC_APA_B.Subtract_pa;
    } else {
      SWC_APA_B.Switch1_iu = ((uint16_T)0U);
    }

    /* End of Switch: '<S260>/Switch1' */
    SWC_APA_B.Switch3_fy = SWC_APA_B.Switch1_iu;
  }

  /* End of Switch: '<S260>/Switch3' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S260>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc =
    (*rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep > SWC_APA_B.Switch3_fy);

  /* Logic: '<S260>/Logical Operator4' */
  SWC_APA_B.IsTimerRunning = !SWC_APA_B.RelationalOperator1_mc;

  /* Switch: '<S244>/Switch3' */
  if (SWC_APA_B.RelationalOperator1_mc) {
    *rty_MeAP_e_PAMPopUpReq = SWC_APA_B.MeAP_e_PAMPopUpReq;
  } else {
    *rty_MeAP_e_PAMPopUpReq = SWC_APA_B.MeAP_e_PAMPopUpReqPrev;
  }

  /* End of Switch: '<S244>/Switch3' */

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  RelationalOperator: '<S310>/FixPt Relational Operator'
   *  UnitDelay: '<S310>/Delay Input1'
   *
   * Block description for '<S310>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SWC_APA_B.RelationalOperator1_mc = SWC_APA_DW.DelayInput1_DSTATE_p;
  SWC_APA_B.RelationalOperator1_mc = ((int32_T)
    SWC_APA_B.MeAP_b_RearSwitchPressed > (int32_T)
    SWC_APA_B.RelationalOperator1_mc);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S311>/Constant'
   *  RelationalOperator: '<S275>/Relational Operator1'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S275>/Relational Operator9' incorporates:
   *  Constant: '<S319>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF);

  /* RelationalOperator: '<S275>/Relational Operator2' incorporates:
   *  Constant: '<S313>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S275>/Logical Operator6' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    SWC_APA_B.RelationalOperator8_er);

  /* RelationalOperator: '<S275>/Relational Operator10' incorporates:
   *  Constant: '<S312>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S275>/Relational Operator8' incorporates:
   *  Constant: '<S318>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S275>/Logical Operator5' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* RelationalOperator: '<S275>/Relational Operator6' incorporates:
   *  Constant: '<S315>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S275>/Relational Operator5' incorporates:
   *  Constant: '<S314>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Parking);

  /* RelationalOperator: '<S275>/Relational Operator7' incorporates:
   *  Constant: '<S317>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Neutral);

  /* RelationalOperator: '<S275>/Relational Operator4' incorporates:
   *  Constant: '<S316>/Constant'
   */
  SWC_APA_B.RelationalOperator7 = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Drive);

  /* Logic: '<S275>/Logical Operator2' incorporates:
   *  Logic: '<S274>/Logical Operator2'
   *  Logic: '<S276>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator8_e = !SWC_APA_B.RelationalOperator1_e1;

  /* Logic: '<S275>/Logical Operator3' */
  SWC_APA_B.RelationalOperator7 = (SWC_APA_B.RelationalOperator7 &&
    SWC_APA_B.RelationalOperator8_e);

  /* Logic: '<S275>/Logical Operator4' */
  SWC_APA_B.RelationalOperator2_j = (SWC_APA_B.RelationalOperator2_j ||
    SWC_APA_B.Compare_k || SWC_APA_B.RelationalOperator7);

  /* Logic: '<S275>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_TrlrBtnPress = (SWC_APA_B.LogicalOperator2_n &&
    SWC_APA_B.RelationalOperator4_m && SWC_APA_B.RelationalOperator8_er &&
    SWC_APA_B.RelationalOperator6_p && SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.RelationalOperator2_j);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Logic: '<S277>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator1_mc = (SWC_APA_B.MeAP_b_FrontSwitchPressed ||
    SWC_APA_B.MeAP_b_RearSwitchPressed);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S330>/Constant'
   *  RelationalOperator: '<S277>/Relational Operator1'
   */
  SWC_APA_B.LogicalOperator2_n = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* RelationalOperator: '<S277>/Relational Operator11' incorporates:
   *  Constant: '<S332>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* RelationalOperator: '<S277>/Relational Operator12' incorporates:
   *  Constant: '<S331>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S277>/Logical Operator6' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m ||
    SWC_APA_B.RelationalOperator8_er);

  /* RelationalOperator: '<S277>/Relational Operator4' incorporates:
   *  Constant: '<S333>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear
    != TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S277>/Relational Operator6' incorporates:
   *  Constant: '<S334>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_ExternalFailure);

  /* Logic: '<S277>/Logical Operator1' */
  SWC_APA_B.MeAP_b_Sys_Temp_NA_BtnPress = (SWC_APA_B.LogicalOperator2_n &&
    SWC_APA_B.RelationalOperator4_m && SWC_APA_B.RelationalOperator8_er &&
    SWC_APA_B.RelationalOperator6_p && SWC_APA_B.RelationalOperator1_mc);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S295>/Constant'
   *  RelationalOperator: '<S273>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S297>/Constant'
   *  RelationalOperator: '<S273>/Relational Operator11'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S273>/Relational Operator12' incorporates:
   *  Constant: '<S296>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S273>/Logical Operator6'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S273>/Relational Operator4' incorporates:
   *  Constant: '<S298>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear
    != TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S273>/Relational Operator6' incorporates:
   *  Constant: '<S299>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* Logic: '<S273>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_FailBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.MeAP_b_RearSwitchPressed);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S300>/Constant'
   *  RelationalOperator: '<S274>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S302>/Constant'
   *  RelationalOperator: '<S274>/Relational Operator11'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S274>/Relational Operator12' incorporates:
   *  Constant: '<S301>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S274>/Logical Operator6'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* Logic: '<S274>/Logical Operator8' */
  SWC_APA_B.RelationalOperator4_m = !SWC_APA_B.LogicalOperator2_n;

  /* RelationalOperator: '<S274>/Relational Operator10' incorporates:
   *  Constant: '<S303>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S274>/Relational Operator2' incorporates:
   *  Constant: '<S304>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S274>/Logical Operator5' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S274>/Logical Operator7' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S274>/Logical Operator9'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S274>/Relational Operator8' incorporates:
   *  Constant: '<S309>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S274>/Relational Operator6' incorporates:
   *  Constant: '<S306>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S274>/Relational Operator5' incorporates:
   *  Constant: '<S305>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Parking);

  /* RelationalOperator: '<S274>/Relational Operator7' incorporates:
   *  Constant: '<S308>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Neutral);

  /* RelationalOperator: '<S274>/Relational Operator4' incorporates:
   *  Constant: '<S307>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Drive);

  /* Logic: '<S274>/Logical Operator2' */
  SWC_APA_B.RelationalOperator7 = SWC_APA_B.RelationalOperator8_e;

  /* Logic: '<S274>/Logical Operator3' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator7);

  /* Logic: '<S274>/Logical Operator4' */
  SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.RelationalOperator6_p ||
    SWC_APA_B.RelationalOperator2_j || SWC_APA_B.Compare_k);

  /* Logic: '<S274>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_SrvBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.MeAP_b_RearSwitchPressed &&
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S320>/Constant'
   *  RelationalOperator: '<S276>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S322>/Constant'
   *  RelationalOperator: '<S276>/Relational Operator11'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S276>/Relational Operator12' incorporates:
   *  Constant: '<S321>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S276>/Logical Operator6'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* Logic: '<S276>/Logical Operator8' */
  SWC_APA_B.RelationalOperator4_m = !SWC_APA_B.LogicalOperator2_n;

  /* RelationalOperator: '<S276>/Relational Operator10' incorporates:
   *  Constant: '<S323>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er =
    (*rtu_IbVBIA_VehState_IeVBII_e_TrailerConnectionSts ==
     TeVBII_e_TrailerConnectionSts_Connected);

  /* RelationalOperator: '<S276>/Relational Operator2' incorporates:
   *  Constant: '<S324>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_IeVBII_e_TrlrPrsntSts ==
    TeVBII_e_TrlrPrsntSts_TRLR_PRSNT);

  /* Logic: '<S276>/Logical Operator5' */
  SWC_APA_B.RelationalOperator8_er = (SWC_APA_B.RelationalOperator8_er ||
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S276>/Logical Operator7' */
  SWC_APA_B.RelationalOperator4_m = (SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S276>/Logical Operator9'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S276>/Relational Operator8' incorporates:
   *  Constant: '<S329>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_IeAP_e_RearSnsrStatus ==
    TeAP_e_RearSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S276>/Relational Operator6' incorporates:
   *  Constant: '<S326>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* RelationalOperator: '<S276>/Relational Operator5' incorporates:
   *  Constant: '<S325>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Parking);

  /* RelationalOperator: '<S276>/Relational Operator7' incorporates:
   *  Constant: '<S328>/Constant'
   */
  SWC_APA_B.RelationalOperator2_j = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Neutral);

  /* RelationalOperator: '<S276>/Relational Operator4' incorporates:
   *  Constant: '<S327>/Constant'
   */
  SWC_APA_B.Compare_k = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear ==
    TeAP_e_FiltdGearState_Drive);

  /* Logic: '<S50>/Logical Operator' incorporates:
   *  Logic: '<S276>/Logical Operator2'
   */
  SWC_APA_B.RelationalOperator1_e1 = SWC_APA_B.RelationalOperator8_e;

  /* Logic: '<S276>/Logical Operator3' */
  SWC_APA_B.Compare_k = (SWC_APA_B.Compare_k && SWC_APA_B.RelationalOperator1_e1);

  /* Logic: '<S276>/Logical Operator4' */
  SWC_APA_B.RelationalOperator6_p = (SWC_APA_B.RelationalOperator6_p ||
    SWC_APA_B.RelationalOperator2_j || SWC_APA_B.Compare_k);

  /* Logic: '<S276>/Logical Operator1' */
  SWC_APA_B.MeAP_b_RR_WipeBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.MeAP_b_RearSwitchPressed &&
    SWC_APA_B.RelationalOperator6_p);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S278>/Constant'
   *  RelationalOperator: '<S270>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S281>/Constant'
   *  RelationalOperator: '<S270>/Relational Operator5'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S270>/Relational Operator7' incorporates:
   *  Constant: '<S282>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S270>/Logical Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S270>/Relational Operator4' incorporates:
   *  Constant: '<S279>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear
    != TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S270>/Relational Operator6' incorporates:
   *  Constant: '<S280>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_SystemFailure);

  /* Logic: '<S270>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_FailBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S283>/Constant'
   *  RelationalOperator: '<S271>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S286>/Constant'
   *  RelationalOperator: '<S271>/Relational Operator5'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S271>/Relational Operator7' incorporates:
   *  Constant: '<S287>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S271>/Logical Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S271>/Relational Operator4' incorporates:
   *  Constant: '<S284>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear
    != TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S271>/Relational Operator8' incorporates:
   *  Constant: '<S288>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Failure);

  /* RelationalOperator: '<S271>/Relational Operator6' incorporates:
   *  Constant: '<S285>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* Logic: '<S271>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_SrvBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.RelationalOperator6_p &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* Logic: '<S53>/Logical Operator4' incorporates:
   *  Constant: '<S289>/Constant'
   *  RelationalOperator: '<S272>/Relational Operator1'
   */
  SWC_APA_B.RelationalOperator1_mc = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Constant: '<S292>/Constant'
   *  RelationalOperator: '<S272>/Relational Operator5'
   */
  SWC_APA_B.LogicalOperator2_n = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON);

  /* RelationalOperator: '<S272>/Relational Operator7' incorporates:
   *  Constant: '<S293>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rty_MeAP_e_PAMOffStatus2BT ==
    TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF);

  /* Logic: '<S376>/Logical Operator3' incorporates:
   *  Logic: '<S272>/Logical Operator2'
   */
  SWC_APA_B.LogicalOperator2_n = (SWC_APA_B.LogicalOperator2_n ||
    SWC_APA_B.RelationalOperator4_m);

  /* RelationalOperator: '<S272>/Relational Operator4' incorporates:
   *  Constant: '<S290>/Constant'
   */
  SWC_APA_B.RelationalOperator4_m = (*rtu_IbVBIA_VehState_MeAP_e_FiltdTrgtGear
    != TeAP_e_FiltdGearState_ReverseGear);

  /* RelationalOperator: '<S272>/Relational Operator8' incorporates:
   *  Constant: '<S294>/Constant'
   */
  SWC_APA_B.RelationalOperator8_er = (*rty_IeAP_e_FrntSnsrStatus ==
    TeAP_e_FrntSnsrStatus_NotActive_Blocked);

  /* RelationalOperator: '<S272>/Relational Operator6' incorporates:
   *  Constant: '<S291>/Constant'
   */
  SWC_APA_B.RelationalOperator6_p = (*rty_IeAP_e_PAMSystemFault ==
    TeAP_e_PAMSystemFault_False);

  /* Logic: '<S272>/Logical Operator1' */
  SWC_APA_B.MeAP_b_FT_WipeBtnPress = (SWC_APA_B.RelationalOperator1_mc &&
    SWC_APA_B.LogicalOperator2_n && SWC_APA_B.RelationalOperator4_m &&
    SWC_APA_B.RelationalOperator8_er && SWC_APA_B.RelationalOperator6_p &&
    SWC_APA_B.MeAP_b_FrontSwitchPressed);

  /* RelationalOperator: '<S54>/Relational Operator' incorporates:
   *  Constant: '<S242>/Constant'
   */
  SWC_APA_B.RelationalOperator_d = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_START);

  /* RelationalOperator: '<S262>/Relational Operator' incorporates:
   *  Constant: '<S267>/Constant'
   */
  SWC_APA_B.RelationalOperator_m = (*rtu_MeTHA_e_RearBrkSupprInfo ==
    TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking);

  /* Update for UnitDelay: '<S468>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_ko = SWC_APA_B.VehKeyDetected;

  /* Update for UnitDelay: '<S464>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_jm = MeAP_b_FPASwtStatus;

  /* Update for UnitDelay: '<S466>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_oc = MeAP_b_RPASwtStatus;

  /* Update for UnitDelay: '<S244>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_kd = *rty_MeAP_e_PAMPopUpReq;

  /* Update for UnitDelay: '<S244>/Unit Delay3' */
  SWC_APA_DW.UnitDelay3_DSTATE_g = SWC_APA_B.MeAP_b_StrtUpPopUp_l;

  /* Update for UnitDelay: '<S244>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_b = SWC_APA_B.MeAP_b_BtnPrssPopUp;

  /* Update for UnitDelay: '<S261>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE_pn = SWC_APA_B.MeAP_b_PopUpHold;

  /* Update for UnitDelay: '<S310>/Delay Input1'
   *
   * Block description for '<S310>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SWC_APA_DW.DelayInput1_DSTATE_p = SWC_APA_B.MeAP_b_RearSwitchPressed;

  /* End of Outputs for SubSystem: '<S6>/PAMPopUpReq_Gen' */

  /* Outputs for Atomic SubSystem: '<S6>/RPAwithBrk' */
  SWC_APA_RPAwithBrk();

  /* End of Outputs for SubSystem: '<S6>/RPAwithBrk' */

  /* Update for UnitDelay: '<S58>/Unit Delay' incorporates:
   *  Constant: '<S58>/Constant'
   */
  SWC_APA_DW.UnitDelay_DSTATE_k = false;

  /* Update for UnitDelay: '<S58>/Unit Delay1' */
  SWC_APA_DW.UnitDelay1_DSTATE = *rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts;

  /* Update for UnitDelay: '<S58>/Unit Delay2' */
  SWC_APA_DW.UnitDelay2_DSTATE_l = SWC_APA_B.MeAP_b_TrlrNotConnected;

  /* End of Outputs for SubSystem: '<S2>/Rear_Front_ParkAssist' */

  /* DataTypeConversion: '<S2>/Data Type Conversion' */
  SWC_APA_B.DataTypeConversion = (uint32_T)SWC_APA_B.MeAP_e_FeatStsBeforeTrlr_h;

  /* DataTypeConversion: '<S2>/Data Type Conversion1' */
  *rty_IeAutoPark_e_ScanDir = (TeAutoPark_e_ScanDir)SWC_APA_B.DataTypeConversion;

  /* SignalConversion generated from: '<Root>/MeAP_b_FPADisable' */
  *rty_MeAP_b_FPADisable = *rtu_IbFID_PA_MeAP_b_FPADisable;

  /* SignalConversion generated from: '<Root>/MeAP_b_RPADisable' */
  *rty_MeAP_b_RPADisable = *rtu_IbFID_PA_MeAP_b_RPADisable;

  /* RelationalOperator: '<S9>/Relational Operator1' incorporates:
   *  Constant: '<S9>/ENS_RQ_ST'
   */
  SWC_APA_B.LogicalOperator1_d = (*rtu_IbVBIA_VehState_IeVBII_e_EssEngState ==
    TeVBII_e_EssEngState_ENS_RQ_ST);

  /* RelationalOperator: '<S9>/Relational Operator2' incorporates:
   *  Constant: '<S9>/ENS_Starting'
   */
  SWC_APA_B.RelationalOperator_jv = (*rtu_IbVBIA_VehState_IeVBII_e_EssEngState ==
    TeVBII_e_EssEngState_ENS_Starting);

  /* Logic: '<S9>/Logical Operator1' */
  SWC_APA_B.LogicalOperator1_d = (SWC_APA_B.LogicalOperator1_d ||
    SWC_APA_B.RelationalOperator_jv);

  /* RelationalOperator: '<S9>/Relational Operator' incorporates:
   *  Constant: '<S9>/IGN_RUN'
   */
  SWC_APA_B.RelationalOperator_jv = (*rtu_IbVBIA_VehState_IeVBII_e_CmdIgnSts ==
    TeVBII_e_CmdIgnSts_RUN);

  /* Logic: '<S9>/Logical Operator' */
  SWC_APA_B.MeAP_b_DisableDiag = (SWC_APA_B.RelationalOperator_jv &&
    SWC_APA_B.LogicalOperator1_d && (*rtu_MbNVM_ProxyParam_KeAP_b_StopAndStrt));

  /* SignalConversion generated from: '<Root>/MeAP_b_RPAwithBrkDisable' */
  *rty_MeAP_b_RPAwithBrkDisable = *rtu_IbFID_PARB_MeAP_b_PARBDiable;

  /* SignalConversion generated from: '<Root>/MeAP_b_SystemFail' */
  *rty_MeAP_b_SystemFail = *rtu_IbFID_PA_MeAP_b_SystemFail;

  /* Update for UnitDelay: '<S7>/Unit Delay' incorporates:
   *  Constant: '<S7>/Constant'
   */
  SWC_APA_DW.UnitDelay_DSTATE_e = false;
}

/* Model initialize function */
void SWC_APA_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_SWC_APA_T *const SWC_APA_M = &(SWC_APA_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(SWC_APA_M, rt_errorStatus);

  /* block I/O */
  {
    SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_0_BusCreator1
      = SWC_APA_rtZTbVBIA_VehState_AP;
    SWC_APA_B.BusConversion_InsertedFor_Rear_ObjectDetection_at_inport_127_BusCreator1
      = SWC_APA_rtZTbNVM_ProxyCalibParam;
    SWC_APA_B.UnitDelay_p = TeVBII_e_PamChimeVol_Medium;
    SWC_APA_B.UnitDelay_k = TeVBII_e_PamChimeVol_Medium;
    SWC_APA_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicRHR_b = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicLHR_i = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR_h = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR_j = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR_f = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR_p = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHR_l = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicLHF = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicRHF_i = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicLHF_j = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHF_a = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHF_l = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.MeAP_e_GraphicCHF_i = TeAP_e_GraphicFlshRate_None;
    SWC_APA_B.UnitDelay1_nu = TeAP_e_FiltdGearState_SNA;
  }

  /* Model Initialize function for ModelReference Block: '<S57>/Rear_ObjectDetection' */
  Rear_ObjectDection_initialize(rtmGetErrorStatusPointer(SWC_APA_M));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
