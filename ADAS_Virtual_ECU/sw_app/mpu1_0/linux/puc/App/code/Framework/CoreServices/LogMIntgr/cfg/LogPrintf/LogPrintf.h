//--------------------------------------------------------------------------
/// @file LogPrintf.h
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

#ifndef LOGPRINTF_H_
#define LOGPRINTF_H_

#include <platform/PlatformAPI.h>

#include "logm/LogBase.h"

#include <cfg/LogTypes.h>

namespace logm
{

class LogPrintf : public LogBase
{
public:

  explicit LogPrintf(mecl::buffer::IBuffer& i_Buffer_ro);

  virtual ~LogPrintf();

  virtual void   onInit_v() ME_OVERRIDE;

  virtual bool_t processLogMsg_b(const logging::LogHeader_t* i_LogHeader_pt) ME_OVERRIDE;

  virtual void   onCleanup_v() ME_OVERRIDE;
};

}

#endif // LOGPRINTF_H_
