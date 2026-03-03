//--------------------------------------------------------------------------
/// @file PsTempMonAccess.cpp
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

#if defined (ME_PLATFORM_QNX)

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
    bool_t v_Result_b = ME_IO_MapDeviceAdress_b(tempmonconsts::c_TemMonBaseAddress_u32,
                                                tempmonconsts::c_TemMonMapAreaSize_u32,
                                                &psSysMonBaseAddr_pv);
    if ((true == v_Result_b) && (NULL != psSysMonBaseAddr_pv))
    {
      ME_Debugger_F_Printf_v("SYS_INFO: The SysMon device base address mapped successfully! \n");
      isInitialized_b = true;
    }
    else
    {
      AssertMsg(false, "SYS_INFO: ERROR: Could not map SysMon device base address! \n");
    }
  }
}

bool_t PsTempMonAccess::readTempMonAdcValue_b(uint32_t& o_TempMonAdcValue_ru32)
{
  AssertMsg(psSysMonBaseAddr_pv != NULL, "SYS_INFO: ERROR: The SysMon is not initialized yet! \n");

  bool_t v_RetVal_b = false;
  uint32_t v_TempMonAdcValue_ru32 = 0U;

  if (true == isInitialized_b)
  {
    bool_t v_Result_b = ME_IO_In32_b(psSysMonBaseAddr_pv, tempmonconsts::c_TemMonMapOffset_u32, &v_TempMonAdcValue_ru32);
    if (true == v_Result_b)
    {
      o_TempMonAdcValue_ru32 = v_TempMonAdcValue_ru32;
      v_RetVal_b = true;
    }
  }

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

#endif // ME_PLATFORM_QNX

} /* namespace bsp */
