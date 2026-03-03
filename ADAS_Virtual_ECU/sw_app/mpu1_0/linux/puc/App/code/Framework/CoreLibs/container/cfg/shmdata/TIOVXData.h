//--------------------------------------------------------------------------
/// @file TIOVXData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Konstantin Kozhevnikov (konstantin.kozhevnikov@cogentembedded.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_TIOVX_DATA_H
#define CONTAINER_TIOVX_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"

#include <logging/Logger.h>

#include <bsp/io/tiovx/TIOVXHost.h>
#include <bsp/io/tiovx/TIOVXVideoInput.h>

namespace container
{

class TIOVXData : public DataContainer
{
public:

  TIOVXData();

  virtual ~TIOVXData();

public:

  bsp::TIOVXHost&         getTIOVX_ro();

  bool_t                  init_b();

  bool_t                  getFrameBuffer_b(uint32_t i_CameraID_u32, uint8_t* o_FrameBuffer_ppu8);
  bool_t                  getFullFrameBuffer_b(uint32_t i_CameraID_u32, uint8_t* o_FrameBuffer_pu8);
  uint32_t getTIOVXRuntime(void);

  void setTIOVXRuntime(uint32_t u_Runtime_u32);

  uint32_t getTIOVXThreadRuntime(void);

  void setTIOVXThreadRuntime(uint32_t u_Runtime_u32);

  uint32_t getCamCalibRuntime(void);

  void setCamCalibRuntime(uint32_t u_Runtime_u32);

private:
  osal::Mutex mutex_o;
  bsp::TIOVXHost          tiovx_o;
  uint32_t m_TIOVX_rt_data;
  uint32_t m_TIOVXThread_rt_data;
  uint32_t m_CamCalib_rt_data;

};

} // namespace container

#endif // CONTAINER_OD_DATA_H
