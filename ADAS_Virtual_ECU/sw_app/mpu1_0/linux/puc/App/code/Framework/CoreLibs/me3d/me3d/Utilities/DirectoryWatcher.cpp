#include "DirectoryWatcher.h"

#ifdef USE_DIRECTORY_WATCHER

#include <string>
#include <algorithm>

namespace me3d
{

DirectoryWatcher::DirectoryWatcher()
{
}

DirectoryWatcher::~DirectoryWatcher()
{
}

void DirectoryWatcher::release_v()
{
  TerminateThread(threadHandle_h, 0);
}

void DirectoryWatcher::watchDirectory_v(const wchar_t* i_Directory_pc)
{
  filePath_ac = i_Directory_pc;

  InitializeCriticalSection(&criticalSection_o);

  threadHandle_h = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)initThread_v, (void*) this, 0, &threadId_dw);
}

void DirectoryWatcher::watchDirectory_v(const char* i_Directory_pc)
{
  std::string dir(i_Directory_pc);

  std::wstring dirW(dir.length(), L' '); // Make room for characters

  // Copy string to wstring.
  std::copy(dir.begin(), dir.end(), dirW.begin());

  watchDirectory_v(dirW.c_str());
}

const char* DirectoryWatcher::getChangedFile()
{
  return changedFile_ac;
}

void DirectoryWatcher::consumeChangedFile()
{
  EnterCriticalSection(&criticalSection_o);

  memset(changedFile_ac, 0, sizeof(changedFile_ac));

  LeaveCriticalSection(&criticalSection_o);
}

void DirectoryWatcher::initThread_v(void* i_Param_pv)
{
  DirectoryWatcher* v_Watcher_po = (DirectoryWatcher*)i_Param_pv;
  v_Watcher_po->watchThread_v();
}

void DirectoryWatcher::watchThread_v()
{
  HANDLE hDir = CreateFileW(
    filePath_ac.c_str(),
    FILE_LIST_DIRECTORY,                
    FILE_SHARE_READ | FILE_SHARE_DELETE,
    NULL,                               
    OPEN_EXISTING,                      
    FILE_FLAG_BACKUP_SEMANTICS,         
    NULL                                
    );

  DWORD v_returnSize_dw;
  FILE_NOTIFY_INFORMATION infos_as[1024];
  while (ReadDirectoryChangesW(hDir, &infos_as, sizeof(infos_as), TRUE, FILE_NOTIFY_CHANGE_LAST_WRITE, &v_returnSize_dw, 0, 0))
  {
    EnterCriticalSection(&criticalSection_o);

    unsigned char* v_DataBin_ac = (unsigned char*)infos_as;
    FILE_NOTIFY_INFORMATION* v_DataInfo_ps = infos_as;

    do 
    {
      std::wstring fileName = filePath_ac + L"/" + std::wstring(v_DataInfo_ps->FileName, v_DataInfo_ps->FileNameLength / sizeof(wchar_t));

      // convert wchar to char
      wcstombs(changedFile_ac, fileName.c_str(), sizeof(changedFile_ac));

      // advance
      v_DataBin_ac += v_DataInfo_ps->NextEntryOffset;
      v_DataInfo_ps = (FILE_NOTIFY_INFORMATION*)v_DataBin_ac;
    } 
    while (v_DataInfo_ps->NextEntryOffset);

    LeaveCriticalSection(&criticalSection_o);
  }
}

} // namespace me3d

#endif // USE_DIRECTORY_WATCHER
