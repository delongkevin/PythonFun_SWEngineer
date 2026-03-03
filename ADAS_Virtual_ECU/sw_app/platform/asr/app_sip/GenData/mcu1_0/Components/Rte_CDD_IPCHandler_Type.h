/**********************************************************************************************************************
 *  COPYRIGHT
 *  -------------------------------------------------------------------------------------------------------------------
 *  \verbatim
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 *  -------------------------------------------------------------------------------------------------------------------
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *             File:  Rte_CDD_IPCHandler_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <CDD_IPCHandler>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_CDD_IPCHANDLER_TYPE_H
# define RTE_CDD_IPCHANDLER_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  define CM_TCH_X_COORD_adt_LowerLimit (0U)
#  define CM_TCH_X_COORD_adt_UpperLimit (65535U)

#  define CM_TCH_Y_COORD_adt_LowerLimit (0U)
#  define CM_TCH_Y_COORD_adt_UpperLimit (65535U)

#  define FD14_THA_SteeringDamping_adt_LowerLimit (0U)
#  define FD14_THA_SteeringDamping_adt_UpperLimit (255U)

#  define TotalOdometer_adt_LowerLimit (0U)
#  define TotalOdometer_adt_UpperLimit (1048575U)

#  define APARequestSts_adt_LowerLimit (0U)
#  define APARequestSts_adt_UpperLimit (1U)

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef BBB_NONE
#   define BBB_NONE (0U)
#  endif

#  ifndef BBB_CHECK_ENTIRE_SURROUNDINGS
#   define BBB_CHECK_ENTIRE_SURROUNDINGS (1U)
#  endif

#  ifndef BBB_BUTTON_PRESSED
#   define BBB_BUTTON_PRESSED (2U)
#  endif

#  ifndef BBB_CRUISE_CONTROL_ENGAGED
#   define BBB_CRUISE_CONTROL_ENGAGED (3U)
#  endif

#  ifndef BBB_DOOR_OPEN
#   define BBB_DOOR_OPEN (4U)
#  endif

#  ifndef BBB_LIFTGATE_OPEN
#   define BBB_LIFTGATE_OPEN (5U)
#  endif

#  ifndef BBB_ESC_ACTIVE
#   define BBB_ESC_ACTIVE (6U)
#  endif

#  ifndef BBB_SPEED_TOO_HIGH
#   define BBB_SPEED_TOO_HIGH (7U)
#  endif

#  ifndef BBB_LOW_ACTIVE
#   define BBB_LOW_ACTIVE (8U)
#  endif

#  ifndef BBB_TRAILER_DETECTED
#   define BBB_TRAILER_DETECTED (9U)
#  endif

#  ifndef BBB_SERVICE_REQUIRED
#   define BBB_SERVICE_REQUIRED (10U)
#  endif

#  ifndef BBB_WIPE_FRONT_SENSOR
#   define BBB_WIPE_FRONT_SENSOR (11U)
#  endif

#  ifndef BBB_WIPE_REAR_SENSOR
#   define BBB_WIPE_REAR_SENSOR (12U)
#  endif

#  ifndef BBB_TEMPORARILY_UNAVAILABLE
#   define BBB_TEMPORARILY_UNAVAILABLE (13U)
#  endif

#  ifndef BBB_STEERING_WHEEL_TOUCHED
#   define BBB_STEERING_WHEEL_TOUCHED (14U)
#  endif

#  ifndef BBB_DRIVER_OVERRIDE
#   define BBB_DRIVER_OVERRIDE (15U)
#  endif

#  ifndef BBB_MANUAL_PARK_REQUIRED
#   define BBB_MANUAL_PARK_REQUIRED (16U)
#  endif

#  ifndef NONE_FULLSCREEN
#   define NONE_FULLSCREEN (0U)
#  endif

#  ifndef DOOR_OPEN_FULLSCREEN
#   define DOOR_OPEN_FULLSCREEN (1U)
#  endif

#  ifndef LIFEGATE_OPEN_FULLSCREEN
#   define LIFEGATE_OPEN_FULLSCREEN (2U)
#  endif

#  ifndef ESC_ACTIVE_FULLSCREEN
#   define ESC_ACTIVE_FULLSCREEN (3U)
#  endif

#  ifndef SPEED_TOO_HIGH_FULLSCREEN
#   define SPEED_TOO_HIGH_FULLSCREEN (4U)
#  endif

#  ifndef LO4_ACTIVE_FULLSCREEN
#   define LO4_ACTIVE_FULLSCREEN (5U)
#  endif

#  ifndef TRAILER_CONNECTED_FULLSCREEN
#   define TRAILER_CONNECTED_FULLSCREEN (6U)
#  endif

#  ifndef SERVICE_REQUIRED_FULLSCREEN
#   define SERVICE_REQUIRED_FULLSCREEN (7U)
#  endif

#  ifndef FRONT_WIPE_FULLSCREEN
#   define FRONT_WIPE_FULLSCREEN (8U)
#  endif

#  ifndef REAR_WIPE_FULLSCREEN
#   define REAR_WIPE_FULLSCREEN (9U)
#  endif

#  ifndef TEMP_NA_FULLSCREEN
#   define TEMP_NA_FULLSCREEN (10U)
#  endif

#  ifndef CRUISE_CONTROL_ENGAGED_FULLSCREEN
#   define CRUISE_CONTROL_ENGAGED_FULLSCREEN (11U)
#  endif

#  ifndef BUTTON_PRESS_FULLSCREEN
#   define BUTTON_PRESS_FULLSCREEN (12U)
#  endif

#  ifndef TBB_NONE
#   define TBB_NONE (0U)
#  endif

#  ifndef TBB_ACTIVE_PARKSENSE_ENGAGED
#   define TBB_ACTIVE_PARKSENSE_ENGAGED (1U)
#  endif

#  ifndef TBB_WAIT_FOR_STEER
#   define TBB_WAIT_FOR_STEER (2U)
#  endif

#  ifndef TBB_MOVE_BACKWARD
#   define TBB_MOVE_BACKWARD (3U)
#  endif

#  ifndef TBB_SHIFT_TO_DRIVE
#   define TBB_SHIFT_TO_DRIVE (4U)
#  endif

#  ifndef TBB_MOVE_FORWARD
#   define TBB_MOVE_FORWARD (5U)
#  endif

#  ifndef TBB_SHIFT_TO_REVERSE
#   define TBB_SHIFT_TO_REVERSE (6U)
#  endif

#  ifndef TBB_COMPLETE_HMI
#   define TBB_COMPLETE_HMI (7U)
#  endif

#  ifndef TBB_DOOR_OPEN
#   define TBB_DOOR_OPEN (8U)
#  endif

#  ifndef TBB_LIFTGATE_OPEN
#   define TBB_LIFTGATE_OPEN (9U)
#  endif

#  ifndef TBB_ESC_ACTIVE
#   define TBB_ESC_ACTIVE (10U)
#  endif

#  ifndef TBB_LOW_ACTIVE
#   define TBB_LOW_ACTIVE (11U)
#  endif

#  ifndef TBB_TRAILER_DETECTED
#   define TBB_TRAILER_DETECTED (12U)
#  endif

#  ifndef TBB_SERVICE_REQUIRED
#   define TBB_SERVICE_REQUIRED (13U)
#  endif

#  ifndef TBB_WIPE_FRONT_SENSOR
#   define TBB_WIPE_FRONT_SENSOR (14U)
#  endif

#  ifndef TBB_WIPE_REAR_SENSOR
#   define TBB_WIPE_REAR_SENSOR (15U)
#  endif

#  ifndef TBB_TEMPORARILY_UNAVAILABLE
#   define TBB_TEMPORARILY_UNAVAILABLE (16U)
#  endif

#  ifndef TRB_NONE
#   define TRB_NONE (0U)
#  endif

#  ifndef TRB_REMOVE_HANDS_FEET
#   define TRB_REMOVE_HANDS_FEET (1U)
#  endif

#  ifndef TRB_PAUSED_HOLD_BUTTON
#   define TRB_PAUSED_HOLD_BUTTON (2U)
#  endif

#  ifndef TRB_PAUSED_OBJECT_IN_PATH
#   define TRB_PAUSED_OBJECT_IN_PATH (3U)
#  endif

#  ifndef TRB_STOP
#   define TRB_STOP (4U)
#  endif

#  ifndef TRB_SPEED_TOO_HIGH
#   define TRB_SPEED_TOO_HIGH (5U)
#  endif

#  ifndef TRB_TAKE_CONTROL
#   define TRB_TAKE_CONTROL (6U)
#  endif

#  define ASCM_Stat_adt_LowerLimit (0U)
#  define ASCM_Stat_adt_UpperLimit (15U)

#  define InvalidValue_ASCM_Stat (15U)

#  ifndef Cx0_NONE
#   define Cx0_NONE (0U)
#  endif

#  ifndef Cx1_DUMP
#   define Cx1_DUMP (1U)
#  endif

#  ifndef Cx2_PARK
#   define Cx2_PARK (2U)
#  endif

#  ifndef Cx3_AERO
#   define Cx3_AERO (3U)
#  endif

#  ifndef Cx4_NVL
#   define Cx4_NVL (4U)
#  endif

#  ifndef Cx5_OR1
#   define Cx5_OR1 (5U)
#  endif

#  ifndef Cx6_ORL2
#   define Cx6_ORL2 (6U)
#  endif

#  ifndef Cx7_Lifter
#   define Cx7_Lifter (7U)
#  endif

#  ifndef Cx8_RAISE
#   define Cx8_RAISE (8U)
#  endif

#  ifndef Cx9_LOWER
#   define Cx9_LOWER (9U)
#  endif

#  ifndef CxA_SYSFAIL
#   define CxA_SYSFAIL (10U)
#  endif

#  ifndef CxB_SRVS
#   define CxB_SRVS (11U)
#  endif

#  ifndef CxC_AERO2
#   define CxC_AERO2 (12U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define ASCM_SysFail_adt_LowerLimit (0U)
#  define ASCM_SysFail_adt_UpperLimit (1U)

#  ifndef Cx0_FALSE
#   define Cx0_FALSE (0U)
#  endif

#  ifndef Cx1_TRUE
#   define Cx1_TRUE (1U)
#  endif

#  define Active_Park_Mode_adt_LowerLimit (0U)
#  define Active_Park_Mode_adt_UpperLimit (1U)

#  ifndef Cx0_Full_Auto
#   define Cx0_Full_Auto (0U)
#  endif

#  ifndef Cx1_Steering_Only
#   define Cx1_Steering_Only (1U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define Backup_Cam_Delay_adt_LowerLimit (0U)
#  define Backup_Cam_Delay_adt_UpperLimit (1U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define Brk_Stat_adt_LowerLimit (0U)
#  define Brk_Stat_adt_UpperLimit (3U)

#  define InvalidValue_Brk_Stat (3U)

#  ifndef Cx0_IDLE
#   define Cx0_IDLE (0U)
#  endif

#  ifndef Cx1_BRAKING
#   define Cx1_BRAKING (1U)
#  endif

#  ifndef Cx2_NDEF2
#   define Cx2_NDEF2 (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define CM_TCH_STAT_adt_LowerLimit (0U)
#  define CM_TCH_STAT_adt_UpperLimit (7U)

#  define InvalidValue_CM_TCH_STAT (7U)

#  ifndef Cx0_TCH_NOT_PSD
#   define Cx0_TCH_NOT_PSD (0U)
#  endif

#  ifndef Cx1_TCH_PSD
#   define Cx1_TCH_PSD (1U)
#  endif

#  ifndef Cx2_TCH_PS_CAN
#   define Cx2_TCH_PS_CAN (2U)
#  endif

#  ifndef Cx3_Not_Used
#   define Cx3_Not_Used (3U)
#  endif

#  ifndef Cx4_TCH_CFG_RES
#   define Cx4_TCH_CFG_RES (4U)
#  endif

#  ifndef Cx5_TCH_CFG_OFFSET
#   define Cx5_TCH_CFG_OFFSET (5U)
#  endif

#  ifndef Cx6_TCH_CFG_MAX
#   define Cx6_TCH_CFG_MAX (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef CalibrationState_DriveStraight_DID
#   define CalibrationState_DriveStraight_DID (0U)
#  endif

#  ifndef CalibrationState_TurnLeftOrRight_DID
#   define CalibrationState_TurnLeftOrRight_DID (1U)
#  endif

#  ifndef CalibrationState_None_DID
#   define CalibrationState_None_DID (2U)
#  endif

#  ifndef CalibrationState_SNA_DID
#   define CalibrationState_SNA_DID (3U)
#  endif

#  ifndef CalibrationState_DriveStraight
#   define CalibrationState_DriveStraight (0U)
#  endif

#  ifndef CalibrationState_TurnLeftOrRight
#   define CalibrationState_TurnLeftOrRight (1U)
#  endif

#  ifndef CalibrationState_Wait
#   define CalibrationState_Wait (2U)
#  endif

#  define CameraDisplaySts2_adt_LowerLimit (0U)
#  define CameraDisplaySts2_adt_UpperLimit (15U)

#  ifndef Cx0_Default
#   define Cx0_Default (0U)
#  endif

#  ifndef Cx1_View_1
#   define Cx1_View_1 (1U)
#  endif

#  ifndef Cx2_View_2
#   define Cx2_View_2 (2U)
#  endif

#  ifndef Cx3_View_3
#   define Cx3_View_3 (3U)
#  endif

#  ifndef Cx4_View_4
#   define Cx4_View_4 (4U)
#  endif

#  ifndef Cx5_View_5
#   define Cx5_View_5 (5U)
#  endif

#  ifndef Cx6_View_6
#   define Cx6_View_6 (6U)
#  endif

#  ifndef Cx7_View_7
#   define Cx7_View_7 (7U)
#  endif

#  ifndef Cx8_View_8
#   define Cx8_View_8 (8U)
#  endif

#  ifndef Cx9_View_9
#   define Cx9_View_9 (9U)
#  endif

#  ifndef CxA_View_10
#   define CxA_View_10 (10U)
#  endif

#  ifndef CxB_View_11
#   define CxB_View_11 (11U)
#  endif

#  ifndef CxC_View_12
#   define CxC_View_12 (12U)
#  endif

#  ifndef CxD_View_13
#   define CxD_View_13 (13U)
#  endif

#  ifndef CxE_View_14
#   define CxE_View_14 (14U)
#  endif

#  ifndef CxF_View_15
#   define CxF_View_15 (15U)
#  endif

#  ifndef Camera_None_Active
#   define Camera_None_Active (0U)
#  endif

#  ifndef Camera_Left_Right_Front
#   define Camera_Left_Right_Front (1U)
#  endif

#  ifndef Camera_Left_Right
#   define Camera_Left_Right (2U)
#  endif

#  ifndef Camera_Left_Front
#   define Camera_Left_Front (3U)
#  endif

#  ifndef Camera_Right_Front
#   define Camera_Right_Front (4U)
#  endif

#  ifndef Camera_Front
#   define Camera_Front (5U)
#  endif

#  ifndef Camera_Left
#   define Camera_Left (6U)
#  endif

#  ifndef Camera_Right
#   define Camera_Right (7U)
#  endif

#  ifndef Production
#   define Production (0U)
#  endif

#  ifndef Debug
#   define Debug (1U)
#  endif

#  ifndef Record
#   define Record (2U)
#  endif

#  ifndef Record_UssDebug
#   define Record_UssDebug (3U)
#  endif

#  ifndef Record_Debug
#   define Record_Debug (4U)
#  endif

#  ifndef Replay
#   define Replay (5U)
#  endif

#  ifndef Replay_UssDebug
#   define Replay_UssDebug (6U)
#  endif

#  ifndef Replay_Debug
#   define Replay_Debug (7U)
#  endif

#  ifndef Uss_Debug
#   define Uss_Debug (8U)
#  endif

#  define CmdIgnSts_adt_LowerLimit (0U)
#  define CmdIgnSts_adt_UpperLimit (7U)

#  define InvalidValue_CmdIgnSts (7U)

#  ifndef Cx0_Initialization
#   define Cx0_Initialization (0U)
#  endif

#  ifndef Cx1_IGN_LK
#   define Cx1_IGN_LK (1U)
#  endif

#  ifndef Cx3_ACC
#   define Cx3_ACC (3U)
#  endif

#  ifndef Cx4_RUN
#   define Cx4_RUN (4U)
#  endif

#  ifndef Cx5_START
#   define Cx5_START (5U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef e_Cplr_Not_Valid
#   define e_Cplr_Not_Valid (0U)
#  endif

#  ifndef e_Cplr_Not_Detected
#   define e_Cplr_Not_Detected (1U)
#  endif

#  ifndef e_Cplr_Detected
#   define e_Cplr_Detected (2U)
#  endif

#  ifndef DLD_Normal
#   define DLD_Normal (0U)
#  endif

#  ifndef DLD_Blockage
#   define DLD_Blockage (1U)
#  endif

#  ifndef DLD_Low_Luminance
#   define DLD_Low_Luminance (2U)
#  endif

#  ifndef DLD_BackLit
#   define DLD_BackLit (3U)
#  endif

#  ifndef DLD_Unknown
#   define DLD_Unknown (10U)
#  endif

#  ifndef DetectionFailInfo_OCCULSION_or_LOWLIGHT_DID
#   define DetectionFailInfo_OCCULSION_or_LOWLIGHT_DID (0U)
#  endif

#  ifndef DetectionFailInfo_NONE_DID
#   define DetectionFailInfo_NONE_DID (1U)
#  endif

#  ifndef DetectionFailInfo_SNA_DID
#   define DetectionFailInfo_SNA_DID (2U)
#  endif

#  ifndef DetectionFailInfo_SNA
#   define DetectionFailInfo_SNA (0U)
#  endif

#  ifndef DetectionFailInfo_NONE
#   define DetectionFailInfo_NONE (1U)
#  endif

#  ifndef DetectionFailInfo_OCCULSION
#   define DetectionFailInfo_OCCULSION (2U)
#  endif

#  define DriverDoorSts_adt_LowerLimit (0U)
#  define DriverDoorSts_adt_UpperLimit (1U)

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  define DynamicGrid_adt_LowerLimit (0U)
#  define DynamicGrid_adt_UpperLimit (1U)

#  ifndef Cx0_Dynamic_Gridlines_OFF
#   define Cx0_Dynamic_Gridlines_OFF (0U)
#  endif

#  ifndef Cx1_Dynamic_Gridlines_ON
#   define Cx1_Dynamic_Gridlines_ON (1U)
#  endif

#  define ECM_THA_Resp_adt_LowerLimit (0U)
#  define ECM_THA_Resp_adt_UpperLimit (3U)

#  define InvalidValue_ECM_THA_Resp (3U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define ECM_TRSC_Resp_adt_LowerLimit (0U)
#  define ECM_TRSC_Resp_adt_UpperLimit (3U)

#  define InvalidValue_ECM_TRSC_Resp (3U)

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define EPS_SteeringTouchStat_adt_LowerLimit (0U)
#  define EPS_SteeringTouchStat_adt_UpperLimit (1U)

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx1_True
#   define Cx1_True (1U)
#  endif

#  define EPS_SteeringTouq_Resp_adt_LowerLimit (0U)
#  define EPS_SteeringTouq_Resp_adt_UpperLimit (3U)

#  define InvalidValue_EPS_SteeringTouq_Resp (3U)

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define EPS_THA_DriverTorqueOverride_adt_LowerLimit (0U)
#  define EPS_THA_DriverTorqueOverride_adt_UpperLimit (3U)

#  define InvalidValue_EPS_THA_DriverTorqueOverride (3U)

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx1_True
#   define Cx1_True (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define EPS_THA_SteeringTorqueResp_adt_LowerLimit (0U)
#  define EPS_THA_SteeringTorqueResp_adt_UpperLimit (7U)

#  define InvalidValue_EPS_THA_SteeringTorqueResp (7U)

#  ifndef Cx0_Temp_NA
#   define Cx0_Temp_NA (0U)
#  endif

#  ifndef Cx1_Perm_NA
#   define Cx1_Perm_NA (1U)
#  endif

#  ifndef Cx2_TOI_Available
#   define Cx2_TOI_Available (2U)
#  endif

#  ifndef Cx3_TOI_Unavailable
#   define Cx3_TOI_Unavailable (3U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define ESS_ENG_ST_W_adt_LowerLimit (0U)
#  define ESS_ENG_ST_W_adt_UpperLimit (15U)

#  define InvalidValue_ESS_ENG_ST_W (15U)

#  ifndef Cx1_ENS_Stopped_ENS_STOPPED
#   define Cx1_ENS_Stopped_ENS_STOPPED (1U)
#  endif

#  ifndef Cx2_ENS_Request_Start_ENS_RQ_ST
#   define Cx2_ENS_Request_Start_ENS_RQ_ST (2U)
#  endif

#  ifndef Cx3_ENS_Running_ENS_RUN
#   define Cx3_ENS_Running_ENS_RUN (3U)
#  endif

#  ifndef Cx4_ENS_Stop_Pending_ENS_STOP_PEND
#   define Cx4_ENS_Stop_Pending_ENS_STOP_PEND (4U)
#  endif

#  ifndef Cx5_ENS_Start_protection_ENS_ST_PRTCT
#   define Cx5_ENS_Start_protection_ENS_ST_PRTCT (5U)
#  endif

#  ifndef Cx6_ENS_Start_inhibit_ENS_ST_INH
#   define Cx6_ENS_Start_inhibit_ENS_ST_INH (6U)
#  endif

#  ifndef Cx7_ENS_disabled_ENS_DSBL
#   define Cx7_ENS_disabled_ENS_DSBL (7U)
#  endif

#  ifndef Cx8_ENS_IHB_LATCH
#   define Cx8_ENS_IHB_LATCH (8U)
#  endif

#  ifndef Cx9_ENS_Starting_ENS_Starting
#   define Cx9_ENS_Starting_ENS_Starting (9U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define EngineSts_W_adt_LowerLimit (0U)
#  define EngineSts_W_adt_UpperLimit (3U)

#  define InvalidValue_EngineSts_W (3U)

#  ifndef Cx0_Engine_Off
#   define Cx0_Engine_Off (0U)
#  endif

#  ifndef Cx1_Engine_Cranking
#   define Cx1_Engine_Cranking (1U)
#  endif

#  ifndef Cx2_Engine_On
#   define Cx2_Engine_On (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_FD14_LHF_FastPulseCounter (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define InvalidValue_FD14_LHR_FastPulseCounter (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_LatAccelerationOffset_BSM_adt_LowerLimit (0U)
#  define FD14_LatAccelerationOffset_BSM_adt_UpperLimit (255U)

#  define InvalidValue_FD14_LatAccelerationOffset_BSM (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_LongAccelerationOffset_BSM_adt_LowerLimit (0U)
#  define FD14_LongAccelerationOffset_BSM_adt_UpperLimit (255U)

#  define InvalidValue_FD14_LongAccelerationOffset_BSM (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_LwsAngle_adt_LowerLimit (0U)
#  define FD14_LwsAngle_adt_UpperLimit (65535U)

#  define InvalidValue_FD14_LwsAngle (65535U)

#  ifndef CxFFFF_SNA
#   define CxFFFF_SNA (65535U)
#  endif

#  define FD14_PPPA_MaxSpeed_adt_LowerLimit (0U)
#  define FD14_PPPA_MaxSpeed_adt_UpperLimit (255U)

#  define InvalidValue_FD14_PPPA_MaxSpeed (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_PdlPosActual_adt_LowerLimit (0U)
#  define FD14_PdlPosActual_adt_UpperLimit (255U)

#  define InvalidValue_FD14_PdlPosActual (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define InvalidValue_FD14_RHF_FastPulseCounter (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define InvalidValue_FD14_RHR_FastPulseCounter (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_Slope_adt_LowerLimit (0U)
#  define FD14_Slope_adt_UpperLimit (255U)

#  define InvalidValue_FD14_Slope (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FD14_TRSC_SteeringDamping_adt_LowerLimit (0U)
#  define FD14_TRSC_SteeringDamping_adt_UpperLimit (255U)

#  define InvalidValue_FD14_TRSC_SteeringDamping (255U)

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  define FL_Lvl_Adj_adt_LowerLimit (0U)
#  define FL_Lvl_Adj_adt_UpperLimit (1U)

#  ifndef Cx1_Adjusting
#   define Cx1_Adjusting (1U)
#  endif

#  define FR_Lvl_Adj_adt_LowerLimit (0U)
#  define FR_Lvl_Adj_adt_UpperLimit (1U)

#  ifndef Cx1_Adjusting
#   define Cx1_Adjusting (1U)
#  endif

#  define FT_PAMRequestSts_adt_LowerLimit (0U)
#  define FT_PAMRequestSts_adt_UpperLimit (1U)

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  define Fwrd_Cam_Guidelines_adt_LowerLimit (0U)
#  define Fwrd_Cam_Guidelines_adt_UpperLimit (1U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define GearEngaged_adt_LowerLimit (0U)
#  define GearEngaged_adt_UpperLimit (15U)

#  define InvalidValue_GearEngaged (15U)

#  ifndef Cx0_Neutral
#   define Cx0_Neutral (0U)
#  endif

#  ifndef Cx1_ForwardGear_1
#   define Cx1_ForwardGear_1 (1U)
#  endif

#  ifndef Cx2_ForwardGear_2
#   define Cx2_ForwardGear_2 (2U)
#  endif

#  ifndef Cx3_ForwardGear_3
#   define Cx3_ForwardGear_3 (3U)
#  endif

#  ifndef Cx4_ForwardGear_4
#   define Cx4_ForwardGear_4 (4U)
#  endif

#  ifndef Cx5_ForwardGear_5
#   define Cx5_ForwardGear_5 (5U)
#  endif

#  ifndef Cx6_ForwardGear_6
#   define Cx6_ForwardGear_6 (6U)
#  endif

#  ifndef Cx7_ForwardGear_7
#   define Cx7_ForwardGear_7 (7U)
#  endif

#  ifndef Cx8_ForwardGear_8
#   define Cx8_ForwardGear_8 (8U)
#  endif

#  ifndef Cx9_ForwardGear_9
#   define Cx9_ForwardGear_9 (9U)
#  endif

#  ifndef CxD_Parking
#   define CxD_Parking (13U)
#  endif

#  ifndef CxE_ReverseGear
#   define CxE_ReverseGear (14U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define GearEngagedForDisplay_adt_LowerLimit (0U)
#  define GearEngagedForDisplay_adt_UpperLimit (31U)

#  define InvalidValue_GearEngagedForDisplay (31U)

#  ifndef Cx00_Initialize
#   define Cx00_Initialize (0U)
#  endif

#  ifndef Cx01_1st_gear
#   define Cx01_1st_gear (1U)
#  endif

#  ifndef Cx02_2nd_gear
#   define Cx02_2nd_gear (2U)
#  endif

#  ifndef Cx03_3rd_gear
#   define Cx03_3rd_gear (3U)
#  endif

#  ifndef Cx04_4th_gear
#   define Cx04_4th_gear (4U)
#  endif

#  ifndef Cx05_5th_gear
#   define Cx05_5th_gear (5U)
#  endif

#  ifndef Cx06_6th_gear
#   define Cx06_6th_gear (6U)
#  endif

#  ifndef Cx07_7th_gear
#   define Cx07_7th_gear (7U)
#  endif

#  ifndef Cx08_8th_gear_
#   define Cx08_8th_gear_ (8U)
#  endif

#  ifndef Cx09_9th_gear
#   define Cx09_9th_gear (9U)
#  endif

#  ifndef Cx0A_Not_used1
#   define Cx0A_Not_used1 (10U)
#  endif

#  ifndef Cx0B_Not_Used2
#   define Cx0B_Not_Used2 (11U)
#  endif

#  ifndef Cx0C_P
#   define Cx0C_P (12U)
#  endif

#  ifndef Cx0D_N
#   define Cx0D_N (13U)
#  endif

#  ifndef Cx0E_R
#   define Cx0E_R (14U)
#  endif

#  ifndef Cx0F_D
#   define Cx0F_D (15U)
#  endif

#  ifndef Cx10_L
#   define Cx10_L (16U)
#  endif

#  ifndef Cx11_M
#   define Cx11_M (17U)
#  endif

#  ifndef Cx12_S
#   define Cx12_S (18U)
#  endif

#  ifndef Cx1F_SNA
#   define Cx1F_SNA (31U)
#  endif

#  define HAS_Status_C2_adt_LowerLimit (0U)
#  define HAS_Status_C2_adt_UpperLimit (3U)

#  ifndef Cx0_Disabled
#   define Cx0_Disabled (0U)
#  endif

#  ifndef Cx1_Enabled
#   define Cx1_Enabled (1U)
#  endif

#  ifndef Cx2_Engaged
#   define Cx2_Engaged (2U)
#  endif

#  ifndef Cx3_Faulted
#   define Cx3_Faulted (3U)
#  endif

#  define HU_TRSC_EnableBtn_Sts_adt_LowerLimit (0U)
#  define HU_TRSC_EnableBtn_Sts_adt_UpperLimit (2U)

#  define InvalidValue_HU_TRSC_EnableBtn_Sts (2U)

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef Cx2_SNA
#   define Cx2_SNA (2U)
#  endif

#  ifndef e_Hitch_Not_Valid
#   define e_Hitch_Not_Valid (0U)
#  endif

#  ifndef e_Hitch_Not_Detected
#   define e_Hitch_Not_Detected (1U)
#  endif

#  ifndef e_Hitch_Detected
#   define e_Hitch_Detected (2U)
#  endif

#  ifndef AllowedParkingDirection_E_NODIR
#   define AllowedParkingDirection_E_NODIR (0U)
#  endif

#  ifndef AllowedParkingDirection_E_NOSE_IN_Only
#   define AllowedParkingDirection_E_NOSE_IN_Only (1U)
#  endif

#  ifndef AllowedParkingDirection_E_REAR_IN_Only
#   define AllowedParkingDirection_E_REAR_IN_Only (2U)
#  endif

#  ifndef AllowedParkingDirection_E_BOTH
#   define AllowedParkingDirection_E_BOTH (3U)
#  endif

#  define ITBM_TrlrStat_adt_LowerLimit (0U)
#  define ITBM_TrlrStat_adt_UpperLimit (3U)

#  define InvalidValue_ITBM_TrlrStat (3U)

#  ifndef Cx0_NO_TRLR
#   define Cx0_NO_TRLR (0U)
#  endif

#  ifndef Cx1_TRLR_PRSNT
#   define Cx1_TRLR_PRSNT (1U)
#  endif

#  ifndef Cx2_TRLR_DCONN
#   define Cx2_TRLR_DCONN (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define LHRDoorSts_adt_LowerLimit (0U)
#  define LHRDoorSts_adt_UpperLimit (1U)

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  ifndef LaneColor_None
#   define LaneColor_None (0U)
#  endif

#  ifndef LaneColor_White
#   define LaneColor_White (1U)
#  endif

#  ifndef LaneColor_Yellow
#   define LaneColor_Yellow (2U)
#  endif

#  ifndef LaneColor_Orange
#   define LaneColor_Orange (3U)
#  endif

#  ifndef LaneColor_Other
#   define LaneColor_Other (4U)
#  endif

#  ifndef Lane_Faulted
#   define Lane_Faulted (0U)
#  endif

#  ifndef Lane_Blocked
#   define Lane_Blocked (1U)
#  endif

#  ifndef Lane_Unknown
#   define Lane_Unknown (2U)
#  endif

#  ifndef Lane_Healthy
#   define Lane_Healthy (3U)
#  endif

#  ifndef LaneTrackState_Null
#   define LaneTrackState_Null (0U)
#  endif

#  ifndef LaneTrackState_Average
#   define LaneTrackState_Average (1U)
#  endif

#  ifndef LaneTrackState_Reset
#   define LaneTrackState_Reset (2U)
#  endif

#  ifndef LaneTrackState_Hold
#   define LaneTrackState_Hold (3U)
#  endif

#  ifndef LaneType_None
#   define LaneType_None (0U)
#  endif

#  ifndef LaneType_Solid
#   define LaneType_Solid (1U)
#  endif

#  ifndef LaneType_Dashed
#   define LaneType_Dashed (2U)
#  endif

#  ifndef LaneType_Double
#   define LaneType_Double (3U)
#  endif

#  ifndef LaneType_RoadEdge
#   define LaneType_RoadEdge (4U)
#  endif

#  ifndef LaneType_BottDots
#   define LaneType_BottDots (5U)
#  endif

#  ifndef LaneType_Barrier
#   define LaneType_Barrier (6U)
#  endif

#  ifndef LaneType_Other
#   define LaneType_Other (7U)
#  endif

#  define LanguageSelection_adt_LowerLimit (0U)
#  define LanguageSelection_adt_UpperLimit (255U)

#  ifndef Cx00_Italian
#   define Cx00_Italian (0U)
#  endif

#  ifndef Cx01_Deutsch
#   define Cx01_Deutsch (1U)
#  endif

#  ifndef Cx02_English
#   define Cx02_English (2U)
#  endif

#  ifndef Cx03_Espanol
#   define Cx03_Espanol (3U)
#  endif

#  ifndef Cx04_Francais
#   define Cx04_Francais (4U)
#  endif

#  ifndef Cx05_Portugues
#   define Cx05_Portugues (5U)
#  endif

#  ifndef Cx06_Polish
#   define Cx06_Polish (6U)
#  endif

#  ifndef Cx07_Dutch
#   define Cx07_Dutch (7U)
#  endif

#  ifndef Cx08_Brazilian
#   define Cx08_Brazilian (8U)
#  endif

#  ifndef Cx09_Turkish
#   define Cx09_Turkish (9U)
#  endif

#  ifndef Cx0A_Mexican
#   define Cx0A_Mexican (10U)
#  endif

#  ifndef Cx0B_English_US
#   define Cx0B_English_US (11U)
#  endif

#  ifndef Cx0C_Canadian
#   define Cx0C_Canadian (12U)
#  endif

#  ifndef Cx0D_Russian
#   define Cx0D_Russian (13U)
#  endif

#  ifndef Cx0E_Chinese
#   define Cx0E_Chinese (14U)
#  endif

#  ifndef Cx0F_Japanese
#   define Cx0F_Japanese (15U)
#  endif

#  ifndef Cx10_Korean
#   define Cx10_Korean (16U)
#  endif

#  ifndef Cx11_Arabic
#   define Cx11_Arabic (17U)
#  endif

#  ifndef Cx12_Czech
#   define Cx12_Czech (18U)
#  endif

#  ifndef Cx13_Slovakian
#   define Cx13_Slovakian (19U)
#  endif

#  ifndef Cx14_Hungarian
#   define Cx14_Hungarian (20U)
#  endif

#  ifndef Cx15_Hindi
#   define Cx15_Hindi (21U)
#  endif

#  define LwsAngleType_adt_LowerLimit (0U)
#  define LwsAngleType_adt_UpperLimit (3U)

#  define InvalidValue_LwsAngleType (3U)

#  ifndef Cx0_Absolute
#   define Cx0_Absolute (0U)
#  endif

#  ifndef Cx1_Relative
#   define Cx1_Relative (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibNotStarted
#   define ME_Hydra3defs_E_CalibNotStarted (0U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibPending
#   define ME_Hydra3defs_E_CalibPending (1U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibRunning
#   define ME_Hydra3defs_E_CalibRunning (2U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibCompletedSuccessful
#   define ME_Hydra3defs_E_CalibCompletedSuccessful (3U)
#  endif

#  ifndef ME_Hydra3defs_E_CalibAbortedFailed
#   define ME_Hydra3defs_E_CalibAbortedFailed (4U)
#  endif

#  ifndef CalibrationID_Zero
#   define CalibrationID_Zero (0U)
#  endif

#  ifndef CalibrationID_EOL
#   define CalibrationID_EOL (1U)
#  endif

#  ifndef CalibrationID_SC
#   define CalibrationID_SC (2U)
#  endif

#  ifndef CalibrationID_OC
#   define CalibrationID_OC (3U)
#  endif

#  ifndef CalibrationID_Current
#   define CalibrationID_Current (4U)
#  endif

#  ifndef CameraID_None
#   define CameraID_None (0U)
#  endif

#  ifndef CameraID_Front
#   define CameraID_Front (1U)
#  endif

#  ifndef CameraID_Left
#   define CameraID_Left (2U)
#  endif

#  ifndef CameraID_Rear
#   define CameraID_Rear (3U)
#  endif

#  ifndef CameraID_Right
#   define CameraID_Right (4U)
#  endif

#  ifndef CameraID_All
#   define CameraID_All (5U)
#  endif

#  ifndef CameraID_Invalid
#   define CameraID_Invalid (6U)
#  endif

#  ifndef e_EOLNotInit
#   define e_EOLNotInit (0U)
#  endif

#  ifndef e_EOLRunning
#   define e_EOLRunning (1U)
#  endif

#  ifndef e_EOLFinished
#   define e_EOLFinished (2U)
#  endif

#  ifndef e_EOL_CALIBRATION_IN_PROCESS
#   define e_EOL_CALIBRATION_IN_PROCESS (0U)
#  endif

#  ifndef e_EOL_CALIBRATION_SUCCESS
#   define e_EOL_CALIBRATION_SUCCESS (1U)
#  endif

#  ifndef e_EOL_MISSING_SOFTWARE
#   define e_EOL_MISSING_SOFTWARE (2U)
#  endif

#  ifndef e_EOL_PRECONDITIONS_NOT_CORRECT_VRANGE
#   define e_EOL_PRECONDITIONS_NOT_CORRECT_VRANGE (3U)
#  endif

#  ifndef e_EOL_PRECONDITION_NOT_CORRECT_NUMCAMERAS
#   define e_EOL_PRECONDITION_NOT_CORRECT_NUMCAMERAS (4U)
#  endif

#  ifndef e_EOL_MISSING_INTERNAL_LINK
#   define e_EOL_MISSING_INTERNAL_LINK (5U)
#  endif

#  ifndef e_EOL_VARIANT_CODING_ISSUE
#   define e_EOL_VARIANT_CODING_ISSUE (6U)
#  endif

#  ifndef e_EOL_TARGET_NOT_FOUND_INIT
#   define e_EOL_TARGET_NOT_FOUND_INIT (7U)
#  endif

#  ifndef e_EOL_TARGET_NOT_FOUND_LEFT
#   define e_EOL_TARGET_NOT_FOUND_LEFT (8U)
#  endif

#  ifndef e_EOL_TARGET_NOT_FOUND_RIGHT
#   define e_EOL_TARGET_NOT_FOUND_RIGHT (9U)
#  endif

#  ifndef e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT
#   define e_EOL_TARGET_IDENTIFICATION_ERROR_LEFT (10U)
#  endif

#  ifndef e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT
#   define e_EOL_TARGET_IDENTIFICATION_ERROR_RIGHT (11U)
#  endif

#  ifndef e_EOL_RESULT_EXCEED_QUALITY_LIMIT
#   define e_EOL_RESULT_EXCEED_QUALITY_LIMIT (12U)
#  endif

#  ifndef e_EOL_NOT_CALIBRATED
#   define e_EOL_NOT_CALIBRATED (13U)
#  endif

#  ifndef e_EOL_ABORTED
#   define e_EOL_ABORTED (14U)
#  endif

#  ifndef e_EOL_HMOGRAPHY_ESTIMATION_ERROR
#   define e_EOL_HMOGRAPHY_ESTIMATION_ERROR (15U)
#  endif

#  ifndef e_EOL_PRECONDITION_NOT_CORRECT_VELOCITY
#   define e_EOL_PRECONDITION_NOT_CORRECT_VELOCITY (16U)
#  endif

#  ifndef e_EOL_PRECONDITION_NOT_CORRECT_DOORS
#   define e_EOL_PRECONDITION_NOT_CORRECT_DOORS (17U)
#  endif

#  ifndef e_EOL_WRONG_CAMERA_SOFTWARE
#   define e_EOL_WRONG_CAMERA_SOFTWARE (18U)
#  endif

#  ifndef e_EOL_PRECONDITION_NOT_CORRECT
#   define e_EOL_PRECONDITION_NOT_CORRECT (19U)
#  endif

#  ifndef none
#   define none (0U)
#  endif

#  ifndef outofrange
#   define outofrange (1U)
#  endif

#  ifndef invalid
#   define invalid (2U)
#  endif

#  ifndef e_OC_Uninit
#   define e_OC_Uninit (0U)
#  endif

#  ifndef e_OC_InitOk
#   define e_OC_InitOk (1U)
#  endif

#  ifndef e_OC_Error
#   define e_OC_Error (2U)
#  endif

#  ifndef e_OC_FeatureCollection
#   define e_OC_FeatureCollection (3U)
#  endif

#  ifndef e_OC_FeatureCollectionCompleted
#   define e_OC_FeatureCollectionCompleted (4U)
#  endif

#  ifndef e_OC_Calibration
#   define e_OC_Calibration (5U)
#  endif

#  ifndef e_OC_CalibrationCompleted
#   define e_OC_CalibrationCompleted (6U)
#  endif

#  ifndef e_OC_Terminated
#   define e_OC_Terminated (7U)
#  endif

#  ifndef e_OC_Paused
#   define e_OC_Paused (8U)
#  endif

#  ifndef e_OC_Unknown
#   define e_OC_Unknown (9U)
#  endif

#  ifndef e_OC_End
#   define e_OC_End (10U)
#  endif

#  ifndef e_OC_NoError
#   define e_OC_NoError (0U)
#  endif

#  ifndef e_OC_InitFail
#   define e_OC_InitFail (1U)
#  endif

#  ifndef e_OC_StartFail
#   define e_OC_StartFail (2U)
#  endif

#  ifndef e_OC_FeatureCollectionError
#   define e_OC_FeatureCollectionError (3U)
#  endif

#  ifndef e_OC_CalibrationError
#   define e_OC_CalibrationError (4U)
#  endif

#  ifndef e_OC_InvalidConfiguration
#   define e_OC_InvalidConfiguration (5U)
#  endif

#  ifndef e_OC_InvalidSavedData
#   define e_OC_InvalidSavedData (6U)
#  endif

#  ifndef e_OC_UnexpectedRequest
#   define e_OC_UnexpectedRequest (7U)
#  endif

#  ifndef e_OC_Num
#   define e_OC_Num (8U)
#  endif

#  ifndef roucameraTestPattern
#   define roucameraTestPattern (1U)
#  endif

#  ifndef rouActivateScreen
#   define rouActivateScreen (2U)
#  endif

#  ifndef NoTP
#   define NoTP (0U)
#  endif

#  ifndef VerticalColorBars100PercentTP
#   define VerticalColorBars100PercentTP (2U)
#  endif

#  ifndef FadeToGrayVerticalColorBarsTP
#   define FadeToGrayVerticalColorBarsTP (3U)
#  endif

#  ifndef Solid_BlackTP
#   define Solid_BlackTP (4U)
#  endif

#  ifndef Solid_WhiteTP
#   define Solid_WhiteTP (5U)
#  endif

#  ifndef Solid_RedTP
#   define Solid_RedTP (6U)
#  endif

#  ifndef Solid_GreenTP
#   define Solid_GreenTP (7U)
#  endif

#  define MRM_STATUS_C2_adt_LowerLimit (0U)
#  define MRM_STATUS_C2_adt_UpperLimit (7U)

#  define InvalidValue_MRM_STATUS_C2 (7U)

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx1_MRM_in_Process
#   define Cx1_MRM_in_Process (1U)
#  endif

#  ifndef Cx2_Vehicle_Secure_Request
#   define Cx2_Vehicle_Secure_Request (2U)
#  endif

#  ifndef Cx3_Vehicle_Securement_Complete
#   define Cx3_Vehicle_Securement_Complete (3U)
#  endif

#  ifndef Cx4_Canceled
#   define Cx4_Canceled (4U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef NVM_REQ_OK
#   define NVM_REQ_OK (0U)
#  endif

#  ifndef NVM_REQ_NOT_OK
#   define NVM_REQ_NOT_OK (1U)
#  endif

#  ifndef NVM_REQ_PENDING
#   define NVM_REQ_PENDING (2U)
#  endif

#  ifndef NVM_REQ_INTEGRITY_FAILED
#   define NVM_REQ_INTEGRITY_FAILED (3U)
#  endif

#  ifndef NVM_REQ_BLOCK_SKIPPED
#   define NVM_REQ_BLOCK_SKIPPED (4U)
#  endif

#  ifndef NVM_REQ_NV_INVALIDATED
#   define NVM_REQ_NV_INVALIDATED (5U)
#  endif

#  ifndef NVM_REQ_CANCELED
#   define NVM_REQ_CANCELED (6U)
#  endif

#  ifndef NVM_REQ_REDUNDANCY_FAILED
#   define NVM_REQ_REDUNDANCY_FAILED (7U)
#  endif

#  ifndef NVM_REQ_RESTORED_FROM_ROM
#   define NVM_REQ_RESTORED_FROM_ROM (8U)
#  endif

#  define PAMRequestSts_adt_LowerLimit (0U)
#  define PAMRequestSts_adt_UpperLimit (1U)

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  define PamChimeVolumeFront_adt_LowerLimit (0U)
#  define PamChimeVolumeFront_adt_UpperLimit (3U)

#  ifndef Cx0_Low
#   define Cx0_Low (0U)
#  endif

#  ifndef Cx1_Medium
#   define Cx1_Medium (1U)
#  endif

#  ifndef Cx2_High
#   define Cx2_High (2U)
#  endif

#  define PamChimeVolumeRear_adt_LowerLimit (0U)
#  define PamChimeVolumeRear_adt_UpperLimit (3U)

#  ifndef Cx0_Low
#   define Cx0_Low (0U)
#  endif

#  ifndef Cx1_Medium
#   define Cx1_Medium (1U)
#  endif

#  ifndef Cx2_High
#   define Cx2_High (2U)
#  endif

#  ifndef ParkINStyle_E_CAR_IN_NULL
#   define ParkINStyle_E_CAR_IN_NULL (0U)
#  endif

#  ifndef ParkINStyle_E_FRONT_IN
#   define ParkINStyle_E_FRONT_IN (1U)
#  endif

#  ifndef ParkINStyle_E_REAR_IN
#   define ParkINStyle_E_REAR_IN (2U)
#  endif

#  ifndef ParkOutStyle_E_CAR_OUT_NULL
#   define ParkOutStyle_E_CAR_OUT_NULL (0U)
#  endif

#  ifndef ParkOutStyle_E_FRONT_OUT
#   define ParkOutStyle_E_FRONT_OUT (1U)
#  endif

#  ifndef ParkOutStyle_E_REAR_OUT
#   define ParkOutStyle_E_REAR_OUT (2U)
#  endif

#  ifndef ParkingSlotID_E_NONE
#   define ParkingSlotID_E_NONE (0U)
#  endif

#  ifndef ParkingSlotID_E_L1
#   define ParkingSlotID_E_L1 (1U)
#  endif

#  ifndef ParkingSlotID_E_L2
#   define ParkingSlotID_E_L2 (2U)
#  endif

#  ifndef ParkingSlotID_E_L3
#   define ParkingSlotID_E_L3 (3U)
#  endif

#  ifndef ParkingSlotID_E_R1
#   define ParkingSlotID_E_R1 (4U)
#  endif

#  ifndef ParkingSlotID_E_R2
#   define ParkingSlotID_E_R2 (5U)
#  endif

#  ifndef ParkingSlotID_E_R3
#   define ParkingSlotID_E_R3 (6U)
#  endif

#  ifndef ParkingSlotType_E_PW_NODIR
#   define ParkingSlotType_E_PW_NODIR (0U)
#  endif

#  ifndef ParkingSlotType_E_PW_PERPENDICULAR
#   define ParkingSlotType_E_PW_PERPENDICULAR (1U)
#  endif

#  ifndef ParkingSlotType_E_PW_DIAGONAL
#   define ParkingSlotType_E_PW_DIAGONAL (2U)
#  endif

#  ifndef ParkingSlotType_E_PW_PARALLEL
#   define ParkingSlotType_E_PW_PARALLEL (3U)
#  endif

#  define PsngrDoorSts_adt_LowerLimit (0U)
#  define PsngrDoorSts_adt_UpperLimit (1U)

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  define RHRDoorSts_adt_LowerLimit (0U)
#  define RHRDoorSts_adt_UpperLimit (1U)

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  define RHatchSts_adt_LowerLimit (0U)
#  define RHatchSts_adt_UpperLimit (1U)

#  ifndef Cx0_Closed
#   define Cx0_Closed (0U)
#  endif

#  ifndef Cx1_Open
#   define Cx1_Open (1U)
#  endif

#  define RL_Lvl_Adj_adt_LowerLimit (0U)
#  define RL_Lvl_Adj_adt_UpperLimit (1U)

#  ifndef Cx1_Adjusting
#   define Cx1_Adjusting (1U)
#  endif

#  define RR_Lvl_Adj_adt_LowerLimit (0U)
#  define RR_Lvl_Adj_adt_UpperLimit (1U)

#  ifndef Cx1_Adjusting
#   define Cx1_Adjusting (1U)
#  endif

#  define Rear_Brk_Asst_adt_LowerLimit (0U)
#  define Rear_Brk_Asst_adt_UpperLimit (1U)

#  ifndef Cx0_Warn
#   define Cx0_Warn (0U)
#  endif

#  ifndef Cx1_Warn_Braking
#   define Cx1_Warn_Braking (1U)
#  endif

#  ifndef unknown
#   define unknown (0U)
#  endif

#  ifndef known
#   define known (1U)
#  endif

#  ifndef QNX_IDLE_STATE
#   define QNX_IDLE_STATE (0U)
#  endif

#  ifndef QNX_BOOTUP_STATE
#   define QNX_BOOTUP_STATE (1U)
#  endif

#  ifndef QNX_RUNNING_STATE
#   define QNX_RUNNING_STATE (2U)
#  endif

#  ifndef QNX_RUNNING_PROXI_WRITTEN_PASS_STATE
#   define QNX_RUNNING_PROXI_WRITTEN_PASS_STATE (3U)
#  endif

#  ifndef QNX_RUNNING_PROXI_WRITTEN_FAILED_STATE
#   define QNX_RUNNING_PROXI_WRITTEN_FAILED_STATE (4U)
#  endif

#  ifndef QNX_RUNNING_PROXI_WRITTEN_SKIPPED_STATE
#   define QNX_RUNNING_PROXI_WRITTEN_SKIPPED_STATE (5U)
#  endif

#  ifndef QNX_RUNNING_PROXI_WAITING_TO_WRITE_STATE
#   define QNX_RUNNING_PROXI_WAITING_TO_WRITE_STATE (6U)
#  endif

#  ifndef QNX_RESTART_REQ_STATE
#   define QNX_RESTART_REQ_STATE (7U)
#  endif

#  ifndef QNX_ETFS_NOT_READY_STATE
#   define QNX_ETFS_NOT_READY_STATE (8U)
#  endif

#  ifndef QNX_SHUTING_DOWN
#   define QNX_SHUTING_DOWN (9U)
#  endif

#  ifndef TeTRSC_e_TADAngActSign_None
#   define TeTRSC_e_TADAngActSign_None (0U)
#  endif

#  ifndef TeTRSC_e_TADAngActSign_Positive
#   define TeTRSC_e_TADAngActSign_Positive (1U)
#  endif

#  ifndef TeTRSC_e_TADAngActSign_Negative
#   define TeTRSC_e_TADAngActSign_Negative (2U)
#  endif

#  ifndef TeTRSC_e_TADAngActSign_SNA
#   define TeTRSC_e_TADAngActSign_SNA (3U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_NotCalibrated
#   define TeTRSC_e_TrlrCalInfo_NotCalibrated (0U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_Calibrated
#   define TeTRSC_e_TrlrCalInfo_Calibrated (1U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_Undefined
#   define TeTRSC_e_TrlrCalInfo_Undefined (2U)
#  endif

#  ifndef TeFA_e_PamChimeRepRateSts_Continuous_0_Hz
#   define TeFA_e_PamChimeRepRateSts_Continuous_0_Hz (0U)
#  endif

#  ifndef TeFA_e_PamChimeRepRateSts_Slow_2_Hz
#   define TeFA_e_PamChimeRepRateSts_Slow_2_Hz (2U)
#  endif

#  ifndef TeFA_e_PamChimeRepRateSts_Slow_3_Hz
#   define TeFA_e_PamChimeRepRateSts_Slow_3_Hz (3U)
#  endif

#  ifndef TeFA_e_PamChimeRepRateSts_Fast_4_Hz
#   define TeFA_e_PamChimeRepRateSts_Fast_4_Hz (4U)
#  endif

#  ifndef TeFA_e_PamChimeRepRateSts_Fast_5_Hz
#   define TeFA_e_PamChimeRepRateSts_Fast_5_Hz (5U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_None
#   define TeFA_e_PamChimeTyp_None (0U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_1
#   define TeFA_e_PamChimeTyp_Type_1 (1U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_2
#   define TeFA_e_PamChimeTyp_Type_2 (2U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_3
#   define TeFA_e_PamChimeTyp_Type_3 (3U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_4
#   define TeFA_e_PamChimeTyp_Type_4 (4U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_5
#   define TeFA_e_PamChimeTyp_Type_5 (5U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_6
#   define TeFA_e_PamChimeTyp_Type_6 (6U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_7
#   define TeFA_e_PamChimeTyp_Type_7 (7U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_8
#   define TeFA_e_PamChimeTyp_Type_8 (8U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_9
#   define TeFA_e_PamChimeTyp_Type_9 (9U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_10
#   define TeFA_e_PamChimeTyp_Type_10 (10U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_11
#   define TeFA_e_PamChimeTyp_Type_11 (11U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_12
#   define TeFA_e_PamChimeTyp_Type_12 (12U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_13
#   define TeFA_e_PamChimeTyp_Type_13 (13U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_14
#   define TeFA_e_PamChimeTyp_Type_14 (14U)
#  endif

#  ifndef TeFA_e_PamChimeTyp_Type_15
#   define TeFA_e_PamChimeTyp_Type_15 (15U)
#  endif

#  ifndef TeFA_e_PamVol_None
#   define TeFA_e_PamVol_None (0U)
#  endif

#  ifndef TeFA_e_PamVol_Low
#   define TeFA_e_PamVol_Low (1U)
#  endif

#  ifndef TeFA_e_PamVol_Medium
#   define TeFA_e_PamVol_Medium (2U)
#  endif

#  ifndef TeFA_e_PamVol_High
#   define TeFA_e_PamVol_High (3U)
#  endif

#  ifndef TeTRSC_e_Completed
#   define TeTRSC_e_Completed (0U)
#  endif

#  ifndef TeTRSC_e_Abort
#   define TeTRSC_e_Abort (1U)
#  endif

#  ifndef SSM_APPSTATE_UNINIT
#   define SSM_APPSTATE_UNINIT (0U)
#  endif

#  ifndef SSM_APPSTATE_INIT
#   define SSM_APPSTATE_INIT (1U)
#  endif

#  ifndef SSM_APPSTATE_RUNNING
#   define SSM_APPSTATE_RUNNING (2U)
#  endif

#  ifndef SSM_APPSTATE_DEGRADED
#   define SSM_APPSTATE_DEGRADED (3U)
#  endif

#  ifndef SSM_APPSTATE_STOPPED
#   define SSM_APPSTATE_STOPPED (4U)
#  endif

#  ifndef SSM_APPSTATE_MAX
#   define SSM_APPSTATE_MAX (5U)
#  endif

#  ifndef SSM_SlaveCore_State_Unknown
#   define SSM_SlaveCore_State_Unknown (0U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Booting
#   define SSM_SlaveCore_State_BSP_Booting (1U)
#  endif

#  ifndef SSM_SlaveCore_State_BSP_Init_Done
#   define SSM_SlaveCore_State_BSP_Init_Done (2U)
#  endif

#  ifndef SSM_SlaveCore_State_Calibrated
#   define SSM_SlaveCore_State_Calibrated (3U)
#  endif

#  ifndef SSM_SlaveCore_State_AppInitialized
#   define SSM_SlaveCore_State_AppInitialized (4U)
#  endif

#  ifndef SSM_SlaveCore_State_Running
#   define SSM_SlaveCore_State_Running (5U)
#  endif

#  ifndef SSM_SlaveCore_State_MAX
#   define SSM_SlaveCore_State_MAX (6U)
#  endif

#  define SVC_Guidelines_adt_LowerLimit (0U)
#  define SVC_Guidelines_adt_UpperLimit (1U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define ShiftLeverPosition_adt_LowerLimit (0U)
#  define ShiftLeverPosition_adt_UpperLimit (15U)

#  define InvalidValue_ShiftLeverPosition (15U)

#  ifndef Cx0_No_Selection_Active_Or_Available
#   define Cx0_No_Selection_Active_Or_Available (0U)
#  endif

#  ifndef Cx1_P
#   define Cx1_P (1U)
#  endif

#  ifndef Cx2_R
#   define Cx2_R (2U)
#  endif

#  ifndef Cx3_N
#   define Cx3_N (3U)
#  endif

#  ifndef Cx4_D
#   define Cx4_D (4U)
#  endif

#  ifndef Cx5_L
#   define Cx5_L (5U)
#  endif

#  ifndef Cx6_TIP_Autostick
#   define Cx6_TIP_Autostick (6U)
#  endif

#  ifndef Cx7_Plus
#   define Cx7_Plus (7U)
#  endif

#  ifndef Cx8_Minus
#   define Cx8_Minus (8U)
#  endif

#  ifndef Cx9_Sport
#   define Cx9_Sport (9U)
#  endif

#  ifndef CxA_Not_Used
#   define CxA_Not_Used (10U)
#  endif

#  ifndef CxB_Not_Used
#   define CxB_Not_Used (11U)
#  endif

#  ifndef CxC_Not_Used
#   define CxC_Not_Used (12U)
#  endif

#  ifndef CxD_Not_Used
#   define CxD_Not_Used (13U)
#  endif

#  ifndef CxE_Not_Used
#   define CxE_Not_Used (14U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define ShiftLeverPositionReq_adt_LowerLimit (0U)
#  define ShiftLeverPositionReq_adt_UpperLimit (15U)

#  define InvalidValue_ShiftLeverPositionReq (15U)

#  ifndef Cx0_No_Selection_Active_Or_Available
#   define Cx0_No_Selection_Active_Or_Available (0U)
#  endif

#  ifndef Cx1_P
#   define Cx1_P (1U)
#  endif

#  ifndef Cx2_R
#   define Cx2_R (2U)
#  endif

#  ifndef Cx3_N
#   define Cx3_N (3U)
#  endif

#  ifndef Cx4_D
#   define Cx4_D (4U)
#  endif

#  ifndef Cx5_L
#   define Cx5_L (5U)
#  endif

#  ifndef Cx6_TIP_Autostick
#   define Cx6_TIP_Autostick (6U)
#  endif

#  ifndef Cx7_Plus
#   define Cx7_Plus (7U)
#  endif

#  ifndef Cx8_Minus
#   define Cx8_Minus (8U)
#  endif

#  ifndef Cx9_Sport
#   define Cx9_Sport (9U)
#  endif

#  ifndef CxA_Not_Used
#   define CxA_Not_Used (10U)
#  endif

#  ifndef CxB_Not_Used
#   define CxB_Not_Used (11U)
#  endif

#  ifndef CxC_Not_Used
#   define CxC_Not_Used (12U)
#  endif

#  ifndef CxD_Not_Used
#   define CxD_Not_Used (13U)
#  endif

#  ifndef CxE_Not_Used
#   define CxE_Not_Used (14U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define Shifter_ADAS_Inhibit_adt_LowerLimit (0U)
#  define Shifter_ADAS_Inhibit_adt_UpperLimit (1U)

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Available
#   define Cx1_Available (1U)
#  endif

#  ifndef SlotSide_E_SLOT_NULL
#   define SlotSide_E_SLOT_NULL (0U)
#  endif

#  ifndef SlotSide_E_SLOT_LEFT
#   define SlotSide_E_SLOT_LEFT (1U)
#  endif

#  ifndef SlotSide_E_SLOT_RIGHT
#   define SlotSide_E_SLOT_RIGHT (2U)
#  endif

#  ifndef DriveStraight
#   define DriveStraight (0U)
#  endif

#  ifndef TurnLeftOrRight
#   define TurnLeftOrRight (1U)
#  endif

#  ifndef Wait
#   define Wait (2U)
#  endif

#  define TCASERANGESTATUS_adt_LowerLimit (0U)
#  define TCASERANGESTATUS_adt_UpperLimit (3U)

#  define InvalidValue_TCASERANGESTATUS (3U)

#  ifndef Cx0_HIGH
#   define Cx0_HIGH (0U)
#  endif

#  ifndef Cx1_NTRL
#   define Cx1_NTRL (1U)
#  endif

#  ifndef Cx2_LOW
#   define Cx2_LOW (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define TGW_CAMERA_DISP_STAT_adt_LowerLimit (0U)
#  define TGW_CAMERA_DISP_STAT_adt_UpperLimit (15U)

#  define InvalidValue_TGW_CAMERA_DISP_STAT (15U)

#  ifndef Cx0_DISP_NON_CAMERA
#   define Cx0_DISP_NON_CAMERA (0U)
#  endif

#  ifndef Cx1_DISP_DIGITAL_RVC_CAMERA
#   define Cx1_DISP_DIGITAL_RVC_CAMERA (1U)
#  endif

#  ifndef Cx2_DISP_ANALOG_RVC_CAMERA
#   define Cx2_DISP_ANALOG_RVC_CAMERA (2U)
#  endif

#  ifndef Cx3_DISP_ANALOG_CHMSL_CAMERA
#   define Cx3_DISP_ANALOG_CHMSL_CAMERA (3U)
#  endif

#  ifndef Cx4_DISP_SURROUND_VIEW_CAMERA
#   define Cx4_DISP_SURROUND_VIEW_CAMERA (4U)
#  endif

#  ifndef Cx5_DISP_TRAILER_CAMERA
#   define Cx5_DISP_TRAILER_CAMERA (5U)
#  endif

#  ifndef Cx6_DISP_WIRLESS_CAMERA
#   define Cx6_DISP_WIRLESS_CAMERA (6U)
#  endif

#  ifndef Cx7_DISP_SVS_MORECAMS_POPUP
#   define Cx7_DISP_SVS_MORECAMS_POPUP (7U)
#  endif

#  ifndef Cx8_DISP_INTERIOR_CAMERA
#   define Cx8_DISP_INTERIOR_CAMERA (8U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  define THA_SteeringTouchStat_adt_LowerLimit (0U)
#  define THA_SteeringTouchStat_adt_UpperLimit (3U)

#  define InvalidValue_THA_SteeringTouchStat (3U)

#  ifndef Cx0_Hands_Off
#   define Cx0_Hands_Off (0U)
#  endif

#  ifndef Cx1_Hands_On
#   define Cx1_Hands_On (1U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define TRANS_ADAS_Inhibit_adt_LowerLimit (0U)
#  define TRANS_ADAS_Inhibit_adt_UpperLimit (1U)

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Available
#   define Cx1_Available (1U)
#  endif

#  define TargetGear_adt_LowerLimit (0U)
#  define TargetGear_adt_UpperLimit (15U)

#  define InvalidValue_TargetGear (15U)

#  ifndef Cx0_Neutral
#   define Cx0_Neutral (0U)
#  endif

#  ifndef Cx1_ForwardGear_1
#   define Cx1_ForwardGear_1 (1U)
#  endif

#  ifndef Cx2_ForwardGear_2
#   define Cx2_ForwardGear_2 (2U)
#  endif

#  ifndef Cx3_ForwardGear_3
#   define Cx3_ForwardGear_3 (3U)
#  endif

#  ifndef Cx4_ForwardGear_4
#   define Cx4_ForwardGear_4 (4U)
#  endif

#  ifndef Cx5_ForwardGear_5
#   define Cx5_ForwardGear_5 (5U)
#  endif

#  ifndef Cx6_ForwardGear_6
#   define Cx6_ForwardGear_6 (6U)
#  endif

#  ifndef Cx7_ForwardGear_7
#   define Cx7_ForwardGear_7 (7U)
#  endif

#  ifndef Cx8_ForwardGear_8
#   define Cx8_ForwardGear_8 (8U)
#  endif

#  ifndef Cx9_ForwardGear_9
#   define Cx9_ForwardGear_9 (9U)
#  endif

#  ifndef CxD_Parking
#   define CxD_Parking (13U)
#  endif

#  ifndef CxE_ReverseGear
#   define CxE_ReverseGear (14U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  ifndef TeAP_e_Alert_NoObjectDetected
#   define TeAP_e_Alert_NoObjectDetected (0U)
#  endif

#  ifndef TeAP_e_Alert_Arc1
#   define TeAP_e_Alert_Arc1 (1U)
#  endif

#  ifndef TeAP_e_Alert_Arc2
#   define TeAP_e_Alert_Arc2 (2U)
#  endif

#  ifndef TeAP_e_Alert_Arc3
#   define TeAP_e_Alert_Arc3 (3U)
#  endif

#  ifndef TeAP_e_Alert_Arc4
#   define TeAP_e_Alert_Arc4 (4U)
#  endif

#  ifndef TeAP_e_Alert_Arc5
#   define TeAP_e_Alert_Arc5 (5U)
#  endif

#  ifndef TeAP_e_Alert_Arc6
#   define TeAP_e_Alert_Arc6 (6U)
#  endif

#  ifndef TeAP_e_Alert_SNA
#   define TeAP_e_Alert_SNA (7U)
#  endif

#  ifndef TeAP_e_AlgoState_Idle
#   define TeAP_e_AlgoState_Idle (0U)
#  endif

#  ifndef TeAP_e_AlgoState_Scanning
#   define TeAP_e_AlgoState_Scanning (1U)
#  endif

#  ifndef TeAP_e_AlgoState_Park_In
#   define TeAP_e_AlgoState_Park_In (2U)
#  endif

#  ifndef TeAP_e_AlgoState_Park_Out
#   define TeAP_e_AlgoState_Park_Out (3U)
#  endif

#  ifndef TeAP_e_DispView2_OFF
#   define TeAP_e_DispView2_OFF (0U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_1
#   define TeAP_e_DispView2_VIEW_1 (1U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_2
#   define TeAP_e_DispView2_VIEW_2 (2U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_3
#   define TeAP_e_DispView2_VIEW_3 (3U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_4
#   define TeAP_e_DispView2_VIEW_4 (4U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_5
#   define TeAP_e_DispView2_VIEW_5 (5U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_6
#   define TeAP_e_DispView2_VIEW_6 (6U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_7
#   define TeAP_e_DispView2_VIEW_7 (7U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_8
#   define TeAP_e_DispView2_VIEW_8 (8U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_9
#   define TeAP_e_DispView2_VIEW_9 (9U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_10
#   define TeAP_e_DispView2_VIEW_10 (10U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_11
#   define TeAP_e_DispView2_VIEW_11 (11U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_12
#   define TeAP_e_DispView2_VIEW_12 (12U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_13
#   define TeAP_e_DispView2_VIEW_13 (13U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_14
#   define TeAP_e_DispView2_VIEW_14 (14U)
#  endif

#  ifndef TeAP_e_DispView2_VIEW_15
#   define TeAP_e_DispView2_VIEW_15 (15U)
#  endif

#  ifndef TeAP_e_FrntSnsrStatus_Active
#   define TeAP_e_FrntSnsrStatus_Active (0U)
#  endif

#  ifndef TeAP_e_FrntSnsrStatus_Not_Active_Blocked
#   define TeAP_e_FrntSnsrStatus_Not_Active_Blocked (1U)
#  endif

#  ifndef TeAP_e_FrntSnsrStatus_Not_Active_Failure
#   define TeAP_e_FrntSnsrStatus_Not_Active_Failure (2U)
#  endif

#  ifndef TeAP_e_FrntSnsrStatus_FrntSnsr_SNA
#   define TeAP_e_FrntSnsrStatus_FrntSnsr_SNA (3U)
#  endif

#  ifndef TeAP_e_GearShiftReq_Idle
#   define TeAP_e_GearShiftReq_Idle (0U)
#  endif

#  ifndef TeAP_e_GearShiftReq_P
#   define TeAP_e_GearShiftReq_P (1U)
#  endif

#  ifndef TeAP_e_GearShiftReq_R
#   define TeAP_e_GearShiftReq_R (2U)
#  endif

#  ifndef TeAP_e_GearShiftReq_N
#   define TeAP_e_GearShiftReq_N (3U)
#  endif

#  ifndef TeAP_e_GearShiftReq_D
#   define TeAP_e_GearShiftReq_D (4U)
#  endif

#  ifndef TeAP_e_GearShiftReq_SNA
#   define TeAP_e_GearShiftReq_SNA (7U)
#  endif

#  ifndef TeAP_e_GraphicFlshRate_Slow_flash
#   define TeAP_e_GraphicFlshRate_Slow_flash (0U)
#  endif

#  ifndef TeAP_e_GraphicFlshRate_Solid
#   define TeAP_e_GraphicFlshRate_Solid (1U)
#  endif

#  ifndef TeAP_e_GraphicFlshRate_None
#   define TeAP_e_GraphicFlshRate_None (2U)
#  endif

#  ifndef TeAP_e_GraphicFlshRate_SNA
#   define TeAP_e_GraphicFlshRate_SNA (3U)
#  endif

#  ifndef TeAP_e_HMIPopUp_IDLE
#   define TeAP_e_HMIPopUp_IDLE (0U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SHIFT_TO_DRIVE
#   define TeAP_e_HMIPopUp_SHIFT_TO_DRIVE (1U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD
#   define TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD (2U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH
#   define TeAP_e_HMIPopUp_SEARCHING_MOVE_FORWARD_SPEED_TOO_HIGH (3U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_STOP
#   define TeAP_e_HMIPopUp_SPACE_FOUND_STOP (4U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL
#   define TeAP_e_HMIPopUp_SPACE_FOUND_STOP_STANDSTILL (5U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH
#   define TeAP_e_HMIPopUp_SPACE_FOUND_SPEED_TOO_HIGH (6U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE
#   define TeAP_e_HMIPopUp_SPACE_FOUND_SELECT_SPACE (7U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_LEFT
#   define TeAP_e_HMIPopUp_PERP_SELECT_LEFT (8U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL
#   define TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD_AVAIL (9U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL
#   define TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE_AVAIL (10U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD
#   define TeAP_e_HMIPopUp_PERP_SELECT_LEFT_FORWARD (11U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE
#   define TeAP_e_HMIPopUp_PERP_SELECT_LEFT_REVERSE (12U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_RIGHT
#   define TeAP_e_HMIPopUp_PERP_SELECT_RIGHT (13U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL
#   define TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD_AVAIL (14U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL
#   define TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE_AVAIL (15U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD
#   define TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_FORWARD (16U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE
#   define TeAP_e_HMIPopUp_PERP_SELECT_RIGHT_REVERSE (17U)
#  endif

#  ifndef TeAP_e_HMIPopUp_DISCLAIMER
#   define TeAP_e_HMIPopUp_DISCLAIMER (18U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT
#   define TeAP_e_HMIPopUp_PARALLEL_EXIT_SELECT (19U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP
#   define TeAP_e_HMIPopUp_PARALLEL_EXIT_STOP (20U)
#  endif

#  ifndef TeAP_e_HMIPopUp_REMOVE_HANDS_FEET
#   define TeAP_e_HMIPopUp_REMOVE_HANDS_FEET (21U)
#  endif

#  ifndef TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT
#   define TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_FRONT (22U)
#  endif

#  ifndef TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR
#   define TeAP_e_HMIPopUp_FULL_AUTO_ACTIVE_REAR (23U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON
#   define TeAP_e_HMIPopUp_PAUSED_PRESS_BUTTON (24U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH
#   define TeAP_e_HMIPopUp_PAUSED_OBJECT_IN_PATH (25U)
#  endif

#  ifndef TeAP_e_HMIPopUp_COMPLETE_PROCEED
#   define TeAP_e_HMIPopUp_COMPLETE_PROCEED (26U)
#  endif

#  ifndef TeAP_e_HMIPopUp_COMPLETE_RELEASE
#   define TeAP_e_HMIPopUp_COMPLETE_RELEASE (27U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT
#   define TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_LEFT (28U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT
#   define TeAP_e_HMIPopUp_SPACE_FOUND_REMOVE_HANDS_RIGHT (29U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT
#   define TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_LEFT (30U)
#  endif

#  ifndef TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT
#   define TeAP_e_HMIPopUp_PARALLEL_EXIT_REMOVE_HANDS_RIGHT (31U)
#  endif

#  ifndef TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT
#   define TeAP_e_HMIPopUp_WAIT_FOR_STEER_FRONT (32U)
#  endif

#  ifndef TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR
#   define TeAP_e_HMIPopUp_WAIT_FOR_STEER_REAR (33U)
#  endif

#  ifndef TeAP_e_HMIPopUp_MOVE_BACKWARD
#   define TeAP_e_HMIPopUp_MOVE_BACKWARD (34U)
#  endif

#  ifndef TeAP_e_HMIPopUp_STOP_FRONT
#   define TeAP_e_HMIPopUp_STOP_FRONT (35U)
#  endif

#  ifndef TeAP_e_HMIPopUp_STOP_REAR
#   define TeAP_e_HMIPopUp_STOP_REAR (36U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE
#   define TeAP_e_HMIPopUp_SHIFT_TO_DRIVE_GUIDANCE (37U)
#  endif

#  ifndef TeAP_e_HMIPopUp_MOVE_FORWARD
#   define TeAP_e_HMIPopUp_MOVE_FORWARD (38U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SHIFT_TO_REVERSE
#   define TeAP_e_HMIPopUp_SHIFT_TO_REVERSE (39U)
#  endif

#  ifndef TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT
#   define TeAP_e_HMIPopUp_COMPLETE_HMI_FRONT (40U)
#  endif

#  ifndef TeAP_e_HMIPopUp_COMPLETE_HMI_REAR
#   define TeAP_e_HMIPopUp_COMPLETE_HMI_REAR (41U)
#  endif

#  ifndef TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN
#   define TeAP_e_HMIPopUp_DOOR_OPEN_FULLSCREEN (42U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN
#   define TeAP_e_HMIPopUp_LIFEGATE_OPEN_FULLSCREEN (43U)
#  endif

#  ifndef TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN
#   define TeAP_e_HMIPopUp_ESC_ACTIVE_FULLSCREEN (44U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN
#   define TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FULLSCREEN (45U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN
#   define TeAP_e_HMIPopUp_LO4_ACTIVE_FULLSCREEN (46U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN
#   define TeAP_e_HMIPopUp_TRAILER_CONNECTED_FULLSCREEN (47U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN
#   define TeAP_e_HMIPopUp_SERVICE_REQUIRED_FULLSCREEN (48U)
#  endif

#  ifndef TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN
#   define TeAP_e_HMIPopUp_FRONT_WIPE_FULLSCREEN (49U)
#  endif

#  ifndef TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN
#   define TeAP_e_HMIPopUp_REAR_WIPE_FULLSCREEN (50U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN
#   define TeAP_e_HMIPopUp_TEMP_NA_FULLSCREEN (51U)
#  endif

#  ifndef TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN
#   define TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_FULLSCREEN (52U)
#  endif

#  ifndef TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN
#   define TeAP_e_HMIPopUp_BUTTON_PRESS_FULLSCREEN (53U)
#  endif

#  ifndef TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY
#   define TeAP_e_HMIPopUp_DOOR_OPEN_OVERLAY (54U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY
#   define TeAP_e_HMIPopUp_LIFTGATE_OPEN_OVERLAY (55U)
#  endif

#  ifndef TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY
#   define TeAP_e_HMIPopUp_ESC_ACTIVE_OVERLAY (56U)
#  endif

#  ifndef TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL
#   define TeAP_e_HMIPopUp_BUTTON_PRESS_TAKECONTROL (57U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY
#   define TeAP_e_HMIPopUp_LO4_ACTIVE_OVERLAY (58U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY
#   define TeAP_e_HMIPopUp_TRAILER_CONNECTED_OVERLAY (59U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY
#   define TeAP_e_HMIPopUp_SERVICE_REQUIRED_OVERLAY (60U)
#  endif

#  ifndef TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY
#   define TeAP_e_HMIPopUp_FRONT_WIPE_OVERLAY (61U)
#  endif

#  ifndef TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY
#   define TeAP_e_HMIPopUp_REAR_WIPE_OVERLAY (62U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TEMP_NA_OVERLAY
#   define TeAP_e_HMIPopUp_TEMP_NA_OVERLAY (63U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR
#   define TeAP_e_HMIPopUp_SPEED_TOO_HIGH_REAR (64U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT
#   define TeAP_e_HMIPopUp_SPEED_TOO_HIGH_FRONT (65U)
#  endif

#  ifndef TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY
#   define TeAP_e_HMIPopUp_UNAVAIL_SPEED_TOO_HIGH_OVERLAY (66U)
#  endif

#  ifndef TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL
#   define TeAP_e_HMIPopUp_CRUISE_CONTROL_ENGAGED_TAKECONTROL (67U)
#  endif

#  ifndef TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL
#   define TeAP_e_HMIPopUp_DOOR_OPEN_TAKECONTROL (68U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL
#   define TeAP_e_HMIPopUp_LIFTGATE_OPEN_TAKECONTROL (69U)
#  endif

#  ifndef TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL
#   define TeAP_e_HMIPopUp_ESC_ACTIVE_TAKECONTROL (70U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL
#   define TeAP_e_HMIPopUp_SPEED_TOO_HIGH_TAKECONTROL (71U)
#  endif

#  ifndef TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL
#   define TeAP_e_HMIPopUp_LO4_ACTIVE_TAKECONTROL (72U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL
#   define TeAP_e_HMIPopUp_TRAILER_CONNECTED_TAKECONTROL (73U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL
#   define TeAP_e_HMIPopUp_SERVICE_REQUIRED_TAKECONTROL (74U)
#  endif

#  ifndef TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL
#   define TeAP_e_HMIPopUp_FRONT_WIPE_TAKECONTROL (75U)
#  endif

#  ifndef TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL
#   define TeAP_e_HMIPopUp_REAR_WIPE_TAKECONTROL (76U)
#  endif

#  ifndef TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL
#   define TeAP_e_HMIPopUp_TEMP_NA_TAKECONTROL (77U)
#  endif

#  ifndef TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL
#   define TeAP_e_HMIPopUp_WHEEL_TOUCHED_TAKECONTROL (78U)
#  endif

#  ifndef TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL
#   define TeAP_e_HMIPopUp_DRIVER_OVERRIDE_TAKECONTROL (79U)
#  endif

#  ifndef TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL
#   define TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL (80U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT
#   define TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT (81U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT
#   define TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT (82U)
#  endif

#  ifndef TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL
#   define TeAP_e_HMIPopUp_MANUAL_PARK_TAKECONTROL (80U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT
#   define TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_LEFT (81U)
#  endif

#  ifndef TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT
#   define TeAP_e_HMIPopUp_SEMI_PARALLEL_REMOVE_HANDS_RIGHT (82U)
#  endif

#  ifndef TeAP_e_InterfaceBSM_Idle
#   define TeAP_e_InterfaceBSM_Idle (0U)
#  endif

#  ifndef TeAP_e_InterfaceBSM_CVPAM_Request
#   define TeAP_e_InterfaceBSM_CVPAM_Request (1U)
#  endif

#  ifndef TeAP_e_InterfaceBSM_Faulted
#   define TeAP_e_InterfaceBSM_Faulted (2U)
#  endif

#  ifndef TeAP_e_InterfaceBSM_IntrBsm_SNA
#   define TeAP_e_InterfaceBSM_IntrBsm_SNA (3U)
#  endif

#  ifndef TeAP_e_PAMChimeRepnRate_Continuous_0Hz
#   define TeAP_e_PAMChimeRepnRate_Continuous_0Hz (0U)
#  endif

#  ifndef TeAP_e_PAMChimeRepnRate_Slow_2Hz
#   define TeAP_e_PAMChimeRepnRate_Slow_2Hz (2U)
#  endif

#  ifndef TeAP_e_PAMChimeRepnRate_Slow_3Hz
#   define TeAP_e_PAMChimeRepnRate_Slow_3Hz (3U)
#  endif

#  ifndef TeAP_e_PAMChimeRepnRate_Fast_4Hz
#   define TeAP_e_PAMChimeRepnRate_Fast_4Hz (4U)
#  endif

#  ifndef TeAP_e_PAMChimeRepnRate_Fast_5Hz
#   define TeAP_e_PAMChimeRepnRate_Fast_5Hz (5U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_None
#   define TeAP_e_PAMChimeTyp_None (0U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type1
#   define TeAP_e_PAMChimeTyp_Type1 (1U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type2
#   define TeAP_e_PAMChimeTyp_Type2 (2U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type3
#   define TeAP_e_PAMChimeTyp_Type3 (3U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type4
#   define TeAP_e_PAMChimeTyp_Type4 (4U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type5
#   define TeAP_e_PAMChimeTyp_Type5 (5U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type6
#   define TeAP_e_PAMChimeTyp_Type6 (6U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type7
#   define TeAP_e_PAMChimeTyp_Type7 (7U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type8
#   define TeAP_e_PAMChimeTyp_Type8 (8U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type9
#   define TeAP_e_PAMChimeTyp_Type9 (9U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type10
#   define TeAP_e_PAMChimeTyp_Type10 (10U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type11
#   define TeAP_e_PAMChimeTyp_Type11 (11U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type12
#   define TeAP_e_PAMChimeTyp_Type12 (12U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type13
#   define TeAP_e_PAMChimeTyp_Type13 (13U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type14
#   define TeAP_e_PAMChimeTyp_Type14 (14U)
#  endif

#  ifndef TeAP_e_PAMChimeTyp_Type15
#   define TeAP_e_PAMChimeTyp_Type15 (15U)
#  endif

#  ifndef TeAP_e_PAMLedCtrlStatus_Off
#   define TeAP_e_PAMLedCtrlStatus_Off (0U)
#  endif

#  ifndef TeAP_e_PAMLedCtrlStatus_ContinousLight
#   define TeAP_e_PAMLedCtrlStatus_ContinousLight (1U)
#  endif

#  ifndef TeAP_e_PAMLedCtrlStatus_BlinkingLight
#   define TeAP_e_PAMLedCtrlStatus_BlinkingLight (2U)
#  endif

#  ifndef TeAP_e_PAMLedCtrlStatus_SNA
#   define TeAP_e_PAMLedCtrlStatus_SNA (3U)
#  endif

#  ifndef TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF
#   define TeAP_e_PAMOffStatus2BT_FT_OFF_RR_OFF (0U)
#  endif

#  ifndef TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON
#   define TeAP_e_PAMOffStatus2BT_FT_OFF_RR_ON (1U)
#  endif

#  ifndef TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF
#   define TeAP_e_PAMOffStatus2BT_FT_ON_RR_OFF (2U)
#  endif

#  ifndef TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON
#   define TeAP_e_PAMOffStatus2BT_FT_ON_RR_ON (3U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM0
#   define TeAP_e_PAMPopUpReq_TM0 (0U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM1
#   define TeAP_e_PAMPopUpReq_TM1 (1U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM2
#   define TeAP_e_PAMPopUpReq_TM2 (2U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM3
#   define TeAP_e_PAMPopUpReq_TM3 (3U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM4
#   define TeAP_e_PAMPopUpReq_TM4 (4U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM5
#   define TeAP_e_PAMPopUpReq_TM5 (5U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM6
#   define TeAP_e_PAMPopUpReq_TM6 (6U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM7
#   define TeAP_e_PAMPopUpReq_TM7 (7U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM8
#   define TeAP_e_PAMPopUpReq_TM8 (8U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM9
#   define TeAP_e_PAMPopUpReq_TM9 (9U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM10
#   define TeAP_e_PAMPopUpReq_TM10 (10U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM11
#   define TeAP_e_PAMPopUpReq_TM11 (11U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM12
#   define TeAP_e_PAMPopUpReq_TM12 (12U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM13
#   define TeAP_e_PAMPopUpReq_TM13 (13U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM14
#   define TeAP_e_PAMPopUpReq_TM14 (14U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM15
#   define TeAP_e_PAMPopUpReq_TM15 (15U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM16
#   define TeAP_e_PAMPopUpReq_TM16 (16U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM17
#   define TeAP_e_PAMPopUpReq_TM17 (17U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM18
#   define TeAP_e_PAMPopUpReq_TM18 (18U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM19
#   define TeAP_e_PAMPopUpReq_TM19 (19U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM20
#   define TeAP_e_PAMPopUpReq_TM20 (20U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM21
#   define TeAP_e_PAMPopUpReq_TM21 (21U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM22
#   define TeAP_e_PAMPopUpReq_TM22 (22U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM23
#   define TeAP_e_PAMPopUpReq_TM23 (23U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM24
#   define TeAP_e_PAMPopUpReq_TM24 (24U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM25
#   define TeAP_e_PAMPopUpReq_TM25 (25U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM26
#   define TeAP_e_PAMPopUpReq_TM26 (26U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM27
#   define TeAP_e_PAMPopUpReq_TM27 (27U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM28
#   define TeAP_e_PAMPopUpReq_TM28 (28U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM29
#   define TeAP_e_PAMPopUpReq_TM29 (29U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM30
#   define TeAP_e_PAMPopUpReq_TM30 (30U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM31
#   define TeAP_e_PAMPopUpReq_TM31 (31U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM32
#   define TeAP_e_PAMPopUpReq_TM32 (32U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM33
#   define TeAP_e_PAMPopUpReq_TM33 (33U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM34
#   define TeAP_e_PAMPopUpReq_TM34 (34U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM35
#   define TeAP_e_PAMPopUpReq_TM35 (35U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM36
#   define TeAP_e_PAMPopUpReq_TM36 (36U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM37
#   define TeAP_e_PAMPopUpReq_TM37 (37U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM38
#   define TeAP_e_PAMPopUpReq_TM38 (38U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM39
#   define TeAP_e_PAMPopUpReq_TM39 (39U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM40
#   define TeAP_e_PAMPopUpReq_TM40 (40U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM41
#   define TeAP_e_PAMPopUpReq_TM41 (41U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM42
#   define TeAP_e_PAMPopUpReq_TM42 (42U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM43
#   define TeAP_e_PAMPopUpReq_TM43 (43U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM44
#   define TeAP_e_PAMPopUpReq_TM44 (44U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM45
#   define TeAP_e_PAMPopUpReq_TM45 (45U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM46
#   define TeAP_e_PAMPopUpReq_TM46 (46U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM47
#   define TeAP_e_PAMPopUpReq_TM47 (47U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM48
#   define TeAP_e_PAMPopUpReq_TM48 (48U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM49
#   define TeAP_e_PAMPopUpReq_TM49 (49U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM50
#   define TeAP_e_PAMPopUpReq_TM50 (50U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM51
#   define TeAP_e_PAMPopUpReq_TM51 (51U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM52
#   define TeAP_e_PAMPopUpReq_TM52 (52U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM53
#   define TeAP_e_PAMPopUpReq_TM53 (53U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM54
#   define TeAP_e_PAMPopUpReq_TM54 (54U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM55
#   define TeAP_e_PAMPopUpReq_TM55 (55U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM56
#   define TeAP_e_PAMPopUpReq_TM56 (56U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM57
#   define TeAP_e_PAMPopUpReq_TM57 (57U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM58
#   define TeAP_e_PAMPopUpReq_TM58 (58U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM59
#   define TeAP_e_PAMPopUpReq_TM59 (59U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM60
#   define TeAP_e_PAMPopUpReq_TM60 (60U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM61
#   define TeAP_e_PAMPopUpReq_TM61 (61U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM62
#   define TeAP_e_PAMPopUpReq_TM62 (62U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM63
#   define TeAP_e_PAMPopUpReq_TM63 (63U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM64
#   define TeAP_e_PAMPopUpReq_TM64 (64U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM65
#   define TeAP_e_PAMPopUpReq_TM65 (65U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM66
#   define TeAP_e_PAMPopUpReq_TM66 (66U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM67
#   define TeAP_e_PAMPopUpReq_TM67 (67U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM68
#   define TeAP_e_PAMPopUpReq_TM68 (68U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM69
#   define TeAP_e_PAMPopUpReq_TM69 (69U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM70
#   define TeAP_e_PAMPopUpReq_TM70 (70U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM71
#   define TeAP_e_PAMPopUpReq_TM71 (71U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM72
#   define TeAP_e_PAMPopUpReq_TM72 (72U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM73
#   define TeAP_e_PAMPopUpReq_TM73 (73U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM74
#   define TeAP_e_PAMPopUpReq_TM74 (74U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM75
#   define TeAP_e_PAMPopUpReq_TM75 (75U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM76
#   define TeAP_e_PAMPopUpReq_TM76 (76U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM77
#   define TeAP_e_PAMPopUpReq_TM77 (77U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM78
#   define TeAP_e_PAMPopUpReq_TM78 (78U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM79
#   define TeAP_e_PAMPopUpReq_TM79 (79U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM80
#   define TeAP_e_PAMPopUpReq_TM80 (80U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM81
#   define TeAP_e_PAMPopUpReq_TM81 (81U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM82
#   define TeAP_e_PAMPopUpReq_TM82 (82U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM83
#   define TeAP_e_PAMPopUpReq_TM83 (83U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM84
#   define TeAP_e_PAMPopUpReq_TM84 (84U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM85
#   define TeAP_e_PAMPopUpReq_TM85 (85U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM86
#   define TeAP_e_PAMPopUpReq_TM86 (86U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM87
#   define TeAP_e_PAMPopUpReq_TM87 (87U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM88
#   define TeAP_e_PAMPopUpReq_TM88 (88U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM89
#   define TeAP_e_PAMPopUpReq_TM89 (89U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM90
#   define TeAP_e_PAMPopUpReq_TM90 (90U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM91
#   define TeAP_e_PAMPopUpReq_TM91 (91U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM92
#   define TeAP_e_PAMPopUpReq_TM92 (92U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM93
#   define TeAP_e_PAMPopUpReq_TM93 (93U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM94
#   define TeAP_e_PAMPopUpReq_TM94 (94U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM95
#   define TeAP_e_PAMPopUpReq_TM95 (95U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM96
#   define TeAP_e_PAMPopUpReq_TM96 (96U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM97
#   define TeAP_e_PAMPopUpReq_TM97 (97U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM98
#   define TeAP_e_PAMPopUpReq_TM98 (98U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM99
#   define TeAP_e_PAMPopUpReq_TM99 (99U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_TM100
#   define TeAP_e_PAMPopUpReq_TM100 (100U)
#  endif

#  ifndef TeAP_e_PAMPopUpReq_SNA
#   define TeAP_e_PAMPopUpReq_SNA (255U)
#  endif

#  ifndef TeAP_e_PAMSystemFault_False
#   define TeAP_e_PAMSystemFault_False (0U)
#  endif

#  ifndef TeAP_e_PAMSystemFault_Temporary_Failure
#   define TeAP_e_PAMSystemFault_Temporary_Failure (1U)
#  endif

#  ifndef TeAP_e_PAMSystemFault_External_Failure
#   define TeAP_e_PAMSystemFault_External_Failure (2U)
#  endif

#  ifndef TeAP_e_PAMSystemFault_System_Failure
#   define TeAP_e_PAMSystemFault_System_Failure (3U)
#  endif

#  ifndef TeAP_e_PAMVolSig_None
#   define TeAP_e_PAMVolSig_None (0U)
#  endif

#  ifndef TeAP_e_PAMVolSig_Low
#   define TeAP_e_PAMVolSig_Low (1U)
#  endif

#  ifndef TeAP_e_PAMVolSig_Medium
#   define TeAP_e_PAMVolSig_Medium (2U)
#  endif

#  ifndef TeAP_e_PAMVolSig_High
#   define TeAP_e_PAMVolSig_High (3U)
#  endif

#  ifndef TeAP_e_PAMVolSig_MAX
#   define TeAP_e_PAMVolSig_MAX (4U)
#  endif

#  ifndef TeAP_e_PAMVolume_Non
#   define TeAP_e_PAMVolume_Non (0U)
#  endif

#  ifndef TeAP_e_PAMVolume_Low
#   define TeAP_e_PAMVolume_Low (1U)
#  endif

#  ifndef TeAP_e_PAMVolume_Medium
#   define TeAP_e_PAMVolume_Medium (2U)
#  endif

#  ifndef TeAP_e_PAMVolume_High
#   define TeAP_e_PAMVolume_High (3U)
#  endif

#  ifndef TeAP_e_ParKMnvrActv_Idle
#   define TeAP_e_ParKMnvrActv_Idle (0U)
#  endif

#  ifndef TeAP_e_ParKMnvrActv_Enabled_Seeking
#   define TeAP_e_ParKMnvrActv_Enabled_Seeking (1U)
#  endif

#  ifndef TeAP_e_ParKMnvrActv_Engaged_Semi
#   define TeAP_e_ParKMnvrActv_Engaged_Semi (2U)
#  endif

#  ifndef TeAP_e_ParKMnvrActv_Engaged_Full
#   define TeAP_e_ParKMnvrActv_Engaged_Full (3U)
#  endif

#  ifndef TeAP_e_ParKMnvrActv_ParkMnvr_SNA
#   define TeAP_e_ParKMnvrActv_ParkMnvr_SNA (4U)
#  endif

#  ifndef TeAP_e_ParkAssistStatus_Off
#   define TeAP_e_ParkAssistStatus_Off (0U)
#  endif

#  ifndef TeAP_e_ParkAssistStatus_Initialize
#   define TeAP_e_ParkAssistStatus_Initialize (1U)
#  endif

#  ifndef TeAP_e_ParkAssistStatus_Standby
#   define TeAP_e_ParkAssistStatus_Standby (2U)
#  endif

#  ifndef TeAP_e_ParkAssistStatus_Active
#   define TeAP_e_ParkAssistStatus_Active (3U)
#  endif

#  ifndef TeAP_e_ParkAssistStatus_Sensor_Fault
#   define TeAP_e_ParkAssistStatus_Sensor_Fault (4U)
#  endif

#  ifndef TeAP_e_RearSnsrStatus_Active
#   define TeAP_e_RearSnsrStatus_Active (0U)
#  endif

#  ifndef TeAP_e_RearSnsrStatus_Not_Active_Blocked
#   define TeAP_e_RearSnsrStatus_Not_Active_Blocked (1U)
#  endif

#  ifndef TeAP_e_RearSnsrStatus_Not_Active_Failure
#   define TeAP_e_RearSnsrStatus_Not_Active_Failure (2U)
#  endif

#  ifndef TeAP_e_RearSnsrStatus_RearSnsr_SNA
#   define TeAP_e_RearSnsrStatus_RearSnsr_SNA (3U)
#  endif

#  ifndef Not_Active
#   define Not_Active (0U)
#  endif

#  ifndef Active_ParallelParking
#   define Active_ParallelParking (1U)
#  endif

#  ifndef Active_PerpendicularParking
#   define Active_PerpendicularParking (2U)
#  endif

#  ifndef Active_OutParking
#   define Active_OutParking (3U)
#  endif

#  ifndef TeAP_e_SPMLatCtrlReqSts_Idle
#   define TeAP_e_SPMLatCtrlReqSts_Idle (0U)
#  endif

#  ifndef TeAP_e_SPMLatCtrlReqSts_Faulted
#   define TeAP_e_SPMLatCtrlReqSts_Faulted (1U)
#  endif

#  ifndef TeAP_e_SPMLatCtrlReqSts_SpmLat_SNA
#   define TeAP_e_SPMLatCtrlReqSts_SpmLat_SNA (2U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Off
#   define TeAutoPark_e_AutoParkStatus_Off (0U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Initialize
#   define TeAutoPark_e_AutoParkStatus_Initialize (1U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Standby
#   define TeAutoPark_e_AutoParkStatus_Standby (2U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Active
#   define TeAutoPark_e_AutoParkStatus_Active (3U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Fault
#   define TeAutoPark_e_AutoParkStatus_Fault (4U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Abort
#   define TeAutoPark_e_AutoParkStatus_Abort (5U)
#  endif

#  ifndef TeAutoPark_e_AutoParkStatus_Complete
#   define TeAutoPark_e_AutoParkStatus_Complete (6U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_No_chime
#   define TeAutoPark_e_ChimeReq_No_chime (0U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Engagement_chime
#   define TeAutoPark_e_ChimeReq_Engagement_chime (1U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Disengagement_chime
#   define TeAutoPark_e_ChimeReq_Disengagement_chime (2U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Fault_chime
#   define TeAutoPark_e_ChimeReq_Fault_chime (3U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Amber
#   define TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Amber (4U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Yellow
#   define TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Yellow (5U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Red
#   define TeAutoPark_e_ChimeReq_Chime_for_Warning_Light_Red (6U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Reserved
#   define TeAutoPark_e_ChimeReq_Reserved (7U)
#  endif

#  ifndef TeAutoPark_e_ChimeReq_Reserved_1
#   define TeAutoPark_e_ChimeReq_Reserved_1 (8U)
#  endif

#  ifndef TeAutoPark_e_GearCmd_None
#   define TeAutoPark_e_GearCmd_None (0U)
#  endif

#  ifndef TeAutoPark_e_GearCmd_Park
#   define TeAutoPark_e_GearCmd_Park (1U)
#  endif

#  ifndef TeAutoPark_e_GearCmd_Reverse
#   define TeAutoPark_e_GearCmd_Reverse (2U)
#  endif

#  ifndef TeAutoPark_e_GearCmd_Neutral
#   define TeAutoPark_e_GearCmd_Neutral (3U)
#  endif

#  ifndef TeAutoPark_e_GearCmd_Drive
#   define TeAutoPark_e_GearCmd_Drive (4U)
#  endif

#  ifndef TeAutoPark_e_ScanDir_Not_scanning
#   define TeAutoPark_e_ScanDir_Not_scanning (0U)
#  endif

#  ifndef TeAutoPark_e_ScanDir_Left
#   define TeAutoPark_e_ScanDir_Left (1U)
#  endif

#  ifndef TeAutoPark_e_ScanDir_Right
#   define TeAutoPark_e_ScanDir_Right (2U)
#  endif

#  ifndef TeAutoPark_e_ScanDir_Both
#   define TeAutoPark_e_ScanDir_Both (3U)
#  endif

#  ifndef NFCD_OFF
#   define NFCD_OFF (0U)
#  endif

#  ifndef NFCD_INIT
#   define NFCD_INIT (1U)
#  endif

#  ifndef NFCD_STANDBY
#   define NFCD_STANDBY (2U)
#  endif

#  ifndef NFCD_ACTIVE
#   define NFCD_ACTIVE (3U)
#  endif

#  ifndef NFCD_FAULT
#   define NFCD_FAULT (4U)
#  endif

#  ifndef OBJ_INVALID
#   define OBJ_INVALID (-1U)
#  endif

#  ifndef OBJ_PEDESTRIAN
#   define OBJ_PEDESTRIAN (0U)
#  endif

#  ifndef OBJ_CAR
#   define OBJ_CAR (1U)
#  endif

#  ifndef OBJ_TRUCK
#   define OBJ_TRUCK (2U)
#  endif

#  ifndef OBJ_BUS
#   define OBJ_BUS (3U)
#  endif

#  ifndef OBJ_MOTORCYCLE
#   define OBJ_MOTORCYCLE (4U)
#  endif

#  ifndef OBJ_BICYCLE
#   define OBJ_BICYCLE (5U)
#  endif

#  ifndef OBJ_RIDER
#   define OBJ_RIDER (6U)
#  endif

#  ifndef OBJ_THREE_WHEELER
#   define OBJ_THREE_WHEELER (7U)
#  endif

#  ifndef OBJ_GARBAGE_BIN
#   define OBJ_GARBAGE_BIN (8U)
#  endif

#  ifndef OBJ_POLE
#   define OBJ_POLE (9U)
#  endif

#  ifndef OBJ_ISO_POLE
#   define OBJ_ISO_POLE (10U)
#  endif

#  ifndef OBJ_TRAFFIC_CONE
#   define OBJ_TRAFFIC_CONE (11U)
#  endif

#  ifndef OBJ_TRAFFIC_BARREL
#   define OBJ_TRAFFIC_BARREL (12U)
#  endif

#  ifndef OBJ_SHOPPING_CART
#   define OBJ_SHOPPING_CART (13U)
#  endif

#  ifndef OBJ_STROLLER
#   define OBJ_STROLLER (14U)
#  endif

#  ifndef OBJ_FENCE_POST
#   define OBJ_FENCE_POST (15U)
#  endif

#  ifndef OBJ_FIRE_HYDRANT
#   define OBJ_FIRE_HYDRANT (16U)
#  endif

#  ifndef OBJ_GENERAL_OBJECT
#   define OBJ_GENERAL_OBJECT (17U)
#  endif

#  ifndef TeTHA_e_EPBReq_No_Request
#   define TeTHA_e_EPBReq_No_Request (0U)
#  endif

#  ifndef TeTHA_e_EPBReq_EPB_Requested
#   define TeTHA_e_EPBReq_EPB_Requested (1U)
#  endif

#  ifndef TeTHA_e_EPBReq_SNA
#   define TeTHA_e_EPBReq_SNA (3U)
#  endif

#  ifndef TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz
#   define TeTHA_e_PamChimeRepRateSts_Continuous_0_Hz (0U)
#  endif

#  ifndef TeTHA_e_PamChimeRepRateSts_Slow_2_Hz
#   define TeTHA_e_PamChimeRepRateSts_Slow_2_Hz (2U)
#  endif

#  ifndef TeTHA_e_PamChimeRepRateSts_Slow_3_Hz
#   define TeTHA_e_PamChimeRepRateSts_Slow_3_Hz (3U)
#  endif

#  ifndef TeTHA_e_PamChimeRepRateSts_Fast_4_Hz
#   define TeTHA_e_PamChimeRepRateSts_Fast_4_Hz (4U)
#  endif

#  ifndef TeTHA_e_PamChimeRepRateSts_Fast_5_Hz
#   define TeTHA_e_PamChimeRepRateSts_Fast_5_Hz (5U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_None
#   define TeTHA_e_PamChimeTyp_None (0U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_1
#   define TeTHA_e_PamChimeTyp_Type_1 (1U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_2
#   define TeTHA_e_PamChimeTyp_Type_2 (2U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_3
#   define TeTHA_e_PamChimeTyp_Type_3 (3U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_4
#   define TeTHA_e_PamChimeTyp_Type_4 (4U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_5
#   define TeTHA_e_PamChimeTyp_Type_5 (5U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_6
#   define TeTHA_e_PamChimeTyp_Type_6 (6U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_7
#   define TeTHA_e_PamChimeTyp_Type_7 (7U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_8
#   define TeTHA_e_PamChimeTyp_Type_8 (8U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_9
#   define TeTHA_e_PamChimeTyp_Type_9 (9U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_10
#   define TeTHA_e_PamChimeTyp_Type_10 (10U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_11
#   define TeTHA_e_PamChimeTyp_Type_11 (11U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_12
#   define TeTHA_e_PamChimeTyp_Type_12 (12U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_13
#   define TeTHA_e_PamChimeTyp_Type_13 (13U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_14
#   define TeTHA_e_PamChimeTyp_Type_14 (14U)
#  endif

#  ifndef TeTHA_e_PamChimeTyp_Type_15
#   define TeTHA_e_PamChimeTyp_Type_15 (15U)
#  endif

#  ifndef TeTHA_e_PamVol_None
#   define TeTHA_e_PamVol_None (0U)
#  endif

#  ifndef TeTHA_e_PamVol_Low
#   define TeTHA_e_PamVol_Low (1U)
#  endif

#  ifndef TeTHA_e_PamVol_Medium
#   define TeTHA_e_PamVol_Medium (2U)
#  endif

#  ifndef TeTHA_e_PamVol_High
#   define TeTHA_e_PamVol_High (3U)
#  endif

#  ifndef TeTHA_e_RearBrkSupprInfo_Invalid
#   define TeTHA_e_RearBrkSupprInfo_Invalid (0U)
#  endif

#  ifndef TeTHA_e_RearBrkSupprInfo_No_Suppression
#   define TeTHA_e_RearBrkSupprInfo_No_Suppression (1U)
#  endif

#  ifndef TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking
#   define TeTHA_e_RearBrkSupprInfo_Suppress_Rear_Braking (2U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_Default
#   define TeTHA_e_ScreenRequest_THA_Default (0U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_Enable
#   define TeTHA_e_ScreenRequest_THA_Enable (1U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_TCS_Msg1
#   define TeTHA_e_ScreenRequest_THA_TCS_Msg1 (2U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_TCS_Msg2
#   define TeTHA_e_ScreenRequest_THA_TCS_Msg2 (3U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_TCS_Msg3
#   define TeTHA_e_ScreenRequest_THA_TCS_Msg3 (4U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_TCS_Msg4
#   define TeTHA_e_ScreenRequest_THA_TCS_Msg4 (5U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_TCS_Msg5
#   define TeTHA_e_ScreenRequest_THA_TCS_Msg5 (6U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_SM_Msg1
#   define TeTHA_e_ScreenRequest_THA_SM_Msg1 (7U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_SM_Msg2
#   define TeTHA_e_ScreenRequest_THA_SM_Msg2 (8U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg1
#   define TeTHA_e_ScreenRequest_THA_CM_Msg1 (9U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg2
#   define TeTHA_e_ScreenRequest_THA_CM_Msg2 (10U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg3
#   define TeTHA_e_ScreenRequest_THA_CM_Msg3 (11U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg4
#   define TeTHA_e_ScreenRequest_THA_CM_Msg4 (12U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg5
#   define TeTHA_e_ScreenRequest_THA_CM_Msg5 (13U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg6
#   define TeTHA_e_ScreenRequest_THA_CM_Msg6 (14U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg7
#   define TeTHA_e_ScreenRequest_THA_CM_Msg7 (15U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg8
#   define TeTHA_e_ScreenRequest_THA_CM_Msg8 (16U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg9
#   define TeTHA_e_ScreenRequest_THA_CM_Msg9 (17U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_CM_Msg10
#   define TeTHA_e_ScreenRequest_THA_CM_Msg10 (18U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_EOM_Msg1
#   define TeTHA_e_ScreenRequest_THA_EOM_Msg1 (19U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_EOM_Msg2
#   define TeTHA_e_ScreenRequest_THA_EOM_Msg2 (20U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_EOM_Msg3
#   define TeTHA_e_ScreenRequest_THA_EOM_Msg3 (21U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_EOM_Msg4
#   define TeTHA_e_ScreenRequest_THA_EOM_Msg4 (22U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_ERR_Msg1
#   define TeTHA_e_ScreenRequest_THA_ERR_Msg1 (23U)
#  endif

#  ifndef TeTHA_e_ScreenRequest_THA_ERR_Msg2
#   define TeTHA_e_ScreenRequest_THA_ERR_Msg2 (24U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_No_Request
#   define TeTHA_e_THARmpUpDwnSpd_No_Request (0U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_1
#   define TeTHA_e_THARmpUpDwnSpd_Kph_1 (1U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_2
#   define TeTHA_e_THARmpUpDwnSpd_Kph_2 (2U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_3
#   define TeTHA_e_THARmpUpDwnSpd_Kph_3 (3U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_4
#   define TeTHA_e_THARmpUpDwnSpd_Kph_4 (4U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_5
#   define TeTHA_e_THARmpUpDwnSpd_Kph_5 (5U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_6
#   define TeTHA_e_THARmpUpDwnSpd_Kph_6 (6U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_7
#   define TeTHA_e_THARmpUpDwnSpd_Kph_7 (7U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_8
#   define TeTHA_e_THARmpUpDwnSpd_Kph_8 (8U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_9
#   define TeTHA_e_THARmpUpDwnSpd_Kph_9 (9U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_Kph_10
#   define TeTHA_e_THARmpUpDwnSpd_Kph_10 (10U)
#  endif

#  ifndef TeTHA_e_THARmpUpDwnSpd_SNA
#   define TeTHA_e_THARmpUpDwnSpd_SNA (31U)
#  endif

#  ifndef TeTHA_e_THASpdLimReq_No_Request
#   define TeTHA_e_THASpdLimReq_No_Request (0U)
#  endif

#  ifndef TeTHA_e_THASpdLimReq_Requested
#   define TeTHA_e_THASpdLimReq_Requested (1U)
#  endif

#  ifndef TeTHA_e_THASpdLimReq_SNA
#   define TeTHA_e_THASpdLimReq_SNA (3U)
#  endif

#  ifndef TeTHA_e_THAState_Initial
#   define TeTHA_e_THAState_Initial (0U)
#  endif

#  ifndef TeTHA_e_THAState_Idle
#   define TeTHA_e_THAState_Idle (1U)
#  endif

#  ifndef TeTHA_e_THAState_Enabled
#   define TeTHA_e_THAState_Enabled (2U)
#  endif

#  ifndef TeTHA_e_THAState_Engaged
#   define TeTHA_e_THAState_Engaged (3U)
#  endif

#  ifndef TeTHA_e_THAState_Complete
#   define TeTHA_e_THAState_Complete (4U)
#  endif

#  ifndef TeTHA_e_THAState_Faulted
#   define TeTHA_e_THAState_Faulted (5U)
#  endif

#  ifndef TeTHA_e_THAState_SNA
#   define TeTHA_e_THAState_SNA (7U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Off
#   define TeTHA_e_THAStateInfo_Off (0U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Initial
#   define TeTHA_e_THAStateInfo_Initial (1U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Idle
#   define TeTHA_e_THAStateInfo_Idle (2U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Enabled
#   define TeTHA_e_THAStateInfo_Enabled (3U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Enabled_Selection
#   define TeTHA_e_THAStateInfo_Enabled_Selection (4U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Engaged
#   define TeTHA_e_THAStateInfo_Engaged (5U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Engaged_Delta
#   define TeTHA_e_THAStateInfo_Engaged_Delta (6U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Engaged_Inquiry
#   define TeTHA_e_THAStateInfo_Engaged_Inquiry (7U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Complete
#   define TeTHA_e_THAStateInfo_Complete (8U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_Faulted
#   define TeTHA_e_THAStateInfo_Faulted (9U)
#  endif

#  ifndef TeTHA_e_THAStateInfo_SNA
#   define TeTHA_e_THAStateInfo_SNA (10U)
#  endif

#  ifndef TeTHA_e_THASteerTrqReq_False
#   define TeTHA_e_THASteerTrqReq_False (0U)
#  endif

#  ifndef TeTHA_e_THASteerTrqReq_True
#   define TeTHA_e_THASteerTrqReq_True (2U)
#  endif

#  ifndef TeTHA_e_THASteerTrqReq_SNA
#   define TeTHA_e_THASteerTrqReq_SNA (3U)
#  endif

#  ifndef TeTRSC_e_CamBlockSts_CameraBlocked
#   define TeTRSC_e_CamBlockSts_CameraBlocked (0U)
#  endif

#  ifndef TeTRSC_e_CamBlockSts_CameraClear
#   define TeTRSC_e_CamBlockSts_CameraClear (1U)
#  endif

#  ifndef TeTRSC_e_CamBlockSts_LowLight
#   define TeTRSC_e_CamBlockSts_LowLight (2U)
#  endif

#  ifndef TeTRSC_e_CamBlockSts_SNA
#   define TeTRSC_e_CamBlockSts_SNA (3U)
#  endif

#  ifndef TeTRSC_e_DispView2_Off_DID
#   define TeTRSC_e_DispView2_Off_DID (0U)
#  endif

#  ifndef TeTRSC_e_DispView2_View1_DID
#   define TeTRSC_e_DispView2_View1_DID (1U)
#  endif

#  ifndef TeTRSC_e_DispView2_View2_DID
#   define TeTRSC_e_DispView2_View2_DID (2U)
#  endif

#  ifndef TeTRSC_e_DispView2_View3_DID
#   define TeTRSC_e_DispView2_View3_DID (3U)
#  endif

#  ifndef TeTRSC_e_DispView2_View4_DID
#   define TeTRSC_e_DispView2_View4_DID (4U)
#  endif

#  ifndef TeTRSC_e_DispView2_View5_DID
#   define TeTRSC_e_DispView2_View5_DID (5U)
#  endif

#  ifndef TeTRSC_e_DispView2_View6_DID
#   define TeTRSC_e_DispView2_View6_DID (6U)
#  endif

#  ifndef TeTRSC_e_DispView2_View7_DID
#   define TeTRSC_e_DispView2_View7_DID (7U)
#  endif

#  ifndef TeTRSC_e_DispView2_View8_DID
#   define TeTRSC_e_DispView2_View8_DID (8U)
#  endif

#  ifndef TeTRSC_e_DispView2_View9_DID
#   define TeTRSC_e_DispView2_View9_DID (9U)
#  endif

#  ifndef TeTRSC_e_DispView2_View10_DID
#   define TeTRSC_e_DispView2_View10_DID (10U)
#  endif

#  ifndef TeTRSC_e_DispView2_View11_DID
#   define TeTRSC_e_DispView2_View11_DID (11U)
#  endif

#  ifndef TeTRSC_e_DispView2_View12_DID
#   define TeTRSC_e_DispView2_View12_DID (12U)
#  endif

#  ifndef TeTRSC_e_DispView2_View13_DID
#   define TeTRSC_e_DispView2_View13_DID (13U)
#  endif

#  ifndef TeTRSC_e_DispView2_View14_DID
#   define TeTRSC_e_DispView2_View14_DID (14U)
#  endif

#  ifndef TeTRSC_e_DispView2_View15_DID
#   define TeTRSC_e_DispView2_View15_DID (15U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_P_DID
#   define TeVBII_e_GearEngagedForDsply_P_DID (0U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_R_DID
#   define TeVBII_e_GearEngagedForDsply_R_DID (1U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_N_DID
#   define TeVBII_e_GearEngagedForDsply_N_DID (2U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_D_DID
#   define TeVBII_e_GearEngagedForDsply_D_DID (3U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_L_DID
#   define TeVBII_e_GearEngagedForDsply_L_DID (4U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_M_DID
#   define TeVBII_e_GearEngagedForDsply_M_DID (5U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_S_DID
#   define TeVBII_e_GearEngagedForDsply_S_DID (6U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_SNA_DID
#   define TeVBII_e_GearEngagedForDsply_SNA_DID (7U)
#  endif

#  ifndef TeTRSC_e_GraphicOverlay_Sts_Inactive
#   define TeTRSC_e_GraphicOverlay_Sts_Inactive (0U)
#  endif

#  ifndef TeTRSC_e_GraphicOverlay_Sts_Active
#   define TeTRSC_e_GraphicOverlay_Sts_Active (1U)
#  endif

#  ifndef TeTRSC_e_GraphicOverlay_Sts_SNA
#   define TeTRSC_e_GraphicOverlay_Sts_SNA (2U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_NotLim
#   define TeTRSC_e_SpdLmtReq_NotLim (0U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd4
#   define TeTRSC_e_SpdLmtReq_Spd4 (1U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd5
#   define TeTRSC_e_SpdLmtReq_Spd5 (2U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd6
#   define TeTRSC_e_SpdLmtReq_Spd6 (3U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd7
#   define TeTRSC_e_SpdLmtReq_Spd7 (4U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd8
#   define TeTRSC_e_SpdLmtReq_Spd8 (5U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd9
#   define TeTRSC_e_SpdLmtReq_Spd9 (6U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_Spd10
#   define TeTRSC_e_SpdLmtReq_Spd10 (7U)
#  endif

#  ifndef TeTRSC_e_SpdLmtReq_SNA
#   define TeTRSC_e_SpdLmtReq_SNA (15U)
#  endif

#  ifndef TeTRSC_e_TADState_Idle
#   define TeTRSC_e_TADState_Idle (0U)
#  endif

#  ifndef TeTRSC_e_TADState_TrailerDetection
#   define TeTRSC_e_TADState_TrailerDetection (1U)
#  endif

#  ifndef TeTRSC_e_TADState_TrailerRecognition
#   define TeTRSC_e_TADState_TrailerRecognition (2U)
#  endif

#  ifndef TeTRSC_e_TADState_Calibration
#   define TeTRSC_e_TADState_Calibration (3U)
#  endif

#  ifndef TeTRSC_e_TADState_ScanningForTrailer
#   define TeTRSC_e_TADState_ScanningForTrailer (4U)
#  endif

#  ifndef TeTRSC_e_TADState_Turnaround
#   define TeTRSC_e_TADState_Turnaround (5U)
#  endif

#  ifndef TeTRSC_e_TADState_AngleDetection
#   define TeTRSC_e_TADState_AngleDetection (6U)
#  endif

#  ifndef TeTRSC_e_TADState_Trackinglost
#   define TeTRSC_e_TADState_Trackinglost (7U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Engine_Controller
#   define TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Engine_Controller (0U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Brake_Systems
#   define TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Brake_Systems (1U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Electric_Power_Steering
#   define TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Electric_Power_Steering (2U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_Transmission_Controller
#   define TeTRSC_e_TRSCAbortReas_No_Or_Transmission_Controller (3U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_ORC_Module
#   define TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_ORC_Module (4U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Radio
#   define TeTRSC_e_TRSCAbortReas_No_Or_InvalidResp_Radio (5U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Speed_Above_25mph
#   define TeTRSC_e_TRSCAbortReas_Speed_Above_25mph (6U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Trailer_Lost_From_FoV
#   define TeTRSC_e_TRSCAbortReas_Trailer_Lost_From_FoV (7U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Ignition_Not_Run
#   define TeTRSC_e_TRSCAbortReas_Ignition_Not_Run (8U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Rear_Tailgate_Open
#   define TeTRSC_e_TRSCAbortReas_Rear_Tailgate_Open (9U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Engine_Off
#   define TeTRSC_e_TRSCAbortReas_Engine_Off (10U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Driver_Steering_Override
#   define TeTRSC_e_TRSCAbortReas_Driver_Steering_Override (11U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_No_User_Feedback
#   define TeTRSC_e_TRSCAbortReas_No_User_Feedback (12U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_TRSC_Btn_Pressed
#   define TeTRSC_e_TRSCAbortReas_TRSC_Btn_Pressed (13U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Vehicle_Speed_exceeded
#   define TeTRSC_e_TRSCAbortReas_Vehicle_Speed_exceeded (14U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Driver_Door_Open
#   define TeTRSC_e_TRSCAbortReas_Driver_Door_Open (15U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_TRSKMKnob_Module_No_Response
#   define TeTRSC_e_TRSCAbortReas_TRSKMKnob_Module_No_Response (16U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Voltage_Low_Or_High_Than_OperatingRange
#   define TeTRSC_e_TRSCAbortReas_Voltage_Low_Or_High_Than_OperatingRange (17U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_Trailer_Angle_Too_Steep
#   define TeTRSC_e_TRSCAbortReas_Trailer_Angle_Too_Steep (18U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_ail_Not_Present
#   define TeTRSC_e_TRSCAbortReas_ail_Not_Present (19U)
#  endif

#  ifndef TeTRSC_e_TRSCAbortReas_SNA
#   define TeTRSC_e_TRSCAbortReas_SNA (20U)
#  endif

#  ifndef TeTRSC_e_TRSCLedSts_Off
#   define TeTRSC_e_TRSCLedSts_Off (0U)
#  endif

#  ifndef TeTRSC_e_TRSCLedSts_Solid
#   define TeTRSC_e_TRSCLedSts_Solid (1U)
#  endif

#  ifndef TeTRSC_e_TRSCLedSts_Blink
#   define TeTRSC_e_TRSCLedSts_Blink (2U)
#  endif

#  ifndef TeTRSC_e_TRSCLedSts_SNA
#   define TeTRSC_e_TRSCLedSts_SNA (3U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp0
#   define TeTRSC_e_TRSCPopupDispInfo_Disp0 (0U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp1
#   define TeTRSC_e_TRSCPopupDispInfo_Disp1 (1U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp2
#   define TeTRSC_e_TRSCPopupDispInfo_Disp2 (2U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp3
#   define TeTRSC_e_TRSCPopupDispInfo_Disp3 (3U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp4
#   define TeTRSC_e_TRSCPopupDispInfo_Disp4 (4U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp5
#   define TeTRSC_e_TRSCPopupDispInfo_Disp5 (5U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp6
#   define TeTRSC_e_TRSCPopupDispInfo_Disp6 (6U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp7
#   define TeTRSC_e_TRSCPopupDispInfo_Disp7 (7U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp8
#   define TeTRSC_e_TRSCPopupDispInfo_Disp8 (8U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp9
#   define TeTRSC_e_TRSCPopupDispInfo_Disp9 (9U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp10
#   define TeTRSC_e_TRSCPopupDispInfo_Disp10 (10U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp11
#   define TeTRSC_e_TRSCPopupDispInfo_Disp11 (11U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp12
#   define TeTRSC_e_TRSCPopupDispInfo_Disp12 (12U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp13
#   define TeTRSC_e_TRSCPopupDispInfo_Disp13 (13U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_Disp14
#   define TeTRSC_e_TRSCPopupDispInfo_Disp14 (14U)
#  endif

#  ifndef TeTRSC_e_TRSCPopupDispInfo_SNA
#   define TeTRSC_e_TRSCPopupDispInfo_SNA (15U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_Off
#   define TeTRSC_e_TRSCStat_Off (0U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_Standby
#   define TeTRSC_e_TRSCStat_Standby (1U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_Calibrating
#   define TeTRSC_e_TRSCStat_Calibrating (2U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_PreActive
#   define TeTRSC_e_TRSCStat_PreActive (3U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_Active
#   define TeTRSC_e_TRSCStat_Active (4U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_ActiveHoldOvr
#   define TeTRSC_e_TRSCStat_ActiveHoldOvr (5U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_Fault
#   define TeTRSC_e_TRSCStat_Fault (6U)
#  endif

#  ifndef TeTRSC_e_TRSCStat_SNA
#   define TeTRSC_e_TRSCStat_SNA (7U)
#  endif

#  ifndef TeTRSC_e_TRSCStrTrqActvReq_False
#   define TeTRSC_e_TRSCStrTrqActvReq_False (0U)
#  endif

#  ifndef TeTRSC_e_TRSCStrTrqActvReq_True
#   define TeTRSC_e_TRSCStrTrqActvReq_True (1U)
#  endif

#  ifndef TeTRSC_e_TRSCStrTrqActvReq_SNA
#   define TeTRSC_e_TRSCStrTrqActvReq_SNA (3U)
#  endif

#  ifndef TeTRSC_e_TRSCSts_Standby
#   define TeTRSC_e_TRSCSts_Standby (0U)
#  endif

#  ifndef TeTRSC_e_TRSCSts_Calibrating
#   define TeTRSC_e_TRSCSts_Calibrating (1U)
#  endif

#  ifndef TeTRSC_e_TRSCSts_PreActive
#   define TeTRSC_e_TRSCSts_PreActive (2U)
#  endif

#  ifndef TeTRSC_e_TRSCSts_Active
#   define TeTRSC_e_TRSCSts_Active (3U)
#  endif

#  ifndef TeTRSC_e_TRSCSts_SNA
#   define TeTRSC_e_TRSCSts_SNA (7U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Engine_Controller
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Engine_Controller (0U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Brake_Systems
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Brake_Systems (1U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Electric_Power_Steering
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Electric_Power_Steering (2U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Transmission_Controller
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Transmission_Controller (3U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_ORC_Module
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_ORC_Module (4U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Radio
#   define TeTRSC_e_TRSCUnavail_No_Or_InvalidResp_Radio (5U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Ignition_Not_Run
#   define TeTRSC_e_TRSCUnavail_Ignition_Not_Run (6U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Rear_Tailgate_Open
#   define TeTRSC_e_TRSCUnavail_Rear_Tailgate_Open (7U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Engine_Off
#   define TeTRSC_e_TRSCUnavail_Engine_Off (8U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Driver_Door_Open
#   define TeTRSC_e_TRSCUnavail_Driver_Door_Open (9U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Vehicle_NotIn_Park
#   define TeTRSC_e_TRSCUnavail_Vehicle_NotIn_Park (10U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_CameraCalibration_Unknown
#   define TeTRSC_e_TRSCUnavail_CameraCalibration_Unknown (11U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Trailer_Not_Detected
#   define TeTRSC_e_TRSCUnavail_Trailer_Not_Detected (12U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Trailer_Angle_Too_Steep
#   define TeTRSC_e_TRSCUnavail_Trailer_Angle_Too_Steep (13U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Trailer_Calibration_Failure
#   define TeTRSC_e_TRSCUnavail_Trailer_Calibration_Failure (14U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_TRSKMKnob_Module_No_Response
#   define TeTRSC_e_TRSCUnavail_TRSKMKnob_Module_No_Response (15U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Voltage_Low_Or_High_Than_OperatingRange
#   define TeTRSC_e_TRSCUnavail_Voltage_Low_Or_High_Than_OperatingRange (16U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_ECU_Plant_Mode
#   define TeTRSC_e_TRSCUnavail_ECU_Plant_Mode (17U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Invalid_Proxi
#   define TeTRSC_e_TRSCUnavail_Invalid_Proxi (18U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_Fail_Not_Present
#   define TeTRSC_e_TRSCUnavail_Fail_Not_Present (19U)
#  endif

#  ifndef TeTRSC_e_TRSCUnavail_SNA
#   define TeTRSC_e_TRSCUnavail_SNA (20U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_NotPressed_DID
#   define TeVBII_e_EnblBtnSts_NotPressed_DID (0U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_Pressed_DID
#   define TeVBII_e_EnblBtnSts_Pressed_DID (1U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_Struck_DID
#   define TeVBII_e_EnblBtnSts_Struck_DID (2U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_SNA_DID
#   define TeVBII_e_EnblBtnSts_SNA_DID (3U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_NotPressed_DID
#   define TeVBII_e_CenterBtnSts_NotPressed_DID (0U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_Pressed_DID
#   define TeVBII_e_CenterBtnSts_Pressed_DID (1U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_Struck_DID
#   define TeVBII_e_CenterBtnSts_Struck_DID (2U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_SNA_DID
#   define TeVBII_e_CenterBtnSts_SNA_DID (3U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_NotEnabled
#   define TeTRSC_e_TRSKMSts_NotEnabled (0U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_Enabled
#   define TeTRSC_e_TRSKMSts_Enabled (1U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_SNA
#   define TeTRSC_e_TRSKMSts_SNA (2U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_Enabled_DID
#   define TeTRSC_e_TRSKMSts_Enabled_DID (0U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_NotEnabled_DID
#   define TeTRSC_e_TRSKMSts_NotEnabled_DID (1U)
#  endif

#  ifndef TeTRSC_e_TRSKMSts_SNA_DID
#   define TeTRSC_e_TRSKMSts_SNA_DID (2U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_NotCalibrated
#   define TeTRSC_e_TrlrCalInfo_NotCalibrated (0U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_Calibrated
#   define TeTRSC_e_TrlrCalInfo_Calibrated (1U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_Undefined
#   define TeTRSC_e_TrlrCalInfo_Undefined (2U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_Calibrated_DID
#   define TeTRSC_e_TrlrCalInfo_Calibrated_DID (0U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_NotCalibrated_DID
#   define TeTRSC_e_TrlrCalInfo_NotCalibrated_DID (1U)
#  endif

#  ifndef TeTRSC_e_TrlrCalInfo_SNA_DID
#   define TeTRSC_e_TrlrCalInfo_SNA_DID (2U)
#  endif

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_ON
#   define TeTRSC_e_TrlrHitchLightCtrl_ON (0U)
#  endif

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_OFF
#   define TeTRSC_e_TrlrHitchLightCtrl_OFF (1U)
#  endif

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_SNA
#   define TeTRSC_e_TrlrHitchLightCtrl_SNA (3U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_Unknown
#   define TeTRSC_e_TrlrPrsntInfo_Unknown (0U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_NoTrlr
#   define TeTRSC_e_TrlrPrsntInfo_NoTrlr (1U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt
#   define TeTRSC_e_TrlrPrsntInfo_TrlrPrsnt (2U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID
#   define TeTRSC_e_TrlrPrsntInfo_Not_Detected_DID (0U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_Detected_DID
#   define TeTRSC_e_TrlrPrsntInfo_Detected_DID (1U)
#  endif

#  ifndef TeTRSC_e_TrlrPrsntInfo_SNA_DID
#   define TeTRSC_e_TrlrPrsntInfo_SNA_DID (2U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_Unknown
#   define TeTRSC_e_TrlrRecogInfo_Unknown (0U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_Known
#   define TeTRSC_e_TrlrRecogInfo_Known (1U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_Known_DID
#   define TeTRSC_e_TrlrRecogInfo_Known_DID (0U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_Unknown_DID
#   define TeTRSC_e_TrlrRecogInfo_Unknown_DID (1U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_No_Trailer_Detected_DID
#   define TeTRSC_e_TrlrRecogInfo_No_Trailer_Detected_DID (2U)
#  endif

#  ifndef TeTRSC_e_TrlrRecogInfo_SNA_DID
#   define TeTRSC_e_TrlrRecogInfo_SNA_DID (3U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_False
#   define TeTRSC_e_VehStpReq_False (0U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_True
#   define TeTRSC_e_VehStpReq_True (1U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_SNA
#   define TeTRSC_e_VehStpReq_SNA (3U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_True_DID
#   define TeTRSC_e_VehStpReq_True_DID (0U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_False_DID
#   define TeTRSC_e_VehStpReq_False_DID (1U)
#  endif

#  ifndef TeTRSC_e_VehStpReq_SNA_DID
#   define TeTRSC_e_VehStpReq_SNA_DID (2U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_NotPressed
#   define TeVBII_e_CenterBtnSts_NotPressed (0U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_Pressed
#   define TeVBII_e_CenterBtnSts_Pressed (1U)
#  endif

#  ifndef TeVBII_e_CenterBtnSts_SNA
#   define TeVBII_e_CenterBtnSts_SNA (2U)
#  endif

#  ifndef Seat_Belt_Fasten
#   define Seat_Belt_Fasten (0U)
#  endif

#  ifndef Seat_Belt_Not_Fasten
#   define Seat_Belt_Not_Fasten (1U)
#  endif

#  ifndef Seat_Belt_SNA
#   define Seat_Belt_SNA (2U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_NotPressed
#   define TeVBII_e_EnblBtnSts_NotPressed (0U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_Pressed
#   define TeVBII_e_EnblBtnSts_Pressed (1U)
#  endif

#  ifndef TeVBII_e_EnblBtnSts_SNA
#   define TeVBII_e_EnblBtnSts_SNA (2U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Init
#   define TeVBII_e_GearEngagedForDsply_Init (0U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear1
#   define TeVBII_e_GearEngagedForDsply_Gear1 (1U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear2
#   define TeVBII_e_GearEngagedForDsply_Gear2 (2U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear3
#   define TeVBII_e_GearEngagedForDsply_Gear3 (3U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear4
#   define TeVBII_e_GearEngagedForDsply_Gear4 (4U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear5
#   define TeVBII_e_GearEngagedForDsply_Gear5 (5U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear6
#   define TeVBII_e_GearEngagedForDsply_Gear6 (6U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear7
#   define TeVBII_e_GearEngagedForDsply_Gear7 (7U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear8
#   define TeVBII_e_GearEngagedForDsply_Gear8 (8U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_Gear9
#   define TeVBII_e_GearEngagedForDsply_Gear9 (9U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_NotUsed1
#   define TeVBII_e_GearEngagedForDsply_NotUsed1 (10U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_NotUsed2
#   define TeVBII_e_GearEngagedForDsply_NotUsed2 (11U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_P
#   define TeVBII_e_GearEngagedForDsply_P (12U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_N
#   define TeVBII_e_GearEngagedForDsply_N (13U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_R
#   define TeVBII_e_GearEngagedForDsply_R (14U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_D
#   define TeVBII_e_GearEngagedForDsply_D (15U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_L
#   define TeVBII_e_GearEngagedForDsply_L (16U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_M
#   define TeVBII_e_GearEngagedForDsply_M (17U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_S
#   define TeVBII_e_GearEngagedForDsply_S (18U)
#  endif

#  ifndef TeVBII_e_GearEngagedForDsply_SNA
#   define TeVBII_e_GearEngagedForDsply_SNA (31U)
#  endif

#  ifndef TrailerAngleSign_Clockwise
#   define TrailerAngleSign_Clockwise (0U)
#  endif

#  ifndef TrailerAngleSign_Anticlockwise
#   define TrailerAngleSign_Anticlockwise (1U)
#  endif

#  ifndef TrailerAngleSign_None
#   define TrailerAngleSign_None (2U)
#  endif

#  ifndef More_Turn_Radius_or_Arc_Length_DID
#   define More_Turn_Radius_or_Arc_Length_DID (0U)
#  endif

#  ifndef More_Straight_driving_DID
#   define More_Straight_driving_DID (1U)
#  endif

#  ifndef Camera_Blocked_or_low_Light
#   define Camera_Blocked_or_low_Light (2U)
#  endif

#  ifndef No_Failure_DID
#   define No_Failure_DID (3U)
#  endif

#  ifndef SNA_DID
#   define SNA_DID (4U)
#  endif

#  ifndef No_Failure
#   define No_Failure (0U)
#  endif

#  ifndef Camera_Blocked
#   define Camera_Blocked (1U)
#  endif

#  ifndef Gear_IN_Reverse
#   define Gear_IN_Reverse (2U)
#  endif

#  define TrailerConnectionSts_adt_LowerLimit (0U)
#  define TrailerConnectionSts_adt_UpperLimit (3U)

#  define InvalidValue_TrailerConnectionSts (3U)

#  ifndef Cx0_Not_Connected
#   define Cx0_Not_Connected (0U)
#  endif

#  ifndef Cx1_Connected
#   define Cx1_Connected (1U)
#  endif

#  ifndef Cx2_Not_Used
#   define Cx2_Not_Used (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef Trailer_ID1
#   define Trailer_ID1 (0U)
#  endif

#  ifndef Trailer_ID2
#   define Trailer_ID2 (1U)
#  endif

#  ifndef Trailer_ID3
#   define Trailer_ID3 (2U)
#  endif

#  ifndef Trailer_ID4
#   define Trailer_ID4 (3U)
#  endif

#  ifndef Trailer_ID5
#   define Trailer_ID5 (4U)
#  endif

#  ifndef Trailer_Absent
#   define Trailer_Absent (5U)
#  endif

#  ifndef Trailer_MAX
#   define Trailer_MAX (6U)
#  endif

#  ifndef UNKNOWN
#   define UNKNOWN (0U)
#  endif

#  ifndef NO_TRAILER
#   define NO_TRAILER (1U)
#  endif

#  ifndef TRAILERPRESENT
#   define TRAILERPRESENT (2U)
#  endif

#  define TransmissionSailingSts_adt_LowerLimit (0U)
#  define TransmissionSailingSts_adt_UpperLimit (15U)

#  define InvalidValue_TransmissionSailingSts (15U)

#  ifndef Cx0_Sailing_Not_Possible
#   define Cx0_Sailing_Not_Possible (0U)
#  endif

#  ifndef Cx1_Sailing_Possible_Passive
#   define Cx1_Sailing_Possible_Passive (1U)
#  endif

#  ifndef Cx2_Transition_To_Sailing
#   define Cx2_Transition_To_Sailing (2U)
#  endif

#  ifndef Cx3_Sailing_Active
#   define Cx3_Sailing_Active (3U)
#  endif

#  ifndef Cx4_Transition_Out_Of_Sailing
#   define Cx4_Transition_Out_Of_Sailing (4U)
#  endif

#  ifndef Cx5_Sailing_Not_Available
#   define Cx5_Sailing_Not_Available (5U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  ifndef NotCalibrated
#   define NotCalibrated (0U)
#  endif

#  ifndef Calibrated
#   define Calibrated (1U)
#  endif

#  ifndef undefined
#   define undefined (2U)
#  endif

#  ifndef TurnAroundState_DriveStraight
#   define TurnAroundState_DriveStraight (0U)
#  endif

#  ifndef TurnAroundState_TurnLeftOrRight
#   define TurnAroundState_TurnLeftOrRight (1U)
#  endif

#  ifndef TurnAroundState_Wait
#   define TurnAroundState_Wait (2U)
#  endif

#  ifndef US_ZONE_OFF
#   define US_ZONE_OFF (0U)
#  endif

#  ifndef US_ZONE_1
#   define US_ZONE_1 (1U)
#  endif

#  ifndef US_ZONE_2
#   define US_ZONE_2 (2U)
#  endif

#  ifndef US_ZONE_3
#   define US_ZONE_3 (3U)
#  endif

#  ifndef US_ZONE_4
#   define US_ZONE_4 (4U)
#  endif

#  ifndef US_ZONE_5_NOT_USED
#   define US_ZONE_5_NOT_USED (5U)
#  endif

#  ifndef US_ZONE_6_NOT_USED
#   define US_ZONE_6_NOT_USED (6U)
#  endif

#  ifndef US_ZONE_7_NOT_USED
#   define US_ZONE_7_NOT_USED (7U)
#  endif

#  ifndef US_ZONE_8_NOT_USED
#   define US_ZONE_8_NOT_USED (8U)
#  endif

#  ifndef US_ZONE_NO_OBSTACLE
#   define US_ZONE_NO_OBSTACLE (9U)
#  endif

#  ifndef US_ZONE_10_NOT_USED
#   define US_ZONE_10_NOT_USED (10U)
#  endif

#  ifndef US_ZONE_11_NOT_USED
#   define US_ZONE_11_NOT_USED (11U)
#  endif

#  ifndef US_ZONE_RESERVED_12
#   define US_ZONE_RESERVED_12 (12U)
#  endif

#  ifndef US_ZONE_RESERVED_13
#   define US_ZONE_RESERVED_13 (13U)
#  endif

#  ifndef US_ZONE_RESERVED_15
#   define US_ZONE_RESERVED_15 (14U)
#  endif

#  ifndef US_ZONE_UNSED
#   define US_ZONE_UNSED (15U)
#  endif

#  define VIN_MSG_adt_LowerLimit (0U)
#  define VIN_MSG_adt_UpperLimit (3U)

#  define InvalidValue_VIN_MSG (3U)

#  ifndef Cx0_VIN_LO
#   define Cx0_VIN_LO (0U)
#  endif

#  ifndef Cx1_VIN_MID
#   define Cx1_VIN_MID (1U)
#  endif

#  ifndef Cx2_VIN_HI
#   define Cx2_VIN_HI (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef DisplayView2_ViewOFF
#   define DisplayView2_ViewOFF (0U)
#  endif

#  ifndef DisplayView2_View1
#   define DisplayView2_View1 (1U)
#  endif

#  ifndef DisplayView2_View2
#   define DisplayView2_View2 (2U)
#  endif

#  ifndef DisplayView2_View3
#   define DisplayView2_View3 (3U)
#  endif

#  ifndef DisplayView2_View4
#   define DisplayView2_View4 (4U)
#  endif

#  ifndef DisplayView2_View5
#   define DisplayView2_View5 (5U)
#  endif

#  ifndef DisplayView2_View6
#   define DisplayView2_View6 (6U)
#  endif

#  ifndef DisplayView2_View7
#   define DisplayView2_View7 (7U)
#  endif

#  ifndef DisplayView2_View8
#   define DisplayView2_View8 (8U)
#  endif

#  ifndef DisplayView2_View9
#   define DisplayView2_View9 (9U)
#  endif

#  ifndef DisplayView2_View10
#   define DisplayView2_View10 (10U)
#  endif

#  ifndef DisplayView2_View11
#   define DisplayView2_View11 (11U)
#  endif

#  ifndef DisplayView2_View12
#   define DisplayView2_View12 (12U)
#  endif

#  ifndef DisplayView2_View13
#   define DisplayView2_View13 (13U)
#  endif

#  ifndef DisplayView2_View14
#   define DisplayView2_View14 (14U)
#  endif

#  ifndef DisplayView2_View15
#   define DisplayView2_View15 (15U)
#  endif

#  ifndef THA_Default
#   define THA_Default (0U)
#  endif

#  ifndef THA_Enable
#   define THA_Enable (1U)
#  endif

#  ifndef THA_TCS_Msg1
#   define THA_TCS_Msg1 (2U)
#  endif

#  ifndef THA_TCS_Msg2
#   define THA_TCS_Msg2 (3U)
#  endif

#  ifndef THA_TCS_Msg3
#   define THA_TCS_Msg3 (4U)
#  endif

#  ifndef THA_TCS_Msg4
#   define THA_TCS_Msg4 (5U)
#  endif

#  ifndef THA_TCS_Msg5
#   define THA_TCS_Msg5 (6U)
#  endif

#  ifndef THA_SM_Msg1
#   define THA_SM_Msg1 (7U)
#  endif

#  ifndef THA_SM_Msg2
#   define THA_SM_Msg2 (8U)
#  endif

#  ifndef THA_CM_Msg1
#   define THA_CM_Msg1 (9U)
#  endif

#  ifndef THA_CM_Msg2
#   define THA_CM_Msg2 (10U)
#  endif

#  ifndef THA_CM_Msg3
#   define THA_CM_Msg3 (11U)
#  endif

#  ifndef THA_CM_Msg4
#   define THA_CM_Msg4 (12U)
#  endif

#  ifndef THA_CM_Msg5
#   define THA_CM_Msg5 (13U)
#  endif

#  ifndef THA_CM_Msg6
#   define THA_CM_Msg6 (14U)
#  endif

#  ifndef THA_CM_Msg7
#   define THA_CM_Msg7 (15U)
#  endif

#  ifndef THA_CM_Msg8
#   define THA_CM_Msg8 (16U)
#  endif

#  ifndef THA_CM_Msg9
#   define THA_CM_Msg9 (17U)
#  endif

#  ifndef THA_CM_Msg10
#   define THA_CM_Msg10 (18U)
#  endif

#  ifndef THA_EOM_Msg1
#   define THA_EOM_Msg1 (19U)
#  endif

#  ifndef THA_EOM_Msg2
#   define THA_EOM_Msg2 (20U)
#  endif

#  ifndef THA_EOM_Msg3
#   define THA_EOM_Msg3 (21U)
#  endif

#  ifndef THA_EOM_Msg4
#   define THA_EOM_Msg4 (22U)
#  endif

#  ifndef THA_ERR_Msg1
#   define THA_ERR_Msg1 (23U)
#  endif

#  ifndef THA_ERR_Msg2
#   define THA_ERR_Msg2 (24U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_NotInit
#   define aZynqM_E_EOL_STM_E_NotInit (0U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_Init
#   define aZynqM_E_EOL_STM_E_Init (1U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_Idle
#   define aZynqM_E_EOL_STM_E_Idle (2U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_SelectCurrentCamera
#   define aZynqM_E_EOL_STM_E_SelectCurrentCamera (3U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_StartCameraCalibration
#   define aZynqM_E_EOL_STM_E_StartCameraCalibration (4U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_CheckStatus
#   define aZynqM_E_EOL_STM_E_CheckStatus (5U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_Stop
#   define aZynqM_E_EOL_STM_E_Stop (6U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_Error
#   define aZynqM_E_EOL_STM_E_Error (7U)
#  endif

#  ifndef aZynqM_E_EOL_STM_E_End
#   define aZynqM_E_EOL_STM_E_End (8U)
#  endif

#  ifndef aZynqM_E_EOL_STM_NumStates
#   define aZynqM_E_EOL_STM_NumStates (9U)
#  endif

#  ifndef aZynqM_E_OC_STM_NotInit
#   define aZynqM_E_OC_STM_NotInit (0U)
#  endif

#  ifndef aZynqM_E_OC_STM_Init
#   define aZynqM_E_OC_STM_Init (1U)
#  endif

#  ifndef aZynqM_E_OC_STM_Idle
#   define aZynqM_E_OC_STM_Idle (2U)
#  endif

#  ifndef aZynqM_E_OC_STM_SelectCurrentCamera
#   define aZynqM_E_OC_STM_SelectCurrentCamera (3U)
#  endif

#  ifndef aZynqM_E_OC_STM_StartCameraCalibration
#   define aZynqM_E_OC_STM_StartCameraCalibration (4U)
#  endif

#  ifndef aZynqM_E_OC_STM_CheckStatus
#   define aZynqM_E_OC_STM_CheckStatus (5U)
#  endif

#  ifndef aZynqM_E_OC_STM_Pause
#   define aZynqM_E_OC_STM_Pause (6U)
#  endif

#  ifndef aZynqM_E_OC_STM_Paused
#   define aZynqM_E_OC_STM_Paused (7U)
#  endif

#  ifndef aZynqM_E_OC_STM_Resume
#   define aZynqM_E_OC_STM_Resume (8U)
#  endif

#  ifndef aZynqM_E_OC_STM_Stop
#   define aZynqM_E_OC_STM_Stop (9U)
#  endif

#  ifndef aZynqM_E_OC_STM_Error
#   define aZynqM_E_OC_STM_Error (10U)
#  endif

#  ifndef aZynqM_E_OC_STM_End
#   define aZynqM_E_OC_STM_End (11U)
#  endif

#  ifndef aZynqM_E_OC_STM_NumStates
#   define aZynqM_E_OC_STM_NumStates (12U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_NotInit
#   define aZynqM_E_SC_STM_E_NotInit (0U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Init
#   define aZynqM_E_SC_STM_E_Init (1U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Idle
#   define aZynqM_E_SC_STM_E_Idle (2U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_WaitForEEPROMRead
#   define aZynqM_E_SC_STM_E_WaitForEEPROMRead (3U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_SelectCurrentCamera
#   define aZynqM_E_SC_STM_E_SelectCurrentCamera (4U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_StartCameraCalibration
#   define aZynqM_E_SC_STM_E_StartCameraCalibration (5U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_CheckStatus
#   define aZynqM_E_SC_STM_E_CheckStatus (6U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Pause
#   define aZynqM_E_SC_STM_E_Pause (7U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Paused
#   define aZynqM_E_SC_STM_E_Paused (8U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Resume
#   define aZynqM_E_SC_STM_E_Resume (9U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Stop
#   define aZynqM_E_SC_STM_E_Stop (10U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_Error
#   define aZynqM_E_SC_STM_E_Error (11U)
#  endif

#  ifndef aZynqM_E_SC_STM_E_End
#   define aZynqM_E_SC_STM_E_End (12U)
#  endif

#  ifndef aZynqM_E_SC_STM_NumStates
#   define aZynqM_E_SC_STM_NumStates (13U)
#  endif

#  ifndef SVS_INVALID
#   define SVS_INVALID (0U)
#  endif

#  ifndef SVS_FRONT
#   define SVS_FRONT (1U)
#  endif

#  ifndef SVS_REAR
#   define SVS_REAR (2U)
#  endif

#  ifndef SVS_LEFT
#   define SVS_LEFT (3U)
#  endif

#  ifndef SVS_RIGHT
#   define SVS_RIGHT (4U)
#  endif

#  ifndef USS_FRONT
#   define USS_FRONT (5U)
#  endif

#  ifndef USS_REAR
#   define USS_REAR (6U)
#  endif

#  ifndef USS_LEFT
#   define USS_LEFT (7U)
#  endif

#  ifndef USS_RIGHT
#   define USS_RIGHT (8U)
#  endif

#  define Battery_Volt_1_adt_LowerLimit (0U)
#  define Battery_Volt_1_adt_UpperLimit (511U)

#  define CM_TCH_X_COORD_adt_LowerLimit (0U)
#  define CM_TCH_X_COORD_adt_UpperLimit (65535U)

#  define CM_TCH_Y_COORD_adt_LowerLimit (0U)
#  define CM_TCH_Y_COORD_adt_UpperLimit (65535U)

#  define Cntr_CVPAM_FD_Data2_adt_LowerLimit (0U)
#  define Cntr_CVPAM_FD_Data2_adt_UpperLimit (65535U)

#  define Cntr_CVPAM_FD_Data_adt_LowerLimit (0U)
#  define Cntr_CVPAM_FD_Data_adt_UpperLimit (65535U)

#  define ExternalTemperature_adt_LowerLimit (0U)
#  define ExternalTemperature_adt_UpperLimit (511U)

#  define FD14_BrkTrq_Driver_adt_LowerLimit (0U)
#  define FD14_BrkTrq_Driver_adt_UpperLimit (32767U)

#  define FD14_BrkTrq_adt_LowerLimit (0U)
#  define FD14_BrkTrq_adt_UpperLimit (32767U)

#  define FD14_LHFWheelSpeed_adt_LowerLimit (0U)
#  define FD14_LHFWheelSpeed_adt_UpperLimit (8191U)

#  define FD14_LHRWheelSpeed_adt_LowerLimit (0U)
#  define FD14_LHRWheelSpeed_adt_UpperLimit (8191U)

#  define FD14_LatAcceleration_BSM_adt_LowerLimit (0U)
#  define FD14_LatAcceleration_BSM_adt_UpperLimit (4095U)

#  define FD14_LongAcceleration_BSM_adt_LowerLimit (0U)
#  define FD14_LongAcceleration_BSM_adt_UpperLimit (4095U)

#  define FD14_LwsSpeed_adt_LowerLimit (0U)
#  define FD14_LwsSpeed_adt_UpperLimit (4095U)

#  define FD14_PA_Line_LM_Distance_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Distance_adt_UpperLimit (511U)

#  define FD14_PA_Line_LM_Heading_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Heading_adt_UpperLimit (511U)

#  define FD14_PA_Line_RM_Distance_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Distance_adt_UpperLimit (511U)

#  define FD14_PA_Line_RM_Heading_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Heading_adt_UpperLimit (511U)

#  define FD14_PA_Obj1_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj1_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj1_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj1_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Range_adt_UpperLimit (1023U)

#  define FD14_PA_Obj2_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj2_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj2_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj2_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Range_adt_UpperLimit (1023U)

#  define FD14_PA_Obj3_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj3_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj3_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj3_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Range_adt_UpperLimit (1023U)

#  define FD14_PA_Obj4_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj4_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj4_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj4_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Range_adt_UpperLimit (1023U)

#  define FD14_PA_Obj5_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj5_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj5_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj5_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Range_adt_UpperLimit (1023U)

#  define FD14_PA_Obj6_Angle_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Angle_2_adt_UpperLimit (511U)

#  define FD14_PA_Obj6_Angle_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Angle_adt_UpperLimit (511U)

#  define FD14_PA_Obj6_Range_2_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Range_2_adt_UpperLimit (1023U)

#  define FD14_PA_Obj6_Range_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Range_adt_UpperLimit (1023U)

#  define FD14_PA_SideSensor_FrontLeft_Dist_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_FrontLeft_Dist_adt_UpperLimit (1023U)

#  define FD14_PA_SideSensor_FrontRight_Dist_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_FrontRight_Dist_adt_UpperLimit (1023U)

#  define FD14_PA_SideSensor_RearLeft_Dist_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_RearLeft_Dist_adt_UpperLimit (1023U)

#  define FD14_PA_SideSensor_RearRight_Dist_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_RearRight_Dist_adt_UpperLimit (1023U)

#  define FD14_PPPA_TargetDistance_adt_LowerLimit (0U)
#  define FD14_PPPA_TargetDistance_adt_UpperLimit (1023U)

#  define FD14_REF_VEH_SPEED_adt_LowerLimit (0U)
#  define FD14_REF_VEH_SPEED_adt_UpperLimit (1023U)

#  define FD14_RHFWheelSpeed_adt_LowerLimit (0U)
#  define FD14_RHFWheelSpeed_adt_UpperLimit (8191U)

#  define FD14_RHRWheelSpeed_adt_LowerLimit (0U)
#  define FD14_RHRWheelSpeed_adt_UpperLimit (8191U)

#  define FD14_RR_PAM_Dist_adt_LowerLimit (0U)
#  define FD14_RR_PAM_Dist_adt_UpperLimit (1023U)

#  define FD14_Steering_Column_Torque_adt_LowerLimit (0U)
#  define FD14_Steering_Column_Torque_adt_UpperLimit (2047U)

#  define FD14_THA_SteeringTorqueInfo_adt_LowerLimit (0U)
#  define FD14_THA_SteeringTorqueInfo_adt_UpperLimit (2047U)

#  define FD14_TRSC_SteeringTorqueInfo_adt_LowerLimit (0U)
#  define FD14_TRSC_SteeringTorqueInfo_adt_UpperLimit (2047U)

#  define FD14_TorqueOverlaySteeringReq_SPM_adt_LowerLimit (0U)
#  define FD14_TorqueOverlaySteeringReq_SPM_adt_UpperLimit (2047U)

#  define FD14_VehicleSpeedVSOSig_B2_adt_LowerLimit (0U)
#  define FD14_VehicleSpeedVSOSig_B2_adt_UpperLimit (8191U)

#  define FD14_VehicleSpeedVSOSig_adt_LowerLimit (0U)
#  define FD14_VehicleSpeedVSOSig_adt_UpperLimit (8191U)

#  define FD14_YawRate_BSM_adt_LowerLimit (0U)
#  define FD14_YawRate_BSM_adt_UpperLimit (4095U)

#  define Heading_Angle_C2_adt_LowerLimit (0U)
#  define Heading_Angle_C2_adt_UpperLimit (65535U)

#  define IgnitionOnCounter_adt_LowerLimit (0U)
#  define IgnitionOnCounter_adt_UpperLimit (65535U)

#  define LHFWheelSpeed_adt_LowerLimit (0U)
#  define LHFWheelSpeed_adt_UpperLimit (8191U)

#  define LHRWheelSpeed_adt_LowerLimit (0U)
#  define LHRWheelSpeed_adt_UpperLimit (8191U)

#  define LatAcceleration_BSM_adt_LowerLimit (0U)
#  define LatAcceleration_BSM_adt_UpperLimit (4095U)

#  define LatAcceleration_C2_adt_LowerLimit (0U)
#  define LatAcceleration_C2_adt_UpperLimit (4095U)

#  define Line_1_Curvature_Rate_adt_LowerLimit (0U)
#  define Line_1_Curvature_Rate_adt_UpperLimit (65535U)

#  define Line_1_Curvature_adt_LowerLimit (0U)
#  define Line_1_Curvature_adt_UpperLimit (65535U)

#  define Line_1_Heading_adt_LowerLimit (0U)
#  define Line_1_Heading_adt_UpperLimit (1023U)

#  define Line_1_Offset_adt_LowerLimit (0U)
#  define Line_1_Offset_adt_UpperLimit (1023U)

#  define Line_2_Curvature_Rate_adt_LowerLimit (0U)
#  define Line_2_Curvature_Rate_adt_UpperLimit (65535U)

#  define Line_2_Curvature_adt_LowerLimit (0U)
#  define Line_2_Curvature_adt_UpperLimit (65535U)

#  define Line_2_Heading_adt_LowerLimit (0U)
#  define Line_2_Heading_adt_UpperLimit (1023U)

#  define Line_2_Offset_adt_LowerLimit (0U)
#  define Line_2_Offset_adt_UpperLimit (1023U)

#  define Line_3_Curvature_Rate_adt_LowerLimit (0U)
#  define Line_3_Curvature_Rate_adt_UpperLimit (65535U)

#  define Line_3_Curvature_adt_LowerLimit (0U)
#  define Line_3_Curvature_adt_UpperLimit (65535U)

#  define Line_3_Heading_adt_LowerLimit (0U)
#  define Line_3_Heading_adt_UpperLimit (1023U)

#  define Line_3_Offset_adt_LowerLimit (0U)
#  define Line_3_Offset_adt_UpperLimit (1023U)

#  define Line_4_Curvature_Rate_adt_LowerLimit (0U)
#  define Line_4_Curvature_Rate_adt_UpperLimit (65535U)

#  define Line_4_Curvature_adt_LowerLimit (0U)
#  define Line_4_Curvature_adt_UpperLimit (65535U)

#  define Line_4_Heading_adt_LowerLimit (0U)
#  define Line_4_Heading_adt_UpperLimit (1023U)

#  define Line_4_Offset_adt_LowerLimit (0U)
#  define Line_4_Offset_adt_UpperLimit (1023U)

#  define LongAcceleration_BSM_adt_LowerLimit (0U)
#  define LongAcceleration_BSM_adt_UpperLimit (4095U)

#  define LongAcceleration_C2_adt_LowerLimit (0U)
#  define LongAcceleration_C2_adt_UpperLimit (4095U)

#  define LwsAngle_adt_LowerLimit (0U)
#  define LwsAngle_adt_UpperLimit (65535U)

#  define LwsSpeed_adt_LowerLimit (0U)
#  define LwsSpeed_adt_UpperLimit (4095U)

#  define PA_Line_LM_Distance_adt_LowerLimit (0U)
#  define PA_Line_LM_Distance_adt_UpperLimit (511U)

#  define PA_Line_LM_Heading_adt_LowerLimit (0U)
#  define PA_Line_LM_Heading_adt_UpperLimit (511U)

#  define PA_Line_RM_Distance_adt_LowerLimit (0U)
#  define PA_Line_RM_Distance_adt_UpperLimit (511U)

#  define PA_Line_RM_Heading_adt_LowerLimit (0U)
#  define PA_Line_RM_Heading_adt_UpperLimit (511U)

#  define PA_Obj1_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj1_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj1_Angle_adt_LowerLimit (0U)
#  define PA_Obj1_Angle_adt_UpperLimit (511U)

#  define PA_Obj1_Range_2_adt_LowerLimit (0U)
#  define PA_Obj1_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj1_Range_adt_LowerLimit (0U)
#  define PA_Obj1_Range_adt_UpperLimit (1023U)

#  define PA_Obj2_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj2_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj2_Angle_adt_LowerLimit (0U)
#  define PA_Obj2_Angle_adt_UpperLimit (511U)

#  define PA_Obj2_Range_2_adt_LowerLimit (0U)
#  define PA_Obj2_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj2_Range_adt_LowerLimit (0U)
#  define PA_Obj2_Range_adt_UpperLimit (1023U)

#  define PA_Obj3_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj3_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj3_Angle_adt_LowerLimit (0U)
#  define PA_Obj3_Angle_adt_UpperLimit (511U)

#  define PA_Obj3_Range_2_adt_LowerLimit (0U)
#  define PA_Obj3_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj3_Range_adt_LowerLimit (0U)
#  define PA_Obj3_Range_adt_UpperLimit (1023U)

#  define PA_Obj4_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj4_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj4_Angle_adt_LowerLimit (0U)
#  define PA_Obj4_Angle_adt_UpperLimit (511U)

#  define PA_Obj4_Range_2_adt_LowerLimit (0U)
#  define PA_Obj4_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj4_Range_adt_LowerLimit (0U)
#  define PA_Obj4_Range_adt_UpperLimit (1023U)

#  define PA_Obj5_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj5_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj5_Angle_adt_LowerLimit (0U)
#  define PA_Obj5_Angle_adt_UpperLimit (511U)

#  define PA_Obj5_Range_2_adt_LowerLimit (0U)
#  define PA_Obj5_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj5_Range_adt_LowerLimit (0U)
#  define PA_Obj5_Range_adt_UpperLimit (1023U)

#  define PA_Obj6_Angle_2_adt_LowerLimit (0U)
#  define PA_Obj6_Angle_2_adt_UpperLimit (511U)

#  define PA_Obj6_Angle_adt_LowerLimit (0U)
#  define PA_Obj6_Angle_adt_UpperLimit (511U)

#  define PA_Obj6_Range_2_adt_LowerLimit (0U)
#  define PA_Obj6_Range_2_adt_UpperLimit (1023U)

#  define PA_Obj6_Range_adt_LowerLimit (0U)
#  define PA_Obj6_Range_adt_UpperLimit (1023U)

#  define PA_SideSensor_FrontLeft_Dist_adt_LowerLimit (0U)
#  define PA_SideSensor_FrontLeft_Dist_adt_UpperLimit (1023U)

#  define PA_SideSensor_FrontRight_Dist_adt_LowerLimit (0U)
#  define PA_SideSensor_FrontRight_Dist_adt_UpperLimit (1023U)

#  define PA_SideSensor_RearLeft_Dist_adt_LowerLimit (0U)
#  define PA_SideSensor_RearLeft_Dist_adt_UpperLimit (1023U)

#  define PA_SideSensor_RearRight_Dist_adt_LowerLimit (0U)
#  define PA_SideSensor_RearRight_Dist_adt_UpperLimit (1023U)

#  define PitchRate_C2_adt_LowerLimit (0U)
#  define PitchRate_C2_adt_UpperLimit (4095U)

#  define REF_VEH_SPEED_adt_LowerLimit (0U)
#  define REF_VEH_SPEED_adt_UpperLimit (1023U)

#  define RHFWheelSpeed_adt_LowerLimit (0U)
#  define RHFWheelSpeed_adt_UpperLimit (8191U)

#  define RHRWheelSpeed_adt_LowerLimit (0U)
#  define RHRWheelSpeed_adt_UpperLimit (8191U)

#  define RR_PAM_Dist_adt_LowerLimit (0U)
#  define RR_PAM_Dist_adt_UpperLimit (1023U)

#  define RollRate_C2_adt_LowerLimit (0U)
#  define RollRate_C2_adt_UpperLimit (4095U)

#  define Segment_1_X1_adt_LowerLimit (0U)
#  define Segment_1_X1_adt_UpperLimit (2047U)

#  define Segment_1_X2_adt_LowerLimit (0U)
#  define Segment_1_X2_adt_UpperLimit (2047U)

#  define Segment_1_Y1_adt_LowerLimit (0U)
#  define Segment_1_Y1_adt_UpperLimit (1023U)

#  define Segment_1_Y2_adt_LowerLimit (0U)
#  define Segment_1_Y2_adt_UpperLimit (1023U)

#  define Segment_2_X1_adt_LowerLimit (0U)
#  define Segment_2_X1_adt_UpperLimit (2047U)

#  define Segment_2_X2_adt_LowerLimit (0U)
#  define Segment_2_X2_adt_UpperLimit (2047U)

#  define Segment_2_Y1_adt_LowerLimit (0U)
#  define Segment_2_Y1_adt_UpperLimit (1023U)

#  define Segment_2_Y2_adt_LowerLimit (0U)
#  define Segment_2_Y2_adt_UpperLimit (1023U)

#  define Segment_3_X1_adt_LowerLimit (0U)
#  define Segment_3_X1_adt_UpperLimit (2047U)

#  define Segment_3_X2_adt_LowerLimit (0U)
#  define Segment_3_X2_adt_UpperLimit (2047U)

#  define Segment_3_Y1_adt_LowerLimit (0U)
#  define Segment_3_Y1_adt_UpperLimit (1023U)

#  define Segment_3_Y2_adt_LowerLimit (0U)
#  define Segment_3_Y2_adt_UpperLimit (1023U)

#  define Segment_4_X1_adt_LowerLimit (0U)
#  define Segment_4_X1_adt_UpperLimit (2047U)

#  define Segment_4_X2_adt_LowerLimit (0U)
#  define Segment_4_X2_adt_UpperLimit (2047U)

#  define Segment_4_Y1_adt_LowerLimit (0U)
#  define Segment_4_Y1_adt_UpperLimit (1023U)

#  define Segment_4_Y2_adt_LowerLimit (0U)
#  define Segment_4_Y2_adt_UpperLimit (1023U)

#  define Segment_5_X1_adt_LowerLimit (0U)
#  define Segment_5_X1_adt_UpperLimit (2047U)

#  define Segment_5_X2_adt_LowerLimit (0U)
#  define Segment_5_X2_adt_UpperLimit (2047U)

#  define Segment_5_Y1_adt_LowerLimit (0U)
#  define Segment_5_Y1_adt_UpperLimit (1023U)

#  define Segment_5_Y2_adt_LowerLimit (0U)
#  define Segment_5_Y2_adt_UpperLimit (1023U)

#  define Segment_6_X1_adt_LowerLimit (0U)
#  define Segment_6_X1_adt_UpperLimit (2047U)

#  define Segment_6_X2_adt_LowerLimit (0U)
#  define Segment_6_X2_adt_UpperLimit (2047U)

#  define Segment_6_Y1_adt_LowerLimit (0U)
#  define Segment_6_Y1_adt_UpperLimit (1023U)

#  define Segment_6_Y2_adt_LowerLimit (0U)
#  define Segment_6_Y2_adt_UpperLimit (1023U)

#  define Segment_7_X1_adt_LowerLimit (0U)
#  define Segment_7_X1_adt_UpperLimit (2047U)

#  define Segment_7_X2_adt_LowerLimit (0U)
#  define Segment_7_X2_adt_UpperLimit (2047U)

#  define Segment_7_Y1_adt_LowerLimit (0U)
#  define Segment_7_Y1_adt_UpperLimit (1023U)

#  define Segment_7_Y2_adt_LowerLimit (0U)
#  define Segment_7_Y2_adt_UpperLimit (1023U)

#  define Segment_8_X1_adt_LowerLimit (0U)
#  define Segment_8_X1_adt_UpperLimit (2047U)

#  define Segment_8_X2_adt_LowerLimit (0U)
#  define Segment_8_X2_adt_UpperLimit (2047U)

#  define Segment_8_Y1_adt_LowerLimit (0U)
#  define Segment_8_Y1_adt_UpperLimit (1023U)

#  define Segment_8_Y2_adt_LowerLimit (0U)
#  define Segment_8_Y2_adt_UpperLimit (1023U)

#  define THA_SteeringTorqueInfo_adt_LowerLimit (0U)
#  define THA_SteeringTorqueInfo_adt_UpperLimit (2047U)

#  define TRSC_RawKnob_adt_LowerLimit (0U)
#  define TRSC_RawKnob_adt_UpperLimit (511U)

#  define TRSC_SteeringTorqueInfo_adt_LowerLimit (0U)
#  define TRSC_SteeringTorqueInfo_adt_UpperLimit (1023U)

#  define VehicleSpeedVSOSig_adt_LowerLimit (0U)
#  define VehicleSpeedVSOSig_adt_UpperLimit (8191U)

#  define VerticalAcceleration_C2_adt_LowerLimit (0U)
#  define VerticalAcceleration_C2_adt_UpperLimit (4095U)

#  define YawRate_BSM_adt_LowerLimit (0U)
#  define YawRate_BSM_adt_UpperLimit (4095U)

#  define YawRate_C2_adt_LowerLimit (0U)
#  define YawRate_C2_adt_UpperLimit (4095U)

#  ifndef Cx1FFF_SNA
#   define Cx1FFF_SNA (8191U)
#  endif

#  ifndef Cx1FF_SNA
#   define Cx1FF_SNA (511U)
#  endif

#  ifndef Cx3FF_SNA
#   define Cx3FF_SNA (1023U)
#  endif

#  ifndef Cx7FFF_SNA
#   define Cx7FFF_SNA (32767U)
#  endif

#  ifndef Cx7FF_SNA
#   define Cx7FF_SNA (2047U)
#  endif

#  ifndef CxFFFF_SNA
#   define CxFFFF_SNA (65535U)
#  endif

#  ifndef CxFFF_SNA
#   define CxFFF_SNA (4095U)
#  endif

#  define APARequestSts_adt_LowerLimit (0U)
#  define APARequestSts_adt_UpperLimit (1U)

#  define ASCM_Stat_adt_LowerLimit (0U)
#  define ASCM_Stat_adt_UpperLimit (15U)

#  define ASCM_SysFail_adt_LowerLimit (0U)
#  define ASCM_SysFail_adt_UpperLimit (1U)

#  define AUXCamsRQSts_adt_LowerLimit (0U)
#  define AUXCamsRQSts_adt_UpperLimit (1U)

#  define Active_Park_Mode_adt_LowerLimit (0U)
#  define Active_Park_Mode_adt_UpperLimit (1U)

#  define Alert_CHF_adt_LowerLimit (0U)
#  define Alert_CHF_adt_UpperLimit (7U)

#  define Alert_CHR_adt_LowerLimit (0U)
#  define Alert_CHR_adt_UpperLimit (7U)

#  define Alert_LHF_adt_LowerLimit (0U)
#  define Alert_LHF_adt_UpperLimit (7U)

#  define Alert_LHR_adt_LowerLimit (0U)
#  define Alert_LHR_adt_UpperLimit (7U)

#  define Alert_RHF_adt_LowerLimit (0U)
#  define Alert_RHF_adt_UpperLimit (7U)

#  define Alert_RHR_adt_LowerLimit (0U)
#  define Alert_RHR_adt_UpperLimit (7U)

#  define Altitude_RMSE_C2_adt_LowerLimit (0U)
#  define Altitude_RMSE_C2_adt_UpperLimit (255U)

#  define BSM_THA_Brk_Resp_adt_LowerLimit (0U)
#  define BSM_THA_Brk_Resp_adt_UpperLimit (3U)

#  define Backup_Cam_Delay_adt_LowerLimit (0U)
#  define Backup_Cam_Delay_adt_UpperLimit (1U)

#  define Brk_Stat_adt_LowerLimit (0U)
#  define Brk_Stat_adt_UpperLimit (3U)

#  define CM_TCH_STAT_adt_LowerLimit (0U)
#  define CM_TCH_STAT_adt_UpperLimit (7U)

#  define CRC_ADAS_INFO_C2_adt_LowerLimit (0U)
#  define CRC_ADAS_INFO_C2_adt_UpperLimit (255U)

#  define CRC_AGSM2_adt_LowerLimit (0U)
#  define CRC_AGSM2_adt_UpperLimit (255U)

#  define CRC_BCM10_adt_LowerLimit (0U)
#  define CRC_BCM10_adt_UpperLimit (255U)

#  define CRC_BCM12_adt_LowerLimit (0U)
#  define CRC_BCM12_adt_UpperLimit (255U)

#  define CRC_BCM27_adt_LowerLimit (0U)
#  define CRC_BCM27_adt_UpperLimit (255U)

#  define CRC_BCM29_adt_LowerLimit (0U)
#  define CRC_BCM29_adt_UpperLimit (255U)

#  define CRC_BCM2_adt_LowerLimit (0U)
#  define CRC_BCM2_adt_UpperLimit (255U)

#  define CRC_BCM9_adt_LowerLimit (0U)
#  define CRC_BCM9_adt_UpperLimit (255U)

#  define CRC_BRAKE1_adt_LowerLimit (0U)
#  define CRC_BRAKE1_adt_UpperLimit (255U)

#  define CRC_BRAKE2_1_adt_LowerLimit (0U)
#  define CRC_BRAKE2_1_adt_UpperLimit (255U)

#  define CRC_BRAKE2_adt_LowerLimit (0U)
#  define CRC_BRAKE2_adt_UpperLimit (255U)

#  define CRC_BRAKE4_adt_LowerLimit (0U)
#  define CRC_BRAKE4_adt_UpperLimit (255U)

#  define CRC_BRAKE5_adt_LowerLimit (0U)
#  define CRC_BRAKE5_adt_UpperLimit (255U)

#  define CRC_BRAKE7_adt_LowerLimit (0U)
#  define CRC_BRAKE7_adt_UpperLimit (255U)

#  define CRC_CVPAM_FD_Control_adt_LowerLimit (0U)
#  define CRC_CVPAM_FD_Control_adt_UpperLimit (255U)

#  define CRC_CVPAM_FD_Data2_adt_LowerLimit (0U)
#  define CRC_CVPAM_FD_Data2_adt_UpperLimit (255U)

#  define CRC_CVPAM_FD_Data_adt_LowerLimit (0U)
#  define CRC_CVPAM_FD_Data_adt_UpperLimit (255U)

#  define CRC_CVPAM_FD_Info_adt_LowerLimit (0U)
#  define CRC_CVPAM_FD_Info_adt_UpperLimit (255U)

#  define CRC_ENGINE2_adt_LowerLimit (0U)
#  define CRC_ENGINE2_adt_UpperLimit (255U)

#  define CRC_ENGINE5_adt_LowerLimit (0U)
#  define CRC_ENGINE5_adt_UpperLimit (255U)

#  define CRC_ENGINE7_adt_LowerLimit (0U)
#  define CRC_ENGINE7_adt_UpperLimit (255U)

#  define CRC_EPS1_adt_LowerLimit (0U)
#  define CRC_EPS1_adt_UpperLimit (255U)

#  define CRC_EPS2_adt_LowerLimit (0U)
#  define CRC_EPS2_adt_UpperLimit (255U)

#  define CRC_GLOB_NAV_C2_adt_LowerLimit (0U)
#  define CRC_GLOB_NAV_C2_adt_UpperLimit (255U)

#  define CRC_TRANSM1_adt_LowerLimit (0U)
#  define CRC_TRANSM1_adt_UpperLimit (255U)

#  define CRC_TRANSM2_adt_LowerLimit (0U)
#  define CRC_TRANSM2_adt_UpperLimit (255U)

#  define CRC_TRANSM4_adt_LowerLimit (0U)
#  define CRC_TRANSM4_adt_UpperLimit (255U)

#  define CRC_TRSCM1_adt_LowerLimit (0U)
#  define CRC_TRSCM1_adt_UpperLimit (255U)

#  define CRC_TRSKM_FD_1_adt_LowerLimit (0U)
#  define CRC_TRSKM_FD_1_adt_UpperLimit (255U)

#  define CRC_Telematic11_adt_LowerLimit (0U)
#  define CRC_Telematic11_adt_UpperLimit (255U)

#  define CRC_Telematic14_adt_LowerLimit (0U)
#  define CRC_Telematic14_adt_UpperLimit (255U)

#  define CRC_Telematic5_adt_LowerLimit (0U)
#  define CRC_Telematic5_adt_UpperLimit (255U)

#  define CRC__BRAKE3_adt_LowerLimit (0U)
#  define CRC__BRAKE3_adt_UpperLimit (255U)

#  define CRC__DRIVETRAIN3_adt_LowerLimit (0U)
#  define CRC__DRIVETRAIN3_adt_UpperLimit (255U)

#  define CameraDisplaySts2_adt_LowerLimit (0U)
#  define CameraDisplaySts2_adt_UpperLimit (15U)

#  define ChimeActivation_LHF_adt_LowerLimit (0U)
#  define ChimeActivation_LHF_adt_UpperLimit (1U)

#  define ChimeActivation_LHR_adt_LowerLimit (0U)
#  define ChimeActivation_LHR_adt_UpperLimit (1U)

#  define ChimeActivation_RHF_adt_LowerLimit (0U)
#  define ChimeActivation_RHF_adt_UpperLimit (1U)

#  define ChimeActivation_RHR_adt_LowerLimit (0U)
#  define ChimeActivation_RHR_adt_UpperLimit (1U)

#  define CmdIgnSts_adt_LowerLimit (0U)
#  define CmdIgnSts_adt_UpperLimit (7U)

#  define CurrentCanNMState_FD01_BCM_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD01_BCM_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD01_SGW_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD01_SGW_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_BCM_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_BCM_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_BSM2_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_BSM2_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_CADM2_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_CADM2_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_EPS_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_EPS_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_ORC_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_ORC_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_PAM_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_PAM_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_SGW_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_SGW_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD02_TRLR_REV_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD03_BCM_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD03_BCM_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD03_SGW_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD03_SGW_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD04_BCM_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD04_BCM_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD08_SGW_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD08_SGW_adt_UpperLimit (15U)

#  define CurrentCanNMState_FD11_SGW_adt_LowerLimit (0U)
#  define CurrentCanNMState_FD11_SGW_adt_UpperLimit (15U)

#  define CurrentFailSts_FD01_BCM_adt_LowerLimit (0U)
#  define CurrentFailSts_FD01_BCM_adt_UpperLimit (1U)

#  define CurrentFailSts_FD01_SGW_adt_LowerLimit (0U)
#  define CurrentFailSts_FD01_SGW_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_BCM_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_BCM_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_BSM2_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_BSM2_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_CADM2_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_CADM2_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_EPS_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_EPS_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_ORC_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_ORC_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_PAM_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_PAM_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_SGW_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_SGW_adt_UpperLimit (1U)

#  define CurrentFailSts_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define CurrentFailSts_FD02_TRLR_REV_adt_UpperLimit (1U)

#  define CurrentFailSts_FD03_BCM_adt_LowerLimit (0U)
#  define CurrentFailSts_FD03_BCM_adt_UpperLimit (1U)

#  define CurrentFailSts_FD03_SGW_adt_LowerLimit (0U)
#  define CurrentFailSts_FD03_SGW_adt_UpperLimit (1U)

#  define CurrentFailSts_FD04_BCM_adt_LowerLimit (0U)
#  define CurrentFailSts_FD04_BCM_adt_UpperLimit (1U)

#  define CurrentFailSts_FD08_SGW_adt_LowerLimit (0U)
#  define CurrentFailSts_FD08_SGW_adt_UpperLimit (1U)

#  define CurrentFailSts_FD11_SGW_adt_LowerLimit (0U)
#  define CurrentFailSts_FD11_SGW_adt_UpperLimit (1U)

#  define DES_FD01_BCM_adt_LowerLimit (0U)
#  define DES_FD01_BCM_adt_UpperLimit (3U)

#  define DES_FD01_SGW_adt_LowerLimit (0U)
#  define DES_FD01_SGW_adt_UpperLimit (3U)

#  define DES_FD02_BCM_adt_LowerLimit (0U)
#  define DES_FD02_BCM_adt_UpperLimit (3U)

#  define DES_FD02_BSM2_adt_LowerLimit (0U)
#  define DES_FD02_BSM2_adt_UpperLimit (3U)

#  define DES_FD02_CADM2_adt_LowerLimit (0U)
#  define DES_FD02_CADM2_adt_UpperLimit (3U)

#  define DES_FD02_EPS_adt_LowerLimit (0U)
#  define DES_FD02_EPS_adt_UpperLimit (3U)

#  define DES_FD02_ORC_adt_LowerLimit (0U)
#  define DES_FD02_ORC_adt_UpperLimit (3U)

#  define DES_FD02_PAM_adt_LowerLimit (0U)
#  define DES_FD02_PAM_adt_UpperLimit (3U)

#  define DES_FD02_SGW_adt_LowerLimit (0U)
#  define DES_FD02_SGW_adt_UpperLimit (3U)

#  define DES_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define DES_FD02_TRLR_REV_adt_UpperLimit (3U)

#  define DES_FD03_BCM_adt_LowerLimit (0U)
#  define DES_FD03_BCM_adt_UpperLimit (3U)

#  define DES_FD03_SGW_adt_LowerLimit (0U)
#  define DES_FD03_SGW_adt_UpperLimit (3U)

#  define DES_FD04_BCM_adt_LowerLimit (0U)
#  define DES_FD04_BCM_adt_UpperLimit (3U)

#  define DES_FD08_SGW_adt_LowerLimit (0U)
#  define DES_FD08_SGW_adt_UpperLimit (3U)

#  define DES_FD11_SGW_adt_LowerLimit (0U)
#  define DES_FD11_SGW_adt_UpperLimit (3U)

#  define DeltaTimestamp_IMUdata_adt_LowerLimit (0U)
#  define DeltaTimestamp_IMUdata_adt_UpperLimit (255U)

#  define Digit_01_PAM_adt_LowerLimit (0U)
#  define Digit_01_PAM_adt_UpperLimit (15U)

#  define Digit_01_adt_LowerLimit (0U)
#  define Digit_01_adt_UpperLimit (15U)

#  define Digit_02_PAM_adt_LowerLimit (0U)
#  define Digit_02_PAM_adt_UpperLimit (15U)

#  define Digit_02_adt_LowerLimit (0U)
#  define Digit_02_adt_UpperLimit (15U)

#  define Digit_03_PAM_adt_LowerLimit (0U)
#  define Digit_03_PAM_adt_UpperLimit (15U)

#  define Digit_03_adt_LowerLimit (0U)
#  define Digit_03_adt_UpperLimit (15U)

#  define Digit_04_PAM_adt_LowerLimit (0U)
#  define Digit_04_PAM_adt_UpperLimit (15U)

#  define Digit_04_adt_LowerLimit (0U)
#  define Digit_04_adt_UpperLimit (15U)

#  define Digit_05_PAM_adt_LowerLimit (0U)
#  define Digit_05_PAM_adt_UpperLimit (15U)

#  define Digit_05_adt_LowerLimit (0U)
#  define Digit_05_adt_UpperLimit (15U)

#  define Digit_06_PAM_adt_LowerLimit (0U)
#  define Digit_06_PAM_adt_UpperLimit (15U)

#  define Digit_06_adt_LowerLimit (0U)
#  define Digit_06_adt_UpperLimit (15U)

#  define Digit_07_PAM_adt_LowerLimit (0U)
#  define Digit_07_PAM_adt_UpperLimit (15U)

#  define Digit_07_adt_LowerLimit (0U)
#  define Digit_07_adt_UpperLimit (15U)

#  define Digit_08_PAM_adt_LowerLimit (0U)
#  define Digit_08_PAM_adt_UpperLimit (15U)

#  define Digit_08_adt_LowerLimit (0U)
#  define Digit_08_adt_UpperLimit (15U)

#  define Digit_09_PAM_adt_LowerLimit (0U)
#  define Digit_09_PAM_adt_UpperLimit (15U)

#  define Digit_09_adt_LowerLimit (0U)
#  define Digit_09_adt_UpperLimit (15U)

#  define Digit_10_PAM_adt_LowerLimit (0U)
#  define Digit_10_PAM_adt_UpperLimit (15U)

#  define Digit_10_adt_LowerLimit (0U)
#  define Digit_10_adt_UpperLimit (15U)

#  define Digit_11_PAM_adt_LowerLimit (0U)
#  define Digit_11_PAM_adt_UpperLimit (15U)

#  define Digit_11_adt_LowerLimit (0U)
#  define Digit_11_adt_UpperLimit (15U)

#  define DisplayView2_adt_LowerLimit (0U)
#  define DisplayView2_adt_UpperLimit (15U)

#  define DriverDoorSts_adt_LowerLimit (0U)
#  define DriverDoorSts_adt_UpperLimit (1U)

#  define DynamicGrid_adt_LowerLimit (0U)
#  define DynamicGrid_adt_UpperLimit (1U)

#  define ECM_THA_Resp_adt_LowerLimit (0U)
#  define ECM_THA_Resp_adt_UpperLimit (3U)

#  define ECM_TRSC_Resp_adt_LowerLimit (0U)
#  define ECM_TRSC_Resp_adt_UpperLimit (3U)

#  define EOL_FD01_BCM_adt_LowerLimit (0U)
#  define EOL_FD01_BCM_adt_UpperLimit (1U)

#  define EOL_FD01_SGW_adt_LowerLimit (0U)
#  define EOL_FD01_SGW_adt_UpperLimit (1U)

#  define EOL_FD02_BCM_adt_LowerLimit (0U)
#  define EOL_FD02_BCM_adt_UpperLimit (1U)

#  define EOL_FD02_BSM2_adt_LowerLimit (0U)
#  define EOL_FD02_BSM2_adt_UpperLimit (1U)

#  define EOL_FD02_CADM2_adt_LowerLimit (0U)
#  define EOL_FD02_CADM2_adt_UpperLimit (1U)

#  define EOL_FD02_EPS_adt_LowerLimit (0U)
#  define EOL_FD02_EPS_adt_UpperLimit (1U)

#  define EOL_FD02_ORC_adt_LowerLimit (0U)
#  define EOL_FD02_ORC_adt_UpperLimit (1U)

#  define EOL_FD02_PAM_adt_LowerLimit (0U)
#  define EOL_FD02_PAM_adt_UpperLimit (1U)

#  define EOL_FD02_SGW_adt_LowerLimit (0U)
#  define EOL_FD02_SGW_adt_UpperLimit (1U)

#  define EOL_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define EOL_FD02_TRLR_REV_adt_UpperLimit (1U)

#  define EOL_FD03_BCM_adt_LowerLimit (0U)
#  define EOL_FD03_BCM_adt_UpperLimit (1U)

#  define EOL_FD03_SGW_adt_LowerLimit (0U)
#  define EOL_FD03_SGW_adt_UpperLimit (1U)

#  define EOL_FD04_BCM_adt_LowerLimit (0U)
#  define EOL_FD04_BCM_adt_UpperLimit (1U)

#  define EOL_FD08_SGW_adt_LowerLimit (0U)
#  define EOL_FD08_SGW_adt_UpperLimit (1U)

#  define EOL_FD11_SGW_adt_LowerLimit (0U)
#  define EOL_FD11_SGW_adt_UpperLimit (1U)

#  define EPBSts_adt_LowerLimit (0U)
#  define EPBSts_adt_UpperLimit (15U)

#  define EPS_SteeringTouchStat_adt_LowerLimit (0U)
#  define EPS_SteeringTouchStat_adt_UpperLimit (1U)

#  define EPS_SteeringTouq_Resp_adt_LowerLimit (0U)
#  define EPS_SteeringTouq_Resp_adt_UpperLimit (3U)

#  define EPS_THA_DriverTorqueOverride_adt_LowerLimit (0U)
#  define EPS_THA_DriverTorqueOverride_adt_UpperLimit (3U)

#  define EPS_THA_SteeringTorqueResp_adt_LowerLimit (0U)
#  define EPS_THA_SteeringTorqueResp_adt_UpperLimit (7U)

#  define ESS_ENG_ST_W_adt_LowerLimit (0U)
#  define ESS_ENG_ST_W_adt_UpperLimit (15U)

#  define EngineSts_W_adt_LowerLimit (0U)
#  define EngineSts_W_adt_UpperLimit (3U)

#  define FD14_ACC_Systemsts_adt_LowerLimit (0U)
#  define FD14_ACC_Systemsts_adt_UpperLimit (15U)

#  define FD14_Accel_Pedal_Override_adt_LowerLimit (0U)
#  define FD14_Accel_Pedal_Override_adt_UpperLimit (1U)

#  define FD14_BSM_THA_Brk_Resp_adt_LowerLimit (0U)
#  define FD14_BSM_THA_Brk_Resp_adt_UpperLimit (3U)

#  define FD14_BrkPdl_Stat_adt_LowerLimit (0U)
#  define FD14_BrkPdl_Stat_adt_UpperLimit (3U)

#  define FD14_Brk_Stat_adt_LowerLimit (0U)
#  define FD14_Brk_Stat_adt_UpperLimit (3U)

#  define FD14_DriverReq_AxleTrq_Enabled_BSM_adt_LowerLimit (0U)
#  define FD14_DriverReq_AxleTrq_Enabled_BSM_adt_UpperLimit (15U)

#  define FD14_ECM_THA_Resp_adt_LowerLimit (0U)
#  define FD14_ECM_THA_Resp_adt_UpperLimit (3U)

#  define FD14_ECM_TRSC_Resp_adt_LowerLimit (0U)
#  define FD14_ECM_TRSC_Resp_adt_UpperLimit (3U)

#  define FD14_EPBSts_adt_LowerLimit (0U)
#  define FD14_EPBSts_adt_UpperLimit (15U)

#  define FD14_EPS_HandsOnRecognition_adt_LowerLimit (0U)
#  define FD14_EPS_HandsOnRecognition_adt_UpperLimit (1U)

#  define FD14_EPS_SteeringTouchStat_adt_LowerLimit (0U)
#  define FD14_EPS_SteeringTouchStat_adt_UpperLimit (1U)

#  define FD14_EPS_SteeringTouq_Resp_adt_LowerLimit (0U)
#  define FD14_EPS_SteeringTouq_Resp_adt_UpperLimit (3U)

#  define FD14_EPS_THA_DriverTorqueOverride_adt_LowerLimit (0U)
#  define FD14_EPS_THA_DriverTorqueOverride_adt_UpperLimit (3U)

#  define FD14_EPS_THA_SteeringTorqueResp_adt_LowerLimit (0U)
#  define FD14_EPS_THA_SteeringTorqueResp_adt_UpperLimit (7U)

#  define FD14_ESC_TRSC_Brk_Resp_adt_LowerLimit (0U)
#  define FD14_ESC_TRSC_Brk_Resp_adt_UpperLimit (3U)

#  define FD14_ESS_ENG_ST_W_adt_LowerLimit (0U)
#  define FD14_ESS_ENG_ST_W_adt_UpperLimit (15U)

#  define FD14_EngineSts_W_adt_LowerLimit (0U)
#  define FD14_EngineSts_W_adt_UpperLimit (3U)

#  define FD14_ExternalBrkRequestsDisabled_adt_LowerLimit (0U)
#  define FD14_ExternalBrkRequestsDisabled_adt_UpperLimit (3U)

#  define FD14_HAS_Status_adt_LowerLimit (0U)
#  define FD14_HAS_Status_adt_UpperLimit (3U)

#  define FD14_LHF_Spin_adt_LowerLimit (0U)
#  define FD14_LHF_Spin_adt_UpperLimit (3U)

#  define FD14_LHF_WheelSensorFailSts_adt_LowerLimit (0U)
#  define FD14_LHF_WheelSensorFailSts_adt_UpperLimit (1U)

#  define FD14_LHR_Spin_adt_LowerLimit (0U)
#  define FD14_LHR_Spin_adt_UpperLimit (3U)

#  define FD14_LHR_WheelSensorFailSts_adt_LowerLimit (0U)
#  define FD14_LHR_WheelSensorFailSts_adt_UpperLimit (1U)

#  define FD14_LatAccelerationFailSts_BSM_adt_LowerLimit (0U)
#  define FD14_LatAccelerationFailSts_BSM_adt_UpperLimit (1U)

#  define FD14_LongAccelerationFailSts_BSM_adt_LowerLimit (0U)
#  define FD14_LongAccelerationFailSts_BSM_adt_UpperLimit (1U)

#  define FD14_LwsAngleType_adt_LowerLimit (0U)
#  define FD14_LwsAngleType_adt_UpperLimit (3U)

#  define FD14_ManoeuvrePhase_adt_LowerLimit (0U)
#  define FD14_ManoeuvrePhase_adt_UpperLimit (1U)

#  define FD14_MessageCounter_ADAS_FD_INFO_adt_LowerLimit (0U)
#  define FD14_MessageCounter_ADAS_FD_INFO_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE1_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE1_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE2_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE2_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE3_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE3_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE4_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE4_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE5_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE5_adt_UpperLimit (15U)

#  define FD14_MessageCounter_BRAKE7_adt_LowerLimit (0U)
#  define FD14_MessageCounter_BRAKE7_adt_UpperLimit (15U)

#  define FD14_MessageCounter_CVPAM_FD_Control_adt_LowerLimit (0U)
#  define FD14_MessageCounter_CVPAM_FD_Control_adt_UpperLimit (15U)

#  define FD14_MessageCounter_ENGINE2_adt_LowerLimit (0U)
#  define FD14_MessageCounter_ENGINE2_adt_UpperLimit (15U)

#  define FD14_MessageCounter_ENGINE7_adt_LowerLimit (0U)
#  define FD14_MessageCounter_ENGINE7_adt_UpperLimit (15U)

#  define FD14_MessageCounter_EPS1_adt_LowerLimit (0U)
#  define FD14_MessageCounter_EPS1_adt_UpperLimit (15U)

#  define FD14_MessageCounter_EPS2_adt_LowerLimit (0U)
#  define FD14_MessageCounter_EPS2_adt_UpperLimit (15U)

#  define FD14_PAM_Brk_Rq_RspSts_adt_LowerLimit (0U)
#  define FD14_PAM_Brk_Rq_RspSts_adt_UpperLimit (3U)

#  define FD14_PA_Front_Sensor_Det_Health_adt_LowerLimit (0U)
#  define FD14_PA_Front_Sensor_Det_Health_adt_UpperLimit (3U)

#  define FD14_PA_Lane_Dection_Health_adt_LowerLimit (0U)
#  define FD14_PA_Lane_Dection_Health_adt_UpperLimit (3U)

#  define FD14_PA_Left_Sensor_Det_Health_adt_LowerLimit (0U)
#  define FD14_PA_Left_Sensor_Det_Health_adt_UpperLimit (3U)

#  define FD14_PA_Line_LM_Color_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Color_adt_UpperLimit (7U)

#  define FD14_PA_Line_LM_Distance_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Distance_Conf_adt_UpperLimit (15U)

#  define FD14_PA_Line_LM_Heading_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Heading_Conf_adt_UpperLimit (15U)

#  define FD14_PA_Line_LM_Style_adt_LowerLimit (0U)
#  define FD14_PA_Line_LM_Style_adt_UpperLimit (15U)

#  define FD14_PA_Line_RM_Color_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Color_adt_UpperLimit (7U)

#  define FD14_PA_Line_RM_Distance_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Distance_Conf_adt_UpperLimit (15U)

#  define FD14_PA_Line_RM_Heading_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Heading_Conf_adt_UpperLimit (15U)

#  define FD14_PA_Line_RM_Style_adt_LowerLimit (0U)
#  define FD14_PA_Line_RM_Style_adt_UpperLimit (15U)

#  define FD14_PA_Obj1_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj1_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj1_Type_adt_UpperLimit (7U)

#  define FD14_PA_Obj2_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj2_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj2_Type_adt_UpperLimit (7U)

#  define FD14_PA_Obj3_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj3_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj3_Type_adt_UpperLimit (7U)

#  define FD14_PA_Obj4_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj4_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj4_Type_adt_UpperLimit (7U)

#  define FD14_PA_Obj5_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj5_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj5_Type_adt_UpperLimit (7U)

#  define FD14_PA_Obj6_Conf_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Conf_adt_UpperLimit (3U)

#  define FD14_PA_Obj6_Type_adt_LowerLimit (0U)
#  define FD14_PA_Obj6_Type_adt_UpperLimit (7U)

#  define FD14_PA_Right_Sensor_Det_Health_adt_LowerLimit (0U)
#  define FD14_PA_Right_Sensor_Det_Health_adt_UpperLimit (3U)

#  define FD14_PA_SideSensor_FrontLeft_Conf_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_FrontLeft_Conf_adt_UpperLimit (3U)

#  define FD14_PA_SideSensor_FrontRight_Conf_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_FrontRight_Conf_adt_UpperLimit (3U)

#  define FD14_PA_SideSensor_RearLeft_Conf_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_RearLeft_Conf_adt_UpperLimit (3U)

#  define FD14_PA_SideSensor_RearRight_Conf_adt_LowerLimit (0U)
#  define FD14_PA_SideSensor_RearRight_Conf_adt_UpperLimit (3U)

#  define FD14_PPPA_AccelMax_adt_LowerLimit (0U)
#  define FD14_PPPA_AccelMax_adt_UpperLimit (31U)

#  define FD14_PPPA_AccelMin_adt_LowerLimit (0U)
#  define FD14_PPPA_AccelMin_adt_UpperLimit (31U)

#  define FD14_PPPA_DecelMax_adt_LowerLimit (0U)
#  define FD14_PPPA_DecelMax_adt_UpperLimit (31U)

#  define FD14_PPPA_DecelMin_adt_LowerLimit (0U)
#  define FD14_PPPA_DecelMin_adt_UpperLimit (31U)

#  define FD14_PPPA_Interface_BSM_adt_LowerLimit (0U)
#  define FD14_PPPA_Interface_BSM_adt_UpperLimit (3U)

#  define FD14_PPPA_JerkAccelMax_adt_LowerLimit (0U)
#  define FD14_PPPA_JerkAccelMax_adt_UpperLimit (63U)

#  define FD14_PPPA_JerkAccelMin_adt_LowerLimit (0U)
#  define FD14_PPPA_JerkAccelMin_adt_UpperLimit (63U)

#  define FD14_PPPA_JerkDecelMax_adt_LowerLimit (0U)
#  define FD14_PPPA_JerkDecelMax_adt_UpperLimit (63U)

#  define FD14_PPPA_JerkDecelMin_adt_LowerLimit (0U)
#  define FD14_PPPA_JerkDecelMin_adt_UpperLimit (63U)

#  define FD14_PPPA_StandstillRqst_adt_LowerLimit (0U)
#  define FD14_PPPA_StandstillRqst_adt_UpperLimit (1U)

#  define FD14_PPPA_TrqEnblRq_Allowed_adt_LowerLimit (0U)
#  define FD14_PPPA_TrqEnblRq_Allowed_adt_UpperLimit (1U)

#  define FD14_ParkingGearShiftReq_BSM_adt_LowerLimit (0U)
#  define FD14_ParkingGearShiftReq_BSM_adt_UpperLimit (7U)

#  define FD14_ParkingGearShiftReq_adt_LowerLimit (0U)
#  define FD14_ParkingGearShiftReq_adt_UpperLimit (7U)

#  define FD14_ParkingInterventionSts_adt_LowerLimit (0U)
#  define FD14_ParkingInterventionSts_adt_UpperLimit (3U)

#  define FD14_ParkingManeuverActive_adt_LowerLimit (0U)
#  define FD14_ParkingManeuverActive_adt_UpperLimit (7U)

#  define FD14_RHF_Spin_adt_LowerLimit (0U)
#  define FD14_RHF_Spin_adt_UpperLimit (3U)

#  define FD14_RHF_WheelSensorFailSts_adt_LowerLimit (0U)
#  define FD14_RHF_WheelSensorFailSts_adt_UpperLimit (1U)

#  define FD14_RHR_Spin_adt_LowerLimit (0U)
#  define FD14_RHR_Spin_adt_UpperLimit (3U)

#  define FD14_RHR_WheelSensorFailSts_adt_LowerLimit (0U)
#  define FD14_RHR_WheelSensorFailSts_adt_UpperLimit (1U)

#  define FD14_RR_PAM_Brk_RqSts_adt_LowerLimit (0U)
#  define FD14_RR_PAM_Brk_RqSts_adt_UpperLimit (1U)

#  define FD14_SPM_Lat_Ctrl_RequestSts_adt_LowerLimit (0U)
#  define FD14_SPM_Lat_Ctrl_RequestSts_adt_UpperLimit (3U)

#  define FD14_SPM_Lat_Ctrl_ResponseSts_adt_LowerLimit (0U)
#  define FD14_SPM_Lat_Ctrl_ResponseSts_adt_UpperLimit (3U)

#  define FD14_THA_EPB_Req_adt_LowerLimit (0U)
#  define FD14_THA_EPB_Req_adt_UpperLimit (3U)

#  define FD14_THA_STAT_adt_LowerLimit (0U)
#  define FD14_THA_STAT_adt_UpperLimit (7U)

#  define FD14_THA_SpeedLimit_Req_adt_LowerLimit (0U)
#  define FD14_THA_SpeedLimit_Req_adt_UpperLimit (3U)

#  define FD14_THA_Speed_Limit_adt_LowerLimit (0U)
#  define FD14_THA_Speed_Limit_adt_UpperLimit (31U)

#  define FD14_THA_SteeringTorqueReq_adt_LowerLimit (0U)
#  define FD14_THA_SteeringTorqueReq_adt_UpperLimit (3U)

#  define FD14_THA_SteeringTouchStat_adt_LowerLimit (0U)
#  define FD14_THA_SteeringTouchStat_adt_UpperLimit (3U)

#  define FD14_TRSC_STAT_adt_LowerLimit (0U)
#  define FD14_TRSC_STAT_adt_UpperLimit (7U)

#  define FD14_TRSC_SpeedLimit_Req_adt_LowerLimit (0U)
#  define FD14_TRSC_SpeedLimit_Req_adt_UpperLimit (15U)

#  define FD14_TRSC_SteeringTorqueReq_adt_LowerLimit (0U)
#  define FD14_TRSC_SteeringTorqueReq_adt_UpperLimit (3U)

#  define FD14_TRSC_VehicleStop_Req_adt_LowerLimit (0U)
#  define FD14_TRSC_VehicleStop_Req_adt_UpperLimit (3U)

#  define FD14_VehicleStandStillSts_adt_LowerLimit (0U)
#  define FD14_VehicleStandStillSts_adt_UpperLimit (3U)

#  define FD14_YawRateFailSts_BSM_adt_LowerLimit (0U)
#  define FD14_YawRateFailSts_BSM_adt_UpperLimit (1U)

#  define FL_Lvl_Adj_adt_LowerLimit (0U)
#  define FL_Lvl_Adj_adt_UpperLimit (1U)

#  define FL_Lvl_adt_LowerLimit (0U)
#  define FL_Lvl_adt_UpperLimit (255U)

#  define FR_Lvl_Adj_adt_LowerLimit (0U)
#  define FR_Lvl_Adj_adt_UpperLimit (1U)

#  define FR_Lvl_adt_LowerLimit (0U)
#  define FR_Lvl_adt_UpperLimit (255U)

#  define FT_PAMRequestSts_adt_LowerLimit (0U)
#  define FT_PAMRequestSts_adt_UpperLimit (1U)

#  define FT_PAM_LedControlSts_adt_LowerLimit (0U)
#  define FT_PAM_LedControlSts_adt_UpperLimit (3U)

#  define FrontSensorSts_adt_LowerLimit (0U)
#  define FrontSensorSts_adt_UpperLimit (3U)

#  define Fwrd_Cam_Guidelines_adt_LowerLimit (0U)
#  define Fwrd_Cam_Guidelines_adt_UpperLimit (1U)

#  define GearEngagedForDisplay_adt_LowerLimit (0U)
#  define GearEngagedForDisplay_adt_UpperLimit (31U)

#  define GearEngaged_adt_LowerLimit (0U)
#  define GearEngaged_adt_UpperLimit (15U)

#  define GenericFailSts_FD01_BCM_adt_LowerLimit (0U)
#  define GenericFailSts_FD01_BCM_adt_UpperLimit (1U)

#  define GenericFailSts_FD01_SGW_adt_LowerLimit (0U)
#  define GenericFailSts_FD01_SGW_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_BCM_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_BCM_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_BSM2_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_BSM2_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_CADM2_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_CADM2_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_EPS_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_EPS_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_ORC_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_ORC_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_PAM_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_PAM_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_SGW_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_SGW_adt_UpperLimit (1U)

#  define GenericFailSts_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define GenericFailSts_FD02_TRLR_REV_adt_UpperLimit (1U)

#  define GenericFailSts_FD03_BCM_adt_LowerLimit (0U)
#  define GenericFailSts_FD03_BCM_adt_UpperLimit (1U)

#  define GenericFailSts_FD03_SGW_adt_LowerLimit (0U)
#  define GenericFailSts_FD03_SGW_adt_UpperLimit (1U)

#  define GenericFailSts_FD04_BCM_adt_LowerLimit (0U)
#  define GenericFailSts_FD04_BCM_adt_UpperLimit (1U)

#  define GenericFailSts_FD08_SGW_adt_LowerLimit (0U)
#  define GenericFailSts_FD08_SGW_adt_UpperLimit (1U)

#  define GenericFailSts_FD11_SGW_adt_LowerLimit (0U)
#  define GenericFailSts_FD11_SGW_adt_UpperLimit (1U)

#  define Graphic_CHF_adt_LowerLimit (0U)
#  define Graphic_CHF_adt_UpperLimit (3U)

#  define Graphic_CHR_adt_LowerLimit (0U)
#  define Graphic_CHR_adt_UpperLimit (3U)

#  define Graphic_LHF_adt_LowerLimit (0U)
#  define Graphic_LHF_adt_UpperLimit (3U)

#  define Graphic_LHR_adt_LowerLimit (0U)
#  define Graphic_LHR_adt_UpperLimit (3U)

#  define Graphic_RHF_adt_LowerLimit (0U)
#  define Graphic_RHF_adt_UpperLimit (3U)

#  define Graphic_RHR_adt_LowerLimit (0U)
#  define Graphic_RHR_adt_UpperLimit (3U)

#  define HAS_Status_C2_adt_LowerLimit (0U)
#  define HAS_Status_C2_adt_UpperLimit (3U)

#  define HMICode_adt_LowerLimit (0U)
#  define HMICode_adt_UpperLimit (255U)

#  define HU_TRSC_EnableBtn_Sts_adt_LowerLimit (0U)
#  define HU_TRSC_EnableBtn_Sts_adt_UpperLimit (2U)

#  define ITBM_TrlrStat_adt_LowerLimit (0U)
#  define ITBM_TrlrStat_adt_UpperLimit (3U)

#  define ImageDefeatRQSts_adt_LowerLimit (0U)
#  define ImageDefeatRQSts_adt_UpperLimit (1U)

#  define LHF_FastPulseCounter_adt_LowerLimit (0U)
#  define LHF_FastPulseCounter_adt_UpperLimit (255U)

#  define LHF_Spin_adt_LowerLimit (0U)
#  define LHF_Spin_adt_UpperLimit (3U)

#  define LHRDoorSts_adt_LowerLimit (0U)
#  define LHRDoorSts_adt_UpperLimit (1U)

#  define LHR_FastPulseCounter_adt_LowerLimit (0U)
#  define LHR_FastPulseCounter_adt_UpperLimit (255U)

#  define LHR_Spin_adt_LowerLimit (0U)
#  define LHR_Spin_adt_UpperLimit (3U)

#  define LanguageSelection_adt_LowerLimit (0U)
#  define LanguageSelection_adt_UpperLimit (255U)

#  define LatAccelerationOffset_BSM_adt_LowerLimit (0U)
#  define LatAccelerationOffset_BSM_adt_UpperLimit (255U)

#  define Latitude_RMSE_C2_adt_LowerLimit (0U)
#  define Latitude_RMSE_C2_adt_UpperLimit (255U)

#  define Line_1_Confidence_adt_LowerLimit (0U)
#  define Line_1_Confidence_adt_UpperLimit (15U)

#  define Line_1_End_Range_adt_LowerLimit (0U)
#  define Line_1_End_Range_adt_UpperLimit (127U)

#  define Line_1_Start_Range_adt_LowerLimit (0U)
#  define Line_1_Start_Range_adt_UpperLimit (127U)

#  define Line_2_Confidence_adt_LowerLimit (0U)
#  define Line_2_Confidence_adt_UpperLimit (15U)

#  define Line_2_End_Range_adt_LowerLimit (0U)
#  define Line_2_End_Range_adt_UpperLimit (127U)

#  define Line_2_Start_Range_adt_LowerLimit (0U)
#  define Line_2_Start_Range_adt_UpperLimit (127U)

#  define Line_3_Confidence_adt_LowerLimit (0U)
#  define Line_3_Confidence_adt_UpperLimit (15U)

#  define Line_3_End_Range_adt_LowerLimit (0U)
#  define Line_3_End_Range_adt_UpperLimit (127U)

#  define Line_3_Start_Range_adt_LowerLimit (0U)
#  define Line_3_Start_Range_adt_UpperLimit (127U)

#  define Line_4_Confidence_adt_LowerLimit (0U)
#  define Line_4_Confidence_adt_UpperLimit (15U)

#  define Line_4_End_Range_adt_LowerLimit (0U)
#  define Line_4_End_Range_adt_UpperLimit (127U)

#  define Line_4_Start_Range_adt_LowerLimit (0U)
#  define Line_4_Start_Range_adt_UpperLimit (127U)

#  define LongAccelerationOffset_BSM_adt_LowerLimit (0U)
#  define LongAccelerationOffset_BSM_adt_UpperLimit (255U)

#  define Longitude_RMSE_C2_adt_LowerLimit (0U)
#  define Longitude_RMSE_C2_adt_UpperLimit (255U)

#  define LwsAngleType_adt_LowerLimit (0U)
#  define LwsAngleType_adt_UpperLimit (3U)

#  define MRM_STATUS_C2_adt_LowerLimit (0U)
#  define MRM_STATUS_C2_adt_UpperLimit (7U)

#  define MessageCounter_ADAS_INFO_C2_adt_LowerLimit (0U)
#  define MessageCounter_ADAS_INFO_C2_adt_UpperLimit (15U)

#  define MessageCounter_AGSM2_adt_LowerLimit (0U)
#  define MessageCounter_AGSM2_adt_UpperLimit (15U)

#  define MessageCounter_BCM10_adt_LowerLimit (0U)
#  define MessageCounter_BCM10_adt_UpperLimit (15U)

#  define MessageCounter_BCM12_adt_LowerLimit (0U)
#  define MessageCounter_BCM12_adt_UpperLimit (15U)

#  define MessageCounter_BCM27_adt_LowerLimit (0U)
#  define MessageCounter_BCM27_adt_UpperLimit (15U)

#  define MessageCounter_BCM29_adt_LowerLimit (0U)
#  define MessageCounter_BCM29_adt_UpperLimit (15U)

#  define MessageCounter_BCM2_adt_LowerLimit (0U)
#  define MessageCounter_BCM2_adt_UpperLimit (15U)

#  define MessageCounter_BCM9_adt_LowerLimit (0U)
#  define MessageCounter_BCM9_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE1_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE1_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE2_1_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE2_1_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE2_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE2_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE3_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE3_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE4_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE4_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE5_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE5_adt_UpperLimit (15U)

#  define MessageCounter_BRAKE7_adt_LowerLimit (0U)
#  define MessageCounter_BRAKE7_adt_UpperLimit (15U)

#  define MessageCounter_CVPAM_FD_Control_adt_LowerLimit (0U)
#  define MessageCounter_CVPAM_FD_Control_adt_UpperLimit (15U)

#  define MessageCounter_CVPAM_FD_Data2_adt_LowerLimit (0U)
#  define MessageCounter_CVPAM_FD_Data2_adt_UpperLimit (15U)

#  define MessageCounter_CVPAM_FD_Data_adt_LowerLimit (0U)
#  define MessageCounter_CVPAM_FD_Data_adt_UpperLimit (15U)

#  define MessageCounter_CVPAM_FD_Info_adt_LowerLimit (0U)
#  define MessageCounter_CVPAM_FD_Info_adt_UpperLimit (15U)

#  define MessageCounter_DRIVETRAIN3_adt_LowerLimit (0U)
#  define MessageCounter_DRIVETRAIN3_adt_UpperLimit (15U)

#  define MessageCounter_ENGINE2_adt_LowerLimit (0U)
#  define MessageCounter_ENGINE2_adt_UpperLimit (15U)

#  define MessageCounter_ENGINE5_adt_LowerLimit (0U)
#  define MessageCounter_ENGINE5_adt_UpperLimit (15U)

#  define MessageCounter_ENGINE7_adt_LowerLimit (0U)
#  define MessageCounter_ENGINE7_adt_UpperLimit (15U)

#  define MessageCounter_EPS1_adt_LowerLimit (0U)
#  define MessageCounter_EPS1_adt_UpperLimit (15U)

#  define MessageCounter_EPS2_adt_LowerLimit (0U)
#  define MessageCounter_EPS2_adt_UpperLimit (15U)

#  define MessageCounter_GLOB_NAV_C2_adt_LowerLimit (0U)
#  define MessageCounter_GLOB_NAV_C2_adt_UpperLimit (15U)

#  define MessageCounter_TRANSM1_adt_LowerLimit (0U)
#  define MessageCounter_TRANSM1_adt_UpperLimit (15U)

#  define MessageCounter_TRANSM2_adt_LowerLimit (0U)
#  define MessageCounter_TRANSM2_adt_UpperLimit (15U)

#  define MessageCounter_TRANSM4_adt_LowerLimit (0U)
#  define MessageCounter_TRANSM4_adt_UpperLimit (15U)

#  define MessageCounter_TRSCM1_adt_LowerLimit (0U)
#  define MessageCounter_TRSCM1_adt_UpperLimit (15U)

#  define MessageCounter_TRSKM_FD_1_adt_LowerLimit (0U)
#  define MessageCounter_TRSKM_FD_1_adt_UpperLimit (15U)

#  define MessageCounter_Telematic11_adt_LowerLimit (0U)
#  define MessageCounter_Telematic11_adt_UpperLimit (15U)

#  define MessageCounter_Telematic14_adt_LowerLimit (0U)
#  define MessageCounter_Telematic14_adt_UpperLimit (15U)

#  define MessageCounter_Telematic5_adt_LowerLimit (0U)
#  define MessageCounter_Telematic5_adt_UpperLimit (15U)

#  define MoreCamsRQSts_adt_LowerLimit (0U)
#  define MoreCamsRQSts_adt_UpperLimit (1U)

#  define OperationalModeSts_adt_LowerLimit (0U)
#  define OperationalModeSts_adt_UpperLimit (15U)

#  define PAMRequestSts_adt_LowerLimit (0U)
#  define PAMRequestSts_adt_UpperLimit (1U)

#  define PAMSystemFault_adt_LowerLimit (0U)
#  define PAMSystemFault_adt_UpperLimit (3U)

#  define PAM_CHIME_REP_RATESts_adt_LowerLimit (0U)
#  define PAM_CHIME_REP_RATESts_adt_UpperLimit (15U)

#  define PAM_CHIME_TYPE_adt_LowerLimit (0U)
#  define PAM_CHIME_TYPE_adt_UpperLimit (15U)

#  define PAM_LedControlSts_adt_LowerLimit (0U)
#  define PAM_LedControlSts_adt_UpperLimit (3U)

#  define PAM_Off_Status_2BT_adt_LowerLimit (0U)
#  define PAM_Off_Status_2BT_adt_UpperLimit (3U)

#  define PAM_Off_Status_adt_LowerLimit (0U)
#  define PAM_Off_Status_adt_UpperLimit (1U)

#  define PAM_PopUpRqst_adt_LowerLimit (0U)
#  define PAM_PopUpRqst_adt_UpperLimit (255U)

#  define PAM_Volume_adt_LowerLimit (0U)
#  define PAM_Volume_adt_UpperLimit (3U)

#  define PA_Front_Sensor_Det_Health_adt_LowerLimit (0U)
#  define PA_Front_Sensor_Det_Health_adt_UpperLimit (3U)

#  define PA_Lane_Dection_Health_adt_LowerLimit (0U)
#  define PA_Lane_Dection_Health_adt_UpperLimit (3U)

#  define PA_Left_Sensor_Det_Health_adt_LowerLimit (0U)
#  define PA_Left_Sensor_Det_Health_adt_UpperLimit (3U)

#  define PA_Line_LM_Color_adt_LowerLimit (0U)
#  define PA_Line_LM_Color_adt_UpperLimit (4U)

#  define PA_Line_LM_Distance_Conf_adt_LowerLimit (0U)
#  define PA_Line_LM_Distance_Conf_adt_UpperLimit (15U)

#  define PA_Line_LM_Heading_Conf_adt_LowerLimit (0U)
#  define PA_Line_LM_Heading_Conf_adt_UpperLimit (15U)

#  define PA_Line_LM_Style_adt_LowerLimit (0U)
#  define PA_Line_LM_Style_adt_UpperLimit (7U)

#  define PA_Line_RM_Color_adt_LowerLimit (0U)
#  define PA_Line_RM_Color_adt_UpperLimit (4U)

#  define PA_Line_RM_Distance_Conf_adt_LowerLimit (0U)
#  define PA_Line_RM_Distance_Conf_adt_UpperLimit (15U)

#  define PA_Line_RM_Heading_Conf_adt_LowerLimit (0U)
#  define PA_Line_RM_Heading_Conf_adt_UpperLimit (15U)

#  define PA_Line_RM_Style_adt_LowerLimit (0U)
#  define PA_Line_RM_Style_adt_UpperLimit (7U)

#  define PA_Obj1_Conf_adt_LowerLimit (0U)
#  define PA_Obj1_Conf_adt_UpperLimit (3U)

#  define PA_Obj1_Type_adt_LowerLimit (0U)
#  define PA_Obj1_Type_adt_UpperLimit (7U)

#  define PA_Obj2_Conf_adt_LowerLimit (0U)
#  define PA_Obj2_Conf_adt_UpperLimit (3U)

#  define PA_Obj2_Type_adt_LowerLimit (0U)
#  define PA_Obj2_Type_adt_UpperLimit (7U)

#  define PA_Obj3_Conf_adt_LowerLimit (0U)
#  define PA_Obj3_Conf_adt_UpperLimit (3U)

#  define PA_Obj3_Type_adt_LowerLimit (0U)
#  define PA_Obj3_Type_adt_UpperLimit (7U)

#  define PA_Obj4_Conf_adt_LowerLimit (0U)
#  define PA_Obj4_Conf_adt_UpperLimit (3U)

#  define PA_Obj4_Type_adt_LowerLimit (0U)
#  define PA_Obj4_Type_adt_UpperLimit (7U)

#  define PA_Obj5_Conf_adt_LowerLimit (0U)
#  define PA_Obj5_Conf_adt_UpperLimit (3U)

#  define PA_Obj5_Type_adt_LowerLimit (0U)
#  define PA_Obj5_Type_adt_UpperLimit (7U)

#  define PA_Obj6_Conf_adt_LowerLimit (0U)
#  define PA_Obj6_Conf_adt_UpperLimit (3U)

#  define PA_Obj6_Type_adt_LowerLimit (0U)
#  define PA_Obj6_Type_adt_UpperLimit (7U)

#  define PA_Right_Sensor_Det_Health_adt_LowerLimit (0U)
#  define PA_Right_Sensor_Det_Health_adt_UpperLimit (3U)

#  define PA_SideSensor_FrontLeft_Conf_adt_LowerLimit (0U)
#  define PA_SideSensor_FrontLeft_Conf_adt_UpperLimit (3U)

#  define PA_SideSensor_FrontRight_Conf_adt_LowerLimit (0U)
#  define PA_SideSensor_FrontRight_Conf_adt_UpperLimit (3U)

#  define PA_SideSensor_RearLeft_Conf_adt_LowerLimit (0U)
#  define PA_SideSensor_RearLeft_Conf_adt_UpperLimit (3U)

#  define PA_SideSensor_RearRight_Conf_adt_LowerLimit (0U)
#  define PA_SideSensor_RearRight_Conf_adt_UpperLimit (3U)

#  define PPPA_TurnIndicatorRqst_adt_LowerLimit (0U)
#  define PPPA_TurnIndicatorRqst_adt_UpperLimit (3U)

#  define PamChimeVolumeFront_adt_LowerLimit (0U)
#  define PamChimeVolumeFront_adt_UpperLimit (3U)

#  define PamChimeVolumeRear_adt_LowerLimit (0U)
#  define PamChimeVolumeRear_adt_UpperLimit (3U)

#  define ParkingManeuverActive_adt_LowerLimit (0U)
#  define ParkingManeuverActive_adt_UpperLimit (7U)

#  define PdlPosActual_adt_LowerLimit (0U)
#  define PdlPosActual_adt_UpperLimit (255U)

#  define Pitch_RMSE_C2_adt_LowerLimit (0U)
#  define Pitch_RMSE_C2_adt_UpperLimit (255U)

#  define PreviousCanNMState_FD01_BCM_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD01_BCM_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD01_SGW_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD01_SGW_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_BCM_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_BCM_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_BSM2_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_BSM2_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_CADM2_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_CADM2_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_EPS_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_EPS_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_ORC_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_ORC_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_PAM_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_PAM_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_SGW_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_SGW_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD02_TRLR_REV_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD03_BCM_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD03_BCM_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD03_SGW_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD03_SGW_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD04_BCM_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD04_BCM_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD08_SGW_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD08_SGW_adt_UpperLimit (15U)

#  define PreviousCanNMState_FD11_SGW_adt_LowerLimit (0U)
#  define PreviousCanNMState_FD11_SGW_adt_UpperLimit (15U)

#  define PsngrDoorSts_adt_LowerLimit (0U)
#  define PsngrDoorSts_adt_UpperLimit (1U)

#  define RHF_FastPulseCounter_adt_LowerLimit (0U)
#  define RHF_FastPulseCounter_adt_UpperLimit (255U)

#  define RHF_Spin_adt_LowerLimit (0U)
#  define RHF_Spin_adt_UpperLimit (3U)

#  define RHRDoorSts_adt_LowerLimit (0U)
#  define RHRDoorSts_adt_UpperLimit (1U)

#  define RHR_FastPulseCounter_adt_LowerLimit (0U)
#  define RHR_FastPulseCounter_adt_UpperLimit (255U)

#  define RHR_Spin_adt_LowerLimit (0U)
#  define RHR_Spin_adt_UpperLimit (3U)

#  define RHatchSts_adt_LowerLimit (0U)
#  define RHatchSts_adt_UpperLimit (1U)

#  define RL_Lvl_Adj_adt_LowerLimit (0U)
#  define RL_Lvl_Adj_adt_UpperLimit (1U)

#  define RL_Lvl_adt_LowerLimit (0U)
#  define RL_Lvl_adt_UpperLimit (255U)

#  define RR_Lvl_Adj_adt_LowerLimit (0U)
#  define RR_Lvl_Adj_adt_UpperLimit (1U)

#  define RR_Lvl_adt_LowerLimit (0U)
#  define RR_Lvl_adt_UpperLimit (255U)

#  define RR_PAM_Brk_RqSts_adt_LowerLimit (0U)
#  define RR_PAM_Brk_RqSts_adt_UpperLimit (1U)

#  define RR_PAM_StopControlSts_adt_LowerLimit (0U)
#  define RR_PAM_StopControlSts_adt_UpperLimit (1U)

#  define RearSensorSts_adt_LowerLimit (0U)
#  define RearSensorSts_adt_UpperLimit (3U)

#  define Rear_Brk_Asst_adt_LowerLimit (0U)
#  define Rear_Brk_Asst_adt_UpperLimit (1U)

#  define RemStActvSts_adt_LowerLimit (0U)
#  define RemStActvSts_adt_UpperLimit (1U)

#  define Roll_RMSE_C2_adt_LowerLimit (0U)
#  define Roll_RMSE_C2_adt_UpperLimit (255U)

#  define SBR1RowDriverSeatSts_adt_LowerLimit (0U)
#  define SBR1RowDriverSeatSts_adt_UpperLimit (3U)

#  define SPMControlSts_adt_LowerLimit (0U)
#  define SPMControlSts_adt_UpperLimit (3U)

#  define SPMFailSts_adt_LowerLimit (0U)
#  define SPMFailSts_adt_UpperLimit (1U)

#  define SPMSystemFault_adt_LowerLimit (0U)
#  define SPMSystemFault_adt_UpperLimit (1U)

#  define SPM_LedControlSts_adt_LowerLimit (0U)
#  define SPM_LedControlSts_adt_UpperLimit (3U)

#  define SPM_Screen_Rqst_adt_LowerLimit (0U)
#  define SPM_Screen_Rqst_adt_UpperLimit (1U)

#  define SVC_Guidelines_adt_LowerLimit (0U)
#  define SVC_Guidelines_adt_UpperLimit (1U)

#  define Segment_1_Confidence_adt_LowerLimit (0U)
#  define Segment_1_Confidence_adt_UpperLimit (15U)

#  define Segment_2_Confidence_adt_LowerLimit (0U)
#  define Segment_2_Confidence_adt_UpperLimit (15U)

#  define Segment_3_Confidence_adt_LowerLimit (0U)
#  define Segment_3_Confidence_adt_UpperLimit (15U)

#  define Segment_4_Confidence_adt_LowerLimit (0U)
#  define Segment_4_Confidence_adt_UpperLimit (15U)

#  define Segment_5_Confidence_adt_LowerLimit (0U)
#  define Segment_5_Confidence_adt_UpperLimit (15U)

#  define Segment_6_Confidence_adt_LowerLimit (0U)
#  define Segment_6_Confidence_adt_UpperLimit (15U)

#  define Segment_7_Confidence_adt_LowerLimit (0U)
#  define Segment_7_Confidence_adt_UpperLimit (15U)

#  define Segment_8_Confidence_adt_LowerLimit (0U)
#  define Segment_8_Confidence_adt_UpperLimit (15U)

#  define ShiftLeverPositionReq_adt_LowerLimit (0U)
#  define ShiftLeverPositionReq_adt_UpperLimit (15U)

#  define ShiftLeverPosition_adt_LowerLimit (0U)
#  define ShiftLeverPosition_adt_UpperLimit (15U)

#  define Shifter_ADAS_Inhibit_adt_LowerLimit (0U)
#  define Shifter_ADAS_Inhibit_adt_UpperLimit (1U)

#  define StaticGrid_adt_LowerLimit (0U)
#  define StaticGrid_adt_UpperLimit (1U)

#  define TCASERANGESTATUS_adt_LowerLimit (0U)
#  define TCASERANGESTATUS_adt_UpperLimit (3U)

#  define TGW_CAMERA_DISP_STAT_adt_LowerLimit (0U)
#  define TGW_CAMERA_DISP_STAT_adt_UpperLimit (15U)

#  define THA_EPB_Req_adt_LowerLimit (0U)
#  define THA_EPB_Req_adt_UpperLimit (3U)

#  define THA_STAT_adt_LowerLimit (0U)
#  define THA_STAT_adt_UpperLimit (7U)

#  define THA_SpeedLimit_Req_adt_LowerLimit (0U)
#  define THA_SpeedLimit_Req_adt_UpperLimit (3U)

#  define THA_SteeringDamping_adt_LowerLimit (0U)
#  define THA_SteeringDamping_adt_UpperLimit (255U)

#  define THA_SteeringTorqueReq_adt_LowerLimit (0U)
#  define THA_SteeringTorqueReq_adt_UpperLimit (3U)

#  define THA_SteeringTouchStat_adt_LowerLimit (0U)
#  define THA_SteeringTouchStat_adt_UpperLimit (3U)

#  define TRANS_ADAS_Inhibit_adt_LowerLimit (0U)
#  define TRANS_ADAS_Inhibit_adt_UpperLimit (1U)

#  define TRSCMoreCamRQSts_adt_LowerLimit (0U)
#  define TRSCMoreCamRQSts_adt_UpperLimit (1U)

#  define TRSC_CenterBtn_Sts_adt_LowerLimit (0U)
#  define TRSC_CenterBtn_Sts_adt_UpperLimit (3U)

#  define TRSC_EnableBtn_Sts_adt_LowerLimit (0U)
#  define TRSC_EnableBtn_Sts_adt_UpperLimit (3U)

#  define TRSC_LED_Stat_adt_LowerLimit (0U)
#  define TRSC_LED_Stat_adt_UpperLimit (3U)

#  define TRSC_PopupDisp_Info_adt_LowerLimit (0U)
#  define TRSC_PopupDisp_Info_adt_UpperLimit (15U)

#  define TRSC_STAT_adt_LowerLimit (0U)
#  define TRSC_STAT_adt_UpperLimit (7U)

#  define TRSC_SpeedLimit_Req_adt_LowerLimit (0U)
#  define TRSC_SpeedLimit_Req_adt_UpperLimit (15U)

#  define TRSC_SteeringDamping_adt_LowerLimit (0U)
#  define TRSC_SteeringDamping_adt_UpperLimit (255U)

#  define TRSC_SteeringTorqueReq_adt_LowerLimit (0U)
#  define TRSC_SteeringTorqueReq_adt_UpperLimit (3U)

#  define TRSC_VehicleStop_Req_adt_LowerLimit (0U)
#  define TRSC_VehicleStop_Req_adt_UpperLimit (3U)

#  define TargetGear_adt_LowerLimit (0U)
#  define TargetGear_adt_UpperLimit (15U)

#  define TrailerConnectionSts_adt_LowerLimit (0U)
#  define TrailerConnectionSts_adt_UpperLimit (3U)

#  define Trailer_Angle_Sign_adt_LowerLimit (0U)
#  define Trailer_Angle_Sign_adt_UpperLimit (3U)

#  define Trailer_Angle_adt_LowerLimit (0U)
#  define Trailer_Angle_adt_UpperLimit (255U)

#  define Trailer_Calibration_adt_LowerLimit (0U)
#  define Trailer_Calibration_adt_UpperLimit (2U)

#  define TransmissionSailingSts_adt_LowerLimit (0U)
#  define TransmissionSailingSts_adt_UpperLimit (15U)

#  define TrlrHitchLight_Cntrl_adt_LowerLimit (0U)
#  define TrlrHitchLight_Cntrl_adt_UpperLimit (3U)

#  define TurnIndicatorSts_adt_LowerLimit (0U)
#  define TurnIndicatorSts_adt_UpperLimit (3U)

#  define VIN_MSG_adt_LowerLimit (0U)
#  define VIN_MSG_adt_UpperLimit (3U)

#  define VehicleStandStillSts_adt_LowerLimit (0U)
#  define VehicleStandStillSts_adt_UpperLimit (3U)

#  define WakeupSource_FD01_ADCM_adt_LowerLimit (0U)
#  define WakeupSource_FD01_ADCM_adt_UpperLimit (255U)

#  define WakeupSource_FD01_BCM_adt_LowerLimit (0U)
#  define WakeupSource_FD01_BCM_adt_UpperLimit (255U)

#  define WakeupSource_FD01_SGW_adt_LowerLimit (0U)
#  define WakeupSource_FD01_SGW_adt_UpperLimit (255U)

#  define WakeupSource_FD02_BCM_adt_LowerLimit (0U)
#  define WakeupSource_FD02_BCM_adt_UpperLimit (255U)

#  define WakeupSource_FD02_BSM2_adt_LowerLimit (0U)
#  define WakeupSource_FD02_BSM2_adt_UpperLimit (255U)

#  define WakeupSource_FD02_CADM2_adt_LowerLimit (0U)
#  define WakeupSource_FD02_CADM2_adt_UpperLimit (255U)

#  define WakeupSource_FD02_EPS_adt_LowerLimit (0U)
#  define WakeupSource_FD02_EPS_adt_UpperLimit (255U)

#  define WakeupSource_FD02_ORC_adt_LowerLimit (0U)
#  define WakeupSource_FD02_ORC_adt_UpperLimit (255U)

#  define WakeupSource_FD02_PAM_adt_LowerLimit (0U)
#  define WakeupSource_FD02_PAM_adt_UpperLimit (255U)

#  define WakeupSource_FD02_SGW_adt_LowerLimit (0U)
#  define WakeupSource_FD02_SGW_adt_UpperLimit (255U)

#  define WakeupSource_FD02_TRLR_REV_adt_LowerLimit (0U)
#  define WakeupSource_FD02_TRLR_REV_adt_UpperLimit (255U)

#  define WakeupSource_FD03_BCM_adt_LowerLimit (0U)
#  define WakeupSource_FD03_BCM_adt_UpperLimit (255U)

#  define WakeupSource_FD03_SGW_adt_LowerLimit (0U)
#  define WakeupSource_FD03_SGW_adt_UpperLimit (255U)

#  define WakeupSource_FD04_BCM_adt_LowerLimit (0U)
#  define WakeupSource_FD04_BCM_adt_UpperLimit (255U)

#  define WakeupSource_FD08_SGW_adt_LowerLimit (0U)
#  define WakeupSource_FD08_SGW_adt_UpperLimit (255U)

#  define WakeupSource_FD11_SGW_adt_LowerLimit (0U)
#  define WakeupSource_FD11_SGW_adt_UpperLimit (255U)

#  define YawRate_RMSE_C2_adt_LowerLimit (0U)
#  define YawRate_RMSE_C2_adt_UpperLimit (255U)

#  ifndef Cx00_Initialize
#   define Cx00_Initialize (0U)
#  endif

#  ifndef Cx00_Italian
#   define Cx00_Italian (0U)
#  endif

#  ifndef Cx00_No_Wakeup
#   define Cx00_No_Wakeup (0U)
#  endif

#  ifndef Cx00_None
#   define Cx00_None (0U)
#  endif

#  ifndef Cx00_TM0
#   define Cx00_TM0 (0U)
#  endif

#  ifndef Cx0_Absolute
#   define Cx0_Absolute (0U)
#  endif

#  ifndef Cx0_Active
#   define Cx0_Active (0U)
#  endif

#  ifndef Cx0_Center
#   define Cx0_Center (0U)
#  endif

#  ifndef Cx0_Continuous_0_Hz
#   define Cx0_Continuous_0_Hz (0U)
#  endif

#  ifndef Cx0_DISP_0
#   define Cx0_DISP_0 (0U)
#  endif

#  ifndef Cx0_DISP_NON_CAMERA
#   define Cx0_DISP_NON_CAMERA (0U)
#  endif

#  ifndef Cx0_Default
#   define Cx0_Default (0U)
#  endif

#  ifndef Cx0_Disabled
#   define Cx0_Disabled (0U)
#  endif

#  ifndef Cx0_Engine_Off
#   define Cx0_Engine_Off (0U)
#  endif

#  ifndef Cx0_Error_Active_state
#   define Cx0_Error_Active_state (0U)
#  endif

#  ifndef Cx0_FT_OFF_RR_OFF
#   define Cx0_FT_OFF_RR_OFF (0U)
#  endif

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx0_HIGH
#   define Cx0_HIGH (0U)
#  endif

#  ifndef Cx0_Hands_Off
#   define Cx0_Hands_Off (0U)
#  endif

#  ifndef Cx0_IDLE
#   define Cx0_IDLE (0U)
#  endif

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx0_Initial
#   define Cx0_Initial (0U)
#  endif

#  ifndef Cx0_Initialization
#   define Cx0_Initialization (0U)
#  endif

#  ifndef Cx0_Low
#   define Cx0_Low (0U)
#  endif

#  ifndef Cx0_NONE
#   define Cx0_NONE (0U)
#  endif

#  ifndef Cx0_NOT_Pressed
#   define Cx0_NOT_Pressed (0U)
#  endif

#  ifndef Cx0_NO_TRLR
#   define Cx0_NO_TRLR (0U)
#  endif

#  ifndef Cx0_N_A
#   define Cx0_N_A (0U)
#  endif

#  ifndef Cx0_Neutral
#   define Cx0_Neutral (0U)
#  endif

#  ifndef Cx0_No_Request
#   define Cx0_No_Request (0U)
#  endif

#  ifndef Cx0_No_Selection_Active_Or_Available
#   define Cx0_No_Selection_Active_Or_Available (0U)
#  endif

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx0_Not_Calibrated
#   define Cx0_Not_Calibrated (0U)
#  endif

#  ifndef Cx0_Not_Connected
#   define Cx0_Not_Connected (0U)
#  endif

#  ifndef Cx0_Not_Limiting
#   define Cx0_Not_Limiting (0U)
#  endif

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx0_ON
#   define Cx0_ON (0U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx0_Released
#   define Cx0_Released (0U)
#  endif

#  ifndef Cx0_Sailing_Not_Possible
#   define Cx0_Sailing_Not_Possible (0U)
#  endif

#  ifndef Cx0_Seat_Belt_Fasten
#   define Cx0_Seat_Belt_Fasten (0U)
#  endif

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx0_Stand_Still
#   define Cx0_Stand_Still (0U)
#  endif

#  ifndef Cx0_Standby
#   define Cx0_Standby (0U)
#  endif

#  ifndef Cx0_TCH_NOT_PSD
#   define Cx0_TCH_NOT_PSD (0U)
#  endif

#  ifndef Cx0_Temp_NA
#   define Cx0_Temp_NA (0U)
#  endif

#  ifndef Cx0_True
#   define Cx0_True (0U)
#  endif

#  ifndef Cx0_Uninitialized_State
#   define Cx0_Uninitialized_State (0U)
#  endif

#  ifndef Cx0_VIN_LO
#   define Cx0_VIN_LO (0U)
#  endif

#  ifndef Cx1_ENS_Stopped_ENS_STOPPED
#   define Cx1_ENS_Stopped_ENS_STOPPED (1U)
#  endif

#  ifndef CxFE_NOT_INIT
#   define CxFE_NOT_INIT (254U)
#  endif

#  ifndef CxFE_OutOfRange
#   define CxFE_OutOfRange (254U)
#  endif

#  ifndef Cx01_1st_gear
#   define Cx01_1st_gear (1U)
#  endif

#  ifndef Cx01_Deutsch
#   define Cx01_Deutsch (1U)
#  endif

#  ifndef Cx01_IGN_ON
#   define Cx01_IGN_ON (1U)
#  endif

#  ifndef Cx01_Ignition_Active
#   define Cx01_Ignition_Active (1U)
#  endif

#  ifndef Cx01_TM1
#   define Cx01_TM1 (1U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx1_Active_ParallelParking
#   define Cx1_Active_ParallelParking (1U)
#  endif

#  ifndef Cx1_Applied
#   define Cx1_Applied (1U)
#  endif

#  ifndef Cx1_BRAKING
#   define Cx1_BRAKING (1U)
#  endif

#  ifndef Cx1_Bus_Sleep_State
#   define Cx1_Bus_Sleep_State (1U)
#  endif

#  ifndef Cx1_Calibrated
#   define Cx1_Calibrated (1U)
#  endif

#  ifndef Cx1_Calibrating
#   define Cx1_Calibrating (1U)
#  endif

#  ifndef Cx1_Connected
#   define Cx1_Connected (1U)
#  endif

#  ifndef Cx1_Continuous_Light
#   define Cx1_Continuous_Light (1U)
#  endif

#  ifndef Cx1_Continuous_light
#   define Cx1_Continuous_light (1U)
#  endif

#  ifndef Cx1_DISP_1
#   define Cx1_DISP_1 (1U)
#  endif

#  ifndef Cx1_DISP_DIGITAL_RVC_CAMERA
#   define Cx1_DISP_DIGITAL_RVC_CAMERA (1U)
#  endif

#  ifndef Cx1_DUMP
#   define Cx1_DUMP (1U)
#  endif

#  ifndef Cx1_EPB_Requested
#   define Cx1_EPB_Requested (1U)
#  endif

#  ifndef Cx1_Enabled
#   define Cx1_Enabled (1U)
#  endif

#  ifndef Cx1_Enabled_Seeking
#   define Cx1_Enabled_Seeking (1U)
#  endif

#  ifndef Cx1_Engine_Cranking
#   define Cx1_Engine_Cranking (1U)
#  endif

#  ifndef Cx1_Error_passive_warning_state
#   define Cx1_Error_passive_warning_state (1U)
#  endif

#  ifndef Cx1_FT_OFF_RR_ON
#   define Cx1_FT_OFF_RR_ON (1U)
#  endif

#  ifndef Cx1_False
#   define Cx1_False (1U)
#  endif

#  ifndef Cx1_Forward
#   define Cx1_Forward (1U)
#  endif

#  ifndef Cx1_ForwardGear_1
#   define Cx1_ForwardGear_1 (1U)
#  endif

#  ifndef Cx1_Hands_On
#   define Cx1_Hands_On (1U)
#  endif

#  ifndef Cx1_IGN_LK
#   define Cx1_IGN_LK (1U)
#  endif

#  ifndef Cx1_Idle
#   define Cx1_Idle (1U)
#  endif

#  ifndef Cx1_Ignition_Off_WithoutKey
#   define Cx1_Ignition_Off_WithoutKey (1U)
#  endif

#  ifndef Cx1_LOW
#   define Cx1_LOW (1U)
#  endif

#  ifndef Cx1_Low
#   define Cx1_Low (1U)
#  endif

#  ifndef Cx1_MRM_in_Process
#   define Cx1_MRM_in_Process (1U)
#  endif

#  ifndef Cx1_Medium
#   define Cx1_Medium (1U)
#  endif

#  ifndef Cx1_NTRL
#   define Cx1_NTRL (1U)
#  endif

#  ifndef Cx1_Not_Active_blocked
#   define Cx1_Not_Active_blocked (1U)
#  endif

#  ifndef Cx1_OFF
#   define Cx1_OFF (1U)
#  endif

#  ifndef Cx1_P
#   define Cx1_P (1U)
#  endif

#  ifndef Cx1_Perm_NA
#   define Cx1_Perm_NA (1U)
#  endif

#  ifndef Cx1_Point
#   define Cx1_Point (1U)
#  endif

#  ifndef Cx1_Positive
#   define Cx1_Positive (1U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef Cx1_Relative
#   define Cx1_Relative (1U)
#  endif

#  ifndef Cx1_Requested
#   define Cx1_Requested (1U)
#  endif

#  ifndef Cx1_Right
#   define Cx1_Right (1U)
#  endif

#  ifndef Cx1_SPD_4
#   define Cx1_SPD_4 (1U)
#  endif

#  ifndef Cx1_Sailing_Possible_Passive
#   define Cx1_Sailing_Possible_Passive (1U)
#  endif

#  ifndef Cx1_Seat_Belt_Not_Fasten
#   define Cx1_Seat_Belt_Not_Fasten (1U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx1_TCH_PSD
#   define Cx1_TCH_PSD (1U)
#  endif

#  ifndef Cx1_TRLR_PRSNT
#   define Cx1_TRLR_PRSNT (1U)
#  endif

#  ifndef Cx1_Temporary_Failure
#   define Cx1_Temporary_Failure (1U)
#  endif

#  ifndef Cx1_True
#   define Cx1_True (1U)
#  endif

#  ifndef Cx1_Type_1
#   define Cx1_Type_1 (1U)
#  endif

#  ifndef Cx1_VIEW_1
#   define Cx1_VIEW_1 (1U)
#  endif

#  ifndef Cx1_VIN_MID
#   define Cx1_VIN_MID (1U)
#  endif

#  ifndef Cx1_View_1
#   define Cx1_View_1 (1U)
#  endif

#  ifndef Cx1_White
#   define Cx1_White (1U)
#  endif

#  ifndef Cx2_ENS_Request_Start_ENS_RQ_ST
#   define Cx2_ENS_Request_Start_ENS_RQ_ST (2U)
#  endif

#  ifndef Cx2_Slow_2_Hz
#   define Cx2_Slow_2_Hz (2U)
#  endif

#  ifndef Cx82_CANFD2_Bus_Wakeup
#   define Cx82_CANFD2_Bus_Wakeup (130U)
#  endif

#  ifndef Cx02_2nd_gear
#   define Cx02_2nd_gear (2U)
#  endif

#  ifndef Cx02_CmdIgnSts_LK_to_ACC_RUN_START
#   define Cx02_CmdIgnSts_LK_to_ACC_RUN_START (2U)
#  endif

#  ifndef Cx02_English
#   define Cx02_English (2U)
#  endif

#  ifndef Cx02_TM2
#   define Cx02_TM2 (2U)
#  endif

#  ifndef Cx2_2Blinking_Light
#   define Cx2_2Blinking_Light (2U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx2_Active_PerpendicularParking
#   define Cx2_Active_PerpendicularParking (2U)
#  endif

#  ifndef Cx2_Backward
#   define Cx2_Backward (2U)
#  endif

#  ifndef Cx2_Blinking
#   define Cx2_Blinking (2U)
#  endif

#  ifndef Cx2_Blinking_light
#   define Cx2_Blinking_light (2U)
#  endif

#  ifndef Cx2_Brakes_Overheated
#   define Cx2_Brakes_Overheated (2U)
#  endif

#  ifndef Cx2_Bus_off_state
#   define Cx2_Bus_off_state (2U)
#  endif

#  ifndef Cx2_DISP_2
#   define Cx2_DISP_2 (2U)
#  endif

#  ifndef Cx2_DISP_ANALOG_RVC_CAMERA
#   define Cx2_DISP_ANALOG_RVC_CAMERA (2U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx2_DynamicBrkESC
#   define Cx2_DynamicBrkESC (2U)
#  endif

#  ifndef Cx2_Enabled
#   define Cx2_Enabled (2U)
#  endif

#  ifndef Cx2_Engaged
#   define Cx2_Engaged (2U)
#  endif

#  ifndef Cx2_Engaged_Semi
#   define Cx2_Engaged_Semi (2U)
#  endif

#  ifndef Cx2_Engine_On
#   define Cx2_Engine_On (2U)
#  endif

#  ifndef Cx2_External_Failure
#   define Cx2_External_Failure (2U)
#  endif

#  ifndef Cx2_FT_ON_RR_OFF
#   define Cx2_FT_ON_RR_OFF (2U)
#  endif

#  ifndef Cx2_ForwardGear_2
#   define Cx2_ForwardGear_2 (2U)
#  endif

#  ifndef Cx2_High
#   define Cx2_High (2U)
#  endif

#  ifndef Cx2_Ignition_Off
#   define Cx2_Ignition_Off (2U)
#  endif

#  ifndef Cx2_LOW
#   define Cx2_LOW (2U)
#  endif

#  ifndef Cx2_Left
#   define Cx2_Left (2U)
#  endif

#  ifndef Cx2_MED
#   define Cx2_MED (2U)
#  endif

#  ifndef Cx2_Medium
#   define Cx2_Medium (2U)
#  endif

#  ifndef Cx2_NDEF2
#   define Cx2_NDEF2 (2U)
#  endif

#  ifndef Cx2_Negative
#   define Cx2_Negative (2U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx2_Not_Active_failure
#   define Cx2_Not_Active_failure (2U)
#  endif

#  ifndef Cx2_Not_Used
#   define Cx2_Not_Used (2U)
#  endif

#  ifndef Cx2_PARK
#   define Cx2_PARK (2U)
#  endif

#  ifndef Cx2_PreActive
#   define Cx2_PreActive (2U)
#  endif

#  ifndef Cx2_Prepare_Bus_State
#   define Cx2_Prepare_Bus_State (2U)
#  endif

#  ifndef Cx2_R
#   define Cx2_R (2U)
#  endif

#  ifndef Cx2_SNA
#   define Cx2_SNA (2U)
#  endif

#  ifndef Cx2_SPD_5
#   define Cx2_SPD_5 (2U)
#  endif

#  ifndef Cx2_Straight_0_Corner
#   define Cx2_Straight_0_Corner (2U)
#  endif

#  ifndef Cx2_TCH_PS_CAN
#   define Cx2_TCH_PS_CAN (2U)
#  endif

#  ifndef Cx2_TOI_Available
#   define Cx2_TOI_Available (2U)
#  endif

#  ifndef Cx2_TRLR_DCONN
#   define Cx2_TRLR_DCONN (2U)
#  endif

#  ifndef Cx2_Transition_To_Sailing
#   define Cx2_Transition_To_Sailing (2U)
#  endif

#  ifndef Cx2_Type_2
#   define Cx2_Type_2 (2U)
#  endif

#  ifndef Cx2_VIEW_2
#   define Cx2_VIEW_2 (2U)
#  endif

#  ifndef Cx2_VIN_HI
#   define Cx2_VIN_HI (2U)
#  endif

#  ifndef Cx2_Vehicle_Secure_Request
#   define Cx2_Vehicle_Secure_Request (2U)
#  endif

#  ifndef Cx2_View_2
#   define Cx2_View_2 (2U)
#  endif

#  ifndef Cx2_Yellow
#   define Cx2_Yellow (2U)
#  endif

#  ifndef Cx3_ACC
#   define Cx3_ACC (3U)
#  endif

#  ifndef Cx3_ENS_Running_ENS_RUN
#   define Cx3_ENS_Running_ENS_RUN (3U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef Cx3_Slow_3_Hz
#   define Cx3_Slow_3_Hz (3U)
#  endif

#  ifndef Cx81_FD1_Psv_WU
#   define Cx81_FD1_Psv_WU (129U)
#  endif

#  ifndef Cx03_3rd_gear
#   define Cx03_3rd_gear (3U)
#  endif

#  ifndef Cx03_Espanol
#   define Cx03_Espanol (3U)
#  endif

#  ifndef Cx03_HazardSwitch_ON
#   define Cx03_HazardSwitch_ON (3U)
#  endif

#  ifndef Cx03_TM3
#   define Cx03_TM3 (3U)
#  endif

#  ifndef Cx3_3_Arc
#   define Cx3_3_Arc (3U)
#  endif

#  ifndef Cx3_AERO
#   define Cx3_AERO (3U)
#  endif

#  ifndef Cx3_Active
#   define Cx3_Active (3U)
#  endif

#  ifndef Cx3_Active_OutParking
#   define Cx3_Active_OutParking (3U)
#  endif

#  ifndef Cx3_DISP_3
#   define Cx3_DISP_3 (3U)
#  endif

#  ifndef Cx3_DISP_ANALOG_CHMSL_CAMERA
#   define Cx3_DISP_ANALOG_CHMSL_CAMERA (3U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx3_DynamicBrkEPB
#   define Cx3_DynamicBrkEPB (3U)
#  endif

#  ifndef Cx3_Engaged
#   define Cx3_Engaged (3U)
#  endif

#  ifndef Cx3_Engaged_Full
#   define Cx3_Engaged_Full (3U)
#  endif

#  ifndef Cx3_FT_ON_RR_ON
#   define Cx3_FT_ON_RR_ON (3U)
#  endif

#  ifndef Cx3_Faulted
#   define Cx3_Faulted (3U)
#  endif

#  ifndef Cx3_ForwardGear_3
#   define Cx3_ForwardGear_3 (3U)
#  endif

#  ifndef Cx3_HI
#   define Cx3_HI (3U)
#  endif

#  ifndef Cx3_High
#   define Cx3_High (3U)
#  endif

#  ifndef Cx3_Ignition_Acc
#   define Cx3_Ignition_Acc (3U)
#  endif

#  ifndef Cx3_N
#   define Cx3_N (3U)
#  endif

#  ifndef Cx3_Not_Used
#   define Cx3_Not_Used (3U)
#  endif

#  ifndef Cx3_Not_used
#   define Cx3_Not_used (3U)
#  endif

#  ifndef Cx3_Orange
#   define Cx3_Orange (3U)
#  endif

#  ifndef Cx3_Ready_Sleep_State
#   define Cx3_Ready_Sleep_State (3U)
#  endif

#  ifndef Cx3_SPD_6
#   define Cx3_SPD_6 (3U)
#  endif

#  ifndef Cx3_Sailing_Active
#   define Cx3_Sailing_Active (3U)
#  endif

#  ifndef Cx3_Straight_1_Corner
#   define Cx3_Straight_1_Corner (3U)
#  endif

#  ifndef Cx3_System_Failure
#   define Cx3_System_Failure (3U)
#  endif

#  ifndef Cx3_TOI_Unavailable
#   define Cx3_TOI_Unavailable (3U)
#  endif

#  ifndef Cx3_Type_3
#   define Cx3_Type_3 (3U)
#  endif

#  ifndef Cx3_VIEW_3
#   define Cx3_VIEW_3 (3U)
#  endif

#  ifndef Cx3_Vehicle_Securement_Complete
#   define Cx3_Vehicle_Securement_Complete (3U)
#  endif

#  ifndef Cx3_View_3
#   define Cx3_View_3 (3U)
#  endif

#  ifndef Cx4_ENS_Stop_Pending_ENS_STOP_PEND
#   define Cx4_ENS_Stop_Pending_ENS_STOP_PEND (4U)
#  endif

#  ifndef Cx4_Fast_4_Hz
#   define Cx4_Fast_4_Hz (4U)
#  endif

#  ifndef Cx4_RUN
#   define Cx4_RUN (4U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef Cx82_FD2_Psv_WU
#   define Cx82_FD2_Psv_WU (130U)
#  endif

#  ifndef Cx04_4th_gear
#   define Cx04_4th_gear (4U)
#  endif

#  ifndef Cx04_DrvDoorAjar
#   define Cx04_DrvDoorAjar (4U)
#  endif

#  ifndef Cx04_Francais
#   define Cx04_Francais (4U)
#  endif

#  ifndef Cx04_TM4
#   define Cx04_TM4 (4U)
#  endif

#  ifndef Cx4_4_Arc
#   define Cx4_4_Arc (4U)
#  endif

#  ifndef Cx4_Canceled
#   define Cx4_Canceled (4U)
#  endif

#  ifndef Cx4_Complete
#   define Cx4_Complete (4U)
#  endif

#  ifndef Cx4_D
#   define Cx4_D (4U)
#  endif

#  ifndef Cx4_DISP_4
#   define Cx4_DISP_4 (4U)
#  endif

#  ifndef Cx4_DISP_SURROUND_VIEW_CAMERA
#   define Cx4_DISP_SURROUND_VIEW_CAMERA (4U)
#  endif

#  ifndef Cx4_Emergency_Braking
#   define Cx4_Emergency_Braking (4U)
#  endif

#  ifndef Cx4_ForwardGear_4
#   define Cx4_ForwardGear_4 (4U)
#  endif

#  ifndef Cx4_Ignition_On
#   define Cx4_Ignition_On (4U)
#  endif

#  ifndef Cx4_NVL
#   define Cx4_NVL (4U)
#  endif

#  ifndef Cx4_Normal_Operation_State
#   define Cx4_Normal_Operation_State (4U)
#  endif

#  ifndef Cx4_Not_Used
#   define Cx4_Not_Used (4U)
#  endif

#  ifndef Cx4_OFF
#   define Cx4_OFF (4U)
#  endif

#  ifndef Cx4_Other
#   define Cx4_Other (4U)
#  endif

#  ifndef Cx4_Road_Edge
#   define Cx4_Road_Edge (4U)
#  endif

#  ifndef Cx4_SPD_7
#   define Cx4_SPD_7 (4U)
#  endif

#  ifndef Cx4_Straight_2_Corner
#   define Cx4_Straight_2_Corner (4U)
#  endif

#  ifndef Cx4_TCH_CFG_RES
#   define Cx4_TCH_CFG_RES (4U)
#  endif

#  ifndef Cx4_Transition_Out_Of_Sailing
#   define Cx4_Transition_Out_Of_Sailing (4U)
#  endif

#  ifndef Cx4_Type_4
#   define Cx4_Type_4 (4U)
#  endif

#  ifndef Cx4_VIEW_4
#   define Cx4_VIEW_4 (4U)
#  endif

#  ifndef Cx4_View_4
#   define Cx4_View_4 (4U)
#  endif

#  ifndef Cx5_ENS_Start_protection_ENS_ST_PRTCT
#   define Cx5_ENS_Start_protection_ENS_ST_PRTCT (5U)
#  endif

#  ifndef Cx5_Fast_5_Hz
#   define Cx5_Fast_5_Hz (5U)
#  endif

#  ifndef Cx5_START
#   define Cx5_START (5U)
#  endif

#  ifndef Cx83_FD3_Psv_WU
#   define Cx83_FD3_Psv_WU (131U)
#  endif

#  ifndef Cx05_5th_gear
#   define Cx05_5th_gear (5U)
#  endif

#  ifndef Cx05_DrvDoor2Ajar
#   define Cx05_DrvDoor2Ajar (5U)
#  endif

#  ifndef Cx05_Portugues
#   define Cx05_Portugues (5U)
#  endif

#  ifndef Cx05_TM5
#   define Cx05_TM5 (5U)
#  endif

#  ifndef Cx5_5_Arc
#   define Cx5_5_Arc (5U)
#  endif

#  ifndef Cx5_Applying
#   define Cx5_Applying (5U)
#  endif

#  ifndef Cx5_Botts_Dot
#   define Cx5_Botts_Dot (5U)
#  endif

#  ifndef Cx5_DISP_5
#   define Cx5_DISP_5 (5U)
#  endif

#  ifndef Cx5_DISP_TRAILER_CAMERA
#   define Cx5_DISP_TRAILER_CAMERA (5U)
#  endif

#  ifndef Cx5_Faulted_
#   define Cx5_Faulted_ (5U)
#  endif

#  ifndef Cx5_ForwardGear_5
#   define Cx5_ForwardGear_5 (5U)
#  endif

#  ifndef Cx5_Ignition_Pre_Start
#   define Cx5_Ignition_Pre_Start (5U)
#  endif

#  ifndef Cx5_L
#   define Cx5_L (5U)
#  endif

#  ifndef Cx5_Not_Used
#   define Cx5_Not_Used (5U)
#  endif

#  ifndef Cx5_OR1
#   define Cx5_OR1 (5U)
#  endif

#  ifndef Cx5_Repeat_Message_State
#   define Cx5_Repeat_Message_State (5U)
#  endif

#  ifndef Cx5_SPD_8
#   define Cx5_SPD_8 (5U)
#  endif

#  ifndef Cx5_Sailing_Not_Available
#   define Cx5_Sailing_Not_Available (5U)
#  endif

#  ifndef Cx5_TCH_CFG_OFFSET
#   define Cx5_TCH_CFG_OFFSET (5U)
#  endif

#  ifndef Cx5_Type_5
#   define Cx5_Type_5 (5U)
#  endif

#  ifndef Cx5_VIEW_5
#   define Cx5_VIEW_5 (5U)
#  endif

#  ifndef Cx5_View_5
#   define Cx5_View_5 (5U)
#  endif

#  ifndef Cx6_ENS_Start_inhibit_ENS_ST_INH
#   define Cx6_ENS_Start_inhibit_ENS_ST_INH (6U)
#  endif

#  ifndef Cx84_FD4_Psv_WU
#   define Cx84_FD4_Psv_WU (132U)
#  endif

#  ifndef Cx06_6th_gear
#   define Cx06_6th_gear (6U)
#  endif

#  ifndef Cx06_Polish
#   define Cx06_Polish (6U)
#  endif

#  ifndef Cx06_PsngrDoorAjar
#   define Cx06_PsngrDoorAjar (6U)
#  endif

#  ifndef Cx06_TM6
#   define Cx06_TM6 (6U)
#  endif

#  ifndef Cx6_6_Arc
#   define Cx6_6_Arc (6U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx6_DISP_6
#   define Cx6_DISP_6 (6U)
#  endif

#  ifndef Cx6_DISP_WIRLESS_CAMERA
#   define Cx6_DISP_WIRLESS_CAMERA (6U)
#  endif

#  ifndef Cx6_ForwardGear_6
#   define Cx6_ForwardGear_6 (6U)
#  endif

#  ifndef Cx6_Ignition_Start
#   define Cx6_Ignition_Start (6U)
#  endif

#  ifndef Cx6_Maintenance_Mode
#   define Cx6_Maintenance_Mode (6U)
#  endif

#  ifndef Cx6_Not_Used
#   define Cx6_Not_Used (6U)
#  endif

#  ifndef Cx6_ORL2
#   define Cx6_ORL2 (6U)
#  endif

#  ifndef Cx6_SPD_9
#   define Cx6_SPD_9 (6U)
#  endif

#  ifndef Cx6_Synchronize_State
#   define Cx6_Synchronize_State (6U)
#  endif

#  ifndef Cx6_TCH_CFG_MAX
#   define Cx6_TCH_CFG_MAX (6U)
#  endif

#  ifndef Cx6_TIP_Autostick
#   define Cx6_TIP_Autostick (6U)
#  endif

#  ifndef Cx6_Type_6
#   define Cx6_Type_6 (6U)
#  endif

#  ifndef Cx6_VIEW_6
#   define Cx6_VIEW_6 (6U)
#  endif

#  ifndef Cx6_View_6
#   define Cx6_View_6 (6U)
#  endif

#  ifndef Cx7_ENS_disabled_ENS_DSBL
#   define Cx7_ENS_disabled_ENS_DSBL (7U)
#  endif

#  ifndef Cx85_FD5_Psv_WU
#   define Cx85_FD5_Psv_WU (133U)
#  endif

#  ifndef CxF_SNA
#   define CxF_SNA (15U)
#  endif

#  ifndef Cx07_7th_gear
#   define Cx07_7th_gear (7U)
#  endif

#  ifndef Cx07_Dutch
#   define Cx07_Dutch (7U)
#  endif

#  ifndef Cx07_LR_DoorAjar
#   define Cx07_LR_DoorAjar (7U)
#  endif

#  ifndef Cx07_TM7
#   define Cx07_TM7 (7U)
#  endif

#  ifndef Cx7_Assembly_Check
#   define Cx7_Assembly_Check (7U)
#  endif

#  ifndef Cx7_DISP_7
#   define Cx7_DISP_7 (7U)
#  endif

#  ifndef Cx7_DISP_SVS_MORECAMS_POPUP
#   define Cx7_DISP_SVS_MORECAMS_POPUP (7U)
#  endif

#  ifndef Cx7_ForwardGear_7
#   define Cx7_ForwardGear_7 (7U)
#  endif

#  ifndef Cx7_Ignition_Cranking
#   define Cx7_Ignition_Cranking (7U)
#  endif

#  ifndef Cx7_Lifter
#   define Cx7_Lifter (7U)
#  endif

#  ifndef Cx7_Offline_State
#   define Cx7_Offline_State (7U)
#  endif

#  ifndef Cx7_Other
#   define Cx7_Other (7U)
#  endif

#  ifndef Cx7_Plus
#   define Cx7_Plus (7U)
#  endif

#  ifndef Cx7_SPD_10
#   define Cx7_SPD_10 (7U)
#  endif

#  ifndef Cx7_Type_7
#   define Cx7_Type_7 (7U)
#  endif

#  ifndef Cx7_VIEW_7
#   define Cx7_VIEW_7 (7U)
#  endif

#  ifndef Cx7_View_7
#   define Cx7_View_7 (7U)
#  endif

#  ifndef Cx86_FD6_Psv_WU
#   define Cx86_FD6_Psv_WU (134U)
#  endif

#  ifndef Cx8_ENS_IHB_LATCH
#   define Cx8_ENS_IHB_LATCH (8U)
#  endif

#  ifndef Cx08_8th_gear_
#   define Cx08_8th_gear_ (8U)
#  endif

#  ifndef Cx08_Brazilian
#   define Cx08_Brazilian (8U)
#  endif

#  ifndef Cx08_RR_DoorAjar
#   define Cx08_RR_DoorAjar (8U)
#  endif

#  ifndef Cx08_TM8
#   define Cx08_TM8 (8U)
#  endif

#  ifndef Cx87_FD7_Psv_WU
#   define Cx87_FD7_Psv_WU (135U)
#  endif

#  ifndef Cx8_DISP_8
#   define Cx8_DISP_8 (8U)
#  endif

#  ifndef Cx8_DISP_INTERIOR_CAMERA
#   define Cx8_DISP_INTERIOR_CAMERA (8U)
#  endif

#  ifndef Cx8_ForwardGear_8
#   define Cx8_ForwardGear_8 (8U)
#  endif

#  ifndef Cx8_Ignition_On_EngOn
#   define Cx8_Ignition_On_EngOn (8U)
#  endif

#  ifndef Cx8_Inspection_Mode
#   define Cx8_Inspection_Mode (8U)
#  endif

#  ifndef Cx8_Minus
#   define Cx8_Minus (8U)
#  endif

#  ifndef Cx8_RAISE
#   define Cx8_RAISE (8U)
#  endif

#  ifndef Cx8_Type_8
#   define Cx8_Type_8 (8U)
#  endif

#  ifndef Cx8_VIEW_8
#   define Cx8_VIEW_8 (8U)
#  endif

#  ifndef Cx8_View_8
#   define Cx8_View_8 (8U)
#  endif

#  ifndef Cx9_ENS_Starting_ENS_Starting
#   define Cx9_ENS_Starting_ENS_Starting (9U)
#  endif

#  ifndef Cx09_9th_gear
#   define Cx09_9th_gear (9U)
#  endif

#  ifndef Cx09_TM9
#   define Cx09_TM9 (9U)
#  endif

#  ifndef Cx09_TrunkAjar
#   define Cx09_TrunkAjar (9U)
#  endif

#  ifndef Cx09_Turkish
#   define Cx09_Turkish (9U)
#  endif

#  ifndef Cx88_FD8_Psv_WU
#   define Cx88_FD8_Psv_WU (136U)
#  endif

#  ifndef Cx9_DISP_9
#   define Cx9_DISP_9 (9U)
#  endif

#  ifndef Cx9_ForwardGear_9
#   define Cx9_ForwardGear_9 (9U)
#  endif

#  ifndef Cx9_Ignition_Pre_Acc
#   define Cx9_Ignition_Pre_Acc (9U)
#  endif

#  ifndef Cx9_LOWER
#   define Cx9_LOWER (9U)
#  endif

#  ifndef Cx9_Re_Clamping
#   define Cx9_Re_Clamping (9U)
#  endif

#  ifndef Cx9_Sport
#   define Cx9_Sport (9U)
#  endif

#  ifndef Cx9_Type_9
#   define Cx9_Type_9 (9U)
#  endif

#  ifndef Cx9_VIEW_9
#   define Cx9_VIEW_9 (9U)
#  endif

#  ifndef Cx9_View_9
#   define Cx9_View_9 (9U)
#  endif

#  ifndef Cx0A_BonnetAjar
#   define Cx0A_BonnetAjar (10U)
#  endif

#  ifndef Cx0A_Mexican
#   define Cx0A_Mexican (10U)
#  endif

#  ifndef Cx0A_Not_used1
#   define Cx0A_Not_used1 (10U)
#  endif

#  ifndef Cx0A_TM10
#   define Cx0A_TM10 (10U)
#  endif

#  ifndef Cx89_FD9_Psv_WU
#   define Cx89_FD9_Psv_WU (137U)
#  endif

#  ifndef CxA_Adjuste_Mode
#   define CxA_Adjuste_Mode (10U)
#  endif

#  ifndef CxA_DISP_10
#   define CxA_DISP_10 (10U)
#  endif

#  ifndef CxA_Ignition_Pre_Off
#   define CxA_Ignition_Pre_Off (10U)
#  endif

#  ifndef CxA_Not_Used
#   define CxA_Not_Used (10U)
#  endif

#  ifndef CxA_SYSFAIL
#   define CxA_SYSFAIL (10U)
#  endif

#  ifndef CxA_Type_10
#   define CxA_Type_10 (10U)
#  endif

#  ifndef CxA_VIEW_10
#   define CxA_VIEW_10 (10U)
#  endif

#  ifndef CxA_View_10
#   define CxA_View_10 (10U)
#  endif

#  ifndef CxD_Parking
#   define CxD_Parking (13U)
#  endif

#  ifndef Cx0B_English_US
#   define Cx0B_English_US (11U)
#  endif

#  ifndef Cx0B_Not_Used2
#   define Cx0B_Not_Used2 (11U)
#  endif

#  ifndef Cx0B_RAPHandle_Req
#   define Cx0B_RAPHandle_Req (11U)
#  endif

#  ifndef Cx0B_TM11
#   define Cx0B_TM11 (11U)
#  endif

#  ifndef Cx8A_FD10_Psv_WU
#   define Cx8A_FD10_Psv_WU (138U)
#  endif

#  ifndef CxB_Automatic_Cranking
#   define CxB_Automatic_Cranking (11U)
#  endif

#  ifndef CxB_DISP_11
#   define CxB_DISP_11 (11U)
#  endif

#  ifndef CxB_Not_Used
#   define CxB_Not_Used (11U)
#  endif

#  ifndef CxB_Releasing
#   define CxB_Releasing (11U)
#  endif

#  ifndef CxB_SRVS
#   define CxB_SRVS (11U)
#  endif

#  ifndef CxB_Type_11
#   define CxB_Type_11 (11U)
#  endif

#  ifndef CxB_VIEW_11
#   define CxB_VIEW_11 (11U)
#  endif

#  ifndef CxB_View_11
#   define CxB_View_11 (11U)
#  endif

#  ifndef CxE_ReverseGear
#   define CxE_ReverseGear (14U)
#  endif

#  ifndef Cx0C_Canadian
#   define Cx0C_Canadian (12U)
#  endif

#  ifndef Cx0C_MainLightSelector_Req_OFF
#   define Cx0C_MainLightSelector_Req_OFF (12U)
#  endif

#  ifndef Cx0C_P
#   define Cx0C_P (12U)
#  endif

#  ifndef Cx0C_TM12
#   define Cx0C_TM12 (12U)
#  endif

#  ifndef Cx8B_FD11_Psv_WU
#   define Cx8B_FD11_Psv_WU (139U)
#  endif

#  ifndef CxC_AERO2
#   define CxC_AERO2 (12U)
#  endif

#  ifndef CxC_Automatic_Stop
#   define CxC_Automatic_Stop (12U)
#  endif

#  ifndef CxC_DISP_12
#   define CxC_DISP_12 (12U)
#  endif

#  ifndef CxC_Fault_EPB_Released
#   define CxC_Fault_EPB_Released (12U)
#  endif

#  ifndef CxC_Not_Used
#   define CxC_Not_Used (12U)
#  endif

#  ifndef CxC_Type_12
#   define CxC_Type_12 (12U)
#  endif

#  ifndef CxC_VIEW_12
#   define CxC_VIEW_12 (12U)
#  endif

#  ifndef CxC_View_12
#   define CxC_View_12 (12U)
#  endif

#  ifndef Cx0D_HiBmLvr_Stat_HIBM_FLASH_ON_PSD
#   define Cx0D_HiBmLvr_Stat_HIBM_FLASH_ON_PSD (13U)
#  endif

#  ifndef Cx0D_N
#   define Cx0D_N (13U)
#  endif

#  ifndef Cx0D_Russian
#   define Cx0D_Russian (13U)
#  endif

#  ifndef Cx0D_TM13
#   define Cx0D_TM13 (13U)
#  endif

#  ifndef Cx8C_FD12_Psv_WU
#   define Cx8C_FD12_Psv_WU (140U)
#  endif

#  ifndef CxD_DISP_13
#   define CxD_DISP_13 (13U)
#  endif

#  ifndef CxD_Fault_EPB_Applied
#   define CxD_Fault_EPB_Applied (13U)
#  endif

#  ifndef CxD_Key_Authenticated
#   define CxD_Key_Authenticated (13U)
#  endif

#  ifndef CxD_Not_Used
#   define CxD_Not_Used (13U)
#  endif

#  ifndef CxD_Type_13
#   define CxD_Type_13 (13U)
#  endif

#  ifndef CxD_VIEW_13
#   define CxD_VIEW_13 (13U)
#  endif

#  ifndef CxD_View_13
#   define CxD_View_13 (13U)
#  endif

#  ifndef Cx0E_Chinese
#   define Cx0E_Chinese (14U)
#  endif

#  ifndef Cx0E_LowBeamSts_SET
#   define Cx0E_LowBeamSts_SET (14U)
#  endif

#  ifndef Cx0E_R
#   define Cx0E_R (14U)
#  endif

#  ifndef Cx0E_TM14
#   define Cx0E_TM14 (14U)
#  endif

#  ifndef Cx8D_FD13_Psv_WU
#   define Cx8D_FD13_Psv_WU (141U)
#  endif

#  ifndef CxE_DISP_14
#   define CxE_DISP_14 (14U)
#  endif

#  ifndef CxE_Fault_Present
#   define CxE_Fault_Present (14U)
#  endif

#  ifndef CxE_Not_Used
#   define CxE_Not_Used (14U)
#  endif

#  ifndef CxE_Type_14
#   define CxE_Type_14 (14U)
#  endif

#  ifndef CxE_VIEW_14
#   define CxE_VIEW_14 (14U)
#  endif

#  ifndef CxE_View_14
#   define CxE_View_14 (14U)
#  endif

#  ifndef Cx0F_D
#   define Cx0F_D (15U)
#  endif

#  ifndef Cx0F_Japanese
#   define Cx0F_Japanese (15U)
#  endif

#  ifndef Cx0F_ParkingLightSts_SET
#   define Cx0F_ParkingLightSts_SET (15U)
#  endif

#  ifndef Cx0F_TM15
#   define Cx0F_TM15 (15U)
#  endif

#  ifndef Cx8E_FD14_Psv_WU
#   define Cx8E_FD14_Psv_WU (142U)
#  endif

#  ifndef CxF_Type_15
#   define CxF_Type_15 (15U)
#  endif

#  ifndef CxF_VIEW_15
#   define CxF_VIEW_15 (15U)
#  endif

#  ifndef CxF_View_15
#   define CxF_View_15 (15U)
#  endif

#  ifndef Cx10_FlashToPass_SET
#   define Cx10_FlashToPass_SET (16U)
#  endif

#  ifndef Cx10_Korean
#   define Cx10_Korean (16U)
#  endif

#  ifndef Cx10_L
#   define Cx10_L (16U)
#  endif

#  ifndef Cx10_TM16
#   define Cx10_TM16 (16U)
#  endif

#  ifndef Cx8F_FD15_Psv_WU
#   define Cx8F_FD15_Psv_WU (143U)
#  endif

#  ifndef Cx11_Arabic
#   define Cx11_Arabic (17U)
#  endif

#  ifndef Cx11_M
#   define Cx11_M (17U)
#  endif

#  ifndef Cx11_RemStActvSts_Active
#   define Cx11_RemStActvSts_Active (17U)
#  endif

#  ifndef Cx11_TM17
#   define Cx11_TM17 (17U)
#  endif

#  ifndef Cx90_FD16_Psv_WU
#   define Cx90_FD16_Psv_WU (144U)
#  endif

#  ifndef Cx12_Czech
#   define Cx12_Czech (18U)
#  endif

#  ifndef Cx12_Fuel_Door_Release_Switch
#   define Cx12_Fuel_Door_Release_Switch (18U)
#  endif

#  ifndef Cx12_S
#   define Cx12_S (18U)
#  endif

#  ifndef Cx12_TM18
#   define Cx12_TM18 (18U)
#  endif

#  ifndef Cx91_FD17_Psv_WU
#   define Cx91_FD17_Psv_WU (145U)
#  endif

#  ifndef Cx13_ENGINE_FD_8_RefuelEvent_Pending
#   define Cx13_ENGINE_FD_8_RefuelEvent_Pending (19U)
#  endif

#  ifndef Cx13_Slovakian
#   define Cx13_Slovakian (19U)
#  endif

#  ifndef Cx13_TM19
#   define Cx13_TM19 (19U)
#  endif

#  ifndef Cx1F_SNA
#   define Cx1F_SNA (31U)
#  endif

#  ifndef Cx92_FD18_Psv_WU
#   define Cx92_FD18_Psv_WU (146U)
#  endif

#  ifndef Cx14_Hungarian
#   define Cx14_Hungarian (20U)
#  endif

#  ifndef Cx14_OHC_1_Front_Int_LG_Sw_1
#   define Cx14_OHC_1_Front_Int_LG_Sw_1 (20U)
#  endif

#  ifndef Cx14_TM20
#   define Cx14_TM20 (20U)
#  endif

#  ifndef Cx93_FD19_Psv_WU
#   define Cx93_FD19_Psv_WU (147U)
#  endif

#  ifndef Cx15_HFRM_1_RearKick
#   define Cx15_HFRM_1_RearKick (21U)
#  endif

#  ifndef Cx15_Hindi
#   define Cx15_Hindi (21U)
#  endif

#  ifndef Cx15_TM21
#   define Cx15_TM21 (21U)
#  endif

#  ifndef Cx94_FD20_Psv_WU
#   define Cx94_FD20_Psv_WU (148U)
#  endif

#  ifndef Cx16_LeakCheckTimerExpired
#   define Cx16_LeakCheckTimerExpired (22U)
#  endif

#  ifndef Cx16_TM22
#   define Cx16_TM22 (22U)
#  endif

#  ifndef Cx95_FD21_Psv_WU
#   define Cx95_FD21_Psv_WU (149U)
#  endif

#  ifndef Cx17_Horn_Req_Not_Pressed_to_Pressed
#   define Cx17_Horn_Req_Not_Pressed_to_Pressed (23U)
#  endif

#  ifndef Cx17_TM23
#   define Cx17_TM23 (23U)
#  endif

#  ifndef Cx96_FD22_Psv_WU
#   define Cx96_FD22_Psv_WU (150U)
#  endif

#  ifndef Cx18_Comfort_Enable_Time_not_0
#   define Cx18_Comfort_Enable_Time_not_0 (24U)
#  endif

#  ifndef Cx18_TM24
#   define Cx18_TM24 (24U)
#  endif

#  ifndef Cx97_FD23_Psv_WU
#   define Cx97_FD23_Psv_WU (151U)
#  endif

#  ifndef Cx19_CmdIgnSts_ACC_RUN_START
#   define Cx19_CmdIgnSts_ACC_RUN_START (25U)
#  endif

#  ifndef Cx19_TM25
#   define Cx19_TM25 (25U)
#  endif

#  ifndef Cx98_FD24_Psv_WU
#   define Cx98_FD24_Psv_WU (152U)
#  endif

#  ifndef Cx1A_ENGINE_FD_8_LeakTestSts_1
#   define Cx1A_ENGINE_FD_8_LeakTestSts_1 (26U)
#  endif

#  ifndef Cx1A_TM26
#   define Cx1A_TM26 (26U)
#  endif

#  ifndef Cx99_FD25_Psv_WU
#   define Cx99_FD25_Psv_WU (153U)
#  endif

#  ifndef Cx1B_Non_Default_Diagnostic_Session
#   define Cx1B_Non_Default_Diagnostic_Session (27U)
#  endif

#  ifndef Cx1B_TM27
#   define Cx1B_TM27 (27U)
#  endif

#  ifndef Cx9A_FD26_Psv_WU
#   define Cx9A_FD26_Psv_WU (154U)
#  endif

#  ifndef Cx1C_RL_Lk_Sw_LK_RQ_or_UNLK_RQ
#   define Cx1C_RL_Lk_Sw_LK_RQ_or_UNLK_RQ (28U)
#  endif

#  ifndef Cx1C_TM28
#   define Cx1C_TM28 (28U)
#  endif

#  ifndef Cx9B_FD27_Psv_WU
#   define Cx9B_FD27_Psv_WU (155U)
#  endif

#  ifndef Cx1D_RR_Lk_Sw_LK_RQ_or_UNLK_RQ
#   define Cx1D_RR_Lk_Sw_LK_RQ_or_UNLK_RQ (29U)
#  endif

#  ifndef Cx1D_TM29
#   define Cx1D_TM29 (29U)
#  endif

#  ifndef Cx9C_FD28_Psv_WU
#   define Cx9C_FD28_Psv_WU (156U)
#  endif

#  ifndef Cx1E_FD_CAN1
#   define Cx1E_FD_CAN1 (30U)
#  endif

#  ifndef Cx1E_TM30
#   define Cx1E_TM30 (30U)
#  endif

#  ifndef Cx9D_FD29_Psv_WU
#   define Cx9D_FD29_Psv_WU (157U)
#  endif

#  ifndef Cx1F_FD_CAN2
#   define Cx1F_FD_CAN2 (31U)
#  endif

#  ifndef Cx1F_TM31
#   define Cx1F_TM31 (31U)
#  endif

#  ifndef Cx9E_BHCAN_Psv_WU
#   define Cx9E_BHCAN_Psv_WU (158U)
#  endif

#  ifndef Cx20_FD_CAN3
#   define Cx20_FD_CAN3 (32U)
#  endif

#  ifndef Cx20_TM32
#   define Cx20_TM32 (32U)
#  endif

#  ifndef Cx9F_CCAN_Psv_WU
#   define Cx9F_CCAN_Psv_WU (159U)
#  endif

#  ifndef Cx21_FD_CAN4
#   define Cx21_FD_CAN4 (33U)
#  endif

#  ifndef Cx21_TM33
#   define Cx21_TM33 (33U)
#  endif

#  ifndef Cx22_BH_CAN
#   define Cx22_BH_CAN (34U)
#  endif

#  ifndef Cx22_TM34
#   define Cx22_TM34 (34U)
#  endif

#  ifndef Cx23_C_CAN1
#   define Cx23_C_CAN1 (35U)
#  endif

#  ifndef Cx23_TM35
#   define Cx23_TM35 (35U)
#  endif

#  ifndef Cx24_EVAP_SWC
#   define Cx24_EVAP_SWC (36U)
#  endif

#  ifndef Cx24_TM36
#   define Cx24_TM36 (36U)
#  endif

#  ifndef Cx25_FUEL_DR_REL_SWC
#   define Cx25_FUEL_DR_REL_SWC (37U)
#  endif

#  ifndef Cx25_TM37
#   define Cx25_TM37 (37U)
#  endif

#  ifndef Cx26_Other_Software_Factory_Component
#   define Cx26_Other_Software_Factory_Component (38U)
#  endif

#  ifndef Cx26_TM38
#   define Cx26_TM38 (38U)
#  endif

#  ifndef Cx27_OHC_1_Front_Map_LGT_RT_Sw
#   define Cx27_OHC_1_Front_Map_LGT_RT_Sw (39U)
#  endif

#  ifndef Cx27_TM39
#   define Cx27_TM39 (39U)
#  endif

#  ifndef Cx28_OHC_1_Front_Map_LGT_LT_Sw
#   define Cx28_OHC_1_Front_Map_LGT_LT_Sw (40U)
#  endif

#  ifndef Cx28_TM40
#   define Cx28_TM40 (40U)
#  endif

#  ifndef Cx29_Fog_Lights_Signal_
#   define Cx29_Fog_Lights_Signal_ (41U)
#  endif

#  ifndef Cx29_TM41
#   define Cx29_TM41 (41U)
#  endif

#  ifndef Cx2A_DOME_ON_OR_DOME_DEFEAT_
#   define Cx2A_DOME_ON_OR_DOME_DEFEAT_ (42U)
#  endif

#  ifndef Cx2A_TM42
#   define Cx2A_TM42 (42U)
#  endif

#  ifndef Cx2B_Screen_Open_Close_is_pressed
#   define Cx2B_Screen_Open_Close_is_pressed (43U)
#  endif

#  ifndef Cx2B_TM43
#   define Cx2B_TM43 (43U)
#  endif

#  ifndef Cx2C_Diagnostic_Message_Routing_DMR
#   define Cx2C_Diagnostic_Message_Routing_DMR (44U)
#  endif

#  ifndef Cx2C_TM44
#   define Cx2C_TM44 (44U)
#  endif

#  ifndef Cx2D_Reserved
#   define Cx2D_Reserved (45U)
#  endif

#  ifndef Cx2D_TM45
#   define Cx2D_TM45 (45U)
#  endif

#  ifndef Cx2E_Reserved
#   define Cx2E_Reserved (46U)
#  endif

#  ifndef Cx2E_TM46
#   define Cx2E_TM46 (46U)
#  endif

#  ifndef Cx2F_Reserved
#   define Cx2F_Reserved (47U)
#  endif

#  ifndef Cx2F_TM47
#   define Cx2F_TM47 (47U)
#  endif

#  ifndef Cx30_Reserved
#   define Cx30_Reserved (48U)
#  endif

#  ifndef Cx30_TM48
#   define Cx30_TM48 (48U)
#  endif

#  ifndef Cx31_Reserved
#   define Cx31_Reserved (49U)
#  endif

#  ifndef Cx31_TM49
#   define Cx31_TM49 (49U)
#  endif

#  ifndef Cx32_Reserved
#   define Cx32_Reserved (50U)
#  endif

#  ifndef Cx32_TM50
#   define Cx32_TM50 (50U)
#  endif

#  ifndef Cx33_Reserved
#   define Cx33_Reserved (51U)
#  endif

#  ifndef Cx33_TM51
#   define Cx33_TM51 (51U)
#  endif

#  ifndef Cx34_Reserved
#   define Cx34_Reserved (52U)
#  endif

#  ifndef Cx34_TM52
#   define Cx34_TM52 (52U)
#  endif

#  ifndef Cx35_Reserved
#   define Cx35_Reserved (53U)
#  endif

#  ifndef Cx35_TM53
#   define Cx35_TM53 (53U)
#  endif

#  ifndef Cx36_Reserved
#   define Cx36_Reserved (54U)
#  endif

#  ifndef Cx36_TM54
#   define Cx36_TM54 (54U)
#  endif

#  ifndef Cx37_Reserved
#   define Cx37_Reserved (55U)
#  endif

#  ifndef Cx37_TM55
#   define Cx37_TM55 (55U)
#  endif

#  ifndef Cx38_Reserved
#   define Cx38_Reserved (56U)
#  endif

#  ifndef Cx38_TM56
#   define Cx38_TM56 (56U)
#  endif

#  ifndef Cx39_Reserved
#   define Cx39_Reserved (57U)
#  endif

#  ifndef Cx39_TM57
#   define Cx39_TM57 (57U)
#  endif

#  ifndef Cx3A_Reserved
#   define Cx3A_Reserved (58U)
#  endif

#  ifndef Cx3A_TM58
#   define Cx3A_TM58 (58U)
#  endif

#  ifndef Cx3B_Reserved
#   define Cx3B_Reserved (59U)
#  endif

#  ifndef Cx3B_TM59
#   define Cx3B_TM59 (59U)
#  endif

#  ifndef Cx3C_Reserved
#   define Cx3C_Reserved (60U)
#  endif

#  ifndef Cx3C_TM60
#   define Cx3C_TM60 (60U)
#  endif

#  ifndef Cx3D_Reserved
#   define Cx3D_Reserved (61U)
#  endif

#  ifndef Cx3D_TM61
#   define Cx3D_TM61 (61U)
#  endif

#  ifndef Cx3E_Reserved
#   define Cx3E_Reserved (62U)
#  endif

#  ifndef Cx3E_TM62
#   define Cx3E_TM62 (62U)
#  endif

#  ifndef Cx3F_Reserved
#   define Cx3F_Reserved (63U)
#  endif

#  ifndef Cx3F_TM63
#   define Cx3F_TM63 (63U)
#  endif

#  ifndef Cx40_Reserved
#   define Cx40_Reserved (64U)
#  endif

#  ifndef Cx40_TM64
#   define Cx40_TM64 (64U)
#  endif

#  ifndef Cx41_Reserved
#   define Cx41_Reserved (65U)
#  endif

#  ifndef Cx41_TM65
#   define Cx41_TM65 (65U)
#  endif

#  ifndef Cx42_Reserved
#   define Cx42_Reserved (66U)
#  endif

#  ifndef Cx42_TM66
#   define Cx42_TM66 (66U)
#  endif

#  ifndef Cx43_Reserved
#   define Cx43_Reserved (67U)
#  endif

#  ifndef Cx43_TM67
#   define Cx43_TM67 (67U)
#  endif

#  ifndef Cx44_Reserved
#   define Cx44_Reserved (68U)
#  endif

#  ifndef Cx44_TM68
#   define Cx44_TM68 (68U)
#  endif

#  ifndef Cx45_Reserved
#   define Cx45_Reserved (69U)
#  endif

#  ifndef Cx45_TM69
#   define Cx45_TM69 (69U)
#  endif

#  ifndef Cx46_Reserved
#   define Cx46_Reserved (70U)
#  endif

#  ifndef Cx46_TM70
#   define Cx46_TM70 (70U)
#  endif

#  ifndef Cx47_Reserved
#   define Cx47_Reserved (71U)
#  endif

#  ifndef Cx47_TM71
#   define Cx47_TM71 (71U)
#  endif

#  ifndef Cx48_Reserved
#   define Cx48_Reserved (72U)
#  endif

#  ifndef Cx48_TM72
#   define Cx48_TM72 (72U)
#  endif

#  ifndef Cx49_Reserved
#   define Cx49_Reserved (73U)
#  endif

#  ifndef Cx49_TM73
#   define Cx49_TM73 (73U)
#  endif

#  ifndef Cx4A_Reserved
#   define Cx4A_Reserved (74U)
#  endif

#  ifndef Cx4A_TM74
#   define Cx4A_TM74 (74U)
#  endif

#  ifndef Cx4B_Reserved
#   define Cx4B_Reserved (75U)
#  endif

#  ifndef Cx4B_TM75
#   define Cx4B_TM75 (75U)
#  endif

#  ifndef Cx4C_Reserved
#   define Cx4C_Reserved (76U)
#  endif

#  ifndef Cx4C_TM76
#   define Cx4C_TM76 (76U)
#  endif

#  ifndef Cx4D_Reserved
#   define Cx4D_Reserved (77U)
#  endif

#  ifndef Cx4D_TM77
#   define Cx4D_TM77 (77U)
#  endif

#  ifndef Cx4E_Reserved
#   define Cx4E_Reserved (78U)
#  endif

#  ifndef Cx4E_TM78
#   define Cx4E_TM78 (78U)
#  endif

#  ifndef Cx4F_Reserved
#   define Cx4F_Reserved (79U)
#  endif

#  ifndef Cx4F_TM79
#   define Cx4F_TM79 (79U)
#  endif

#  ifndef Cx50_Reserved
#   define Cx50_Reserved (80U)
#  endif

#  ifndef Cx50_TM80
#   define Cx50_TM80 (80U)
#  endif

#  ifndef Cx51_Reserved
#   define Cx51_Reserved (81U)
#  endif

#  ifndef Cx51_TM81
#   define Cx51_TM81 (81U)
#  endif

#  ifndef Cx52_Reserved
#   define Cx52_Reserved (82U)
#  endif

#  ifndef Cx52_TM82
#   define Cx52_TM82 (82U)
#  endif

#  ifndef Cx53_Reserved
#   define Cx53_Reserved (83U)
#  endif

#  ifndef Cx53_TM83
#   define Cx53_TM83 (83U)
#  endif

#  ifndef Cx54_Reserved
#   define Cx54_Reserved (84U)
#  endif

#  ifndef Cx54_TM84
#   define Cx54_TM84 (84U)
#  endif

#  ifndef Cx55_Reserved
#   define Cx55_Reserved (85U)
#  endif

#  ifndef Cx55_TM85
#   define Cx55_TM85 (85U)
#  endif

#  ifndef Cx56_Reserved
#   define Cx56_Reserved (86U)
#  endif

#  ifndef Cx56_TM86
#   define Cx56_TM86 (86U)
#  endif

#  ifndef Cx57_Reserved
#   define Cx57_Reserved (87U)
#  endif

#  ifndef Cx57_TM87
#   define Cx57_TM87 (87U)
#  endif

#  ifndef Cx58_Reserved
#   define Cx58_Reserved (88U)
#  endif

#  ifndef Cx58_TM88
#   define Cx58_TM88 (88U)
#  endif

#  ifndef Cx59_Reserved
#   define Cx59_Reserved (89U)
#  endif

#  ifndef Cx59_TM89
#   define Cx59_TM89 (89U)
#  endif

#  ifndef Cx5A_Reserved
#   define Cx5A_Reserved (90U)
#  endif

#  ifndef Cx5A_TM90
#   define Cx5A_TM90 (90U)
#  endif

#  ifndef Cx5B_Reserved
#   define Cx5B_Reserved (91U)
#  endif

#  ifndef Cx5B_TM91
#   define Cx5B_TM91 (91U)
#  endif

#  ifndef Cx5C_Reserved
#   define Cx5C_Reserved (92U)
#  endif

#  ifndef Cx5C_TM92
#   define Cx5C_TM92 (92U)
#  endif

#  ifndef Cx5D_Reserved
#   define Cx5D_Reserved (93U)
#  endif

#  ifndef Cx5D_TM93
#   define Cx5D_TM93 (93U)
#  endif

#  ifndef Cx5E_Reserved
#   define Cx5E_Reserved (94U)
#  endif

#  ifndef Cx5E_TM94
#   define Cx5E_TM94 (94U)
#  endif

#  ifndef Cx5F_Reserved
#   define Cx5F_Reserved (95U)
#  endif

#  ifndef Cx5F_TM95
#   define Cx5F_TM95 (95U)
#  endif

#  ifndef Cx60_Reserved
#   define Cx60_Reserved (96U)
#  endif

#  ifndef Cx60_TM96
#   define Cx60_TM96 (96U)
#  endif

#  ifndef Cx61_Reserved
#   define Cx61_Reserved (97U)
#  endif

#  ifndef Cx61_TM97
#   define Cx61_TM97 (97U)
#  endif

#  ifndef Cx62_Reserved
#   define Cx62_Reserved (98U)
#  endif

#  ifndef Cx62_TM98
#   define Cx62_TM98 (98U)
#  endif

#  ifndef Cx63_Reserved
#   define Cx63_Reserved (99U)
#  endif

#  ifndef Cx63_TM99
#   define Cx63_TM99 (99U)
#  endif

#  ifndef Cx64_Reserved
#   define Cx64_Reserved (100U)
#  endif

#  ifndef Cx64_TM100
#   define Cx64_TM100 (100U)
#  endif

#  ifndef Cx65_Reserved
#   define Cx65_Reserved (101U)
#  endif

#  ifndef Cx66_Reserved
#   define Cx66_Reserved (102U)
#  endif

#  ifndef Cx67_Reserved
#   define Cx67_Reserved (103U)
#  endif

#  ifndef Cx68_Reserved
#   define Cx68_Reserved (104U)
#  endif

#  ifndef Cx69_Reserved
#   define Cx69_Reserved (105U)
#  endif

#  ifndef Cx6A_Reserved
#   define Cx6A_Reserved (106U)
#  endif

#  ifndef Cx6B_Reserved
#   define Cx6B_Reserved (107U)
#  endif

#  ifndef Cx6C_Reserved
#   define Cx6C_Reserved (108U)
#  endif

#  ifndef Cx6D_Reserved
#   define Cx6D_Reserved (109U)
#  endif

#  ifndef Cx6E_Reserved
#   define Cx6E_Reserved (110U)
#  endif

#  ifndef Cx6F_Reserved
#   define Cx6F_Reserved (111U)
#  endif

#  ifndef Cx70_Reserved
#   define Cx70_Reserved (112U)
#  endif

#  ifndef Cx71_Reserved
#   define Cx71_Reserved (113U)
#  endif

#  ifndef Cx72_Reserved
#   define Cx72_Reserved (114U)
#  endif

#  ifndef Cx73_Reserved
#   define Cx73_Reserved (115U)
#  endif

#  ifndef Cx74_Reserved
#   define Cx74_Reserved (116U)
#  endif

#  ifndef Cx75_Reserved
#   define Cx75_Reserved (117U)
#  endif

#  ifndef Cx76_Reserved
#   define Cx76_Reserved (118U)
#  endif

#  ifndef Cx77_Reserved
#   define Cx77_Reserved (119U)
#  endif

#  ifndef Cx78_Reserved
#   define Cx78_Reserved (120U)
#  endif

#  ifndef Cx79_Reserved
#   define Cx79_Reserved (121U)
#  endif

#  ifndef Cx7A_Reserved
#   define Cx7A_Reserved (122U)
#  endif

#  ifndef Cx7B_Reserved
#   define Cx7B_Reserved (123U)
#  endif

#  ifndef Cx7C_Reserved
#   define Cx7C_Reserved (124U)
#  endif

#  ifndef Cx7D_Reserved
#   define Cx7D_Reserved (125U)
#  endif

#  ifndef Cx7E_Reserved
#   define Cx7E_Reserved (126U)
#  endif

#  ifndef Cx7F_Reserved
#   define Cx7F_Reserved (127U)
#  endif

#  ifndef Cx80_Reserved
#   define Cx80_Reserved (128U)
#  endif

#  ifndef Cx81_FD_CAN1
#   define Cx81_FD_CAN1 (129U)
#  endif

#  ifndef Cx82_FD_CAN2
#   define Cx82_FD_CAN2 (130U)
#  endif

#  ifndef Cx83_FD_CAN3
#   define Cx83_FD_CAN3 (131U)
#  endif

#  ifndef Cx84_FD_CAN4
#   define Cx84_FD_CAN4 (132U)
#  endif

#  ifndef Cx85_FD_CAN5
#   define Cx85_FD_CAN5 (133U)
#  endif

#  ifndef Cx86_FD_CAN6
#   define Cx86_FD_CAN6 (134U)
#  endif

#  ifndef Cx87_FD_CAN7
#   define Cx87_FD_CAN7 (135U)
#  endif

#  ifndef Cx88_FD_CAN8
#   define Cx88_FD_CAN8 (136U)
#  endif

#  ifndef Cx89_FD_CAN9
#   define Cx89_FD_CAN9 (137U)
#  endif

#  ifndef Cx8A_FD_CAN10
#   define Cx8A_FD_CAN10 (138U)
#  endif

#  ifndef Cx8B_FD_CAN11
#   define Cx8B_FD_CAN11 (139U)
#  endif

#  ifndef Cx8C_FD_CAN12
#   define Cx8C_FD_CAN12 (140U)
#  endif

#  ifndef Cx8D_FD_CAN13
#   define Cx8D_FD_CAN13 (141U)
#  endif

#  ifndef Cx8E_FD_CAN14
#   define Cx8E_FD_CAN14 (142U)
#  endif

#  ifndef Cx8F_FD_CAN15
#   define Cx8F_FD_CAN15 (143U)
#  endif

#  ifndef Cx90_FD_CAN16
#   define Cx90_FD_CAN16 (144U)
#  endif

#  ifndef Cx91_FD_CAN17
#   define Cx91_FD_CAN17 (145U)
#  endif

#  ifndef Cx92_FD_CAN18
#   define Cx92_FD_CAN18 (146U)
#  endif

#  ifndef Cx93_FD_CAN19
#   define Cx93_FD_CAN19 (147U)
#  endif

#  ifndef Cx94_FD_CAN20
#   define Cx94_FD_CAN20 (148U)
#  endif

#  ifndef Cx95_FD_CAN21
#   define Cx95_FD_CAN21 (149U)
#  endif

#  ifndef Cx96_FD_CAN22
#   define Cx96_FD_CAN22 (150U)
#  endif

#  ifndef Cx97_FD_CAN23
#   define Cx97_FD_CAN23 (151U)
#  endif

#  ifndef Cx98_FD_CAN24
#   define Cx98_FD_CAN24 (152U)
#  endif

#  ifndef Cx99_FD_CAN25
#   define Cx99_FD_CAN25 (153U)
#  endif

#  ifndef Cx9A_FD_CAN26
#   define Cx9A_FD_CAN26 (154U)
#  endif

#  ifndef Cx9B_FD_CAN27
#   define Cx9B_FD_CAN27 (155U)
#  endif

#  ifndef Cx9C_FD_CAN28
#   define Cx9C_FD_CAN28 (156U)
#  endif

#  ifndef Cx9D_FD_CAN29
#   define Cx9D_FD_CAN29 (157U)
#  endif

#  ifndef Cx9E_FD_CAN30
#   define Cx9E_FD_CAN30 (158U)
#  endif

#  ifndef Cx9F_FD_CAN31
#   define Cx9F_FD_CAN31 (159U)
#  endif

#  ifndef CxA0_BH_CAN
#   define CxA0_BH_CAN (160U)
#  endif

#  ifndef CxA1_BH_CAN1
#   define CxA1_BH_CAN1 (161U)
#  endif

#  ifndef CxA2_BH_CAN2
#   define CxA2_BH_CAN2 (162U)
#  endif

#  ifndef CxA3_C_CAN
#   define CxA3_C_CAN (163U)
#  endif

#  ifndef CxA4_C_CAN1
#   define CxA4_C_CAN1 (164U)
#  endif

#  ifndef CxA5_Reserved
#   define CxA5_Reserved (165U)
#  endif

#  ifndef CxA6_Reserved
#   define CxA6_Reserved (166U)
#  endif

#  ifndef CxA7_Reserved
#   define CxA7_Reserved (167U)
#  endif

#  ifndef CxA8_Reserved
#   define CxA8_Reserved (168U)
#  endif

#  ifndef CxA9_Reserved
#   define CxA9_Reserved (169U)
#  endif

#  ifndef CxAA_Reserved
#   define CxAA_Reserved (170U)
#  endif

#  ifndef CxAB_Reserved
#   define CxAB_Reserved (171U)
#  endif

#  ifndef CxAC_Reserved
#   define CxAC_Reserved (172U)
#  endif

#  ifndef CxAD_Reserved
#   define CxAD_Reserved (173U)
#  endif

#  ifndef CxAE_Reserved
#   define CxAE_Reserved (174U)
#  endif

#  ifndef CxAF_Reserved
#   define CxAF_Reserved (175U)
#  endif

#  ifndef CxB0_Reserved
#   define CxB0_Reserved (176U)
#  endif

#  ifndef CxB1_Reserved
#   define CxB1_Reserved (177U)
#  endif

#  ifndef CxB2_Reserved
#   define CxB2_Reserved (178U)
#  endif

#  ifndef CxB3_Reserved
#   define CxB3_Reserved (179U)
#  endif

#  ifndef CxB4_Reserved
#   define CxB4_Reserved (180U)
#  endif

#  ifndef CxB5_Reserved
#   define CxB5_Reserved (181U)
#  endif

#  ifndef CxB6_Reserved
#   define CxB6_Reserved (182U)
#  endif

#  ifndef CxB7_Reserved
#   define CxB7_Reserved (183U)
#  endif

#  ifndef CxB8_Reserved
#   define CxB8_Reserved (184U)
#  endif

#  ifndef CxB9_Reserved
#   define CxB9_Reserved (185U)
#  endif

#  ifndef CxBA_Reserved
#   define CxBA_Reserved (186U)
#  endif

#  ifndef CxBB_Reserved
#   define CxBB_Reserved (187U)
#  endif

#  ifndef CxBC_Reserved
#   define CxBC_Reserved (188U)
#  endif

#  ifndef CxBD_Reserved
#   define CxBD_Reserved (189U)
#  endif

#  ifndef CxBE_Reserved
#   define CxBE_Reserved (190U)
#  endif

#  ifndef CxBF_Reserved
#   define CxBF_Reserved (191U)
#  endif

#  ifndef CxC0_Reserved
#   define CxC0_Reserved (192U)
#  endif

#  ifndef CxC1_Reserved
#   define CxC1_Reserved (193U)
#  endif

#  ifndef CxC2_Reserved
#   define CxC2_Reserved (194U)
#  endif

#  ifndef CxC3_Reserved
#   define CxC3_Reserved (195U)
#  endif

#  ifndef CxC4_Reserved
#   define CxC4_Reserved (196U)
#  endif

#  ifndef CxC5_Reserved
#   define CxC5_Reserved (197U)
#  endif

#  ifndef CxC6_Reserved
#   define CxC6_Reserved (198U)
#  endif

#  ifndef CxC7_Reserved
#   define CxC7_Reserved (199U)
#  endif

#  ifndef CxC8_Reserved
#   define CxC8_Reserved (200U)
#  endif

#  ifndef CxC9_Reserved
#   define CxC9_Reserved (201U)
#  endif

#  ifndef CxCA_Reserved
#   define CxCA_Reserved (202U)
#  endif

#  ifndef CxCB_Reserved
#   define CxCB_Reserved (203U)
#  endif

#  ifndef CxCC_Reserved
#   define CxCC_Reserved (204U)
#  endif

#  ifndef CxCD_Reserved
#   define CxCD_Reserved (205U)
#  endif

#  ifndef CxCE_Reserved
#   define CxCE_Reserved (206U)
#  endif

#  ifndef CxCF_Reserved
#   define CxCF_Reserved (207U)
#  endif

#  ifndef CxD0_Reserved
#   define CxD0_Reserved (208U)
#  endif

#  ifndef CxD1_Reserved
#   define CxD1_Reserved (209U)
#  endif

#  ifndef CxD2_Reserved
#   define CxD2_Reserved (210U)
#  endif

#  ifndef CxD3_Reserved
#   define CxD3_Reserved (211U)
#  endif

#  ifndef CxD4_Reserved
#   define CxD4_Reserved (212U)
#  endif

#  ifndef CxD5_Reserved
#   define CxD5_Reserved (213U)
#  endif

#  ifndef CxD6_Reserved
#   define CxD6_Reserved (214U)
#  endif

#  ifndef CxD7_Reserved
#   define CxD7_Reserved (215U)
#  endif

#  ifndef CxD8_Reserved
#   define CxD8_Reserved (216U)
#  endif

#  ifndef CxD9_Reserved
#   define CxD9_Reserved (217U)
#  endif

#  ifndef CxDA_Reserved
#   define CxDA_Reserved (218U)
#  endif

#  ifndef CxDB_Reserved
#   define CxDB_Reserved (219U)
#  endif

#  ifndef CxDC_Reserved
#   define CxDC_Reserved (220U)
#  endif

#  ifndef CxDD_Reserved
#   define CxDD_Reserved (221U)
#  endif

#  ifndef CxDE_Reserved
#   define CxDE_Reserved (222U)
#  endif

#  ifndef CxDF_Reserved
#   define CxDF_Reserved (223U)
#  endif

#  ifndef CxE0_Reserved
#   define CxE0_Reserved (224U)
#  endif

#  ifndef CxE1_Reserved
#   define CxE1_Reserved (225U)
#  endif

#  ifndef CxE2_Reserved
#   define CxE2_Reserved (226U)
#  endif

#  ifndef CxE3_Reserved
#   define CxE3_Reserved (227U)
#  endif

#  ifndef CxE4_Reserved
#   define CxE4_Reserved (228U)
#  endif

#  ifndef CxE5_Reserved
#   define CxE5_Reserved (229U)
#  endif

#  ifndef CxE6_Reserved
#   define CxE6_Reserved (230U)
#  endif

#  ifndef CxE7_Reserved
#   define CxE7_Reserved (231U)
#  endif

#  ifndef CxE8_Reserved
#   define CxE8_Reserved (232U)
#  endif

#  ifndef CxE9_Reserved
#   define CxE9_Reserved (233U)
#  endif

#  ifndef CxEA_Reserved
#   define CxEA_Reserved (234U)
#  endif

#  ifndef CxEB_Reserved
#   define CxEB_Reserved (235U)
#  endif

#  ifndef CxEC_Reserved
#   define CxEC_Reserved (236U)
#  endif

#  ifndef CxED_Reserved
#   define CxED_Reserved (237U)
#  endif

#  ifndef CxEE_Reserved
#   define CxEE_Reserved (238U)
#  endif

#  ifndef CxEF_Reserved
#   define CxEF_Reserved (239U)
#  endif

#  ifndef CxF0_Reserved
#   define CxF0_Reserved (240U)
#  endif

#  ifndef CxF1_Reserved
#   define CxF1_Reserved (241U)
#  endif

#  ifndef CxF2_Reserved
#   define CxF2_Reserved (242U)
#  endif

#  ifndef CxF3_Reserved
#   define CxF3_Reserved (243U)
#  endif

#  ifndef CxF4_Reserved
#   define CxF4_Reserved (244U)
#  endif

#  ifndef CxF5_Reserved
#   define CxF5_Reserved (245U)
#  endif

#  ifndef CxF6_Reserved
#   define CxF6_Reserved (246U)
#  endif

#  ifndef CxF7_Reserved
#   define CxF7_Reserved (247U)
#  endif

#  ifndef CxF8_Reserved
#   define CxF8_Reserved (248U)
#  endif

#  ifndef CxF9_Reserved
#   define CxF9_Reserved (249U)
#  endif

#  ifndef CxFA_Reserved
#   define CxFA_Reserved (250U)
#  endif

#  ifndef CxFB_Reserved
#   define CxFB_Reserved (251U)
#  endif

#  ifndef CxFC_Reserved
#   define CxFC_Reserved (252U)
#  endif

#  ifndef CxFD_Reserved
#   define CxFD_Reserved (253U)
#  endif

#  ifndef CxFE_Reserved
#   define CxFE_Reserved (254U)
#  endif

#  ifndef CxFF_Reserved
#   define CxFF_Reserved (255U)
#  endif

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_CDD_IPCHANDLER_TYPE_H */
