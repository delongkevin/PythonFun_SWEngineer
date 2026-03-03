/*
 * dp83tc812.c
 *
 *  Created on: Apr 12, 2022
 *      Author: aviswakumar
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/drv/enet/include/core/enet_utils.h>
#include <ti/drv/enet/priv/core/enet_trace_priv.h>
#include <ti/drv/enet/include/phy/enetphy.h>
#include <ti/drv/enet/include/phy/dp83tc812.h>
#include "enetphy_priv.h"
#include "generic_phy.h"
#include "dp83tc812_priv.h"
#include <time.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define DP83tc812_OUI                           (0x080028U)
#define DP83tc812_MODEL                         (0x27U)
#define DP83tc812_REV                           (0x01U)

/*! \brief Control Register (CTRL) */
#define DP83TC812_CTRL                          (0x1FU)

/*! \brief RGMII Control Register (RGMIICTL) */
#define DP83TC812_RGMIICTL                      (0x600U)
/* RGMIICTL register definitions */
#define RGMIICTL_RGMIIEN                      ENETPHY_BIT(3)
#define RGMIICTL_TXCLKDLY                     ENETPHY_BIT(1)
#define RGMIICTL_RXCLKDLY                     ENETPHY_BIT(0)

/* RGMIIDCTL register definitions */
#define RGMIIDCTL_TXDLYCTRL_MASK              (0x00F0U)
#define RGMIIDCTL_TXDLYCTRL_OFFSET            (4U)
#define RGMIIDCTL_RXDLYCTRL_MASK              (0x000FU)
#define RGMIIDCTL_RXDLYCTRL_OFFSET            (0U)
#define RGMIIDCTL_DELAY_MAX                   (4000U) /* 4.00 ns */
#define RGMIIDCTL_DELAY_STEP                  (250U)  /* 0.25 ns */

/* MMD1_PMA_CTRL_2 */
#define MMD1_PMA_CTRL_2                        (0x1834U)
#define CTRL_MASTER_MODE                      ENETPHY_BIT(14)

/* CTRL register definitions */
#define CTRL_SWRESET                          ENETPHY_BIT(15)
#define CTRL_SWRESTART                        ENETPHY_BIT(14)

/* Impedance */
#define IOMUXCFG_IOIMPEDANCE_MIN_IO 45000U
#define IOMUXCFG_IOIMPEDANCE_MAX_IO 55000U
#define IOMUXCFG_IOIMPEDANCE_RANGE_IO IOMUXCFG_IOIMPEDANCE_MAX_IO - IOMUXCFG_IOIMPEDANCE_MIN_IO
#define DP83tc812_IOMUXCFG 0x456U
#define IOMUXCFG_IOIMPEDANCE_MASK_TX 0x1FU
#define IOMUXCFG_IOIMPEDANCE_MASK_RX 0x3E0U

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static bool Dp83tc812_isPhyDevSupported(EnetPhy_Handle hPhy,
                                      const EnetPhy_Version *version);

static bool Dp83tc812_isMacModeSupported(EnetPhy_Handle hPhy,
                                       EnetPhy_Mii mii);

static void Dp83tc812_printRegs(EnetPhy_Handle hPhy);

static void Dp83tc812_reset(EnetPhy_Handle hPhy);

static bool Dp83tc812_isResetComplete(EnetPhy_Handle hPhy);

static void Dp83tc812_rmwExtReg(EnetPhy_Handle hPhy,
                              uint32_t reg,
                              uint16_t mask,
                              uint16_t val);

static void Dp83tc812_setMiiMode(EnetPhy_Handle hPhy,
                               EnetPhy_Mii mii);

static int32_t Dp83tc812_config(EnetPhy_Handle hPhy,
                              const EnetPhy_Cfg *cfg,
                              EnetPhy_Mii mii);

static int32_t Dp83tc812_setOutputImpedance(EnetPhy_Handle hPhy,
                                          uint32_t impedance);

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

EnetPhy_Drv gEnetPhyDrvDp83tc812 =
{
    .name               = "dp83tc812",
    .isPhyDevSupported  = Dp83tc812_isPhyDevSupported,
    .isMacModeSupported = Dp83tc812_isMacModeSupported,
    .config             = Dp83tc812_config,
    .reset              = Dp83tc812_reset,
    .isResetComplete    = Dp83tc812_isResetComplete,
    .readExtReg         = GenericPhy_readExtReg,
    .writeExtReg        = GenericPhy_writeExtReg,
    .printRegs          = Dp83tc812_printRegs,
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void Dp83tc812_initCfg(Dp83tc812_Cfg *cfg)
{
    /* No extended config parameters at the moment */
}

static bool Dp83tc812_isPhyDevSupported(EnetPhy_Handle hPhy,
                                      const EnetPhy_Version *version)
{
    bool supported = false;

    if ((version->oui == DP83tc812_OUI) &&
        (version->model == DP83tc812_MODEL) &&
        (version->revision == DP83tc812_REV))
    {
        supported = true;
    }

    return supported;
}

static bool Dp83tc812_isMacModeSupported(EnetPhy_Handle hPhy,
                                       EnetPhy_Mii mii)
{
    bool supported;

    switch (mii)
    {
        case ENETPHY_MAC_MII_MII:
        case ENETPHY_MAC_MII_SGMII:
        case ENETPHY_MAC_MII_RGMII:
            supported = true;
            break;

        default:
            supported = false;
            break;
    }

    return supported;
}

static int32_t Dp83tc812_config(EnetPhy_Handle hPhy,
                              const EnetPhy_Cfg *cfg,
                              EnetPhy_Mii mii)
{
    //const Dp83tc812_Cfg *extendedCfg = (const Dp83tc812_Cfg *)cfg->extendedCfg;
    //uint32_t extendedCfgSize = cfg->extendedCfgSize;
    //bool enableAutoMdix;
    int32_t status = ENETPHY_SOK;
    
    #if 0
    Dp83tc812_printRegs(hPhy);
    /* Read Master / Slave Mode */
    uint16_t temp_val;

    GenericPhy_readExtReg(hPhy, 0x18BU, &temp_val);
    ENETTRACE_DBG("PHY %u: 0x18BU = 0x%04x\n", hPhy->addr, temp_val);
    //GenericPhy_writeExtReg(hPhy, 0x18BU, temp_val | ENET_BIT(6)); ALREADY in AUTO Mode
    GenericPhy_readExtReg(hPhy, 0x18BU, &temp_val);
    ENETTRACE_DBG("PHY %u: 0x18BU = 0x%04x\n", hPhy->addr, temp_val);

    EnetPhy_readReg(hPhy, MMD1_PMA_CTRL_2, &temp_val);
    ENETTRACE_DBG("PHY %u: MMD1_PMA_CTRL_2, Reg = 0x%04x, CTRL_MASTER_MODE = %d\n", hPhy->addr, temp_val, temp_val & CTRL_MASTER_MODE);
    
    /* Read Duplex and Speed */
    EnetPhy_readReg(hPhy, PHY_BMSR, &temp_val);
    ENETTRACE_DBG("PHY %u: PHY_BMSR = 0x%04x, BMSR_100FD = %d\n", hPhy->addr, temp_val, temp_val & BMSR_100FD);
    #endif

    /* Setup dp83tc812 Config Like the 83867 Config */

    /* SSet MII mode: MII or RGMII */
    if (status == ENETPHY_SOK)
    {
        Dp83tc812_setMiiMode(hPhy, mii);
    }

    uint16_t temp_val;

    /* For Hugh */
    // BMSR 1h
    ENETTRACE_DBG("PHY %u: Register Dump\n", hPhy->addr);
    EnetPhy_readReg(hPhy, PHY_BMSR, &temp_val);
    ENETTRACE_DBG("PHY %u: BMSR (0x1h) = 0x%04x\n", hPhy->addr, temp_val);
    // Register_133 133h
    GenericPhy_readExtReg(hPhy, 0x133U, &temp_val);
    ENETTRACE_DBG("PHY %u: Register_133 (0x133h) = 0x%04x\n", hPhy->addr, temp_val);
    // TC1_CFG_RW 560h
    GenericPhy_readExtReg(hPhy, 0x560U, &temp_val);
    ENETTRACE_DBG("PHY %u: TC1_CFG_RW (0x560h) = 0x%04x\n", hPhy->addr, temp_val);
    // MISR1 12h
    EnetPhy_readReg(hPhy, 0x12U, &temp_val);
    ENETTRACE_DBG("PHY %u: MISR1 (0x12h) = 0x%04x\n", hPhy->addr, temp_val);
    // MISR2 13h
    EnetPhy_readReg(hPhy, 0x13U, &temp_val);
    ENETTRACE_DBG("PHY %u: MISR2 (0x13h) = 0x%04x\n", hPhy->addr, temp_val);
    // MISR3 18h
    EnetPhy_readReg(hPhy, 0x18U, &temp_val);
    ENETTRACE_DBG("PHY %u: MISR3 (0x18h) = 0x%04x\n", hPhy->addr, temp_val);

    /* Set Impedance */
    GenericPhy_readExtReg(hPhy, DP83tc812_IOMUXCFG, &temp_val);
    ENETTRACE_DBG("PHY %u: IO_MUX_CFG (0x456) = 0x%04x\n", hPhy->addr, temp_val);
    Dp83tc812_setOutputImpedance(hPhy,45000U);
    ENETTRACE_DBG("PHY %u: Set Impedance to 45 Ohm\n", hPhy->addr);
    GenericPhy_readExtReg(hPhy, DP83tc812_IOMUXCFG, &temp_val);
    ENETTRACE_DBG("PHY %u: IO_MUX_CFG (0x456) = 0x%04x\n", hPhy->addr, temp_val);

    nanospin_ns(1000);

    /* Print Out RGMII_CTL Register */
    GenericPhy_readExtReg(hPhy, 0x600U, &temp_val);
    ENETTRACE_DBG("PHY %u: RGMII_CTRL (0x600) = 0x%04x\n", hPhy->addr, temp_val);
    if(temp_val & ENETPHY_BIT(3)){
        ENETTRACE_DBG("PHY %u: RGMII Enable = 1\n", hPhy->addr);    
    }
    else{
        ENETTRACE_DBG("PHY %u: RGMII_CTRL (0x600) = 0x%04x\n", hPhy->addr, temp_val);
        ENETTRACE_DBG("PHY %u: RGMII Enable = 0\n", hPhy->addr);
    }

    GenericPhy_readExtReg(hPhy, 0x602U, &temp_val);
    ENETTRACE_DBG("PHY %u: RGMII_CLK_SHIFT_CTRL (0x602) = 0x%04x\n", hPhy->addr, temp_val);
    GenericPhy_writeExtReg(hPhy, 0x602U, temp_val | ENET_BIT(0));
    GenericPhy_readExtReg(hPhy, 0x602U, &temp_val);
    ENETTRACE_DBG("PHY %u: RGMII_CLK_SHIFT_CTRL (0x602) = 0x%04x\n", hPhy->addr, temp_val);
    
    GenericPhy_readExtReg(hPhy, 0x430U, &temp_val);
    ENETTRACE_DBG("PHY %u: A2D_REG_48 (0x430) = 0x%04x\n", hPhy->addr, temp_val);
    GenericPhy_readExtReg(hPhy, 0x430U, &temp_val);
    ENETTRACE_DBG("PHY %u: A2D_REG_48 (0x430) = 0x%04x\n", hPhy->addr, temp_val);

    /* Read PHYRCR */
    EnetPhy_readReg(hPhy, 0x1FU, &temp_val);
    ENETTRACE_DBG("PHY %u: PHYRCR (0x1F) = 0x%04x\n", hPhy->addr, temp_val);

    #if 0
    /* Config RGMII TX and RX clock shift and clock delay */
    if ((status == ENETPHY_SOK) &&
        (mii == ENETPHY_MAC_MII_RGMII))
    {
        Dp83tc812_setClkShift(hPhy,
                            false,
                            true);

        status = Dp83tc812_setClkDelay(hPhy,
                                     2000U,
                                     2000U);
    }
    #endif

    return status;
}

static void Dp83tc812_reset(EnetPhy_Handle hPhy)
{
    /* Global software reset: all PHY internal circuits including IEEE-defined
     * registers and all extended registers are reset */
    ENETTRACE_DBG("PHY %u: global soft-reset\n", hPhy->addr);
    EnetPhy_rmwReg(hPhy, DP83TC812_CTRL, CTRL_SWRESET, CTRL_SWRESET);
}

static bool Dp83tc812_isResetComplete(EnetPhy_Handle hPhy)
{
    int32_t status;
    uint16_t val;
    bool complete = false;

    /* Reset is complete when RESET bit has self-cleared */
    status = EnetPhy_readReg(hPhy, DP83TC812_CTRL, &val);
    if (status == ENETPHY_SOK)
    {
        complete = ((val & CTRL_SWRESET) == 0U);
    }

    ENETTRACE_DBG("PHY %u: global soft-reset is %scomplete\n", hPhy->addr, complete ? "" : "not");

    return complete;
}

static void Dp83tc812_setMiiMode(EnetPhy_Handle hPhy,
                               EnetPhy_Mii mii)
{
    uint16_t val = 0U;

    ENETTRACE_DBG("PHY %u: MII mode: %u\n", hPhy->addr, mii);

    if (mii == ENETPHY_MAC_MII_RGMII)
    {
        val = RGMIICTL_RGMIIEN;
    }

    Dp83tc812_rmwExtReg(hPhy, DP83TC812_RGMIICTL, val, RGMIICTL_RGMIIEN);
}

static int32_t Dp83tc812_setOutputImpedance(EnetPhy_Handle hPhy,
                                          uint32_t impedance)
{
    int32_t status = ENETPHY_SOK;
    uint32_t val;

    if ((impedance >= IOMUXCFG_IOIMPEDANCE_MIN_IO) &&
        (impedance <= IOMUXCFG_IOIMPEDANCE_MAX_IO))
    {
        ENETTRACE_DBG("PHY %u: set output impedance to %u milli-ohms\n", hPhy->addr, impedance);

        val = (IOMUXCFG_IOIMPEDANCE_MAX_IO - impedance) * IOMUXCFG_IOIMPEDANCE_MASK_TX;
        val = (val + IOMUXCFG_IOIMPEDANCE_MIN_IO / 2) / IOMUXCFG_IOIMPEDANCE_RANGE_IO;

        Dp83tc812_rmwExtReg(hPhy, DP83tc812_IOMUXCFG,
                          IOMUXCFG_IOIMPEDANCE_MASK_TX,
                          val);
        Dp83tc812_rmwExtReg(hPhy, DP83tc812_IOMUXCFG,
                          IOMUXCFG_IOIMPEDANCE_MASK_RX,
                          val);
    }
    else
    {
        ENETTRACE_ERR("PHY %u: out-of-range impedance: %u\n", hPhy->addr, impedance);
        status = ENETPHY_EINVALIDPARAMS;
    }

    return status;
}

static void Dp83tc812_rmwExtReg(EnetPhy_Handle hPhy,
                              uint32_t reg,
                              uint16_t mask,
                              uint16_t val)
{
    uint16_t devad = MMD_CR_DEVADDR;
    uint16_t data;
    int32_t status;

    ENETTRACE_VERBOSE("PHY %u: write reg %u mask 0x%04x val 0x%04x\n",
                      hPhy->addr, reg, mask, val);

    EnetPhy_writeReg(hPhy, PHY_MMD_CR, devad | MMD_CR_ADDR);
    EnetPhy_writeReg(hPhy, PHY_MMD_DR, reg);
    EnetPhy_writeReg(hPhy, PHY_MMD_CR, devad | MMD_CR_DATA_NOPOSTINC);
    status = EnetPhy_readReg(hPhy, PHY_MMD_DR, &data);

    if (status == ENETPHY_SOK)
    {
        data = (data & ~mask) | (val & mask);
        EnetPhy_writeReg(hPhy, PHY_MMD_CR, devad | MMD_CR_DATA_NOPOSTINC);
        EnetPhy_writeReg(hPhy, PHY_MMD_DR, data);
    }
}

static void Dp83tc812_printRegs(EnetPhy_Handle hPhy)
{
    uint32_t phyAddr = hPhy->addr;
    uint16_t val;

    EnetPhy_readReg(hPhy, PHY_BMCR, &val);
    EnetUtils_printf("PHY %u: BMCR    = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_BMSR, &val);
    EnetUtils_printf("PHY %u: BMSR    = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_PHYIDR1, &val);
    EnetUtils_printf("PHY %u: PHYIDR1 = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_PHYIDR2, &val);
    EnetUtils_printf("PHY %u: PHYIDR2 = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_ANAR, &val);
    EnetUtils_printf("PHY %u: ANAR    = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_ANLPAR, &val);
    EnetUtils_printf("PHY %u: ANLPAR  = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_ANER, &val);
    EnetUtils_printf("PHY %u: ANER    = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_ANNPTR, &val);
    EnetUtils_printf("PHY %u: ANNPTR  = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_ANNPRR, &val);
    EnetUtils_printf("PHY %u: ANNPRR  = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, DP83TC812_CR1, &val);
    EnetUtils_printf("PHY %u: CR1     = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_GIGSR, &val);
    EnetUtils_printf("PHY %u: STS1    = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, PHY_GIGESR, &val);
    EnetUtils_printf("PHY %u: 1KSCR   = 0x%04x\n", phyAddr, val);
    EnetPhy_readReg(hPhy, DP83TC812_PHYCR, &val);
    EnetUtils_printf("PHY %u: PHYCR   = 0x%04x\n", phyAddr, val);
}
