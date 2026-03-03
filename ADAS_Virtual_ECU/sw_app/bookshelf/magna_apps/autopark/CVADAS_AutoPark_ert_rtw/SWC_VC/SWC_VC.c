/*
 * File: SWC_VC.c
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

#include "SWC_VC.h"
#include "SWC_VC_private.h"
#include "abs_DujjoFWP.h"
#include "abs_NgDyBNHZ.h"
#include "abs_fEIKHoQZ.h"
#include "atan2d_4JrmYGtm.h"
#include "cosd_KZN3FnAl.h"
#include "diff_PkLl8BoA.h"
#include "look1_iflf_binlxpw.h"
#include "look2_iflf_binlxpw.h"
#include "mod_B4YoGN9V.h"
#include "mod_GIkes8zg.h"
#include "mod_jpURcOT9.h"
#include "norm_5ISqY4yY.h"
#include "power_WcQaq5Rj.h"
#include "rt_atan2f_snf.h"
#include "rt_powf_snf.h"
#include "rt_remf_snf.h"
#include "rt_roundd_snf.h"
#include "sign_dXEnEZRu.h"
#include "sind_7is3Ljjc.h"
#include "sqrt_bTObkNxA.h"
#include "sum_1dSfq50U.h"
#include "sum_52uUX64c.h"
#include "sum_8eIcAjAO.h"
#include "sum_XHaVrCkY.h"
#include "sum_cZvgqUmQ.h"
#include "sum_d5YRIYyL.h"
#include "sum_lsjEpyTA.h"
#include "sum_tAhCUalH.h"
#include "tand_brbYAlcS.h"
#include "tand_cOkjHg6k.h"

/* Named constants for Chart: '<S25>/SC_ParkingManeuverMgr1' */
#define SWC_VC_C_APX_REMAIN_DIST_LIM   (38.0F)
#define SWC_VC_C_Regen_on_fly_lim      ((uint8_T)5U)
#define SWC_VC_C_TSL_POSN_TCM_FORWARD  ((uint8_T)4U)
#define SWC_VC_C_TSL_POSN_TCM_REAR     ((uint8_T)2U)
#define SWC_VC_C_V_STILL_APC           (0.1F)
#define SWC_VC_IN_APX_Park_State_Active_ST ((uint8_T)1U)
#define SWC_VC_IN_APX_Park_State_AllStrokes_ST ((uint8_T)1U)
#define SWC_VC_IN_APX_Park_State_Backw_DeviationExceeded ((uint8_T)1U)
#define SWC_VC_IN_APX_Park_State_Backw_DispForw ((uint8_T)2U)
#define SWC_VC_IN_APX_Park_State_Backw_DispForw1 ((uint8_T)3U)
#define SWC_VC_IN_APX_Park_State_Backw_PathAccepted ((uint8_T)4U)
#define SWC_VC_IN_APX_Park_State_Backw_RegenPathStarted ((uint8_T)5U)
#define SWC_VC_IN_APX_Park_State_Backward ((uint8_T)6U)
#define SWC_VC_IN_APX_Park_State_D_gear ((uint8_T)7U)
#define SWC_VC_IN_APX_Park_State_End_ST ((uint8_T)2U)
#define SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded ((uint8_T)8U)
#define SWC_VC_IN_APX_Park_State_Forw_DispBackw ((uint8_T)9U)
#define SWC_VC_IN_APX_Park_State_Forw_DispBackw1 ((uint8_T)10U)
#define SWC_VC_IN_APX_Park_State_Forw_PathAccepted ((uint8_T)11U)
#define SWC_VC_IN_APX_Park_State_Forw_RegenPathStarted ((uint8_T)12U)
#define SWC_VC_IN_APX_Park_State_Forward ((uint8_T)13U)
#define SWC_VC_IN_APX_Park_State_Inactive_ST ((uint8_T)2U)
#define SWC_VC_IN_APX_Park_State_Inactive_ST1 ((uint8_T)3U)
#define SWC_VC_IN_APX_Park_State_PARK_FIN_MSG ((uint8_T)3U)
#define SWC_VC_IN_APX_Park_State_R_gear ((uint8_T)4U)
#define SWC_VC_IN_APX_Park_State_R_gear_o ((uint8_T)14U)
#define SWC_VC_IN_DIRECTION_CHECK      ((uint8_T)15U)
#define SWC_VC_IN_NO_ACTIVE_CHILD      ((uint8_T)0U)
#define SWC_VC_IN_WAIT                 ((uint8_T)16U)
#define SWC_VC_IN_WAIT1                ((uint8_T)17U)

/* Named constants for Chart: '<S59>/Chart1' */
#define SWC_VC_IN_ERROR                ((uint8_T)1U)
#define SWC_VC_IN_FOLLOWING            ((uint8_T)2U)
#define SWC_VC_IN_OFF                  ((uint8_T)4U)
#define SWC_VC_IN_PLAN_FISHBONE        ((uint8_T)5U)
#define SWC_VC_IN_PLAN_PARA            ((uint8_T)6U)
#define SWC_VC_IN_PLAN_PERP            ((uint8_T)7U)
#define SWC_VC_IN_REGEN                ((uint8_T)3U)
#define SWC_VC_IN_RENDER_FISHBONE      ((uint8_T)8U)
#define SWC_VC_IN_RENDER_PARA          ((uint8_T)9U)
#define SWC_VC_IN_RENDER_PERP          ((uint8_T)10U)
#define SWC_VC_IN_RESTORE_OLD_PATH     ((uint8_T)13U)
#define SWC_VC_IN_SCANNING             ((uint8_T)14U)
#define SWC_VC_IN_TRANSPOSE            ((uint8_T)11U)
#define SWC_VC_IN_TRANSPOSE_INV        ((uint8_T)12U)
#define SWC_VC_n_per_segment           ((uint8_T)50U)
#define SWC_VC_num_waypoints           ((uint16_T)250U)

/* Exported data definition */

/* Definition for custom storage class: Default */
boolean_T ACT_ACTIVE;               /* '<S1>/Decativate VC if planner failed' */
uint8_T Ap_App_ID;                     /* '<S1>/Constant' */
real32_T Ma_AP_I_PSLimFBX;             /* '<S1>/Add1' */
real32_T Ma_AP_I_PSLimFBY;             /* '<S1>/Add5' */
real32_T Ma_AP_I_PSLimFSX;             /* '<S1>/Add' */
real32_T Ma_AP_I_PSLimFSY;             /* '<S1>/Add4' */
real32_T Ma_AP_I_PSLimRBX;             /* '<S1>/Add2' */
real32_T Ma_AP_I_PSLimRBY;             /* '<S1>/Add6' */
real32_T Ma_AP_I_PSLimRSX;             /* '<S1>/Add3' */
real32_T Ma_AP_I_PSLimRSY;             /* '<S1>/Add7' */
boolean_T MeAP_b_PosMet;               /* '<S8>/Compare' */
boolean_T MeAP_b_SteerActionReq;       /* '<S6>/Compare' */
real32_T MeAP_deg_strAngtoWhlAng;      /* '<S51>/Multiport Switch' */
TeAutoPark_e_GearCmd MeAP_e_GearCmd;   /* '<Root>/Data Type Conversion7' */
real32_T MeAP_m_PlanminRadius;         /* '<S64>/Multiport Switch' */
real32_T MeAP_m_VehFrontOverhang;      /* '<S61>/Subtract' */
real32_T MeAP_m_VehRearOverhang;       /* '<S61>/Product1' */
real32_T MeAP_m_VehWheelbase;          /* '<S63>/Multiport Switch' */
real32_T MeAP_m_VehWidth;              /* '<S61>/Product' */
real32_T MeAP_m_WhlBase;               /* '<S52>/Multiport Switch' */
real32_T MeAP_m_WhlCircum;             /* '<S12>/Gain' */
real32_T MeAP_pm_maxCurvature;         /* '<S62>/Multiport Switch' */
uint8_T PM_CurrentSweep;               /* '<S25>/SC_ParkingManeuverMgr1' */
boolean_T PM_RegenPath;                /* '<S25>/SC_ParkingManeuverMgr1' */
boolean_T PP_Abort;                    /* '<S59>/Chart1' */
real32_T PP_H[250];                    /* '<S13>/Data Type Conversion10' */
int8_T PP_state;                       /* '<S59>/Chart1' */
real32_T PP_x[250];                    /* '<S13>/Data Type Conversion5' */
real32_T PP_y[250];                    /* '<S13>/Data Type Conversion9' */
real32_T VC_Head_Dev;                  /* '<S80>/Signal Conversion' */
real32_T VC_PathDev;                   /* '<S80>/Signal Conversion' */
real32_T VC_RemainingDist;             /* '<S109>/Data Type Conversion12' */
real32_T VC_Steer_CMD;                 /* '<S80>/Signal Conversion' */
real32_T X_MABx;                       /* '<S1>/Data Type Conversion2' */
real32_T Y_MABx;                       /* '<S1>/Data Type Conversion3' */
real32_T heading_MABx;                 /* '<S1>/Data Type Conversion4' */
MdlrefDW_SWC_VC_T SWC_VC_MdlrefDW;

/* Block signals (default storage) */
B_SWC_VC_c_T SWC_VC_B;

/* Block states (default storage) */
DW_SWC_VC_f_T SWC_VC_DW;

/* Previous zero-crossings (trigger) states */
ZCE_SWC_VC_T SWC_VC_PrevZCX;

/* Forward declaration for local functions */
static void SWC_VC_post_render(const real32_T xx[250], const real32_T yy[250],
  uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T delta_s, real32_T
  fxo[250], real32_T fyo[250], uint8_T *total_num_idx);
static void SWC_VC_Bezier_path_function(const real32_T W0[2], const real32_T W1
  [2], const real32_T W2[2], uint8_T n, real32_T *extrema, real32_T x_out[50],
  real32_T y_out[50], uint8_T *num_idx);
static void SWC_VC_renderPath_fishbone(const real32_T pii[30], real32_T fxo[250],
  real32_T fyo[250], real32_T fho[250], real32_T KeAP_fvo[250], real32_T
  KeAP_fso[250], int16_T fio[10], int8_T *co);
static void SWC_VC_RENDER_FISHBONE(void);
static void SWC_VC_sweep_finder_para_common(real32_T x1, real32_T x2, real32_T
  b_y1, real32_T phi, const real32_T pps[8], real32_T str_wheel_ang, int8_T gear,
  boolean_T ParkOut, real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2]);
static void SWC_VC_sweep_finder_para_common_ml(real32_T x1, real32_T x2,
  real32_T b_y1, real32_T phi, const real32_T pps[8], int8_T gear, boolean_T
  ParkOut, real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2]);
static void SWC_VC_sweep_finder_para_common_m(real32_T x1, real32_T x2, real32_T
  b_y1, real32_T phi, const real32_T pps[8], int8_T gear, boolean_T ParkOut,
  real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2]);
static void SWC_VC_diff(const real32_T x_data[], real32_T y_data[], int32_T
  *y_size);
static void SWC_VC_atan2d(const real32_T y_data[], const int32_T *y_size, const
  real32_T x_data[], real32_T r_data[], int32_T *r_size);
static void SWC_VC_power(const real32_T a_data[], real32_T y_data[], int32_T
  *y_size);
static void SWC_VC_sqrt(real32_T x_data[]);
static void SWC_VC_post_render_common(const real32_T xx_data[], const real32_T
  yy_data[], uint8_T idx_end, real32_T Kf, real32_T delta_s, real32_T fxo_data[],
  int32_T fxo_size[2], real32_T fyo_data[], int32_T fyo_size[2], uint8_T
  *total_num_idx);
static void SWC_VC_abs(const real32_T x_data[], real32_T y_data[], int32_T
  *y_size);
static void SWC_VC_Bezier_path_function_common(real32_T W0[2], real32_T W1[2],
  real32_T W2[2], uint8_T n, real32_T *extrema, real32_T x_out_data[], int32_T
  x_out_size[2], real32_T y_out_data[], int32_T y_out_size[2], uint8_T *num_idx);
static void SWC_VC_mod(const real32_T x_data[], real32_T y, real32_T r_data[],
  int32_T *r_size);
static void SWC_VC_post_render_common_m(const real32_T xx_data[], const real32_T
  yy_data[], uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T delta_s,
  real32_T fxo_data[], int32_T fxo_size[2], real32_T fyo_data[], int32_T
  fyo_size[2], uint8_T *total_num_idx);
static void SWC_VC_renderPath_para_common(const real32_T pii[30], const real32_T
  ps[8], int8_T regen_dir, const sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T *plan_params,
  const s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T veh_params, real32_T fxo_data[], int32_T
  *fxo_size, real32_T fyo_data[], int32_T *fyo_size, real32_T fho_data[],
  int32_T *fho_size, real32_T fvo_data[], int32_T *fvo_size, real32_T fso_data[],
  int32_T *fso_size, int16_T fio[10], int8_T *co);
static void SWC_VC_renderPath_para(const real32_T pii[30], const real32_T ps[8],
  int8_T regen_dir, real32_T fxo[250], real32_T fyo[250], real32_T fho[250],
  real32_T fvo[250], real32_T fso[250], int16_T fio[10], int8_T *co);
static void SWC_VC_RENDER_PARA(void);
static void SWC_VC_post_render_common_ml(const real32_T xx_data[], const
  real32_T yy_data[], uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T
  delta_s, real32_T fxo_data[], int32_T fxo_size[2], real32_T fyo_data[],
  int32_T fyo_size[2], uint8_T *total_num_idx);
static void SWC_VC_renderPath_perp_common(const real32_T pii[30], const real32_T
  ps[8], const sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T *plan_params, const
  s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T veh_params, real32_T fxo_data[], int32_T
  *fxo_size, real32_T fyo_data[], int32_T *fyo_size, real32_T fho_data[],
  int32_T *fho_size, real32_T fvo_data[], int32_T *fvo_size, real32_T fso_data[],
  int32_T *fso_size, int16_T fio[10], int8_T *co);
static void SWC_VC_renderPath_perp(const real32_T pii[30], const real32_T ps[8],
  real32_T fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fvo[250],
  real32_T fso[250], int16_T fio[10], int8_T *co);
static void SWC_VC_RENDER_PERP(void);
static void SWC_VC_TFR_inv_common(real32_T fxi[250], real32_T fyi[250], real32_T
  fhi[250], real32_T fsi[250], const real32_T fvi[250], real32_T PSLi[8], const
  real32_T tfRi[3], boolean_T LeftPSi, real32_T plan_params_PP_RES_DIST_TRAVEL,
  real32_T fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fso[250],
  real32_T fvo[250], real32_T PSLo[8]);
static void SWC_VC_TFR_inv(const real32_T fxi[250], const real32_T fyi[250],
  const real32_T fhi[250], const real32_T fsi[250], const real32_T fvi[250],
  const real32_T PSLi[8], const real32_T tfRi[3], boolean_T LeftPSi, real32_T
  fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fso[250], real32_T
  fvo[250], real32_T PSLo[8], int8_T *co);
static void SWC_VC_TRANSPOSE_INV(void);
static void SWC_VC_reset_plan(int16_T fio[10]);
static void SWC_VC_enter_atomic_SCANNING(void);
static void SWC_VC_save_current_path(const real32_T fx_in[250], const real32_T
  fy_in[250], const real32_T fh_in[250], const real32_T fs_in[250], const
  real32_T fv_in[250], const int16_T fi_in[10], real32_T fx_out[250], real32_T
  fy_out[250], real32_T fh_out[250], real32_T fs_out[250], real32_T fv_out[250],
  int16_T fi_out[10]);
static void SWC_VC_enter_atomic_REGEN(void);
static void SWC_VC_planPath_fishbone(const real32_T v[5], const real32_T ps[8],
  real32_T po_fb[30], int8_T *co);
static void SWC_VC_planPath_para(const real32_T v[5], const real32_T ps[8],
  real32_T po_para[30], int8_T *co);
static void SWC_VC_planPath_perp(const real32_T v[5], const real32_T ps[8],
  real32_T po_perp[30], int8_T *co);
static void SWC_VC_TFR_common(const real32_T EgoCoordinates[5], real32_T
  ParkingSpotCoordinates[8], real32_T ParkingSpotType, const
  s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T *plan_params, real32_T tfRo[3], real32_T
  tfPS[8], real32_T vo[5], boolean_T *left);
static void SWC_VC_TFR(const real32_T EgoCoordinates[5], const real32_T
  ParkingSpotCoordinates[8], real32_T ParkingSpotType, real32_T tfRo[3],
  real32_T tfPS[8], real32_T vo[5], boolean_T *left, int8_T *co);
static real_T SWC_VC_sum_i(const uint8_T x_data[], const int32_T *x_size);
static void SWC_VC_power_e(const real32_T a_data[], const int32_T a_size[2],
  real32_T y_data[], int32_T y_size[2]);
static void SWC_VC_sqrt_k(real32_T x_data[], const int32_T x_size[2]);
static void SWC_VC_diff_a(const real32_T x_data[], const int32_T x_size[2],
  real32_T y_data[], int32_T y_size[2]);
static real32_T SWC_VC_sum(const real32_T x_data[], const int32_T x_size[2]);
static void SWC_VC_exit_internal_APX_Park_State_AllStrokes_ST(void);
static void SWC_VC_APX_Park_State_Backw_DeviationExceeded(void);
static void SWC_VC_APX_Park_State_Backw_DispForw(void);
static void SWC_VC_APX_Park_State_Backw_DispForw1(void);
static void SWC_VC_APX_Park_State_Backw_PathAccepted(void);
static void SWC_VC_APX_Park_State_Backw_RegenPathStarted(void);
static void SWC_VC_APX_Park_State_AllStrokes_ST(const boolean_T
  *rtu_MeAP_b_ParkOut);

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_post_render(const real32_T xx[250], const real32_T yy[250],
  uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T delta_s, real32_T
  fxo[250], real32_T fyo[250], uint8_T *total_num_idx)
{
  uint8_T i;
  uint8_T j;
  int32_T e_i;
  real32_T a;
  real32_T b_a;
  uint32_T qY;
  int32_T tmp;
  int32_T fxp_tmp;
  int32_T fxp_tmp_0;
  int32_T exitg1;
  i = 1U;
  j = 2U;
  fxp_tmp = idx_begin - 1;
  SWC_VC_B.fxp[0] = xx[fxp_tmp];
  SWC_VC_B.fyp[0] = yy[fxp_tmp];
  do {
    exitg1 = 0;
    qY = (uint32_T)idx_end - /*MW:OvSatOk*/ idx_begin;
    if (qY > idx_end) {
      qY = 0U;
    }

    e_i = (int32_T)(qY + 1U);
    if ((uint32_T)e_i > 255U) {
      e_i = 255;
    }

    if (j < e_i) {
      e_i = (int32_T)((uint32_T)idx_begin + j);
      fxp_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_tmp_0 = 255;
      }

      fxp_tmp = i - 1;
      a = xx[fxp_tmp_0 - 2] - SWC_VC_B.fxp[fxp_tmp];
      fxp_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_tmp_0 = 255;
      }

      b_a = yy[fxp_tmp_0 - 2] - SWC_VC_B.fyp[fxp_tmp];
      if (sqrtf(a * a + b_a * b_a) > delta_s) {
        fxp_tmp_0 = (int32_T)(i + 1U);
        if ((uint32_T)fxp_tmp_0 > 255U) {
          fxp_tmp_0 = 255;
        }

        i = (uint8_T)fxp_tmp_0;
        tmp = e_i;
        if ((uint32_T)e_i > 255U) {
          tmp = 255;
          e_i = 255;
        }

        fxp_tmp = (uint8_T)fxp_tmp_0 - 1;
        SWC_VC_B.fxp[fxp_tmp] = xx[tmp - 2];
        SWC_VC_B.fyp[fxp_tmp] = yy[e_i - 2];
      }

      j++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  e_i = (int32_T)(i + 1U);
  if ((uint32_T)e_i > 255U) {
    e_i = 255;
  }

  fxp_tmp = idx_end - 1;
  fxp_tmp_0 = (uint8_T)e_i - 1;
  SWC_VC_B.fxp[fxp_tmp_0] = xx[fxp_tmp];
  SWC_VC_B.fyp[fxp_tmp_0] = yy[fxp_tmp];
  *total_num_idx = (uint8_T)e_i;
  if (Kf < 1.0F) {
    for (fxp_tmp = 0; fxp_tmp <= fxp_tmp_0; fxp_tmp++) {
      SWC_VC_B.xf1[fxp_tmp] = SWC_VC_B.fxp[fxp_tmp];
      SWC_VC_B.xf2[fxp_tmp] = SWC_VC_B.fxp[fxp_tmp];
      SWC_VC_B.yf1[fxp_tmp] = SWC_VC_B.fyp[fxp_tmp];
      SWC_VC_B.yf2[fxp_tmp] = SWC_VC_B.fyp[fxp_tmp];
    }

    for (fxp_tmp = 1; fxp_tmp - 1 <= (uint8_T)e_i - 3; fxp_tmp++) {
      SWC_VC_B.xf1[fxp_tmp] = (1.0F - Kf) * SWC_VC_B.xf1[fxp_tmp - 1] + Kf *
        SWC_VC_B.fxp[fxp_tmp];
      SWC_VC_B.yf1[fxp_tmp] = (1.0F - Kf) * SWC_VC_B.yf1[fxp_tmp - 1] + Kf *
        SWC_VC_B.fyp[fxp_tmp];
      SWC_VC_B.xf2[fxp_tmp] = (1.0F - Kf) * SWC_VC_B.xf2[fxp_tmp - 1] + Kf *
        SWC_VC_B.xf1[fxp_tmp];
      SWC_VC_B.yf2[fxp_tmp] = (1.0F - Kf) * SWC_VC_B.yf2[fxp_tmp - 1] + Kf *
        SWC_VC_B.yf1[fxp_tmp];
    }

    memcpy(&SWC_VC_B.fxp[0], &SWC_VC_B.xf2[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fyp[0], &SWC_VC_B.yf2[0], 250U * sizeof(real32_T));
    i = (uint8_T)fxp_tmp_0;
    while (i > 1) {
      e_i = i - 1;
      SWC_VC_B.xf1[e_i] = (1.0F - Kf) * SWC_VC_B.xf1[i] + SWC_VC_B.fxp[e_i] * Kf;
      SWC_VC_B.yf1[e_i] = (1.0F - Kf) * SWC_VC_B.yf1[i] + SWC_VC_B.fyp[e_i] * Kf;
      SWC_VC_B.xf2[e_i] = (1.0F - Kf) * SWC_VC_B.xf2[i] + SWC_VC_B.xf1[e_i] * Kf;
      SWC_VC_B.yf2[e_i] = (1.0F - Kf) * SWC_VC_B.yf2[i] + SWC_VC_B.yf1[e_i] * Kf;
      i = (uint8_T)e_i;
    }

    memcpy(&SWC_VC_B.fxp[0], &SWC_VC_B.xf2[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fyp[0], &SWC_VC_B.yf2[0], 250U * sizeof(real32_T));
  }

  for (e_i = 0; e_i <= fxp_tmp_0; e_i++) {
    fxo[e_i] = SWC_VC_B.fxp[e_i];
    fyo[e_i] = SWC_VC_B.fyp[e_i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_Bezier_path_function(const real32_T W0[2], const real32_T W1
  [2], const real32_T W2[2], uint8_T n, real32_T *extrema, real32_T x_out[50],
  real32_T y_out[50], uint8_T *num_idx)
{
  uint8_T b_n;
  boolean_T flag;
  boolean_T tmp;
  real32_T kappa_num_tmp;
  real32_T kappa_num_tmp_0;
  real32_T kappa_num_tmp_1;
  real32_T kappa_num_tmp_2;
  real32_T kappa_num_tmp_3;
  real32_T kappa_num_tmp_4;
  real32_T kappa_num_tmp_tmp;
  boolean_T exitg1;
  if (n < 49) {
    b_n = n;
  } else {
    b_n = 49U;
  }

  SWC_VC_B.step_size_i = roundf(1.0F / (real32_T)b_n * 10000.0F) / 10000.0F;
  SWC_VC_B.theta_rotation = 1.57079637F - rt_atan2f_snf((W0[1] - 2.0F * W1[1]) +
    W2[1], (W0[0] - 2.0F * W1[0]) + W2[0]);
  SWC_VC_B.Rot_tmp_tmp = sinf(SWC_VC_B.theta_rotation);
  SWC_VC_B.theta_rotation = cosf(SWC_VC_B.theta_rotation);
  SWC_VC_B.b_W0_idx_0 = SWC_VC_B.theta_rotation * W0[0] + -SWC_VC_B.Rot_tmp_tmp *
    W0[1];
  SWC_VC_B.alpha2 = SWC_VC_B.theta_rotation * W1[0] + -SWC_VC_B.Rot_tmp_tmp *
    W1[1];
  SWC_VC_B.beta1 = SWC_VC_B.Rot_tmp_tmp * W0[0] + SWC_VC_B.theta_rotation * W0[1];
  SWC_VC_B.x_max = SWC_VC_B.Rot_tmp_tmp * W1[0] + SWC_VC_B.theta_rotation * W1[1];
  SWC_VC_B.b_W2 = SWC_VC_B.Rot_tmp_tmp * W2[0] + SWC_VC_B.theta_rotation * W2[1];
  SWC_VC_B.b_W0_idx_1 = SWC_VC_B.beta1;
  SWC_VC_B.b_W1_idx_1 = SWC_VC_B.x_max;
  SWC_VC_B.i_o = SWC_VC_B.b_W2;
  SWC_VC_B.a = ((SWC_VC_B.beta1 - 2.0F * SWC_VC_B.x_max) + SWC_VC_B.b_W2) * 3.0F;
  if (fabsf(SWC_VC_B.b_W0_idx_0) <= 1.0E-5) {
    *extrema = 0.0F;
    SWC_VC_B.b_W0_idx_0 = (SWC_VC_B.theta_rotation * W2[0] +
      -SWC_VC_B.Rot_tmp_tmp * W2[1]) + (SWC_VC_B.b_W0_idx_0 + SWC_VC_B.alpha2);
    SWC_VC_B.b_W0_idx_1 = (SWC_VC_B.beta1 + SWC_VC_B.x_max) + SWC_VC_B.b_W2;
    SWC_VC_B.step_size_i = SWC_VC_B.theta_rotation * SWC_VC_B.b_W0_idx_0 +
      SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.b_W0_idx_1;
    SWC_VC_B.Rot_tmp_tmp = -SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.b_W0_idx_0 +
      SWC_VC_B.theta_rotation * SWC_VC_B.b_W0_idx_1;
    x_out[0] = 0.0F;
    y_out[0] = 0.0F;
    *num_idx = 0U;
    SWC_VC_B.c_k = 0;
    while (SWC_VC_B.c_k <= b_n - 1) {
      SWC_VC_B.idx = (int32_T)(*num_idx + 1U);
      if ((uint32_T)SWC_VC_B.idx > 255U) {
        SWC_VC_B.idx = 255;
      }

      *num_idx = (uint8_T)SWC_VC_B.idx;
      x_out[SWC_VC_B.c_k + 1] = SWC_VC_B.step_size_i / (real32_T)b_n +
        x_out[SWC_VC_B.c_k];
      y_out[SWC_VC_B.c_k + 1] = SWC_VC_B.Rot_tmp_tmp / (real32_T)b_n +
        y_out[SWC_VC_B.c_k];
      SWC_VC_B.c_k++;
    }
  } else {
    SWC_VC_B.alpha3 = SWC_VC_B.alpha2 - SWC_VC_B.b_W0_idx_0;
    if (fabsf(SWC_VC_B.alpha3) <= 1.0E-5) {
      SWC_VC_B.alpha1 = SWC_VC_B.beta1 / SWC_VC_B.b_W0_idx_0;
      SWC_VC_B.alpha2 = (SWC_VC_B.x_max - SWC_VC_B.beta1) / (SWC_VC_B.b_W0_idx_0
        * SWC_VC_B.b_W0_idx_0 * 3.0F);
      SWC_VC_B.alpha3 = SWC_VC_B.a / (27.0F * rt_powf_snf(SWC_VC_B.b_W0_idx_0,
        3.0F));
      flag = false;
      if (SWC_VC_B.alpha3 < 0.0F) {
        flag = true;
        SWC_VC_B.b_W0_idx_1 = -SWC_VC_B.beta1;
        SWC_VC_B.b_W1_idx_1 = -SWC_VC_B.x_max;
        SWC_VC_B.i_o = -SWC_VC_B.b_W2;
        SWC_VC_B.a = ((-SWC_VC_B.beta1 - 2.0F * -SWC_VC_B.x_max) +
                      -SWC_VC_B.b_W2) * 3.0F;
        SWC_VC_B.alpha1 = -SWC_VC_B.beta1 / SWC_VC_B.b_W0_idx_0;
        SWC_VC_B.alpha2 = (-SWC_VC_B.x_max - (-SWC_VC_B.beta1)) /
          (SWC_VC_B.b_W0_idx_0 * SWC_VC_B.b_W0_idx_0 * 3.0F);
        SWC_VC_B.alpha3 = SWC_VC_B.a / (27.0F * rt_powf_snf(SWC_VC_B.b_W0_idx_0,
          3.0F));
      }

      SWC_VC_B.beta1 = SWC_VC_B.alpha1 - SWC_VC_B.alpha2 * SWC_VC_B.alpha2 /
        SWC_VC_B.alpha3;
      SWC_VC_B.x_max = sqrtf((sqrtf(SWC_VC_B.beta1 * SWC_VC_B.beta1 * 9.0F +
        5.0F) + -2.0F * SWC_VC_B.beta1) / 5.0F);
      SWC_VC_B.beta1 = sqrtf(SWC_VC_B.alpha3);
      SWC_VC_B.Rot[0] = (SWC_VC_B.x_max - SWC_VC_B.alpha2 / SWC_VC_B.beta1) /
        SWC_VC_B.beta1 / 3.0F / SWC_VC_B.b_W0_idx_0;
      SWC_VC_B.Rot[1] = (-SWC_VC_B.x_max - SWC_VC_B.alpha2 / sqrtf
                         (SWC_VC_B.alpha3)) / SWC_VC_B.beta1 / 3.0F /
        SWC_VC_B.b_W0_idx_0;
      SWC_VC_B.beta1 = SWC_VC_B.b_W0_idx_1 * SWC_VC_B.b_W0_idx_1;
      SWC_VC_B.x_max = SWC_VC_B.Rot[0] * SWC_VC_B.Rot[0];
      SWC_VC_B.alpha2 = SWC_VC_B.beta1 * 36.0F;
      SWC_VC_B.alpha3 = rt_powf_snf(SWC_VC_B.Rot[0], 3.0F);
      SWC_VC_B.b_W2 = -3.0F * SWC_VC_B.b_W1_idx_1 + 3.0F * SWC_VC_B.b_W0_idx_1;
      SWC_VC_B.alpha1 = SWC_VC_B.beta1 * 9.0F;
      SWC_VC_B.beta1 = SWC_VC_B.b_W0_idx_0 * SWC_VC_B.b_W0_idx_0 * 9.0F +
        SWC_VC_B.alpha1;
      SWC_VC_B.kappa_num_tmp = 6.0F * SWC_VC_B.b_W0_idx_1 * SWC_VC_B.a;
      SWC_VC_B.kappa_num_tmp_k = SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W1_idx_1;
      SWC_VC_B.kappa_num_tmp_i = SWC_VC_B.a * SWC_VC_B.a;
      SWC_VC_B.Rot[0] = fabsf((SWC_VC_B.b_W2 - SWC_VC_B.a * SWC_VC_B.Rot[0]) * (
        -6.0F * SWC_VC_B.b_W0_idx_0) / rt_powf_snf(((((((((SWC_VC_B.beta1 +
        36.0F * SWC_VC_B.b_W0_idx_1 * SWC_VC_B.Rot[0] * SWC_VC_B.b_W1_idx_1) -
        SWC_VC_B.alpha2 * SWC_VC_B.Rot[0]) + SWC_VC_B.kappa_num_tmp *
        SWC_VC_B.x_max) + SWC_VC_B.x_max * 36.0F * SWC_VC_B.kappa_num_tmp_k) -
        SWC_VC_B.x_max * 72.0F * SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_1) +
        12.0F * SWC_VC_B.alpha3 * SWC_VC_B.b_W1_idx_1 * SWC_VC_B.a) +
        SWC_VC_B.alpha2 * SWC_VC_B.x_max) - 12.0F * SWC_VC_B.b_W0_idx_1 *
        SWC_VC_B.alpha3 * SWC_VC_B.a) + SWC_VC_B.kappa_num_tmp_i * rt_powf_snf
        (SWC_VC_B.Rot[0], 4.0F), 1.5F));
      SWC_VC_B.x_max = SWC_VC_B.Rot[1] * SWC_VC_B.Rot[1];
      SWC_VC_B.alpha3 = rt_powf_snf(SWC_VC_B.Rot[1], 3.0F);
      SWC_VC_B.Rot[1] = fabsf((SWC_VC_B.b_W2 - SWC_VC_B.a * SWC_VC_B.Rot[1]) * (
        -6.0F * SWC_VC_B.b_W0_idx_0) / rt_powf_snf(((((((((SWC_VC_B.beta1 +
        36.0F * SWC_VC_B.b_W0_idx_1 * SWC_VC_B.Rot[1] * SWC_VC_B.b_W1_idx_1) -
        SWC_VC_B.alpha2 * SWC_VC_B.Rot[1]) + SWC_VC_B.kappa_num_tmp *
        SWC_VC_B.x_max) + SWC_VC_B.x_max * 36.0F * SWC_VC_B.kappa_num_tmp_k) -
        SWC_VC_B.x_max * 72.0F * SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_1) +
        12.0F * SWC_VC_B.alpha3 * SWC_VC_B.b_W1_idx_1 * SWC_VC_B.a) +
        SWC_VC_B.alpha2 * SWC_VC_B.x_max) - 12.0F * SWC_VC_B.b_W0_idx_1 *
        SWC_VC_B.alpha3 * SWC_VC_B.a) + SWC_VC_B.kappa_num_tmp_i * rt_powf_snf
        (SWC_VC_B.Rot[1], 4.0F), 1.5F));
      SWC_VC_B.beta1 = SWC_VC_B.alpha2 * 0.0F;
      SWC_VC_B.x_max = SWC_VC_B.b_W0_idx_0 * SWC_VC_B.b_W0_idx_0 * 9.0F +
        SWC_VC_B.alpha1;
      SWC_VC_B.Rot[2] = fabsf((SWC_VC_B.b_W2 - SWC_VC_B.a * 0.0F) * (-6.0F *
        SWC_VC_B.b_W0_idx_0) / rt_powf_snf(((((((((SWC_VC_B.x_max + 36.0F *
        SWC_VC_B.b_W0_idx_1 * 0.0F * SWC_VC_B.b_W1_idx_1) - SWC_VC_B.beta1) +
        SWC_VC_B.kappa_num_tmp * 0.0F) + SWC_VC_B.kappa_num_tmp_k * 0.0F) - 0.0F
        * SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_1) + 0.0F *
        SWC_VC_B.b_W1_idx_1 * SWC_VC_B.a) + SWC_VC_B.beta1) - 12.0F *
        SWC_VC_B.b_W0_idx_1 * 0.0F * SWC_VC_B.a) + SWC_VC_B.kappa_num_tmp_i *
        0.0F, 1.5F));
      SWC_VC_B.Rot[3] = fabsf((SWC_VC_B.b_W2 - SWC_VC_B.a) * (-6.0F *
        SWC_VC_B.b_W0_idx_0) / rt_powf_snf(((((((((SWC_VC_B.x_max + 36.0F *
        SWC_VC_B.b_W0_idx_1 * SWC_VC_B.b_W1_idx_1) - SWC_VC_B.alpha2) +
        SWC_VC_B.kappa_num_tmp) + SWC_VC_B.kappa_num_tmp_k * 36.0F) - 72.0F *
        SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_1) + 12.0F * SWC_VC_B.b_W1_idx_1
        * SWC_VC_B.a) + SWC_VC_B.alpha2) - 12.0F * SWC_VC_B.b_W0_idx_1 *
        SWC_VC_B.a) + SWC_VC_B.kappa_num_tmp_i, 1.5F));
      if (!rtIsNaNF(SWC_VC_B.Rot[0])) {
        SWC_VC_B.idx = 1;
      } else {
        SWC_VC_B.idx = 0;
        SWC_VC_B.c_k = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k <= 4)) {
          if (!rtIsNaNF(SWC_VC_B.Rot[SWC_VC_B.c_k - 1])) {
            SWC_VC_B.idx = SWC_VC_B.c_k;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k++;
          }
        }
      }

      if (SWC_VC_B.idx == 0) {
        *extrema = SWC_VC_B.Rot[0];
      } else {
        *extrema = SWC_VC_B.Rot[SWC_VC_B.idx - 1];
        while (SWC_VC_B.idx + 1 <= 4) {
          if (*extrema < SWC_VC_B.Rot[SWC_VC_B.idx]) {
            *extrema = SWC_VC_B.Rot[SWC_VC_B.idx];
          }

          SWC_VC_B.idx++;
        }
      }

      if (flag) {
        SWC_VC_B.b_W0_idx_1 = -SWC_VC_B.b_W0_idx_1;
        SWC_VC_B.b_W1_idx_1 = -SWC_VC_B.b_W1_idx_1;
        SWC_VC_B.i_o = -SWC_VC_B.i_o;
        SWC_VC_B.a = ((SWC_VC_B.b_W0_idx_1 - 2.0F * SWC_VC_B.b_W1_idx_1) +
                      SWC_VC_B.i_o) * 3.0F;
      }

      *num_idx = 0U;
      SWC_VC_B.i_o = 0.0F;
      while (SWC_VC_B.i_o <= 1.0F) {
        SWC_VC_B.idx = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx > 255U) {
          SWC_VC_B.idx = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx;
        SWC_VC_B.alpha3 = 3.0F * SWC_VC_B.b_W0_idx_0 * SWC_VC_B.i_o;
        SWC_VC_B.b_W2 = ((SWC_VC_B.b_W1_idx_1 - SWC_VC_B.b_W0_idx_1) * 3.0F *
                         (SWC_VC_B.i_o * SWC_VC_B.i_o) + 3.0F *
                         SWC_VC_B.b_W0_idx_1 * SWC_VC_B.i_o) + 0.333333343F *
          SWC_VC_B.a * rt_powf_snf(SWC_VC_B.i_o, 3.0F);
        SWC_VC_B.idx = (uint8_T)SWC_VC_B.idx - 1;
        x_out[SWC_VC_B.idx] = SWC_VC_B.theta_rotation * SWC_VC_B.alpha3 +
          SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.b_W2;
        y_out[SWC_VC_B.idx] = -SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.alpha3 +
          SWC_VC_B.theta_rotation * SWC_VC_B.b_W2;
        SWC_VC_B.i_o += SWC_VC_B.step_size_i;
      }
    } else {
      flag = false;
      if (SWC_VC_B.alpha3 < 0.0F) {
        flag = true;
        SWC_VC_B.b_W0_idx_0 = -SWC_VC_B.b_W0_idx_0;
        SWC_VC_B.alpha2 = -SWC_VC_B.alpha2;
      }

      *num_idx = 0U;
      SWC_VC_B.i_o = 0.0F;
      while (SWC_VC_B.i_o <= 1.0F) {
        SWC_VC_B.idx = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx > 255U) {
          SWC_VC_B.idx = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx;
        SWC_VC_B.alpha3 = rt_powf_snf(SWC_VC_B.i_o, 3.0F);
        SWC_VC_B.b_W0_idx_1 = SWC_VC_B.i_o * SWC_VC_B.i_o;
        SWC_VC_B.b_W1_idx_1 = 2.0F * (real32_T)flag;
        SWC_VC_B.b_W2 = SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_0;
        SWC_VC_B.alpha1 = SWC_VC_B.beta1 * SWC_VC_B.beta1;
        SWC_VC_B.kappa_num_tmp = SWC_VC_B.alpha1 * 36.0F;
        SWC_VC_B.kappa_num_tmp_k = SWC_VC_B.b_W0_idx_0 * SWC_VC_B.b_W0_idx_0;
        SWC_VC_B.kappa_num_tmp_i = 144.0F * (real32_T)flag;
        SWC_VC_B.kappa_num_tmp_o = SWC_VC_B.kappa_num_tmp_i *
          SWC_VC_B.b_W0_idx_0 * SWC_VC_B.i_o * SWC_VC_B.alpha2;
        SWC_VC_B.kappa_num_tmp_m = 288.0F * (real32_T)flag * SWC_VC_B.b_W0_idx_1
          * SWC_VC_B.alpha2 * SWC_VC_B.b_W0_idx_0;
        kappa_num_tmp = SWC_VC_B.b_W0_idx_1 * 36.0F;
        kappa_num_tmp_0 = SWC_VC_B.kappa_num_tmp_k * 36.0F;
        kappa_num_tmp_1 = 36.0F * (real32_T)flag * SWC_VC_B.kappa_num_tmp_k;
        kappa_num_tmp_2 = SWC_VC_B.b_W0_idx_1 * 72.0F;
        kappa_num_tmp_tmp = SWC_VC_B.kappa_num_tmp_i * SWC_VC_B.kappa_num_tmp_k;
        kappa_num_tmp_3 = kappa_num_tmp_tmp * SWC_VC_B.i_o;
        kappa_num_tmp_4 = SWC_VC_B.alpha2 * SWC_VC_B.alpha2;
        SWC_VC_B.kappa_num_tmp_i = SWC_VC_B.kappa_num_tmp_i *
          SWC_VC_B.b_W0_idx_1 * kappa_num_tmp_4;
        kappa_num_tmp_tmp *= SWC_VC_B.b_W0_idx_1;
        SWC_VC_B.kappa_num[(uint8_T)SWC_VC_B.idx - 1] =
          (((((((((SWC_VC_B.b_W0_idx_1 * SWC_VC_B.b_W0_idx_0 * SWC_VC_B.a + 6.0F
                   * (real32_T)flag * SWC_VC_B.b_W0_idx_0 * SWC_VC_B.x_max) -
                  SWC_VC_B.b_W0_idx_0 * SWC_VC_B.a * SWC_VC_B.i_o) - 6.0F *
                 SWC_VC_B.beta1 * (real32_T)flag * SWC_VC_B.alpha2) - 3.0F *
                SWC_VC_B.b_W0_idx_0 * SWC_VC_B.x_max) + 3.0F * SWC_VC_B.beta1 *
               SWC_VC_B.alpha2) - SWC_VC_B.b_W0_idx_1 * SWC_VC_B.alpha2 *
              SWC_VC_B.a) + SWC_VC_B.b_W2 * SWC_VC_B.a * SWC_VC_B.i_o) +
            SWC_VC_B.b_W1_idx_1 * SWC_VC_B.b_W0_idx_1 * SWC_VC_B.alpha2 *
            SWC_VC_B.a) - SWC_VC_B.b_W2 * SWC_VC_B.b_W0_idx_1 * SWC_VC_B.a) *
          -6.0F / rt_powf_snf(((((((((((((((((((((((((((SWC_VC_B.kappa_num_tmp_k
          * 9.0F - kappa_num_tmp_2 * SWC_VC_B.x_max * SWC_VC_B.beta1) + 12.0F *
          SWC_VC_B.alpha3 * SWC_VC_B.x_max * SWC_VC_B.a) - 12.0F *
          SWC_VC_B.beta1 * SWC_VC_B.alpha3 * SWC_VC_B.a) + 36.0F *
          SWC_VC_B.beta1 * SWC_VC_B.i_o * SWC_VC_B.x_max) + 6.0F *
          SWC_VC_B.beta1 * SWC_VC_B.a * SWC_VC_B.b_W0_idx_1) + SWC_VC_B.alpha1 *
          9.0F) - SWC_VC_B.kappa_num_tmp * SWC_VC_B.i_o) + kappa_num_tmp *
          (SWC_VC_B.x_max * SWC_VC_B.x_max)) + SWC_VC_B.kappa_num_tmp *
          SWC_VC_B.b_W0_idx_1) + SWC_VC_B.a * SWC_VC_B.a * rt_powf_snf
          (SWC_VC_B.i_o, 4.0F)) + kappa_num_tmp_1) + kappa_num_tmp_3) +
          SWC_VC_B.kappa_num_tmp_o) - SWC_VC_B.kappa_num_tmp_m) -
          SWC_VC_B.kappa_num_tmp_o) + SWC_VC_B.kappa_num_tmp_m) -
          kappa_num_tmp_0 * SWC_VC_B.i_o) + kappa_num_tmp * kappa_num_tmp_4) +
          kappa_num_tmp_0 * SWC_VC_B.b_W0_idx_1) - kappa_num_tmp_1) -
          kappa_num_tmp_2 * SWC_VC_B.alpha2 * SWC_VC_B.b_W0_idx_0) + 36.0F *
          SWC_VC_B.b_W0_idx_0 * SWC_VC_B.i_o * SWC_VC_B.alpha2) -
          kappa_num_tmp_3) + SWC_VC_B.kappa_num_tmp_i) + kappa_num_tmp_tmp) -
          SWC_VC_B.kappa_num_tmp_i) - kappa_num_tmp_tmp, 1.5F);
        SWC_VC_B.i_o += SWC_VC_B.step_size_i;
      }

      SWC_VC_B.idx = (int32_T)(*num_idx + 1U);
      if ((uint32_T)SWC_VC_B.idx > 255U) {
        SWC_VC_B.idx = 255;
      }

      for (b_n = (uint8_T)SWC_VC_B.idx; b_n < 51; b_n++) {
        SWC_VC_B.kappa_num[b_n - 1] = SWC_VC_B.kappa_num[*num_idx - 1];
      }

      tmp = rtIsNaNF(SWC_VC_B.kappa_num[0]);
      if (!tmp) {
        SWC_VC_B.idx = 1;
      } else {
        SWC_VC_B.idx = 0;
        SWC_VC_B.c_k = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k <= 50)) {
          if (!rtIsNaNF(SWC_VC_B.kappa_num[SWC_VC_B.c_k - 1])) {
            SWC_VC_B.idx = SWC_VC_B.c_k;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k++;
          }
        }
      }

      if (SWC_VC_B.idx == 0) {
        SWC_VC_B.b_W0_idx_1 = SWC_VC_B.kappa_num[0];
      } else {
        SWC_VC_B.b_W0_idx_1 = SWC_VC_B.kappa_num[SWC_VC_B.idx - 1];
        while (SWC_VC_B.idx + 1 <= 50) {
          if (SWC_VC_B.b_W0_idx_1 < SWC_VC_B.kappa_num[SWC_VC_B.idx]) {
            SWC_VC_B.b_W0_idx_1 = SWC_VC_B.kappa_num[SWC_VC_B.idx];
          }

          SWC_VC_B.idx++;
        }
      }

      if (!tmp) {
        SWC_VC_B.idx = 1;
      } else {
        SWC_VC_B.idx = 0;
        SWC_VC_B.c_k = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k <= 50)) {
          if (!rtIsNaNF(SWC_VC_B.kappa_num[SWC_VC_B.c_k - 1])) {
            SWC_VC_B.idx = SWC_VC_B.c_k;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k++;
          }
        }
      }

      if (SWC_VC_B.idx == 0) {
        SWC_VC_B.i_o = SWC_VC_B.kappa_num[0];
      } else {
        SWC_VC_B.i_o = SWC_VC_B.kappa_num[SWC_VC_B.idx - 1];
        while (SWC_VC_B.idx + 1 < 51) {
          if (SWC_VC_B.i_o > SWC_VC_B.kappa_num[SWC_VC_B.idx]) {
            SWC_VC_B.i_o = SWC_VC_B.kappa_num[SWC_VC_B.idx];
          }

          SWC_VC_B.idx++;
        }
      }

      *extrema = fabsf(SWC_VC_B.b_W0_idx_1);
      SWC_VC_B.i_o = fabsf(SWC_VC_B.i_o);
      if (*extrema < SWC_VC_B.i_o) {
        *extrema = SWC_VC_B.i_o;
      } else {
        if (rtIsNaNF(*extrema) && (!rtIsNaNF(SWC_VC_B.i_o))) {
          *extrema = SWC_VC_B.i_o;
        }
      }

      if (flag) {
        SWC_VC_B.b_W0_idx_0 = -SWC_VC_B.b_W0_idx_0;
        SWC_VC_B.alpha2 = -SWC_VC_B.alpha2;
      }

      *num_idx = 0U;
      SWC_VC_B.i_o = 0.0F;
      while (SWC_VC_B.i_o <= 1.0F) {
        SWC_VC_B.idx = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx > 255U) {
          SWC_VC_B.idx = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx;
        SWC_VC_B.b_W0_idx_1 = SWC_VC_B.i_o * SWC_VC_B.i_o;
        SWC_VC_B.alpha3 = (SWC_VC_B.alpha2 - SWC_VC_B.b_W0_idx_0) * 3.0F *
          SWC_VC_B.b_W0_idx_1 + 3.0F * SWC_VC_B.b_W0_idx_0 * SWC_VC_B.i_o;
        SWC_VC_B.b_W2 = ((SWC_VC_B.x_max - SWC_VC_B.beta1) * 3.0F *
                         SWC_VC_B.b_W0_idx_1 + 3.0F * SWC_VC_B.beta1 *
                         SWC_VC_B.i_o) + 0.333333343F * SWC_VC_B.a * rt_powf_snf
          (SWC_VC_B.i_o, 3.0F);
        SWC_VC_B.idx = (uint8_T)SWC_VC_B.idx - 1;
        x_out[SWC_VC_B.idx] = SWC_VC_B.theta_rotation * SWC_VC_B.alpha3 +
          SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.b_W2;
        y_out[SWC_VC_B.idx] = -SWC_VC_B.Rot_tmp_tmp * SWC_VC_B.alpha3 +
          SWC_VC_B.theta_rotation * SWC_VC_B.b_W2;
        SWC_VC_B.i_o += SWC_VC_B.step_size_i;
      }
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_renderPath_fishbone(const real32_T pii[30], real32_T fxo[250],
  real32_T fyo[250], real32_T fho[250], real32_T KeAP_fvo[250], real32_T
  KeAP_fso[250], int16_T fio[10], int8_T *co)
{
  boolean_T no_str_flag;
  uint8_T total_num_idx_34;
  boolean_T forward_fishbone;
  boolean_T regen_mode_fb;
  int8_T dir;
  boolean_T run_once;
  boolean_T run_twice;
  int8_T direction_flag_W2;
  uint8_T b_counter;
  uint8_T e_i;
  uint16_T l_i;
  int16_T KeAP_fso_tmp;
  uint8_T fio_tmp;
  int16_T tmp;
  int32_T exitg1;
  *co = 1;
  no_str_flag = true;
  SWC_VC_B.init_wheel_angle_h3 = pii[29];
  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 10; SWC_VC_B.counter++) {
    SWC_VC_B.pp_tmp_o = SWC_VC_B.counter << 1;
    SWC_VC_B.pp_m3[SWC_VC_B.pp_tmp_o] = pii[SWC_VC_B.counter];
    SWC_VC_B.pp_m3[SWC_VC_B.pp_tmp_o + 1] = pii[SWC_VC_B.counter + 10];
    SWC_VC_B.Phi_guideline_p[SWC_VC_B.counter] = pii[SWC_VC_B.counter + 20];
    SWC_VC_B.n_segment_f[SWC_VC_B.counter] = 50U;
    fio[SWC_VC_B.counter] = 0;
  }

  if (!SWC_VC_B.RateTransition3_i) {
    SWC_VC_B.regen_mode_fb_tmp = fabsf(pii[27]);
    regen_mode_fb = (((SWC_VC_B.regen_mode_fb_tmp > 25.0F) &&
                      (!(SWC_VC_B.regen_mode_fb_tmp < 155.0F))) ||
                     (!(SWC_VC_B.regen_mode_fb_tmp > 25.0F)));
    forward_fishbone = (pii[27] < 90.0F);
    if (!regen_mode_fb) {
      SWC_VC_B.heading_angle[0] = pii[20] + 180.0F;
      SWC_VC_B.x_path[0] = SWC_VC_B.pp_m3[0];
      SWC_VC_B.y_path[0] = SWC_VC_B.pp_m3[1];
      if (forward_fishbone && (SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4])) {
        dir = -1;
      } else if (!forward_fishbone) {
        if (SWC_VC_B.pp_m3[0] < SWC_VC_B.pp_m3[4]) {
          dir = -1;
        } else {
          dir = 1;
        }
      } else {
        dir = 1;
      }

      SWC_VC_B.counter = 1;
      while (SWC_VC_B.counter - 1 <= ((uint8_T)num_points_no_str_fb) - 2) {
        SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.init_wheel_angle_h3;
        tand_brbYAlcS(&SWC_VC_B.regen_mode_fb_tmp);
        SWC_VC_B.heading_angle[SWC_VC_B.counter] = ((real32_T)dir *
          SWC_VC_B.regen_mode_fb_tmp * delta_s_no_str_fb / MeAP_m_VehWheelbase +
          SWC_VC_B.heading_angle[SWC_VC_B.counter - 1] * 3.14159274F / 180.0F) *
          180.0F / 3.14159274F;
        SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.heading_angle[SWC_VC_B.counter];
        cosd_KZN3FnAl(&SWC_VC_B.regen_mode_fb_tmp);
        SWC_VC_B.x_path[SWC_VC_B.counter] = SWC_VC_B.x_path[SWC_VC_B.counter - 1]
          - delta_s_no_str_fb * SWC_VC_B.regen_mode_fb_tmp * (real32_T)dir;
        SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.heading_angle[SWC_VC_B.counter];
        sind_7is3Ljjc(&SWC_VC_B.regen_mode_fb_tmp);
        SWC_VC_B.y_path[SWC_VC_B.counter] = SWC_VC_B.y_path[SWC_VC_B.counter - 1]
          - delta_s_no_str_fb * SWC_VC_B.regen_mode_fb_tmp * (real32_T)dir;
        SWC_VC_B.counter++;
      }

      SWC_VC_B.pp_tmp_o = ((uint8_T)num_points_no_str_fb) - 1;
      SWC_VC_B.pp_m3[2] = SWC_VC_B.x_path[SWC_VC_B.pp_tmp_o];
      SWC_VC_B.pp_m3[3] = SWC_VC_B.y_path[SWC_VC_B.pp_tmp_o];
      SWC_VC_B.Phi_guideline_p[1] = SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] -
        180.0F;
      SWC_VC_B.n_segment_f[0] = ((uint8_T)num_points_no_str_fb);
      if (forward_fishbone) {
        if (!(SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4] - 3.5F)) {
          if (SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4]) {
            SWC_VC_B.regen_mode_fb_tmp =
              SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
            cosd_KZN3FnAl(&SWC_VC_B.regen_mode_fb_tmp);
            SWC_VC_B.h = SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
            sind_7is3Ljjc(&SWC_VC_B.h);
            SWC_VC_B.pp_m3[4] = SWC_VC_B.x_path[SWC_VC_B.pp_tmp_o] -
              SWC_VC_B.regen_mode_fb_tmp * 3.5F;
            SWC_VC_B.pp_m3[5] = SWC_VC_B.y_path[SWC_VC_B.pp_tmp_o] - SWC_VC_B.h *
              3.5F;
          } else {
            SWC_VC_B.n_segment_f[1] = 0U;
            SWC_VC_B.pp_m3[4] = SWC_VC_B.x_path[SWC_VC_B.pp_tmp_o];
            SWC_VC_B.pp_m3[5] = SWC_VC_B.y_path[SWC_VC_B.pp_tmp_o];
            SWC_VC_B.Phi_guideline_p[2] =
              SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
          }
        }
      } else {
        if (!(SWC_VC_B.pp_m3[0] >= SWC_VC_B.pp_m3[4] + 3.5F)) {
          if (SWC_VC_B.pp_m3[0] >= SWC_VC_B.pp_m3[4]) {
            SWC_VC_B.regen_mode_fb_tmp =
              SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
            cosd_KZN3FnAl(&SWC_VC_B.regen_mode_fb_tmp);
            SWC_VC_B.h = SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
            sind_7is3Ljjc(&SWC_VC_B.h);
            SWC_VC_B.pp_m3[4] = SWC_VC_B.x_path[SWC_VC_B.pp_tmp_o] +
              SWC_VC_B.regen_mode_fb_tmp * 3.5F;
            SWC_VC_B.pp_m3[5] = SWC_VC_B.y_path[SWC_VC_B.pp_tmp_o] + SWC_VC_B.h *
              3.5F;
          } else {
            SWC_VC_B.n_segment_f[1] = 0U;
            SWC_VC_B.pp_m3[4] = SWC_VC_B.x_path[SWC_VC_B.pp_tmp_o];
            SWC_VC_B.pp_m3[5] = SWC_VC_B.y_path[SWC_VC_B.pp_tmp_o];
            SWC_VC_B.Phi_guideline_p[2] =
              SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] - 180.0F;
          }
        }
      }
    } else {
      no_str_flag = false;
      SWC_VC_B.n_segment_f[0] = 1U;
      SWC_VC_B.x_path[0] = SWC_VC_B.pp_m3[0];
      SWC_VC_B.y_path[0] = SWC_VC_B.pp_m3[1];
      SWC_VC_B.pp_m3[2] = SWC_VC_B.pp_m3[0];
      SWC_VC_B.pp_m3[3] = SWC_VC_B.pp_m3[1];
      SWC_VC_B.Phi_guideline_p[1] = pii[20];
      SWC_VC_B.h_tmp_tmp = 180.0F * (real32_T)forward_fishbone;
      SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.h_tmp_tmp + pii[20];
      SWC_VC_B.h = SWC_VC_B.regen_mode_fb_tmp;
      cosd_KZN3FnAl(&SWC_VC_B.h);
      sind_7is3Ljjc(&SWC_VC_B.regen_mode_fb_tmp);
      SWC_VC_B.h_tmp_tmp += pii[24];
      SWC_VC_B.l = SWC_VC_B.h_tmp_tmp;
      cosd_KZN3FnAl(&SWC_VC_B.l);
      sind_7is3Ljjc(&SWC_VC_B.h_tmp_tmp);
      SWC_VC_B.h = (2.0F * SWC_VC_B.h + SWC_VC_B.l) / 3.0F * length_regen_fb;
      SWC_VC_B.pp_m3[4] = SWC_VC_B.h + SWC_VC_B.pp_m3[8];
      SWC_VC_B.pp_o[0] = SWC_VC_B.pp_m3[2] - (SWC_VC_B.h + SWC_VC_B.pp_m3[8]);
      SWC_VC_B.h = (2.0F * SWC_VC_B.regen_mode_fb_tmp + SWC_VC_B.h_tmp_tmp) /
        3.0F * length_regen_fb + SWC_VC_B.pp_m3[9];
      SWC_VC_B.pp_m3[5] = SWC_VC_B.h;
      SWC_VC_B.pp_o[1] = SWC_VC_B.pp_m3[1] - SWC_VC_B.h;
      if (norm_5ISqY4yY(SWC_VC_B.pp_o) < 3.0F) {
        SWC_VC_B.P0[0] = SWC_VC_B.pp_m3[4] - SWC_VC_B.pp_m3[8];
        SWC_VC_B.P0[1] = SWC_VC_B.h - SWC_VC_B.pp_m3[9];
        SWC_VC_B.regen_mode_fb_tmp = norm_5ISqY4yY(SWC_VC_B.P0);
        SWC_VC_B.counter = forward_fishbone + 2;
        SWC_VC_B.pp_m3[4] += SWC_VC_B.P0[0] / SWC_VC_B.regen_mode_fb_tmp *
          (real32_T)SWC_VC_B.counter;
        SWC_VC_B.pp_m3[5] = SWC_VC_B.P0[1] / SWC_VC_B.regen_mode_fb_tmp *
          (real32_T)SWC_VC_B.counter + SWC_VC_B.h;
      }

      SWC_VC_B.Phi_guideline_p[2] = (pii[20] + pii[24]) / 2.0F;
      if (!forward_fishbone) {
        SWC_VC_B.P0[0] = SWC_VC_B.pp_m3[6] - SWC_VC_B.pp_m3[8];
        SWC_VC_B.P0[1] = SWC_VC_B.pp_m3[7] - SWC_VC_B.pp_m3[9];
        SWC_VC_B.regen_mode_fb_tmp = norm_5ISqY4yY(SWC_VC_B.P0);
        SWC_VC_B.pp_m3[6] -= SWC_VC_B.P0[0] / SWC_VC_B.regen_mode_fb_tmp;
        SWC_VC_B.pp_m3[7] -= SWC_VC_B.P0[1] / SWC_VC_B.regen_mode_fb_tmp;
      }
    }

    SWC_VC_B.n_segment_f[3] = ((uint8_T)n_fb);
    SWC_VC_B.counter = 0;
    while (SWC_VC_B.counter + 1 <= ((uint8_T)n_fb)) {
      SWC_VC_B.regen_mode_fb_tmp = (real32_T)(SWC_VC_B.counter + 1) - 1.0F;
      SWC_VC_B.pp_tmp_o = ((uint8_T)n_fb) - 1;
      SWC_VC_B.h = (SWC_VC_B.pp_m3[6] - SWC_VC_B.pp_m3[8]) *
        SWC_VC_B.regen_mode_fb_tmp / (real32_T)SWC_VC_B.pp_tmp_o;
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.h;
      SWC_VC_B.P0[0] = SWC_VC_B.h;
      SWC_VC_B.h = (SWC_VC_B.pp_m3[7] - SWC_VC_B.pp_m3[9]) *
        SWC_VC_B.regen_mode_fb_tmp / (real32_T)SWC_VC_B.pp_tmp_o;
      SWC_VC_B.h_tmp_tmp += SWC_VC_B.h * 0.0F;
      fxo[SWC_VC_B.counter] = SWC_VC_B.pp_m3[8] + SWC_VC_B.h_tmp_tmp;
      fyo[SWC_VC_B.counter] = (SWC_VC_B.P0[0] * 0.0F + SWC_VC_B.h) +
        SWC_VC_B.pp_m3[9];
      SWC_VC_B.counter++;
    }

    run_once = true;
    run_twice = false;
    while (run_once || run_twice) {
      run_once = false;
      SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.pp_m3[4] - SWC_VC_B.pp_m3[6];
      SWC_VC_B.h = SWC_VC_B.pp_m3[5] - SWC_VC_B.pp_m3[7];
      SWC_VC_B.extremum_c = pii[23];
      cosd_KZN3FnAl(&SWC_VC_B.extremum_c);
      SWC_VC_B.h_tmp_tmp = pii[23];
      sind_7is3Ljjc(&SWC_VC_B.h_tmp_tmp);
      if (SWC_VC_B.regen_mode_fb_tmp * SWC_VC_B.extremum_c + SWC_VC_B.h *
          SWC_VC_B.h_tmp_tmp >= 0.0F) {
        dir = 1;
      } else {
        dir = -1;
      }

      SWC_VC_B.extremum_c = SWC_VC_B.Phi_guideline_p[2];
      cosd_KZN3FnAl(&SWC_VC_B.extremum_c);
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[2];
      sind_7is3Ljjc(&SWC_VC_B.h_tmp_tmp);
      if (SWC_VC_B.regen_mode_fb_tmp * SWC_VC_B.extremum_c + SWC_VC_B.h *
          SWC_VC_B.h_tmp_tmp >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.extremum_c = fmaxf(fabsf(SWC_VC_B.regen_mode_fb_tmp), fabsf
        (SWC_VC_B.h)) * vecLen_coeff_fb;
      SWC_VC_B.h_tmp_tmp = pii[23];
      cosd_KZN3FnAl(&SWC_VC_B.h_tmp_tmp);
      SWC_VC_B.l = pii[23];
      sind_7is3Ljjc(&SWC_VC_B.l);
      SWC_VC_B.Y_e[0] = SWC_VC_B.extremum_c * SWC_VC_B.h_tmp_tmp * (real32_T)dir;
      SWC_VC_B.Y_e[1] = SWC_VC_B.extremum_c * SWC_VC_B.l * (real32_T)dir;
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[2];
      cosd_KZN3FnAl(&SWC_VC_B.h_tmp_tmp);
      SWC_VC_B.l = SWC_VC_B.Phi_guideline_p[2];
      sind_7is3Ljjc(&SWC_VC_B.l);
      SWC_VC_B.X_p[0] = SWC_VC_B.extremum_c * SWC_VC_B.h_tmp_tmp * (real32_T)
        direction_flag_W2;
      SWC_VC_B.X_p[1] = SWC_VC_B.extremum_c * SWC_VC_B.l * (real32_T)
        direction_flag_W2;
      SWC_VC_B.pp_o[0] = SWC_VC_B.regen_mode_fb_tmp;
      SWC_VC_B.P0[0] = (SWC_VC_B.regen_mode_fb_tmp - SWC_VC_B.Y_e[0]) -
        SWC_VC_B.X_p[0];
      SWC_VC_B.pp_o[1] = SWC_VC_B.h;
      SWC_VC_B.P0[1] = (SWC_VC_B.h - SWC_VC_B.Y_e[1]) - SWC_VC_B.X_p[1];
      SWC_VC_B.extremum_c = floorf(norm_5ISqY4yY(SWC_VC_B.pp_o) / delta_s_fb);
      if (SWC_VC_B.extremum_c < 256.0F) {
        if (SWC_VC_B.extremum_c >= 0.0F) {
          b_counter = (uint8_T)SWC_VC_B.extremum_c;
        } else {
          b_counter = 0U;
        }
      } else {
        b_counter = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function(SWC_VC_B.Y_e, SWC_VC_B.P0, SWC_VC_B.X_p,
        b_counter, &SWC_VC_B.extremum_c, SWC_VC_B.heading_angle, SWC_VC_B.y_out,
        &SWC_VC_B.n_segment_f[2]);
      if ((SWC_VC_B.extremum_c > MeAP_pm_maxCurvature) && (!run_twice)) {
        if (!regen_mode_fb) {
          SWC_VC_B.pp_m3[5]--;
        } else {
          SWC_VC_B.X_p[0] = SWC_VC_B.regen_mode_fb_tmp;
          SWC_VC_B.X_p[1] = SWC_VC_B.h;
          SWC_VC_B.h_tmp_tmp = norm_5ISqY4yY(SWC_VC_B.X_p);
          SWC_VC_B.pp_m3[4] += SWC_VC_B.regen_mode_fb_tmp / SWC_VC_B.h_tmp_tmp;
          SWC_VC_B.pp_m3[5] += SWC_VC_B.h / SWC_VC_B.h_tmp_tmp;
        }

        run_twice = true;
      } else {
        run_twice = false;
      }

      SWC_VC_B.pp_tmp_o = 0;
      while (SWC_VC_B.pp_tmp_o <= SWC_VC_B.n_segment_f[2] - 2) {
        SWC_VC_B.counter = ((uint8_T)n_fb) + SWC_VC_B.pp_tmp_o;
        fxo[SWC_VC_B.counter] = SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o + 1] +
          SWC_VC_B.pp_m3[6];
        fyo[SWC_VC_B.counter] = SWC_VC_B.y_out[SWC_VC_B.pp_tmp_o + 1] +
          SWC_VC_B.pp_m3[7];
        SWC_VC_B.pp_tmp_o++;
      }

      SWC_VC_B.qY_c3 = SWC_VC_B.n_segment_f[2] - /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY_c3 > SWC_VC_B.n_segment_f[2]) {
        SWC_VC_B.qY_c3 = 0U;
      }

      SWC_VC_B.n_segment_f[2] = (uint8_T)SWC_VC_B.qY_c3;
    }

    if (SWC_VC_B.extremum_c > MeAP_pm_maxCurvature) {
      *co = -13;
    }

    if ((forward_fishbone && (SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4])) ||
        ((!forward_fishbone) && (SWC_VC_B.pp_m3[0] >= SWC_VC_B.pp_m3[4])) ||
        regen_mode_fb) {
      fio[1] = sum_lsjEpyTA(&SWC_VC_B.n_segment_f[2]);
      SWC_VC_post_render(fxo, fyo, 1, (uint8_T)fio[1], Kf_fb, delta_s_fb,
                         SWC_VC_B.fxo_dummy, SWC_VC_B.fyo_dummy, &b_counter);
      SWC_VC_B.qY_tmp_i = b_counter - /*MW:OvSatOk*/ 1U;
      SWC_VC_B.qY_c3 = SWC_VC_B.qY_tmp_i;
      if (SWC_VC_B.qY_tmp_i > b_counter) {
        SWC_VC_B.qY_c3 = 0U;
      }

      total_num_idx_34 = (uint8_T)SWC_VC_B.qY_c3;
      SWC_VC_B.counter = 0;
      while (SWC_VC_B.counter <= (uint8_T)SWC_VC_B.qY_c3) {
        fxo[SWC_VC_B.counter] = SWC_VC_B.fxo_dummy[SWC_VC_B.counter];
        fyo[SWC_VC_B.counter] = SWC_VC_B.fyo_dummy[SWC_VC_B.counter];
        if (forward_fishbone) {
          SWC_VC_B.fgo[SWC_VC_B.counter] = 1;
        } else {
          SWC_VC_B.fgo[SWC_VC_B.counter] = -1;
        }

        SWC_VC_B.counter++;
      }

      if (forward_fishbone) {
        fio[1] = (uint8_T)SWC_VC_B.qY_c3;
      } else {
        fio[1] = (int16_T)-(uint8_T)SWC_VC_B.qY_c3;
      }

      SWC_VC_B.pp_m3[4] = fxo[(uint8_T)SWC_VC_B.qY_c3];
      SWC_VC_B.pp_m3[5] = fyo[(uint8_T)SWC_VC_B.qY_c3];
      SWC_VC_B.qY_c3 = SWC_VC_B.qY_tmp_i;
      if (SWC_VC_B.qY_tmp_i > b_counter) {
        SWC_VC_B.qY_c3 = 0U;
        SWC_VC_B.qY_tmp_i = 0U;
      }

      SWC_VC_B.counter = b_counter - 1;
      SWC_VC_B.Phi_guideline_p[2] = rt_atan2f_snf
        (SWC_VC_B.fyo_dummy[SWC_VC_B.counter] - SWC_VC_B.fyo_dummy[(int32_T)
         SWC_VC_B.qY_c3 - 1], SWC_VC_B.fxo_dummy[SWC_VC_B.counter] -
         SWC_VC_B.fxo_dummy[(int32_T)SWC_VC_B.qY_tmp_i - 1]) * 57.2957802F -
        180.0F * (real32_T)forward_fishbone;
    } else {
      SWC_VC_B.pp_tmp_o = (int32_T)((uint32_T)SWC_VC_B.n_segment_f[2] +
        ((uint8_T)n_fb));
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      total_num_idx_34 = (uint8_T)SWC_VC_B.pp_tmp_o;
    }

    if ((forward_fishbone && (SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4])) ||
        ((!forward_fishbone) && (SWC_VC_B.pp_m3[0] >= SWC_VC_B.pp_m3[4])) ||
        regen_mode_fb) {
      SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.pp_m3[2] - SWC_VC_B.pp_m3[4];
      SWC_VC_B.h = SWC_VC_B.pp_m3[3] - SWC_VC_B.pp_m3[5];
      SWC_VC_B.extremum_c = SWC_VC_B.Phi_guideline_p[2];
      cosd_KZN3FnAl(&SWC_VC_B.extremum_c);
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[2];
      sind_7is3Ljjc(&SWC_VC_B.h_tmp_tmp);
      if (SWC_VC_B.regen_mode_fb_tmp * SWC_VC_B.extremum_c + SWC_VC_B.h *
          SWC_VC_B.h_tmp_tmp >= 0.0F) {
        dir = 1;
      } else {
        dir = -1;
      }

      SWC_VC_B.extremum_c = SWC_VC_B.Phi_guideline_p[1];
      cosd_KZN3FnAl(&SWC_VC_B.extremum_c);
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[1];
      sind_7is3Ljjc(&SWC_VC_B.h_tmp_tmp);
      if (SWC_VC_B.regen_mode_fb_tmp * SWC_VC_B.extremum_c + SWC_VC_B.h *
          SWC_VC_B.h_tmp_tmp >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.extremum_c = fmaxf(fabsf(SWC_VC_B.regen_mode_fb_tmp), fabsf
        (SWC_VC_B.h)) * vecLen_coeff_fb;
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[2];
      cosd_KZN3FnAl(&SWC_VC_B.h_tmp_tmp);
      SWC_VC_B.l = SWC_VC_B.Phi_guideline_p[2];
      sind_7is3Ljjc(&SWC_VC_B.l);
      SWC_VC_B.Y_e[0] = SWC_VC_B.extremum_c * SWC_VC_B.h_tmp_tmp * (real32_T)dir;
      SWC_VC_B.Y_e[1] = SWC_VC_B.extremum_c * SWC_VC_B.l * (real32_T)dir;
      SWC_VC_B.h_tmp_tmp = SWC_VC_B.Phi_guideline_p[1];
      cosd_KZN3FnAl(&SWC_VC_B.h_tmp_tmp);
      SWC_VC_B.l = SWC_VC_B.Phi_guideline_p[1];
      sind_7is3Ljjc(&SWC_VC_B.l);
      SWC_VC_B.X_p[0] = SWC_VC_B.extremum_c * SWC_VC_B.h_tmp_tmp * (real32_T)
        direction_flag_W2;
      SWC_VC_B.X_p[1] = SWC_VC_B.extremum_c * SWC_VC_B.l * (real32_T)
        direction_flag_W2;
      SWC_VC_B.pp_o[0] = SWC_VC_B.regen_mode_fb_tmp;
      SWC_VC_B.P0[0] = (SWC_VC_B.regen_mode_fb_tmp - SWC_VC_B.Y_e[0]) -
        SWC_VC_B.X_p[0];
      SWC_VC_B.pp_o[1] = SWC_VC_B.h;
      SWC_VC_B.P0[1] = (SWC_VC_B.h - SWC_VC_B.Y_e[1]) - SWC_VC_B.X_p[1];
      SWC_VC_B.extremum_c = floorf(norm_5ISqY4yY(SWC_VC_B.pp_o) / delta_s_fb);
      if (SWC_VC_B.extremum_c < 256.0F) {
        if (SWC_VC_B.extremum_c >= 0.0F) {
          b_counter = (uint8_T)SWC_VC_B.extremum_c;
        } else {
          b_counter = 0U;
        }
      } else {
        b_counter = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function(SWC_VC_B.Y_e, SWC_VC_B.P0, SWC_VC_B.X_p,
        b_counter, &SWC_VC_B.extremum_c, SWC_VC_B.heading_angle, SWC_VC_B.y_out,
        &SWC_VC_B.n_segment_f[1]);
      if (SWC_VC_B.extremum_c > MeAP_pm_maxCurvature) {
        *co = -12;
      }

      SWC_VC_B.qY_c3 = SWC_VC_B.n_segment_f[1] - /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY_c3 > SWC_VC_B.n_segment_f[1]) {
        SWC_VC_B.qY_c3 = 0U;
      }

      SWC_VC_B.n_segment_f[1] = (uint8_T)SWC_VC_B.qY_c3;
      SWC_VC_B.pp_tmp_o = 0;
      while (SWC_VC_B.pp_tmp_o <= (uint8_T)SWC_VC_B.qY_c3 - 1) {
        SWC_VC_B.counter = total_num_idx_34 + SWC_VC_B.pp_tmp_o;
        fxo[SWC_VC_B.counter] = SWC_VC_B.heading_angle[SWC_VC_B.pp_tmp_o] +
          SWC_VC_B.pp_m3[4];
        fyo[SWC_VC_B.counter] = SWC_VC_B.y_out[SWC_VC_B.pp_tmp_o] +
          SWC_VC_B.pp_m3[5];
        SWC_VC_B.pp_tmp_o++;
      }
    }

    if ((forward_fishbone && (SWC_VC_B.pp_m3[0] <= SWC_VC_B.pp_m3[4])) ||
        ((!forward_fishbone) && (SWC_VC_B.pp_m3[0] >= SWC_VC_B.pp_m3[4])) ||
        regen_mode_fb) {
      fio_tmp = sum_lsjEpyTA(&SWC_VC_B.n_segment_f[0]);
      b_counter = 1U;
      SWC_VC_B.pp_tmp_o = (int32_T)((uint32_T)total_num_idx_34 + fio_tmp);
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      SWC_VC_B.h_i = (int32_T)((uint32_T)total_num_idx_34 +
        SWC_VC_B.n_segment_f[1]);
      if ((uint32_T)SWC_VC_B.h_i > 255U) {
        SWC_VC_B.h_i = 255;
      }

      SWC_VC_B.h_i++;
      if ((uint32_T)SWC_VC_B.h_i > 255U) {
        SWC_VC_B.h_i = 255;
      }

      for (e_i = (uint8_T)SWC_VC_B.h_i; e_i <= (uint8_T)SWC_VC_B.pp_tmp_o; e_i++)
      {
        SWC_VC_B.h_i = (int32_T)(SWC_VC_B.n_segment_f[0] + 1U);
        if ((uint32_T)SWC_VC_B.h_i > 255U) {
          SWC_VC_B.h_i = 255;
        }

        SWC_VC_B.qY_c3 = (uint32_T)SWC_VC_B.h_i - /*MW:OvSatOk*/ b_counter;
        if (SWC_VC_B.qY_c3 > (uint32_T)SWC_VC_B.h_i) {
          SWC_VC_B.qY_c3 = 0U;
        }

        SWC_VC_B.counter = e_i - 1;
        fxo[SWC_VC_B.counter] = SWC_VC_B.x_path[(int32_T)SWC_VC_B.qY_c3 - 1];
        SWC_VC_B.h_i = (int32_T)(SWC_VC_B.n_segment_f[0] + 1U);
        if ((uint32_T)SWC_VC_B.h_i > 255U) {
          SWC_VC_B.h_i = 255;
        }

        SWC_VC_B.qY_c3 = (uint32_T)SWC_VC_B.h_i - /*MW:OvSatOk*/ b_counter;
        if (SWC_VC_B.qY_c3 > (uint32_T)SWC_VC_B.h_i) {
          SWC_VC_B.qY_c3 = 0U;
        }

        fyo[SWC_VC_B.counter] = SWC_VC_B.y_path[(int32_T)SWC_VC_B.qY_c3 - 1];
        SWC_VC_B.h_i = (int32_T)(b_counter + 1U);
        if ((uint32_T)SWC_VC_B.h_i > 255U) {
          SWC_VC_B.h_i = 255;
        }

        b_counter = (uint8_T)SWC_VC_B.h_i;
      }

      SWC_VC_B.pp_tmp_o = abs_NgDyBNHZ(fio[1]);
      SWC_VC_B.h_i = SWC_VC_B.pp_tmp_o + 1;
      if (SWC_VC_B.h_i > 32767) {
        SWC_VC_B.h_i = 32767;
      }

      KeAP_fso_tmp = (int16_T)SWC_VC_B.h_i;
      if ((int16_T)SWC_VC_B.h_i < 0) {
        KeAP_fso_tmp = 0;
      } else {
        if ((int16_T)SWC_VC_B.h_i > 255) {
          KeAP_fso_tmp = 255;
        }
      }

      SWC_VC_B.pp_tmp_o += fio_tmp;
      if (SWC_VC_B.pp_tmp_o > 32767) {
        SWC_VC_B.pp_tmp_o = 32767;
      }

      tmp = (int16_T)SWC_VC_B.pp_tmp_o;
      if ((int16_T)SWC_VC_B.pp_tmp_o < 0) {
        tmp = 0;
      } else {
        if ((int16_T)SWC_VC_B.pp_tmp_o > 255) {
          tmp = 255;
        }
      }

      SWC_VC_post_render(fxo, fyo, (uint8_T)KeAP_fso_tmp, (uint8_T)tmp, Kf_fb,
                         delta_s_fb, SWC_VC_B.fxo_dummy, SWC_VC_B.fyo_dummy,
                         &fio_tmp);
      b_counter = 1U;
      SWC_VC_B.pp_tmp_o = (int32_T)((uint32_T)fio_tmp + total_num_idx_34);
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      SWC_VC_B.h_i = (int32_T)(total_num_idx_34 + 1U);
      if ((uint32_T)SWC_VC_B.h_i > 255U) {
        SWC_VC_B.h_i = 255;
      }

      for (total_num_idx_34 = (uint8_T)SWC_VC_B.h_i; total_num_idx_34 <=
           (uint8_T)SWC_VC_B.pp_tmp_o; total_num_idx_34++) {
        SWC_VC_B.counter = b_counter - 1;
        SWC_VC_B.h_i = total_num_idx_34 - 1;
        fxo[SWC_VC_B.h_i] = SWC_VC_B.fxo_dummy[SWC_VC_B.counter];
        fyo[SWC_VC_B.h_i] = SWC_VC_B.fyo_dummy[SWC_VC_B.counter];
        if (forward_fishbone) {
          SWC_VC_B.fgo[SWC_VC_B.h_i] = -1;
        } else {
          SWC_VC_B.fgo[SWC_VC_B.h_i] = 1;
        }

        SWC_VC_B.h_i = (int32_T)(b_counter + 1U);
        if ((uint32_T)SWC_VC_B.h_i > 255U) {
          SWC_VC_B.h_i = 255;
        }

        b_counter = (uint8_T)SWC_VC_B.h_i;
      }

      if (forward_fishbone) {
        fio[0] = (int16_T)-fio_tmp;
      } else {
        fio[0] = fio_tmp;
      }
    } else {
      fio_tmp = sum_XHaVrCkY(&SWC_VC_B.n_segment_f[0]);
      b_counter = 1U;
      SWC_VC_B.pp_tmp_o = (int32_T)(sum_1dSfq50U(&SWC_VC_B.n_segment_f[1]) + 1U);
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      for (total_num_idx_34 = (uint8_T)SWC_VC_B.pp_tmp_o; total_num_idx_34 <=
           fio_tmp; total_num_idx_34++) {
        SWC_VC_B.pp_tmp_o = (int32_T)(SWC_VC_B.n_segment_f[0] + 1U);
        SWC_VC_B.h_i = SWC_VC_B.pp_tmp_o;
        if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
          SWC_VC_B.h_i = 255;
        }

        SWC_VC_B.qY_c3 = (uint32_T)SWC_VC_B.h_i - /*MW:OvSatOk*/ b_counter;
        if (SWC_VC_B.qY_c3 > (uint32_T)SWC_VC_B.h_i) {
          SWC_VC_B.qY_c3 = 0U;
        }

        SWC_VC_B.counter = total_num_idx_34 - 1;
        fxo[SWC_VC_B.counter] = SWC_VC_B.x_path[(int32_T)SWC_VC_B.qY_c3 - 1];
        if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
          SWC_VC_B.pp_tmp_o = 255;
        }

        SWC_VC_B.qY_c3 = (uint32_T)SWC_VC_B.pp_tmp_o - /*MW:OvSatOk*/ b_counter;
        if (SWC_VC_B.qY_c3 > (uint32_T)SWC_VC_B.pp_tmp_o) {
          SWC_VC_B.qY_c3 = 0U;
        }

        fyo[SWC_VC_B.counter] = SWC_VC_B.y_path[(int32_T)SWC_VC_B.qY_c3 - 1];
        SWC_VC_B.pp_tmp_o = (int32_T)(b_counter + 1U);
        if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
          SWC_VC_B.pp_tmp_o = 255;
        }

        b_counter = (uint8_T)SWC_VC_B.pp_tmp_o;
      }

      SWC_VC_post_render(fxo, fyo, 1, fio_tmp, Kf_fb, delta_s_fb,
                         SWC_VC_B.fxo_dummy, SWC_VC_B.fyo_dummy,
                         &total_num_idx_34);
      b_counter = 1U;
      SWC_VC_B.h_i = 0;
      while (SWC_VC_B.h_i <= total_num_idx_34 - 1) {
        SWC_VC_B.counter = b_counter - 1;
        fxo[SWC_VC_B.h_i] = SWC_VC_B.fxo_dummy[SWC_VC_B.counter];
        fyo[SWC_VC_B.h_i] = SWC_VC_B.fyo_dummy[SWC_VC_B.counter];
        if (forward_fishbone) {
          SWC_VC_B.fgo[SWC_VC_B.h_i] = 1;
        } else {
          SWC_VC_B.fgo[SWC_VC_B.h_i] = -1;
        }

        SWC_VC_B.pp_tmp_o = (int32_T)(b_counter + 1U);
        if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
          SWC_VC_B.pp_tmp_o = 255;
        }

        b_counter = (uint8_T)SWC_VC_B.pp_tmp_o;
        SWC_VC_B.h_i++;
      }

      if (forward_fishbone) {
        fio[0] = total_num_idx_34;
      } else {
        fio[0] = (int16_T)-total_num_idx_34;
      }
    }

    memcpy(&SWC_VC_B.fxo_dummy[0], &fxo[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fyo_dummy[0], &fyo[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fgo_dummy[0], &SWC_VC_B.fgo[0], 250U * sizeof(int8_T));
    SWC_VC_B.pp_tmp_o = abs_NgDyBNHZ(fio[0]) + abs_NgDyBNHZ(fio[1]);
    SWC_VC_B.h_i = SWC_VC_B.pp_tmp_o;
    if (SWC_VC_B.pp_tmp_o > 32767) {
      SWC_VC_B.h_i = 32767;
    } else {
      if (SWC_VC_B.pp_tmp_o < -32768) {
        SWC_VC_B.h_i = -32768;
      }
    }

    SWC_VC_B.i_i = 1;
    while (SWC_VC_B.i_i - 1 <= (int16_T)SWC_VC_B.h_i - 1) {
      SWC_VC_B.i5 = SWC_VC_B.pp_tmp_o;
      if (SWC_VC_B.pp_tmp_o > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.pp_tmp_o < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      SWC_VC_B.i5++;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      }

      SWC_VC_B.i5 -= (int16_T)SWC_VC_B.i_i;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.i5 < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      SWC_VC_B.counter = (int16_T)SWC_VC_B.i_i - 1;
      fxo[SWC_VC_B.counter] = SWC_VC_B.fxo_dummy[SWC_VC_B.i5 - 1];
      SWC_VC_B.i5 = SWC_VC_B.pp_tmp_o;
      if (SWC_VC_B.pp_tmp_o > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.pp_tmp_o < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      SWC_VC_B.i5++;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      }

      SWC_VC_B.i5 -= (int16_T)SWC_VC_B.i_i;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.i5 < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      fyo[SWC_VC_B.counter] = SWC_VC_B.fyo_dummy[SWC_VC_B.i5 - 1];
      SWC_VC_B.i5 = SWC_VC_B.pp_tmp_o;
      if (SWC_VC_B.pp_tmp_o > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.pp_tmp_o < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      SWC_VC_B.i5++;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      }

      SWC_VC_B.i5 -= (int16_T)SWC_VC_B.i_i;
      if (SWC_VC_B.i5 > 32767) {
        SWC_VC_B.i5 = 32767;
      } else {
        if (SWC_VC_B.i5 < -32768) {
          SWC_VC_B.i5 = -32768;
        }
      }

      SWC_VC_B.fgo[SWC_VC_B.counter] = SWC_VC_B.fgo_dummy[SWC_VC_B.i5 - 1];
      SWC_VC_B.i_i++;
    }
  }

  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 10; SWC_VC_B.counter++) {
    SWC_VC_B.fio_dummy_o[SWC_VC_B.counter] = 0;
  }

  b_counter = 0U;
  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 10; SWC_VC_B.counter++) {
    if (fio[SWC_VC_B.counter] != 0) {
      SWC_VC_B.pp_tmp_o = (int32_T)(b_counter + 1U);
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      b_counter = (uint8_T)SWC_VC_B.pp_tmp_o;
      SWC_VC_B.fio_dummy_o[(uint8_T)SWC_VC_B.pp_tmp_o - 1] =
        fio[SWC_VC_B.counter];
    }
  }

  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 10; SWC_VC_B.counter++) {
    fio[SWC_VC_B.counter] = SWC_VC_B.fio_dummy_o[SWC_VC_B.counter];
  }

  diff_PkLl8BoA(fxo, SWC_VC_B.fv7);
  diff_PkLl8BoA(fyo, SWC_VC_B.fv6);
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 249; SWC_VC_B.pp_tmp_o++) {
    SWC_VC_B.extremum_c = -(real32_T)SWC_VC_B.fgo[SWC_VC_B.pp_tmp_o + 1];
    SWC_VC_B.dfx[SWC_VC_B.pp_tmp_o] = SWC_VC_B.extremum_c *
      SWC_VC_B.fv7[SWC_VC_B.pp_tmp_o];
    SWC_VC_B.dfy[SWC_VC_B.pp_tmp_o] = SWC_VC_B.extremum_c *
      SWC_VC_B.fv6[SWC_VC_B.pp_tmp_o];
  }

  atan2d_4JrmYGtm(SWC_VC_B.dfy, SWC_VC_B.dfx, SWC_VC_B.fv7);
  fho[0] = pii[20] + 180.0F;
  power_WcQaq5Rj(SWC_VC_B.dfx, SWC_VC_B.fv6);
  power_WcQaq5Rj(SWC_VC_B.dfy, SWC_VC_B.dfx);
  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 249; SWC_VC_B.counter++) {
    fho[SWC_VC_B.counter + 1] = SWC_VC_B.fv7[SWC_VC_B.counter];
    SWC_VC_B.extremum_c = fho[SWC_VC_B.counter + 1];
    SWC_VC_B.regen_mode_fb_tmp = SWC_VC_B.extremum_c - fho[SWC_VC_B.counter];
    if (SWC_VC_B.regen_mode_fb_tmp > 300.0F) {
      fho[SWC_VC_B.counter + 1] = SWC_VC_B.extremum_c - 360.0F;
    } else {
      if (SWC_VC_B.regen_mode_fb_tmp < -300.0F) {
        fho[SWC_VC_B.counter + 1] = SWC_VC_B.extremum_c + 360.0F;
      }
    }

    SWC_VC_B.dfy[SWC_VC_B.counter] = SWC_VC_B.fv6[SWC_VC_B.counter] +
      SWC_VC_B.dfx[SWC_VC_B.counter];
  }

  sqrt_bTObkNxA(SWC_VC_B.dfy);
  diff_PkLl8BoA(fho, SWC_VC_B.fv7);
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 249; SWC_VC_B.pp_tmp_o++) {
    SWC_VC_B.fv6[SWC_VC_B.pp_tmp_o] = MeAP_m_VehWheelbase *
      SWC_VC_B.fv7[SWC_VC_B.pp_tmp_o] * 3.14159274F / 180.0F;
  }

  atan2d_4JrmYGtm(SWC_VC_B.fv6, SWC_VC_B.dfy, SWC_VC_B.fv7);
  SWC_VC_B.fyo_dummy[0] = 0.0F;
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 249; SWC_VC_B.pp_tmp_o++) {
    SWC_VC_B.fyo_dummy[SWC_VC_B.pp_tmp_o + 1] = KeAP_Ks *
      SWC_VC_B.fv7[SWC_VC_B.pp_tmp_o];
  }

  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 250; SWC_VC_B.pp_tmp_o++) {
    KeAP_fso[SWC_VC_B.pp_tmp_o] = (real32_T)SWC_VC_B.fgo[SWC_VC_B.pp_tmp_o] *
      SWC_VC_B.fyo_dummy[SWC_VC_B.pp_tmp_o];
  }

  if (no_str_flag) {
    SWC_VC_B.counter = 0;
    while (SWC_VC_B.counter <= ((uint8_T)num_points_no_str_fb) - 4) {
      KeAP_fso[SWC_VC_B.counter] = SWC_VC_B.init_wheel_angle_h3;
      SWC_VC_B.counter++;
    }

    SWC_VC_B.qY_c3 = ((uint8_T)num_points_no_str_fb) - /*MW:OvSatOk*/ 2U;
    if (SWC_VC_B.qY_c3 > ((uint8_T)num_points_no_str_fb)) {
      SWC_VC_B.qY_c3 = 0U;
    }

    SWC_VC_B.qY_tmp_i = ((uint8_T)num_points_no_str_fb) - /*MW:OvSatOk*/ 3U;
    SWC_VC_B.qY_d = SWC_VC_B.qY_tmp_i;
    if (SWC_VC_B.qY_tmp_i > ((uint8_T)num_points_no_str_fb)) {
      SWC_VC_B.qY_d = 0U;
    }

    SWC_VC_B.qY_g = SWC_VC_B.qY_tmp_i;
    if (SWC_VC_B.qY_tmp_i > ((uint8_T)num_points_no_str_fb)) {
      SWC_VC_B.qY_g = 0U;
    }

    SWC_VC_B.counter = ((uint8_T)num_points_no_str_fb) - 1;
    KeAP_fso[(int32_T)SWC_VC_B.qY_c3 - 1] = (KeAP_fso[SWC_VC_B.counter] -
      KeAP_fso[(int32_T)SWC_VC_B.qY_g - 1]) / 3.0F + KeAP_fso[(int32_T)
      SWC_VC_B.qY_d - 1];
    SWC_VC_B.qY_c3 = ((uint8_T)num_points_no_str_fb) - /*MW:OvSatOk*/ 1U;
    if (SWC_VC_B.qY_c3 > ((uint8_T)num_points_no_str_fb)) {
      SWC_VC_B.qY_c3 = 0U;
    }

    SWC_VC_B.qY_d = SWC_VC_B.qY_tmp_i;
    if (SWC_VC_B.qY_tmp_i > ((uint8_T)num_points_no_str_fb)) {
      SWC_VC_B.qY_d = 0U;
      SWC_VC_B.qY_tmp_i = 0U;
    }

    KeAP_fso[(int32_T)SWC_VC_B.qY_c3 - 1] = (KeAP_fso[SWC_VC_B.counter] -
      KeAP_fso[(int32_T)SWC_VC_B.qY_tmp_i - 1]) * 2.0F / 3.0F + KeAP_fso
      [(int32_T)SWC_VC_B.qY_d - 1];
  } else {
    KeAP_fso[1] = (KeAP_fso[0] + KeAP_fso[2]) / 2.0F;
  }

  KeAP_fso_tmp = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_o[0]);
  SWC_VC_B.pp_tmp_o = KeAP_fso_tmp + 1;
  if (SWC_VC_B.pp_tmp_o > 32767) {
    SWC_VC_B.pp_tmp_o = 32767;
  }

  SWC_VC_B.h_i = KeAP_fso_tmp + 2;
  if (SWC_VC_B.h_i > 32767) {
    SWC_VC_B.h_i = 32767;
  }

  KeAP_fso[SWC_VC_B.pp_tmp_o - 1] = KeAP_fso[SWC_VC_B.h_i - 1];
  SWC_VC_B.init_wheel_angle_h3 = 3.6F * StrRateLim_fb;
  diff_PkLl8BoA(KeAP_fso, SWC_VC_B.fv7);
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 249; SWC_VC_B.pp_tmp_o++) {
    SWC_VC_B.fv6[SWC_VC_B.pp_tmp_o] = SWC_VC_B.fv7[SWC_VC_B.pp_tmp_o] /
      SWC_VC_B.dfy[SWC_VC_B.pp_tmp_o];
  }

  abs_DujjoFWP(SWC_VC_B.fv6, SWC_VC_B.fv7);
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 249; SWC_VC_B.pp_tmp_o++) {
    SWC_VC_B.fxo_dummy[SWC_VC_B.pp_tmp_o] = SWC_VC_B.init_wheel_angle_h3 /
      (SWC_VC_B.fv7[SWC_VC_B.pp_tmp_o] + 0.01F);
  }

  SWC_VC_B.fxo_dummy[249] = SWC_VC_B.init_wheel_angle_h3 / 0.01F;
  for (SWC_VC_B.counter = 0; SWC_VC_B.counter < 250; SWC_VC_B.counter++) {
    KeAP_fvo[SWC_VC_B.counter] = fminf(V_max_fb,
      SWC_VC_B.fxo_dummy[SWC_VC_B.counter]);
  }

  abs_fEIKHoQZ(SWC_VC_B.fio_dummy_o, SWC_VC_B.iv2);
  KeAP_fso_tmp = sum_d5YRIYyL(SWC_VC_B.iv2);
  if (KeAP_fso_tmp < 0) {
    KeAP_fso_tmp = 0;
  }

  if ((uint16_T)KeAP_fso_tmp > 0) {
    for (l_i = (uint16_T)((uint16_T)KeAP_fso_tmp + 1); l_i < 251; l_i++) {
      SWC_VC_B.counter = (uint16_T)KeAP_fso_tmp - 1;
      SWC_VC_B.h_i = l_i - 1;
      fxo[SWC_VC_B.h_i] = fxo[SWC_VC_B.counter];
      fyo[SWC_VC_B.h_i] = fyo[SWC_VC_B.counter];
      fho[SWC_VC_B.h_i] = fho[SWC_VC_B.counter];
      KeAP_fso[SWC_VC_B.h_i] = KeAP_fso[SWC_VC_B.counter];
      KeAP_fvo[SWC_VC_B.h_i] = KeAP_fvo[SWC_VC_B.counter];
    }
  }

  SWC_VC_B.num_sweeps = 0U;
  do {
    exitg1 = 0;
    SWC_VC_B.pp_tmp_o = (int32_T)(SWC_VC_B.num_sweeps + 1U);
    SWC_VC_B.h_i = SWC_VC_B.pp_tmp_o;
    if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
      SWC_VC_B.h_i = 255;
    }

    if (SWC_VC_B.fio_dummy_o[SWC_VC_B.h_i - 1] != 0) {
      if ((uint32_T)SWC_VC_B.pp_tmp_o > 255U) {
        SWC_VC_B.pp_tmp_o = 255;
      }

      SWC_VC_B.num_sweeps = (uint8_T)SWC_VC_B.pp_tmp_o;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  mod_GIkes8zg(fxo, KeAP_PP_RES_DIST_TRAVEL, SWC_VC_B.fyo_dummy);
  mod_GIkes8zg(fyo, KeAP_PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_dummy);
  mod_GIkes8zg(fho, KeAP_PP_RES_DIST_TRAVEL, SWC_VC_B.fv5);
  mod_GIkes8zg(KeAP_fso, KeAP_PP_RES_DIST_TRAVEL, SWC_VC_B.fv4);
  mod_GIkes8zg(KeAP_fvo, KeAP_PP_RES_DIST_TRAVEL, SWC_VC_B.fv3);
  for (SWC_VC_B.pp_tmp_o = 0; SWC_VC_B.pp_tmp_o < 250; SWC_VC_B.pp_tmp_o++) {
    fxo[SWC_VC_B.pp_tmp_o] -= SWC_VC_B.fyo_dummy[SWC_VC_B.pp_tmp_o];
    fyo[SWC_VC_B.pp_tmp_o] -= SWC_VC_B.fxo_dummy[SWC_VC_B.pp_tmp_o];
    fho[SWC_VC_B.pp_tmp_o] -= SWC_VC_B.fv5[SWC_VC_B.pp_tmp_o];
    KeAP_fso[SWC_VC_B.pp_tmp_o] -= SWC_VC_B.fv4[SWC_VC_B.pp_tmp_o];
    KeAP_fvo[SWC_VC_B.pp_tmp_o] -= SWC_VC_B.fv3[SWC_VC_B.pp_tmp_o];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_RENDER_FISHBONE(void)
{
  boolean_T guard1 = false;
  guard1 = false;
  if (SWC_VC_DW.c1 < 0) {
    if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
         (SWC_VC_B.UnitDelay2 == 3))) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
      SWC_VC_B.i4 = 100 - SWC_VC_DW.c1;
      if (SWC_VC_B.i4 > 127) {
        SWC_VC_B.i4 = 127;
      }

      PP_state = (int8_T)SWC_VC_B.i4;
      PP_Abort = true;
    } else if (SWC_VC_DW.regen_mode == 1.0F) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
      PP_state = 99;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (SWC_VC_DW.c1 == 1) {
      SWC_VC_DW.c1 = 0;
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_TRANSPOSE_INV;
      PP_state = 41;
    } else {
      SWC_VC_renderPath_fishbone(SWC_VC_DW.p_guide, SWC_VC_B.fx, SWC_VC_B.fy,
        SWC_VC_B.fh, SWC_VC_B.fv, SWC_VC_B.fs, SWC_VC_B.fi, &SWC_VC_DW.c1);
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_sweep_finder_para_common(real32_T x1, real32_T x2, real32_T
  b_y1, real32_T phi, const real32_T pps[8], real32_T str_wheel_ang, int8_T gear,
  boolean_T ParkOut, real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2])
{
  boolean_T collision_flag;
  boolean_T park_out_flag;
  uint8_T counter;
  int8_T whl_dir;
  uint8_T run_count;
  real32_T c_center_idx_0;
  real32_T c_center_idx_1;
  real32_T veh_params_Ke_AP_I_VehRearOverh_idx_1;
  int32_T x_out_data_tmp;
  int32_T exitg1;
  int32_T exitg2;
  collision_flag = false;
  park_out_flag = false;
  if (!ParkOut) {
    whl_dir = gear;
    if (phi + 180.0F != 0.0F) {
      if (phi + 180.0F < 0.0F) {
        SWC_VC_B.n = -1.0F;
      } else if (phi + 180.0F > 0.0F) {
        SWC_VC_B.n = 1.0F;
      } else if (phi + 180.0F == 0.0F) {
        SWC_VC_B.n = 0.0F;
      } else {
        SWC_VC_B.n = (rtNaNF);
      }

      if (SWC_VC_B.n < 128.0F) {
        whl_dir = (int8_T)SWC_VC_B.n;
      } else {
        whl_dir = MAX_int8_T;
      }

      x_out_data_tmp = gear * whl_dir;
      if (x_out_data_tmp > 127) {
        x_out_data_tmp = 127;
      } else {
        if (x_out_data_tmp < -128) {
          x_out_data_tmp = -128;
        }
      }

      whl_dir = (int8_T)x_out_data_tmp;
    }
  } else {
    x_out_data_tmp = -gear;
    if (x_out_data_tmp > 127) {
      x_out_data_tmp = 127;
    }

    whl_dir = (int8_T)x_out_data_tmp;
  }

  SWC_VC_B.d_k = str_wheel_ang;
  tand_brbYAlcS(&SWC_VC_B.d_k);
  SWC_VC_B.turn_radius_para = veh_params_Ke_AP_I_VehWheelbase / SWC_VC_B.d_k;
  SWC_VC_B.d_k = 90.0F * (real32_T)whl_dir;
  c_center_idx_0 = SWC_VC_B.d_k;
  cosd_KZN3FnAl(&c_center_idx_0);
  SWC_VC_B.f = SWC_VC_B.d_k;
  sind_7is3Ljjc(&SWC_VC_B.f);
  SWC_VC_B.heading_angle_change = SWC_VC_B.d_k;
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change);
  SWC_VC_B.h_p = SWC_VC_B.d_k;
  cosd_KZN3FnAl(&SWC_VC_B.h_p);
  SWC_VC_B.step_size = phi + 180.0F;
  cosd_KZN3FnAl(&SWC_VC_B.step_size);
  c_center_idx_1 = phi + 180.0F;
  sind_7is3Ljjc(&c_center_idx_1);
  c_center_idx_0 = (c_center_idx_0 * SWC_VC_B.step_size + -SWC_VC_B.f *
                    c_center_idx_1) * SWC_VC_B.turn_radius_para + x1;
  c_center_idx_1 = (SWC_VC_B.heading_angle_change * SWC_VC_B.step_size +
                    SWC_VC_B.h_p * c_center_idx_1) * SWC_VC_B.turn_radius_para +
    b_y1;
  SWC_VC_B.heading_angle_change = asinf(fmaxf(-1.0F, fminf(1.0F, (x2 -
    c_center_idx_0) / SWC_VC_B.turn_radius_para))) * 57.2957802F * (real32_T)
    whl_dir + -(phi + 180.0F);
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change);
  SWC_VC_B.heading_angle_change = 57.2957802F * asinf
    (SWC_VC_B.heading_angle_change);
  if (SWC_VC_B.turn_radius_para < 100.0F) {
    if (SWC_VC_B.heading_angle_change < 0.0F) {
      SWC_VC_B.h_p = -1.0F;
    } else if (SWC_VC_B.heading_angle_change > 0.0F) {
      SWC_VC_B.h_p = 1.0F;
    } else if (SWC_VC_B.heading_angle_change == 0.0F) {
      SWC_VC_B.h_p = 0.0F;
    } else {
      SWC_VC_B.h_p = (rtNaNF);
    }

    SWC_VC_B.heading_angle_change += plan_params_aux_turn_para_regen *
      SWC_VC_B.h_p;
  }

  SWC_VC_B.n = phi + SWC_VC_B.heading_angle_change;
  if ((((phi < -180.0F) && (SWC_VC_B.n > -180.0F)) || ((phi > -180.0F) &&
        (SWC_VC_B.n < -180.0F))) && (!ParkOut)) {
    SWC_VC_B.heading_angle_change = -(phi + 180.0F);
  }

  if (SWC_VC_B.heading_angle_change < 0.0F) {
    SWC_VC_B.h_p = -1.0F;
  } else if (SWC_VC_B.heading_angle_change > 0.0F) {
    SWC_VC_B.h_p = 1.0F;
  } else if (SWC_VC_B.heading_angle_change == 0.0F) {
    SWC_VC_B.h_p = 0.0F;
  } else {
    SWC_VC_B.h_p = (rtNaNF);
  }

  SWC_VC_B.step_size = SWC_VC_B.h_p;
  while (fabsf(SWC_VC_B.heading_angle_change / SWC_VC_B.step_size) < 10.0F) {
    SWC_VC_B.step_size /= 2.0F;
  }

  run_count = 1U;
  do {
    exitg1 = 0;
    counter = 0U;
    SWC_VC_B.f = (phi + 180.0F) - SWC_VC_B.d_k;
    SWC_VC_B.angle = roundf(SWC_VC_B.f * 1000.0F) / 1000.0F;
    SWC_VC_B.angle_bound = roundf((SWC_VC_B.angle +
      SWC_VC_B.heading_angle_change) * 1000.0F) / 1000.0F;
    do {
      exitg2 = 0;
      if (SWC_VC_B.step_size < 0.0F) {
        SWC_VC_B.n = -1.0F;
      } else if (SWC_VC_B.step_size > 0.0F) {
        SWC_VC_B.n = 1.0F;
      } else if (SWC_VC_B.step_size == 0.0F) {
        SWC_VC_B.n = 0.0F;
      } else {
        SWC_VC_B.n = (rtNaNF);
      }

      if (SWC_VC_B.angle * SWC_VC_B.n <= SWC_VC_B.angle_bound * SWC_VC_B.n) {
        x_out_data_tmp = (int32_T)(counter + 1U);
        if ((uint32_T)x_out_data_tmp > 255U) {
          x_out_data_tmp = 255;
        }

        counter = (uint8_T)x_out_data_tmp;
        SWC_VC_B.veh_heading = SWC_VC_B.angle;
        cosd_KZN3FnAl(&SWC_VC_B.veh_heading);
        x_out_data_tmp = (uint8_T)x_out_data_tmp - 1;
        SWC_VC_B.x_out_data_j[x_out_data_tmp] = SWC_VC_B.turn_radius_para *
          SWC_VC_B.veh_heading + c_center_idx_0;
        SWC_VC_B.veh_heading = SWC_VC_B.angle;
        sind_7is3Ljjc(&SWC_VC_B.veh_heading);
        SWC_VC_B.y_out_data_o[x_out_data_tmp] = SWC_VC_B.turn_radius_para *
          SWC_VC_B.veh_heading + c_center_idx_1;
        SWC_VC_B.veh_heading = SWC_VC_B.d_k + SWC_VC_B.angle;
        if (x2 - x1 <= 0.0F) {
          if (SWC_VC_B.veh_heading >= 0.0F) {
            SWC_VC_B.n = SWC_VC_B.veh_heading;
            cosd_KZN3FnAl(&SWC_VC_B.n);
            SWC_VC_B.o = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&SWC_VC_B.o);
            SWC_VC_B.y_p = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&SWC_VC_B.y_p);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading);
            SWC_VC_B.p = -(veh_params_Ke_AP_I_VehWheelbase +
                           veh_params_Ke_AP_I_VehFrontOverhang);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
              2.0F;
            SWC_VC_B.veh_heading = (SWC_VC_B.y_p * SWC_VC_B.p +
              SWC_VC_B.veh_heading * veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.y_out_data_o[x_out_data_tmp];
            if ((SWC_VC_B.n * SWC_VC_B.p + -SWC_VC_B.o *
                 veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                SWC_VC_B.x_out_data_j[x_out_data_tmp] <= pps[2]) {
              collision_flag = (SWC_VC_B.veh_heading >= pps[1]);
            }

            if (ParkOut) {
              park_out_flag = ((SWC_VC_B.veh_heading < pps[1] - -0.5F) ||
                               park_out_flag);
            }
          } else {
            SWC_VC_B.o = SWC_VC_B.veh_heading;
            cosd_KZN3FnAl(&SWC_VC_B.o);
            SWC_VC_B.p = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&SWC_VC_B.p);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
            SWC_VC_B.y_p = SWC_VC_B.veh_heading;
            cosd_KZN3FnAl(&SWC_VC_B.y_p);
            SWC_VC_B.n = -(veh_params_Ke_AP_I_VehWheelbase +
                           veh_params_Ke_AP_I_VehFrontOverhang);
            if (((0.0F * SWC_VC_B.o + veh_params_Ke_AP_I_VehRearOverh_idx_1) *
                 SWC_VC_B.n + (0.0F * -SWC_VC_B.p + SWC_VC_B.y_p) *
                 (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                SWC_VC_B.y_out_data_o[x_out_data_tmp] >= pps[3] +
                plan_params_curb_over_Y_dir_para) {
              collision_flag = true;
            } else {
              SWC_VC_B.o = SWC_VC_B.veh_heading;
              cosd_KZN3FnAl(&SWC_VC_B.o);
              SWC_VC_B.p = SWC_VC_B.veh_heading;
              sind_7is3Ljjc(&SWC_VC_B.p);
              veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading;
              sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
              cosd_KZN3FnAl(&SWC_VC_B.veh_heading);
              collision_flag = ((((0.0F * veh_params_Ke_AP_I_VehRearOverh_idx_1
                                   + SWC_VC_B.o) * SWC_VC_B.n + (0.0F *
                SWC_VC_B.veh_heading + -SWC_VC_B.p) *
                                  (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                                 SWC_VC_B.x_out_data_j[x_out_data_tmp] <= pps[0])
                                || collision_flag);
            }
          }
        } else if (SWC_VC_B.veh_heading >= 0.0F) {
          SWC_VC_B.n = SWC_VC_B.veh_heading;
          cosd_KZN3FnAl(&SWC_VC_B.n);
          SWC_VC_B.o = SWC_VC_B.veh_heading;
          sind_7is3Ljjc(&SWC_VC_B.o);
          SWC_VC_B.p = SWC_VC_B.veh_heading;
          sind_7is3Ljjc(&SWC_VC_B.p);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading;
          cosd_KZN3FnAl(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
          if (((0.0F * SWC_VC_B.n + SWC_VC_B.p) *
               veh_params_Ke_AP_I_VehRearOverhang + (0.0F * -SWC_VC_B.o +
                veh_params_Ke_AP_I_VehRearOverh_idx_1) *
               (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
              SWC_VC_B.y_out_data_o[x_out_data_tmp] >= pps[5] +
              plan_params_curb_over_Y_dir_para) {
            collision_flag = true;
          } else {
            SWC_VC_B.n = SWC_VC_B.veh_heading;
            cosd_KZN3FnAl(&SWC_VC_B.n);
            SWC_VC_B.o = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&SWC_VC_B.o);
            SWC_VC_B.p = SWC_VC_B.veh_heading;
            sind_7is3Ljjc(&SWC_VC_B.p);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading);
            collision_flag = ((((0.0F * SWC_VC_B.p + SWC_VC_B.n) *
                                veh_params_Ke_AP_I_VehRearOverhang + (0.0F *
              SWC_VC_B.veh_heading + -SWC_VC_B.o) *
                                (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                               SWC_VC_B.x_out_data_j[x_out_data_tmp] >= pps[6]) ||
                              collision_flag);
          }
        } else {
          SWC_VC_B.n = SWC_VC_B.veh_heading;
          cosd_KZN3FnAl(&SWC_VC_B.n);
          SWC_VC_B.o = SWC_VC_B.veh_heading;
          sind_7is3Ljjc(&SWC_VC_B.o);
          SWC_VC_B.p = SWC_VC_B.veh_heading;
          sind_7is3Ljjc(&SWC_VC_B.p);
          cosd_KZN3FnAl(&SWC_VC_B.veh_heading);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
            2.0F;
          if ((SWC_VC_B.n * veh_params_Ke_AP_I_VehRearOverhang + -SWC_VC_B.o *
               veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.x_out_data_j[x_out_data_tmp] >= pps[4]) {
            collision_flag = (((SWC_VC_B.p * veh_params_Ke_AP_I_VehRearOverhang
                                + SWC_VC_B.veh_heading *
                                veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                               SWC_VC_B.y_out_data_o[x_out_data_tmp] >= pps[7]) ||
                              collision_flag);
          }
        }

        if (!collision_flag) {
          SWC_VC_B.angle_end = SWC_VC_B.angle;
          if (park_out_flag) {
            SWC_VC_B.x_out[0] = SWC_VC_B.x_out_data_j[x_out_data_tmp] -
              SWC_VC_B.x_out_data_j[0];
            SWC_VC_B.x_out[1] = SWC_VC_B.y_out_data_o[x_out_data_tmp] -
              SWC_VC_B.y_out_data_o[0];
            if (norm_5ISqY4yY(SWC_VC_B.x_out) > 0.5F) {
              exitg2 = 1;
            } else {
              SWC_VC_B.angle += SWC_VC_B.step_size;
            }
          } else {
            SWC_VC_B.angle += SWC_VC_B.step_size;
          }
        } else {
          counter = (uint8_T)x_out_data_tmp;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if ((counter > 1) && (run_count == 1)) {
      park_out_flag = false;
      collision_flag = false;
      if (fabsf(SWC_VC_B.d_k + SWC_VC_B.angle_end) <=
          plan_params_ang_threshold_regen) {
        if (!ParkOut) {
          SWC_VC_B.x_out[0] = x2 - SWC_VC_B.x_out_data_j[0];
          SWC_VC_B.x_out[1] = SWC_VC_B.y_out_data_o[counter - 1] -
            SWC_VC_B.y_out_data_o[0];
          SWC_VC_B.step_size = (SWC_VC_B.angle_end - ((phi + 180.0F) - 90.0F *
            (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out) /
            plan_params_delta_s_para, 40.0F);
          SWC_VC_B.turn_radius_para = SWC_VC_B.heading_angle_change;
          sind_7is3Ljjc(&SWC_VC_B.turn_radius_para);
          SWC_VC_B.turn_radius_para = fabsf((x2 - x1) /
            SWC_VC_B.turn_radius_para);
          c_center_idx_0 = SWC_VC_B.d_k;
          cosd_KZN3FnAl(&c_center_idx_0);
          SWC_VC_B.veh_heading = SWC_VC_B.d_k;
          sind_7is3Ljjc(&SWC_VC_B.veh_heading);
          c_center_idx_1 = SWC_VC_B.d_k;
          sind_7is3Ljjc(&c_center_idx_1);
          SWC_VC_B.f = SWC_VC_B.d_k;
          cosd_KZN3FnAl(&SWC_VC_B.f);
          SWC_VC_B.angle = phi + 180.0F;
          cosd_KZN3FnAl(&SWC_VC_B.angle);
          SWC_VC_B.angle_bound = phi + 180.0F;
          sind_7is3Ljjc(&SWC_VC_B.angle_bound);
          c_center_idx_0 = (c_center_idx_0 * SWC_VC_B.angle +
                            -SWC_VC_B.veh_heading * SWC_VC_B.angle_bound) *
            SWC_VC_B.turn_radius_para + x1;
          c_center_idx_1 = (c_center_idx_1 * SWC_VC_B.angle + SWC_VC_B.f *
                            SWC_VC_B.angle_bound) * SWC_VC_B.turn_radius_para +
            b_y1;
        } else {
          x_out_data_tmp = counter - 1;
          SWC_VC_B.x_out[0] = SWC_VC_B.x_out_data_j[x_out_data_tmp] -
            SWC_VC_B.x_out_data_j[0];
          SWC_VC_B.x_out[1] = SWC_VC_B.y_out_data_o[x_out_data_tmp] -
            SWC_VC_B.y_out_data_o[0];
          SWC_VC_B.step_size = (SWC_VC_B.angle_end - ((phi + 180.0F) - 90.0F *
            (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out) /
            plan_params_delta_s_para, 40.0F);
        }
      } else {
        x_out_data_tmp = counter - 1;
        SWC_VC_B.x_out[0] = SWC_VC_B.x_out_data_j[x_out_data_tmp] -
          SWC_VC_B.x_out_data_j[0];
        SWC_VC_B.x_out[1] = SWC_VC_B.y_out_data_o[x_out_data_tmp] -
          SWC_VC_B.y_out_data_o[0];
        SWC_VC_B.step_size = (SWC_VC_B.angle_end - SWC_VC_B.f) / fminf
          (norm_5ISqY4yY(SWC_VC_B.x_out) / plan_params_delta_s_para, 40.0F);
      }

      SWC_VC_B.step_size = roundf(SWC_VC_B.step_size * 1000.0F) / 1000.0F;
      if (SWC_VC_B.step_size == 0.0F) {
        SWC_VC_B.step_size = SWC_VC_B.h_p * 0.01F;
      }

      run_count = 2U;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (counter > 0) {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_j[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_o[x_out_data_tmp];
    }

    x_out_data_tmp = counter - 1;
    output_data[100] = SWC_VC_B.x_out_data_j[x_out_data_tmp];
    output_data[101] = SWC_VC_B.y_out_data_o[x_out_data_tmp];
    output_data[102] = SWC_VC_B.angle_end - (180.0F - SWC_VC_B.d_k);
    output_data[103] = counter;
    output_data[104] = park_out_flag;
  } else {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_j[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_o[x_out_data_tmp];
    }

    output_data[100] = x1;
    output_data[101] = b_y1;
    output_data[102] = phi;
    output_data[103] = 0.0F;
    output_data[104] = park_out_flag;
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_sweep_finder_para_common_ml(real32_T x1, real32_T x2,
  real32_T b_y1, real32_T phi, const real32_T pps[8], int8_T gear, boolean_T
  ParkOut, real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2])
{
  boolean_T collision_flag;
  boolean_T park_out_flag;
  uint8_T counter;
  int8_T whl_dir;
  uint8_T run_count;
  real32_T c_center_idx_1;
  real32_T veh_params_Ke_AP_I_VehRearOverh_idx_1;
  real32_T d_tmp;
  int32_T x_out_data_tmp;
  int32_T exitg1;
  int32_T exitg2;
  collision_flag = false;
  park_out_flag = false;
  if (!ParkOut) {
    whl_dir = gear;
    if (phi + 180.0F != 0.0F) {
      if (phi + 180.0F < 0.0F) {
        SWC_VC_B.m_n = -1.0F;
      } else if (phi + 180.0F > 0.0F) {
        SWC_VC_B.m_n = 1.0F;
      } else if (phi + 180.0F == 0.0F) {
        SWC_VC_B.m_n = 0.0F;
      } else {
        SWC_VC_B.m_n = (rtNaNF);
      }

      if (SWC_VC_B.m_n < 128.0F) {
        whl_dir = (int8_T)SWC_VC_B.m_n;
      } else {
        whl_dir = MAX_int8_T;
      }

      x_out_data_tmp = gear * whl_dir;
      if (x_out_data_tmp > 127) {
        x_out_data_tmp = 127;
      } else {
        if (x_out_data_tmp < -128) {
          x_out_data_tmp = -128;
        }
      }

      whl_dir = (int8_T)x_out_data_tmp;
    }
  } else {
    x_out_data_tmp = -gear;
    if (x_out_data_tmp > 127) {
      x_out_data_tmp = 127;
    }

    whl_dir = (int8_T)x_out_data_tmp;
  }

  SWC_VC_B.turn_radius_para_e = veh_params_Ke_AP_I_VehWheelbase / 0.649407625F;
  d_tmp = 90.0F * (real32_T)whl_dir;
  SWC_VC_B.c_center_idx_0_f = d_tmp;
  cosd_KZN3FnAl(&SWC_VC_B.c_center_idx_0_f);
  SWC_VC_B.e_m = d_tmp;
  sind_7is3Ljjc(&SWC_VC_B.e_m);
  SWC_VC_B.heading_angle_change_c = d_tmp;
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change_c);
  SWC_VC_B.g_o = d_tmp;
  cosd_KZN3FnAl(&SWC_VC_B.g_o);
  SWC_VC_B.step_size_a = phi + 180.0F;
  cosd_KZN3FnAl(&SWC_VC_B.step_size_a);
  c_center_idx_1 = phi + 180.0F;
  sind_7is3Ljjc(&c_center_idx_1);
  SWC_VC_B.c_center_idx_0_f = (SWC_VC_B.c_center_idx_0_f * SWC_VC_B.step_size_a
    + -SWC_VC_B.e_m * c_center_idx_1) * SWC_VC_B.turn_radius_para_e + x1;
  c_center_idx_1 = (SWC_VC_B.heading_angle_change_c * SWC_VC_B.step_size_a +
                    SWC_VC_B.g_o * c_center_idx_1) * SWC_VC_B.turn_radius_para_e
    + b_y1;
  SWC_VC_B.heading_angle_change_c = asinf(fmaxf(-1.0F, fminf(1.0F, (x2 -
    SWC_VC_B.c_center_idx_0_f) / SWC_VC_B.turn_radius_para_e))) * 57.2957802F *
    (real32_T)whl_dir + -(phi + 180.0F);
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change_c);
  SWC_VC_B.heading_angle_change_c = 57.2957802F * asinf
    (SWC_VC_B.heading_angle_change_c);
  if (SWC_VC_B.turn_radius_para_e < 100.0F) {
    if (SWC_VC_B.heading_angle_change_c < 0.0F) {
      SWC_VC_B.g_o = -1.0F;
    } else if (SWC_VC_B.heading_angle_change_c > 0.0F) {
      SWC_VC_B.g_o = 1.0F;
    } else if (SWC_VC_B.heading_angle_change_c == 0.0F) {
      SWC_VC_B.g_o = 0.0F;
    } else {
      SWC_VC_B.g_o = (rtNaNF);
    }

    SWC_VC_B.heading_angle_change_c += plan_params_aux_turn_para_regen *
      SWC_VC_B.g_o;
  }

  SWC_VC_B.m_n = phi + SWC_VC_B.heading_angle_change_c;
  if ((((phi < -180.0F) && (SWC_VC_B.m_n > -180.0F)) || ((phi > -180.0F) &&
        (SWC_VC_B.m_n < -180.0F))) && (!ParkOut)) {
    SWC_VC_B.heading_angle_change_c = -(phi + 180.0F);
  }

  if (SWC_VC_B.heading_angle_change_c < 0.0F) {
    SWC_VC_B.g_o = -1.0F;
  } else if (SWC_VC_B.heading_angle_change_c > 0.0F) {
    SWC_VC_B.g_o = 1.0F;
  } else if (SWC_VC_B.heading_angle_change_c == 0.0F) {
    SWC_VC_B.g_o = 0.0F;
  } else {
    SWC_VC_B.g_o = (rtNaNF);
  }

  SWC_VC_B.step_size_a = SWC_VC_B.g_o;
  while (fabsf(SWC_VC_B.heading_angle_change_c / SWC_VC_B.step_size_a) < 10.0F)
  {
    SWC_VC_B.step_size_a /= 2.0F;
  }

  run_count = 1U;
  do {
    exitg1 = 0;
    counter = 0U;
    SWC_VC_B.e_m = (phi + 180.0F) - d_tmp;
    SWC_VC_B.angle_d = roundf(SWC_VC_B.e_m * 1000.0F) / 1000.0F;
    SWC_VC_B.angle_bound_a = roundf((SWC_VC_B.angle_d +
      SWC_VC_B.heading_angle_change_c) * 1000.0F) / 1000.0F;
    do {
      exitg2 = 0;
      if (SWC_VC_B.step_size_a < 0.0F) {
        SWC_VC_B.m_n = -1.0F;
      } else if (SWC_VC_B.step_size_a > 0.0F) {
        SWC_VC_B.m_n = 1.0F;
      } else if (SWC_VC_B.step_size_a == 0.0F) {
        SWC_VC_B.m_n = 0.0F;
      } else {
        SWC_VC_B.m_n = (rtNaNF);
      }

      if (SWC_VC_B.angle_d * SWC_VC_B.m_n <= SWC_VC_B.angle_bound_a *
          SWC_VC_B.m_n) {
        x_out_data_tmp = (int32_T)(counter + 1U);
        if ((uint32_T)x_out_data_tmp > 255U) {
          x_out_data_tmp = 255;
        }

        counter = (uint8_T)x_out_data_tmp;
        SWC_VC_B.veh_heading_p = SWC_VC_B.angle_d;
        cosd_KZN3FnAl(&SWC_VC_B.veh_heading_p);
        x_out_data_tmp = (uint8_T)x_out_data_tmp - 1;
        SWC_VC_B.x_out_data_o[x_out_data_tmp] = SWC_VC_B.turn_radius_para_e *
          SWC_VC_B.veh_heading_p + SWC_VC_B.c_center_idx_0_f;
        SWC_VC_B.veh_heading_p = SWC_VC_B.angle_d;
        sind_7is3Ljjc(&SWC_VC_B.veh_heading_p);
        SWC_VC_B.y_out_data_n[x_out_data_tmp] = SWC_VC_B.turn_radius_para_e *
          SWC_VC_B.veh_heading_p + c_center_idx_1;
        SWC_VC_B.veh_heading_p = d_tmp + SWC_VC_B.angle_d;
        if (x2 - x1 <= 0.0F) {
          if (SWC_VC_B.veh_heading_p >= 0.0F) {
            SWC_VC_B.m_n = SWC_VC_B.veh_heading_p;
            cosd_KZN3FnAl(&SWC_VC_B.m_n);
            SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&SWC_VC_B.n_l);
            SWC_VC_B.x_p = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&SWC_VC_B.x_p);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading_p);
            SWC_VC_B.o_p = -(veh_params_Ke_AP_I_VehWheelbase +
                             veh_params_Ke_AP_I_VehFrontOverhang);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
              2.0F;
            SWC_VC_B.veh_heading_p = (SWC_VC_B.x_p * SWC_VC_B.o_p +
              SWC_VC_B.veh_heading_p * veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.y_out_data_n[x_out_data_tmp];
            if ((SWC_VC_B.m_n * SWC_VC_B.o_p + -SWC_VC_B.n_l *
                 veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                SWC_VC_B.x_out_data_o[x_out_data_tmp] <= pps[2]) {
              collision_flag = (SWC_VC_B.veh_heading_p >= pps[1]);
            }

            if (ParkOut) {
              park_out_flag = ((SWC_VC_B.veh_heading_p < pps[1] - -0.5F) ||
                               park_out_flag);
            }
          } else {
            SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
            cosd_KZN3FnAl(&SWC_VC_B.n_l);
            SWC_VC_B.o_p = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&SWC_VC_B.o_p);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
            SWC_VC_B.x_p = SWC_VC_B.veh_heading_p;
            cosd_KZN3FnAl(&SWC_VC_B.x_p);
            SWC_VC_B.m_n = -(veh_params_Ke_AP_I_VehWheelbase +
                             veh_params_Ke_AP_I_VehFrontOverhang);
            if (((0.0F * SWC_VC_B.n_l + veh_params_Ke_AP_I_VehRearOverh_idx_1) *
                 SWC_VC_B.m_n + (0.0F * -SWC_VC_B.o_p + SWC_VC_B.x_p) *
                 (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                SWC_VC_B.y_out_data_n[x_out_data_tmp] >= pps[3] +
                plan_params_curb_over_Y_dir_para) {
              collision_flag = true;
            } else {
              SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
              cosd_KZN3FnAl(&SWC_VC_B.n_l);
              SWC_VC_B.o_p = SWC_VC_B.veh_heading_p;
              sind_7is3Ljjc(&SWC_VC_B.o_p);
              veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_p;
              sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
              cosd_KZN3FnAl(&SWC_VC_B.veh_heading_p);
              collision_flag = ((((0.0F * veh_params_Ke_AP_I_VehRearOverh_idx_1
                                   + SWC_VC_B.n_l) * SWC_VC_B.m_n + (0.0F *
                SWC_VC_B.veh_heading_p + -SWC_VC_B.o_p) *
                                  (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                                 SWC_VC_B.x_out_data_o[x_out_data_tmp] <= pps[0])
                                || collision_flag);
            }
          }
        } else if (SWC_VC_B.veh_heading_p >= 0.0F) {
          SWC_VC_B.m_n = SWC_VC_B.veh_heading_p;
          cosd_KZN3FnAl(&SWC_VC_B.m_n);
          SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
          sind_7is3Ljjc(&SWC_VC_B.n_l);
          SWC_VC_B.o_p = SWC_VC_B.veh_heading_p;
          sind_7is3Ljjc(&SWC_VC_B.o_p);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_p;
          cosd_KZN3FnAl(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
          if (((0.0F * SWC_VC_B.m_n + SWC_VC_B.o_p) *
               veh_params_Ke_AP_I_VehRearOverhang + (0.0F * -SWC_VC_B.n_l +
                veh_params_Ke_AP_I_VehRearOverh_idx_1) *
               (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
              SWC_VC_B.y_out_data_n[x_out_data_tmp] >= pps[5] +
              plan_params_curb_over_Y_dir_para) {
            collision_flag = true;
          } else {
            SWC_VC_B.m_n = SWC_VC_B.veh_heading_p;
            cosd_KZN3FnAl(&SWC_VC_B.m_n);
            SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&SWC_VC_B.n_l);
            SWC_VC_B.o_p = SWC_VC_B.veh_heading_p;
            sind_7is3Ljjc(&SWC_VC_B.o_p);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading_p);
            collision_flag = ((((0.0F * SWC_VC_B.o_p + SWC_VC_B.m_n) *
                                veh_params_Ke_AP_I_VehRearOverhang + (0.0F *
              SWC_VC_B.veh_heading_p + -SWC_VC_B.n_l) *
                                (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                               SWC_VC_B.x_out_data_o[x_out_data_tmp] >= pps[6]) ||
                              collision_flag);
          }
        } else {
          SWC_VC_B.m_n = SWC_VC_B.veh_heading_p;
          cosd_KZN3FnAl(&SWC_VC_B.m_n);
          SWC_VC_B.n_l = SWC_VC_B.veh_heading_p;
          sind_7is3Ljjc(&SWC_VC_B.n_l);
          SWC_VC_B.o_p = SWC_VC_B.veh_heading_p;
          sind_7is3Ljjc(&SWC_VC_B.o_p);
          cosd_KZN3FnAl(&SWC_VC_B.veh_heading_p);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
            2.0F;
          if ((SWC_VC_B.m_n * veh_params_Ke_AP_I_VehRearOverhang + -SWC_VC_B.n_l
               * veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.x_out_data_o[x_out_data_tmp] >= pps[4]) {
            collision_flag = (((SWC_VC_B.o_p *
                                veh_params_Ke_AP_I_VehRearOverhang +
                                SWC_VC_B.veh_heading_p *
                                veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                               SWC_VC_B.y_out_data_n[x_out_data_tmp] >= pps[7]) ||
                              collision_flag);
          }
        }

        if (!collision_flag) {
          SWC_VC_B.angle_end_h = SWC_VC_B.angle_d;
          if (park_out_flag) {
            SWC_VC_B.x_out_l[0] = SWC_VC_B.x_out_data_o[x_out_data_tmp] -
              SWC_VC_B.x_out_data_o[0];
            SWC_VC_B.x_out_l[1] = SWC_VC_B.y_out_data_n[x_out_data_tmp] -
              SWC_VC_B.y_out_data_n[0];
            if (norm_5ISqY4yY(SWC_VC_B.x_out_l) > 0.5F) {
              exitg2 = 1;
            } else {
              SWC_VC_B.angle_d += SWC_VC_B.step_size_a;
            }
          } else {
            SWC_VC_B.angle_d += SWC_VC_B.step_size_a;
          }
        } else {
          counter = (uint8_T)x_out_data_tmp;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if ((counter > 1) && (run_count == 1)) {
      park_out_flag = false;
      collision_flag = false;
      if (fabsf(d_tmp + SWC_VC_B.angle_end_h) <= plan_params_ang_threshold_regen)
      {
        if (!ParkOut) {
          SWC_VC_B.x_out_l[0] = x2 - SWC_VC_B.x_out_data_o[0];
          SWC_VC_B.x_out_l[1] = SWC_VC_B.y_out_data_n[counter - 1] -
            SWC_VC_B.y_out_data_n[0];
          SWC_VC_B.step_size_a = (SWC_VC_B.angle_end_h - ((phi + 180.0F) - 90.0F
            * (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out_l) /
            plan_params_delta_s_para, 40.0F);
          SWC_VC_B.turn_radius_para_e = SWC_VC_B.heading_angle_change_c;
          sind_7is3Ljjc(&SWC_VC_B.turn_radius_para_e);
          SWC_VC_B.turn_radius_para_e = fabsf((x2 - x1) /
            SWC_VC_B.turn_radius_para_e);
          SWC_VC_B.c_center_idx_0_f = d_tmp;
          cosd_KZN3FnAl(&SWC_VC_B.c_center_idx_0_f);
          SWC_VC_B.veh_heading_p = d_tmp;
          sind_7is3Ljjc(&SWC_VC_B.veh_heading_p);
          c_center_idx_1 = d_tmp;
          sind_7is3Ljjc(&c_center_idx_1);
          SWC_VC_B.e_m = d_tmp;
          cosd_KZN3FnAl(&SWC_VC_B.e_m);
          SWC_VC_B.angle_d = phi + 180.0F;
          cosd_KZN3FnAl(&SWC_VC_B.angle_d);
          SWC_VC_B.angle_bound_a = phi + 180.0F;
          sind_7is3Ljjc(&SWC_VC_B.angle_bound_a);
          SWC_VC_B.c_center_idx_0_f = (SWC_VC_B.c_center_idx_0_f *
            SWC_VC_B.angle_d + -SWC_VC_B.veh_heading_p * SWC_VC_B.angle_bound_a)
            * SWC_VC_B.turn_radius_para_e + x1;
          c_center_idx_1 = (c_center_idx_1 * SWC_VC_B.angle_d + SWC_VC_B.e_m *
                            SWC_VC_B.angle_bound_a) *
            SWC_VC_B.turn_radius_para_e + b_y1;
        } else {
          x_out_data_tmp = counter - 1;
          SWC_VC_B.x_out_l[0] = SWC_VC_B.x_out_data_o[x_out_data_tmp] -
            SWC_VC_B.x_out_data_o[0];
          SWC_VC_B.x_out_l[1] = SWC_VC_B.y_out_data_n[x_out_data_tmp] -
            SWC_VC_B.y_out_data_n[0];
          SWC_VC_B.step_size_a = (SWC_VC_B.angle_end_h - ((phi + 180.0F) - 90.0F
            * (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out_l) /
            plan_params_delta_s_para, 40.0F);
        }
      } else {
        x_out_data_tmp = counter - 1;
        SWC_VC_B.x_out_l[0] = SWC_VC_B.x_out_data_o[x_out_data_tmp] -
          SWC_VC_B.x_out_data_o[0];
        SWC_VC_B.x_out_l[1] = SWC_VC_B.y_out_data_n[x_out_data_tmp] -
          SWC_VC_B.y_out_data_n[0];
        SWC_VC_B.step_size_a = (SWC_VC_B.angle_end_h - SWC_VC_B.e_m) / fminf
          (norm_5ISqY4yY(SWC_VC_B.x_out_l) / plan_params_delta_s_para, 40.0F);
      }

      SWC_VC_B.step_size_a = roundf(SWC_VC_B.step_size_a * 1000.0F) / 1000.0F;
      if (SWC_VC_B.step_size_a == 0.0F) {
        SWC_VC_B.step_size_a = SWC_VC_B.g_o * 0.01F;
      }

      run_count = 2U;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (counter > 0) {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_o[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_n[x_out_data_tmp];
    }

    x_out_data_tmp = counter - 1;
    output_data[100] = SWC_VC_B.x_out_data_o[x_out_data_tmp];
    output_data[101] = SWC_VC_B.y_out_data_n[x_out_data_tmp];
    output_data[102] = SWC_VC_B.angle_end_h - (180.0F - d_tmp);
    output_data[103] = counter;
    output_data[104] = park_out_flag;
  } else {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_o[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_n[x_out_data_tmp];
    }

    output_data[100] = x1;
    output_data[101] = b_y1;
    output_data[102] = phi;
    output_data[103] = 0.0F;
    output_data[104] = park_out_flag;
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_sweep_finder_para_common_m(real32_T x1, real32_T x2, real32_T
  b_y1, real32_T phi, const real32_T pps[8], int8_T gear, boolean_T ParkOut,
  real32_T plan_params_ang_threshold_regen, real32_T
  plan_params_aux_turn_para_regen, real32_T plan_params_curb_over_Y_dir_para,
  real32_T plan_params_delta_s_para, real32_T
  veh_params_Ke_AP_I_VehFrontOverhang, real32_T veh_params_Ke_AP_I_VehWheelbase,
  real32_T veh_params_Ke_AP_I_VehWidth, real32_T
  veh_params_Ke_AP_I_VehRearOverhang, real32_T output_data[], int32_T
  output_size[2])
{
  boolean_T collision_flag;
  boolean_T park_out_flag;
  uint8_T counter;
  int8_T whl_dir;
  uint8_T run_count;
  real32_T c_center_idx_1;
  real32_T veh_params_Ke_AP_I_VehRearOverh_idx_1;
  real32_T d_tmp;
  int32_T x_out_data_tmp;
  int32_T exitg1;
  int32_T exitg2;
  collision_flag = false;
  park_out_flag = false;
  if (!ParkOut) {
    whl_dir = gear;
    if (phi + 180.0F != 0.0F) {
      if (phi + 180.0F < 0.0F) {
        SWC_VC_B.m = -1.0F;
      } else if (phi + 180.0F > 0.0F) {
        SWC_VC_B.m = 1.0F;
      } else if (phi + 180.0F == 0.0F) {
        SWC_VC_B.m = 0.0F;
      } else {
        SWC_VC_B.m = (rtNaNF);
      }

      if (SWC_VC_B.m < 128.0F) {
        whl_dir = (int8_T)SWC_VC_B.m;
      } else {
        whl_dir = MAX_int8_T;
      }

      x_out_data_tmp = gear * whl_dir;
      if (x_out_data_tmp > 127) {
        x_out_data_tmp = 127;
      } else {
        if (x_out_data_tmp < -128) {
          x_out_data_tmp = -128;
        }
      }

      whl_dir = (int8_T)x_out_data_tmp;
    }
  } else {
    x_out_data_tmp = -gear;
    if (x_out_data_tmp > 127) {
      x_out_data_tmp = 127;
    }

    whl_dir = (int8_T)x_out_data_tmp;
  }

  SWC_VC_B.turn_radius_para_a = veh_params_Ke_AP_I_VehWheelbase / 0.267949194F;
  d_tmp = 90.0F * (real32_T)whl_dir;
  SWC_VC_B.c_center_idx_0 = d_tmp;
  cosd_KZN3FnAl(&SWC_VC_B.c_center_idx_0);
  SWC_VC_B.e = d_tmp;
  sind_7is3Ljjc(&SWC_VC_B.e);
  SWC_VC_B.heading_angle_change_j = d_tmp;
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change_j);
  SWC_VC_B.g = d_tmp;
  cosd_KZN3FnAl(&SWC_VC_B.g);
  SWC_VC_B.step_size_e = phi + 180.0F;
  cosd_KZN3FnAl(&SWC_VC_B.step_size_e);
  c_center_idx_1 = phi + 180.0F;
  sind_7is3Ljjc(&c_center_idx_1);
  SWC_VC_B.c_center_idx_0 = (SWC_VC_B.c_center_idx_0 * SWC_VC_B.step_size_e +
    -SWC_VC_B.e * c_center_idx_1) * SWC_VC_B.turn_radius_para_a + x1;
  c_center_idx_1 = (SWC_VC_B.heading_angle_change_j * SWC_VC_B.step_size_e +
                    SWC_VC_B.g * c_center_idx_1) * SWC_VC_B.turn_radius_para_a +
    b_y1;
  SWC_VC_B.heading_angle_change_j = asinf(fmaxf(-1.0F, fminf(1.0F, (x2 -
    SWC_VC_B.c_center_idx_0) / SWC_VC_B.turn_radius_para_a))) * 57.2957802F *
    (real32_T)whl_dir + -(phi + 180.0F);
  sind_7is3Ljjc(&SWC_VC_B.heading_angle_change_j);
  SWC_VC_B.heading_angle_change_j = 57.2957802F * asinf
    (SWC_VC_B.heading_angle_change_j);
  if (SWC_VC_B.turn_radius_para_a < 100.0F) {
    if (SWC_VC_B.heading_angle_change_j < 0.0F) {
      SWC_VC_B.g = -1.0F;
    } else if (SWC_VC_B.heading_angle_change_j > 0.0F) {
      SWC_VC_B.g = 1.0F;
    } else if (SWC_VC_B.heading_angle_change_j == 0.0F) {
      SWC_VC_B.g = 0.0F;
    } else {
      SWC_VC_B.g = (rtNaNF);
    }

    SWC_VC_B.heading_angle_change_j += plan_params_aux_turn_para_regen *
      SWC_VC_B.g;
  }

  SWC_VC_B.m = phi + SWC_VC_B.heading_angle_change_j;
  if ((((phi < -180.0F) && (SWC_VC_B.m > -180.0F)) || ((phi > -180.0F) &&
        (SWC_VC_B.m < -180.0F))) && (!ParkOut)) {
    SWC_VC_B.heading_angle_change_j = -(phi + 180.0F);
  }

  if (SWC_VC_B.heading_angle_change_j < 0.0F) {
    SWC_VC_B.g = -1.0F;
  } else if (SWC_VC_B.heading_angle_change_j > 0.0F) {
    SWC_VC_B.g = 1.0F;
  } else if (SWC_VC_B.heading_angle_change_j == 0.0F) {
    SWC_VC_B.g = 0.0F;
  } else {
    SWC_VC_B.g = (rtNaNF);
  }

  SWC_VC_B.step_size_e = SWC_VC_B.g;
  while (fabsf(SWC_VC_B.heading_angle_change_j / SWC_VC_B.step_size_e) < 10.0F)
  {
    SWC_VC_B.step_size_e /= 2.0F;
  }

  run_count = 1U;
  do {
    exitg1 = 0;
    counter = 0U;
    SWC_VC_B.e = (phi + 180.0F) - d_tmp;
    SWC_VC_B.angle_o = roundf(SWC_VC_B.e * 1000.0F) / 1000.0F;
    SWC_VC_B.angle_bound_b = roundf((SWC_VC_B.angle_o +
      SWC_VC_B.heading_angle_change_j) * 1000.0F) / 1000.0F;
    do {
      exitg2 = 0;
      if (SWC_VC_B.step_size_e < 0.0F) {
        SWC_VC_B.m = -1.0F;
      } else if (SWC_VC_B.step_size_e > 0.0F) {
        SWC_VC_B.m = 1.0F;
      } else if (SWC_VC_B.step_size_e == 0.0F) {
        SWC_VC_B.m = 0.0F;
      } else {
        SWC_VC_B.m = (rtNaNF);
      }

      if (SWC_VC_B.angle_o * SWC_VC_B.m <= SWC_VC_B.angle_bound_b * SWC_VC_B.m)
      {
        x_out_data_tmp = (int32_T)(counter + 1U);
        if ((uint32_T)x_out_data_tmp > 255U) {
          x_out_data_tmp = 255;
        }

        counter = (uint8_T)x_out_data_tmp;
        SWC_VC_B.veh_heading_a = SWC_VC_B.angle_o;
        cosd_KZN3FnAl(&SWC_VC_B.veh_heading_a);
        x_out_data_tmp = (uint8_T)x_out_data_tmp - 1;
        SWC_VC_B.x_out_data_n[x_out_data_tmp] = SWC_VC_B.turn_radius_para_a *
          SWC_VC_B.veh_heading_a + SWC_VC_B.c_center_idx_0;
        SWC_VC_B.veh_heading_a = SWC_VC_B.angle_o;
        sind_7is3Ljjc(&SWC_VC_B.veh_heading_a);
        SWC_VC_B.y_out_data_i[x_out_data_tmp] = SWC_VC_B.turn_radius_para_a *
          SWC_VC_B.veh_heading_a + c_center_idx_1;
        SWC_VC_B.veh_heading_a = d_tmp + SWC_VC_B.angle_o;
        if (x2 - x1 <= 0.0F) {
          if (SWC_VC_B.veh_heading_a >= 0.0F) {
            SWC_VC_B.m = SWC_VC_B.veh_heading_a;
            cosd_KZN3FnAl(&SWC_VC_B.m);
            SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&SWC_VC_B.n_g);
            SWC_VC_B.x_f = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&SWC_VC_B.x_f);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading_a);
            SWC_VC_B.o_e = -(veh_params_Ke_AP_I_VehWheelbase +
                             veh_params_Ke_AP_I_VehFrontOverhang);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
              2.0F;
            SWC_VC_B.veh_heading_a = (SWC_VC_B.x_f * SWC_VC_B.o_e +
              SWC_VC_B.veh_heading_a * veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.y_out_data_i[x_out_data_tmp];
            if ((SWC_VC_B.m * SWC_VC_B.o_e + -SWC_VC_B.n_g *
                 veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                SWC_VC_B.x_out_data_n[x_out_data_tmp] <= pps[2]) {
              collision_flag = (SWC_VC_B.veh_heading_a >= pps[1]);
            }

            if (ParkOut) {
              park_out_flag = ((SWC_VC_B.veh_heading_a < pps[1] - -0.5F) ||
                               park_out_flag);
            }
          } else {
            SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
            cosd_KZN3FnAl(&SWC_VC_B.n_g);
            SWC_VC_B.o_e = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&SWC_VC_B.o_e);
            veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
            SWC_VC_B.x_f = SWC_VC_B.veh_heading_a;
            cosd_KZN3FnAl(&SWC_VC_B.x_f);
            SWC_VC_B.m = -(veh_params_Ke_AP_I_VehWheelbase +
                           veh_params_Ke_AP_I_VehFrontOverhang);
            if (((0.0F * SWC_VC_B.n_g + veh_params_Ke_AP_I_VehRearOverh_idx_1) *
                 SWC_VC_B.m + (0.0F * -SWC_VC_B.o_e + SWC_VC_B.x_f) *
                 (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                SWC_VC_B.y_out_data_i[x_out_data_tmp] >= pps[3] +
                plan_params_curb_over_Y_dir_para) {
              collision_flag = true;
            } else {
              SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
              cosd_KZN3FnAl(&SWC_VC_B.n_g);
              SWC_VC_B.o_e = SWC_VC_B.veh_heading_a;
              sind_7is3Ljjc(&SWC_VC_B.o_e);
              veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_a;
              sind_7is3Ljjc(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
              cosd_KZN3FnAl(&SWC_VC_B.veh_heading_a);
              collision_flag = ((((0.0F * veh_params_Ke_AP_I_VehRearOverh_idx_1
                                   + SWC_VC_B.n_g) * SWC_VC_B.m + (0.0F *
                SWC_VC_B.veh_heading_a + -SWC_VC_B.o_e) *
                                  (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                                 SWC_VC_B.x_out_data_n[x_out_data_tmp] <= pps[0])
                                || collision_flag);
            }
          }
        } else if (SWC_VC_B.veh_heading_a >= 0.0F) {
          SWC_VC_B.m = SWC_VC_B.veh_heading_a;
          cosd_KZN3FnAl(&SWC_VC_B.m);
          SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
          sind_7is3Ljjc(&SWC_VC_B.n_g);
          SWC_VC_B.o_e = SWC_VC_B.veh_heading_a;
          sind_7is3Ljjc(&SWC_VC_B.o_e);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = SWC_VC_B.veh_heading_a;
          cosd_KZN3FnAl(&veh_params_Ke_AP_I_VehRearOverh_idx_1);
          if (((0.0F * SWC_VC_B.m + SWC_VC_B.o_e) *
               veh_params_Ke_AP_I_VehRearOverhang + (0.0F * -SWC_VC_B.n_g +
                veh_params_Ke_AP_I_VehRearOverh_idx_1) *
               (veh_params_Ke_AP_I_VehWidth / 2.0F)) +
              SWC_VC_B.y_out_data_i[x_out_data_tmp] >= pps[5] +
              plan_params_curb_over_Y_dir_para) {
            collision_flag = true;
          } else {
            SWC_VC_B.m = SWC_VC_B.veh_heading_a;
            cosd_KZN3FnAl(&SWC_VC_B.m);
            SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&SWC_VC_B.n_g);
            SWC_VC_B.o_e = SWC_VC_B.veh_heading_a;
            sind_7is3Ljjc(&SWC_VC_B.o_e);
            cosd_KZN3FnAl(&SWC_VC_B.veh_heading_a);
            collision_flag = ((((0.0F * SWC_VC_B.o_e + SWC_VC_B.m) *
                                veh_params_Ke_AP_I_VehRearOverhang + (0.0F *
              SWC_VC_B.veh_heading_a + -SWC_VC_B.n_g) *
                                (-veh_params_Ke_AP_I_VehWidth / 2.0F)) +
                               SWC_VC_B.x_out_data_n[x_out_data_tmp] >= pps[6]) ||
                              collision_flag);
          }
        } else {
          SWC_VC_B.m = SWC_VC_B.veh_heading_a;
          cosd_KZN3FnAl(&SWC_VC_B.m);
          SWC_VC_B.n_g = SWC_VC_B.veh_heading_a;
          sind_7is3Ljjc(&SWC_VC_B.n_g);
          SWC_VC_B.o_e = SWC_VC_B.veh_heading_a;
          sind_7is3Ljjc(&SWC_VC_B.o_e);
          cosd_KZN3FnAl(&SWC_VC_B.veh_heading_a);
          veh_params_Ke_AP_I_VehRearOverh_idx_1 = veh_params_Ke_AP_I_VehWidth /
            2.0F;
          if ((SWC_VC_B.m * veh_params_Ke_AP_I_VehRearOverhang + -SWC_VC_B.n_g *
               veh_params_Ke_AP_I_VehRearOverh_idx_1) +
              SWC_VC_B.x_out_data_n[x_out_data_tmp] >= pps[4]) {
            collision_flag = (((SWC_VC_B.o_e *
                                veh_params_Ke_AP_I_VehRearOverhang +
                                SWC_VC_B.veh_heading_a *
                                veh_params_Ke_AP_I_VehRearOverh_idx_1) +
                               SWC_VC_B.y_out_data_i[x_out_data_tmp] >= pps[7]) ||
                              collision_flag);
          }
        }

        if (!collision_flag) {
          SWC_VC_B.angle_end_p = SWC_VC_B.angle_o;
          if (park_out_flag) {
            SWC_VC_B.x_out_h[0] = SWC_VC_B.x_out_data_n[x_out_data_tmp] -
              SWC_VC_B.x_out_data_n[0];
            SWC_VC_B.x_out_h[1] = SWC_VC_B.y_out_data_i[x_out_data_tmp] -
              SWC_VC_B.y_out_data_i[0];
            if (norm_5ISqY4yY(SWC_VC_B.x_out_h) > 0.5F) {
              exitg2 = 1;
            } else {
              SWC_VC_B.angle_o += SWC_VC_B.step_size_e;
            }
          } else {
            SWC_VC_B.angle_o += SWC_VC_B.step_size_e;
          }
        } else {
          counter = (uint8_T)x_out_data_tmp;
          exitg2 = 1;
        }
      } else {
        exitg2 = 1;
      }
    } while (exitg2 == 0);

    if ((counter > 1) && (run_count == 1)) {
      park_out_flag = false;
      collision_flag = false;
      if (fabsf(d_tmp + SWC_VC_B.angle_end_p) <= plan_params_ang_threshold_regen)
      {
        if (!ParkOut) {
          SWC_VC_B.x_out_h[0] = x2 - SWC_VC_B.x_out_data_n[0];
          SWC_VC_B.x_out_h[1] = SWC_VC_B.y_out_data_i[counter - 1] -
            SWC_VC_B.y_out_data_i[0];
          SWC_VC_B.step_size_e = (SWC_VC_B.angle_end_p - ((phi + 180.0F) - 90.0F
            * (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out_h) /
            plan_params_delta_s_para, 40.0F);
          SWC_VC_B.turn_radius_para_a = SWC_VC_B.heading_angle_change_j;
          sind_7is3Ljjc(&SWC_VC_B.turn_radius_para_a);
          SWC_VC_B.turn_radius_para_a = fabsf((x2 - x1) /
            SWC_VC_B.turn_radius_para_a);
          SWC_VC_B.c_center_idx_0 = d_tmp;
          cosd_KZN3FnAl(&SWC_VC_B.c_center_idx_0);
          SWC_VC_B.veh_heading_a = d_tmp;
          sind_7is3Ljjc(&SWC_VC_B.veh_heading_a);
          c_center_idx_1 = d_tmp;
          sind_7is3Ljjc(&c_center_idx_1);
          SWC_VC_B.e = d_tmp;
          cosd_KZN3FnAl(&SWC_VC_B.e);
          SWC_VC_B.angle_o = phi + 180.0F;
          cosd_KZN3FnAl(&SWC_VC_B.angle_o);
          SWC_VC_B.angle_bound_b = phi + 180.0F;
          sind_7is3Ljjc(&SWC_VC_B.angle_bound_b);
          SWC_VC_B.c_center_idx_0 = (SWC_VC_B.c_center_idx_0 * SWC_VC_B.angle_o
            + -SWC_VC_B.veh_heading_a * SWC_VC_B.angle_bound_b) *
            SWC_VC_B.turn_radius_para_a + x1;
          c_center_idx_1 = (c_center_idx_1 * SWC_VC_B.angle_o + SWC_VC_B.e *
                            SWC_VC_B.angle_bound_b) *
            SWC_VC_B.turn_radius_para_a + b_y1;
        } else {
          x_out_data_tmp = counter - 1;
          SWC_VC_B.x_out_h[0] = SWC_VC_B.x_out_data_n[x_out_data_tmp] -
            SWC_VC_B.x_out_data_n[0];
          SWC_VC_B.x_out_h[1] = SWC_VC_B.y_out_data_i[x_out_data_tmp] -
            SWC_VC_B.y_out_data_i[0];
          SWC_VC_B.step_size_e = (SWC_VC_B.angle_end_p - ((phi + 180.0F) - 90.0F
            * (real32_T)whl_dir)) / fminf(norm_5ISqY4yY(SWC_VC_B.x_out_h) /
            plan_params_delta_s_para, 40.0F);
        }
      } else {
        x_out_data_tmp = counter - 1;
        SWC_VC_B.x_out_h[0] = SWC_VC_B.x_out_data_n[x_out_data_tmp] -
          SWC_VC_B.x_out_data_n[0];
        SWC_VC_B.x_out_h[1] = SWC_VC_B.y_out_data_i[x_out_data_tmp] -
          SWC_VC_B.y_out_data_i[0];
        SWC_VC_B.step_size_e = (SWC_VC_B.angle_end_p - SWC_VC_B.e) / fminf
          (norm_5ISqY4yY(SWC_VC_B.x_out_h) / plan_params_delta_s_para, 40.0F);
      }

      SWC_VC_B.step_size_e = roundf(SWC_VC_B.step_size_e * 1000.0F) / 1000.0F;
      if (SWC_VC_B.step_size_e == 0.0F) {
        SWC_VC_B.step_size_e = SWC_VC_B.g * 0.01F;
      }

      run_count = 2U;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (counter > 0) {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_n[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_i[x_out_data_tmp];
    }

    x_out_data_tmp = counter - 1;
    output_data[100] = SWC_VC_B.x_out_data_n[x_out_data_tmp];
    output_data[101] = SWC_VC_B.y_out_data_i[x_out_data_tmp];
    output_data[102] = SWC_VC_B.angle_end_p - (180.0F - d_tmp);
    output_data[103] = counter;
    output_data[104] = park_out_flag;
  } else {
    output_size[0] = 1;
    output_size[1] = 105;
    for (x_out_data_tmp = 0; x_out_data_tmp < 50; x_out_data_tmp++) {
      output_data[x_out_data_tmp] = SWC_VC_B.x_out_data_n[x_out_data_tmp];
      output_data[x_out_data_tmp + 50] = SWC_VC_B.y_out_data_i[x_out_data_tmp];
    }

    output_data[100] = x1;
    output_data[101] = b_y1;
    output_data[102] = phi;
    output_data[103] = 0.0F;
    output_data[104] = park_out_flag;
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_diff(const real32_T x_data[], real32_T y_data[], int32_T
  *y_size)
{
  int32_T ixLead;
  int32_T iyLead;
  int32_T m;
  real32_T work_data;
  real32_T work_data_idx_0;
  ixLead = 1;
  iyLead = 0;
  work_data_idx_0 = x_data[0];
  for (m = 0; m < 249; m++) {
    work_data = x_data[ixLead];
    SWC_VC_B.b_y1_data[iyLead] = x_data[ixLead] - work_data_idx_0;
    ixLead++;
    iyLead++;
    work_data_idx_0 = work_data;
  }

  *y_size = 249;
  memcpy(&y_data[0], &SWC_VC_B.b_y1_data[0], 249U * sizeof(real32_T));
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_atan2d(const real32_T y_data[], const int32_T *y_size, const
  real32_T x_data[], real32_T r_data[], int32_T *r_size)
{
  int32_T loop_ub;
  uint8_T csz_idx_0;
  csz_idx_0 = (uint8_T)*y_size;
  if (0 <= csz_idx_0 - 1) {
    memcpy(&SWC_VC_B.z1_data_n[0], &r_data[0], csz_idx_0 * sizeof(real32_T));
  }

  for (loop_ub = 0; loop_ub < csz_idx_0; loop_ub++) {
    SWC_VC_B.z1_data_n[loop_ub] = 57.2957802F * rt_atan2f_snf(y_data[loop_ub],
      x_data[loop_ub]);
  }

  *r_size = (uint8_T)*y_size;
  if (0 <= csz_idx_0 - 1) {
    memcpy(&r_data[0], &SWC_VC_B.z1_data_n[0], csz_idx_0 * sizeof(real32_T));
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_power(const real32_T a_data[], real32_T y_data[], int32_T
  *y_size)
{
  int32_T k;
  *y_size = 249;
  for (k = 0; k < 249; k++) {
    y_data[k] = a_data[k] * a_data[k];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_sqrt(real32_T x_data[])
{
  int32_T k;
  for (k = 0; k < 249; k++) {
    x_data[k] = sqrtf(x_data[k]);
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_post_render_common(const real32_T xx_data[], const real32_T
  yy_data[], uint8_T idx_end, real32_T Kf, real32_T delta_s, real32_T fxo_data[],
  int32_T fxo_size[2], real32_T fyo_data[], int32_T fyo_size[2], uint8_T
  *total_num_idx)
{
  uint8_T i;
  uint8_T j;
  int32_T e_i;
  real32_T a;
  real32_T b_a;
  uint32_T qY;
  int32_T fxp_data_tmp;
  int32_T fxp_data_tmp_0;
  int32_T exitg1;
  fxo_size[0] = 1;
  fxo_size[1] = 250;
  fyo_size[0] = 1;
  fyo_size[1] = 250;
  i = 1U;
  j = 2U;
  SWC_VC_B.fxp_data_f[0] = xx_data[0];
  SWC_VC_B.fyp_data_g[0] = yy_data[0];
  do {
    exitg1 = 0;
    qY = idx_end - /*MW:OvSatOk*/ 1U;
    if (qY > idx_end) {
      qY = 0U;
    }

    if (j < (int32_T)qY + 1) {
      fxp_data_tmp_0 = j - 1;
      e_i = i - 1;
      a = xx_data[fxp_data_tmp_0] - SWC_VC_B.fxp_data_f[e_i];
      b_a = yy_data[fxp_data_tmp_0] - SWC_VC_B.fyp_data_g[e_i];
      if (sqrtf(a * a + b_a * b_a) > delta_s) {
        e_i = (int32_T)(i + 1U);
        if ((uint32_T)e_i > 255U) {
          e_i = 255;
        }

        i = (uint8_T)e_i;
        fxp_data_tmp = (uint8_T)e_i - 1;
        SWC_VC_B.fxp_data_f[fxp_data_tmp] = xx_data[fxp_data_tmp_0];
        SWC_VC_B.fyp_data_g[fxp_data_tmp] = yy_data[fxp_data_tmp_0];
      }

      j++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  e_i = (int32_T)(i + 1U);
  if ((uint32_T)e_i > 255U) {
    e_i = 255;
  }

  fxp_data_tmp = idx_end - 1;
  fxp_data_tmp_0 = (uint8_T)e_i - 1;
  SWC_VC_B.fxp_data_f[fxp_data_tmp_0] = xx_data[fxp_data_tmp];
  SWC_VC_B.fyp_data_g[fxp_data_tmp_0] = yy_data[fxp_data_tmp];
  *total_num_idx = (uint8_T)e_i;
  if (Kf < 1.0F) {
    for (fxp_data_tmp = 0; fxp_data_tmp <= fxp_data_tmp_0; fxp_data_tmp++) {
      SWC_VC_B.xf1_data_g[fxp_data_tmp] = SWC_VC_B.fxp_data_f[fxp_data_tmp];
      SWC_VC_B.xf2_data_n[fxp_data_tmp] = SWC_VC_B.fxp_data_f[fxp_data_tmp];
      SWC_VC_B.yf1_data_m[fxp_data_tmp] = SWC_VC_B.fyp_data_g[fxp_data_tmp];
      SWC_VC_B.yf2_data_p[fxp_data_tmp] = SWC_VC_B.fyp_data_g[fxp_data_tmp];
    }

    for (fxp_data_tmp = 1; fxp_data_tmp - 1 <= (uint8_T)e_i - 3; fxp_data_tmp++)
    {
      SWC_VC_B.xf1_data_g[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf1_data_g[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fxp_data_f[fxp_data_tmp];
      SWC_VC_B.yf1_data_m[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf1_data_m[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fyp_data_g[fxp_data_tmp];
      SWC_VC_B.xf2_data_n[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf2_data_n[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.xf1_data_g[fxp_data_tmp];
      SWC_VC_B.yf2_data_p[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf2_data_p[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.yf1_data_m[fxp_data_tmp];
    }

    memcpy(&SWC_VC_B.fxp_data_f[0], &SWC_VC_B.xf2_data_n[0], 250U * sizeof
           (real32_T));
    memcpy(&SWC_VC_B.fyp_data_g[0], &SWC_VC_B.yf2_data_p[0], 250U * sizeof
           (real32_T));
    i = (uint8_T)fxp_data_tmp_0;
    while (i > 1) {
      e_i = i - 1;
      SWC_VC_B.xf1_data_g[e_i] = (1.0F - Kf) * SWC_VC_B.xf1_data_g[i] +
        SWC_VC_B.fxp_data_f[e_i] * Kf;
      SWC_VC_B.yf1_data_m[e_i] = (1.0F - Kf) * SWC_VC_B.yf1_data_m[i] +
        SWC_VC_B.fyp_data_g[e_i] * Kf;
      SWC_VC_B.xf2_data_n[e_i] = (1.0F - Kf) * SWC_VC_B.xf2_data_n[i] +
        SWC_VC_B.xf1_data_g[e_i] * Kf;
      SWC_VC_B.yf2_data_p[e_i] = (1.0F - Kf) * SWC_VC_B.yf2_data_p[i] +
        SWC_VC_B.yf1_data_m[e_i] * Kf;
      i = (uint8_T)e_i;
    }

    memcpy(&SWC_VC_B.fxp_data_f[0], &SWC_VC_B.xf2_data_n[0], 250U * sizeof
           (real32_T));
    memcpy(&SWC_VC_B.fyp_data_g[0], &SWC_VC_B.yf2_data_p[0], 250U * sizeof
           (real32_T));
  }

  for (e_i = 0; e_i <= fxp_data_tmp_0; e_i++) {
    fxo_data[e_i] = SWC_VC_B.fxp_data_f[e_i];
    fyo_data[e_i] = SWC_VC_B.fyp_data_g[e_i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_abs(const real32_T x_data[], real32_T y_data[], int32_T
  *y_size)
{
  int32_T k;
  *y_size = 249;
  for (k = 0; k < 249; k++) {
    y_data[k] = fabsf(x_data[k]);
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_Bezier_path_function_common(real32_T W0[2], real32_T W1[2],
  real32_T W2[2], uint8_T n, real32_T *extrema, real32_T x_out_data[], int32_T
  x_out_size[2], real32_T y_out_data[], int32_T y_out_size[2], uint8_T *num_idx)
{
  boolean_T flag;
  uint8_T d_i;
  boolean_T tmp;
  real32_T kappa_num_data_tmp;
  real32_T kappa_num_data_tmp_0;
  real32_T kappa_num_data_tmp_1;
  real32_T kappa_num_data_tmp_2;
  real32_T kappa_num_data_tmp_3;
  real32_T kappa_num_data_tmp_tmp;
  boolean_T exitg1;
  x_out_size[0] = 1;
  x_out_size[1] = 50;
  y_out_size[0] = 1;
  y_out_size[1] = 50;
  if (n >= 49) {
    n = 49U;
  }

  SWC_VC_B.step_size_f = roundf(1.0F / (real32_T)n * 10000.0F) / 10000.0F;
  SWC_VC_B.theta_rotation_h = 1.57079637F - rt_atan2f_snf((W0[1] - 2.0F * W1[1])
    + W2[1], (W0[0] - 2.0F * W1[0]) + W2[0]);
  SWC_VC_B.Rot_tmp_tmp_m = sinf(SWC_VC_B.theta_rotation_h);
  SWC_VC_B.theta_rotation_h = cosf(SWC_VC_B.theta_rotation_h);
  SWC_VC_B.Rot_idx_0 = SWC_VC_B.theta_rotation_h * W0[0] +
    -SWC_VC_B.Rot_tmp_tmp_m * W0[1];
  SWC_VC_B.beta1_b = SWC_VC_B.Rot_tmp_tmp_m * W0[0] + SWC_VC_B.theta_rotation_h *
    W0[1];
  W0[0] = SWC_VC_B.Rot_idx_0;
  SWC_VC_B.i_m = SWC_VC_B.theta_rotation_h * W1[0] + -SWC_VC_B.Rot_tmp_tmp_m *
    W1[1];
  W0[1] = SWC_VC_B.beta1_b;
  SWC_VC_B.Rot_n = SWC_VC_B.Rot_tmp_tmp_m * W1[0] + SWC_VC_B.theta_rotation_h *
    W1[1];
  W1[0] = SWC_VC_B.i_m;
  SWC_VC_B.alpha2_k = SWC_VC_B.theta_rotation_h * W2[0] +
    -SWC_VC_B.Rot_tmp_tmp_m * W2[1];
  W1[1] = SWC_VC_B.Rot_n;
  SWC_VC_B.Rot_i = SWC_VC_B.Rot_tmp_tmp_m * W2[0] + SWC_VC_B.theta_rotation_h *
    W2[1];
  W2[1] = SWC_VC_B.Rot_i;
  SWC_VC_B.a_c = ((SWC_VC_B.beta1_b - 2.0F * SWC_VC_B.Rot_n) + SWC_VC_B.Rot_i) *
    3.0F;
  if (fabsf(SWC_VC_B.Rot_idx_0) <= 1.0E-5) {
    *extrema = 0.0F;
    SWC_VC_B.step_size_f = (SWC_VC_B.Rot_idx_0 + SWC_VC_B.i_m) +
      SWC_VC_B.alpha2_k;
    SWC_VC_B.beta1_b = (SWC_VC_B.beta1_b + SWC_VC_B.Rot_n) + SWC_VC_B.Rot_i;
    SWC_VC_B.a_c = SWC_VC_B.theta_rotation_h * SWC_VC_B.step_size_f +
      SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.beta1_b;
    SWC_VC_B.Rot_tmp_tmp_m = -SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.step_size_f +
      SWC_VC_B.theta_rotation_h * SWC_VC_B.beta1_b;
    x_out_data[0] = 0.0F;
    y_out_data[0] = 0.0F;
    *num_idx = 0U;
    SWC_VC_B.c_k_c = 0;
    while (SWC_VC_B.c_k_c <= n - 1) {
      SWC_VC_B.idx_g = (int32_T)(*num_idx + 1U);
      if ((uint32_T)SWC_VC_B.idx_g > 255U) {
        SWC_VC_B.idx_g = 255;
      }

      *num_idx = (uint8_T)SWC_VC_B.idx_g;
      x_out_data[SWC_VC_B.c_k_c + 1] = SWC_VC_B.a_c / (real32_T)n +
        x_out_data[SWC_VC_B.c_k_c];
      y_out_data[SWC_VC_B.c_k_c + 1] = SWC_VC_B.Rot_tmp_tmp_m / (real32_T)n +
        y_out_data[SWC_VC_B.c_k_c];
      SWC_VC_B.c_k_c++;
    }
  } else {
    SWC_VC_B.alpha2_k = SWC_VC_B.i_m - SWC_VC_B.Rot_idx_0;
    if (fabsf(SWC_VC_B.alpha2_k) <= 1.0E-5) {
      SWC_VC_B.alpha1_a = SWC_VC_B.beta1_b / SWC_VC_B.Rot_idx_0;
      SWC_VC_B.i_m = SWC_VC_B.Rot_idx_0 * SWC_VC_B.Rot_idx_0;
      SWC_VC_B.kappa_num_I_idx_1 = SWC_VC_B.i_m * 3.0F;
      SWC_VC_B.alpha2_k = (SWC_VC_B.Rot_n - SWC_VC_B.beta1_b) /
        SWC_VC_B.kappa_num_I_idx_1;
      SWC_VC_B.kappa_num_data_tmp = 27.0F * rt_powf_snf(SWC_VC_B.Rot_idx_0, 3.0F);
      SWC_VC_B.alpha3_p = SWC_VC_B.a_c / SWC_VC_B.kappa_num_data_tmp;
      flag = false;
      if (SWC_VC_B.alpha3_p < 0.0F) {
        flag = true;
        W0[1] = -SWC_VC_B.beta1_b;
        W1[1] = -SWC_VC_B.Rot_n;
        W2[1] = -SWC_VC_B.Rot_i;
        SWC_VC_B.a_c = ((-SWC_VC_B.beta1_b - 2.0F * -SWC_VC_B.Rot_n) +
                        -SWC_VC_B.Rot_i) * 3.0F;
        SWC_VC_B.alpha1_a = -SWC_VC_B.beta1_b / SWC_VC_B.Rot_idx_0;
        SWC_VC_B.alpha2_k = (-SWC_VC_B.Rot_n - (-SWC_VC_B.beta1_b)) /
          SWC_VC_B.kappa_num_I_idx_1;
        SWC_VC_B.alpha3_p = SWC_VC_B.a_c / SWC_VC_B.kappa_num_data_tmp;
      }

      SWC_VC_B.beta1_b = SWC_VC_B.alpha1_a - SWC_VC_B.alpha2_k *
        SWC_VC_B.alpha2_k / SWC_VC_B.alpha3_p;
      SWC_VC_B.beta1_b = sqrtf((sqrtf(SWC_VC_B.beta1_b * SWC_VC_B.beta1_b * 9.0F
        + 5.0F) + -2.0F * SWC_VC_B.beta1_b) / 5.0F);
      SWC_VC_B.alpha1_a = sqrtf(SWC_VC_B.alpha3_p);
      SWC_VC_B.Rot_f[0] = (SWC_VC_B.beta1_b - SWC_VC_B.alpha2_k /
                           SWC_VC_B.alpha1_a) / SWC_VC_B.alpha1_a / 3.0F /
        SWC_VC_B.Rot_idx_0;
      SWC_VC_B.Rot_f[1] = (-SWC_VC_B.beta1_b - SWC_VC_B.alpha2_k / sqrtf
                           (SWC_VC_B.alpha3_p)) / SWC_VC_B.alpha1_a / 3.0F /
        SWC_VC_B.Rot_idx_0;
      SWC_VC_B.beta1_b = W0[1] * W0[1];
      SWC_VC_B.alpha1_a = SWC_VC_B.Rot_f[0] * SWC_VC_B.Rot_f[0];
      SWC_VC_B.Rot_n = SWC_VC_B.beta1_b * 36.0F;
      SWC_VC_B.kappa_num_I_idx_1 = rt_powf_snf(SWC_VC_B.Rot_f[0], 3.0F);
      SWC_VC_B.alpha2_k = -3.0F * W1[1] + 3.0F * W0[1];
      SWC_VC_B.beta1_b = SWC_VC_B.i_m * 9.0F + SWC_VC_B.beta1_b * 9.0F;
      SWC_VC_B.i_m = 6.0F * W0[1] * SWC_VC_B.a_c;
      SWC_VC_B.Rot_i = W1[1] * W1[1];
      SWC_VC_B.alpha3_p = SWC_VC_B.a_c * SWC_VC_B.a_c;
      SWC_VC_B.alpha1_a = (SWC_VC_B.alpha2_k - SWC_VC_B.a_c * SWC_VC_B.Rot_f[0])
        * (-6.0F * SWC_VC_B.Rot_idx_0) / rt_powf_snf(((((((((SWC_VC_B.beta1_b +
        36.0F * W0[1] * SWC_VC_B.Rot_f[0] * W1[1]) - SWC_VC_B.Rot_n *
        SWC_VC_B.Rot_f[0]) + SWC_VC_B.i_m * SWC_VC_B.alpha1_a) +
        SWC_VC_B.alpha1_a * 36.0F * SWC_VC_B.Rot_i) - SWC_VC_B.alpha1_a * 72.0F *
        W1[1] * W0[1]) + 12.0F * SWC_VC_B.kappa_num_I_idx_1 * W1[1] *
        SWC_VC_B.a_c) + SWC_VC_B.Rot_n * SWC_VC_B.alpha1_a) - 12.0F * W0[1] *
        SWC_VC_B.kappa_num_I_idx_1 * SWC_VC_B.a_c) + SWC_VC_B.alpha3_p *
        rt_powf_snf(SWC_VC_B.Rot_f[0], 4.0F), 1.5F);
      SWC_VC_B.kappa_num_I_idx_1 = SWC_VC_B.Rot_f[1] * SWC_VC_B.Rot_f[1];
      SWC_VC_B.kappa_num_data_tmp = rt_powf_snf(SWC_VC_B.Rot_f[1], 3.0F);
      SWC_VC_B.kappa_num_I_idx_1 = (SWC_VC_B.alpha2_k - SWC_VC_B.a_c *
        SWC_VC_B.Rot_f[1]) * (-6.0F * SWC_VC_B.Rot_idx_0) / rt_powf_snf
        (((((((((SWC_VC_B.beta1_b + 36.0F * W0[1] * SWC_VC_B.Rot_f[1] * W1[1]) -
                SWC_VC_B.Rot_n * SWC_VC_B.Rot_f[1]) + SWC_VC_B.i_m *
               SWC_VC_B.kappa_num_I_idx_1) + SWC_VC_B.kappa_num_I_idx_1 * 36.0F *
              SWC_VC_B.Rot_i) - SWC_VC_B.kappa_num_I_idx_1 * 72.0F * W1[1] * W0
             [1]) + 12.0F * SWC_VC_B.kappa_num_data_tmp * W1[1] * SWC_VC_B.a_c)
           + SWC_VC_B.Rot_n * SWC_VC_B.kappa_num_I_idx_1) - 12.0F * W0[1] *
          SWC_VC_B.kappa_num_data_tmp * SWC_VC_B.a_c) + SWC_VC_B.alpha3_p *
         rt_powf_snf(SWC_VC_B.Rot_f[1], 4.0F), 1.5F);
      SWC_VC_B.Rot_f[0] = fabsf(SWC_VC_B.alpha1_a);
      SWC_VC_B.Rot_f[1] = fabsf(SWC_VC_B.kappa_num_I_idx_1);
      SWC_VC_B.alpha1_a = SWC_VC_B.Rot_n * 0.0F;
      SWC_VC_B.Rot_f[2] = fabsf((SWC_VC_B.alpha2_k - SWC_VC_B.a_c * 0.0F) *
        (-6.0F * SWC_VC_B.Rot_idx_0) / rt_powf_snf(((((((((SWC_VC_B.beta1_b +
        36.0F * W0[1] * 0.0F * W1[1]) - SWC_VC_B.alpha1_a) + SWC_VC_B.i_m * 0.0F)
        + SWC_VC_B.Rot_i * 0.0F) - 0.0F * W1[1] * W0[1]) + 0.0F * W1[1] *
        SWC_VC_B.a_c) + SWC_VC_B.alpha1_a) - 12.0F * W0[1] * 0.0F * SWC_VC_B.a_c)
        + SWC_VC_B.alpha3_p * 0.0F, 1.5F));
      SWC_VC_B.Rot_f[3] = fabsf((SWC_VC_B.alpha2_k - SWC_VC_B.a_c) * (-6.0F *
        SWC_VC_B.Rot_idx_0) / rt_powf_snf(((((((((SWC_VC_B.beta1_b + 36.0F * W0
        [1] * W1[1]) - SWC_VC_B.Rot_n) + SWC_VC_B.i_m) + SWC_VC_B.Rot_i * 36.0F)
        - 72.0F * W1[1] * W0[1]) + 12.0F * W1[1] * SWC_VC_B.a_c) +
        SWC_VC_B.Rot_n) - 12.0F * W0[1] * SWC_VC_B.a_c) + SWC_VC_B.alpha3_p,
        1.5F));
      if (!rtIsNaNF(SWC_VC_B.Rot_f[0])) {
        SWC_VC_B.idx_g = 1;
      } else {
        SWC_VC_B.idx_g = 0;
        SWC_VC_B.c_k_c = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k_c <= 4)) {
          if (!rtIsNaNF(SWC_VC_B.Rot_f[SWC_VC_B.c_k_c - 1])) {
            SWC_VC_B.idx_g = SWC_VC_B.c_k_c;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k_c++;
          }
        }
      }

      if (SWC_VC_B.idx_g == 0) {
        *extrema = SWC_VC_B.Rot_f[0];
      } else {
        *extrema = SWC_VC_B.Rot_f[SWC_VC_B.idx_g - 1];
        while (SWC_VC_B.idx_g + 1 <= 4) {
          if (*extrema < SWC_VC_B.Rot_f[SWC_VC_B.idx_g]) {
            *extrema = SWC_VC_B.Rot_f[SWC_VC_B.idx_g];
          }

          SWC_VC_B.idx_g++;
        }
      }

      if (flag) {
        W0[1] = -W0[1];
        W1[1] = -W1[1];
        W2[1] = -W2[1];
        SWC_VC_B.a_c = ((W0[1] - 2.0F * W1[1]) + W2[1]) * 3.0F;
      }

      *num_idx = 0U;
      SWC_VC_B.i_m = 0.0F;
      while (SWC_VC_B.i_m <= 1.0F) {
        SWC_VC_B.idx_g = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx_g > 255U) {
          SWC_VC_B.idx_g = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx_g;
        SWC_VC_B.alpha2_k = 3.0F * SWC_VC_B.Rot_idx_0 * SWC_VC_B.i_m;
        SWC_VC_B.Rot_i = ((W1[1] - W0[1]) * 3.0F * (SWC_VC_B.i_m * SWC_VC_B.i_m)
                          + 3.0F * W0[1] * SWC_VC_B.i_m) + 0.333333343F *
          SWC_VC_B.a_c * rt_powf_snf(SWC_VC_B.i_m, 3.0F);
        SWC_VC_B.idx_g = (uint8_T)SWC_VC_B.idx_g - 1;
        x_out_data[SWC_VC_B.idx_g] = SWC_VC_B.theta_rotation_h *
          SWC_VC_B.alpha2_k + SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.Rot_i;
        y_out_data[SWC_VC_B.idx_g] = -SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.alpha2_k
          + SWC_VC_B.theta_rotation_h * SWC_VC_B.Rot_i;
        SWC_VC_B.i_m += SWC_VC_B.step_size_f;
      }
    } else {
      flag = false;
      if (SWC_VC_B.alpha2_k < 0.0F) {
        flag = true;
        W0[0] = -SWC_VC_B.Rot_idx_0;
        W1[0] = -SWC_VC_B.i_m;
      }

      *num_idx = 0U;
      SWC_VC_B.i_m = 0.0F;
      while (SWC_VC_B.i_m <= 1.0F) {
        SWC_VC_B.idx_g = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx_g > 255U) {
          SWC_VC_B.idx_g = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx_g;
        SWC_VC_B.alpha2_k = rt_powf_snf(SWC_VC_B.i_m, 3.0F);
        SWC_VC_B.Rot_idx_0 = SWC_VC_B.i_m * SWC_VC_B.i_m;
        SWC_VC_B.Rot_i = 2.0F * (real32_T)flag;
        SWC_VC_B.alpha3_p = SWC_VC_B.Rot_i * W0[0];
        SWC_VC_B.alpha1_a = SWC_VC_B.beta1_b * SWC_VC_B.beta1_b;
        SWC_VC_B.kappa_num_I_idx_1 = SWC_VC_B.alpha1_a * 36.0F;
        SWC_VC_B.kappa_num_data_tmp = W0[0] * W0[0];
        SWC_VC_B.kappa_num_data_tmp_j = 144.0F * (real32_T)flag;
        SWC_VC_B.kappa_num_data_tmp_e = SWC_VC_B.kappa_num_data_tmp_j * W0[0] *
          SWC_VC_B.i_m * W1[0];
        SWC_VC_B.kappa_num_data_tmp_m = 288.0F * (real32_T)flag *
          SWC_VC_B.Rot_idx_0 * W1[0] * W0[0];
        SWC_VC_B.kappa_num_data_tmp_m0 = SWC_VC_B.Rot_idx_0 * 36.0F;
        kappa_num_data_tmp = SWC_VC_B.kappa_num_data_tmp * 36.0F;
        kappa_num_data_tmp_0 = 36.0F * (real32_T)flag *
          SWC_VC_B.kappa_num_data_tmp;
        kappa_num_data_tmp_1 = SWC_VC_B.Rot_idx_0 * 72.0F;
        kappa_num_data_tmp_tmp = SWC_VC_B.kappa_num_data_tmp_j *
          SWC_VC_B.kappa_num_data_tmp;
        kappa_num_data_tmp_2 = kappa_num_data_tmp_tmp * SWC_VC_B.i_m;
        kappa_num_data_tmp_3 = W1[0] * W1[0];
        SWC_VC_B.kappa_num_data_tmp_j = SWC_VC_B.kappa_num_data_tmp_j *
          SWC_VC_B.Rot_idx_0 * kappa_num_data_tmp_3;
        kappa_num_data_tmp_tmp *= SWC_VC_B.Rot_idx_0;
        SWC_VC_B.kappa_num_data[(uint8_T)SWC_VC_B.idx_g - 1] =
          (((((((((SWC_VC_B.Rot_idx_0 * W0[0] * SWC_VC_B.a_c + 6.0F * (real32_T)
                   flag * W0[0] * SWC_VC_B.Rot_n) - W0[0] * SWC_VC_B.a_c *
                  SWC_VC_B.i_m) - 6.0F * SWC_VC_B.beta1_b * (real32_T)flag * W1
                 [0]) - 3.0F * W0[0] * SWC_VC_B.Rot_n) + 3.0F * SWC_VC_B.beta1_b
               * W1[0]) - SWC_VC_B.Rot_idx_0 * W1[0] * SWC_VC_B.a_c) +
             SWC_VC_B.alpha3_p * SWC_VC_B.a_c * SWC_VC_B.i_m) + SWC_VC_B.Rot_i *
            SWC_VC_B.Rot_idx_0 * W1[0] * SWC_VC_B.a_c) - SWC_VC_B.alpha3_p *
           SWC_VC_B.Rot_idx_0 * SWC_VC_B.a_c) * -6.0F / rt_powf_snf
          (((((((((((((((((((((((((((SWC_VC_B.kappa_num_data_tmp * 9.0F -
          kappa_num_data_tmp_1 * SWC_VC_B.Rot_n * SWC_VC_B.beta1_b) + 12.0F *
          SWC_VC_B.alpha2_k * SWC_VC_B.Rot_n * SWC_VC_B.a_c) - 12.0F *
          SWC_VC_B.beta1_b * SWC_VC_B.alpha2_k * SWC_VC_B.a_c) + 36.0F *
          SWC_VC_B.beta1_b * SWC_VC_B.i_m * SWC_VC_B.Rot_n) + 6.0F *
          SWC_VC_B.beta1_b * SWC_VC_B.a_c * SWC_VC_B.Rot_idx_0) +
          SWC_VC_B.alpha1_a * 9.0F) - SWC_VC_B.kappa_num_I_idx_1 * SWC_VC_B.i_m)
          + SWC_VC_B.kappa_num_data_tmp_m0 * (SWC_VC_B.Rot_n * SWC_VC_B.Rot_n))
                             + SWC_VC_B.kappa_num_I_idx_1 * SWC_VC_B.Rot_idx_0)
                            + SWC_VC_B.a_c * SWC_VC_B.a_c * rt_powf_snf
                            (SWC_VC_B.i_m, 4.0F)) + kappa_num_data_tmp_0) +
                          kappa_num_data_tmp_2) + SWC_VC_B.kappa_num_data_tmp_e)
                        - SWC_VC_B.kappa_num_data_tmp_m) -
                       SWC_VC_B.kappa_num_data_tmp_e) +
                      SWC_VC_B.kappa_num_data_tmp_m) - kappa_num_data_tmp *
                     SWC_VC_B.i_m) + SWC_VC_B.kappa_num_data_tmp_m0 *
                    kappa_num_data_tmp_3) + kappa_num_data_tmp *
                   SWC_VC_B.Rot_idx_0) - kappa_num_data_tmp_0) -
                 kappa_num_data_tmp_1 * W1[0] * W0[0]) + 36.0F * W0[0] *
                SWC_VC_B.i_m * W1[0]) - kappa_num_data_tmp_2) +
              SWC_VC_B.kappa_num_data_tmp_j) + kappa_num_data_tmp_tmp) -
            SWC_VC_B.kappa_num_data_tmp_j) - kappa_num_data_tmp_tmp, 1.5F);
        SWC_VC_B.i_m += SWC_VC_B.step_size_f;
      }

      SWC_VC_B.idx_g = (int32_T)(*num_idx + 1U);
      if ((uint32_T)SWC_VC_B.idx_g > 255U) {
        SWC_VC_B.idx_g = 255;
      }

      for (d_i = (uint8_T)SWC_VC_B.idx_g; d_i < 51; d_i++) {
        SWC_VC_B.kappa_num_data[d_i - 1] = SWC_VC_B.kappa_num_data[*num_idx - 1];
      }

      tmp = rtIsNaNF(SWC_VC_B.kappa_num_data[0]);
      if (!tmp) {
        SWC_VC_B.idx_g = 1;
      } else {
        SWC_VC_B.idx_g = 0;
        SWC_VC_B.c_k_c = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k_c <= 50)) {
          if (!rtIsNaNF(SWC_VC_B.kappa_num_data[SWC_VC_B.c_k_c - 1])) {
            SWC_VC_B.idx_g = SWC_VC_B.c_k_c;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k_c++;
          }
        }
      }

      if (SWC_VC_B.idx_g == 0) {
        SWC_VC_B.i_m = SWC_VC_B.kappa_num_data[0];
      } else {
        SWC_VC_B.i_m = SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g - 1];
        while (SWC_VC_B.idx_g + 1 <= 50) {
          if (SWC_VC_B.i_m < SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g]) {
            SWC_VC_B.i_m = SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g];
          }

          SWC_VC_B.idx_g++;
        }
      }

      if (!tmp) {
        SWC_VC_B.idx_g = 1;
      } else {
        SWC_VC_B.idx_g = 0;
        SWC_VC_B.c_k_c = 2;
        exitg1 = false;
        while ((!exitg1) && (SWC_VC_B.c_k_c <= 50)) {
          if (!rtIsNaNF(SWC_VC_B.kappa_num_data[SWC_VC_B.c_k_c - 1])) {
            SWC_VC_B.idx_g = SWC_VC_B.c_k_c;
            exitg1 = true;
          } else {
            SWC_VC_B.c_k_c++;
          }
        }
      }

      if (SWC_VC_B.idx_g == 0) {
        SWC_VC_B.Rot_idx_0 = SWC_VC_B.kappa_num_data[0];
      } else {
        SWC_VC_B.Rot_idx_0 = SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g - 1];
        while (SWC_VC_B.idx_g + 1 < 51) {
          if (SWC_VC_B.Rot_idx_0 > SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g]) {
            SWC_VC_B.Rot_idx_0 = SWC_VC_B.kappa_num_data[SWC_VC_B.idx_g];
          }

          SWC_VC_B.idx_g++;
        }
      }

      *extrema = fabsf(SWC_VC_B.i_m);
      SWC_VC_B.Rot_idx_0 = fabsf(SWC_VC_B.Rot_idx_0);
      if (*extrema < SWC_VC_B.Rot_idx_0) {
        *extrema = SWC_VC_B.Rot_idx_0;
      } else {
        if (rtIsNaNF(*extrema) && (!rtIsNaNF(SWC_VC_B.Rot_idx_0))) {
          *extrema = SWC_VC_B.Rot_idx_0;
        }
      }

      if (flag) {
        W0[0] = -W0[0];
        W1[0] = -W1[0];
      }

      *num_idx = 0U;
      SWC_VC_B.i_m = 0.0F;
      while (SWC_VC_B.i_m <= 1.0F) {
        SWC_VC_B.idx_g = (int32_T)(*num_idx + 1U);
        if ((uint32_T)SWC_VC_B.idx_g > 255U) {
          SWC_VC_B.idx_g = 255;
        }

        *num_idx = (uint8_T)SWC_VC_B.idx_g;
        SWC_VC_B.Rot_idx_0 = SWC_VC_B.i_m * SWC_VC_B.i_m;
        SWC_VC_B.alpha2_k = (W1[0] - W0[0]) * 3.0F * SWC_VC_B.Rot_idx_0 + 3.0F *
          W0[0] * SWC_VC_B.i_m;
        SWC_VC_B.Rot_i = ((SWC_VC_B.Rot_n - SWC_VC_B.beta1_b) * 3.0F *
                          SWC_VC_B.Rot_idx_0 + 3.0F * SWC_VC_B.beta1_b *
                          SWC_VC_B.i_m) + 0.333333343F * SWC_VC_B.a_c *
          rt_powf_snf(SWC_VC_B.i_m, 3.0F);
        SWC_VC_B.idx_g = (uint8_T)SWC_VC_B.idx_g - 1;
        x_out_data[SWC_VC_B.idx_g] = SWC_VC_B.theta_rotation_h *
          SWC_VC_B.alpha2_k + SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.Rot_i;
        y_out_data[SWC_VC_B.idx_g] = -SWC_VC_B.Rot_tmp_tmp_m * SWC_VC_B.alpha2_k
          + SWC_VC_B.theta_rotation_h * SWC_VC_B.Rot_i;
        SWC_VC_B.i_m += SWC_VC_B.step_size_f;
      }
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_mod(const real32_T x_data[], real32_T y, real32_T r_data[],
  int32_T *r_size)
{
  int32_T k;
  *r_size = 250;
  for (k = 0; k < 250; k++) {
    r_data[k] = mod_jpURcOT9(x_data[k], y);
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_post_render_common_m(const real32_T xx_data[], const real32_T
  yy_data[], uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T delta_s,
  real32_T fxo_data[], int32_T fxo_size[2], real32_T fyo_data[], int32_T
  fyo_size[2], uint8_T *total_num_idx)
{
  uint8_T i;
  uint8_T j;
  int32_T e_i;
  real32_T a;
  real32_T b_a;
  uint32_T qY;
  int32_T tmp;
  int32_T fxp_data_tmp;
  int32_T fxp_data_tmp_0;
  int32_T exitg1;
  fxo_size[0] = 1;
  fxo_size[1] = 250;
  fyo_size[0] = 1;
  fyo_size[1] = 250;
  i = 1U;
  j = 2U;
  fxp_data_tmp = idx_begin - 1;
  SWC_VC_B.fxp_data[0] = xx_data[fxp_data_tmp];
  SWC_VC_B.fyp_data[0] = yy_data[fxp_data_tmp];
  do {
    exitg1 = 0;
    qY = (uint32_T)idx_end - /*MW:OvSatOk*/ idx_begin;
    if (qY > idx_end) {
      qY = 0U;
    }

    e_i = (int32_T)(qY + 1U);
    if ((uint32_T)e_i > 255U) {
      e_i = 255;
    }

    if (j < e_i) {
      e_i = (int32_T)((uint32_T)idx_begin + j);
      fxp_data_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_data_tmp_0 = 255;
      }

      fxp_data_tmp = i - 1;
      a = xx_data[fxp_data_tmp_0 - 2] - SWC_VC_B.fxp_data[fxp_data_tmp];
      fxp_data_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_data_tmp_0 = 255;
      }

      b_a = yy_data[fxp_data_tmp_0 - 2] - SWC_VC_B.fyp_data[fxp_data_tmp];
      if (sqrtf(a * a + b_a * b_a) > delta_s) {
        fxp_data_tmp_0 = (int32_T)(i + 1U);
        if ((uint32_T)fxp_data_tmp_0 > 255U) {
          fxp_data_tmp_0 = 255;
        }

        i = (uint8_T)fxp_data_tmp_0;
        tmp = e_i;
        if ((uint32_T)e_i > 255U) {
          tmp = 255;
          e_i = 255;
        }

        fxp_data_tmp = (uint8_T)fxp_data_tmp_0 - 1;
        SWC_VC_B.fxp_data[fxp_data_tmp] = xx_data[tmp - 2];
        SWC_VC_B.fyp_data[fxp_data_tmp] = yy_data[e_i - 2];
      }

      j++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  e_i = (int32_T)(i + 1U);
  if ((uint32_T)e_i > 255U) {
    e_i = 255;
  }

  fxp_data_tmp = idx_end - 1;
  fxp_data_tmp_0 = (uint8_T)e_i - 1;
  SWC_VC_B.fxp_data[fxp_data_tmp_0] = xx_data[fxp_data_tmp];
  SWC_VC_B.fyp_data[fxp_data_tmp_0] = yy_data[fxp_data_tmp];
  *total_num_idx = (uint8_T)e_i;
  if (Kf < 1.0F) {
    for (fxp_data_tmp = 0; fxp_data_tmp <= fxp_data_tmp_0; fxp_data_tmp++) {
      SWC_VC_B.xf1_data[fxp_data_tmp] = SWC_VC_B.fxp_data[fxp_data_tmp];
      SWC_VC_B.xf2_data[fxp_data_tmp] = SWC_VC_B.fxp_data[fxp_data_tmp];
      SWC_VC_B.yf1_data[fxp_data_tmp] = SWC_VC_B.fyp_data[fxp_data_tmp];
      SWC_VC_B.yf2_data[fxp_data_tmp] = SWC_VC_B.fyp_data[fxp_data_tmp];
    }

    for (fxp_data_tmp = 1; fxp_data_tmp - 1 <= (uint8_T)e_i - 3; fxp_data_tmp++)
    {
      SWC_VC_B.xf1_data[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf1_data[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fxp_data[fxp_data_tmp];
      SWC_VC_B.yf1_data[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf1_data[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fyp_data[fxp_data_tmp];
      SWC_VC_B.xf2_data[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf2_data[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.xf1_data[fxp_data_tmp];
      SWC_VC_B.yf2_data[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf2_data[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.yf1_data[fxp_data_tmp];
    }

    memcpy(&SWC_VC_B.fxp_data[0], &SWC_VC_B.xf2_data[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fyp_data[0], &SWC_VC_B.yf2_data[0], 250U * sizeof(real32_T));
    i = (uint8_T)fxp_data_tmp_0;
    while (i > 1) {
      e_i = i - 1;
      SWC_VC_B.xf1_data[e_i] = (1.0F - Kf) * SWC_VC_B.xf1_data[i] +
        SWC_VC_B.fxp_data[e_i] * Kf;
      SWC_VC_B.yf1_data[e_i] = (1.0F - Kf) * SWC_VC_B.yf1_data[i] +
        SWC_VC_B.fyp_data[e_i] * Kf;
      SWC_VC_B.xf2_data[e_i] = (1.0F - Kf) * SWC_VC_B.xf2_data[i] +
        SWC_VC_B.xf1_data[e_i] * Kf;
      SWC_VC_B.yf2_data[e_i] = (1.0F - Kf) * SWC_VC_B.yf2_data[i] +
        SWC_VC_B.yf1_data[e_i] * Kf;
      i = (uint8_T)e_i;
    }

    memcpy(&SWC_VC_B.fxp_data[0], &SWC_VC_B.xf2_data[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fyp_data[0], &SWC_VC_B.yf2_data[0], 250U * sizeof(real32_T));
  }

  for (e_i = 0; e_i <= fxp_data_tmp_0; e_i++) {
    fxo_data[e_i] = SWC_VC_B.fxp_data[e_i];
    fyo_data[e_i] = SWC_VC_B.fyp_data[e_i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_renderPath_para_common(const real32_T pii[30], const real32_T
  ps[8], int8_T regen_dir, const sKLkrkTJ3gZMTxjPMClazsD_SWC_VC_T *plan_params,
  const s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T veh_params, real32_T fxo_data[], int32_T
  *fxo_size, real32_T fyo_data[], int32_T *fyo_size, real32_T fho_data[],
  int32_T *fho_size, real32_T fvo_data[], int32_T *fvo_size, real32_T fso_data[],
  int32_T *fso_size, int16_T fio[10], int8_T *co)
{
  boolean_T no_str_flag;
  uint8_T n_segment_tail;
  uint8_T total_num_idx_12;
  uint8_T sweep_count;
  int8_T gear_last_sweep;
  uint8_T sum_n_segment_xlast3;
  boolean_T car_in_ps;
  boolean_T car_passed_ps;
  uint8_T sum_n_segment;
  uint8_T while_step;
  uint8_T data_point_idx;
  boolean_T run_once;
  boolean_T run_twice;
  int8_T direction_flag_W2;
  int16_T sum_indx_sweeps;
  uint8_T e;
  uint16_T cc_i;
  int16_T varargin_1;
  boolean_T guard1 = false;
  int32_T exitg1;
  int32_T exitg2;
  SWC_VC_B.pps[0] = ps[0];
  SWC_VC_B.pps[1] = ps[1];
  SWC_VC_B.pps[2] = ps[2];
  SWC_VC_B.pps[3] = ps[3];
  SWC_VC_B.pps[4] = ps[4];
  SWC_VC_B.pps[5] = ps[5];
  SWC_VC_B.pps[6] = ps[6];
  SWC_VC_B.pps[7] = ps[7];
  *co = 1;
  no_str_flag = false;
  SWC_VC_B.init_wheel_angle_h = pii[29];
  for (SWC_VC_B.i_p = 0; SWC_VC_B.i_p < 10; SWC_VC_B.i_p++) {
    SWC_VC_B.pp_tmp_n = SWC_VC_B.i_p << 1;
    SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] = pii[SWC_VC_B.i_p];
    SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n + 1] = pii[SWC_VC_B.i_p + 10];
    SWC_VC_B.Phi_guideline_c[SWC_VC_B.i_p] = pii[SWC_VC_B.i_p + 20];
    SWC_VC_B.n_segment_i[SWC_VC_B.i_p] = 50U;
    fio[SWC_VC_B.i_p] = 0;
  }

  SWC_VC_B.rear_X = ps[6] - veh_params.Ke_AP_I_VehRearOverhang;
  SWC_VC_B.front_X = (ps[0] + veh_params.Ke_AP_I_VehFrontOverhang) +
    veh_params.Ke_AP_I_VehWheelbase;
  SWC_VC_B.final_point_idx_0 = SWC_VC_B.pp_m[18];
  SWC_VC_B.PS_play_room = SWC_VC_B.rear_X - SWC_VC_B.front_X;
  car_in_ps = false;
  if (SWC_VC_B.pp_m[0] >= SWC_VC_B.front_X - 0.2F) {
    car_in_ps = (SWC_VC_B.pp_m[0] <= SWC_VC_B.rear_X + 0.2F);
  }

  car_passed_ps = false;
  if (SWC_VC_B.pp_m[0] >= ps[0]) {
    car_passed_ps = (SWC_VC_B.pp_m[0] < ps[6]);
  }

  if (!plan_params->park_out) {
    if (!car_in_ps) {
      SWC_VC_B.temp = ps[6] - ps[0];
      if (SWC_VC_B.temp < plan_params->PS_size_para[0]) {
        sweep_count = 6U;
        gear_last_sweep = 1;
        SWC_VC_B.PS_play_room_max = plan_params->PS_size_para[0] -
          ((veh_params.Ke_AP_I_VehFrontOverhang +
            veh_params.Ke_AP_I_VehWheelbase) +
           veh_params.Ke_AP_I_VehRearOverhang);
      } else if (SWC_VC_B.temp < plan_params->PS_size_para[1]) {
        sweep_count = 5U;
        gear_last_sweep = -1;
        SWC_VC_B.PS_play_room_max = plan_params->PS_size_para[1] -
          ((veh_params.Ke_AP_I_VehFrontOverhang +
            veh_params.Ke_AP_I_VehWheelbase) +
           veh_params.Ke_AP_I_VehRearOverhang);
      } else if (SWC_VC_B.temp < plan_params->PS_size_para[2]) {
        sweep_count = 4U;
        gear_last_sweep = 1;
        SWC_VC_B.PS_play_room_max = plan_params->PS_size_para[2] -
          ((veh_params.Ke_AP_I_VehFrontOverhang +
            veh_params.Ke_AP_I_VehWheelbase) +
           veh_params.Ke_AP_I_VehRearOverhang);
      } else if (SWC_VC_B.temp < plan_params->PS_size_para[3]) {
        sweep_count = 3U;
        gear_last_sweep = -1;
        SWC_VC_B.PS_play_room_max = plan_params->PS_size_para[3] -
          ((veh_params.Ke_AP_I_VehFrontOverhang +
            veh_params.Ke_AP_I_VehWheelbase) +
           veh_params.Ke_AP_I_VehRearOverhang);
      } else {
        sweep_count = 2U;
        gear_last_sweep = 1;
      }

      SWC_VC_B.pp_m[14] = SWC_VC_B.pp_m[18];
      SWC_VC_B.pp_m[15] = SWC_VC_B.pp_m[19];
      SWC_VC_B.Phi_guideline_c[7] = -180.0F;
      switch (gear_last_sweep) {
       case 1:
        SWC_VC_B.pp_m[12] = SWC_VC_B.rear_X;
        SWC_VC_B.pp_m[13] = SWC_VC_B.pp_m[19];
        break;

       case -1:
        SWC_VC_B.pp_m[12] = SWC_VC_B.front_X;
        SWC_VC_B.pp_m[13] = SWC_VC_B.pp_m[19];
        break;
      }

      SWC_VC_B.Phi_guideline_c[6] = -180.0F;
      SWC_VC_B.X[0] = SWC_VC_B.pp_m[14] - SWC_VC_B.pp_m[12];
      SWC_VC_B.X[1] = SWC_VC_B.pp_m[19] - SWC_VC_B.pp_m[13];
      SWC_VC_B.final_point_idx_0 = norm_5ISqY4yY(SWC_VC_B.X);
      if (SWC_VC_B.final_point_idx_0 <= 0.42) {
        SWC_VC_B.pp_m[14] = SWC_VC_B.X[0] / SWC_VC_B.final_point_idx_0 * 0.42F +
          SWC_VC_B.pp_m[12];
        SWC_VC_B.pp_m[15] = SWC_VC_B.X[1] / SWC_VC_B.final_point_idx_0 * 0.42F +
          SWC_VC_B.pp_m[13];
      }

      SWC_VC_B.n_segment_i[6] = plan_params->n_para;
      SWC_VC_B.b_counter = 1;
      while (SWC_VC_B.b_counter <= SWC_VC_B.n_segment_i[6]) {
        SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter - 1] = ((real32_T)
          SWC_VC_B.b_counter - 1.0F) * (SWC_VC_B.pp_m[12] - SWC_VC_B.pp_m[14]) /
          ((real32_T)SWC_VC_B.n_segment_i[6] - 1.0F) + SWC_VC_B.pp_m[14];
        SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter - 1] = ((real32_T)
          SWC_VC_B.b_counter - 1.0F) * (SWC_VC_B.pp_m[13] - SWC_VC_B.pp_m[15]) /
          ((real32_T)SWC_VC_B.n_segment_i[6] - 1.0F) + SWC_VC_B.pp_m[15];
        SWC_VC_B.b_counter++;
      }

      if (plan_params->n_para > 0) {
        SWC_VC_B.n_segment_i[6] = (uint8_T)(plan_params->n_para - 1);
        SWC_VC_B.b_counter = 0;
        while (SWC_VC_B.b_counter + 1 <= SWC_VC_B.n_segment_i[6]) {
          fxo_data[SWC_VC_B.b_counter] =
            SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter];
          fyo_data[SWC_VC_B.b_counter] =
            SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter];
          SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter] = gear_last_sweep;
          SWC_VC_B.b_counter++;
        }
      }

      fio[6] = (int16_T)(SWC_VC_B.n_segment_i[6] * gear_last_sweep);
      sum_n_segment = 0U;
      while_step = 2U;
      data_point_idx = 7U;
      while (while_step < sweep_count) {
        switch (sweep_count) {
         case 6:
          switch (while_step) {
           case 2:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_smallPS_R5;
            break;

           case 3:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_smallPS_D4;
            break;

           case 4:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_smallPS_R3;
            break;

           default:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_smallPS_D2;
            break;
          }
          break;

         case 5:
          switch (while_step) {
           case 2:
            SWC_VC_B.str_whl_ang_para = 10.0F;
            break;

           case 3:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 10.0F +
              plan_params->str_whl_ang_para_smallPS_D4;
            break;

           case 4:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 10.0F +
              plan_params->str_whl_ang_para_smallPS_R3;
            break;
          }
          break;

         case 4:
          switch (while_step) {
           case 2:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_mediumPS_R;
            break;

           case 3:
            SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
              SWC_VC_B.PS_play_room_max) * 20.0F +
              plan_params->str_whl_ang_para_mediumPS_D;
            break;
          }
          break;

         default:
          SWC_VC_B.str_whl_ang_para = (1.0F - SWC_VC_B.PS_play_room /
            SWC_VC_B.PS_play_room_max) * 10.0F +
            plan_params->str_whl_ang_para_mediumPS_R;
          break;
        }

        SWC_VC_sweep_finder_para_common(SWC_VC_B.pp_m[(data_point_idx - 1) << 1],
          SWC_VC_B.front_X * (real32_T)(gear_last_sweep == 1) + SWC_VC_B.rear_X *
          (real32_T)(gear_last_sweep == -1), SWC_VC_B.pp_m[((data_point_idx - 1)
          << 1) + 1], SWC_VC_B.Phi_guideline_c[data_point_idx - 1], SWC_VC_B.pps,
          SWC_VC_B.str_whl_ang_para, (int8_T)-gear_last_sweep,
          plan_params->park_out, plan_params->ang_threshold_regen,
          plan_params->aux_turn_para_regen, plan_params->curb_over_Y_dir_para,
          plan_params->delta_s_para, veh_params.Ke_AP_I_VehFrontOverhang,
          veh_params.Ke_AP_I_VehWheelbase, veh_params.Ke_AP_I_VehWidth,
          veh_params.Ke_AP_I_VehRearOverhang, SWC_VC_B.output_data,
          SWC_VC_B.x_out_bz_size);
        memcpy(&SWC_VC_B.x_out_data_l[0], &SWC_VC_B.output_data[0], 50U * sizeof
               (real32_T));
        memcpy(&SWC_VC_B.y_out_data_h[0], &SWC_VC_B.output_data[50], 50U *
               sizeof(real32_T));
        SWC_VC_B.qY_tmp_c = data_point_idx - /*MW:OvSatOk*/ 1U;
        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.pp_m[((int32_T)SWC_VC_B.qY_p - 1) << 1] = SWC_VC_B.output_data
          [100];
        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.pp_m[(((int32_T)SWC_VC_B.qY_p - 1) << 1) + 1] =
          SWC_VC_B.output_data[101];
        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.Phi_guideline_c[(int32_T)SWC_VC_B.qY_p - 1] =
          SWC_VC_B.output_data[102];
        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.temp = roundf(SWC_VC_B.output_data[103]);
        if (SWC_VC_B.temp < 256.0F) {
          if (SWC_VC_B.temp >= 0.0F) {
            SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1] = (uint8_T)
              SWC_VC_B.temp;
          } else {
            SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1] = 0U;
          }
        } else {
          SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1] = MAX_uint8_T;
        }

        SWC_VC_B.b_counter = (int32_T)((uint32_T)
          SWC_VC_B.n_segment_i[data_point_idx - 1] + sum_n_segment);
        if ((uint32_T)SWC_VC_B.b_counter > 255U) {
          SWC_VC_B.b_counter = 255;
        }

        sum_n_segment = (uint8_T)SWC_VC_B.b_counter;
        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        if (SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1] > 0) {
          SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
          if (SWC_VC_B.qY_tmp_c > data_point_idx) {
            SWC_VC_B.qY_p = 0U;
          }

          SWC_VC_B.qY_mx = SWC_VC_B.qY_tmp_c;
          if (SWC_VC_B.qY_tmp_c > data_point_idx) {
            SWC_VC_B.qY_mx = 0U;
          }

          SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_mx -
            1];
          SWC_VC_B.qY_mx = SWC_VC_B.P0_idx_0_tmp - /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_mx > (uint32_T)SWC_VC_B.P0_idx_0_tmp) {
            SWC_VC_B.qY_mx = 0U;
          }

          SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1] = (uint8_T)
            SWC_VC_B.qY_mx;
          SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
          if (SWC_VC_B.qY_tmp_c > data_point_idx) {
            SWC_VC_B.qY_p = 0U;
          }

          e = SWC_VC_B.n_segment_i[(int32_T)SWC_VC_B.qY_p - 1];
          SWC_VC_B.i_p = 1;
          while (SWC_VC_B.i_p - 1 <= e - 1) {
            SWC_VC_B.park_out_segment = (int32_T)((uint32_T)(uint8_T)
              SWC_VC_B.b_counter + (uint8_T)SWC_VC_B.i_p);
            SWC_VC_B.fxo_data_tmp = SWC_VC_B.park_out_segment;
            if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
              SWC_VC_B.fxo_data_tmp = 255;
            }

            fxo_data[SWC_VC_B.fxo_data_tmp - 1] = SWC_VC_B.output_data[(uint8_T)
              SWC_VC_B.i_p - 1];
            SWC_VC_B.fxo_data_tmp = SWC_VC_B.park_out_segment;
            if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
              SWC_VC_B.fxo_data_tmp = 255;
              SWC_VC_B.park_out_segment = 255;
            }

            fyo_data[SWC_VC_B.fxo_data_tmp - 1] = SWC_VC_B.output_data[(uint8_T)
              SWC_VC_B.i_p + 49];
            SWC_VC_B.fgo_data_b[SWC_VC_B.park_out_segment - 1] = (int8_T)
              -gear_last_sweep;
            SWC_VC_B.i_p++;
          }
        }

        SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.qY_mx = SWC_VC_B.qY_tmp_c;
        if (SWC_VC_B.qY_tmp_c > data_point_idx) {
          SWC_VC_B.qY_mx = 0U;
          SWC_VC_B.qY_tmp_c = 0U;
        }

        fio[(int32_T)SWC_VC_B.qY_p - 1] = (int16_T)(SWC_VC_B.n_segment_i
          [(int32_T)SWC_VC_B.qY_mx - 1] * -gear_last_sweep);
        data_point_idx = (uint8_T)SWC_VC_B.qY_tmp_c;
        while_step++;
        gear_last_sweep = (int8_T)-gear_last_sweep;
      }

      while (data_point_idx > 3) {
        SWC_VC_B.b_counter = data_point_idx - 1;
        SWC_VC_B.park_out_segment = SWC_VC_B.b_counter << 1;
        SWC_VC_B.final_point_idx_0 = SWC_VC_B.pp_m[SWC_VC_B.park_out_segment + 1];
        SWC_VC_B.i_p = data_point_idx - 2;
        SWC_VC_B.pp_tmp_n = SWC_VC_B.i_p << 1;
        SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] =
          SWC_VC_B.pp_m[SWC_VC_B.park_out_segment];
        SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n + 1] = SWC_VC_B.final_point_idx_0;
        SWC_VC_B.Phi_guideline_c[SWC_VC_B.i_p] =
          SWC_VC_B.Phi_guideline_c[SWC_VC_B.b_counter];
        SWC_VC_B.n_segment_i[SWC_VC_B.i_p] = 0U;
        data_point_idx = (uint8_T)SWC_VC_B.b_counter;
      }

      run_once = true;
      run_twice = false;
      sum_n_segment = plan_params->num_points_no_str_para;
      while (run_once || run_twice) {
        run_once = false;
        if (!car_passed_ps) {
          SWC_VC_B.temp = SWC_VC_B.pps[6] - SWC_VC_B.pps[0];
          if (SWC_VC_B.temp >= plan_params->PS_size_para[3]) {
            SWC_VC_B.x_out_data_l[0] = 0.0F;
            SWC_VC_B.y_out_data_h[0] = 0.0F;
            SWC_VC_B.alpha_clothoid_old_m = 0.0F;
            SWC_VC_B.final_point_idx_0 = 0.0F;
            SWC_VC_B.pp_tail_idx_0 = floorf((SWC_VC_B.temp -
              plan_params->PS_size_para[3]) / plan_params->delta_s_clothoid_para)
              - 2.0F;
            SWC_VC_B.i_p = 0;
            while (SWC_VC_B.i_p <= (int32_T)SWC_VC_B.pp_tail_idx_0 - 1) {
              SWC_VC_B.final_point_idx_0++;
              SWC_VC_B.park_out_segment = (int32_T)SWC_VC_B.final_point_idx_0 -
                1;
              SWC_VC_B.b_counter = (int32_T)(SWC_VC_B.final_point_idx_0 + 1.0F)
                - 1;
              SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter] =
                SWC_VC_B.x_out_data_l[SWC_VC_B.park_out_segment] +
                plan_params->delta_s_clothoid_para;
              SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter] =
                SWC_VC_B.y_out_data_h[SWC_VC_B.park_out_segment];
              SWC_VC_B.i_p++;
            }

            for (SWC_VC_B.i_p = 0; SWC_VC_B.i_p < 33; SWC_VC_B.i_p++) {
              SWC_VC_B.alpha_clothoid_m = plan_params->
                str_profile_bigPS[SWC_VC_B.i_p + 1];
              tand_brbYAlcS(&SWC_VC_B.alpha_clothoid_m);
              SWC_VC_B.alpha_clothoid_m = (SWC_VC_B.alpha_clothoid_m *
                plan_params->delta_s_clothoid_para /
                veh_params.Ke_AP_I_VehWheelbase + SWC_VC_B.alpha_clothoid_old_m *
                3.14159274F / 180.0F) * 180.0F / 3.14159274F;
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
              cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old_m);
              SWC_VC_B.pp_tail_idx_0 = ((real32_T)SWC_VC_B.i_p + 2.0F) +
                SWC_VC_B.final_point_idx_0;
              SWC_VC_B.park_out_segment = (int32_T)(SWC_VC_B.pp_tail_idx_0 -
                1.0F) - 1;
              SWC_VC_B.b_counter = (int32_T)SWC_VC_B.pp_tail_idx_0 - 1;
              SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter] =
                SWC_VC_B.x_out_data_l[SWC_VC_B.park_out_segment] +
                plan_params->delta_s_clothoid_para *
                SWC_VC_B.alpha_clothoid_old_m;
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
              sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_old_m);
              SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter] =
                SWC_VC_B.y_out_data_h[SWC_VC_B.park_out_segment] +
                plan_params->delta_s_clothoid_para *
                SWC_VC_B.alpha_clothoid_old_m;
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
            }

            for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 50;
                 SWC_VC_B.b_counter++) {
              SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter] =
                -SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter] + SWC_VC_B.pp_m[4];
              SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter] =
                -SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter] + SWC_VC_B.pp_m[5];
            }

            SWC_VC_B.b_counter = (int32_T)(SWC_VC_B.final_point_idx_0 + 34.0F) -
              1;
            SWC_VC_B.pp_tail_idx_0 = SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter];
            SWC_VC_B.pp_tail_idx_1 = SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter];
            SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m + -180.0F;
            if (SWC_VC_B.final_point_idx_0 < 256.0F) {
              n_segment_tail = (uint8_T)SWC_VC_B.final_point_idx_0;
            } else {
              n_segment_tail = MAX_uint8_T;
            }

            SWC_VC_B.b_counter = (int32_T)(n_segment_tail + 34U);
            if ((uint32_T)SWC_VC_B.b_counter > 255U) {
              SWC_VC_B.b_counter = 255;
            }

            n_segment_tail = (uint8_T)(SWC_VC_B.b_counter - 1);
          } else {
            if (SWC_VC_B.temp < plan_params->PS_size_para[3]) {
              if ((SWC_VC_B.temp > plan_params->PS_size_para[1]) &&
                  (SWC_VC_B.temp < plan_params->PS_size_para[3])) {
                SWC_VC_B.alpha_clothoid_old_m = fmaxf(1.0F, ceilf((-140.0F -
                  SWC_VC_B.Phi_guideline_c[2]) / 2.0F));
                if (SWC_VC_B.alpha_clothoid_old_m < 256.0F) {
                  n_segment_tail = (uint8_T)SWC_VC_B.alpha_clothoid_old_m;
                } else {
                  n_segment_tail = MAX_uint8_T;
                }

                SWC_VC_B.b_counter = (int32_T)((uint32_T)n_segment_tail +
                  plan_params->num_clothoid_waypoints_para_mediumPS);
                if ((uint32_T)SWC_VC_B.b_counter > 255U) {
                  SWC_VC_B.b_counter = 255;
                }

                n_segment_tail = (uint8_T)SWC_VC_B.b_counter;
                SWC_VC_B.park_out_segment = 0;
                while (SWC_VC_B.park_out_segment <= (int32_T)
                       (SWC_VC_B.alpha_clothoid_old_m + 1.0F) - 1) {
                  SWC_VC_B.str_profile_data[(int32_T)((real32_T)
                    SWC_VC_B.park_out_segment + 1.0F) - 1] =
                    plan_params->str_whl_ang_para_mediumPS_R_tail;
                  SWC_VC_B.park_out_segment++;
                }

                if (SWC_VC_B.alpha_clothoid_old_m + 2.0F < 256.0F) {
                  total_num_idx_12 = (uint8_T)(SWC_VC_B.alpha_clothoid_old_m +
                    2.0F);
                } else {
                  total_num_idx_12 = MAX_uint8_T;
                }

                while (total_num_idx_12 <= (uint8_T)SWC_VC_B.b_counter) {
                  SWC_VC_B.qY_p = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
                  if (SWC_VC_B.qY_p > total_num_idx_12) {
                    SWC_VC_B.qY_p = 0U;
                  }

                  SWC_VC_B.qY_mx =
                    plan_params->num_clothoid_waypoints_para_mediumPS -
                    /*MW:OvSatOk*/ 1U;
                  if (SWC_VC_B.qY_mx >
                      plan_params->num_clothoid_waypoints_para_mediumPS) {
                    SWC_VC_B.qY_mx = 0U;
                  }

                  SWC_VC_B.str_profile_data[total_num_idx_12 - 1] =
                    SWC_VC_B.str_profile_data[(int32_T)SWC_VC_B.qY_p - 1] -
                    plan_params->str_whl_ang_para_mediumPS_R_tail / (real32_T)
                    (int32_T)SWC_VC_B.qY_mx;
                  total_num_idx_12++;
                }
              } else {
                if (SWC_VC_B.temp <= plan_params->PS_size_para[1]) {
                  SWC_VC_B.alpha_clothoid_old_m = fmaxf(1.0F, ceilf((-145.0F -
                    SWC_VC_B.Phi_guideline_c[2]) / 2.0F));
                  if (SWC_VC_B.alpha_clothoid_old_m < 256.0F) {
                    n_segment_tail = (uint8_T)SWC_VC_B.alpha_clothoid_old_m;
                  } else {
                    n_segment_tail = MAX_uint8_T;
                  }

                  SWC_VC_B.b_counter = (int32_T)((uint32_T)n_segment_tail +
                    plan_params->num_clothoid_waypoints_para_smallPS);
                  if ((uint32_T)SWC_VC_B.b_counter > 255U) {
                    SWC_VC_B.b_counter = 255;
                  }

                  n_segment_tail = (uint8_T)SWC_VC_B.b_counter;
                  SWC_VC_B.park_out_segment = 0;
                  while (SWC_VC_B.park_out_segment <= (int32_T)
                         (SWC_VC_B.alpha_clothoid_old_m + 1.0F) - 1) {
                    SWC_VC_B.str_profile_data[(int32_T)((real32_T)
                      SWC_VC_B.park_out_segment + 1.0F) - 1] =
                      plan_params->str_whl_ang_para_smallPS_R_tail;
                    SWC_VC_B.park_out_segment++;
                  }

                  if (SWC_VC_B.alpha_clothoid_old_m + 2.0F < 256.0F) {
                    total_num_idx_12 = (uint8_T)(SWC_VC_B.alpha_clothoid_old_m +
                      2.0F);
                  } else {
                    total_num_idx_12 = MAX_uint8_T;
                  }

                  while (total_num_idx_12 <= (uint8_T)SWC_VC_B.b_counter) {
                    SWC_VC_B.qY_p = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
                    if (SWC_VC_B.qY_p > total_num_idx_12) {
                      SWC_VC_B.qY_p = 0U;
                    }

                    SWC_VC_B.qY_mx =
                      plan_params->num_clothoid_waypoints_para_smallPS -
                      /*MW:OvSatOk*/ 1U;
                    if (SWC_VC_B.qY_mx >
                        plan_params->num_clothoid_waypoints_para_smallPS) {
                      SWC_VC_B.qY_mx = 0U;
                    }

                    SWC_VC_B.str_profile_data[total_num_idx_12 - 1] =
                      SWC_VC_B.str_profile_data[(int32_T)SWC_VC_B.qY_p - 1] -
                      plan_params->str_whl_ang_para_smallPS_R_tail / (real32_T)
                      (int32_T)SWC_VC_B.qY_mx;
                    total_num_idx_12++;
                  }
                }
              }

              SWC_VC_B.x_out_data_l[0] = 0.0F;
              SWC_VC_B.y_out_data_h[0] = 0.0F;
              SWC_VC_B.alpha_clothoid_old_m = 0.0F;
              SWC_VC_B.b_counter = 0;
              while (SWC_VC_B.b_counter <= n_segment_tail - 2) {
                SWC_VC_B.alpha_clothoid_m =
                  SWC_VC_B.str_profile_data[SWC_VC_B.b_counter + 1];
                tand_brbYAlcS(&SWC_VC_B.alpha_clothoid_m);
                SWC_VC_B.alpha_clothoid_m = (SWC_VC_B.alpha_clothoid_m *
                  plan_params->delta_s_clothoid_para /
                  veh_params.Ke_AP_I_VehWheelbase +
                  SWC_VC_B.alpha_clothoid_old_m * 3.14159274F / 180.0F) * 180.0F
                  / 3.14159274F;
                SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
                cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old_m);
                SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter + 1] =
                  plan_params->delta_s_clothoid_para *
                  SWC_VC_B.alpha_clothoid_old_m +
                  SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter];
                SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
                sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_old_m);
                SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter + 1] =
                  plan_params->delta_s_clothoid_para *
                  SWC_VC_B.alpha_clothoid_old_m +
                  SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter];
                SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m;
                SWC_VC_B.b_counter++;
              }

              for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 50;
                   SWC_VC_B.b_counter++) {
                SWC_VC_B.park_out_segment = SWC_VC_B.b_counter << 1;
                SWC_VC_B.result_data[SWC_VC_B.park_out_segment] =
                  SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter];
                SWC_VC_B.result_data[SWC_VC_B.park_out_segment + 1] =
                  SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter];
              }

              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.Phi_guideline_c[2];
              cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old_m);
              SWC_VC_B.pp_tail_idx_0 = SWC_VC_B.Phi_guideline_c[2];
              sind_7is3Ljjc(&SWC_VC_B.pp_tail_idx_0);
              SWC_VC_B.pp_tail_idx_1 = SWC_VC_B.Phi_guideline_c[2];
              sind_7is3Ljjc(&SWC_VC_B.pp_tail_idx_1);
              SWC_VC_B.final_point_idx_0 = SWC_VC_B.Phi_guideline_c[2];
              cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
              for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 50;
                   SWC_VC_B.b_counter++) {
                SWC_VC_B.park_out_segment = SWC_VC_B.b_counter << 1;
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment] = 0.0F;
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment + 1] =
                  0.0F;
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment] +=
                  SWC_VC_B.result_data[SWC_VC_B.park_out_segment] *
                  SWC_VC_B.alpha_clothoid_old_m;
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment + 1] +=
                  SWC_VC_B.result_data[SWC_VC_B.park_out_segment] *
                  SWC_VC_B.pp_tail_idx_1;
                SWC_VC_B.temp = SWC_VC_B.result_data[SWC_VC_B.park_out_segment +
                  1];
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment] +=
                  SWC_VC_B.temp * -SWC_VC_B.pp_tail_idx_0;
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment + 1] +=
                  SWC_VC_B.temp * SWC_VC_B.final_point_idx_0;
              }

              for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 2;
                   SWC_VC_B.b_counter++) {
                for (SWC_VC_B.park_out_segment = 0; SWC_VC_B.park_out_segment <
                     50; SWC_VC_B.park_out_segment++) {
                  SWC_VC_B.i_p = (SWC_VC_B.park_out_segment << 1) +
                    SWC_VC_B.b_counter;
                  SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.i_p] +=
                    SWC_VC_B.pp_m[SWC_VC_B.b_counter + 4];
                }
              }

              for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 50;
                   SWC_VC_B.b_counter++) {
                SWC_VC_B.park_out_segment = SWC_VC_B.b_counter << 1;
                SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter] =
                  SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment];
                SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter] =
                  SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.park_out_segment + 1];
              }

              SWC_VC_B.b_counter = (n_segment_tail - 1) << 1;
              SWC_VC_B.pp_tail_idx_0 =
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.b_counter];
              SWC_VC_B.pp_tail_idx_1 =
                SWC_VC_B.xy_out_clothoid_data[SWC_VC_B.b_counter + 1];
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.alpha_clothoid_m +
                SWC_VC_B.Phi_guideline_c[2];
              SWC_VC_B.qY_p = n_segment_tail - /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > n_segment_tail) {
                SWC_VC_B.qY_p = 0U;
              }

              n_segment_tail = (uint8_T)SWC_VC_B.qY_p;
            }
          }
        } else {
          SWC_VC_B.pp_m[2] = SWC_VC_B.pp_m[0];
          SWC_VC_B.pp_m[3] = SWC_VC_B.pp_m[1];
          SWC_VC_B.Phi_guideline_c[1] = SWC_VC_B.Phi_guideline_c[0];
          n_segment_tail = 0U;
          SWC_VC_B.pp_tail_idx_0 = SWC_VC_B.pp_m[4];
          SWC_VC_B.pp_tail_idx_1 = SWC_VC_B.pp_m[5];
          SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.Phi_guideline_c[2];
        }

        no_str_flag = true;
        while (no_str_flag) {
          no_str_flag = false;
          SWC_VC_B.extremum = SWC_VC_B.pp_m[2] - SWC_VC_B.pp_tail_idx_0;
          SWC_VC_B.temp = SWC_VC_B.pp_m[3] - SWC_VC_B.pp_tail_idx_1;
          SWC_VC_B.final_point_idx_0 = SWC_VC_B.alpha_clothoid_old_m;
          cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
          SWC_VC_B.PS_play_room = SWC_VC_B.alpha_clothoid_old_m;
          sind_7is3Ljjc(&SWC_VC_B.PS_play_room);
          if (SWC_VC_B.extremum * SWC_VC_B.final_point_idx_0 + SWC_VC_B.temp *
              SWC_VC_B.PS_play_room >= 0.0F) {
            gear_last_sweep = 1;
          } else {
            gear_last_sweep = -1;
          }

          SWC_VC_B.final_point_idx_0 = SWC_VC_B.Phi_guideline_c[1];
          cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
          SWC_VC_B.PS_play_room = SWC_VC_B.Phi_guideline_c[1];
          sind_7is3Ljjc(&SWC_VC_B.PS_play_room);
          if (SWC_VC_B.extremum * SWC_VC_B.final_point_idx_0 + SWC_VC_B.temp *
              SWC_VC_B.PS_play_room >= 0.0F) {
            direction_flag_W2 = 1;
          } else {
            direction_flag_W2 = -1;
          }

          SWC_VC_B.PS_play_room = fmaxf(fabsf(SWC_VC_B.extremum), fabsf
            (SWC_VC_B.temp)) * plan_params->vecLen_coeff_para;
          SWC_VC_B.final_point_idx_0 = SWC_VC_B.alpha_clothoid_old_m;
          cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
          SWC_VC_B.PS_play_room_max = SWC_VC_B.alpha_clothoid_old_m;
          sind_7is3Ljjc(&SWC_VC_B.PS_play_room_max);
          SWC_VC_B.X[0] = SWC_VC_B.PS_play_room * SWC_VC_B.final_point_idx_0;
          SWC_VC_B.X[1] = SWC_VC_B.PS_play_room * SWC_VC_B.PS_play_room_max;
          if (!car_passed_ps) {
            SWC_VC_B.X[0] *= 0.74F;
            SWC_VC_B.X[1] *= 0.74F;
          }

          SWC_VC_B.X[0] *= (real32_T)gear_last_sweep;
          SWC_VC_B.X[1] *= (real32_T)gear_last_sweep;
          SWC_VC_B.final_point_idx_0 = SWC_VC_B.Phi_guideline_c[1];
          cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
          SWC_VC_B.PS_play_room_max = SWC_VC_B.Phi_guideline_c[1];
          sind_7is3Ljjc(&SWC_VC_B.PS_play_room_max);
          SWC_VC_B.final_point_idx_0 = SWC_VC_B.PS_play_room *
            SWC_VC_B.final_point_idx_0 * (real32_T)direction_flag_W2;
          SWC_VC_B.PS_play_room = SWC_VC_B.PS_play_room *
            SWC_VC_B.PS_play_room_max * (real32_T)direction_flag_W2;
          SWC_VC_B.Y[0] = SWC_VC_B.extremum;
          SWC_VC_B.X_c[0] = SWC_VC_B.X[0];
          SWC_VC_B.P3_f[0] = (SWC_VC_B.extremum - SWC_VC_B.X[0]) -
            SWC_VC_B.final_point_idx_0;
          SWC_VC_B.final_point[0] = SWC_VC_B.final_point_idx_0;
          SWC_VC_B.Y[1] = SWC_VC_B.temp;
          SWC_VC_B.X_c[1] = SWC_VC_B.X[1];
          SWC_VC_B.P3_f[1] = (SWC_VC_B.temp - SWC_VC_B.X[1]) -
            SWC_VC_B.PS_play_room;
          SWC_VC_B.final_point[1] = SWC_VC_B.PS_play_room;
          SWC_VC_B.temp = floorf(norm_5ISqY4yY(SWC_VC_B.Y) /
            plan_params->delta_s_para);
          if (SWC_VC_B.temp < 256.0F) {
            if (SWC_VC_B.temp >= 0.0F) {
              while_step = (uint8_T)SWC_VC_B.temp;
            } else {
              while_step = 0U;
            }
          } else {
            while_step = MAX_uint8_T;
          }

          SWC_VC_Bezier_path_function_common(SWC_VC_B.X_c, SWC_VC_B.P3_f,
            SWC_VC_B.final_point, while_step, &SWC_VC_B.extremum,
            SWC_VC_B.x_out_bz_data, SWC_VC_B.x_out_bz_size,
            SWC_VC_B.y_out_bz_data, SWC_VC_B.y_out_bz_size,
            &SWC_VC_B.n_segment_i[1]);
          SWC_VC_B.b_counter = 0;
          while (SWC_VC_B.b_counter <= SWC_VC_B.n_segment_i[1] - 1) {
            SWC_VC_B.x_out_bz_data[SWC_VC_B.b_counter] += SWC_VC_B.pp_tail_idx_0;
            SWC_VC_B.y_out_bz_data[SWC_VC_B.b_counter] += SWC_VC_B.pp_tail_idx_1;
            SWC_VC_B.b_counter++;
          }

          if ((SWC_VC_B.extremum > plan_params->maxCurvature) && (SWC_VC_B.pps[0]
               + plan_params->break_point_para[0] != SWC_VC_B.pp_m[2]) &&
              (SWC_VC_B.pps[1] + plan_params->break_point_para[1] !=
               SWC_VC_B.pp_m[3]) && ((SWC_VC_B.pp_m[0] != SWC_VC_B.pp_m[2]) ||
               (SWC_VC_B.pp_m[1] != SWC_VC_B.pp_m[3]))) {
            no_str_flag = true;
            SWC_VC_B.pp_m[2] = fmaxf(SWC_VC_B.pp_m[0], SWC_VC_B.pp_m[2] +
              plan_params->para_control_point_2_x_step_m);
            SWC_VC_B.X_c[0] = SWC_VC_B.pp_m[0] - SWC_VC_B.pp_m[2];
            SWC_VC_B.X_c[1] = SWC_VC_B.pp_m[1] - SWC_VC_B.pp_m[3];
            SWC_VC_B.temp = roundf(norm_5ISqY4yY(SWC_VC_B.X_c) /
              plan_params->delta_s_no_str_para);
            if (SWC_VC_B.temp < 256.0F) {
              if (SWC_VC_B.temp >= 0.0F) {
                sum_n_segment = (uint8_T)SWC_VC_B.temp;
              } else {
                sum_n_segment = 0U;
              }
            } else {
              sum_n_segment = MAX_uint8_T;
            }
          }
        }

        if ((SWC_VC_B.extremum > plan_params->maxCurvature) &&
            (!(plan_params->regen_mode != 0.0F))) {
          *co = -12;
        }

        SWC_VC_B.b_counter = 0;
        while (SWC_VC_B.b_counter <= n_segment_tail - 1) {
          fxo_data[sum_tAhCUalH(&SWC_VC_B.n_segment_i[2]) + SWC_VC_B.b_counter] =
            SWC_VC_B.x_out_data_l[SWC_VC_B.b_counter];
          fyo_data[sum_tAhCUalH(&SWC_VC_B.n_segment_i[2]) + SWC_VC_B.b_counter] =
            SWC_VC_B.y_out_data_h[SWC_VC_B.b_counter];
          SWC_VC_B.b_counter++;
        }

        if (SWC_VC_B.n_segment_i[1] > 0) {
          if (SWC_VC_B.pp_m[0] != SWC_VC_B.pp_m[2]) {
            SWC_VC_B.n_segment_i[1]--;
          } else {
            if (SWC_VC_B.pp_m[1] != SWC_VC_B.pp_m[3]) {
              SWC_VC_B.n_segment_i[1]--;
            }
          }

          SWC_VC_B.b_counter = 0;
          while (SWC_VC_B.b_counter <= SWC_VC_B.n_segment_i[1] - 1) {
            fxo_data[(sum_tAhCUalH(&SWC_VC_B.n_segment_i[2]) + n_segment_tail) +
              SWC_VC_B.b_counter] = SWC_VC_B.x_out_bz_data[SWC_VC_B.b_counter];
            fyo_data[(sum_tAhCUalH(&SWC_VC_B.n_segment_i[2]) + n_segment_tail) +
              SWC_VC_B.b_counter] = SWC_VC_B.y_out_bz_data[SWC_VC_B.b_counter];
            SWC_VC_B.b_counter++;
          }

          SWC_VC_B.b_counter = (int32_T)((uint32_T)SWC_VC_B.n_segment_i[1] +
            n_segment_tail);
          if ((uint32_T)SWC_VC_B.b_counter > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          SWC_VC_B.n_segment_i[1] = (uint8_T)SWC_VC_B.b_counter;
        }

        no_str_flag = false;
        if ((SWC_VC_B.pp_m[0] != SWC_VC_B.pp_m[2]) || (SWC_VC_B.pp_m[1] !=
             SWC_VC_B.pp_m[3])) {
          no_str_flag = true;
          SWC_VC_B.park_out_segment = 0;
          do {
            exitg1 = 0;
            SWC_VC_B.b_counter = sum_n_segment - 1;
            if (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
              SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment] = 0.0F;
              SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment] = 0.0F;
              SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment] = 0.0F;
              SWC_VC_B.park_out_segment++;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          SWC_VC_B.str_profile_data[0] = SWC_VC_B.Phi_guideline_c[0] + 180.0F;
          SWC_VC_B.x_path_data_b[0] = SWC_VC_B.pp_m[0];
          SWC_VC_B.y_path_data_d[0] = SWC_VC_B.pp_m[1];
          SWC_VC_B.park_out_segment = 1;
          while (SWC_VC_B.park_out_segment - 1 <= sum_n_segment - 2) {
            SWC_VC_B.final_point_idx_0 = SWC_VC_B.init_wheel_angle_h;
            tand_brbYAlcS(&SWC_VC_B.final_point_idx_0);
            SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment] =
              (SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment - 1] *
               3.14159274F / 180.0F + -SWC_VC_B.final_point_idx_0 *
               plan_params->delta_s_no_str_para /
               veh_params.Ke_AP_I_VehWheelbase) * 180.0F / 3.14159274F;
            SWC_VC_B.final_point_idx_0 =
              SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment];
            cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
            SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment] =
              SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment - 1] -
              (-(plan_params->delta_s_no_str_para * SWC_VC_B.final_point_idx_0));
            SWC_VC_B.final_point_idx_0 =
              SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment];
            sind_7is3Ljjc(&SWC_VC_B.final_point_idx_0);
            SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment] =
              SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment - 1] -
              (-(plan_params->delta_s_no_str_para * SWC_VC_B.final_point_idx_0));
            SWC_VC_B.park_out_segment++;
          }

          memcpy(&SWC_VC_B.dummy_2_data[0], &SWC_VC_B.str_profile_data[0], 50U *
                 sizeof(real32_T));
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
            SWC_VC_B.str_profile_data[SWC_VC_B.park_out_segment] =
              SWC_VC_B.dummy_2_data[(sum_n_segment - SWC_VC_B.park_out_segment)
              - 1];
            SWC_VC_B.park_out_segment++;
          }

          memcpy(&SWC_VC_B.dummy_2_data[0], &SWC_VC_B.x_path_data_b[0], 50U *
                 sizeof(real32_T));
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
            SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment] =
              SWC_VC_B.dummy_2_data[(sum_n_segment - SWC_VC_B.park_out_segment)
              - 1];
            SWC_VC_B.park_out_segment++;
          }

          memcpy(&SWC_VC_B.dummy_2_data[0], &SWC_VC_B.y_path_data_d[0], 50U *
                 sizeof(real32_T));
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
            SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment] =
              SWC_VC_B.dummy_2_data[(sum_n_segment - SWC_VC_B.park_out_segment)
              - 1];
            SWC_VC_B.park_out_segment++;
          }

          SWC_VC_B.Y[0] = SWC_VC_B.x_path_data_b[0] - SWC_VC_B.pp_m[2];
          SWC_VC_B.Y[1] = SWC_VC_B.y_path_data_d[0] - SWC_VC_B.pp_m[3];
          if (norm_5ISqY4yY(SWC_VC_B.Y) <= 0.01) {
            SWC_VC_B.n_segment_i[0] = sum_n_segment;
            SWC_VC_B.park_out_segment = 0;
            while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
              fxo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                SWC_VC_B.park_out_segment] =
                SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment];
              fyo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                SWC_VC_B.park_out_segment] =
                SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment];
              SWC_VC_B.park_out_segment++;
            }
          } else {
            do {
              exitg1 = 0;
              SWC_VC_B.extremum = SWC_VC_B.x_path_data_b[0] - SWC_VC_B.pp_m[2];
              SWC_VC_B.temp = SWC_VC_B.y_path_data_d[0] - SWC_VC_B.pp_m[3];
              SWC_VC_B.final_point_idx_0 = SWC_VC_B.Phi_guideline_c[1];
              cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
              SWC_VC_B.PS_play_room = SWC_VC_B.Phi_guideline_c[1];
              sind_7is3Ljjc(&SWC_VC_B.PS_play_room);
              if (SWC_VC_B.extremum * SWC_VC_B.final_point_idx_0 + SWC_VC_B.temp
                  * SWC_VC_B.PS_play_room >= 0.0F) {
                gear_last_sweep = 1;
              } else {
                gear_last_sweep = -1;
              }

              SWC_VC_B.final_point_idx_0 = SWC_VC_B.str_profile_data[0] - 180.0F;
              cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
              SWC_VC_B.PS_play_room = SWC_VC_B.str_profile_data[0] - 180.0F;
              sind_7is3Ljjc(&SWC_VC_B.PS_play_room);
              if (SWC_VC_B.extremum * SWC_VC_B.final_point_idx_0 + SWC_VC_B.temp
                  * SWC_VC_B.PS_play_room >= 0.0F) {
                direction_flag_W2 = 1;
              } else {
                direction_flag_W2 = -1;
              }

              SWC_VC_B.PS_play_room = fmaxf(fabsf(SWC_VC_B.extremum), fabsf
                (SWC_VC_B.temp)) * plan_params->vecLen_coeff_para;
              SWC_VC_B.final_point_idx_0 = SWC_VC_B.Phi_guideline_c[1];
              cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
              SWC_VC_B.PS_play_room_max = SWC_VC_B.Phi_guideline_c[1];
              sind_7is3Ljjc(&SWC_VC_B.PS_play_room_max);
              SWC_VC_B.X[0] = SWC_VC_B.PS_play_room * SWC_VC_B.final_point_idx_0
                * (real32_T)gear_last_sweep;
              SWC_VC_B.X[1] = SWC_VC_B.PS_play_room * SWC_VC_B.PS_play_room_max *
                (real32_T)gear_last_sweep;
              SWC_VC_B.final_point_idx_0 = SWC_VC_B.str_profile_data[0] - 180.0F;
              cosd_KZN3FnAl(&SWC_VC_B.final_point_idx_0);
              SWC_VC_B.PS_play_room_max = SWC_VC_B.str_profile_data[0] - 180.0F;
              sind_7is3Ljjc(&SWC_VC_B.PS_play_room_max);
              SWC_VC_B.final_point_idx_0 = SWC_VC_B.PS_play_room *
                SWC_VC_B.final_point_idx_0 * (real32_T)direction_flag_W2;
              SWC_VC_B.PS_play_room = SWC_VC_B.PS_play_room *
                SWC_VC_B.PS_play_room_max * (real32_T)direction_flag_W2;
              SWC_VC_B.Y[0] = SWC_VC_B.extremum;
              SWC_VC_B.X_c[0] = SWC_VC_B.X[0];
              SWC_VC_B.P3_f[0] = (SWC_VC_B.extremum - SWC_VC_B.X[0]) -
                SWC_VC_B.final_point_idx_0;
              SWC_VC_B.final_point[0] = SWC_VC_B.final_point_idx_0;
              SWC_VC_B.Y[1] = SWC_VC_B.temp;
              SWC_VC_B.X_c[1] = SWC_VC_B.X[1];
              SWC_VC_B.P3_f[1] = (SWC_VC_B.temp - SWC_VC_B.X[1]) -
                SWC_VC_B.PS_play_room;
              SWC_VC_B.final_point[1] = SWC_VC_B.PS_play_room;
              SWC_VC_B.temp = floorf(norm_5ISqY4yY(SWC_VC_B.Y) /
                plan_params->delta_s_para);
              if (SWC_VC_B.temp < 256.0F) {
                if (SWC_VC_B.temp >= 0.0F) {
                  while_step = (uint8_T)SWC_VC_B.temp;
                } else {
                  while_step = 0U;
                }
              } else {
                while_step = MAX_uint8_T;
              }

              SWC_VC_Bezier_path_function_common(SWC_VC_B.X_c, SWC_VC_B.P3_f,
                SWC_VC_B.final_point, while_step, &SWC_VC_B.extremum,
                SWC_VC_B.x_out_bz_data, SWC_VC_B.x_out_bz_size,
                SWC_VC_B.y_out_bz_data, SWC_VC_B.y_out_bz_size,
                &SWC_VC_B.n_segment_i[0]);
              SWC_VC_B.i_p = 0;
              do {
                exitg2 = 0;
                SWC_VC_B.park_out_segment = SWC_VC_B.n_segment_i[0] - 1;
                if (SWC_VC_B.i_p <= SWC_VC_B.park_out_segment) {
                  SWC_VC_B.x_out_bz_data[SWC_VC_B.i_p] += SWC_VC_B.pp_m[2];
                  SWC_VC_B.y_out_bz_data[SWC_VC_B.i_p] += SWC_VC_B.pp_m[3];
                  SWC_VC_B.i_p++;
                } else {
                  exitg2 = 1;
                }
              } while (exitg2 == 0);

              if ((SWC_VC_B.extremum > plan_params->maxCurvature) && no_str_flag)
              {
                no_str_flag = false;
                SWC_VC_B.x_path_data_b[0] = SWC_VC_B.pp_m[0];
                SWC_VC_B.y_path_data_d[0] = SWC_VC_B.pp_m[1];
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);

            if (SWC_VC_B.extremum > plan_params->maxCurvature) {
              *co = -11;
            }

            if (no_str_flag) {
              SWC_VC_B.park_out_segment = 0;
              while (SWC_VC_B.park_out_segment <= SWC_VC_B.n_segment_i[0] - 2) {
                fxo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                  SWC_VC_B.park_out_segment] =
                  SWC_VC_B.x_out_bz_data[SWC_VC_B.park_out_segment];
                fyo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                  SWC_VC_B.park_out_segment] =
                  SWC_VC_B.y_out_bz_data[SWC_VC_B.park_out_segment];
                SWC_VC_B.park_out_segment++;
              }

              SWC_VC_B.park_out_segment = 0;
              while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
                fxo_data[(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) +
                          SWC_VC_B.park_out_segment) - 1] =
                  SWC_VC_B.x_path_data_b[SWC_VC_B.park_out_segment];
                fyo_data[(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) +
                          SWC_VC_B.park_out_segment) - 1] =
                  SWC_VC_B.y_path_data_d[SWC_VC_B.park_out_segment];
                SWC_VC_B.park_out_segment++;
              }

              SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[0] - /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[0]) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.b_counter = (int32_T)(SWC_VC_B.qY_p + sum_n_segment);
              if ((uint32_T)SWC_VC_B.b_counter > 255U) {
                SWC_VC_B.b_counter = 255;
              }

              SWC_VC_B.n_segment_i[0] = (uint8_T)SWC_VC_B.b_counter;
            } else {
              SWC_VC_B.b_counter = 0;
              while (SWC_VC_B.b_counter <= SWC_VC_B.park_out_segment) {
                fxo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                  SWC_VC_B.b_counter] =
                  SWC_VC_B.x_out_bz_data[SWC_VC_B.b_counter];
                fyo_data[sum_52uUX64c(&SWC_VC_B.n_segment_i[1]) +
                  SWC_VC_B.b_counter] =
                  SWC_VC_B.y_out_bz_data[SWC_VC_B.b_counter];
                SWC_VC_B.b_counter++;
              }
            }
          }
        } else {
          SWC_VC_B.n_segment_i[0] = 0U;
        }

        memcpy(&SWC_VC_B.dummy_data[0], &fxo_data[0], 250U * sizeof(real32_T));
        SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
        SWC_VC_B.park_out_segment = 0;
        while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
          fxo_data[SWC_VC_B.park_out_segment] = SWC_VC_B.dummy_data
            [(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) - SWC_VC_B.park_out_segment)
            - 1];
          SWC_VC_B.park_out_segment++;
        }

        memcpy(&SWC_VC_B.dummy_data[0], &fyo_data[0], 250U * sizeof(real32_T));
        SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
        SWC_VC_B.park_out_segment = 0;
        while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
          fyo_data[SWC_VC_B.park_out_segment] = SWC_VC_B.dummy_data
            [(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) - SWC_VC_B.park_out_segment)
            - 1];
          SWC_VC_B.park_out_segment++;
        }

        memcpy(&SWC_VC_B.b_dummy_data[0], &SWC_VC_B.fgo_data_b[0], 250U * sizeof
               (int8_T));
        SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
        SWC_VC_B.park_out_segment = 0;
        while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
          SWC_VC_B.fgo_data_b[SWC_VC_B.park_out_segment] =
            SWC_VC_B.b_dummy_data[(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) -
            SWC_VC_B.park_out_segment) - 1];
          SWC_VC_B.park_out_segment++;
        }

        total_num_idx_12 = 0U;
        if (SWC_VC_B.n_segment_i[1] > 0) {
          if (!(plan_params->regen_mode != 0.0F)) {
            SWC_VC_B.d = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment_i[0]));
            if (SWC_VC_B.d < 256.0) {
              if (SWC_VC_B.d >= 0.0) {
                while_step = (uint8_T)SWC_VC_B.d;
              } else {
                while_step = 0U;
              }
            } else {
              while_step = MAX_uint8_T;
            }

            SWC_VC_post_render_common(fxo_data, fyo_data, while_step,
              plan_params->Kf_para, plan_params->delta_s_para,
              SWC_VC_B.fxo_12_data_p, SWC_VC_B.x_out_bz_size,
              SWC_VC_B.fyo_12_data_c, SWC_VC_B.y_out_bz_size, &total_num_idx_12);
            SWC_VC_B.qY_tmp_c = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
            SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
            if (SWC_VC_B.qY_tmp_c > total_num_idx_12) {
              SWC_VC_B.qY_p = 0U;
              SWC_VC_B.qY_tmp_c = 0U;
            }

            SWC_VC_B.b_counter = total_num_idx_12 - 1;
            SWC_VC_B.heading_2 = rt_atan2f_snf
              (SWC_VC_B.fyo_12_data_c[SWC_VC_B.b_counter] -
               SWC_VC_B.fyo_12_data_c[(int32_T)SWC_VC_B.qY_p - 1],
               SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter] -
               SWC_VC_B.fxo_12_data_p[(int32_T)SWC_VC_B.qY_tmp_c - 1]) *
              57.2957802F;
            SWC_VC_B.park_out_segment = 0;
            while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
              fxo_data[SWC_VC_B.park_out_segment] =
                SWC_VC_B.fxo_12_data_p[SWC_VC_B.park_out_segment];
              fyo_data[SWC_VC_B.park_out_segment] =
                SWC_VC_B.fyo_12_data_c[SWC_VC_B.park_out_segment];
              SWC_VC_B.fgo_data_b[SWC_VC_B.park_out_segment] = -1;
              SWC_VC_B.park_out_segment++;
            }
          } else {
            total_num_idx_12 = sum_lsjEpyTA(&SWC_VC_B.n_segment_i[0]);
            SWC_VC_B.qY_tmp_c = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
            SWC_VC_B.qY_p = SWC_VC_B.qY_tmp_c;
            if (SWC_VC_B.qY_tmp_c > total_num_idx_12) {
              SWC_VC_B.qY_p = 0U;
              SWC_VC_B.qY_tmp_c = 0U;
            }

            SWC_VC_B.b_counter = total_num_idx_12 - 1;
            SWC_VC_B.heading_2 = rt_atan2f_snf(fyo_data[SWC_VC_B.b_counter] -
              fyo_data[(int32_T)SWC_VC_B.qY_p - 1], fxo_data[SWC_VC_B.b_counter]
              - fxo_data[(int32_T)SWC_VC_B.qY_tmp_c - 1]) * 57.2957802F;
            SWC_VC_B.park_out_segment = 0;
            while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter) {
              SWC_VC_B.fgo_data_b[SWC_VC_B.park_out_segment] = -1;
              SWC_VC_B.park_out_segment++;
            }
          }

          fio[1] = (int16_T)-total_num_idx_12;
        }

        if ((!run_twice) && (SWC_VC_B.pps[6] - SWC_VC_B.pps[0] <
                             plan_params->PS_size_para[3])) {
          run_twice = true;
          SWC_VC_B.Phi_guideline_c[2] += SWC_VC_B.Phi_guideline_c[2] -
            (SWC_VC_B.heading_2 - 180.0F);
          memcpy(&SWC_VC_B.dummy_data[0], &fxo_data[0], 250U * sizeof(real32_T));
          SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
            fxo_data[SWC_VC_B.park_out_segment] = SWC_VC_B.dummy_data
              [(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) -
                SWC_VC_B.park_out_segment) - 1];
            SWC_VC_B.park_out_segment++;
          }

          memcpy(&SWC_VC_B.dummy_data[0], &fyo_data[0], 250U * sizeof(real32_T));
          SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
            fyo_data[SWC_VC_B.park_out_segment] = SWC_VC_B.dummy_data
              [(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) -
                SWC_VC_B.park_out_segment) - 1];
            SWC_VC_B.park_out_segment++;
          }

          memcpy(&SWC_VC_B.b_dummy_data[0], &SWC_VC_B.fgo_data_b[0], 250U *
                 sizeof(int8_T));
          SWC_VC_B.b_counter = sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]);
          SWC_VC_B.park_out_segment = 0;
          while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
            SWC_VC_B.fgo_data_b[SWC_VC_B.park_out_segment] =
              SWC_VC_B.b_dummy_data[(sum_8eIcAjAO(&SWC_VC_B.n_segment_i[0]) -
              SWC_VC_B.park_out_segment) - 1];
            SWC_VC_B.park_out_segment++;
          }
        } else {
          run_twice = false;
        }
      }

      SWC_VC_B.b_counter = sum_tAhCUalH(&SWC_VC_B.n_segment_i[2]);
      SWC_VC_B.park_out_segment = 0;
      while (SWC_VC_B.park_out_segment <= SWC_VC_B.b_counter - 1) {
        SWC_VC_B.P0_idx_0_tmp = total_num_idx_12 + SWC_VC_B.park_out_segment;
        fxo_data[SWC_VC_B.P0_idx_0_tmp] = fxo_data[sum_lsjEpyTA
          (&SWC_VC_B.n_segment_i[0]) + SWC_VC_B.park_out_segment];
        fyo_data[SWC_VC_B.P0_idx_0_tmp] = fyo_data[sum_lsjEpyTA
          (&SWC_VC_B.n_segment_i[0]) + SWC_VC_B.park_out_segment];
        SWC_VC_B.park_out_segment++;
      }
    } else {
      total_num_idx_12 = 0U;
      gear_last_sweep = regen_dir;
      sum_n_segment = 0U;
      do {
        exitg1 = 0;
        SWC_VC_B.temp = fabsf(SWC_VC_B.Phi_guideline_c[total_num_idx_12] +
                              180.0F);
        if ((SWC_VC_B.temp > plan_params->ang_threshold_regen) &&
            ((total_num_idx_12 <= 4) && (*co > 0))) {
          total_num_idx_12++;
          SWC_VC_B.X[0] = SWC_VC_B.pp_m[(total_num_idx_12 - 1) << 1];
          switch (regen_dir) {
           case 1:
            SWC_VC_B.X[1] = fminf(SWC_VC_B.front_X, SWC_VC_B.pp_m
                                  [(total_num_idx_12 - 1) << 1]);
            break;

           case -1:
            SWC_VC_B.X[1] = fmaxf(SWC_VC_B.rear_X, SWC_VC_B.pp_m
                                  [(total_num_idx_12 - 1) << 1]);
            break;
          }

          SWC_VC_B.b_counter = (total_num_idx_12 - 1) << 1;
          if (SWC_VC_B.pp_m[SWC_VC_B.b_counter] != SWC_VC_B.X[1]) {
            SWC_VC_sweep_finder_para_common(SWC_VC_B.pp_m[(total_num_idx_12 - 1)
              << 1], SWC_VC_B.X[1], SWC_VC_B.pp_m[((total_num_idx_12 - 1) << 1)
              + 1], SWC_VC_B.Phi_guideline_c[total_num_idx_12 - 1], SWC_VC_B.pps,
              plan_params->str_whl_ang_regen, regen_dir, plan_params->park_out,
              plan_params->ang_threshold_regen, plan_params->aux_turn_para_regen,
              plan_params->curb_over_Y_dir_para, plan_params->delta_s_para,
              veh_params.Ke_AP_I_VehFrontOverhang,
              veh_params.Ke_AP_I_VehWheelbase, veh_params.Ke_AP_I_VehWidth,
              veh_params.Ke_AP_I_VehRearOverhang, SWC_VC_B.output_data,
              SWC_VC_B.x_out_bz_size);
            memcpy(&SWC_VC_B.x_out_data_l[0], &SWC_VC_B.output_data[0], 50U *
                   sizeof(real32_T));
            memcpy(&SWC_VC_B.y_out_data_h[0], &SWC_VC_B.output_data[50], 50U *
                   sizeof(real32_T));
            SWC_VC_B.pp_m[total_num_idx_12 << 1] = SWC_VC_B.output_data[100];
            SWC_VC_B.pp_m[(total_num_idx_12 << 1) + 1] = SWC_VC_B.output_data
              [101];
            SWC_VC_B.Phi_guideline_c[total_num_idx_12] = SWC_VC_B.output_data
              [102];
            SWC_VC_B.temp = roundf(SWC_VC_B.output_data[103]);
            if (SWC_VC_B.temp < 256.0F) {
              if (SWC_VC_B.temp >= 0.0F) {
                SWC_VC_B.n_segment_i[total_num_idx_12 - 1] = (uint8_T)
                  SWC_VC_B.temp;
              } else {
                SWC_VC_B.n_segment_i[total_num_idx_12 - 1] = 0U;
              }
            } else {
              SWC_VC_B.n_segment_i[total_num_idx_12 - 1] = MAX_uint8_T;
            }
          } else {
            SWC_VC_B.n_segment_i[total_num_idx_12 - 1] = 0U;
          }

          SWC_VC_B.park_out_segment = total_num_idx_12 - 1;
          if (SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] != 0) {
            SWC_VC_B.X_c[0] = SWC_VC_B.pp_m[total_num_idx_12 << 1] -
              SWC_VC_B.pp_m[SWC_VC_B.b_counter];
            SWC_VC_B.X_c[1] = SWC_VC_B.pp_m[(total_num_idx_12 << 1) + 1] -
              SWC_VC_B.pp_m[((total_num_idx_12 - 1) << 1) + 1];
            if (norm_5ISqY4yY(SWC_VC_B.X_c) >
                plan_params->sweep_length_lim_regen) {
              n_segment_tail = 1U;
              if (total_num_idx_12 > 1) {
                n_segment_tail = 2U;
                SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment]
                  - /*MW:OvSatOk*/ 1U;
                if (SWC_VC_B.qY_p >
                    SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment]) {
                  SWC_VC_B.qY_p = 0U;
                }

                SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] = (uint8_T)
                  SWC_VC_B.qY_p;
              }

              SWC_VC_B.qY_mx = (uint32_T)(n_segment_tail - 1);
              SWC_VC_B.b_counter = (int32_T)
                (SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] +
                 SWC_VC_B.qY_mx);
              if ((uint32_T)SWC_VC_B.b_counter > 255U) {
                SWC_VC_B.b_counter = 255;
              }

              while (n_segment_tail <= (uint8_T)SWC_VC_B.b_counter) {
                SWC_VC_B.fxo_data_tmp = (int32_T)((uint32_T)sum_n_segment +
                  n_segment_tail);
                SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.fxo_data_tmp;
                if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                  SWC_VC_B.P0_idx_0_tmp = 255;
                }

                SWC_VC_B.qY_p = SWC_VC_B.P0_idx_0_tmp - /*MW:OvSatOk*/
                  SWC_VC_B.qY_mx;
                if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.P0_idx_0_tmp) {
                  SWC_VC_B.qY_p = 0U;
                }

                SWC_VC_B.P0_idx_0_tmp = n_segment_tail - 1;
                fxo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                  SWC_VC_B.x_out_data_l[SWC_VC_B.P0_idx_0_tmp];
                if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                  SWC_VC_B.fxo_data_tmp = 255;
                }

                SWC_VC_B.qY_p = SWC_VC_B.fxo_data_tmp - /*MW:OvSatOk*/
                  SWC_VC_B.qY_mx;
                if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.fxo_data_tmp) {
                  SWC_VC_B.qY_p = 0U;
                }

                fyo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                  SWC_VC_B.y_out_data_h[SWC_VC_B.P0_idx_0_tmp];
                n_segment_tail++;
              }
            } else {
              *co = -22;
            }
          } else {
            *co = -22;
          }

          SWC_VC_B.b_counter = SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] -
            1;
          if (0 <= SWC_VC_B.b_counter) {
            SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.X[1] - SWC_VC_B.X[0];
            if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
              SWC_VC_B.alpha_clothoid_m = 1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
              SWC_VC_B.alpha_clothoid_m = -1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
              SWC_VC_B.alpha_clothoid_m = -0.0F;
            } else {
              SWC_VC_B.alpha_clothoid_m = (rtNaNF);
            }
          }

          SWC_VC_B.i_p = 0;
          while (SWC_VC_B.i_p <= SWC_VC_B.b_counter) {
            if (SWC_VC_B.alpha_clothoid_m < 128.0F) {
              SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.i_p] = (int8_T)
                SWC_VC_B.alpha_clothoid_m;
            } else {
              SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.i_p] = MAX_int8_T;
            }

            SWC_VC_B.i_p++;
          }

          SWC_VC_B.b_counter = (int32_T)(sum_n_segment + 1U);
          if ((uint32_T)SWC_VC_B.b_counter > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          fio[SWC_VC_B.park_out_segment] = (int16_T)
            (SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] *
             SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter - 1]);
          SWC_VC_B.b_counter = (int32_T)((uint32_T)
            SWC_VC_B.n_segment_i[SWC_VC_B.park_out_segment] + sum_n_segment);
          if ((uint32_T)SWC_VC_B.b_counter > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          sum_n_segment = (uint8_T)SWC_VC_B.b_counter;
          SWC_VC_B.b_counter = -regen_dir;
          if (SWC_VC_B.b_counter > 127) {
            SWC_VC_B.b_counter = 127;
          }

          regen_dir = (int8_T)SWC_VC_B.b_counter;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      if (SWC_VC_B.temp <= plan_params->ang_threshold_regen) {
        if (*co > 0) {
          total_num_idx_12++;
          SWC_VC_B.pp_tmp_n = total_num_idx_12 << 1;
          SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] = SWC_VC_B.final_point_idx_0;
          SWC_VC_B.b_counter = (total_num_idx_12 - 1) << 1;
          SWC_VC_B.temp = SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] -
            SWC_VC_B.pp_m[SWC_VC_B.b_counter];
          if (SWC_VC_B.temp <= 0.0F) {
            SWC_VC_B.alpha_clothoid_m =
              SWC_VC_B.Phi_guideline_c[total_num_idx_12 - 1];
            tand_brbYAlcS(&SWC_VC_B.alpha_clothoid_m);
            SWC_VC_B.pp_m[(total_num_idx_12 << 1) + 1] = SWC_VC_B.temp *
              SWC_VC_B.alpha_clothoid_m + SWC_VC_B.pp_m[((total_num_idx_12 - 1) <<
              1) + 1];
          } else {
            SWC_VC_B.alpha_clothoid_m =
              SWC_VC_B.Phi_guideline_c[total_num_idx_12 - 1];
            tand_brbYAlcS(&SWC_VC_B.alpha_clothoid_m);
            SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n + 1] =
              SWC_VC_B.pp_m[SWC_VC_B.b_counter + 1] - SWC_VC_B.temp *
              SWC_VC_B.alpha_clothoid_m;
          }

          SWC_VC_B.alpha_clothoid_m = SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] -
            SWC_VC_B.pp_m[SWC_VC_B.b_counter];
          SWC_VC_B.X[0] = SWC_VC_B.alpha_clothoid_m;
          SWC_VC_B.i_p = ((total_num_idx_12 - 1) << 1) + 1;
          SWC_VC_B.P0_idx_0_tmp = (total_num_idx_12 << 1) + 1;
          SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp] -
            SWC_VC_B.pp_m[SWC_VC_B.i_p];
          SWC_VC_B.X[1] = SWC_VC_B.alpha_clothoid_old_m;
          SWC_VC_B.pp_tail_idx_0 = norm_5ISqY4yY(SWC_VC_B.X);
          if ((SWC_VC_B.pp_tail_idx_0 <= 0.42) && (total_num_idx_12 > 1)) {
            SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] = SWC_VC_B.pp_m[SWC_VC_B.b_counter]
              + SWC_VC_B.alpha_clothoid_m / SWC_VC_B.pp_tail_idx_0 * 0.42F;
            SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp] = SWC_VC_B.pp_m[SWC_VC_B.i_p] +
              SWC_VC_B.alpha_clothoid_old_m / SWC_VC_B.pp_tail_idx_0 * 0.42F;
          } else {
            SWC_VC_B.X_c[0] = SWC_VC_B.alpha_clothoid_m;
            SWC_VC_B.X_c[1] = SWC_VC_B.alpha_clothoid_old_m;
            if ((norm_5ISqY4yY(SWC_VC_B.X_c) <= 0.17) && (total_num_idx_12 == 1))
            {
              SWC_VC_B.Y[0] = SWC_VC_B.pp_m[2] - SWC_VC_B.pp_m[0];
              SWC_VC_B.Y[1] = SWC_VC_B.pp_m[3] - SWC_VC_B.pp_m[1];
              SWC_VC_B.alpha_clothoid_m = norm_5ISqY4yY(SWC_VC_B.Y);
              SWC_VC_B.pp_m[2] = SWC_VC_B.Y[0] / SWC_VC_B.alpha_clothoid_m *
                0.17F + SWC_VC_B.pp_m[0];
              SWC_VC_B.pp_m[3] = SWC_VC_B.Y[1] / SWC_VC_B.alpha_clothoid_m *
                0.17F + SWC_VC_B.pp_m[1];
            }
          }

          guard1 = false;
          if (total_num_idx_12 == 1) {
            SWC_VC_B.park_out_segment = -gear_last_sweep;
            if (SWC_VC_B.park_out_segment > 127) {
              SWC_VC_B.park_out_segment = 127;
            }

            SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.pp_m[2] - SWC_VC_B.pp_m[0];
            if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
              SWC_VC_B.alpha_clothoid_old_m = -1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
              SWC_VC_B.alpha_clothoid_old_m = 1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
              SWC_VC_B.alpha_clothoid_old_m = 0.0F;
            } else {
              SWC_VC_B.alpha_clothoid_old_m = (rtNaNF);
            }

            if (SWC_VC_B.alpha_clothoid_old_m != SWC_VC_B.park_out_segment) {
              *co = -26;
            } else {
              guard1 = true;
            }
          } else {
            guard1 = true;
          }

          if (guard1) {
            SWC_VC_B.P0_idx_1_tmp = total_num_idx_12 - 1;
            SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] = plan_params->n_para;
            n_segment_tail = 1U;
            while (n_segment_tail <= SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp])
            {
              SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
                /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.park_out_segment = n_segment_tail - 1;
              SWC_VC_B.x_out_data_l[SWC_VC_B.park_out_segment] =
                (SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] -
                 SWC_VC_B.pp_m[SWC_VC_B.b_counter]) * ((real32_T)n_segment_tail
                - 1.0F) / (real32_T)(int32_T)SWC_VC_B.qY_p +
                SWC_VC_B.pp_m[SWC_VC_B.b_counter];
              SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
                /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.y_out_data_h[SWC_VC_B.park_out_segment] =
                (SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp] -
                 SWC_VC_B.pp_m[SWC_VC_B.i_p]) * ((real32_T)n_segment_tail - 1.0F)
                / (real32_T)(int32_T)SWC_VC_B.qY_p + SWC_VC_B.pp_m[SWC_VC_B.i_p];
              SWC_VC_B.park_out_segment = (int32_T)(n_segment_tail + 1U);
              if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
                SWC_VC_B.park_out_segment = 255;
              }

              n_segment_tail = (uint8_T)SWC_VC_B.park_out_segment;
            }

            n_segment_tail = 1U;
            if (total_num_idx_12 > 1) {
              n_segment_tail = 2U;
              SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
                /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] = (uint8_T)
                SWC_VC_B.qY_p;
            }

            SWC_VC_B.qY_mx = (uint32_T)(n_segment_tail - 1);
            SWC_VC_B.park_out_segment = (int32_T)
              (SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] + SWC_VC_B.qY_mx);
            if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
              SWC_VC_B.park_out_segment = 255;
            }

            while (n_segment_tail <= (uint8_T)SWC_VC_B.park_out_segment) {
              SWC_VC_B.fxo_data_tmp = (int32_T)((uint32_T)sum_n_segment +
                n_segment_tail);
              SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.fxo_data_tmp;
              if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                SWC_VC_B.P0_idx_0_tmp = 255;
              }

              SWC_VC_B.qY_p = SWC_VC_B.P0_idx_0_tmp - /*MW:OvSatOk*/
                SWC_VC_B.qY_mx;
              if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.P0_idx_0_tmp) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.P0_idx_0_tmp = n_segment_tail - 1;
              fxo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                SWC_VC_B.x_out_data_l[SWC_VC_B.P0_idx_0_tmp];
              if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                SWC_VC_B.fxo_data_tmp = 255;
              }

              SWC_VC_B.qY_p = SWC_VC_B.fxo_data_tmp - /*MW:OvSatOk*/
                SWC_VC_B.qY_mx;
              if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.fxo_data_tmp) {
                SWC_VC_B.qY_p = 0U;
              }

              fyo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                SWC_VC_B.y_out_data_h[SWC_VC_B.P0_idx_0_tmp];
              n_segment_tail++;
            }

            SWC_VC_B.park_out_segment =
              SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] - 1;
            if (0 <= SWC_VC_B.park_out_segment) {
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] -
                SWC_VC_B.pp_m[SWC_VC_B.b_counter];
              if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
                SWC_VC_B.heading_2 = 1.0F;
              } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
                SWC_VC_B.heading_2 = -1.0F;
              } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
                SWC_VC_B.heading_2 = -0.0F;
              } else {
                SWC_VC_B.heading_2 = (rtNaNF);
              }
            }

            SWC_VC_B.b_counter = 0;
            while (SWC_VC_B.b_counter <= SWC_VC_B.park_out_segment) {
              if (SWC_VC_B.heading_2 < 128.0F) {
                SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.b_counter] =
                  (int8_T)SWC_VC_B.heading_2;
              } else {
                SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.b_counter] =
                  MAX_int8_T;
              }

              SWC_VC_B.b_counter++;
            }

            SWC_VC_B.b_counter = (int32_T)(sum_n_segment + 1U);
            if ((uint32_T)SWC_VC_B.b_counter > 255U) {
              SWC_VC_B.b_counter = 255;
            }

            fio[SWC_VC_B.P0_idx_1_tmp] = (int16_T)
              (SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] *
               SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter - 1]);
          }
        } else {
          *co = -26;
        }
      } else {
        *co = -26;
      }
    }
  } else {
    car_passed_ps = false;
    if (!(plan_params->regen_mode != 0.0F)) {
      gear_last_sweep = -1;
    } else {
      gear_last_sweep = regen_dir;
      car_passed_ps = true;
    }

    total_num_idx_12 = 0U;
    SWC_VC_B.alpha_clothoid_m = 0.0F;
    sum_n_segment = 0U;
    if (SWC_VC_B.pp_m[0] < ps[0]) {
      *co = -19;
    } else if (SWC_VC_B.pp_m[0] > ps[6]) {
      *co = -19;
    } else {
      if ((SWC_VC_B.pp_m[0] >= SWC_VC_B.front_X) || (gear_last_sweep == -1)) {
        while (((!(SWC_VC_B.alpha_clothoid_m != 0.0F)) || (gear_last_sweep == 1))
               && (total_num_idx_12 < plan_params->max_num_sweeps) && (*co > 0))
        {
          total_num_idx_12++;
          SWC_VC_B.pp_tmp_n = total_num_idx_12 - 1;
          SWC_VC_B.i_p = SWC_VC_B.pp_tmp_n << 1;
          SWC_VC_B.X[0] = SWC_VC_B.pp_m[SWC_VC_B.i_p];
          SWC_VC_B.X[1] = (real32_T)(gear_last_sweep == 1) * SWC_VC_B.front_X +
            (real32_T)(gear_last_sweep == -1) * SWC_VC_B.rear_X;
          if ((SWC_VC_B.pp_m[SWC_VC_B.i_p] > SWC_VC_B.rear_X + 1.0F) &&
              (gear_last_sweep == -1)) {
            SWC_VC_B.X[1] = SWC_VC_B.front_X;
            gear_last_sweep = 1;
          }

          if ((total_num_idx_12 == 1) && (!(plan_params->regen_mode != 0.0F))) {
            SWC_VC_sweep_finder_para_common_m(SWC_VC_B.pp_m[(total_num_idx_12 -
              1) << 1], SWC_VC_B.X[1], SWC_VC_B.pp_m[((total_num_idx_12 - 1) <<
              1) + 1], SWC_VC_B.Phi_guideline_c[0], SWC_VC_B.pps,
              gear_last_sweep, plan_params->park_out,
              plan_params->ang_threshold_regen, plan_params->aux_turn_para_regen,
              plan_params->curb_over_Y_dir_para, plan_params->delta_s_para,
              veh_params.Ke_AP_I_VehFrontOverhang,
              veh_params.Ke_AP_I_VehWheelbase, veh_params.Ke_AP_I_VehWidth,
              veh_params.Ke_AP_I_VehRearOverhang, SWC_VC_B.output_data,
              SWC_VC_B.x_out_bz_size);
          } else {
            SWC_VC_sweep_finder_para_common_ml(SWC_VC_B.pp_m[(total_num_idx_12 -
              1) << 1], SWC_VC_B.X[1], SWC_VC_B.pp_m[((total_num_idx_12 - 1) <<
              1) + 1], SWC_VC_B.Phi_guideline_c[total_num_idx_12 - 1],
              SWC_VC_B.pps, gear_last_sweep, plan_params->park_out,
              plan_params->ang_threshold_regen, plan_params->aux_turn_para_regen,
              plan_params->curb_over_Y_dir_para, plan_params->delta_s_para,
              veh_params.Ke_AP_I_VehFrontOverhang,
              veh_params.Ke_AP_I_VehWheelbase, veh_params.Ke_AP_I_VehWidth,
              veh_params.Ke_AP_I_VehRearOverhang, SWC_VC_B.output_data,
              SWC_VC_B.x_out_bz_size);
          }

          SWC_VC_B.park_out_segment = (int32_T)(total_num_idx_12 + 1U);
          SWC_VC_B.b_counter = SWC_VC_B.park_out_segment;
          if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          SWC_VC_B.pp_m[(SWC_VC_B.b_counter - 1) << 1] = SWC_VC_B.output_data
            [100];
          SWC_VC_B.b_counter = SWC_VC_B.park_out_segment;
          if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          SWC_VC_B.pp_m[((SWC_VC_B.b_counter - 1) << 1) + 1] =
            SWC_VC_B.output_data[101];
          SWC_VC_B.b_counter = SWC_VC_B.park_out_segment;
          if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
            SWC_VC_B.b_counter = 255;
          }

          SWC_VC_B.Phi_guideline_c[SWC_VC_B.b_counter - 1] =
            SWC_VC_B.output_data[102];
          SWC_VC_B.temp = roundf(SWC_VC_B.output_data[103]);
          if (SWC_VC_B.temp < 256.0F) {
            if (SWC_VC_B.temp >= 0.0F) {
              SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] = (uint8_T)SWC_VC_B.temp;
            } else {
              SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] = 0U;
            }
          } else {
            SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] = MAX_uint8_T;
          }

          SWC_VC_B.alpha_clothoid_m = SWC_VC_B.output_data[104];
          SWC_VC_B.alpha_clothoid_old_m = 0.0F;
          if (SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] != 0) {
            if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
              SWC_VC_B.park_out_segment = 255;
            }

            SWC_VC_B.pp_tmp_n = (SWC_VC_B.park_out_segment - 1) << 1;
            SWC_VC_B.X_c[0] = SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] -
              SWC_VC_B.pp_m[SWC_VC_B.i_p];
            SWC_VC_B.X_c[1] = SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n + 1] -
              SWC_VC_B.pp_m[((total_num_idx_12 - 1) << 1) + 1];
            SWC_VC_B.alpha_clothoid_old_m = norm_5ISqY4yY(SWC_VC_B.X_c);
          }

          if ((SWC_VC_B.alpha_clothoid_old_m <
               plan_params->sweep_length_lim_regen) && (!(SWC_VC_B.output_data
                [104] != 0.0F))) {
            if ((total_num_idx_12 == 1) && car_passed_ps) {
              car_passed_ps = false;
              total_num_idx_12 = 0U;
            } else {
              *co = -18;
            }
          } else {
            n_segment_tail = 1U;
            if (total_num_idx_12 > 1) {
              n_segment_tail = 2U;
              SWC_VC_B.fxo_data_tmp = total_num_idx_12 - 1;
              SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.fxo_data_tmp] -
                /*MW:OvSatOk*/ 1U;
              if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.fxo_data_tmp]) {
                SWC_VC_B.qY_p = 0U;
              }

              SWC_VC_B.n_segment_i[SWC_VC_B.fxo_data_tmp] = (uint8_T)
                SWC_VC_B.qY_p;
            }

            SWC_VC_B.b_counter = total_num_idx_12 - 1;
            SWC_VC_B.qY_mx = (uint32_T)(n_segment_tail - 1);
            SWC_VC_B.park_out_segment = (int32_T)
              (SWC_VC_B.n_segment_i[SWC_VC_B.b_counter] + SWC_VC_B.qY_mx);
            if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
              SWC_VC_B.park_out_segment = 255;
            }

            while (n_segment_tail <= (uint8_T)SWC_VC_B.park_out_segment) {
              SWC_VC_B.fxo_data_tmp = (int32_T)((uint32_T)sum_n_segment +
                n_segment_tail);
              SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.fxo_data_tmp;
              if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                SWC_VC_B.P0_idx_0_tmp = 255;
              }

              SWC_VC_B.qY_p = SWC_VC_B.P0_idx_0_tmp - /*MW:OvSatOk*/
                SWC_VC_B.qY_mx;
              if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.P0_idx_0_tmp) {
                SWC_VC_B.qY_p = 0U;
              }

              fxo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                SWC_VC_B.output_data[n_segment_tail - 1];
              if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
                SWC_VC_B.fxo_data_tmp = 255;
              }

              SWC_VC_B.qY_p = SWC_VC_B.fxo_data_tmp - /*MW:OvSatOk*/
                SWC_VC_B.qY_mx;
              if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.fxo_data_tmp) {
                SWC_VC_B.qY_p = 0U;
              }

              fyo_data[(int32_T)SWC_VC_B.qY_p - 1] =
                SWC_VC_B.output_data[n_segment_tail + 49];
              n_segment_tail++;
            }

            SWC_VC_B.park_out_segment = SWC_VC_B.n_segment_i[SWC_VC_B.b_counter]
              - 1;
            if (0 <= SWC_VC_B.park_out_segment) {
              SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.X[1] - SWC_VC_B.X[0];
              if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
                SWC_VC_B.heading_2 = 1.0F;
              } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
                SWC_VC_B.heading_2 = -1.0F;
              } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
                SWC_VC_B.heading_2 = -0.0F;
              } else {
                SWC_VC_B.heading_2 = (rtNaNF);
              }
            }

            SWC_VC_B.i_p = 0;
            while (SWC_VC_B.i_p <= SWC_VC_B.park_out_segment) {
              if (SWC_VC_B.heading_2 < 128.0F) {
                SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.i_p] = (int8_T)
                  SWC_VC_B.heading_2;
              } else {
                SWC_VC_B.fgo_data_b[sum_n_segment + SWC_VC_B.i_p] = MAX_int8_T;
              }

              SWC_VC_B.i_p++;
            }

            SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.X[1] - SWC_VC_B.X[0];
            if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
              SWC_VC_B.temp = 1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
              SWC_VC_B.temp = -1.0F;
            } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
              SWC_VC_B.temp = -0.0F;
            } else {
              SWC_VC_B.temp = (rtNaNF);
            }

            if (SWC_VC_B.temp < 32768.0F) {
              sum_indx_sweeps = (int16_T)SWC_VC_B.temp;
            } else {
              sum_indx_sweeps = MAX_int16_T;
            }

            fio[SWC_VC_B.b_counter] = (int16_T)
              (SWC_VC_B.n_segment_i[SWC_VC_B.b_counter] * sum_indx_sweeps);
            SWC_VC_B.b_counter = (int32_T)((uint32_T)
              SWC_VC_B.n_segment_i[SWC_VC_B.b_counter] + sum_n_segment);
            if ((uint32_T)SWC_VC_B.b_counter > 255U) {
              SWC_VC_B.b_counter = 255;
            }

            sum_n_segment = (uint8_T)SWC_VC_B.b_counter;
          }

          SWC_VC_B.b_counter = -gear_last_sweep;
          if (SWC_VC_B.b_counter > 127) {
            SWC_VC_B.b_counter = 127;
          }

          gear_last_sweep = (int8_T)SWC_VC_B.b_counter;
        }
      }

      SWC_VC_B.b_counter = (int32_T)(total_num_idx_12 + 1U);
      if ((uint32_T)SWC_VC_B.b_counter > 255U) {
        SWC_VC_B.b_counter = 255;
      }

      SWC_VC_B.i_p = (int32_T)((uint8_T)SWC_VC_B.b_counter + 1U);
      SWC_VC_B.park_out_segment = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.park_out_segment = 255;
      }

      SWC_VC_B.pp_tmp_n = (SWC_VC_B.park_out_segment - 1) << 1;
      SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n] = ps[0] + plan_params->fin_loc_para_out[0];
      SWC_VC_B.pp_m[SWC_VC_B.pp_tmp_n + 1] = (ps[1] +
        plan_params->fin_loc_para_out[1]) + -0.8F;
      SWC_VC_B.park_out_segment = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.park_out_segment = 255;
      }

      SWC_VC_B.Phi_guideline_c[SWC_VC_B.park_out_segment - 1] = -180.0F;
      SWC_VC_B.pp_tmp_n = (uint8_T)SWC_VC_B.b_counter - 1;
      SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.pp_tmp_n << 1;
      SWC_VC_B.P0_idx_1_tmp = SWC_VC_B.P0_idx_0_tmp + 1;
      SWC_VC_B.park_out_segment = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.park_out_segment = 255;
      }

      SWC_VC_B.fxo_data_tmp = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.fxo_data_tmp = 255;
      }

      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.final_point_idx_0 = SWC_VC_B.pp_m[(SWC_VC_B.i3 - 1) << 1] -
        SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp];
      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.PS_play_room = SWC_VC_B.pp_m[((SWC_VC_B.i3 - 1) << 1) + 1] -
        SWC_VC_B.pp_m[SWC_VC_B.P0_idx_1_tmp];
      SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.pp_tmp_n];
      cosd_KZN3FnAl(&SWC_VC_B.heading_2);
      SWC_VC_B.alpha_clothoid_m = SWC_VC_B.Phi_guideline_c[SWC_VC_B.pp_tmp_n];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_m);
      if (SWC_VC_B.final_point_idx_0 * SWC_VC_B.heading_2 +
          SWC_VC_B.PS_play_room * SWC_VC_B.alpha_clothoid_m >= 0.0F) {
        gear_last_sweep = 1;
      } else {
        gear_last_sweep = -1;
      }

      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.i3 - 1];
      cosd_KZN3FnAl(&SWC_VC_B.heading_2);
      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.alpha_clothoid_m = SWC_VC_B.Phi_guideline_c[SWC_VC_B.i3 - 1];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_m);
      if (SWC_VC_B.final_point_idx_0 * SWC_VC_B.heading_2 +
          SWC_VC_B.PS_play_room * SWC_VC_B.alpha_clothoid_m >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.i2 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i2 = 255;
      }

      SWC_VC_B.PS_play_room = fmaxf(fabsf(SWC_VC_B.pp_m[(SWC_VC_B.i3 - 1) << 1]
        - SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp]), fabsf(SWC_VC_B.pp_m
        [((SWC_VC_B.i2 - 1) << 1) + 1] - SWC_VC_B.pp_m[SWC_VC_B.P0_idx_1_tmp])) *
        plan_params->vecLen_coeff_para;
      SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.pp_tmp_n];
      cosd_KZN3FnAl(&SWC_VC_B.heading_2);
      SWC_VC_B.alpha_clothoid_m = SWC_VC_B.Phi_guideline_c[SWC_VC_B.pp_tmp_n];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_m);
      SWC_VC_B.X[0] = SWC_VC_B.PS_play_room * SWC_VC_B.heading_2 * (real32_T)
        gear_last_sweep;
      SWC_VC_B.X[1] = SWC_VC_B.PS_play_room * SWC_VC_B.alpha_clothoid_m *
        (real32_T)gear_last_sweep;
      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.alpha_clothoid_m = SWC_VC_B.Phi_guideline_c[SWC_VC_B.i3 - 1];
      cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_m);
      SWC_VC_B.i3 = SWC_VC_B.i_p;
      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i3 = 255;
      }

      SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.i3 - 1];
      sind_7is3Ljjc(&SWC_VC_B.heading_2);
      SWC_VC_B.final_point_idx_0 = SWC_VC_B.PS_play_room *
        SWC_VC_B.alpha_clothoid_m * (real32_T)direction_flag_W2;
      SWC_VC_B.PS_play_room = SWC_VC_B.PS_play_room * SWC_VC_B.heading_2 *
        (real32_T)direction_flag_W2;
      SWC_VC_B.heading_2 = SWC_VC_B.pp_m[(SWC_VC_B.park_out_segment - 1) << 1] -
        SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp];
      SWC_VC_B.Y[0] = SWC_VC_B.heading_2;
      SWC_VC_B.X_c[0] = SWC_VC_B.X[0];
      SWC_VC_B.P3_f[0] = (SWC_VC_B.heading_2 - SWC_VC_B.X[0]) -
        SWC_VC_B.final_point_idx_0;
      SWC_VC_B.final_point[0] = SWC_VC_B.final_point_idx_0;
      SWC_VC_B.heading_2 = SWC_VC_B.pp_m[((SWC_VC_B.fxo_data_tmp - 1) << 1) + 1]
        - SWC_VC_B.pp_m[SWC_VC_B.P0_idx_1_tmp];
      SWC_VC_B.Y[1] = SWC_VC_B.heading_2;
      SWC_VC_B.X_c[1] = SWC_VC_B.X[1];
      SWC_VC_B.P3_f[1] = (SWC_VC_B.heading_2 - SWC_VC_B.X[1]) -
        SWC_VC_B.PS_play_room;
      SWC_VC_B.final_point[1] = SWC_VC_B.PS_play_room;
      SWC_VC_B.temp = floorf(norm_5ISqY4yY(SWC_VC_B.Y) /
        plan_params->delta_s_para);
      if (SWC_VC_B.temp < 256.0F) {
        if (SWC_VC_B.temp >= 0.0F) {
          while_step = (uint8_T)SWC_VC_B.temp;
        } else {
          while_step = 0U;
        }
      } else {
        while_step = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function_common(SWC_VC_B.X_c, SWC_VC_B.P3_f,
        SWC_VC_B.final_point, while_step, &SWC_VC_B.heading_2,
        SWC_VC_B.x_out_bz_data, SWC_VC_B.x_out_bz_size, SWC_VC_B.y_out_bz_data,
        SWC_VC_B.y_out_bz_size, &SWC_VC_B.n_segment_i[(uint8_T)
        SWC_VC_B.b_counter - 1]);
      SWC_VC_B.park_out_segment = 0;
      while (SWC_VC_B.park_out_segment <= SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n]
             - 1) {
        SWC_VC_B.x_out_bz_data[SWC_VC_B.park_out_segment] +=
          SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp];
        SWC_VC_B.y_out_bz_data[SWC_VC_B.park_out_segment] +=
          SWC_VC_B.pp_m[SWC_VC_B.P0_idx_1_tmp];
        SWC_VC_B.park_out_segment++;
      }

      if ((SWC_VC_B.heading_2 > plan_params->maxCurvature) &&
          (plan_params->CurrentSweepVeh == 0)) {
        *co = 1;
      }

      if (SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] > 0) {
        n_segment_tail = 1U;
        if ((uint8_T)SWC_VC_B.b_counter > 1) {
          n_segment_tail = 2U;
          SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] -
            /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n]) {
            SWC_VC_B.qY_p = 0U;
          }

          SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] = (uint8_T)SWC_VC_B.qY_p;
        }

        SWC_VC_B.qY_mx = (uint32_T)(n_segment_tail - 1);
        SWC_VC_B.b_counter = (int32_T)(SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] +
          SWC_VC_B.qY_mx);
        if ((uint32_T)SWC_VC_B.b_counter > 255U) {
          SWC_VC_B.b_counter = 255;
        }

        while (n_segment_tail <= (uint8_T)SWC_VC_B.b_counter) {
          SWC_VC_B.fxo_data_tmp = (int32_T)((uint32_T)sum_n_segment +
            n_segment_tail);
          SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.fxo_data_tmp;
          if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
            SWC_VC_B.P0_idx_0_tmp = 255;
          }

          SWC_VC_B.qY_p = SWC_VC_B.P0_idx_0_tmp - /*MW:OvSatOk*/ SWC_VC_B.qY_mx;
          if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.P0_idx_0_tmp) {
            SWC_VC_B.qY_p = 0U;
          }

          SWC_VC_B.P0_idx_0_tmp = n_segment_tail - 1;
          fxo_data[(int32_T)SWC_VC_B.qY_p - 1] =
            SWC_VC_B.x_out_bz_data[SWC_VC_B.P0_idx_0_tmp];
          if ((uint32_T)SWC_VC_B.fxo_data_tmp > 255U) {
            SWC_VC_B.fxo_data_tmp = 255;
          }

          SWC_VC_B.qY_p = SWC_VC_B.fxo_data_tmp - /*MW:OvSatOk*/ SWC_VC_B.qY_mx;
          if (SWC_VC_B.qY_p > (uint32_T)SWC_VC_B.fxo_data_tmp) {
            SWC_VC_B.qY_p = 0U;
          }

          fyo_data[(int32_T)SWC_VC_B.qY_p - 1] =
            SWC_VC_B.y_out_bz_data[SWC_VC_B.P0_idx_0_tmp];
          n_segment_tail++;
        }

        SWC_VC_B.b_counter = (int32_T)((uint32_T)
          SWC_VC_B.n_segment_i[SWC_VC_B.pp_tmp_n] + sum_n_segment);
        if ((uint32_T)SWC_VC_B.b_counter > 255U) {
          SWC_VC_B.b_counter = 255;
        }

        sum_n_segment = (uint8_T)SWC_VC_B.b_counter;
      }

      if ((uint32_T)SWC_VC_B.i_p > 255U) {
        SWC_VC_B.i_p = 255;
      }

      SWC_VC_B.P0_idx_1_tmp = (uint8_T)SWC_VC_B.i_p - 1;
      SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] = plan_params->n_para;
      SWC_VC_B.b_counter = (int32_T)((uint8_T)SWC_VC_B.i_p + 1U);
      SWC_VC_B.park_out_segment = SWC_VC_B.b_counter;
      if ((uint32_T)SWC_VC_B.b_counter > 255U) {
        SWC_VC_B.park_out_segment = 255;
      }

      SWC_VC_B.Phi_guideline_c[SWC_VC_B.park_out_segment - 1] = -180.0F;
      n_segment_tail = 1U;
      while (n_segment_tail <= SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
        SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.P0_idx_1_tmp];
        cosd_KZN3FnAl(&SWC_VC_B.heading_2);
        SWC_VC_B.park_out_segment = (int32_T)((uint32_T)n_segment_tail +
          sum_n_segment);
        SWC_VC_B.fxo_data_tmp = SWC_VC_B.park_out_segment;
        if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
          SWC_VC_B.fxo_data_tmp = 255;
        }

        SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
          /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.P0_idx_1_tmp << 1;
        fxo_data[SWC_VC_B.fxo_data_tmp - 1] = ((real32_T)n_segment_tail - 1.0F) /
          (real32_T)(int32_T)SWC_VC_B.qY_p * SWC_VC_B.heading_2 +
          SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp];
        SWC_VC_B.heading_2 = SWC_VC_B.Phi_guideline_c[SWC_VC_B.P0_idx_1_tmp];
        sind_7is3Ljjc(&SWC_VC_B.heading_2);
        if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
          SWC_VC_B.park_out_segment = 255;
        }

        SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
          /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
          SWC_VC_B.qY_p = 0U;
        }

        fyo_data[SWC_VC_B.park_out_segment - 1] =
          SWC_VC_B.pp_m[SWC_VC_B.P0_idx_0_tmp + 1] + ((real32_T)n_segment_tail -
          1.0F) / (real32_T)(int32_T)SWC_VC_B.qY_p * SWC_VC_B.heading_2;
        SWC_VC_B.park_out_segment = (int32_T)(n_segment_tail + 1U);
        if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
          SWC_VC_B.park_out_segment = 255;
        }

        n_segment_tail = (uint8_T)SWC_VC_B.park_out_segment;
      }

      SWC_VC_B.qY_p = SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] -
        /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY_p > SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp]) {
        SWC_VC_B.qY_p = 0U;
      }

      SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] = (uint8_T)SWC_VC_B.qY_p;
      SWC_VC_B.park_out_segment = (int32_T)((uint32_T)
        SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp] + sum_n_segment);
      if ((uint32_T)SWC_VC_B.park_out_segment > 255U) {
        SWC_VC_B.park_out_segment = 255;
      }

      SWC_VC_B.pp_tmp_n = 0;
      while (SWC_VC_B.pp_tmp_n <= n_segment_tail - 2) {
        SWC_VC_B.P0_idx_0_tmp = SWC_VC_B.pp_tmp_n + (uint8_T)
          SWC_VC_B.park_out_segment;
        SWC_VC_B.fxo_data_tmp = SWC_VC_B.P0_idx_0_tmp + 1;
        fxo_data[SWC_VC_B.P0_idx_0_tmp] = fxo_data[SWC_VC_B.fxo_data_tmp];
        fyo_data[SWC_VC_B.P0_idx_0_tmp] = fyo_data[SWC_VC_B.fxo_data_tmp];
        SWC_VC_B.pp_tmp_n++;
      }

      SWC_VC_B.fxo_data_tmp = SWC_VC_B.b_counter;
      if ((uint32_T)SWC_VC_B.b_counter > 255U) {
        SWC_VC_B.fxo_data_tmp = 255;
        SWC_VC_B.b_counter = 255;
      }

      SWC_VC_B.pp_tmp_n = (uint8_T)SWC_VC_B.park_out_segment - 1;
      SWC_VC_B.pp_m[(SWC_VC_B.fxo_data_tmp - 1) << 1] =
        fxo_data[SWC_VC_B.pp_tmp_n];
      SWC_VC_B.pp_m[((SWC_VC_B.b_counter - 1) << 1) + 1] =
        fyo_data[SWC_VC_B.pp_tmp_n];
      if ((uint8_T)SWC_VC_B.i_p > 3) {
        SWC_VC_B.qY_p = (uint32_T)(uint8_T)SWC_VC_B.park_out_segment -
          /*MW:OvSatOk*/ SWC_VC_B.n_segment_i[SWC_VC_B.P0_idx_1_tmp];
        if (SWC_VC_B.qY_p > (uint8_T)SWC_VC_B.park_out_segment) {
          SWC_VC_B.qY_p = 0U;
        }

        SWC_VC_B.b_counter = (uint8_T)SWC_VC_B.i_p - 2;
        SWC_VC_B.qY_mx = SWC_VC_B.qY_p - /*MW:OvSatOk*/
          SWC_VC_B.n_segment_i[SWC_VC_B.b_counter];
        if (SWC_VC_B.qY_mx > SWC_VC_B.qY_p) {
          SWC_VC_B.qY_mx = 0U;
        }

        SWC_VC_B.i_p = (uint8_T)SWC_VC_B.i_p - 3;
        SWC_VC_B.qY_p = SWC_VC_B.qY_mx - /*MW:OvSatOk*/
          SWC_VC_B.n_segment_i[SWC_VC_B.i_p];
        if (SWC_VC_B.qY_p > SWC_VC_B.qY_mx) {
          SWC_VC_B.qY_p = 0U;
        }

        sum_n_segment_xlast3 = (uint8_T)SWC_VC_B.qY_p;
        SWC_VC_post_render_common_m(fxo_data, fyo_data, (uint8_T)SWC_VC_B.qY_p,
          (uint8_T)SWC_VC_B.park_out_segment, plan_params->Kf_para,
          plan_params->delta_s_para, SWC_VC_B.fxo_12_data_p,
          SWC_VC_B.x_out_bz_size, SWC_VC_B.fyo_12_data_c, SWC_VC_B.y_out_bz_size,
          &sweep_count);
        SWC_VC_B.park_out_segment = 0;
        while (SWC_VC_B.park_out_segment <= sweep_count - 2) {
          SWC_VC_B.P0_idx_0_tmp = (uint8_T)SWC_VC_B.qY_p +
            SWC_VC_B.park_out_segment;
          fxo_data[SWC_VC_B.P0_idx_0_tmp] =
            SWC_VC_B.fxo_12_data_p[SWC_VC_B.park_out_segment + 1];
          fyo_data[SWC_VC_B.P0_idx_0_tmp] =
            SWC_VC_B.fyo_12_data_c[SWC_VC_B.park_out_segment + 1];
          SWC_VC_B.fgo_data_b[SWC_VC_B.P0_idx_0_tmp] = 1;
          SWC_VC_B.park_out_segment++;
        }

        SWC_VC_B.qY_p = sweep_count - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_p > sweep_count) {
          SWC_VC_B.qY_p = 0U;
        }

        fio[SWC_VC_B.i_p] = (int16_T)SWC_VC_B.qY_p;
        sweep_count = (uint8_T)SWC_VC_B.b_counter;
      } else {
        SWC_VC_post_render_common(fxo_data, fyo_data, (uint8_T)
          SWC_VC_B.park_out_segment, plan_params->Kf_para,
          plan_params->delta_s_para, SWC_VC_B.fxo_12_data_p,
          SWC_VC_B.x_out_bz_size, SWC_VC_B.fyo_12_data_c, SWC_VC_B.y_out_bz_size,
          &sweep_count);
        SWC_VC_B.b_counter = 0;
        while (SWC_VC_B.b_counter <= sweep_count - 1) {
          fxo_data[SWC_VC_B.b_counter] =
            SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
          fyo_data[SWC_VC_B.b_counter] =
            SWC_VC_B.fyo_12_data_c[SWC_VC_B.b_counter];
          SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter] = 1;
          SWC_VC_B.b_counter++;
        }

        fio[0] = sweep_count;
        sweep_count = 1U;
      }
    }
  }

  for (SWC_VC_B.i_p = 0; SWC_VC_B.i_p < 10; SWC_VC_B.i_p++) {
    SWC_VC_B.fio_dummy_l[SWC_VC_B.i_p] = 0;
  }

  n_segment_tail = 0U;
  for (SWC_VC_B.park_out_segment = 0; SWC_VC_B.park_out_segment < 10;
       SWC_VC_B.park_out_segment++) {
    if (fio[SWC_VC_B.park_out_segment] != 0) {
      SWC_VC_B.b_counter = (int32_T)(n_segment_tail + 1U);
      if ((uint32_T)SWC_VC_B.b_counter > 255U) {
        SWC_VC_B.b_counter = 255;
      }

      n_segment_tail = (uint8_T)SWC_VC_B.b_counter;
      SWC_VC_B.fio_dummy_l[(uint8_T)SWC_VC_B.b_counter - 1] =
        fio[SWC_VC_B.park_out_segment];
    }
  }

  for (SWC_VC_B.i_p = 0; SWC_VC_B.i_p < 10; SWC_VC_B.i_p++) {
    fio[SWC_VC_B.i_p] = SWC_VC_B.fio_dummy_l[SWC_VC_B.i_p];
  }

  SWC_VC_diff(fxo_data, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  SWC_VC_diff(fyo_data, SWC_VC_B.tmp_data_o, &SWC_VC_B.tmp_size_k);
  SWC_VC_B.dfy_size_p = 249;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 249; SWC_VC_B.b_counter++) {
    SWC_VC_B.heading_2 = -(real32_T)SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter + 1];
    SWC_VC_B.dfx_data_d[SWC_VC_B.b_counter] = SWC_VC_B.heading_2 *
      SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter];
    SWC_VC_B.dfy_data_l[SWC_VC_B.b_counter] = SWC_VC_B.heading_2 *
      SWC_VC_B.tmp_data_o[SWC_VC_B.b_counter];
  }

  SWC_VC_atan2d(SWC_VC_B.dfy_data_l, &SWC_VC_B.dfy_size_p, SWC_VC_B.dfx_data_d,
                SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  fho_data[0] = SWC_VC_B.Phi_guideline_c[0] + 180.0F;
  SWC_VC_B.park_out_segment = SWC_VC_B.tmp_size_k;
  if (0 <= SWC_VC_B.park_out_segment - 1) {
    memcpy(&fho_data[1], &SWC_VC_B.tmp_data_b[0], SWC_VC_B.park_out_segment *
           sizeof(real32_T));
  }

  SWC_VC_power(SWC_VC_B.dfx_data_d, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  SWC_VC_power(SWC_VC_B.dfy_data_l, SWC_VC_B.tmp_data_o, &SWC_VC_B.tmp_size_k);
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 249; SWC_VC_B.b_counter++) {
    SWC_VC_B.temp = fho_data[SWC_VC_B.b_counter + 1];
    SWC_VC_B.heading_2 = SWC_VC_B.temp - fho_data[SWC_VC_B.b_counter];
    if (SWC_VC_B.heading_2 > 300.0F) {
      fho_data[SWC_VC_B.b_counter + 1] = SWC_VC_B.temp - 360.0F;
    } else {
      if (SWC_VC_B.heading_2 < -300.0F) {
        fho_data[SWC_VC_B.b_counter + 1] = SWC_VC_B.temp + 360.0F;
      }
    }

    SWC_VC_B.dfx_data_d[SWC_VC_B.b_counter] =
      SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter] +
      SWC_VC_B.tmp_data_o[SWC_VC_B.b_counter];
  }

  SWC_VC_sqrt(SWC_VC_B.dfx_data_d);
  SWC_VC_diff(fho_data, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  SWC_VC_B.veh_params_size_n = SWC_VC_B.tmp_size_k;
  SWC_VC_B.park_out_segment = SWC_VC_B.tmp_size_k;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < SWC_VC_B.park_out_segment;
       SWC_VC_B.b_counter++) {
    SWC_VC_B.tmp_data_o[SWC_VC_B.b_counter] = veh_params.Ke_AP_I_VehWheelbase *
      SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter] * 3.14159274F / 180.0F;
  }

  SWC_VC_atan2d(SWC_VC_B.tmp_data_o, &SWC_VC_B.veh_params_size_n,
                SWC_VC_B.dfx_data_d, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  SWC_VC_B.fxo_12_data_p[0] = 0.0F;
  SWC_VC_B.park_out_segment = SWC_VC_B.tmp_size_k;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < SWC_VC_B.park_out_segment;
       SWC_VC_B.b_counter++) {
    SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter + 1] = plan_params->Ks *
      SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter];
  }

  *fso_size = 250;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fso_data[SWC_VC_B.b_counter] = (real32_T)
      SWC_VC_B.fgo_data_b[SWC_VC_B.b_counter] *
      SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }

  if (!car_in_ps) {
    if (!no_str_flag) {
      fso_data[0] = pii[29];
      SWC_VC_B.heading_2 = fso_data[2];
      n_segment_tail = 1U;
      if (plan_params->regen_mode != 0.0F) {
        fso_data[1] = pii[29];
        fso_data[2] = pii[29];
        SWC_VC_B.heading_2 = fso_data[3];
        n_segment_tail = 3U;
      }

      while (fabsf(fso_data[n_segment_tail - 1] - SWC_VC_B.heading_2) > 4.0F) {
        SWC_VC_B.b_counter = (int32_T)(n_segment_tail + 1U);
        if ((uint32_T)SWC_VC_B.b_counter > 255U) {
          SWC_VC_B.b_counter = 255;
        }

        n_segment_tail = (uint8_T)SWC_VC_B.b_counter;
        SWC_VC_B.alpha_clothoid_old_m = SWC_VC_B.heading_2 - fso_data[0];
        if (SWC_VC_B.alpha_clothoid_old_m < 0.0F) {
          SWC_VC_B.alpha_clothoid_old_m = -1.0F;
        } else if (SWC_VC_B.alpha_clothoid_old_m > 0.0F) {
          SWC_VC_B.alpha_clothoid_old_m = 1.0F;
        } else if (SWC_VC_B.alpha_clothoid_old_m == 0.0F) {
          SWC_VC_B.alpha_clothoid_old_m = 0.0F;
        } else {
          SWC_VC_B.alpha_clothoid_old_m = (rtNaNF);
        }

        fso_data[(uint8_T)SWC_VC_B.b_counter - 1] = fso_data[(uint8_T)
          SWC_VC_B.b_counter - 2] + 4.0F * SWC_VC_B.alpha_clothoid_old_m;
      }
    }
  } else if ((SWC_VC_B.fio_dummy_l[1] != 0) || plan_params->park_out) {
    fso_data[0] = fso_data[2];
    fso_data[1] = fso_data[2];
  } else {
    if (!plan_params->park_out) {
      sum_indx_sweeps = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]);
      SWC_VC_B.b_counter = 0;
      while (SWC_VC_B.b_counter <= sum_indx_sweeps - 1) {
        fso_data[SWC_VC_B.b_counter] = 0.0F;
        SWC_VC_B.b_counter++;
      }
    }
  }

  if (no_str_flag) {
    SWC_VC_B.b_counter = 0;
    while (SWC_VC_B.b_counter <= plan_params->num_points_no_str_para - 4) {
      fso_data[SWC_VC_B.b_counter] = SWC_VC_B.init_wheel_angle_h;
      SWC_VC_B.b_counter++;
    }

    SWC_VC_B.qY_p = plan_params->num_points_no_str_para - /*MW:OvSatOk*/ 2U;
    if (SWC_VC_B.qY_p > plan_params->num_points_no_str_para) {
      SWC_VC_B.qY_p = 0U;
    }

    SWC_VC_B.qY_tmp_c = plan_params->num_points_no_str_para - /*MW:OvSatOk*/ 3U;
    SWC_VC_B.qY_mx = SWC_VC_B.qY_tmp_c;
    if (SWC_VC_B.qY_tmp_c > plan_params->num_points_no_str_para) {
      SWC_VC_B.qY_mx = 0U;
    }

    SWC_VC_B.qY_k = SWC_VC_B.qY_tmp_c;
    if (SWC_VC_B.qY_tmp_c > plan_params->num_points_no_str_para) {
      SWC_VC_B.qY_k = 0U;
    }

    SWC_VC_B.b_counter = plan_params->num_points_no_str_para - 1;
    fso_data[(int32_T)SWC_VC_B.qY_p - 1] = (fso_data[SWC_VC_B.b_counter] -
      fso_data[(int32_T)SWC_VC_B.qY_k - 1]) / 3.0F + fso_data[(int32_T)
      SWC_VC_B.qY_mx - 1];
    SWC_VC_B.qY_p = plan_params->num_points_no_str_para - /*MW:OvSatOk*/ 1U;
    if (SWC_VC_B.qY_p > plan_params->num_points_no_str_para) {
      SWC_VC_B.qY_p = 0U;
    }

    SWC_VC_B.qY_mx = SWC_VC_B.qY_tmp_c;
    if (SWC_VC_B.qY_tmp_c > plan_params->num_points_no_str_para) {
      SWC_VC_B.qY_mx = 0U;
      SWC_VC_B.qY_tmp_c = 0U;
    }

    fso_data[(int32_T)SWC_VC_B.qY_p - 1] = (fso_data[SWC_VC_B.b_counter] -
      fso_data[(int32_T)SWC_VC_B.qY_tmp_c - 1]) * 2.0F / 3.0F + fso_data
      [(int32_T)SWC_VC_B.qY_mx - 1];
  }

  if (!car_in_ps) {
    sum_indx_sweeps = 0;
    SWC_VC_B.i_p = 0;
    while (SWC_VC_B.i_p <= sweep_count - 1) {
      SWC_VC_B.b_counter = sum_indx_sweeps + abs_NgDyBNHZ
        (SWC_VC_B.fio_dummy_l[SWC_VC_B.i_p]);
      if (SWC_VC_B.b_counter > 32767) {
        SWC_VC_B.b_counter = 32767;
      } else {
        if (SWC_VC_B.b_counter < -32768) {
          SWC_VC_B.b_counter = -32768;
        }
      }

      sum_indx_sweeps = (int16_T)SWC_VC_B.b_counter;
      SWC_VC_B.park_out_segment = (int16_T)SWC_VC_B.b_counter + 3;
      if (SWC_VC_B.park_out_segment > 32767) {
        SWC_VC_B.park_out_segment = 32767;
      }

      SWC_VC_B.temp = fso_data[SWC_VC_B.park_out_segment - 1];
      SWC_VC_B.park_out_segment = (int16_T)SWC_VC_B.b_counter + 1;
      if (SWC_VC_B.park_out_segment > 32767) {
        SWC_VC_B.park_out_segment = 32767;
      }

      fso_data[SWC_VC_B.park_out_segment - 1] = SWC_VC_B.temp;
      SWC_VC_B.b_counter = (int16_T)SWC_VC_B.b_counter + 2;
      if (SWC_VC_B.b_counter > 32767) {
        SWC_VC_B.b_counter = 32767;
      }

      fso_data[SWC_VC_B.b_counter - 1] = SWC_VC_B.temp;
      SWC_VC_B.i_p++;
    }
  } else {
    sum_indx_sweeps = 0;
    for (SWC_VC_B.i_p = 0; SWC_VC_B.i_p < 6; SWC_VC_B.i_p++) {
      SWC_VC_B.b_counter = sum_indx_sweeps + abs_NgDyBNHZ
        (SWC_VC_B.fio_dummy_l[SWC_VC_B.i_p]);
      if (SWC_VC_B.b_counter > 32767) {
        SWC_VC_B.b_counter = 32767;
      } else {
        if (SWC_VC_B.b_counter < -32768) {
          SWC_VC_B.b_counter = -32768;
        }
      }

      sum_indx_sweeps = (int16_T)SWC_VC_B.b_counter;
      SWC_VC_B.park_out_segment = (int16_T)SWC_VC_B.b_counter + 1;
      if (SWC_VC_B.park_out_segment > 32767) {
        SWC_VC_B.park_out_segment = 32767;
      }

      SWC_VC_B.b_counter = (int16_T)SWC_VC_B.b_counter + 2;
      if (SWC_VC_B.b_counter > 32767) {
        SWC_VC_B.b_counter = 32767;
      }

      fso_data[SWC_VC_B.park_out_segment - 1] = fso_data[SWC_VC_B.b_counter - 1];
    }
  }

  SWC_VC_B.init_wheel_angle_h = 3.6F * plan_params->StrRateLim_para;
  SWC_VC_diff(fso_data, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  SWC_VC_B.park_out_segment = SWC_VC_B.tmp_size_k;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < SWC_VC_B.park_out_segment;
       SWC_VC_B.b_counter++) {
    SWC_VC_B.tmp_data_o[SWC_VC_B.b_counter] =
      SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter] /
      SWC_VC_B.dfx_data_d[SWC_VC_B.b_counter];
  }

  SWC_VC_abs(SWC_VC_B.tmp_data_o, SWC_VC_B.tmp_data_b, &SWC_VC_B.tmp_size_k);
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 249; SWC_VC_B.b_counter++) {
    SWC_VC_B.dummy_data[SWC_VC_B.b_counter] = SWC_VC_B.init_wheel_angle_h /
      (SWC_VC_B.tmp_data_b[SWC_VC_B.b_counter] + 0.01F);
  }

  SWC_VC_B.dummy_data[249] = SWC_VC_B.init_wheel_angle_h / 0.01F;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fvo_data[SWC_VC_B.b_counter] = fminf(plan_params->V_max_para,
      SWC_VC_B.dummy_data[SWC_VC_B.b_counter]);
  }

  if ((!plan_params->park_out) && (*co == 1)) {
    SWC_VC_B.b_counter = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]) + 1;
    if (SWC_VC_B.b_counter > 32767) {
      SWC_VC_B.b_counter = 32767;
    }

    sum_indx_sweeps = (int16_T)SWC_VC_B.b_counter;
    if ((int16_T)SWC_VC_B.b_counter < 0) {
      sum_indx_sweeps = 0;
    }

    for (cc_i = (uint16_T)sum_indx_sweeps; cc_i < 251; cc_i++) {
      SWC_VC_B.park_out_segment = cc_i - 1;
      fvo_data[SWC_VC_B.park_out_segment] = fminf(2.0F,
        fvo_data[SWC_VC_B.park_out_segment]);
    }

    if (plan_params->CurrentSweepVeh <= 1) {
      varargin_1 = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]);
      sum_indx_sweeps = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]);
      if (sum_indx_sweeps < 0) {
        sum_indx_sweeps = 0;
      }

      if (varargin_1 > 10) {
        varargin_1 = 10;
      }

      SWC_VC_B.b_counter = varargin_1 - 1;
      if (SWC_VC_B.b_counter < -32768) {
        SWC_VC_B.b_counter = -32768;
      }

      SWC_VC_B.b_counter = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]) -
        SWC_VC_B.b_counter;
      if (SWC_VC_B.b_counter > 32767) {
        SWC_VC_B.b_counter = 32767;
      } else {
        if (SWC_VC_B.b_counter < -32768) {
          SWC_VC_B.b_counter = -32768;
        }
      }

      varargin_1 = (int16_T)SWC_VC_B.b_counter;
      if ((int16_T)SWC_VC_B.b_counter < 0) {
        varargin_1 = 0;
      }

      for (cc_i = (uint16_T)varargin_1; cc_i <= (uint16_T)sum_indx_sweeps; cc_i
           ++) {
        SWC_VC_B.park_out_segment = cc_i - 1;
        fvo_data[SWC_VC_B.park_out_segment] = fminf(3.0F,
          fvo_data[SWC_VC_B.park_out_segment]);
      }
    }

    if ((SWC_VC_B.pp_m[0] >= SWC_VC_B.front_X - 0.2F) && (SWC_VC_B.pp_m[0] <=
         SWC_VC_B.rear_X + 0.2F)) {
      sum_indx_sweeps = abs_NgDyBNHZ(SWC_VC_B.fio_dummy_l[0]);
      SWC_VC_B.b_counter = 1;
      while (SWC_VC_B.b_counter - 1 <= sum_indx_sweeps - 1) {
        SWC_VC_B.park_out_segment = (int16_T)SWC_VC_B.b_counter - 1;
        fvo_data[SWC_VC_B.park_out_segment] = fminf(2.0F,
          fvo_data[SWC_VC_B.park_out_segment]);
        SWC_VC_B.b_counter++;
      }
    }
  } else {
    if (plan_params->park_out && (*co == 1)) {
      SWC_VC_B.b_counter = 0;
      while (SWC_VC_B.b_counter <= sum_n_segment_xlast3 - 1) {
        fvo_data[SWC_VC_B.b_counter] = fminf(2.0F, fvo_data[SWC_VC_B.b_counter]);
        SWC_VC_B.b_counter++;
      }

      abs_fEIKHoQZ(SWC_VC_B.fio_dummy_l, SWC_VC_B.iv1);
      sum_indx_sweeps = sum_d5YRIYyL(SWC_VC_B.iv1);
      if (sum_indx_sweeps < 0) {
        sum_indx_sweeps = 0;
      }

      for (cc_i = (uint16_T)(sum_n_segment_xlast3 + 1); cc_i <= (uint16_T)
           sum_indx_sweeps; cc_i++) {
        fvo_data[cc_i - 1] = 7.0F;
      }
    }
  }

  abs_fEIKHoQZ(SWC_VC_B.fio_dummy_l, SWC_VC_B.iv1);
  sum_indx_sweeps = sum_d5YRIYyL(SWC_VC_B.iv1);
  if (sum_indx_sweeps < 0) {
    sum_indx_sweeps = 0;
  }

  if ((uint16_T)sum_indx_sweeps > 0) {
    for (cc_i = (uint16_T)((uint16_T)sum_indx_sweeps + 1); cc_i < 251; cc_i++) {
      SWC_VC_B.P0_idx_0_tmp = (uint16_T)sum_indx_sweeps - 1;
      SWC_VC_B.fxo_data_tmp = cc_i - 1;
      fxo_data[SWC_VC_B.fxo_data_tmp] = fxo_data[SWC_VC_B.P0_idx_0_tmp];
      fyo_data[SWC_VC_B.fxo_data_tmp] = fyo_data[SWC_VC_B.P0_idx_0_tmp];
      fho_data[SWC_VC_B.fxo_data_tmp] = fho_data[SWC_VC_B.P0_idx_0_tmp];
      fso_data[SWC_VC_B.fxo_data_tmp] = fso_data[SWC_VC_B.P0_idx_0_tmp];
      fvo_data[SWC_VC_B.fxo_data_tmp] = fvo_data[SWC_VC_B.P0_idx_0_tmp];
    }
  }

  sum_n_segment_xlast3 = 0U;
  do {
    exitg1 = 0;
    SWC_VC_B.b_counter = (int32_T)(sum_n_segment_xlast3 + 1U);
    SWC_VC_B.park_out_segment = SWC_VC_B.b_counter;
    if ((uint32_T)SWC_VC_B.b_counter > 255U) {
      SWC_VC_B.park_out_segment = 255;
    }

    if (SWC_VC_B.fio_dummy_l[SWC_VC_B.park_out_segment - 1] != 0) {
      if ((uint32_T)SWC_VC_B.b_counter > 255U) {
        SWC_VC_B.b_counter = 255;
      }

      sum_n_segment_xlast3 = (uint8_T)SWC_VC_B.b_counter;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  SWC_VC_B.b_counter = (int32_T)((uint32_T)plan_params->CurrentSweepVeh +
    sum_n_segment_xlast3);
  if ((uint32_T)SWC_VC_B.b_counter > 255U) {
    SWC_VC_B.b_counter = 255;
  }

  if (SWC_VC_B.b_counter > plan_params->max_num_sweeps) {
    *co = -7;
  }

  SWC_VC_mod(fxo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data_p,
             &SWC_VC_B.tmp_size_k);
  *fxo_size = 250;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fxo_data[SWC_VC_B.b_counter] -= SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }

  SWC_VC_mod(fyo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data_p,
             &SWC_VC_B.tmp_size_k);
  *fyo_size = 250;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fyo_data[SWC_VC_B.b_counter] -= SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }

  SWC_VC_mod(fho_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data_p,
             &SWC_VC_B.tmp_size_k);
  *fho_size = 250;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fho_data[SWC_VC_B.b_counter] -= SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }

  SWC_VC_mod(fso_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data_p,
             &SWC_VC_B.tmp_size_k);
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fso_data[SWC_VC_B.b_counter] -= SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }

  SWC_VC_mod(fvo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data_p,
             &SWC_VC_B.tmp_size_k);
  *fvo_size = 250;
  for (SWC_VC_B.b_counter = 0; SWC_VC_B.b_counter < 250; SWC_VC_B.b_counter++) {
    fvo_data[SWC_VC_B.b_counter] -= SWC_VC_B.fxo_12_data_p[SWC_VC_B.b_counter];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_renderPath_para(const real32_T pii[30], const real32_T ps[8],
  int8_T regen_dir, real32_T fxo[250], real32_T fyo[250], real32_T fho[250],
  real32_T fvo[250], real32_T fso[250], int16_T fio[10], int8_T *co)
{
  SWC_VC_B.expl_temp.vecLen_coeff_para = KeAP_vecLen_coeff_para;
  SWC_VC_B.expl_temp.V_max_para = KeAP_V_max_para;
  SWC_VC_B.expl_temp.sweep_length_lim_regen = KeAP_sweep_length_lim_regen;
  SWC_VC_B.expl_temp.StrRateLim_para = KeAP_StrRateLim_para;
  SWC_VC_B.expl_temp.str_whl_ang_para_smallPS_R_tail =
    KeAP_str_whl_ang_para_smallPS_R_tail;
  SWC_VC_B.expl_temp.str_whl_ang_para_smallPS_R5 =
    KeAP_str_whl_ang_para_smallPS_R5;
  SWC_VC_B.expl_temp.str_whl_ang_para_smallPS_R3 =
    KeAP_str_whl_ang_para_smallPS_R3;
  SWC_VC_B.expl_temp.str_whl_ang_para_smallPS_D4 =
    KeAP_str_whl_ang_para_smallPS_D4;
  SWC_VC_B.expl_temp.str_whl_ang_para_smallPS_D2 =
    KeAP_str_whl_ang_para_smallPS_D2;
  SWC_VC_B.expl_temp.str_whl_ang_para_mediumPS_R_tail =
    KeAP_str_whl_ang_para_mediumPS_R_tail;
  SWC_VC_B.expl_temp.str_whl_ang_para_mediumPS_R =
    KeAP_str_whl_ang_para_mediumPS_R;
  SWC_VC_B.expl_temp.str_whl_ang_para_mediumPS_D =
    KeAP_str_whl_ang_para_mediumPS_D;
  SWC_VC_B.expl_temp.str_whl_ang_regen = KeAP_str_whl_ang_regen;
  memcpy(&SWC_VC_B.expl_temp.str_profile_bigPS[0], (&(KeAP_str_profile_bigPS[0])),
         34U * sizeof(real32_T));
  SWC_VC_B.expl_temp.regen_mode = SWC_VC_DW.regen_mode;
  SWC_VC_B.expl_temp.PS_size_para[0] = SWC_VC_B.KeAP_PS_size_para[0];
  SWC_VC_B.expl_temp.PS_size_para[1] = SWC_VC_B.KeAP_PS_size_para[1];
  SWC_VC_B.expl_temp.PS_size_para[2] = SWC_VC_B.KeAP_PS_size_para[2];
  SWC_VC_B.expl_temp.PS_size_para[3] = SWC_VC_B.KeAP_PS_size_para[3];
  SWC_VC_B.expl_temp.PP_RES_DIST_TRAVEL = KeAP_PP_RES_DIST_TRAVEL;
  SWC_VC_B.expl_temp.park_out = SWC_VC_B.RateTransition3_i;
  SWC_VC_B.expl_temp.para_control_point_2_x_step_m =
    KeAP_para_control_point_2_x_step_m;
  SWC_VC_B.expl_temp.num_points_no_str_para = ((uint8_T)
    KeAP_num_points_no_str_para);
  SWC_VC_B.expl_temp.num_waypoints = SWC_VC_num_waypoints;
  SWC_VC_B.expl_temp.num_clothoid_waypoints_para_smallPS = ((uint8_T)
    KeAP_num_clothoid_waypoints_para_smallPS);
  SWC_VC_B.expl_temp.num_clothoid_waypoints_para_mediumPS = ((uint8_T)
    KeAP_num_clothoid_waypoints_para_mediumPS);
  SWC_VC_B.expl_temp.n_para = ((uint8_T)KeAP_n_para);
  SWC_VC_B.expl_temp.n_per_segment = SWC_VC_n_per_segment;
  SWC_VC_B.expl_temp.maxCurvature = MeAP_pm_maxCurvature;
  SWC_VC_B.expl_temp.max_num_sweeps = ((uint8_T)KeAP_max_num_sweeps);
  SWC_VC_B.expl_temp.Ks = KeAP_Ks;
  SWC_VC_B.expl_temp.Kf_para = KeAP_Kf_para;
  SWC_VC_B.expl_temp.delta_s_para = KeAP_delta_s_para;
  SWC_VC_B.expl_temp.delta_s_no_str_para = KeAP_delta_s_no_str_para;
  SWC_VC_B.expl_temp.delta_s_clothoid_para = KeAP_delta_s_clothoid_para;
  SWC_VC_B.expl_temp.CurrentSweepVeh = SWC_VC_B.UnitDelay2;
  SWC_VC_B.expl_temp.curb_over_Y_dir_para = KeAP_curb_over_Y_dir_para;
  SWC_VC_B.expl_temp.fin_loc_para_out[0] = KeAP_fin_loc_para_out[0];
  SWC_VC_B.expl_temp.break_point_para[0] = KeAP_break_point_para[0];
  SWC_VC_B.expl_temp.fin_loc_para_out[1] = KeAP_fin_loc_para_out[1];
  SWC_VC_B.expl_temp.break_point_para[1] = KeAP_break_point_para[1];
  SWC_VC_B.expl_temp.aux_turn_para_regen = KeAP_aux_turn_para_regen;
  SWC_VC_B.expl_temp.ang_threshold_regen = KeAP_ang_threshold_regen;
  SWC_VC_B.expl_temp_i.Ke_AP_I_VehRearOverhang = MeAP_m_VehRearOverhang;
  SWC_VC_B.expl_temp_i.Ke_AP_I_VehWidth = MeAP_m_VehWidth;
  SWC_VC_B.expl_temp_i.Ke_AP_I_VehWheelbase = MeAP_m_VehWheelbase;
  SWC_VC_B.expl_temp_i.Ke_AP_I_VehFrontOverhang = MeAP_m_VehFrontOverhang;
  SWC_VC_renderPath_para_common(pii, ps, regen_dir, &SWC_VC_B.expl_temp,
    SWC_VC_B.expl_temp_i, SWC_VC_B.fxoi_data_m, &SWC_VC_B.fxoi_size_n,
    SWC_VC_B.fyoi_data_c, &SWC_VC_B.fyoi_size_d, SWC_VC_B.fhoi_data_k,
    &SWC_VC_B.fhoi_size_n, SWC_VC_B.fvoi_data_c, &SWC_VC_B.fvoi_size_c,
    SWC_VC_B.fsoi_data_b, &SWC_VC_B.fsoi_size_f, fio, co);
  memcpy(&fxo[0], &SWC_VC_B.fxoi_data_m[0], 250U * sizeof(real32_T));
  memcpy(&fyo[0], &SWC_VC_B.fyoi_data_c[0], 250U * sizeof(real32_T));
  memcpy(&fho[0], &SWC_VC_B.fhoi_data_k[0], 250U * sizeof(real32_T));
  memcpy(&fvo[0], &SWC_VC_B.fvoi_data_c[0], 250U * sizeof(real32_T));
  memcpy(&fso[0], &SWC_VC_B.fsoi_data_b[0], 250U * sizeof(real32_T));
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_RENDER_PARA(void)
{
  boolean_T guard1 = false;
  guard1 = false;
  if (SWC_VC_DW.c1 < 0) {
    if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
         (SWC_VC_B.UnitDelay2 == 3))) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
      SWC_VC_B.i1 = 100 - SWC_VC_DW.c1;
      if (SWC_VC_B.i1 > 127) {
        SWC_VC_B.i1 = 127;
      }

      PP_state = (int8_T)SWC_VC_B.i1;
      PP_Abort = true;
    } else if (SWC_VC_DW.regen_mode == 1.0F) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
      PP_state = 99;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (SWC_VC_DW.c1 == 1) {
      SWC_VC_DW.c1 = 0;
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_TRANSPOSE_INV;
      PP_state = 41;
    } else {
      SWC_VC_renderPath_para(SWC_VC_DW.p_guide, SWC_VC_DW.PSL,
        SWC_VC_B.RateTransition2_j, SWC_VC_B.fx, SWC_VC_B.fy, SWC_VC_B.fh,
        SWC_VC_B.fv, SWC_VC_B.fs, SWC_VC_B.fi, &SWC_VC_DW.c1);
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_post_render_common_ml(const real32_T xx_data[], const
  real32_T yy_data[], uint8_T idx_begin, uint8_T idx_end, real32_T Kf, real32_T
  delta_s, real32_T fxo_data[], int32_T fxo_size[2], real32_T fyo_data[],
  int32_T fyo_size[2], uint8_T *total_num_idx)
{
  uint8_T i;
  uint8_T j;
  int32_T e_i;
  real32_T a;
  real32_T b_a;
  uint32_T qY;
  int32_T tmp;
  int32_T fxp_data_tmp;
  int32_T fxp_data_tmp_0;
  int32_T exitg1;
  fxo_size[0] = 1;
  fxo_size[1] = 50;
  fyo_size[0] = 1;
  fyo_size[1] = 50;
  i = 1U;
  j = 2U;
  fxp_data_tmp = idx_begin - 1;
  SWC_VC_B.fxp_data_e[0] = xx_data[fxp_data_tmp];
  SWC_VC_B.fyp_data_b[0] = yy_data[fxp_data_tmp];
  do {
    exitg1 = 0;
    qY = (uint32_T)idx_end - /*MW:OvSatOk*/ idx_begin;
    if (qY > idx_end) {
      qY = 0U;
    }

    e_i = (int32_T)(qY + 1U);
    if ((uint32_T)e_i > 255U) {
      e_i = 255;
    }

    if (j < e_i) {
      e_i = (int32_T)((uint32_T)idx_begin + j);
      fxp_data_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_data_tmp_0 = 255;
      }

      fxp_data_tmp = i - 1;
      a = xx_data[fxp_data_tmp_0 - 2] - SWC_VC_B.fxp_data_e[fxp_data_tmp];
      fxp_data_tmp_0 = e_i;
      if ((uint32_T)e_i > 255U) {
        fxp_data_tmp_0 = 255;
      }

      b_a = yy_data[fxp_data_tmp_0 - 2] - SWC_VC_B.fyp_data_b[fxp_data_tmp];
      if (sqrtf(a * a + b_a * b_a) > delta_s) {
        fxp_data_tmp_0 = (int32_T)(i + 1U);
        if ((uint32_T)fxp_data_tmp_0 > 255U) {
          fxp_data_tmp_0 = 255;
        }

        i = (uint8_T)fxp_data_tmp_0;
        tmp = e_i;
        if ((uint32_T)e_i > 255U) {
          tmp = 255;
          e_i = 255;
        }

        fxp_data_tmp = (uint8_T)fxp_data_tmp_0 - 1;
        SWC_VC_B.fxp_data_e[fxp_data_tmp] = xx_data[tmp - 2];
        SWC_VC_B.fyp_data_b[fxp_data_tmp] = yy_data[e_i - 2];
      }

      j++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  e_i = (int32_T)(i + 1U);
  if ((uint32_T)e_i > 255U) {
    e_i = 255;
  }

  fxp_data_tmp = idx_end - 1;
  fxp_data_tmp_0 = (uint8_T)e_i - 1;
  SWC_VC_B.fxp_data_e[fxp_data_tmp_0] = xx_data[fxp_data_tmp];
  SWC_VC_B.fyp_data_b[fxp_data_tmp_0] = yy_data[fxp_data_tmp];
  *total_num_idx = (uint8_T)e_i;
  if (Kf < 1.0F) {
    for (fxp_data_tmp = 0; fxp_data_tmp <= fxp_data_tmp_0; fxp_data_tmp++) {
      SWC_VC_B.xf1_data_j[fxp_data_tmp] = SWC_VC_B.fxp_data_e[fxp_data_tmp];
      SWC_VC_B.xf2_data_a[fxp_data_tmp] = SWC_VC_B.fxp_data_e[fxp_data_tmp];
      SWC_VC_B.yf1_data_f[fxp_data_tmp] = SWC_VC_B.fyp_data_b[fxp_data_tmp];
      SWC_VC_B.yf2_data_j[fxp_data_tmp] = SWC_VC_B.fyp_data_b[fxp_data_tmp];
    }

    for (fxp_data_tmp = 1; fxp_data_tmp - 1 <= (uint8_T)e_i - 3; fxp_data_tmp++)
    {
      SWC_VC_B.xf1_data_j[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf1_data_j[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fxp_data_e[fxp_data_tmp];
      SWC_VC_B.yf1_data_f[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf1_data_f[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.fyp_data_b[fxp_data_tmp];
      SWC_VC_B.xf2_data_a[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.xf2_data_a[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.xf1_data_j[fxp_data_tmp];
      SWC_VC_B.yf2_data_j[fxp_data_tmp] = (1.0F - Kf) *
        SWC_VC_B.yf2_data_j[fxp_data_tmp - 1] + Kf *
        SWC_VC_B.yf1_data_f[fxp_data_tmp];
    }

    memcpy(&SWC_VC_B.fxp_data_e[0], &SWC_VC_B.xf2_data_a[0], 50U * sizeof
           (real32_T));
    memcpy(&SWC_VC_B.fyp_data_b[0], &SWC_VC_B.yf2_data_j[0], 50U * sizeof
           (real32_T));
    i = (uint8_T)fxp_data_tmp_0;
    while (i > 1) {
      e_i = i - 1;
      SWC_VC_B.xf1_data_j[e_i] = (1.0F - Kf) * SWC_VC_B.xf1_data_j[i] +
        SWC_VC_B.fxp_data_e[e_i] * Kf;
      SWC_VC_B.yf1_data_f[e_i] = (1.0F - Kf) * SWC_VC_B.yf1_data_f[i] +
        SWC_VC_B.fyp_data_b[e_i] * Kf;
      SWC_VC_B.xf2_data_a[e_i] = (1.0F - Kf) * SWC_VC_B.xf2_data_a[i] +
        SWC_VC_B.xf1_data_j[e_i] * Kf;
      SWC_VC_B.yf2_data_j[e_i] = (1.0F - Kf) * SWC_VC_B.yf2_data_j[i] +
        SWC_VC_B.yf1_data_f[e_i] * Kf;
      i = (uint8_T)e_i;
    }

    memcpy(&SWC_VC_B.fxp_data_e[0], &SWC_VC_B.xf2_data_a[0], 50U * sizeof
           (real32_T));
    memcpy(&SWC_VC_B.fyp_data_b[0], &SWC_VC_B.yf2_data_j[0], 50U * sizeof
           (real32_T));
  }

  for (e_i = 0; e_i <= fxp_data_tmp_0; e_i++) {
    fxo_data[e_i] = SWC_VC_B.fxp_data_e[e_i];
    fyo_data[e_i] = SWC_VC_B.fyp_data_b[e_i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_renderPath_perp_common(const real32_T pii[30], const real32_T
  ps[8], const sgoad9SKTGOgw8JqT1MdSbB_SWC_VC_T *plan_params, const
  s9RMC8MZujbBaIhNLHvrkS_SWC_VC_T veh_params, real32_T fxo_data[], int32_T
  *fxo_size, real32_T fyo_data[], int32_T *fyo_size, real32_T fho_data[],
  int32_T *fho_size, real32_T fvo_data[], int32_T *fvo_size, real32_T fso_data[],
  int32_T *fso_size, int16_T fio[10], int8_T *co)
{
  boolean_T no_str_flag;
  uint8_T counter;
  int8_T direction_flag_W0;
  int8_T direction_flag_W2;
  uint8_T total_num_idx_12;
  boolean_T final_seg2_attempt;
  uint16_T b_counter;
  uint16_T l_i;
  uint8_T tb_i;
  int16_T fso_tmp;
  uint8_T fio_tmp;
  boolean_T pps;
  boolean_T pps_0;
  boolean_T guard1 = false;
  int32_T exitg1;
  int32_T exitg2;
  SWC_VC_B.pps_idx_0 = ps[0];
  SWC_VC_B.pps_idx_6 = ps[6];
  *co = 1;
  no_str_flag = true;
  SWC_VC_B.init_wheel_angle = pii[29];
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 10; SWC_VC_B.i_a++) {
    SWC_VC_B.pp_tmp = SWC_VC_B.i_a << 1;
    SWC_VC_B.pp[SWC_VC_B.pp_tmp] = pii[SWC_VC_B.i_a];
    SWC_VC_B.pp[SWC_VC_B.pp_tmp + 1] = pii[SWC_VC_B.i_a + 10];
    SWC_VC_B.Phi_guideline[SWC_VC_B.i_a] = pii[SWC_VC_B.i_a + 20];
    SWC_VC_B.n_segment[SWC_VC_B.i_a] = 50U;
    fio[SWC_VC_B.i_a] = 0;
  }

  SWC_VC_B.alpha_clothoid = -180.0F;
  if (!plan_params->park_out) {
    SWC_VC_B.des_wheel_angle = 0;
    do {
      exitg1 = 0;
      SWC_VC_B.i_a = plan_params->num_points_no_str_perp - 1;
      if (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
        SWC_VC_B.heading_angle_data[SWC_VC_B.des_wheel_angle] = 0.0F;
        SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle] = 0.0F;
        SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle] = 0.0F;
        SWC_VC_B.des_wheel_angle++;
      } else {
        exitg1 = 1;
      }
    } while (exitg1 == 0);

    SWC_VC_B.heading_angle_data[0] = pii[20] + 180.0F;
    SWC_VC_B.x_path_data[0] = SWC_VC_B.pp[0];
    SWC_VC_B.y_path_data[0] = SWC_VC_B.pp[1];
    SWC_VC_B.des_wheel_angle = 1;
    while (SWC_VC_B.des_wheel_angle - 1 <= plan_params->num_points_no_str_perp -
           2) {
      SWC_VC_B.alpha_clothoid_old = SWC_VC_B.init_wheel_angle;
      tand_brbYAlcS(&SWC_VC_B.alpha_clothoid_old);
      SWC_VC_B.heading_angle_data[SWC_VC_B.des_wheel_angle] =
        (SWC_VC_B.heading_angle_data[SWC_VC_B.des_wheel_angle - 1] * 3.14159274F
         / 180.0F + -SWC_VC_B.alpha_clothoid_old *
         plan_params->delta_s_no_str_perp / veh_params.Ke_AP_I_VehWheelbase) *
        180.0F / 3.14159274F;
      SWC_VC_B.alpha_clothoid_old =
        SWC_VC_B.heading_angle_data[SWC_VC_B.des_wheel_angle];
      cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old);
      SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle] =
        SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle - 1] -
        (-(plan_params->delta_s_no_str_perp * SWC_VC_B.alpha_clothoid_old));
      SWC_VC_B.alpha_clothoid_old =
        SWC_VC_B.heading_angle_data[SWC_VC_B.des_wheel_angle];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_old);
      SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle] =
        SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle - 1] -
        (-(plan_params->delta_s_no_str_perp * SWC_VC_B.alpha_clothoid_old));
      SWC_VC_B.des_wheel_angle++;
    }

    SWC_VC_B.X_idx_0 = SWC_VC_B.x_path_data[SWC_VC_B.i_a];
    SWC_VC_B.y_fin_no_str = SWC_VC_B.y_path_data[SWC_VC_B.i_a];
    if (plan_params->nose_in) {
      total_num_idx_12 = 0U;
      if ((!(plan_params->regen_mode != 0.0F)) || ((plan_params->CurrentSweepVeh
            == 1) || (plan_params->CurrentSweepVeh == 3) ||
           (plan_params->CurrentSweepVeh == 5))) {
        SWC_VC_B.n_segment[3] = plan_params->n_perp;
        counter = 1U;
        while (counter <= SWC_VC_B.n_segment[3]) {
          SWC_VC_B.des_wheel_angle = counter - 1;
          SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle] = ((real32_T)counter -
            1.0F) * (SWC_VC_B.pp[6] - SWC_VC_B.pp[8]) / ((real32_T)
            SWC_VC_B.n_segment[3] - 1.0F) + SWC_VC_B.pp[8];
          SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle] = ((real32_T)counter -
            1.0F) * (SWC_VC_B.pp[7] - SWC_VC_B.pp[9]) / ((real32_T)
            SWC_VC_B.n_segment[3] - 1.0F) + SWC_VC_B.pp[9];
          SWC_VC_B.pp_tmp = (int32_T)(counter + 1U);
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.pp_tmp = 255;
          }

          counter = (uint8_T)SWC_VC_B.pp_tmp;
        }

        if (!(plan_params->regen_mode != 0.0F)) {
          SWC_VC_B.pp[4] = SWC_VC_B.pp[8] + 0.75F;
          SWC_VC_B.pp[5] = SWC_VC_B.pp[9] - 8.5F;
          SWC_VC_B.Phi_guideline[2] = 125.0F;
          if (SWC_VC_B.pp[9] - 8.5F < ps[1] - 1.0F) {
            SWC_VC_B.Phi_guideline[2] = 100.0F;
          }
        } else {
          no_str_flag = false;
          SWC_VC_B.pp[4] = SWC_VC_B.pp[0];
          SWC_VC_B.pp[5] = SWC_VC_B.pp[1];
          SWC_VC_B.Phi_guideline[2] = pii[20];
        }

        SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[4] - SWC_VC_B.pp[6];
        SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[5] - SWC_VC_B.pp[7];
        SWC_VC_B.vectorLength = pii[23];
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = pii[23];
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W0 = 1;
        } else {
          direction_flag_W0 = -1;
        }

        SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W2 = 1;
        } else {
          direction_flag_W2 = -1;
        }

        SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
          fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
        SWC_VC_B.line_direction_idx_0 = pii[23];
        cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
        SWC_VC_B.alpha_clothoid = pii[23];
        sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
          SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
        SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
          SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
        SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[2];
        cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
        SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[2];
        sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
        SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 * 0.001F *
          (real32_T)direction_flag_W2;
        SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.alpha_clothoid *
          0.001F * (real32_T)direction_flag_W2;
        SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
        SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
        SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                            SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
        SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
        SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
        SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
        SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                            SWC_VC_B.line_direction_idx_1) -
          SWC_VC_B.vectorLength;
        SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
        SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
          plan_params->delta_s_perp);
        if (SWC_VC_B.W2_idx_0 < 256.0F) {
          if (SWC_VC_B.W2_idx_0 >= 0.0F) {
            fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
          SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old,
          SWC_VC_B.x_out2_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out2_data,
          SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[1]);
        SWC_VC_B.des_wheel_angle = 0;
        while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[1] - 1) {
          SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle] += SWC_VC_B.pp[6];
          SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle] += SWC_VC_B.pp[7];
          SWC_VC_B.des_wheel_angle++;
        }

        SWC_VC_B.des_wheel_angle = 0;
        while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[3] - 2) {
          fxo_data[SWC_VC_B.des_wheel_angle] =
            SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.des_wheel_angle] =
            SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.des_wheel_angle++;
        }

        counter = 1U;
        SWC_VC_B.yb_i = (int32_T)(((real32_T)sum_cZvgqUmQ(&SWC_VC_B.n_segment[2])
          - 1.0F) + (1.0F - (real32_T)plan_params->n_perp));
        SWC_VC_B.g_i = 0;
        while (SWC_VC_B.g_i <= SWC_VC_B.yb_i - 1) {
          SWC_VC_B.des_wheel_angle = counter - 1;
          SWC_VC_B.dc_i = (int32_T)((real32_T)SWC_VC_B.n_segment[3] + (real32_T)
            SWC_VC_B.g_i) - 1;
          fxo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.pp_tmp = (int32_T)(counter + 1U);
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.pp_tmp = 255;
          }

          counter = (uint8_T)SWC_VC_B.pp_tmp;
          SWC_VC_B.g_i++;
        }

        SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[2]));
        if (SWC_VC_B.dd < 256.0) {
          if (SWC_VC_B.dd >= 0.0) {
            fio_tmp = (uint8_T)SWC_VC_B.dd;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_B.qY_j = fio_tmp - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > fio_tmp) {
          SWC_VC_B.qY_j = 0U;
        }

        SWC_VC_post_render_common(fxo_data, fyo_data, (uint8_T)SWC_VC_B.qY_j,
          plan_params->Kf_perp_single_sweep, plan_params->delta_s_perp,
          SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data,
          SWC_VC_B.y_out2_size, &total_num_idx_12);
        SWC_VC_B.qY_tmp_d = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
        SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
        if (SWC_VC_B.qY_tmp_d > total_num_idx_12) {
          SWC_VC_B.qY_j = 0U;
          SWC_VC_B.qY_tmp_d = 0U;
        }

        SWC_VC_B.des_wheel_angle = total_num_idx_12 - 1;
        SWC_VC_B.alpha_clothoid = rt_atan2f_snf
          (SWC_VC_B.fyo_34_data[SWC_VC_B.des_wheel_angle] -
           SWC_VC_B.fyo_34_data[(int32_T)SWC_VC_B.qY_j - 1],
           SWC_VC_B.fxo_34_data[SWC_VC_B.des_wheel_angle] -
           SWC_VC_B.fxo_34_data[(int32_T)SWC_VC_B.qY_tmp_d - 1]) * 57.2957802F;
      }

      if (!(plan_params->regen_mode != 0.0F)) {
        SWC_VC_B.n_segment[0] = plan_params->num_points_no_str_perp;
        SWC_VC_B.pp_tmp = total_num_idx_12 - 1;
        SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.fxo_34_data[SWC_VC_B.pp_tmp]
          - SWC_VC_B.x_path_data[SWC_VC_B.i_a];
        SWC_VC_B.alpha_clothoid_old = SWC_VC_B.fyo_34_data[SWC_VC_B.pp_tmp] -
          SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        SWC_VC_B.vectorLength = SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] -
          180.0F;
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.heading_angle_data[SWC_VC_B.i_a]
          - 180.0F;
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W0 = 1;
        } else {
          direction_flag_W0 = -1;
        }

        SWC_VC_B.vectorLength = SWC_VC_B.alpha_clothoid;
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.alpha_clothoid;
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W2 = 1;
        } else {
          direction_flag_W2 = -1;
        }

        SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
          fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.heading_angle_data[SWC_VC_B.i_a]
          - 180.0F;
        cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
        SWC_VC_B.pps_idx_0 = SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] - 180.0F;
        sind_7is3Ljjc(&SWC_VC_B.pps_idx_0);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
          SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
        SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
          SWC_VC_B.pps_idx_0 * (real32_T)direction_flag_W0;
        SWC_VC_B.pps_idx_0 = SWC_VC_B.alpha_clothoid;
        cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
        sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
        SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
          (real32_T)direction_flag_W2;
        SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.alpha_clothoid *
          (real32_T)direction_flag_W2;
        SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
        SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
        SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                            SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
        SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
        SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
        SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
        SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                            SWC_VC_B.line_direction_idx_1) -
          SWC_VC_B.vectorLength;
        SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
        SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
          plan_params->delta_s_perp);
        if (SWC_VC_B.W2_idx_0 < 256.0F) {
          if (SWC_VC_B.W2_idx_0 >= 0.0F) {
            fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
          SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old,
          SWC_VC_B.x_out2_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out2_data,
          SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[1]);
        SWC_VC_B.des_wheel_angle = 0;
        while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[1] - 1) {
          SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.x_path_data[SWC_VC_B.i_a];
          SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.y_path_data[SWC_VC_B.i_a];
          SWC_VC_B.des_wheel_angle++;
        }

        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[0] - 1) {
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_path_data[SWC_VC_B.i_a];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_path_data[SWC_VC_B.i_a];
          SWC_VC_B.i_a++;
        }

        counter = 2U;
        SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[0]) - 1.0);
        if (SWC_VC_B.dd < 256.0) {
          if (SWC_VC_B.dd >= 0.0) {
            fio_tmp = (uint8_T)SWC_VC_B.dd;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_B.i_a = (int32_T)(plan_params->num_points_no_str_perp + 1U);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        for (tb_i = (uint8_T)SWC_VC_B.i_a; tb_i <= fio_tmp; tb_i++) {
          SWC_VC_B.des_wheel_angle = counter - 1;
          SWC_VC_B.dc_i = tb_i - 1;
          fxo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.i_a = (int32_T)(counter + 1U);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          counter = (uint8_T)SWC_VC_B.i_a;
        }

        SWC_VC_B.des_wheel_angle = (int32_T)((uint32_T)
          plan_params->num_points_no_str_perp + SWC_VC_B.n_segment[1]);
        if ((uint32_T)SWC_VC_B.des_wheel_angle > 255U) {
          SWC_VC_B.des_wheel_angle = 255;
        }

        SWC_VC_B.qY_j = SWC_VC_B.des_wheel_angle - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > (uint32_T)SWC_VC_B.des_wheel_angle) {
          SWC_VC_B.qY_j = 0U;
        }

        SWC_VC_post_render_common_ml(fxo_data, fyo_data,
          plan_params->num_points_no_str_perp, (uint8_T)SWC_VC_B.qY_j,
          plan_params->Kf_perp_single_sweep, plan_params->delta_s_perp,
          SWC_VC_B.x_out_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data,
          SWC_VC_B.y_out2_size, &counter);
        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= counter - 1) {
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_out_data[SWC_VC_B.i_a];
          SWC_VC_B.fgo_data[SWC_VC_B.i_a] = -1;
          SWC_VC_B.i_a++;
        }

        fio[0] = (int16_T)-counter;
        SWC_VC_B.qY_j = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > total_num_idx_12) {
          SWC_VC_B.qY_j = 0U;
        }

        b_counter = (uint16_T)SWC_VC_B.qY_j;
        SWC_VC_B.des_wheel_angle = counter + total_num_idx_12;
        SWC_VC_B.qY_j = SWC_VC_B.des_wheel_angle - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > (uint32_T)SWC_VC_B.des_wheel_angle) {
          SWC_VC_B.qY_j = 0U;
        }

        for (l_i = (uint16_T)(counter + 1); l_i <= (uint16_T)SWC_VC_B.qY_j; l_i
             ++) {
          SWC_VC_B.des_wheel_angle = b_counter - 1;
          SWC_VC_B.dc_i = l_i - 1;
          fxo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.fxo_34_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.fyo_34_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.fgo_data[SWC_VC_B.dc_i] = 1;
          SWC_VC_B.qY_c = b_counter - /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_c > b_counter) {
            SWC_VC_B.qY_c = 0U;
          }

          b_counter = (uint16_T)SWC_VC_B.qY_c;
        }

        fio[1] = (int16_T)SWC_VC_B.pp_tmp;
      } else if ((plan_params->regen_mode != 0.0F) &&
                 ((plan_params->CurrentSweepVeh == 1) ||
                  (plan_params->CurrentSweepVeh == 3) ||
                  (plan_params->CurrentSweepVeh == 5))) {
        b_counter = total_num_idx_12;
        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= total_num_idx_12 - 1) {
          SWC_VC_B.des_wheel_angle = b_counter - 1;
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.fxo_34_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.fyo_34_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.fgo_data[SWC_VC_B.i_a] = 1;
          SWC_VC_B.qY_j = b_counter - /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_j > b_counter) {
            SWC_VC_B.qY_j = 0U;
          }

          b_counter = (uint16_T)SWC_VC_B.qY_j;
          SWC_VC_B.i_a++;
        }

        fio[0] = total_num_idx_12;
      } else {
        if ((plan_params->regen_mode != 0.0F) && ((plan_params->CurrentSweepVeh ==
              2) || (plan_params->CurrentSweepVeh == 4) ||
             (plan_params->CurrentSweepVeh == 6))) {
          no_str_flag = false;
          SWC_VC_B.heading_angle_data[0] = pii[20] + 180.0F;
          SWC_VC_B.x_path_data[0] = SWC_VC_B.pp[0];
          SWC_VC_B.y_path_data[0] = SWC_VC_B.pp[1];
          if (SWC_VC_B.pp[0] <= SWC_VC_B.pp[8]) {
            SWC_VC_B.des_wheel_angle = 30;
          } else if (SWC_VC_B.pp[0] <= SWC_VC_B.pp[8] + 0.1F) {
            SWC_VC_B.des_wheel_angle = 20;
          } else if (SWC_VC_B.pp[0] <= SWC_VC_B.pp[8] + 0.2F) {
            SWC_VC_B.des_wheel_angle = 10;
          } else {
            SWC_VC_B.des_wheel_angle = 0;
          }

          SWC_VC_B.alpha_clothoid_old = 1.0F;
          do {
            exitg1 = 0;
            SWC_VC_B.i_a = (int32_T)SWC_VC_B.alpha_clothoid_old;
            if ((SWC_VC_B.i_a <= plan_params->n_perp) &&
                ((SWC_VC_B.alpha_clothoid_old <= 3.0F) ||
                 (SWC_VC_B.heading_angle_data[SWC_VC_B.i_a - 1] >= -90.0F))) {
              SWC_VC_B.alpha_clothoid_old++;
              SWC_VC_B.dd = SWC_VC_B.des_wheel_angle;
              tand_cOkjHg6k(&SWC_VC_B.dd);
              SWC_VC_B.i_a = (int32_T)SWC_VC_B.alpha_clothoid_old - 1;
              SWC_VC_B.pp_tmp = (int32_T)SWC_VC_B.alpha_clothoid_old - 2;
              SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] =
                (SWC_VC_B.heading_angle_data[SWC_VC_B.pp_tmp] * 3.14159274F /
                 180.0F + -(real32_T)SWC_VC_B.dd *
                 plan_params->delta_s_nose_in_regen /
                 veh_params.Ke_AP_I_VehWheelbase) * 180.0F / 3.14159274F;
              SWC_VC_B.line_direction_idx_0_tmp =
                SWC_VC_B.heading_angle_data[SWC_VC_B.i_a];
              cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0_tmp);
              SWC_VC_B.x_path_data[SWC_VC_B.i_a] =
                SWC_VC_B.x_path_data[SWC_VC_B.pp_tmp] -
                (-(plan_params->delta_s_nose_in_regen *
                   SWC_VC_B.line_direction_idx_0_tmp));
              SWC_VC_B.line_direction_idx_0_tmp =
                SWC_VC_B.heading_angle_data[SWC_VC_B.i_a];
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp);
              SWC_VC_B.y_path_data[SWC_VC_B.i_a] =
                SWC_VC_B.y_path_data[SWC_VC_B.pp_tmp] -
                (-(plan_params->delta_s_nose_in_regen *
                   SWC_VC_B.line_direction_idx_0_tmp));
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          if (SWC_VC_B.alpha_clothoid_old < 256.0F) {
            fio_tmp = (uint8_T)SWC_VC_B.alpha_clothoid_old;
            SWC_VC_B.n_segment[0] = (uint8_T)SWC_VC_B.alpha_clothoid_old;
          } else {
            fio_tmp = MAX_uint8_T;
            SWC_VC_B.n_segment[0] = MAX_uint8_T;
          }

          SWC_VC_B.des_wheel_angle = 0;
          do {
            exitg1 = 0;
            SWC_VC_B.i_a = fio_tmp - 1;
            if (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
              fxo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle];
              fyo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle];
              SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = -1;
              SWC_VC_B.des_wheel_angle++;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          fio[0] = (int16_T)-fio_tmp;
          SWC_VC_B.n_segment[3] = plan_params->n_perp;
          counter = 1U;
          while (counter <= SWC_VC_B.n_segment[3]) {
            SWC_VC_B.des_wheel_angle = counter - 1;
            SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.pp[6] -
              ((real32_T)counter - 1.0F) * (SWC_VC_B.pp[6] - SWC_VC_B.pp[8]) /
              ((real32_T)SWC_VC_B.n_segment[3] - 1.0F);
            SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.pp[7] -
              ((real32_T)counter - 1.0F) * (SWC_VC_B.pp[7] - SWC_VC_B.pp[9]) /
              ((real32_T)SWC_VC_B.n_segment[3] - 1.0F);
            SWC_VC_B.pp_tmp = (int32_T)(counter + 1U);
            if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
              SWC_VC_B.pp_tmp = 255;
            }

            counter = (uint8_T)SWC_VC_B.pp_tmp;
          }

          SWC_VC_B.pp_tmp = SWC_VC_B.n_segment[0] - 1;
          SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[6] -
            SWC_VC_B.x_path_data[SWC_VC_B.i_a];
          SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[7] -
            SWC_VC_B.y_path_data[SWC_VC_B.i_a];
          SWC_VC_B.vectorLength = SWC_VC_B.heading_angle_data[SWC_VC_B.pp_tmp] -
            180.0F;
          cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
          SWC_VC_B.line_direction_idx_0 =
            SWC_VC_B.heading_angle_data[SWC_VC_B.pp_tmp] - 180.0F;
          sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
          if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
              SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
              0.0F) {
            direction_flag_W0 = 1;
          } else {
            direction_flag_W0 = -1;
          }

          SWC_VC_B.vectorLength = pii[23];
          cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
          SWC_VC_B.line_direction_idx_0 = pii[23];
          sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
          if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
              SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
              0.0F) {
            direction_flag_W2 = 1;
          } else {
            direction_flag_W2 = -1;
          }

          SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
            fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
          SWC_VC_B.line_direction_idx_0 =
            SWC_VC_B.heading_angle_data[SWC_VC_B.pp_tmp] - 180.0F;
          cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
          SWC_VC_B.alpha_clothoid = SWC_VC_B.heading_angle_data[SWC_VC_B.pp_tmp]
            - 180.0F;
          sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
          SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
            SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
          SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
            SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
          SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[3];
          cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
          SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[3];
          sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
          SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
            (real32_T)direction_flag_W2;
          SWC_VC_B.vectorLength = SWC_VC_B.vectorLength *
            SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W2;
          SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
          SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
          SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                              SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
          SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
          SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
          SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
          SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                              SWC_VC_B.line_direction_idx_1) -
            SWC_VC_B.vectorLength;
          SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
          SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
            plan_params->delta_s_perp);
          if (SWC_VC_B.W2_idx_0 < 256.0F) {
            if (SWC_VC_B.W2_idx_0 >= 0.0F) {
              counter = (uint8_T)SWC_VC_B.W2_idx_0;
            } else {
              counter = 0U;
            }
          } else {
            counter = MAX_uint8_T;
          }

          SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
            SWC_VC_B.P3_m, SWC_VC_B.W2, counter, &SWC_VC_B.alpha_clothoid_old,
            SWC_VC_B.x_out_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data,
            SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[2]);
          SWC_VC_B.des_wheel_angle = 0;
          while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[2] - 1) {
            SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] +=
              SWC_VC_B.x_path_data[SWC_VC_B.i_a];
            SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] +=
              SWC_VC_B.y_path_data[SWC_VC_B.pp_tmp];
            SWC_VC_B.des_wheel_angle++;
          }

          if (SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) {
            *co = -24;
          }

          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[2] - 2) {
            SWC_VC_B.des_wheel_angle = fio_tmp + SWC_VC_B.i_a;
            fxo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.x_out_data[SWC_VC_B.i_a + 1];
            fyo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.y_out_data[SWC_VC_B.i_a + 1];
            SWC_VC_B.i_a++;
          }

          SWC_VC_B.i_a = 1;
          while (SWC_VC_B.i_a - 1 <= SWC_VC_B.n_segment[3] - 2) {
            SWC_VC_B.des_wheel_angle = ((fio_tmp + SWC_VC_B.n_segment[2]) +
              SWC_VC_B.i_a) - 2;
            fxo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.x_out4_data[SWC_VC_B.i_a];
            fyo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.y_out4_data[SWC_VC_B.i_a];
            SWC_VC_B.i_a++;
          }

          SWC_VC_B.i_a = (int32_T)(fio_tmp + 1U);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.pp_tmp = (int32_T)((uint32_T)fio_tmp + SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.pp_tmp = 255;
          }

          SWC_VC_B.des_wheel_angle = (int32_T)((uint32_T)SWC_VC_B.pp_tmp +
            plan_params->n_perp);
          if ((uint32_T)SWC_VC_B.des_wheel_angle > 255U) {
            SWC_VC_B.des_wheel_angle = 255;
          }

          SWC_VC_B.qY_j = SWC_VC_B.des_wheel_angle - /*MW:OvSatOk*/ 2U;
          if (SWC_VC_B.qY_j > (uint32_T)SWC_VC_B.des_wheel_angle) {
            SWC_VC_B.qY_j = 0U;
          }

          SWC_VC_post_render_common_m(fxo_data, fyo_data, (uint8_T)SWC_VC_B.i_a,
            (uint8_T)SWC_VC_B.qY_j, plan_params->Kf_perp,
            plan_params->delta_s_perp, SWC_VC_B.fxo_34_data,
            SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data, SWC_VC_B.y_out2_size,
            &counter);
          SWC_VC_B.qY_j = counter - /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_j > counter) {
            SWC_VC_B.qY_j = 0U;
          }

          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= (uint8_T)SWC_VC_B.qY_j - 2) {
            SWC_VC_B.des_wheel_angle = fio_tmp + SWC_VC_B.i_a;
            fxo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.fxo_34_data[SWC_VC_B.i_a + 1];
            fyo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.fyo_34_data[SWC_VC_B.i_a + 1];
            SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = 1;
            SWC_VC_B.i_a++;
          }

          fio[1] = (uint8_T)SWC_VC_B.qY_j;
        }
      }
    } else {
      guard1 = false;
      if ((fabsf(ps[1] - SWC_VC_B.pp[1]) >=
           plan_params->single_sweep_start_min_lat_dist_m) && (fabsf(ps[0] -
            SWC_VC_B.pp[0]) >= plan_params->single_sweep_start_min_lon_dist_m))
      {
        SWC_VC_B.alpha_clothoid_old = 0.0F;
        cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old);
        SWC_VC_B.alpha_clothoid_old = SWC_VC_B.y_path_data[SWC_VC_B.i_a] +
          plan_params->turn_radius_single_sweep_perp *
          SWC_VC_B.alpha_clothoid_old;
        SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.alpha_clothoid_old -
          SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        if (SWC_VC_B.line_direction_idx_0_tmp < 0.0F) {
          SWC_VC_B.line_direction_idx_0_tmp = -1.0F;
        } else if (SWC_VC_B.line_direction_idx_0_tmp > 0.0F) {
          SWC_VC_B.line_direction_idx_0_tmp = 1.0F;
        } else if (SWC_VC_B.line_direction_idx_0_tmp == 0.0F) {
          SWC_VC_B.line_direction_idx_0_tmp = 0.0F;
        } else {
          SWC_VC_B.line_direction_idx_0_tmp = (rtNaNF);
        }

        SWC_VC_B.W2_idx_0 = (SWC_VC_B.pp[10] - SWC_VC_B.x_path_data[SWC_VC_B.i_a])
          / 3.0F + SWC_VC_B.x_path_data[SWC_VC_B.i_a];
        SWC_VC_B.vectorLength =
          plan_params->single_sweep_control_point_2_y_offset *
          SWC_VC_B.line_direction_idx_0_tmp + SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.pp[10] +
          plan_params->single_sweep_control_point_3_x_offset;
        SWC_VC_B.line_direction_idx_1 =
          plan_params->single_sweep_control_point_3_y_offset *
          SWC_VC_B.line_direction_idx_0_tmp + SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        SWC_VC_B.P3[0] = SWC_VC_B.pp[10] - SWC_VC_B.x_path_data[SWC_VC_B.i_a];
        SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0 - SWC_VC_B.x_path_data[SWC_VC_B.i_a];
        SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0 -
          SWC_VC_B.W2_idx_0;
        SWC_VC_B.P3_m[0] = SWC_VC_B.pp[10] - SWC_VC_B.line_direction_idx_0;
        SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old -
          SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        SWC_VC_B.W2[1] = SWC_VC_B.vectorLength -
          SWC_VC_B.y_path_data[SWC_VC_B.i_a];
        SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1 -
          SWC_VC_B.vectorLength;
        SWC_VC_B.P3_m[1] = SWC_VC_B.alpha_clothoid_old -
          SWC_VC_B.line_direction_idx_1;
        SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
          plan_params->delta_s_perp);
        if (SWC_VC_B.W2_idx_0 < 256.0F) {
          if (SWC_VC_B.W2_idx_0 >= 0.0F) {
            fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_Bezier_path_function_common(SWC_VC_B.W2, SWC_VC_B.line_direction,
          SWC_VC_B.P3_m, fio_tmp, &SWC_VC_B.alpha_clothoid_old,
          SWC_VC_B.x_out_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data,
          SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[2]);
        SWC_VC_B.des_wheel_angle = 0;
        while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[2] - 1) {
          SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.x_path_data[SWC_VC_B.i_a];
          SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.y_path_data[SWC_VC_B.i_a];
          SWC_VC_B.des_wheel_angle++;
        }

        if (SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) {
          guard1 = true;
        } else {
          SWC_VC_B.n_segment[3] = plan_params->n_perp;
          counter = 1U;
          while (counter <= SWC_VC_B.n_segment[3]) {
            SWC_VC_B.des_wheel_angle = counter - 1;
            SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.pp[10];
            SWC_VC_B.pp_tmp = SWC_VC_B.n_segment[2] - 1;
            SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle] = (SWC_VC_B.pp[11] -
              SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp]) * ((real32_T)counter - 1.0F)
              / ((real32_T)SWC_VC_B.n_segment[3] - 1.0F) +
              SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp];
            SWC_VC_B.pp_tmp = (int32_T)(counter + 1U);
            if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
              SWC_VC_B.pp_tmp = 255;
            }

            counter = (uint8_T)SWC_VC_B.pp_tmp;
          }

          SWC_VC_B.pp_tmp = (int32_T)(plan_params->num_points_no_str_perp + 50U);
          SWC_VC_B.des_wheel_angle = SWC_VC_B.pp_tmp;
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.des_wheel_angle = 255;
          }

          SWC_VC_B.des_wheel_angle = (int32_T)((uint32_T)
            (SWC_VC_B.des_wheel_angle - 1) + SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.des_wheel_angle > 255U) {
            SWC_VC_B.des_wheel_angle = 255;
          }

          SWC_VC_B.des_wheel_angle = (int32_T)((uint32_T)
            (SWC_VC_B.des_wheel_angle - 1) + plan_params->n_perp);
          if ((uint32_T)SWC_VC_B.des_wheel_angle > 255U) {
            SWC_VC_B.des_wheel_angle = 255;
          }

          fio[0] = (int16_T)(1 - SWC_VC_B.des_wheel_angle);
          SWC_VC_B.des_wheel_angle = 0;
          while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
            fxo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle];
            fyo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle];
            SWC_VC_B.des_wheel_angle++;
          }

          SWC_VC_B.i_a = SWC_VC_B.pp_tmp;
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.i_a = 255;
          }

          counter = (uint8_T)(SWC_VC_B.i_a - 1);
          SWC_VC_B.i_a = (int32_T)(plan_params->num_points_no_str_perp + 1U);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          for (fio_tmp = (uint8_T)SWC_VC_B.i_a; fio_tmp <= counter; fio_tmp++) {
            SWC_VC_B.des_wheel_angle = fio_tmp - 1;
            fxo_data[SWC_VC_B.des_wheel_angle] = 0.0F;
            fyo_data[SWC_VC_B.des_wheel_angle] = 0.0F;
          }

          counter = 1U;
          SWC_VC_B.i_a = SWC_VC_B.pp_tmp;
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.i_a = (int32_T)((uint32_T)(SWC_VC_B.i_a - 1) +
            SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          fio_tmp = (uint8_T)(SWC_VC_B.i_a - 1);
          SWC_VC_B.i_a = SWC_VC_B.pp_tmp;
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.i_a = 255;
          }

          for (total_num_idx_12 = (uint8_T)SWC_VC_B.i_a; total_num_idx_12 <=
               fio_tmp; total_num_idx_12++) {
            SWC_VC_B.i_a = (int32_T)(counter + 1U);
            if ((uint32_T)SWC_VC_B.i_a > 255U) {
              SWC_VC_B.i_a = 255;
            }

            counter = (uint8_T)SWC_VC_B.i_a;
            SWC_VC_B.des_wheel_angle = (uint8_T)SWC_VC_B.i_a - 1;
            SWC_VC_B.dc_i = total_num_idx_12 - 1;
            fxo_data[SWC_VC_B.dc_i] =
              SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle];
            fyo_data[SWC_VC_B.dc_i] =
              SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle];
          }

          counter = 1U;
          SWC_VC_B.i_a = SWC_VC_B.pp_tmp;
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.i_a = (int32_T)((uint32_T)(SWC_VC_B.i_a - 1) +
            SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.i_a = (int32_T)((uint32_T)(SWC_VC_B.i_a - 1) +
            plan_params->n_perp);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          fio_tmp = (uint8_T)(SWC_VC_B.i_a - 1);
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.pp_tmp = 255;
          }

          SWC_VC_B.i_a = (int32_T)((uint32_T)(SWC_VC_B.pp_tmp - 1) +
            SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          for (total_num_idx_12 = (uint8_T)SWC_VC_B.i_a; total_num_idx_12 <=
               fio_tmp; total_num_idx_12++) {
            SWC_VC_B.i_a = (int32_T)(counter + 1U);
            if ((uint32_T)SWC_VC_B.i_a > 255U) {
              SWC_VC_B.i_a = 255;
            }

            counter = (uint8_T)SWC_VC_B.i_a;
            SWC_VC_B.des_wheel_angle = (uint8_T)SWC_VC_B.i_a - 1;
            SWC_VC_B.dc_i = total_num_idx_12 - 1;
            fxo_data[SWC_VC_B.dc_i] =
              SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle];
            fyo_data[SWC_VC_B.dc_i] =
              SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle];
          }

          SWC_VC_post_render_common(fxo_data, fyo_data, (uint8_T)-fio[0],
            plan_params->Kf_perp_single_sweep, plan_params->delta_s_perp,
            SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data,
            SWC_VC_B.y_out2_size, &counter);
          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= counter - 1) {
            fxo_data[SWC_VC_B.i_a] = SWC_VC_B.fxo_34_data[SWC_VC_B.i_a];
            fyo_data[SWC_VC_B.i_a] = SWC_VC_B.fyo_34_data[SWC_VC_B.i_a];
            SWC_VC_B.fgo_data[SWC_VC_B.i_a] = -1;
            SWC_VC_B.i_a++;
          }

          fio[0] = (int16_T)-counter;
        }
      } else {
        guard1 = true;
      }

      if (guard1) {
        if ((SWC_VC_B.pp[0] != SWC_VC_B.pp[2]) || (SWC_VC_B.pp[1] !=
             SWC_VC_B.pp[3])) {
          if ((SWC_VC_B.x_path_data[SWC_VC_B.i_a] != SWC_VC_B.pp[2]) ||
              (SWC_VC_B.y_path_data[SWC_VC_B.i_a] != SWC_VC_B.pp[3])) {
            do {
              exitg1 = 0;
              SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[2] -
                SWC_VC_B.X_idx_0;
              SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[3] -
                SWC_VC_B.y_fin_no_str;
              SWC_VC_B.vectorLength = SWC_VC_B.heading_angle_data[SWC_VC_B.i_a]
                - 180.0F;
              cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
              SWC_VC_B.line_direction_idx_0 =
                SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] - 180.0F;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
              if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                  SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                  0.0F) {
                direction_flag_W0 = 1;
              } else {
                direction_flag_W0 = -1;
              }

              SWC_VC_B.vectorLength = pii[21];
              cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
              SWC_VC_B.line_direction_idx_0 = pii[21];
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
              if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                  SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                  0.0F) {
                direction_flag_W2 = 1;
              } else {
                direction_flag_W2 = -1;
              }

              SWC_VC_B.vectorLength = fmaxf(fabsf
                (SWC_VC_B.line_direction_idx_0_tmp), fabsf
                (SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
              SWC_VC_B.line_direction_idx_0 =
                SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] - 180.0F;
              cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
              SWC_VC_B.line_direction_idx_1 =
                SWC_VC_B.heading_angle_data[SWC_VC_B.i_a] - 180.0F;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_1);
              SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
                SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
              SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
                SWC_VC_B.line_direction_idx_1 * (real32_T)direction_flag_W0;
              SWC_VC_B.W2_idx_0 = pii[21];
              cosd_KZN3FnAl(&SWC_VC_B.W2_idx_0);
              SWC_VC_B.Phi_idx_0 = pii[21];
              sind_7is3Ljjc(&SWC_VC_B.Phi_idx_0);
              SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.W2_idx_0 *
                (real32_T)direction_flag_W2;
              SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.Phi_idx_0
                * (real32_T)direction_flag_W2;
              SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
              SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
              SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                                  SWC_VC_B.line_direction_idx_0) -
                SWC_VC_B.W2_idx_0;
              SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
              SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
              SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
              SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                                  SWC_VC_B.line_direction_idx_1) -
                SWC_VC_B.vectorLength;
              SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
              SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
                plan_params->delta_s_perp);
              if (SWC_VC_B.W2_idx_0 < 256.0F) {
                if (SWC_VC_B.W2_idx_0 >= 0.0F) {
                  fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
                } else {
                  fio_tmp = 0U;
                }
              } else {
                fio_tmp = MAX_uint8_T;
              }

              SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
                SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp,
                &SWC_VC_B.alpha_clothoid_old, SWC_VC_B.x_out_data,
                SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data, SWC_VC_B.y_out2_size,
                &SWC_VC_B.n_segment[0]);
              SWC_VC_B.des_wheel_angle = 0;
              while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[0] - 1) {
                SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] +=
                  SWC_VC_B.X_idx_0;
                SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] +=
                  SWC_VC_B.y_fin_no_str;
                SWC_VC_B.des_wheel_angle++;
              }

              if ((SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) &&
                  no_str_flag) {
                no_str_flag = false;
                SWC_VC_B.X_idx_0 = SWC_VC_B.pp[0];
                SWC_VC_B.y_fin_no_str = SWC_VC_B.pp[1];
              } else {
                exitg1 = 1;
              }
            } while (exitg1 == 0);

            if (SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) {
              *co = -21;
            }
          }

          if (no_str_flag) {
            if ((SWC_VC_B.X_idx_0 != SWC_VC_B.pp[2]) || (SWC_VC_B.y_fin_no_str
                 != SWC_VC_B.pp[3])) {
              if (SWC_VC_B.n_segment[0] == 0) {
                SWC_VC_B.n_segment[0] = plan_params->num_points_no_str_perp;
                SWC_VC_B.i_a = 0;
                while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[0] - 1) {
                  fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_path_data[SWC_VC_B.i_a];
                  fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_path_data[SWC_VC_B.i_a];
                  SWC_VC_B.i_a++;
                }
              } else {
                SWC_VC_B.pp_tmp = (int32_T)((uint32_T)SWC_VC_B.n_segment[0] +
                  plan_params->num_points_no_str_perp);
                if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
                  SWC_VC_B.pp_tmp = 255;
                }

                SWC_VC_B.n_segment[0] = (uint8_T)SWC_VC_B.pp_tmp;
                SWC_VC_B.des_wheel_angle = 0;
                while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
                  fxo_data[SWC_VC_B.des_wheel_angle] =
                    SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle];
                  fyo_data[SWC_VC_B.des_wheel_angle] =
                    SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle];
                  SWC_VC_B.des_wheel_angle++;
                }

                SWC_VC_B.i_a = (int32_T)(plan_params->num_points_no_str_perp +
                  1U);
                if ((uint32_T)SWC_VC_B.i_a > 255U) {
                  SWC_VC_B.i_a = 255;
                }

                for (counter = (uint8_T)SWC_VC_B.i_a; counter <= (uint8_T)
                     SWC_VC_B.pp_tmp; counter++) {
                  SWC_VC_B.qY_tmp_d = (uint32_T)counter - /*MW:OvSatOk*/
                    plan_params->num_points_no_str_perp;
                  SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
                  if (SWC_VC_B.qY_tmp_d > counter) {
                    SWC_VC_B.qY_j = 0U;
                  }

                  SWC_VC_B.des_wheel_angle = counter - 1;
                  fxo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.x_out_data
                    [(int32_T)SWC_VC_B.qY_j - 1];
                  if (SWC_VC_B.qY_tmp_d > counter) {
                    SWC_VC_B.qY_tmp_d = 0U;
                  }

                  fyo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.y_out_data
                    [(int32_T)SWC_VC_B.qY_tmp_d - 1];
                }
              }
            } else {
              SWC_VC_B.n_segment[0] = plan_params->num_points_no_str_perp;
              SWC_VC_B.i_a = 0;
              while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[0] - 1) {
                fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_path_data[SWC_VC_B.i_a];
                fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_path_data[SWC_VC_B.i_a];
                SWC_VC_B.i_a++;
              }
            }
          } else {
            SWC_VC_B.i_a = 0;
            while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[0] - 1) {
              fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
              fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_out_data[SWC_VC_B.i_a];
              SWC_VC_B.i_a++;
            }
          }
        } else {
          SWC_VC_B.n_segment[0] = 0U;
          no_str_flag = false;
        }

        final_seg2_attempt = false;
        while (!final_seg2_attempt) {
          if ((SWC_VC_B.pp[2] != SWC_VC_B.pp[4]) || (SWC_VC_B.pp[3] !=
               SWC_VC_B.pp[5])) {
            if (SWC_VC_B.pp[5] >= 0.0F) {
              SWC_VC_B.X_idx_0 = SWC_VC_B.pp[2];
              SWC_VC_B.y_fin_no_str = SWC_VC_B.pp[3];
              SWC_VC_B.Phi_idx_0 = pii[21];
            } else {
              SWC_VC_B.n_segment[0] = 0U;
              no_str_flag = false;
              SWC_VC_B.X_idx_0 = SWC_VC_B.pp[0];
              SWC_VC_B.y_fin_no_str = SWC_VC_B.pp[1];
              SWC_VC_B.Phi_idx_0 = pii[20];
              final_seg2_attempt = true;
            }

            SWC_VC_B.alpha_clothoid_old = plan_params->maxCurvature + 1.0F;
            SWC_VC_B.Phi_idx_1 = SWC_VC_B.Phi_guideline[2] +
              plan_params->Phi_resolution_perp;
            while ((SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) &&
                   (SWC_VC_B.Phi_idx_1 >= SWC_VC_B.Phi_guideline[2] -
                    plan_params->Phi_lim_perp)) {
              SWC_VC_B.Phi_idx_1 -= plan_params->Phi_resolution_perp;
              SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[4] -
                SWC_VC_B.X_idx_0;
              SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[5] -
                SWC_VC_B.y_fin_no_str;
              SWC_VC_B.vectorLength = SWC_VC_B.Phi_idx_0;
              cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
              SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_idx_0;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
              if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                  SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                  0.0F) {
                direction_flag_W0 = 1;
              } else {
                direction_flag_W0 = -1;
              }

              SWC_VC_B.vectorLength = SWC_VC_B.Phi_idx_1;
              cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
              SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_idx_1;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
              if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                  SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                  0.0F) {
                direction_flag_W2 = 1;
              } else {
                direction_flag_W2 = -1;
              }

              SWC_VC_B.vectorLength = fmaxf(fabsf
                (SWC_VC_B.line_direction_idx_0_tmp), fabsf
                (SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
              SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_idx_0;
              cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
              SWC_VC_B.line_direction_idx_1 = SWC_VC_B.Phi_idx_0;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_1);
              SWC_VC_B.line_direction_idx_0 *= SWC_VC_B.vectorLength;
              SWC_VC_B.line_direction_idx_1 *= SWC_VC_B.vectorLength;
              if (fabsf(pii[28]) < 4.0F) {
                SWC_VC_B.W2_idx_0 = ps[1] - SWC_VC_B.pp[1];
                if (SWC_VC_B.W2_idx_0 > 0.9) {
                  SWC_VC_B.W2_idx_0 = fmaxf(1.4F - (SWC_VC_B.W2_idx_0 - 1.0F),
                    1.0F);
                  SWC_VC_B.line_direction_idx_0_tmp_c = fminf(fmaxf
                    ((SWC_VC_B.pps_idx_0 - SWC_VC_B.pp[0]) -
                     plan_params->p3_pos_lim_perp, 0.0F) / 15.0F, 1.5F) + 1.0F;
                  SWC_VC_B.line_direction_idx_0 =
                    SWC_VC_B.line_direction_idx_0_tmp_c *
                    (SWC_VC_B.line_direction_idx_0 * SWC_VC_B.W2_idx_0);
                  SWC_VC_B.line_direction_idx_1 =
                    SWC_VC_B.line_direction_idx_0_tmp_c *
                    (SWC_VC_B.line_direction_idx_1 * SWC_VC_B.W2_idx_0);
                  SWC_VC_B.W2_idx_0 = SWC_VC_B.pps_idx_6 - SWC_VC_B.pps_idx_0;
                  if (!(SWC_VC_B.W2_idx_0 > 3.0F)) {
                    pps = (SWC_VC_B.pps_idx_6 - SWC_VC_B.pps_idx_0 > 2.8);
                    pps_0 = (SWC_VC_B.pps_idx_6 - SWC_VC_B.pps_idx_0 > 2.7);
                    if (SWC_VC_B.W2_idx_0 > 2.9) {
                      SWC_VC_B.line_direction_idx_0 *= 0.9F;
                      SWC_VC_B.line_direction_idx_1 *= 0.9F;
                    } else if (pps) {
                      SWC_VC_B.line_direction_idx_0 *= 0.85F;
                      SWC_VC_B.line_direction_idx_1 *= 0.85F;
                    } else {
                      if (pps_0) {
                        SWC_VC_B.line_direction_idx_0 *= 0.8F;
                      } else {
                        SWC_VC_B.line_direction_idx_0 *= 0.75F;
                      }

                      if (pps_0) {
                        SWC_VC_B.line_direction_idx_1 *= 0.8F;
                      } else {
                        SWC_VC_B.line_direction_idx_1 *= 0.75F;
                      }
                    }
                  }
                }
              }

              SWC_VC_B.line_direction_idx_0 *= (real32_T)direction_flag_W0;
              SWC_VC_B.line_direction_idx_1 *= (real32_T)direction_flag_W0;
              SWC_VC_B.W2_idx_0 = SWC_VC_B.Phi_idx_1;
              cosd_KZN3FnAl(&SWC_VC_B.W2_idx_0);
              SWC_VC_B.line_direction_idx_0_tmp_c = SWC_VC_B.Phi_idx_1;
              sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp_c);
              SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.W2_idx_0 *
                (real32_T)direction_flag_W2;
              SWC_VC_B.vectorLength = SWC_VC_B.vectorLength *
                SWC_VC_B.line_direction_idx_0_tmp_c * (real32_T)
                direction_flag_W2;
              SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
              SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
              SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                                  SWC_VC_B.line_direction_idx_0) -
                SWC_VC_B.W2_idx_0;
              SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
              SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
              SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
              SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                                  SWC_VC_B.line_direction_idx_1) -
                SWC_VC_B.vectorLength;
              SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
              SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
                plan_params->delta_s_perp);
              if (SWC_VC_B.W2_idx_0 < 256.0F) {
                if (SWC_VC_B.W2_idx_0 >= 0.0F) {
                  fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
                } else {
                  fio_tmp = 0U;
                }
              } else {
                fio_tmp = MAX_uint8_T;
              }

              SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
                SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp,
                &SWC_VC_B.alpha_clothoid_old, SWC_VC_B.x_out_data,
                SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data, SWC_VC_B.y_out2_size,
                &SWC_VC_B.n_segment[1]);
              SWC_VC_B.i_a = 0;
              while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[1] - 1) {
                SWC_VC_B.x_out_data[SWC_VC_B.i_a] += SWC_VC_B.X_idx_0;
                SWC_VC_B.y_out_data[SWC_VC_B.i_a] += SWC_VC_B.y_fin_no_str;
                SWC_VC_B.i_a++;
              }
            }

            if ((SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) &&
                (!final_seg2_attempt)) {
              SWC_VC_B.pp[5] -= 0.25F;
            } else if ((SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature)
                       && final_seg2_attempt) {
              *co = -22;
              SWC_VC_B.pp_tmp = SWC_VC_B.n_segment[1] - 1;
              SWC_VC_B.pp[4] = SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp];
              SWC_VC_B.pp[5] = SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp];
              SWC_VC_B.Phi_guideline[2] = SWC_VC_B.Phi_idx_1;
              SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[0]));
              if (SWC_VC_B.dd < 256.0) {
                if (SWC_VC_B.dd >= 0.0) {
                  counter = (uint8_T)SWC_VC_B.dd;
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              SWC_VC_B.i_a = (int32_T)(SWC_VC_B.n_segment[0] + 1U);
              if ((uint32_T)SWC_VC_B.i_a > 255U) {
                SWC_VC_B.i_a = 255;
              }

              for (fio_tmp = (uint8_T)SWC_VC_B.i_a; fio_tmp <= counter; fio_tmp
                   ++) {
                SWC_VC_B.qY_tmp_d = (uint32_T)fio_tmp - /*MW:OvSatOk*/
                  SWC_VC_B.n_segment[0];
                SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
                if (SWC_VC_B.qY_tmp_d > fio_tmp) {
                  SWC_VC_B.qY_j = 0U;
                }

                SWC_VC_B.des_wheel_angle = fio_tmp - 1;
                fxo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.x_out_data
                  [(int32_T)SWC_VC_B.qY_j - 1];
                if (SWC_VC_B.qY_tmp_d > fio_tmp) {
                  SWC_VC_B.qY_tmp_d = 0U;
                }

                fyo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.y_out_data
                  [(int32_T)SWC_VC_B.qY_tmp_d - 1];
              }
            } else {
              final_seg2_attempt = true;
              SWC_VC_B.pp_tmp = SWC_VC_B.n_segment[1] - 1;
              SWC_VC_B.pp[4] = SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp];
              SWC_VC_B.pp[5] = SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp];
              SWC_VC_B.Phi_guideline[2] = SWC_VC_B.Phi_idx_1;
              SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[0]));
              if (SWC_VC_B.dd < 256.0) {
                if (SWC_VC_B.dd >= 0.0) {
                  counter = (uint8_T)SWC_VC_B.dd;
                } else {
                  counter = 0U;
                }
              } else {
                counter = MAX_uint8_T;
              }

              SWC_VC_B.i_a = (int32_T)(SWC_VC_B.n_segment[0] + 1U);
              if ((uint32_T)SWC_VC_B.i_a > 255U) {
                SWC_VC_B.i_a = 255;
              }

              for (fio_tmp = (uint8_T)SWC_VC_B.i_a; fio_tmp <= counter; fio_tmp
                   ++) {
                SWC_VC_B.qY_tmp_d = (uint32_T)fio_tmp - /*MW:OvSatOk*/
                  SWC_VC_B.n_segment[0];
                SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
                if (SWC_VC_B.qY_tmp_d > fio_tmp) {
                  SWC_VC_B.qY_j = 0U;
                }

                SWC_VC_B.des_wheel_angle = fio_tmp - 1;
                fxo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.x_out_data
                  [(int32_T)SWC_VC_B.qY_j - 1];
                if (SWC_VC_B.qY_tmp_d > fio_tmp) {
                  SWC_VC_B.qY_tmp_d = 0U;
                }

                fyo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.y_out_data
                  [(int32_T)SWC_VC_B.qY_tmp_d - 1];
              }
            }
          }
        }

        if ((SWC_VC_B.pp[0] != SWC_VC_B.pp[2]) || (SWC_VC_B.pp[1] !=
             SWC_VC_B.pp[3]) || (SWC_VC_B.pp[2] != SWC_VC_B.pp[4]) ||
            (SWC_VC_B.pp[3] != SWC_VC_B.pp[5])) {
          total_num_idx_12 = 0U;
          if (SWC_VC_B.pp[2] > SWC_VC_B.pp[0]) {
            SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[0]));
            if (SWC_VC_B.dd < 256.0) {
              if (SWC_VC_B.dd >= 0.0) {
                fio_tmp = (uint8_T)SWC_VC_B.dd;
              } else {
                fio_tmp = 0U;
              }
            } else {
              fio_tmp = MAX_uint8_T;
            }

            SWC_VC_post_render_common(fxo_data, fyo_data, fio_tmp,
              plan_params->Kf_perp, plan_params->delta_s_perp,
              SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data,
              SWC_VC_B.y_out2_size, &total_num_idx_12);
            SWC_VC_B.qY_tmp_d = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
            SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
            if (SWC_VC_B.qY_tmp_d > total_num_idx_12) {
              SWC_VC_B.qY_j = 0U;
              SWC_VC_B.qY_tmp_d = 0U;
            }

            SWC_VC_B.i_a = total_num_idx_12 - 1;
            SWC_VC_B.Phi_guideline[2] = rt_atan2f_snf
              (SWC_VC_B.fyo_34_data[SWC_VC_B.i_a] - SWC_VC_B.fyo_34_data
               [(int32_T)SWC_VC_B.qY_j - 1], SWC_VC_B.fxo_34_data[SWC_VC_B.i_a]
               - SWC_VC_B.fxo_34_data[(int32_T)SWC_VC_B.qY_tmp_d - 1]) *
              57.2957802F - 180.0F;
            SWC_VC_B.des_wheel_angle = 0;
            while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
              fxo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.fxo_34_data[SWC_VC_B.des_wheel_angle];
              fyo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.fyo_34_data[SWC_VC_B.des_wheel_angle];
              SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = -1;
              SWC_VC_B.des_wheel_angle++;
            }

            fio[1] = (int16_T)-total_num_idx_12;
          } else {
            if (SWC_VC_B.pp[2] == SWC_VC_B.pp[0]) {
              SWC_VC_B.i_a = 0;
              while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[1] - 1) {
                SWC_VC_B.fgo_data[SWC_VC_B.i_a] = -1;
                SWC_VC_B.i_a++;
              }

              fio[1] = (int16_T)-SWC_VC_B.n_segment[1];
              total_num_idx_12 = SWC_VC_B.n_segment[1];
            }
          }
        } else {
          total_num_idx_12 = 0U;
        }

        if ((SWC_VC_B.pp[0] < ps[0]) || (SWC_VC_B.pp[0] > ps[6])) {
          SWC_VC_B.alpha_clothoid_old = SWC_VC_B.Phi_guideline[2];
          SWC_VC_B.x_out_data[0] = SWC_VC_B.pp[4];
          SWC_VC_B.y_out_data[0] = SWC_VC_B.pp[5];
          direction_flag_W0 = 1;
          SWC_VC_B.W2_idx_0 = roundf(plan_params->segment_3_length_perp_m /
            plan_params->delta_s_clothoid_perp);
          do {
            exitg1 = 0;
            if (SWC_VC_B.W2_idx_0 < 256.0F) {
              if (SWC_VC_B.W2_idx_0 >= 0.0F) {
                fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
              } else {
                fio_tmp = 0U;
              }
            } else {
              fio_tmp = MAX_uint8_T;
            }

            if (direction_flag_W0 < fio_tmp) {
              SWC_VC_B.i_a = direction_flag_W0 + 1;
              if (SWC_VC_B.i_a > 127) {
                SWC_VC_B.i_a = 127;
              }

              direction_flag_W0 = (int8_T)SWC_VC_B.i_a;
              SWC_VC_B.line_direction_idx_0_tmp =
                plan_params->str_wheel_ang_perp;
              tand_brbYAlcS(&SWC_VC_B.line_direction_idx_0_tmp);
              SWC_VC_B.alpha_clothoid = (SWC_VC_B.line_direction_idx_0_tmp *
                plan_params->delta_s_clothoid_perp /
                veh_params.Ke_AP_I_VehWheelbase + SWC_VC_B.alpha_clothoid_old *
                3.14159274F / 180.0F) * 180.0F / 3.14159274F;
              SWC_VC_B.alpha_clothoid_old = SWC_VC_B.alpha_clothoid;
              cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old);
              SWC_VC_B.des_wheel_angle = (int8_T)SWC_VC_B.i_a - 2;
              SWC_VC_B.i_a = (int8_T)SWC_VC_B.i_a - 1;
              SWC_VC_B.x_out_data[SWC_VC_B.i_a] =
                SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] +
                plan_params->delta_s_clothoid_perp * SWC_VC_B.alpha_clothoid_old;
              SWC_VC_B.alpha_clothoid_old = SWC_VC_B.alpha_clothoid;
              sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_old);
              SWC_VC_B.y_out_data[SWC_VC_B.i_a] =
                SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] +
                plan_params->delta_s_clothoid_perp * SWC_VC_B.alpha_clothoid_old;
              SWC_VC_B.alpha_clothoid_old = SWC_VC_B.alpha_clothoid;
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);

          SWC_VC_B.pp_tmp = direction_flag_W0 - 1;
          SWC_VC_B.pp[6] = SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp];
          SWC_VC_B.pp[7] = SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp];
          SWC_VC_B.Phi_guideline[3] = SWC_VC_B.alpha_clothoid;
          if (total_num_idx_12 != 0) {
            SWC_VC_B.n_segment[2] = (uint8_T)SWC_VC_B.pp_tmp;
            SWC_VC_B.i_a = 0;
            while (SWC_VC_B.i_a <= (uint8_T)SWC_VC_B.pp_tmp - 1) {
              SWC_VC_B.des_wheel_angle = total_num_idx_12 + SWC_VC_B.i_a;
              fxo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.x_out_data[SWC_VC_B.i_a + 1];
              fyo_data[SWC_VC_B.des_wheel_angle] =
                SWC_VC_B.y_out_data[SWC_VC_B.i_a + 1];
              SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = 1;
              SWC_VC_B.i_a++;
            }
          } else {
            SWC_VC_B.n_segment[2] = (uint8_T)direction_flag_W0;
            SWC_VC_B.i_a = 0;
            while (SWC_VC_B.i_a <= (uint8_T)direction_flag_W0 - 1) {
              fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
              fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_out_data[SWC_VC_B.i_a];
              SWC_VC_B.fgo_data[SWC_VC_B.i_a] = 1;
              SWC_VC_B.i_a++;
            }
          }

          fio[2] = SWC_VC_B.n_segment[2];
        } else {
          SWC_VC_B.alpha_clothoid_old = (((SWC_VC_B.pp[5] - ps[7]) + 4.5F) +
            1.01F) - (veh_params.Ke_AP_I_VehWheelbase +
                      veh_params.Ke_AP_I_VehFrontOverhang);
          if (SWC_VC_B.alpha_clothoid_old > 0.2) {
            SWC_VC_B.vectorLength = pii[28];
            cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
            SWC_VC_B.line_direction_idx_0_tmp = pii[28];
            sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp);
            SWC_VC_B.vectorLength = SWC_VC_B.alpha_clothoid_old *
              -SWC_VC_B.vectorLength;
            SWC_VC_B.pp[6] = SWC_VC_B.vectorLength + SWC_VC_B.pp[4];
            SWC_VC_B.pp[7] = SWC_VC_B.alpha_clothoid_old *
              -SWC_VC_B.line_direction_idx_0_tmp + SWC_VC_B.pp[5];
            SWC_VC_B.Phi_guideline[3] = pii[28] - 180.0F;
            if (SWC_VC_B.alpha_clothoid_old > 3.0F) {
              SWC_VC_B.pp[6] = ((SWC_VC_B.vectorLength + SWC_VC_B.pp[4]) +
                                SWC_VC_B.pp[10]) / 2.0F;
              SWC_VC_B.Phi_guideline[3] = ((pii[28] - 180.0F) - 90.0F) / 2.0F;
            }

            SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[6] - SWC_VC_B.pp[4];
            SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[7] - SWC_VC_B.pp[5];
            SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
            cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
            SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
            sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
            if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                0.0F) {
              direction_flag_W0 = 1;
            } else {
              direction_flag_W0 = -1;
            }

            SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[3];
            cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
            SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[3];
            sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
            if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
                SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
                0.0F) {
              direction_flag_W2 = 1;
            } else {
              direction_flag_W2 = -1;
            }

            SWC_VC_B.vectorLength = fmaxf(fabsf
              (SWC_VC_B.line_direction_idx_0_tmp), fabsf
              (SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
            SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
            cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
            SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[2];
            sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
            SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
              SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
            SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
              SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
            SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[3];
            cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
            SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[3];
            sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
            SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
              (real32_T)direction_flag_W2;
            SWC_VC_B.vectorLength = SWC_VC_B.vectorLength *
              SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W2;
            SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
            SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
            SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                                SWC_VC_B.line_direction_idx_0) -
              SWC_VC_B.W2_idx_0;
            SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
            SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
            SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
            SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                                SWC_VC_B.line_direction_idx_1) -
              SWC_VC_B.vectorLength;
            SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
            SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
              plan_params->delta_s_perp);
            if (SWC_VC_B.W2_idx_0 < 256.0F) {
              if (SWC_VC_B.W2_idx_0 >= 0.0F) {
                fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
              } else {
                fio_tmp = 0U;
              }
            } else {
              fio_tmp = MAX_uint8_T;
            }

            SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
              SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old,
              SWC_VC_B.x_out_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data,
              SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[2]);
            SWC_VC_B.i_a = 0;
            while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[2] - 1) {
              SWC_VC_B.x_out_data[SWC_VC_B.i_a] += SWC_VC_B.pp[4];
              SWC_VC_B.y_out_data[SWC_VC_B.i_a] += SWC_VC_B.pp[5];
              SWC_VC_B.i_a++;
            }

            if (SWC_VC_B.alpha_clothoid_old > plan_params->maxCurvature) {
              *co = -27;
            }
          } else {
            SWC_VC_B.n_segment[2] = 0U;
            SWC_VC_B.pp[6] = SWC_VC_B.pp[4];
            SWC_VC_B.pp[7] = SWC_VC_B.pp[5];
            SWC_VC_B.Phi_guideline[3] = SWC_VC_B.Phi_guideline[2];
            SWC_VC_B.pp[9] = SWC_VC_B.pp[11];
          }

          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[2] - 1) {
            fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
            fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_out_data[SWC_VC_B.i_a];
            SWC_VC_B.fgo_data[SWC_VC_B.i_a] = 1;
            SWC_VC_B.i_a++;
          }

          fio[2] = SWC_VC_B.n_segment[2];
        }

        final_seg2_attempt = false;
        do {
          exitg1 = 0;
          SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[8] - SWC_VC_B.pp[6];
          SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[9] - SWC_VC_B.pp[7];
          SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[3];
          cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
          SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[3];
          sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
          if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
              SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
              0.0F) {
            direction_flag_W0 = 1;
          } else {
            direction_flag_W0 = -1;
          }

          SWC_VC_B.vectorLength = pii[24];
          cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
          SWC_VC_B.line_direction_idx_0 = pii[24];
          sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
          if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
              SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >=
              0.0F) {
            direction_flag_W2 = 1;
          } else {
            direction_flag_W2 = -1;
          }

          SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
            fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
          SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[3];
          cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
          SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[3];
          sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
          SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
            SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
          SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
            SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
          SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[4];
          cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
          SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[4];
          sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
          SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
            (real32_T)direction_flag_W2;
          SWC_VC_B.vectorLength = SWC_VC_B.vectorLength *
            SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W2;
          SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
          SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
          SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                              SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
          SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
          SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
          SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
          SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                              SWC_VC_B.line_direction_idx_1) -
            SWC_VC_B.vectorLength;
          SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
          SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
            plan_params->delta_s_perp);
          if (SWC_VC_B.W2_idx_0 < 256.0F) {
            if (SWC_VC_B.W2_idx_0 >= 0.0F) {
              fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
            } else {
              fio_tmp = 0U;
            }
          } else {
            fio_tmp = MAX_uint8_T;
          }

          SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
            SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp,
            &SWC_VC_B.line_direction_idx_0_tmp, SWC_VC_B.x_out_data,
            SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data, SWC_VC_B.y_out2_size,
            &SWC_VC_B.n_segment[3]);
          SWC_VC_B.des_wheel_angle = 0;
          do {
            exitg2 = 0;
            SWC_VC_B.i_a = SWC_VC_B.n_segment[3] - 1;
            if (SWC_VC_B.des_wheel_angle <= SWC_VC_B.i_a) {
              SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] += SWC_VC_B.pp[6];
              SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] += SWC_VC_B.pp[7];
              SWC_VC_B.des_wheel_angle++;
            } else {
              exitg2 = 1;
            }
          } while (exitg2 == 0);

          if (SWC_VC_B.line_direction_idx_0_tmp > plan_params->maxCurvature) {
            *co = -24;
          }

          SWC_VC_B.pp_tmp = 0;
          while (SWC_VC_B.pp_tmp <= SWC_VC_B.i_a) {
            SWC_VC_B.des_wheel_angle = (total_num_idx_12 + SWC_VC_B.n_segment[2])
              + SWC_VC_B.pp_tmp;
            fxo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp];
            fyo_data[SWC_VC_B.des_wheel_angle] =
              SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp];
            SWC_VC_B.pp_tmp++;
          }

          if (SWC_VC_B.alpha_clothoid_old < 4.0F) {
            SWC_VC_B.pp[9] = SWC_VC_B.pp[11];
          }

          SWC_VC_B.n_segment[4] = plan_params->n_perp;
          counter = 1U;
          while (counter <= SWC_VC_B.n_segment[4]) {
            SWC_VC_B.des_wheel_angle = counter - 1;
            SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] = ((real32_T)counter -
              1.0F) * (SWC_VC_B.pp[10] - SWC_VC_B.pp[8]) / ((real32_T)
              SWC_VC_B.n_segment[4] - 1.0F) + SWC_VC_B.pp[8];
            SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] = ((real32_T)counter -
              1.0F) * (SWC_VC_B.pp[11] - SWC_VC_B.pp[9]) / ((real32_T)
              SWC_VC_B.n_segment[4] - 1.0F) + SWC_VC_B.pp[9];
            SWC_VC_B.i_a = (int32_T)(counter + 1U);
            if ((uint32_T)SWC_VC_B.i_a > 255U) {
              SWC_VC_B.i_a = 255;
            }

            counter = (uint8_T)SWC_VC_B.i_a;
          }

          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[4] - 1) {
            fxo_data[(int32_T)(((real32_T)total_num_idx_12 + (real32_T)
                                sum_cZvgqUmQ(&SWC_VC_B.n_segment[2])) +
                               ((real32_T)SWC_VC_B.i_a + 1.0F)) - 1] =
              SWC_VC_B.x_out_data[SWC_VC_B.i_a];
            fyo_data[(int32_T)(((real32_T)total_num_idx_12 + (real32_T)
                                sum_cZvgqUmQ(&SWC_VC_B.n_segment[2])) +
                               ((real32_T)SWC_VC_B.i_a + 1.0F)) - 1] =
              SWC_VC_B.y_out_data[SWC_VC_B.i_a];
            SWC_VC_B.i_a++;
          }

          SWC_VC_B.i_a = (int32_T)((uint32_T)total_num_idx_12 +
            SWC_VC_B.n_segment[2]);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.i_a++;
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          SWC_VC_B.pp_tmp = (int32_T)((uint32_T)total_num_idx_12 + sum_1dSfq50U(
            &SWC_VC_B.n_segment[2]));
          if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
            SWC_VC_B.pp_tmp = 255;
          }

          SWC_VC_post_render_common_m(fxo_data, fyo_data, (uint8_T)SWC_VC_B.i_a,
            (uint8_T)SWC_VC_B.pp_tmp, plan_params->Kf_perp,
            plan_params->delta_s_perp, SWC_VC_B.fxo_34_data,
            SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data, SWC_VC_B.y_out2_size,
            &counter);
          SWC_VC_B.qY_j = counter - /*MW:OvSatOk*/ 1U;
          if (SWC_VC_B.qY_j > counter) {
            SWC_VC_B.qY_j = 0U;
          }

          SWC_VC_B.i_a = 0;
          while (SWC_VC_B.i_a <= (uint8_T)SWC_VC_B.qY_j - 1) {
            SWC_VC_B.des_wheel_angle = (total_num_idx_12 + SWC_VC_B.n_segment[2])
              + SWC_VC_B.i_a;
            fxo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.fxo_34_data
              [(SWC_VC_B.i_a - (SWC_VC_B.n_segment[2] == 0)) + 1];
            fyo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.fyo_34_data
              [(SWC_VC_B.i_a - (SWC_VC_B.n_segment[2] == 0)) + 1];
            SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = -1;
            SWC_VC_B.i_a++;
          }

          fio[4] = (int16_T)-(uint8_T)SWC_VC_B.qY_j;
          if (!final_seg2_attempt) {
            SWC_VC_B.Phi_guideline[3] += SWC_VC_B.Phi_guideline[3] -
              (rt_atan2f_snf(SWC_VC_B.fyo_34_data[1] - SWC_VC_B.fyo_34_data[0],
                             SWC_VC_B.fxo_34_data[1] - SWC_VC_B.fxo_34_data[0]) *
               57.2957802F - 180.0F);
            final_seg2_attempt = true;
          } else {
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
  } else if (SWC_VC_B.pp[0] < ps[0] - 1.0F) {
    *co = -19;
  } else if (SWC_VC_B.pp[0] > ps[6] + 1.0F) {
    *co = -19;
  } else {
    no_str_flag = false;
    if (!plan_params->nose_in) {
      SWC_VC_B.n_segment[3] = plan_params->n_perp;
      counter = 1U;
      while (counter <= SWC_VC_B.n_segment[3]) {
        SWC_VC_B.line_direction_idx_0_tmp = pii[20];
        cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0_tmp);
        SWC_VC_B.alpha_clothoid_old = ((real32_T)counter - 1.0F) *
          plan_params->straight_line_perp_park_out / ((real32_T)
          SWC_VC_B.n_segment[3] - 1.0F);
        SWC_VC_B.des_wheel_angle = counter - 1;
        SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0_tmp +
          SWC_VC_B.pp[0];
        SWC_VC_B.line_direction_idx_0_tmp = pii[20];
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp);
        SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0_tmp +
          SWC_VC_B.pp[1];
        SWC_VC_B.i_a = (int32_T)(counter + 1U);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        counter = (uint8_T)SWC_VC_B.i_a;
      }

      final_seg2_attempt = !plan_params->parkout_perp_left;
      if ((plan_params->parkout_perp_left && (plan_params->PP == 3)) ||
          (final_seg2_attempt && (plan_params->PP == 4))) {
        SWC_VC_B.Phi_guideline[2] = 0.0F;
      } else {
        if ((plan_params->parkout_perp_left && (plan_params->PP == 4)) ||
            (final_seg2_attempt && (plan_params->PP == 3))) {
          SWC_VC_B.Phi_guideline[2] = -180.0F;
        }
      }

      SWC_VC_B.alpha_clothoid_old = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old);
      SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp);
      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
      if (plan_params->parkout_perp_left && (plan_params->PP == 3)) {
        SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
        SWC_VC_B.pp[4] = (SWC_VC_B.alpha_clothoid_old +
                          SWC_VC_B.line_direction_idx_0_tmp) *
          plan_params->turn_radius_park_out_perp_big +
          SWC_VC_B.x_out4_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.pp[5] = (SWC_VC_B.vectorLength + -SWC_VC_B.line_direction_idx_0)
          * plan_params->turn_radius_park_out_perp_big +
          SWC_VC_B.y_out4_data[SWC_VC_B.pp_tmp];
      } else if (final_seg2_attempt && (plan_params->PP == 3)) {
        SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
        SWC_VC_B.pp[4] = (SWC_VC_B.alpha_clothoid_old +
                          -SWC_VC_B.line_direction_idx_0_tmp) *
          plan_params->turn_radius_park_out_perp +
          SWC_VC_B.x_out4_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.pp[5] = (SWC_VC_B.vectorLength + SWC_VC_B.line_direction_idx_0)
          * plan_params->turn_radius_park_out_perp +
          SWC_VC_B.y_out4_data[SWC_VC_B.pp_tmp];
      } else if (final_seg2_attempt && (plan_params->PP == 4)) {
        SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
        SWC_VC_B.pp[4] = (SWC_VC_B.alpha_clothoid_old +
                          SWC_VC_B.line_direction_idx_0_tmp) *
          plan_params->turn_radius_park_out_perp +
          SWC_VC_B.x_out4_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.pp[5] = (SWC_VC_B.vectorLength + -SWC_VC_B.line_direction_idx_0)
          * plan_params->turn_radius_park_out_perp +
          SWC_VC_B.y_out4_data[SWC_VC_B.pp_tmp];
      } else {
        if (plan_params->parkout_perp_left && (plan_params->PP == 4)) {
          SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
          SWC_VC_B.pp[4] = (SWC_VC_B.alpha_clothoid_old +
                            -SWC_VC_B.line_direction_idx_0_tmp) *
            plan_params->turn_radius_park_out_perp_big +
            SWC_VC_B.x_out4_data[SWC_VC_B.pp_tmp];
          SWC_VC_B.pp[5] = (SWC_VC_B.vectorLength +
                            SWC_VC_B.line_direction_idx_0) *
            plan_params->turn_radius_park_out_perp_big +
            SWC_VC_B.y_out4_data[SWC_VC_B.pp_tmp];
        }
      }

      SWC_VC_B.i_a = plan_params->n_perp - 1;
      SWC_VC_B.X_idx_0 = SWC_VC_B.x_out4_data[SWC_VC_B.i_a];
      SWC_VC_B.alpha_clothoid = SWC_VC_B.pp[4];
      SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[4] -
        SWC_VC_B.x_out4_data[SWC_VC_B.i_a];
      SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[5] -
        SWC_VC_B.y_out4_data[SWC_VC_B.i_a];
      SWC_VC_B.vectorLength = pii[20];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = pii[20];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W0 = 1;
      } else {
        direction_flag_W0 = -1;
      }

      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.vectorLength = fabsf(SWC_VC_B.Phi_guideline[2] - pii[20]) *
        plan_params->vecLen_coeff_perp_single_sweep_Phi;
      SWC_VC_B.line_direction_idx_0 = pii[20];
      cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
      SWC_VC_B.pps_idx_0 = pii[20];
      sind_7is3Ljjc(&SWC_VC_B.pps_idx_0);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
        SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
      SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0
        * (real32_T)direction_flag_W0;
      SWC_VC_B.pps_idx_6 = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.pps_idx_6);
      SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.pps_idx_0);
      SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_6 * (real32_T)
        direction_flag_W2;
      SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
        (real32_T)direction_flag_W2;
      SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
      SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
      SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                          SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
      SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
      SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
      SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
      SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                          SWC_VC_B.line_direction_idx_1) - SWC_VC_B.vectorLength;
      SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
      SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
        plan_params->delta_s_perp);
      if (SWC_VC_B.W2_idx_0 < 256.0F) {
        if (SWC_VC_B.W2_idx_0 >= 0.0F) {
          fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
        } else {
          fio_tmp = 0U;
        }
      } else {
        fio_tmp = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction, SWC_VC_B.P3_m,
        SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old, SWC_VC_B.x_out_data,
        SWC_VC_B.x_out2_size, SWC_VC_B.y_out_data, SWC_VC_B.y_out2_size,
        &SWC_VC_B.n_segment[2]);
      SWC_VC_B.des_wheel_angle = 0;
      while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[2] - 2) {
        SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle + 1] +
          SWC_VC_B.x_out4_data[SWC_VC_B.i_a];
        SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle + 1] +
          SWC_VC_B.y_out4_data[SWC_VC_B.i_a];
        SWC_VC_B.des_wheel_angle++;
      }

      SWC_VC_B.qY_j = SWC_VC_B.n_segment[2] - /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY_j > SWC_VC_B.n_segment[2]) {
        SWC_VC_B.qY_j = 0U;
      }

      SWC_VC_B.n_segment[2] = (uint8_T)SWC_VC_B.qY_j;
      if ((plan_params->parkout_perp_left && (plan_params->PP == 3)) ||
          (final_seg2_attempt && (plan_params->PP == 4))) {
        SWC_VC_B.Phi_guideline[3] = 0.0F;
        SWC_VC_B.i_a = (uint8_T)SWC_VC_B.qY_j - 1;
        SWC_VC_B.X_idx_0 = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
        SWC_VC_B.alpha_clothoid = SWC_VC_B.x_out_data[SWC_VC_B.i_a] + 1.5F;
      } else {
        if ((final_seg2_attempt && (plan_params->PP == 3)) ||
            (plan_params->parkout_perp_left && (plan_params->PP == 4))) {
          SWC_VC_B.Phi_guideline[3] = -180.0F;
          SWC_VC_B.i_a = (uint8_T)SWC_VC_B.qY_j - 1;
          SWC_VC_B.X_idx_0 = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
          SWC_VC_B.alpha_clothoid = SWC_VC_B.x_out_data[SWC_VC_B.i_a] - 1.5F;
        }
      }

      SWC_VC_B.i_a = (uint8_T)SWC_VC_B.qY_j - 1;
      SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.alpha_clothoid -
        SWC_VC_B.X_idx_0;
      SWC_VC_B.alpha_clothoid_old = SWC_VC_B.y_out_data[SWC_VC_B.i_a] -
        SWC_VC_B.y_out_data[SWC_VC_B.i_a];
      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W0 = 1;
      } else {
        direction_flag_W0 = -1;
      }

      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[3];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[3];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
        fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
      SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
        SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
      SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
        SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
      SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[3];
      cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
      SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[3];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
      SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 * (real32_T)
        direction_flag_W2;
      SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.alpha_clothoid *
        (real32_T)direction_flag_W2;
      SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
      SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
      SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                          SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
      SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
      SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
      SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
      SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                          SWC_VC_B.line_direction_idx_1) - SWC_VC_B.vectorLength;
      SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
      SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
        plan_params->delta_s_perp);
      if (SWC_VC_B.W2_idx_0 < 256.0F) {
        if (SWC_VC_B.W2_idx_0 >= 0.0F) {
          fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
        } else {
          fio_tmp = 0U;
        }
      } else {
        fio_tmp = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction, SWC_VC_B.P3_m,
        SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old, SWC_VC_B.x_out2_data,
        SWC_VC_B.x_out2_size, SWC_VC_B.y_out2_data, SWC_VC_B.y_out2_size,
        &SWC_VC_B.n_segment[1]);
      SWC_VC_B.des_wheel_angle = 0;
      while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[1] - 2) {
        SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle + 1] + SWC_VC_B.X_idx_0;
        SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle + 1] +
          SWC_VC_B.y_out_data[SWC_VC_B.i_a];
        SWC_VC_B.des_wheel_angle++;
      }

      SWC_VC_B.qY_j = SWC_VC_B.n_segment[1] - /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY_j > SWC_VC_B.n_segment[1]) {
        SWC_VC_B.qY_j = 0U;
      }

      SWC_VC_B.n_segment[1] = (uint8_T)SWC_VC_B.qY_j;
      fio_tmp = sum_1dSfq50U(&SWC_VC_B.n_segment[1]);
      counter = 1U;
      SWC_VC_B.pp_tmp = 0;
      while (SWC_VC_B.pp_tmp <= SWC_VC_B.n_segment[3] - 1) {
        SWC_VC_B.des_wheel_angle = counter - 1;
        fxo_data[SWC_VC_B.pp_tmp] =
          SWC_VC_B.x_out4_data[SWC_VC_B.des_wheel_angle];
        fyo_data[SWC_VC_B.pp_tmp] =
          SWC_VC_B.y_out4_data[SWC_VC_B.des_wheel_angle];
        SWC_VC_B.i_a = (int32_T)(counter + 1U);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        counter = (uint8_T)SWC_VC_B.i_a;
        SWC_VC_B.pp_tmp++;
      }

      counter = 1U;
      SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[2]));
      if (SWC_VC_B.dd < 256.0) {
        if (SWC_VC_B.dd >= 0.0) {
          total_num_idx_12 = (uint8_T)SWC_VC_B.dd;
        } else {
          total_num_idx_12 = 0U;
        }
      } else {
        total_num_idx_12 = MAX_uint8_T;
      }

      for (tb_i = (uint8_T)(plan_params->n_perp + 1); tb_i <= total_num_idx_12;
           tb_i++) {
        SWC_VC_B.des_wheel_angle = counter - 1;
        SWC_VC_B.dc_i = tb_i - 1;
        fxo_data[SWC_VC_B.dc_i] = SWC_VC_B.x_out_data[SWC_VC_B.des_wheel_angle];
        fyo_data[SWC_VC_B.dc_i] = SWC_VC_B.y_out_data[SWC_VC_B.des_wheel_angle];
        SWC_VC_B.i_a = (int32_T)(counter + 1U);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        counter = (uint8_T)SWC_VC_B.i_a;
      }

      counter = 1U;
      SWC_VC_B.i_a = (int32_T)(sum_lsjEpyTA(&SWC_VC_B.n_segment[2]) + 1U);
      if ((uint32_T)SWC_VC_B.i_a > 255U) {
        SWC_VC_B.i_a = 255;
      }

      for (total_num_idx_12 = (uint8_T)SWC_VC_B.i_a; total_num_idx_12 <= fio_tmp;
           total_num_idx_12++) {
        SWC_VC_B.des_wheel_angle = counter - 1;
        SWC_VC_B.dc_i = total_num_idx_12 - 1;
        fxo_data[SWC_VC_B.dc_i] = SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle];
        fyo_data[SWC_VC_B.dc_i] = SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle];
        SWC_VC_B.i_a = (int32_T)(counter + 1U);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        counter = (uint8_T)SWC_VC_B.i_a;
      }

      SWC_VC_post_render_common(fxo_data, fyo_data, fio_tmp,
        plan_params->Kf_perp_single_sweep, plan_params->delta_s_perp,
        SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data,
        SWC_VC_B.y_out2_size, &counter);
      SWC_VC_B.i_a = 0;
      while (SWC_VC_B.i_a <= counter - 1) {
        fxo_data[SWC_VC_B.i_a] = SWC_VC_B.fxo_34_data[SWC_VC_B.i_a];
        fyo_data[SWC_VC_B.i_a] = SWC_VC_B.fyo_34_data[SWC_VC_B.i_a];
        SWC_VC_B.fgo_data[SWC_VC_B.i_a] = 1;
        SWC_VC_B.i_a++;
      }

      fio[0] = counter;
    } else {
      if (!(plan_params->regen_mode != 0.0F)) {
        SWC_VC_B.n_segment[0] = plan_params->n_perp;
        counter = 1U;
        while (counter <= SWC_VC_B.n_segment[0]) {
          SWC_VC_B.line_direction_idx_0_tmp = pii[20];
          cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0_tmp);
          SWC_VC_B.alpha_clothoid_old = ((real32_T)counter - 1.0F) *
            plan_params->straight_line_perp_park_out / ((real32_T)
            SWC_VC_B.n_segment[0] - 1.0F);
          SWC_VC_B.i_a = counter - 1;
          SWC_VC_B.x_out_data[SWC_VC_B.i_a] = SWC_VC_B.pp[0] -
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0_tmp;
          SWC_VC_B.line_direction_idx_0_tmp = pii[20];
          sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0_tmp);
          SWC_VC_B.y_out_data[SWC_VC_B.i_a] = SWC_VC_B.pp[1] -
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0_tmp;
          SWC_VC_B.i_a = (int32_T)(counter + 1U);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          counter = (uint8_T)SWC_VC_B.i_a;
        }

        final_seg2_attempt = !plan_params->parkout_perp_left;
        if ((plan_params->parkout_perp_left && (plan_params->PP == 3)) ||
            (final_seg2_attempt && (plan_params->PP == 4))) {
          SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
          SWC_VC_B.pp[4] = SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp] +
            -plan_params->park_out_nose_in_brk_pos_offset_X;
          SWC_VC_B.pp[5] = SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp] +
            -plan_params->park_out_nose_in_brk_pos_offset_Y;
          SWC_VC_B.Phi_guideline[2] = 90.0F -
            plan_params->park_out_nose_in_angle;
        } else {
          if ((plan_params->parkout_perp_left && (plan_params->PP == 4)) ||
              (final_seg2_attempt && (plan_params->PP == 3))) {
            SWC_VC_B.pp_tmp = plan_params->n_perp - 1;
            SWC_VC_B.pp[4] = SWC_VC_B.x_out_data[SWC_VC_B.pp_tmp] +
              plan_params->park_out_nose_in_brk_pos_offset_X;
            SWC_VC_B.pp[5] = SWC_VC_B.y_out_data[SWC_VC_B.pp_tmp] +
              -plan_params->park_out_nose_in_brk_pos_offset_Y;
            SWC_VC_B.Phi_guideline[2] = plan_params->park_out_nose_in_angle +
              90.0F;
          }
        }

        SWC_VC_B.i_a = plan_params->n_perp - 1;
        SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[4] -
          SWC_VC_B.x_out_data[SWC_VC_B.i_a];
        SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[5] -
          SWC_VC_B.y_out_data[SWC_VC_B.i_a];
        SWC_VC_B.vectorLength = pii[20];
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = pii[20];
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W0 = 1;
        } else {
          direction_flag_W0 = -1;
        }

        SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
        cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
        sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
        if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
            SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F)
        {
          direction_flag_W2 = 1;
        } else {
          direction_flag_W2 = -1;
        }

        SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
          fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
        SWC_VC_B.line_direction_idx_0 = pii[20];
        cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
        SWC_VC_B.alpha_clothoid = pii[20];
        sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
        SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
          SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
        SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
          SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
        SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[2];
        cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
        SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[2];
        sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
        SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 *
          (real32_T)direction_flag_W2;
        SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.alpha_clothoid *
          (real32_T)direction_flag_W2;
        SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
        SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
        SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                            SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
        SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
        SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
        SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
        SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                            SWC_VC_B.line_direction_idx_1) -
          SWC_VC_B.vectorLength;
        SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
        SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
          plan_params->delta_s_perp);
        if (SWC_VC_B.W2_idx_0 < 256.0F) {
          if (SWC_VC_B.W2_idx_0 >= 0.0F) {
            fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction,
          SWC_VC_B.P3_m, SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old,
          SWC_VC_B.x_out2_data, SWC_VC_B.x_out2_size, SWC_VC_B.y_out2_data,
          SWC_VC_B.y_out2_size, &SWC_VC_B.n_segment[1]);
        SWC_VC_B.des_wheel_angle = 0;
        while (SWC_VC_B.des_wheel_angle <= SWC_VC_B.n_segment[1] - 1) {
          SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.x_out_data[SWC_VC_B.i_a];
          SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle] +=
            SWC_VC_B.y_out_data[SWC_VC_B.i_a];
          SWC_VC_B.des_wheel_angle++;
        }

        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[0] - 2) {
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.x_out_data[SWC_VC_B.i_a];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.y_out_data[SWC_VC_B.i_a];
          SWC_VC_B.i_a++;
        }

        counter = 1U;
        SWC_VC_B.pp_tmp = (int32_T)(((real32_T)sum_cZvgqUmQ(&SWC_VC_B.n_segment
          [0]) - 1.0F) + (1.0F - (real32_T)plan_params->n_perp));
        SWC_VC_B.yb_i = 0;
        while (SWC_VC_B.yb_i <= SWC_VC_B.pp_tmp - 1) {
          SWC_VC_B.des_wheel_angle = counter - 1;
          SWC_VC_B.dc_i = (int32_T)((real32_T)SWC_VC_B.n_segment[0] + (real32_T)
            SWC_VC_B.yb_i) - 1;
          fxo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.x_out2_data[SWC_VC_B.des_wheel_angle];
          fyo_data[SWC_VC_B.dc_i] =
            SWC_VC_B.y_out2_data[SWC_VC_B.des_wheel_angle];
          SWC_VC_B.i_a = (int32_T)(counter + 1U);
          if ((uint32_T)SWC_VC_B.i_a > 255U) {
            SWC_VC_B.i_a = 255;
          }

          counter = (uint8_T)SWC_VC_B.i_a;
          SWC_VC_B.yb_i++;
        }

        SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[0]));
        if (SWC_VC_B.dd < 256.0) {
          if (SWC_VC_B.dd >= 0.0) {
            fio_tmp = (uint8_T)SWC_VC_B.dd;
          } else {
            fio_tmp = 0U;
          }
        } else {
          fio_tmp = MAX_uint8_T;
        }

        SWC_VC_B.qY_j = fio_tmp - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > fio_tmp) {
          SWC_VC_B.qY_j = 0U;
        }

        SWC_VC_post_render_common(fxo_data, fyo_data, (uint8_T)SWC_VC_B.qY_j,
          plan_params->Kf_perp_single_sweep, plan_params->delta_s_perp,
          SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size, SWC_VC_B.fyo_34_data,
          SWC_VC_B.y_out2_size, &total_num_idx_12);
        SWC_VC_B.des_wheel_angle = SWC_VC_B.x_out2_size[0] *
          SWC_VC_B.x_out2_size[1] - 1;
        if (0 <= SWC_VC_B.des_wheel_angle) {
          memcpy(&SWC_VC_B.fxo_12_data[0], &SWC_VC_B.fxo_34_data[0],
                 (SWC_VC_B.des_wheel_angle + 1) * sizeof(real32_T));
        }

        SWC_VC_B.des_wheel_angle = SWC_VC_B.y_out2_size[0] *
          SWC_VC_B.y_out2_size[1] - 1;
        if (0 <= SWC_VC_B.des_wheel_angle) {
          memcpy(&SWC_VC_B.fyo_12_data[0], &SWC_VC_B.fyo_34_data[0],
                 (SWC_VC_B.des_wheel_angle + 1) * sizeof(real32_T));
        }

        SWC_VC_B.qY_tmp_d = total_num_idx_12 - /*MW:OvSatOk*/ 1U;
        SWC_VC_B.qY_j = SWC_VC_B.qY_tmp_d;
        if (SWC_VC_B.qY_tmp_d > total_num_idx_12) {
          SWC_VC_B.qY_j = 0U;
          SWC_VC_B.qY_tmp_d = 0U;
        }

        SWC_VC_B.des_wheel_angle = total_num_idx_12 - 1;
        SWC_VC_B.alpha_clothoid = rt_atan2f_snf
          (SWC_VC_B.fyo_34_data[SWC_VC_B.des_wheel_angle] -
           SWC_VC_B.fyo_34_data[(int32_T)SWC_VC_B.qY_j - 1],
           SWC_VC_B.fxo_34_data[SWC_VC_B.des_wheel_angle] -
           SWC_VC_B.fxo_34_data[(int32_T)SWC_VC_B.qY_tmp_d - 1]) * 57.2957802F;
        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= SWC_VC_B.des_wheel_angle) {
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.fxo_34_data[SWC_VC_B.i_a];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.fyo_34_data[SWC_VC_B.i_a];
          SWC_VC_B.fgo_data[SWC_VC_B.i_a] = -1;
          SWC_VC_B.i_a++;
        }

        fio[0] = (int16_T)-total_num_idx_12;
      } else {
        total_num_idx_12 = 0U;
      }

      final_seg2_attempt = !plan_params->parkout_perp_left;
      if (final_seg2_attempt && (plan_params->PP == 3)) {
        SWC_VC_B.pp[6] = ps[0] + -plan_params->park_out_nose_in_end_pos_offset_X;
        SWC_VC_B.pp[7] = ps[1] +
          -plan_params->park_out_nose_in_end_pos_offset_Y_small;
        SWC_VC_B.Phi_guideline[3] = -180.0F;
      } else if (plan_params->parkout_perp_left && (plan_params->PP == 3)) {
        SWC_VC_B.pp[6] = ps[6] + plan_params->park_out_nose_in_end_pos_offset_X;
        SWC_VC_B.pp[7] = ps[7] +
          -plan_params->park_out_nose_in_end_pos_offset_Y_big;
        SWC_VC_B.Phi_guideline[3] = 0.0F;
      } else if (final_seg2_attempt && (plan_params->PP == 4)) {
        SWC_VC_B.pp[6] = ps[6] + plan_params->park_out_nose_in_end_pos_offset_X;
        SWC_VC_B.pp[7] = ps[7] +
          -plan_params->park_out_nose_in_end_pos_offset_Y_small;
        SWC_VC_B.Phi_guideline[3] = 0.0F;
      } else {
        if (plan_params->parkout_perp_left && (plan_params->PP == 4)) {
          SWC_VC_B.pp[6] = ps[0] +
            -plan_params->park_out_nose_in_end_pos_offset_X;
          SWC_VC_B.pp[7] = ps[1] +
            -plan_params->park_out_nose_in_end_pos_offset_Y_big;
          SWC_VC_B.Phi_guideline[3] = -180.0F;
        }
      }

      if (!(plan_params->regen_mode != 0.0F)) {
        SWC_VC_B.pp_tmp = total_num_idx_12 - 1;
        SWC_VC_B.pp[4] = SWC_VC_B.fxo_12_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.pp[5] = SWC_VC_B.fyo_12_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.Phi_guideline[2] = SWC_VC_B.alpha_clothoid;
      } else {
        SWC_VC_B.pp[4] = SWC_VC_B.pp[0];
        SWC_VC_B.pp[5] = SWC_VC_B.pp[1];
        SWC_VC_B.Phi_guideline[2] = pii[20];
      }

      SWC_VC_B.line_direction_idx_0_tmp = SWC_VC_B.pp[6] - SWC_VC_B.pp[4];
      SWC_VC_B.alpha_clothoid_old = SWC_VC_B.pp[7] - SWC_VC_B.pp[5];
      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W0 = 1;
      } else {
        direction_flag_W0 = -1;
      }

      SWC_VC_B.vectorLength = SWC_VC_B.Phi_guideline[3];
      cosd_KZN3FnAl(&SWC_VC_B.vectorLength);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[3];
      sind_7is3Ljjc(&SWC_VC_B.line_direction_idx_0);
      if (SWC_VC_B.line_direction_idx_0_tmp * SWC_VC_B.vectorLength +
          SWC_VC_B.alpha_clothoid_old * SWC_VC_B.line_direction_idx_0 >= 0.0F) {
        direction_flag_W2 = 1;
      } else {
        direction_flag_W2 = -1;
      }

      SWC_VC_B.vectorLength = fmaxf(fabsf(SWC_VC_B.line_direction_idx_0_tmp),
        fabsf(SWC_VC_B.alpha_clothoid_old)) * plan_params->vecLen_coeff_perp;
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.Phi_guideline[2];
      cosd_KZN3FnAl(&SWC_VC_B.line_direction_idx_0);
      SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[2];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
      SWC_VC_B.line_direction_idx_0 = SWC_VC_B.vectorLength *
        SWC_VC_B.line_direction_idx_0 * (real32_T)direction_flag_W0;
      SWC_VC_B.line_direction_idx_1 = SWC_VC_B.vectorLength *
        SWC_VC_B.alpha_clothoid * (real32_T)direction_flag_W0;
      SWC_VC_B.pps_idx_0 = SWC_VC_B.Phi_guideline[3];
      cosd_KZN3FnAl(&SWC_VC_B.pps_idx_0);
      SWC_VC_B.alpha_clothoid = SWC_VC_B.Phi_guideline[3];
      sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid);
      SWC_VC_B.W2_idx_0 = SWC_VC_B.vectorLength * SWC_VC_B.pps_idx_0 * (real32_T)
        direction_flag_W2;
      SWC_VC_B.vectorLength = SWC_VC_B.vectorLength * SWC_VC_B.alpha_clothoid *
        (real32_T)direction_flag_W2;
      SWC_VC_B.P3[0] = SWC_VC_B.line_direction_idx_0_tmp;
      SWC_VC_B.line_direction[0] = SWC_VC_B.line_direction_idx_0;
      SWC_VC_B.P3_m[0] = (SWC_VC_B.line_direction_idx_0_tmp -
                          SWC_VC_B.line_direction_idx_0) - SWC_VC_B.W2_idx_0;
      SWC_VC_B.W2[0] = SWC_VC_B.W2_idx_0;
      SWC_VC_B.P3[1] = SWC_VC_B.alpha_clothoid_old;
      SWC_VC_B.line_direction[1] = SWC_VC_B.line_direction_idx_1;
      SWC_VC_B.P3_m[1] = (SWC_VC_B.alpha_clothoid_old -
                          SWC_VC_B.line_direction_idx_1) - SWC_VC_B.vectorLength;
      SWC_VC_B.W2[1] = SWC_VC_B.vectorLength;
      SWC_VC_B.W2_idx_0 = floorf(norm_5ISqY4yY(SWC_VC_B.P3) /
        plan_params->delta_s_perp);
      if (SWC_VC_B.W2_idx_0 < 256.0F) {
        if (SWC_VC_B.W2_idx_0 >= 0.0F) {
          fio_tmp = (uint8_T)SWC_VC_B.W2_idx_0;
        } else {
          fio_tmp = 0U;
        }
      } else {
        fio_tmp = MAX_uint8_T;
      }

      SWC_VC_Bezier_path_function_common(SWC_VC_B.line_direction, SWC_VC_B.P3_m,
        SWC_VC_B.W2, fio_tmp, &SWC_VC_B.alpha_clothoid_old, SWC_VC_B.x_out4_data,
        SWC_VC_B.x_out2_size, SWC_VC_B.y_out4_data, SWC_VC_B.y_out2_size,
        &SWC_VC_B.n_segment[2]);
      SWC_VC_B.i_a = 0;
      while (SWC_VC_B.i_a <= SWC_VC_B.n_segment[2] - 1) {
        SWC_VC_B.x_out4_data[SWC_VC_B.i_a] += SWC_VC_B.pp[4];
        SWC_VC_B.y_out4_data[SWC_VC_B.i_a] += SWC_VC_B.pp[5];
        SWC_VC_B.i_a++;
      }

      SWC_VC_B.n_segment[3] = plan_params->num_points_no_str_perp;
      SWC_VC_B.i_a = SWC_VC_B.n_segment[2] - 1;
      SWC_VC_B.x_path_data[0] = SWC_VC_B.x_out4_data[SWC_VC_B.i_a];
      SWC_VC_B.y_path_data[0] = SWC_VC_B.y_out4_data[SWC_VC_B.i_a];
      counter = 1U;
      do {
        exitg1 = 0;
        SWC_VC_B.qY_j = SWC_VC_B.n_segment[3] - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY_j > SWC_VC_B.n_segment[3]) {
          SWC_VC_B.qY_j = 0U;
        }

        if (counter <= (int32_T)SWC_VC_B.qY_j) {
          SWC_VC_B.alpha_clothoid_old = SWC_VC_B.Phi_guideline[3];
          cosd_KZN3FnAl(&SWC_VC_B.alpha_clothoid_old);
          SWC_VC_B.des_wheel_angle = counter - 1;
          SWC_VC_B.x_path_data[counter] =
            SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle] +
            plan_params->delta_s_no_str_perp * SWC_VC_B.alpha_clothoid_old;
          SWC_VC_B.alpha_clothoid_old = SWC_VC_B.Phi_guideline[3];
          sind_7is3Ljjc(&SWC_VC_B.alpha_clothoid_old);
          SWC_VC_B.y_path_data[counter] =
            SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle] +
            plan_params->delta_s_no_str_perp * SWC_VC_B.alpha_clothoid_old;
          counter++;
        } else {
          exitg1 = 1;
        }
      } while (exitg1 == 0);

      SWC_VC_B.pp_tmp = 0;
      while (SWC_VC_B.pp_tmp <= SWC_VC_B.i_a) {
        SWC_VC_B.des_wheel_angle = total_num_idx_12 + SWC_VC_B.pp_tmp;
        fxo_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.x_out4_data[SWC_VC_B.pp_tmp];
        fyo_data[SWC_VC_B.des_wheel_angle] =
          SWC_VC_B.y_out4_data[SWC_VC_B.pp_tmp];
        SWC_VC_B.pp_tmp++;
      }

      SWC_VC_B.dc_i = 1;
      while (SWC_VC_B.dc_i - 1 <= SWC_VC_B.n_segment[3] - 1) {
        SWC_VC_B.i_a = (int32_T)((uint32_T)total_num_idx_12 +
          SWC_VC_B.n_segment[2]);
        SWC_VC_B.pp_tmp = SWC_VC_B.i_a;
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.pp_tmp = 255;
        }

        SWC_VC_B.pp_tmp = (int32_T)((uint32_T)SWC_VC_B.pp_tmp + (uint8_T)
          SWC_VC_B.dc_i);
        if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
          SWC_VC_B.pp_tmp = 255;
        }

        SWC_VC_B.des_wheel_angle = (uint8_T)SWC_VC_B.dc_i - 1;
        fxo_data[SWC_VC_B.pp_tmp - 1] =
          SWC_VC_B.x_path_data[SWC_VC_B.des_wheel_angle];
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        SWC_VC_B.i_a = (int32_T)((uint32_T)SWC_VC_B.i_a + (uint8_T)SWC_VC_B.dc_i);
        if ((uint32_T)SWC_VC_B.i_a > 255U) {
          SWC_VC_B.i_a = 255;
        }

        fyo_data[SWC_VC_B.i_a - 1] =
          SWC_VC_B.y_path_data[SWC_VC_B.des_wheel_angle];
        SWC_VC_B.dc_i++;
      }

      SWC_VC_B.i_a = (int32_T)(total_num_idx_12 + 1U);
      if ((uint32_T)SWC_VC_B.i_a > 255U) {
        SWC_VC_B.i_a = 255;
      }

      SWC_VC_B.dd = rt_roundd_snf(sum_cZvgqUmQ(&SWC_VC_B.n_segment[2]));
      if (SWC_VC_B.dd < 256.0) {
        if (SWC_VC_B.dd >= 0.0) {
          fio_tmp = (uint8_T)SWC_VC_B.dd;
        } else {
          fio_tmp = 0U;
        }
      } else {
        fio_tmp = MAX_uint8_T;
      }

      SWC_VC_B.pp_tmp = (int32_T)((uint32_T)total_num_idx_12 + fio_tmp);
      if ((uint32_T)SWC_VC_B.pp_tmp > 255U) {
        SWC_VC_B.pp_tmp = 255;
      }

      SWC_VC_post_render_common_m(fxo_data, fyo_data, (uint8_T)SWC_VC_B.i_a,
        (uint8_T)SWC_VC_B.pp_tmp, plan_params->Kf_perp_single_sweep,
        plan_params->delta_s_perp, SWC_VC_B.fxo_34_data, SWC_VC_B.x_out2_size,
        SWC_VC_B.fyo_34_data, SWC_VC_B.y_out2_size, &counter);
      if (!(plan_params->regen_mode != 0.0F)) {
        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= counter - 2) {
          SWC_VC_B.des_wheel_angle = total_num_idx_12 + SWC_VC_B.i_a;
          fxo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.fxo_34_data[SWC_VC_B.i_a
            + 1];
          fyo_data[SWC_VC_B.des_wheel_angle] = SWC_VC_B.fyo_34_data[SWC_VC_B.i_a
            + 1];
          SWC_VC_B.fgo_data[SWC_VC_B.des_wheel_angle] = 1;
          SWC_VC_B.i_a++;
        }

        fio[1] = counter;
      } else {
        SWC_VC_B.i_a = 0;
        while (SWC_VC_B.i_a <= counter - 1) {
          fxo_data[SWC_VC_B.i_a] = SWC_VC_B.fxo_34_data[SWC_VC_B.i_a];
          fyo_data[SWC_VC_B.i_a] = SWC_VC_B.fyo_34_data[SWC_VC_B.i_a];
          SWC_VC_B.fgo_data[SWC_VC_B.i_a] = 1;
          SWC_VC_B.i_a++;
        }

        fio[0] = counter;
      }
    }
  }

  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 10; SWC_VC_B.i_a++) {
    SWC_VC_B.fio_dummy[SWC_VC_B.i_a] = 0;
  }

  counter = 0U;
  for (SWC_VC_B.des_wheel_angle = 0; SWC_VC_B.des_wheel_angle < 10;
       SWC_VC_B.des_wheel_angle++) {
    if (fio[SWC_VC_B.des_wheel_angle] != 0) {
      SWC_VC_B.i_a = (int32_T)(counter + 1U);
      if ((uint32_T)SWC_VC_B.i_a > 255U) {
        SWC_VC_B.i_a = 255;
      }

      counter = (uint8_T)SWC_VC_B.i_a;
      SWC_VC_B.fio_dummy[(uint8_T)SWC_VC_B.i_a - 1] =
        fio[SWC_VC_B.des_wheel_angle];
    }
  }

  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 10; SWC_VC_B.i_a++) {
    fio[SWC_VC_B.i_a] = SWC_VC_B.fio_dummy[SWC_VC_B.i_a];
  }

  SWC_VC_diff(fxo_data, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  SWC_VC_diff(fyo_data, SWC_VC_B.tmp_data_l, &SWC_VC_B.tmp_size_g);
  SWC_VC_B.dfy_size = 249;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 249; SWC_VC_B.i_a++) {
    SWC_VC_B.alpha_clothoid_old = -(real32_T)SWC_VC_B.fgo_data[SWC_VC_B.i_a + 1];
    SWC_VC_B.dfx_data[SWC_VC_B.i_a] = SWC_VC_B.alpha_clothoid_old *
      SWC_VC_B.tmp_data_d[SWC_VC_B.i_a];
    SWC_VC_B.dfy_data[SWC_VC_B.i_a] = SWC_VC_B.alpha_clothoid_old *
      SWC_VC_B.tmp_data_l[SWC_VC_B.i_a];
  }

  SWC_VC_atan2d(SWC_VC_B.dfy_data, &SWC_VC_B.dfy_size, SWC_VC_B.dfx_data,
                SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  fho_data[0] = pii[20] + 180.0F;
  SWC_VC_B.des_wheel_angle = SWC_VC_B.tmp_size_g;
  if (0 <= SWC_VC_B.des_wheel_angle - 1) {
    memcpy(&fho_data[1], &SWC_VC_B.tmp_data_d[0], SWC_VC_B.des_wheel_angle *
           sizeof(real32_T));
  }

  SWC_VC_power(SWC_VC_B.dfx_data, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  SWC_VC_power(SWC_VC_B.dfy_data, SWC_VC_B.tmp_data_l, &SWC_VC_B.tmp_size_g);
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 249; SWC_VC_B.i_a++) {
    SWC_VC_B.W2_idx_0 = fho_data[SWC_VC_B.i_a + 1];
    SWC_VC_B.alpha_clothoid_old = SWC_VC_B.W2_idx_0 - fho_data[SWC_VC_B.i_a];
    if (SWC_VC_B.alpha_clothoid_old > 360.0F) {
      fho_data[SWC_VC_B.i_a + 1] = SWC_VC_B.W2_idx_0 - 360.0F;
    } else {
      if (SWC_VC_B.alpha_clothoid_old < -360.0F) {
        fho_data[SWC_VC_B.i_a + 1] = SWC_VC_B.W2_idx_0 + 360.0F;
      }
    }

    SWC_VC_B.dfx_data[SWC_VC_B.i_a] = SWC_VC_B.tmp_data_d[SWC_VC_B.i_a] +
      SWC_VC_B.tmp_data_l[SWC_VC_B.i_a];
  }

  SWC_VC_sqrt(SWC_VC_B.dfx_data);
  SWC_VC_diff(fho_data, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  SWC_VC_B.veh_params_size = SWC_VC_B.tmp_size_g;
  SWC_VC_B.des_wheel_angle = SWC_VC_B.tmp_size_g;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < SWC_VC_B.des_wheel_angle; SWC_VC_B.i_a++)
  {
    SWC_VC_B.tmp_data_l[SWC_VC_B.i_a] = veh_params.Ke_AP_I_VehWheelbase *
      SWC_VC_B.tmp_data_d[SWC_VC_B.i_a] * 3.14159274F / 180.0F;
  }

  SWC_VC_atan2d(SWC_VC_B.tmp_data_l, &SWC_VC_B.veh_params_size,
                SWC_VC_B.dfx_data, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  SWC_VC_B.fxo_12_data[0] = 0.0F;
  SWC_VC_B.des_wheel_angle = SWC_VC_B.tmp_size_g;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < SWC_VC_B.des_wheel_angle; SWC_VC_B.i_a++)
  {
    SWC_VC_B.fxo_12_data[SWC_VC_B.i_a + 1] = plan_params->Ks *
      SWC_VC_B.tmp_data_d[SWC_VC_B.i_a];
  }

  *fso_size = 250;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fso_data[SWC_VC_B.i_a] = (real32_T)SWC_VC_B.fgo_data[SWC_VC_B.i_a] *
      SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }

  if (SWC_VC_B.pp[0] < ps[0]) {
    if (!no_str_flag) {
      fso_data[0] = pii[29];
      fso_data[1] = (fso_data[3] - pii[29]) / 3.0F + pii[29];
      fso_data[2] = (fso_data[3] - pii[29]) * 2.0F / 3.0F + pii[29];
    }
  } else {
    fso_data[0] = fso_data[2];
    fso_data[1] = fso_data[2];
  }

  if (no_str_flag) {
    SWC_VC_B.i_a = 0;
    while (SWC_VC_B.i_a <= plan_params->num_points_no_str_perp - 4) {
      fso_data[SWC_VC_B.i_a] = SWC_VC_B.init_wheel_angle;
      SWC_VC_B.i_a++;
    }

    SWC_VC_B.qY_j = plan_params->num_points_no_str_perp - /*MW:OvSatOk*/ 2U;
    if (SWC_VC_B.qY_j > plan_params->num_points_no_str_perp) {
      SWC_VC_B.qY_j = 0U;
    }

    SWC_VC_B.qY_tmp_d = plan_params->num_points_no_str_perp - /*MW:OvSatOk*/ 3U;
    SWC_VC_B.qY_c = SWC_VC_B.qY_tmp_d;
    if (SWC_VC_B.qY_tmp_d > plan_params->num_points_no_str_perp) {
      SWC_VC_B.qY_c = 0U;
    }

    SWC_VC_B.qY_m = SWC_VC_B.qY_tmp_d;
    if (SWC_VC_B.qY_tmp_d > plan_params->num_points_no_str_perp) {
      SWC_VC_B.qY_m = 0U;
    }

    SWC_VC_B.i_a = plan_params->num_points_no_str_perp - 1;
    fso_data[(int32_T)SWC_VC_B.qY_j - 1] = (fso_data[SWC_VC_B.i_a] - fso_data
      [(int32_T)SWC_VC_B.qY_m - 1]) / 3.0F + fso_data[(int32_T)SWC_VC_B.qY_c - 1];
    SWC_VC_B.qY_j = plan_params->num_points_no_str_perp - /*MW:OvSatOk*/ 1U;
    if (SWC_VC_B.qY_j > plan_params->num_points_no_str_perp) {
      SWC_VC_B.qY_j = 0U;
    }

    SWC_VC_B.qY_c = SWC_VC_B.qY_tmp_d;
    if (SWC_VC_B.qY_tmp_d > plan_params->num_points_no_str_perp) {
      SWC_VC_B.qY_c = 0U;
      SWC_VC_B.qY_tmp_d = 0U;
    }

    fso_data[(int32_T)SWC_VC_B.qY_j - 1] = (fso_data[SWC_VC_B.i_a] - fso_data
      [(int32_T)SWC_VC_B.qY_tmp_d - 1]) * 2.0F / 3.0F + fso_data[(int32_T)
      SWC_VC_B.qY_c - 1];
  }

  fso_tmp = abs_NgDyBNHZ(SWC_VC_B.fio_dummy[0]);
  SWC_VC_B.i_a = fso_tmp + 2;
  if (SWC_VC_B.i_a > 32767) {
    SWC_VC_B.i_a = 32767;
  }

  SWC_VC_B.pp_tmp = fso_tmp + 3;
  if (SWC_VC_B.pp_tmp > 32767) {
    SWC_VC_B.pp_tmp = 32767;
  }

  fso_data[SWC_VC_B.i_a - 1] = fso_data[SWC_VC_B.pp_tmp - 1];
  SWC_VC_B.i_a = fso_tmp + 1;
  if (SWC_VC_B.i_a > 32767) {
    SWC_VC_B.i_a = 32767;
  }

  SWC_VC_B.pp_tmp = abs_NgDyBNHZ(SWC_VC_B.fio_dummy[0]) + 2;
  if (SWC_VC_B.pp_tmp > 32767) {
    SWC_VC_B.pp_tmp = 32767;
  }

  fso_data[SWC_VC_B.i_a - 1] = fso_data[SWC_VC_B.pp_tmp - 1];
  SWC_VC_B.i_a = abs_NgDyBNHZ(SWC_VC_B.fio_dummy[0]) + abs_NgDyBNHZ
    (SWC_VC_B.fio_dummy[1]);
  SWC_VC_B.pp_tmp = SWC_VC_B.i_a;
  if (SWC_VC_B.i_a > 32767) {
    SWC_VC_B.pp_tmp = 32767;
  } else {
    if (SWC_VC_B.i_a < -32768) {
      SWC_VC_B.pp_tmp = -32768;
    }
  }

  SWC_VC_B.pp_tmp += 2;
  if (SWC_VC_B.pp_tmp > 32767) {
    SWC_VC_B.pp_tmp = 32767;
  }

  if (SWC_VC_B.i_a > 32767) {
    SWC_VC_B.i_a = 32767;
  } else {
    if (SWC_VC_B.i_a < -32768) {
      SWC_VC_B.i_a = -32768;
    }
  }

  SWC_VC_B.i_a += 3;
  if (SWC_VC_B.i_a > 32767) {
    SWC_VC_B.i_a = 32767;
  }

  fso_data[SWC_VC_B.pp_tmp - 1] = fso_data[SWC_VC_B.i_a - 1];
  SWC_VC_B.init_wheel_angle = 3.6F * plan_params->StrRateLim_perp;
  SWC_VC_diff(fso_data, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  SWC_VC_B.des_wheel_angle = SWC_VC_B.tmp_size_g;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < SWC_VC_B.des_wheel_angle; SWC_VC_B.i_a++)
  {
    SWC_VC_B.tmp_data_l[SWC_VC_B.i_a] = SWC_VC_B.tmp_data_d[SWC_VC_B.i_a] /
      SWC_VC_B.dfx_data[SWC_VC_B.i_a];
  }

  SWC_VC_abs(SWC_VC_B.tmp_data_l, SWC_VC_B.tmp_data_d, &SWC_VC_B.tmp_size_g);
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 249; SWC_VC_B.i_a++) {
    SWC_VC_B.z_data[SWC_VC_B.i_a] = SWC_VC_B.init_wheel_angle /
      (SWC_VC_B.tmp_data_d[SWC_VC_B.i_a] + 0.01F);
  }

  SWC_VC_B.z_data[249] = SWC_VC_B.init_wheel_angle / 0.01F;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fvo_data[SWC_VC_B.i_a] = fminf(plan_params->V_max_perp,
      SWC_VC_B.z_data[SWC_VC_B.i_a]);
  }

  abs_fEIKHoQZ(SWC_VC_B.fio_dummy, SWC_VC_B.iv);
  fso_tmp = sum_d5YRIYyL(SWC_VC_B.iv);
  if (fso_tmp < 0) {
    fso_tmp = 0;
  }

  if ((uint16_T)fso_tmp > 0) {
    for (b_counter = (uint16_T)((uint16_T)fso_tmp + 1); b_counter < 251;
         b_counter++) {
      SWC_VC_B.des_wheel_angle = (uint16_T)fso_tmp - 1;
      SWC_VC_B.dc_i = b_counter - 1;
      fxo_data[SWC_VC_B.dc_i] = fxo_data[SWC_VC_B.des_wheel_angle];
      fyo_data[SWC_VC_B.dc_i] = fyo_data[SWC_VC_B.des_wheel_angle];
      fho_data[SWC_VC_B.dc_i] = fho_data[SWC_VC_B.des_wheel_angle];
      fso_data[SWC_VC_B.dc_i] = fso_data[SWC_VC_B.des_wheel_angle];
      fvo_data[SWC_VC_B.dc_i] = fvo_data[SWC_VC_B.des_wheel_angle];
    }
  }

  SWC_VC_mod(fxo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data,
             &SWC_VC_B.tmp_size_g);
  *fxo_size = 250;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fxo_data[SWC_VC_B.i_a] -= SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }

  SWC_VC_mod(fyo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data,
             &SWC_VC_B.tmp_size_g);
  *fyo_size = 250;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fyo_data[SWC_VC_B.i_a] -= SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }

  SWC_VC_mod(fho_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data,
             &SWC_VC_B.tmp_size_g);
  *fho_size = 250;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fho_data[SWC_VC_B.i_a] -= SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }

  SWC_VC_mod(fso_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data,
             &SWC_VC_B.tmp_size_g);
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fso_data[SWC_VC_B.i_a] -= SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }

  SWC_VC_mod(fvo_data, plan_params->PP_RES_DIST_TRAVEL, SWC_VC_B.fxo_12_data,
             &SWC_VC_B.tmp_size_g);
  *fvo_size = 250;
  for (SWC_VC_B.i_a = 0; SWC_VC_B.i_a < 250; SWC_VC_B.i_a++) {
    fvo_data[SWC_VC_B.i_a] -= SWC_VC_B.fxo_12_data[SWC_VC_B.i_a];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_renderPath_perp(const real32_T pii[30], const real32_T ps[8],
  real32_T fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fvo[250],
  real32_T fso[250], int16_T fio[10], int8_T *co)
{
  SWC_VC_B.expl_temp_m.vecLen_coeff_perp_single_sweep_XY =
    KeAP_vecLen_coeff_perp_single_sweep_XY;
  SWC_VC_B.expl_temp_m.vecLen_coeff_perp_single_sweep_Phi =
    KeAP_vecLen_coeff_perp_single_sweep_Phi;
  SWC_VC_B.expl_temp_m.vecLen_coeff_perp = KeAP_vecLen_coeff_perp;
  SWC_VC_B.expl_temp_m.V_max_perp = KeAP_V_max_perp;
  SWC_VC_B.expl_temp_m.turn_radius_single_sweep_perp =
    KeAP_turn_radius_single_sweep_perp;
  SWC_VC_B.expl_temp_m.turn_radius_park_out_perp_big =
    KeAP_turn_radius_park_out_perp_big;
  SWC_VC_B.expl_temp_m.turn_radius_park_out_perp =
    KeAP_turn_radius_park_out_perp;
  SWC_VC_B.expl_temp_m.straight_line_perp_park_out =
    KeAP_straight_line_perp_park_out;
  SWC_VC_B.expl_temp_m.StrRateLim_perp = KeAP_StrRateLim_perp;
  SWC_VC_B.expl_temp_m.str_wheel_ang_perp = KeAP_str_wheel_ang_perp;
  SWC_VC_B.expl_temp_m.single_sweep_start_min_lon_dist_m =
    KeAP_single_sweep_start_min_lon_dist_m;
  SWC_VC_B.expl_temp_m.single_sweep_start_min_lat_dist_m =
    SWC_VC_B.KeAP_single_sweep_start_min_lat_dist_m;
  SWC_VC_B.expl_temp_m.single_sweep_perp_width_lim =
    KeAP_single_sweep_perp_width_lim;
  SWC_VC_B.expl_temp_m.single_sweep_control_point_3_y_offset =
    KeAP_single_sweep_control_point_3_y_offset;
  SWC_VC_B.expl_temp_m.single_sweep_control_point_3_x_offset =
    KeAP_single_sweep_control_point_3_x_offset;
  SWC_VC_B.expl_temp_m.single_sweep_control_point_2_y_offset =
    KeAP_single_sweep_control_point_2_y_offset;
  SWC_VC_B.expl_temp_m.segment_3_length_perp_m = KeAP_segment_3_length_perp_m;
  SWC_VC_B.expl_temp_m.safety_lim_single_sweep_perp =
    KeAP_safety_lim_single_sweep_perp;
  SWC_VC_B.expl_temp_m.regen_mode = SWC_VC_DW.regen_mode;
  SWC_VC_B.expl_temp_m.PP_RES_DIST_TRAVEL = KeAP_PP_RES_DIST_TRAVEL;

  /* Inport: '<Root>/MeAP_m_ParkSpotType' */
  SWC_VC_B.expl_temp_m.PP = PSType;
  SWC_VC_B.expl_temp_m.Phi_lim_perp = KeAP_Phi_lim_perp;
  SWC_VC_B.expl_temp_m.Phi_resolution_perp = KeAP_Phi_resolution_perp;
  SWC_VC_B.expl_temp_m.parkout_perp_left = SWC_VC_B.DataTypeConversion6;
  SWC_VC_B.expl_temp_m.park_out_nose_in_end_pos_offset_Y_big =
    KeAP_park_out_nose_in_end_pos_offset_Y_big;
  SWC_VC_B.expl_temp_m.park_out_nose_in_end_pos_offset_Y_small =
    KeAP_park_out_nose_in_end_pos_offset_Y_small;
  SWC_VC_B.expl_temp_m.park_out_nose_in_end_pos_offset_X =
    KeAP_park_out_nose_in_end_pos_offset_X;
  SWC_VC_B.expl_temp_m.park_out_nose_in_brk_pos_offset_Y =
    KeAP_park_out_nose_in_brk_pos_offset_Y;
  SWC_VC_B.expl_temp_m.park_out_nose_in_brk_pos_offset_X =
    KeAP_park_out_nose_in_brk_pos_offset_X;
  SWC_VC_B.expl_temp_m.park_out_nose_in_angle = KeAP_park_out_nose_in_angle;
  SWC_VC_B.expl_temp_m.park_out = SWC_VC_B.RateTransition3_i;
  SWC_VC_B.expl_temp_m.p3_pos_lim_perp = KeAP_p3_pos_lim_perp;
  SWC_VC_B.expl_temp_m.num_waypoints = SWC_VC_num_waypoints;
  SWC_VC_B.expl_temp_m.num_points_no_str_perp = ((uint8_T)
    KeAP_num_points_no_str_perp);

  /* Inport: '<Root>/MeAP_b_PerpNoseIn' */
  SWC_VC_B.expl_temp_m.nose_in = MeAP_k_PerpNoseIn;
  SWC_VC_B.expl_temp_m.n_perp = ((uint8_T)KeAP_n_perp);
  SWC_VC_B.expl_temp_m.maxCurvature = MeAP_pm_maxCurvature;
  SWC_VC_B.expl_temp_m.n_per_segment = SWC_VC_n_per_segment;
  SWC_VC_B.expl_temp_m.lim_perp_PS4 = KeAP_lim_perp_PS4;
  SWC_VC_B.expl_temp_m.Ks = KeAP_Ks;
  SWC_VC_B.expl_temp_m.Kf_perp_single_sweep = KeAP_Kf_perp_single_sweep;
  SWC_VC_B.expl_temp_m.Kf_perp = KeAP_Kf_perp;
  SWC_VC_B.expl_temp_m.delta_s_perp = KeAP_delta_s_perp;
  SWC_VC_B.expl_temp_m.delta_s_nose_in_regen = KeAP_delta_s_nose_in_regen;
  SWC_VC_B.expl_temp_m.delta_s_no_str_perp = KeAP_delta_s_no_str_perp;
  SWC_VC_B.expl_temp_m.delta_s_clothoid_perp = KeAP_delta_s_clothoid_perp;
  SWC_VC_B.expl_temp_m.curvature_coeff_perp = KeAP_curvature_coeff_perp;
  SWC_VC_B.expl_temp_m.control_point_3_y_step_m = KeAP_control_point_3_y_step_m;
  SWC_VC_B.expl_temp_m.CurrentSweepVeh = SWC_VC_B.UnitDelay2;
  SWC_VC_B.expl_temp_o.Ke_AP_I_VehRearOverhang = MeAP_m_VehRearOverhang;
  SWC_VC_B.expl_temp_o.Ke_AP_I_VehWidth = MeAP_m_VehWidth;
  SWC_VC_B.expl_temp_o.Ke_AP_I_VehWheelbase = MeAP_m_VehWheelbase;
  SWC_VC_B.expl_temp_o.Ke_AP_I_VehFrontOverhang = MeAP_m_VehFrontOverhang;
  SWC_VC_renderPath_perp_common(pii, ps, &SWC_VC_B.expl_temp_m,
    SWC_VC_B.expl_temp_o, SWC_VC_B.fxoi_data, &SWC_VC_B.fxoi_size,
    SWC_VC_B.fyoi_data, &SWC_VC_B.fyoi_size, SWC_VC_B.fhoi_data,
    &SWC_VC_B.fhoi_size, SWC_VC_B.fvoi_data, &SWC_VC_B.fvoi_size,
    SWC_VC_B.fsoi_data, &SWC_VC_B.fsoi_size, fio, co);
  memcpy(&fxo[0], &SWC_VC_B.fxoi_data[0], 250U * sizeof(real32_T));
  memcpy(&fyo[0], &SWC_VC_B.fyoi_data[0], 250U * sizeof(real32_T));
  memcpy(&fho[0], &SWC_VC_B.fhoi_data[0], 250U * sizeof(real32_T));
  memcpy(&fvo[0], &SWC_VC_B.fvoi_data[0], 250U * sizeof(real32_T));
  memcpy(&fso[0], &SWC_VC_B.fsoi_data[0], 250U * sizeof(real32_T));
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_RENDER_PERP(void)
{
  boolean_T guard1 = false;
  guard1 = false;
  if (SWC_VC_DW.c1 < 0) {
    if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
         (SWC_VC_B.UnitDelay2 == 3))) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
      SWC_VC_B.i_f = 100 - SWC_VC_DW.c1;
      if (SWC_VC_B.i_f > 127) {
        SWC_VC_B.i_f = 127;
      }

      PP_state = (int8_T)SWC_VC_B.i_f;
      PP_Abort = true;
    } else if (SWC_VC_DW.regen_mode == 1.0F) {
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
      PP_state = 99;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    if (SWC_VC_DW.c1 == 1) {
      SWC_VC_DW.c1 = 0;
      SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_TRANSPOSE_INV;
      PP_state = 41;
    } else {
      SWC_VC_renderPath_perp(SWC_VC_DW.p_guide, SWC_VC_DW.PSL, SWC_VC_B.fx,
        SWC_VC_B.fy, SWC_VC_B.fh, SWC_VC_B.fv, SWC_VC_B.fs, SWC_VC_B.fi,
        &SWC_VC_DW.c1);
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_TFR_inv_common(real32_T fxi[250], real32_T fyi[250], real32_T
  fhi[250], real32_T fsi[250], const real32_T fvi[250], real32_T PSLi[8], const
  real32_T tfRi[3], boolean_T LeftPSi, real32_T plan_params_PP_RES_DIST_TRAVEL,
  real32_T fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fso[250],
  real32_T fvo[250], real32_T PSLo[8])
{
  real32_T z;
  int32_T i;
  real32_T fyi_0;
  real32_T fhi_0;
  real32_T fsi_0;
  real32_T Pwc_tmp_tmp;
  real32_T Pwc_tmp_tmp_0;
  int32_T fxi_tmp;
  int32_T fxi_tmp_0;
  static const int8_T b[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T c[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };

  for (i = 0; i < 250; i++) {
    fxi[i] += tfRi[1];
    fyi[i] += tfRi[2];
  }

  for (i = 0; i < 8; i++) {
    PSLi[i] = (tfRi[1] * (real32_T)b[i] + PSLi[i]) + tfRi[2] * (real32_T)c[i];
  }

  Pwc_tmp_tmp_0 = sinf(-tfRi[0]);
  Pwc_tmp_tmp = cosf(-tfRi[0]);
  z = tfRi[0] * 180.0F / 3.14159274F;
  for (i = 0; i < 250; i++) {
    fsi_0 = fsi[i];
    fhi_0 = fhi[i];
    fyi_0 = fyi[i];
    if (LeftPSi) {
      fyi_0 = -fyi[i];
      fhi_0 = -fhi[i];
      fsi_0 = -fsi[i];
    }

    fxi_tmp = i << 1;
    SWC_VC_B.fxi[fxi_tmp] = fxi[i];
    fxi_tmp_0 = fxi_tmp + 1;
    SWC_VC_B.fxi[fxi_tmp_0] = fyi_0;
    SWC_VC_B.Pwc[fxi_tmp] = 0.0F;
    SWC_VC_B.Pwc[fxi_tmp] += SWC_VC_B.fxi[fxi_tmp] * Pwc_tmp_tmp;
    SWC_VC_B.Pwc[fxi_tmp] += SWC_VC_B.fxi[fxi_tmp_0] * -Pwc_tmp_tmp_0;
    SWC_VC_B.Pwc[fxi_tmp_0] = 0.0F;
    SWC_VC_B.Pwc[fxi_tmp_0] += SWC_VC_B.fxi[fxi_tmp] * Pwc_tmp_tmp_0;
    SWC_VC_B.Pwc[fxi_tmp_0] += SWC_VC_B.fxi[fxi_tmp_0] * Pwc_tmp_tmp;
    fho[i] = fhi_0 - z;
    fsi[i] = fsi_0;
    fhi[i] = fhi_0;
    fyi[i] = fyi_0;
  }

  SWC_VC_B.PSLi_a[0] = PSLi[0];
  SWC_VC_B.PSLi_a[1] = PSLi[1];
  SWC_VC_B.PSLi_a[2] = PSLi[2];
  SWC_VC_B.PSLi_a[3] = PSLi[3];
  SWC_VC_B.PSLi_a[4] = PSLi[4];
  SWC_VC_B.PSLi_a[5] = PSLi[5];
  SWC_VC_B.PSLi_a[6] = PSLi[6];
  SWC_VC_B.PSLi_a[7] = PSLi[7];
  for (i = 0; i < 4; i++) {
    fxi_tmp = i << 1;
    PSLo[fxi_tmp] = 0.0F;
    PSLo[fxi_tmp] += SWC_VC_B.PSLi_a[fxi_tmp] * Pwc_tmp_tmp;
    fxi_tmp_0 = fxi_tmp + 1;
    PSLo[fxi_tmp] += SWC_VC_B.PSLi_a[fxi_tmp_0] * -Pwc_tmp_tmp_0;
    PSLo[fxi_tmp_0] = 0.0F;
    PSLo[fxi_tmp_0] += SWC_VC_B.PSLi_a[fxi_tmp] * Pwc_tmp_tmp_0;
    PSLo[fxi_tmp_0] += SWC_VC_B.PSLi_a[fxi_tmp_0] * Pwc_tmp_tmp;
  }

  for (i = 0; i < 250; i++) {
    SWC_VC_B.Pwc_d[i] = SWC_VC_B.Pwc[i << 1];
  }

  mod_GIkes8zg(SWC_VC_B.Pwc_d, plan_params_PP_RES_DIST_TRAVEL, SWC_VC_B.fv2);
  for (i = 0; i < 250; i++) {
    fxi_tmp = i << 1;
    fxo[i] = SWC_VC_B.Pwc[fxi_tmp] - SWC_VC_B.fv2[i];
    SWC_VC_B.Pwc_d[i] = SWC_VC_B.Pwc[fxi_tmp + 1];
  }

  mod_GIkes8zg(SWC_VC_B.Pwc_d, plan_params_PP_RES_DIST_TRAVEL, SWC_VC_B.fv2);
  mod_GIkes8zg(fho, plan_params_PP_RES_DIST_TRAVEL, SWC_VC_B.Pwc_d);
  mod_GIkes8zg(fsi, plan_params_PP_RES_DIST_TRAVEL, SWC_VC_B.fv1);
  mod_GIkes8zg(fvi, plan_params_PP_RES_DIST_TRAVEL, SWC_VC_B.fv_j);
  for (i = 0; i < 250; i++) {
    fyo[i] = SWC_VC_B.Pwc[(i << 1) + 1] - SWC_VC_B.fv2[i];
    fso[i] = fsi[i] - SWC_VC_B.fv1[i];
    fvo[i] = fvi[i] - SWC_VC_B.fv_j[i];
    fho[i] -= SWC_VC_B.Pwc_d[i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_TFR_inv(const real32_T fxi[250], const real32_T fyi[250],
  const real32_T fhi[250], const real32_T fsi[250], const real32_T fvi[250],
  const real32_T PSLi[8], const real32_T tfRi[3], boolean_T LeftPSi, real32_T
  fxo[250], real32_T fyo[250], real32_T fho[250], real32_T fso[250], real32_T
  fvo[250], real32_T PSLo[8], int8_T *co)
{
  int32_T i;
  memcpy(&SWC_VC_B.fxi_l[0], &fxi[0], 250U * sizeof(real32_T));
  memcpy(&SWC_VC_B.fyi[0], &fyi[0], 250U * sizeof(real32_T));
  memcpy(&SWC_VC_B.fhi[0], &fhi[0], 250U * sizeof(real32_T));
  memcpy(&SWC_VC_B.fsi[0], &fsi[0], 250U * sizeof(real32_T));
  for (i = 0; i < 8; i++) {
    SWC_VC_B.PSLi[i] = PSLi[i];
  }

  SWC_VC_TFR_inv_common(SWC_VC_B.fxi_l, SWC_VC_B.fyi, SWC_VC_B.fhi, SWC_VC_B.fsi,
                        fvi, SWC_VC_B.PSLi, tfRi, LeftPSi,
                        KeAP_PP_RES_DIST_TRAVEL, fxo, fyo, fho, fso, fvo, PSLo);
  *co = 1;
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_TRANSPOSE_INV(void)
{
  int32_T i;
  if (SWC_VC_DW.c1 == 1) {
    SWC_VC_DW.c1 = 0;
    SWC_VC_DW.regen_mode = 0.0F;
    SWC_VC_B.old_path = false;
    SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_FOLLOWING;
    PP_state = 5;
  } else {
    SWC_VC_TFR_inv(SWC_VC_B.fx, SWC_VC_B.fy, SWC_VC_B.fh, SWC_VC_B.fs,
                   SWC_VC_B.fv, SWC_VC_DW.PSL, SWC_VC_DW.tfR, SWC_VC_DW.LeftPS
                   != 0.0F, SWC_VC_B.fxo, SWC_VC_B.fyo, SWC_VC_B.fho,
                   SWC_VC_B.fso, SWC_VC_B.fvo, SWC_VC_B.PSLo, &SWC_VC_DW.c1);
    memcpy(&SWC_VC_B.fx[0], &SWC_VC_B.fxo[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fy[0], &SWC_VC_B.fyo[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fh[0], &SWC_VC_B.fho[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fs[0], &SWC_VC_B.fso[0], 250U * sizeof(real32_T));
    memcpy(&SWC_VC_B.fv[0], &SWC_VC_B.fvo[0], 250U * sizeof(real32_T));
    for (i = 0; i < 8; i++) {
      SWC_VC_DW.PSL[i] = SWC_VC_B.PSLo[i];
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_reset_plan(int16_T fio[10])
{
  int32_T i;
  for (i = 0; i < 10; i++) {
    fio[i] = 0;
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_enter_atomic_SCANNING(void)
{
  SWC_VC_DW.c1 = 0;
  PP_state = 1;
  SWC_VC_B.old_path = false;
  SWC_VC_DW.regen_mode = 0.0F;
  SWC_VC_reset_plan(SWC_VC_B.fi);
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_save_current_path(const real32_T fx_in[250], const real32_T
  fy_in[250], const real32_T fh_in[250], const real32_T fs_in[250], const
  real32_T fv_in[250], const int16_T fi_in[10], real32_T fx_out[250], real32_T
  fy_out[250], real32_T fh_out[250], real32_T fs_out[250], real32_T fv_out[250],
  int16_T fi_out[10])
{
  real32_T sum_indx_CurrentSweep;
  int32_T b_i;
  uint16_T d_i;
  int16_T b_y[10];
  int16_T d_y;
  int32_T i;
  uint32_T qY;
  for (i = 0; i < 10; i++) {
    fi_out[i] = 0;
  }

  qY = 10U - /*MW:OvSatOk*/ SWC_VC_B.UnitDelay1_m;
  if (qY > 10U) {
    qY = 0U;
  }

  for (i = 0; i < (int32_T)qY; i++) {
    if (SWC_VC_B.UnitDelay3 == SWC_VC_B.RateTransition2_j) {
      fi_out[i] = fi_in[(i + SWC_VC_B.UnitDelay1_m) - 1];
    } else {
      fi_out[i] = fi_in[i + SWC_VC_B.UnitDelay1_m];
    }
  }

  sum_indx_CurrentSweep = 0.0F;
  if (SWC_VC_B.UnitDelay3 == SWC_VC_B.RateTransition2_j) {
    i = SWC_VC_B.UnitDelay1_m - 1;
    if (fi_in[i] < 0) {
      i = -fi_in[i];
      if (i > 32767) {
        i = 32767;
      }

      sum_indx_CurrentSweep = -(real32_T)i;
    } else {
      sum_indx_CurrentSweep = -(real32_T)fi_in[i];
    }
  }

  for (b_i = 0; b_i < SWC_VC_B.UnitDelay1_m; b_i++) {
    if (fi_in[b_i] < 0) {
      i = -fi_in[b_i];
      if (i > 32767) {
        i = 32767;
      }

      d_y = (int16_T)i;
    } else {
      d_y = fi_in[b_i];
    }

    sum_indx_CurrentSweep += (real32_T)d_y;
  }

  for (b_i = 0; b_i < 10; b_i++) {
    if (fi_out[b_i] < 0) {
      i = -fi_out[b_i];
      if (i > 32767) {
        i = 32767;
      }

      b_y[b_i] = (int16_T)i;
    } else {
      b_y[b_i] = fi_out[b_i];
    }
  }

  d_y = b_y[0];
  for (b_i = 0; b_i < 9; b_i++) {
    i = b_y[b_i + 1] + d_y;
    if (i > 32767) {
      i = 32767;
    } else {
      if (i < -32768) {
        i = -32768;
      }
    }

    d_y = (int16_T)i;
  }

  for (b_i = 0; b_i < d_y; b_i++) {
    i = (int32_T)(((real32_T)b_i + 1.0F) + sum_indx_CurrentSweep) - 1;
    fx_out[b_i] = fx_in[i];
    fy_out[b_i] = fy_in[i];
    fh_out[b_i] = fh_in[i];
    fs_out[b_i] = fs_in[i];
    fv_out[b_i] = fv_in[i];
  }

  for (b_i = 0; b_i < 10; b_i++) {
    if (fi_out[b_i] < 0) {
      i = -fi_out[b_i];
      if (i > 32767) {
        i = 32767;
      }

      b_y[b_i] = (int16_T)i;
    } else {
      b_y[b_i] = fi_out[b_i];
    }
  }

  d_y = b_y[0];
  for (b_i = 0; b_i < 9; b_i++) {
    i = b_y[b_i + 1] + d_y;
    if (i > 32767) {
      i = 32767;
    } else {
      if (i < -32768) {
        i = -32768;
      }
    }

    d_y = (int16_T)i;
  }

  if (d_y < 0) {
    d_y = 0;
  }

  if ((uint16_T)d_y > 0) {
    for (d_i = (uint16_T)((uint16_T)d_y + 1); d_i < 251; d_i++) {
      i = (uint16_T)d_y - 1;
      b_i = d_i - 1;
      fx_out[b_i] = fx_out[i];
      fy_out[b_i] = fy_out[i];
      fh_out[b_i] = fh_out[i];
      fs_out[b_i] = fs_out[i];
      fv_out[b_i] = fv_out[i];
    }
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_enter_atomic_REGEN(void)
{
  int32_T i;
  PP_state = 55;
  SWC_VC_DW.regen_mode = 1.0F;
  SWC_VC_save_current_path(SWC_VC_B.fx, SWC_VC_B.fy, SWC_VC_B.fh, SWC_VC_B.fs,
    SWC_VC_B.fv, SWC_VC_B.fi, SWC_VC_DW.fx_old, SWC_VC_DW.fy_old,
    SWC_VC_DW.fh_old, SWC_VC_DW.fs_old, SWC_VC_DW.fv_old, SWC_VC_B.fi_out);
  for (i = 0; i < 10; i++) {
    SWC_VC_DW.fi_old[i] = SWC_VC_B.fi_out[i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_planPath_fishbone(const real32_T v[5], const real32_T ps[8],
  real32_T po_fb[30], int8_T *co)
{
  boolean_T forward_fishbone;
  real32_T ps_veh_angle;
  real32_T pps[2];
  real32_T mid_border;
  int32_T i;
  real32_T mid_street;
  real32_T mid_border_0;
  real32_T mid_street_idx_0;
  real32_T final_p_idx_0;
  real32_T final_p_idx_1;
  int32_T po_fb_tmp;
  *co = 1;
  forward_fishbone = false;
  pps[0] = ps[0] - ps[6];
  pps[1] = ps[1] - ps[7];
  if (norm_5ISqY4yY(pps) < FB_PS_min_width) {
    *co = -1;
  }

  mid_street = (ps[0] + ps[6]) / 2.0F;
  SWC_VC_B.mid_border[0] = (ps[2] + ps[4]) / 2.0F - mid_street;
  mid_street_idx_0 = mid_street;
  mid_street = (ps[1] + ps[7]) / 2.0F;
  SWC_VC_B.mid_border[1] = (ps[3] + ps[5]) / 2.0F - mid_street;
  ps_veh_angle = norm_5ISqY4yY(SWC_VC_B.mid_border);
  mid_border_0 = SWC_VC_B.mid_border[0] / ps_veh_angle;
  mid_border = cosf(3.14159274F - v[2]) * mid_border_0;
  SWC_VC_B.mid_border[0] = mid_border_0;
  mid_border_0 = SWC_VC_B.mid_border[1] / ps_veh_angle;
  mid_border += sinf(3.14159274F - v[2]) * mid_border_0;
  ps_veh_angle = 57.2957802F * acosf(mid_border);
  if (ps_veh_angle < 90.0F) {
    forward_fishbone = true;
    final_p_idx_1 = MeAP_m_VehRearOverhang + KeAP_FrontOffset;
    final_p_idx_0 = SWC_VC_B.mid_border[0] * final_p_idx_1 + mid_street_idx_0;
    final_p_idx_1 = mid_border_0 * final_p_idx_1 + mid_street;
  } else {
    if (ps_veh_angle > 90.0F) {
      final_p_idx_1 = (MeAP_m_VehFrontOverhang + MeAP_m_VehWheelbase) +
        KeAP_FrontOffset;
      final_p_idx_0 = SWC_VC_B.mid_border[0] * final_p_idx_1 + mid_street_idx_0;
      final_p_idx_1 = mid_border_0 * final_p_idx_1 + mid_street;
    }
  }

  SWC_VC_B.pp_j[0] = v[0];
  SWC_VC_B.pp_j[1] = v[1];
  memset(&SWC_VC_B.pp_j[2], 0, 18U * sizeof(real32_T));
  mid_street = -v[2] * 180.0F / 3.14159274F;
  SWC_VC_B.Phi_guideline_p5[0] = mid_street - 180.0F;
  for (i = 0; i < 9; i++) {
    SWC_VC_B.Phi_guideline_p5[i + 1] = 0.0F;
  }

  SWC_VC_B.Phi_guideline_p5[2] = -180.0F;
  SWC_VC_B.Phi_guideline_p5[3] = 57.2957802F * rt_atan2f_snf(-mid_border_0,
    -SWC_VC_B.mid_border[0]) - 180.0F * (real32_T)forward_fishbone;
  if (forward_fishbone) {
    SWC_VC_B.pp_j[4] = mid_street_idx_0 + break_point_fb;
    SWC_VC_B.pp_j[6] = final_p_idx_0 - SWC_VC_B.mid_border[0] * straight_line_fb;
  } else {
    SWC_VC_B.pp_j[4] = mid_street_idx_0 - break_point_fb;
    SWC_VC_B.pp_j[6] = final_p_idx_0 - SWC_VC_B.mid_border[0] * straight_line_fb
      * 2.5F;
  }

  SWC_VC_B.pp_j[8] = final_p_idx_0;
  if (forward_fishbone) {
    SWC_VC_B.pp_j[5] = SWC_VC_B.pp_j[1];
    SWC_VC_B.pp_j[7] = final_p_idx_1 - mid_border_0 * straight_line_fb;
  } else {
    SWC_VC_B.pp_j[5] = SWC_VC_B.pp_j[1];
    SWC_VC_B.pp_j[7] = final_p_idx_1 - mid_border_0 * straight_line_fb * 2.5F;
  }

  SWC_VC_B.pp_j[9] = final_p_idx_1;
  SWC_VC_B.Phi_guideline_p5[4] = SWC_VC_B.Phi_guideline_p5[3];
  SWC_VC_B.Phi_guideline_p5[7] = ps_veh_angle;
  SWC_VC_B.Phi_guideline_p5[8] = mid_street;
  SWC_VC_B.Phi_guideline_p5[9] = v[4] * 180.0F / 3.14159274F;
  for (i = 0; i < 10; i++) {
    po_fb_tmp = i << 1;
    po_fb[i] = SWC_VC_B.pp_j[po_fb_tmp];
    po_fb[i + 10] = SWC_VC_B.pp_j[po_fb_tmp + 1];
    po_fb[i + 20] = SWC_VC_B.Phi_guideline_p5[i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_planPath_para(const real32_T v[5], const real32_T ps[8],
  real32_T po_para[30], int8_T *co)
{
  real32_T init_wheel_angle;
  real32_T heading_angle;
  real32_T y_path;
  int32_T i;
  real32_T tmp;
  int32_T po_para_tmp;
  SWC_VC_B.pp_c[0] = v[0];
  SWC_VC_B.pp_c[1] = v[1];
  memset(&SWC_VC_B.pp_c[2], 0, 18U * sizeof(real32_T));
  heading_angle = -v[2] * 180.0F / 3.14159274F;
  SWC_VC_B.Phi_guideline_e[0] = heading_angle - 180.0F;
  for (i = 0; i < 9; i++) {
    SWC_VC_B.Phi_guideline_e[i + 1] = 0.0F;
  }

  if (!SWC_VC_B.RateTransition3_i) {
    init_wheel_angle = sinf(-v[2]);
    y_path = cosf(-v[2]);
    tmp = MeAP_m_VehWidth / 2.0F;
    if (heading_angle < rt_atan2f_snf(ps[1] - ((init_wheel_angle *
           MeAP_m_VehRearOverhang + y_path * tmp) + SWC_VC_B.pp_c[1]), ps[0] -
         ((y_path * MeAP_m_VehRearOverhang + -init_wheel_angle * tmp) +
          SWC_VC_B.pp_c[0])) * 57.2957802F) {
      if (ps[0] - SWC_VC_B.pp_c[0] > KeAP_app_ctrl_min_dist_x_para) {
        init_wheel_angle = v[4] * 180.0F / 3.14159274F;
        y_path = SWC_VC_B.pp_c[1];
        for (i = 0; i <= ((uint8_T)KeAP_num_points_no_str_para) - 2; i++) {
          tmp = init_wheel_angle;
          tand_brbYAlcS(&tmp);
          heading_angle = (-tmp * KeAP_delta_s_no_str_para / MeAP_m_VehWheelbase
                           + heading_angle * 3.14159274F / 180.0F) * 180.0F /
            3.14159274F;
          tmp = heading_angle;
          sind_7is3Ljjc(&tmp);
          y_path -= -(KeAP_delta_s_no_str_para * tmp);
        }

        SWC_VC_B.pp_c[2] = ps[1];
        SWC_VC_B.pp_c[3] = y_path;
        SWC_VC_B.Phi_guideline_e[1] = heading_angle - 180.0F;
      } else {
        SWC_VC_B.pp_c[2] = SWC_VC_B.pp_c[0];
        SWC_VC_B.pp_c[3] = SWC_VC_B.pp_c[1];
        SWC_VC_B.Phi_guideline_e[1] = -v[2] * 180.0F / 3.14159274F - 180.0F;
      }
    } else {
      if (ps[0] - SWC_VC_B.pp_c[0] > KeAP_app_ctrl_min_dist_x_para) {
        SWC_VC_B.pp_c[2] = ps[0] + KeAP_break_point_para[0];
        SWC_VC_B.pp_c[3] = ps[1] + KeAP_break_point_para[1];
      } else {
        SWC_VC_B.pp_c[2] = SWC_VC_B.pp_c[0];
        SWC_VC_B.pp_c[3] = SWC_VC_B.pp_c[1];
      }

      SWC_VC_B.Phi_guideline_e[1] = -v[2] * 180.0F / 3.14159274F - 180.0F;
    }

    SWC_VC_B.pp_c[18] = (ps[6] - MeAP_m_VehRearOverhang) - ((ps[6] - ps[0]) -
      ((MeAP_m_VehFrontOverhang + MeAP_m_VehWheelbase) + MeAP_m_VehRearOverhang))
      / 2.0F;
    SWC_VC_B.pp_c[19] = ((ps[3] + ps[5]) / 2.0F - MeAP_m_VehWidth / 2.0F) +
      KeAP_para_final_curb_offset;
    SWC_VC_B.Phi_guideline_e[9] = v[4] * 180.0F / 3.14159274F;
  } else {
    SWC_VC_B.Phi_guideline_e[9] = v[4] * 180.0F / 3.14159274F;
  }

  for (i = 0; i < 10; i++) {
    po_para_tmp = i << 1;
    po_para[i] = SWC_VC_B.pp_c[po_para_tmp];
    po_para[i + 10] = SWC_VC_B.pp_c[po_para_tmp + 1];
    po_para[i + 20] = SWC_VC_B.Phi_guideline_e[i];
  }

  *co = 1;
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_planPath_perp(const real32_T v[5], const real32_T ps[8],
  real32_T po_perp[30], int8_T *co)
{
  real32_T actual_spot_length_y;
  real32_T vehicle_length_y;
  real32_T front_buffer_y;
  real32_T x_path;
  real32_T y_path;
  uint8_T i;
  real32_T f;
  int32_T i_0;
  real32_T final_p_idx_1;
  int32_T po_perp_tmp;
  real32_T Phi_guideline_tmp;
  SWC_VC_B.pp_h[0] = v[0];
  SWC_VC_B.pp_h[1] = v[1];
  memset(&SWC_VC_B.pp_h[2], 0, 18U * sizeof(real32_T));
  Phi_guideline_tmp = -v[2] * 180.0F / 3.14159274F;
  SWC_VC_B.Phi_guideline_a[0] = Phi_guideline_tmp - 180.0F;
  for (i_0 = 0; i_0 < 9; i_0++) {
    SWC_VC_B.Phi_guideline_a[i_0 + 1] = 0.0F;
  }

  if (!SWC_VC_B.RateTransition3_i) {
    actual_spot_length_y = ps[5] - ps[1];
    final_p_idx_1 = MeAP_m_VehFrontOverhang + MeAP_m_VehWheelbase;
    vehicle_length_y = final_p_idx_1 + MeAP_m_VehRearOverhang;
    front_buffer_y = KeAP_FrontOffset;
    if (actual_spot_length_y < vehicle_length_y + KeAP_FrontOffset) {
      front_buffer_y = actual_spot_length_y - vehicle_length_y;
    }

    /* Inport: '<Root>/MeAP_b_PerpNoseIn' */
    if (!MeAP_k_PerpNoseIn) {
      actual_spot_length_y = (ps[2] + ps[4]) / 2.0F;
      final_p_idx_1 = (ps[1] + ps[7]) / 2.0F + (final_p_idx_1 + front_buffer_y);
      if (Phi_guideline_tmp - 180.0F < rt_atan2f_snf((SWC_VC_B.pp_h[1] - ps[1])
           + 1.0F, SWC_VC_B.pp_h[0] - ps[0]) * 57.2957802F + KeAP_aux_alpha) {
        if (ps[0] - SWC_VC_B.pp_h[0] > KeAP_app_ctrl_min_dist_x_perp) {
          front_buffer_y = v[4] * 180.0F / 3.14159274F;
          vehicle_length_y = Phi_guideline_tmp;
          x_path = SWC_VC_B.pp_h[0];
          y_path = SWC_VC_B.pp_h[1];
          for (i = 2U; i <= ((uint8_T)KeAP_num_points_no_str_perp); i++) {
            f = front_buffer_y;
            tand_brbYAlcS(&f);
            vehicle_length_y = (-f * KeAP_delta_s_no_str_perp /
                                MeAP_m_VehWheelbase + vehicle_length_y *
                                3.14159274F / 180.0F) * 180.0F / 3.14159274F;
            f = vehicle_length_y;
            cosd_KZN3FnAl(&f);
            x_path -= -(KeAP_delta_s_no_str_perp * f);
            f = vehicle_length_y;
            sind_7is3Ljjc(&f);
            y_path -= -(KeAP_delta_s_no_str_perp * f);
          }

          SWC_VC_B.pp_h[2] = x_path;
          SWC_VC_B.pp_h[3] = y_path;
          SWC_VC_B.Phi_guideline_a[1] = vehicle_length_y - 180.0F;
        } else {
          SWC_VC_B.pp_h[2] = SWC_VC_B.pp_h[0];
          SWC_VC_B.pp_h[3] = SWC_VC_B.pp_h[1];
          SWC_VC_B.Phi_guideline_a[1] = SWC_VC_B.Phi_guideline_a[0];
        }
      } else if (ps[0] - SWC_VC_B.pp_h[0] > KeAP_app_ctrl_min_dist_x_perp) {
        SWC_VC_B.pp_h[2] = ps[0] + KeAP_break_point_perp[0];
        SWC_VC_B.pp_h[3] = ps[1] + KeAP_break_point_perp[1];
        SWC_VC_B.Phi_guideline_a[1] = -170.0F;
      } else {
        SWC_VC_B.pp_h[2] = SWC_VC_B.pp_h[0];
        SWC_VC_B.pp_h[3] = SWC_VC_B.pp_h[1];
        SWC_VC_B.Phi_guideline_a[1] = SWC_VC_B.Phi_guideline_a[0];
      }

      if ((actual_spot_length_y > SWC_VC_B.pp_h[0] + 0.5F) && (-v[2] * 180.0F /
           3.14159274F - 180.0F < -125.0F)) {
        front_buffer_y = KeAP_yaw_control_point_3_perp_deg;
        sind_7is3Ljjc(&front_buffer_y);
        vehicle_length_y = KeAP_yaw_control_point_3_perp_deg;
        cosd_KZN3FnAl(&vehicle_length_y);
        SWC_VC_B.pp_h[4] = (ps[6] - MeAP_m_VehRearOverhang * front_buffer_y) -
          MeAP_m_VehWidth / 2.0F * vehicle_length_y;
        SWC_VC_B.pp_h[4] += KeAP_control_point_3_x_adjust_m;
        if (SWC_VC_B.pp_h[4] > actual_spot_length_y) {
          SWC_VC_B.pp_h[4] = actual_spot_length_y;
        }

        SWC_VC_B.pp_h[5] = ps[7] + KeAP_control_point_3_y_step_m;
        front_buffer_y = KeAP_yaw_control_point_3_perp_deg;
        cosd_KZN3FnAl(&front_buffer_y);
        vehicle_length_y = KeAP_yaw_control_point_3_perp_deg;
        tand_brbYAlcS(&vehicle_length_y);
        front_buffer_y = ((SWC_VC_B.pp_h[4] - ps[0]) - MeAP_m_VehWidth / 2.0F /
                          front_buffer_y) / vehicle_length_y;
        while (SWC_VC_B.pp_h[5] - ps[7] > front_buffer_y) {
          SWC_VC_B.pp_h[5] -= 0.1F;
        }

        SWC_VC_B.Phi_guideline_a[2] = (atanf((ps[5] - ps[7]) / (ps[4] - ps[6])) *
          57.2957802F - KeAP_yaw_control_point_3_perp_deg) - 180.0F;
        if (Phi_guideline_tmp < -10.0F) {
          front_buffer_y = sinf(-v[2] + 3.14159274F);
          vehicle_length_y = cosf(-v[2] + 3.14159274F);
          x_path = (ps[0] - 1.5F) - SWC_VC_B.pp_h[4];
          y_path = SWC_VC_B.pp_h[3] - SWC_VC_B.pp_h[5];
          SWC_VC_B.pp_h[4] = (vehicle_length_y * x_path + -front_buffer_y *
                              y_path) + (ps[0] - 1.5F);
          SWC_VC_B.pp_h[5] = (front_buffer_y * x_path + vehicle_length_y *
                              y_path) + SWC_VC_B.pp_h[3];
          if (ps[0] - SWC_VC_B.pp_h[0] < KeAP_p3_pos_lim_perp) {
            SWC_VC_B.pp_h[4] += KeAP_p3_adj_perp[0];
            SWC_VC_B.pp_h[5] += KeAP_p3_adj_perp[1];
          }
        }
      } else {
        SWC_VC_B.pp_h[4] = SWC_VC_B.pp_h[2];
        SWC_VC_B.pp_h[5] = SWC_VC_B.pp_h[3];
        SWC_VC_B.Phi_guideline_a[2] = SWC_VC_B.Phi_guideline_a[1];
      }

      if ((actual_spot_length_y < SWC_VC_B.pp_h[0] + 0.5F) || (-v[2] * 180.0F /
           3.14159274F - 180.0F < -125.0F)) {
        SWC_VC_B.pp_h[6] = (actual_spot_length_y - 1.4F) + 0.35F;
        SWC_VC_B.pp_h[7] = SWC_VC_B.pp_h[5] - 2.3F;
        SWC_VC_B.Phi_guideline_a[3] = -135.0F;
      } else {
        SWC_VC_B.pp_h[6] = SWC_VC_B.pp_h[4];
        SWC_VC_B.pp_h[7] = SWC_VC_B.pp_h[5];
        SWC_VC_B.Phi_guideline_a[3] = SWC_VC_B.Phi_guideline_a[2];
      }

      if (!(SWC_VC_DW.regen_mode != 0.0F)) {
        SWC_VC_B.pp_h[8] = actual_spot_length_y;
        SWC_VC_B.pp_h[9] = fminf((real32_T)(Phi_guideline_tmp < 0.0F) * 4.0F +
          (SWC_VC_B.pp_h[5] + 4.0F), final_p_idx_1 - 2.0F);
      } else {
        SWC_VC_B.pp_h[8] = actual_spot_length_y;
        SWC_VC_B.pp_h[9] = fminf((real32_T)(Phi_guideline_tmp < 0.0F) * 4.0F +
          (SWC_VC_B.pp_h[5] + 4.0F), final_p_idx_1 - 2.0F);
      }

      SWC_VC_B.Phi_guideline_a[4] = -90.0F;
      SWC_VC_B.pp_h[10] = actual_spot_length_y;
      SWC_VC_B.pp_h[11] = final_p_idx_1;
      SWC_VC_B.Phi_guideline_a[5] = -90.0F;
    } else {
      actual_spot_length_y = (ps[0] + ps[6]) / 2.0F;
      final_p_idx_1 = (ps[1] + ps[7]) / 2.0F + (MeAP_m_VehRearOverhang +
        front_buffer_y);
      SWC_VC_B.Phi_guideline_a[3] = 90.0F;
      SWC_VC_B.pp_h[6] = actual_spot_length_y;
      SWC_VC_B.pp_h[8] = actual_spot_length_y;
      SWC_VC_B.pp_h[7] = final_p_idx_1 - 1.0F;
      SWC_VC_B.pp_h[9] = final_p_idx_1;
      SWC_VC_B.Phi_guideline_a[4] = 90.0F;
    }

    /* End of Inport: '<Root>/MeAP_b_PerpNoseIn' */
    SWC_VC_B.Phi_guideline_a[8] = Phi_guideline_tmp;
    SWC_VC_B.Phi_guideline_a[9] = v[4] * 180.0F / 3.14159274F;
  }

  for (i_0 = 0; i_0 < 10; i_0++) {
    po_perp_tmp = i_0 << 1;
    po_perp[i_0] = SWC_VC_B.pp_h[po_perp_tmp];
    po_perp[i_0 + 10] = SWC_VC_B.pp_h[po_perp_tmp + 1];
    po_perp[i_0 + 20] = SWC_VC_B.Phi_guideline_a[i_0];
  }

  *co = 1;
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_TFR_common(const real32_T EgoCoordinates[5], real32_T
  ParkingSpotCoordinates[8], real32_T ParkingSpotType, const
  s46ZhDOfhHDUZ8M92mIUzjH_SWC_VC_T *plan_params, real32_T tfRo[3], real32_T
  tfPS[8], real32_T vo[5], boolean_T *left)
{
  real32_T safety_lim_f;
  real32_T safety_lim_r;
  real32_T safety_lim_s;
  int32_T i;
  real32_T tfPS_tmp_tmp;
  real32_T tfPS_tmp_tmp_0;
  int32_T tfPS_tmp;
  int32_T tfPS_tmp_0;
  boolean_T tmp;
  static const int8_T b[8] = { 1, 0, 1, 0, 1, 0, 1, 0 };

  static const int8_T e[8] = { 0, 1, 0, 1, 0, 1, 0, 1 };

  *left = false;
  if (((ParkingSpotType == 3.0F) || (ParkingSpotType == 4.0F)) &&
      plan_params->park_out && plan_params->nose_in) {
    SWC_VC_B.ParkingSpotCoordinates_a[0] = ParkingSpotCoordinates[4];
    SWC_VC_B.ParkingSpotCoordinates_a[4] = ParkingSpotCoordinates[0];
    SWC_VC_B.ParkingSpotCoordinates_a[1] = ParkingSpotCoordinates[5];
    SWC_VC_B.ParkingSpotCoordinates_a[5] = ParkingSpotCoordinates[1];
    SWC_VC_B.ParkingSpotCoordinates_a[2] = ParkingSpotCoordinates[6];
    SWC_VC_B.ParkingSpotCoordinates_a[6] = ParkingSpotCoordinates[2];
    SWC_VC_B.ParkingSpotCoordinates_a[3] = ParkingSpotCoordinates[7];
    SWC_VC_B.ParkingSpotCoordinates_a[7] = ParkingSpotCoordinates[3];
    for (i = 0; i < 8; i++) {
      ParkingSpotCoordinates[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
    }
  }

  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[0] = ParkingSpotCoordinates[0];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[1] = ParkingSpotCoordinates[1];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[2] = ParkingSpotCoordinates[2];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[3] = ParkingSpotCoordinates[3];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[4] = ParkingSpotCoordinates[4];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[5] = ParkingSpotCoordinates[5];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[6] = ParkingSpotCoordinates[6];
  SWC_VC_B.ParkingSpotCoordRow1XRow2Y[7] = ParkingSpotCoordinates[7];
  safety_lim_f = 0.0F;
  safety_lim_r = 0.0F;
  safety_lim_s = 0.0F;
  if ((ParkingSpotType == 1.0F) || (ParkingSpotType == 2.0F)) {
    safety_lim_f = plan_params->safety_lim_para_f;
    safety_lim_r = plan_params->safety_lim_para_r;
    safety_lim_s = plan_params->safety_lim_para_s;
  } else if ((ParkingSpotType == 3.0F) || (ParkingSpotType == 4.0F)) {
    if (!plan_params->nose_in) {
      safety_lim_f = plan_params->safety_lim_perp_f;
      safety_lim_r = plan_params->safety_lim_perp_r;
      safety_lim_s = plan_params->safety_lim_perp_s;
    } else {
      safety_lim_f = plan_params->safety_lim_nz_f;
      safety_lim_r = plan_params->safety_lim_nz_r;
      safety_lim_s = plan_params->safety_lim_nz_s;
    }
  } else {
    if ((ParkingSpotType == 5.0F) || (ParkingSpotType == 6.0F)) {
      safety_lim_f = plan_params->safety_lim_fb_f;
      safety_lim_r = plan_params->safety_lim_fb_r;
      safety_lim_s = plan_params->safety_lim_fb_s;
    }
  }

  tfRo[0] = -rt_atan2f_snf(ParkingSpotCoordinates[7] - ParkingSpotCoordinates[1],
    ParkingSpotCoordinates[6] - ParkingSpotCoordinates[0]);
  if ((ParkingSpotType == 5.0F) || (ParkingSpotType == 6.0F)) {
    tfRo[0] = 0.0F;
  }

  tmp = !plan_params->park_out;
  if ((!(plan_params->regen_mode != 0.0F)) && tmp) {
    if ((ParkingSpotType == 1.0F) || (ParkingSpotType == 2.0F)) {
      tfRo[0] += plan_params->aux_offset[2] * 3.14159274F / 180.0F;
    } else if ((ParkingSpotType == 3.0F) || (ParkingSpotType == 4.0F)) {
      if (!plan_params->nose_in) {
        tfRo[0] += plan_params->aux_offset[5] * 3.14159274F / 180.0F;
      } else {
        tfRo[0] += plan_params->aux_offset[11] * 3.14159274F / 180.0F;
      }
    } else {
      if ((ParkingSpotType == 5.0F) || (ParkingSpotType == 6.0F)) {
        tfRo[0] += plan_params->aux_offset[8] * 3.14159274F / 180.0F;
      }
    }
  }

  tfPS_tmp_tmp_0 = sinf(tfRo[0]);
  tfPS_tmp_tmp = cosf(tfRo[0]);
  for (i = 0; i < 4; i++) {
    tfPS_tmp = i << 1;
    tfPS[tfPS_tmp] = 0.0F;
    tfPS[tfPS_tmp] += SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] *
      tfPS_tmp_tmp;
    tfPS_tmp_0 = tfPS_tmp + 1;
    tfPS[tfPS_tmp] += SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp_0] *
      -tfPS_tmp_tmp_0;
    tfPS[tfPS_tmp_0] = 0.0F;
    tfPS[tfPS_tmp_0] += SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] *
      tfPS_tmp_tmp_0;
    tfPS[tfPS_tmp_0] += SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp_0] *
      tfPS_tmp_tmp;
  }

  vo[0] = tfPS_tmp_tmp * EgoCoordinates[0] + -tfPS_tmp_tmp_0 * EgoCoordinates[1];
  tfPS_tmp_tmp_0 = tfPS_tmp_tmp_0 * EgoCoordinates[0] + tfPS_tmp_tmp *
    EgoCoordinates[1];
  vo[1] = tfPS_tmp_tmp_0;
  vo[2] = -0.0174532924F * EgoCoordinates[2] - tfRo[0];
  vo[3] = 0.0174532924F * EgoCoordinates[3];
  vo[4] = 0.0174532924F * EgoCoordinates[4];
  while (vo[2] > 3.1415926535897931) {
    vo[2] -= 6.28318548F;
  }

  while (vo[2] < -3.1415926535897931) {
    vo[2] += 6.28318548F;
  }

  for (i = 0; i < 4; i++) {
    tfPS_tmp = i << 1;
    SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
    SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
    tfPS_tmp++;
    SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
    SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
  }

  if (SWC_VC_B.ParkingSpotCoordinates_a[1] >
      SWC_VC_B.ParkingSpotCoordRow1XRow2Y[3]) {
    *left = true;
    for (i = 0; i < 4; i++) {
      tfPS_tmp = i << 1;
      SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
      tfPS_tmp++;
      SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
    }

    tfPS[1] = -SWC_VC_B.ParkingSpotCoordinates_a[1];
    tfPS[3] = -SWC_VC_B.ParkingSpotCoordinates_a[3];
    tfPS[5] = -SWC_VC_B.ParkingSpotCoordinates_a[5];
    tfPS[7] = -SWC_VC_B.ParkingSpotCoordinates_a[7];
    vo[1] = -tfPS_tmp_tmp_0;
    vo[2] = -vo[2];
    vo[4] = -vo[4];
  }

  if (!plan_params->park_out) {
    SWC_VC_B.ParkingSpotCoordinates_a[0] = tfPS[0] + safety_lim_f;
    SWC_VC_B.ParkingSpotCoordinates_a[2] = tfPS[2] + safety_lim_f;
    SWC_VC_B.ParkingSpotCoordinates_a[4] = tfPS[4] + -safety_lim_r;
    SWC_VC_B.ParkingSpotCoordinates_a[6] = tfPS[6] + -safety_lim_r;
    SWC_VC_B.ParkingSpotCoordinates_a[1] = tfPS[1];
    SWC_VC_B.ParkingSpotCoordinates_a[3] = tfPS[3] + -safety_lim_s;
    SWC_VC_B.ParkingSpotCoordinates_a[5] = tfPS[5] + -safety_lim_s;
    SWC_VC_B.ParkingSpotCoordinates_a[7] = tfPS[7];
    for (i = 0; i < 8; i++) {
      tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
    }
  }

  if ((ParkingSpotType == 1.0F) || (ParkingSpotType == 2.0F)) {
    for (i = 0; i < 4; i++) {
      tfPS_tmp = i << 1;
      SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
      SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
      tfPS_tmp++;
      SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
      SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
    }

    if (SWC_VC_B.ParkingSpotCoordinates_a[6] -
        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[0] > 7.0F) {
      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
      }

      tfPS[4] = SWC_VC_B.ParkingSpotCoordinates_a[2] + 7.0F;
      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
      }

      tfPS[6] = SWC_VC_B.ParkingSpotCoordinates_a[0] + 7.0F;
    }
  } else {
    if ((ParkingSpotType == 3.0F) || (ParkingSpotType == 4.0F)) {
      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
      }

      if (SWC_VC_B.ParkingSpotCoordinates_a[6] -
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[0] > 3.25F) {
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
        }

        safety_lim_f = (SWC_VC_B.ParkingSpotCoordinates_a[0] +
                        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[6]) / 2.0F;
        tfPS[0] = safety_lim_f - 1.625F;
        tfPS[2] = safety_lim_f - 1.625F;
        tfPS[4] = safety_lim_f + 1.625F;
        tfPS[6] = safety_lim_f + 1.625F;
      }

      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
      }

      if (SWC_VC_B.ParkingSpotCoordinates_a[6] -
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[0] < 2.51) {
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
          SWC_VC_B.ParkingSpotCoordRow1XRow2Y[tfPS_tmp] = tfPS[tfPS_tmp];
        }

        safety_lim_f = (SWC_VC_B.ParkingSpotCoordinates_a[0] +
                        SWC_VC_B.ParkingSpotCoordRow1XRow2Y[6]) / 2.0F;
        tfPS[0] = safety_lim_f - 1.325F;
        tfPS[2] = safety_lim_f - 1.325F;
        tfPS[4] = safety_lim_f + 1.325F;
        tfPS[6] = safety_lim_f + 1.325F;
      }
    }
  }

  if ((!(plan_params->regen_mode != 0.0F)) && tmp) {
    if ((ParkingSpotType == 1.0F) || (ParkingSpotType == 2.0F)) {
      safety_lim_f = plan_params->aux_offset[0];
      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] - (real32_T)
          b[tfPS_tmp] * safety_lim_f;
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] - (real32_T)
          b[tfPS_tmp] * safety_lim_f;
      }

      for (i = 0; i < 8; i++) {
        tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
      }

      safety_lim_f = plan_params->aux_offset[1];
      for (i = 0; i < 4; i++) {
        tfPS_tmp = i << 1;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] - (real32_T)
          e[tfPS_tmp] * safety_lim_f;
        tfPS_tmp++;
        SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] - (real32_T)
          e[tfPS_tmp] * safety_lim_f;
      }

      for (i = 0; i < 8; i++) {
        tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
      }
    } else if ((ParkingSpotType == 3.0F) || (ParkingSpotType == 4.0F)) {
      if (!plan_params->nose_in) {
        safety_lim_f = plan_params->aux_offset[3];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }

        safety_lim_f = plan_params->aux_offset[4];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }
      } else {
        safety_lim_f = plan_params->aux_offset[9];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }

        safety_lim_f = plan_params->aux_offset[10];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }
      }
    } else {
      if ((ParkingSpotType == 5.0F) || (ParkingSpotType == 6.0F)) {
        safety_lim_f = plan_params->aux_offset[6];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)b[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }

        safety_lim_f = plan_params->aux_offset[7];
        for (i = 0; i < 4; i++) {
          tfPS_tmp = i << 1;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
          tfPS_tmp++;
          SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp] -
            (real32_T)e[tfPS_tmp] * safety_lim_f;
        }

        for (i = 0; i < 8; i++) {
          tfPS[i] = SWC_VC_B.ParkingSpotCoordinates_a[i];
        }
      }
    }
  }

  tfRo[1] = vo[0];
  vo[0] -= vo[0];
  tfRo[2] = vo[1];
  vo[1] -= vo[1];
  for (i = 0; i < 4; i++) {
    tfPS_tmp = i << 1;
    SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
    tfPS_tmp++;
    SWC_VC_B.ParkingSpotCoordinates_a[tfPS_tmp] = tfPS[tfPS_tmp];
  }

  for (i = 0; i < 8; i++) {
    tfPS[i] = (SWC_VC_B.ParkingSpotCoordinates_a[i] - tfRo[1] * (real32_T)b[i])
      - tfRo[2] * (real32_T)e[i];
  }
}

/* Function for Chart: '<S59>/Chart1' */
static void SWC_VC_TFR(const real32_T EgoCoordinates[5], const real32_T
  ParkingSpotCoordinates[8], real32_T ParkingSpotType, real32_T tfRo[3],
  real32_T tfPS[8], real32_T vo[5], boolean_T *left, int8_T *co)
{
  int32_T i;
  SWC_VC_B.expl_temp_c.safety_lim_fb_s = KeAP_safety_lim_fb_s;
  SWC_VC_B.expl_temp_c.safety_lim_fb_r = KeAP_safety_lim_fb_r;
  SWC_VC_B.expl_temp_c.safety_lim_fb_f = KeAP_safety_lim_fb_f;
  SWC_VC_B.expl_temp_c.safety_lim_nz_s = KeAP_safety_lim_nz_s;
  SWC_VC_B.expl_temp_c.safety_lim_nz_r = KeAP_safety_lim_nz_r;
  SWC_VC_B.expl_temp_c.safety_lim_nz_f = KeAP_safety_lim_nz_f;
  SWC_VC_B.expl_temp_c.safety_lim_perp_s = KeAP_safety_lim_perp_s;
  SWC_VC_B.expl_temp_c.safety_lim_perp_r = KeAP_safety_lim_perp_r;
  SWC_VC_B.expl_temp_c.safety_lim_perp_f = KeAP_safety_lim_perp_f;
  SWC_VC_B.expl_temp_c.safety_lim_para_s = KeAP_safety_lim_para_s;
  SWC_VC_B.expl_temp_c.safety_lim_para_r = KeAP_safety_lim_para_r;
  SWC_VC_B.expl_temp_c.safety_lim_para_f = KeAP_safety_lim_para_f;
  SWC_VC_B.expl_temp_c.regen_mode = SWC_VC_DW.regen_mode;
  SWC_VC_B.expl_temp_c.park_out = SWC_VC_B.RateTransition3_i;

  /* Inport: '<Root>/MeAP_b_PerpNoseIn' */
  SWC_VC_B.expl_temp_c.nose_in = MeAP_k_PerpNoseIn;
  for (i = 0; i < 12; i++) {
    SWC_VC_B.expl_temp_c.aux_offset[i] =
      SWC_VC_B.TmpSignalConversionAtSFunctionInport14[i];
  }

  for (i = 0; i < 8; i++) {
    SWC_VC_B.ParkingSpotCoordinates[i] = ParkingSpotCoordinates[i];
  }

  SWC_VC_TFR_common(EgoCoordinates, SWC_VC_B.ParkingSpotCoordinates,
                    ParkingSpotType, &SWC_VC_B.expl_temp_c, tfRo, tfPS, vo, left);
  *co = 1;
}

/* Function for MATLAB Function: '<S82>/MATLAB Function PathSeparation' */
static real_T SWC_VC_sum_i(const uint8_T x_data[], const int32_T *x_size)
{
  real_T y;
  int32_T k;
  y = x_data[0];
  for (k = 2; k <= *x_size; k++) {
    y += (real_T)x_data[k - 1];
  }

  return y;
}

/* Function for MATLAB Function: '<S83>/MATLAB Function' */
static void SWC_VC_power_e(const real32_T a_data[], const int32_T a_size[2],
  real32_T y_data[], int32_T y_size[2])
{
  int32_T loop_ub;
  y_size[1] = (uint8_T)a_size[1];
  loop_ub = y_size[1] - 1;
  if (0 <= loop_ub) {
    memcpy(&SWC_VC_B.z1_data[0], &y_data[0], (loop_ub + 1) * sizeof(real32_T));
  }

  for (loop_ub = 0; loop_ub < y_size[1]; loop_ub++) {
    SWC_VC_B.z1_data[loop_ub] = a_data[loop_ub] * a_data[loop_ub];
  }

  y_size[0] = 1;
  loop_ub = y_size[1] - 1;
  if (0 <= loop_ub) {
    memcpy(&y_data[0], &SWC_VC_B.z1_data[0], (loop_ub + 1) * sizeof(real32_T));
  }
}

/* Function for MATLAB Function: '<S83>/MATLAB Function' */
static void SWC_VC_sqrt_k(real32_T x_data[], const int32_T x_size[2])
{
  int32_T k;
  for (k = 0; k < x_size[1]; k++) {
    x_data[k] = sqrtf(x_data[k]);
  }
}

/* Function for MATLAB Function: '<S83>/MATLAB Function' */
static void SWC_VC_diff_a(const real32_T x_data[], const int32_T x_size[2],
  real32_T y_data[], int32_T y_size[2])
{
  int32_T ixLead;
  int32_T iyLead;
  real32_T tmp2;
  int32_T m;
  real32_T work_data_idx_0;
  if (x_size[1] == 0) {
    y_size[0] = 1;
    y_size[1] = 0;
  } else {
    ixLead = x_size[1] - 1;
    if (ixLead >= 1) {
      ixLead = 1;
    }

    if (ixLead < 1) {
      y_size[0] = 1;
      y_size[1] = 0;
    } else {
      y_size[0] = 1;
      y_size[1] = (uint8_T)(x_size[1] - 1);
      if ((uint8_T)(x_size[1] - 1) != 0) {
        ixLead = 1;
        iyLead = 0;
        work_data_idx_0 = x_data[0];
        for (m = 2; m <= x_size[1]; m++) {
          tmp2 = work_data_idx_0;
          work_data_idx_0 = x_data[ixLead];
          y_data[iyLead] = x_data[ixLead] - tmp2;
          ixLead++;
          iyLead++;
        }
      }
    }
  }
}

/* Function for MATLAB Function: '<S83>/MATLAB Function' */
static real32_T SWC_VC_sum(const real32_T x_data[], const int32_T x_size[2])
{
  real32_T y;
  int32_T k;
  if (x_size[1] == 0) {
    y = 0.0F;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_size[1]; k++) {
      y += x_data[k - 1];
    }
  }

  return y;
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_exit_internal_APX_Park_State_AllStrokes_ST(void)
{
  SWC_VC_DW.tp_APX_Park_State_Backw_DeviationExceeded = 0U;
  SWC_VC_DW.tp_APX_Park_State_Backw_DispForw = 0U;
  SWC_VC_DW.tp_APX_Park_State_Backw_DispForw1 = 0U;
  SWC_VC_DW.tp_APX_Park_State_Backw_PathAccepted = 0U;
  SWC_VC_DW.tp_APX_Park_State_Backw_RegenPathStarted = 0U;
  SWC_VC_DW.tp_APX_Park_State_Backward = 0U;
  SWC_VC_DW.tp_APX_Park_State_D_gear = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw1 = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forw_PathAccepted = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forw_RegenPathStarted = 0U;
  SWC_VC_DW.tp_APX_Park_State_Forward = 0U;
  SWC_VC_DW.tp_APX_Park_State_R_gear_o = 0U;
  SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_NO_ACTIVE_CHILD;
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_Backw_DeviationExceeded(void)
{
  if (!SWC_VC_B.DataTypeConversion_m) {
    SWC_VC_DW.tp_APX_Park_State_Backw_DeviationExceeded = 0U;
    SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
      SWC_VC_IN_APX_Park_State_Backw_RegenPathStarted;
    SWC_VC_DW.tp_APX_Park_State_Backw_RegenPathStarted = 1U;
    PM_RegenPath = false;
    SWC_VC_B.APC_Debug_Park_Stat = 6.0F;
  }
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_Backw_DispForw(void)
{
  int32_T tmp;
  if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_FORWARD) {
    SWC_VC_DW.tp_APX_Park_State_Backw_DispForw = 0U;
    tmp = PM_CurrentSweep + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    PM_CurrentSweep = (uint8_T)tmp;
    tmp = SWC_VC_B.CurrentSweepVeh + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    SWC_VC_B.CurrentSweepVeh = (uint8_T)tmp;
    SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_APX_Park_State_Forward;
    SWC_VC_DW.tp_APX_Park_State_Forward = 1U;
    SWC_VC_B.APC_Debug_Park_Stat = 3.0F;
    SWC_VC_B.NewPathAccepted = 0.0F;
    SWC_VC_B.APX_Park_Stat =
      SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
  }
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_Backw_DispForw1(void)
{
  int32_T tmp;
  if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_FORWARD) {
    SWC_VC_DW.tp_APX_Park_State_Backw_DispForw1 = 0U;
    tmp = SWC_VC_B.CurrentSweepVeh + 1;
    if (tmp > 255) {
      tmp = 255;
    }

    SWC_VC_B.CurrentSweepVeh = (uint8_T)tmp;
    SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_APX_Park_State_Forward;
    SWC_VC_DW.tp_APX_Park_State_Forward = 1U;
    SWC_VC_B.APC_Debug_Park_Stat = 3.0F;
    SWC_VC_B.NewPathAccepted = 0.0F;
    SWC_VC_B.APX_Park_Stat =
      SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
  }
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_Backw_PathAccepted(void)
{
  SWC_VC_B.NewPathAccepted = 1.0F;
  if ((SWC_VC_B.Dir == -1) && SWC_VC_B.UnitDelay_g) {
    SWC_VC_DW.tp_APX_Park_State_Backw_PathAccepted = 0U;
    SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
      SWC_VC_IN_APX_Park_State_Backward;
    SWC_VC_DW.tp_APX_Park_State_Backward = 1U;
    SWC_VC_B.APC_Debug_Park_Stat = 1.0F;
    SWC_VC_B.NewPathAccepted = 0.0F;
    SWC_VC_B.APX_Park_Stat =
      SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
  } else {
    if ((SWC_VC_B.Dir == 1) && SWC_VC_B.UnitDelay_g) {
      SWC_VC_DW.tp_APX_Park_State_Backw_PathAccepted = 0U;
      SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
        SWC_VC_IN_APX_Park_State_Backw_DispForw1;
      SWC_VC_DW.tp_APX_Park_State_Backw_DispForw1 = 1U;
      SWC_VC_B.DesiredDir = 1;
      SWC_VC_B.APC_Debug_Park_Stat = 8.0F;
    }
  }
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_Backw_RegenPathStarted(void)
{
  if (SWC_VC_B.DataTypeConversion_m) {
    SWC_VC_DW.tp_APX_Park_State_Backw_RegenPathStarted = 0U;
    PM_CurrentSweep = 1U;
    SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
      SWC_VC_IN_APX_Park_State_Backw_PathAccepted;
    SWC_VC_DW.tp_APX_Park_State_Backw_PathAccepted = 1U;
    SWC_VC_B.NewPathAccepted = 1.0F;
    SWC_VC_B.APC_Debug_Park_Stat = 7.0F;
    SWC_VC_B.regen_count++;
  }
}

/* Function for Chart: '<S25>/SC_ParkingManeuverMgr1' */
static void SWC_VC_APX_Park_State_AllStrokes_ST(const boolean_T
  *rtu_MeAP_b_ParkOut)
{
  int32_T tmp;
  boolean_T tmp_0;
  boolean_T guard1 = false;

  /*  &&((!DeviationExceeded && !ParkSpace_Exc && !CollDistRegen) || CurrentSweepVeh>6 || Dir ==0) */
  tmp_0 = !SWC_VC_B.Delay1_d;

  /* Inport: '<Root>/MeAP_m_ParkSpotType' */
  if ((VC_RemainingDist <= SWC_VC_C_APX_REMAIN_DIST_LIM) && (SWC_VC_B.NextDir ==
       0) && (SWC_VC_B.speed_kph_MABx <= SWC_VC_C_V_STILL_APC) &&
      ((SWC_VC_B.APC_Debug_Park_Stat == 1.0F) || (SWC_VC_B.APC_Debug_Park_Stat ==
        3.0F) || (SWC_VC_B.APC_Debug_Park_Stat == 66.0F) ||
       ((SWC_VC_B.NewPathAccepted != 0.0F) && (SWC_VC_B.Dir == 0))) &&
      ((!SWC_VC_B.RelationalOperator5) || (SWC_VC_B.Dir == 0)) && tmp_0 &&
      ((Ap_App_ID == 0) && ((SWC_VC_DW.counter_fishbone > 500) ||
        (SWC_VC_B.CurrentSweepVeh != 2) || ((PSType != 5) && (PSType != 6))))) {
    SWC_VC_exit_internal_APX_Park_State_AllStrokes_ST();
    SWC_VC_DW.tp_APX_Park_State_AllStrokes_ST = 0U;
    SWC_VC_DW.is_APX_Park_State_Active_ST =
      SWC_VC_IN_APX_Park_State_PARK_FIN_MSG;
    SWC_VC_B.APC_Debug_Park_Stat = 22.0F;
  } else {
    guard1 = false;
    switch (SWC_VC_DW.is_APX_Park_State_AllStrokes_ST) {
     case SWC_VC_IN_APX_Park_State_Backw_DeviationExceeded:
      SWC_VC_APX_Park_State_Backw_DeviationExceeded();
      break;

     case SWC_VC_IN_APX_Park_State_Backw_DispForw:
      SWC_VC_APX_Park_State_Backw_DispForw();
      break;

     case SWC_VC_IN_APX_Park_State_Backw_DispForw1:
      SWC_VC_APX_Park_State_Backw_DispForw1();
      break;

     case SWC_VC_IN_APX_Park_State_Backw_PathAccepted:
      SWC_VC_APX_Park_State_Backw_PathAccepted();
      break;

     case SWC_VC_IN_APX_Park_State_Backw_RegenPathStarted:
      SWC_VC_APX_Park_State_Backw_RegenPathStarted();
      break;

     case SWC_VC_IN_APX_Park_State_Backward:
      SWC_VC_B.NewPathAccepted = 0.0F;
      if ((VC_RemainingDist <= SWC_VC_C_APX_REMAIN_DIST_LIM) &&
          (SWC_VC_B.speed_kph_MABx <= SWC_VC_C_V_STILL_APC)) {
        SWC_VC_DW.tp_APX_Park_State_Backward = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_WAIT;
        SWC_VC_DW.temporalCounter_i1 = 0U;
        SWC_VC_B.APC_Debug_Park_Stat = 66.0F;
      } else {
        if (SWC_VC_B.Delay1_d && ((Ap_App_ID == 0) && (SWC_VC_B.CurrentSweepVeh ==
              1) && ((PSType == 1) || (PSType == 2)) &&
             (SWC_VC_DW.regen_on_fly_counter < SWC_VC_C_Regen_on_fly_lim))) {
          SWC_VC_DW.tp_APX_Park_State_Backward = 0U;
          tmp = SWC_VC_DW.regen_on_fly_counter + 1;
          if (tmp > 255) {
            tmp = 255;
          }

          SWC_VC_DW.regen_on_fly_counter = (uint8_T)tmp;
          SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
            SWC_VC_IN_APX_Park_State_Backw_DeviationExceeded;
          SWC_VC_DW.tp_APX_Park_State_Backw_DeviationExceeded = 1U;
          PM_RegenPath = true;
          SWC_VC_B.APC_Debug_Park_Stat = 5.0F;
        }
      }
      break;

     case SWC_VC_IN_APX_Park_State_D_gear:
      SWC_VC_B.NewPathAccepted = 0.0F;
      if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_FORWARD) {
        SWC_VC_DW.tp_APX_Park_State_D_gear = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Forward;
        SWC_VC_DW.tp_APX_Park_State_Forward = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 3.0F;
        SWC_VC_B.NewPathAccepted = 0.0F;
        SWC_VC_B.APX_Park_Stat =
          SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded:
      if (!SWC_VC_B.DataTypeConversion_m) {
        SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Forw_RegenPathStarted;
        SWC_VC_DW.tp_APX_Park_State_Forw_RegenPathStarted = 1U;
        PM_RegenPath = false;
        SWC_VC_B.APC_Debug_Park_Stat = 10.0F;
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forw_DispBackw:
      if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_REAR) {
        SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw = 0U;
        tmp = PM_CurrentSweep + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        PM_CurrentSweep = (uint8_T)tmp;
        tmp = SWC_VC_B.CurrentSweepVeh + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_VC_B.CurrentSweepVeh = (uint8_T)tmp;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Backward;
        SWC_VC_DW.tp_APX_Park_State_Backward = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 1.0F;
        SWC_VC_B.NewPathAccepted = 0.0F;
        SWC_VC_B.APX_Park_Stat =
          SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forw_DispBackw1:
      if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_REAR) {
        SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw1 = 0U;
        tmp = SWC_VC_B.CurrentSweepVeh + 1;
        if (tmp > 255) {
          tmp = 255;
        }

        SWC_VC_B.CurrentSweepVeh = (uint8_T)tmp;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Backward;
        SWC_VC_DW.tp_APX_Park_State_Backward = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 1.0F;
        SWC_VC_B.NewPathAccepted = 0.0F;
        SWC_VC_B.APX_Park_Stat =
          SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forw_PathAccepted:
      SWC_VC_B.NewPathAccepted = 1.0F;
      if ((SWC_VC_B.Dir == 1) && SWC_VC_B.UnitDelay_g) {
        SWC_VC_DW.tp_APX_Park_State_Forw_PathAccepted = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Forward;
        SWC_VC_DW.tp_APX_Park_State_Forward = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 3.0F;
        SWC_VC_B.NewPathAccepted = 0.0F;
        SWC_VC_B.APX_Park_Stat =
          SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
      } else {
        if ((SWC_VC_B.Dir == -1) && SWC_VC_B.UnitDelay_g) {
          SWC_VC_DW.tp_APX_Park_State_Forw_PathAccepted = 0U;
          SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
            SWC_VC_IN_APX_Park_State_Forw_DispBackw1;
          SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw1 = 1U;
          SWC_VC_B.DesiredDir = -1;
          SWC_VC_B.APC_Debug_Park_Stat = 12.0F;
        }
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forw_RegenPathStarted:
      if (SWC_VC_B.DataTypeConversion_m) {
        SWC_VC_DW.tp_APX_Park_State_Forw_RegenPathStarted = 0U;
        PM_CurrentSweep = 1U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Forw_PathAccepted;
        SWC_VC_DW.tp_APX_Park_State_Forw_PathAccepted = 1U;
        SWC_VC_B.NewPathAccepted = 1.0F;
        SWC_VC_B.APC_Debug_Park_Stat = 11.0F;
        SWC_VC_B.regen_count++;
      }
      break;

     case SWC_VC_IN_APX_Park_State_Forward:
      SWC_VC_B.NewPathAccepted = 0.0F;
      if ((VC_RemainingDist <= SWC_VC_C_APX_REMAIN_DIST_LIM) &&
          (SWC_VC_B.speed_kph_MABx <= SWC_VC_C_V_STILL_APC)) {
        SWC_VC_DW.tp_APX_Park_State_Forward = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_WAIT1;
        SWC_VC_DW.temporalCounter_i1 = 0U;
        SWC_VC_B.APC_Debug_Park_Stat = 66.0F;
        SWC_VC_DW.counter_fishbone = 0U;
      } else {
        if (SWC_VC_B.Delay1_d) {
          /* Chart: '<S25>/SC_ParkingManeuverMgr1' */
          if ((Ap_App_ID == 0) && ((PSType == 1) || (PSType == 2)) &&
              (*rtu_MeAP_b_ParkOut)) {
            SWC_VC_DW.tp_APX_Park_State_Forward = 0U;
            SWC_VC_B.APC_Debug_Park_Stat = 94.0F;
            SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
              SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded;
            SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 1U;
            PM_RegenPath = true;

            /* APC_Debug_Park_Stat = 9; */
          } else {
            if ((Ap_App_ID == 1) || (Ap_App_ID == 2)) {
              SWC_VC_DW.tp_APX_Park_State_Forward = 0U;
              SWC_VC_B.APC_Debug_Park_Stat = 94.0F;
              SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
                SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded;
              SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 1U;
              PM_RegenPath = true;

              /* APC_Debug_Park_Stat = 9; */
            }
          }
        }
      }
      break;

     case SWC_VC_IN_APX_Park_State_R_gear_o:
      if (SWC_VC_B.MeAP_I_GearRpt == SWC_VC_C_TSL_POSN_TCM_REAR) {
        SWC_VC_DW.tp_APX_Park_State_R_gear_o = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Backward;
        SWC_VC_DW.tp_APX_Park_State_Backward = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 1.0F;
        SWC_VC_B.NewPathAccepted = 0.0F;
        SWC_VC_B.APX_Park_Stat =
          SWC_VC_DW.C_APX_PARK_STAT_FIELD[SWC_VC_B.CurrentSweepVeh - 1];
      }
      break;

     case SWC_VC_IN_DIRECTION_CHECK:
      SWC_VC_B.NewPathAccepted = 1.0F;
      switch (SWC_VC_B.Dir) {
       case -1:
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_R_gear_o;
        SWC_VC_DW.tp_APX_Park_State_R_gear_o = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 15.0F;
        SWC_VC_B.DesiredDir = -1;
        break;

       case 1:
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_D_gear;
        SWC_VC_DW.tp_APX_Park_State_D_gear = 1U;
        SWC_VC_B.APC_Debug_Park_Stat = 16.0F;
        SWC_VC_B.DesiredDir = 1;
        SWC_VC_B.NewPathAccepted = 0.0F;
        break;
      }
      break;

     case SWC_VC_IN_WAIT:
      if (SWC_VC_DW.temporalCounter_i1 >= 34U) {
        /* Chart: '<S25>/SC_ParkingManeuverMgr1' */
        if (((SWC_VC_B.NextDir == 1) && ((tmp_0 && (!SWC_VC_B.CollDistRegen_out))
              || (SWC_VC_B.CurrentSweepVeh > 4))) || (*rtu_MeAP_b_ParkOut)) {
          /* after(3,sec) */
          SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
            SWC_VC_IN_APX_Park_State_Backw_DispForw;
          SWC_VC_DW.tp_APX_Park_State_Backw_DispForw = 1U;
          SWC_VC_B.DesiredDir = 1;
          SWC_VC_B.APC_Debug_Park_Stat = 2.0F;
        } else {
          if (SWC_VC_B.CurrentSweepVeh <= 4) {
            if (SWC_VC_B.Delay1_d) {
              SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
                SWC_VC_IN_APX_Park_State_Backw_DeviationExceeded;
              SWC_VC_DW.tp_APX_Park_State_Backw_DeviationExceeded = 1U;
              PM_RegenPath = true;
              SWC_VC_B.APC_Debug_Park_Stat = 5.0F;
            } else {
              if (SWC_VC_B.CollDistRegen_out) {
                SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
                  SWC_VC_IN_APX_Park_State_Backw_DeviationExceeded;
                SWC_VC_DW.tp_APX_Park_State_Backw_DeviationExceeded = 1U;
                PM_RegenPath = true;
                SWC_VC_B.APC_Debug_Park_Stat = 5.0F;
              }
            }
          }
        }
      }
      break;

     default:
      /* case IN_WAIT1: */
      if ((SWC_VC_DW.temporalCounter_i1 >= 34U) && ((Ap_App_ID == 0) &&
           ((SWC_VC_B.CurrentSweepVeh != 2) || ((PSType != 5) && (PSType != 6)))))
      {
        if (((SWC_VC_B.NextDir == -1) && (((!SWC_VC_B.Delay1_d) &&
               (!SWC_VC_B.CollDistRegen_out)) || (SWC_VC_B.CurrentSweepVeh > 4)))
            || (*rtu_MeAP_b_ParkOut)) {
          SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
            SWC_VC_IN_APX_Park_State_Forw_DispBackw;
          SWC_VC_DW.tp_APX_Park_State_Forw_DispBackw = 1U;
          SWC_VC_B.DesiredDir = -1;
          SWC_VC_B.APC_Debug_Park_Stat = 4.0F;
        } else if (SWC_VC_B.CurrentSweepVeh <= 4) {
          if (SWC_VC_B.CollDistRegen_out) {
            SWC_VC_B.APC_Debug_Park_Stat = 93.0F;
            SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
              SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded;
            SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 1U;
            PM_RegenPath = true;

            /* APC_Debug_Park_Stat = 9; */
          } else if (SWC_VC_B.Delay1_d) {
            SWC_VC_B.APC_Debug_Park_Stat = 92.0F;
            SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
              SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded;
            SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 1U;
            PM_RegenPath = true;

            /* APC_Debug_Park_Stat = 9; */
          } else {
            guard1 = true;
          }
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;
    }

    if (guard1) {
      if ((Ap_App_ID == 0) && SWC_VC_B.Delay1_d && (SWC_VC_DW.counter_fishbone >
           490)) {
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST =
          SWC_VC_IN_APX_Park_State_Forw_DeviationExceeded;
        SWC_VC_DW.tp_APX_Park_State_Forw_DeviationExceeded = 1U;
        PM_RegenPath = true;

        /* APC_Debug_Park_Stat = 9; */
      } else {
        tmp = SWC_VC_DW.counter_fishbone + 1;
        if (tmp > 65535) {
          tmp = 65535;
        }

        SWC_VC_DW.counter_fishbone = (uint16_T)tmp;
      }
    }
  }

  /* End of Inport: '<Root>/MeAP_m_ParkSpotType' */
}

/* System initialize for referenced model: 'SWC_VC' */
void SWC_VC_Init(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[0] = SWC_VC_ConstB.xy_init[0];
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[1] = SWC_VC_ConstB.xy_init[1];

  /* InitializeConditions for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE = SWC_VC_ConstB.heading_init;

  /* InitializeConditions for Delay: '<S12>/Delay1' */
  SWC_VC_DW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S12>/Delay2' */
  SWC_VC_DW.icLoad_l = 1U;

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = SWC_VC_B.RemainDist_Stat_sendtime;
  if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = (-1.0F);
    }
  }

  /* End of InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */

  /* InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */
  SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = SWC_VC_B.Lower_rate_limit_duration;
  if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = (-1.0F);
    }
  }

  /* End of InitializeConditions for DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */

  /* InitializeConditions for Memory: '<S111>/Memory' */
  SWC_VC_DW.Memory_PreviousInput = ((uint8_T)1U);

  /* InitializeConditions for Memory: '<S111>/Memory2' */
  SWC_VC_DW.Memory2_PreviousInput = true;

  /* InitializeConditions for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_IC_LOADING = 1U;
  SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_f = 2;

  /* SystemInitialize for Enabled SubSystem: '<S21>/Control' */
  /* InitializeConditions for Delay: '<S84>/Delay One Step' */
  SWC_VC_DW.DelayOneStep_DSTATE = 0.0F;

  /* End of SystemInitialize for SubSystem: '<S21>/Control' */

  /* SystemInitialize for Chart: '<S25>/SC_ParkingManeuverMgr1' */
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[0] = 3U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[1] = 4U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[2] = 5U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[3] = 6U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[4] = 7U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[5] = 11U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[6] = 12U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[7] = 12U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[8] = 12U;
  SWC_VC_DW.C_APX_PARK_STAT_FIELD[9] = 12U;
}

/* Disable for referenced model: 'SWC_VC' */
void SWC_VC_Disable(void)
{
  /* Disable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[0] =
    SWC_VC_B.DiscreteTimeIntegrator1[0];
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[1] =
    SWC_VC_B.DiscreteTimeIntegrator1[1];

  /* Disable for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE = SWC_VC_B.DiscreteTimeIntegrator;

  /* Disable for Enabled SubSystem: '<S21>/Control' */
  SWC_VC_DW.Control_MODE = false;

  /* End of Disable for SubSystem: '<S21>/Control' */

  /* Disable for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = SWC_VC_B.DiscreteTimeIntegrator_l;

  /* Disable for DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */
  SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = SWC_VC_B.DiscreteTimeIntegrator2;

  /* Disable for Enabled SubSystem: '<S1>/Subsystem1' */
  if (SWC_VC_DW.Subsystem1_MODE) {
    /* Disable for Outport: '<S17>/IeAP_a_DecelMax' */
    SWC_VC_B.OutportBufferForIeAP_a_DecelMax = 0.0;

    /* Disable for Outport: '<S17>/IeAP_a_DecelMin' */
    SWC_VC_B.OutportBufferForIeAP_a_DecelMin = 0.0;

    /* Disable for Outport: '<S17>/IeAP_a_JerkDecelMax' */
    SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMax = 0.0;

    /* Disable for Outport: '<S17>/IeAP_a_JerkDecelMin' */
    SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMin = 0.0;

    /* Disable for Outport: '<S17>/IeAP_a_AcclMin' */
    SWC_VC_B.OutportBufferForIeAP_a_AcclMin = 0.0;

    /* Disable for Outport: '<S17>/IeAP_a_AcclMax' */
    SWC_VC_B.OutportBufferForIeAP_a_AcclMax = 0.0;

    /* Disable for Outport: '<S17>/IeAP_da_JerkAcclMax' */
    SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMax = 0.0;

    /* Disable for Outport: '<S17>/IeAP_da_JerkAcclMin' */
    SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMin = 0.0;

    /* Disable for Outport: '<S17>/IeAP_b_StandstillReq' */
    SWC_VC_B.OutportBufferForIeAP_b_StandstillReq = 0.0;

    /* Disable for Outport: '<S17>/IeAP_kph_MaxSpeed' */
    SWC_VC_B.DataTypeConversion_l = 0.0F;
    SWC_VC_DW.Subsystem1_MODE = false;
  }

  /* End of Disable for SubSystem: '<S1>/Subsystem1' */
}

/* Start for referenced model: 'SWC_VC' */
void SWC_VC_Start(void)
{
  /* Start for Constant: '<S113>/RemainDist_Stat_sendtime ' */
  SWC_VC_B.RemainDist_Stat_sendtime = 5.0F;

  /* Start for Constant: '<S113>/Lower_rate_limit_duration' */
  SWC_VC_B.Lower_rate_limit_duration = 3.0F;

  /* ConstCode for Constant: '<S1>/Constant' */
  Ap_App_ID = ((uint8_T)0U);
}

/* Output and update for referenced model: 'SWC_VC' */
void SWC_VC(const int16_T *rtu_MeAP_I_WhlPosRR, const int16_T
            *rtu_MeAP_I_WhlPosRL, const uint8_T *rtu_MeAP_I_GearRpt, const
            boolean_T *rtu_MeAP_b_VCActive, const boolean_T *rtu_MeAP_b_ParkOut,
            const boolean_T *rtu_MeAP_b_ResetVCKM, const TbNVM_ProxyCalibParam
            *rtu_MbNVM_ProxyParam, const real32_T *rtu_MeAP_cm_CDminDist, const
            boolean_T *rtu_MeAP_b_VCOpPaused, const boolean_T
            *rtu_IeVBII_b_ActvParkMode, const uint16_T
            *rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth, const int16_T
            *rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj, const int16_T
            *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj, const int16_T
            *rtu_IeVBII_deg_StrWhlSpd, real32_T *rty_MeAP_deg_StrCmd, real32_T
            *rty_MeAP_a_BrkCmd, real32_T *rty_MeAP_a_ThrtlCmd, int32_T
            *rty_IeAP_e_TurnIndicReq, real32_T *rty_IeAP_nm_StrwTrqReq, real32_T
            *rty_IeAP_a_DecelMax, real32_T *rty_IeAP_a_DecelMin, real32_T
            *rty_IeAP_a_JerkDecelMax, real32_T *rty_IeAP_a_JerkDecelMin,
            real32_T *rty_IeAP_a_AcclMin, real32_T *rty_IeAP_a_AcclMax, real32_T
            *rty_IeAP_da_JerkAcclMax, real32_T *rty_IeAP_da_JerkAcclMin,
            boolean_T *rty_IeAP_b_StandstillReq, real32_T *rty_IeAP_cm_TrgtDist,
            boolean_T *rty_MeAP_b_ManeuverAbort, boolean_T
            *rty_MeAP_b_ManeuverSuccess, int8_T *rty_MeAP_e_PP_state, real32_T
            *rty_MeAP_e_Park_state, real32_T rty_MaAP_m_PlannerWayPointsX[250],
            real32_T rty_MaAP_m_PlannerWayPointsY[250], boolean_T
            *rty_MeAP_b_PosMet, boolean_T *rty_MeAP_b_SteerActionReq, real32_T
            *rty_IeAP_kph_TrgtVehSpd, TeAutoPark_e_GearCmd *rty_MeAP_e_GearCmd,
            real32_T *rty_IbVC_DebugOut_X_MABx, real32_T
            *rty_IbVC_DebugOut_Y_MABx, real32_T *rty_IbVC_DebugOut_heading_MABx,
            real32_T *rty_IbVC_DebugOut_Str_Trq_CMD, real32_T
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
            *rty_IbVC_DebugOut_PM_RegenPath)
{
  boolean_T left;
  uint8_T WPst;
  uint8_T WPend;
  uint8_T sweep_id;
  int8_T n;
  int16_T tmp;
  static const real_T b[14] = { 2.0, 2.0, 2.0, 1.0, 1.0, 0.65, 0.65, 0.65, 0.65,
    1.0, 1.0, 2.0, 2.0, 2.0 };

  static const real_T b_0[14] = { 2.0, 2.0, 2.0, 1.0, 1.0, 0.7, 0.7, 0.7, 0.7,
    1.0, 1.0, 2.0, 2.0, 2.0 };

  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T exitg1;

  /* Delay: '<S21>/Delay' */
  SWC_VC_B.Delay = SWC_VC_DW.Delay_DSTATE_a;

  /* RateTransition: '<S1>/Rate Transition7' */
  SWC_VC_B.RateTransition7 = *rtu_MeAP_b_VCActive;

  /* Delay: '<S1>/Delay' */
  SWC_VC_B.Delay_b = SWC_VC_DW.Delay_DSTATE_n;

  /* MATLAB Function: '<S1>/Decativate VC if planner failed' */
  ACT_ACTIVE = SWC_VC_B.RateTransition7;
  ACT_ACTIVE = ((SWC_VC_B.Delay_b <= 100) && ACT_ACTIVE);

  /* Switch: '<S13>/SwitchActive3' incorporates:
   *  Constant: '<S13>/Constant3'
   */
  if (SWC_VC_ConstB.Compare) {
    /* Switch: '<S13>/SwitchActive' incorporates:
     *  Constant: '<S13>/Constant'
     *  Constant: '<S13>/Constant1'
     */
    if (ACT_ACTIVE) {
      SWC_VC_B.SwitchActive = ((uint8_T)2U);
    } else {
      SWC_VC_B.SwitchActive = ((uint8_T)1U);
    }

    /* End of Switch: '<S13>/SwitchActive' */
    SWC_VC_B.UnitDelay = SWC_VC_B.SwitchActive;
  } else {
    SWC_VC_B.lookahead_dist_wp = floorf(0.0F);
    if (rtIsNaNF(SWC_VC_B.lookahead_dist_wp) || rtIsInfF
        (SWC_VC_B.lookahead_dist_wp)) {
      SWC_VC_B.lookahead_dist_wp = 0.0F;
    } else {
      SWC_VC_B.lookahead_dist_wp = fmodf(SWC_VC_B.lookahead_dist_wp, 256.0F);
    }

    SWC_VC_B.UnitDelay = (uint8_T)(SWC_VC_B.lookahead_dist_wp < 0.0F ? (int32_T)
      (uint8_T)-(int8_T)(uint8_T)-SWC_VC_B.lookahead_dist_wp : (int32_T)(uint8_T)
      SWC_VC_B.lookahead_dist_wp);
  }

  /* End of Switch: '<S13>/SwitchActive3' */

  /* RateTransition: '<S13>/Rate Transition1' */
  SWC_VC_B.RateTransition1 = SWC_VC_B.UnitDelay;

  /* RateTransition: '<S1>/Rate Transition14' */
  SWC_VC_B.RateTransition14 = *rtu_MeAP_b_ResetVCKM;

  /* DataTypeConversion: '<S12>/Data Type Conversion1' */
  SWC_VC_B.DataTypeConversion1_h = SWC_VC_B.RateTransition14;

  /* Delay: '<S12>/Delay4' */
  SWC_VC_B.UpperRelop = SWC_VC_DW.Delay4_DSTATE;

  /* Logic: '<S12>/Logical Operator4' */
  SWC_VC_B.UpperRelop = !SWC_VC_B.UpperRelop;

  /* Logic: '<S12>/Logical Operator3' */
  SWC_VC_B.LogicalOperator3 = (SWC_VC_B.DataTypeConversion1_h &&
    SWC_VC_B.UpperRelop);

  /* Delay: '<S12>/Delay5' */
  SWC_VC_B.DataTypeConversion = SWC_VC_B.reset_KM;

  /* DataTypeConversion: '<S12>/Data Type Conversion2' */
  SWC_VC_B.DataTypeConversion2 = (real32_T)SWC_VC_B.DataTypeConversion;

  /* Delay: '<S12>/Delay8' */
  SWC_VC_B.Delay8[0] = SWC_VC_DW.Delay8_DSTATE[0];
  SWC_VC_B.Delay8[1] = SWC_VC_DW.Delay8_DSTATE[1];

  /* RelationalOperator: '<S43>/Compare' incorporates:
   *  Constant: '<S43>/Constant'
   */
  SWC_VC_B.UpperRelop = (SWC_VC_B.Delay8[0] == 0.0F);

  /* Delay: '<S12>/Delay7' */
  SWC_VC_B.Compare_b = SWC_VC_B.Compare_a;

  /* Delay: '<S12>/Delay6' */
  SWC_VC_B.LogicalOperator2_a = SWC_VC_B.Compare_l;

  /* Logic: '<S12>/Logical Operator5' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UpperRelop && SWC_VC_B.Compare_b &&
    SWC_VC_B.LogicalOperator2_a);

  /* RateTransition: '<S12>/Rate Transition3' */
  SWC_VC_B.RateTransition3 = SWC_VC_B.UpperRelop;

  /* MATLAB Function: '<S12>/KM_Reset Decision Function' */
  SWC_VC_B.reset_KM = 0.0;
  if (SWC_VC_B.LogicalOperator3 || (SWC_VC_B.DataTypeConversion2 != 0.0F)) {
    SWC_VC_B.reset_KM = 1.0;
  }

  if (SWC_VC_B.RateTransition3) {
    SWC_VC_B.reset_KM = 0.0;
  }

  /* End of MATLAB Function: '<S12>/KM_Reset Decision Function' */

  /* Logic: '<S12>/Logical Operator1' incorporates:
   *  Constant: '<S12>/KM_reset'
   */
  SWC_VC_B.LogicalOperator1 = ((SWC_VC_B.reset_KM != 0.0) || false);

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  if (SWC_VC_B.LogicalOperator1 ||
      (SWC_VC_DW.DiscreteTimeIntegrator1_PrevResetState != 0)) {
    SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[0] = SWC_VC_ConstB.xy_init[0];
    SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[1] = SWC_VC_ConstB.xy_init[1];
  }

  SWC_VC_B.DiscreteTimeIntegrator1[0] =
    SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[0];
  SWC_VC_B.DiscreteTimeIntegrator1[1] =
    SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[1];

  /* End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */

  /* DataTypeConversion: '<S1>/Data Type Conversion2' */
  X_MABx = SWC_VC_B.DiscreteTimeIntegrator1[0];

  /* DataTypeConversion: '<S56>/Data Type Conversion1' */
  SWC_VC_B.DataTypeConversion1 = X_MABx;

  /* DataTypeConversion: '<S1>/Data Type Conversion3' */
  Y_MABx = SWC_VC_B.DiscreteTimeIntegrator1[1];

  /* DataTypeConversion: '<S56>/Data Type Conversion2' */
  SWC_VC_B.DataTypeConversion2_l = Y_MABx;

  /* DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  if (SWC_VC_B.LogicalOperator1 ||
      (SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState != 0)) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE = SWC_VC_ConstB.heading_init;
  }

  SWC_VC_B.DiscreteTimeIntegrator = SWC_VC_DW.DiscreteTimeIntegrator_DSTATE;

  /* End of DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */

  /* MATLAB Function: '<S12>/MATLAB Function4' */
  SWC_VC_B.heading_MABx_h = SWC_VC_B.DiscreteTimeIntegrator;
  while (SWC_VC_B.heading_MABx_h < -180.0F) {
    SWC_VC_B.heading_MABx_h += 360.0F;
  }

  while (SWC_VC_B.heading_MABx_h > 180.0F) {
    SWC_VC_B.heading_MABx_h -= 360.0F;
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function4' */

  /* DataTypeConversion: '<S1>/Data Type Conversion4' */
  heading_MABx = SWC_VC_B.heading_MABx_h;

  /* DataTypeConversion: '<S56>/Data Type Conversion3' */
  SWC_VC_B.DataTypeConversion3 = heading_MABx;

  /* DataTypeConversion: '<S13>/Data Type Conversion3' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  SWC_VC_B.Abs1_p = DS_ANGLE;

  /* Abs: '<S56>/Abs' */
  SWC_VC_B.Abs = fabsf(SWC_VC_B.Abs1_p);

  /* Lookup_n-D: '<S58>/steering_XXc.mat2' */
  SWC_VC_B.steering_XXcmat2 = look1_iflf_binlxpw(SWC_VC_B.Abs,
    rtCP_steering_XXcmat2_bp01Data_p, rtCP_steering_XXcmat2_tableData_c, 8U);

  /* MultiPortSwitch: '<S58>/Multiport Switch' */
  switch (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp) {
   case TeAP_e_SteerRatRackPinionTyp_Type_1:
    /* Lookup_n-D: '<S58>/steering_XXc.mat' */
    SWC_VC_B.steering_XXcmat_j = look1_iflf_binlxpw(SWC_VC_B.Abs,
      rtCP_steering_XXcmat_bp01Data_a, rtCP_steering_XXcmat_tableData_e, 8U);
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.steering_XXcmat_j;
    break;

   case TeAP_e_SteerRatRackPinionTyp_Type_2:
    /* Lookup_n-D: '<S58>/steering_XXc.mat1' */
    SWC_VC_B.steering_XXcmat1_b = look1_iflf_binlxpw(SWC_VC_B.Abs,
      rtCP_steering_XXcmat1_bp01Data_o, rtCP_steering_XXcmat1_tableData_l, 8U);
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.steering_XXcmat1_b;
    break;

   default:
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.steering_XXcmat2;
    break;
  }

  /* End of MultiPortSwitch: '<S58>/Multiport Switch' */

  /* Signum: '<S56>/Sign' */
  if (SWC_VC_B.Abs1_p < 0.0F) {
    SWC_VC_B.Abs1_p = -1.0F;
  } else if (SWC_VC_B.Abs1_p > 0.0F) {
    SWC_VC_B.Abs1_p = 1.0F;
  } else if (SWC_VC_B.Abs1_p == 0.0F) {
    SWC_VC_B.Abs1_p = 0.0F;
  } else {
    SWC_VC_B.Abs1_p = (rtNaNF);
  }

  /* End of Signum: '<S56>/Sign' */

  /* Product: '<S56>/Product3' */
  SWC_VC_B.whl_angl = SWC_VC_B.StrTqFB_Old * SWC_VC_B.Abs1_p;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  Inport: '<Root>/MeAP_b_PerpNoseIn'
   *  Inport: '<Root>/MeAP_m_ParkSpotType'
   *  Logic: '<S130>/Logical Operator2'
   */
  SWC_VC_B.xOffset = 0.0;
  SWC_VC_B.x_para_Offset = 0.0;
  SWC_VC_B.yOffset = 0.0;
  SWC_VC_B.LogicalOperator3_p = !*rtu_MeAP_b_ParkOut;
  if ((PSType == 1) && SWC_VC_B.LogicalOperator3_p) {
    SWC_VC_B.xOffset = 0.0;
    SWC_VC_B.x_para_Offset = -0.3;
    SWC_VC_B.yOffset = -0.8;
  }

  if ((PSType == 2) && SWC_VC_B.LogicalOperator3_p) {
    SWC_VC_B.xOffset = 0.0;
    SWC_VC_B.x_para_Offset = -0.3;
    SWC_VC_B.yOffset = 0.8;
  }

  if (((PSType == 1) || (PSType == 2)) && (*rtu_MeAP_b_ParkOut)) {
    SWC_VC_B.xOffset = 0.0;
  }

  if (MeAP_k_PerpNoseIn) {
    SWC_VC_B.xOffset = -0.9;
  }

  /* DataTypeConversion: '<S15>/Data Type Conversion2' */
  SWC_VC_B.StrTqFB_Old = (real32_T)SWC_VC_B.xOffset;

  /* DataTypeConversion: '<S15>/Data Type Conversion' */
  SWC_VC_B.Abs1_p = (real32_T)SWC_VC_B.x_para_Offset;

  /* Sum: '<S1>/Add' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetX'
   */
  Ma_AP_I_PSLimFSX = (SWC_VC_B.StrTqFB_Old + MaAP_m_ParkSpot1FrntStreetX) +
    SWC_VC_B.Abs1_p;

  /* DataTypeConversion: '<S15>/Data Type Conversion1' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = (real32_T)SWC_VC_B.yOffset;

  /* Sum: '<S1>/Add4' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot1FrntStreetY'
   */
  Ma_AP_I_PSLimFSY = SWC_VC_B.DiscreteTimeIntegrator_ll +
    MaAP_m_ParkSpot1FrntStreetY;

  /* Sum: '<S1>/Add1' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderX'
   */
  Ma_AP_I_PSLimFBX = (SWC_VC_B.Abs1_p + SWC_VC_B.StrTqFB_Old) +
    MaAP_m_ParkSpot2FrntBorderX;

  /* Sum: '<S1>/Add5' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot2FrntBorderY'
   */
  Ma_AP_I_PSLimFBY = SWC_VC_B.DiscreteTimeIntegrator_ll +
    MaAP_m_ParkSpot2FrntBorderY;

  /* Sum: '<S1>/Add2' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderX'
   */
  Ma_AP_I_PSLimRBX = SWC_VC_B.StrTqFB_Old + MaAP_m_ParkSpot3RearBorderX;

  /* Sum: '<S1>/Add6' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot3RearBorderY'
   */
  Ma_AP_I_PSLimRBY = SWC_VC_B.DiscreteTimeIntegrator_ll +
    MaAP_m_ParkSpot3RearBorderY;

  /* Sum: '<S1>/Add3' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetX'
   */
  Ma_AP_I_PSLimRSX = SWC_VC_B.StrTqFB_Old + MaAP_m_ParkSpot4RearStreetX;

  /* Sum: '<S1>/Add7' incorporates:
   *  Inport: '<Root>/MaAP_m_ParkSpot4RearStreetY'
   */
  Ma_AP_I_PSLimRSY = SWC_VC_B.DiscreteTimeIntegrator_ll +
    MaAP_m_ParkSpot4RearStreetY;

  /* DataTypeConversion: '<S13>/Data Type Conversion4' */
  SWC_VC_B.DataTypeConversion4[0] = Ma_AP_I_PSLimFSX;
  SWC_VC_B.DataTypeConversion4[1] = Ma_AP_I_PSLimFSY;
  SWC_VC_B.DataTypeConversion4[2] = Ma_AP_I_PSLimFBX;
  SWC_VC_B.DataTypeConversion4[3] = Ma_AP_I_PSLimFBY;
  SWC_VC_B.DataTypeConversion4[4] = Ma_AP_I_PSLimRBX;
  SWC_VC_B.DataTypeConversion4[5] = Ma_AP_I_PSLimRBY;
  SWC_VC_B.DataTypeConversion4[6] = Ma_AP_I_PSLimRSX;
  SWC_VC_B.DataTypeConversion4[7] = Ma_AP_I_PSLimRSY;

  /* UnitDelay: '<S13>/Unit Delay' */
  SWC_VC_B.UnitDelay_n = SWC_VC_DW.UnitDelay_DSTATE_d;

  /* UnitDelay: '<S13>/Unit Delay3' */
  SWC_VC_B.UnitDelay3 = SWC_VC_B.DataTypeConversion_a;

  /* Delay: '<S13>/Delay1' */
  SWC_VC_B.DataTypeConversion = SWC_VC_B.SwitchActive1;

  /* DataTypeConversion: '<S13>/Data Type Conversion1' */
  SWC_VC_B.minV = floor(SWC_VC_B.DataTypeConversion);
  if (rtIsNaN(SWC_VC_B.minV) || rtIsInf(SWC_VC_B.minV)) {
    SWC_VC_B.minV = 0.0;
  } else {
    SWC_VC_B.minV = fmod(SWC_VC_B.minV, 256.0);
  }

  SWC_VC_B.NextDir_a = (int8_T)(SWC_VC_B.minV < 0.0 ? (int32_T)(int8_T)-(int8_T)
    (uint8_T)-SWC_VC_B.minV : (int32_T)(int8_T)(uint8_T)SWC_VC_B.minV);

  /* End of DataTypeConversion: '<S13>/Data Type Conversion1' */

  /* RateTransition: '<S13>/Rate Transition2' */
  SWC_VC_B.RateTransition2_j = SWC_VC_B.NextDir_a;

  /* UnitDelay: '<S13>/Unit Delay1' */
  SWC_VC_B.UnitDelay1_m = SWC_VC_DW.UnitDelay1_DSTATE_b;

  /* UnitDelay: '<S13>/Unit Delay2' */
  SWC_VC_B.UnitDelay2 = SWC_VC_DW.UnitDelay2_DSTATE;

  /* RateTransition: '<S13>/Rate Transition3' */
  SWC_VC_B.RateTransition3_i = *rtu_MeAP_b_ParkOut;

  /* DataTypeConversion: '<S13>/Data Type Conversion22' incorporates:
   *  Inport: '<Root>/MeAP_b_parkout_perp_left'
   */
  SWC_VC_B.DiscreteTimeIntegrator_ll = parkout_perp_left;

  /* DataTypeConversion: '<S13>/Data Type Conversion6' */
  SWC_VC_B.DataTypeConversion6 = (SWC_VC_B.DiscreteTimeIntegrator_ll != 0.0F);

  /* MultiPortSwitch: '<S63>/Multiport Switch' incorporates:
   *  Constant: '<S63>/Constant3'
   *  Constant: '<S63>/Constant4'
   *  Constant: '<S63>/Constant5'
   */
  switch (rtu_MbNVM_ProxyParam->KeAP_e_WhlBas) {
   case TeAP_e_WhlBas_Type_1:
    MeAP_m_VehWheelbase = 3.5687F;
    break;

   case TeAP_e_WhlBas_Type_2:
    MeAP_m_VehWheelbase = 3.6703F;
    break;

   default:
    MeAP_m_VehWheelbase = 3.8989F;
    break;
  }

  /* End of MultiPortSwitch: '<S63>/Multiport Switch' */

  /* Product: '<S61>/Product2' incorporates:
   *  Constant: '<S61>/Constant2'
   */
  SWC_VC_B.DiscreteTimeIntegrator_ll = (real32_T)
    *rtu_IbAP_InputVrntTunParam_KeAP_cm_FrntLongDistAdj * 0.01F;

  /* Sum: '<S61>/Subtract' */
  MeAP_m_VehFrontOverhang = SWC_VC_B.DiscreteTimeIntegrator_ll -
    MeAP_m_VehWheelbase;

  /* Product: '<S61>/Product1' incorporates:
   *  Constant: '<S61>/Constant1'
   */
  MeAP_m_VehRearOverhang = (real32_T)
    *rtu_IbAP_InputVrntTunParam_KeAP_cm_RearLongDistAdj * 0.01F;

  /* Product: '<S61>/Product' incorporates:
   *  Constant: '<S61>/Constant3'
   */
  MeAP_m_VehWidth = (real32_T)*rtu_IbAP_InputVrntTunParam_KeAP_cm_VehicleWidth *
    0.01F;

  /* MultiPortSwitch: '<S64>/Multiport Switch' incorporates:
   *  Constant: '<S64>/Constant3'
   *  Constant: '<S64>/Constant4'
   *  Constant: '<S64>/Constant5'
   */
  switch (rtu_MbNVM_ProxyParam->KeAP_e_WhlBas) {
   case TeAP_e_WhlBas_Type_1:
    MeAP_m_PlanminRadius = minRadius_TypeOne;

    /* MultiPortSwitch: '<S62>/Multiport Switch' incorporates:
     *  Constant: '<S62>/Constant3'
     *  Constant: '<S64>/Constant3'
     */
    MeAP_pm_maxCurvature = KeAP_maxCurvatureTypeOne;
    break;

   case TeAP_e_WhlBas_Type_2:
    MeAP_m_PlanminRadius = minRadiusTypeTwo;

    /* MultiPortSwitch: '<S62>/Multiport Switch' incorporates:
     *  Constant: '<S62>/Constant4'
     *  Constant: '<S64>/Constant4'
     */
    MeAP_pm_maxCurvature = KeAP_maxCurvatureTypeTwo;
    break;

   default:
    MeAP_m_PlanminRadius = minRadiustypeThree;

    /* MultiPortSwitch: '<S62>/Multiport Switch' incorporates:
     *  Constant: '<S62>/Constant5'
     *  Constant: '<S64>/Constant5'
     */
    MeAP_pm_maxCurvature = KeAP_maxCurvatureTypeThree;
    break;
  }

  /* End of MultiPortSwitch: '<S64>/Multiport Switch' */

  /* Sum: '<S61>/Add' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = (MeAP_m_VehFrontOverhang +
    MeAP_m_VehWheelbase) + MeAP_m_VehRearOverhang;

  /* Sum: '<S61>/Add1' incorporates:
   *  Constant: '<S61>/Constant4'
   */
  SWC_VC_B.KeAP_PS_size_para[0] = SWC_VC_B.DiscreteTimeIntegrator_ll + 0.8F;
  SWC_VC_B.KeAP_PS_size_para[1] = SWC_VC_B.DiscreteTimeIntegrator_ll + 1.0F;
  SWC_VC_B.KeAP_PS_size_para[2] = SWC_VC_B.DiscreteTimeIntegrator_ll + 1.4F;
  SWC_VC_B.KeAP_PS_size_para[3] = SWC_VC_B.DiscreteTimeIntegrator_ll + 1.8F;

  /* Product: '<S61>/Product3' incorporates:
   *  Constant: '<S61>/Constant5'
   */
  SWC_VC_B.PEP_PS_min_length = SWC_VC_B.DiscreteTimeIntegrator_ll * 1.2F;

  /* Sum: '<S61>/Add2' incorporates:
   *  Constant: '<S61>/Constant6'
   */
  SWC_VC_B.PEP_PS_min_width = MeAP_m_VehWidth + 1.0F;

  /* Product: '<S61>/Divide' incorporates:
   *  Constant: '<S61>/Constant7'
   */
  SWC_VC_B.DiscreteTimeIntegrator_ll = MeAP_m_VehWidth / 2.0F;

  /* Sum: '<S61>/Add3' incorporates:
   *  Constant: '<S61>/Constant8'
   */
  SWC_VC_B.KeAP_single_sweep_start_min_lat_dist_m =
    SWC_VC_B.DiscreteTimeIntegrator_ll + 0.9F;

  /* SignalConversion generated from: '<S60>/ SFunction ' incorporates:
   *  Chart: '<S59>/Chart1'
   *  Constant: '<S56>/speed'
   */
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2[0] =
    SWC_VC_B.DataTypeConversion1;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2[1] =
    SWC_VC_B.DataTypeConversion2_l;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2[2] =
    SWC_VC_B.DataTypeConversion3;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2[3] = (-1.0F);
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2[4] = SWC_VC_B.whl_angl;

  /* SignalConversion generated from: '<S60>/ SFunction ' incorporates:
   *  Chart: '<S59>/Chart1'
   *  Constant: '<S57>/Constant10'
   *  Constant: '<S57>/Constant11'
   *  Constant: '<S57>/Constant2'
   *  Constant: '<S57>/Constant3'
   *  Constant: '<S57>/Constant4'
   *  Constant: '<S57>/Constant5'
   *  Constant: '<S57>/Constant6'
   *  Constant: '<S57>/Constant7'
   *  Constant: '<S57>/Constant8'
   *  Constant: '<S57>/Constant9'
   */
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[0] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[1] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[2] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[3] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[4] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[5] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[6] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[7] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[8] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[9] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[10] = 0.0F;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport14[11] = 0.0F;

  /* Chart: '<S59>/Chart1' incorporates:
   *  Constant: '<S57>/Constant1'
   *  Inport: '<Root>/MeAP_m_ParkSpotType'
   */
  if (SWC_VC_DW.is_active_c43_SWC_VC == 0U) {
    SWC_VC_DW.is_active_c43_SWC_VC = 1U;
    SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_OFF;
    SWC_VC_DW.c1 = 0;
    PP_state = 0;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    switch (SWC_VC_DW.is_c43_SWC_VC) {
     case SWC_VC_IN_ERROR:
      if (SWC_VC_B.RateTransition1 == 1) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_SCANNING;
        SWC_VC_enter_atomic_SCANNING();
      }
      break;

     case SWC_VC_IN_FOLLOWING:
      if (SWC_VC_B.UnitDelay_n) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_REGEN;
        SWC_VC_enter_atomic_REGEN();
      } else if (false || (!ACT_ACTIVE)) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_OFF;
        SWC_VC_DW.c1 = 0;
        PP_state = 0;
      } else {
        if (SWC_VC_B.RateTransition1 == 1) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_SCANNING;
          SWC_VC_enter_atomic_SCANNING();
        }
      }
      break;

     case SWC_VC_IN_REGEN:
      if (!SWC_VC_B.UnitDelay_n) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_TRANSPOSE;
        PP_state = 11;
      }
      break;

     case SWC_VC_IN_OFF:
      if (SWC_VC_B.RateTransition1 == 1) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_SCANNING;
        SWC_VC_enter_atomic_SCANNING();
      }
      break;

     case SWC_VC_IN_PLAN_FISHBONE:
      if (SWC_VC_DW.c1 < 0) {
        if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
             (SWC_VC_B.UnitDelay2 == 3))) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
          SWC_VC_B.i_j = 100 - SWC_VC_DW.c1;
          if (SWC_VC_B.i_j > 127) {
            SWC_VC_B.i_j = 127;
          }

          PP_state = (int8_T)SWC_VC_B.i_j;
          PP_Abort = true;
        } else if (SWC_VC_DW.regen_mode == 1.0F) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
          PP_state = 99;
        } else {
          guard1 = true;
        }
      } else {
        guard1 = true;
      }
      break;

     case SWC_VC_IN_PLAN_PARA:
      if (SWC_VC_DW.c1 < 0) {
        if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
             (SWC_VC_B.UnitDelay2 == 3))) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
          SWC_VC_B.i_j = 100 - SWC_VC_DW.c1;
          if (SWC_VC_B.i_j > 127) {
            SWC_VC_B.i_j = 127;
          }

          PP_state = (int8_T)SWC_VC_B.i_j;
          PP_Abort = true;
        } else if (SWC_VC_DW.regen_mode == 1.0F) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
          PP_state = 99;
        } else {
          guard2 = true;
        }
      } else {
        guard2 = true;
      }
      break;

     case SWC_VC_IN_PLAN_PERP:
      if (SWC_VC_DW.c1 < 0) {
        if ((SWC_VC_DW.regen_mode == 0.0F) || (((PSType == 3) || (PSType == 4)) &&
             (SWC_VC_B.UnitDelay2 == 3))) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_ERROR;
          SWC_VC_B.i_j = 100 - SWC_VC_DW.c1;
          if (SWC_VC_B.i_j > 127) {
            SWC_VC_B.i_j = 127;
          }

          PP_state = (int8_T)SWC_VC_B.i_j;
          PP_Abort = true;
        } else if (SWC_VC_DW.regen_mode == 1.0F) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RESTORE_OLD_PATH;
          PP_state = 99;
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }
      break;

     case SWC_VC_IN_RENDER_FISHBONE:
      SWC_VC_RENDER_FISHBONE();
      break;

     case SWC_VC_IN_RENDER_PARA:
      SWC_VC_RENDER_PARA();
      break;

     case SWC_VC_IN_RENDER_PERP:
      SWC_VC_RENDER_PERP();
      break;

     case SWC_VC_IN_TRANSPOSE:
      if (((PSType == 1) || (PSType == 2)) && (SWC_VC_DW.c1 == 1)) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_PLAN_PARA;
        PP_state = 21;
      } else if (((PSType == 3) || (PSType == 4)) && (SWC_VC_DW.c1 == 1)) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_PLAN_PERP;
        PP_state = 22;
      } else if (((PSType == 5) || (PSType == 6)) && (SWC_VC_DW.c1 == 1)) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_PLAN_FISHBONE;
        PP_state = 23;
      } else {
        SWC_VC_TFR(SWC_VC_B.TmpSignalConversionAtSFunctionInport2,
                   SWC_VC_B.DataTypeConversion4, (real32_T)PSType, SWC_VC_DW.tfR,
                   SWC_VC_DW.PSL, SWC_VC_DW.emL, &left, &SWC_VC_DW.c1);
        SWC_VC_DW.LeftPS = left;
      }
      break;

     case SWC_VC_IN_TRANSPOSE_INV:
      SWC_VC_TRANSPOSE_INV();
      break;

     case SWC_VC_IN_RESTORE_OLD_PATH:
      if (SWC_VC_DW.c1 == 1) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.regen_mode = 0.0F;
        SWC_VC_B.old_path = true;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_FOLLOWING;
        PP_state = 5;
      } else {
        memcpy(&SWC_VC_B.fx[0], &SWC_VC_DW.fx_old[0], 250U * sizeof(real32_T));
        memcpy(&SWC_VC_B.fy[0], &SWC_VC_DW.fy_old[0], 250U * sizeof(real32_T));
        memcpy(&SWC_VC_B.fh[0], &SWC_VC_DW.fh_old[0], 250U * sizeof(real32_T));
        memcpy(&SWC_VC_B.fs[0], &SWC_VC_DW.fs_old[0], 250U * sizeof(real32_T));
        memcpy(&SWC_VC_B.fv[0], &SWC_VC_DW.fv_old[0], 250U * sizeof(real32_T));
        for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 10; SWC_VC_B.i_j++) {
          if (SWC_VC_DW.fi_old[SWC_VC_B.i_j] < 32768.0F) {
            if (SWC_VC_DW.fi_old[SWC_VC_B.i_j] >= -32768.0F) {
              SWC_VC_B.fi[SWC_VC_B.i_j] = (int16_T)SWC_VC_DW.fi_old[SWC_VC_B.i_j];
            } else {
              SWC_VC_B.fi[SWC_VC_B.i_j] = MIN_int16_T;
            }
          } else {
            SWC_VC_B.fi[SWC_VC_B.i_j] = MAX_int16_T;
          }
        }

        SWC_VC_DW.c1 = 1;
      }
      break;

     default:
      /* case IN_SCANNING: */
      if (false) {
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_OFF;
        SWC_VC_DW.c1 = 0;
        PP_state = 0;
      } else {
        if ((SWC_VC_B.RateTransition1 == 2) && (PSType >= 1) && (PSType <= 6)) {
          SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_TRANSPOSE;
          PP_state = 11;
        }
      }
      break;
    }

    if (guard3) {
      if (SWC_VC_DW.c1 == 1) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RENDER_PERP;
        PP_state = 32;
      } else {
        SWC_VC_planPath_perp(SWC_VC_DW.emL, SWC_VC_DW.PSL, SWC_VC_DW.p_guide,
                             &SWC_VC_DW.c1);
      }
    }

    if (guard2) {
      if (SWC_VC_DW.c1 == 1) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RENDER_PARA;
        PP_state = 31;
      } else {
        SWC_VC_planPath_para(SWC_VC_DW.emL, SWC_VC_DW.PSL, SWC_VC_DW.p_guide,
                             &SWC_VC_DW.c1);
      }
    }

    if (guard1) {
      if (SWC_VC_DW.c1 == 1) {
        SWC_VC_DW.c1 = 0;
        SWC_VC_DW.is_c43_SWC_VC = SWC_VC_IN_RENDER_FISHBONE;
        PP_state = 33;
      } else {
        SWC_VC_planPath_fishbone(SWC_VC_DW.emL, SWC_VC_DW.PSL, SWC_VC_DW.p_guide,
          &SWC_VC_DW.c1);
      }
    }
  }

  /* DataTypeConversion: '<S13>/Data Type Conversion10' */
  memcpy((&(PP_H[0])), &SWC_VC_B.fh[0], 250U * sizeof(real32_T));

  /* DataTypeConversion: '<S13>/Data Type Conversion5' */
  memcpy((&(PP_x[0])), &SWC_VC_B.fx[0], 250U * sizeof(real32_T));

  /* DataTypeConversion: '<S13>/Data Type Conversion9' */
  memcpy((&(PP_y[0])), &SWC_VC_B.fy[0], 250U * sizeof(real32_T));

  /* Delay: '<S21>/Delay1' */
  SWC_VC_B.Delay1_k = SWC_VC_B.LogicalOperator2;

  /* Outputs for Triggered SubSystem: '<S21>/PathSeparation' incorporates:
   *  TriggerPort: '<S82>/Trigger'
   */
  if (SWC_VC_B.Delay1_k && (SWC_VC_PrevZCX.PathSeparation_Trig_ZCE != POS_ZCSIG))
  {
    /* Inport: '<S82>/CurrentSweep' */
    SWC_VC_B.CurrentSweep = SWC_VC_B.Delay;

    /* MATLAB Function: '<S82>/MATLAB Function PathSeparation' incorporates:
     *  Constant: '<S82>/Constant'
     *  Constant: '<S82>/Constant1'
     */
    memset(&SWC_VC_B.O_steer[0], 0, 250U * sizeof(real32_T));
    memset(&SWC_VC_B.O_speed[0], 0, 250U * sizeof(real32_T));
    memset(&SWC_VC_B.O_yaw[0], 0, 250U * sizeof(real32_T));
    memset(&SWC_VC_B.O_x[0], 0, 250U * sizeof(real32_T));
    memset(&SWC_VC_B.O_y[0], 0, 250U * sizeof(real32_T));
    SWC_VC_B.O_Dir = 0;
    SWC_VC_B.O_NextDir = -1;
    SWC_VC_B.O_WPlastSweeps = 0U;
    SWC_VC_B.O_WPSweepN = 0U;
    if (SWC_VC_B.CurrentSweep >= 1) {
      abs_fEIKHoQZ(SWC_VC_B.fi, SWC_VC_B.y_i);
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 10; SWC_VC_B.i_j++) {
        tmp = SWC_VC_B.y_i[SWC_VC_B.i_j];
        if (SWC_VC_B.y_i[SWC_VC_B.i_j] < 0) {
          tmp = 0;
        } else {
          if (SWC_VC_B.y_i[SWC_VC_B.i_j] > 255) {
            tmp = 255;
          }
        }

        SWC_VC_B.i[SWC_VC_B.i_j] = (uint8_T)tmp;
      }

      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 10; SWC_VC_B.i_j++) {
        SWC_VC_B.r[SWC_VC_B.i_j] = SWC_VC_B.fi[SWC_VC_B.i_j];
      }

      SWC_VC_B.r[10] = 0;
      sign_dXEnEZRu(SWC_VC_B.r);
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 11; SWC_VC_B.i_j++) {
        tmp = SWC_VC_B.r[SWC_VC_B.i_j];
        if (SWC_VC_B.r[SWC_VC_B.i_j] > 127) {
          tmp = 127;
        } else {
          if (SWC_VC_B.r[SWC_VC_B.i_j] < -128) {
            tmp = -128;
          }
        }

        SWC_VC_B.i_sign[SWC_VC_B.i_j] = (int8_T)tmp;
      }

      if (SWC_VC_B.CurrentSweep == 1) {
        WPst = 1U;
        WPend = SWC_VC_B.i[0];
      } else {
        SWC_VC_B.qY = SWC_VC_B.CurrentSweep - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY > SWC_VC_B.CurrentSweep) {
          SWC_VC_B.qY = 0U;
        }

        SWC_VC_B.loop_ub = (int32_T)SWC_VC_B.qY;
        SWC_VC_B.i_size = (int32_T)SWC_VC_B.qY;
        if (0 <= SWC_VC_B.loop_ub - 1) {
          memcpy(&SWC_VC_B.i_data[0], &SWC_VC_B.i[0], SWC_VC_B.loop_ub * sizeof
                 (uint8_T));
        }

        SWC_VC_B.minV = rt_roundd_snf(SWC_VC_sum_i(SWC_VC_B.i_data,
          &SWC_VC_B.i_size));
        if (SWC_VC_B.minV < 256.0) {
          if (SWC_VC_B.minV >= 0.0) {
            SWC_VC_B.O_WPlastSweeps = (uint8_T)SWC_VC_B.minV;
          } else {
            SWC_VC_B.O_WPlastSweeps = 0U;
          }
        } else {
          SWC_VC_B.O_WPlastSweeps = MAX_uint8_T;
        }

        SWC_VC_B.i_j = (int32_T)(SWC_VC_B.O_WPlastSweeps + 1U);
        if ((uint32_T)SWC_VC_B.i_j > 255U) {
          SWC_VC_B.i_j = 255;
        }

        WPst = (uint8_T)SWC_VC_B.i_j;
        SWC_VC_B.i_j = (int32_T)((uint32_T)SWC_VC_B.i[SWC_VC_B.CurrentSweep - 1]
          + (uint8_T)SWC_VC_B.i_j);
        if ((uint32_T)SWC_VC_B.i_j > 255U) {
          SWC_VC_B.i_j = 255;
        }

        WPend = (uint8_T)(SWC_VC_B.i_j - 1);
      }

      SWC_VC_B.O_WPSweepN_tmp = SWC_VC_B.CurrentSweep - 1;
      SWC_VC_B.O_WPSweepN = SWC_VC_B.i[SWC_VC_B.O_WPSweepN_tmp];
      if (WPst > WPend) {
        SWC_VC_B.c = 0;
        SWC_VC_B.i_j = 0;
      } else {
        SWC_VC_B.c = WPst - 1;
        SWC_VC_B.i_j = WPend;
      }

      SWC_VC_B.loop_ub = SWC_VC_B.i_j - SWC_VC_B.c;
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
        SWC_VC_B.O_steer[SWC_VC_B.i_j] = SWC_VC_B.fs[SWC_VC_B.c + SWC_VC_B.i_j];
      }

      if (WPst > WPend) {
        SWC_VC_B.c = 0;
        SWC_VC_B.i_j = 0;
      } else {
        SWC_VC_B.c = WPst - 1;
        SWC_VC_B.i_j = WPend;
      }

      SWC_VC_B.loop_ub = SWC_VC_B.i_j - SWC_VC_B.c;
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
        SWC_VC_B.O_yaw[SWC_VC_B.i_j] = PP_H[SWC_VC_B.c + SWC_VC_B.i_j];
      }

      if (WPst > WPend) {
        SWC_VC_B.c = 0;
        SWC_VC_B.i_j = 0;
      } else {
        SWC_VC_B.c = WPst - 1;
        SWC_VC_B.i_j = WPend;
      }

      SWC_VC_B.loop_ub = SWC_VC_B.i_j - SWC_VC_B.c;
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
        SWC_VC_B.O_x[SWC_VC_B.i_j] = PP_x[SWC_VC_B.c + SWC_VC_B.i_j];
      }

      if (WPst > WPend) {
        SWC_VC_B.c = 0;
        SWC_VC_B.i_j = 0;
      } else {
        SWC_VC_B.c = WPst - 1;
        SWC_VC_B.i_j = WPend;
      }

      SWC_VC_B.loop_ub = SWC_VC_B.i_j - SWC_VC_B.c;
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
        SWC_VC_B.O_y[SWC_VC_B.i_j] = PP_y[SWC_VC_B.c + SWC_VC_B.i_j];
      }

      SWC_VC_B.O_Dir = SWC_VC_B.i_sign[SWC_VC_B.O_WPSweepN_tmp];
      SWC_VC_B.i_j = (int32_T)(SWC_VC_B.CurrentSweep + 1U);
      if ((uint32_T)SWC_VC_B.i_j > 255U) {
        SWC_VC_B.i_j = 255;
      }

      SWC_VC_B.O_NextDir = SWC_VC_B.i_sign[SWC_VC_B.i_j - 1];
      if (WPst > WPend) {
        SWC_VC_B.c = 0;
        SWC_VC_B.k = 0;
      } else {
        SWC_VC_B.c = WPst - 1;
        SWC_VC_B.k = WPend;
      }

      SWC_VC_B.k -= SWC_VC_B.c;
      for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.k; SWC_VC_B.i_j++) {
        SWC_VC_B.Spd_data[SWC_VC_B.i_j] = SWC_VC_B.fv[SWC_VC_B.c + SWC_VC_B.i_j];
      }

      for (WPst = 2U; WPst <= SWC_VC_B.O_WPSweepN; WPst++) {
        SWC_VC_B.qY = WPst - /*MW:OvSatOk*/ 1U;
        if (SWC_VC_B.qY > WPst) {
          SWC_VC_B.qY = 0U;
        }

        SWC_VC_B.i_j = WPst - 1;
        SWC_VC_B.Spd_data[SWC_VC_B.i_j] = fminf(SWC_VC_B.Spd_data[SWC_VC_B.i_j],
          SWC_VC_B.Spd_data[(int32_T)SWC_VC_B.qY - 1] + 0.12F);
      }

      SWC_VC_B.qY = SWC_VC_B.i[SWC_VC_B.O_WPSweepN_tmp] - /*MW:OvSatOk*/ 1U;
      if (SWC_VC_B.qY > SWC_VC_B.i[SWC_VC_B.O_WPSweepN_tmp]) {
        SWC_VC_B.qY = 0U;
      }

      WPst = (uint8_T)SWC_VC_B.qY;
      while (WPst > 0) {
        SWC_VC_B.i_j = WPst - 1;
        SWC_VC_B.Spd_data[SWC_VC_B.i_j] = fminf(SWC_VC_B.Spd_data[SWC_VC_B.i_j],
          SWC_VC_B.Spd_data[WPst] + 0.12F);
        WPst = (uint8_T)SWC_VC_B.i_j;
      }

      if (1 > SWC_VC_B.i[SWC_VC_B.O_WPSweepN_tmp]) {
        SWC_VC_B.i_j = -1;
      } else {
        SWC_VC_B.i_j = SWC_VC_B.i[SWC_VC_B.O_WPSweepN_tmp] - 1;
      }

      SWC_VC_B.i_j++;
      if (0 <= SWC_VC_B.k - 1) {
        memcpy(&SWC_VC_B.dist_y[0], &SWC_VC_B.distance_data[0], SWC_VC_B.k *
               sizeof(real32_T));
      }

      SWC_VC_B.O_WPSweepN_tmp = 0;
      while (SWC_VC_B.O_WPSweepN_tmp <= SWC_VC_B.k - 1) {
        SWC_VC_B.dist_y[SWC_VC_B.O_WPSweepN_tmp] = fmaxf
          (SWC_VC_B.Spd_data[SWC_VC_B.O_WPSweepN_tmp], 2.0F);
        SWC_VC_B.O_WPSweepN_tmp++;
      }

      if (0 <= SWC_VC_B.i_j - 1) {
        memcpy(&SWC_VC_B.O_speed[0], &SWC_VC_B.dist_y[0], SWC_VC_B.i_j * sizeof
               (real32_T));
      }
    }

    /* End of MATLAB Function: '<S82>/MATLAB Function PathSeparation' */

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    memcpy(&SWC_VC_B.steer[0], &SWC_VC_B.O_steer[0], 250U * sizeof(real32_T));

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    memcpy(&SWC_VC_B.speed_d[0], &SWC_VC_B.O_speed[0], 250U * sizeof(real32_T));

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    memcpy(&SWC_VC_B.yaw[0], &SWC_VC_B.O_yaw[0], 250U * sizeof(real32_T));

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    memcpy(&SWC_VC_B.x[0], &SWC_VC_B.O_x[0], 250U * sizeof(real32_T));

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    memcpy(&SWC_VC_B.y_o[0], &SWC_VC_B.O_y[0], 250U * sizeof(real32_T));

    /* DataTypeConversion: '<S82>/Data Type Conversion' */
    SWC_VC_B.NextDir_a = SWC_VC_B.O_Dir;

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    SWC_VC_B.Dir = SWC_VC_B.NextDir_a;

    /* DataTypeConversion: '<S82>/Data Type Conversion1' */
    SWC_VC_B.NextDir_a = SWC_VC_B.O_NextDir;

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    SWC_VC_B.NextDir = SWC_VC_B.NextDir_a;

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    SWC_VC_B.wp_lastsweeps = SWC_VC_B.O_WPlastSweeps;

    /* SignalConversion generated from: '<S82>/Signal Conversion' */
    SWC_VC_B.wp_N = SWC_VC_B.O_WPSweepN;
  }

  SWC_VC_PrevZCX.PathSeparation_Trig_ZCE = SWC_VC_B.Delay1_k;

  /* End of Outputs for SubSystem: '<S21>/PathSeparation' */

  /* DataTypeConversion: '<Root>/Data Type Conversion8' */
  memcpy(&rty_MaAP_m_PlannerWayPointsY[0], (&(PP_y[0])), 250U * sizeof(real32_T));

  /* DataTypeConversion: '<Root>/Data Type Conversion9' */
  memcpy(&rty_MaAP_m_PlannerWayPointsX[0], (&(PP_x[0])), 250U * sizeof(real32_T));
  for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 14; SWC_VC_B.i_j++) {
    /* MATLAB Function: '<S35>/MATLAB Function' incorporates:
     *  Constant: '<S5>/Constant'
     */
    SWC_VC_B.y_a[SWC_VC_B.i_j] = 0.0 * b[SWC_VC_B.i_j];

    /* MATLAB Function: '<S36>/MATLAB Function' incorporates:
     *  Constant: '<S5>/Constant'
     */
    SWC_VC_B.y[SWC_VC_B.i_j] = 0.0 * b_0[SWC_VC_B.i_j];
  }

  /* Logic: '<S23>/Logical Operator1' */
  SWC_VC_B.LogicalOperator2_a = !SWC_VC_B.old_path;

  /* RateTransition: '<S26>/Rate Transition' */
  SWC_VC_B.RateTransition_j = PP_state;

  /* RelationalOperator: '<S33>/Compare' incorporates:
   *  Constant: '<S33>/Constant'
   */
  SWC_VC_B.Compare_b = (SWC_VC_B.RateTransition_j == 5);

  /* Logic: '<S26>/Logical Operator' */
  SWC_VC_B.LogicalOperator = ((*rtu_MeAP_b_VCActive) && SWC_VC_B.Compare_b);

  /* Logic: '<S23>/Logical Operator2' */
  SWC_VC_B.UpperRelop = !SWC_VC_B.LogicalOperator;

  /* Logic: '<S23>/Logical Operator4' */
  SWC_VC_B.LogicalOperator4 = (SWC_VC_B.LogicalOperator2_a &&
    SWC_VC_B.UpperRelop);

  /* Outputs for Enabled SubSystem: '<S23>/Enabled Subsystem' incorporates:
   *  EnablePort: '<S28>/Enable'
   */
  if (SWC_VC_B.LogicalOperator4) {
    /* Inport: '<S28>/In1' */
    SWC_VC_B.In1[0] = Ma_AP_I_PSLimFSX;
    SWC_VC_B.In1[1] = Ma_AP_I_PSLimFSY;
    SWC_VC_B.In1[2] = Ma_AP_I_PSLimFBX;
    SWC_VC_B.In1[3] = Ma_AP_I_PSLimFBY;
    SWC_VC_B.In1[4] = Ma_AP_I_PSLimRBX;
    SWC_VC_B.In1[5] = Ma_AP_I_PSLimRBY;
    SWC_VC_B.In1[6] = Ma_AP_I_PSLimRSX;
    SWC_VC_B.In1[7] = Ma_AP_I_PSLimRSY;
  }

  /* End of Outputs for SubSystem: '<S23>/Enabled Subsystem' */

  /* RelationalOperator: '<S79>/Compare' incorporates:
   *  Constant: '<S79>/Constant'
   */
  SWC_VC_B.Compare_n = (SWC_VC_B.CurrentSweep != ((uint8_T)0U));

  /* Outputs for Enabled SubSystem: '<S21>/Control' incorporates:
   *  EnablePort: '<S80>/Enable'
   */
  if (SWC_VC_B.Compare_n) {
    if (!SWC_VC_DW.Control_MODE) {
      /* InitializeConditions for Delay: '<S84>/Delay One Step' */
      SWC_VC_DW.DelayOneStep_DSTATE = 0.0F;
      SWC_VC_DW.Control_MODE = true;
    }

    /* MATLAB Function: '<S80>/MATLAB Function' */
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 250; SWC_VC_B.i_j++) {
      SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j] = SWC_VC_B.x[SWC_VC_B.i_j] - X_MABx;
    }

    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 250; SWC_VC_B.i_j++) {
      SWC_VC_B.dist_y[SWC_VC_B.i_j] = SWC_VC_B.y_o[SWC_VC_B.i_j] - Y_MABx;
    }

    SWC_VC_B.lookahead_dist_wp = -heading_MABx - 180.0F;
    cosd_KZN3FnAl(&SWC_VC_B.lookahead_dist_wp);
    SWC_VC_B.lookahead_long = -heading_MABx - 180.0F;
    sind_7is3Ljjc(&SWC_VC_B.lookahead_long);
    SWC_VC_B.absx = -heading_MABx - 180.0F;
    sind_7is3Ljjc(&SWC_VC_B.absx);
    SWC_VC_B.virtual_point_length_m = -heading_MABx - 180.0F;
    cosd_KZN3FnAl(&SWC_VC_B.virtual_point_length_m);
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 250; SWC_VC_B.i_j++) {
      SWC_VC_B.Dist2Path_long[SWC_VC_B.i_j] =
        SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j] * SWC_VC_B.lookahead_dist_wp -
        SWC_VC_B.dist_y[SWC_VC_B.i_j] * SWC_VC_B.lookahead_long;
      SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j] = SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j]
        * SWC_VC_B.absx + SWC_VC_B.dist_y[SWC_VC_B.i_j] *
        SWC_VC_B.virtual_point_length_m;
    }

    /* End of MATLAB Function: '<S80>/MATLAB Function' */

    /* MATLAB Function: '<S83>/MATLAB Function' incorporates:
     *  Constant: '<S83>/Fixed_Lookaheads'
     *  MultiPortSwitch: '<S89>/Index WP'
     */
    SWC_VC_B.k = 1;
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 10; SWC_VC_B.i_j++) {
      SWC_VC_B.i[SWC_VC_B.i_j] = 0U;
      SWC_VC_B.waypoint_dist[SWC_VC_B.i_j] = 0.0F;
    }

    WPend = 0U;
    SWC_VC_B.O_WPSweepN_tmp = SWC_VC_B.wp_N - 1;
    if (0 <= SWC_VC_B.O_WPSweepN_tmp) {
      memset(&SWC_VC_B.waypoint_segment_dist_data[0], 0,
             (SWC_VC_B.O_WPSweepN_tmp + 1) * sizeof(real32_T));
    }

    if (1 > SWC_VC_B.wp_N) {
      SWC_VC_B.loop_ub = -1;
    } else {
      SWC_VC_B.loop_ub = SWC_VC_B.O_WPSweepN_tmp;
    }

    SWC_VC_B.tmp_size_o[0] = 1;
    SWC_VC_B.tmp_size_o[1] = SWC_VC_B.loop_ub + 1;
    if (0 <= SWC_VC_B.loop_ub) {
      memcpy(&SWC_VC_B.dist_y[0], &SWC_VC_B.Dist2Path_long[0], (SWC_VC_B.loop_ub
              + 1) * sizeof(real32_T));
    }

    SWC_VC_power_e(SWC_VC_B.dist_y, SWC_VC_B.tmp_size_o, SWC_VC_B.Spd_data,
                   SWC_VC_B.tmp_size_l);
    if (1 > SWC_VC_B.wp_N) {
      SWC_VC_B.loop_ub = -1;
    } else {
      SWC_VC_B.loop_ub = SWC_VC_B.O_WPSweepN_tmp;
    }

    SWC_VC_B.tmp_size_m[0] = 1;
    SWC_VC_B.tmp_size_m[1] = SWC_VC_B.loop_ub + 1;
    if (0 <= SWC_VC_B.loop_ub) {
      memcpy(&SWC_VC_B.dist_y[0], &SWC_VC_B.Dist2Path_lat[0], (SWC_VC_B.loop_ub
              + 1) * sizeof(real32_T));
    }

    SWC_VC_power_e(SWC_VC_B.dist_y, SWC_VC_B.tmp_size_m, SWC_VC_B.tmp_data,
                   SWC_VC_B.tmp_size_o);
    SWC_VC_B.distance_size[0] = 1;
    SWC_VC_B.distance_size[1] = SWC_VC_B.tmp_size_l[1];
    SWC_VC_B.loop_ub = SWC_VC_B.tmp_size_l[0] * SWC_VC_B.tmp_size_l[1];
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
      SWC_VC_B.distance_data[SWC_VC_B.i_j] = SWC_VC_B.Spd_data[SWC_VC_B.i_j] +
        SWC_VC_B.tmp_data[SWC_VC_B.i_j];
    }

    SWC_VC_sqrt_k(SWC_VC_B.distance_data, SWC_VC_B.distance_size);
    SWC_VC_B.qY_tmp = SWC_VC_B.wp_N - /*MW:OvSatOk*/ 1U;
    SWC_VC_B.qY = SWC_VC_B.qY_tmp;
    if (SWC_VC_B.qY_tmp > SWC_VC_B.wp_N) {
      SWC_VC_B.qY = 0U;
    }

    SWC_VC_B.i_j = 1;
    exitg1 = false;
    while ((!exitg1) && (SWC_VC_B.i_j - 1 <= (uint8_T)SWC_VC_B.qY - 1)) {
      SWC_VC_B.c = (uint8_T)SWC_VC_B.i_j - 1;
      SWC_VC_B.lookahead_dist_wp = SWC_VC_B.Dist2Path_long[(uint8_T)SWC_VC_B.i_j];
      if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] < 0.0F) {
        SWC_VC_B.lookahead_long = -1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] > 0.0F) {
        SWC_VC_B.lookahead_long = 1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] == 0.0F) {
        SWC_VC_B.lookahead_long = 0.0F;
      } else {
        SWC_VC_B.lookahead_long = (rtNaNF);
      }

      if (SWC_VC_B.lookahead_dist_wp < 0.0F) {
        SWC_VC_B.lookahead_dist_wp = -1.0F;
      } else if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 1.0F;
      } else if (SWC_VC_B.lookahead_dist_wp == 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 0.0F;
      } else {
        SWC_VC_B.lookahead_dist_wp = (rtNaNF);
      }

      if (SWC_VC_B.lookahead_long != SWC_VC_B.lookahead_dist_wp) {
        SWC_VC_B.i[SWC_VC_B.k - 1] = (uint8_T)SWC_VC_B.i_j;
        SWC_VC_B.waypoint_dist[SWC_VC_B.k - 1] =
          SWC_VC_B.distance_data[SWC_VC_B.c];
        SWC_VC_B.k++;
      }

      if (SWC_VC_B.k > 10) {
        exitg1 = true;
      } else {
        SWC_VC_B.i_j++;
      }
    }

    if (1 > SWC_VC_B.k - 1) {
      SWC_VC_B.i_j = -1;
    } else {
      SWC_VC_B.i_j = SWC_VC_B.k - 2;
    }

    SWC_VC_B.c = SWC_VC_B.i_j + 1;
    if ((SWC_VC_B.k == 1) || (SWC_VC_B.k > 10)) {
      if (SWC_VC_B.distance_size[1] <= 2) {
        if (SWC_VC_B.distance_size[1] == 1) {
          SWC_VC_B.i_j = 1;
        } else if (SWC_VC_B.distance_data[0] > SWC_VC_B.distance_data[1]) {
          SWC_VC_B.i_j = 2;
        } else if (rtIsNaNF(SWC_VC_B.distance_data[0])) {
          if (!rtIsNaNF(SWC_VC_B.distance_data[1])) {
            SWC_VC_B.i_j = 2;
          } else {
            SWC_VC_B.i_j = 1;
          }
        } else {
          SWC_VC_B.i_j = 1;
        }
      } else {
        if (!rtIsNaNF(SWC_VC_B.distance_data[0])) {
          SWC_VC_B.i_j = 1;
        } else {
          SWC_VC_B.i_j = 0;
          SWC_VC_B.c = 2;
          exitg1 = false;
          while ((!exitg1) && (SWC_VC_B.c <= SWC_VC_B.distance_size[1])) {
            if (!rtIsNaNF(SWC_VC_B.distance_data[SWC_VC_B.c - 1])) {
              SWC_VC_B.i_j = SWC_VC_B.c;
              exitg1 = true;
            } else {
              SWC_VC_B.c++;
            }
          }
        }

        if (SWC_VC_B.i_j == 0) {
          SWC_VC_B.i_j = 1;
        } else {
          SWC_VC_B.lookahead_dist_wp = SWC_VC_B.distance_data[SWC_VC_B.i_j - 1];
          SWC_VC_B.c = SWC_VC_B.i_j;
          while (SWC_VC_B.c + 1 <= SWC_VC_B.distance_size[1]) {
            if (SWC_VC_B.lookahead_dist_wp > SWC_VC_B.distance_data[SWC_VC_B.c])
            {
              SWC_VC_B.lookahead_dist_wp = SWC_VC_B.distance_data[SWC_VC_B.c];
              SWC_VC_B.i_j = SWC_VC_B.c + 1;
            }

            SWC_VC_B.c++;
          }
        }
      }

      SWC_VC_B.curr_wp_l = (uint8_T)SWC_VC_B.i_j;
      SWC_VC_B.curr_factor = 0.0F;
    } else {
      if (0 <= SWC_VC_B.c - 1) {
        memcpy(&SWC_VC_B.varargin_1_data[0], &SWC_VC_B.waypoint_dist[0],
               SWC_VC_B.c * sizeof(real32_T));
      }

      if ((int8_T)SWC_VC_B.c <= 2) {
        if ((int8_T)SWC_VC_B.c == 1) {
          SWC_VC_B.i_j = 1;
        } else if (SWC_VC_B.waypoint_dist[0] > SWC_VC_B.waypoint_dist[1]) {
          SWC_VC_B.i_j = 2;
        } else if (rtIsNaNF(SWC_VC_B.waypoint_dist[0])) {
          if (!rtIsNaNF(SWC_VC_B.waypoint_dist[1])) {
            SWC_VC_B.i_j = 2;
          } else {
            SWC_VC_B.i_j = 1;
          }
        } else {
          SWC_VC_B.i_j = 1;
        }
      } else {
        if (!rtIsNaNF(SWC_VC_B.waypoint_dist[0])) {
          SWC_VC_B.i_j = 1;
        } else {
          SWC_VC_B.i_j = 0;
          SWC_VC_B.k = 2;
          exitg1 = false;
          while ((!exitg1) && (SWC_VC_B.k <= (int8_T)SWC_VC_B.c)) {
            if (!rtIsNaNF(SWC_VC_B.varargin_1_data[SWC_VC_B.k - 1])) {
              SWC_VC_B.i_j = SWC_VC_B.k;
              exitg1 = true;
            } else {
              SWC_VC_B.k++;
            }
          }
        }

        if (SWC_VC_B.i_j == 0) {
          SWC_VC_B.i_j = 1;
        } else {
          SWC_VC_B.lookahead_dist_wp = SWC_VC_B.waypoint_dist[SWC_VC_B.i_j - 1];
          SWC_VC_B.k = SWC_VC_B.i_j;
          while (SWC_VC_B.k + 1 <= (int8_T)SWC_VC_B.c) {
            if (SWC_VC_B.lookahead_dist_wp > SWC_VC_B.waypoint_dist[SWC_VC_B.k])
            {
              SWC_VC_B.lookahead_dist_wp = SWC_VC_B.waypoint_dist[SWC_VC_B.k];
              SWC_VC_B.i_j = SWC_VC_B.k + 1;
            }

            SWC_VC_B.k++;
          }
        }
      }

      SWC_VC_B.curr_wp_l = SWC_VC_B.i[SWC_VC_B.i_j - 1];
      SWC_VC_B.i_j = (uint8_T)SWC_VC_B.i_j - 1;
      SWC_VC_B.c = (int32_T)(SWC_VC_B.i[SWC_VC_B.i_j] + 1U);
      if ((uint32_T)SWC_VC_B.c > 255U) {
        SWC_VC_B.c = 255;
      }

      SWC_VC_B.curr_factor = fabsf(SWC_VC_B.Dist2Path_long[SWC_VC_B.curr_wp_l -
        1] / (SWC_VC_B.Dist2Path_long[SWC_VC_B.i[SWC_VC_B.i_j] - 1] -
              SWC_VC_B.Dist2Path_long[SWC_VC_B.c - 1]));
    }

    if (1 > SWC_VC_B.wp_N) {
      SWC_VC_B.loop_ub = -1;
    } else {
      SWC_VC_B.loop_ub = SWC_VC_B.O_WPSweepN_tmp;
    }

    SWC_VC_B.tmp_size[0] = 1;
    SWC_VC_B.tmp_size[1] = SWC_VC_B.loop_ub + 1;
    if (0 <= SWC_VC_B.loop_ub) {
      memcpy(&SWC_VC_B.dist_y[0], &SWC_VC_B.x[0], (SWC_VC_B.loop_ub + 1) *
             sizeof(real32_T));
    }

    SWC_VC_diff_a(SWC_VC_B.dist_y, SWC_VC_B.tmp_size, SWC_VC_B.tmp_data_g,
                  SWC_VC_B.tmp_size_o);
    SWC_VC_power_e(SWC_VC_B.tmp_data_g, SWC_VC_B.tmp_size_o, SWC_VC_B.dist_y,
                   SWC_VC_B.tmp_size_l);
    if (1 > SWC_VC_B.wp_N) {
      SWC_VC_B.loop_ub = -1;
    } else {
      SWC_VC_B.loop_ub = SWC_VC_B.O_WPSweepN_tmp;
    }

    SWC_VC_B.tmp_size_c[0] = 1;
    SWC_VC_B.tmp_size_c[1] = SWC_VC_B.loop_ub + 1;
    if (0 <= SWC_VC_B.loop_ub) {
      memcpy(&SWC_VC_B.Spd_data[0], &SWC_VC_B.y_o[0], (SWC_VC_B.loop_ub + 1) *
             sizeof(real32_T));
    }

    SWC_VC_diff_a(SWC_VC_B.Spd_data, SWC_VC_B.tmp_size_c, SWC_VC_B.tmp_data_g,
                  SWC_VC_B.tmp_size_o);
    SWC_VC_power_e(SWC_VC_B.tmp_data_g, SWC_VC_B.tmp_size_o, SWC_VC_B.Spd_data,
                   SWC_VC_B.tmp_size_m);
    SWC_VC_B.varargin_1_size[0] = 1;
    SWC_VC_B.varargin_1_size[1] = SWC_VC_B.tmp_size_l[1];
    SWC_VC_B.loop_ub = SWC_VC_B.tmp_size_l[0] * SWC_VC_B.tmp_size_l[1];
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.loop_ub; SWC_VC_B.i_j++) {
      SWC_VC_B.varargin_1_data[SWC_VC_B.i_j] = SWC_VC_B.dist_y[SWC_VC_B.i_j] +
        SWC_VC_B.Spd_data[SWC_VC_B.i_j];
    }

    SWC_VC_sqrt_k(SWC_VC_B.varargin_1_data, SWC_VC_B.varargin_1_size);
    if (SWC_VC_B.curr_wp_l == SWC_VC_B.wp_N) {
      SWC_VC_B.remain_dist = 0.0F;
    } else {
      SWC_VC_B.qY = SWC_VC_B.qY_tmp;
      if (SWC_VC_B.qY_tmp > SWC_VC_B.wp_N) {
        SWC_VC_B.qY = 0U;
      }

      if (SWC_VC_B.curr_wp_l == (int32_T)SWC_VC_B.qY) {
        SWC_VC_B.qY = SWC_VC_B.qY_tmp;
        if (SWC_VC_B.qY_tmp > SWC_VC_B.wp_N) {
          SWC_VC_B.qY = 0U;
        }

        SWC_VC_B.remain_dist = SWC_VC_B.varargin_1_data[(int32_T)SWC_VC_B.qY - 1]
          * (1.0F - SWC_VC_B.curr_factor);
      } else if ((SWC_VC_B.curr_wp_l == 1) && (SWC_VC_B.curr_factor == 0.0F)) {
        SWC_VC_B.remain_dist = SWC_VC_B.distance_data[1] + SWC_VC_sum
          (SWC_VC_B.varargin_1_data, SWC_VC_B.varargin_1_size);
      } else {
        SWC_VC_B.i_j = (int32_T)(SWC_VC_B.curr_wp_l + 1U);
        if ((uint32_T)SWC_VC_B.i_j > 255U) {
          SWC_VC_B.i_j = 255;
        }

        SWC_VC_B.qY = SWC_VC_B.qY_tmp;
        if (SWC_VC_B.qY_tmp > SWC_VC_B.wp_N) {
          SWC_VC_B.qY = 0U;
        }

        if ((uint8_T)SWC_VC_B.i_j > (uint8_T)SWC_VC_B.qY) {
          SWC_VC_B.k = 0;
          SWC_VC_B.c = 0;
        } else {
          SWC_VC_B.k = (uint8_T)SWC_VC_B.i_j - 1;
          SWC_VC_B.c = (uint8_T)SWC_VC_B.qY;
        }

        SWC_VC_B.varargin_1_size_g[0] = 1;
        SWC_VC_B.c -= SWC_VC_B.k;
        SWC_VC_B.varargin_1_size_g[1] = SWC_VC_B.c;
        for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < SWC_VC_B.c; SWC_VC_B.i_j++) {
          SWC_VC_B.tmp_data_g[SWC_VC_B.i_j] =
            SWC_VC_B.varargin_1_data[SWC_VC_B.k + SWC_VC_B.i_j];
        }

        SWC_VC_B.remain_dist = SWC_VC_B.varargin_1_data[SWC_VC_B.curr_wp_l - 1] *
          (1.0F - SWC_VC_B.curr_factor) + SWC_VC_sum(SWC_VC_B.tmp_data_g,
          SWC_VC_B.varargin_1_size_g);
      }
    }

    sweep_id = mod_B4YoGN9V(SWC_VC_B.Delay);
    if (sweep_id == 0) {
      sweep_id = 3U;
    }

    SWC_VC_B.preview_wp = SWC_VC_B.curr_wp_l;
    SWC_VC_B.factor_preview = SWC_VC_B.curr_factor;
    if (SWC_VC_B.qY_tmp > SWC_VC_B.wp_N) {
      SWC_VC_B.qY_tmp = 0U;
    }

    if (SWC_VC_B.curr_wp_l >= (int32_T)SWC_VC_B.qY_tmp) {
      SWC_VC_B.preview_wp = SWC_VC_B.wp_N;
    } else {
      SWC_VC_B.c = SWC_VC_B.curr_wp_l - 1;
      if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] < 0.0F) {
        SWC_VC_B.lookahead_dist_wp = -1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] > 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] == 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 0.0F;
      } else {
        SWC_VC_B.lookahead_dist_wp = (rtNaNF);
      }

      SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] =
        SWC_VC_B.varargin_1_data[SWC_VC_B.c] * SWC_VC_B.curr_factor *
        SWC_VC_B.lookahead_dist_wp;
      if (SWC_VC_B.Dist2Path_long[SWC_VC_B.curr_wp_l] < 0.0F) {
        SWC_VC_B.lookahead_dist_wp = -1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.curr_wp_l] > 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 1.0F;
      } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.curr_wp_l] == 0.0F) {
        SWC_VC_B.lookahead_dist_wp = 0.0F;
      } else {
        SWC_VC_B.lookahead_dist_wp = (rtNaNF);
      }

      SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.curr_wp_l] =
        SWC_VC_B.varargin_1_data[SWC_VC_B.c] * (1.0F - SWC_VC_B.curr_factor) *
        SWC_VC_B.lookahead_dist_wp;
      for (WPst = (uint8_T)(SWC_VC_B.curr_wp_l + 2); WPst <= SWC_VC_B.wp_N; WPst
           ++) {
        SWC_VC_B.qY_tmp = WPst - /*MW:OvSatOk*/ 1U;
        SWC_VC_B.qY = SWC_VC_B.qY_tmp;
        if (SWC_VC_B.qY_tmp > WPst) {
          SWC_VC_B.qY = 0U;
          SWC_VC_B.qY_tmp = 0U;
        }

        SWC_VC_B.c = WPst - 1;
        if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] < 0.0F) {
          SWC_VC_B.lookahead_dist_wp = -1.0F;
        } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] > 0.0F) {
          SWC_VC_B.lookahead_dist_wp = 1.0F;
        } else if (SWC_VC_B.Dist2Path_long[SWC_VC_B.c] == 0.0F) {
          SWC_VC_B.lookahead_dist_wp = 0.0F;
        } else {
          SWC_VC_B.lookahead_dist_wp = (rtNaNF);
        }

        SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] =
          SWC_VC_B.varargin_1_data[(int32_T)SWC_VC_B.qY_tmp - 1] *
          SWC_VC_B.lookahead_dist_wp + SWC_VC_B.waypoint_segment_dist_data
          [(int32_T)SWC_VC_B.qY - 1];
      }

      if (SWC_VC_B.Dist2Path_long[SWC_VC_B.curr_wp_l] > 0.0F) {
        SWC_VC_B.lookahead_dist_wp = (real32_T)
          rtCP_Fixed_Lookaheads_Value[sweep_id - 1];
        for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j <= SWC_VC_B.O_WPSweepN_tmp;
             SWC_VC_B.i_j++) {
          SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.i_j] -=
            SWC_VC_B.lookahead_dist_wp;
        }
      } else {
        SWC_VC_B.lookahead_dist_wp = (real32_T)
          rtCP_Fixed_Lookaheads_Value[sweep_id - 1];
        for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j <= SWC_VC_B.O_WPSweepN_tmp;
             SWC_VC_B.i_j++) {
          SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.i_j] =
            -SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.i_j] -
            SWC_VC_B.lookahead_dist_wp;
        }
      }

      SWC_VC_B.qY = SWC_VC_B.wp_N - /*MW:OvSatOk*/ 2U;
      if (SWC_VC_B.qY > SWC_VC_B.wp_N) {
        SWC_VC_B.qY = 0U;
      }

      WPst = SWC_VC_B.curr_wp_l;
      exitg1 = false;
      while ((!exitg1) && (WPst <= (uint8_T)SWC_VC_B.qY)) {
        SWC_VC_B.c = WPst - 1;
        if (SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] < 0.0F) {
          SWC_VC_B.lookahead_dist_wp = -1.0F;
        } else if (SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] > 0.0F) {
          SWC_VC_B.lookahead_dist_wp = 1.0F;
        } else if (SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] == 0.0F) {
          SWC_VC_B.lookahead_dist_wp = 0.0F;
        } else {
          SWC_VC_B.lookahead_dist_wp = (rtNaNF);
        }

        if (SWC_VC_B.waypoint_segment_dist_data[WPst] < 0.0F) {
          SWC_VC_B.lookahead_long = -1.0F;
        } else if (SWC_VC_B.waypoint_segment_dist_data[WPst] > 0.0F) {
          SWC_VC_B.lookahead_long = 1.0F;
        } else if (SWC_VC_B.waypoint_segment_dist_data[WPst] == 0.0F) {
          SWC_VC_B.lookahead_long = 0.0F;
        } else {
          SWC_VC_B.lookahead_long = (rtNaNF);
        }

        if (SWC_VC_B.lookahead_dist_wp != SWC_VC_B.lookahead_long) {
          WPend = 1U;
          SWC_VC_B.preview_wp = WPst;
          SWC_VC_B.factor_preview = fabsf
            (SWC_VC_B.waypoint_segment_dist_data[SWC_VC_B.c] /
             SWC_VC_B.varargin_1_data[SWC_VC_B.c]);
          exitg1 = true;
        } else {
          WPst++;
        }
      }

      if (WPend == 0) {
        SWC_VC_B.preview_wp = SWC_VC_B.wp_N;
        SWC_VC_B.factor_preview = 0.0F;
      }
    }

    SWC_VC_B.updated_preview_dist = rtCP_Fixed_Lookaheads_Value[sweep_id - 1];

    /* End of MATLAB Function: '<S83>/MATLAB Function' */

    /* Sum: '<S80>/Add' */
    SWC_VC_B.ColDist = (uint8_T)((uint32_T)SWC_VC_B.wp_lastsweeps +
      SWC_VC_B.curr_wp_l);

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    SWC_VC_B.Current_waypoint = SWC_VC_B.ColDist;

    /* DataTypeConversion: '<S80>/Cast To Single' */
    SWC_VC_B.Delay1 = SWC_VC_B.curr_wp_l;

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    SWC_VC_B.curr_wp = SWC_VC_B.Delay1;

    /* MultiPortSwitch: '<S94>/Index WP' incorporates:
     *  MultiPortSwitch: '<S105>/Index WP'
     *  MultiPortSwitch: '<S90>/Index WP'
     */
    SWC_VC_B.i_j = SWC_VC_B.curr_wp_l - 1;
    SWC_VC_B.IndexWP = SWC_VC_B.yaw[SWC_VC_B.i_j];

    /* RelationalOperator: '<S96>/Compare' incorporates:
     *  Constant: '<S96>/Constant'
     */
    SWC_VC_B.Compare_o = (SWC_VC_B.curr_factor > 0.0F);

    /* Outputs for Enabled SubSystem: '<S94>/Index WPplus1' incorporates:
     *  EnablePort: '<S97>/Enable'
     */
    if (SWC_VC_B.Compare_o) {
      /* Sum: '<S97>/Add5' incorporates:
       *  Constant: '<S97>/Constant1'
       */
      SWC_VC_B.wp_plus_1_g = (real_T)SWC_VC_B.curr_wp_l + 1.0;

      /* MultiPortSwitch: '<S97>/Index WPp1' */
      SWC_VC_B.Delay1 = SWC_VC_B.yaw[(int32_T)SWC_VC_B.wp_plus_1_g - 1];

      /* Sum: '<S97>/Add6' */
      SWC_VC_B.Delay1 -= SWC_VC_B.IndexWP;

      /* Product: '<S97>/Multiply1' */
      SWC_VC_B.Multiply1_m = SWC_VC_B.Delay1 * SWC_VC_B.curr_factor;
    }

    /* End of Outputs for SubSystem: '<S94>/Index WPplus1' */

    /* Sum: '<S94>/Add1' */
    SWC_VC_B.Delay1 = SWC_VC_B.IndexWP + SWC_VC_B.Multiply1_m;

    /* Sum: '<S88>/Add4' */
    SWC_VC_B.Add4 = SWC_VC_B.Delay1 - heading_MABx;

    /* RelationalOperator: '<S98>/Compare' incorporates:
     *  Constant: '<S98>/Constant'
     */
    SWC_VC_B.Compare_lw = (SWC_VC_B.Add4 >= (-180.0F));

    /* Switch: '<S95>/Switch1' */
    if (SWC_VC_B.Compare_lw) {
      /* RelationalOperator: '<S99>/Compare' incorporates:
       *  Constant: '<S99>/Constant'
       */
      SWC_VC_B.Compare_o1 = (SWC_VC_B.Add4 > 180.0F);

      /* Switch: '<S95>/Switch' */
      if (SWC_VC_B.Compare_o1) {
        /* Sum: '<S95>/Add1' incorporates:
         *  Constant: '<S95>/Constant'
         */
        SWC_VC_B.Add1_m = SWC_VC_B.Add4 - (real32_T)((uint16_T)360U);
        SWC_VC_B.Switch_k = SWC_VC_B.Add1_m;
      } else {
        SWC_VC_B.Switch_k = SWC_VC_B.Add4;
      }

      /* End of Switch: '<S95>/Switch' */
      SWC_VC_B.Delay1 = SWC_VC_B.Switch_k;
    } else {
      /* Sum: '<S95>/Add2' incorporates:
       *  Constant: '<S95>/Constant1'
       */
      SWC_VC_B.Add2_g = SWC_VC_B.Add4 + (real32_T)((uint16_T)360U);
      SWC_VC_B.Delay1 = SWC_VC_B.Add2_g;
    }

    /* End of Switch: '<S95>/Switch1' */

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    VC_Head_Dev = SWC_VC_B.Delay1;

    /* MultiPortSwitch: '<S90>/Index WP' */
    SWC_VC_B.IndexWP_c = SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j];

    /* RelationalOperator: '<S103>/Compare' incorporates:
     *  Constant: '<S103>/Constant'
     */
    SWC_VC_B.Compare_nm = (SWC_VC_B.curr_factor > 0.0F);

    /* Outputs for Enabled SubSystem: '<S90>/Index WPplus1' incorporates:
     *  EnablePort: '<S104>/Enable'
     */
    if (SWC_VC_B.Compare_nm) {
      /* Sum: '<S104>/Add5' incorporates:
       *  Constant: '<S104>/Constant1'
       */
      SWC_VC_B.wp_plus_1 = (real_T)SWC_VC_B.curr_wp_l + 1.0;

      /* MultiPortSwitch: '<S104>/Index WPp1' */
      SWC_VC_B.Delay1 = SWC_VC_B.Dist2Path_lat[(int32_T)SWC_VC_B.wp_plus_1 - 1];

      /* Sum: '<S104>/Add6' */
      SWC_VC_B.Delay1 -= SWC_VC_B.IndexWP_c;

      /* Product: '<S104>/Multiply1' */
      SWC_VC_B.Multiply1_l = SWC_VC_B.Delay1 * SWC_VC_B.curr_factor;
    }

    /* End of Outputs for SubSystem: '<S90>/Index WPplus1' */

    /* Sum: '<S90>/Add1' */
    SWC_VC_B.Delay1 = SWC_VC_B.IndexWP_c + SWC_VC_B.Multiply1_l;

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    VC_PathDev = SWC_VC_B.Delay1;

    /* MultiPortSwitch: '<S105>/Index WP' */
    SWC_VC_B.IndexWP_n = SWC_VC_B.speed_d[SWC_VC_B.i_j];

    /* RelationalOperator: '<S106>/Compare' incorporates:
     *  Constant: '<S106>/Constant'
     */
    SWC_VC_B.Compare_f = (SWC_VC_B.curr_factor > 0.0F);

    /* Outputs for Enabled SubSystem: '<S105>/Index WPplus1' incorporates:
     *  EnablePort: '<S107>/Enable'
     */
    if (SWC_VC_B.Compare_f) {
      /* Sum: '<S107>/Add5' incorporates:
       *  Constant: '<S107>/Constant1'
       */
      SWC_VC_B.wp_plus_1_o = (real32_T)SWC_VC_B.curr_wp_l + 1.0F;

      /* MultiPortSwitch: '<S107>/Index WPp1' */
      SWC_VC_B.Delay1 = SWC_VC_B.speed_d[(int32_T)SWC_VC_B.wp_plus_1_o - 1];

      /* Sum: '<S107>/Add6' */
      SWC_VC_B.Delay1 -= SWC_VC_B.IndexWP_n;

      /* Product: '<S107>/Multiply1' */
      SWC_VC_B.Multiply1 = SWC_VC_B.Delay1 * SWC_VC_B.curr_factor;
    }

    /* End of Outputs for SubSystem: '<S105>/Index WPplus1' */

    /* Sum: '<S105>/Add1' */
    SWC_VC_B.Delay1 = SWC_VC_B.IndexWP_n + SWC_VC_B.Multiply1;

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    SWC_VC_B.MaxSpeed = SWC_VC_B.Delay1;

    /* MultiPortSwitch: '<S89>/Index WP' */
    SWC_VC_B.Delay1 = SWC_VC_B.yaw[SWC_VC_B.O_WPSweepN_tmp];

    /* Sum: '<S89>/Add4' */
    SWC_VC_B.Add4_h = SWC_VC_B.Delay1 - heading_MABx;

    /* RelationalOperator: '<S101>/Compare' incorporates:
     *  Constant: '<S101>/Constant'
     */
    SWC_VC_B.Compare_lw = (SWC_VC_B.Add4_h >= (-180.0F));

    /* Switch: '<S100>/Switch1' */
    if (SWC_VC_B.Compare_lw) {
      /* RelationalOperator: '<S102>/Compare' incorporates:
       *  Constant: '<S102>/Constant'
       */
      SWC_VC_B.Compare_m = (SWC_VC_B.Add4_h > 180.0F);

      /* Switch: '<S100>/Switch' */
      if (SWC_VC_B.Compare_m) {
        /* Sum: '<S100>/Add1' incorporates:
         *  Constant: '<S100>/Constant'
         */
        SWC_VC_B.Add1 = SWC_VC_B.Add4_h - (real32_T)((uint16_T)360U);
        SWC_VC_B.Switch_p = SWC_VC_B.Add1;
      } else {
        SWC_VC_B.Switch_p = SWC_VC_B.Add4_h;
      }

      /* End of Switch: '<S100>/Switch' */
      SWC_VC_B.Switch1_c = SWC_VC_B.Switch_p;
    } else {
      /* Sum: '<S100>/Add2' incorporates:
       *  Constant: '<S100>/Constant1'
       */
      SWC_VC_B.Add2 = SWC_VC_B.Add4_h + (real32_T)((uint16_T)360U);
      SWC_VC_B.Switch1_c = SWC_VC_B.Add2;
    }

    /* End of Switch: '<S100>/Switch1' */

    /* Delay: '<S84>/Delay One Step' */
    SWC_VC_B.Delay1 = SWC_VC_DW.DelayOneStep_DSTATE;

    /* DataTypeConversion: '<S84>/Cast To Single' */
    SWC_VC_B.CastToSingle_f = SWC_VC_B.Delay1;

    /* MultiPortSwitch: '<S93>/Multiport Switch' incorporates:
     *  Constant: '<S93>/Constant'
     *  Constant: '<S93>/Constant1'
     *  Constant: '<S93>/Constant2'
     */
    switch (rtu_MbNVM_ProxyParam->KeAP_e_WhlBas) {
     case TeAP_e_WhlBas_Type_1:
      SWC_VC_B.MultiportSwitch = 3.5687F;
      break;

     case TeAP_e_WhlBas_Type_2:
      SWC_VC_B.MultiportSwitch = 3.6703F;
      break;

     default:
      SWC_VC_B.MultiportSwitch = 3.8989F;
      break;
    }

    /* End of MultiPortSwitch: '<S93>/Multiport Switch' */

    /* DataTypeConversion: '<S83>/Data Type Conversion2' */
    SWC_VC_B.remainingdistance = SWC_VC_B.remain_dist;

    /* MATLAB Function: '<S84>/MATLAB Function' */
    SWC_VC_B.steering_tire_angle_deg = 0.0F;
    if (SWC_VC_B.preview_wp == SWC_VC_B.wp_N) {
      SWC_VC_B.virtual_point_length_m = fmaxf(0.1F, (real32_T)
        SWC_VC_B.updated_preview_dist - SWC_VC_B.remainingdistance);
      if (rtIsInfF(SWC_VC_B.Switch1_c) || rtIsNaNF(SWC_VC_B.Switch1_c)) {
        SWC_VC_B.lookahead_long = (rtNaNF);
        SWC_VC_B.lookahead_dist_wp = (rtNaNF);
      } else {
        SWC_VC_B.lookahead_dist_wp = rt_remf_snf(SWC_VC_B.Switch1_c, 360.0F);
        SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp;
        SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
        if (SWC_VC_B.absx > 180.0F) {
          if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
            SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp - 360.0F;
          } else {
            SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp + 360.0F;
          }

          SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_long);
        }

        if (SWC_VC_B.absx <= 45.0F) {
          SWC_VC_B.lookahead_long *= 0.0174532924F;
          n = 0;
        } else if (SWC_VC_B.absx <= 135.0F) {
          if (SWC_VC_B.lookahead_long > 0.0F) {
            SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 90.0F) *
              0.0174532924F;
            n = 1;
          } else {
            SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 90.0F) *
              0.0174532924F;
            n = -1;
          }
        } else if (SWC_VC_B.lookahead_long > 0.0F) {
          SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 180.0F) *
            0.0174532924F;
          n = 2;
        } else {
          SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 180.0F) *
            0.0174532924F;
          n = -2;
        }

        switch (n) {
         case 0:
          SWC_VC_B.lookahead_long = cosf(SWC_VC_B.lookahead_long);
          break;

         case 1:
          SWC_VC_B.lookahead_long = -sinf(SWC_VC_B.lookahead_long);
          break;

         case -1:
          SWC_VC_B.lookahead_long = sinf(SWC_VC_B.lookahead_long);
          break;

         default:
          SWC_VC_B.lookahead_long = -cosf(SWC_VC_B.lookahead_long);
          break;
        }

        SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
        if (SWC_VC_B.absx > 180.0F) {
          if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
            SWC_VC_B.lookahead_dist_wp -= 360.0F;
          } else {
            SWC_VC_B.lookahead_dist_wp += 360.0F;
          }

          SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
        }

        if (SWC_VC_B.absx <= 45.0F) {
          SWC_VC_B.lookahead_dist_wp *= 0.0174532924F;
          n = 0;
        } else if (SWC_VC_B.absx <= 135.0F) {
          if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
            SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp - 90.0F) *
              0.0174532924F;
            n = 1;
          } else {
            SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp + 90.0F) *
              0.0174532924F;
            n = -1;
          }
        } else if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
          SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp - 180.0F) *
            0.0174532924F;
          n = 2;
        } else {
          SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp + 180.0F) *
            0.0174532924F;
          n = -2;
        }

        switch (n) {
         case 0:
          SWC_VC_B.lookahead_dist_wp = sinf(SWC_VC_B.lookahead_dist_wp);
          break;

         case 1:
          SWC_VC_B.lookahead_dist_wp = cosf(SWC_VC_B.lookahead_dist_wp);
          break;

         case -1:
          SWC_VC_B.lookahead_dist_wp = -cosf(SWC_VC_B.lookahead_dist_wp);
          break;

         default:
          SWC_VC_B.lookahead_dist_wp = -sinf(SWC_VC_B.lookahead_dist_wp);
          break;
        }
      }

      SWC_VC_B.O_WPSweepN_tmp = SWC_VC_B.preview_wp - 1;
      SWC_VC_B.lookahead_long = (real32_T)SWC_VC_B.Dir * SWC_VC_B.lookahead_long
        * SWC_VC_B.virtual_point_length_m +
        SWC_VC_B.Dist2Path_long[SWC_VC_B.O_WPSweepN_tmp];
      SWC_VC_B.absx = (real32_T)SWC_VC_B.Dir * SWC_VC_B.lookahead_dist_wp *
        SWC_VC_B.virtual_point_length_m +
        SWC_VC_B.Dist2Path_lat[SWC_VC_B.O_WPSweepN_tmp];
      SWC_VC_B.lookahead_dist_wp = sqrtf(SWC_VC_B.lookahead_long
        * SWC_VC_B.lookahead_long + SWC_VC_B.absx * SWC_VC_B.absx);
    } else {
      SWC_VC_B.O_WPSweepN_tmp = SWC_VC_B.preview_wp - 1;
      SWC_VC_B.lookahead_dist_wp = sqrtf
        (SWC_VC_B.Dist2Path_long[SWC_VC_B.O_WPSweepN_tmp] *
         SWC_VC_B.Dist2Path_long[SWC_VC_B.O_WPSweepN_tmp] +
         SWC_VC_B.Dist2Path_lat[SWC_VC_B.O_WPSweepN_tmp] *
         SWC_VC_B.Dist2Path_lat[SWC_VC_B.O_WPSweepN_tmp]);
      SWC_VC_B.i_j = (int32_T)(SWC_VC_B.preview_wp + 1U);
      SWC_VC_B.c = SWC_VC_B.i_j;
      if ((uint32_T)SWC_VC_B.i_j > 255U) {
        SWC_VC_B.c = 255;
      }

      SWC_VC_B.lookahead_long = SWC_VC_B.Dist2Path_long[SWC_VC_B.c - 1];
      SWC_VC_B.c = SWC_VC_B.i_j;
      if ((uint32_T)SWC_VC_B.i_j > 255U) {
        SWC_VC_B.c = 255;
        SWC_VC_B.i_j = 255;
      }

      SWC_VC_B.absx = SWC_VC_B.Dist2Path_lat[SWC_VC_B.c - 1];
      SWC_VC_B.lookahead_dist_wp += (sqrtf(SWC_VC_B.lookahead_long
        * SWC_VC_B.lookahead_long + SWC_VC_B.absx * SWC_VC_B.absx) -
        SWC_VC_B.lookahead_dist_wp) * SWC_VC_B.factor_preview;
      SWC_VC_B.absx = (SWC_VC_B.Dist2Path_lat[SWC_VC_B.i_j - 1] -
                       SWC_VC_B.Dist2Path_lat[SWC_VC_B.O_WPSweepN_tmp]) *
        SWC_VC_B.factor_preview + SWC_VC_B.Dist2Path_lat[SWC_VC_B.O_WPSweepN_tmp];
    }

    if (SWC_VC_B.lookahead_dist_wp > 0.001) {
      SWC_VC_B.steering_tire_angle_deg = atanf(2.0F * SWC_VC_B.absx /
        (SWC_VC_B.lookahead_dist_wp * SWC_VC_B.lookahead_dist_wp) *
        SWC_VC_B.MultiportSwitch) * 57.2957802F;
    }

    if (SWC_VC_B.remainingdistance <= 0.5F) {
      SWC_VC_B.steering_tire_angle_deg = 0.8F * SWC_VC_B.CastToSingle_f + 0.2F *
        SWC_VC_B.steering_tire_angle_deg;
    }

    SWC_VC_B.lookahead_lat = SWC_VC_B.absx;
    SWC_VC_B.lookahead_dist = SWC_VC_B.lookahead_dist_wp;

    /* End of MATLAB Function: '<S84>/MATLAB Function' */

    /* Signum: '<S84>/Sign' */
    if (SWC_VC_B.steering_tire_angle_deg < 0.0F) {
      SWC_VC_B.Delay1 = -1.0F;
    } else if (SWC_VC_B.steering_tire_angle_deg > 0.0F) {
      SWC_VC_B.Delay1 = 1.0F;
    } else if (SWC_VC_B.steering_tire_angle_deg == 0.0F) {
      SWC_VC_B.Delay1 = 0.0F;
    } else {
      SWC_VC_B.Delay1 = (rtNaNF);
    }

    /* End of Signum: '<S84>/Sign' */

    /* Abs: '<S84>/Abs' */
    SWC_VC_B.Abs_c = fabsf(SWC_VC_B.steering_tire_angle_deg);

    /* Lookup_n-D: '<S92>/steering_XXc.mat2' */
    SWC_VC_B.steering_XXcmat2_l = look1_iflf_binlxpw(SWC_VC_B.Abs_c,
      rtCP_steering_XXcmat2_bp01Data, rtCP_steering_XXcmat2_tableData, 8U);

    /* MultiPortSwitch: '<S92>/Multiport Switch' */
    switch (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp) {
     case TeAP_e_SteerRatRackPinionTyp_Type_1:
      /* Lookup_n-D: '<S92>/steering_XXc.mat' */
      SWC_VC_B.steering_XXcmat = look1_iflf_binlxpw(SWC_VC_B.Abs_c,
        rtCP_steering_XXcmat_bp01Data_n, rtCP_steering_XXcmat_tableData_p, 8U);
      SWC_VC_B.Product3_o = SWC_VC_B.steering_XXcmat;
      break;

     case TeAP_e_SteerRatRackPinionTyp_Type_2:
      /* Lookup_n-D: '<S92>/steering_XXc.mat1' */
      SWC_VC_B.steering_XXcmat1 = look1_iflf_binlxpw(SWC_VC_B.Abs_c,
        rtCP_steering_XXcmat1_bp01Data_l, rtCP_steering_XXcmat1_tableData_g, 8U);
      SWC_VC_B.Product3_o = SWC_VC_B.steering_XXcmat1;
      break;

     default:
      SWC_VC_B.Product3_o = SWC_VC_B.steering_XXcmat2_l;
      break;
    }

    /* End of MultiPortSwitch: '<S92>/Multiport Switch' */

    /* Product: '<S84>/Product3' */
    SWC_VC_B.Product3_o *= SWC_VC_B.Delay1;

    /* Saturate: '<S84>/Steer_CMDSat' */
    if (SWC_VC_B.Product3_o > 570.0F) {
      SWC_VC_B.Product3_o = 570.0F;
    } else {
      if (SWC_VC_B.Product3_o < (-570.0F)) {
        SWC_VC_B.Product3_o = (-570.0F);
      }
    }

    /* End of Saturate: '<S84>/Steer_CMDSat' */

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    VC_Steer_CMD = SWC_VC_B.Product3_o;

    /* SignalConversion generated from: '<S80>/Signal Conversion' */
    SWC_VC_B.remainingdistance_d = SWC_VC_B.remainingdistance;

    /* Update for Delay: '<S84>/Delay One Step' */
    SWC_VC_DW.DelayOneStep_DSTATE = SWC_VC_B.steering_tire_angle_deg;
  } else {
    SWC_VC_DW.Control_MODE = false;
  }

  /* End of Outputs for SubSystem: '<S21>/Control' */
  /* RateTransition: '<S1>/Rate Transition15' */
  SWC_VC_B.RateTransition15 = *rtu_MeAP_I_GearRpt;

  /* MATLAB Function: '<S12>/MATLAB Function' */
  switch (SWC_VC_B.RateTransition15) {
   case 14:
    SWC_VC_B.direction = -1.0F;
    break;

   case 13:
    SWC_VC_B.direction = 0.0F;
    break;

   default:
    SWC_VC_B.direction = 1.0F;
    break;
  }

  /* End of MATLAB Function: '<S12>/MATLAB Function' */

  /* RateTransition: '<S1>/Rate Transition21' */
  SWC_VC_B.RateTransition21 = rtu_MbNVM_ProxyParam->KeAP_mm_TyreSz;

  /* Gain: '<S12>/Gain' */
  MeAP_m_WhlCircum = (real32_T)((uint16_T)33554U) * 2.98023224E-8F * (real32_T)
    SWC_VC_B.RateTransition21;

  /* RateTransition: '<S1>/Rate Transition13' incorporates:
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRR'
   */
  SWC_VC_B.RateTransition13 = DS_WheelSpeed_RR;

  /* RateTransition: '<S1>/Rate Transition17' incorporates:
   *  Inport: '<Root>/MeAP_radPsec_WhlRotSpdRL'
   */
  SWC_VC_B.RateTransition17 = DS_WheelSpeed_RL;

  /* MATLAB Function: '<S12>/Rear axle speed conversion ' */
  SWC_VC_B.speed_Rear_axle_mps = (SWC_VC_B.RateTransition13 +
    SWC_VC_B.RateTransition17) / 2.0F / 3.6F;

  /* RateTransition: '<S1>/Rate Transition18' */
  SWC_VC_B.RateTransition18 = *rtu_MeAP_I_WhlPosRR;

  /* RateTransition: '<S1>/Rate Transition12' */
  SWC_VC_B.RateTransition12 = *rtu_MeAP_I_WhlPosRL;

  /* Delay: '<S12>/Delay1' */
  if (SWC_VC_DW.icLoad != 0) {
    SWC_VC_DW.Delay1_DSTATE_n = SWC_VC_B.RateTransition18;
  }

  SWC_VC_B.Delay1_f = SWC_VC_DW.Delay1_DSTATE_n;

  /* End of Delay: '<S12>/Delay1' */

  /* Delay: '<S12>/Delay2' */
  if (SWC_VC_DW.icLoad_l != 0) {
    SWC_VC_DW.Delay2_DSTATE = SWC_VC_B.RateTransition12;
  }

  SWC_VC_B.Delay2 = SWC_VC_DW.Delay2_DSTATE;

  /* End of Delay: '<S12>/Delay2' */

  /* RateTransition: '<S1>/Rate Transition16' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  SWC_VC_B.RateTransition16 = DS_ANGLE;

  /* RateTransition: '<S1>/Rate Transition20' */
  SWC_VC_B.RateTransition20 = rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp;

  /* Abs: '<S12>/Abs' */
  SWC_VC_B.Abs_g = fabsf(SWC_VC_B.RateTransition16);

  /* Lookup_n-D: '<S51>/steering_XXc.mat2' */
  SWC_VC_B.steering_XXcmat2_o = look1_iflf_binlxpw(SWC_VC_B.Abs_g,
    rtCP_steering_XXcmat2_bp01Data_m, rtCP_steering_XXcmat2_tableData_f, 8U);

  /* MultiPortSwitch: '<S51>/Multiport Switch' */
  switch (SWC_VC_B.RateTransition20) {
   case TeAP_e_SteerRatRackPinionTyp_Type_1:
    /* Lookup_n-D: '<S51>/steering_XXc.mat' */
    SWC_VC_B.steering_XXcmat_l = look1_iflf_binlxpw(SWC_VC_B.Abs_g,
      rtCP_steering_XXcmat_bp01Data, rtCP_steering_XXcmat_tableData, 8U);
    MeAP_deg_strAngtoWhlAng = SWC_VC_B.steering_XXcmat_l;
    break;

   case TeAP_e_SteerRatRackPinionTyp_Type_2:
    /* Lookup_n-D: '<S51>/steering_XXc.mat1' */
    SWC_VC_B.steering_XXcmat1_e = look1_iflf_binlxpw(SWC_VC_B.Abs_g,
      rtCP_steering_XXcmat1_bp01Data, rtCP_steering_XXcmat1_tableData, 8U);
    MeAP_deg_strAngtoWhlAng = SWC_VC_B.steering_XXcmat1_e;
    break;

   default:
    MeAP_deg_strAngtoWhlAng = SWC_VC_B.steering_XXcmat2_o;
    break;
  }

  /* End of MultiPortSwitch: '<S51>/Multiport Switch' */

  /* Switch: '<S12>/Switch' incorporates:
   *  Constant: '<S12>/linearAssumption'
   *  Signum: '<S12>/Sign'
   */
  if (0.0F > 0.0F) {
    /* Gain: '<S12>/linear_gain' */
    SWC_VC_B.whl_angl_a = 0.0660066F * SWC_VC_B.RateTransition16;
    SWC_VC_B.whl_angl_d = SWC_VC_B.whl_angl_a;
  } else {
    if (SWC_VC_B.RateTransition16 < 0.0F) {
      /* Signum: '<S12>/Sign' */
      SWC_VC_B.Sign = -1.0F;
    } else if (SWC_VC_B.RateTransition16 > 0.0F) {
      /* Signum: '<S12>/Sign' */
      SWC_VC_B.Sign = 1.0F;
    } else if (SWC_VC_B.RateTransition16 == 0.0F) {
      /* Signum: '<S12>/Sign' */
      SWC_VC_B.Sign = 0.0F;
    } else {
      /* Signum: '<S12>/Sign' */
      SWC_VC_B.Sign = (rtNaNF);
    }

    /* Product: '<S12>/Product' incorporates:
     *  Signum: '<S12>/Sign'
     */
    SWC_VC_B.Product_g = MeAP_deg_strAngtoWhlAng * SWC_VC_B.Sign;
    SWC_VC_B.whl_angl_d = SWC_VC_B.Product_g;
  }

  /* End of Switch: '<S12>/Switch' */

  /* RateTransition: '<S1>/Rate Transition19' */
  SWC_VC_B.RateTransition19 = rtu_MbNVM_ProxyParam->KeAP_e_WhlBas;

  /* MultiPortSwitch: '<S52>/Multiport Switch' incorporates:
   *  Constant: '<S52>/Constant'
   *  Constant: '<S52>/Constant1'
   *  Constant: '<S52>/Constant2'
   */
  switch (SWC_VC_B.RateTransition19) {
   case TeAP_e_WhlBas_Type_1:
    MeAP_m_WhlBase = 3.5687F;
    break;

   case TeAP_e_WhlBas_Type_2:
    MeAP_m_WhlBase = 3.6703F;
    break;

   default:
    MeAP_m_WhlBase = 3.8989F;
    break;
  }

  /* End of MultiPortSwitch: '<S52>/Multiport Switch' */

  /* MATLAB Function: '<S12>/MATLAB Function2' */
  SWC_VC_B.lookahead_dist_wp = 0.0F;
  SWC_VC_B.lookahead_long = 0.0F;
  if (SWC_VC_B.speed_Rear_axle_mps > 0.5F) {
    SWC_VC_B.ds_Rear_axle_m = SWC_VC_B.speed_Rear_axle_mps;
  } else {
    if (SWC_VC_B.RateTransition18 >= SWC_VC_B.Delay1_f) {
      SWC_VC_B.lookahead_dist_wp = (real32_T)(SWC_VC_B.RateTransition18 -
        SWC_VC_B.Delay1_f);
    } else {
      if (SWC_VC_B.RateTransition18 < SWC_VC_B.Delay1_f) {
        SWC_VC_B.lookahead_dist_wp = (real32_T)((SWC_VC_B.RateTransition18 -
          SWC_VC_B.Delay1_f) + 254);
      }
    }

    if (SWC_VC_B.RateTransition12 >= SWC_VC_B.Delay2) {
      SWC_VC_B.lookahead_long = (real32_T)(SWC_VC_B.RateTransition12 -
        SWC_VC_B.Delay2);
    } else {
      if (SWC_VC_B.RateTransition12 < SWC_VC_B.Delay2) {
        SWC_VC_B.lookahead_long = (real32_T)((SWC_VC_B.RateTransition12 -
          SWC_VC_B.Delay2) + 254);
      }
    }

    SWC_VC_B.ds_Rear_axle_m = (SWC_VC_B.lookahead_dist_wp +
      SWC_VC_B.lookahead_long) / 2.0F * 0.0262F / 0.03F;
  }

  if (rtIsInfF(SWC_VC_B.whl_angl_d) || rtIsNaNF(SWC_VC_B.whl_angl_d)) {
    SWC_VC_B.lookahead_long = (rtNaNF);
  } else {
    SWC_VC_B.lookahead_long = rt_remf_snf(SWC_VC_B.whl_angl_d, 360.0F);
    SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_long);
    if (SWC_VC_B.absx > 180.0F) {
      if (SWC_VC_B.lookahead_long > 0.0F) {
        SWC_VC_B.lookahead_long -= 360.0F;
      } else {
        SWC_VC_B.lookahead_long += 360.0F;
      }

      SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_long);
    }

    if (SWC_VC_B.absx <= 45.0F) {
      SWC_VC_B.lookahead_long *= 0.0174532924F;
      n = 0;
    } else if (SWC_VC_B.absx <= 135.0F) {
      if (SWC_VC_B.lookahead_long > 0.0F) {
        SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 90.0F) *
          0.0174532924F;
        n = 1;
      } else {
        SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 90.0F) *
          0.0174532924F;
        n = -1;
      }
    } else if (SWC_VC_B.lookahead_long > 0.0F) {
      SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 180.0F) *
        0.0174532924F;
      n = 2;
    } else {
      SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 180.0F) *
        0.0174532924F;
      n = -2;
    }

    SWC_VC_B.lookahead_long = tanf(SWC_VC_B.lookahead_long);
    if ((n == 1) || (n == -1)) {
      SWC_VC_B.lookahead_dist_wp = 1.0F / SWC_VC_B.lookahead_long;
      SWC_VC_B.lookahead_long = -(1.0F / SWC_VC_B.lookahead_long);
      if (rtIsInfF(SWC_VC_B.lookahead_long) && (n == 1)) {
        SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp;
      }
    }
  }

  SWC_VC_B.d_heading_deg = SWC_VC_B.ds_Rear_axle_m * SWC_VC_B.lookahead_long /
    MeAP_m_WhlBase * 57.2957802F * SWC_VC_B.direction;

  /* End of MATLAB Function: '<S12>/MATLAB Function2' */

  /* MATLAB Function: '<S12>/MATLAB Function3' */
  if (rtIsInfF(SWC_VC_B.heading_MABx_h) || rtIsNaNF(SWC_VC_B.heading_MABx_h)) {
    SWC_VC_B.lookahead_long = (rtNaNF);
    SWC_VC_B.lookahead_dist_wp = (rtNaNF);
  } else {
    SWC_VC_B.lookahead_dist_wp = rt_remf_snf(SWC_VC_B.heading_MABx_h, 360.0F);
    SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp;
    SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
    if (SWC_VC_B.absx > 180.0F) {
      if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
        SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp - 360.0F;
      } else {
        SWC_VC_B.lookahead_long = SWC_VC_B.lookahead_dist_wp + 360.0F;
      }

      SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_long);
    }

    if (SWC_VC_B.absx <= 45.0F) {
      SWC_VC_B.lookahead_long *= 0.0174532924F;
      n = 0;
    } else if (SWC_VC_B.absx <= 135.0F) {
      if (SWC_VC_B.lookahead_long > 0.0F) {
        SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 90.0F) *
          0.0174532924F;
        n = 1;
      } else {
        SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 90.0F) *
          0.0174532924F;
        n = -1;
      }
    } else if (SWC_VC_B.lookahead_long > 0.0F) {
      SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long - 180.0F) *
        0.0174532924F;
      n = 2;
    } else {
      SWC_VC_B.lookahead_long = (SWC_VC_B.lookahead_long + 180.0F) *
        0.0174532924F;
      n = -2;
    }

    switch (n) {
     case 0:
      SWC_VC_B.lookahead_long = cosf(SWC_VC_B.lookahead_long);
      break;

     case 1:
      SWC_VC_B.lookahead_long = -sinf(SWC_VC_B.lookahead_long);
      break;

     case -1:
      SWC_VC_B.lookahead_long = sinf(SWC_VC_B.lookahead_long);
      break;

     default:
      SWC_VC_B.lookahead_long = -cosf(SWC_VC_B.lookahead_long);
      break;
    }

    SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
    if (SWC_VC_B.absx > 180.0F) {
      if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
        SWC_VC_B.lookahead_dist_wp -= 360.0F;
      } else {
        SWC_VC_B.lookahead_dist_wp += 360.0F;
      }

      SWC_VC_B.absx = fabsf(SWC_VC_B.lookahead_dist_wp);
    }

    if (SWC_VC_B.absx <= 45.0F) {
      SWC_VC_B.lookahead_dist_wp *= 0.0174532924F;
      n = 0;
    } else if (SWC_VC_B.absx <= 135.0F) {
      if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
        SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp - 90.0F) *
          0.0174532924F;
        n = 1;
      } else {
        SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp + 90.0F) *
          0.0174532924F;
        n = -1;
      }
    } else if (SWC_VC_B.lookahead_dist_wp > 0.0F) {
      SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp - 180.0F) *
        0.0174532924F;
      n = 2;
    } else {
      SWC_VC_B.lookahead_dist_wp = (SWC_VC_B.lookahead_dist_wp + 180.0F) *
        0.0174532924F;
      n = -2;
    }

    switch (n) {
     case 0:
      SWC_VC_B.lookahead_dist_wp = sinf(SWC_VC_B.lookahead_dist_wp);
      break;

     case 1:
      SWC_VC_B.lookahead_dist_wp = cosf(SWC_VC_B.lookahead_dist_wp);
      break;

     case -1:
      SWC_VC_B.lookahead_dist_wp = -cosf(SWC_VC_B.lookahead_dist_wp);
      break;

     default:
      SWC_VC_B.lookahead_dist_wp = -sinf(SWC_VC_B.lookahead_dist_wp);
      break;
    }
  }

  SWC_VC_B.dx_dy_m[0] = -SWC_VC_B.lookahead_long * SWC_VC_B.ds_Rear_axle_m *
    SWC_VC_B.direction;
  SWC_VC_B.dx_dy_m[1] = -SWC_VC_B.lookahead_dist_wp * SWC_VC_B.ds_Rear_axle_m *
    SWC_VC_B.direction;

  /* End of MATLAB Function: '<S12>/MATLAB Function3' */

  /* Gain: '<S12>/Multiply' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = 3.6F * SWC_VC_B.ds_Rear_axle_m;

  /* Product: '<S22>/Product1' */
  SWC_VC_B.DataTypeConversion = SWC_VC_B.DiscreteTimeIntegrator_ll *
    SWC_VC_ConstB.alpha;

  /* UnitDelay: '<S22>/Unit Delay' */
  SWC_VC_B.Product_a = SWC_VC_B.Sum;

  /* Product: '<S22>/Product' */
  SWC_VC_B.Product_a *= SWC_VC_ConstB.one_minus_alpha;

  /* Sum: '<S22>/Sum' */
  SWC_VC_B.Sum = SWC_VC_B.DataTypeConversion + SWC_VC_B.Product_a;

  /* DataTypeConversion: '<S1>/Data Type Conversion11' */
  SWC_VC_B.speed_kph_MABx = (real32_T)SWC_VC_B.Sum;

  /* MultiPortSwitch: '<S20>/Multiport Switch' incorporates:
   *  Constant: '<S20>/Constant'
   *  Constant: '<S20>/Constant1'
   *  Constant: '<S20>/Constant2'
   *  Constant: '<S20>/Constant3'
   *  Constant: '<S20>/Constant4'
   *  Constant: '<S20>/Constant5'
   */
  switch (*rtu_MeAP_I_GearRpt) {
   case 0:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)0U);
    break;

   case 1:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 2:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 3:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 4:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 5:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 6:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 7:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 8:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 9:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)4U);
    break;

   case 10:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)0U);
    break;

   case 11:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)0U);
    break;

   case 12:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)0U);
    break;

   case 13:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)1U);
    break;

   case 14:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)2U);
    break;

   default:
    SWC_VC_B.MeAP_I_GearRpt = ((uint8_T)0U);
    break;
  }

  /* End of MultiPortSwitch: '<S20>/Multiport Switch' */

  /* RateTransition: '<S1>/Rate Transition8' */
  SWC_VC_B.RateTransition8 = SWC_VC_B.MeAP_I_GearRpt;

  /* DataTypeConversion: '<S5>/Data Type Conversion2' */
  SWC_VC_B.DataTypeConversion2_d = SWC_VC_B.RateTransition8;

  /* MultiPortSwitch: '<S5>/Multiport Switch' incorporates:
   *  Constant: '<S5>/default_dist'
   */
  switch ((int32_T)SWC_VC_B.DataTypeConversion2_d) {
   case 4:
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 14; SWC_VC_B.i_j++) {
      /* RelationalOperator: '<S37>/Compare' incorporates:
       *  Constant: '<S37>/Constant'
       */
      SWC_VC_B.Compare_k[SWC_VC_B.i_j] = (SWC_VC_B.y_a[SWC_VC_B.i_j] == 0.0);

      /* Product: '<S35>/Product' incorporates:
       *  Constant: '<S35>/Constant'
       */
      SWC_VC_B.Product_k[SWC_VC_B.i_j] = 255.0 * (real_T)
        SWC_VC_B.Compare_k[SWC_VC_B.i_j];

      /* Sum: '<S35>/Add' */
      SWC_VC_B.Add[SWC_VC_B.i_j] = SWC_VC_B.Product_k[SWC_VC_B.i_j] +
        SWC_VC_B.y_a[SWC_VC_B.i_j];
    }

    /* MinMax: '<S35>/MinMax1' */
    SWC_VC_B.minV = SWC_VC_B.Add[0];
    for (SWC_VC_B.O_WPSweepN_tmp = 0; SWC_VC_B.O_WPSweepN_tmp < 13;
         SWC_VC_B.O_WPSweepN_tmp++) {
      SWC_VC_B.minV = fmin(SWC_VC_B.minV, SWC_VC_B.Add[SWC_VC_B.O_WPSweepN_tmp +
                           1]);
    }

    SWC_VC_B.MinMax1_e = (real32_T)SWC_VC_B.minV;

    /* End of MinMax: '<S35>/MinMax1' */
    SWC_VC_B.DiscreteTimeIntegrator_ll = SWC_VC_B.MinMax1_e;
    break;

   case 2:
    for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 14; SWC_VC_B.i_j++) {
      /* RelationalOperator: '<S39>/Compare' incorporates:
       *  Constant: '<S39>/Constant'
       */
      SWC_VC_B.Compare_fj[SWC_VC_B.i_j] = (SWC_VC_B.y[SWC_VC_B.i_j] == 0.0);

      /* Product: '<S36>/Product' incorporates:
       *  Constant: '<S36>/Constant'
       */
      SWC_VC_B.Product_h[SWC_VC_B.i_j] = 255.0 * (real_T)
        SWC_VC_B.Compare_fj[SWC_VC_B.i_j];

      /* Sum: '<S36>/Add' */
      SWC_VC_B.Add_b[SWC_VC_B.i_j] = SWC_VC_B.Product_h[SWC_VC_B.i_j] +
        SWC_VC_B.y[SWC_VC_B.i_j];
    }

    /* MinMax: '<S36>/MinMax1' */
    SWC_VC_B.minV = SWC_VC_B.Add_b[0];
    for (SWC_VC_B.O_WPSweepN_tmp = 0; SWC_VC_B.O_WPSweepN_tmp < 13;
         SWC_VC_B.O_WPSweepN_tmp++) {
      SWC_VC_B.minV = fmin(SWC_VC_B.minV, SWC_VC_B.Add_b[SWC_VC_B.O_WPSweepN_tmp
                           + 1]);
    }

    SWC_VC_B.MinMax1_a = (real32_T)SWC_VC_B.minV;

    /* End of MinMax: '<S36>/MinMax1' */
    SWC_VC_B.DiscreteTimeIntegrator_ll = SWC_VC_B.MinMax1_a;
    break;

   default:
    SWC_VC_B.DiscreteTimeIntegrator_ll = 255.0F;
    break;
  }

  /* End of MultiPortSwitch: '<S5>/Multiport Switch' */

  /* RelationalOperator: '<S5>/Relational Operator' */
  SWC_VC_B.LogicalOperator2_a = (SWC_VC_B.DiscreteTimeIntegrator_ll <=
    SWC_VC_ConstB.DataTypeConversion3);

  /* Gain: '<S5>/Gain5' */
  SWC_VC_B.UnitDelay = (uint8_T)(SWC_VC_B.LogicalOperator2_a ? (int32_T)
    ((uint8_T)128U) : 0);

  /* DataTypeConversion: '<S5>/Data Type Conversion4' */
  SWC_VC_B.ColDist = (uint8_T)((uint32_T)SWC_VC_B.UnitDelay >> 6);

  /* RelationalOperator: '<S124>/Relational Operator5' incorporates:
   *  Constant: '<S124>/Veh_SpdMax_Rq_Def2'
   */
  SWC_VC_B.RelationalOperator5 = (((uint8_T)2U) == SWC_VC_B.ColDist);

  /* Switch: '<S125>/Switch1' incorporates:
   *  Constant: '<S125>/C_APX_RemainDist_NA_Value'
   */
  if (SWC_VC_B.Delay > ((uint8_T)0U)) {
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.remainingdistance_d;
  } else {
    SWC_VC_B.StrTqFB_Old = 20.46F;
  }

  /* End of Switch: '<S125>/Switch1' */

  /* Gain: '<S125>/Gain2' */
  SWC_VC_B.StrTqFB_Old *= 100.0F;

  /* DataTypeConversion: '<S125>/Data Type Conversion1' */
  SWC_VC_B.lookahead_dist_wp = floorf(SWC_VC_B.StrTqFB_Old);
  if (rtIsNaNF(SWC_VC_B.lookahead_dist_wp) || rtIsInfF
      (SWC_VC_B.lookahead_dist_wp)) {
    SWC_VC_B.lookahead_dist_wp = 0.0F;
  } else {
    SWC_VC_B.lookahead_dist_wp = fmodf(SWC_VC_B.lookahead_dist_wp, 65536.0F);
  }

  SWC_VC_B.DataTypeConversion1_m = (uint16_T)(SWC_VC_B.lookahead_dist_wp < 0.0F ?
    (int32_T)(uint16_T)-(int16_T)(uint16_T)-SWC_VC_B.lookahead_dist_wp :
    (int32_T)(uint16_T)SWC_VC_B.lookahead_dist_wp);

  /* End of DataTypeConversion: '<S125>/Data Type Conversion1' */

  /* DataTypeConversion: '<S5>/Data Type Conversion5' */
  SWC_VC_B.lookahead_dist_wp = floorf(SWC_VC_B.DiscreteTimeIntegrator_ll);
  if (rtIsNaNF(SWC_VC_B.lookahead_dist_wp) || rtIsInfF
      (SWC_VC_B.lookahead_dist_wp)) {
    SWC_VC_B.lookahead_dist_wp = 0.0F;
  } else {
    SWC_VC_B.lookahead_dist_wp = fmodf(SWC_VC_B.lookahead_dist_wp, 256.0F);
  }

  SWC_VC_B.ColDist = (uint8_T)(SWC_VC_B.lookahead_dist_wp < 0.0F ? (int32_T)
    (uint8_T)-(int8_T)(uint8_T)-SWC_VC_B.lookahead_dist_wp : (int32_T)(uint8_T)
    SWC_VC_B.lookahead_dist_wp);

  /* End of DataTypeConversion: '<S5>/Data Type Conversion5' */

  /* Sum: '<S124>/Add2' incorporates:
   *  Constant: '<S124>/C_CtrlOut.CollDet_CollDistLimit'
   */
  SWC_VC_B.UnitDelay = (uint8_T)(SWC_VC_B.ColDist - ((uint8_T)30U));

  /* Saturate: '<S124>/Saturation1' */
  SWC_VC_B.CollDistReduc = SWC_VC_B.UnitDelay;

  /* RelationalOperator: '<S130>/Relational Operator1' incorporates:
   *  Constant: '<S130>/CollDet_CalcLimCollDistInt'
   */
  SWC_VC_B.LogicalOperator2_a = (SWC_VC_B.ColDist < 20.0);

  /* RateTransition: '<S21>/Rate Transition1' */
  SWC_VC_B.RateTransition1_a = SWC_VC_B.MeAP_I_GearRpt;

  /* UnitDelay: '<S131>/Unit Delay' */
  SWC_VC_B.UnitDelay = SWC_VC_DW.UnitDelay_DSTATE_j;

  /* RelationalOperator: '<S131>/Relational Operator' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.RateTransition1_a != SWC_VC_B.UnitDelay);

  /* Logic: '<S130>/Logical Operator1' */
  SWC_VC_B.UpperRelop = !SWC_VC_B.UpperRelop;

  /* Logic: '<S130>/Logical Operator' */
  SWC_VC_B.LogicalOperator_i = (SWC_VC_B.RelationalOperator5 &&
    SWC_VC_B.LogicalOperator2_a && SWC_VC_B.UpperRelop &&
    SWC_VC_B.LogicalOperator3_p);

  /* Outputs for Triggered SubSystem: '<S127>/CollDistAtPreCollFlagEntry' incorporates:
   *  TriggerPort: '<S128>/Trigger'
   */
  if (SWC_VC_B.LogicalOperator_i &&
      (SWC_VC_PrevZCX.CollDistAtPreCollFlagEntry_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S128>/In1' */
    SWC_VC_B.In1_k = SWC_VC_B.CollDistReduc;
  }

  SWC_VC_PrevZCX.CollDistAtPreCollFlagEntry_Trig_ZCE =
    SWC_VC_B.LogicalOperator_i;

  /* End of Outputs for SubSystem: '<S127>/CollDistAtPreCollFlagEntry' */

  /* Outputs for Triggered SubSystem: '<S127>/RemainDistAtPreCollFlagEntry' incorporates:
   *  TriggerPort: '<S129>/Trigger'
   */
  if (SWC_VC_B.LogicalOperator_i &&
      (SWC_VC_PrevZCX.RemainDistAtPreCollFlagEntry_Trig_ZCE != POS_ZCSIG)) {
    /* Inport: '<S129>/In1' */
    SWC_VC_B.In1_l = SWC_VC_B.DataTypeConversion1_m;
  }

  SWC_VC_PrevZCX.RemainDistAtPreCollFlagEntry_Trig_ZCE =
    SWC_VC_B.LogicalOperator_i;

  /* End of Outputs for SubSystem: '<S127>/RemainDistAtPreCollFlagEntry' */

  /* Sum: '<S127>/Add' */
  SWC_VC_B.Add_f = (uint16_T)(SWC_VC_B.In1_k - SWC_VC_B.In1_l);

  /* Product: '<S127>/Product' */
  SWC_VC_B.DataTypeConversion5 = (uint16_T)(SWC_VC_B.LogicalOperator_i ?
    (int32_T)SWC_VC_B.Add_f : 0);

  /* Sum: '<S127>/Add1' */
  SWC_VC_B.DataTypeConversion5 = (uint16_T)((uint32_T)
    SWC_VC_B.DataTypeConversion5 + SWC_VC_B.DataTypeConversion1_m);

  /* Saturate: '<S127>/Saturation' */
  if (SWC_VC_B.DataTypeConversion5 < ((uint16_T)2500U)) {
    SWC_VC_B.RemainDistFromCollDist = SWC_VC_B.DataTypeConversion5;
  } else {
    SWC_VC_B.RemainDistFromCollDist = ((uint16_T)2500U);
  }

  /* End of Saturate: '<S127>/Saturation' */

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  RelationalOperator: '<S124>/Relational Operator6'
   */
  SWC_VC_B.LogicalOperator3_p = (SWC_VC_B.CollDistReduc <
    SWC_VC_B.DataTypeConversion1_m);

  /* RelationalOperator: '<S124>/Relational Operator' */
  SWC_VC_B.LogicalOperator2_a = (SWC_VC_B.RemainDistFromCollDist <
    SWC_VC_B.DataTypeConversion1_m);

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  Constant: '<S124>/C_CtrlOut.CollDet_Activate'
   *  Logic: '<S124>/Logical Operator'
   *  Logic: '<S124>/Logical Operator1'
   */
  SWC_VC_B.LogicalOperator3_p = (SWC_VC_B.LogicalOperator3_p ||
    SWC_VC_B.LogicalOperator2_a);
  SWC_VC_B.LogicalOperator3_p = (SWC_VC_B.LogicalOperator3_p &&
    SWC_VC_B.RelationalOperator5 && true);

  /* Switch: '<S124>/Switch1' */
  if (SWC_VC_B.LogicalOperator3_p) {
    /* RelationalOperator: '<S124>/Relational Operator1' */
    SWC_VC_B.RelationalOperator1_p = (SWC_VC_B.CollDistReduc <
      SWC_VC_B.RemainDistFromCollDist);

    /* Switch: '<S124>/Switch6' */
    if (SWC_VC_B.RelationalOperator1_p) {
      SWC_VC_B.CollDist = SWC_VC_B.CollDistReduc;
    } else {
      SWC_VC_B.CollDist = SWC_VC_B.RemainDistFromCollDist;
    }

    /* End of Switch: '<S124>/Switch6' */
    SWC_VC_B.DataTypeConversion5 = SWC_VC_B.CollDist;
  } else {
    SWC_VC_B.DataTypeConversion5 = SWC_VC_B.DataTypeConversion1_m;
  }

  /* End of Switch: '<S124>/Switch1' */

  /* MinMax: '<S124>/MinMax1' incorporates:
   *  Constant: '<S124>/RemainDist_Max'
   */
  SWC_VC_B.Product_a = fmin(2046.0, SWC_VC_B.DataTypeConversion5);

  /* DataTypeConversion: '<S124>/Data Type Conversion5' */
  SWC_VC_B.minV = floor(SWC_VC_B.Product_a);
  if (rtIsNaN(SWC_VC_B.minV) || rtIsInf(SWC_VC_B.minV)) {
    SWC_VC_B.minV = 0.0;
  } else {
    SWC_VC_B.minV = fmod(SWC_VC_B.minV, 65536.0);
  }

  SWC_VC_B.DataTypeConversion5 = (uint16_T)(SWC_VC_B.minV < 0.0 ? (int32_T)
    (uint16_T)-(int16_T)(uint16_T)-SWC_VC_B.minV : (int32_T)(uint16_T)
    SWC_VC_B.minV);

  /* End of DataTypeConversion: '<S124>/Data Type Conversion5' */

  /* DataTypeConversion: '<S109>/Data Type Conversion12' */
  VC_RemainingDist = (real32_T)SWC_VC_B.DataTypeConversion5;

  /* UnitDelay: '<S25>/Unit Delay' */
  SWC_VC_B.UnitDelay_g = SWC_VC_B.LogicalOperator2;

  /* Delay: '<S4>/Delay1' */
  SWC_VC_B.Delay1_d = SWC_VC_B.DataTypeConversion1_o;

  /* DataTypeConversion: '<S25>/Data Type Conversion' */
  SWC_VC_B.DataTypeConversion_m = SWC_VC_B.LogicalOperator;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  Delay: '<S26>/Delay'
   */
  SWC_VC_B.LogicalOperator3_p = SWC_VC_B.LogicalOperator1_m;

  /* Logic: '<S26>/Logical Operator2' */
  SWC_VC_B.LogicalOperator2_a = (SWC_VC_B.LogicalOperator3_p &&
    (*rtu_MeAP_b_VCActive));

  /* DataTypeConversion: '<S25>/Data Type Conversion1' */
  SWC_VC_B.DataTypeConversion1_le = (int8_T)SWC_VC_B.LogicalOperator2_a;

  /* MATLAB Function: '<S124>/MATLAB Function2' incorporates:
   *  Inport: '<Root>/MeAP_m_ParkSpotType'
   */
  SWC_VC_B.CollDistRegen_out = SWC_VC_B.RelationalOperator5;
  if ((SWC_VC_B.NextDir == 0) && ((PSType == 3) || (PSType == 4))) {
    for (SWC_VC_B.k = 0; SWC_VC_B.k < 10; SWC_VC_B.k++) {
      if (SWC_VC_B.fi[SWC_VC_B.k] < 0) {
        SWC_VC_B.i_j = -SWC_VC_B.fi[SWC_VC_B.k];
        if (SWC_VC_B.i_j > 32767) {
          SWC_VC_B.i_j = 32767;
        }

        SWC_VC_B.y_i[SWC_VC_B.k] = (int16_T)SWC_VC_B.i_j;
      } else {
        SWC_VC_B.y_i[SWC_VC_B.k] = SWC_VC_B.fi[SWC_VC_B.k];
      }
    }

    SWC_VC_B.minV = SWC_VC_B.y_i[0];
    for (SWC_VC_B.O_WPSweepN_tmp = 0; SWC_VC_B.O_WPSweepN_tmp < 9;
         SWC_VC_B.O_WPSweepN_tmp++) {
      SWC_VC_B.minV += (real_T)SWC_VC_B.y_i[SWC_VC_B.O_WPSweepN_tmp + 1];
    }

    if (SWC_VC_B.Current_waypoint > SWC_VC_B.minV - 15.0) {
      SWC_VC_B.CollDistRegen_out = false;
    } else {
      SWC_VC_B.CollDistRegen_out = ((PSType != 1) && (PSType != 2) &&
        SWC_VC_B.CollDistRegen_out);
    }
  } else {
    SWC_VC_B.CollDistRegen_out = ((PSType != 1) && (PSType != 2) &&
      SWC_VC_B.CollDistRegen_out);
  }

  /* End of MATLAB Function: '<S124>/MATLAB Function2' */

  /* Chart: '<S25>/SC_ParkingManeuverMgr1' */
  if (SWC_VC_DW.temporalCounter_i1 < 8191U) {
    SWC_VC_DW.temporalCounter_i1++;
  }

  if (SWC_VC_DW.is_active_c25_SWC_VC == 0U) {
    SWC_VC_DW.is_active_c25_SWC_VC = 1U;
    SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Inactive_ST1;
    SWC_VC_DW.tp_APX_Park_State_Inactive_ST1 = 1U;
    SWC_VC_B.ParkingFinished = false;
    SWC_VC_B.APC_Debug_Park_Stat = 40.0F;
    PM_CurrentSweep = 0U;
    SWC_VC_B.CurrentSweepVeh = 0U;
    SWC_VC_B.regen_count = 0.0F;
    SWC_VC_B.DesiredDir = 0;
    SWC_VC_B.APX_Park_Stat = 0.0F;

    /*  Ideal  */
  } else {
    switch (SWC_VC_DW.is_c25_SWC_VC) {
     case SWC_VC_IN_APX_Park_State_Active_ST:
      if (SWC_VC_B.DataTypeConversion1_le == -1) {
        SWC_VC_exit_internal_APX_Park_State_AllStrokes_ST();
        SWC_VC_DW.tp_APX_Park_State_AllStrokes_ST = 0U;
        SWC_VC_DW.tp_APX_Park_State_End_ST = 0U;
        SWC_VC_DW.tp_APX_Park_State_R_gear = 0U;
        SWC_VC_DW.is_APX_Park_State_Active_ST = SWC_VC_IN_NO_ACTIVE_CHILD;
        SWC_VC_DW.tp_APX_Park_State_Active_ST = 0U;
        SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Inactive_ST;
        SWC_VC_DW.temporalCounter_i1 = 0U;
        SWC_VC_DW.tp_APX_Park_State_Inactive_ST = 1U;
        SWC_VC_B.ParkingFinished = false;
        SWC_VC_B.APC_Debug_Park_Stat = 0.0F;
        PM_CurrentSweep = 0U;
        SWC_VC_B.CurrentSweepVeh = 0U;
        SWC_VC_B.regen_count = 0.0F;
        SWC_VC_B.DesiredDir = 0;
        SWC_VC_B.APX_Park_Stat = 1.0F;

        /*  scanning for parking spots */
      } else if ((SWC_VC_B.DataTypeConversion1_le == 0) ||
                 (SWC_VC_B.DataTypeConversion1_le == 2)) {
        SWC_VC_exit_internal_APX_Park_State_AllStrokes_ST();
        SWC_VC_DW.tp_APX_Park_State_AllStrokes_ST = 0U;
        SWC_VC_DW.tp_APX_Park_State_End_ST = 0U;
        SWC_VC_DW.tp_APX_Park_State_R_gear = 0U;
        SWC_VC_DW.is_APX_Park_State_Active_ST = SWC_VC_IN_NO_ACTIVE_CHILD;
        SWC_VC_DW.tp_APX_Park_State_Active_ST = 0U;
        SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Inactive_ST;
        SWC_VC_DW.temporalCounter_i1 = 0U;
        SWC_VC_DW.tp_APX_Park_State_Inactive_ST = 1U;
        SWC_VC_B.ParkingFinished = false;
        SWC_VC_B.APC_Debug_Park_Stat = 0.0F;
        PM_CurrentSweep = 0U;
        SWC_VC_B.CurrentSweepVeh = 0U;
        SWC_VC_B.regen_count = 0.0F;
        SWC_VC_B.DesiredDir = 0;
        SWC_VC_B.APX_Park_Stat = 1.0F;

        /*  scanning for parking spots */
      } else {
        switch (SWC_VC_DW.is_APX_Park_State_Active_ST) {
         case SWC_VC_IN_APX_Park_State_AllStrokes_ST:
          SWC_VC_APX_Park_State_AllStrokes_ST(rtu_MeAP_b_ParkOut);
          break;

         case SWC_VC_IN_APX_Park_State_End_ST:
          break;

         case SWC_VC_IN_APX_Park_State_PARK_FIN_MSG:
          if ((Ap_App_ID == 0) && (*rtu_MeAP_b_ParkOut)) {
            SWC_VC_B.DesiredDir = 1;
            SWC_VC_DW.is_APX_Park_State_Active_ST =
              SWC_VC_IN_APX_Park_State_End_ST;
            SWC_VC_DW.tp_APX_Park_State_End_ST = 1U;
            SWC_VC_B.ParkingFinished = true;
            SWC_VC_B.APC_Debug_Park_Stat = 20.0F;
            SWC_VC_B.APX_Park_Stat = 8.0F;
          } else {
            SWC_VC_DW.is_APX_Park_State_Active_ST =
              SWC_VC_IN_APX_Park_State_R_gear;
            SWC_VC_DW.tp_APX_Park_State_R_gear = 1U;
            SWC_VC_B.APC_Debug_Park_Stat = 25.0F;
            SWC_VC_B.DesiredDir = 0;
          }
          break;

         default:
          /* case IN_APX_Park_State_R_gear: */
          if (SWC_VC_B.MeAP_I_GearRpt == 0) {
            SWC_VC_DW.tp_APX_Park_State_R_gear = 0U;
            SWC_VC_DW.is_APX_Park_State_Active_ST =
              SWC_VC_IN_APX_Park_State_End_ST;
            SWC_VC_DW.tp_APX_Park_State_End_ST = 1U;
            SWC_VC_B.ParkingFinished = true;
            SWC_VC_B.APC_Debug_Park_Stat = 20.0F;
            SWC_VC_B.APX_Park_Stat = 8.0F;
          }
          break;
        }
      }
      break;

     case SWC_VC_IN_APX_Park_State_Inactive_ST:
      if (SWC_VC_B.DataTypeConversion1_le == 1) {
        SWC_VC_DW.tp_APX_Park_State_Inactive_ST = 0U;
        PM_CurrentSweep = 1U;
        SWC_VC_B.CurrentSweepVeh = 1U;
        SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Active_ST;
        SWC_VC_DW.tp_APX_Park_State_Active_ST = 1U;
        SWC_VC_B.APX_Park_Stat = 2.0F;

        /*  Found parking spots */
        SWC_VC_DW.is_APX_Park_State_Active_ST =
          SWC_VC_IN_APX_Park_State_AllStrokes_ST;
        SWC_VC_DW.tp_APX_Park_State_AllStrokes_ST = 1U;
        SWC_VC_DW.regen_on_fly_counter = 0U;
        SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_DIRECTION_CHECK;
        SWC_VC_B.APC_Debug_Park_Stat = 33.0F;
        SWC_VC_B.NewPathAccepted = 1.0F;
      } else {
        if (SWC_VC_DW.temporalCounter_i1 >= 6000U) {
          /* [(VehSpd_Disp_Value <= 0.1)] */
          SWC_VC_DW.tp_APX_Park_State_Inactive_ST = 0U;
          SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Inactive_ST1;
          SWC_VC_DW.tp_APX_Park_State_Inactive_ST1 = 1U;
          SWC_VC_B.ParkingFinished = false;
          SWC_VC_B.APC_Debug_Park_Stat = 40.0F;
          PM_CurrentSweep = 0U;
          SWC_VC_B.CurrentSweepVeh = 0U;
          SWC_VC_B.regen_count = 0.0F;
          SWC_VC_B.DesiredDir = 0;
          SWC_VC_B.APX_Park_Stat = 0.0F;

          /*  Ideal  */
        }
      }
      break;

     default:
      /* case IN_APX_Park_State_Inactive_ST1: */
      if (SWC_VC_B.speed_kph_MABx > 0.2) {
        SWC_VC_DW.tp_APX_Park_State_Inactive_ST1 = 0U;
        SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Inactive_ST;
        SWC_VC_DW.temporalCounter_i1 = 0U;
        SWC_VC_DW.tp_APX_Park_State_Inactive_ST = 1U;
        SWC_VC_B.ParkingFinished = false;
        SWC_VC_B.APC_Debug_Park_Stat = 0.0F;
        PM_CurrentSweep = 0U;
        SWC_VC_B.CurrentSweepVeh = 0U;
        SWC_VC_B.regen_count = 0.0F;
        SWC_VC_B.DesiredDir = 0;
        SWC_VC_B.APX_Park_Stat = 1.0F;

        /*  scanning for parking spots */
      } else {
        if (SWC_VC_B.DataTypeConversion1_le == 1) {
          SWC_VC_DW.tp_APX_Park_State_Inactive_ST1 = 0U;
          PM_CurrentSweep = 1U;
          SWC_VC_B.CurrentSweepVeh = 1U;
          SWC_VC_DW.is_c25_SWC_VC = SWC_VC_IN_APX_Park_State_Active_ST;
          SWC_VC_DW.tp_APX_Park_State_Active_ST = 1U;
          SWC_VC_B.APX_Park_Stat = 2.0F;

          /*  Found parking spots */
          SWC_VC_DW.is_APX_Park_State_Active_ST =
            SWC_VC_IN_APX_Park_State_AllStrokes_ST;
          SWC_VC_DW.tp_APX_Park_State_AllStrokes_ST = 1U;
          SWC_VC_DW.regen_on_fly_counter = 0U;
          SWC_VC_DW.is_APX_Park_State_AllStrokes_ST = SWC_VC_IN_DIRECTION_CHECK;
          SWC_VC_B.APC_Debug_Park_Stat = 33.0F;
          SWC_VC_B.NewPathAccepted = 1.0F;
        }
      }
      break;
    }
  }

  /* End of Chart: '<S25>/SC_ParkingManeuverMgr1' */

  /* RateTransition: '<S21>/Rate Transition2' */
  SWC_VC_B.RateTransition2 = SWC_VC_B.speed_kph_MABx;

  /* Delay: '<S108>/Delay One Step' */
  SWC_VC_B.DelayOneStep = SWC_VC_DW.DelayOneStep_DSTATE_c;

  /* MATLAB Function: '<S108>/Gear_CMD_func' incorporates:
   *  Constant: '<S108>/GearDrive'
   *  Constant: '<S108>/GearPark'
   *  Constant: '<S108>/GearReverse'
   *  Constant: '<S108>/gear_change_speed_eps_kph'
   */
  SWC_VC_B.Gear_CMD = 0.0;
  if (SWC_VC_B.LogicalOperator && (fabsf(SWC_VC_B.RateTransition2) < 0.001)) {
    switch (SWC_VC_B.DesiredDir) {
     case 1:
      SWC_VC_B.Gear_CMD = 4.0;
      break;

     case 0:
      SWC_VC_B.Gear_CMD = 1.0;
      break;

     case -1:
      SWC_VC_B.Gear_CMD = 2.0;
      break;
    }
  }

  SWC_VC_B.i_j = SWC_VC_B.DesiredDir * SWC_VC_B.DelayOneStep;
  if (SWC_VC_B.i_j > 127) {
    SWC_VC_B.i_j = 127;
  } else {
    if (SWC_VC_B.i_j < -128) {
      SWC_VC_B.i_j = -128;
    }
  }

  SWC_VC_B.new_dir_flag = (SWC_VC_B.i_j < 0);

  /* End of MATLAB Function: '<S108>/Gear_CMD_func' */

  /* Delay: '<S113>/Delay1' */
  SWC_VC_B.UpperRelop = SWC_VC_B.sweep_end_flag;

  /* DataTypeConversion: '<S113>/Cast To Boolean1' */
  SWC_VC_B.CastToBoolean1 = SWC_VC_B.UpperRelop;

  /* MATLAB Function: '<S113>/MATLAB Function1' */
  SWC_VC_B.sweep_end_flag = ((!(SWC_VC_B.curr_wp < 5.0F)) &&
    (SWC_VC_B.new_dir_flag || SWC_VC_B.CastToBoolean1));

  /* RelationalOperator: '<S118>/Compare' incorporates:
   *  Constant: '<S118>/Constant'
   */
  SWC_VC_B.UpperRelop = (SWC_VC_B.sweep_end_flag == false);

  /* Delay: '<S113>/Delay' */
  SWC_VC_B.RelationalOperator1_a = SWC_VC_B.no_vel_flag;

  /* DataTypeConversion: '<S113>/Cast To Boolean' */
  SWC_VC_B.CastToBoolean = SWC_VC_B.RelationalOperator1_a;

  /* Constant: '<S113>/RemainDist_Stat_sendtime ' */
  SWC_VC_B.RemainDist_Stat_sendtime = 5.0F;

  /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */
  if (SWC_VC_B.Delay1_k || (SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_g !=
       0)) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d =
      SWC_VC_B.RemainDist_Stat_sendtime;
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d >= rtInfF) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = rtInfF;
    } else {
      if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d <= (-1.0F)) {
        SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = (-1.0F);
      }
    }
  }

  if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = (-1.0F);
    }
  }

  SWC_VC_B.DiscreteTimeIntegrator_l = SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d;

  /* End of DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */

  /* RelationalOperator: '<S119>/Compare' incorporates:
   *  Constant: '<S119>/Constant'
   */
  SWC_VC_B.Compare_i = (SWC_VC_B.DiscreteTimeIntegrator_l > 0.0F);

  /* DataTypeConversion: '<S108>/Data Type Conversion22' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  SWC_VC_B.DiscreteTimeIntegrator_ll = DS_ANGLE;

  /* Sum: '<S113>/Add' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = VC_Steer_CMD -
    SWC_VC_B.DiscreteTimeIntegrator_ll;

  /* Abs: '<S113>/Abs' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = fabsf(SWC_VC_B.DiscreteTimeIntegrator_ll);

  /* RelationalOperator: '<S113>/RelOp' incorporates:
   *  Constant: '<S113>/VehSpdMax_DeadStr_RackDevThd'
   */
  SWC_VC_B.RelOp = (SWC_VC_B.DiscreteTimeIntegrator_ll > 70.0F);

  /* MATLAB Function: '<S113>/MATLAB Function' */
  SWC_VC_B.no_vel_flag = (SWC_VC_B.Delay1_k || (SWC_VC_B.RelOp &&
    SWC_VC_B.CastToBoolean && SWC_VC_B.Compare_i));

  /* Switch: '<S113>/Switch7' incorporates:
   *  Constant: '<S113>/VehSpdMax_DeadSteer'
   *  Switch: '<S113>/Switch4'
   */
  if (SWC_VC_B.no_vel_flag) {
    SWC_VC_B.Switch7 = 0.0F;
  } else {
    if (SWC_VC_B.Delay != 0) {
      /* MinMax: '<S113>/MinMax1' incorporates:
       *  Constant: '<S113>/Max_Spd_limit'
       *  Switch: '<S113>/Switch4'
       */
      SWC_VC_B.MinMax1 = fmin(SWC_VC_B.MaxSpeed, 2.5);

      /* Switch: '<S113>/Switch4' */
      SWC_VC_B.Switch4 = (real32_T)SWC_VC_B.MinMax1;
    } else {
      /* Switch: '<S113>/Switch4' incorporates:
       *  Constant: '<S113>/Veh_SpdMax_Rq_Def1'
       */
      SWC_VC_B.Switch4 = 0.0F;
    }

    SWC_VC_B.Switch7 = SWC_VC_B.Switch4;
  }

  /* End of Switch: '<S113>/Switch7' */

  /* Switch: '<S113>/Switch' incorporates:
   *  Constant: '<S113>/NoRemainDist'
   */
  if (0.0F > 0.0F) {
    SWC_VC_B.Product_a = SWC_VC_B.Switch7;
  } else {
    /* Gain: '<S113>/Gain1' */
    SWC_VC_B.Saturation_Speed = 0.01F * VC_RemainingDist;

    /* Saturate: '<S113>/Saturation_Speed' */
    if (SWC_VC_B.Saturation_Speed > 2.0F) {
      SWC_VC_B.Saturation_Speed = 2.0F;
    } else {
      if (SWC_VC_B.Saturation_Speed < 0.0F) {
        SWC_VC_B.Saturation_Speed = 0.0F;
      }
    }

    /* End of Saturate: '<S113>/Saturation_Speed' */

    /* Sum: '<S113>/Sum' incorporates:
     *  Constant: '<S113>/Max_Spd_limit1'
     */
    SWC_VC_B.Sum_g = SWC_VC_B.Saturation_Speed + 0.2;

    /* MinMax: '<S113>/MinMax' */
    SWC_VC_B.MinMax = fmin(SWC_VC_B.Switch7, SWC_VC_B.Sum_g);
    SWC_VC_B.Product_a = SWC_VC_B.MinMax;
  }

  /* End of Switch: '<S113>/Switch' */

  /* Product: '<S113>/Product' */
  SWC_VC_B.Product = (real_T)SWC_VC_B.UpperRelop * SWC_VC_B.Product_a;

  /* UnitDelay: '<S122>/Delay Input2'
   *
   * Block description for '<S122>/Delay Input2':
   *
   *  Store in Global RAM
   */
  SWC_VC_B.Yk1 = SWC_VC_B.DifferenceInputs2;

  /* Sum: '<S122>/Difference Inputs1'
   *
   * Block description for '<S122>/Difference Inputs1':
   *
   *  Add in CPU
   */
  SWC_VC_B.UkYk1 = SWC_VC_B.Product - SWC_VC_B.Yk1;

  /* Constant: '<S113>/Lower_rate_limit_duration' */
  SWC_VC_B.Lower_rate_limit_duration = 3.0F;

  /* DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */
  if (SWC_VC_B.Delay1_k || (SWC_VC_DW.DiscreteTimeIntegrator2_PrevResetState !=
       0)) {
    SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE =
      SWC_VC_B.Lower_rate_limit_duration;
    if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE >= rtInfF) {
      SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = rtInfF;
    } else {
      if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE <= (-1.0F)) {
        SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = (-1.0F);
      }
    }
  }

  if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = (-1.0F);
    }
  }

  SWC_VC_B.DiscreteTimeIntegrator2 = SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE;

  /* End of DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */

  /* Switch: '<S113>/Switch1' incorporates:
   *  Constant: '<S113>/Initial_speed_rate_limit'
   *  Constant: '<S113>/final_speed_rate_limit'
   */
  if (SWC_VC_B.DiscreteTimeIntegrator2 > 0.0F) {
    SWC_VC_B.Product_a = 0.3;
  } else {
    SWC_VC_B.Product_a = 0.5;
  }

  /* End of Switch: '<S113>/Switch1' */

  /* SampleTimeMath: '<S122>/sample time'
   *
   * About '<S122>/sample time':
   *  y = K where K = ( w * Ts )
   */
  SWC_VC_B.sampletime = 0.03;

  /* Product: '<S122>/delta rise limit' */
  SWC_VC_B.deltariselimit = SWC_VC_B.Product_a * SWC_VC_B.sampletime;

  /* RelationalOperator: '<S123>/LowerRelop1' */
  SWC_VC_B.RelationalOperator1_a = (SWC_VC_B.UkYk1 > SWC_VC_B.deltariselimit);

  /* Gain: '<S113>/Gain' */
  SWC_VC_B.Product_a *= (-1.0);

  /* Product: '<S122>/delta fall limit' */
  SWC_VC_B.deltafalllimit = SWC_VC_B.Product_a * SWC_VC_B.sampletime;

  /* RelationalOperator: '<S123>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UkYk1 < SWC_VC_B.deltafalllimit);

  /* Switch: '<S123>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch = SWC_VC_B.deltafalllimit;
  } else {
    SWC_VC_B.Switch = SWC_VC_B.UkYk1;
  }

  /* End of Switch: '<S123>/Switch' */

  /* Switch: '<S123>/Switch2' */
  if (SWC_VC_B.RelationalOperator1_a) {
    SWC_VC_B.Switch2 = SWC_VC_B.deltariselimit;
  } else {
    SWC_VC_B.Switch2 = SWC_VC_B.Switch;
  }

  /* End of Switch: '<S123>/Switch2' */

  /* Sum: '<S122>/Difference Inputs2'
   *
   * Block description for '<S122>/Difference Inputs2':
   *
   *  Add in CPU
   */
  SWC_VC_B.DifferenceInputs2 = SWC_VC_B.Switch2 + SWC_VC_B.Yk1;

  /* DataTypeConversion: '<S108>/Data Type Conversion1' */
  SWC_VC_B.TargetSpeed = (real32_T)SWC_VC_B.DifferenceInputs2;

  /* DataTypeConversion: '<S111>/Data Type Conversion1' */
  SWC_VC_B.DataTypeConversion1_l = SWC_VC_B.TargetSpeed;

  /* Memory: '<S111>/Memory' */
  SWC_VC_B.Memory = SWC_VC_DW.Memory_PreviousInput;

  /* DiscreteIntegrator: '<S111>/Discrete-Time Integrator' */
  SWC_VC_B.DiscreteTimeIntegrator_ll = SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_p;

  /* DataTypeConversion: '<S111>/Data Type Conversion12' */
  SWC_VC_B.StrTqFB_Old = SWC_VC_B.DiscreteTimeIntegrator_ll;

  /* RateTransition: '<S111>/Rate Transition' */
  SWC_VC_B.RateTransition = SWC_VC_B.StrTqFB_Old;

  /* Memory: '<S111>/Memory1' */
  SWC_VC_B.StrTqFB_Old = SWC_VC_DW.Memory1_PreviousInput;

  /* DataTypeConversion: '<S111>/Data Type Conversion3' */
  SWC_VC_B.DataTypeConversion3_e = SWC_VC_B.StrTqFB_Old;

  /* RelationalOperator: '<S34>/Compare' incorporates:
   *  Constant: '<S34>/Constant'
   */
  SWC_VC_B.RelationalOperator1_a = (*rtu_MeAP_cm_CDminDist < 40.0F);

  /* Logic: '<S1>/Logical Operator' */
  SWC_VC_B.LogicalOperator_c = (SWC_VC_B.RelationalOperator1_a ||
    (*rtu_MeAP_b_VCOpPaused));

  /* Memory: '<S111>/Memory2' */
  SWC_VC_B.Memory2 = SWC_VC_DW.Memory2_PreviousInput;

  /* MATLAB Function: '<S111>/Brake At Gear Changing From Zero || Stopping Mode' */
  SWC_VC_B.driverIgnore = 0.0;
  SWC_VC_B.brakeReleaseTime = SWC_VC_B.DataTypeConversion3_e;
  if (((SWC_VC_B.RateTransition1_a == 2) || (SWC_VC_B.RateTransition1_a == 4)) &&
      (SWC_VC_B.Memory == 1)) {
    SWC_VC_B.brakeReleaseTime = SWC_VC_B.RateTransition + 1.0F;
  }

  if (SWC_VC_B.LogicalOperator_c && (!SWC_VC_B.Memory2)) {
    SWC_VC_B.brakeReleaseTime = SWC_VC_B.RateTransition + 5.0F;
  }

  if (SWC_VC_B.LogicalOperator_c) {
    SWC_VC_B.hardBrake = SWC_VC_B.LogicalOperator_c;
    SWC_VC_B.driverIgnore = 1.0;
  } else if ((SWC_VC_B.RateTransition < SWC_VC_B.brakeReleaseTime) ||
             ((SWC_VC_B.DataTypeConversion1_l == 0.0F) &&
              (SWC_VC_B.RateTransition2 == 0.0F)) || (VC_RemainingDist < 4.0F))
  {
    SWC_VC_B.hardBrake = 1.0;
    SWC_VC_B.driverIgnore = 1.0;
  } else {
    SWC_VC_B.hardBrake = 0.0;
  }

  /* End of MATLAB Function: '<S111>/Brake At Gear Changing From Zero || Stopping Mode' */

  /* Sum: '<S111>/Sum1' */
  SWC_VC_B.Sum1 = SWC_VC_B.TargetSpeed - SWC_VC_B.RateTransition2;

  /* Outputs for Atomic SubSystem: '<S111>/Brake_PID' */
  /* Lookup_n-D: '<S115>/1-D Lookup Table' */
  SWC_VC_B.uDLookupTable = look1_iflf_binlxpw(VC_RemainingDist,
    rtCP_uDLookupTable_bp01Data, rtCP_uDLookupTable_tableData, 5U);

  /* RelationalOperator: '<S116>/u_GTE_up' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.Sum1 >= SWC_VC_B.uDLookupTable);

  /* Switch: '<S116>/Switch' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Delay1 = SWC_VC_B.uDLookupTable;
  } else {
    /* Gain: '<S115>/Gain' */
    SWC_VC_B.Gain = (-1.0F) * SWC_VC_B.uDLookupTable;

    /* RelationalOperator: '<S116>/u_GT_lo' */
    SWC_VC_B.u_GT_lo = (SWC_VC_B.Sum1 > SWC_VC_B.Gain);

    /* Switch: '<S116>/Switch1' */
    if (SWC_VC_B.u_GT_lo) {
      SWC_VC_B.Switch1 = SWC_VC_B.Sum1;
    } else {
      SWC_VC_B.Switch1 = SWC_VC_B.Gain;
    }

    /* End of Switch: '<S116>/Switch1' */
    SWC_VC_B.Delay1 = SWC_VC_B.Switch1;
  }

  /* End of Switch: '<S116>/Switch' */

  /* Sum: '<S116>/Diff' */
  SWC_VC_B.Diff = SWC_VC_B.Sum1 - SWC_VC_B.Delay1;

  /* UnitDelay: '<S115>/Unit Delay1' */
  SWC_VC_B.UnitDelay1 = SWC_VC_DW.UnitDelay1_DSTATE_f;

  /* MATLAB Function: '<S115>/PID_Algorithm' incorporates:
   *  Constant: '<S115>/Ki'
   *  Constant: '<S115>/Kp'
   *  Constant: '<S115>/max_pid_val'
   *  Constant: '<S115>/min_pid_val'
   *  Constant: '<S115>/sampleTime'
   */
  SWC_VC_B.integrator_val = SWC_VC_B.UnitDelay1;
  SWC_VC_B.lookahead_dist_wp = 0.07F * SWC_VC_B.Diff + 0.07F *
    SWC_VC_B.UnitDelay1;
  if (SWC_VC_B.lookahead_dist_wp > 0.07F) {
    SWC_VC_B.lookahead_dist_wp = 0.07F;
  } else if (SWC_VC_B.lookahead_dist_wp < (-0.07F)) {
    SWC_VC_B.lookahead_dist_wp = (-0.07F);
  } else {
    SWC_VC_B.integrator_val = SWC_VC_B.Diff * 0.01F + SWC_VC_B.UnitDelay1;
  }

  SWC_VC_B.act_pct = SWC_VC_B.lookahead_dist_wp;

  /* End of MATLAB Function: '<S115>/PID_Algorithm' */
  /* Switch: '<S115>/Switch' incorporates:
   *  Constant: '<S115>/Constant'
   *  Constant: '<S115>/Constant2'
   */
  if (0.0F != 0.0F) {
    SWC_VC_B.Switch_j = 0.0F;
  } else {
    SWC_VC_B.Switch_j = SWC_VC_B.integrator_val;
  }

  /* End of Switch: '<S115>/Switch' */

  /* DataTypeConversion: '<S115>/Data Type Conversion3' */
  SWC_VC_B.DataTypeConversion3_j = SWC_VC_B.act_pct;

  /* Switch: '<S115>/Switch3' incorporates:
   *  Constant: '<S115>/Constant3'
   */
  if (SWC_VC_B.DataTypeConversion3_j > 0.0F) {
    SWC_VC_B.Switch3 = SWC_VC_B.DataTypeConversion3_j;
  } else {
    SWC_VC_B.Switch3 = 0.0F;
  }

  /* End of Switch: '<S115>/Switch3' */
  /* Switch: '<S115>/Switch4' incorporates:
   *  Constant: '<S115>/Constant4'
   */
  if (SWC_VC_B.DataTypeConversion3_j > 0.0F) {
    SWC_VC_B.Switch4_o = 0.0F;
  } else {
    /* Abs: '<S115>/Abs' */
    SWC_VC_B.Abs_e4 = fabsf(SWC_VC_B.DataTypeConversion3_j);
    SWC_VC_B.Switch4_o = SWC_VC_B.Abs_e4;
  }

  /* End of Switch: '<S115>/Switch4' */
  /* Update for UnitDelay: '<S115>/Unit Delay1' */
  SWC_VC_DW.UnitDelay1_DSTATE_f = SWC_VC_B.Switch_j;

  /* End of Outputs for SubSystem: '<S111>/Brake_PID' */

  /* Switch: '<S111>/Switch_Brake2' */
  if (SWC_VC_B.hardBrake != 0.0) {
    SWC_VC_B.StrTqFB_Old = SWC_VC_ConstB.DataTypeConversion22;
  } else {
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.Switch3;
  }

  /* End of Switch: '<S111>/Switch_Brake2' */
  /* DataTypeConversion: '<Root>/Data Type Conversion1' */
  *rty_MeAP_a_ThrtlCmd = SWC_VC_B.StrTqFB_Old;

  /* Switch: '<S111>/Switch_Brake1' */
  if (SWC_VC_B.hardBrake != 0.0) {
    /* Product: '<S111>/Product' */
    SWC_VC_B.Product_b = SWC_VC_ConstB.DataTypeConversion4 * SWC_VC_B.hardBrake;
    SWC_VC_B.Product_a = SWC_VC_B.Product_b;
  } else {
    SWC_VC_B.Product_a = SWC_VC_B.Switch4_o;
  }

  /* End of Switch: '<S111>/Switch_Brake1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion2' */
  *rty_MeAP_a_BrkCmd = (real32_T)SWC_VC_B.Product_a;

  /* Outputs for Enabled SubSystem: '<S1>/Subsystem1' incorporates:
   *  EnablePort: '<S17>/Enable'
   */
  if (*rtu_MeAP_b_VCActive) {
    SWC_VC_DW.Subsystem1_MODE = true;

    /* SignalConversion generated from: '<S17>/IeAP_a_DecelMax' incorporates:
     *  Constant: '<S17>/Constant'
     */
    SWC_VC_B.OutportBufferForIeAP_a_DecelMax = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_a_DecelMin' incorporates:
     *  Constant: '<S17>/Constant1'
     */
    SWC_VC_B.OutportBufferForIeAP_a_DecelMin = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_a_JerkDecelMax' incorporates:
     *  Constant: '<S17>/Constant2'
     */
    SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMax = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_a_JerkDecelMin' incorporates:
     *  Constant: '<S17>/Constant3'
     */
    SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMin = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_a_AcclMin' incorporates:
     *  Constant: '<S17>/Constant4'
     */
    SWC_VC_B.OutportBufferForIeAP_a_AcclMin = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_a_AcclMax' incorporates:
     *  Constant: '<S17>/Constant5'
     */
    SWC_VC_B.OutportBufferForIeAP_a_AcclMax = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_da_JerkAcclMax' incorporates:
     *  Constant: '<S17>/Constant6'
     */
    SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMax = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_da_JerkAcclMin' incorporates:
     *  Constant: '<S17>/Constant7'
     */
    SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMin = 0.0;

    /* SignalConversion generated from: '<S17>/IeAP_b_StandstillReq' incorporates:
     *  Constant: '<S17>/Constant8'
     */
    SWC_VC_B.OutportBufferForIeAP_b_StandstillReq = 0.0;

    /* DataTypeConversion: '<S17>/Data Type Conversion' */
    SWC_VC_B.DataTypeConversion_l = SWC_VC_B.TargetSpeed;

    /* RelationalOperator: '<S70>/Compare' incorporates:
     *  Constant: '<S70>/Constant'
     */
    SWC_VC_B.Compare_g = (VC_RemainingDist <= 15.0F);
  } else {
    if (SWC_VC_DW.Subsystem1_MODE) {
      /* Disable for Outport: '<S17>/IeAP_a_DecelMax' */
      SWC_VC_B.OutportBufferForIeAP_a_DecelMax = 0.0;

      /* Disable for Outport: '<S17>/IeAP_a_DecelMin' */
      SWC_VC_B.OutportBufferForIeAP_a_DecelMin = 0.0;

      /* Disable for Outport: '<S17>/IeAP_a_JerkDecelMax' */
      SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMax = 0.0;

      /* Disable for Outport: '<S17>/IeAP_a_JerkDecelMin' */
      SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMin = 0.0;

      /* Disable for Outport: '<S17>/IeAP_a_AcclMin' */
      SWC_VC_B.OutportBufferForIeAP_a_AcclMin = 0.0;

      /* Disable for Outport: '<S17>/IeAP_a_AcclMax' */
      SWC_VC_B.OutportBufferForIeAP_a_AcclMax = 0.0;

      /* Disable for Outport: '<S17>/IeAP_da_JerkAcclMax' */
      SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMax = 0.0;

      /* Disable for Outport: '<S17>/IeAP_da_JerkAcclMin' */
      SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMin = 0.0;

      /* Disable for Outport: '<S17>/IeAP_b_StandstillReq' */
      SWC_VC_B.OutportBufferForIeAP_b_StandstillReq = 0.0;

      /* Disable for Outport: '<S17>/IeAP_kph_MaxSpeed' */
      SWC_VC_B.DataTypeConversion_l = 0.0F;
      SWC_VC_DW.Subsystem1_MODE = false;
    }
  }

  /* End of Outputs for SubSystem: '<S1>/Subsystem1' */

  /* RelationalOperator: '<S1>/NotEqual' incorporates:
   *  Constant: '<S1>/Constant3'
   */
  SWC_VC_B.RelationalOperator1_a = (0.0 != SWC_VC_B.Gear_CMD);

  /* RelationalOperator: '<S1>/Relational Operator' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.Gear_CMD != SWC_VC_B.MeAP_I_GearRpt);

  /* Logic: '<S1>/Logical Operator8' */
  SWC_VC_B.LogicalOperator8 = (SWC_VC_B.RelationalOperator1_a &&
    SWC_VC_B.UpperRelop);

  /* Logic: '<S3>/Logical Operator' */
  SWC_VC_B.RelationalOperator1_a = ((*rtu_MeAP_b_VCActive) ||
    (*rtu_MeAP_b_ParkOut));

  /* Logic: '<S3>/Logical Operator2' */
  SWC_VC_B.UpperRelop = !*rtu_IeVBII_b_ActvParkMode;

  /* Logic: '<S3>/Logical Operator1' */
  SWC_VC_B.RelationalOperator1_a = (SWC_VC_B.RelationalOperator1_a &&
    SWC_VC_B.UpperRelop);

  /* Switch generated from: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant8'
   */
  if (SWC_VC_B.RelationalOperator1_a) {
    /* Logic: '<S1>/Logical Operator10' */
    SWC_VC_B.LogicalOperator10 = !SWC_VC_B.LogicalOperator8;

    /* Logic: '<S1>/Logical Operator2' */
    SWC_VC_B.LogicalOperator4_j = !*rtu_MeAP_b_VCOpPaused;

    /* RelationalOperator: '<S9>/Compare' incorporates:
     *  Constant: '<S9>/Constant'
     */
    SWC_VC_B.Compare_gr = (SWC_VC_B.DataTypeConversion_l > 0.1F);

    /* Logic: '<S1>/Logical Operator4' */
    SWC_VC_B.LogicalOperator4_j = (SWC_VC_B.LogicalOperator4_j &&
      SWC_VC_B.Compare_gr && SWC_VC_B.LogicalOperator10);

    /* DataTypeConversion: '<S1>/Data Type Conversion5' */
    SWC_VC_B.Product1 = SWC_VC_B.LogicalOperator4_j;

    /* Product: '<S1>/Product1' */
    SWC_VC_B.Product1 *= VC_RemainingDist;

    /* MinMax: '<S1>/Min' incorporates:
     *  Constant: '<S1>/Constant1'
     */
    SWC_VC_B.Min = fmin(SWC_VC_B.Product1, 1023.0);

    /* DataTypeConversion: '<Root>/Data Type Conversion11' */
    SWC_VC_B.IeAP_cm_TrgtDist = (real32_T)SWC_VC_B.Min;
    *rty_IeAP_cm_TrgtDist = SWC_VC_B.IeAP_cm_TrgtDist;
  } else {
    *rty_IeAP_cm_TrgtDist = 0.0F;
  }

  /* Delay: '<S1>/Delay1' */
  SWC_VC_B.Product_a = SWC_VC_DW.Delay1_DSTATE_c[0];

  /* DataTypeConversion: '<Root>/Data Type Conversion4' */
  SWC_VC_B.minV = floor(SWC_VC_B.Product_a);
  if (rtIsNaN(SWC_VC_B.minV) || rtIsInf(SWC_VC_B.minV)) {
    SWC_VC_B.minV = 0.0;
  } else {
    SWC_VC_B.minV = fmod(SWC_VC_B.minV, 256.0);
  }

  SWC_VC_B.UnitDelay = (uint8_T)(SWC_VC_B.minV < 0.0 ? (int32_T)(uint8_T)
    -(int8_T)(uint8_T)-SWC_VC_B.minV : (int32_T)(uint8_T)SWC_VC_B.minV);

  /* End of DataTypeConversion: '<Root>/Data Type Conversion4' */

  /* DataTypeConversion: '<Root>/Data Type Conversion7' */
  MeAP_e_GearCmd = (TeAutoPark_e_GearCmd)SWC_VC_B.UnitDelay;

  /* Switch generated from: '<S3>/Switch' incorporates:
   *  Constant: '<S3>/Constant'
   *  Constant: '<S3>/Constant1'
   *  Constant: '<S3>/Constant10'
   *  Constant: '<S3>/Constant11'
   *  Constant: '<S3>/Constant2'
   *  Constant: '<S3>/Constant3'
   *  Constant: '<S3>/Constant4'
   *  Constant: '<S3>/Constant5'
   *  Constant: '<S3>/Constant6'
   *  Constant: '<S3>/Constant7'
   *  Constant: '<S3>/Constant9'
   */
  if (SWC_VC_B.RelationalOperator1_a) {
    *rty_MeAP_e_GearCmd = MeAP_e_GearCmd;

    /* DataTypeConversion: '<Root>/Data Type Conversion23' */
    SWC_VC_B.IeAP_a_DecelMax = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_a_DecelMax;
    *rty_IeAP_a_DecelMax = SWC_VC_B.IeAP_a_DecelMax;

    /* DataTypeConversion: '<Root>/Data Type Conversion22' */
    SWC_VC_B.IeAP_a_DecelMin = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_a_DecelMin;
    *rty_IeAP_a_DecelMin = SWC_VC_B.IeAP_a_DecelMin;

    /* DataTypeConversion: '<Root>/Data Type Conversion21' */
    SWC_VC_B.IeAP_a_JerkDecelMax = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMax;
    *rty_IeAP_a_JerkDecelMax = SWC_VC_B.IeAP_a_JerkDecelMax;

    /* DataTypeConversion: '<Root>/Data Type Conversion20' */
    SWC_VC_B.IeAP_a_JerkDecelMin = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_a_JerkDecelMin;
    *rty_IeAP_a_JerkDecelMin = SWC_VC_B.IeAP_a_JerkDecelMin;

    /* DataTypeConversion: '<Root>/Data Type Conversion19' */
    SWC_VC_B.IeAP_a_AcclMin = (real32_T)SWC_VC_B.OutportBufferForIeAP_a_AcclMin;
    *rty_IeAP_a_AcclMin = SWC_VC_B.IeAP_a_AcclMin;

    /* DataTypeConversion: '<Root>/Data Type Conversion18' */
    SWC_VC_B.IeAP_a_AcclMax = (real32_T)SWC_VC_B.OutportBufferForIeAP_a_AcclMax;
    *rty_IeAP_a_AcclMax = SWC_VC_B.IeAP_a_AcclMax;

    /* DataTypeConversion: '<Root>/Data Type Conversion17' */
    SWC_VC_B.IeAP_da_JerkAcclMax = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMax;
    *rty_IeAP_da_JerkAcclMax = SWC_VC_B.IeAP_da_JerkAcclMax;

    /* DataTypeConversion: '<Root>/Data Type Conversion16' */
    SWC_VC_B.IeAP_da_JerkAcclMin = (real32_T)
      SWC_VC_B.OutportBufferForIeAP_da_JerkAcclMin;
    *rty_IeAP_da_JerkAcclMin = SWC_VC_B.IeAP_da_JerkAcclMin;

    /* DataTypeConversion: '<Root>/Data Type Conversion14' */
    SWC_VC_B.IeAP_b_StandstillReq =
      (SWC_VC_B.OutportBufferForIeAP_b_StandstillReq != 0.0);
    *rty_IeAP_b_StandstillReq = SWC_VC_B.IeAP_b_StandstillReq;

    /* RelationalOperator: '<S7>/Compare' incorporates:
     *  Constant: '<S7>/Constant'
     */
    SWC_VC_B.Compare_a1 = (VC_RemainingDist >= 0.1F);

    /* RelationalOperator: '<S1>/Relational Operator1' incorporates:
     *  Constant: '<S1>/Constant4'
     */
    SWC_VC_B.RelationalOperator1 = (SWC_VC_B.Gear_CMD != ((uint8_T)1U));

    /* Logic: '<S1>/Logical Operator9' */
    SWC_VC_B.LogicalOperator9 = !SWC_VC_B.LogicalOperator8;

    /* Logic: '<S1>/Logical Operator3' */
    SWC_VC_B.LogicalOperator7 = !*rtu_MeAP_b_VCOpPaused;

    /* Logic: '<S1>/Logical Operator7' */
    SWC_VC_B.LogicalOperator7 = (SWC_VC_B.LogicalOperator7 &&
      SWC_VC_B.LogicalOperator9 && SWC_VC_B.RelationalOperator1 &&
      SWC_VC_B.Compare_a1);

    /* DataTypeConversion: '<S1>/Data Type Conversion6' */
    SWC_VC_B.Product2_b = SWC_VC_B.LogicalOperator7;

    /* Product: '<S1>/Product2' */
    SWC_VC_B.Product2_b *= SWC_VC_B.DataTypeConversion_l;

    /* DataTypeConversion: '<Root>/Data Type Conversion26' */
    SWC_VC_B.IeAP_kph_TrgtVehSpd = SWC_VC_B.Product2_b;
    *rty_IeAP_kph_TrgtVehSpd = SWC_VC_B.IeAP_kph_TrgtVehSpd;
  } else {
    *rty_MeAP_e_GearCmd = TeAutoPark_e_GearCmd_None;
    *rty_IeAP_a_DecelMax = 0.0F;
    *rty_IeAP_a_DecelMin = 0.0F;
    *rty_IeAP_a_JerkDecelMax = 0.0F;
    *rty_IeAP_a_JerkDecelMin = 0.0F;
    *rty_IeAP_a_AcclMin = 0.0F;
    *rty_IeAP_a_AcclMax = 0.0F;
    *rty_IeAP_da_JerkAcclMax = 0.0F;
    *rty_IeAP_da_JerkAcclMin = 0.0F;
    *rty_IeAP_b_StandstillReq = false;
    *rty_IeAP_kph_TrgtVehSpd = 0.0F;
  }

  /* SignalConversion generated from: '<S27>/ SFunction ' incorporates:
   *  MATLAB Function: '<S23>/ChackParkingSpaceChangeFunc'
   */
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[0] = Ma_AP_I_PSLimFSX;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[1] = Ma_AP_I_PSLimFSY;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[2] = Ma_AP_I_PSLimFBX;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[3] = Ma_AP_I_PSLimFBY;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[4] = Ma_AP_I_PSLimRBX;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[5] = Ma_AP_I_PSLimRBY;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[6] = Ma_AP_I_PSLimRSX;
  SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[7] = Ma_AP_I_PSLimRSY;

  /* MATLAB Function: '<S23>/ChackParkingSpaceChangeFunc' incorporates:
   *  Inport: '<Root>/MeAP_b_PerpNoseIn'
   *  Inport: '<Root>/MeAP_m_ParkSpotType'
   */
  SWC_VC_B.PS_Exc = false;
  for (SWC_VC_B.i_j = 0; SWC_VC_B.i_j < 8; SWC_VC_B.i_j++) {
    SWC_VC_B.PS_diff[SWC_VC_B.i_j] =
      SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[SWC_VC_B.i_j] -
      SWC_VC_B.In1[SWC_VC_B.i_j];
  }

  SWC_VC_B.PS_move = norm_5ISqY4yY(&SWC_VC_B.PS_diff[0]);
  SWC_VC_B.varargin_1[1] = norm_5ISqY4yY(&SWC_VC_B.PS_diff[2]);
  SWC_VC_B.varargin_1[2] = norm_5ISqY4yY(&SWC_VC_B.PS_diff[4]);
  SWC_VC_B.varargin_1[3] = norm_5ISqY4yY(&SWC_VC_B.PS_diff[6]);
  SWC_VC_B.varargin_1[0] = SWC_VC_B.PS_move;
  if (!rtIsNaNF(SWC_VC_B.PS_move)) {
    SWC_VC_B.i_j = 1;
  } else {
    SWC_VC_B.i_j = 0;
    SWC_VC_B.k = 2;
    exitg1 = false;
    while ((!exitg1) && (SWC_VC_B.k < 5)) {
      if (!rtIsNaNF(SWC_VC_B.varargin_1[SWC_VC_B.k - 1])) {
        SWC_VC_B.i_j = SWC_VC_B.k;
        exitg1 = true;
      } else {
        SWC_VC_B.k++;
      }
    }
  }

  if (SWC_VC_B.i_j != 0) {
    SWC_VC_B.PS_move = SWC_VC_B.varargin_1[SWC_VC_B.i_j - 1];
    while (SWC_VC_B.i_j + 1 < 5) {
      if (SWC_VC_B.PS_move < SWC_VC_B.varargin_1[SWC_VC_B.i_j]) {
        SWC_VC_B.PS_move = SWC_VC_B.varargin_1[SWC_VC_B.i_j];
      }

      SWC_VC_B.i_j++;
    }
  }

  SWC_VC_B.lookahead_dist_wp = X_MABx -
    (SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[2] +
     SWC_VC_B.TmpSignalConversionAtSFunctionInport2_j[4]) / 2.0F;
  SWC_VC_B.x_deviation_temp = SWC_VC_B.lookahead_dist_wp;
  if (((Ap_App_ID == 3) || (Ap_App_ID == 4)) && (fabsf
       (SWC_VC_B.lookahead_dist_wp) > 0.2) && (SWC_VC_B.NextDir == 0)) {
    for (SWC_VC_B.k = 0; SWC_VC_B.k < 10; SWC_VC_B.k++) {
      if (SWC_VC_B.fi[SWC_VC_B.k] < 0) {
        SWC_VC_B.i_j = -SWC_VC_B.fi[SWC_VC_B.k];
        if (SWC_VC_B.i_j > 32767) {
          SWC_VC_B.i_j = 32767;
        }

        SWC_VC_B.y_i[SWC_VC_B.k] = (int16_T)SWC_VC_B.i_j;
      } else {
        SWC_VC_B.y_i[SWC_VC_B.k] = SWC_VC_B.fi[SWC_VC_B.k];
      }
    }

    SWC_VC_B.minV = SWC_VC_B.y_i[0];
    for (SWC_VC_B.O_WPSweepN_tmp = 0; SWC_VC_B.O_WPSweepN_tmp < 9;
         SWC_VC_B.O_WPSweepN_tmp++) {
      SWC_VC_B.minV += (real_T)SWC_VC_B.y_i[SWC_VC_B.O_WPSweepN_tmp + 1];
    }

    SWC_VC_B.PS_Exc = (((SWC_VC_B.Current_waypoint > SWC_VC_B.minV - 10.0) &&
                        (SWC_VC_B.CurrentSweepVeh <= 4)) || SWC_VC_B.PS_Exc);
  }

  if ((SWC_VC_B.PS_move >= 0.2) && (SWC_VC_B.PS_move < 0.75F)) {
    if ((PSType == 3) || (PSType == 4)) {
      SWC_VC_B.PS_Exc = ((MeAP_k_PerpNoseIn && (SWC_VC_B.CurrentSweepVeh < 2)) ||
                         (SWC_VC_B.CurrentSweepVeh < 3) || SWC_VC_B.PS_Exc);
    } else {
      SWC_VC_B.PS_Exc = ((((PSType == 1) || (PSType == 2)) &&
                          (SWC_VC_B.CurrentSweepVeh <= 4)) || SWC_VC_B.PS_Exc);
    }
  }

  /* DataTypeConversion: '<S23>/Data Type Conversion1' */
  SWC_VC_B.DataTypeConversion1_o = SWC_VC_B.PS_Exc;

  /* DataTypeConversion: '<S23>/Data Type Conversion3' */
  SWC_VC_B.DataTypeConversion3_d = SWC_VC_B.PS_move;

  /* RelationalOperator: '<S31>/Compare' incorporates:
   *  Constant: '<S31>/Constant'
   */
  SWC_VC_B.RelationalOperator1_a = (PM_CurrentSweep > ((uint8_T)0U));

  /* UnitDelay: '<S30>/Unit Delay' */
  SWC_VC_B.UnitDelay = SWC_VC_DW.UnitDelay_DSTATE_b;

  /* RelationalOperator: '<S30>/Relational Operator' */
  SWC_VC_B.UpperRelop = (PM_CurrentSweep != SWC_VC_B.UnitDelay);

  /* Logic: '<S30>/Logical Operator' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UpperRelop && SWC_VC_B.RelationalOperator1_a);

  /* RelationalOperator: '<S32>/Compare' incorporates:
   *  Constant: '<S32>/Constant'
   */
  SWC_VC_B.RelationalOperator1_a = (SWC_VC_B.NewPathAccepted > 0.0F);

  /* Logic: '<S30>/Logical Operator2' */
  SWC_VC_B.LogicalOperator2 = (SWC_VC_B.UpperRelop ||
    SWC_VC_B.RelationalOperator1_a);

  /* UnitDelay: '<S11>/Delay Input1'
   *
   * Block description for '<S11>/Delay Input1':
   *
   *  Store in Global RAM
   */
  SWC_VC_B.UpperRelop = SWC_VC_B.Compare_id;

  /* RelationalOperator: '<S41>/Compare' incorporates:
   *  Constant: '<S41>/Constant'
   */
  SWC_VC_B.Compare_id = ((int32_T)SWC_VC_B.ParkingFinished > (int32_T)false);

  /* RelationalOperator: '<S11>/FixPt Relational Operator' */
  SWC_VC_B.UpperRelop = ((int32_T)SWC_VC_B.Compare_id > (int32_T)
    SWC_VC_B.UpperRelop);

  /* Logic: '<S1>/Logical Operator1' */
  SWC_VC_B.LogicalOperator1_d = (SWC_VC_B.LogicalOperator2 ||
    SWC_VC_B.UpperRelop);

  /* UnitDelay: '<S30>/Unit Delay1' */
  SWC_VC_B.StrTqFB_Old = SWC_VC_DW.UnitDelay1_DSTATE;

  /* RelationalOperator: '<S30>/Relational Operator1' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.NewPathAccepted != SWC_VC_B.StrTqFB_Old);

  /* Logic: '<S30>/Logical Operator1' */
  SWC_VC_B.LogicalOperator1_k = (SWC_VC_B.UpperRelop &&
    SWC_VC_B.RelationalOperator1_a);

  /* UnitDelay: '<S71>/Delay Input2'
   *
   * Block description for '<S71>/Delay Input2':
   *
   *  Store in Global RAM
   */
  SWC_VC_B.Yk1_d = SWC_VC_B.DifferenceInputs2_p;

  /* SampleTimeMath: '<S71>/sample time'
   *
   * About '<S71>/sample time':
   *  y = K where K = ( w * Ts )
   */
  SWC_VC_B.sampletime_l = 0.03F;

  /* Product: '<S71>/delta rise limit' incorporates:
   *  Constant: '<S18>/Constant_RateLimit'
   */
  SWC_VC_B.deltariselimit_n = 50.0F * SWC_VC_B.sampletime_l;

  /* Abs: '<S18>/Abs1' */
  SWC_VC_B.Abs1 = fabsf(SWC_VC_B.speed_kph_MABx);

  /* Abs: '<S18>/Abs' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  SWC_VC_B.Abs_e = fabsf(DS_ANGLE);

  /* RelationalOperator: '<S75>/Relational Operator1' incorporates:
   *  Constant: '<S75>/Constant4'
   */
  SWC_VC_B.RelationalOperator1_a =
    (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp ==
     TeAP_e_SteerRatRackPinionTyp_Type_3);

  /* RelationalOperator: '<S75>/Relational Operator' incorporates:
   *  Constant: '<S75>/Constant2'
   */
  SWC_VC_B.RelationalOperator =
    (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp ==
     TeAP_e_SteerRatRackPinionTyp_Type_2);

  /* Switch: '<S18>/Switch5' incorporates:
   *  Switch: '<S18>/Switch1'
   *  Switch: '<S18>/Switch4'
   */
  if (SWC_VC_B.RelationalOperator1_a) {
    /* Lookup_n-D: '<S18>/P_gain_lookup_table_Veh98_Veh54' */
    SWC_VC_B.P_gain_lookup_table_Veh98_Veh54 = look2_iflf_binlxpw(SWC_VC_B.Abs1,
      SWC_VC_B.Abs_e, rtCP_P_gain_lookup_table_Veh98_Veh54_bp01Data,
      rtCP_P_gain_lookup_table_Veh98_Veh54_bp02Data, (&(KsAP_k_PGainLUT_TD_63C[0])),
      rtCP_P_gain_lookup_table_Veh98_Veh54_maxIndex, 4U);
    SWC_VC_B.StrTqFB_Old = SWC_VC_B.P_gain_lookup_table_Veh98_Veh54;

    /* Lookup_n-D: '<S18>/input_rate_limit_table1' */
    SWC_VC_B.input_rate_limit_table1 = look1_iflf_binlxpw(SWC_VC_B.Abs1,
      rtCP_input_rate_limit_table1_bp01Data,
      rtCP_input_rate_limit_table1_tableData, 3U);
    SWC_VC_B.Abs1_p = SWC_VC_B.input_rate_limit_table1;
  } else {
    if (SWC_VC_B.RelationalOperator) {
      /* Lookup_n-D: '<S18>/P_gain_lookup_table2' incorporates:
       *  Switch: '<S18>/Switch4'
       */
      SWC_VC_B.P_gain_lookup_table2 = look2_iflf_binlxpw(SWC_VC_B.Abs1,
        SWC_VC_B.Abs_e, rtCP_P_gain_lookup_table2_bp01Data,
        rtCP_P_gain_lookup_table2_bp02Data, (&(KsAP_k_PGainLUT_TD_60C[0])),
        rtCP_P_gain_lookup_table2_maxIndex, 4U);

      /* Switch: '<S18>/Switch4' */
      SWC_VC_B.StrTqFB_P_Old = SWC_VC_B.P_gain_lookup_table2;
    } else {
      /* RelationalOperator: '<S75>/Relational Operator2' incorporates:
       *  Constant: '<S75>/Constant3'
       *  Switch: '<S18>/Switch4'
       */
      SWC_VC_B.RelationalOperator2 =
        (rtu_MbNVM_ProxyParam->KeAP_e_SteerRatRackPinionTyp ==
         TeAP_e_SteerRatRackPinionTyp_Type_1);

      /* Switch: '<S18>/Switch' incorporates:
       *  Switch: '<S18>/Switch4'
       */
      if (SWC_VC_B.RelationalOperator2) {
        /* Lookup_n-D: '<S18>/P_gain_lookup_table3' */
        SWC_VC_B.P_gain_lookup_table3 = look2_iflf_binlxpw(SWC_VC_B.Abs1,
          SWC_VC_B.Abs_e, rtCP_P_gain_lookup_table3_bp01Data,
          rtCP_P_gain_lookup_table3_bp02Data, (&(KsAP_k_PGainLUT_TD_55C[0])),
          rtCP_P_gain_lookup_table3_maxIndex, 4U);
        SWC_VC_B.StrTqFB_P_Old_h = SWC_VC_B.P_gain_lookup_table3;
      } else {
        /* Lookup_n-D: '<S18>/P_gain_lookup_table4' */
        SWC_VC_B.P_gain_lookup_table4 = look2_iflf_binlxpw(SWC_VC_B.Abs1,
          SWC_VC_B.Abs_e, rtCP_P_gain_lookup_table4_bp01Data,
          rtCP_P_gain_lookup_table4_bp02Data, (&(KsAP_k_PGainLUT_TD_63C[0])),
          rtCP_P_gain_lookup_table4_maxIndex, 4U);
        SWC_VC_B.StrTqFB_P_Old_h = SWC_VC_B.P_gain_lookup_table4;
      }

      /* End of Switch: '<S18>/Switch' */

      /* Switch: '<S18>/Switch4' */
      SWC_VC_B.StrTqFB_P_Old = SWC_VC_B.StrTqFB_P_Old_h;
    }

    SWC_VC_B.StrTqFB_Old = SWC_VC_B.StrTqFB_P_Old;

    /* Lookup_n-D: '<S18>/input_rate_limit_table' */
    SWC_VC_B.input_rate_limit_table = look1_iflf_binlxpw(SWC_VC_B.Abs1,
      rtCP_input_rate_limit_table_bp01Data,
      rtCP_input_rate_limit_table_tableData, 3U);
    SWC_VC_B.Abs1_p = SWC_VC_B.input_rate_limit_table;
  }

  /* End of Switch: '<S18>/Switch5' */

  /* UnitDelay: '<S72>/Delay Input2'
   *
   * Block description for '<S72>/Delay Input2':
   *
   *  Store in Global RAM
   */
  SWC_VC_B.Yk1_b = SWC_VC_B.DifferenceInputs2_f;

  /* SampleTimeMath: '<S72>/sample time'
   *
   * About '<S72>/sample time':
   *  y = K where K = ( w * Ts )
   */
  SWC_VC_B.sampletime_h = 0.03F;

  /* Product: '<S72>/delta rise limit' */
  SWC_VC_B.deltariselimit_f = SWC_VC_B.Abs1_p * SWC_VC_B.sampletime_h;

  /* Logic: '<S1>/Logical Operator6' */
  SWC_VC_B.UpperRelop = !*rtu_MeAP_b_VCOpPaused;

  /* Logic: '<S1>/Logical Operator5' */
  SWC_VC_B.LogicalOperator5 = ((*rtu_MeAP_b_VCActive) && SWC_VC_B.UpperRelop);

  /* Switch: '<S19>/Switch' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  if (SWC_VC_B.LogicalOperator5) {
    SWC_VC_B.Switch_g = VC_Steer_CMD;
  } else {
    SWC_VC_B.Switch_g = DS_ANGLE;
  }

  /* End of Switch: '<S19>/Switch' */

  /* RelationalOperator: '<S78>/LowerRelop1' incorporates:
   *  Constant: '<S19>/Constant'
   */
  SWC_VC_B.UpperRelop = (SWC_VC_B.Switch_g > 500.0);

  /* RelationalOperator: '<S78>/UpperRelop' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.Switch_g < SWC_VC_ConstB.Gain);

  /* Switch: '<S78>/Switch' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch_d = (real32_T)SWC_VC_ConstB.Gain;
  } else {
    SWC_VC_B.Switch_d = SWC_VC_B.Switch_g;
  }

  /* End of Switch: '<S78>/Switch' */

  /* Switch: '<S78>/Switch2' incorporates:
   *  Constant: '<S19>/Constant'
   */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch2_p = (real32_T)500.0;
  } else {
    SWC_VC_B.Switch2_p = SWC_VC_B.Switch_d;
  }

  /* End of Switch: '<S78>/Switch2' */

  /* Sum: '<S72>/Difference Inputs1'
   *
   * Block description for '<S72>/Difference Inputs1':
   *
   *  Add in CPU
   */
  SWC_VC_B.UkYk1_n = SWC_VC_B.Switch2_p - SWC_VC_B.Yk1_b;

  /* RelationalOperator: '<S77>/LowerRelop1' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.UkYk1_n > SWC_VC_B.deltariselimit_f);

  /* Gain: '<S18>/Gain1' */
  SWC_VC_B.Abs1_p *= (-1.0F);

  /* Product: '<S72>/delta fall limit' */
  SWC_VC_B.deltafalllimit_c = SWC_VC_B.Abs1_p * SWC_VC_B.sampletime_h;

  /* RelationalOperator: '<S77>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UkYk1_n < SWC_VC_B.deltafalllimit_c);

  /* Switch: '<S77>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch_m = SWC_VC_B.deltafalllimit_c;
  } else {
    SWC_VC_B.Switch_m = SWC_VC_B.UkYk1_n;
  }

  /* End of Switch: '<S77>/Switch' */

  /* Switch: '<S77>/Switch2' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch2_c = SWC_VC_B.deltariselimit_f;
  } else {
    SWC_VC_B.Switch2_c = SWC_VC_B.Switch_m;
  }

  /* End of Switch: '<S77>/Switch2' */

  /* Sum: '<S72>/Difference Inputs2'
   *
   * Block description for '<S72>/Difference Inputs2':
   *
   *  Add in CPU
   */
  SWC_VC_B.DifferenceInputs2_f = SWC_VC_B.Switch2_c + SWC_VC_B.Yk1_b;

  /* Sum: '<S18>/Sum1' incorporates:
   *  Inport: '<Root>/MeAP_deg_StrAngl'
   */
  SWC_VC_B.Abs1_p = SWC_VC_B.DifferenceInputs2_f - DS_ANGLE;

  /* Product: '<S18>/Product' */
  SWC_VC_B.StrTqFB_Old *= SWC_VC_B.Abs1_p;

  /* Gain: '<S18>/entire_table' */
  SWC_VC_B.StrTqFB_Old *= 1.0F;

  /* Lookup_n-D: '<S18>/integrator_external_saturation_table' */
  SWC_VC_B.damping_gain_table = look1_iflf_binlxpw(SWC_VC_B.Abs1,
    rtCP_integrator_external_saturation_table_bp01Data,
    (&(KsAP_k_IntegratorExtSatTD[0])), 3U);

  /* DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  if (SWC_VC_DW.DiscreteTimeIntegrator_IC_LOADING != 0) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b =
      SWC_VC_ConstB.DataTypeConversion2;
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b >= 3.5F) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = 3.5F;
    } else {
      if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b <= (-3.5F)) {
        SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = (-3.5F);
      }
    }
  }

  if (((*rtu_MeAP_b_VCActive) &&
       (SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_f <= 0)) ||
      ((!*rtu_MeAP_b_VCActive) &&
       (SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_f == 1))) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b =
      SWC_VC_ConstB.DataTypeConversion2;
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b >= 3.5F) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = 3.5F;
    } else {
      if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b <= (-3.5F)) {
        SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = (-3.5F);
      }
    }
  }

  if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b >= 3.5F) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = 3.5F;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b <= (-3.5F)) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = (-3.5F);
    }
  }

  SWC_VC_B.DiscreteTimeIntegrator_lc = SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b;

  /* End of DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* RelationalOperator: '<S74>/LowerRelop1' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.DiscreteTimeIntegrator_lc >
    SWC_VC_B.damping_gain_table);

  /* Gain: '<S18>/Gain' */
  SWC_VC_B.Product3_o = (-1.0F) * SWC_VC_B.damping_gain_table;

  /* RelationalOperator: '<S74>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.DiscreteTimeIntegrator_lc <
    SWC_VC_B.Product3_o);

  /* Switch: '<S74>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch_do = SWC_VC_B.Product3_o;
  } else {
    SWC_VC_B.Switch_do = SWC_VC_B.DiscreteTimeIntegrator_lc;
  }

  /* End of Switch: '<S74>/Switch' */

  /* Switch: '<S74>/Switch2' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch2_i = SWC_VC_B.damping_gain_table;
  } else {
    SWC_VC_B.Switch2_i = SWC_VC_B.Switch_do;
  }

  /* End of Switch: '<S74>/Switch2' */

  /* Lookup_n-D: '<S18>/differential_gain_table1' */
  SWC_VC_B.differential_gain_table1 = look1_iflf_binlxpw(SWC_VC_B.Abs1,
    rtCP_differential_gain_table1_bp01Data, (&(KsAP_k_DGainLUT_TD_63C[0])), 3U);

  /* Switch: '<S18>/Switch3' incorporates:
   *  Switch: '<S18>/Switch7'
   */
  if (SWC_VC_B.RelationalOperator1_a) {
    SWC_VC_B.Product3_o = SWC_VC_B.differential_gain_table1;
  } else {
    if (SWC_VC_B.RelationalOperator) {
      /* Switch: '<S18>/Switch7' */
      SWC_VC_B.Switch7_g = SWC_VC_B.differential_gain_table1;
    } else {
      /* Lookup_n-D: '<S18>/differential_gain_table' incorporates:
       *  Switch: '<S18>/Switch7'
       */
      SWC_VC_B.differential_gain_table = look1_iflf_binlxpw(SWC_VC_B.Abs1,
        rtCP_differential_gain_table_bp01Data, (&(KsAP_k_DGainLUT_TD_55C[0])),
        3U);

      /* Switch: '<S18>/Switch7' */
      SWC_VC_B.Switch7_g = SWC_VC_B.differential_gain_table;
    }

    SWC_VC_B.Product3_o = SWC_VC_B.Switch7_g;
  }

  /* End of Switch: '<S18>/Switch3' */

  /* UnitDelay: '<S18>/Unit Delay1' */
  SWC_VC_B.damping_gain_table = SWC_VC_DW.UnitDelay1_DSTATE_e;

  /* Sum: '<S18>/Subtract2' */
  SWC_VC_B.damping_gain_table = SWC_VC_B.DifferenceInputs2_f -
    SWC_VC_B.damping_gain_table;

  /* Gain: '<S18>/inverse_dt1' */
  SWC_VC_B.damping_gain_table *= 33.3333321F;

  /* DataTypeConversion: '<S1>/Data Type Conversion9' */
  SWC_VC_B.Delay1 = *rtu_IeVBII_deg_StrWhlSpd;

  /* Sum: '<S18>/Sum2' */
  SWC_VC_B.damping_gain_table -= SWC_VC_B.Delay1;

  /* Product: '<S18>/Product3' */
  SWC_VC_B.Product3_o *= SWC_VC_B.damping_gain_table;

  /* Lookup_n-D: '<S18>/damping_gain_table' */
  SWC_VC_B.damping_gain_table = look1_iflf_binlxpw(SWC_VC_B.Abs1,
    rtCP_damping_gain_table_bp01Data, (&(KsAP_k_DampingGainTD[0])), 3U);

  /* Product: '<S18>/Product1' */
  SWC_VC_B.Delay1 *= SWC_VC_B.damping_gain_table;

  /* Sum: '<S18>/Add' */
  SWC_VC_B.StrTqFB_Old = ((SWC_VC_B.StrTqFB_Old + SWC_VC_B.Switch2_i) +
    SWC_VC_B.Product3_o) + SWC_VC_B.Delay1;

  /* Sum: '<S18>/Add1' incorporates:
   *  Constant: '<S18>/Constant'
   */
  SWC_VC_B.StrCmdTqLmtOld = 0.0F + SWC_VC_B.StrTqFB_Old;

  /* Sum: '<S71>/Difference Inputs1'
   *
   * Block description for '<S71>/Difference Inputs1':
   *
   *  Add in CPU
   */
  SWC_VC_B.UkYk1_ns = SWC_VC_B.StrCmdTqLmtOld - SWC_VC_B.Yk1_d;

  /* RelationalOperator: '<S76>/LowerRelop1' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.UkYk1_ns > SWC_VC_B.deltariselimit_n);

  /* Product: '<S71>/delta fall limit' */
  SWC_VC_B.deltafalllimit_d = SWC_VC_ConstB.Gain4 * SWC_VC_B.sampletime_l;

  /* RelationalOperator: '<S76>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UkYk1_ns < SWC_VC_B.deltafalllimit_d);

  /* Switch: '<S76>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch_n = SWC_VC_B.deltafalllimit_d;
  } else {
    SWC_VC_B.Switch_n = SWC_VC_B.UkYk1_ns;
  }

  /* End of Switch: '<S76>/Switch' */

  /* Switch: '<S76>/Switch2' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch2_j = SWC_VC_B.deltariselimit_n;
  } else {
    SWC_VC_B.Switch2_j = SWC_VC_B.Switch_n;
  }

  /* End of Switch: '<S76>/Switch2' */

  /* Sum: '<S71>/Difference Inputs2'
   *
   * Block description for '<S71>/Difference Inputs2':
   *
   *  Add in CPU
   */
  SWC_VC_B.DifferenceInputs2_p = SWC_VC_B.Switch2_j + SWC_VC_B.Yk1_d;

  /* RelationalOperator: '<S73>/LowerRelop1' incorporates:
   *  Constant: '<S18>/Constant_SaturationLimit'
   */
  SWC_VC_B.Compare_lw = (SWC_VC_B.DifferenceInputs2_p > KeAP_M_StrTrqValLimit);

  /* Gain: '<S18>/Gain3' incorporates:
   *  Constant: '<S18>/Constant_SaturationLimit'
   */
  SWC_VC_B.Delay1 = (-1.0F) * KeAP_M_StrTrqValLimit;

  /* RelationalOperator: '<S73>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.DifferenceInputs2_p < SWC_VC_B.Delay1);

  /* Switch: '<S73>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch_no = SWC_VC_B.Delay1;
  } else {
    SWC_VC_B.Switch_no = SWC_VC_B.DifferenceInputs2_p;
  }

  /* End of Switch: '<S73>/Switch' */

  /* Switch: '<S73>/Switch2' incorporates:
   *  Constant: '<S18>/Constant_SaturationLimit'
   */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch2_d = KeAP_M_StrTrqValLimit;
  } else {
    SWC_VC_B.Switch2_d = SWC_VC_B.Switch_no;
  }

  /* End of Switch: '<S73>/Switch2' */

  /* BusCreator: '<S1>/Bus Creator' */
  SWC_VC_B.IbVC_DebugOut.X_MABx = X_MABx;
  SWC_VC_B.IbVC_DebugOut.Y_MABx = Y_MABx;
  SWC_VC_B.IbVC_DebugOut.heading_MABx = heading_MABx;
  SWC_VC_B.IbVC_DebugOut.Str_Trq_CMD = SWC_VC_B.Switch2_d;
  SWC_VC_B.IbVC_DebugOut.VC_RemainingDist = VC_RemainingDist;
  SWC_VC_B.IbVC_DebugOut.VC_PathDev = VC_PathDev;
  SWC_VC_B.IbVC_DebugOut.VC_Head_Dev = VC_Head_Dev;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFSX = Ma_AP_I_PSLimFSX;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFSY = Ma_AP_I_PSLimFSY;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFBX = Ma_AP_I_PSLimFBX;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFBY = Ma_AP_I_PSLimFBY;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRSX = Ma_AP_I_PSLimRSX;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRSY = Ma_AP_I_PSLimRSY;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRBX = Ma_AP_I_PSLimRBX;
  SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRBY = Ma_AP_I_PSLimRBY;
  SWC_VC_B.IbVC_DebugOut.PM_CurrentSweep = PM_CurrentSweep;
  SWC_VC_B.IbVC_DebugOut.PM_RegenPath = PM_RegenPath;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_X_MABx = SWC_VC_B.IbVC_DebugOut.X_MABx;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBX = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFBX;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFBY = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFBY;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSX = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRSX;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRSY = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRSY;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBX = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRBX;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimRBY = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimRBY;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_PM_CurrentSweep = SWC_VC_B.IbVC_DebugOut.PM_CurrentSweep;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_PM_RegenPath = SWC_VC_B.IbVC_DebugOut.PM_RegenPath;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Y_MABx = SWC_VC_B.IbVC_DebugOut.Y_MABx;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_heading_MABx = SWC_VC_B.IbVC_DebugOut.heading_MABx;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Str_Trq_CMD = SWC_VC_B.IbVC_DebugOut.Str_Trq_CMD;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_VC_RemainingDist = SWC_VC_B.IbVC_DebugOut.VC_RemainingDist;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_VC_PathDev = SWC_VC_B.IbVC_DebugOut.VC_PathDev;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_VC_Head_Dev = SWC_VC_B.IbVC_DebugOut.VC_Head_Dev;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSX = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFSX;

  /* SignalConversion generated from: '<Root>/IbVC_DebugOut' */
  *rty_IbVC_DebugOut_Ma_AP_I_PSLimFSY = SWC_VC_B.IbVC_DebugOut.Ma_AP_I_PSLimFSY;

  /* Switch: '<S1>/Switch' */
  if (*rtu_IeVBII_b_ActvParkMode) {
    /* DataTypeConversion: '<S1>/Data Type Conversion' */
    SWC_VC_B.DataTypeConversion_o = *rtu_MeAP_b_VCActive;

    /* DataTypeConversion: '<S1>/Data Type Conversion1' */
    SWC_VC_B.DataTypeConversion1_e = SWC_VC_B.Switch2_d;

    /* Product: '<S1>/Product' */
    SWC_VC_B.Product_hk = SWC_VC_B.DataTypeConversion1_e *
      SWC_VC_B.DataTypeConversion_o;
    SWC_VC_B.Switch_n4 = SWC_VC_B.Product_hk;
  } else {
    /* DataTypeConversion: '<S1>/Data Type Conversion7' */
    SWC_VC_B.DataTypeConversion7 = SWC_VC_B.LogicalOperator5;

    /* DataTypeConversion: '<S1>/Data Type Conversion8' */
    SWC_VC_B.DataTypeConversion8 = SWC_VC_B.Switch2_d;

    /* Product: '<S1>/Product3' */
    SWC_VC_B.Product3 = SWC_VC_B.DataTypeConversion8 *
      SWC_VC_B.DataTypeConversion7;
    SWC_VC_B.Switch_n4 = SWC_VC_B.Product3;
  }

  /* End of Switch: '<S1>/Switch' */

  /* UnitDelay: '<S14>/Delay Input2'
   *
   * Block description for '<S14>/Delay Input2':
   *
   *  Store in Global RAM
   */
  SWC_VC_B.Yk1_c = SWC_VC_B.DifferenceInputs2_h;

  /* Sum: '<S14>/Difference Inputs1'
   *
   * Block description for '<S14>/Difference Inputs1':
   *
   *  Add in CPU
   */
  SWC_VC_B.UkYk1_j = SWC_VC_B.Switch_n4 - SWC_VC_B.Yk1_c;

  /* SampleTimeMath: '<S14>/sample time'
   *
   * About '<S14>/sample time':
   *  y = K where K = ( w * Ts )
   */
  SWC_VC_B.sampletime_p = 0.03F;

  /* Product: '<S14>/delta rise limit' incorporates:
   *  Constant: '<S1>/Constant_RateLimit'
   */
  SWC_VC_B.deltariselimit_o = KeAP_nm_TrqCmdRateLimThd * SWC_VC_B.sampletime_p;

  /* RelationalOperator: '<S65>/LowerRelop1' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.UkYk1_j > SWC_VC_B.deltariselimit_o);

  /* Gain: '<S1>/Gain4' incorporates:
   *  Constant: '<S1>/Constant_RateLimit'
   */
  SWC_VC_B.Delay1 = (-1.0F) * KeAP_nm_TrqCmdRateLimThd;

  /* Product: '<S14>/delta fall limit' */
  SWC_VC_B.deltafalllimit_h = SWC_VC_B.Delay1 * SWC_VC_B.sampletime_p;

  /* RelationalOperator: '<S65>/UpperRelop' */
  SWC_VC_B.UpperRelop = (SWC_VC_B.UkYk1_j < SWC_VC_B.deltafalllimit_h);

  /* Switch: '<S65>/Switch' */
  if (SWC_VC_B.UpperRelop) {
    SWC_VC_B.Switch_i = SWC_VC_B.deltafalllimit_h;
  } else {
    SWC_VC_B.Switch_i = SWC_VC_B.UkYk1_j;
  }

  /* End of Switch: '<S65>/Switch' */

  /* Switch: '<S65>/Switch2' */
  if (SWC_VC_B.Compare_lw) {
    SWC_VC_B.Switch2_g = SWC_VC_B.deltariselimit_o;
  } else {
    SWC_VC_B.Switch2_g = SWC_VC_B.Switch_i;
  }

  /* End of Switch: '<S65>/Switch2' */

  /* Sum: '<S14>/Difference Inputs2'
   *
   * Block description for '<S14>/Difference Inputs2':
   *
   *  Add in CPU
   */
  SWC_VC_B.DifferenceInputs2_h = SWC_VC_B.Switch2_g + SWC_VC_B.Yk1_c;

  /* DataTypeConversion: '<Root>/Data Type Conversion6' */
  *rty_IeAP_nm_StrwTrqReq = SWC_VC_B.DifferenceInputs2_h;

  /* Lookup_n-D: '<S18>/integrator_gain_table1' */
  SWC_VC_B.integrator_gain_table1 = look1_iflf_binlxpw(SWC_VC_B.Abs1,
    rtCP_integrator_gain_table1_bp01Data, (&(KsAP_k_IGainLUT_TD_63C[0])), 3U);

  /* Switch: '<S18>/Switch6' incorporates:
   *  Switch: '<S18>/Switch2'
   */
  if (SWC_VC_B.RelationalOperator1_a) {
    SWC_VC_B.Delay1 = SWC_VC_B.integrator_gain_table1;
  } else {
    if (SWC_VC_B.RelationalOperator) {
      /* Switch: '<S18>/Switch2' */
      SWC_VC_B.Switch2_a = SWC_VC_B.integrator_gain_table1;
    } else {
      /* Lookup_n-D: '<S18>/integrator_gain_table' incorporates:
       *  Switch: '<S18>/Switch2'
       */
      SWC_VC_B.integrator_gain_table = look1_iflf_binlxpw(SWC_VC_B.Abs1,
        rtCP_integrator_gain_table_bp01Data, (&(KsAP_k_IGainLUT_TD_55C[0])), 3U);

      /* Switch: '<S18>/Switch2' */
      SWC_VC_B.Switch2_a = SWC_VC_B.integrator_gain_table;
    }

    SWC_VC_B.Delay1 = SWC_VC_B.Switch2_a;
  }

  /* End of Switch: '<S18>/Switch6' */

  /* Product: '<S18>/Product2' */
  SWC_VC_B.Product2 = SWC_VC_B.Delay1 * SWC_VC_B.Abs1_p;

  /* Abs: '<S1>/Abs1' */
  SWC_VC_B.Abs1_p = fabsf(SWC_VC_B.Abs1_p);

  /* RelationalOperator: '<S6>/Compare' incorporates:
   *  Constant: '<S6>/Constant'
   */
  MeAP_b_SteerActionReq = (SWC_VC_B.Abs1_p >= KeAP_deg_SteerAngelDiffThd);

  /* DataTypeConversion: '<Root>/Data Type Conversion24' */
  *rty_MeAP_b_SteerActionReq = MeAP_b_SteerActionReq;

  /* Gain: '<S1>/steer_cmd_angle' */
  SWC_VC_B.steer_cmd_angle = 1.0F * SWC_VC_B.Switch2_p;

  /* DataTypeConversion: '<Root>/Data Type Conversion12' */
  *rty_MeAP_b_ManeuverSuccess = SWC_VC_B.ParkingFinished;

  /* DataTypeConversion: '<Root>/Data Type Conversion10' */
  *rty_MeAP_e_Park_state = SWC_VC_B.APX_Park_Stat;

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  Logic: '<S26>/Logical Operator3'
   */
  SWC_VC_B.LogicalOperator3_p = ((*rtu_MeAP_b_VCActive) &&
    SWC_VC_B.LogicalOperator3_p);

  /* Logic: '<S26>/Logical Operator1' */
  SWC_VC_B.LogicalOperator1_m = (SWC_VC_B.LogicalOperator ||
    SWC_VC_B.LogicalOperator3_p);

  /* RelationalOperator: '<S8>/Compare' incorporates:
   *  Constant: '<S8>/Constant'
   */
  MeAP_b_PosMet = (VC_RemainingDist <= 30.0F);

  /* DataTypeConversion: '<Root>/Data Type Conversion25' */
  *rty_MeAP_b_PosMet = MeAP_b_PosMet;

  /* RelationalOperator: '<S53>/Compare' incorporates:
   *  Constant: '<S53>/Constant'
   */
  SWC_VC_B.Compare_lw = (VC_RemainingDist <= 40.0F);

  /* RelationalOperator: '<S55>/Compare' incorporates:
   *  Constant: '<S55>/Constant'
   */
  SWC_VC_B.RelationalOperator1_a = (SWC_VC_B.ColDist <= ((uint8_T)40U));

  /* Logic: '<S13>/Logical Operator' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.Compare_lw || SWC_VC_B.RelationalOperator1_a);

  /* DataTypeConversion: '<S13>/Data Type Conversion' */
  SWC_VC_B.DataTypeConversion_a = SWC_VC_B.Dir;

  /* Switch: '<S13>/SwitchActive1' */
  if (SWC_VC_B.Compare_lw) {
    /* Gain: '<S13>/Gain' */
    SWC_VC_B.Gain_l = (int16_T)((-128) * SWC_VC_B.DataTypeConversion_a);
    SWC_VC_B.SwitchActive1 = (real_T)SWC_VC_B.Gain_l * 0.0078125;
  } else {
    SWC_VC_B.SwitchActive1 = SWC_VC_B.DataTypeConversion_a;
  }

  /* End of Switch: '<S13>/SwitchActive1' */

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  *rty_MeAP_deg_StrCmd = VC_Steer_CMD;

  /* Abs: '<S24>/Abs' */
  SWC_VC_B.Delay1 = fabsf(VC_PathDev);

  /* RelationalOperator: '<S24>/Relational Operator' incorporates:
   *  Constant: '<S24>/Constant'
   */
  SWC_VC_B.Compare_lw = (SWC_VC_B.Delay1 >= 30.0);

  /* Abs: '<S24>/Abs1' */
  SWC_VC_B.Delay1 = fabsf(VC_Head_Dev);

  /* RelationalOperator: '<S24>/Relational Operator1' incorporates:
   *  Constant: '<S24>/Constant1'
   */
  SWC_VC_B.RelationalOperator1_a = (SWC_VC_B.Delay1 >= 15.0);

  /* Logic: '<S24>/Logical Operator' */
  SWC_VC_B.Compare_lw = (SWC_VC_B.Compare_lw || SWC_VC_B.RelationalOperator1_a);

  /* Logic: '<S24>/Logical Operator1' incorporates:
   *  Constant: '<S24>/C_DevCalc.PosDev_Activate'
   */
  SWC_VC_B.LogicalOperator1_kg = (SWC_VC_B.Compare_lw && (1.0 != 0.0));

  /* RateTransition: '<S16>/Rate Transition' */
  SWC_VC_B.RateTransition_c = PP_state;

  /* RelationalOperator: '<S67>/Compare' incorporates:
   *  Constant: '<S67>/Constant'
   */
  SWC_VC_B.Compare_lw = (SWC_VC_B.RateTransition_c == 5);

  /* Switch: '<S16>/Switch' incorporates:
   *  Constant: '<S16>/Constant'
   */
  if (SWC_VC_B.Compare_lw) {
    /* RelationalOperator: '<S69>/Compare' incorporates:
     *  Constant: '<S69>/Constant'
     */
    SWC_VC_B.Compare = (uint8_T)(Ma_AP_I_PSLimFSY < 0.0F);

    /* RelationalOperator: '<S68>/Compare' incorporates:
     *  Constant: '<S68>/Constant'
     */
    SWC_VC_B.Compare_p = (uint8_T)(Ma_AP_I_PSLimFSY > 0.0F);

    /* Gain: '<S16>/Gain' */
    SWC_VC_B.Gain_a = (uint16_T)((uint32_T)((uint8_T)128U) * SWC_VC_B.Compare_p);

    /* Sum: '<S16>/Add' */
    SWC_VC_B.Add_h = (uint16_T)(((uint32_T)SWC_VC_B.Compare << 6) +
      SWC_VC_B.Gain_a);
    SWC_VC_B.Product_a = (real_T)SWC_VC_B.Add_h * 0.015625;
  } else {
    SWC_VC_B.Product_a = 0.0;
  }

  /* End of Switch: '<S16>/Switch' */

  /* DataTypeConversion: '<S16>/Data Type Conversion' */
  SWC_VC_B.DataTypeConversion = *rtu_MeAP_b_VCActive;

  /* Product: '<S16>/Product' */
  SWC_VC_B.Product_a *= SWC_VC_B.DataTypeConversion;

  /* DataTypeConversion: '<Root>/Data Type Conversion5' */
  SWC_VC_B.minV = floor(SWC_VC_B.Product_a);
  if (rtIsNaN(SWC_VC_B.minV) || rtIsInf(SWC_VC_B.minV)) {
    SWC_VC_B.minV = 0.0;
  } else {
    SWC_VC_B.minV = fmod(SWC_VC_B.minV, 4.294967296E+9);
  }

  *rty_IeAP_e_TurnIndicReq = SWC_VC_B.minV < 0.0 ? -(int32_T)(uint32_T)
    -SWC_VC_B.minV : (int32_T)(uint32_T)SWC_VC_B.minV;

  /* End of DataTypeConversion: '<Root>/Data Type Conversion5' */

  /* DataTypeConversion: '<Root>/Data Type Conversion13' */
  *rty_MeAP_b_ManeuverAbort = PP_Abort;

  /* DataTypeConversion: '<Root>/Data Type Conversion15' */
  *rty_MeAP_e_PP_state = PP_state;

  /* RelationalOperator: '<S42>/Compare' incorporates:
   *  Constant: '<S42>/Constant'
   */
  SWC_VC_B.Compare_l = (SWC_VC_B.DiscreteTimeIntegrator == 0.0F);

  /* RelationalOperator: '<S44>/Compare' incorporates:
   *  Constant: '<S44>/Constant'
   */
  SWC_VC_B.Compare_a = (SWC_VC_B.Delay8[1] == 0.0F);

  /* RelationalOperator: '<S75>/Relational Operator3' incorporates:
   *  Constant: '<S75>/Constant'
   */
  SWC_VC_B.RelationalOperator3 = (rtu_MbNVM_ProxyParam->KeAP_k_VariantID ==
    ((uint8_T)9U));

  /* Constant: '<S24>/PP_REPLAN_ORNT_DEVIATION' */
  SWC_VC_B.PP_REPLAN_ORNT_DEVIATION = 3.0;

  /* Constant: '<S24>/PP_REPLAN_POS_DEVIATION' */
  SWC_VC_B.PP_REPLAN_POS_DEVIATION = 15.0;

  /* Constant: '<S61>/Constant' */
  SWC_VC_B.Constant = Ke_AP_deg_MaxWheelAngle;

  /* Constant: '<S113>/VehSpdMax_DeadSteer1' */
  SWC_VC_B.VehSpdMax_DeadSteer1 = 0.0F;

  /* Constant: '<S108>/Veh_SpdMax_Rq_Def' */
  SWC_VC_B.Veh_SpdMax_Rq_Def = 7.5F;

  /* Delay: '<S3>/Delay' */
  SWC_VC_B.Delay1 = SWC_VC_B.speed;

  /* DataTypeConversion: '<S3>/Cast To Single' */
  SWC_VC_B.CastToSingle = SWC_VC_B.Delay1;

  /* Delay: '<S3>/Delay1' */
  SWC_VC_B.Delay1 = SWC_VC_B.distance;

  /* DataTypeConversion: '<S3>/Cast To Single1' */
  SWC_VC_B.CastToSingle1 = SWC_VC_B.Delay1;

  /* MATLAB Function: '<S3>/MATLAB Function' incorporates:
   *  Constant: '<S3>/const_dist'
   *  Constant: '<S3>/const_speed'
   */
  SWC_VC_B.lookahead_long = SWC_VC_B.CastToSingle;
  SWC_VC_B.lookahead_dist_wp = SWC_VC_B.CastToSingle1;
  if (SWC_VC_B.CastToSingle == 0.0F) {
    SWC_VC_B.lookahead_long = (real32_T)2.0;
    SWC_VC_B.lookahead_dist_wp = (real32_T)500.0;
  }

  if (*rtu_MeAP_b_VCActive) {
    SWC_VC_B.speed = SWC_VC_B.lookahead_long * 0.9F;
    SWC_VC_B.distance = SWC_VC_B.lookahead_dist_wp * 0.9F;
    if (SWC_VC_B.distance < 10.0F) {
      SWC_VC_B.speed = 0.0F;
      SWC_VC_B.distance = 0.0F;
    }
  } else {
    SWC_VC_B.speed = 0.0F;
    SWC_VC_B.distance = 0.0F;
  }

  /* End of MATLAB Function: '<S3>/MATLAB Function' */
  /* Update for Delay: '<S21>/Delay' */
  SWC_VC_DW.Delay_DSTATE_a = PM_CurrentSweep;

  /* Update for Delay: '<S1>/Delay' */
  SWC_VC_DW.Delay_DSTATE_n = PP_state;

  /* Update for Delay: '<S12>/Delay4' */
  SWC_VC_DW.Delay4_DSTATE = SWC_VC_B.DataTypeConversion1_h;

  /* Update for Delay: '<S12>/Delay8' */
  SWC_VC_DW.Delay8_DSTATE[0] = SWC_VC_B.DiscreteTimeIntegrator1[0];

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[0] += 0.03F * SWC_VC_B.dx_dy_m[0];

  /* Update for Delay: '<S12>/Delay8' */
  SWC_VC_DW.Delay8_DSTATE[1] = SWC_VC_B.DiscreteTimeIntegrator1[1];

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator1' */
  SWC_VC_DW.DiscreteTimeIntegrator1_DSTATE[1] += 0.03F * SWC_VC_B.dx_dy_m[1];
  SWC_VC_DW.DiscreteTimeIntegrator1_PrevResetState = (int8_T)
    SWC_VC_B.LogicalOperator1;

  /* Update for DiscreteIntegrator: '<S12>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE += 0.03F * SWC_VC_B.d_heading_deg;
  SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState = (int8_T)
    SWC_VC_B.LogicalOperator1;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  SWC_VC_DW.UnitDelay_DSTATE_d = PM_RegenPath;

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  SWC_VC_DW.UnitDelay1_DSTATE_b = PM_CurrentSweep;

  /* Update for UnitDelay: '<S13>/Unit Delay2' */
  SWC_VC_DW.UnitDelay2_DSTATE = SWC_VC_B.CurrentSweepVeh;

  /* Update for Delay: '<S12>/Delay1' */
  SWC_VC_DW.icLoad = 0U;
  SWC_VC_DW.Delay1_DSTATE_n = SWC_VC_B.RateTransition18;

  /* Update for Delay: '<S12>/Delay2' */
  SWC_VC_DW.icLoad_l = 0U;
  SWC_VC_DW.Delay2_DSTATE = SWC_VC_B.RateTransition12;

  /* Update for UnitDelay: '<S131>/Unit Delay' */
  SWC_VC_DW.UnitDelay_DSTATE_j = SWC_VC_B.RateTransition1_a;

  /* Update for Delay: '<S108>/Delay One Step' */
  SWC_VC_DW.DelayOneStep_DSTATE_c = SWC_VC_B.DesiredDir;

  /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S113>/RampGrd'
   */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d += 0.03F * (-1.0F);
  if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_d = (-1.0F);
    }
  }

  SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_g = (int8_T)SWC_VC_B.Delay1_k;

  /* End of Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator' */

  /* Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' incorporates:
   *  Constant: '<S113>/RampGrd2'
   */
  SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE += 0.03F * (-1.0F);
  if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE >= rtInfF) {
    SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = rtInfF;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE <= (-1.0F)) {
      SWC_VC_DW.DiscreteTimeIntegrator2_DSTATE = (-1.0F);
    }
  }

  SWC_VC_DW.DiscreteTimeIntegrator2_PrevResetState = (int8_T)SWC_VC_B.Delay1_k;

  /* End of Update for DiscreteIntegrator: '<S113>/Discrete-Time Integrator2' */

  /* Update for Memory: '<S111>/Memory' */
  SWC_VC_DW.Memory_PreviousInput = SWC_VC_B.RateTransition1_a;

  /* Update for DiscreteIntegrator: '<S111>/Discrete-Time Integrator' incorporates:
   *  Constant: '<S111>/Constant'
   */
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_p += 0.03F * 1.0F;

  /* Update for Memory: '<S111>/Memory1' */
  SWC_VC_DW.Memory1_PreviousInput = SWC_VC_B.brakeReleaseTime;

  /* Update for Memory: '<S111>/Memory2' */
  SWC_VC_DW.Memory2_PreviousInput = SWC_VC_B.LogicalOperator_c;

  /* Update for Delay: '<S1>/Delay1' */
  for (SWC_VC_B.O_WPSweepN_tmp = 0; SWC_VC_B.O_WPSweepN_tmp < 14;
       SWC_VC_B.O_WPSweepN_tmp++) {
    SWC_VC_DW.Delay1_DSTATE_c[SWC_VC_B.O_WPSweepN_tmp] =
      SWC_VC_DW.Delay1_DSTATE_c[SWC_VC_B.O_WPSweepN_tmp + 1];
  }

  SWC_VC_DW.Delay1_DSTATE_c[14] = SWC_VC_B.Gear_CMD;

  /* End of Update for Delay: '<S1>/Delay1' */

  /* Update for UnitDelay: '<S30>/Unit Delay' */
  SWC_VC_DW.UnitDelay_DSTATE_b = PM_CurrentSweep;

  /* Update for UnitDelay: '<S30>/Unit Delay1' */
  SWC_VC_DW.UnitDelay1_DSTATE = SWC_VC_B.NewPathAccepted;

  /* Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */
  SWC_VC_DW.DiscreteTimeIntegrator_IC_LOADING = 0U;
  SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b += 0.03F * SWC_VC_B.Product2;
  if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b >= 3.5F) {
    SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = 3.5F;
  } else {
    if (SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b <= (-3.5F)) {
      SWC_VC_DW.DiscreteTimeIntegrator_DSTATE_b = (-3.5F);
    }
  }

  SWC_VC_DW.DiscreteTimeIntegrator_PrevResetState_f = (int8_T)
    *rtu_MeAP_b_VCActive;

  /* End of Update for DiscreteIntegrator: '<S18>/Discrete-Time Integrator' */

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  SWC_VC_DW.UnitDelay1_DSTATE_e = SWC_VC_B.DifferenceInputs2_f;
}

/* Model initialize function */
void SWC_VC_initialize(const char_T **rt_errorStatus)
{
  RT_MODEL_SWC_VC_T *const SWC_VC_M = &(SWC_VC_MdlrefDW.rtm);

  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatusPointer(SWC_VC_M, rt_errorStatus);

  /* block I/O */

  /* custom signals */
  MeAP_m_VehWheelbase = 3.898F;
  MeAP_m_VehFrontOverhang = 0.9933F;
  MeAP_m_VehRearOverhang = 1.2365F;
  MeAP_m_VehWidth = 2.4815F;
  SWC_VC_PrevZCX.CollDistAtPreCollFlagEntry_Trig_ZCE = POS_ZCSIG;
  SWC_VC_PrevZCX.RemainDistAtPreCollFlagEntry_Trig_ZCE = POS_ZCSIG;
  SWC_VC_PrevZCX.PathSeparation_Trig_ZCE = POS_ZCSIG;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
