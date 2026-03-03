/*
 * File: DT24_CVADAS_AP_CodGen_private.h
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

#ifndef RTW_HEADER_DT24_CVADAS_AP_CodGen_private_h_
#define RTW_HEADER_DT24_CVADAS_AP_CodGen_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "DT24_CVADAS_AP_CodGen.h"
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

extern const uint32_T rtCP_pooled_MiCERyeYSjrH;

#define rtCP_Gain1_Gain                rtCP_pooled_MiCERyeYSjrH  /* Computed Parameter: rtCP_Gain1_Gain
                                                                  * Referenced by: '<S12>/Gain1'
                                                                  */

extern void DT24_CVADAS_AP_CodGen_FIL_Blk(const real32_T rtu_RadialDist[12],
  uint8_T rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, uint8_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_FIL_Blk_DT24_CVADAS_AP_CodGen_T *localDW);
extern void DT24_CVADAS_AP_CodGen_FSL_Blk(const real32_T rtu_RadialDist[12],
  uint8_T rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, boolean_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_FSL_Blk_DT24_CVADAS_AP_CodGen_T *localDW);
extern void DT24_CVADAS_AP_CodGen_RIL_Blk(const real32_T rtu_RadialDist[12],
  uint8_T rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, uint8_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_RIL_Blk_DT24_CVADAS_AP_CodGen_T *localDW);
extern void DT24_CVADAS_AP_CodGen_RSL_Blk(const real32_T rtu_RadialDist[12],
  uint8_T rtu_sensor_index, real32_T rtu_Global_x, uint8_T rtu_MeAP_b_Standstill,
  TeAP_e_FiltdGearState rtu_MeAP_e_FiltdTrgtGear, boolean_T
  rtu_MeAP_b_ArcTrackFlag, const real32_T rtu_PrevRadialDist[12], uint8_T
  *rty_SensorBlockStatus, DW_RSL_Blk_DT24_CVADAS_AP_CodGen_T *localDW);
extern void DT24_CVADAS_AP_CodGen_NeighbourHoodCheck(const
  US_S_PointOutputBuff_t rtu_PointMapData[96], const US_S_PointOutputBuff_t
  *rtu_CurrentPoint, uint8_T rtu_EgoPtHeight, boolean_T *rty_DiscardPoint,
  B_NeighbourHoodCheck_DT24_CVADAS_AP_CodGen_T *localB);

#endif                         /* RTW_HEADER_DT24_CVADAS_AP_CodGen_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
