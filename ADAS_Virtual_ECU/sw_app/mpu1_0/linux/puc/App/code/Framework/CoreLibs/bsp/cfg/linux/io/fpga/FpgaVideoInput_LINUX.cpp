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

#ifdef ME_PLATFORM_LINUX

FpgaVideoInput::FpgaVideoInput()
  : plBaseAddress_pv(NULL)
  , currentReadBufferID_u32(0U)
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

  // set initial ID for write and read buffer

  return true;
}

void FpgaVideoInput::powerEnable_v()
{
}

void FpgaVideoInput::powerDisable_v()
{
}

void FpgaVideoInput::setFrameSync_v(bool_t i_Activate_b)
{
}

void FpgaVideoInput::switchMode_v(bool_t i_Mode_b)
{

}

bool_t FpgaVideoInput::getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc_t& o_VideoInputBufferDesc_rt)
{
  o_VideoInputBufferDesc_rt.numOfBuffer_u32 = 2U;
  o_VideoInputBufferDesc_rt.size_u32 = 0x4B0000U;
  o_VideoInputBufferDesc_rt.buffers_apv[0] = videoInputBuffer_apv[i_CameraID_t][0];
  o_VideoInputBufferDesc_rt.buffers_apv[1] = videoInputBuffer_apv[i_CameraID_t][1];

  return true;
}


// does also the swap
uint32_t FpgaVideoInput::getCurrentBufferID_u32(variants::Camera_t i_CameraID_t)
{
  currentReadBufferID_u32 = !currentReadBufferID_u32;

  return currentReadBufferID_u32;
}

#endif // ME_PLATFORM_QNX

} // namespace bsp

