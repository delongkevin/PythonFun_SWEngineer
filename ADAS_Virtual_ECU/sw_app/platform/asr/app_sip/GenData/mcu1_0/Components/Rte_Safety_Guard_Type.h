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
 *             File:  Rte_Safety_Guard_Type.h
 *           Config:  L2H4060_CVADAS_MCU1_0.dpa
 *      ECU-Project:  L2H4060_CVADAS_MCU1_0
 *
 *        Generator:  MICROSAR RTE Generator Version 4.31.0
 *                    RTE Core Version 4.31.0
 *          License:  CBD2101089
 *
 *      Description:  Application types header file for SW-C <Safety_Guard>
 *********************************************************************************************************************/

/* double include prevention */
#ifndef RTE_SAFETY_GUARD_TYPE_H
# define RTE_SAFETY_GUARD_TYPE_H

# ifdef __cplusplus
extern "C"
{
# endif /* __cplusplus */

# include "Rte_Type.h"

# ifndef RTE_CORE

/**********************************************************************************************************************
 * Range, Invalidation, Enumeration and Bit Field Definitions
 *********************************************************************************************************************/

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


/**********************************************************************************************************************
 * Definitions for Mode Management
 *********************************************************************************************************************/
# ifndef RTE_MODETYPE_SafetyGuard_BSWM_SafeMode
#  define RTE_MODETYPE_SafetyGuard_BSWM_SafeMode
typedef uint8 Rte_ModeType_SafetyGuard_BSWM_SafeMode;
# endif

# define RTE_MODE_Safety_Guard_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL (0U)
# ifndef RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL
#  define RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETTYGUARD_SAFASTATE_NORMAL (0U)
# endif
# define RTE_MODE_Safety_Guard_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET (1U)
# ifndef RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET
#  define RTE_MODE_SafetyGuard_BSWM_SafeMode_SAFETYGUARD_SAFESTATE_2_RESET (1U)
# endif
# define RTE_TRANSITION_Safety_Guard_SafetyGuard_BSWM_SafeMode (2U)
# ifndef RTE_TRANSITION_SafetyGuard_BSWM_SafeMode
#  define RTE_TRANSITION_SafetyGuard_BSWM_SafeMode (2U)
# endif

# ifdef __cplusplus
} /* extern "C" */
# endif /* __cplusplus */

#endif /* RTE_SAFETY_GUARD_TYPE_H */
