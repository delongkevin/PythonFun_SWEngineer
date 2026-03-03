//--------------------------------------------------------------------------
/// @file Thread.h
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

#ifndef OSAL_THREAD_H_
#define OSAL_THREAD_H_

#include "platform/PlatformAPI.h"
#include "platform/stdlib/memory/PlatformStl.h"
#include "IRunnable.h"

namespace osal
{

// PRQA S 1051 40 // comment contains code samples
/// Wrapper for OS specific thread implementations.
/// @par Example
/// @code{.cpp}
/// class TestRunnable : public container::IRunnable
/// {
///   virtual void run_v()
///   {
///     osal::Waiter v_Waiter_o;
///     uint32_t count = 0U;
///     while (count < 1000)
///     {
///       ++count;
///       if ((count % 100) == 0)
///       {
///         vm_cprintf("runnable: %d\n", count);
///       }
///       v_Waiter_o.waitForNextFrame_v();
///     }
///     // the thread is ended here automatically. But usually this is an endless loop
///   }
/// };
///
/// mainThread()
/// {
///  // ...
///  TestRunnable v_Runnable_o;
///  // either use static here or make it a global variable
///  // otherwise the threadStack will be packed on top of the main thread's stack
///  static uint8_t s_ThreadStack_au8[0x1000];
///
///  osal::Thread v_Thread_o(v_Runnable_o, s_ThreadStack_au8, sizeof(s_ThreadStack_au8));
///
///  // ...
///  v_Thread_o.start_v(osal::Thread::e_PriorityLow);
///
///  // ... (do main thread stuff)
/// }
/// @endcode

class Thread
{
public:
  typedef enum ThreadState_e
  {
    e_ThreadRunning,          ///< The thread is running in parallel
    e_ThreadTerminated,       ///< The thread is dead
    e_ThreadCurrent,          ///< Current state is only possible when asked in the context of the Thread.
    e_ThreadPaused,           ///< The thread has been paused (or stopped) using pause_v().
    e_ThreadWaiting,          ///< The thread is waiting for I/O
    e_ThreadStateUnavailable  ///< There was an error when calling the system functions to retrieve the thread's state.
  } ThreadState_t;


  /// Creates the thread object.
  Thread();
  explicit Thread(const char_t* i_ThreadName_pc);
  ~Thread();

  void start_v(IRunnable* i_Runnable_po, bool_t i_StartSuspended_b = false);
  void pause_v();
  void resume_v();

  void setName_v(const char_t* c_ThreadName_pc);
  void setPriority_v(ME_Thread_Priority_t I_Prio_t);
  void setAffinity_v(CpuId_t i_CpuId_t);
  void setStackSize_v(size_t i_StackSize_t);

  /// Stops and terminates a thread.
  /// A running thread will automatically terminated when its runnable has finished.
  void terminate_v();

  void join_v() const;

private:
  // static Thread Entry point
  static void* threadEntry_pv(void* b_ThreadAddress_pv);

  /// Stops and terminates a thread.
  /// A running thread will automatically terminated when its runnable has finished.

private:

  IRunnable*           runnable_po;

  ThreadHandle_s       threadHandle_s;

  mepl::string         name_o;

  ME_Thread_Priority_t priority_t;

  CpuId_t              cpuAffinity_t;

  size_t               stackSize_t;

  ThreadState_t        threadState_e;

  bool_t               startSuspended_b;

};

}

#endif /* OSAL_THREAD_H_ */
