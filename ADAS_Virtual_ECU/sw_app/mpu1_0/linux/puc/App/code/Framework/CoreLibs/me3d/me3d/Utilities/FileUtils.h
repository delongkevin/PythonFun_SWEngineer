#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include "MeclTypeDefs.h"

namespace me3d
{
  class FileUtils
  {
  public:
    // Returns the extension from the input string
    static MEString getExtension_o(const MEString& i_String_ro);
    static MEString getFileName_o(const MEString& i_String_ro, bool i_NoExtension_b, char i_PathSeparator_c);

  };

} // namespace me3d

#endif
