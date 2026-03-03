/*
 * dp83tc812_priv.h
 *
 *  Created on: Apr 12, 2022
 *      Author: aviswakumar
 */

#ifndef DP83TC812_PRIV_H_
#define DP83TC812_PRIV_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include "enetphy_priv.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/*! \brief PHY Control Register #1 (CR1) */
#define DP83TC812_CR1                           (0x09U)

/*! \brief PHY Control Register (PHYCR) */
#define DP83TC812_PHYCR                         (0x19U)

/* CR1 register definitions */
#define CR1_ROBUSTAUTOMDIX                    (0x0020U)

/* PHYCR register definitions */
#define PHYCR_AUTOMDIX_ENABLE                 (0x8000U)
#define PHYCR_FORCEMDIX_MASK                  (0x4000U)
#define PHYCR_FORCEMDIX_MDIX                  (0x4000U)
#define PHYCR_FORCEMDIX_MDI                   (0x0000U)

#endif /* PSDKQA_PDK_PACKAGES_TI_DRV_ENET_SRC_PHY_DP83TC812_PRIV_H_ */
