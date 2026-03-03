//--------------------------------------------------------------------------
/// @file MemoryFile.h
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

#ifndef OSAL_MEMORY_FILE_H
#define OSAL_MEMORY_FILE_H

#include "IFile.h"

namespace osal
{

class MemoryFile : public IFile
{
public:
  /// Creates a Memory file object
  MemoryFile();

  /// Destructor
  virtual ~MemoryFile();

  /// Opens a file.
  /// @param[in] b_Data_u8 uint8_t pointer to Data
  /// @param[in] i_Size_u64 data size in bytes
  /// @return true on success, false on failure (e.g. invalid arguments).
  bool_t                      open_b(uint8_t* b_Data_u8, uint64_t i_Size_u64, bool_t i_SwapEndian_b);

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
  uint64_t dataSize_u64; // data size in bytes
  uint8_t* data_pu8;     // pointer to Data;
  uint64_t position_u64; // current position in data array
  bool_t swapEndian_b;   // swap endianess when reading file ?
};

} // namespace osal

#endif // OSAL_FILE_H
