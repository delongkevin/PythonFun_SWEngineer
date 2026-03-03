//--------------------------------------------------------------------------
/// @file IDataProvider.h
/// @brief Contains all the shared memory structures needed for inter-process-communication
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_I_DATA_PROVIDER_H
#define CONTAINER_I_DATA_PROVIDER_H

// Project specific Data Provider Types.

#include "cfg/DataProviderTypes.h"

namespace container
{

class IDataProvider
{
public:

  IDataProvider() { }
  virtual ~IDataProvider() { }

  virtual CamMData_t*  getCamMData_po() = 0;
  virtual AppMData_t*  getAppMData_po()   = 0;
  virtual SigMData_t*  getSigMData_po()   = 0;
  virtual VarMData_t*  getVarMData_po()   = 0;
  virtual EolMData_t*  getEolMData_po()   = 0;
  virtual SysMonData*  getSysMonData_po() = 0;
  virtual OcMData_t*   getOcMData_po() = 0;
  virtual TIOVXData_t* getTIOVXData_po()  = 0;
  virtual OVL3DData_t*   getOVL3DData_po() = 0;
  virtual CalSmMData_t* getCalSmMData_po()= 0;
  virtual THAData_t*   getTHAData_po()    = 0;
  virtual TAD2Data_t*   getTAD2Data_po()    = 0;
  virtual DLDData_t*   getDLDData_po()    = 0;
};

} // namespace container

#endif // CONTAINER_I_DATA_PROVIDER_H
