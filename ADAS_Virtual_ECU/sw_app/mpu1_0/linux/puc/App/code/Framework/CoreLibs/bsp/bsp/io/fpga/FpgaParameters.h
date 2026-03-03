//--------------------------------------------------------------------------
/// @file FpgaParameters.h
/// @brief Includes for platform independency
///
/// --------------------------------------------------------------------------
/// @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
/// This document in its entirety is CONFIDENTIAL and may not be disclosed,
/// disseminated or distributed to parties outside MAGNA Electronics
/// without written permission from MAGNA Electronics.
///
/// @author Martin Rachor (martin.rachor@Magna.com)
//  --------------------------------------------------------------------------

#ifndef FPGA_PARAMETERS_H_
#define FPGA_PARAMETERS_H_

#include <platform/PlatformAPI.h>

#ifdef ME_PLATFORM_QNX
#include <cfg/qnx/io/fpga/FpgaParameters_QNX.h>
#elif defined(ME_PLATFORM_WIN)
#include <cfg/win/io/fpga/FpgaParameters_WIN.h>
#elif defined(ME_PLATFORM_RTOS)
#include <cfg/rtos/io/fpga/FpgaParameters_RTOS.h>
#else
#error "No FpgaParameters.h include defined for this platform"
#endif


#endif // FPGA_PARAMETERS_H_
