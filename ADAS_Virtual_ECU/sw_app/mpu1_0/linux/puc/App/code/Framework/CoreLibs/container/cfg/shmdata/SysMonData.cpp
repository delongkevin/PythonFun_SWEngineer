//--------------------------------------------------------------------------
/// @file SysMonData.cpp
/// @brief Contains the ... implementations
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#include "SysMonData.h"

// #include <variants/VariantHelper.h>

namespace container
{

  SysMonData::SysMonData()
    : DataContainer()
    , currentSoCTemperature_f32(sysmonconsts::c_AbsoluteZeroValue_f32)
  {
  }

  SysMonData::~SysMonData()
  {
  }

  void SysMonData::setCurrentSoCTemperature_v(const float32_t& i_CurrentSoCTemperature_f32)
  {
    currentSoCTemperature_f32 = i_CurrentSoCTemperature_f32;
  }

  float32_t SysMonData::getCurrentSoCTemperature_f32() const
  {
    return currentSoCTemperature_f32;
  }

  uint32_t SysMonData::getSysMonRuntime(void)
  {
      uint32_t v_DataCopy_u32 = 0;
      mutex_o.take_b();
      v_DataCopy_u32 = m_SysMon_rt_data;
      mutex_o.give_v();

      return v_DataCopy_u32;  
  }

  void SysMonData::setSysMonRuntime(uint32_t u_Runtime_u32)
  {
      mutex_o.take_b();
      m_SysMon_rt_data = u_Runtime_u32;
      mutex_o.give_v();
  }

} // namespace container
