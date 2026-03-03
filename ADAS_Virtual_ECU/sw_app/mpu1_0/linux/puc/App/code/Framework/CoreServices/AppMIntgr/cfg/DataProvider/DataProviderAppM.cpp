//--------------------------------------------------------------------------
/// @file DataProviderAppM.cpp
/// @brief Contains
///
/// DataProvider is an interface between AppM module and the shared memory.
/// This file contains all the implementation required to access input and
/// output data.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------


#include "DataProviderAppM.h"


namespace appm
{

DataProviderAppM::DataProviderAppM(container::IDataProvider& b_DataProvider_ro)
: IDataProviderAppM()
, dataProvider_ro(b_DataProvider_ro)
{
}

DataProviderAppM::~DataProviderAppM()
{
  // nothing to do here
}

#if 1
//----------------------------------------------------------------------------------------
// Data Input (only getter)
//---------------------------------------------------------------------------------------
uint32_t DataProviderAppM::getFrameID_u32() const
{
  uint32_t v_FrameId_u32 = 0U;

  if (NULL != dataProvider_ro.getAppMData_po())
  {
    v_FrameId_u32 = dataProvider_ro.getAppMData_po()->getFrameID_u32();
  }

  return v_FrameId_u32;
}



//----------------------------------------------------------------------------------------
// Data Output (only setter)
//----------------------------------------------------------------------------------------

void DataProviderAppM::setFrameID_v(uint32_t i_FrameID_u32)
{
  if (NULL != dataProvider_ro.getAppMData_po())
  {
    dataProvider_ro.getAppMData_po()->setFrameID_v(i_FrameID_u32);
  }
}

void DataProviderAppM::setBootState_v(uint8_t i_BootState_u8)
{  
  if (NULL != dataProvider_ro.getAppMData_po())
  {
    dataProvider_ro.getAppMData_po()->setBootState_v(i_BootState_u8);
  }
}

 void DataProviderAppM::setAppMRuntime(uint32_t u_Runtime_u32)
 {
    dataProvider_ro.getAppMData_po()->setAppMRuntime(u_Runtime_u32);
 }

 PerformanceStatsEnable_t DataProviderAppM::get_PerformanceStatsEnable(void)
  {
    return dataProvider_ro.getSigMData_po()->getPerformanceStatsEnable_t();
  }


#endif
} // namespace appm
