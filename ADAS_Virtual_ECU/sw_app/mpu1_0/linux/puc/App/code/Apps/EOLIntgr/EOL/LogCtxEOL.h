//--------------------------------------------------------------------------
/// @file LogCtxEOL.h
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// Created on: 08.12.2015
///
/// @author Roman Berngardt (Roman.Berngardt@magna.com)
///
//  --------------------------------------------------------------------------

#ifndef LOGCTXEOL_H_
#define LOGCTXEOL_H_

#include "logging/LogProvider.h"

namespace eol
{

class LogCtxEOL
{
public:
  static void registerCtxId_v()
  {
    logging::LogProvider v_Lp_o;
    v_Lp_o.registerCtxId_v(LogCtxEOL::c_LogCtxEOL_u32);
  }
  static const uint32_t c_LogCtxEOL_u32 = 0x10000U;
};

} // namespace eol


#endif // LOGCTXEOL_H_
