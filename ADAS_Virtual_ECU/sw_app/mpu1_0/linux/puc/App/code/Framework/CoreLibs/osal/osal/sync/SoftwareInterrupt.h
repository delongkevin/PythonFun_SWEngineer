//--------------------------------------------------------------------------
/// @file SoftwareInterrupt.h
/// @brief Implementation of Software interrupt to synchronize different threads
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef SOFTWARE_INTERRUPT_H_
#define SOFTWARE_INTERRUPT_H_

#include <platform/PlatformAPI.h>

#include <osal/threading/Mutex.h>


namespace osal
{

const uint32_t c_MAX_ATTACHMENTS_u8 = 1U;

class SoftwareInterrupt
{
public:

  SoftwareInterrupt();

  ~SoftwareInterrupt();

  void    init_v();

  void    broadcast_v();

  void    receive_v(uint8_t i_AttachmentID_u8);

  uint8_t attach_u8();

  void    detach_v(uint8_t i_AttachmentID_u8);

  bool_t  isUsed_b(uint8_t i_AttachmentID_u8);

private:

  Mutex_s       mutex_o;

  bool_t        isInitialized_b;

  Condvar_s     condvars_as[c_MAX_ATTACHMENTS_u8];

  bool_t        isUsed_ab[c_MAX_ATTACHMENTS_u8];

};

} // namespace osal

#endif
