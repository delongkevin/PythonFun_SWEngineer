/* 
 * File: SM_ModelOutput.h 
 *   
 * Code generated for Simulink model ''. 
 *  
 * Model version                  :  
 * Simulink Coder version         :  
 * C/C++ source code generated on : Wed Nov 12 18:10:05 2025 
 * Embedded hardware selection: 
 */

#ifndef RTW_HEADER_SM_ModelOutput_h_
#define RTW_HEADER_SM_ModelOutput_h_
#include "TeAP_e_HMIPopUp.h"
#include "TeAP_e_ParkAssistStatus.h"
#include "TeAutoPark_e_GearCmd.h"
#include "TeAP_e_PAMSystemFault.h"
#include "TeAP_e_PAMOffStatus2BT.h"
#include "TeAP_e_FrntSnsrStatus.h"
#include "TeAP_e_RearSnsrStatus.h"
#include "TeAutoPark_e_ChimeReq.h"
#include "TeAutoPark_e_ScanDir.h"
#include "TeAutoPark_e_AutoParkStatus.h"
#include "TeAP_e_AlgoState.h"
#include "TeAP_e_ParKMnvrActv.h"
#include "TeAP_e_InterfaceBSM.h"
#include "TeAP_e_SPMLatCtrlReqSts.h"
#include "TeAP_e_PAMLedCtrlStatus.h"
#include "TeAP_e_SPMActvStat.h"
#include "TeAP_e_DispView2.h"
#include "TeAP_e_GearShiftReq.h"
#include "TeAP_e_PAMVolSig.h"
#include "TeAP_e_PAMChimeTyp.h"
#include "TeAP_e_PAMChimeRepnRate.h"
#include "TeAP_e_USSSupplyPwrSt.h"
#include "TeAP_e_USSSystemMode.h"
#include "TeAP_e_USSSystemState.h"
#include "rtwtypes.h"

typedef struct {
  TeAP_e_HMIPopUp MeAP_e_HMIPopUp;
  boolean_T MeAP_b_FPAStatus;
  boolean_T MeAP_b_RPAStatus;
  boolean_T MeAP_b_FPASwtStatus;
  boolean_T MeAP_b_RPASwtStatus;
  boolean_T MeAP_b_DisableDiag;
  boolean_T MeAP_b_RPAwithBrkStatus;
  boolean_T MeAP_b_SystemFail;
  boolean_T MeAP_b_ExternalFail;
  boolean_T MeAP_b_TempFail;
  boolean_T MeAP_b_RPAwithBrkDisable;
  boolean_T MeAP_b_RPADisable;
  boolean_T MeAP_b_FPADisable;
} TbAP_SMPAInternalOut_t;

typedef struct {
  TeAP_e_ParkAssistStatus MeAP_e_ParkAssistStatus;
  TeAutoPark_e_GearCmd MeAP_e_GearCmdToHMI;
  uint8_T IeAP_e_MnvActvStat;
  uint8_T IeAP_e_AbortCon;
  uint8_T IeAP_e_SemiParkSysSts;
  uint8_T IeAP_e_DIDHMICode;
  boolean_T MeAP_b_AutoParkEnblSwtStuckStatus;
  boolean_T MeAP_b_ScanSts;
  boolean_T MeAP_b_ParkSlotDetctSts;
  boolean_T MeAP_b_ResetKM;
} TbAP_SMDAInternalOut_t;

typedef struct {
  TeAP_e_PAMSystemFault IeAP_e_PAMFlt;
  TeAP_e_PAMOffStatus2BT IeAP_e_FrntRearParkSts;
  TeAP_e_FrntSnsrStatus IeAP_e_FrntSensorActvSts;
  TeAP_e_RearSnsrStatus IeAP_e_RearSnsrActvSts;
} TbAP_APSMPAOut_t;

typedef struct {
  real32_T MeAP_s_FaultWaitTime;
  TeAutoPark_e_ChimeReq IeAutoPark_e_ChimeReq;
  TeAutoPark_e_ScanDir IeAP_e_ScanDir;
  TeAutoPark_e_AutoParkStatus IeAP_e_AutoParkStatus;
  TeAP_e_AlgoState IeAP_e_AlgoState;
  TeAP_e_ParKMnvrActv IeAP_e_ParKMnvrActv;
  TeAP_e_InterfaceBSM IeAP_e_InterfaceBSM;
  TeAP_e_SPMLatCtrlReqSts IeAP_e_SPMLatCtrlReqSts;
  TeAP_e_PAMLedCtrlStatus IeAP_e_SPMLedSts;
  TeAP_e_SPMActvStat IeAP_e_SPMActvStat;
  TeAP_e_DispView2 IeAP_e_DispView2;
  TeAP_e_GearShiftReq IeAP_e_GearShiftReq;
  TeAP_e_PAMVolSig MeAP_e_PAMVolSigSVM;
  TeAP_e_PAMChimeTyp MeAP_e_PAMChimeTypSVM;
  TeAP_e_PAMChimeRepnRate MeAP_e_PAMChimeRepnRateSVM;
  uint8_T IeAP_e_HMIDispReq;
  boolean_T IeAP_b_WrngSpdExceed;
  boolean_T IeAP_b_FaultStatus;
  boolean_T IeAP_b_ParkInOutSuccess;
  boolean_T IeAP_b_ParkInOutAbort;
  boolean_T IeAP_b_FeatureAvl;
  boolean_T IeAP_b_ParkOutAvailable;
  boolean_T IeAP_b_ImgDefeatReqSts;
  boolean_T IeAP_b_SPMScrnReq;
  boolean_T IeAP_b_SPMFailSts;
  boolean_T IeAP_b_SPMFaultSts;
  boolean_T IeAP_b_VehMnvrDirSPM;
  boolean_T IeAP_b_AutoParkOverride;
  boolean_T MeAP_b_SensorFltSts;
  boolean_T MeAP_b_ChimeActvReqLHFSVM;
  boolean_T MeAP_b_ChimeActvReqLHRSVM;
  boolean_T MeAP_b_ChimeActvReqRHFSVM;
  boolean_T MeAP_b_ChimeActvReqRHRSVM;
} TbAP_DriveAssistStatOut_t;

typedef struct {
  TeAP_e_USSSupplyPwrSt IeAP_e_USSSupplyPwrSt;
  TeAP_e_USSSystemMode IeAP_e_USSSystemMode;
  TeAP_e_USSSystemState IeAP_e_USSSystemState;
  uint8_T IeAP_e_USSFiringMode;
  boolean_T MeAP_b_USSReInit;
} TbAP_USSStateOut_t;

#endif                                 /* RTW_HEADER_SM_ModelOutput_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
