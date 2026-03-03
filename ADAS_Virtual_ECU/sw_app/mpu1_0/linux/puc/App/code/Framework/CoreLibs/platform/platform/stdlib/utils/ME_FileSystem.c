/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_FileSystem.h
/// @brief Simple Interface for a Magna file system
/// 
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

// include needed to check OS define

#include "platform/PlatformAPI.h"

#include "cfg/FileSystem/FileSystem.h"

static ME_FileSystemHeader_t s_FileSystemHeader_s;
static ME_FileInfo_t         s_FileInfos_at[c_MAX_NUMBER_OF_FILES_u32];

/// Init file system with an existing file (e.g. WIN environment)
/// todo: need to implement a tool for creating FileSystem Emulation file
PlatformError_t ME_FileSystem_F_InitByFileName_t(const char_t* i_FsFileName_pc)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

/// Init file system with a knowing (physical) address in the RAM
PlatformError_t ME_FileSystem_F_InitByPhysicalAddress_t(const void* i_FsBaseAddress_pv)
{
  PlatformError_t v_Error_t = e_PeOk;
  ME_FileSystemEntry_t v_Entry_t;
  uint8_t v_I_u8 = 0U;

  memcpy(&s_FileSystemHeader_s, &c_FileSystemArray_au8[c_FileSystemSize_u32 - sizeof(ME_FileSystemHeader_t)], sizeof(ME_FileSystemHeader_t));

  memcpy(&v_Entry_t, c_FileSystemArray_au8, sizeof(v_Entry_t));

  if(s_FileSystemHeader_s.fileSystemSize_u32 != c_FileSystemSize_u32)
  {
    v_Error_t = e_PeFault;
  }
  else
  {
    for(v_I_u8 = 0; v_I_u8 < s_FileSystemHeader_s.numberOfFiles_u32; v_I_u8++)
    {
      ME_FileSystemEntry_t* v_Entry_pt = (ME_FileSystemEntry_t*)&c_FileSystemArray_au8[v_I_u8 * sizeof(ME_FileSystemEntry_t)];
      
      s_FileInfos_at[v_I_u8].data_pv = (void*)&c_FileSystemArray_au8[v_Entry_pt->dataOffset_u32];
      s_FileInfos_at[v_I_u8].size_u32 = v_Entry_pt->size_u32;
      memcpy(s_FileInfos_at[v_I_u8].name_ac, v_Entry_pt->name_ac, strlen(v_Entry_pt->name_ac));
    }
  }

  Assert(v_Error_t == e_PeOk);

  return v_Error_t;
}

/// Open the given file
/// @return is non-zero, if file exists and was opened successfully
ME_FileInfo_t* ME_FileSystem_F_Fopen_t(const char_t* i_Name_pc, uint8_t i_Mode_u8)
{
  ME_FileInfo_t* v_Result_pt = NULL;
  uint8_t v_I_u8 = 0;
  for(v_I_u8 = 0; v_I_u8 < s_FileSystemHeader_s.numberOfFiles_u32; v_I_u8++)
  {
    if(0 == strcmp(i_Name_pc, s_FileInfos_at[v_I_u8].name_ac))
    {
      v_Result_pt = &s_FileInfos_at[v_I_u8];
    }
  }

  return v_Result_pt;
}

PlatformError_t ME_FileSystem_F_Fclose_t(const ME_FileInfo_t* i_FileInfo_pt)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

PlatformError_t ME_FileSystem_F_Fwrite_t(const ME_FileInfo_t* i_FileInfo_pt, const void* i_Data_pv, uint32_t i_Size_u32)
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}

uint32_t ME_FileSystem_F_Fread_u32(const ME_FileInfo_t* i_FileInfo_pt, void* o_Data_pv, uint32_t i_Size_u32)
{
  return 0;
}

ME_FileInfo_t* ME_FileSystem_F_Fcreate_t()
{
  return NULL;
}

PlatformError_t ME_FileSystem_F_Fdelete_t()
{
  PlatformError_t v_Error_t = e_PeOk;

  return v_Error_t;
}