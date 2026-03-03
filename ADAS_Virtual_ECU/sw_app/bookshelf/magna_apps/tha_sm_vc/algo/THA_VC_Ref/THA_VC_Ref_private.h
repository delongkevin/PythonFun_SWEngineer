/*
 * File: THA_VC_Ref_private.h
 *
 * Code generated for Simulink model 'THA_VC_Ref'.
 *
 * Model version                  : 1.2042
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Aug  7 17:42:34 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Custom Processor->Custom Processor
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_THA_VC_Ref_private_h_
#define RTW_HEADER_THA_VC_Ref_private_h_
#include "rtwtypes.h"
#include "zero_crossing_types.h"
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

/* Constant parameters (default storage) */
typedef struct {
  /* Computed Parameter: uDLookupTable_bp01Data
   * Referenced by: '<S17>/1-D Lookup Table'
   */
  real32_T uDLookupTable_bp01Data[6];

  /* Expression: Steering_Data_55C(:,4) % 4 represents left
   * Referenced by: '<S64>/1D_LUT_LEFT_55C'
   */
  real32_T uD_LUT_LEFT_55C_tableData[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S64>/1D_LUT_CENTER_55C'
   *   '<S64>/1D_LUT_LEFT_55C'
   *   '<S64>/1D_LUT_RIGHT_55C'
   */
  real32_T pooled13[9];

  /* Expression: Steering_Data_55C(:,3) % 3 represents right
   * Referenced by: '<S64>/1D_LUT_RIGHT_55C'
   */
  real32_T uD_LUT_RIGHT_55C_tableData[9];

  /* Expression: Steering_Correction_55C(:,2) % 2 represents correction
   * Referenced by: '<S64>/1D_LUT_CORRECTION_55C'
   */
  real32_T uD_LUT_CORRECTION_55C_tableData[8];

  /* Expression: Steering_Correction_55C(:,1) % 1 represents steer
   * Referenced by: '<S64>/1D_LUT_CORRECTION_55C'
   */
  real32_T uD_LUT_CORRECTION_55C_bp01Data[8];

  /* Expression: Steering_Data_55C(:,2) % 2 represents center
   * Referenced by: '<S64>/1D_LUT_CENTER_55C'
   */
  real32_T uD_LUT_CENTER_55C_tableData[9];

  /* Expression: Steering_Data_60C(:,4) % 4 represents left
   * Referenced by: '<S62>/1D_LUT_LEFT_60C'
   */
  real32_T uD_LUT_LEFT_60C_tableData[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S62>/1D_LUT_CENTER_60C'
   *   '<S62>/1D_LUT_LEFT_60C'
   *   '<S62>/1D_LUT_RIGHT_60C'
   */
  real32_T pooled14[9];

  /* Expression: Steering_Data_60C(:,3) % 3 represents right
   * Referenced by: '<S62>/1D_LUT_RIGHT_60C'
   */
  real32_T uD_LUT_RIGHT_60C_tableData[9];

  /* Expression: Steering_Correction_60C(:,2) % 2 represents correction
   * Referenced by: '<S62>/1D_LUT_CORRECTION_60C'
   */
  real32_T uD_LUT_CORRECTION_60C_tableData[8];

  /* Expression: Steering_Correction_60C(:,1) % 1 represents steer
   * Referenced by: '<S62>/1D_LUT_CORRECTION_60C'
   */
  real32_T uD_LUT_CORRECTION_60C_bp01Data[8];

  /* Expression: Steering_Data_60C(:,2) % 2 represents center
   * Referenced by: '<S62>/1D_LUT_CENTER_60C'
   */
  real32_T uD_LUT_CENTER_60C_tableData[9];

  /* Pooled Parameter (Expression: Steering_Data_63C(:,4) % 4 represents left)
   * Referenced by:
   *   '<S61>/1D_LUT_LEFT_63C'
   *   '<S63>/1D_LUT_LEFT_63C'
   */
  real32_T pooled15[9];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S61>/1D_LUT_CENTER_63C'
   *   '<S61>/1D_LUT_LEFT_63C'
   *   '<S61>/1D_LUT_RIGHT_63C'
   *   '<S63>/1D_LUT_CENTER_63C'
   *   '<S63>/1D_LUT_LEFT_63C'
   *   '<S63>/1D_LUT_RIGHT_63C'
   */
  real32_T pooled16[9];

  /* Pooled Parameter (Expression: Steering_Data_63C(:,3) % 3 represents right)
   * Referenced by:
   *   '<S61>/1D_LUT_RIGHT_63C'
   *   '<S63>/1D_LUT_RIGHT_63C'
   */
  real32_T pooled17[9];

  /* Pooled Parameter (Expression: Steering_Correction_63C(:,2) % 2 represents correction)
   * Referenced by:
   *   '<S61>/1D_LUT_CORRECTION_63C'
   *   '<S63>/1D_LUT_CORRECTION_63C'
   */
  real32_T pooled18[7];

  /* Pooled Parameter (Expression: Steering_Correction_63C(:,1) % 1 represents steer)
   * Referenced by:
   *   '<S61>/1D_LUT_CORRECTION_63C'
   *   '<S63>/1D_LUT_CORRECTION_63C'
   */
  real32_T pooled19[7];

  /* Pooled Parameter (Expression: Steering_Data_63C(:,2) % 2 represents center)
   * Referenced by:
   *   '<S61>/1D_LUT_CENTER_63C'
   *   '<S63>/1D_LUT_CENTER_63C'
   */
  real32_T pooled20[9];

  /* Expression: single([0 50 150 200])
   * Referenced by: '<S40>/Constant3'
   */
  real32_T Constant3_Value[4];

  /* Pooled Parameter (Expression: [0,2,5,10])
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   *   '<S42>/damping_gain_table'
   *   '<S42>/differential_gain_table'
   *   '<S42>/differential_gain_table1'
   *   '<S42>/differential_gain_table_trx'
   *   '<S42>/integrator_external_saturation_table'
   *   '<S42>/integrator_gain_table'
   *   '<S42>/integrator_gain_table1'
   *   '<S42>/integrator_gain_table_trx'
   */
  real32_T pooled25[4];

  /* Pooled Parameter (Expression: [0,25,50,100,570])
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   */
  real32_T pooled26[5];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S42>/P_gain_lookup_table trx'
   *   '<S42>/P_gain_lookup_table102'
   *   '<S42>/P_gain_lookup_table103'
   *   '<S42>/P_gain_lookup_table98'
   */
  uint32_T pooled34[2];
} ConstP_THA_VC_Ref_T;

/* Constant parameters (default storage) */
extern const ConstP_THA_VC_Ref_T THA_VC_Ref_ConstP;
extern const ConstB_THA_VC_Ref_hb4t_T THA_VC_Ref_ConstB;

#endif                                 /* RTW_HEADER_THA_VC_Ref_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
