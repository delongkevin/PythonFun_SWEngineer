//--------------------------------------------------------------------------
/// @file HMI.cpp
/// @brief Contains Wrapper for HMI
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Pravin Pawar (pravin.pawar@magna.com)
///
//  --------------------------------------------------------------------------

#include "JobHMI.h"
#include "HMI.h"

#ifdef __cplusplus
extern "C"
{
#endif

  using namespace HMI;

  static HMI::DataProviderHMI m_HMIDataProvider;
  static HMI::JobHMI m_HMIJob((IDataProviderHMI *)&m_HMIDataProvider);

  /* Model initialize function */
  void HMI_Init()
  {
    /* DD-ID: {6D1BCC7A-9EEA-420c-A2E9-83214D9FBD87}*/
    m_HMIJob.onInit_b();
    return;
  }

  /* Model step function */
  void HMI_Run()
  {
    /* DD-ID: {2EC9F9B1-7401-44ee-8641-7E86156D5A8B}*/
    m_HMIJob.onRun_b();
    return;
  }


#ifdef __cplusplus
}
#endif
