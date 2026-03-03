//--------------------------------------------------------------------------
/// @file IFile.h
/// @brief Contains the interface definition for file objects.
/// Acts as a base for different file Types (e.g. Archives, Memfiles, and FileSystem files)
/// Make sure to initialize memory pool before usage
/// Why String and no StringW? check out https://stackoverflow.com/questions/4676327/how-to-open-a-file-with-wchar-t-containing-non-ascii-string-in-linux
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (mark.reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef OSAL_I_FILE_H
#define OSAL_I_FILE_H

#include <platform/PlatformAPI.h>

namespace osal
{

class IFile
{
public:
  /// Creates a file object with no filename given.
  IFile() {}

  /// The filename can be set later using setFileName_v()
  virtual ~IFile() {}

  /// Closes the file.
  /// @return true on success, false on failure (e.g. already closed).
  virtual bool_t close_b() = 0;

  /// Write the buffer content to a file.
  /// @param[in] i_Buffer_pv pointer to a data buffer
  /// @param[in] i_BufferSize_u64 number of bytes in the data buffer.
  /// @return number of bytes that were actually written.
  virtual uint64_t write_u64(const void* i_Buffer_pv, uint64_t i_BufferSize_u64) = 0;

  /// Read the content of a file and write it to a given buffer.
  /// @param[out] b_Buffer_po pointer to a data buffer
  /// @param[in] i_BufferSize_u64 maximum number of bytes in the data buffer.
  /// @return number of bytes that were actually read.
  virtual uint64_t read_u64(void* b_Buffer_po, uint64_t i_BufferSize_u64) = 0;

  /// Set the file pointer to a given position relative to the beginning, current position or
  /// end of the file.
  /// @param[in] i_DistanceToMove_s64 number of bytes relative to the origin. Has to be negative if
  /// the origin is the end of the file.
  /// @param[in] i_Origin_e either beginning, current position or end of the file.
  /// @return the new seeker position
  virtual uint64_t seek_u64(sint64_t i_DistanceToMove_s64, FilePointer_e i_Origin_e) = 0;

  /// Gets the current position set with the last seek, read or write operation.
  virtual uint64_t getPosition_u64(void) = 0;

  /// Returns the size of a file.
  virtual uint64_t getSize_u64(void) = 0;

};

} // namespace osal

#endif // OSAL_I_FILE_H
