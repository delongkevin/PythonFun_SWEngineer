/** @file esm.h 
 *  @brief  CCM Application
 * 
 *  CPU Compare module (CCM) Application
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
#ifndef CCM_APP_H_
#define CCM_APP_H_

#include <soc.h>
/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/

#if (SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)
void TASK_ccm_app_self_test(void);
#endif	/*(SDL_APP_CCM_SELFTEST_ENABLED == SDL_APP_ON)*/
extern void TASK_ccm_app_init(void);
extern void TASK_ccm_app_MainFunction(void);

#endif /*  CCM_APP_H_ */
