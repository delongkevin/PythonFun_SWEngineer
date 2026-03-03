//--------------------------------------------------------------------------
/// @file JobContext.cpp
/// @brief
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#include "JobContext.h"

#include "MessageQueue.h"
#include "DataContainer.h"

#include <osal/threading/BinarySemaphore.h>

namespace container
{

osal::SoftwareInterrupt& JobContext::getTriggerSemaphore_ro(void) const
{
  return *triggerSemaphore_po;
}

MessageQueue& JobContext::getSystemQueue_ro(void) const
{
  return *systemQueue_po;
}

MessageQueue& JobContext::getExternalQueue_ro(void) const
{
  return *externalQueue_po;
}

MessageQueue& JobContext::getInternalQueue_ro(void) const
{
  return *internalQueue_po;
}

DataContainer& JobContext::getDataContainer_ro(void) const
{
  return *dataContainer_po;
}

const char_t* JobContext::getContextName_pc() const
{
  return c_ContextName_pc;
}

sint32_t JobContext::getContextId_s32() const
{
  return contextId_s32;
}

sint32_t JobContext::getMaxLogLevel_s32() const
{
  return maxLogLevel_s32;
}

JobContext JobContext::createJobContext_o(
                      uint8_t* b_SharedMemory_pu8,
                      const char_t* i_ContextName_pc,
                      sint32_t i_ContextId_s32,
                      sint32_t i_ExternalQueueSize_s32,
                      sint32_t i_SystemQueueSize_s32,
                      sint32_t i_InternalQueueSize_s32,
                      sint32_t i_DataContainerSize_s32,
                      sint32_t i_MaxLogLevel_s32)
{
  JobContext v_JobContext_o;
  v_JobContext_o.c_ContextName_pc = i_ContextName_pc;

  // create data header
  v_JobContext_o.triggerSemaphore_po = new(b_SharedMemory_pu8) osal::SoftwareInterrupt(); // PRQA S 5118 // false detection - using placement new here
  b_SharedMemory_pu8 += MAKE_ALIGNMENT_SIZE(sizeof(osal::SoftwareInterrupt));
  Assert(NULL != v_JobContext_o.triggerSemaphore_po);

  // and queues
  v_JobContext_o.externalQueue_po = new(b_SharedMemory_pu8) MessageQueue(i_ExternalQueueSize_s32, *v_JobContext_o.triggerSemaphore_po); // PRQA S 5118 // false detection - using placement new here
  b_SharedMemory_pu8 += v_JobContext_o.externalQueue_po->getNumBytesNeeded_s32();
  Assert(NULL != v_JobContext_o.externalQueue_po);

  v_JobContext_o.systemQueue_po = new(b_SharedMemory_pu8) MessageQueue(i_SystemQueueSize_s32, *v_JobContext_o.triggerSemaphore_po); // PRQA S 5118 // false detection - using placement new here
  b_SharedMemory_pu8 += v_JobContext_o.systemQueue_po->getNumBytesNeeded_s32();
  Assert(NULL != v_JobContext_o.systemQueue_po);

  v_JobContext_o.internalQueue_po = new(b_SharedMemory_pu8) MessageQueue(i_InternalQueueSize_s32, *v_JobContext_o.triggerSemaphore_po); // PRQA S 5118 // false detection - using placement new here
  b_SharedMemory_pu8 += v_JobContext_o.internalQueue_po->getNumBytesNeeded_s32();
  Assert(NULL != v_JobContext_o.internalQueue_po);

  // and DataContainers (only memory pointer is set - content has to be initialized later @see Context.cpp)
  v_JobContext_o.dataContainer_po = reinterpret_cast<container::DataContainer*>(b_SharedMemory_pu8);
  b_SharedMemory_pu8 += i_DataContainerSize_s32;

  v_JobContext_o.contextId_s32 = i_ContextId_s32;

  v_JobContext_o.maxLogLevel_s32 = i_MaxLogLevel_s32;

  return v_JobContext_o;
}

void JobContext::reset_v() const
{
  // Reset all queues -> remove all messages from pipeline
  internalQueue_po->reset_v();
  externalQueue_po->reset_v();
  systemQueue_po->reset_v();
}

} // namespace container
