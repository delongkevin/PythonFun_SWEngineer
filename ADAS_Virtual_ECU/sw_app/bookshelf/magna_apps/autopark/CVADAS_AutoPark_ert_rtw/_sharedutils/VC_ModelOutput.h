/* 
 * File: VC_ModelOutput.h 
 *   
 * Code generated for Simulink model ''. 
 *  
 * Model version                  :  
 * Simulink Coder version         :  
 * C/C++ source code generated on : Wed Nov 12 18:10:05 2025 
 * Embedded hardware selection: 
 */

#ifndef RTW_HEADER_VC_ModelOutput_h_
#define RTW_HEADER_VC_ModelOutput_h_
#include "rtwtypes.h"


typedef struct
{
    real32_T MaAP_m_PlannerWayPointsX[250];
    real32_T MaAP_m_PlannerWayPointsY[250];
} TbAP_VCTrajOut_t;


typedef struct
{
    real32_T MeAP_e_Park_state;
    int8_T MeAP_e_PP_state;
    uint8_T IeAP_cnt_CurrentVehSweep;
    boolean_T MeAP_b_ManeuverAbort;
    boolean_T MeAP_b_ManeuverSuccess;
    boolean_T MeAP_b_PosMet;
    boolean_T MeAP_b_SteerActionReq;
    boolean_T IeAP_b_MnvPosOk;
} TbAP_VCStateOut_t;


typedef struct
{
    real32_T IeAP_nm_StrwTrqReq;
    real32_T IeAP_a_DecelMax;
    real32_T IeAP_a_DecelMin;
    real32_T IeAP_a_JerkDecelMax;
    real32_T IeAP_a_JerkDecelMin;
    real32_T IeAP_a_AcclMin;
    real32_T IeAP_a_AcclMax;
    real32_T IeAP_da_JerkAcclMax;
    real32_T IeAP_da_JerkAcclMin;
    real32_T IeAP_cm_TrgtDist;
    real32_T IeAP_kph_TrgtVehSpd;
    int32_T IeAP_e_TurnIndicReq;
    boolean_T IeAP_b_StandstillReq;
} TbAP_VCActuatorOut_t;


#endif                     /* RTW_HEADER_VC_ModelOutput_h_ */
/* 
 * File trailer for generated code. 
 *  
 * [EOF] 
 */

