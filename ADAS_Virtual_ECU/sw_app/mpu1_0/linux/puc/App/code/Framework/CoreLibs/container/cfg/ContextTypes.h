//--------------------------------------------------------------------------
/// @file ContextTypes.h
/// @brief Contains the context specific types.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_CONTEXT_TYPES_H
#define CONTAINER_CONTEXT_TYPES_H

#include <platform/PlatformSpecs.h>

namespace container
{

struct ContextDesc_s
{
  // id of the job
  sint32_t id_s32;

  // name of the job
  const char_t* c_Name_pc;

  // scheduling config
  sint32_t cpuAffinity_s32; // ME_Thread.h cpu affinity
  sint32_t priority_s32;    // ME_Thread.h priority
  sint32_t stackSize_s32;   // ME_Thread.h stacksize

  // queue sizes
  sint32_t externalQueueSize_s32;
  sint32_t systemQueueSize_s32;
  sint32_t internalQueueSize_s32;

  // size of the used data container
  sint32_t dataContainerSize_s32;

  // size in shared memory
  sint32_t sharedMemSize_s32;
};


}; // namespace container

#endif // CONTAINER_CONTEXT_TYPES_H
