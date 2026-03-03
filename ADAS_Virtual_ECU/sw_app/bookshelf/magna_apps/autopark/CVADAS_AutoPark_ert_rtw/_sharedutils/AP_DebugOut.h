/* 
 * File: AP_DebugOut.h 
 *   
 * Code generated for Simulink model ''. 
 *  
 * Model version                  :  
 * Simulink Coder version         :  
 * C/C++ source code generated on : Wed Nov 12 18:10:05 2025 
 * Embedded hardware selection: 
 */

#ifndef RTW_HEADER_AP_DebugOut_h_
#define RTW_HEADER_AP_DebugOut_h_
#include "rtwtypes.h"


typedef struct
{
    real32_T MeAP_deg_StrCmd;
    real32_T MeAP_a_BrkCmd;
    real32_T MeAP_a_ThrtlCmd;
    uint16_T MeAP_cnt_StateDebugVar;
    uint16_T MeAP_cnt_TransDebugVar;
    int16_T MeAP_cm_FrntCenterMinXDist;
    int16_T MeAP_cm_FrntLeftMinXDist;
    int16_T MeAP_cm_FrntRightMinXDist;
    int16_T MeAP_cm_RearCenterMinXDist;
    int16_T MeAP_cm_RearLeftMinXDist;
    int16_T MeAP_cm_RearRightMinXDist;
    boolean_T MeAP_b_VCOpPaused;
    boolean_T MeAP_b_BSMInterfaceTimeout;
    boolean_T MeAP_b_EPSInterfaceTimeout;
    boolean_T MeAP_b_GearShiftWaitTimeout;
    boolean_T MeAP_b_CamHandshakeTimeout;
    boolean_T MeAP_b_ObjInPathTimeout;
    boolean_T MeAP_b_PausedPressBtnTimeout;
    boolean_T MeAP_b_SeekSpdExceedTimeout;
    boolean_T MeAP_b_APInitSts;
    boolean_T MeAP_b_DriverOverride;
    boolean_T MeAP_b_StandStill;
    boolean_T MeAP_b_BSMHandshakeActv;
    boolean_T MeAP_b_VehCndSts;
    boolean_T MeAP_b_FeatureEnbl;
    boolean_T MeAP_b_FPADisable;
    boolean_T MeAP_b_RPADisable;
    boolean_T MeAP_b_RPAActvTrlr;
    boolean_T MeAP_b_PAVolDefMed;
    boolean_T MeAP_b_FPAVolDefMed;
    boolean_T MeAP_b_RPAVolDefMed;
    boolean_T MeAP_b_PARBActvTrlr;
    boolean_T MeAP_b_PARBActv4LOW;
    boolean_T MeAP_b_PARBDiable;
    boolean_T MeAP_b_PPPAActvTrlr;
    boolean_T MeAP_b_PPPAActv4LOW;
    boolean_T MeAP_b_PPPADefEng;
    boolean_T MeAP_b_PPPADisable;
} TbAP_DebugOut;


#endif                     /* RTW_HEADER_AP_DebugOut_h_ */
/* 
 * File trailer for generated code. 
 *  
 * [EOF] 
 */

