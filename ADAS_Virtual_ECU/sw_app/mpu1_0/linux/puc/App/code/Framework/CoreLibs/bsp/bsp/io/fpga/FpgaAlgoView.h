//--------------------------------------------------------------------------
/// @file Cam.cpp
/// @brief Implementation of QNX camera interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_ALGO_VIEW_H_
#define FPGA_ALGO_VIEW_H_

#include <platform/PlatformAPI.h>

#include <osal/threading/Mutex.h>

namespace bsp
{


class FpgaAlgoView
{
public:

  FpgaAlgoView();

  ~FpgaAlgoView();

  bool_t  initAlgoView_b();

public:

  const uint8_t* getAlgoViewBuffer_pu8(uint32_t i_CameraID_u32, bool_t i_FullBuffer_b);

  uint32_t       getSelectedCamera_u32();

private:

  uint32_t      captureFrameBuffer_u32(uint32_t i_CameraId_t);

  void          clearRxStatusFlags_v(uint32_t v_I_u32);

  bool_t        checkRxPacketCount_b(uint8_t i_ViewId_u8);

  void          algoViewTrigger_v(uint32_t i_CameraId_t, bool_t algoTriggerFlag_b);

  uint32_t      frameBufferAvailable_u32(uint32_t i_CameraId_t);

  uint32_t      readAlgoViewStatus_u32(uint32_t i_CameraId_t);

private:

  osal::Mutex   mutex_o;

  void*         plBaseAddress_pv;

  void*         algoViewBaseAddress1_pv;
  void*         algoViewBaseAddress2_pv;

  uint8_t*      algoViewBuffer_pau8[2];
  uint8_t*      algoViewFullBuffer_pau8[2];

  uint32_t      selectedCamera_u32;
};


} // namespace bsp



#endif // FPGA_ALGO_VIEW_H_
