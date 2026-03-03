//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_EOLM_DATA_H
#define CONTAINER_EOLM_DATA_H

#include <osal/threading/Mutex.h>
#include <variants/Enums.h>

#include "container/DataContainer.h"

/*
NOTE !!!! 
the define __EOLTEST must now be set in 

..\L2G8970\KP03_ProductEngineering\40_Software\20_Construction\L2G8970_PVS\PuC\Tools\cmake_buildsys\addons\projdefines.cmake
*/


namespace container
{

struct EolData_s
{
    uint16_t      m_Camera; // [ 0 = eCamFront, 1 = eCamLeft, 2 = eCamRear, 3 = eCamRight ]
    float32_t     m_Roll_f32;
    float32_t     m_Pitch_f32;
    float32_t     m_Yaw_f32;
};
typedef struct EolData_s EolData_t;

struct EolStructuredData_s
{
    static const uint32_t c_EolCfgVersion_u32 = 1U;

    uint32_t              m_EolCfgVersion_u32;

    EolData_t             m_EolData_at[variants::e_CameraCount];
    sint32_t              m_ErrorCode_s32[variants::e_CameraCount];
};
typedef struct EolStructuredData_s EolStructuredData_t;

class EolMData : public DataContainer
{
public:
    static const uint32_t c_ImgMaxWidth_u32  = 1280U;
    static const uint32_t c_ImgMaxHeight_u32 = 960U;
    static const uint32_t c_ImgLength_u32    = c_ImgMaxWidth_u32 * c_ImgMaxHeight_u32;

public:
  EolMData();
  virtual ~EolMData();

private:
  osal::Mutex mutex_o;
  uint8_t m_MemoryPool_ua8[variants::e_CameraCount-1][c_ImgLength_u32];

  uint8_t m_TempMemoryPool_ua8[variants::e_CameraCount-1][c_ImgLength_u32];

  uint8_t imgHMI[4][2][201*201];
  uint32_t m_EOL_rt_data;
  uint32_t m_EOLThread_rt_data;
  public:
      static uint32_t getImageMaxWidth_u32(void)
      {
        return c_ImgMaxWidth_u32;
      }

      static uint32_t getImageMaxHeight_u32(void)
      {
        return c_ImgMaxHeight_u32;
      }

      uint8_t* getImageBuffer_pu8(const variants::Camera_t i_Camera_e)
      {
        return &m_MemoryPool_ua8[i_Camera_e][0];
      }

      uint8_t* getTemplateBuffer_pu8(uint8_t index)
      {
        return &m_TempMemoryPool_ua8[index][0];
      }

      uint8_t* getHMIBuffer_pu8(const variants::Camera_t i_Camera_e, uint8_t tempId)
      {
        return &imgHMI[i_Camera_e][tempId][0];
      }

      uint32_t getEOLRuntime(void)
      {
        uint32_t v_DataCopy_u32 = 0;
        mutex_o.take_b();
        v_DataCopy_u32 = m_EOL_rt_data;
        mutex_o.give_v();

        return v_DataCopy_u32;  
      }

      void setEOLRuntime(uint32_t u_Runtime_u32)
      {
        mutex_o.take_b();
        m_EOL_rt_data = u_Runtime_u32;
        mutex_o.give_v();
      }

      uint32_t getEOLThreadRuntime(void)
      {
        uint32_t v_DataCopy_u32 = 0;
        mutex_o.take_b();
        v_DataCopy_u32 = m_EOLThread_rt_data;
        mutex_o.give_v();

        return v_DataCopy_u32;  
      }

      void setEOLThreadRuntime(uint32_t u_Runtime_u32)
      {
        mutex_o.take_b();
        m_EOLThread_rt_data = u_Runtime_u32;
        mutex_o.give_v();
      }      

  };

 } // namespace container

 #endif // CONTAINER_EOLM_DATA_H
