/// --------------------------------------------------------------------------
/// @file DLD_Input_Output.h
/// @brief Contains DLD detection input/output structure definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------

#ifndef DLD_INPUT_OUTPUT_H
#define DLD_INPUT_OUTPUT_H

typedef enum DLDCamSts_e
{
	DLD_Normal = 0,
	DLD_Blockage = 1,
	DLD_Low_Luminance = 2,
	DLD_BackLit = 3,
  DLD_Unknown = 10
} DLDCamSts_t;

/* DLD Diagnostics output from A72 to MCU1_0 */
typedef struct JobDLDOutput_s {
  DLDCamSts_t IeDLD_e_FrCamSts;       /* DLD_Normal = 0, DLD_Blockage = 1, DLD_Low_Luminance = 2, DLD_BackLit = 3, DLD_Unknown = 10 */
  DLDCamSts_t IeDLD_e_RrCamSts;       /* DLD_Normal = 0, DLD_Blockage = 1, DLD_Low_Luminance = 2, DLD_BackLit = 3, DLD_Unknown = 10 */
  DLDCamSts_t IeDLD_e_RyCamSts;       /* DLD_Normal = 0, DLD_Blockage = 1, DLD_Low_Luminance = 2, DLD_BackLit = 3, DLD_Unknown = 10 */
  DLDCamSts_t IeDLD_e_LyCamSts;       /* DLD_Normal = 0, DLD_Blockage = 1, DLD_Low_Luminance = 2, DLD_BackLit = 3, DLD_Unknown = 10 */
  uint8_t     IeDLD_p_FrCamOcclnPerc; /* Front - Occlusion percentage 0 to 100% */
  uint8_t     IeDLD_p_FrCamLoLumPerc; /* Front - Low light percentage 0 to 100% */
  uint8_t     IeDLD_p_RrCamOcclnPerc; /* Rear - Occlusion percentage 0 to 100% */
  uint8_t     IeDLD_p_RrCamLoLumPerc; /* Rear - Low light percentage 0 to 100% */
  uint8_t     IeDLD_p_LyCamOcclnPerc; /* Left - Occlusion percentage 0 to 100% */
  uint8_t     IeDLD_p_LyCamLoLumPerc; /* Left - Low light percentage 0 to 100% */
  uint8_t     IeDLD_p_RyCamOcclnPerc; /* Right - Low light percentage 0 to 100% */
  uint8_t     IeDLD_p_RyCamLoLumPerc; /* Right - Low light percentage 0 to 100% */
  bool_t      IeDLD_b_FrCamOcclnSts;  /* Front - Occlusion status - Normal = 0, Occluded = 1 */
  bool_t      IeDLD_b_FrCamLoLumSts;  /* Front - Low light status - Normal = 0, Low Light = 1 */
  bool_t      IeDLD_b_RrCamOcclnSts;  /* Rear - Occlusion status - Normal = 0, Occluded = 1 */
  bool_t      IeDLD_b_RrCamLoLumSts;  /* Rear - Low light status - Normal = 0, Low Light = 1 */
  bool_t      IeDLD_b_LyCamOcclnSts;  /* Left - Occlusion status - Normal = 0, Occluded = 1 */
  bool_t      IeDLD_b_LyCamLoLumSts;  /* Left - Low light status - Normal = 0, Low Light = 1 */
  bool_t      IeDLD_b_RyCamOcclnSts;  /* Right - Occlusion status - Normal = 0, Occluded = 1 */
  bool_t      IeDLD_b_RyCamLoLumSts;  /* Right - Low light status - Normal = 0, Low Light = 1 */
} JobDLDOutput_t;

#endif // DLD_INPUT_OUTPUT_H
