/*
 * File: TRSC_VC_types.h
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

#ifndef RTW_HEADER_TRSC_VC_types_h_
#define RTW_HEADER_TRSC_VC_types_h_
#include "rtwtypes.h"
#include "TeTRSC_e_VehWhlBase.h"
#include "TeTRSC_e_RadDsplyTyp.h"
#include "TeTRSC_e_StrRackPinTyp.h"
#include "TbTRSC_InpBus.h"
#include "TeTRSC_e_TRSCStat.h"
#include "TeTRSC_e_TRSCStrTrqActvReq.h"
#include "TbTRSC_KM_MABx.h"
#include "TeTRSC_e_SpdLmtReq.h"
#ifndef DEFINED_TYPEDEF_FOR_struct_ANq9KjTY8gzuPxRcfiGj9_
#define DEFINED_TYPEDEF_FOR_struct_ANq9KjTY8gzuPxRcfiGj9_

typedef struct {
  real32_T T;
  real32_T TADvec;
  real32_T phiVec;
  real32_T uVec;
  real32_T TAD01;
  real32_T KeOTBL_m_HV_WheelBase;
} struct_ANq9KjTY8gzuPxRcfiGj9;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_TRSC_VC_T RT_MODEL_TRSC_VC_T;

#endif                                 /* RTW_HEADER_TRSC_VC_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
