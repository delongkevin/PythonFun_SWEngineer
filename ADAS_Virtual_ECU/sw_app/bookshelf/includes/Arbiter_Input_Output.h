/// @file   Arbiter_Inputs_Outputs.h
/// @brief  Arbiter IPC Interface Data Structure definition
///
///  Arbiter IPC Interface Data Structure definition
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author  Dipti Natu (dipti.natu@magna.com)
///

#ifndef _ARBITER_INPUT_OUTPUT_H_
#define _ARBITER_INPUT_OUTPUT_H_

#include "APA_ModelOutput.h"
#include "THAFeatureOutputs.h"
#include "SM_ModelOutput.h"
#include "FOD_Input_Output.h" //Added here as currently definition is available here
#include "FeatureArbiterOutputs.h"

/* ################# Inputs to Arbiter #############################*/
/*AP MCU2_1 to MCU2_1 */
/*TbAP_FPAWarnOut_t */

/*AP MCU2_1 to MCU2_1 */
/*TbAP_RPAWarnOut_t */

/*AP MCU2_1 to MCU2_1 */
/*TbAP_PAStateOut_t */

/*THA SM VC MCU2_1 to MCU2_1*/
/*TbTHASmVc_FeatureOutputs_t */

/*AP MCU2_1 to MCU2_1*/
/*TbAP_DriveAssistStatOut_t */

/*AP MCU2_1 to MCU2_1*/
/*TbAP_SMPAInternalOut_t */

/*AP MCU2_1 to MCU2_1*/
/*TbAP_USSStateOut_t*/

/*FOD MCU2_1 to MCU2_1*/
/*IFOD_Outputs_Arbitration_t*/

/*AP MCU2_1 to MCU2_1*/
/*TbAP_SMDAInternalOut_t*/

/* #####################################################################*/

/* ################# Outputs from Arbiter #############################*/

/* MCU2_1 to MCU1_0*/
/*TbFA_ArbiterOutput_t  */

/* MCU2_1 to MCU2_1*/
/*TbFA_USSStateOutput_t*/

/* MCU2_1 to MCU1_0*/
/*TbFA_ResetKM_t*/

/* #####################################################################*/

#endif //_ARBITER_INPUT_OUTPUT_H_
