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
 *             File:  Rte_SWC_SafeVCANTx_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <SWC_SafeVCANTx>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SWC_SAFEVCANTX_TYPE_H
# define RTE_SWC_SAFEVCANTX_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  define InvalidValue_Alert_CHF (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx3_3_Arc
#   define Cx3_3_Arc (3U)
#  endif

#  ifndef Cx4_4_Arc
#   define Cx4_4_Arc (4U)
#  endif

#  ifndef Cx5_5_Arc
#   define Cx5_5_Arc (5U)
#  endif

#  ifndef Cx6_6_Arc
#   define Cx6_6_Arc (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_Alert_CHR (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx3_3_Arc
#   define Cx3_3_Arc (3U)
#  endif

#  ifndef Cx4_4_Arc
#   define Cx4_4_Arc (4U)
#  endif

#  ifndef Cx5_5_Arc
#   define Cx5_5_Arc (5U)
#  endif

#  ifndef Cx6_6_Arc
#   define Cx6_6_Arc (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_Alert_LHF (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_Alert_LHR (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_Alert_RHF (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_Alert_RHR (7U)

#  ifndef Cx0_No_object_detected
#   define Cx0_No_object_detected (0U)
#  endif

#  ifndef Cx1_1_Arc
#   define Cx1_1_Arc (1U)
#  endif

#  ifndef Cx2_2_Arc
#   define Cx2_2_Arc (2U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
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

#  ifndef Cx0_None_Active
#   define Cx0_None_Active (0U)
#  endif

#  ifndef Cx1_Left_Right_Front
#   define Cx1_Left_Right_Front (1U)
#  endif

#  ifndef Cx2_Left_Right
#   define Cx2_Left_Right (2U)
#  endif

#  ifndef Cx3_Left_Front
#   define Cx3_Left_Front (3U)
#  endif

#  ifndef Cx4_Right_Front
#   define Cx4_Right_Front (4U)
#  endif

#  ifndef Cx5_Front
#   define Cx5_Front (5U)
#  endif

#  ifndef Cx6_Left
#   define Cx6_Left (6U)
#  endif

#  ifndef Cx7_Right
#   define Cx7_Right (7U)
#  endif

#  ifndef Cx0_NotActive
#   define Cx0_NotActive (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx0_NotActive
#   define Cx0_NotActive (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx0_NotActive
#   define Cx0_NotActive (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx0_NotActive
#   define Cx0_NotActive (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_VIEW_1
#   define Cx1_VIEW_1 (1U)
#  endif

#  ifndef Cx2_VIEW_2
#   define Cx2_VIEW_2 (2U)
#  endif

#  ifndef Cx3_VIEW_3
#   define Cx3_VIEW_3 (3U)
#  endif

#  ifndef Cx4_VIEW_4
#   define Cx4_VIEW_4 (4U)
#  endif

#  ifndef Cx5_VIEW_5
#   define Cx5_VIEW_5 (5U)
#  endif

#  ifndef Cx6_VIEW_6
#   define Cx6_VIEW_6 (6U)
#  endif

#  ifndef Cx7_VIEW_7
#   define Cx7_VIEW_7 (7U)
#  endif

#  ifndef Cx8_VIEW_8
#   define Cx8_VIEW_8 (8U)
#  endif

#  ifndef Cx9_VIEW_9
#   define Cx9_VIEW_9 (9U)
#  endif

#  ifndef CxA_VIEW_10
#   define CxA_VIEW_10 (10U)
#  endif

#  ifndef CxB_VIEW_11
#   define CxB_VIEW_11 (11U)
#  endif

#  ifndef CxC_VIEW_12
#   define CxC_VIEW_12 (12U)
#  endif

#  ifndef CxD_VIEW_13
#   define CxD_VIEW_13 (13U)
#  endif

#  ifndef CxE_VIEW_14
#   define CxE_VIEW_14 (14U)
#  endif

#  ifndef CxF_VIEW_15
#   define CxF_VIEW_15 (15U)
#  endif

#  ifndef E2E_MEP_DATAID_BOTH
#   define E2E_MEP_DATAID_BOTH (0U)
#  endif

#  ifndef E2E_MEP_DATAID_ALT
#   define E2E_MEP_DATAID_ALT (1U)
#  endif

#  ifndef E2E_MEP_DATAID_LOW
#   define E2E_MEP_DATAID_LOW (2U)
#  endif

#  ifndef E2E_MEP_DATAID_NIBBLE
#   define E2E_MEP_DATAID_NIBBLE (3U)
#  endif

#  ifndef Cx0_None_Active
#   define Cx0_None_Active (0U)
#  endif

#  ifndef Cx1_Left_Right_Front
#   define Cx1_Left_Right_Front (1U)
#  endif

#  ifndef Cx2_Left_Right
#   define Cx2_Left_Right (2U)
#  endif

#  ifndef Cx3_Left_Front
#   define Cx3_Left_Front (3U)
#  endif

#  ifndef Cx4_Right_Front
#   define Cx4_Right_Front (4U)
#  endif

#  ifndef Cx5_Front
#   define Cx5_Front (5U)
#  endif

#  ifndef Cx6_Left
#   define Cx6_Left (6U)
#  endif

#  ifndef Cx7_Right
#   define Cx7_Right (7U)
#  endif

#  ifndef Cx0_Not_Detected
#   define Cx0_Not_Detected (0U)
#  endif

#  ifndef Cx1_Detected_Low_Confidence
#   define Cx1_Detected_Low_Confidence (1U)
#  endif

#  ifndef Cx2_Detected_Medium_Confidence
#   define Cx2_Detected_Medium_Confidence (2U)
#  endif

#  ifndef Cx3_Detected_High_Confidence
#   define Cx3_Detected_High_Confidence (3U)
#  endif

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Blocked
#   define Cx1_Blocked (1U)
#  endif

#  ifndef Cx2_Unknown
#   define Cx2_Unknown (2U)
#  endif

#  ifndef Cx3_Healthy
#   define Cx3_Healthy (3U)
#  endif

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Blocked
#   define Cx1_Blocked (1U)
#  endif

#  ifndef Cx2_Unknown
#   define Cx2_Unknown (2U)
#  endif

#  ifndef Cx3_Healthy
#   define Cx3_Healthy (3U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_Backward
#   define Cx0_Backward (0U)
#  endif

#  ifndef Cx1_Forward
#   define Cx1_Forward (1U)
#  endif

#  define InvalidValue_FD14_PPPA_Interface_BSM (3U)

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx1_CVPAM_Request
#   define Cx1_CVPAM_Request (1U)
#  endif

#  ifndef Cx2_Faulted
#   define Cx2_Faulted (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_FD14_PPPA_MaxSpeed (255U)

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  define InvalidValue_FD14_PPPA_TargetDistance (1023U)

#  ifndef Cx3FF_SNA
#   define Cx3FF_SNA (1023U)
#  endif

#  define InvalidValue_FD14_ParkingGearShiftReq (7U)

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
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

#  ifndef Cx5_Not_Used
#   define Cx5_Not_Used (5U)
#  endif

#  ifndef Cx6_Not_Used
#   define Cx6_Not_Used (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  define InvalidValue_FD14_ParkingManeuverActive (7U)

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx1_Enabled_Seeking
#   define Cx1_Enabled_Seeking (1U)
#  endif

#  ifndef Cx2_Engaged_Semi
#   define Cx2_Engaged_Semi (2U)
#  endif

#  ifndef Cx3_Engaged_Full
#   define Cx3_Engaged_Full (3U)
#  endif

#  ifndef Cx4_Not_Used
#   define Cx4_Not_Used (4U)
#  endif

#  ifndef Cx5_Not_Used
#   define Cx5_Not_Used (5U)
#  endif

#  ifndef Cx6_Not_Used
#   define Cx6_Not_Used (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define InvalidValue_FD14_RR_PAM_Dist (1023U)

#  ifndef Cx3FF_SNA
#   define Cx3FF_SNA (1023U)
#  endif

#  ifndef Cx0_IDLE
#   define Cx0_IDLE (0U)
#  endif

#  ifndef Cx1_Faulted
#   define Cx1_Faulted (1U)
#  endif

#  ifndef Cx2_SPM_Request
#   define Cx2_SPM_Request (2U)
#  endif

#  ifndef Cx0_Not_Detected
#   define Cx0_Not_Detected (0U)
#  endif

#  ifndef Cx1_Detected_Low_Confidence
#   define Cx1_Detected_Low_Confidence (1U)
#  endif

#  ifndef Cx2_Detected_Medium_Confidence
#   define Cx2_Detected_Medium_Confidence (2U)
#  endif

#  ifndef Cx3_Detected_High_Confidence
#   define Cx3_Detected_High_Confidence (3U)
#  endif

#  define InvalidValue_FT_PAM_LedControlSts (3U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_Continuous_Light
#   define Cx1_Continuous_Light (1U)
#  endif

#  ifndef Cx2_2Blinking_Light
#   define Cx2_2Blinking_Light (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_FrontSensorSts (3U)

#  ifndef Cx0_Active
#   define Cx0_Active (0U)
#  endif

#  ifndef Cx1_Not_Active_blocked
#   define Cx1_Not_Active_blocked (1U)
#  endif

#  ifndef Cx2_Not_Active_failure
#   define Cx2_Not_Active_failure (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_CHF (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_CHR (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_LHF (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_LHR (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_RHF (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_Graphic_RHR (3U)

#  ifndef Cx0_Slow_flash
#   define Cx0_Slow_flash (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_None
#   define Cx2_None (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Blocked
#   define Cx1_Blocked (1U)
#  endif

#  ifndef Cx2_Unknown
#   define Cx2_Unknown (2U)
#  endif

#  ifndef Cx3_Healthy
#   define Cx3_Healthy (3U)
#  endif

#  ifndef Cx0_Faulted
#   define Cx0_Faulted (0U)
#  endif

#  ifndef Cx1_Blocked
#   define Cx1_Blocked (1U)
#  endif

#  ifndef Cx2_Unknown
#   define Cx2_Unknown (2U)
#  endif

#  ifndef Cx3_Healthy
#   define Cx3_Healthy (3U)
#  endif

#  ifndef Cx0_NOT_PRESSED
#   define Cx0_NOT_PRESSED (0U)
#  endif

#  ifndef Cx1_PRESSED
#   define Cx1_PRESSED (1U)
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

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Dashed
#   define Cx2_Dashed (2U)
#  endif

#  ifndef Cx3_Double
#   define Cx3_Double (3U)
#  endif

#  ifndef Cx4_Road_edge
#   define Cx4_Road_edge (4U)
#  endif

#  ifndef Cx5_Botts_Dotts
#   define Cx5_Botts_Dotts (5U)
#  endif

#  ifndef Cx6_Barrier
#   define Cx6_Barrier (6U)
#  endif

#  ifndef Cx0_Not_Pressed
#   define Cx0_Not_Pressed (0U)
#  endif

#  ifndef Cx1_Pressed
#   define Cx1_Pressed (1U)
#  endif

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx1_Temporary_Failure
#   define Cx1_Temporary_Failure (1U)
#  endif

#  ifndef Cx2_External_Failure
#   define Cx2_External_Failure (2U)
#  endif

#  ifndef Cx3_System_Failure
#   define Cx3_System_Failure (3U)
#  endif

#  ifndef Cx0_Continuous_0_Hz
#   define Cx0_Continuous_0_Hz (0U)
#  endif

#  ifndef Cx2_Slow_2_Hz
#   define Cx2_Slow_2_Hz (2U)
#  endif

#  ifndef Cx3_Slow_3_Hz
#   define Cx3_Slow_3_Hz (3U)
#  endif

#  ifndef Cx4_Fast_4_Hz
#   define Cx4_Fast_4_Hz (4U)
#  endif

#  ifndef Cx5_Fast_5_Hz
#   define Cx5_Fast_5_Hz (5U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Type_1
#   define Cx1_Type_1 (1U)
#  endif

#  ifndef Cx2_Type_2
#   define Cx2_Type_2 (2U)
#  endif

#  ifndef Cx3_Type_3
#   define Cx3_Type_3 (3U)
#  endif

#  ifndef Cx4_Type_4
#   define Cx4_Type_4 (4U)
#  endif

#  ifndef Cx5_Type_5
#   define Cx5_Type_5 (5U)
#  endif

#  ifndef Cx6_Type_6
#   define Cx6_Type_6 (6U)
#  endif

#  ifndef Cx7_Type_7
#   define Cx7_Type_7 (7U)
#  endif

#  ifndef Cx8_Type_8
#   define Cx8_Type_8 (8U)
#  endif

#  ifndef Cx9_Type_9
#   define Cx9_Type_9 (9U)
#  endif

#  ifndef CxA_Type_10
#   define CxA_Type_10 (10U)
#  endif

#  ifndef CxB_Type_11
#   define CxB_Type_11 (11U)
#  endif

#  ifndef CxC_Type_12
#   define CxC_Type_12 (12U)
#  endif

#  ifndef CxD_Type_13
#   define CxD_Type_13 (13U)
#  endif

#  ifndef CxE_Type_14
#   define CxE_Type_14 (14U)
#  endif

#  ifndef CxF_Type_15
#   define CxF_Type_15 (15U)
#  endif

#  define InvalidValue_PAM_LedControlSts (3U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_Continuous_light
#   define Cx1_Continuous_light (1U)
#  endif

#  ifndef Cx2_Blinking_light
#   define Cx2_Blinking_light (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef Cx0_SYSTEM_ON
#   define Cx0_SYSTEM_ON (0U)
#  endif

#  ifndef Cx1_SYSTEM_OFF
#   define Cx1_SYSTEM_OFF (1U)
#  endif

#  ifndef Cx0_FT_OFF_RR_OFF
#   define Cx0_FT_OFF_RR_OFF (0U)
#  endif

#  ifndef Cx1_FT_OFF_RR_ON
#   define Cx1_FT_OFF_RR_ON (1U)
#  endif

#  ifndef Cx2_FT_ON_RR_OFF
#   define Cx2_FT_ON_RR_OFF (2U)
#  endif

#  ifndef Cx3_FT_ON_RR_ON
#   define Cx3_FT_ON_RR_ON (3U)
#  endif

#  define InvalidValue_PAM_PopUpRqst (255U)

#  ifndef Cx00_TM0
#   define Cx00_TM0 (0U)
#  endif

#  ifndef Cx01_TM1
#   define Cx01_TM1 (1U)
#  endif

#  ifndef Cx02_TM2
#   define Cx02_TM2 (2U)
#  endif

#  ifndef Cx03_TM3
#   define Cx03_TM3 (3U)
#  endif

#  ifndef Cx04_TM4
#   define Cx04_TM4 (4U)
#  endif

#  ifndef Cx05_TM5
#   define Cx05_TM5 (5U)
#  endif

#  ifndef Cx06_TM6
#   define Cx06_TM6 (6U)
#  endif

#  ifndef Cx07_TM7
#   define Cx07_TM7 (7U)
#  endif

#  ifndef Cx08_TM8
#   define Cx08_TM8 (8U)
#  endif

#  ifndef Cx09_TM9
#   define Cx09_TM9 (9U)
#  endif

#  ifndef Cx0A_TM10
#   define Cx0A_TM10 (10U)
#  endif

#  ifndef Cx0B_TM11
#   define Cx0B_TM11 (11U)
#  endif

#  ifndef Cx0C_TM12
#   define Cx0C_TM12 (12U)
#  endif

#  ifndef Cx0D_TM13
#   define Cx0D_TM13 (13U)
#  endif

#  ifndef Cx0E_TM14
#   define Cx0E_TM14 (14U)
#  endif

#  ifndef Cx0F_TM15
#   define Cx0F_TM15 (15U)
#  endif

#  ifndef Cx10_TM16
#   define Cx10_TM16 (16U)
#  endif

#  ifndef Cx11_TM17
#   define Cx11_TM17 (17U)
#  endif

#  ifndef Cx12_TM18
#   define Cx12_TM18 (18U)
#  endif

#  ifndef Cx13_TM19
#   define Cx13_TM19 (19U)
#  endif

#  ifndef Cx14_TM20
#   define Cx14_TM20 (20U)
#  endif

#  ifndef Cx15_TM21
#   define Cx15_TM21 (21U)
#  endif

#  ifndef Cx16_TM22
#   define Cx16_TM22 (22U)
#  endif

#  ifndef Cx17_TM23
#   define Cx17_TM23 (23U)
#  endif

#  ifndef Cx18_TM24
#   define Cx18_TM24 (24U)
#  endif

#  ifndef Cx19_TM25
#   define Cx19_TM25 (25U)
#  endif

#  ifndef Cx1A_TM26
#   define Cx1A_TM26 (26U)
#  endif

#  ifndef Cx1B_TM27
#   define Cx1B_TM27 (27U)
#  endif

#  ifndef Cx1C_TM28
#   define Cx1C_TM28 (28U)
#  endif

#  ifndef Cx1D_TM29
#   define Cx1D_TM29 (29U)
#  endif

#  ifndef Cx1E_TM30
#   define Cx1E_TM30 (30U)
#  endif

#  ifndef Cx1F_TM31
#   define Cx1F_TM31 (31U)
#  endif

#  ifndef Cx20_TM32
#   define Cx20_TM32 (32U)
#  endif

#  ifndef Cx21_TM33
#   define Cx21_TM33 (33U)
#  endif

#  ifndef Cx22_TM34
#   define Cx22_TM34 (34U)
#  endif

#  ifndef Cx23_TM35
#   define Cx23_TM35 (35U)
#  endif

#  ifndef Cx24_TM36
#   define Cx24_TM36 (36U)
#  endif

#  ifndef Cx25_TM37
#   define Cx25_TM37 (37U)
#  endif

#  ifndef Cx26_TM38
#   define Cx26_TM38 (38U)
#  endif

#  ifndef Cx27_TM39
#   define Cx27_TM39 (39U)
#  endif

#  ifndef Cx28_TM40
#   define Cx28_TM40 (40U)
#  endif

#  ifndef Cx29_TM41
#   define Cx29_TM41 (41U)
#  endif

#  ifndef Cx2A_TM42
#   define Cx2A_TM42 (42U)
#  endif

#  ifndef Cx2B_TM43
#   define Cx2B_TM43 (43U)
#  endif

#  ifndef Cx2C_TM44
#   define Cx2C_TM44 (44U)
#  endif

#  ifndef Cx2D_TM45
#   define Cx2D_TM45 (45U)
#  endif

#  ifndef Cx2E_TM46
#   define Cx2E_TM46 (46U)
#  endif

#  ifndef Cx2F_TM47
#   define Cx2F_TM47 (47U)
#  endif

#  ifndef Cx30_TM48
#   define Cx30_TM48 (48U)
#  endif

#  ifndef Cx31_TM49
#   define Cx31_TM49 (49U)
#  endif

#  ifndef Cx32_TM50
#   define Cx32_TM50 (50U)
#  endif

#  ifndef Cx33_TM51
#   define Cx33_TM51 (51U)
#  endif

#  ifndef Cx34_TM52
#   define Cx34_TM52 (52U)
#  endif

#  ifndef Cx35_TM53
#   define Cx35_TM53 (53U)
#  endif

#  ifndef Cx36_TM54
#   define Cx36_TM54 (54U)
#  endif

#  ifndef Cx37_TM55
#   define Cx37_TM55 (55U)
#  endif

#  ifndef Cx38_TM56
#   define Cx38_TM56 (56U)
#  endif

#  ifndef Cx39_TM57
#   define Cx39_TM57 (57U)
#  endif

#  ifndef Cx3A_TM58
#   define Cx3A_TM58 (58U)
#  endif

#  ifndef Cx3B_TM59
#   define Cx3B_TM59 (59U)
#  endif

#  ifndef Cx3C_TM60
#   define Cx3C_TM60 (60U)
#  endif

#  ifndef Cx3D_TM61
#   define Cx3D_TM61 (61U)
#  endif

#  ifndef Cx3E_TM62
#   define Cx3E_TM62 (62U)
#  endif

#  ifndef Cx3F_TM63
#   define Cx3F_TM63 (63U)
#  endif

#  ifndef Cx40_TM64
#   define Cx40_TM64 (64U)
#  endif

#  ifndef Cx41_TM65
#   define Cx41_TM65 (65U)
#  endif

#  ifndef Cx42_TM66
#   define Cx42_TM66 (66U)
#  endif

#  ifndef Cx43_TM67
#   define Cx43_TM67 (67U)
#  endif

#  ifndef Cx44_TM68
#   define Cx44_TM68 (68U)
#  endif

#  ifndef Cx45_TM69
#   define Cx45_TM69 (69U)
#  endif

#  ifndef Cx46_TM70
#   define Cx46_TM70 (70U)
#  endif

#  ifndef Cx47_TM71
#   define Cx47_TM71 (71U)
#  endif

#  ifndef Cx48_TM72
#   define Cx48_TM72 (72U)
#  endif

#  ifndef Cx49_TM73
#   define Cx49_TM73 (73U)
#  endif

#  ifndef Cx4A_TM74
#   define Cx4A_TM74 (74U)
#  endif

#  ifndef Cx4B_TM75
#   define Cx4B_TM75 (75U)
#  endif

#  ifndef Cx4C_TM76
#   define Cx4C_TM76 (76U)
#  endif

#  ifndef Cx4D_TM77
#   define Cx4D_TM77 (77U)
#  endif

#  ifndef Cx4E_TM78
#   define Cx4E_TM78 (78U)
#  endif

#  ifndef Cx4F_TM79
#   define Cx4F_TM79 (79U)
#  endif

#  ifndef Cx50_TM80
#   define Cx50_TM80 (80U)
#  endif

#  ifndef Cx51_TM81
#   define Cx51_TM81 (81U)
#  endif

#  ifndef Cx52_TM82
#   define Cx52_TM82 (82U)
#  endif

#  ifndef Cx53_TM83
#   define Cx53_TM83 (83U)
#  endif

#  ifndef Cx54_TM84
#   define Cx54_TM84 (84U)
#  endif

#  ifndef Cx55_TM85
#   define Cx55_TM85 (85U)
#  endif

#  ifndef Cx56_TM86
#   define Cx56_TM86 (86U)
#  endif

#  ifndef Cx57_TM87
#   define Cx57_TM87 (87U)
#  endif

#  ifndef Cx58_TM88
#   define Cx58_TM88 (88U)
#  endif

#  ifndef Cx59_TM89
#   define Cx59_TM89 (89U)
#  endif

#  ifndef Cx5A_TM90
#   define Cx5A_TM90 (90U)
#  endif

#  ifndef Cx5B_TM91
#   define Cx5B_TM91 (91U)
#  endif

#  ifndef Cx5C_TM92
#   define Cx5C_TM92 (92U)
#  endif

#  ifndef Cx5D_TM93
#   define Cx5D_TM93 (93U)
#  endif

#  ifndef Cx5E_TM94
#   define Cx5E_TM94 (94U)
#  endif

#  ifndef Cx5F_TM95
#   define Cx5F_TM95 (95U)
#  endif

#  ifndef Cx60_TM96
#   define Cx60_TM96 (96U)
#  endif

#  ifndef Cx61_TM97
#   define Cx61_TM97 (97U)
#  endif

#  ifndef Cx62_TM98
#   define Cx62_TM98 (98U)
#  endif

#  ifndef Cx63_TM99
#   define Cx63_TM99 (99U)
#  endif

#  ifndef Cx64_TM100
#   define Cx64_TM100 (100U)
#  endif

#  ifndef CxFF_SNA
#   define CxFF_SNA (255U)
#  endif

#  ifndef Cx0_None
#   define Cx0_None (0U)
#  endif

#  ifndef Cx1_Low
#   define Cx1_Low (1U)
#  endif

#  ifndef Cx2_Medium
#   define Cx2_Medium (2U)
#  endif

#  ifndef Cx3_High
#   define Cx3_High (3U)
#  endif

#  define InvalidValue_PPPA_TurnIndicatorRqst (3U)

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx1_Right
#   define Cx1_Right (1U)
#  endif

#  ifndef Cx2_Left
#   define Cx2_Left (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  define InvalidValue_ParkingManeuverActive (7U)

#  ifndef Cx0_Idle
#   define Cx0_Idle (0U)
#  endif

#  ifndef Cx1_Enabled_Seeking
#   define Cx1_Enabled_Seeking (1U)
#  endif

#  ifndef Cx2_Engaged_Semi
#   define Cx2_Engaged_Semi (2U)
#  endif

#  ifndef Cx3_Engaged_Full
#   define Cx3_Engaged_Full (3U)
#  endif

#  ifndef Cx4_Not_Used
#   define Cx4_Not_Used (4U)
#  endif

#  ifndef Cx5_Not_Used
#   define Cx5_Not_Used (5U)
#  endif

#  ifndef Cx6_Not_Used
#   define Cx6_Not_Used (6U)
#  endif

#  ifndef Cx7_SNA
#   define Cx7_SNA (7U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define InvalidValue_RR_PAM_Dist (1023U)

#  ifndef Cx3FF_SNA
#   define Cx3FF_SNA (1023U)
#  endif

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_On
#   define Cx1_On (1U)
#  endif

#  define InvalidValue_RearSensorSts (3U)

#  ifndef Cx0_Active
#   define Cx0_Active (0U)
#  endif

#  ifndef Cx1_Not_Active_blocked
#   define Cx1_Not_Active_blocked (1U)
#  endif

#  ifndef Cx2_Not_Active_failure
#   define Cx2_Not_Active_failure (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
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

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx1_Active_ParallelParking
#   define Cx1_Active_ParallelParking (1U)
#  endif

#  ifndef Cx2_Active_PerpendicularParking
#   define Cx2_Active_PerpendicularParking (2U)
#  endif

#  ifndef Cx3_Active_OutParking
#   define Cx3_Active_OutParking (3U)
#  endif

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx1_True
#   define Cx1_True (1U)
#  endif

#  ifndef Cx0_False
#   define Cx0_False (0U)
#  endif

#  ifndef Cx1_True
#   define Cx1_True (1U)
#  endif

#  define InvalidValue_SPM_LedControlSts (3U)

#  ifndef Cx0_Off
#   define Cx0_Off (0U)
#  endif

#  ifndef Cx1_Continuous_light
#   define Cx1_Continuous_light (1U)
#  endif

#  ifndef Cx2_Blinking_light
#   define Cx2_Blinking_light (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
#  endif

#  ifndef Cx0_Not_Active
#   define Cx0_Not_Active (0U)
#  endif

#  ifndef Cx1_Active
#   define Cx1_Active (1U)
#  endif

#  ifndef SSM_DEGRADEDSTATE_MAX
#   define SSM_DEGRADEDSTATE_MAX (0U)
#  endif

#  ifndef SSM_STATE_BOOTING
#   define SSM_STATE_BOOTING (0U)
#  endif

#  ifndef SSM_STATE_IPCREADY
#   define SSM_STATE_IPCREADY (1U)
#  endif

#  ifndef SSM_STATE_RUNNING
#   define SSM_STATE_RUNNING (2U)
#  endif

#  ifndef SSM_STATE_DEGRADED
#   define SSM_STATE_DEGRADED (3U)
#  endif

#  ifndef SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP
#   define SSM_STATE_SLAVECORES_STARTSHUTDOWNCLEANUP (4U)
#  endif

#  ifndef SSM_STATE_SHUTTINGDOWN_REMOTECORES
#   define SSM_STATE_SHUTTINGDOWN_REMOTECORES (5U)
#  endif

#  ifndef SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE
#   define SSM_STATE_MASTERCORE_SHUTDOWNJOBSEXECUTE (6U)
#  endif

#  ifndef SSM_STATE_OFF
#   define SSM_STATE_OFF (7U)
#  endif

#  ifndef SSM_STATE_BOOT_ERROR
#   define SSM_STATE_BOOT_ERROR (8U)
#  endif

#  ifndef SSM_STATE_MAX
#   define SSM_STATE_MAX (9U)
#  endif

#  define InvalidValue_TRSC_LED_Stat (3U)

#  ifndef Cx0_OFF
#   define Cx0_OFF (0U)
#  endif

#  ifndef Cx1_Solid
#   define Cx1_Solid (1U)
#  endif

#  ifndef Cx2_Blinking
#   define Cx2_Blinking (2U)
#  endif

#  ifndef Cx3_SNA
#   define Cx3_SNA (3U)
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

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_ON
#   define TeTRSC_e_TrlrHitchLightCtrl_ON (0U)
#  endif

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_OFF
#   define TeTRSC_e_TrlrHitchLightCtrl_OFF (1U)
#  endif

#  ifndef TeTRSC_e_TrlrHitchLightCtrl_SNA
#   define TeTRSC_e_TrlrHitchLightCtrl_SNA (3U)
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

# endif /* RTE_CORE */

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SWC_SAFEVCANTX_TYPE_H */
