/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------
/// @file ME_FileSstem.h
/// @brief Simple Interface for a file system
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

#ifndef ME_FILESYSTEM_H_
#define ME_FILESYSTEM_H_

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#define c_MAX_NUMBER_OF_FILES_u32     128U
#define c_MAX_FILE_NAME_SIZE_u32      128U

typedef struct ME_FileSystemHeader_s
{
  uint32_t          fileSystemSize_u32;
  uint32_t          numberOfFiles_u32;
} ME_FileSystemHeader_t;

typedef struct ME_FileSystemEntry_s
{
  uint32_t         idx_u32;
  char_t           name_ac[c_MAX_FILE_NAME_SIZE_u32];
  uint32_t         dataOffset_u32;
  uint32_t         size_u32;
} ME_FileSystemEntry_t;

typedef struct ME_FileInfo_s
{
  void*           data_pv;
  char_t          name_ac[c_MAX_FILE_NAME_SIZE_u32];
  uint32_t        readIdx_u32;
  uint32_t        writeIdx_u32;
  uint32_t        size_u32;
  uint8_t         type_u8;
  uint8_t         mode_u8;
} ME_FileInfo_t;


/// Init file system with an existing file (e.g. WIN environment)
PlatformError_t   ME_FileSystem_F_InitByFileName_t(const char_t* i_FsFileName_pc);

/// Init file system with a knowing (physical) address in the RAM
PlatformError_t   ME_FileSystem_F_InitByPhysicalAddress_t(const void* i_FsBaseAddress_pv);

/// Open the given file
/// @return is non-zero, if file exists and was opened successfully
ME_FileInfo_t*    ME_FileSystem_F_Fopen_t(const char_t* i_Name_pc, uint8_t i_Mode_u8);

PlatformError_t   ME_FileSystem_F_Fclose_t(const ME_FileInfo_t* i_FileInfo_pt);

PlatformError_t   ME_FileSystem_F_Fwrite_t(const ME_FileInfo_t* i_FileInfo_pt, const void* i_Data_pv, uint32_t i_Size_u32);

uint32_t          ME_FileSystem_F_Fread_u32(const ME_FileInfo_t* i_FileInfo_pt, void* o_Data_pv, uint32_t i_Size_u32);

ME_FileInfo_t*    ME_FileSystem_F_Fcreate_t();

PlatformError_t   ME_FileSystem_F_Fdelete_t();

#if defined(__cplusplus)
}; // extern C
#endif



#endif // ME_FILESYSTEM_H_
