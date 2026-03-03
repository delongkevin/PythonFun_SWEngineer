// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

// stdlib header include
#include "platform/stdlib/ME_Semaphore.h"
#include <fcntl.h>

// NOT named semaphore
// http://www.qnx.com/developers/docs/6.5.0/topic/com.qnx.doc.neutrino_lib_ref/s/sem_init.html?cp=13_4_22_31
PlatformError_t ME_Semaphore_Init_t(Semaphore_s* b_Semaphore_po, sint32_t i_Shared_s32, uint32_t i_Value_u32)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    v_Result_s32 = sem_init(b_Semaphore_po->qnxSem_po, i_Shared_s32, i_Value_u32);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// named semaphore
// http://www.qnx.com/developers/docs/6.5.0/topic/com.qnx.doc.neutrino_lib_ref/s/sem_open.html?cp=13_4_22_32
PlatformError_t ME_Semaphore_Open_t(Semaphore_s* b_Semaphore_po, const char_t* i_Name_pc, SemaphoreOpenFlags_t i_OpenFlag_e, SemaphoreModeFlags_t i_ModeFlags_e, uint32_t i_Value_u32)
{
  // http://www.qnx.com/developers/docs/6.5.0/index.jsp?topic=%2Fcom.qnx.doc.neutrino_lib_ref%2Fs%2Fsem_open.html
  PlatformError_t v_Error_t;
  int oFlags;
  int mFlags;

  // Don't set oflags to O_RDONLY, O_RDWR, or O_WRONLY. A semaphore's behavior is undefined with these flags.
  // The QNX libraries silently ignore these options, but they may reduce your code's portability.
  switch(i_OpenFlag_e)
  {
    case e_SofCreate:
      oFlags = O_CREAT;
      break;
    case e_SofExcl:
      oFlags = O_EXCL;
      break;
    default:
      oFlags = O_CREAT; // used as default
      break;
  }

  //If you set O_CREAT in oflags, you must also pass the following arguments:
  if(O_CREAT == oFlags)
  {
    switch(i_ModeFlags_e)
    {
      case e_SmfGroup:
        mFlags = S_IRWXG; // for group access.
        break;
      case e_SmfOther:
        mFlags = S_IRWXO; // for other's access.
        break;
      case e_SmfOwn:
        mFlags = S_IRWXU; // for your own access.
        break;
      default:
        mFlags = S_IRWXU; // used as default
        break;
    }
  }
  else
  {
    mFlags = S_IRWXU; // used as default
  }

  if(NULL != b_Semaphore_po)
  {
    // Returns: A pointer to the created or accessed semaphore, or SEM_FAILED for failure (errno is set).
    b_Semaphore_po->qnxSem_po = sem_open(i_Name_pc, oFlags, mFlags, i_Value_u32);

    if(b_Semaphore_po->qnxSem_po == SEM_FAILED) // PRQA S 306 // QNX lib define used
    {
      v_Error_t = e_PeFault;
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// Destroy an unnamed semaphore
PlatformError_t ME_Semaphore_Destroy_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    v_Result_s32 = sem_destroy(b_Semaphore_po->qnxSem_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

// Get the value of a named or unnamed semaphore
PlatformError_t ME_Semaphore_GetValue_t(Semaphore_s* b_Semaphore_po, sint32_t* o_value_ps32)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    if(NULL != o_value_ps32)
    {
      v_Result_s32 = sem_getvalue(b_Semaphore_po->qnxSem_po, o_value_ps32);
      v_Error_t = ME_GetPlatformError_t(v_Result_s32);
    }
    else
    {
      v_Error_t = e_PeFault;
    }
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Increment a named or unnamed semaphore
PlatformError_t ME_Semaphore_Post_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    v_Result_s32 = sem_post(b_Semaphore_po->qnxSem_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Wait on a named or unnamed semaphore, but don't block
PlatformError_t ME_Semaphore_TryWait_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    v_Result_s32 = sem_trywait(b_Semaphore_po->qnxSem_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

// Destroy a named semaphore
PlatformError_t ME_Semaphore_Unlink_t(const char_t* i_Name_pc)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  v_Result_s32 = sem_unlink(i_Name_pc);
  v_Error_t = ME_GetPlatformError_t(v_Result_s32);

  return v_Error_t;
}

// Wait on a named or unnamed semaphore
PlatformError_t ME_Semaphore_Wait_t(Semaphore_s* b_Semaphore_po)
{
  sint32_t        v_Result_s32;
  PlatformError_t v_Error_t;

  if(NULL != b_Semaphore_po)
  {
    v_Result_s32 = sem_wait(b_Semaphore_po->qnxSem_po);
    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeFault;
  }

  return v_Error_t;
}

#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
