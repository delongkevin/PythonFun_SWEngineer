//--------------------------------------------------------------------------
/// @file JobSigM.h
/// @brief Contains the job definition for the signal manager.
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///         Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef JOB_SIGM_H
#define JOB_SIGM_H

#include <platform/PlatformAPI.h>

#include "IDataProviderSigM.h"
#include "NetworkMessageRunnable.h"

#include "cfg/ProjectRequests.h"
#include "cfg/ProjectReceivers.h"
#include "cfg/runnables/KeepAliveRunnable.h"
#include "cfg/runnables/TraGateway4Runnable.h"
#include "cfg/runnables/IsoTpTransceiver.h"
#include "cfg/runnables/MessageSenderRunnable.h"

#include <container/JobBase.h>

#include <osal/networking/INetworkMsgHandler.h>

#define USE_KEEP_ALIVE

#if 0
#define USE_ISOTP
//#define USE_KEEP_ALIVE
#define USE_REQUEST_AND_RESPONSE
#define TRA_GATEWAY4
#endif

/// Signal-Manager handles communication between CuC & PuC
namespace sigm
{


class JobSigM : public container::JobBase<IDataProviderSigM>
              , public osal::INetworkMsgHandler
{
public:
  JobSigM(container::JobDesc_s& b_JobDesc_rs, IDataProviderSigM& b_DataProvider_ro, osal::INetwork* b_NetInterface_po);
  virtual ~JobSigM();

  // JobBase implementation
  virtual bool_t  onInit_b() ME_OVERRIDE;
  virtual void    onVariantChanged_v(bool_t i_FirstTime_b) ME_OVERRIDE;
  virtual bool_t  onRun_b() ME_OVERRIDE;
  virtual void    onCleanup_v() ME_OVERRIDE;

  // INetworkMsgHandler implementation
  virtual void    onReceive_v(osal::INetwork * i_NetworkInterface_po, uint8_t* b_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;

  //Send anything via INetwork implementation
  bool_t          send_b(const uint8_t* i_Data_pu8, uint32_t i_DataSize_u32, uint32_t i_Channel_u32); // for sending RAW data

private:

  virtual bool_t  processMessage_b(const ME_MsgRx_s& i_Msg_rx);

  virtual void    handleErrorneousRequest(const ME_MsgRx_s& i_Msg_rx);

  /// Collector function to process all common requests
  virtual void    checkBaseRequests_v();

  virtual void    startThreads_v();
  virtual void    terminateThreads_v();

private:

  osal::Mutex                   mutex_o;
  osal::INetwork*               network_po;
  BaseRequestList_t             requestItems_t;
  ProjectRequests_s             projectRequests_s;

  BaseReceiverList_t            receiverItems_t;
  ProjectReceivers_s            projectReceivers_s;

#ifdef USE_KEEP_ALIVE
  KeepAliveRunnable             keepAliveRunnable_o;
  osal::Thread                  keepAliveSenderThread_o;
#endif

#ifdef TRA_GATEWAY4
  TRAGateway4Runnable           TRAGateway4Runnable_o;
  osal::Thread                  TRAGateway4SenderThread_o;
#endif

  NetworkMessageRunnable        networkMessageRunnable_o;
  osal::Thread
  networkMessageThread_o;
#ifdef USE_ISOTP
  IsoTpTransceiver              isoTpTransceiver_o;
  osal::Thread                  isoTpTransceiverThread_o;
#endif

  MessageSenderRunnable         MessageSenderRunnable_o;
  osal::Thread                  messageSenderThread_o;

};

}
#endif // JOB_SIGM_H

