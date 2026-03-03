/// @file   MOT_Inputs_Outputs.h
/// @brief  MOT IPC Interface Data Structure definition
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

#ifndef _MOT_INPUT_OUTPUT_H_
#define _MOT_INPUT_OUTPUT_H_

#include "PlatformDataTypes.h"
#include "JobKM.h"
/* ################# Inputs to MOT #############################*/
/*VCAN(MCU1_0) to MCU2_1 */
/*ME_VehInp_to_IpcSignals_t */

/*OD/THA(A72) to MCU2_1 */
/*DNN_Output*/

/* KM(MCU1_0) to MOT(A72)*/
/* ExtY_Kinematic_T;*/
/* #####################################################################*/

/* ################# Outputs from MOT #############################*/

/*MOT(A72) to MCU2_1*/
/*MOT_Output*/

// Dummy structure to remove compiler error
#ifndef MOT_OUTPUT_h_
#define MOT_OUTPUT_h_
typedef struct MOT_Output_s
{
  uint8_t dummy;
} MOT_Output;
#endif // MOT_OUTPUT_h_

#ifndef TbAPNFCD_VrntTunParam_s_h_
#define TbAPNFCD_VrntTunParam_s_h_
typedef struct TbAPNFCD_VrntTunParam_s
{
	float32_t Variant_WhlAngCFWt;
	float32_t Variant_WhlAngCFBias;
	uint16_t VEHICLE_LENGTH;
	uint16_t VEHICLE_WIDTH;
	uint16_t FRONT_OVERHANG;
	uint16_t REAR_OVERHANG;
	uint16_t WHEEL_BASE;
	uint8_t dummy1;
	uint32 dummy2[235];
}TbAPNFCD_VrntTunParam_t;
#endif // TbAPNFCD_VrntTunParam_s_h_
/* #####################################################################*/

#endif //_MOT_INPUT_OUTPUT_H_
