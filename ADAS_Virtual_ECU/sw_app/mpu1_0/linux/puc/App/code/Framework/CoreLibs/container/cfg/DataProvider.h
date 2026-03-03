//--------------------------------------------------------------------------
/// @file DataProvider.h
/// @brief Header that Contains all the shared memory structure defined in the IDataProvider interface
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_DATA_PROVIDER_H
#define CONTAINER_DATA_PROVIDER_H

// Project specific Data Provider Types.

#include "IDataProvider.h"

#include <platform/PlatformSpecs.h>

namespace container
{

class DataProvider : public IDataProvider
{
public:
  DataProvider();
  virtual ~DataProvider();

  virtual CamMData_t*  	 getCamMData_po()    ME_OVERRIDE;
  virtual AppMData_t*    getAppMData_po()    ME_OVERRIDE;
  virtual SigMData_t*    getSigMData_po()    ME_OVERRIDE;
  virtual VarMData_t*    getVarMData_po()    ME_OVERRIDE;
  virtual EolMData_t*    getEolMData_po()    ME_OVERRIDE;
  virtual SysMonData_t*  getSysMonData_po()  ME_OVERRIDE;
  virtual OcMData_t*     getOcMData_po()     ME_OVERRIDE;
  virtual TIOVXData_t*   getTIOVXData_po()   ME_OVERRIDE;
  virtual OVL3DData_t*   getOVL3DData_po()   ME_OVERRIDE;
  virtual CalSmMData_t*  getCalSmMData_po()  ME_OVERRIDE;
  virtual THAData_t*   	 getTHAData_po()     ME_OVERRIDE;
  virtual TAD2Data_t*     getTAD2Data_po()     ME_OVERRIDE;
  virtual DLDData_t*     getDLDData_po()     ME_OVERRIDE;
};

} // namespace container

#endif // CONTAINER_DATA_PROVIDER_H
