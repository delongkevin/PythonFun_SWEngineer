/*
 * File: TRSC_VC_private.h
 *
 * Code generated for Simulink model 'TRSC_VC'.
 *
 * Model version                  : 1.7705
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Thu Nov 13 09:52:03 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_TRSC_VC_private_h_
#define RTW_HEADER_TRSC_VC_private_h_
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

extern const real32_T rtCP_pooled_G4pf6ezoRqSl[91];
extern const real32_T rtCP_pooled_aJt64d48XjKf[91];
extern const real32_T rtCP_pooled_IfZxqwWWQ9Dq[91];
extern const real32_T rtCP_pooled_NAkK6ET6n8qC[181];
extern const real32_T rtCP_pooled_TnkrKmM0RBPE[181];
extern const real32_T rtCP_pooled_KF8f8LMY4QZw[9];
extern const real32_T rtCP_pooled_KpxIUsu9Tpfo[9];
extern const real32_T rtCP_pooled_QJvoKtvKpryd[101];
extern const real32_T rtCP_pooled_fDZf64zFvwHY[101];
extern const real32_T rtCP_pooled_4ZnYz1w3Ugac[3];
extern const real32_T rtCP_pooled_GRnjqXwr57XW[3];
extern const real32_T rtCP_pooled_ZrnH9lFmjJfC[4];
extern const uint32_T rtCP_pooled_NIEuc0YFqRfp;
extern const uint32_T rtCP_pooled_cAr5EnHOxIRd;
extern const uint32_T rtCP_pooled_HKUgUYXMke6E[2];
extern const uint32_T rtCP_pooled_wI2Ssoe1OxCP[2];
extern const uint32_T trsc_rtCP_pooled_nJwGcJM2ZB38[2];
extern const uint32_T rtCP_pooled_oBc9SmOqSpNv[2];

#define rtCP_uDLookupTable_0_1_tableData rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_1'
                                                                  */
#define rtCP_uDLookupTable_0_1_bp01Data rtCP_pooled_aJt64d48XjKf /* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_1'
                                                                  */
#define rtCP_uDLookupTable_0_2_tableData rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_2'
                                                                  */
#define rtCP_uDLookupTable_0_2_bp01Data rtCP_pooled_aJt64d48XjKf /* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_2'
                                                                  */
#define rtCP_uDLookupTable_0_3_tableData rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_3'
                                                                  */
#define rtCP_uDLookupTable_0_3_bp01Data rtCP_pooled_aJt64d48XjKf /* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data
                                                                  * Referenced by: '<S49>/1-D Lookup Table_0_3'
                                                                  */
#define rtCP_uDLookupTable_0_1_tableData_i rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_i
                                                                    * Referenced by: '<S50>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_d rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_d
                                                                   * Referenced by: '<S50>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_6_tableData rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData
                                                                  * Referenced by: '<S50>/1-D Lookup Table_0_6'
                                                                  */
#define rtCP_uDLookupTable_0_6_bp01Data rtCP_pooled_aJt64d48XjKf /* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data
                                                                  * Referenced by: '<S50>/1-D Lookup Table_0_6'
                                                                  */
#define rtCP_tanLookup_tableData       rtCP_pooled_NAkK6ET6n8qC  /* Computed Parameter: rtCP_tanLookup_tableData
                                                                  * Referenced by: '<S64>/tan Lookup'
                                                                  */
#define rtCP_tanLookup_bp01Data        rtCP_pooled_TnkrKmM0RBPE  /* Computed Parameter: rtCP_tanLookup_bp01Data
                                                                  * Referenced by: '<S64>/tan Lookup'
                                                                  */
#define rtCP_uDLookupTable_0_1_tableData_f rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_f
                                                                    * Referenced by: '<S75>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_dd rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_dd
                                                                    * Referenced by: '<S75>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_2_tableData_i rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_i
                                                                    * Referenced by: '<S75>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_h rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_h
                                                                   * Referenced by: '<S75>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_3_tableData_j rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_j
                                                                    * Referenced by: '<S75>/1-D Lookup Table_0_3'
                                                                    */
#define rtCP_uDLookupTable_0_3_bp01Data_n rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_n
                                                                   * Referenced by: '<S75>/1-D Lookup Table_0_3'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_c rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_c
                                                                    * Referenced by: '<S76>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_p rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_p
                                                                   * Referenced by: '<S76>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_6_tableData_c rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_c
                                                                    * Referenced by: '<S76>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_e rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_e
                                                                   * Referenced by: '<S76>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_n rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_n
                                                                    * Referenced by: '<S78>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_p5 rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_p5
                                                                    * Referenced by: '<S78>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_2_tableData_j rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_j
                                                                    * Referenced by: '<S78>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_c rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_c
                                                                   * Referenced by: '<S78>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_3_tableData_n rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_n
                                                                    * Referenced by: '<S78>/1-D Lookup Table_0_3'
                                                                    */
#define rtCP_uDLookupTable_0_3_bp01Data_l rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_l
                                                                   * Referenced by: '<S78>/1-D Lookup Table_0_3'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_p rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_p
                                                                    * Referenced by: '<S79>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_d2 rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_d2
                                                                    * Referenced by: '<S79>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_6_tableData_b rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_b
                                                                    * Referenced by: '<S79>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_j rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_j
                                                                   * Referenced by: '<S79>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_tanLookup_tableData_n     rtCP_pooled_NAkK6ET6n8qC  /* Computed Parameter: rtCP_tanLookup_tableData_n
                                                                  * Referenced by: '<S81>/tan Lookup'
                                                                  */
#define rtCP_tanLookup_bp01Data_h      rtCP_pooled_TnkrKmM0RBPE  /* Computed Parameter: rtCP_tanLookup_bp01Data_h
                                                                  * Referenced by: '<S81>/tan Lookup'
                                                                  */
#define rtCP_uDLookupTable_0_1_tableData_a rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_a
                                                                    * Referenced by: '<S86>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_g rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_g
                                                                   * Referenced by: '<S86>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_2_tableData_l rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_l
                                                                    * Referenced by: '<S86>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_m rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_m
                                                                   * Referenced by: '<S86>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_3_tableData_o rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_o
                                                                    * Referenced by: '<S86>/1-D Lookup Table_0_3'
                                                                    */
#define rtCP_uDLookupTable_0_3_bp01Data_lk rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_lk
                                                                    * Referenced by: '<S86>/1-D Lookup Table_0_3'
                                                                    */
#define rtCP_uDLookupTable_0_1_tableData_j rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_j
                                                                    * Referenced by: '<S87>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_m rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_m
                                                                   * Referenced by: '<S87>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_2_tableData_b rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_b
                                                                    * Referenced by: '<S87>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_l rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_l
                                                                   * Referenced by: '<S87>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_3_tableData_nw rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_nw
                                                                     * Referenced by: '<S87>/1-D Lookup Table_0_3'
                                                                     */
#define rtCP_uDLookupTable_0_3_bp01Data_e rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_e
                                                                   * Referenced by: '<S87>/1-D Lookup Table_0_3'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_pl rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_pl
                                                                     * Referenced by: '<S88>/1-D Lookup Table_0_1'
                                                                     */
#define rtCP_uDLookupTable_0_1_bp01Data_mf rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_mf
                                                                    * Referenced by: '<S88>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_6_tableData_m rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_m
                                                                    * Referenced by: '<S88>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_c rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_c
                                                                   * Referenced by: '<S88>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_o rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_o
                                                                    * Referenced by: '<S89>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_ml rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_ml
                                                                    * Referenced by: '<S89>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_6_tableData_l rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_l
                                                                    * Referenced by: '<S89>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_d rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_d
                                                                   * Referenced by: '<S89>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_Constant2_Value_b         rtCP_pooled_KF8f8LMY4QZw  /* Computed Parameter: rtCP_Constant2_Value_b
                                                                  * Referenced by: '<S36>/Constant2'
                                                                  */
#define rtCP_zeros33_Value             rtCP_pooled_KF8f8LMY4QZw  /* Computed Parameter: rtCP_zeros33_Value
                                                                  * Referenced by: '<S68>/zeros(3,3)'
                                                                  */
#define rtCP_UnitDelay3_InitialCondition_e rtCP_pooled_KpxIUsu9Tpfo/* Computed Parameter: rtCP_UnitDelay3_InitialCondition_e
                                                                    * Referenced by: '<S24>/Unit Delay3'
                                                                    */
#define rtCP_tanLookup_tableData_h     rtCP_pooled_NAkK6ET6n8qC  /* Computed Parameter: rtCP_tanLookup_tableData_h
                                                                  * Referenced by: '<S80>/tan Lookup'
                                                                  */
#define rtCP_tanLookup_bp01Data_j      rtCP_pooled_TnkrKmM0RBPE  /* Computed Parameter: rtCP_tanLookup_bp01Data_j
                                                                  * Referenced by: '<S80>/tan Lookup'
                                                                  */
#define rtCP_uDLookupTable_0_2_tableData_f rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_f
                                                                    * Referenced by: '<S79>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_c0 rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_c0
                                                                    * Referenced by: '<S79>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_Constant1_Value_n5        rtCP_pooled_KF8f8LMY4QZw  /* Computed Parameter: rtCP_Constant1_Value_n5
                                                                  * Referenced by: '<S72>/Constant1'
                                                                  */
#define rtCP_uDLookupTable_0_2_tableData_m rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_m
                                                                    * Referenced by: '<S76>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_l1 rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_l1
                                                                    * Referenced by: '<S76>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_tanLookup_tableData_a     rtCP_pooled_NAkK6ET6n8qC  /* Computed Parameter: rtCP_tanLookup_tableData_a
                                                                  * Referenced by: '<S77>/tan Lookup'
                                                                  */
#define rtCP_tanLookup_bp01Data_jb     rtCP_pooled_TnkrKmM0RBPE  /* Computed Parameter: rtCP_tanLookup_bp01Data_jb
                                                                  * Referenced by: '<S77>/tan Lookup'
                                                                  */
#define rtCP_uDLookupTable_0_2_tableData_f2 rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_f2
                                                                     * Referenced by: '<S89>/1-D Lookup Table_0_2'
                                                                     */
#define rtCP_uDLookupTable_0_2_bp01Data_o rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_o
                                                                   * Referenced by: '<S89>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_2_tableData_d rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_d
                                                                    * Referenced by: '<S88>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_mn rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_mn
                                                                    * Referenced by: '<S88>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_tableData_lt rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_lt
                                                                     * Referenced by: '<S50>/1-D Lookup Table_0_2'
                                                                     */
#define rtCP_uDLookupTable_0_2_bp01Data_oy rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_oy
                                                                    * Referenced by: '<S50>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_1_tableData_n5 rtCP_pooled_QJvoKtvKpryd/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_n5
                                                                     * Referenced by: '<S123>/1-D Lookup Table_0_1'
                                                                     */
#define rtCP_uDLookupTable_0_1_bp01Data_j rtCP_pooled_fDZf64zFvwHY/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_j
                                                                   * Referenced by: '<S123>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_6_tableData_e rtCP_pooled_QJvoKtvKpryd/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_e
                                                                    * Referenced by: '<S123>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_f rtCP_pooled_fDZf64zFvwHY/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_f
                                                                   * Referenced by: '<S123>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_jz rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_jz
                                                                     * Referenced by: '<S124>/1-D Lookup Table_0_1'
                                                                     */
#define rtCP_uDLookupTable_0_1_bp01Data_l rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_l
                                                                   * Referenced by: '<S124>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_2_tableData_ia rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_ia
                                                                     * Referenced by: '<S124>/1-D Lookup Table_0_2'
                                                                     */
#define rtCP_uDLookupTable_0_2_bp01Data_i rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_i
                                                                   * Referenced by: '<S124>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_3_tableData_f rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_f
                                                                    * Referenced by: '<S124>/1-D Lookup Table_0_3'
                                                                    */
#define rtCP_uDLookupTable_0_3_bp01Data_d rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_d
                                                                   * Referenced by: '<S124>/1-D Lookup Table_0_3'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_jj rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_jj
                                                                     * Referenced by: '<S125>/1-D Lookup Table_0_1'
                                                                     */
#define rtCP_uDLookupTable_0_1_bp01Data_c rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_c
                                                                   * Referenced by: '<S125>/1-D Lookup Table_0_1'
                                                                   */
#define rtCP_uDLookupTable_0_6_tableData_a rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_a
                                                                    * Referenced by: '<S125>/1-D Lookup Table_0_6'
                                                                    */
#define rtCP_uDLookupTable_0_6_bp01Data_p rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_p
                                                                   * Referenced by: '<S125>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_FrttoStrWhl1_tableData    rtCP_pooled_4ZnYz1w3Ugac  /* Computed Parameter: rtCP_FrttoStrWhl1_tableData
                                                                  * Referenced by: '<S114>/Frt to Str Whl1'
                                                                  */
#define rtCP_FrttoStrWhl1_bp01Data     rtCP_pooled_GRnjqXwr57XW  /* Computed Parameter: rtCP_FrttoStrWhl1_bp01Data
                                                                  * Referenced by: '<S114>/Frt to Str Whl1'
                                                                  */
#define rtCP_uDLookupTable_0_1_tableData_fi rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_fi
                                                                     * Referenced by: '<S132>/1-D Lookup Table_0_1'
                                                                     */
#define rtCP_uDLookupTable_0_1_bp01Data_lr rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_lr
                                                                    * Referenced by: '<S132>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_2_tableData_c rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_c
                                                                    * Referenced by: '<S132>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_oe rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_oe
                                                                    * Referenced by: '<S132>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_3_tableData_n4 rtCP_pooled_G4pf6ezoRqSl/* Computed Parameter: rtCP_uDLookupTable_0_3_tableData_n4
                                                                     * Referenced by: '<S132>/1-D Lookup Table_0_3'
                                                                     */
#define rtCP_uDLookupTable_0_3_bp01Data_j rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_3_bp01Data_j
                                                                   * Referenced by: '<S132>/1-D Lookup Table_0_3'
                                                                   */
#define rtCP_uDLookupTable_0_1_tableData_b rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_1_tableData_b
                                                                    * Referenced by: '<S133>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_1_bp01Data_db rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_1_bp01Data_db
                                                                    * Referenced by: '<S133>/1-D Lookup Table_0_1'
                                                                    */
#define rtCP_uDLookupTable_0_6_tableData_aw rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_6_tableData_aw
                                                                     * Referenced by: '<S133>/1-D Lookup Table_0_6'
                                                                     */
#define rtCP_uDLookupTable_0_6_bp01Data_n rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_6_bp01Data_n
                                                                   * Referenced by: '<S133>/1-D Lookup Table_0_6'
                                                                   */
#define rtCP_uDLookupTable_0_2_tableData_du rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_du
                                                                     * Referenced by: '<S133>/1-D Lookup Table_0_2'
                                                                     */
#define rtCP_uDLookupTable_0_2_bp01Data_k rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_k
                                                                   * Referenced by: '<S133>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_integrator_gain_table_type1_bp02Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3])
                                                                      * Referenced by: '<S159>/integrator_gain_table_type1'
                                                                      */
#define rtCP_integrator_gain_table_type2or3_bp02Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3])
                                                                      * Referenced by: '<S159>/integrator_gain_table_type2or3'
                                                                      */
#define rtCP_proportional_multiplier_table_type1_bp01Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3]);
                                                                      * Referenced by: '<S159>/proportional_multiplier_table_type1'
                                                                      */
#define rtCP_proportional_multiplier_table_type2or3_bp01Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3]);
                                                                      * Referenced by: '<S159>/proportional_multiplier_table_type2or3'
                                                                      */
#define rtCP_uDLookupTable_0_2_tableData_o rtCP_pooled_IfZxqwWWQ9Dq/* Computed Parameter: rtCP_uDLookupTable_0_2_tableData_o
                                                                    * Referenced by: '<S125>/1-D Lookup Table_0_2'
                                                                    */
#define rtCP_uDLookupTable_0_2_bp01Data_d rtCP_pooled_aJt64d48XjKf/* Computed Parameter: rtCP_uDLookupTable_0_2_bp01Data_d
                                                                   * Referenced by: '<S125>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_diffrential_multiplier_table_type1_bp01Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3])
                                                                      * Referenced by: '<S159>/diffrential_multiplier_table_type1'
                                                                      */
#define rtCP_error_sat_limit_bp01Data  rtCP_pooled_ZrnH9lFmjJfC  /* Expression: single([0,1,2,3]);
                                                                  * Referenced by: '<S159>/error_sat_limit'
                                                                  */
#define rtCP_integrator_multiplier_table_type1_bp01Data rtCP_pooled_ZrnH9lFmjJfC/* Expression: single([0,1,2,3]);
                                                                      * Referenced by: '<S159>/integrator_multiplier_table_type1'
                                                                      */
#define rtCP_uDLookupTable_0_2_maxIndex rtCP_pooled_NIEuc0YFqRfp /* Computed Parameter: rtCP_uDLookupTable_0_2_maxIndex
                                                                  * Referenced by: '<S75>/1-D Lookup Table_0_2'
                                                                  */
#define rtCP_uDLookupTable_0_2_dimSizes rtCP_pooled_cAr5EnHOxIRd /* Computed Parameter: rtCP_uDLookupTable_0_2_dimSizes
                                                                  * Referenced by: '<S75>/1-D Lookup Table_0_2'
                                                                  */
#define rtCP_uDLookupTable_0_2_numYWorkElts rtCP_pooled_HKUgUYXMke6E/* Computed Parameter: rtCP_uDLookupTable_0_2_numYWorkElts
                                                                     * Referenced by: '<S75>/1-D Lookup Table_0_2'
                                                                     */
#define rtCP_uDLookupTable_0_2_maxIndex_e rtCP_pooled_NIEuc0YFqRfp/* Computed Parameter: rtCP_uDLookupTable_0_2_maxIndex_e
                                                                   * Referenced by: '<S78>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_2_dimSizes_g rtCP_pooled_cAr5EnHOxIRd/* Computed Parameter: rtCP_uDLookupTable_0_2_dimSizes_g
                                                                   * Referenced by: '<S78>/1-D Lookup Table_0_2'
                                                                   */
#define rtCP_uDLookupTable_0_2_numYWorkElts_n rtCP_pooled_HKUgUYXMke6E/* Computed Parameter: rtCP_uDLookupTable_0_2_numYWorkElts_n
                                                                      * Referenced by: '<S78>/1-D Lookup Table_0_2'
                                                                      */
#define rtCP_integrator_gain_table_type1_maxIndex rtCP_pooled_wI2Ssoe1OxCP/* Computed Parameter: rtCP_integrator_gain_table_type1_maxIndex
                                                                      * Referenced by: '<S159>/integrator_gain_table_type1'
                                                                      */
#define rtCP_integrator_gain_table_type2or3_maxIndex rtCP_pooled_wI2Ssoe1OxCP/* Computed Parameter: rtCP_integrator_gain_table_type2or3_maxIndex
                                                                      * Referenced by: '<S159>/integrator_gain_table_type2or3'
                                                                      */
#define rtCP_P_gain_lookup_table_type1_maxIndex trsc_rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table_type1_maxIndex
                                                                      * Referenced by: '<S159>/P_gain_lookup_table_type1'
                                                                      */
#define rtCP_P_gain_lookup_table_type3_maxIndex trsc_rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table_type3_maxIndex
                                                                      * Referenced by: '<S159>/P_gain_lookup_table_type3'
                                                                      */
#define rtCP_P_gain_lookup_table_type2_maxIndex trsc_rtCP_pooled_nJwGcJM2ZB38/* Computed Parameter: rtCP_P_gain_lookup_table_type2_maxIndex
                                                                      * Referenced by: '<S159>/P_gain_lookup_table_type2'
                                                                      */
#define rtCP_uDLookupTable1_maxIndex   rtCP_pooled_oBc9SmOqSpNv  /* Computed Parameter: rtCP_uDLookupTable1_maxIndex
                                                                  * Referenced by: '<S118>/2-D Lookup Table1'
                                                                  */

extern const ConstB_TRSC_VC_h_T TRSC_VC_ConstB;

#endif                                 /* RTW_HEADER_TRSC_VC_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
