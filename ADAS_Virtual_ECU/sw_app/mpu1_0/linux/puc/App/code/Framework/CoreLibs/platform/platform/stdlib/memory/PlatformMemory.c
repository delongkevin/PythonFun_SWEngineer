/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */
//--------------------------------------------------------------------------                                                                                                           
/// @file PlatformMemory.c
/// @brief Encapsulates the tlsf allocator and provides a default memory pool 
/// 
/// This allocator is not thread safe, so we provide a method to register callbacks for lock / unlock.
/// These callbacks are called for all functions that manipulate the memory pool: malloc/realloc/mem align/free
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#include "PlatformMemory.h"

#include "platform/stdlib/ME_Debugger.h"

// globals
static tlsf_t                g_TlsfPool_pv = NULL;
static MeplMemoryLockCb_t    g_LockCB_t    = NULL;
static MeplMemoryUnlockCb_t  g_UnLockCB_t  = NULL;

void lMepl_F_RegisterCallbacks_v(MeplMemoryLockCb_t i_Lock_t, MeplMemoryUnlockCb_t i_Unlock_t)
{
  g_LockCB_t = i_Lock_t;
  g_UnLockCB_t = i_Unlock_t;
}

void lMepl_F_InitMemoryPool_v(void* i_MemoryPool_pv, size_t i_Size_t)
{
  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  g_TlsfPool_pv = tlsf_create_with_pool(i_MemoryPool_pv, i_Size_t);

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }
}

void lMepl_F_DestroyMemoryPool_v(void)
{
  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  tlsf_destroy(g_TlsfPool_pv);
  g_TlsfPool_pv = NULL;

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }
}

void* lMepl_F_Malloc_pv(size_t i_Size_t)
{
  void* v_Allocated_pv;

  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  v_Allocated_pv = tlsf_malloc(g_TlsfPool_pv, i_Size_t);

  if (NULL == v_Allocated_pv)
  {
    ME_Debugger_F_Printf_v("Out of Memory\n");
  }

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }

  return v_Allocated_pv;
}

void* lMepl_F_Realloc_pv(void* i_Memory_pv, size_t i_Size_t)
{
  void* v_Allocated_pv;

  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  v_Allocated_pv = tlsf_realloc(g_TlsfPool_pv, i_Memory_pv, i_Size_t);

  if (NULL == v_Allocated_pv)
  {
    ME_Debugger_F_Printf_v("Out of Memory\n");
  }

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }

  return v_Allocated_pv;
}

void lMepl_F_Free_v(const void* i_Memory_pv)
{
  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  tlsf_free(g_TlsfPool_pv, i_Memory_pv);

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }
}

void* lMepl_F_MemAlign_pv(size_t i_Align_u3264, size_t i_Size_t)
{
  void* v_Allocated_pv;

  if (NULL != g_LockCB_t)
  {
    g_LockCB_t();
  }

  v_Allocated_pv = tlsf_memalign(g_TlsfPool_pv, i_Align_u3264, i_Size_t);

  if (NULL == v_Allocated_pv)
  {
    ME_Debugger_F_Printf_v("Out of Memory\n");
  }

  if (NULL != g_UnLockCB_t)
  {
    g_UnLockCB_t();
  }

  return v_Allocated_pv;
}
