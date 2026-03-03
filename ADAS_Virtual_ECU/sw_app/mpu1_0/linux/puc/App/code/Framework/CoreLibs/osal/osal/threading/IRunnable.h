//--------------------------------------------------------------------------
/// @file IRunnable.h
/// @brief Interface used by Thread class. Inherit from this Interface and override function run_v
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Mark Reichert (Mark.Reichert2@magna.com)
///
//  --------------------------------------------------------------------------


#ifndef OSAL_RUNNABLE_H
#define OSAL_RUNNABLE_H

namespace osal
{

class IRunnable
{
  public:
    virtual ~IRunnable()      {};
    virtual void    init_v()     = 0;
    virtual bool_t  run_b()      = 0;
    virtual void    cleanup_v()  = 0;
};

} // namespace osal

#endif // OSAL_RUNNABLE_H
