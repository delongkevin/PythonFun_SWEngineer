/*
 * File: SWC_VC_types.h
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

#ifndef RTW_HEADER_SWC_VC_types_h_
#define RTW_HEADER_SWC_VC_types_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "TeAP_e_SteerRatRackPinionTyp.h"
#include "TeAP_e_DrvTypVrnt.h"
#include "TeAP_e_GbTyp.h"
#include "TeAP_e_PAMTunSet.h"
#include "TeAP_e_CtryCod.h"
#include "TeAP_e_HybTyp.h"
#include "TeAP_e_WhlBas.h"
#include "TeAP_e_RadioDispTyp.h"
#include "TeAutoPark_e_GearCmd.h"
#ifndef DEFINED_TYPEDEF_FOR_TbNVM_ProxyCalibParam_
#define DEFINED_TYPEDEF_FOR_TbNVM_ProxyCalibParam_

typedef struct {
  boolean_T KeAP_b_CanNode67DTCM;
  boolean_T KeAP_b_CanNode63TTM;
  boolean_T KeAP_b_StopAndStrt;
  uint16_T KeAP_mm_TyreSz;
  TeAP_e_SteerRatRackPinionTyp KeAP_e_SteerRatRackPinionTyp;
  TeAP_e_DrvTypVrnt KeAP_e_DrvTypVrnt;
  TeAP_e_GbTyp KeAP_e_GbTyp;
  TeAP_e_PAMTunSet KeAP_e_PAMTunSet;
  uint8_T KeAP_e_VehLineCfg;
  TeAP_e_CtryCod KeAP_e_CtryCod;
  TeAP_e_HybTyp KeAP_e_HybTyp;
  TeAP_e_WhlBas KeAP_e_WhlBas;
  boolean_T KeAP_b_ParkWithStop;
  boolean_T KeAP_b_PAMCfg;
  TeAP_e_RadioDispTyp KeAP_e_RadioDispTyp;
  boolean_T KeAP_b_CanNode95ITBMTCM;
  boolean_T KeAP_b_DrvSide;
  boolean_T KeAP_b_SemiAutoPrkgSys;
  uint16_T KeAP_e_MdlYr;
  boolean_T KeAP_b_PullOutCtrlPres;
  boolean_T KeAP_b_FullAutoPrkgSys;
  boolean_T KeAP_b_TrlrHitchAsstPres;
  boolean_T KeAP_b_TrlrRvsSteerPres;
  boolean_T KeAP_b_SVSPresent;
  uint8_T KeAP_k_VariantID;
} TbNVM_ProxyCalibParam;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbAP_InputVrntTunParam_t_
#define DEFINED_TYPEDEF_FOR_TbAP_InputVrntTunParam_t_

typedef struct {
  real32_T KeAP_degC_OperatingTempThd;
  real32_T KeAP_kph_EnblHysThd;
  real32_T KeAP_kph_FrntWarnMaxSpdThd;
  real32_T KeAP_kph_ParkMnvThd;
  real32_T KeAP_kph_PSDOffThd;
  real32_T KeAP_kph_PSDOnThd;
  real32_T KeAP_kph_RearWarnMaxSpdThd;
  real32_T KeAP_kph_USSActiveSpdThd;
  real32_T K_e_RAEB_VehicleWidth;
  real32_T K_Overlap_Thrsld_RAEB[5];
  real32_T KeTOS_s_InTurnDbncTm;
  real32_T KeTOS_s_StrDrvDbncTm;
  real32_T KeTOS_s_TurnExitDbncTm;
  real32_T KeTOS_x_InTurnThd;
  real32_T KeTOS_x_TurnExitThd;
  real32_T keVehParam_m_DistWhlBse;
  real32_T Obj_DistTable[5];
  real32_T Overlap_Thrsld_Switch;
  real32_T RAEB_Envelope_Offset;
  real32_T RAEB_Lateral_Distance_Notification;
  real32_T RAEB_Minimum_Object_Heigh;
  real32_T sampling_time;
  real32_T keVehParam_e_VehSteerRatioTable[19];
  real32_T keVehParam_e_StrWhlRatioBrkPnts[19];
  real32_T keInpAdptr_e_StWhOffset;
  real32_T Straight_Driving_Thresold_rads2;
  real32_T Steering_Angle_DeadZone_Start;
  real32_T Steering_Angle_DeadZone_End;
  real32_T KeAP_k_PathSepaMinSpd;
  real32_T KeAP_k_PathSepaSpdRampGrd;
  real32_T KeAP_k_DetWP_PreviewTime;
  real32_T KeAP_k_LatPathDevPGain;
  real32_T KeAP_k_LatPathDevIGain;
  real32_T KeAP_k_LatPathDevDGain;
  real32_T KeAP_k_LatHeadDevPGain;
  real32_T KeAP_k_LatHeadDevIGain;
  real32_T KeAP_k_LatHeadDevDGain;
  real32_T KeAP_k_SteerUpperLimit;
  real32_T KeAP_k_SteerLowerLimit;
  real32_T KeAP_k_CtrlOutCollDetActivate;
  real32_T KeAP_k_CtrlOutRemainDistNA;
  real32_T KeAP_k_CtrlOutCollDetCollDistLimit;
  real32_T KeAP_k_CtrlOutCollDetRedStopVal;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrTime;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotStrRackDevThd;
  real32_T KeAP_k_CtrlOutVehSpdMaxSpotSteer;
  real32_T KeAP_k_BrakePGain;
  real32_T KeAP_k_BrakeIGain;
  real32_T KeAP_k_BrakeUpperLimit;
  real32_T KeAP_k_BrakeLowerLimit;
  real32_T KeAP_k_CtrlOutGearDrive;
  real32_T KeAP_k_CtrlOutGearReverse;
  real32_T KeAP_k_CtrlOutGearPark;
  real32_T KeAP_k_WhlCircum;
  uint16_T KeAP_cnt_ChimeVolChgAlert;
  uint16_T KeAP_cnt_FrntChimeDisTimeThd;
  uint16_T KeAP_cnt_HalfSecChimeAlert;
  uint16_T KeAP_cnt_LEDBlinkTimeThd;
  uint16_T KeAP_cnt_VehKeyOnTimeThd;
  uint16_T KeAP_Cnt_GearFiltTimeThd;
  uint16_T KeAP_cnt_TimeStep;
  uint16_T KeAP_cm_ObjPrestFCDistThd;
  uint16_T KeAP_cm_ObjPrestRCDistThd;
  uint16_T KeAP_cm_VehicleWidth;
  uint16_T KeAP_Cnt_GearOverrideTimeThd;
  uint16_T KeAP_cnt_SwtStuckTimeThd;
  uint16_T KeAP_s_BSMInterfaceCntTimeout;
  uint16_T KeAP_s_CamHandshakeDur;
  uint16_T KeAP_s_EPSInterfaceCntTimeout;
  uint16_T KeAP_s_GearShiftWaitCntTimeout;
  uint16_T KeAP_s_MaxStandstillTimeThd;
  uint16_T KeAP_s_ObjInPathTimeoutDur;
  uint16_T KeAP_s_PausedPressBtnTimeoutDur;
  uint16_T KeAP_s_SeekPhaseTimeoutDur;
  uint16_T KeAP_s_SpdExceedDur;
  uint16_T KeAP_cnt_SPMBlinkLEDDur;
  int16_T KeAP_cm_VehContour_FSL_x;
  int16_T KeAP_cm_VehContour_FOL_x;
  int16_T KeAP_cm_VehContour_FIL_x;
  int16_T KeAP_cm_VehContour_FIR_x;
  int16_T KeAP_cm_VehContour_FOR_x;
  int16_T KeAP_cm_VehContour_FSR_x;
  int16_T KeAP_cm_VehContour_FSL_y;
  int16_T KeAP_cm_VehContour_FOL_y;
  int16_T KeAP_cm_VehContour_FIL_y;
  int16_T KeAP_cm_VehContour_FIR_y;
  int16_T KeAP_cm_VehContour_FOR_y;
  int16_T KeAP_cm_VehContour_FSR_y;
  int16_T KeAP_cm_VehContour_RSR_x;
  int16_T KeAP_cm_VehContour_ROR_x;
  int16_T KeAP_cm_VehContour_RIR_x;
  int16_T KeAP_cm_VehContour_RIL_x;
  int16_T KeAP_cm_VehContour_ROL_x;
  int16_T KeAP_cm_VehContour_RSL_x;
  int16_T KeAP_cm_VehContour_RSR_y;
  int16_T KeAP_cm_VehContour_ROR_y;
  int16_T KeAP_cm_VehContour_RIR_y;
  int16_T KeAP_cm_VehContour_RIL_y;
  int16_T KeAP_cm_VehContour_ROL_y;
  int16_T KeAP_cm_VehContour_RSL_y;
  int16_T KeAP_cm_DistZone1;
  int16_T KeAP_cm_DistZone2;
  int16_T KeAP_cm_DistZone3;
  int16_T KeAP_cm_DistZone4;
  int16_T KeAP_cm_DistZone5;
  int16_T KeAP_cm_DistZone6;
  int16_T KeAP_cnt_DebounceTimeThd;
  int16_T KeAP_cm_FrntLongDistAdj;
  int16_T KeAP_cm_HalfVehicleWidth;
  int16_T KeAP_cm_HookDistOffset;
  int16_T KeAP_cm_MaxNoObjDetctDist;
  int16_T KeAP_cm_RearLongDistAdj;
  int16_T KeAP_cm_WarnOffset;
  uint8_T KeAP_e_GbTypAT;
  uint8_T KeAP_pct_ObjConfidenceThd;
  uint8_T Reverse_Gr_num;
  boolean_T KeAP_b_AutoParkEn;
  boolean_T KeAP_b_FPAEn;
  boolean_T KeAP_b_FullAutoPark;
  boolean_T KeAP_b_HookConnected;
  boolean_T KeAP_b_RPAwithBrk;
  boolean_T KeAP_b_RPAwithSurroundView;
  boolean_T KeAP_b_SteerOnlyAutoPark;
  boolean_T KeCMbB_b_EnblOncObjDbnc;
  uint16_T KeAP_cnt_EngagedFullWaitCnt;
} TbAP_InputVrntTunParam_t;

#endif

#ifndef DEFINED_TYPEDEF_FOR_TbVC_DebugOut_
#define DEFINED_TYPEDEF_FOR_TbVC_DebugOut_

typedef struct {
  real32_T X_MABx;
  real32_T Y_MABx;
  real32_T heading_MABx;
  real32_T Str_Trq_CMD;
  real32_T VC_RemainingDist;
  real32_T VC_PathDev;
  real32_T VC_Head_Dev;
  real32_T Ma_AP_I_PSLimFSX;
  real32_T Ma_AP_I_PSLimFSY;
  real32_T Ma_AP_I_PSLimFBX;
  real32_T Ma_AP_I_PSLimFBY;
  real32_T Ma_AP_I_PSLimRSX;
  real32_T Ma_AP_I_PSLimRSY;
  real32_T Ma_AP_I_PSLimRBX;
  real32_T Ma_AP_I_PSLimRBY;
  uint8_T PM_CurrentSweep;
  boolean_T PM_RegenPath;
} TbVC_DebugOut;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_XLpZC1b7A6nxcgwe3fHeeD_
#define DEFINED_TYPEDEF_FOR_struct_XLpZC1b7A6nxcgwe3fHeeD_

typedef struct {
  uint8_T Current_waypoint;
  real32_T Steer_CMD;
  real32_T Path_deviation;
  real32_T Heading_deviation;
  real32_T remaining_distance;
  real32_T MaxSpeed;
  real32_T curr_wp;
} struct_XLpZC1b7A6nxcgwe3fHeeD;

#endif

#ifndef DEFINED_TYPEDEF_FOR_struct_VlmJKVI2F5DJPOPeBTAoyE_
#define DEFINED_TYPEDEF_FOR_struct_VlmJKVI2F5DJPOPeBTAoyE_

typedef struct {
  real32_T steer[250];
  real32_T speed[250];
  real32_T yaw[250];
  real32_T x[250];
  real32_T y[250];
  uint8_T wp_lastsweeps;
  uint8_T wp_N;
  int8_T Dir;
  int8_T NextDir;
} struct_VlmJKVI2F5DJPOPeBTAoyE;

#endif

/* Custom Type definition for Chart: '<S59>/Chart1' */
#ifndef struct_tag_sKLkrkTJ3gZMTxjPMClazsD
#define struct_tag_sKLkrkTJ3gZMTxjPMClazsD

struct tag_sKLkrkTJ3gZMTxjPMClazsD
{
  real32_T ang_threshold_regen;
  real32_T aux_turn_para_regen;
  real32_T break_point_para[2];
  real32_T curb_over_Y_dir_para;
  uint8_T CurrentSweepVeh;
  real32_T delta_s_clothoid_para;
  real32_T delta_s_no_str_para;
  real32_T delta_s_para;
  real32_T fin_loc_para_out[2];
  real32_T Kf_para;
  real32_T Ks;
  uint8_T max_num_sweeps;
  real32_T maxCurvature;
  uint8_T n_per_segment;
  uint8_T n_para;
  uint8_T num_clothoid_waypoints_para_mediumPS;
  uint8_T num_clothoid_waypoints_para_smallPS;
  uint16_T num_waypoints;
  uint8_T num_points_no_str_para;
  real32_T para_control_point_2_x_step_m;
  boolean_T park_out;
  real32_T PP_RES_DIST_TRAVEL;
  real32_T PS_size_para[4];
  real32_T regen_mode;
  real32_T str_profile_bigPS[34];
  real32_T str_whl_ang_regen;
  real32_T str_whl_ang_para_mediumPS_D;
  real32_T str_whl_ang_para_mediumPS_R;
  real32_T str_whl_ang_para_mediumPS_R_tail;
  real32_T str_whl_ang_para_smallPS_D2;
  real32_T str_whl_ang_para_smallPS_D4;
  real32_T str_whl_ang_para_smallPS_R3;
  real32_T str_whl_ang_para_smallPS_R5;
  real32_T str_whl_ang_para_smallPS_R_tail;
  real32_T StrRateLim_para;
  real32_T sweep_length_lim_regen;
  real32_T V_max_para;
  real32_T vecLen_coeff_para;
};

#endif                                 /*struct_tag_sKLkrkTJ3gZMTxjPMClazsD*/

#ifndef typedef_sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T
#define typedef_sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T

typedef struct tag_sKLkrkTJ3gZMTxjPMClazsD sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T;

#endif                              /*typedef_sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T*/

#ifndef struct_tag_s9RMC8MZujbBaIhNLHvrkS
#define struct_tag_s9RMC8MZujbBaIhNLHvrkS

struct tag_s9RMC8MZujbBaIhNLHvrkS
{
  real32_T Ke_AP_I_VehFrontOverhang;
  real32_T Ke_AP_I_VehWheelbase;
  real32_T Ke_AP_I_VehWidth;
  real32_T Ke_AP_I_VehRearOverhang;
};

#endif                                 /*struct_tag_s9RMC8MZujbBaIhNLHvrkS*/

#ifndef typedef_s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T
#define typedef_s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T

typedef struct tag_s9RMC8MZujbBaIhNLHvrkS s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T;

#endif                               /*typedef_s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T*/

#ifndef struct_tag_skA4KFEZ4HPkJJBOYCrevdH
#define struct_tag_skA4KFEZ4HPkJJBOYCrevdH

struct tag_skA4KFEZ4HPkJJBOYCrevdH
{
  uint32_T SafeEq;
  uint32_T Absolute;
  uint32_T NaNBias;
  uint32_T NaNWithFinite;
  uint32_T FiniteWithNaN;
  uint32_T NaNWithNaN;
};

#endif                                 /*struct_tag_skA4KFEZ4HPkJJBOYCrevdH*/

#ifndef typedef_skA4KFEZ4HPkJJBOYCrevdH_SWC_VC_T
#define typedef_skA4KFEZ4HPkJJBOYCrevdH_SWC_VC_T

typedef struct tag_skA4KFEZ4HPkJJBOYCrevdH skA4KFEZ4HPkJJBOYCrevdH_SWC_VC_T;

#endif                              /*typedef_skA4KFEZ4HPkJJBOYCrevdH_SWC_VC_T*/

#ifndef struct_tag_sgoad9SKTGOgw8JqT1MdSbB
#define struct_tag_sgoad9SKTGOgw8JqT1MdSbB

struct tag_sgoad9SKTGOgw8JqT1MdSbB
{
  uint8_T CurrentSweepVeh;
  real32_T control_point_3_y_step_m;
  real32_T curvature_coeff_perp;
  real32_T delta_s_clothoid_perp;
  real32_T delta_s_no_str_perp;
  real32_T delta_s_nose_in_regen;
  real32_T delta_s_perp;
  real32_T Kf_perp;
  real32_T Kf_perp_single_sweep;
  real32_T Ks;
  real32_T lim_perp_PS4;
  uint8_T n_per_segment;
  real32_T maxCurvature;
  uint8_T n_perp;
  boolean_T nose_in;
  uint8_T num_points_no_str_perp;
  uint16_T num_waypoints;
  real32_T p3_pos_lim_perp;
  boolean_T park_out;
  real32_T park_out_nose_in_angle;
  real32_T park_out_nose_in_brk_pos_offset_X;
  real32_T park_out_nose_in_brk_pos_offset_Y;
  real32_T park_out_nose_in_end_pos_offset_X;
  real32_T park_out_nose_in_end_pos_offset_Y_small;
  real32_T park_out_nose_in_end_pos_offset_Y_big;
  boolean_T parkout_perp_left;
  real32_T Phi_resolution_perp;
  real32_T Phi_lim_perp;
  uint8_T PP;
  real32_T PP_RES_DIST_TRAVEL;
  real32_T regen_mode;
  real32_T safety_lim_single_sweep_perp;
  real32_T segment_3_length_perp_m;
  real32_T single_sweep_control_point_2_y_offset;
  real32_T single_sweep_control_point_3_x_offset;
  real32_T single_sweep_control_point_3_y_offset;
  real32_T single_sweep_perp_width_lim;
  real32_T single_sweep_start_min_lat_dist_m;
  real32_T single_sweep_start_min_lon_dist_m;
  real32_T str_wheel_ang_perp;
  real32_T StrRateLim_perp;
  real32_T straight_line_perp_park_out;
  real32_T turn_radius_park_out_perp;
  real32_T turn_radius_park_out_perp_big;
  real32_T turn_radius_single_sweep_perp;
  real32_T V_max_perp;
  real32_T vecLen_coeff_perp;
  real32_T vecLen_coeff_perp_single_sweep_Phi;
  real32_T vecLen_coeff_perp_single_sweep_XY;
};

#endif                                 /*struct_tag_sgoad9SKTGOgw8JqT1MdSbB*/

#ifndef typedef_sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T
#define typedef_sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T

typedef struct tag_sgoad9SKTGOgw8JqT1MdSbB sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T;

#endif                              /*typedef_sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T*/

#ifndef struct_tag_s46ZhDOfhHDUZ8M92mIUzjH
#define struct_tag_s46ZhDOfhHDUZ8M92mIUzjH

struct tag_s46ZhDOfhHDUZ8M92mIUzjH
{
  real32_T aux_offset[12];
  boolean_T nose_in;
  boolean_T park_out;
  real32_T regen_mode;
  real32_T safety_lim_para_f;
  real32_T safety_lim_para_r;
  real32_T safety_lim_para_s;
  real32_T safety_lim_perp_f;
  real32_T safety_lim_perp_r;
  real32_T safety_lim_perp_s;
  real32_T safety_lim_nz_f;
  real32_T safety_lim_nz_r;
  real32_T safety_lim_nz_s;
  real32_T safety_lim_fb_f;
  real32_T safety_lim_fb_r;
  real32_T safety_lim_fb_s;
};

#endif                                 /*struct_tag_s46ZhDOfhHDUZ8M92mIUzjH*/

#ifndef typedef_s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T
#define typedef_s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T

typedef struct tag_s46ZhDOfhHDUZ8M92mIUzjH s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T;

#endif                              /*typedef_s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T*/

#ifndef struct_tag_sJCxfmxS8gBOONUZjbjUd9E
#define struct_tag_sJCxfmxS8gBOONUZjbjUd9E

struct tag_sJCxfmxS8gBOONUZjbjUd9E
{
  boolean_T CaseSensitivity;
  boolean_T StructExpand;
  char_T PartialMatching[6];
  boolean_T IgnoreNulls;
};

#endif                                 /*struct_tag_sJCxfmxS8gBOONUZjbjUd9E*/

#ifndef typedef_sJCxfmxS8gBOONUZjbjUd9E_SWC_VC_T
#define typedef_sJCxfmxS8gBOONUZjbjUd9E_SWC_VC_T

typedef struct tag_sJCxfmxS8gBOONUZjbjUd9E sJCxfmxS8gBOONUZjbjUd9E_SWC_VC_T;

#endif                              /*typedef_sJCxfmxS8gBOONUZjbjUd9E_SWC_VC_T*/

/* Forward declaration for rtModel */
typedef struct tag_RTM_SWC_VC_T RT_MODEL_SWC_VC_T;

#endif                                 /* RTW_HEADER_SWC_VC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
