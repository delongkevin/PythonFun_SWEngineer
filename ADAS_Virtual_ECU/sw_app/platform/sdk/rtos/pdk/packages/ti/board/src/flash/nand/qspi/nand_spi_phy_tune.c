/*
 * Copyright (c) 2020, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nand the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/board/src/flash/nand/nand.h>
#include <ti/board/src/flash/nand/qspi/nand_qspi.h>
#include <ti/board/src/flash/nand/qspi/nand_spi_phy_tune.h>
#include <ti/board/src/flash/nand/qspi/nand_qspi_utils.h>

#include <ti/drv/spi/test/src/SPI_log.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

extern void UART_printf(const char *pcString, ...);

//#define NAND_SPI_TUNE_DEBUG


#ifdef NAND_SPI_TUNE_DEBUG
#define NAND_log SPI_log
uint32_t nandSpiTuneCnt = 0;
#endif

#ifdef NAND_SPI_TUNE_PROFILE
#define NAND_log UART_printf
#endif

/* Enables a "Grid Search" routine which can be used for debugging. This will scan through all possible 
   txDLL and rxDLL values for readDelay values of 0-3 and print a 2D pass/fail map for each readDelay value.
   This corresponds to the 2D plots in the TI OSPI PHY Tuning App note. */
// #define ENABLE_DLL_GRID_SEARCH

static const NAND_PhyConfig defaultPhyTuning =
{
    40,
    40,
    0,
    PHY_CONFIG_MAGIC_VALUE_TUNING_UNTUNED
};

/* TODO (amendola) move gNandDtrStrTuningPoint to a new, designated section in DDR or other RAM that isn't re-initialized
   in the Boot App to allow the Boot App to reuse the PHY tuning from the SBL */
NAND_PhyConfig gNandDtrStrTuningPoint __attribute__((section(".ospi_phy_tuning_data")));

static void NAND_spiRdDelayConfig(OSPI_Handle handle, uint32_t rdDelay)
{
    OSPI_v0_HwAttrs* hwAttrs = (OSPI_v0_HwAttrs *)handle->hwAttrs;

    CSL_ospiSetDataReadCapDelay((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr), rdDelay);
}

static void NAND_spiTxRxDllConfig(OSPI_Handle handle, uint32_t txDLL, uint32_t rxDLL)
{
    uint32_t data[3];

    data[0] = TRUE;
    data[1] = txDLL;
    data[2] = rxDLL;

    OSPI_control(handle, OSPI_V0_CMD_CFG_PHY, (void *)data);
}

static void NAND_spiPhyConfig(OSPI_Handle handle, NAND_PhyConfig phyConfig)
{
#ifdef NAND_SPI_TUNE_DEBUG
    SPI_log("Configuring PHY: txDLL=%d, rxDLL=%d, delay=%d\n", phyConfig.txDLL, phyConfig.rxDLL, phyConfig.rdDelay);
#endif  // NAND_SPI_TUNE_DEBUG
    NAND_spiRdDelayConfig(handle, phyConfig.rdDelay);
    NAND_spiTxRxDllConfig(handle, phyConfig.txDLL, phyConfig.rxDLL);
}

static uint32_t rdBuf[NAND_ATTACK_VECTOR_SIZE/sizeof(uint32_t)];

void NAND_spiPhyDllObserve(OSPI_Handle handle);

static NAND_STATUS NAND_spiPhyRdAttack(OSPI_Handle handle, uintptr_t flashVectorAddr)
{
    NAND_STATUS        status = NAND_PASS;
    uint32_t          i;
    volatile uint8_t *pByte = (volatile uint8_t *)rdBuf;

    /* Set transfer mode and read type */
    uint32_t transferType = SPI_TRANSACTION_TYPE_READ;
    OSPI_control(handle, OSPI_V0_CMD_SET_XFER_MODE, NULL);
    OSPI_control(handle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
    
    OSPI_Transaction transaction;

    transaction.arg   = (void *)(uintptr_t)0U;
    transaction.txBuf = NULL;
    transaction.rxBuf = (void *)(rdBuf);
    transaction.count = NAND_ATTACK_VECTOR_SIZE;

    int32_t ret = Nand_qspiOptimizedQuadRead(handle, &transaction);

    if (ret == false)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    for (i = 0; i < NAND_ATTACK_VECTOR_SIZE; i++)
    {
        if (pByte[i] != nand_attack_vector[i])
        {
            status = NAND_FAIL;
            break;
        }
    }
    return (status);
}

static NAND_STATUS NAND_spiPhyRdAttack2(OSPI_Handle handle, uintptr_t flashVectorAddr, NAND_PhyConfig config)
{
    NAND_STATUS        status = NAND_PASS;
    uint32_t          i;
    volatile uint8_t *pByte = (volatile uint8_t *)rdBuf;

    /* PHY Tuning test vector must be programmed at a block (and therefore page) boundary. */
    OSPI_v0_HwAttrs *hwAttrs = (OSPI_v0_HwAttrs*)handle->hwAttrs;
    while (!CSL_ospiIsIdle((const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr)));

    NAND_spiPhyConfig(handle, config);

    /* Set transfer mode and read type */
    uint32_t transferType = SPI_TRANSACTION_TYPE_READ;
    OSPI_control(handle, OSPI_V0_CMD_SET_XFER_MODE, NULL);
    OSPI_control(handle, OSPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);
    
    OSPI_Transaction transaction;

    transaction.arg   = (void *)(uintptr_t)0U;
    transaction.txBuf = NULL;
    transaction.rxBuf = (void *)(rdBuf);
    transaction.count = NAND_ATTACK_VECTOR_SIZE;

    int32_t ret = OSPI_transfer(handle, &transaction);
    if (ret == false)
    {
        SPI_log("\n Failure in %s at line %d \n", __func__, __LINE__);
        return NAND_FAIL;
    }

    for (i = 0; i < NAND_ATTACK_VECTOR_SIZE; i++)
    {
        if (pByte[i] != nand_attack_vector[i])
        {
            status = NAND_FAIL;
            break;
        }
    }
    return (status);
}

static bool resultsTable[128][128];

void Nand_gridSearch(OSPI_Handle handle, uint32_t offset)
{
    OSPI_v0_HwAttrs const        *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    bool save_dtr_enable = hwAttrs->dtrEnable;

    Nand_enterSpiMode(handle, true, false);

    /* Set Flash device to Continuous read mode. */
    uint32_t pageidx = (hwAttrs->dataAddr + offset) / NAND_PAGE_SIZE;

    /* Send page read command for first page of test data. */
    NAND_SendPageReadCmd(handle, pageidx);

    Nand_enterQspiMode(handle, true, true, save_dtr_enable);

    SPI_log("\nDoing grid searches...\n");

    uint32_t rddel;
    for (rddel = 0; rddel < 3; ++rddel)
    {
        int32_t txdel;
        int32_t rxdel;
        for (txdel = 127; txdel >= 0; txdel -= 1)
        {
            for (rxdel = 0; rxdel < 128; rxdel += 1)
            {
                NAND_PhyConfig config =
                {
                    txdel, 
                    rxdel,
                    rddel
                };
                resultsTable[txdel][rxdel] = (bool)NAND_spiPhyRdAttack2(handle, hwAttrs->dataAddr + offset, config);

            }
        }
        int32_t txdelprint;
        int32_t rxdelprint;
        SPI_log("\n\n RESULTS FOR rddel = %d - rxDLL increases L->R, txDLL increases down->up\n", rddel);
        for(txdelprint = 127; txdelprint >= 0; --txdelprint)
        {
            SPI_log("txDLL=%03d: ", txdelprint);
            for (rxdelprint = 0; rxdelprint < 128; ++rxdelprint)
            {
                SPI_log("%d", resultsTable[txdelprint][rxdelprint]);
            }
            SPI_log("\n");
        }

    }
}

/*
 * Searches txDLL down from start until the tuning basis passes.
 * Does not look at the next rdDelay setting.  Returns txDLL=128 if fail.
 */
NAND_PhyConfig NAND_spiPhyFindTxHigh(OSPI_Handle handle, NAND_PhyConfig start, uint32_t offset)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    NAND_STATUS             status;

    NAND_spiPhyConfig(handle, start);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    while(status == NAND_FAIL)
    {
        start.txDLL--;
        if(start.txDLL < 48U)
        {
            start.txDLL = 128U;
            break;
        }
        NAND_spiPhyConfig(handle, start);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    return start;
}

/*
 * Searches txDLL up from start until the tuning basis passes.
 * Does not look at the next rdDelay setting.  Returns txDLL=128 if fail.
 */
NAND_PhyConfig NAND_spiPhyFindTxLow(OSPI_Handle handle, NAND_PhyConfig start, uint32_t offset)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    NAND_STATUS             status;


    NAND_spiPhyConfig(handle, start);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + (uintptr_t)offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    while(status == NAND_FAIL)
    {
        start.txDLL++;
        if (start.txDLL > 32U)
        {
            start.txDLL = 128U;
            break;
        }
        NAND_spiPhyConfig(handle, start);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    return start;
}

/*
 * Searches rxDLL down from start until the tuning basis passes.
 * Does not look at the next rdDelay setting.  Returns rxDLL=128 if fail.
 */
NAND_PhyConfig NAND_spiPhyFindRxHigh(OSPI_Handle handle, NAND_PhyConfig start, uint32_t offset)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    NAND_STATUS             status;

    NAND_spiPhyConfig(handle, start);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    while(status == NAND_FAIL)
    {
        start.rxDLL--;
        if(start.rxDLL < 25U)
        {
            start.rxDLL = 128U;
            break;
        }
        NAND_spiPhyConfig(handle, start);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    return start;
}

/*
 * Searches rxDLL up from start until the tuning basis passes.
 * Does not look at the next rdDelay setting. Returns rxDLL=128 if fail.
 */
NAND_PhyConfig NAND_spiPhyFindRxLow(OSPI_Handle handle, NAND_PhyConfig start, uint32_t offset)
{
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    NAND_STATUS             status;

    NAND_spiPhyConfig(handle, start);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    while(status == NAND_FAIL)
    {

        start.rxDLL++;
        if(start.rxDLL > 10U)
        {
            start.rxDLL = 128U;
            break;
        }
        NAND_spiPhyConfig(handle, start);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    return start;
}

double NAND_spiPhyAvgVtmTemp(double vtm125){
    double   avg = 0;
    double   m = 0;
    double   b = 0;
    uint32_t temp;
    uint32_t j;
    uint32_t statReg; /* VTM temperature sensor status register addr */
    uint32_t ctrlReg; /* VTM temperature sensor control register addr */

#if defined (SOC_J721E) || defined (SOC_J7200) || defined(SOC_J721S2)
    statReg = CSL_WKUP_VTM0_MMR_VBUSP_CFG1_BASE + 0x308U;
    ctrlReg = CSL_WKUP_VTM0_MMR_VBUSP_CFG2_BASE + 0x300U;
#elif defined (SOC_AM65XX)
    statReg = CSL_WKUP_VTM0_CFG0_BASE + 0x308U;
    ctrlReg = CSL_WKUP_VTM0_CFG1_BASE + 0x300U;
#else
    statReg = CSL_VTM0_MMR_VBUSP_CFG1_BASE + 0x308U;
    ctrlReg = CSL_VTM0_MMR_VBUSP_CFG2_BASE + 0x300U;
#endif
    /* Take the average VTM value */
    for (j = 0; j < 5U; j++)
    {
        uintptr_t pCtrl = (uintptr_t)(ctrlReg + (j * 0x20U));
        uintptr_t pStat = (uintptr_t)(statReg + (j * 0x20U));

        /* Setting sensor to continous readout mode. */
        CSL_REG32_WR(pCtrl, (CSL_REG32_RD(pCtrl) & ~0x10U) | (1U << 4U));
        CSL_REG32_WR(pCtrl, (CSL_REG32_RD(pCtrl) & ~0x10U) | (1U << 4U));

        /* Read from pStat register to get temp */
        temp = CSL_REG32_RD(pStat) & 0x3FFU;

        /* Accumlate a number to average */
        avg += temp;
    }
    avg=avg/5U;
    /* Convert to a temperature */
    m = 160U/(vtm125-43U);
    b = (125U/m)-vtm125;
    avg = m*(avg+b);

    return avg;
}

/* Fast tuning in DDR mode (DQS enabled) */
NAND_STATUS Nand_spiPhyDdrTune(OSPI_Handle handle, uint32_t offset)
{
    NAND_STATUS             status;
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    NAND_PhyConfig          searchPoint;
    NAND_PhyConfig          bottomLeft;
    NAND_PhyConfig          topRight;
    NAND_PhyConfig          gapLow;
    NAND_PhyConfig          gapHigh;
    NAND_PhyConfig          rxLow, rxHigh, txLow, txHigh, temp, left, right;
    int32_t                rdDelay;
    // float                  temperature = 0;
    float                  length1,length2;
#ifdef ENABLE_DLL_GRID_SEARCH
    SPI_log("\n ------ EXPECTED test buffer ------\n");
    PrintBuffer((uint8_t*)nand_attack_vector, NAND_ATTACK_VECTOR_SIZE);

    Nand_gridSearch(handle, offset);
#endif

    bool save_dtr_enable = hwAttrs->dtrEnable;

    Nand_enterSpiMode(handle, true, false);

    uint32_t pageidx = (hwAttrs->dataAddr + offset) / NAND_PAGE_SIZE;

    /* Send page read command for test data. */
    NAND_SendPageReadCmd(handle, pageidx);

    Nand_enterQspiMode(handle, true, true, save_dtr_enable);


    /*
     * Bottom left corner is present in initial rdDelay value and search from there.
     * Can be adjusted to save time.
     */
    rdDelay = 0U;

    /*
     * Finding RxDLL fails at some of the TxDLL values based on the HW platform.
     * A window of TxDLL values is used to find the RxDLL without errors.
     * This can increase the number of CPU cycles taken for the PHY tuning
     * in the cases where more TxDLL values need to be parsed to find a stable RxDLL.
     *
     * Update NAND_SPI_PHY_TXDLL_LOW_WINDOW_START based on the TxDLL value where
     * stable RxDLL can be found consistently for a given platform and
     * define the macro NAND_DISABLE_TXDLL_WINDOW after fixing TxDLL value
     * to reduce the time taken for PHY tuning.
     */
#if !defined(NAND_DISABLE_TXDLL_WINDOW)
    /* Look for rxDLL boundaries at a txDLL Window to find rxDLL Min */
    searchPoint.txDLL = NAND_SPI_PHY_TXDLL_LOW_WINDOW_START;
    while(searchPoint.txDLL <= NAND_SPI_PHY_TXDLL_LOW_WINDOW_END)
    {
        searchPoint.rdDelay = rdDelay;
        searchPoint.rxDLL   = 0;
        rxLow = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
        while(rxLow.rxDLL == 128U)
        {

            searchPoint.rdDelay++;
            if(searchPoint.rdDelay > 4U)
            {
                if(searchPoint.txDLL >= NAND_SPI_PHY_TXDLL_LOW_WINDOW_END)
                {
#ifdef NAND_SPI_TUNE_DEBUG
                    NAND_log("Unable to find RX Min\n");
#endif
                    return NAND_FAIL;
                }
                else
                {
                    break;
                }
            }
            rxLow = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
        }

        if(rxLow.rxDLL != 128U)
        {
            break;
        }

        searchPoint.txDLL++;
    }
#else

    /* Look for rxDLL boundaries at txDLL = 16 to find rxDLL Min */
    searchPoint.rdDelay = rdDelay;
    searchPoint.txDLL = NAND_SPI_PHY_TXDLL_LOW_WINDOW_START;
    searchPoint.rxDLL = 0U;
    rxLow = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
    while(rxLow.rxDLL == 128U)
    {

        searchPoint.rdDelay++;
        if(searchPoint.rdDelay > 4U)
        {
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("Unable to find RX Min\n");
#endif
            return NAND_FAIL;
        }
        rxLow = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
    }
#endif  /* #if !defined(NAND_DISABLE_TXDLL_WINDOW) */

    /* Find rxDLL Max at a txDLL */
    searchPoint.rxDLL = 127U;
    rxHigh = NAND_spiPhyFindRxHigh(handle, searchPoint, offset);
    while(rxHigh.rxDLL == 128U)
    {

        searchPoint.rdDelay++;
        if(searchPoint.rdDelay > 4U)
        {
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("Unable to find RX Min\n");
#endif
            return NAND_FAIL;
        }
        rxHigh = NAND_spiPhyFindRxHigh(handle, searchPoint, offset);
    }

    /*
     * Check a different point if the rxLow and rxHigh are on the same rdDelay.
     * This avoids mistaking the metastability gap for an rxDLL boundary
     */
    if (rxLow.rdDelay == rxHigh.rdDelay)
    {
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("rxLow and rxHigh are on the same rdDelay\n");
#endif

    /*
     * Finding RxDLL fails at some of the TxDLL values based on the HW platform.
     * A window of TxDLL values is used to find the RxDLL without errors.
     * This can increase the number of CPU cycles taken for the PHY tuning
     * in the cases where more TxDLL values need to be parsed to find a stable RxDLL.
     *
     * Update NAND_SPI_PHY_TXDLL_HIGH_WINDOW_START based on the TxDLL value where
     * stable RxDLL can be found consistently for a given platform and
     * define the macro NAND_DISABLE_TXDLL_WINDOW after fixing TxDLL value
     * to reduce the time taken for PHY tuning.
     */
#if !defined(NAND_DISABLE_TXDLL_WINDOW)
        /* Look for rxDLL boundaries at a txDLL Window */
        searchPoint.txDLL = NAND_SPI_PHY_TXDLL_HIGH_WINDOW_START;

        /* Find rxDLL Min. Start txDLL at window end and reduce txDLL until a passing rxDLL is found */
        while(searchPoint.txDLL >= NAND_SPI_PHY_TXDLL_HIGH_WINDOW_END)
        {
            searchPoint.rdDelay = rdDelay;
            searchPoint.rxDLL   = 0;
            temp = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
            while(temp.rxDLL == 128U)
            {
                searchPoint.rdDelay++;
                if(searchPoint.rdDelay > 4U)
                {
                    if(searchPoint.txDLL <= NAND_SPI_PHY_TXDLL_HIGH_WINDOW_END)
                    {
#ifdef NAND_SPI_TUNE_DEBUG
                        NAND_log("Unable to find RX Min\n");
#endif
                        return NAND_FAIL;
                    }
                    else
                    {
                        break;
                    }
                }
                temp = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
            }

            if(temp.rxDLL != 128U)
            {
                break;
            }

            searchPoint.txDLL--;
        }

#else
        /* Look for rxDLL boundaries at txDLL=48 */
        searchPoint.rdDelay = rdDelay;
        searchPoint.txDLL = NAND_SPI_PHY_TXDLL_HIGH_WINDOW_START;
        searchPoint.rxDLL = 0;

        /* Find rxDLL Min */
        temp = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
        while(temp.rxDLL == 128U)
        {
            searchPoint.rdDelay++;
            if(searchPoint.rdDelay > 4U)
            {
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("Unable to find RX Min\n");
#endif
                return NAND_FAIL;
            }
            temp = NAND_spiPhyFindRxLow(handle, searchPoint, offset);
        }
#endif

        if(temp.rxDLL<rxLow.rxDLL)
        {
            rxLow = temp;
        }

        /* Find rxDLL Max */
        searchPoint.rxDLL = 127U;
        temp = NAND_spiPhyFindRxHigh(handle, searchPoint, offset);
        while(temp.rxDLL == 128U)
        {
            searchPoint.rdDelay++;
            if(searchPoint.rdDelay > 4U)
            {
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("Unable to find RX Max\n");
#endif
                return NAND_FAIL;
            }
            temp = NAND_spiPhyFindRxHigh(handle, searchPoint, offset);
        }
        if(temp.rxDLL > rxHigh.rxDLL)
        {
            rxHigh = temp;
        }
    }

    /*
     * Look for txDLL boundaries at 1/4 of rxDLL window
     * Find txDLL Min
     */
    searchPoint.rdDelay = rdDelay;
    searchPoint.rxDLL = (rxHigh.rxDLL+rxLow.rxDLL)/4U;
    searchPoint.txDLL = 0U;
    txLow = NAND_spiPhyFindTxLow(handle,searchPoint,offset);
    while(txLow.txDLL==128U)
    {
        searchPoint.rdDelay++;
        txLow = NAND_spiPhyFindTxLow(handle,searchPoint,offset);
        if(searchPoint.rdDelay>4U)
        {
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("Unable to find TX Min\n");
#endif
            return NAND_FAIL;
        }
    }

    /* Find txDLL Max */
    searchPoint.txDLL = 127U;
    txHigh = NAND_spiPhyFindTxHigh(handle,searchPoint,offset);
    while(txHigh.txDLL==128U)
    {
        searchPoint.rdDelay++;
        txHigh = NAND_spiPhyFindTxHigh(handle,searchPoint,offset);
        if(searchPoint.rdDelay>4U){
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("Unable to find TX Max\n");
#endif
            return NAND_FAIL;
        }
    }

    /*
     * Check a different point if the txLow and txHigh are on the same rdDelay.
     * This avoids mistaking the metastability gap for an rxDLL boundary
     */
    if(txLow.rdDelay==txHigh.rdDelay)
    {
        /* Look for txDLL boundaries at 3/4 of rxDLL window
           Find txDLL Min */
        searchPoint.rdDelay = rdDelay;
        searchPoint.rxDLL = 3U*(rxHigh.rxDLL+rxLow.rxDLL)/4U;
        searchPoint.txDLL = 0U;
        temp = NAND_spiPhyFindTxLow(handle,searchPoint,offset);
        while(temp.txDLL==128U)
        {
            searchPoint.rdDelay++;
            temp = NAND_spiPhyFindTxLow(handle,searchPoint,offset);
            if(searchPoint.rdDelay>4U)
            {
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("Unable to find TX Min\n");
#endif
                return NAND_FAIL;
            }
        }
        if(temp.txDLL<txLow.txDLL)
        {
            txLow = temp;
        }

        /* Find txDLL Max */
        searchPoint.txDLL = 127U;
        temp = NAND_spiPhyFindTxHigh(handle,searchPoint,offset);
        while(temp.txDLL==128U)
        {
            searchPoint.rdDelay++;
            temp = NAND_spiPhyFindTxHigh(handle,searchPoint,offset);
            if(searchPoint.rdDelay>4U)
            {
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("Unable to find TX Max\n");
#endif
                return NAND_FAIL;
            }
        }
        if(temp.txDLL>txHigh.txDLL)
        {
            txHigh = temp;
        }
    }

    /*
     * Set bottom left and top right right corners.  These are theoretical corners. They may not actually be "good" points.
     * But the longest diagonal of the shmoo will be between these corners.
     */
    /* Bottom Left */
    bottomLeft.txDLL = txLow.txDLL;
    bottomLeft.rxDLL = rxLow.rxDLL;
    if(txLow.rdDelay<=rxLow.rdDelay)
    {
        bottomLeft.rdDelay = txLow.rdDelay;
    }
    else
    {
        bottomLeft.rdDelay = rxLow.rdDelay;
    }
    temp = bottomLeft;
    temp.txDLL += 4U;
    temp.rxDLL += 4U;
    NAND_spiPhyConfig(handle, temp);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    if(status == NAND_FAIL)
    {
        temp.rdDelay--;
        NAND_spiPhyConfig(handle, temp);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    if (status == NAND_PASS)
    {
        bottomLeft.rdDelay = temp.rdDelay;
    }

    /* Top Right */
    topRight.txDLL = txHigh.txDLL;
    topRight.rxDLL = rxHigh.rxDLL;
    if(txHigh.rdDelay>=rxHigh.rdDelay)
    {
        topRight.rdDelay = txHigh.rdDelay;
    }
    else
    {
        topRight.rdDelay = rxHigh.rdDelay;
    }
    temp = topRight;
    temp.txDLL -= 4U;
    temp.rxDLL -= 4U;
    NAND_spiPhyConfig(handle, temp);
    status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
    nandSpiTuneCnt++;
#endif
    if(status == NAND_FAIL)
    {
        temp.rdDelay++;
        NAND_spiPhyConfig(handle, temp);
        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    }
    if(status == NAND_PASS)
    {
        topRight.rdDelay = temp.rdDelay;
    }

    left  = bottomLeft;
    right = topRight;

    searchPoint.txDLL = left.txDLL + ((right.txDLL - left.txDLL) / 2);
    searchPoint.rxDLL = left.rxDLL + ((right.rxDLL - left.rxDLL) / 2);
    searchPoint.rdDelay = left.rdDelay;

    do
    {
        NAND_spiPhyConfig(handle,searchPoint);

        status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
        if(status == NAND_FAIL)
        {
            /*
             * Since we couldn't find the pattern, we need to go the
             * the upper half.
             */
            right.txDLL = searchPoint.txDLL;
            right.rxDLL = searchPoint.rxDLL;
            
            searchPoint.txDLL = left.txDLL + ((searchPoint.txDLL - left.txDLL)/2);
            searchPoint.rxDLL = left.rxDLL + ((searchPoint.rxDLL - left.rxDLL)/2);
        }
        else
        {
            /*
             * Since we found the pattern, we need to go to the
             * lower half.
             */
            left.txDLL = searchPoint.txDLL;
            left.rxDLL = searchPoint.rxDLL;
            
            searchPoint.txDLL = searchPoint.txDLL + ((right.txDLL - searchPoint.txDLL)/2);
            searchPoint.rxDLL = searchPoint.rxDLL + ((right.rxDLL - searchPoint.rxDLL)/2);
        }
#ifdef NAND_SPI_TUNE_DEBUG
        nandSpiTuneCnt++;
#endif
    /* Break the loop if the window has closed. */
    } while ((right.txDLL - left.txDLL >= 2) && (right.rxDLL - left.rxDLL >= 2));
    gapLow = searchPoint;

    /* If there's only one segment, put tuning point in the middle and adjust for temperature */
    if(bottomLeft.rdDelay==topRight.rdDelay)
    {
        //The "true" top right corner was too small to find, so the start of the metastability gap is a good approximation
        topRight = gapLow;
        searchPoint.rdDelay = bottomLeft.rdDelay;
        searchPoint.txDLL = (bottomLeft.txDLL+topRight.txDLL)/2U;
        searchPoint.rxDLL = (bottomLeft.rxDLL+topRight.rxDLL)/2U;
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("Only one passing window found, from txDLL,rxDLL of %d,%d to %d,%d, and a rdDelay of %d\n",bottomLeft.txDLL, bottomLeft.rxDLL,  topRight.txDLL, topRight.rxDLL,   topRight.rdDelay);
#endif

        /* TODO (amendola) enable temperature compensation. Need to:
            - Get NAND_spiPhyAvgVtmTemp() working
            - Confirm that the existing formula applies to this system.
        */
        // temperature = NAND_spiPhyAvgVtmTemp(NAND_SPI_PHY_VTM_TARGET);
        // searchPoint.txDLL+= (topRight.txDLL-bottomLeft.txDLL)*(0.5*(temperature-42.5)/165U);
        // searchPoint.rxDLL+= (topRight.rxDLL-bottomLeft.rxDLL)*(0.5*(temperature-42.5)/165U);
    }
    else
    {
        /* If there are two segments, find the start and end of the second one */

        left  = bottomLeft;
        right = topRight;

        searchPoint.txDLL = left.txDLL + ((right.txDLL - left.txDLL) / 2);
        searchPoint.rxDLL = left.rxDLL + ((right.rxDLL - left.rxDLL) / 2);
        searchPoint.rdDelay = right.rdDelay;

        do
        {
            NAND_spiPhyConfig(handle,searchPoint);
            status = NAND_spiPhyRdAttack(handle, hwAttrs->dataAddr + offset);
            if(status == NAND_FAIL)
            {
                /*
			     * Since we couldn't find the pattern, we need to go the
			     * the upper half.
			     */
                left.txDLL = searchPoint.txDLL;
                left.rxDLL = searchPoint.rxDLL;
                
                searchPoint.txDLL = searchPoint.txDLL + ((right.txDLL - searchPoint.txDLL)/2);
                searchPoint.rxDLL = searchPoint.rxDLL + ((right.rxDLL - searchPoint.rxDLL)/2);
            }
            else
            {
                /*
			     * Since we found the pattern, we need to go to the
			     * lower half.
			     */
                right.txDLL = searchPoint.txDLL;
                right.rxDLL = searchPoint.rxDLL;
                
                searchPoint.txDLL = left.txDLL + ((searchPoint.txDLL - left.txDLL)/2);
                searchPoint.rxDLL = left.rxDLL + ((searchPoint.rxDLL - left.rxDLL)/2);
            }
#ifdef NAND_SPI_TUNE_DEBUG
            nandSpiTuneCnt++;
#endif
        /* Break the loop if the window has closed. */
        } while ((right.txDLL - left.txDLL >= 2) && (right.rxDLL - left.rxDLL >= 2));

        gapHigh = searchPoint;
        /* Place the final tuning point of the PHY in the corner furthest from the gap */
        length1 = abs(gapLow.txDLL-bottomLeft.txDLL) + abs(gapLow.rxDLL-bottomLeft.rxDLL);
        length2 = abs(gapHigh.txDLL-topRight.txDLL) + abs(gapHigh.rxDLL-topRight.rxDLL);
        if(length2>length1)
        {
            searchPoint = topRight;
            searchPoint.txDLL-=16U;
            searchPoint.rxDLL-= 16U * ((float)topRight.rxDLL-(float)bottomLeft.rxDLL)/((float)topRight.txDLL-(float)bottomLeft.txDLL);
        }
        else
        {
            searchPoint = bottomLeft;
            searchPoint.txDLL+=16U;
            searchPoint.rxDLL+=16U * ((float)topRight.rxDLL-(float)bottomLeft.rxDLL)/((float)topRight.txDLL-(float)bottomLeft.txDLL);
        }
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("Bottom left found at txDLL,rxDLL of %d,%d to %d,%d, and a rdDelay of %d\n",bottomLeft.txDLL,bottomLeft.rxDLL,gapLow.txDLL,gapLow.rxDLL,gapLow.rdDelay);
        NAND_log("Top Right found at txDLL,rxDLL of %d,%d to %d,%d, and a rdDelay of %d\n",gapHigh.txDLL,gapHigh.rxDLL,topRight.txDLL,topRight.rxDLL,gapHigh.rdDelay);
#endif
    }
#ifdef NAND_SPI_TUNE_DEBUG
    NAND_log("Tuning was complete in %d steps\n", nandSpiTuneCnt);
    NAND_log("Tuning PHY to txDLL,rxDLL of %d,%d and rdDelay of %d\n",searchPoint.txDLL,searchPoint.rxDLL,searchPoint.rdDelay);
#endif
    NAND_spiPhyConfig(handle,searchPoint);

    /* Save SDR tuning config point data */
    gNandDtrStrTuningPoint = searchPoint;

    return NAND_PASS;
}

/*
 * Prints out DLL settings, and check the lock status bits
 *     0 = Full cycle
 *     2 = Half cycle
 *     3 = Failed to lock
 * if not full cycl locked, turn on the master PHY bypass mode
 */
void NAND_spiPhyDllObserve(OSPI_Handle handle)
{
    OSPI_v0_HwAttrs const        *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    const CSL_ospi_flash_cfgRegs *pRegs = (const CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr);
    uint32_t                      dll_lock_mode;

#ifdef NAND_SPI_TUNE_DEBUG
    uint32_t rx_decode, tx_decode, dll_lock_value, dll_lock_status;

    /* Parse the observable upper and lower registers for the bit fields */
    rx_decode = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_UPPER_REG,
                               OSPI_FLASH_CFG_DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE__UPPER_RX_DECODER_OUTPUT_FLD);
    tx_decode = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_UPPER_REG,
                               OSPI_FLASH_CFG_DLL_OBSERVABLE_UPPER_REG_DLL_OBSERVABLE_UPPER_TX_DECODER_OUTPUT_FLD);
    dll_lock_value = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_LOWER_REG,
                                    OSPI_FLASH_CFG_DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_VALUE_FLD);
    dll_lock_mode = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_LOWER_REG,
                                   OSPI_FLASH_CFG_DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD);
    dll_lock_status = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_LOWER_REG,
                                     OSPI_FLASH_CFG_DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD);

    /* Print out lock status, the lock value, and the tx/rx decoded value */
    // switch(dll_lock_mode)
    // {
    //     case 0b00:
    //         NAND_log("Decoded TX,RX is %d,%d\nDLL locked on full cycle with %d Delay elements\n",tx_decode,rx_decode,dll_lock_value);
    //         break;
    //     case 0b10:
    //         NAND_log("Decoded TX,RX is %d,%d\nDLL locked on half cycle with %d Delay elements\n",tx_decode,rx_decode,dll_lock_value);
    //         break;
    //     case 0b11:
    //         NAND_log("Decoded TX,RX is %d,%d\nDLL did not lock\n",tx_decode,rx_decode);
    //         break;
    //     default:
    //         break;
    // }
    // NAND_log("lock mode is %d, lock status is %d, \n",dll_lock_mode,dll_lock_status);
#else
    dll_lock_mode = CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_LOWER_REG,
                                   OSPI_FLASH_CFG_DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOCK_MODE_FLD);
#endif
    if(dll_lock_mode != 0U)
    {
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("Bypassing PHY Master because of dll lock mode\n");
#endif
        /* Put DLL into bypass mode */
       CSL_REG32_FINS(&pRegs->PHY_MASTER_CONTROL_REG,
                      OSPI_FLASH_CFG_PHY_MASTER_CONTROL_REG_PHY_MASTER_BYPASS_MODE_FLD, 1U);
    }
}

NAND_STATUS Nand_spiPhyTune(OSPI_Handle handle, uint32_t offset)
{
    NAND_STATUS                    status = NAND_PASS;
    OSPI_v0_HwAttrs const        *hwAttrs = (OSPI_v0_HwAttrs const *)handle->hwAttrs;

#ifdef NAND_SPI_TUNE_PROFILE
    uint64_t          startTime;        /* start time stamp in usec */
    uint64_t          elapsedTime;      /* elapsed time in usec */
    startTime = TimerP_getTimeInUsecs();
#endif

    if (hwAttrs->dtrEnable)
    {
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("\nDoing DTR tuning\n");
#endif
        if (gNandDtrStrTuningPoint.magicNumber == PHY_CONFIG_MAGIC_VALUE_TUNING_COMPLETE &&
            gNandDtrStrTuningPoint.funcClk == hwAttrs->funcClk)
        {
            /* If an existing PHY tuning is already in RAM, just use the existing results */
            NAND_spiPhyConfig(handle, gNandDtrStrTuningPoint);
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("\nConfiguring PHY for DTR using existing DDR-compatible tuning point from RAM\n");
#endif
        } 
        else
        {
            /* Perform PHY tuning */
            status = Nand_spiPhyDdrTune(handle, offset);
    
            if (status == NAND_PASS)
            {
                /* Update magic number in RAM so the next time this function is called tuning isn't repeated */
                gNandDtrStrTuningPoint.magicNumber = PHY_CONFIG_MAGIC_VALUE_TUNING_COMPLETE;
                gNandDtrStrTuningPoint.funcClk = hwAttrs->funcClk;
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("\nConfiguring PHY for DTR by performing PHY tuning.\n");
#endif
            }
            else
            {
                gNandDtrStrTuningPoint.magicNumber = PHY_CONFIG_MAGIC_VALUE_TUNING_UNTUNED;
#ifdef NAND_SPI_TUNE_DEBUG
                NAND_log("\nERROR: PHY tuning failed! Is the test pattern binary written to Flash?");
#endif
                status = NAND_FAIL;
            }
        }
    }
    else
    {
#ifdef NAND_SPI_TUNE_DEBUG
        NAND_log("\nDoing STR tuning\n");
#endif

        /* Always use hard-coded PHY tuning for SDR if an existing DTR-compatible tuning
            doesn't exist in RAM */
        if (gNandDtrStrTuningPoint.magicNumber == PHY_CONFIG_MAGIC_VALUE_TUNING_COMPLETE &&
            gNandDtrStrTuningPoint.funcClk == hwAttrs->funcClk)
        {
            /* If an existing PHY tuning is already in RAM, just use the existing results */
            NAND_spiPhyConfig(handle, gNandDtrStrTuningPoint);
#ifdef NAND_SPI_TUNE_DEBUG
            NAND_log("\nConfiguring PHY for STR using existing DDR-compatible tuning point from RAM\n");
#endif
        }
        else
        {
#ifdef NAND_SPI_TUNE_DEBUG
            SPI_log("\nConfiguring PHY for STR using default tuning point\n");
#endif
            NAND_spiPhyConfig(handle, defaultPhyTuning);
            gNandDtrStrTuningPoint.magicNumber = PHY_CONFIG_MAGIC_VALUE_TUNING_UNTUNED;
        }
        status = NAND_PASS;
    }

#ifdef NAND_SPI_TUNE_PROFILE
    elapsedTime = TimerP_getTimeInUsecs() - startTime;
    NAND_log("\n PHY tuning elapsed %d us", (uint32_t)elapsedTime);
#endif

    return status;
}

void Nand_spiPhyTuneReset(bool ddrMode)
{
    gNandDtrStrTuningPoint.txDLL   = 0;
    gNandDtrStrTuningPoint.rxDLL   = 0;
    gNandDtrStrTuningPoint.rdDelay = 0;
}

void Nand_enableDefaultPhyTuning(OSPI_Handle handle)
{
  NAND_spiPhyConfig(handle, defaultPhyTuning);
}
