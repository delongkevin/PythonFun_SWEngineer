//--------------------------------------------------------------------------
/// @file DataContainer.h
/// @brief Contains the base functions for all data containers
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "DataContainer.h"

namespace container
{

DataContainer::DataContainer()
: activeTime_u64(0U)
, appState_e(variants::e_AppStateInvalid)
{

}

DataContainer::~DataContainer()
{

}

void DataContainer::setActivetime_v(uint64_t i_ActiveTime_u64)
{
  activeTime_u64 = i_ActiveTime_u64;
}

void DataContainer::setAppState_t(variants::AppState_t i_AppState_e)
{
  appState_e = i_AppState_e;
}

} // namespace container
