/*
 *  Copyright (c) Texas Instruments Incorporated 2021
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*!
 * \file  enet_board_j721s2_evm.c
 *
 * \brief This file contains the implementation of J721S2 EVM support.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <ti/drv/enet/enet.h>
#include <ti/drv/enet/include/phy/enetphy.h>
#include <ti/drv/enet/include/phy/dp83867.h>
#include <ti/drv/enet/examples/utils/include/enet_board.h>
#include <ti/drv/enet/examples/utils/include/enet_apputils.h>

#include <ti/board/board.h>
#if defined(j721s2_evm)
#include <ti/board/src/j721s2_evm/include/board_pinmux.h>
#include <ti/board/src/j721s2_evm/include/board_utils.h>
#include <ti/board/src/j721s2_evm/include/board_control.h>
#include <ti/board/src/j721s2_evm/include/board_cfg.h>
#include <ti/board/src/j721s2_evm/include/board_ethernet_config.h>
#elif defined(j721s2_hyd)
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>
#include <ti/board/src/j721s2_hyd/include/board_control.h>
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_ethernet_config.h>
#else
#error No board define
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* GESI PHYs connected to Main CPSW2G MDIO (MDIO_MDC_SEL0 = MDIO_MDC_SEL1 = High) */
#define ENET_BOARD_J7XEVM_MAIN_CPSW2G_MDIO_MUX       ENET_BIT(1U)

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

static const EnetBoard_PortCfg *EnetBoard_getPortCfg(const EnetBoard_EthPort *ethPort);

static const EnetBoard_PortCfg *EnetBoard_findPortCfg(const EnetBoard_EthPort *ethPort,
                                                      const EnetBoard_PortCfg *ethPortCfgs,
                                                      uint32_t numEthPorts);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/*!
 * \brief Common Processor Board (CPB) board's DP83867 PHY configuration.
 */
static const Dp83867_Cfg gEnetCpbBoard_dp83867PhyCfg =
{
    .txClkShiftEn         = true,
    .rxClkShiftEn         = true,
    .txDelayInPs          = 2000U,  /* 2.00 ns */
    .rxDelayInPs          = 2000U,  /* 2.00 ns */
    .txFifoDepth          = 4U,
    .idleCntThresh        = 4U,     /* Improves short cable performance */
    .impedanceInMilliOhms = 35000,  /* 35 ohms */
    .gpio0Mode            = DP83867_GPIO0_LED3,
    .gpio1Mode            = DP83867_GPIO1_COL, /* Unused */
    .ledMode              =
    {
        DP83867_LED_LINKED,         /* Unused */
        DP83867_LED_LINKED_100BTX,
        DP83867_LED_RXTXACT,
        DP83867_LED_LINKED_1000BT,
    },
};

/*
 * GESI board's DP83867 PHY configuration.
 */
static const Dp83867_Cfg gEnetGesiBoard_dp83867PhyCfg =
{
    .txClkShiftEn         = true,
    .rxClkShiftEn         = true,
    .txDelayInPs          = 2750U,  /* 2.75 ns */
    .rxDelayInPs          = 2500U,  /* 2.50 ns */
    .txFifoDepth          = 4U,
    .idleCntThresh        = 4U,     /* Improves short cable performance */
    .impedanceInMilliOhms = 35000,  /* 35 ohms */
    .gpio0Mode            = DP83867_GPIO0_LED3,
    .gpio1Mode            = DP83867_GPIO1_COL, /* Unused */
    .ledMode              =
    {
        DP83867_LED_LINKED,         /* Unused */
        DP83867_LED_LINKED_100BTX,
        DP83867_LED_RXTXACT,
        DP83867_LED_LINKED_1000BT,
    },
};

/*
 * J721S2 CPB board configuration.
 *
 * 1 x RGMII PHY connected to J721S2 CPSW_2G MAC port.
 */
static const EnetBoard_PortCfg gEnetCpbBoard_j7xEthPort[] =
{
    {    /* "MCU_ENET" */
        .enetType = ENET_CPSW_2G,
        .instId   = 0U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_GMII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr         = 0U,
            .isStrapped      = false,
            .skipExtendedCfg = false,
            .extendedCfg     = &gEnetCpbBoard_dp83867PhyCfg,
            .extendedCfgSize = sizeof(gEnetCpbBoard_dp83867PhyCfg),
        },
        .flags    = 0U,
    },
};

/*
 * J721S2 GESI board configuration.
 *
 * 1 x RGMII PHY connected to J721S2 Main CPSW_2G MAC ports.
 */
static const EnetBoard_PortCfg gEnetGesiBoard_j721s2EthPort[] =
{
    {    /* "PRG0_RGMII1_B" */
        .enetType = ENET_CPSW_2G,
        .instId   = 1U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_GMII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr         = 0U,
            .isStrapped      = false,
            .skipExtendedCfg = false,
            .extendedCfg     = &gEnetGesiBoard_dp83867PhyCfg,
            .extendedCfgSize = sizeof(gEnetGesiBoard_dp83867PhyCfg),
        },
        .flags    = ENET_BOARD_J7XEVM_MAIN_CPSW2G_MDIO_MUX,
    },
};

/*
 * J721S2 virtual board used for MAC loopback setup.
 */
static const EnetBoard_PortCfg gEnetLpbkBoard_j721s2EthPort[] =
{
    {    /* CPSW_2G RGMII MAC loopback */
        .enetType = ENET_CPSW_2G,
        .instId   = 0U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_GMII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr = ENETPHY_INVALID_PHYADDR,
        },
        .flags    = 0U,
    },
    {    /* CPSW_2G RMII MAC loopback */
        .enetType = ENET_CPSW_2G,
        .instId   = 0U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_MII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr = ENETPHY_INVALID_PHYADDR,
        },
        .flags    = 0U,
    },
    {    /* Main CPSW_2G RGMII MAC loopback */
        .enetType = ENET_CPSW_2G,
        .instId   = 1U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_GMII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr = ENETPHY_INVALID_PHYADDR,
        },
        .flags    = 0U,
    },
    {    /* Main CPSW_2G RMII MAC loopback */
        .enetType = ENET_CPSW_2G,
        .instId   = 1U,
        .macPort  = ENET_MAC_PORT_1,
        .mii      = { ENET_MAC_LAYER_MII, ENET_MAC_SUBLAYER_REDUCED },
        .phyCfg   =
        {
            .phyAddr = ENETPHY_INVALID_PHYADDR,
        },
        .flags    = 0U,
    },
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

const EnetBoard_PhyCfg *EnetBoard_getPhyCfg(const EnetBoard_EthPort *ethPort)
{
    const EnetBoard_PortCfg *portCfg;

    portCfg = EnetBoard_getPortCfg(ethPort);

    return (portCfg != NULL) ? &portCfg->phyCfg : NULL;
}

static const EnetBoard_PortCfg *EnetBoard_getPortCfg(const EnetBoard_EthPort *ethPort)
{
    const EnetBoard_PortCfg *portCfg = NULL;

    if (ENET_NOT_ZERO(ethPort->boardId & ENETBOARD_CPB_ID))
    {
        portCfg = EnetBoard_findPortCfg(ethPort,
                                        gEnetCpbBoard_j7xEthPort,
                                        ENETPHY_ARRAYSIZE(gEnetCpbBoard_j7xEthPort));
    }

    if ((portCfg == NULL) &&
        ENET_NOT_ZERO(ethPort->boardId & ENETBOARD_GESI_ID))
    {
        if ((ethPort->enetType == ENET_CPSW_2G) && (ethPort->instId == 1))
        {
            portCfg = EnetBoard_findPortCfg(ethPort,
                                            gEnetGesiBoard_j721s2EthPort,
                                            ENETPHY_ARRAYSIZE(gEnetGesiBoard_j721s2EthPort));
        }
    }

    if ((portCfg == NULL) &&
        ENET_NOT_ZERO(ethPort->boardId & ENETBOARD_LOOPBACK_ID))
    {
        portCfg = EnetBoard_findPortCfg(ethPort,
                                        gEnetLpbkBoard_j721s2EthPort,
                                        ENETPHY_ARRAYSIZE(gEnetLpbkBoard_j721s2EthPort));
    }


    return portCfg;
}

static const EnetBoard_PortCfg *EnetBoard_findPortCfg(const EnetBoard_EthPort *ethPort,
                                                      const EnetBoard_PortCfg *ethPortCfgs,
                                                      uint32_t numEthPorts)
{
    const EnetBoard_PortCfg *ethPortCfg = NULL;
    bool found = false;
    uint32_t i;

    for (i = 0U; i < numEthPorts; i++)
    {
        ethPortCfg = &ethPortCfgs[i];

        if ((ethPortCfg->enetType == ethPort->enetType) &&
            (ethPortCfg->instId == ethPort->instId) &&
            (ethPortCfg->macPort == ethPort->macPort) &&
            (ethPortCfg->mii.layerType == ethPort->mii.layerType) &&
            (ethPortCfg->mii.sublayerType == ethPort->mii.sublayerType))
        {
            found = true;
            break;
        }
    }

    return found ? ethPortCfg : NULL;
}

int32_t EnetBoard_init(void)
{
    Board_initParams_t initParams;
    Board_initCfg boardCfg;
    Board_STATUS boardStatus;

    EnetAppUtils_setupSciServer();

    Board_getInitParams(&initParams);
#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1)
    initParams.uartInst      = BOARD_UART2_INSTANCE;
    initParams.uartSocDomain = BOARD_SOC_DOMAIN_MAIN;
#elif defined(BUILD_MCU1_0)
    initParams.uartInst      = BOARD_MCU_UART_INSTANCE;
    initParams.uartSocDomain = BOARD_SOC_DOMAIN_MCU;
#endif
    /* Use non-exclusive mode in board lib when accessing the module for clock enable
     * to let Linux also access the module */
    initParams.pscMode = BOARD_PSC_DEVICE_MODE_NONEXCLUSIVE;
    Board_setInitParams(&initParams);

    /* Board configuration parameters. Further configuration done explicitly (i.e. ENETCTRL) */
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    EnetAppUtils_assert(boardStatus == BOARD_SOK);

    return (boardStatus == BOARD_SOK) ? ENET_SOK : ENET_EFAIL;
}

void EnetBoard_deinit(void)
{
    Board_initCfg boardCfg;
    Board_STATUS boardStatus;
#if defined(BUILD_MCU2_0)
    int32_t enetCard = Board_detectEnetCard();
#endif

    //TODO should Enet control be reseted as part of deinit
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_deinit(boardCfg);
    EnetAppUtils_assert(boardStatus == BOARD_SOK);
}

int32_t EnetBoard_setupPorts(EnetBoard_EthPort *ethPorts,
                             uint32_t numEthPorts)
{
    Board_STATUS boardStatus;
    bool gesiDetected = false;
#if defined(BUILD_MCU2_0)
    int32_t enetCard = Board_detectEnetCard();
#endif
    uint32_t hits = 0U;
    uint32_t flags = 0U;
    uint32_t i;
    int32_t status = ENET_SOK;

    gesiDetected = Board_detectBoard(BOARD_ID_GESI);
    for (i = 0U; i < numEthPorts; i++)
    {
        EnetBoard_EthPort *ethPort = &ethPorts[i];
        const EnetBoard_PortCfg *portCfg;

        portCfg = EnetBoard_getPortCfg(ethPort);
        if (portCfg != NULL)
        {
            EnetBoard_setEnetControl(ethPort->enetType, ethPort->instId, ethPort->macPort, &ethPort->mii);
            flags |= portCfg->flags;
            hits++;
        }
    }

    EnetAppUtils_print("EnetBoard_setupPorts: %u of %u ports configurations found\n", hits, numEthPorts);

    boardStatus = Board_init(BOARD_INIT_PINMUX_CONFIG);
    EnetAppUtils_assert(boardStatus == BOARD_SOK);

    /* Check if GESI board is detected if any GESI related configuration is required */
    if (ENET_NOT_ZERO(flags & ENET_BOARD_J7XEVM_MAIN_CPSW2G_MDIO_MUX))
    {
        if (!gesiDetected)
        {
            EnetAppUtils_print("EnetBoard_setupPorts: GESI board not detected\n");
            status = ENET_EFAIL;
        }
        else
        {
            /* GESI PHY connected to Main CPSW2G MDIO */
            boardStatus = Board_control(BOARD_CTRL_CMD_SET_GESI_CPSW_MDIO_MUX, NULL);
            EnetAppUtils_assert(boardStatus == BOARD_SOK);
        }
    }

    return status;
}


void EnetBoard_setEnetControl(Enet_Type enetType,
                              uint32_t instId,
                              Enet_MacPort macPort,
                              EnetMacPort_Interface *mii)
{
    uint32_t modeSel = 0U;
    int32_t status = BOARD_FAIL;

    if (EnetMacPort_isRmii(mii))
    {
        modeSel = RMII;
    }
    else if (EnetMacPort_isRgmii(mii))
    {
        modeSel = RGMII;
    }
    else
    {
        EnetAppUtils_print("Invalid MII type: layer %u suyblayer %u\n", mii->layerType, mii->sublayerType);
        EnetAppUtils_assert(false);
    }

    switch (enetType)
    {
        case ENET_CPSW_2G:
            if (instId == 0U)
            {
                Board_unlockMMR();
                status = Board_cpsw2gMacModeConfig(modeSel);
            }
            else
            {
                status = Board_cpsw2gMainEthConfig(modeSel);
            }
            break;
        default:
            break;
    }

    EnetAppUtils_assert(status == BOARD_SOK);
}

uint32_t EnetBoard_getMacAddrList(Enet_Type enetType,
                                  uint32_t instId,
                                  uint8_t macAddr[][ENET_MAC_ADDR_LEN],
                                  uint32_t maxMacEntries)
{
    uint32_t numMacAddrs = maxMacEntries;

    if (maxMacEntries < 1U)
    {
        EnetAppUtils_print("Invalid number of requested MAC addresses\n");
        EnetAppUtils_assert(false);
    }

    switch (enetType)
    {
        case ENET_CPSW_2G:
            EnetSoc_getEFusedMacAddrs(macAddr, &numMacAddrs);
            break;

        default:
            EnetAppUtils_print("Invalid peripheral type/instId\n");
            EnetAppUtils_assert(false);
            break;
    }

    return numMacAddrs;
}
