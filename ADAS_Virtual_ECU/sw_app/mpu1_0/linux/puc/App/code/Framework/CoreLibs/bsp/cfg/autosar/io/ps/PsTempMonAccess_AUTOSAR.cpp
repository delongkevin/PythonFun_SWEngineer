//--------------------------------------------------------------------------
/// @file PsTempMonAccess_AUTSOAR.cpp
/// @brief Contains the implementation for the access to the Zynq_PS
///        SysMon on QNX.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author   Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------


#include <platform/PlatformAPI.h>

#include "bsp/io/ps/PsTempMonAccess.h"

namespace bsp
{

#if defined (ME_PLATFORM_AUTSOAR)

PsTempMonAccess::PsTempMonAccess()
  : isInitialized_b(false)
  , psSysMonBaseAddr_pv(NULL)
{
  init_v();
}

PsTempMonAccess& PsTempMonAccess::getInstance_ro()
{
  static PsTempMonAccess instance_o;
  return instance_o;
}

void PsTempMonAccess::init_v()
{
  if (false ==  isInitialized_b)
  {
      isInitialized_b = true;
  }
}

bool_t PsTempMonAccess::readTempMonAdcValue_b(uint32_t& o_TempMonAdcValue_ru32)
{
  bool_t v_RetVal_b = true;

  return v_RetVal_b;
}

float32_t PsTempMonAccess::convertAdcToTemperature_f32(const uint32_t& i_AdcValue_ru32)
{
  float32_t v_Result_f32 = i_AdcValue_ru32 * 1.0F;

  v_Result_f32 = (v_Result_f32 * tempmonconsts::c_TempCoeff_f32);
  v_Result_f32 = (v_Result_f32 / tempmonconsts::c_AdcCoeff_u32);
  v_Result_f32 = (v_Result_f32 - tempmonconsts::c_StartTemp_f32);

  return v_Result_f32;
}

#endif // ME_PLATFORM_WIN

} /* namespace bsp */
