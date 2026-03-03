/* PRQA S 1011 EOF */ /* C99 comments allowed, this file is shared between cpp and c */

//--------------------------------------------------------------------------

/// @file ME_String.h
/// @brief Interface to abstract standard-library String functions
/// See QNX/MSDN/Stdlib Documentation for usage. Most functions are wrappers
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef ME_STRING_H
#define ME_STRING_H

#include "platform/PlatformSpecs.h"
#include "platform/stdlib/StdLibTypes.h"

#if defined(__cplusplus)
extern "C"
{
#endif

#include <stdarg.h>

sint32_t ME_String_Scanf_s32(const char_t* i_Format_pc, ...);
sint32_t ME_String_Vscanf_s32(const char_t* i_Format_pc, va_list argptr);
sint32_t ME_String_Printf_s32(const char_t* i_Format_pc, ...);
sint32_t ME_String_Sprintf_s32(char_t* i_String_pc, const char_t* i_Format_pc, ...);
sint32_t ME_String_Swprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, ...);

// -- copy / concatenation ---
void     ME_String_Wcsncpy_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t);
void     ME_String_Strncat_v(char_t* o_StrDest_pc, size_t i_SizeInBytes_t, const char_t* i_StrSource_pc, size_t i_Count_t);
void     ME_String_Wcsncat_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t);
void     ME_String_Strcpy_v(char_t* o_StrDest_pc, const char_t* i_Source_pc);
void     ME_String_Strncpy_v(char_t* o_StrDest_pc, size_t i_SizeInBytes_t, const char_t* i_Source_pc, size_t i_Count_t);

sint32_t ME_String_Vsprintf_s32(char_t* i_Buffer_pc, const char_t* i_Format_pc, va_list i_Argptr_t);
sint32_t ME_String_Vswprintf_s32(wchar_t* i_Buffer_pc, size_t i_SizeInWords_t, const wchar_t* i_Format_pc, va_list i_Argptr_t);
sint32_t ME_String_Snprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, ...);
sint32_t ME_String_Vsnprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, va_list i_Argptr_t);
sint32_t ME_String_Snwprintf_s32(wchar_t* i_Buffer_pc,  size_t i_Count_t, const wchar_t* i_Format_pc, ...);
sint32_t ME_String_Vsnwprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, va_list i_Argptr_t);

// -- find --
char_t*  ME_String_StrStr_pc(const char_t* i_Buffer_pc, const char_t* i_SearchString_pc);

// --- Compare (wide) Strings ---
// 0 = equal strings
sint32_t ME_String_Stricmp_s32(const char_t* i_String1_pc, const char_t* i_String2_pc);
sint32_t ME_String_Wcsicmp_s32(const wchar_t* i_String1_pc, const wchar_t* i_String2_pc);

// --- Conversion functions ---
bool_t    ME_String_Itoa_b(sint32_t i_Value_s32, char_t* o_Buffer_pc, sint32_t i_Radix_s32);
sint32_t  ME_String_Atoi_s32(const char_t* i_String_pc);
sint64_t  ME_String_Atoi64_s64(const char_t* i_String_pc);
float32_t ME_String_Atof_f32(const char_t* i_String_pc);
sint32_t  ME_String_Wtoi_s32(const wchar_t* i_String_pc);
sint64_t  ME_String_Wtoi64_s64(const wchar_t* i_String_pc);
float32_t ME_String_Wtof_f32(const wchar_t* i_String_pc);

sint32_t  ME_String_WideCharToMultiByte_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32);
sint32_t  ME_String_MultiByteToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32);
sint32_t  ME_String_WideCharToUTF16_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32);
// Convert from UTF-16 to wchar_t (see above) Make sure to only pass multiples of 2 as 2. argument (sizeInBytes). Otherwise iconv will not work and gets stuck
sint32_t  ME_String_UTF16ToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32);

// --- Count functions ---
sint32_t ME_String_CountCharacters_s32(const char_t* i_String_pc);
sint32_t ME_String_CountCharactersW_s32(const wchar_t* i_WString_pc);
sint32_t ME_String_CountBytes_s32(const char_t* i_String_pc);
sint32_t ME_String_CountBytesW_s32(const wchar_t* i_WString_pc);

#if defined(__cplusplus)
}
;
// extern C
#endif

#endif // ME_THREAD_H
