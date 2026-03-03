//--------------------------------------------------------------------------
/// @file JobContext.h
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

#ifndef CONTAINER_JOB_CONTEXT_H_
#define CONTAINER_JOB_CONTEXT_H_

#include "platform/PlatformSpecs.h"

#include "DataContainer.h"

namespace osal
{
  class SoftwareInterrupt;
}

namespace container
{
  class MessageQueue;
}

namespace container
{

class JobContext
{
public:
  /**
   * get the trigger semaphore. It is used by the dispatcher to
   * stay blocking if necessary (no message, no signal)
   * @return  reference to the trigger semaphore
   */
  osal::SoftwareInterrupt&   getTriggerSemaphore_ro(void) const ;

  /**
   * used for the system communication
   * @return reference to the system queue
   */
  MessageQueue&            getSystemQueue_ro(void) const ;


  /**
   * used for the normal communication
   * @return reference to the normal queue
   */
  MessageQueue&            getExternalQueue_ro(void) const ;

 /**
   * used for the internal communication
   * @return reference to the normal queue
   */
  MessageQueue&            getInternalQueue_ro(void) const ;

  DataContainer&           getDataContainer_ro(void) const ;

  const char_t*            getContextName_pc() const ;

  sint32_t                 getContextId_s32() const ;

  sint32_t                 getMaxLogLevel_s32() const ;

  uint32_t                 getThreshNoResponse_u32() const ;

  uint32_t                 getThreshRestart_u32() const ;

  static JobContext        createJobContext_o(uint8_t* b_SharedMemory_pu8,
                                              const char_t* i_ContextName_pc,
                                              sint32_t i_ContextId_s32,
                                              sint32_t i_ExternalQueueSize_s32,
                                              sint32_t i_SystemQueueSize_s32,
                                              sint32_t i_InternalQueueSize_s32,
                                              sint32_t i_DataContainerSize_s32,
                                              sint32_t i_MaxLogLevel_s32);

  void                     reset_v() const;

private:
  const char_t* c_ContextName_pc;

  sint32_t      contextId_s32;

  sint32_t      maxLogLevel_s32;

  // pointer to the queues
  MessageQueue* externalQueue_po;
  MessageQueue* systemQueue_po;
  MessageQueue* internalQueue_po;

  DataContainer* dataContainer_po;

  osal::SoftwareInterrupt* triggerSemaphore_po;
};

} // namespace container

#endif // CONTAINER_JOB_CONTEXT_H_
