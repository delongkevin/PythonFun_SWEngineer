//--------------------------------------------------------------------------
/// @file FpgaVideoOutput.cpp
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

#ifdef ME_PLATFORM_QNX


FpgaVideoOutput::FpgaVideoOutput()
  : plBaseAddress_pv(NULL)
{
}

FpgaVideoOutput::~FpgaVideoOutput()
{

}

bool_t FpgaVideoOutput::initVideoOutput_b()
{
  // get pointer to physical address
  ME_IO_MapDeviceAdress_b(c_AxiLiteBase_u32, c_AxiLiteSize_u32, &plBaseAddress_pv);

  if(plBaseAddress_pv != NULL)
  {
    powerEnable_v();

    ME_Thread_Sleep_t(10);

    ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoOutCsi2TxBase_u32              , 0x00000002U);
    ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoOutCsi2TxBase_u32 + 0x00000040U, 0x00000438U);
    ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoOutCsi2TxBase_u32 + 0x00000004U, 0x00008009U);
    ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoOutCsi2TxBase_u32 + 0x00000000U, 0x00000001U);

    uint32_t v_TxReady_u32 = 0x00U;
    while(((v_TxReady_u32 >> 2) & 1) == 0)
    {
      ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoOutCsi2TxBase_u32, &v_TxReady_u32);
    }
  }

  return true;
}

void FpgaVideoOutput::powerEnable_v() const
{
  uint32_t v_VideoOutReg_u32 = 0x00U;
  ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIOSerCEBaseOffset_u32, &v_VideoOutReg_u32);

  v_VideoOutReg_u32 |= 0x00000001U;
  ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIOSerCEBaseOffset_u32, v_VideoOutReg_u32);
}

void FpgaVideoOutput::powerDisable_v() const
{
  uint32_t v_VideoOutReg_u32 = 0x00U;
  ME_IO_In32_b(plBaseAddress_pv, bsp::c_VideoInGPIOSerCEBaseOffset_u32, &v_VideoOutReg_u32);

  v_VideoOutReg_u32 &= ~(0x00000001U);
  ME_IO_Out32_b(plBaseAddress_pv, bsp::c_VideoInGPIOSerCEBaseOffset_u32, v_VideoOutReg_u32);
}

#endif // ME_PLATFORM_QNX

} // namespace bsp

