// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for Linux only
#ifdef ME_PLATFORM_LINUX

#include "platform/stdlib/ME_File.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

PlatformError_t ME_File_Open_t(FileHandle_s* b_Handle_ps, const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if ((NULL != i_FileName_pc) && (NULL != b_Handle_ps))
  {
    // 1. Convert open flags to a string interpreted by fopen()
    char_t v_OpenMode_ac[16];

    sint32_t i = 0;

    if ((i_OpenFlags_u32 & e_FomWrite) == e_FomWrite)
    {
      if ((i_OpenFlags_u32 & e_FomAppend) == e_FomAppend)
      {
        v_OpenMode_ac[i] = 'a';
      }
      else
      {
        // overwrite
        v_OpenMode_ac[i] = 'w';
      }

      ++i; // PRQA S 2984 1 // This operation is NOT redundant.
    }

    if ((i_OpenFlags_u32 & e_FomRead) == e_FomRead)
    {
      if ((i_OpenFlags_u32 & e_FomWrite) == e_FomWrite)
      {
        // read-write mode: add a plus to 'w' or 'a'
        v_OpenMode_ac[i] = '+';
      }
      else
      {
        // read only
        v_OpenMode_ac[i] = 'r';
      }

      ++i;
    }

    // open in binary mode ?
    if ((i_OpenFlags_u32 & e_FomBinary) == e_FomBinary)
    {
      v_OpenMode_ac[i] = 'b';
      ++i;
    }

    // Null Terminate
    v_OpenMode_ac[i] = '\0';

    // 2. Open file
    b_Handle_ps->qnxFileHandle_po = fopen(i_FileName_pc, (const char_t*) v_OpenMode_ac);

    // 3. Check for errors
    if (NULL == b_Handle_ps->qnxFileHandle_po)
    {
      v_Error_t = ME_GetPlatformError_t(-1);
    }
    else
    {
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

uint64_t ME_File_Read_u64(FileHandle_s* i_Handle_ps, void* i_Buffer_pv, uint64_t i_BufferSize_u64)
{
  uint64_t v_NumBytesRead_u64 = 0;

  if ((NULL != i_Buffer_pv) && (i_Handle_ps != NULL ))
  {
    v_NumBytesRead_u64 = fread(i_Buffer_pv, 1, i_BufferSize_u64, i_Handle_ps->qnxFileHandle_po);
  }

  return v_NumBytesRead_u64;
}

uint64_t ME_File_Write_u64(const FileHandle_s* i_Handle_ps, const void* i_Buffer_pv, uint64_t i_BufferSize_u64)
{
  uint64_t v_NumBytesWritten_u64 = 0;

  if ((NULL != i_Buffer_pv) && (i_Handle_ps != NULL ))
  {
    v_NumBytesWritten_u64 = fwrite(i_Buffer_pv, 1, i_BufferSize_u64, i_Handle_ps->qnxFileHandle_po);
  }

  return v_NumBytesWritten_u64;
}

uint64_t ME_File_SetPointer_u64(FileHandle_s* i_Handle_ps, sint64_t i_DistanceToMove_s64, FilePointer_t i_StartingPoint_e)
{
  uint64_t v_NewFilePointer_u64 = 0;

  if (i_Handle_ps != NULL)
  {
    const sint32_t seekModeMapping[] =
    {
      SEEK_SET,        // e_FpBegin
      SEEK_CUR,        // e_FpCurrent
      SEEK_END         // e_FpEnd
    };

    if (fseeko(i_Handle_ps->qnxFileHandle_po, i_DistanceToMove_s64, seekModeMapping[i_StartingPoint_e]) != 0)
    {
      // seek fail
      v_NewFilePointer_u64 = 0;
    }
    else
    {
      v_NewFilePointer_u64 = (uint64_t)ftello(i_Handle_ps->qnxFileHandle_po);
    }
  }

  return v_NewFilePointer_u64;
}

uint64_t ME_File_GetSize_u64(FileHandle_s* i_Handle_ps)
{
  uint64_t v_FileSize_u64 = 0;

  if (i_Handle_ps != NULL)
  {
    sint64_t v_CurrFilePointer_s64 = (sint64_t)ftello(i_Handle_ps->qnxFileHandle_po);

    if (v_CurrFilePointer_s64 < 0)
    {
      // something went wrong
      v_FileSize_u64 = 0;
    }
    else
    {
      // Go to end of file and get the file pointer position
      if (fseeko(i_Handle_ps->qnxFileHandle_po, 0, SEEK_END) != 0)
      {
        // something went wrong
        v_FileSize_u64 = 0;
      }
      else
      {
        // get size
        v_FileSize_u64 = (uint64_t)ftello(i_Handle_ps->qnxFileHandle_po);

        // Reset File pointer
        (void)fseeko(i_Handle_ps->qnxFileHandle_po, v_CurrFilePointer_s64, SEEK_SET);
      }
    }
  }

  return v_FileSize_u64;
}

PlatformError_t ME_File_Close_t(const FileHandle_s* b_Handle_ps)
{
  PlatformError_t v_Error_t;

  if((b_Handle_ps != NULL) && (NULL != b_Handle_ps->qnxFileHandle_po))
  {
    // returns: Zero for success, or -1 if an error occurs (errno is set).
    sint32_t v_Result_s32 = fclose(b_Handle_ps->qnxFileHandle_po);

    v_Error_t = ME_GetPlatformError_t(v_Result_s32);
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

PlatformError_t ME_File_Delete_t(const char_t* i_FileName_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(NULL != i_FileName_pc)
  {
    if (0 != remove(i_FileName_pc))
    {
      v_Error_t = e_PeFault;
    }
  }
  else
  {
    v_Error_t = e_PeInvalid;
  }

  return v_Error_t;
}

#else
/* do not do anything */
#endif // ME_PLATFORM_LINUX // PRQA S 862 // this define decides which platform is defined
