//--------------------------------------------------------------------------
/// @file FpgaVideoInput.cpp
/// @brief Implementation of FPGA Video Input interface
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

#include <bsp/io/fpga/FpgaVideoInput.h>

#include <bsp/io/fpga/FpgaParameters.h>

namespace bsp
{

#ifdef ME_PLATFORM_WIN

FpgaVideoInput::FpgaVideoInput()
  : plBaseAddress_pv(NULL)
{
  for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraCount; v_I_u32++)
  {
    videoInputBuffer_apv[v_I_u32][0] = NULL;
    videoInputBuffer_apv[v_I_u32][1] = NULL;
  }
}

FpgaVideoInput::~FpgaVideoInput()
{

}

bool_t FpgaVideoInput::initVideoInput_b()
{
  // get pointer to physical address

  // enable VIIF

  // set initial ID for write and read buffer

  return true;
}

void FpgaVideoInput::powerEnable_v() const
{
}

void FpgaVideoInput::powerDisable_v() const
{
}

void FpgaVideoInput::autorunEnable_v()
{

}

void FpgaVideoInput::autorunDisable_v()
{

}

bool_t FpgaVideoInput::isStreaming_b() const
{
  return true;
}

void FpgaVideoInput::setFrameSync_v(variants::Camera_t i_Camera_t, bool_t i_Activate_b)
{
}

void FpgaVideoInput::switchMode_v(bool_t i_Mode_b) const
{

}

bool_t FpgaVideoInput::getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc_t& o_VideoInputBufferDesc_rt) const
{
  return true;
}

// does also the swap
uint32_t FpgaVideoInput::getCurrentBufferID_u32(variants::Camera_t i_CameraID_t)
{
  return 0;
}

#endif // ME_PLATFORM_QNX

} // namespace bsp

