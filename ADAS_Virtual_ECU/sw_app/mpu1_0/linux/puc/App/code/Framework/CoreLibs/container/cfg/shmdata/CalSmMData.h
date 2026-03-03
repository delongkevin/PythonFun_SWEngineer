//--------------------------------------------------------------------------
/// @file CalSmMData.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda kavrady (Ananda.kavrady@Magna.com)
///
//  --------------------------------------------------------------------------




#ifndef CONTAINER_CALSM_DATA_H
#define CONTAINER_CALSM_DATA_H

#include <osal/threading/Mutex.h>

#include "container/DataContainer.h"
#include "CommonDataTypeRef.h"


namespace container
{

class CalSmMData : public DataContainer
{
public:
  CalSmMData();
  virtual ~CalSmMData();

  sint32_t getSomeData_s32();
  void setSomeData_v(sint32_t i_SomeData_s32);

  void setSVSCalibSMToAlgoCamCalib (TbSVS_e_SVSCalibSMToAlgoCamCalib_t& i_SMToAlgo);
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t getSVSCalibSMToAlgoCamCalib();
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t SVSCalibSMToAlgoCamCalib;

  void setSVSCalibAlgoToSMCamCalib ( TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_AlgoToSM);
  void setSVSCalibAlgoToSMCamCalib_EolStatus ( ME_Hydra3defs_S_EOLStatus_t& i_EOLStatus);
  void setSVSCalibAlgoToSMCamCalib_OCStatus ( ME_Hydra3defs_S_OCStatus_t& i_OCStatus);
  void setSVSCalibAlgoToSMCamCalib_OCStatus_AlgoType ( ME_Hydra3defs_E_AlgoID_t& i_AlgoType);
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t getSVSCalibAlgoToSMCamCalib ();
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t SVSCalibAlgoToSMCamCalib;
  uint32_t getCALSMRuntime(void);
  void setCALSMRuntime(uint32_t u_CALSMRuntime_val);
  uint32_t getCALSMThreadRuntime(void);
  void setCALSMThreadRuntime(uint32_t u_CALSMRuntime_val);

private:
  osal::Mutex mutex_o;
  sint32_t someData_s32;
  uint32_t m_CALSM_rt_data;
  uint32_t m_CALSMThread_rt_data;
};

} // namespace container

#endif // CONTAINER_CALSM_DATA_H
