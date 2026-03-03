/// --------------------------------------------------------------------------
/// @file JobDLDInput.h
/// @brief Contains DLD detection input structure definition
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
/// --------------------------------------------------------------------------

#ifndef JOBDLD_INPUT_H
#define JOBDLD_INPUT_H

#include "../common/DLDDef.h"
#include "TeVBII_e_CmdIgnSts.h"

struct JobDLDInput_s
{
  /*
  @@ ELEMENT = InputImgColor_u8_ptr
  @@ STRUCTURE = JobDLDInput_s
  @@ A2L_TYPE = PARAMETER WRITEABLE
  @@ DATA_TYPE = ULONG
  @@ END
  */
  uint8_t* InputImgColor_pu8;
};

struct JobDLDVehicleInput_s
{
  uint8_t DriverDoorSts;
  uint8_t RHatchSts;
  uint8_t RHRDoorSts;
  uint8_t LHRDoorSts;
  uint8_t PsngrDoorSts;
  TeVBII_e_CmdIgnSts CmdIgnSts;
};

typedef struct JobDLDFIDs_s {
  uint8_t FID_DLD_FRONT_DISABLED;
  uint8_t FID_DLD_REAR_DISABLED;
  uint8_t FID_DLD_LEFT_DISABLED;
  uint8_t FID_DLD_RIGHT_DISABLED;
#if ENABLE_DLD_CHMSL_CAMERA
  uint8_t FID_DLD_CHMSL_DISABLED;
#endif
} JobDLDFIDs_t;

#endif

