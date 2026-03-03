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
///         Gangadhar Reddy Yadiki(GangadharReddy.Yadiki@magna.com)
//  --------------------------------------------------------------------------

#include <platform/PlatformAPI.h>

#include <variants/Enums.h>

#include "bsp/io/fpga/FpgaAlgoView.h"
#include "bsp/io/fpga/FpgaParameters.h"
#include "bsp/io/fpga/FpgaHelper.h"

#ifdef ME_PLATFORM_QNX

namespace bsp
{



static const uint32_t s_CameraSelect_u32[] =
{
  0x00000038U,
  0x00000012U,
  0x00000024U,
  0x00000001U
};


static const uint32_t s_RxRegisters_au32[] = {c_VideoInCsi2RxBase1_u32,
                                              c_VideoInCsi2RxBase2_u32,
                                              c_VideoInCsi2RxBase3_u32,
                                              c_VideoInCsi2RxBase4_u32,
                                              c_VideoInCsi2RxBase5_u32,
                                              c_VideoInCsi2RxBase6_u32};



FpgaAlgoView::FpgaAlgoView()
  : mutex_o()
  , plBaseAddress_pv(NULL)
  , algoViewBaseAddress1_pv(NULL)
  , algoViewBaseAddress2_pv(NULL)
  , selectedCamera_u32(0U)
{
  for(uint32_t v_I_u32 = 0; v_I_u32 < c_AlgoViewBufferCount_u32; v_I_u32++)
  {
    algoViewBuffer_pau8[v_I_u32] = NULL;
    algoViewFullBuffer_pau8[v_I_u32] = NULL;
  }
}

FpgaAlgoView::~FpgaAlgoView()
{

}


bool_t FpgaAlgoView::initAlgoView_b()
{
  ME_IO_MapDeviceAdress_b(c_AxiLiteBase_u32, c_AxiLiteSize_u32, &plBaseAddress_pv);
  ME_IO_MapDeviceAdress_b(c_VideoInAlgoView1Offset_u32, 0x1000U, &algoViewBaseAddress1_pv);
  ME_IO_MapDeviceAdress_b(c_VideoInAlgoView1Offset_u32, 0x1000U, &algoViewBaseAddress2_pv);

  void* v_ShrMemPtr_pv;
  ME_IO_MapDeviceAdress_b(c_AlgoViewBuffer0_u32, (c_AlgoViewBufferWidth_u32 * c_AlgoViewBufferHeight_u32 ), &v_ShrMemPtr_pv);
  algoViewBuffer_pau8[0] = static_cast<uint8_t*>(v_ShrMemPtr_pv);

  ME_IO_MapDeviceAdress_b(c_AlgoViewBuffer1_u32, (c_AlgoViewBufferWidth_u32 * c_AlgoViewBufferHeight_u32 ), &v_ShrMemPtr_pv);
  algoViewBuffer_pau8[1] = static_cast<uint8_t*>(v_ShrMemPtr_pv);

  ME_IO_MapDeviceAdress_b(c_AlgoViewFullBuffer0_u32, (c_AlgoViewFullBufferWidth_u32 * c_AlgoViewFullBufferHeight_u32 ), &v_ShrMemPtr_pv);
  algoViewFullBuffer_pau8[0] = static_cast<uint8_t*>(v_ShrMemPtr_pv);

  ME_IO_MapDeviceAdress_b(c_AlgoViewFullBuffer1_u32, (c_AlgoViewFullBufferWidth_u32 * c_AlgoViewFullBufferHeight_u32 ), &v_ShrMemPtr_pv);
  algoViewFullBuffer_pau8[1] = static_cast<uint8_t*>(v_ShrMemPtr_pv);

  return true;
}


const uint8_t* FpgaAlgoView::getAlgoViewBuffer_pu8(uint32_t i_CameraId_u32, bool_t i_FullBuffer_b)
{
  uint8_t* v_ReturnBuffer_pu8 = NULL;

  mutex_o.take_b();

  uint32_t v_Status_u32 = captureFrameBuffer_u32(i_CameraId_u32);

  if(0x10U == v_Status_u32)
  {
    v_ReturnBuffer_pu8 = i_FullBuffer_b ? algoViewFullBuffer_pau8[0] : algoViewBuffer_pau8[0];
  }
  else if(0x11U == v_Status_u32)
  {
    v_ReturnBuffer_pu8 = i_FullBuffer_b ? algoViewFullBuffer_pau8[1] : algoViewBuffer_pau8[1];
  }
  else
  {
    // do nothing
  }

  if(v_ReturnBuffer_pu8 != NULL)
  {
    selectedCamera_u32 = i_CameraId_u32;
  }

  mutex_o.give_v();

  return v_ReturnBuffer_pu8;
}

uint32_t FpgaAlgoView::getSelectedCamera_u32()
{
  uint32_t v_Result_u32 = 0;
  mutex_o.take_b();
  v_Result_u32 = selectedCamera_u32;
  mutex_o.give_v();

  return v_Result_u32;
}


bool_t FpgaAlgoView::checkRxPacketCount_b(uint8_t i_ViewId_u8)
{
  bool_t v_Result_b = false;

  uint32_t v_ReadSize_u32 = 1;
  uint32_t v_PacketCount1_u32 = 0;
  uint32_t v_PacketCount2_u32 = 0;
  uint32_t v_PacketCount3_u32 = 0;

  ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount1_u32);
  ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount2_u32);
  ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount3_u32);


  if((v_PacketCount1_u32 == v_PacketCount2_u32) && (v_PacketCount1_u32 == v_PacketCount3_u32))
  {
    ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount1_u32);
    ME_Thread_Sleep_t(5);
    ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount2_u32);
    ME_Thread_Sleep_t(5);
    ME_IO_In32_b(plBaseAddress_pv, s_RxRegisters_au32[i_ViewId_u8] + 0x10U, &v_PacketCount3_u32);

    if((v_PacketCount1_u32 == v_PacketCount2_u32) && (v_PacketCount1_u32 == v_PacketCount3_u32))
    {
      v_Result_b = false;
    }
    else
    {
      v_Result_b = true;
    }
  }
  else
  {
    v_Result_b = true;
  }

   return v_Result_b;
}

void FpgaAlgoView::clearRxStatusFlags_v(uint32_t v_ViewId_u32)
{
  ME_IO_Out32_b(plBaseAddress_pv, s_RxRegisters_au32[v_ViewId_u32] + 0x24U, 0xFFFF);
}

void FpgaAlgoView::algoViewTrigger_v(uint32_t i_CameraId_t, bool_t i_AlgoTriggerFlag_b)
{
  bool_t v_Result_b = true;
  
  ME_IO_Out32_b(plBaseAddress_pv, c_VideoInAlgoView1Offset_u32 + 8U, s_CameraSelect_u32[mapOldCameraId_u32(static_cast<variants::Camera_t>(i_CameraId_t))]);

  if(i_AlgoTriggerFlag_b == 0x01U)
  {
    ME_IO_Out32_b(plBaseAddress_pv, c_VideoInAlgoView1Offset_u32, 0x01U);
  }
  else
  {
    ME_IO_Out32_b(plBaseAddress_pv, c_VideoInAlgoView1Offset_u32, 0x00U);
  }
}

uint32_t FpgaAlgoView::readAlgoViewStatus_u32(uint32_t i_CameraId_t)
{
  uint32_t v_Status_u32 = 0x0;
  uint32_t v_ReadSize_u32 = 0x1;

  while((v_Status_u32 != 0x10U) && (v_Status_u32 != 0x11U))
  {
    ME_IO_In32_b(plBaseAddress_pv, c_VideoInAlgoView2Offset_u32, &v_Status_u32);
    //ME_Thread_Sleep_t(32);
  }

  return v_Status_u32;
}

uint32_t FpgaAlgoView::frameBufferAvailable_u32(uint32_t i_CameraId_t)
{
  static bool_t s_FirstTrigger_b = true;

  uint32_t v_AlgoBufferStatus_u32 = 0x0;

  if (s_FirstTrigger_b == true)
  {
    algoViewTrigger_v(i_CameraId_t, 1);
    ME_Thread_Sleep_t(1);
    algoViewTrigger_v(i_CameraId_t, 0);
    ME_Thread_Sleep_t(15);
    s_FirstTrigger_b = false;
  }

  v_AlgoBufferStatus_u32 = readAlgoViewStatus_u32(i_CameraId_t);
  algoViewTrigger_v(i_CameraId_t, 1);
  ME_Thread_Sleep_t(1);
  algoViewTrigger_v(i_CameraId_t, 0);
  
  return v_AlgoBufferStatus_u32;
}

uint32_t FpgaAlgoView::captureFrameBuffer_u32(uint32_t i_CameraId_t)
{
  uint32_t v_AlgoBufferStatus_u32 = 0x0;
  bool_t v_CountCheck_b = false;

  v_AlgoBufferStatus_u32 = frameBufferAvailable_u32(i_CameraId_t);

  return v_AlgoBufferStatus_u32;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX

