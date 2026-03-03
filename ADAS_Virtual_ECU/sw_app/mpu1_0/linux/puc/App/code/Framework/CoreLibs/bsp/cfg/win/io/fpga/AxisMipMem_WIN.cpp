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

#ifdef ME_PLATFORM_WIN

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

bool_t AxisMipMem::snapshot_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const
{
  return true;
}

bool_t AxisMipMem::continous_b(Port_e i_Port_e, uint8_t i_BufferIdx_u8) const
{
  return true;
}

bool_t AxisMipMem::setCameraSelect_b(variants::Camera_t i_CameraID_t) const
{
  return true;
}

bool_t AxisMipMem::getFrameError_b(variants::Camera_t i_Camera_t)
{
  return true;
}

} // namespace bsp

#endif // ME_PLATFORM_QNX

