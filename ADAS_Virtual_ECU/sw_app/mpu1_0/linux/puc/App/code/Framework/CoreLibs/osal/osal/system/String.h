// --------------------------------------------------------------------------
/// @file String.h
/// @brief Make sure to use memory pool before usage.
/// Own wrapper around mepl STL string class.
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

#ifndef PLATFORM_STRING_H
#define PLATFORM_STRING_H

#include "platform/stdlib/memory/PlatformStl.h"

namespace osal
{

class String;

String operator + (char_t i_Other_c, const String& i_String_ro);

class String
{
public:
  typedef mepl::string DataType_t;
  static const uint32_t c_Npos_u32 = static_cast<uint32_t>(-1);

  // Constructors
  String();
  ~String();

  // PRQA S 2180 1 // intended for strings due to easier usage.
  String(const char_t* i_String_pc);
  String(const String& i_String_ro);
  String(const char_t* i_String_pc, size_t i_Length_t);
  explicit String(char_t i_Char_c);

  // return non-modifiable char pointer
  const char_t* getString_pc() const;

  // return string data type
  DataType_t& getData_ro();

  // return string data type - const version
  const DataType_t& getData_ro() const;

  // Returns the count of character stored in this string. The count does not include a null terminator.
  // Remark: GetLength could be less than getSize_u32(), because of Utf-8 encodings.
  uint32_t getLength_u32() const;

  // Returns the count of bytes for the current string. null terminator is not included.
  size_t getSize_t() const;

  // The number of characters allocated for this object (including null terminator).
  size_t getAllocSize_t() const;

  // clears the string
  void clear_v();

  // true if string is empty
  bool_t isEmpty_b() const;

  // get string at index
  char_t getAt_c(uint32_t i_Index_u32) const;

  // set string at index
  void setAt_v(uint32_t i_Index_u32, char_t i_Char_c);

  // Find char at start index, returns c_Npos_u32 if nothing was found
  uint32_t find_u32(char_t i_Char_c, uint32_t i_Start_u32 = 0) const;

  // Find String at start index, returns c_Npos_u32 if nothing was found
  uint32_t find_u32(const String& i_String_ro, uint32_t i_Start_u32 = 0) const;

  // Reverse find char in this string
  uint32_t reverseFind_u32(char_t i_Char_c) const;

  /// Reverse finds a substring in this string searching from the end to the beginning
  uint32_t reverseFind_u32(const char_t* i_String_pc, uint32_t i_Endpos_u32 = String::c_Npos_u32) const;

  /// Find first occurrence of the given string in this string
  uint32_t findFirstOf_u32(const char_t* i_String_pc, uint32_t i_Start_u32 = 0) const;

  String tokenize_o(const char_t i_Token_c, uint32_t& i_Start_u32) const;

  uint32_t tokenize_o(const char_t i_Token_c, mepl::vector<String>& o_Result_ro) const;

  String mid_o(uint32_t start, uint32_t count) const;

  String mid_o(uint32_t start) const;

#if 0
  String left_o(int count) const;

  String right_o(int count) const;
#endif

  void trimRight_v(const String& i_String_ro);

  uint32_t replace_u32(const char_t* i_OldStr_pc, uint32_t i_LenOldStr_u32, const char_t* o_NewStr_pc, uint32_t i_LenNewStr_u32);
  uint32_t replace_u32(const char_t* i_OldStr_pc, const char_t* o_NewStr_pc);

  void appendChar_v(const char_t i_Char_c);

  void appendString_v(const char* i_String_pc);

  void appendString_v(const String& i_String_ro);

  bool_t compare_b(const String& i_Other_ro) const;

  bool_t compare_b(const char_t* i_Other_pc) const;

  bool_t compare_b(char_t i_Other_c) const;

  // operators
  String& operator = (const String& i_Other_ro);
  String& operator = (const char_t* i_Other_pc);
  String& operator = (char_t i_Other_c);

  String operator + (const String& i_Other_ro) const;
  String operator + (const char_t* i_Other_pc) const;
  String operator + (char_t i_Other_c) const;

  String& operator += (const String& i_Other_ro);
  String& operator += (const char_t* i_Other_pc);
  String& operator += (char_t i_Other_c);

  bool_t operator == (const String& i_Other_ro) const;
  bool_t operator == (const char_t* i_Other_ro) const;
  bool_t operator == (char_t i_Other_c) const;

  bool_t operator != (const String& i_Other_ro) const;
  bool_t operator != (const char_t* i_Other_ro) const;
  bool_t operator != (char_t i_Other_c) const;

private:
  DataType_t data_t;

};

} // namespace osal

#endif // PLATFORM_STRING_H
