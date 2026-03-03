//--------------------------------------------------------------------------
/// @file BaseSender.h
/// @brief Contains BaseClass implementation for a base sender
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Ananda Kavrady (Ananda Kavrady@magna.com)
///
//  --------------------------------------------------------------------------

/// \addtogroup sigm
/// @{
/// @brief Contains handlers for the different private communication requests.

#ifndef BASESENDER_H_
#define BASESENDER_H_

#include "sigm/IDataProviderSigM.h"

#include "cfg/ME_Msg.h"

#include "sigm/SigMTypes.h"

#include <platform/PlatformAPI.h>

#include <container/MessageTypes.h>
#include <container/JobBase.h>

#include <cfg/shmdata/SigM_Messages.h>

namespace sigm
{

class JobSigM;

/// Contains handlers for the different INetwork interface requests.
// PRQA S 2127 ++ // for simplicity there is a default implementation of all virtual methods - this is by design
// PRQA S 2101 ++ // protected members are by design

/// Common request class which is used in JobSigM to parse incoming data for a request and to fill the response for that request.
/// The handleRequest_v and fillResponse_b method has to be implemented
/// if the response contains more data than just a response state (e.g. "OK").
/// Each request implementation has to be added to the requestlist and initialized in JobSigM::init_v().
class BaseSender

{
public:
  /// Constructor
  /// @param [in] i_MsgReceived_ro received message
  /// @param [in] i_MsgReceived_ro received message
  /// @param [in] i_MsgReceived_ro received message
  /// @return void 
  BaseSender(IpcMsgId_t i_SenderID_t, uint32_t i_FrameCountTimeout_u32);

  virtual ~BaseSender();

  /// Initializes the request.
  void init_v(sigm::IDataProviderSigM& b_DataProvider_ro, JobSigM& b_JobSigM_ro);


  /// Copies the receive message
  /// @return true if the response should be sent. used in Signal Manager 
  bool_t handlSender_b();

  /// Gets the receive id
  /// @return enum representing the send id
  IpcMsgId_t getSendID_t() const;

  /// Check if receiver is still active
  /// @return enum representing the send id
  virtual bool_t isActive_b();

  /// Mark Message as processed
  /// @return void
  void setProcessed_v();

  /// Mark Message as requested
  /// @return void
  void setReceived_v();

  /// Set the actal state of the received message
  /// @return always true
  bool_t setProcess_b();

  /// Performs the actual send on the INetwork Interface using the JobSigM
  /// @return always true
  bool_t sendResponse_b();

  // add crc later here
  /// @return the header length + sizeof the struct specified in template argument
  template <typename T>
  static uint32_t getMessageSize_u32()
  {
    return c_HeaderLength_u32 + sizeof(T);
  }

protected:

  /// handles a specific request. must be overridden
  /// @return true if response needs to be sent
  virtual bool_t handleSpecificSender_b() = 0;

 
  uint32_t addSendIdHeader_u32(uint8_t* b_Data_pu8) const;

  /// Sets the response state to "delayed" in case the response cannot be sent yet.
  /// @return void
  void setDelayed_v();

  /// Checks if the message is timed out (e.g exceeded frameCountTimeout_u32)
  /// @return true if message timed out
  bool_t checkForTimeout_b() const;

protected:
  static const uint32_t c_HeaderLength_u32 = 2U;        /// < Current Header length for this protocols
                               ///< Specifies whether the request has a response
  IDataProviderSigM* dataProvider_po;                   ///< Access to the DataProvider
  JobSigM* jobSigM_po;                                  ///< Access to the Signal Manager Job
  uint32_t channel_u32;

  ME_MsgTx_s msgToRespond_s;                            ///< Message Object to respond


private:
  osal::Mutex mutex_o;
  IpcMsgId_t senderID_t;                              ///< receiver id, defined in constructor
  SendCntrl_s sendControl_s;
  uint32_t frameCountTimeout_u32;                       ///< if timeout, request will be marked as delayed
};

} // namespace sigm

// PRQA S 2127 --
// PRQA S 2101 --

#endif /* BASESENDER_H_ */
/// @}
/// @}
