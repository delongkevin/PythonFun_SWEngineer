/*
 * File: DT24_CVADAS_AP_CodGen.c
 *
 * Code generated for Simulink model 'DT24_CVADAS_AP_CodGen'.
 *
 * Model version                  : 1.1280
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:15:18 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#include "DT24_CVADAS_AP_CodGen.h"
#include "DT24_CVADAS_AP_CodGen_private.h"
#include "LookUp_real_TU8_real32_T.h"
#include "div_s16s32.h"
#include "mul_s32_sat.h"
#include "uLong2MultiWord.h"
#include "uMultiWordMul.h"
#include "UART_stdio.h"
#include "SWC_VC.h"

/* Named constants for Chart: '<S46>/FIL_Blk' */
#define DT24_CVADAS_AP_CodGen_IN_BlockDetect2 ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlocked1 ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1 ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1 ((uint8_T)4U)

/* Named constants for Chart: '<S46>/FSL_Blk' */
#define DT24_CVADAS_AP_CodGen_IN_BlockDetect2_d ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_h ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_i ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_i ((uint8_T)4U)

/* Named constants for Chart: '<S46>/RIL_Blk' */
#define DT24_CVADAS_AP_CodGen_IN_BlockDetect2_b ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_l ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_b ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_is ((uint8_T)4U)

/* Named constants for Chart: '<S46>/RSL_Blk' */
#define DT24_CVADAS_AP_CodGen_IN_BlockDetect2_g ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_a ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_g ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_c ((uint8_T)4U)

/* Named constants for Chart: '<S42>/Chart1' */
#define DT24_CVADAS_AP_CodGen_IN_BlockageDetected ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_Default ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_Default_c ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_DetectBlockage ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c ((uint8_T)0U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockageReset ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold ((uint8_T)4U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc2 ((uint8_T)5U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc2_2 ((uint8_T)6U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc3 ((uint8_T)7U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc3_2 ((uint8_T)8U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc4 ((uint8_T)9U)
#define DT24_CVADAS_AP_CodGen_IN_TransitionToArc4_2 ((uint8_T)10U)

/* Named constants for Chart: '<S46>/FLAlertCount' */
#define DT24_CVADAS_AP_CodGen_IN_Alert1 ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_Alert2 ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_NoObjectDetected ((uint8_T)3U)

/* Named constants for Chart: '<S46>/FrontAlertCount' */
#define DT24_CVADAS_AP_CodGen_IN_Alert3 ((uint8_T)3U)
#define DT24_CVADAS_AP_CodGen_IN_Alert4 ((uint8_T)4U)
#define DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e ((uint8_T)5U)

/* Named constants for Chart: '<S46>/RearAlertCount' */
#define DT24_CVADAS_AP_CodGen_IN_Alert5 ((uint8_T)5U)
#define DT24_CVADAS_AP_CodGen_IN_Alert6 ((uint8_T)6U)
#define DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a ((uint8_T)7U)

/* Named constants for Chart: '<S112>/DistDbnc' */
#define DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED ((uint8_T)2U)
#define DT24_CVADAS_AP_CodGen_IN_RESET_DBNC ((uint8_T)1U)
#define DT24_CVADAS_AP_CodGen_IN_SET_DBNC ((uint8_T)2U)

const TbVBIA_VehState_AP DT24_CVADAS_AP_CodGen_rtZTbVBIA_VehState_AP = {
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

const TbNVM_ProxyCalibParam DT24_CVADAS_AP_CodGen_rtZTbNVM_ProxyCalibParam = {
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

const TbHMI_HMIInfoToAP DT24_CVADAS_AP_CodGen_rtZTbHMI_HMIInfoToAP = {
  false,                               /* IeHMI_b_UsrSlotSelStatus */
  TeAutoPark_e_ParkStyle_Rear_In,      /* IeHMI_e_ParkStyle */
  TeHMI_e_UsrParkOutSide_None,         /* IeHMI_e_UsrParkOutSideSel */
  false,                               /* IeHMI_b_HMIHandshake */
  false,                               /* IeHMI_b_BackBtnPsd */
  TeAP_e_UsrPPPAManeuverSel_None,      /* IeHMI_e_UsrPPPAManeuverSel */
  ParkingSlotType_E_PW_NODIR,          /* IeHMI_e_SelectedMnvSlotType */
  SlotSide_E_SLOT_NULL,                /* IeHMI_e_SelectedMnvSlotSide */
  ParkingSlotID_E_NONE,                /* IeHMI_e_SelectedSlotId */

  { { 0UL, 0UL } }                     /* IeHMI_cnt_FressnessCounter */
} ;                                    /* TbHMI_HMIInfoToAP ground */

const TbAP_FPAWarnOut_t DT24_CVADAS_AP_CodGen_rtZTbAP_FPAWarnOut_t = {
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcCHF */
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcLHF */
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcRHF */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateLHF */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateRHF */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateCHF */
  false,                               /* IeAP_b_ChimeActvReqLHF */
  false                                /* IeAP_b_ChimeActvReqRHF */
} ;                                    /* TbAP_FPAWarnOut_t ground */

const TbAP_RPAWarnOut_t DT24_CVADAS_AP_CodGen_rtZTbAP_RPAWarnOut_t = {
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcCHR */
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcLHR */
  TeAP_e_Alert_NoObjectDetected,       /* IeAP_e_DispArcRHR */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateCHR */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateLHR */
  TeAP_e_GraphicFlshRate_None,         /* IeAP_e_ArcFlashRateRHR */
  0U,                                  /* IeAP_cm_RearDisttoNearObst */
  false,                               /* IeAP_b_ChimeActvReqLHR */
  false                                /* IeAP_b_ChimeActvReqRHR */
} ;                                    /* TbAP_RPAWarnOut_t ground */

const HMIInfoToAP_t DT24_CVADAS_AP_CodGen_rtZHMIInfoToAP_t = {
  TeAP_e_HMIPopUp_IDLE,                /* DisplayedPopUp */
  AbortSftBtnSelected,                 /* HmiAbort_Type */
  NONE_PRESSED,                        /* HMI_ButtonPressed */
  TYPE_NONE,                           /* SelectedManeuverType */
  ParkingSlotType_E_PW_NODIR,          /* SelectedManeuverSlotType */
  SlotSide_E_SLOT_NULL,                /* SelectedManeuverSlotSide */
  ParkingSlotID_E_NONE,                /* SelectedSlotId */
  0U                                   /* FressnessCounter */
} ;                                    /* HMIInfoToAP_t ground */

/* Exported data definition */
volatile uint8_t v_Enable_Tgt_Dist_Saturation_u8 = 1u;//keep
/* Definition for custom storage class: Default */
TbAP_APSMPAOut_t APSMPAOut;            /* '<S208>/Bus Creator1' */
real32_T CONST_DPS2RPS = 0.01745F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* conversion parameter from degree/s to rad/s */
uint16_T CeAP_ms_SampleTime = 30U;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S112>/DistDbnc'
                                        * '<S113>/DistDbnc'
                                        * '<S114>/DistDbnc'
                                        * '<S133>/DistDbnc'
                                        * '<S134>/DistDbnc'
                                        * '<S135>/DistDbnc'
                                        */
real32_T DS_ANGLE;                     /* '<S12>/Data Type Conversion269' */
real32_T DS_WheelSpeed_RL;             /* '<S23>/Data Type Conversion32' */
real32_T DS_WheelSpeed_RR;             /* '<S23>/Data Type Conversion38' */
TbAP_DriveAssistStatOut_t DriveAssistStatOut;/* '<S208>/Bus Creator2' */
TbAP_FPAWarnOut_t FPAWarnOut;          /* '<S209>/Bus Creator1' */
TbAP_InputVrntTunParam_t IbAP_InputVrntTunParam;/* '<S25>/Switch' */
boolean_T IeAP_b_DisForceNoiseMode;    /* '<S19>/Logical Operator1' */
boolean_T IeHMI_b_BackBtnPsd;          /* '<S11>/Relational Operator2' */
boolean_T IeHMI_b_HMIHandshake;        /* '<S11>/Logical Operator2' */
boolean_T IeHMI_b_UsrSlotSelStatus;    /* '<S11>/Relational Operator8' */
TeAutoPark_e_ParkStyle IeHMI_e_ParkStyle;/* '<S11>/Switch' */
TeAP_e_UsrPPPAManeuverSel IeHMI_e_UsrPPPAManeuverSel;/* '<S11>/Switch4' */
TeHMI_e_UsrParkOutSide IeHMI_e_UsrParkOutSideSel;/* '<S11>/Switch2' */
real32_T K_Overlap_Thrsld_RAEB[5] = { 0.05F, 0.1F, 0.15F, 0.2F, 0.25F } ;
                              /* Referenced by: '<S25>/K_Overlap_Thrsld_RAEB' */

real32_T K_e_RAEB_DrawingTubeOffset = 0.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
real32_T K_e_RAEB_VehicleWidth = 2.06F;/* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/K_e_RAEB_VehicleWidth'
                                        */

/* To feed mobileye obj type into AdCam instead of hard coded value */
real32_T K_e_RAEB_WarnOffset = 0.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* To feed lateral offset to issue warning */
uint16_T KeAP_Cnt_GearFiltTimeThd = 40U;/* Referenced by:
                                         * '<S25>/KeAP_Cnt_GearFiltTimeThd'
                                         * '<S183>/Constant1'
                                         * '<S183>/Constant3'
                                         */

/* Gear Filtering time threshold 400ms */
uint16_T KeAP_Cnt_GearOverrideTimeThd = 500U;/* Referenced by:
                                              * '<Root>/CVADAS_AutoPark_Main'
                                              * '<S25>/KeAP_Cnt_GearOverrideTimeThd'
                                              */

/* Gear override time threshold */
real32_T KeAP_M_StrTrqValLimit = 5.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
boolean_T KeAP_b_AutoParkEn = 1;  /* Referenced by: '<S25>/KeAP_b_AutoParkEn' */

/* Ego vehicle shall be equipped with Auto Park Assist feature */
boolean_T KeAP_b_CruisAgeBasedGhsObjDet = 1;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
boolean_T KeAP_b_DbncEnabld = 0;       /* Referenced by:
                                        * '<S112>/Constant2'
                                        * '<S113>/Constant2'
                                        * '<S114>/Constant2'
                                        * '<S133>/Constant2'
                                        * '<S134>/Constant2'
                                        * '<S135>/Constant2'
                                        */
boolean_T KeAP_b_DensityBasedGhstObjDet = 0;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
boolean_T KeAP_b_DevlopmentTest = 0;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S6>/Constant'
                                        * '<S9>/Constant'
                                        * '<S25>/Constant'
                                        * '<S25>/Constant1'
                                        * '<S25>/Constant2'
                                        * '<S25>/Constant3'
                                        */

/* Test Parameter used to change value of Tunable parameter while Testing */
boolean_T KeAP_b_EnFeatForceNoiseMode = 0;/* Referenced by: '<S19>/Constant' */
boolean_T KeAP_b_EnVehStandstillArcBlip = 1;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
boolean_T KeAP_b_EnWallAcurracy = 1;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
boolean_T KeAP_b_FPAEn = 1;            /* Referenced by: '<S25>/KeAP_b_FPAEn' */

/* Ego vehicle shall be equipped with Front Park Assist feature */
uint8_T KeAP_b_FeatDetectWall = 1U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
boolean_T KeAP_b_ForceEnArcTrack = 1;  /* Referenced by:
                                        * '<S88>/CalculateMinDistances1'
                                        * '<S100>/Constant5'
                                        */
boolean_T KeAP_b_FullAutoPark = 1;
                                /* Referenced by: '<S25>/KeAP_b_FullAutoPark' */

/* Ego vehicle shall be equipped with Fully Auto Park Assist feature */
boolean_T KeAP_b_HeightFlagEnabled = 1;/* Referenced by:
                                        * '<S92>/FC_Dbnc'
                                        * '<S92>/FC_Dbnc1'
                                        * '<S92>/FC_Dbnc2'
                                        * '<S93>/RC_Dbnc'
                                        * '<S93>/RC_Dbnc1'
                                        * '<S93>/RC_Dbnc2'
                                        */
boolean_T KeAP_b_HookConnected = 0;    /* Referenced by:
                                        * '<S25>/KeAP_b_HookConnected'
                                        * '<S93>/Constant2'
                                        * '<S93>/Constant5'
                                        * '<S93>/Constant8'
                                        */

/* Hook Connected 0= Not Connected 1=Connected */
boolean_T KeAP_b_RPAwithBrk = 1;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_b_RPAwithBrk'
                                        */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake */
boolean_T KeAP_b_RPAwithSurroundView = 1;
                         /* Referenced by: '<S25>/KeAP_b_RPAwithSurroundView' */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake and Surround View Interaction */
boolean_T KeAP_b_RearDistCorrBasedVehSpd = 1;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
boolean_T KeAP_b_SteerOnlyAutoPark = 1;
                           /* Referenced by: '<S25>/KeAP_b_SteerOnlyAutoPark' */

/* Ego vehicle shall be equipped with Steer only Auto Park Assist feature */
boolean_T KeAP_b_SuppArcInNoForceNoise = 1;/* Referenced by:
                                            * '<S155>/Constant'
                                            * '<S156>/Constant'
                                            * '<S157>/Constant'
                                            * '<S158>/Constant'
                                            * '<S159>/Constant'
                                            * '<S160>/Constant'
                                            * '<S161>/Constant'
                                            * '<S162>/Constant'
                                            */
uint8_T KeAP_b_SupprsUssGlblHght = 0U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
boolean_T KeAP_b_SwitchOldAlgo = 0;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
int16_T KeAP_cm_CenterWarnLatThreshold = 62;/* Referenced by: '<S88>/Constant2' */

/* Parameter to decide center region */
int16_T KeAP_cm_DistZone1 = 55;        /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone1'
                                        * '<S25>/KeAP_cm_DistZone8'
                                        */

/* Warning Zone 1 Dist */
int16_T KeAP_cm_DistZone2 = 95;        /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone2'
                                        * '<S25>/KeAP_cm_DistZone9'
                                        * '<S88>/CalculateMinDistances1'
                                        * '<S93>/RC_Dbnc1'
                                        * '<S93>/RC_Dbnc2'
                                        * '<S100>/Constant3'
                                        */

/* Warning Zone 2 Dist */
int16_T KeAP_cm_DistZone3 = 125;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone10'
                                        * '<S25>/KeAP_cm_DistZone3'
                                        */

/* Warning Zone 3 Dist */
int16_T KeAP_cm_DistZone4 = 150;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone11'
                                        * '<S25>/KeAP_cm_DistZone4'
                                        * '<S88>/CalculateMinDistances1'
                                        */

/* Warning Zone 4 Dist */
int16_T KeAP_cm_DistZone5 = 180;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone12'
                                        * '<S25>/KeAP_cm_DistZone5'
                                        */

/* Warning Zone 5 Dist */
int16_T KeAP_cm_DistZone6 = 220;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone13'
                                        * '<S25>/KeAP_cm_DistZone6'
                                        * '<S88>/CalculateMinDistances1'
                                        * '<S93>/RC_Dbnc'
                                        */

/* Warning Zone 6 Dist */
int16_T KeAP_cm_FrntDistArcComp = 7;   /* Referenced by:
                                        * '<S115>/Constant1'
                                        * '<S115>/Constant2'
                                        * '<S118>/Constant1'
                                        * '<S118>/Constant2'
                                        * '<S121>/Constant1'
                                        * '<S121>/Constant2'
                                        * '<S124>/Constant1'
                                        * '<S124>/Constant2'
                                        */

/* Warning Zone 6 Dist */
int16_T KeAP_cm_FrntDistZone1 = 65;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 1 Dist */
int16_T KeAP_cm_FrntDistZone2 = 100;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S92>/FC_Dbnc1'
                                        * '<S92>/FC_Dbnc2'
                                        */

/* Warning Zone 2 Dist */
int16_T KeAP_cm_FrntDistZone3 = 135;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 3 Dist */
int16_T KeAP_cm_FrntDistZone4 = 155;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S92>/FC_Dbnc'
                                        */

/* Warning Zone 4 Dist */
int16_T KeAP_cm_FrntDistZone5 = 185;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 5 Dist */
int16_T KeAP_cm_FrntDistZone6 = 235;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 6 Dist */
int16_T KeAP_cm_FrntLongDistAdj = 450;
                            /* Referenced by: '<S25>/KeAP_cm_FrntLongDistAdj' */

/* Longitudanl Distance from Rear Axle to Front edge of vehicle */
real32_T KeAP_cm_FrntWallZone1Adj = 10.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
int16_T KeAP_cm_HalfVehicleWidth = 103;
                           /* Referenced by: '<S25>/KeAP_cm_HalfVehicleWidth' */

/* Ego Vehicle Car Half Width */
int16_T KeAP_cm_HookDistOffset = 18;   /* Referenced by:
                                        * '<S25>/KeAP_cm_HookDistOffset'
                                        * '<S93>/Constant4'
                                        * '<S93>/Constant6'
                                        * '<S93>/Constant9'
                                        */

/* Length of Permanant Hook attached at back side of Ego */
int16_T KeAP_cm_MaxNoObjDetctDist = 1000;
                          /* Referenced by: '<S25>/KeAP_cm_MaxNoObjDetctDist' */

/* Max distance when no object detected */
int16_T KeAP_cm_NhXmaxOffset = 22;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant1'
                                        */

/* NeighboutHood Window */
int16_T KeAP_cm_NhXminOffset = 22;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant'
                                        */

/* NeighboutHood Window */
int16_T KeAP_cm_NhYmaxOffset = 55;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant3'
                                        */

/* NeighboutHood Window */
int16_T KeAP_cm_NhYminOffset = 55;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant2'
                                        */

/* NeighboutHood Window */
uint16_T KeAP_cm_ObjPrestFCDistThd = 120U;/* Referenced by:
                                           * '<S16>/Constant'
                                           * '<S25>/KeAP_cm_ObjPrestFCDistThd'
                                           */

/* Distance threshold to detect object in Front Centre */
uint16_T KeAP_cm_ObjPrestRCDistThd = 120U;/* Referenced by:
                                           * '<S16>/Constant1'
                                           * '<S25>/KeAP_cm_ObjPrestRCDistThd'
                                           */

/* Distance threshold to detect object in Rear Centre */
real32_T KeAP_cm_RearBrkDistChngLwThresh = 27.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Rear Braking Dist Change lower Threshold */
real32_T KeAP_cm_RearBrkDistChngUpThresh = 50.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Rear Braking Dist Change upper Threshold */
int16_T KeAP_cm_RearDistArcComp = 0;   /* Referenced by:
                                        * '<S140>/Constant1'
                                        * '<S140>/Constant2'
                                        * '<S143>/Constant1'
                                        * '<S143>/Constant2'
                                        * '<S146>/Constant1'
                                        * '<S146>/Constant2'
                                        * '<S152>/Constant1'
                                        * '<S152>/Constant2'
                                        */

/* Warning Zone 6 Dist */
int16_T KeAP_cm_RearLongDistAdj = 122; /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_RearLongDistAdj'
                                        */

/* Longitudanl Distance from Rear Axle to Rear edge of vehicle */
real32_T KeAP_cm_RearWallZone1Adj = 10.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
int16_T KeAP_cm_StndStillObjMinDistThd = 0;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
int16_T KeAP_cm_VIMGhstObjMinDistThd = 0;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
int16_T KeAP_cm_VehContourFrntXAdj = 30;/* Referenced by:
                                         * '<S95>/Constant'
                                         * '<S95>/Constant1'
                                         */

/* X-coordinate for Adjustment for Front side */
int16_T KeAP_cm_VehContourRearXAdj = -15;/* Referenced by:
                                          * '<S95>/Constant2'
                                          * '<S95>/Constant3'
                                          */

/* X-coordinate for Adjustment for Front side */
int16_T KeAP_cm_VehContour_FIL_x = 462;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur1' */

/* X-coordinate for FIL Edge */
int16_T KeAP_cm_VehContour_FIL_y = 36;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur2' */

/* Y-coordinate for FIL Edge */
int16_T KeAP_cm_VehContour_FIR_x = 462;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur1' */

/* X-coordinate for FIR Edge */
int16_T KeAP_cm_VehContour_FIR_y = -36;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur2' */

/* Y-coordinate for FIR Edge */
int16_T KeAP_cm_VehContour_FOL_x = 455;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd1' */

/* X-coordinate for FOL Edge */
int16_T KeAP_cm_VehContour_FOL_y = 70;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd2' */

/* Y-coordinate for FOL Edge */
int16_T KeAP_cm_VehContour_FOR_x = 455;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur1' */

/* X-coordinate for FOR Edge */
int16_T KeAP_cm_VehContour_FOR_y = -70;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur2' */

/* Y-coordinate for FOR Edge */
int16_T KeAP_cm_VehContour_FSL_x = 431;
                    /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout1' */

/* X-coordinate for FSL Edge */
int16_T KeAP_cm_VehContour_FSL_y = 103; /* Referenced by:
                                        * '<S25>/KeAP_s_GearShiftWaitCntTimeout2'
                                        * '<S95>/Constant4'
                                        */

/* Y-coordinate for FSL Edge */
int16_T KeAP_cm_VehContour_FSR_x = 431;
                               /* Referenced by: '<S25>/KeAP_s_SpdExceedDur1' */

/* X-coordinate for FSR Edge */
int16_T KeAP_cm_VehContour_FSR_y = -103;/* Referenced by:
                                        * '<S25>/KeAP_s_SpdExceedDur2'
                                        * '<S95>/Constant6'
                                        */

/* Y-coordinate for FSR Edge */
int16_T KeAP_cm_VehContour_RIL_x = -122;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur3' */

/* X-coordinate for RIL Edge */
int16_T KeAP_cm_VehContour_RIL_y = 33;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur4' */

/* Y-coordinate for RIL Edge */
int16_T KeAP_cm_VehContour_RIR_x = -122;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur3' */

/* X-coordinate for RIR Edge */
int16_T KeAP_cm_VehContour_RIR_y = -33;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur4' */

/* Y-coordinate for RIR Edge */
int16_T KeAP_cm_VehContour_ROL_x = -117;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur3' */

/* X-coordinate for ROL Edge */
int16_T KeAP_cm_VehContour_ROL_y = 81;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur4' */

/* Y-coordinate for ROL Edge */
int16_T KeAP_cm_VehContour_ROR_x = -117;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd3' */

/* X-coordinate for ROR Edge */
int16_T KeAP_cm_VehContour_ROR_y = -81;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd4' */

/* Y-coordinate for ROR Edge */
int16_T KeAP_cm_VehContour_RSL_x = -95;
                               /* Referenced by: '<S25>/KeAP_s_SpdExceedDur3' */

/* X-coordinate for RSL Edge */
int16_T KeAP_cm_VehContour_RSL_y = 98; /* Referenced by:
                                        * '<S25>/KeAP_s_SpdExceedDur4'
                                        * '<S95>/Constant5'
                                        */

/* Y-coordinate for RSL Edge */
int16_T KeAP_cm_VehContour_RSR_x = -95;
                    /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout3' */

/* X-coordinate for RSR Edge */
int16_T KeAP_cm_VehContour_RSR_y = -98;/* Referenced by:
                                        * '<S25>/KeAP_s_GearShiftWaitCntTimeout4'
                                        * '<S95>/Constant7'
                                        */

/* Y-coordinate for RSR Edge */
uint16_T KeAP_cm_VehicleWidth = 196U;
                               /* Referenced by: '<S25>/KeAP_cm_VehicleWidth' */

/* Ego Vehicle Car Width */
int16_T KeAP_cm_WarnOffset = 36;       /* Referenced by:
                                        * '<S25>/KeAP_cm_WarnOffset'
                                        * '<S88>/Constant1'
                                        * '<S95>/Constant8'
                                        */

/* Warn Offset Distance  */
uint16_T KeAP_cnt_AbortDelayWaitCnt = 3U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
real32_T KeAP_cnt_AbortHMIWaitCnt = 500.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_ArcBlipStandstillTimer = 700U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_ArcBlipVehInMotTimer[6] = { 700U, 200U, 200U, 200U, 100U, 100U
} ;                           /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KeAP_cnt_ArcBlipVehSpdThd[6] = { 0.0F, 1.0F, 2.0F, 3.0F, 4.0F, 5.0F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

uint16_T KeAP_cnt_BootupTimeThd = 500U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time threshold for ECU bootup */
uint16_T KeAP_cnt_BtnPressPopUpTimeThd = 200U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time for which Startup PopUp Requests are shown */
uint16_T KeAP_cnt_ChimeVolChgAlert = 50U;
                          /* Referenced by: '<S25>/KeAP_cnt_ChimeVolChgAlert' */

/* Chime Volume Change Alert time threshold - Half sec chime */
uint8_T KeAP_cnt_CruisAgeBasedDbncCount = 2U;/* Referenced by:
                                              * '<S92>/FC_Dbnc'
                                              * '<S92>/FC_Dbnc1'
                                              * '<S92>/FC_Dbnc2'
                                              * '<S93>/RC_Dbnc'
                                              * '<S93>/RC_Dbnc1'
                                              * '<S93>/RC_Dbnc2'
                                              */
int16_T KeAP_cnt_DebounceTimeThd = 10;
                           /* Referenced by: '<S25>/KeAP_cnt_DebounceTimeThd' */

/* Debounce time threshold */
uint8_T KeAP_cnt_DensStdStlHighPntConfThd = 75U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_DensStdStlLowPntConfThd = 90U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_DensStdStlObjCruiseAgeThd = 3U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_DensVIMHighPntConfThd = 75U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_DensVIMLowPntConfThd = 80U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_DensVIMObjCruiseAgeThd = 3U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint16_T KeAP_cnt_ForceNoiseModeTimeThd = 300U;/* Referenced by: '<S168>/Constant1' */
uint16_T KeAP_cnt_FrntChimeDisTimeThd = 300U;
                       /* Referenced by: '<S25>/KeAP_cnt_FrntChimeDisTimeThd' */

/* Front Chime Disable time threshold when Vehicle Standstill condition is true  */
uint16_T KeAP_cnt_HalfSecChimeAlert = 50U;
                         /* Referenced by: '<S25>/KeAP_cnt_HalfSecChimeAlert' */

/* Half Sec Chime Alert Time Threshold */
uint16_T KeAP_cnt_LEDBlinkTimeThd = 500U;
                           /* Referenced by: '<S25>/KeAP_cnt_LEDBlinkTimeThd' */

/* Time Step for LED blinking  */
real32_T KeAP_cnt_NoiseModeRearDistComp = 0.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_PlntModeLEDBlinkTimeThd = 300U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time Step for LED blinking for ECU-In Plant Mode */
real32_T KeAP_cnt_RearDistCompTimeThd = 11.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_RelCntrlWaitThd = 3U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_SPMBlinkLEDDur = 500U;
                                  /* Referenced by: '<S25>/KeAP_cm_DistZone7' */

/* PPPA LED Blinking Time Threshold 5 sec */
uint16_T KeAP_cnt_ScreenChimeTimeoutDur = 15U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Screen Chime Time Threshold */
uint16_T KeAP_cnt_ScreenWaitTimeoutDur = 500U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_cnt_StandstillTimeoutDur = 59000U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/*  Standstill Timer 9 min 50sec */
uint8_T KeAP_cnt_StndStSideCruiseAgeThd = 8U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_StndStSideLowCruiseAgeThd = 5U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_StndStillCruiseAgeThd = 5U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_StndStillPntConfThd = 70U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_StndStillSideLowPntConfThd = 75U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_StndStillSidePntConfThd = 65U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint16_T KeAP_cnt_SwtStuckTimeThd = 6000U;
                           /* Referenced by: '<S25>/KeAP_cnt_SwtStuckTimeThd' */

/* Maximum time threshold for Switch to be presssed condition 60sec */
uint16_T KeAP_cnt_TimeStep = 3U;       /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cnt_TimeStep'
                                        * '<S89>/Constant1'
                                        * '<S168>/Constant'
                                        * '<S183>/Constant'
                                        * '<S183>/Constant2'
                                        */

/* Time Step for Counter  */
uint8_T KeAP_cnt_VIMGhstObjCruiseAgeThd = 5U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_VIMGhstObjPntConfThd = 65U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_VIMSideLowPntConfThd = 75U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_VIMSideObjCruiseAgeThd = 8U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_VIMSideObjLowCruiseAgeThd = 5U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint8_T KeAP_cnt_VIMSidePntConfThd = 65U;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
uint16_T KeAP_cnt_VehKeyOnTimeThd = 500U;
                           /* Referenced by: '<S25>/KeAP_cnt_VehKeyOnTimeThd' */

/* Vehicle Key On Time Threshold */
uint16_T KeAP_cnt_VehMovementCntThd = 255U;/* Referenced by: '<S167>/Constant2' */
real32_T KeAP_degC_OperatingTempThd = 50.0F;
                         /* Referenced by: '<S25>/KeAP_degC_OperatingTempThd' */

/* Maximum operating Temprature threshold  */
real32_T KeAP_deg_SteerAngelDiffThd = 10.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint8_T KeAP_e_GbTypAT = 4U;           /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_e_GbTypAT'
                                        */

/* ATX Gear_Box_Type */
real32_T KeAP_k_BrakeIGain = 0.07F;
                                  /* Referenced by: '<S25>/KeAP_k_BrakeIGain' */
real32_T KeAP_k_BrakeLowerLimit = -0.07F;
                             /* Referenced by: '<S25>/KeAP_k_BrakeLowerLimit' */
real32_T KeAP_k_BrakePGain = 0.07F;
                                  /* Referenced by: '<S25>/KeAP_k_BrakePGain' */
real32_T KeAP_k_BrakeUpperLimit = 0.07F;
                             /* Referenced by: '<S25>/KeAP_k_BrakeUpperLimit' */
real32_T KeAP_k_CtrlOutCollDetActivate = 1.0F;
                      /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetActivate' */
real32_T KeAP_k_CtrlOutCollDetCollDistLimit = 30.0F;
                 /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetCollDistLimit' */
real32_T KeAP_k_CtrlOutCollDetRedStopVal = 2.0F;
                    /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetRedStopVal' */
real32_T KeAP_k_CtrlOutGearDrive = 4.0F;
                            /* Referenced by: '<S25>/KeAP_k_CtrlOutGearDrive' */
real32_T KeAP_k_CtrlOutGearPark = 1.0F;
                             /* Referenced by: '<S25>/KeAP_k_CtrlOutGearPark' */
real32_T KeAP_k_CtrlOutGearReverse = 2.0F;
                          /* Referenced by: '<S25>/KeAP_k_CtrlOutGearReverse' */
real32_T KeAP_k_CtrlOutRemainDistNA = 20.46F;
                         /* Referenced by: '<S25>/KeAP_k_CtrlOutRemainDistNA' */
real32_T KeAP_k_CtrlOutVehSpdMaxSpotSteer = 0.0F;
                   /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotSteer' */
real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd = 250.0F;
           /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd' */
real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrTime = 2.0F;
                 /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrTime' */
real32_T KeAP_k_DetWP_PreviewTime = 0.25F;
                           /* Referenced by: '<S25>/KeAP_k_DetWP_PreviewTime' */
real32_T KeAP_k_LatHeadDevDGain = 0.1F;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevDGain' */
real32_T KeAP_k_LatHeadDevIGain = 0.1F;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevIGain' */
real32_T KeAP_k_LatHeadDevPGain = 160.0F;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevPGain' */
real32_T KeAP_k_LatPathDevDGain = 5.0F;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevDGain' */
real32_T KeAP_k_LatPathDevIGain = 2.0F;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevIGain' */
real32_T KeAP_k_LatPathDevPGain = 1000.0F;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevPGain' */
real32_T KeAP_k_PathSepaMinSpd = 2.0F;
                              /* Referenced by: '<S25>/KeAP_k_PathSepaMinSpd' */
real32_T KeAP_k_PathSepaSpdRampGrd = 0.12F;
                          /* Referenced by: '<S25>/KeAP_k_PathSepaSpdRampGrd' */
real32_T KeAP_k_SteerLowerLimit = -570.0F;
                             /* Referenced by: '<S25>/KeAP_k_SteerLowerLimit' */
real32_T KeAP_k_SteerUpperLimit = 570.0F;
                             /* Referenced by: '<S25>/KeAP_k_SteerUpperLimit' */
real32_T KeAP_k_WhlCircum = 2.38F; /* Referenced by: '<S25>/KeAP_k_WhlCircum' */
real32_T KeAP_kph_ConfThdSpdBrkPnts[2] = { 1.0F, 8.0F } ;/* Referenced by: '<S88>/Constant3' */

real32_T KeAP_kph_EnblHysThd = 2.0F;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_EnblHysThd'
                                        */

/* Hystere sis threshold to apply for all vehicle speed related threshold parameters */
real32_T KeAP_kph_FrntWarnMaxSpdThd = 11.0F;/* Referenced by:
                                             * '<Root>/CVADAS_AutoPark_Main'
                                             * '<S25>/KeAP_kph_FrntWarnMaxSpdThd'
                                             */

/* Vehicle speed threshold during Front Park Assist feature */
real32_T KeAP_kph_PSDOffThd = 45.0F;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_PSDOffThd'
                                        */

/* Vehicle speed threshold during detection the parking slot */
real32_T KeAP_kph_PSDOnThd = 40.0F;
                                  /* Referenced by: '<S25>/KeAP_kph_PSDOnThd' */

/* Vehicle speed threshold to warn driver about hight speed during parking slot detection */
real32_T KeAP_kph_ParkMnvThd = 7.0F;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_ParkMnvThd'
                                        */

/* Ego Vehicle speed limit to continue parking maneuvering */
real32_T KeAP_kph_RearWarnMaxSpdThd = 11.0F;/* Referenced by:
                                             * '<Root>/CVADAS_AutoPark_Main'
                                             * '<S25>/KeAP_kph_RearWarnMaxSpdThd'
                                             */

/* Vehicle speed threshold during Rear Park Assist feature */
real32_T KeAP_kph_StandStillSpdThd = 0.4F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_ms_DbncTimeThsd = 150U;  /* Referenced by:
                                        * '<S112>/Constant1'
                                        * '<S113>/Constant1'
                                        * '<S114>/Constant1'
                                        * '<S133>/Constant1'
                                        * '<S134>/Constant1'
                                        * '<S135>/Constant1'
                                        */
real32_T KeAP_nm_TrqCmdRateLimThd = 20.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint8_T KeAP_pct_ObjConfidenceThd = 45U;/* Referenced by:
                                         * '<Root>/CVADAS_AutoPark_Main'
                                         * '<S25>/KeAP_pct_ObjConfidenceThd'
                                         */

/* Detected Object Confidence threshold */
real32_T KeAP_pct_PdlPosActThd = 0.03F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Screen Chime Time Threshold */
uint8_T KeAP_pct_SpdBasedObjConfThd[2] = { 45U, 45U } ;/* Referenced by: '<S88>/Constant' */

uint16_T KeAP_s_BSMInterfaceCntTimeout = 40U;
                      /* Referenced by: '<S25>/KeAP_s_BSMInterfaceCntTimeout' */

/* BSM Interface timeout threshold */
uint16_T KeAP_s_BSMInterfaceCntTimeoutTest = 18000U;
                     /* Referenced by: '<S25>/KeAP_s_BSMInterfaceCntTimeout1' */

/* BSM Interface timeout threshold */
uint16_T KeAP_s_CamHandshakeDur = 100U;
                             /* Referenced by: '<S25>/KeAP_s_CamHandshakeDur' */

/* Cam HMI Interface timeout threshold 100ms */
uint16_T KeAP_s_CamHandshakeDurTest = 18000U;
                            /* Referenced by: '<S25>/KeAP_s_CamHandshakeDur1' */

/* Cam HMI Interface timeout threshold 100ms */
uint16_T KeAP_s_EPSInterfaceCntTimeout = 40U;
                      /* Referenced by: '<S25>/KeAP_s_EPSInterfaceCntTimeout' */

/* EPS Interface timeout threshold */
uint16_T KeAP_s_EPSInterfaceCntTimeoutTest = 18000U;
                     /* Referenced by: '<S25>/KeAP_s_EPSInterfaceCntTimeout1' */

/* EPS Interface timeout threshold */
uint16_T KeAP_s_GearShiftReqWaitCnt = 10U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
uint16_T KeAP_s_GearShiftWaitCntTimeout = 500U;
                     /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout' */

/* Gear Change/Shift request timeout threshold */
uint16_T KeAP_s_MaxStandstillTimeThd = 60000U;
                        /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd' */

/* Maximum time threshold for vehicle to be in stand still position */
uint16_T KeAP_s_ObjInPathTimeoutDur = 60000U;
                         /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur' */

/* EPS Interface timeout threshold */
uint16_T KeAP_s_PausedPressBtnTimeoutDur = 60000U;
                    /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur' */

/* EPS Interface timeout threshold */
uint16_T KeAP_s_WaitEngineOnThd = 500U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Engine On Time THreshold */
real32_T KeAP_sec_SampleTime = 0.03F;  /* Referenced by: '<S13>/Constant1' */
boolean_T KeCMbB_b_EnblOncObjDbnc = 0;
                            /* Referenced by: '<S25>/KeCMbB_b_EnblOncObjDbnc' */
uint8_T KeHMI_e_ParkStyleTest = 1U;    /* Referenced by: '<S6>/Constant1' */

/* Tunable parameter to change value of Park Style input while Testing 0=None, 1=Rear_In, 2=Front_In */
uint8_T KePA_b_EnFeatPointSplitImp = 1U;/* Referenced by:
                                         * '<Root>/CVADAS_AutoPark_Main'
                                         * '<S88>/CalculateMinDistances1'
                                         */

/* Enable NeighboutHood Window */
uint8_T KePA_b_EnHeightFlagFrontSideArcs = 1U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check for Side front arcs */
uint8_T KePA_b_EnHeightFlagRearSideArcs = 1U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check for Side rear arc */
boolean_T KePA_b_EnbAppBlckg = 0;      /* Referenced by: '<S3>/Constant' */
uint8_T KePA_b_IsDnnHeightLow = 1U;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check */
int16_T KePA_cm_FrntWallDetectLatThd = 15;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
int16_T KePA_cm_FrntWallDetectLongThd = 30;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
int16_T KePA_cm_RearWallDetectLatThd = 20;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
int16_T KePA_cm_RearWallDetectLongThd = 30;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
real32_T KePA_cnt_FrntWallPntCntThd = 3.0F;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
real32_T KePA_cnt_RearWallPntCntThd = 3.0F;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
real32_T KeTOS_s_InTurnDbncTm = 3.0F;
                               /* Referenced by: '<S25>/KeTOS_s_InTurnDbncTm' */
real32_T KeTOS_s_StrDrvDbncTm = 13.0F;
                               /* Referenced by: '<S25>/KeTOS_s_StrDrvDbncTm' */
real32_T KeTOS_s_TurnExitDbncTm = 1.0F;
                             /* Referenced by: '<S25>/KeTOS_s_TurnExitDbncTm' */
real32_T KeTOS_x_InTurnThd = 0.04F;
                                  /* Referenced by: '<S25>/KeTOS_x_InTurnThd' */
real32_T KeTOS_x_TurnExitThd = 0.004F;
                                /* Referenced by: '<S25>/KeTOS_x_TurnExitThd' */
real32_T KsAP_k_DGainLUT_TD_55C[4] = { 0.002F, 0.002F, 0.0015F, 0.0012F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_DGainLUT_TD_63C[4] = { 0.0025F, 0.003F, 0.0025F, 0.002F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_DampingGainTD[4] = { 0.0F, 0.0F, 0.0F, 0.0F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_IGainLUT_TD_55C[4] = { 0.05F, 0.05F, 0.035F, 0.025F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_IGainLUT_TD_63C[4] = { 0.05F, 0.05F, 0.03F, 0.025F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_IntegratorExtSatTD[4] = { 3.5F, 2.0F, 2.0F, 1.0F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_PGainLUT_TD_55C[20] = { 0.01F, 0.01F, 0.007F, 0.0005F, 0.01F,
  0.01F, 0.007F, 0.0005F, 0.01F, 0.001F, 0.007F, 0.0005F, 0.01F, 0.01F, 0.007F,
  0.0005F, 0.01F, 0.01F, 0.007F, 0.0005F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_PGainLUT_TD_60C[20] = { 0.01F, 0.005F, 0.0035F, 0.0025F, 0.01F,
  0.005F, 0.0035F, 0.0025F, 0.01F, 0.005F, 0.0035F, 0.0025F, 0.01F, 0.005F,
  0.0035F, 0.0025F, 0.01F, 0.01F, 0.005F, 0.0035F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T KsAP_k_PGainLUT_TD_63C[20] = { 0.02F, 0.02F, 0.015F, 0.01F, 0.02F,
  0.02F, 0.015F, 0.01F, 0.02F, 0.02F, 0.015F, 0.01F, 0.02F, 0.02F, 0.015F, 0.01F,
  0.03F, 0.02F, 0.015F, 0.01F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

real32_T MaAP_m_ParkSpot1FrntStreetX;  /* synthesized block */
real32_T MaAP_m_ParkSpot1FrntStreetY;  /* synthesized block */
real32_T MaAP_m_ParkSpot2FrntBorderX;  /* synthesized block */
real32_T MaAP_m_ParkSpot2FrntBorderY;  /* synthesized block */
real32_T MaAP_m_ParkSpot3RearBorderX;  /* synthesized block */
real32_T MaAP_m_ParkSpot3RearBorderY;  /* synthesized block */
real32_T MaAP_m_ParkSpot4RearStreetX;  /* synthesized block */
real32_T MaAP_m_ParkSpot4RearStreetY;  /* synthesized block */
TbNVM_ProxyCalibParam MbNVM_ProxyParam;/* '<S17>/Bus Creator2' */
boolean_T MeAP_b_ExternalFail;         /* '<S8>/Logical Operator' */
boolean_T MeAP_b_FPADisable;           /* '<S27>/Logical Operator' */
boolean_T MeAP_b_FPASwtStatus;         /* '<Root>/CVADAS_AutoPark_Main' */
boolean_T MeAP_b_FPAVolDefMed;         /* '<S8>/Data Type Conversion116' */
boolean_T MeAP_b_FrntSenorBlock;       /* '<S8>/Data Type Conversion132' */
boolean_T MeAP_b_FrntSenorFail;        /* '<S8>/Data Type Conversion131' */
boolean_T MeAP_b_ObjInPath;            /* '<S87>/Compare' */
boolean_T MeAP_b_PARBActv4LOW;         /* '<S8>/Data Type Conversion120' */
boolean_T MeAP_b_PARBActvTrlr_27;      /* '<S8>/Data Type Conversion119' */
boolean_T MeAP_b_PARBActvTrlr_29;      /* '<S8>/Data Type Conversion7' */
boolean_T MeAP_b_PARBDiable;           /* '<S8>/Logical Operator3' */
boolean_T MeAP_b_PAVolDefMed;          /* '<S8>/Data Type Conversion115' */
boolean_T MeAP_b_PPPAActv4LOW;         /* '<S8>/Data Type Conversion123' */
boolean_T MeAP_b_PPPAActvTrlr;         /* '<S8>/Data Type Conversion122' */
boolean_T MeAP_b_PPPADefEng;           /* '<S8>/Data Type Conversion124' */
boolean_T MeAP_b_PPPADisable;          /* '<S8>/Logical Operator4' */
boolean_T MeAP_b_RPAActvTrlr_27;       /* '<S8>/Data Type Conversion114' */
boolean_T MeAP_b_RPAActvTrlr_29;       /* '<S8>/Data Type Conversion6' */
boolean_T MeAP_b_RPADisable;           /* '<S27>/Logical Operator2' */
boolean_T MeAP_b_RPASwtStatus;         /* '<Root>/CVADAS_AutoPark_Main' */
boolean_T MeAP_b_RPAVolDefMed;         /* '<S8>/Data Type Conversion117' */
boolean_T MeAP_b_RearSenorBlock;       /* '<S8>/Data Type Conversion134' */
boolean_T MeAP_b_RearSenorFail;        /* '<S8>/Data Type Conversion133' */
boolean_T MeAP_b_ResetKM;              /* '<Root>/CVADAS_AutoPark_Main' */
boolean_T MeAP_b_SystemFail;           /* '<S8>/Data Type Conversion1' */
int16_T MeAP_cm_FrntCenterMinXDist;    /* '<S92>/FC_Dbnc' */
int16_T MeAP_cm_FrntLeftMinXDist;      /* '<S92>/FC_Dbnc1' */
int16_T MeAP_cm_FrntRightMinXDist;     /* '<S92>/FC_Dbnc2' */
int16_T MeAP_cm_RearCenterMinXDist;    /* '<S93>/RC_Dbnc' */
int16_T MeAP_cm_RearLeftMinXDist;      /* '<S93>/RC_Dbnc1' */
int16_T MeAP_cm_RearRightMinXDist;     /* '<S93>/RC_Dbnc2' */
TeAutoPark_e_AutoParkStatus MeAP_e_AutoParkStatus;/* '<Root>/CVADAS_AutoPark_Main' */
TeAP_e_AlgoState MeAutoPark_e_AlgoState;/* '<Root>/CVADAS_AutoPark_Main' */
real32_T Obj_DistTable[5] = { 20.0F, 40.0F, 60.0F, 80.0F, 100.0F } ;
                                      /* Referenced by: '<S25>/Obj_DistTable' */

real32_T Overlap_Thrsld_Switch = 1.0F;
                              /* Referenced by: '<S25>/Overlap_Thrsld_Switch' */
TbAP_PAStateOut_t PAStateOut;          /* '<S209>/Bus Creator' */
real32_T RAEB_Envelope_Offset = 0.6F;
                               /* Referenced by: '<S25>/RAEB_Envelope_Offset' */
real32_T RAEB_Lateral_Distance_Notification = 2.0F;
                 /* Referenced by: '<S25>/RAEB_Lateral_Distance_Notification' */
real32_T RAEB_Minimum_Object_Heigh = 0.2F;
                          /* Referenced by: '<S25>/RAEB_Minimum_Object_Heigh' */

/* Minimum acceptable height of a object */
TbAP_RPAWarnOut_t RPAWarnOut;          /* '<S209>/Bus Creator2' */
uint8_T Reverse_Gr_num = 14U;        /* Referenced by: '<S25>/Reverse_Gr_num' */

/* Reverse Gear Number */
real32_T Steering_Angle_DeadZone_End = 0.03F;
                        /* Referenced by: '<S25>/Steering_Angle_DeadZone_End' */
real32_T Steering_Angle_DeadZone_Start = -0.03F;
                      /* Referenced by: '<S25>/Steering_Angle_DeadZone_Start' */
real32_T Straight_Driving_Thresold_rads2 = 0.15F;
                    /* Referenced by: '<S25>/Straight_Driving_Thresold_rads2' */
TbAP_VCActuatorOut_t VCActuatorOut;    /* '<S210>/Bus Creator1' */
real32_T dx_cm;                        /* '<S13>/Gain' */
real32_T keInpAdptr_e_StWhOffset = 0.0F;
                            /* Referenced by: '<S25>/keInpAdptr_e_StWhOffset' */

/* Wheel Offset */
real32_T keVehParam_e_StrWhlRatioBrkPnts[19] = { -525.0F, -503.57F, -478.57F,
  -450.0F, -414.29F, -371.43F, -321.43F, -249.0F, -128.57F, 0.0F, 107.14F,
  221.43F, 289.29F, 346.43F, 385.71F, 421.43F, 450.0F, 475.0F, 496.43F } ;
                    /* Referenced by: '<S25>/keVehParam_e_StrWhlRatioBrkPnts' */

/* Vehicle Steering Wheel Ratio Break Points  */
real32_T keVehParam_e_VehSteerRatioTable[19] = { 16.5F, 16.5F, 16.5F, 16.5F,
  16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F, 16.5F,
  16.5F, 16.5F, 16.5F, 16.5F } ;
                    /* Referenced by: '<S25>/keVehParam_e_VehSteerRatioTable' */

real32_T keVehParam_m_DistWhlBse = 3.672F;
                            /* Referenced by: '<S25>/keVehParam_m_DistWhlBse' */

/* Reply Type In */
real32_T sampling_time = 0.01F;       /* Referenced by: '<S25>/sampling_time' */

/* 10ms sampling time */

/* Const memory section */
/* Definition for custom storage class: Const */
const uint8_T CeAP_k_CurbArrayInit[10] = { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
  0U } ;                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_CurbLim_para[3] = { 0.1F, 0.1F, 0.1F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_break_point_para[2] = { -1.0F, -1.25F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_break_point_perp[2] = { -1.0F, -1.25F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_fin_loc_para_out[2] = { -3.0F, -1.4F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_p3_adj_perp[2] = { 0.5F, -0.5F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T KeAP_str_profile_bigPS[34] = { 0.0F, 0.0F, 0.0F, 0.0F, 33.0F,
  33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F,
  33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F, 33.0F,
  33.0F, 27.5F, 22.0F, 16.5F, 11.0F, 5.5F, 0.0F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T step_size_coeff[6] = { 0.0F, 0.0F, 0.5F, 1.0F, 1.0F, 1.0F } ;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

const real32_T str_whl_ang_park_out = 33.0F;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Block signals (default storage) */
B_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_B;

/* Block states (default storage) */
DW_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_DW;

/* Real-time model */
RT_MODEL_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_M_;
RT_MODEL_DT24_CVADAS_AP_CodGen_T *const DT24_CVADAS_AP_CodGen_M =
  &DT24_CVADAS_AP_CodGen_M_;

/* Forward declaration for local functions */
static void DT24_CVADAS_AP_CodGen_CheckForWallLikePatternFront(void);
static void DT24_CVADAS_AP_CodGen_CheckForWallLikePatternRear(void);
static void DT24_CVADAS_AP_CodGen_DetectBlockage(void);
static void DT24_CVADAS_AP_CodGen_IsValidObjectDistance(void);
static void DT24_CVADAS_AP_CodGen_CalculateDistance(void);
static void DT24_CVADAS_AP_CodGen_CheckNeaighbourHoodForRegions(void);
static void DT24_CVADAS_AP_CodGen_GetObjectPointRegion(void);
static void DT24_CVADAS_AP_CodGen_GetCenterRegionPoints(void);

/*
 * Output and update for atomic system:
 *    '<S46>/FIL_Blk'
 *    '<S46>/FIR_Blk'
 *    '<S46>/FOL_Blk'
 *    '<S46>/FOR_Blk'
 */
void DT24_CVADAS_AP_CodGen_FIL_Blk(const real32_T rtu_RadialDist[12], uint8_T
  rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, uint8_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T *localDW)
{
  boolean_T h_sf_internal_predicateOutput;
  int32_T tmp;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S46>/FIL_Blk' */
  if (localDW->is_active_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck == 0U) {
    localDW->is_active_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck = 1U;
    localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
      DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1;
    *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck) {
     case DT24_CVADAS_AP_CodGen_IN_BlockDetect2:
      if (localDW->output && (rtu_MeAP_b_ArcTrackFlag == 0)) {
        localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1;
        *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      } else {
        tmp = rtu_sensor_index - 1;
        if (((rtu_RadialDist[tmp] > KeAP_cm_RadialDistMaxThd) &&
             (rtu_RadialDist[tmp] < 1023.0F)) || ((rtu_MeAP_b_Standstill != 0) ||
             (rtu_MeAP_b_ArcTrackFlag != 0) || (rtu_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_ReverseGear))) {
          localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        } else if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlocked1:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear == TeAP_e_FiltdGearState_Parking) {
        localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear != TeAP_e_FiltdGearState_Parking) {
        localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1;
      } else {
        if (localDW->temporalCounter_i1 >= KeAP_k_BlockageHoldCountThd) {
          localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_SensorNoBlock1: */
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
      tmp = rtu_sensor_index - 1;
      if ((rtu_RadialDist[tmp] <= KeAP_cm_RadialDistThd) &&
          (rtu_MeAP_b_Standstill == 0)) {
        localDW->is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_BlockDetect2;
        localDW->savedGlobalX = rtu_Global_x;
        localDW->cnt = 0.0;
        localDW->step = 0U;
        if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S46>/FIL_Blk' */
}

/*
 * Output and update for atomic system:
 *    '<S46>/FSL_Blk'
 *    '<S46>/FSR_Blk'
 */
void DT24_CVADAS_AP_CodGen_FSL_Blk(const real32_T rtu_RadialDist[12], uint8_T
  rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, boolean_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_FSL_Blk_DT24_CVADAS_AP_CodGen_T *localDW)
{
  boolean_T h_sf_internal_predicateOutput;
  int32_T tmp;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S46>/FSL_Blk' */
  if (localDW->is_active_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck == 0U) {
    localDW->is_active_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck = 1U;
    localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
      DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_i;
    *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck) {
     case DT24_CVADAS_AP_CodGen_IN_BlockDetect2_d:
      if (localDW->output && (!rtu_MeAP_b_ArcTrackFlag)) {
        localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_h;
        *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      } else {
        tmp = rtu_sensor_index - 1;
        if (((rtu_RadialDist[tmp] > KeAP_cm_RadialDistMaxThd) &&
             (rtu_RadialDist[tmp] < 1023.0F)) || ((rtu_MeAP_b_Standstill != 0) ||
             rtu_MeAP_b_ArcTrackFlag || (rtu_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_ReverseGear))) {
          localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_i;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        } else if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_h:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear == TeAP_e_FiltdGearState_Parking) {
        localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_i;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_i:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear != TeAP_e_FiltdGearState_Parking) {
        localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_h;
      } else {
        if (localDW->temporalCounter_i1 >= KeAP_k_BlockageHoldCountThd) {
          localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_i;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_SensorNoBlock1: */
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
      tmp = rtu_sensor_index - 1;
      if ((rtu_RadialDist[tmp] <= KeAP_cm_RadialDistThd) &&
          (rtu_MeAP_b_Standstill == 0)) {
        localDW->is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_BlockDetect2_d;
        localDW->savedGlobalX = rtu_Global_x;
        localDW->cnt = 0.0;
        localDW->step = 0U;
        if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S46>/FSL_Blk' */
}

/*
 * Output and update for atomic system:
 *    '<S46>/RIL_Blk'
 *    '<S46>/RIR_Blk'
 *    '<S46>/ROL_Blk'
 *    '<S46>/ROR_Blk'
 */
void DT24_CVADAS_AP_CodGen_RIL_Blk(const real32_T rtu_RadialDist[12], uint8_T
  rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, uint8_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T *localDW)
{
  boolean_T h_sf_internal_predicateOutput;
  int32_T tmp;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S46>/RIL_Blk' */
  if (localDW->is_active_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck == 0U) {
    localDW->is_active_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck = 1U;
    localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
      DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_is;
    *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck) {
     case DT24_CVADAS_AP_CodGen_IN_BlockDetect2_b:
      if (localDW->output && (rtu_MeAP_b_ArcTrackFlag == 0)) {
        localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_l;
        *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      } else {
        tmp = rtu_sensor_index - 1;
        if (((rtu_RadialDist[tmp] > KeAP_cm_RadialDistMaxThd) &&
             (rtu_RadialDist[tmp] < 1023.0F)) || ((rtu_MeAP_b_Standstill != 0) ||
             (rtu_MeAP_b_ArcTrackFlag != 0) || (rtu_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_Drive))) {
          localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_is;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        } else if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_l:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear == TeAP_e_FiltdGearState_Parking) {
        localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_b;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_b:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear != TeAP_e_FiltdGearState_Parking) {
        localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_l;
      } else {
        if (localDW->temporalCounter_i1 >= KeAP_k_BlockageHoldCountThd) {
          localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_is;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_SensorNoBlock1: */
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
      tmp = rtu_sensor_index - 1;
      if ((rtu_RadialDist[tmp] <= KeAP_cm_RadialDistThd) &&
          (rtu_MeAP_b_Standstill == 0)) {
        localDW->is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_BlockDetect2_b;
        localDW->savedGlobalX = rtu_Global_x;
        localDW->cnt = 0.0;
        localDW->step = 0U;
        if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S46>/RIL_Blk' */
}

/*
 * Output and update for atomic system:
 *    '<S46>/RSL_Blk'
 *    '<S46>/RSR_Blk'
 */
void DT24_CVADAS_AP_CodGen_RSL_Blk(const real32_T rtu_RadialDist[12], uint8_T
  rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, boolean_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_RSL_Blk_DT24_CVADAS_AP_CodGen_T *localDW)
{
  boolean_T h_sf_internal_predicateOutput;
  int32_T tmp;
  if (localDW->temporalCounter_i1 < MAX_uint32_T) {
    localDW->temporalCounter_i1++;
  }

  /* Chart: '<S46>/RSL_Blk' */
  if (localDW->is_active_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck == 0U) {
    localDW->is_active_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck = 1U;
    localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
      DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_c;
    *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck) {
     case DT24_CVADAS_AP_CodGen_IN_BlockDetect2_g:
      if (localDW->output && (!rtu_MeAP_b_ArcTrackFlag)) {
        localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_a;
        *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      } else {
        tmp = rtu_sensor_index - 1;
        if (((rtu_RadialDist[tmp] > KeAP_cm_RadialDistMaxThd) &&
             (rtu_RadialDist[tmp] < 1023.0F)) || ((rtu_MeAP_b_Standstill != 0) ||
             rtu_MeAP_b_ArcTrackFlag || (rtu_MeAP_e_FiltdTrgtGear ==
              TeAP_e_FiltdGearState_Drive))) {
          localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_c;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        } else if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_a:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear == TeAP_e_FiltdGearState_Parking) {
        localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_g;
        localDW->temporalCounter_i1 = 0U;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold1_g:
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8One);
      if (rtu_MeAP_e_FiltdTrgtGear != TeAP_e_FiltdGearState_Parking) {
        localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_SensorBlocked1_a;
      } else {
        if (localDW->temporalCounter_i1 >= KeAP_k_BlockageHoldCountThd) {
          localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
            DT24_CVADAS_AP_CodGen_IN_SensorNoBlock1_c;
          *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_SensorNoBlock1: */
      *rty_SensorBlockStatus = ((uint8_T)CeAP_k_Uint8Zero);
      tmp = rtu_sensor_index - 1;
      if ((rtu_RadialDist[tmp] <= KeAP_cm_RadialDistThd) &&
          (rtu_MeAP_b_Standstill == 0)) {
        localDW->is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck =
          DT24_CVADAS_AP_CodGen_IN_BlockDetect2_g;
        localDW->savedGlobalX = rtu_Global_x;
        localDW->cnt = 0.0;
        localDW->step = 0U;
        if (localDW->cnt >= 2.0) {
          localDW->output = true;
          localDW->cnt = 0.0;
          localDW->step = 0U;
        } else if ((rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) &&
                   (localDW->step == 0)) {
          localDW->step = 1U;
          localDW->output = false;
        } else {
          if (fabsf(localDW->savedGlobalX - rtu_Global_x) >
              KeAP_cm_SenBlkVehMovDisThd) {
            if (rtu_RadialDist[tmp] > 1022.0F) {
              h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                (localDW->cnt <= 2.0));
            } else if (rtu_PrevRadialDist[tmp] < 5.0F) {
              if (rtu_RadialDist[tmp] > 20.0F) {
                if (rtu_RadialDist[tmp] < KeAP_cm_RadialDistThd) {
                  h_sf_internal_predicateOutput = ((localDW->step == 1) &&
                    (localDW->cnt <= 2.0));
                } else {
                  h_sf_internal_predicateOutput = false;
                }
              } else {
                h_sf_internal_predicateOutput = false;
              }
            } else {
              h_sf_internal_predicateOutput = false;
            }
          } else {
            h_sf_internal_predicateOutput = false;
          }

          if (h_sf_internal_predicateOutput) {
            localDW->cnt++;
            localDW->step = 0U;
            localDW->output = false;
          } else {
            localDW->output = false;
          }
        }
      }
      break;
    }
  }

  /* End of Chart: '<S46>/RSL_Blk' */
}

/* Output and update for function-call system: '<S91>/NeighbourHoodCheck' */
void DT24_CVADAS_AP_CodGen_NeighbourHoodCheck(const US_S_PointOutputBuff_t
  rtu_PointMapData[96], const US_S_PointOutputBuff_t *rtu_CurrentPoint, uint8_T
  rtu_EgoPtHeight, boolean_T *rty_DiscardPoint,
  B_NeighbourHoodCheck_DT24_CVADAS_AP_CodGen_T *localB)
{
  uint8_T b_pt_i;
  int16_T x_min;
  int16_T x_max;
  int16_T y_min;
  int16_T y_max;
  int32_T tmp;

  /* Saturate: '<S99>/Saturation' incorporates:
   *  Constant: '<S99>/Constant'
   */
  if (KeAP_cm_NhXminOffset > 100) {
    localB->Saturation = 100;
  } else if (KeAP_cm_NhXminOffset < (-100)) {
    localB->Saturation = (-100);
  } else {
    localB->Saturation = KeAP_cm_NhXminOffset;
  }

  /* End of Saturate: '<S99>/Saturation' */

  /* Saturate: '<S99>/Saturation1' incorporates:
   *  Constant: '<S99>/Constant1'
   */
  if (KeAP_cm_NhXmaxOffset > 100) {
    localB->Saturation1 = 100;
  } else if (KeAP_cm_NhXmaxOffset < (-100)) {
    localB->Saturation1 = (-100);
  } else {
    localB->Saturation1 = KeAP_cm_NhXmaxOffset;
  }

  /* End of Saturate: '<S99>/Saturation1' */

  /* Saturate: '<S99>/Saturation2' incorporates:
   *  Constant: '<S99>/Constant2'
   */
  if (KeAP_cm_NhYminOffset > 100) {
    localB->Saturation2 = 100;
  } else if (KeAP_cm_NhYminOffset < (-100)) {
    localB->Saturation2 = (-100);
  } else {
    localB->Saturation2 = KeAP_cm_NhYminOffset;
  }

  /* End of Saturate: '<S99>/Saturation2' */

  /* Saturate: '<S99>/Saturation3' incorporates:
   *  Constant: '<S99>/Constant3'
   */
  if (KeAP_cm_NhYmaxOffset > 100) {
    localB->Saturation3 = 100;
  } else if (KeAP_cm_NhYmaxOffset < (-100)) {
    localB->Saturation3 = (-100);
  } else {
    localB->Saturation3 = KeAP_cm_NhYmaxOffset;
  }

  /* End of Saturate: '<S99>/Saturation3' */

  /* Chart: '<S99>/NeighbourCheck' */
  localB->DiscardPoint = false;
  b_pt_i = 1U;
  x_min = (int16_T)(rtu_CurrentPoint->x - localB->Saturation);
  x_max = (int16_T)(rtu_CurrentPoint->x + localB->Saturation1);
  y_min = (int16_T)(rtu_CurrentPoint->y - localB->Saturation2);
  y_max = (int16_T)(rtu_CurrentPoint->y + localB->Saturation3);
  while ((b_pt_i <= ((uint8_T)96U)) && (!localB->DiscardPoint)) {
    tmp = b_pt_i - 1;
    if ((rtu_PointMapData[tmp].x <= x_max) && ((rtu_PointMapData[tmp].x >= x_min)
         && ((rtu_PointMapData[tmp].y <= y_max) && (rtu_PointMapData[tmp].y >=
           y_min)))) {
      localB->DiscardPoint = (((rtu_PointMapData[tmp].confidence >
        rtu_CurrentPoint->confidence) && ((rtu_EgoPtHeight != 2) ||
        (rtu_PointMapData[tmp].height == 2))) || localB->DiscardPoint);
    }

    b_pt_i = (uint8_T)((uint32_T)b_pt_i + ((uint8_T)CeAP_k_Uint8One));
  }

  /* End of Chart: '<S99>/NeighbourCheck' */

  /* SignalConversion generated from: '<S99>/DiscardPoint' */
  *rty_DiscardPoint = localB->DiscardPoint;
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_CheckForWallLikePatternFront(void)
{
  DT24_CVADAS_AP_CodGen_B.WallCount = 0U;
  DT24_CVADAS_AP_CodGen_B.fidx = 1U;
  if (DT24_CVADAS_AP_CodGen_DW.FrontIdx >= 1) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist = 0;
    DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx = 0U;
  }

  while (DT24_CVADAS_AP_CodGen_B.fidx <= DT24_CVADAS_AP_CodGen_DW.FrontIdx) {
    DT24_CVADAS_AP_CodGen_B.i2 =
      DT24_CVADAS_AP_CodGen_DW.FrontPointsArray[DT24_CVADAS_AP_CodGen_B.fidx - 1]
      - 1;
    DT24_CVADAS_AP_CodGen_B.i4 = DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.x -
      DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i2]
      .x;
    if (DT24_CVADAS_AP_CodGen_B.i4 > 32767) {
      DT24_CVADAS_AP_CodGen_B.i4 = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i4 < -32768) {
        DT24_CVADAS_AP_CodGen_B.i4 = -32768;
      }
    }

    if ((int16_T)DT24_CVADAS_AP_CodGen_B.i4 < 0) {
      DT24_CVADAS_AP_CodGen_B.i4 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i4;
      if (DT24_CVADAS_AP_CodGen_B.i4 > 32767) {
        DT24_CVADAS_AP_CodGen_B.i4 = 32767;
      }

      DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i4;
    } else {
      DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i4;
    }

    if (DT24_CVADAS_AP_CodGen_B.z <= KePA_cm_FrntWallDetectLongThd) {
      DT24_CVADAS_AP_CodGen_B.PtSeparationCount = 0U;
      DT24_CVADAS_AP_CodGen_B.InnerIdx = 1U;
      DT24_CVADAS_AP_CodGen_B.i4 = (int32_T)
        (DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx + 1U);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i4 > 255U) {
        DT24_CVADAS_AP_CodGen_B.i4 = 255;
      }

      DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx = (uint8_T)
        DT24_CVADAS_AP_CodGen_B.i4;
      DT24_CVADAS_AP_CodGen_B.i4 =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i2]
        .x + DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist;
      if (DT24_CVADAS_AP_CodGen_B.i4 > 32767) {
        DT24_CVADAS_AP_CodGen_B.i4 = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i4 < -32768) {
          DT24_CVADAS_AP_CodGen_B.i4 = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist = (int16_T)
        DT24_CVADAS_AP_CodGen_B.i4;
      while (DT24_CVADAS_AP_CodGen_B.InnerIdx <=
             DT24_CVADAS_AP_CodGen_DW.FrontIdx) {
        DT24_CVADAS_AP_CodGen_B.i4 =
          DT24_CVADAS_AP_CodGen_DW.FrontPointsArray[DT24_CVADAS_AP_CodGen_B.InnerIdx
          - 1] - 1;
        DT24_CVADAS_AP_CodGen_B.i3 =
          DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i4]
          .x -
          DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i2]
          .x;
        if (DT24_CVADAS_AP_CodGen_B.i3 > 32767) {
          DT24_CVADAS_AP_CodGen_B.i3 = 32767;
        } else {
          if (DT24_CVADAS_AP_CodGen_B.i3 < -32768) {
            DT24_CVADAS_AP_CodGen_B.i3 = -32768;
          }
        }

        if ((int16_T)DT24_CVADAS_AP_CodGen_B.i3 < 0) {
          DT24_CVADAS_AP_CodGen_B.i3 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i3;
          if (DT24_CVADAS_AP_CodGen_B.i3 > 32767) {
            DT24_CVADAS_AP_CodGen_B.i3 = 32767;
          }

          DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i3;
        } else {
          DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i3;
        }

        if (DT24_CVADAS_AP_CodGen_B.z <= KePA_cm_FrntWallDetectLongThd) {
          DT24_CVADAS_AP_CodGen_B.i4 =
            DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i4]
            .y -
            DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i2]
            .y;
          if (DT24_CVADAS_AP_CodGen_B.i4 > 32767) {
            DT24_CVADAS_AP_CodGen_B.i4 = 32767;
          } else {
            if (DT24_CVADAS_AP_CodGen_B.i4 < -32768) {
              DT24_CVADAS_AP_CodGen_B.i4 = -32768;
            }
          }

          if ((int16_T)DT24_CVADAS_AP_CodGen_B.i4 < 0) {
            DT24_CVADAS_AP_CodGen_B.i4 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i4;
            if (DT24_CVADAS_AP_CodGen_B.i4 > 32767) {
              DT24_CVADAS_AP_CodGen_B.i4 = 32767;
            }

            DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i4;
          } else {
            DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.i4;
          }

          DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput =
            (DT24_CVADAS_AP_CodGen_B.z >= KePA_cm_FrntWallDetectLatThd);
        } else {
          DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput = false;
        }

        if (DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput) {
          DT24_CVADAS_AP_CodGen_B.i4 = (int32_T)
            (DT24_CVADAS_AP_CodGen_B.PtSeparationCount + 1U);
          if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i4 > 255U) {
            DT24_CVADAS_AP_CodGen_B.i4 = 255;
          }

          DT24_CVADAS_AP_CodGen_B.PtSeparationCount = (uint8_T)
            DT24_CVADAS_AP_CodGen_B.i4;
        }

        DT24_CVADAS_AP_CodGen_B.i4 = (int32_T)(DT24_CVADAS_AP_CodGen_B.InnerIdx
          + 1U);
        if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i4 > 255U) {
          DT24_CVADAS_AP_CodGen_B.i4 = 255;
        }

        DT24_CVADAS_AP_CodGen_B.InnerIdx = (uint8_T)DT24_CVADAS_AP_CodGen_B.i4;
      }

      if (DT24_CVADAS_AP_CodGen_B.PtSeparationCount >= 2) {
        DT24_CVADAS_AP_CodGen_B.i2 = (int32_T)(DT24_CVADAS_AP_CodGen_B.WallCount
          + 1U);
        if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i2 > 255U) {
          DT24_CVADAS_AP_CodGen_B.i2 = 255;
        }

        DT24_CVADAS_AP_CodGen_B.WallCount = (uint8_T)DT24_CVADAS_AP_CodGen_B.i2;
      }
    }

    DT24_CVADAS_AP_CodGen_B.i2 = (int32_T)(DT24_CVADAS_AP_CodGen_B.fidx + 1U);
    if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i2 > 255U) {
      DT24_CVADAS_AP_CodGen_B.i2 = 255;
    }

    DT24_CVADAS_AP_CodGen_B.fidx = (uint8_T)DT24_CVADAS_AP_CodGen_B.i2;
  }

  if (DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx > 0) {
    switch (DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx) {
     case 0:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist == 0) {
        DT24_CVADAS_AP_CodGen_B.z = 0;
      } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist < 0) {
        DT24_CVADAS_AP_CodGen_B.z = MIN_int16_T;
      } else {
        DT24_CVADAS_AP_CodGen_B.z = MAX_int16_T;
      }
      break;

     case 1:
      DT24_CVADAS_AP_CodGen_B.z =
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist;
      break;

     default:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist >= 0) {
        DT24_CVADAS_AP_CodGen_B.d_y = (uint16_T)
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist;
      } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist == -32768) {
        DT24_CVADAS_AP_CodGen_B.d_y = 32768U;
      } else {
        DT24_CVADAS_AP_CodGen_B.d_y = (uint16_T)
          -DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist;
      }

      DT24_CVADAS_AP_CodGen_B.q = (uint16_T)
        (DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx == 0U ? MAX_uint32_T :
         (uint32_T)DT24_CVADAS_AP_CodGen_B.d_y /
         DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx);
      DT24_CVADAS_AP_CodGen_B.d_y = (uint16_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.d_y - (uint16_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.q * DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx));
      if ((DT24_CVADAS_AP_CodGen_B.d_y > 0) && (DT24_CVADAS_AP_CodGen_B.d_y >=
           (int32_T)((uint32_T)DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx >> 1) +
           (DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx & 1))) {
        DT24_CVADAS_AP_CodGen_B.q++;
      }

      DT24_CVADAS_AP_CodGen_B.z = (int16_T)DT24_CVADAS_AP_CodGen_B.q;
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist < 0) {
        DT24_CVADAS_AP_CodGen_B.z = (int16_T)-(int16_T)DT24_CVADAS_AP_CodGen_B.q;
      }
      break;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist =
      DT24_CVADAS_AP_CodGen_B.z;
    DT24_CVADAS_AP_CodGen_B.i2 =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist -
      DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[2];
    if (DT24_CVADAS_AP_CodGen_B.i2 > 32767) {
      DT24_CVADAS_AP_CodGen_B.i2 = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i2 < -32768) {
        DT24_CVADAS_AP_CodGen_B.i2 = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist = (int16_T)
      DT24_CVADAS_AP_CodGen_B.i2;
  }

  if (DT24_CVADAS_AP_CodGen_B.WallCount >= KePA_cnt_FrntWallPntCntThd) {
    DT24_CVADAS_AP_CodGen_B.MeAP_b_IsWall = 1U;
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_CheckForWallLikePatternRear(void)
{
  DT24_CVADAS_AP_CodGen_B.fidx_c = 1U;
  if (DT24_CVADAS_AP_CodGen_DW.RearIdx >= 1) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist = 0;
    DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx = 0U;
  }

  while (DT24_CVADAS_AP_CodGen_B.fidx_c <= DT24_CVADAS_AP_CodGen_DW.RearIdx) {
    DT24_CVADAS_AP_CodGen_B.i5 =
      DT24_CVADAS_AP_CodGen_DW.RearPointsArray[DT24_CVADAS_AP_CodGen_B.fidx_c -
      1] - 1;
    DT24_CVADAS_AP_CodGen_B.i7 = DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.x -
      DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i5]
      .x;
    if (DT24_CVADAS_AP_CodGen_B.i7 > 32767) {
      DT24_CVADAS_AP_CodGen_B.i7 = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i7 < -32768) {
        DT24_CVADAS_AP_CodGen_B.i7 = -32768;
      }
    }

    if ((int16_T)DT24_CVADAS_AP_CodGen_B.i7 < 0) {
      DT24_CVADAS_AP_CodGen_B.i7 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i7;
      if (DT24_CVADAS_AP_CodGen_B.i7 > 32767) {
        DT24_CVADAS_AP_CodGen_B.i7 = 32767;
      }

      DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i7;
    } else {
      DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i7;
    }

    if (DT24_CVADAS_AP_CodGen_B.z_k <= KePA_cm_RearWallDetectLongThd) {
      DT24_CVADAS_AP_CodGen_B.RearPtSeparationCount = 0U;
      DT24_CVADAS_AP_CodGen_B.InnerIdx_p = 1U;
      DT24_CVADAS_AP_CodGen_B.i7 = (int32_T)
        (DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx + 1U);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i7 > 255U) {
        DT24_CVADAS_AP_CodGen_B.i7 = 255;
      }

      DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx = (uint8_T)
        DT24_CVADAS_AP_CodGen_B.i7;
      DT24_CVADAS_AP_CodGen_B.i7 =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i5]
        .x + DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist;
      if (DT24_CVADAS_AP_CodGen_B.i7 > 32767) {
        DT24_CVADAS_AP_CodGen_B.i7 = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i7 < -32768) {
          DT24_CVADAS_AP_CodGen_B.i7 = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist = (int16_T)
        DT24_CVADAS_AP_CodGen_B.i7;
      while (DT24_CVADAS_AP_CodGen_B.InnerIdx_p <=
             DT24_CVADAS_AP_CodGen_DW.RearIdx) {
        DT24_CVADAS_AP_CodGen_B.i7 =
          DT24_CVADAS_AP_CodGen_DW.RearPointsArray[DT24_CVADAS_AP_CodGen_B.InnerIdx_p
          - 1] - 1;
        DT24_CVADAS_AP_CodGen_B.i6 =
          DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i7]
          .x -
          DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i5]
          .x;
        if (DT24_CVADAS_AP_CodGen_B.i6 > 32767) {
          DT24_CVADAS_AP_CodGen_B.i6 = 32767;
        } else {
          if (DT24_CVADAS_AP_CodGen_B.i6 < -32768) {
            DT24_CVADAS_AP_CodGen_B.i6 = -32768;
          }
        }

        if ((int16_T)DT24_CVADAS_AP_CodGen_B.i6 < 0) {
          DT24_CVADAS_AP_CodGen_B.i6 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i6;
          if (DT24_CVADAS_AP_CodGen_B.i6 > 32767) {
            DT24_CVADAS_AP_CodGen_B.i6 = 32767;
          }

          DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i6;
        } else {
          DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i6;
        }

        if (DT24_CVADAS_AP_CodGen_B.z_k <= KePA_cm_RearWallDetectLongThd) {
          DT24_CVADAS_AP_CodGen_B.i7 =
            DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i7]
            .y -
            DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i5]
            .y;
          if (DT24_CVADAS_AP_CodGen_B.i7 > 32767) {
            DT24_CVADAS_AP_CodGen_B.i7 = 32767;
          } else {
            if (DT24_CVADAS_AP_CodGen_B.i7 < -32768) {
              DT24_CVADAS_AP_CodGen_B.i7 = -32768;
            }
          }

          if ((int16_T)DT24_CVADAS_AP_CodGen_B.i7 < 0) {
            DT24_CVADAS_AP_CodGen_B.i7 = -(int16_T)DT24_CVADAS_AP_CodGen_B.i7;
            if (DT24_CVADAS_AP_CodGen_B.i7 > 32767) {
              DT24_CVADAS_AP_CodGen_B.i7 = 32767;
            }

            DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i7;
          } else {
            DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.i7;
          }

          DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput_f =
            (DT24_CVADAS_AP_CodGen_B.z_k >= KePA_cm_RearWallDetectLatThd);
        } else {
          DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput_f = false;
        }

        if (DT24_CVADAS_AP_CodGen_B.sf_internal_predicateOutput_f) {
          DT24_CVADAS_AP_CodGen_B.i7 = (int32_T)
            (DT24_CVADAS_AP_CodGen_B.RearPtSeparationCount + 1U);
          if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i7 > 255U) {
            DT24_CVADAS_AP_CodGen_B.i7 = 255;
          }

          DT24_CVADAS_AP_CodGen_B.RearPtSeparationCount = (uint8_T)
            DT24_CVADAS_AP_CodGen_B.i7;
        }

        DT24_CVADAS_AP_CodGen_B.i7 = (int32_T)
          (DT24_CVADAS_AP_CodGen_B.InnerIdx_p + 1U);
        if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i7 > 255U) {
          DT24_CVADAS_AP_CodGen_B.i7 = 255;
        }

        DT24_CVADAS_AP_CodGen_B.InnerIdx_p = (uint8_T)DT24_CVADAS_AP_CodGen_B.i7;
      }

      if (DT24_CVADAS_AP_CodGen_B.RearPtSeparationCount >= 2) {
        DT24_CVADAS_AP_CodGen_B.i5 = (int32_T)
          (DT24_CVADAS_AP_CodGen_DW.RearWallCount + 1U);
        if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i5 > 255U) {
          DT24_CVADAS_AP_CodGen_B.i5 = 255;
        }

        DT24_CVADAS_AP_CodGen_DW.RearWallCount = (uint8_T)
          DT24_CVADAS_AP_CodGen_B.i5;
      }
    }

    DT24_CVADAS_AP_CodGen_B.i5 = (int32_T)(DT24_CVADAS_AP_CodGen_B.fidx_c + 1U);
    if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i5 > 255U) {
      DT24_CVADAS_AP_CodGen_B.i5 = 255;
    }

    DT24_CVADAS_AP_CodGen_B.fidx_c = (uint8_T)DT24_CVADAS_AP_CodGen_B.i5;
  }

  if (DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx > 0) {
    switch (DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx) {
     case 0:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist == 0) {
        DT24_CVADAS_AP_CodGen_B.z_k = 0;
      } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist < 0) {
        DT24_CVADAS_AP_CodGen_B.z_k = MIN_int16_T;
      } else {
        DT24_CVADAS_AP_CodGen_B.z_k = MAX_int16_T;
      }
      break;

     case 1:
      DT24_CVADAS_AP_CodGen_B.z_k =
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist;
      break;

     default:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist >= 0) {
        DT24_CVADAS_AP_CodGen_B.d_y_c = (uint16_T)
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist;
      } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist == -32768) {
        DT24_CVADAS_AP_CodGen_B.d_y_c = 32768U;
      } else {
        DT24_CVADAS_AP_CodGen_B.d_y_c = (uint16_T)
          -DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist;
      }

      DT24_CVADAS_AP_CodGen_B.q_b = (uint16_T)
        (DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx == 0U ? MAX_uint32_T :
         (uint32_T)DT24_CVADAS_AP_CodGen_B.d_y_c /
         DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx);
      DT24_CVADAS_AP_CodGen_B.d_y_c = (uint16_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.d_y_c - (uint16_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.q_b * DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx));
      if ((DT24_CVADAS_AP_CodGen_B.d_y_c > 0) && (DT24_CVADAS_AP_CodGen_B.d_y_c >=
           (int32_T)((uint32_T)DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx >> 1) +
           (DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx & 1))) {
        DT24_CVADAS_AP_CodGen_B.q_b++;
      }

      DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)DT24_CVADAS_AP_CodGen_B.q_b;
      if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist < 0) {
        DT24_CVADAS_AP_CodGen_B.z_k = (int16_T)-(int16_T)
          DT24_CVADAS_AP_CodGen_B.q_b;
      }
      break;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist =
      DT24_CVADAS_AP_CodGen_B.z_k;
    DT24_CVADAS_AP_CodGen_B.i5 =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist -
      DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[10];
    if (DT24_CVADAS_AP_CodGen_B.i5 > 32767) {
      DT24_CVADAS_AP_CodGen_B.i5 = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i5 < -32768) {
        DT24_CVADAS_AP_CodGen_B.i5 = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist = (int16_T)
      DT24_CVADAS_AP_CodGen_B.i5;
  }

  if (DT24_CVADAS_AP_CodGen_DW.RearWallCount >= KePA_cnt_RearWallPntCntThd) {
    DT24_CVADAS_AP_CodGen_B.i5 = (int32_T)(DT24_CVADAS_AP_CodGen_B.MeAP_b_IsWall
      + 2U);
    if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i5 > 255U) {
      DT24_CVADAS_AP_CodGen_B.i5 = 255;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_b_IsWall = (uint8_T)DT24_CVADAS_AP_CodGen_B.i5;
  }
}

/* Function for Chart: '<S42>/Chart1' */
static void DT24_CVADAS_AP_CodGen_DetectBlockage(void)
{
  int32_T tmp;
  if (((DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill == 1) ||
       (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k !=
        TeAP_e_FiltdGearState_ReverseGear) ||
       (DT24_CVADAS_AP_CodGen_DW.temporalCounter_i2 >= 1000U)) &&
      (!DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts)) {
    DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
      DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
    DT24_CVADAS_AP_CodGen_DW.is_c3_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_Default;
    DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts = false;
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage) {
     case DT24_CVADAS_AP_CodGen_IN_BlockageDetected:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 8U;
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k ==
          TeAP_e_FiltdGearState_Parking) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold;
        DT24_CVADAS_AP_CodGen_DW.temporalCounter_i1 = 0U;
        DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts = true;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Default_c:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 0U;
      if ((MeAP_cm_FrntCenterMinXDist >= 65) && (MeAP_cm_FrntCenterMinXDist <
           100)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc2;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 1U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      } else if ((MeAP_cm_FrntCenterMinXDist >= 100) &&
                 (MeAP_cm_FrntCenterMinXDist < 135)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc3;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 2U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      } else {
        if ((MeAP_cm_FrntCenterMinXDist >= 135) && (MeAP_cm_FrntCenterMinXDist <
             1023)) {
          DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
            DT24_CVADAS_AP_CodGen_IN_TransitionToArc4;
          DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 3U;
          tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockageReset:
      break;

     case DT24_CVADAS_AP_CodGen_IN_SensorBlockedHold:
      if (DT24_CVADAS_AP_CodGen_DW.temporalCounter_i1 >=
          KeAP_k_BlockageHoldCountThd) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_SensorBlockageReset;
        DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts = false;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k !=
            TeAP_e_FiltdGearState_Parking) {
          DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
            DT24_CVADAS_AP_CodGen_IN_BlockageDetected;
          DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 8U;
          tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
          DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts =
            ((DT24_CVADAS_AP_CodGen_B.cnt >= 5) ||
             DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts);
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_TransitionToArc2:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 1U;
      if ((MeAP_cm_FrntCenterMinXDist >= 100) && (MeAP_cm_FrntCenterMinXDist <
           135)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc3;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 2U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_TransitionToArc2_2:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 5U;
      if ((MeAP_cm_FrntCenterMinXDist >= 100) && (MeAP_cm_FrntCenterMinXDist <
           135)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc3_2;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 6U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      } else {
        if ((MeAP_cm_FrntCenterMinXDist >= 135) && (MeAP_cm_FrntCenterMinXDist <
             155)) {
          DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
            DT24_CVADAS_AP_CodGen_IN_TransitionToArc4_2;
          DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 7U;
          tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
          DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts =
            ((DT24_CVADAS_AP_CodGen_B.cnt >= 5) ||
             DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts);
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_TransitionToArc3:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 2U;
      if ((MeAP_cm_FrntCenterMinXDist >= 135) && (MeAP_cm_FrntCenterMinXDist <
           1023)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc4;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 3U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      } else {
        if (MeAP_cm_FrntCenterMinXDist == 1023) {
          DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
            DT24_CVADAS_AP_CodGen_IN_TransitionToArc2_2;
          DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 5U;
          tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
          if ((uint32_T)tmp > 255U) {
            tmp = 255;
          }

          DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_TransitionToArc3_2:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 6U;
      if ((MeAP_cm_FrntCenterMinXDist >= 135) && (MeAP_cm_FrntCenterMinXDist <
           1023)) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc4_2;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 7U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
        DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts =
          ((DT24_CVADAS_AP_CodGen_B.cnt >= 5) ||
           DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_TransitionToArc4:
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 3U;
      if (MeAP_cm_FrntCenterMinXDist == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_TransitionToArc2_2;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 5U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
      }
      break;

     default:
      /* case IN_TransitionToArc4_2: */
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 7U;
      if (MeAP_cm_FrntCenterMinXDist == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
          DT24_CVADAS_AP_CodGen_IN_BlockageDetected;
        DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 8U;
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_B.cnt + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_B.cnt = (uint8_T)tmp;
        DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts =
          ((DT24_CVADAS_AP_CodGen_B.cnt >= 5) ||
           DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts);
      }
      break;
    }
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_IsValidObjectDistance(void)
{
  if (DT24_CVADAS_AP_CodGen_DW.ObjInFront &&
      (DT24_CVADAS_AP_CodGen_DW.DistanceToObject < 0)) {
    DT24_CVADAS_AP_CodGen_DW.DistanceToObject = DT24_CVADAS_AP_CodGen_DW.MaxDist;
  } else {
    if ((!DT24_CVADAS_AP_CodGen_DW.ObjInFront) &&
        (DT24_CVADAS_AP_CodGen_DW.DistanceToObject > 0)) {
      DT24_CVADAS_AP_CodGen_B.i1 = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
      if (DT24_CVADAS_AP_CodGen_B.i1 > 32767) {
        DT24_CVADAS_AP_CodGen_B.i1 = 32767;
      }

      DT24_CVADAS_AP_CodGen_DW.DistanceToObject = (int16_T)
        DT24_CVADAS_AP_CodGen_B.i1;
    }
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_CalculateDistance(void)
{
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T exitg1;
  DT24_CVADAS_AP_CodGen_B.NumberOfIterations = ((uint8_T)8U);
  DT24_CVADAS_AP_CodGen_B.i12 = 1;
  if (1 < 0) {
    DT24_CVADAS_AP_CodGen_B.i12 = 0;
  }

  DT24_CVADAS_AP_CodGen_B.ContourPtIdx = (uint8_T)DT24_CVADAS_AP_CodGen_B.i12;
  DT24_CVADAS_AP_CodGen_DW.DistanceToObject = DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_DW.ObjInFront = true;
  DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd =
    IbAP_InputVrntTunParam.KeAP_cm_HalfVehicleWidth;
  if (DT24_CVADAS_AP_CodGen_DW.current_point_x < 0) {
    DT24_CVADAS_AP_CodGen_B.q0 = (int32_T)((uint32_T)((uint8_T)9U) + ((uint8_T)
      8U));
    if ((uint32_T)DT24_CVADAS_AP_CodGen_B.q0 > 255U) {
      DT24_CVADAS_AP_CodGen_B.q0 = 255;
    }

    DT24_CVADAS_AP_CodGen_B.i12 = 1;
    if (1 < 0) {
      DT24_CVADAS_AP_CodGen_B.i12 = 0;
    }

    DT24_CVADAS_AP_CodGen_B.qY = (uint32_T)DT24_CVADAS_AP_CodGen_B.q0 -
      /*MW:OvSatOk*/ DT24_CVADAS_AP_CodGen_B.i12;
    if (DT24_CVADAS_AP_CodGen_B.qY > (uint32_T)DT24_CVADAS_AP_CodGen_B.q0) {
      DT24_CVADAS_AP_CodGen_B.qY = 0U;
    }

    DT24_CVADAS_AP_CodGen_B.NumberOfIterations = (uint8_T)
      DT24_CVADAS_AP_CodGen_B.qY;
    DT24_CVADAS_AP_CodGen_B.ContourPtIdx = ((uint8_T)9U);
    DT24_CVADAS_AP_CodGen_B.q0 = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.q0 > 32767) {
      DT24_CVADAS_AP_CodGen_B.q0 = 32767;
    }

    DT24_CVADAS_AP_CodGen_DW.DistanceToObject = (int16_T)
      DT24_CVADAS_AP_CodGen_B.q0;
    DT24_CVADAS_AP_CodGen_DW.ObjInFront = false;
    DT24_CVADAS_AP_CodGen_B.q0 = IbAP_InputVrntTunParam.KeAP_cm_HalfVehicleWidth
      - 5;
    if (DT24_CVADAS_AP_CodGen_B.q0 < -32768) {
      DT24_CVADAS_AP_CodGen_B.q0 = -32768;
    }

    DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd = (int16_T)
      DT24_CVADAS_AP_CodGen_B.q0;
  }

  exitg1 = false;
  while ((!exitg1) && (DT24_CVADAS_AP_CodGen_B.ContourPtIdx <
                       DT24_CVADAS_AP_CodGen_B.NumberOfIterations)) {
    DT24_CVADAS_AP_CodGen_B.q0 = DT24_CVADAS_AP_CodGen_B.ContourPtIdx - 1;
    guard1 = false;
    if (DT24_CVADAS_AP_CodGen_DW.current_point_y <=
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.q0])
    {
      DT24_CVADAS_AP_CodGen_B.i12 = 1;
      if (1 < 0) {
        DT24_CVADAS_AP_CodGen_B.i12 = 0;
      }

      DT24_CVADAS_AP_CodGen_B.i_m = (int32_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.ContourPtIdx + DT24_CVADAS_AP_CodGen_B.i12);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i_m > 255U) {
        DT24_CVADAS_AP_CodGen_B.i_m = 255;
      }

      if ((DT24_CVADAS_AP_CodGen_DW.current_point_y >=
           DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.i_m
           - 1]) && DT24_CVADAS_AP_CodGen_DW.ObjInFront) {
        DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }

    if (guard1) {
      DT24_CVADAS_AP_CodGen_B.i12 = 1;
      if (1 < 0) {
        DT24_CVADAS_AP_CodGen_B.i12 = 0;
      }

      DT24_CVADAS_AP_CodGen_B.i_m = (int32_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.ContourPtIdx + DT24_CVADAS_AP_CodGen_B.i12);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i_m > 255U) {
        DT24_CVADAS_AP_CodGen_B.i_m = 255;
      }

      DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput =
        ((DT24_CVADAS_AP_CodGen_DW.current_point_y >=
          DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.q0])
         && ((DT24_CVADAS_AP_CodGen_DW.current_point_y <=
              DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.i_m
              - 1]) && (!DT24_CVADAS_AP_CodGen_DW.ObjInFront)));
    }

    if (DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput) {
      DT24_CVADAS_AP_CodGen_B.i_m =
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.q0]
        - DT24_CVADAS_AP_CodGen_DW.current_point_y;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
          DT24_CVADAS_AP_CodGen_B.i_m = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_B.Nominator = (real32_T)DT24_CVADAS_AP_CodGen_B.i_m;
      DT24_CVADAS_AP_CodGen_B.i12 = 1;
      if (1 < 0) {
        DT24_CVADAS_AP_CodGen_B.i12 = 0;
      }

      DT24_CVADAS_AP_CodGen_B.i_m = (int32_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.ContourPtIdx + DT24_CVADAS_AP_CodGen_B.i12);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i_m > 255U) {
        DT24_CVADAS_AP_CodGen_B.i_m = 255;
      }

      DT24_CVADAS_AP_CodGen_B.i_m =
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.q0]
        - DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[DT24_CVADAS_AP_CodGen_B.i_m
        - 1];
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
          DT24_CVADAS_AP_CodGen_B.i_m = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_B.Denominator = (real32_T)
        DT24_CVADAS_AP_CodGen_B.i_m;
      DT24_CVADAS_AP_CodGen_B.Switch_l = fabsf
        (DT24_CVADAS_AP_CodGen_B.Denominator);
      DT24_CVADAS_AP_CodGen_B.RelationalOperator_a =
        (DT24_CVADAS_AP_CodGen_B.Switch_l > 0.0001F);
      if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_a) {
        DT24_CVADAS_AP_CodGen_B.Switch_l = DT24_CVADAS_AP_CodGen_B.Denominator;
      } else {
        DT24_CVADAS_AP_CodGen_B.Switch_l = 0.0001F;
      }

      DT24_CVADAS_AP_CodGen_B.DivResult = DT24_CVADAS_AP_CodGen_B.Nominator /
        DT24_CVADAS_AP_CodGen_B.Switch_l;
      DT24_CVADAS_AP_CodGen_B.i12 = 1;
      if (1 < 0) {
        DT24_CVADAS_AP_CodGen_B.i12 = 0;
      }

      DT24_CVADAS_AP_CodGen_B.i_m = (int32_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.ContourPtIdx + DT24_CVADAS_AP_CodGen_B.i12);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.i_m > 255U) {
        DT24_CVADAS_AP_CodGen_B.i_m = 255;
      }

      DT24_CVADAS_AP_CodGen_B.i_m =
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[DT24_CVADAS_AP_CodGen_B.q0]
        - DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[DT24_CVADAS_AP_CodGen_B.i_m
        - 1];
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
          DT24_CVADAS_AP_CodGen_B.i_m = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_B.f2 = roundf(DT24_CVADAS_AP_CodGen_B.DivResult *
        (real32_T)DT24_CVADAS_AP_CodGen_B.i_m);
      DT24_CVADAS_AP_CodGen_B.q0 =
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[DT24_CVADAS_AP_CodGen_B.q0]
        - DT24_CVADAS_AP_CodGen_DW.current_point_x;
      if (DT24_CVADAS_AP_CodGen_B.q0 > 32767) {
        DT24_CVADAS_AP_CodGen_B.q0 = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.q0 < -32768) {
          DT24_CVADAS_AP_CodGen_B.q0 = -32768;
        }
      }

      if (DT24_CVADAS_AP_CodGen_B.f2 < 32768.0F) {
        if (DT24_CVADAS_AP_CodGen_B.f2 >= -32768.0F) {
          DT24_CVADAS_AP_CodGen_B.i11 = (int16_T)DT24_CVADAS_AP_CodGen_B.f2;
        } else {
          DT24_CVADAS_AP_CodGen_B.i11 = MIN_int16_T;
        }
      } else {
        DT24_CVADAS_AP_CodGen_B.i11 = MAX_int16_T;
      }

      DT24_CVADAS_AP_CodGen_B.q0 = DT24_CVADAS_AP_CodGen_B.i11 -
        DT24_CVADAS_AP_CodGen_B.q0;
      if (DT24_CVADAS_AP_CodGen_B.q0 > 32767) {
        DT24_CVADAS_AP_CodGen_B.q0 = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.q0 < -32768) {
          DT24_CVADAS_AP_CodGen_B.q0 = -32768;
        }
      }

      DT24_CVADAS_AP_CodGen_DW.DistanceToObject = (int16_T)
        DT24_CVADAS_AP_CodGen_B.q0;
      DT24_CVADAS_AP_CodGen_IsValidObjectDistance();
      exitg1 = true;
    } else {
      DT24_CVADAS_AP_CodGen_B.i12 = 1;
      if (1 < 0) {
        DT24_CVADAS_AP_CodGen_B.i12 = 0;
      }

      DT24_CVADAS_AP_CodGen_B.q0 = (int32_T)((uint32_T)
        DT24_CVADAS_AP_CodGen_B.ContourPtIdx + DT24_CVADAS_AP_CodGen_B.i12);
      if ((uint32_T)DT24_CVADAS_AP_CodGen_B.q0 > 255U) {
        DT24_CVADAS_AP_CodGen_B.q0 = 255;
      }

      DT24_CVADAS_AP_CodGen_B.ContourPtIdx = (uint8_T)DT24_CVADAS_AP_CodGen_B.q0;
    }
  }

  if (DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill_m) {
    DT24_CVADAS_AP_CodGen_B.NumberOfIterations = KeAP_cnt_StndStillPntConfThd;
    DT24_CVADAS_AP_CodGen_B.ContourPtIdx = KeAP_cnt_StndStillCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjMinDistThd = KeAP_cm_StndStillObjMinDistThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntConfThd =
      KeAP_cnt_StndStillSidePntConfThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntCruiseAgeThd =
      KeAP_cnt_StndStSideCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntConfThd =
      KeAP_cnt_StndStillSideLowPntConfThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntCruiseAgeThd =
      KeAP_cnt_StndStSideLowCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjHighPntConfThd =
      KeAP_cnt_DensStdStlHighPntConfThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjLowPntConfThd =
      KeAP_cnt_DensStdStlLowPntConfThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjPntCruiseAgeThd =
      KeAP_cnt_DensStdStlObjCruiseAgeThd;
  } else {
    DT24_CVADAS_AP_CodGen_B.NumberOfIterations = KeAP_cnt_VIMGhstObjPntConfThd;
    DT24_CVADAS_AP_CodGen_B.ContourPtIdx = KeAP_cnt_VIMGhstObjCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjMinDistThd = KeAP_cm_VIMGhstObjMinDistThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntConfThd =
      KeAP_cnt_VIMSidePntConfThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntCruiseAgeThd =
      KeAP_cnt_VIMSideObjCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntConfThd =
      KeAP_cnt_VIMSideLowPntConfThd;
    DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntCruiseAgeThd =
      KeAP_cnt_VIMSideObjLowCruiseAgeThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjHighPntConfThd =
      KeAP_cnt_DensVIMHighPntConfThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjLowPntConfThd =
      KeAP_cnt_DensVIMLowPntConfThd;
    DT24_CVADAS_AP_CodGen_B.DensGhstObjPntCruiseAgeThd =
      KeAP_cnt_DensVIMObjCruiseAgeThd;
  }

  DT24_CVADAS_AP_CodGen_B.q0 = DT24_CVADAS_AP_CodGen_DW.point_index - 1;
  guard1 = false;
  guard2 = false;
  guard3 = false;
  guard4 = false;
  guard5 = false;
  guard6 = false;
  guard7 = false;
  guard8 = false;
  if ((DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
       .height != 2) &&
      (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
       .height != 0) &&
      (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
       .Cruising_Age > DT24_CVADAS_AP_CodGen_B.ContourPtIdx) &&
      (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
       .confidence < DT24_CVADAS_AP_CodGen_B.NumberOfIterations)) {
    if (DT24_CVADAS_AP_CodGen_DW.DistanceToObject < 0) {
      DT24_CVADAS_AP_CodGen_B.i_m = -DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      }

      DT24_CVADAS_AP_CodGen_B.i11 = (int16_T)DT24_CVADAS_AP_CodGen_B.i_m;
    } else {
      DT24_CVADAS_AP_CodGen_B.i11 = DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    }

    if (DT24_CVADAS_AP_CodGen_B.i11 > DT24_CVADAS_AP_CodGen_B.GhstObjMinDistThd)
    {
      guard2 = true;
    } else {
      guard8 = true;
    }
  } else {
    guard8 = true;
  }

  if (guard8) {
    if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
        .y > DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd) {
      /* Constant: '<S88>/Constant1' */
      DT24_CVADAS_AP_CodGen_B.i_m = DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd +
        KeAP_cm_WarnOffset;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
          DT24_CVADAS_AP_CodGen_B.i_m = -32768;
        }
      }

      if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .y <= DT24_CVADAS_AP_CodGen_B.i_m) {
        guard6 = true;
      } else {
        guard7 = true;
      }
    } else {
      guard7 = true;
    }
  }

  if (guard7) {
    /* Constant: '<S88>/Constant1' */
    DT24_CVADAS_AP_CodGen_B.i_m = DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd +
      KeAP_cm_WarnOffset;
    if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
      DT24_CVADAS_AP_CodGen_B.i_m = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
        DT24_CVADAS_AP_CodGen_B.i_m = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.i_m = -DT24_CVADAS_AP_CodGen_B.i_m;
    if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
      DT24_CVADAS_AP_CodGen_B.i_m = 32767;
    }

    if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
        .y >= DT24_CVADAS_AP_CodGen_B.i_m) {
      DT24_CVADAS_AP_CodGen_B.i_m = -DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      }

      if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .y < DT24_CVADAS_AP_CodGen_B.i_m) {
        guard6 = true;
      } else {
        guard5 = true;
      }
    } else {
      guard5 = true;
    }
  }

  if (guard6) {
    if ((DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .height == 1) &&
        (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .Cruising_Age > DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntCruiseAgeThd) &&
        (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .confidence < DT24_CVADAS_AP_CodGen_B.GhstObjSideLowPntConfThd)) {
      guard2 = true;
    } else {
      guard5 = true;
    }
  }

  if (guard5) {
    if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
        .y > DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd) {
      /* Constant: '<S88>/Constant1' */
      DT24_CVADAS_AP_CodGen_B.i_m = DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd +
        KeAP_cm_WarnOffset;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      } else {
        if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
          DT24_CVADAS_AP_CodGen_B.i_m = -32768;
        }
      }

      if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .y <= DT24_CVADAS_AP_CodGen_B.i_m) {
        guard3 = true;
      } else {
        guard4 = true;
      }
    } else {
      guard4 = true;
    }
  }

  if (guard4) {
    /* Constant: '<S88>/Constant1' */
    DT24_CVADAS_AP_CodGen_B.i_m = DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd +
      KeAP_cm_WarnOffset;
    if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
      DT24_CVADAS_AP_CodGen_B.i_m = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.i_m < -32768) {
        DT24_CVADAS_AP_CodGen_B.i_m = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.i_m = -DT24_CVADAS_AP_CodGen_B.i_m;
    if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
      DT24_CVADAS_AP_CodGen_B.i_m = 32767;
    }

    if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
        .y >= DT24_CVADAS_AP_CodGen_B.i_m) {
      DT24_CVADAS_AP_CodGen_B.i_m = -DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd;
      if (DT24_CVADAS_AP_CodGen_B.i_m > 32767) {
        DT24_CVADAS_AP_CodGen_B.i_m = 32767;
      }

      if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .y < DT24_CVADAS_AP_CodGen_B.i_m) {
        guard3 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard1 = true;
    }
  }

  if (guard3) {
    if ((DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .height != 1) &&
        (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .Cruising_Age > DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntCruiseAgeThd)
        &&
        (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .confidence < DT24_CVADAS_AP_CodGen_B.GhstObjSideHighPntConfThd)) {
      guard2 = true;
    } else {
      guard1 = true;
    }
  }

  if (guard2) {
    if (KeAP_b_CruisAgeBasedGhsObjDet) {
      DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput = true;
    } else {
      guard1 = true;
    }
  }

  if (guard1) {
    if (((DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .confidence < DT24_CVADAS_AP_CodGen_B.DensGhstObjHighPntConfThd) &&
         (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .height != 1)) ||
        ((DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .confidence < DT24_CVADAS_AP_CodGen_B.DensGhstObjLowPntConfThd) &&
         (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .height == 1))) {
      /* Constant: '<S88>/Constant4' incorporates:
       *  Constant: '<S88>/Constant5'
       */
      DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput =
        (((DT24_CVADAS_AP_CodGen_DW.ObjInFront && false) ||
          ((!DT24_CVADAS_AP_CodGen_DW.ObjInFront) && false)) &&
         KeAP_b_DensityBasedGhstObjDet);
    } else if
        (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
         .Cruising_Age > DT24_CVADAS_AP_CodGen_B.DensGhstObjPntCruiseAgeThd) {
      if (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.q0]
          .age > DT24_CVADAS_AP_CodGen_B.DensGhstObjPntCruiseAgeThd) {
        /* Constant: '<S88>/Constant4' incorporates:
         *  Constant: '<S88>/Constant5'
         */
        DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput =
          (((DT24_CVADAS_AP_CodGen_DW.ObjInFront && false) ||
            ((!DT24_CVADAS_AP_CodGen_DW.ObjInFront) && false)) &&
           KeAP_b_DensityBasedGhstObjDet);
      } else {
        DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput = false;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput = false;
    }
  }

  if (DT24_CVADAS_AP_CodGen_B.b_sf_internal_predicateOutput) {
    if (DT24_CVADAS_AP_CodGen_DW.ObjInFront) {
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject =
        DT24_CVADAS_AP_CodGen_DW.MaxDist;
    } else {
      DT24_CVADAS_AP_CodGen_B.q0 = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
      if (DT24_CVADAS_AP_CodGen_B.q0 > 32767) {
        DT24_CVADAS_AP_CodGen_B.q0 = 32767;
      }

      DT24_CVADAS_AP_CodGen_DW.DistanceToObject = (int16_T)
        DT24_CVADAS_AP_CodGen_B.q0;
    }
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_CheckNeaighbourHoodForRegions(void)
{
  if (KePA_b_EnFeatPointSplitImp != 0) {
    DT24_CVADAS_AP_CodGen_DW.Current_Pt.x =
      DT24_CVADAS_AP_CodGen_DW.current_point_x;
    DT24_CVADAS_AP_CodGen_DW.Current_Pt.y =
      DT24_CVADAS_AP_CodGen_DW.current_point_y;
    DT24_CVADAS_AP_CodGen_DW.Current_Pt.confidence =
      DT24_CVADAS_AP_CodGen_DW.current_point_confidence;
    memcpy(&DT24_CVADAS_AP_CodGen_B.PointMapData[0],
           &DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[0], 96U * sizeof
           (US_S_PointOutputBuff_t));
    DT24_CVADAS_AP_CodGen_B.CurrentPoint = DT24_CVADAS_AP_CodGen_DW.Current_Pt;
    DT24_CVADAS_AP_CodGen_B.EgoPtHeight =
      DT24_CVADAS_AP_CodGen_DW.current_point_height;

    /* Outputs for Function Call SubSystem: '<S91>/NeighbourHoodCheck' */
    DT24_CVADAS_AP_CodGen_NeighbourHoodCheck
      (DT24_CVADAS_AP_CodGen_B.PointMapData,
       &DT24_CVADAS_AP_CodGen_B.CurrentPoint,
       DT24_CVADAS_AP_CodGen_B.EgoPtHeight,
       &DT24_CVADAS_AP_CodGen_B.OutportBufferForDiscardPoint,
       &DT24_CVADAS_AP_CodGen_B.NeighbourHoodCheck);

    /* End of Outputs for SubSystem: '<S91>/NeighbourHoodCheck' */
    if (DT24_CVADAS_AP_CodGen_B.OutportBufferForDiscardPoint) {
      if (DT24_CVADAS_AP_CodGen_DW.ObjInFront) {
        DT24_CVADAS_AP_CodGen_DW.DistanceToObject =
          DT24_CVADAS_AP_CodGen_DW.MaxDist;
      } else {
        DT24_CVADAS_AP_CodGen_B.i10 = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
        if (DT24_CVADAS_AP_CodGen_B.i10 > 32767) {
          DT24_CVADAS_AP_CodGen_B.i10 = 32767;
        }

        DT24_CVADAS_AP_CodGen_DW.DistanceToObject = (int16_T)
          DT24_CVADAS_AP_CodGen_B.i10;
      }
    }
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_GetObjectPointRegion(void)
{
  DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 =
    (DT24_CVADAS_AP_CodGen_DW.current_point_x > 0);
  DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_2 =
    (DT24_CVADAS_AP_CodGen_DW.current_point_x < 0);
  DT24_CVADAS_AP_CodGen_B.i9 = -DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd;
  if (DT24_CVADAS_AP_CodGen_B.i9 > 32767) {
    DT24_CVADAS_AP_CodGen_B.i9 = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.b = ((DT24_CVADAS_AP_CodGen_DW.current_point_y >=
    DT24_CVADAS_AP_CodGen_B.i9) && (DT24_CVADAS_AP_CodGen_DW.current_point_y <=
    DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd));

  /* Constant: '<S88>/Constant1' */
  DT24_CVADAS_AP_CodGen_B.i9 = DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd +
    KeAP_cm_WarnOffset;
  DT24_CVADAS_AP_CodGen_B.i8 = DT24_CVADAS_AP_CodGen_B.i9;
  if (DT24_CVADAS_AP_CodGen_B.i9 > 32767) {
    DT24_CVADAS_AP_CodGen_B.i8 = 32767;
    DT24_CVADAS_AP_CodGen_B.i9 = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.i9 < -32768) {
      DT24_CVADAS_AP_CodGen_B.i8 = -32768;
    }

    if (DT24_CVADAS_AP_CodGen_B.i9 < -32768) {
      DT24_CVADAS_AP_CodGen_B.i9 = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.c = ((DT24_CVADAS_AP_CodGen_DW.current_point_y >
    DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd) &&
    (DT24_CVADAS_AP_CodGen_DW.current_point_y <= DT24_CVADAS_AP_CodGen_B.i8));
  DT24_CVADAS_AP_CodGen_B.i9 = -DT24_CVADAS_AP_CodGen_B.i9;
  if (DT24_CVADAS_AP_CodGen_B.i9 > 32767) {
    DT24_CVADAS_AP_CodGen_B.i9 = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.i8 = -DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd;
  if (DT24_CVADAS_AP_CodGen_B.i8 > 32767) {
    DT24_CVADAS_AP_CodGen_B.i8 = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.d_g = ((DT24_CVADAS_AP_CodGen_DW.current_point_y >=
    DT24_CVADAS_AP_CodGen_B.i9) && (DT24_CVADAS_AP_CodGen_DW.current_point_y <
    DT24_CVADAS_AP_CodGen_B.i8));
  DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 =
    (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2);
  DT24_CVADAS_AP_CodGen_B.e = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject <
    DT24_CVADAS_AP_CodGen_DW.PrevCenterFront_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFront == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  DT24_CVADAS_AP_CodGen_B.f_g = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject <
    DT24_CVADAS_AP_CodGen_DW.PrevLeftFront_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFL == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  DT24_CVADAS_AP_CodGen_B.g = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject <
    DT24_CVADAS_AP_CodGen_DW.PrevRightFront_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFR == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  DT24_CVADAS_AP_CodGen_B.h = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject >
    DT24_CVADAS_AP_CodGen_DW.PrevCenterRear_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRear == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  DT24_CVADAS_AP_CodGen_B.i_me = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject >
    DT24_CVADAS_AP_CodGen_DW.PrevLeftRear_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRL == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  DT24_CVADAS_AP_CodGen_B.j = ((DT24_CVADAS_AP_CodGen_DW.DistanceToObject >
    DT24_CVADAS_AP_CodGen_DW.PrevRightRear_MeAP_cm_ObjXPon) ||
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRR == 0) &&
     (DT24_CVADAS_AP_CodGen_DW.current_point_height == 2)));
  if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
      DT24_CVADAS_AP_CodGen_B.b &&
      DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
      DT24_CVADAS_AP_CodGen_B.e) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevCenterFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist;
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFront = 1U;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.x =
      DT24_CVADAS_AP_CodGen_DW.current_point_x;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.y =
      DT24_CVADAS_AP_CodGen_DW.current_point_y;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.confidence =
      DT24_CVADAS_AP_CodGen_DW.current_point_confidence;
  } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
             DT24_CVADAS_AP_CodGen_B.b &&
             (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFront == 0) &&
             DT24_CVADAS_AP_CodGen_B.e) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevCenterFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.x =
      DT24_CVADAS_AP_CodGen_DW.current_point_x;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.y =
      DT24_CVADAS_AP_CodGen_DW.current_point_y;
    DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt.confidence =
      DT24_CVADAS_AP_CodGen_DW.current_point_confidence;
  } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
             DT24_CVADAS_AP_CodGen_B.c &&
             DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
             DT24_CVADAS_AP_CodGen_B.f_g) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevLeftFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist;
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFL = 1U;
  } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
             DT24_CVADAS_AP_CodGen_B.c &&
             (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFL == 0) &&
             DT24_CVADAS_AP_CodGen_B.f_g) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevLeftFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist;
  } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
             DT24_CVADAS_AP_CodGen_B.d_g &&
             DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
             DT24_CVADAS_AP_CodGen_B.g) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevRightFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist;
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFR = 1U;
  } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
             DT24_CVADAS_AP_CodGen_B.d_g &&
             (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFR == 0) &&
             DT24_CVADAS_AP_CodGen_B.g) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
    DT24_CVADAS_AP_CodGen_DW.PrevRightFront_MeAP_cm_ObjXPon =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 =
      (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_2 &&
       DT24_CVADAS_AP_CodGen_B.b);
    if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
        DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
        DT24_CVADAS_AP_CodGen_B.h) {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist =
        DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
      DT24_CVADAS_AP_CodGen_DW.PrevCenterRear_MeAP_cm_ObjXPon =
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist;
      DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRear = 1U;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.x =
        DT24_CVADAS_AP_CodGen_DW.current_point_x;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.y =
        DT24_CVADAS_AP_CodGen_DW.current_point_y;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.confidence =
        DT24_CVADAS_AP_CodGen_DW.current_point_confidence;
    } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
               (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRear == 0) &&
               DT24_CVADAS_AP_CodGen_B.h) {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist =
        DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
      DT24_CVADAS_AP_CodGen_DW.PrevCenterRear_MeAP_cm_ObjXPon =
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.x =
        DT24_CVADAS_AP_CodGen_DW.current_point_x;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.y =
        DT24_CVADAS_AP_CodGen_DW.current_point_y;
      DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt.confidence =
        DT24_CVADAS_AP_CodGen_DW.current_point_confidence;
    } else {
      DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 =
        (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_2 &&
         DT24_CVADAS_AP_CodGen_B.c);
      if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
          DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
          DT24_CVADAS_AP_CodGen_B.i_me) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist =
          DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
        DT24_CVADAS_AP_CodGen_DW.PrevLeftRear_MeAP_cm_ObjXPon =
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist;
        DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRL = 1U;
      } else if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
                 (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRL == 0) &&
                 DT24_CVADAS_AP_CodGen_B.i_me) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist =
          DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
        DT24_CVADAS_AP_CodGen_DW.PrevLeftRear_MeAP_cm_ObjXPon =
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist;
      } else {
        DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 =
          (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_2 &&
           DT24_CVADAS_AP_CodGen_B.d_g);
        if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
            DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_6 &&
            DT24_CVADAS_AP_CodGen_B.j) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist =
            DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
          DT24_CVADAS_AP_CodGen_DW.PrevRightRear_MeAP_cm_ObjXPon =
            DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist;
          DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRR = 1U;
        } else {
          if (DT24_CVADAS_AP_CodGen_B.aVarTruthTableCondition_1 &&
              (DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRR == 0) &&
              DT24_CVADAS_AP_CodGen_B.j) {
            DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist =
              DT24_CVADAS_AP_CodGen_DW.DistanceToObject;
            DT24_CVADAS_AP_CodGen_DW.PrevRightRear_MeAP_cm_ObjXPon =
              DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist;
          }
        }
      }
    }
  }
}

/* Function for Chart: '<S88>/CalculateMinDistances1' */
static void DT24_CVADAS_AP_CodGen_GetCenterRegionPoints(void)
{
  int32_T tmp;
  tmp = -DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd;
  if (tmp > 32767) {
    tmp = 32767;
  }

  if ((DT24_CVADAS_AP_CodGen_DW.current_point_y <=
       DT24_CVADAS_AP_CodGen_DW.CenterRegionThsd) &&
      (DT24_CVADAS_AP_CodGen_DW.current_point_y >= tmp)) {
    tmp = DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[2] + 130;
    if (tmp > 32767) {
      tmp = 32767;
    }

    if ((DT24_CVADAS_AP_CodGen_DW.current_point_x > 0) &&
        ((DT24_CVADAS_AP_CodGen_DW.current_point_x < tmp) &&
         (DT24_CVADAS_AP_CodGen_DW.FrontIdx < 10))) {
      tmp = (int32_T)(DT24_CVADAS_AP_CodGen_DW.FrontIdx + 1U);
      if ((uint32_T)tmp > 255U) {
        tmp = 255;
      }

      DT24_CVADAS_AP_CodGen_DW.FrontIdx = (uint8_T)tmp;
      DT24_CVADAS_AP_CodGen_DW.FrontPointsArray[DT24_CVADAS_AP_CodGen_DW.FrontIdx
        - 1] = DT24_CVADAS_AP_CodGen_DW.point_index;
    } else {
      tmp = DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[10] -
        115;
      if (tmp < -32768) {
        tmp = -32768;
      }

      if ((DT24_CVADAS_AP_CodGen_DW.current_point_x < 0) &&
          ((DT24_CVADAS_AP_CodGen_DW.current_point_x > tmp) &&
           (DT24_CVADAS_AP_CodGen_DW.RearIdx < 10))) {
        tmp = (int32_T)(DT24_CVADAS_AP_CodGen_DW.RearIdx + 1U);
        if ((uint32_T)tmp > 255U) {
          tmp = 255;
        }

        DT24_CVADAS_AP_CodGen_DW.RearIdx = (uint8_T)tmp;
        DT24_CVADAS_AP_CodGen_DW.RearPointsArray[DT24_CVADAS_AP_CodGen_DW.RearIdx
          - 1] = DT24_CVADAS_AP_CodGen_DW.point_index;
      }
    }
  }
}

 /*Kedar*/
boolean_T ReInitializeAPSMVC(void)
{
  boolean_T v_Ret_t = FALSE;
  static TeAutoPark_e_AutoParkStatus v_PrevAutoParkStatus_e = TeAutoPark_e_AutoParkStatus_Initialize;

  if ((TeAutoPark_e_AutoParkStatus_Complete == v_PrevAutoParkStatus_e) &&
      (TeAutoPark_e_AutoParkStatus_Standby == DriveAssistStatOut.IeAP_e_AutoParkStatus))
  {
    UART_printf("Initializing APSMVC\n");
    memset(&SWC_VC_B, 0, sizeof(SWC_VC_B));
    memset(&SWC_VC_DW, 0, sizeof(SWC_VC_DW));
    memset(&SWC_VC_PrevZCX, 0, sizeof(SWC_VC_PrevZCX));
    DT24_CVADAS_AP_CodGen_initialize();
    v_Ret_t = TRUE;
  }
  else if ((TeAutoPark_e_AutoParkStatus_Abort == v_PrevAutoParkStatus_e) &&
           (TeAutoPark_e_AutoParkStatus_Standby == DriveAssistStatOut.IeAP_e_AutoParkStatus))
  {
    UART_printf("Initializing APSMVC\n");
    memset(&SWC_VC_B, 0, sizeof(SWC_VC_B));
    memset(&SWC_VC_DW, 0, sizeof(SWC_VC_DW));
    memset(&SWC_VC_PrevZCX, 0, sizeof(SWC_VC_PrevZCX));
    DT24_CVADAS_AP_CodGen_initialize();
    v_Ret_t = TRUE;
  }
  else if ((TeAutoPark_e_AutoParkStatus_Fault == v_PrevAutoParkStatus_e) &&
           (TeAutoPark_e_AutoParkStatus_Standby == DriveAssistStatOut.IeAP_e_AutoParkStatus))
  {
    UART_printf("Initializing APSMVC\n");
    memset(&SWC_VC_B, 0, sizeof(SWC_VC_B));
    memset(&SWC_VC_DW, 0, sizeof(SWC_VC_DW));
    memset(&SWC_VC_PrevZCX, 0, sizeof(SWC_VC_PrevZCX));   
    DT24_CVADAS_AP_CodGen_initialize();
    v_Ret_t = TRUE;
  }
  v_PrevAutoParkStatus_e = DriveAssistStatOut.IeAP_e_AutoParkStatus;
  return v_Ret_t;
}
/* Model step function */
void DT24_CVADAS_AP_CodGen_step(void)
{
  /*Kedar*/
  if( TRUE == ReInitializeAPSMVC())
  {
    return;
  }
  int32_T exitg1;

  /* DataStoreRead: '<S2>/VehInpAdapter_opVehSignals_data' */
  SigMgr_ME_VehInp_to_IpcSignals_data_f_Get(&DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals);

  /* DataTypeConversion: '<S23>/Data Type Conversion32' */
  DS_WheelSpeed_RL =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHRWheelSpeed;

  /* DataTypeConversion: '<S23>/Data Type Conversion38' */
  DS_WheelSpeed_RR =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHRWheelSpeed;

  /* DataTypeConversion: '<S23>/Data Type Conversion89' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_10.CmdIgnSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion88' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_CmdIgnSts = (TeVBII_e_CmdIgnSts)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion7' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_FrntParkAsstReq =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_12.FT_PAMRequestSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion8' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ParkAsstReq =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_12.PAMRequestSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion9' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_RemoteStartActvSts =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_2.RemStActvSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion86' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_27.TrailerConnectionSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion11' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TrailerConnectionSts =
    (TeVBII_e_TrailerConnectionSts)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion12' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TrlrPrsntSts = (TeVBII_e_TrlrPrsntSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_29.ITBM_TrlrStat;

  /* DataTypeConversion: '<S23>/Data Type Conversion13' */
  DT24_CVADAS_AP_CodGen_B.K_e_RAEB_VehicleWidth_f =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.ExternalTemperature;

  /* DataTypeConversion: '<S23>/Data Type Conversion82' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_Brk_Stat;

  /* DataTypeConversion: '<S23>/Data Type Conversion14' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_BrkStat = (TeVBII_e_BrkStat)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion85' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_4.FD14_EPBSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion15' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_VehEPBSts = (TeVBII_e_VehEPBSts)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion5' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_DRIVETRAIN_FD_3.TCASERANGESTATUS;

  /* DataTypeConversion: '<S23>/Data Type Conversion16' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TCaseRangeSts = (TeVBII_e_TCaseRangeSts)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion6' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_ESS_ENG_ST_W;

  /* Switch: '<S23>/Switch' incorporates:
   *  Constant: '<S23>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr <= ((uint8_T)0U)) {
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr = ((uint8_T)15U);
  }

  /* End of Switch: '<S23>/Switch' */

  /* DataTypeConversion: '<S23>/Data Type Conversion17' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_EssEngState = (TeVBII_e_EssEngState)
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;

  /* DataTypeConversion: '<S23>/Data Type Conversion18' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolFrnt = (TeVBII_e_PamChimeVol)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.PamChimeVolumeFront;

  /* DataTypeConversion: '<S23>/Data Type Conversion19' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolRear = (TeVBII_e_PamChimeVol)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.PamChimeVolumeRear;

  /* DataTypeConversion: '<S23>/Data Type Conversion20' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_RearBrkAsst =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Rear_Brk_Asst
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion23' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TransSailingTst = (TeVBII_e_TransSailingTst)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TRANSM_FD_1.TransmissionSailingSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion22' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_GearRptState = (TeVBII_e_GearState)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TRANSM_FD_1.TargetGear;

  /* DataTypeConversion: '<S182>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_h = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_GearRptState;

  /* MultiPortSwitch: '<S182>/Multiport Switch' incorporates:
   *  Constant: '<S184>/Constant'
   *  Constant: '<S185>/Constant'
   *  Constant: '<S186>/Constant'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S188>/Constant'
   */
  switch (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_h) {
   case 0:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState =
      TeAP_e_FiltdGearState_Neutral;
    break;

   case 1:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 2:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 3:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 4:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 5:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 6:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 7:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 8:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 9:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_Drive;
    break;

   case 13:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState =
      TeAP_e_FiltdGearState_Parking;
    break;

   case 14:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState =
      TeAP_e_FiltdGearState_ReverseGear;
    break;

   default:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S182>/Multiport Switch' */

  /* RelationalOperator: '<S183>/Relational Operator1' incorporates:
   *  Constant: '<S189>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_DriverDoorSts =
    (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
     TeAP_e_FiltdGearState_Drive);

  /* UnitDelay: '<S183>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_m;

  /* RelationalOperator: '<S183>/Relational Operator6' incorporates:
   *  Constant: '<S202>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator6 =
    (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
     TeAP_e_FiltdGearState_ReverseGear);

  /* UnitDelay: '<S205>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_c;

  /* Logic: '<S205>/Logical Operator9' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt =
    !DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt;

  /* Logic: '<S205>/Logical Operator8' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt =
    (DT24_CVADAS_AP_CodGen_B.RelationalOperator6 &&
     DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt);

  /* UnitDelay: '<S203>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_h5;

  /* Switch: '<S203>/Switch2' */
  DT24_CVADAS_AP_CodGen_B.Switch2_b =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt ||
     DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts);

  /* UnitDelay: '<S203>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay2 =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_m;

  /* Switch: '<S203>/Switch3' incorporates:
   *  Constant: '<S183>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt) {
    DT24_CVADAS_AP_CodGen_B.count = KeAP_Cnt_GearFiltTimeThd;
  } else {
    /* RelationalOperator: '<S203>/Relational Operator' incorporates:
     *  Constant: '<S183>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_d = (KeAP_cnt_TimeStep <=
      DT24_CVADAS_AP_CodGen_B.UnitDelay2);

    /* Switch: '<S203>/Switch1' incorporates:
     *  Constant: '<S203>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_d) {
      /* Sum: '<S203>/Subtract' incorporates:
       *  Constant: '<S183>/Constant'
       */
      DT24_CVADAS_AP_CodGen_B.Subtract_f = (uint16_T)
        (DT24_CVADAS_AP_CodGen_B.UnitDelay2 - KeAP_cnt_TimeStep);
      DT24_CVADAS_AP_CodGen_B.Switch1_b = DT24_CVADAS_AP_CodGen_B.Subtract_f;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_b = ((uint16_T)0U);
    }

    /* End of Switch: '<S203>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.count = DT24_CVADAS_AP_CodGen_B.Switch1_b;
  }

  /* End of Switch: '<S203>/Switch3' */

  /* RelationalOperator: '<S203>/Relational Operator1' incorporates:
   *  Constant: '<S183>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.overflow = (KeAP_cnt_TimeStep >
    DT24_CVADAS_AP_CodGen_B.count);

  /* RelationalOperator: '<S183>/Relational Operator8' incorporates:
   *  Constant: '<S192>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator8 =
    (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
     TeAP_e_FiltdGearState_Neutral);

  /* UnitDelay: '<S206>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_p;

  /* Logic: '<S206>/Logical Operator9' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts =
    !DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts;

  /* Logic: '<S206>/Logical Operator8' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts =
    (DT24_CVADAS_AP_CodGen_B.RelationalOperator8 &&
     DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts);

  /* UnitDelay: '<S204>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_d;

  /* Switch: '<S204>/Switch2' */
  DT24_CVADAS_AP_CodGen_B.Switch2_e =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts ||
     DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt);

  /* UnitDelay: '<S204>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay2_c =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_c;

  /* Switch: '<S204>/Switch3' incorporates:
   *  Constant: '<S183>/Constant3'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts) {
    DT24_CVADAS_AP_CodGen_B.count_d = KeAP_Cnt_GearFiltTimeThd;
  } else {
    /* RelationalOperator: '<S204>/Relational Operator' incorporates:
     *  Constant: '<S183>/Constant2'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator = (KeAP_cnt_TimeStep <=
      DT24_CVADAS_AP_CodGen_B.UnitDelay2_c);

    /* Switch: '<S204>/Switch1' incorporates:
     *  Constant: '<S204>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator) {
      /* Sum: '<S204>/Subtract' incorporates:
       *  Constant: '<S183>/Constant2'
       */
      DT24_CVADAS_AP_CodGen_B.Subtract_n = (uint16_T)
        (DT24_CVADAS_AP_CodGen_B.UnitDelay2_c - KeAP_cnt_TimeStep);
      DT24_CVADAS_AP_CodGen_B.Switch1_o = DT24_CVADAS_AP_CodGen_B.Subtract_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_o = ((uint16_T)0U);
    }

    /* End of Switch: '<S204>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.count_d = DT24_CVADAS_AP_CodGen_B.Switch1_o;
  }

  /* End of Switch: '<S204>/Switch3' */

  /* RelationalOperator: '<S204>/Relational Operator1' incorporates:
   *  Constant: '<S183>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.overflow_h = (KeAP_cnt_TimeStep >
    DT24_CVADAS_AP_CodGen_B.count_d);

  /* Switch: '<S183>/Switch' incorporates:
   *  Constant: '<S197>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeVBII_b_DriverDoorSts) {
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k =
      TeAP_e_FiltdGearState_Drive;
  } else {
    /* RelationalOperator: '<S183>/Relational Operator2' incorporates:
     *  Constant: '<S195>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator2 =
      (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
       TeAP_e_FiltdGearState_Parking);

    /* Switch: '<S183>/Switch1' incorporates:
     *  Constant: '<S198>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator2) {
      DT24_CVADAS_AP_CodGen_B.Switch1_j = TeAP_e_FiltdGearState_Parking;
    } else {
      /* RelationalOperator: '<S183>/Relational Operator3' incorporates:
       *  Constant: '<S196>/Constant'
       */
      DT24_CVADAS_AP_CodGen_B.RelationalOperator3 =
        (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
         TeAP_e_FiltdGearState_ReverseGear);

      /* Switch: '<S183>/Switch2' */
      if (DT24_CVADAS_AP_CodGen_B.RelationalOperator3) {
        /* RelationalOperator: '<S183>/Relational Operator5' incorporates:
         *  Constant: '<S201>/Constant'
         */
        DT24_CVADAS_AP_CodGen_B.RelationalOperator5 =
          (DT24_CVADAS_AP_CodGen_B.UnitDelay == TeAP_e_FiltdGearState_Neutral);

        /* Logic: '<S203>/Logical Operator8' */
        DT24_CVADAS_AP_CodGen_B.LogicalOperator_a =
          (DT24_CVADAS_AP_CodGen_B.Switch2_b && DT24_CVADAS_AP_CodGen_B.overflow);

        /* Logic: '<S203>/Logical Operator' */
        DT24_CVADAS_AP_CodGen_B.LogicalOperator_a =
          (DT24_CVADAS_AP_CodGen_B.RelationalOperator6 &&
           DT24_CVADAS_AP_CodGen_B.LogicalOperator_a);

        /* Logic: '<S183>/Logical Operator' */
        DT24_CVADAS_AP_CodGen_B.LogicalOperator_a =
          (DT24_CVADAS_AP_CodGen_B.LogicalOperator_a ||
           DT24_CVADAS_AP_CodGen_B.RelationalOperator5);

        /* Switch: '<S183>/Switch3' incorporates:
         *  Constant: '<S200>/Constant'
         */
        if (DT24_CVADAS_AP_CodGen_B.LogicalOperator_a) {
          DT24_CVADAS_AP_CodGen_B.Switch3_f = TeAP_e_FiltdGearState_ReverseGear;
        } else {
          DT24_CVADAS_AP_CodGen_B.Switch3_f = DT24_CVADAS_AP_CodGen_B.UnitDelay;
        }

        /* End of Switch: '<S183>/Switch3' */
        DT24_CVADAS_AP_CodGen_B.Switch2 = DT24_CVADAS_AP_CodGen_B.Switch3_f;
      } else {
        /* RelationalOperator: '<S183>/Relational Operator4' incorporates:
         *  Constant: '<S199>/Constant'
         */
        DT24_CVADAS_AP_CodGen_B.RelationalOperator4_l =
          (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState ==
           TeAP_e_FiltdGearState_Neutral);

        /* Switch: '<S183>/Switch4' */
        if (DT24_CVADAS_AP_CodGen_B.RelationalOperator4_l) {
          /* RelationalOperator: '<S183>/Relational Operator7' incorporates:
           *  Constant: '<S191>/Constant'
           */
          DT24_CVADAS_AP_CodGen_B.RelationalOperator7 =
            (DT24_CVADAS_AP_CodGen_B.UnitDelay ==
             TeAP_e_FiltdGearState_ReverseGear);

          /* Logic: '<S204>/Logical Operator8' */
          DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c =
            (DT24_CVADAS_AP_CodGen_B.Switch2_e &&
             DT24_CVADAS_AP_CodGen_B.overflow_h);

          /* Logic: '<S204>/Logical Operator' */
          DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c =
            (DT24_CVADAS_AP_CodGen_B.RelationalOperator8 &&
             DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c);

          /* Logic: '<S183>/Logical Operator1' */
          DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c =
            (DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c ||
             DT24_CVADAS_AP_CodGen_B.RelationalOperator7);

          /* Switch: '<S183>/Switch5' */
          if (DT24_CVADAS_AP_CodGen_B.LogicalOperator1_c) {
            /* RelationalOperator: '<S183>/Relational Operator9' incorporates:
             *  Constant: '<S193>/Constant'
             */
            DT24_CVADAS_AP_CodGen_B.RelationalOperator9 =
              (DT24_CVADAS_AP_CodGen_B.IeVBII_e_TransSailingTst ==
               TeVBII_e_TransSailingTst_Sailing_Active);

            /* Switch: '<S183>/Switch6' incorporates:
             *  Constant: '<S190>/Constant'
             *  Constant: '<S194>/Constant'
             */
            if (DT24_CVADAS_AP_CodGen_B.RelationalOperator9) {
              DT24_CVADAS_AP_CodGen_B.Switch6 = TeAP_e_FiltdGearState_Drive;
            } else {
              DT24_CVADAS_AP_CodGen_B.Switch6 = TeAP_e_FiltdGearState_Neutral;
            }

            /* End of Switch: '<S183>/Switch6' */
            DT24_CVADAS_AP_CodGen_B.Switch5_m = DT24_CVADAS_AP_CodGen_B.Switch6;
          } else {
            DT24_CVADAS_AP_CodGen_B.Switch5_m =
              DT24_CVADAS_AP_CodGen_B.UnitDelay;
          }

          /* End of Switch: '<S183>/Switch5' */
          DT24_CVADAS_AP_CodGen_B.Switch4 = DT24_CVADAS_AP_CodGen_B.Switch5_m;
        } else {
          DT24_CVADAS_AP_CodGen_B.Switch4 =
            DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState;
        }

        /* End of Switch: '<S183>/Switch4' */
        DT24_CVADAS_AP_CodGen_B.Switch2 = DT24_CVADAS_AP_CodGen_B.Switch4;
      }

      /* End of Switch: '<S183>/Switch2' */
      DT24_CVADAS_AP_CodGen_B.Switch1_j = DT24_CVADAS_AP_CodGen_B.Switch2;
    }

    /* End of Switch: '<S183>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k =
      DT24_CVADAS_AP_CodGen_B.Switch1_j;
  }

  /* End of Switch: '<S183>/Switch' */

  /* DataTypeConversion: '<S23>/Data Type Conversion24' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_USSActiveSpdThd =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LatAcceleration_BSM;

  /* DataTypeConversion: '<S23>/Data Type Conversion25' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_RearWarnMaxSpdThd_o =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LongAcceleration_BSM;

  /* DataTypeConversion: '<S23>/Data Type Conversion26' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_VehicleSpeedVSOSig;

  /* DataTypeConversion: '<S23>/Data Type Conversion27' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOnThd_m =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_YawRate_BSM;

  /* DataTypeConversion: '<S23>/Data Type Conversion28' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_FastPulseCounter;

  /* DataTypeConversion: '<S23>/Data Type Conversion29' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_LhfWhlSpnSts = (TeVBII_e_WhlSpnSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_Spin;

  /* DataTypeConversion: '<S23>/Data Type Conversion30' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOffThd_o =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHFWheelSpeed;

  /* DataTypeConversion: '<S23>/Data Type Conversion31' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhrPulseCtr =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_FastPulseCounter;

  /* DataTypeConversion: '<S23>/Data Type Conversion34' */
  DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_FastPulseCounter;

  /* DataTypeConversion: '<S23>/Data Type Conversion35' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_RhfWhlSpnSts = (TeVBII_e_WhlSpnSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_Spin;

  /* DataTypeConversion: '<S23>/Data Type Conversion36' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_ParkMnvThd_b =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHFWheelSpeed;

  /* DataTypeConversion: '<S23>/Data Type Conversion37' */
  DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_FastPulseCounter;

  /* DataTypeConversion: '<S23>/Data Type Conversion39' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_FrntWarnMaxSpdThd_h =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsAngle;

  /* DataTypeConversion: '<S23>/Data Type Conversion40' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_deg_StrWhlSpd =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_LwsSpeed;

  /* DataTypeConversion: '<S23>/Data Type Conversion41' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_AGSM_FD_2.Shifter_ADAS_Inhibit
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion42' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ShiftLvrPosReq = (TeVBII_e_ShiftLvrPosReq)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_AGSM_FD_2.ShiftLeverPositionReq;

  /* DataTypeConversion: '<S23>/Data Type Conversion43' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_12.APARequestSts
     != 0);

  /*Added by Kedar, Pavan and Priyesh to disable autp park acitvation*/
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt = 0;		//keep
  /* DataTypeConversion: '<S23>/Data Type Conversion83' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_2.TurnIndicatorSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion44' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TurnIndicSts = (TeVBII_e_TurnIndicSts)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S23>/Data Type Conversion45' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_DriverDoorSts =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.DriverDoorSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion46' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_DoorRL =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.LHRDoorSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion47' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_DoorP =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.PsngrDoorSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion48' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_TrnkStatus =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.RHatchSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion49' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_SVSPresent =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_BCM_FD_9.RHRDoorSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion50' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_EngineSts = (TeVBII_e_EngineSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_2.FD14_EngineSts_W;

  /* DataTypeConversion: '<S23>/Data Type Conversion51' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_EnblHysThd_c =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_ENGINE_FD_5.FD14_PdlPosActual;

  /* DataTypeConversion: '<S23>/Data Type Conversion52' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_b_ActvParkMode =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Active_Park_Mode
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion53' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_LanguageSeln = (TeVBII_e_LanguageSeln)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.LanguageSelection;

  /* DataTypeConversion: '<S23>/Data Type Conversion54' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TGWCamDispSts = (TeVBII_e_TGWCamDispSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TELEMATIC_FD_14.TGW_CAMERA_DISP_STAT;

  /* DataTypeConversion: '<S23>/Data Type Conversion55' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_TchScrSts = (TeVBII_e_TchScrSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_STAT;

  /* DataTypeConversion: '<S23>/Data Type Conversion56' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_X_COORD;

  /* DataTypeConversion: '<S23>/Data Type Conversion57' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TELEMATIC_FD_5.CM_TCH_Y_COORD;

  /* DataTypeConversion: '<S23>/Data Type Conversion58' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrRvsSteerPres =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TRANSM_FD_1.TRANS_ADAS_Inhibit
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion84' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TRANSM_FD_4.GearEngaged;

  /* DataTypeConversion: '<S23>/Data Type Conversion59' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_GearRptState = (TeVBII_e_GearState)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S175>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_i = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_GearRptState;

  /* MultiPortSwitch: '<S175>/Multiport Switch' incorporates:
   *  Constant: '<S177>/Constant'
   *  Constant: '<S178>/Constant'
   *  Constant: '<S179>/Constant'
   *  Constant: '<S180>/Constant'
   *  Constant: '<S181>/Constant'
   */
  switch (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_i) {
   case 0:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Neutral;
    break;

   case 1:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 2:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 3:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 4:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 5:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 6:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 7:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 8:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 9:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Drive;
    break;

   case 13:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_Parking;
    break;

   case 14:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState =
      TeAP_e_FiltdGearState_ReverseGear;
    break;

   default:
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState = TeAP_e_FiltdGearState_SNA;
    break;
  }

  /* End of MultiPortSwitch: '<S175>/Multiport Switch' */

  /* DataTypeConversion: '<S23>/Data Type Conversion60' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ACCSysSts = (TeVBII_e_ACCSysSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_ADAS_FD_INFO.FD14_ACC_Systemsts;

  /* DataTypeConversion: '<S23>/Data Type Conversion61' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_nm_BrkTrqAct =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_BrkTrq;

  /* DataTypeConversion: '<S23>/Data Type Conversion62' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ParkingIntrvntionSts =
    (TeVBII_e_ParkingIntrvntionSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_ParkingInterventionSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion63' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrHitchAsstPres =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_EPS_HandsOnRecognition
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion64' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_SPMLatCtrlRespSts =
    (TeVBII_e_SPMLatCtrlRespSts)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_SPM_Lat_Ctrl_ResponseSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion65' */
  DT24_CVADAS_AP_CodGen_B.KeAP_degC_OperatingTempThd_c =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_EPS_FD_1.FD14_Steering_Column_Torque;

  /* DataTypeConversion: '<S23>/Data Type Conversion66' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_FullAutoPrkgSys =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LatAccelerationFailSts_BSM
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion67' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_PullOutCtrlPres =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_LongAccelerationFailSts_BSM
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion68' */
  DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_YawRateFailSts_BSM
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion69' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHF_WheelSensorFailSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion71' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_LHR_WheelSensorFailSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion72' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHF_WheelSensorFailSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion73' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_3.FD14_RHR_WheelSensorFailSts
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion74' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_PAMBrkReqRespStatus =
    (TeVBII_e_PAMBrkReqRespStatus)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_7.FD14_PAM_Brk_Rq_RspSts;

  /* DataTypeConversion: '<S23>/Data Type Conversion70' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_TRANSM_FD_4.ShiftLeverPosition;

  /* DataTypeConversion: '<S23>/Data Type Conversion75' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ShiftLvrPos = (TeVBII_e_ShiftLvrPos)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* Gain: '<S12>/Gain1' incorporates:
   *  DataTypeConversion: '<S23>/Data Type Conversion76'
   */
  DT24_CVADAS_AP_CodGen_B.Gain =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_BrkTrq_Driver;

  /* DataTypeConversion: '<S23>/Data Type Conversion78' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ExtBrkReqDisabled =
    (TeVBII_e_ExtBrkReqDisabled)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_1.FD14_ExternalBrkRequestsDisabled;

  /* DataTypeConversion: '<S23>/Data Type Conversion79' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_ParkingGearShiftReq =
    (TeVBII_e_ParkingGearShiftReq)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_ParkingGearShiftReq_BSM;

  /* DataTypeConversion: '<S23>/Data Type Conversion80' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cm_VehContour_FSL_x_b =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_2.FD14_Slope;

  /* DataTypeConversion: '<S23>/Data Type Conversion81' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_DriverReqAxleTrqEnabled =
    (TeVBII_e_DriverReqAxleTrqEnabled)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_6.FD14_DriverReq_AxleTrq_Enabled_BSM;

  /* DataTypeConversion: '<S23>/Data Type Conversion21' */
  DT24_CVADAS_AP_CodGen_B.IeVBII_e_BrkPdlStat = (TeVBII_e_BrkPdlStat)
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_BRAKE_FD_7.FD14_BrkPdl_Stat;

  /* DataTypeConversion: '<S23>/Data Type Conversion33' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_PT_TORQUE_FD_1.FD14_Accel_Pedal_Override;

  /* DataTypeConversion: '<S23>/Data Type Conversion77' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN14_to_IPC.DataInp_FD14_PT_TORQUE_FD_1.FD14_PPPA_TrqEnblRq_Allowed
     != 0);

  /* DataTypeConversion: '<S23>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.VehInpAdapter_opVehSignals.CAN2_to_IPC.DataInp_IPC_VEHICLE_SETUP.Active_Park_Prox_Chime
     != 0);

  /* BusCreator generated from: '<Root>/CVADAS_AutoPark_Main' */
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_CmdIgnSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_CmdIgnSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_FrntParkAsstReq
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_FrntParkAsstReq;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_ParkAsstReq
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_ParkAsstReq;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_RemoteStartActvSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_RemoteStartActvSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_SnowPlowAttached
    = DT24_CVADAS_AP_CodGen_ConstB.IeVBII_b_SnowPlowAttached;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TrailerConnectionSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TrailerConnectionSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TrlrPrsntSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TrlrPrsntSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_degC_ExtTemp
    = DT24_CVADAS_AP_CodGen_B.K_e_RAEB_VehicleWidth_f;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_BrkStat
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_BrkStat;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_VehEPBSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_VehEPBSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TCaseRangeSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TCaseRangeSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_EssEngState
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_EssEngState;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_PamChimeVolFrnt
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolFrnt;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_PamChimeVolRear
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolRear;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_RearBrkAsst
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_RearBrkAsst;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.MeAP_e_FiltdTrgtGear
    = DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TransSailingTst
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TransSailingTst;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_a_VehLatAcc
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_USSActiveSpdThd;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_a_VehLongAcc
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_RearWarnMaxSpdThd_o;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_kph_VehSpeedVSOSig
    = DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_ddeg_VehYawRate
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOnThd_m;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_cnt_LhfPulseCtr
    = DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhfPulseCtr;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_LhfWhlSpnSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_LhfWhlSpnSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_kph_LhfWhlSpd
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOffThd_o;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_cnt_LhrPulseCtr
    = DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhrPulseCtr;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_kph_LhrWhlSpd
    = DS_WheelSpeed_RL;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_cnt_RhfPulseCtr
    = DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_RhfWhlSpnSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_RhfWhlSpnSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_kph_RhfWhlSpd
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_ParkMnvThd_b;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_cnt_RhrPulseCtr
    = DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_kph_RhrWhlSpd
    = DS_WheelSpeed_RR;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_deg_StrWhlAng
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_FrntWarnMaxSpdThd_h;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_deg_StrWhlSpd
    = DT24_CVADAS_AP_CodGen_B.IeVBII_deg_StrWhlSpd;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_ShifterAutoconnectSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_ShifterAutoconnectSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ShiftLvrPosReq
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ShiftLvrPosReq;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_AutoParkEnblSwt
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_AutoParkEnblSwt;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TurnIndicSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TurnIndicSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_DriverDoorSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_DriverDoorSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_DoorRL
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_DoorRL;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_DoorP
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_DoorP;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_TrnkStatus
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_TrnkStatus;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_DoorRR
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_SVSPresent;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_EngineSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_EngineSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_per_PdlPosAct
    = DT24_CVADAS_AP_CodGen_B.KeAP_kph_EnblHysThd_c;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_ActvParkMode
    = DT24_CVADAS_AP_CodGen_B.IeVBII_b_ActvParkMode;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_LanguageSeln
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_LanguageSeln;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TGWCamDispSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TGWCamDispSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TchScrSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_TchScrSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TchXCoord
    = DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_TchYCoord
    = DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_GearShiftReqAccept
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrRvsSteerPres;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.MeAP_e_FiltdGearRptState
    = DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ACCSysSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ACCSysSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_nm_BrkTrqAct
    = DT24_CVADAS_AP_CodGen_B.IeVBII_nm_BrkTrqAct;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ParkingIntrvntionSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ParkingIntrvntionSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_HandsOnRecog
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrHitchAsstPres;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_SPMLatCtrlRespSts
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_SPMLatCtrlRespSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_M_StrWhlTrq
    = DT24_CVADAS_AP_CodGen_B.KeAP_degC_OperatingTempThd_c;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_VehLatAccFailSts
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_FullAutoPrkgSys;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_VehLongAccFailSts
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_PullOutCtrlPres;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_VehYawRateFailSts
    = DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_LHFWhlSnsrFailSts
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_LHRWhlSnsrFailSts
    = DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_RHFWhlSnsrFailSts
    = DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_RHRWhlSnsrFailSts
    = DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_PAMBrkReqRespStatus
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_PAMBrkReqRespStatus;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ShiftLvrPos
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ShiftLvrPos;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_nm_BrkTrqDriver
    = DT24_CVADAS_AP_CodGen_B.Gain;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ExtBrkReqDisabled
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ExtBrkReqDisabled;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_ParkingGearShiftReq
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_ParkingGearShiftReq;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_pct_Slope
    = DT24_CVADAS_AP_CodGen_B.KeAP_cm_VehContour_FSL_x_b;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_DriverReqAxleTrqEnabled
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_DriverReqAxleTrqEnabled;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_e_BrkPdlStat
    = DT24_CVADAS_AP_CodGen_B.IeVBII_e_BrkPdlStat;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_Override
    = DT24_CVADAS_AP_CodGen_B.RelationalOperator_e;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_TrqEnblReqAllowed
    = DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;
  DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1.IeVBII_b_ParkProxChime
    = DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* DataStoreRead: '<S2>/MbNVM_ReadParam_data' */
  //DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam_j = SigMgr_TbNVM_ReadParam_data_Get();
  SigMgr_Data_TbNVM_ReadParam_Get(&DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam_j);	
  /* SignalConversion: '<S14>/Signal Conversion' */
  DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam_j;

  /* DataStoreRead: '<S2>/TbNVM_ProxyCalibParam_data' */
  //DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e =
  //  SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get();
  SigMgr_Data_ME_ProxiToMCU2_1_Def_t_Get(&DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e);

  /* DataTypeConversion: '<S17>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_CanNod67_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion90' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_CanNod63_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion91' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_StopNStrt_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion92' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_TyreSz_u16;

  /* DataTypeConversion: '<S17>/Data Type Conversion93' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_SteerRatRackPinionTyp =
    (TeAP_e_SteerRatRackPinionTyp)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_StrRatRckPinionTyp_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion94' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_DrvTypVrnt = (TeAP_e_DrvTypVrnt)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_DrvTypVrnt_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion95' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_GbTyp = (TeAP_e_GbTyp)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_GbTyp_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion96' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_PAMTunSet = (TeAP_e_PAMTunSet)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_PAMTunSet_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion97' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_VehLineCfg_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion98' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_CtryCod = (TeAP_e_CtryCod)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_CountryCode_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion99' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_HybTyp = (TeAP_e_HybTyp)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_HybTyp_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion101' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_WhlBas = (TeAP_e_WhlBas)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_Wheelbase_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion102' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_ParkWithStop_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion103' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_PAMCfg_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion104' */
  DT24_CVADAS_AP_CodGen_B.KeAP_e_RadioDispTyp = (TeAP_e_RadioDispTyp)
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_RadioDispTyp_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion105' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_CanNod95_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion106' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_DrvSide_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion107' */
  DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_SemiAutoPrkgSys_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion108' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_ModelYear_u8;

  /* DataTypeConversion: '<S17>/Data Type Conversion109' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_PullOutCtrlPres =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_PullOutCtrlPres_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion110' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_FullAutoPrkgSys =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_FullAutoPrkgSys_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion127' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrHitchAsstPres =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_TrlrHitchAssPres_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion111' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrRvsSteerPres =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_TRSCPresence_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion128' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_SVSPresent =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_SurroundViewCamera_b;

  /* DataTypeConversion: '<S17>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a =
    DT24_CVADAS_AP_CodGen_B.MbNVM_ProxyParam_e.PRX_variantID_u8;

  /* BusCreator: '<S17>/Bus Creator2' */
  MbNVM_ProxyParam.KeAP_b_CanNode67DTCM =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  MbNVM_ProxyParam.KeAP_b_CanNode63TTM =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;
  MbNVM_ProxyParam.KeAP_b_StopAndStrt =
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_e;
  MbNVM_ProxyParam.KeAP_mm_TyreSz =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h;
  MbNVM_ProxyParam.KeAP_e_SteerRatRackPinionTyp =
    DT24_CVADAS_AP_CodGen_B.KeAP_e_SteerRatRackPinionTyp;
  MbNVM_ProxyParam.KeAP_e_DrvTypVrnt = DT24_CVADAS_AP_CodGen_B.KeAP_e_DrvTypVrnt;
  MbNVM_ProxyParam.KeAP_e_GbTyp = DT24_CVADAS_AP_CodGen_B.KeAP_e_GbTyp;
  MbNVM_ProxyParam.KeAP_e_PAMTunSet = DT24_CVADAS_AP_CodGen_B.KeAP_e_PAMTunSet;
  MbNVM_ProxyParam.KeAP_e_VehLineCfg =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;
  MbNVM_ProxyParam.KeAP_e_CtryCod = DT24_CVADAS_AP_CodGen_B.KeAP_e_CtryCod;
  MbNVM_ProxyParam.KeAP_e_HybTyp = DT24_CVADAS_AP_CodGen_B.KeAP_e_HybTyp;
  MbNVM_ProxyParam.KeAP_e_WhlBas = DT24_CVADAS_AP_CodGen_B.KeAP_e_WhlBas;
  MbNVM_ProxyParam.KeAP_b_ParkWithStop =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p;
  MbNVM_ProxyParam.KeAP_b_PAMCfg = DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j;
  MbNVM_ProxyParam.KeAP_e_RadioDispTyp =
    DT24_CVADAS_AP_CodGen_B.KeAP_e_RadioDispTyp;
  MbNVM_ProxyParam.KeAP_b_CanNode95ITBMTCM =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b;
  MbNVM_ProxyParam.KeAP_b_DrvSide =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i;
  MbNVM_ProxyParam.KeAP_b_SemiAutoPrkgSys =
    DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d;
  MbNVM_ProxyParam.KeAP_e_MdlYr =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h;
  MbNVM_ProxyParam.KeAP_b_PullOutCtrlPres =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_PullOutCtrlPres;
  MbNVM_ProxyParam.KeAP_b_FullAutoPrkgSys =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_FullAutoPrkgSys;
  MbNVM_ProxyParam.KeAP_b_TrlrHitchAsstPres =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrHitchAsstPres;
  MbNVM_ProxyParam.KeAP_b_TrlrRvsSteerPres =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_TrlrRvsSteerPres;
  MbNVM_ProxyParam.KeAP_b_SVSPresent = DT24_CVADAS_AP_CodGen_B.KeAP_b_SVSPresent;
  MbNVM_ProxyParam.KeAP_k_VariantID = DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a;

  /* DataStoreRead: '<S2>/USS_BlockageBit_data' */
 // DT24_CVADAS_AP_CodGen_B.USS_BlockageBit =
 //   SigMgr_PpUSSBlockageBit_US_S_BlockageBit_t_Get();

  /* DataTypeConversion: '<S22>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.IeUSS_e_BlockageFlag =
    DT24_CVADAS_AP_CodGen_B.USS_BlockageBit.blockageFlagBits;

  /* DataStoreRead: '<S2>/USS_ErrorDiag_Data' */
  // DT24_CVADAS_AP_CodGen_B.USSErrorDiagData =
  //   SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get();
  SigMgr_PpUSSErrorDiagData_US_S_USSErrorDiagData_t_Get(&DT24_CVADAS_AP_CodGen_B.USSErrorDiagData);
  /* DataTypeConversion: '<S22>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h =
    DT24_CVADAS_AP_CodGen_B.USSErrorDiagData.ErrorMsg.overTempFault;

  /* DataTypeConversion: '<S22>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h =
    DT24_CVADAS_AP_CodGen_B.USSErrorDiagData.ErrorMsg.commFault;

  /* DataTypeConversion: '<S22>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_FrntChimeDisTimeThd_j =
    DT24_CVADAS_AP_CodGen_B.USSErrorDiagData.ErrorMsg.commUnknown;

  /* DataTypeConversion: '<S22>/Data Type Conversion126' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_ChimeVolChgAlert_d =
    DT24_CVADAS_AP_CodGen_B.USSErrorDiagData.ErrorMsg.hardwareFault;

  /* BusCreator: '<S22>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.IbUSS_DiagFlag.overTempFault =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h;
  DT24_CVADAS_AP_CodGen_B.IbUSS_DiagFlag.commFault =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h;
  DT24_CVADAS_AP_CodGen_B.IbUSS_DiagFlag.commUnknown =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_FrntChimeDisTimeThd_j;
  DT24_CVADAS_AP_CodGen_B.IbUSS_DiagFlag.hardwareFault =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_ChimeVolChgAlert_d;

  /* DataStoreRead: '<S2>/LwSpd_FPA_data' */
  SigMgr_PpJobFPAData_IJobFPAOutput_t_Get(&DT24_CVADAS_AP_CodGen_B.FPA_Output);

  /* BusCreator: '<S36>/Bus Creator5' incorporates:
   *  Constant: '<S30>/Constant22'
   *  Constant: '<S30>/Constant23'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices.x = 8.64F;
  DT24_CVADAS_AP_CodGen_B.Vertices.y = 2.21F;

  /* BusCreator: '<S36>/Bus Creator1' incorporates:
   *  Constant: '<S30>/Constant16'
   *  Constant: '<S30>/Constant17'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_f.x = 8.64F;
  DT24_CVADAS_AP_CodGen_B.Vertices_f.y = 7.41F;

  /* BusCreator: '<S36>/Bus Creator2' incorporates:
   *  Constant: '<S30>/Constant18'
   *  Constant: '<S30>/Constant19'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_c.x = 12.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_c.y = 7.41F;

  /* BusCreator: '<S36>/Bus Creator3' incorporates:
   *  Constant: '<S30>/Constant20'
   *  Constant: '<S30>/Constant21'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_h.x = 12.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_h.y = 2.21F;

  /* Concatenate: '<S36>/Vector Concatenate' */
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0] =
    DT24_CVADAS_AP_CodGen_B.Vertices;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1] =
    DT24_CVADAS_AP_CodGen_B.Vertices_f;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2] =
    DT24_CVADAS_AP_CodGen_B.Vertices_c;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3] =
    DT24_CVADAS_AP_CodGen_B.Vertices_h;

  /* BusCreator: '<S30>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.Vertices[0] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0];
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.Vertices[1] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1];
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.Vertices[2] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2];
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.Vertices[3] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3];
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.m_SlotType =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotType;
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.m_SlotSide =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotSide;
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.m_SlotID =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotID;
  DT24_CVADAS_AP_CodGen_B.BusCreator_o.m_isSlotValid_b =
    DT24_CVADAS_AP_CodGen_ConstB.m_isSlotValid_b;

  /* BusCreator: '<S35>/Bus Creator5' incorporates:
   *  Constant: '<S30>/Constant8'
   *  Constant: '<S30>/Constant9'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_h.x = 0.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_h.y = 0.0F;

  /* BusCreator: '<S35>/Bus Creator1' incorporates:
   *  Constant: '<S30>/Constant10'
   *  Constant: '<S30>/Constant11'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_c.x = 0.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_c.y = 0.0F;

  /* BusCreator: '<S35>/Bus Creator2' incorporates:
   *  Constant: '<S30>/Constant12'
   *  Constant: '<S30>/Constant13'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_f.x = 0.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_f.y = 0.0F;

  /* BusCreator: '<S35>/Bus Creator3' incorporates:
   *  Constant: '<S30>/Constant14'
   *  Constant: '<S30>/Constant15'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices.x = 0.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices.y = 0.0F;

  /* Concatenate: '<S35>/Vector Concatenate' */
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0] =
    DT24_CVADAS_AP_CodGen_B.Vertices_h;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1] =
    DT24_CVADAS_AP_CodGen_B.Vertices_c;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2] =
    DT24_CVADAS_AP_CodGen_B.Vertices_f;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3] =
    DT24_CVADAS_AP_CodGen_B.Vertices;

  /* BusCreator: '<S30>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[0] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[1] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[2] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[3] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotType =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotType_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotSide =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotSide_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotID =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotID_p;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_isSlotValid_b =
    DT24_CVADAS_AP_CodGen_ConstB.m_isSlotValid_b_d;

  /* Concatenate: '<S30>/Vector Concatenate' */
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[0] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_o;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[1] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[2] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[3] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[4] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate[5] =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;

  /* BusCreator: '<S39>/Bus Creator5' incorporates:
   *  Constant: '<S31>/Constant22'
   *  Constant: '<S31>/Constant23'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_h.x = 8.64F;
  DT24_CVADAS_AP_CodGen_B.Vertices_h.y = 2.21F;

  /* BusCreator: '<S39>/Bus Creator1' incorporates:
   *  Constant: '<S31>/Constant16'
   *  Constant: '<S31>/Constant17'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_c.x = 8.64F;
  DT24_CVADAS_AP_CodGen_B.Vertices_c.y = 7.41F;

  /* BusCreator: '<S39>/Bus Creator2' incorporates:
   *  Constant: '<S31>/Constant18'
   *  Constant: '<S31>/Constant19'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices_f.x = 12.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices_f.y = 7.41F;

  /* BusCreator: '<S39>/Bus Creator3' incorporates:
   *  Constant: '<S31>/Constant20'
   *  Constant: '<S31>/Constant21'
   */
  DT24_CVADAS_AP_CodGen_B.Vertices.x = 12.0F;
  DT24_CVADAS_AP_CodGen_B.Vertices.y = 2.21F;

  /* Concatenate: '<S39>/Vector Concatenate' */
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0] =
    DT24_CVADAS_AP_CodGen_B.Vertices_h;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1] =
    DT24_CVADAS_AP_CodGen_B.Vertices_c;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2] =
    DT24_CVADAS_AP_CodGen_B.Vertices_f;
  DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3] =
    DT24_CVADAS_AP_CodGen_B.Vertices;

  /* BusCreator: '<S31>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[0] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[0];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[1] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[1];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[2] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[2];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.Vertices[3] =
    DT24_CVADAS_AP_CodGen_B.VectorConcatenate_e[3];
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotType =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotType_l;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotSide =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotSide_k;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_SlotID =
    DT24_CVADAS_AP_CodGen_ConstB.m_SlotID_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator_l.m_isSlotValid_b =
    DT24_CVADAS_AP_CodGen_ConstB.m_isSlotValid_b_g;

  /* BusAssignment: '<S9>/Bus Assignment' incorporates:
   *  Constant: '<S32>/Constant2'
   *  Constant: '<S32>/Constant3'
   *  Constant: '<S32>/Constant4'
   *  Constant: '<S32>/Constant5'
   *  Constant: '<S32>/Constant6'
   *  Constant: '<S32>/Constant7'
   *  Constant: '<S9>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.BusAssignment = DT24_CVADAS_AP_CodGen_B.FPA_Output;
  DT24_CVADAS_AP_CodGen_B.BusAssignment.AutoParkInitializedStatus_b = ((uint8_T)
    1U);
  memcpy
    (&DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.stFPAParkingSlotData
     [0], &DT24_CVADAS_AP_CodGen_B.VectorConcatenate[0], 6U * sizeof
     (IParkingSlotData_t));
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FpaInfoToVC.stFPALockedSlotData =
    DT24_CVADAS_AP_CodGen_B.BusCreator_l;
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[0] = ((uint8_T)
    1U);
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[1] = ((uint8_T)
    0U);
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[2] = ((uint8_T)
    0U);
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[3] = ((uint8_T)
    0U);
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[4] = ((uint8_T)
    0U);
  DT24_CVADAS_AP_CodGen_B.BusAssignment.m_FPAInfoToHMI.m_Parkable[5] = ((uint8_T)
    0U);

  /* Switch: '<S9>/Switch' incorporates:
   *  Constant: '<S9>/Constant'
   */
  if (KeAP_b_DevlopmentTest) {
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA = DT24_CVADAS_AP_CodGen_B.BusAssignment;
  } else {
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA = DT24_CVADAS_AP_CodGen_B.FPA_Output;
  }

  /*Added by Kedar, Pavan and Priyesh to disable autp park acitvation*/
  DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.AutoParkInitializedStatus_b = FALSE;
  /* End of Switch: '<S9>/Switch' */

  /* DataStoreRead: '<S2>/THA_Feature_Output_data' */
  // DT24_CVADAS_AP_CodGen_B.THA_Feature_Output =
  //   SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get();
  SigMgr_PpFeatureOutputsTHA_TbTHASmVc_FeatureOutputs_t_Get(&DT24_CVADAS_AP_CodGen_B.THA_Feature_Output);

  /* DataTypeConversion: '<S12>/Data Type Conversion269' */
  DS_ANGLE = DT24_CVADAS_AP_CodGen_B.KeAP_kph_FrntWarnMaxSpdThd_h;

  /* DataTypeConversion: '<S12>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion3 =
    DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig;

  /* DataTypeConversion: '<S12>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion2 =
    DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear;

  /* DataTypeConversion: '<S12>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion4 =
    DT24_CVADAS_AP_CodGen_B.IeVBII_cnt_LhrPulseCtr;

  /* DataTypeConversion: '<S12>/Data Type Conversion314' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion314 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState;

  /* DataTypeConversion: '<S12>/Data Type Conversion7' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion7 =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOnThd_m;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot1FrntStreetX =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    0].x;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot1FrntStreetY =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    0].y;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot2FrntBorderX =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    1].x;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot2FrntBorderY =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    1].y;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot3RearBorderX =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    2].x;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot3RearBorderY =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    2].y;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot4RearStreetX =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    3].x;

  /* SignalConversion generated from: '<Root>/CVADAS_AutoPark_Main' */
  MaAP_m_ParkSpot4RearStreetY =
    DT24_CVADAS_AP_CodGen_B.LwSpd_FPA.m_FpaInfoToVC.stFPALockedSlotData.Vertices[
    3].y;

  /* DataStoreRead: '<S2>/USS_2DPointMap_data' */
  //DT24_CVADAS_AP_CodGen_B.USS_2DPointMap =
  //  SigMgr_PpUSS_PointMapGroup_US_S_PointMapGroup_t_Get();
  SigMgr_PpUssPointMapGrp_US_S_PointMapGroup_t_Get(&DT24_CVADAS_AP_CodGen_B.USS_2DPointMap);
  /* SignalConversion: '<S22>/Signal Conversion2' */
  DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap =
    DT24_CVADAS_AP_CodGen_B.USS_2DPointMap.PointMap;

  /* DataStoreRead: '<S2>/TRSC_Feature_Output_data' */
  // DT24_CVADAS_AP_CodGen_B.TRSC_Feature_Output =
    // SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get();
  SigMgr_PpTRSC_ME_VehOut_TRSC_t_Get(&DT24_CVADAS_AP_CodGen_B.TRSC_Feature_Output);
  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion1 =
    DT24_CVADAS_AP_CodGen_B.IeVBII_b_ActvParkMode;

  /* DataStoreRead: '<S2>/VrntTunParam_data' */
  // DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam = SigMgr_Data_AP_VrntTunParam_t_Get();
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 5;
       DT24_CVADAS_AP_CodGen_B.i++) {
    /* DataTypeConversion: '<S25>/Data Type Conversion9' */
    DT24_CVADAS_AP_CodGen_B.BusCreator1.K_Overlap_Thrsld_RAEB[DT24_CVADAS_AP_CodGen_B.i]
      =
      DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.K_Overlap_Thrsld_RAEB[DT24_CVADAS_AP_CodGen_B.i];

    /* DataTypeConversion: '<S25>/Data Type Conversion16' */
    DT24_CVADAS_AP_CodGen_B.BusCreator1.Obj_DistTable[DT24_CVADAS_AP_CodGen_B.i]
      =
      DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Obj_DistTable[DT24_CVADAS_AP_CodGen_B.i];
  }

  /* DataTypeConversion: '<S25>/Data Type Conversion22' */
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator1.keVehParam_e_VehSteerRatioTable[0],
         &DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.keVehParam_e_VehSteerRatioTable
         [0], 19U * sizeof(real32_T));

  /* DataTypeConversion: '<S25>/Data Type Conversion23' */
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator1.keVehParam_e_StrWhlRatioBrkPnts[0],
         &DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.keVehParam_e_StrWhlRatioBrkPnts
         [0], 19U * sizeof(real32_T));

  /* DataTypeConversion: '<S25>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.KeAP_degC_OperatingTempThd_c =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_degC_OperatingTempThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_EnblHysThd_c =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_EnblHysThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_FrntWarnMaxSpdThd_h =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_FrntWarnMaxSpdThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_ParkMnvThd_b =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_ParkMnvThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOffThd_o =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_PSDOffThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion5' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOnThd_m =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_PSDOnThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion6' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_RearWarnMaxSpdThd_o =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_RearWarnMaxSpdThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion7' */
  DT24_CVADAS_AP_CodGen_B.KeAP_kph_USSActiveSpdThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_kph_USSActiveSpdThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion8' */
  DT24_CVADAS_AP_CodGen_B.K_e_RAEB_VehicleWidth_f =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.K_e_RAEB_VehicleWidth;

  /* DataTypeConversion: '<S25>/Data Type Conversion10' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeTOS_s_InTurnDbncTm =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeTOS_s_InTurnDbncTm;

  /* DataTypeConversion: '<S25>/Data Type Conversion11' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeTOS_s_StrDrvDbncTm =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeTOS_s_StrDrvDbncTm;

  /* DataTypeConversion: '<S25>/Data Type Conversion12' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeTOS_s_TurnExitDbncTm =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeTOS_s_TurnExitDbncTm;

  /* DataTypeConversion: '<S25>/Data Type Conversion13' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeTOS_x_InTurnThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeTOS_x_InTurnThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion14' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeTOS_x_TurnExitThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeTOS_x_TurnExitThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion15' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.keVehParam_m_DistWhlBse =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.keVehParam_m_DistWhlBse;

  /* DataTypeConversion: '<S25>/Data Type Conversion17' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.Overlap_Thrsld_Switch =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Overlap_Thrsld_Switch;

  /* DataTypeConversion: '<S25>/Data Type Conversion18' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.RAEB_Envelope_Offset =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.RAEB_Envelope_Offset;

  /* DataTypeConversion: '<S25>/Data Type Conversion19' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.RAEB_Lateral_Distance_Notification =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.RAEB_Lateral_Distance_Notification;

  /* DataTypeConversion: '<S25>/Data Type Conversion20' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.RAEB_Minimum_Object_Heigh =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.RAEB_Minimum_Object_Heigh;

  /* DataTypeConversion: '<S25>/Data Type Conversion21' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.sampling_time =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.sampling_time;

  /* DataTypeConversion: '<S25>/Data Type Conversion24' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.keInpAdptr_e_StWhOffset =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.keInpAdptr_e_StWhOffset;

  /* DataTypeConversion: '<S25>/Data Type Conversion25' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.Straight_Driving_Thresold_rads2 =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Straight_Driving_Thresold_rads2;

  /* DataTypeConversion: '<S25>/Data Type Conversion26' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.Steering_Angle_DeadZone_Start =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Steering_Angle_DeadZone_Start;

  /* DataTypeConversion: '<S25>/Data Type Conversion27' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.Steering_Angle_DeadZone_End =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Steering_Angle_DeadZone_End;

  /* DataTypeConversion: '<S25>/Data Type Conversion74' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_PathSepaMinSpd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_PathSepaMinSpd;

  /* DataTypeConversion: '<S25>/Data Type Conversion75' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_PathSepaSpdRampGrd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_PathSepaSpdRampGrd;

  /* DataTypeConversion: '<S25>/Data Type Conversion76' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_DetWP_PreviewTime =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_DetWP_PreviewTime;

  /* DataTypeConversion: '<S25>/Data Type Conversion77' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatPathDevPGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatPathDevPGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion78' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatPathDevIGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatPathDevIGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion79' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatPathDevDGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatPathDevDGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion80' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatHeadDevPGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatHeadDevPGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion81' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatHeadDevIGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatHeadDevIGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion82' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_LatHeadDevDGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_LatHeadDevDGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion83' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_SteerUpperLimit =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_SteerUpperLimit;

  /* DataTypeConversion: '<S25>/Data Type Conversion84' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_SteerLowerLimit =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_SteerLowerLimit;

  /* DataTypeConversion: '<S25>/Data Type Conversion85' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutCollDetActivate =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutCollDetActivate;

  /* DataTypeConversion: '<S25>/Data Type Conversion86' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutRemainDistNA =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutRemainDistNA;

  /* DataTypeConversion: '<S25>/Data Type Conversion87' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutCollDetCollDistLimit =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutCollDetCollDistLimit;

  /* DataTypeConversion: '<S25>/Data Type Conversion88' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutCollDetRedStopVal =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutCollDetRedStopVal;

  /* DataTypeConversion: '<S25>/Data Type Conversion89' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutVehSpdMaxSpotStrTime =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutVehSpdMaxSpotStrTime;

  /* DataTypeConversion: '<S25>/Data Type Conversion90' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion91' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutVehSpdMaxSpotSteer =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutVehSpdMaxSpotSteer;

  /* DataTypeConversion: '<S25>/Data Type Conversion92' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_BrakePGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_BrakePGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion93' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_BrakeIGain =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_BrakeIGain;

  /* DataTypeConversion: '<S25>/Data Type Conversion94' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_BrakeUpperLimit =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_BrakeUpperLimit;

  /* DataTypeConversion: '<S25>/Data Type Conversion95' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_BrakeLowerLimit =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_BrakeLowerLimit;

  /* DataTypeConversion: '<S25>/Data Type Conversion96' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutGearDrive =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutGearDrive;

  /* DataTypeConversion: '<S25>/Data Type Conversion97' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutGearReverse =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutGearReverse;

  /* DataTypeConversion: '<S25>/Data Type Conversion98' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_CtrlOutGearPark =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_CtrlOutGearPark;

  /* DataTypeConversion: '<S25>/Data Type Conversion99' */
  DT24_CVADAS_AP_CodGen_B.Abs4_e =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_k_WhlCircum;

  /* DataTypeConversion: '<S25>/Data Type Conversion28' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_ChimeVolChgAlert_d =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_ChimeVolChgAlert;

  /* DataTypeConversion: '<S25>/Data Type Conversion29' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_FrntChimeDisTimeThd_j =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_FrntChimeDisTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion30' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_HalfSecChimeAlert;

  /* DataTypeConversion: '<S25>/Data Type Conversion31' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_LEDBlinkTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion32' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_VehKeyOnTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_VehKeyOnTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion36' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_Cnt_GearFiltTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_Cnt_GearFiltTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion37' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_TimeStep =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_TimeStep;

  /* DataTypeConversion: '<S25>/Data Type Conversion38' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_ObjPrestFCDistThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_ObjPrestFCDistThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion39' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_ObjPrestRCDistThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_ObjPrestRCDistThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion40' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehicleWidth =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehicleWidth;

  /* DataTypeConversion: '<S25>/Data Type Conversion41' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_Cnt_GearOverrideTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_Cnt_GearOverrideTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion42' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_SwtStuckTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_SwtStuckTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion43' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_BSMInterfaceCntTimeout =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_BSMInterfaceCntTimeout;

  /* DataTypeConversion: '<S25>/Data Type Conversion44' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_CamHandshakeDur =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_CamHandshakeDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion45' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_EPSInterfaceCntTimeout =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_EPSInterfaceCntTimeout;

  /* DataTypeConversion: '<S25>/Data Type Conversion46' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_GearShiftWaitCntTimeout =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_GearShiftWaitCntTimeout;

  /* DataTypeConversion: '<S25>/Data Type Conversion47' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_MaxStandstillTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_MaxStandstillTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion48' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_ObjInPathTimeoutDur =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_ObjInPathTimeoutDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion49' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_PausedPressBtnTimeoutDur =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_PausedPressBtnTimeoutDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion50' */
  DT24_CVADAS_AP_CodGen_B.KeAP_s_EPSInterfaceCntTimeout_f =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_SeekPhaseTimeoutDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion51' */
  DT24_CVADAS_AP_CodGen_B.KeAP_s_CamHandshakeDur_j =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_s_SpdExceedDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion52' */
  DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_SPMBlinkLEDDur;

  /* DataTypeConversion: '<S25>/Data Type Conversion100' */
  DT24_CVADAS_AP_CodGen_B.KeAP_cm_VehContour_FSL_x_b =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion101' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FOL_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion102' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FIL_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion103' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FIR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion104' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FOR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion105' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FSR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion106' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FSL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion107' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FOL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion108' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FIL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion109' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FIR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FIR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion110' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FOR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FOR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion111' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FSR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_FSR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion112' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RSR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion113' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_ROR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion114' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RIR_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIR_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion115' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RIL_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion116' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_ROL_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion117' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RSL_x =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSL_x;

  /* DataTypeConversion: '<S25>/Data Type Conversion118' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RSR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion119' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_ROR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion120' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RIR_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIR_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion121' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RIL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RIL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion122' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_ROL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_ROL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion123' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_RSL_y =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_VehContour_RSL_y;

  /* DataTypeConversion: '<S25>/Data Type Conversion53' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone8'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone1 = KeAP_cm_DistZone1;

  /* DataTypeConversion: '<S25>/Data Type Conversion33' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone9'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone2 = KeAP_cm_DistZone2;

  /* DataTypeConversion: '<S25>/Data Type Conversion54' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone10'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone3 = KeAP_cm_DistZone3;

  /* DataTypeConversion: '<S25>/Data Type Conversion55' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone11'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone4 = KeAP_cm_DistZone4;

  /* DataTypeConversion: '<S25>/Data Type Conversion56' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone12'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone5 = KeAP_cm_DistZone5;

  /* DataTypeConversion: '<S25>/Data Type Conversion57' incorporates:
   *  Constant: '<S25>/KeAP_cm_DistZone13'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_DistZone6 = KeAP_cm_DistZone6;

  /* DataTypeConversion: '<S25>/Data Type Conversion58' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_DebounceTimeThd =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cnt_DebounceTimeThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion59' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_FrntLongDistAdj =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_FrntLongDistAdj;

  /* DataTypeConversion: '<S25>/Data Type Conversion60' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_HalfVehicleWidth =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_HalfVehicleWidth;

  /* DataTypeConversion: '<S25>/Data Type Conversion61' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_HookDistOffset =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_HookDistOffset;

  /* DataTypeConversion: '<S25>/Data Type Conversion62' */
  DT24_CVADAS_AP_CodGen_B.Add_o =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_MaxNoObjDetctDist;

  /* DataTypeConversion: '<S25>/Data Type Conversion63' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_RearLongDistAdj;

  /* DataTypeConversion: '<S25>/Data Type Conversion64' */
  DT24_CVADAS_AP_CodGen_B.Abs3_f =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_cm_WarnOffset;

  /* DataTypeConversion: '<S25>/Data Type Conversion34' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_e_GbTypAT;

  /* DataTypeConversion: '<S25>/Data Type Conversion65' */
  DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_pct_ObjConfidenceThd;

  /* DataTypeConversion: '<S25>/Data Type Conversion66' */
  DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.Reverse_Gr_num;

  /* DataTypeConversion: '<S25>/Data Type Conversion35' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_AutoParkEn;

  /* DataTypeConversion: '<S25>/Data Type Conversion67' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_FPAEn;

  /* DataTypeConversion: '<S25>/Data Type Conversion68' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_FullAutoPark;

  /* DataTypeConversion: '<S25>/Data Type Conversion69' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_HookConnected;

  /* DataTypeConversion: '<S25>/Data Type Conversion70' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_RPAwithBrk;

  /* DataTypeConversion: '<S25>/Data Type Conversion71' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_RPAwithSurroundView;

  /* DataTypeConversion: '<S25>/Data Type Conversion72' */
  DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeAP_b_SteerOnlyAutoPark;

  /* DataTypeConversion: '<S25>/Data Type Conversion73' */
  DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d =
    DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.CalData1.KeCMbB_b_EnblOncObjDbnc;

  /* BusCreator: '<S25>/Bus Creator1' incorporates:
   *  Constant: '<S25>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_degC_OperatingTempThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_degC_OperatingTempThd_c;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_EnblHysThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_EnblHysThd_c;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_FrntWarnMaxSpdThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_FrntWarnMaxSpdThd_h;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_ParkMnvThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_ParkMnvThd_b;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_PSDOffThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOffThd_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_PSDOnThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_PSDOnThd_m;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_RearWarnMaxSpdThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_RearWarnMaxSpdThd_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_kph_USSActiveSpdThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_kph_USSActiveSpdThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.K_e_RAEB_VehicleWidth =
    DT24_CVADAS_AP_CodGen_B.K_e_RAEB_VehicleWidth_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_k_WhlCircum =
    DT24_CVADAS_AP_CodGen_B.Abs4_e;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_ChimeVolChgAlert =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_ChimeVolChgAlert_d;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_FrntChimeDisTimeThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_FrntChimeDisTimeThd_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_HalfSecChimeAlert =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_HalfSecChimeAlert_h;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_LEDBlinkTimeThd =
    DT24_CVADAS_AP_CodGen_B.KeAP_cnt_LEDBlinkTimeThd_h;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_SeekPhaseTimeoutDur =
    DT24_CVADAS_AP_CodGen_B.KeAP_s_EPSInterfaceCntTimeout_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_s_SpdExceedDur =
    DT24_CVADAS_AP_CodGen_B.KeAP_s_CamHandshakeDur_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_SPMBlinkLEDDur =
    DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_VehContour_FSL_x =
    DT24_CVADAS_AP_CodGen_B.KeAP_cm_VehContour_FSL_x_b;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_MaxNoObjDetctDist =
    DT24_CVADAS_AP_CodGen_B.Add_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_RearLongDistAdj =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cm_WarnOffset =
    DT24_CVADAS_AP_CodGen_B.Abs3_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_e_GbTypAT =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_pct_ObjConfidenceThd =
    DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.Reverse_Gr_num =
    DT24_CVADAS_AP_CodGen_B.Reverse_Gr_num_a;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_AutoParkEn =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_FPAEn =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_FullAutoPark =
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_e;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_HookConnected =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_RPAwithBrk =
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_RPAwithSurroundView =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_RPAwithSurroundView_b;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_b_SteerOnlyAutoPark =
    DT24_CVADAS_AP_CodGen_B.KeAP_b_SteerOnlyAutoPark_i;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeCMbB_b_EnblOncObjDbnc =
    DT24_CVADAS_AP_CodGen_B.KeCMbB_b_EnblOncObjDbnc_d;
  DT24_CVADAS_AP_CodGen_B.BusCreator1.KeAP_cnt_EngagedFullWaitCnt = ((uint16_T)
    4U);

  /* Logic: '<S25>/Logical Operator1' incorporates:
   *  Constant: '<S25>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq = !KeAP_b_DevlopmentTest;

  /* Logic: '<S25>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    ((DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam.bValid != 0) &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq);

  /* Switch: '<S25>/Switch1' incorporates:
   *  Constant: '<S25>/Constant1'
   *  Constant: '<S25>/KeAP_s_BSMInterfaceCntTimeout'
   *  Constant: '<S25>/KeAP_s_BSMInterfaceCntTimeout1'
   *  Constant: '<S25>/KeAP_s_CamHandshakeDur'
   *  Constant: '<S25>/KeAP_s_CamHandshakeDur1'
   *  Constant: '<S25>/KeAP_s_EPSInterfaceCntTimeout'
   *  Constant: '<S25>/KeAP_s_EPSInterfaceCntTimeout1'
   *  Switch: '<S25>/Switch2'
   *  Switch: '<S25>/Switch3'
   */
  if (KeAP_b_DevlopmentTest) {
    DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst =
      KeAP_s_BSMInterfaceCntTimeoutTest;
    DT24_CVADAS_AP_CodGen_B.KeAP_s_CamHandshakeDur_j =
      KeAP_s_CamHandshakeDurTest;
    DT24_CVADAS_AP_CodGen_B.KeAP_s_EPSInterfaceCntTimeout_f =
      KeAP_s_EPSInterfaceCntTimeoutTest;
  } else {
    DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst =
      KeAP_s_BSMInterfaceCntTimeout;
    DT24_CVADAS_AP_CodGen_B.KeAP_s_CamHandshakeDur_j = KeAP_s_CamHandshakeDur;
    DT24_CVADAS_AP_CodGen_B.KeAP_s_EPSInterfaceCntTimeout_f =
      KeAP_s_EPSInterfaceCntTimeout;
  }

  /* End of Switch: '<S25>/Switch1' */

  /* BusCreator: '<S25>/Bus Creator' incorporates:
   *  Constant: '<S25>/K_Overlap_Thrsld_RAEB'
   *  Constant: '<S25>/K_e_RAEB_VehicleWidth'
   *  Constant: '<S25>/KeAP_Cnt_GearFiltTimeThd'
   *  Constant: '<S25>/KeAP_Cnt_GearOverrideTimeThd'
   *  Constant: '<S25>/KeAP_b_AutoParkEn'
   *  Constant: '<S25>/KeAP_b_FPAEn'
   *  Constant: '<S25>/KeAP_b_FullAutoPark'
   *  Constant: '<S25>/KeAP_b_HookConnected'
   *  Constant: '<S25>/KeAP_b_RPAwithBrk'
   *  Constant: '<S25>/KeAP_b_RPAwithSurroundView'
   *  Constant: '<S25>/KeAP_b_SteerOnlyAutoPark'
   *  Constant: '<S25>/KeAP_cm_DistZone1'
   *  Constant: '<S25>/KeAP_cm_DistZone2'
   *  Constant: '<S25>/KeAP_cm_DistZone3'
   *  Constant: '<S25>/KeAP_cm_DistZone4'
   *  Constant: '<S25>/KeAP_cm_DistZone5'
   *  Constant: '<S25>/KeAP_cm_DistZone6'
   *  Constant: '<S25>/KeAP_cm_DistZone7'
   *  Constant: '<S25>/KeAP_cm_FrntLongDistAdj'
   *  Constant: '<S25>/KeAP_cm_HalfVehicleWidth'
   *  Constant: '<S25>/KeAP_cm_HookDistOffset'
   *  Constant: '<S25>/KeAP_cm_MaxNoObjDetctDist'
   *  Constant: '<S25>/KeAP_cm_ObjPrestFCDistThd'
   *  Constant: '<S25>/KeAP_cm_ObjPrestRCDistThd'
   *  Constant: '<S25>/KeAP_cm_RearLongDistAdj'
   *  Constant: '<S25>/KeAP_cm_VehicleWidth'
   *  Constant: '<S25>/KeAP_cm_WarnOffset'
   *  Constant: '<S25>/KeAP_cnt_ChimeVolChgAlert'
   *  Constant: '<S25>/KeAP_cnt_DebounceTimeThd'
   *  Constant: '<S25>/KeAP_cnt_FrntChimeDisTimeThd'
   *  Constant: '<S25>/KeAP_cnt_HalfSecChimeAlert'
   *  Constant: '<S25>/KeAP_cnt_LEDBlinkTimeThd'
   *  Constant: '<S25>/KeAP_cnt_SwtStuckTimeThd'
   *  Constant: '<S25>/KeAP_cnt_TimeStep'
   *  Constant: '<S25>/KeAP_cnt_VehKeyOnTimeThd'
   *  Constant: '<S25>/KeAP_degC_OperatingTempThd'
   *  Constant: '<S25>/KeAP_e_GbTypAT'
   *  Constant: '<S25>/KeAP_k_BrakeIGain'
   *  Constant: '<S25>/KeAP_k_BrakeLowerLimit'
   *  Constant: '<S25>/KeAP_k_BrakePGain'
   *  Constant: '<S25>/KeAP_k_BrakeUpperLimit'
   *  Constant: '<S25>/KeAP_k_CtrlOutCollDetActivate'
   *  Constant: '<S25>/KeAP_k_CtrlOutCollDetCollDistLimit'
   *  Constant: '<S25>/KeAP_k_CtrlOutCollDetRedStopVal'
   *  Constant: '<S25>/KeAP_k_CtrlOutGearDrive'
   *  Constant: '<S25>/KeAP_k_CtrlOutGearPark'
   *  Constant: '<S25>/KeAP_k_CtrlOutGearReverse'
   *  Constant: '<S25>/KeAP_k_CtrlOutRemainDistNA'
   *  Constant: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotSteer'
   *  Constant: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd'
   *  Constant: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrTime'
   *  Constant: '<S25>/KeAP_k_DetWP_PreviewTime'
   *  Constant: '<S25>/KeAP_k_LatHeadDevDGain'
   *  Constant: '<S25>/KeAP_k_LatHeadDevIGain'
   *  Constant: '<S25>/KeAP_k_LatHeadDevPGain'
   *  Constant: '<S25>/KeAP_k_LatPathDevDGain'
   *  Constant: '<S25>/KeAP_k_LatPathDevIGain'
   *  Constant: '<S25>/KeAP_k_LatPathDevPGain'
   *  Constant: '<S25>/KeAP_k_PathSepaMinSpd'
   *  Constant: '<S25>/KeAP_k_PathSepaSpdRampGrd'
   *  Constant: '<S25>/KeAP_k_SteerLowerLimit'
   *  Constant: '<S25>/KeAP_k_SteerUpperLimit'
   *  Constant: '<S25>/KeAP_k_WhlCircum'
   *  Constant: '<S25>/KeAP_kph_EnblHysThd'
   *  Constant: '<S25>/KeAP_kph_FrntWarnMaxSpdThd'
   *  Constant: '<S25>/KeAP_kph_PSDOffThd'
   *  Constant: '<S25>/KeAP_kph_PSDOnThd'
   *  Constant: '<S25>/KeAP_kph_ParkMnvThd'
   *  Constant: '<S25>/KeAP_kph_RearWarnMaxSpdThd'
   *  Constant: '<S25>/KeAP_kph_USSActiveSpdThd'
   *  Constant: '<S25>/KeAP_pct_ObjConfidenceThd'
   *  Constant: '<S25>/KeAP_s_GearShiftWaitCntTimeout'
   *  Constant: '<S25>/KeAP_s_GearShiftWaitCntTimeout1'
   *  Constant: '<S25>/KeAP_s_GearShiftWaitCntTimeout2'
   *  Constant: '<S25>/KeAP_s_GearShiftWaitCntTimeout3'
   *  Constant: '<S25>/KeAP_s_GearShiftWaitCntTimeout4'
   *  Constant: '<S25>/KeAP_s_MaxStandstillTimeThd'
   *  Constant: '<S25>/KeAP_s_MaxStandstillTimeThd1'
   *  Constant: '<S25>/KeAP_s_MaxStandstillTimeThd2'
   *  Constant: '<S25>/KeAP_s_MaxStandstillTimeThd3'
   *  Constant: '<S25>/KeAP_s_MaxStandstillTimeThd4'
   *  Constant: '<S25>/KeAP_s_ObjInPathTimeoutDur'
   *  Constant: '<S25>/KeAP_s_ObjInPathTimeoutDur1'
   *  Constant: '<S25>/KeAP_s_ObjInPathTimeoutDur2'
   *  Constant: '<S25>/KeAP_s_ObjInPathTimeoutDur3'
   *  Constant: '<S25>/KeAP_s_ObjInPathTimeoutDur4'
   *  Constant: '<S25>/KeAP_s_PausedPressBtnTimeoutDur'
   *  Constant: '<S25>/KeAP_s_PausedPressBtnTimeoutDur1'
   *  Constant: '<S25>/KeAP_s_PausedPressBtnTimeoutDur2'
   *  Constant: '<S25>/KeAP_s_PausedPressBtnTimeoutDur3'
   *  Constant: '<S25>/KeAP_s_PausedPressBtnTimeoutDur4'
   *  Constant: '<S25>/KeAP_s_SeekPhaseTimeoutDur'
   *  Constant: '<S25>/KeAP_s_SeekPhaseTimeoutDur1'
   *  Constant: '<S25>/KeAP_s_SeekPhaseTimeoutDur2'
   *  Constant: '<S25>/KeAP_s_SeekPhaseTimeoutDur3'
   *  Constant: '<S25>/KeAP_s_SeekPhaseTimeoutDur4'
   *  Constant: '<S25>/KeAP_s_SpdExceedDur'
   *  Constant: '<S25>/KeAP_s_SpdExceedDur1'
   *  Constant: '<S25>/KeAP_s_SpdExceedDur2'
   *  Constant: '<S25>/KeAP_s_SpdExceedDur3'
   *  Constant: '<S25>/KeAP_s_SpdExceedDur4'
   *  Constant: '<S25>/KeCMbB_b_EnblOncObjDbnc'
   *  Constant: '<S25>/KeCMbB_b_EnblOncObjDbnc1'
   *  Constant: '<S25>/KeTOS_s_InTurnDbncTm'
   *  Constant: '<S25>/KeTOS_s_StrDrvDbncTm'
   *  Constant: '<S25>/KeTOS_s_TurnExitDbncTm'
   *  Constant: '<S25>/KeTOS_x_InTurnThd'
   *  Constant: '<S25>/KeTOS_x_TurnExitThd'
   *  Constant: '<S25>/Obj_DistTable'
   *  Constant: '<S25>/Overlap_Thrsld_Switch'
   *  Constant: '<S25>/RAEB_Envelope_Offset'
   *  Constant: '<S25>/RAEB_Lateral_Distance_Notification'
   *  Constant: '<S25>/RAEB_Minimum_Object_Heigh'
   *  Constant: '<S25>/Reverse_Gr_num'
   *  Constant: '<S25>/Steering_Angle_DeadZone_End'
   *  Constant: '<S25>/Steering_Angle_DeadZone_Start'
   *  Constant: '<S25>/Straight_Driving_Thresold_rads2'
   *  Constant: '<S25>/keInpAdptr_e_StWhOffset'
   *  Constant: '<S25>/keVehParam_e_StrWhlRatioBrkPnts'
   *  Constant: '<S25>/keVehParam_e_VehSteerRatioTable'
   *  Constant: '<S25>/keVehParam_m_DistWhlBse'
   *  Constant: '<S25>/sampling_time'
   */
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_degC_OperatingTempThd =
    KeAP_degC_OperatingTempThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_EnblHysThd = KeAP_kph_EnblHysThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_FrntWarnMaxSpdThd =
    KeAP_kph_FrntWarnMaxSpdThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_ParkMnvThd = KeAP_kph_ParkMnvThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_PSDOffThd = KeAP_kph_PSDOffThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_PSDOnThd = KeAP_kph_PSDOnThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_RearWarnMaxSpdThd =
    KeAP_kph_RearWarnMaxSpdThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_kph_USSActiveSpdThd = 65.0F;
  DT24_CVADAS_AP_CodGen_B.BusCreator.K_e_RAEB_VehicleWidth =
    K_e_RAEB_VehicleWidth;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeTOS_s_InTurnDbncTm = KeTOS_s_InTurnDbncTm;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeTOS_s_StrDrvDbncTm = KeTOS_s_StrDrvDbncTm;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeTOS_s_TurnExitDbncTm =
    KeTOS_s_TurnExitDbncTm;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeTOS_x_InTurnThd = KeTOS_x_InTurnThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeTOS_x_TurnExitThd = KeTOS_x_TurnExitThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.keVehParam_m_DistWhlBse =
    keVehParam_m_DistWhlBse;
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 5;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_B.BusCreator.K_Overlap_Thrsld_RAEB[DT24_CVADAS_AP_CodGen_B.i]
      = K_Overlap_Thrsld_RAEB[DT24_CVADAS_AP_CodGen_B.i];
    DT24_CVADAS_AP_CodGen_B.BusCreator.Obj_DistTable[DT24_CVADAS_AP_CodGen_B.i] =
      Obj_DistTable[DT24_CVADAS_AP_CodGen_B.i];
  }

  DT24_CVADAS_AP_CodGen_B.BusCreator.Overlap_Thrsld_Switch =
    Overlap_Thrsld_Switch;
  DT24_CVADAS_AP_CodGen_B.BusCreator.RAEB_Envelope_Offset = RAEB_Envelope_Offset;
  DT24_CVADAS_AP_CodGen_B.BusCreator.RAEB_Lateral_Distance_Notification =
    RAEB_Lateral_Distance_Notification;
  DT24_CVADAS_AP_CodGen_B.BusCreator.RAEB_Minimum_Object_Heigh =
    RAEB_Minimum_Object_Heigh;
  DT24_CVADAS_AP_CodGen_B.BusCreator.sampling_time = sampling_time;
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator.keVehParam_e_VehSteerRatioTable[0],
         (&(keVehParam_e_VehSteerRatioTable[0])), 19U * sizeof(real32_T));
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator.keVehParam_e_StrWhlRatioBrkPnts[0],
         (&(keVehParam_e_StrWhlRatioBrkPnts[0])), 19U * sizeof(real32_T));
  DT24_CVADAS_AP_CodGen_B.BusCreator.keInpAdptr_e_StWhOffset =
    keInpAdptr_e_StWhOffset;
  DT24_CVADAS_AP_CodGen_B.BusCreator.Straight_Driving_Thresold_rads2 =
    Straight_Driving_Thresold_rads2;
  DT24_CVADAS_AP_CodGen_B.BusCreator.Steering_Angle_DeadZone_Start =
    Steering_Angle_DeadZone_Start;
  DT24_CVADAS_AP_CodGen_B.BusCreator.Steering_Angle_DeadZone_End =
    Steering_Angle_DeadZone_End;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_PathSepaMinSpd =
    KeAP_k_PathSepaMinSpd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_PathSepaSpdRampGrd =
    KeAP_k_PathSepaSpdRampGrd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_DetWP_PreviewTime =
    KeAP_k_DetWP_PreviewTime;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatPathDevPGain =
    KeAP_k_LatPathDevPGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatPathDevIGain =
    KeAP_k_LatPathDevIGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatPathDevDGain =
    KeAP_k_LatPathDevDGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatHeadDevPGain =
    KeAP_k_LatHeadDevPGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatHeadDevIGain =
    KeAP_k_LatHeadDevIGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_LatHeadDevDGain =
    KeAP_k_LatHeadDevDGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_SteerUpperLimit =
    KeAP_k_SteerUpperLimit;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_SteerLowerLimit =
    KeAP_k_SteerLowerLimit;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutCollDetActivate =
    KeAP_k_CtrlOutCollDetActivate;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutRemainDistNA =
    KeAP_k_CtrlOutRemainDistNA;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutCollDetCollDistLimit =
    KeAP_k_CtrlOutCollDetCollDistLimit;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutCollDetRedStopVal =
    KeAP_k_CtrlOutCollDetRedStopVal;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutVehSpdMaxSpotStrTime =
    KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd =
    KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutVehSpdMaxSpotSteer =
    KeAP_k_CtrlOutVehSpdMaxSpotSteer;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_BrakePGain = KeAP_k_BrakePGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_BrakeIGain = KeAP_k_BrakeIGain;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_BrakeUpperLimit =
    KeAP_k_BrakeUpperLimit;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_BrakeLowerLimit =
    KeAP_k_BrakeLowerLimit;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutGearDrive =
    KeAP_k_CtrlOutGearDrive;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutGearReverse =
    KeAP_k_CtrlOutGearReverse;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_CtrlOutGearPark =
    KeAP_k_CtrlOutGearPark;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_k_WhlCircum = KeAP_k_WhlCircum;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_ChimeVolChgAlert =
    KeAP_cnt_ChimeVolChgAlert;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_FrntChimeDisTimeThd =
    KeAP_cnt_FrntChimeDisTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_HalfSecChimeAlert =
    KeAP_cnt_HalfSecChimeAlert;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_LEDBlinkTimeThd =
    KeAP_cnt_LEDBlinkTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_VehKeyOnTimeThd =
    KeAP_cnt_VehKeyOnTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_Cnt_GearFiltTimeThd =
    KeAP_Cnt_GearFiltTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_TimeStep = KeAP_cnt_TimeStep;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_ObjPrestFCDistThd =
    KeAP_cm_ObjPrestFCDistThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_ObjPrestRCDistThd =
    KeAP_cm_ObjPrestRCDistThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehicleWidth = KeAP_cm_VehicleWidth;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_Cnt_GearOverrideTimeThd =
    KeAP_Cnt_GearOverrideTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_SwtStuckTimeThd =
    KeAP_cnt_SwtStuckTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_BSMInterfaceCntTimeout =
    DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_CamHandshakeDur =
    DT24_CVADAS_AP_CodGen_B.KeAP_s_CamHandshakeDur_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_EPSInterfaceCntTimeout =
    DT24_CVADAS_AP_CodGen_B.KeAP_s_EPSInterfaceCntTimeout_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_GearShiftWaitCntTimeout =
    KeAP_s_GearShiftWaitCntTimeout;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_MaxStandstillTimeThd =
    KeAP_s_MaxStandstillTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_ObjInPathTimeoutDur =
    KeAP_s_ObjInPathTimeoutDur;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_PausedPressBtnTimeoutDur =
    KeAP_s_PausedPressBtnTimeoutDur;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_SeekPhaseTimeoutDur = ((uint16_T)
    60000U);
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_s_SpdExceedDur = ((uint16_T)2000U);
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_SPMBlinkLEDDur =
    KeAP_cnt_SPMBlinkLEDDur;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FSL_x =
    KeAP_cm_VehContour_FSL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FOL_x =
    KeAP_cm_VehContour_FOL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FIL_x =
    KeAP_cm_VehContour_FIL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FIR_x =
    KeAP_cm_VehContour_FIR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FOR_x =
    KeAP_cm_VehContour_FOR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FSR_x =
    KeAP_cm_VehContour_FSR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FSL_y =
    KeAP_cm_VehContour_FSL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FOL_y =
    KeAP_cm_VehContour_FOL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FIL_y =
    KeAP_cm_VehContour_FIL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FIR_y =
    KeAP_cm_VehContour_FIR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FOR_y =
    KeAP_cm_VehContour_FOR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_FSR_y =
    KeAP_cm_VehContour_FSR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RSR_x =
    KeAP_cm_VehContour_RSR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_ROR_x =
    KeAP_cm_VehContour_ROR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RIR_x =
    KeAP_cm_VehContour_RIR_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RIL_x =
    KeAP_cm_VehContour_RIL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_ROL_x =
    KeAP_cm_VehContour_ROL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RSL_x =
    KeAP_cm_VehContour_RSL_x;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RSR_y =
    KeAP_cm_VehContour_RSR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_ROR_y =
    KeAP_cm_VehContour_ROR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RIR_y =
    KeAP_cm_VehContour_RIR_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RIL_y =
    KeAP_cm_VehContour_RIL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_ROL_y =
    KeAP_cm_VehContour_ROL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_VehContour_RSL_y =
    KeAP_cm_VehContour_RSL_y;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone1 = KeAP_cm_DistZone1;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone2 = KeAP_cm_DistZone2;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone3 = KeAP_cm_DistZone3;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone4 = KeAP_cm_DistZone4;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone5 = KeAP_cm_DistZone5;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_DistZone6 = KeAP_cm_DistZone6;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_DebounceTimeThd =
    KeAP_cnt_DebounceTimeThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_FrntLongDistAdj =
    KeAP_cm_FrntLongDistAdj;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_HalfVehicleWidth =
    KeAP_cm_HalfVehicleWidth;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_HookDistOffset =
    KeAP_cm_HookDistOffset;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_MaxNoObjDetctDist =
    KeAP_cm_MaxNoObjDetctDist;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_RearLongDistAdj =
    KeAP_cm_RearLongDistAdj;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cm_WarnOffset = KeAP_cm_WarnOffset;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_e_GbTypAT = KeAP_e_GbTypAT;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_pct_ObjConfidenceThd =
    KeAP_pct_ObjConfidenceThd;
  DT24_CVADAS_AP_CodGen_B.BusCreator.Reverse_Gr_num = Reverse_Gr_num;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_AutoParkEn = KeAP_b_AutoParkEn;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_FPAEn = KeAP_b_FPAEn;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_FullAutoPark = KeAP_b_FullAutoPark;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_HookConnected = KeAP_b_HookConnected;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_RPAwithBrk = KeAP_b_RPAwithBrk;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_RPAwithSurroundView =
    KeAP_b_RPAwithSurroundView;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_b_SteerOnlyAutoPark =
    KeAP_b_SteerOnlyAutoPark;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeCMbB_b_EnblOncObjDbnc =
    KeCMbB_b_EnblOncObjDbnc;
  DT24_CVADAS_AP_CodGen_B.BusCreator.KeAP_cnt_EngagedFullWaitCnt = ((uint16_T)4U);

  /* End of BusCreator: '<S25>/Bus Creator' */

  /* Switch: '<S25>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    IbAP_InputVrntTunParam = DT24_CVADAS_AP_CodGen_B.BusCreator1;
  } else {
    IbAP_InputVrntTunParam = DT24_CVADAS_AP_CodGen_B.BusCreator;
  }

  /* End of Switch: '<S25>/Switch' */

  /* Saturate: '<S95>/Saturation15' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x > 600) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 600;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x < 400) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x;
  }

  /* End of Saturate: '<S95>/Saturation15' */

  /* Sum: '<S95>/Add11' incorporates:
   *  Constant: '<S95>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Add11 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs3_f -
    KeAP_cm_VehContourFrntXAdj);

  /* Saturate: '<S95>/Saturation16' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x > 600) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 600;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x < 400) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x;
  }

  /* End of Saturate: '<S95>/Saturation16' */

  /* Sum: '<S95>/Add12' incorporates:
   *  Constant: '<S95>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.Add12 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs3_f -
    KeAP_cm_VehContourFrntXAdj);

  /* Saturate: '<S95>/Saturation17' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x;
  }

  /* End of Saturate: '<S95>/Saturation17' */

  /* Sum: '<S95>/Add13' incorporates:
   *  Constant: '<S95>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.Add13 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs3_f -
    KeAP_cm_VehContourRearXAdj);

  /* Saturate: '<S95>/Saturation18' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x;
  }

  /* End of Saturate: '<S95>/Saturation18' */

  /* Sum: '<S95>/Add14' incorporates:
   *  Constant: '<S95>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.Add14 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs3_f -
    KeAP_cm_VehContourRearXAdj);

  /* Saturate: '<S95>/Saturation1' incorporates:
   *  Constant: '<S95>/Constant4'
   */
  if (KeAP_cm_VehContour_FSL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Saturation1 = 200;
  } else if (KeAP_cm_VehContour_FSL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Saturation1 = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Saturation1 = KeAP_cm_VehContour_FSL_y;
  }

  /* End of Saturate: '<S95>/Saturation1' */

  /* Saturate: '<S95>/Saturation' incorporates:
   *  Constant: '<S95>/Constant8'
   */
  if (KeAP_cm_WarnOffset > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (KeAP_cm_WarnOffset < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = KeAP_cm_WarnOffset;
  }

  /* End of Saturate: '<S95>/Saturation' */

  /* Sum: '<S95>/Add8' */
  DT24_CVADAS_AP_CodGen_B.Add8 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs3_f +
    DT24_CVADAS_AP_CodGen_B.Saturation1);

  /* Saturate: '<S95>/Saturation2' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y;
  }

  /* End of Saturate: '<S95>/Saturation2' */

  /* Sum: '<S95>/Add' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (int16_T)
    (DT24_CVADAS_AP_CodGen_B.Saturation1 + DT24_CVADAS_AP_CodGen_B.Abs3_f);

  /* Gain: '<S95>/Gain' */
  DT24_CVADAS_AP_CodGen_B.Gain_h = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g) >> 15);

  /* Saturate: '<S95>/Saturation3' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y;
  }

  /* End of Saturate: '<S95>/Saturation3' */

  /* Sum: '<S95>/Add1' */
  DT24_CVADAS_AP_CodGen_B.Abs3_f += DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;

  /* Gain: '<S95>/Gain1' */
  DT24_CVADAS_AP_CodGen_B.Gain1_c = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.Abs3_f) >> 15);

  /* Saturate: '<S95>/Saturation4' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y;
  }

  /* End of Saturate: '<S95>/Saturation4' */

  /* Saturate: '<S95>/Saturation5' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y;
  }

  /* End of Saturate: '<S95>/Saturation5' */

  /* Sum: '<S95>/Add2' */
  DT24_CVADAS_AP_CodGen_B.Abs3_f += DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;

  /* Gain: '<S95>/Gain2' */
  DT24_CVADAS_AP_CodGen_B.Gain2 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.Abs3_f) >> 15);

  /* Saturate: '<S95>/Saturation6' incorporates:
   *  Constant: '<S95>/Constant6'
   */
  if (KeAP_cm_VehContour_FSR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Saturation6 = 200;
  } else if (KeAP_cm_VehContour_FSR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Saturation6 = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Saturation6 = KeAP_cm_VehContour_FSR_y;
  }

  /* End of Saturate: '<S95>/Saturation6' */

  /* Sum: '<S95>/Add3' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g +=
    DT24_CVADAS_AP_CodGen_B.Saturation6;

  /* Gain: '<S95>/Gain3' */
  DT24_CVADAS_AP_CodGen_B.Gain3 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g) >> 15);

  /* Saturate: '<S95>/Saturation7' incorporates:
   *  Constant: '<S95>/Constant8'
   */
  if (KeAP_cm_WarnOffset > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (KeAP_cm_WarnOffset < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = KeAP_cm_WarnOffset;
  }

  /* End of Saturate: '<S95>/Saturation7' */

  /* Sum: '<S95>/Add9' */
  DT24_CVADAS_AP_CodGen_B.Add9 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Saturation6 -
    DT24_CVADAS_AP_CodGen_B.Abs3_f);

  /* Saturate: '<S95>/Saturation8' incorporates:
   *  Constant: '<S95>/Constant7'
   */
  if (KeAP_cm_VehContour_RSR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Saturation8 = 200;
  } else if (KeAP_cm_VehContour_RSR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Saturation8 = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Saturation8 = KeAP_cm_VehContour_RSR_y;
  }

  /* End of Saturate: '<S95>/Saturation8' */

  /* Saturate: '<S95>/Saturation9' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y;
  }

  /* End of Saturate: '<S95>/Saturation9' */

  /* Sum: '<S95>/Add4' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (int16_T)
    (DT24_CVADAS_AP_CodGen_B.Saturation8 + DT24_CVADAS_AP_CodGen_B.Abs3_f);

  /* Gain: '<S95>/Gain4' */
  DT24_CVADAS_AP_CodGen_B.Gain4 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g) >> 15);

  /* Saturate: '<S95>/Saturation10' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y > 200) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y;
  }

  /* End of Saturate: '<S95>/Saturation10' */

  /* Sum: '<S95>/Add5' */
  DT24_CVADAS_AP_CodGen_B.Abs3_f += DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;

  /* Gain: '<S95>/Gain5' */
  DT24_CVADAS_AP_CodGen_B.Gain5 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.Abs3_f) >> 15);

  /* Saturate: '<S95>/Saturation11' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y;
  }

  /* End of Saturate: '<S95>/Saturation11' */

  /* Saturate: '<S95>/Saturation12' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = 200;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y;
  }

  /* End of Saturate: '<S95>/Saturation12' */

  /* Sum: '<S95>/Add6' */
  DT24_CVADAS_AP_CodGen_B.Abs3_f += DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;

  /* Gain: '<S95>/Gain6' */
  DT24_CVADAS_AP_CodGen_B.Gain6 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.Abs3_f) >> 15);

  /* Saturate: '<S95>/Saturation13' incorporates:
   *  Constant: '<S95>/Constant5'
   */
  if (KeAP_cm_VehContour_RSL_y > 200) {
    DT24_CVADAS_AP_CodGen_B.Saturation13 = 200;
  } else if (KeAP_cm_VehContour_RSL_y < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Saturation13 = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Saturation13 = KeAP_cm_VehContour_RSL_y;
  }

  /* End of Saturate: '<S95>/Saturation13' */

  /* Sum: '<S95>/Add7' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g +=
    DT24_CVADAS_AP_CodGen_B.Saturation13;

  /* Gain: '<S95>/Gain7' */
  DT24_CVADAS_AP_CodGen_B.Gain7 = (int16_T)((16384 *
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g) >> 15);

  /* Saturate: '<S95>/Saturation14' incorporates:
   *  Constant: '<S95>/Constant8'
   */
  if (KeAP_cm_WarnOffset > 200) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 200;
  } else if (KeAP_cm_WarnOffset < (-200)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = KeAP_cm_WarnOffset;
  }

  /* End of Saturate: '<S95>/Saturation14' */

  /* Sum: '<S95>/Add10' */
  DT24_CVADAS_AP_CodGen_B.Add10 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Saturation13
    + DT24_CVADAS_AP_CodGen_B.Abs3_f);

  /* S-Function (sfix_bitop): '<S26>/Bitwise Operator1' */
  DT24_CVADAS_AP_CodGen_B.BitwiseOperator1 = (uint8_T)
    (DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam_j.Dtc_B12852A_Status & ((uint8_T)2U));

  /* S-Function (sfix_bitop): '<S26>/Bitwise Operator' */
  DT24_CVADAS_AP_CodGen_B.BitwiseOperator = (uint8_T)
    (DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam_j.Dtc_B12852A_Status & ((uint8_T)1U));

  /* S-Function (sfix_look1_dyn): '<S88>/Lookup Table Dynamic' incorporates:
   *  Constant: '<S88>/Constant'
   *  Constant: '<S88>/Constant3'
   */
  /* Dynamic Look-Up Table Block: '<S88>/Lookup Table Dynamic'
   * Input0  Data Type:  Floating Point real32_T
   * Input1  Data Type:  Floating Point real32_T
   * Input2  Data Type:  Integer        U8
   * Output0 Data Type:  Floating Point real_T
   * Lookup Method: Linear_Endpoint
   *
   */
  LookUp_real_TU8_real32_T( &(DT24_CVADAS_AP_CodGen_B.LookupTableDynamic),
    &KeAP_pct_SpdBasedObjConfThd[0],
    DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig,
    &KeAP_kph_ConfThdSpdBrkPnts[0], 1U);

  /* DataTypeConversion: '<S88>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.d = floor(DT24_CVADAS_AP_CodGen_B.LookupTableDynamic);
  if (rtIsNaN(DT24_CVADAS_AP_CodGen_B.d) || rtIsInf(DT24_CVADAS_AP_CodGen_B.d))
  {
    DT24_CVADAS_AP_CodGen_B.d = 0.0;
  } else {
    DT24_CVADAS_AP_CodGen_B.d = fmod(DT24_CVADAS_AP_CodGen_B.d, 256.0);
  }

  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_hr = (uint8_T)
    (DT24_CVADAS_AP_CodGen_B.d < 0.0 ? (int32_T)(uint8_T)-(int8_T)(uint8_T)
     -DT24_CVADAS_AP_CodGen_B.d : (int32_T)(uint8_T)DT24_CVADAS_AP_CodGen_B.d);

  /* End of DataTypeConversion: '<S88>/Data Type Conversion' */

  /* DataStoreRead: '<S2>/VrntTunParam_data3' */
  //DT24_CVADAS_AP_CodGen_B.IbKM_KinematicData = SigMgr_Data_IKinematicData_t_Gut();
  SigMgr_Data_IKinematicData_t_Get(&DT24_CVADAS_AP_CodGen_B.IbKM_KinematicData);
  /* Product: '<S13>/Product' incorporates:
   *  Constant: '<S13>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Abs4_e =
    DT24_CVADAS_AP_CodGen_B.IbKM_KinematicData.dx_m * 100.0F;

  /* Product: '<S13>/Product1' incorporates:
   *  Constant: '<S13>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.Abs4_e *= KeAP_sec_SampleTime;

  /* Gain: '<S13>/Gain' */
  dx_cm = (-1.0F) * DT24_CVADAS_AP_CodGen_B.Abs4_e;

  /* Abs: '<S89>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4_e = fabsf(dx_cm);

  /* RelationalOperator: '<S89>/Relational Operator4' incorporates:
   *  Constant: '<S89>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator4 = (DT24_CVADAS_AP_CodGen_B.Abs4_e >
    0.0F);

  /* Logic: '<S89>/Logical Operator4' incorporates:
   *  Logic: '<S163>/Logical Operator1'
   *  Switch: '<S163>/Switch3'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4 =
    !DT24_CVADAS_AP_CodGen_B.RelationalOperator4;

  /* UnitDelay: '<S164>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_a;

  /* Logic: '<S164>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    !DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S164>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4 &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq);

  /* UnitDelay: '<S163>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay2_n =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_a;

  /* Switch: '<S163>/Switch3' incorporates:
   *  Constant: '<S89>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch3_c = ((uint16_T)50U);
  } else {
    /* Logic: '<S163>/Logical Operator1' */
    DT24_CVADAS_AP_CodGen_B.LogicalOperator1_i =
      DT24_CVADAS_AP_CodGen_B.LogicalOperator4;

    /* RelationalOperator: '<S163>/Relational Operator' incorporates:
     *  Constant: '<S89>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.ElapseTimer_l = (KeAP_cnt_TimeStep <=
      DT24_CVADAS_AP_CodGen_B.UnitDelay2_n);

    /* Logic: '<S163>/Logical Operator3' */
    DT24_CVADAS_AP_CodGen_B.ElapseTimer_l =
      (DT24_CVADAS_AP_CodGen_B.ElapseTimer_l &&
       DT24_CVADAS_AP_CodGen_B.LogicalOperator1_i);

    /* Switch: '<S163>/Switch1' incorporates:
     *  Constant: '<S163>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.ElapseTimer_l) {
      /* Sum: '<S163>/Subtract' incorporates:
       *  Constant: '<S89>/Constant1'
       */
      DT24_CVADAS_AP_CodGen_B.Subtract_nl = (uint16_T)
        (DT24_CVADAS_AP_CodGen_B.UnitDelay2_n - KeAP_cnt_TimeStep);
      DT24_CVADAS_AP_CodGen_B.Switch1_d = DT24_CVADAS_AP_CodGen_B.Subtract_nl;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_d = ((uint16_T)0U);
    }

    /* End of Switch: '<S163>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch3_c = DT24_CVADAS_AP_CodGen_B.Switch1_d;
  }

  /* RelationalOperator: '<S163>/Relational Operator1' incorporates:
   *  Constant: '<S89>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq = (KeAP_cnt_TimeStep >
    DT24_CVADAS_AP_CodGen_B.Switch3_c);

  /* Logic: '<S163>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    !DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* SignalConversion: '<S89>/Signal Conversion' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_StandstillTimerRunning =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* RelationalOperator: '<S90>/Relational Operator4' incorporates:
   *  Constant: '<S165>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_RhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S90>/Relational Operator5' incorporates:
   *  Constant: '<S166>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_LhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S90>/Relational Operator1' incorporates:
   *  Constant: '<S90>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig <= 0.4F);

  /* Logic: '<S90>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill_m =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts &&
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* SignalConversion generated from: '<S91>/ SFunction ' */
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[0] =
    DT24_CVADAS_AP_CodGen_B.Add11;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[1] =
    DT24_CVADAS_AP_CodGen_B.Add11;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[2] =
    DT24_CVADAS_AP_CodGen_B.Add11;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[3] =
    DT24_CVADAS_AP_CodGen_B.Add11;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[4] =
    DT24_CVADAS_AP_CodGen_B.Add12;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[5] =
    DT24_CVADAS_AP_CodGen_B.Add12;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[6] =
    DT24_CVADAS_AP_CodGen_B.Add12;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[7] =
    DT24_CVADAS_AP_CodGen_B.Add12;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[8] =
    DT24_CVADAS_AP_CodGen_B.Add13;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[9] =
    DT24_CVADAS_AP_CodGen_B.Add13;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[10] =
    DT24_CVADAS_AP_CodGen_B.Add13;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[11] =
    DT24_CVADAS_AP_CodGen_B.Add13;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[12] =
    DT24_CVADAS_AP_CodGen_B.Add14;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[13] =
    DT24_CVADAS_AP_CodGen_B.Add14;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[14] =
    DT24_CVADAS_AP_CodGen_B.Add14;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport1[15] =
    DT24_CVADAS_AP_CodGen_B.Add14;

  /* SignalConversion generated from: '<S91>/ SFunction ' */
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[0] =
    DT24_CVADAS_AP_CodGen_B.Add8;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[1] =
    DT24_CVADAS_AP_CodGen_B.Saturation1;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[2] =
    DT24_CVADAS_AP_CodGen_B.Gain_h;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[3] =
    DT24_CVADAS_AP_CodGen_B.Gain1_c;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[4] =
    DT24_CVADAS_AP_CodGen_B.Gain2;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[5] =
    DT24_CVADAS_AP_CodGen_B.Gain3;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[6] =
    DT24_CVADAS_AP_CodGen_B.Saturation6;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[7] =
    DT24_CVADAS_AP_CodGen_B.Add9;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[8] =
    DT24_CVADAS_AP_CodGen_B.Add9;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[9] =
    DT24_CVADAS_AP_CodGen_B.Saturation8;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[10] =
    DT24_CVADAS_AP_CodGen_B.Gain4;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[11] =
    DT24_CVADAS_AP_CodGen_B.Gain5;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[12] =
    DT24_CVADAS_AP_CodGen_B.Gain6;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[13] =
    DT24_CVADAS_AP_CodGen_B.Gain7;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[14] =
    DT24_CVADAS_AP_CodGen_B.Saturation13;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2[15] =
    DT24_CVADAS_AP_CodGen_B.Add10;
  DT24_CVADAS_AP_CodGen_DW.point_index = 1U;
  DT24_CVADAS_AP_CodGen_B.f1 = roundf(1023.0F);
  if (DT24_CVADAS_AP_CodGen_B.f1 < 32768.0F) {
    if (DT24_CVADAS_AP_CodGen_B.f1 >= -32768.0F) {
      DT24_CVADAS_AP_CodGen_DW.MaxDist = (int16_T)DT24_CVADAS_AP_CodGen_B.f1;
    } else {
      DT24_CVADAS_AP_CodGen_DW.MaxDist = MIN_int16_T;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.MaxDist = MAX_int16_T;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_SideRegionLongThresh =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_CenterRegionLongThresh =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_DW.PrevCenterFront_MeAP_cm_ObjXPon =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_DW.PrevLeftFront_MeAP_cm_ObjXPon =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_DW.PrevRightFront_MeAP_cm_ObjXPon =
    DT24_CVADAS_AP_CodGen_DW.MaxDist;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_DW.PrevCenterRear_MeAP_cm_ObjXPon = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_DW.PrevLeftRear_MeAP_cm_ObjXPon = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  }

  DT24_CVADAS_AP_CodGen_DW.PrevRightRear_MeAP_cm_ObjXPon = (int16_T)
    DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/InitalisePointData'
   */
  /* DataTypeConversion: '<S98>/Data Type Conversion1' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.height = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.x = 0;

  /* DataTypeConversion: '<S98>/Data Type Conversion2' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.y = 0;

  /* DataTypeConversion: '<S98>/Data Type Conversion3' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Cruising_Age = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion5' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.confidence = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion4' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.age = (uint8_T)0;

  /* BusCreator: '<S98>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.x = DT24_CVADAS_AP_CodGen_B.x;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.y = DT24_CVADAS_AP_CodGen_B.y;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.height = DT24_CVADAS_AP_CodGen_B.height;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.Cruising_Age =
    DT24_CVADAS_AP_CodGen_B.Cruising_Age;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.confidence =
    DT24_CVADAS_AP_CodGen_B.confidence;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.age = DT24_CVADAS_AP_CodGen_B.age;
  DT24_CVADAS_AP_CodGen_DW.Current_Pt = DT24_CVADAS_AP_CodGen_B.BusCreator1_o;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFront = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFL = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFR = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRear = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRL = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRR = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist = 0;
  DT24_CVADAS_AP_CodGen_DW.FrntWallCountIdx = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist = 0;
  DT24_CVADAS_AP_CodGen_DW.RearWallCountIdx = 0U;
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 10;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_DW.FrontPointsArray[DT24_CVADAS_AP_CodGen_B.i] = 0U;
    DT24_CVADAS_AP_CodGen_DW.RearPointsArray[DT24_CVADAS_AP_CodGen_B.i] = 0U;
  }

  DT24_CVADAS_AP_CodGen_DW.FrontIdx = 0U;
  DT24_CVADAS_AP_CodGen_DW.RearIdx = 0U;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/InitalisePointData'
   */
  /* DataTypeConversion: '<S98>/Data Type Conversion1' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.height = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion3' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Cruising_Age = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion5' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.confidence = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion4' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.age = (uint8_T)0;

  /* BusCreator: '<S98>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.x = DT24_CVADAS_AP_CodGen_B.x;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.y = DT24_CVADAS_AP_CodGen_B.y;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.height = DT24_CVADAS_AP_CodGen_B.height;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.Cruising_Age =
    DT24_CVADAS_AP_CodGen_B.Cruising_Age;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.confidence =
    DT24_CVADAS_AP_CodGen_B.confidence;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.age = DT24_CVADAS_AP_CodGen_B.age;
  DT24_CVADAS_AP_CodGen_DW.FrontCenter_Pt =
    DT24_CVADAS_AP_CodGen_B.BusCreator1_o;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/InitalisePointData'
   */
  /* DataTypeConversion: '<S98>/Data Type Conversion1' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.height = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion3' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Cruising_Age = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion5' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.confidence = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion4' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.age = (uint8_T)0;

  /* BusCreator: '<S98>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.x = DT24_CVADAS_AP_CodGen_B.x;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.y = DT24_CVADAS_AP_CodGen_B.y;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.height = DT24_CVADAS_AP_CodGen_B.height;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.Cruising_Age =
    DT24_CVADAS_AP_CodGen_B.Cruising_Age;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.confidence =
    DT24_CVADAS_AP_CodGen_B.confidence;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.age = DT24_CVADAS_AP_CodGen_B.age;
  DT24_CVADAS_AP_CodGen_DW.RearCenter_Pt = DT24_CVADAS_AP_CodGen_B.BusCreator1_o;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/InitalisePointData'
   */
  /* DataTypeConversion: '<S98>/Data Type Conversion1' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.height = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion3' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.Cruising_Age = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion5' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.confidence = (uint8_T)0;

  /* DataTypeConversion: '<S98>/Data Type Conversion4' incorporates:
   *  Constant: '<S98>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.age = (uint8_T)0;

  /* BusCreator: '<S98>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.x = DT24_CVADAS_AP_CodGen_B.x;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.y = DT24_CVADAS_AP_CodGen_B.y;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.height = DT24_CVADAS_AP_CodGen_B.height;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.Cruising_Age =
    DT24_CVADAS_AP_CodGen_B.Cruising_Age;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.confidence =
    DT24_CVADAS_AP_CodGen_B.confidence;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_o.age = DT24_CVADAS_AP_CodGen_B.age;
  DT24_CVADAS_AP_CodGen_DW.RearWallCount = 0U;
  DT24_CVADAS_AP_CodGen_B.MeAP_b_IsWall = 0U;
  while (DT24_CVADAS_AP_CodGen_DW.point_index <= ((uint8_T)96U)) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    }

    DT24_CVADAS_AP_CodGen_B.i = DT24_CVADAS_AP_CodGen_DW.point_index - 1;
    if ((int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp >
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .x) {
      DT24_CVADAS_AP_CodGen_DW.current_point_x = (int16_T)
        DT24_CVADAS_AP_CodGen_B.a_tmp;
    } else {
      DT24_CVADAS_AP_CodGen_DW.current_point_x =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .x;
    }

    if (DT24_CVADAS_AP_CodGen_DW.current_point_x >=
        DT24_CVADAS_AP_CodGen_DW.MaxDist) {
      DT24_CVADAS_AP_CodGen_DW.current_point_x =
        DT24_CVADAS_AP_CodGen_DW.MaxDist;
    }

    DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    }

    if ((int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp >
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .y) {
      DT24_CVADAS_AP_CodGen_DW.current_point_y = (int16_T)
        DT24_CVADAS_AP_CodGen_B.a_tmp;
    } else {
      DT24_CVADAS_AP_CodGen_DW.current_point_y =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .y;
    }

    if (DT24_CVADAS_AP_CodGen_DW.current_point_y >=
        DT24_CVADAS_AP_CodGen_DW.MaxDist) {
      DT24_CVADAS_AP_CodGen_DW.current_point_y =
        DT24_CVADAS_AP_CodGen_DW.MaxDist;
    }

    DT24_CVADAS_AP_CodGen_DW.current_point_confidence =
      DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
      .confidence;
    DT24_CVADAS_AP_CodGen_DW.current_point_height =
      DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
      .height;
    if (DT24_CVADAS_AP_CodGen_DW.current_point_x < 0) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.current_point_x;
      if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
        DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
      }

      DT24_CVADAS_AP_CodGen_B.MaxDist = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;
    } else {
      DT24_CVADAS_AP_CodGen_B.MaxDist = DT24_CVADAS_AP_CodGen_DW.current_point_x;
    }

    if ((DT24_CVADAS_AP_CodGen_B.MaxDist <= DT24_CVADAS_AP_CodGen_DW.MaxDist) &&
        (DT24_CVADAS_AP_CodGen_DW.current_point_confidence >
         DT24_CVADAS_AP_CodGen_B.DataTypeConversion_hr)) {
      DT24_CVADAS_AP_CodGen_CalculateDistance();
      DT24_CVADAS_AP_CodGen_B.ObjY = DT24_CVADAS_AP_CodGen_DW.current_point_y;

      /* Constant: '<S88>/Constant2' */
      DT24_CVADAS_AP_CodGen_B.CenterLatThresh = KeAP_cm_CenterWarnLatThreshold;
      DT24_CVADAS_AP_CodGen_B.HalfVehWidth =
        IbAP_InputVrntTunParam.KeAP_cm_HalfVehicleWidth;
      DT24_CVADAS_AP_CodGen_B.SideMaxLongDist = KeAP_cm_DistZone2;

      /* Outputs for Function Call SubSystem: '<S91>/GetDiagonalCenterRegion' */
      /* Abs: '<S97>/Abs' */
      if (DT24_CVADAS_AP_CodGen_B.ObjY < 0) {
        DT24_CVADAS_AP_CodGen_B.Abs_h = (int16_T)-DT24_CVADAS_AP_CodGen_B.ObjY;
      } else {
        DT24_CVADAS_AP_CodGen_B.Abs_h = DT24_CVADAS_AP_CodGen_B.ObjY;
      }

      /* End of Abs: '<S97>/Abs' */

      /* RelationalOperator: '<S97>/Relational Operator' */
      DT24_CVADAS_AP_CodGen_B.RelationalOperator_f =
        (DT24_CVADAS_AP_CodGen_B.Abs_h > DT24_CVADAS_AP_CodGen_B.CenterLatThresh);

      /* RelationalOperator: '<S97>/Relational Operator1' */
      DT24_CVADAS_AP_CodGen_B.RelationalOperator1 =
        (DT24_CVADAS_AP_CodGen_B.Abs_h < DT24_CVADAS_AP_CodGen_B.HalfVehWidth);

      /* Logic: '<S97>/Logical Operator' */
      DT24_CVADAS_AP_CodGen_B.LogicalOperator_g =
        (DT24_CVADAS_AP_CodGen_B.RelationalOperator_f &&
         DT24_CVADAS_AP_CodGen_B.RelationalOperator1);

      /* Outputs for Enabled SubSystem: '<S97>/CalcSideRegLongThresh' incorporates:
       *  EnablePort: '<S102>/Enable'
       */
      if (DT24_CVADAS_AP_CodGen_B.LogicalOperator_g) {
        DT24_CVADAS_AP_CodGen_DW.CalcSideRegLongThresh_MODE = true;

        /* Sum: '<S102>/Subtract' */
        DT24_CVADAS_AP_CodGen_B.y_max = (int16_T)(DT24_CVADAS_AP_CodGen_B.Abs_h
          - DT24_CVADAS_AP_CodGen_B.CenterLatThresh);

        /* DataTypeConversion: '<S102>/Data Type Conversion1' */
        DT24_CVADAS_AP_CodGen_B.side_warn_weight = DT24_CVADAS_AP_CodGen_B.y_max;

        /* Sum: '<S102>/Subtract1' */
        DT24_CVADAS_AP_CodGen_B.y_max = (int16_T)
          (DT24_CVADAS_AP_CodGen_B.HalfVehWidth -
           DT24_CVADAS_AP_CodGen_B.CenterLatThresh);

        /* DataTypeConversion: '<S102>/Data Type Conversion2' */
        DT24_CVADAS_AP_CodGen_B.Switch_k = DT24_CVADAS_AP_CodGen_B.y_max;

        /* Abs: '<S103>/Abs' */
        DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh_In = fabsf
          (DT24_CVADAS_AP_CodGen_B.Switch_k);

        /* RelationalOperator: '<S103>/Relational Operator' incorporates:
         *  Constant: '<S103>/Constant'
         */
        DT24_CVADAS_AP_CodGen_B.RelationalOperator_fz =
          (DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh_In > 0.0001F);

        /* Switch: '<S103>/Switch' incorporates:
         *  Constant: '<S103>/Constant'
         */
        if (!DT24_CVADAS_AP_CodGen_B.RelationalOperator_fz) {
          DT24_CVADAS_AP_CodGen_B.Switch_k = 0.0001F;
        }

        /* End of Switch: '<S103>/Switch' */

        /* Product: '<S103>/Divide' */
        DT24_CVADAS_AP_CodGen_B.side_warn_weight /=
          DT24_CVADAS_AP_CodGen_B.Switch_k;

        /* Product: '<S102>/Product' */
        DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh_In =
          DT24_CVADAS_AP_CodGen_B.side_warn_weight * (real32_T)
          DT24_CVADAS_AP_CodGen_B.SideMaxLongDist;

        /* DataTypeConversion: '<S102>/Data Type Conversion' */
        DT24_CVADAS_AP_CodGen_B.f1 = floorf
          (DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh_In);
        if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
            (DT24_CVADAS_AP_CodGen_B.f1)) {
          DT24_CVADAS_AP_CodGen_B.f1 = 0.0F;
        } else {
          DT24_CVADAS_AP_CodGen_B.f1 = fmodf(DT24_CVADAS_AP_CodGen_B.f1,
            65536.0F);
        }

        DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh = (int16_T)
          (DT24_CVADAS_AP_CodGen_B.f1 < 0.0F ? (int32_T)(int16_T)-(int16_T)
           (uint16_T)-DT24_CVADAS_AP_CodGen_B.f1 : (int32_T)(int16_T)(uint16_T)
           DT24_CVADAS_AP_CodGen_B.f1);

        /* End of DataTypeConversion: '<S102>/Data Type Conversion' */
      } else {
        if (DT24_CVADAS_AP_CodGen_DW.CalcSideRegLongThresh_MODE) {
          /* Disable for Outport: '<S102>/SideRegionLongThresh' */
          DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh = 1023;
          DT24_CVADAS_AP_CodGen_DW.CalcSideRegLongThresh_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S97>/CalcSideRegLongThresh' */

      /* SignalConversion generated from: '<S97>/SideRegionLongThresh' */
      DT24_CVADAS_AP_CodGen_B.OutportBufferForSideRegionLongThresh =
        DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh;

      /* End of Outputs for SubSystem: '<S91>/GetDiagonalCenterRegion' */
      DT24_CVADAS_AP_CodGen_B.MeAP_b_SideRegionLongThresh =
        DT24_CVADAS_AP_CodGen_B.OutportBufferForSideRegionLongThresh;
      DT24_CVADAS_AP_CodGen_CheckNeaighbourHoodForRegions();
      DT24_CVADAS_AP_CodGen_GetObjectPointRegion();
      DT24_CVADAS_AP_CodGen_GetCenterRegionPoints();
    }

    DT24_CVADAS_AP_CodGen_B.a_tmp = (int32_T)
      (DT24_CVADAS_AP_CodGen_DW.point_index + 1U);
    if ((uint32_T)DT24_CVADAS_AP_CodGen_B.a_tmp > 255U) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 255;
    }

    DT24_CVADAS_AP_CodGen_DW.point_index = (uint8_T)
      DT24_CVADAS_AP_CodGen_B.a_tmp;
  }

  DT24_CVADAS_AP_CodGen_CheckForWallLikePatternFront();
  DT24_CVADAS_AP_CodGen_CheckForWallLikePatternRear();
  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_RearCenterMinDist;
  DT24_CVADAS_AP_CodGen_B.VehTravelDist = dx_cm;
  DT24_CVADAS_AP_CodGen_B.ZoneDist = KeAP_cm_DistZone2;
  DT24_CVADAS_AP_CodGen_B.HoldTracking =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_StandstillTimerRunning;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' incorporates:
   *  Constant: '<S100>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.f1 = floorf(1022.0F);
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4_tmp = fabsf(DT24_CVADAS_AP_CodGen_B.VehTravelDist);
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f)) {
      DT24_CVADAS_AP_CodGen_B.f = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f <
      0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f :
      (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearCenterMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist > 0) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist = (int16_T)
      DT24_CVADAS_AP_CodGen_B.a_tmp;
  }

  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_RearLeftMinDist;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' */
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f)) {
      DT24_CVADAS_AP_CodGen_B.f = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f <
      0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f :
      (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearLeftMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist > 0) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist = (int16_T)
      DT24_CVADAS_AP_CodGen_B.a_tmp;
  }

  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_RearRightMinDist;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' */
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f)) {
      DT24_CVADAS_AP_CodGen_B.f = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f <
      0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f :
      (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearRightMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist > 0) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = -DT24_CVADAS_AP_CodGen_DW.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    }

    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist = (int16_T)
      DT24_CVADAS_AP_CodGen_B.a_tmp;
  }

  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_FrntCenterMinDist;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' */
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f)) {
      DT24_CVADAS_AP_CodGen_B.f = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f <
      0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f :
      (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntCenterMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.MaxDist;
  }

  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_FrntLeftMinDist;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' */
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f)) {
      DT24_CVADAS_AP_CodGen_B.f = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f = fmodf(DT24_CVADAS_AP_CodGen_B.f, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f <
      0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f :
      (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntLeftMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.MaxDist;
  }

  DT24_CVADAS_AP_CodGen_B.RawDist =
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist;
  DT24_CVADAS_AP_CodGen_B.LastGoodDist =
    DT24_CVADAS_AP_CodGen_DW.LastGood_FrntRightMinDist;

  /* Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/UpdateDistNoDetection'
   */
  /* Abs: '<S100>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_c = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* DataTypeConversion: '<S100>/Data Type Conversion' */
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f1 = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f1 = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)(DT24_CVADAS_AP_CodGen_B.f1 < 0.0F ?
    (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f1 : (int32_T)
    (int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f1);

  /* RelationalOperator: '<S100>/Relational Operator1' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.Abs1_c >
    DT24_CVADAS_AP_CodGen_B.Abs2_g);

  /* Logic: '<S100>/Logical Operator2' incorporates:
   *  Constant: '<S100>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (KeAP_b_ForceEnArcTrack ||
    DT24_CVADAS_AP_CodGen_B.TrackObj);

  /* Abs: '<S100>/Abs3' */
  DT24_CVADAS_AP_CodGen_B.Abs3 = fabsf(DT24_CVADAS_AP_CodGen_B.LastGoodDist);

  /* DataTypeConversion: '<S100>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.ZoneDist;

  /* RelationalOperator: '<S100>/Relational Operator' */
  DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3
    <= DT24_CVADAS_AP_CodGen_B.Abs4);

  /* RelationalOperator: '<S100>/Relational Operator2' incorporates:
   *  Constant: '<S100>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 = (DT24_CVADAS_AP_CodGen_B.Abs3 >
    0);

  /* Abs: '<S100>/Abs4' */
  DT24_CVADAS_AP_CodGen_B.Abs4 = DT24_CVADAS_AP_CodGen_B.Abs4_tmp;

  /* RelationalOperator: '<S100>/Relational Operator4' incorporates:
   *  Constant: '<S100>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d = (DT24_CVADAS_AP_CodGen_B.Abs4 >
    0.0F);

  /* Logic: '<S100>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d ||
     DT24_CVADAS_AP_CodGen_B.HoldTracking);

  /* Logic: '<S100>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.TrackObj = (DT24_CVADAS_AP_CodGen_B.TrackObj &&
    DT24_CVADAS_AP_CodGen_B.LastObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Sum: '<S100>/Subtract' */
  DT24_CVADAS_AP_CodGen_B.Subtract = DT24_CVADAS_AP_CodGen_B.LastGoodDist -
    DT24_CVADAS_AP_CodGen_B.VehTravelDist;

  /* Abs: '<S100>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.RawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = (int16_T)-DT24_CVADAS_AP_CodGen_B.RawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_g = DT24_CVADAS_AP_CodGen_B.RawDist;
  }

  /* RelationalOperator: '<S100>/Relational Operator3' incorporates:
   *  Constant: '<S100>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 =
    (DT24_CVADAS_AP_CodGen_B.Abs2_g < KeAP_cm_DistZone2);

  /* Logic: '<S100>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.SaveObjInfo =
    (DT24_CVADAS_AP_CodGen_B.USSObjDetectedInZone2 &&
     DT24_CVADAS_AP_CodGen_B.LogicalOperator4_d);

  /* Switch generated from: '<S100>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.TrackObj) {
    /* DataTypeConversion: '<S100>/Data Type Conversion2' */
    DT24_CVADAS_AP_CodGen_B.f1 = floorf(DT24_CVADAS_AP_CodGen_B.Subtract);
    if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
        (DT24_CVADAS_AP_CodGen_B.f1)) {
      DT24_CVADAS_AP_CodGen_B.f1 = 0.0F;
    } else {
      DT24_CVADAS_AP_CodGen_B.f1 = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedDist_n = (int16_T)(DT24_CVADAS_AP_CodGen_B.f1
      < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.f1
      : (int32_T)(int16_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f1);
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_n;

    /* SignalConversion: '<S100>/Signal Conversion' */
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c =
      DT24_CVADAS_AP_CodGen_B.Subtract;
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_c;
  } else {
    /* Switch generated from: '<S100>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.UpdatedDist_b = DT24_CVADAS_AP_CodGen_B.RawDist;
    DT24_CVADAS_AP_CodGen_B.UpdatedDist = DT24_CVADAS_AP_CodGen_B.UpdatedDist_b;

    /* Switch generated from: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (DT24_CVADAS_AP_CodGen_B.SaveObjInfo) {
      /* DataTypeConversion: '<S100>/Data Type Conversion1' */
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n =
        DT24_CVADAS_AP_CodGen_B.RawDist;
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h =
        DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_n;
    } else {
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h = 1023.0F;
    }

    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist =
      DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist_h;
  }

  DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedDist;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntRightMinDist =
    DT24_CVADAS_AP_CodGen_B.UpdatedLastGoodDist;
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist =
      DT24_CVADAS_AP_CodGen_DW.MaxDist;
  }

  /* RelationalOperator: '<S29>/Compare' incorporates:
   *  Constant: '<S29>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.BitwiseOperator1 != ((uint8_T)0U));

  /* DataStoreRead: '<S2>/FID_STRUCT_B_data' */
  //DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B = SigMgr_Data_FID_STRUCT_B_Get();
  SigMgr_Data_FID_STRUCT_B_Get(&DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B);

  /* DataTypeConversion: '<S8>/Data Type Conversion112' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_FPADis != 0);

  /* Logic: '<S8>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* DataTypeConversion: '<S8>/Data Type Conversion113' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_RPADis != 0);

  /* RelationalOperator: '<S28>/Compare' incorporates:
   *  Constant: '<S28>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.BitwiseOperator != ((uint8_T)0U));

  /* Logic: '<S8>/Logical Operator2' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* DataTypeConversion: '<S8>/Data Type Conversion118' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_DISABLED_External_failure
     != 0);

  /* Logic: '<S8>/Logical Operator' */
  MeAP_b_ExternalFail = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* DataTypeConversion: '<S8>/Data Type Conversion1' */
  MeAP_b_SystemFail =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_DISABLED_System_failure
     != 0);

  /* Logic: '<S27>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e || MeAP_b_SystemFail);

  /* Logic: '<S27>/Logical Operator' */
  MeAP_b_FPADisable = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
                       DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* Logic: '<S27>/Logical Operator2' */
  MeAP_b_RPADisable = (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e ||
                       DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* DataTypeConversion: '<S8>/Data Type Conversion114' */
  MeAP_b_RPAActvTrlr_27 =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_RPA_ActTrlr_27
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion6' */
  MeAP_b_RPAActvTrlr_29 =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_RPA_ActTrlr_29
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion115' */
  MeAP_b_PAVolDefMed =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_DefMed != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion116' */
  MeAP_b_FPAVolDefMed =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_DefMedFPA != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion117' */
  MeAP_b_RPAVolDefMed =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_DefMedRPA != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion131' */
  MeAP_b_FrntSenorFail =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_FrontSensorSts
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion132' */
  MeAP_b_FrntSenorBlock =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_FrontSensorBlockage
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion133' */
  MeAP_b_RearSenorFail =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_RearSensorSts
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion134' */
  MeAP_b_RearSenorBlock =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PA_LIMITED_RearSensorBlockage
     != 0);

  /* BusCreator: '<S8>/Bus Creator3' */
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_ExternalFail = MeAP_b_ExternalFail;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_SystemFail = MeAP_b_SystemFail;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_FPADisable = MeAP_b_FPADisable;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RPADisable = MeAP_b_RPADisable;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RPAActvTrlr_27 = MeAP_b_RPAActvTrlr_27;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RPAActvTrlr_29 = MeAP_b_RPAActvTrlr_29;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_PAVolDefMed = MeAP_b_PAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_FPAVolDefMed = MeAP_b_FPAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RPAVolDefMed = MeAP_b_RPAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_FrntSenorFail = MeAP_b_FrntSenorFail;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_FrntSenorBlock = MeAP_b_FrntSenorBlock;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RearSenorFail = MeAP_b_RearSenorFail;
  DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RearSenorBlock = MeAP_b_RearSenorBlock;

  /* Product: '<S13>/Product2' incorporates:
   *  Constant: '<S13>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.Product2 =
    DT24_CVADAS_AP_CodGen_B.IbKM_KinematicData.m_Global_dx * 100.0F;

  /* UnitDelay: '<Root>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE;

  /* Saturate: '<S41>/Saturation' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FSL_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FSL_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FSL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_x;
  }

  /* End of Saturate: '<S41>/Saturation' */

  /* Saturate: '<S41>/Saturation1' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FOL_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FOL_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FOL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_x;
  }

  /* End of Saturate: '<S41>/Saturation1' */

  /* Saturate: '<S41>/Saturation2' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FIL_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FIL_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FIL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_x;
  }

  /* End of Saturate: '<S41>/Saturation2' */

  /* Saturate: '<S41>/Saturation3' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FIR_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FIR_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FIR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_x;
  }

  /* End of Saturate: '<S41>/Saturation3' */

  /* Saturate: '<S41>/Saturation4' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FOR_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FOR_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FOR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_x;
  }

  /* End of Saturate: '<S41>/Saturation4' */

  /* Saturate: '<S41>/Saturation5' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_x > 500) {
    DT24_CVADAS_AP_CodGen_B.FSR_x = 500;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_x < 400) {
    DT24_CVADAS_AP_CodGen_B.FSR_x = 400;
  } else {
    DT24_CVADAS_AP_CodGen_B.FSR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_x;
  }

  /* End of Saturate: '<S41>/Saturation5' */

  /* Saturate: '<S41>/Saturation6' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.RSR_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.RSR_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.RSR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_x;
  }

  /* End of Saturate: '<S41>/Saturation6' */

  /* Saturate: '<S41>/Saturation7' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.ROR_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.ROR_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.ROR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_x;
  }

  /* End of Saturate: '<S41>/Saturation7' */

  /* Saturate: '<S41>/Saturation8' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.RIR_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.RIR_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.RIR_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_x;
  }

  /* End of Saturate: '<S41>/Saturation8' */

  /* Saturate: '<S41>/Saturation9' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.RIL_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.RIL_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.RIL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_x;
  }

  /* End of Saturate: '<S41>/Saturation9' */

  /* Saturate: '<S41>/Saturation10' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.ROL_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.ROL_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.ROL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_x;
  }

  /* End of Saturate: '<S41>/Saturation10' */

  /* Saturate: '<S41>/Saturation11' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_x > (-50)) {
    DT24_CVADAS_AP_CodGen_B.RSL_x = (-50);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_x < (-200)) {
    DT24_CVADAS_AP_CodGen_B.RSL_x = (-200);
  } else {
    DT24_CVADAS_AP_CodGen_B.RSL_x =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_x;
  }

  /* End of Saturate: '<S41>/Saturation11' */

  /* Saturate: '<S41>/Saturation12' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_y > 100) {
    DT24_CVADAS_AP_CodGen_B.FSL_y = 100;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_y < 90) {
    DT24_CVADAS_AP_CodGen_B.FSL_y = 90;
  } else {
    DT24_CVADAS_AP_CodGen_B.FSL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSL_y;
  }

  /* End of Saturate: '<S41>/Saturation12' */

  /* Saturate: '<S41>/Saturation18' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y > 80) {
    DT24_CVADAS_AP_CodGen_B.FOL_y = 80;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y < 60) {
    DT24_CVADAS_AP_CodGen_B.FOL_y = 60;
  } else {
    DT24_CVADAS_AP_CodGen_B.FOL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOL_y;
  }

  /* End of Saturate: '<S41>/Saturation18' */

  /* Saturate: '<S41>/Saturation19' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y > 40) {
    DT24_CVADAS_AP_CodGen_B.FIL_y = 40;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y < 30) {
    DT24_CVADAS_AP_CodGen_B.FIL_y = 30;
  } else {
    DT24_CVADAS_AP_CodGen_B.FIL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIL_y;
  }

  /* End of Saturate: '<S41>/Saturation19' */

  /* Saturate: '<S41>/Saturation20' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y > (-30)) {
    DT24_CVADAS_AP_CodGen_B.FIR_y = (-30);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y < (-40)) {
    DT24_CVADAS_AP_CodGen_B.FIR_y = (-40);
  } else {
    DT24_CVADAS_AP_CodGen_B.FIR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FIR_y;
  }

  /* End of Saturate: '<S41>/Saturation20' */

  /* Saturate: '<S41>/Saturation21' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y > (-60)) {
    DT24_CVADAS_AP_CodGen_B.FOR_y = (-60);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y < (-80)) {
    DT24_CVADAS_AP_CodGen_B.FOR_y = (-80);
  } else {
    DT24_CVADAS_AP_CodGen_B.FOR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FOR_y;
  }

  /* End of Saturate: '<S41>/Saturation21' */

  /* Saturate: '<S41>/Saturation22' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_y > (-90)) {
    DT24_CVADAS_AP_CodGen_B.FSR_y = (-90);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_y < (-100)) {
    DT24_CVADAS_AP_CodGen_B.FSR_y = (-100);
  } else {
    DT24_CVADAS_AP_CodGen_B.FSR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_FSR_y;
  }

  /* End of Saturate: '<S41>/Saturation22' */

  /* Saturate: '<S41>/Saturation23' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_y > (-90)) {
    DT24_CVADAS_AP_CodGen_B.RSR_y = (-90);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_y < (-100)) {
    DT24_CVADAS_AP_CodGen_B.RSR_y = (-100);
  } else {
    DT24_CVADAS_AP_CodGen_B.RSR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSR_y;
  }

  /* End of Saturate: '<S41>/Saturation23' */

  /* Saturate: '<S41>/Saturation24' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y > (-70)) {
    DT24_CVADAS_AP_CodGen_B.ROR_y = (-70);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y < (-85)) {
    DT24_CVADAS_AP_CodGen_B.ROR_y = (-85);
  } else {
    DT24_CVADAS_AP_CodGen_B.ROR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROR_y;
  }

  /* End of Saturate: '<S41>/Saturation24' */

  /* Saturate: '<S41>/Saturation25' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y > (-30)) {
    DT24_CVADAS_AP_CodGen_B.RIR_y = (-30);
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y < (-40)) {
    DT24_CVADAS_AP_CodGen_B.RIR_y = (-40);
  } else {
    DT24_CVADAS_AP_CodGen_B.RIR_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIR_y;
  }

  /* End of Saturate: '<S41>/Saturation25' */

  /* Saturate: '<S41>/Saturation14' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y > 40) {
    DT24_CVADAS_AP_CodGen_B.RIL_y = 40;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y < 30) {
    DT24_CVADAS_AP_CodGen_B.RIL_y = 30;
  } else {
    DT24_CVADAS_AP_CodGen_B.RIL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RIL_y;
  }

  /* End of Saturate: '<S41>/Saturation14' */

  /* Saturate: '<S41>/Saturation15' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y > 85) {
    DT24_CVADAS_AP_CodGen_B.ROL_y = 85;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y < 70) {
    DT24_CVADAS_AP_CodGen_B.ROL_y = 70;
  } else {
    DT24_CVADAS_AP_CodGen_B.ROL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_ROL_y;
  }

  /* End of Saturate: '<S41>/Saturation15' */

  /* Saturate: '<S41>/Saturation13' */
  if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_y > 100) {
    DT24_CVADAS_AP_CodGen_B.RSL_y = 100;
  } else if (IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_y < 90) {
    DT24_CVADAS_AP_CodGen_B.RSL_y = 90;
  } else {
    DT24_CVADAS_AP_CodGen_B.RSL_y =
      IbAP_InputVrntTunParam.KeAP_cm_VehContour_RSL_y;
  }

  /* End of Saturate: '<S41>/Saturation13' */

  /* Abs: '<S92>/Abs' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXRawDist;
  }

  /* End of Abs: '<S92>/Abs' */

  /* Chart: '<S112>/DistDbnc' incorporates:
   *  Constant: '<S112>/Constant1'
   *  Constant: '<S112>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c12_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c12_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c12_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs;
    DT24_CVADAS_AP_CodGen_DW.Timer_a = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c12_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c12_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_p =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer_a = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer_a > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_a
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs;
      DT24_CVADAS_AP_CodGen_DW.Timer_a = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_p =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c12_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs;
      DT24_CVADAS_AP_CodGen_DW.Timer_a = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_p ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_p =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer_a = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_a > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_a + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_a > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_a
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_p =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_a > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_a + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_a > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_a
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_a = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S112>/DistDbnc' */

  /* RelationalOperator: '<S117>/Compare' incorporates:
   *  Constant: '<S117>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut == 1023);

  /* UnitDelay: '<S108>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay_o =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_f;

  /* RelationalOperator: '<S116>/Compare' incorporates:
   *  Constant: '<S116>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.UnitDelay_o == 1023);

  /* Logic: '<S108>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* Switch: '<S108>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_m =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut;
  } else {
    /* Sum: '<S108>/Add' */
    DT24_CVADAS_AP_CodGen_B.Add_c = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntCenterMinXDistOut +
       DT24_CVADAS_AP_CodGen_B.UnitDelay_o);

    /* Product: '<S108>/Divide' incorporates:
     *  Constant: '<S108>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
    DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
      DT24_CVADAS_AP_CodGen_B.Add_c >= 0 ? MAX_int32_T : MIN_int32_T :
      DT24_CVADAS_AP_CodGen_B.Add_c / DT24_CVADAS_AP_CodGen_B.a_tmp;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
        DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.Divide_l = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

    /* End of Product: '<S108>/Divide' */

    /* RelationalOperator: '<S115>/Relational Operator' incorporates:
     *  Constant: '<S115>/Constant2'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_c =
      (DT24_CVADAS_AP_CodGen_B.Divide_l > KeAP_cm_FrntDistArcComp);

    /* Switch: '<S115>/Switch1' */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_c) {
      /* Sum: '<S115>/Add1' incorporates:
       *  Constant: '<S115>/Constant1'
       */
      DT24_CVADAS_AP_CodGen_B.Add1_h = (int16_T)
        (DT24_CVADAS_AP_CodGen_B.Divide_l - KeAP_cm_FrntDistArcComp);
      DT24_CVADAS_AP_CodGen_B.Switch1_n2 = DT24_CVADAS_AP_CodGen_B.Add1_h;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_n2 = DT24_CVADAS_AP_CodGen_B.Divide_l;
    }

    /* End of Switch: '<S115>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch_m = DT24_CVADAS_AP_CodGen_B.Switch1_n2;
  }

  /* End of Switch: '<S108>/Switch' */

  /* Chart: '<S92>/FC_Dbnc' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c4_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c4_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_FrntCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_m;
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist_o = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_FrntDistZone4 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_m <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_o) && (MeAP_cm_FrntCenterMinXDist
         > DT24_CVADAS_AP_CodGen_DW.BoundaryDist_o) && KeAP_b_HeightFlagEnabled)
    {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a++;
      if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a >
          KeAP_cnt_CruisAgeBasedDbncCount) {
        DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_m <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_o) &&
             (MeAP_cm_FrntCenterMinXDist >
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_o) &&
             KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a++;
    if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a = 0U;
      MeAP_cm_FrntCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_m;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_a = 0U;
    MeAP_cm_FrntCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_m;
  }

  /* End of Chart: '<S92>/FC_Dbnc' */

  /* UnitDelay: '<Root>/Unit Delay3' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay3_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay4' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay4_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay5' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay5_DSTATE;

  /* UnitDelay: '<Root>/Unit Delay6' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay6_DSTATE;

  /* Outputs for Atomic SubSystem: '<S10>/DetectBlockage' */
  /* UnitDelay: '<S46>/Unit Delay' */
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 12;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist[DT24_CVADAS_AP_CodGen_B.i] =
      DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE[DT24_CVADAS_AP_CodGen_B.i];
  }

  /* End of UnitDelay: '<S46>/Unit Delay' */

  /* RelationalOperator: '<S44>/Relational Operator4' incorporates:
   *  Constant: '<S65>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_RhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S44>/Relational Operator5' incorporates:
   *  Constant: '<S66>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_LhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S44>/Relational Operator1' incorporates:
   *  Constant: '<S44>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig <= 0.4F);

  /* Logic: '<S44>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts &&
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* DataTypeConversion: '<S44>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Chart: '<S42>/Chart1' */
  if (DT24_CVADAS_AP_CodGen_DW.temporalCounter_i2 < 1023U) {
    DT24_CVADAS_AP_CodGen_DW.temporalCounter_i2++;
  }

  if (DT24_CVADAS_AP_CodGen_DW.temporalCounter_i1 < MAX_uint32_T) {
    DT24_CVADAS_AP_CodGen_DW.temporalCounter_i1++;
  }

  if (DT24_CVADAS_AP_CodGen_DW.is_active_c3_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c3_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c3_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_Default;
    DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts = false;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c3_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_Default) {
    if ((DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill == 0) &&
        (DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k ==
         TeAP_e_FiltdGearState_ReverseGear)) {
      DT24_CVADAS_AP_CodGen_DW.is_c3_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DetectBlockage;
      DT24_CVADAS_AP_CodGen_DW.temporalCounter_i2 = 0U;
      DT24_CVADAS_AP_CodGen_DW.is_DetectBlockage =
        DT24_CVADAS_AP_CodGen_IN_Default_c;
      DT24_CVADAS_AP_CodGen_B.ReverseBlockStateDebug = 0U;
      DT24_CVADAS_AP_CodGen_B.cnt = 0U;
    } else {
      DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts = false;
    }
  } else {
    /* case IN_DetectBlockage: */
    DT24_CVADAS_AP_CodGen_DetectBlockage();
  }

  /* End of Chart: '<S42>/Chart1' */

  /* Chart: '<S46>/FrontAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c64_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c64_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e;
    DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt++;
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e;
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert3:
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt++;
        break;

       default:
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e;
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
        break;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert4:
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF) {
       case TeAP_e_Alert_Arc3:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert3;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt++;
        break;

       default:
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_e;
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
        break;
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF) {
       case TeAP_e_Alert_Arc4:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert4;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc3:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert3;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c64_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt++;
        break;
		
	   default:
	   break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/FrontAlertCount' */

  /* Chart: '<S46>/RearAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c39_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c39_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
    DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert3:
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       default:
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
        break;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert4:
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR) {
       case TeAP_e_Alert_Arc3:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert3;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       default:
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
        }
        break;
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert5:
      if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR ==
           TeAP_e_Alert_NoObjectDetected) ||
          (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_SNA)) {
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
      } else {
        switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR) {
         case TeAP_e_Alert_Arc4:
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_Alert4;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
            DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
          break;

         case TeAP_e_Alert_Arc3:
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_Alert3;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
            DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
          break;
		     default:
	        break;
        }
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert6:
      if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR ==
           TeAP_e_Alert_NoObjectDetected) ||
          (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR == TeAP_e_Alert_SNA)) {
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected_a;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = ((uint8_T)CeAP_k_Uint8Zero);
      } else {
        switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR) {
         case TeAP_e_Alert_Arc5:
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_Alert5;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
            DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
          break;

         case TeAP_e_Alert_Arc4:
          DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_Alert4;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
            DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
          break;
		     default:
	        break;
        }
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR) {
       case TeAP_e_Alert_Arc6:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert6;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc5:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert5;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc4:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert4;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc3:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert3;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c39_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt + ((uint8_T)CeAP_k_Uint8One));
        break;
       default:
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/RearAlertCount' */

  /* Chart: '<S46>/FLAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c37_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c37_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
    DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d++;
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c37_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d++;
        break;
       default:
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/FLAlertCount' */

  /* Chart: '<S46>/RLAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c67_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c67_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
    DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a + ((uint8_T)CeAP_k_Uint8One));
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c67_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a + ((uint8_T)CeAP_k_Uint8One));
        break;
       default:
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/RLAlertCount' */

  /* Chart: '<S46>/FRAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c60_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c60_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
    DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p++;
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c60_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p++;
        break;
       default:
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/FRAlertCount' */

  /* Chart: '<S46>/RRAlertCount' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c38_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c38_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
    DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
  } else {
    switch (DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen) {
     case DT24_CVADAS_AP_CodGen_IN_Alert1:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR != TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
      }
      break;

     case DT24_CVADAS_AP_CodGen_IN_Alert2:
      if (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR == TeAP_e_Alert_Arc1) {
        DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p + ((uint8_T)CeAP_k_Uint8One));
      } else {
        if ((DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR ==
             TeAP_e_Alert_NoObjectDetected) ||
            (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR == TeAP_e_Alert_SNA)) {
          DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
            DT24_CVADAS_AP_CodGen_IN_NoObjectDetected;
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = ((uint8_T)CeAP_k_Uint8Zero);
        }
      }
      break;

     default:
      /* case IN_NoObjectDetected: */
      switch (DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR) {
       case TeAP_e_Alert_Arc2:
        DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert2;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p + ((uint8_T)CeAP_k_Uint8One));
        break;

       case TeAP_e_Alert_Arc1:
        DT24_CVADAS_AP_CodGen_DW.is_c38_DT24_CVADAS_AP_CodGen =
          DT24_CVADAS_AP_CodGen_IN_Alert1;
        DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p = (uint8_T)((uint32_T)
          DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p + ((uint8_T)CeAP_k_Uint8One));
        break;
       default:
        break;
      }
      break;
    }
  }

  /* End of Chart: '<S46>/RRAlertCount' */

  /* SignalConversion generated from: '<S43>/ SFunction ' incorporates:
   *  Chart: '<S40>/CalcRadialDistToSensor'
   */
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[0] =
    DT24_CVADAS_AP_CodGen_B.FSL_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[1] =
    DT24_CVADAS_AP_CodGen_B.FOL_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[2] =
    DT24_CVADAS_AP_CodGen_B.FIL_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[3] =
    DT24_CVADAS_AP_CodGen_B.FIR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[4] =
    DT24_CVADAS_AP_CodGen_B.FOR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[5] =
    DT24_CVADAS_AP_CodGen_B.FSR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[6] =
    DT24_CVADAS_AP_CodGen_B.RSR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[7] =
    DT24_CVADAS_AP_CodGen_B.ROR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[8] =
    DT24_CVADAS_AP_CodGen_B.RIR_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[9] =
    DT24_CVADAS_AP_CodGen_B.RIL_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[10] =
    DT24_CVADAS_AP_CodGen_B.ROL_x;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[11] =
    DT24_CVADAS_AP_CodGen_B.RSL_x;

  /* SignalConversion generated from: '<S43>/ SFunction ' incorporates:
   *  Chart: '<S40>/CalcRadialDistToSensor'
   */
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[0] =
    DT24_CVADAS_AP_CodGen_B.FSL_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[1] =
    DT24_CVADAS_AP_CodGen_B.FOL_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[2] =
    DT24_CVADAS_AP_CodGen_B.FIL_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[3] =
    DT24_CVADAS_AP_CodGen_B.FIR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[4] =
    DT24_CVADAS_AP_CodGen_B.FOR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[5] =
    DT24_CVADAS_AP_CodGen_B.FSR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[6] =
    DT24_CVADAS_AP_CodGen_B.RSR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[7] =
    DT24_CVADAS_AP_CodGen_B.ROR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[8] =
    DT24_CVADAS_AP_CodGen_B.RIR_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[9] =
    DT24_CVADAS_AP_CodGen_B.RIL_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[10] =
    DT24_CVADAS_AP_CodGen_B.ROL_y;
  DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[11] =
    DT24_CVADAS_AP_CodGen_B.RSL_y;

  /* Chart: '<S40>/CalcRadialDistToSensor' */
  DT24_CVADAS_AP_CodGen_B.MaxDist = (int16_T)roundf(1023.0F);
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 12;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_B.RadialDist[DT24_CVADAS_AP_CodGen_B.i] = 1046529;
  }

  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 12;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_B.RadialDistSqrt[DT24_CVADAS_AP_CodGen_B.i] = 1023.0F;
  }

  DT24_CVADAS_AP_CodGen_B.point_index = 1U;
  while (DT24_CVADAS_AP_CodGen_B.point_index <= ((uint8_T)96U)) {
    DT24_CVADAS_AP_CodGen_B.u0 = (int16_T)-DT24_CVADAS_AP_CodGen_B.MaxDist;
    DT24_CVADAS_AP_CodGen_B.i = DT24_CVADAS_AP_CodGen_B.point_index - 1;
    if (DT24_CVADAS_AP_CodGen_B.u0 <=
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .x) {
      DT24_CVADAS_AP_CodGen_B.u0 =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .x;
    }

    if (DT24_CVADAS_AP_CodGen_B.u0 >= DT24_CVADAS_AP_CodGen_B.MaxDist) {
      DT24_CVADAS_AP_CodGen_B.u0 = DT24_CVADAS_AP_CodGen_B.MaxDist;
    }

    DT24_CVADAS_AP_CodGen_B.u0_c = (int16_T)-DT24_CVADAS_AP_CodGen_B.MaxDist;
    if (DT24_CVADAS_AP_CodGen_B.u0_c <=
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .y) {
      DT24_CVADAS_AP_CodGen_B.u0_c =
        DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
        .y;
    }

    if (DT24_CVADAS_AP_CodGen_B.u0_c >= DT24_CVADAS_AP_CodGen_B.MaxDist) {
      DT24_CVADAS_AP_CodGen_B.u0_c = DT24_CVADAS_AP_CodGen_B.MaxDist;
    }

    DT24_CVADAS_AP_CodGen_B.sensor_index = 1U;
    while ((DT24_CVADAS_AP_CodGen_B.sensor_index <= ((uint8_T)
             CeAP_cnt_SensorCount)) &&
           (DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap.pointMap[DT24_CVADAS_AP_CodGen_B.i]
            .confidence > ((uint8_T)KeAP_pct_SenBlockPntConfThd))) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.sensor_index - 1;
      DT24_CVADAS_AP_CodGen_B.a = DT24_CVADAS_AP_CodGen_B.u0 -
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport2_j[DT24_CVADAS_AP_CodGen_B.a_tmp];
      DT24_CVADAS_AP_CodGen_B.current_RadialDist = 1;
      DT24_CVADAS_AP_CodGen_B.bu = 2U;
      do {
        exitg1 = 0;
        if ((DT24_CVADAS_AP_CodGen_B.bu & 1U) != 0U) {
          DT24_CVADAS_AP_CodGen_B.current_RadialDist *=
            DT24_CVADAS_AP_CodGen_B.a;
        }

        DT24_CVADAS_AP_CodGen_B.bu >>= 1U;
        if ((int32_T)DT24_CVADAS_AP_CodGen_B.bu == 0) {
          exitg1 = 1;
        } else {
          DT24_CVADAS_AP_CodGen_B.a *= DT24_CVADAS_AP_CodGen_B.a;
        }
      } while (exitg1 == 0);

      DT24_CVADAS_AP_CodGen_B.a = DT24_CVADAS_AP_CodGen_B.u0_c -
        DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[DT24_CVADAS_AP_CodGen_B.a_tmp];
      DT24_CVADAS_AP_CodGen_B.b_a = DT24_CVADAS_AP_CodGen_B.a;
      DT24_CVADAS_AP_CodGen_B.b_c = 1;
      DT24_CVADAS_AP_CodGen_B.bu = 2U;
      do {
        exitg1 = 0;
        if ((DT24_CVADAS_AP_CodGen_B.bu & 1U) != 0U) {
          DT24_CVADAS_AP_CodGen_B.b_c *= DT24_CVADAS_AP_CodGen_B.b_a;
        }

        DT24_CVADAS_AP_CodGen_B.bu >>= 1U;
        if ((int32_T)DT24_CVADAS_AP_CodGen_B.bu == 0) {
          exitg1 = 1;
        } else {
          DT24_CVADAS_AP_CodGen_B.b_a *= DT24_CVADAS_AP_CodGen_B.b_a;
        }
      } while (exitg1 == 0);

      DT24_CVADAS_AP_CodGen_B.current_RadialDist += DT24_CVADAS_AP_CodGen_B.b_c;
      if ((DT24_CVADAS_AP_CodGen_B.RadialDist[DT24_CVADAS_AP_CodGen_B.a_tmp] >
           DT24_CVADAS_AP_CodGen_B.current_RadialDist) &&
          ((DT24_CVADAS_AP_CodGen_B.a < 15) ||
           (DT24_CVADAS_AP_CodGen_B.TmpSignalConversionAtSFunctionInport3[DT24_CVADAS_AP_CodGen_B.a_tmp]
            - DT24_CVADAS_AP_CodGen_B.u0_c < 15))) {
        DT24_CVADAS_AP_CodGen_B.RadialDist[DT24_CVADAS_AP_CodGen_B.a_tmp] =
          DT24_CVADAS_AP_CodGen_B.current_RadialDist;
        if (DT24_CVADAS_AP_CodGen_B.current_RadialDist >= 500000) {
          DT24_CVADAS_AP_CodGen_B.current_RadialDist = 500000;
        }

        if (0 > DT24_CVADAS_AP_CodGen_B.current_RadialDist) {
          DT24_CVADAS_AP_CodGen_B.current_RadialDist = 0;
        }

        DT24_CVADAS_AP_CodGen_B.RadialDistSqrt[DT24_CVADAS_AP_CodGen_B.a_tmp] =
          sqrtf((real32_T)DT24_CVADAS_AP_CodGen_B.current_RadialDist);
      }

      DT24_CVADAS_AP_CodGen_B.sensor_index++;
    }

    DT24_CVADAS_AP_CodGen_B.point_index++;
  }

  /* RelationalOperator: '<S46>/Relational Operator' incorporates:
   *  Constant: '<S46>/Constant12'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FrntAlertCnt >= ((uint8_T)3U));

  /* DataTypeConversion: '<S46>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Chart: '<S46>/FIL_Blk' incorporates:
   *  Constant: '<S46>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_FIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)3U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_g,
    &DT24_CVADAS_AP_CodGen_DW.sf_FIL_Blk);

  /* Chart: '<S46>/FIR_Blk' incorporates:
   *  Constant: '<S46>/Constant3'
   */
  DT24_CVADAS_AP_CodGen_FIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)4U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_ht,
    &DT24_CVADAS_AP_CodGen_DW.sf_FIR_Blk);

  /* Chart: '<S46>/FOL_Blk' incorporates:
   *  Constant: '<S46>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_FIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)2U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_f,
    &DT24_CVADAS_AP_CodGen_DW.sf_FOL_Blk);

  /* Chart: '<S46>/FOR_Blk' incorporates:
   *  Constant: '<S46>/Constant4'
   */
  DT24_CVADAS_AP_CodGen_FIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)5U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_mm,
    &DT24_CVADAS_AP_CodGen_DW.sf_FOR_Blk);

  /* RelationalOperator: '<S46>/Relational Operator2' incorporates:
   *  Constant: '<S46>/Constant14'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_d >= ((uint8_T)2U));

  /* DataTypeConversion: '<S46>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S46>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator_h =
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag != 0) ||
     (DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 != 0));

  /* Chart: '<S46>/FSL_Blk' incorporates:
   *  Constant: '<S46>/Constant'
   */
  DT24_CVADAS_AP_CodGen_FSL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)1U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.LogicalOperator_h,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_d,
    &DT24_CVADAS_AP_CodGen_DW.sf_FSL_Blk);

  /* RelationalOperator: '<S46>/Relational Operator4' incorporates:
   *  Constant: '<S46>/Constant16'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FrntAlertCnt_p >= ((uint8_T)2U));

  /* DataTypeConversion: '<S46>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S46>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator1 =
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_FrntArcTrackFlag != 0) ||
     (DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 != 0));

  /* Chart: '<S46>/FSR_Blk' incorporates:
   *  Constant: '<S46>/Constant5'
   */
  DT24_CVADAS_AP_CodGen_FSL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)6U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.LogicalOperator1,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_h,
    &DT24_CVADAS_AP_CodGen_DW.sf_FSR_Blk);

  /* RelationalOperator: '<S46>/Relational Operator1' incorporates:
   *  Constant: '<S46>/Constant13'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.RearAlertCnt >= ((uint8_T)4U));

  /* DataTypeConversion: '<S46>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Chart: '<S46>/RIL_Blk' incorporates:
   *  Constant: '<S46>/Constant9'
   */
  DT24_CVADAS_AP_CodGen_RIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)10U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_n,
    &DT24_CVADAS_AP_CodGen_DW.sf_RIL_Blk);

  /* Chart: '<S46>/RIR_Blk' incorporates:
   *  Constant: '<S46>/Constant8'
   */
  DT24_CVADAS_AP_CodGen_RIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)9U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_e,
    &DT24_CVADAS_AP_CodGen_DW.sf_RIR_Blk);

  /* Chart: '<S46>/ROL_Blk' incorporates:
   *  Constant: '<S46>/Constant10'
   */
  DT24_CVADAS_AP_CodGen_RIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)11U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_a,
    &DT24_CVADAS_AP_CodGen_DW.sf_ROL_Blk);

  /* Chart: '<S46>/ROR_Blk' incorporates:
   *  Constant: '<S46>/Constant7'
   */
  DT24_CVADAS_AP_CodGen_RIL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)8U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_m,
    &DT24_CVADAS_AP_CodGen_DW.sf_ROR_Blk);

  /* RelationalOperator: '<S46>/Relational Operator3' incorporates:
   *  Constant: '<S46>/Constant15'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.RearAlertCnt_a >= ((uint8_T)2U));

  /* DataTypeConversion: '<S46>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S46>/Logical Operator3' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator3 =
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag != 0) ||
     (DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 != 0));

  /* Chart: '<S46>/RSL_Blk' incorporates:
   *  Constant: '<S46>/Constant11'
   */
  DT24_CVADAS_AP_CodGen_RSL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)12U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.LogicalOperator3,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_l,
    &DT24_CVADAS_AP_CodGen_DW.sf_RSL_Blk);

  /* RelationalOperator: '<S46>/Relational Operator5' incorporates:
   *  Constant: '<S46>/Constant17'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.RearAlertCnt_p >= ((uint8_T)2U));

  /* DataTypeConversion: '<S46>/Data Type Conversion5' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S46>/Logical Operator2' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator2 =
    ((DT24_CVADAS_AP_CodGen_B.MeAP_b_RearArcTrackFlag != 0) ||
     (DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 != 0));

  /* Chart: '<S46>/RSR_Blk' incorporates:
   *  Constant: '<S46>/Constant6'
   */
  DT24_CVADAS_AP_CodGen_RSL_Blk(DT24_CVADAS_AP_CodGen_B.RadialDistSqrt,
    ((uint8_T)7U), DT24_CVADAS_AP_CodGen_B.Product2,
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill,
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k,
    DT24_CVADAS_AP_CodGen_B.LogicalOperator2,
    DT24_CVADAS_AP_CodGen_B.PrevRadialDist,
    &DT24_CVADAS_AP_CodGen_B.SensorBlockStatus,
    &DT24_CVADAS_AP_CodGen_DW.sf_RSR_Blk);

  /* Logic: '<S42>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    ((DT24_CVADAS_AP_CodGen_B.SensorBlockStatus != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_m != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_e != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_n != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_a != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_l != 0));

  /* DataTypeConversion: '<S42>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.RearSensorBlockage =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S42>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    ((DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_d != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_f != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_g != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_ht != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_mm != 0) ||
     (DT24_CVADAS_AP_CodGen_B.SensorBlockStatus_h != 0));

  /* DataTypeConversion: '<S42>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* DataTypeConversion: '<S42>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear =
    DT24_CVADAS_AP_CodGen_B.FrontSensorBlockSts;

  /* Logic: '<S42>/Logical Operator2' */
  DT24_CVADAS_AP_CodGen_B.FrontSensorBlockage =
    ((DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 != 0) ||
     (DT24_CVADAS_AP_CodGen_B.FrontBlockageInReverseGear != 0));

  /* Update for UnitDelay: '<S46>/Unit Delay' */
  for (DT24_CVADAS_AP_CodGen_B.i = 0; DT24_CVADAS_AP_CodGen_B.i < 12;
       DT24_CVADAS_AP_CodGen_B.i++) {
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE[DT24_CVADAS_AP_CodGen_B.i] =
      DT24_CVADAS_AP_CodGen_B.RadialDistSqrt[DT24_CVADAS_AP_CodGen_B.i];
  }

  /* End of Update for UnitDelay: '<S46>/Unit Delay' */
  /* End of Outputs for SubSystem: '<S10>/DetectBlockage' */

  /* Logic: '<S18>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FrontSensorBlockage ||
     DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_FrntSenorBlock);

  /* Logic: '<S18>/Logical Operator1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IbFID_PA.MeAP_b_RearSenorBlock ||
     (DT24_CVADAS_AP_CodGen_B.RearSensorBlockage != 0));

  /* BusAssignment: '<S18>/Bus Assignment' */
  DT24_CVADAS_AP_CodGen_B.BusAssignment_b = DT24_CVADAS_AP_CodGen_B.IbFID_PA;
  DT24_CVADAS_AP_CodGen_B.BusAssignment_b.MeAP_b_FrntSenorBlock =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  DT24_CVADAS_AP_CodGen_B.BusAssignment_b.MeAP_b_RearSenorBlock =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;

  /* Switch: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   */
  if (KePA_b_EnbAppBlckg) {
    DT24_CVADAS_AP_CodGen_B.Switch = DT24_CVADAS_AP_CodGen_B.BusAssignment_b;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch = DT24_CVADAS_AP_CodGen_B.IbFID_PA;
  }

  /* End of Switch: '<S3>/Switch' */

  /* DataStoreRead: '<S2>/FID_STRUCT_QM_data' */
  //DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e = SigMgr_Data_FID_STRUCT_QM_Get();
  SigMgr_Data_FID_STRUCT_QM_Get(&DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e);

  /* DataTypeConversion: '<S8>/Data Type Conversion119' */
  MeAP_b_PARBActvTrlr_27 =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_LIMITED_ActTrlr_27 !=
     0);

  /* DataTypeConversion: '<S8>/Data Type Conversion7' */
  MeAP_b_PARBActvTrlr_29 =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_LIMITED_ActTrlr_29 !=
     0);

  /* DataTypeConversion: '<S8>/Data Type Conversion120' */
  MeAP_b_PARBActv4LOW =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_LIMITED_Act4LOW != 0);

  /* DataTypeConversion: '<S8>/D ata Type Conversion121' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_DISABLED_External_failure
     != 0);

  /* DataTypeConversion: '<S8>/D ata Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_DISABLED_System_failure
     != 0);

  /* DataTypeConversion: '<S8>/D ata Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_QM_e.m_QM_FID_PARB_DISABLED_RearSensorBlockage
     != 0);

  /* Logic: '<S8>/Logical Operator3' */
  MeAP_b_PARBDiable = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
                       DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
                       DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* BusCreator: '<S8>/Bus Creator4' */
  DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActvTrlr_27 =
    MeAP_b_PARBActvTrlr_27;
  DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActvTrlr_29 =
    MeAP_b_PARBActvTrlr_29;
  DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActv4LOW = MeAP_b_PARBActv4LOW;
  DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBDiable = MeAP_b_PARBDiable;

  /* DataTypeConversion: '<S8>/Data Type Conversion122' */
  MeAP_b_PPPAActvTrlr =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_LIMITED_ActTrlr_27
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion123' */
  MeAP_b_PPPAActv4LOW =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_LIMITED_ActLOW != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion124' */
  MeAP_b_PPPADefEng =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_LIMITED_DefEng != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion125' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_DISABLED_External_failure
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion5' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_DISABLED_System_failure
     != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_CAM_CAL_ABORT != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_DLD_DISABLED != 0);

  /* DataTypeConversion: '<S8>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j =
    (DT24_CVADAS_AP_CodGen_B.FID_STRUCT_ASIL_B.m_B_FID_PPPA_DISABLED_SensorBlockage
     != 0);

  /* Logic: '<S8>/Logical Operator4' */
  MeAP_b_PPPADisable = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
                        DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
                        DT24_CVADAS_AP_CodGen_B.RelationalOperator_e ||
                        DT24_CVADAS_AP_CodGen_B.DataTypeConversion3_p ||
                        DT24_CVADAS_AP_CodGen_B.DataTypeConversion4_j);

  /* BusCreator: '<S8>/Bus Creator5' */
  DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActvTrlr = MeAP_b_PPPAActvTrlr;
  DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActv4LOW = MeAP_b_PPPAActv4LOW;
  DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPADefEng = MeAP_b_PPPADefEng;
  DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPADisable = MeAP_b_PPPADisable;

  /* DataStoreRead: '<S2>/HMIInfoToAP_data' */
  //DT24_CVADAS_AP_CodGen_B.HMIInfoToAP = SigMgr_Data_HMIInfoToAP_t_Get();
  SigMgr_Data_HMIInfoToAP_t_Get(&DT24_CVADAS_AP_CodGen_B.HMIInfoToAP);

  /* RelationalOperator: '<S11>/Relational Operator8' incorporates:
   *  Constant: '<S77>/Constant'
   */
  IeHMI_b_UsrSlotSelStatus =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.HMI_ButtonPressed == PARK_SLOT_PRESSED);

  /* RelationalOperator: '<S11>/Relational Operator3' incorporates:
   *  Constant: '<S80>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType == RIGHT_FRONT_IN);

  /* RelationalOperator: '<S11>/Relational Operator4' incorporates:
   *  Constant: '<S81>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType == LEFT_FRONT_IN);

  /* Logic: '<S11>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* Switch: '<S11>/Switch' incorporates:
   *  Constant: '<S84>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    IeHMI_e_ParkStyle = TeAutoPark_e_ParkStyle_Front_In;
  } else {
    /* RelationalOperator: '<S11>/Relational Operator6' incorporates:
     *  Constant: '<S83>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator6_n =
      (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType == LEFT_REAR_IN);

    /* RelationalOperator: '<S11>/Relational Operator5' incorporates:
     *  Constant: '<S82>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.LogicalOperator1_a =
      (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType == RIGHT_REAR_IN);

    /* Logic: '<S11>/Logical Operator1' */
    DT24_CVADAS_AP_CodGen_B.LogicalOperator1_a =
      (DT24_CVADAS_AP_CodGen_B.LogicalOperator1_a ||
       DT24_CVADAS_AP_CodGen_B.RelationalOperator6_n);

    /* Switch: '<S11>/Switch1' incorporates:
     *  Constant: '<S85>/Constant'
     *  Constant: '<S86>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.LogicalOperator1_a) {
      DT24_CVADAS_AP_CodGen_B.Switch1 = TeAutoPark_e_ParkStyle_Rear_In;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1 = TeAutoPark_e_ParkStyle_None;
    }

    /* End of Switch: '<S11>/Switch1' */
    IeHMI_e_ParkStyle = DT24_CVADAS_AP_CodGen_B.Switch1;
  }

  /* End of Switch: '<S11>/Switch' */

  /* Switch: '<S6>/Switch' incorporates:
   *  Constant: '<S6>/Constant'
   */
  if (KeAP_b_DevlopmentTest) {
    /* DataTypeConversion: '<S6>/Data Type Conversion' incorporates:
     *  Constant: '<S6>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion = (TeAutoPark_e_ParkStyle)
      KeHMI_e_ParkStyleTest;
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_ParkStyle_i =
      DT24_CVADAS_AP_CodGen_B.DataTypeConversion;
  } else {
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_ParkStyle_i = IeHMI_e_ParkStyle;
  }

  /* End of Switch: '<S6>/Switch' */

  /* RelationalOperator: '<S11>/Relational Operator7' incorporates:
   *  Constant: '<S69>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType ==
     RIGHT_FORWARD_OUT);

  /* Switch: '<S11>/Switch2' incorporates:
   *  Constant: '<S73>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    IeHMI_e_UsrParkOutSideSel = TeHMI_e_UsrParkOutSide_Right;
  } else {
    /* RelationalOperator: '<S11>/Relational Operator9' incorporates:
     *  Constant: '<S71>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator9_i =
      (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverType ==
       LEFT_FORWARD_OUT);

    /* Switch: '<S11>/Switch3' incorporates:
     *  Constant: '<S70>/Constant'
     *  Constant: '<S72>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator9_i) {
      DT24_CVADAS_AP_CodGen_B.Switch3 = TeHMI_e_UsrParkOutSide_Left;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch3 = TeHMI_e_UsrParkOutSide_None;
    }

    /* End of Switch: '<S11>/Switch3' */
    IeHMI_e_UsrParkOutSideSel = DT24_CVADAS_AP_CodGen_B.Switch3;
  }

  /* End of Switch: '<S11>/Switch2' */

  /* UnitDelay: '<Root>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp_o =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_j;

  /* RelationalOperator: '<S11>/Relational Operator10' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.DisplayedPopUp ==
     DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp_o);

  /* RelationalOperator: '<S11>/Relational Operator11' incorporates:
   *  Constant: '<S78>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp_o != TeAP_e_HMIPopUp_IDLE);

  /* Logic: '<S11>/Logical Operator2' */
  IeHMI_b_HMIHandshake = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* RelationalOperator: '<S11>/Relational Operator2' incorporates:
   *  Constant: '<S79>/Constant'
   */
  IeHMI_b_BackBtnPsd = (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.HMI_ButtonPressed ==
                        BACK_MODE_PRESSED);

  /* RelationalOperator: '<S11>/Relational Operator' incorporates:
   *  Constant: '<S67>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.HMI_ButtonPressed == PARK_MODE_PRESSED);

  /* Switch: '<S11>/Switch4' incorporates:
   *  Constant: '<S74>/Constant'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    IeHMI_e_UsrPPPAManeuverSel = TeAP_e_UsrPPPAManeuverSel_ParkIn;
  } else {
    /* RelationalOperator: '<S11>/Relational Operator1' incorporates:
     *  Constant: '<S68>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator1_f =
      (DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.HMI_ButtonPressed ==
       EXIT_MODE_PRESSED);

    /* Switch: '<S11>/Switch5' incorporates:
     *  Constant: '<S75>/Constant'
     *  Constant: '<S76>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator1_f) {
      DT24_CVADAS_AP_CodGen_B.Switch5 = TeAP_e_UsrPPPAManeuverSel_ParkExit;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch5 = TeAP_e_UsrPPPAManeuverSel_None;
    }

    /* End of Switch: '<S11>/Switch5' */
    IeHMI_e_UsrPPPAManeuverSel = DT24_CVADAS_AP_CodGen_B.Switch5;
  }

  /* End of Switch: '<S11>/Switch4' */

  /* DataTypeConversion: '<S11>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedMnvSlotType =
    DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverSlotType;

  /* DataTypeConversion: '<S11>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedMnvSlotSide =
    DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedManeuverSlotSide;

  /* DataTypeConversion: '<S11>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedSlotId =
    DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.SelectedSlotId;

  /* DataTypeConversion: '<S11>/Data Type Conversion3' */
  uLong2MultiWord(DT24_CVADAS_AP_CodGen_B.HMIInfoToAP.FressnessCounter,
                  &DT24_CVADAS_AP_CodGen_B.IeHMI_cnt_FressnessCounter.chunks[0U],
                  2);

  /* BusCreator: '<S3>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_UsrSlotSelStatus =
    IeHMI_b_UsrSlotSelStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_ParkStyle =
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_ParkStyle_i;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_UsrParkOutSideSel =
    IeHMI_e_UsrParkOutSideSel;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_HMIHandshake =
    IeHMI_b_HMIHandshake;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_BackBtnPsd = IeHMI_b_BackBtnPsd;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_UsrPPPAManeuverSel =
    IeHMI_e_UsrPPPAManeuverSel;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_SelectedMnvSlotType =
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedMnvSlotType;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_SelectedMnvSlotSide =
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedMnvSlotSide;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_SelectedSlotId =
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_SelectedSlotId;
  DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_cnt_FressnessCounter =
    DT24_CVADAS_AP_CodGen_B.IeHMI_cnt_FressnessCounter;

  /* DataStoreRead: '<S2>/VrntTunParam_data2' */
  // DT24_CVADAS_AP_CodGen_B.IbDiag_DiagToParkAssist =
  //   e_IpcMsgId_Data_DiagToParkAssist_t();
   SigMgr_Data_DiagToParkAssist_t_Get(&DT24_CVADAS_AP_CodGen_B.IbDiag_DiagToParkAssist);
  /* SignalConversion: '<S7>/Signal Conversion' */
  DT24_CVADAS_AP_CodGen_B.SignalConversion =
    DT24_CVADAS_AP_CodGen_B.IbDiag_DiagToParkAssist.IeDiag_b_ParkAssistSts;

  /* RelationalOperator: '<S169>/Relational Operator4' incorporates:
   *  Constant: '<S173>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_RhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S169>/Relational Operator5' incorporates:
   *  Constant: '<S174>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_e_LhfWhlSpnSts ==
     TeVBII_e_WhlSpnSts_StandStill);

  /* RelationalOperator: '<S169>/Relational Operator1' incorporates:
   *  Constant: '<S169>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.IeVBII_kph_VehSpeedVSOSig <= 0.4F);

  /* Logic: '<S169>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill_g =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts &&
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* Logic: '<S19>/Logical Operator2' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    !DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill_g;

  /* UnitDelay: '<S19>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_g;

  /* Logic: '<S19>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* UnitDelay: '<S167>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay2_h =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_j;

  /* Switch: '<S167>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    /* Sum: '<S167>/Add' incorporates:
     *  Constant: '<S167>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.Add = (uint16_T)((uint32_T)
      DT24_CVADAS_AP_CodGen_B.UnitDelay2_h + ((uint16_T)1U));
    DT24_CVADAS_AP_CodGen_B.Switch_p = DT24_CVADAS_AP_CodGen_B.Add;
  } else {
    /* RelationalOperator: '<S167>/Relational Operator3' incorporates:
     *  Constant: '<S170>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator3_i =
      (DT24_CVADAS_AP_CodGen_B.IeVBII_e_CmdIgnSts == TeVBII_e_CmdIgnSts_RUN);

    /* Switch: '<S167>/Switch1' incorporates:
     *  Constant: '<S167>/Constant1'
     */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator3_i) {
      DT24_CVADAS_AP_CodGen_B.Switch1_j1 = DT24_CVADAS_AP_CodGen_B.UnitDelay2_h;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_j1 = ((uint16_T)0U);
    }

    /* End of Switch: '<S167>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch_p = DT24_CVADAS_AP_CodGen_B.Switch1_j1;
  }

  /* End of Switch: '<S167>/Switch' */

  /* RelationalOperator: '<S167>/Relational Operator1' incorporates:
   *  Constant: '<S167>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Switch_p <= KeAP_cnt_VehMovementCntThd);

  /* Logic: '<S19>/Logical Operator3' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* UnitDelay: '<S168>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_md;

  /* Logic: '<S168>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.LogicalOperator =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* UnitDelay: '<S172>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_hd;

  /* Logic: '<S172>/Logical Operator9' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    !DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;

  /* Logic: '<S172>/Logical Operator8' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.LogicalOperator &&
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq);

  /* UnitDelay: '<S171>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay2_m =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_af;

  /* Switch: '<S171>/Switch3' incorporates:
   *  Constant: '<S168>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch3_n = KeAP_cnt_ForceNoiseModeTimeThd;
  } else {
    /* RelationalOperator: '<S171>/Relational Operator' incorporates:
     *  Constant: '<S168>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.ElapseTimer = (KeAP_cnt_TimeStep <=
      DT24_CVADAS_AP_CodGen_B.UnitDelay2_m);

    /* Logic: '<S171>/Logical Operator3' */
    DT24_CVADAS_AP_CodGen_B.ElapseTimer = (DT24_CVADAS_AP_CodGen_B.ElapseTimer &&
      DT24_CVADAS_AP_CodGen_ConstB.LogicalOperator1);

    /* Switch: '<S171>/Switch1' incorporates:
     *  Constant: '<S171>/Constant'
     */
    if (DT24_CVADAS_AP_CodGen_B.ElapseTimer) {
      /* Sum: '<S171>/Subtract' incorporates:
       *  Constant: '<S168>/Constant'
       */
      DT24_CVADAS_AP_CodGen_B.Subtract_l = (uint16_T)
        (DT24_CVADAS_AP_CodGen_B.UnitDelay2_m - KeAP_cnt_TimeStep);
      DT24_CVADAS_AP_CodGen_B.Switch1_l = DT24_CVADAS_AP_CodGen_B.Subtract_l;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_l = ((uint16_T)0U);
    }

    /* End of Switch: '<S171>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch3_n = DT24_CVADAS_AP_CodGen_B.Switch1_l;
  }

  /* End of Switch: '<S171>/Switch3' */

  /* RelationalOperator: '<S171>/Relational Operator1' incorporates:
   *  Constant: '<S168>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IsTimerElapsed = (KeAP_cnt_TimeStep >
    DT24_CVADAS_AP_CodGen_B.Switch3_n);

  /* Logic: '<S171>/Logical Operator4' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    !DT24_CVADAS_AP_CodGen_B.IsTimerElapsed;

  /* Logic: '<S19>/Logical Operator1' incorporates:
   *  Constant: '<S19>/Constant'
   */
  IeAP_b_DisForceNoiseMode = (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq &&
    KeAP_b_EnFeatForceNoiseMode);

  /* Logic: '<S155>/Logical Operator' incorporates:
   *  Constant: '<S155>/Constant'
   *  Logic: '<S156>/Logical Operator'
   *  Logic: '<S157>/Logical Operator'
   *  Logic: '<S158>/Logical Operator'
   *  Logic: '<S159>/Logical Operator'
   *  Logic: '<S160>/Logical Operator'
   *  Logic: '<S161>/Logical Operator'
   *  Logic: '<S162>/Logical Operator'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq_tmp = (IeAP_b_DisForceNoiseMode &&
    KeAP_b_SuppArcInNoForceNoise);
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq_tmp;

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S155>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_a = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_a = MeAP_cm_FrntCenterMinXDist;
  }

  /* End of Switch: '<S155>/Switch' */

  /* Abs: '<S92>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1 = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1 =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXRawDist;
  }

  /* End of Abs: '<S92>/Abs1' */

  /* Chart: '<S113>/DistDbnc' incorporates:
   *  Constant: '<S113>/Constant1'
   *  Constant: '<S113>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c13_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c13_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c13_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs1;
    DT24_CVADAS_AP_CodGen_DW.Timer_k = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c13_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c13_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_c =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer_k = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer_k > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_k
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs1;
      DT24_CVADAS_AP_CodGen_DW.Timer_k = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_c =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c13_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs1;
      DT24_CVADAS_AP_CodGen_DW.Timer_k = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_c ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs1 < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_c =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer_k = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_k > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs1;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_k + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_k > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_k
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs1 == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_c =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_k > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs1;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_k + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_k > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_k
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_k = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S113>/DistDbnc' */

  /* RelationalOperator: '<S123>/Compare' incorporates:
   *  Constant: '<S123>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut == 1023);

  /* UnitDelay: '<S110>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay_og =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_k;

  /* RelationalOperator: '<S122>/Compare' incorporates:
   *  Constant: '<S122>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.UnitDelay_og == 1023);

  /* Logic: '<S110>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* Switch: '<S110>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_i =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut;
  } else {
    /* Sum: '<S110>/Add' */
    DT24_CVADAS_AP_CodGen_B.Add_m = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntLeftMinXDistOut +
       DT24_CVADAS_AP_CodGen_B.UnitDelay_og);

    /* Product: '<S110>/Divide' incorporates:
     *  Constant: '<S110>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
    DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
      DT24_CVADAS_AP_CodGen_B.Add_m >= 0 ? MAX_int32_T : MIN_int32_T :
      DT24_CVADAS_AP_CodGen_B.Add_m / DT24_CVADAS_AP_CodGen_B.a_tmp;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
        DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.Divide_f = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

    /* End of Product: '<S110>/Divide' */

    /* RelationalOperator: '<S121>/Relational Operator' incorporates:
     *  Constant: '<S121>/Constant2'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_l =
      (DT24_CVADAS_AP_CodGen_B.Divide_f > KeAP_cm_FrntDistArcComp);

    /* Switch: '<S121>/Switch1' */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_l) {
      /* Sum: '<S121>/Add1' incorporates:
       *  Constant: '<S121>/Constant1'
       */
      DT24_CVADAS_AP_CodGen_B.Add1_k = (int16_T)
        (DT24_CVADAS_AP_CodGen_B.Divide_f - KeAP_cm_FrntDistArcComp);
      DT24_CVADAS_AP_CodGen_B.Switch1_l5 = DT24_CVADAS_AP_CodGen_B.Add1_k;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_l5 = DT24_CVADAS_AP_CodGen_B.Divide_f;
    }

    /* End of Switch: '<S121>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch_i = DT24_CVADAS_AP_CodGen_B.Switch1_l5;
  }

  /* End of Switch: '<S110>/Switch' */

  /* Chart: '<S92>/FC_Dbnc1' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c7_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c7_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_FrntLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_i;
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist_e = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_FrntDistZone2 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_i <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_e) && (MeAP_cm_FrntLeftMinXDist >
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_e) && KeAP_b_HeightFlagEnabled) {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o++;
      if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o >
          KeAP_cnt_CruisAgeBasedDbncCount) {
        DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_i <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_e) &&
             (MeAP_cm_FrntLeftMinXDist > DT24_CVADAS_AP_CodGen_DW.BoundaryDist_e)
             && KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o++;
    if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o = 0U;
      MeAP_cm_FrntLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_i;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount_o = 0U;
    MeAP_cm_FrntLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_i;
  }

  /* End of Chart: '<S92>/FC_Dbnc1' */

  /* Switch: '<S156>/Switch' incorporates:
   *  Constant: '<S156>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_c = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_c = MeAP_cm_FrntLeftMinXDist;
  }

  /* End of Switch: '<S156>/Switch' */

  /* Abs: '<S92>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2 = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2 =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXRawDist;
  }

  /* End of Abs: '<S92>/Abs2' */

  /* Chart: '<S114>/DistDbnc' incorporates:
   *  Constant: '<S114>/Constant1'
   *  Constant: '<S114>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c14_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c14_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c14_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs2;
    DT24_CVADAS_AP_CodGen_DW.Timer_m = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c14_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c14_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_l =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer_m = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer_m > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_m
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs2;
      DT24_CVADAS_AP_CodGen_DW.Timer_m = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_l =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c14_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs2;
      DT24_CVADAS_AP_CodGen_DW.Timer_m = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_l ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs2 < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_l =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer_m = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_m > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs2;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_m + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_m > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_m
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs2 == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_l =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_m > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs2;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_m + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_m > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_m
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_m = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S114>/DistDbnc' */

  /* RelationalOperator: '<S126>/Compare' incorporates:
   *  Constant: '<S126>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut == 1023);

  /* UnitDelay: '<S111>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.UnitDelay_a =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_c;

  /* RelationalOperator: '<S125>/Compare' incorporates:
   *  Constant: '<S125>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.UnitDelay_a == 1023);

  /* Logic: '<S111>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* Switch: '<S111>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_e =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut;
  } else {
    /* Sum: '<S111>/Add' */
    DT24_CVADAS_AP_CodGen_B.Add_f = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_FrntRightMinXDistOut +
       DT24_CVADAS_AP_CodGen_B.UnitDelay_a);

    /* Product: '<S111>/Divide' incorporates:
     *  Constant: '<S111>/Constant'
     */
    DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
    DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
      DT24_CVADAS_AP_CodGen_B.Add_f >= 0 ? MAX_int32_T : MIN_int32_T :
      DT24_CVADAS_AP_CodGen_B.Add_f / DT24_CVADAS_AP_CodGen_B.a_tmp;
    if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
    } else {
      if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
        DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
      }
    }

    DT24_CVADAS_AP_CodGen_B.Divide_a = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

    /* End of Product: '<S111>/Divide' */

    /* RelationalOperator: '<S124>/Relational Operator' incorporates:
     *  Constant: '<S124>/Constant2'
     */
    DT24_CVADAS_AP_CodGen_B.RelationalOperator_p =
      (DT24_CVADAS_AP_CodGen_B.Divide_a > KeAP_cm_FrntDistArcComp);

    /* Switch: '<S124>/Switch1' */
    if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_p) {
      /* Sum: '<S124>/Add1' incorporates:
       *  Constant: '<S124>/Constant1'
       */
      DT24_CVADAS_AP_CodGen_B.Add1_e = (int16_T)
        (DT24_CVADAS_AP_CodGen_B.Divide_a - KeAP_cm_FrntDistArcComp);
      DT24_CVADAS_AP_CodGen_B.Switch1_jm = DT24_CVADAS_AP_CodGen_B.Add1_e;
    } else {
      DT24_CVADAS_AP_CodGen_B.Switch1_jm = DT24_CVADAS_AP_CodGen_B.Divide_a;
    }

    /* End of Switch: '<S124>/Switch1' */
    DT24_CVADAS_AP_CodGen_B.Switch_e = DT24_CVADAS_AP_CodGen_B.Switch1_jm;
  }

  /* End of Switch: '<S111>/Switch' */

  /* Chart: '<S92>/FC_Dbnc2' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c8_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c8_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_FrntRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_e;
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist_f = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_FrntDistZone2 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_e <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_f) && (MeAP_cm_FrntRightMinXDist >
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_f) && KeAP_b_HeightFlagEnabled) {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount++;
      if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount > KeAP_cnt_CruisAgeBasedDbncCount)
      {
        DT24_CVADAS_AP_CodGen_DW.FCDbncCount = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_e <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_f) &&
             (MeAP_cm_FrntRightMinXDist >
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_f) &&
             KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount++;
    if (DT24_CVADAS_AP_CodGen_DW.FCDbncCount > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.FCDbncCount = 0U;
      MeAP_cm_FrntRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_e;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.FCDbncCount = 0U;
    MeAP_cm_FrntRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_e;
  }

  /* End of Chart: '<S92>/FC_Dbnc2' */

  /* Switch: '<S157>/Switch' incorporates:
   *  Constant: '<S157>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_l3 = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_l3 = MeAP_cm_FrntRightMinXDist;
  }

  /* End of Switch: '<S157>/Switch' */

  /* Abs: '<S93>/Abs' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs_f = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXRawDist;
  }

  /* End of Abs: '<S93>/Abs' */

  /* Chart: '<S133>/DistDbnc' incorporates:
   *  Constant: '<S133>/Constant1'
   *  Constant: '<S133>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c15_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c15_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c15_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs_f;
    DT24_CVADAS_AP_CodGen_DW.Timer_b = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c15_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c15_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_j =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer_b = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer_b > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs_f;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_b
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs_f;
      DT24_CVADAS_AP_CodGen_DW.Timer_b = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_j =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c15_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs_f;
      DT24_CVADAS_AP_CodGen_DW.Timer_b = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_j ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs_f < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_j =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer_b = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_b > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs_f;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_b + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_b > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs_f;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_b
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs_f == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_j =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_b > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs_f;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_b + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_b > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs_f;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_b
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_b = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S133>/DistDbnc' */

  /* Switch: '<S93>/Switch1' incorporates:
   *  Constant: '<S93>/Constant2'
   */
  if (KeAP_b_HookConnected) {
    /* Sum: '<S93>/Subtract1' incorporates:
     *  Constant: '<S93>/Constant4'
     */
    DT24_CVADAS_AP_CodGen_B.Subtract1 = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut -
       KeAP_cm_HookDistOffset);
    DT24_CVADAS_AP_CodGen_B.Abs3_f = DT24_CVADAS_AP_CodGen_B.Subtract1;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearCenterMinXDistOut;
  }

  /* End of Switch: '<S93>/Switch1' */

  /* RelationalOperator: '<S142>/Compare' incorporates:
   *  Constant: '<S142>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Abs3_f == 1023);

  /* UnitDelay: '<S130>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_l;

  /* RelationalOperator: '<S141>/Compare' incorporates:
   *  Constant: '<S141>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g == 1023);

  /* Logic: '<S130>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* UnitDelay: '<S130>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_h;

  /* Sum: '<S130>/Add' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g += DT24_CVADAS_AP_CodGen_B.Abs3_f;

  /* Product: '<S130>/Divide' incorporates:
   *  Constant: '<S130>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
  DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g >= 0 ? MAX_int32_T :
    MIN_int32_T : DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g /
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.Divide = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* End of Product: '<S130>/Divide' */

  /* RelationalOperator: '<S140>/Relational Operator' incorporates:
   *  Constant: '<S140>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e = (DT24_CVADAS_AP_CodGen_B.Divide
    > KeAP_cm_RearDistArcComp);

  /* Switch: '<S140>/Switch1' */
  if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e) {
    /* Sum: '<S140>/Add1' incorporates:
     *  Constant: '<S140>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.Add1_c = (int16_T)(DT24_CVADAS_AP_CodGen_B.Divide -
      KeAP_cm_RearDistArcComp);
    DT24_CVADAS_AP_CodGen_B.Switch1_os = DT24_CVADAS_AP_CodGen_B.Add1_c;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch1_os = DT24_CVADAS_AP_CodGen_B.Divide;
  }

  /* End of Switch: '<S140>/Switch1' */

  /* Switch: '<S130>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_n = DT24_CVADAS_AP_CodGen_B.Abs3_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_n = DT24_CVADAS_AP_CodGen_B.Switch1_os;
  }

  /* End of Switch: '<S130>/Switch' */

  /* Chart: '<S93>/RC_Dbnc' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c2_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c2_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_RearCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_n;
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist_c = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_DistZone6 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_n <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_c) && (MeAP_cm_RearCenterMinXDist
         > DT24_CVADAS_AP_CodGen_DW.BoundaryDist_c) && KeAP_b_HeightFlagEnabled)
    {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d++;
      if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d >
          KeAP_cnt_CruisAgeBasedDbncCount) {
        DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_n <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_c) &&
             (MeAP_cm_RearCenterMinXDist >
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_c) &&
             KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d++;
    if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d = 0U;
      MeAP_cm_RearCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_n;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_d = 0U;
    MeAP_cm_RearCenterMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_n;
  }

  /* End of Chart: '<S93>/RC_Dbnc' */

  /* Switch: '<S159>/Switch' incorporates:
   *  Constant: '<S159>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_j = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_j = MeAP_cm_RearCenterMinXDist;
  }

  /* End of Switch: '<S159>/Switch' */

  /* Abs: '<S93>/Abs1' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs1_n = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs1_n =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXRawDist;
  }

  /* End of Abs: '<S93>/Abs1' */

  /* Chart: '<S134>/DistDbnc' incorporates:
   *  Constant: '<S134>/Constant1'
   *  Constant: '<S134>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c16_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c16_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c16_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs1_n;
    DT24_CVADAS_AP_CodGen_DW.Timer_p = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c16_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c16_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_a =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer_p = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer_p > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1_n;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_p
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs1_n;
      DT24_CVADAS_AP_CodGen_DW.Timer_p = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_a =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c16_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs1_n;
      DT24_CVADAS_AP_CodGen_DW.Timer_p = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_a ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs1_n < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_a =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer_p = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_p > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs1_n;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_p + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_p > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1_n;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_p
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs1_n == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED_a =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer_p > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs1_n;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)
            DT24_CVADAS_AP_CodGen_DW.Timer_p + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)
            DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer_p > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs1_n;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer_p
          + CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer_p = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S134>/DistDbnc' */

  /* Switch: '<S93>/Switch2' incorporates:
   *  Constant: '<S93>/Constant5'
   */
  if (KeAP_b_HookConnected) {
    /* Sum: '<S93>/Subtract3' incorporates:
     *  Constant: '<S93>/Constant6'
     */
    DT24_CVADAS_AP_CodGen_B.Subtract3 = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut -
       KeAP_cm_HookDistOffset);
    DT24_CVADAS_AP_CodGen_B.Abs3_f = DT24_CVADAS_AP_CodGen_B.Subtract3;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearLeftMinXDistOut;
  }

  /* End of Switch: '<S93>/Switch2' */

  /* RelationalOperator: '<S145>/Compare' incorporates:
   *  Constant: '<S145>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Abs3_f == 1023);

  /* UnitDelay: '<S131>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_jj;

  /* RelationalOperator: '<S144>/Compare' incorporates:
   *  Constant: '<S144>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g == 1023);

  /* Logic: '<S131>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* UnitDelay: '<S131>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_j;

  /* Sum: '<S131>/Add' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g += DT24_CVADAS_AP_CodGen_B.Abs3_f;

  /* Product: '<S131>/Divide' incorporates:
   *  Constant: '<S131>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
  DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g >= 0 ? MAX_int32_T :
    MIN_int32_T : DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g /
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.Divide_d = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* End of Product: '<S131>/Divide' */

  /* RelationalOperator: '<S143>/Relational Operator' incorporates:
   *  Constant: '<S143>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.Divide_d > KeAP_cm_RearDistArcComp);

  /* Switch: '<S143>/Switch1' */
  if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e) {
    /* Sum: '<S143>/Add1' incorporates:
     *  Constant: '<S143>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.Add1_a = (int16_T)(DT24_CVADAS_AP_CodGen_B.Divide_d
      - KeAP_cm_RearDistArcComp);
    DT24_CVADAS_AP_CodGen_B.Switch1_c = DT24_CVADAS_AP_CodGen_B.Add1_a;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch1_c = DT24_CVADAS_AP_CodGen_B.Divide_d;
  }

  /* End of Switch: '<S143>/Switch1' */

  /* Switch: '<S131>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_nz = DT24_CVADAS_AP_CodGen_B.Abs3_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_nz = DT24_CVADAS_AP_CodGen_B.Switch1_c;
  }

  /* End of Switch: '<S131>/Switch' */

  /* Chart: '<S93>/RC_Dbnc1' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c5_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c5_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_RearLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_nz;
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist_a = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_DistZone2 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_nz <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_a) && (MeAP_cm_RearLeftMinXDist >
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist_a) && KeAP_b_HeightFlagEnabled) {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c++;
      if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c >
          KeAP_cnt_CruisAgeBasedDbncCount) {
        DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_nz <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist_a) &&
             (MeAP_cm_RearLeftMinXDist > DT24_CVADAS_AP_CodGen_DW.BoundaryDist_a)
             && KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c++;
    if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c = 0U;
      MeAP_cm_RearLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_nz;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount_c = 0U;
    MeAP_cm_RearLeftMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_nz;
  }

  /* End of Chart: '<S93>/RC_Dbnc1' */

  /* Switch: '<S160>/Switch' incorporates:
   *  Constant: '<S160>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_ev = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_ev = MeAP_cm_RearLeftMinXDist;
  }

  /* End of Switch: '<S160>/Switch' */

  /* Abs: '<S93>/Abs2' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs2_e = (int16_T)
      -DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs2_e =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXRawDist;
  }

  /* End of Abs: '<S93>/Abs2' */

  /* Chart: '<S135>/DistDbnc' incorporates:
   *  Constant: '<S135>/Constant1'
   *  Constant: '<S135>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c17_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c17_DT24_CVADAS_AP_CodGen = 1U;
    DT24_CVADAS_AP_CodGen_DW.is_c17_DT24_CVADAS_AP_CodGen =
      DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
    DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
      DT24_CVADAS_AP_CodGen_B.Abs2_e;
    DT24_CVADAS_AP_CodGen_DW.Timer = 0U;
  } else if (DT24_CVADAS_AP_CodGen_DW.is_c17_DT24_CVADAS_AP_CodGen ==
             DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED) {
    if (KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_c17_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_ENABLED;
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED =
        DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
      DT24_CVADAS_AP_CodGen_DW.Timer = 0U;
      if (DT24_CVADAS_AP_CodGen_DW.Timer > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2_e;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer +
          CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs2_e;
      DT24_CVADAS_AP_CodGen_DW.Timer = 0U;
    }
  } else {
    /* case IN_DBNC_ENABLED: */
    if (!KeAP_b_DbncEnabld) {
      DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED =
        DT24_CVADAS_AP_CodGen_IN_NO_ACTIVE_CHILD_c;
      DT24_CVADAS_AP_CodGen_DW.is_c17_DT24_CVADAS_AP_CodGen =
        DT24_CVADAS_AP_CodGen_IN_DBNC_DISABLED;
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
        DT24_CVADAS_AP_CodGen_B.Abs2_e;
      DT24_CVADAS_AP_CodGen_DW.Timer = 0U;
    } else if (DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED ==
               DT24_CVADAS_AP_CodGen_IN_RESET_DBNC) {
      if (DT24_CVADAS_AP_CodGen_B.Abs2_e < 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED =
          DT24_CVADAS_AP_CodGen_IN_SET_DBNC;
        DT24_CVADAS_AP_CodGen_DW.Timer = 0U;
        if (DT24_CVADAS_AP_CodGen_DW.Timer > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs2_e;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer
            + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2_e;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer +
          CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    } else {
      /* case IN_SET_DBNC: */
      if (DT24_CVADAS_AP_CodGen_B.Abs2_e == 1023) {
        DT24_CVADAS_AP_CodGen_DW.is_DBNC_ENABLED =
          DT24_CVADAS_AP_CodGen_IN_RESET_DBNC;
        DT24_CVADAS_AP_CodGen_B.bu = KeAP_ms_DbncTimeThsd + 1U;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        if (DT24_CVADAS_AP_CodGen_DW.Timer > KeAP_ms_DbncTimeThsd) {
          DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
            DT24_CVADAS_AP_CodGen_B.Abs2_e;
        } else {
          DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer
            + CeAP_ms_SampleTime;
          if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
            DT24_CVADAS_AP_CodGen_B.bu = 65535U;
          }

          DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
        }
      } else if (DT24_CVADAS_AP_CodGen_DW.Timer > KeAP_ms_DbncTimeThsd) {
        DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut =
          DT24_CVADAS_AP_CodGen_B.Abs2_e;
      } else {
        DT24_CVADAS_AP_CodGen_B.bu = (uint32_T)DT24_CVADAS_AP_CodGen_DW.Timer +
          CeAP_ms_SampleTime;
        if (DT24_CVADAS_AP_CodGen_B.bu > 65535U) {
          DT24_CVADAS_AP_CodGen_B.bu = 65535U;
        }

        DT24_CVADAS_AP_CodGen_DW.Timer = (uint16_T)DT24_CVADAS_AP_CodGen_B.bu;
      }
    }
  }

  /* End of Chart: '<S135>/DistDbnc' */

  /* Switch: '<S93>/Switch3' incorporates:
   *  Constant: '<S93>/Constant8'
   */
  if (KeAP_b_HookConnected) {
    /* Sum: '<S93>/Subtract5' incorporates:
     *  Constant: '<S93>/Constant9'
     */
    DT24_CVADAS_AP_CodGen_B.Subtract5 = (int16_T)
      (DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut -
       KeAP_cm_HookDistOffset);
    DT24_CVADAS_AP_CodGen_B.Abs3_f = DT24_CVADAS_AP_CodGen_B.Subtract5;
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_RearRightMinXDistOut;
  }

  /* End of Switch: '<S93>/Switch3' */

  /* RelationalOperator: '<S148>/Compare' incorporates:
   *  Constant: '<S148>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq = (DT24_CVADAS_AP_CodGen_B.Abs3_f
    == 1023);

  /* UnitDelay: '<S132>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_b;

  /* RelationalOperator: '<S147>/Compare' incorporates:
   *  Constant: '<S147>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g == 1023);

  /* Logic: '<S132>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq ||
     DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts);

  /* UnitDelay: '<S132>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_n;

  /* Sum: '<S132>/Add' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g += DT24_CVADAS_AP_CodGen_B.Abs3_f;

  /* Product: '<S132>/Divide' incorporates:
   *  Constant: '<S132>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.a_tmp = 2;
  DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.a_tmp == 0 ?
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g >= 0 ? MAX_int32_T :
    MIN_int32_T : DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g /
    DT24_CVADAS_AP_CodGen_B.a_tmp;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.Divide_k = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* End of Product: '<S132>/Divide' */

  /* RelationalOperator: '<S146>/Relational Operator' incorporates:
   *  Constant: '<S146>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Divide_k > KeAP_cm_RearDistArcComp);

  /* Switch: '<S146>/Switch1' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    /* Sum: '<S146>/Add1' incorporates:
     *  Constant: '<S146>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.Add1_f = (int16_T)(DT24_CVADAS_AP_CodGen_B.Divide_k
      - KeAP_cm_RearDistArcComp);
    DT24_CVADAS_AP_CodGen_B.Switch1_k = DT24_CVADAS_AP_CodGen_B.Add1_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch1_k = DT24_CVADAS_AP_CodGen_B.Divide_k;
  }

  /* End of Switch: '<S146>/Switch1' */

  /* Switch: '<S132>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_h = DT24_CVADAS_AP_CodGen_B.Abs3_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_h = DT24_CVADAS_AP_CodGen_B.Switch1_k;
  }

  /* End of Switch: '<S132>/Switch' */

  /* Chart: '<S93>/RC_Dbnc2' */
  if (DT24_CVADAS_AP_CodGen_DW.is_active_c6_DT24_CVADAS_AP_CodGen == 0U) {
    DT24_CVADAS_AP_CodGen_DW.is_active_c6_DT24_CVADAS_AP_CodGen = 1U;
    MeAP_cm_RearRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_h;
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount = 0U;
    DT24_CVADAS_AP_CodGen_DW.BoundaryDist = (int16_T)fminf(fmaxf((real32_T)
      (KeAP_cm_DistZone2 + 50), 0.0F), 1023.0F);
    if ((DT24_CVADAS_AP_CodGen_B.Switch_h <
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist) && (MeAP_cm_RearRightMinXDist >
         DT24_CVADAS_AP_CodGen_DW.BoundaryDist) && KeAP_b_HeightFlagEnabled) {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount++;
      if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount > KeAP_cnt_CruisAgeBasedDbncCount)
      {
        DT24_CVADAS_AP_CodGen_DW.RCDbncCount = 0U;
      }
    } else {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount = 0U;
    }
  } else if ((DT24_CVADAS_AP_CodGen_B.Switch_h <
              DT24_CVADAS_AP_CodGen_DW.BoundaryDist) &&
             (MeAP_cm_RearRightMinXDist > DT24_CVADAS_AP_CodGen_DW.BoundaryDist)
             && KeAP_b_HeightFlagEnabled) {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount++;
    if (DT24_CVADAS_AP_CodGen_DW.RCDbncCount > KeAP_cnt_CruisAgeBasedDbncCount)
    {
      DT24_CVADAS_AP_CodGen_DW.RCDbncCount = 0U;
      MeAP_cm_RearRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_h;
    }
  } else {
    DT24_CVADAS_AP_CodGen_DW.RCDbncCount = 0U;
    MeAP_cm_RearRightMinXDist = DT24_CVADAS_AP_CodGen_B.Switch_h;
  }

  /* End of Chart: '<S93>/RC_Dbnc2' */

  /* Logic: '<S161>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq_tmp;

  /* Switch: '<S161>/Switch' incorporates:
   *  Constant: '<S161>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_b = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_b = MeAP_cm_RearRightMinXDist;
  }

  /* End of Switch: '<S161>/Switch' */

  /* RelationalOperator: '<S16>/Relational Operator' incorporates:
   *  Constant: '<S16>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjPrestFC = (DT24_CVADAS_AP_CodGen_B.Switch_a <=
    KeAP_cm_ObjPrestFCDistThd);

  /* RelationalOperator: '<S16>/Relational Operator1' incorporates:
   *  Constant: '<S16>/Constant1'
   */
  DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjPrestRC = (DT24_CVADAS_AP_CodGen_B.Switch_j <=
    KeAP_cm_ObjPrestRCDistThd);

  /* DataTypeConversion: '<S12>/Data Type Conversion8' */
  DT24_CVADAS_AP_CodGen_B.f1 = floorf
    (DT24_CVADAS_AP_CodGen_B.IeVBII_deg_StrWhlSpd);
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f1 = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f1 = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.IeVBII_deg_StrWhlSpd_k = (int16_T)
    (DT24_CVADAS_AP_CodGen_B.f1 < 0.0F ? (int32_T)(int16_T)-(int16_T)(uint16_T)
     -DT24_CVADAS_AP_CodGen_B.f1 : (int32_T)(int16_T)(uint16_T)
     DT24_CVADAS_AP_CodGen_B.f1);

  /* End of DataTypeConversion: '<S12>/Data Type Conversion8' */

  /* DataTypeConversion: '<S7>/Data Type Conversion' */
  DT24_CVADAS_AP_CodGen_B.MbDiag_PlantModeOn =
    DT24_CVADAS_AP_CodGen_B.IbDiag_DiagToParkAssist.MbDiag_PlantModeOn;

  /* BusCreator: '<S88>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFront =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFront;
  DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFL =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFL;
  DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFR =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentFR;

  /* BusCreator: '<S88>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRear =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRear;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRL =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRL;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRR =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_HighPointsPresentRR;

  /* Saturate: '<S92>/Saturation17' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist > 1024) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 1024;
  } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist < (-1024)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-1024);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallFrntCenterDist;
  }

  /* End of Saturate: '<S92>/Saturation17' */

  /* Abs: '<S92>/Abs3' */
  if (DT24_CVADAS_AP_CodGen_B.Abs3_f < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (int16_T)-DT24_CVADAS_AP_CodGen_B.Abs3_f;
  }

  /* End of Abs: '<S92>/Abs3' */

  /* RelationalOperator: '<S119>/Compare' incorporates:
   *  Constant: '<S119>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Abs3_f == 1023);

  /* UnitDelay: '<S109>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_o;

  /* RelationalOperator: '<S120>/Compare' incorporates:
   *  Constant: '<S120>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g == 1023);

  /* Logic: '<S109>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* UnitDelay: '<S109>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_k;

  /* Sum: '<S109>/Add' */
  DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.Abs3_f +
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.Add_o = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* End of Sum: '<S109>/Add' */

  /* DataTypeConversion: '<S109>/Data Type Conversion' incorporates:
   *  Constant: '<S109>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = ((uint8_T)2U);

  /* Product: '<S109>/Divide' */
  DT24_CVADAS_AP_CodGen_B.Divide_p = div_s16s32(DT24_CVADAS_AP_CodGen_B.Add_o,
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g);

  /* RelationalOperator: '<S118>/Relational Operator' incorporates:
   *  Constant: '<S118>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.Divide_p > KeAP_cm_FrntDistArcComp);

  /* Switch: '<S118>/Switch1' */
  if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e) {
    /* Sum: '<S118>/Add1' incorporates:
     *  Constant: '<S118>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.Add1_b = (int16_T)(DT24_CVADAS_AP_CodGen_B.Divide_p
      - KeAP_cm_FrntDistArcComp);
    DT24_CVADAS_AP_CodGen_B.Switch1_n = DT24_CVADAS_AP_CodGen_B.Add1_b;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch1_n = DT24_CVADAS_AP_CodGen_B.Divide_p;
  }

  /* End of Switch: '<S118>/Switch1' */

  /* Switch: '<S109>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_o = DT24_CVADAS_AP_CodGen_B.Abs3_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_o = DT24_CVADAS_AP_CodGen_B.Switch1_n;
  }

  /* End of Switch: '<S109>/Switch' */

  /* Switch: '<S158>/Switch' incorporates:
   *  Constant: '<S158>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_or = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_or = DT24_CVADAS_AP_CodGen_B.Switch_o;
  }

  /* End of Switch: '<S158>/Switch' */

  /* Saturate: '<S93>/Saturation3' */
  if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist > 0) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = 0;
  } else if (DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist < (-1023)) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (-1023);
  } else {
    DT24_CVADAS_AP_CodGen_B.Abs3_f =
      DT24_CVADAS_AP_CodGen_B.MeAP_cm_WallRearCenterDist;
  }

  /* End of Saturate: '<S93>/Saturation3' */

  /* Abs: '<S93>/Abs3' */
  if (DT24_CVADAS_AP_CodGen_B.Abs3_f < 0) {
    DT24_CVADAS_AP_CodGen_B.Abs3_f = (int16_T)-DT24_CVADAS_AP_CodGen_B.Abs3_f;
  }

  /* End of Abs: '<S93>/Abs3' */

  /* RelationalOperator: '<S153>/Compare' incorporates:
   *  Constant: '<S153>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.Abs3_f == 1023);

  /* UnitDelay: '<S139>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_i;

  /* RelationalOperator: '<S154>/Compare' incorporates:
   *  Constant: '<S154>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g == 1023);

  /* Logic: '<S139>/Logical Operator' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts ||
     DT24_CVADAS_AP_CodGen_B.RelationalOperator_e);

  /* UnitDelay: '<S139>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g =
    DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_l;

  /* Sum: '<S139>/Add' */
  DT24_CVADAS_AP_CodGen_B.a_tmp = DT24_CVADAS_AP_CodGen_B.Abs3_f +
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g;
  if (DT24_CVADAS_AP_CodGen_B.a_tmp > 32767) {
    DT24_CVADAS_AP_CodGen_B.a_tmp = 32767;
  } else {
    if (DT24_CVADAS_AP_CodGen_B.a_tmp < -32768) {
      DT24_CVADAS_AP_CodGen_B.a_tmp = -32768;
    }
  }

  DT24_CVADAS_AP_CodGen_B.Add_o = (int16_T)DT24_CVADAS_AP_CodGen_B.a_tmp;

  /* End of Sum: '<S139>/Add' */

  /* DataTypeConversion: '<S139>/Data Type Conversion' incorporates:
   *  Constant: '<S139>/Constant'
   */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g = ((uint8_T)2U);

  /* Product: '<S139>/Divide' */
  DT24_CVADAS_AP_CodGen_B.Divide_kq = div_s16s32(DT24_CVADAS_AP_CodGen_B.Add_o,
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion_g);

  /* RelationalOperator: '<S152>/Relational Operator' incorporates:
   *  Constant: '<S152>/Constant2'
   */
  DT24_CVADAS_AP_CodGen_B.RelationalOperator_e =
    (DT24_CVADAS_AP_CodGen_B.Divide_kq > KeAP_cm_RearDistArcComp);

  /* Switch: '<S152>/Switch1' */
  if (DT24_CVADAS_AP_CodGen_B.RelationalOperator_e) {
    /* Sum: '<S152>/Add1' incorporates:
     *  Constant: '<S152>/Constant1'
     */
    DT24_CVADAS_AP_CodGen_B.Add1 = (int16_T)(DT24_CVADAS_AP_CodGen_B.Divide_kq -
      KeAP_cm_RearDistArcComp);
    DT24_CVADAS_AP_CodGen_B.Switch1_a = DT24_CVADAS_AP_CodGen_B.Add1;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch1_a = DT24_CVADAS_AP_CodGen_B.Divide_kq;
  }

  /* End of Switch: '<S152>/Switch1' */

  /* Switch: '<S139>/Switch' */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts) {
    DT24_CVADAS_AP_CodGen_B.Switch_f = DT24_CVADAS_AP_CodGen_B.Abs3_f;
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_f = DT24_CVADAS_AP_CodGen_B.Switch1_a;
  }

  /* End of Switch: '<S139>/Switch' */

  /* Switch: '<S162>/Switch' incorporates:
   *  Constant: '<S162>/Constant1'
   */
  if (DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq) {
    DT24_CVADAS_AP_CodGen_B.Switch_ik = ((int16_T)CeAP_cm_DefaultRearDistInt16);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch_ik = DT24_CVADAS_AP_CodGen_B.Switch_f;
  }

  /* End of Switch: '<S162>/Switch' */

  /* ModelReference generated from: '<Root>/CVADAS_AutoPark_Main' */
  DT24_CVADAS_AutoPark_Func
    (&DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1,
     &DT24_CVADAS_AP_CodGen_B.MbNVM_ReadParam, (&(MbNVM_ProxyParam)),
     &DT24_CVADAS_AP_CodGen_B.IbUSS_DiagFlag, &DT24_CVADAS_AP_CodGen_B.LwSpd_FPA,
     &DT24_CVADAS_AP_CodGen_B.THA_Feature_Output.MeTHA_e_RearBrkSupprInfo,
     &DT24_CVADAS_AP_CodGen_B.DataTypeConversion2,
     &DT24_CVADAS_AP_CodGen_B.DataTypeConversion4,
     &DT24_CVADAS_AP_CodGen_B.DataTypeConversion314,
     &DT24_CVADAS_AP_CodGen_B.IbUSS_2DPointMap,
     &DT24_CVADAS_AP_CodGen_ConstB.Saturation,
     &DT24_CVADAS_AP_CodGen_B.TRSC_Feature_Output.IeTRSC_e_TRSCSts,
     &DT24_CVADAS_AP_CodGen_B.DataTypeConversion1, (&(MeAP_b_ObjInPath)),
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_ExternalFail,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_SystemFail,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FPADisable,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPADisable,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPAActvTrlr_27,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPAActvTrlr_29,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_PAVolDefMed,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FPAVolDefMed,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPAVolDefMed,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FrntSenorFail,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FrntSenorBlock,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RearSenorFail,
     &DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RearSenorBlock,
     &DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActv4LOW,
     &DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBDiable,
     &DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActvTrlr,
     &DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActv4LOW,
     &DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPADisable,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_UsrSlotSelStatus,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_ParkStyle,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_UsrParkOutSideSel,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_HMIHandshake,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_b_BackBtnPsd,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_UsrPPPAManeuverSel,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_SelectedMnvSlotType,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_e_SelectedMnvSlotSide,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_ok.IeHMI_cnt_FressnessCounter,
     (&(IbAP_InputVrntTunParam.KeAP_degC_OperatingTempThd)),
     (&(IbAP_InputVrntTunParam.KeAP_kph_EnblHysThd)),
     (&(IbAP_InputVrntTunParam.KeAP_kph_FrntWarnMaxSpdThd)),
     (&(IbAP_InputVrntTunParam.KeAP_kph_PSDOffThd)),
     (&(IbAP_InputVrntTunParam.KeAP_kph_PSDOnThd)),
     (&(IbAP_InputVrntTunParam.KeAP_kph_RearWarnMaxSpdThd)),
     (&(IbAP_InputVrntTunParam.K_e_RAEB_VehicleWidth)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_ChimeVolChgAlert)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_FrntChimeDisTimeThd)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_LEDBlinkTimeThd)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_VehKeyOnTimeThd)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_TimeStep)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_VehicleWidth)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_SwtStuckTimeThd)),
     (&(IbAP_InputVrntTunParam.KeAP_s_BSMInterfaceCntTimeout)),
     (&(IbAP_InputVrntTunParam.KeAP_s_EPSInterfaceCntTimeout)),
     (&(IbAP_InputVrntTunParam.KeAP_s_GearShiftWaitCntTimeout)),
     (&(IbAP_InputVrntTunParam.KeAP_s_ObjInPathTimeoutDur)),
     (&(IbAP_InputVrntTunParam.KeAP_s_PausedPressBtnTimeoutDur)),
     (&(IbAP_InputVrntTunParam.KeAP_s_SeekPhaseTimeoutDur)),
     (&(IbAP_InputVrntTunParam.KeAP_s_SpdExceedDur)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_SPMBlinkLEDDur)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone1)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone2)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone3)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone4)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone5)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_DistZone6)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_FrntLongDistAdj)),
     (&(IbAP_InputVrntTunParam.KeAP_cm_RearLongDistAdj)),
     (&(IbAP_InputVrntTunParam.KeAP_b_AutoParkEn)),
     (&(IbAP_InputVrntTunParam.KeAP_b_FPAEn)),
     (&(IbAP_InputVrntTunParam.KeAP_b_RPAwithBrk)),
     (&(IbAP_InputVrntTunParam.KeAP_b_RPAwithSurroundView)),
     (&(IbAP_InputVrntTunParam.KeAP_cnt_EngagedFullWaitCnt)),
     &DT24_CVADAS_AP_CodGen_B.SignalConversion,
     &DT24_CVADAS_AP_CodGen_B.Switch_a, &DT24_CVADAS_AP_CodGen_B.Switch_c,
     &DT24_CVADAS_AP_CodGen_B.Switch_l3, &DT24_CVADAS_AP_CodGen_B.Switch_j,
     &DT24_CVADAS_AP_CodGen_B.Switch_ev, &DT24_CVADAS_AP_CodGen_B.Switch_b,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjPrestFC,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjPrestRC,
     &DT24_CVADAS_AP_CodGen_B.IeVBII_deg_StrWhlSpd_k,
     &DT24_CVADAS_AP_CodGen_B.MbDiag_PlantModeOn,
     &DT24_CVADAS_AP_CodGen_B.TRSC_Feature_Output.IeTRSC_e_TRSCPopupDispInfo,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFront,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFL,
     &DT24_CVADAS_AP_CodGen_B.BusCreator_e.MeAP_b_HighPointsPresentFR,
     &DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRear,
     &DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRL,
     &DT24_CVADAS_AP_CodGen_B.BusCreator1_ow.MeAP_b_HighPointsPresentRR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_IsWall, &DT24_CVADAS_AP_CodGen_B.Switch_or,
     &DT24_CVADAS_AP_CodGen_B.Switch_ik,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_FPAStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_RPAStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_ParkAssistStatus,
     &DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o10,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_PAMSystemFault,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMOffStatus2BT,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_FrntSnsrStatus,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_RearSnsrStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_DisableDiag,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_APEnblSwtStuckStatus,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_InterfaceBSM,
     &DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o25,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_ParKMnvrActv,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_SystemFail_l,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ExternalFail_g,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_PARBDiable_h,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_RPADisable_n,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_FPADisable_b,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_SPMLedSts,
     &DT24_CVADAS_AP_CodGen_B.IeAP_b_SPMFailSts,
     &DT24_CVADAS_AP_CodGen_B.IeAP_b_SPMFaultSts,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_SPMActvStat,
     &DT24_CVADAS_AP_CodGen_B.IeAP_b_VehMnvrDirSPM,
     &DT24_CVADAS_AP_CodGen_B.IeAP_b_StandstillReq,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_VCOpPaused,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_GearShiftReq,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF_b,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF_a,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF_g,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR_g,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR_n,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR_g,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHF,
     &DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o56,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHF,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicLHR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvLHF,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvRHF,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvLHR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvRHR,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeRepnRate,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMVolume,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_FrntPAMLedCtrlStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_RearPAMLedCtrlStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeTyp,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMPopUpReq,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_CalculateRearObjectDist,
     &DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o72,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_PAMStopCtrlStatus,
     &DT24_CVADAS_AP_CodGen_B.MeAP_deg_StrCmd,
     &DT24_CVADAS_AP_CodGen_B.MeAP_a_BrkCmd,
     &DT24_CVADAS_AP_CodGen_B.MeAP_a_ThrtlCmd,
     &DT24_CVADAS_AP_CodGen_B.IeAP_e_TurnIndicReq,
     &DT24_CVADAS_AP_CodGen_B.IeAP_nm_StrwTrqReq,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_DecelMax,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_DecelMin,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_JerkDecelMax,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_JerkDecelMin,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_AcclMin,
     &DT24_CVADAS_AP_CodGen_B.IeAP_a_AcclMax,
     &DT24_CVADAS_AP_CodGen_B.IeAP_da_JerkAcclMax,
     &DT24_CVADAS_AP_CodGen_B.IeAP_da_JerkAcclMin,
     &DT24_CVADAS_AP_CodGen_B.IeAP_b_StandstillReq_a,
     &DT24_CVADAS_AP_CodGen_B.IeAP_cm_TrgtDist,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ManeuverAbort,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ManeuverSuccess,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PP_state,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_Park_state,
     &DT24_CVADAS_AP_CodGen_B.MaAP_m_PlannerWayPointsX[0],
     &DT24_CVADAS_AP_CodGen_B.MaAP_m_PlannerWayPointsY[0],
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_PosMet_f,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_SteerActionReq_g,
     &DT24_CVADAS_AP_CodGen_B.IeAP_kph_TrgtVehSpd,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMVolSigSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqLHFSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqLHRSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqRHFSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqRHRSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeTypSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeRepnRateSVM,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSupplyPwrSt,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSystemMode,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSystemState,
     &DT24_CVADAS_AP_CodGen_B.MeAP_e_USSFiringMode,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_USSReinitAllowed,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ScanSts,
     &DT24_CVADAS_AP_CodGen_B.MeAP_cnt_StateDebugVar_f,
     &DT24_CVADAS_AP_CodGen_B.MeAP_cnt_TransDebugVar_f,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_VCOpPaused_k,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_BSMInterfaceTimeout,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_EPSInterfaceTimeout,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_GearShiftWaitTimeout,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_CamHandshakeTimeout,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjInPathTimeout_d,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_PausedPressBtnTimeout_f,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_SeekSpdExceedTimeout,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_APInitSts,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_DriverOverride_k,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_StandStill,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_BSMHandshakeActv,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_VehCndSts_l,
     &DT24_CVADAS_AP_CodGen_B.MeAP_b_FeatureEnbl,
     &DT24_CVADAS_AP_CodGen_B.X_MABx_b, &DT24_CVADAS_AP_CodGen_B.Y_MABx_g,
     &DT24_CVADAS_AP_CodGen_B.heading_MABx_j,
     &DT24_CVADAS_AP_CodGen_B.Str_Trq_CMD,
     &DT24_CVADAS_AP_CodGen_B.VC_RemainingDist_o,
     &DT24_CVADAS_AP_CodGen_B.VC_PathDev_o,
     &DT24_CVADAS_AP_CodGen_B.VC_Head_Dev_l,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFSX_g,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFSY_k,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFBX_g,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFBY_d,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRSX_f,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRSY_k,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRBX_h,
     &DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRBY_k,
     &DT24_CVADAS_AP_CodGen_B.PM_CurrentSweep_f,
     &DT24_CVADAS_AP_CodGen_B.PM_RegenPath_a);

  /* BusCreator: '<S208>/Bus Creator2' */
  DriveAssistStatOut.MeAP_s_FaultWaitTime =
    DT24_CVADAS_AP_CodGen_B.MeAP_s_FaultWaitTime;
  DriveAssistStatOut.IeAutoPark_e_ChimeReq =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o9;
  DriveAssistStatOut.IeAP_e_ScanDir =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o10;
  DriveAssistStatOut.IeAP_e_AutoParkStatus = MeAP_e_AutoParkStatus;
  DriveAssistStatOut.IeAP_e_AlgoState = MeAutoPark_e_AlgoState;
  DriveAssistStatOut.IeAP_e_ParKMnvrActv =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ParKMnvrActv;
  DriveAssistStatOut.IeAP_e_InterfaceBSM =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_InterfaceBSM;
  DriveAssistStatOut.IeAP_e_SPMLatCtrlReqSts =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o25;
  DriveAssistStatOut.IeAP_e_SPMLedSts = DT24_CVADAS_AP_CodGen_B.IeAP_e_SPMLedSts;
  DriveAssistStatOut.IeAP_e_SPMActvStat =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_SPMActvStat;
  DriveAssistStatOut.IeAP_e_DispView2 = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispView2;
  DriveAssistStatOut.IeAP_e_GearShiftReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_GearShiftReq;
  DriveAssistStatOut.MeAP_e_PAMVolSigSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMVolSigSVM;
  DriveAssistStatOut.MeAP_e_PAMChimeTypSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeTypSVM;
  DriveAssistStatOut.MeAP_e_PAMChimeRepnRateSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeRepnRateSVM;
  DriveAssistStatOut.IeAP_e_HMIDispReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_HMIDispReq;
  DriveAssistStatOut.IeAP_b_WrngSpdExceed =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o3;
  DriveAssistStatOut.IeAP_b_FaultStatus =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o4;
  DriveAssistStatOut.IeAP_b_ParkInOutSuccess =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o6;
  DriveAssistStatOut.IeAP_b_ParkInOutAbort =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o7;
  DriveAssistStatOut.IeAP_b_FeatureAvl =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o8;
  DriveAssistStatOut.IeAP_b_ParkOutAvailable =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o11;
  DriveAssistStatOut.IeAP_b_ImgDefeatReqSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_ImgDefeatReqSts;
  DriveAssistStatOut.IeAP_b_SPMScrnReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_SPMScrnReq;
  DriveAssistStatOut.IeAP_b_SPMFailSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_SPMFailSts;
  DriveAssistStatOut.IeAP_b_SPMFaultSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_SPMFaultSts;
  DriveAssistStatOut.IeAP_b_VehMnvrDirSPM =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_VehMnvrDirSPM;
  DriveAssistStatOut.IeAP_b_AutoParkOverride =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_AutoParkOverride;
  DriveAssistStatOut.MeAP_b_SensorFltSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_SensorFltSts;
  DriveAssistStatOut.MeAP_b_ChimeActvReqLHFSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqLHFSVM;
  DriveAssistStatOut.MeAP_b_ChimeActvReqLHRSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqLHRSVM;
  DriveAssistStatOut.MeAP_b_ChimeActvReqRHFSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqRHFSVM;
  DriveAssistStatOut.MeAP_b_ChimeActvReqRHRSVM =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvReqRHRSVM;

  /* DataStoreWrite: '<S1>/Data Store Write4' */
  static TbAP_DriveAssistStatOut_t PrevDriveAssistStatOut;
  if(0 != memcmp(&PrevDriveAssistStatOut, &DriveAssistStatOut, sizeof(DriveAssistStatOut)))
  {
    SigMgr_PpDriveAssistStatOut_TbAP_DriveAssistStatOut_t_Put(&DriveAssistStatOut);
  }
  PrevDriveAssistStatOut = DriveAssistStatOut;

  /* BusCreator: '<S208>/Bus Creator3' */
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_e_ParkAssistStatus =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_ParkAssistStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_e_GearCmdToHMI =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o14;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.IeAP_e_MnvActvStat =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_MnvActvStat;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.IeAP_e_AbortCon =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_AbortCon;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.IeAP_e_SemiParkSysSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_SemiParkSysSts;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.IeAP_e_DIDHMICode =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_DIDHMICode;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_b_AutoParkEnblSwtStuckStatus =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_APEnblSwtStuckStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_b_ScanSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ScanSts;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_b_ParkSlotDetctSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ParkSlotDetctSts;
  DT24_CVADAS_AP_CodGen_B.BusCreator3_b.MeAP_b_ResetKM = MeAP_b_ResetKM;

  /* DataStoreWrite: '<S1>/Data Store Write2' */
  static TbAP_SMDAInternalOut_t PrevSMDAInternalOut;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.BusCreator3_b, &PrevSMDAInternalOut, sizeof(PrevSMDAInternalOut)))
  {
    SigMgr_PpSMDAInternal_TbAP_SMDAInternalOut_t_Put(&DT24_CVADAS_AP_CodGen_B.BusCreator3_b);
  }
  PrevSMDAInternalOut = DT24_CVADAS_AP_CodGen_B.BusCreator3_b;

  /* BusCreator: '<S208>/Bus Creator1' */
  APSMPAOut.IeAP_e_PAMFlt = DT24_CVADAS_AP_CodGen_B.IeAP_e_PAMSystemFault;
  APSMPAOut.IeAP_e_FrntRearParkSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMOffStatus2BT;
  APSMPAOut.IeAP_e_FrntSensorActvSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_FrntSnsrStatus;
  APSMPAOut.IeAP_e_RearSnsrActvSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_RearSnsrStatus;

  /* DataStoreWrite: '<S1>/Data Store Write3' */
  static TbAP_APSMPAOut_t PrevAPSMPAOut;
  if(0 != memcmp(&APSMPAOut, &PrevAPSMPAOut, sizeof(PrevAPSMPAOut)))
  {
    SigMgr_PpAPSMPAOut_TbAP_APSMPAOut_t_Put(&APSMPAOut);
  }
  PrevAPSMPAOut = APSMPAOut;

  /* BusCreator: '<S208>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_e_HMIPopUp =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_FPAStatus =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FPAStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_RPAStatus =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RPAStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_FPASwtStatus = MeAP_b_FPASwtStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_RPASwtStatus = MeAP_b_RPASwtStatus;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_DisableDiag =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_DisableDiag;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_RPAwithBrkStatus =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o23;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_SystemFail =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_SystemFail_l;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_ExternalFail =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ExternalFail_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_TempFail =
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o30;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_RPAwithBrkDisable =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_PARBDiable_h;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_RPADisable =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_RPADisable_n;
  DT24_CVADAS_AP_CodGen_B.BusCreator_p.MeAP_b_FPADisable =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FPADisable_b;

  /* DataStoreWrite: '<S1>/Data Store Write1' */
  static TbAP_SMPAInternalOut_t PrevBusCreator_p;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.BusCreator_p, &PrevBusCreator_p, sizeof(PrevBusCreator_p)))
  {
    SigMgr_PpTbAPSMPAOut_TbAP_SMPAInternalOut_t_Put(&DT24_CVADAS_AP_CodGen_B.BusCreator_p);
  } 
  PrevBusCreator_p = DT24_CVADAS_AP_CodGen_B.BusCreator_p;

  /* DataTypeConversion: '<S209>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF_b;

  /* DataTypeConversion: '<S209>/Data Type Conversion36' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcRHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion3' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF_a;

  /* DataTypeConversion: '<S209>/Data Type Conversion38' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcLHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion5' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF_g;

  /* DataTypeConversion: '<S209>/Data Type Conversion40' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcCHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion20' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o56;

  /* DataTypeConversion: '<S209>/Data Type Conversion46' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateRHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion22' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHF;

  /* DataTypeConversion: '<S209>/Data Type Conversion48' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateLHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion18' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHF;

  /* DataTypeConversion: '<S209>/Data Type Conversion44' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateCHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion7' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvLHF;

  /* DataTypeConversion: '<S209>/Data Type Conversion8' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvRHF;

  /* BusCreator: '<S209>/Bus Creator1' */
  FPAWarnOut.IeAP_e_DispArcCHF = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcRHR;
  FPAWarnOut.IeAP_e_DispArcLHF = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcLHR;
  FPAWarnOut.IeAP_e_DispArcRHF = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcCHR;
  FPAWarnOut.IeAP_e_ArcFlashRateLHF =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateRHR;
  FPAWarnOut.IeAP_e_ArcFlashRateRHF =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateLHR;
  FPAWarnOut.IeAP_e_ArcFlashRateCHF =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateCHR;
  FPAWarnOut.IeAP_b_ChimeActvReqLHF =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  FPAWarnOut.IeAP_b_ChimeActvReqRHF =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;

  /* DataStoreWrite: '<S1>/Data Store Write5' */
  static TbAP_FPAWarnOut_t PrevFPAWarnOut;
  if(0 != memcmp(&FPAWarnOut, &PrevFPAWarnOut, sizeof(PrevFPAWarnOut)))
  {
    SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put(&FPAWarnOut);
  }
  PrevFPAWarnOut = FPAWarnOut;

  /* DataTypeConversion: '<S209>/Data Type Conversion2' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR_g;

  /* DataTypeConversion: '<S209>/Data Type Conversion37' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcCHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion4' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR_n;

  /* DataTypeConversion: '<S209>/Data Type Conversion39' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcLHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion6' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR_g;

  /* DataTypeConversion: '<S209>/Data Type Conversion41' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcRHR = (TeAP_e_Alert)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion19' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHR;

  /* DataTypeConversion: '<S209>/Data Type Conversion45' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateCHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion21' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicLHR;

  /* DataTypeConversion: '<S209>/Data Type Conversion47' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateLHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion23' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHR;

  /* DataTypeConversion: '<S209>/Data Type Conversion49' */
  DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateRHR = (TeAP_e_GraphicFlshRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion15' */
  DT24_CVADAS_AP_CodGen_B.f1 = floorf
    (DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o72);
  if (rtIsNaNF(DT24_CVADAS_AP_CodGen_B.f1) || rtIsInfF
      (DT24_CVADAS_AP_CodGen_B.f1)) {
    DT24_CVADAS_AP_CodGen_B.f1 = 0.0F;
  } else {
    DT24_CVADAS_AP_CodGen_B.f1 = fmodf(DT24_CVADAS_AP_CodGen_B.f1, 65536.0F);
  }

  DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst = (uint16_T)
    (DT24_CVADAS_AP_CodGen_B.f1 < 0.0F ? (int32_T)(uint16_T)-(int16_T)(uint16_T)
     -DT24_CVADAS_AP_CodGen_B.f1 : (int32_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.f1);

  /* End of DataTypeConversion: '<S209>/Data Type Conversion15' */

  /* DataTypeConversion: '<S209>/Data Type Conversion9' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvLHR;

  /* DataTypeConversion: '<S209>/Data Type Conversion10' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ChimeActvRHR;

  /* BusCreator: '<S209>/Bus Creator2' */
  RPAWarnOut.IeAP_e_DispArcCHR = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcCHR;
  RPAWarnOut.IeAP_e_DispArcLHR = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcLHR;
  RPAWarnOut.IeAP_e_DispArcRHR = DT24_CVADAS_AP_CodGen_B.IeAP_e_DispArcRHR;
  RPAWarnOut.IeAP_e_ArcFlashRateCHR =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateCHR;
  RPAWarnOut.IeAP_e_ArcFlashRateLHR =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateLHR;
  RPAWarnOut.IeAP_e_ArcFlashRateRHR =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateRHR;
  RPAWarnOut.IeAP_cm_RearDisttoNearObst =
    DT24_CVADAS_AP_CodGen_B.IeAP_cm_RearDisttoNearObst;
  RPAWarnOut.IeAP_b_ChimeActvReqLHR =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  RPAWarnOut.IeAP_b_ChimeActvReqRHR =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;

  /* DataStoreWrite: '<S1>/Data Store Write6' */
  static TbAP_RPAWarnOut_t PrevRPAWarnOut;
  if(0 != memcmp(&RPAWarnOut, &PrevRPAWarnOut, sizeof(PrevRPAWarnOut)))
  {
    SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put(&RPAWarnOut);
  }
  PrevRPAWarnOut = RPAWarnOut;

  /* DataTypeConversion: '<S209>/Data Type Conversion24' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeRepnRate;

  /* DataTypeConversion: '<S209>/Data Type Conversion35' */
  PAStateOut.IeAP_e_PAMChimeRepnRate = (TeAP_e_PAMChimeRepnRate)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion28' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMVolume;

  /* DataTypeConversion: '<S209>/Data Type Conversion53' */
  PAStateOut.IeAP_e_PAMVolSig = (TeAP_e_PAMVolume)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion17' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FrntPAMLedCtrlStatus;

  /* DataTypeConversion: '<S209>/Data Type Conversion43' */
  PAStateOut.IeAP_e_FrntParkLEDSts = (TeAP_e_PAMLedCtrlStatus)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion25' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_RearPAMLedCtrlStatus;

  /* DataTypeConversion: '<S209>/Data Type Conversion50' */
  PAStateOut.IeAP_e_PAMLedCtrl = (TeAP_e_PAMLedCtrlStatus)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion12' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMChimeTyp;

  /* DataTypeConversion: '<S209>/Data Type Conversion11' */
  PAStateOut.IeAP_e_PAMChimeTyp = (TeAP_e_PAMChimeTyp)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion27' */
  DT24_CVADAS_AP_CodGen_B.DataTypeConversion27 = (uint8_T)
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PAMPopUpReq;

  /* DataTypeConversion: '<S209>/Data Type Conversion52' */
  PAStateOut.IeAP_e_ParkSensePopUpReq = (TeAP_e_PAMPopUpReq)
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion27;

  /* DataTypeConversion: '<S209>/Data Type Conversion13' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_CalculateRearObjectDist;

  /* DataTypeConversion: '<S209>/Data Type Conversion14' */
  DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_PAMStopCtrlStatus;

  /* BusCreator: '<S209>/Bus Creator' */
  PAStateOut.IeAP_b_PAMRearBrkReq = DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearBrkReq;
  PAStateOut.IeAP_b_PAMRearCtrlSts =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_PAMRearCtrlSts;

  /* DataStoreWrite: '<S1>/Data Store Write7' */
  static TbAP_PAStateOut_t PrevPAStateOut;
  if(0 != memcmp(&PAStateOut, &PrevPAStateOut, sizeof(PrevPAStateOut)))
  {
    SigMgr_PpPAStateOut_TbAP_PAStateOut_t_Put(&PAStateOut);
  }
  PrevPAStateOut = PAStateOut;

  /* BusCreator: '<S210>/Bus Creator1' */
  VCActuatorOut.IeAP_nm_StrwTrqReq = DT24_CVADAS_AP_CodGen_B.IeAP_nm_StrwTrqReq;
  VCActuatorOut.IeAP_a_DecelMax = DT24_CVADAS_AP_CodGen_B.IeAP_a_DecelMax;
  VCActuatorOut.IeAP_a_DecelMin = DT24_CVADAS_AP_CodGen_B.IeAP_a_DecelMin;
  VCActuatorOut.IeAP_a_JerkDecelMax =
    DT24_CVADAS_AP_CodGen_B.IeAP_a_JerkDecelMax;
  VCActuatorOut.IeAP_a_JerkDecelMin =
    DT24_CVADAS_AP_CodGen_B.IeAP_a_JerkDecelMin;
  VCActuatorOut.IeAP_a_AcclMin = DT24_CVADAS_AP_CodGen_B.IeAP_a_AcclMin;
  VCActuatorOut.IeAP_a_AcclMax = DT24_CVADAS_AP_CodGen_B.IeAP_a_AcclMax;
  VCActuatorOut.IeAP_da_JerkAcclMax =
    DT24_CVADAS_AP_CodGen_B.IeAP_da_JerkAcclMax;
  VCActuatorOut.IeAP_da_JerkAcclMin =
    DT24_CVADAS_AP_CodGen_B.IeAP_da_JerkAcclMin;
  VCActuatorOut.IeAP_cm_TrgtDist = DT24_CVADAS_AP_CodGen_B.IeAP_cm_TrgtDist;
  VCActuatorOut.IeAP_kph_TrgtVehSpd =
    DT24_CVADAS_AP_CodGen_B.IeAP_kph_TrgtVehSpd;
  VCActuatorOut.IeAP_e_TurnIndicReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_e_TurnIndicReq;
  VCActuatorOut.IeAP_b_StandstillReq =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_StandstillReq_a;

  /* DataStoreWrite: '<S1>/Data Store Write8' */
  static TbAP_VCActuatorOut_t PrevVCActuatorOut;
  if(0 != memcmp(&VCActuatorOut, &PrevVCActuatorOut, sizeof(PrevVCActuatorOut)))
  {
    if (1u == v_Enable_Tgt_Dist_Saturation_u8)//keep
    {
      if (1022.0f < VCActuatorOut.IeAP_cm_TrgtDist)
      {
        VCActuatorOut.IeAP_cm_TrgtDist = 1023.0f;
      }
    }
    SigMgr_PpVCActuatorOut_TbAP_VCActuatorOut_t_Put(&VCActuatorOut);
  }
  PrevVCActuatorOut = VCActuatorOut;

  /* BusCreator: '<S210>/Bus Creator3' */
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator3.MaAP_m_PlannerWayPointsX[0],
         &DT24_CVADAS_AP_CodGen_B.MaAP_m_PlannerWayPointsX[0], 250U * sizeof
         (real32_T));
  memcpy(&DT24_CVADAS_AP_CodGen_B.BusCreator3.MaAP_m_PlannerWayPointsY[0],
         &DT24_CVADAS_AP_CodGen_B.MaAP_m_PlannerWayPointsY[0], 250U * sizeof
         (real32_T));

  /* DataStoreWrite: '<S1>/Data Store Write10' */
  static TbAP_VCTrajOut_t PrevVCTrajOut;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.BusCreator3, &PrevVCTrajOut, sizeof(PrevVCTrajOut)))
  {
    SigMgr_PpVCTrajOut_TbAP_VCTrajOut_t_Put(&DT24_CVADAS_AP_CodGen_B.BusCreator3);
  }
  PrevVCTrajOut = DT24_CVADAS_AP_CodGen_B.BusCreator3;

  /* BusCreator: '<S210>/Bus Creator4' */
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_e_Park_state =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_Park_state;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_e_PP_state =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_PP_state;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.IeAP_cnt_CurrentVehSweep =
    DT24_CVADAS_AP_CodGen_B.IeAP_cnt_CurrentVehSweep;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_b_ManeuverAbort =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ManeuverAbort;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_b_ManeuverSuccess =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ManeuverSuccess;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_b_PosMet =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_PosMet_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.MeAP_b_SteerActionReq =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_SteerActionReq_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator4.IeAP_b_MnvPosOk =
    DT24_CVADAS_AP_CodGen_B.IeAP_b_MnvPosOk;

  /* DataStoreWrite: '<S1>/Data Store Write11' */
  static TbAP_VCStateOut_t PrevVCStateOut;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.BusCreator4, &PrevVCStateOut, sizeof(PrevVCStateOut)))
  {
    SigMgr_PpVCState_TbAP_VCStateOut_t_Put(&DT24_CVADAS_AP_CodGen_B.BusCreator4);
  }
  PrevVCStateOut = DT24_CVADAS_AP_CodGen_B.BusCreator4;

  /* BusCreator: '<S208>/Bus Creator4' */
  DT24_CVADAS_AP_CodGen_B.BusCreator4_d.IeAP_e_USSSupplyPwrSt =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSupplyPwrSt;
  DT24_CVADAS_AP_CodGen_B.BusCreator4_d.IeAP_e_USSSystemMode =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSystemMode;
  DT24_CVADAS_AP_CodGen_B.BusCreator4_d.IeAP_e_USSSystemState =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_USSSystemState;
  DT24_CVADAS_AP_CodGen_B.BusCreator4_d.IeAP_e_USSFiringMode =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_USSFiringMode;
  DT24_CVADAS_AP_CodGen_B.BusCreator4_d.MeAP_b_USSReInit =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_USSReinitAllowed;

  /* DataStoreWrite: '<S1>/Data Store Write9' */
  static TbAP_USSStateOut_t PrevUSSStateOut;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.BusCreator4_d, &PrevUSSStateOut, sizeof(PrevUSSStateOut)))
  {
    SigMgr_Data_TbAP_USSStateOut_t_Put(&DT24_CVADAS_AP_CodGen_B.BusCreator4_d);
  }
  PrevUSSStateOut = DT24_CVADAS_AP_CodGen_B.BusCreator4_d;

  /* BusCreator: '<S207>/Bus Creator' */
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_deg_StrCmd =
    DT24_CVADAS_AP_CodGen_B.MeAP_deg_StrCmd;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_a_BrkCmd =
    DT24_CVADAS_AP_CodGen_B.MeAP_a_BrkCmd;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_a_ThrtlCmd =
    DT24_CVADAS_AP_CodGen_B.MeAP_a_ThrtlCmd;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cnt_StateDebugVar =
    DT24_CVADAS_AP_CodGen_B.MeAP_cnt_StateDebugVar_f;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cnt_TransDebugVar =
    DT24_CVADAS_AP_CodGen_B.MeAP_cnt_TransDebugVar_f;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_FrntCenterMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_a;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_FrntLeftMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_c;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_FrntRightMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_l3;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_RearCenterMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_j;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_RearLeftMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_ev;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_cm_RearRightMinXDist =
    DT24_CVADAS_AP_CodGen_B.Switch_b;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_VCOpPaused =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VCOpPaused_k;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_BSMInterfaceTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_BSMInterfaceTimeout;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_EPSInterfaceTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_EPSInterfaceTimeout;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_GearShiftWaitTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_GearShiftWaitTimeout;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_CamHandshakeTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_CamHandshakeTimeout;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_ObjInPathTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ObjInPathTimeout_d;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PausedPressBtnTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_PausedPressBtnTimeout_f;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_SeekSpdExceedTimeout =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_SeekSpdExceedTimeout;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_APInitSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_APInitSts;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_DriverOverride =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_DriverOverride_k;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_StandStill =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_StandStill;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_BSMHandshakeActv =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_BSMHandshakeActv;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_VehCndSts =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehCndSts_l;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_FeatureEnbl =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_FeatureEnbl;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_FPADisable =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FPADisable;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_RPADisable =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPADisable;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_RPAActvTrlr =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPAActvTrlr_27;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PAVolDefMed =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_PAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_FPAVolDefMed =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_FPAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_RPAVolDefMed =
    DT24_CVADAS_AP_CodGen_B.Switch.MeAP_b_RPAVolDefMed;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PARBActvTrlr =
    DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActvTrlr_27;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PARBActv4LOW =
    DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBActv4LOW;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PARBDiable =
    DT24_CVADAS_AP_CodGen_B.IbFID_PARB.MeAP_b_PARBDiable;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PPPAActvTrlr =
    DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActvTrlr;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PPPAActv4LOW =
    DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPAActv4LOW;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PPPADefEng =
    DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPADefEng;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_PPPADisable =
    DT24_CVADAS_AP_CodGen_B.IbFID_PPPA.MeAP_b_PPPADisable;

  /*Using few variables in AP debug messaged for VC debug*/
  // DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_b_APInitSts = Algo_Active;
  // DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_a_BrkCmd = ((uint32_t)MeAP_e_GearCmd * 1.0f);
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_deg_StrCmd = X_MABx;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_a_BrkCmd = Y_MABx;
  DT24_CVADAS_AP_CodGen_B.AP_DebugOut.MeAP_a_ThrtlCmd = heading_MABx;
  /* DataStoreWrite: '<S1>/Data Store Write12' */
  static TbAP_DebugOut PrevDebugOut;
  if(0 != memcmp(&DT24_CVADAS_AP_CodGen_B.AP_DebugOut, &PrevDebugOut, sizeof(PrevDebugOut)))
  {
    SigMgr_PpTbAPDebugOut_TbAP_DebugOut_Put(&DT24_CVADAS_AP_CodGen_B.AP_DebugOut);
  }  
  PrevDebugOut = DT24_CVADAS_AP_CodGen_B.AP_DebugOut;

  /* BusCreator: '<S207>/Bus Creator1' */
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.X_MABx =
    DT24_CVADAS_AP_CodGen_B.X_MABx_b;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Y_MABx =
    DT24_CVADAS_AP_CodGen_B.Y_MABx_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.heading_MABx =
    DT24_CVADAS_AP_CodGen_B.heading_MABx_j;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Str_Trq_CMD =
    DT24_CVADAS_AP_CodGen_B.Str_Trq_CMD;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.VC_RemainingDist =
    DT24_CVADAS_AP_CodGen_B.VC_RemainingDist_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.VC_PathDev =
    DT24_CVADAS_AP_CodGen_B.VC_PathDev_o;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.VC_Head_Dev =
    DT24_CVADAS_AP_CodGen_B.VC_Head_Dev_l;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimFSX =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFSX_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimFSY =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFSY_k;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimFBX =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFBX_g;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimFBY =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimFBY_d;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimRSX =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRSX_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimRSY =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRSY_k;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimRBX =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRBX_h;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.Ma_AP_I_PSLimRBY =
    DT24_CVADAS_AP_CodGen_B.Ma_AP_I_PSLimRBY_k;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.PM_CurrentSweep =
    DT24_CVADAS_AP_CodGen_B.PM_CurrentSweep_f;
  DT24_CVADAS_AP_CodGen_B.BusCreator1_i.PM_RegenPath =
    DT24_CVADAS_AP_CodGen_B.PM_RegenPath_a;

  /* DataStoreWrite: '<S1>/Data Store Write13' */
  // SigMgr_PpTbVCDebugOut_TbVC_DebugOut_Put(DT24_CVADAS_AP_CodGen_B.BusCreator1_i);


  /* DataTypeConversion: '<S7>/Data Type Conversion1' */
  DT24_CVADAS_AP_CodGen_B.MbDiag_SensorTestMode =
    DT24_CVADAS_AP_CodGen_B.IbDiag_DiagToParkAssist.MbDiag_SensorTestMode;

  /* Gain: '<S12>/Gain1' incorporates:
   *  Gain: '<S12>/Gain'
   */
  DT24_CVADAS_AP_CodGen_B.Gain = (uint32_T)((uint16_T)33554U) *
    MbNVM_ProxyParam.KeAP_mm_TyreSz;
  uMultiWordMul(&rtCP_Gain1_Gain, 1, &DT24_CVADAS_AP_CodGen_B.Gain, 1,
                &DT24_CVADAS_AP_CodGen_B.Gain1.chunks[0U], 2);

  /* Switch: '<S204>/Switch4' incorporates:
   *  Constant: '<S204>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_B.overflow_h) {
    DT24_CVADAS_AP_CodGen_B.d = floor(0.0);
    if (rtIsNaN(DT24_CVADAS_AP_CodGen_B.d) || rtIsInf(DT24_CVADAS_AP_CodGen_B.d))
    {
      DT24_CVADAS_AP_CodGen_B.d = 0.0;
    } else {
      DT24_CVADAS_AP_CodGen_B.d = fmod(DT24_CVADAS_AP_CodGen_B.d, 65536.0);
    }

    DT24_CVADAS_AP_CodGen_B.Switch4_j = (uint16_T)(DT24_CVADAS_AP_CodGen_B.d <
      0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.d :
      (int32_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.d);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch4_j = DT24_CVADAS_AP_CodGen_B.count_d;
  }

  /* End of Switch: '<S204>/Switch4' */

  /* Switch: '<S203>/Switch4' incorporates:
   *  Constant: '<S203>/Constant2'
   */
  if (DT24_CVADAS_AP_CodGen_B.overflow) {
    DT24_CVADAS_AP_CodGen_B.d = floor(0.0);
    if (rtIsNaN(DT24_CVADAS_AP_CodGen_B.d) || rtIsInf(DT24_CVADAS_AP_CodGen_B.d))
    {
      DT24_CVADAS_AP_CodGen_B.d = 0.0;
    } else {
      DT24_CVADAS_AP_CodGen_B.d = fmod(DT24_CVADAS_AP_CodGen_B.d, 65536.0);
    }

    DT24_CVADAS_AP_CodGen_B.Switch4_i = (uint16_T)(DT24_CVADAS_AP_CodGen_B.d <
      0.0 ? (int32_T)(uint16_T)-(int16_T)(uint16_T)-DT24_CVADAS_AP_CodGen_B.d :
      (int32_T)(uint16_T)DT24_CVADAS_AP_CodGen_B.d);
  } else {
    DT24_CVADAS_AP_CodGen_B.Switch4_i = DT24_CVADAS_AP_CodGen_B.count;
  }

  /* End of Switch: '<S203>/Switch4' */

  /* DataStoreRead: '<S2>/VrntTunParam_data1' */
//  DT24_CVADAS_AP_CodGen_B.IbAP_CalDataProviderMCU21Def =
   // SigMgr_Data_CalDataProviderMCU21Def_t_Get();

  /* Update for UnitDelay: '<S183>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_m =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k;

  /* Update for UnitDelay: '<S205>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_c =
    DT24_CVADAS_AP_CodGen_B.RelationalOperator6;

  /* Update for UnitDelay: '<S203>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_h5 =
    DT24_CVADAS_AP_CodGen_B.Switch2_b;

  /* Update for UnitDelay: '<S203>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_m =
    DT24_CVADAS_AP_CodGen_B.Switch4_i;

  /* Update for UnitDelay: '<S206>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_p =
    DT24_CVADAS_AP_CodGen_B.RelationalOperator8;

  /* Update for UnitDelay: '<S204>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_d =
    DT24_CVADAS_AP_CodGen_B.Switch2_e;

  /* Update for UnitDelay: '<S204>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_c =
    DT24_CVADAS_AP_CodGen_B.Switch4_j;

  /* Update for UnitDelay: '<S164>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_a =
    DT24_CVADAS_AP_CodGen_B.LogicalOperator4;

  /* Update for UnitDelay: '<S163>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_a =
    DT24_CVADAS_AP_CodGen_B.Switch3_c;

  /* Update for UnitDelay: '<Root>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHF_b;

  /* Update for UnitDelay: '<Root>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertCHR_g;

  /* Update for UnitDelay: '<S108>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_f = DT24_CVADAS_AP_CodGen_B.Switch_m;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay3_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHF_a;

  /* Update for UnitDelay: '<Root>/Unit Delay4' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay4_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertLHR_n;

  /* Update for UnitDelay: '<Root>/Unit Delay5' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay5_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHF_g;

  /* Update for UnitDelay: '<Root>/Unit Delay6' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay6_DSTATE =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_AlertRHR_g;

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_j =
    DT24_CVADAS_AP_CodGen_B.MeAP_e_HMIPopUp;

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_g =
    DT24_CVADAS_AP_CodGen_B.MeAP_b_VehStandstill_g;

  /* Update for UnitDelay: '<S167>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_j =
    DT24_CVADAS_AP_CodGen_B.Switch_p;

  /* Update for UnitDelay: '<S168>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_md =
    DT24_CVADAS_AP_CodGen_B.IsTimerElapsed;

  /* Update for UnitDelay: '<S172>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_hd =
    DT24_CVADAS_AP_CodGen_B.LogicalOperator;

  /* Update for UnitDelay: '<S171>/Unit Delay2' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay2_DSTATE_af =
    DT24_CVADAS_AP_CodGen_B.Switch3_n;

  /* Update for UnitDelay: '<S110>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_k = DT24_CVADAS_AP_CodGen_B.Switch_i;

  /* Update for UnitDelay: '<S111>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_c = DT24_CVADAS_AP_CodGen_B.Switch_e;

  /* Update for UnitDelay: '<S130>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_l = DT24_CVADAS_AP_CodGen_B.Switch_n;

  /* Update for UnitDelay: '<S130>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_h =
    DT24_CVADAS_AP_CodGen_B.Switch1_os;

  /* Update for UnitDelay: '<S131>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_jj =
    DT24_CVADAS_AP_CodGen_B.Switch_nz;

  /* Update for UnitDelay: '<S131>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_j =
    DT24_CVADAS_AP_CodGen_B.Switch1_c;

  /* Update for UnitDelay: '<S132>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_b = DT24_CVADAS_AP_CodGen_B.Switch_h;

  /* Update for UnitDelay: '<S132>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_n =
    DT24_CVADAS_AP_CodGen_B.Switch1_k;

  /* Update for UnitDelay: '<S109>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_o = DT24_CVADAS_AP_CodGen_B.Switch_o;

  /* Update for UnitDelay: '<S109>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_k =
    DT24_CVADAS_AP_CodGen_B.Switch1_n;

  /* Update for UnitDelay: '<S139>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_i = DT24_CVADAS_AP_CodGen_B.Switch_f;

  /* Update for UnitDelay: '<S139>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_l =
    DT24_CVADAS_AP_CodGen_B.Switch1_a;
}

/* Model initialize function */
void DT24_CVADAS_AP_CodGen_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* block I/O */
  {
    DT24_CVADAS_AP_CodGen_B.BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1
      = DT24_CVADAS_AP_CodGen_rtZTbVBIA_VehState_AP;
    DT24_CVADAS_AP_CodGen_B.BusCreator_ok =
      DT24_CVADAS_AP_CodGen_rtZTbHMI_HMIInfoToAP;
    DT24_CVADAS_AP_CodGen_B.HMIInfoToAP = DT24_CVADAS_AP_CodGen_rtZHMIInfoToAP_t;
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolFrnt =
      TeVBII_e_PamChimeVol_Medium;
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_PamChimeVolRear =
      TeVBII_e_PamChimeVol_Medium;
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_GearRptState = TeVBII_e_GearState_SNA;
    DT24_CVADAS_AP_CodGen_B.IeVBII_e_EssEngState = TeVBII_e_EssEngState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch1 = TeAutoPark_e_ParkStyle_Rear_In;
    DT24_CVADAS_AP_CodGen_B.DataTypeConversion = TeAutoPark_e_ParkStyle_Rear_In;
    DT24_CVADAS_AP_CodGen_B.IeHMI_e_ParkStyle_i = TeAutoPark_e_ParkStyle_Rear_In;
    DT24_CVADAS_AP_CodGen_B.KeAP_e_PAMTunSet = TeAP_e_PAMTunSet_Base;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHF = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o56 =
      TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHF = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicCHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicLHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_GraphicRHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateRHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateLHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.IeAP_e_ArcFlashRateCHR = TeAP_e_GraphicFlshRate_None;
    DT24_CVADAS_AP_CodGen_B.KeAP_e_GbTyp = TeAP_e_GbTyp_ATX;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.UnitDelay = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearState_k = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch1_j = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch2 = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch3_f = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch4 = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch5_m = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.Switch6 = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.MeAP_e_FiltdGearRptState = TeAP_e_FiltdGearState_SNA;
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o14 =
      TeAutoPark_e_GearCmd_Drive;
    DT24_CVADAS_AP_CodGen_B.IeAP_e_SemiParkSysSts = ((uint8_T)1U);
    DT24_CVADAS_AP_CodGen_B.CVADAS_AutoPark_Main_o23 = true;
    DT24_CVADAS_AP_CodGen_B.MeAP_b_ParkSlotDetctSts = true;
    DT24_CVADAS_AP_CodGen_B.IeAP_b_MnvPosOk = true;
  }

  /* custom signals */
  MbNVM_ProxyParam = DT24_CVADAS_AP_CodGen_rtZTbNVM_ProxyCalibParam;
  RPAWarnOut = DT24_CVADAS_AP_CodGen_rtZTbAP_RPAWarnOut_t;
  FPAWarnOut = DT24_CVADAS_AP_CodGen_rtZTbAP_FPAWarnOut_t;
  IeHMI_e_ParkStyle = TeAutoPark_e_ParkStyle_Rear_In;

  /* Model Initialize function for ModelReference Block: '<Root>/CVADAS_AutoPark_Main' */
  DT24_CVADAS_AutoPark_Func_initialize(rtmGetErrorStatusPointer
    (DT24_CVADAS_AP_CodGen_M));

  /* Start for ModelReference generated from: '<Root>/CVADAS_AutoPark_Main' */
  DT24_CVADAS_AutoPark_Func_Start();

  /* Start for DataStoreMemory: '<S1>/DataStoreMemory5' */
  SigMgr_PpFPAWarnOut_TbAP_FPAWarnOut_t_Put
    ((TbAP_FPAWarnOut_t *)&DT24_CVADAS_AP_CodGen_rtZTbAP_FPAWarnOut_t);

  /* Start for DataStoreMemory: '<S1>/DataStoreMemory6' */
  SigMgr_PpRPAWarnOut_TbAP_RPAWarnOut_t_Put
    ((TbAP_RPAWarnOut_t *)&DT24_CVADAS_AP_CodGen_rtZTbAP_RPAWarnOut_t);

  /* Start for DataStoreMemory: '<S2>/HMIInfoToAP_DSM' */
  // set_HMIInfoToAP(DT24_CVADAS_AP_CodGen_rtZHMIInfoToAP_t);

  /* ConstCode for RelationalOperator: '<S87>/Compare' incorporates:
   *  Constant: '<S87>/Constant'
   */
  MeAP_b_ObjInPath = (DT24_CVADAS_AP_CodGen_ConstB.Saturation < 40.0F);

  /* InitializeConditions for UnitDelay: '<S183>/Unit Delay' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay_DSTATE_m = TeAP_e_FiltdGearState_Parking;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
  DT24_CVADAS_AP_CodGen_DW.UnitDelay1_DSTATE_g = true;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearCenterMinDist = 1023.0F;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearRightMinDist = 1023.0F;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntCenterMinDist = 1023.0F;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntRightMinDist = 1023.0F;
  DT24_CVADAS_AP_CodGen_DW.LastGood_RearLeftMinDist = 1023.0F;
  DT24_CVADAS_AP_CodGen_DW.LastGood_FrntLeftMinDist = 1023.0F;

  /* SystemInitialize for Chart: '<S88>/CalculateMinDistances1' incorporates:
   *  SubSystem: '<S91>/GetDiagonalCenterRegion'
   */
  /* SystemInitialize for Enabled SubSystem: '<S97>/CalcSideRegLongThresh' */
  /* SystemInitialize for Outport: '<S102>/SideRegionLongThresh' */
  DT24_CVADAS_AP_CodGen_B.SideRegionLongThresh = 1023;

  /* End of SystemInitialize for SubSystem: '<S97>/CalcSideRegLongThresh' */

  /* SystemInitialize for Outport: '<S97>/SideRegionLongThresh' */
  DT24_CVADAS_AP_CodGen_B.OutportBufferForSideRegionLongThresh = 1023;

  /* SystemInitialize for ModelReference generated from: '<Root>/CVADAS_AutoPark_Main' */
  DT24_CVADAS_AutoPark_Func_Init();
     SigMgr_Data_CalDataProvider_MCU_2_1_Def_Get(&DT24_CVADAS_AP_CodGen_B.IbAP_CalDataProviderMCU21Def);
     SigMgr_Data_APA_Calibration_data_MCU2_1_t_Get(&DT24_CVADAS_AP_CodGen_B.IbAP_VrntTunParam);
}

/* Model terminate function */
void DT24_CVADAS_AP_CodGen_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
