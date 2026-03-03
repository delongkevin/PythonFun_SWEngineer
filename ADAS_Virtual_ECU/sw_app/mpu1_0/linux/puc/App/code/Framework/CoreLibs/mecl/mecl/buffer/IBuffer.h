//--------------------------------------------------------------------------
/// @file IBuffer.h
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

#ifndef IBUFFER_H_
#define IBUFFER_H_

#include <platform/PlatformAPI.h>

namespace mecl
{

  namespace buffer
  {

    class IBuffer
    {
    public:

      IBuffer() {}

      virtual ~IBuffer() {}

      virtual void init_v() = 0;

      virtual void cleanup_v() = 0;

      virtual bool_t write_b(const void* b_Buffer_pv, uint32_t i_Size_u32) = 0;

      virtual uint32_t read_u32(void* b_Buffer_pv) = 0;
    };

  } // namespace buffer

} // namespace mecl

#endif /* IBUFFER_H_ */
