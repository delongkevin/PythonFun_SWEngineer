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

// include needed to check OS define

#include "platform/stdlib/utils/ME_Profiler.h"

#ifdef ME_PROFILER_ENABLED

typedef struct ProfilerEventData_s
{
  const char_t*     name_pc;
  const char_t*     cat_pc;
  void*             id_pv;
  sint64_t          ts_s64;
  uint32_t          pid_u32;
  uint32_t          tid_u32;
  char_t            ph_c;
  ProfilerArgType_t argType_t;
  const char_t*     argName_pc;

  union 
  {
    const char_t*   a_str_pc;
    sint32_t        a_int_s32;
    float64_t       a_double_f64;
  };

} ProfilerEventData_t;

// static global variables
static ProfilerEventData_t*         s_Profiler_Buffer_ps = NULL;
static volatile sint32_t            s_Profiler_Count_s32 = 0;
static bool_t                       s_Profiler_IsTracing_b = false;
static sint64_t                     s_Profiler_TimeOffset_s64 = 0;
static bool_t                       s_Profiler_FirstLine_b = true;
static FileHandle_s                 s_Profiler_FileHandle_s;
static ME_THREAD_STORAGE ThreadID_t s_Profiler_CurrentThreadID_t = 0;
static ProcessID_t                  s_Profiler_CurrentProcessID_t = 0;
static Mutex_s                      s_Profiler_Mutex_s;
static const uint32_t               s_Profiler_BufferSize_u32 = 1000000;
static float64_t                    s_Profiler_startTime_f64 = 0.0;

// in nanoseconds
float64_t ME_Profiler_TimeDelta_f64()
{
  float64_t v_CurrTime_f64 = 0.0;

  if (0.0 == s_Profiler_startTime_f64)
  {
    ME_Time_GetTimeMsecf64_t(&s_Profiler_startTime_f64);
    s_Profiler_startTime_f64 *= 1000.0;
  }

  ME_Time_GetTimeMsecf64_t(&v_CurrTime_f64);
  v_CurrTime_f64 *= 1000.0;

  return v_CurrTime_f64 - s_Profiler_startTime_f64;
}

void ME_Profiler_Init_v(const char_t* i_JsonFile_pc)
{
  const char* c_Header_pc = "{\"traceEvents\":[\n";
  PlatformError_t v_Error_t = e_PeOk;

  v_Error_t = ME_File_Open_t(&s_Profiler_FileHandle_s, i_JsonFile_pc, e_FomWrite | e_FomBinary);

  if (e_PeOk == v_Error_t)
  {
    ME_File_Write_u64(&s_Profiler_FileHandle_s, c_Header_pc, strlen(c_Header_pc));

    s_Profiler_Buffer_ps = (ProfilerEventData_t*)malloc(s_Profiler_BufferSize_u32 * sizeof(ProfilerEventData_t));
    s_Profiler_IsTracing_b = true;
    s_Profiler_Count_s32 = 0;

    s_Profiler_TimeOffset_s64 = (sint64_t)(ME_Profiler_TimeDelta_f64());

    s_Profiler_FirstLine_b = true;

    v_Error_t = ME_Mutex_Init_t(&s_Profiler_Mutex_s, false);
    Assert(e_PeOk == v_Error_t);
  }
}


void ME_Profiler_Shutdown_v(void)
{
  const char_t* c_EndHeader_pc = "\n]}\n";

  s_Profiler_IsTracing_b = false;

  ME_Profiler_Flush_v();

  // write end and close file
  ME_File_Write_u64(&s_Profiler_FileHandle_s, c_EndHeader_pc, 4);
  ME_File_Close_t(&s_Profiler_FileHandle_s);

  ME_Mutex_Destroy_t(&s_Profiler_Mutex_s);

  if (NULL != s_Profiler_Buffer_ps)
  {
    free(s_Profiler_Buffer_ps);
    s_Profiler_Buffer_ps = NULL;
  }
}


void ME_Profiler_Flush_v(void)
{
  sint32_t len;
  sint32_t i = 0;
  char_t linebuf[1024];
  char_t arg_buf[1024];
  char_t id_buf[256];
  char_t temp[256];
  const char_t *cat = NULL;
  bool_t old_tracing = s_Profiler_IsTracing_b;
  // We have to lock while flushing. So we really should avoid flushing as much as possible.

  ME_Mutex_Lock_t(&s_Profiler_Mutex_s);
  s_Profiler_IsTracing_b = false;	// Stop logging even if using interlocked increments instead of the mutex. Can cause data loss.

  for (i = 0; i < s_Profiler_Count_s32; i++) 
  {
    ProfilerEventData_t *raw = &s_Profiler_Buffer_ps[i];

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

    switch (raw->argType_t) 
    {
    case e_PfatInt:
      ME_String_Snprintf_s32(arg_buf, ARRAY_SIZE(arg_buf), "\"%s\":%i", raw->argName_pc, raw->a_int_s32);
      break;
    case e_PfatStringConst://MTR_ARG_TYPE_STRING_CONST:
      ME_String_Snprintf_s32(arg_buf, ARRAY_SIZE(arg_buf), "\"%s\":\"%s\"", raw->argName_pc, raw->a_str_pc);
      break;
    case e_PfatStringCopy:
      if (strlen(raw->a_str_pc) > 700) 
      {
        ME_String_Snprintf_s32(arg_buf, ARRAY_SIZE(arg_buf), "\"%s\":\"%.*s\"", raw->argName_pc, 700, raw->a_str_pc);
      }
      else 
      {
        ME_String_Snprintf_s32(arg_buf, ARRAY_SIZE(arg_buf), "\"%s\":\"%s\"", raw->argName_pc, raw->a_str_pc);
      }
      break;
    case e_PfatNone:
      arg_buf[0] = '\0';
      break;
    }
    if (raw->id_pv) 
    {
      switch (raw->ph_c) 
      {
      case 'S':
      case 'T':
      case 'F':
        // TODO: Support full 64-bit pointers
        ME_String_Snprintf_s32(id_buf, ARRAY_SIZE(id_buf), ",\"id\":\"0x%08x\"", (uint32_t)(uint64_t)raw->id_pv);
        break;
      case 'X':
        ME_String_Snprintf_s32(id_buf, ARRAY_SIZE(id_buf), ",\"dur\":%i", (int)raw->a_double_f64);
        break;
      }
    }
    else {
      id_buf[0] = 0;
    }
      cat = raw->cat_pc;

#ifdef ME_PLATFORM_WIN
    // On Windows, we often end up with backslashes in category.
    {
      int len = (int)strlen(cat);
      int i;
      if (len > 255) len = 255;
      for (i = 0; i < len; i++) {
        temp[i] = cat[i] == '\\' ? '/' : cat[i];
      }
      temp[len] = 0;
      cat = temp;
    }
#endif
    
    len = ME_String_Snprintf_s32(linebuf, ARRAY_SIZE(linebuf), "%s{\"cat\":\"%s\",\"pid\":%i,\"tid\":%i,\"ts\":%lld,\"ph\":\"%c\",\"name\":\"%s\",\"args\":{%s}%s}",
      s_Profiler_FirstLine_b ? "" : ",\n",
      cat, raw->pid_u32, raw->tid_u32, raw->ts_s64 - s_Profiler_TimeOffset_s64, raw->ph_c, raw->name_pc, arg_buf, id_buf);

    ME_File_Write_u64(&s_Profiler_FileHandle_s, linebuf, len);
    s_Profiler_FirstLine_b = false;
  }
  s_Profiler_Count_s32 = 0;
  s_Profiler_IsTracing_b = old_tracing;

  ME_Mutex_Lock_t(&s_Profiler_Mutex_s);
}

void ME_Profiler_Internal_Raw_Event_v(const char_t* i_Category_pc, const char_t* i_Name_pc, char_t i_Ph_c, char_t* i_Id_pc)
{
  ProfilerEventData_t* ev;
  float64_t ts;
  float64_t x;

  if ((false == s_Profiler_IsTracing_b) || (s_Profiler_Count_s32 >= s_Profiler_BufferSize_u32))
  {
    return;
  }

  if (0 == s_Profiler_CurrentThreadID_t)
  {
    s_Profiler_CurrentThreadID_t = ME_Thread_GetCurrentID_t();
  }
  if (0 == s_Profiler_CurrentProcessID_t)
  {
    s_Profiler_CurrentProcessID_t = ME_Process_GetCurrentID_t();
  }

  ts = ME_Profiler_TimeDelta_f64();

  ME_Mutex_Lock_t(&s_Profiler_Mutex_s);
  ev = &s_Profiler_Buffer_ps[s_Profiler_Count_s32];
  ++s_Profiler_Count_s32;
  ME_Mutex_UnLock_t(&s_Profiler_Mutex_s);

  ev->cat_pc = i_Category_pc;
  ev->name_pc = i_Name_pc;
  ev->id_pv = i_Id_pc;
  ev->ph_c = i_Ph_c;
  if (ev->ph_c == 'X') 
  {
    memcpy(&x, i_Id_pc, sizeof(float64_t));
    ev->ts_s64 = (sint64_t)(x);
    ev->a_double_f64 = (ts - x);
  }
  else 
  {
    ev->ts_s64 = (sint64_t)(ts);
  }
  ev->tid_u32 = s_Profiler_CurrentThreadID_t;
  ev->pid_u32 = s_Profiler_CurrentProcessID_t;
  ev->argType_t = e_PfatNone;
}

void ME_Profiler_Internal_Raw_Event_Arg_v(const char_t* i_Category_pc, const char_t* i_Name_pc, char_t i_Ph_c, void* i_Id_pv, ProfilerArgType_t i_Argtype_t, const char_t* i_ArgName_pc, void* i_ArgValue_pv)
{
  ProfilerEventData_t* ev;

  if ((false == s_Profiler_IsTracing_b) || (s_Profiler_Count_s32 >= s_Profiler_BufferSize_u32))
  {
    return;
  }

  if (0 == s_Profiler_CurrentThreadID_t) 
  {
    s_Profiler_CurrentThreadID_t = ME_Thread_GetCurrentID_t();
  }
  if (0 == s_Profiler_CurrentProcessID_t) 
  {
    s_Profiler_CurrentProcessID_t = ME_Process_GetCurrentID_t();
  }

  ME_Mutex_Lock_t(&s_Profiler_Mutex_s);
  ev = &s_Profiler_Buffer_ps[s_Profiler_Count_s32];
  ++s_Profiler_Count_s32;
  ME_Mutex_UnLock_t(&s_Profiler_Mutex_s);

  ev->cat_pc = i_Category_pc;
  ev->name_pc = i_Name_pc;
  ev->id_pv = i_Id_pv;
  ev->ts_s64 = (sint64_t)(ME_Profiler_TimeDelta_f64());
  ev->ph_c = i_Ph_c;
  ev->tid_u32 = s_Profiler_CurrentThreadID_t;
  ev->pid_u32 = s_Profiler_CurrentProcessID_t;
  ev->argType_t = i_Argtype_t;
  ev->argName_pc = i_ArgName_pc;

  switch (i_Argtype_t) 
  {
    case e_PfatInt:           ev->a_int_s32 = (sint32_t)(uint64_t)i_ArgValue_pv; break;
    case e_PfatStringConst: 	ev->a_str_pc  = (const char_t*)i_ArgValue_pv; break;
    case e_PfatStringCopy:    ev->a_str_pc  = strdup((const char_t*)i_ArgValue_pv); break;
    case e_PfatNone: break;
  }
}

#endif
