#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>

namespace tsdk
{


class StringUtils
{
public:
  StringUtils();
  ~StringUtils();
  
  static std::string getFileNameNoExt_o(const std::string& i_FileName_ro);
  static std::string getFileName_o(const std::string& i_FileName_ro);
  static std::string getBasePath_o(const std::string& i_FileName_ro);
  static std::string removeExtension_o(const std::string& i_FileName_ro);
  static std::string getExtension_o(const std::string& i_FileName_ro);
  static std::string replaceString_o(std::string i_Str_o, std::string& i_Pattern_ro, const std::string i_Replacement_o);

};

} // namespace tsdk

#endif
