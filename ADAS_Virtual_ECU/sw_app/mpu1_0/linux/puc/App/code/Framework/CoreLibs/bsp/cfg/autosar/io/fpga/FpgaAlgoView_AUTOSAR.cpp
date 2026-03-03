//--------------------------------------------------------------------------
/// @file FpgaAlgoView_AUTOSAR.cpp
/// @brief Implementation of FPGA Algo View Interface
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

#include "bsp/io/fpga/FpgaAlgoView.h"

#ifdef ME_PLATFORM_AUTOSAR


namespace bsp
{
  
FpgaAlgoView::FpgaAlgoView()
{
}

FpgaAlgoView::~FpgaAlgoView()
{
}


bool_t FpgaAlgoView::initAlgoView_b()
{
  return true;
}


bool_t FpgaAlgoView::checkRxPacketCount_b(uint8_t i_ViewId_u8)
{
  bool_t v_Result_b = false;

  return v_Result_b;
}

void FpgaAlgoView::clearRxStatusFlags_v(uint32_t v_I_u32)
{
}

void FpgaAlgoView::algoviewTrigger_v(uint32_t i_CameraId_t, bool_t algoTriggerFlag_b)
{
}

uint32_t FpgaAlgoView::readAlgoviewStatus_u32(uint32_t i_CameraId_t)
{
  uint32_t status_u32 = 0x0;
  
  return status_u32;
}

uint32_t FpgaAlgoView::frameBufferAvail_u32(uint32_t i_CameraId_t)
{
  uint32_t algobufstatus_u32 = 0x0;

  return algobufstatus_u32;
}

uint32_t FpgaAlgoView::captureFrameBuffer_u32(uint32_t i_CameraId_t)
{
  uint32_t algobufstatus_u32 = 0x0;

  return algobufstatus_u32;
}

} // namespace bsp

#endif // ME_PLATFORM_AUTOSAR

