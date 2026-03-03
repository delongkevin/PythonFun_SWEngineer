//--------------------------------------------------------------------------
/// @file LogBase.h
/// @brief Defines the Input-Output Interface for Opject Detection Algo
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

#ifndef LOGBASE_H_
#define LOGBASE_H_

#include <cfg/LogTypes.h>

#include <platform/PlatformAPI.h>

#include <platform/stdlib/ME_Semaphore.h>

#include <osal/threading/IRunnable.h>

#include <mecl/buffer/IBuffer.h>

namespace logm
{

class LogBase : public osal::IRunnable
{
public:

  explicit LogBase(mecl::buffer::IBuffer& i_Buffer_ro);

  virtual ~LogBase();

  virtual void   init_v() ME_OVERRIDE;

  virtual bool_t run_b() ME_OVERRIDE;

  virtual void   cleanup_v() ME_OVERRIDE;

  virtual void   onInit_v() = 0;

  virtual void   onCleanup_v() = 0;

  virtual bool_t processLogMsg_b(const logging::LogHeader_t* i_LogHeader_pt) = 0;

  bool_t log_b(const void* i_Buffer_pv, uint32_t v_Size_u32);

  static sint32_t isLogMsg_pt(uint8_t* i_Buffer_pu8, uint32_t i_Size_u32, logging::LogHeader_t** o_LogHeader_t);

private:

  mecl::buffer::IBuffer& buffer_ro; // PRQA S 2101 // buffer_o shall be used by derived classes

  Mutex_s mutex_s;

#ifdef ME_PLATFORM_WIN
  HANDLE mutex_t;
#endif

  uint32_t    numOfBytesProcessed_u32;
  uint32_t    numOfBytesLogged_u32;

  uint32_t    writeIdx_u32;
  uint32_t    size_u32;
  uint32_t    diff_u32;
};


} // namespace logging


#endif /* I_LOG_H_ */
