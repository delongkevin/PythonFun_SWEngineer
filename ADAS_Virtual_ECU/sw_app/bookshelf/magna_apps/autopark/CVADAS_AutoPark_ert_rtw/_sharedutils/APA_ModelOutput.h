/* 
 * File: APA_ModelOutput.h 
 *   
 * Code generated for Simulink model ''. 
 *  
 * Model version                  :  
 * Simulink Coder version         :  
 * C/C++ source code generated on : Wed Nov 12 18:10:05 2025 
 * Embedded hardware selection: 
 */

#ifndef RTW_HEADER_APA_ModelOutput_h_
#define RTW_HEADER_APA_ModelOutput_h_
#include "TeAP_e_Alert.h"
#include "TeAP_e_GraphicFlshRate.h"
#include "TeAP_e_PAMChimeRepnRate.h"
#include "TeAP_e_PAMVolume.h"
#include "TeAP_e_PAMLedCtrlStatus.h"
#include "TeAP_e_PAMChimeTyp.h"
#include "TeAP_e_PAMPopUpReq.h"
#include "rtwtypes.h"


typedef struct
{
    TeAP_e_Alert IeAP_e_DispArcCHR;
    TeAP_e_Alert IeAP_e_DispArcLHR;
    TeAP_e_Alert IeAP_e_DispArcRHR;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateCHR;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateLHR;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateRHR;
    uint16_T IeAP_cm_RearDisttoNearObst;
    boolean_T IeAP_b_ChimeActvReqLHR;
    boolean_T IeAP_b_ChimeActvReqRHR;
} TbAP_RPAWarnOut_t;


typedef struct
{
    TeAP_e_Alert IeAP_e_DispArcCHF;
    TeAP_e_Alert IeAP_e_DispArcLHF;
    TeAP_e_Alert IeAP_e_DispArcRHF;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateLHF;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateRHF;
    TeAP_e_GraphicFlshRate IeAP_e_ArcFlashRateCHF;
    boolean_T IeAP_b_ChimeActvReqLHF;
    boolean_T IeAP_b_ChimeActvReqRHF;
} TbAP_FPAWarnOut_t;


typedef struct
{
    TeAP_e_PAMChimeRepnRate IeAP_e_PAMChimeRepnRate;
    TeAP_e_PAMVolume IeAP_e_PAMVolSig;
    TeAP_e_PAMLedCtrlStatus IeAP_e_FrntParkLEDSts;
    TeAP_e_PAMLedCtrlStatus IeAP_e_PAMLedCtrl;
    TeAP_e_PAMChimeTyp IeAP_e_PAMChimeTyp;
    TeAP_e_PAMPopUpReq IeAP_e_ParkSensePopUpReq;
    boolean_T IeAP_b_PAMRearBrkReq;
    boolean_T IeAP_b_PAMRearCtrlSts;
} TbAP_PAStateOut_t;


#endif                     /* RTW_HEADER_APA_ModelOutput_h_ */
/* 
 * File trailer for generated code. 
 *  
 * [EOF] 
 */

