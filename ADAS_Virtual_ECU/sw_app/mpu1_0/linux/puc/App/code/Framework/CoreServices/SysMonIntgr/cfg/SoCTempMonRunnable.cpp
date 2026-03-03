//--------------------------------------------------------------------------
/// @file SoCTempMonRunnable.cpp
/// @brief Contains the SoC temperature monitor component implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include "SoCTempMonRunnable.h"

#include "bsp/io/ps/PsTempMonAccess.h"

namespace sysmon
{

SoCTempMonRunnable::SoCTempMonRunnable()
  : osal::IRunnable()
  , mutex_o()
  , isRunning_b(true)
  , averageAdcValue_u32(0U)
{
}

SoCTempMonRunnable::~SoCTempMonRunnable()
{
  // Nothing to do yet!
}

void SoCTempMonRunnable::init_v()
{
  // Nothing to do yet!
}

bool_t SoCTempMonRunnable::run_b()
{
  // prform SoC temperature measurement
  performSoCTempMeasurement_v();
  // sleep a while, the temperature does not changes so fast
  ME_Thread_Sleep_t(sysmonconsts::c_SysMomTempMeasurementSleepTime_u16);
  return isRunning_b;
}

void SoCTempMonRunnable::cleanup_v()
{
  // Nothing to do yet!
}

void SoCTempMonRunnable::terminate_v()
{
  isRunning_b = false;
}

uint32_t SoCTempMonRunnable::getSoCTemperature_u32()
{
  uint32_t v_Result_u32 = 0U;

  mutex_o.take_b();
  v_Result_u32 = averageAdcValue_u32;
  mutex_o.give_v();

  return v_Result_u32;
}

void SoCTempMonRunnable::performSoCTempMeasurement_v()
{
  const uint8_t c_ReadAdcCount_u8 = 20U;
  uint32_t v_AverageAdcValue_u32 = 0U;
  bsp::PsTempMonAccess& v_PsTempMonAccess_ro = bsp::PsTempMonAccess::getInstance_ro();

  for (uint8_t v_I_u32 = 0U; v_I_u32 < c_ReadAdcCount_u8; ++v_I_u32)
  {
    uint32_t v_AdcVal_u32 = 0U;
    // read out current SoC temperature ADC
    v_PsTempMonAccess_ro.readTempMonAdcValue_b(v_AdcVal_u32);
    // accumulate the value
    v_AverageAdcValue_u32 = v_AverageAdcValue_u32 + v_AdcVal_u32;
    // let the ADC value change a little bit
    ME_Thread_Sleep_t(sysmonconsts::c_SysMomTempADCReadingSleepTime_u16);
  }

  mutex_o.take_b();
  // calc average value
  averageAdcValue_u32 = v_AverageAdcValue_u32 / c_ReadAdcCount_u8;
  mutex_o.give_v();

#if defined (USE_JOB_SYS_DBG_PRINTS)
    ME_Debugger_F_Printf_v("SYS_INFO: SoC tem.: %3.2f deg. Celsius [ADC: 0x%04X] \n",
                           v_PsTempMonAccess_ro.convertAdcToTemperature_f32(averageAdcValue_u32),
                           averageAdcValue_u32);
#endif
}

} // namespace sysmon
