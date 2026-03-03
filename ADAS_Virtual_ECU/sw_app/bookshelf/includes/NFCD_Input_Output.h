/// @file   NFCD_Inputs_Outputs.h
/// @brief  NFCD IPC Interface Data Structure definition
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

#ifndef _NFCD_INPUT_OUTPUT_H_
#define _NFCD_INPUT_OUTPUT_H_

#include "PlatformDataTypes.h"
#include "MOT_Input_Output.h"
#include "JobKM.h"
/* ################# Inputs to NFCD #############################*/
/*VCAN(MCU1_0) to MCU2_1 */
/*ME_VehInp_to_IpcSignals_t */

/*USS(MCU2_1) to MCU2_1 */
/*IUPASensorDataV2_t*/

/* KM(MCU1_0) to NFCD(MCU2_1)*/
/* ExtY_Kinematic_T;*/

/* CalData(MCU1_0) to NFCD(MCU2_1)*/
/* #####################################################################*/

/* ################# Outputs from NFCD #############################*/

/*NFCD(MCU2_1) to MCU2_1*/
#ifndef NFCD_Output_h_
#define NFCD_Output_h_
typedef struct NFCD_Output_s
{
    uint8_t dummy;
}NFCD_Output;
#endif // NFCD_Output_h_
/* #####################################################################*/

#endif //_NFCD_INPUT_OUTPUT_H_
