//--------------------------------------------------------------------------
/// @file File.h
/// @brief Contains the implementation for FileSystem files
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (mark.reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_FILE_H
#define OSAL_FILE_H

#include "IFile.h"

namespace osal
{

class File : public IFile
{
public:
  /// Creates a file object with no filename given.
  File();

  /// The filename can be set later using setFileName_v()
  virtual ~File();

  /// Opens a file.
  /// @param[in] i_FileName_ro Path and filename
  /// @param[in] i_OpenMode_e open the file in the given mode. Default is binary read-only.
  /// @return true on success, false on failure (e.g. already closed).
  bool_t                       open_b(const char_t* i_FileName_pc, uint32_t i_OpenFlags_u32);

  /// Closes the file.
  /// @return true on success, false on failure (e.g. already closed).
  virtual bool_t               close_b() ME_OVERRIDE;

  /// Write the buffer content to a file.
  /// @param[in] i_Buffer_pv pointer to a data buffer
  /// @param[in] i_BufferSize_u64 number of bytes in the data buffer.
  /// @return number of bytes that were actually written.
  virtual uint64_t             write_u64(const void* i_Buffer_pv, uint64_t i_BufferSize_u64) ME_OVERRIDE;

  /// Read the content of a file and write it to a given buffer.
  /// @param[out] b_Buffer_pv pointer to a data buffer
  /// @param[in] i_BufferSize_u64 maximum number of bytes in the data buffer.
  /// @return number of bytes that were actually read.
  virtual uint64_t            read_u64(void* b_Buffer_pv, uint64_t i_BufferSize_u64) ME_OVERRIDE;

  /// Set the file pointer to a given position relative to the beginning, current position or
  /// end of the file.
  /// @param[in] i_DistanceToMove_s64 number of bytes relative to the origin. Has to be negative if
  /// the origin is the end of the file.
  /// @param[in] i_Origin_e either beginning, current position or end of the file.
  /// @return the new seeker position
  virtual uint64_t            seek_u64(sint64_t i_DistanceToMove_s64, FilePointer_e i_Origin_e) ME_OVERRIDE;

  /// Gets the current position set with the last seek, read or write operation.
  virtual uint64_t            getPosition_u64(void) ME_OVERRIDE;

  /// Returns the size of a file.
  virtual uint64_t            getSize_u64(void) ME_OVERRIDE;

private:
  FileHandle_s  fileHandle_s;
  uint32_t      fileFlags_u32;
  bool_t        fileOpened_b;
};

} // namespace osal

#endif // OSAL_FILE_H
