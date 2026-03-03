#ifndef HMI_SVS_H_
#define HMI_SVS_H_

#include "PlatformDataTypes.h"
#if !defined(VCAST)
#include "AutoPark_Input_Output.h"
#endif

#if defined(VCAST)
#include "CrossplatformCommon.h"
#include "TeAP_e_HMIPopUp.h"
#endif
/*****************************************************************************************************/
/*							Error capture from FailSafe Manger                                       */
/*****************************************************************************************************/
typedef enum aFailM_E_ImageDefeat_Error_e
{
  ImageDefeat_ForceOFF  = 0u,   /* Image Defeat Signal should be sent as 0 */
  ImageDefeat_ForceON   = 1u,   /* Image Defeat Signal should be sent as 1 -> No View will be provided */
  ImageDefeat_NoError   = 2u    /* Image Defeat Signal should be sent as it would be in normal HMI operation Mode */
} aFailM_E_ImageDefeat_Error_t;

typedef enum aFailM_E_SoftBtn_Error_e
{
  SoftBtns_NotFunctional  = 0u, /* Soft Buttons should not be selectable by HMI / Display user input */
  SoftBtns_Functional     = 1u  /* Soft Buttons should be available for selection as in normal HMI operation Mode */
} aFailM_E_SoftBtn_Error_t;

typedef enum aFailM_E_DynOvl_Error_e
{
  DynOvl_ForceOFF   = 0u, /* Dynamic Overlays (Trajectories) should never be visible in this Mode */
  DynOvl_NoError    = 1u  /* Dynamic Overlays (Trajectories) are handled as in normal HMI Operation Mode */
} aFailM_E_DynOvl_Error_t;

typedef enum aFailM_E_View_Error_e
{
  View_ForceDEFAULT = 0u, /* Only the Default (Rear-Top) View should be displayed */
  View_NoError      = 1u  /* The View which is selected by HMI as in normal operation Mode should be displayed */
} aFailM_E_View_Error_t;

// R5_MCU1_0 output to HMI(R5_MCU2_0)
typedef struct aFailM_S_HmiM_Errors_s
{
  aFailM_E_ImageDefeat_Error_t  IeFailSafe_e_ImageDefeatError;
  aFailM_E_SoftBtn_Error_t      IeFailSafe_e_SoftBtnError;
  aFailM_E_DynOvl_Error_t       IeFailSafe_e_DynOvlError;
  aFailM_E_View_Error_t         IeFailSafe_e_ViewError;

  /* CAM_NA_Bitfield_uint8_t
   *
   * Bit Encoded Variable with the following structure:
   *
   * Problems with Left Cam  (Bit 1)     00000001 -> 0x01
   * Problems with Right Cam (Bit 2)     00000010 -> 0x02
   * Problems with Front Cam (Bit 3)     00000100 -> 0x04
   * Problems with Rear Cam  (Bit 4)     00001000 -> 0x08
   * */
  uint8_t 						          IeFailSafe_e_CAM_NABitfield;
  boolean 						          IeFailSafe_b_No_TRA_View;
  boolean 						          IeFailSafe_b_TopVideoBlanked;
} aFailM_S_HmiM_Errors_t;

/***************************END of FailSafe Manager*************************************************/

/*********************************************************************************/
/*					ParkSense Area Info Arc Internal Definition				 */
/*********************************************************************************/

// /*********************Internal signal from parksense(R5_MCU2_0) to HMI STM(R5_MCU2_0)**********************************/
typedef enum APA_HMI_BtnSel_e
{
  NONE_PRESSED      = 0,
  PARK_MODE_PRESSED = 1, // park soft button selected or not
  EXIT_MODE_PRESSED = 2, // exit soft button selected or not
  BACK_MODE_PRESSED = 3, // back soft button selected or not
  PARK_SLOT_PRESSED = 4, // any slot soft button selected or not //INfo to be used along with m_selectedslotID that HMI is sending to Detection
  MANEUVER_PRESSED  = 5, // Info to be used along with SelectedManeuverType that HMI is sending to APA
  ABORT_PRESSED     = 6, // Dosen't exist in any videos but added for future to let APA STM know that it has been aborted by user.
  APA_BtnSel_MAX    = 0xFFFFFFFFu

  // HMI will reset this back to NONE_PRESSED as soon as new TeAP_e_HMIPopUp is requested by APA.
} APA_HMI_BtnSel_t;

typedef enum SelectedManeuverType_e
{
  TYPE_NONE         = 0,
  // Right Prep Parkin Types
  RIGHT_FRONT_IN    = 1,
  RIGHT_REAR_IN     = 2,
  // Left Prep Parkin Types
  LEFT_FRONT_IN     = 3,
  LEFT_REAR_IN      = 4,
  // Perpendicular Parkout Manauver Types
  RIGHT_REVERSE_OUT = 5,
  LEFT_REVERSE_OUT  = 6,
  /*Not including Parallel ParkIN types as it dosent have any options for user.*/
  // Parallel Parkout Manauver Types
  RIGHT_FORWARD_OUT = 7,
  LEFT_FORWARD_OUT  = 8,
  SelectedManeuverType_MAX = 0xFFFFFFFFu
} SelectedManeuverType_t;

typedef enum HmiAbort_e
{
  AbortNone 				  = 0,
  AbortSftBtnSelected = 1,
  AbortViaArbitration = 2,
  AbortHmiDisabled    = 3,
  AbortHmiReset       = 4
  // More values and reasons can be added in future
} HmiAbort_t;

typedef struct HMIInfoToAP_s
{
  TeAP_e_HMIPopUp         DisplayedPopUp;
  HmiAbort_t              HmiAbort_Type;
  APA_HMI_BtnSel_t        HMI_ButtonPressed;
  SelectedManeuverType_t  SelectedManeuverType;
  ParkingSlotType_t       SelectedManeuverSlotType;
  SlotSide_t              SelectedManeuverSlotSide;
  ParkingSlotID_t         SelectedSlotId;
  uint32_t                FressnessCounter;
} HMIInfoToAP_t;

typedef enum AP_HMI_Fullscreen_e
{
  NONE_FULLSCREEN                    = 0,
  DOOR_OPEN_FULLSCREEN               = 1,
  LIFEGATE_OPEN_FULLSCREEN           = 2,
  ESC_ACTIVE_FULLSCREEN              = 3,
  SPEED_TOO_HIGH_FULLSCREEN          = 4,
  LO4_ACTIVE_FULLSCREEN              = 5,
  TRAILER_CONNECTED_FULLSCREEN       = 6,
  SERVICE_REQUIRED_FULLSCREEN        = 7,
  FRONT_WIPE_FULLSCREEN              = 8,
  REAR_WIPE_FULLSCREEN               = 9,
  TEMP_NA_FULLSCREEN                 = 10,
  CRUISE_CONTROL_ENGAGED_FULLSCREEN  = 11,
  BUTTON_PRESS_FULLSCREEN            = 12,
  AP_HMI_Fullscreen_Enforcer         = 0xFFFFFFFF
} AP_HMI_Fullscreen_t;

typedef enum AP_HMI_TopBlackBanner_e
{
  TBB_NONE                      = 0,
  TBB_ACTIVE_PARKSENSE_ENGAGED  = 1,
  TBB_WAIT_FOR_STEER            = 2,
  TBB_MOVE_BACKWARD             = 3,
  TBB_SHIFT_TO_DRIVE            = 4,
  TBB_MOVE_FORWARD              = 5,
  TBB_SHIFT_TO_REVERSE          = 6,
  TBB_COMPLETE_HMI              = 7,
  TBB_DOOR_OPEN                 = 8,
  TBB_LIFTGATE_OPEN             = 9,
  TBB_ESC_ACTIVE                = 10,
  TBB_LOW_ACTIVE                = 11,
  TBB_TRAILER_DETECTED          = 12,
  TBB_SERVICE_REQUIRED          = 13,
  TBB_WIPE_FRONT_SENSOR         = 14,
  TBB_WIPE_REAR_SENSOR          = 15,
  TBB_TEMPORARILY_UNAVAILABLE   = 16,
  TBB_TO_CONTINUE_MANUEVER      = 17,
  AP_HMI_TBB_Enforcer           = 0xFFFFFFFF
} AP_HMI_TopBlackBanner_t;

typedef enum AP_HMI_TopRedBanner_e
{
  TRB_NONE                        = 0,
  TRB_REMOVE_HANDS_FEET           = 1,
  TRB_PAUSED_HOLD_BUTTON          = 2,
  TRB_PAUSED_OBJECT_IN_PATH       = 3,
  TRB_STOP                        = 4,
  TRB_PARKSENSE_SPEED_TOO_HIGH    = 5,
  TRB_TAKE_CONTROL                = 6,
  TRB_UNAVAILABLE_SPEED_TOO_HIGH  = 7,
  AP_HMI_TRB_Enforcer             = 0xFFFFFFFF
} AP_HMI_TopRedBanner_t;

typedef enum AP_HMI_BottomBlackBanner_e
{
  BBB_NONE                      = 0,
  BBB_CHECK_ENTIRE_SURROUNDINGS = 1,
  BBB_BUTTON_PRESSED            = 2,
  BBB_CRUISE_CONTROL_ENGAGED    = 3,
  BBB_DOOR_OPEN                 = 4,
  BBB_LIFTGATE_OPEN             = 5,
  BBB_ESC_ACTIVE                = 6,
  BBB_SPEED_TOO_HIGH            = 7,
  BBB_LOW_ACTIVE                = 8,
  BBB_TRAILER_DETECTED          = 9,
  BBB_SERVICE_REQUIRED          = 10,
  BBB_WIPE_FRONT_SENSOR         = 11,
  BBB_WIPE_REAR_SENSOR          = 12,
  BBB_TEMPORARILY_UNAVAILABLE   = 13,
  BBB_STEERING_WHEEL_TOUCHED    = 14,
  BBB_DRIVER_OVERRIDE           = 15,
  BBB_MANUAL_PARK_REQUIRED      = 16,
  AP_HMI_BBB_Enforcer           = 0xFFFFFFFF
} AP_HMI_BottomBlackBanner_t;

typedef struct AP_HMI_ParkSlot_s
{
  ParkingSlotID_t   SlotID;
  ParkingSlotType_t SlotType;
  boolean           SlotSelected;
  /*Indicates top left pixel coordinate of parking slot*/
  uint16_t          SlotPixelCoordinate_X; 
  uint16_t          SlotPixelCoordinate_Y;
} AP_HMI_ParkSlot_t;
/*********************************END of ParkSense Area Info**************************************/
/*************************************************************************************************/

/******************************************************************************************************/
/*						    Configuration Parameters(Proxi manager)									  */
/******************************************************************************************************/

// Vehicle_Line_Configuration
typedef enum aSigConverter_E_VC_VEH_LINE_e
{
  InVEH_LINE_Invalid  = 0u,
  VEH_LINE_343        = 51u,
  VEH_LINE_327FL      = 52u,
  VEH_LINE_226        = 53u,
  VEH_LINE_PF         = 80u,
  VEH_LINE_KLK4       = 81u,
  VEH_LINE_UF         = 82u,
  VEH_LINE_UT         = 83u,
  VEH_LINE_334        = 84u,
  VEH_LINE_520        = 85u,
  VEH_LINE_551M1      = 86u,
  VEH_LINE_338        = 87u,
  VEH_LINE_521        = 88u,
  VEH_LINE_636VM      = 89u,
  VEH_LINE_356        = 90u,
  VEH_LINE_952        = 91u,
  VEH_LINE_341        = 92u,
  VEH_LINE_552MP      = 93u,
  VEH_LINE_949        = 94u,
  VEH_LINE_523        = 95u,
  VEH_LINE_358        = 96u,
  VEH_LINE_359        = 97u,
  VEH_LINE_553M4      = 98u,
  VEH_LINE_556M6      = 99u,
  VEH_LINE_K8         = 100u,
  VEH_LINE_WL         = 101u,
  VEH_LINE_281        = 102u,
  VEH_LINE_363        = 103u,
  VEH_LINE_WS         = 104u,
  VEH_LINE_332        = 105u,
  VEH_LINE_560        = 106u,
  VEH_LINE_DT         = 124u
} aSigConverter_E_VC_VEH_LINE_t;

// Steering Rack Ratio Pinion
typedef enum aSigConverter_E_Steering_RRP_type_e
{
  TYPE_Steer_1 = 0u,
  TYPE_Steer_2,
  TYPE_Steer_3
} aSigConverter_E_Steering_RRP_type_t;

// Wheelbase
typedef enum aSigConverter_E_WheelBase_e
{
  TYPE_WB_1 = 0u,
  TYPE_WB_2,
  TYPE_WB_3
} aSigConverter_E_WheelBase_t;

// Autonomy Level
typedef enum aSigConverter_E_AutonomyLevel_e
{
  LEVEL_AL_1 = 0u,
  LEVEL_AL_2,
  LEVEL_2_PLUS
} aSigConverter_E_AutonomyLevel_t;

// Mirror_Type
typedef enum aSigConverter_E_Mirrors_Type_e
{
  TYPE_MT_1 = 0u,
  TYPE_MT_2,
  TYPE_MT_3,
  TYPE_MT_4,
  Type_MT_5,
  Type_MT_6,
  Type_MT_7,
  Type_MT_8,
  Type_MT_9,
  Type_MT_10
} aSigConverter_E_Mirrors_Type_t;

// TCase_Type
typedef enum aSigConverter_E_Tcase_Type_e
{
  ABSENT = 0u,
  DH8,
  DH9,
  DHZ
} aSigConverter_E_Tcase_Type_t;

// Package
typedef enum aSigConverter_E_Special_Pckg_VP_e
{
  No_Package          = 0u,
  WS_Sport            = 61u,
  WS_Default          = 62u,
  WS_Snow             = 63u,
  WS_Mud              = 64u,
  WS_Track            = 65u,
  WS_Auto             = 76u,
  WS_Rock             = 77u,
  WS_Tow              = 78u,
  WS_Sand             = 79u,
  WS_SRT_TrackHawk    = 165u,
  WS_SRT_Supercharged = 178u
} aSigConverter_E_Special_Pckg_VP_t;

// Country Code
typedef enum aSigConverter_E_Country_Code_e
{
  COUNTRY_CODE_ROW  = 0u,
  COUNTRY_CODE_USA  = 2u,
  COUNTRY_CODE_CND  = 4u,
  COUNTRY_CODE_MEX  = 14u,
  COUNTRY_CODE_BRN  = 18u,
  COUNTRY_CODE_IRQ  = 97u,
  COUNTRY_CODE_JRD  = 104u,
  COUNTRY_CODE_KWT  = 108u,
  COUNTRY_CODE_LBN  = 112u,
  COUNTRY_CODE_OMN  = 149u,
  COUNTRY_CODE_QTR  = 160u,
  COUNTRY_CODE_SA   = 165u,
  COUNTRY_CODE_UAE  = 204u,
  COUNTRY_CODE_YMN  = 215u,
} aSigConverter_E_Country_Code_t;

/********************** From R5_MCU1_0 to SVS***************************************/

typedef struct VehicleCofig_S_ProxiParameter_s
{
  aSigConverter_E_VC_VEH_LINE_t       MePRX_e_VehLineCfg;             // VEHICLE_LINE_CONFIGURATION Proxi data
  aSigConverter_E_Steering_RRP_type_t MePRX_e_SteerRatRackPinionType; // Steering_Ratio_Rack_Pinion_Type Proxi data
  aSigConverter_E_WheelBase_t         MePRX_e_Wheelbase;              // Wheelbase proxi parameter
  aSigConverter_E_AutonomyLevel_t     MePRX_e_AutonomyLvl;            // Autonomy Level Proxi Parameter
  aSigConverter_E_Mirrors_Type_t      MePRX_e_MirrorType;             // Mirrors Type
  aSigConverter_E_Special_Pckg_VP_t   MePRX_e_SpecialPckgVP;          // Special Package VP
  aSigConverter_E_Tcase_Type_t        MePRX_e_TCaseType;              // T Case Type
  aSigConverter_E_Country_Code_t      MePRX_e_CountryCode;            // Country Code
  uint16                              MePRX_e_ModelYear;              // Model Year
  boolean                             MePRX_b_SurroundViewCamera;     // Surround_View_Camera Proxi Data
  boolean                             MePRX_b_CanNode29;              // 0->Absent 1->Present
  boolean                             MePRX_b_FrwFacingCam;           // Forward Facing Camera     0-> Absent 1-> Present
  boolean                             MePRX_b_AuxTrlrCam;             // Auxilliary Trailer Camera    0-> Absent 1-> Present
  boolean                             MePRX_b_CANNode24;              // PAM/CVADAS Module present status  0-> Absent 1-> Present
  boolean                             MePRX_b_CANNode95;              // ITBM/ITCM Module present status   0-> Absent 1-> Present
  boolean                             MePRX_b_ParkSenseCamView;       // Park Sensense Camera View Present Status    0-> Absent 1-> Present
  boolean                             MePRX_b_TRGPresence;            // Trailer Reverse Guidance Feature Present status 0-> Absent 1-> Present
  boolean                             MePRX_b_TRSCPresence;           // Trailer Reverse Steering Control Feature Present status   0-> Absent 1-> Present
  boolean                             MePRX_b_TrlrSurroundPresence;   // Trailer Surround Present Status   0-> Absent 1-> Present
  boolean                             MePRX_b_DigTVfeature;           // Digital Television Feature Enabled Status 0-> Disabled 1-> Enabled
  boolean                             MePRX_b_CanNod27;               // ASCM Configuration
  boolean                             MePRX_b_CanNod14;               // TRSCM Configuration
} VehicleCofig_S_ProxiParameter_t;
/*****************************END OF Proxi Parameter*********************************************************************************************************************/
/************************************************************************************************************************************************************************/

/******************************************************************************************************/
/*						    TRSC Feature specific enum and I/O signals								  */
/******************************************************************************************************/

// MPU1_0(A72) output to HMI(MCU2_0)
typedef enum aSigConverter_E_TrailerCalibrationInfo_e
{
  NOT_CALIBRATED = 0u,
  CALIBRATED,
  Trlr_Cal_SNA
} aSigConverter_E_TrailerCalibrationInfo_t;

// MPU1_0(A72) output to HMI(MCU2_0)
typedef enum aSigConverter_E_TrailerAngleSignInfo_e
{
  Clockwise = 0u,
  AntiClockwise,
  TralrAngSign_SNA
} aSigConverter_E_TrailerAngleSignInfo_t;

// TRSC_MainStateMachine(R5_MCU2_0) to HMI --> Same Core   7
// TRSC_MainStateMachine(R5_MCU2_0) to HMI --> Same Core   7
typedef enum
{
  TRSCStat_Off = 0u, /* Default value */
  TRSCStat_Standby,
  TRSCStat_Calibrating,
  TRSCStat_PreActive,
  TRSCStat_Active,
  TRSCStat_ActiveHoldOvr,
  TRSCStat_Fault,
  TRSCStat_SNA
} aSigConverterTRSC_e_TRSCStat;

typedef enum aSigConverter_E_DisplayView2_e
{
  DisplayView2_ViewOFF = 0u,
  DisplayView2_View1,
  DisplayView2_View2,
  DisplayView2_View3,
  DisplayView2_View4,
  DisplayView2_View5,
  DisplayView2_View6,
  DisplayView2_View7,
  DisplayView2_View8,
  DisplayView2_View9,
  DisplayView2_View10,
  DisplayView2_View11,
  DisplayView2_View12,
  DisplayView2_View13,
  DisplayView2_View14,
  DisplayView2_View15,
  DisplayView2_Enforcer = 0xFFFFFFFF
} aSigConverter_E_DisplayView2_t;

// Input from Trailer_Detection(A72) to HMI(R5_MCU2_0)
typedef struct TrlrDettoSVS_s
{
  aSigConverter_E_TrailerCalibrationInfo_t MeTRSC_e_TrlrCalInfo; // Trailer Calibration info --> MPU1_0(A72) output to HMI(MCU2_0)
  float32 MeTRSC_deg_TADAngle;                                   // Trailer angle info from Trailer_Detection(MPU1_0(A72))
  aSigConverter_E_TrailerAngleSignInfo_t MeTRSC_e_TrlrAngSign;   // Trailer angle and sign info --> MPU1_0(A72) output to HMI(MCU2_0)
} TrlrDettoSVS_t;

// Output to TRSC STM(R5_MCU2_0) from HMI(R5_MCU2_0) --> Same Core
typedef struct SVStoTRSC_s
{
  aSigConverter_E_DisplayView2_t MeSVS_e_DispView2Info;
  bool_t MeSVS_b_MoreCamReq;
} SVStoTRSC_t;

/*********************END OF TRSC Component Interface******************************************/

/**********************************************************************************************/
// SVS To VCAN
/**********************************************************************************************/

/* mcu2_0(SVS SM) output to VCAN */
typedef struct SvsToVCAN_s
{
  boolean IeSVS_b_SPMScrnReq;                      /* CVPAM_FD_Info--> 1 Bit */
  boolean IeSVS_b_ImgDefeatReqSts;                  /* CVPAM_FD_Info--> 1 Bit */
  boolean IeSVS_b_MoreCamsReqSts;                   /* CVPAM_FD_Info--> 1 Bit */
  boolean IeSVS_b_AUXCamReqSts;                     /* CVPAM_FD_Info--> 1 Bit */
  aSigConverter_E_DisplayView2_t IeSVS_e_DispView2; /* CVPAM_FD_Info--> 1 Bit */
} SvsToVCAN_t;

/***********************END od SVS to VCAN Signal*******************************************/
/*******************************************************************************************/

/**********************************************************************************************/
// THA Component
/**********************************************************************************************/

typedef enum aSigConverter_E_THAScreenRequest_e
{
  THA_Default = 0u,
  THA_Enable,
  THA_TCS_Msg1,
  THA_TCS_Msg2,
  THA_TCS_Msg3,
  THA_TCS_Msg4,
  THA_TCS_Msg5,
  THA_SM_Msg1,
  THA_SM_Msg2,
  THA_CM_Msg1,
  THA_CM_Msg2,
  THA_CM_Msg3,
  THA_CM_Msg4,
  THA_CM_Msg5,
  THA_CM_Msg6,
  THA_CM_Msg7,
  THA_CM_Msg8,
  THA_CM_Msg9,
  THA_CM_Msg10,
  THA_EOM_Msg1,
  THA_EOM_Msg2,
  THA_EOM_Msg3,
  THA_EOM_Msg4,
  THA_ERR_Msg1,
  THA_ERR_Msg2,
  THA_Size_Enforcer = 0xFFFFFFFF,
} aSigConverter_E_THAScreenRequest_t;

typedef struct aSigConverter_Point2i_s
{
  sint32_t x;
  sint32_t y;
} aSigConverter_Point2i_t;

// HMI(MCU2_0) to THA(MCU2_1)
typedef struct SvsToTHA_s
{
  aSigConverter_E_THAScreenRequest_t  MeSVS_e_THAScrResp;             // THA State response
  boolean                             MeSVS_b_THASftBtnPrsdStsToTHA;  // Internal signal to THA confirmation regarding THA button pressed or not
  boolean                             MeSVS_b_IsConfirmBtnPrsd;       // Internal signal if THA button is pressed
  boolean                             MeSVS_b_ImgDefeatReqSts;        // Image defeat button pressed while THA is active
  boolean                             MeSVS_b_ViewZoomSts;            // View is in normal view or Zoom view --> 0-> Normal View 1-> Zoom view
  boolean                             MeSVS_b_THAMnvrStartBtnPrsd;    // Whether Start button pressed from user for backup manuever start
  boolean                             MeSVS_b_THAScrTchSts;           // Whether Coupler is selected first time by user or not
  boolean                             MeSVS_b_THAAbortReq;            // Is THA overlay active on screen or not
} SvsToTHA_t;

// HMI(MCU2_0) to THA_Detection(A72)
typedef struct SvsToTHADet_s
{
  uint16 MeSVS_px_THACplrPosX; // CouplerPosX position when user selects copler over screen
  uint16 MeSVS_px_THACplrPosY; // CoplerPosY position when user selects copler over screen
} SvsToTHADet_t;

/***************************End of THA Component***************************************************/

/*****************************************************************************************************/
/*							Overlay Bits to A72 Core						                         */
/*****************************************************************************************************/

typedef struct OverlayBits_s
{
	/*Basic Views Button*/						
  uint8_t	TopRearButtonSelect_b	            :	1;	/*	Bit	0	*/
  uint8_t	TopRearButtonNoSelect_b	          :	1;	/*	Bit	1	*/
  uint8_t	RearCrossButtonSelect_b	          :	1;	/*	Bit	2	*/
  uint8_t	RearCrossButtonNoSelect_b	        :	1;	/*	Bit	3	*/
  uint8_t	FrontCrossButtonSelect_b	        :	1;	/*	Bit	4	*/
  uint8_t	FrontCrossButtonNoSelect_b	      :	1;	/*	Bit	5	*/
  uint8_t	TopFrontButtonNoSelect_b	        :	1;	/*	Bit	6	*/
  uint8_t	TopFrontButtonSelect_b	          :	1;	/*	Bit	7	*/
  uint8_t	BackupRearCamButtonNoSelect_b	    :	1;	/*	Bit	8	*/
  uint8_t	BackupRearCamButtonSelect_b	      :	1;	/*	Bit	9	*/
  uint8_t	FrontFaceCamButtonNoSelect_b	    :	1;	/*	Bit	10	*/
  uint8_t	FrontFaceCamButtonSelect_b	      :	1;	/*	Bit	11	*/
  uint8_t	AuxCamButton1NoSelect_b	          :	1;	/*	Bit	12	*/
  uint8_t	AuxCamButton1Select_b	            :	1;	/*	Bit	13	*/
  uint8_t	AuxCamButton2NoSelect_b	          :	1;	/*	Bit	14	*/
  uint8_t	AuxCamButton2Select_b	            :	1;	/*	Bit	15	*/
  uint8_t	MoreCamsButton1NoSelect_b	        :	1;	/*	Bit	16	*/
  uint8_t	MoreCamsButton1Select_b	          :	1;	/*	Bit	17	*/
  uint8_t	MoreCamsButton2NoSelect_b	        :	1;	/*	Bit	18	*/
  uint8_t	MoreCamsButton2Select_b	          :	1;	/*	Bit	19	*/
  uint8_t	XIcon_b	                          :	1;	/*	Bit	20	*/
	/*Basic Views Text*/						  
  uint8_t	Frameset1AndTopRearText_b	        :	1;	/*	Bit	21	*/
  uint8_t	Frameset1AndTopFrontText_b	      :	1;	/*	Bit	22	*/
  uint8_t	Frameset2AndRearCrossText_b	      :	1;	/*	Bit	23	*/
  uint8_t	Frameset2AndFrontCrossText_b	    :	1;	/*	Bit	24	*/
	/*FullScreen Views Button*/						  
  uint8_t	ZoomPlus_Selectable_b	            :	1;	/*	Bit	25	*/
  uint8_t	ZoomPlus_Not_Selectable_b	        :	1;	/*	Bit	26	*/
  uint8_t	ZoomMinus_Selectable_b	          :	1;	/*	Bit	27	*/
  uint8_t	ZoomMinus_Not_Selectable_b	      :	1;	/*	Bit	28	*/
  uint8_t	MoreCamsIconFullScreenNoSelect_b  :	1;	/*	Bit	29	*/
  uint8_t	Auto_NoSelect_b                   :	1;	/*	Bit	30	*/
  uint8_t	Auto_Select_b                     :	1;	/*	Bit	31	*/
	/*GuildLines*/						              
  uint8_t	TopViewFrontDynamics_b	          :	1;	/*	Bit	32	*/
  uint8_t	FrontViewDynamics_b	              :	1;	/*	Bit	33	*/
  uint8_t	TopViewRearDynamics_b	            :	1;	/*	Bit	34	*/
  uint8_t	RearViewDynamics_b	              :	1;	/*	Bit	35	*/
  uint8_t	FrontTireTracks_b	                :	1;	/*	Bit	36	*/
	/*AJAR CLOSED*/						              
  uint8_t	BackDoorClose_Icon_b	            :	1;	/*	Bit	37	*/
  uint8_t	RightDoorRearClose_Icon_b	        :	1;	/*	Bit	38	*/
  uint8_t	RightDoorFrontClose_Icon_b	      :	1;	/*	Bit	39	*/
  uint8_t	LeftDoorRearClose_Icon_b	        :	1;	/*	Bit	40	*/
  uint8_t	LeftDoorFrontClose_Icon_b	        :	1;	/*	Bit	41	*/
	/*AJAR OPEN*/						                
  uint8_t	BackDoorOpen_Icon_b	              :	1;	/*	Bit	42	*/
  uint8_t	RightDoorRearOpen_Icon_b	        :	1;	/*	Bit	43	*/
  uint8_t	RightDoorFrontOpen_Icon_b	        :	1;	/*	Bit	44	*/
  uint8_t	LeftDoorRearOpen_Icon_b	          :	1;	/*	Bit	45	*/
  uint8_t	LeftDoorFrontOpen_Icon_b	        :	1;	/*	Bit	46	*/
  /*FAILSAFE*/						          
  uint8_t	TopViewBlack_b	                  :	1;	/*	Bit	47	*/
  uint8_t	RightCam_NA_b	                    :	1;	/*	Bit	48	*/
  uint8_t	BackCam_NA_b	                    :	1;	/*	Bit	49	*/
  uint8_t	LeftCam_NA_b	                    :	1;	/*	Bit	50	*/
  uint8_t	FrontCam_NA_b	                    :	1;	/*	Bit	51	*/
  uint8_t DefaultEngLang_b                  : 1;  /*  Bit 52 */
  uint8_t EnableStaticGuidelines_b          : 1;  /*  Bit 53 */
  uint8_t DoorSigFault_b                    : 1;  /*  Bit 54 */
  uint8_t	Reserved_15_b	                    :	1;	/*	Bit	55	*/
  /*TRSC HMI*/						                
  uint8_t	TRSC_TrailerRed	                  :	1;	/*	Bit	56	*/
  uint8_t	TRSC_Enable	                      :	1;	/*	Bit	57	*/
	/*THA HMI*/						                  
  uint8_t THA_Updated_b                     : 1;
  uint8_t	THA_ProgressBar	                  :	1;	/*	Bit	58	*/
  uint8_t	THA_StartButton	                  :	1;	/*	Bit	59	*/
  uint8_t	THA_ConfirmButton	                :	1;	/*	Bit	60	*/
  uint8_t	THA_ButtonSelectable	            :	1;	/*	Bit	61	*/
  uint8_t	THA_ButtonGrey	                  :	1;	/*	Bit	62	*/
  uint8_t	THA_CouplerBulletIcon	            :	1;	/*	Bit	63	*/
  uint8_t	THA_TriangleOverlay	              :	1;	/*	Bit	64	*/
  /*ParkAssist HMI*/					      
  uint8_t	PDC_RearLeft_Red_b	              :	1;	/*	Bit	65	*/
  uint8_t	PDC_RearLeft_Yellow_b	            :	1;	/*	Bit	66	*/
  uint8_t	PDC_RearRight_Red_b	              :	1;	/*	Bit	67	*/
  uint8_t	PDC_RearRight_Yellow_b	          :	1;	/*	Bit	68	*/
  uint8_t	PDC_RearCenter_Red_b	            :	1;	/*	Bit	69	*/
  uint8_t	PDC_RearCenter_Yellow_b	          :	1;	/*	Bit	70	*/
  uint8_t	PDC_FrontLeft_Red_b	              :	1;	/*	Bit	71	*/
  uint8_t	PDC_FrontLeft_Yellow_b	          :	1;	/*	Bit	72	*/
  uint8_t	PDC_FrontRight_Red_b	            :	1;	/*	Bit	73	*/
  uint8_t	PDC_FrontRight_Yellow_b	          :	1;	/*	Bit	74	*/
  uint8_t	PDC_FrontCenter_Red_b	            :	1;	/*	Bit	75	*/
  uint8_t	PDC_FrontCenter_Yellow_b	        :	1;	/*	Bit	76	*/
	/*AutoPark HMI*/						            
  uint8_t	AP_BackBtn	                      :	1;	/*	Bit	77	*/
  uint8_t	AP_ParkBtn_Selected	              :	1;	/*	Bit	78	*/
  uint8_t	AP_ParkBtn_Not_Selected	          :	1;	/*	Bit	79	*/
  uint8_t	AP_ExitBtn_Selected	              :	1;	/*	Bit	80	*/
  uint8_t	AP_ExitBtn_Not_Selected	          :	1;	/*	Bit	81	*/
  uint8_t	AP_Disclaimer_Core	              :	1;	/*	Bit	82	*/
  uint8_t	AP_BG_Main	                      :	1;	/*	Bit	83	*/
  uint8_t	AP_Para_Exit_Core	                :	1;	/*	Bit	84	*/
  uint8_t	AP_Forward_LeftBtn_Selected	      :	1;	/*	Bit	85	*/
  uint8_t	AP_Forward_LeftBtn_Not_Selected	  :	1;	/*	Bit	86	*/
  uint8_t	AP_Forward_RightBtn_Selected	    :	1;	/*	Bit	87	*/
  uint8_t	AP_Forward_RightBtn_Not_Selected	:	1;	/*	Bit	88	*/
  uint8_t	AP_Perp_Right_Core	              :	1;	/*	Bit	89	*/
  uint8_t	AP_Perp_Left_Core	                :	1;	/*	Bit	90	*/
  uint8_t	AP_RearInBtn_Not_Selected	        :	1;	/*	Bit	91	*/
  uint8_t	AP_RearInBtn_Selected	            :	1;	/*	Bit	92	*/
  uint8_t	AP_FrontInBtn_Not_Selected	      :	1;	/*	Bit	93	*/
  uint8_t	AP_FrontInBtn_Selected	          :	1;	/*	Bit	94	*/
  uint8_t	AP_RearInBtn_Not_Avail	          :	1;	/*	Bit	95	*/
  uint8_t	AP_FrontInBtn_Not_Avail	          :	1;	/*	Bit	96	*/
  uint8_t	AP_Parkout_Done	                  :	1;	/*	Bit	97	*/
  uint8_t	AP_ParkIn_Done	                  :	1;	/*	Bit	98	*/
  uint8_t	AP_Scanning_Core	                :	1;	/*	Bit	99	*/
  uint8_t	AP_Grey_Banner1	                  :	1;	/*	Bit	100	*/
  uint8_t	AP_Grey_Banner2	                  :	1;	/*	Bit	101	*/
  uint8_t	AP_Scan_Select_Space_Text	        :	1;	/*	Bit	102	*/
  uint8_t	AP_Scan_Space_Found_Text	        :	1;	/*	Bit	103	*/
  uint8_t	AP_Scan_STOP_Text	                :	1;	/*	Bit	104	*/
  uint8_t	AP_Scan_Searching_Text	          :	1;	/*	Bit	105	*/
  uint8_t	AP_Scan_Keep_Moving_Forward_Text	:	1;	/*	Bit	106	*/
  uint8_t	AP_Scan_Reduce_Speed_Text	        :	1;	/*	Bit	107	*/
  uint8_t	AP_FullscreenText_Updated	        :	1;	/*	Bit	108	*/
  uint8_t	AP_ParksenseUnavailable	          :	1;	/*	Bit	109	*/
  uint8_t	AP_TopBlackBannerUpdated	        :	1;	/*	Bit	110	*/
  uint8_t	AP_BottomBlackBannerUpdated	      :	1;	/*	Bit	111	*/
  uint8_t	AP_RedBannerUpdated               :	1;	/*	Bit	112	*/
  uint8_t	AP_ParkSlots_Updated	            :	1;	/*	Bit	113	*/
  /*Calibration*/						
  uint8_t	SrvPrgBar999Per_b	                :	1;	/*	Bit	114	*/
  uint8_t	SrvPrgBar100Per_b	                :	1;	/*	Bit	115	*/
  uint8_t	SrvPrgBar75Per_b	                :	1;	/*	Bit	116	*/
  uint8_t	SrvPrgBar50Per_b	                :	1;	/*	Bit	117	*/
  uint8_t	SrvPrgBar25Per_b	                :	1;	/*	Bit	118	*/
  uint8_t	SrvPrgBar0Per_b	                  :	1;	/*	Bit	119	*/
  uint8_t	SrvCamIndRiNone_b	                :	1;	/*	Bit	120	*/
  uint8_t	SrvCamIndRiPend_b	                :	1;	/*	Bit	121	*/
  uint8_t	SrvCamIndRiNok_b	                :	1;	/*	Bit	122	*/
  uint8_t	SrvCamIndRiOk_b	                  :	1;	/*	Bit	123	*/
  uint8_t	SrvCamIndBaNone_b	                :	1;	/*	Bit	124	*/
  uint8_t	SrvCamIndBaPend_b	                :	1;	/*	Bit	125	*/
  uint8_t	SrvCamIndBaNok_b	                :	1;	/*	Bit	126	*/
  uint8_t	SrvCamIndBaOk_b	                  :	1;	/*	Bit	127	*/
  uint8_t	SrvCamIndLeNone_b	                :	1;	/*	Bit	128	*/
  uint8_t	SrvCamIndLePend_b	                :	1;	/*	Bit	129	*/
  uint8_t	SrvCamIndLeNok_b	                :	1;	/*	Bit	130	*/
  uint8_t	SrvCamIndLeOk_b	                  :	1;	/*	Bit	131	*/
  uint8_t	SrvCamIndFrNone_b	                :	1;	/*	Bit	132	*/
  uint8_t	SrvCamIndFrPend_b	                :	1;	/*	Bit	133	*/
  uint8_t	SrvCamIndFrNok_b	                :	1;	/*	Bit	134	*/
  uint8_t	SrvCamIndFrOk_b	                  :	1;	/*	Bit	135	*/
  uint8_t	SrvChkIndCondNok_b	              :	1;	/*	Bit	136	*/
  uint8_t	SrvChkIndNok_b	                  :	1;	/*	Bit	137	*/
  uint8_t	SrvChkIndOk_b	                    :	1;	/*	Bit	138	*/
  uint8_t	SrvChkIndRun_b	                  :	1;	/*	Bit	139	*/
  uint8_t	SrvSpOmIndNok_b	                  :	1;	/*	Bit	140	*/
  uint8_t	SrvSpOmIndOk_b	                  :	1;	/*	Bit	141	*/
  uint8_t	SrvStAngIndNok_b	                :	1;	/*	Bit	142	*/
  uint8_t	SrvStAngIndOk_b	                  :	1;	/*	Bit	143	*/
  uint8_t	SrvLayout_b	                      :	1;	/*	Bit	144	*/
  /*Reserved*/
  uint8_t Reserved_01_b                     : 1;  /*  Bit 145 */  
  uint8_t Reserved_02_b                     : 1;  /*  Bit 146 */
  uint8_t Reserved_03_b                     : 1;  /*  Bit 147 */
  uint8_t Reserved_04_b                     : 1;  /*  Bit 148 */
  uint8_t Reserved_05_b                     : 1;  /*  Bit 149 */
  uint8_t Reserved_06_b                     : 1;  /*  Bit 151 */
  uint8_t Reserved_07_b                     : 1;  /*  Bit 152 */
  uint8_t Reserved_08_b                     : 1;  /*  Bit 153 */
  uint8_t Reserved_09_b                     : 1;  /*  Bit 154 */
  uint8_t Reserved_10_b                     : 1;  /*  Bit 155 */
  uint8_t Reserved_11_b                     : 1;  /*  Bit 156 */
  uint8_t Reserved_12_b                     : 1;  /*  Bit 157 */
  uint8_t Reserved_13_b                     : 1;  /*  Bit 158 */
  uint8_t Reserved_14_b                     : 1;  /*  Bit 159 */
  uint8_t OneCam_ZoomPlus_Selectable_b      : 1;  /*  Bit 160 */
  uint8_t OneCam_ZoomPlus_Not_Selectable_b  : 1;  /*  Bit 161 */
  uint8_t OneCam_ZoomMinus_Selectable_b     : 1;  /*  Bit 162 */
  uint8_t OneCam_ZoomMinus_Not_Selectable_b : 1;  /*  Bit 163 */
  uint8_t OneCam_AuxCamButtonSelect_b       : 1;  /*  Bit 164 */
  uint8_t OneCam_AuxCamButtonNoSelect_b     : 1;  /*  Bit 165 */ 
} OverlayBits_t;

// HMI to A72 core
typedef struct ScreenRequest_s
{
  /*General 1*/
  OverlayBits_t                       MbSVS_bf_OverlayBitsReq;          // Overlay bits
  
  /*AP*/
  AP_HMI_ParkSlot_t                   AP_HMI_ParkSlot[6];
  ParkingSlotID_t                     AP_HMI_SelectedSlot;
  AP_HMI_Fullscreen_t                 AP_HMI_Fullscreen;
  AP_HMI_TopBlackBanner_t             AP_HMI_TopBlackBanner;
  AP_HMI_TopRedBanner_t               AP_HMI_TopRedBanner;
  AP_HMI_BottomBlackBanner_t          AP_HMI_BottomBlackBanner;
  
  /*THA 1*/
  aSigConverter_E_THAScreenRequest_t  MeSVS_e_THAScreenRequesttoA72;
  
  /*TRSC*/
  int8_t                               MeSVS_DesiredTrailerAngle;  // JackKnife WhiteDotted Line
  int8_t                               MeSVS_ActualTrailerAngle;   // Trailer angle
  int8_t                               MeSVS_Orage_Arc_StartAngle;
  int8_t                               MeSVS_Red_Arc_StartAngle;
  
  /*THA 2*/
  uint16                              MeSVS_pct_ProgressBar;
  uint16                              MeSVS_px_CplrPosX;                // CouplerPosX position when user selects copler over screen
  uint16                              MeSVS_px_CplrPosY;                // CouplerPosY position when user selects copler over screen
  uint16                              MeSVS_px_ScrnTchX;                // X coordinate when user touches screen to select coupler
  uint16                              MeSVS_px_ScrnTchY;                // Y coordinate when user touches screen to select coupler 
  
  /*General 2*/
  int16                               MeSVS_deg_StrWhlAng;              // Steering Wheel Angle
  uint16                              MeSVS_e_CRCRReq;                  // CRC
  uint8_t                             MeSVS_e_ViewEngReqCode;           // View Request
  uint8_t                             ZoomFactor_u8;
  boolean                             MeSVS_b_ZoomPressedReq;           /* Zoom Response	*/
} ScreenRequest_t;

// HMI to A72 Core (THA Related Signals)

// A72(ViewGen) core output to mcu2_0(SVS SM)
typedef struct ScreenResponse_s
{
  /*General 1*/
  OverlayBits_t                       MbSVS_bf_OverlayBitsRes;          // Overlay bits
  
  /*FOR APA HMI*/
  AP_HMI_ParkSlot_t                   AP_HMI_ParkSlot[6];
  ParkingSlotID_t                     AP_HMI_SelectedSlot;
  AP_HMI_Fullscreen_t                 AP_HMI_Fullscreen;
  AP_HMI_TopBlackBanner_t             AP_HMI_TopBlackBanner;
  AP_HMI_TopRedBanner_t               AP_HMI_TopRedBanner;
  AP_HMI_BottomBlackBanner_t          AP_HMI_BottomBlackBanner;
  /*Indicates factor of multiplication k i.e 1pixel = k x 1cm*/
  float32                             Pixel_X_to_RealWord_X_cm; 
  float32                             Pixel_Y_to_RealWord_Y_cm;  
  /*THA 1*/
  aSigConverter_E_THAScreenRequest_t  MeSVS_e_THAScreenResponse;
  
  /*TRSC*/
  int8_t                               MeSVS_DesiredTrailerAngle;  // JackKnife WhiteDotted Line
  int8_t                               MeSVS_ActualTrailerAngle;   // Trailer angle
  int8_t                               MeSVS_Orage_Arc_StartAngle;
  int8_t                               MeSVS_Red_Arc_StartAngle;
  
  /*THA 2*/
  uint16                              MeSVS_pct_ProgressBar;
  uint16                              MeSVS_px_CplrPosX;                // CouplerPosX position when user selects copler over screen
  uint16                              MeSVS_px_CplrPosY;                // CouplerPosY position when user selects copler over screen
  uint16                              MeSVS_px_ScrnTchX;                // X coordinate when user touches screen to select coupler
  uint16                              MeSVS_px_ScrnTchY;                // Y coordinate when user touches screen to select coupler 
  
  /*General 2*/
  int16                               MeSVS_deg_StrWhlAng;              // Steering Wheel Angle
  uint16                              MeSVS_e_CRCRReq;                  // CRC
  uint8_t                             MeSVS_e_ViewEngResCode;           // View Request
  uint8_t                             ZoomFactor_u8;
  uint8_t                             RenderedRadioDispType;            /*Current RadioType being used by SV Engine*/
  uint8_t                             MeSVS_b_ZoomPressedRes;
  boolean                             THAViewZoomResponse;              /* Zoom Response	*/
} ScreenResponse_t;

typedef struct THARelated_ScreenReq_s
{
  uint16  MeSVS_px_ScrnTchX;              // X coordinate when user touches screen to select coupler
  uint16  MeSVS_px_ScrnTchY;              // Y coordinate when user touches screen to select coupler
  uint16  MeSVS_pct_ProgressBar;          // Progress Bar percentage value
  uint8   MeSVS_e_THAScreenRequesttoA72;  // THA msg ID
  boolean MeSVS_b_THASftBtnPressedSts;    // Not used currently
} THARelated_ScreenReq_t;

/* From MCU2_0 to A core*/
typedef struct TRSCDebug_ScrReq_s
{
  float32 MeSVS_m_HitchLength;
  float32 MeSVS_deg_TADAngle;
  float32 MeSVS_e_TADState;
  float32 IeSVS_pct_TrlrTrackConf;
  float32 IeSVS_pct_TrlrRecogConf;
  float32 MeSVS_deg_DetJackknifeThrAngle;
  float32 MeSVS_m_DetTrailerBeamLen;
  float32 MeSVS_deg_wheelAngle;
  float32 MeSVS_deg_DetJackKnifeAngle;
  float32 MeSVS_kmph_vehicleSpeed;
  uint16  MeSVS_HitpointStartX;
  uint16  MeSVS_HitpointStartY;
  uint16  MeSVS_EndAnglePointX;
  uint16  MeSVS_EndAnglePointY;
  uint16  MeSVS_EndKniematicsPoint1X;
  uint16  MeSVS_EndKniematicsPoint1Y;
  uint16  MeSVS_EndKniematicsPoint2X;
  uint16  MeSVS_EndKniematicsPoint2Y;
  uint8   MeSVS_e_TurnAroundSubState;
  uint8   MeSVS_e_TADCalibrationSubstate;
  uint8   MeSVS_e_TrailerID;
  boolean MeSVS_b_AngleONGrnLine;
  boolean MeSVS_b_KinematicONPurLine;
} TRSCDebug_ScrReq_t;

/*A core to MCU2_0 core*/
typedef struct TrscDebug_ScrRes_s
{
  float32 MeSVS_m_HitchLengthRes;
  float32 MeSVS_deg_TADAngleRes;
  float32 MeSVS_e_TADStateRes;
  float32 IeSVS_pct_TrlrTrackConfRes;
  float32 IeSVS_pct_TrlrRecogConfRes;
  float32 MeSVS_deg_DetJackknifeThrAngleRes;
  float32 MeSVS_m_DetTrailerBeamLenRes;
  float32 MeSVS_deg_DetJackKnifeAngleRes;
  float32 MeSVS_kmph_vehicleSpeedRes;
  float32 MeSVS_deg_wheelAngle;
  uint16  MeSVS_HitpointStartXRes;
  uint16  MeSVS_HitpointStartYRes;
  uint16  MeSVS_EndAnglePointXRes;
  uint16  MeSVS_EndAnglePointYRes;
  uint16  MeSVS_EndKniematicsPoint1XRes;
  uint16  MeSVS_EndKniematicsPoint1YRes;
  uint16  MeSVS_EndKniematicsPoint2XRes;
  uint16  MeSVS_EndKniematicsPoint2YRes;
  uint8   MeSVS_e_TurnAroundSubStateRes;
  uint8   MeSVS_e_TADCalibrationSubstateRes;
  uint8   MeSVS_e_TrailerIDRes;
  boolean MeSVS_b_AngleONGrnLineRes;
  boolean MeSVS_b_KinematicONPurLineRes;
} TrscDebug_ScrRes_t;

/******************************************STRUCTS USED FOR DEBUG DBC************************************/
/******************************************STRUCTS USED FOR DEBUG DBC************************************/
/******************************************STRUCTS USED FOR DEBUG DBC************************************/
/******************************************STRUCTS USED FOR DEBUG DBC************************************/
typedef struct Debug_HMI_ProxiConfig_s
{
  uint8_t MePRX_e_VariantID;
  uint8_t MePRX_e_VehLineCfg;
  uint8_t MePRX_e_Wheelbase;
  uint8_t MePRX_e_SteerRatRackPinionType;
  uint8_t MePRX_e_RadDispType;
  uint8_t MePRX_e_MirrorType;
  uint8_t MePRX_e_PAMTunSet;
  uint8_t MePRX_e_AutonomyLvl;
  bool    MePRX_b_SurroundViewCamera;
  bool    MePRX_b_FrwFacingCam;
  bool    MePRX_b_AuxTrlrCam;
  bool    MePRX_b_CANNode95;
  bool    MePRX_b_CanNode27;
  bool    MePRX_b_TRGPresence;
  bool    MePRX_b_TRSCPresence;
} Debug_HMI_ProxiConfig_t;

typedef struct Debug_HMI_Trailer_Views_Data_s
{
  float32_t TadAngle;
  float32_t MaxTadAngle;
  float32_t KnobAngle;
  float32_t JackKnifeAngle;
  uint32_t  TrscStatus;
  uint32_t  TrailerAngleSign;
  uint32_t  TrailerCalibrationStatus;
  uint32_t  Curr_TRG_Stat;
  uint32_t  Prev_TRG_Stat;
  uint8_t   M_CPLR_POS_X_u;
  uint8_t   M_CPLR_POS_Y_u;
  uint8_t   M_Cplr_Htch_Distance;
  uint8_t   M_Progress_Bar_Distance;
  uint8_t   M_Maneuver_Initial_Run;
  uint8_t   M_Progress_Bar_Percentage;
  uint8_t   M_Current_THA_State_On_Zync;
  uint8_t   M_Current_THA_State_On_Screen;
  uint8_t   M_Requested_THA_State;
  uint8_t   TrailerWheelBase;
  uint8_t   TrailerConnectionStatus;
  uint8_t   ItbmTrailerStatus;
  bool      M_VIEW_ZOOM_STS_b;
  bool      M_VIEW_SCRN_TCH_STS_b;
  bool      M_CONFIRM_BTN_PRESSED_b;
  bool      M_START_BTN_PRESSED_b;
  bool      M_THA_SFT_BTN_PRESSED_b;
  bool      aHmiM_STM_v_TRGLEFT_BTN_PRESSED_b;
  bool      aHmiM_STM_v_TRGRIGHT_BTN_PRESSED_b;
  bool      aHmiM_STM_v_TRGAUTO_BTN_PRESSED_b;
} Debug_HMI_Trailer_Views_Data_t;

typedef struct Debug_HMI_Input_Data_s
{
  float32_t steeringWheelAngle_f32;
  float32_t vehicleSpeed_f32;
  uint32_t  lrwsST_e;
  uint32_t  revGear_e;
  uint32_t  trscStat_e;
  uint32_t  NetCfg_TRSCM_e;
  uint32_t  ignitionStatus_e;
  uint32_t  transEquipped_e;
  uint32_t  prndStatus_e;
  uint32_t  CameraDisplaySts2_e;
  uint32_t  tgwDispStatus_e;
  uint32_t  ImageDefeat_Error_e;
  uint32_t  SoftBtn_Error_e;
  uint32_t  DynOvl_Error_e;
  uint32_t  View_Error_e;
  uint32_t  tchScrnStatus_e;
  uint16_t  tchScrnCoordX_s;
  uint16_t  tchScrnCoordY_s;
  uint8_t   CAM_NA_Bitfield_u8;
  uint8_t   vehicleLine_e;
  uint8_t   LanguageSelection_u8;
  bool      TopVideoBlanked_b;
  bool      SVC_Dynamic_Gridlines_Feature_b;
  bool      SVC_Static_Gridlines_Feature_b;
  bool      SVC_FFCV_Gridlines_Feature_b;
  bool      SVC_Delay_Feature_b;
  bool      GW_C_I6_timeout_b;
} Debug_HMI_Input_Data_t;

typedef struct Debug_HMI_Internal_Data_s
{
  uint32_t  M_BURV_Memory_e;
  uint32_t  M_FFClatch_e;
  uint32_t  Curr_SystemState_e;
  uint32_t  Prev_SystemState_e;
  uint32_t  Curr_RequestedViewByHmiM_e;
  uint32_t  Prev_RequestedViewByHmiM_e;
  uint32_t  Curr_DisplayedViewByAcore_e;
  uint32_t  Prev_DisplayedViewByAcore_e;
  uint32_t  LastViewBeforeTestPattern_e;
  uint8_t   ZoomFactor_u8;
  bool      IgnoreVehicleOffSpeed;
  bool      X_BTN_PRESSED_b;
  bool      MAGNIFIER_BTN_PRESSED_b;
  bool      REAR_TOP_BTN_PRESSED_b;
  bool      FRONT_TOP_BTN_PRESSED_b;
  bool      REAR_CROSS_BTN_PRESSED_b;
  bool      FRONT_CROSS_BTN_PRESSED_b;
  bool      FFCV_BTN_PRESSED_b;
  bool      RVCONLY_BTN_PRESSED_b;
  bool      VC_OFFROAD_PRSNT_AUXCAM_BTN_PRESSED_b;
  bool      VC_OFFROAD_ABSNT_AUXCAM_BTN_PRESSED_b;
  bool      VC_OFFROAD_PRSNT_MC_BTN_PRESSED_b;
  bool      VC_OFFROAD_ABSNT_MC_BTN_PRESSED_b;
} Debug_HMI_Internal_Data_t;

/*Signals to go from MCU2_0 to MCU1_0*/
// OverlayBits_t 		Debug_HMI_Curr_Requested_Overlays;
// OverlayBits_t			Debug_HMI_Curr_Displayed_Overlays;

// Debug_HMI_ProxiConfig_t 		Debug_HMI_Curr_Requested_ProxiConfig;
// Debug_HMI_ProxiConfig_t 		Debug_HMI_Curr_Displayed_ProxiConfig;

// Debug_HMI_Trailer_Views_Data_t 	Debug_HMI_Trailer_Views_Data;
// Debug_HMI_Input_Data_t         	Debug_HMI_Input_Data;
// Debug_HMI_Internal_Data_t      	Debug_HMI_Internal_Data;
/*END of Signals to go from MCU2_0 to MCU1_0*/

typedef struct HmiSM_Tuning_s
{
  float32 HMI_XCP_VIDEO_ON_SPEED;       /* Video Output shall be ON when Vehicle speed is below */
  float32 HMI_XCP_VIDEO_OFF_SPEED;      /* Video Output can be OFF when Vehicle speed exceeds */
  float32 HMI_XCP_PDC_THRESHOLD_SPEED;  /* PDCs should be disabled when Vehicle speed exceeds */
  float32 HMI_XCP_RVC_VIEWRESET_SPEED;  /* View Reset Speed for RVC-Only Zoomed View*/
  float32 HMI_XCP_TRG_PANGUARD_SPEED;   /* TRG AutoPanning should be disabled when Vehicle Speed exceeds*/

  float32 TRG_LEFT_TAD_MAX;           
  float32 TRG_LEFT_TAD_MIN;                 

  float32 TRG_75L25R_TAD_MAX;                      
  float32 TRG_75L25R_TAD_MIN;                      

  float32 TRG_50L50R_TAD_MAX;                        
  float32 TRG_50L50R_TAD_MIN;                         

  float32 TRG_25L75R_TAD_MAX;                     
  float32 TRG_25L75R_TAD_MIN;                       

  float32 TRG_RIGHT_TAD_MAX;                               
  float32 TRG_RIGHT_TAD_MIN;  

  uint8 	HMI_XCP_LOCKOUTWAITCYCLES;    /* 5 cycles wait time */
  uint8 	HMI_XCP_SCREENREQ_TIMEOUT;    /* 500 msec timeout to get correct screen response */
  uint8 	HMI_XCP_K_TDELAYPRND;         /* Time of delayAfter entering new gear position */                     
}HmiSM_Tuning_t;

typedef struct HmiSM_Generic_s
{  /*For Future USE to avoid repetation of activity*/

  float32 HmiGen_Reserve_00;
  float32 HmiGen_Reserve_01;
  float32 HmiGen_Reserve_02;
  float32 HmiGen_Reserve_03;

  float32 HmiGen_Reserve_10;
  float32 HmiGen_Reserve_11;
  float32 HmiGen_Reserve_12;
  float32 HmiGen_Reserve_13;

  float32 HmiGen_Reserve_20;
  float32 HmiGen_Reserve_21;
  float32 HmiGen_Reserve_22;
  float32 HmiGen_Reserve_23;

  float32 HmiGen_Reserve_30;
  float32 HmiGen_Reserve_31;
  float32 HmiGen_Reserve_32;
  float32 HmiGen_Reserve_33;
}HmiSM_Generic_t;

typedef struct SVS_NVMData_s
{
  boolean IeSVS_b_isDynGridPrstFromNVM;
  boolean IeSVS_b_isFwdCamGridPrstFromNVM;
}SVS_NVMData_t;

typedef enum ME_Hydra2defs_E_CameraSensor_e
{

  SensorIDx_Left    = 0,
  SensorIDx_Right   = 1,
  SensorIDx_Front   = 2,
  SensorIDx_Rear    = 3,
} ME_Hydra2defs_E_CameraSensor_t;
#endif
