/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef SBL_SCI_CLIENT_H
#define SBL_SCI_CLIENT_H

#include "sbl_log.h"
#include "sbl_profile.h"
#include <ti/board/board.h>
#include <ti/drv/sciclient/sciclient.h>

#ifdef __cplusplus
extern "C" {
#endif

#define SBL_NEVER_AUTH_APP         (0x55555555u)
#define SBL_ALWAYS_AUTH_APP        (0xAAAAAAAAu)
/* NOTE: tifs.bin is currently 160715 bytes. If we receive a new version of
 * tifs.bin that's larger than the current version, then this may need to be 
 * increased!!
 */
#define SBL_SYSFW_MAX_SIZE         (0x30000U)
/*#define SBL_SYSFW_MAX_SIZE         (161000U)*/


#define SBL_SYS_STATUS_REG              (0x44234100U)
#define SBL_SYS_STATUS_DEV_TYPE_MASK    (0x0000000FU)
#define SBL_SYS_STATUS_DEV_SUBTYPE_MASK (0x00000F00U)


#define SBL_SYS_STATUS_DEV_TYPE_GP      (0x3U)
#define SBL_SYS_STATUS_DEV_TYPE_TEST    (0x5U)
#define SBL_SYS_STATUS_DEV_SUBTYPE_FS   (0x00000A00U)

#define SBL_FW_REGION_MASK			(0x00000100U)
#define SBL_FW_REGION_SHIFT			(0x00000008U)
#define SBL_FW_REGION_BACKGROUND	(0x1U)
#define SBL_FW_REGION_FOREGROUND	(0x0U)

/**
* @brief - Structure to store firewall data
*
*/
typedef struct
{
	/* firewall ID */
	uint16_t fwlId;
	/* Number of Regions */
	uint32_t numRegions;
}sblFwlData;

/**
 * @brief - SBL_SciClientInit() - function to do load DMSC firmware.
 *
 * @param   none
 *
 * @return - none
 *      Loops forever if error occurs
 *
 */
void SBL_SciClientInit(void);

/**
 * @brief - SBL_ReadSysfwImage() - function to do read DMSC firmware.
 *
 * @param pBuffer        [IN] Pointer to buffer large enough for SYSFW
 * @param num_bytes      [IN] Size in bytes of system firmware bnary
 *
 * @return CSL_PASS on success, CSL_EFAIL failure
 *
 *      Loops forever if error occurs
 *
 */
int32_t SBL_ReadSysfwImage(void **pBuffer, uint32_t num_bytes);

/**
 * @brief - SBL_IsAuthReq() - function to check if SBL needs to authenticate app
 *
 * @param  none
 *
 * @return SBL_ALWAYS_AUTH_APP if apps have to be authenticated and/decrypted before being executed (SE subtype)
 *         SBL_NEVER_AUTH_APP  if app authentication must not be done (no SMPK/BMPK present)
 *
 *      Loops forever if error occurs
 *
 */
uint32_t SBL_IsAuthReq(void);

/**
* @brief - SBL_disableFwlRegion() - function to disable firewall on region based
*          i.e if disableRegion is passed as SBL_FW_REGION_BACKGROUND then it disables all the background
*          regions and if disableRegion is passed as SBL_FW_REGION_FOREGROUND then it disables all the
*          foreground regions
*
* @param tisci_msg_fwl_get_firewall_region_req              [IN] Structure to request for retrieving the firewall permissions.
* @param numRegions                                         [IN] Max number of regions that can be configured for fwId
* @param disableRegion                                      [IN] Removes firewall for Background regions if true else remove foreground regions
*
* @return CSL_PASS on success, CSL_EFAIL failure
*
*/
int32_t SBL_disableFwlRegion(struct tisci_msg_fwl_get_firewall_region_req* reqGetFwCtrl, uint32_t numRegions, uint32_t disableRegion);

extern const struct tisci_boardcfg_pm gBoardConfigLow_pm;

#ifdef __cplusplus
}
#endif /* __cplusplus */


#endif
