//--------------------------------------------------------------------------
/// @file Iccom.h
/// @brief Class declaration of Iccom server
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Farzad Safa (Farzad.Safa@partner.magna.com)
///
//  --------------------------------------------------------------------------


#ifndef ICCOM_H
#define ICCOM_H

#include "cfg/BspTypes.h"

// ==========================================================================
// Includes
// ==========================================================================
#include <osal/networking/INetwork.h>


namespace bsp
{

/** Provides server objects encapsulating Iccom protocol.
 */
class Iccom : public osal::INetwork
{
  // --------------------------------------------------------------------------
  // Type definition(s)
  // --------------------------------------------------------------------------

  static const uint32_t c_MaxBufferSize_u32 = 2048U;

public:

  // --------------------------------------------------------------------------
  // c-tor / d-tor
  // --------------------------------------------------------------------------
public:
  /** tbd
   */
  explicit Iccom();

  /** tbd
   */
  virtual ~Iccom();

  // --------------------------------------------------------------------------
  // Interface inherited from INetwork
  // --------------------------------------------------------------------------
public:

  void                       init_v(uint8_t i_ChannelId_u8);

  bool_t                     open_b();

  /** tbd
   *
   * @param[in,out]  b_Handler_po   tbd
   */
  virtual bool_t             registerHandler_b(osal::INetworkMsgHandler* b_Handler_po) ME_OVERRIDE;

  /** tbd
   *
   * @return  tbd
   */
  virtual bool_t             process_b() ME_OVERRIDE;

  /** tbd
   */
  virtual void               shutdown_v() ME_OVERRIDE;

  /** tbd
   *
   * @param[in] b_Buffer_pu8
   * @param[in]     i_BufferLength_t
   */
  virtual bool_t             send_b(const uint8_t* i_Buffer_pu8, size_t i_BufferLength_t) ME_OVERRIDE;


  // --------------------------------------------------------------------------
  // Implementation
  // --------------------------------------------------------------------------
private:

  bool_t                     isOpened_b() const;

  bool_t                     isClosed_b() const;

  bool_t                     isFailed_b() const;


  // --------------------------------------------------------------------------
  // Data
  // --------------------------------------------------------------------------
private:

  enum Status_e
  {
    e_SendFailed =0,
    e_Opened,
    e_Closed
  };

  IccomHandle_t                iccomHandle_t;

  uint8_t                      channelId_u8;

  char_t                       receiveBuffer_ac[c_MaxBufferSize_u32]; // PRQA S 1021 // MAX_SOCKET_SIZE to be used from C and CPP

  osal::INetworkMsgHandler*    msgHandler_po;

  Status_e                     status_e;

};//END class ICCOMServer


} // namespace bsp

#endif // OSAL_ICCOMSERVER_H
