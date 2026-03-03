/*
 * File: DT24_CVADAS_AutoPark_Func.h
 *
 * Code generated for Simulink model 'DT24_CVADAS_AutoPark_Func'.
 *
 * Model version                  : 1.340
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:12:56 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DT24_CVADAS_AutoPark_Func_h_
#define RTW_HEADER_DT24_CVADAS_AutoPark_Func_h_
#ifndef DT24_CVADAS_AutoPark_Func_COMMON_INCLUDES_
# define DT24_CVADAS_AutoPark_Func_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                          /* DT24_CVADAS_AutoPark_Func_COMMON_INCLUDES_ */

#include "DT24_CVADAS_AutoPark_Func_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_
#define SWC_AP_StateMachine_MDLREF_HIDE_CHILD_
#include "SWC_AP_StateMachine.h"
#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_
#define SWC_APA_MDLREF_HIDE_CHILD_
#include "SWC_APA.h"
#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_
#define SWC_VC_MDLREF_HIDE_CHILD_
#include "SWC_VC.h"
#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define CeAP_cm_CurbLatchDist          170.0F                    /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_DefaultRearDistInt16   1023                      /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_EnRaebDistHoldThsd     60                        /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_FrntSideArc1Adj        10                        /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_FrntSideArc2Adj        5                         /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_SideArc1Adj            5                         /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_cm_SideArc2Adj            0                         /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_deg_MinSteerCurvature     10.0F                     /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_CurbDbnc                20U                       /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_SingleNegOne            -1.0F                     /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_SingleOne               1.0F                      /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_SingleTwo               2.0F                      /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_SingleZero              2.0F                      /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_Uint8One                1U                        /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_k_Uint8Zero               0U                        /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_ms_RaebThsdHold1          100U                      /* Referenced by: '<S1>/APA_Controller' */
#define CeAP_ms_RaebThsdHold2          200U                      /* Referenced by: '<S1>/APA_Controller' */
#define FB_PS_min_length               5.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define FB_PS_min_width                2.18F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_FrontOffset               0.2F                      /* Referenced by: '<S1>/VC_Controller' */

/* Offset of the front of the vehicle from the final pose */
#define KeAP_Kf_para                   0.7F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_Kf_perp                   0.7F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_Kf_perp_single_sweep      0.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_Ks                        1.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_PP_RES_DIST_TRAVEL        0.01F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_Phi_lim_perp              50.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_Phi_resolution_perp       3.0F                      /* Referenced by: '<S1>/VC_Controller' */

/* Resolution of path heading (Deg) */
#define KeAP_StrRateLim_para           100.0F                    /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_StrRateLim_perp           100.0F                    /* Referenced by: '<S1>/VC_Controller' */

/* Steering rate limit during a perpendicular maneuver */
#define KeAP_V_max_para                1.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_V_max_perp                2.5F                      /* Referenced by: '<S1>/VC_Controller' */

/* Max velocity during perpendicular maneuver (m/s) */
#define KeAP_ang_threshold_regen       1.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_app_ctrl_min_dist_x_para  1.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_app_ctrl_min_dist_x_perp  1.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_aux_alpha                 2.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_aux_turn_para_regen       4.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_control_point_3_x_adjust_m -0.2F                    /* Referenced by: '<S1>/VC_Controller' */

/* Adjustment to x position of control point 3 (m) */
#define KeAP_control_point_3_y_step_m  -0.1F                     /* Referenced by: '<S1>/VC_Controller' */

/* Adjustment to y position of control point 3 (m) */
#define KeAP_curb_over_Y_dir_para      0.25F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_curvature_coeff_perp      0.6667F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_delta_s_clothoid_para     0.1F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_delta_s_clothoid_perp     0.08F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_delta_s_no_str_para       0.09F                     /* Referenced by: '<S1>/VC_Controller' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_delta_s_no_str_perp       0.07F                     /* Referenced by: '<S1>/VC_Controller' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_delta_s_nose_in_regen     0.1F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_delta_s_para              0.05F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_delta_s_perp              0.05F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_k_RaebCruiseAgeThd        6U                        /* Referenced by: '<S1>/APA_Controller' */
#define KeAP_lim_perp_PS4              0.1F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_maxCurvatureTypeOne       0.22845903F               /* Referenced by: '<S1>/VC_Controller' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeThree     0.215264142F              /* Referenced by: '<S1>/VC_Controller' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeTwo       0.228461951F              /* Referenced by: '<S1>/VC_Controller' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_max_num_sweeps            7U                        /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_n_para                    15U                       /* Referenced by: '<S1>/VC_Controller' */

/* Number of waypoints in each parallel planner segment */
#define KeAP_n_perp                    20U                       /* Referenced by: '<S1>/VC_Controller' */

/* Number of waypoints in each perpendicular planner segment. ALERT n_per_segment acts as an upper bound for this */
#define KeAP_num_clothoid_waypoints_para_mediumPS 2U             /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_num_clothoid_waypoints_para_smallPS 2U              /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_num_points_no_str_para    16U                       /* Referenced by: '<S1>/VC_Controller' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_num_points_no_str_perp    10U                       /* Referenced by: '<S1>/VC_Controller' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_p3_pos_lim_perp           2.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_para_control_point_2_x_step_m -0.3F                 /* Referenced by: '<S1>/VC_Controller' */

/* Step size for adjusting the X position of the second parallel control point (m) */
#define KeAP_para_final_curb_offset    -0.16F                    /* Referenced by: '<S1>/VC_Controller' */

/* Offset of the final position of the vehicle from the curb (m) */
#define KeAP_park_out_nose_in_angle    35.0F                     /* Referenced by: '<S1>/VC_Controller' */

/* Angle at gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_X 1.5F              /* Referenced by: '<S1>/VC_Controller' */

/* X offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_Y 4.5F              /* Referenced by: '<S1>/VC_Controller' */

/* Y offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_X 3.0F              /* Referenced by: '<S1>/VC_Controller' */

/* X offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_big 2.0F          /* Referenced by: '<S1>/VC_Controller' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_small 2.0F        /* Referenced by: '<S1>/VC_Controller' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_pct_CurbConfThd           78U                       /* Referenced by: '<S1>/APA_Controller' */
#define KeAP_safety_lim_fb_f           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_fb_r           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_fb_s           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_nz_f           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_nz_r           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_nz_s           0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_para_f         0.1F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_para_r         0.1F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_para_s         0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_perp_f         0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_perp_r         0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_perp_s         0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_safety_lim_single_sweep_perp 0.05F                  /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_segment_3_length_perp_m   2.0F                      /* Referenced by: '<S1>/VC_Controller' */

/* Length of segment 3 (m) in a perpendicular back-in 3 sweep park */
#define KeAP_single_sweep_control_point_2_y_offset -1.9F         /* Referenced by: '<S1>/VC_Controller' */

/* The y offset of the second control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_x_offset 0.65F         /* Referenced by: '<S1>/VC_Controller' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_y_offset -1.6F         /* Referenced by: '<S1>/VC_Controller' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_perp_width_lim 2.95F                   /* Referenced by: '<S1>/VC_Controller' */

/* The minimum width of a parking space that allows a single sweep park */
#define KeAP_single_sweep_start_min_lon_dist_m 6.8F              /* Referenced by: '<S1>/VC_Controller' */

/* The minimum longitudinal distance of the vehicle origin from the C1 corner of the parking spot to perform a single sweep (m) */
#define KeAP_str_wheel_ang_perp        45.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_mediumPS_D 22.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_mediumPS_R 10.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_mediumPS_R_tail 33.0F              /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_smallPS_D2 25.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_smallPS_D4 15.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_smallPS_R3 25.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_smallPS_R5 15.0F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_para_smallPS_R_tail 33.0F               /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_str_whl_ang_regen         33.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_straight_line_perp_park_out 2.5F                    /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_sweep_length_lim_regen    0.15F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_turn_radius_park_out_perp 5.25F                     /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_turn_radius_park_out_perp_big 5.25F                 /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_turn_radius_single_sweep_perp 4.5F                  /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_vecLen_coeff_para         0.4437F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_vecLen_coeff_perp         0.4437F                   /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_vecLen_coeff_perp_single_sweep_Phi 0.0323F          /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_vecLen_coeff_perp_single_sweep_XY 0.5547F           /* Referenced by: '<S1>/VC_Controller' */
#define KeAP_yaw_control_point_3_perp_deg 25.0F                  /* Referenced by: '<S1>/VC_Controller' */

/* Heading (deg) of the vehicle with respect to the parking spot at the third control point of a perpendiciular rear park in */
#define KePA_cm_RearCurbDetectLatThd   15                        /* Referenced by: '<S1>/APA_Controller' */
#define KePA_cm_RearCurbDetectLongThd  10                        /* Referenced by: '<S1>/APA_Controller' */
#define KePA_cnt_RearCurbPntCntThd     3U                        /* Referenced by: '<S1>/APA_Controller' */
#define Ke_AP_deg_MaxWheelAngle        40.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define Kf_fb                          0.7F                      /* Referenced by: '<S1>/VC_Controller' */
#define PP_PS_min_length               5.4F                      /* Referenced by: '<S1>/VC_Controller' */
#define PP_PS_min_width                2.18F                     /* Referenced by: '<S1>/VC_Controller' */
#define Rs                             100.0F                    /* Referenced by: '<S1>/VC_Controller' */
#define StrRateLim_fb                  47.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define V_max_fb                       2.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define Y_resolution_para              0.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define app_ctrl_min_dist_x_fb         1.5F                      /* Referenced by: '<S1>/VC_Controller' */
#define aux_turn_para                  5.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define break_point_fb                 6.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define delta_s_fb                     0.05F                     /* Referenced by: '<S1>/VC_Controller' */
#define delta_s_no_str_fb              0.07F                     /* Referenced by: '<S1>/VC_Controller' */
#define length_regen_fb                5.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define minRadiusTypeTwo               4.37709665F               /* Referenced by: '<S1>/VC_Controller' */
#define minRadius_TypeOne              4.37715244F               /* Referenced by: '<S1>/VC_Controller' */
#define minRadiustypeThree             4.64545536F               /* Referenced by: '<S1>/VC_Controller' */
#define n_fb                           15U                       /* Referenced by: '<S1>/VC_Controller' */
#define num_arc_waypoints_para_bigPS   27U                       /* Referenced by: '<S1>/VC_Controller' */
#define num_clothoid_waypoints_para_bigPS 2U                     /* Referenced by: '<S1>/VC_Controller' */
#define num_points_no_str_fb           10U                       /* Referenced by: '<S1>/VC_Controller' */
#define p3_ang_lim_perp                0.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define str_whl_ang_para_bigPS_R       33.0F                     /* Referenced by: '<S1>/VC_Controller' */
#define straight_line_fb               1.0F                      /* Referenced by: '<S1>/VC_Controller' */
#define vecLen_coeff_fb                0.4437F                   /* Referenced by: '<S1>/VC_Controller' */

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'DT24_CVADAS_AutoPark_Func' */
#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay6;                 /* '<S1>/Unit Delay6' */
  real32_T UnitDelay7;                 /* '<S1>/Unit Delay7' */
  real32_T MeAP_s_FaultWaitTime;       /* '<S1>/StateMachine_Controller' */
  real32_T UnitDelay8;                 /* '<S1>/Unit Delay8' */
  TeAutoPark_e_ScanDir StateMachine_Controller_o10;/* '<S1>/StateMachine_Controller' */
  TeAutoPark_e_GearCmd UnitDelay1;     /* '<S1>/Unit Delay1' */
  TeAutoPark_e_GearCmd MeAP_e_GearCmd_j;/* '<S1>/VC_Controller' */
  TeAutoPark_e_GearCmd StateMachine_Controller_o12;/* '<S1>/StateMachine_Controller' */
  TeAutoPark_e_ChimeReq StateMachine_Controller_o9;/* '<S1>/StateMachine_Controller' */
  TeAP_e_RearSnsrStatus IeAP_e_RearSnsrStatus;/* '<S1>/StateMachine_Controller' */
  TeAP_e_PAMOffStatus2BT UnitDelay5;   /* '<S1>/Unit Delay5' */
  TeAP_e_FrntSnsrStatus IeAP_e_FrntSnsrStatus;/* '<S1>/StateMachine_Controller' */
  uint8_T IeAP_e_MnvActvStat;          /* '<S1>/StateMachine_Controller' */
  uint8_T IeAP_e_AbortCon;             /* '<S1>/StateMachine_Controller' */
  uint8_T IeAP_e_SemiParkSysSts;       /* '<S1>/StateMachine_Controller' */
  uint8_T IeAP_e_DIDHMICode;           /* '<S1>/StateMachine_Controller' */
  uint8_T IeAP_cnt_CurrentVehSweep;    /* '<S1>/VC_Controller' */
  boolean_T UnitDelay;                 /* '<S1>/Unit Delay' */
  boolean_T UnitDelay2;                /* '<S1>/Unit Delay2' */
  boolean_T UnitDelay3;                /* '<S1>/Unit Delay3' */
  boolean_T UnitDelay4;                /* '<S1>/Unit Delay4' */
  boolean_T MeAP_b_VCActive;           /* '<S1>/StateMachine_Controller' */
  boolean_T MeAP_b_ParkOut;            /* '<S1>/StateMachine_Controller' */
  boolean_T MeAP_b_ResetVCKM;          /* '<S1>/StateMachine_Controller' */
  boolean_T MeAP_b_StandStill;         /* '<S1>/StateMachine_Controller' */
  boolean_T APA_Controller_o33;        /* '<S1>/APA_Controller' */
  boolean_T APA_Controller_o36;        /* '<S1>/APA_Controller' */
  boolean_T StateMachine_Controller_o4;/* '<S1>/StateMachine_Controller' */
  boolean_T StateMachine_Controller_o5;/* '<S1>/StateMachine_Controller' */
  boolean_T StateMachine_Controller_o6;/* '<S1>/StateMachine_Controller' */
  boolean_T StateMachine_Controller_o7;/* '<S1>/StateMachine_Controller' */
  boolean_T StateMachine_Controller_o8;/* '<S1>/StateMachine_Controller' */
  boolean_T StateMachine_Controller_o11;/* '<S1>/StateMachine_Controller' */
  boolean_T IeAP_b_AutoParkOverride;   /* '<S1>/StateMachine_Controller' */
  boolean_T MeAP_b_SensorFltSts;       /* '<S1>/StateMachine_Controller' */
  boolean_T MeAP_b_ParkSlotDetctSts;   /* '<S1>/StateMachine_Controller' */
  boolean_T IeAP_b_MnvPosOk;           /* '<S1>/VC_Controller' */
} B_DT24_CVADAS_AutoPark_Func_c_T;

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'DT24_CVADAS_AutoPark_Func' */
#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T UnitDelay6_DSTATE;          /* '<S1>/Unit Delay6' */
  real32_T UnitDelay7_DSTATE;          /* '<S1>/Unit Delay7' */
  real32_T UnitDelay8_DSTATE;          /* '<S1>/Unit Delay8' */
  TeAP_e_PAMOffStatus2BT UnitDelay5_DSTATE;/* '<S1>/Unit Delay5' */
  TeAutoPark_e_GearCmd UnitDelay1_DSTATE;/* '<S1>/Unit Delay1' */
  boolean_T UnitDelay_DSTATE;          /* '<S1>/Unit Delay' */
  boolean_T UnitDelay2_DSTATE;         /* '<S1>/Unit Delay2' */
  boolean_T UnitDelay3_DSTATE;         /* '<S1>/Unit Delay3' */
  boolean_T UnitDelay4_DSTATE;         /* '<S1>/Unit Delay4' */
} DW_DT24_CVADAS_AutoPark_Func_f_T;

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_DT24_CVADAS_AutoPark_Func_T {
  const char_T **errorStatus;
};

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_DT24_CVADAS_AutoPark_Func_T rtm;
} MdlrefDW_DT24_CVADAS_AutoPark_Func_T;

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

extern void DT24_CVADAS_AutoPark_Func_Init(void);
extern void DT24_CVADAS_AutoPark_Func_Start(void);
extern void DT24_CVADAS_AutoPark_Func_Disable(void);
extern void DT24_CVADAS_AutoPark_Func(const TbVBIA_VehState_AP
  *rtu_IbVBII_VehState_LowSpd, const TbNVM_ReadParam *rtu_MbNVM_ReadParam, const
  TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const TbUSS_DiagFlag
  *rtu_MbUSS_DiagFlag, const IJobFPAOutput_t *rtu_LwSpd_FPA_Output, const
  TeTHA_e_RearBrkSupprInfo *rtu_MeTHA_e_RearBrkSupprInfo, const int16_T
  *rtu_MeAP_I_WhlPosRR, const int16_T *rtu_MeAP_I_WhlPosRL, const uint8_T
  *rtu_MeAP_I_GearRpt, const US_S_PointMapOutputBuff_t *rtu_USS_2DPointMap,
  const real32_T *rtu_MeAP_cm_CDminDist, const TeTRSC_e_TRSCSts
  *rtu_IeTRSC_e_TRSCSts, const boolean_T *rtu_IeVBII_b_ActvParkMode, const
  boolean_T *rtu_MeAP_b_ObjInPath, const boolean_T
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
  *rtu_IbFID_PARB_MeAP_b_PARBDiable, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActvTrlr, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPAActv4LOW, const boolean_T
  *rtu_IbFID_PPPA_MeAP_b_PPPADisable, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_UsrSlotSelStatus, const TeAutoPark_e_ParkStyle *
  rtu_IbHMI_HMIInfoToAP_IeHMI_e_ParkStyle, const TeHMI_e_UsrParkOutSide
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrParkOutSideSel, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_HMIHandshake, const boolean_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_b_BackBtnPsd, const TeAP_e_UsrPPPAManeuverSel
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_UsrPPPAManeuverSel, const ParkingSlotType_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotType, const SlotSide_t
  *rtu_IbHMI_HMIInfoToAP_IeHMI_e_SelectedMnvSlotSide, const uint64m_T
  *rtu_IbHMI_HMIInfoToAP_IeHMI_cnt_FressnessCounter, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_degC_OperatingTempThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_EnblHysThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_FrntWarnMaxSpdThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOffThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_PSDOnThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_KeAP_kph_RearWarnMaxSpdThd, const real32_T
  *rtu_IbAP_InputVrntTunParam_K_e_RAEB_VehicleWidth, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_ChimeVolChgAlert, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_FrntChimeDisTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_LEDBlinkTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_VehKeyOnTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_TimeStep, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SwtStuckTimeThd, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_BSMInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_EPSInterfaceCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_GearShiftWaitCntTimeout, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_ObjInPathTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_PausedPressBtnTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SeekPhaseTimeoutDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_s_SpdExceedDur, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_SPMBlinkLEDDur, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone1, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone2, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone3, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone4, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone5, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_DistZone6, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj, const int16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_AutoParkEn, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_FPAEn, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithBrk, const boolean_T
  *rtu_IbAP_InputVrntTunParam_KeAP_b_RPAwithSurroundView, const uint16_T
  *rtu_IbAP_InputVrntTunParam_KeAP_cnt_EngagedFullWaitCnt, const boolean_T
  *rtu_MbDiag_TestModeForceOn, const int16_T *rtu_MeAP_cm_FrntCenterMinXDist,
  const int16_T *rtu_MeAP_cm_FrntLeftMinXDist, const int16_T
  *rtu_MeAP_cm_FrntRightMinXDist, const int16_T *rtu_MeAP_cm_RearCenterMinXDist,
  const int16_T *rtu_MeAP_cm_RearLeftMinXDist, const int16_T
  *rtu_MeAP_cm_RearRightMinXDist, const boolean_T *rtu_MeAP_b_ObjPrestFC, const
  boolean_T *rtu_MeAP_b_ObjPrestRC, const int16_T *rtu_IeVBII_deg_StrWhlSpd,
  const boolean_T *rtu_MbDiag_PlantModeOn, const TeTRSC_e_TRSCPopupDispInfo
  *rtu_IeTRSC_e_TRSCPopupDispInfo, const uint8_T
  *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFront, const
  uint8_T *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFL, const
  uint8_T *rtu_MeAP_b_HighPointsPresentFront_MeAP_b_HighPointsPresentFR, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRear, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRL, const
  uint8_T *rtu_MeAP_b_HighPointsPresentRear_MeAP_b_HighPointsPresentRR, const
  uint8_T *rtu_MeAP_b_IsWall, const int16_T *rtu_MeAP_cm_WallFrntCenterDist,
  const int16_T *rtu_MeAP_cm_WallRearCenterDist, boolean_T *rty_MeAP_b_FPAStatus,
  boolean_T *rty_MeAP_b_RPAStatus, TeAP_e_ParkAssistStatus
  *rty_MeAP_e_ParkAssistStatus, TeAutoPark_e_ScanDir *rty_IeAutoPark_e_ScanDir,
  TeAP_e_PAMSystemFault *rty_IeAP_e_PAMSystemFault, TeAP_e_PAMOffStatus2BT
  *rty_MeAP_e_PAMOffStatus2BT, TeAP_e_FrntSnsrStatus *rty_MeAP_e_FrntSnsrStatus,
  TeAP_e_RearSnsrStatus *rty_IeAP_e_RearSnsrStatus, boolean_T
  *rty_MeAP_b_DisableDiag, boolean_T *rty_MeAP_b_AutoParkEnblSwtStuckStatus,
  TeAP_e_InterfaceBSM *rty_IeAP_e_InterfaceBSM, TeAP_e_SPMLatCtrlReqSts
  *rty_IeAP_e_SPMLatCtrlReqSts, TeAP_e_ParKMnvrActv *rty_IeAP_e_ParKMnvrActv,
  TeAP_e_HMIPopUp *rty_MeAP_e_HMIPopUp, boolean_T *rty_MeAP_b_SystemFail,
  boolean_T *rty_MeAP_b_ExternalFail, boolean_T *rty_MeAP_b_RPAwithBrkDisable,
  boolean_T *rty_MeAP_b_RPADisable, boolean_T *rty_MeAP_b_FPADisable,
  TeAP_e_PAMLedCtrlStatus *rty_IeAP_e_SPMLedSts, boolean_T
  *rty_IeAP_b_SPMFailSts, boolean_T *rty_IeAP_b_SPMFaultSts, TeAP_e_SPMActvStat *
  rty_IeAP_e_SPMActvStat, boolean_T *rty_IeAP_b_VehMnvrDirSPM, boolean_T
  *rty_IeAP_b_StandstillReq, boolean_T *rty_MeAP_b_VCOpPaused,
  TeAP_e_GearShiftReq *rty_IeAP_e_GearShiftReq, TeAP_e_Alert
  *rty_MeAP_e_AlertCHF, TeAP_e_Alert *rty_MeAP_e_AlertLHF, TeAP_e_Alert
  *rty_MeAP_e_AlertRHF, TeAP_e_Alert *rty_MeAP_e_AlertCHR, TeAP_e_Alert
  *rty_MeAP_e_AlertLHR, TeAP_e_Alert *rty_MeAP_e_AlertRHR,
  TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHF, TeAP_e_GraphicFlshRate
  *rty_MeAP_e_GraphicLHF, TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHF,
  TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicCHR, TeAP_e_GraphicFlshRate
  *rty_MeAP_e_GraphicLHR, TeAP_e_GraphicFlshRate *rty_MeAP_e_GraphicRHR,
  boolean_T *rty_MeAP_b_ChimeActvLHF, boolean_T *rty_MeAP_b_ChimeActvRHF,
  boolean_T *rty_MeAP_b_ChimeActvLHR, boolean_T *rty_MeAP_b_ChimeActvRHR,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRate, TeAP_e_PAMVolume
  *rty_MeAP_e_PAMVolume, TeAP_e_PAMLedCtrlStatus
  *rty_MeAP_e_FrntPAMLedCtrlStatus, TeAP_e_PAMLedCtrlStatus
  *rty_MeAP_e_RearPAMLedCtrlStatus, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTyp,
  TeAP_e_PAMPopUpReq *rty_MeAP_e_PAMPopUpReq, boolean_T
  *rty_MeAP_b_PAMBrkReqStatus, real32_T *rty_MeAP_cm_RearDist, boolean_T
  *rty_MeAP_b_PAMStopCtrlStatus, real32_T *rty_MeAP_deg_StrCmd, real32_T
  *rty_MeAP_a_BrkCmd, real32_T *rty_MeAP_a_ThrtlCmd, int32_T
  *rty_IeAP_e_TurnIndicReq, real32_T *rty_IeAP_nm_StrwTrqReq, real32_T
  *rty_IeAP_a_DecelMax, real32_T *rty_IeAP_a_DecelMin, real32_T
  *rty_IeAP_a_JerkDecelMax, real32_T *rty_IeAP_a_JerkDecelMin, real32_T
  *rty_IeAP_a_AcclMin, real32_T *rty_IeAP_a_AcclMax, real32_T
  *rty_IeAP_da_JerkAcclMax, real32_T *rty_IeAP_da_JerkAcclMin, boolean_T
  *rty_IeAP_b_StandstillReq1, real32_T *rty_IeAP_cm_TrgtDist, boolean_T
  *rty_MeAP_b_ManeuverAbort, boolean_T *rty_MeAP_b_ManeuverSuccess, int8_T
  *rty_MeAP_e_PP_state, real32_T *rty_MeAP_e_Park_state, real32_T
  rty_MaAP_m_PlannerWayPointsX[250], real32_T rty_MaAP_m_PlannerWayPointsY[250],
  boolean_T *rty_MeAP_b_PosMet, boolean_T *rty_MeAP_b_SteerActionReq, real32_T
  *rty_IeAP_kph_TrgtVehSpd, TeAP_e_PAMVolSig *rty_MeAP_e_PAMVolSigSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqLHFSVM, boolean_T *rty_MeAP_b_ChimeActvReqLHRSVM,
  boolean_T *rty_MeAP_b_ChimeActvReqRHFSVM, boolean_T
  *rty_MeAP_b_ChimeActvReqRHRSVM, TeAP_e_PAMChimeTyp *rty_MeAP_e_PAMChimeTypSVM,
  TeAP_e_PAMChimeRepnRate *rty_MeAP_e_PAMChimeRepnRateSVM, TeAP_e_USSSupplyPwrSt
  *rty_MeAP_e_USSSupplyPwrSt, TeAP_e_USSSystemMode *rty_MeAP_e_USSSystemMode,
  TeAP_e_USSSystemState *rty_MeAP_e_USSSystemState, uint8_T
  *rty_MeAP_e_USSFiringMode, boolean_T *rty_MeAP_b_USSReInit, boolean_T
  *rty_MeAP_b_ScanSts, uint16_T *rty_IbAP_SMDebugOut_MeAP_cnt_StateDebugVar,
  uint16_T *rty_IbAP_SMDebugOut_MeAP_cnt_TransDebugVar, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VCOpPaused, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_EPSInterfaceTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_GearShiftWaitTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_CamHandshakeTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_ObjInPathTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_PausedPressBtnTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_SeekSpdExceedTimeout, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_APInitSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_DriverOverride, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_StandStill, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_BSMHandshakeActv, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_VehCndSts, boolean_T
  *rty_IbAP_SMDebugOut_MeAP_b_FeatureEnbl, real32_T *rty_IbVC_DebugOut_X_MABx,
  real32_T *rty_IbVC_DebugOut_Y_MABx, real32_T *rty_IbVC_DebugOut_heading_MABx,
  real32_T *rty_IbVC_DebugOut_Str_Trq_CMD, real32_T
  *rty_IbVC_DebugOut_VC_RemainingDist, real32_T *rty_IbVC_DebugOut_VC_PathDev,
  real32_T *rty_IbVC_DebugOut_VC_Head_Dev, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSY, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBX, real32_T
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBY, uint8_T
  *rty_IbVC_DebugOut_PM_CurrentSweep, boolean_T *rty_IbVC_DebugOut_PM_RegenPath);

/* Model reference registration function */
extern void DT24_CVADAS_AutoPark_Func_initialize(const char_T **rt_errorStatus);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern real32_T CONST_DPS2RPS;        /* Referenced by: '<S1>/APA_Controller' */

/* conversion parameter from degree/s to rad/s */
extern uint16_T CeAP_ms_SampleTime;   /* Referenced by: '<S1>/APA_Controller' */
extern real32_T DS_ANGLE;
extern real32_T DS_WheelSpeed_RL;
extern real32_T DS_WheelSpeed_RR;
extern real32_T K_e_RAEB_DrawingTubeOffset;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_VehicleWidth;/* Referenced by: '<S1>/APA_Controller' */

/* To feed mobileye obj type into AdCam instead of hard coded value */
extern real32_T K_e_RAEB_WarnOffset;  /* Referenced by: '<S1>/APA_Controller' */

/* To feed lateral offset to issue warning */
extern uint16_T KeAP_Cnt_GearOverrideTimeThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Gear override time threshold */
extern real32_T KeAP_M_StrTrqValLimit; /* Referenced by: '<S1>/VC_Controller' */
extern boolean_T KeAP_b_DevlopmentTest;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Test Parameter used to change value of Tunable parameter while Testing */
extern boolean_T KeAP_b_EnVehStandstillArcBlip;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern boolean_T KeAP_b_EnWallAcurracy;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern boolean_T KeAP_b_RPAwithBrk;   /* Referenced by: '<S1>/APA_Controller' */

/* Ego vehicle shall be equipped with Rear Park Assist with Brake */
extern boolean_T KeAP_b_RearDistCorrBasedVehSpd;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint8_T KeAP_b_SupprsUssGlblHght;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern boolean_T KeAP_b_SwitchOldAlgo;/* Referenced by: '<S1>/APA_Controller' */
extern int16_T KeAP_cm_DistZone1;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_DistZone2;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_DistZone3;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_DistZone4;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_DistZone5;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_DistZone6;     /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 6 Dist */
extern int16_T KeAP_cm_FrntDistZone1; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 1 Dist */
extern int16_T KeAP_cm_FrntDistZone2; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 2 Dist */
extern int16_T KeAP_cm_FrntDistZone3; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 3 Dist */
extern int16_T KeAP_cm_FrntDistZone4; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 4 Dist */
extern int16_T KeAP_cm_FrntDistZone5; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 5 Dist */
extern int16_T KeAP_cm_FrntDistZone6; /* Referenced by: '<S1>/APA_Controller' */

/* Warning Zone 6 Dist */
extern real32_T KeAP_cm_FrntWallZone1Adj;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern int16_T KeAP_cm_NhXmaxOffset;  /* Referenced by: '<S1>/APA_Controller' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhXminOffset;  /* Referenced by: '<S1>/APA_Controller' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYmaxOffset;  /* Referenced by: '<S1>/APA_Controller' */

/* NeighboutHood Window */
extern int16_T KeAP_cm_NhYminOffset;  /* Referenced by: '<S1>/APA_Controller' */

/* NeighboutHood Window */
extern real32_T KeAP_cm_RearBrkDistChngLwThresh;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Rear Braking Dist Change lower Threshold */
extern real32_T KeAP_cm_RearBrkDistChngUpThresh;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Rear Braking Dist Change upper Threshold */
extern int16_T KeAP_cm_RearLongDistAdj;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Longitudanl Distance from Rear Axle to Rear edge of vehicle */
extern real32_T KeAP_cm_RearWallZone1Adj;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint16_T KeAP_cnt_AbortDelayWaitCnt;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern real32_T KeAP_cnt_AbortHMIWaitCnt;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern uint16_T KeAP_cnt_ArcBlipStandstillTimer;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint16_T KeAP_cnt_ArcBlipVehInMotTimer[6];
                                      /* Referenced by: '<S1>/APA_Controller' */
extern real32_T KeAP_cnt_ArcBlipVehSpdThd[6];
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint16_T KeAP_cnt_BootupTimeThd;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Time threshold for ECU bootup */
extern uint16_T KeAP_cnt_BtnPressPopUpTimeThd;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Time for which Startup PopUp Requests are shown */
extern real32_T KeAP_cnt_NoiseModeRearDistComp;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint16_T KeAP_cnt_PlntModeLEDBlinkTimeThd;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Time Step for LED blinking for ECU-In Plant Mode */
extern real32_T KeAP_cnt_RearDistCompTimeThd;
                                      /* Referenced by: '<S1>/APA_Controller' */
extern uint16_T KeAP_cnt_RelCntrlWaitThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern uint16_T KeAP_cnt_ScreenChimeTimeoutDur;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Screen Chime Time Threshold */
extern uint16_T KeAP_cnt_ScreenWaitTimeoutDur;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern uint16_T KeAP_cnt_StandstillTimeoutDur;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/*  Standstill Timer 9 min 50sec */
extern uint16_T KeAP_cnt_TimeStep;     /* Referenced by:
                                        * '<S1>/APA_Controller'
                                        * '<S1>/StateMachine_Controller'
                                        */

/* Time Step for Counter  */
extern real32_T KeAP_deg_SteerAngelDiffThd;/* Referenced by: '<S1>/VC_Controller' */
extern uint8_T KeAP_e_GbTypAT;        /* Referenced by: '<S1>/APA_Controller' */

/* ATX Gear_Box_Type */
extern real32_T KeAP_kph_EnblHysThd;  /* Referenced by: '<S1>/APA_Controller' */

/* Hystere sis threshold to apply for all vehicle speed related threshold parameters */
extern real32_T KeAP_kph_FrntWarnMaxSpdThd;/* Referenced by:
                                            * '<S1>/APA_Controller'
                                            * '<S1>/StateMachine_Controller'
                                            */

/* Vehicle speed threshold during Front Park Assist feature */
extern real32_T KeAP_kph_PSDOffThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Vehicle speed threshold during detection the parking slot */
extern real32_T KeAP_kph_ParkMnvThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Ego Vehicle speed limit to continue parking maneuvering */
extern real32_T KeAP_kph_RearWarnMaxSpdThd;/* Referenced by:
                                            * '<S1>/APA_Controller'
                                            * '<S1>/StateMachine_Controller'
                                            */

/* Vehicle speed threshold during Rear Park Assist feature */
extern real32_T KeAP_kph_StandStillSpdThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern real32_T KeAP_nm_TrqCmdRateLimThd;/* Referenced by: '<S1>/VC_Controller' */
extern uint8_T KeAP_pct_ObjConfidenceThd;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Detected Object Confidence threshold */
extern real32_T KeAP_pct_PdlPosActThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Screen Chime Time Threshold */
extern uint16_T KeAP_s_GearShiftReqWaitCnt;
                             /* Referenced by: '<S1>/StateMachine_Controller' */
extern uint16_T KeAP_s_WaitEngineOnThd;
                             /* Referenced by: '<S1>/StateMachine_Controller' */

/* Engine On Time THreshold */
extern uint8_T KePA_b_EnFeatPointSplitImp;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Enable NeighboutHood Window */
extern uint8_T KePA_b_EnHeightFlagFrontSideArcs;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Enable DNN Flag check for Side front arcs */
extern uint8_T KePA_b_EnHeightFlagRearSideArcs;
                                      /* Referenced by: '<S1>/APA_Controller' */

/* Enable DNN Flag check for Side rear arc */
extern uint8_T KePA_b_IsDnnHeightLow; /* Referenced by: '<S1>/APA_Controller' */

/* Enable DNN Flag check */
extern real32_T KsAP_k_DGainLUT_TD_55C[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_DGainLUT_TD_63C[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_DampingGainTD[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_IGainLUT_TD_55C[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_IGainLUT_TD_63C[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_IntegratorExtSatTD[4];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_PGainLUT_TD_55C[20];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_PGainLUT_TD_60C[20];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T KsAP_k_PGainLUT_TD_63C[20];/* Referenced by: '<S1>/VC_Controller' */
extern real32_T MaAP_m_ParkSpot1FrntStreetX;
extern real32_T MaAP_m_ParkSpot1FrntStreetY;
extern real32_T MaAP_m_ParkSpot2FrntBorderX;
extern real32_T MaAP_m_ParkSpot2FrntBorderY;
extern real32_T MaAP_m_ParkSpot3RearBorderX;
extern real32_T MaAP_m_ParkSpot3RearBorderY;
extern real32_T MaAP_m_ParkSpot4RearStreetX;
extern real32_T MaAP_m_ParkSpot4RearStreetY;
extern boolean_T MeAP_b_FPASwtStatus;  /* '<S1>/APA_Controller' */
extern boolean_T MeAP_b_RPASwtStatus;  /* '<S1>/APA_Controller' */
extern boolean_T MeAP_b_ResetKM;       /* '<S1>/StateMachine_Controller' */
extern TeAutoPark_e_AutoParkStatus MeAP_e_AutoParkStatus;/* '<S1>/StateMachine_Controller' */
extern boolean_T MeAP_k_PerpNoseIn;    /* '<S1>/StateMachine_Controller' */
extern TeAP_e_AlgoState MeAutoPark_e_AlgoState;/* '<S1>/StateMachine_Controller' */
extern uint8_T PSType;                 /* '<S1>/StateMachine_Controller' */
extern uint8_T parkout_perp_left;      /* '<S1>/StateMachine_Controller' */

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const uint8_T CeAP_k_CurbArrayInit[10];
                                      /* Referenced by: '<S1>/APA_Controller' */
extern const real32_T KeAP_CurbLim_para[3];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T KeAP_break_point_para[2];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T KeAP_break_point_perp[2];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T KeAP_fin_loc_para_out[2];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T KeAP_p3_adj_perp[2];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T KeAP_str_profile_bigPS[34];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T step_size_coeff[6];/* Referenced by: '<S1>/VC_Controller' */
extern const real32_T str_whl_ang_park_out;/* Referenced by: '<S1>/VC_Controller' */

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

extern MdlrefDW_DT24_CVADAS_AutoPark_Func_T DT24_CVADAS_AutoPark_Func_MdlrefDW;

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

#ifndef DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_DT24_CVADAS_AutoPark_Func_c_T DT24_CVADAS_AutoPark_Func_B;

/* Block states (default storage) */
extern DW_DT24_CVADAS_AutoPark_Func_f_T DT24_CVADAS_AutoPark_Func_DW;

#endif                          /*DT24_CVADAS_AutoPark_Func_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'DT24_CVADAS_AutoPark_Func'
 * '<S1>'   : 'DT24_CVADAS_AutoPark_Func/Controller'
 */
#endif                             /* RTW_HEADER_DT24_CVADAS_AutoPark_Func_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
