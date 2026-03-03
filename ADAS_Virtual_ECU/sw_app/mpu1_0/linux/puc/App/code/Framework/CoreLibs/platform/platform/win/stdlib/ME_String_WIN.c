
// Compile this file for windows only
#include "platform/PlatformSpecs.h"
#ifdef ME_PLATFORM_WIN

#include "platform/stdlib/ME_String.h"

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

#include "platform/win/WinInclude.h"

#include <wingdi.h>

#pragma warning(disable: 4996)    //Disable warning: This function or variable may be unsafe. Consider using...

sint32_t ME_String_Scanf_s32(const char_t* i_Format_pc, ...)
{
  va_list v_Argptr_t;
  sint32_t v_Result_s32;
  va_start(v_Argptr_t, i_Format_pc);
  v_Result_s32 = ME_String_Vscanf_s32(i_Format_pc, v_Argptr_t);

  va_end(v_Argptr_t);

  return v_Result_s32;
}

sint32_t ME_String_Vscanf_s32(const char_t* i_Format_pc, va_list argptr)
{
  // implementing vscanf because it's missing in Microsoft C-library
  char_t* v_Nformat_pc = _strdup(i_Format_pc);
  char_t* v_Format_pc = v_Nformat_pc;
  sint32_t v_Num_s32 = 0;
  sint32_t v_Convtot_s32 = 0;
  sint32_t v_i_s32;
  void* v_Args_pv;
  sint32_t v_Lu_s32;  
  sint32_t v_Conv_v;
  
  for (v_i_s32 = 0; v_Format_pc[v_i_s32]; v_i_s32++)
  {
    if (v_Format_pc[v_i_s32] == '%')
    {
      if (v_Format_pc[v_i_s32 + 1] == '%' || v_Format_pc[v_i_s32 + 1] == '*' || v_Format_pc[v_i_s32 + 1] == '\0')
      {
        v_i_s32++;
      }
      else
      {
        if (v_Num_s32 == 0)
        {
          v_Num_s32++;
        }
        else
        {
          char f[3];

          f[1] = v_Format_pc[v_i_s32 + 1];
          f[2] = v_Format_pc[v_i_s32 + 2];

          v_Format_pc[v_i_s32 + 1] = 'n';
          v_Format_pc[v_i_s32 + 2] = '\0';

          v_Args_pv  = va_arg(argptr, void*);
          v_Lu_s32   = -1;

          v_Conv_v = scanf(v_Format_pc, v_Args_pv, &v_Lu_s32);

          if (v_Lu_s32 == -1)
          {
            v_Convtot_s32 += v_Conv_v;
            break;
          }

          v_Convtot_s32++;

          v_Format_pc[v_i_s32+1]=f[1];
          v_Format_pc[v_i_s32+2]=f[2];
          v_Format_pc += v_i_s32;
          v_i_s32 = -1;
          v_Num_s32 = 0;
        }
      }
    }
  }

  if (v_Format_pc[v_i_s32] == '\0' && v_Num_s32 > 0)
  {
    void* p = va_arg(argptr, void*);

    v_Conv_v = scanf(v_Format_pc, p);

    v_Convtot_s32 += v_Conv_v;
  }

  free(v_Nformat_pc);

  return v_Convtot_s32;
}

sint32_t ME_String_Printf_s32(const char_t* i_Format_pc, ...)
{
  va_list v_Arguments_pc;
  sint32_t v_Result_s32;
  va_start(v_Arguments_pc, i_Format_pc);

  v_Result_s32 = _vprintf_s_l(i_Format_pc, NULL, v_Arguments_pc);

  va_end(v_Arguments_pc);

  return v_Result_s32;
}

sint32_t ME_String_Sprintf_s32(char_t* i_String_pc, const char_t* i_Format_pc, ...)
{
  va_list arg_ptr;   
  sint32_t v_Erg_s32 = 0;
                                                                                
   va_start(arg_ptr, i_Format_pc);                                                      
   v_Erg_s32 = vsprintf(i_String_pc, i_Format_pc, arg_ptr);                                              
   va_end(arg_ptr); 
  return v_Erg_s32;
}

sint32_t ME_String_Swprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, ...)
{
  va_list v_Arguments_pc;
  sint32_t v_Result_s32;
  va_start(v_Arguments_pc, i_Format_pc);

  v_Result_s32 = vswprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Arguments_pc);

  va_end(v_Arguments_pc);

  return v_Result_s32;
}

// -- copy / concatenation ---
void ME_String_Wcsncpy_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t)
{
  wcsncpy_s(o_StrDest_pc, i_SizeInWords_t, i_StrSource_pc, i_Count_t);
}

void ME_String_Strncat_v(char_t* o_StrDest_pc, size_t i_SizeInBytes_t, const char_t* i_StrSource_pc, size_t i_Count_t)
{
  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  strncat_s(o_StrDest_pc, i_SizeInBytes_t, i_StrSource_pc, i_Count_t);
}

void ME_String_Wcsncat_v(wchar_t* o_StrDest_pc, size_t i_SizeInWords_t, const wchar_t* i_StrSource_pc, size_t i_Count_t)
{
  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  wcsncat_s(o_StrDest_pc, i_SizeInWords_t, i_StrSource_pc, i_Count_t);
}

void ME_String_Strcpy_v(char_t* o_StrDest_pc, const char_t* pSource)
{
  strcpy(o_StrDest_pc, pSource);
}

void ME_String_Strncpy_v(char_t* o_StrDest_pc, size_t sizeInBytes, const char_t* pSource, size_t count)
{
  strncpy_s(o_StrDest_pc, sizeInBytes, pSource, count);
}


sint32_t ME_String_Vsprintf_s32(char_t* i_Buffer_pc, const char_t* i_Format_pc, va_list i_Argptr_t)
{
  return vsprintf(i_Buffer_pc, i_Format_pc, i_Argptr_t);
}

sint32_t ME_String_Vswprintf_s32(wchar_t* i_Buffer_pc, size_t i_SizeInWords_t, const wchar_t* i_Format_pc, va_list i_Argptr_t)
{
  return vswprintf_s(i_Buffer_pc, i_SizeInWords_t, i_Format_pc, i_Argptr_t);
}

sint32_t ME_String_Snprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, ...)
{
  va_list v_Argptr_pc;
  sint32_t v_Result_s32;
  va_start(v_Argptr_pc, i_Format_pc);

  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  v_Result_s32 = _vsnprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Argptr_pc);

  va_end(v_Argptr_pc);

  return v_Result_s32;
}

sint32_t ME_String_Vsnprintf_s32(char_t* i_Buffer_pc, size_t i_Count_t, const char_t* i_Format_pc, va_list i_Argptr_t)
{
  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  return _vsnprintf(i_Buffer_pc, i_Count_t, i_Format_pc, i_Argptr_t);
}

sint32_t ME_String_Snwprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, ...)
{
  va_list v_Argptr_pc;
  sint32_t v_Result_s32;
  va_start(v_Argptr_pc, i_Format_pc);

  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  v_Result_s32 = _vsnwprintf(i_Buffer_pc, i_Count_t, i_Format_pc, v_Argptr_pc);

  va_end(v_Argptr_pc);

  return v_Result_s32;
}

sint32_t ME_String_Vsnwprintf_s32(wchar_t* i_Buffer_pc, size_t i_Count_t, const wchar_t* i_Format_pc, va_list i_Argptr_t)
{
  if (i_Count_t == -1)
  {
    i_Count_t = _TRUNCATE;
  }

  return _vsnwprintf(i_Buffer_pc, i_Count_t, i_Format_pc, i_Argptr_t);
}

char_t* ME_String_StrStr_pc(const char_t* i_Buffer_pc, const char_t* i_SearchString_pc)
{
  return strstr((char_t*)i_Buffer_pc, i_SearchString_pc);
}

// --- Compare (wide) Strings ---
sint32_t ME_String_Stricmp_s32(const char_t* i_String1_pc, const char_t* i_String2_pc)
{
  return _stricmp(i_String1_pc, i_String2_pc);
}

sint32_t ME_String_Wcsicmp_s32(const wchar_t* i_String1_pc, const wchar_t* i_String2_pc)
{
  return _wcsicmp(i_String1_pc, i_String2_pc);
}

bool_t ME_String_Itoa_b(sint32_t i_Value_s32, char_t* o_Buffer_pc, sint32_t i_Radix_s32)
{
  bool_t v_Ret_b;

  if (_itoa(i_Value_s32, o_Buffer_pc, i_Radix_s32) == 0)
  {
    v_Ret_b = true;
  }
  else
  {
    v_Ret_b = false;
  }

  return v_Ret_b;
}

sint32_t ME_String_Atoi_s32(const char_t* i_String_pc)
{
  return atoi(i_String_pc);
}

sint64_t ME_String_Atoi64_s64(const char_t* i_String_pc)
{
  return _atoi64(i_String_pc);
}

float32_t ME_String_Atof_f32(const char_t* i_String_pc)
{
  return (float32_t)atof(i_String_pc);
}

sint32_t ME_String_Wtoi_s32(const wchar_t* i_String_pc)
{
  return _wtoi(i_String_pc);
}

sint64_t ME_String_Wtoi64_s64(const wchar_t* i_String_pc)
{
  return _wtoi64(i_String_pc);
}

float32_t ME_String_Wtof_f32(const wchar_t* i_String_pc)
{
  return (float32_t)_wtof(i_String_pc);
}

sint32_t ME_String_WideCharToMultiByte_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32)
{
  return WideCharToMultiByte(CP_UTF8, 0, i_SrcString_pc, i_SizeInChars_s32, o_DestString_pc, i_SizeInBytes_s32, 0, 0);
}

sint32_t ME_String_MultiByteToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32)
{
  return MultiByteToWideChar(CP_UTF8, 0, i_SrcString_pc, i_SizeInBytes_s32, o_DestString_pc, i_SizeInChars_s32);
}

sint32_t ME_String_WideCharToUTF16_s32(const wchar_t* i_SrcString_pc, sint32_t i_SizeInChars_s32, char_t* o_DestString_pc, sint32_t i_SizeInBytes_s32)
{
  memcpy(o_DestString_pc, (char*)i_SrcString_pc, (size_t)i_SizeInBytes_s32);

  return 1;
}

sint32_t ME_String_UTF16ToWideChar_s32(const char_t* i_SrcString_pc, sint32_t i_SizeInBytes_s32, wchar_t* o_DestString_pc, sint32_t i_SizeInChars_s32)
{
  memcpy(o_DestString_pc, (char*)i_SrcString_pc, (size_t)i_SizeInBytes_s32);

  return 1;
}

// --- Count functions ---
sint32_t ME_String_CountCharacters_s32(const char_t* i_String_pc)
{
  sint32_t v_Len_s32 = 0;

  while (*i_String_pc)
  {
    // Count all character start bytes
    v_Len_s32 += (*i_String_pc++ & 0xc0) != 0x80;
  }

  return v_Len_s32;
}

sint32_t ME_String_CountCharactersW_s32(const wchar_t* i_WString_pc)
{
  sint32_t v_Len_s32 = 0;

  while (*i_WString_pc++)
  {
    ++v_Len_s32;
  }

  return v_Len_s32;
}

sint32_t ME_String_CountBytes_s32(const char_t* i_String_pc)
{
  sint32_t v_Len_s32 = 0;

  while (*i_String_pc++)
  {
    ++v_Len_s32;
  }

  return v_Len_s32;
}

sint32_t ME_String_CountBytesW_s32(const wchar_t* i_WString_pc)
{
  sint32_t v_Len_s32 = 0;

  while (*i_WString_pc++)
  {
    v_Len_s32 += sizeof(wchar_t);
  }

  return v_Len_s32;
}


#endif // ME_PLATFORM_WIN // PRQA S 862 // this define decides which platform is defined
