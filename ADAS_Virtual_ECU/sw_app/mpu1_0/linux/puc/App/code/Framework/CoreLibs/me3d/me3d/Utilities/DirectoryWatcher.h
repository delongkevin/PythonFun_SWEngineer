//--------------------------------------------------------------------------                                                                                                           
/// @file Directory Watcher.h                                                                         
/// @brief Caution: Windows Only. Watches directories in a background thread and report changed files.
/// --------------------------------------------------------------------------              
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>                             
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,                 
/// disseminated or distributed to parties outside MAGNA Electronics                        
/// without written permission from MAGNA Electronics.                                      
///                                                                                         
/// @author Mark Reichert (Mark.Reichert2@magna.com)                                     
///                                                                                         
//  -------------------------------------------------------------------------- 

#ifndef DIRECTORY_WATCHER_H
#define DIRECTORY_WATCHER_H

#include "RenderEngineCfg.h"


#ifdef USE_DIRECTORY_WATCHER


#include <Windows.h>
#include <winnt.h>
#include <concrt.h>
#include <vector>

namespace me3d
{

class DirectoryWatcher
{
public:
  DirectoryWatcher();
  ~DirectoryWatcher();

  void release_v();

  void watchDirectory_v(const char* i_Directory_pc);
  void watchDirectory_v(const wchar_t* i_Directory_pc);

  const char* getChangedFile();
  void consumeChangedFile();

private:
  static void initThread_v(void* i_Param_pv);
  void watchThread_v();

private:
  DWORD threadId_dw;
  HANDLE threadHandle_h;
  CRITICAL_SECTION criticalSection_o;

  std::wstring filePath_ac;
  char changedFile_ac[128];
};

} // namespace me3d


#endif // USE_DIRECTORY_WATCHER

#endif // DIRECTORY_WATCHER_H
