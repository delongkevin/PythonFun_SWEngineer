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
#include <ti/csl/src/ip/ospi/V0/cslr_ospi.h>
#include <ti/csl/src/ip/ospi/V0/csl_ospi.h>
#include <ti/board/src/flash/nand/ospi/nand_spi_pattern.h>
#include <ti/board/src/flash/nand/ospi/nand_spi_phy_tune.h>
#include <ti/board/src/flash/nor/ospi/nor_spi_phy_tune.h>
/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

//extern void UART_printf(const char *pcString, ...);

#undef NAND_SPI_TUNE_DEBUG
#undef NAND_SPI_TUNE_PROFILE
#undef NAND_DISABLE_TXDLL_WINDOW

#ifdef NAND_SPI_TUNE_DEBUG
#define NAND_log UART_printf
uint32_t nandSpiTuneCnt = 0;
#endif

#ifdef NAND_SPI_TUNE_PROFILE
#define NAND_log UART_printf
#endif

#define SMART_SLEEP(ticks)      {\
                                 uint32_t volatile isleep;\
                                 for(isleep=0;isleep<ticks;isleep++)\
                                 {\
                                    ;/*Do Nothing*/ \
                                 }\
                                 }

uint8_t tx_valid[0x80];
uint8_t rx_valid[0x80][0x80];

/* TODO  move gNandPhyTuningPoint to a new, designated section in DDR or other RAM that isn't re-initialized
   in the Boot App to allow the Boot App to reuse the PHY tuning from the SBL */
NAND_PhyConfig gNandPhyTuningPoint __attribute__((section(".ospi_phy_tuning_data")));


uint32_t ospi_w35_configure_PHY(OSPI_Handle handle)
{
    OSPI_v0_HwAttrs const        *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    CSL_ospi_flash_cfgRegs *pRegs = (CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr);
    uint32_t return_code = NAND_PASS;
    SMART_SLEEP(5000);
    CSL_ospiSetPreScaler(pRegs, 0);
    CSL_ospiPhyEnable(pRegs, 1);
    SMART_SLEEP(5000);
    CSL_ospiPipelinePhyEnable(pRegs, 0);
    SMART_SLEEP(5000);
    //Doc says to assume DDR mode, still works with SDR

    pRegs->PHY_CONFIGURATION_REG &= ~(1<<30);

    //2b.2 Set intial delay for Master DLL
    pRegs->PHY_MASTER_CONTROL_REG &= ~(0x7F); //Clear previous setting
    pRegs->PHY_MASTER_CONTROL_REG |= 91; //120MHz TODO
    pRegs->PHY_MASTER_CONTROL_REG |= (1 << 24);
    //2b.3
    pRegs->PHY_CONFIGURATION_REG &= ~(0x7F0000); //Clear previous setting
    pRegs->PHY_CONFIGURATION_REG |= 26<<16; //120MHz TODO

    //2b.4 Resync DLLs and set DLL reset bit back to high
    pRegs->PHY_CONFIGURATION_REG &= ~(0x1 << 31); //Untoggle DLL sync bit
    pRegs->PHY_CONFIGURATION_REG |=  ( (unsigned) 0x1 << 31);
    pRegs->PHY_CONFIGURATION_REG |= (1<<30);

    //Force Half-Clock lock
    pRegs->PHY_MASTER_CONTROL_REG |= (1<<24);

    //2b.5 Poll DLL Observable Reg lower bit to be set
    uint32_t dll_reg= pRegs->DLL_OBSERVABLE_LOWER_REG;
    dll_reg= pRegs->DLL_OBSERVABLE_LOWER_REG;
    dll_reg &= (1<<15);
    while(!dll_reg){
        dll_reg= pRegs->DLL_OBSERVABLE_LOWER_REG;
        dll_reg &= (1<<15);
    }

    //2b.6 Resync slave DLLs and set initial TX and RX delays
    //Setting intials to 0
    //Wait some time
    pRegs->PHY_CONFIGURATION_REG &= ~(0x7F << 0); //RX
    pRegs->PHY_CONFIGURATION_REG &= ~(0x7F << 16); //TX
    pRegs->PHY_CONFIGURATION_REG &= ~(0x1 << 31); //Untoggle DLL sync bit
    pRegs->PHY_CONFIGURATION_REG |=  ( (unsigned) 0x1 << 31);
    SMART_SLEEP(10000);
    Nor_spiPhyTune(handle, NAND_TUNING_DATA_OFFSET ,&gNandPhyTuningPoint);

    return return_code;

}

NAND_STATUS Nand_spiPhyTune(OSPI_Handle handle, uint32_t offset)
{
    OSPI_v0_HwAttrs const        *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;
    CSL_ospi_flash_cfgRegs *pRegs = (CSL_ospi_flash_cfgRegs *)(hwAttrs->baseAddr);
    NAND_STATUS ret = NAND_PASS;
    uint8_t i;
    uint32_t data[3];
    uint32_t rdDelayStored;
    pRegs->RD_DATA_CAPTURE_REG += 0x0020;
    if ((gNandPhyTuningPoint.txDLL == 0U) && (gNandPhyTuningPoint.rxDLL == 0U))
    {
        for(i = 0; i <= 0xf; i++){
            //UART_printf("RD DLY %d\n", i);
            if(ospi_w35_configure_PHY(handle) == NAND_PASS){
                //UART_printf("PHY config found\n");
                return NAND_PASS;
            }
            pRegs->RD_DATA_CAPTURE_REG += 0x10002;
        }
    }
    else
    {
        rdDelayStored = gNandPhyTuningPoint.rdDelay;
        OSPI_control(handle, OSPI_V0_CMD_CFG_RD_DELAY, (void *)(&rdDelayStored));
        data[0] = TRUE;
        data[1] = gNandPhyTuningPoint.txDLL;
        data[2] = gNandPhyTuningPoint.rxDLL;
        OSPI_control(handle, OSPI_V0_CMD_CFG_PHY, (void *)data);
        //CSL_ospiPhyEnable(pRegs, 1);
        //pRegs->PHY_CONFIGURATION_REG &= ~(0x7F << 16); //TX
        //pRegs->PHY_CONFIGURATION_REG |= (gNandPhyTuningPoint.txDLL << 16); //TX
        //CSL_ospiPhyResyncDll(pRegs, 0U);
        //pRegs->PHY_CONFIGURATION_REG &= ~(0x7F << 0); //RX
        //pRegs->PHY_CONFIGURATION_REG |= (gNandPhyTuningPoint.rxDLL << 0); //RX
        //CSL_ospiPhyResyncDll(pRegs, 0U);
    }
    return ret;
}

void Nand_spiPhyTuneReset(bool ddrMode)
{
    gNandPhyTuningPoint.txDLL   = 0U;
    gNandPhyTuningPoint.rxDLL   = 0U;
    gNandPhyTuningPoint.rdDelay = 0U;
}
