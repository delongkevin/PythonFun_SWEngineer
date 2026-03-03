#include "StringUtils.h"

namespace tsdk
{



  StringUtils::StringUtils()
  {

  }

  StringUtils::~StringUtils()
  {

  }

  std::string StringUtils::getFileNameNoExt_o(const std::string& i_FileName_ro)
  {
    return getFileName_o(removeExtension_o(i_FileName_ro));
  }

  std::string StringUtils::getFileName_o(const std::string& i_FileName_ro)
  {
    size_t pos = i_FileName_ro.find_last_of("\\/");
    return (std::string::npos == pos) ? i_FileName_ro : i_FileName_ro.substr(pos + 1, i_FileName_ro.length());
  }

  std::string StringUtils::getBasePath_o(const std::string& i_FileName_ro)
  {
    size_t pos = i_FileName_ro.find_last_of("\\/");
    return (std::string::npos == pos) ? "" : i_FileName_ro.substr(0, pos + 1);
  }

  std::string StringUtils::removeExtension_o(const std::string& i_FileName_ro)
  {
    size_t pos = i_FileName_ro.find_last_of(".");
    return (std::string::npos == pos) ? i_FileName_ro : i_FileName_ro.substr(0, pos);
  }

  std::string StringUtils::getExtension_o(const std::string& i_FileName_ro)
  {
    std::string extension = "";

    std::string::size_type idx = i_FileName_ro.rfind('.');
    if(idx != std::string::npos)
    {
      extension = i_FileName_ro.substr(idx+1);
    }
    else
    {
      // No extension found
      extension = "";
    }

    return extension;
  }

  std::string StringUtils::replaceString_o(std::string i_Str_o, std::string& i_Pattern_ro, const std::string i_Replacement_o)
  {
    std::string::size_type pos = i_Str_o.find(i_Pattern_ro, 0);

    while (std::string::npos != pos) 
    {
      i_Str_o.replace(pos, i_Pattern_ro.length(), i_Replacement_o);
      pos = i_Str_o.find(i_Pattern_ro, 0);
    }

    return i_Str_o;
  }

} // namespace tsdk