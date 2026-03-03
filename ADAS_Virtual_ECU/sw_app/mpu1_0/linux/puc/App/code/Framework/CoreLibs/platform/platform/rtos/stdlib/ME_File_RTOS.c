/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * ME_File_RTOS.c
 *
 *  Creation Date: 28.09.2021
 *         Author: Martin Rachor
 *        Company: Magna Electronics
 */
// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for AUTOSAR only
#ifdef ME_PLATFORM_RTOS

#include "platform/stdlib/ME_File.h"
#include "platform/stdlib/ME_Assert.h"

PlatformError_t ME_File_Open_t(FileHandle_s* b_Handle_ps, const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32)
{
  PlatformError_t v_Error_t = e_PeInvalid;

  if ((NULL != i_FileName_pc) && (NULL != b_Handle_ps))
  {
    b_Handle_ps->FileHandle_pt = ME_FileSystem_F_Fopen_t(i_FileName_pc, 0);

    if(b_Handle_ps->FileHandle_pt != NULL)
    {
      v_Error_t = e_PeOk;
    }
  }

  return v_Error_t;
}

uint64_t ME_File_Read_u64(FileHandle_s* i_Handle_ps, void* i_Buffer_pv, uint64_t i_BufferSize_u64) /* PRQA S 3673 */ /* keep this function parameter not const */
{
  uint64_t v_NumBytesRead_u64 = 0;

  if ((NULL != i_Buffer_pv) && (i_Handle_ps != NULL ))
  {
    if((i_Handle_ps->FileHandle_pt->readIdx_u32 + i_BufferSize_u64) < i_Handle_ps->FileHandle_pt->size_u32)
    {
      memcpy(i_Buffer_pv, &((uint8_t*)i_Handle_ps->FileHandle_pt->data_pv)[i_Handle_ps->FileHandle_pt->readIdx_u32], i_BufferSize_u64);
      v_NumBytesRead_u64 = i_BufferSize_u64;
    }
    else if((i_Handle_ps->FileHandle_pt->readIdx_u32 + i_BufferSize_u64) >= i_Handle_ps->FileHandle_pt->size_u32)
    {
      v_NumBytesRead_u64 = i_Handle_ps->FileHandle_pt->size_u32 - i_Handle_ps->FileHandle_pt->readIdx_u32;
      if(v_NumBytesRead_u64 > 0)
      {
        memcpy(i_Buffer_pv, &((uint8_t*)i_Handle_ps->FileHandle_pt->data_pv)[i_Handle_ps->FileHandle_pt->readIdx_u32], v_NumBytesRead_u64);
      }
    }
  }

  i_Handle_ps->FileHandle_pt->readIdx_u32 += v_NumBytesRead_u64;

  Assert(i_Handle_ps->FileHandle_pt->readIdx_u32 <= i_Handle_ps->FileHandle_pt->size_u32);

  return v_NumBytesRead_u64;
}

uint64_t ME_File_Write_u64(const FileHandle_s* i_Handle_ps, const void* i_Buffer_pv, uint64_t i_BufferSize_u64)
{
  uint64_t v_NumBytesWritten_u64 = 0;

  if ((NULL != i_Buffer_pv) && (i_Handle_ps != NULL ))
  {
    v_NumBytesWritten_u64 = 0; //TODO: fwrite(i_Buffer_pv, 1, i_BufferSize_u64, i_Handle_ps->FileHandle_po);
  }

  return v_NumBytesWritten_u64;
}

uint64_t ME_File_SetPointer_u64(FileHandle_s* i_Handle_ps, sint64_t i_DistanceToMove_s64, FilePointer_t i_StartingPoint_e)/* PRQA S 3673 */ /* keep this function parameter not const */
{
  uint64_t v_NewFilePointer_u64 = 0;

  if (i_Handle_ps != NULL)
  {
    const sint32_t seekModeMapping[] =
    {
      0,//SEEK_SET,        // e_FpBegin
      1,//SEEK_CUR,        // e_FpCurrent
      2,//SEEK_END         // e_FpEnd
    };
  }

  return v_NewFilePointer_u64;
}

uint64_t ME_File_GetSize_u64(FileHandle_s* i_Handle_ps)
{
  uint64_t v_FileSize_u64 = 0;

  if (i_Handle_ps != NULL)
  {
  }

  return v_FileSize_u64;
}

PlatformError_t ME_File_Close_t(const FileHandle_s* b_Handle_ps)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_File_Delete_t(const char_t* i_FileName_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  if(NULL != i_FileName_pc)
  {
    /* if((0 != remove(i_FileName_pc)) */ /* TODO */
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

#endif // ME_PLATFORM_RTOS // PRQA S 862 // this define decides which platform is defined

