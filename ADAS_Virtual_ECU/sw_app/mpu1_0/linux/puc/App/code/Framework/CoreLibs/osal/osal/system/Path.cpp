//--------------------------------------------------------------------------
/// @file Path.cpp
/// @brief Contains the implementation to platform independent specific directory and path control functions
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@magna.com)
///
//  --------------------------------------------------------------------------

#include "Path.h"

#include "platform/stdlib/ME_Directory.h"

//PRQA S 1021 EOF // to be consistent in the platform header files we want to keep ME_PATH_SEPERATOR and ME_WORKING_DIR as a define
//PRQA S 4243 EOF // STL design
//PRQA S 4244 EOF // STL design

namespace osal
{

// doesn't work with String-class, because TLSF isn't initialized yet
const char_t* Path::workingDir_o = ME_WORKING_DIR;

Path::Path()
  : absolutePath_o()
  , relativePath_o()
  , fileName_o()
  , extension_o()
{
}

Path::Path(const String& i_Path_ro)
  : absolutePath_o()
  , relativePath_o()
  , fileName_o()
  , extension_o()
{
  SetPath_v(i_Path_ro);
}

void Path::SetPath_v(const String& i_Path_ro)
{
  relativePath_o = i_Path_ro;

  // create absolute path
  absolutePath_o = String(workingDir_o) + ME_PATH_SEPARATOR + relativePath_o;
}

String Path::GetRelativePath_o() const
{
  return relativePath_o;
}

String Path::GetAbsolutePath_o() const
{
  return absolutePath_o;
}

String Path::ResolvePath_o(const String& i_Path_ro, char_t i_PathSeperator_c)
{
  String tmp;
  // scan the path only if there are some "."s or ".."s in the path
  if ((i_Path_ro.find_u32(String("/..")) != String::c_Npos_u32) && (i_Path_ro.find_u32(String("/.")) != String::c_Npos_u32))
  {
    tmp = i_Path_ro;
  }
  else
  {
    // split path by path separators and throw away all "."s
    typedef std::vector<String> TokenList_t;
    TokenList_t tokenList;
    uint32_t pos = 0;
    while (pos != String::c_Npos_u32)
    {
      String token = i_Path_ro.tokenize_o(ME_PATH_SEPARATOR, pos);
      if ((!token.isEmpty_b()) && ((token == ".") == false))
      {
        tokenList.push_back(token);
      }
    }

    // remove all occurrences of patterns like "/a/../"
    TokenList_t::iterator tokenIt = tokenList.begin();
    TokenList_t::iterator previousTokenIt = tokenList.end();

    while (tokenIt != tokenList.end())
    {
      if ( ( (*tokenIt) == "..")  && ( previousTokenIt != tokenList.end() ) && !((*previousTokenIt) == "..") )
      {
        *tokenIt = String("");
        *previousTokenIt = String("");

        if (tokenIt == tokenList.begin())
        {
          previousTokenIt = tokenList.end();
        }
        else
        {
          previousTokenIt = tokenIt;
          --previousTokenIt;
        }
      }
      else
      {
        previousTokenIt = tokenIt;
        ++tokenIt;
      }
    }

    // build path based on remaining tokens
    const uint32_t v_ListSize_u32 = tokenList.size();
    for(uint32_t v_idx_u32 = 0; v_idx_u32 < v_ListSize_u32; v_idx_u32++)
    {
      if(tokenList.at(v_idx_u32).getLength_u32() == 0)
      {
        tmp += i_PathSeperator_c;
      }
      tmp += tokenList.at(v_idx_u32); // necessary here
    }
  }

  return tmp;
}

bool_t Path::IsAbsolutePath_b(const String& i_Path_ro)
{
  return ME_Directory_IsAbsolutePath_b(i_Path_ro.getString_pc(), static_cast<uint32_t>(i_Path_ro.getLength_u32()));
}

bool Path::IsRelativePath_b(const String& i_Path_ro)
{
  return ME_Directory_IsRelativePath_b(i_Path_ro.getString_pc(), static_cast<uint32_t>(i_Path_ro.getLength_u32()));
}

bool_t Path::Exists_b(const String& i_Path_ro)
{
  return ME_Directory_Exists_b(i_Path_ro.getString_pc());
}

bool_t Path::Exists_b(const Path& i_Path_ro)
{
  return Exists_b(i_Path_ro.GetAbsolutePath_o());
}

bool_t Path::Create_b(const String& i_Path_ro)
{
  bool_t v_Result_b = false;
  mepl::vector<osal::String>::iterator it;
  mepl::vector<osal::String> v_DirTokenList_o;
  osal::String v_tmpPath_o;

  i_Path_ro.tokenize_o(ME_PATH_SEPARATOR, v_DirTokenList_o);

  if(i_Path_ro.getAt_c(0) == ME_PATH_SEPARATOR)
  {
    v_tmpPath_o = ME_PATH_SEPARATOR;
  }

  uint32_t v_ListSize_u32 = v_DirTokenList_o.size();
  for(uint32_t v_idx_u32 = 0; v_idx_u32 < v_ListSize_u32; v_idx_u32++)
  {
    v_tmpPath_o = v_tmpPath_o + v_DirTokenList_o.at(v_idx_u32) + ME_PATH_SEPARATOR;
    if(false == ME_Directory_Exists_b(v_tmpPath_o.getString_pc()))
    {
      v_Result_b = ME_Directory_Create_b(v_tmpPath_o.getString_pc());
    }
  }

  return v_Result_b;
}

bool_t Path::Create_b(const Path& i_Path_ro)
{
  return Create_b(i_Path_ro.GetAbsolutePath_o());
}

bool_t Path::IsValidPath_b(const String& i_Path_ro)
{
  bool_t v_Result_b = true;

  if(i_Path_ro.getSize_t() == 0)
  {
    v_Result_b = true;
  }
  else
  {
    // Check for invalid path separators
    for(uint32_t v_idx_u32 = 0; v_idx_u32 < i_Path_ro.getSize_t(); v_idx_u32++)
    {
      if(i_Path_ro.getAt_c(v_idx_u32) == ME_INVALID_PATH_SEPARATOR)
      {
        v_Result_b = false;
      }
    }
  
    // Only allow paths like
    // "/a/ab/abc"
    // "./a/ab/abc"
    // "../a/ab/abc"
    if(i_Path_ro.getAt_c(0) != ME_PATH_SEPARATOR)
    {
      if(i_Path_ro.getSize_t() == 1)
      {
        v_Result_b = false;
      }

      if((i_Path_ro.getSize_t() == 2) && (i_Path_ro.getAt_c(0) == '.'))
      {
        if(i_Path_ro.getAt_c(1) != ME_PATH_SEPARATOR)
        {
          v_Result_b = false;
        }
      }
      else if((i_Path_ro.getSize_t() >= 3) && (i_Path_ro.getAt_c(0) == '.') && (i_Path_ro.getAt_c(1) == '.'))
      {
        if(i_Path_ro.getAt_c(2) != ME_PATH_SEPARATOR)
        {
          v_Result_b = false;
        }
      }
      else
      {
        v_Result_b = false;
      }
    }
  }
#if 0
  if (!IsAbsolutePath_b(i_Path_ro) && !IsRelativePath_b(i_Path_ro))
  {
    v_Result_b = false;
  }
#endif
  return v_Result_b;
}

void Path::AppendBackslash_v(String& i_Path_ro)
{
  uint32_t Length = i_Path_ro.getLength_u32();

  if (Length > 0)
  {
    if (i_Path_ro.getAt_c(Length - 1) != ME_PATH_SEPARATOR)
    {
      i_Path_ro += ME_PATH_SEPARATOR;
    }
  }
}

void Path::MakeValidPath_v(String& b_Path_ro)
{
  uint32_t v_idx_u32 = 0;
  
  for (v_idx_u32 = 0; v_idx_u32 < b_Path_ro.getSize_t(); ++v_idx_u32)
  {
    if (b_Path_ro.getAt_c(v_idx_u32) == L'\\')
    {
      // replace backslashes
      b_Path_ro.setAt_v(v_idx_u32, ME_PATH_SEPARATOR);
    }
  }
}

String Path::getWorkingDirectory()
{
  return String(workingDir_o);
}

}; // namespace osal
