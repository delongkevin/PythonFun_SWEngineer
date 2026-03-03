//--------------------------------------------------------------------------                                                                                                           
/// @file PlatformNew.cpp
/// @brief overloads the global new, array new, delete, array delete operators.
///
/// These operators utilize the PlatformMemory allocator,
/// doesn't throw any exceptions and returns NULL if we run out of memory.
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

// this define enables/disables new/delete operator overload
#ifdef PLATFORM_OVERLOAD_NEW_DELETE

#include <new>
#include <stdio.h>
#include "PlatformMemory.h"

// PRQA S 5118 EOF // this is the platform implementation of new

void* operator new(std::size_t i_Size_t)
{
  void* v_Allocated_pv = NULL;

  if (i_Size_t != 0)
  {
    v_Allocated_pv = lMepl_F_Malloc_pv(i_Size_t);

    if (NULL == v_Allocated_pv)
    {
      printf("Out of memory");
    }
  }
  else
  {
    printf("Bad Size");
  }

  return v_Allocated_pv;
}

void operator delete(void* i_Memory_pv)
{
  lMepl_F_Free_v(i_Memory_pv);
}

void* operator new[](std::size_t i_Size_t)
{
  void* v_Allocated_pv = NULL;

  if (i_Size_t != 0)
  {
    v_Allocated_pv = lMepl_F_Malloc_pv(i_Size_t);

    if (NULL == v_Allocated_pv)
    {
      printf("Out of memory");
    }
  }
  else
  {
    printf("Bad Size");
  }

  return v_Allocated_pv;
}

void operator delete[] (void* i_Memory_pv)
{
  lMepl_F_Free_v(i_Memory_pv);
}

#endif
