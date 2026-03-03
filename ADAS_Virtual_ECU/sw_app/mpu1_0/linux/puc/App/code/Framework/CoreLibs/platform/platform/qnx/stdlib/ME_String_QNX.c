//--------------------------------------------------------------------------
/// @file ME_String_QNX.c
/// @brief Qnx implementation for standard-library String
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

// include needed to check OS define
#include "platform/PlatformSpecs.h"

// compile this file for QNX only
#ifdef ME_PLATFORM_QNX

// stdlib header include
#include "platform/stdlib/ME_String.h"

#include <string.h>
#include <wchar.h>
#include <stdlib.h>
#include <stdio.h> // PRQA S 5124 // standard library needed here, use of vprintf and vscan here

sint32_t ME_String_Scanf_s32(const char_t* i_Format_pc, ...)
{
  sint32_t v_Result_s32;
  va_list v_Argptr_t;
  va_start(v_Argptr_t, i_Format_pc);

  v_Result_s32 = vscanf(i_Format_pc, v_Argptr_t);

  va_end(v_Argptr_t);

  return v_Result_s32;
}

sint32_t ME_String_Vscanf_s32(const char_t* i_Format_pc, va_list argptr)
{
  return vscanf(i_Format_pc, argptr);
}

sint32_t ME_String_Printf_s32(const char_t* i_Format_pc, ...)
{
  sint32_t v_Result_s32 = -1;
  va_list  v_Argptr_t;

  if (NULL != i_Format_pc)
  {
    va_start(v_Argptr_t, i_Format_pc);
  }

  if (NULL != i_Format_pc)
  {
    v_Result_s32 = vprintf(i_Format_pc, v_Argptr_t);
  }

  va_end(v_Argptr_t);

  return v_Result_s32;
}

sint32_t ME_String_Sprintf_s32(char_t* i_String_pc, const char_t* i_Format_pc, ...)
{
  sint32_t v_Result_s32 = -1;
  va_list  v_Argptr_t;

  if (NULL != i_Format_pc)
  {
    va_start(v_Argptr_t, i_Format_pc);
  }
  if ( (NULL != i_Format_pc) && (NULL != i_String_pc) )
  {
    v_Result_s32 = vsprintf(i_String_pc, i_Format_pc, v_Argptr_t);
  }

  va_end(v_Argptr_t);

  return v_Result_s32;
}

sint32_t ME_String_Swprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, ...)
{
  sint32_t v_Result_s32;
  va_list v_Argptr_t;
  va_start(v_Argptr_t, i_Format_pc);

  v_Result_s32 = vswprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Argptr_t);

  va_end(v_Argptr_t);

  return v_Result_s32;
}

void ME_String_Wcsncpy_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t)
{
  size_t v_NumCopyWords_t = min(i_SizeInWords_t, i_Count_t);

  if (NULL != o_StrDest_pc)
  {
    // PRQA S 0492 1 // wcsncpy() is considered unsafe, force terminating zero (http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/)
    (void)wcsncpy(o_StrDest_pc, i_StrSource_pc, v_NumCopyWords_t);

    // PRQA S 0492 1 // ensured by range check numCopyWords
    o_StrDest_pc[v_NumCopyWords_t] = L'\0';
  }
}

void ME_String_Strncat_v(char_t* o_StrDest_pc, size_t i_SizeInBytes_t, const char_t* i_StrSource_pc, size_t i_Count_t)
{
  size_t v_Length_t;
  size_t v_NumCopyChars_t;

  if ( (NULL != i_StrSource_pc) && (NULL != o_StrDest_pc))
  {
    v_Length_t = i_SizeInBytes_t - strlen(o_StrDest_pc);

    if (v_Length_t > 0)
    {
      v_NumCopyChars_t = min(v_Length_t - 1, i_Count_t);

      (void)strncat(o_StrDest_pc, i_StrSource_pc, v_NumCopyChars_t);
    }
  }
}

void ME_String_Wcsncat_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t)
{
  size_t v_Length_t = i_SizeInWords_t - wcslen(o_StrDest_pc);

  if (v_Length_t > 0)
  {
    size_t v_NumCopyWords_t = min(v_Length_t - 1, i_Count_t);

    (void)wcsncat(o_StrDest_pc, i_StrSource_pc, v_NumCopyWords_t);
  }
}

void ME_String_Strcpy_v(char_t* o_StrDest_pc, const char_t* i_Source_pc)
{
  if ( (NULL != o_StrDest_pc) && (NULL != i_Source_pc))
  {
    (void)strcpy(o_StrDest_pc, i_Source_pc);
  }
}

void ME_String_Strncpy_v(char_t* o_StrDest_pc, size_t i_SizeInBytes_t, const char_t* i_Source_pc, size_t i_Count_t)
{
  size_t v_NumCopyChars_t = min(i_SizeInBytes_t, i_Count_t);

  if ( (NULL != o_StrDest_pc) && (NULL != i_Source_pc))
  {
    // PRQA S 0492 1 // strncpy() is considered unsafe, force terminating zero (http://randomascii.wordpress.com/2013/04/03/stop-using-strncpy-already/)
    (void)strncpy(o_StrDest_pc, i_Source_pc, v_NumCopyChars_t);
  }

  if ((NULL != o_StrDest_pc) && (v_NumCopyChars_t > 0))
  {
    // PRQA S 0492 1 // ensured by range check numCopyChars
    o_StrDest_pc[v_NumCopyChars_t - 1] = '\0';
  }

}

sint32_t ME_String_Vsprintf_s32(char_t* i_Buffer_pc, const char_t* i_Format_pc, va_list i_Argptr_t)
{
  sint32_t v_Result_s32 = -1;

  if ( (NULL != i_Buffer_pc) && (NULL != i_Format_pc))
  {
    // PRQA S 2814 1 // i_Argptr can't be null-checked
    v_Result_s32 = vsprintf(i_Buffer_pc, i_Format_pc, i_Argptr_t);
  }

  return v_Result_s32;
}

sint32_t ME_String_Vswprintf_s32(wchar_t* i_Buffer_pc, size_t i_SizeInWords_t, const wchar_t* i_Format_pc, va_list i_Argptr_t)
{
  sint32_t v_Result_s32 = -1;

  if ( (NULL != i_Buffer_pc) && (NULL != i_Format_pc))
  {
    // PRQA S 2814 1 // i_Argptr can't be null-checked
    v_Result_s32 = vswprintf(i_Buffer_pc, i_SizeInWords_t, i_Format_pc, i_Argptr_t);
  }

  return v_Result_s32;
}

sint32_t ME_String_Snprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, ...)
{
  sint32_t v_Result_s32;
  va_list v_Argptr_t;
  va_start(v_Argptr_t, i_Format_pc);

  v_Result_s32 = vsnprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Argptr_t);

  va_end(v_Argptr_t);

  return v_Result_s32;
}

sint32_t ME_String_Vsnprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, va_list i_Argptr_t)
{
  return vsnprintf(i_Buffer_pc, i_Count_t, i_Format_pc, i_Argptr_t);
}

sint32_t ME_String_Snwprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, ...)
{
  sint32_t result;

  va_list v_Argptr_t;
  va_start(v_Argptr_t, i_Format_pc);

  result = vswprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Argptr_t);

  va_end(v_Argptr_t);

  return result;
}

sint32_t ME_String_Vsnwprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, va_list i_Argptr_t)
{
  return vswprintf(i_Buffer_pc, i_Count_t, i_Format_pc, i_Argptr_t);
}

char_t*  ME_String_StrStr_pc(const char_t* i_Buffer_pc, const char_t* i_SearchString_pc)
{
  return strstr(i_Buffer_pc, i_SearchString_pc);
}

sint32_t ME_String_Stricmp_s32(const char_t* i_String1_pc, const char_t* i_String2_pc)
{
  return strcasecmp(i_String1_pc, i_String2_pc);
}

sint32_t ME_String_Wcsicmp_s32(const wchar_t* i_String1_pc, const wchar_t* i_String2_pc)
{
  return wcscmp(i_String1_pc, i_String2_pc);
}

// Conversion functions
bool_t ME_String_Itoa_b(sint32_t i_Value_s32, char_t* o_Buffer_pc, sint32_t i_Radix_s32)
{
  return (NULL != itoa(i_Value_s32, o_Buffer_pc, i_Radix_s32));
}

sint32_t ME_String_Atoi_s32(const char_t* i_String_pc)
{
  sint32_t v_Result_s32 = 0;

  if (NULL != i_String_pc)
  {
    // PRQA S 5125 1 // using this until own implementation is implemented
    v_Result_s32 = atoi(i_String_pc);
  }

  return v_Result_s32;
}

sint64_t ME_String_Atoi64_s64(const char_t* i_String_pc)
{
  sint64_t v_Result_s64 = 0;

  if (NULL != i_String_pc)
  {
    // PRQA S 5125 1 // using this until own implementation is implemented
    v_Result_s64 = (sint64_t)atoll(i_String_pc);
  }

  return v_Result_s64;
}

float32_t ME_String_Atof_f32(const char_t* i_String_pc)
{
  float32_t v_Result_f32 = 0.0F;

  if (NULL != i_String_pc)
  {
    // PRQA S 5125 1 // using this until own implementation is implemented
    v_Result_f32 = (float32_t) atof(i_String_pc);
  }

  return v_Result_f32;
}

sint32_t ME_String_Wtoi_s32(const wchar_t* i_String_pc)
{
  return wcstol(i_String_pc, NULL, 10);
}

sint64_t ME_String_Wtoi64_s64(const wchar_t* i_String_pc)
{
  return (sint64_t)wcstoll(i_String_pc, NULL, 10);
}

float32_t ME_String_Wtof_f32(const wchar_t* i_String_pc)
{
  return (float32_t) wcstof(i_String_pc, NULL);
}

// TODO: check why iconv doesn't work here
#if 0
sint32_t ME_String_WideCharToMultiByte_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32)
{
  char_t* v_InputBuffer_pc  = (char_t*) i_SrcString_pc;
  char_t* v_OutputBuffer_pc = (char_t*) o_DestString_pc;

  size_t v_InputLength_t    = (size_t) i_SizeInChars_s32 * sizeof(wchar_t);
  size_t v_OutputLength_t   = (size_t) i_SizeInBytes_s32;

  sint32_t v_Count_s32      = 0;
  sint32_t v_CharCount_s32  = i_SizeInChars_s32;
  sint32_t v_Result_s32     = 0;

  if (o_DestString_pc == 0 || i_SizeInBytes_s32 == 0)
  {
    if (v_CharCount_s32 < 0)
    {
      v_CharCount_s32 = ME_String_CountCharactersW_s32(i_SrcString_pc);
    }

    for (sint32_t i = 0; i < v_CharCount_s32; i++)
    {
      if (i_SrcString_pc[i] <= 0x7F)
      {
        v_Count_s32++;
      }
      else if (i_SrcString_pc[i] <= 0x7FF)
      {
        v_Count_s32 += 2;
      }
      else
      {
        v_Count_s32 += 3;
      }
    }

    if (i_SizeInChars_s32 < 0)
    {
      // add null termination to count
      v_Count_s32++;
    }

    v_Result_s32 = v_Count_s32;
  }
  else
  {
    if (i_SizeInChars_s32 < 0)
    {
      // determine input length by myself. Precondition: null terminated string.
      i_SizeInChars_s32 = ME_String_CountCharactersW_s32(i_SrcString_pc) + 1; // adding terminating null
    }

    if (i_SizeInChars_s32 == 0)
    {
      v_Result_s32 = 0;
    }

    setlocale(LC_CTYPE, ""); //set locale LC_CTYPE to system default("") to prevent iconv() error EILSEQ

    // Convert from UCS-2 / UCS-4 to UTF-8
    iconv_t v_Descriptor_t = iconv_open("UTF-8", "WCHAR_T");

    if (v_Descriptor_t != (iconv_t) -1)
    {
      v_Result_s32 = iconv(v_Descriptor_t, &v_InputBuffer_pc, &v_InputLength_t, &v_OutputBuffer_pc, &v_OutputLength_t);

      if (v_Result_s32 == (size_t) -1)
      {
        if (errno == EILSEQ)
        {
          ME_Debugger_F_Printf_v("An invalid multibyte sequence is encountered in the input");
        }
        else if (errno == EINVAL)
        {
          ME_Debugger_F_Printf_v("An incomplete multibyte sequence is encountered in the input, and the input byte sequence terminates after it.");
        }
        else if (errno == E2BIG)
        {
          ME_Debugger_F_Printf_v("The output buffer has no more room for the next converted character");
        }

        v_Result_s32 = 0;
      }
      else
      {
        // calculate the count of _bytes_ written to pDestString
        v_Result_s32 = i_SizeInBytes_s32 - v_OutputLength_t;
      }

      iconv_close(v_Descriptor_t);
    }
  }

  return v_Result_s32;
}

sint32_t ME_String_MultiByteToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32)
{
  char_t* v_InputBuffer_pc  = (char_t*) i_SrcString_pc;
  char_t* v_OutputBuffer_pc = (char_t*) o_DestString_pc;

  size_t v_InputLength_t    = (size_t) i_SizeInBytes_s32;
  size_t v_OutputLength_t   = (size_t) i_SizeInChars_s32 * sizeof(wchar_t);

  sint32_t v_Result_s32     = 0;

  if (o_DestString_pc == 0 || i_SizeInChars_s32 == 0)
  {
    v_Result_s32 = ME_String_CountCharacters_s32(i_SrcString_pc) + 1; // plus 1 for null termination
  }
  else
  {
    if (i_SizeInBytes_s32 < 0)
    {
      // determine input length by myself. Precondition: null terminated string.
      i_SizeInBytes_s32 = ME_String_CountBytes_s32(i_SrcString_pc) + 1; // include terminating null
    }

    // Convert from UTF-8 to UCS-2 / UCS-4
    iconv_t v_Descriptor_t = iconv_open("WCHAR_T", "UTF-8");

    if (v_Descriptor_t != (iconv_t) -1)
    {
      v_Result_s32 = iconv(v_Descriptor_t, &v_InputBuffer_pc, &v_InputLength_t, &v_OutputBuffer_pc, &v_OutputLength_t);

      if (v_Result_s32 == (size_t) -1)
      {
        v_Result_s32 = 0;
      }
      else if (v_OutputLength_t > 0)
      {
        v_Result_s32 = i_SizeInChars_s32 - (v_OutputLength_t / sizeof(wchar_t));
      }

      iconv_close(v_Descriptor_t);
    }
  }

  return v_Result_s32;
}

sint32_t ME_String_WideCharToUTF16_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32)
{
  char_t* v_InputBuffer_pc  = (char_t*) i_SrcString_pc;
  char_t* v_OutputBuffer_pc = (char_t*) o_DestString_pc;

  size_t v_InputLength_t    = (size_t) i_SizeInChars_s32 * sizeof(wchar_t);
  size_t v_OutputLength_t   = (size_t) i_SizeInBytes_s32;

  sint32_t v_Count_s32      = 0;
  sint32_t v_CharCount_s32  = i_SizeInChars_s32;
  sint32_t v_Result_s32     = 0;

  if (o_DestString_pc == 0 || i_SizeInBytes_s32 == 0)
  {
    if (v_CharCount_s32 < 0)
    {
      v_CharCount_s32 = ME_String_CountCharactersW_s32(i_SrcString_pc);
    }

    for (sint32_t i = 0; i < v_CharCount_s32; i++)
    {
      if (i_SrcString_pc[i] <= 0x7F)
      {
        v_Count_s32++;
      }
      else if (i_SrcString_pc[i] <= 0x7FF)
      {
        v_Count_s32 += 2;
      }
      else
      {
        v_Count_s32 += 3;
      }
    }

    if (i_SizeInChars_s32 < 0)
    {
      // add null termination to count
      v_Count_s32++;
    }

    v_Result_s32 = v_Count_s32;
  }
  else
  {

    if (i_SizeInChars_s32 < 0)
    {
      // determine input length by myself. Precondition: null terminated string.
      i_SizeInChars_s32 = ME_String_CountCharactersW_s32(i_SrcString_pc) + 1; // adding terminating null
    }

    if (i_SizeInChars_s32 == 0)
    {
      v_Result_s32 = 0;
    }
    else
    {
      setlocale(LC_CTYPE, ""); //set locale LC_CTYPE to system default("") to prevent iconv() error EILSEQ

      // Convert from UCS-2 / UCS-4 to UTF-8
      iconv_t v_Descriptor_t = iconv_open("UTF-16LE", "WCHAR_T");

      if (v_Descriptor_t != (iconv_t) -1)
      {
        v_Result_s32 = iconv(v_Descriptor_t, &v_InputBuffer_pc, &v_InputLength_t, &v_OutputBuffer_pc, &v_OutputLength_t);

        if (v_Result_s32 == (size_t) -1)
        {
          if (errno == EILSEQ)
          {
            ME_Debugger_F_Printf_v("An invalid multibyte sequence is encountered in the input");
          }
          else if (errno == EINVAL)
          {
            ME_Debugger_F_Printf_v("An incomplete multibyte sequence is encountered in the input, and the input byte sequence terminates after it.");
          }
          else if (errno == E2BIG)
          {
            ME_Debugger_F_Printf_v("The output buffer has no more room for the next converted character");
          }

          v_Result_s32 = 0;
        }
        else
        {
          // calculate the count of _bytes_ written to pDestString
          v_Result_s32 = i_SizeInBytes_s32 - v_OutputLength_t;
        }

        iconv_close(v_Descriptor_t);
      }
    }
  }


  return v_Result_s32;
}

sint32_t ME_String_UTF16ToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32)
{
  char_t* pInputBuffer  = (char_t*) i_SrcString_pc;
  char_t* pOutputBuffer = (char_t*) o_DestString_pc;

  size_t inputLength    = (size_t) i_SizeInBytes_s32;
  size_t outputLength   = (size_t) i_SizeInChars_s32 * sizeof(wchar_t);

  sint32_t v_Result_s32 = 0;

  if (o_DestString_pc == 0 || i_SizeInChars_s32 == 0)
  {
    v_Result_s32 = ME_String_CountCharacters_s32(i_SrcString_pc) + 1; // plus 1 for null termination
  }
  else
  {
    if (i_SizeInBytes_s32 < 0)
    {
      // determine input length by myself. Precondition: null terminated string.
      i_SizeInBytes_s32 = ME_String_CountBytes_s32(i_SrcString_pc) + 1; // include terminating null
    }

    // Convert from UTF-8 to UCS-2 / UCS-4
    iconv_t descriptor = iconv_open("WCHAR_T", "UTF-16LE");

    if (descriptor != (iconv_t) -1)
    {
      v_Result_s32 = iconv(descriptor, &pInputBuffer, &inputLength, &pOutputBuffer, &outputLength);

      if (v_Result_s32 == (size_t) -1)
      {
        v_Result_s32 = 0;
      }
      else if (outputLength > 0)
      {
        v_Result_s32 = i_SizeInChars_s32 - (outputLength / sizeof(wchar_t));
      }

      iconv_close(descriptor);
    }
  }

  return v_Result_s32;
}
#endif

// PRQA S 3344 EOF // Controlling expression is a Boolean expression for strings
// PRQA S 0489 EOF // The integer value 1 is being added or subtracted from a pointer is intended here
// PRQA S 3440 EOF // Using the value resulting from a ++ or -- operation is ok in this case

sint32_t ME_String_CountCharacters_s32(const char_t* i_String_pc)
{
  sint32_t v_Count_s32 = 0;

  if (NULL != i_String_pc)
  {
    while (*i_String_pc)
    {
      // Count all character start bytes
      // PRQA S 4105 1 // used to increase character count here, so it's ok
      v_Count_s32 += (*i_String_pc++ & 0xc0) != 0x80;
    }
  }

  return v_Count_s32;
}

sint32_t ME_String_CountCharactersW_s32(const wchar_t* i_WString_pc)
{
  sint32_t v_Count_s32 = 0;

  if (NULL != i_WString_pc)
  {
    while (*i_WString_pc++)
    {
      ++i_WString_pc;
    }
  }

  return v_Count_s32;
}

sint32_t ME_String_CountBytes_s32(const char_t* i_String_pc)
{
  sint32_t v_Count_s32 = 0;

  if (NULL != i_String_pc)
  {
    while (*i_String_pc++)
    {
      ++v_Count_s32;
    }
  }

  return v_Count_s32;
}

sint32_t ME_String_CountBytesW_s32(const wchar_t* i_WString_pc)
{
  sint32_t v_Count_s32 = 0;

  if (NULL != i_WString_pc)
  {
    while (*i_WString_pc++)
    {
      v_Count_s32 += (sint32_t)sizeof(wchar_t);
    }
  }

  return v_Count_s32;
}

#endif // ME_PLATFORM_QNX

