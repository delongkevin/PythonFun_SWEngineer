/** @file diagnostics.h
 *  @brief diagnostics data
 * 
 *  diagnostics data
 * 
 *  --------------------------------------------------------------------------
 *  @copyright MAGNA Electronics - C O N F I D E N T I A L <br>
 *  This document in its entirety is CONFIDENTIAL and may not be disclosed,
 *  disseminated or distributed to parties outside MAGNA Electronics
 *  without written permission from MAGNA Electronics.
 * 
 *  @author Anonymous Author (Anonymous.Author@magna.com)
 */
/*==================[inclusions]============================================*/
#ifndef DIAGNOSTICS_MCU2_0_H
#define DIAGNOSTICS_MCU2_0_H
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */



/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* UB960 Deser Registers */
#define UB960_RX_PORT_STS1_REG              (0x4DU)
#define UB960_RX_PORT_STS1_REG_LOCK_STS     (1 << 0)
#define UB960_RX_PORT_STS1_REG_LOCK_STS_CHG (1 << 4)

#define MAX_SVS_CAM          (4U)
/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* Cameras and Serializer Power enable status - for DID 22FD20 */


	
	
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
void Diagnostics_Run();
void Get_Cam_Power_EN_Stat(void);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */


/* ========================================================================== */
/*                            External Variables                              */
/* ========================================================================== */


#endif


