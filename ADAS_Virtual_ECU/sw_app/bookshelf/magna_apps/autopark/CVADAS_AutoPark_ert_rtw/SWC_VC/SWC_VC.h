/*
 * File: SWC_VC.h
 *
 * Code generated for Simulink model 'SWC_VC'.
 *
 * Model version                  : 1.2255
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Tue Nov 11 20:51:59 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_VC_h_
#define RTW_HEADER_SWC_VC_h_
#include <math.h>
#include <string.h>
#ifndef SWC_VC_COMMON_INCLUDES_
# define SWC_VC_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#endif                                 /* SWC_VC_COMMON_INCLUDES_ */

#include "SWC_VC_types.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

/* Exported data define */

/* Definition for custom storage class: Define */
#define FB_PS_min_length               5.0F                      /* Referenced by: '<S59>/Chart1' */
#define FB_PS_min_width                2.18F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_FrontOffset               0.2F                      /* Referenced by: '<S59>/Chart1' */

/* Offset of the front of the vehicle from the final pose */
#define KeAP_Kf_para                   0.7F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_Kf_perp                   0.7F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_Kf_perp_single_sweep      0.5F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_Ks                        1.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_PP_RES_DIST_TRAVEL        0.01F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_Phi_lim_perp              50.0F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_Phi_resolution_perp       3.0F                      /* Referenced by: '<S59>/Chart1' */

/* Resolution of path heading (Deg) */
#define KeAP_StrRateLim_para           100.0F                    /* Referenced by: '<S59>/Chart1' */
#define KeAP_StrRateLim_perp           100.0F                    /* Referenced by: '<S59>/Chart1' */

/* Steering rate limit during a perpendicular maneuver */
#define KeAP_V_max_para                1.5F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_V_max_perp                2.5F                      /* Referenced by: '<S59>/Chart1' */

/* Max velocity during perpendicular maneuver (m/s) */
#define KeAP_ang_threshold_regen       1.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_app_ctrl_min_dist_x_para  1.5F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_app_ctrl_min_dist_x_perp  1.5F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_aux_alpha                 2.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_aux_turn_para_regen       4.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_control_point_3_x_adjust_m -0.2F                    /* Referenced by: '<S59>/Chart1' */

/* Adjustment to x position of control point 3 (m) */
#define KeAP_control_point_3_y_step_m  -0.1F                     /* Referenced by: '<S59>/Chart1' */

/* Adjustment to y position of control point 3 (m) */
#define KeAP_curb_over_Y_dir_para      0.25F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_curvature_coeff_perp      0.6667F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_delta_s_clothoid_para     0.1F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_delta_s_clothoid_perp     0.08F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_delta_s_no_str_para       0.09F                     /* Referenced by: '<S59>/Chart1' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_delta_s_no_str_perp       0.07F                     /* Referenced by: '<S59>/Chart1' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_delta_s_nose_in_regen     0.1F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_delta_s_para              0.05F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_delta_s_perp              0.05F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_lim_perp_PS4              0.1F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_maxCurvatureTypeOne       0.22845903F               /* Referenced by: '<S62>/Constant3' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeThree     0.215264142F              /* Referenced by:
                                                                  * '<S62>/Constant5'
                                                                  * '<S62>/Constant6'
                                                                  */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_maxCurvatureTypeTwo       0.228461951F              /* Referenced by: '<S62>/Constant4' */

/* Maximum curvature of the vehicle (1/m) */
#define KeAP_max_num_sweeps            7U                        /* Referenced by: '<S59>/Chart1' */
#define KeAP_n_para                    15U                       /* Referenced by: '<S59>/Chart1' */

/* Number of waypoints in each parallel planner segment */
#define KeAP_n_perp                    20U                       /* Referenced by: '<S59>/Chart1' */

/* Number of waypoints in each perpendicular planner segment. ALERT n_per_segment acts as an upper bound for this */
#define KeAP_num_clothoid_waypoints_para_mediumPS 2U             /* Referenced by: '<S59>/Chart1' */
#define KeAP_num_clothoid_waypoints_para_smallPS 2U              /* Referenced by: '<S59>/Chart1' */
#define KeAP_num_points_no_str_para    16U                       /* Referenced by: '<S59>/Chart1' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a parallel parking plan */
#define KeAP_num_points_no_str_perp    10U                       /* Referenced by: '<S59>/Chart1' */

/* The path displacement (m) between waypoints during the no steering portion at the beginning of a perpendiular parking plan */
#define KeAP_p3_pos_lim_perp           2.5F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_para_control_point_2_x_step_m -0.3F                 /* Referenced by: '<S59>/Chart1' */

/* Step size for adjusting the X position of the second parallel control point (m) */
#define KeAP_para_final_curb_offset    -0.16F                    /* Referenced by: '<S59>/Chart1' */

/* Offset of the final position of the vehicle from the curb (m) */
#define KeAP_park_out_nose_in_angle    35.0F                     /* Referenced by: '<S59>/Chart1' */

/* Angle at gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_X 1.5F              /* Referenced by: '<S59>/Chart1' */

/* X offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_brk_pos_offset_Y 4.5F              /* Referenced by: '<S59>/Chart1' */

/* Y offset of gear change point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_X 3.0F              /* Referenced by: '<S59>/Chart1' */

/* X offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_big 2.0F          /* Referenced by: '<S59>/Chart1' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_park_out_nose_in_end_pos_offset_Y_small 2.0F        /* Referenced by: '<S59>/Chart1' */

/* Y offset of final point of a park out nose in maneuver */
#define KeAP_safety_lim_fb_f           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_fb_r           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_fb_s           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_nz_f           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_nz_r           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_nz_s           0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_para_f         0.1F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_para_r         0.1F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_para_s         0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_perp_f         0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_perp_r         0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_perp_s         0.0F                      /* Referenced by: '<S59>/Chart1' */
#define KeAP_safety_lim_single_sweep_perp 0.05F                  /* Referenced by: '<S59>/Chart1' */
#define KeAP_segment_3_length_perp_m   2.0F                      /* Referenced by: '<S59>/Chart1' */

/* Length of segment 3 (m) in a perpendicular back-in 3 sweep park */
#define KeAP_single_sweep_control_point_2_y_offset -1.9F         /* Referenced by: '<S59>/Chart1' */

/* The y offset of the second control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_x_offset 0.65F         /* Referenced by: '<S59>/Chart1' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_control_point_3_y_offset -1.6F         /* Referenced by: '<S59>/Chart1' */

/* The y offset of the third control point of a single sweep plan(m) */
#define KeAP_single_sweep_perp_width_lim 2.95F                   /* Referenced by: '<S59>/Chart1' */

/* The minimum width of a parking space that allows a single sweep park */
#define KeAP_single_sweep_start_min_lon_dist_m 6.8F              /* Referenced by: '<S59>/Chart1' */

/* The minimum longitudinal distance of the vehicle origin from the C1 corner of the parking spot to perform a single sweep (m) */
#define KeAP_str_wheel_ang_perp        45.0F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_mediumPS_D 22.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_mediumPS_R 10.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_mediumPS_R_tail 33.0F              /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_smallPS_D2 25.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_smallPS_D4 15.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_smallPS_R3 25.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_smallPS_R5 15.0F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_para_smallPS_R_tail 33.0F               /* Referenced by: '<S59>/Chart1' */
#define KeAP_str_whl_ang_regen         33.0F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_straight_line_perp_park_out 2.5F                    /* Referenced by: '<S59>/Chart1' */
#define KeAP_sweep_length_lim_regen    0.15F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_turn_radius_park_out_perp 5.25F                     /* Referenced by: '<S59>/Chart1' */
#define KeAP_turn_radius_park_out_perp_big 5.25F                 /* Referenced by: '<S59>/Chart1' */
#define KeAP_turn_radius_single_sweep_perp 4.5F                  /* Referenced by: '<S59>/Chart1' */
#define KeAP_vecLen_coeff_para         0.4437F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_vecLen_coeff_perp         0.4437F                   /* Referenced by: '<S59>/Chart1' */
#define KeAP_vecLen_coeff_perp_single_sweep_Phi 0.0323F          /* Referenced by: '<S59>/Chart1' */
#define KeAP_vecLen_coeff_perp_single_sweep_XY 0.5547F           /* Referenced by: '<S59>/Chart1' */
#define KeAP_yaw_control_point_3_perp_deg 25.0F                  /* Referenced by: '<S59>/Chart1' */

/* Heading (deg) of the vehicle with respect to the parking spot at the third control point of a perpendiciular rear park in */
#define Ke_AP_deg_MaxWheelAngle        40.0F                     /* Referenced by:
                                                                  * '<S59>/Chart1'
                                                                  * '<S61>/Constant'
                                                                  */
#define Kf_fb                          0.7F                      /* Referenced by: '<S59>/Chart1' */
#define PP_PS_min_length               5.4F                      /* Referenced by: '<S59>/Chart1' */
#define PP_PS_min_width                2.18F                     /* Referenced by: '<S59>/Chart1' */
#define Rs                             100.0F                    /* Referenced by: '<S59>/Chart1' */
#define StrRateLim_fb                  47.0F                     /* Referenced by: '<S59>/Chart1' */
#define V_max_fb                       2.5F                      /* Referenced by: '<S59>/Chart1' */
#define Y_resolution_para              0.5F                      /* Referenced by: '<S59>/Chart1' */
#define app_ctrl_min_dist_x_fb         1.5F                      /* Referenced by: '<S59>/Chart1' */
#define aux_turn_para                  5.0F                      /* Referenced by: '<S59>/Chart1' */
#define break_point_fb                 6.0F                      /* Referenced by: '<S59>/Chart1' */
#define delta_s_fb                     0.05F                     /* Referenced by: '<S59>/Chart1' */
#define delta_s_no_str_fb              0.07F                     /* Referenced by: '<S59>/Chart1' */
#define length_regen_fb                5.0F                      /* Referenced by: '<S59>/Chart1' */
#define minRadiusTypeTwo               4.37709665F               /* Referenced by: '<S64>/Constant4' */
#define minRadius_TypeOne              4.37715244F               /* Referenced by: '<S64>/Constant3' */
#define minRadiustypeThree             4.64545536F               /* Referenced by:
                                                                  * '<S64>/Constant5'
                                                                  * '<S64>/Constant6'
                                                                  */
#define n_fb                           15U                       /* Referenced by: '<S59>/Chart1' */
#define num_arc_waypoints_para_bigPS   27U                       /* Referenced by: '<S59>/Chart1' */
#define num_clothoid_waypoints_para_bigPS 2U                     /* Referenced by: '<S59>/Chart1' */
#define num_points_no_str_fb           10U                       /* Referenced by: '<S59>/Chart1' */
#define p3_ang_lim_perp                0.0F                      /* Referenced by: '<S59>/Chart1' */
#define str_whl_ang_para_bigPS_R       33.0F                     /* Referenced by: '<S59>/Chart1' */
#define straight_line_fb               1.0F                      /* Referenced by: '<S59>/Chart1' */
#define vecLen_coeff_fb                0.4437F                   /* Referenced by: '<S59>/Chart1' */

/* user code (top of header file) */
#include "SignalDef.h"

/* Block signals for model 'SWC_VC' */
#ifndef SWC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real32_T Pwc[500];
  real32_T fxi[500];
  real32_T waypoint_segment_dist_data[255];
  real32_T Spd_data[250];
  real32_T dist_y[250];
  real32_T distance_data[250];
  real32_T varargin_1_data[250];
  real32_T tmp_data[250];
  real32_T fxoi_data[250];
  real32_T fyoi_data[250];
  real32_T fhoi_data[250];
  real32_T fvoi_data[250];
  real32_T fsoi_data[250];
  real32_T fxo_12_data[250];
  real32_T fyo_12_data[250];
  real32_T fxo_34_data[250];
  real32_T fyo_34_data[250];
  real32_T z_data[250];
  real32_T fxp_data[250];
  real32_T fyp_data[250];
  real32_T xf1_data[250];
  real32_T yf1_data[250];
  real32_T xf2_data[250];
  real32_T yf2_data[250];
  real32_T fxoi_data_m[250];
  real32_T fyoi_data_c[250];
  real32_T fhoi_data_k[250];
  real32_T fvoi_data_c[250];
  real32_T fsoi_data_b[250];
  real32_T dummy_data[250];
  real32_T fxo_12_data_p[250];
  real32_T fyo_12_data_c[250];
  real32_T fxp_data_f[250];
  real32_T fyp_data_g[250];
  real32_T xf1_data_g[250];
  real32_T yf1_data_m[250];
  real32_T xf2_data_n[250];
  real32_T yf2_data_p[250];
  real32_T fvo[250];
  real32_T fso[250];
  real32_T fho[250];
  real32_T fyo[250];
  real32_T fxo[250];
  real32_T fxi_l[250];
  real32_T fyi[250];
  real32_T fhi[250];
  real32_T fsi[250];
  real32_T fv_j[250];
  real32_T fv1[250];
  real32_T Pwc_d[250];
  real32_T fv2[250];
  real32_T fxo_dummy[250];
  real32_T fyo_dummy[250];
  real32_T fv3[250];
  real32_T fv4[250];
  real32_T fv5[250];
  real32_T fxp[250];
  real32_T fyp[250];
  real32_T xf1[250];
  real32_T yf1[250];
  real32_T xf2[250];
  real32_T yf2[250];
  real32_T z1_data[250];
  real32_T tmp_data_g[249];
  real32_T dfx_data[249];
  real32_T dfy_data[249];
  real32_T tmp_data_l[249];
  real32_T tmp_data_d[249];
  real32_T dfx_data_d[249];
  real32_T dfy_data_l[249];
  real32_T tmp_data_o[249];
  real32_T tmp_data_b[249];
  real32_T dfx[249];
  real32_T dfy[249];
  real32_T fv6[249];
  real32_T fv7[249];
  real32_T b_y1_data[249];
  real32_T z1_data_n[249];
  real32_T output_data[105];
  real32_T xy_out_clothoid_data[100];
  real32_T result_data[100];
  sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T expl_temp;
  int8_T fgo_data[250];
  int8_T fgo_data_b[250];
  int8_T b_dummy_data[250];
  int8_T fgo[250];
  int8_T fgo_dummy[250];
  real32_T x_out_data[50];
  real32_T y_out_data[50];
  real32_T x_out2_data[50];
  real32_T y_out2_data[50];
  real32_T x_out4_data[50];
  real32_T y_out4_data[50];
  real32_T x_path_data[50];
  real32_T y_path_data[50];
  real32_T heading_angle_data[50];
  real32_T x_out_data_l[50];
  real32_T y_out_data_h[50];
  real32_T x_out_bz_data[50];
  real32_T y_out_bz_data[50];
  real32_T str_profile_data[50];
  real32_T x_path_data_b[50];
  real32_T y_path_data_d[50];
  real32_T dummy_2_data[50];
  real32_T x_path[50];
  real32_T y_path[50];
  real32_T heading_angle[50];
  real32_T y_out[50];
  real32_T fxp_data_e[50];
  real32_T fyp_data_b[50];
  real32_T xf1_data_j[50];
  real32_T yf1_data_f[50];
  real32_T xf2_data_a[50];
  real32_T yf2_data_j[50];
  real32_T x_out_data_j[50];
  real32_T y_out_data_o[50];
  real32_T x_out_data_n[50];
  real32_T y_out_data_i[50];
  real32_T x_out_data_o[50];
  real32_T y_out_data_n[50];
  real32_T kappa_num[50];
  real32_T kappa_num_data[50];
  sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T expl_temp_m;
  s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T expl_temp_c;
  real32_T pp[20];
  real32_T pp_m[20];
  real32_T pp_m3[20];
  real32_T pp_j[20];
  real32_T pp_h[20];
  real32_T pp_c[20];
  TbVC_DebugOut IbVC_DebugOut;         /* '<S1>/Bus Creator' */
  real32_T waypoint_dist[10];
  real32_T Phi_guideline[10];
  real32_T Phi_guideline_c[10];
  real32_T Phi_guideline_p[10];
  real32_T Phi_guideline_p5[10];
  real32_T Phi_guideline_a[10];
  real32_T Phi_guideline_e[10];
  real32_T PS_diff[8];
  real32_T pps[8];
  real32_T PSLo[8];
  real32_T PSLi[8];
  real32_T PSLi_a[8];
  real32_T ParkingSpotCoordinates[8];
  real32_T ParkingSpotCoordRow1XRow2Y[8];
  real32_T ParkingSpotCoordinates_a[8];
  int16_T r[11];
  int16_T y_i[10];
  int16_T fio_dummy[10];
  int16_T iv[10];
  int16_T fio_dummy_l[10];
  int16_T iv1[10];
  int16_T fio_dummy_o[10];
  int16_T iv2[10];
  int16_T fi_out[10];
  real32_T varargin_1[4];
  real32_T Rot[4];
  real32_T Rot_f[4];
  s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T expl_temp_o;
  s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T expl_temp_i;
  int8_T i_sign[11];
  uint8_T i[10];
  uint8_T i_data[10];
  uint8_T n_segment[10];
  uint8_T n_segment_i[10];
  uint8_T n_segment_f[10];
  real_T Sum;                          /* '<S22>/Sum' */
  real_T Product;                      /* '<S113>/Product' */
  real_T Yk1;                          /* '<S122>/Delay Input2' */
  real_T UkYk1;                        /* '<S122>/Difference Inputs1' */
  real_T deltariselimit;               /* '<S122>/delta rise limit' */
  real_T deltafalllimit;               /* '<S122>/delta fall limit' */
  real_T Switch;                       /* '<S123>/Switch' */
  real_T Switch2;                      /* '<S123>/Switch2' */
  real_T DifferenceInputs2;            /* '<S122>/Difference Inputs2' */
  real_T SwitchActive1;                /* '<S13>/SwitchActive1' */
  real_T PP_REPLAN_ORNT_DEVIATION;     /* '<S24>/PP_REPLAN_ORNT_DEVIATION' */
  real_T PP_REPLAN_POS_DEVIATION;      /* '<S24>/PP_REPLAN_POS_DEVIATION' */
  real_T MinMax;                       /* '<S113>/MinMax' */
  real_T MinMax1;                      /* '<S113>/MinMax1' */
  real_T hardBrake;
                /* '<S111>/Brake At Gear Changing From Zero || Stopping Mode' */
  real_T driverIgnore;
                /* '<S111>/Brake At Gear Changing From Zero || Stopping Mode' */
  real_T Product_b;                    /* '<S111>/Product' */
  real_T Gear_CMD;                     /* '<S108>/Gear_CMD_func' */
  real_T wp_plus_1;                    /* '<S104>/Add5' */
  real_T wp_plus_1_g;                  /* '<S97>/Add5' */
  real_T updated_preview_dist;         /* '<S83>/MATLAB Function' */
  real_T OutportBufferForIeAP_a_DecelMax;/* '<S17>/Constant' */
  real_T OutportBufferForIeAP_a_DecelMin;/* '<S17>/Constant1' */
  real_T OutportBufferForIeAP_a_JerkDecelMax;/* '<S17>/Constant2' */
  real_T OutportBufferForIeAP_a_JerkDecelMin;/* '<S17>/Constant3' */
  real_T OutportBufferForIeAP_a_AcclMin;/* '<S17>/Constant4' */
  real_T OutportBufferForIeAP_a_AcclMax;/* '<S17>/Constant5' */
  real_T OutportBufferForIeAP_da_JerkAcclMax;/* '<S17>/Constant6' */
  real_T OutportBufferForIeAP_da_JerkAcclMin;/* '<S17>/Constant7' */
  real_T OutportBufferForIeAP_b_StandstillReq;/* '<S17>/Constant8' */
  real_T xOffset;                      /* '<S15>/MATLAB Function' */
  real_T x_para_Offset;                /* '<S15>/MATLAB Function' */
  real_T yOffset;                      /* '<S15>/MATLAB Function' */
  real_T reset_KM;                     /* '<S12>/KM_Reset Decision Function' */
  real_T y[14];                        /* '<S36>/MATLAB Function' */
  real_T y_a[14];                      /* '<S35>/MATLAB Function' */
  real_T sampletime;                   /* '<S122>/sample time' */
  real_T Min;                          /* '<S1>/Min' */
  real_T Sum_g;                        /* '<S113>/Sum' */
  real_T Product_k[14];                /* '<S35>/Product' */
  real_T Add[14];                      /* '<S35>/Add' */
  real_T Product_h[14];                /* '<S36>/Product' */
  real_T Add_b[14];                    /* '<S36>/Add' */
  real_T DataTypeConversion;           /* '<S16>/Data Type Conversion' */
  real_T Product_a;                    /* '<S16>/Product' */
  real_T minV;
  real_T dd;
  real_T d;
  real32_T P3[2];
  real32_T line_direction[2];
  real32_T P3_m[2];
  real32_T W2[2];
  real32_T X[2];
  real32_T Y[2];
  real32_T X_c[2];
  real32_T P3_f[2];
  real32_T final_point[2];
  real32_T X_p[2];
  real32_T Y_e[2];
  real32_T P0[2];
  real32_T pp_o[2];
  real32_T x_out[2];
  real32_T x_out_h[2];
  real32_T x_out_l[2];
  real32_T mid_border[2];
  int32_T distance_size[2];
  int32_T varargin_1_size[2];
  int32_T varargin_1_size_g[2];
  int32_T tmp_size[2];
  int32_T tmp_size_c[2];
  int32_T tmp_size_o[2];
  int32_T tmp_size_l[2];
  int32_T tmp_size_m[2];
  int32_T x_out2_size[2];
  int32_T y_out2_size[2];
  int32_T x_out_bz_size[2];
  int32_T y_out_bz_size[2];
  real32_T DataTypeConversion2;        /* '<S12>/Data Type Conversion2' */
  real32_T DiscreteTimeIntegrator1[2]; /* '<S12>/Discrete-Time Integrator1' */
  real32_T DataTypeConversion1;        /* '<S56>/Data Type Conversion1' */
  real32_T DataTypeConversion2_l;      /* '<S56>/Data Type Conversion2' */
  real32_T DiscreteTimeIntegrator;     /* '<S12>/Discrete-Time Integrator' */
  real32_T DataTypeConversion3;        /* '<S56>/Data Type Conversion3' */
  real32_T Abs;                        /* '<S56>/Abs' */
  real32_T steering_XXcmat2;           /* '<S58>/steering_XXc.mat2' */
  real32_T whl_angl;                   /* '<S56>/Product3' */
  real32_T DataTypeConversion4[8];     /* '<S13>/Data Type Conversion4' */
  real32_T KeAP_PS_size_para[4];       /* '<S61>/Add1' */
  real32_T PEP_PS_min_length;          /* '<S61>/Product3' */
  real32_T PEP_PS_min_width;           /* '<S61>/Add2' */
  real32_T KeAP_single_sweep_start_min_lat_dist_m;/* '<S61>/Add3' */
  real32_T RateTransition13;           /* '<S1>/Rate Transition13' */
  real32_T RateTransition17;           /* '<S1>/Rate Transition17' */
  real32_T RateTransition16;           /* '<S1>/Rate Transition16' */
  real32_T Abs_g;                      /* '<S12>/Abs' */
  real32_T steering_XXcmat2_o;         /* '<S51>/steering_XXc.mat2' */
  real32_T whl_angl_d;                 /* '<S12>/Switch' */
  real32_T speed_kph_MABx;             /* '<S1>/Data Type Conversion11' */
  real32_T DataTypeConversion2_d;      /* '<S5>/Data Type Conversion2' */
  real32_T RateTransition2;            /* '<S21>/Rate Transition2' */
  real32_T RemainDist_Stat_sendtime;   /* '<S113>/RemainDist_Stat_sendtime ' */
  real32_T DiscreteTimeIntegrator_l;   /* '<S113>/Discrete-Time Integrator' */
  real32_T Switch7;                    /* '<S113>/Switch7' */
  real32_T Lower_rate_limit_duration;  /* '<S113>/Lower_rate_limit_duration' */
  real32_T DiscreteTimeIntegrator2;    /* '<S113>/Discrete-Time Integrator2' */
  real32_T TargetSpeed;                /* '<S108>/Data Type Conversion1' */
  real32_T DataTypeConversion1_l;      /* '<S111>/Data Type Conversion1' */
  real32_T RateTransition;             /* '<S111>/Rate Transition' */
  real32_T DataTypeConversion3_e;      /* '<S111>/Data Type Conversion3' */
  real32_T Sum1;                       /* '<S111>/Sum1' */
  real32_T DataTypeConversion3_d;      /* '<S23>/Data Type Conversion3' */
  real32_T Yk1_d;                      /* '<S71>/Delay Input2' */
  real32_T deltariselimit_n;           /* '<S71>/delta rise limit' */
  real32_T Abs1;                       /* '<S18>/Abs1' */
  real32_T Abs_e;                      /* '<S18>/Abs' */
  real32_T Yk1_b;                      /* '<S72>/Delay Input2' */
  real32_T deltariselimit_f;           /* '<S72>/delta rise limit' */
  real32_T Switch_g;                   /* '<S19>/Switch' */
  real32_T Switch_d;                   /* '<S78>/Switch' */
  real32_T Switch2_p;                  /* '<S78>/Switch2' */
  real32_T UkYk1_n;                    /* '<S72>/Difference Inputs1' */
  real32_T deltafalllimit_c;           /* '<S72>/delta fall limit' */
  real32_T Switch_m;                   /* '<S77>/Switch' */
  real32_T Switch2_c;                  /* '<S77>/Switch2' */
  real32_T DifferenceInputs2_f;        /* '<S72>/Difference Inputs2' */
  real32_T DiscreteTimeIntegrator_lc;  /* '<S18>/Discrete-Time Integrator' */
  real32_T Switch_do;                  /* '<S74>/Switch' */
  real32_T Switch2_i;                  /* '<S74>/Switch2' */
  real32_T differential_gain_table1;   /* '<S18>/differential_gain_table1' */
  real32_T StrCmdTqLmtOld;             /* '<S18>/Add1' */
  real32_T UkYk1_ns;                   /* '<S71>/Difference Inputs1' */
  real32_T deltafalllimit_d;           /* '<S71>/delta fall limit' */
  real32_T Switch_n;                   /* '<S76>/Switch' */
  real32_T Switch2_j;                  /* '<S76>/Switch2' */
  real32_T DifferenceInputs2_p;        /* '<S71>/Difference Inputs2' */
  real32_T Switch_no;                  /* '<S73>/Switch' */
  real32_T Switch2_d;                  /* '<S73>/Switch2' */
  real32_T Switch_n4;                  /* '<S1>/Switch' */
  real32_T Yk1_c;                      /* '<S14>/Delay Input2' */
  real32_T UkYk1_j;                    /* '<S14>/Difference Inputs1' */
  real32_T deltariselimit_o;           /* '<S14>/delta rise limit' */
  real32_T deltafalllimit_h;           /* '<S14>/delta fall limit' */
  real32_T Switch_i;                   /* '<S65>/Switch' */
  real32_T Switch2_g;                  /* '<S65>/Switch2' */
  real32_T DifferenceInputs2_h;        /* '<S14>/Difference Inputs2' */
  real32_T integrator_gain_table1;     /* '<S18>/integrator_gain_table1' */
  real32_T Product2;                   /* '<S18>/Product2' */
  real32_T steer_cmd_angle;            /* '<S1>/steer_cmd_angle' */
  real32_T Constant;                   /* '<S61>/Constant' */
  real32_T VehSpdMax_DeadSteer1;       /* '<S113>/VehSpdMax_DeadSteer1' */
  real32_T Veh_SpdMax_Rq_Def;          /* '<S108>/Veh_SpdMax_Rq_Def' */
  real32_T CastToSingle;               /* '<S3>/Cast To Single' */
  real32_T CastToSingle1;              /* '<S3>/Cast To Single1' */
  real32_T IeAP_a_DecelMax;            /* '<Root>/Data Type Conversion23' */
  real32_T IeAP_cm_TrgtDist;           /* '<Root>/Data Type Conversion11' */
  real32_T IeAP_kph_TrgtVehSpd;        /* '<Root>/Data Type Conversion26' */
  real32_T IeAP_a_DecelMin;            /* '<Root>/Data Type Conversion22' */
  real32_T IeAP_a_JerkDecelMax;        /* '<Root>/Data Type Conversion21' */
  real32_T IeAP_a_JerkDecelMin;        /* '<Root>/Data Type Conversion20' */
  real32_T IeAP_a_AcclMin;             /* '<Root>/Data Type Conversion19' */
  real32_T IeAP_a_AcclMax;             /* '<Root>/Data Type Conversion18' */
  real32_T IeAP_da_JerkAcclMax;        /* '<Root>/Data Type Conversion17' */
  real32_T IeAP_da_JerkAcclMin;        /* '<Root>/Data Type Conversion16' */
  real32_T speed;                      /* '<S3>/MATLAB Function' */
  real32_T distance;                   /* '<S3>/MATLAB Function' */
  real32_T steer[250];                 /* '<S82>/Signal Conversion' */
  real32_T speed_d[250];               /* '<S82>/Signal Conversion' */
  real32_T yaw[250];                   /* '<S82>/Signal Conversion' */
  real32_T x[250];                     /* '<S82>/Signal Conversion' */
  real32_T y_o[250];                   /* '<S82>/Signal Conversion' */
  real32_T O_steer[250];            /* '<S82>/MATLAB Function PathSeparation' */
  real32_T O_speed[250];            /* '<S82>/MATLAB Function PathSeparation' */
  real32_T O_yaw[250];              /* '<S82>/MATLAB Function PathSeparation' */
  real32_T O_x[250];                /* '<S82>/MATLAB Function PathSeparation' */
  real32_T O_y[250];                /* '<S82>/MATLAB Function PathSeparation' */
  real32_T Switch4;                    /* '<S113>/Switch4' */
  real32_T uDLookupTable;              /* '<S115>/1-D Lookup Table' */
  real32_T Diff;                       /* '<S116>/Diff' */
  real32_T UnitDelay1;                 /* '<S115>/Unit Delay1' */
  real32_T Switch_j;                   /* '<S115>/Switch' */
  real32_T DataTypeConversion3_j;      /* '<S115>/Data Type Conversion3' */
  real32_T Switch3;                    /* '<S115>/Switch3' */
  real32_T Switch4_o;                  /* '<S115>/Switch4' */
  real32_T act_pct;                    /* '<S115>/PID_Algorithm' */
  real32_T integrator_val;             /* '<S115>/PID_Algorithm' */
  real32_T Switch1;                    /* '<S116>/Switch1' */
  real32_T Abs_e4;                     /* '<S115>/Abs' */
  real32_T brakeReleaseTime;
                /* '<S111>/Brake At Gear Changing From Zero || Stopping Mode' */
  real32_T curr_wp;                    /* '<S80>/Signal Conversion' */
  real32_T IndexWP;                    /* '<S94>/Index WP' */
  real32_T Add4;                       /* '<S88>/Add4' */
  real32_T IndexWP_c;                  /* '<S90>/Index WP' */
  real32_T IndexWP_n;                  /* '<S105>/Index WP' */
  real32_T MaxSpeed;                   /* '<S80>/Signal Conversion' */
  real32_T Add4_h;                     /* '<S89>/Add4' */
  real32_T Switch1_c;                  /* '<S100>/Switch1' */
  real32_T CastToSingle_f;             /* '<S84>/Cast To Single' */
  real32_T MultiportSwitch;            /* '<S93>/Multiport Switch' */
  real32_T remainingdistance;          /* '<S83>/Data Type Conversion2' */
  real32_T Abs_c;                      /* '<S84>/Abs' */
  real32_T steering_XXcmat2_l;         /* '<S92>/steering_XXc.mat2' */
  real32_T remainingdistance_d;        /* '<S80>/Signal Conversion' */
  real32_T Dist2Path_long[250];        /* '<S80>/MATLAB Function' */
  real32_T Dist2Path_lat[250];         /* '<S80>/MATLAB Function' */
  real32_T wp_plus_1_o;                /* '<S107>/Add5' */
  real32_T Multiply1;                  /* '<S107>/Multiply1' */
  real32_T steering_XXcmat;            /* '<S92>/steering_XXc.mat' */
  real32_T steering_XXcmat1;           /* '<S92>/steering_XXc.mat1' */
  real32_T steering_tire_angle_deg;    /* '<S84>/MATLAB Function' */
  real32_T lookahead_lat;              /* '<S84>/MATLAB Function' */
  real32_T lookahead_dist;             /* '<S84>/MATLAB Function' */
  real32_T Multiply1_l;                /* '<S104>/Multiply1' */
  real32_T Switch_p;                   /* '<S100>/Switch' */
  real32_T Add1;                       /* '<S100>/Add1' */
  real32_T Add2;                       /* '<S100>/Add2' */
  real32_T Switch_k;                   /* '<S95>/Switch' */
  real32_T Add1_m;                     /* '<S95>/Add1' */
  real32_T Add2_g;                     /* '<S95>/Add2' */
  real32_T Multiply1_m;                /* '<S97>/Multiply1' */
  real32_T curr_factor;                /* '<S83>/MATLAB Function' */
  real32_T remain_dist;                /* '<S83>/MATLAB Function' */
  real32_T factor_preview;             /* '<S83>/MATLAB Function' */
  real32_T input_rate_limit_table1;    /* '<S18>/input_rate_limit_table1' */
  real32_T input_rate_limit_table;     /* '<S18>/input_rate_limit_table' */
  real32_T Switch7_g;                  /* '<S18>/Switch7' */
  real32_T differential_gain_table;    /* '<S18>/differential_gain_table' */
  real32_T P_gain_lookup_table_Veh98_Veh54;
                                   /* '<S18>/P_gain_lookup_table_Veh98_Veh54' */
  real32_T StrTqFB_P_Old;              /* '<S18>/Switch4' */
  real32_T P_gain_lookup_table2;       /* '<S18>/P_gain_lookup_table2' */
  real32_T StrTqFB_P_Old_h;            /* '<S18>/Switch' */
  real32_T P_gain_lookup_table3;       /* '<S18>/P_gain_lookup_table3' */
  real32_T P_gain_lookup_table4;       /* '<S18>/P_gain_lookup_table4' */
  real32_T Switch2_a;                  /* '<S18>/Switch2' */
  real32_T integrator_gain_table;      /* '<S18>/integrator_gain_table' */
  real32_T DataTypeConversion_l;       /* '<S17>/Data Type Conversion' */
  real32_T TmpSignalConversionAtSFunctionInport2[5];/* '<S59>/Chart1' */
  real32_T TmpSignalConversionAtSFunctionInport14[12];/* '<S59>/Chart1' */
  real32_T fx[250];                    /* '<S59>/Chart1' */
  real32_T fy[250];                    /* '<S59>/Chart1' */
  real32_T fh[250];                    /* '<S59>/Chart1' */
  real32_T fs[250];                    /* '<S59>/Chart1' */
  real32_T fv[250];                    /* '<S59>/Chart1' */
  real32_T steering_XXcmat_j;          /* '<S58>/steering_XXc.mat' */
  real32_T steering_XXcmat1_b;         /* '<S58>/steering_XXc.mat1' */
  real32_T steering_XXcmat_l;          /* '<S51>/steering_XXc.mat' */
  real32_T steering_XXcmat1_e;         /* '<S51>/steering_XXc.mat1' */
  real32_T speed_Rear_axle_mps;        /* '<S12>/Rear axle speed conversion ' */
  real32_T heading_MABx_h;             /* '<S12>/MATLAB Function4' */
  real32_T dx_dy_m[2];                 /* '<S12>/MATLAB Function3' */
  real32_T ds_Rear_axle_m;             /* '<S12>/MATLAB Function2' */
  real32_T d_heading_deg;              /* '<S12>/MATLAB Function2' */
  real32_T direction;                  /* '<S12>/MATLAB Function' */
  real32_T whl_angl_a;                 /* '<S12>/linear_gain' */
  real32_T Product_g;                  /* '<S12>/Product' */
  real32_T MinMax1_e;                  /* '<S35>/MinMax1' */
  real32_T MinMax1_a;                  /* '<S36>/MinMax1' */
  real32_T APX_Park_Stat;              /* '<S25>/SC_ParkingManeuverMgr1' */
  real32_T NewPathAccepted;            /* '<S25>/SC_ParkingManeuverMgr1' */
  real32_T regen_count;                /* '<S25>/SC_ParkingManeuverMgr1' */
  real32_T APC_Debug_Park_Stat;        /* '<S25>/SC_ParkingManeuverMgr1' */
  real32_T In1[8];                     /* '<S28>/In1' */
  real32_T PS_move;                    /* '<S23>/ChackParkingSpaceChangeFunc' */
  real32_T x_deviation_temp;           /* '<S23>/ChackParkingSpaceChangeFunc' */
  real32_T Product_hk;                 /* '<S1>/Product' */
  real32_T Product3;                   /* '<S1>/Product3' */
  real32_T Delay8[2];                  /* '<S12>/Delay8' */
  real32_T sampletime_l;               /* '<S71>/sample time' */
  real32_T sampletime_h;               /* '<S72>/sample time' */
  real32_T sampletime_p;               /* '<S14>/sample time' */
  real32_T Gain;                       /* '<S115>/Gain' */
  real32_T Sign;                       /* '<S12>/Sign' */
  real32_T TmpSignalConversionAtSFunctionInport2_j[8];/* '<S23>/ChackParkingSpaceChangeFunc' */
  real32_T DataTypeConversion_o;       /* '<S1>/Data Type Conversion' */
  real32_T DataTypeConversion1_e;      /* '<S1>/Data Type Conversion1' */
  real32_T DataTypeConversion7;        /* '<S1>/Data Type Conversion7' */
  real32_T DataTypeConversion8;        /* '<S1>/Data Type Conversion8' */
  real32_T Product1;                   /* '<S1>/Product1' */
  real32_T Product2_b;                 /* '<S1>/Product2' */
  real32_T Saturation_Speed;           /* '<S113>/Saturation_Speed' */
  real32_T damping_gain_table;         /* '<S18>/damping_gain_table' */
  real32_T Product3_o;                 /* '<S18>/Product3' */
  real32_T Abs1_p;                     /* '<S1>/Abs1' */
  real32_T DiscreteTimeIntegrator_ll;  /* '<S111>/Discrete-Time Integrator' */
  real32_T StrTqFB_Old;                /* '<S18>/Add' */
  real32_T Delay1;                     /* '<S3>/Delay1' */
  real32_T virtual_point_length_m;
  real32_T lookahead_long;
  real32_T lookahead_dist_wp;
  real32_T absx;
  real32_T init_wheel_angle;
  real32_T alpha_clothoid;
  real32_T alpha_clothoid_old;
  real32_T y_fin_no_str;
  real32_T vectorLength;
  real32_T line_direction_idx_0;
  real32_T line_direction_idx_1;
  real32_T W2_idx_0;
  real32_T pps_idx_0;
  real32_T pps_idx_6;
  real32_T X_idx_0;
  real32_T Phi_idx_0;
  real32_T Phi_idx_1;
  real32_T line_direction_idx_0_tmp;
  real32_T init_wheel_angle_h;
  real32_T alpha_clothoid_m;
  real32_T alpha_clothoid_old_m;
  real32_T extremum;
  real32_T heading_2;
  real32_T PS_play_room_max;
  real32_T str_whl_ang_para;
  real32_T rear_X;
  real32_T front_X;
  real32_T PS_play_room;
  real32_T temp;
  real32_T final_point_idx_0;
  real32_T pp_tail_idx_0;
  real32_T pp_tail_idx_1;
  real32_T init_wheel_angle_h3;
  real32_T extremum_c;
  real32_T h;
  real32_T l;
  real32_T regen_mode_fb_tmp;
  real32_T angle_end;
  real32_T turn_radius_para;
  real32_T heading_angle_change;
  real32_T step_size;
  real32_T angle;
  real32_T angle_bound;
  real32_T veh_heading;
  real32_T d_k;
  real32_T f;
  real32_T h_p;
  real32_T n;
  real32_T o;
  real32_T p;
  real32_T y_p;
  real32_T angle_end_p;
  real32_T turn_radius_para_a;
  real32_T heading_angle_change_j;
  real32_T step_size_e;
  real32_T angle_o;
  real32_T angle_bound_b;
  real32_T veh_heading_a;
  real32_T e;
  real32_T g;
  real32_T m;
  real32_T n_g;
  real32_T o_e;
  real32_T x_f;
  real32_T c_center_idx_0;
  real32_T angle_end_h;
  real32_T turn_radius_para_e;
  real32_T heading_angle_change_c;
  real32_T step_size_a;
  real32_T angle_d;
  real32_T angle_bound_a;
  real32_T veh_heading_p;
  real32_T e_m;
  real32_T g_o;
  real32_T m_n;
  real32_T n_l;
  real32_T o_p;
  real32_T x_p;
  real32_T c_center_idx_0_f;
  real32_T h_tmp_tmp;
  real32_T step_size_i;
  real32_T theta_rotation;
  real32_T i_o;
  real32_T alpha1;
  real32_T alpha2;
  real32_T alpha3;
  real32_T beta1;
  real32_T x_max;
  real32_T a;
  real32_T b_W2;
  real32_T b_W0_idx_1;
  real32_T b_W1_idx_1;
  real32_T b_W0_idx_0;
  real32_T Rot_tmp_tmp;
  real32_T kappa_num_tmp;
  real32_T kappa_num_tmp_k;
  real32_T kappa_num_tmp_i;
  real32_T kappa_num_tmp_o;
  real32_T kappa_num_tmp_m;
  real32_T line_direction_idx_0_tmp_c;
  real32_T step_size_f;
  real32_T theta_rotation_h;
  real32_T i_m;
  real32_T alpha1_a;
  real32_T alpha2_k;
  real32_T alpha3_p;
  real32_T beta1_b;
  real32_T a_c;
  real32_T Rot_n;
  real32_T Rot_i;
  real32_T Rot_idx_0;
  real32_T kappa_num_I_idx_1;
  real32_T Rot_tmp_tmp_m;
  real32_T kappa_num_data_tmp;
  real32_T kappa_num_data_tmp_j;
  real32_T kappa_num_data_tmp_e;
  real32_T kappa_num_data_tmp_m;
  real32_T kappa_num_data_tmp_m0;
  int32_T c;
  int32_T k;
  int32_T i_j;
  int32_T i_size;
  int32_T loop_ub;
  int32_T O_WPSweepN_tmp;
  int32_T i_f;
  int32_T fxoi_size;
  int32_T fyoi_size;
  int32_T fhoi_size;
  int32_T fvoi_size;
  int32_T fsoi_size;
  int32_T des_wheel_angle;
  int32_T g_i;
  int32_T yb_i;
  int32_T dc_i;
  int32_T i_a;
  int32_T dfy_size;
  int32_T veh_params_size;
  int32_T tmp_size_g;
  int32_T pp_tmp;
  int32_T i1;
  int32_T fxoi_size_n;
  int32_T fyoi_size_d;
  int32_T fhoi_size_n;
  int32_T fvoi_size_c;
  int32_T fsoi_size_f;
  int32_T b_counter;
  int32_T i_p;
  int32_T dfy_size_p;
  int32_T veh_params_size_n;
  int32_T tmp_size_k;
  int32_T i2;
  int32_T i3;
  int32_T park_out_segment;
  int32_T pp_tmp_n;
  int32_T P0_idx_0_tmp;
  int32_T P0_idx_1_tmp;
  int32_T i4;
  int32_T counter;
  int32_T h_i;
  int32_T i_i;
  int32_T i5;
  int32_T pp_tmp_o;
  int32_T fxo_data_tmp;
  int32_T idx;
  int32_T c_k;
  int32_T idx_g;
  int32_T c_k_c;
  uint32_T qY;
  uint32_T qY_tmp;
  uint32_T qY_c;
  uint32_T qY_m;
  uint32_T qY_j;
  uint32_T qY_k;
  uint32_T qY_mx;
  uint32_T qY_p;
  uint32_T qY_d;
  uint32_T qY_g;
  uint32_T qY_c3;
  uint32_T qY_tmp_c;
  uint32_T qY_tmp_i;
  uint32_T qY_tmp_d;
  TeAP_e_WhlBas RateTransition19;      /* '<S1>/Rate Transition19' */
  TeAP_e_SteerRatRackPinionTyp RateTransition20;/* '<S1>/Rate Transition20' */
  uint16_T RateTransition21;           /* '<S1>/Rate Transition21' */
  uint16_T DataTypeConversion1_m;      /* '<S125>/Data Type Conversion1' */
  uint16_T CollDistReduc;              /* '<S124>/Saturation1' */
  uint16_T RemainDistFromCollDist;     /* '<S127>/Saturation' */
  uint16_T In1_l;                      /* '<S129>/In1' */
  uint16_T In1_k;                      /* '<S128>/In1' */
  uint16_T CollDist;                   /* '<S124>/Switch6' */
  uint16_T Add_f;                      /* '<S127>/Add' */
  uint16_T DataTypeConversion5;        /* '<S124>/Data Type Conversion5' */
  uint16_T Add_h;                      /* '<S16>/Add' */
  uint16_T Gain_a;                     /* '<S16>/Gain' */
  int16_T Gain_l;                      /* '<S13>/Gain' */
  int16_T RateTransition18;            /* '<S1>/Rate Transition18' */
  int16_T RateTransition12;            /* '<S1>/Rate Transition12' */
  int16_T Delay1_f;                    /* '<S12>/Delay1' */
  int16_T Delay2;                      /* '<S12>/Delay2' */
  int16_T fi[10];                      /* '<S59>/Chart1' */
  uint8_T Delay;                       /* '<S21>/Delay' */
  uint8_T RateTransition1;             /* '<S13>/Rate Transition1' */
  uint8_T UnitDelay1_m;                /* '<S13>/Unit Delay1' */
  uint8_T UnitDelay2;                  /* '<S13>/Unit Delay2' */
  uint8_T RateTransition15;            /* '<S1>/Rate Transition15' */
  uint8_T MeAP_I_GearRpt;              /* '<S20>/Multiport Switch' */
  uint8_T RateTransition8;             /* '<S1>/Rate Transition8' */
  uint8_T RateTransition1_a;           /* '<S21>/Rate Transition1' */
  uint8_T Memory;                      /* '<S111>/Memory' */
  uint8_T CurrentSweep;                /* '<S82>/CurrentSweep' */
  uint8_T wp_lastsweeps;               /* '<S82>/Signal Conversion' */
  uint8_T wp_N;                        /* '<S82>/Signal Conversion' */
  uint8_T O_WPlastSweeps;           /* '<S82>/MATLAB Function PathSeparation' */
  uint8_T O_WPSweepN;               /* '<S82>/MATLAB Function PathSeparation' */
  uint8_T Current_waypoint;            /* '<S80>/Signal Conversion' */
  uint8_T curr_wp_l;                   /* '<S83>/MATLAB Function' */
  uint8_T preview_wp;                  /* '<S83>/MATLAB Function' */
  uint8_T num_sweeps;                  /* '<S59>/Chart1' */
  uint8_T SwitchActive;                /* '<S13>/SwitchActive' */
  uint8_T CurrentSweepVeh;             /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T Compare;                     /* '<S69>/Compare' */
  uint8_T Compare_p;                   /* '<S68>/Compare' */
  uint8_T ColDist;                     /* '<S5>/Data Type Conversion5' */
  uint8_T UnitDelay;                   /* '<S30>/Unit Delay' */
  int8_T Delay_b;                      /* '<S1>/Delay' */
  int8_T UnitDelay3;                   /* '<S13>/Unit Delay3' */
  int8_T RateTransition2_j;            /* '<S13>/Rate Transition2' */
  int8_T RateTransition_j;             /* '<S26>/Rate Transition' */
  int8_T DataTypeConversion1_le;       /* '<S25>/Data Type Conversion1' */
  int8_T DelayOneStep;                 /* '<S108>/Delay One Step' */
  int8_T DataTypeConversion_a;         /* '<S13>/Data Type Conversion' */
  int8_T RateTransition_c;             /* '<S16>/Rate Transition' */
  int8_T Dir;                          /* '<S82>/Signal Conversion' */
  int8_T NextDir;                      /* '<S82>/Signal Conversion' */
  int8_T O_Dir;                     /* '<S82>/MATLAB Function PathSeparation' */
  int8_T O_NextDir;                 /* '<S82>/MATLAB Function PathSeparation' */
  int8_T DesiredDir;                   /* '<S25>/SC_ParkingManeuverMgr1' */
  int8_T NextDir_a;                    /* '<S82>/Data Type Conversion1' */
  boolean_T RateTransition7;           /* '<S1>/Rate Transition7' */
  boolean_T RateTransition14;          /* '<S1>/Rate Transition14' */
  boolean_T DataTypeConversion1_h;     /* '<S12>/Data Type Conversion1' */
  boolean_T LogicalOperator3;          /* '<S12>/Logical Operator3' */
  boolean_T RateTransition3;           /* '<S12>/Rate Transition3' */
  boolean_T LogicalOperator1;          /* '<S12>/Logical Operator1' */
  boolean_T UnitDelay_n;               /* '<S13>/Unit Delay' */
  boolean_T RateTransition3_i;         /* '<S13>/Rate Transition3' */
  boolean_T DataTypeConversion6;       /* '<S13>/Data Type Conversion6' */
  boolean_T Delay1_k;                  /* '<S21>/Delay1' */
  boolean_T LogicalOperator;           /* '<S26>/Logical Operator' */
  boolean_T LogicalOperator4;          /* '<S23>/Logical Operator4' */
  boolean_T Compare_n;                 /* '<S79>/Compare' */
  boolean_T RelationalOperator5;       /* '<S124>/Relational Operator5' */
  boolean_T LogicalOperator_i;         /* '<S130>/Logical Operator' */
  boolean_T UnitDelay_g;               /* '<S25>/Unit Delay' */
  boolean_T Delay1_d;                  /* '<S4>/Delay1' */
  boolean_T DataTypeConversion_m;      /* '<S25>/Data Type Conversion' */
  boolean_T CastToBoolean1;            /* '<S113>/Cast To Boolean1' */
  boolean_T CastToBoolean;             /* '<S113>/Cast To Boolean' */
  boolean_T Compare_i;                 /* '<S119>/Compare' */
  boolean_T RelOp;                     /* '<S113>/RelOp' */
  boolean_T LogicalOperator_c;         /* '<S1>/Logical Operator' */
  boolean_T Memory2;                   /* '<S111>/Memory2' */
  boolean_T LogicalOperator8;          /* '<S1>/Logical Operator8' */
  boolean_T DataTypeConversion1_o;     /* '<S23>/Data Type Conversion1' */
  boolean_T LogicalOperator2;          /* '<S30>/Logical Operator2' */
  boolean_T Compare_id;                /* '<S41>/Compare' */
  boolean_T LogicalOperator1_d;        /* '<S1>/Logical Operator1' */
  boolean_T LogicalOperator1_k;        /* '<S30>/Logical Operator1' */
  boolean_T RelationalOperator;        /* '<S75>/Relational Operator' */
  boolean_T LogicalOperator5;          /* '<S1>/Logical Operator5' */
  boolean_T LogicalOperator1_m;        /* '<S26>/Logical Operator1' */
  boolean_T LogicalOperator1_kg;       /* '<S24>/Logical Operator1' */
  boolean_T Compare_l;                 /* '<S42>/Compare' */
  boolean_T Compare_a;                 /* '<S44>/Compare' */
  boolean_T RelationalOperator3;       /* '<S75>/Relational Operator3' */
  boolean_T IeAP_b_StandstillReq;      /* '<Root>/Data Type Conversion14' */
  boolean_T CollDistRegen_out;         /* '<S124>/MATLAB Function2' */
  boolean_T sweep_end_flag;            /* '<S113>/MATLAB Function1' */
  boolean_T no_vel_flag;               /* '<S113>/MATLAB Function' */
  boolean_T new_dir_flag;              /* '<S108>/Gear_CMD_func' */
  boolean_T Compare_o;                 /* '<S96>/Compare' */
  boolean_T Compare_nm;                /* '<S103>/Compare' */
  boolean_T Compare_f;                 /* '<S106>/Compare' */
  boolean_T Compare_g;                 /* '<S70>/Compare' */
  boolean_T old_path;                  /* '<S59>/Chart1' */
  boolean_T ParkingFinished;           /* '<S25>/SC_ParkingManeuverMgr1' */
  boolean_T PS_Exc;                    /* '<S23>/ChackParkingSpaceChangeFunc' */
  boolean_T LogicalOperator10;         /* '<S1>/Logical Operator10' */
  boolean_T Compare_gr;                /* '<S9>/Compare' */
  boolean_T Compare_a1;                /* '<S7>/Compare' */
  boolean_T RelationalOperator1;       /* '<S1>/Relational Operator1' */
  boolean_T LogicalOperator9;          /* '<S1>/Logical Operator9' */
  boolean_T RelationalOperator1_p;     /* '<S124>/Relational Operator1' */
  boolean_T u_GT_lo;                   /* '<S116>/u_GT_lo' */
  boolean_T Compare_m;                 /* '<S102>/Compare' */
  boolean_T Compare_o1;                /* '<S99>/Compare' */
  boolean_T RelationalOperator2;       /* '<S75>/Relational Operator2' */
  boolean_T Compare_k[14];             /* '<S37>/Compare' */
  boolean_T Compare_fj[14];            /* '<S39>/Compare' */
  boolean_T Compare_b;                 /* '<S33>/Compare' */
  boolean_T LogicalOperator4_j;        /* '<S1>/Logical Operator4' */
  boolean_T LogicalOperator7;          /* '<S1>/Logical Operator7' */
  boolean_T LogicalOperator2_a;        /* '<S26>/Logical Operator2' */
  boolean_T LogicalOperator3_p;        /* '<S26>/Logical Operator3' */
  boolean_T RelationalOperator1_a;     /* '<S24>/Relational Operator1' */
  boolean_T Compare_lw;                /* '<S67>/Compare' */
  boolean_T UpperRelop;                /* '<S65>/UpperRelop' */
} B_SWC_VC_c_T;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

/* Block states (default storage) for model 'SWC_VC' */
#ifndef SWC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  real_T Delay5_DSTATE;                /* '<S12>/Delay5' */
  real_T Delay1_DSTATE;                /* '<S13>/Delay1' */
  real_T UnitDelay_DSTATE;             /* '<S22>/Unit Delay' */
  real_T DelayInput2_DSTATE;           /* '<S122>/Delay Input2' */
  real_T Delay1_DSTATE_c[15];          /* '<S1>/Delay1' */
  real_T Sum_DWORK1;                   /* '<S113>/Sum' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S4>/Scope' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S21>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S108>/Scope1' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S108>/Scope3' */

  struct {
    void *LoggedData[2];
  } Scope5_PWORK;                      /* '<S108>/Scope5' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S111>/Scope10' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S111>/Scope8' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S108>/Scope2' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S111>/Scope7' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S111>/Scope9' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_j;                    /* '<S111>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_b;                     /* '<S108>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_e;                    /* '<S111>/Scope2' */

  struct {
    void *LoggedData;
  } Scope8_PWORK_d;                    /* '<S25>/Scope8' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_e;                    /* '<S25>/Scope4' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S25>/Scope6' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_j;                    /* '<S108>/Scope4' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_f;                    /* '<S26>/Scope1' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_d;                    /* '<S21>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK_c;                     /* '<S21>/Scope' */

  struct {
    void *LoggedData;
  } Scope_PWORK_by;                    /* '<S57>/Scope' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_l;                    /* '<S13>/Scope2' */

  struct {
    void *LoggedData;
  } Scope_PWORK_o;                     /* '<S12>/Scope' */

  struct {
    void *LoggedData;
  } Scope5_PWORK_h;                    /* '<S21>/Scope5' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_p;                    /* '<S21>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_d;                    /* '<S21>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_j;                     /* '<S26>/Scope' */

  struct {
    void *LoggedData;
  } Scope1_PWORK_i;                    /* '<S115>/Scope1' */

  struct {
    void *LoggedData;
  } Scope4_PWORK_m;                    /* '<S115>/Scope4' */

  struct {
    void *LoggedData;
  } Scope6_PWORK_d;                    /* '<S115>/Scope6' */

  struct {
    void *LoggedData;
  } Scope2_PWORK_o;                    /* '<S115>/Scope2' */

  struct {
    void *LoggedData;
  } Scope3_PWORK_dl;                   /* '<S115>/Scope3' */

  struct {
    void *LoggedData;
  } Scope_PWORK_jx;                    /* '<S83>/Scope' */

  real32_T Delay8_DSTATE[2];           /* '<S12>/Delay8' */
  real32_T DiscreteTimeIntegrator1_DSTATE[2];/* '<S12>/Discrete-Time Integrator1' */
  real32_T DiscreteTimeIntegrator_DSTATE;/* '<S12>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator_DSTATE_d;/* '<S113>/Discrete-Time Integrator' */
  real32_T DiscreteTimeIntegrator2_DSTATE;/* '<S113>/Discrete-Time Integrator2' */
  real32_T DiscreteTimeIntegrator_DSTATE_p;/* '<S111>/Discrete-Time Integrator' */
  real32_T UnitDelay1_DSTATE;          /* '<S30>/Unit Delay1' */
  real32_T DelayInput2_DSTATE_i;       /* '<S71>/Delay Input2' */
  real32_T DelayInput2_DSTATE_d;       /* '<S72>/Delay Input2' */
  real32_T DiscreteTimeIntegrator_DSTATE_b;/* '<S18>/Discrete-Time Integrator' */
  real32_T UnitDelay1_DSTATE_e;        /* '<S18>/Unit Delay1' */
  real32_T DelayInput2_DSTATE_o;       /* '<S14>/Delay Input2' */
  real32_T Delay_DSTATE;               /* '<S3>/Delay' */
  real32_T Delay1_DSTATE_j;            /* '<S3>/Delay1' */
  real32_T UnitDelay1_DSTATE_f;        /* '<S115>/Unit Delay1' */
  real32_T DelayOneStep_DSTATE;        /* '<S84>/Delay One Step' */
  real32_T Memory1_PreviousInput;      /* '<S111>/Memory1' */
  real32_T Add5_DWORK1;                /* '<S107>/Add5' */
  real32_T PSL[8];                     /* '<S59>/Chart1' */
  real32_T tfR[3];                     /* '<S59>/Chart1' */
  real32_T emL[5];                     /* '<S59>/Chart1' */
  real32_T LeftPS;                     /* '<S59>/Chart1' */
  real32_T p_guide[30];                /* '<S59>/Chart1' */
  real32_T regen_mode;                 /* '<S59>/Chart1' */
  real32_T fx_old[250];                /* '<S59>/Chart1' */
  real32_T fy_old[250];                /* '<S59>/Chart1' */
  real32_T fh_old[250];                /* '<S59>/Chart1' */
  real32_T fs_old[250];                /* '<S59>/Chart1' */
  real32_T fv_old[250];                /* '<S59>/Chart1' */
  real32_T fi_old[10];                 /* '<S59>/Chart1' */
  int32_T Add2_DWORK1;                 /* '<S124>/Add2' */
  uint32_T Add_DWORK1;                 /* '<S16>/Add' */
  int16_T Delay1_DSTATE_n;             /* '<S12>/Delay1' */
  int16_T Delay2_DSTATE;               /* '<S12>/Delay2' */
  uint16_T counter_fishbone;           /* '<S25>/SC_ParkingManeuverMgr1' */
  uint16_T temporalCounter_i1;         /* '<S25>/SC_ParkingManeuverMgr1' */
  int8_T Delay_DSTATE_n;               /* '<S1>/Delay' */
  int8_T UnitDelay3_DSTATE;            /* '<S13>/Unit Delay3' */
  int8_T DelayOneStep_DSTATE_c;        /* '<S108>/Delay One Step' */
  uint8_T Delay_DSTATE_a;              /* '<S21>/Delay' */
  uint8_T UnitDelay1_DSTATE_b;         /* '<S13>/Unit Delay1' */
  uint8_T UnitDelay2_DSTATE;           /* '<S13>/Unit Delay2' */
  uint8_T UnitDelay_DSTATE_j;          /* '<S131>/Unit Delay' */
  uint8_T UnitDelay_DSTATE_b;          /* '<S30>/Unit Delay' */
  boolean_T Delay4_DSTATE;             /* '<S12>/Delay4' */
  boolean_T Delay7_DSTATE;             /* '<S12>/Delay7' */
  boolean_T Delay6_DSTATE;             /* '<S12>/Delay6' */
  boolean_T UnitDelay_DSTATE_d;        /* '<S13>/Unit Delay' */
  boolean_T Delay1_DSTATE_e;           /* '<S21>/Delay1' */
  boolean_T UnitDelay_DSTATE_l;        /* '<S25>/Unit Delay' */
  boolean_T Delay1_DSTATE_a;           /* '<S4>/Delay1' */
  boolean_T Delay_DSTATE_h;            /* '<S26>/Delay' */
  boolean_T Delay1_DSTATE_jj;          /* '<S113>/Delay1' */
  boolean_T Delay_DSTATE_e;            /* '<S113>/Delay' */
  boolean_T DelayInput1_DSTATE;        /* '<S11>/Delay Input1' */
  int8_T DiscreteTimeIntegrator1_PrevResetState;/* '<S12>/Discrete-Time Integrator1' */
  int8_T DiscreteTimeIntegrator_PrevResetState;/* '<S12>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator_PrevResetState_g;/* '<S113>/Discrete-Time Integrator' */
  int8_T DiscreteTimeIntegrator2_PrevResetState;/* '<S113>/Discrete-Time Integrator2' */
  int8_T DiscreteTimeIntegrator_PrevResetState_f;/* '<S18>/Discrete-Time Integrator' */
  int8_T c1;                           /* '<S59>/Chart1' */
  uint8_T icLoad;                      /* '<S12>/Delay1' */
  uint8_T icLoad_l;                    /* '<S12>/Delay2' */
  uint8_T Memory_PreviousInput;        /* '<S111>/Memory' */
  uint8_T DiscreteTimeIntegrator_IC_LOADING;/* '<S18>/Discrete-Time Integrator' */
  uint8_T is_active_c43_SWC_VC;        /* '<S59>/Chart1' */
  uint8_T is_c43_SWC_VC;               /* '<S59>/Chart1' */
  uint8_T tp_APX_Park_State_Inactive_ST1;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Inactive_ST;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Active_ST; /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_R_gear;    /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_End_ST;    /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_AllStrokes_ST;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backw_DispForw;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_R_gear_o;  /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backward;  /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backw_DeviationExceeded;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forw_DispBackw1;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backw_RegenPathStarted;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forw_PathAccepted;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backw_PathAccepted;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forw_RegenPathStarted;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Backw_DispForw1;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forw_DeviationExceeded;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forward;   /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_Forw_DispBackw;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T tp_APX_Park_State_D_gear;    /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T is_active_c25_SWC_VC;        /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T is_c25_SWC_VC;               /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T is_APX_Park_State_Active_ST; /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T is_APX_Park_State_AllStrokes_ST;/* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T C_APX_PARK_STAT_FIELD[10];   /* '<S25>/SC_ParkingManeuverMgr1' */
  uint8_T regen_on_fly_counter;        /* '<S25>/SC_ParkingManeuverMgr1' */
  boolean_T Memory2_PreviousInput;     /* '<S111>/Memory2' */
  boolean_T Control_MODE;              /* '<S21>/Control' */
  boolean_T Subsystem1_MODE;           /* '<S1>/Subsystem1' */
} DW_SWC_VC_f_T;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

/* Zero-crossing (trigger) state for model 'SWC_VC' */
#ifndef SWC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  ZCSigState PathSeparation_Trig_ZCE;  /* '<S21>/PathSeparation' */
  ZCSigState RemainDistAtPreCollFlagEntry_Trig_ZCE;
                                     /* '<S127>/RemainDistAtPreCollFlagEntry' */
  ZCSigState CollDistAtPreCollFlagEntry_Trig_ZCE;/* '<S127>/CollDistAtPreCollFlagEntry' */
} ZCE_SWC_VC_T;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

/* Invariant block signals for model 'SWC_VC' */
#ifndef SWC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  const real_T Gain;                   /* '<S19>/Gain' */
  const real_T alpha;                  /* '<S22>/Divide' */
  const real_T one_minus_alpha;        /* '<S22>/Add' */
  const real32_T DataTypeConversion3;  /* '<S5>/Data Type Conversion3' */
  const real32_T heading_init;         /* '<S12>/heading_init' */
  const real32_T xy_init[2];           /* '<S12>/xy_init' */
  const real32_T DataTypeConversion2;  /* '<S18>/Data Type Conversion2' */
  const real32_T Gain4;                /* '<S18>/Gain4' */
  const real32_T DataTypeConversion22; /* '<S111>/Data Type Conversion22' */
  const real32_T DataTypeConversion4;  /* '<S111>/Data Type Conversion4' */
  const uint8_T IeAP_cnt_CurrentVehSweep;/* '<Root>/Constant1' */
  const boolean_T Compare;             /* '<S54>/Compare' */
  const boolean_T IeAP_b_MnvPosOk;     /* '<Root>/Constant8' */
} ConstB_SWC_VC_h_T;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

#ifndef SWC_VC_MDLREF_HIDE_CHILD_

/* Real-time Model Data Structure */
struct tag_RTM_SWC_VC_T {
  const char_T **errorStatus;
};

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

#ifndef SWC_VC_MDLREF_HIDE_CHILD_

typedef struct {
  RT_MODEL_SWC_VC_T rtm;
} MdlrefDW_SWC_VC_T;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

extern void SWC_VC_Init(void);
extern void SWC_VC_Start(void);
extern void SWC_VC_Disable(void);
extern void SWC_VC(const int16_T *rtu_MeAP_I_WhlPosRR, const int16_T
                   *rtu_MeAP_I_WhlPosRL, const uint8_T *rtu_MeAP_I_GearRpt,
                   const boolean_T *rtu_MeAP_b_VCActive, const boolean_T
                   *rtu_MeAP_b_ParkOut, const boolean_T *rtu_MeAP_b_ResetVCKM,
                   const TbNVM_ProxyCalibParam *rtu_MbNVM_ProxyParam, const
                   real32_T *rtu_MeAP_cm_CDminDist, const boolean_T
                   *rtu_MeAP_b_VCOpPaused, const boolean_T
                   *rtu_IeVBII_b_ActvParkMode, const uint16_T
                   *rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth, const
                   int16_T *rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj,
                   const int16_T
                   *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const
                   int16_T *rtu_IeVBII_deg_StrWhlSpd, real32_T
                   *rty_MeAP_deg_StrCmd, real32_T *rty_MeAP_a_BrkCmd, real32_T
                   *rty_MeAP_a_ThrtlCmd, int32_T *rty_IeAP_e_TurnIndicReq,
                   real32_T *rty_IeAP_nm_StrwTrqReq, real32_T
                   *rty_IeAP_a_DecelMax, real32_T *rty_IeAP_a_DecelMin, real32_T
                   *rty_IeAP_a_JerkDecelMax, real32_T *rty_IeAP_a_JerkDecelMin,
                   real32_T *rty_IeAP_a_AcclMin, real32_T *rty_IeAP_a_AcclMax,
                   real32_T *rty_IeAP_da_JerkAcclMax, real32_T
                   *rty_IeAP_da_JerkAcclMin, boolean_T *rty_IeAP_b_StandstillReq,
                   real32_T *rty_IeAP_cm_TrgtDist, boolean_T
                   *rty_MeAP_b_ManeuverAbort, boolean_T
                   *rty_MeAP_b_ManeuverSuccess, int8_T *rty_MeAP_e_PP_state,
                   real32_T *rty_MeAP_e_Park_state, real32_T
                   rty_MaAP_m_PlannerWayPointsX[250], real32_T
                   rty_MaAP_m_PlannerWayPointsY[250], boolean_T
                   *rty_MeAP_b_PosMet, boolean_T *rty_MeAP_b_SteerActionReq,
                   real32_T *rty_IeAP_kph_TrgtVehSpd, TeAutoPark_e_GearCmd
                   *rty_MeAP_e_GearCmd, real32_T *rty_IbVC_DebugOut_X_MABx,
                   real32_T *rty_IbVC_DebugOut_Y_MABx, real32_T
                   *rty_IbVC_DebugOut_heading_MABx, real32_T
                   *rty_IbVC_DebugOut_Str_Trq_CMD, real32_T
                   *rty_IbVC_DebugOut_VC_RemainingDist, real32_T
                   *rty_IbVC_DebugOut_VC_PathDev, real32_T
                   *rty_IbVC_DebugOut_VC_Head_Dev, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSX, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSY, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBX, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBY, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSX, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSY, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBX, real32_T
                   *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBY, uint8_T
                   *rty_IbVC_DebugOut_PM_CurrentSweep, boolean_T
                   *rty_IbVC_DebugOut_PM_RegenPath);

/* Model reference registration function */
extern void SWC_VC_initialize(const char_T **rt_errorStatus);

/* Exported data declaration */

/* Declaration for custom storage class: Default */
extern boolean_T ACT_ACTIVE;        /* '<S1>/Decativate VC if planner failed' */
extern uint8_T Ap_App_ID;              /* '<S1>/Constant' */
extern real32_T DS_ANGLE;
extern real32_T DS_WheelSpeed_RL;
extern real32_T DS_WheelSpeed_RR;
extern real32_T KeAP_M_StrTrqValLimit;
                           /* Referenced by: '<S18>/Constant_SaturationLimit' */
extern real32_T KeAP_deg_SteerAngelDiffThd;/* Referenced by: '<S6>/Constant' */
extern real32_T KeAP_nm_TrqCmdRateLimThd;
                                  /* Referenced by: '<S1>/Constant_RateLimit' */
extern real32_T KsAP_k_DGainLUT_TD_55C[4];
                            /* Referenced by: '<S18>/differential_gain_table' */
extern real32_T KsAP_k_DGainLUT_TD_63C[4];
                           /* Referenced by: '<S18>/differential_gain_table1' */
extern real32_T KsAP_k_DampingGainTD[4];
                                 /* Referenced by: '<S18>/damping_gain_table' */
extern real32_T KsAP_k_IGainLUT_TD_55C[4];
                              /* Referenced by: '<S18>/integrator_gain_table' */
extern real32_T KsAP_k_IGainLUT_TD_63C[4];
                             /* Referenced by: '<S18>/integrator_gain_table1' */
extern real32_T KsAP_k_IntegratorExtSatTD[4];
               /* Referenced by: '<S18>/integrator_external_saturation_table' */
extern real32_T KsAP_k_PGainLUT_TD_55C[20];
                               /* Referenced by: '<S18>/P_gain_lookup_table3' */
extern real32_T KsAP_k_PGainLUT_TD_60C[20];
                               /* Referenced by: '<S18>/P_gain_lookup_table2' */
extern real32_T KsAP_k_PGainLUT_TD_63C[20];/* Referenced by:
                                            * '<S18>/P_gain_lookup_table4'
                                            * '<S18>/P_gain_lookup_table_Veh98_Veh54'
                                            */
extern real32_T MaAP_m_ParkSpot1FrntStreetX;
extern real32_T MaAP_m_ParkSpot1FrntStreetY;
extern real32_T MaAP_m_ParkSpot2FrntBorderX;
extern real32_T MaAP_m_ParkSpot2FrntBorderY;
extern real32_T MaAP_m_ParkSpot3RearBorderX;
extern real32_T MaAP_m_ParkSpot3RearBorderY;
extern real32_T MaAP_m_ParkSpot4RearStreetX;
extern real32_T MaAP_m_ParkSpot4RearStreetY;
extern real32_T Ma_AP_I_PSLimFBX;      /* '<S1>/Add1' */
extern real32_T Ma_AP_I_PSLimFBY;      /* '<S1>/Add5' */
extern real32_T Ma_AP_I_PSLimFSX;      /* '<S1>/Add' */
extern real32_T Ma_AP_I_PSLimFSY;      /* '<S1>/Add4' */
extern real32_T Ma_AP_I_PSLimRBX;      /* '<S1>/Add2' */
extern real32_T Ma_AP_I_PSLimRBY;      /* '<S1>/Add6' */
extern real32_T Ma_AP_I_PSLimRSX;      /* '<S1>/Add3' */
extern real32_T Ma_AP_I_PSLimRSY;      /* '<S1>/Add7' */
extern boolean_T MeAP_b_PosMet;        /* '<S8>/Compare' */
extern boolean_T MeAP_b_SteerActionReq;/* '<S6>/Compare' */
extern real32_T MeAP_deg_strAngtoWhlAng;/* '<S51>/Multiport Switch' */
extern TeAutoPark_e_GearCmd MeAP_e_GearCmd;/* '<Root>/Data Type Conversion7' */
extern boolean_T MeAP_k_PerpNoseIn;
extern real32_T MeAP_m_PlanminRadius;  /* '<S64>/Multiport Switch' */
extern real32_T MeAP_m_VehFrontOverhang;/* '<S61>/Subtract' */
extern real32_T MeAP_m_VehRearOverhang;/* '<S61>/Product1' */
extern real32_T MeAP_m_VehWheelbase;   /* '<S63>/Multiport Switch' */
extern real32_T MeAP_m_VehWidth;       /* '<S61>/Product' */
extern real32_T MeAP_m_WhlBase;        /* '<S52>/Multiport Switch' */
extern real32_T MeAP_m_WhlCircum;      /* '<S12>/Gain' */
extern real32_T MeAP_pm_maxCurvature;  /* '<S62>/Multiport Switch' */
extern uint8_T PM_CurrentSweep;        /* '<S25>/SC_ParkingManeuverMgr1' */
extern boolean_T PM_RegenPath;         /* '<S25>/SC_ParkingManeuverMgr1' */
extern boolean_T PP_Abort;             /* '<S59>/Chart1' */
extern real32_T PP_H[250];             /* '<S13>/Data Type Conversion10' */
extern int8_T PP_state;                /* '<S59>/Chart1' */
extern real32_T PP_x[250];             /* '<S13>/Data Type Conversion5' */
extern real32_T PP_y[250];             /* '<S13>/Data Type Conversion9' */
extern uint8_T PSType;
extern real32_T VC_Head_Dev;           /* '<S80>/Signal Conversion' */
extern real32_T VC_PathDev;            /* '<S80>/Signal Conversion' */
extern real32_T VC_RemainingDist;      /* '<S109>/Data Type Conversion12' */
extern real32_T VC_Steer_CMD;          /* '<S80>/Signal Conversion' */
extern real32_T X_MABx;                /* '<S1>/Data Type Conversion2' */
extern real32_T Y_MABx;                /* '<S1>/Data Type Conversion3' */
extern real32_T heading_MABx;          /* '<S1>/Data Type Conversion4' */
extern uint8_T parkout_perp_left;

/* Const memory section */
/* Declaration for custom storage class: Const */
extern const real32_T KeAP_CurbLim_para[3];/* Referenced by: '<S59>/Chart1' */
extern const real32_T KeAP_break_point_para[2];/* Referenced by: '<S59>/Chart1' */
extern const real32_T KeAP_break_point_perp[2];/* Referenced by: '<S59>/Chart1' */
extern const real32_T KeAP_fin_loc_para_out[2];/* Referenced by: '<S59>/Chart1' */
extern const real32_T KeAP_p3_adj_perp[2];/* Referenced by: '<S59>/Chart1' */
extern const real32_T KeAP_str_profile_bigPS[34];/* Referenced by: '<S59>/Chart1' */
extern const real32_T step_size_coeff[6];/* Referenced by: '<S59>/Chart1' */
extern const real32_T str_whl_ang_park_out;/* Referenced by: '<S59>/Chart1' */

#ifndef SWC_VC_MDLREF_HIDE_CHILD_

extern MdlrefDW_SWC_VC_T SWC_VC_MdlrefDW;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

#ifndef SWC_VC_MDLREF_HIDE_CHILD_

/* Block signals (default storage) */
extern B_SWC_VC_c_T SWC_VC_B;

/* Block states (default storage) */
extern DW_SWC_VC_f_T SWC_VC_DW;

/* Previous zero-crossings (trigger) states */
extern ZCE_SWC_VC_T SWC_VC_PrevZCX;

#endif                                 /*SWC_VC_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'SWC_VC'
 * '<S1>'   : 'SWC_VC/FCA_AutoPark_VC2'
 * '<S2>'   : 'SWC_VC/Model Info'
 * '<S3>'   : 'SWC_VC/VC_OutputArbitration1'
 * '<S4>'   : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager'
 * '<S5>'   : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection'
 * '<S6>'   : 'SWC_VC/FCA_AutoPark_VC2/Compare To Constant'
 * '<S7>'   : 'SWC_VC/FCA_AutoPark_VC2/Compare To Constant1'
 * '<S8>'   : 'SWC_VC/FCA_AutoPark_VC2/Compare To Constant2'
 * '<S9>'   : 'SWC_VC/FCA_AutoPark_VC2/Compare To Constant3'
 * '<S10>'  : 'SWC_VC/FCA_AutoPark_VC2/Decativate VC if planner failed'
 * '<S11>'  : 'SWC_VC/FCA_AutoPark_VC2/Detect Rise Positive'
 * '<S12>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1'
 * '<S13>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner'
 * '<S14>'  : 'SWC_VC/FCA_AutoPark_VC2/Rate Limiter Dynamic'
 * '<S15>'  : 'SWC_VC/FCA_AutoPark_VC2/Spot manipulation'
 * '<S16>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem'
 * '<S17>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem1'
 * '<S18>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl'
 * '<S19>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl_PreProcessor'
 * '<S20>'  : 'SWC_VC/FCA_AutoPark_VC2/VC_GearConversion'
 * '<S21>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1'
 * '<S22>'  : 'SWC_VC/FCA_AutoPark_VC2/low_pass_filter 1'
 * '<S23>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/CheckParkSpaceChange'
 * '<S24>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/CheckPathOrntDeviation'
 * '<S25>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/ParkingManeucerManager_SM'
 * '<S26>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/checkPathAvailability'
 * '<S27>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/CheckParkSpaceChange/ChackParkingSpaceChangeFunc'
 * '<S28>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/CheckParkSpaceChange/Enabled Subsystem'
 * '<S29>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/ParkingManeucerManager_SM/SC_ParkingManeuverMgr1'
 * '<S30>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/ParkingManeucerManager_SM/newStroke'
 * '<S31>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/ParkingManeucerManager_SM/newStroke/Compare To Zero'
 * '<S32>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/ParkingManeucerManager_SM/newStroke/Compare To Zero1'
 * '<S33>'  : 'SWC_VC/FCA_AutoPark_VC2/ADASManeuverManager/checkPathAvailability/Compare To Constant'
 * '<S34>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Compare To Constant'
 * '<S35>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Front'
 * '<S36>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Rear1'
 * '<S37>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Front/Compare To Zero'
 * '<S38>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Front/MATLAB Function'
 * '<S39>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Rear1/Compare To Zero'
 * '<S40>'  : 'SWC_VC/FCA_AutoPark_VC2/CollisionDetection/Subsystem_Rear1/MATLAB Function'
 * '<S41>'  : 'SWC_VC/FCA_AutoPark_VC2/Detect Rise Positive/Positive'
 * '<S42>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/Compare To Zero'
 * '<S43>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/Compare To Zero1'
 * '<S44>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/Compare To Zero2'
 * '<S45>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/KM_Reset Decision Function'
 * '<S46>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/MATLAB Function'
 * '<S47>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/MATLAB Function2'
 * '<S48>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/MATLAB Function3'
 * '<S49>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/MATLAB Function4'
 * '<S50>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/Rear axle speed conversion '
 * '<S51>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/StrTypeSel'
 * '<S52>'  : 'SWC_VC/FCA_AutoPark_VC2/Kinematic Model1/VCWhlBaseSel'
 * '<S53>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Compare To Constant'
 * '<S54>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Compare To Constant1'
 * '<S55>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Compare To Constant2'
 * '<S56>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/EGO Motion AP'
 * '<S57>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP'
 * '<S58>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/EGO Motion AP/StrTypeSel'
 * '<S59>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1'
 * '<S60>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1/Chart1'
 * '<S61>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1/Subsystem'
 * '<S62>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1/Subsystem/Whl_baseMaxCurvature'
 * '<S63>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1/Subsystem/Whl_baseSelect'
 * '<S64>'  : 'SWC_VC/FCA_AutoPark_VC2/PathPlanner/Pathplanner_AP/PathPlanner1/Subsystem/Whl_baseSelectMinRadious'
 * '<S65>'  : 'SWC_VC/FCA_AutoPark_VC2/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S66>'  : 'SWC_VC/FCA_AutoPark_VC2/Spot manipulation/MATLAB Function'
 * '<S67>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem/Compare To Constant'
 * '<S68>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem/Compare To Zero'
 * '<S69>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem/Compare To Zero1'
 * '<S70>'  : 'SWC_VC/FCA_AutoPark_VC2/Subsystem1/Compare To Constant'
 * '<S71>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Rate Limiter Dynamic'
 * '<S72>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Rate Limiter Dynamic1'
 * '<S73>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Saturation Dynamic'
 * '<S74>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Saturation Dynamic1'
 * '<S75>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/SelSteerType'
 * '<S76>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S77>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl/Rate Limiter Dynamic1/Saturation Dynamic'
 * '<S78>'  : 'SWC_VC/FCA_AutoPark_VC2/TrqControl_PreProcessor/Saturation Dynamic'
 * '<S79>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Compare To Zero'
 * '<S80>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control'
 * '<S81>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput'
 * '<S82>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/PathSeparation'
 * '<S83>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Determine_curr_waypoint1'
 * '<S84>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control'
 * '<S85>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Longitudinal_Control'
 * '<S86>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/MATLAB Function'
 * '<S87>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Determine_curr_waypoint1/MATLAB Function'
 * '<S88>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego'
 * '<S89>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Final_Heading_in_Ego'
 * '<S90>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Indexing_PPInput1'
 * '<S91>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/MATLAB Function'
 * '<S92>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/StrTypeSel'
 * '<S93>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/VCWhlBaseSel'
 * '<S94>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Indexing_PPInput2'
 * '<S95>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Subsystem'
 * '<S96>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Indexing_PPInput2/Compare To Zero'
 * '<S97>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Indexing_PPInput2/Index WPplus1'
 * '<S98>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Subsystem/Compare To Constant'
 * '<S99>'  : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Current_Heading_in_Ego/Subsystem/Compare To Constant1'
 * '<S100>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Final_Heading_in_Ego/Subsystem'
 * '<S101>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Final_Heading_in_Ego/Subsystem/Compare To Constant'
 * '<S102>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Calc_Final_Heading_in_Ego/Subsystem/Compare To Constant1'
 * '<S103>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Indexing_PPInput1/Compare To Zero'
 * '<S104>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Lateral_Control/Indexing_PPInput1/Index WPplus1'
 * '<S105>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Longitudinal_Control/Indexing_PPInput'
 * '<S106>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Longitudinal_Control/Indexing_PPInput/Compare To Zero'
 * '<S107>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/Control/Longitudinal_Control/Indexing_PPInput/Index WPplus1'
 * '<S108>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands'
 * '<S109>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1'
 * '<S110>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Gear_CMD_func'
 * '<S111>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Speed Controller'
 * '<S112>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/SteeringLimitations'
 * '<S113>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist'
 * '<S114>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Speed Controller/Brake At Gear Changing From Zero || Stopping Mode'
 * '<S115>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Speed Controller/Brake_PID'
 * '<S116>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Speed Controller/Brake_PID/Dead Zone Dynamic'
 * '<S117>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/Speed Controller/Brake_PID/PID_Algorithm'
 * '<S118>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/Compare To Zero'
 * '<S119>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/Compare To Zero1'
 * '<S120>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/MATLAB Function'
 * '<S121>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/MATLAB Function1'
 * '<S122>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/Rate Limiter Dynamic'
 * '<S123>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/AllCommands/TargetSpeedManager base on SpotSteer & remainingDist/Rate Limiter Dynamic/Saturation Dynamic'
 * '<S124>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection'
 * '<S125>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/minRemainDist'
 * '<S126>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/MATLAB Function2'
 * '<S127>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/Switch2CollDistInt'
 * '<S128>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/Switch2CollDistInt/CollDistAtPreCollFlagEntry'
 * '<S129>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/Switch2CollDistInt/RemainDistAtPreCollFlagEntry'
 * '<S130>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/Switch2CollDistInt/StoreDistDiffFlag'
 * '<S131>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/ControllerOutput/remainingDist1/CollisionDetection/Switch2CollDistInt/StoreDistDiffFlag/ChangeDetect'
 * '<S132>' : 'SWC_VC/FCA_AutoPark_VC2/VehicleControl1/PathSeparation/MATLAB Function PathSeparation'
 * '<S133>' : 'SWC_VC/VC_OutputArbitration1/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_SWC_VC_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
