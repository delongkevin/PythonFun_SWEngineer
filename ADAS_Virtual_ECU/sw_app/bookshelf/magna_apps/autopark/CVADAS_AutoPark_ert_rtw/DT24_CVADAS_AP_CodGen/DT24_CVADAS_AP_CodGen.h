/*
 * File: DT24_CVADAS_AP_CodGen.h
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

#ifndef RTW_HEADER_DT24_CVADAS_AP_CodGen_h_
#define RTW_HEADER_DT24_CVADAS_AP_CodGen_h_
#include <math.h>
#include <string.h>
#ifndef DT24_CVADAS_AP_CodGen_COMMON_INCLUDES_
# define DT24_CVADAS_AP_CodGen_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                              /* DT24_CVADAS_AP_CodGen_COMMON_INCLUDES_ */

#include "DT24_CVADAS_AP_CodGen_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#define DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_
#include "DT24_CVADAS_AutoPark_Func.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

/* Exported data define */

/* Definition for custom storage class: Define */
#define CeAP_cm_CurbLatchDist          170.0F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cm_DefaultRearDistInt16   1023                      /* Referenced by:
                                                                  * '<Root>/CVADAS_AutoPark_Main'
                                                                  * '<S155>/Constant1'
                                                                  * '<S156>/Constant1'
                                                                  * '<S157>/Constant1'
                                                                  * '<S158>/Constant1'
                                                                  * '<S159>/Constant1'
                                                                  * '<S160>/Constant1'
                                                                  * '<S161>/Constant1'
                                                                  * '<S162>/Constant1'
                                                                  */
#define CeAP_cm_EnRaebDistHoldThsd     60                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cm_FrntSideArc1Adj        10                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cm_FrntSideArc2Adj        5                         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cm_SideArc1Adj            5                         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cm_SideArc2Adj            0                         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_cnt_SensorCount           12U                       /* Referenced by: '<S40>/CalcRadialDistToSensor' */
#define CeAP_deg_MinSteerCurvature     10.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_CurbDbnc                20U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_SingleNegOne            -1.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_SingleOne               1.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_SingleTwo               2.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_SingleZero              2.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_k_Uint8One                1U                        /* Referenced by:
                                                                  * '<Root>/CVADAS_AutoPark_Main'
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FLAlertCount'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FRAlertCount'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/FrontAlertCount'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/RLAlertCount'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RRAlertCount'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  * '<S46>/RearAlertCount'
                                                                  * '<S99>/NeighbourCheck'
                                                                  */
#define CeAP_k_Uint8Zero               0U                        /* Referenced by:
                                                                  * '<Root>/CVADAS_AutoPark_Main'
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FLAlertCount'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FRAlertCount'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/FrontAlertCount'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/RLAlertCount'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RRAlertCount'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  * '<S46>/RearAlertCount'
                                                                  */
#define CeAP_ms_RaebThsdHold1          100U                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define CeAP_ms_RaebThsdHold2          200U                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define FB_PS_min_length               5.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define FB_PS_min_width                2.18F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_FrontOffset               0.2F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Offset of the front of the vehicle from the final pose */
#define KeAP_Kf_para                   0.7F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_Kf_perp                   0.7F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_Kf_perp_single_sweep      0.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_Ks                        1.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_PP_RES_DIST_TRAVEL        0.01F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_Phi_lim_perp              50.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_Phi_resolution_perp       3.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Resolution of path heading (Deg) */
#define KeAP_StrRateLim_para           100.0F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_StrRateLim_perp           100.0F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Steering rate limit during a perpendicular maneuver */
#define KeAP_V_max_para                1.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_V_max_perp                2.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Max velocity during perpendicular maneuver (m/s) */
#define KeAP_ang_threshold_regen       1.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_app_ctrl_min_dist_x_para  1.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_app_ctrl_min_dist_x_perp  1.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_aux_alpha                 2.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_aux_turn_para_regen       4.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_cm_RadialDistChgThd       25                        /* Referenced by:
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_cm_RadialDistMaxThd       80.0F                     /* Referenced by:
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_cm_RadialDistMinThd       20.0F                     /* Referenced by:
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_cm_RadialDistThd          50.0F                     /* Referenced by:
                                                                  * '<S40>/CalcRadialDistToSensor'
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_cm_SenBlkVehMovDisThd     40.0F                     /* Referenced by:
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_control_point_3_x_adjust_m -0.2F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Adjustment to x position of control point 3 (m) */
#define KeAP_control_point_3_y_step_m  -0.1F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Adjustment to y position of control point 3 (m) */
#define KeAP_curb_over_Y_dir_para      0.25F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_curvature_coeff_perp      0.6667F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_delta_s_clothoid_para     0.1F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_delta_s_clothoid_perp     0.08F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_delta_s_no_str_para       0.09F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_delta_s_no_str_perp       0.07F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_delta_s_nose_in_regen     0.1F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_delta_s_para              0.05F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_delta_s_perp              0.05F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_k_BlockageHoldCountThd    166U                      /* Referenced by:
                                                                  * '<S42>/Chart1'
                                                                  * '<S46>/FIL_Blk'
                                                                  * '<S46>/FIR_Blk'
                                                                  * '<S46>/FOL_Blk'
                                                                  * '<S46>/FOR_Blk'
                                                                  * '<S46>/FSL_Blk'
                                                                  * '<S46>/FSR_Blk'
                                                                  * '<S46>/RIL_Blk'
                                                                  * '<S46>/RIR_Blk'
                                                                  * '<S46>/ROL_Blk'
                                                                  * '<S46>/ROR_Blk'
                                                                  * '<S46>/RSL_Blk'
                                                                  * '<S46>/RSR_Blk'
                                                                  */
#define KeAP_k_RaebCruiseAgeThd        6U                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_lim_perp_PS4              0.1F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_maxCurvatureTypeOne       0.22845903F               /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeThree     0.215264142F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeTwo       0.228461951F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_max_num_sweeps            7U                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_n_para                    15U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Number of waypoints in each parallel planner segment */
#define KeAP_n_perp                    20U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Number of waypoints in each perpendicular planner segment. ALERT n_per_segment acts as an upper bound for this */
#define KeAP_num_clothoid_waypoints_para_mediumPS 2U             /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_num_clothoid_waypoints_para_smallPS 2U              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_num_points_no_str_para    16U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_num_points_no_str_perp    10U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_p3_pos_lim_perp           2.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_para_control_point_2_x_step_m -0.3F                 /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Step size for adjusting the X position of the second parallel control point (m) */
#define KeAP_para_final_curb_offset    -0.16F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Offset of the final position of the vehicle from the curb (m) */
#define KeAP_park_out_nose_in_angle    35.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Angle at gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_X 1.5F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* X offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_Y 4.5F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Y offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_X 3.0F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* X offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_big 2.0F          /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_small 2.0F        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_pct_CurbConfThd           78U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_pct_SenBlockPntConfThd    45U                       /* Referenced by: '<S40>/CalcRadialDistToSensor' */
#define KeAP_safety_lim_fb_f           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_fb_r           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_fb_s           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_nz_f           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_nz_r           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_nz_s           0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_para_f         0.1F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_para_r         0.1F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_para_s         0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_perp_f         0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_perp_r         0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_perp_s         0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_safety_lim_single_sweep_perp 0.05F                  /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_segment_3_length_perp_m   2.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Length of segment 3 (m) in a perpendicular back-in 3 sweep park */
#define KeAP_single_sweep_control_point_2_y_offset -1.9F         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The y offset of the second control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_x_offset 0.65F         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_y_offset -1.6F         /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_perp_width_lim 2.95F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The minimum width of a parking space that allows a single sweep park */
#define KeAP_single_sweep_start_min_lon_dist_m 6.8F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* The minimum longitudinal distance of the vehicle origin from the C1 corner of the parking spot to perform a single sweep (m) */
#define KeAP_str_wheel_ang_perp        45.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_mediumPS_D 22.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_mediumPS_R 10.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_mediumPS_R_tail 33.0F              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_smallPS_D2 25.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_smallPS_D4 15.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_smallPS_R3 25.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_smallPS_R5 15.0F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_para_smallPS_R_tail 33.0F               /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_str_whl_ang_regen         33.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_straight_line_perp_park_out 2.5F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_sweep_length_lim_regen    0.15F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_turn_radius_park_out_perp 5.25F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_turn_radius_park_out_perp_big 5.25F                 /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_turn_radius_single_sweep_perp 4.5F                  /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_vecLen_coeff_para         0.4437F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_vecLen_coeff_perp         0.4437F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_vecLen_coeff_perp_single_sweep_Phi 0.0323F          /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_vecLen_coeff_perp_single_sweep_XY 0.5547F           /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KeAP_yaw_control_point_3_perp_deg 25.0F                  /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Heading (deg) of the vehicle with respect to the parking spot at the third control point of a perpendiciular rear park in */
#define KePA_cm_RearCurbDetectLatThd   15                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KePA_cm_RearCurbDetectLongThd  10                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define KePA_cnt_RearCurbPntCntThd     3U                        /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define Ke_AP_deg_MaxWheelAngle        40.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define Kf_fb                          0.7F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define PP_PS_min_length               5.4F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define PP_PS_min_width                2.18F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define Rs                             100.0F                    /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define StrRateLim_fb                  47.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define V_max_fb                       2.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define Y_resolution_para              0.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define app_ctrl_min_dist_x_fb         1.5F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define aux_turn_para                  5.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define break_point_fb                 6.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define delta_s_fb                     0.05F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define delta_s_no_str_fb              0.07F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define length_regen_fb                5.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define minRadiusTypeTwo               4.37709665F               /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define minRadius_TypeOne              4.37715244F               /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define minRadiustypeThree             4.64545536F               /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define n_fb                           15U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define num_arc_waypoints_para_bigPS   27U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define num_clothoid_waypoints_para_bigPS 2U                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define num_points_no_str_fb           10U                       /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define p3_ang_lim_perp                0.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define str_whl_ang_para_bigPS_R       33.0F                     /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define straight_line_fb               1.0F                      /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
#define vecLen_coeff_fb                0.4437F                   /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* user code (top of header file) */
#include "SignalDef.h"

/* Block states (default storage) for system '<S46>/FIL_Blk' */
typedef struct {
  real_T cnt;                          /* '<S46>/FIL_Blk' */
  real32_T savedGlobalX;               /* '<S46>/FIL_Blk' */
  uint32_T temporalCounter_i1;         /* '<S46>/FIL_Blk' */
  uint8_T is_active_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck;/* '<S46>/FIL_Blk' */
  uint8_T is_c61_sVigAn9Vg2n8AREN0oQdiIH_FrntSensorBlck;/* '<S46>/FIL_Blk' */
  uint8_T step;                        /* '<S46>/FIL_Blk' */
  boolean_T output;                    /* '<S46>/FIL_Blk' */
} DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T;

/* Block states (default storage) for system '<S46>/FSL_Blk' */
typedef struct {
  real_T cnt;                          /* '<S46>/FSL_Blk' */
  real32_T savedGlobalX;               /* '<S46>/FSL_Blk' */
  uint32_T temporalCounter_i1;         /* '<S46>/FSL_Blk' */
  uint8_T is_active_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck;/* '<S46>/FSL_Blk' */
  uint8_T is_c61_sHFgKD6lQxwuHPbbl89gPmC_FrntSensorBlck;/* '<S46>/FSL_Blk' */
  uint8_T step;                        /* '<S46>/FSL_Blk' */
  boolean_T output;                    /* '<S46>/FSL_Blk' */
} DW_FSL_Blk_DT24_CVADAS_AP_CodGen_T;

/* Block states (default storage) for system '<S46>/RIL_Blk' */
typedef struct {
  real_T cnt;                          /* '<S46>/RIL_Blk' */
  real32_T savedGlobalX;               /* '<S46>/RIL_Blk' */
  uint32_T temporalCounter_i1;         /* '<S46>/RIL_Blk' */
  uint8_T is_active_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck;/* '<S46>/RIL_Blk' */
  uint8_T is_c87_sSkwEDKxyICMpRhDfXceOyG_RearSensorBlck;/* '<S46>/RIL_Blk' */
  uint8_T step;                        /* '<S46>/RIL_Blk' */
  boolean_T output;                    /* '<S46>/RIL_Blk' */
} DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T;

/* Block states (default storage) for system '<S46>/RSL_Blk' */
typedef struct {
  real_T cnt;                          /* '<S46>/RSL_Blk' */
  real32_T savedGlobalX;               /* '<S46>/RSL_Blk' */
  uint32_T temporalCounter_i1;         /* '<S46>/RSL_Blk' */
  uint8_T is_active_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck;/* '<S46>/RSL_Blk' */
  uint8_T is_c87_sv7x1vyKSJPQnNkmof9pKJD_RearSensorBlck;/* '<S46>/RSL_Blk' */
  uint8_T step;                        /* '<S46>/RSL_Blk' */
  boolean_T output;                    /* '<S46>/RSL_Blk' */
} DW_RSL_Blk_DT24_CVADAS_AP_CodGen_T;

/* Block signals for system '<S91>/NeighbourHoodCheck' */
typedef struct {
  int16_T Saturation;                  /* '<S99>/Saturation' */
  int16_T Saturation1;                 /* '<S99>/Saturation1' */
  int16_T Saturation2;                 /* '<S99>/Saturation2' */
  int16_T Saturation3;                 /* '<S99>/Saturation3' */
  boolean_T DiscardPoint;              /* '<S99>/NeighbourCheck' */
} B_NeighbourHoodCheck_DT24_CVADAS_AP_CodGen_T;

/* Block signals (default storage) */
typedef struct {
  TbAP_VCTrajOut_t BusCreator3;        /* '<S210>/Bus Creator3' */
  US_S_PointMapGroup_t USS_2DPointMap; /* '<S2>/USS_2DPointMap_data' */
  US_S_PointMapOutputBuff_t IbUSS_2DPointMap;/* '<S22>/Signal Conversion2' */
  IJobFPAOutput_t LwSpd_FPA;           /* '<S9>/Switch' */
  IJobFPAOutput_t FPA_Output;          /* '<S2>/LwSpd_FPA_data' */
  IJobFPAOutput_t BusAssignment;       /* '<S9>/Bus Assignment' */
  APA_Calibration_data_MCU2_1_t IbAP_VrntTunParam;/* '<S2>/VrntTunParam_data' */
  TbAP_InputVrntTunParam_t BusCreator1;/* '<S25>/Bus Creator1' */
  TbAP_InputVrntTunParam_t BusCreator; /* '<S25>/Bus Creator' */
  ME_VehInp_to_IpcSignals_t VehInpAdapter_opVehSignals;
                                    /* '<S2>/VehInpAdapter_opVehSignals_data' */
  TbVBIA_VehState_AP
    BusConversion_InsertedFor_CVADAS_AutoPark_Main_at_inport_0_BusCreator1;
  TbVC_DebugOut BusCreator1_i;         /* '<S207>/Bus Creator1' */
  TbTHASmVc_FeatureOutputs_t THA_Feature_Output;/* '<S2>/THA_Feature_Output_data' */
  TbAP_DebugOut AP_DebugOut;           /* '<S207>/Bus Creator' */
  ME_ProxiToMCU2_1_Def_t MbNVM_ProxyParam_e;/* '<S2>/TbNVM_ProxyCalibParam_data' */
  IParkingSlotData_t BusCreator_o;     /* '<S30>/Bus Creator' */
  IParkingSlotData_t VectorConcatenate[6];/* '<S30>/Vector Concatenate' */
  IParkingSlotData_t BusCreator_l;     /* '<S31>/Bus Creator' */
  FID_STRUCT_B FID_STRUCT_ASIL_B;      /* '<S2>/FID_STRUCT_B_data' */
  TbHMI_HMIInfoToAP BusCreator_ok;     /* '<S3>/Bus Creator' */
  ME_VehOut_TRSC_t TRSC_Feature_Output;/* '<S2>/TRSC_Feature_Output_data' */
  IKinematicData_t IbKM_KinematicData; /* '<S2>/VrntTunParam_data3' */
  HMIInfoToAP_t HMIInfoToAP;           /* '<S2>/HMIInfoToAP_data' */
  FID_STRUCT_QM FID_STRUCT_QM_e;       /* '<S2>/FID_STRUCT_QM_data' */
  US_S_USSErrorDiagData_t USSErrorDiagData;/* '<S2>/USS_ErrorDiag_Data' */
  TbFID_PA Switch;                     /* '<S3>/Switch' */
  TbFID_PA IbFID_PA;                   /* '<S8>/Bus Creator3' */
  TbFID_PA BusAssignment_b;            /* '<S18>/Bus Assignment' */
  TbAP_VCStateOut_t BusCreator4;       /* '<S210>/Bus Creator4' */
  TbAP_USSStateOut_t BusCreator4_d;    /* '<S208>/Bus Creator4' */
  TbAP_SMPAInternalOut_t BusCreator_p; /* '<S208>/Bus Creator' */
  TbAP_SMDAInternalOut_t BusCreator3_b;/* '<S208>/Bus Creator3' */
  real_T SFunction_o26;                /* '<S88>/CalculateMinDistances1' */
  real_T SFunction_o27;                /* '<S88>/CalculateMinDistances1' */
  real_T SFunction_o28;                /* '<S88>/CalculateMinDistances1' */
  real_T SFunction_o34;                /* '<S88>/CalculateMinDistances1' */
  real_T SFunction_o35;                /* '<S88>/CalculateMinDistances1' */
  real_T SFunction_o36;                /* '<S88>/CalculateMinDistances1' */
  real_T LookupTableDynamic;           /* '<S88>/Lookup Table Dynamic' */
  US_S_PointOutputBuff_t PointMapData[96];/* '<S88>/CalculateMinDistances1' */
  real_T d;
  uint64m_T Gain1;                     /* '<S12>/Gain1' */
  uint64m_T IeHMI_cnt_FressnessCounter;/* '<S11>/Data Type Conversion3' */
  real_T SFunction_o25;                /* '<S88>/CalculateMinDistances1' */
  US_S_PointOutputBuff_t CurrentPoint; /* '<S88>/CalculateMinDistances1' */
  US_S_PointOutputBuff_t BusCreator1_o;/* '<S98>/Bus Creator1' */
  US_S_BlockageBit_t USS_BlockageBit;  /* '<S2>/USS_BlockageBit_data' */
  TbUSS_DiagFlag IbUSS_DiagFlag;       /* '<S22>/Bus Creator' */
  TbNVM_ReadParam MbNVM_ReadParam;     /* '<S14>/Signal Conversion' */
  TbNVM_ReadParam MbNVM_ReadParam_j;   /* '<S2>/MbNVM_ReadParam_data' */
  TbFID_PPPA IbFID_PPPA;               /* '<S8>/Bus Creator5' */
  TbFID_PARB IbFID_PARB;               /* '<S8>/Bus Creator4' */
  TbAP_RearHighPointsPresent BusCreator1_ow;/* '<S88>/Bus Creator1' */
  TbAP_FrontHighPointsPresent BusCreator_e;/* '<S88>/Bus Creator' */
  Float2 Vertices;                     /* '<S39>/Bus Creator3' */
  Float2 Vertices_f;                   /* '<S39>/Bus Creator2' */
  Float2 Vertices_c;                   /* '<S39>/Bus Creator1' */
  Float2 Vertices_h;                   /* '<S39>/Bus Creator5' */
  Float2 VectorConcatenate_e[4];       /* '<S39>/Vector Concatenate' */
  DiagToParkAssist_t IbDiag_DiagToParkAssist;/* '<S2>/VrntTunParam_data2' */
  CalDataProvider_MCU_2_1_Def IbAP_CalDataProviderMCU21Def;/* '<S2>/VrntTunParam_data1' */
  real32_T IeVBII_kph_VehSpeedVSOSig;  /* '<S23>/Data Type Conversion26' */
  real32_T DataTypeConversion3;        /* '<S12>/Data Type Conversion3' */
  real32_T DataTypeConversion7;        /* '<S12>/Data Type Conversion7' */
  real32_T Product2;                   /* '<S13>/Product2' */
  real32_T CVADAS_AutoPark_Main_o72;   /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MeAP_deg_StrCmd;            /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MeAP_a_BrkCmd;              /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MeAP_a_ThrtlCmd;            /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_nm_StrwTrqReq;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_DecelMax;            /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_DecelMin;            /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_JerkDecelMax;        /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_JerkDecelMin;        /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_AcclMin;             /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_a_AcclMax;             /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_da_JerkAcclMax;        /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_da_JerkAcclMin;        /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_cm_TrgtDist;           /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MeAP_e_Park_state;          /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MaAP_m_PlannerWayPointsX[250];/* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MaAP_m_PlannerWayPointsY[250];/* '<Root>/CVADAS_AutoPark_Main' */
  real32_T IeAP_kph_TrgtVehSpd;        /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T X_MABx_b;                   /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Y_MABx_g;                   /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T heading_MABx_j;             /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Str_Trq_CMD;                /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T VC_RemainingDist_o;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T VC_PathDev_o;               /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T VC_Head_Dev_l;              /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimFSX_g;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimFSY_k;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimFBX_g;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimFBY_d;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimRSX_f;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimRSY_k;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimRBX_h;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Ma_AP_I_PSLimRBY_k;         /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T MeAP_s_FaultWaitTime;       /* '<Root>/CVADAS_AutoPark_Main' */
  real32_T Nominator;                  /* '<S88>/CalculateMinDistances1' */
  real32_T Denominator;                /* '<S88>/CalculateMinDistances1' */
  real32_T LastGoodDist;               /* '<S88>/CalculateMinDistances1' */
  real32_T VehTravelDist;              /* '<S88>/CalculateMinDistances1' */
  real32_T Subtract;                   /* '<S100>/Subtract' */
  real32_T UpdatedLastGoodDist;        /* '<S100>/Switch' */
  real32_T UpdatedLastGoodDist_c;      /* '<S100>/Signal Conversion' */
  real32_T UpdatedLastGoodDist_h;      /* '<S100>/Switch1' */
  real32_T UpdatedLastGoodDist_n;      /* '<S100>/Data Type Conversion1' */
  real32_T DivResult;                  /* '<S101>/Divide' */
  real32_T PrevRadialDist[12];         /* '<S46>/Unit Delay' */
  real32_T RadialDistSqrt[12];         /* '<S40>/CalcRadialDistToSensor' */
  real32_T IeVBII_deg_StrWhlSpd;       /* '<S23>/Data Type Conversion40' */
  real32_T Abs3;                       /* '<S100>/Abs3' */
  real32_T K_e_RAEB_VehicleWidth_f;    /* '<S25>/Data Type Conversion8' */
  real32_T KeAP_kph_USSActiveSpdThd;   /* '<S25>/Data Type Conversion7' */
  real32_T KeAP_kph_RearWarnMaxSpdThd_o;/* '<S25>/Data Type Conversion6' */
  real32_T KeAP_kph_PSDOnThd_m;        /* '<S25>/Data Type Conversion5' */
  real32_T KeAP_kph_PSDOffThd_o;       /* '<S25>/Data Type Conversion4' */
  real32_T KeAP_kph_ParkMnvThd_b;      /* '<S25>/Data Type Conversion3' */
  real32_T KeAP_kph_FrntWarnMaxSpdThd_h;/* '<S25>/Data Type Conversion2' */
  real32_T KeAP_kph_EnblHysThd_c;      /* '<S25>/Data Type Conversion1' */
  real32_T KeAP_degC_OperatingTempThd_c;/* '<S25>/Data Type Conversion' */
  real32_T Abs4;                       /* '<S100>/Abs4' */
  real32_T Switch_l;                   /* '<S101>/Switch' */
  real32_T Switch_k;                   /* '<S103>/Switch' */
  real32_T SideRegionLongThresh_In;    /* '<S102>/Product' */
  real32_T side_warn_weight;           /* '<S102>/Signal Conversion' */
  real32_T Abs4_e;                     /* '<S89>/Abs4' */
  real32_T f;
  real32_T f1;
  real32_T Abs4_tmp;
  real32_T f2;
  int32_T IeAP_e_TurnIndicReq;         /* '<Root>/CVADAS_AutoPark_Main' */
  int32_T RadialDist[12];              /* '<S40>/CalcRadialDistToSensor' */
  int32_T b_c;
  int32_T a;
  int32_T b_a;
  int32_T current_RadialDist;
  int32_T i;
  int32_T a_tmp;
  int32_T q0;
  int32_T i_m;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T i4;
  int32_T i5;
  int32_T i6;
  int32_T i7;
  int32_T i8;
  int32_T i9;
  int32_T i10;
  uint32_T IeVBII_nm_BrkTrqAct;        /* '<S23>/Data Type Conversion61' */
  uint32_T Gain;                       /* '<S12>/Gain' */
  uint32_T bu;
  uint32_T qY;
  TeVBII_e_WhlSpnSts IeVBII_e_LhfWhlSpnSts;/* '<S23>/Data Type Conversion29' */
  TeVBII_e_WhlSpnSts IeVBII_e_RhfWhlSpnSts;/* '<S23>/Data Type Conversion35' */
  TeVBII_e_VehEPBSts IeVBII_e_VehEPBSts;/* '<S23>/Data Type Conversion15' */
  TeVBII_e_TurnIndicSts IeVBII_e_TurnIndicSts;/* '<S23>/Data Type Conversion44' */
  TeVBII_e_TrlrPrsntSts IeVBII_e_TrlrPrsntSts;/* '<S23>/Data Type Conversion12' */
  TeVBII_e_TransSailingTst IeVBII_e_TransSailingTst;/* '<S23>/Data Type Conversion23' */
  TeVBII_e_TrailerConnectionSts IeVBII_e_TrailerConnectionSts;/* '<S23>/Data Type Conversion11' */
  TeVBII_e_TchScrSts IeVBII_e_TchScrSts;/* '<S23>/Data Type Conversion55' */
  TeVBII_e_TGWCamDispSts IeVBII_e_TGWCamDispSts;/* '<S23>/Data Type Conversion54' */
  TeVBII_e_TCaseRangeSts IeVBII_e_TCaseRangeSts;/* '<S23>/Data Type Conversion16' */
  TeVBII_e_ShiftLvrPosReq IeVBII_e_ShiftLvrPosReq;/* '<S23>/Data Type Conversion42' */
  TeVBII_e_ShiftLvrPos IeVBII_e_ShiftLvrPos;/* '<S23>/Data Type Conversion75' */
  TeVBII_e_SPMLatCtrlRespSts IeVBII_e_SPMLatCtrlRespSts;/* '<S23>/Data Type Conversion64' */
  TeVBII_e_ParkingIntrvntionSts IeVBII_e_ParkingIntrvntionSts;/* '<S23>/Data Type Conversion62' */
  TeVBII_e_ParkingGearShiftReq IeVBII_e_ParkingGearShiftReq;/* '<S23>/Data Type Conversion79' */
  TeVBII_e_PamChimeVol IeVBII_e_PamChimeVolFrnt;/* '<S23>/Data Type Conversion18' */
  TeVBII_e_PamChimeVol IeVBII_e_PamChimeVolRear;/* '<S23>/Data Type Conversion19' */
  TeVBII_e_PAMBrkReqRespStatus IeVBII_e_PAMBrkReqRespStatus;/* '<S23>/Data Type Conversion74' */
  TeVBII_e_LanguageSeln IeVBII_e_LanguageSeln;/* '<S23>/Data Type Conversion53' */
  TeVBII_e_GearState IeVBII_e_GearRptState;/* '<S23>/Data Type Conversion59' */
  TeVBII_e_ExtBrkReqDisabled IeVBII_e_ExtBrkReqDisabled;/* '<S23>/Data Type Conversion78' */
  TeVBII_e_EssEngState IeVBII_e_EssEngState;/* '<S23>/Data Type Conversion17' */
  TeVBII_e_EngineSts IeVBII_e_EngineSts;/* '<S23>/Data Type Conversion50' */
  TeVBII_e_DriverReqAxleTrqEnabled IeVBII_e_DriverReqAxleTrqEnabled;/* '<S23>/Data Type Conversion81' */
  TeVBII_e_CmdIgnSts IeVBII_e_CmdIgnSts;/* '<S23>/Data Type Conversion88' */
  TeVBII_e_BrkStat IeVBII_e_BrkStat;   /* '<S23>/Data Type Conversion14' */
  TeVBII_e_BrkPdlStat IeVBII_e_BrkPdlStat;/* '<S23>/Data Type Conversion21' */
  TeVBII_e_ACCSysSts IeVBII_e_ACCSysSts;/* '<S23>/Data Type Conversion60' */
  TeHMI_e_UsrParkOutSide Switch3;      /* '<S11>/Switch3' */
  TeAutoPark_e_ScanDir CVADAS_AutoPark_Main_o10;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAutoPark_e_ParkStyle Switch1;      /* '<S11>/Switch1' */
  TeAutoPark_e_ParkStyle DataTypeConversion;/* '<S6>/Data Type Conversion' */
  TeAutoPark_e_ParkStyle IeHMI_e_ParkStyle_i;/* '<S6>/Switch' */
  TeAutoPark_e_GearCmd CVADAS_AutoPark_Main_o14;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAutoPark_e_ChimeReq CVADAS_AutoPark_Main_o9;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_WhlBas KeAP_e_WhlBas;         /* '<S17>/Data Type Conversion101' */
  TeAP_e_UsrPPPAManeuverSel Switch5;   /* '<S11>/Switch5' */
  TeAP_e_USSSystemState MeAP_e_USSSystemState;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_USSSystemMode MeAP_e_USSSystemMode;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_USSSupplyPwrSt MeAP_e_USSSupplyPwrSt;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_SteerRatRackPinionTyp KeAP_e_SteerRatRackPinionTyp;/* '<S17>/Data Type Conversion93' */
  TeAP_e_SPMLatCtrlReqSts CVADAS_AutoPark_Main_o25;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_SPMActvStat IeAP_e_SPMActvStat;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_RearSnsrStatus IeAP_e_RearSnsrStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_RadioDispTyp KeAP_e_RadioDispTyp;/* '<S17>/Data Type Conversion104' */
  TeAP_e_ParkAssistStatus MeAP_e_ParkAssistStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_ParKMnvrActv IeAP_e_ParKMnvrActv;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMVolume MeAP_e_PAMVolume;   /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMVolSig MeAP_e_PAMVolSigSVM;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMTunSet KeAP_e_PAMTunSet;   /* '<S17>/Data Type Conversion96' */
  TeAP_e_PAMSystemFault IeAP_e_PAMSystemFault;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMPopUpReq MeAP_e_PAMPopUpReq;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMOffStatus2BT MeAP_e_PAMOffStatus2BT;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMLedCtrlStatus IeAP_e_SPMLedSts;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMLedCtrlStatus MeAP_e_FrntPAMLedCtrlStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMLedCtrlStatus MeAP_e_RearPAMLedCtrlStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMChimeTyp MeAP_e_PAMChimeTyp;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMChimeTyp MeAP_e_PAMChimeTypSVM;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMChimeRepnRate MeAP_e_PAMChimeRepnRate;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_PAMChimeRepnRate MeAP_e_PAMChimeRepnRateSVM;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_InterfaceBSM IeAP_e_InterfaceBSM;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_HybTyp KeAP_e_HybTyp;         /* '<S17>/Data Type Conversion99' */
  TeAP_e_HMIPopUp MeAP_e_HMIPopUp;     /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_HMIPopUp MeAP_e_HMIPopUp_o;   /* '<Root>/Unit Delay' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHF;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate CVADAS_AutoPark_Main_o56;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHF;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicCHR;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicLHR;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate MeAP_e_GraphicRHR;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateRHR;/* '<S209>/Data Type Conversion49' */
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateLHR;/* '<S209>/Data Type Conversion47' */
  TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateCHR;/* '<S209>/Data Type Conversion45' */
  TeAP_e_GearShiftReq IeAP_e_GearShiftReq;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_GbTyp KeAP_e_GbTyp;           /* '<S17>/Data Type Conversion95' */
  TeAP_e_FrntSnsrStatus IeAP_e_FrntSnsrStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_FiltdGearState MeAP_e_FiltdGearState;/* '<S182>/Multiport Switch' */
  TeAP_e_FiltdGearState UnitDelay;     /* '<S183>/Unit Delay' */
  TeAP_e_FiltdGearState MeAP_e_FiltdGearState_k;/* '<S183>/Switch' */
  TeAP_e_FiltdGearState Switch1_j;     /* '<S183>/Switch1' */
  TeAP_e_FiltdGearState Switch2;       /* '<S183>/Switch2' */
  TeAP_e_FiltdGearState Switch3_f;     /* '<S183>/Switch3' */
  TeAP_e_FiltdGearState Switch4;       /* '<S183>/Switch4' */
  TeAP_e_FiltdGearState Switch5_m;     /* '<S183>/Switch5' */
  TeAP_e_FiltdGearState Switch6;       /* '<S183>/Switch6' */
  TeAP_e_FiltdGearState MeAP_e_FiltdGearRptState;/* '<S175>/Multiport Switch' */
  TeAP_e_DrvTypVrnt KeAP_e_DrvTypVrnt; /* '<S17>/Data Type Conversion94' */
  TeAP_e_DispView2 IeAP_e_DispView2;   /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_CtryCod KeAP_e_CtryCod;       /* '<S17>/Data Type Conversion98' */
  TeAP_e_Alert MeAP_e_AlertCHF;        /* '<Root>/Unit Delay1' */
  TeAP_e_Alert MeAP_e_AlertCHR;        /* '<Root>/Unit Delay2' */
  TeAP_e_Alert MeAP_e_AlertLHF;        /* '<Root>/Unit Delay3' */
  TeAP_e_Alert MeAP_e_AlertLHR;        /* '<Root>/Unit Delay4' */
  TeAP_e_Alert MeAP_e_AlertRHF;        /* '<Root>/Unit Delay5' */
  TeAP_e_Alert MeAP_e_AlertRHR;        /* '<Root>/Unit Delay6' */
  TeAP_e_Alert MeAP_e_AlertCHF_b;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert MeAP_e_AlertLHF_a;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert MeAP_e_AlertRHF_g;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert MeAP_e_AlertCHR_g;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert MeAP_e_AlertLHR_n;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert MeAP_e_AlertRHR_g;      /* '<Root>/CVADAS_AutoPark_Main' */
  TeAP_e_Alert IeAP_e_DispArcRHR;      /* '<S209>/Data Type Conversion41' */
  TeAP_e_Alert IeAP_e_DispArcLHR;      /* '<S209>/Data Type Conversion39' */
  TeAP_e_Alert IeAP_e_DispArcCHR;      /* '<S209>/Data Type Conversion37' */
  SlotSide_t IeHMI_e_SelectedMnvSlotSide;/* '<S11>/Data Type Conversion1' */
  ParkingSlotType_t IeHMI_e_SelectedMnvSlotType;/* '<S11>/Data Type Conversion' */
  ParkingSlotID_t IeHMI_e_SelectedSlotId;/* '<S11>/Data Type Conversion2' */
  uint16_T UnitDelay2;                 /* '<S203>/Unit Delay2' */
  uint16_T UnitDelay2_c;               /* '<S204>/Unit Delay2' */
  uint16_T IeUSS_e_BlockageFlag;       /* '<S22>/Data Type Conversion3' */
  uint16_T UnitDelay2_n;               /* '<S163>/Unit Delay2' */
  uint16_T Switch3_c;                  /* '<S163>/Switch3' */
  uint16_T UnitDelay2_h;               /* '<S167>/Unit Delay2' */
  uint16_T Switch_p;                   /* '<S167>/Switch' */
  uint16_T UnitDelay2_m;               /* '<S171>/Unit Delay2' */
  uint16_T Switch3_n;                  /* '<S171>/Switch3' */
  uint16_T MeAP_cnt_StateDebugVar_f;   /* '<Root>/CVADAS_AutoPark_Main' */
  uint16_T MeAP_cnt_TransDebugVar_f;   /* '<Root>/CVADAS_AutoPark_Main' */
  uint16_T Switch4_j;                  /* '<S204>/Switch4' */
  uint16_T Switch4_i;                  /* '<S203>/Switch4' */
  uint16_T Switch1_o;                  /* '<S204>/Switch1' */
  uint16_T Subtract_n;                 /* '<S204>/Subtract' */
  uint16_T Switch1_b;                  /* '<S203>/Switch1' */
  uint16_T Subtract_f;                 /* '<S203>/Subtract' */
  uint16_T Switch1_l;                  /* '<S171>/Switch1' */
  uint16_T Subtract_l;                 /* '<S171>/Subtract' */
  uint16_T Add;                        /* '<S167>/Add' */
  uint16_T Switch1_j1;                 /* '<S167>/Switch1' */
  uint16_T Switch1_d;                  /* '<S163>/Switch1' */
  uint16_T Subtract_nl;                /* '<S163>/Subtract' */
  uint16_T count;                      /* '<S203>/Switch3' */
  uint16_T count_d;                    /* '<S204>/Switch3' */
  uint16_T KeAP_cnt_FrntChimeDisTimeThd_j;/* '<S25>/Data Type Conversion29' */
  uint16_T KeAP_cnt_ChimeVolChgAlert_d;/* '<S25>/Data Type Conversion28' */
  uint16_T KeAP_s_EPSInterfaceCntTimeout_f;/* '<S25>/Switch3' */
  uint16_T KeAP_s_CamHandshakeDur_j;   /* '<S25>/Switch2' */
  uint16_T IeAP_cm_RearDisttoNearObst; /* '<S209>/Data Type Conversion15' */
  uint16_T KeAP_cnt_LEDBlinkTimeThd_h; /* '<S25>/Data Type Conversion31' */
  uint16_T KeAP_cnt_HalfSecChimeAlert_h;/* '<S25>/Data Type Conversion30' */
  int16_T DataTypeConversion2;         /* '<S12>/Data Type Conversion2' */
  int16_T DataTypeConversion4;         /* '<S12>/Data Type Conversion4' */
  int16_T Add11;                       /* '<S95>/Add11' */
  int16_T Add12;                       /* '<S95>/Add12' */
  int16_T Add13;                       /* '<S95>/Add13' */
  int16_T Add14;                       /* '<S95>/Add14' */
  int16_T Saturation1;                 /* '<S95>/Saturation1' */
  int16_T Add8;                        /* '<S95>/Add8' */
  int16_T Gain_h;                      /* '<S95>/Gain' */
  int16_T Gain1_c;                     /* '<S95>/Gain1' */
  int16_T Gain2;                       /* '<S95>/Gain2' */
  int16_T Saturation6;                 /* '<S95>/Saturation6' */
  int16_T Gain3;                       /* '<S95>/Gain3' */
  int16_T Add9;                        /* '<S95>/Add9' */
  int16_T Saturation8;                 /* '<S95>/Saturation8' */
  int16_T Gain4;                       /* '<S95>/Gain4' */
  int16_T Gain5;                       /* '<S95>/Gain5' */
  int16_T Gain6;                       /* '<S95>/Gain6' */
  int16_T Saturation13;                /* '<S95>/Saturation13' */
  int16_T Gain7;                       /* '<S95>/Gain7' */
  int16_T Add10;                       /* '<S95>/Add10' */
  int16_T FSL_x;                       /* '<S41>/Saturation' */
  int16_T FOL_x;                       /* '<S41>/Saturation1' */
  int16_T FIL_x;                       /* '<S41>/Saturation2' */
  int16_T FIR_x;                       /* '<S41>/Saturation3' */
  int16_T FOR_x;                       /* '<S41>/Saturation4' */
  int16_T FSR_x;                       /* '<S41>/Saturation5' */
  int16_T RSR_x;                       /* '<S41>/Saturation6' */
  int16_T ROR_x;                       /* '<S41>/Saturation7' */
  int16_T RIR_x;                       /* '<S41>/Saturation8' */
  int16_T RIL_x;                       /* '<S41>/Saturation9' */
  int16_T ROL_x;                       /* '<S41>/Saturation10' */
  int16_T RSL_x;                       /* '<S41>/Saturation11' */
  int16_T FSL_y;                       /* '<S41>/Saturation12' */
  int16_T FOL_y;                       /* '<S41>/Saturation18' */
  int16_T FIL_y;                       /* '<S41>/Saturation19' */
  int16_T FIR_y;                       /* '<S41>/Saturation20' */
  int16_T FOR_y;                       /* '<S41>/Saturation21' */
  int16_T FSR_y;                       /* '<S41>/Saturation22' */
  int16_T RSR_y;                       /* '<S41>/Saturation23' */
  int16_T ROR_y;                       /* '<S41>/Saturation24' */
  int16_T RIR_y;                       /* '<S41>/Saturation25' */
  int16_T RIL_y;                       /* '<S41>/Saturation14' */
  int16_T ROL_y;                       /* '<S41>/Saturation15' */
  int16_T RSL_y;                       /* '<S41>/Saturation13' */
  int16_T Abs;                         /* '<S92>/Abs' */
  int16_T UnitDelay_o;                 /* '<S108>/Unit Delay' */
  int16_T Switch_m;                    /* '<S108>/Switch' */
  int16_T Switch_a;                    /* '<S155>/Switch' */
  int16_T Abs1;                        /* '<S92>/Abs1' */
  int16_T UnitDelay_og;                /* '<S110>/Unit Delay' */
  int16_T Switch_i;                    /* '<S110>/Switch' */
  int16_T Switch_c;                    /* '<S156>/Switch' */
  int16_T Abs2;                        /* '<S92>/Abs2' */
  int16_T UnitDelay_a;                 /* '<S111>/Unit Delay' */
  int16_T Switch_e;                    /* '<S111>/Switch' */
  int16_T Switch_l3;                   /* '<S157>/Switch' */
  int16_T Abs_f;                       /* '<S93>/Abs' */
  int16_T Divide;                      /* '<S130>/Divide' */
  int16_T Switch1_os;                  /* '<S140>/Switch1' */
  int16_T Switch_n;                    /* '<S130>/Switch' */
  int16_T Switch_j;                    /* '<S159>/Switch' */
  int16_T Abs1_n;                      /* '<S93>/Abs1' */
  int16_T Divide_d;                    /* '<S131>/Divide' */
  int16_T Switch1_c;                   /* '<S143>/Switch1' */
  int16_T Switch_nz;                   /* '<S131>/Switch' */
  int16_T Switch_ev;                   /* '<S160>/Switch' */
  int16_T Abs2_e;                      /* '<S93>/Abs2' */
  int16_T Divide_k;                    /* '<S132>/Divide' */
  int16_T Switch1_k;                   /* '<S146>/Switch1' */
  int16_T Switch_h;                    /* '<S132>/Switch' */
  int16_T Switch_b;                    /* '<S161>/Switch' */
  int16_T IeVBII_deg_StrWhlSpd_k;      /* '<S12>/Data Type Conversion8' */
  int16_T Divide_p;                    /* '<S109>/Divide' */
  int16_T Switch1_n;                   /* '<S118>/Switch1' */
  int16_T Switch_o;                    /* '<S109>/Switch' */
  int16_T Switch_or;                   /* '<S158>/Switch' */
  int16_T Divide_kq;                   /* '<S139>/Divide' */
  int16_T Switch1_a;                   /* '<S152>/Switch1' */
  int16_T Switch_f;                    /* '<S139>/Switch' */
  int16_T Switch_ik;                   /* '<S162>/Switch' */
  int16_T Add1;                        /* '<S152>/Add1' */
  int16_T MeAP_cm_RearRightMinXDistOut;/* '<S135>/DistDbnc' */
  int16_T MeAP_cm_RearLeftMinXDistOut; /* '<S134>/DistDbnc' */
  int16_T MeAP_cm_RearCenterMinXDistOut;/* '<S133>/DistDbnc' */
  int16_T Add1_f;                      /* '<S146>/Add1' */
  int16_T Add1_a;                      /* '<S143>/Add1' */
  int16_T Add1_c;                      /* '<S140>/Add1' */
  int16_T Subtract1;                   /* '<S93>/Subtract1' */
  int16_T Subtract3;                   /* '<S93>/Subtract3' */
  int16_T Subtract5;                   /* '<S93>/Subtract5' */
  int16_T MeAP_cm_FrntRightMinXDistOut;/* '<S114>/DistDbnc' */
  int16_T MeAP_cm_FrntLeftMinXDistOut; /* '<S113>/DistDbnc' */
  int16_T MeAP_cm_FrntCenterMinXDistOut;/* '<S112>/DistDbnc' */
  int16_T Divide_a;                    /* '<S111>/Divide' */
  int16_T Switch1_jm;                  /* '<S124>/Switch1' */
  int16_T Add1_e;                      /* '<S124>/Add1' */
  int16_T Divide_f;                    /* '<S110>/Divide' */
  int16_T Switch1_l5;                  /* '<S121>/Switch1' */
  int16_T Add1_k;                      /* '<S121>/Add1' */
  int16_T Add1_b;                      /* '<S118>/Add1' */
  int16_T Divide_l;                    /* '<S108>/Divide' */
  int16_T Switch1_n2;                  /* '<S115>/Switch1' */
  int16_T Add1_h;                      /* '<S115>/Add1' */
  int16_T TmpSignalConversionAtSFunctionInport1[16];/* '<S88>/CalculateMinDistances1' */
  int16_T TmpSignalConversionAtSFunctionInport2[16];/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_FrntCenterMinXRawDist;/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_FrntLeftMinXRawDist; /* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_FrntRightMinXRawDist;/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_RearCenterMinXRawDist;/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_RearLeftMinXRawDist; /* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_RearRightMinXRawDist;/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_b_SideRegionLongThresh; /* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_b_CenterRegionLongThresh;/* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_WallFrntCenterDist;  /* '<S88>/CalculateMinDistances1' */
  int16_T MeAP_cm_WallRearCenterDist;  /* '<S88>/CalculateMinDistances1' */
  int16_T ObjY;                        /* '<S88>/CalculateMinDistances1' */
  int16_T CenterLatThresh;             /* '<S88>/CalculateMinDistances1' */
  int16_T HalfVehWidth;                /* '<S88>/CalculateMinDistances1' */
  int16_T SideMaxLongDist;             /* '<S88>/CalculateMinDistances1' */
  int16_T RawDist;                     /* '<S88>/CalculateMinDistances1' */
  int16_T ZoneDist;                    /* '<S88>/CalculateMinDistances1' */
  int16_T UpdatedDist;                 /* '<S100>/Switch' */
  int16_T UpdatedDist_n;               /* '<S100>/Data Type Conversion2' */
  int16_T UpdatedDist_b;               /* '<S100>/Switch1' */
  int16_T Abs_h;                       /* '<S97>/Abs' */
  int16_T OutportBufferForSideRegionLongThresh;/* '<S97>/CalcSideRegLongThresh' */
  int16_T SideRegionLongThresh;        /* '<S102>/Data Type Conversion' */
  int16_T Add_f;                       /* '<S111>/Add' */
  int16_T Add_m;                       /* '<S110>/Add' */
  int16_T Add_c;                       /* '<S108>/Add' */
  int16_T x;                           /* '<S98>/Data Type Conversion' */
  int16_T y;                           /* '<S98>/Data Type Conversion2' */
  int16_T Abs1_c;                      /* '<S100>/Abs1' */
  int16_T TmpSignalConversionAtSFunctionInport2_j[12];/* '<S40>/CalcRadialDistToSensor' */
  int16_T TmpSignalConversionAtSFunctionInport3[12];/* '<S40>/CalcRadialDistToSensor' */
  int16_T KeAP_cm_VehContour_FSL_x_b;  /* '<S25>/Data Type Conversion100' */
  int16_T Abs2_g;                      /* '<S100>/Abs2' */
  int16_T y_max;                       /* '<S102>/Subtract1' */
  int16_T Add_o;                       /* '<S139>/Add' */
  int16_T Abs3_f;                      /* '<S93>/Abs3' */
  int16_T DataTypeConversion_g;        /* '<S139>/Data Type Conversion' */
  int16_T MaxDist;
  int16_T u0;
  int16_T u0_c;
  int16_T GhstObjMinDistThd;
  int16_T i11;
  int16_T z;
  int16_T z_k;
  uint16_T d_y;
  uint16_T q;
  uint16_T d_y_c;
  uint16_T q_b;
  int8_T i12;
  uint8_T DataTypeConversion_h;        /* '<S182>/Data Type Conversion' */
  uint8_T DataTypeConversion_i;        /* '<S175>/Data Type Conversion' */
  uint8_T DataTypeConversion314;       /* '<S12>/Data Type Conversion314' */
  uint8_T DataTypeConversion_hr;       /* '<S88>/Data Type Conversion' */
  uint8_T IeAP_e_HMIDispReq;           /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T MeAP_e_USSFiringMode;        /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T PM_CurrentSweep_f;           /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T IeAP_e_MnvActvStat;          /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T IeAP_e_AbortCon;             /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T IeAP_e_SemiParkSysSts;       /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T IeAP_e_DIDHMICode;           /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T IeAP_cnt_CurrentVehSweep;    /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T MeAP_b_HighPointsPresentFront;/* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_HighPointsPresentFL;  /* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_HighPointsPresentFR;  /* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_HighPointsPresentRear;/* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_HighPointsPresentRL;  /* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_HighPointsPresentRR;  /* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_IsWall;               /* '<S88>/CalculateMinDistances1' */
  uint8_T EgoPtHeight;                 /* '<S88>/CalculateMinDistances1' */
  uint8_T MeAP_b_VehStandstill;        /* '<S44>/Data Type Conversion' */
  uint8_T MeAP_b_FrntArcTrackFlag;     /* '<S46>/Data Type Conversion' */
  uint8_T MeAP_b_RearArcTrackFlag;     /* '<S46>/Data Type Conversion1' */
  uint8_T RearSensorBlockage;          /* '<S42>/Data Type Conversion1' */
  uint8_T RearAlertCnt;                /* '<S46>/RearAlertCount' */
  uint8_T SensorBlockStatus;           /* '<S46>/RSR_Blk' */
  uint8_T SensorBlockStatus_l;         /* '<S46>/RSL_Blk' */
  uint8_T RearAlertCnt_p;              /* '<S46>/RRAlertCount' */
  uint8_T SensorBlockStatus_m;         /* '<S46>/ROR_Blk' */
  uint8_T SensorBlockStatus_a;         /* '<S46>/ROL_Blk' */
  uint8_T RearAlertCnt_a;              /* '<S46>/RLAlertCount' */
  uint8_T SensorBlockStatus_e;         /* '<S46>/RIR_Blk' */
  uint8_T SensorBlockStatus_n;         /* '<S46>/RIL_Blk' */
  uint8_T FrntAlertCnt;                /* '<S46>/FrontAlertCount' */
  uint8_T SensorBlockStatus_h;         /* '<S46>/FSR_Blk' */
  uint8_T SensorBlockStatus_d;         /* '<S46>/FSL_Blk' */
  uint8_T FrntAlertCnt_p;              /* '<S46>/FRAlertCount' */
  uint8_T SensorBlockStatus_mm;        /* '<S46>/FOR_Blk' */
  uint8_T SensorBlockStatus_f;         /* '<S46>/FOL_Blk' */
  uint8_T FrntAlertCnt_d;              /* '<S46>/FLAlertCount' */
  uint8_T SensorBlockStatus_ht;        /* '<S46>/FIR_Blk' */
  uint8_T SensorBlockStatus_g;         /* '<S46>/FIL_Blk' */
  uint8_T ReverseBlockStateDebug;      /* '<S42>/Chart1' */
  uint8_T cnt;                         /* '<S42>/Chart1' */
  uint8_T IeVBII_cnt_LhrPulseCtr;      /* '<S23>/Data Type Conversion31' */
  uint8_T BitwiseOperator1;            /* '<S26>/Bitwise Operator1' */
  uint8_T BitwiseOperator;             /* '<S26>/Bitwise Operator' */
  uint8_T height;                      /* '<S98>/Data Type Conversion1' */
  uint8_T Cruising_Age;                /* '<S98>/Data Type Conversion3' */
  uint8_T confidence;                  /* '<S98>/Data Type Conversion5' */
  uint8_T age;                         /* '<S98>/Data Type Conversion4' */
  uint8_T Reverse_Gr_num_a;            /* '<S25>/Data Type Conversion66' */
  uint8_T FrontBlockageInReverseGear;  /* '<S42>/Data Type Conversion2' */
  uint8_T IeVBII_cnt_LhfPulseCtr;      /* '<S23>/Data Type Conversion28' */
  uint8_T DataTypeConversion27;        /* '<S209>/Data Type Conversion27' */
  int8_T MeAP_e_PP_state;              /* '<Root>/CVADAS_AutoPark_Main' */
  uint8_T point_index;
  uint8_T sensor_index;
  uint8_T ContourPtIdx;
  uint8_T NumberOfIterations;
  uint8_T GhstObjSideHighPntCruiseAgeThd;
  uint8_T GhstObjSideHighPntConfThd;
  uint8_T DensGhstObjPntCruiseAgeThd;
  uint8_T DensGhstObjHighPntConfThd;
  uint8_T DensGhstObjLowPntConfThd;
  uint8_T GhstObjSideLowPntCruiseAgeThd;
  uint8_T GhstObjSideLowPntConfThd;
  uint8_T InnerIdx;
  uint8_T fidx;
  uint8_T PtSeparationCount;
  uint8_T WallCount;
  uint8_T InnerIdx_p;
  uint8_T RearPtSeparationCount;
  uint8_T fidx_c;
  boolean_T RelationalOperator6;       /* '<S183>/Relational Operator6' */
  boolean_T Switch2_b;                 /* '<S203>/Switch2' */
  boolean_T overflow;                  /* '<S203>/Relational Operator1' */
  boolean_T RelationalOperator8;       /* '<S183>/Relational Operator8' */
  boolean_T Switch2_e;                 /* '<S204>/Switch2' */
  boolean_T overflow_h;                /* '<S204>/Relational Operator1' */
  boolean_T DataTypeConversion1;       /* '<S12>/Data Type Conversion1' */
  boolean_T RelationalOperator4;       /* '<S89>/Relational Operator4' */
  boolean_T LogicalOperator4;          /* '<S89>/Logical Operator4' */
  boolean_T MeAP_b_StandstillTimerRunning;/* '<S89>/Signal Conversion' */
  boolean_T MeAP_b_VehStandstill_m;    /* '<S90>/Logical Operator' */
  boolean_T SignalConversion;          /* '<S7>/Signal Conversion' */
  boolean_T MeAP_b_VehStandstill_g;    /* '<S169>/Logical Operator' */
  boolean_T LogicalOperator;           /* '<S168>/Logical Operator' */
  boolean_T IsTimerElapsed;            /* '<S171>/Relational Operator1' */
  boolean_T MeAP_b_ObjPrestFC;         /* '<S16>/Relational Operator' */
  boolean_T MeAP_b_ObjPrestRC;         /* '<S16>/Relational Operator1' */
  boolean_T MbDiag_PlantModeOn;        /* '<S7>/Data Type Conversion' */
  boolean_T MeAP_b_FPAStatus;          /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_RPAStatus;          /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_DisableDiag;        /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_APEnblSwtStuckStatus;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_SystemFail_l;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ExternalFail_g;     /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_PARBDiable_h;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_RPADisable_n;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_FPADisable_b;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_ImgDefeatReqSts;    /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_SPMScrnReq;         /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_SPMFailSts;         /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_SPMFaultSts;        /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_VehMnvrDirSPM;      /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_StandstillReq;      /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_VCOpPaused;         /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvLHF;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvRHF;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvLHR;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvRHR;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_CalculateRearObjectDist;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_PAMStopCtrlStatus;  /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_StandstillReq_a;    /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ManeuverAbort;      /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ManeuverSuccess;    /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_PosMet_f;           /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_SteerActionReq_g;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvReqLHFSVM; /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvReqLHRSVM; /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvReqRHFSVM; /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ChimeActvReqRHRSVM; /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_USSReinitAllowed;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ScanSts;            /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_VCOpPaused_k;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_BSMInterfaceTimeout;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_EPSInterfaceTimeout;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_GearShiftWaitTimeout;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_CamHandshakeTimeout;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ObjInPathTimeout_d; /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_PausedPressBtnTimeout_f;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_SeekSpdExceedTimeout;/* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_APInitSts;          /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_DriverOverride_k;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_StandStill;         /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_BSMHandshakeActv;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_VehCndSts_l;        /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_FeatureEnbl;        /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T PM_RegenPath_a;            /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MbDiag_SensorTestMode;     /* '<S7>/Data Type Conversion1' */
  boolean_T CVADAS_AutoPark_Main_o3;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o4;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o6;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o7;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o8;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o11;  /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o23;  /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T CVADAS_AutoPark_Main_o30;  /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_AutoParkOverride;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_SensorFltSts;       /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T MeAP_b_ParkSlotDetctSts;   /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T IeAP_b_MnvPosOk;           /* '<Root>/CVADAS_AutoPark_Main' */
  boolean_T HoldTracking;              /* '<S88>/CalculateMinDistances1' */
  boolean_T OutportBufferForDiscardPoint;/* '<S99>/NeighbourCheck' */
  boolean_T SaveObjInfo;               /* '<S100>/Logical Operator1' */
  boolean_T LogicalOperator_g;         /* '<S97>/Logical Operator' */
  boolean_T LogicalOperator_h;         /* '<S46>/Logical Operator' */
  boolean_T LogicalOperator1;          /* '<S46>/Logical Operator1' */
  boolean_T LogicalOperator3;          /* '<S46>/Logical Operator3' */
  boolean_T LogicalOperator2;          /* '<S46>/Logical Operator2' */
  boolean_T FrontSensorBlockage;       /* '<S42>/Logical Operator2' */
  boolean_T FrontSensorBlockSts;       /* '<S42>/Chart1' */
  boolean_T IeVBII_b_FrntParkAsstReq;  /* '<S23>/Data Type Conversion7' */
  boolean_T IeVBII_b_ParkAsstReq;      /* '<S23>/Data Type Conversion8' */
  boolean_T IeVBII_b_RemoteStartActvSts;/* '<S23>/Data Type Conversion9' */
  boolean_T IeVBII_b_RearBrkAsst;      /* '<S23>/Data Type Conversion20' */
  boolean_T IeVBII_b_DoorRL;           /* '<S23>/Data Type Conversion46' */
  boolean_T IeVBII_b_DoorP;            /* '<S23>/Data Type Conversion47' */
  boolean_T IeVBII_b_TrnkStatus;       /* '<S23>/Data Type Conversion48' */
  boolean_T IeVBII_b_ActvParkMode;     /* '<S23>/Data Type Conversion52' */
  boolean_T RelationalOperator;        /* '<S204>/Relational Operator' */
  boolean_T RelationalOperator_d;      /* '<S203>/Relational Operator' */
  boolean_T RelationalOperator2;       /* '<S183>/Relational Operator2' */
  boolean_T RelationalOperator3;       /* '<S183>/Relational Operator3' */
  boolean_T RelationalOperator5;       /* '<S183>/Relational Operator5' */
  boolean_T RelationalOperator4_l;     /* '<S183>/Relational Operator4' */
  boolean_T RelationalOperator7;       /* '<S183>/Relational Operator7' */
  boolean_T RelationalOperator9;       /* '<S183>/Relational Operator9' */
  boolean_T RelationalOperator3_i;     /* '<S167>/Relational Operator3' */
  boolean_T LogicalOperator1_i;        /* '<S163>/Logical Operator1' */
  boolean_T RelationalOperator_p;      /* '<S124>/Relational Operator' */
  boolean_T RelationalOperator_l;      /* '<S121>/Relational Operator' */
  boolean_T RelationalOperator_c;      /* '<S115>/Relational Operator' */
  boolean_T LastObjDetectedInZone2;    /* '<S100>/Relational Operator' */
  boolean_T RelationalOperator_a;      /* '<S101>/Relational Operator' */
  boolean_T RelationalOperator_f;      /* '<S97>/Relational Operator' */
  boolean_T RelationalOperator1;       /* '<S97>/Relational Operator1' */
  boolean_T RelationalOperator_fz;     /* '<S103>/Relational Operator' */
  boolean_T RelationalOperator6_n;     /* '<S11>/Relational Operator6' */
  boolean_T RelationalOperator9_i;     /* '<S11>/Relational Operator9' */
  boolean_T RelationalOperator1_f;     /* '<S11>/Relational Operator1' */
  boolean_T IeVBII_b_DriverDoorSts;    /* '<S23>/Data Type Conversion45' */
  boolean_T KeAP_b_SVSPresent;         /* '<S17>/Data Type Conversion128' */
  boolean_T KeAP_b_TrlrRvsSteerPres;   /* '<S17>/Data Type Conversion111' */
  boolean_T KeAP_b_TrlrHitchAsstPres;  /* '<S17>/Data Type Conversion127' */
  boolean_T KeAP_b_FullAutoPrkgSys;    /* '<S17>/Data Type Conversion110' */
  boolean_T KeAP_b_PullOutCtrlPres;    /* '<S17>/Data Type Conversion109' */
  boolean_T ElapseTimer;               /* '<S171>/Logical Operator3' */
  boolean_T ElapseTimer_l;             /* '<S163>/Logical Operator3' */
  boolean_T USSObjDetectedInZone2;     /* '<S100>/Relational Operator3' */
  boolean_T LogicalOperator4_d;        /* '<S100>/Logical Operator4' */
  boolean_T LogicalOperator1_a;        /* '<S11>/Logical Operator1' */
  boolean_T KeCMbB_b_EnblOncObjDbnc_d; /* '<S25>/Data Type Conversion73' */
  boolean_T KeAP_b_SteerOnlyAutoPark_i;/* '<S25>/Data Type Conversion72' */
  boolean_T KeAP_b_RPAwithSurroundView_b;/* '<S25>/Data Type Conversion71' */
  boolean_T LogicalOperator_a;         /* '<S183>/Logical Operator' */
  boolean_T LogicalOperator1_c;        /* '<S183>/Logical Operator1' */
  boolean_T TrackObj;                  /* '<S100>/Logical Operator' */
  boolean_T DataTypeConversion4_j;     /* '<S8>/Data Type Conversion4' */
  boolean_T DataTypeConversion3_p;     /* '<S8>/Data Type Conversion3' */
  boolean_T IeVBII_b_AutoParkEnblSwt;  /* '<S23>/Data Type Conversion43' */
  boolean_T IeVBII_b_ShifterAutoconnectSts;/* '<S23>/Data Type Conversion41' */
  boolean_T RelationalOperator_e;      /* '<S152>/Relational Operator' */
  boolean_T IeAP_b_PAMRearCtrlSts;     /* '<S209>/Data Type Conversion14' */
  boolean_T IeAP_b_PAMRearBrkReq;      /* '<S209>/Data Type Conversion13' */
  boolean_T IeAP_b_PAMRearBrkReq_tmp;
  boolean_T b_sf_internal_predicateOutput;
  boolean_T sf_internal_predicateOutput;
  boolean_T sf_internal_predicateOutput_f;
  boolean_T aVarTruthTableCondition_1;
  boolean_T aVarTruthTableCondition_2;
  boolean_T aVarTruthTableCondition_6;
  boolean_T b;
  boolean_T c;
  boolean_T d_g;
  boolean_T e;
  boolean_T f_g;
  boolean_T g;
  boolean_T h;
  boolean_T i_me;
  boolean_T j;
  B_NeighbourHoodCheck_DT24_CVADAS_AP_CodGen_T NeighbourHoodCheck;/* '<S91>/NeighbourHoodCheck' */
} B_DT24_CVADAS_AP_CodGen_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  US_S_PointOutputBuff_t Current_Pt;   /* '<S88>/CalculateMinDistances1' */
  US_S_PointOutputBuff_t FrontCenter_Pt;/* '<S88>/CalculateMinDistances1' */
  US_S_PointOutputBuff_t RearCenter_Pt;/* '<S88>/CalculateMinDistances1' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S209>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S209>/Scope' */

  real32_T UnitDelay_DSTATE[12];       /* '<S46>/Unit Delay' */
  TeAP_e_FiltdGearState UnitDelay_DSTATE_m;/* '<S183>/Unit Delay' */
  TeAP_e_HMIPopUp UnitDelay_DSTATE_j;  /* '<Root>/Unit Delay' */
  TeAP_e_Alert UnitDelay1_DSTATE;      /* '<Root>/Unit Delay1' */
  TeAP_e_Alert UnitDelay2_DSTATE;      /* '<Root>/Unit Delay2' */
  TeAP_e_Alert UnitDelay3_DSTATE;      /* '<Root>/Unit Delay3' */
  TeAP_e_Alert UnitDelay4_DSTATE;      /* '<Root>/Unit Delay4' */
  TeAP_e_Alert UnitDelay5_DSTATE;      /* '<Root>/Unit Delay5' */
  TeAP_e_Alert UnitDelay6_DSTATE;      /* '<Root>/Unit Delay6' */
  real32_T LastGood_RearCenterMinDist; /* '<S88>/CalculateMinDistances1' */
  real32_T LastGood_RearRightMinDist;  /* '<S88>/CalculateMinDistances1' */
  real32_T LastGood_FrntCenterMinDist; /* '<S88>/CalculateMinDistances1' */
  real32_T LastGood_FrntRightMinDist;  /* '<S88>/CalculateMinDistances1' */
  real32_T LastGood_RearLeftMinDist;   /* '<S88>/CalculateMinDistances1' */
  real32_T LastGood_FrntLeftMinDist;   /* '<S88>/CalculateMinDistances1' */
  int32_T Add_DWORK1;                  /* '<S109>/Add' */
  uint32_T temporalCounter_i1;         /* '<S42>/Chart1' */
  int16_T UnitDelay_DSTATE_f;          /* '<S108>/Unit Delay' */
  int16_T UnitDelay_DSTATE_k;          /* '<S110>/Unit Delay' */
  int16_T UnitDelay_DSTATE_c;          /* '<S111>/Unit Delay' */
  int16_T UnitDelay_DSTATE_l;          /* '<S130>/Unit Delay' */
  int16_T UnitDelay1_DSTATE_h;         /* '<S130>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_jj;         /* '<S131>/Unit Delay' */
  int16_T UnitDelay1_DSTATE_j;         /* '<S131>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_b;          /* '<S132>/Unit Delay' */
  int16_T UnitDelay1_DSTATE_n;         /* '<S132>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_o;          /* '<S109>/Unit Delay' */
  int16_T UnitDelay1_DSTATE_k;         /* '<S109>/Unit Delay1' */
  int16_T UnitDelay_DSTATE_i;          /* '<S139>/Unit Delay' */
  int16_T UnitDelay1_DSTATE_l;         /* '<S139>/Unit Delay1' */
  uint16_T UnitDelay2_DSTATE_m;        /* '<S203>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_c;        /* '<S204>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_a;        /* '<S163>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_j;        /* '<S167>/Unit Delay2' */
  uint16_T UnitDelay2_DSTATE_af;       /* '<S171>/Unit Delay2' */
  int16_T BoundaryDist;                /* '<S93>/RC_Dbnc2' */
  int16_T BoundaryDist_a;              /* '<S93>/RC_Dbnc1' */
  int16_T BoundaryDist_c;              /* '<S93>/RC_Dbnc' */
  int16_T BoundaryDist_f;              /* '<S92>/FC_Dbnc2' */
  int16_T BoundaryDist_e;              /* '<S92>/FC_Dbnc1' */
  int16_T BoundaryDist_o;              /* '<S92>/FC_Dbnc' */
  int16_T MaxDist;                     /* '<S88>/CalculateMinDistances1' */
  int16_T current_point_x;             /* '<S88>/CalculateMinDistances1' */
  int16_T current_point_y;             /* '<S88>/CalculateMinDistances1' */
  int16_T PrevRightRear_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T PrevLeftFront_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T PrevCenterFront_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T PrevRightFront_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T PrevCenterRear_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T PrevLeftRear_MeAP_cm_ObjXPon;/* '<S88>/CalculateMinDistances1' */
  int16_T DistanceToObject;            /* '<S88>/CalculateMinDistances1' */
  int16_T CenterRegionThsd;            /* '<S88>/CalculateMinDistances1' */
  uint16_T Timer;                      /* '<S135>/DistDbnc' */
  uint16_T Timer_p;                    /* '<S134>/DistDbnc' */
  uint16_T Timer_b;                    /* '<S133>/DistDbnc' */
  uint16_T Timer_m;                    /* '<S114>/DistDbnc' */
  uint16_T Timer_k;                    /* '<S113>/DistDbnc' */
  uint16_T Timer_a;                    /* '<S112>/DistDbnc' */
  uint16_T temporalCounter_i2;         /* '<S42>/Chart1' */
  boolean_T UnitDelay1_DSTATE_c;       /* '<S205>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_h5;      /* '<S203>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_p;       /* '<S206>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_d;       /* '<S204>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_a;       /* '<S164>/Unit Delay1' */
  boolean_T UnitDelay1_DSTATE_g;       /* '<S19>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE_md;       /* '<S168>/Unit Delay' */
  boolean_T UnitDelay1_DSTATE_hd;      /* '<S172>/Unit Delay1' */
  uint8_T is_active_c6_DT24_CVADAS_AP_CodGen;/* '<S93>/RC_Dbnc2' */
  uint8_T RCDbncCount;                 /* '<S93>/RC_Dbnc2' */
  uint8_T is_active_c5_DT24_CVADAS_AP_CodGen;/* '<S93>/RC_Dbnc1' */
  uint8_T RCDbncCount_c;               /* '<S93>/RC_Dbnc1' */
  uint8_T is_active_c2_DT24_CVADAS_AP_CodGen;/* '<S93>/RC_Dbnc' */
  uint8_T RCDbncCount_d;               /* '<S93>/RC_Dbnc' */
  uint8_T is_active_c17_DT24_CVADAS_AP_CodGen;/* '<S135>/DistDbnc' */
  uint8_T is_c17_DT24_CVADAS_AP_CodGen;/* '<S135>/DistDbnc' */
  uint8_T is_DBNC_ENABLED;             /* '<S135>/DistDbnc' */
  uint8_T is_active_c16_DT24_CVADAS_AP_CodGen;/* '<S134>/DistDbnc' */
  uint8_T is_c16_DT24_CVADAS_AP_CodGen;/* '<S134>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_a;           /* '<S134>/DistDbnc' */
  uint8_T is_active_c15_DT24_CVADAS_AP_CodGen;/* '<S133>/DistDbnc' */
  uint8_T is_c15_DT24_CVADAS_AP_CodGen;/* '<S133>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_j;           /* '<S133>/DistDbnc' */
  uint8_T is_active_c14_DT24_CVADAS_AP_CodGen;/* '<S114>/DistDbnc' */
  uint8_T is_c14_DT24_CVADAS_AP_CodGen;/* '<S114>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_l;           /* '<S114>/DistDbnc' */
  uint8_T is_active_c13_DT24_CVADAS_AP_CodGen;/* '<S113>/DistDbnc' */
  uint8_T is_c13_DT24_CVADAS_AP_CodGen;/* '<S113>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_c;           /* '<S113>/DistDbnc' */
  uint8_T is_active_c12_DT24_CVADAS_AP_CodGen;/* '<S112>/DistDbnc' */
  uint8_T is_c12_DT24_CVADAS_AP_CodGen;/* '<S112>/DistDbnc' */
  uint8_T is_DBNC_ENABLED_p;           /* '<S112>/DistDbnc' */
  uint8_T is_active_c8_DT24_CVADAS_AP_CodGen;/* '<S92>/FC_Dbnc2' */
  uint8_T FCDbncCount;                 /* '<S92>/FC_Dbnc2' */
  uint8_T is_active_c7_DT24_CVADAS_AP_CodGen;/* '<S92>/FC_Dbnc1' */
  uint8_T FCDbncCount_o;               /* '<S92>/FC_Dbnc1' */
  uint8_T is_active_c4_DT24_CVADAS_AP_CodGen;/* '<S92>/FC_Dbnc' */
  uint8_T FCDbncCount_a;               /* '<S92>/FC_Dbnc' */
  uint8_T point_index;                 /* '<S88>/CalculateMinDistances1' */
  uint8_T current_point_confidence;    /* '<S88>/CalculateMinDistances1' */
  uint8_T current_point_height;        /* '<S88>/CalculateMinDistances1' */
  uint8_T FrontPointsArray[10];        /* '<S88>/CalculateMinDistances1' */
  uint8_T RearIdx;                     /* '<S88>/CalculateMinDistances1' */
  uint8_T FrontIdx;                    /* '<S88>/CalculateMinDistances1' */
  uint8_T RearPointsArray[10];         /* '<S88>/CalculateMinDistances1' */
  uint8_T RearWallCount;               /* '<S88>/CalculateMinDistances1' */
  uint8_T RearWallCountIdx;            /* '<S88>/CalculateMinDistances1' */
  uint8_T FrntWallCountIdx;            /* '<S88>/CalculateMinDistances1' */
  uint8_T is_active_c39_DT24_CVADAS_AP_CodGen;/* '<S46>/RearAlertCount' */
  uint8_T is_c39_DT24_CVADAS_AP_CodGen;/* '<S46>/RearAlertCount' */
  uint8_T is_active_c38_DT24_CVADAS_AP_CodGen;/* '<S46>/RRAlertCount' */
  uint8_T is_c38_DT24_CVADAS_AP_CodGen;/* '<S46>/RRAlertCount' */
  uint8_T is_active_c67_DT24_CVADAS_AP_CodGen;/* '<S46>/RLAlertCount' */
  uint8_T is_c67_DT24_CVADAS_AP_CodGen;/* '<S46>/RLAlertCount' */
  uint8_T is_active_c64_DT24_CVADAS_AP_CodGen;/* '<S46>/FrontAlertCount' */
  uint8_T is_c64_DT24_CVADAS_AP_CodGen;/* '<S46>/FrontAlertCount' */
  uint8_T is_active_c60_DT24_CVADAS_AP_CodGen;/* '<S46>/FRAlertCount' */
  uint8_T is_c60_DT24_CVADAS_AP_CodGen;/* '<S46>/FRAlertCount' */
  uint8_T is_active_c37_DT24_CVADAS_AP_CodGen;/* '<S46>/FLAlertCount' */
  uint8_T is_c37_DT24_CVADAS_AP_CodGen;/* '<S46>/FLAlertCount' */
  uint8_T is_active_c3_DT24_CVADAS_AP_CodGen;/* '<S42>/Chart1' */
  uint8_T is_c3_DT24_CVADAS_AP_CodGen; /* '<S42>/Chart1' */
  uint8_T is_DetectBlockage;           /* '<S42>/Chart1' */
  boolean_T ObjInFront;                /* '<S88>/CalculateMinDistances1' */
  boolean_T CalcSideRegLongThresh_MODE;/* '<S97>/CalcSideRegLongThresh' */
  DW_RSL_Blk_DT24_CVADAS_AP_CodGen_T sf_RSR_Blk;/* '<S46>/RSR_Blk' */
  DW_RSL_Blk_DT24_CVADAS_AP_CodGen_T sf_RSL_Blk;/* '<S46>/RSL_Blk' */
  DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T sf_ROR_Blk;/* '<S46>/ROR_Blk' */
  DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T sf_ROL_Blk;/* '<S46>/ROL_Blk' */
  DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T sf_RIR_Blk;/* '<S46>/RIR_Blk' */
  DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T sf_RIL_Blk;/* '<S46>/RIL_Blk' */
  DW_FSL_Blk_DT24_CVADAS_AP_CodGen_T sf_FSR_Blk;/* '<S46>/FSR_Blk' */
  DW_FSL_Blk_DT24_CVADAS_AP_CodGen_T sf_FSL_Blk;/* '<S46>/FSL_Blk' */
  DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T sf_FOR_Blk;/* '<S46>/FOR_Blk' */
  DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T sf_FOL_Blk;/* '<S46>/FOL_Blk' */
  DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T sf_FIR_Blk;/* '<S46>/FIR_Blk' */
  DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T sf_FIL_Blk;/* '<S46>/FIL_Blk' */
} DW_DT24_CVADAS_AP_CodGen_T;

/* Invariant block signals (default storage) */
typedef struct {
  const real32_T Gain2;                /* '<S12>/Gain2' */
  const real32_T Saturation;           /* '<S12>/Saturation' */
  const SlotSide_t m_SlotSide;         /* '<S30>/Data Type Conversion1' */
  const SlotSide_t m_SlotSide_o;       /* '<S30>/Data Type Conversion5' */
  const SlotSide_t m_SlotSide_k;       /* '<S31>/Data Type Conversion1' */
  const ParkingSlotType_t m_SlotType;  /* '<S30>/Data Type Conversion' */
  const ParkingSlotType_t m_SlotType_f;/* '<S30>/Data Type Conversion4' */
  const ParkingSlotType_t m_SlotType_l;/* '<S31>/Data Type Conversion' */
  const ParkingSlotID_t m_SlotID;      /* '<S30>/Data Type Conversion2' */
  const ParkingSlotID_t m_SlotID_p;    /* '<S30>/Data Type Conversion6' */
  const ParkingSlotID_t m_SlotID_j;    /* '<S31>/Data Type Conversion2' */
  const bool_t m_isSlotValid_b;        /* '<S30>/Data Type Conversion3' */
  const bool_t m_isSlotValid_b_d;      /* '<S30>/Data Type Conversion7' */
  const bool_t m_isSlotValid_b_g;      /* '<S31>/Data Type Conversion3' */
  const boolean_T LogicalOperator1;    /* '<S171>/Logical Operator1' */
  const boolean_T IeVBII_b_SnowPlowAttached;/* '<S23>/Data Type Conversion10' */
} ConstB_DT24_CVADAS_AP_CodGen_T;

/* Real-time Model Data Structure */
struct tag_RTM_DT24_CVADAS_AP_CodGen_T {
  const char_T *errorStatus;
};

/* Block signals (default storage) */
extern B_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_B;

/* Block states (default storage) */
extern DW_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_DW;

/* External data declarations for dependent source files */
extern const TbVBIA_VehState_AP DT24_CVADAS_AP_CodGen_rtZTbVBIA_VehState_AP;/* TbVBIA_VehState_AP ground */
extern const TbNVM_ProxyCalibParam
  DT24_CVADAS_AP_CodGen_rtZTbNVM_ProxyCalibParam;/* TbNVM_ProxyCalibParam ground */
extern const uint64m_T DT24_CVADAS_AP_CodGen_ufix64_GND;/* uint64m_T ground */
extern const TbHMI_HMIInfoToAP DT24_CVADAS_AP_CodGen_rtZTbHMI_HMIInfoToAP;/* TbHMI_HMIInfoToAP ground */
extern const TbAP_FPAWarnOut_t DT24_CVADAS_AP_CodGen_rtZTbAP_FPAWarnOut_t;/* TbAP_FPAWarnOut_t ground */
extern const TbAP_RPAWarnOut_t DT24_CVADAS_AP_CodGen_rtZTbAP_RPAWarnOut_t;/* TbAP_RPAWarnOut_t ground */
extern const HMIInfoToAP_t DT24_CVADAS_AP_CodGen_rtZHMIInfoToAP_t;/* HMIInfoToAP_t ground */
extern const ConstB_DT24_CVADAS_AP_CodGen_T DT24_CVADAS_AP_CodGen_ConstB;/* constant block i/o */

/* Model entry point functions */
extern "C" void DT24_CVADAS_AP_CodGen_initialize(void);
extern "C" void DT24_CVADAS_AP_CodGen_step(void);
extern "C" void DT24_CVADAS_AP_CodGen_terminate(void);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern TbAP_APSMPAOut_t APSMPAOut;     /* '<S208>/Bus Creator1' */
extern real32_T CONST_DPS2RPS;/* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* conversion parameter from degree/s to rad/s */
extern uint16_T CeAP_ms_SampleTime;    /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S112>/DistDbnc'
                                        * '<S113>/DistDbnc'
                                        * '<S114>/DistDbnc'
                                        * '<S133>/DistDbnc'
                                        * '<S134>/DistDbnc'
                                        * '<S135>/DistDbnc'
                                        */
extern real32_T DS_ANGLE;              /* '<S12>/Data Type Conversion269' */
extern real32_T DS_WheelSpeed_RL;      /* '<S23>/Data Type Conversion32' */
extern real32_T DS_WheelSpeed_RR;      /* '<S23>/Data Type Conversion38' */
extern TbAP_DriveAssistStatOut_t DriveAssistStatOut;/* '<S208>/Bus Creator2' */
extern TbAP_FPAWarnOut_t FPAWarnOut;   /* '<S209>/Bus Creator1' */
extern TbAP_InputVrntTunParam_t IbAP_InputVrntTunParam;/* '<S25>/Switch' */
extern boolean_T IeAP_b_DisForceNoiseMode;/* '<S19>/Logical Operator1' */
extern boolean_T IeHMI_b_BackBtnPsd;   /* '<S11>/Relational Operator2' */
extern boolean_T IeHMI_b_HMIHandshake; /* '<S11>/Logical Operator2' */
extern boolean_T IeHMI_b_UsrSlotSelStatus;/* '<S11>/Relational Operator8' */
extern TeAutoPark_e_ParkStyle IeHMI_e_ParkStyle;/* '<S11>/Switch' */
extern TeAP_e_UsrPPPAManeuverSel IeHMI_e_UsrPPPAManeuverSel;/* '<S11>/Switch4' */
extern TeHMI_e_UsrParkOutSide IeHMI_e_UsrParkOutSideSel;/* '<S11>/Switch2' */
extern real32_T K_Overlap_Thrsld_RAEB[5];
                              /* Referenced by: '<S25>/K_Overlap_Thrsld_RAEB' */
extern real32_T K_e_RAEB_DrawingTubeOffset;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_VehicleWidth; /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/K_e_RAEB_VehicleWidth'
                                        */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_WarnOffset;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* To feed lateral offset to issue warning */
extern uint16_T KeAP_Cnt_GearFiltTimeThd;/* Referenced by:
                                          * '<S25>/KeAP_Cnt_GearFiltTimeThd'
                                          * '<S183>/Constant1'
                                          * '<S183>/Constant3'
                                          */

/* Gear Filtering time threshold 400ms */
extern uint16_T KeAP_Cnt_GearOverrideTimeThd;/* Referenced by:
                                              * '<Root>/CVADAS_AutoPark_Main'
                                              * '<S25>/KeAP_Cnt_GearOverrideTimeThd'
                                              */

/* Gear override time threshold */
extern real32_T KeAP_M_StrTrqValLimit;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T KeAP_b_AutoParkEn;
                                  /* Referenced by: '<S25>/KeAP_b_AutoParkEn' */

/* Ego vehicle shall be equipped with Auto Park Assist feature */
extern boolean_T KeAP_b_CruisAgeBasedGhsObjDet;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern boolean_T KeAP_b_DbncEnabld;    /* Referenced by:
                                        * '<S112>/Constant2'
                                        * '<S113>/Constant2'
                                        * '<S114>/Constant2'
                                        * '<S133>/Constant2'
                                        * '<S134>/Constant2'
                                        * '<S135>/Constant2'
                                        */
extern boolean_T KeAP_b_DensityBasedGhstObjDet;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern boolean_T KeAP_b_DevlopmentTest;/* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S6>/Constant'
                                        * '<S9>/Constant'
                                        * '<S25>/Constant'
                                        * '<S25>/Constant1'
                                        * '<S25>/Constant2'
                                        * '<S25>/Constant3'
                                        */

/* Test Parameter used to change value of Tunable parameter while Testing */
extern boolean_T KeAP_b_EnFeatForceNoiseMode;/* Referenced by: '<S19>/Constant' */
extern boolean_T KeAP_b_EnVehStandstillArcBlip;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T KeAP_b_EnWallAcurracy;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T KeAP_b_FPAEn;         /* Referenced by: '<S25>/KeAP_b_FPAEn' */

/* Ego vehicle shall be equipped with Front Park Assist feature */
extern uint8_T KeAP_b_FeatDetectWall;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern boolean_T KeAP_b_ForceEnArcTrack;/* Referenced by:
                                         * '<S88>/CalculateMinDistances1'
                                         * '<S100>/Constant5'
                                         */
extern boolean_T KeAP_b_FullAutoPark;
                                /* Referenced by: '<S25>/KeAP_b_FullAutoPark' */

/* Ego vehicle shall be equipped with Fully Auto Park Assist feature */
extern boolean_T KeAP_b_HeightFlagEnabled;/* Referenced by:
                                           * '<S92>/FC_Dbnc'
                                           * '<S92>/FC_Dbnc1'
                                           * '<S92>/FC_Dbnc2'
                                           * '<S93>/RC_Dbnc'
                                           * '<S93>/RC_Dbnc1'
                                           * '<S93>/RC_Dbnc2'
                                           */
extern boolean_T KeAP_b_HookConnected; /* Referenced by:
                                        * '<S25>/KeAP_b_HookConnected'
                                        * '<S93>/Constant2'
                                        * '<S93>/Constant5'
                                        * '<S93>/Constant8'
                                        */

/* Hook Connected 0= Not Connected 1=Connected */
extern boolean_T KeAP_b_RPAwithBrk;    /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_b_RPAwithBrk'
                                        */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake */
extern boolean_T KeAP_b_RPAwithSurroundView;
                         /* Referenced by: '<S25>/KeAP_b_RPAwithSurroundView' */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake and Surround View Interaction */
extern boolean_T KeAP_b_RearDistCorrBasedVehSpd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T KeAP_b_SteerOnlyAutoPark;
                           /* Referenced by: '<S25>/KeAP_b_SteerOnlyAutoPark' */

/* Ego vehicle shall be equipped with Steer only Auto Park Assist feature */
extern boolean_T KeAP_b_SuppArcInNoForceNoise;/* Referenced by:
                                               * '<S155>/Constant'
                                               * '<S156>/Constant'
                                               * '<S157>/Constant'
                                               * '<S158>/Constant'
                                               * '<S159>/Constant'
                                               * '<S160>/Constant'
                                               * '<S161>/Constant'
                                               * '<S162>/Constant'
                                               */
extern uint8_T KeAP_b_SupprsUssGlblHght;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T KeAP_b_SwitchOldAlgo;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern int16_T KeAP_cm_CenterWarnLatThreshold;/* Referenced by: '<S88>/Constant2' */

/* Parameter to decide center region */
extern int16_T KeAP_cm_DistZone1;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone1'
                                        * '<S25>/KeAP_cm_DistZone8'
                                        */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_DistZone2;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone2'
                                        * '<S25>/KeAP_cm_DistZone9'
                                        * '<S88>/CalculateMinDistances1'
                                        * '<S93>/RC_Dbnc1'
                                        * '<S93>/RC_Dbnc2'
                                        * '<S100>/Constant3'
                                        */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_DistZone3;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone10'
                                        * '<S25>/KeAP_cm_DistZone3'
                                        */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_DistZone4;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone11'
                                        * '<S25>/KeAP_cm_DistZone4'
                                        * '<S88>/CalculateMinDistances1'
                                        */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_DistZone5;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone12'
                                        * '<S25>/KeAP_cm_DistZone5'
                                        */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_DistZone6;      /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_DistZone13'
                                        * '<S25>/KeAP_cm_DistZone6'
                                        * '<S88>/CalculateMinDistances1'
                                        * '<S93>/RC_Dbnc'
                                        */

/* Warning Zone 6 Dist */
extern int16_T KeAP_cm_FrntDistArcComp;/* Referenced by:
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
extern int16_T KeAP_cm_FrntDistZone1;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_FrntDistZone2;  /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S92>/FC_Dbnc1'
                                        * '<S92>/FC_Dbnc2'
                                        */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_FrntDistZone3;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_FrntDistZone4;  /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S92>/FC_Dbnc'
                                        */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_FrntDistZone5;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_FrntDistZone6;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Warning Zone 6 Dist */
extern int16_T KeAP_cm_FrntLongDistAdj;
                            /* Referenced by: '<S25>/KeAP_cm_FrntLongDistAdj' */

/* Longitudanl Distance from Rear Axle to Front edge of vehicle */
extern real32_T KeAP_cm_FrntWallZone1Adj;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern int16_T KeAP_cm_HalfVehicleWidth;
                           /* Referenced by: '<S25>/KeAP_cm_HalfVehicleWidth' */

/* Ego Vehicle Car Half Width */
extern int16_T KeAP_cm_HookDistOffset; /* Referenced by:
                                        * '<S25>/KeAP_cm_HookDistOffset'
                                        * '<S93>/Constant4'
                                        * '<S93>/Constant6'
                                        * '<S93>/Constant9'
                                        */

/* Length of Permanant Hook attached at back side of Ego */
extern int16_T KeAP_cm_MaxNoObjDetctDist;
                          /* Referenced by: '<S25>/KeAP_cm_MaxNoObjDetctDist' */

/* Max distance when no object detected */
extern int16_T KeAP_cm_NhXmaxOffset;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant1'
                                        */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhXminOffset;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant'
                                        */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYmaxOffset;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant3'
                                        */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYminOffset;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S99>/Constant2'
                                        */

/* NeighboutHood Window */
extern uint16_T KeAP_cm_ObjPrestFCDistThd;/* Referenced by:
                                           * '<S16>/Constant'
                                           * '<S25>/KeAP_cm_ObjPrestFCDistThd'
                                           */

/* Distance threshold to detect object in Front Centre */
extern uint16_T KeAP_cm_ObjPrestRCDistThd;/* Referenced by:
                                           * '<S16>/Constant1'
                                           * '<S25>/KeAP_cm_ObjPrestRCDistThd'
                                           */

/* Distance threshold to detect object in Rear Centre */
extern real32_T KeAP_cm_RearBrkDistChngLwThresh;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Rear Braking Dist Change lower Threshold */
extern real32_T KeAP_cm_RearBrkDistChngUpThresh;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Rear Braking Dist Change upper Threshold */
extern int16_T KeAP_cm_RearDistArcComp;/* Referenced by:
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
extern int16_T KeAP_cm_RearLongDistAdj;/* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cm_RearLongDistAdj'
                                        */

/* Longitudanl Distance from Rear Axle to Rear edge of vehicle */
extern real32_T KeAP_cm_RearWallZone1Adj;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern int16_T KeAP_cm_StndStillObjMinDistThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern int16_T KeAP_cm_VIMGhstObjMinDistThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern int16_T KeAP_cm_VehContourFrntXAdj;/* Referenced by:
                                           * '<S95>/Constant'
                                           * '<S95>/Constant1'
                                           */

/* X-coordinate for Adjustment for Front side */
extern int16_T KeAP_cm_VehContourRearXAdj;/* Referenced by:
                                           * '<S95>/Constant2'
                                           * '<S95>/Constant3'
                                           */

/* X-coordinate for Adjustment for Front side */
extern int16_T KeAP_cm_VehContour_FIL_x;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur1' */

/* X-coordinate for FIL Edge */
extern int16_T KeAP_cm_VehContour_FIL_y;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur2' */

/* Y-coordinate for FIL Edge */
extern int16_T KeAP_cm_VehContour_FIR_x;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur1' */

/* X-coordinate for FIR Edge */
extern int16_T KeAP_cm_VehContour_FIR_y;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur2' */

/* Y-coordinate for FIR Edge */
extern int16_T KeAP_cm_VehContour_FOL_x;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd1' */

/* X-coordinate for FOL Edge */
extern int16_T KeAP_cm_VehContour_FOL_y;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd2' */

/* Y-coordinate for FOL Edge */
extern int16_T KeAP_cm_VehContour_FOR_x;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur1' */

/* X-coordinate for FOR Edge */
extern int16_T KeAP_cm_VehContour_FOR_y;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur2' */

/* Y-coordinate for FOR Edge */
extern int16_T KeAP_cm_VehContour_FSL_x;
                    /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout1' */

/* X-coordinate for FSL Edge */
extern int16_T KeAP_cm_VehContour_FSL_y;/* Referenced by:
                                         * '<S25>/KeAP_s_GearShiftWaitCntTimeout2'
                                         * '<S95>/Constant4'
                                         */

/* Y-coordinate for FSL Edge */
extern int16_T KeAP_cm_VehContour_FSR_x;
                               /* Referenced by: '<S25>/KeAP_s_SpdExceedDur1' */

/* X-coordinate for FSR Edge */
extern int16_T KeAP_cm_VehContour_FSR_y;/* Referenced by:
                                         * '<S25>/KeAP_s_SpdExceedDur2'
                                         * '<S95>/Constant6'
                                         */

/* Y-coordinate for FSR Edge */
extern int16_T KeAP_cm_VehContour_RIL_x;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur3' */

/* X-coordinate for RIL Edge */
extern int16_T KeAP_cm_VehContour_RIL_y;
                   /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur4' */

/* Y-coordinate for RIL Edge */
extern int16_T KeAP_cm_VehContour_RIR_x;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur3' */

/* X-coordinate for RIR Edge */
extern int16_T KeAP_cm_VehContour_RIR_y;
                        /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur4' */

/* Y-coordinate for RIR Edge */
extern int16_T KeAP_cm_VehContour_ROL_x;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur3' */

/* X-coordinate for ROL Edge */
extern int16_T KeAP_cm_VehContour_ROL_y;
                        /* Referenced by: '<S25>/KeAP_s_SeekPhaseTimeoutDur4' */

/* Y-coordinate for ROL Edge */
extern int16_T KeAP_cm_VehContour_ROR_x;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd3' */

/* X-coordinate for ROR Edge */
extern int16_T KeAP_cm_VehContour_ROR_y;
                       /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd4' */

/* Y-coordinate for ROR Edge */
extern int16_T KeAP_cm_VehContour_RSL_x;
                               /* Referenced by: '<S25>/KeAP_s_SpdExceedDur3' */

/* X-coordinate for RSL Edge */
extern int16_T KeAP_cm_VehContour_RSL_y;/* Referenced by:
                                         * '<S25>/KeAP_s_SpdExceedDur4'
                                         * '<S95>/Constant5'
                                         */

/* Y-coordinate for RSL Edge */
extern int16_T KeAP_cm_VehContour_RSR_x;
                    /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout3' */

/* X-coordinate for RSR Edge */
extern int16_T KeAP_cm_VehContour_RSR_y;/* Referenced by:
                                         * '<S25>/KeAP_s_GearShiftWaitCntTimeout4'
                                         * '<S95>/Constant7'
                                         */

/* Y-coordinate for RSR Edge */
extern uint16_T KeAP_cm_VehicleWidth;
                               /* Referenced by: '<S25>/KeAP_cm_VehicleWidth' */

/* Ego Vehicle Car Width */
extern int16_T KeAP_cm_WarnOffset;     /* Referenced by:
                                        * '<S25>/KeAP_cm_WarnOffset'
                                        * '<S88>/Constant1'
                                        * '<S95>/Constant8'
                                        */

/* Warn Offset Distance  */
extern uint16_T KeAP_cnt_AbortDelayWaitCnt;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KeAP_cnt_AbortHMIWaitCnt;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_ArcBlipStandstillTimer;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_ArcBlipVehInMotTimer[6];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KeAP_cnt_ArcBlipVehSpdThd[6];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_BootupTimeThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time threshold for ECU bootup */
extern uint16_T KeAP_cnt_BtnPressPopUpTimeThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time for which Startup PopUp Requests are shown */
extern uint16_T KeAP_cnt_ChimeVolChgAlert;
                          /* Referenced by: '<S25>/KeAP_cnt_ChimeVolChgAlert' */

/* Chime Volume Change Alert time threshold - Half sec chime */
extern uint8_T KeAP_cnt_CruisAgeBasedDbncCount;/* Referenced by:
                                                * '<S92>/FC_Dbnc'
                                                * '<S92>/FC_Dbnc1'
                                                * '<S92>/FC_Dbnc2'
                                                * '<S93>/RC_Dbnc'
                                                * '<S93>/RC_Dbnc1'
                                                * '<S93>/RC_Dbnc2'
                                                */
extern int16_T KeAP_cnt_DebounceTimeThd;
                           /* Referenced by: '<S25>/KeAP_cnt_DebounceTimeThd' */

/* Debounce time threshold */
extern uint8_T KeAP_cnt_DensStdStlHighPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_DensStdStlLowPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_DensStdStlObjCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_DensVIMHighPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_DensVIMLowPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_DensVIMObjCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint16_T KeAP_cnt_ForceNoiseModeTimeThd;/* Referenced by: '<S168>/Constant1' */
extern uint16_T KeAP_cnt_FrntChimeDisTimeThd;
                       /* Referenced by: '<S25>/KeAP_cnt_FrntChimeDisTimeThd' */

/* Front Chime Disable time threshold when Vehicle Standstill condition is true  */
extern uint16_T KeAP_cnt_HalfSecChimeAlert;
                         /* Referenced by: '<S25>/KeAP_cnt_HalfSecChimeAlert' */

/* Half Sec Chime Alert Time Threshold */
extern uint16_T KeAP_cnt_LEDBlinkTimeThd;
                           /* Referenced by: '<S25>/KeAP_cnt_LEDBlinkTimeThd' */

/* Time Step for LED blinking  */
extern real32_T KeAP_cnt_NoiseModeRearDistComp;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_PlntModeLEDBlinkTimeThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Time Step for LED blinking for ECU-In Plant Mode */
extern real32_T KeAP_cnt_RearDistCompTimeThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_RelCntrlWaitThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_SPMBlinkLEDDur;
                                  /* Referenced by: '<S25>/KeAP_cm_DistZone7' */

/* PPPA LED Blinking Time Threshold 5 sec */
extern uint16_T KeAP_cnt_ScreenChimeTimeoutDur;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Screen Chime Time Threshold */
extern uint16_T KeAP_cnt_ScreenWaitTimeoutDur;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_cnt_StandstillTimeoutDur;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/*  Standstill Timer 9 min 50sec */
extern uint8_T KeAP_cnt_StndStSideCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_StndStSideLowCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_StndStillCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_StndStillPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_StndStillSideLowPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_StndStillSidePntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint16_T KeAP_cnt_SwtStuckTimeThd;
                           /* Referenced by: '<S25>/KeAP_cnt_SwtStuckTimeThd' */

/* Maximum time threshold for Switch to be presssed condition 60sec */
extern uint16_T KeAP_cnt_TimeStep;     /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_cnt_TimeStep'
                                        * '<S89>/Constant1'
                                        * '<S168>/Constant'
                                        * '<S183>/Constant'
                                        * '<S183>/Constant2'
                                        */

/* Time Step for Counter  */
extern uint8_T KeAP_cnt_VIMGhstObjCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_VIMGhstObjPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_VIMSideLowPntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_VIMSideObjCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_VIMSideObjLowCruiseAgeThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint8_T KeAP_cnt_VIMSidePntConfThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern uint16_T KeAP_cnt_VehKeyOnTimeThd;
                           /* Referenced by: '<S25>/KeAP_cnt_VehKeyOnTimeThd' */

/* Vehicle Key On Time Threshold */
extern uint16_T KeAP_cnt_VehMovementCntThd;/* Referenced by: '<S167>/Constant2' */
extern real32_T KeAP_degC_OperatingTempThd;
                         /* Referenced by: '<S25>/KeAP_degC_OperatingTempThd' */

/* Maximum operating Temprature threshold  */
extern real32_T KeAP_deg_SteerAngelDiffThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint8_T KeAP_e_GbTypAT;         /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_e_GbTypAT'
                                        */

/* ATX Gear_Box_Type */
extern real32_T KeAP_k_BrakeIGain;/* Referenced by: '<S25>/KeAP_k_BrakeIGain' */
extern real32_T KeAP_k_BrakeLowerLimit;
                             /* Referenced by: '<S25>/KeAP_k_BrakeLowerLimit' */
extern real32_T KeAP_k_BrakePGain;/* Referenced by: '<S25>/KeAP_k_BrakePGain' */
extern real32_T KeAP_k_BrakeUpperLimit;
                             /* Referenced by: '<S25>/KeAP_k_BrakeUpperLimit' */
extern real32_T KeAP_k_CtrlOutCollDetActivate;
                      /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetActivate' */
extern real32_T KeAP_k_CtrlOutCollDetCollDistLimit;
                 /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetCollDistLimit' */
extern real32_T KeAP_k_CtrlOutCollDetRedStopVal;
                    /* Referenced by: '<S25>/KeAP_k_CtrlOutCollDetRedStopVal' */
extern real32_T KeAP_k_CtrlOutGearDrive;
                            /* Referenced by: '<S25>/KeAP_k_CtrlOutGearDrive' */
extern real32_T KeAP_k_CtrlOutGearPark;
                             /* Referenced by: '<S25>/KeAP_k_CtrlOutGearPark' */
extern real32_T KeAP_k_CtrlOutGearReverse;
                          /* Referenced by: '<S25>/KeAP_k_CtrlOutGearReverse' */
extern real32_T KeAP_k_CtrlOutRemainDistNA;
                         /* Referenced by: '<S25>/KeAP_k_CtrlOutRemainDistNA' */
extern real32_T KeAP_k_CtrlOutVehSpdMaxSpotSteer;
                   /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotSteer' */
extern real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
           /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd' */
extern real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
                 /* Referenced by: '<S25>/KeAP_k_CtrlOutVehSpdMaxSpotStrTime' */
extern real32_T KeAP_k_DetWP_PreviewTime;
                           /* Referenced by: '<S25>/KeAP_k_DetWP_PreviewTime' */
extern real32_T KeAP_k_LatHeadDevDGain;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevDGain' */
extern real32_T KeAP_k_LatHeadDevIGain;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevIGain' */
extern real32_T KeAP_k_LatHeadDevPGain;
                             /* Referenced by: '<S25>/KeAP_k_LatHeadDevPGain' */
extern real32_T KeAP_k_LatPathDevDGain;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevDGain' */
extern real32_T KeAP_k_LatPathDevIGain;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevIGain' */
extern real32_T KeAP_k_LatPathDevPGain;
                             /* Referenced by: '<S25>/KeAP_k_LatPathDevPGain' */
extern real32_T KeAP_k_PathSepaMinSpd;
                              /* Referenced by: '<S25>/KeAP_k_PathSepaMinSpd' */
extern real32_T KeAP_k_PathSepaSpdRampGrd;
                          /* Referenced by: '<S25>/KeAP_k_PathSepaSpdRampGrd' */
extern real32_T KeAP_k_SteerLowerLimit;
                             /* Referenced by: '<S25>/KeAP_k_SteerLowerLimit' */
extern real32_T KeAP_k_SteerUpperLimit;
                             /* Referenced by: '<S25>/KeAP_k_SteerUpperLimit' */
extern real32_T KeAP_k_WhlCircum;  /* Referenced by: '<S25>/KeAP_k_WhlCircum' */
extern real32_T KeAP_kph_ConfThdSpdBrkPnts[2];/* Referenced by: '<S88>/Constant3' */
extern real32_T KeAP_kph_EnblHysThd;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_EnblHysThd'
                                        */

/* Hystere sis threshold to apply for all vehicle speed related threshold parameters */
extern real32_T KeAP_kph_FrntWarnMaxSpdThd;/* Referenced by:
                                            * '<Root>/CVADAS_AutoPark_Main'
                                            * '<S25>/KeAP_kph_FrntWarnMaxSpdThd'
                                            */

/* Vehicle speed threshold during Front Park Assist feature */
extern real32_T KeAP_kph_PSDOffThd;    /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_PSDOffThd'
                                        */

/* Vehicle speed threshold during detection the parking slot */
extern real32_T KeAP_kph_PSDOnThd;/* Referenced by: '<S25>/KeAP_kph_PSDOnThd' */

/* Vehicle speed threshold to warn driver about hight speed during parking slot detection */
extern real32_T KeAP_kph_ParkMnvThd;   /* Referenced by:
                                        * '<Root>/CVADAS_AutoPark_Main'
                                        * '<S25>/KeAP_kph_ParkMnvThd'
                                        */

/* Ego Vehicle speed limit to continue parking maneuvering */
extern real32_T KeAP_kph_RearWarnMaxSpdThd;/* Referenced by:
                                            * '<Root>/CVADAS_AutoPark_Main'
                                            * '<S25>/KeAP_kph_RearWarnMaxSpdThd'
                                            */

/* Vehicle speed threshold during Rear Park Assist feature */
extern real32_T KeAP_kph_StandStillSpdThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_ms_DbncTimeThsd;  /* Referenced by:
                                        * '<S112>/Constant1'
                                        * '<S113>/Constant1'
                                        * '<S114>/Constant1'
                                        * '<S133>/Constant1'
                                        * '<S134>/Constant1'
                                        * '<S135>/Constant1'
                                        */
extern real32_T KeAP_nm_TrqCmdRateLimThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint8_T KeAP_pct_ObjConfidenceThd;/* Referenced by:
                                          * '<Root>/CVADAS_AutoPark_Main'
                                          * '<S25>/KeAP_pct_ObjConfidenceThd'
                                          */

/* Detected Object Confidence threshold */
extern real32_T KeAP_pct_PdlPosActThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Screen Chime Time Threshold */
extern uint8_T KeAP_pct_SpdBasedObjConfThd[2];/* Referenced by: '<S88>/Constant' */
extern uint16_T KeAP_s_BSMInterfaceCntTimeout;
                      /* Referenced by: '<S25>/KeAP_s_BSMInterfaceCntTimeout' */

/* BSM Interface timeout threshold */
extern uint16_T KeAP_s_BSMInterfaceCntTimeoutTest;
                     /* Referenced by: '<S25>/KeAP_s_BSMInterfaceCntTimeout1' */

/* BSM Interface timeout threshold */
extern uint16_T KeAP_s_CamHandshakeDur;
                             /* Referenced by: '<S25>/KeAP_s_CamHandshakeDur' */

/* Cam HMI Interface timeout threshold 100ms */
extern uint16_T KeAP_s_CamHandshakeDurTest;
                            /* Referenced by: '<S25>/KeAP_s_CamHandshakeDur1' */

/* Cam HMI Interface timeout threshold 100ms */
extern uint16_T KeAP_s_EPSInterfaceCntTimeout;
                      /* Referenced by: '<S25>/KeAP_s_EPSInterfaceCntTimeout' */

/* EPS Interface timeout threshold */
extern uint16_T KeAP_s_EPSInterfaceCntTimeoutTest;
                     /* Referenced by: '<S25>/KeAP_s_EPSInterfaceCntTimeout1' */

/* EPS Interface timeout threshold */
extern uint16_T KeAP_s_GearShiftReqWaitCnt;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern uint16_T KeAP_s_GearShiftWaitCntTimeout;
                     /* Referenced by: '<S25>/KeAP_s_GearShiftWaitCntTimeout' */

/* Gear Change/Shift request timeout threshold */
extern uint16_T KeAP_s_MaxStandstillTimeThd;
                        /* Referenced by: '<S25>/KeAP_s_MaxStandstillTimeThd' */

/* Maximum time threshold for vehicle to be in stand still position */
extern uint16_T KeAP_s_ObjInPathTimeoutDur;
                         /* Referenced by: '<S25>/KeAP_s_ObjInPathTimeoutDur' */

/* EPS Interface timeout threshold */
extern uint16_T KeAP_s_PausedPressBtnTimeoutDur;
                    /* Referenced by: '<S25>/KeAP_s_PausedPressBtnTimeoutDur' */

/* EPS Interface timeout threshold */
extern uint16_T KeAP_s_WaitEngineOnThd;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Engine On Time THreshold */
extern real32_T KeAP_sec_SampleTime;   /* Referenced by: '<S13>/Constant1' */
extern boolean_T KeCMbB_b_EnblOncObjDbnc;
                            /* Referenced by: '<S25>/KeCMbB_b_EnblOncObjDbnc' */
extern uint8_T KeHMI_e_ParkStyleTest;  /* Referenced by: '<S6>/Constant1' */

/* Tunable parameter to change value of Park Style input while Testing 0=None, 1=Rear_In, 2=Front_In */
extern uint8_T KePA_b_EnFeatPointSplitImp;/* Referenced by:
                                           * '<Root>/CVADAS_AutoPark_Main'
                                           * '<S88>/CalculateMinDistances1'
                                           */

/* Enable NeighboutHood Window */
extern uint8_T KePA_b_EnHeightFlagFrontSideArcs;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check for Side front arcs */
extern uint8_T KePA_b_EnHeightFlagRearSideArcs;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check for Side rear arc */
extern boolean_T KePA_b_EnbAppBlckg;   /* Referenced by: '<S3>/Constant' */
extern uint8_T KePA_b_IsDnnHeightLow;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Enable DNN Flag check */
extern int16_T KePA_cm_FrntWallDetectLatThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern int16_T KePA_cm_FrntWallDetectLongThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern int16_T KePA_cm_RearWallDetectLatThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern int16_T KePA_cm_RearWallDetectLongThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern real32_T KePA_cnt_FrntWallPntCntThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern real32_T KePA_cnt_RearWallPntCntThd;
                             /* Referenced by: '<S88>/CalculateMinDistances1' */
extern real32_T KeTOS_s_InTurnDbncTm;
                               /* Referenced by: '<S25>/KeTOS_s_InTurnDbncTm' */
extern real32_T KeTOS_s_StrDrvDbncTm;
                               /* Referenced by: '<S25>/KeTOS_s_StrDrvDbncTm' */
extern real32_T KeTOS_s_TurnExitDbncTm;
                             /* Referenced by: '<S25>/KeTOS_s_TurnExitDbncTm' */
extern real32_T KeTOS_x_InTurnThd;/* Referenced by: '<S25>/KeTOS_x_InTurnThd' */
extern real32_T KeTOS_x_TurnExitThd;
                                /* Referenced by: '<S25>/KeTOS_x_TurnExitThd' */
extern real32_T KsAP_k_DGainLUT_TD_55C[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_DGainLUT_TD_63C[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_DampingGainTD[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_IGainLUT_TD_55C[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_IGainLUT_TD_63C[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_IntegratorExtSatTD[4];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_PGainLUT_TD_55C[20];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_PGainLUT_TD_60C[20];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T KsAP_k_PGainLUT_TD_63C[20];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern real32_T MaAP_m_ParkSpot1FrntStreetX;/* synthesized block */
extern real32_T MaAP_m_ParkSpot1FrntStreetY;/* synthesized block */
extern real32_T MaAP_m_ParkSpot2FrntBorderX;/* synthesized block */
extern real32_T MaAP_m_ParkSpot2FrntBorderY;/* synthesized block */
extern real32_T MaAP_m_ParkSpot3RearBorderX;/* synthesized block */
extern real32_T MaAP_m_ParkSpot3RearBorderY;/* synthesized block */
extern real32_T MaAP_m_ParkSpot4RearStreetX;/* synthesized block */
extern real32_T MaAP_m_ParkSpot4RearStreetY;/* synthesized block */
extern TbNVM_ProxyCalibParam MbNVM_ProxyParam;/* '<S17>/Bus Creator2' */
extern boolean_T MeAP_b_ExternalFail;  /* '<S8>/Logical Operator' */
extern boolean_T MeAP_b_FPADisable;    /* '<S27>/Logical Operator' */
extern boolean_T MeAP_b_FPASwtStatus;  /* '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T MeAP_b_FPAVolDefMed;  /* '<S8>/Data Type Conversion116' */
extern boolean_T MeAP_b_FrntSenorBlock;/* '<S8>/Data Type Conversion132' */
extern boolean_T MeAP_b_FrntSenorFail; /* '<S8>/Data Type Conversion131' */
extern boolean_T MeAP_b_ObjInPath;     /* '<S87>/Compare' */
extern boolean_T MeAP_b_PARBActv4LOW;  /* '<S8>/Data Type Conversion120' */
extern boolean_T MeAP_b_PARBActvTrlr_27;/* '<S8>/Data Type Conversion119' */
extern boolean_T MeAP_b_PARBActvTrlr_29;/* '<S8>/Data Type Conversion7' */
extern boolean_T MeAP_b_PARBDiable;    /* '<S8>/Logical Operator3' */
extern boolean_T MeAP_b_PAVolDefMed;   /* '<S8>/Data Type Conversion115' */
extern boolean_T MeAP_b_PPPAActv4LOW;  /* '<S8>/Data Type Conversion123' */
extern boolean_T MeAP_b_PPPAActvTrlr;  /* '<S8>/Data Type Conversion122' */
extern boolean_T MeAP_b_PPPADefEng;    /* '<S8>/Data Type Conversion124' */
extern boolean_T MeAP_b_PPPADisable;   /* '<S8>/Logical Operator4' */
extern boolean_T MeAP_b_RPAActvTrlr_27;/* '<S8>/Data Type Conversion114' */
extern boolean_T MeAP_b_RPAActvTrlr_29;/* '<S8>/Data Type Conversion6' */
extern boolean_T MeAP_b_RPADisable;    /* '<S27>/Logical Operator2' */
extern boolean_T MeAP_b_RPASwtStatus;  /* '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T MeAP_b_RPAVolDefMed;  /* '<S8>/Data Type Conversion117' */
extern boolean_T MeAP_b_RearSenorBlock;/* '<S8>/Data Type Conversion134' */
extern boolean_T MeAP_b_RearSenorFail; /* '<S8>/Data Type Conversion133' */
extern boolean_T MeAP_b_ResetKM;       /* '<Root>/CVADAS_AutoPark_Main' */
extern boolean_T MeAP_b_SystemFail;    /* '<S8>/Data Type Conversion1' */
extern int16_T MeAP_cm_FrntCenterMinXDist;/* '<S92>/FC_Dbnc' */
extern int16_T MeAP_cm_FrntLeftMinXDist;/* '<S92>/FC_Dbnc1' */
extern int16_T MeAP_cm_FrntRightMinXDist;/* '<S92>/FC_Dbnc2' */
extern int16_T MeAP_cm_RearCenterMinXDist;/* '<S93>/RC_Dbnc' */
extern int16_T MeAP_cm_RearLeftMinXDist;/* '<S93>/RC_Dbnc1' */
extern int16_T MeAP_cm_RearRightMinXDist;/* '<S93>/RC_Dbnc2' */
extern TeAutoPark_e_AutoParkStatus MeAP_e_AutoParkStatus;/* '<Root>/CVADAS_AutoPark_Main' */
extern TeAP_e_AlgoState MeAutoPark_e_AlgoState;/* '<Root>/CVADAS_AutoPark_Main' */
extern real32_T Obj_DistTable[5];     /* Referenced by: '<S25>/Obj_DistTable' */
extern real32_T Overlap_Thrsld_Switch;
                              /* Referenced by: '<S25>/Overlap_Thrsld_Switch' */
extern TbAP_PAStateOut_t PAStateOut;   /* '<S209>/Bus Creator' */
extern real32_T RAEB_Envelope_Offset;
                               /* Referenced by: '<S25>/RAEB_Envelope_Offset' */
extern real32_T RAEB_Lateral_Distance_Notification;
                 /* Referenced by: '<S25>/RAEB_Lateral_Distance_Notification' */
extern real32_T RAEB_Minimum_Object_Heigh;
                          /* Referenced by: '<S25>/RAEB_Minimum_Object_Heigh' */

/* Minimum acceptable height of a object */
extern TbAP_RPAWarnOut_t RPAWarnOut;   /* '<S209>/Bus Creator2' */
extern uint8_T Reverse_Gr_num;       /* Referenced by: '<S25>/Reverse_Gr_num' */

/* Reverse Gear Number */
extern real32_T Steering_Angle_DeadZone_End;
                        /* Referenced by: '<S25>/Steering_Angle_DeadZone_End' */
extern real32_T Steering_Angle_DeadZone_Start;
                      /* Referenced by: '<S25>/Steering_Angle_DeadZone_Start' */
extern real32_T Straight_Driving_Thresold_rads2;
                    /* Referenced by: '<S25>/Straight_Driving_Thresold_rads2' */
extern TbAP_VCActuatorOut_t VCActuatorOut;/* '<S210>/Bus Creator1' */
extern real32_T dx_cm;                 /* '<S13>/Gain' */
extern real32_T keInpAdptr_e_StWhOffset;
                            /* Referenced by: '<S25>/keInpAdptr_e_StWhOffset' */

/* Wheel Offset */
extern real32_T keVehParam_e_StrWhlRatioBrkPnts[19];
                    /* Referenced by: '<S25>/keVehParam_e_StrWhlRatioBrkPnts' */

/* Vehicle Steering Wheel Ratio Break Points  */
extern real32_T keVehParam_e_VehSteerRatioTable[19];
                    /* Referenced by: '<S25>/keVehParam_e_VehSteerRatioTable' */
extern real32_T keVehParam_m_DistWhlBse;
                            /* Referenced by: '<S25>/keVehParam_m_DistWhlBse' */

/* Reply Type In */
extern real32_T sampling_time;        /* Referenced by: '<S25>/sampling_time' */

/* 10ms sampling time */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint8_T CeAP_k_CurbArrayInit[10];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_CurbLim_para[3];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_break_point_para[2];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_break_point_perp[2];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_fin_loc_para_out[2];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_p3_adj_perp[2];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T KeAP_str_profile_bigPS[34];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T step_size_coeff[6];
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */
extern const real32_T str_whl_ang_park_out;
                              /* Referenced by: '<Root>/CVADAS_AutoPark_Main' */

/* Real-time Model object */
extern RT_MODEL_DT24_CVADAS_AP_CodGen_T *const DT24_CVADAS_AP_CodGen_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'DT24_CVADAS_AP_CodGen'
 * '<S1>'   : 'DT24_CVADAS_AP_CodGen/CVADAS_Output_IPC'
 * '<S2>'   : 'DT24_CVADAS_AP_CodGen/IPC_Input'
 * '<S3>'   : 'DT24_CVADAS_AP_CodGen/Input_Adapter'
 * '<S4>'   : 'DT24_CVADAS_AP_CodGen/Model Info'
 * '<S5>'   : 'DT24_CVADAS_AP_CodGen/Output_Adapter'
 * '<S6>'   : 'DT24_CVADAS_AP_CodGen/Input_Adapter/DevlopmentTest1'
 * '<S7>'   : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Diag_InputProcessing'
 * '<S8>'   : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FID_InputProcessing1'
 * '<S9>'   : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing'
 * '<S10>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1'
 * '<S11>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing'
 * '<S12>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Inputs_Signal_Processing_VC'
 * '<S13>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/KM_InputProcessing'
 * '<S14>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/NVMStored_InputProcessing'
 * '<S15>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator'
 * '<S16>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ParkManoeuvreObjDet'
 * '<S17>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ProxyParam_InputProcessing'
 * '<S18>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/SnsrStatusUpdate'
 * '<S19>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6'
 * '<S20>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/THA_InputProcessing'
 * '<S21>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/TRSC_InputProcessing'
 * '<S22>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/USS_InputProcessing'
 * '<S23>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputPreProcessing'
 * '<S24>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing'
 * '<S25>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VrntTunParam'
 * '<S26>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FID_InputProcessing1/Dtc_B12852A'
 * '<S27>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FID_InputProcessing1/Subsystem'
 * '<S28>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FID_InputProcessing1/Dtc_B12852A/Compare To Constant'
 * '<S29>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FID_InputProcessing1/Dtc_B12852A/Compare To Constant1'
 * '<S30>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToHMI'
 * '<S31>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToVC'
 * '<S32>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/Parkable_slot'
 * '<S33>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToHMI/Enumerated Constant'
 * '<S34>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToHMI/Enumerated Constant9'
 * '<S35>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToHMI/Subsystem1'
 * '<S36>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToHMI/Subsystem2'
 * '<S37>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToVC/Enumerated Constant'
 * '<S38>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToVC/Enumerated Constant9'
 * '<S39>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/FPA_InputProcessing/FPAInfoToVC/Subsystem2'
 * '<S40>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage'
 * '<S41>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/SensorLocations'
 * '<S42>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet'
 * '<S43>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/CalcRadialDistToSensor'
 * '<S44>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/standstill'
 * '<S45>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/Chart1'
 * '<S46>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1'
 * '<S47>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FIL_Blk'
 * '<S48>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FIR_Blk'
 * '<S49>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FLAlertCount'
 * '<S50>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FOL_Blk'
 * '<S51>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FOR_Blk'
 * '<S52>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FRAlertCount'
 * '<S53>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FSL_Blk'
 * '<S54>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FSR_Blk'
 * '<S55>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/FrontAlertCount'
 * '<S56>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RIL_Blk'
 * '<S57>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RIR_Blk'
 * '<S58>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RLAlertCount'
 * '<S59>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/ROL_Blk'
 * '<S60>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/ROR_Blk'
 * '<S61>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RRAlertCount'
 * '<S62>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RSL_Blk'
 * '<S63>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RSR_Blk'
 * '<S64>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/BlockageDet/CheckSnsBlck1/RearAlertCount'
 * '<S65>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/standstill/Enumerated Constant3'
 * '<S66>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Feature_BlockageDetectionAlgo1/DetectBlockage/standstill/Enumerated Constant4'
 * '<S67>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant'
 * '<S68>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant1'
 * '<S69>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant10'
 * '<S70>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant11'
 * '<S71>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant12'
 * '<S72>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant13'
 * '<S73>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant14'
 * '<S74>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant15'
 * '<S75>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant16'
 * '<S76>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant17'
 * '<S77>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant18'
 * '<S78>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant19'
 * '<S79>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant2'
 * '<S80>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant3'
 * '<S81>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant4'
 * '<S82>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant5'
 * '<S83>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant6'
 * '<S84>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant7'
 * '<S85>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant8'
 * '<S86>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/HMI_InputProcessing/Enumerated Constant9'
 * '<S87>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Inputs_Signal_Processing_VC/Compare To Constant'
 * '<S88>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance'
 * '<S89>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/StandstillTimer'
 * '<S90>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/standstill'
 * '<S91>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1'
 * '<S92>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist'
 * '<S93>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist'
 * '<S94>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist'
 * '<S95>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/VehicleContourXY'
 * '<S96>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/CalculateDistance.DivisionWithZeroProtection'
 * '<S97>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/GetDiagonalCenterRegion'
 * '<S98>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/InitalisePointData'
 * '<S99>'  : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/NeighbourHoodCheck'
 * '<S100>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/UpdateDistNoDetection'
 * '<S101>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/CalculateDistance.DivisionWithZeroProtection/DivWithZeroProtection'
 * '<S102>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/GetDiagonalCenterRegion/CalcSideRegLongThresh'
 * '<S103>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/GetDiagonalCenterRegion/CalcSideRegLongThresh/DivWithZeroProtection'
 * '<S104>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/CalculateMinDistances1/NeighbourHoodCheck/NeighbourCheck'
 * '<S105>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FC_Dbnc'
 * '<S106>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FC_Dbnc1'
 * '<S107>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FC_Dbnc2'
 * '<S108>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg'
 * '<S109>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg1'
 * '<S110>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg'
 * '<S111>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontRightDistAvg'
 * '<S112>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FC_DBNC'
 * '<S113>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FL_DBNC'
 * '<S114>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FR_DBNC'
 * '<S115>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg/ArcDistOffset'
 * '<S116>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg/Compare To Constant'
 * '<S117>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg/Compare To Constant1'
 * '<S118>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg1/ArcDistOffset'
 * '<S119>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg1/Compare To Constant1'
 * '<S120>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontCenterDistAvg1/Compare To Constant2'
 * '<S121>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg/ArcDistOffset'
 * '<S122>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg/Compare To Constant'
 * '<S123>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontLeftDistAvg/Compare To Constant1'
 * '<S124>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontRightDistAvg/ArcDistOffset'
 * '<S125>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontRightDistAvg/Compare To Constant'
 * '<S126>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/FrontRightDistAvg/Compare To Constant1'
 * '<S127>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FC_DBNC/DistDbnc'
 * '<S128>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FL_DBNC/DistDbnc'
 * '<S129>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/FromtMinDist/PA_FR_DBNC/DistDbnc'
 * '<S130>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontCenterDistAvg'
 * '<S131>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontLeftDistAvg'
 * '<S132>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontRightDistAvg'
 * '<S133>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RC_DBNC'
 * '<S134>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RL_DBNC'
 * '<S135>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RR_DBNC'
 * '<S136>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RC_Dbnc'
 * '<S137>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RC_Dbnc1'
 * '<S138>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RC_Dbnc2'
 * '<S139>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RearCenterDistAvg1'
 * '<S140>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontCenterDistAvg/ArcDistOffset'
 * '<S141>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontCenterDistAvg/Compare To Constant'
 * '<S142>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontCenterDistAvg/Compare To Constant1'
 * '<S143>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontLeftDistAvg/ArcDistOffset'
 * '<S144>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontLeftDistAvg/Compare To Constant'
 * '<S145>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontLeftDistAvg/Compare To Constant1'
 * '<S146>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontRightDistAvg/ArcDistOffset'
 * '<S147>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontRightDistAvg/Compare To Constant'
 * '<S148>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/FrontRightDistAvg/Compare To Constant1'
 * '<S149>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RC_DBNC/DistDbnc'
 * '<S150>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RL_DBNC/DistDbnc'
 * '<S151>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/PA_RR_DBNC/DistDbnc'
 * '<S152>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RearCenterDistAvg1/ArcDistOffset'
 * '<S153>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RearCenterDistAvg1/Compare To Constant1'
 * '<S154>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/RearMinDist/RearCenterDistAvg1/Compare To Constant2'
 * '<S155>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist'
 * '<S156>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist1'
 * '<S157>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist2'
 * '<S158>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist3'
 * '<S159>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist4'
 * '<S160>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist5'
 * '<S161>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist6'
 * '<S162>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/CalcMinDistance/SuppArcMinDist/SuppArcMinDist7'
 * '<S163>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/StandstillTimer/OffTimer'
 * '<S164>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/StandstillTimer/OffTimer/DetectIncChange'
 * '<S165>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/standstill/Enumerated Constant3'
 * '<S166>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/ObjectMinDistanceCalculator/standstill/Enumerated Constant4'
 * '<S167>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/Subsystem'
 * '<S168>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/TimerForVehKey'
 * '<S169>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/standstill'
 * '<S170>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/Subsystem/Enumerated Constant2'
 * '<S171>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/TimerForVehKey/OffTimer'
 * '<S172>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/TimerForVehKey/OffTimer/RisingEdge'
 * '<S173>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/standstill/Enumerated Constant3'
 * '<S174>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/Subsystem6/standstill/Enumerated Constant4'
 * '<S175>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering'
 * '<S176>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering'
 * '<S177>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering/Enumerated Constant'
 * '<S178>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering/Enumerated Constant1'
 * '<S179>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering/Enumerated Constant2'
 * '<S180>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering/Enumerated Constant3'
 * '<S181>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/EngagedGearFiltering/Enumerated Constant4'
 * '<S182>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1'
 * '<S183>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2'
 * '<S184>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1/Enumerated Constant'
 * '<S185>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1/Enumerated Constant1'
 * '<S186>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1/Enumerated Constant2'
 * '<S187>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1/Enumerated Constant3'
 * '<S188>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering1/Enumerated Constant4'
 * '<S189>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant1'
 * '<S190>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant10'
 * '<S191>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant11'
 * '<S192>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant12'
 * '<S193>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant13'
 * '<S194>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant14'
 * '<S195>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant2'
 * '<S196>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant3'
 * '<S197>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant4'
 * '<S198>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant5'
 * '<S199>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant6'
 * '<S200>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant7'
 * '<S201>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant8'
 * '<S202>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/Enumerated Constant9'
 * '<S203>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/OffTimer'
 * '<S204>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/OffTimer1'
 * '<S205>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/OffTimer/RisingEdge'
 * '<S206>' : 'DT24_CVADAS_AP_CodGen/Input_Adapter/VCAN_InputProcessing/TargetGearFiltering/TargetGearFiltering2/OffTimer1/RisingEdge'
 * '<S207>' : 'DT24_CVADAS_AP_CodGen/Output_Adapter/AP_Debug'
 * '<S208>' : 'DT24_CVADAS_AP_CodGen/Output_Adapter/OutputAdapter_APSM'
 * '<S209>' : 'DT24_CVADAS_AP_CodGen/Output_Adapter/Output_Adapter_APA'
 * '<S210>' : 'DT24_CVADAS_AP_CodGen/Output_Adapter/Output_Adapter_VC'
 */
#endif                                 /* RTW_HEADER_DT24_CVADAS_AP_CodGen_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
