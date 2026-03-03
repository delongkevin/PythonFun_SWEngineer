/***********************************************************************************************************************
 *  FILE DESCRIPTION
 *  ------------------------------------------------------------------------------------------------------------------*/
/** \file
 *  \brief        Inter-Integrated Circuit Driver (Texas Instruments)
 *
 *  \note         Please note, that this file contains an implementation/configuration example for the I2C driver.
 *                This code may influence the behavior of the I2C driver in principle. Therefore, great care must be
 *                taken to verify the correctness of the implementation.
 *
 *                The contents of the originally delivered files are only examples resp. implementation proposals.
 *                With regard to the fact that these functions are meant for demonstration purposes only, Vector
 *                Informatik's liability shall be expressly excluded in cases of ordinary negligence, to the extent
 *                admissible by law or statute.
 *
 *  --------------------------------------------------------------------------------------------------------------------
 *  COPYRIGHT
 *  --------------------------------------------------------------------------------------------------------------------
 *  \par Copyright
 *  \verbatim
 *  Copyright (c) 2022 by Vector Informatik GmbH.                                                  All rights reserved.
 *
 *                This software is copyright protected and proprietary to Vector Informatik GmbH.
 *                Vector Informatik GmbH grants to you only those rights as set out in the license conditions.
 *                All other rights remain with Vector Informatik GmbH.
 *  \endverbatim
 */
/**********************************************************************************************************************/

/***********************************************************************************************************************
 *  TEMPLATE REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2015-06-12  visrie  -             Initial version
 *  01.00.01   2015-09-14  visshs  -             Minor changes
 *  01.00.02   2016-05-13  visrie  -             Minor changes
 *  --------------------------------------------------------------------------------------------------------------------
 *  REVISION HISTORY
 *  --------------------------------------------------------------------------------------------------------------------
 *  Version    Date        Author  Change Id     Description
 *  --------------------------------------------------------------------------------------------------------------------
 *  01.00.00   2022-05-12  vismix  FBL-4521      Initial version
 **********************************************************************************************************************/

#ifndef FBLDRVI2C_TEXASINSTRUMENTS_I2C_CFG_H
#define FBLDRVI2C_TEXASINSTRUMENTS_I2C_CFG_H

/***********************************************************************************************************************
 *  INCLUDES
 **********************************************************************************************************************/

/* Include API of watchdog service module */
#include "fbl_wd.h"

/***********************************************************************************************************************
 *  DEFINES
 **********************************************************************************************************************/

/* Select the required I2C base address */
#if defined( V_CPU_JACINTO7 )
# define FBL_I2C0_BASE      0x02000000uL
# define FBL_I2C1_BASE      0x02010000uL
# define FBL_I2C2_BASE      0x02020000uL
# define FBL_I2C3_BASE      0x02030000uL
# define FBL_I2C4_BASE      0x02040000uL
# define FBL_I2C5_BASE      0x02050000uL
# define FBL_I2C6_BASE      0x02060000uL
# define FBL_MCU_I2C0_BASE  0x040B0000uL
# define FBL_WKUP_I2C0_BASE 0x04212000uL
#endif

#define FBL_I2C_BASE    FBL_I2C0_BASE

/* Enable peripheral clocks for I2C, system clock = peripheral clock */
/* Must be done before run mode switch in e.g. ApplFblInit() */
/* CGM_SCDC = 0x80808080ul; */

/* Set value for the frequency divider (here for 12 MHz) */
#define FBL_I2C_PSC_VALUE           0x0Cu
/* Set value for SCL low time (here for 400Kbps) */
#define FBL_I2C_BITRATE_SCLL_VALUE  0x07u
/* Set value for SCL high time (here for 400Kbps) */
#define FBL_I2C_BITRATE_SCLH_VALUE  0x05u
/* Set value for own slave address */
#define FBL_I2C_SLAVE_OWN_VALUE     0x33u
/* Set value for external slave address */
#define FBL_I2C_SLAVE_EXT_VALUE     0x6Fu
/* Set value for BUS timeout */
#define FBL_I2C_BUS_TIMEOUT         0x0Au
/* Set value for BUS minimum waittime */
#define FBL_I2C_BUS_MIN_WAITTIME    0x01u

/* Watchdog trigger function
 * Note: If I2C driver is used to control an external watchdog this define should be empty (unintentional recursion) */
#define FBL_I2C_WATCHDOG_FCT()      FblLookForWatchdog()

#endif /* FBLDRVI2C_TEXASINSTRUMENTS_I2C_CFG_H */

/***********************************************************************************************************************
 *  END OF FILE: FBL_I2C_CFG.H
 **********************************************************************************************************************/
