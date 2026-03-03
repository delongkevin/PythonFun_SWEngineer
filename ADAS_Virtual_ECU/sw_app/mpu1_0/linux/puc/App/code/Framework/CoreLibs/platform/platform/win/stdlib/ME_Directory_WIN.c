//--------------------------------------------------------------------------
/// @file ME_Directory_WIN.c
/// @brief Contains the implementation to platform Windows specific directory and path control functions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------


// Compile this file for windows only
#include "platform/PlatformSpecs.h"

#ifdef ME_PLATFORM_WIN

#include "platform/stdlib/ME_Directory.h"
#include "platform/stdlib/ME_Debugger.h"
#include "platform/win/WinInclude.h"


bool_t ME_Directory_IsAbsolutePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32)
{
  bool_t v_Result_b = true;

  if (NULL == i_Path_pc)
  {
    v_Result_b = false;
  }

  if (
      (i_Length_u32 < 3) || // must start like C:/
      (i_Path_pc[1] != ':') ||
      (i_Path_pc[2] != ME_PATH_SEPARATOR)
     )
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_IsRelativePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32)
{
  bool_t v_Result_b;

  if (NULL == i_Path_pc)
  {
    v_Result_b = false;
  }

  v_Result_b = !ME_Directory_IsAbsolutePath_b(i_Path_pc, i_Length_u32);

  if (i_Length_u32 == 1)
  {
    if (i_Path_pc[0] == ME_PATH_SEPARATOR)
    {
      v_Result_b = false;
    }
  }

  if (i_Length_u32 == 2)
  {
    if (i_Path_pc[0] == ME_PATH_SEPARATOR)
    {
      v_Result_b = false;
    }

    if (i_Path_pc[0] == '.')
    {
      if (i_Path_pc[1] != ME_PATH_SEPARATOR)
      {
        v_Result_b = false;
      }
    }
  }

  if (i_Length_u32 >= 2)
  {
    if (i_Path_pc[0] == ME_PATH_SEPARATOR)
    {
      v_Result_b = false;
    }

    if (i_Path_pc[0] == '.')
    {
      if (i_Path_pc[1] == '.')
      {
        if (i_Path_pc[2] != ME_PATH_SEPARATOR)
        {
          v_Result_b = false;
        }
      }
      else if (i_Path_pc[1] != ME_PATH_SEPARATOR)
      {
        v_Result_b = false;
      }
      else
      {
        // do not change v_Result_b
      }
    }
  }

  return v_Result_b;
}

bool_t ME_Directory_Create_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = true;

  if (NULL == i_Path_pc)
  {
    v_Result_b = false;
  }

  if(0 == CreateDirectory(i_Path_pc, NULL)) // using default security attributes
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_Delete_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = true;

  if (NULL == i_Path_pc)
  {
    v_Result_b = false;
  }

  if(0 == RemoveDirectory(i_Path_pc)) // using default security attributes
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_Exists_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = true;

  if (NULL == i_Path_pc)
  {
    v_Result_b = false;
  }

  if (-1 == (sint32_t)GetFileAttributesA(i_Path_pc))
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

//////////////////////////////////////////////////////////////////////////

bool_t ME_Directory_GetCurrentDir_b(uint32_t i_BufferLen_u32, char_t* o_CurrentDir_pc)
{
  bool_t v_Result_b = false;

  if (NULL == o_CurrentDir_pc)
  {
    v_Result_b = false;
  }

  if(0 < GetCurrentDirectory(i_BufferLen_u32, o_CurrentDir_pc))
  {
    v_Result_b = true;
  }

  return v_Result_b;
}


#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
