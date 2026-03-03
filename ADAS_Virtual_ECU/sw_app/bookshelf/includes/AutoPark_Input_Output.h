/// @file   AutoPark_Inputs_Outputs.h
/// @brief  AutoPark IPC Interface Data Structure definition
///
///  AutoPark IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Kedar Naphad (kedar.naphad@magna.com)
///

#ifndef _AUTO_PARK_INPUT_OUTPUT_H_
#define _AUTO_PARK_INPUT_OUTPUT_H_

#include "PlatformDataTypes.h"
#include "APA_ModelOutput.h"
#include "SM_ModelOutput.h"
#include "VC_ModelOutput.h"
#include "APFusion_Interface.h"
#include "THAFeatureOutputs.h"
#include "ObjectFusion_Input_Output.h"
#include "MOT_Input_Output.h"
#include "AP_VrntTunParam.h"
#include "AP_DebugOut.h"
#include "SWC_APA_types.h"

/* ################# Inputs to Auto Park #############################*/
/*VCAN(MCU1_0) to MCU2_1 */
/*ME_VehInp_to_IpcSignals_t */

/*NVM(TBD) to MCU2_1 */
/*TbNVM_ReadParam */
/*TbNVM_ProxyCalibParam */

/*USS(MCU2_1) to MCU2_1 */
/*IUPASensorDataV2_t*/

/*FPA(MCU2_1) to MCU2_1*/
/*JobFPAOutput_t */

/*THA(MCU2_1) to MCU2_1*/
/*TbTHASmVc_FeatureOutputs_t */

/*NFCD(MCU2_1) to MCU2_1*/
/*NFCD_Output*/

/*TRSC (MCU2_0) to Auto Park SM VC(MCU2_1)*/
/*ME_VehOut_TRSC_t*/

/*MCU1_0 to Auto Park (MCU2_1) */
/*FID_STRUCT_A*/

/*MCU1_0 to Auto Park (MCU2_1) */
/*FID_STRUCT_B*/

/*HMI(MCU2_0) to Auto Park(MCU2_1)*/
/*HMIInfoToAP_t*/

/*CalData(MCU1_0) to Auto Park(MCU2_1)*/
/*TbAP_VrntTunParam_t */

/* #####################################################################*/

/* ################# Outputs from Auto Park #############################*/

/* SM model output*/
/* MCU2_1 to MCU1_0(VCAN) and A72(PLD)*/
/* TbAP_DriveAssistStatOut_t  */

/* MCU2_1 to MCU1_0(VCAN)/MCU2_1(Arbitration)*/
/* TbAP_SMDAInternalOut_t */

/* MCU2_1 to MCU2_0(THA_SM_VC)*/
/* TbAP_APSMPAOut_t */

/* MCU2_1 to MCU2_1*/
/* TbAP_SMPAInternalOut_t */

/* APA model output*/
/* MCU2_1 to MCU1_0(VCAN)/MCU2_1(Arbitration)*/
/* TbAP_FPAWarnOut_t */

/* MCU2_1 to MCU1_0(VCAN)/MCU2_1(Arbitration)*/
/* TbAP_RPAWarnOut_t */

/* MCU2_1 to MCU1_0(VCAN)/MCU2_1(Arbitration)*/
/* TbAP_PAStateOut_t */

/* VC model output*/
/* MCU2_1 to MCU2_1*/
/* TbAP_VCTrajOut_t */

/* MCU2_1 to MCU1_0(VCAN)/MCU2_1(Arbitration)*/
/* TbAP_VCStateOut_t */

/* MCU2_1(Auto Park) to MCU2_1(USS Manager)*/
/*TbAP_USSStateOut_t*/

/* MCU2_1 to MCU1_0(VCAN)*/
/* TbAP_DebugOut; */
/* #####################################################################*/

#endif //_AUTO_PARK_INPUT_OUTPUT_H_
