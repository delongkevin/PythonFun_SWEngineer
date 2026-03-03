//--------------------------------------------------------------------------
/// @file SysMonData.h
/// @brief Contains the ... descriptions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_SYSMON_DATA_H_
#define CONTAINER_SYSMON_DATA_H_

#include "container/DataContainer.h"
#include <osal/threading/Mutex.h>

namespace container
{

namespace sysmonconsts
{
  static const float32_t c_AbsoluteZeroValue_f32 = -273.15F;
} // namespace sysmonconsts

class SysMonData : public DataContainer
{
  public:
	SysMonData();
    virtual ~SysMonData();

    virtual void setCurrentSoCTemperature_v(const float32_t& i_CurrentSoCTemperature_f32);

    virtual float32_t getCurrentSoCTemperature_f32() const;
    uint32_t getSysMonRuntime(void);
    void setSysMonRuntime(uint32_t u_Runtime_u32);
    
  private:
    float32_t currentSoCTemperature_f32;
    uint32_t m_SysMon_rt_data;
    osal::Mutex mutex_o;
};

} // namespace container

#endif // CONTAINER_VDG_DATA_H
