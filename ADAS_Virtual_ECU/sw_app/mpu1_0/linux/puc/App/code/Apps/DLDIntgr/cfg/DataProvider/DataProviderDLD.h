//--------------------------------------------------------------------------
/// @file DataProviderDLD.h
/// @brief Contains
///
/// DataProvider is an interface between FPGA module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Sharad Benakatti (sharad.benakatti@magna.com)
//  --------------------------------------------------------------------------
#ifndef DATA_PROVIDER_DLD_H_
#define DATA_PROVIDER_DLD_H_

#include "AlgoViewDLD.h"
#include "DLD/IDataProviderDLD.h"
#include <cfg/IDataProvider.h>
#include <bsp/io/tiovx/TIOVXConsumer.h>

namespace dld
{

class DataProviderDLD: public IDataProviderDLD
{

public:
  explicit DataProviderDLD(container::IDataProvider &b_DataProvider_ro);
  virtual ~DataProviderDLD();

  /*
  * Get DLD input data
  */
  virtual void c_getInputcolorImage_pu8(DLD_Camera_ID camId);

  /*
  * Get algo view buffer
  */
  virtual bsp::TIOVXHost& getTIOVX_ro();
  virtual container::OVL3DData* getOVL3DData_po();

  /*
  * Get DLD input data
  */
  virtual const JobDLDInput_s getDLDInput(DLD_Camera_ID camId) ME_OVERRIDE;
  virtual const JobDLDVehicleInput_s getVehicleInput(void) ME_OVERRIDE;
  virtual const JobDLDFIDs_t getDLDFIDs(void) ME_OVERRIDE;
  virtual ME_ProxiToMPU1_0_Def_t* getProxiSettings(void) ME_OVERRIDE;

  // Get SC, THA and APA status value
  virtual bool_t isFeatureAllowedToRun() ME_OVERRIDE;

  /*
  * DLD output
  */
  void setDLDOutput(DLDOutput_s& outputDLD) ME_OVERRIDE;
  void setDLDThreadRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
  void setDLDRuntime(uint32_t u_Runtime_u32) ME_OVERRIDE;
  virtual PerformanceStatsEnable_t get_PerformanceStatsEnable(void) ME_OVERRIDE;

  void setInputPadSizes(uint32_t inPadL, uint32_t inPadT, uint32_t inPadR, uint32_t inPadB) ME_OVERRIDE;
  
private:
  container::IDataProvider& m_dataProvider_ro;
  bsp::TIOVXConsumer m_tiovxConsumer;
  JobDLDInput_s   m_jobDLDInput;
  AlgoViewDLD     m_algoView[DLD_Camera_ID::DLD_NUM_CAMS];
  JobDLDVehicleInput_s  m_vehicleInput;
  JobDLDFIDs_t    m_dldFIDs;
  JobDLDOutput_t prevJobDLDOutput;
  ErrorMgr_ErrorCommPack_QNX_B prevErr_QNX_B_DLD;
  ME_ProxiToMPU1_0_Def_t proxy_s;

  void createAlgoViewDescriptors();
#if ENABLE_DLD_DEBUG_PRINT
  const char* getDldCameraString(DLD_Camera_ID camId);
  const char* getDldStatusString(DLDCamSts_t status);
#endif
  void copyInputWithPadding(uint8_t *src_r, uint8_t *src_g, uint8_t *src_b);

  uint32_t m_inputPadL;
  uint32_t m_inputPadT;
  uint32_t m_inputPadR;
  uint32_t m_inputPadB;
  uint32_t m_paddedInputSize;

#if ENABLE_DLD_OFFLINE_TEST
  char ut_inputName[100][100];
  uint8_t ut_numInputs;
#endif
};

} //namespace dld

#endif // DATA_PROVIDER_DLD_H_

