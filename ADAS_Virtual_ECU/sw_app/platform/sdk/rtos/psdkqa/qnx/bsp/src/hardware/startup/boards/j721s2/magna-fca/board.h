/*
 * $QNXLicenseC:
 * Copyright 2021, QNX Software Systems.
 * Copyright 2021, Texas Instruments Incorporated.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"). You
 * may not reproduce, modify or distribute this software except in
 * compliance with the License. You may obtain a copy of the License
 * at: http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTIES OF ANY KIND, either express or implied.
 *
 * This file may contain contributions from others, either as
 * contributors under the License or as licensors under other terms.
 * Please review this entire file for other proprietary rights or license
 * notices, as well as the QNX Development Suite License Guide at
 * http://licensing.qnx.com/license-guide/ for other information.
 * $
 */

/* This file can contain board specific preprocessor macros and function declarations */

#ifndef __BOARD_H
#define __BOARD_H

#define IDK_DDR0_BASE   0x80000000ul
#define IDK_DDR0_SIZE   (MEG(1024))     /* 1GB */
#undef IDK_DDR1_BASE
#undef IDK_DDR1_SIZE

#define CTRL_MMR0_CFG0_BASE         (0x0100000UL)

#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK0_CLKSEL          (0x8070U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK0_CLKSEL_OUT_CLK_EN       (0x100U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK1_CLKSEL          (0x8074U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK1_CLKSEL_OUT_CLK_EN       (0x100U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK2_CLKSEL          (0x8078U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK2_CLKSEL_OUT_CLK_EN       (0x100U)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK3_CLKSEL          (0x807CU)
#define CSL_MAIN_CTRL_MMR_CFG0_PCIE_REFCLK3_CLKSEL_OUT_CLK_EN       (0x100U)

#define CTRLMMR_SERDES0_CLKSEL          (0x8400U)
#define CTRLMMR_SERDES0_CLK1SEL         (0x8404U)
#define CTRLMMR_SERDES1_CLKSEL          (0x8410U)
#define CTRLMMR_SERDES1_CLK1SEL         (0x8414U)
#define CTRLMMR_SERDES2_CLKSEL          (0x8420U)
#define CTRLMMR_SERDES2_CLK1SEL         (0x8424U)
#define CTRLMMR_SERDES3_CLKSEL          (0x8430U)
#define CTRLMMR_SERDES3_CLK1SEL         (0X8434U)
#define CTRLMMR_SERDES0_LN0_CTRL        (0x4080U)
#define CTRLMMR_SERDES0_LN1_CTRL        (0x4084U)
#define CTRLMMR_SERDES0_LN2_CTRL        (0x4088U)
#define CTRLMMR_SERDES0_LN3_CTRL        (0x408CU)
#define CTRLMMR_SERDES1_LN0_CTRL        (0x4090U)
#define CTRLMMR_SERDES1_LN1_CTRL        (0x4094U)
#define CTRLMMR_SERDES1_LN2_CTRL        (0x4098U)
#define CTRLMMR_SERDES1_LN3_CTRL        (0x409CU)
#define CTRLMMR_SERDES2_LN0_CTRL        (0x40A0U)
#define CTRLMMR_SERDES2_LN1_CTRL        (0x40A4U)
#define CTRLMMR_SERDES2_LN2_CTRL        (0x40A8U)
#define CTRLMMR_SERDES2_LN3_CTRL        (0x40ACU)
#define CTRLMMR_SERDES3_LN0_CTRL        (0x40B0U)
#define CTRLMMR_SERDES3_LN1_CTRL        (0x40B4U)
#define CTRLMMR_SERDES3_LN2_CTRL        (0x40B8U)
#define CTRLMMR_SERDES3_LN3_CTRL        (0x40BCU)

#define CTRLMMR_LOCK1_KICK0             (0x5008U)
#define CTRLMMR_LOCK1_KICK1             (0x500CU)
#define CTRLMMR_LOCK2_KICK0             (0x9008U)
#define CTRLMMR_LOCK2_KICK1             (0x900CU)

#define CTRLMMR_KICK0_UNLOCK_VAL        (0x68EF3490U)
#define CTRLMMR_KICK1_UNLOCK_VAL        (0xD172BC5AU)
#define CTRLMMR_KICK0_LOCK_VAL          (0x0U)
#define CTRLMMR_KICK1_LOCK_VAL          (0x0U)
#define CTRLMMR_WAS_UNLOCKED            (0x0U)
#define CTRLMMR_WAS_LOCKED              (0x1U)

#define CTRLMMR_ACSPCIE0_CTRL           (0x18090U)
#define CTRLMMR_ACSPCIE1_CTRL           (0x18094U)

#define CTRLMMR_SERDES_CLKSEL_WKUP_HFOSC0_CLKOUT            (0x0U)
#define CTRLMMR_SERDES_CLKSEL_HFOSC1_CLKOUT                 (0x1U)
#define CTRLMMR_SERDES_CLKSEL_MAIN_PLL3_HSDIV4_CLKOUT       (0x2U)
#define CTRLMMR_SERDES_CLKSEL_MAIN_PLL2_HSDIV4_CLKOUT       (0x3U)

#define CSL_PCIE0_CORE_DBN_CFG_PCIE_CORE_BASE   (0xd000000UL)
#define CSL_SERDES_16G0_BASE            (0x5000000UL)

#define CSL_SERDES_CMN_PLLLC_LF_COEFF_MODE1_PREG__CMN_PLLLC_MODE_PREG               (0x90U)
#define CSL_SERDES_CMN_PLLLC_LF_CMN_PLLLC_LF_INTCOEFF_MODE1_PREG_SHIFT              (16U)
#define CSL_SERDES_CMN_PLLLC_LF_CMN_PLLLC_LF_PROPFRAC_MODE1_PREG_SHIFT              (20U)
#define CSL_SERDES_CMN_PLLLC_LF_CMN_PLLLC_LF_CMN_PLLLC_LF_PROPCOEFF_MODE1_PREG      (28U)

#define CSL_SERDES_CMN_PLLLC_LOCK_CNTSTART_PREG__CMN_PLLLC_LF_COEFF_MODE0_PREG      (0x94U)
#define CSL_SERDES_CMN_PLLLC_LOCK_CMN_PLLLC_LF_INTCOEFF_MODE0_PREG                  (0U)
#define CSL_SERDES_CMN_PLLLC_LOCK_CMN_PLLLC_LF_PROPFRAC_MODE0_PREG                  (4U)
#define CSL_SERDES_CMN_PLLLC_LOCK_CMN_PLLLC_LF_PROPCOEFF_MODE0_PREG                 (12U)

#define CSL_SERDES_CMN_PLLLC_BWCAL_MODE1_PREG__CMN_PLLLC_CLK0_PREG                  (0x9CU)
#define CSL_SERDES_CMN_PLLLC_BWCAL_MODE1_CMN_PLLLC_BWCAL_TMR_MODE1_PREG_SHIFT       (16U)
#define CSL_SERDES_CMN_PLLLC_BWCAL_MODE1_CMN_PLLLC_BWCAL_THRESH_MODE1_PREG_SHIFT    (24U)
#define CSL_SERDES_CMN_PLLLC_BWCAL_MODE1_CMN_PLLLC_BWCAL_EN_MODE1_PREG_SHIFT        (31U)

#define CSL_SERDES_CMN_PLLLC_DSMCORR_PREG__CMN_PLLLC_BWCAL_MODE0_PREG               (0xA0U)
#define CSL_SERDES_CMN_PLLLC_DSMCORR_PREG_CMN_PLLLC_BWCAL_TMR_MODE0_PREG_SHIFT      (0U)
#define CSL_SERDES_CMN_PLLLC_DSMCORR_PREG_CMN_PLLLC_BWCAL_THRESH_MODE0_PREG_SHIFT   (8U)
#define CSL_SERDES_CMN_PLLLC_DSMCORR_PREG_CMN_PLLLC_BWCAL_EN_MODE0_PREG_SHIFT       (15U)

#define CSL_SERDES_CTRL                 (0x404U)
#define CSL_SERDES_CTRL_POR_EN          (1 << 31)

#define CSL_SERDES_TOP_CTRL             (0x408U)
#define CSL_SERDES_TOP_CTRL_PMA_CMN_REFCLK_DIG_DIV_MASK     (0xC000000U)
#define CSL_SERDES_TOP_CTRL_PMA_CMN_REFCLK_DIG_DIV_SHIFT    (26U)
#define CSL_SERDES_TOP_CTRL_PMA_CMN_REFCLK_INT_MODE_MASK    (0x30000000U)
#define CSL_SERDES_TOP_CTRL_PMA_CMN_REFCLK_INT_MODE_SHIFT   (28U)

#define CSL_SERDES_RST                  (0x40CU)
#define CSL_SERDES_RST_REFCLK_DIG_SEL   (1 << 24)
#define CSL_SERDES_RST_PLL0_REFCLK_SEL  (1 << 28)
#define CSL_SERDES_RST_PLL1_REFCLK_SEL  (1 << 29)
#define CSL_SERDES_RST_PHY_RESET_N      (1 << 31)

#define CSL_SERDES_LANECTL0             (0x480U)
#define CSL_SERDES_LANECTL0_P0_STANDARD_MODE_MASK           (0x3000000U)
#define CSL_SERDES_LANECTL0_P0_STANDARD_MODE_SHIFT          (24U)
#define CSL_SERDES_LANECTL0_P0_FORCE_ENABLE_MASK            (0x40000000U)
#define CSL_SERDES_LANECTL0_P0_FORCE_ENABLE_SHIFT           (30U)
#define CSL_SERDES_LANECTL0_P0_ENABLE_MASK                  (0x80000000U)
#define CSL_SERDES_LANECTL0_P0_ENABLE_SHIFT                 (31U)

#define CSL_SERDES_MAX_LANES                                (0x4U)
#define SERDES_DIAG_PCIE_LANE_MASK                          (0x3U) /* All lanes are set */
#define SERDES_DIAG_PCIE_NUM_LANES                          (0x2U) //Number of lanes to be tested

#define CSL_SERDES_PCIE_GEN4                                (3U)
#define SERDES_DIAG_PCIE_GEN_TYPE                           (CSL_SERDES_PCIE_GEN4)

#define CSL_SERDES_LOOPBACK_DISABLED                        (0U)

extern struct callout_rtn   reboot_ti_sci;

extern uint8_t serdes0_sel;// = 1; /* SerDes default to PCIe0 */
extern uint8_t serdes1_sel; //= 1; /* SerDes default to PCIe1 */
extern uint8_t serdes2_sel; //= 1; /* SerDes default to PCIe2 */
extern uint8_t serdes3_sel; //= 2; /* SerDes default to USB3 */

void hw_init(void);
void hwi_j721s(void);

#endif    /* __BOARD_H */

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://svn.ott.qnx.com/product/branches/7.1.0/CE/magna/magna-fca/hardware/startup/boards/j721s2/magna-fca/board.h $ $Rev: 946157 $")
#endif
