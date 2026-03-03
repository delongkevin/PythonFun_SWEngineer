/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

/*
 * ME_File.h
 *
 *  Creation Date: 15.11.2017
 *         Author: Marcel Engelhardt
 *        Company: Magna Electronics
 */

#ifndef ME_FILE_H_
#define ME_FILE_H_

#include "platform/PlatformSpecs.h"

#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif


/// File open mode
typedef enum FileOpenMode_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_FomRead    = 0x00000001, ///< Read access.
  e_FomWrite   = 0x00000002, ///< Write access; Overwrites an existing file if the RD_FOM_APPEND flag is not set.
  e_FomAppend  = 0x00000004, ///< When opening with write-access: Don't overwrite but append to an existing file.
  e_FomBinary  = 0x00000008  ///< Flag to set Read / Write Binary
} FileOpenMode_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

/// Position in a file. Don't change Order!
typedef enum FilePointer_e // PRQA S 2400 // global scope, this is a shared c and cpp header file
{
  e_FpBegin   = 0,  ///< Position is relative to the beginning of the file.
  e_FpCurrent = 1,  ///< Position is a consecutive file pointer
  e_FpEnd     = 2   ///< Position is relative to the end of the file
} FilePointer_t; // PRQA S 2400 // global scope, this is a shared c and cpp header file

// --------------------------------------------------------------------------
/// Opens a file.
///
/// The parameter \c i_OpenFlags_u32 is a combination of \c FileOpenMode_e flags.
///
/// @param[in,out] b_Handle_ps     Pointer to the file handle to be stored to
/// @param[in]     i_FileName_pc   File name / path to be opened
/// @param[in]     i_OpenFlags_u32 Flags specifying the open mode
/// @return PlatformError_t#e_PeOk if the operation succeeds, PlatformError_t#e_PeInvalid otherwise
// --------------------------------------------------------------------------
PlatformError_t ME_File_Open_t(FileHandle_s* b_Handle_ps, const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32);

// --------------------------------------------------------------------------
/// Reads from a file.
///
/// @param[in] i_Handle_ps      Pointer to file handle to be read from
/// @param[in] i_Buffer_pv      Buffer to be written to
/// @param[in] i_BufferSize_u64 Size of the Buffer to be written to
/// @return Number of bytes read if the operation succeeds, \c 0 otherwise
// --------------------------------------------------------------------------
uint64_t ME_File_Read_u64(FileHandle_s* i_Handle_ps, void* i_Buffer_pv, uint64_t i_BufferSize_u64);

// --------------------------------------------------------------------------
/// Writes to a file.
///
/// @param[in] i_Handle_ps      Pointer to file handle to be written to
/// @param[in] i_Buffer_pv      Buffer to be read from
/// @param[in] i_BufferSize_u64 Size of the Buffer to be read from
/// @return Number of bytes written if the operation succeeds, \c 0 otherwise
// --------------------------------------------------------------------------
uint64_t ME_File_Write_u64(const FileHandle_s* i_Handle_ps, const void* i_Buffer_pv, uint64_t i_BufferSize_u64);

// --------------------------------------------------------------------------
/// Moves the file pointer to the specified position. Returns the new file pointer.
///
/// @param[in] i_Handle_ps          Pointer to file handle whose next access position has to be moved
/// @param[in] i_DistanceToMove_s64 Distance to move
/// @param[in] i_StartingPoint_e    Start position
/// @return New file access position if the operation succeeds, \0 otherwise
// --------------------------------------------------------------------------
uint64_t ME_File_SetPointer_u64(FileHandle_s* i_Handle_ps, sint64_t i_DistanceToMove_s64, FilePointer_t i_StartingPoint_e);

// --------------------------------------------------------------------------
/// Returns the size of a file.
///
/// @param[in] i_Handle_ps Pointer to the file handle
/// @return File size if the operation succeeds, \0 otherwise
// --------------------------------------------------------------------------
uint64_t ME_File_GetSize_u64(FileHandle_s* i_Handle_ps);

// --------------------------------------------------------------------------
/// Closes an open file.
///
/// @param[in,out] b_Handle_ps Pointer to the file handle to be closed
/// @return PlatformError_t#e_PeOk if the operation succeeds, PlatformError_t#e_PeInvalid otherwise
PlatformError_t ME_File_Close_t(const FileHandle_s* b_Handle_ps);
// --------------------------------------------------------------------------

// --------------------------------------------------------------------------
/// Deletes an existing file
///
/// @param[in] i_FileName_pc Name / path of the file to be deleted
/// @return PlatformError_t#e_PeOk if the operation succeeds, PlatformError_t#e_PeInvalid otherwise
// --------------------------------------------------------------------------
PlatformError_t ME_File_Delete_t(const char_t* i_FileName_pc);

#if defined(__cplusplus)
}; // extern C
#endif


#endif /* ME_FILE_H_ */
