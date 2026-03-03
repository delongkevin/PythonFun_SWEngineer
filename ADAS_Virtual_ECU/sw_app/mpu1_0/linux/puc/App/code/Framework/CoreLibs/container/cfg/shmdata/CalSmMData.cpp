//--------------------------------------------------------------------------
/// @file CalSmMData.cpp
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda.kavrady@Magna.com)
///
//  --------------------------------------------------------------------------

#include "CalSmMData.h"

namespace container
{

CalSmMData::CalSmMData()
  : DataContainer()
  , mutex_o()
  , someData_s32(0)
{

}

CalSmMData::~CalSmMData()
{

}

sint32_t CalSmMData::getSomeData_s32()
{
  sint32_t v_DataCopy_s32 = 0;
  mutex_o.take_b();
  v_DataCopy_s32 = someData_s32;
  mutex_o.give_v();

  return v_DataCopy_s32;
}

void CalSmMData::setSomeData_v(sint32_t i_SomeData_s32)
{
  mutex_o.take_b();
  someData_s32 = i_SomeData_s32;
  mutex_o.give_v();
}

void CalSmMData::setSVSCalibSMToAlgoCamCalib (TbSVS_e_SVSCalibSMToAlgoCamCalib_t &i_SMToAlgo)
{
  mutex_o.take_b();
  SVSCalibSMToAlgoCamCalib = i_SMToAlgo;
  mutex_o.give_v();
  }
TbSVS_e_SVSCalibSMToAlgoCamCalib_t CalSmMData::getSVSCalibSMToAlgoCamCalib()
{
  TbSVS_e_SVSCalibSMToAlgoCamCalib_t o_SVSCalibSMToAlgoCamCalib;
  mutex_o.take_b();
  o_SVSCalibSMToAlgoCamCalib = SVSCalibSMToAlgoCamCalib;
  mutex_o.give_v();

  return o_SVSCalibSMToAlgoCamCalib;
}

void CalSmMData::setSVSCalibAlgoToSMCamCalib ( TbSVS_e_SVSCalibAlgoToSMCamCalib_t& i_AlgoToSM)
{
  mutex_o.take_b();
  SVSCalibAlgoToSMCamCalib = i_AlgoToSM;
  mutex_o.give_v();
}

TbSVS_e_SVSCalibAlgoToSMCamCalib_t CalSmMData::getSVSCalibAlgoToSMCamCalib ()
{
  TbSVS_e_SVSCalibAlgoToSMCamCalib_t o_SVSCalibAlgoToSMCamCalib;
  mutex_o.take_b();
  o_SVSCalibAlgoToSMCamCalib = SVSCalibAlgoToSMCamCalib;
  mutex_o.give_v();

  return o_SVSCalibAlgoToSMCamCalib;
}

void CalSmMData::setSVSCalibAlgoToSMCamCalib_EolStatus ( ME_Hydra3defs_S_EOLStatus_t& i_EOLStatus)
{
  mutex_o.take_b();
  SVSCalibAlgoToSMCamCalib.EOL_Status_STM = i_EOLStatus;
  mutex_o.give_v();
}

void CalSmMData::setSVSCalibAlgoToSMCamCalib_OCStatus ( ME_Hydra3defs_S_OCStatus_t& i_OCStatus)
{
  mutex_o.take_b();
  SVSCalibAlgoToSMCamCalib.OC_Status_STM = i_OCStatus;
  mutex_o.give_v();
}

void CalSmMData::setSVSCalibAlgoToSMCamCalib_OCStatus_AlgoType ( ME_Hydra3defs_E_AlgoID_t& i_AlgoType)
{
  mutex_o.take_b();
  SVSCalibAlgoToSMCamCalib.CalibAlgoType = i_AlgoType;
  mutex_o.give_v();
}

uint32_t CalSmMData::getCALSMRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_CALSM_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void CalSmMData::setCALSMRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_CALSM_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}

uint32_t CalSmMData::getCALSMThreadRuntime(void)
{
  uint32_t v_DataCopy_u32 = 0;
  mutex_o.take_b();
  v_DataCopy_u32 = m_CALSMThread_rt_data;
  mutex_o.give_v();

  return v_DataCopy_u32;  
}

void CalSmMData::setCALSMThreadRuntime(uint32_t u_Runtime_u32)
{
  mutex_o.take_b();
  m_CALSMThread_rt_data = u_Runtime_u32;
  mutex_o.give_v();
}


} // namespace container
