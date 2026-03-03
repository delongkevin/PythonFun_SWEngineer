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

#ifndef CONTAINER_DATA_CONTAINER_H
#define CONTAINER_DATA_CONTAINER_H

#include <platform/PlatformAPI.h>
#include <variants/Enums.h>

#pragma pack(1) // exact fit - no padding // PRQA S 1040 // pragma needed for structures


namespace container
{

class DataContainer
{
public:
  DataContainer();
  virtual ~DataContainer();

  uint64_t              getActiveTime_u64() const;
  variants::AppState_t  getAppState_t() const;


  void                  setActivetime_v(uint64_t i_ActiveTime_u64);
  void                  setAppState_t(variants::AppState_t i_AppState_e);

private:

  uint64_t              activeTime_u64;
  variants::AppState_t  appState_e;
};


// ==========================================================================
// Inlines
// ==========================================================================
ME_INLINE uint64_t DataContainer::getActiveTime_u64() const
{
  return activeTime_u64;
}

ME_INLINE variants::AppState_t DataContainer::getAppState_t() const
{
  return appState_e;
}


} // namespace container

#pragma pack() //back to whatever the previous packing mode was // PRQA S 1040 // pragma needed for structures

#endif // CONTAINER_DATA_CONTAINER_H
