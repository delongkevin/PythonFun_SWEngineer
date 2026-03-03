//--------------------------------------------------------------------------
/// @file DataProviderVarM.cpp
/// @brief Contains
///
/// DataProvider is an interface between VarM module and the shared memory.
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


#include "DataProviderVarM.h"


namespace varm
{

DataProviderVarM::DataProviderVarM(container::IDataProvider& b_DataProvider_ro)
: IDataProviderVarM()
, dataProvider_ro(b_DataProvider_ro)
{
}

DataProviderVarM::~DataProviderVarM()
{
  // nothing to do here
}



//----------------------------------------------------------------------------------------
// // Data Input (only getter)
//---------------------------------------------------------------------------------------
uint32_t DataProviderVarM::getLanguageID_u32(void) const
{
  return dataProvider_ro.getVarMData_po()->getLanguageID_u32();
}

//----------------------------------------------------------------------------------------
// Data Output (only setter)
//----------------------------------------------------------------------------------------

void DataProviderVarM::setLanguageID_v(uint32_t i_Data_u32)
{
  dataProvider_ro.getVarMData_po()->setLanguageID_v(i_Data_u32);
}


} // namespace varm
