
#include <platform/PlatformAPI.h>

#ifndef IO_TYPES_H_
#define IO_TYPES_H_

#ifdef ME_PLATFORM_QNX
#include "qnx/BspTypes_Qnx.h"
#elif defined(ME_PLATFORM_WIN)
#include "win/BspTypes_Win.h"
#elif defined(ME_PLATFORM_LINUX)
#include "linux/BspTypes_Linux.h"
#elif defined(ME_PLATFORM_AUTOSAR)
#include "autosar/BspTypes_Autosar.h"
#elif defined(ME_PLATFORM_RTOS)
#include "rtos/BspTypes_Rtos.h"
#else
#error "No platform defined"
#endif

#endif // IO_TYPES_H_
