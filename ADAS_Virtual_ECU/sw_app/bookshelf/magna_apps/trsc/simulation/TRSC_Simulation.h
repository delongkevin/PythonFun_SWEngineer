/// @file   TRSC_Simulation.h
/// @brief  TRSC SM VC simulated data for offline testing
///
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Pravin Pawar (pravin.pawar@magna.com)
///

#ifndef TRSC_SIMULATION_H
#define TRSC_SIMULATION_H

#define PRINT_INPUTS          0
#define TRSC_OUTPUT_PRINT     0
#define MAX_SIMULATION_DATA 	3889
#if (!TRSC_SIGM_TESTING)
float32_t IeVBII_deg_StrWhlAng_test[] = { 0};
int32_t IeVBII_e_TchScrSts_test[] = { 0};
float32_t IeVBII_px_TchXCoord_test[] = { 0};
float32_t IeVBII_px_TchYCoord_test[] = { 0};
int32_t IeVBII_e_TrscEnblBtnSts_test[] = { 0};
int32_t IeVBII_e_GearRptState_test[] = { 0};
float32_t IeVBII_e_SBR1RowDriverSeatSts_test[] = { 0};
int32_t IeVBII_e_EcmTrscResp_test[] = { 0};
int32_t IeVBII_e_EscTrscBrkResp_test[] = { 0};
float32_t IeVBII_kph_RefVehSpd_test[] = { 0};
int32_t IeVBII_e_VehStandStillSts_test[] = { 1};
float32_t IeVBII_mm_VehFlLvl_test[] = { 0};
float32_t IeVBII_mm_VehFrLvl_test[] = { 0};
uint8_t IeVBII_e_VehFlLvlAdj_test[] = { 0};
uint8_t IeVBII_e_VehFrLvlAdj_test[] = { 0};
float32_t IeVBII_mm_VehRlLvl_test[] = { 0};
uint8_t IeVBII_e_VehRlLvlAdj_test[] = { 0};
float32_t IeVBII_mm_VehRrLvl_test[] = { 0};
uint8_t IeVBII_e_VehRrLvlAdj_test[] = { 0};
uint8_t IeVBII_b_VehAscmSysFail_test[] = { 0};
uint8_t IeVBII_b_StrTchSts_test[] = { 0};
uint8_t IeVBII_k_KnobAngl_test[] = { 0};
uint8_t MeTRSC_b_TrlrCalibPopInfo_test[] = { 0};
float32_t MeTRSC_deg_TADAngle_test[] = { 90};
uint8_t MeTRSC_cnt_TrlrCalibFailCntInfo_test[] = { 0};
uint8_t MeTRSC_b_TrlrCalibDelayInfo_test[] = { 0};
uint8_t MeTRSC_b_InternalFault_test[] = { 0};
uint8_t MeTRSC_e_CamBlockSts_test[] = { 75};
uint8_t IeHMI_b_MoreCamReq_test[] = { 0};
int32_t MeTRSC_e_TADState_test[] = { 0};
int32_t MeTRSC_e_TrlrPrsntInfo_test[] = { 1};
int32_t MeTRSC_e_TrlrRecogInfo_test[] = { 0};
int32_t MeTRSC_e_TrlrCalInfo_test[] = { 1};
int32_t IeVBII_e_CenterBtnSts_test[] = { 1};
int32_t IeVBII_e_VehAscmSts_test[] = { 15};
float32_t MeTRSC_m_HitchLength_test[] = { 1.39999997615814};
int32_t MeTRSC_deg_TADAngleRate_test[] = { 0};
uint8_t MeTRSC_b_OBTLRecalibrate_test[] = { 0};
float32_t MeTRSC_deg_DetJackknifeThrAngle_test[] = { 10.0};
float32_t MeTRSC_m_DetTrailerBeamLen_test[] = { 1.39999997615814};
float32_t MeTRSC_deg_DetJackKnifeAngle_test[] = { 50.0};
uint8_t MeTRSC_e_TurnAroundSubState_test[] = { 1};
uint8_t MeTRSC_e_TADCalibrationSubstate_test[] = { 1};
uint8_t MeTRSC_e_CalFail_test[] = { 1};
uint8_t MeTRSC_e_TrailerID_test[] = { 1};
int32_t IeVBII_e_CmdIgnSts_test[] = { 4};
int32_t IeVBII_e_TrailerConnectionSts_test[] = { 1};
int32_t IeVBII_e_TrlrPrsntSts_test[] = { 1};
float32_t IeVBII_a_VehLatAcc_test[] = { 0};
float32_t IeVBII_a_VehLongAcc_test[] = { 0};
float32_t IeVBII_ddeg_VehYawRate_test[] = { 0};
float32_t IeVBII_kph_VehSpeedVSOSig_test[] = { 0};
uint8_t IeVBII_cnt_LhfPulseCtr_test[] = { 0};
int32_t IeVBII_e_LhfWhlSpnSts_test[] = { 0};
float32_t IeVBII_kph_LhfWhlSpd_test[] = { 0};
uint8_t IeVBII_cnt_LhrPulseCtr_test[] = { 0};
float32_t IeVBII_kph_LhrWhlSpd_test[] = { 0};
uint8_t IeVBII_cnt_RhfPulseCtr_test[] = { 0};
int32_t IeVBII_e_RhfWhlSpnSts_test[] = { 0};
float32_t IeVBII_kph_RhfWhlSpd_test[] = { 0};
uint8_t IeVBII_cnt_RhrPulseCtr_test[] = { 0};
float32_t IeVBII_kph_RhrWhlSpd_test[] = { 0};
int32_t IeVBII_e_LhrWhlSpnSts_test[] = { 0};
int32_t IeVBII_e_RhrWhlSpnSts_test[] = { 0};
float32_t IeVBII_a_VehLatAccOffset_test[] = { 0};
float32_t IeVBII_a_VehLongAccOffset_test[] = { 0};
float32_t IeVBII_deg_StrWhlSpd_test[] = { 0};
int32_t IeVBII_e_SPMLatCtrlRespSts_test[] = { 0};
float32_t IeVBII_M_StrWhlTrq_test[] = { 0};
int32_t IeVBII_e_StrWhlAngleType_test[] = { 0};
uint8_t IeVBII_b_DriverDoorSts_test[] = { 0};
uint8_t IeVBII_b_TrnkStatus_test[] = { 0};
int32_t IeVBII_e_EngineSts_test[] = { 2};
int32_t IeVBII_e_TGWCamDispSts_test[] = { 0};
int32_t IeVBII_e_CamDispSts_test[] = { 0};
int32_t MeSVS_e_DispView2Info_test[] = { 13};
#include "IeVBII_e_GearEngagedForDsply.h"
#include "IeVBII_e_StrTrqResp.h"
#include "IeVBII_e_EnblBtnSts.h"
#endif

#endif // TRSC_SIMULATION_H

