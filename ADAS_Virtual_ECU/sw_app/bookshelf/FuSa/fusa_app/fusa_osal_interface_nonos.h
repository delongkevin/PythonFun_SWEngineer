/** @file fusa_osal_interface_nonos.h 
 *  @brief  osal api Handler
 * 
 *  osal api Handler
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
int32_t FUSA_freeRTOS_osalInit(void);
int32_t FUSA_freeRTOS_enableInterrupt(int32_t intNum);
int32_t FUSA_freeRTOS_disableInterrupt(int32_t intNum);
HwiP_Handle FUSA_freeRTOS_registerInterrupt(SDL_OSAL_hwipParams *pParams);
int32_t FUSA_freeRTOS_deregisterInterrupt(pSDL_OSAL_hwipHandle handle);
int32_t FUSA_freeRTOS_globalDisableInterrupts(uintptr_t *key);
int32_t FUSA_freeRTOS_globalRestoreInterrupts(uintptr_t key);
void FUSA_freeRTOS_applog_printf(const char* traceBuf, ...);
int32_t FUSA_freeRTOS_Osal_delay(int32_t ndelay);
void* FUSA_freeRTOS_addrTranslate(uint64_t addr, uint32_t size);
void* FUSA_TEST_addrTranslate(uint64_t addr, uint32_t size);

int32_t FUSA_freeRTOS_GlobalTimeInit(void);
uint64_t FUSA_freeRTOS_GetGlobalTimeInUsec(void);

#ifdef __cplusplus
}
#endif

#endif  /* #define FUSA_MCU_1_0 */
