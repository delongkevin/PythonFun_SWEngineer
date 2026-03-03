/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   board_power.c
 *
 *  \brief  Implements functions to control the power on the board.
 *
 */

#include <ti/csl/cslr_device.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/osal/osal.h>
#include <ti/board/board.h>
#include <ti/board/src/devices/common/common.h>
#include "board_internal.h"
#include "board_power.h"
#include "board_utils.h"
#include <ti/board/src/devices/pmic/tps65941.h>


#if 0 //ToDO: Need to check @Aniket & @Bhagwan
#include <stdio.h>
#include <string.h>
#include <ti/csl/arch/csl_arch.h>
#include "board_internal.h"
#include "board_utils.h"
#include "board_cfg.h"
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/**
 *  \brief    Function to configure SD card voltage gpio configuration.
 *
 *  \param    gpioValue [IN] GPIO pin value.
 *            1 for GPIO pin high
 *            0 for GPIO pin low
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
static void Board_sdVoltageCtrlGpioCfg(uint8_t gpioValue)
{
    uint32_t regVal;

    /* Setting the GPIO direction to output */
    regVal = HW_RD_REG32(CSL_GPIO1_BASE + 0x88);
    regVal &= ~(0x01 << (BOARD_SDIO_1V8_EN_PIN_NUM % 32));
    HW_WR_REG32((CSL_GPIO1_BASE + 0x88), regVal);

    /* Setting the GPIO value */
    regVal = HW_RD_REG32(CSL_GPIO1_BASE + 0x90);

    if(gpioValue == 0)
    {
        regVal &= ~(0x01 << (BOARD_SDIO_1V8_EN_PIN_NUM % 32));
        HW_WR_REG32((CSL_GPIO1_BASE + 0x90), regVal);
    }
    else
    {
        regVal |= (gpioValue << (BOARD_SDIO_1V8_EN_PIN_NUM % 32));
        HW_WR_REG32((CSL_GPIO1_BASE + 0x90), regVal);
    }
}

/**
 *  \brief    Function to programs VDD_CORE to 0.9V.
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pmVDDCoreVoltageCfg(void)
{
    I2C_Handle handle = NULL;
	Board_STATUS retVal = BOARD_SOK;
    uint8_t regData;

    /* VDD voltage is 0.9v by default for Leo PMIC SoM */
    if(Board_detectBoard(BOARD_ID_SOM) != TRUE)
    {
        handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_LP87561_I2C_INSTANCE);
        if(handle == NULL)
        {
            retVal = BOARD_I2C_OPEN_FAIL;
        }
        else
        {
            regData = BOARD_PMIC_LP87561_VOLTAGE_0V9_VAL;
            retVal= Board_i2c8BitRegWr(handle,
                                       BOARD_PMIC_LP87561_I2C_SLAVE_ADDR,
                                       BOARD_PMIC_LP87561_BUCK0_VOUT_REG,
                                       &regData,
                                       1U,
                                       I2C_WAIT_FOREVER);
            if(retVal != BOARD_SOK)
            {
                retVal = BOARD_I2C_TRANSFER_FAIL;
            }
        }

        /* Wait for some time to ensure voltage ramp is complete */
        BOARD_delay(100000);

        Board_i2cDeInit();
    }

    return retVal;
}

/**
 *  \brief    Function to configure SD card voltage.
 *
 *  \param vsel [IN] SD voltage selection. 0 for 1.8v, 1 for 3.3v
 *
 *  \return   BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pmSdVoltageCtrl(uint8_t vsel)
{
    I2C_Handle handle = NULL;
	Board_STATUS retVal = -1;
    uint8_t voltage;
    uint8_t regData;
    uint8_t leoPMIC = 0;

    /* Detecting SoM board */
    if(Board_detectBoard(BOARD_ID_SOM) == TRUE)
    {
        leoPMIC = 1;
        Board_sdVoltageCtrlGpioCfg(vsel);
    }
    else
    {
        handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);
        if(handle == NULL)
        {
            retVal = BOARD_I2C_OPEN_FAIL;
            goto voltage_switch_exit;
        }

        if(vsel == 1)
        {
            voltage = BOARD_PMIC_LDO1_VSEL_3V3;
        }
        else
        {
            voltage = BOARD_PMIC_LDO1_VSEL_1V8;
        }

        /* Write voltage */
        retVal = Board_i2c8BitRegWr(handle,
                                    BOARD_PMIC_I2C_SLAVE_ADDR,
                                    BOARD_PMIC_LDO1_VOLTAGE_REG,
                                    &voltage,
                                    1U,
                                    I2C_WAIT_FOREVER);
        if(retVal != 0)
        {
            retVal = BOARD_I2C_TRANSFER_FAIL;
            goto voltage_switch_exit;
        }

        BOARD_delay(10000);

        /* Enable LDO */
        regData = 0x1;
        retVal = Board_i2c8BitRegWr(handle,
                                    BOARD_PMIC_I2C_SLAVE_ADDR,
                                    BOARD_PMIC_LDO1_CTRL_REG,
                                    &regData,
                                    1U,
                                    I2C_WAIT_FOREVER);
        if(retVal != 0)
        {
        retVal = BOARD_I2C_TRANSFER_FAIL;
        goto voltage_switch_exit;
        }
    }
    /* Wait for some time to ensure voltage ramp is complete */
    BOARD_delay(100000);
    retVal = BOARD_SOK; /* Success */

voltage_switch_exit:
    if(leoPMIC == 0)
    {
        Board_i2cDeInit();
    }

    return retVal;
}

#endif

static const struct pmic_ovuv_threshold_reg tp65941_UVOV_data[NUM_PMIC_CONFIG] = {
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_BUCK1_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CPU_AVS
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_BUCK2_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CPU_AVS
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_BUCK3_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CPU_AVS
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_BUCK4_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_MCU_0V85
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_BUCK5_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_PHY_1V8
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_LDO1_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD1_LPDDR4_1V8
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_LDO2_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_MCUIO_1V8
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_LDO3_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_DLL_0V8
        //{BOARD_HYDRA_I2C_PMIC_MASTER_ADDR,BOARD_TPS65941_LDO4_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_MCU_1V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_BUCK1_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CORE_0V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_BUCK2_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CORE_0V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_BUCK3_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CORE_0V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_BUCK4_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_CORE_0V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_BUCK5_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDD_RAM_0V85
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_LDO1_RESOURCE,UV_OV_10_PERCENT,UV_OV_10_PERCENT}, //VDD_SD_DV
        {BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_LDO2_RESOURCE,UV_OV_10_PERCENT,UV_OV_10_PERCENT}, //VDD_USB_3V3
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_LDO3_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VLDO_PMICB_1V8
        //{BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,BOARD_TPS65941_LDO4_RESOURCE,UV_OV_3_PERCENT,UV_OV_3_PERCENT}, //VDA_PLL_1V8
};

Board_STATUS Board_PMIC_Init(void)
{
    Board_STATUS boardStatus = BOARD_SOK;
    I2C_Handle pmic_handle = NULL;
    uint8_t index = 0;

    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);


    for(index=0;index<NUM_PMIC_CONFIG;index++)
    {
        if(BOARD_SOK != Board_tps65941SetUVOVThreshold(pmic_handle, tp65941_UVOV_data[index].slaveAddr, tp65941_UVOV_data[index].powerResource, 
            tp65941_UVOV_data[index].UVthreshold, tp65941_UVOV_data[index].OVthreshold))
        {
            boardStatus = -1;
        }
    }

    return boardStatus;

}

int32_t PMIC_Read(uint8_t slaveaddr, uint8_t regaddr, uint8_t *regData)
{
    Board_STATUS boardStatus = BOARD_SOK;
    I2C_Handle pmic_handle = NULL;
    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);

    boardStatus = Board_i2c8BitRegRd(pmic_handle,
                                     slaveaddr,
                                     regaddr,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);

    return boardStatus;
}

int32_t PMIC_Write(uint8_t slaveaddr, uint8_t regaddr, uint8_t regData)
{
    Board_STATUS boardStatus = BOARD_SOK;
    I2C_Handle pmic_handle = NULL;
    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);

    boardStatus = Board_i2c8BitRegWr(pmic_handle,
                                     slaveaddr,
                                     regaddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);

    return boardStatus;
}

uint8_t PMIC_Test_Write(uint8_t regaddr, uint8_t regData)
{
    Board_STATUS boardStatus = BOARD_SOK;
    I2C_Handle pmic_handle = NULL;
    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);

    boardStatus = Board_i2c8BitRegWr(pmic_handle,
                                     BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR,
                                     regaddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     BOARD_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    return boardStatus;
}

Board_STATUS PMIC_Disable_Wdg(void)
{
    Board_STATUS boardStatus = BOARD_SOK;
    I2C_Handle pmic_handle = NULL;
    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                    BOARD_PMIC_I2C_INSTANCE);

    /* Configure GPIO2_CONF Register to 0x2A.This sets the bit GPIO2_SEL to TRIG_WDOG (Bit 7:5), and all other bits to default settings */
    boardStatus = Board_tps65941SetGPIO2(pmic_handle, BOARD_HYDRA_I2C_PMIC_MASTER_ADDR, 0x2A);

    boardStatus = Board_tps65941WdtDisable(pmic_handle, BOARD_HYDRA_I2C_PMIC_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_DISABLE);

    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    return boardStatus;
}


void PMIC_EnterLongWindow_DisableWdg(void)
{
    I2C_Handle pmic_handle = NULL;

    /* Get I2C handle */
    pmic_handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP, BOARD_PMIC_I2C_INSTANCE);

    /* Enter in long window */
    Board_tps65941RetToLongWin(pmic_handle, BOARD_HYDRA_I2C_PMIC_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_IN_LONGWINDOW);

    /* Disable Watchdog */
    Board_tps65941WdtDisable(pmic_handle, BOARD_HYDRA_I2C_PMIC_WDG_SLAVE_ADDR, BOARD_TPS65941_WDT_DISABLE);
}

