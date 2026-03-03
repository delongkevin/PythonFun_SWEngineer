/** @file esm.h 
 *  @brief  ESM Application
 * 
 *  Error signaling module (ESM) Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Matt Kloepfer (Matt.Kloepfer@magna.com)
 */

#ifndef ESM_APP_H_
#define ESM_APP_H_

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

void TASK_esm_app_init(void);
uint8_t IsEsmAppInitComplete(void);
/* Hard init ESM functions to re-iniitialize (e.g. POK module overwrites WKUP_ESM0 settings)*/
int32_t ESM_init_WKUP_ESM0 (void);
void TASK_esm_MainFunction(void);
void ESM_DeInit(void);

#endif /*  ESM_APP_H_ */
