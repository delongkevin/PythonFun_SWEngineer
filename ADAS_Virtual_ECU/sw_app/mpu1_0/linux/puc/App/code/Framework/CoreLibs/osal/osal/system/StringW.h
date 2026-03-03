// --------------------------------------------------------------------------
/// @file StringW.h
/// @brief Make sure to use memory pool before usage.
/// Own wrapper around mepl STL wstring class.
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@Magna.com)
///
// --------------------------------------------------------------------------

#ifndef PLATFORM_STRING_W_H
#define PLATFORM_STRING_W_H

#include "platform/stdlib/memory/PlatformStl.h"

namespace osal
{

class StringW
{
public:
  typedef mepl::wstring DataType_t;
  static const uint32_t c_Npos_u32 = static_cast<uint32_t>(-1);

  // Constructors
  StringW();
  ~StringW();
  explicit StringW(const wchar_t* i_StringW_pc);
  StringW(const wchar_t* i_StringW_pc, size_t i_Length_t);

  // return non-modifiable char pointer
  const wchar_t* getString_pc() const;

  // return string data type
  DataType_t& getData_ro();

  // return string data type - const version
  const DataType_t& getData_ro() const;

  // Returns the count of character stored in this string. The count does not include a null terminator.
  // Remark: GetLength could be less than getSize_u32(), because of Utf-8 encodings.
  size_t getLength_t() const;

  // Returns the count of bytes for the current string. null terminator is not included.
  size_t getSize_t() const;

  // The number of characters allocated for this object (including null terminator).
  size_t getAllocSize_t() const;

  // clears the string
  void clear_v();

  // true if string is empty
  bool_t isEmpty_b() const;

  // get string at index
  wchar_t getAt_c(uint32_t i_Index_u32) const;

  // set string at index
  void setAt_v(uint32_t i_Index_u32, wchar_t i_Char_c);

  // Find char at start index, returns c_Npos_u32 if nothing was found
  uint32_t find_u32(wchar_t i_Char_c, uint32_t i_Start_u32) const;

  // Find String at start index, returns c_Npos_u32 if nothing was found
  uint32_t find_u32(const StringW& i_StringW_ro, uint32_t i_Start_u32) const;

  // Reverse find char in this string
  uint32_t reverseFind_u32(wchar_t i_Char_c) const;

  /// Reverse finds a substring in this string searching from the end to the beginning
  uint32_t reverseFind_u32(const wchar_t* i_StringW_pc, uint32_t i_Endpos_u32 = StringW::c_Npos_u32) const;

  /// Find first occurrence of the given string in this string
  uint32_t findFirstOf_u32(const wchar_t* i_StringW_pc, uint32_t i_Start_u32 = 0) const;

  // operators
  StringW& operator += (char_t i_Other_c);
  StringW& operator += (const wchar_t* i_Other_pc);
  StringW& operator += (const StringW& i_Other_ro);

  bool operator == (wchar_t i_Other_c) const;
  bool operator != (wchar_t i_Other_c) const;

private:
  DataType_t data_t;

};

} // namespace osal

#endif // PLATFORM_STRING_W_H
