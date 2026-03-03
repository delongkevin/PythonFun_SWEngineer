/* ===========================================================================
 * MAGNA Electronics - C O N F I D E N T I A L
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * ===========================================================================
 * SHORT:   aHmiM_STM_Functions
 * DESIGN:  Fries S.
 * DESCRIPTION:
 *    Normal Operation Sub State Machine for the aHmiM Module
 * ======================================================================== */

/* ######################################################################################################
 * --- MODULE VERSION ---
 * ###################################################################################################### */
#define AHMIM_STM_FUNCTIONS_D_VERSION_ID_C "$Id: aHmiM_STM_Functions.c 1.30.1.16.1.2.1.32 2022/01/06 14:06:36IST Mahesh Singam (mahesing) Draft  $"
/* ------------------------------------------------------------------------------------------------------ */

/* PRQA S 3206 EOF */ /* Suppress warning "The parameter 'ST_CurrState_e' is not used in this function. - This is needed for the condition functions of the STM" */
/* PRQA S 0715 EOF */ /* Suppress warning "Nesting of control structures (statements) exceeds 15. - That is not an issue" */

/* ######################################################################################################
 * --- include files ---
 * ###################################################################################################### */
#define AHMIM_STM_FUNCTIONS_C_

#include "cogent_api.h"
#include "cam_testpattern.h"
#include "aHmiM_STM_RadioDisp.h"
// Included Header Files Porting
#include "aHmiM.h"
#include "aHmiM_STM.h"
#include "External_Dependency.h"
#include "HMI_drv_par.h"
#include "ME_hydra2defs_OEM.h"
#include <string.h>
#include <utils/console_io/include/app_log.h>
#include <math.h>
#include <ti/osal/TimerP.h>
#include <ti/osal/osal.h>

#undef AHMIM_STM_FUNCTIONS_C_ /* PRQA S 0841 ++*/ /* Suppress warning "Using '#undef'." */

/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- local macros ---
 * ###################################################################################################### */
// #define SW_PATCH_DEBUG
#define HMI_PROFILING 0
#define HMI_DEGRADATION_FUNC_DEBUG_ENABLE 0 // debug flag for degradation debug prints
#if HMI_PROFILING
//#define GPIO_TIMING_MEASURE_ENA
#if defined(GPIO_TIMING_MEASURE_ENA)
#include <ti/csl/csl_gpio.h>
#endif
uint64_t end_time, end_time2, hit_counter, hit_counter2;
bool TouchFlag, GearFlag, DisplayStsFlag;
bool TouchFlag2, GearFlag2, DisplayStsFlag2;
uint64_t TouchRecieved, GearRecieved, DisplayStsRecieved;  
#endif
/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- local defines ---
 * ###################################################################################################### */
#define HMI_XCP_LOCKOUTWAITCYCLES  5u                                                /* 5 cycles wait time */
#define HMI_XCP_SCREENREQ_TIMEOUT  50u                                               /* 500 msec timeout to get correct screen response */
#define HMI_XCP_K_TDELAYPRND       250000llu                                         /* Req. ID 301430 - Time of delay after entering new gear position */
#define HMI_BACKING_EVENT_OFF_SPEED 12.0F                                             /* Backing event speed limit(KMPH) above which it will go to END state */                                      
static BOOL was_ScreenActiveinZynq = FALSE;
static BOOL StmBootUpViewSts = FALSE;
static BOOL lastReqSvResponseFailureSts =  FALSE;
static BOOL lastValidReqSentSts = FALSE;
/*
@@ SYMBOL = HMI_XCP_VIDEO_ON_SPEED
@@ A2L_TYPE = PARAMETER
@@ DATA_TYPE = FLOAT
@@ ALIAS = HMI_XCP_VIDEO_ON_SPEED
@@ GROUP = MCU2_0
@@ DESCRIPTION = "ViewManager"
@@ END
*/
float32_t HMI_XCP_VIDEO_ON_SPEED      = (f32)ASIGCONVERTER_D_VEHSPEED_SNA;

/*
@@ SYMBOL = HMI_XCP_VIDEO_OFF_SPEED
@@ A2L_TYPE = PARAMETER
@@ DATA_TYPE = FLOAT
@@ ALIAS = HMI_XCP_VIDEO_OFF_SPEED
@@ GROUP = MCU2_0
@@ DESCRIPTION = "ViewManager"
@@ END
*/                                                   /* Req. ID 301430 - Video Output shall be ON when Vehicle speed is below */
float32_t HMI_XCP_VIDEO_OFF_SPEED     = (f32)ASIGCONVERTER_D_VEHSPEED_SNA;                                                  /* Req. ID 301430 - Video Output can be OFF when Vehicle speed exceeds */

/*
@@ SYMBOL = HMI_XCP_PDC_THRESHOLD_SPEED
@@ A2L_TYPE = PARAMETER
@@ DATA_TYPE = FLOAT
@@ ALIAS = HMI_XCP_PDC_THRESHOLD_SPEED
@@ GROUP = MCU2_0
@@ DESCRIPTION = "ViewManager"
@@ END
*/
float32_t HMI_XCP_PDC_THRESHOLD_SPEED = 11.0f;                                              /* Req. ID 606753 - Above 11km/h PDCs should be disabled */

/*
@@ SYMBOL = HMI_XCP_RVC_VIEWRESET_SPEED
@@ A2L_TYPE = PARAMETER
@@ DATA_TYPE = FLOAT
@@ ALIAS = HMI_XCP_RVC_VIEWRESET_SPEED
@@ GROUP = MCU2_0
@@ DESCRIPTION = "ViewManager"
@@ END
*/
float32_t HMI_XCP_RVC_VIEWRESET_SPEED = 12.8748f; /* Req. ID 445012, Defect 378582 Fix */ /* View Reset Speed for RVC-Only Zoomed View is 8mph = 12.8748kmh */

/*
@@ SYMBOL = HMI_XCP_TRG_PANGUARD_SPEED
@@ A2L_TYPE = PARAMETER
@@ DATA_TYPE = FLOAT
@@ ALIAS = HMI_XCP_TRG_PANGUARD_SPEED
@@ GROUP = MCU2_0
@@ DESCRIPTION = "ViewManager"
@@ END
*/
float32_t HMI_XCP_TRG_PANGUARD_SPEED  = 13.0f;                                             /* Req. ID 525408 - The CVPM should not react to TRG L/R Panning buttons if VehSpeed >= 13 KPH. */

/*0.5, 0.7 and 0.9 correspond to 50, 70 and 90 percent repectively*/
#define aHmiM_STM_D_JackKnife_OrangeZONE_MIN ((real32_T)(0.50f))
#define aHmiM_STM_D_JackKnife_RedZONE_MIN ((real32_T)(0.70f))
#define aHmiM_STM_D_JackKnife_RedTrlr_MIN ((real32_T)(0.90f))


/******************THA Related Calibration Parameters***********************/
#define THA_DELTA_THRESHOLD1 125u
/***************************************************************************/

static DiagToSVS_t DiagToSVS_e;
static DiagToSVS_t Prev_DiagToSVS_e;
static SVSToDiag_t SVSToDiag_e;
static SVSToDiag_t Prev_SVSToDiag_e;
static uint8_t prndStatus_e_old = 0xFFu;

static TbSVS_e_SVSCalibSMToHmi_t TSC_to_HMI;
static TbSVS_e_SVSCalibSMToHmi_t prev_TSC_to_HMI;
static void aHmiM_STM_f_Entry_TSC_Aiming_View_v(void);
static void aHmiM_STM_f_Do_TSC_Aiming_View_v(void);
static void aHmiM_STM_f_Exit_TSC_Aiming_View_v(void);
/* ######################################################################################################
 * --- local defines for logs ---
 * ###################################################################################################### */
//#define TRSC_LOG_ENABLE
//#define THA_LOG_ENABLE
//#define APA_LOG_ENABLE
//#define AP_LOGS
// Added to assist BSW in debugging
// #define PROXI_DEBUG
#define HMI_ESSENTIAL_DEBUG 0
/*********************************************************************************************************************/
/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- local typedefs ---
 * ###################################################################################################### */
struct aHmiM_STM_s_ViewTriggerSetList_s
{
  BOOL GearToReversed_b;              /* Trigger 1 */
  BOOL PRNDStatSNAorUndef_b;          /* Trigger 3 */
  BOOL GearToPark_b;                  /* Trigger 4 */
  BOOL GearToNeutral_b;               /* Trigger 5 */
  BOOL GearToDrive_b;                 /* Trigger 6 */
  BOOL NotDispRearCam_b;              /* Trigger 7 */
  BOOL VehSpeedLowerVideoONSpeed_b;   /* Trigger 8 */
  BOOL IgnitionNotRun_b;              /* Trigger 9 */
  BOOL VehSpeedHigherVideoOFFSpeed_b; /* Trigger 10 */
  BOOL VehSpeedSignalNA_b;            /* Trigger 11 */
  BOOL CamDispStsView1_b;             /* Trigger 12 */
  BOOL CamDispStsView2_b;             /* Trigger 13 */
  BOOL VehSpeedHigherRVCResetSpeed_b; /* Trigger 14 */
  BOOL REAR_TOP_BTN_PRESSED_b;        /* Trigger 15 */
  BOOL REAR_CROSS_BTN_PRESSED_b;      /* Trigger 16 */
  BOOL FRONT_CROSS_BTN_PRESSED_b;     /* Trigger 17 */
  BOOL FRONT_TOP_BTN_PRESSED_b;       /* Trigger 18 */
  BOOL X_BTN_PRESSED_b;               /* Trigger 19 */
  BOOL FFCV_BTN_PRESSED_b;            /* Trigger    */
  BOOL RVC_BTN_PRESSED_b;             /* Trigger 20 */
  BOOL MAGNIFIER_BTN_PRESSED_b;       /* Trigger 21 */
  BOOL SFTBTN_SVC_AUX_PRESSED_b;      /* Trigger 22 */
  BOOL SFTBTN_ZOUT_PRESSED_b; /* Trigger 24 */
  BOOL CamDispStsView3_b;     /* Trigger 28 */
  BOOL CamDispStsView4_b;     /* Trigger 29 */
  BOOL CamDispStsView5_b;
  BOOL CamDispStsView6_b;
  BOOL CamDispStsView7_b;
  BOOL CamDispStsView8_b;
  BOOL CamDispStsView9_b;
  BOOL CamDispStsView11_b;
  BOOL CamDispStsView12_b;
  BOOL CamDispStsView13_b;
  BOOL CamDispStsView14_b;
  BOOL IgnitionRun_b;
  BOOL IgnitionNotRunToRun_b;
  BOOL NotDispTrailerOrWirlessCamera_b;
  BOOL TrscToStandBy_b;
  BOOL TrscToCalibrating_b;
  BOOL TrscToPreActive_b;
  BOOL TrscToActive_b;
  BOOL TrscWasActive_b;
  BOOL TrscToSNA_b;
  BOOL TrailerWirelessCam_b;
  BOOL GearNotEqualToNeutral_b;
  BOOL GearNotEqualToReverse_b;
  BOOL TRGLEFT_BTN_PRESSED_b;
  BOOL TRGRIGHT_BTN_PRESSED_b;
  BOOL TRGAUTO_BTN_PRESSED_b;
  BOOL RoutineMsgRcvChanged_b;
  BOOL THA_Active_to_NotActive;
  BOOL isOneCamPresent;
  BOOL isFourCamPresent;
  BOOL isTHAPresent;
};

struct aHmiM_STM_s_ViewGuardSetList_s
{
  BOOL GUARD_5_b;                                   /* Guard 5 - Responsible for Trigger 8 & 11 */
  BOOL GUARD_6_b;                                   /* Guard 6 - Responsible for Trigger 5 */
  BOOL GUARD_7_b;                                   /* Guard 7 - Responsible for Trigger 3 */
  BOOL GUARD_8_b;                                   /* Guard 8 - Responsible for Trigger 8 & 11 */
  BOOL GUARD_9_b;                                   /* Guard 9 - Responsible for Trigger 7 */
  BOOL GUARD_10_b;                                  /* Guard 10 - Responsible for Trigger 7 */
  BOOL GUARD_11_b;                                  /* Guard 11 - Responsible for Trigger 4 */
  BOOL GUARD_12_b;                                  /* Guard 12 - Responsible for Trigger 5 */
  BOOL GUARD_13_b;                                  /* Guard 13 - Responsible for Trigger 10 */
  BOOL GUARD_14_b;                                  /* Guard 14 - Responsible for Trigger 3 */
  BOOL M_SVC_View_RearTop_b;                        /* Guard 15 -  */
  BOOL M_SVC_View_FrontTop_b;                       /* Guard 16 -  */
  BOOL M_SVC_View_RearCross_b;                      /* Guard 17 -  */
  BOOL M_SVC_View_FrontCross_b;                     /* Guard 18 -  */
  BOOL GUARD_19_b;                                  /* Guard 19 -  */
  BOOL GUARD_20_b;                                  /* Guard 20 -  */
  BOOL GUARD_IGN_RUN;                               /* Guard 21 -  */
  BOOL GUARD_21_b;                                  /* Guard 21 -  */
  BOOL GUARD_BURV_MemoryZoom_b;                     /* Guard BURV_MemoryZoom */
  BOOL GUARD_VehSpdDispStat_b;                      /* vehspd dispStat */
  BOOL GUARD_TGW_CAM_DISP_STAT_b;                   /* TGW_CAMERA_DISP_STAT */
  BOOL GUARD_22_b;                                  /* Guard 22 - */
  BOOL GUARD_Trlr_Rev_Guidance_Prsnt_b;             /* Guard Trlr_Rev_Guidance_Prsnt */
  BOOL GUARD_VehSpd_TRGPanning_b;                   /* VehSpd guard for TRG Panning  */
  BOOL GUARD_RCV_Views_b;                           /* BUNRV BUZRV */
  BOOL GUARD_FrontTop_FrontCross_RearCross_Views_b; /* Front/Rear Cross and Front Top View */
  BOOL GUARD_RearTop_RearCross_FrontCross_Views_b;  /* Front/Rear Cross and Rear Top View */
  BOOL GUARD_NotReverse_b;                          /* Not reverse Gear */
  BOOL GUARD_OFFRoadCameraPresent_b;                /* Off road cam */
/*TBD - VDW - Below_code needs to revisit once MY22 DT application requirements updated
for removed signals. Currently disabled code to avoid build errors due to removed signals. */
#if 0
  BOOL GUARD_AUX_Connected_b;           /* Aux_Connected */
#endif
  /*BOOL GUARD_AUX_Views_b;    */          /* Aux Views */
  BOOL GUARD_FFC_View_b;                   /* FFC View */
  BOOL GUARD_TRG_Views_b;                  /* TRG_Views */
  BOOL GUARD_NOT_DRIVE_AND_NOT_VIEW1234_b; /* Guard for Req ID 3102114 */
  BOOL GUARD_DRIVE_AND_NOT_VIEW1234_b;
  BOOL GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b; /* Guard for Req ID 3102772 */
  BOOL GUARD_VehSpeedHigherVideoOFFSpeed_b;
  BOOL GUARD_NotDispTrailerOrWirelessCamera_b;
  BOOL GUARD_SVCSuperState_b;
  BOOL M_SVC_View_BUNRV_BUZRV_b;
  BOOL M_SVC_View_TRA_b;

  BOOL GUARD_TrscPreActive_b;
  BOOL GUARD_TrscActive_b;
  BOOL GUARD_TrscStandBy_b;
  BOOL GUARD_TrscCalibrate_b;
  BOOL GUARD_TrscModulFitted_b;
  BOOL M_THA_Active_Status;
  BOOL prev_M_THA_Active_Status;
};

typedef enum aHmiM_STM_e_SwitchToGearDetection_e
{
  aHmiM_STM_e_None = 0u,
  aHmiM_STM_e_Reverse = 1u,
  aHmiM_STM_e_Park = 2u,
  aHmiM_STM_e_Neutral = 3u,
  aHmiM_STM_e_Drive = 4u,
  aHmiM_STM_e_NotReverse = 5u
} aHmiM_STM_e_SwitchToGearDetection_t;

typedef enum aHmiM_STM_E_RequestedMode_e
{
  aHmiM_STM_E_NoModeRequested = 0u,
  aHmiM_STM_E_NormalOperationModeRequested = 1u,
  aHmiM_STM_E_InactiveModeRequested = 2u
} aHmiM_STM_E_RequestedMode_t;

typedef enum aHmiM_STM_E_VehicleType_e
{
  aHmiM_STM_E_VehType_Chrysler = 0u,
  aHmiM_STM_E_VehType_Maserati = 1u,
  aHmiM_STM_E_VehType_D2DJ = 2u,
  aHmiM_STM_E_VehType_Undefined = 3u
} aHmiM_STM_E_VehicleType_t;
/* ------------------------------------------------------------------------------------------------------ */

/* ######################################################################################################
 * --- local variables ---
 * ###################################################################################################### */
/* List Variables for the Triggers and Guards */
// Porting
static struct aHmiM_STM_s_ViewTriggerSetList_s aHmiM_STM_v_ViewTriggerSetList_s;
static struct aHmiM_STM_s_ViewGuardSetList_s aHmiM_STM_v_ViewGuardSetList_s;

static aHmiM_STM_E_RequestedMode_t aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;

static BOOL aHmiM_STM_v_InitialRun_b;

static aZynqM_S_ScreenType_t aHmiM_STM_v_RequestedScreenByHmiM_s;
static aZynqM_S_ScreenType_t aHmiM_STM_v_CurrentScreenOnZynqM_s;
static u8 aHmiM_STM_v_ZoomFactor_u8 = 100u;
static ME_Hydra2defs_S_GooseNeck_t aHmiM_STM_v_gooseneck_s;

static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_M_SVC_View_e; /* Last Surround View Camera View - Req.ID: 1922592 */
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_M_BURV_Memory_e;
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_LastRequestedView_e;
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_LastScreenOnZynqM_s;
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_RequestedViewByHmiM_s;
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_LastScreenBeforeTHA_e;
/* Req 515905 , 526963 */
static ME_Hydra2defs_E_DNDGear_t aHmiM_STM_v_M_DNDGear_e = M_DNDGear_NotSet;
/* Req Id - 529288 ,529290 */
static ME_Hydra2defs_E_FFClatch_t aHmiM_STM_v_M_FFClatch_e = M_FFClatch_NotSet;

static BOOL aHmiM_STM_v_M_TRA_View;
static BOOL aHmiM_STM_v_MoreCamOfFullScreenFrameExpected_b;

static ME_Hydra2defs_E_SystemState_t aHmiM_STM_v_SystemState_e = SystemONVideoOFF;
static ME_Hydra2defs_E_SystemState_t aHmiM_STM_v_LastSystemState_e = SystemONVideoOFF; //! FOR DEBUG

ScreenRequest_t screenReq;
static ScreenRequest_t prev_screenReq;
static ScreenRequest_t lastValid_screenReq;
ScreenResponse_t screenResponse;
static ScreenRequest_t AP_screenRes;
static ScreenRequest_t prev_THAscreenReq;
SvsToVCAN_t HMI_to_VCAN;
static SvsToVCAN_t prev_HMI_to_VCAN;
aSigConverterTypes_S_Rx_HmiMRelatedData_t aHmiM_STM_v_Rx_HmiMRelatedData_e;

static SvsToTHA_t SvsToTHA_e;
static SvsToTHADet_t SvsToTHADet_e;

static SvsToTHA_t prev_SvsToTHA_e;
static SvsToTHADet_t prev_SvsToTHADet_e;


// static aSigConverterTypes_S_Tx_HmiMRelatedData_t aHmiM_STM_v_Tx_HmiMRelatedData_e.;
// static aSigConverterTypes_S_Tx_HmiMRelatedData_t prev_aHmiM_STM_v_Tx_HmiMRelatedData_e; //! FOR DEBUG FZ
// static boolean HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = FALSE;    /* 1 Bit */
// static boolean MemUpdateEnforcer1_b = TRUE;
// static boolean HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = FALSE;      /* 1 bit */
// static boolean MemUpdateEnforcer2_b = TRUE;
// static boolean HMI_to_VCAN.IeSVS_b_AUXCamReqSts = FALSE;    /* 1 Bit *//*Req Id : 498356*/
static aSigConverter_E_DisplayView3_t Tx_HmiView;

static ME_Hydra2defs_E_ViewType_t LastViewBeforeTestPattern_e;
static boolean TestPatternPending_b = FALSE;

static ME_Hydra2defs_E_ViewType_t LastViewBeforeTSC_e;
static boolean TSC_Pending_b = FALSE;
static boolean prev_TSC_Pending_b = FALSE;

static BOOL aHmiM_STM_v_Reverse_RisingEdge_b;  /* RevGear Auto&Man Transmission */
static BOOL aHmiM_STM_v_Reverse_FallingEdge_b; /* RevGear Auto&Man Transmission */
static BOOL aHmiM_STM_v_Neutral_RisingEdge_b;  /* Neutral Automatic Transmission */
static BOOL aHmiM_STM_v_Neutral_FallingEdge_b; /* Neutral Automatic Transmission */
static BOOL aHmiM_STM_v_Park_RisingEdge_b;     /* Park Automatic Transmission */
static BOOL aHmiM_STM_v_Park_FallingEdge_b;    /* Park Automatic Transmission */
static BOOL aHmiM_STM_v_Drive_RisingEdge_b;    /* Drive Automatic Transmission */
static BOOL aHmiM_STM_v_Drive_FallingEdge_b;   /* Drive Automatic Transmission */

static BOOL aHmiM_STM_v_REAR_TOP_BTN_PRESSED_b;    /* Variable indicating that the Button for the RearTopView was pressed */
static BOOL aHmiM_STM_v_FRONT_TOP_BTN_PRESSED_b;   /* Variable indicating that the Button for the FrontTopView was pressed */
static BOOL aHmiM_STM_v_REAR_CROSS_BTN_PRESSED_b;  /* Variable indicating that the Button for the RearCrossView was pressed */
static BOOL aHmiM_STM_v_FRONT_CROSS_BTN_PRESSED_b; /* Variable indicating that the Button for the FrontCrossView was pressed */
static BOOL aHmiM_STM_v_X_BTN_PRESSED_b;           /* Variable indicating that the X-Button was pressed */
static BOOL aHmiM_STM_v_FFCV_BTN_PRESSED_b;        /* Variable indicating that the FFCV-Button was pressed */
static BOOL aHmiM_STM_v_RVCONLY_BTN_PRESSED_b;     /* Variable indicating that the RVCOnly Soft-Button was pressed */
static BOOL aHmiM_STM_v_MAGNIFIER_BTN_PRESSED_b;
static BOOL aHmiM_STM_v_VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b; /* Variable indicating that the MoreCams-Button was pressed */
static BOOL aHmiM_STM_v_VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b; /* Variable indicating that the MoreCams-Button was pressed */

static BOOL aHmiM_STM_v_VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b; /* Variable indication that the AUX CAM Button was pressed */
static BOOL aHmiM_STM_v_VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b; /* Variable indication that the AUX CAM Button was pressed */
static BOOL aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b;
static BOOL aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b;
static BOOL aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b;
static aHmiM_E_TrgStatus_t TRG_Stat;
static aHmiM_E_TrgStatus_t Last_TRG_Stat;
static BOOL TRG_Latched;
static BOOL prev_TRG_Latched;
static BOOL First_Reverse_After_TRG_Done;
static BOOL First_Reverse_After_ECU_On = FALSE;
static BOOL MoreCam1Set = FALSE;

static back_Event_Sts_t Back_Event_Sts = BACK_EVENT_END;
static ME_Hydra2defs_E_ViewType_t Last_TRG_Screen_Before_First_R_gear = ME_Hydra2defs_OEM_E_NoView;

static BOOL aHmiM_STM_v_ZOOM_BTN_PRESSED_b; /* Variable indication that the Zoom Button was pressed */

static BOOL aHmiM_STM_v_IgnoreVehicleOffSpeed = FALSE; /* Defect 3836277 */ /* PRQA S 3218 */ /* keep this static */

static aHmiM_STM_e_SwitchToGearDetection_t aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_None;
static aSigConverter_E_PRND_STAT_t lastValidGearReq = PRND_STAT_NA;
static aSigConverter_E_PRND_STAT_t curValidGearReq = PRND_STAT_NA;
static BOOL aHmiM_STM_v_GearNotReverse_Delayed_b = FALSE;
static BOOL aHmiM_STM_v_GearReverse_Delayed_b = FALSE;

static BOOL aHmiM_STM_v_StartLockOutWaitTimer_b = FALSE;
static u32 aHmiM_STM_v_ScreenRequestTimeout_u32 = HMI_XCP_SCREENREQ_TIMEOUT;
static u32 aHmiM_STM_v_ReleaseWaitForScreenCnt_u32 = HMI_XCP_SCREENREQ_TIMEOUT;
static u32 aHmiM_STM_v_ScreenRequestTimeoutCnt_u32 = 0u;
static BOOL aHmiM_STM_v_ScreenRequestTimedOut_b = FALSE;
static BOOL aHmiM_STM_v_EnableScreenRequestTimeoutTimer = FALSE;
static uint64_t aHmiM_STM_v_LastScreenRequestTime_u64 = 0u;

static BOOL aHmiM_STM_v_EnableScreenRequestRetryTimer = FALSE;
static uint64_t aHmiM_STM_v_LastScreenRequestRetryTime_u64 = 0u;

static BOOL aHmiM_STM_v_SoftBtnsDisabled_b = FALSE;

static f32 aHmiM_STM_v_Video_On_Speed_f32;                        /*Defect 378582 Fix, Changing variable u8 to float f32*/
static f32 aHmiM_STM_v_Video_Off_Speed_f32;                       /*Defect 378582 Fix, Changing variable u8 to float f32*/
static uint64_t aHmiM_STM_v_K_TDelayPRND_u64 = HMI_XCP_K_TDELAYPRND; /* Fix for defect 729785: Variable is Initialized at the place declaration itself.*/
static uint64_t StartTimeDelayPRND;
static uint64_t EndTimeDelayPRND;
static aHmiM_STM_E_VehicleType_t aHmiM_STM_v_VehicleType_e;
static SVStoTRSCSMVC_t SVStoTRSCSMVC_e;
static SVStoTRSCSMVC_t prev_SVStoTRSCSMVC_e;
static aSigConverter_E_TRSC_STAT_t aHmiM_STM_v_Last_TRSC_STAT_t = TRSC_INVALID;
/********************************************************************************/
/************************THA Related Variables Declared**********************************/
static ME_Hydra2defs_E_ViewType_t aHmiM_STM_v_M_View_Before_THA_Active_e;
static aSigConverter_E_THAScreenRequest_t M_Requested_THA_State;            
static aSigConverter_E_THAScreenRequest_t M_Current_THA_State_On_Zync;
static aSigConverter_E_THAScreenRequest_t M_Current_THA_State_Received;
static aSigConverter_E_THAScreenRequest_t last_M_Current_THA_State_Received;
static aSigConverter_E_THAScreenRequest_t M_Current_THA_State_On_Screen;
static BOOL aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b; // THA Zoom out button pressed status
static BOOL aHmiM_STM_v_VIEW_SCRN_TCH_STS_b;        // THA Screen touch status
static BOOL aHmiM_STM_v_VIEW_ZOOM_STS_b;
static BOOL aHmiM_STM_v_CONFIRM_BTN_PRESSED_b;   // THA Confirm Button Pressed Status
static BOOL aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b; // THA Confirm Button Pressed Status during State 4, 20 and 24
static BOOL aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b; // THA Confirm Button Pressed Status during state 5
static BOOL aHmiM_STM_v_START_BTN_PRESSED_b;     // THA Start Button Pressed Status
static BOOL aHmiM_STM_v_THA_SFT_BTN_PRESSED_b;   // THA Soft Button Pressed Status
static BOOL aHmiM_STM_v_THA_X_BTN_PRESSED_b;     // THA Soft Button Pressed Status
static uint16 aHmiM_STM_v_CPLR_POS_X_THA_u;      // Coupler position pixel coordinates x axis value 
static uint16 aHmiM_STM_v_CPLR_POS_Y_THA_u;      // Coupler position pixel coordinates y axis value
static uint16 aHmiM_STM_v_CPLR_POS_X_u;          // Bullet Icon position pixel coordinates x axis value
static uint16 aHmiM_STM_v_CPLR_POS_Y_u;          // Bullet Icon position pixel coordinates y axis value
static uint16 aHmiM_STM_v_SCRN_TCH_X_u;
static uint16 aHmiM_STM_v_SCRN_TCH_Y_u;       
static uint8 M_Cplr_Htch_Distance;             // Coupler Hitch longitudinal distance in pixels
static BOOL M_THA_Abort_Req_b;                 // THA Abort Request by HMI
static BOOL M_Is_Valid_Tch_Zone;               // THA View zoom response
static BOOL M_THA_View_Zoom_Or_Not;            // THA View should zoom or not

static aSigConverter_E_THAScreenRequest_t prev_M_Current_THA_State_Received; // Previous Current THA state received
static BOOL prev_aHmiM_STM_v_VIEW_ZOOM_STS_b;       // for coupler selection
static BOOL prev_aHmiM_STM_v_VIEW_SCRN_TCH_STS_b;   // For THA Screen touch status
static BOOL prev_aHmiM_STM_v_CONFIRM_BTN_PRESSED_b; // For THA Confirm Button Pressed Status
static BOOL prev_aHmiM_STM_v_START_BTN_PRESSED_b;   // THA Start Button Pressed Status
static BOOL prev_aHmiM_STM_v_THA_SFT_BTN_PRESSED_b; // THA Soft Button Pressed Status
static BOOL prev_aHmiM_STM_v_THA_X_BTN_PRESSED_b; // THA Screen Exit Button pressed status
static uint16 prev_aHmiM_STM_v_CPLR_POS_X_u;        // Coupler position pixel coordinates x axis value
static uint16 prev_aHmiM_STM_v_CPLR_POS_Y_u;        // Coupler position pixel coordinates y axis value
static uint8 prev_M_Cplr_Htch_Distance;             // Coupler Hitch longitudinal distance in pixels
/********************************************************************************/

/******************************* Degrdation variables declaration ***************************************/
static BOOL vDisableSVS = FALSE;
static BOOL vViewDegToRearTop= FALSE;
static BOOL vDisableZoomBut = FALSE;
/********************************************************************************************************/
/*#############################################################################*/

/* ------------------------------------------------------------------------------------------------------ */
/* ######################################################################################################
 * --- local function declarations ---
 * ###################################################################################################### */

static void aHmiM_STM_f_Entry_NotInit_v(void);
static void aHmiM_STM_f_Entry_Init_v(void);
static void aHmiM_STM_f_Entry_CheckInactiveMode_v(void);
static void aHmiM_STM_f_Entry_CheckView_v(void);
static void aHmiM_STM_f_Entry_CheckOvl_v(void);
static void aHmiM_STM_f_Entry_CheckFailsafe_v(void);
static void aHmiM_STM_f_Entry_RequestScreenOnZynqM_v(void);
static void aHmiM_STM_f_Entry_WaitForRequestedScreenOnZynqM_v(void);
static void aHmiM_STM_f_Entry_LockOutWait_v(void);
static void aHmiM_STM_f_Entry_End_v(void);

static void aHmiM_STM_f_DoState_NotInit_v(void);
static void aHmiM_STM_f_DoState_Init_v(void);
static void aHmiM_STM_f_DoState_CheckInactiveMode_v(void);
static void aHmiM_STM_f_DoState_CheckView_v(void);
static void aHmiM_STM_f_DoState_CheckOvl_v(void);
static void aHmiM_STM_f_DoState_CheckFailsafe_v(void);
static void aHmiM_STM_f_DoState_RequestScreenOnZynqM_v(void);
static void aHmiM_STM_f_DoState_WaitForRequestedScreenOnZynqM_v(void);
static void aHmiM_STM_f_DoState_LockOutWait_v(void);
static void aHmiM_STM_f_DoState_End_v(void);

static void aHmiM_STM_f_Exit_NotInit_v(void);
static void aHmiM_STM_f_Exit_Init_v(void);
static void aHmiM_STM_f_Exit_CheckInactiveMode_v(void);
static void aHmiM_STM_f_Exit_CheckView_v(void);
static void aHmiM_STM_f_Exit_CheckOvl_v(void);
static void aHmiM_STM_f_Exit_CheckFailsafe_v(void);
static void aHmiM_STM_f_Exit_RequestScreenOnZynqM_v(void);
static void aHmiM_STM_f_Exit_WaitForRequestedScreenOnZynqM_v(void);
static void aHmiM_STM_f_Exit_LockOutWait_v(void);
static void aHmiM_STM_f_Exit_End_v(void);

static void Reset_BackupZoomViewMemory(void);

static void aHmiM_STM_f_StartScreenRequestTimeoutTimer(void);
static void aHmiM_STM_f_ResetScreenRequestTimeoutTimer(void);
static bool aHmiM_STM_f_IsScreenRequestTimeoutExpr(void);


static void aHmiM_STM_f_StartScreenRequestRetryTimer(void);
static void aHmiM_STM_f_ResetScreenRequestRetryTimer(void);
static bool aHmiM_STM_f_IsScreenRequestRetryExpr(void);
static BOOL retryScreenReqSts = FALSE;

static bool AP_CameraHandshakeTimerExpired;
static bool AP_CameraHandshake_Initiated;
static uint64_t AP_CameraHandshake_StartTime;
#define CameraHandshakeTimeoutThr 20000llu /* Threshhold value changed to 20 ms from 2 sec to avoid black screen when AP finished/aborted and HMI activated again to show gear based view*/
/*Refer AP Requirement Ids : 16127255 , 16127267, timeout value is unknown in requirements hence added whatever felt right*/

static boolean AP_HMI_Active_Status;
static HMIInfoToAP_t   HMI_to_AP;
static IHMIInfoToFPA_t HMI_to_FPA;
static HMIInfoToAP_t   old_HMI_to_AP;
static IHMIInfoToFPA_t old_HMI_to_FPA;
static void AP_HMI_ViewID_Decoding(void);
static void AP_HMI_Overlay_Decoding(void);
static void AP_HMI_Touch_Processing(void);
static void AP_HMI_ParkSlot_Display_Processing(void);
static bool_t AP_HMI_ParkSlot_Touch_Processing(void);
static void AP_HMI_ParkSlot_Overlap_Prevention(void);
static void AP_HMI_Outputs(void);
static void aHmiM_STM_f_Entry_AutoPark_View_v(void);
static void aHmiM_STM_f_Do_AutoPark_View_v(void);
static void aHmiM_STM_f_Exit_AutoPark_View_v(void);

static void AP_HMI_Para_Exit_Overlay_Decoding(void);
static void AP_HMI_Perp_Parkin_Overlay_Decoding(void);
static void AP_HMI_Scanning_Overlay_Decoding(void);
static void AP_HMI_Disclaimer_Overlay_Decoding(void);
static void AP_HMI_Park_Complete_Overlay_Decoding(void);
static void AP_HMI_TV_Text_Overlay_Encoding(void);
static void AP_HMI_Fullscreen_Overlay_Decoding(void);

static void AP_BUMPER_TEST(void);
static void PDC_Blinking(void);
static int counter_ap;
static uint8_t slow_tick = 0;
static uint8_t fast_tick = 0;
static uint8_t tick_count =0;

static void aHmiM_STM_f_Update_MCUDebug0_v(void);

/* TRIGGERS FOR THE VIEWS */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToReversed_b(void);              /* Trigger 1 - M_ReverseGear0->1 + K_TDelayPRND */
static BOOL aHmiM_STM_f_CheckViewTrigger_PRNDStatSNAorUndef_b(void);          /* Trigger 3 - Rx_PRND_STAT -> 0x7 (SNA) || 0x3 || 0x6 */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToPark_b(void);                  /* Trigger 4 - Rx_PRND -> 0x00(P) + K_TDelayPRND +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToNeutral_b(void);               /* Trigger 5 - Rx_PRND -> 0x02(N) + K_TDelayPRND +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToDrive_b(void);                 /* Trigger 6 - Rx_PRND -> 0x04(D) + K_TDelayPRND +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_NotDispRearCam_b(void);              /* Trigger 7 - Rx_TGW_DISP != 0x07 (DISP_REAR_CAMERA) +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedLowerVideoONSpeed_b(void);   /* Trigger 8 - Rx_VEH_SPEED < K_VideoON_Speed +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionNotRun_b(void);              /* Trigger 9 - Rx_CmdIgn =< 0x4 (ACC) */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherVideoOFFSpeed_b(void); /* Trigger 10 - Rx_VEH_SPEED > K_VideoOFF_Speed +*/
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedSignalNA_b(void);            /* Trigger 11 - Rx_VEH_SPEED = 0xFFFF (SNA) */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherRVCResetSpeed_b(void); /* Trigger 14 - Vehicle speed greater than RVC Reset Speed to Full Frame View */
static BOOL aHmiM_STM_f_CheckViewTrigger_REAR_TOP_BTN_PRESSED_b(void);        /* Trigger 15 - Was the RearTopButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_REAR_CROSS_BTN_PRESSED_b(void);      /* Trigger 16 - Was the RearCrossButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FRONT_CROSS_BTN_PRESSED_b(void);     /* Trigger 17 - Was the FrontCrossButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FRONT_TOP_BTN_PRESSED_b(void);       /* Trigger 18 - Was the FrontTopButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_X_BTN_PRESSED_b(void);               /* Trigger 19 - Was the X-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FFCV_BTN_PRESSED_b(void);            /* Trigger  -   Was the FFCV-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_RVC_BTN_PRESSED_b(void);             /* Trigger 20 - Was the RVC-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_MAGNIFIER_BTN_PRESSED_b(void);       /* Trigger 21 - Was the Magnifier-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGLEFT_PRESSED_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGRIGHT_PRESSED_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGAUTO_PRESSED_b(void);

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_SVC_AUX_PRESSED_b(void); /* Trigger 22 - Was the SVC 5TH-Button Pressed? */

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_ZOUT_PRESSED_b(void); /* Trigger 24 - Was the ZOUT-Button Pressed? */

static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView1_b(void); /* Trigger 12 - Camera Display Status = View1 (SurroundView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView2_b(void); /* Trigger 13 - Camera Display Status = View2 (RVC_Only) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView3_b(void); /* Trigger 28 - Camera Display Status = View3 */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView5_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView6_b(void);  /* Trigger 12 - Camera Display Status = View7 (TRGLeftView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView7_b(void);  /* Trigger 12 - Camera Display Status = View7 (TRGRightView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView8_b(void);  /* Trigger 12 - Camera Display Status = View8 (BlindLeftView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView9_b(void);  /* Trigger 12 - Camera Display Status = View9 (BlindRightView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView11_b(void); /* Trigger 12 - Camera Display Status = View7 (TRGRightView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView12_b(void); /* Trigger 12 - Camera Display Status = View7 (TRGRightView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView13_b(void); /* Trigger 12 - Camera Display Status = View7 (TRGRightView) --> Man Activation */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView14_b(void); /* Trigger 12 - Camera Display Status = View7 (TRGRightView) --> Man Activation */

static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionRun_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionNotRunToRun_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_NotDispTrailerOrWirelessCamera_b(void);

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToStandBy_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToCalibrating_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToPreAactive_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToActive_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_TrscWasActive_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToSNA_b(void);

static BOOL aHmiM_STM_f_CheckViewTrigger_TrailerWirelessCam_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoNeutral_b(void);
static BOOL aHmiM_STM_f_Check_MoreCams_BTN_PRESSED_b(void); /*Trigger for MoreCams button pressed*/
static BOOL aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoReverse_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_isSVSEnabled_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_isSVSDisabled_b(void);

//! FZTP
static BOOL aHmiM_STM_f_CheckViewTrigger_IsDiagRoutineMsgRcvChanged_b(void);
static void testPatternBasic(void);
static void testPattern(void);
static v3xISP_ManufacturingTestType_t GetTestPatternType(ME_Hydra3defs_E_TestPatternType_t TestPatternType);

/* GUARDS FOR THE VIEWS */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_5_b(void);                       /* Guard 5 - Responsible for Trigger 8 & 11 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_6_b(void);                       /* Guard 6 - Responsible for Trigger 5 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_7_b(void);                       /* Guard 7 - Responsible for Trigger 3 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_8_b(void);                       /* Guard 8 - Responsible for Trigger 8 & 11 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_9_b(void);                       /* Guard 9 - Responsible for Trigger 7 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_10_b(void);                      /* Guard 10 - Responsible for Trigger 7 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_11_b(void);                      /* Guard 11 - Responsible for Trigger 4 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_13_b(void);                      /* Guard 13 - Responsible for Trigger 10 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_14_b(void);                      /* Guard 14 - Responsible for Trigger 3 */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_b(void);            /* Guard 15 - Responsible for Trigger 19 - M_SVC_View = Rear+Top */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_b(void);           /* Guard 16 - Responsible for Trigger 19 - M_SVC_View = Front+Top */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearCross_b(void);          /* Guard 17 - Responsible for Trigger 19 - M_SVC_View = RearCross */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontCross_b(void);         /* Guard 18 - Responsible for Trigger 19 - M_SVC_View = FrontCross */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_19_b(void);                      /* Guard 19 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT != 0x4 (D) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_20_b(void);                      /* Guard 20 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT = 0x4 (D) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_IGN_RUN_b(void);                 /* Guard 21 - Responsible for Trigger - Rx_IGN => 0x04 (IGN_Run) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_BURV_MemoryZoom_b(void);         /* Guard 24 - Responsible for Trigger - BURV_MemoryZoom */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_VehSpdDispStat_b(void);          /* Guard 25 - Responsible for Trigger - Vehicle.Speed =< 8mph &&  Rx_TGW_CAMERA_DISP_STAT = (0x4) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_b(void);    /* Guard 27 - Responsible for Trigger - Rx_TGW_CAMERA_DISP_STAT = (0x4) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_22_b(void);                      /* Guard 28 - Responsible for Trigger - {(914 =< Rx_TCH_X_COORD < 1010) && (651 =< Rx_TCH_Y_COORD <747)} */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_Trlr_Rev_Guidance_Prsnt_b(void); /* Guard 29 - Responsible for Trigger - Rx_VC_Trlr_Rev_Guidance_Prsnt = 1 */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RCV_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_FrontCross_RearCross_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_RearCross_FrontCross_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_OFFRoadPresent_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_FFC_View_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_DisplayView3_TRG_View_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_NotDrive_And_Not_View1234_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_Drive_And_Not_View1234_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_TRA_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_VehSpeedHigherVideoOFFSpeed_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_NotDispTrailerOrWirelessCamera_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_SVCSuperState_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscPreActive_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscActive_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscStandBy_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscCalibrate_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscModulFitted_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_TRGPanning_VehSpdInRng_b(void);

/********************* THA Related Functions Declarations ***********************************/

static BOOL aHmiM_STM_f_CheckViewTrigger_isTHAPresent_b(void);
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_THA_Active_Status_b(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_isValidTch_Within_Zone(void);               // View Zoom response
static BOOL aHmiM_STM_f_CheckViewTrigger_THA_Active_to_NotActive(void);
static BOOL aHmiM_STM_f_CheckViewTrigger_THA_View_Zoom_Decision(void);
static uint8 aHmiM_STM_f_Get_Coupler_Hitch_Distance_u(void);                 // Function to return longitudinal distance in pixels between coupler and hitch*/
static aSigConverter_E_THAScreenRequest_t aHmiM_STM_f_Get_THA_State_u(void); // Function to return THA State from THA SM */
static aSigConverter_E_THAScreenRequest_t aHmiM_STM_f_Get_THA_State_Response_u(void); // Function to return THA State Set Response */
static void aHmiM_STM_setting_Overlay_bits_THA(void);
static void aHmiM_STM_Verify_Output_Change_THA(void);
static void aHmiM_STM_f_Request_THA_State_to_Zync_u(void);
static void aHmiM_STM_f_Send_THA_State_Response_u(void);
static void aHmiM_THA_Overlays_Debug(void);
static void aHmiM_THA_Related_Debug(void);
static void aHmiM_STM_f_Update_THA_Related_Output_v(void); // Sending THA Soft Button Pressed Status
static void aHmiM_STM_f_Update_User_Slctd_Cplr_Crdnts_THA_b(void);
static void aHmiM_STM_f_Update_Bullet_Icon_Coordinates_b(void);
static void aHmiM_STM_f_Update_Scrn_Pressed_Crdnts_b(void);
static void aHmiM_STM_f_Update_THAScrnTch_PRESSED_b(void);  /* Trigger    - Whether Coupler Selection for first time on screen*/
static void aHmiM_STM_f_Update_THA_Screen_Exit_PRESSED_b(void);  /* Trigger    - Screen Exit Pressed when user wants to exit THA*/
static void aHmiM_STM_f_Update_Confirm_Btn_PRESSED_b(void); /* Trigger    - THA Confirm Button Pressed Status */
static void aHmiM_STM_f_Update_Start_Btn_PRESSED_b(void);   /* Trigger    - THA Start Button Pressed Status  */
static void aHmiM_STM_f_Update_THA_Sft_Btn_PRESSED_b(void); /* Trigger    - THA Soft Button Pressed Status  */
static void aHmiM_STM_f_Update_Zoom_View_Status_b(void); /* Trigger    - THA Soft Button Pressed Status  */
static BOOL aHmiM_STM_f_CheckViewTrigger_THA_SFT_BTN_ZOUT_PRESSED_b(void); /* Was THA ZOUT-Button Pressed? */

/*************************************************************************************/
/* Req 515905 , 526963 */
static void aHmiM_STM_update_M_DNDGear_b(void);
/* Req Id - 529288 ,529290 */
static void aHmiM_STM_update_M_FFClatch_b(void);
/* ENTRY EXIT DO Functions for Views */
static void aHmiM_STM_f_Entry_SystemONVideoOFF_v(void);
static void aHmiM_STM_f_Entry_RearTopView_v(void);
static void aHmiM_STM_f_Entry_FrontTopView_v(void);
static void aHmiM_STM_f_Entry_RearCrossView_v(void);
static void aHmiM_STM_f_Entry_FrontCrossView_v(void);
static void aHmiM_STM_f_Entry_RVCOnlyNormalView_v(void);
static void aHmiM_STM_f_Entry_RVCOnlyZoomView_v(void);
static void aHmiM_STM_f_Entry_FrontWithTiretracks_v(void);
static void aHmiM_STM_f_Entry_TRA_View_v(void);
static void aHmiM_STM_f_Entry_TRGLeftCurb_View_v(void);
static void aHmiM_STM_f_Entry_TRGRightCurb_View_v(void);
static void aHmiM_STM_f_Entry_BlindLeft_View_v(void);
static void aHmiM_STM_f_Entry_BlindRight_View_v(void);
static void aHmiM_STM_f_Entry_TRG_View_v(void);
static void aHmiM_STM_f_Entry_Raw_View_v(void);
static void aHmiM_STM_f_Entry_BUNRVOneCam_View_v(void);
static void aHmiM_STM_f_Entry_BUZRVOneCam_View_v(void);
static void aHmiM_STM_f_Entry_THANormalRearView_v(void);
static void aHmiM_STM_f_Entry_THAZoomRearView1_v(void);
static void aHmiM_STM_f_Entry_THAZoomRearView2_v(void);

static void aHmiM_STM_f_Exit_SystemONVideoOFF_v(void);
static void aHmiM_STM_f_Exit_RearTopView_v(void);
static void aHmiM_STM_f_Exit_FrontTopView_v(void);
static void aHmiM_STM_f_Exit_RearCrossView_v(void);
static void aHmiM_STM_f_Exit_FrontCrossView_v(void);
static void aHmiM_STM_f_Exit_RVCOnlyNormalView_v(void);
static void aHmiM_STM_f_Exit_RVCOnlyZoomView_v(void);
static void aHmiM_STM_f_Exit_FrontWithTiretracks_v(void);
static void aHmiM_STM_f_Exit_TRA_View_v(void);
static void aHmiM_STM_f_Exit_TRGLeftCurb_View_v(void);
static void aHmiM_STM_f_Exit_TRGRightCurb_View_v(void);
static void aHmiM_STM_f_Exit_BlindLeft_View_v(void);
static void aHmiM_STM_f_Exit_BlindRight_View_v(void);
static void aHmiM_STM_f_Exit_TRG_View_v(void);
static void aHmiM_STM_f_Exit_Raw_View_v(void);
static void aHmiM_STM_f_Exit_BUNRVOneCam_View_v(void);
static void aHmiM_STM_f_Exit_BUZRVOneCam_View_v(void);
static void aHmiM_STM_f_Exit_THANormalRearView_v(void);
static void aHmiM_STM_f_Exit_THAZoomRearView1_v(void);
static void aHmiM_STM_f_Exit_THAZoomRearView2_v(void);

static void aHmiM_STM_f_Do_SystemONVideoOFF_v(void);
static void aHmiM_STM_f_Do_RearTopView_v(void);
static void aHmiM_STM_f_Do_FrontTopView_v(void);
static void aHmiM_STM_f_Do_RearCrossView_v(void);
static void aHmiM_STM_f_Do_FrontCrossView_v(void);
static void aHmiM_STM_f_Do_RVCOnlyNormalView_v(void);
static void aHmiM_STM_f_Do_RVCOnlyZoomView_v(void);
static void aHmiM_STM_f_Do_FrontWithTiretracks_v(void);
static void aHmiM_STM_f_Do_TRA_View_v(void);
static void aHmiM_STM_f_Do_TRGLeftCurb_View_v(void);
static void aHmiM_STM_f_Do_TRGRightCurb_View_v(void);
static void aHmiM_STM_f_Do_BlindLeft_View_v(void);
static void aHmiM_STM_f_Do_BlindRight_View_v(void);
static void aHmiM_STM_f_Do_TRG_View_v(void);
static void aHmiM_STM_f_Do_Raw_View_v(void);
static void aHmiM_STM_f_Do_BUNRVOneCam_View_v(void);
static void aHmiM_STM_f_Do_BUZRVOneCam_View_v(void);
static void aHmiM_STM_f_Do_THANormalRearView_v(void);
static void aHmiM_STM_f_Do_THAZoomRearView1_v(void);
static void aHmiM_STM_f_Do_THAZoomRearView2_v(void);

/* HELPER FUNCTIONS */
/* Function for button press coordinates - this function will return true if at the current moment the coordinates for the corresponding button are matching */
static BOOL aHmiM_STM_f_Is_BTN_PRESSED_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16);                                                                                                                                                      /* Function which returns true if the coordinates for the corresponding Button are matching */
static BOOL aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16);                                                                                                                                           /* Function which returns true if the coordinates for the corresponding Button are matching and if application is generating a view */
static BOOL aHmiM_STM_f_Is_BTN_PRESSED_IF_MC_VISIBLE_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16); /* Function which returns true if the coordinates for the corresponding Button are matching and if application is generating a view */ /*297200*/
/* Evaluate the Failsafe Action for the Cameras and set the corresponding Overlay bits */
static void aHmiM_STM_f_EvaluateCamsNA_v(void);

/* Delay Functions for Triggers */
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToReverse_b(void);
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToPark_b(void);
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToNeutral_b(void);
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToDrive_b(void);
static BOOL aHmiM_STM_f_K_TDelayPRND_GearNotReverse_b(void);
static BOOL aHmiM_STM_f_K_TDelayPRND_GearReverse_b(void);

/* Gear Edge Detection */
static void aHmiM_STM_f_GearEdgeDetection_v(void);
static void aHmiM_STM_f_GearDelayDetection_v(void);

static void aHmiM_STM_f_MonitorTchScrn_v(void);

static void aHmiM_STM_f_M_ReversedGearUpdate_v(void); /* Req. ID 298251 */
static void aHmiM_STM_f_M_SVC_ViewUpdate_v(void);

static void aHmiM_STM_f_XButtonHandlingDefault(void);
static void aHmiM_STM_f_ZoomIcoHandlingSpeed_v(void);

static void aHmiM_STM_f_EvaluateTopViewOverlayGroups_v(void); /* Evaluation Function for Overlay Flags which are not bound to a specific View */
static void aHmiM_STM_f_Eval_FrontLeftAJAR_v(void);
static void aHmiM_STM_f_Eval_FrontRightAJAR_v(void);
static void aHmiM_STM_f_Eval_RearLeftAJAR_v(void);
static void aHmiM_STM_f_Eval_RearRightAJAR_v(void);
static void aHmiM_STM_f_Eval_TailgateAJAR_v(void);
static void aHmiM_STM_f_Eval_pdcFL_Mas_v(void); /* Maserati */
static void aHmiM_STM_f_Eval_pdcFR_Mas_v(void); /* Maserati */
static void aHmiM_STM_f_Eval_pdcRL_Mas_v(void); /* Maserati */
static void aHmiM_STM_f_Eval_pdcRR_Mas_v(void); /* Maserati */
static void aHmiM_STM_f_Eval_pdcFL_Chr_v(void); /* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcFC_Chr_v(void); /* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcFR_Chr_v(void); /* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRL_Chr_v(void); /* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRC_Chr_v(void); /* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRR_Chr_v(void); /* Chrysler & MagnaJeep */

static void aHmiM_STM_f_EvaluateFrontTopTrajectories_v(void);  /* Evaluate the Trajectories for the Top and Front View */
static void aHmiM_STM_f_EvaluateRearTopTrajectories_v(void);   /* Evaluate the Trajectories for the Rear and Front View */
static void aHmiM_STM_f_EvaluateRVCNormalTrajectories_v(void); /* Evaluate the Trajectories for the RVC Only Normal View */
static void aHmiM_STM_f_EvaluateFFCVTrajectories_v(void);      /* Evaluate the Trajectories for FFC View */

static BOOL aHmiM_STM_f_EvaluateReq3103728_v(void);

static void aHmiM_STM_f_RequestControlHandling_v(void);
static void aHmiM_STM_f_UpdateVehicleType_v(void);
static void aHmiM_STM_f_CameraBlanking_v(void);

static void aHmiM_STM_f_Evaluate_HMIView_DisplayView_v(void);

static void aHmiM_STM_f_HandleAuxOverlay_v(void);

static void aHmiM_STM_f_EvaluateMoreCamsOverlay_v(void); /*�More Cams� Soft Button Overlay State Machine S02 added in the �Top + Rear� View*/

static void aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v(void); /* SRD 224741 (req id: 226454) */

static float32 aHmiM_STF_F_ValueCapping_f(float32 value, float32 uppercap, float32 lowercap);
static void EvaluateBottomBarButtons(void);
static void aHmiM_STF_F_EvaluateJackKnifeOverlays_v(void);
static void aHmiM_AutoPark_Debug(void);
static void aHmiM_TRSC_Debug(void);
static void CheckTRGLatch(void);
/* ######################################################################################################
 * --- local functions ---
 * ###################################################################################################### */

static void aHmiM_STM_f_Entry_NotInit_v(void)
{
  /* DD-ID: {A73B10F2-7F71-411d-B04A-CD2C3D6022FE}*/
  return;
}
static void aHmiM_STM_f_Entry_Init_v(void)
{
  /* DD-ID: {C0AEDC1E-85B6-4081-9245-1E4DEF7AB713}*/
  Std_E_ReturnType_t eRet;

  /* Set back the Requested Mode */
  aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;

  /* Do all Initializations here */
  aHmiM_STM_v_SystemState_e = SystemONVideoOFF;

  aHmiM_STM_v_InitialRun_b = TRUE;
  aHmiM_STM_v_ReleaseWaitForScreenCnt_u32 = aHmiM_STM_v_ScreenRequestTimeout_u32;

  /* initially set to 0 to prevent structure garbage */
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s, 0x00, sizeof(aZynqM_S_ScreenType_t));
  (void)memset(&aHmiM_STM_v_CurrentScreenOnZynqM_s, 0x00, sizeof(aZynqM_S_ScreenType_t));
  (void)memset(&aHmiM_STM_v_gooseneck_s, 0x00, sizeof(aHmiM_STM_v_gooseneck_s));
  aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
  aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
  aHmiM_STM_v_LastRequestedView_e = ME_Hydra2defs_OEM_E_NoView;
  aHmiM_STM_v_LastScreenOnZynqM_s = ME_Hydra2defs_OEM_E_NoView;
  aHmiM_STM_v_LastScreenBeforeTHA_e = ME_Hydra2defs_OEM_E_NoView;

  aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NoView;
  aHmiM_STM_v_CurrentScreenOnZynqM_s.view = ME_Hydra2defs_OEM_E_NoView;

  aHmiM_STM_v_M_TRA_View = FALSE;
  aHmiM_STM_v_MoreCamOfFullScreenFrameExpected_b = FALSE;

  HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF; /* Init value = 0 -> ImageShown */
  Tx_HmiView = DisplayView3_ViewOFF;

  /*enable AuxCam Tx Signal*/
  HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_OFF;
  HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;

  /* Set all Triggers to False */
  aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.GearToNeutral_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRun_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.REAR_TOP_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.REAR_CROSS_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.FRONT_CROSS_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.FRONT_TOP_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.X_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.MAGNIFIER_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.SFTBTN_ZOUT_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView4_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView5_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TRGLEFT_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TRGRIGHT_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.RoutineMsgRcvChanged_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRunToRun_b = FALSE;

  aHmiM_STM_v_ViewTriggerSetList_s.TrscToStandBy_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToCalibrating_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToPreActive_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToActive_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrscWasActive_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToSNA_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.TrailerWirelessCam_b = FALSE;
  /* Req 515905*/
  aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToNeutral_b = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToReverse_b = FALSE;

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_6_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_7_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_8_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_9_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_10_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_11_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_14_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontTop_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearCross_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontCross_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpdDispStat_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAM_DISP_STAT_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_22_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpd_TRGPanning_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_FrontTop_FrontCross_RearCross_Views_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_RearTop_RearCross_FrontCross_Views_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TRG_Views_b = FALSE;

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NotReverse_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b = FALSE;

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NOT_DRIVE_AND_NOT_VIEW1234_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_DRIVE_AND_NOT_VIEW1234_b = FALSE;

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpeedHigherVideoOFFSpeed_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NotDispTrailerOrWirelessCamera_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_SVCSuperState_b = FALSE;

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscStandBy_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscCalibrate_b = FALSE;
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b = FALSE;

/* Setting THA Related variables default values*/
  aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status             = FALSE;
  aHmiM_STM_v_ViewTriggerSetList_s.THA_Active_to_NotActive       = FALSE;

  M_Current_THA_State_Received                         = THA_Default;
  M_Current_THA_State_On_Zync                          = THA_Default;
  M_Current_THA_State_On_Screen                        = THA_Default;
  M_Requested_THA_State                                = THA_Default;
  last_M_Current_THA_State_Received                    = THA_Default;
  aHmiM_STM_v_M_View_Before_THA_Active_e               = ME_Hydra2defs_OEM_E_NoView;
                   
  M_Cplr_Htch_Distance                                 = 0u;
  M_THA_Abort_Req_b                                    = FALSE;
  M_Is_Valid_Tch_Zone                                  = FALSE;
  M_THA_View_Zoom_Or_Not                               = FALSE;
  
  SvsToTHA_e.MeSVS_b_THASftBtnPrsdStsToTHA             = FALSE;
  SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd                  = FALSE;
  SvsToTHA_e.MeSVS_b_ImgDefeatReqSts                   = FALSE;
  SvsToTHA_e.MeSVS_b_ViewZoomSts                       = FALSE;
  SvsToTHA_e.MeSVS_b_THAMnvrStartBtnPrsd               = FALSE;
  SvsToTHA_e.MeSVS_b_THAScrTchSts                      = FALSE;
  SvsToTHA_e.MeSVS_b_THAAbortReq                       = FALSE;
  SvsToTHA_e.MeSVS_e_THAScrResp                        = THA_Default;
  SvsToTHADet_e.MeSVS_px_THACplrPosX                   = 0u;
  SvsToTHADet_e.MeSVS_px_THACplrPosY                   = 0u;
  screenReq.MeSVS_e_THAScreenRequesttoA72              = THA_Default;
  screenReq.MeSVS_px_ScrnTchX                          = 0u;
  screenReq.MeSVS_px_ScrnTchY                          = 0u;
  screenReq.MeSVS_pct_ProgressBar                      = 0u;
  screenReq.MeSVS_px_CplrPosX                          = 0u;
  screenReq.MeSVS_px_CplrPosY                          = 0u;

  aHmiM_STM_v_VIEW_ZOOM_STS_b                          = FALSE;
  aHmiM_STM_v_VIEW_SCRN_TCH_STS_b                      = FALSE;
  aHmiM_STM_v_CONFIRM_BTN_PRESSED_b                    = FALSE;
  aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b                  = FALSE;
  aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b                  = FALSE;
  aHmiM_STM_v_START_BTN_PRESSED_b                      = FALSE;
  aHmiM_STM_v_THA_SFT_BTN_PRESSED_b                    = FALSE;
  aHmiM_STM_v_THA_X_BTN_PRESSED_b                      = FALSE;
  aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b               = FALSE;
 
  aHmiM_STM_v_CPLR_POS_X_u                             = 0u;
  aHmiM_STM_v_CPLR_POS_Y_u                             = 0u;
  aHmiM_STM_v_SCRN_TCH_X_u                             = 0u;
  aHmiM_STM_v_SCRN_TCH_Y_u                             = 0u;
  aHmiM_STM_v_CPLR_POS_X_THA_u                         = 0u;
  aHmiM_STM_v_CPLR_POS_Y_THA_u                         = 0u;
  
/************************************************/

  aHmiM_STM_v_Video_On_Speed_f32 = HMI_XCP_VIDEO_ON_SPEED;    /*Defect 378582 Fix, Changing variable u8 to float f32*/
  aHmiM_STM_v_Video_Off_Speed_f32 = HMI_XCP_VIDEO_OFF_SPEED;  /*Defect 378582 Fix, Changing variable u8 to float f32*/
  /* aHmiM_STM_v_K_TDelayPRND_u64    = HMI_XCP_K_TDELAYPRND;*/ /*Fix for defect 729785: Variable is Initialized at the place declaration itself.*/

  aHmiM_STM_v_VehicleType_e = aHmiM_STM_E_VehType_Undefined;

  aHmiM_STM_v_REAR_TOP_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_FRONT_TOP_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_REAR_CROSS_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_FRONT_CROSS_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_X_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_FFCV_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_RVCONLY_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_ZOOM_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b = FALSE;
  aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b = FALSE;
  TRG_Stat = TRG_INACTIVE;
  Last_TRG_Stat = TRG_INACTIVE;

  return;
}
static void aHmiM_STM_f_Entry_CheckInactiveMode_v(void)
{
  /* DD-ID: {83F658C6-CB26-4d6c-96A5-A731939DA68C}*/
  return;
}
static void aHmiM_STM_f_Entry_CheckView_v(void)
{
  /* DD-ID: {A1FFE14D-987D-4f19-A126-D2278834EC1B}*/
  /*If SVS featured disabled FID is set do not process this state*/
  if(TRUE==vDisableSVS)
  {
    return; 
  }
  else
  {
  // PDC_Blinking();
  // Added to assist BSW in debugging
  #ifdef PROXI_DEBUG
    appLogPrintf("Proxi: %d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n"
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VariantID
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_VehLineCfg
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_Wheelbase
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_SteerRatRackPinionType
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_PAMTunSet
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_AutonomyLvl
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CanNode27
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRGPresence
    , aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRSCPresence
    );
  #endif

  /* Check all View Triggers */
  aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b = aHmiM_STM_f_CheckViewTrigger_GearToReversed_b();                           /* Trigger 1 - M_ReversedGear0->1 + K_TDelayPRND */
  aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b = aHmiM_STM_f_CheckViewTrigger_PRNDStatSNAorUndef_b();                   /* Trigger 3 - Rx_PRND_STAT -> 0x7 (SNA) || 0x3 || 0x6 */
  aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b = aHmiM_STM_f_CheckViewTrigger_GearToPark_b();                                   /* Trigger 4 - Rx_PRND -> 0x00(P) + K_TDelayPRND */
  aHmiM_STM_v_ViewTriggerSetList_s.GearToNeutral_b = aHmiM_STM_f_CheckViewTrigger_GearToNeutral_b();                             /* Trigger 5 - Rx_PRND -> 0x02(N) + K_TDelayPRND */
  aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b = aHmiM_STM_f_CheckViewTrigger_GearToDrive_b();                                 /* Trigger 6 - Rx_PRND -> 0x04(D) + K_TDelayPRND */
  aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b = aHmiM_STM_f_CheckViewTrigger_NotDispRearCam_b();                           /* Trigger 7 - Rx_TGW_DISP != 0x07 (DISP_REAR_CAMERA) */
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b = aHmiM_STM_f_CheckViewTrigger_VehSpeedLowerVideoONSpeed_b();     /* Trigger 8 - Rx_VEH_SPEED < K_VideoON_Speed */
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRun_b = aHmiM_STM_f_CheckViewTrigger_IgnitionNotRun_b();                           /* Trigger 9 - Rx_CmdIgn =< 0x4 (ACC) */
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b = aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherVideoOFFSpeed_b(); /* Trigger 10 - Rx_VEH_SPEED > K_VideoOFF_Speed */
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b = aHmiM_STM_f_CheckViewTrigger_VehSpeedSignalNA_b();                       /* Trigger 11 - Rx_VEH_SPEED = 0xFFFF (SNA) */
  aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b = aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherRVCResetSpeed_b(); /* Trigger 14 - Rx_VEH_SPEED >= 8 mph */
  aHmiM_STM_v_ViewTriggerSetList_s.REAR_TOP_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_REAR_TOP_BTN_PRESSED_b();               /* Trigger 15 - Was the RearTopButton Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.REAR_CROSS_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_REAR_CROSS_BTN_PRESSED_b();           /* Trigger 16 - Was the RearCrossButton Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.FRONT_CROSS_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_FRONT_CROSS_BTN_PRESSED_b();         /* Trigger 17 - Was the FrontCrossButton Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.FRONT_TOP_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_FRONT_TOP_BTN_PRESSED_b();             /* Trigger 18 - Was the FrontTopButton Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.X_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_X_BTN_PRESSED_b();                             /* Trigger 19 - Was the X-Button Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.FFCV_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_FFCV_BTN_PRESSED_b();                       /* Trigger  -   Was the FFCV-Button Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_RVC_BTN_PRESSED_b();                         /* Trigger 20 - Was the RVC-Button Pressed? In D2DJ BURV,CHMSL or CHMSL_TRG */
  aHmiM_STM_v_ViewTriggerSetList_s.MAGNIFIER_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_MAGNIFIER_BTN_PRESSED_b();             /* Trigger 21 - Was the Magnifier-Button Pressed? */
/*TBD - VDW - Below_code needs to revisit once MY22 DT application requirements updated
for removed signals. Currently disabled code to avoid build errors due to removed signals. */
  aHmiM_STM_v_ViewTriggerSetList_s.SFTBTN_SVC_AUX_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_SFTBTN_SVC_AUX_PRESSED_b();      /* Trigger 22 - Was the SVC AUX-Button Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.SFTBTN_ZOUT_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_SFTBTN_ZOUT_PRESSED_b(); /* Trigger 24 - Was the ZOUT-Button Pressed? */
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView1_b();         /* Trigger 12 - Rx_Radio_A1.CameraDisplaySts -> [View 1] */
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView2_b();         /* Trigger 13 - Rx_Radio_A1.CameraDisplaySts -> [View 2] */
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView3_b();         /* Trigger 28 - Camera Display Status = View3 */
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView5_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView5_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView6_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView7_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView8_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView9_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView11_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView12_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView13_b();
  aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b = aHmiM_STM_f_CheckViewTrigger_CamDispStsView14_b();
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b = aHmiM_STM_f_CheckViewTrigger_IgnitionRun_b();
  aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRunToRun_b = aHmiM_STM_f_CheckViewTrigger_IgnitionNotRunToRun_b();
  aHmiM_STM_v_ViewTriggerSetList_s.NotDispTrailerOrWirlessCamera_b = aHmiM_STM_f_CheckViewTrigger_NotDispTrailerOrWirelessCamera_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b = aHmiM_STM_f_CheckViewGuard_GUARD_BURV_MemoryZoom_b(); /* Guard 24 - Responsible for Trigger - BURV_MemoryZoom */
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToStandBy_b = aHmiM_STM_f_CheckViewTrigger_TrscToStandBy_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToCalibrating_b = aHmiM_STM_f_CheckViewTrigger_TrscToCalibrating_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToPreActive_b = aHmiM_STM_f_CheckViewTrigger_TrscToPreAactive_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToActive_b = aHmiM_STM_f_CheckViewTrigger_TrscToActive_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrscWasActive_b = aHmiM_STM_f_CheckViewTrigger_TrscWasActive_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrscToSNA_b = aHmiM_STM_f_CheckViewTrigger_TrscToSNA_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TrailerWirelessCam_b = aHmiM_STM_f_CheckViewTrigger_TrailerWirelessCam_b();
  aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToNeutral_b = aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoNeutral_b();
  aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToReverse_b = aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoReverse_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TRGLEFT_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGLEFT_PRESSED_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TRGRIGHT_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGRIGHT_PRESSED_b();
  aHmiM_STM_v_ViewTriggerSetList_s.TRGAUTO_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGAUTO_PRESSED_b();
  aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent = aHmiM_STM_f_CheckViewTrigger_isSVSEnabled_b();
  aHmiM_STM_v_ViewTriggerSetList_s.isOneCamPresent = aHmiM_STM_f_CheckViewTrigger_isSVSDisabled_b();
  aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent = aHmiM_STM_f_CheckViewTrigger_isTHAPresent_b();

  //on softbutton press this function reset zoom memory refer defect 20615084
  Reset_BackupZoomViewMemory();
  aHmiM_STM_v_Last_TRSC_STAT_t = aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e;

  /* Check All View Guards */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b = aHmiM_STM_f_CheckViewGuard_GUARD_5_b();                                    /* Guard 5 - Responsible for Trigger 8 & 11 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_6_b = aHmiM_STM_f_CheckViewGuard_GUARD_6_b();                                    /* Guard 6 - Responsible for Trigger 3 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_7_b = aHmiM_STM_f_CheckViewGuard_GUARD_7_b();                                    /* Guard 7 - Responsible for Trigger 5 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_8_b = aHmiM_STM_f_CheckViewGuard_GUARD_8_b();                                    /* Guard 8 - Responsible for Trigger 4 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_9_b = aHmiM_STM_f_CheckViewGuard_GUARD_9_b();                                    /* Guard 9 - Responsible for Trigger 7 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_10_b = aHmiM_STM_f_CheckViewGuard_GUARD_10_b();                                  /* Guard 10 - Responsible for Trigger 8 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_11_b = aHmiM_STM_f_CheckViewGuard_GUARD_11_b();                                  /* Guard 11 - Responsible for Trigger 7 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b = aHmiM_STM_f_CheckViewGuard_GUARD_13_b();                                  /* Guard 13 - Responsible for Trigger 10 */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_14_b = aHmiM_STM_f_CheckViewGuard_GUARD_14_b();                                  /* Guard 14 - Responsible for Trigger 3 */
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_b();              /* Guard 15 - Responsible for Trigger 19 - M_SVC_View = Rear+Top */
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontTop_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_b();            /* Guard 16 - Responsible for Trigger 19 - M_SVC_View = Front+Top */
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearCross_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearCross_b();          /* Guard 17 - Responsible for Trigger 19 - M_SVC_View = RearCross */
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontCross_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontCross_b();        /* Guard 18 - Responsible for Trigger 19 - M_SVC_View = FrontCross */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b = aHmiM_STM_f_CheckViewGuard_GUARD_19_b();                                  /* Guard 19 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT != 0x4 (D) */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b = aHmiM_STM_f_CheckViewGuard_GUARD_20_b();                                  /* Guard 20 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT = 0x4 (D) */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN = aHmiM_STM_f_CheckViewGuard_GUARD_IGN_RUN_b();                          /* Guard 21 - Responsible for Trigger - Rx_IGN => 0x04 (IGN_Run) */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b = aHmiM_STM_f_CheckViewGuard_GUARD_BURV_MemoryZoom_b();        /* Guard 24 - Responsible for Trigger - BURV_MemoryZoom */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpdDispStat_b = aHmiM_STM_f_CheckViewGuard_GUARD_VehSpdDispStat_b();          /* Guard 25 - Responsible for Trigger - Vehicle.Speed =< 8mph &&  Rx_TGW_CAMERA_DISP_STAT = (0x4) */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAM_DISP_STAT_b = aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_b(); /* Guard 27 - Responsible for Trigger - Rx_TGW_CAMERA_DISP_STAT = (0x4) */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_22_b = aHmiM_STM_f_CheckViewGuard_GUARD_22_b();                                  /* Guard 28 - Responsible for Trigger - {(914 =< Rx_TCH_X_COORD < 1010) && (651 =< Rx_TCH_Y_COORD <747)} */
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b = aHmiM_STM_f_CheckViewGuard_GUARD_Trlr_Rev_Guidance_Prsnt_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpd_TRGPanning_b = aHmiM_STM_f_CheckViewGuard_TRGPanning_VehSpdInRng_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_RCV_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_FrontTop_FrontCross_RearCross_Views_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_FrontCross_RearCross_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_RearTop_RearCross_FrontCross_Views_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_RearCross_FrontCross_b();

  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_BUNRV_BUZRV_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_RCV_b();
  aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b = aHmiM_STM_f_CheckViewGuard_M_SVC_View_TRA_b();

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NotReverse_b = aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b = aHmiM_STM_f_CheckViewGuard_OFFRoadPresent_b();
/*TBD - VDW - Below_code needs to revisit once MY22 DT application requirements updated
for removed signals. Currently disabled code to avoid build errors due to removed signals. */
#if 0 
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_AUX_Connected_b            = aHmiM_STM_f_CheckViewGuard_Aux_Connected_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_AUX_Views_b                = aHmiM_STM_f_CheckViewGuard_Aux_Views_b();
#endif
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_FFC_View_b = aHmiM_STM_f_CheckViewGuard_FFC_View_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TRG_Views_b = aHmiM_STM_f_CheckViewGuard_DisplayView3_TRG_View_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NOT_DRIVE_AND_NOT_VIEW1234_b = aHmiM_STM_f_CheckViewGuard_NotDrive_And_Not_View1234_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_DRIVE_AND_NOT_VIEW1234_b = aHmiM_STM_f_CheckViewGuard_Drive_And_Not_View1234_b();

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b = aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpeedHigherVideoOFFSpeed_b = aHmiM_STM_f_CheckViewGuard_VehSpeedHigherVideoOFFSpeed_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_NotDispTrailerOrWirelessCamera_b = aHmiM_STM_f_CheckViewGuard_NotDispTrailerOrWirelessCamera_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_SVCSuperState_b = aHmiM_STM_f_CheckViewGuard_SVCSuperState_b();

  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b = aHmiM_STM_f_CheckViewGuard_GUARD_TrscPreActive_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b = aHmiM_STM_f_CheckViewGuard_GUARD_TrscActive_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscStandBy_b = aHmiM_STM_f_CheckViewGuard_GUARD_TrscStandBy_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscCalibrate_b = aHmiM_STM_f_CheckViewGuard_GUARD_TrscCalibrate_b();
  aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b = aHmiM_STM_f_CheckViewGuard_GUARD_TrscModulFitted_b();
  /* Update internal variable */
  M_Current_THA_State_Received = aHmiM_STM_f_Get_THA_State_u();
  aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status = aHmiM_STM_f_CheckViewGuard_GUARD_THA_Active_Status_b(); /* Check THA Active Status */
  M_Cplr_Htch_Distance = aHmiM_STM_f_Get_Coupler_Hitch_Distance_u();
  
  aHmiM_STM_v_ViewTriggerSetList_s.THA_Active_to_NotActive = aHmiM_STM_f_CheckViewTrigger_THA_Active_to_NotActive();
  if(aHmiM_STM_v_ViewTriggerSetList_s.THA_Active_to_NotActive == TRUE)
  { 
  aHmiM_STM_v_CPLR_POS_X_u                             = 0u;
  aHmiM_STM_v_CPLR_POS_Y_u                             = 0u;
  aHmiM_STM_v_SCRN_TCH_X_u                             = 0u;
  aHmiM_STM_v_SCRN_TCH_Y_u                             = 0u;
  aHmiM_STM_v_CPLR_POS_X_THA_u                         = 0u;
  aHmiM_STM_v_CPLR_POS_Y_THA_u                         = 0u;
  }
  else
  {/* Do Nothing*/}
  aHmiM_STM_f_Update_THA_Related_Output_v();

  /* Check Backing event */
  if((BACK_EVENT_END == Back_Event_Sts) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b)) /* Backing event will start only when its previous state is end and R- gear is detected */
  {
    Back_Event_Sts = BACK_EVENT_START;
    //printf("\n back eve started \n");
  }
  else if((((PRND_STAT_N == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) || (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)) && (HMI_BACKING_EVENT_OFF_SPEED < aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) && (BACK_EVENT_END != Back_Event_Sts)) /* If backing event is active then it will off only when if gear is in D or N and vehicle speed is above backing speed limit(8mp or 12kmph) */
  {
    Back_Event_Sts = BACK_EVENT_END;
    Last_TRG_Screen_Before_First_R_gear = ME_Hydra2defs_OEM_E_NoView;
    //printf("\n back eve ended \n");
    //printf("\n park trig=%d --- guard Sts=%d --- TGW Sts=%d\n ", aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b, aHmiM_STM_v_ViewGuardSetList_s.GUARD_11_b, aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e );
  }
  else
  {
    /* NOP */
  }
  CheckTRGLatch();
  if(prev_TRG_Latched != TRG_Latched)
  {
    prev_TRG_Latched = TRG_Latched;
    // appLogPrintf("TRG_Latched: %d",TRG_Latched);
  }
  /* Req 515905 , 526963 */
  aHmiM_STM_update_M_DNDGear_b();
  /* Check if we are in the initial Run - If so we have to decide which view we display depending on gear position */

  // testPatternBasic();

  SigMgr_Data_DiagToSVS_t_Get(&DiagToSVS_e);
  //appLogPrintf("HMI::Size of is: %d", (int)sizeof(DiagToSVS_t));
  if (0 != memcmp(&Prev_DiagToSVS_e, &DiagToSVS_e, sizeof(DiagToSVS_t)))
  {
    // appLogPrintf("isRoutineStarted: %d, Routine_ID: %d, Camera_ID: %d, TestPattern_ID: %d \n",DiagToSVS_e.isRoutineStarted, DiagToSVS_e.Routine_ID, DiagToSVS_e.Camera_ID, DiagToSVS_e.TestPattern_ID);
    memcpy(&Prev_DiagToSVS_e, &DiagToSVS_e, sizeof(DiagToSVS_t));
  }
 
  //when this fuction is called them TestPatternPending_b is set to TRUE
  aHmiM_STM_v_ViewTriggerSetList_s.RoutineMsgRcvChanged_b = aHmiM_STM_f_CheckViewTrigger_IsDiagRoutineMsgRcvChanged_b();


  SigMgr_Data_TbSVS_e_SVSCalibSMToHmi_t_Get(&TSC_to_HMI);
  // TSC_to_HMI.IsHmiActive_b = aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftFrontAJAR_e;
  // TSC_to_HMI.IsScRequestedByDiag_b = aHmiM_STM_v_Rx_HmiMRelatedData_e.RightFrontAJAR_e;

  // if(prev_TSC_Pending_b != TSC_Pending_b)
  // {
  //   appLogPrintf("0th %d",TSC_Pending_b);
  //   prev_TSC_Pending_b = TSC_Pending_b;
  // }

  if (memcmp(&prev_TSC_to_HMI,&TSC_to_HMI, sizeof(TSC_to_HMI)))
  {
    //appLogPrintf("HMIactive %d :: SCReq %d", TSC_to_HMI.IsHmiActive_b, TSC_to_HMI.IsScRequestedByDiag_b);
    memcpy(&prev_TSC_to_HMI,&TSC_to_HMI, sizeof(TSC_to_HMI));
  }

  if((FALSE == TSC_to_HMI.IsHmiActive_b) && (TRUE == TSC_to_HMI.IsScRequestedByDiag_b))
  {
    if((FALSE == TSC_Pending_b) && (ME_Hydra2defs_OEM_E_TSC_Aiming != aHmiM_STM_v_CurrentScreenOnZynqM_s.view))
    {  
      LastViewBeforeTSC_e = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
      TSC_Pending_b = TRUE;
      // if(prev_TSC_Pending_b != TSC_Pending_b)
      // {
      //   appLogPrintf("1st %d",TSC_Pending_b);
      //   prev_TSC_Pending_b = TSC_Pending_b;
      // }
    }
    aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TSC_Aiming;
  }
  else if ((TRUE == TSC_to_HMI.IsHmiActive_b) && (FALSE == TSC_to_HMI.IsScRequestedByDiag_b) && (TRUE == TSC_Pending_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.view = LastViewBeforeTSC_e;
    TSC_Pending_b = FALSE;
      // if(prev_TSC_Pending_b != TSC_Pending_b)
      // {
      //   appLogPrintf("2nd %d",TSC_Pending_b);
      //   prev_TSC_Pending_b = TSC_Pending_b;
      // }
  }
  else if(TRUE == TSC_Pending_b)
  {
    /*Wait as maybe TSC is not completed*/
  }
  //TestPatternPending_b is set to FALSE only when RequestedView from Test Pattern becomes CurrentView.
  else if ((aHmiM_STM_v_ViewTriggerSetList_s.RoutineMsgRcvChanged_b == TRUE || TestPatternPending_b == TRUE) && (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
  {
    //appLogPrintf("routine running! \n");
    static ME_Hydra2defs_E_ViewType_t lastTestPAtternReq = ME_Hydra2defs_OEM_E_NoView;
    if(aHmiM_STM_v_ViewTriggerSetList_s.RoutineMsgRcvChanged_b == TRUE)
    {
        testPattern();
        lastTestPAtternReq=aHmiM_STM_v_RequestedScreenByHmiM_s.view;

    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = lastTestPAtternReq; 
    }

    if(aHmiM_STM_v_RequestedScreenByHmiM_s.view == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    { /* We have already displayed the Requested View - don't request again */
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested;
      TestPatternPending_b = FALSE;
    }
    if(memcmp(&Prev_SVSToDiag_e, &SVSToDiag_e , sizeof(SVSToDiag_t))!=0)
    {
      SigMgr_PpSVSToDiag_SVSToDiag_t_Put(&SVSToDiag_e);
      memcpy(&Prev_SVSToDiag_e, &SVSToDiag_e , sizeof(SVSToDiag_t));
    }
    //printf("\n CHK_VIEW: time:%llu Line:%d SigMgr_PpSVSToDiag_SVSToDiag_t_Put", TimerP_getTimeInUsecs(), __LINE__);
  }
  else if (TRUE == aHmiM_STM_v_InitialRun_b)
  {
    /* Make a View decision on startup */

    if (((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e)) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontTopView;

      /* Req ID 3102116 3238634 3238642 */
      if ((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b))
      {
        aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
      }
      /* end of Req ID 3102116 3238634 3238642 */
    }
    else
    {
      if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
      }
      else
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
      }

      /* Req ID 3102116 3238634 3238642 */
      if ((PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b))
      {
        aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
      }
      /* end of Req ID 3102116 3238634 3238642 */
    }
    /*Set aHmiM_STM_v_InitialRun_b to FALSE in aHmiM_STM_f_Entry_CheckOvl_v*/
  }
  else
  {
    /* Dispatch View */
    switch (aHmiM_STM_v_SystemState_e)
    {
    case SystemONVideoOFF:
      if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (!((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))) /*Transition T 0:11  Req ID 444716*/
      {
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRV;
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
        }
        
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*Transition T 0:22.1 Req ID: 444719*/
      {                                                                                                                                  /*S0:S22.1  TRG3 LeftCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRGLeftCurbView;
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*Transition T 0:22.2 Req ID: 444697 */
      {                                                                                                                                  /*S0:S22.2  TRG5 RightCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRGRightCurbView;
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (3u == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*Transition T 0:22.1 Req ID: 444719*/
      {                                                                                                                                  /*S0:S22.1  TRG3 LeftCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BlindLeft;
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (3u == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*Transition T 0:22.2 Req ID: 444697 */
      {                                                                                                                                  /*S0:S22.2  TRG5 RightCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BlindRight;
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)) /* Transition T 0:3 Req ID. 526980 */
      {
        /*S0:S3 Rear Cross Path View */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearCrossPathView;
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /* Transition T 0:4 A Req ID. 526982 */
      {
        /*S0:S4 A Front Cross Path View */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontCrossPathView;
      }
      else if ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView5_b) && (aHmiM_STM_v_M_SVC_View_e != ME_Hydra2defs_OEM_E_TRG_L50_R50) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*SRS Req. - 290691*/
      {
        /* Transition to S22 - TRGV5050 */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L50_R50;
        if (Last_TRG_Stat == TRG_INACTIVE)
        {
          TRG_Stat = TRG_AUTO_PAN;
          Last_TRG_Stat = TRG_AUTO_PAN;
        }
        else if (Last_TRG_Stat == TRG_AUTO_PAN || Last_TRG_Stat == TRG_MANU_PAN)
        {
          TRG_Stat = Last_TRG_Stat;
        }
        else
        {
          // Do nothing
        }
      }
      else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)) /*Transition�T 0:30 Req ID 527146 */
      {                                                                                                                                                                                                                                                                                                                                                     /* FFC view */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontFacingCameraView;
      }
      /* We are in S0 - Possible View Transitions are to S5 & S2 */
      else if ((((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b))) /* Transition T 0:5 B Req ID 444699 */ /* Transition T 0:5 A Req ID 444713  */
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRunToRun_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_6_b))                                                                                                              /* Transition T 0:5 C Req ID 444704 */
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b)                                                                                                                                                                             /* Transition T 0:5 C Req ID 444704 */
              && (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b))                                                                                                            /*Transition T 0:5 D Req ID: 527116*/
                  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b)))))                                                                                                                                                           /*Transition T 0:5 E Req ID: 526984*/
      {
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent) /*20683917 defect fix*/
        {
          /* Transition to S5 - FTV */
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontTopView;

          /* Req ID 3102116 3238634 3238642 */
          if ((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b))
          {
            aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
          }
          /* end of Req ID 3102116 3238634 3238642 */
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
        }
      }
      else if (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) &&
               (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))             /* Transition 0:2 F  Req ID: 527114*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b))) /* Transition 0:2 G  Req ID: 527192 ; Defect Fix : 685432 (View should not transit to RVTV if TRA view is currently ACTIVE */
      ) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
      }

      else if (((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_8_b) && ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b)               /* Transition T 0:2 A Req ID 444720 */
                                                                       || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b) /* Transition T 0:2 B Req ID 444712 */
                                                                       || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b))))      /* Transition T 0:2 E Req ID 499530 */
               || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_7_b)))       /* Transition T 0:2 D Req ID 444710 */
      {
        /* Transition to S2 - RTV */
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
        }

        /* Req ID 3102116 3238634 3238642 */
        if ((PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b))
        {
          aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        }
        /* end of Req ID 3102116 3238634 3238642 */

        /* If T1 was the switch condition, then set CANTx_SVC_Image_Defeat = 0 */ /* Req ID 3102739 */
        if (TRUE == aHmiM_STM_v_GearReverse_Delayed_b)
        {
          HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
        }
        else
        { /*do nothing*/
        }
      }
      else
      {
        /* No View Transition */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested;
      }
      break;
      //!!!!!!!!!!!!!!!!!!
    case SystemONVideoON:
      /* We are in S1 - Possible View Transition are to S0, S1-{S2, S3, S4, S5}, RVC_FullFrame */
      if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b))
      { /* Task 4077845 */
        aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        aHmiM_STM_f_Update_MCUDebug0_v();
      }
      else
      { /*Do nothing */
      }
      
      //appLogPrintf("Spd: %.2f, Str: %.2f \n",aHmiM_STM_v_Rx_HmiMRelatedData_e.steeringWheelAngle_f32, aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32);

      if (   (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionNotRun_b)                                                                                                                                                                                                                                              
          || ((CameraDisplaySts2_OFF == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e) && (FALSE == aHmiM_STM_v_IgnoreVehicleOffSpeed) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_NotReverse_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b))                                                                                                                                                                                                                         
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))) 
         )

      {
        // appLogPrintf("\nCmdIgn: %u HMI will go in sleep\n",aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e);
        /* Transition to S0 - SystemOnVideoOFF */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NoView;
        aHmiM_STM_v_IgnoreVehicleOffSpeed = TRUE;
        aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
      }

      /*FZ: Here section to detect THA active is skipped as AP has higher pririty than THA*/
      /*Above inputs were recieved by AutoPark Team*/
      else if(  (TRUE                 ==  aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
              &&(IGN_RUN              ==  aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)     
              &&(TeAP_e_HMIPopUp_SHIFT_TO_DRIVE <=   aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP) 
              &&(TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT  >=   aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
              &&(FALSE == AP_CameraHandshake_Initiated)
            )
      {
        if(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP != aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP)
        {
          aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP = aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP;
          HMI_to_AP.HMI_ButtonPressed = NONE_PRESSED;

          if(TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
          {
            HMI_to_AP.SelectedManeuverSlotType  = ParkingSlotType_E_PW_NODIR;
            HMI_to_AP.SelectedManeuverSlotSide  = SlotSide_E_SLOT_NULL;
            HMI_to_FPA.m_selectedslotID         = ParkingSlotID_E_NONE;
            HMI_to_AP.SelectedSlotId            = HMI_to_FPA.m_selectedslotID;
          }

          if ( 
               (FALSE)
            || (TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_LEFT == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_RIGHT == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
            || (TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
          )
          {
            HMI_to_AP.SelectedManeuverType = TYPE_NONE;
            HMI_to_FPA.VehicleParkDirection = ParkINStyle_E_CAR_IN_NULL;
          }

        }
        AP_HMI_Active_Status = TRUE;
        aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status  = FALSE;   
        AP_HMI_ViewID_Decoding();
        HMI_to_VCAN.IeSVS_b_SPMScrnReq = TRUE;
      }

      else if(  (TRUE                 ==  aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
              &&(IGN_RUN              ==  aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)     
              &&
              (
                ((TeAP_e_HMIPopUp_IDLE ==  aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP != aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP))
                || (TRUE == AP_CameraHandshake_Initiated) /*IF handshake is initiated means we are about to exit this view*/
              )
      )
      {
        if((DISP_OFF == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (TRUE == AP_CameraHandshakeTimerExpired))
        {
          aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP = aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP;
          AP_HMI_Active_Status = FALSE;

          if(PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
          {
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontTopView;
          }
          else
          {
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
          }
        }
        else
        {
          if(FALSE == AP_CameraHandshake_Initiated)
          {
            AP_CameraHandshake_Initiated = TRUE;
            AP_CameraHandshake_StartTime = TimerP_getTimeInUsecs();
          }
          if(PRND_STAT_R == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) /*This section added to fulfill the requirement that in R gear ImgDefaet req should not be sent out to head unit when AP aborted */
          {
            HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
          }
          else
          {
            HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_ON;
          }
          
          HMI_to_VCAN.IeSVS_b_SPMScrnReq = FALSE;
          aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP = aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP;  
          AP_HMI_ViewID_Decoding();
        }
      }

      else if ((((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView5_b) && (aHmiM_STM_v_M_SVC_View_e != ME_Hydra2defs_OEM_E_TRG_L50_R50) && (DisplayView3_View9 != Tx_HmiView)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)&& (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*SRS Req. - 488349*/
      /*T 50:02_A (System Active ON to TRG1(main)) Req ID 499947*/
      {
        /* Transition to S22 - TRGV5050 */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L50_R50;
        if (Last_TRG_Stat == TRG_INACTIVE) //TODO: add check of trailer calibration
        {
          TRG_Stat = TRG_AUTO_PAN;
          Last_TRG_Stat = TRG_AUTO_PAN;
        }
        else if (Last_TRG_Stat == TRG_AUTO_PAN || Last_TRG_Stat == TRG_MANU_PAN)
        {
          TRG_Stat = Last_TRG_Stat;
        }
        else
        {
          // do nothing
        }
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (DisplayView3_View6 != Tx_HmiView)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /* Req ID: 445204 for S1 to S22.1*/ /* 445186 */
                                                                                                                                                                                                                                                                                                                                                                                /*Transition�T 11:22 Req ID: 445186 and Transition�T S12:22, 445644*/
      {                                                                                                                                                                                                                                                                                                                                                                         /* S22.1  TRG3 LeftCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRGLeftCurbView;
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (DisplayView3_View7 != Tx_HmiView)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*  Req ID: 445177 for S1 to S22.2*/ /* 445186 */
                                                                                                                                                                                                                                                                                                                                                                                 /*Transition�T 11:22 Req ID: 445186 and  Transition�T S12:22, 445644*/
      {                                                                                                                                                                                                                                                                                                                                                                          /* S22.2  TRG5 RightCurbView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRGRightCurbView;
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (DisplayView3_View10 != Tx_HmiView)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (3u == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /* Req ID: 445204 for S1 to S22.1*/ /* 445186 */
                                                                                                                                                                                                                                                                                                                                                                                 /*Transition�T 11:22 Req ID: 445186 and Transition�T S12:22, 445644*/
      {                                                                                                                                                                                                                                                                                                                                                                          /* S22.1   BlindLeftView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BlindLeft;
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (DisplayView3_View11 != Tx_HmiView)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (3u == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_MirrorType) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))  /*  Req ID: 445177 for S1 to S22.2*/ /* 445186 */
                                                                                                                                                                                                                                                                                                                                                                                  /*Transition�T 11:22 Req ID: 445186 and  Transition�T S12:22, 445644*/
      {                                                                                                                                                                                                                                                                                                                                                                           /* S22.2   BlindRightView */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BlindRight;
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.REAR_CROSS_BTN_PRESSED_b) /*Req. ID: 444614 */ /* aHmiM_STM_f_Is_BTN_PRESSED_b already checked for coord and disp_stat = 0x4|| 0x7 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b) && (DisplayView3_View2 != Tx_HmiView) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))) &&
               aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)) /* Transition T 1:3 B Req ID: 526988 ; Defect Fix : 685432 (View should not transit to RCPV if TRA view is currently ACTIVE*/
      {
        /* Transition to S3 - RCV */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearCrossPathView;
      }

      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b) && (aHmiM_STM_v_M_SVC_View_e != ME_Hydra2defs_OEM_E_FrontFacingCameraView) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b)) && aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)) /*Transition�T 0:30 Req ID 527146 */
      {                                                                                                                                                                                                                                                                                                                                                     /* FFC view */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontFacingCameraView;
      }

      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FRONT_CROSS_BTN_PRESSED_b) /*Req. ID: 527160 */ /* aHmiM_STM_f_Is_BTN_PRESSED_b already checked for coord and disp_stat = 0x4|| 0x7 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b) && (DisplayView3_View3 != Tx_HmiView) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))) &&
               aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))/* Transition T 1:4 B Req ID: 526990 ; Defect Fix : 685432 (View should not transit to FCPV if TRA view is currently ACTIVE*/
      {
        /* Transition to S4 - FCV */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontCrossPathView;
      }

      else if ((
          (
              (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FFCV_BTN_PRESSED_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b))                                                                                                                                           /*Req id 527232*/
               && ((DisplayView3_View8 != Tx_HmiView) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))) /*Req id 445109*/

              || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) && (M_FFClatch_Set == aHmiM_STM_v_M_FFClatch_e) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b)) /*Requirement - 529282*/

              || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToNeutral_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) && (M_FFClatch_Set == aHmiM_STM_v_M_FFClatch_e) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b)) /*Requirement - 529284*/
              ) &&
          aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))
      { /* FFC view */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontFacingCameraView;
      }

      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (!((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))))                                                                                                                                           /* Transition�T 1:11 A  Req ID:517033 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && (aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b == FALSE) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b) && ((FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b) || ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b)))) /* Req.:445314 Defect Fix -729786 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b))  
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_11_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         /*Req ID 457427*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) && (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_SVC_View_e))                                                                                                                                                                                                                                                                                                                                  /* Req.: 445330 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b) && (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_SVC_View_e))                                                                                                                                                                                                                                                                                                                                             /* Req.: 445330 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b) && ((FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b) || TRUE) && /* Req.: 445668 */ /* aHmiM_STM_f_Is_BTN_PRESSED_b already checked for coord and disp_stat = 0x4|| 0x7 */                                                                                                                                                                                                                        //! FZ TRUE OVERRIDE
                    ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontTop_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearCross_b) ||
                     (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontCross_b) || (Tx_HmiView == DisplayView3_View8)))                                                                                                                /* Req.:3102100 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.MAGNIFIER_BTN_PRESSED_b) && (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_SVC_View_e))                                                                                                               /* Req.: 445656 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b)) /*Transition�T 100:11, Req ID: 445197*/
                || ((aHmiM_STM_v_M_View_Before_THA_Active_e == ME_Hydra2defs_OEM_E_BUNRVOneCam) && (aHmiM_STM_v_ViewTriggerSetList_s.THA_Active_to_NotActive == TRUE))
                ) &&
               aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)
      {
        /* Transition to S11 - BUNRV */
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRV;
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
        }
        if (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b) /*requirement 444743 for S30 to S11*/
        {
          aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
          aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        }
        else
        {
          // do nothing
        }
        if (FALSE == aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b()) /* Req: 3248106 & 3214284 */
        {
          aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        }
        else
        {
          /* nothing */
        }

        if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedSignalNA_b)) /* Req.: 3101980 */
        {
          aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        }
        else
        {
          /* do nothing */
        }

        // if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b) /*requirement 444743 for S30 to S11*/
        // {
        //   aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
        //   aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
        // }
        // else
        // {
        //   /*do nothing*/
        // }
      }
      else if ((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.MAGNIFIER_BTN_PRESSED_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) && (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV))                                /* Req Id - 445189 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.RVC_BTN_PRESSED_b) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_BURV_MemoryZoom_b) || TRUE)) /* Req.:444854*/ /* aHmiM_STM_f_Is_BTN_PRESSED_b already checked for coord and disp_stat = 0x4|| 0x7 */ //! FZ OVERRIDE TRUE
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_BURV_Memory_e) && ((FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b) || ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b))))) &&
               aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)
      {
        /* Transition to S12 - BUZRV */
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUZRV;
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUZRVOneCam;
        }

        if (FALSE == aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b()) /* Req: 1942553 & 2487690 */
        {
          aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUZRV;
        }
        else
        {
          /* nothing */
        }
      }
      else if (((((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) && (M_DNDGear_NotSet == aHmiM_STM_v_M_DNDGear_e) && (M_FFClatch_NotSet == aHmiM_STM_v_M_FFClatch_e) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearCross_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_FrontCross_b)))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     /*Req ID 526951 ,526955, 526959*/
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_RearTop_b))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  /*Req. ID: 526949*/
          || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FRONT_TOP_BTN_PRESSED_b)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  /* Req ID 457498 Req ID 444615  */
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_9_b)) /* T7 && G9 */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  /*Req ID 457498*/
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_DRIVE_AND_NOT_VIEW1234_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b) && (DisplayView3_View4 != Tx_HmiView) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            /* Transition T 1:5 J Req ID: 526992 ; Defect Fix : 685432 (View should not transit to FVTV if TRA view is currently ACTIVE*/
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscToStandBy_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscToSNA_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscWasActive_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TRG_Views_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_FFC_View_b) || ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))) /*req id# 445120 for S22 to S5 req 444748 for S30 to S5   S10 to S5 Req Id - 445310 */
          || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       /* S10 to S5 Req Id - 445319  */
          ) &&
          aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)) 
      {
        /* Transition to S5 - FTV */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_FrontTopView;

        if (aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
        {
          if (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))) /* Req id -445310 */
              || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_20_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))))               /*Req Id - 445319  */

          {
            aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
          }
        }
      }
      else if ((   ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b /*Req 3102349*/) && (FALSE == TRG_Latched)) /* T1 */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  /*Req ID 457392 3179694 3180883 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_RCV_Views_b /*Req 3102349*/) && (TRUE == TRG_Latched) && ((BACK_EVENT_START == Back_Event_Sts ) || (BACK_EVENT_IN_PROCESS == Back_Event_Sts ))) 
                || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.REAR_TOP_BTN_PRESSED_b) /* RearTopBtn */ /*Req ID 444616*/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      /*Req ID 3102778*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_11_b)) /* T4 && G11 */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          /*Req ID 457427*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_10_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        /*Req ID 1942531 ; Defect Fix : 685432 (View should not transit to RVTV if TRA view is currently ACTIVE*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_14_b)) /* T3 && G14*/ /*Req ID 476320*/                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 /* Req ID 3102156 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscWasActive_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscToSNA_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscToStandBy_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_5_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b) && (DisplayView3_View1 != Tx_HmiView) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b)) /* Transition T 1:2 M Req ID: 526986 ; Defect Fix : 685432 (View should not transit to RVTV if TRA view is currently ACTIVE*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))                                                                                                                                                                                                                                                                                                                                                                                                                             /*S10 : 2B  Req id  445295 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_NOT_DRIVE_AND_NOT_VIEW1234_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     /*Req id 444725 */
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b))                                                                                                                                                                                                                                                                                                                                                                                                                                            /*Transition T 1:2 G  Req ID: 444725 and Transition�T 100:2 B Req ID:445223*/
				        || ((aHmiM_STM_v_M_View_Before_THA_Active_e == ME_Hydra2defs_OEM_E_RearTopView) && (aHmiM_STM_v_ViewTriggerSetList_s.THA_Active_to_NotActive == TRUE))                                                                                                                                                                                                                                                                                                                                                                                                                                            /*Transition T 1:2 G  Req ID: 444725 and Transition�T 100:2 B Req ID:445223*/
                || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TRG_Views_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_FFC_View_b) || ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))) /*Req id 555137 S22 to S2 Req id 444732 for S30 to S2*/ /* S10 to S2 Req.ID. 517039*/
                ) 
                   && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status) )
      {
        /* Transition to S2 - RTV */
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
        }
        // else if(!(((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV)))                                                                                                                                                                                                                                                                                                                                                                                                                             /*S10 : 2B  Req id  445295 */
        //         || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_NOT_DRIVE_AND_NOT_VIEW1234_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b))                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     /*Req id 444725 */
        //         || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.IgnitionRun_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.M_SVC_View_TRA_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b))                                                                                                                                                                                                                                                                                                                                                                                                                                            /*Transition T 1:2 G  Req ID: 444725 and Transition�T 100:2 B Req ID:445223*/
				//))
        else
        {
          //do nothing
        }

        if (aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
        {
          if (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.NotDispRearCam_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && (FALSE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherVideoOFFSpeed_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))) /* Req.ID. 517039*/
              || ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_IGN_RUN) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_19_b) && ((aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUNRV) || (aHmiM_STM_v_M_SVC_View_e == ME_Hydra2defs_OEM_E_BUZRV))))               /* Req.ID. 445295*/
          {
            aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
          }
        }
        if((TRUE == TRG_Latched) && (BACK_EVENT_IN_PROCESS == Back_Event_Sts ) && (ME_Hydra2defs_OEM_E_NoView != aHmiM_STM_v_LastRequestedView_e) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b))
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = aHmiM_STM_v_LastRequestedView_e;
        }
        else if((BACK_EVENT_START == Back_Event_Sts) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b))
        {
          Back_Event_Sts = BACK_EVENT_IN_PROCESS;
          if(TRUE == TRG_Latched)
          {
              Last_TRG_Screen_Before_First_R_gear = aHmiM_STM_v_LastRequestedView_e;
          }
          //printf("\n back eve in process \n");
        }
        else{/* NOP */}

      }
      // else if ((((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscModulFitted_b) && (((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscPreActive_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TrscActive_b))) /* 444740*/
      //                                                                                 || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TrscToCalibrating_b)))                                                                                                                              /* 444739*/
      //           && (DisplayView3_View7 != Tx_HmiView)                                                                                                                                                                                                    /*No transition to TRA if current view is TRG/sidecam view*/
      //           ) &&
      //          aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)
      // {
      //   aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RAW_Rear; /* this is TRA view */
      //   aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;     /* 444739 and 444740*/
      // }

      /*Transition to THA View*/
      else if (aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
      {
        // Latch the zoom status to avoid flicker
        static BOOL tha_viewZoomedAlready = FALSE;
        if (THA_SM_Msg2 == M_Current_THA_State_Received) {
          tha_viewZoomedAlready |= (M_Cplr_Htch_Distance <= THA_DELTA_THRESHOLD1);
        }
        else
        {
          tha_viewZoomedAlready = FALSE;
        }

        switch (M_Current_THA_State_Received)
        {
        case THA_TCS_Msg1:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_TCS_Msg2:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic;

          break;
        case THA_TCS_Msg3:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic;
          break;
        case THA_TCS_Msg4:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_TCS_Msg5:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_SM_Msg1:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_SM_Msg2:
          if ((FALSE == tha_viewZoomedAlready) && (M_Cplr_Htch_Distance > THA_DELTA_THRESHOLD1))
          {
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;
          }
          else
          {
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Static;
          }
          break;
        case THA_CM_Msg1:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg2:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg3:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg4:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg5:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg6:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg7:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg8:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg9:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_CM_Msg10:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_EOM_Msg1:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Static;

          break;
        case THA_EOM_Msg2:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Static;

          break;
        case THA_EOM_Msg3:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Static;

          break;
        case THA_EOM_Msg4:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Zoom_Static;

          break;
        case THA_ERR_Msg1:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        case THA_ERR_Msg2:
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_THA_Normal;

          break;
        default:
          break;
        }

        /* Store the last known non-THA view befoer starting THA */
        if(((aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_THA_Normal) 
         && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic) 
         && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_THA_Zoom_Static))
        && ((aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_THA_Normal) 
         || (aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic) 
         || (aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_THA_Zoom_Static)))
        {
          aHmiM_STM_v_LastScreenBeforeTHA_e = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
        }
      }
      /* Restore last non-THA view if THA is disabled */
      else if ((aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE) && 
        ((aHmiM_STM_v_CurrentScreenOnZynqM_s.view == ME_Hydra2defs_OEM_E_THA_Normal) 
        || (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic) 
        || (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == ME_Hydra2defs_OEM_E_THA_Zoom_Static)))
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = aHmiM_STM_v_LastScreenBeforeTHA_e;
      }
      else if (((TRG_Stat == TRG_MANU_PAN) && (DisplayView3_View9 == Tx_HmiView) && (aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))
      {
        // TRG MANUAL
        if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TRGRIGHT_BTN_PRESSED_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAM_DISP_STAT_b)&& (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpd_TRGPanning_b))
        {
          /*To understand switch case imagine we are displaying 100% left view now with each press of left button the size of right view increased, window slideing*/
          switch (aHmiM_STM_v_M_SVC_View_e)
          {
          case ME_Hydra2defs_OEM_E_TRG_L100_R0:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L75_R25;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L75_R25:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L50_R50;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L50_R50:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L25_R75;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L25_R75:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L0_R100;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L0_R100:
            /* do nothing already right 100% view*/
            break;
          default:
            break;
          }
        }

        else if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.TRGLEFT_BTN_PRESSED_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_Trlr_Rev_Guidance_Prsnt_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAM_DISP_STAT_b) && (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_VehSpd_TRGPanning_b))
        {
          switch (aHmiM_STM_v_M_SVC_View_e)
          {
          case ME_Hydra2defs_OEM_E_TRG_L0_R100:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L25_R75;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L25_R75:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L50_R50;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L50_R50:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L75_R25;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L75_R25:
            aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L100_R0;
            break;
          case ME_Hydra2defs_OEM_E_TRG_L100_R0:
            /* do nothing already left 100% view*/
            break;

          default:
            break;
          }
        }
      }

      else if (((TRG_Stat == TRG_AUTO_PAN) && (DisplayView3_View9 == Tx_HmiView) && (aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE)) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent))
      {
        // TRG AUTO
        if (aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle < -40.0f)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L100_R0;
        }
        else if (aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle < -24.0f && aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle >= -40.0f)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L75_R25;
        }
        else if (aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle <= 24.0f && aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle >= -24.0f)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L50_R50;
        }
        else if (aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle <= 40.0f && aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle > 24.0f)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L25_R75;
        }
        else if (aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle > 40.0f)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_TRG_L0_R100;
        }
        else
        {
          // do nothing
        }
      }

      else
      {
        /* No View Transition */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested;
      }

      /* TRG Latching in backing event */
      if(((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToNeutral_b))  && (ME_Hydra2defs_OEM_E_NoView != Last_TRG_Screen_Before_First_R_gear) && (BACK_EVENT_IN_PROCESS == Back_Event_Sts) && (TRUE == TRG_Latched))
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = Last_TRG_Screen_Before_First_R_gear;
        Last_TRG_Screen_Before_First_R_gear = ME_Hydra2defs_OEM_E_NoView;
        //printf("\n TRG View reengaged \n");
      }

      if((TRUE == vViewDegToRearTop) && (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status )) // Lock SVS view to RTV or BRV 
      {
        if(TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RearTopView;
        }
        else
        {
          aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRVOneCam;
        }
      }
      if (aHmiM_STM_v_RequestedScreenByHmiM_s.view == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
      { /* We have already displayed the Requested View - don't request again */
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested;
      }
      else
      { /*do nothing*/
      }
      /*Default X-Button Handling*/
      /*Req ID 500485*/
      //aHmiM_STM_f_XButtonHandlingDefault(); /* X-Button & Icon handling (ImageDefeatRqst) - (X-Icon is the only Overlay which will be handled separately here)" */

      break;
    default:
      break;
    }
  }

  if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedLowerVideoONSpeed_b) || (DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)) /*Defect 729664 Fix*/
  {
    aHmiM_STM_v_IgnoreVehicleOffSpeed = FALSE;
  }


  /* Req Id - 529288 ,529290 */
  aHmiM_STM_update_M_FFClatch_b();
 
  return;
  }
}
static void aHmiM_STM_f_Entry_CheckOvl_v(void)
{
  /* DD-ID: {404423F5-F49B-4da3-9C3A-6DF5F778A64B}*/
  if (TRUE == aHmiM_STM_v_InitialRun_b)
  {
    aHmiM_STM_v_InitialRun_b = FALSE; /* Set to FALSE */
  }
  else
  {
    SigMgr_PpScreenResponse_ScreenResponse_t_Get(&screenResponse);
    memcpy(&aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays,&screenResponse.MbSVS_bf_OverlayBitsRes,sizeof(screenResponse.MbSVS_bf_OverlayBitsRes));
    aHmiM_STM_v_CurrentScreenOnZynqM_s.view = (ME_Hydra2defs_E_ViewType_t)screenResponse.MeSVS_e_ViewEngResCode;

    if(aHmiM_STM_v_CurrentScreenOnZynqM_s.view != aHmiM_STM_v_LastScreenOnZynqM_s)
    {
      aHmiM_STM_v_LastScreenOnZynqM_s = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
      #if HMI_ESSENTIAL_DEBUG
        appLogPrintf("Displayed HMI Screen: %d", (ME_Hydra2defs_E_ViewType_t)aHmiM_STM_v_CurrentScreenOnZynqM_s.view);
      #endif

      #if HMI_PROFILING
        #if defined(GPIO_TIMING_MEASURE_ENA)
        	/*HMI Instance 5 - Reading View Response From A72*/
          GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 34, GPIO_PIN_HIGH);
        #endif
      #endif
    }

    aHmiM_STM_f_Evaluate_HMIView_DisplayView_v();
    HMI_to_VCAN.IeSVS_e_DispView2 = (aSigConverter_E_DisplayView2_t)Tx_HmiView;
    
    if(memcmp(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t))!=0)
      {
        #if HMI_ESSENTIAL_DEBUG
          appLogPrintf("CHeckOvl");
          appLogPrintf("DispView2 %d, ImgDefeat: %d, MoreCams %d, AUXCam %d, SPM %d \n"
          ,HMI_to_VCAN.IeSVS_e_DispView2
          ,HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts
          ,HMI_to_VCAN.IeSVS_b_MoreCamsReqSts
          ,HMI_to_VCAN.IeSVS_b_AUXCamReqSts
          ,HMI_to_VCAN.IeSVS_b_SPMScrnReq
          );
        #endif
		
		#if HMI_PROFILING
		if(prev_HMI_to_VCAN.IeSVS_e_DispView2 != HMI_to_VCAN.IeSVS_e_DispView2)
          {
            /*HMI Instance 6 - Sending VCAN Signal to MCU1_0*/
              if((TRUE == GearFlag2) && (DisplayView3_View4 == Tx_HmiView)) //FTV
                {
                  GearFlag = FALSE;
                  GearFlag2 = FALSE;
                  end_time = TimerP_getTimeInUsecs();
                  // appLogPrintf("TX CAN Gear Based: %llu us" ,(end_time - GearRecieved));
                  GearRecieved = 0llu;
                }
              else{/*do nothing*/}     

              if((TRUE == DisplayStsFlag2) && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == aHmiM_STM_v_LastRequestedView_e)) //RCPV
                {
                  DisplayStsFlag = FALSE;
                  DisplayStsFlag2 = FALSE;
                  end_time = TimerP_getTimeInUsecs();
                  #if defined(GPIO_TIMING_MEASURE_ENA)
                    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 34, GPIO_PIN_LOW);
                    GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 36, GPIO_PIN_HIGH);
                  #endif
                  appLogPrintf("%llu,DP,%d,P2to6,%llu",hit_counter2, aHmiM_STM_v_CurrentScreenOnZynqM_s.view, (end_time2 - DisplayStsRecieved));
                  appLogPrintf("%llu,ID,%d,P6to7,%llu",hit_counter, aHmiM_STM_v_CurrentScreenOnZynqM_s.view, (end_time - end_time2));
                  DisplayStsRecieved = 0llu;
                }
              else{/*do nothing*/}    

              if((TRUE == TouchFlag2) && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == aHmiM_STM_v_LastRequestedView_e)) //BURV
                {
                  TouchFlag = FALSE;
                  TouchFlag2 = FALSE;
                  end_time = TimerP_getTimeInUsecs();
                  // appLogPrintf("TX CAN Touch Based: %llu us" ,(end_time - TouchRecieved));
                  TouchRecieved = 0llu;
                }
              else{/*do nothing*/}     
          }
		#endif
		
        SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(&HMI_to_VCAN);
        memcpy(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t));
      }
    // if(0 == memcmp(&aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays,&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays,sizeof(aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays))
    // && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == aHmiM_STM_v_RequestedScreenByHmiM_s.view)
    // )//more checks like text enums and parkslots to be added
    // {
    //   HMI_to_AP.DisplayedPopUp = aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP;
    // }
   
    if (ME_Hydra2defs_OEM_E_NoView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
      aHmiM_STM_v_SystemState_e = SystemONVideoOFF;
    }
    else
    {
      aHmiM_STM_v_SystemState_e = SystemONVideoON;
    }
    
    if (aHmiM_STM_v_SystemState_e != aHmiM_STM_v_LastSystemState_e)
    {
      #if HMI_ESSENTIAL_DEBUG
        if(aHmiM_STM_v_SystemState_e == SystemONVideoOFF)
          appLogPrintf("HMI Video OFF");
        else if(aHmiM_STM_v_SystemState_e == SystemONVideoON)
          appLogPrintf("HMI Video ON");
      #endif  
      aHmiM_STM_v_LastSystemState_e = (ME_Hydra2defs_E_SystemState_t)aHmiM_STM_v_SystemState_e;
    }
    else
    {
      // do nothing
    }


    M_Current_THA_State_On_Screen = aHmiM_STM_f_Get_THA_State_Response_u();
    M_Requested_THA_State = aHmiM_STM_f_Get_THA_State_u();   // Get THA state from THA SM 
    aHmiM_STM_f_Request_THA_State_to_Zync_u();
    M_Current_THA_State_On_Zync = M_Requested_THA_State;
    aHmiM_STM_f_Send_THA_State_Response_u();
  }
  if (ME_Hydra2defs_OEM_E_NonViewRequested != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    /* We had a View Change */
    /* Call the Exit Function for the Currently Displayed View */
    HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
    HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;
    HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_OFF;
    if(memcmp(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t))!=0)
    {	
      SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(&HMI_to_VCAN);
      memcpy(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t));
      //printf("\n CHK_OVL_2: time:%llu Line:%d SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put", TimerP_getTimeInUsecs(), __LINE__);
    }

    switch (aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
    case ME_Hydra2defs_OEM_E_NoView:
      /* exit Function SystemONVideoOFF */
      aHmiM_STM_f_Exit_SystemONVideoOFF_v();
      break;
    case ME_Hydra2defs_OEM_E_RearTopView:
      /* exit Function Front Top View */
      aHmiM_STM_f_Exit_RearTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontTopView:
      /* exit Function Front Top View */
      aHmiM_STM_f_Exit_FrontTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_RearCrossPathView:
      /* exit Function Front Top View */
      aHmiM_STM_f_Exit_RearCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontCrossPathView:
      /* exit Function Front Top View */
      aHmiM_STM_f_Exit_FrontCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUNRV:
      /* exit Function RVC_Only Normal View */
      aHmiM_STM_f_Exit_RVCOnlyNormalView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRV:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Exit_RVCOnlyZoomView_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Normal:
      /* exit Function RVC_Only Normal View */
      aHmiM_STM_f_Exit_THANormalRearView_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Exit_THAZoomRearView1_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Static:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Exit_THAZoomRearView2_v();
      break;
    case ME_Hydra2defs_OEM_E_TRG_L50_R50:
    case ME_Hydra2defs_OEM_E_TRG_L25_R75:
    case ME_Hydra2defs_OEM_E_TRG_L75_R25:
    case ME_Hydra2defs_OEM_E_TRG_L100_R0:
    case ME_Hydra2defs_OEM_E_TRG_L0_R100:
      aHmiM_STM_f_Exit_TRG_View_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
      aHmiM_STM_f_Exit_FrontWithTiretracks_v();
      break;
      // case ME_Hydra2defs_OEM_E_RAW_Rear:
      //   aHmiM_STM_f_Exit_TRA_View_v();
      // break;
    case ME_Hydra2defs_OEM_E_TRGLeftCurbView:
      aHmiM_STM_f_Exit_TRGLeftCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRGRightCurbView:
      aHmiM_STM_f_Exit_TRGRightCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindLeft:
      aHmiM_STM_f_Exit_BlindLeft_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindRight:
      aHmiM_STM_f_Exit_BlindRight_View_v();
      break;
    case ME_Hydra2defs_OEM_E_RAW_Front:
    case ME_Hydra2defs_OEM_E_RAW_Rear:
    case ME_Hydra2defs_OEM_E_RAW_Right:
    case ME_Hydra2defs_OEM_E_RAW_Left:
    case ME_Hydra2defs_OEM_E_QuadView:
      aHmiM_STM_f_Exit_Raw_View_v();
      break;
	  case ME_Hydra2defs_OEM_E_BUNRVOneCam :
      aHmiM_STM_f_Exit_BUNRVOneCam_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRVOneCam :
      aHmiM_STM_f_Exit_BUZRVOneCam_View_v();
      break;
		/*AP HMI*/
    case ME_Hydra2defs_OEM_E_APA_FTV:
    case ME_Hydra2defs_OEM_E_APA_RTV:
    case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
    	aHmiM_STM_f_Exit_AutoPark_View_v();
    	break;
    case ME_Hydra2defs_OEM_E_TSC_Aiming:
      aHmiM_STM_f_Exit_TSC_Aiming_View_v();
      break;
    default:
      break;
    }
    EvaluateBottomBarButtons();
    aHmiM_STF_F_EvaluateJackKnifeOverlays_v();
    aHmiM_STM_f_XButtonHandlingDefault();
    /* Call the Entry Function for the Requested View */
    switch (aHmiM_STM_v_RequestedScreenByHmiM_s.view)
    {
    case ME_Hydra2defs_OEM_E_NoView:
      /* entry Function SystemONVideoOFF */
      aHmiM_STM_f_Entry_SystemONVideoOFF_v();
      break;
    case ME_Hydra2defs_OEM_E_RearTopView:
      /* entry Function Front Top View */
      aHmiM_STM_f_Entry_RearTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontTopView:
      /* entry Function Front Top View */
      aHmiM_STM_f_Entry_FrontTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_RearCrossPathView:
      /* entry Function Front Top View */
      aHmiM_STM_f_Entry_RearCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontCrossPathView:
      /* entry Function Front Top View */
      aHmiM_STM_f_Entry_FrontCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUNRV:
      /* entry Function RVC_Only Normal View */
      aHmiM_STM_f_Entry_RVCOnlyNormalView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRV:
      /* entry Function RVC_Only Zoom View */
      aHmiM_STM_f_Entry_RVCOnlyZoomView_v();
      break;
    case ME_Hydra2defs_OEM_E_TRG_L50_R50:
    case ME_Hydra2defs_OEM_E_TRG_L25_R75:
    case ME_Hydra2defs_OEM_E_TRG_L75_R25:
    case ME_Hydra2defs_OEM_E_TRG_L100_R0:
    case ME_Hydra2defs_OEM_E_TRG_L0_R100:
      aHmiM_STM_f_Entry_TRG_View_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Normal:
      /* exit Function RVC_Only Normal View */
      aHmiM_STM_f_Entry_THANormalRearView_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Entry_THAZoomRearView1_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Static:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Entry_THAZoomRearView2_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
      aHmiM_STM_f_Entry_FrontWithTiretracks_v();
      break;
      // case ME_Hydra2defs_OEM_E_RAW_Rear:
      //   aHmiM_STM_f_Entry_TRA_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRGLeftCurbView:
      aHmiM_STM_f_Entry_TRGLeftCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRGRightCurbView:
      aHmiM_STM_f_Entry_TRGRightCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindLeft:
      aHmiM_STM_f_Entry_BlindLeft_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindRight:
      aHmiM_STM_f_Entry_BlindRight_View_v();
      break;
    case ME_Hydra2defs_OEM_E_RAW_Front:
    case ME_Hydra2defs_OEM_E_RAW_Rear:
    case ME_Hydra2defs_OEM_E_RAW_Right:
    case ME_Hydra2defs_OEM_E_RAW_Left:
    case ME_Hydra2defs_OEM_E_QuadView:
      aHmiM_STM_f_Entry_Raw_View_v();
      break;
	  case ME_Hydra2defs_OEM_E_BUNRVOneCam :
      aHmiM_STM_f_Entry_BUNRVOneCam_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRVOneCam :
      aHmiM_STM_f_Entry_BUZRVOneCam_View_v();
      break;
    /*AP HMI*/
	  case ME_Hydra2defs_OEM_E_APA_FTV:
    case ME_Hydra2defs_OEM_E_APA_RTV:
    case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
    	aHmiM_STM_f_Entry_AutoPark_View_v();
    	break;
    case ME_Hydra2defs_OEM_E_TSC_Aiming:
      aHmiM_STM_f_Entry_TSC_Aiming_View_v();
      break;
    default:
      break;
    }
  }
  else
  {
    EvaluateBottomBarButtons();
    aHmiM_STF_F_EvaluateJackKnifeOverlays_v();
    aHmiM_STM_f_XButtonHandlingDefault();
    /* View remains the same */
    switch (aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
    case ME_Hydra2defs_OEM_E_NoView:
      /* do Function SystemONVideoOFF */
      aHmiM_STM_f_Do_SystemONVideoOFF_v();
      break;
    case ME_Hydra2defs_OEM_E_RearTopView:
      aHmiM_STM_f_Do_RearTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontTopView:
      /* do Function Front Top View */
      aHmiM_STM_f_Do_FrontTopView_v();
      break;
    case ME_Hydra2defs_OEM_E_RearCrossPathView:
      /* do Function Front Top View */
      aHmiM_STM_f_Do_RearCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontCrossPathView:
      /* do Function Front Top View */
      aHmiM_STM_f_Do_FrontCrossView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUNRV:
      /* do Function RVC_Only Normal View */
      aHmiM_STM_f_Do_RVCOnlyNormalView_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRV:
      /* do Function RVC_Only Zoom View */
      aHmiM_STM_f_Do_RVCOnlyZoomView_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Normal:
      /* exit Function RVC_Only Normal View */
      aHmiM_STM_f_Do_THANormalRearView_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Do_THAZoomRearView1_v();
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Static:
      /* exit Function RVC_Only Zoom View */
      aHmiM_STM_f_Do_THAZoomRearView2_v();
      break;
    case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
      aHmiM_STM_f_Do_FrontWithTiretracks_v();
      break;
      // case ME_Hydra2defs_OEM_E_RAW_Rear:
      //   aHmiM_STM_f_Do_TRA_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRGLeftCurbView:
      aHmiM_STM_f_Do_TRGLeftCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRGRightCurbView:
      aHmiM_STM_f_Do_TRGRightCurb_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindLeft:
      aHmiM_STM_f_Do_BlindLeft_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BlindRight:
      aHmiM_STM_f_Do_BlindRight_View_v();
      break;
    case ME_Hydra2defs_OEM_E_TRG_L50_R50:
    case ME_Hydra2defs_OEM_E_TRG_L25_R75:
    case ME_Hydra2defs_OEM_E_TRG_L75_R25:
    case ME_Hydra2defs_OEM_E_TRG_L100_R0:
    case ME_Hydra2defs_OEM_E_TRG_L0_R100:
      aHmiM_STM_f_Do_TRG_View_v();
      break;
    case ME_Hydra2defs_OEM_E_RAW_Front:
    case ME_Hydra2defs_OEM_E_RAW_Rear:
    case ME_Hydra2defs_OEM_E_RAW_Right:
    case ME_Hydra2defs_OEM_E_RAW_Left:
    case ME_Hydra2defs_OEM_E_QuadView:
      aHmiM_STM_f_Do_Raw_View_v();
      break;
	  case ME_Hydra2defs_OEM_E_BUNRVOneCam :
      aHmiM_STM_f_Do_BUNRVOneCam_View_v();
      break;
    case ME_Hydra2defs_OEM_E_BUZRVOneCam :
      aHmiM_STM_f_Do_BUZRVOneCam_View_v();
      break;
    /*AP HMI*/
    case ME_Hydra2defs_OEM_E_APA_FTV:
    case ME_Hydra2defs_OEM_E_APA_RTV:
    case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
     aHmiM_STM_f_Do_AutoPark_View_v();
     break;
    case ME_Hydra2defs_OEM_E_TSC_Aiming:
      aHmiM_STM_f_Do_TSC_Aiming_View_v();
      break;
    case ME_Hydra2defs_OEM_E_NonViewRequested:
      /*Fall through*/
    default:
      /*Failure - be sure to not request a wrong screen and set screen to default*/
      break;
    }
  }
  aHmiM_STM_Verify_Output_Change_THA();
  
  return;
}
static void aHmiM_STM_f_Entry_CheckFailsafe_v(void)
{
  /* DD-ID: {83851DC1-1BFB-482a-BBFB-64570FEA861E}*/
  static aZynqM_S_ScreenType_t lastFilsafeRequestedScreenByHmi_s  = {0};

  /* Degrdae to deactivate video ouptput from SVS (FID_SV360_DISABLED) */
  if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled)
  {

      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NoView;
      aHmiM_STM_f_Entry_SystemONVideoOFF_v();
      vDisableSVS = TRUE;
  }
  else 
  {
    vDisableSVS = FALSE;
  }

  /* IF SVS is active then only check for other failsafe */
  if(FALSE == vDisableSVS)
  {

    /* Degrade SVS views and lock to Rear top view only */
    if(((TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2)||
        (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3)||
        (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5)||
        (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6)))
    {
      aHmiM_STM_v_SoftBtnsDisabled_b = TRUE;
      vViewDegToRearTop = TRUE;
    }
    else
    {
      aHmiM_STM_v_SoftBtnsDisabled_b = FALSE;
      vViewDegToRearTop = FALSE;
    }



    /* Degrade SVS feature to display only static guidelines*/
    if((TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1) || (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3))
    {	  
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.EnableStaticGuidelines_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.EnableStaticGuidelines_b = FALSE;
    }

    /* Degrade SVS feature with dynamic and tyre guidelines deafult ON and default ENGLISH language selected */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewFrontDynamics_b = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontViewDynamics_b    = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewRearDynamics_b  = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b     = TRUE; 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontTireTracks_b      = TRUE;

      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.DefaultEngLang_b       = TRUE;            
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.DefaultEngLang_b = FALSE;
    }

    /* Degrade SVS views with X button not selectable */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5)
    {
      HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b=FALSE;
    }

    /* Degrade SVS views by disabling zoom buttons */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6)
    {
      vDisableZoomBut = TRUE;
    }
    else
    {
      vDisableZoomBut = FALSE;
    }


    /* Degrade SVS Rear cam views with black view in all views */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackCam_NA_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackCam_NA_b = FALSE;
    }

    /* Degrade SVS Front cam views with black screen in all views */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCam_NA_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCam_NA_b = FALSE;
    }

    /* Degrade SVS Left cam views with black screen in all views */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftCam_NA_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftCam_NA_b = FALSE;
    }

    /* Degrade SVS Right cam views with black screen in all views */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightCam_NA_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightCam_NA_b = FALSE;
    }

    /* Degrade SVS Top View to blackout until first successful calibration */
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewBlack_b = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewBlack_b = FALSE;
    }

    /* Degrade SVS Top View to live camera feed even if Doors are open*/
    if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.DoorSigFault_b = TRUE;

      aHmiM_STM_v_Rx_HmiMRelatedData_e.TailgateAJAR_e   =DoorCLOSED;
      aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftFrontAJAR_e  =DoorCLOSED;    
      aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftRearAJAR_e   =DoorCLOSED;
      aHmiM_STM_v_Rx_HmiMRelatedData_e.RightRearAJAR_e  =DoorCLOSED;   
      aHmiM_STM_v_Rx_HmiMRelatedData_e.RightFrontAJAR_e =DoorCLOSED;

      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackDoorOpen_Icon_b        = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearOpen_Icon_b   = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearOpen_Icon_b    = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontOpen_Icon_b  = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontOpen_Icon_b   = FALSE;  
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.DoorSigFault_b = FALSE;
    }

  }

  #if HMI_DEGRADATION_FUNC_DEBUG_ENABLE
    static uint8 lastMeFID_SVS_Disabled 	    = 0;
    static uint8 lastMeFID_SVS_LIMMod1 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod2 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod3 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod4 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod5 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod6 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod7 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod8 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod9 	      = 0;
    static uint8 lastMeFID_SVS_LIMMod10 	    = 0;
    static uint8 lastMeFID_SVS_LIMMod11 	    = 0;
    static uint8 lastMeFID_SVS_LIMModOpenDoor = 0;
    if((lastMeFID_SVS_Disabled 	    != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled 	    ) ||
      (lastMeFID_SVS_LIMMod1 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1 	    ) ||
      (lastMeFID_SVS_LIMMod2 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2 	    ) ||
      (lastMeFID_SVS_LIMMod3 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3 	    ) ||
      (lastMeFID_SVS_LIMMod4 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4 	    ) ||
      (lastMeFID_SVS_LIMMod5 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5 	    ) ||
      (lastMeFID_SVS_LIMMod6 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6 	    ) ||
      (lastMeFID_SVS_LIMMod7 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7 	    ) ||
      (lastMeFID_SVS_LIMMod8 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8 	    ) ||
      (lastMeFID_SVS_LIMMod9 	      != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9 	    ) ||
      (lastMeFID_SVS_LIMMod10 	    != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10 	    ) ||
      (lastMeFID_SVS_LIMMod11 	    != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11 	    ) ||
      (lastMeFID_SVS_LIMModOpenDoor != aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor))
    {
      lastMeFID_SVS_Disabled 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_Disabled;
      lastMeFID_SVS_LIMMod1 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod1;
      lastMeFID_SVS_LIMMod2 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod2;
      lastMeFID_SVS_LIMMod3 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod3;
      lastMeFID_SVS_LIMMod4 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod4;
      lastMeFID_SVS_LIMMod5 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod5;
      lastMeFID_SVS_LIMMod6 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod6;
      lastMeFID_SVS_LIMMod7 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7;
      lastMeFID_SVS_LIMMod8 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8;
      lastMeFID_SVS_LIMMod9 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9;
      lastMeFID_SVS_LIMMod10 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10;
      lastMeFID_SVS_LIMMod11 	      = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod11;
      lastMeFID_SVS_LIMModOpenDoor  = aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMModOpenDoor;

      appLogPrintf( "\n !!! FID_SV360_DISABLED          = %d "
                    "\n !!! FID_SV360_LIMITED_Mode1     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode2     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode3     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode4     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode5     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode6     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode7     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode8     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode9     = %d "
                    "\n !!! FID_SV360_LIMITED_Mode10    = %d "
                    "\n !!! FID_SV360_LIMITED_Mode11    = %d "
                    "\n !!! FID_SV360_LIMITED_Open_Door = %d ",
                    lastMeFID_SVS_Disabled,
                    lastMeFID_SVS_LIMMod1,
                    lastMeFID_SVS_LIMMod2,
                    lastMeFID_SVS_LIMMod3,
                    lastMeFID_SVS_LIMMod4,
                    lastMeFID_SVS_LIMMod5,
                    lastMeFID_SVS_LIMMod6,
                    lastMeFID_SVS_LIMMod7,
                    lastMeFID_SVS_LIMMod8,
                    lastMeFID_SVS_LIMMod9,
                    lastMeFID_SVS_LIMMod10,
                    lastMeFID_SVS_LIMMod11,
                    lastMeFID_SVS_LIMModOpenDoor);
    }
  #endif
  if(ME_Hydra2defs_OEM_E_NonViewRequested == aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    /* Make sure that we don't request "NonViewRequested" if only overlays changed
     * "aHmiM_STM_v_RequestedScreenByHmiM_s.view" will be reset to "NonViewRequested" on "aHmiM_STM_f_Exit_WaitForRequestedScreenOnZynqM_v" */
    aHmiM_STM_v_RequestedScreenByHmiM_s.view = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
  }
  else{/*do nothing*/}
  if(lastFilsafeRequestedScreenByHmi_s.view != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    screenReq.MeSVS_e_ViewEngReqCode = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
    lastFilsafeRequestedScreenByHmi_s.view =  aHmiM_STM_v_RequestedScreenByHmiM_s.view;
  }
  
  if(memcmp(&lastFilsafeRequestedScreenByHmi_s.overlays, &aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, sizeof(OverlayBits_t))!=0)
  {
    memcpy((&screenReq.MbSVS_bf_OverlayBitsReq),(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays),sizeof(OverlayBits_t)); 
    memcpy(&lastFilsafeRequestedScreenByHmi_s.overlays, &aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, sizeof(OverlayBits_t));
  }
  return; 
}

static void aHmiM_STM_f_Entry_RequestScreenOnZynqM_v(void)
{
  /* DD-ID: {78B9D0C9-DCA7-4596-BBAD-61D9A509C29A}*/

  if((TRUE == lastReqSvResponseFailureSts) && (TRUE == StmBootUpViewSts) && (FALSE == lastValidReqSentSts))
  {
    /* Make sure that we don't request "NonViewRequested" if only overlays changed
     * "aHmiM_STM_v_RequestedScreenByHmiM_s.view" will be reset to "NonViewRequested" on "aHmiM_STM_f_Exit_WaitForRequestedScreenOnZynqM_v" */
      memcpy(&screenReq, &lastValid_screenReq, sizeof(ScreenRequest_t));
      lastValidReqSentSts = TRUE;
      //printf("\n LAST VALID VIEW REQUESTED..............................\n");
  }


  if(memcmp(&prev_screenReq, &screenReq, sizeof(ScreenRequest_t))!=0)
  {	
    SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq);
    retryScreenReqSts = FALSE;

    aHmiM_STM_f_StartScreenRequestTimeoutTimer();
    aHmiM_STM_f_StartScreenRequestRetryTimer();
    //printf("\n ENT_SCR_REQ: time:%llu Line:%d SigMgr_PpScreenRequest_ScreenRequest_t_Put: req:%d -- %d, ovl:%d\n", TimerP_getTimeInUsecs(), __LINE__,prev_screenReq.MeSVS_e_ViewEngReqCode, screenReq.MeSVS_e_ViewEngReqCode, memcmp((&prev_screenReq.MbSVS_bf_OverlayBitsReq),(&screenReq.MbSVS_bf_OverlayBitsReq),sizeof(screenReq.MbSVS_bf_OverlayBitsReq)));
    memcpy(&prev_screenReq, &screenReq, sizeof(ScreenRequest_t));
  }
  #if HMI_PROFILING
  /*HMI Instance 2 - Sending View Request to A72*/
      if((TRUE == GearFlag) && (aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)) //FTV
        {
          GearFlag = FALSE;
          GearFlag2 = TRUE;
          end_time = TimerP_getTimeInUsecs();
          // appLogPrintf("TX IPC Gear Based: %llu us" ,(end_time - GearRecieved));
        }
      else{/*do nothing*/}    

      if((TRUE == DisplayStsFlag) && (aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)) //RCPV
        {
          DisplayStsFlag = FALSE;
          DisplayStsFlag2 = TRUE;
          end_time = TimerP_getTimeInUsecs();
          #if defined(GPIO_TIMING_MEASURE_ENA)
            GPIOPinWrite_v0(CSL_WKUP_GPIO0_BASE, 34, GPIO_PIN_LOW);
          #endif
          appLogPrintf("%llu,ID,%d,P2to3,%llu",hit_counter, aHmiM_STM_v_RequestedScreenByHmiM_s.view, (end_time - DisplayStsRecieved));
        }
        else{/*do nothing*/}     

      if((TRUE == TouchFlag) && (aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view))  //BURV
        {
          TouchFlag = FALSE;
          TouchFlag2 = TRUE;
          end_time = TimerP_getTimeInUsecs();
          // appLogPrintf("TX IPC Touch Based: %llu us" ,(end_time - TouchRecieved));
        }   
        else{/*do nothing*/}  
    #endif

#ifdef AP_LOGS
  appLogPrintf("BBB:%d FST:%d TRB:%d TBB:%d" , screenReq.AP_HMI_BottomBlackBanner, screenReq.AP_HMI_Fullscreen, screenReq.AP_HMI_TopRedBanner, screenReq.AP_HMI_TopBlackBanner);

  for(int slot_index=0; slot_index<6; slot_index++)
    appLogPrintf("Slot:%d, X:%d, Y:%d, ID:%d, Typ:%d, Sel:%d\n"
      ,slot_index
      ,screenReq.AP_HMI_ParkSlot[slot_index].SlotPixelCoordinate_X
      ,screenReq.AP_HMI_ParkSlot[slot_index].SlotPixelCoordinate_Y
      ,screenReq.AP_HMI_ParkSlot[slot_index].SlotID
      ,screenReq.AP_HMI_ParkSlot[slot_index].SlotType
      ,screenReq.AP_HMI_ParkSlot[slot_index].SlotSelected
    );
#endif
  // aZynqM_F_SetScreen_v(&aHmiM_STM_v_RequestedScreenByHmiM_s);
  // aZynqM_F_SetZoomFactor_v(aHmiM_STM_v_ZoomFactor_u8);
  aHmiM_STM_v_RequestedViewByHmiM_s = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
  aHmiM_STM_f_Update_MCUDebug0_v();
  return;
}
static void aHmiM_STM_f_Entry_WaitForRequestedScreenOnZynqM_v(void)
{
  /* DD-ID: {4DF55EF1-ADA7-44b8-956F-7A178D8DB4CC}*/
  /* do nothing - we wait for the Requested View in aHmiM_STM_f_DoState_WaitForRequestedScreenOnZynqM_v */
  return;
}
static void aHmiM_STM_f_Entry_LockOutWait_v(void)
{
  /* DD-ID: {4FE0C844-5EDB-4aa5-B53F-4926FE9724C3}*/
  aHmiM_STM_v_StartLockOutWaitTimer_b = TRUE; /* Set the LockOutWait Start Flag */
  return;
}
static void aHmiM_STM_f_Entry_End_v(void)
{
  /* DD-ID: {49DC2C46-9F24-45d4-B3D4-C6608DAA63D0}*/
  /* Set back the Requested Mode */
  aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;
  return;
}

static void aHmiM_STM_f_DoState_NotInit_v(void)
{
  /* DD-ID: {7F4B620F-B303-4a5b-BE1E-4B702C16697E}*/
  return;
}
static void aHmiM_STM_f_DoState_Init_v(void)
{
  /* DD-ID: {C14ACE50-46DF-480a-9E0A-0A9133F5A152}*/
  return;
}
static void aHmiM_STM_f_DoState_CheckInactiveMode_v(void)
{
  /* DD-ID: {FF560211-4C59-432d-977B-408B62D4829E}*/
  return;
}
static void aHmiM_STM_f_DoState_CheckView_v(void)
{
  /* DD-ID: {65A8BF5C-ECA4-416a-A1E6-B4C41390BA5B}*/
  return;
}
static void aHmiM_STM_f_DoState_CheckOvl_v(void)
{
  /* DD-ID: {55E171F7-62AF-4ae6-97C7-4A253341CCF2}*/
  return;
}
static void aHmiM_STM_f_DoState_CheckFailsafe_v(void)
{
  /* DD-ID: {57EB0453-BDE5-4cfe-A9CA-8D0FA8BDEE73}*/
  return;
}
static void aHmiM_STM_f_DoState_RequestScreenOnZynqM_v(void)
{
  /* DD-ID: {D238DBA3-79CA-42cc-9217-362B9557D537}*/
  return;
}
static void aHmiM_STM_f_DoState_WaitForRequestedScreenOnZynqM_v(void)
{
  /* DD-ID: {B70B30B3-8940-453f-B9A2-54E3A1D8B292}*/

  if(TRUE == aHmiM_STM_f_IsScreenRequestRetryExpr())
  {
    retryScreenReqSts = TRUE;
  }

  if(TRUE == retryScreenReqSts)
  {	
    SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq);
    retryScreenReqSts = FALSE;
    aHmiM_STM_f_StartScreenRequestRetryTimer();
    //printf("\n WAIT_SCR_REQ: time:%llu Line:%d SigMgr_PpScreenRequest_ScreenRequest_t_Put ----- Req:%d --- %d  OVL:%d\n", TimerP_getTimeInUsecs(), __LINE__,prev_screenReq.MeSVS_e_ViewEngReqCode, screenReq.MeSVS_e_ViewEngReqCode, memcmp((&prev_screenReq.MbSVS_bf_OverlayBitsReq),(&screenReq.MbSVS_bf_OverlayBitsReq),sizeof(screenReq.MbSVS_bf_OverlayBitsReq)));
  }
//printf("\n Do_SCR_REQ ViewId:%d --- %d\n",aHmiM_STM_v_RequestedScreenByHmiM_s.view,screenReq.MeSVS_e_ViewEngReqCode);
  // aZynqM_F_SetZoomFactor_v(aHmiM_STM_v_ZoomFactor_u8);


  return;
}
static void aHmiM_STM_f_DoState_LockOutWait_v(void)
{
  /* DD-ID: {6AF3A2B9-30EC-4965-A433-BF93EDC78D5E}*/
  /* Wait till LockOutWait Timer Expired */
  return;
}
static void aHmiM_STM_f_DoState_End_v(void)
{
  /* DD-ID: {4EEA527C-80D9-48c5-8D6A-730A6A1AB9A5}*/
  /* Wait for reactivation... */
  return;
}

static void aHmiM_STM_f_Exit_NotInit_v(void)
{
  /* DD-ID: {20F7587E-D169-4649-90C1-9D36B3B07962}*/
  return;
}
static void aHmiM_STM_f_Exit_Init_v(void)
{
  /* DD-ID: {FD469D0B-7B3A-49df-81C9-2BA60457DB84}*/
  return;
}
static void aHmiM_STM_f_Exit_CheckInactiveMode_v(void)
{
  /* DD-ID: {2EB69229-58E4-45f7-9081-89E96DC2F51E}*/
  return;
}
static void aHmiM_STM_f_Exit_CheckView_v(void)
{
  /* DD-ID: {DDE9DB98-A50B-4ed1-A2D0-BCA95F33CBEC}*/
  return;
}
static void aHmiM_STM_f_Exit_CheckOvl_v(void)
{
  /* DD-ID: {DA97D297-9666-433b-AEB0-321034082A63}*/
  return;
}
static void aHmiM_STM_f_Exit_CheckFailsafe_v(void)
{
  /* DD-ID: {241CE345-F04A-4c88-ADA7-D1430F423FCC}*/
  return;
}
static void aHmiM_STM_f_Exit_RequestScreenOnZynqM_v(void)
{
  /* DD-ID: {BFFE0E16-7B11-4483-AB13-C85D055C234C}*/
  return;
}
static void aHmiM_STM_f_Exit_WaitForRequestedScreenOnZynqM_v(void)
{
  /* DD-ID: {0A8EF13F-64A9-4c52-9538-7320D6D7E7C0}*/
  if ((0 == aHmiM_STM_v_ReleaseWaitForScreenCnt_u32)&&(FALSE)) 
  {
    /* Timer Expired - Error Handling */
    /* For now the initial Values as they are set in aHmiM_STM_f_Entry_Init_v are restored */
    aHmiM_STM_v_SystemState_e = SystemONVideoOFF;
    aHmiM_STM_v_InitialRun_b = TRUE;

    /* reset the screen structures */
    (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s, 0x00, sizeof(aZynqM_S_ScreenType_t)); /* just overlays were set here before */
    (void)memset(&aHmiM_STM_v_CurrentScreenOnZynqM_s, 0x00, sizeof(aZynqM_S_ScreenType_t));  /* just overlays were set here before */

    // aHmiM_STM_v_ScreenRequestTimeoutCnt_u32++;
    // aHmiM_STM_v_ScreenRequestTimedOut_b = TRUE;
  }
  else
  {
    /* Requested Screen is active on ZynqM */
    // aHmiM_STM_v_ScreenRequestTimeoutCnt_u32 = 0;
    // aHmiM_STM_v_ScreenRequestTimedOut_b = FALSE;

    /* Set the System State */
    if (ME_Hydra2defs_OEM_E_NoView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
      aHmiM_STM_v_SystemState_e = SystemONVideoOFF;
    }
    else
    {
      aHmiM_STM_v_SystemState_e = SystemONVideoON;
    }

    if ((aHmiM_STM_v_LastRequestedView_e != aHmiM_STM_v_RequestedScreenByHmiM_s.view) && (aHmiM_STM_v_RequestedScreenByHmiM_s.view != ME_Hydra2defs_OEM_E_NonViewRequested))
    {
      #if HMI_ESSENTIAL_DEBUG
        appLogPrintf("Transition made from View: %d to View: %d \n", (ME_Hydra2defs_E_ViewType_t)aHmiM_STM_v_LastRequestedView_e, (ME_Hydra2defs_E_ViewType_t)aHmiM_STM_v_RequestedScreenByHmiM_s.view);
      #endif
      aHmiM_STM_v_LastRequestedView_e = (ME_Hydra2defs_E_ViewType_t)aHmiM_STM_v_RequestedScreenByHmiM_s.view;
    }
    else
    {
      // do nothing
    }
    
    /* Reset the Requested View */
    if(TRUE == StmBootUpViewSts)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = aHmiM_STM_v_LastRequestedView_e;
    }

   

    // if(aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view && aHmiM_STM_v_RequestedScreenByHmiM_s.view != ME_Hydra2defs_OEM_E_NonViewRequested)
    // {
    //   screenReq.MeSVS_e_ViewEngReqCode = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
    //   memcpy((&screenReq.MbSVS_bf_OverlayBitsReq), (&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays), sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
    //   SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq);
    //   //appLogPrintf("View Change was sent!");
    // }
    // else if(aHmiM_STM_v_RequestedScreenByHmiM_s.view == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    // {
    //   if(0 !=  memcmp((&aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays), (&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays), sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays)))
    //   {
    //     memcpy((&screenReq.MbSVS_bf_OverlayBitsReq), (&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays), sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
    //     SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq);
    //     //appLogPrintf("Overlay Change was sent!"); /*Commenting as there is always a mismatch and log will appear again and again*/
    //   }
    //   else
    //   {
    //     //do nothing
    //   }
    // }
    // else
    // {
    //   //do nothing
    // }

    // MemUpdateEnforcer1_b = !MemUpdateEnforcer1_b;
    // MemUpdateEnforcer2_b = !MemUpdateEnforcer2_b;

    // HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = (boolean);
    // HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = (boolean);
    // HMI_to_VCAN.IeSVS_b_AUXCamReqSts = (boolean);
  }

    aHmiM_STM_f_Evaluate_HMIView_DisplayView_v();
    
    aHmiM_STM_v_ReleaseWaitForScreenCnt_u32 = aHmiM_STM_v_ScreenRequestTimeout_u32; /* Set back the Release Timer */
    
    aHmiM_STM_f_Update_MCUDebug0_v();

    #ifdef SW_PATCH_DEBUG
    static uint32_t cntDisplayViewPatch = 0U;
    // 14 is just a delay for view to start appearing on headUnit.
    if (cntDisplayViewPatch < 14U)
    {
      cntDisplayViewPatch += 1U;
      Tx_HmiView = (aSigConverter_E_DisplayView2_t)DisplayView3_ViewOFF;
    }
    else
    {
      Tx_HmiView = (aSigConverter_E_DisplayView2_t)DisplayView3_View1;
      cntDisplayViewPatch = 14U;
    }
    #endif

    #ifdef TRSC_LOG_ENABLE
    aHmiM_TRSC_Debug();
    #endif
    #ifdef APA_LOG_ENABLE
    aHmiM_AutoPark_Debug();
    #endif
  
  return;
}

static void aHmiM_STM_f_Update_MCUDebug0_v(void)
{
  /* DD-ID: {B5E78BFF-31B5-4224-B4A4-1221B938F09F}*/
  ME_Hydra2defs_E_MCUDebug0_t mcudebug;
  /* Commenting for future use for debugging */
  // mcudebug = aZynqM_F_GetMCUDebug0_e();
  mcudebug.M_CurrentScreenOnZynqM = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
  if (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_BURV_Memory_e)
  {
    mcudebug.M_BURV_Memory_e = M_ZoomLevel_Zoom;
  }
  else if (ME_Hydra2defs_OEM_E_BUNRV == aHmiM_STM_v_M_BURV_Memory_e)
  {
    mcudebug.M_BURV_Memory_e = M_ZoomLevel_Normal;
  }
  else
  {
    /* Do Nothing */
  }

  /* Req Id - 529288 ,529290 */
  mcudebug.M_FFClatch = aHmiM_STM_v_M_FFClatch_e;
  mcudebug.Reserved1_u8 = 0x00;
  /* Req 515905 , 526963 */
  mcudebug.DNDGear = aHmiM_STM_v_M_DNDGear_e;
  mcudebug.M_RequestedScreenByHmiM = aHmiM_STM_v_RequestedViewByHmiM_s;
  /* Commenting for future use for debugging */
  // aZynqM_F_SetMCUDebug0_v(mcudebug);
}

static void aHmiM_STM_f_Exit_LockOutWait_v(void)
{
  /* DD-ID: {C98AF5AC-C37E-4dc7-A500-09A93DE4B65B}*/
  /* do nothing */
  return;
}
static void aHmiM_STM_f_Exit_End_v(void)
{
  /* DD-ID: {A3CC75AD-90D8-4354-9DD3-D84BB415E668}*/
  aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;
  return;
}

/* ######################################################################################################
 * --- TRIGGERS ---
 * ###################################################################################################### */
/* Trigger 1 - M_ReversedGear0->1 + K_TDelayPRND */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToReversed_b(void)
{
  /* DD-ID: {521538A6-2EA4-482c-A69D-055B86507FEA}*/
  BOOL retVal;
  if (aHmiM_STM_e_Reverse == aHmiM_STM_v_SwitchToGear_ViewTrigger_e)
  {
    retVal = TRUE;
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_None;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 3 - Rx_PRND_STAT -> 0x7 (SNA) || 0x3 || 0x6 */
static BOOL aHmiM_STM_f_CheckViewTrigger_PRNDStatSNAorUndef_b(void)
{
  /* DD-ID: {EA9A0FDD-7CD0-4f5a-8870-0D7F635CD20F}*/
  BOOL retVal;
  if (prndStatus_e_old != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e && ((PRND_STAT_SNA == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) || (PRND_STAT_NA == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) || (PRND_STAT_UNDEF == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)))
  {
    prndStatus_e_old = aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e;
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 4 - Rx_PRND -> 0x00(P) + K_TDelayPRND */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToPark_b(void)
{
  /* DD-ID: {AF6A23EA-8ABF-4b93-99EA-8B0F01CBAF94}*/
  BOOL retVal;
  if ((PRND_STAT_P == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (aHmiM_STM_e_Park == aHmiM_STM_v_SwitchToGear_ViewTrigger_e))
  {
    retVal = TRUE;
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_None;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 5 - Rx_PRND -> 0x02(N) + K_TDelayPRND */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToNeutral_b(void)
{
  /* DD-ID: {7FA169B4-9969-4dd2-9757-416CC1F9F560}*/
  BOOL retVal;
  if ((PRND_STAT_N == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (aHmiM_STM_e_Neutral == aHmiM_STM_v_SwitchToGear_ViewTrigger_e))
  {
    retVal = TRUE;
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_None;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 6 - Rx_PRND -> 0x04(D) + K_TDelayPRND */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearToDrive_b(void)
{
  /* DD-ID: {3E94B0EB-A61C-4b4b-942D-E1F32E410ACB}*/
  BOOL retVal;
  if ((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (aHmiM_STM_e_Drive == aHmiM_STM_v_SwitchToGear_ViewTrigger_e))
  {
    retVal = TRUE;
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_None;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* ===============================================================
 * Purpose :To check gear status is not equal to Neutral
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 526965
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoNeutral_b(void)
{
  /* DD-ID: {335E7CCC-39BC-40e2-AE9E-F4C48ADEF89B}*/
  BOOL retVal;

  if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b)
      /*Req ID : 526965, Defect ID : 698431*/
  )
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* ===============================================================
 * Purpose :Trigger check function for gear changes from Reverse to Any other gear trigger
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 526965
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckViewTrigger_GearNotEqualtoReverse_b(void)
{
  /* DD-ID: {3EE5EF49-E0CF-42e8-AF0B-C9166A3618B7}*/
  BOOL retVal;

  if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToNeutral_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.PRNDStatSNAorUndef_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b) || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_isSVSEnabled_b(void)
{
  /* DD-ID: {BFC78705-EABA-4439-8CEB-F1988D766491}*/
  BOOL retval = FALSE;
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera == 1U)
  {
    retval = TRUE;
  }
  return retval;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_isSVSDisabled_b(void)
{
  /* DD-ID: {71BD926E-32A6-43b3-B399-FA9D91154D6F}*/
  BOOL retval = FALSE;
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera == 0U)
  {
    retval = TRUE;
  }
  return retval;
}

/* Trigger 7 - Rx_TGW_DISP != 0x04 (DISP_REAR_CAMERA) and Rx_TGW_DISP != 0x07(DISP_SVS_MORECAMS_POPUP)  */
static BOOL aHmiM_STM_f_CheckViewTrigger_NotDispRearCam_b(void)
{
  /* DD-ID: {45CB1FB9-B7AE-4ca2-A3B3-10CCBC96D248}*/
  BOOL retVal;
  static aSigConverter_E_TGW_DISP_STAT_t dispStatOld = TGW_DISP_STAT_SNA;

  if (dispStatOld != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
  {
    if (((DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) &&
         /*Req Id :498360 the last known CVPM view that was being displayed before going to AUX view should be displayed.�*/
         (DISP_TRAILER_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) &&
         (DISP_WIRLESS_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) &&
         (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)) &&
        /* The function "aHmiM_STM_f_CheckViewTrigger_NotDispRearCam_b" should return TRUE only when the value changes from TGW changes from TGW = !(4/5/6/7) to TGW = (0/1/2/3) */
        ((DISP_REAR_CAMERA == dispStatOld) || (DISP_TRAILER_CAMERA == dispStatOld) ||
         (DISP_WIRLESS_CAMERA == dispStatOld) || (DISP_SVS_MORECAMS_POPUP == dispStatOld)))
    {
      retVal = TRUE;
    }
    else
    {
      retVal = FALSE;
    }
    dispStatOld = aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrailerWirelessCam_b(void)
{
  /* DD-ID: {737DCB5A-2F63-4b33-8E61-5B92C0944162}*/
  BOOL retVal;
  static aSigConverter_E_TGW_DISP_STAT_t dispStatOldTrailerWireless = TGW_DISP_STAT_SNA;

  if (dispStatOldTrailerWireless != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
  {
    dispStatOldTrailerWireless = aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e;
    if ((DISP_TRAILER_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_WIRLESS_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
    {
      retVal = TRUE;
    }
    else
    {
      retVal = FALSE;
    }
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* Rx_TGW_DISP != 0x05 && != 0x06 */
static BOOL aHmiM_STM_f_CheckViewTrigger_NotDispTrailerOrWirelessCamera_b(void)
{
  /* DD-ID: {9051921C-F334-4519-9329-D4FAD21CBDC4}*/
  BOOL retVal = FALSE;
  /*  static aSigConverter_E_TGW_DISP_STAT_t dispStatOld_NotDispTrailerOrWirelessCamera = TGW_DISP_STAT_SNA;

      if(dispStatOld_NotDispTrailerOrWirelessCamera != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
      {
        dispStatOld_NotDispTrailerOrWirelessCamera = aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e;
        if(    (TGW_CAMERA_DISP_STAT_TRAILER_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
            && (TGW_CAMERA_DISP_STAT_WIRLESS_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
           )
        {
          retVal = TRUE;
        }
        else
        {
          retVal = FALSE;
        }
      }
      else
      {
        retVal = FALSE;
      } */
  return retVal;
}

/* Trigger 8 - Rx_VEH_SPEED < K_VideoON_Speed */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedLowerVideoONSpeed_b(void)
{
  /* DD-ID: {D9161B76-60C8-4a8f-84E1-866605A47C2A}*/
  BOOL retVal;
  if ((aHmiM_STM_v_Video_On_Speed_f32 > aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) && ((f32)ASIGCONVERTER_D_VEHSPEED_SNA > aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) /*Defect 378582 Fix, Changing variable u16/u8 to float f32*/ /* PRQA S 2995 */ /* The result of this logical operation is always 'true'. */ /* ASIGCONVERTER_D_VEHSPEED_SNA can be set in SignalConverter */
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 9 - Rx_CmdIgn < 0x04 (IGN_RUN) */
static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionNotRun_b(void)
{
  /* DD-ID: {AFA0698C-01F9-4f98-A41E-5D43A0750032}*/
  BOOL retVal;
  if (IGN_RUN != aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 10 - Rx_VEH_SPEED > K_VideoOFF_Speed */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherVideoOFFSpeed_b(void)
{
  /* DD-ID: {444B483B-ED25-4372-A9E6-4B0DA6C6CAE0}*/
  BOOL retVal;
  if ((aHmiM_STM_v_Video_Off_Speed_f32 < aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) && ((f32)ASIGCONVERTER_D_VEHSPEED_SNA > aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Trigger 11 - Rx_VEH_SPEED = 0xFFFF (SNA) */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedSignalNA_b(void)
{
  /* DD-ID: {F28D413F-3226-43c5-9FBF-3CA08B998087}*/
  BOOL retVal;
  if (((f32)ASIGCONVERTER_D_VEHSPEED_SNA - 1.0f) < aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* Trigger 12 - CameraDisplayStatus2 = View1 (SurroundViews - TVRV/TVFV/RCPV/FCPV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView1_b(void)
{
  /* DD-ID: {85D1085B-59D7-4537-BBC2-7ADB74364536}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View1 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 13 - CameraDisplayStatus2 = View2 (Backup Camera View - BURV/BUZRV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView2_b(void)
{
  /* DD-ID: {EFFA8EE2-B06F-4801-BED2-A386B365CF12}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 28 - CameraDisplayStatus2 = View3 (CVPM FFCV View) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView3_b(void)
{
  /* DD-ID: {FAE7BA67-F04A-4524-9D7E-29CDA6F9FA09}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View3 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView5_b(void)
{
  /* DD-ID: {BC6308D4-5B25-4539-9B9D-331206224CE6}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View5 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View6 (TRGLeftView) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView6_b(void)
{
  /* DD-ID: {8B94D249-6F91-4466-B069-6A33A1412C89}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View6 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View7 (TRGRightView) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView7_b(void)
{
  /* DD-ID: {307A6966-1025-4903-95AD-94D83176BC7C}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View7 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View6 (BlindLeftView) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView8_b(void)
{
  /* DD-ID: {AE503234-F49C-43bd-B294-9C7C32693075}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View8 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View8 (BlindRightView) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView9_b(void)
{
  /* DD-ID: {08FCF1A6-0B18-43f3-A109-71893DFD3F08}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View9 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View11 (TVRV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView11_b(void)
{
  /* DD-ID: {60160D82-99CA-49ea-BE40-258FB4E19D9D}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View11 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View12 (TVFV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView12_b(void)
{
  /* DD-ID: {26D93AE3-50B4-4c0d-A89B-931197869B3F}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View12 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View13 (FCPV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView13_b(void)
{
  /* DD-ID: {694C737B-AC2C-47d1-AA3D-E56AB76EB79B}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View13 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger - CameraDisplayStatus2 = View14 (RCPV) */
static BOOL aHmiM_STM_f_CheckViewTrigger_CamDispStsView14_b(void)
{
  /* DD-ID: {290DBD76-1BB6-40b6-A29B-D509EFB20E19}*/
  BOOL retVal = FALSE;
  if (CameraDisplaySts2_View14 == aHmiM_STM_v_Rx_HmiMRelatedData_e.CameraDisplaySts2_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 14 - VehicleSpeed greater than RVC Reset Speed to Full Frame View */
static BOOL aHmiM_STM_f_CheckViewTrigger_VehSpeedHigherRVCResetSpeed_b(void)
{
  /* DD-ID: {33470BE4-4DF1-4ca1-BF11-A6C85B8F4CA7}*/
  BOOL retVal = FALSE;
  if (HMI_XCP_RVC_VIEWRESET_SPEED <= aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 15 - Was the RearTopButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_REAR_TOP_BTN_PRESSED_b(void)
{
  /* DD-ID: {4F778A10-44D5-4853-B4B2-EC899FB26590}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_REAR_TOP_BTN_PRESSED_b)
  {
    aHmiM_STM_v_REAR_TOP_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 16 - Was the RearCrossButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_REAR_CROSS_BTN_PRESSED_b(void)
{
  /* DD-ID: {E626E80F-A446-4c0a-BB00-6534CAE3AAE7}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_REAR_CROSS_BTN_PRESSED_b)
  {
    aHmiM_STM_v_REAR_CROSS_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 17 - Was the FrontCrossButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FRONT_CROSS_BTN_PRESSED_b(void)
{
  /* DD-ID: {7F883325-0497-4534-903F-6BBA0F6D1E43}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_FRONT_CROSS_BTN_PRESSED_b)
  {
    aHmiM_STM_v_FRONT_CROSS_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 18 - Was the FrontTopButton Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FRONT_TOP_BTN_PRESSED_b(void)
{
  /* DD-ID: {C74D16F2-F547-4e0b-BB4B-7EEECD65431B}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_FRONT_TOP_BTN_PRESSED_b)
  {
    aHmiM_STM_v_FRONT_TOP_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 19 - Was the X-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_X_BTN_PRESSED_b(void)
{
  /* DD-ID: {4E1D14CC-5B58-4290-8477-48C417B31520}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_X_BTN_PRESSED_b)
  {
    aHmiM_STM_v_X_BTN_PRESSED_b = FALSE;
    retVal = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b; /* button can only pressed when visible */
  }
  else
  { /*do nothing*/
  }
  return retVal;
}
/* Req ID : 445337 */
static BOOL aHmiM_STM_f_Check_MoreCams_BTN_PRESSED_b(void)
{
  /* DD-ID: {5DD92DAD-6834-495d-B3E7-2E008C2C9A2B}*/
  BOOL retVal = FALSE;
  if ((TRUE == aHmiM_STM_v_VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b) || (TRUE == aHmiM_STM_v_VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b))
  {
    aHmiM_STM_v_VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b = FALSE;
    aHmiM_STM_v_VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 20 - Was the RVC-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_RVC_BTN_PRESSED_b(void)
{
  /* DD-ID: {FB9C5017-0713-4cf3-AC9B-DCD8A3A2858F}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_RVCONLY_BTN_PRESSED_b)
  {
    aHmiM_STM_v_RVCONLY_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger  - Was the FFCV-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_FFCV_BTN_PRESSED_b(void)
{
  /* DD-ID: {B2CFDBB8-6DC5-4250-A34A-B14E32B5B8A9}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_FFCV_BTN_PRESSED_b)
  {
    aHmiM_STM_v_FFCV_BTN_PRESSED_b = FALSE;
    /* button can only pressed when visible
     * FrontFaceCamButtonNoSelect_b is overlay bit to show FFCV button
     * FrontFaceCamButtonSelect_b is overlay bit to show button in RED that indicates FFCV view is currently activie.
     */
    retVal = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Req ID : 445366 */
static BOOL aHmiM_STM_f_CheckViewTrigger_MAGNIFIER_BTN_PRESSED_b(void)
{
  /* DD-ID: {EDA78C58-7AE5-477f-8A23-204CD0018D10}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_MAGNIFIER_BTN_PRESSED_b)
  {
    aHmiM_STM_v_MAGNIFIER_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_SVC_AUX_PRESSED_b(void)
{
  /* DD-ID: {36686AFB-DA54-429f-A92F-4FF11A2A611D}*/
  BOOL retVal = FALSE;
  if ((TRUE == aHmiM_STM_v_VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b) || (TRUE == aHmiM_STM_v_VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b))

  {
    aHmiM_STM_v_VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b = FALSE;
    aHmiM_STM_v_VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Trigger 24 - Was the ZOUT-Button Pressed? */
static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_ZOUT_PRESSED_b(void)
{
  /* DD-ID: {78724377-6EE2-4f4c-B9CB-AA5F44F86B36}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_ZOOM_BTN_PRESSED_b)
  {
    aHmiM_STM_v_ZOOM_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionRun_b(void)
{
  /* DD-ID: {041CB84C-793A-4449-A4B4-F23BB236FD50}*/
  BOOL retVal;
  if (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGLEFT_PRESSED_b(void)
{
  /* DD-ID: {64FC110A-D99A-4dc6-AACA-B84BB930CF7C}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b)
  {
    aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b = FALSE;
    TRG_Stat = TRG_MANU_PAN;
    Last_TRG_Stat = TRG_MANU_PAN;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGRIGHT_PRESSED_b(void)
{
  /* DD-ID: {F2AA1828-0E1D-4e5e-9AE3-1EA17C5B3AA1}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b)
  {
    aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
    TRG_Stat = TRG_MANU_PAN;
    Last_TRG_Stat = TRG_MANU_PAN;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_SFTBTN_TRGAUTO_PRESSED_b(void)
{
  /* DD-ID: {79892649-DF45-4e66-9C5B-779FEF61FE93}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b)
  {
    aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b = FALSE;
    retVal = TRUE;

    if(TRG_AUTO_PAN == TRG_Stat)
      TRG_Stat = kTRG_MANU_PAN;
    else
      TRG_Stat = TRG_AUTO_PAN;
    
    Last_TRG_Stat = TRG_Stat;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* ===============================================================
 * Purpose :To check ignition Changed from not Run to Run
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return : True: If Ign changed Not Run to Run
 *                   False : If Ign not changed Not Run to Run
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 528495
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckViewTrigger_IgnitionNotRunToRun_b(void)
{
  /* DD-ID: {1C07A0EA-A891-46e2-9682-2133F302EAE1}*/
  BOOL retVal;
  static aSigConverter_E_CmdIgnStat_t old_ignitionStatus_e = IGN_LK;
 
  if ((old_ignitionStatus_e != IGN_RUN) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e == IGN_RUN))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  old_ignitionStatus_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e;

  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToStandBy_b(void)
{
  /* DD-ID: {8811AA87-4F0F-454b-AF30-F4E2523BDE7F}*/
  BOOL retVal = FALSE;

  if ((TRSC_STANDBY == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_STANDBY != aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToCalibrating_b(void)
{
  /* DD-ID: {AD1B6FD5-5F81-4e12-A5FF-82E89EDAD077}*/
  BOOL retVal = FALSE;
  if ((TRSC_CALIBRATING == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_CALIBRATING != aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToPreAactive_b(void)
{
  /* DD-ID: {542BA2D8-2063-49b3-9B35-32ABFC5885F6}*/
  BOOL retVal = FALSE;
  if ((TRSC_PRE_ACTIVE == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_PRE_ACTIVE != aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToActive_b(void)
{
  /* DD-ID: {24F57C06-3E25-4615-98AB-AB7E0836F84F}*/
  BOOL retVal = FALSE;
  if ((TRSC_ACTIVE == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_ACTIVE != aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscWasActive_b(void)
{
  /* DD-ID: {815CB394-56BB-43df-B157-68ECB72C2AED}*/
  BOOL retVal = FALSE;
  if ((TRSC_ACTIVE != aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_ACTIVE == aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_TrscToSNA_b(void)
{
  /* DD-ID: {927E385C-2CEB-4865-8D85-64E0FAA575C1}*/
  BOOL retVal = FALSE;
  if ((TRSC_SNA == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e) && (TRSC_SNA != aHmiM_STM_v_Last_TRSC_STAT_t))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* ######################################################################################################
 * --- GUARDS ---
 * ###################################################################################################### */

/* Guard 5 - Responsible for Trigger 8 - {(Rx_VC_Trans_Equipped = 0(Auto) && Rx_PRND_STAT = 0x04(D)) || (Rx_VC_Trans_Equipped = 1(Man) && Rx_REV_GEAR = 0)} && Rx_CmdIgnStat => 0x4 (RUN/START/SNA) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_5_b(void)
{
  /* DD-ID: {F017CADB-1F97-4d59-A861-E4F21AFE3C15}*/
  BOOL retVal;
  if ((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) &&
      (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* ===============================================================
 * Purpose :To check Gear is Drive
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return True: if Gear is in Drive state
 *                 False:if Gear is other than Drive
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 528495
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_6_b(void)
{
  /* DD-ID: {2E912D10-DEE5-4e80-973E-9A2A60AF8AD2}*/
  BOOL retVal;
  if (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Guard 7 - Responsible for Trigger 3 - Rx_VC_Trans_Equipped = 0(Auto) && Rx_CmdIgnStat => 0x4 (RUN/START/SNA) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_7_b(void)
{
  /* DD-ID: {F5B4249A-FA00-4edf-AB44-BFE099D92DF8}*/
  BOOL retVal;
  if ((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Guard 8 - Responsible for Trigger 8 & 11 - {(Rx_VC_Trans_Equipped = 0(Auto) && Rx_PRND_STAT != 0x04(D)) || (Rx_VC_Trans_Equipped = 1(Man) && Rx_REV_GEAR = 1)} && Rx_CmdIgnStat => 0x4 (RUN/START/SNA) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_8_b(void)
{
  /* DD-ID: {47A40528-A89F-449a-9899-758B64C3E4D5}*/
  BOOL retVal;
  if ((((TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (REV_GEAR_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)) || ((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))) &&
      (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Guard 9 - Responsible for Trigger 7 - {(Rx_VC_Trans_Equipped = 0(Auto) && Rx_PRND_STAT = 0x04(D)) || (Rx_VC_Trans_Equipped = 1(Man) && Rx_REV_GEAR = 0)}  && Rx_VEH_SPEED < K_VideoOFF_Speed  PRND */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_9_b(void)
{
  /* DD-ID: {12972666-A791-4ea4-BDD8-2431B7F5C8C2}*/
  BOOL retVal;
  if ((((PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e)) || ((REV_GEAR_NOT_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e) && (TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e))) &&
      (aHmiM_STM_v_Video_Off_Speed_f32 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Guard 10 - Responsible for Trigger 7 - {(Rx_VC_Trans_Equipped = 0(Auto) && Rx_PRND_STAT != 0x04(D)) || (Rx_VC_Trans_Equipped = 1(Man) && Rx_REV_GEAR = 1)}  && Rx_VEH_SPEED < K_VideoOFF_Speed */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_10_b(void)
{
  /* DD-ID: {47807A39-69B5-4f94-ACAE-168F6A718952}*/
  BOOL retVal;
  if ((((PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) && (TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e)) || ((REV_GEAR_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e) && (TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e))) &&
      (aHmiM_STM_v_Video_Off_Speed_f32 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* Guard 11 - Responsible for Trigger 4 - Rx_TGW_Disp!=0x04 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_11_b(void)
{
  /* DD-ID: {D549C495-22DF-43df-9144-92AE127FBDD8}*/
  BOOL retVal;
  if ((DISP_TRAILER_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_WIRLESS_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* ===============================================================
 * Purpose :To check Video goes off the glass
 * TGW_CAMERA_DISP_STAT != (0x4, 0x5, 0x6, 0x7)
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return True: if TGW_CAMERA_DISP_STAT is not equals (0x4, 0x5, 0x6, 0x7)
 *                 False:if TGW_CAMERA_DISP_STAT is equals to (0x4, 0x5, 0x6, 0x7)
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 526965
 * =============================================================== */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_13_b(void)
{
  /* DD-ID: {13B89BC6-7E56-4ee7-ADE5-241EFAB6D968}*/
  BOOL retVal;

  if ((DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_TRAILER_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_WIRLESS_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* Guard 14 - Responsible for Trigger 03 - Rx_VC_Trans_Equipped = 0(Auto) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_14_b(void)
{
  /* DD-ID: {E0F84E9A-135D-4459-AFD5-B4BC93691CC8}*/
  BOOL retVal = FALSE;
  if (TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}
/* Guard 15 - Responsible for Trigger 19 - M_SVC_View = Rear+Top */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_b(void)
{
  /* DD-ID: {245BF95D-B5C7-4a49-BF8E-7C9C9077286E}*/
  BOOL retVal = FALSE;
  if (ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_M_SVC_View_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}
/* Guard 16 - Responsible for Trigger 19 - M_SVC_View = Front+Top */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_b(void)
{
  /* DD-ID: {4FC41BE7-482B-4d01-9441-6210F5C85DC4}*/
  BOOL retVal = FALSE;
  if (ME_Hydra2defs_OEM_E_FrontTopView == aHmiM_STM_v_M_SVC_View_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}
/* Guard 17 - Responsible for Trigger 19 - M_SVC_View = RearCross */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearCross_b(void)
{
  /* DD-ID: {2ADC46A4-B50A-42e0-940C-322F3F9E6617}*/
  BOOL retVal = FALSE;
  if (ME_Hydra2defs_OEM_E_RearCrossPathView == aHmiM_STM_v_M_SVC_View_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}
/* Guard 18 - Responsible for Trigger 19 - M_SVC_View = FrontCross */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontCross_b(void)
{
  /* DD-ID: {7FCD0894-2B94-482a-BE5B-F29EE80603CE}*/
  BOOL retVal = FALSE;
  if (ME_Hydra2defs_OEM_E_FrontCrossPathView == aHmiM_STM_v_M_SVC_View_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_TRA_b(void)
{
  /* DD-ID: {1700E34F-C20F-4c0f-A7DA-EB5285AB3D6D}*/
  BOOL retVal = FALSE;
  if ((ME_Hydra2defs_OEM_E_RAW_Rear == aHmiM_STM_v_M_SVC_View_e) || (TRUE == aHmiM_STM_v_M_TRA_View))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Guard 19 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT != 0x4 (D) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_19_b(void)
{
  /* DD-ID: {3786A432-59AB-4b36-8D95-2B2AD37719AD}*/
  BOOL retVal = FALSE;
  if (PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
  {
    retVal = TRUE;
  }
  return retVal;
}
/* Guard 20 - Responsible for Trigger 7 & 12 - Rx_PRND_STAT = 0x4 (D) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_20_b(void)
{
  /* DD-ID: {D83810F3-8F26-4f8e-87BB-88D0AE452205}*/
  BOOL retVal = FALSE;
  if (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
  {
    retVal = TRUE;
  }
  return retVal;
}

/* Guard 21 - Responsible for Trigger - Rx_IGN => 0x04 (IGN_Run)*/
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_IGN_RUN_b(void)
{
  /* DD-ID: {550DD8A7-DE2C-442d-BB5A-AE7CD0BFD2CF}*/
  /* Rx_IGN => 0x04 (IGN_Run) */
  BOOL retVal = FALSE;
  if (IGN_RUN == aHmiM_STM_v_Rx_HmiMRelatedData_e.ignitionStatus_e)
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Guard 24 - Responsible for Trigger - BURV_Memory Zoom*/
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_BURV_MemoryZoom_b(void)
{
  /* DD-ID: {E31405B8-DC2E-4936-86D2-015439DD1209}*/
  BOOL retVal = FALSE;
  /* M_BURV_Memory = Zoom */
  if (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_BURV_Memory_e)
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Guard 25 - Responsible for Trigger - Vehicle.Speed =< 8mph &&  Rx_TGW_CAMERA_DISP_STAT = (0x4) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_VehSpdDispStat_b(void)
{
  /* DD-ID: {BBEC5C9C-AB14-445c-A98C-1B0D2843D819}*/
  BOOL retVal = FALSE;

  if ((aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32 <= HMI_XCP_RVC_VIEWRESET_SPEED) && (TRUE == aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_b())) /*Defect 378582 Fix, Changing variable u8/u16 to float f32 Vehicle.Speed =< 8mph req ID 445189 */ /* PRQA S 3415 */ /* Suppress warning "Right hand operand of '&&' or '||' is an expression with possible side effects" - this is OK here */
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Guard 27 - Responsible for Trigger - Rx_TGW_CAMERA_DISP_STAT = (0x4) || (0x07) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_b(void)
{
  /* DD-ID: {930717C2-24B5-4fa3-8B69-B679CFC49D80}*/
  BOOL retVal = FALSE;

  if ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_TRAILER_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_WIRLESS_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Guard 27 - Responsible for Trigger - Rx_TGW_CAMERA_DISP_STAT = (0x0) */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b(void)
{
  /* DD-ID: {E7B89EA7-D7E7-46c9-9A1F-D7B3410A4ED4}*/
  BOOL retVal = FALSE;
  static aSigConverter_E_TGW_DISP_STAT_t prevTgwDispSts = DISP_OFF;
  if ((prevTgwDispSts != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_OFF == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)) // 22262861 defect fix. TGW_NO_CAM status will be set only on falling edge.
  {
    retVal = TRUE;
  }
  prevTgwDispSts = aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e;
  
  return retVal;
}

/* Guard 28 - Responsible for Trigger - {(914 =< Rx_TCH_X_COORD < 1010) && (651 =< Rx_TCH_Y_COORD <747)} */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_22_b(void)
{
  /* DD-ID: {DB5A76C5-9497-43af-A88A-82F70F0A75D0}*/
  BOOL retVal = FALSE;
  BOOL tmp_BTN = aHmiM_STM_f_Is_BTN_PRESSED_b(914, 1010, 651, 747);

  if (TRUE == tmp_BTN)
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Guard 29 - Responsible for Trigger - Rx_VC_Trlr_Rev_Guidance_Prsnt = 1 */
static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_Trlr_Rev_Guidance_Prsnt_b(void)
{
  /* DD-ID: {3374D993-7D60-4b68-A90A-6AF0DC10BB32}*/
  BOOL retVal = FALSE;

  if (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRGPresence)
  {
    retVal = TRUE;
  }

  return retVal;
}

/* Requirement 525408 : TRG Panning Views Vehicle Speed Limit Guard */
static BOOL aHmiM_STM_f_CheckViewGuard_TRGPanning_VehSpdInRng_b(void)
{
  /* DD-ID: {4291AEAE-E8A2-407a-B0F7-55261F119F25}*/
  BOOL retVal;
  if (HMI_XCP_TRG_PANGUARD_SPEED > aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  return retVal;
}

/* Guard  - Responsible for Trigger  - M_SVC_View = BUNRV/BUZRV */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RCV_b(void)
{
  /* DD-ID: {10915082-D5F0-4b89-8762-DBDE640C3496}*/
  BOOL retVal = FALSE;
  if ((ME_Hydra2defs_OEM_E_BUNRV == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_BUZRV == aHmiM_STM_v_M_SVC_View_e))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Guard  - Responsible for Trigger  - M_SVC_View = FrontTop_FrontCross_RearCross */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_FrontTop_FrontCross_RearCross_b(void)
{
  /* DD-ID: {7EA4FA8E-20F6-4eb7-B564-917FFA6CB825}*/
  BOOL retVal = FALSE;
  if ((ME_Hydra2defs_OEM_E_FrontTopView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_FrontCrossPathView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_RearCrossPathView == aHmiM_STM_v_M_SVC_View_e))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* Guard  - Responsible for Trigger  - M_SVC_View = RearTop_RearCross_FrontCross */
static BOOL aHmiM_STM_f_CheckViewGuard_M_SVC_View_RearTop_RearCross_FrontCross_b(void)
{
  /* DD-ID: {2D495C9E-EE0B-4e62-A71E-4BA0FC9375B6}*/
  BOOL retVal = FALSE;
  if ((ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_RearCrossPathView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_FrontCrossPathView == aHmiM_STM_v_M_SVC_View_e))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_NotReverseGearEngaged_b(void)
{
  /* DD-ID: {B151BF8E-5170-4aa2-BAAA-BB095E9A508A}*/
  BOOL retVal;
  if (
      ((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) &&
       ((PRND_STAT_P == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) ||
        (PRND_STAT_N == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) ||
        (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e) ||
        (PRND_STAT_NOT_R == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))) ||
      ((TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (REV_GEAR_NOT_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_OFFRoadPresent_b(void)
{
  /* DD-ID: {EAA459A1-53A4-4285-9600-588A4EB830B8}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
  {
    retVal = TRUE;
  }
  else
  {
    /* do nothing */
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_FFC_View_b(void)
{
  /* DD-ID: {123B5C16-CFFE-4499-A0C1-704FF9A35701}*/
  BOOL retVal = FALSE;
  if (ME_Hydra2defs_OEM_E_FrontFacingCameraView == aHmiM_STM_v_M_SVC_View_e)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_DisplayView3_TRG_View_b(void)
{
  /* DD-ID: {665D85B0-D8EF-4f1f-96CE-AF69F6D3A44F}*/
  BOOL retVal = FALSE;

  if (DisplayView3_View7 == Tx_HmiView)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_NotDrive_And_Not_View1234_b(void)
{
  /* DD-ID: {2EF408D5-A941-44d8-AAD3-C19953AE871B}*/
  BOOL retVal = FALSE;
  if ((FALSE ==
       ((DisplayView3_View1 == Tx_HmiView) || (DisplayView3_View2 == Tx_HmiView) || (DisplayView3_View3 == Tx_HmiView) || (DisplayView3_View4 == Tx_HmiView))) &&
      ((
           (TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (REV_GEAR_NOT_ENGAGED != aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)) ||
       ((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (PRND_STAT_D != aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))))
  {
    retVal = TRUE;
  }
  else
  {
    /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_Drive_And_Not_View1234_b(void)
{
  /* DD-ID: {50A3E49B-6083-494a-97DC-4C0451E365C9}*/
  BOOL retVal = FALSE;
  if ((FALSE == ((DisplayView3_View1 == Tx_HmiView) || (DisplayView3_View2 == Tx_HmiView) || (DisplayView3_View3 == Tx_HmiView) || (DisplayView3_View4 == Tx_HmiView))) &&
      (((TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (REV_GEAR_NOT_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)) || ((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))))
  {
    retVal = TRUE;
  }
  else
  {
    /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_VehSpeedHigherVideoOFFSpeed_b(void)
{
  /* DD-ID: {86C8BD25-07C9-4b1d-A4E2-325CEC1546AD}*/
  BOOL retVal;
  if ((aHmiM_STM_v_Video_Off_Speed_f32 < aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) && ((f32)ASIGCONVERTER_D_VEHSPEED_SNA > aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32)) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

/* Rx_TGW_DISP != 0x05 && != 0x06 */
static BOOL aHmiM_STM_f_CheckViewGuard_NotDispTrailerOrWirelessCamera_b(void)
{
  /* DD-ID: {F9BDF71D-864E-4b24-AEC9-5B14C204C4B5}*/
  BOOL retVal = TRUE;
  /* static aSigConverter_E_TGW_DISP_STAT_t v_dispStatOld_NotDispTrailerOrWirelessCamera = TGW_DISP_STAT_SNA;

    if(v_dispStatOld_NotDispTrailerOrWirelessCamera != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    {
      v_dispStatOld_NotDispTrailerOrWirelessCamera = aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e;
      if(    (TGW_CAMERA_DISP_STAT_TRAILER_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
          && (TGW_CAMERA_DISP_STAT_WIRLESS_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
         )
      {
        retVal = TRUE;
      }
      else
      {
        retVal = FALSE;
      }
    }
    else
    {
      retVal = FALSE;
    } */
  return retVal;
}

/* Returns TRUE if one of the SVC views is active (S01) */
static BOOL aHmiM_STM_f_CheckViewGuard_SVCSuperState_b(void)
{
  /* DD-ID: {D021C3BE-E450-4555-93E0-9027AD951FF5}*/
  BOOL retVal = FALSE;
  if ((ME_Hydra2defs_OEM_E_FrontTopView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view) || (ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view) || (ME_Hydra2defs_OEM_E_RearCrossPathView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view) || (ME_Hydra2defs_OEM_E_FrontCrossPathView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscActive_b(void)
{
  /* DD-ID: {3419F5CE-1323-4adb-A03F-AAA3002FF219}*/
  BOOL retVal = FALSE;

  if (TRSC_ACTIVE == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscStandBy_b(void)
{
  /* DD-ID: {454AD5F3-3FA6-48b9-8E11-2D6574DCE008}*/
  BOOL retVal = FALSE;

  if (TRSC_STANDBY == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e)
  {
    retVal = TRUE;
  }
  else
  {
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscPreActive_b(void)
{
  /* DD-ID: {94EE9059-8E38-4551-8AD7-6902B06F5703}*/
  BOOL retVal = FALSE;

  if (TRSC_PRE_ACTIVE == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e)
  {
    retVal = TRUE;
  }
  else
  {
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscCalibrate_b(void)
{
  /* DD-ID: {70992D73-35B3-4f1f-887C-1D0CF7575A7C}*/
  BOOL retVal = FALSE;

  if (TRSC_CALIBRATING == aHmiM_STM_v_Rx_HmiMRelatedData_e.trscStat_e)
  {
    retVal = TRUE;
  }
  else
  {
  }
  return retVal;
}

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_TrscModulFitted_b(void)
{
  /* DD-ID: {2EB6A7D0-1F1B-4d39-AE2D-0B7D75CDA6DA}*/
  BOOL retVal = FALSE;

  if (TRSCM_Prsnt_TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.NetCfg_TRSCM_e)
  {
    retVal = TRUE;
  }
  else
  {
  }
  return retVal;
}

static BOOL aHMIM_STM_CheckGuard_IsTRSCEnable(void)
{
  /* DD-ID: {A27C40E9-A9F8-43eb-80EA-9257740D704C}*/
  BOOL retval = FALSE;
  // if()
  return retval;
}
/***************************************** THA Functions ****************************************************/
/* ===============================================================
 * Purpose :  Returns THA Screen Request States from THA SM
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : THA Screen Request
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return THA Screen Request
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */
static uint32_t THA_Counter;
static uint8_t THA_HARD_STATE;
static aSigConverter_E_THAScreenRequest_t aHmiM_STM_f_Get_THA_State_u(void)
{
  /* DD-ID: {4C2AFA2D-5EE6-4265-AAC5-0BA574607B4C}*/
  // if(THA_Counter>500)
  // {
  //   THA_HARD_STATE++;
  //   THA_Counter = 0;
  //   appLogPrintf("THA State: %d", THA_HARD_STATE);
  // }
  
  // THA_Counter++;
  // if(THA_HARD_STATE > THA_ERR_Msg2)
  // {
  //   THA_HARD_STATE = 0;
  // }
  // aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenRequest_e = THA_HARD_STATE;
  
  return aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenRequest_e;
}

static void PDC_Blinking()
{
  /* DD-ID: {5FF90243-513D-443e-8FE8-1492CF1A53DC}*/
  tick_count++;
  if(1 >= tick_count)
  {
    fast_tick = TRUE;
    slow_tick = TRUE;
  }
  else if(2 >= tick_count)
  {
    fast_tick = FALSE;
    slow_tick = TRUE;
  }
  else if(3 >= tick_count)
  {
    fast_tick = TRUE;
    slow_tick = FALSE;
  }
  else if(4 >= tick_count)
  {
    fast_tick = FALSE;
    slow_tick = FALSE;
    tick_count = 0;
  }
  else
  {
    /*Do nothing*/
  }

  return;
}

static BOOL aHmiM_STM_f_CheckViewTrigger_isValidTch_Within_Zone(void)
{
  /* DD-ID: {EB79929B-C4C1-4417-8271-011D11C197D8}*/
  return aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_Is_Valid_Tch_Zone;
}


static BOOL aHmiM_STM_f_CheckViewTrigger_THA_SFT_BTN_ZOUT_PRESSED_b(void)
{
  /* DD-ID: {A05B57BA-C2F6-41dc-9724-3FA156D17C82}*/
  BOOL retVal = FALSE;
  if (TRUE == aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b)
  {
    aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b = FALSE;
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/* ===============================================================
 * Purpose :  Sends THA Screen Set Response to THA SM
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input :
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output :
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static void aHmiM_STM_f_Send_THA_State_Response_u(void)
{
  /* DD-ID: {1968C108-DFAA-4337-A080-03A8D5B4E454}*/
  SvsToTHA_e.MeSVS_e_THAScrResp = M_Current_THA_State_On_Zync;
}

/* ===============================================================
 * Purpose :  Returns THA Screen Set Response from Codent
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : THA Screen Response
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return THA Screen Response
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static aSigConverter_E_THAScreenRequest_t aHmiM_STM_f_Get_THA_State_Response_u(void)
{
  /* DD-ID: {69571A84-04B1-44e9-B307-29D42A105B17}*/
  return aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_ScreenResponse_e;
}

/* ===============================================================
 * Purpose :  Requesting THA State Request to Zync
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static void aHmiM_STM_f_Request_THA_State_to_Zync_u(void)
{ 
  /* DD-ID: {40025824-DF02-43e9-9A61-662318AA3E93}*/
  screenReq.MeSVS_e_THAScreenRequesttoA72 = M_Requested_THA_State;
}

/* ===============================================================
 * Purpose : THis function calculates and  Returns Longitudinal distance in Pixels between coupler and hitch points
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : Hitch and Coupler Point
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Longitudinal distance in Pixels between coupler and hitch points
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static uint8 aHmiM_STM_f_Get_Coupler_Hitch_Distance_u(void)
{
  /* DD-ID: {020AFF19-B235-442d-818D-B97B213E39C3}*/
return aHmiM_STM_v_Rx_HmiMRelatedData_e.THA_LongHitchCplrDiff;
}

/* ===============================================================
 * Purpose :  Check THA Active Status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return THA Active Status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static BOOL aHmiM_STM_f_CheckViewGuard_GUARD_THA_Active_Status_b(void)
{
  /* DD-ID: {0A740B5C-A2F9-4110-919D-271C1C4110B2}*/
  BOOL retVal = FALSE;
  if ((THA_Enable < M_Current_THA_State_Received) && (M_Current_THA_State_Received <= THA_ERR_Msg2))
  {
    if (DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    {
      // THA should not be aborted if CVADAS is not on the HEAD UNIT (when CVADAS in taken off the glass).
      // M_THA_Abort_Req_b = TRUE;
    }
    retVal = TRUE;
  }
  else if ((THA_Default == M_Current_THA_State_Received) || (M_Current_THA_State_Received == THA_Enable) && (M_THA_Abort_Req_b == TRUE))
  {
    M_THA_Abort_Req_b = FALSE;
  }
  SvsToTHA_e.MeSVS_b_THAAbortReq = M_THA_Abort_Req_b;
  return retVal;
}

/* ===============================================================
 * Purpose :  Check THA Hitch Assist Present or not
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return THA Active Status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static BOOL aHmiM_STM_f_CheckViewTrigger_isTHAPresent_b(void)
{
  /* DD-ID: {14E567B9-45FE-4c69-83FF-1A31730A4D4D}*/
  BOOL retval = FALSE;
  if(aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TrlrHitchAssPres == 1U)
  {
    retval = TRUE;
  }
  return retval;
}

static void aHmiM_STM_Verify_Output_Change_THA(void)
{
  /* DD-ID: {24D2BD14-A1EA-49a6-9BF5-3B8779242360}*/
  if ((prev_SvsToTHADet_e.MeSVS_px_THACplrPosX == SvsToTHADet_e.MeSVS_px_THACplrPosX) && 
    (prev_SvsToTHADet_e.MeSVS_px_THACplrPosY == SvsToTHADet_e.MeSVS_px_THACplrPosY) &&
	  (prev_screenReq.MeSVS_px_CplrPosX  ==    screenReq.MeSVS_px_CplrPosX) &&
	  (prev_screenReq.MeSVS_px_CplrPosY  ==    screenReq.MeSVS_px_CplrPosY) &&
    (prev_screenReq.MeSVS_px_ScrnTchX  ==    screenReq.MeSVS_px_ScrnTchX) &&
	  (prev_screenReq.MeSVS_px_ScrnTchY  ==    screenReq.MeSVS_px_ScrnTchY) &&
	  (prev_screenReq.MeSVS_pct_ProgressBar ==   screenReq.MeSVS_pct_ProgressBar) &&
	  (prev_screenReq.MeSVS_e_THAScreenRequesttoA72    ==   screenReq.MeSVS_e_THAScreenRequesttoA72) &&
	  (prev_SvsToTHA_e.MeSVS_e_THAScrResp      == SvsToTHA_e.MeSVS_e_THAScrResp) &&
	  (prev_SvsToTHA_e.MeSVS_b_THASftBtnPrsdStsToTHA      == SvsToTHA_e.MeSVS_b_THASftBtnPrsdStsToTHA) &&
	  (prev_SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd      == SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd) &&
	  (prev_SvsToTHA_e.MeSVS_b_ImgDefeatReqSts      == SvsToTHA_e.MeSVS_b_ImgDefeatReqSts) &&
	  (prev_SvsToTHA_e.MeSVS_b_ViewZoomSts      == SvsToTHA_e.MeSVS_b_ViewZoomSts) &&
	  (prev_SvsToTHA_e.MeSVS_b_THAMnvrStartBtnPrsd      == SvsToTHA_e.MeSVS_b_THAMnvrStartBtnPrsd) &&
	  (prev_SvsToTHA_e.MeSVS_b_THAScrTchSts      == SvsToTHA_e.MeSVS_b_THAScrTchSts) &&
	  (prev_SvsToTHA_e.MeSVS_b_THAAbortReq      == SvsToTHA_e.MeSVS_b_THAAbortReq))
{
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_Updated_b = FALSE; 
}
else
{
    if((prev_screenReq.MeSVS_e_THAScreenRequesttoA72  != screenReq.MeSVS_e_THAScreenRequesttoA72)&&
    (SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd == TRUE))
    {
    SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd =FALSE;
    }
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_Updated_b = TRUE;
    if(memcmp(&prev_SvsToTHA_e, &SvsToTHA_e, sizeof(SvsToTHA_t))!=0)
    {
      SigMgr_PpSvsToTHA_SvsToTHA_t_Put(&SvsToTHA_e);
      memcpy(&prev_SvsToTHA_e, &SvsToTHA_e, sizeof(SvsToTHA_t));
    }

    if(memcmp(&prev_SvsToTHADet_e, &SvsToTHADet_e, sizeof(SvsToTHADet_t))!=0)
    {
      SigMgr_data_SvsToTHADet_t_Put(&SvsToTHADet_e);
      memcpy(&prev_SvsToTHADet_e, &SvsToTHADet_e, sizeof(SvsToTHADet_t));
    }

    // if(memcmp(&prev_screenReq, &screenReq, sizeof(ScreenRequest_t))!=0)
    // {
    //   SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq); //TODO "REVIEW AND REMOVE THIS FROM HERE"
    //   memcpy(&prev_screenReq, &screenReq, sizeof(ScreenRequest_t));
    // }
    
	  #ifdef THA_LOG_ENABLE
    appLogPrintf("THA struct changed");
    appLogPrintf("THA is Updated: %d",screenReq.MeSVS_e_THAScreenRequesttoA72);
    aHmiM_THA_Overlays_Debug();
    aHmiM_THA_Related_Debug();
    #endif        
}
}




/* ===============================================================
 * Purpose : Setting Overlay Bits when THA Is active
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :
 * =============================================================== */

static void aHmiM_STM_setting_Overlay_bits_THA(void)
{
  /* DD-ID: {B985E7AB-DFD6-4fa4-AD4A-8365D435E341}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b = TRUE; 
  switch (M_Current_THA_State_Received)
  {
  case THA_Default:
    break;
  case THA_Enable:
    break;
  case THA_TCS_Msg1:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_TriangleOverlay = TRUE;
    break;
  case THA_TCS_Msg2: 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b = TRUE;
    break;
  case THA_TCS_Msg3:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_CouplerBulletIcon = TRUE;
    break;
  case THA_TCS_Msg4:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton = TRUE;
    break;
  case THA_TCS_Msg5:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_StartButton = TRUE;
    break;
  case THA_SM_Msg1:
    break;
  case THA_SM_Msg2:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ProgressBar = TRUE;
    break;
  case THA_CM_Msg1:
    break;
  case THA_CM_Msg2:
    break;
  case THA_CM_Msg3:
    break;
  case THA_CM_Msg4:
    break;
  case THA_CM_Msg5:
    break;
  case THA_CM_Msg6:
    break;
  case THA_CM_Msg7:
    break;
  case THA_CM_Msg8:
    break;
  case THA_CM_Msg9:
    break;
  case THA_CM_Msg10:
    break;
  case THA_EOM_Msg1:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ProgressBar = TRUE;
    break;
  case THA_EOM_Msg2:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton = TRUE;
    break;
  case THA_EOM_Msg3:
    break;
  case THA_EOM_Msg4:
    break;
  case THA_ERR_Msg1:
    break;
  case THA_ERR_Msg2:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton = TRUE;
    break;
  default:
    break;
  }
}

static void aHmiM_STM_f_Update_User_Slctd_Cplr_Crdnts_THA_b(void)
{
  /* DD-ID: {AF6D897F-5929-4c79-B2AB-E8FA2ECEE5F1}*/
  if (M_Current_THA_State_Received == THA_TCS_Msg1)
  { 
    // appLogPrintf("HMI to THA CPLR <X=%d, Y=%d>\n", screenResponse.MeSVS_px_CplrPosX, screenResponse.MeSVS_px_CplrPosY);
    SvsToTHADet_e.MeSVS_px_THACplrPosX = screenResponse.MeSVS_px_CplrPosX;
    SvsToTHADet_e.MeSVS_px_THACplrPosY = screenResponse.MeSVS_px_CplrPosY;
  
  }
  return;
}

static void aHmiM_STM_f_Update_Bullet_Icon_Coordinates_b(void)
{
  /* DD-ID: {3CB9382A-A650-4076-AB72-078D795AF3E2} */

    screenReq.MeSVS_px_CplrPosX = aHmiM_STM_v_CPLR_POS_X_u;
    screenReq.MeSVS_px_CplrPosY = aHmiM_STM_v_CPLR_POS_Y_u;

  return;
}


static void aHmiM_STM_f_Update_Scrn_Pressed_Crdnts_b(void)
{   
  /* DD-ID: {58FC6453-4086-445f-B16E-F900F0FABB52}*/
  if(M_Current_THA_State_Received != THA_TCS_Msg1)
  {
  aHmiM_STM_v_SCRN_TCH_X_u = 0u;
  aHmiM_STM_v_SCRN_TCH_Y_u = 0u;
  }
  else
  {
    /*Do Nothing*/
  }
  screenReq.MeSVS_px_ScrnTchX = aHmiM_STM_v_SCRN_TCH_X_u;
  screenReq.MeSVS_px_ScrnTchY = aHmiM_STM_v_SCRN_TCH_Y_u;
  
  return;
}


static void aHmiM_STM_f_Update_Confirm_Btn_PRESSED_b(void)
{
  /* DD-ID: {E2D3CD1C-5EC6-4c4c-9BCF-F410E805D2A0}*/
  SvsToTHA_e.MeSVS_b_THAAbortReq = false;
  if (TRUE == aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b)
  {
    if((M_Current_THA_State_Received != THA_TCS_Msg3) && (M_Current_THA_State_Received != THA_EOM_Msg2) && (M_Current_THA_State_Received != THA_ERR_Msg2))
    {
    aHmiM_STM_v_CONFIRM_BTN_PRESSED_b = aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b;
    aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b = FALSE;
    }
    else
    {
      // Abort the session if the selected coupler location is outside the region, SV sends 0 in this case
      SvsToTHA_e.MeSVS_b_THAAbortReq = (screenResponse.MeSVS_px_CplrPosX == 0) && (screenResponse.MeSVS_px_CplrPosY == 0);
      aHmiM_STM_v_CONFIRM_BTN_PRESSED_b = aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b; 
    }
  }
  else
  {
    /*do nothing*/
  }
  if (TRUE == aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b)
  {
    if(M_Current_THA_State_Received != THA_TCS_Msg4)
    {
    aHmiM_STM_v_CONFIRM_BTN_PRESSED_b = aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b;
    aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b = FALSE;
    }
    else
    {
    aHmiM_STM_v_CONFIRM_BTN_PRESSED_b = aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b; 
    }
  }
  else
  { 
    /*do nothing*/
  }
  SvsToTHA_e.MeSVS_b_IsConfirmBtnPrsd = aHmiM_STM_v_CONFIRM_BTN_PRESSED_b;
  return;
}

static void aHmiM_STM_f_Update_Start_Btn_PRESSED_b(void)
{
  /* DD-ID: {BC709D63-7DB0-4828-8F4E-489F04F1ECF9}*/
  if (TRUE == aHmiM_STM_v_START_BTN_PRESSED_b)
  {
    if(M_Current_THA_State_Received != THA_TCS_Msg5)
    {
    aHmiM_STM_v_START_BTN_PRESSED_b = FALSE;
    SvsToTHA_e.MeSVS_b_THAMnvrStartBtnPrsd = FALSE;
    }
    else
    {
    SvsToTHA_e.MeSVS_b_THAMnvrStartBtnPrsd = TRUE;
    }
  }
  else
  { /*do nothing*/
  }
  return;
}

static void aHmiM_STM_f_Update_Zoom_View_Status_b(void)
{
  /* DD-ID: {E0C32770-866A-424d-AC24-8F2568EE8E42}*/
 M_Is_Valid_Tch_Zone = aHmiM_STM_f_CheckViewTrigger_isValidTch_Within_Zone();
 M_THA_View_Zoom_Or_Not = aHmiM_STM_f_CheckViewTrigger_THA_View_Zoom_Decision();
 aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b = aHmiM_STM_f_CheckViewTrigger_THA_SFT_BTN_ZOUT_PRESSED_b();
  if (TRUE == M_THA_View_Zoom_Or_Not)
  {
  aHmiM_STM_v_VIEW_ZOOM_STS_b = TRUE;
  }
  else if(aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b == TRUE)
  { 
  aHmiM_STM_v_VIEW_ZOOM_STS_b = FALSE; 
  }
  else
  {
   /*do nothing*/ 
  }
  if(M_Current_THA_State_Received == THA_Default || M_Current_THA_State_Received == THA_Enable || ((prev_M_Current_THA_State_Received != THA_TCS_Msg1) && (M_Current_THA_State_Received ==THA_TCS_Msg1)))
  {
    aHmiM_STM_v_VIEW_ZOOM_STS_b = FALSE;
  }
  prev_M_Current_THA_State_Received = M_Current_THA_State_Received;
  SvsToTHA_e.MeSVS_b_ViewZoomSts = aHmiM_STM_v_VIEW_ZOOM_STS_b;
  return;
}

static void aHmiM_STM_f_Update_THA_Sft_Btn_PRESSED_b(void)
{
  /* DD-ID: {E03E79F3-AE95-405e-B145-9CBE1797B9D1}*/
  if (TRUE == aHmiM_STM_v_THA_SFT_BTN_PRESSED_b)
  {
    if(M_Current_THA_State_Received != THA_Enable)
    {
    aHmiM_STM_v_THA_SFT_BTN_PRESSED_b = FALSE;
    SvsToTHA_e.MeSVS_b_THASftBtnPrsdStsToTHA = FALSE;
    }
    else
    {
    SvsToTHA_e.MeSVS_b_THASftBtnPrsdStsToTHA = TRUE;
    }
  }
  else
  { /*do nothing*/
  }
  return;
}

static void aHmiM_STM_f_Update_THA_Screen_Exit_PRESSED_b(void)
{
  /* DD-ID: {207F1EBC-1A12-47b4-ADB2-9C0FE92527A2}*/
if (TRUE == aHmiM_STM_v_THA_X_BTN_PRESSED_b)
  {
    if(M_Current_THA_State_Received == THA_Enable || M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_THA_X_BTN_PRESSED_b = FALSE;
    SvsToTHA_e.MeSVS_b_ImgDefeatReqSts = FALSE;
    }
    else
    {
    SvsToTHA_e.MeSVS_b_ImgDefeatReqSts = TRUE;
    }
  }
  else
  { /*do nothing*/
  }
  return;
}


static void aHmiM_STM_f_Update_THAScrnTch_PRESSED_b(void)
{
  /* DD-ID: {28F5339A-AE68-4627-B6B4-E86346FC14C2}*/
  if (TRUE == aHmiM_STM_v_VIEW_SCRN_TCH_STS_b)
  {
    if(M_Current_THA_State_Received != THA_TCS_Msg1)
    {
    aHmiM_STM_v_VIEW_SCRN_TCH_STS_b = FALSE;
    SvsToTHA_e.MeSVS_b_THAScrTchSts = FALSE;
    }
    else
    {
    SvsToTHA_e.MeSVS_b_THAScrTchSts = TRUE;
  }
}
  else
  { /*do nothing*/
  }
  return;
}


static BOOL aHmiM_STM_f_CheckViewTrigger_THA_Active_to_NotActive(void)
{
  /* DD-ID: {F794577D-3972-4b8e-B23E-29F15F2F3F72}*/
  BOOL retVal = FALSE;
  static BOOL old_THA_Active_Status = FALSE;

  if ((old_THA_Active_Status == TRUE) && (aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == FALSE))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  old_THA_Active_Status = aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status;

  return retVal;
}


static BOOL aHmiM_STM_f_CheckViewTrigger_THA_View_Zoom_Decision(void)
{
  /* DD-ID: {806F3D58-447F-4b18-852B-14AB9774CDBD}*/
  BOOL retVal = FALSE;
  static BOOL M_Old_Is_Valid_Tch_Zone = FALSE;

  if ((M_Old_Is_Valid_Tch_Zone == FALSE) && (M_Is_Valid_Tch_Zone == TRUE))
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }

  M_Old_Is_Valid_Tch_Zone = M_Is_Valid_Tch_Zone;

  return retVal;
}

	

/************************************************************************************************************/

/* ===============================================================
 * Purpose : While on the glass�in any CVPM view�with current gear state "Drive",
 * we should remain in the same view on changing the gear to Neutral and then to Drive.
 * To Update aHmiM_STM_v_M_DNDGear_e variable for Set/Unset
 * Update the MCUDebug0(0x351) Private CAN Message M_DNDGeare signal
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 526965, 526963
 * =============================================================== */
static void aHmiM_STM_update_M_DNDGear_b(void)
{
  /* DD-ID: {7B5DAE54-31B8-4763-A2D0-0989BBCD7537}*/
  BOOL GearChange_D_to_N = FALSE;
  static ME_Hydra2defs_E_ViewType_t CVPM_view_when_DND_Set = ME_Hydra2defs_OEM_E_NoView;
  static aSigConverter_E_PRND_STAT_t prev_prndStatus_e = PRND_STAT_SNA;
  static ME_Hydra2defs_E_DNDGear_t aHmiM_STM_v_M_PrevDNDGear_e = M_DNDGear_NotSet;
  static BOOL aHmiM_STM_v_ClrDNDGear_in_next_iteration = FALSE;

  if ((PRND_STAT_D == prev_prndStatus_e) && (PRND_STAT_N == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e))
  {
    GearChange_D_to_N = TRUE;
  }
  prev_prndStatus_e = aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e;

  if ((TRUE == GearChange_D_to_N) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) /*i.e. Video is on the glass*/
      && ((ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_RearCrossPathView == aHmiM_STM_v_M_SVC_View_e) || (ME_Hydra2defs_OEM_E_FrontCrossPathView == aHmiM_STM_v_M_SVC_View_e)))
  {
    aHmiM_STM_v_M_DNDGear_e = M_DNDGear_Set;
    CVPM_view_when_DND_Set = aHmiM_STM_v_M_SVC_View_e; /*retrieve CVPM current view to clear DND later if view is changed*/
  }
  else if (((M_DNDGear_Set == aHmiM_STM_v_M_DNDGear_e) && ((TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b)     /*Video goes off the glass i.e. [TGW_CAMERA_DISP_STAT != (0x4, 0x5, 0x6, 0x7)]*/
                                                           || (CVPM_view_when_DND_Set != aHmiM_STM_v_M_SVC_View_e) /*CVPM switches to another view*/
                                                           || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToNeutral_b))))
  {
    if (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToDrive_b)
    {
      /*Its gear change from N->D, so clear M_DNDGear variable in next iteration (i.e. after completing entry_checkView)
       * Because when M_DNDGear is Set before as mentioned in requirement 504873 - point b, then transition to
       * FVTV should not happen as per point c.
       */
      aHmiM_STM_v_ClrDNDGear_in_next_iteration = TRUE;
    }
    else
    {
      aHmiM_STM_v_M_DNDGear_e = M_DNDGear_NotSet;
    }
  }
  else if (TRUE == aHmiM_STM_v_ClrDNDGear_in_next_iteration)
  {
    aHmiM_STM_v_ClrDNDGear_in_next_iteration = FALSE;
    aHmiM_STM_v_M_DNDGear_e = M_DNDGear_NotSet;
  }
  else
  {
    /*Do nothing*/
  }

  if (aHmiM_STM_v_M_PrevDNDGear_e != aHmiM_STM_v_M_DNDGear_e)
  {
    aHmiM_STM_v_M_PrevDNDGear_e = aHmiM_STM_v_M_DNDGear_e;
    aHmiM_STM_f_Update_MCUDebug0_v();
  }

  return;
}

/* ===============================================================
 * Purpose :While on the glass�in any CVPM in FFCV view�with current gear state !Reverse,
 * we should change view to RVTV on changing the gear to Reverse and Set M_FFCLatch variable to 1.
 * To Update aHmiM_STM_v_M_FFCLatch_e variable for Set/Unset
 * Update the MCUDebug0(0x351) Private CAN Message M_FFCLatch signal
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : Return status
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id :- 529288 ,529290
 * =============================================================== */
static void aHmiM_STM_update_M_FFClatch_b(void)
{
  /* DD-ID: {B333F7ED-28DD-4b13-8E15-8E7E6FF4CD4B}*/
  static ME_Hydra2defs_E_ViewType_t prev_view = ME_Hydra2defs_OEM_E_NoView;
  static ME_Hydra2defs_E_FFClatch_t aHmiM_STM_v_M_PrevFFClatch_e = M_FFClatch_NotSet;

  if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToReversed_b) && (FALSE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) /*GUARD_13_b eq. to False means video is on the glass*/
      && ((ME_Hydra2defs_OEM_E_FrontFacingCameraView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view) && (ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_RequestedScreenByHmiM_s.view)))
  {
    aHmiM_STM_v_M_FFClatch_e = M_FFClatch_Set;
  }
  else if ((M_FFClatch_Set == aHmiM_STM_v_M_FFClatch_e) && (ME_Hydra2defs_OEM_E_RearTopView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view))
  {
    prev_view = ME_Hydra2defs_OEM_E_RearTopView;
  }
  else
  { /*do nothing*/
  }

  if ((M_FFClatch_Set == aHmiM_STM_v_M_FFClatch_e) &&
      ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearNotEqualToReverse_b) || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_13_b) || ((ME_Hydra2defs_OEM_E_RearTopView == prev_view) && (ME_Hydra2defs_OEM_E_RearTopView != aHmiM_STM_v_CurrentScreenOnZynqM_s.view))))
  {
    aHmiM_STM_v_M_FFClatch_e = M_FFClatch_NotSet;
    prev_view = ME_Hydra2defs_OEM_E_NoView;
  }
  else
  { /*do nothing*/
  }

  if (aHmiM_STM_v_M_FFClatch_e != aHmiM_STM_v_M_PrevFFClatch_e)
  {
    aHmiM_STM_v_M_PrevFFClatch_e = aHmiM_STM_v_M_FFClatch_e;
    aHmiM_STM_f_Update_MCUDebug0_v();
  }
  else
  { /*do nothing*/
  }
  return;
}

/* ENTRY EXIT DO Functions for Views */
static void aHmiM_STM_f_Entry_SystemONVideoOFF_v(void)
{
  /* DD-ID: {86505E5E-8E7B-4a24-B26C-E6BAACA5712C}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

/* ===============================================================
 * Purpose :Enable the Rear top view Soft button in Active state (RED),
 * Enable the Top view rear and Rear view dynamics
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_RearTopView_v(void)
{
  /* DD-ID: {5BD92551-A94F-40c5-A8B6-CA7171F3DFE0}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }
 
  /* Req Id - 518707 */
  /*Select Frame 2 and Top Rear view text*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Frameset1AndTopRearText_b = TRUE;

  /* Evaluate the Trajectories for the Rear and Front View */
  aHmiM_STM_f_EvaluateRearTopTrajectories_v();
  /* Evaluate TopView Overlay groups */
  aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
  /* Evaluate the XButton overlay */
  //aHmiM_STM_f_XButtonHandlingDefault(); /*Defect 290447, Task ID- 291139*/
  return;
}

/* ===============================================================
 * Purpose :Enable the Rear top view Soft button in Active state (RED),
 * Enable the Top view rear and Rear view dynamics
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_BUNRVOneCam_View_v(void)
{  
  /* DD-ID: {DFA13F13-BB14-45c3-B4BB-1248CE89D41B}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isOneCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }
  
  if(FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b        = TRUE;
  }
  else
  { 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Selectable_b = TRUE;
  }

  /* Req Id - 518707 */
  /*Select Frame 2 and Top Rear view text*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Frameset1AndTopRearText_b = FALSE;
  /* Evaluate the Trajectories for the Rear View */
  aHmiM_STM_f_EvaluateRVCNormalTrajectories_v();
  /* Evaluate the XButton overlay */
  //aHmiM_STM_f_XButtonHandlingDefault(); /*Defect 290447, Task ID- 291139*/
  /* Evaluate More Cams Overlay for Top + Rear view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate Aux Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();

  return;
}


/* ===============================================================
 * Purpose :Enable the Backup rear view Soft button in in Active state (RED)and
 * Enable the ZoomMinus icon
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_BUZRVOneCam_View_v(void)
{
  /* DD-ID: {4C5E68EF-33C5-4389-B233-310BFC8B358B}*/
    aHmiM_STM_v_ZoomFactor_u8 = 50;

      if(FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b        = TRUE;
      }
      else
      { 
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomMinus_Selectable_b = TRUE;
      }

    /*Default X-Button Handling*/
    /*Req ID 500485*/
    //aHmiM_STM_f_XButtonHandlingDefault(); /* X-Button & Icon handling (ImageDefeatRqst) - (X-Icon is the only Overlay which will be handled separately here)" */
    /* Evaluate More Cams Overlay for RVC Only Zoom view ; Req ID : 445682, 445337, 445679 */
    //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
    /* Evaluate Aux Cams Overlay */
    //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}


/* ===============================================================
 * Purpose :Enable the Front top view Soft button in Active state (RED),
 * Enable the Top view Front and Front view dynamics
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_FrontTopView_v(void)
{
  /* DD-ID: {A9A24BCD-F1AE-49a6-9457-55C436193A61}*/
  /* Req Id - 518707 */
  /*Select Frame 2 and Top Front view text*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Frameset1AndTopFrontText_b = TRUE;

  /* Evaluate the  FFCV soft Button overlay */
  //aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v();
  /* Evaluate the Trajectories for the Top and Front View */
  aHmiM_STM_f_EvaluateFrontTopTrajectories_v();
  /* Evaluate TopView Overlay groups */
  aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
  /* Evaluate the XButton overlay */
  //aHmiM_STM_f_XButtonHandlingDefault(); /*Defect 290447, Task ID- 291139*/
                                        /* Evaluate More Cams Overlay for Top + Front view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate More Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();

  return;
}

/* ===============================================================
 * Purpose :Enable the Rear cross view Soft button in Active state (RED),
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_RearCrossView_v(void)
{
  /* DD-ID: {510B57DE-60E4-4d43-B0AA-B824FAF683DA}*/
  /* Req Id - 518707 */
  /*Select Frame 2 and Rear cross view text*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Frameset2AndRearCrossText_b = TRUE;
  /* Evaluate the  FFCV soft Button overlay */
  //aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v();
  /* Evaluate the XButton overlay */
  //aHmiM_STM_f_XButtonHandlingDefault(); /*Defect 290447, Task ID- 291139*/
                                        /* Evaluate More Cams Overlay for Rear cross view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate AUX Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}

/* ===============================================================
 * Purpose :Enable the Front cross view Soft button in in Active state (RED),
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_FrontCrossView_v(void)
{
  /* DD-ID: {6CC58479-32AA-46c2-B326-527473C03437}*/
  /* Req Id - 518707 */
  /*Select Frame 2 and Rear cross view text*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Frameset2AndFrontCrossText_b = TRUE;

  /* Evaluate the  FFCV soft Button overlay */
  //aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v();
  /* Evaluate the XButton overlay */
  //aHmiM_STM_f_XButtonHandlingDefault(); /*Defect 290447, Task ID- 291139*/
  /* Evaluate More Cams Overlay for Front cross view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate AUX Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();

  return;
}

/* ===============================================================
 * Purpose :Enable the Backup rear view Soft button in in Active state (RED)and
 * Enable the ZoomPlus icon
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_RVCOnlyNormalView_v(void)
{
  /* DD-ID: {F6574069-9B7B-40d4-8860-42B9745C2088}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }

  /* Req Id - 518707 */
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b               = TRUE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b              = FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b          = FALSE;

    /* Evaluate the Zoom icon overlay  */
    aHmiM_STM_f_ZoomIcoHandlingSpeed_v();
    /* Evaluate the  RVC Normal trajectory overlay */
    aHmiM_STM_f_EvaluateRVCNormalTrajectories_v();
    /*Default X-Button Handling*/
    /*Req ID 500485*/
    //aHmiM_STM_f_XButtonHandlingDefault(); /* X-Button & Icon handling (ImageDefeatRqst) - (X-Icon is the only Overlay which will be handled separately here)" */
    /* Evaluate the  FFCV soft Button overlay */
    //aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v(); /* SRD 224741 (req id: 226454) */
                                                 /* Evaluate More Cams Overlay for RVC Only Normal view ; Req ID : 445682, 445337, 445679 */
    //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
    /* Evaluate Aux Cams Overlay */
    //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}
/* ===============================================================
 * Purpose :Enable the Backup rear view Soft button in in Active state (RED)and
 * Enable the ZoomMinus icon
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_RVCOnlyZoomView_v(void)
{
  /* DD-ID: {DF0B7C79-1C13-41e4-B7DC-C2C97834D321}*/
    aHmiM_STM_v_ZoomFactor_u8 = 50;

    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b = FALSE;
    /* Req Id - 518707 */

    /*Default X-Button Handling*/
    /*Req ID 500485*/
    //aHmiM_STM_f_XButtonHandlingDefault(); /* X-Button & Icon handling (ImageDefeatRqst) - (X-Icon is the only Overlay which will be handled separately here)" */
    /* Evaluate the  FFCV soft Button overlay */
    //aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v(); /* SRD 224741 (req id: 226454) */
    /* Evaluate More Cams Overlay for RVC Only Zoom view ; Req ID : 445682, 445337, 445679 */
    //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
    /* Evaluate Aux Cams Overlay */
    //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}



static void aHmiM_STM_f_Entry_TRG_View_v(void)
{
  /* DD-ID: {D3EE6726-076B-4e4c-AC35-B4B8294E0B5F}*/
  if((TRUE)
  && (ME_Hydra2defs_OEM_E_TRG_L50_R50 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L25_R75 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L75_R25 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L100_R0 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L0_R100 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  )
  {
    TRG_Latched = TRUE;

  }

  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MirroCamCenterPoint_b       = TRUE;
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonNoSelect_b = FALSE;
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonNoSelect_b = FALSE;
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonNoSelect_b = FALSE;
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonNoSelect_b = FALSE;
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b = FALSE;

  if(TRG_Stat == TRG_AUTO_PAN)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_Select_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_NoSelect_b = FALSE;
  }
  else if(TRG_Stat == TRG_MANU_PAN)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_Select_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_NoSelect_b = TRUE;
  }
  /* X-Button Icon handling and ImageDefeatRqst signal update handling*/
  //aHmiM_STM_f_XButtonHandlingDefault();

  /*TRG view is shown in Full Screen frameset(where footer is not present)
   * thus in full screen framset in-active state of MoreCam button has darker black backround vs
   * shown in other frameset
   */
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  /* Evaluate More Cams Overlay, Req ID : 487546, 487550, 488248, 488513, 496301 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MirroCamRightPoint2_b = TRUE;  /*Req. ID: 443557*/
  return;
}

/* ===============================================================
 * Purpose :Enable the FFCV view Soft button in in Active state (RED)and
 * Show other views Soft Buttons in Non Active(BLACK) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 518707
 * =============================================================== */
static void aHmiM_STM_f_Entry_FrontWithTiretracks_v(void)
{
  /* DD-ID: {A2191BC5-2CC9-4232-A1AC-640C7ED6B447}*/
  //aHmiM_STM_f_XButtonHandlingDefault();
  /* Evaluate the  FFCV Trajectory overlay */
  aHmiM_STM_f_EvaluateFFCVTrajectories_v();
  /* Evaluate More Cams Overlay for FrontWithTiretracks view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate Aux Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();

  return;
}

static void aHmiM_STM_f_Entry_TRA_View_v(void)
{
  /* DD-ID: {7E684E93-7CBF-4356-B909-BB503E5B818E}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  aHmiM_STM_v_M_TRA_View = TRUE;
}

static void aHmiM_STM_f_Entry_TRGLeftCurb_View_v(void)
{
  /* DD-ID: {DE3449B9-5445-49a7-A069-C91C39DD6E9C}*/
  // (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  //aHmiM_STM_f_XButtonHandlingDefault(); /* Req. - 306415 */

  /* Evaluate More Cams Overlay for TRG LeftCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  return;
}
static void aHmiM_STM_f_Entry_TRGRightCurb_View_v(void)
{
  /* DD-ID: {B44038F9-8C81-4767-AAEC-A356DB9771BB}*/

  // (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  //aHmiM_STM_f_XButtonHandlingDefault(); /* Req. - 306424 */
                                        /* Evaluate More Cams Overlay for TRGRightCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  return;
}

static void aHmiM_STM_f_Entry_BlindLeft_View_v(void)
{
  /* DD-ID: {6B3A97C8-46B7-403f-A4B7-0370C9B5D7D5}*/
  // (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  //aHmiM_STM_f_XButtonHandlingDefault(); /* Req. - 306415 */

  /* Evaluate More Cams Overlay for TRG LeftCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  return;
}
static void aHmiM_STM_f_Entry_BlindRight_View_v(void)
{
  /* DD-ID: {E8252766-72ED-4da1-8AD0-0CAE328AF869}*/

  // (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  //aHmiM_STM_f_XButtonHandlingDefault(); /* Req. - 306424 */
                                        /* Evaluate More Cams Overlay for TRGRightCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  return;
}

static void aHmiM_STM_f_Entry_Raw_View_v(void)
{
  /* DD-ID: {0A63D19C-8AAC-4386-8F93-6ECEDF535B97}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Entry_THANormalRearView_v(void)
{
  /* DD-ID: {9279B165-2003-4a68-B987-82372D471FC0}*/
 if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  {
   /*do nothing*/
  }
}

static void aHmiM_STM_f_Entry_THAZoomRearView1_v(void)
{
  /* DD-ID: {7DFC3BA8-6EB1-4307-B0B1-33042A53148D}*/
 if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  {
   /*do nothing*/
  }
}

static void aHmiM_STM_f_Entry_THAZoomRearView2_v(void)
{
  /* DD-ID: {3460E4A7-1567-4716-B4F7-6554CC59F741}*/
  if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  {
    /*do nothing*/
  }
}

static void aHmiM_STM_f_Entry_TSC_Aiming_View_v(void)
{
  /* DD-ID: {D51089B6-1218-4251-B7A6-4B9195A5F730}*/
  memcpy(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, &TSC_to_HMI.CalibScreen, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
}

static void aHmiM_STM_f_Exit_SystemONVideoOFF_v(void)
{
  /* DD-ID: {96C059C8-286C-4971-A702-969603AAE941}*/
  return;
}
static void aHmiM_STM_f_Exit_RearTopView_v(void)
{
  /* DD-ID: {2141DB3A-0114-49ae-9017-50CEC3CAFA54}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}
static void aHmiM_STM_f_Exit_FrontTopView_v(void)
{
  /* DD-ID: {9772DD89-6C16-459d-A6F9-50ED6AFA36D1}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}
static void aHmiM_STM_f_Exit_RearCrossView_v(void)
{
  /* DD-ID: {41B9935C-6A53-4149-8D26-B3827966F060}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}
static void aHmiM_STM_f_Exit_FrontCrossView_v(void)
{
  /* DD-ID: {F8E99F20-401E-448b-9AD7-B3F9F07BE479}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}
static void aHmiM_STM_f_Exit_RVCOnlyNormalView_v(void)
{
  /* DD-ID: {CECAFA10-1D6B-43eb-9B41-D797C911D93F}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return; /*297200*/
}
static void aHmiM_STM_f_Exit_RVCOnlyZoomView_v(void)
{
  /* DD-ID: {4128F331-26CF-4598-B195-5834264A2946}*/
  aHmiM_STM_v_ZoomFactor_u8 = 100;
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));

  return;
}
static void aHmiM_STM_f_Exit_BUNRVOneCam_View_v(void)
{
  /* DD-ID: {FE5527F3-D898-4497-AF5A-E32B22C49EB9}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return; /*297200*/
}
static void aHmiM_STM_f_Exit_BUZRVOneCam_View_v(void)
{
  /* DD-ID: {8EA71DEA-851F-4f4c-8640-8F8EBC8E52E7}*/
  aHmiM_STM_v_ZoomFactor_u8 = 100;
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}
static void aHmiM_STM_f_Exit_TRGV_v(void)
{
  /* DD-ID: {A251E6A4-63F2-45d0-8E82-BD2926E24534}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  if (
      aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_TRG_L50_R50 || aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_TRG_L25_R75 || aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_TRG_L75_R25 || aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_TRG_L100_R0 || aHmiM_STM_v_RequestedScreenByHmiM_s.view == ME_Hydra2defs_OEM_E_TRG_L0_R100)
  {
    // do nothing
  }
  else
  {
    TRG_Stat = TRG_INACTIVE;
  }
  return;
}

static void aHmiM_STM_f_Exit_FrontWithTiretracks_v(void)
{
  /* DD-ID: {8F4DBAFC-6DDB-4afd-83CF-127EADD262D6}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_TRA_View_v(void)
{
  /* DD-ID: {1D70314D-16A0-4796-B3F1-A7AE5730C303}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  aHmiM_STM_v_M_TRA_View = FALSE;
  return;
}

static void aHmiM_STM_f_Exit_TRGLeftCurb_View_v(void)
{
  /* DD-ID: {A50FD1BC-0CBD-404a-AB10-0B0D6DAF0A81}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_TRGRightCurb_View_v(void)
{
  /* DD-ID: {6D83F03A-8F88-4973-8F26-66B8AA483992}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_BlindLeft_View_v(void)
{
  /* DD-ID: {A8C465FC-51BF-45d8-A02A-7F9A24FF6DB2}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_BlindRight_View_v(void)
{
  /* DD-ID: {E5DB4BA6-77BD-494b-87E8-AE5BBE351850}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_TRG_View_v(void)
{
  /* DD-ID: {CF5785EF-7892-4096-A9D1-C85C91096DE2}*/
  if((TRUE)
  && (ME_Hydra2defs_OEM_E_TRG_L50_R50 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L25_R75 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L75_R25 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L100_R0 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  && (ME_Hydra2defs_OEM_E_TRG_L0_R100 != aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
  )
  {
    (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  }
  return;
}

static void aHmiM_STM_f_Exit_Raw_View_v(void)
{
  /* DD-ID: {4E32A8C5-8498-4d0a-8413-E201A62CD13C}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_THANormalRearView_v(void)
{
  /* DD-ID: {0E3234E2-2CE9-4ce4-BC98-764494FA6123}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_THAZoomRearView1_v(void)
{
  /* DD-ID: {139E1284-17EC-4b65-B1B7-D591058CC1B2}*/
  aHmiM_STM_v_ZoomFactor_u8 = 100;
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;
}

static void aHmiM_STM_f_Exit_THAZoomRearView2_v(void)
{
  /* DD-ID: {63562721-02D3-47b5-B564-4BF5F2A43939}*/
  aHmiM_STM_v_ZoomFactor_u8 = 100;
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));

  return;
}

static void aHmiM_STM_f_Exit_TSC_Aiming_View_v(void)
{
  /* DD-ID: {068BD273-2642-4298-BF6B-48B1E11D3D06}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  return;  
}

static void aHmiM_STM_f_Do_SystemONVideoOFF_v(void)
{
  /* DD-ID: {FA1C79A0-1FCD-4d6a-9EB7-B4B6CF239CD9}*/
  /* Nothing to do yet */
  return;
}
static void aHmiM_STM_f_Do_RearTopView_v(void)
{
  /* DD-ID: {4060D71F-4991-4010-8521-85506B6D790A}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }

  /* Evaluate the Trajectories for the Rear and Front View */
  aHmiM_STM_f_EvaluateRearTopTrajectories_v();
  /* Evaluate TopView Overlay groups (do "Vehicle Top View Graphics" in EA Document) */
  aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
  return;
}
static void aHmiM_STM_f_Do_FrontTopView_v(void)
{
  /* DD-ID: {47410B36-25F6-4ee0-A2A9-1FE37A76DEA3}*/
  /* Evaluate the Trajectories for the Top and Front View */
  aHmiM_STM_f_EvaluateFrontTopTrajectories_v();
  /* Evaluate TopView Overlay groups (do "Vehicle Top View Graphics" in EA Document) */
  aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
  /* Evaluate More Cams Overlay for Front + Rear view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate Aux Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();

  return;
}
static void aHmiM_STM_f_Do_RearCrossView_v(void)
{
  /* DD-ID: {EE2CA738-57E4-42f2-9817-3EC63F236D43}*/
  /* Evaluate More Cams Overlay for Rear cross view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate Aux Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}
static void aHmiM_STM_f_Do_FrontCrossView_v(void)
{
  /* DD-ID: {70ADC9E2-260F-4a4b-ABAC-EC7EFC6FF5D3}*/
  /* Evaluate More Cams Overlay for Rearcross view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate Aux Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}

static void aHmiM_STM_f_Do_RVCOnlyNormalView_v(void)
{
  /* DD-ID: {4FA924D0-CD94-4fd2-8037-C10EE9B6C91E}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }

   /* Evaluate the Zoom icon overlay  */
  aHmiM_STM_f_ZoomIcoHandlingSpeed_v();
  /* Evaluate the  RVC Trajectories overlay */
  aHmiM_STM_f_EvaluateRVCNormalTrajectories_v();
  /* Evaluate More Cams Overlay for RVCOnlyNormal view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate More Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}

static void aHmiM_STM_f_Do_BUNRVOneCam_View_v(void)
{
  /* DD-ID: {D5AD4714-C5E5-4e7e-8CA7-562B9D961F66}*/
  if ((TRUE == aHmiM_STM_v_GearReverse_Delayed_b) && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isOneCamPresent)  && (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.isTHAPresent))
  {
    if(M_Current_THA_State_Received == THA_Default)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    }
    else if(M_Current_THA_State_Received == THA_Enable)
    {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
    } 
    else
    {
     /*Do Nothing*/
    } 
  }
  else if ((TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey          = FALSE;
  }
  else
  {
    /*Do Nothing*/
  }
 
  /* Evaluate the Zoom icon overlay  */
  aHmiM_STM_f_ZoomIcoHandlingSpeed_v();
  /* Evaluate the  RVC Trajectories overlay */
  aHmiM_STM_f_EvaluateRVCNormalTrajectories_v();
  /* Evaluate More Cams Overlay for RVCOnlyNormal view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate More Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}

static void aHmiM_STM_f_Do_RVCOnlyZoomView_v(void)
{
  /* DD-ID: {55CE21EC-CA91-453e-8CFA-166B104C7916}*/
    /* Evaluate More Cams Overlay for RVCOnlyZoom view ; Req ID : 445682, 445337, 445679 */
    //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
    /* Evaluate More Cams Overlay */
    //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}

static void aHmiM_STM_f_Do_BUZRVOneCam_View_v(void)
{
  /* DD-ID: {73D203BA-D66C-4d83-A008-E206F30AF1B3}*/
    /* Evaluate More Cams Overlay for RVCOnlyZoom view ; Req ID : 445682, 445337, 445679 */
    //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
    /* Evaluate More Cams Overlay */
    //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}
static void aHmiM_STM_f_Do_FrontWithTiretracks_v(void)
{
  /* DD-ID: {123CC001-7637-447f-9F6B-25983204D615}*/
  /* Evaluate the  FFCV Trajectories overlay */
  aHmiM_STM_f_EvaluateFFCVTrajectories_v();
  /* Evaluate More Cams Overlay for FrontWithTiretracks view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /* Evaluate More Cams Overlay */
  //aHmiM_STM_f_HandleAuxOverlay_v();
  return;
}
static void aHmiM_STM_f_Do_TRA_View_v(void)
{
  /* DD-ID: {CB51DBD4-CCD7-4e0e-AB85-DC9974E28933}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b = FALSE;
  return;
}

static void aHmiM_STM_f_Do_TRGLeftCurb_View_v(void)
{
  /* DD-ID: {57A4A60B-D82A-4792-A6DB-B6813AFBCD33}*/
  /* Evaluate More Cams Overlay for TRGLeftCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /*To dispaly MoreCam button in TRG view InActive state */
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;
  /* Req. - 306415 */
  //aHmiM_STM_f_XButtonHandlingDefault();

  return;
}
static void aHmiM_STM_f_Do_TRGRightCurb_View_v(void)
{
  /* DD-ID: {5CB6A926-6C3A-4b7c-991C-631E86E03165}*/
  /* Evaluate More Cams Overlay for TRGRightCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /*To dispaly MoreCam button in TRG view InActive state */
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;
  /* Req. - 306415 */
  //aHmiM_STM_f_XButtonHandlingDefault();

  return;
}

static void aHmiM_STM_f_Do_BlindLeft_View_v(void)
{
  /* DD-ID: {E04D9940-C3D3-4153-AD1B-626B12A50A1B}*/
  /* Evaluate More Cams Overlay for TRGLeftCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /*To dispaly MoreCam button in TRG view InActive state */
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;
  /* Req. - 306415 */
  //aHmiM_STM_f_XButtonHandlingDefault();

  return;
}
static void aHmiM_STM_f_Do_BlindRight_View_v(void)
{
  /* DD-ID: {A7230F41-60F6-407d-A7EE-CACD362EAF50}*/
  /* Evaluate More Cams Overlay for TRGRightCurb view ; Req ID : 445682, 445337, 445679 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();
  /*To dispaly MoreCam button in TRG view InActive state */
  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;
  /* Req. - 306415 */
  //aHmiM_STM_f_XButtonHandlingDefault();

  return;
}

static void aHmiM_STM_f_Do_TRG_View_v(void)
{
  /* DD-ID: {1AED52F4-4718-47c5-A435-F919E9D91F2A}*/
  /* X-Button Icon handling and ImageDefeatRqst signal update handling*/
  //aHmiM_STM_f_XButtonHandlingDefault();

  /* Evaluate More Cams Overlay, Req ID : 487546, 487550, 488248, 488513, 496301 */
  //aHmiM_STM_f_EvaluateMoreCamsOverlay_v();

  if(TRG_Stat == TRG_AUTO_PAN)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_Select_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_NoSelect_b = FALSE;
  }
  else if(TRG_Stat == TRG_MANU_PAN)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_Select_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.Auto_NoSelect_b = TRUE;
  }

  //aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;

  return;
}



static void aHmiM_STM_f_Do_Raw_View_v(void)
{
  /* DD-ID: {568E2DD0-9A7D-420f-BC3C-ACFEC93B4CCA}*/
  // Do Nothing
  return;
}


static void aHmiM_STM_f_Do_THANormalRearView_v(void)
{
  /* DD-ID: {8A7CF892-5FA7-4cb6-947C-1512570B4C69}*/
  if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  { 
    /* Do Nothing */  
  }
}


static void aHmiM_STM_f_Do_THAZoomRearView1_v(void)
{
  /* DD-ID: {C94A76AC-5718-4711-8AA7-E9DB2278EB9E}*/
 if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  {
   /*do nothing*/
  }
}

static void aHmiM_STM_f_Do_THAZoomRearView2_v(void)
{
  /* DD-ID: {D944C095-464E-432e-B996-81AF22BB0693}*/
 if(aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
  {
    aHmiM_STM_setting_Overlay_bits_THA();
  }
  else
  {
   /*do nothing*/
  }
}

static void aHmiM_STM_f_Do_TSC_Aiming_View_v(void)
{
  /* DD-ID: {83D21D0E-2F0C-4b29-8CEB-4A2B640B7D10}*/
  aHmiM_STM_f_Entry_TSC_Aiming_View_v();
  return;  
}

/* ######################################################################################################
 * --- HELPERS ---
 * ###################################################################################################### */

static BOOL aHmiM_STM_f_Is_BTN_PRESSED_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16)
{
  /* DD-ID: {76919FB4-7DA0-40d7-B78B-9CB6670D5C07}*/
  BOOL retVal = FALSE;
  if (
      ((i_Xmin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16) && (i_Xmax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16)) &&
      ((i_Ymin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16) && (i_Ymax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16))

      && ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) ||
          (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) /*CVPM Video is displayed on the screen*/
          ))
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static BOOL aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16)
{
  /* DD-ID: {70E48453-F8E7-41b3-8809-825598F0F64C}*/
  BOOL retVal = FALSE;
  if (
         ((i_Xmin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16)  && (i_Xmax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16)) 
      && ((i_Ymin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16)  && (i_Ymax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16)) 
      && (ME_Hydra2defs_OEM_E_NoView != aHmiM_STM_v_CurrentScreenOnZynqM_s.view) && ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)) /*CVPM Video is displayed on the screen*/
    )
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

/*Requirement ID - */
static BOOL aHmiM_STM_f_Is_BTN_PRESSED_IF_MC_VISIBLE_b(u16 i_Xmin_u16, u16 i_Xmax_u16, u16 i_Ymin_u16, u16 i_Ymax_u16)
{
  /* DD-ID: {393C807C-7FAC-4462-9555-32C96F3E02C0}*/
  BOOL retVal = FALSE;
  if (
      ((i_Xmin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16) && (i_Xmax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16)) &&
      ((i_Ymin_u16 <= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16) && (i_Ymax_u16 >= aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16)) &&
      (ME_Hydra2defs_OEM_E_NoView != aHmiM_STM_v_CurrentScreenOnZynqM_s.view) && ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) || (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))&&
      ((TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton1NoSelect_b) || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton2NoSelect_b) || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsIconFullScreenNoSelect_b))) /*More Cams button is visible on screen*/
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }
  return retVal;
}

static void aHmiM_STM_f_EvaluateCamsNA_v(void)
{
  /* DD-ID: {98D8BFE6-1C18-4ad1-80DC-D99A56C40CC9}*/
  //appLogPrintf("LIMMode7 = %d, LIMMode8 = %d, LIMMode9 = %d, LIMMode10 = %d\n", aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7,aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8,aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9, aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10);
  if (0x01 == (aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod9))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftCam_NA_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftCam_NA_b = FALSE;
  }
  if (0x01 == (aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod10))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightCam_NA_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightCam_NA_b = FALSE;
  }
  if (0x01 == (aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod8))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCam_NA_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCam_NA_b = FALSE;
  }
  if (0x01 == (aHmiM_STM_v_Rx_HmiMRelatedData_e.MeFID_SVS_LIMMod7))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackCam_NA_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackCam_NA_b = FALSE;
  }

  return;
}

static BOOL aHmiM_STM_f_K_TDelayPRND_GearToReverse_b(void)
{
  /* DD-ID: {C82726F9-B457-4135-A616-05E85F357BC5}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGtoR_u64 = 0llu;
  static BOOL v_startDelayGtoR_b = FALSE;

  if (TRUE == aHmiM_STM_v_Reverse_RisingEdge_b)
  {
    v_startDelayGtoR_b = TRUE;
  }
  else if (TRUE == aHmiM_STM_v_Reverse_FallingEdge_b)
  {
    v_startDelayGtoR_b = FALSE;
    v_tDelayGtoR_u64 = 0llu;
  }
  else
  {
    /* Do nothing */
  }

  if ((TRUE == v_startDelayGtoR_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGtoR_u64))
  {
    v_tDelayGtoR_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  {
    /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGtoR_u64)
  {
    retVal = TRUE;
    v_startDelayGtoR_b = FALSE;
    v_tDelayGtoR_u64 = 0llu;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_K_TDelayPRND_GearToPark_b(void)
{
  /* DD-ID: {82CB5182-DAE0-4366-AA73-F1CE873B8E28}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGtoP_u64 = 0llu;
  static BOOL v_startDelayGtoP_b = FALSE;

  if (TRUE == aHmiM_STM_v_Park_RisingEdge_b)
  {
    v_startDelayGtoP_b = TRUE;
  }
  else if (TRUE == aHmiM_STM_v_Park_FallingEdge_b)
  {
    v_startDelayGtoP_b = FALSE;
    v_tDelayGtoP_u64 = 0llu;
  }
  else
  {
    /* Do nothing */
  }

  if ((TRUE == v_startDelayGtoP_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGtoP_u64))
  {
    v_tDelayGtoP_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  {
    /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGtoP_u64)
  {
    retVal = TRUE;
    v_startDelayGtoP_b = FALSE;
    v_tDelayGtoP_u64 = 0llu;
  }
  return retVal;
}
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToNeutral_b(void)
{
  /* DD-ID: {2E12008E-0786-4f0b-8ACD-73D1B134C92A}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGtoN_u64 = 0llu;
  static BOOL v_startDelayGtoN_b = FALSE;

  if (TRUE == aHmiM_STM_v_Neutral_RisingEdge_b)
  {
    v_startDelayGtoN_b = TRUE;
  }
  else if (TRUE == aHmiM_STM_v_Neutral_FallingEdge_b)
  {
    v_startDelayGtoN_b = FALSE;
    v_tDelayGtoN_u64 = 0llu;
  }
  else
  {
    /* Do nothing */
  }

  if ((TRUE == v_startDelayGtoN_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGtoN_u64))
  {
    v_tDelayGtoN_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  {
    /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGtoN_u64)
  {
    retVal = TRUE;
    v_startDelayGtoN_b = FALSE;
    v_tDelayGtoN_u64 = 0llu;
  }
  return retVal;
}
static BOOL aHmiM_STM_f_K_TDelayPRND_GearToDrive_b(void)
{
  /* DD-ID: {94D14B91-B2E6-49e5-9A3E-DE4C9400662C}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGtoD_u64 = 0llu;
  static BOOL v_startDelayGtoD_b = FALSE;

  if (TRUE == aHmiM_STM_v_Drive_RisingEdge_b)
  {
    v_startDelayGtoD_b = TRUE;
  }
  else if (TRUE == aHmiM_STM_v_Drive_FallingEdge_b)
  {
    v_startDelayGtoD_b = FALSE;
    v_tDelayGtoD_u64 = 0llu;
  }
  else
  {
    /* Do nothing */
  }

  if ((TRUE == v_startDelayGtoD_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGtoD_u64))
  {
    v_tDelayGtoD_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  {
    /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGtoD_u64)
  {
    retVal = TRUE;
    v_startDelayGtoD_b = FALSE;
    v_tDelayGtoD_u64 = 0llu;
  }
  return retVal;
}

static BOOL aHmiM_STM_f_K_TDelayPRND_GearNotReverse_b(void)
{
  /* DD-ID: {46D0566A-8790-487a-AEE7-45BDEF42C8CD}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGtoNR_u64 = 0llu;
  static BOOL v_startDelayGtoNR_b = FALSE;

  if (REV_GEAR_NOT_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)
  {
    v_startDelayGtoNR_b = TRUE;
  }
  else if (REV_GEAR_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)
  {
    v_startDelayGtoNR_b = FALSE;
    v_tDelayGtoNR_u64 = 0llu; /* reset the timer once shifted in reverse again */
  }
  else
  { /* Do nothing */
  }

  if ((TRUE == v_startDelayGtoNR_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGtoNR_u64))
  {
    v_tDelayGtoNR_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  { /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGtoNR_u64)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }

  return retVal;
}

static BOOL aHmiM_STM_f_K_TDelayPRND_GearReverse_b(void)
{
  /* DD-ID: {2D5BA75C-7C2F-4c98-ADEE-38FF9655695F}*/
  BOOL retVal = FALSE;
  static uint64_t v_tDelayGR_u64 = 0llu;
  static BOOL v_startDelayGR_b = FALSE;

  if (REV_GEAR_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)
  {
    v_startDelayGR_b = TRUE;
  }
  else if (REV_GEAR_NOT_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)
  {
    v_startDelayGR_b = FALSE;
    v_tDelayGR_u64 = 0llu; /* reset the timer once shifted in reverse again */
  }
  else
  { /* Do nothing */
  }

  if ((TRUE == v_startDelayGR_b) && (aHmiM_STM_v_K_TDelayPRND_u64 > v_tDelayGR_u64))
  {
    v_tDelayGR_u64 = EndTimeDelayPRND - StartTimeDelayPRND;
  }
  else
  { /* Do nothing */
  }

  if (aHmiM_STM_v_K_TDelayPRND_u64 <= v_tDelayGR_u64)
  {
    retVal = TRUE;
  }
  else
  { /*do nothing*/
  }

  return retVal;
}

static void aHmiM_STM_f_GearEdgeDetection_v(void)
{
  /* DD-ID: {F28956A0-C406-4ee4-A726-B151E2CDEAE3}*/
  static aSigConverter_E_REV_GEAR_t revGearOld = REV_GEAR_NOT_ENGAGED; /* Set initially to RevGear not engaged */
  aSigConverter_E_REV_GEAR_t revGearActual = aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e;

  static aSigConverter_E_PRND_STAT_t prndStatOld = PRND_STAT_SNA; /* Set initially to Invalid */
  aSigConverter_E_PRND_STAT_t prndStatActual = aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e;

  /* Gear Edge Detection */
  aHmiM_STM_v_Reverse_RisingEdge_b = FALSE;
  aHmiM_STM_v_Reverse_FallingEdge_b = FALSE;
  aHmiM_STM_v_Park_RisingEdge_b = FALSE;
  aHmiM_STM_v_Park_FallingEdge_b = FALSE;
  aHmiM_STM_v_Neutral_RisingEdge_b = FALSE;
  aHmiM_STM_v_Neutral_FallingEdge_b = FALSE;
  aHmiM_STM_v_Drive_RisingEdge_b = FALSE;
  aHmiM_STM_v_Drive_FallingEdge_b = FALSE;

  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e)
  {
  case TRANS_MANUAL:
  {
    /* Manual Transmission - Reverse Gear (Separate Signal) */
    if (revGearActual != revGearOld)
    {
      switch (revGearActual)
      {
      case REV_GEAR_ENGAGED:
        aHmiM_STM_v_Reverse_RisingEdge_b = TRUE;
        revGearOld = REV_GEAR_ENGAGED;
        break;
      case REV_GEAR_NOT_ENGAGED:
        aHmiM_STM_v_Reverse_FallingEdge_b = TRUE;
        revGearOld = REV_GEAR_NOT_ENGAGED;
        break;
      default:
        break;
      }
    }
    else
    { /*Do nothing*/
    }
    break;
  }
  case TRANS_AUTOMATIC:
  {
    /* Automatic Transmission - P(R)ND Edges */
    if (prndStatActual != prndStatOld)
    {
      /* We had some Gear Change! Trigger the corresponding Rising and Falling Edges */
      /* Trigger Falling Edges */
      StartTimeDelayPRND = TimerP_getTimeInUsecs();
      EndTimeDelayPRND = StartTimeDelayPRND;
      switch (prndStatOld)
      {
      case PRND_STAT_P:
        aHmiM_STM_v_Park_FallingEdge_b = TRUE;
        break;
      case PRND_STAT_N:
        aHmiM_STM_v_Neutral_FallingEdge_b = TRUE;
        break;
      case PRND_STAT_D:
        aHmiM_STM_v_Drive_FallingEdge_b = TRUE;
        break;
      case PRND_STAT_R:
        aHmiM_STM_v_Reverse_FallingEdge_b = TRUE;
        break;
      case PRND_STAT_NOT_R:
      case PRND_STAT_SNA:

      default:
        break;
      }
      /* Trigger Rising Edges */
      switch (prndStatActual)
      {
      case PRND_STAT_P:
        aHmiM_STM_v_Park_RisingEdge_b = TRUE;
        prndStatOld = PRND_STAT_P;
        break;
      case PRND_STAT_N:
        aHmiM_STM_v_Neutral_RisingEdge_b = TRUE;
        prndStatOld = PRND_STAT_N;
        break;
      case PRND_STAT_D:
        aHmiM_STM_v_Drive_RisingEdge_b = TRUE;
        prndStatOld = PRND_STAT_D;
        break;
      case PRND_STAT_R:
        aHmiM_STM_v_Reverse_RisingEdge_b = TRUE;
        prndStatOld = PRND_STAT_R;
        break;
      case PRND_STAT_NOT_R:
        prndStatOld = PRND_STAT_NOT_R;
        break;
      case PRND_STAT_SNA:

      default:
        prndStatOld = PRND_STAT_SNA;
        break;
      }
    }
    else
    { /*No Gear Change - Do nothing*/
      EndTimeDelayPRND = TimerP_getTimeInUsecs();
    }
    break;
  }
  default:
    break;
  }
  return;
}

static void aHmiM_STM_f_GearDelayDetection_v(void)
{
  /* DD-ID: {170FFA85-9CD0-4ff8-929C-2ABC29FA27CE}*/
  static aHmiM_STM_e_SwitchToGearDetection_t aHmiM_STM_v_SwitchToGear_lastValidViewTrigger_e = aHmiM_STM_e_None;
  /* Separate handling to check if we are not in reverse anymore (+ delay) - X-Button handling */
  if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearNotReverse_b())
  {
    aHmiM_STM_v_GearNotReverse_Delayed_b = TRUE; /* Set the Variable which is indicating that we are currently not in Reverse */
  }
  else
  {
    aHmiM_STM_v_GearNotReverse_Delayed_b = FALSE; /* When we go to Reverse Reset the Variable which is indicating that we are currently not in Reverse */
  }
  /* Separate handling to check if we are in reverse (+ delay) - X-Button handling */
  if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearReverse_b())
  {
    aHmiM_STM_v_GearReverse_Delayed_b = TRUE; /* Set the Variable which is indicating that we are currently in Reverse */
  }
  else
  {
    aHmiM_STM_v_GearReverse_Delayed_b = FALSE; /* When we go away from Reverse, Reset the Variable which is indicating that we are currently in Reverse */
  }

  if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearToReverse_b())
  {
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_Reverse;
    curValidGearReq = PRND_STAT_R;
  }
  else if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearToPark_b())
  {
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_Park;
    curValidGearReq = PRND_STAT_P;
  }
  else if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearToNeutral_b())
  {
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_Neutral;
    curValidGearReq = PRND_STAT_N;
  }
  else if (TRUE == aHmiM_STM_f_K_TDelayPRND_GearToDrive_b())
  {
    aHmiM_STM_v_SwitchToGear_ViewTrigger_e = aHmiM_STM_e_Drive;
    curValidGearReq = PRND_STAT_D;
  }

  else
  { /* do nothing */
  }
  if((aHmiM_STM_v_SwitchToGear_lastValidViewTrigger_e != aHmiM_STM_v_SwitchToGear_ViewTrigger_e) && (aHmiM_STM_e_None != aHmiM_STM_v_SwitchToGear_ViewTrigger_e))
  {

    switch(aHmiM_STM_v_SwitchToGear_lastValidViewTrigger_e)
    {
      case aHmiM_STM_e_Reverse:
      {
        lastValidGearReq = PRND_STAT_R;
        break;
      }
      case aHmiM_STM_e_Park:
      {
        lastValidGearReq = PRND_STAT_P;
        break;
      }
      case aHmiM_STM_e_Neutral:
      {
        lastValidGearReq = PRND_STAT_N;
        break;
      }
      case aHmiM_STM_e_Drive:
      {
        lastValidGearReq = PRND_STAT_D;
        break;
      }
      default:
      {
        ;
      }
    }
    aHmiM_STM_v_SwitchToGear_lastValidViewTrigger_e = aHmiM_STM_v_SwitchToGear_ViewTrigger_e;
  
  }
  
  return;
}

static void aHmiM_STM_f_MonitorTchScrn_v(void)
{
  /* DD-ID: {D29A22F8-3963-473d-98C9-CC92C5DE750C}*/
  static aSigConverter_E_CM_TCH_STAT_t tchStatOld = CM_TCH_STAT_SNA; /* Set initially to Invalid */
  aSigConverter_E_CM_TCH_STAT_t tchStatActual = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnStatus_e;
  if (tchStatActual != tchStatOld)
  {
    switch (tchStatActual)
    {
    case TCH_PSD:
      if (TRUE == AP_HMI_Active_Status)
      {
        AP_HMI_Touch_Processing();
      }
      else if (aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status == TRUE)
      {
        if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_XBTN_X_MIN_COORD,
                                                            AHMIM_STM_D_XBTN_X_MAX_COORD,
                                                            AHMIM_STM_D_XBTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_XBTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.XIcon_b)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          aHmiM_STM_v_THA_X_BTN_PRESSED_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD)) &&
            (THA_TCS_Msg1 == M_Current_THA_State_Received)  && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.THA_TriangleOverlay)) /* If current THA State is 02u*/
        {
          aHmiM_STM_v_CPLR_POS_X_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16;
          aHmiM_STM_v_CPLR_POS_Y_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16;
          aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b = FALSE;
          aHmiM_STM_v_VIEW_SCRN_TCH_STS_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_ZMOUT_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_ZMOUT_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_ZMOUT_PRSD_Y_MAX_COORD))

                 && (THA_TCS_Msg2 == M_Current_THA_State_Received) && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.ZoomMinus_Selectable_b)) /* If current THA State is 02u*/
        {
          aHmiM_STM_v_THA_ZOOM_OUT_BTN_PRESSED_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD))

                 && (THA_TCS_Msg2 == M_Current_THA_State_Received)) /* If current THA State is 02u*/
        {
          aHmiM_STM_v_VIEW_SCRN_TCH_STS_b = TRUE; /*Coupler is selected on Screen*/
          aHmiM_STM_v_CPLR_POS_X_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16;
          aHmiM_STM_v_CPLR_POS_Y_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16;
          
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_SCRN_TCH_PRSD_Y_MAX_COORD))

                 && (THA_TCS_Msg3 == M_Current_THA_State_Received)) /* If current THA State is 04u*/
        {   
          aHmiM_STM_v_CPLR_POS_Y_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.Y_u16;
          aHmiM_STM_v_CPLR_POS_X_u = aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoord_s.X_u16;
        }
        /* Check if THA Start Button is pressed on screen */
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_START_BTN_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_START_BTN_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_START_BTN_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_START_BTN_PRSD_Y_MAX_COORD))

                 && (THA_TCS_Msg5 == M_Current_THA_State_Received) && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.THA_StartButton))
        {
          aHmiM_STM_v_START_BTN_PRESSED_b = TRUE; /*Start-Button is pressed*/
        }

        /* Check if Confirm Button is pressed on screen */
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD))

                 && ((THA_TCS_Msg3 == M_Current_THA_State_Received) || (THA_EOM_Msg2 == M_Current_THA_State_Received) || (THA_ERR_Msg2 == M_Current_THA_State_Received))
                 && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.THA_ConfirmButton))
        {
          aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b = TRUE; /*Confirm-Button is pressed*/
          aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b = FALSE;
        }
                /* Check if Confirm Button is pressed on screen */
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MIN_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_X_MAX_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MIN_COORD,
                                                                  AHMIM_STM_D_THA_CNFRM_BTN_PRSD_Y_MAX_COORD))

                 && (THA_TCS_Msg4 == M_Current_THA_State_Received) /* If current THA State is 05u*/
                 && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.THA_ConfirmButton))
        {
          aHmiM_STM_v_CONFIRM_BTN_PRESSED_A_b = FALSE; /*Confirm-Button is pressed*/
          aHmiM_STM_v_CONFIRM_BTN_PRESSED_B_b = TRUE;
        }
        else
        {
          /* Do NOthing */
        }
      }
      /*Check if THA Soft Button was pressed*/
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_THA_BTN_PRSD_X_MIN_COORD,
                                                     AHMIM_STM_D_THA_BTN_PRSD_X_MAX_COORD,
                                                     AHMIM_STM_D_THA_BTN_PRSD_Y_MIN_COORD,
                                                     AHMIM_STM_D_THA_BTN_PRSD_Y_MAX_COORD))   /* THA Soft Button is pressed*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.THA_ButtonSelectable)) /* THA SftBtn shown */
      {
        aHmiM_STM_v_THA_SFT_BTN_PRESSED_b = TRUE;
        aHmiM_STM_v_M_View_Before_THA_Active_e = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
      }
      /*for TRG only*/
      else if (DisplayView3_View9 == Tx_HmiView)
      {
        if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_TRGLEFT_X_MIN_COORD,
                                                  AHMIM_STM_D_TRGLEFT_X_MAX_COORD,
                                                  AHMIM_STM_D_TRGLEFT_Y_MIN_COORD,
                                                  AHMIM_STM_D_TRGLEFT_Y_MAX_COORD)) &&
            (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)) /*Soft Buttons are not Disabled*/
        {
          aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_TRGRIGHT_X_MIN_COORD,
                                                       AHMIM_STM_D_TRGRIGHT_X_MAX_COORD,
                                                       AHMIM_STM_D_TRGRIGHT_Y_MIN_COORD,
                                                       AHMIM_STM_D_TRGRIGHT_Y_MAX_COORD)) /*ZoomMinus Button is pressed*/
                 && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b))                             /*Soft Buttons are not Disabled*/

        {
          aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_TRGAUTO_X_MIN_COORD,
                                                       AHMIM_STM_D_TRGAUTO_X_MAX_COORD,
                                                       AHMIM_STM_D_TRGAUTO_Y_MIN_COORD,
                                                       AHMIM_STM_D_TRGAUTO_Y_MAX_COORD)) /*ZoomMinus Button is pressed*/
                 && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                            /*Soft Buttons are not Disabled*/
                 && ((TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.Auto_Select_b) || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.Auto_NoSelect_b)))
        {
          aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b = TRUE;
        }
        else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_MC_VISIBLE_b(AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD))
               //&& (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsIconFullScreenNoSelect_b)
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)) /*Soft Buttons are not Disabled*/
        {
          aHmiM_STM_v_VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b = TRUE;
        }
        else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_XBTN_X_MIN_COORD,
                                                                 AHMIM_STM_D_XBTN_X_MAX_COORD,
                                                                 AHMIM_STM_D_XBTN_Y_MIN_COORD,
                                                                 AHMIM_STM_D_XBTN_Y_MAX_COORD)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                               /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          aHmiM_STM_v_X_BTN_PRESSED_b = TRUE;
        }
        else
        {
          // do nothing
          #if HMI_ESSENTIAL_DEBUG
            appLogPrintf("Nothing pressed in TRG!\n");
          #endif
        }
      }
      /*Check if a View Button was pressed*/
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_RTV_X_MIN_COORD,
                                                     AHMIM_STM_D_RTV_X_MAX_COORD,
                                                     AHMIM_STM_D_RTV_Y_MIN_COORD,
                                                     AHMIM_STM_D_RTV_Y_MAX_COORD))                /*RearTop Button is pressed*/
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                        /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.TopRearButtonNoSelect_b)) /* RVTV SftBtn shown, but its not selected as the current view */
      {
        aHmiM_STM_v_REAR_TOP_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_FTV_X_MIN_COORD,
                                                     AHMIM_STM_D_FTV_X_MAX_COORD,
                                                     AHMIM_STM_D_FTV_Y_MIN_COORD,
                                                     AHMIM_STM_D_FTV_Y_MAX_COORD))                 /*FrontTop Button is pressed*/
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                         /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.TopFrontButtonNoSelect_b)) /* FVTV SftBtn shown, but its not selected as the current view */
      {
        aHmiM_STM_v_FRONT_TOP_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_RCV_X_MIN_COORD,
                                                     AHMIM_STM_D_RCV_X_MAX_COORD,
                                                     AHMIM_STM_D_RCV_Y_MIN_COORD,
                                                     AHMIM_STM_D_RCV_Y_MAX_COORD))                  /*RearCross Button is pressed*/
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                          /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.RearCrossButtonNoSelect_b)) /* RCPV SftBtn shown, but its not selected as the current view */
      {
        aHmiM_STM_v_REAR_CROSS_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_FCV_X_MIN_COORD,
                                                     AHMIM_STM_D_FCV_X_MAX_COORD,
                                                     AHMIM_STM_D_FCV_Y_MIN_COORD,
                                                     AHMIM_STM_D_FCV_Y_MAX_COORD))                   /*FrontCross Button is pressed*/
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                           /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.FrontCrossButtonNoSelect_b)) /* FCPV SftBtn shown, but its not selected as the current view */
      {
        aHmiM_STM_v_FRONT_CROSS_BTN_PRESSED_b = TRUE;
      }
      else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_XBTN_X_MIN_COORD,
                                                               AHMIM_STM_D_XBTN_X_MAX_COORD,
                                                               AHMIM_STM_D_XBTN_Y_MIN_COORD,
                                                               AHMIM_STM_D_XBTN_Y_MAX_COORD)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
      {                                                                                                                                                               /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
        aHmiM_STM_v_X_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_RVC_X_MIN_COORD,
                                                     AHMIM_STM_D_RVC_X_MAX_COORD,
                                                     AHMIM_STM_D_RVC_Y_MIN_COORD,
                                                     AHMIM_STM_D_RVC_Y_MAX_COORD))                      /* BUNRV Button is pressed*/
               && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                             /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.BackupRearCamButtonNoSelect_b)) /* BUNRV SftBtn shown, but its not selected as the current view */
      {
        aHmiM_STM_v_RVCONLY_BTN_PRESSED_b = TRUE;
      }
      /* condition for Zoom soft button in 4cam and 1 cam when aux absent*/
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_4CAM_MAGNIFIER_X_MIN_COORD,
                                                     AHMIM_STM_D_4CAM_MAGNIFIER_X_MAX_COORD,
                                                     AHMIM_STM_D_4CAM_MAGNIFIER_Y_MIN_COORD,
                                                     AHMIM_STM_D_4CAM_MAGNIFIER_Y_MAX_COORD)) &&
               (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b) && 
               ((FALSE)
                ||(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.ZoomPlus_Selectable_b)
                ||(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.ZoomMinus_Selectable_b))
               ) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_MAGNIFIER_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_1CAM_MAGNIFIER_X_MIN_COORD,
                                                     AHMIM_STM_D_1CAM_MAGNIFIER_X_MAX_COORD,
                                                     AHMIM_STM_D_1CAM_MAGNIFIER_Y_MIN_COORD,
                                                     AHMIM_STM_D_1CAM_MAGNIFIER_Y_MAX_COORD)) &&
               (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b) && 
               ((FALSE)
                ||(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.OneCam_ZoomPlus_Selectable_b)
                ||(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.OneCam_ZoomMinus_Selectable_b))
               ) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_MAGNIFIER_BTN_PRESSED_b = TRUE;
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MIN_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_X_MAX_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MIN_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_PRSNT_AUXCAM_Y_MAX_COORD))                         /*AUX Button is pressed*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AuxCamButton1NoSelect_b) && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b = TRUE; /* AUX */
      }
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MIN_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_X_MAX_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MIN_COORD,
                                                     AHMIM_STM_D_VC_OFFROAD_ABSNT_AUXCAM_Y_MAX_COORD))                          /*AUX Button is pressed*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AuxCamButton2NoSelect_b) && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b = TRUE; /* AUX */
      }

      // else if( (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_ZOOM_X_MIN_COORD,
      //                                                AHMIM_STM_D_ZOOM_X_MAX_COORD,
      //                                                AHMIM_STM_D_ZOOM_Y_MIN_COORD,
      //                                                AHMIM_STM_D_ZOOM_Y_MAX_COORD)) /*ZoomMinus Button is pressed*/
      //      && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b) )  /*Soft Buttons are not Disabled*/
      // {
      //   aHmiM_STM_v_ZOOM_BTN_PRESSED_b = TRUE;
      // }

      /* condition for monitor touch screen for More Cams- when VehCfg8.VC_OFFroad_Camera = [Present]*/ /* Req ID : 445337 */
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_MC_VISIBLE_b(AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_X_MAX_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_PRSNT_MC_BTN_Y_MAX_COORD))
                && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b) 
                && ((TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton1NoSelect_b) 
                    || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton1Select_b)
                    || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsIconFullScreenNoSelect_b))) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b = TRUE;
      }
      /* condition for monitor touch screen for More Cams- when VehCfg8.VC_OFFroad_Camera = [NOT-Present]*/ /* Req ID : 445337 */
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_MC_VISIBLE_b(AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_X_MAX_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MIN_COORD,
                                                                   AHMIM_STM_D_VC_OFFROAD_ABSNT_MC_BTN_Y_MAX_COORD))
                && (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)
                && ((TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton2NoSelect_b) || (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton2Select_b))) /*Soft Buttons are not Disabled*/
      {
        aHmiM_STM_v_VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b = TRUE;
      }

      /* Req ID : 445337 FFCV cordinate update */
      else if ((TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_FFCVBTN_X_MIN_COORD,
                                                                AHMIM_STM_D_FFCVBTN_X_MAX_COORD,
                                                                AHMIM_STM_D_FFCVBTN_Y_MIN_COORD,
                                                                AHMIM_STM_D_FFCVBTN_Y_MAX_COORD)) &&
               (TRUE != aHmiM_STM_v_SoftBtnsDisabled_b)                                                /*Soft Buttons are not Disabled*/
               && (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.FrontFaceCamButtonNoSelect_b)) /* FFCV SftBtn shown, but its not selected as the current view */

      {
        aHmiM_STM_v_FFCV_BTN_PRESSED_b = TRUE; /*FFCV-Button is pressed*/
      }
      else
      {
        #if HMI_ESSENTIAL_DEBUG
          appLogPrintf("RS MC1: %d, MC2: %d, MCFS: %d", aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b, aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b, aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b);
          appLogPrintf("CS MC1: %d, MC2: %d, MCFS: %d", aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton1NoSelect_b, aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsButton2NoSelect_b, aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.MoreCamsIconFullScreenNoSelect_b);
          appLogPrintf("Nothing pressed! \n");
        #endif
        /* do nothing */
      }
      break;
    case TCH_CFG_RES:
      /*
          1. ETM/LTM shall send the touch screen pixel resolution to CVPM by sending
          a.  CM_CTRL.CM_TCH_STAT = [ 4h ; Touch screen config, resolution in pixels],
          b.  CM_CTRL.CM_TCH_X_COORD = [Value representing HU touchscreen horizontal pixels] ,
          c.  CM_CTRL.CM_TCH_Y_COORD = [Value representing HU touchscreen vertical pixels]
       */

      /* aParaM_F_SetTouchDisplayResolutionX_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.X_u16);
         aParaM_F_SetTouchDisplayResolutionY_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.Y_u16); */
      break;
    case TCH_CFG_OFFSET:
      /*
          2.  ETM/LTM shall calculate the min touch grid point (upper left corner X, Y coordinates as described  above) of the RDC2 image window and send the following signals to CVPM:
          a.  CM_CTRL.CM_TCH_STAT = [ 5h ; Touch screen config, upper left in grid points],
          b.  CM_CTRL.CM_TCH_X_COORD = [X coordinate of Upper Left Corner] ,
          c.  CM_CTRL.CM_TCH_Y_COORD = [Y coordinate of Upper Left Corner]
       */

      /* aParaM_F_SetDisplayOffsetX_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.X_u16);
         aParaM_F_SetDisplayOffsetY_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.Y_u16); */
      break;
    case TCH_CFG_MAX:
      /*
          3. ETM/LTM shall calculate the max touch grid point (lower right corner X, Y coordinates as described above) of the RDC2 image window and send the following signals to CVPM:
          a.  CM_CTRL.CM_TCH_STAT = [ 6h ; Touch screen config, lower right in grid points],
          b.  CM_CTRL.CM_TCH_X_COORD = [X coordinate of lower right Corner] ,
          c.  CM_CTRL.CM_TCH_Y_COORD = [Y coordinate of lower right Corner]
       */

      /* aParaM_F_SetDisplayEndX_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.X_u16);
         aParaM_F_SetDisplayEndY_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.tchScrnCoordRaw_s.Y_u16); */
      break;
    case TCH_NOT_PSD:
    case TCH_PS_CAN:
    case CM_TCH_STAT_SNA:
    default:
      break;
    }
  }
  else
  { /* Do nothing */
  }

  tchStatOld = tchStatActual;
  return;
}

static void aHmiM_STM_f_M_ReversedGearUpdate_v(void)
{
  /* DD-ID: {FB8C2858-C4B2-461a-9434-4997D4217015}*/
  static ME_Hydra2defs_E_ReversedGear_t M_ReversedGear_Old;
  static u8 counterFirstSendReversedGear = 0u;
  static ME_Hydra2defs_E_ReversedGear_t aHmiM_STM_v_M_ReversedGear_e = M_ReversedGear_Inactive; /* Req. ID 298251 */

  if (((TRANS_AUTOMATIC == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (PRND_STAT_R == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)) || ((TRANS_MANUAL == aHmiM_STM_v_Rx_HmiMRelatedData_e.transEquipped_e) && (REV_GEAR_ENGAGED == aHmiM_STM_v_Rx_HmiMRelatedData_e.revGear_e)))
  {
    aHmiM_STM_v_M_ReversedGear_e = M_ReversedGear_Active;
  }
  else
  {
    aHmiM_STM_v_M_ReversedGear_e = M_ReversedGear_Inactive;
  }

  /* This is Debug Information on PrivateCAN! */
  if (200 == counterFirstSendReversedGear) /* wait 2sec before first send */
  {
    ME_Hydra2defs_E_MCUDebug0_t mcudebug;
    /* Commenting for future use for debugging */
    // mcudebug = aZynqM_F_GetMCUDebug0_e();
    mcudebug.ReversedGear = aHmiM_STM_v_M_ReversedGear_e;
    /* Commenting for future use for debugging */
    // aZynqM_F_SetMCUDebug0_v(mcudebug);

    counterFirstSendReversedGear = 201u;
  }
  else if (201u == counterFirstSendReversedGear)
  {
    /*do nothing*/
  }
  else
  {
    counterFirstSendReversedGear++;
  }

  if (M_ReversedGear_Old != aHmiM_STM_v_M_ReversedGear_e)
  {
    ME_Hydra2defs_E_MCUDebug0_t mcudebug;
    /* Commenting for future use for debugging */
    // mcudebug = aZynqM_F_GetMCUDebug0_e();
    mcudebug.ReversedGear = aHmiM_STM_v_M_ReversedGear_e;
    /* Commenting for future use for debugging */
    // aZynqM_F_SetMCUDebug0_v(mcudebug);

    M_ReversedGear_Old = aHmiM_STM_v_M_ReversedGear_e;
  }
  else
  { /*do nothing*/
  }

  return;
}

static void aHmiM_STM_f_M_SVC_ViewUpdate_v(void)
{
  /* DD-ID: {35DE1B7C-E397-4b57-936E-95B5024A07D9}*/
  if (aHmiM_STM_v_CurrentScreenOnZynqM_s.view == aHmiM_STM_v_LastRequestedView_e)
  {
    switch (aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
    case ME_Hydra2defs_OEM_E_RearTopView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_RearTopView;
      break;
    case ME_Hydra2defs_OEM_E_RearCrossPathView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_RearCrossPathView;
      break;
    case ME_Hydra2defs_OEM_E_FrontCrossPathView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_FrontCrossPathView;
      break;
    case ME_Hydra2defs_OEM_E_FrontTopView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_FrontTopView;
      break;
    case ME_Hydra2defs_OEM_E_RAW_Front:
    case ME_Hydra2defs_OEM_E_RAW_Rear:
    case ME_Hydra2defs_OEM_E_RAW_Right:
    case ME_Hydra2defs_OEM_E_RAW_Left:
    case ME_Hydra2defs_OEM_E_QuadView:
      /* Req. 226972,226974, 227008, 227010 */
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
      break;
    case ME_Hydra2defs_OEM_E_NoView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_NoView;
      break;
    case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_FrontFacingCameraView;
      break;
    case ME_Hydra2defs_OEM_E_BUNRV:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BUNRV;
      break;
    case ME_Hydra2defs_OEM_E_BUZRV:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BUZRV;
      break;
    case ME_Hydra2defs_OEM_E_TRG_L50_R50:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRG_L50_R50;
      break;
    case ME_Hydra2defs_OEM_E_TRG_L25_R75:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRG_L25_R75;
      break;
    case ME_Hydra2defs_OEM_E_TRG_L75_R25:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRG_L75_R25;
      break;
    case ME_Hydra2defs_OEM_E_TRG_L100_R0:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRG_L100_R0;
      break;
    case ME_Hydra2defs_OEM_E_TRG_L0_R100:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRG_L0_R100;
      break;
      /*Defect fix -545875 */
    case ME_Hydra2defs_OEM_E_TRGLeftCurbView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRGLeftCurbView;
      break;
      /*Defect fix -545875 */
    case ME_Hydra2defs_OEM_E_TRGRightCurbView:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_TRGRightCurbView;
      break;
    case ME_Hydra2defs_OEM_E_THA_Normal:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_THA_Normal;
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic;
      break;
    case ME_Hydra2defs_OEM_E_THA_Zoom_Static:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_THA_Zoom_Static;
      break;
    case ME_Hydra2defs_OEM_E_BlindLeft:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BlindLeft;
      break;
      /*Defect fix -545875 */
    case ME_Hydra2defs_OEM_E_BlindRight:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BlindRight;
      break;
	  case ME_Hydra2defs_OEM_E_BUNRVOneCam:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BUNRV;
      break;
    case ME_Hydra2defs_OEM_E_BUZRVOneCam:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_BUZRV;
      break;
    case ME_Hydra2defs_OEM_E_APA_FTV:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_APA_FTV;
      break;
    case ME_Hydra2defs_OEM_E_APA_RTV:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_APA_RTV;
      break;
    case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
      aHmiM_STM_v_M_SVC_View_e = ME_Hydra2defs_OEM_E_APA_FULLSCREEN;
      break;
    default:
      break; /*do not update*/
    }
  }
  else
  { /*do nothing*/
  }

  return;
}

static void aHmiM_STM_f_XButtonHandlingDefault(void)
{
  /* DD-ID: {BE923849-0A08-4f5f-BDC5-CCE6EA008577}*/
  ME_Hydra2defs_E_ViewType_t CurrUseableView = ME_Hydra2defs_OEM_E_NoView;
  if(ME_Hydra2defs_OEM_E_NonViewRequested == aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    CurrUseableView = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
  }
  else
  {
    CurrUseableView = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
  }

  /*Implemented as per VF560 Rev5*/
  if( (FALSE)
    || (TRUE == aHmiM_STM_v_GearReverse_Delayed_b)
    || ((DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
  )
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b = FALSE;
    HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
  }
  else if (TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b)
  {
    
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b = TRUE;

    if (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.X_BTN_PRESSED_b)
    {
      //appLogPrintf("Defeat on CAN");
      HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_ON;
    }
    else if((FALSE)
    || (ME_Hydra2defs_OEM_E_TRG_L50_R50 == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRG_L25_R75 == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRG_L75_R25 == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRG_L100_R0 == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRG_L0_R100 == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRGLeftCurbView == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_TRGRightCurbView == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_BlindLeft == CurrUseableView)
    || (ME_Hydra2defs_OEM_E_BlindRight == CurrUseableView)
    )
    {
      if(DISP_OFF == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) 
        HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
    }
    else /*This will take care of other views*/
    {
      if((DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
        HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts = IMAGE_DEFEAT_RQ_STS_OFF;
    }
  }
  else
  { /*do nothing*/
  }
  return;
}
/* ===============================================================
 * Purpose :It will Disable/Enable the Zoom Plus icon based on the
 * vehicle Speed . Zoom in Soft button disable if Speed > 8MPH or speed is SNA
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req Id : 296594
 * =============================================================== */
static void aHmiM_STM_f_ZoomIcoHandlingSpeed_v(void)
{ 
  /* DD-ID: {E95D0681-8B36-4f55-A35A-D3BC60DA55D6}*/
  /*Req Id : 296594*/
  /* To hold the previous Zoom disable overlay status*/
  static u8 prevZoomdisableStat = 0u;
  
  /*Four Cam Mode*/
  if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera)
  {
    if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) || (TRUE == vDisableZoomBut)) /*Added for Defect 290977, Task 291517,291518*/
    {
      /*Disable the Zoom icon , If speed > 8MPH or SNA */
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b = FALSE;
      prevZoomdisableStat = 1u;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b = FALSE;
      if (prevZoomdisableStat == TRUE)
      {
        /* If speed < 8MPH enablethe ZoomPlus icon */
        prevZoomdisableStat = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b = TRUE;
      }
    }
  }

  if(FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera)
  {
  /*Check if single CAM varaint is enabled*/
  if(FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
  {
    if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) || (TRUE == vDisableZoomBut)) /*Added for Defect 290977, Task 291517,291518*/
    {
      /*Disable the Zoom icon , If speed > 8MPH or SNA */
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b = FALSE;
      prevZoomdisableStat = 1u;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b = FALSE;
      if (prevZoomdisableStat == TRUE)
      {
        /* If speed < 8MPH enablethe ZoomPlus icon */
        prevZoomdisableStat = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b = TRUE;
      }
    }
  }
  else if (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
  {
    if ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.VehSpeedHigherRVCResetSpeed_b) || (TRUE == vDisableZoomBut)) /*Added for Defect 290977, Task 291517,291518*/
    {
      /*Disable the Zoom icon , If speed > 8MPH or SNA */
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Not_Selectable_b = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomMinus_Selectable_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Selectable_b = FALSE;
      prevZoomdisableStat = 1u;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Not_Selectable_b = FALSE;
      if (prevZoomdisableStat == TRUE)
      {
        /* If speed < 8MPH enablethe ZoomPlus icon */
        prevZoomdisableStat = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Selectable_b = TRUE;
      }
    }
  }
  else
  {
    /*Do Nothing*/
  }
  }
}

static void aHmiM_STM_f_EvaluateTopViewOverlayGroups_v(void)
{
  /* DD-ID: {87110040-5935-4a06-ACED-83478A94E34D}*/
  /*****************************************
   ****************  AJARs  ****************
   *****************************************/
  aHmiM_STM_f_Eval_FrontLeftAJAR_v();
  aHmiM_STM_f_Eval_FrontRightAJAR_v();
  aHmiM_STM_f_Eval_RearLeftAJAR_v();
  aHmiM_STM_f_Eval_RearRightAJAR_v();
  aHmiM_STM_f_Eval_TailgateAJAR_v();


  /*****************************************
   ****************  PDCs  *****************
   *****************************************/
  if (HMI_XCP_PDC_THRESHOLD_SPEED < aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleSpeed_f32) /*Defect 378582 Fix, Changing variable u8/u16 to float f32*/
  {    
    /* Do not display any PDCs above 11 km/h */
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Green_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
  }
  else
  {
    if(counter_ap == 20)
    {
    // appLogPrintf("FL,FC,FR,RL,RC,RR");
    // appLogPrintf("Arc: %d : %d : %d : %d : %d :%d \n"
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FL_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FC_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FR_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RL_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RC_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RR_e
    // );
    
    // appLogPrintf("Flash: %d : %d : %d : %d : %d :%d \n"
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FL_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FC_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FR_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RL_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RC_e
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RR_e
    // );
    }
    else
    {
      counter_ap++;

      if(counter_ap > 11)
        counter_ap = 0;
    }

    if (aHmiM_STM_E_VehType_Maserati == aHmiM_STM_v_VehicleType_e)
    {
      /* Do normal PDC handling - Maserati */
      aHmiM_STM_f_Eval_pdcFL_Mas_v();
      aHmiM_STM_f_Eval_pdcFR_Mas_v();
      aHmiM_STM_f_Eval_pdcRL_Mas_v();
      aHmiM_STM_f_Eval_pdcRR_Mas_v();
    }
    else if (aHmiM_STM_E_VehType_Chrysler == aHmiM_STM_v_VehicleType_e)
    {
      /* Do normal PDC handling - Chrysler */
      aHmiM_STM_f_Eval_pdcFL_Chr_v();
      aHmiM_STM_f_Eval_pdcFC_Chr_v();
      aHmiM_STM_f_Eval_pdcFR_Chr_v();
      aHmiM_STM_f_Eval_pdcRL_Chr_v();
      aHmiM_STM_f_Eval_pdcRC_Chr_v();
      aHmiM_STM_f_Eval_pdcRR_Chr_v();
    }
    else if (aHmiM_STM_E_VehType_D2DJ == aHmiM_STM_v_VehicleType_e)
    {
      /* Do normal PDC handling - D2 DJ */
      aHmiM_STM_f_Eval_pdcFL_Chr_v();
      aHmiM_STM_f_Eval_pdcFC_Chr_v();
      aHmiM_STM_f_Eval_pdcFR_Chr_v();
      aHmiM_STM_f_Eval_pdcRL_Chr_v();
      aHmiM_STM_f_Eval_pdcRC_Chr_v();
      aHmiM_STM_f_Eval_pdcRR_Chr_v();
    }
    else
    { /*do nothing*/
    }
  }
  // AP_BUMPER_TEST();
  return;
}

static void aHmiM_STM_f_Eval_FrontLeftAJAR_v(void)
{
  /* DD-ID: {60E918CE-36CD-4d74-B5D2-C539B395706C}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftFrontAJAR_e)
  {
  case DoorCLOSED:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontClose_Icon_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontOpen_Icon_b = FALSE;
    break;
  case DoorOPEN:
  default:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontClose_Icon_b = FALSE; /* Set Door Icon to Open if SNA (for now) */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontOpen_Icon_b = TRUE;
    break;
  }
  return;
}
static void aHmiM_STM_f_Eval_FrontRightAJAR_v(void)
{
  /* DD-ID: {CD93DEBC-B168-49f4-AEDE-124C5344BDB9}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.RightFrontAJAR_e)
  {
  case DoorCLOSED:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontClose_Icon_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontOpen_Icon_b = FALSE;
    break;
  case DoorOPEN:
  default:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontClose_Icon_b = FALSE; /* Set Door Icon to Open if SNA (for now) */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontOpen_Icon_b = TRUE;
    break;
  }
  return;
}
static void aHmiM_STM_f_Eval_RearLeftAJAR_v(void)
{
  /* DD-ID: {05E8D940-E126-4f6a-8AF8-F8ABF54C1465}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftRearAJAR_e)
  {
  case DoorCLOSED:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearClose_Icon_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearOpen_Icon_b = FALSE;
    break;
  case DoorOPEN:
  default:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearClose_Icon_b = FALSE; /* Set Door Icon to Open if SNA (for now) */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearOpen_Icon_b = TRUE;
    break;
  }
  return;
}
static void aHmiM_STM_f_Eval_RearRightAJAR_v(void)
{
  /* DD-ID: {D1B04263-2BA1-4c41-A947-BF3B19445F3A}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.RightRearAJAR_e)
  {
  case DoorCLOSED:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearClose_Icon_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearOpen_Icon_b = FALSE;
    break;
  case DoorOPEN:
  default:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearClose_Icon_b = FALSE; /* Set Door Icon to Open if SNA (for now) */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearOpen_Icon_b = TRUE;
    break;
  }
  return;
}
static void aHmiM_STM_f_Eval_TailgateAJAR_v(void)
{
  /* DD-ID: {AB809598-E96B-4eed-88E6-E8A0DBAA9EBC}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.TailgateAJAR_e)
  {
  case DoorCLOSED:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackDoorOpen_Icon_b = FALSE;
    break;
  case DoorOPEN:
  default:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackDoorOpen_Icon_b = TRUE; /* Set Door Icon to Open if SNA (for now) */
    break;
  }
  return;
}

/* Maserati - Req.ID: 780929 */
static void aHmiM_STM_f_Eval_pdcFL_Mas_v(void)
{
  /* DD-ID: {FECEC7AF-DC8F-46fb-A9CC-AEC734B8FFCE}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FL_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC FL Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
    /* PDC FL Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = TRUE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc4:
    /* PDC FL Green */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Green_b = TRUE;
    break;
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC FL None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Green_b = FALSE;
    break;
  default:
    break;
  }
  return;
}
/* Maserati - Req.ID: 780929 */
static void aHmiM_STM_f_Eval_pdcFR_Mas_v(void)
{
  /* DD-ID: {0E64D40B-4E9C-42a4-9452-4F34C12BABFD}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FR_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC FR Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
    /* PDC FR Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = TRUE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc4:
    /* PDC FR Green */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Green_b = TRUE;
    break;
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC FR None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Green_b = FALSE;
    break;
  default:
    break;
  }
  return;
}
/* Maserati - Req.ID: 781250 */
static void aHmiM_STM_f_Eval_pdcRL_Mas_v(void)
{
  /* DD-ID: {2A745BF8-C7CE-420f-A368-DF5766A4A6A7}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RL_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC RL Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
    /* PDC RL Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = TRUE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc5:
    /* PDC RL Green */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Green_b = TRUE;
    break;
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC RL None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Green_b = FALSE;
    break;
  default:
    break;
  }
  return;
}
/* Maserati - Req.ID: 781250 */
static void aHmiM_STM_f_Eval_pdcRR_Mas_v(void)
{
  /* DD-ID: {F6ECD1E6-AA5A-407d-96F6-9855A284627A}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RR_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC RR Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
    /* PDC RR Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = TRUE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Green_b = FALSE;
    break;
  case TeAP_e_Alert_Arc5:
    /* PDC RR Green */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Green_b = TRUE;
    break;
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC RR None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Green_b = FALSE;
    break;
  default:
    break;
  }
  return;
}
/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcFL_Chr_v(void)
{
  /* DD-ID: {D138967E-C9D2-4ff4-A783-8CD17EA34F9E}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FL_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC FL Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
    /* PDC FL Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    break;
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC FL None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    break;
  default:
    break;
  }
  
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FL_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = (fast_tick == TRUE) ? aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b : FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b =    (fast_tick == TRUE) ? aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b: FALSE;     
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = (slow_tick == TRUE) ? aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b : FALSE; 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b =    (slow_tick == TRUE) ? aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b: FALSE;    
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  
  return;
}


/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcFC_Chr_v(void)
{
  /* DD-ID: {6E83DADD-06CD-41f6-87CD-E59B536D3D25}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FC_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC FC Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
    /* PDC FC Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = FALSE;
    break;
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC FC None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = FALSE;
    break;
  default:
    break;
  }

    switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FC_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  return;
}
/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcFR_Chr_v(void)
{
  /* DD-ID: {D483FC00-CD95-454d-8EA1-3C161A0F41D6}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_FR_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC FR Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
    /* PDC FR Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    break;
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC FR None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    break;
  default:
    break;
  }

    switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_FR_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  return;
}
/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRL_Chr_v(void)
{
  /* DD-ID: {DF0AAF82-BB3E-4d63-BE0D-C1B7E2D2F28B}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RL_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC RL Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
    /* PDC RL Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    break;
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC RL None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    break;
  default:
    break;
  }

  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RL_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  return;
}
/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRC_Chr_v(void)
{
  /* DD-ID: {A030D1B1-5D41-4868-9C9C-A784344F89E7}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RC_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC RC Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
    /* PDC RC Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = FALSE;
    break;
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC RC None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = FALSE;
    break;
  default:
    break;
  }

    switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RC_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  return;
}
/* Chrysler & MagnaJeep */
static void aHmiM_STM_f_Eval_pdcRR_Chr_v(void)
{
  /* DD-ID: {73D21523-207E-4795-8AD2-56598C94357B}*/
  switch (aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_Arc_RR_e)
  {
  case TeAP_e_Alert_Arc1:
    /* PDC RR Red */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = TRUE;
    break;
  case TeAP_e_Alert_Arc2:
    /* PDC RR Yellow */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    break;
  case TeAP_e_Alert_Arc3:
  case TeAP_e_Alert_Arc4:
  case TeAP_e_Alert_Arc5:
  case TeAP_e_Alert_Arc6:
  case TeAP_e_Alert_NoObjectDetected:
  case TeAP_e_Alert_SNA:
    /* PDC RR None */
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    break;
  default:
    break;
  }

    switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.APA_FlashRate_RR_e)
  {
    case TeAP_e_GraphicFlshRate_Solid:
      /*Do nothing*/
    break;
    case TeAP_e_GraphicFlshRate_MAX:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = (fast_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_SlowFlash:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b); 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = (slow_tick && aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b);
    break;
    case TeAP_e_GraphicFlshRate_None:
    case TeAP_e_GraphicFlshRate_SNA:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b = FALSE;
    break;
    default:
    /*Do nothing*/
    break;  
  }
  return;
}

static void aHmiM_STM_f_EvaluateFrontTopTrajectories_v(void)
{
  /* DD-ID: {20590A86-20C0-470b-9A69-5AA545CF73EE}*/
  /* Top View and Front View Dynamic Trajectory Overlays - Req. ID 381222 & 625769 */
  if ((TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Dynamic_Gridlines_Feature_b)
          && (FALSE == (    (FALSE)
            || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63 == TRUE) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1))
	          || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95 == TRUE) && ((aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus == 1) || (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1)))                                                                                                                    // Connected)
            || (2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo)
          )))
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontViewDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewFrontDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontViewDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewFrontDynamics_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontViewDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewFrontDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontViewDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewFrontDynamics_b = FALSE;
  }
  return;
}

static void aHmiM_STM_f_EvaluateFFCVTrajectories_v(void)
{
  /* DD-ID: {C8D71648-EE6A-400a-BC0F-FAB66185C1CC}*/
  /* Top View and FFCV Trajectory Overlays */
  if(TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_FFCV_Gridlines_Feature_b)
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontTireTracks_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontTireTracks_b = FALSE;
  }
  return;
}

static void aHmiM_STM_f_EvaluateRearTopTrajectories_v(void)
{
  /* DD-ID: {E7FBD69F-2518-44d4-A7C1-5DEBB778A88D}*/
  /* Top View and Rear View Dynamic Trajectory Overlays - Req. ID 381222 & 625769, 3103728, 3101758 */
  /*If trailer is connected dont show graphic*/
  if((TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Dynamic_Gridlines_Feature_b)
          && (FALSE == (    (FALSE)
            || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63 == TRUE) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1))
	          || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95 == TRUE) && ((aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus == 1) || (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1)))                                                                                                                    // Connected)
            || (2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo)
          ))
          )
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewRearDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewRearDynamics_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = TRUE;
    
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewRearDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopViewRearDynamics_b = FALSE;
  }

  return;
}
/* ===============================================================
 * Purpose :Evaluate MOrecam overlay both Offraod_Camera present /Absent
 * If MoreCam Button is pressed Tx.MoreCamsRQSts_b if TRUE and show
 *  MoreCAm button Active(RED) state.
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output : None
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Req ID : 445682, 445337, 445679
 * =============================================================== */
static void aHmiM_STM_f_EvaluateMoreCamsOverlay_v(void)
{
  /* DD-ID: {24C338B3-7CAF-4135-8996-7DD95C8BB647}*/
  // /* Evaluate More Cams Overlay, Req ID : 445682, 445337 */
  // /* More Cams button is pressed when more cams overlay is there and CVPM Video is displayed on the screen */
  // if ((TRUE == aHmiM_STM_f_Check_MoreCams_BTN_PRESSED_b()) && (DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
  // {
  //   if ((FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam) && (kDisplayView3_VIEW_7 != Tx_HmiView))
  //   {
  //     /* Once Morecam button is pressed, OffRoad = Absent & DisplayView3 != 7 (TRG View), show MoreCambutton1select in ACTIVE state*/
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = TRUE;
  //   }
  //   else
  //   {
  //     /* Once Morecam button is pressed, OffRoad = Present or DisplayView3 == 7 (TRG View), show MoreCambutton2select in ACTIVE state*/
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = TRUE;
  //   }

  //   HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_ON;
    
  // }
  // else if (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) /* Req ID : 445682, 445337, 445679 */
  // {
  //   if ((FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam) && (kDisplayView3_VIEW_7 != Tx_HmiView))
  //   {
  //     /* Once Tx signal MoreCamReqStst = 1 is received to radio and radio is acknowledged with tgwDispStatus = 0x07
  //      * Along with OffRoad = Absent & DisplayView3 != 7 (TRG View) Make the MoreCamButton1select in NonActive state */
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = FALSE;
  //   }
  //   else
  //   {
  //     /* Once Tx signal MoreCamReqStst = 1 is received to radio and radio is acknowledged with tgwDispStatus = 0x07
  //      * Along with OffRoad = Present or DisplayView3 == 7 (TRG View) Make the MoreCamButton2select in NonActive state */
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = FALSE;
  //   }

  //   HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;
    
  // }
  // else
  // {
  //   /*Do nothing*/
  // }

  // if ((aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b == FALSE) && (aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b == FALSE))
  // {
  //   if ((FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam) && (kDisplayView3_VIEW_7 != Tx_HmiView))
  //   {
  //     /* MoreCamButton1NoSelect_b will be TRUE if button is not pressed(means MoreCamsIconSelect is not TRUE before) */
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = TRUE; /*Show MoreCam of grayish background */
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = FALSE;
  //   }
  //   else
  //   {
  //     /* MoreCamButton2NoSelect_b will be TRUE if button is not pressed(means MoreCamsIconSelect is not TRUE before)*/
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = TRUE; /* Show MoreCam of grayish background */
  //     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = FALSE;
  //   }
  // }
  // else
  // {
  //   /*  MoreCamsButton1Select_b/MoreCamsButton2Select_b is TRUE, then
  //    *  MoreCamsButton1NoSelect_b/MoreCamsButton2NoSelect_b should made FALSE */
  //   aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = FALSE;
  //   aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = FALSE;
  // }
}

static void aHmiM_STM_f_EvaluateFFCV_Button_Overlay_v(void) /* SRD 224741 (req id: 226454) */
{
  /* DD-ID: {FB322D05-4BBB-495c-9D69-63CAE577CCB2}*/
  if (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_OFFRoadCameraPresent_b) /* SRD 224741 (req id: 226454) */
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b = FALSE;
  }
}
/* req. ID: 3103728 to enable/disable Dynamic Trajectories */
/* v_RetV_b: TRUE  -> overlays will be enabled
   v_RetV_b: FALSE -> overlays will be disabled */
static BOOL aHmiM_STM_f_EvaluateReq3103728_v(void)
{
  /* DD-ID: {4D39A956-4EBF-4a72-BFD8-CAE7E3E63355}*/
  SignalTypes_S_Rx_LRWS_ST_t v_LRWS_ST_local;
  SignalTypes_S_Rx_LRW_t v_LRW_local;
  Std_E_ReturnType_t v_Ret_t = Std_E_RetType_Successful;
  BOOL v_RetV_b = TRUE;

  // Stubbed value for removing interface error Porting
  v_LRWS_ST_local.v_Value = 1u;
  v_LRW_local.v_LRW1 = 1u;
  v_LRW_local.v_LRW0 = 1u;

  /* req. ID: 3103728 to enable/disable  Rear View Dynamic Trajectories */
  v_Ret_t = Std_E_RetType_Successful;
  if ((v_Ret_t == Std_E_RetType_Successful) && (v_LRWS_ST_local.v_Value != 0))
  { /* disabled */
    v_RetV_b = FALSE;
  }
  else
  {
    /* do nothing */
  }

  v_Ret_t = Std_E_RetType_Successful;

  if ((v_Ret_t == Std_E_RetType_Successful) && ((((u16)(v_LRW_local.v_LRW1) << 8) | (u16)v_LRW_local.v_LRW0) == 0x3FFF))
  { /* disabled */
    v_RetV_b = FALSE;
  }
  else
  {
    /* do nothing */
  }

  return v_RetV_b;
}

static void aHmiM_STM_f_EvaluateRVCNormalTrajectories_v(void)
{
  /* DD-ID: {D86A9FB0-A2AB-4a80-AFF7-587FB7BFD6CC}*/
  /* Top View and Rear View Dynamic Trajectory Overlays - Req. ID 381222 & 625769, 3103728, 3101758 */
  /*If trailer is connected dont show graphic*/
  if((TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.SVC_Dynamic_Gridlines_Feature_b)
          && (FALSE == (    (FALSE)
            || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63 == TRUE) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1))
	          || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95 == TRUE) && ((aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus == 1) || (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1)))                                                                                                                    // Connected)
            || (2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo)
          ))
          )
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = TRUE;
  }
  else
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearViewDynamics_b = FALSE;
  }
  return;
}
static void aHmiM_STM_f_RequestControlHandling_v(void)
{
  /* DD-ID: {69E9EAC9-B234-4eb6-9A4A-9248126D01F7}*/
  aFailM_S1_HmiM_Errors_t v_HmiErrors_s;
/* Commenting for future use for debugging */
// aFailM_F_GetFailsafeAction_HmiM_v(&v_HmiErrors_s);
#if 0 /* Kept a placeholder for next release */
  if(aHmiM_E_NormalOperation == aHmiM_F_GetModuleState_e())
  {
    if(ME_Hydra2defs_OEM_E_NoView == aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
      if(ImageDefeat1_ForceON == v_HmiErrors_s.ImageDefeat_Error_e)
      {
        if(TRUE == ZynqM_F_GetCurrentStateVideoOutput_b())
        { /*Turn off Video Output*/
          ZynqM_F_RequestStateVideoOutput_v(FALSE);
        }
        else if(TRUE == aZynqM_F_GetCurrentStateCams_b())
        { /*Turn off Cams if Video Output is Off*/
          aZynqM_F_RequestStateCams_v(FALSE);
        }
        else{/*do nothing*/}
      }
      else
      { /*Only Turn Cams Off*/
        if(TRUE == aZynqM_F_GetCurrentStateCams_b())
        {
          aZynqM_F_RequestStateCams_v(FALSE);    /* hier wird 0x80 ausgel�st */
        }
        else{/*do nothing*/}
      }
    }
    else
    {
      /*Turn On Cams and Video Output again*/
      if(FALSE == aZynqM_F_GetCurrentStateCams_b())
      { /*Turn On Cams first*/
        aZynqM_F_RequestStateCams_v(TRUE);
      }
      else if(FALSE == aZynqM_F_GetCurrentStateVideoOutput_b())
      { /*Turn On Video Output*/
        aZynqM_F_RequestStateVideoOutput_v(TRUE);
      }
      else{/*do nothing*/}
    }
  }
  else
  {
    /* Zynq has not booted yet */
  }
#endif
  return;
}

static void aHmiM_STM_f_UpdateVehicleType_v(void)
{
  /* DD-ID: {89817C2E-3543-47be-8022-EA9A6E8BB93E}*/
  if ((VEH_LINE1_M161 == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e) || (VEH_LINE1_M156 == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e) || (VEH_LINE1_M157 == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e))
  {
    aHmiM_STM_v_VehicleType_e = aHmiM_STM_E_VehType_Maserati;
  }
  else if ((VEH_LINE1_RU == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e) ||
           (VEH_LINE1_MAGNAJEEP_CHRYSLER_MOUNTING == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e) ||
           (VEH_LINE1_MAGNAJEEP_FORD_MOUNTING == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e) ||
           (VEH_LINE1_DT == aHmiM_STM_v_Rx_HmiMRelatedData_e.vehicleLine_e))
  {
    //appLogPrintf("VehType = DT \n");
    aHmiM_STM_v_VehicleType_e = aHmiM_STM_E_VehType_Chrysler;
  }
  else
  {
    aHmiM_STM_v_VehicleType_e = aHmiM_STM_E_VehType_Undefined;
  }
  return;
}

static void aHmiM_STM_f_CameraBlanking_v(void)
{
  /* DD-ID: {185A3133-6B2D-4c84-9220-9E2061E11E7E}*/
  /* LeftCam */
  if (DoorOPEN == aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftFrontAJAR_e)
  {
    /*Kept for FID Development */
    // aZynqM_F_SetCameraBlankedState_v(CamID_Left,TRUE);
  }
  else if ((aHmiM_STM_E_VehType_Maserati == aHmiM_STM_v_VehicleType_e) && (DoorOPEN == aHmiM_STM_v_Rx_HmiMRelatedData_e.LeftRearAJAR_e))
  {
    /*Kept for FID Development */
    //  aZynqM_F_SetCameraBlankedState_v(CamID_Left,TRUE);
  }
  else
  {
    /*Kept for FID Development */
    //  aZynqM_F_SetCameraBlankedState_v(CamID_Left,FALSE);
  }
  /* RightCam */
  if (DoorOPEN == aHmiM_STM_v_Rx_HmiMRelatedData_e.RightFrontAJAR_e)
  {
    /*Kept for FID Development */
    // aZynqM_F_SetCameraBlankedState_v(CamID_Right,TRUE);
  }
  else if ((aHmiM_STM_E_VehType_Maserati == aHmiM_STM_v_VehicleType_e) && (DoorOPEN == aHmiM_STM_v_Rx_HmiMRelatedData_e.RightRearAJAR_e))
  {
    /*Kept for FID Development */
    // aZynqM_F_SetCameraBlankedState_v(CamID_Right,TRUE);
  }
  else
  {
    /*Kept for FID Development */
    //   aZynqM_F_SetCameraBlankedState_v(CamID_Right,FALSE);
  }
  /* BackCam */
  if ((DoorOPEN == aHmiM_STM_v_Rx_HmiMRelatedData_e.TailgateAJAR_e)) /* Req 3331606 */
  {
    /*Kept for FID Development */
    //   aZynqM_F_SetCameraBlankedState_v(CamID_Rear,TRUE);
  }
  else
  {
    /*Kept for FID Development */
    //  aZynqM_F_SetCameraBlankedState_v(CamID_Rear,FALSE);
  }
  return;
}

/* HMI View will be set when current view is active/stabilized */ /* Req. ID: 2905986 */
static void aHmiM_STM_f_Evaluate_HMIView_DisplayView_v(void)
{
  /* DD-ID: {16CDE9AB-2F7B-4a77-9157-D1D1BF1222DF}*/
  /* Dispatch State */
  switch (aHmiM_STM_v_SystemState_e)
  {
    case SystemONVideoOFF:
      Tx_HmiView = DisplayView3_ViewOFF; /* Req. ID: 457323/2905992 */ /* SVC_1.DisplayView shall be equal to 0x0, OFF */
      break;

    case SystemONVideoON:
      /* Req. ID: 457325 */ /* State 1: System ON View ON (Superstate of S2, S3, S4, and S5) */
      switch (aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
      {
        case ME_Hydra2defs_OEM_E_NoView:
          Tx_HmiView = DisplayView3_ViewOFF;      
          break;
        case ME_Hydra2defs_OEM_E_RearTopView:
        case ME_Hydra2defs_OEM_E_TSC_Aiming: /*TSC mimics RTV for time being*/
          /* Req. ID: 457327 */  /* State 2: Top and Rear View (TV+RV) */
          /* Req. ID: 2905994 */ /* SVC_1.DisplayView shall be equal to 0x1, View_1 */
          Tx_HmiView = DisplayView3_View1;   
          break;
        case ME_Hydra2defs_OEM_E_RearCrossPathView:
          /* Req. ID: 457334 */  /* State 3: Rear Cross Path View (RCPV) */
          /* Req. ID: 2905996 */ /* SVC_1.DisplayView shall be equal to 0x2, View_2 */
          Tx_HmiView = DisplayView3_View2;      
          break;
        case ME_Hydra2defs_OEM_E_FrontCrossPathView:
          /* Req. ID: 457338 */  /* State 4: Front Cross Path View (FCPV) */
          /* Req. ID: 2905998 */ /* SVC_1.DisplayView shall be equal to 0x3, View_3 */
          Tx_HmiView = DisplayView3_View3;     
          break;
        case ME_Hydra2defs_OEM_E_FrontTopView:
          /* Req. ID: 457342 */  /* State 5: Top and Front View (TV+FV) */
          /* Req. ID: 2906000 */ /* SVC_1.DisplayView shall be equal to 0x4, View_4 */
          Tx_HmiView = DisplayView3_View4;      
          break;
        case ME_Hydra2defs_OEM_E_BUNRV:
        case ME_Hydra2defs_OEM_E_BUZRV:
        case ME_Hydra2defs_OEM_E_BUNRVOneCam:
        case ME_Hydra2defs_OEM_E_BUZRVOneCam:
        case ME_Hydra2defs_OEM_E_THA_Normal:
        case ME_Hydra2defs_OEM_E_THA_Zoom_Dynamic:
        case ME_Hydra2defs_OEM_E_THA_Zoom_Static:
          Tx_HmiView = DisplayView3_View5;      
          break;
        case ME_Hydra2defs_OEM_E_TRGLeftCurbView:
          /* for S22.1: SVC_1.DisplayView shall be equal to 0x7, View_7 */
          Tx_HmiView = DisplayView3_View6;      
          break;
        case ME_Hydra2defs_OEM_E_TRGRightCurbView:
          /* for S22.2: SVC_1.DisplayView shall be equal to 0x7, View_7 */
          Tx_HmiView = DisplayView3_View7;      
          break;
        case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
          /* for FFC: SVC_1.DisplayView shall be equal to 0x8, View_8 */
          Tx_HmiView = DisplayView3_View8;      
          break;
        case ME_Hydra2defs_OEM_E_TRG_L50_R50:
        case ME_Hydra2defs_OEM_E_TRG_L25_R75:
        case ME_Hydra2defs_OEM_E_TRG_L75_R25:
        case ME_Hydra2defs_OEM_E_TRG_L100_R0:
        case ME_Hydra2defs_OEM_E_TRG_L0_R100:
          Tx_HmiView = DisplayView3_View9;      
          break;
        case ME_Hydra2defs_OEM_E_BlindLeft:
          /* for S22.1: SVC_1.DisplayView shall be equal to 0x7, View_7 */
          Tx_HmiView = DisplayView3_View10;      
          break;
        case ME_Hydra2defs_OEM_E_BlindRight:
          /* for S22.2: SVC_1.DisplayView shall be equal to 0x7, View_7 */
          Tx_HmiView = DisplayView3_View11;      
          break;
        case ME_Hydra2defs_OEM_E_APA_FTV:
        case ME_Hydra2defs_OEM_E_APA_RTV:
        case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
          Tx_HmiView = DisplayView3_View12;
          break;
        default:
          Tx_HmiView = DisplayView3_ViewOFF;      
          break;
      }
      break;

    default:
      Tx_HmiView = DisplayView3_ViewOFF;
      break;
  }

  return;
}

static void aHmiM_STM_f_Update_THA_Related_Output_v(void)
{
  /* DD-ID: {DF81702F-5AFE-4bbe-B906-76D56D5EA00B}*/
  aHmiM_STM_f_Update_THA_Sft_Btn_PRESSED_b();
  aHmiM_STM_f_Update_Confirm_Btn_PRESSED_b();
  aHmiM_STM_f_Update_Start_Btn_PRESSED_b();
  aHmiM_STM_f_Update_THAScrnTch_PRESSED_b(); 
  aHmiM_STM_f_Update_User_Slctd_Cplr_Crdnts_THA_b();
  aHmiM_STM_f_Update_Bullet_Icon_Coordinates_b();
  aHmiM_STM_f_Update_THA_Screen_Exit_PRESSED_b();
  aHmiM_STM_f_Update_Scrn_Pressed_Crdnts_b();
  aHmiM_STM_f_Update_Zoom_View_Status_b();
}

static void aHmiM_STM_f_HandleAuxOverlay_v(void)
{
  /* DD-ID: {3E54B0E8-C76B-4e9e-95F8-B25237549C93}*/
//   /* AUXCamRQSts= 1 When Aux Camera View Soft Button (SftBtn.AuxCam) is displayed AND touched/selected
//    * Req Id 498356, 445337 */

//   if (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.SFTBTN_SVC_AUX_PRESSED_b)
//   {
//     if (FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
//     {
//       /* Once AuxCam button is pressed, OffRoad = Absent & DisplayView3 != 7 (TRG View), show AuxCambutton1select in ACTIVE state*/
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b = TRUE;
//     }
//     else
//     {
//       /* Once AuxCam button is pressed, OffRoad = Present or DisplayView3 == 7 (TRG View), show AuxCambutton2select in ACTIVE state*/
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b = TRUE;
//     }
//     HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_ON;
    
//   }
//   else if (DISP_TRAILER_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
//   {
//     if (FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
//     {
//       /* Once Tx signal AuxCamRqSts = 1 is received to radio and radio is acknowledged with tgwDispStatus = 0x05
//        * Along with OffRoad = Absent & DisplayView3 != 7 (TRG View) Make the AuxCamButton1select in NonActive state */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b = FALSE;
//     }
//     else
//     {
//       /* Once Tx signal AuxCamRqSts = 1 is received to radio and radio is acknowledged with tgwDispStatus = 0x05
//        * Along with OffRoad = Present or DisplayView3 == 7 (TRG View) Make the AuxCamButton2select in NonActive state */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b = FALSE;
//     }
//     HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_OFF;
    
//   }
//   else
//   {
//     /* Do Nothing */
//   }

//   if ((aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b == FALSE) && (aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b == FALSE))
//   {
//     if ((FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam) && (kDisplayView3_VIEW_7 != Tx_HmiView))
//     {
//       /* AuxCamButton1NoSelect_b will be TRUE if button is not pressed(means AuxCamButton1Select is not TRUE before) */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b = TRUE; /* Show MoreCam of grayish background */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b = FALSE;
//     }
//     else
//     {
//       /* AuxCamButton2NoSelect_b will be TRUE if button is not pressed(means AuxCamButton2Select is not TRUE before) */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b = TRUE; /* Show MoreCam of grayish background */
//       aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b = FALSE;
//     }
//   }
//   else
//   {
//     /*  AuxCamButton1Select_b/AuxCamButton2Select_b is TRUE, then
//      *  AuxCamButton1NoSelect_b/AuxCamButton2NoSelect_b should made FALSE*/
//     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b = FALSE;
//     aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b = FALSE;
//   }
}

/* ------------------------------------------------------------------------------------------------------ */

/* ===============================================================
 * Purpose  : this function initializes all used variables
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_InitCfg_v(void)
{
  /* DD-ID: {AE5C6A3B-00FB-4176-B2F9-E8A8B1680AEB}*/
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function runs only one time at first call of
 *          : a state
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_f_OnEntry_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {BDFCB6BB-1F81-449f-BE08-34B1E252C057}*/
  /* --- declarations --- */

  /* --- declarations --- */

  /* --- react in dependency on state machine position  --- */
  switch (ST_CurrState_e)
  {
  case aHmiM_STM_E_ST_NotInit:
    aHmiM_STM_f_Entry_NotInit_v();
    break;
  case aHmiM_STM_E_ST_Init:
    aHmiM_STM_f_Entry_Init_v();
    break;
  case aHmiM_STM_E_ST_CheckInactiveMode:
    aHmiM_STM_f_Entry_CheckInactiveMode_v();
    break;
  case aHmiM_STM_E_ST_CheckView:
    aHmiM_STM_f_Entry_CheckView_v();
    break;
  case aHmiM_STM_E_ST_CheckOvl:
    aHmiM_STM_f_Entry_CheckOvl_v();
    break;
  case aHmiM_STM_E_ST_CheckFailsafe:
    aHmiM_STM_f_Entry_CheckFailsafe_v(); 
    break;
  case aHmiM_STM_E_ST_RequestScreenOnZynq:
    aHmiM_STM_f_Entry_RequestScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq:
    aHmiM_STM_f_Entry_WaitForRequestedScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_LockOutWait:
    aHmiM_STM_f_Entry_LockOutWait_v();
    break;
  case aHmiM_STM_E_ST_End:
    aHmiM_STM_f_Entry_End_v();
    break;
  default:
    /* do nothing */
    break;
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function runs if STM is in a specific state
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_f_OnRun_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {E6DB5BCD-2A2B-4ea2-B498-2FE55AC8868E}*/
  /* --- declarations --- */

  /* --- declarations --- */
  /* --- react in dependency on state machine position  --- */
  switch (ST_CurrState_e)
  {
  case aHmiM_STM_E_ST_NotInit:
    aHmiM_STM_f_DoState_NotInit_v();
    break;
  case aHmiM_STM_E_ST_Init:
    aHmiM_STM_f_DoState_Init_v();
    break;
  case aHmiM_STM_E_ST_CheckInactiveMode:
    aHmiM_STM_f_DoState_CheckInactiveMode_v();
    break;
  case aHmiM_STM_E_ST_CheckView:
    aHmiM_STM_f_DoState_CheckView_v();
    break;
  case aHmiM_STM_E_ST_CheckOvl:
    aHmiM_STM_f_DoState_CheckOvl_v();
    break;
  case aHmiM_STM_E_ST_CheckFailsafe:
    aHmiM_STM_f_DoState_CheckFailsafe_v();
    break;
  case aHmiM_STM_E_ST_RequestScreenOnZynq:
    aHmiM_STM_f_DoState_RequestScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq:
    aHmiM_STM_f_DoState_WaitForRequestedScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_LockOutWait:
    aHmiM_STM_f_DoState_LockOutWait_v();
    break;
  case aHmiM_STM_E_ST_End:
    aHmiM_STM_f_DoState_End_v();
    break;
  default:
    /* do nothing */
    break;
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function runs only one time when leaving a state
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_f_OnExit_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {9DEBD842-6DC2-4466-B4BB-FC50CD3F567A}*/
  /* --- react in dependency on state machine position  --- */
  switch (ST_CurrState_e)
  {
  case aHmiM_STM_E_ST_NotInit:
    aHmiM_STM_f_Exit_NotInit_v();
    break;
  case aHmiM_STM_E_ST_Init:
    aHmiM_STM_f_Exit_Init_v();
    break;
  case aHmiM_STM_E_ST_CheckInactiveMode:
    aHmiM_STM_f_Exit_CheckInactiveMode_v();
    break;
  case aHmiM_STM_E_ST_CheckView:
    aHmiM_STM_f_Exit_CheckView_v();
    break;
  case aHmiM_STM_E_ST_CheckOvl:
    aHmiM_STM_f_Exit_CheckOvl_v();
    break;
  case aHmiM_STM_E_ST_CheckFailsafe:
    aHmiM_STM_f_Exit_CheckFailsafe_v();
    break;
  case aHmiM_STM_E_ST_RequestScreenOnZynq:
    aHmiM_STM_f_Exit_RequestScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq:
    aHmiM_STM_f_Exit_WaitForRequestedScreenOnZynqM_v();
    break;
  case aHmiM_STM_E_ST_LockOutWait:
    aHmiM_STM_f_Exit_LockOutWait_v();
    break;
  case aHmiM_STM_E_ST_End:
    aHmiM_STM_f_Exit_End_v();
    break;
  default:
    /* do nothing */
    break;
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Mandatory
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns always TRUE
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_TransitionNotInitToInit_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {70B69251-11A0-48f7-ADF6-49F15B6DB041}*/
  BOOL retVal;
  if (aHmiM_E_NormalOperation == aHmiM_F_GetModuleState_e())
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Mandatory
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns always TRUE
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_TransitionInitToCheckInactiveMode_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {CEE26294-97FD-4faf-A0B9-5FFD8657C6F3}*/
  return TRUE;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : We have to recognize if Inactive Mode was Requested
 *          : so we can switch to End State
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if the Inactive Mode was requested
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_InactiveModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {32CD7FF0-EBF9-4b63-ABC3-C2D84FC9C1AC}*/
  BOOL retVal;
  /* If InactiveMode is Requested we have to switch the NormalOperation STM to End State */
  if (aHmiM_STM_E_InactiveModeRequested == aHmiM_STM_v_RequestedMode_e)
  {
    retVal = TRUE;
  }
  else
  {
    /* Continue with normal Operation - go to check View State */
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Checks if a Mode was Requested or not
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if we have no Mode Request
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_NoModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {119AC068-B13B-4ed6-9E63-BEC987044682}*/
  BOOL retVal;
  if (aHmiM_STM_E_NoModeRequested == aHmiM_STM_v_RequestedMode_e)
  {
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Checks if Active Mode Requested
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if Active Mode was requested
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_ActiveModeRequested_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {D6659BDA-2371-4e2c-BAB2-AAF070C4A602}*/
  BOOL retVal;
  /* If InactiveMode is Requested we have to switch the NormalOperation STM to End State */
  if (aHmiM_STM_E_NormalOperationModeRequested == aHmiM_STM_v_RequestedMode_e)
  {
    retVal = TRUE;
  }
  else
  {
    /* Continue with normal Operation - go to check View State */
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Mandatory
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns always TRUE
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_TransitionCheckViewToCheckOvl_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {213A4465-36C7-47f3-93A4-F048F852476A}*/
  return TRUE;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Mandatory
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns always TRUE
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2015-04-02 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_TransitionCheckOvlToCheckFailsafe_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {61D51F5D-E001-431e-9125-4B0E7801B02B}*/
  return TRUE;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : If a Screen changed we have to go to RequestScreenOnZynq
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if View OR Overlays changed
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-10-01 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_ScreenChanged_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {9396AA1C-6A02-4c36-B167-3EAE5B89E442}*/
  BOOL retVal;
  /* If View OR Overlays Changed return True */
  if( (FALSE)

    ||  (screenReq.MeSVS_e_ViewEngReqCode != screenResponse.MeSVS_e_ViewEngResCode)
    ||  (screenReq.AP_HMI_SelectedSlot != screenResponse.AP_HMI_SelectedSlot)
    ||  (screenReq.AP_HMI_Fullscreen != screenResponse.AP_HMI_Fullscreen)
    ||  (screenReq.AP_HMI_TopBlackBanner != screenResponse.AP_HMI_TopBlackBanner)
    ||  (screenReq.AP_HMI_TopRedBanner != screenResponse.AP_HMI_TopRedBanner)
    ||  (screenReq.AP_HMI_BottomBlackBanner != screenResponse.AP_HMI_BottomBlackBanner)
    ||  (screenReq.MeSVS_e_THAScreenRequesttoA72 != screenResponse.MeSVS_e_THAScreenResponse)
    ||  (screenReq.MeSVS_DesiredTrailerAngle != screenResponse.MeSVS_DesiredTrailerAngle)
    ||  (screenReq.MeSVS_ActualTrailerAngle != screenResponse.MeSVS_ActualTrailerAngle)
    ||  (screenReq.MeSVS_Orage_Arc_StartAngle != screenResponse.MeSVS_Orage_Arc_StartAngle)
    ||  (screenReq.MeSVS_Red_Arc_StartAngle != screenResponse.MeSVS_Red_Arc_StartAngle)
    ||  (screenReq.MeSVS_pct_ProgressBar != screenResponse.MeSVS_pct_ProgressBar)
    ||  (screenReq.MeSVS_px_CplrPosX != screenResponse.MeSVS_px_CplrPosX)
    ||  (screenReq.MeSVS_px_CplrPosY != screenResponse.MeSVS_px_CplrPosY)
    ||  (screenReq.MeSVS_px_ScrnTchX != screenResponse.MeSVS_px_ScrnTchX)
    ||  (screenReq.MeSVS_px_ScrnTchY != screenResponse.MeSVS_px_ScrnTchY)
    ||  memcmp(&screenReq.MbSVS_bf_OverlayBitsReq, &screenResponse.MbSVS_bf_OverlayBitsRes ,sizeof(OverlayBits_t))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[0], &screenResponse.AP_HMI_ParkSlot[0], sizeof(screenResponse.AP_HMI_ParkSlot[0]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[1], &screenResponse.AP_HMI_ParkSlot[1], sizeof(screenResponse.AP_HMI_ParkSlot[1]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[2], &screenResponse.AP_HMI_ParkSlot[2], sizeof(screenResponse.AP_HMI_ParkSlot[2]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[3], &screenResponse.AP_HMI_ParkSlot[3], sizeof(screenResponse.AP_HMI_ParkSlot[3]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[4], &screenResponse.AP_HMI_ParkSlot[4], sizeof(screenResponse.AP_HMI_ParkSlot[4]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[5], &screenResponse.AP_HMI_ParkSlot[5], sizeof(screenResponse.AP_HMI_ParkSlot[5])) 
    )
  {
    retVal = TRUE;
    
    // appLogPrintf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d"
    //   ,((aHmiM_STM_v_RequestedScreenByHmiM_s.view != aHmiM_STM_v_CurrentScreenOnZynqM_s.view) && (ME_Hydra2defs_OEM_E_NonViewRequested != aHmiM_STM_v_RequestedScreenByHmiM_s.view))
    //   ,(screenReq.AP_HMI_SelectedSlot != screenResponse.AP_HMI_SelectedSlot)
    //   ,(screenReq.AP_HMI_Fullscreen != screenResponse.AP_HMI_Fullscreen)
    //   ,(screenReq.AP_HMI_TopBlackBanner != screenResponse.AP_HMI_TopBlackBanner)
    //   ,(screenReq.AP_HMI_TopRedBanner != screenResponse.AP_HMI_TopRedBanner)
    //   ,(screenReq.AP_HMI_BottomBlackBanner != screenResponse.AP_HMI_BottomBlackBanner)
    //   ,(screenReq.MeSVS_e_THAScreenRequesttoA72 != screenResponse.MeSVS_e_THAScreenResponse)
    //   ,(screenReq.MeSVS_DesiredTrailerAngle != screenResponse.MeSVS_DesiredTrailerAngle)
    //   ,(screenReq.MeSVS_ActualTrailerAngle != screenResponse.MeSVS_ActualTrailerAngle)
    //   ,(screenReq.MeSVS_pct_ProgressBar != screenResponse.MeSVS_pct_ProgressBar)
    //   ,(screenReq.MeSVS_px_CplrPosX != screenResponse.MeSVS_px_CplrPosX)
    //   ,(screenReq.MeSVS_px_CplrPosY != screenResponse.MeSVS_px_CplrPosY)
    //   ,(screenReq.MeSVS_px_ScrnTchX != screenResponse.MeSVS_px_ScrnTchX)
    //   ,(screenReq.MeSVS_px_ScrnTchY != screenResponse.MeSVS_px_ScrnTchY)
    // );

    // appLogPrintf("%d, %d, %d, %d, %d, %d, %d,"    
    //   ,memcmp(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, &aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays ,sizeof(OverlayBits_t))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[0], &screenResponse.AP_HMI_ParkSlot[0], sizeof(screenResponse.AP_HMI_ParkSlot[0]))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[1], &screenResponse.AP_HMI_ParkSlot[1], sizeof(screenResponse.AP_HMI_ParkSlot[1]))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[2], &screenResponse.AP_HMI_ParkSlot[2], sizeof(screenResponse.AP_HMI_ParkSlot[2]))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[3], &screenResponse.AP_HMI_ParkSlot[3], sizeof(screenResponse.AP_HMI_ParkSlot[3]))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[4], &screenResponse.AP_HMI_ParkSlot[4], sizeof(screenResponse.AP_HMI_ParkSlot[4]))
    //   ,memcmp(&screenReq.AP_HMI_ParkSlot[5], &screenResponse.AP_HMI_ParkSlot[5], sizeof(screenResponse.AP_HMI_ParkSlot[5]))
    // );

    // appLogPrintf("\n\n\n %d, %d, %d"
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_SurroundViewCamera
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam
    // ,aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam
    //         );

    // appLogPrintf("\n %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d"
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontTireTracks_b
    //         );

    // appLogPrintf("\n Delay: %d",aHmiM_STM_v_K_TDelayPRND_u64);
    // appLogPrintf("\n %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d"
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.view
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b
    // );

    // appLogPrintf("\n %d, %d, %d, %d, %d, %d, %d, %d"
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomPlus_Not_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Not_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomPlus_Not_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomMinus_Selectable_b
    // ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.OneCam_ZoomMinus_Not_Selectable_b        
    // );        

  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : If a Screen didn't change we have to go back to CheckInactiveMode
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if View AND Overlays didn't change
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-10-01 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_ScreenNotChanged_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {69FAFE77-42F4-455f-B84E-1024BA9B3F9A}*/
  BOOL retVal = FALSE;
  /* If View OR Overlays Changed return False */
  if( (FALSE)
    ||  (screenReq.MeSVS_e_ViewEngReqCode != screenResponse.MeSVS_e_ViewEngResCode)
    ||  (screenReq.AP_HMI_SelectedSlot != screenResponse.AP_HMI_SelectedSlot)
    ||  (screenReq.AP_HMI_Fullscreen != screenResponse.AP_HMI_Fullscreen)
    ||  (screenReq.AP_HMI_TopBlackBanner != screenResponse.AP_HMI_TopBlackBanner)
    ||  (screenReq.AP_HMI_TopRedBanner != screenResponse.AP_HMI_TopRedBanner)
    ||  (screenReq.AP_HMI_BottomBlackBanner != screenResponse.AP_HMI_BottomBlackBanner)
    ||  (screenReq.MeSVS_e_THAScreenRequesttoA72 != screenResponse.MeSVS_e_THAScreenResponse)
    ||  (screenReq.MeSVS_DesiredTrailerAngle != screenResponse.MeSVS_DesiredTrailerAngle)
    ||  (screenReq.MeSVS_ActualTrailerAngle != screenResponse.MeSVS_ActualTrailerAngle)
    ||  (screenReq.MeSVS_Orage_Arc_StartAngle != screenResponse.MeSVS_Orage_Arc_StartAngle)
    ||  (screenReq.MeSVS_Red_Arc_StartAngle != screenResponse.MeSVS_Red_Arc_StartAngle)
    ||  (screenReq.MeSVS_pct_ProgressBar != screenResponse.MeSVS_pct_ProgressBar)
    // ||  (screenReq.MeSVS_px_CplrPosX != screenResponse.MeSVS_px_CplrPosX) // removed this code as SV engine always send back raw cordinate and not what HMIT STM requested. So this is not a correct to check them, It will case timer expiry. 
    // ||  (screenReq.MeSVS_px_CplrPosY != screenResponse.MeSVS_px_CplrPosY)
    ||  (screenReq.MeSVS_px_ScrnTchX != screenResponse.MeSVS_px_ScrnTchX)
    ||  (screenReq.MeSVS_px_ScrnTchY != screenResponse.MeSVS_px_ScrnTchY)
    ||  memcmp(&screenReq.MbSVS_bf_OverlayBitsReq, &screenResponse.MbSVS_bf_OverlayBitsRes ,sizeof(OverlayBits_t))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[0], &screenResponse.AP_HMI_ParkSlot[0], sizeof(screenResponse.AP_HMI_ParkSlot[0]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[1], &screenResponse.AP_HMI_ParkSlot[1], sizeof(screenResponse.AP_HMI_ParkSlot[1]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[2], &screenResponse.AP_HMI_ParkSlot[2], sizeof(screenResponse.AP_HMI_ParkSlot[2]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[3], &screenResponse.AP_HMI_ParkSlot[3], sizeof(screenResponse.AP_HMI_ParkSlot[3]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[4], &screenResponse.AP_HMI_ParkSlot[4], sizeof(screenResponse.AP_HMI_ParkSlot[4]))
    ||  memcmp(&screenReq.AP_HMI_ParkSlot[5], &screenResponse.AP_HMI_ParkSlot[5], sizeof(screenResponse.AP_HMI_ParkSlot[5])) 
    )
  {
    retVal = FALSE;
  }
  else
  {
    aHmiM_STM_f_ResetScreenRequestRetryTimer();
    aHmiM_STM_f_ResetScreenRequestTimeoutTimer();
    retVal = TRUE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Mandatory
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns always TRUE
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_TransitionRequestScreenOnZynqToWaitForRequestedScreenOnZynq_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {2A737FA5-DCFA-4f3f-AE56-CB785B167A71}*/
  return TRUE;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Decrements the Timer for the WaitForScreen State
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if the Timer expired
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_WaitForScreenTimerExpired_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {CB9DC3C2-E2E2-4d93-BAFC-1413184EE653}*/
  BOOL retVal;
  if (aHmiM_STM_E_ST_WaitForRequestedScreenOnZynq == ST_CurrState_e)
  {
    /* Decrement the Timer */
    //aHmiM_STM_v_ReleaseWaitForScreenCnt_u32--; // replaced counter logic with timer logic
    //if (0 == aHmiM_STM_v_ReleaseWaitForScreenCnt_u32)
    if(TRUE == aHmiM_STM_f_IsScreenRequestTimeoutExpr())
    {
      lastReqSvResponseFailureSts = TRUE;
      retVal = TRUE;
    }
    else
    {
      retVal = FALSE;
    }
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : Checks if the Requested View from the HMI is active on Zynq
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if the Requested Screen is active on Zynq
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_ScreenIsActiveOnZynq_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {4D0821C5-71F1-4269-B3E3-554DCF3C9345}*/
  BOOL retVal;
  /* Check if Requested Screen by HMI is equal to Current Screen on Zynq */

  SigMgr_PpScreenResponse_ScreenResponse_t_Get(&screenResponse);
  memcpy(&aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays,&screenResponse.MbSVS_bf_OverlayBitsRes,sizeof(screenResponse.MbSVS_bf_OverlayBitsRes));
  aHmiM_STM_v_CurrentScreenOnZynqM_s.view = (ME_Hydra2defs_E_ViewType_t)screenResponse.MeSVS_e_ViewEngResCode;

  /*aZynqM_F_GetScreen_v(&aHmiM_STM_v_CurrentScreenOnZynqM_s);*/
  /*Screen Not Changed in other words is screen request and response being equal to each other*/
  if (TRUE == aHmiM_STM_f_ScreenNotChanged_b(ST_CurrState_e))
  {
  	memcpy(&lastValid_screenReq, &screenReq, sizeof(ScreenRequest_t));
  	lastValidReqSentSts = FALSE;
    lastReqSvResponseFailureSts = FALSE;
    if(FALSE == StmBootUpViewSts)
    {
      StmBootUpViewSts = TRUE;
      //printf("\n BOOTUP VIEW COMPLETE................\n");
    }
    retVal = TRUE;
  }
  else
  {
    retVal = FALSE;
  }
  was_ScreenActiveinZynq = retVal;
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : This Function decrements the lock-out counter
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Input    : ST_CurrState_e = current state machine position
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Output   : Returns TRUE if the lock-out counter == 0
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
BOOL aHmiM_STM_f_LockOutWaitTimerExpired_b(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {3A9E6409-1A69-4678-B57A-C6ECDC65F6CA}*/
  BOOL retVal;
  static u8 lockOutCnt = HMI_XCP_LOCKOUTWAITCYCLES; /* Lockout Counter */

  if (((TRUE == aHmiM_STM_v_StartLockOutWaitTimer_b) && (0 == lockOutCnt)) || (TRUE == was_ScreenActiveinZynq))
  {
    /* If Lockout Counter == 0 Return TRUE */
    retVal = TRUE;
    lockOutCnt = HMI_XCP_LOCKOUTWAITCYCLES;
    aHmiM_STM_v_StartLockOutWaitTimer_b = FALSE; /* Reset the LockOutWait Start Flag */
  }
  else if (TRUE == aHmiM_STM_v_StartLockOutWaitTimer_b)
  {
    retVal = FALSE;
    lockOutCnt--; /* Decrement the Lockout Counter */
  }
  else
  {
    retVal = FALSE;
  }
  return retVal;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function is called every time the module is called
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_OnModuleCall_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {42E2CDAC-2ADA-4f7e-9119-9DC76DD88E67}*/

  aHmiM_STM_f_GearEdgeDetection_v();                                                  /* Edge Detection */
  aHmiM_STM_f_GearDelayDetection_v();                                                 /* Call the Delay Functions for the Triggers and save triggered Triggers for "WaitforTriggers" State */
  aHmiM_STM_f_UpdateScrnType_v(aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_e_RadDispType, aHmiM_STM_v_ViewTriggerSetList_s.isFourCamPresent,aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam); /* Checks if Radio Display Type has been changed*/
  aHmiM_STM_f_MonitorTchScrn_v();                                                     /* Detect if the Display was touched */
  PDC_Blinking();
  aHmiM_STM_f_M_ReversedGearUpdate_v(); /* update internal variable */
  aHmiM_STM_f_M_SVC_ViewUpdate_v();     /* update internal variable */

  aHmiM_STM_f_UpdateVehicleType_v(); /* update the vehicle type */
  aHmiM_STM_f_CameraBlanking_v();    /* handle cam blanking */

  /*Added for Autopark Exit Conditions Req 16127255*/
  if(TRUE == AP_CameraHandshake_Initiated) 
  {
    if((CameraHandshakeTimeoutThr + AP_CameraHandshake_StartTime) < TimerP_getTimeInUsecs())
    {
      AP_CameraHandshakeTimerExpired = TRUE;
    } 
  }

  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function is called before the module returns
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_OnModuleReturn_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {8190BEE5-C53F-4a6a-878E-0E8D541F0C65}*/
  if (ST_CurrState_e == aHmiM_STM_E_ST_End)
  {
    /* state machine is not active anymore */
  }
  else
  {
    /* state machine is active */
    aHmiM_STM_f_RequestControlHandling_v(); /*do request control handling*/
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function ...
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_RequestInact_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {DB66EC06-45B9-48ef-BA8C-DC1812649C2F}*/
  if (aHmiM_STM_E_ST_End != ST_CurrState_e)
  {
    aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_InactiveModeRequested;
  }
  else
  {
    aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */

/* ===============================================================
 * Purpose  : this function ...
 * ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Version  : 2014-09-24 Function Created
 * =============================================================== */
void aHmiM_STM_F_RequestNormalOp_v(aHmiM_STM_E_StateMachineList_t ST_CurrState_e)
{
  /* DD-ID: {35F474EC-BEF8-4d14-898D-6FEFE416D8BE}*/
  if (aHmiM_STM_E_ST_End == ST_CurrState_e)
  {
    aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NormalOperationModeRequested;
  }
  else
  {
    aHmiM_STM_v_RequestedMode_e = aHmiM_STM_E_NoModeRequested;
  }
  return;
}
/* ================================================================
 * === END OF FUNCTION ============================================
 * ================================================================ */
void aHmiM_STM_F_Reset_CurrentViewOnZynqM__v(void)
{
  /* DD-ID: {702DA70D-C01C-4f6f-AE96-26E3594C97CA}*/
  aHmiM_STM_v_CurrentScreenOnZynqM_s.view = ME_Hydra2defs_OEM_E_NoView;

  return;
}

u32 aHmiM_STM_F_GetScreenRequestTimeout_u32(void)
{
  /* DD-ID: {9DB04250-8475-402c-89A6-668699B0478B}*/
  return aHmiM_STM_v_ScreenRequestTimeout_u32;
}

void aHmiM_STM_F_SetScreenRequestTimeout_v(u32 value)
{
  /* DD-ID: {65B1DC3E-9A02-4958-A05B-D197F7B09A04}*/
  aHmiM_STM_v_ScreenRequestTimeout_u32 = value;
  return;
}

u32 aHmiM_STM_F_GetScreenRequestTimeoutCount_u32(void)
{
  /* DD-ID: {603245EF-8F29-4cc4-A1B0-1D6DA000355E}*/
  return aHmiM_STM_v_ScreenRequestTimeoutCnt_u32;
}

void aHmiM_STM_F_ResetScreenRequestTimeoutCount_v(void)
{
  /* DD-ID: {1881A7C3-E19C-4e6c-ABA2-549D50AEDD8A}*/
  aHmiM_STM_v_ScreenRequestTimeoutCnt_u32 = 0u;
  return;
}

BOOL aHmiM_STM_F_IsScreenRequestTimedOut_b(void)
{
  /* DD-ID: {2BB1D09F-BC1D-4ac1-A31F-97F7EE6F12D1}*/
  return aHmiM_STM_v_ScreenRequestTimedOut_b;
}

static void aHmiM_STF_F_EvaluateJackKnifeOverlays_v(void)
{
  /* DD-ID: {5102FD0B-23B8-4bc2-80F6-FA8CF4D33918}*/
  if(
      (aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_TRSCPresence == TRUE) 
	    && (    (FALSE)
            || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode63 == TRUE) && (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1))
	          || ((aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_CANNode95 == TRUE) && ((aHmiM_STM_v_Rx_HmiMRelatedData_e.ItbmTrailerStatus == 1) || (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerConnectionStatus == 1)))                                                                                                                    // Connected)
            || (2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.MeTRSC_e_TrlrPrsntInfo)
          )
      && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_FrontFacingCameraView) 
      && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_TRGLeftCurbView) 
      && (aHmiM_STM_v_CurrentScreenOnZynqM_s.view != ME_Hydra2defs_OEM_E_TRGRightCurbView)
      && (aHmiM_STM_v_Rx_HmiMRelatedData_e.TrailerCalibrationStatus == TeTRSC_e_TrlrCalInfo_Calibrated) 
    )
  {
    static real32_T SV_remapping = ((real32_T)(100.0f / 90.0f)); /*TO compensate remapping at SV engine, SV maps 100 to 90*/

    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_Enable = TRUE;
    real32_T temp_tad, temp_jk;
    
    /*Trailer Angle Protection Implemented based on input from Kamlesh and Aishwarya*/
    temp_jk = ((real32_T)(aHmiM_STF_F_ValueCapping_f( ((float32_t)(aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle)), 53.0f, 26.0f)));
    
    screenReq.MeSVS_DesiredTrailerAngle = \
    (int)(aHmiM_STF_F_ValueCapping_f( ((float32_t)(aHmiM_STM_v_Rx_HmiMRelatedData_e.KnobAngle * SV_remapping)), 100.0f, -100.0f));
    
    screenReq.MeSVS_ActualTrailerAngle = \
    (int)(aHmiM_STF_F_ValueCapping_f( ((float32_t)(aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle * SV_remapping)), 100.0f, -100.0f));
    
    screenReq.MeSVS_Orage_Arc_StartAngle = \
    (int)(aHmiM_STF_F_ValueCapping_f( ((float32_t)(temp_jk * aHmiM_STM_D_JackKnife_OrangeZONE_MIN)), 90.0f, -90.0f));
    
    screenReq.MeSVS_Red_Arc_StartAngle = \
    (int)(aHmiM_STF_F_ValueCapping_f( ((float32_t)(temp_jk * aHmiM_STM_D_JackKnife_RedZONE_MIN)), 90.0f, -90.0f));

    if(((real32_T)0.0f) > aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle)
    {
      temp_tad = (real32_T)((-1.0f) * aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle);
    }
    else
    {
      temp_tad = (real32_T)((1.0f) * aHmiM_STM_v_Rx_HmiMRelatedData_e.TadAngle);
    }

    if( temp_tad >= (temp_jk * aHmiM_STM_D_JackKnife_RedTrlr_MIN))
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_TrailerRed = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_TrailerRed = FALSE;
    }

  }
  else
  {
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_Enable = FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_TrailerRed = FALSE;
  screenReq.MeSVS_DesiredTrailerAngle = 0.0f;
  screenReq.MeSVS_ActualTrailerAngle = 0.0f;
  screenReq.MeSVS_Orage_Arc_StartAngle = 0.0f;
  screenReq.MeSVS_Red_Arc_StartAngle = 0.0f;
  }

  //SVS to TRSC added
  SVStoTRSCSMVC_e.MeSVS_b_MoreCamReq = (boolean)HMI_to_VCAN.IeSVS_b_MoreCamsReqSts;
  SVStoTRSCSMVC_e.MeSVS_e_DispView2Info = (aSigConverter_E_DisplayView2_t)Tx_HmiView;
  if(memcmp(&prev_SVStoTRSCSMVC_e, &SVStoTRSCSMVC_e, sizeof(SVStoTRSCSMVC_t))!=0)
  {
    SigMgr_data_SVStoTRSCSMVC_t_Put(&SVStoTRSCSMVC_e);
    memcpy(&prev_SVStoTRSCSMVC_e, &SVStoTRSCSMVC_e, sizeof(SVStoTRSCSMVC_t));
    //printf("\n EV_JKNF_OVL: time:%llu Line:%d SigMgr_data_SVStoTRSCSMVC_t_Put", TimerP_getTimeInUsecs(), __LINE__);
  }
  

  return;
}

static float32 aHmiM_STF_F_ValueCapping_f(float32 value, float32 uppercap, float32 lowercap)
{
  /* DD-ID: {7AEDFFE4-5A98-45fd-9626-BD1982A0F62A}*/
  if (value > uppercap)
  {
    value = uppercap;
  }
  else if (value < lowercap)
  {
    value = lowercap;
  }
  else
  {
    // do nothing
  }

  return value;
}

#ifdef TRSC_LOG_ENABLE
  static u8 prev_TRSC_Enable = FALSE;
  // static u8 prev_TRSC_JackKnifeOrange = FALSE;
  // static u8 prev_TRSC_JackKnifeRed = FALSE;
  static u8 prev_TRSC_TrailerRed = FALSE;
  static float32 prev_MeSVS_DesiredTrailerAngle = 0.0f;
  static float32 prev_MeSVS_ActualTrailerAngle = 0.0f;

  static void aHmiM_TRSC_Debug()
  {
      if(
        prev_TRSC_Enable != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_Enable || 
        // prev_TRSC_JackKnifeOrange != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_JackKnifeOrange || 
        // prev_TRSC_JackKnifeRed != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_JackKnifeRed ||
        prev_TRSC_TrailerRed != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_TrailerRed || 
        prev_MeSVS_DesiredTrailerAngle != screenReq.MeSVS_DesiredTrailerAngle ||
        prev_MeSVS_ActualTrailerAngle != screenReq.MeSVS_ActualTrailerAngle
      )
    {
      prev_TRSC_Enable = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_Enable;
      // prev_TRSC_JackKnifeOrange = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_JackKnifeOrange;
      // prev_TRSC_JackKnifeRed = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_JackKnifeRed;
      prev_TRSC_TrailerRed = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TRSC_TrailerRed;
      prev_MeSVS_DesiredTrailerAngle = screenReq.MeSVS_DesiredTrailerAngle;
      prev_MeSVS_ActualTrailerAngle = screenReq.MeSVS_ActualTrailerAngle;

      // appLogPrintf("\n TRSC_Enable: %u \n TRSC_JackKnifeOrange: %u \n TRSC_JackKnifeRed=%u \n TRSC_TrailerRed: %u \n",
      //             prev_TRSC_Enable, prev_TRSC_JackKnifeOrange, prev_TRSC_JackKnifeRed, prev_TRSC_TrailerRed);
      appLogPrintf("whiteDottedLine_angle_percentage: %0.2f \n trailer_angle_percentage: %0.2f",
                  prev_MeSVS_DesiredTrailerAngle, prev_MeSVS_ActualTrailerAngle);

      if (aHmiM_STM_v_Rx_HmiMRelatedData_e.JackKnifeAngle == 0.0f)
        appLogPrintf("JackKnife Angle recieved is 0");
    }
    else
    {
      // do nothing
    }
  }
#endif

#ifdef APA_LOG_ENABLE

  static u8 Last_PDC_FrontCenter_Red_b = FALSE;
  static u8 Last_PDC_FrontCenter_Yellow_b = FALSE;
  static u8 Last_PDC_RearCenter_Red_b = FALSE;
  static u8 Last_PDC_RearCenter_Yellow_b = FALSE;

  static u8 Last_PDC_FrontRight_Red_b = FALSE;
  static u8 Last_PDC_FrontRight_Yellow_b = FALSE;

  static u8 Last_PDC_FrontLeft_Red_b = FALSE;
  static u8 Last_PDC_FrontLeft_Yellow_b = FALSE;

  static u8 Last_PDC_RearRight_Red_b = FALSE;
  static u8 Last_PDC_RearRight_Yellow_b = FALSE;

  static u8 Last_PDC_RearLeft_Red_b = FALSE;
  static u8 Last_PDC_RearLeft_Yellow_b = FALSE;

  static u8 Last_RightDoorFrontClose_Icon_b = FALSE;
  static u8 Last_LeftDoorFrontClose_Icon_b = FALSE;
  static u8 Last_RightDoorRearClose_Icon_b = FALSE;
  static u8 Last_LeftDoorRearClose_Icon_b = FALSE;

  static u8 Last_BackDoorOpen_Icon_b = FALSE;
  static u8 Last_RightDoorRearOpen_Icon_b = FALSE;
  static u8 Last_RightDoorFrontOpen_Icon_b = FALSE;
  static u8 Last_LeftDoorRearOpen_Icon_b = FALSE;
  static u8 Last_LeftDoorFrontOpen_Icon_b = FALSE;

  static void aHmiM_AutoPark_Debug()
  {
    if (
        (Last_PDC_RearLeft_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b) || (Last_PDC_RearLeft_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b)

        || (Last_PDC_FrontRight_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b) || (Last_PDC_FrontRight_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b)

        || (Last_PDC_FrontCenter_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b) || (Last_PDC_FrontCenter_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b)

        || (Last_PDC_FrontLeft_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b) || (Last_PDC_FrontLeft_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b)

        || (Last_PDC_RearRight_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b) || (Last_PDC_RearRight_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b)

        || (Last_PDC_RearCenter_Red_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b) || (Last_PDC_RearCenter_Yellow_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b)

        || (Last_RightDoorRearClose_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearClose_Icon_b) || (Last_RightDoorFrontClose_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontClose_Icon_b) || (Last_LeftDoorRearClose_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearClose_Icon_b) || (Last_LeftDoorFrontClose_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontClose_Icon_b)

        || (Last_BackDoorOpen_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackDoorOpen_Icon_b) || (Last_RightDoorRearOpen_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearOpen_Icon_b) || (Last_RightDoorFrontOpen_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontOpen_Icon_b) || (Last_LeftDoorRearOpen_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearOpen_Icon_b) || (Last_LeftDoorFrontOpen_Icon_b != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontOpen_Icon_b))
    {

      Last_PDC_RearLeft_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b;
      Last_PDC_RearLeft_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b;

      Last_PDC_FrontRight_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b;
      Last_PDC_FrontRight_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b;

      Last_PDC_FrontCenter_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b;
      Last_PDC_FrontCenter_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b;

      Last_PDC_FrontLeft_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b;
      Last_PDC_FrontLeft_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b;

      Last_PDC_RearRight_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b;
      Last_PDC_RearRight_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b;

      Last_PDC_RearCenter_Red_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b;
      Last_PDC_RearCenter_Yellow_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b;

      Last_RightDoorRearClose_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearClose_Icon_b;
      Last_RightDoorFrontClose_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontClose_Icon_b;
      Last_LeftDoorRearClose_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearClose_Icon_b;
      Last_LeftDoorFrontClose_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontClose_Icon_b;

      Last_BackDoorOpen_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackDoorOpen_Icon_b;

      Last_RightDoorRearOpen_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorRearOpen_Icon_b;
      Last_RightDoorFrontOpen_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RightDoorFrontOpen_Icon_b;
      Last_LeftDoorRearOpen_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorRearOpen_Icon_b;
      Last_LeftDoorFrontOpen_Icon_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.LeftDoorFrontOpen_Icon_b;

      appLogPrintf("PDC_RearLeft_Red_b         : %u, \n PDC_RearLeft_Yellow_b      : %u, \n PDC_FrontRight_Red_b       : %u, \n PDC_FrontRight_Yellow_b    : %u, \n PDC_FrontCenter_Red_b      : %u, \n PDC_FrontCenter_Yellow_b   : %u, \n PDC_FrontLeft_Red_b        : %u, \n PDC_FrontLeft_Yellow_b     : %u, \n PDC_RearRight_Red_b        : %u, \n PDC_RearRight_Yellow_b     : %u, \n PDC_RearCenter_Red_b       : %u, \n PDC_RearCenter_Yellow_b    : %u, \n RightDoorRearClose_Icon_b  : %u, \n RightDoorFrontClose_Icon_b : %u, \n LeftDoorRearClose_Icon_b   : %u, \n LeftDoorFrontClose_Icon_b  : %u, \n BackDoorOpen_Icon_b       : %u, \n RightDoorRearOpen_Icon_b  : %u, \n RightDoorFrontOpen_Icon_b : %u, \n LeftDoorRearOpen_Icon_b   : %u, \n LeftDoorFrontOpen_Icon_b  : %u, \n ", Last_PDC_RearLeft_Red_b, Last_PDC_RearLeft_Yellow_b, Last_PDC_FrontRight_Red_b, Last_PDC_FrontRight_Yellow_b

                  ,
                  Last_PDC_FrontCenter_Red_b, Last_PDC_FrontCenter_Yellow_b

                  ,
                  Last_PDC_FrontLeft_Red_b, Last_PDC_FrontLeft_Yellow_b

                  ,
                  Last_PDC_RearRight_Red_b, Last_PDC_RearRight_Yellow_b

                  ,
                  Last_PDC_RearCenter_Red_b, Last_PDC_RearCenter_Yellow_b

                  ,
                  Last_RightDoorRearClose_Icon_b, Last_RightDoorFrontClose_Icon_b, Last_LeftDoorRearClose_Icon_b, Last_LeftDoorFrontClose_Icon_b

                  ,
                  Last_BackDoorOpen_Icon_b, Last_RightDoorRearOpen_Icon_b, Last_RightDoorFrontOpen_Icon_b, Last_LeftDoorRearOpen_Icon_b, Last_LeftDoorFrontOpen_Icon_b);
    }

    return;
  }
#endif

#ifdef THA_LOG_ENABLE

  static u8 Last_THA_ButtonGrey        = FALSE;
  static u8 Last_THA_ButtonSelectable  = FALSE;
  static u8 Last_ZoomMinus_Selectable_b      = FALSE;
  static u8 Last_THA_TriangleOverlay   = FALSE;
  static u8 Last_THA_ConfirmButton     = FALSE;
  static u8 Last_THA_StartButton       = FALSE;
  static u8 Last_THA_ProgressBar       = FALSE;
  static u8 Last_THA_CouplerBulletIcon = FALSE;
  static u8 Last_XIcon                = FALSE;
  static u8 Last_THAmsdID             = 0u;
  static u8 Last_THA_ProgressPct      = 0u;
  static u8 Last_THAscrPressXpos      = 0u;
  static u8 Last_THAscrPressYpos      = 0u;
  static u8 Last_THACouplerXpos       = 0u;
  static u8 Last_THACouplerYpos       = 0u;

  static void aHmiM_THA_Overlays_Debug()
  {
    if( (FALSE)
      || (Last_THA_ButtonGrey        != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey       )
      || (Last_THA_ButtonSelectable  != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable )
      || (Last_ZoomMinus_Selectable_b      != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b     )
      || (Last_THA_TriangleOverlay   != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_TriangleOverlay  )
      || (Last_THA_ConfirmButton     != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton    )
      || (Last_THA_StartButton       != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_StartButton      )
      || (Last_THA_ProgressBar       != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ProgressBar      )
      || (Last_THA_CouplerBulletIcon != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_CouplerBulletIcon)
      || (Last_XIcon                != aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b             )
      || (Last_THAmsdID             != screenReq.MeSVS_e_THAScreenRequesttoA72                          )
      || (Last_THA_ProgressPct      != screenReq.MeSVS_pct_ProgressBar                                  )
      || (Last_THAscrPressXpos      != screenReq.MeSVS_px_ScrnTchX                                      )
      || (Last_THAscrPressYpos      != screenReq.MeSVS_px_ScrnTchY                                      )
      || (Last_THACouplerXpos       != screenReq.MeSVS_px_CplrPosX                                      )
      || (Last_THACouplerYpos       != screenReq.MeSVS_px_CplrPosY                                      )  
    )
    {
      Last_THA_ButtonGrey        = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonGrey       ;
      Last_THA_ButtonSelectable  = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ButtonSelectable ;
      Last_ZoomMinus_Selectable_b      = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.ZoomMinus_Selectable_b     ;
      Last_THA_TriangleOverlay   = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_TriangleOverlay  ;
      Last_THA_ConfirmButton     = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ConfirmButton    ;
      Last_XIcon                = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.XIcon_b             ;
      Last_THA_StartButton       = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_StartButton      ;
      Last_THA_ProgressBar       = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_ProgressBar      ;
      Last_THA_CouplerBulletIcon = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.THA_CouplerBulletIcon;
      Last_THAmsdID             = screenReq.MeSVS_e_THAScreenRequesttoA72                          ;
      Last_THA_ProgressPct      = screenReq.MeSVS_pct_ProgressBar                                  ;
      Last_THAscrPressXpos      = screenReq.MeSVS_px_ScrnTchX                                      ;
      Last_THAscrPressYpos      = screenReq.MeSVS_px_ScrnTchY                                      ;
      Last_THACouplerXpos       = screenReq.MeSVS_px_CplrPosX                                      ;
      Last_THACouplerYpos       = screenReq.MeSVS_px_CplrPosY                                      ;
      

      appLogPrintf("\n\n\
      THA_ButtonGrey        : %d \t \
      THA_ButtonSelectable  : %d \t \
      ZoomMinus_Selectable_b      : %d \n \
      THA_TriangleOverlay   : %d \t \
      THA_ConfirmButton     : %d \t \
      XIcon                : %d \t \
      THA_StartButton       : %d \n \
      THA_ProgressBar       : %d \t \
      THA_CouplerBulletIcon : %d \t \
      THAmsdID             : %d \n \
      THA_ProgressPct      : %d \t \
      THAscrPressXpos      : %d \t \
      THAscrPressYpos      : %d \n \
      THACouplerXpos       : %d \t \
      THACouplerYpos       : %d \t \
      "
      ,Last_THA_ButtonGrey       
      ,Last_THA_ButtonSelectable 
      ,Last_ZoomMinus_Selectable_b     
      ,Last_THA_TriangleOverlay  
      ,Last_THA_ConfirmButton 
      ,Last_XIcon   
      ,Last_THA_StartButton      
      ,Last_THA_ProgressBar      
      ,Last_THA_CouplerBulletIcon
      ,Last_THAmsdID            
      ,Last_THA_ProgressPct     
      ,Last_THAscrPressXpos     
      ,Last_THAscrPressYpos     
      ,Last_THACouplerXpos      
      ,Last_THACouplerYpos      
      );
    }

    return;
  }

  static void aHmiM_THA_Related_Debug()
  {
    if (
        (prev_M_Current_THA_State_Received != M_Current_THA_State_Received) || (prev_aHmiM_STM_v_VIEW_ZOOM_STS_b != aHmiM_STM_v_VIEW_ZOOM_STS_b) || (prev_aHmiM_STM_v_VIEW_SCRN_TCH_STS_b != aHmiM_STM_v_VIEW_SCRN_TCH_STS_b) || (prev_aHmiM_STM_v_CONFIRM_BTN_PRESSED_b != aHmiM_STM_v_CONFIRM_BTN_PRESSED_b) || (prev_aHmiM_STM_v_START_BTN_PRESSED_b != aHmiM_STM_v_START_BTN_PRESSED_b) || (prev_aHmiM_STM_v_THA_SFT_BTN_PRESSED_b != aHmiM_STM_v_THA_SFT_BTN_PRESSED_b) || (prev_aHmiM_STM_v_CPLR_POS_X_u != aHmiM_STM_v_CPLR_POS_X_u) || (prev_aHmiM_STM_v_CPLR_POS_Y_u != aHmiM_STM_v_CPLR_POS_Y_u) || (prev_M_Cplr_Htch_Distance != M_Cplr_Htch_Distance) || (aHmiM_STM_v_ViewGuardSetList_s.prev_M_THA_Active_Status != aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status) || (prev_aHmiM_STM_v_THA_X_BTN_PRESSED_b != aHmiM_STM_v_THA_X_BTN_PRESSED_b))
    {
      prev_M_Current_THA_State_Received = M_Current_THA_State_Received;
      prev_aHmiM_STM_v_VIEW_ZOOM_STS_b = aHmiM_STM_v_VIEW_ZOOM_STS_b;
      prev_aHmiM_STM_v_VIEW_SCRN_TCH_STS_b = aHmiM_STM_v_VIEW_SCRN_TCH_STS_b;
      prev_aHmiM_STM_v_CONFIRM_BTN_PRESSED_b = aHmiM_STM_v_CONFIRM_BTN_PRESSED_b;
      prev_aHmiM_STM_v_START_BTN_PRESSED_b = aHmiM_STM_v_START_BTN_PRESSED_b;
      prev_aHmiM_STM_v_THA_SFT_BTN_PRESSED_b = aHmiM_STM_v_THA_SFT_BTN_PRESSED_b;
      prev_aHmiM_STM_v_THA_X_BTN_PRESSED_b = aHmiM_STM_v_THA_X_BTN_PRESSED_b;
      prev_aHmiM_STM_v_CPLR_POS_X_u = aHmiM_STM_v_CPLR_POS_X_u;
      prev_aHmiM_STM_v_CPLR_POS_Y_u = aHmiM_STM_v_CPLR_POS_Y_u;
      prev_M_Cplr_Htch_Distance = M_Cplr_Htch_Distance;
      aHmiM_STM_v_ViewGuardSetList_s.prev_M_THA_Active_Status = aHmiM_STM_v_ViewGuardSetList_s.M_THA_Active_Status;

      appLogPrintf("Current_THA_State_Rec: %d \n ZOOM_STS: %d \n SCRN_TCH_STS: %d \n",
                  (aSigConverter_E_THAScreenRequest_t)M_Current_THA_State_Received, (BOOL)aHmiM_STM_v_VIEW_ZOOM_STS_b, (BOOL)aHmiM_STM_v_VIEW_SCRN_TCH_STS_b);

      appLogPrintf("CONFIRM_BTN_PRsd: %u \n START_BTN_PRSD: %u \n THA_SFT_BTN_PRSD: %u \n THA_X_BTN_PRSD: %u \n",
                  (BOOL)aHmiM_STM_v_CONFIRM_BTN_PRESSED_b, (BOOL)aHmiM_STM_v_START_BTN_PRESSED_b, (BOOL)aHmiM_STM_v_THA_SFT_BTN_PRESSED_b, (BOOL)aHmiM_STM_v_THA_X_BTN_PRESSED_b);

      appLogPrintf("BULT_POS_X: %u \n BULT_POS_Y: %u \n Cplr_Htch_Dis: %u \n",
                  (uint16)aHmiM_STM_v_CPLR_POS_X_u, (uint16)aHmiM_STM_v_CPLR_POS_Y_u, (uint8)M_Cplr_Htch_Distance);
    }
    return;
  }

#endif

static BOOL aHmiM_STM_f_CheckViewTrigger_IsDiagRoutineMsgRcvChanged_b()
{
  /* DD-ID: {C0196F1E-BE06-4f2d-80C2-C4B8DB7C8937}*/

  BOOL retVal = FALSE;
  static boolean PREV_isRoutineStarted = FALSE;
  static boolean CURR_isRoutineStarted = FALSE;

  CURR_isRoutineStarted = DiagToSVS_e.isRoutineStarted;

  if (CURR_isRoutineStarted != PREV_isRoutineStarted)
  {
    TestPatternPending_b = TRUE;
    retVal = TRUE;
  }

  PREV_isRoutineStarted = CURR_isRoutineStarted;
  return retVal;
}
/*   commenting as it is not being used anywhere
static void testPatternBasic(void)
{
*/
  /* DD-ID: {17A70B31-E878-4174-A37E-45B7DFE5AFAE}*/
/*
  static uint16_T counter_pattern = 0u;
  if (counter_pattern < 10u * 1u)
  { // 0x6666
    cam_testpattern(0u, ISP_MANUFACTURING_COLOR_BAR);
    cam_testpattern(1u, ISP_MANUFACTURING_COLOR_BAR);
    cam_testpattern(2u, ISP_MANUFACTURING_COLOR_BAR);
    cam_testpattern(3u, ISP_MANUFACTURING_COLOR_BAR);
  }
  else if (counter_pattern < 10u * 2u)
  { // 0x7777
    cam_testpattern(0u, ISP_MANUFACTURING_COLOR_BAR_GRADIENT);
    cam_testpattern(1u, ISP_MANUFACTURING_COLOR_BAR_GRADIENT);
    cam_testpattern(2u, ISP_MANUFACTURING_COLOR_BAR_GRADIENT);
    cam_testpattern(3u, ISP_MANUFACTURING_COLOR_BAR_GRADIENT);
  }
  else if (counter_pattern < 10u * 3u)
  { // 0x0000
    cam_testpattern(0u, ISP_MANUFACTURING_TEST_NONE);
    cam_testpattern(1u, ISP_MANUFACTURING_TEST_NONE);
    cam_testpattern(2u, ISP_MANUFACTURING_TEST_NONE);
    cam_testpattern(3u, ISP_MANUFACTURING_TEST_NONE);
  }
  else
  {
    counter_pattern = 0u;
    aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_BUNRV;
    screenReq.MeSVS_e_ViewEngReqCode = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
    SigMgr_PpScreenRequest_ScreenRequest_t_Put(&screenReq);
  }
  counter_pattern++;
}
*/
static void testPattern(void)
{
  /* DD-ID: {17A70B31-E878-4174-A37E-45B7DFE5AFAE}*/
  SVSToDiag_e.Routine_ID = DiagToSVS_e.Routine_ID;
  SVSToDiag_e.Camera_ID = DiagToSVS_e.Camera_ID;
  SVSToDiag_e.TestPattern_ID = DiagToSVS_e.TestPattern_ID;
  SVSToDiag_e.Response_Ack = TRUE;
  SVSToDiag_e.NRC_ID = (ME_Hydra3defs_E_NRCType_t)none;

  if (DiagToSVS_e.Routine_ID != roucameraTestPattern)
  {
    SVSToDiag_e.Response_Ack = FALSE;
  }
  else
  {
    // do nothing
  }

  if (DiagToSVS_e.isRoutineStarted == FALSE)
  {
    //appLogPrintf("routineStarted FALSE SVSToDiag_e.Camera_ID=%d\n",SVSToDiag_e.Camera_ID);
    aHmiM_STM_v_RequestedScreenByHmiM_s.view = LastViewBeforeTestPattern_e;
      switch (SVSToDiag_e.Camera_ID)
      {
      case CamID_Front: // 1
        cam_testpattern(SensorIDx_Front, ISP_MANUFACTURING_TEST_NONE);
        break;
      case CamID_Left: // 2
        cam_testpattern(SensorIDx_Left, ISP_MANUFACTURING_TEST_NONE);
        break;
      case CamID_Rear: // 3
        cam_testpattern(SensorIDx_Rear, ISP_MANUFACTURING_TEST_NONE);
        break;
      case CamID_Right: // 4 
        cam_testpattern(SensorIDx_Right, ISP_MANUFACTURING_TEST_NONE);
        break;
      case CamID_Debug: // 5
        cam_testpattern(SensorIDx_Left, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Right, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Front, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Rear, ISP_MANUFACTURING_TEST_NONE);
        break;
      default: 
        cam_testpattern(SensorIDx_Left, ISP_MANUFACTURING_TEST_NONE); /*stop routine does not provide camera ID so we have to disable test pattern for each camera.*/
        cam_testpattern(SensorIDx_Right, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Front, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Rear, ISP_MANUFACTURING_TEST_NONE);  
        break;
      }
  }
  else if (DiagToSVS_e.isRoutineStarted == TRUE)
  {
    //appLogPrintf("routineStarted TRUE \n");
    static ME_Hydra3defs_E_CameraID_t cameraMask;
    static v3xISP_ManufacturingTestType_t patternMask;
    cameraMask = DiagToSVS_e.Camera_ID;
    patternMask = GetTestPatternType(DiagToSVS_e.TestPattern_ID);
    
    if (aHmiM_STM_v_CurrentScreenOnZynqM_s.view < ME_Hydra2defs_OEM_E_RAW_Front || aHmiM_STM_v_CurrentScreenOnZynqM_s.view > ME_Hydra2defs_OEM_E_QuadView)
    {
      LastViewBeforeTestPattern_e = aHmiM_STM_v_CurrentScreenOnZynqM_s.view; 
    }
    if (SVSToDiag_e.Response_Ack == TRUE)
    {
      switch (cameraMask)
      {
      case CamID_Front: // 1
        cam_testpattern(SensorIDx_Front, patternMask);
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RAW_Front;
        break;

      case CamID_Left: // 2
        cam_testpattern(SensorIDx_Left, patternMask);
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RAW_Left;
        break;

      case CamID_Rear: // 3
        cam_testpattern(SensorIDx_Rear, patternMask);
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RAW_Rear;
        break;

      case CamID_Right: // 4 
        cam_testpattern(SensorIDx_Right, patternMask);
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_RAW_Right;
        break;

      case CamID_Debug: // 5
        cam_testpattern(SensorIDx_Left, patternMask);
        cam_testpattern(SensorIDx_Right, patternMask);
        cam_testpattern(SensorIDx_Front, patternMask);
        cam_testpattern(SensorIDx_Rear, patternMask);
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_QuadView;
        break;

      default:
        SVSToDiag_e.Response_Ack = FALSE;
        //appLogPrintf("ACK FALSE Due to Camera\n");
        SVSToDiag_e.NRC_ID = (ME_Hydra3defs_E_NRCType_t)invalid;
        TestPatternPending_b = FALSE;
        cam_testpattern(SensorIDx_Left, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Right, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Front, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Rear, ISP_MANUFACTURING_TEST_NONE);
        break;
      }
    }
    else
    { 
      TestPatternPending_b = FALSE;
        cam_testpattern(SensorIDx_Left, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Right, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Front, ISP_MANUFACTURING_TEST_NONE);
        cam_testpattern(SensorIDx_Rear, ISP_MANUFACTURING_TEST_NONE);
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = LastViewBeforeTestPattern_e;
    }

    if(SVSToDiag_e.Response_Ack == FALSE)
    {
      TestPatternPending_b = FALSE;
    }
  }
  return;
}

static v3xISP_ManufacturingTestType_t GetTestPatternType(ME_Hydra3defs_E_TestPatternType_t TestPatternType)
{
  /* DD-ID: {B904892F-6FC7-4ac5-AA5C-7E16D005C267}*/
  switch ((int)TestPatternType)
  {
  case 1: // 100% Vertical Color Bars
    return ISP_MANUFACTURING_COLOR_BAR;

  case 2: // Fade-To-Gray
    return ISP_MANUFACTURING_COLOR_BAR_GRADIENT;

  case 0: //No testPattern
    return ISP_MANUFACTURING_TEST_NONE;

  default: // all other cases
    SVSToDiag_e.Response_Ack = FALSE;
    //appLogPrintf("ACK FALSE Due to Pattern\n");
    SVSToDiag_e.NRC_ID = (ME_Hydra3defs_E_NRCType_t)invalid;
    return ISP_MANUFACTURING_TEST_NONE;
  }
}

static void AP_HMI_Touch_Processing(void)
{
  /* DD-ID: {C397F088-5C8D-4f38-A0E3-5CB990009B39}*/

  if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_BACK_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_BACK_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_BACK_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_BACK_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_BackBtn)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = BACK_MODE_PRESSED;
        }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_EXIT_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_EXIT_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_EXIT_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_EXIT_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_ExitBtn_Not_Selected)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = EXIT_MODE_PRESSED;
        }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_PARK_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_PARK_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_PARK_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_PARK_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_ParkBtn_Not_Selected)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = PARK_MODE_PRESSED;
        }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_RIGHT_FWD_OUT_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Forward_RightBtn_Not_Selected) && (FALSE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Grey_Banner2)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = MANEUVER_PRESSED;
          HMI_to_AP.SelectedManeuverType = RIGHT_FORWARD_OUT;
        }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_LEFT_FWD_OUT_BTN_Y_MAX_COORD) &&
                (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Forward_LeftBtn_Not_Selected) && (FALSE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Grey_Banner2)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
      {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
        HMI_to_AP.HMI_ButtonPressed = MANEUVER_PRESSED;
        HMI_to_AP.SelectedManeuverType = LEFT_FORWARD_OUT;
      }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_FRONT_IN_BTN_X_MIN_COORD,
                                                            AHMIM_STM_D_AP_FRONT_IN_BTN_X_MAX_COORD,
                                                            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MIN_COORD,
                                                            AHMIM_STM_D_AP_FRONT_IN_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_FrontInBtn_Not_Selected) && (FALSE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Grey_Banner2)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = MANEUVER_PRESSED;

          if(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Perp_Left_Core)
            {
              HMI_to_AP.SelectedManeuverType = LEFT_FRONT_IN;
              HMI_to_FPA.VehicleParkDirection = ParkINStyle_E_FRONT_IN;
            }
            else if (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Perp_Right_Core)
            {
              HMI_to_AP.SelectedManeuverType = RIGHT_FRONT_IN;
              HMI_to_FPA.VehicleParkDirection = ParkINStyle_E_FRONT_IN;
            }
            else
            {
              HMI_to_AP.HMI_ButtonPressed = NONE_PRESSED;
            }
        }
  else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(AHMIM_STM_D_AP_REAR_IN_BTN_X_MIN_COORD,
                                                          AHMIM_STM_D_AP_REAR_IN_BTN_X_MAX_COORD,
                                                          AHMIM_STM_D_AP_REAR_IN_BTN_Y_MIN_COORD,
                                                          AHMIM_STM_D_AP_REAR_IN_BTN_Y_MAX_COORD) &&
                 (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_RearInBtn_Not_Selected) && (FALSE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Grey_Banner2)) /*Req ID 500485, 444626 X button should display even more cam is TRUE*/ /*X-Button is pressed*/
        {                                                                                                                                                /*X-Button should always be functional - therefore we don't check for "aHmiM_STM_v_SoftBtnsDisabled_b" */
          HMI_to_AP.HMI_ButtonPressed = MANEUVER_PRESSED;
          if(TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Perp_Left_Core)
            {
              HMI_to_AP.SelectedManeuverType = LEFT_REAR_IN;
              HMI_to_FPA.VehicleParkDirection = ParkINStyle_E_REAR_IN;
            }
            else if (TRUE == aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays.AP_Perp_Right_Core)
            {
              HMI_to_AP.SelectedManeuverType = RIGHT_REAR_IN;
              HMI_to_FPA.VehicleParkDirection = ParkINStyle_E_REAR_IN;
            }
            else
            {
              HMI_to_AP.HMI_ButtonPressed = NONE_PRESSED;
            }
        } 
  else if (TRUE == AP_HMI_ParkSlot_Touch_Processing())
        {
          /*Processing already done in else if, Do Nothing*/
        }
    else
        {
          // HMI_to_AP.HMI_ButtonPressed = NONE_PRESSED;
          #if HMI_ESSENTIAL_DEBUG
            appLogPrintf("Nothing pressed in AP!\n");
          #endif
        }
  return;
}

static bool_t AP_HMI_ParkSlot_Touch_Processing(void)
{
  /* DD-ID: {49EAA314-2039-444c-875E-3BDFC7134B2A}*/
  if(FALSE == aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2)
  {
    for(int arr_index = 0; arr_index < 6; arr_index++)
    {
      if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b(screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X,
                                                          screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X + AHMIM_STM_D_AP_PARKSLOT_HEIGHT,
                                                          screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_Y,
                                                          screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_WIDTH) &&
                  (ParkingSlotType_E_PW_PERPENDICULAR == screenResponse.AP_HMI_ParkSlot[arr_index].SlotType))
        {
          HMI_to_AP.HMI_ButtonPressed = PARK_SLOT_PRESSED;
          HMI_to_AP.SelectedManeuverSlotType = screenResponse.AP_HMI_ParkSlot[arr_index].SlotType;   
          if(AHMIM_STM_D_AP_PARKSLOT_X3 == screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X)
          {
            HMI_to_AP.SelectedManeuverSlotSide = SlotSide_E_SLOT_RIGHT;
          }
          else
          {
            HMI_to_AP.SelectedManeuverSlotSide = SlotSide_E_SLOT_LEFT;
          } 
          HMI_to_FPA.m_selectedslotID = screenResponse.AP_HMI_ParkSlot[arr_index].SlotID;
          HMI_to_AP.SelectedSlotId = HMI_to_FPA.m_selectedslotID;
          return TRUE; //added break to save some computational time
        }
      else if (TRUE == aHmiM_STM_f_Is_BTN_PRESSED_IF_VISIBLE_b( screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X,
                                                                screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X + AHMIM_STM_D_AP_PARKSLOT_WIDTH,
                                                                screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_Y,
                                                                screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_HEIGHT) &&
                  (ParkingSlotType_E_PW_PARALLEL == screenResponse.AP_HMI_ParkSlot[arr_index].SlotType))
        {
          HMI_to_AP.HMI_ButtonPressed = PARK_SLOT_PRESSED;
          HMI_to_AP.SelectedManeuverSlotType = screenResponse.AP_HMI_ParkSlot[arr_index].SlotType;   
          if(AHMIM_STM_D_AP_PARKSLOT_X3 == screenResponse.AP_HMI_ParkSlot[arr_index].SlotPixelCoordinate_X)
          {
            HMI_to_AP.SelectedManeuverSlotSide = SlotSide_E_SLOT_RIGHT;
          }
          else
          {
            HMI_to_AP.SelectedManeuverSlotSide = SlotSide_E_SLOT_LEFT;
          }
          HMI_to_FPA.m_selectedslotID = screenResponse.AP_HMI_ParkSlot[arr_index].SlotID;
          HMI_to_AP.SelectedSlotId = HMI_to_FPA.m_selectedslotID;
          return TRUE; //added break to save some computational time
        }
    }
  }
  return FALSE;
}

static void AP_HMI_ViewID_Decoding(void)
{
  /* DD-ID: {ADDE6F0D-E703-4a71-84AC-9173DA1FF5E7}*/
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_REMOVE_HANDS_FEET:
    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR:
    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT:
    case TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON:
    case TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH:
    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR:
    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT:
    case TeAP_e_HMIPopUp_MOVE_BACKWARD:
    case TeAP_e_HMIPopUp_STOP_REAR:
    case TeAP_e_HMIPopUp_STOP_FRONT:
    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE:
    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE:
    case TeAP_e_HMIPopUp_MOVE_FORWARD:
    case TeAP_e_HMIPopUp_SHIFT_TO_REVERSE:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR:
    case TeAP_e_HMIPopUp_COMPLETE_HMI_REAR:
    case TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT:
    case TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY:
    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY:
    case TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY:
    case TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY:
    case TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY:
    case TeAP_e_HMIPopUp_TEMP_NA_OVERLAY:
    case TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY:
    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL:
    case TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL:
    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL:
    case TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL:
    case TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL:
    case TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL:
    case TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL:
    case TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL:
    case TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL:
      if(PRND_STAT_D == aHmiM_STM_v_Rx_HmiMRelatedData_e.prndStatus_e)
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_APA_FTV;
      else
        aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_APA_RTV;           
      break;

    case TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE:
    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD:
    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP:
    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL:
    case TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH:
    case TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE:
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT:
    case TeAP_e_HMIPopUp_DISCLAIMER:
    case TeAP_e_HMIPopUp_COMPLETE_PROCEED:
    case TeAP_e_HMIPopUp_COMPLETE_RELEASE:
    case TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN:
    case TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN:
    case TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN:
    case TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN:
    case TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN:
    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN:
    case TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN:   
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_APA_FULLSCREEN; 
      break;
      
    default: 
      aHmiM_STM_v_RequestedScreenByHmiM_s.view = ME_Hydra2defs_OEM_E_NonViewRequested; 
      break;
  }
  
  return;
}

static void AP_HMI_Overlay_Decoding(void)
{
  /* DD-ID: {AD444F42-5992-4502-AE8A-436DD8C63919}*/
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT:
      AP_HMI_Para_Exit_Overlay_Decoding();
      break;

    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD:
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD:
    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE:
      AP_HMI_Perp_Parkin_Overlay_Decoding();
      break;

    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD:
    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP:
    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL:
    case TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH:
    case TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE:
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT:
      AP_HMI_Scanning_Overlay_Decoding();
      break;

    case TeAP_e_HMIPopUp_REMOVE_HANDS_FEET:
    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR:
    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT:
    case TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON:
    case TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH:
    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR:
    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT:
    case TeAP_e_HMIPopUp_MOVE_BACKWARD:
    case TeAP_e_HMIPopUp_STOP_REAR:
    case TeAP_e_HMIPopUp_STOP_FRONT:
    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE:
    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE:
    case TeAP_e_HMIPopUp_MOVE_FORWARD:
    case TeAP_e_HMIPopUp_SHIFT_TO_REVERSE:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR:
    case TeAP_e_HMIPopUp_COMPLETE_HMI_REAR:
    case TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT:
    case TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY:
    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY:
    case TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY:
    case TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY:
    case TeAP_e_HMIPopUp_TEMP_NA_OVERLAY:
    case TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY:
    case TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL:
    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL:
    case TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL:
    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL:
    case TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL:
    case TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL:
    case TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL:
    case TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL:
    case TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL:
    case TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL:
      AP_HMI_TV_Text_Overlay_Encoding();
      break;

    case TeAP_e_HMIPopUp_DISCLAIMER:
      AP_HMI_Disclaimer_Overlay_Decoding();
      break;

    case TeAP_e_HMIPopUp_COMPLETE_PROCEED:
    case TeAP_e_HMIPopUp_COMPLETE_RELEASE:
      AP_HMI_Park_Complete_Overlay_Decoding();
      break;

    case TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN:
    case TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN:
    case TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN:
    case TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN:
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN:
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN:
    case TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN:
    case TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN:
    case TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN:
    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN:
    case TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN:
      AP_HMI_Fullscreen_Overlay_Decoding();
      break;
      
    default:
    /*Do Nothing*/
      break;
  }

/*AP Related overlay bits with suffix Updated are redundant now, hence commenting entire code*/
#if 0 //Not Required anymore, can be discarded later completely
  for (int8_t pro_index = 0; pro_index < 6; pro_index++)
  {
    if(( screenResponse.AP_HMI_ParkSlot[pro_index].SlotType != screenReq.AP_HMI_ParkSlot[pro_index].SlotType)
    || ( screenResponse.AP_HMI_ParkSlot[pro_index].SlotID != screenReq.AP_HMI_ParkSlot[pro_index].SlotID)
    || ( screenResponse.AP_HMI_ParkSlot[pro_index].SlotSelected != screenReq.AP_HMI_ParkSlot[pro_index].SlotSelected)
    || ( screenResponse.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X != screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X)
    || ( screenResponse.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y != screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y))
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkSlots_Updated = TRUE;
        break;
      }
    else
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkSlots_Updated = FALSE;
  }

  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FullscreenText_Updated    = (screenResponse.AP_HMI_Fullscreen != screenReq.AP_HMI_Fullscreen)               ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_TopBlackBannerUpdated     = (screenResponse.AP_HMI_TopBlackBanner != screenReq.AP_HMI_TopBlackBanner)       ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BottomBlackBannerUpdated  = (screenResponse.AP_HMI_BottomBlackBanner != screenReq.AP_HMI_BottomBlackBanner) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RedBannerUpdated          = (screenResponse.AP_HMI_TopRedBanner != screenReq.AP_HMI_TopRedBanner)           ? TRUE : FALSE;
#endif

  return;
}

static void aHmiM_STM_f_Entry_AutoPark_View_v(void)
{
  /* DD-ID: {39E814A4-AA65-41ce-8D3B-336D1F55E906}*/
  if(TRUE == AP_CameraHandshake_Initiated)
    return; /*If this timeout is initiated then HMI is about to exit autpark hence dont set or clear any overlays now*/

  (void)memset(&screenReq, 0, sizeof(screenReq));
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
  /*Warning there is a overlaybits metset in AP_HMI_Overlay_Decoding,*/
  /*hence it should be called first and then guildlines overlays are set*/
  AP_HMI_Overlay_Decoding();

  if(DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    HMI_to_AP.DisplayedPopUp = aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP;

  if(ME_Hydra2defs_OEM_E_NonViewRequested != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    switch(aHmiM_STM_v_RequestedScreenByHmiM_s.view)
    {
      case ME_Hydra2defs_OEM_E_APA_FTV:
        /*Guidelines need to be present in AutoPark as per requirements*/
        aHmiM_STM_f_EvaluateFrontTopTrajectories_v();
        aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
      break;

      case ME_Hydra2defs_OEM_E_APA_RTV:
        /*Guidelines need to be present in AutoPark as per requirements*/
        aHmiM_STM_f_EvaluateRearTopTrajectories_v();
        aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
      break;

      case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
      default:
        /*Do Nothing as Overlays are getting decoded already*/
      break;
    }
  }
  else /* This code is added to show the guidelines in AP as well */
  {
    switch(aHmiM_STM_v_CurrentScreenOnZynqM_s.view)
    {
      case ME_Hydra2defs_OEM_E_APA_FTV:
        /*Guidelines need to be present in AutoPark as per requirements*/
        aHmiM_STM_f_EvaluateFrontTopTrajectories_v();
        aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
      break;

      case ME_Hydra2defs_OEM_E_APA_RTV:
        /*Guidelines need to be present in AutoPark as per requirements*/
        aHmiM_STM_f_EvaluateRearTopTrajectories_v();
        aHmiM_STM_f_EvaluateTopViewOverlayGroups_v();
      break;

      case ME_Hydra2defs_OEM_E_APA_FULLSCREEN:
      default:
        /*Do Nothing as Overlays are getting decoded already*/
      break;
    }
  }
  if(0 != memcmp(&old_HMI_to_FPA ,&HMI_to_FPA, sizeof(HMI_to_FPA)))
  {
    SigMgr_Data_IHMIInfoToFPA_t_Put(&HMI_to_FPA);
    old_HMI_to_FPA = HMI_to_FPA;
      // appLogPrintf("\n HMI_to_FPA\n");
      // appLogPrintf("m_selectedslotID: %u \n", HMI_to_FPA.m_selectedslotID);

  }

  if(0 != memcmp(&old_HMI_to_AP ,&HMI_to_AP, sizeof(HMI_to_AP)))
  {
    HMI_to_AP.FressnessCounter++;
    SigMgr_Data_HMIInfoToAP_t_Put(&HMI_to_AP);
    old_HMI_to_AP = HMI_to_AP;
  //     appLogPrintf("\n HMI_to_AP\n");
  //     appLogPrintf("DisplayedPopUp: %u,  HmiAbort_Type: %u, HMI_ButtonPressed: %u SelectedManeuverType: %u\n", HMI_to_AP.DisplayedPopUp, HMI_to_AP.HmiAbort_Type, HMI_to_AP.HMI_ButtonPressed, HMI_to_AP.SelectedManeuverType);
  //     appLogPrintf("SelectedManeuverSlotType: %u,  SelectedManeuverSlotSide: %u, SelectedSlotId: %u FressnessCounter: %u\n", HMI_to_AP.SelectedManeuverSlotType, HMI_to_AP.SelectedManeuverSlotSide, HMI_to_AP.SelectedSlotId, HMI_to_AP.FressnessCounter);
  }
  return;
}

static void aHmiM_STM_f_Do_AutoPark_View_v(void)
{
  /* DD-ID: {30309F31-DBAF-4f8e-AE9B-610F0E1B9D9E}*/
  /*Currently AutoPark Entry is same as Do so calling Entry inside do to save program memory*/
  aHmiM_STM_f_Entry_AutoPark_View_v();
  return;
}

static void aHmiM_STM_f_Exit_AutoPark_View_v(void)
{
  /* DD-ID: {EDB9218F-A646-4e5e-9385-D31764E0C855}*/
  (void)memset(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, 0, sizeof(aHmiM_STM_v_RequestedScreenByHmiM_s.overlays));
 
  if(  (TRUE)
    && (TeAP_e_HMIPopUp_IDLE == aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
    && (ME_Hydra2defs_OEM_E_APA_FTV != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
    && (ME_Hydra2defs_OEM_E_APA_RTV != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
    && (ME_Hydra2defs_OEM_E_APA_FULLSCREEN != aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  )
  {
    AP_CameraHandshake_Initiated = FALSE;
    AP_CameraHandshakeTimerExpired = FALSE;
    AP_CameraHandshake_StartTime = 0llu;
    /*IMage Defect anyways resets when view ID is changed*/
    AP_HMI_Active_Status = FALSE;
    HMI_to_VCAN.IeSVS_b_SPMScrnReq = FALSE;
    if(memcmp(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t))!=0)
    {	
      SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(&HMI_to_VCAN);
      memcpy(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t));
      //printf("\n EXIT_AP: time:%llu Line:%d SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put", TimerP_getTimeInUsecs(), __LINE__);
    }

    (void)memset(&HMI_to_AP, 0, sizeof(HMI_to_AP));
    (void)memset(&HMI_to_FPA, 0, sizeof(HMI_to_FPA));

    if(0 != memcmp(&old_HMI_to_FPA ,&HMI_to_FPA, sizeof(HMI_to_FPA)))
    {
      SigMgr_Data_IHMIInfoToFPA_t_Put(&HMI_to_FPA);
      old_HMI_to_FPA = HMI_to_FPA;
      // appLogPrintf("\n HMI_to_FPA\n");
      // appLogPrintf("m_selectedslotID: %u \n", HMI_to_FPA.m_selectedslotID);
    }

    if(0 != memcmp(&old_HMI_to_AP ,&HMI_to_AP, sizeof(HMI_to_AP)))
    {
      SigMgr_Data_HMIInfoToAP_t_Put(&HMI_to_AP);
      old_HMI_to_AP = HMI_to_AP;
    //   appLogPrintf("\n HMI_to_AP\n");
    //   appLogPrintf("DisplayedPopUp: %u,  HmiAbort_Type: %u, HMI_ButtonPressed: %u SelectedManeuverType: %u\n", HMI_to_AP.DisplayedPopUp, HMI_to_AP.HmiAbort_Type, HMI_to_AP.HMI_ButtonPressed, HMI_to_AP.SelectedManeuverType);
    //   appLogPrintf("SelectedManeuverSlotType: %u,  SelectedManeuverSlotSide: %u, SelectedSlotId: %u FressnessCounter: %u\n", HMI_to_AP.SelectedManeuverSlotType, HMI_to_AP.SelectedManeuverSlotSide, HMI_to_AP.SelectedSlotId, HMI_to_AP.FressnessCounter);
    }
  }
  return;
}

static void AP_HMI_Para_Exit_Overlay_Decoding(void)
{
  /* DD-ID: {ACC4B5F9-FF45-434b-A1C7-6BE2F92A283F}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main                         = TRUE;        
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Para_Exit_Core                  = TRUE;        
  
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Not_Selected          = TRUE;                      
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Selected              = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_LeftBtn_Not_Selected  = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_RightBtn_Not_Selected = TRUE;       
    break;

    case TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner1                  = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_LeftBtn_Not_Selected  = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_RightBtn_Not_Selected = TRUE;         
    break;

    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn                       = TRUE;            
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2                  = TRUE;                       
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_LeftBtn_Selected      = TRUE;                
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_RightBtn_Not_Selected = TRUE;                  
    break;

    case TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn                       = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2                  = TRUE;      
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_RightBtn_Selected     = TRUE;            
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Forward_LeftBtn_Not_Selected  = TRUE;          
    break;

    default:
    //do nothing
    break;
  }

  return;
}

static void AP_HMI_Perp_Parkin_Overlay_Decoding(void)
{
  /* DD-ID: {2CC1215A-DD98-4f3d-B9B3-D345404552FE}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main = TRUE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn = TRUE;
  
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Left_Core = TRUE; 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE;              
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE;
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Right_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE;              
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE;
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Left_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Avail = TRUE; 
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Right_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Avail = TRUE;
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Left_Core = TRUE; 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Avail = TRUE;
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Right_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE;  
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Avail = TRUE;
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Left_Core = TRUE; 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Selected = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE; 
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Right_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Selected = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Not_Selected = TRUE; 
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Left_Core = TRUE; 
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Selected = TRUE;           
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE; 
    break;

    case TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE:
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Perp_Right_Core = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_RearInBtn_Selected = TRUE;           
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_FrontInBtn_Not_Selected = TRUE; 
    break;

    default:
    //do nothing
    break;
  }

  return;
}

static void AP_HMI_Scanning_Overlay_Decoding(void)
{
  /* DD-ID: {50DFAAD6-9470-4160-9872-1CA851051EDC}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main              = TRUE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scanning_Core        = TRUE;

  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Selected     = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Not_Selected = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Keep_Moving_Forward_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Searching_Text = TRUE;
      break;

    case TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Reduce_Speed_Text = TRUE;
      break;

    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Selected     = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Not_Selected = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Space_Found_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_STOP_Text = TRUE;
      AP_HMI_ParkSlot_Display_Processing();
      break;  

    case TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Space_Found_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_STOP_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Reduce_Speed_Text = TRUE;
      AP_HMI_ParkSlot_Display_Processing();
      break;

    case TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner1 = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_STOP_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Space_Found_Text = TRUE;
      AP_HMI_ParkSlot_Display_Processing();
    break;

    case TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Selected     = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Not_Selected = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Space_Found_Text = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Select_Space_Text = TRUE;
      AP_HMI_ParkSlot_Display_Processing();
      break;

    /*Remove Hands LEFT and RIGHT are SAME for HMI*/
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT:
    case TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Selected     = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Not_Selected = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn = TRUE;      
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = TRUE;
      AP_HMI_ParkSlot_Display_Processing();
      break;

    default:    
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scanning_Core = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkBtn_Selected = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ExitBtn_Not_Selected = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner1 = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Grey_Banner2 = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Select_Space_Text = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Space_Found_Text = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_STOP_Text = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Searching_Text = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Keep_Moving_Forward_Text = FALSE;
      // aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Scan_Reduce_Speed_Text = FALSE;
    break;
  }

  return;
}

static void AP_HMI_Disclaimer_Overlay_Decoding(void)
{
  /* DD-ID: {0A9955D3-925A-4113-A871-6A12E20C606A}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Disclaimer_Core = TRUE ; 
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BackBtn = TRUE ;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main = TRUE ;
  return;
}

static void AP_HMI_Park_Complete_Overlay_Decoding(void)
{
  /* DD-ID: {D3A20BC4-C5F5-49be-99D7-0A52A5A9FDAA}*/
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_BG_Main = TRUE ;
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_COMPLETE_PROCEED:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_Parkout_Done = TRUE ;
    break;
    case TeAP_e_HMIPopUp_COMPLETE_RELEASE:
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AP_ParkIn_Done = TRUE ;
    break;
    default:
    //do nothing
    break;
  }
  return;  
}
static void AP_HMI_TV_Text_Overlay_Encoding(void)
{
  /* DD-ID: {494D6397-0E1B-465f-B79A-BBAF0D58E2FF}*/

  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {  
    case TeAP_e_HMIPopUp_REMOVE_HANDS_FEET:
      screenReq.AP_HMI_TopRedBanner = TRB_REMOVE_HANDS_FEET;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR:
    case TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_ACTIVE_PARKSENSE_ENGAGED;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON:
      screenReq.AP_HMI_TopRedBanner = TRB_PAUSED_HOLD_BUTTON;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;
      
    case TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH:
      screenReq.AP_HMI_TopRedBanner = TRB_PAUSED_OBJECT_IN_PATH;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR:
    case TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_WAIT_FOR_STEER;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_MOVE_BACKWARD:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_MOVE_BACKWARD;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_STOP_REAR:
    case TeAP_e_HMIPopUp_STOP_FRONT:
      screenReq.AP_HMI_TopRedBanner = TRB_STOP;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_TO_CONTINUE_MANUEVER;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_SHIFT_TO_DRIVE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_MOVE_FORWARD:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_MOVE_FORWARD;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_SHIFT_TO_REVERSE:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_SHIFT_TO_REVERSE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT:
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR:
      screenReq.AP_HMI_TopRedBanner = TRB_PARKSENSE_SPEED_TOO_HIGH;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_COMPLETE_HMI_REAR:
    case TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_COMPLETE_HMI;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;
      
    case TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_DOOR_OPEN;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_LIFTGATE_OPEN;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_ESC_ACTIVE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_UNAVAILABLE_SPEED_TOO_HIGH;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_LOW_ACTIVE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_TRAILER_DETECTED;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_SERVICE_REQUIRED;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_WIPE_FRONT_SENSOR;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_WIPE_REAR_SENSOR;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_TEMP_NA_OVERLAY:
      screenReq.AP_HMI_TopRedBanner = TRB_NONE;
      screenReq.AP_HMI_TopBlackBanner = TBB_TEMPORARILY_UNAVAILABLE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CHECK_ENTIRE_SURROUNDINGS;
      break;

    case TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_BUTTON_PRESSED;
      break;

    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_CRUISE_CONTROL_ENGAGED;
      break;    
    
    case TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_DOOR_OPEN;
      break;    
    
    case TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_LIFTGATE_OPEN;
      break;    
    
    case TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL:
       screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_ESC_ACTIVE;
      break;   
    
    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_SPEED_TOO_HIGH;
      break;    
    
    case TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_LOW_ACTIVE;
      break;    
    
    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_TRAILER_DETECTED;
      break;    
    
    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_SERVICE_REQUIRED;
      break;    
    
    case TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_WIPE_FRONT_SENSOR;
      break;    
    
    case TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_WIPE_REAR_SENSOR;
      break;    
    
    case TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_TEMPORARILY_UNAVAILABLE;
      break;    
    
    case TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_STEERING_WHEEL_TOUCHED;
      break;    
    
    case TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_DRIVER_OVERRIDE;
      break;    
    
    case TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL:
      screenReq.AP_HMI_TopRedBanner = TRB_TAKE_CONTROL;
      screenReq.AP_HMI_TopBlackBanner = TBB_NONE;
      screenReq.AP_HMI_BottomBlackBanner = BBB_MANUAL_PARK_REQUIRED;
      break;
      
    default:
      break;
  }

  return;
}

static void AP_HMI_Fullscreen_Overlay_Decoding(void)
{
  /* DD-ID: {573DFFE2-2E1C-45d9-A281-39D1B28D4E25}*/
  screenReq.AP_HMI_Fullscreen = NONE_FULLSCREEN;
  
  switch(aHmiM_STM_v_Rx_HmiMRelatedData_e.CurrRequestedScreenByAP)
  {
    case TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = DOOR_OPEN_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = LIFEGATE_OPEN_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = ESC_ACTIVE_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = SPEED_TOO_HIGH_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = LO4_ACTIVE_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = TRAILER_CONNECTED_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = SERVICE_REQUIRED_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = FRONT_WIPE_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = REAR_WIPE_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = TEMP_NA_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = CRUISE_CONTROL_ENGAGED_FULLSCREEN;
      break;

    case TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN:
      screenReq.AP_HMI_Fullscreen = BUTTON_PRESS_FULLSCREEN;
      break;

    default:
      screenReq.AP_HMI_Fullscreen = NONE_FULLSCREEN;
      break;

  }
  return;
}
 
static void AP_HMI_ParkSlot_Display_Processing(void)
{
  /* DD-ID: {37538170-5E79-43b4-8868-4E22451A3447}*/
  for (int8_t pro_index = 0; pro_index < 6; pro_index++)
  {
    bool flag_execute = FALSE; 
    //If slot is not valid then dont show it.
    if(   (TRUE)
       && (     (FALSE)
            ||  (ParkingSlotID_E_L1 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
            ||  (ParkingSlotID_E_L2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
            ||  (ParkingSlotID_E_L3 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
            ||  (ParkingSlotID_E_R1 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
            ||  (ParkingSlotID_E_R2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
            ||  (ParkingSlotID_E_R3 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
          )
       && (     (FALSE)
            ||  (SlotSide_E_SLOT_RIGHT == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotSide)
            ||  (SlotSide_E_SLOT_LEFT  == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotSide)
          )
       && (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_isSlotValid_b)
      )
      {
        flag_execute = TRUE;   
      }

    uint16_t MidPoints[2];

    if (flag_execute)
    {      
      screenReq.AP_HMI_ParkSlot[pro_index].SlotType = aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotType;
      screenReq.AP_HMI_ParkSlot[pro_index].SlotID = aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID;
      
      //If slot is selected make it glow
      if(  (TRUE)
        && (screenReq.AP_HMI_ParkSlot[pro_index].SlotID  == HMI_to_FPA.m_selectedslotID)
        && (TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE == aHmiM_STM_v_Rx_HmiMRelatedData_e.LastRequestedScreenByAP)
      )
      { 
        screenReq.AP_HMI_ParkSlot[pro_index].SlotSelected = TRUE;
      }
      else
      {
        screenReq.AP_HMI_ParkSlot[pro_index].SlotSelected = FALSE;
      }
      
      MidPoints[0] = (uint16_t)((aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].Vertices[0].x + aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].Vertices[1].x)/2u);
      MidPoints[1] = (uint16_t)((aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].Vertices[3].x + aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].Vertices[2].x)/2u);
 
      //TODO : Check with Aruna regarding midpoints //
      uint16_t width_mid = (MidPoints[0] + MidPoints[1])/2;

      if(  (FALSE)
        || (ParkingSlotID_E_L1 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
        || (ParkingSlotID_E_L2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
        || (ParkingSlotID_E_L3 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
      )
      {
        if( (ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        {
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = AHMIM_STM_D_AP_PARKSLOT_X1;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = (AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y + width_mid/AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR) - AHMIM_STM_D_AP_PARKSLOT_WIDTH/2u;
        }
        else if((ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        {
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = AHMIM_STM_D_AP_PARKSLOT_X2;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = (AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y + width_mid/AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR) - AHMIM_STM_D_AP_PARKSLOT_HEIGHT/2u;
        }
        else
        {
          /*Do Nothing*/
        }
      }

      if(  (FALSE)
        || (ParkingSlotID_E_R1 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
        || (ParkingSlotID_E_R2 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
        || (ParkingSlotID_E_R3 == aHmiM_STM_v_Rx_HmiMRelatedData_e.ParkingSlotRawData[pro_index].m_SlotID)
      )
      {
        if( (ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        {
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = AHMIM_STM_D_AP_PARKSLOT_X3;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = (AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y + width_mid/AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR) - AHMIM_STM_D_AP_PARKSLOT_WIDTH/2u;
        }
        else if((ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        {
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = AHMIM_STM_D_AP_PARKSLOT_X3;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = (AHMIM_STM_D_AP_PIXEL_CAR_ORIGIN_Y + width_mid/AHMIM_STM_D_AP_WORLD_TO_PIXEL_FACTOR) - AHMIM_STM_D_AP_PARKSLOT_HEIGHT/2u;
        }
        else
        {
          /*DO nothing*/
        }
      }

      //dont show slot if going out of screen
      if( (FALSE)
          || (AHMIM_STM_D_AP_PARKSLOT_MIN_Y >= screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y)
          || ((AHMIM_STM_D_AP_PARKSLOT_MAX_Y <= (screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_WIDTH)) && (ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
          || ((AHMIM_STM_D_AP_PARKSLOT_MAX_Y <= (screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_HEIGHT)) && (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        )
      { 
        screenReq.AP_HMI_ParkSlot[pro_index].SlotType = ParkingSlotType_E_PW_NODIR;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotSelected = FALSE;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = 0u;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = 0u;

        if(screenReq.AP_HMI_ParkSlot[pro_index].SlotID  == HMI_to_FPA.m_selectedslotID)
        {
          HMI_to_FPA.m_selectedslotID         = ParkingSlotID_E_NONE;
          HMI_to_AP.SelectedSlotId            = HMI_to_FPA.m_selectedslotID;
        }
      }
      else
      {
        /*DO nothing*/
      }

    }
    else
    {
      #ifdef AP_LOGS
      appLogPrintf("Slot:%d invalid",pro_index);
      #endif
    }
  }

  //overlap prevention code, will only work if PLD continues to send sorted slot data
  // AP_HMI_ParkSlot_Overlap_Prevention(); // Disabled this functionality because now overlap prevention is done at AP side only.
  
  return;
}

static void AP_HMI_ParkSlot_Overlap_Prevention(void)
{
  /* DD-ID: {7B7A110A-46EC-47e5-ACF2-A213BC4B34DB}*/
  int8_t pro_index;
  bool Overlaps_Seen = FALSE;
  int16_t Slot_Shift = 0;

  /*This section is for Left Slots*/
  do
  {
    Overlaps_Seen = FALSE; /*Reset value here*/
    
    Slot_Shift = 0;
    if( (TRUE) /*Check if both slots are even valid*/
        &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L1-1].SlotType)
          || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L1-1].SlotType))
        &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotType)
          || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotType))
    )
    {
      Slot_Shift =  AHMIM_STM_D_AP_PARKSLOT_SEPRATION \
                        + ( screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L1-1].SlotPixelCoordinate_Y \
                            + ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L1-1].SlotType) ? AHMIM_STM_D_AP_PARKSLOT_WIDTH : AHMIM_STM_D_AP_PARKSLOT_HEIGHT )) \
                              - screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotPixelCoordinate_Y;

      if(Slot_Shift > AHMIM_STM_D_AP_PARKSLOT_SEPRATION) /*Means there was surely an overlap*/
      {
        /*shift 1st slot towards up and push 2nd slot towards down to eliminate overlap*/
        screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L1-1].SlotPixelCoordinate_Y -= Slot_Shift/2;
        screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotPixelCoordinate_Y += Slot_Shift/2;

        Overlaps_Seen = TRUE; /*THis push up and push down event may cause other overlaps hence make flag TRUE*/
      }

      Slot_Shift = 0;
      if( (TRUE) /*Check if both slots are even valid*/
      &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotType)
        || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotType))
      &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L3-1].SlotType)
        || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L3-1].SlotType))
      )
      {
        Slot_Shift =  AHMIM_STM_D_AP_PARKSLOT_SEPRATION \
                      + ( screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotPixelCoordinate_Y \
                          + ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotType) ? AHMIM_STM_D_AP_PARKSLOT_WIDTH : AHMIM_STM_D_AP_PARKSLOT_HEIGHT )) \
                          - screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L3-1].SlotPixelCoordinate_Y;

        if(Slot_Shift > AHMIM_STM_D_AP_PARKSLOT_SEPRATION) /*Means there was surely an overlap*/
        {
          /*shift 1st slot towards up and push 2nd slot towards down to eliminate overlap*/
          screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L2-1].SlotPixelCoordinate_Y -= Slot_Shift/2;
          screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_L3-1].SlotPixelCoordinate_Y += Slot_Shift/2;

          Overlaps_Seen = TRUE; /*THis push up and push down event may cause other overlaps hence make flag TRUE*/
        }
      }
    }
  }while(TRUE == Overlaps_Seen);

  /*This section is for Right Slots*/
  do
  {
    Overlaps_Seen = FALSE; /*Reset value here*/
    
    Slot_Shift = 0;
    if( (TRUE) /*Check if both slots are even valid*/
        &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R1-1].SlotType)
          || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R1-1].SlotType))
        &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotType)
          || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotType))
    )
    {
      Slot_Shift =  AHMIM_STM_D_AP_PARKSLOT_SEPRATION \
                        + ( screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R1-1].SlotPixelCoordinate_Y \
                            + ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R1-1].SlotType) ? AHMIM_STM_D_AP_PARKSLOT_WIDTH : AHMIM_STM_D_AP_PARKSLOT_HEIGHT )) \
                              - screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotPixelCoordinate_Y;

      if(Slot_Shift > AHMIM_STM_D_AP_PARKSLOT_SEPRATION) /*Means there was surely an overlap*/
      {
        /*shift 1st slot towards up and push 2nd slot towards down to eliminate overlap*/
        screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R1-1].SlotPixelCoordinate_Y -= Slot_Shift/2;
        screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotPixelCoordinate_Y += Slot_Shift/2;

        Overlaps_Seen = TRUE; /*THis push up and push down event may cause other overlaps hence make flag TRUE*/
      }

      Slot_Shift = 0;
      if( (TRUE) /*Check if both slots are even valid*/
      &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotType)
        || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotType))
      &&  ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R3-1].SlotType)
        || (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R3-1].SlotType))
      )
      {
        Slot_Shift =  AHMIM_STM_D_AP_PARKSLOT_SEPRATION \
                      + ( screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotPixelCoordinate_Y \
                          + ((ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotType) ? AHMIM_STM_D_AP_PARKSLOT_WIDTH : AHMIM_STM_D_AP_PARKSLOT_HEIGHT )) \
                          - screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R3-1].SlotPixelCoordinate_Y;

        if(Slot_Shift > AHMIM_STM_D_AP_PARKSLOT_SEPRATION) /*Means there was surely an overlap*/
        {
          /*shift 1st slot towards up and push 2nd slot towards down to eliminate overlap*/
          screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R2-1].SlotPixelCoordinate_Y -= Slot_Shift/2;
          screenReq.AP_HMI_ParkSlot[ParkingSlotID_E_R3-1].SlotPixelCoordinate_Y += Slot_Shift/2;

          Overlaps_Seen = TRUE; /*THis push up and push down event may cause other overlaps hence make flag TRUE*/
        }
      }
    }
  }while(TRUE == Overlaps_Seen);

  for (pro_index = 0; pro_index < 6; pro_index++)
  {
      //dont show slot if going out of screen
      if( (FALSE)
          || (AHMIM_STM_D_AP_PARKSLOT_MIN_Y >= screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y)
          || ((AHMIM_STM_D_AP_PARKSLOT_MAX_Y <= (screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_WIDTH)) && (ParkingSlotType_E_PW_PERPENDICULAR == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
          || ((AHMIM_STM_D_AP_PARKSLOT_MAX_Y <= (screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y + AHMIM_STM_D_AP_PARKSLOT_HEIGHT)) && (ParkingSlotType_E_PW_PARALLEL == screenReq.AP_HMI_ParkSlot[pro_index].SlotType))
        )
      { 
        screenReq.AP_HMI_ParkSlot[pro_index].SlotType = ParkingSlotType_E_PW_NODIR;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotSelected = FALSE;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_X = 0u;
        screenReq.AP_HMI_ParkSlot[pro_index].SlotPixelCoordinate_Y = 0u;

        if(screenReq.AP_HMI_ParkSlot[pro_index].SlotID  == HMI_to_FPA.m_selectedslotID)
        {
          HMI_to_FPA.m_selectedslotID         = ParkingSlotID_E_NONE;
          HMI_to_AP.SelectedSlotId            = HMI_to_FPA.m_selectedslotID;
        }
      }
      else
      {
        /*DO nothing*/
      }
  }

  return;
}

static void AP_HMI_Outputs(void)
{
  /* DD-ID: {D571B52C-8CEC-44cd-BD8A-87E3BA933994}*/

  return;
}

static uint8_t test_id;
static uint8_t test_delay;

static void AP_BUMPER_TEST(void)
{
  /* DD-ID: {A23C8D7C-31DB-4873-9DFA-29B3EC3F3779}*/
  if(test_delay<4u)
  {
    test_delay++;
  }
  else
  {
    test_delay=0;
    test_id++;
  }
  if(test_id<12u)
  {
    //do nothing
  }
  else
  {
    test_id=0;
  }

  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b      = (test_id == 0u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b    = (test_id == 1u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b     = (test_id == 2u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b      = (test_id == 3u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b     = (test_id == 4u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b       = (test_id == 5u) ? TRUE : FALSE;

  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b   = (test_id == 6u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b = (test_id == 7u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b  = (test_id == 8u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b   = (test_id == 9u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b  = (test_id == 10u) ? TRUE : FALSE;
  aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b    = (test_id == 11u) ? TRUE : FALSE;

  // appLogPrintf("%d : %d : %d \n"
  //               ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Red_b
  //               ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Red_b
  //               ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Red_b 
  //             );
  // appLogPrintf("%d : %d : %d \n"
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Red_b 
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Red_b
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Red_b   
  //         );

  // appLogPrintf("%d : %d : %d \n"
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontLeft_Yellow_b
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontCenter_Yellow_b
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_FrontRight_Yellow_b 
  //         );
  // appLogPrintf("%d : %d : %d \n"
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearLeft_Yellow_b 
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearCenter_Yellow_b
  //           ,aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.PDC_RearRight_Yellow_b   
  //         );                     

  // appLogPrintf("\n\n");
  return;
}

// static ME_Hydra2defs_E_ViewType_t PrevUseableView = ME_Hydra2defs_OEM_E_NoView;
static void EvaluateBottomBarButtons(void)
{
  /* DD-ID: {B62CD779-2B35-493f-AE77-197043AE2C20}*/
  ME_Hydra2defs_E_ViewType_t CurrUseableView = ME_Hydra2defs_OEM_E_NoView;
  if(ME_Hydra2defs_OEM_E_NonViewRequested == aHmiM_STM_v_RequestedScreenByHmiM_s.view)
  {
    CurrUseableView = aHmiM_STM_v_CurrentScreenOnZynqM_s.view;
  }
  else
  {
    CurrUseableView = aHmiM_STM_v_RequestedScreenByHmiM_s.view;
  }

  // if(PrevUseableView != CurrUseableView)
  // {
  //   PrevUseableView = CurrUseableView;
  //   appLogPrintf("CUV %d, RSH %d, CSZ %d",CurrUseableView, aHmiM_STM_v_RequestedScreenByHmiM_s.view, aHmiM_STM_v_CurrentScreenOnZynqM_s.view);
  // }

  if((FALSE)
  || (ME_Hydra2defs_OEM_E_RearTopView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_RearCrossPathView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_FrontCrossPathView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_FrontTopView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_BUNRV == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_BUZRV == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_FrontFacingCameraView == CurrUseableView)
  )
  {
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonNoSelect_b       = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonNoSelect_b     = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonNoSelect_b    = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonNoSelect_b      = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonNoSelect_b = TRUE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b  = TRUE;

    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonSelect_b       = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonSelect_b     = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonSelect_b    = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonSelect_b      = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonSelect_b = FALSE;
    aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonSelect_b  = FALSE;

    switch(CurrUseableView)
    {
      case ME_Hydra2defs_OEM_E_RearTopView:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_RearCrossPathView:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_FrontCrossPathView:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_FrontTopView:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_BUNRV:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_BUZRV:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonSelect_b = TRUE;
      break;
      case ME_Hydra2defs_OEM_E_FrontFacingCameraView:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonSelect_b = TRUE;
      break;
      default:
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonNoSelect_b       = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonNoSelect_b     = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonNoSelect_b    = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonNoSelect_b      = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonNoSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b  = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopRearButtonSelect_b       = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.RearCrossButtonSelect_b     = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontCrossButtonSelect_b    = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.TopFrontButtonSelect_b      = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.BackupRearCamButtonSelect_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonSelect_b  = FALSE;
      break;
    }

    if(FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonNoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.FrontFaceCamButtonSelect_b   = FALSE;
    }

    if((TRUE) 
    && (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
    && (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
    )
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b   = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = TRUE;
      MoreCam1Set = TRUE;
    }
    else if((TRUE) 
    && (FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
    && (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
    )
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b   = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = TRUE;
        MoreCam1Set = FALSE;
    }
    else if((TRUE) 
    && (TRUE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_FrwFacingCam)
    && (FALSE == aHmiM_STM_v_Rx_HmiMRelatedData_e.MePRX_b_AuxTrlrCam)
    )
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b   = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = TRUE;
      MoreCam1Set = TRUE;
    }
    else
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = TRUE;
    }

    if((TRUE)
    && (DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    && (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    )
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = FALSE; 
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b = FALSE; 
    }

    if((TRUE) 
      && ((TRUE == aHmiM_STM_v_ViewTriggerSetList_s.SFTBTN_SVC_AUX_PRESSED_b) || (AUX_CAMS_RQ_STS_ON == HMI_to_VCAN.IeSVS_b_AUXCamReqSts))
      && ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)|| (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)))
    {
      HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_ON;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b = aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1NoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2NoSelect_b = FALSE;    
    }

    if(((TRUE) 
      && (TRUE == aHmiM_STM_f_Check_MoreCams_BTN_PRESSED_b())
      && ((DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)|| (DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)))
      || ((MORE_CAMS_RQ_STS_ON == HMI_to_VCAN.IeSVS_b_MoreCamsReqSts) && (DISP_REAR_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)))
    {
      HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_ON;
      if (MoreCam1Set)
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = TRUE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = FALSE;
      }
      else
      {
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = TRUE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = FALSE;
      }
    }
    else if((DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e))
    {
      if(DISP_TRAILER_CAMERA == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
      {
        HMI_to_VCAN.IeSVS_b_AUXCamReqSts = AUX_CAMS_RQ_STS_OFF;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton1Select_b = FALSE;
        aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.AuxCamButton2Select_b = FALSE; 
      }

      HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = FALSE; 
    }
  }
  else if((FALSE)
  || (ME_Hydra2defs_OEM_E_TRG_L50_R50 == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRG_L25_R75 == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRG_L75_R25 == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRG_L100_R0 == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRG_L0_R100 == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRGLeftCurbView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_TRGRightCurbView == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_BlindLeft == CurrUseableView)
  || (ME_Hydra2defs_OEM_E_BlindRight == CurrUseableView)
  )
  {
    
    if((MORE_CAMS_RQ_STS_ON != HMI_to_VCAN.IeSVS_b_MoreCamsReqSts))
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1NoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2NoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton2Select_b = FALSE;
    }
    else
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = FALSE;
    
    if((TRUE)
    && (DISP_REAR_CAMERA != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    && (DISP_SVS_MORECAMS_POPUP != aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e)
    )
    {
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = FALSE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b  = FALSE;
    }

    // if((TRUE)
    // && ((ME_Hydra2defs_OEM_E_TRGLeftCurbView == CurrUseableView) || (ME_Hydra2defs_OEM_E_TRGRightCurbView == CurrUseableView))
    // && (TRUE == aHmiM_STM_v_GearNotReverse_Delayed_b)
    // )
    // {
    //   aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = FALSE;
    //   aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b  = FALSE;
    //   HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;
    // }

    if((TRUE) 
    && ((TRUE == aHmiM_STM_f_Check_MoreCams_BTN_PRESSED_b()) || (MORE_CAMS_RQ_STS_ON == HMI_to_VCAN.IeSVS_b_MoreCamsReqSts))
    && (TRUE == aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b))
    {
      HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_ON;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b  = TRUE;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsIconFullScreenNoSelect_b = FALSE;   
    }
    else if((DISP_SVS_MORECAMS_POPUP == aHmiM_STM_v_Rx_HmiMRelatedData_e.tgwDispStatus_e) && (MORE_CAMS_RQ_STS_ON == HMI_to_VCAN.IeSVS_b_MoreCamsReqSts))
    {
      HMI_to_VCAN.IeSVS_b_MoreCamsReqSts = MORE_CAMS_RQ_STS_OFF;
      aHmiM_STM_v_RequestedScreenByHmiM_s.overlays.MoreCamsButton1Select_b = FALSE;
    }
  }
  else
  {
    /*relax*/
  }
       
  if(memcmp(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t))!=0)
    {
      // appLogPrintf("EB ImgDefeat: %d, MoreCams %d, AUXCam %d \n"
      // ,HMI_to_VCAN.IeSVS_b_ImgDefeatReqSts
      // ,HMI_to_VCAN.IeSVS_b_MoreCamsReqSts
      // ,HMI_to_VCAN.IeSVS_b_AUXCamReqSts
      // );
      SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put(&HMI_to_VCAN);
      memcpy(&prev_HMI_to_VCAN, &HMI_to_VCAN, sizeof(SvsToVCAN_t));
      //printf("\n EVL_BOTT_BAR_BUT: time:%llu Line:%d SigMgr_PpSvsToVCAN_SvsToVCAN_t_Put", TimerP_getTimeInUsecs(), __LINE__);
      
    } 
}

static void CheckTRGLatch(void)
{
  /* DD-ID: {1A96D29B-923A-412c-871A-F5CB0A7F64F7}*/
  if(TRUE == TRG_Latched)
  {
    if((FALSE)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView2_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.X_BTN_PRESSED_b)
      || (TRUE == aHmiM_STM_v_ViewGuardSetList_s.GUARD_TGW_CAMERA_DISP_STAT_EQUAL_NONCAM_b)
      || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.GearToPark_b))
    {
      TRG_Latched = FALSE;
      // appLogPrintf("TRG Latch Broken Telematics");
    }


  }

  return;
}

static void Reset_BackupZoomViewMemory(void)
{
  /* DD-ID: {81BA80B0-965A-40c9-B74C-122372F5EE10}*/

if( FALSE
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView1_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView3_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView5_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView6_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView7_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView8_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView9_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView11_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView12_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView13_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.CamDispStsView14_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.REAR_TOP_BTN_PRESSED_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.REAR_CROSS_BTN_PRESSED_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FRONT_CROSS_BTN_PRESSED_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FRONT_TOP_BTN_PRESSED_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.X_BTN_PRESSED_b)
  || (TRUE == aHmiM_STM_v_ViewTriggerSetList_s.FFCV_BTN_PRESSED_b)
)
{
  aHmiM_STM_v_M_BURV_Memory_e = ME_Hydra2defs_OEM_E_BUNRV;
}

}

static void aHmiM_STM_f_StartScreenRequestTimeoutTimer(void)
{
  /* DD-ID: {1D842D21-74A8-480c-96A3-12A4D25B0E62}*/
  aHmiM_STM_v_EnableScreenRequestTimeoutTimer = TRUE;
  aHmiM_STM_v_LastScreenRequestTime_u64 = TimerP_getTimeInUsecs();
  //printf("\n Screen req timer started: %llu\n",aHmiM_STM_v_LastScreenRequestTime_u64);
}
static void aHmiM_STM_f_ResetScreenRequestTimeoutTimer(void)
{
  /* DD-ID: {FDD28B05-9114-43b8-A262-EF7E8962B23B}*/
  aHmiM_STM_v_EnableScreenRequestTimeoutTimer = FALSE;
  //printf("\n Screen req timer stopped\n");
}
static bool aHmiM_STM_f_IsScreenRequestTimeoutExpr(void)
{
  /* DD-ID: {4088B3AB-8F97-4ed8-9DBD-1CBFFDE4768D}*/
  uint64_t aHmiM_STM_v_CurScreenRequestTime_u64 = TimerP_getTimeInUsecs();
  bool retValue = FALSE;
  if((TRUE == aHmiM_STM_v_EnableScreenRequestTimeoutTimer) && ((aHmiM_STM_v_CurScreenRequestTime_u64 - aHmiM_STM_v_LastScreenRequestTime_u64) >  (HMI_XCP_SCREENREQ_TIMEOUT * 10000U)))
  {
    retValue =  TRUE;
    aHmiM_STM_f_ResetScreenRequestTimeoutTimer();
    //printf("\n Screen req timer expired: %llu, ReqViewID:%d -- %d, SvRes:%d -- %d, OvlBits:%d -- %d\n",aHmiM_STM_v_CurScreenRequestTime_u64,aHmiM_STM_v_RequestedScreenByHmiM_s.view, screenReq.MeSVS_e_ViewEngReqCode, aHmiM_STM_v_CurrentScreenOnZynqM_s.view, screenResponse.MeSVS_e_ViewEngResCode, memcmp(&screenResponse.MbSVS_bf_OverlayBitsRes, &screenReq.MbSVS_bf_OverlayBitsReq, sizeof(screenReq.MbSVS_bf_OverlayBitsReq)), memcmp(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, &aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays ,sizeof(OverlayBits_t)));
  }

  return retValue;
}

// Retry timer
static void aHmiM_STM_f_StartScreenRequestRetryTimer(void)
{
  /* DD-ID: {CA273BD1-063D-48a4-8ED8-EE33598FC8C6}*/
  aHmiM_STM_v_EnableScreenRequestRetryTimer = TRUE;
  aHmiM_STM_v_LastScreenRequestRetryTime_u64 = TimerP_getTimeInUsecs();
  //printf("\n Screen retry timer started:----: %llu, ReqViewID:%d -- %d, SvRes:%d -- %d, OvlBits:%d -- %d\n",aHmiM_STM_v_LastScreenRequestRetryTime_u64, aHmiM_STM_v_RequestedScreenByHmiM_s.view,screenReq.MeSVS_e_ViewEngReqCode, aHmiM_STM_v_CurrentScreenOnZynqM_s.view,screenResponse.MeSVS_e_ViewEngResCode, memcmp(&screenResponse.MbSVS_bf_OverlayBitsRes, &screenReq.MbSVS_bf_OverlayBitsReq, sizeof(screenReq.MbSVS_bf_OverlayBitsReq)), memcmp(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, &aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays ,sizeof(OverlayBits_t)));
}
static void aHmiM_STM_f_ResetScreenRequestRetryTimer(void)
{
    /* DD-ID: {374293B4-3274-45c9-A279-DBC6C6AEEEAC}*/
  aHmiM_STM_v_EnableScreenRequestRetryTimer = FALSE;
  //printf("\n Screen req timer stopped\n");
}
static bool aHmiM_STM_f_IsScreenRequestRetryExpr(void)
{
  uint64_t aHmiM_STM_v_CurScreenRequestRetryTime_u64 = TimerP_getTimeInUsecs();
  bool retValue = FALSE;
  if((TRUE == aHmiM_STM_v_EnableScreenRequestRetryTimer) && ((aHmiM_STM_v_CurScreenRequestRetryTime_u64 - aHmiM_STM_v_LastScreenRequestRetryTime_u64) >  (10 * 10000U)))
  {
    /* DD-ID: {FFE56819-1B16-40de-9148-165D404B2AA3}*/
    retValue =  TRUE;
    aHmiM_STM_f_ResetScreenRequestRetryTimer();
    //printf("\n Screen retry timer expired:----: %llu, ReqViewID:%d -- %d, SvRes:%d -- %d, OvlBits:%d -- %d\n",aHmiM_STM_v_CurScreenRequestRetryTime_u64,aHmiM_STM_v_RequestedScreenByHmiM_s.view, screenReq.MeSVS_e_ViewEngReqCode, aHmiM_STM_v_CurrentScreenOnZynqM_s.view, screenResponse.MeSVS_e_ViewEngResCode, memcmp(&screenResponse.MbSVS_bf_OverlayBitsRes, &screenReq.MbSVS_bf_OverlayBitsReq, sizeof(screenReq.MbSVS_bf_OverlayBitsReq)), memcmp(&aHmiM_STM_v_RequestedScreenByHmiM_s.overlays, &aHmiM_STM_v_CurrentScreenOnZynqM_s.overlays ,sizeof(OverlayBits_t)));
  }

  return retValue;
}
/* === End Of Source File ================================================= */
