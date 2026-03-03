//--------------------------------------------------------------------------
/// @file Context.h
/// @brief Contains the algo job definition with input and output providers.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef CONTAINER_CONTEXT_H
#define CONTAINER_CONTEXT_H

#include "ContextTypes.h"
#include "container/JobContext.h"
#include <variants/Enums.h>

namespace osal
{
  class Thread;
}

namespace container
{

class Context
{
public:
  static JobContext& getContext_ro(variants::Job_e i_Job_e);

  static void createContexts_v(void);

  static void resetContexts_v(void);

  // set the thread's name, priority, cpu affinity, etc based on enum
  static void setThreadConfig_v(osal::Thread& b_Thread_rs, variants::Job_e i_Job_e);


public:
  static const sint32_t   s_MaxLogLvlError_s32;

private:
  static JobContext       s_ContextTable_ao[variants::e_JobCount];

};


} // namespace container

#endif // CONTAINER_CONTEXT_H_
