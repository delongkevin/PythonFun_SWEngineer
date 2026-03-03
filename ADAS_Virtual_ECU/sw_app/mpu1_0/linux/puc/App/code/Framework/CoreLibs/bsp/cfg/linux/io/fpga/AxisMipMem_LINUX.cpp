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

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_LINUX

#include "bsp/io/fpga/AxisMipMem.h"
#include "bsp/io/fpga/FpgaParameters.h"

namespace bsp
{

  AxisMipMem::AxisMipMem()
    : axisMipMemBase_pv(NULL)
  {

  }

  AxisMipMem::~AxisMipMem()
  {

  }

  bool_t AxisMipMem::initAxisMipMap_b()
  {
    return true;
  }

  bool_t AxisMipMem::snapshot_b(uint8_t i_Port_u8, uint8_t i_BufferIdx_u8)
  {
    return true;
  }

  bool_t AxisMipMem::setCameraSelect_b(variants::Camera_t i_CameraID_t)
  {
    return true;
  }

  bool_t AxisMipMem::setPortControl_b(uint32_t i_Port_u32, uint32_t i_PortControl_u32)
  {
    return true;
  }

} // namespace bsp

#endif // ME_PLATFORM_QNX

