//--------------------------------------------------------------------------
/// @file LogDlt.h
/// @brief
///
/// IDataProvider is an interface used by the algorithm to define what data
/// is actually needed. Implementation is delegated to a derived data provider
/// that is component/module specific and belongs to the framework implementation.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGDLT_H_
#define LOGDLT_H_

#include "logm/LogBase.h"

#include <platform/PlatformAPI.h>

#include <dlt/dlt.h>
#include <dlt/dltapp.h>
#include <dlt/dltcom.h>
#include <dlt/dltpdu.h>
#include <dlt/dltctrl.h>
#include <dlt/dlthdr.h>

#include <cfg/LogTypes.h>

#include <osal/networking/INetwork.h>
#include <osal/threading/IRunnable.h>
#include <osal/threading/Thread.h>

namespace logm
{

// -------------------------------------------------------------------------------------
// Class LogDlt
// -------------------------------------------------------------------------------------

class LogDltRunnable : public osal::IRunnable, public osal::Thread
{
public:

  explicit LogDltRunnable(osal::INetwork* i_Interface_po)
  : osal::IRunnable()
  , osal::Thread()
  , interface_po(i_Interface_po)
  , isActive_b(false)
  {}

  virtual ~LogDltRunnable()
  {
  }

  virtual void init_v()
  {
  }

  virtual bool_t run_b()
  {
    if(interface_po != NULL)
    {
      // check for new connection
      if(true == interface_po->process_b())
      {
        isActive_b = true;

        ME_Debugger_F_Printf_v("LogDlt - connected\n");
        FileHandle_s v_FileHandle_s;
        ME_File_Open_t(&v_FileHandle_s, "/tmp/LogDlt", e_FomWrite);
      }

      // Receive packages
      while(true == interface_po->process_b())
      {
        // do nothing
      }

      isActive_b = false;
    }

    return true;
  }

  virtual void cleanup_v()
  {

  }

  void setInterface_v(osal::INetwork* i_Interface_po)
  {
    interface_po = i_Interface_po;
  }

  bool_t getIsActive_b() const
  {
    return isActive_b;
  }

private:

  osal::INetwork* interface_po;

  bool_t isActive_b;
};


// -------------------------------------------------------------------------------------
// Class LogDlt
// -------------------------------------------------------------------------------------

class LogDlt : public LogBase
{
public:

  explicit LogDlt(mecl::buffer::IBuffer& i_Buffer_ro);

  virtual ~LogDlt();

  virtual void     onInit_v() ME_OVERRIDE;

  virtual bool_t   processLogMsg_b(const logging::LogHeader_t* i_LogHeader_pt) ME_OVERRIDE;

  virtual void     onCleanup_v() ME_OVERRIDE;

  static bool_t    send_b(uint8_t i_PduId_u8);

  static uint8_t   getDltLoglevel_u8(logging::LogLevel_t i_CommonLogLevel_e);

  static logging::LogLevel_t getPlatformLoglevel_u8(uint8_t i_CommonLogLevel_u8);

  static uint8_t   sendBuffer_b(uint8_t i_Channel_u8, const sDltPdu_s_PduInfo_t *i_TxBuffer_ps);

  static void      setLogInterface_v(osal::INetwork* i_LogInterface_po);

private:

  LogDltRunnable processThread_o;

  static osal::INetwork* s_LogInterface_ro;
};

}

#endif // LOGDLT_H_
