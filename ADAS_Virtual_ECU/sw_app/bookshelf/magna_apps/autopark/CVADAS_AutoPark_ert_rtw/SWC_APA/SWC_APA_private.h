/*
 * File: SWC_APA_private.h
 *
 * Code generated for Simulink model 'SWC_APA'.
 *
 * Model version                  : 1.594
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Wed Nov 12 18:11:22 2025
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives:
 *    1. MISRA C:2012 guidelines
 *    2. RAM efficiency
 *    3. ROM efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_SWC_APA_private_h_
#define RTW_HEADER_SWC_APA_private_h_
#include "rtwtypes.h"

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

extern const real32_T rtCP_pooled_N87o8IFiLF1E[6];
extern const uint16_T rtCP_pooled_GPF4Fre45rNh[6];

#define rtCP_uDLookupTable_bp01Data    rtCP_pooled_N87o8IFiLF1E  /* Computed Parameter: rtCP_uDLookupTable_bp01Data
                                                                  * Referenced by: '<S170>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_bp01Data_o  rtCP_pooled_N87o8IFiLF1E  /* Computed Parameter: rtCP_uDLookupTable_bp01Data_o
                                                                  * Referenced by: '<S582>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData   rtCP_pooled_GPF4Fre45rNh  /* Computed Parameter: rtCP_uDLookupTable_tableData
                                                                  * Referenced by: '<S170>/1-D Lookup Table'
                                                                  */
#define rtCP_uDLookupTable_tableData_d rtCP_pooled_GPF4Fre45rNh  /* Computed Parameter: rtCP_uDLookupTable_tableData_d
                                                                  * Referenced by: '<S582>/1-D Lookup Table'
                                                                  */

extern const ConstB_SWC_APA_h_T SWC_APA_ConstB;

#endif                                 /* RTW_HEADER_SWC_APA_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
