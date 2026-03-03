//--------------------------------------------------------------------------
/// @file FpgaVideoInput.h
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

#ifndef FPGA_VIDEO_INPUT_H_
#define FPGA_VIDEO_INPUT_H_

#include <platform/PlatformAPI.h>

#include <osal/threading/Mutex.h>

#include <variants/Enums.h>

namespace bsp
{

const uint32_t c_MaxBuffer_u32 = 2U;

typedef struct VideoInputBufferDesc_s
{
  void*      buffers_apv[c_MaxBuffer_u32];
  uint32_t   numOfBuffer_u32;
  uint32_t   size_u32;
  uint32_t   format_u32;

} VideoInputBufferDesc_t;


class FpgaVideoInput
{
public:

  FpgaVideoInput();

  ~FpgaVideoInput();

  bool_t    initVideoInput_b();

public:

  void      powerEnable_v() const;

  void      powerDisable_v() const;

  void      autorunEnable_v();

  void      autorunDisable_v();

  bool_t    isStreaming_b() const;

  void      setFrameSync_v(variants::Camera_t i_Camera_t, bool_t i_Activate_b);

  void      switchMode_v(bool_t i_Mode_b) const;

public:

  uint32_t  getStatusRegister_u32(variants::Camera_t i_Camera_t);

  bool_t    getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc_t& o_VideoInputBufferDesc_rt) const;

  uint32_t  getCurrentBufferID_u32(variants::Camera_t i_CameraID_t);

private:

  /// -------------------------------------------------------------------------------

  osal::Mutex       mutex_o;

  bool_t            isInputStreaming_b;

  void*             plBaseAddress_pv;

  void*             videoInputBuffer_apv[variants::e_CameraCount][c_MaxBuffer_u32];

};


} // namespace bsp



#endif // FPGA_VIDEO_INPUT_H_
