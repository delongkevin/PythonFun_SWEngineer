//--------------------------------------------------------------------------
/// @file Path.h
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

#ifndef PATH_H
#define PATH_H

#include "String.h"

namespace osal
{

class Path
{
private:

  static const char_t*    workingDir_o;                ///< Current working directory

  String                  absolutePath_o;              ///< Absolute path
  String                  relativePath_o;              ///< Relative (to the working directory) path of the input path
  String                  fileName_o;                  ///< Only the file name of the input path
  String                  extension_o;                 ///< Only the extension of the file of the input path

public:

  Path();
  explicit Path(const String& i_Path_ro);

  /// Returns true if the path is absolute, not relative
  static bool_t IsAbsolutePath_b(const String& i_Path_ro);

  /// Returns true if the path is relative, not absolute
  static bool_t IsRelativePath_b(const String& i_Path_ro);

  /// Returns false if the path is not relative and not absolute
  static bool_t IsValidPath_b(const String& i_Path_ro);

  /// Returns false if the path is not existing
  static bool_t Exists_b(const String& i_Path_ro);

  /// Returns false if the path is not existing
  static bool_t Exists_b(const Path& i_Path_ro);

  /// Returns true, if the path was successfully created
  static bool_t Create_b(const String& i_Path_ro);

  /// Returns true, if the path was successfully created
  static bool_t Create_b(const Path& i_Path_ro);

  /// Add a backslash at the end (if not already exist)
  static void AppendBackslash_v(String& i_Path_ro);

  /// Change the type of slashes to make the path valid
  static void MakeValidPath_v(String& b_Path_ro);

  /// Removes redundant slashes and resolves '.' and '..' in the path
  static String ResolvePath_o(const String& i_Path_ro, char_t i_PathSeperator_c);

  /// Returns the project (platform) working directory
  static String getWorkingDirectory();

  /// Set a new path
  void SetPath_v(const String& i_Path_ro);

  /// Returns the relative path of the current path
  String GetRelativePath_o() const;

  /// Returns the absolute path of the current path
  String GetAbsolutePath_o() const;

};

}; // namespace mepl


#endif // PATH_H
