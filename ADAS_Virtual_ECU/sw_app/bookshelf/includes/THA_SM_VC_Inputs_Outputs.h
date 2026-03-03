/// @file   THA_SM_VC_Inputs_Outputs.h
/// @brief  THA SM VC IPC Interface Data Structure definition
///
///  THA SM VC IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Afshan Shaikh (afshan.shaikh@magna.com)
/// --------------------------------------------------------------------------

#ifndef THA_SM_VC_INPUTS_OUTPUTS_H_INCGUARD
#define THA_SM_VC_INPUTS_OUTPUTS_H_INCGUARD

#include "../magna_apps/tha_sm_vc/THA_SWC_ert_rtw/THA_SWC_types.h"

/* ------------------- Inputs to THA_SM_VC ------------------- */
/* THA Detection to THA_SM_VC, A72 to mcu2_1*/
/* JobTHADetOutput_t */ 

/* HMI SVS to THA_SM_VC, mcu2_0 to mcu2_1*/
/* SvsToTHA_t */
/* SvsToVCAN_t */

/* Vehicle CAN to THA_SM_VC, mcu1_0 to mcu2_1*/
/* ME_VehInp_to_IpcSignals_t */

/* AutoPark SMVC to THA_SM_VC, mcu2_1 to mcu2_1*/
/* TbAP_APSMPAOut_t */
/* TbAP_DriveAssistStatOut_t */

/* Proxi manager to THA_SM_VC, mcu2_0 to mcu2_1*/
/* ME_ProxiToMCU2_1_Def_t */

/* TRSC SM VC output, mcu2_0 to mcu2_1 */
/* ME_VehOut_TRSC_t */

/* Degradation manager, mcu1_0 to mcu2_1 */
/* FID_STRUCT_QM */

/*CalDataProvider,mcu1_0 to mcu2_1 */
/* CalDataProvider_MCU_2_1_Def */

/* Tunable parameter, mcu1_0 to mcu2_1*/
/* TbTHASmVc_VrntTunParam_t */

/* ------------------- Output from THA_SM_VC ------------------- */

/* To HMI              : mcu2_1 to mcu2_0
   To THA_Detection    : mcu2_1 to A72
   To Rear Park assist : mcu2_1 to mcu2_1
   To VCAN             : mcu2_1 to mcu1_0
*/
/* TbTHASmVc_FeatureOutputs_t */

/* To Diag Manager, MCU2_1 to R5_MCU1_0
   To THA Detection,MCU2_1 to A72_MPU1_0*/
/* TbTHASmVc_DiagMgr_t */

#endif // THA_SM_VC_INPUTS_OUTPUTS_H_INCGUARD
