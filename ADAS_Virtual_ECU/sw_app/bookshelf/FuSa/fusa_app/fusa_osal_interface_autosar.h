/** @file fusa_osal_interface_autosar.h 
 *  @brief  autosar interface for SDL
 * 
 *  Interface provides functions for the SDL to interact with Autosar correctly.
 *  SDL is only capable of natively interfacing with baremetal and safeRTOS.
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Matt Kloepfer (Matt.Kloepfer@magna.com)
 */

#ifndef FUSA_MCU_1_0
#define FUSA_MCU_1_0

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

#include <osal/sdl_osal.h>
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */



/* ========================================================================== */
/*                          External Dependencies                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
int32_t FUSA_autosar_osalInit(void);
int32_t FUSA_autosar_GlobalTimeInit(void);
uint64_t FUSA_autosar_GetGlobalTimeInUsec(void);

#ifdef __cplusplus
}
#endif

#endif  /* #define FUSA_MCU_1_0 */
