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


#include "bsp/io/fpga/FpgaZCU102.h"

#ifdef ME_PLATFORM_RTOS

namespace bsp
{

FpgaZCU102::FpgaZCU102()
  : fpgaState_e(e_FpgaStateNotInitialized)
  , plBaseAddress_pv(NULL)
  , viewId_t(variants::e_ServiceHelper_E_HMIView_NoView)
{
}

FpgaZCU102::~FpgaZCU102()
{

}

bool_t FpgaZCU102::init_b()
{
  fpgaLayerEngine_o.initLayerEngine_b();
  fpgaViewGen_o.initViewGen_b();

  fpgaState_e = e_FpgaStateInitalized;

  return true;
}

FpgaLayerEngine& FpgaZCU102::getFpgaLayerEngine_ro()
{
  return fpgaLayerEngine_o;
}

FpgaViewGen& FpgaZCU102::getFpgaViewGen_ro()
{
  return fpgaViewGen_o;
}

FpgaAlgoView& FpgaZCU102::getFpgaAlgoView_ro()
{
  return fpgaAlgoView_o;
}

FpgaVideoInput& FpgaZCU102::getFpgaVideoInput_ro()
{
  return fpgaVideoInput_o;
}

FpgaVideoOutput& FpgaZCU102::getFpgaVideoOutput_ro()
{
  return fpgaVideoOutput_o;
}

AxisMipMem& FpgaZCU102::getAxisMipMem_ro()
{
  return axisMipMem_o;
}

FpgaVersion_s FpgaZCU102::getFpgaVersion_s()
{
  FpgaVersion_s v_Version_s;
  uint32_t v_Version_u32 = 0x00U;

  v_Version_s.year_u8         = (v_Version_u32 & 0xff000000U) >> 24;
  v_Version_s.week_u8         = (v_Version_u32 & 0x00ff0000U) >> 16;
  v_Version_s.day_u8          = (v_Version_u32 & 0x0000f000U) >> 12;
  v_Version_s.buildNumber_u8  = (v_Version_u32 & 0x00000f00U) >> 8;

  return v_Version_s;
}

uint32_t FpgaZCU102::getFrameTrigger_u32()
{
  ME_Thread_Sleep_t(33);

  return frameNumber_u32++;
}

} // namespace bsp


#endif // ME_PLATFORM_WIN

