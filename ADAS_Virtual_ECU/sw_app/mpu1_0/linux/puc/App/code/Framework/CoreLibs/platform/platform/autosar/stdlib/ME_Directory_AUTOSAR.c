/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

// Compile this file for Autosar only
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_AUTOSARTODO

#include "platform/stdlib/ME_Directory.h"

#include <unistd.h>
#include <dirent.h>

// PRQA S 492 EOF // file name/path compare with char array, OK

bool_t ME_Directory_IsAbsolutePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32) // PRQA S 1505 // called from cpp context, not in this analysis
{
  bool_t v_Result_b = true;

  if(NULL != i_Path_pc)
  {
    if(
        (i_Length_u32 < 1) || // must start with '/' (ME_PATH_SEPARATOR)
        (i_Path_pc[0] != ME_PATH_SEPARATOR)
      )
    {
      v_Result_b = false;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_IsRelativePath_b(const char_t* i_Path_pc, uint32_t i_Length_u32)
{
  bool_t v_Result_b;

  if(NULL != i_Path_pc)
  {
    // !operator leads to QAC-Warning: Msg(2:4116) Operand of logical ! operator is not an 'essentially Boolean' expression.
    if(true  == ME_Directory_IsAbsolutePath_b(i_Path_pc, i_Length_u32))
    {
      v_Result_b = false;
    }
    else
    {
      v_Result_b = true;
    }

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
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_Create_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = true;

  if(NULL != i_Path_pc)
  {
    if(0 != mkdir(i_Path_pc, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))
    {
      v_Result_b = false;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_Delete_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = false;

  if(NULL != i_Path_pc)
  {
    if(0 == rmdir(i_Path_pc))
    {
      v_Result_b = true;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

bool_t ME_Directory_Exists_b(const char_t* i_Path_pc)
{
  bool_t v_Result_b = false;

  if(NULL != i_Path_pc)
  {
    DIR* dir = opendir(i_Path_pc);
    if(NULL != dir)
    {
      v_Result_b = true;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}

//////////////////////////////////////////////////////////////////////////

bool_t ME_Directory_GetCurrentDir_b(uint32_t i_BufferLen_u32, char_t* o_CurrentDir_pc)
{
  bool_t v_Result_b = false;

  if(NULL != o_CurrentDir_pc)
  {
    if(NULL != getcwd(o_CurrentDir_pc, i_BufferLen_u32))
    {
      v_Result_b = true;
    }
  }
  else
  {
    v_Result_b = false;
  }

  return v_Result_b;
}


#endif // ME_PLATFORM_AUTOSAR // PRQA S 862 // this define decides which platform is defined
