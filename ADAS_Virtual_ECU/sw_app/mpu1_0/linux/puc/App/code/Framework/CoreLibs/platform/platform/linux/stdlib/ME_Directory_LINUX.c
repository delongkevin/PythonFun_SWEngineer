// Compile this file for windows only
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

#include "platform/stdlib/ME_Directory.h"

#include <unistd.h>
#include <dirent.h>


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


#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
