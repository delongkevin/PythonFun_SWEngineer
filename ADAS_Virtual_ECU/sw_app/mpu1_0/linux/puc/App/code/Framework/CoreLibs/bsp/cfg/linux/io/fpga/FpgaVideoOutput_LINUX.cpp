//--------------------------------------------------------------------------
/// @file FpgaVideoOutput_LINUX.cpp
/// @brief Implementation of FPGA Video Output interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------


#include <platform/PlatformAPI.h>

#include <bsp/io/fpga/FpgaVideoOutput.h>

#include <bsp/io/fpga/FpgaParameters.h>

namespace bsp
{

#ifdef ME_PLATFORM_LINUX


FpgaVideoOutput::FpgaVideoOutput()
  : plBaseAddress_pv(NULL)
{
}

FpgaVideoOutput::~FpgaVideoOutput()
{

}

bool_t FpgaVideoOutput::initVideoOutput_b()
{

  return true;
}

void FpgaVideoOutput::powerEnable_v()
{
}

void FpgaVideoOutput::powerDisable_v()
{
}

#endif // ME_PLATFORM_LINUX

} // namespace bsp

