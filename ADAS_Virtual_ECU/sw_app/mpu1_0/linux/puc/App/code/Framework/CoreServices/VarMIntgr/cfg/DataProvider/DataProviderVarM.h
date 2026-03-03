//--------------------------------------------------------------------------
/// @file DataProviderVarM.h
/// @brief Contains
///
/// DataProvider is an interface between EOL module and the shared memory.
/// It implements the pure virtual interface definition to adapt the
/// module/component to the framework by specifying where the data comes form
/// or goes to. This means, this file contains all the interfaces required
/// to access input and output data.
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
#ifndef DATAPROVIDERVARM_H_
#define DATAPROVIDERVARM_H_

#include "varm/IDataProviderVarM.h"
#include <cfg/IDataProvider.h>

namespace varm
{

class DataProviderVarM : public IDataProviderVarM
{
public:

  explicit DataProviderVarM(container::IDataProvider& b_DataProvider_ro);
  virtual ~DataProviderVarM();

  //----------------------------------------------------------------------------------------
  // // Data Input (only getter)
  //---------------------------------------------------------------------------------------
  virtual uint32_t              getLanguageID_u32() const;


  //----------------------------------------------------------------------------------------
  // Data Output (only setter)
  //----------------------------------------------------------------------------------------

  virtual void                  setLanguageID_v(uint32_t i_Data_u32);

private:
    container::IDataProvider& dataProvider_ro;

};

} // namespace varm

#endif // DATAPROVIDERVARM_H_

