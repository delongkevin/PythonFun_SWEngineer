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

#include <bsp/io/fpga/AxisMipMem.h>

namespace bsp
{

#ifdef ME_PLATFORM_QNX

static const uint32_t v_Offsets_au32[] = {bsp::c_VideoInCsi2RxBase1_u32,
                                          bsp::c_VideoInCsi2RxBase2_u32,
                                          bsp::c_VideoInCsi2RxBase3_u32,
                                          bsp::c_VideoInCsi2RxBase4_u32,
                                          bsp::c_VideoInCsi2RxBase5_u32,
                                          bsp::c_VideoInCsi2RxBase6_u32};

static const uint32_t v_VideoBuffer0Adresses_au32[] = {
  c_VideoInCamera0Buffer0_u32,
  c_VideoInCamera1Buffer0_u32,
  c_VideoInCamera2Buffer0_u32,
  c_VideoInCamera3Buffer0_u32
};

static const uint32_t v_VideoBuffer1Adresses_au32[] = {
  c_VideoInCamera0Buffer1_u32,
  c_VideoInCamera1Buffer1_u32,
  c_VideoInCamera2Buffer1_u32,
  c_VideoInCamera3Buffer1_u32
};


FpgaVideoInput::FpgaVideoInput()
  : mutex_o()
  , isInputStreaming_b(false)
  , plBaseAddress_pv(NULL)
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
  ME_IO_MapDeviceAdress_b(c_AxiLiteBase_u32, c_AxiLiteSize_u32, &plBaseAddress_pv);

  powerEnable_v();

  for(uint32_t v_I_u32 = 0; v_I_u32 < (static_cast<uint8_t>(variants::e_CameraCount) - 1U); v_I_u32++)
  {
    ME_SharedMemory_MapPhysicalByAddress_t(v_VideoBuffer0Adresses_au32[v_I_u32], 0x004b0000U, &videoInputBuffer_apv[v_I_u32][0]);
    ME_SharedMemory_MapPhysicalByAddress_t(v_VideoBuffer1Adresses_au32[v_I_u32], 0x004b0000U, &videoInputBuffer_apv[v_I_u32][1]);
  }

  for(uint32_t v_I_u32 = 0; v_I_u32 < variants::e_CameraCount; v_I_u32++)
  {
    ME_IO_Out32_b(plBaseAddress_pv, v_Offsets_au32[v_I_u32], 0x00000002U);
    ME_IO_Out32_b(plBaseAddress_pv, v_Offsets_au32[v_I_u32], 0x00000001U);
  }

#if 0
  void* test = NULL;
  ME_IO_MapDeviceAdress_b(0x80011000, 1, &test);
  ME_IO_Out32_b(test, 0, 0x00000001U);
#endif

  // set initial ID for write and read buffer

  return true;
}

void FpgaVideoInput::powerEnable_v() const
{
  uint32_t v_VideoInReg_u32 = 0x00U;
  ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, &v_VideoInReg_u32);

  v_VideoInReg_u32 |= 0x00040000U;
  ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, v_VideoInReg_u32);
}

void FpgaVideoInput::powerDisable_v() const
{
  uint32_t v_VideoInReg_u32 = 0x00U;
  ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, &v_VideoInReg_u32);

  v_VideoInReg_u32 &= ~(0x00040000U);
  ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIO1Offset_u32, v_VideoInReg_u32);
}

void FpgaVideoInput::autorunEnable_v()
{
  uint32_t v_ReadVal_u32 = 0x00U;
  mutex_o.take_b();
  do
  {
    ME_IO_Out32_b(plBaseAddress_pv, 0x16020U, 0x06U);
    ME_Thread_Sleep_t(1);
    ME_IO_In32_b(plBaseAddress_pv, 0x16020U, &v_ReadVal_u32);

    ME_Debugger_F_Printf_v("FgpaVideoInput::autorunEnable reg: 0x%x\n", v_ReadVal_u32);
  }
  while((v_ReadVal_u32 & 0x06) != 0x06U);
  isInputStreaming_b = true;
  mutex_o.give_v();
}

void FpgaVideoInput::autorunDisable_v()
{
  mutex_o.take_b();
  ME_IO_Out32_b(plBaseAddress_pv, 0x16020U, 0x00000000U);
  isInputStreaming_b = false;
  mutex_o.give_v();
}

bool_t FpgaVideoInput::isStreaming_b() const
{
  return isInputStreaming_b;
}

void FpgaVideoInput::setFrameSync_v(variants::Camera_t i_Camera_t, bool_t i_Activate_b)
{
  uint32_t v_ReadVal_u32 = 0x00U;
  mutex_o.take_b();

  ME_IO_In32_b(plBaseAddress_pv, 0x16028U, &v_ReadVal_u32);

  if(i_Activate_b == true)
  {
    uint32_t v_WriteVal_u32 = v_ReadVal_u32 | (1U << i_Camera_t);

    do
    {
      ME_IO_Out32_b(plBaseAddress_pv, 0x16028U, v_WriteVal_u32);
      ME_Thread_Sleep_t(1);
      ME_IO_In32_b(plBaseAddress_pv, 0x16028U, &v_ReadVal_u32);

      ME_Debugger_F_Printf_v("FgpaVideoInput::setFrameSync_v reg: 0x%x\n", v_ReadVal_u32);
    }
    while(v_ReadVal_u32 != v_WriteVal_u32);
  }
  else
  {
    uint32_t v_WriteVal_u32 = v_ReadVal_u32 & ~(1U << i_Camera_t);

    do
    {
      ME_IO_Out32_b(plBaseAddress_pv, 0x16028U, v_WriteVal_u32);
      ME_Thread_Sleep_t(1);
      ME_IO_In32_b(plBaseAddress_pv, 0x16028U, &v_ReadVal_u32);

      ME_Debugger_F_Printf_v("FgpaVideoInput::setFrameSync_v reg: 0x%x\n", v_ReadVal_u32);
    }
    while(v_ReadVal_u32 != v_WriteVal_u32);
  }

  mutex_o.give_v();
}

void FpgaVideoInput::switchMode_v(bool_t i_Mode_b) const
{
}

uint32_t FpgaVideoInput::getStatusRegister_u32(variants::Camera_t i_Camera_t)
{
  uint32_t v_ReadVal_u32 = 0x00U;
  ME_IO_In32_b(plBaseAddress_pv, v_Offsets_au32[i_Camera_t] + 0x20U, &v_ReadVal_u32);

  return v_ReadVal_u32;
}


bool_t FpgaVideoInput::getVideoInputBuffer_b(variants::Camera_t i_CameraID_t, VideoInputBufferDesc_t& o_VideoInputBufferDesc_rt) const
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
  uint32_t v_ReadBufferID_u32 = 0x00;
  ME_IO_In32_b(plBaseAddress_pv, 0x16018U, &v_ReadBufferID_u32);


  return v_ReadBufferID_u32;
}

#endif // ME_PLATFORM_QNX

} // namespace bsp

