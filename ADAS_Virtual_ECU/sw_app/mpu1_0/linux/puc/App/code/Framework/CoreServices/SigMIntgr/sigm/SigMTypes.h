//--------------------------------------------------------------------------
/// @file SigMTypes.h
/// @brief Contains SignalManager specific defines, enums and structures
///
/// 
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author
///
//  --------------------------------------------------------------------------

#ifndef SIGMTYPES_H_
#define SIGMTYPES_H_

#include <platform/PlatformAPI.h>
#include "variants/Enums.h"


// PRQA S 2100 EOF // public members used here by design. All structs here should be considered POD
// PRQA S 2400 EOF // global scope, this is a header file

namespace sigm
{

struct SendReceiveCntrl_s
{
  SendReceiveCntrl_s()
  : requestedAt_u32(0)
  , respondedAt_u32(0)
  , responseCode_t(variants::e_ResponseCodeNotSupportedCANID)
  {}

  uint32_t requestedAt_u32;
  uint32_t respondedAt_u32;
  variants::SignalTypesResponseCode_t responseCode_t;

  SendReceiveCntrl_s& operator=(const SendReceiveCntrl_s& i_data_rs)
  {
    if (this != &i_data_rs)
    {
      requestedAt_u32= i_data_rs.requestedAt_u32;
      respondedAt_u32 = i_data_rs.respondedAt_u32;
      responseCode_t = i_data_rs.responseCode_t;
    }
    return *this;
  }

private:
  SendReceiveCntrl_s(const SendReceiveCntrl_s& i_data_rs);
};


struct ReceiveCntrl_s
{
  ReceiveCntrl_s()
  : receivedAt_u32(0)
  , processedAt_u32(0)
  , responseCode_t(variants::e_ResponseCodeNotSupportedCANID)
  {}

  uint32_t receivedAt_u32;
  uint32_t processedAt_u32;
  variants::SignalTypesResponseCode_t responseCode_t;

  ReceiveCntrl_s& operator=(const ReceiveCntrl_s& i_data_rs)
  {
    if (this != &i_data_rs)
    {
      receivedAt_u32= i_data_rs.receivedAt_u32;
      processedAt_u32 = i_data_rs.processedAt_u32;
      responseCode_t = i_data_rs.responseCode_t;
    }
    return *this;
  }

private:
  ReceiveCntrl_s(const ReceiveCntrl_s& i_data_rs);
};



struct SendCntrl_s
{
	SendCntrl_s()
  : sendAt_u32(0)
  , processedAt_u32(0)
  , responseCode_t(variants::e_ResponseCodeNotSupportedCANID)
  {}

  uint32_t sendAt_u32;
  uint32_t processedAt_u32;
  variants::SignalTypesResponseCode_t responseCode_t;

  SendCntrl_s& operator=(const SendCntrl_s& i_data_rs)
  {
    if (this != &i_data_rs)
    {
      sendAt_u32= i_data_rs.sendAt_u32;
      processedAt_u32 = i_data_rs.processedAt_u32;
      responseCode_t = i_data_rs.responseCode_t;
    }
    return *this;
  }

private:
  SendCntrl_s(const SendCntrl_s& i_data_rs);
};



}

#endif /* SIGMTYPES_H_ */

