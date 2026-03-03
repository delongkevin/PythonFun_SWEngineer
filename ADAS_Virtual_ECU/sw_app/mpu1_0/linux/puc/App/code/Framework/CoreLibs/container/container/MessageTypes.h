//--------------------------------------------------------------------------
/// @file Message.h
/// @brief Defines the different message types sent via Jobs
///        Defines the Framework message types
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert(Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_MESSAGE_TYPES_H
#define CONTAINER_MESSAGE_TYPES_H

#include <platform/PlatformSpecs.h>

namespace container
{

// different types of messages
enum MessageType_e
{
  e_MtFramework,          // internal framework messages defined below
  e_MtCount
};

// e_MtFramework: possible OpCodes
enum OpCodeFramework_e
{
  e_OpFwShutdown,
  e_OpFwAppInit,
  e_OpFwAppInitDone,
  e_OpFwAppCleanupDone,
  e_OpFwAppExecute,
  e_OpFwAppExecuteDone,
  e_OpFwAppRestart,
  e_OpFwVariantConfigChanged,
  e_OpFwCount,
  e_OpFwInvalid
};

// e_MtDataChanged: possible OpCodes
enum OpCodeDataChanged_e
{
  e_OpConfigChanged,
  e_OpScreenChanged,
  e_OpVehicleStateChanged,
  e_OpDataChangedCount,
  e_OpCVObjectListCtrlStructureArrayChanged
};


} // namespace container

#endif // CONTAINER_MESSAGE_TYPES_H
