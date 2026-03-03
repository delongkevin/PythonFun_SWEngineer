/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_Profiler.h
/// @brief Simple Interface for profiling. Creates a JSON file.
/// Open "about:tracing" in Chrome and load the produced JSON.
/// 
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_PROFILER_H
#define ME_PROFILER_H

#include <platform/PlatformAPI.h>

#if defined(__cplusplus)
extern "C"
{
#endif

typedef enum ProfilerArgType_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_PfatNone          = 0,
  e_PfatInt           = 1, // I
  e_PfatStringConst   = 2, // C
  e_PfatStringCopy    = 3
} ProfilerArgType_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

//#define ME_PROFILER_ENABLED
#ifdef ME_PROFILER_ENABLED

// PRQA S 1026 EOF // Macro may be used as a constant expression. shared between c and cpp
// PRQA S 1025 EOF // Macro may be used as a literal. shared between c and cpp
// PRQA S 1021 EOF // Macro may be used as a literal. shared between c and cpp
// PRQA S 1020 EOF // Macro may be used here
  

  void ME_Profiler_Init_v(const char_t* i_JsonFile_pc);
  void ME_Profiler_Shutdown_v(void);

  void ME_Profiler_Flush_v(void);

  void ME_Profiler_Internal_Raw_Event_v(const char_t* i_Category_pc, const char_t* i_Name_pc, char_t i_Ph_c, char_t* i_Id_pc);
  void ME_Profiler_Internal_Raw_Event_Arg_v(const char_t* i_Category_pc, const char_t* i_Name_pc, char_t i_Ph_c, void* i_Id_pv, ProfilerArgType_t i_Argtype_t, const char_t* i_ArgName_pc, void* i_ArgValue_pv);

#define MEP_INIT(f)    ME_Profiler_Init_v(f)
#define MEP_SHUTDOWN() ME_Profiler_Shutdown_v()
#define MEP_FLUSH()    ME_Profiler_Flush_v()

#define MEP_BEGIN(c, n) ME_Profiler_Internal_Raw_Event_v(c, n, 'B', 0)
#define MEP_END(c, n)   ME_Profiler_Internal_Raw_Event_v(c, n, 'E', 0)

#define MEP_EVENT(n)    MEP_BEGIN("Event", n); MEP_END("Event", n);

   // Metadata. Call at the start preferably. Must be const strings.
#define MEP_META_PROCESS_NAME(n) ME_Profiler_Internal_Raw_Event_Arg_v("", "process_name", 'M', 0, e_PfatStringCopy, "name", (void *)(n))
#define MEP_META_THREAD_NAME(n)  ME_Profiler_Internal_Raw_Event_Arg_v("", "thread_name",  'M', 0, e_PfatStringCopy, "name", (void *)(n))

#else  // ME_PROFILER_ENABLED

// just use empty defines

#define MEP_INIT(f)
#define MEP_SHUTDOWN()
#define MEP_FLUSH()

#define MEP_BEGIN(c, n)
#define MEP_END(c, n)

#define MEP_EVENT(n)

// Metadata. Call at the start preferably. Must be const strings.
#define MEP_META_PROCESS_NAME(n)
#define MEP_META_THREAD_NAME(n)

#endif // ME_PROFILER_ENABLED

#if defined(__cplusplus)
}; // extern C
#endif

#endif // ME_PROFILER_H
