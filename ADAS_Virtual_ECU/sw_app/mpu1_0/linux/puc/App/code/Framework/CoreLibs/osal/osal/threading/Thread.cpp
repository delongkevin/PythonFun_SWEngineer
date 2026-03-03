//--------------------------------------------------------------------------
/// @file Thread.cpp
/// @brief Generic Thread class implementation based on platforms stdlib
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#include "Thread.h"

#include <platform/stdlib/ME_Assert.h>
#include <platform/stdlib/ME_Thread.h>

namespace osal
{

Thread::Thread()
  : runnable_po(NULL)
  , threadHandle_s()
  , name_o("")
  , priority_t(e_PriorityNormal)
  , cpuAffinity_t(e_CpuAny)
  , stackSize_t(ME_Thread_C_DefaultStackSize_t)
  , threadState_e(e_ThreadStateUnavailable)
  , startSuspended_b(false)
{
}

Thread::Thread(const char_t* i_ThreadName_pc)
  : runnable_po(NULL)
  , threadHandle_s()
  , priority_t(e_PriorityNormal)
  , cpuAffinity_t(e_CpuAny)
  , stackSize_t(ME_Thread_C_DefaultStackSize_t)
  , threadState_e(e_ThreadStateUnavailable)
  , startSuspended_b(false)
{
  if (i_ThreadName_pc != NULL)
  {
    name_o = i_ThreadName_pc;
  }
}
Thread::~Thread()
{
}

void* Thread::threadEntry_pv(void* b_ThreadAddress_pv)
{
  PlatformError_t v_Result_t = e_PeNoEntry;

  Thread* v_Thread_po = reinterpret_cast<Thread*>(b_ThreadAddress_pv);
  AssertMsg(NULL != v_Thread_po, "Thread::threadEntry_v pointer is NULL!\n");

  // 1.) Set Configuration

  // set priority
  v_Result_t = ME_Thread_SetPriority_t(&v_Thread_po->threadHandle_s, v_Thread_po->priority_t);
  AssertMsg(v_Result_t == e_PeOk, "Thread SetPriority failed: %s\n", v_Thread_po->name_o.c_str());
  // set affinity
  v_Result_t = ME_Thread_SetCpuAffinity_t(&v_Thread_po->threadHandle_s, v_Thread_po->cpuAffinity_t);
  Assert(v_Result_t == e_PeOk);

  v_Result_t = ME_Thread_SetName_t(NULL, v_Thread_po->name_o.c_str());

  // 2.) run the thread
  v_Thread_po->runnable_po->init_v();

  if(v_Thread_po->startSuspended_b == true)
  {
    ME_Thread_CheckSuspend_t(&v_Thread_po->threadHandle_s);
  }

  do
  {
    if(v_Thread_po->runnable_po->run_b() == false)
    {
      v_Thread_po->pause_v();
    }

    ME_Thread_CheckSuspend_t(&v_Thread_po->threadHandle_s);
  }
  while(v_Thread_po->threadState_e == e_ThreadRunning);


  v_Thread_po->runnable_po->cleanup_v();

  // 3.) terminate thread
  v_Thread_po->terminate_v();

  return NULL;
}

void Thread::start_v(IRunnable* i_Runnable_po, bool_t i_StartSuspended_b)
{
  AssertMsg(NULL != i_Runnable_po, "Thread::start_v_runnable pointer is NULL!\n");
  runnable_po = i_Runnable_po;

  startSuspended_b = i_StartSuspended_b;

  if(startSuspended_b == true)
  {
    pause_v();
  }

  threadState_e = e_ThreadRunning;

  // PRQA S 0228 1 // fine here
  PlatformError_t v_Error_t = ME_Thread_Create_t(&threadHandle_s, static_cast<ThreadFunc_t>(threadEntry_pv), this, stackSize_t); // PRQA S 1021 // using ME_THREAD_DEFAULT_STACK_SIZE

  Assert(e_PeOk == v_Error_t);
}

void Thread::pause_v()
{
  ME_Thread_Suspend_t(&threadHandle_s);
}

void Thread::resume_v()
{
  ME_Thread_Resume_t(&threadHandle_s);
}

void Thread::terminate_v()
{
  if(threadState_e == e_ThreadRunning)
  {
    PlatformError_t v_Error_t = ME_Thread_Cancel_t(&threadHandle_s);
    Assert(e_PeOk == v_Error_t);

    threadState_e = e_ThreadTerminated;
  }
}


void Thread::join_v() const
{
  PlatformError_t v_Result_t = e_PeOk;
  v_Result_t = ME_Thread_Join_t(&threadHandle_s);
  AssertMsg(v_Result_t == e_PeOk, "Thread join %s - with code %d\n", name_o.c_str(), v_Result_t);
}

void Thread::setName_v(const char_t* c_ThreadName_pc)
{
  name_o = c_ThreadName_pc;
}

void Thread::setPriority_v(ME_Thread_Priority_t I_Prio_t)
{
  priority_t = I_Prio_t;

  // set priority
  PlatformError_t v_Result_t = ME_Thread_SetPriority_t(&threadHandle_s, priority_t);
  AssertMsg(v_Result_t == e_PeOk, "Thread SetPriority failed: %s\n", name_o.c_str());
}

void Thread::setAffinity_v(CpuId_t i_CpuId_t)
{
  cpuAffinity_t = i_CpuId_t;

  // set affinity
  PlatformError_t v_Result_t = ME_Thread_SetCpuAffinity_t(&threadHandle_s, cpuAffinity_t);
  Assert(v_Result_t == e_PeOk);
}

void Thread::setStackSize_v(size_t i_StackSize_t)
{
  stackSize_t = i_StackSize_t;
}

} // namespace osal

