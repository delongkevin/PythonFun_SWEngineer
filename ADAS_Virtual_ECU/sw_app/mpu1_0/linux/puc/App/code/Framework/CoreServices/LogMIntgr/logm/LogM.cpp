
#include "LogM.h"

#include <cfg/LogTypes.h>

// PRQA S 2427 EOF // using the QNX resource manager functionalities requires using fundamental types

namespace logm
{
 
  LogM::LogM(LogBase& b_Log_ro, osal::INetwork& i_Interface_ro)
    : osal::IRunnable()
    , logInterface_ro(i_Interface_ro)
    , receiveHandler_o(b_Log_ro)
    , log_ro(b_Log_ro)
  {}

  LogM::~LogM()
  {}

  // -----------------------------------------------------------------
  // Function declaration
  // -----------------------------------------------------------------

  void LogM::init_v()
  {
    logInterface_ro.registerHandler_b(&receiveHandler_o);

    ME_File_Open_t(&fileHandle_s, "/tmp/LogM", e_FomWrite);
  }

  // -----------------------------------------------------------------

  bool_t LogM::run_b()
  {
    // check for incoming messages
    if(true == logInterface_ro.process_b())
    {
      ME_Debugger_F_Printf_v("LogM - connected\n");
    }

    // Receive packages
    while (true == logInterface_ro.process_b())
    {
      // do nothing, just wait for receiving packages
    }

    ME_Debugger_F_Printf_v("LogM - disconnected\n");

    return true;
  }

  // -----------------------------------------------------------------

  void LogM::cleanup_v()
  {
    ME_Debugger_F_Printf_v("LogM::cleanup_v()\n");
    logInterface_ro.shutdown_v();
  }

} // namespace logm
