//--------------------------------------------------------------------------
/// @file DataProviderTypes.h
/// @brief Typedefs for Project specific Shared Memory Data
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_DATA_PROVIDER_TYPES_H
#define CONTAINER_DATA_PROVIDER_TYPES_H

#include "cfg/DataProviderTypes.h"

#include "shmdata/CamMData.h"
#include "shmdata/SigMData.h"
#include "shmdata/VarMData.h"
#include "shmdata/ODData.h"
#include "shmdata/AppMData.h"
#include "shmdata/EolMData.h"
#include "shmdata/OcMData.h"
#include "shmdata/TIOVXData.h"
#include "shmdata/OVL3DData.h"
#include "shmdata/SysMonData.h"
#include "shmdata/CalSmMData.h"
#include "shmdata/THAData.h"
#include "shmdata/TAD2Data.h"
#include "shmdata/MOTData.h"
#include "shmdata/OVLData.h"
#include "shmdata/DLDData.h"
#ifdef USE_VDG
#include "shmdata/VDGData.h"
#endif

namespace container
{

typedef container::CamMData     CamMData_t;
typedef container::SigMData     SigMData_t;
typedef container::VarMData     VarMData_t;
typedef container::AppMData     AppMData_t;
typedef container::EolMData     EolMData_t;
typedef container::OcMData      OcMData_t;
typedef container::OVLData      OVLData_t;
typedef container::TIOVXData    TIOVXData_t;
typedef container::OVL3DData    OVL3DData_t;
typedef container::SysMonData   SysMonData_t;
typedef container::CalSmMData   CalSmMData_t;
typedef container::THAData      THAData_t;
typedef container::TAD2Data      TAD2Data_t;
typedef container::DLDData      DLDData_t;

#ifdef USE_VDG
typedef container::VDGData      VDGData_t;
#endif

} // namespace container

#endif // CONTAINER_DATA_PROVIDER_TYPES_H
