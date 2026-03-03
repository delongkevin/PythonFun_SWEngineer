//--------------------------------------------------------------------------
/// @file SensorBase.h
/// @brief Defines a general interface implementation for sensors
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
///
//  --------------------------------------------------------------------------

#ifndef SENSROR_BASE_H_
#define SENSROR_BASE_H_

#include <platform/PlatformAPI.h>

namespace sensor
{

  class SensorBase
  {
  public:

    SensorBase(){}

    virtual ~SensorBase(){}

    // configure
    static bool_t init_b()
    {
      return true;
    }

    // open for usage
    virtual bool_t open_b() = 0;

    virtual bool_t close_b() = 0;

  };

} // namespace sensor

#endif // SENSROR_BASE_H_
