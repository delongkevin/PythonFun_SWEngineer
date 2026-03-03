#ifndef HMI_STRUCTURES_H_
#define HMI_STRUCTURES_H_


#include "HMI_drv_par.h"
#include "ME_hydra2defs_OEM.h"
#include "SignalDef.h"
#include "TRSC_SM_VC_Int_types.h"
//#include "External_Dependency.h"


typedef unsigned char           BOOL;
typedef unsigned char           u8;
typedef signed char             s8;
typedef unsigned short int      u16;
typedef signed short int        s16;
typedef unsigned long int       u32;
typedef signed long int         s32;
typedef unsigned long long      u64;
typedef signed long long        s64;
typedef float                   f32;
typedef double                  d64;


#ifndef FALSE
 #define FALSE (0)
#endif

 #ifndef TRUE
  #define TRUE (1)
#endif



//Used In HMI from SigConverter

#define ASIGCONVERTER_D_STEERING_WHEEL_ANGLE_SNA   0x3FFF
#define ASIGCONVERTER_D_VEHSPEED_SNA               0xFFFF


typedef enum aSigConverter_E_ModuleState_e
{
  aSigConverter_E_NotInit = 0u,
  aSigConverter_E_InitComplete,
  aSigConverter_E_FirstRunDone
} aSigConverter_E_ModuleState_t;


typedef enum aFailM_E1_ImageDefeat_Error_e
{
  ImageDefeat1_ForceOFF  = 0u,   /* Image Defeat Signal should be sent as 0 over Vehicle CAN */
  ImageDefeat1_ForceON   = 1u,   /* Image Defeat Signal should be sent as 1 over Vehicle CAN -> No View will be provided */
  ImageDefeat1_NoError   = 2u    /* Image Defeat Signal should be sent as it would be in normal HMI operation Mode */
}aFailM_E1_ImageDefeat_Error_t;

typedef enum aFailM_E1_SoftBtn_Error_e
{
  SoftBtns1_NotFunctional  = 0u, /* Soft Buttons should not be selectable by HMI / Display user input */
  SoftBtns1_Functional     = 1u  /* Soft Buttons should be available for selection as in normal HMI operation Mode */
}aFailM_E1_SoftBtn_Error_t;

typedef enum aFailM_E1_DynOvl_Error_e
{
  DynOvl1_ForceOFF = 0u,         /* Dynamic Overlays (Trajectories) should never be visible in this Mode */
  DynOvl1_NoError  = 1u          /* Dynamic Overlays (Trajectories) are handled as in normal HMI Operation Mode */
}aFailM_E1_DynOvl_Error_t;

typedef enum aFailM_E1_View_Error_e
{
  View1_ForceDEFAULT = 0u,       /* Only the Default (Rear-Top) View should be displayed */
  View1_NoError      = 1u        /* The View which is selected by HMI as in normal operation Mode should be displayed */
}aFailM_E1_View_Error_t;

//! FZ Commented out as there was no use of this struct and it seems to be added by error
// typedef enum ME_Hydra2defs_E_CameraID_e
// {
//   CamID1_None    = 0,
//   CamID1_Front   = 1,
//   CamID1_Left    = 2,
//   CamID1_Rear    = 3,
//   CamID1_Right   = 4,
//   CamID1_5th     = 5,
//   CamID1_Invalid = 6
// } ME_Hydra2defs_E_CameraID_t;


typedef enum aSigConverter_E_DOOR_AJAR_e
{
  DoorCLOSED = 0x0, /* own define, not defined in DBC */
  DoorOPEN   = 0x1  /* own define, not defined in DBC */
} aSigConverter_E_DOOR_AJAR_t;


typedef enum aSigConverter_E_PRND_STAT_e
{
  PRND_STAT_NA    = kPRND_STAT_LVR_NA,
  PRND_STAT_P     = kPRND_STAT_LVR_P,  /* Park */
  PRND_STAT_R     = kPRND_STAT_LVR_R,  /* Reverse */
  PRND_STAT_N     = kPRND_STAT_LVR_N,  /* Neutral */
  PRND_STAT_D     = kPRND_STAT_LVR_D,  /* Drive */
  PRND_STAT_NOT_R = kPRND_STAT_NOT_R,  /* Not Reverse */
  PRND_STAT_UNDEF = 0xA,               /* Undefined Value */
  PRND_STAT_SNA   = kPRND_STAT_SNA

} aSigConverter_E_PRND_STAT_t;


typedef enum aSigConverter_E_CM_TCH_STAT_e
{
  TCH_NOT_PSD     = kCM_TCH_STAT_TCH_NOT_PSD,
  TCH_PSD         = kCM_TCH_STAT_TCH_PSD,
  TCH_PS_CAN      = kCM_TCH_STAT_TCH_PS_CAN,
  TCH_CFG_RES     = kCM_TCH_STAT_TCH_CFG_RES,
  TCH_CFG_OFFSET  = kCM_TCH_STAT_TCH_CFG_OFFSET,
  TCH_CFG_MAX     = kCM_TCH_STAT_TCH_CFG_MAX,
  CM_TCH_STAT_SNA = kCM_TCH_STAT_SNA
} aSigConverter_E_CM_TCH_STAT_t;


typedef enum aSigConverter_E_REV_GEAR_e
{
  REV_GEAR_NOT_ENGAGED  = 0x00,
  REV_GEAR_ENGAGED      = 0x01,
  REV_GEAR_SNA          = 0x02
} aSigConverter_E_REV_GEAR_t;


typedef enum aSigConverter_E_VC_Trans_Equipped
{
  TRANS_AUTOMATIC = 0x00,
  TRANS_MANUAL    = 0x01,
  TRANS_SNA       = 0x02
} aSigConverter_E_VC_Trans_Equipped_t;

typedef enum aSigConverter_E1_VC_VEH_LINE_e
{
  VEH_LINE1_NONE                        = kVC_VEH_LINE_VEH_NONE,
  VEH_LINE1_WK                          = kVC_VEH_LINE_VEH_WK,
  VEH_LINE1_LX                          = kVC_VEH_LINE_VEH_LX,

  VEH_LINE1_JC                          = kVC_VEH_LINE_VEH_JC,
  VEH_LINE1_DS                          = kVC_VEH_LINE_VEH_DS,
  VEH_LINE1_D2                          = kVC_VEH_LINE_VEH_D2,
  VEH_LINE1_DD                          = kVC_VEH_LINE_VEH_DD,
  VEH_LINE1_DP                          = kVC_VEH_LINE_VEH_DP,
  VEH_LINE1_DJ                          = kVC_VEH_LINE_VEH_DJ,
  VEH_LINE1_WD                          = kVC_VEH_LINE_VEH_WD,
  VEH_LINE1_DX                          = kVC_VEH_LINE_VEH_DX,
  VEH_LINE1_LD                          = kVC_VEH_LINE_VEH_LD,
  VEH_LINE1_M156                        = kVC_VEH_LINE_VEH_M156,
  VEH_LINE1_ZD                          = kVC_VEH_LINE_VEH_ZD,
  VEH_LINE1_LA                          = kVC_VEH_LINE_VEH_LA,
  VEH_LINE1_RU                          = kVC_VEH_LINE_VEH_RU,
  VEH_LINE1_M161                        = kVC_VEH_LINE_VEH_M161,
  VEH_LINE1_WS                          = kVC_VEH_LINE_VEH_WS,
  VEH_LINE1_DF                          = kVC_VEH_LINE_VEH_DF,
  VEH_LINE1_JL                          = kVC_VEH_LINE_VEH_JL,
  VEH_LINE1_M157                        = kVC_VEH_LINE_VEH_M157,
  VEH_LINE1_WL                          = kVC_VEH_LINE_VEH_WL,
  VEH_LINE1_DT                          = kVC_VEH_LINE_VEH_DT,
  VEH_LINE1_DU                          = kVC_VEH_LINE_VEH_DU,
  VEH_LINE1_PF                          = kVC_VEH_LINE_VEH_PF,
  VEH_LINE1_KL                          = kVC_VEH_LINE_VEH_KL,
  VEH_LINE1_UF                          = kVC_VEH_LINE_VEH_UF,
  VEH_LINE1_UT                          = kVC_VEH_LINE_VEH_UT,

  VEH_LINE1_MAGNAJEEP_FORD_MOUNTING     = 253,
  VEH_LINE1_MAGNAJEEP_CHRYSLER_MOUNTING = 254,

  VEH_LINE1_SNA                         = kVC_VEH_LINE_SNA
} aSigConverter_E1_VC_VEH_LINE_t;


typedef enum aSigConverter_E_VC_OFFRoadCameraPresent_e
{
  OFFRoadCamera_Prsnt_FALSE  = FALSE,
  OFFRoadCamera_Prsnt_TRUE   = TRUE,
  OFFRoadCamera_Prsnt_SNA    = 0x2
} aSigConverter_E_VC_OFFRoadCameraPresent_t;


typedef enum aSigConverter_E_VC_NetCfg_TRSCM_e
{
  TRSCM_Prsnt_FALSE  = FALSE,
  TRSCM_Prsnt_TRUE   = TRUE,
  TRSCM_Prsnt_SNA    = 0x2
} aSigConverter_E_NetCfg_TRSCM_t;

typedef enum aSigConverter_E_CmdIgnStat_e
{
  IGN_LK          = kCmdIgnStat_IGN_LK,
  IGN_OFF         = 0x1, /* not defined in drv_par.h */
  IGN_ACC         = 0x2, /* not defined in drv_par.h */
  IGN_OFF_ACC     = kCmdIgnStat_IGN_OFF_ACC,
  IGN_RUN         = kCmdIgnStat_IGN_RUN,
  IGN_START       = kCmdIgnStat_IGN_START,
  IGN_SNA         = kCmdIgnStat_SNA
} aSigConverter_E_CmdIgnStat_t;


typedef enum aSigConverter_E_TGW_DISP_STAT_e
{
  DISP_OFF             		= kTGW_CAMERA_DISP_STAT_DISP_NON_CAMERA,
  DISP_REAR_CAMERA     		= kTGW_CAMERA_DISP_STAT_DISP_SURROUND_VIEW_CAMERA,  /* This is our Surround View System */
  DISP_TRAILER_CAMERA  		= kTGW_CAMERA_DISP_STAT_DISP_TRAILER_CAMERA,  /* This is not our Surround View System */
  DISP_WIRLESS_CAMERA  		= kTGW_CAMERA_DISP_STAT_DISP_WIRLESS_CAMERA,  /* This is not our Surround View System */
  DISP_SVS_MORECAMS_POPUP	= kTGW_CAMERA_DISP_STAT_DISP_SVS_MORECAMS_POPUP,
  TGW_DISP_STAT_SNA    		= kTGW_CAMERA_DISP_STAT_SNA
} aSigConverter_E_TGW_DISP_STAT_t;


typedef enum aSigConverter_E_PTS_Alr_e
{
  PTS1_ALR_NOD   = kPTS_AlrFL_PTS_ALR_NOD,
  PTS1_ALR_ARC1  = kPTS_AlrFL_ARC1,
  PTS1_ALR_ARC2  = kPTS_AlrFL_ARC2,
  PTS1_ALR_ARC3  = kPTS_AlrFL_ARC3,
  PTS1_ALR_ARC4  = kPTS_AlrFL_ARC4,
  PTS1_ALR_ARC5  = kPTS_AlrFL_ARC5,
  PTS1_ALR_ARC6  = kPTS_AlrFL_ARC6,
  PTS1_ALR_SNA   = kPTS_AlrFL_SNA
} aSigConverter_E_PTS_Alr_t;


typedef enum aSigConverter_E_CameraDisplaySts2
{
  CameraDisplaySts2_OFF      = kCameraDisplaySts2_OFF    , /* inactive, not pressed                */
  CameraDisplaySts2_View1    = kCameraDisplaySts2_VIEW_1 , /* Normal Surround View Button pressed  */
  CameraDisplaySts2_View2    = kCameraDisplaySts2_VIEW_2 , /* TowBall View Button pressed          */
  CameraDisplaySts2_View3    = kCameraDisplaySts2_VIEW_3 , /* FFCV View Button pressed             */
  CameraDisplaySts2_View4    = kCameraDisplaySts2_VIEW_4 , /* CHMSL View Button pressed - unused   */
  CameraDisplaySts2_View5    = kCameraDisplaySts2_VIEW_5 ,
  CameraDisplaySts2_View6    = kCameraDisplaySts2_VIEW_6 , /* TRG Left View Button pressed         */
  CameraDisplaySts2_View7    = kCameraDisplaySts2_VIEW_7 , /* TRG Right View Button pressed        */
  CameraDisplaySts2_View8    = kCameraDisplaySts2_VIEW_8 , /* TRG Left View Button pressed         */
  CameraDisplaySts2_View9    = kCameraDisplaySts2_VIEW_9 , /* TRG Right View Button pressed        */
  CameraDisplaySts2_View11   = kCameraDisplaySts2_VIEW_11, /* Top+Rear View Button pressed         */
  CameraDisplaySts2_View12   = kCameraDisplaySts2_VIEW_12, /* Top+Front View Button pressed        */
  CameraDisplaySts2_View13   = kCameraDisplaySts2_VIEW_13, /* Front Cross Path View Button pressed */
  CameraDisplaySts2_View14   = kCameraDisplaySts2_VIEW_14, /* Rear Cross Path View Button pressed  */
  CameraDisplaySts2_Enforcer = 0xFFFFFFFF
} aSigConverter_E_CameraDisplaySts2_t;


/* -------------------------- HMI RELATED TX SIGNALS ------------------------ */
#define IMAGE_DEFEAT_RQ_STS_OFF  (BOOL)0u
#define IMAGE_DEFEAT_RQ_STS_ON   (BOOL)1u

#define MORE_CAMS_RQ_STS_OFF     (BOOL)0u
#define MORE_CAMS_RQ_STS_ON      (BOOL)1u

#define AUX_CAMS_RQ_STS_OFF      (BOOL)0u
#define AUX_CAMS_RQ_STS_ON       (BOOL)1u


typedef enum aSigConverter_E_DisplayView3
{
  DisplayView3_ViewOFF  = kDisplayView3_OFF,
  DisplayView3_View1    = kDisplayView3_VIEW_1,
  DisplayView3_View2    = kDisplayView3_VIEW_2,
  DisplayView3_View3    = kDisplayView3_VIEW_3,
  DisplayView3_View4    = kDisplayView3_VIEW_4,
  DisplayView3_View5    = kDisplayView3_VIEW_5,
  DisplayView3_View6    = kDisplayView3_VIEW_6,
  DisplayView3_View7    = kDisplayView3_VIEW_7,
  DisplayView3_View8    = kDisplayView3_VIEW_8,
  DisplayView3_View9    = kDisplayView3_VIEW_9,
  DisplayView3_View10   = kDisplayView3_VIEW_10,
  DisplayView3_View11   = kDisplayView3_VIEW_11,
  DisplayView3_View12   = kDisplayView3_VIEW_12,
  DisplayView3_View13   = kDisplayView3_VIEW_13,
  DisplayView3_View14   = kDisplayView3_VIEW_14,
  DisplayView3_View15   = kDisplayView3_VIEW_15,
  DisplayView3_View16   = kDisplayView3_VIEW_16,
  DisplayView3_View17   = kDisplayView3_VIEW_17,
  DisplayView3_View18   = kDisplayView3_VIEW_18,
  DisplayView3_View19   = kDisplayView3_VIEW_19,
  DisplayView3_Enforcer = 0xFFFFFFFF
} aSigConverter_E_DisplayView3_t;

typedef enum aSigConverter_E_SVC_Features_s
{
  /* Supported Features */
  SVC_GRIDLINES        = kCFG_FEATURE_SVC_GRIDLINES,
  SVC_DELAY            = kCFG_FEATURE_SVC_DELAY,
  SVC_FFCV_GRIDLINES   = kCFG_FEATURE_CFG_FFC_GRIDLINES,
  SVC_CHMSL_GRIDLINES  = kCFG_FEATURE_CFG_CHMSL_DYN_CNTR
} aSigConverter_E_SVC_Features_t;



typedef enum aSigConverter_E_TRSC_STAT_e
{
  TRSC_OFF          = kTRSC_STAT_Off,
  TRSC_STANDBY      = kTRSC_STAT_Standby,
  TRSC_CALIBRATING  = kTRSC_STAT_Calibrating,
  TRSC_PRE_ACTIVE   = kTRSC_STAT_PreActive,
  TRSC_ACTIVE       = kTRSC_STAT_Active,
  TRSC_SNA          = kTRSC_STAT_SNA,
  TRSC_INVALID      = 0xFF,
} aSigConverter_E_TRSC_STAT_t;

/* Steering wheel angle sensor status */
typedef enum aSigConverter_E_LRWS_ST_e
{
  LRWS_ST_OK      = kLRWS_ST_OK,
  LRWS_ST_INI     = kLRWS_ST_INI,
  LRWS_ST_ERR     = kLRWS_ST_ERR,
  LRWS_ST_ERR_INI = kLRWS_ST_ERR_INI,
  LRWS_ST_SNA     = kLRW_SNA
} aSigConverter_E_LRWS_ST_t;




typedef enum aSigConverter_E_VC_Aux_Trailer_CameraPresent_e
{
  Aux_Trailer_Camera_Prsnt_FALSE  = FALSE,
  Aux_Trailer_Camera_Prsnt_TRUE   = TRUE,
  Aux_Trailer_Camera_Prsnt_SNA    = 0x2
} aSigConverter_E_VC_Aux_Trailer_CameraPresent_t;


typedef struct aSigConverter_CM_TCH_COORD_s
{
  u16 X_u16;
  u16 Y_u16;
} aSigConverter_S_CM_TCH_COORD_t;

typedef struct BCM_FD_29_s
{
  u8 ITBM_TrlrStatus;
}ME_VehInp_BCM_FD_29_t;

typedef struct BCM_FD_27_s
{
  uint8 TrailerConnSts;
}ME_VehInp_BCM_FD_27_t;


/* In this struct all HMI Relevant Rx Signals are defined */
typedef struct aSigConverterTypes_S_Rx_HmiRelatedData
{
  aSigConverter_E_LRWS_ST_t                              lrwsST_e;                 /* Steering Wheel Angle Status */
  aSigConverter_E_DOOR_AJAR_t                            TailgateAJAR_e;           /* Tailgate Open/Closed */
  aSigConverter_E_DOOR_AJAR_t                            LeftFrontAJAR_e;          /* Left Front Door Open/Closed */
  aSigConverter_E_DOOR_AJAR_t                            RightFrontAJAR_e;         /* Right Front Door Open/Closed */
  aSigConverter_E_DOOR_AJAR_t                            LeftRearAJAR_e;           /* Left Rear Door Open/Closed */
  aSigConverter_E_DOOR_AJAR_t                            RightRearAJAR_e;          /* Right Rear Door Open/Closed */
  aSigConverter_E_REV_GEAR_t                             revGear_e;                /* Reverse Gear (for Auto&Man Transmission) */
  aSigConverter_E_CM_TCH_STAT_t                          tchScrnStatus_e;          /* Touch Screen Status */
  aSigConverter_E_CM_TCH_STAT_t                          prev_tchScrnStatus_e;
  aSigConverter_S_CM_TCH_COORD_t                         tchScrnCoord_s;           /* Touch Screen Coordinates */
  aSigConverter_S_CM_TCH_COORD_t                         tchScrnCoordRaw_s;        /* Touch Screen Coordinates Raw */
  aSigConverter_E_CmdIgnStat_t                           ignitionStatus_e;         /* Ignition Status */
  aSigConverter_E_CmdIgnStat_t                           prev_ignitionStatus_e;
  aSigConverter_E_PRND_STAT_t                            prndStatus_e;             /* P(R)ND for Automatic Transmission */
  aSigConverter_E_PRND_STAT_t                            prev_prndStatus_e;             /* P(R)ND for Automatic Transmission */
  aSigConverter_E_TGW_DISP_STAT_t                        tgwDispStatus_e;          /* Status of which Application is currently Displayed on HU (DISP_REAR_CAMERA == CVPM) */
  aSigConverter_E_VC_Trans_Equipped_t                    transEquipped_e;          /* Equipped Transmission Type (Auto/Man) */
  f32                                                    steeringWheelAngle_f32;   /* Steering Wheel Angle */
  f32                                                    vehicleSpeed_f32;         /*Defect 378582 Fix, Changing variable u8/u16 to float f32*//* Vehicle Speed */
  BOOL                                                   SVC_Delay_Feature_b;      /* Delay feature */
  BOOL                                                   SVC_Dynamic_Gridlines_Feature_b;  /* Gridlines feature - Driver configurable feature if Dynamic Gridlines should be enabled or disabled */
  BOOL                                                   SVC_FFCV_Gridlines_Feature_b;     /* Gridlines feature - Driver configurable feature if FFCV Dynamic Gridlines should be enabled or disabled */
  BOOL                                                   SVC_Static_Gridlines_Feature_b;   /* Gridlines feature - Static Gridlines enabled or disabled*/
  uint8                                                  LanguageSelection_u8;
  aSigConverter_E1_VC_VEH_LINE_t                         vehicleLine_e;            /* Type of Vehicle Variant */
  aSigConverter_E_CameraDisplaySts2_t                    CameraDisplaySts2_e;      /* HeadUnit Button Handling */
  aSigConverter_E_CameraDisplaySts2_t                    prev_CameraDisplaySts2_e;
  aSigConverter_E_TRSC_STAT_t                            trscStat_e;
  aSigConverter_E_NetCfg_TRSCM_t                         NetCfg_TRSCM_e;

  /* ============ TIMEOUTS ============ */
  BOOL                                GW_C_I6_timeout_b;        /* Timeout for message GW_C_I6 (lrw & lrws_st) */
  ME_VehInp_BCM_FD_29_t               Ie_VBII_ITBM_TrlrStat;

  //!THA VARIABLES
  aSigConverter_E_THAScreenRequest_t      THA_ScreenRequest_e;     /* THA Feature Screen Request States */
  aSigConverter_E_THAScreenRequest_t      THA_ScreenResponse_e;    /* THA Feature Screen Set Reponse */
  uint16_t                                THA_LongHitchCplrDiff;   /*Coupler Hitch Longitudinal Difference in pixel*/
  BOOL                                    THA_Is_Valid_Tch_Zone;   /* THA View Zoom response*/
  //!!!!!!!!!!!!!!!!!!!
  
  //!TRSC VARIABLES
  TeTRSC_e_TrlrCalInfo TrailerCalibrationStatus;
  real32_T TadAngle;
  TeTRSC_e_TrlrAngSign TrailerAngleSign;

  real32_T KnobAngle;
  real32_T JackKnifeAngle;
  real32_T MaxTadAngle;
  TeTRSC_e_TRSCStat TrscStatus;

  uint8 TrailerConnectionStatus;
  uint8 ItbmTrailerStatus;
  uint8 MeTRSC_e_TrlrPrsntInfo;

  //!!/**************************PROXI***************************************/
	uint8 MePRX_e_VariantID;             // Varaint ID <$ $>
  uint8 MePRX_e_VehLineCfg;				     // VEHICLE_LINE_CONFIGURATION Proxi data
  uint8 MePRX_e_Wheelbase;				     // Wheelbase proxi parameter
  uint8 MePRX_e_SteerRatRackPinionType;// Steering_Ratio_Rack_Pinion_Type Proxi data
  uint8 MePRX_e_RadDispType;           // 
  uint8 MePRX_e_MirrorType;        		 // Mirrors Type  
  uint8 MePRX_e_PAMTunSet;             // PAM Tuning set for Front Cam Position
  uint8 MePRX_e_AutonomyLvl; 			     // Autonomy Level Proxi Parameter
	
  boolean MePRX_b_SurroundViewCamera;   // Surround_View_Camera Proxi Data
  boolean MePRX_b_FrwFacingCam;       	// Forward Facing Camera     0-> Absent 1-> Present
  boolean MePRX_b_AuxTrlrCam;          	// Auxilliary Trailer Camera    0-> Absent 1-> Present
  boolean MePRX_b_CANNode95;           	// ITBM/ITCM Module present status   0-> Absent 1-> Present
  boolean MePRX_b_CanNode27;            // ASCM Configuration  
  boolean MePRX_b_TRGPresence;          // Trailer Reverse Guidance Feature Present status 0-> Absent 1-> Present
  boolean MePRX_b_TRSCPresence;         // Trailer Reverse Steering Control Feature Present status   0-> Absent 1-> Present
  boolean MePRX_b_TrlrHitchAssPres;     // Trailer Hitch Assistance Presense related Proxi
  boolean MePRX_b_CANNode63;
 /* HMI degradation flags */ 
  uint8                               MeFID_SVS_Disabled;
  uint8                               MeFID_SVS_LIMMod1;
  uint8                               MeFID_SVS_LIMMod2;
  uint8                               MeFID_SVS_LIMMod3;
  uint8                               MeFID_SVS_LIMMod4;
  uint8                               MeFID_SVS_LIMMod5;
  uint8                               MeFID_SVS_LIMMod6;
  uint8                               MeFID_SVS_LIMMod7;
  uint8                               MeFID_SVS_LIMMod8;
  uint8                               MeFID_SVS_LIMMod9;
  uint8                               MeFID_SVS_LIMMod10;
  uint8                               MeFID_SVS_LIMMod11;
  uint8                               MeFID_SVS_LIMModOpenDoor;
  /*For Future Use*/
  /*
  boolean MePRX_b_TrlrSurroundPresence;	// Trailer Surround Present Status   0-> Absent 1-> Present
  boolean MePRX_b_ParkSenseCamView;    	// Park Sensense Camera View Present Status    0-> Absent 1-> Present
  boolean MePRX_b_DigTVfeature;    		// Digital Television Feature Enabled Status 0-> Disabled 1-> Enabled
  uint8   MePRX_e_CountryCode;          // Country Code
  uint16 	MePRX_e_ModelYear;          // Model Year
  */
 //!!/**************************PROXI***************************************/


//!!/****************** AutoPark HMI Inputs ***********************************/
  IParkingSlotData_t ParkingSlotRawData[6]; /*We will later conver this to pixel co-ordinates via compuations done in STM_Fuctions.c*/
  
  TeAP_e_HMIPopUp CurrRequestedScreenByAP;
  TeAP_e_HMIPopUp LastRequestedScreenByAP;

  TeAP_e_Alert  APA_Arc_FL_e;  /* Park Distance Warning Front Left */
  TeAP_e_Alert  APA_Arc_FC_e;  /* Park Distance Warning Front Center */
  TeAP_e_Alert  APA_Arc_FR_e;  /* Park Distance Warning Front Right */
  TeAP_e_Alert  APA_Arc_RL_e;  /* Park Distance Warning Rear Left */
  TeAP_e_Alert  APA_Arc_RC_e;  /* Park Distance Warning Rear Center */
  TeAP_e_Alert  APA_Arc_RR_e;  /* Park Distance Warning Rear Right */

  TeAP_e_GraphicFlshRate APA_FlashRate_FL_e;
  TeAP_e_GraphicFlshRate APA_FlashRate_FC_e; 
  TeAP_e_GraphicFlshRate APA_FlashRate_FR_e;
  TeAP_e_GraphicFlshRate APA_FlashRate_RL_e;
  TeAP_e_GraphicFlshRate APA_FlashRate_RC_e;
  TeAP_e_GraphicFlshRate APA_FlashRate_RR_e;
//!!/***************************************************************************/
} aSigConverterTypes_S_Rx_HmiMRelatedData_t;

//Copied from HMI_STM_Functions.
typedef struct aZynqM_S_ScreenType
{
  ME_Hydra2defs_E_ViewType_t      view;
  OverlayBits_t overlays;
} aZynqM_S_ScreenType_t;

// static aSigConverterTypes_S_Tx_HmiMRelatedData_t aSigConverter_v_Tx_HmiRelatedData;

typedef struct aSigConverterTypes_S_Tx_HmiRelatedData
{
  BOOL SPM_Req_AP;
  BOOL imageDefeatRqst_b;    /* 1 Bit */
  BOOL MoreCamsRQSts_b;      /* 1 bit */
  BOOL aux_cam_request;      /* 1 Bit *//*Req Id : 498356*/
  BOOL reserved1;
  aSigConverter_E_DisplayView3_t HMIView;
  // u16 pitch;
  // u16 rollangle;
  // u16 yaw;
} aSigConverterTypes_S_Tx_HmiMRelatedData_t;



typedef struct aFailM_S1_HmiM_Errors_s
{
  aFailM_E1_ImageDefeat_Error_t  ImageDefeat_Error_e;
  aFailM_E1_SoftBtn_Error_t      SoftBtn_Error_e;
  aFailM_E1_DynOvl_Error_t       DynOvl_Error_e;
  aFailM_E1_View_Error_t         View_Error_e;

  /* CAM_NA_Bitfield_u8
   *
   * Bit Encoded Variable with the following structure:
   *
   * Problems with Left Cam  (Bit 1)     00000001 -> 0x01
   * Problems with Right Cam (Bit 2)     00000010 -> 0x02
   * Problems with Front Cam (Bit 3)     00000100 -> 0x04
   * Problems with Rear Cam  (Bit 4)     00001000 -> 0x08
   * */
  u8                            CAM_NA_Bitfield_u8;
  BOOL                          No_TRA_View_b;
  BOOL                          TopVideoBlanked_b;
}aFailM_S1_HmiM_Errors_t;

typedef enum aHmiM_E_TrgStatus_e
{
  TRG_INACTIVE = kTRG_INACTIVE,
  TRG_AUTO_PAN = kTRG_AUTO_PAN,
  TRG_MANU_PAN = kTRG_MANU_PAN,
  TRG_STAT_SNA = kTRG_STAT_SNA
}aHmiM_E_TrgStatus_t;

/* Enumeration used to check status of backing event of vehicle */
typedef enum back_Event_Sts_e

{
  BACK_EVENT_START= 0,
  BACK_EVENT_IN_PROCESS = 1,
  BACK_EVENT_END = 2
}back_Event_Sts_t;

//extern aSigConverterTypes_S_Tx_HmiMRelatedData_t aHmiM_STM_v_Tx_HmiMRelatedData_e;
//end

#endif
