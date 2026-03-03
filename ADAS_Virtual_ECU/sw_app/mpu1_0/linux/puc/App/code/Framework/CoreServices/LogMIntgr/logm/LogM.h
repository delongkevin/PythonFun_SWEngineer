//--------------------------------------------------------------------------
/// @file LogM.h
/// @brief Class, implementing the interface to the application
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGM_H_
#define LOGM_H_

#include <platform/PlatformAPI.h>

#include <osal/threading/Thread.h>

#include "LogBase.h"
#include "LogMessageReceiver.h"

#include <osal/networking/SocketServer.h>
#include <osal/networking/INetworkMsgHandler.h>

namespace logm
{

class LogM : public osal::IRunnable
{
public:

  LogM(LogBase& b_Log_ro, osal::INetwork& i_Interface_ro);

  virtual ~LogM();

  virtual void   init_v() ME_OVERRIDE;

  virtual bool_t run_b() ME_OVERRIDE;

  virtual void   cleanup_v() ME_OVERRIDE;

private:

  FileHandle_s       fileHandle_s;

  // interface members
  osal::INetwork&    logInterface_ro;

  LogMessageReceiver receiveHandler_o;

  // logging members

  LogBase&           log_ro;

};

} // namespace logm

#endif // LOGM_H_
