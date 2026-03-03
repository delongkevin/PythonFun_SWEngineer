//--------------------------------------------------------------------------
/// @file DataProvider.cpp
/// @brief Implements all the shared memory structures defined in the DataProvider Header
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

#include "cfg/DataProvider.h"

#include "cfg/Context.h"

namespace container
{

DataProvider::DataProvider()
: IDataProvider()
{

}
DataProvider::~DataProvider()
{

}

CamMData_t* DataProvider::getCamMData_po()
{
  return static_cast<CamMData_t*>(&container::Context::getContext_ro(variants::e_JobCamM).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

AppMData_t* DataProvider::getAppMData_po()
{
  return static_cast<AppMData_t*>(&container::Context::getContext_ro(variants::e_JobAppM).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

SigMData_t* DataProvider::getSigMData_po()
{
  return static_cast<SigMData_t*>(&container::Context::getContext_ro(variants::e_JobSigM).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

VarMData_t* DataProvider::getVarMData_po()
{
  return static_cast<VarMData_t*>(&container::Context::getContext_ro(variants::e_JobVarM).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

EolMData_t* DataProvider::getEolMData_po()
{
  return static_cast<EolMData_t*>(&container::Context::getContext_ro(variants::e_JobEol).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

SysMonData_t* DataProvider::getSysMonData_po()
{
  return static_cast<SysMonData_t*>(&container::Context::getContext_ro(variants::e_JobSysMon).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

TIOVXData_t* DataProvider::getTIOVXData_po()
{
  return static_cast<TIOVXData_t*>(&container::Context::getContext_ro(variants::e_JobTIOVX).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

OVL3DData_t* DataProvider::getOVL3DData_po()
{
  return static_cast<OVL3DData_t*>(&container::Context::getContext_ro(variants::e_JobOVL3D).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

OcMData_t* DataProvider::getOcMData_po()
{
  return static_cast<OcMData_t*>(&container::Context::getContext_ro(variants::e_JobOC).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

CalSmMData_t* DataProvider::getCalSmMData_po()
{
  return static_cast<CalSmMData_t*>(&container::Context::getContext_ro(variants::e_JobCalSM).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

THAData_t* DataProvider::getTHAData_po()
{
  return static_cast<THAData_t*>(&container::Context::getContext_ro(variants::e_JobTHA).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

TAD2Data_t* DataProvider::getTAD2Data_po()
{
  return static_cast<TAD2Data_t*>(&container::Context::getContext_ro(variants::e_JobTAD2).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

DLDData_t* DataProvider::getDLDData_po()
{
  return static_cast<DLDData_t*>(&container::Context::getContext_ro(variants::e_JobDLD).getDataContainer_ro()); // PRQA S 3076 // this is a downcast, yes
}

} // namespace container

