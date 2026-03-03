//--------------------------------------------------------------------------
/// @file TIOVXData.cpp
/// @brief Contains the data for overlays
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
///
//  --------------------------------------------------------------------------

#include "TIOVXData.h"

namespace container
{

  TIOVXData::TIOVXData()
    : DataContainer()
    , tiovx_o()
  {
  }

  TIOVXData::~TIOVXData()
  {
  }

  bsp::TIOVXHost& TIOVXData::getTIOVX_ro()
  {
    return tiovx_o;
  }

  bool_t TIOVXData::init_b()
  {
    return tiovx_o.init_b();
  }

  uint32_t TIOVXData::getTIOVXRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_TIOVX_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void TIOVXData::setTIOVXRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_TIOVX_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t TIOVXData::getTIOVXThreadRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_TIOVXThread_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void TIOVXData::setTIOVXThreadRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_TIOVXThread_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t TIOVXData::getCamCalibRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_CamCalib_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void TIOVXData::setCamCalibRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_CamCalib_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

} // namespace container
