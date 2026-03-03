/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *
 *****************************************************************************/

/**
 *   \file    tps65941.c
 *
 *   \brief   This file contains the default API's for configuring TPS65941
 *            PMIC.
 *
 */

#include "tps65941.h"


/*!
 * \brief  PMIC SERIAL_IF_CONFIG register Shift Values
 */
#define PMIC_SERIAL_IF_CONFIG_REGADDR_CRC                           (0x1AU)
#define PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_SHIFT_CRC             (0x1U)
#define PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_MASK_CRC              \
    ((uint8_t)(0x01U << PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_SHIFT_CRC))

#define PMIC_IO_BUF_SIZE                                             (0x4U)
#define PMIC_I2C_TRANSACTION_TIMEOUT         (2u)

static Board_Tps65941GpioRegCfg gpioRegCfg[] = {
    {BOARD_TPS65941_NPWRON_CONF, 0,  0, BOARD_TPS65941_NPWRON_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO1_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO1_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO2_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO2_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO3_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO3_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO4_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO4_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO5_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO5_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO6_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO6_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO7_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO7_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO8_CONF, BOARD_TPS65941_GPIO_OUT_1, BOARD_TPS65941_GPIO_IN_1, BOARD_TPS65941_GPIO8_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO9_CONF, BOARD_TPS65941_GPIO_OUT_2, BOARD_TPS65941_GPIO_IN_2, BOARD_TPS65941_GPIO9_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO10_CONF, BOARD_TPS65941_GPIO_OUT_2, BOARD_TPS65941_GPIO_IN_2, BOARD_TPS65941_GPIO10_IN_OUT_SHIFT},
    {BOARD_TPS65941_GPIO11_CONF, BOARD_TPS65941_GPIO_OUT_2, BOARD_TPS65941_GPIO_IN_2, BOARD_TPS65941_GPIO11_IN_OUT_SHIFT}
};

static Board_Tps65941PwrResourceRegCfg pwrResourceRegCfg[] = {
    {BOARD_TPS65941_BUCK1_CTRL, BOARD_TPS65941_BUCK1_CONF, BOARD_TPS65941_BUCK1_VOUT_1, BOARD_TPS65941_BUCK1_PG_WIN, BOARD_TPS65941_STAT_BUCK1_2, 0},
    {BOARD_TPS65941_BUCK2_CTRL, BOARD_TPS65941_BUCK2_CONF, BOARD_TPS65941_BUCK2_VOUT_1, BOARD_TPS65941_BUCK2_PG_WIN, BOARD_TPS65941_STAT_BUCK1_2, 4},
    {BOARD_TPS65941_BUCK3_CTRL, BOARD_TPS65941_BUCK3_CONF, BOARD_TPS65941_BUCK3_VOUT_1, BOARD_TPS65941_BUCK3_PG_WIN, BOARD_TPS65941_STAT_BUCK3_4, 0},
    {BOARD_TPS65941_BUCK4_CTRL, BOARD_TPS65941_BUCK4_CONF, BOARD_TPS65941_BUCK4_VOUT_1, BOARD_TPS65941_BUCK4_PG_WIN, BOARD_TPS65941_STAT_BUCK3_4, 4},
    {BOARD_TPS65941_BUCK5_CTRL, BOARD_TPS65941_BUCK5_CONF, BOARD_TPS65941_BUCK5_VOUT_1, BOARD_TPS65941_BUCK5_PG_WIN, BOARD_TPS65941_STAT_BUCK5, 0},
    {BOARD_TPS65941_LDO1_CTRL, 0, BOARD_TPS65941_LDO1_VOUT, BOARD_TPS65941_LDO1_PG_WIN, BOARD_TPS65941_STAT_LDO1_2, 0},
    {BOARD_TPS65941_LDO2_CTRL, 0, BOARD_TPS65941_LDO2_VOUT, BOARD_TPS65941_LDO2_PG_WIN, BOARD_TPS65941_STAT_LDO1_2, 4},
    {BOARD_TPS65941_LDO3_CTRL, 0, BOARD_TPS65941_LDO3_VOUT, BOARD_TPS65941_LDO3_PG_WIN, BOARD_TPS65941_STAT_LDO3_4, 0},
    {BOARD_TPS65941_LDO4_CTRL, 0, BOARD_TPS65941_LDO4_VOUT, BOARD_TPS65941_LDO4_PG_WIN, BOARD_TPS65941_STAT_LDO3_4, 4}
};

static Board_Tps65941IntrRegMap tps65941IntrRegMap[] = {
    {BOARD_TPS65941_BUCK_MASK,      BOARD_TPS65941_BUCK_INT,        3}, //BOARD_TPS65941_INTR_TYPE_BUCK_ERR
    {BOARD_TPS65941_LDO_MASK,       BOARD_TPS65941_LDO_VMON_INT,    3}, //BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR
    {0x0,                           BOARD_TPS65941_SEV_ERR_INT,     1}, //BOARD_TPS65941_INTR_TYPE_SEVERE_ERR
    {BOARD_TPS65941_MOD_ERR_MASK,   BOARD_TPS65941_MOD_ERR_INT,     1}, //BOARD_TPS65941_INTR_TYPE_MODERATE_ERR
    {BOARD_TPS65941_MISC_WARN_MASK, BOARD_TPS65941_MISC_INT,        1}, //BOARD_TPS65941_INTR_TYPE_MISC_WARN
    {BOARD_TPS65941_STARTUP_MASK,   BOARD_TPS65941_STARTUP_INT,     1}, //BOARD_TPS65941_INTR_TYPE_STARTUP_SRC
    {BOARD_TPS65941_GPIO_MASK,      BOARD_TPS65941_GPIO_INT,        3}, //BOARD_TPS65941_INTR_TYPE_GPIO
    {BOARD_TPS65941_FSM_ERR_MASK,   BOARD_TPS65941_FSM_ERR_INT,     4}  //BOARD_TPS65941_INTR_TYPE_FSM_ERR
};


/**
 *  Used CRC Polynomial:  x^8 + x^2 + x + 1
 *   Evalution of CRC Polynomial value from equation:
 *     1*x^8 + 0*x^7 + 0*x^6 + 0*x^5 + 0*x^4 + 0*x^3 + 1*x^2 + 1*x + 1
 *  =  1     + 0     + 0     + 0     + 0     + 0     + 1     + 1   + 1
 *  =  0x107(After discarding MSB bit) = 0x7
 *
 * CRC Polynomial value: 0x07, Initial Value: 0x00, Final Value: 0x00
 * link to generate custom CRC table from polynomial:
 * http://www.sunshine2k.de/coding/javascript/crc/crc_js.html
 */

static const uint8_t CRC_8_TABLE[] =
{
    0x00, 0x07, 0x0e, 0x09, 0x1c, 0x1b, 0x12, 0x15,
    0x38, 0x3f, 0x36, 0x31, 0x24, 0x23, 0x2a, 0x2d,
    0x70, 0x77, 0x7e, 0x79, 0x6c, 0x6b, 0x62, 0x65,
    0x48, 0x4f, 0x46, 0x41, 0x54, 0x53, 0x5a, 0x5d,
    0xe0, 0xe7, 0xee, 0xe9, 0xfc, 0xfb, 0xf2, 0xf5,
    0xd8, 0xdf, 0xd6, 0xd1, 0xc4, 0xc3, 0xca, 0xcd,
    0x90, 0x97, 0x9e, 0x99, 0x8c, 0x8b, 0x82, 0x85,
    0xa8, 0xaf, 0xa6, 0xa1, 0xb4, 0xb3, 0xba, 0xbd,
    0xc7, 0xc0, 0xc9, 0xce, 0xdb, 0xdc, 0xd5, 0xd2,
    0xff, 0xf8, 0xf1, 0xf6, 0xe3, 0xe4, 0xed, 0xea,
    0xb7, 0xb0, 0xb9, 0xbe, 0xab, 0xac, 0xa5, 0xa2,
    0x8f, 0x88, 0x81, 0x86, 0x93, 0x94, 0x9d, 0x9a,
    0x27, 0x20, 0x29, 0x2e, 0x3b, 0x3c, 0x35, 0x32,
    0x1f, 0x18, 0x11, 0x16, 0x03, 0x04, 0x0d, 0x0a,
    0x57, 0x50, 0x59, 0x5e, 0x4b, 0x4c, 0x45, 0x42,
    0x6f, 0x68, 0x61, 0x66, 0x73, 0x74, 0x7d, 0x7a,
    0x89, 0x8e, 0x87, 0x80, 0x95, 0x92, 0x9b, 0x9c,
    0xb1, 0xb6, 0xbf, 0xb8, 0xad, 0xaa, 0xa3, 0xa4,
    0xf9, 0xfe, 0xf7, 0xf0, 0xe5, 0xe2, 0xeb, 0xec,
    0xc1, 0xc6, 0xcf, 0xc8, 0xdd, 0xda, 0xd3, 0xd4,
    0x69, 0x6e, 0x67, 0x60, 0x75, 0x72, 0x7b, 0x7c,
    0x51, 0x56, 0x5f, 0x58, 0x4d, 0x4a, 0x43, 0x44,
    0x19, 0x1e, 0x17, 0x10, 0x05, 0x02, 0x0b, 0x0c,
    0x21, 0x26, 0x2f, 0x28, 0x3d, 0x3a, 0x33, 0x34,
    0x4e, 0x49, 0x40, 0x47, 0x52, 0x55, 0x5c, 0x5b,
    0x76, 0x71, 0x78, 0x7f, 0x6a, 0x6d, 0x64, 0x63,
    0x3e, 0x39, 0x30, 0x37, 0x22, 0x25, 0x2c, 0x2b,
    0x06, 0x01, 0x08, 0x0f, 0x1a, 0x1d, 0x14, 0x13,
    0xae, 0xa9, 0xa0, 0xa7, 0xb2, 0xb5, 0xbc, 0xbb,
    0x96, 0x91, 0x98, 0x9f, 0x8a, 0x8d, 0x84, 0x83,
    0xde, 0xd9, 0xd0, 0xd7, 0xc2, 0xc5, 0xcc, 0xcb,
    0xe6, 0xe1, 0xe8, 0xef, 0xfa, 0xfd, 0xf4, 0xf3
};


/*!
 * \brief   This function is used to read a specific bit field value
 */
static uint8_t Pmic_getBitField(uint8_t regData,
                                uint8_t regFieldShift,
                                uint8_t regFieldMask)
{
    uint8_t fieldVal;

    fieldVal = (((regData) & (uint8_t) regFieldMask) >>  \
                 (uint8_t) regFieldShift);

    return fieldVal;
}

uint8_t Board_tps65941GetCRCStatus(void *handle,
                                    uint8_t slaveAddr)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0, i2c1SpiCrcStatus = 0;
 
    if(handle == NULL)
    {
        i2c1SpiCrcStatus = 0u;
    }
    else
    {
        /* Check the CRC status */
        boardStatus = Board_i2c8BitRegRd(handle,
                                        slaveAddr,
                                        PMIC_SERIAL_IF_CONFIG_REGADDR_CRC,
                                        &regData,
                                        BOARD_I2C_NUM_OF_BYTES_01,
                                        PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            i2c1SpiCrcStatus = 0u;
        }
        else
        {
            i2c1SpiCrcStatus = Pmic_getBitField(regData, PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_SHIFT_CRC,
                                                PMIC_SERIAL_IF_CONFIG_I2C1_SPI_CRC_EN_MASK_CRC);
        }
    }
 
    return i2c1SpiCrcStatus;
}


/*!
 * \brief: API to Get CRC8 data
 *
 * \param   data     [IN]     Data for which CRC is to be determined
 * \param   length   [IN]     Length of the buffer in bytes.
 * \retval  crc      [OUT]    CRC value for data.
 */
uint8_t PmicWdg_getCRC8Val(const uint8_t *data, uint8_t length)
{
    uint8_t crc = PMIC_COMM_CRC_INITIAL_VALUE_SBL;
    uint8_t i;
    for(i = 0; i < length; i++)
    {
        crc = CRC_8_TABLE[data[i] ^ crc];
    }

    return crc;
}

/*!
 * \brief: API to Get CRC8 data
 *
 * \param   data     [IN]     Data for which CRC is to be determined
 * \param   length   [IN]     Length of the buffer in bytes.
 * \retval  crc      [OUT]    CRC value for data.
 */
uint8_t Board_tps65941CalculateCRC(uint8_t slaveAddr,
                                    uint8_t regAddr,
                                    uint8_t txData)
{
    uint8_t  crcData[PMIC_IO_BUF_SIZE] = {0};
    uint8_t  crcDataLen = 0;
    uint8_t crcCalculated = 0;

    /* Store the slave address and I2C write request bit */
    crcData[crcDataLen] = (slaveAddr << 1U);
    crcDataLen++;

    /* Store register address */
    crcData[crcDataLen] = regAddr;
    crcDataLen++;

    /* Store the data to be transferred */
    crcData[crcDataLen] = txData;
    crcDataLen++;

    /* Increase 1 more byte to store CRC8 */
    crcCalculated = PmicWdg_getCRC8Val(crcData, crcDataLen);

    /* Return Calculated CRC */
    return crcCalculated;
}


/**
 * \brief   PMIC GPIO read function.
 *
 * This function is used to read the gpio signal level of the PMIC
 * device.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   pinNum          [IN]    PMIC GPIO number
 * \param   pinValue        [OUT]   PMIC GPIO signal level High/Low
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GpioRead(void *handle,
                                    uint8_t slaveAddr,
                                    uint8_t pinNum, 
                                    uint8_t *pinValue)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (pinNum > BOARD_TPS65941_GPIO_PIN_MAX) ||
       (pinValue == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    if(pinNum != BOARD_TPS65941_NPWRON_PIN)
    {
        /* Setting the GPIO direction to input and GPIO mode */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         gpioRegCfg[pinNum].regAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_GPIO_DIR_BIT_MASK);
        regData |= (BOARD_TPS65941_GPIO_DIR_IN << BOARD_TPS65941_GPIO_DIR_SHIFT);
        regData &= ~(BOARD_TPS65941_GPIO_SEL_BIT_MASK);
        regData |= (BOARD_TPS65941_GPIO_MODE << BOARD_TPS65941_GPIO_SEL_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         gpioRegCfg[pinNum].regAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    /* Reading the GPIO value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     gpioRegCfg[pinNum].inRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((regData >> gpioRegCfg[pinNum].inOutRegBitPos) & 0x1)
    {
        *pinValue = BOARD_TPS65941_GPIO_HIGH;
    }
    else
    {
        *pinValue = BOARD_TPS65941_GPIO_LOW;
    }

    return boardStatus;
}

/**
 * \brief   PMIC GPIO write function.
 *
 * This function is used to write the gpio signal level to the PMIC
 * device.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    PMIC slave address
 * \param   pinNum      [IN]    PMIC GPIO number
 * \param   pinValue    [IN]    PMIC GPIO signal level High/Low
 *                              Valid values: BOARD_TPS65941_GPIO_HIGH
 *                                            BOARD_TPS65941_GPIO_LOW
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GpioWrite(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t pinNum, 
                                     uint8_t pinValue)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (pinNum > BOARD_TPS65941_GPIO_PIN_MAX) ||
       (pinNum == BOARD_TPS65941_NPWRON_PIN))
    {
        return BOARD_INVALID_PARAM;
    }

    if((pinValue != BOARD_TPS65941_GPIO_LOW) && 
       (pinValue != BOARD_TPS65941_GPIO_HIGH))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting the GPIO direction to output */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     gpioRegCfg[pinNum].regAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_GPIO_DIR_BIT_MASK);
    regData |= (BOARD_TPS65941_GPIO_DIR_OUT << BOARD_TPS65941_GPIO_DIR_SHIFT);
    regData &= ~(BOARD_TPS65941_GPIO_SEL_BIT_MASK);
    regData |= (BOARD_TPS65941_GPIO_MODE << BOARD_TPS65941_GPIO_SEL_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     gpioRegCfg[pinNum].regAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the GPIO value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     gpioRegCfg[pinNum].regAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(0x01 << gpioRegCfg[pinNum].inOutRegBitPos);
    regData |= (pinValue << gpioRegCfg[pinNum].inOutRegBitPos);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     gpioRegCfg[pinNum].outRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Conversion of VOUT code to millivolt.
 *
 * This function is used to convert the VOUT code read from the PMIC
 * registers to millivolt.
 *
 * \param   voutCode        [IN]    VOUT code in hexadecimal
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [OUT]   Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConvertVolt(uint8_t voutCode,
                                       uint8_t powerResource,
                                       uint16_t *millivolt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint16_t baseMillivolt, millivoltStep;
    uint8_t baseVoutCode;

    if((powerResource > BOARD_TPS65941_LDO4_RESOURCE) || (millivolt == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    if(voutCode > 0xFF)
    {
        return BOARD_INVALID_PARAM;
    }

    if(powerResource <= BOARD_TPS65941_BUCK5_RESOURCE)
    {
        if(voutCode <= 0x0E)
        {
            baseMillivolt = 300;
            millivoltStep = 20;
            baseVoutCode = 0;
        }
        else if((voutCode >= 0x0F) && (voutCode <= 0x72))
        {
            baseMillivolt = 600;
            millivoltStep = 5;
            baseVoutCode = 0x0F;
        }
        else if((voutCode >= 0x73) && (voutCode <= 0xAA))
        {
            baseMillivolt = 1100;
            millivoltStep = 10;
            baseVoutCode = 0x73;
        }
        else    /* if(voutCode >= 0xAB && voutCode <= 0xFF) */
        {
            baseMillivolt = 1660;
            millivoltStep = 20;
            baseVoutCode = 0xAB;
        }
    }
    else if(powerResource == BOARD_TPS65941_LDO4_RESOURCE)
    {
        if((voutCode <= 0x1F) || 
           ((voutCode >= 0x75) && (voutCode <= 0x7F)) || 
           (voutCode >= 0x7F))
        {
            return BOARD_INVALID_PARAM;
        }
        else
        {
            baseMillivolt = 1200;
            millivoltStep = 25;
            baseVoutCode = 0x20;
        }
    }
    else /* BOARD_TPS65941_LDO1_RESOURCE, BOARD_TPS65941_LDO2_RESOURCE, BOARD_TPS65941_LDO3_RESOURCE */
    {
        if((voutCode <= 0x03) || 
           ((voutCode >= 0x3B) && (voutCode <= 0x7F)) || 
           (voutCode >= 0x7F))
        {
            return BOARD_INVALID_PARAM;
        }
        else
        {
            baseMillivolt = 600;
            millivoltStep = 50;
            baseVoutCode = 0x04;
        }
    }

    *millivolt = (baseMillivolt + ((voutCode - baseVoutCode) * millivoltStep));

    return boardStatus;
}

/**
 * \brief   Conversion of millivolt to VOUT code.
 *
 * This function is used to convert the millivolt value to VOUT code
 * to write into the PMIC registers.
 *
 * \param   millivolt       [IN]    Voltage in millivolt
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   voutCode        [OUT]   VOUT code in hexadecimal
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConvertVoutCode(uint16_t millivolt,
                                           uint8_t powerResource,
                                           uint8_t *voutCode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint16_t baseMillivolt, millivoltStep;
    uint8_t baseVoutCode;

    if((powerResource > BOARD_TPS65941_LDO4_RESOURCE) || (voutCode == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    if(powerResource <= BOARD_TPS65941_BUCK5_RESOURCE)
    {
        if((millivolt < 300) || (millivolt > 3340))
        {
            return BOARD_INVALID_PARAM;
        }
        else if((millivolt >= 300) && (millivolt <= 580))
        {
            baseMillivolt = 300;
            millivoltStep = 20;
            baseVoutCode = 0;
        }
        else if((millivolt >= 600) && (millivolt <= 1095))
        {
            baseMillivolt = 600;
            millivoltStep = 5;
            baseVoutCode = 0x0F;
        }
        else if((millivolt >= 1100) && (millivolt <= 1650))
        {
            baseMillivolt = 1100;
            millivoltStep = 10;
            baseVoutCode = 0x73;
        }
        else    /* if(millivolt >= 1660 && millivolt <= 3340) */
        {
            baseMillivolt = 1660;
            millivoltStep = 20;
            baseVoutCode = 0xAB;
        }
    }
    else if(powerResource == BOARD_TPS65941_LDO4_RESOURCE)
    {
        if((millivolt > 3300) || (millivolt < 1200))
        {
            return BOARD_INVALID_PARAM;
        }
        else
        {
            baseMillivolt = 1200;
            millivoltStep = 25;
            baseVoutCode = 0x20;
        }
    }
    else /* BOARD_TPS65941_LDO1_RESOURCE, BOARD_TPS65941_LDO2_RESOURCE, BOARD_TPS65941_LDO3_RESOURCE */
    {
        if((millivolt > 3300) || (millivolt < 600))
        {
            return BOARD_INVALID_PARAM;
        }
        else
        {
            baseMillivolt = 600;
            millivoltStep = 50;
            baseVoutCode = 0x04;
        }
    }

    if((millivolt % millivoltStep))
    {
        return BOARD_INVALID_PARAM;
    }

    *voutCode = (baseVoutCode + ((millivolt - baseMillivolt) / millivoltStep));

    return boardStatus;
}

/**
 * \brief   PMIC set voltage function.
 *
 * This function is used to set the voltage to the power resource of
 * the PMIC.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [IN]    Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVoltage(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint16_t millivolt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t voutCode;
    uint8_t regData = 0;

    if((handle == NULL) || 
       (powerResource > BOARD_TPS65941_LDO4_RESOURCE))
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_tps65941ConvertVoutCode(millivolt, powerResource, &voutCode);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    if(powerResource <= BOARD_TPS65941_BUCK5_RESOURCE)
    {
        /* Setting the BUCK voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = voutCode;

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].voltageRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        /* Setting the BUCK VOUT_1 register */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_BUCK_VSEL_BIT_MASK);
        regData |= (0 << BOARD_TPS65941_BUCK_VSEL_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        /* Enabling the BUCK voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_BUCK_EN_BIT_MASK);
        regData |= (1 << BOARD_TPS65941_BUCK_EN_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    else    /* LDO power resource */
    {
        /* Setting LDO voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].voltageRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if(powerResource == BOARD_TPS65941_LDO4_RESOURCE)
        {
            regData &= ~(BOARD_TPS65941_LDO4_VSET_BIT_MASK);
            regData |= (voutCode << BOARD_TPS65941_LDO4_VSET_SHIFT);
        }
        else
        {
            regData &= ~(BOARD_TPS65941_LDO_123_VSET_BIT_MASK);
            regData |= (voutCode << BOARD_TPS65941_LDO_123_VSET_SHIFT);
        }

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].voltageRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        /* Enabling the LDO voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_LDO_EN_BIT_MASK);
        regData |= (1 << BOARD_TPS65941_LDO_EN_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cntrRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    return boardStatus;
}

/**
 * \brief   PMIC read voltage function.
 *
 * This function is used to read the voltage to the power resource of
 * the PMIC.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [OUT]   Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetVoltage(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint16_t *millivolt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) ||
       (powerResource > BOARD_TPS65941_LDO4_RESOURCE) ||
       (millivolt == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    if(powerResource <= BOARD_TPS65941_BUCK5_RESOURCE)
    {
        /* Reading the BUCK voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].voltageRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    else    /* LDO power resource */
    {
        /* Reading the LDO voltage */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].voltageRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if(powerResource == BOARD_TPS65941_LDO4_RESOURCE)
        {
            regData = (regData & BOARD_TPS65941_LDO4_VSET_BIT_MASK) >> BOARD_TPS65941_LDO4_VSET_SHIFT;
        }
        else
        {
            regData = (regData & BOARD_TPS65941_LDO_123_VSET_BIT_MASK) >> BOARD_TPS65941_LDO_123_VSET_SHIFT;
        }
    }

    boardStatus = Board_tps65941ConvertVolt(regData, powerResource, millivolt);
    if(boardStatus != BOARD_SOK)
    {
        return boardStatus;
    }

    return boardStatus;
}

/**
 * \brief   PMIC regulator status get function.
 *
 * This function is used to read the status of PMIC regulator
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   status          [OUT]   Status mask
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetRegStatus(void *handle,
                                        uint8_t slaveAddr,
                                        uint8_t powerResource,
                                        uint8_t *status)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) ||
       (powerResource > BOARD_TPS65941_LDO4_RESOURCE) ||
       (status == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Reading the status register voltage */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].statRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *status = (regData >> pwrResourceRegCfg[powerResource].statRegShift) & 0x0f;

    return boardStatus;
}

/**
 * \brief   PMIC Vmon status get function.
 *
 * This function is used to read the status of PMIC Vcca monitor
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   status          [OUT]   Status mask
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetVmonStatus(void *handle,
                                         uint8_t slaveAddr,
                                         uint8_t *status)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) ||
       (status == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Reading the status register voltage */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_STAT_VMON,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *status = regData & 0x03;

    return boardStatus;
}

/**
 * \brief   TPS65941 enable/disable interrupt function.
 *
 * This function is used to enable/disable the interrupt of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrType    	[IN]    TPS65941 Interrupt
 * \param   intrEnable  	[IN]    Enable/Disable the interrupt
 *                                  Valid values: BOARD_TPS65941_INTR_ENABLE
 *                                                BOARD_TPS65941_INTR_DISABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static Board_STATUS Board_tps65941SetIntr(void *handle,
                                          uint8_t slaveAddr,
                                          uint8_t intrType,
                                          uint16_t intrNum,
                                          uint8_t intrEnable)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regAddr  = 0;
    uint8_t regData  = 0;
    uint8_t regMask  = 0;
    uint8_t regShift = 0;

    regAddr = tps65941IntrRegMap[intrType].maskRegAddr;
    if(regAddr != 0)
    {
        if(!(intrNum >> BOARD_TPS65941_INTR_REG_WIDTH))
        {
            intrNum &= 0xFF;
            regAddr += intrNum / BOARD_TPS65941_INTR_REG_WIDTH;

            boardStatus = Board_i2c8BitRegRd(handle,
                                            slaveAddr,
                                            regAddr,
                                            &regData,
                                            BOARD_I2C_NUM_OF_BYTES_01,
                                            PMIC_I2C_TRANSACTION_TIMEOUT);
            if(boardStatus != BOARD_SOK)
            {
                return BOARD_I2C_TRANSFER_FAIL;
            }

            regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
            regMask  = (1 << regShift);

            if(intrEnable == BOARD_TPS65941_INTR_DISABLE)
            {
                regData |= regMask;
            }
            else
            {
                regData &= ~(regMask);
            }

            boardStatus = Board_i2c8BitRegWr(handle,
                                            slaveAddr,
                                            regAddr,
                                            &regData,
                                            BOARD_I2C_NUM_OF_BYTES_01,
                                            PMIC_I2C_TRANSACTION_TIMEOUT);
            if(boardStatus != BOARD_SOK)
            {
                return BOARD_I2C_TRANSFER_FAIL;
            }
        }
    }

    return boardStatus;
}

/**
 * \brief   TPS65941 enable/disable interrupt function.
 *
 * This function is used to enable/disable the interrupt of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID    	    [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \param   intrEnable  	[IN]    Enable/Disable the interrupt
 *                                  Valid values: BOARD_TPS65941_INTR_ENABLE
 *                                                BOARD_TPS65941_INTR_DISABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConfigIntr(void *handle,
                                      uint8_t slaveAddr,
                                      uint32_t intrID,
                                      uint8_t intrEnable)
{
    Board_STATUS boardStatus = BOARD_SOK;

    if((handle == NULL) || (intrEnable > BOARD_TPS65941_INTR_DISABLE))
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_tps65941SetIntr(handle, slaveAddr,
                                        ((intrID >> 16) & 0xFFFF),
                                        (intrID & 0xFFFF), intrEnable);

    return boardStatus;
}

/**
 * \brief   Get the TPS65941 interrupt function.
 *
 * This function is used to get the interrupt status of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID    	    [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \param   intrStatus      [OUT]   Interrupt status
 *                                  Valid value:
 *                                  BOARD_TPS65941_INTR_SET
 *                                  BOARD_TPS65941_INTR_UNSET
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetIntrStatus(void *handle,
                                         uint8_t slaveAddr,
                                         uint32_t intrID,
                                         uint8_t *intrStatus)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t intrType = 0;
    uint8_t intrNum = 0;
    uint8_t regAddr  = 0;
    uint8_t regData  = 0;
    uint8_t regMask  = 0;
    uint8_t regShift = 0;

    if((handle == NULL) || (intrStatus == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    intrType = (intrID >> 16) & 0xFFFF;
    intrNum = intrID & 0xFF;

    regAddr = tps65941IntrRegMap[intrType].intrRegAddr;

    if(intrType != BOARD_TPS65941_INTR_TYPE_GPIO)
    {
        regAddr += intrNum / BOARD_TPS65941_INTR_REG_WIDTH;
        regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
        regMask = 1 << regShift;
    }
    else
    {
        if(!((intrNum >> (BOARD_TPS65941_INTR_REG_WIDTH / 2)) > 0))
        {
            regAddr += 1;
            regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
            regMask = 1 << regShift;
        }
        else
        {
            regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
            if(regShift >= 3)
            {
                regShift -= 3;
            }
            regMask = 1 << regShift;
        }
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     regAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((regData & regMask) >> regShift)
    {
        *intrStatus = BOARD_TPS65941_INTR_SET;
    }
    else
    {
        *intrStatus = BOARD_TPS65941_INTR_UNSET;
    }
    return boardStatus;
}

/**
 * \brief   Clears the TPS65941 interrupt function.
 *
 * This function is used to clear the interrupt of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID          [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ClearIntr(void *handle,
                                     uint8_t slaveAddr,
                                     uint32_t intrID)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t intrType = 0;
    uint8_t intrNum = 0;
    uint8_t regAddr  = 0;
    uint8_t regData  = 0;
    uint8_t regMask  = 0;
    uint8_t regShift = 0;

    if((handle == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    intrType = (intrID >> 16) & 0xFFFF;
    intrNum = intrID & 0xFF;

    regAddr = tps65941IntrRegMap[intrType].intrRegAddr;
    if(intrType != BOARD_TPS65941_INTR_TYPE_GPIO)
    {
        regAddr += intrNum / BOARD_TPS65941_INTR_REG_WIDTH;
        regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
        regMask = 1 << regShift;
    }
    else
    {
        if(!((intrNum >> (BOARD_TPS65941_INTR_REG_WIDTH / 2)) > 0))
        {
            regAddr += 1;
            regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
            regMask = 1 << regShift;
        }
        else
        {
            regShift = intrNum % BOARD_TPS65941_INTR_REG_WIDTH;
            if(regShift >= 3)
            {
                regShift -= 3;
            }
            regMask = 1 << regShift;
        }
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     regAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((regData & regMask) >> regShift)
    {
        regData = 0x00;
        regData &= ~(regMask);
        regData |= regMask;

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         regAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    return boardStatus;
}

/**
 * \brief   Set the voltage monitoring function.
 *
 * This function is used to set the voltage monitoring function to
 * the BUCK and LDO power resources with PGOOD signal.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   powerResource   [IN]    TPS65941 Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   voltMonitorCfg  [IN]    TPS65941 voltage monitor details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVoltageMonitor(void *handle,
                                             uint8_t slaveAddr,
                                             uint8_t powerResource,
                                             Board_Tps65941VoltMonitorCfg *voltMonitorCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (voltMonitorCfg == NULL) ||
        (powerResource > BOARD_TPS65941_LDO4_RESOURCE))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting undervoltage and overvoltage values */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].pgRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_PWR_UV_THR_BIT_MASK);
    regData |= (voltMonitorCfg->voltUnderLimit >> BOARD_TPS65941_PWR_UV_THR_SHIFT);
    regData &= ~(BOARD_TPS65941_PWR_OV_THR_BIT_MASK);
    regData |= (voltMonitorCfg->voltOverLimit >> BOARD_TPS65941_PWR_OV_THR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].pgRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if(powerResource <= BOARD_TPS65941_BUCK5_RESOURCE)
    {
        /* Setting the current limit */
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cfgRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_BUCK_ILIM_BIT_MASK);
        regData |= (voltMonitorCfg->currentLimit >> BOARD_TPS65941_BUCK_ILIM_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         pwrResourceRegCfg[powerResource].cfgRegAddr,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    /* Setting Voltage monitor enable */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].cntrRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_PWR_VMON_EN_BIT_MASK);
    regData |= (voltMonitorCfg->regularEnable >> BOARD_TPS65941_PWR_VMON_EN_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].cntrRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Enabling PGOOD overvoltage monitoring */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_PGOOD_WINDOW_BIT_MASK);
    regData |= (voltMonitorCfg->overVoltEnable >> BOARD_TPS65941_PGOOD_WINDOW_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting PGOOD signal with voltage monitor */

    return boardStatus;

}

/**
 * \brief   Set the Vcca voltage monitoring function.
 *
 * This function is used to set the voltage monitoring function to
 * the Vcca with PGOOD signal.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   vccaPgLevel     [IN]    TPS65941 Vcca Power good level
 *                                  Valid values:
 *                                  BOARD_TPS65941_PG_3V3_LEVEL
 *                                  BOARD_TPS65941_PG_5V_LEVEL
 * \param   voltMonitorCfg  [IN]    TPS65941 voltage monitor details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVccaMonitor(void *handle,
                                          uint8_t slaveAddr,
                                          uint8_t vccaPgLevel,
                                          Board_Tps65941VoltMonitorCfg *voltMonitorCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (voltMonitorCfg == NULL) ||
        (vccaPgLevel > BOARD_TPS65941_PG_5V_LEVEL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting PGOOD window, undervoltage and overvoltage values */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_VCCA_PG_WINDOW,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_VCCA_PG_SET_BIT_MASK);
    regData |= (vccaPgLevel >> BOARD_TPS65941_VCCA_PG_SET_SHIFT);
    regData &= ~(BOARD_TPS65941_VCCA_UV_THR_BIT_MASK);
    regData |= (voltMonitorCfg->voltUnderLimit >> BOARD_TPS65941_VCCA_UV_THR_SHIFT);
    regData &= ~(BOARD_TPS65941_VCCA_OV_THR_BIT_MASK);
    regData |= (voltMonitorCfg->voltOverLimit >> BOARD_TPS65941_VCCA_OV_THR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_VCCA_PG_WINDOW,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Enabling voltage monitor */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_VCCA_VMON_CTRL,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_VCCA_VMON_EN_BIT_MASK);
    regData |= (BOARD_TPS65941_OV_UV_ENABLE >> BOARD_TPS65941_VCCA_VMON_EN_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_VCCA_PG_WINDOW,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Enabling PGOOD signal with VCCa voltage monitor */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_PGOOD_WINDOW_BIT_MASK);
    regData |= (voltMonitorCfg->overVoltEnable >> BOARD_TPS65941_PGOOD_WINDOW_SHIFT);
    regData &= ~(BOARD_TPS65941_PGOOD_VCCA_SEL_BIT_MASK);
    regData |= (voltMonitorCfg->pgoodEnable >> BOARD_TPS65941_PGOOD_VCCA_SEL_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Set the PMIC thermal threshold value function.
 *
 * This function is used to set the thermal temperature threshold
 * value for the PMIC.
 *
 * \param   handle                  [IN]    Low level driver handle
 * \param   slaveAddr               [IN]    PMIC slave address
 * \param   thermalThresholdVal     [IN]    Thermal temperature threshold value  //PR_CRC: Check the parameter name
 *                                          Valid Values: 
 *                                          BOARD_TPS65941_THERMAL_TEMP_120C
 *                                          BOARD_TPS65941_THERMAL_TEMP_130C
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetThermalThresVal(void *handle,
                                              uint8_t slaveAddr,
                                              uint32_t thermalThresholdVal)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) ||
       (thermalThresholdVal > BOARD_TPS65941_THERMAL_TEMP_130C))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting the thermal threshold value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_CONFIG_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_TWARN_LVL_BIT_MASK);
    regData |= (thermalThresholdVal << BOARD_TPS65941_TWARN_LVL_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_CONFIG_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Get the PMIC thermal status function.
 *
 * This function is used to read the thermal status of the PMIC.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    PMIC slave address
 * \param   thermalStatus       [OUT]   PMIC Thermal status
 *                                      Valid Value:
 *                                      BOARD_TPS65941_TDIE_NO_WARN    
 *                                      BOARD_TPS65941_TDIE_WARN       
 *                                      BOARD_TPS65941_TDIE_WARN_ORD_SD
 *                                      BOARD_TPS65941_TDIE_WARN_IMM_SD
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetThermalStatus(void *handle,
                                            uint8_t slaveAddr,
                                            uint32_t *thermalStatus)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0;

    if((handle == NULL) || (thermalStatus == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_STAT_MISC,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((regData & BOARD_TPS65941_TWARN_STAT_BIT_MASK) >> BOARD_TPS65941_TWARN_STAT_SHIFT)
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_STAT_MODERATE_ERR,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if((regData & BOARD_TPS65941_TSD_ORD_STAT_BIT_MASK) >> BOARD_TPS65941_TSD_ORD_STAT_SHIFT)
        {
            *thermalStatus = BOARD_TPS65941_TDIE_WARN_ORD_SD;
        }
        else
        {
            boardStatus = Board_i2c8BitRegRd(handle,
                                             slaveAddr,
                                             BOARD_TPS65941_STAT_SEVERE_ERR,
                                             &regData,
                                             BOARD_I2C_NUM_OF_BYTES_01,
                                             PMIC_I2C_TRANSACTION_TIMEOUT);
            if(boardStatus != BOARD_SOK)
            {
                return BOARD_I2C_TRANSFER_FAIL;
            }
    
            if((regData & BOARD_TPS65941_TSD_IMM_STAT_BIT_MASK) >> BOARD_TPS65941_TSD_IMM_STAT_SHIFT)
            {
                *thermalStatus = BOARD_TPS65941_TDIE_WARN_IMM_SD;
            }
            else
            {
                *thermalStatus = BOARD_TPS65941_TDIE_WARN;
            }
        }
    }
    else
    {
        *thermalStatus = BOARD_TPS65941_TDIE_NO_WARN;
    }

    return boardStatus;
}
/**
 * \brief   Set the thermal monitoring function.
 *
 * This function is used to set the thermal temperature monitoring
 * function with PGOOD signal.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    PMIC slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetThermalMonitor(void *handle,
                                             uint8_t slaveAddr)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting the thermal warning to affect PGOOD */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_PGOOD_TDIE_WARN_BIT_MASK);
    regData |= (1 << BOARD_TPS65941_PGOOD_TDIE_WARN_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_PGOOD_4,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Set the PMIC RTC date and time function.
 *
 * This function is used to set the date and time parameters in
 * RTC present in the PMIC.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   timeCfg         [IN]    PMIC RTC time configuration
 * \param   dateCfg         [IN]    PMIC RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetRtc(void *handle,
                                  uint8_t slaveAddr,
                                  Board_Tps65941RtcTime *timeCfg,
                                  Board_Tps65941RtcDate *dateCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData;

    if((handle == NULL) || (timeCfg == NULL) || (dateCfg == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Stopping the RTC */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_STOP_RTC_BIT_MASK);
    regData |= (BOARD_TPS65941_RTC_FROZEN << BOARD_TPS65941_STOP_RTC_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the seconds */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_SECONDS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_SEC_1_BIT_MASK);
    regData |= ((timeCfg->seconds/10) << BOARD_TPS65941_RTC_ALRM_SEC_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_SEC_0_BIT_MASK);
    regData |= ((timeCfg->seconds%10) << BOARD_TPS65941_RTC_ALRM_SEC_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_SECONDS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the minutes */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MINUTES,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_MIN_1_BIT_MASK);
    regData |= ((timeCfg->minutes/10) << BOARD_TPS65941_RTC_ALRM_MIN_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_MIN_0_BIT_MASK);
    regData |= ((timeCfg->minutes%10) << BOARD_TPS65941_RTC_ALRM_MIN_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MINUTES,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the hour mode */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_HOUR_MODE_BIT_MASK);
    regData |= (timeCfg->timeMode << BOARD_TPS65941_HOUR_MODE_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the hour */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_HOURS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_HR_1_BIT_MASK);
    regData |= ((timeCfg->hour/10) << BOARD_TPS65941_RTC_ALRM_HR_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_HR_0_BIT_MASK);
    regData |= ((timeCfg->hour%10) << BOARD_TPS65941_RTC_ALRM_HR_0_SHIFT);
    if(timeCfg->timeMode == BOARD_TPS65941_12_HOUR_MODE)
    {
        regData &= ~(BOARD_TPS65941_RTC_ALRM_AM_PM_BIT_MASK);
        regData |= (timeCfg->meridienMode << BOARD_TPS65941_RTC_ALRM_AM_PM_SHIFT);
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_HOURS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the day */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_DAYS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_DAY_1_BIT_MASK);
    regData |= ((dateCfg->date/10) << BOARD_TPS65941_RTC_ALRM_DAY_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_DAY_0_BIT_MASK);
    regData |= ((dateCfg->date%10) << BOARD_TPS65941_RTC_ALRM_DAY_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_DAYS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the month */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MONTHS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_MON_1_BIT_MASK);
    regData |= ((dateCfg->month/10) << BOARD_TPS65941_RTC_ALRM_MON_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_MON_0_BIT_MASK);
    regData |= ((dateCfg->month%10) << BOARD_TPS65941_RTC_ALRM_MON_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MONTHS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the year */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_YEARS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_YR_1_BIT_MASK);
    regData |= ((dateCfg->year/10) << BOARD_TPS65941_RTC_ALRM_YR_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_YR_0_BIT_MASK);
    regData |= ((dateCfg->year%10) << BOARD_TPS65941_RTC_ALRM_YR_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_YEARS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the week */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_WEEKS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_WEEK_BIT_MASK);
    regData |= (dateCfg->week << BOARD_TPS65941_RTC_WEEK_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_WEEKS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Restarting the RTC */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_STOP_RTC_BIT_MASK);
    regData |= (BOARD_TPS65941_RTC_START << BOARD_TPS65941_STOP_RTC_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Get the PMIC RTC date and time function.
 *
 * This function is used to get the current date and time parameters
 * in RTC present in the PMIC.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    PMIC slave address
 * \param   timeCfg             [OUT]   PMIC RTC time configuration
 * \param   dateCfg             [OUT]   PMIC RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetRtc(void *handle,
                                  uint8_t slaveAddr,
                                  Board_Tps65941RtcTime *timeCfg,
                                  Board_Tps65941RtcDate *dateCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;
    uint8_t data1, data2;

    if((handle == NULL) || (timeCfg == NULL) || (dateCfg == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting GET_TIME */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_GET_TIME_BIT_MASK);
    regData |= (1 << BOARD_TPS65941_GET_TIME_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Reading the seconds */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_SECONDS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_SEC_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_SEC_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_SEC_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_SEC_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    timeCfg->seconds = (data2 * 10) + data1;
    
    /* Reading the minutes */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MINUTES,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_MIN_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_MIN_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_MIN_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_MIN_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    timeCfg->minutes = (data2 * 10) + data1;

    /* Setting the hour mode */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((regData & BOARD_TPS65941_HOUR_MODE_BIT_MASK) >> BOARD_TPS65941_HOUR_MODE_SHIFT)
    {
        timeCfg->timeMode = BOARD_TPS65941_12_HOUR_MODE;
    }
    else
    {
        timeCfg->timeMode = BOARD_TPS65941_24_HOUR_MODE;
    }

    /* Reading the hour */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_HOURS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_HR_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_HR_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_HR_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_HR_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    timeCfg->hour = (data2 * 10) + data1;

    if((regData & BOARD_TPS65941_RTC_ALRM_AM_PM_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_AM_PM_SHIFT)
    {
        timeCfg->meridienMode = BOARD_TPS65941_PM_MODE;
    }
    else
    {
        timeCfg->meridienMode = BOARD_TPS65941_AM_MODE;
    }

    /* Reading the day */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_DAYS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_DAY_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_DAY_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_DAY_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_DAY_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    dateCfg->date = (data2 * 10) + data1;

    /* Reading the month */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_MONTHS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_MON_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_MON_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_MON_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_MON_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    dateCfg->month = (data2 * 10) + data1;

    /* Reading the year */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_YEARS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_ALRM_YR_0_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_YR_0_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    data2 = (regData & BOARD_TPS65941_RTC_ALRM_YR_1_BIT_MASK) >> BOARD_TPS65941_RTC_ALRM_YR_1_SHIFT;
    data2 = ((data2 >> 4) * 10) + (data2 & 0xF);
    dateCfg->year = (data2 * 10) + data1;

    /* Reading the week */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_WEEKS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    data1 = (regData & BOARD_TPS65941_RTC_WEEK_BIT_MASK) >> BOARD_TPS65941_RTC_WEEK_SHIFT;
    data1 = ((data1 >> 4) * 10) + (data1 & 0xF);
    dateCfg->week = data1;

    return boardStatus;
}

/**
 * \brief   Set the alarm interrupt in PMIC RTC function.
 *
 * This function is used to set the alarm date and time interrupt
 * in RTC present in the PMIC.
 *
 * \param   handle           [IN]    Low level driver handle
 * \param   slaveAddr        [IN]    PMIC slave address
 * \param   timeCfg          [IN]    PMIC RTC time configuration
 * \param   dateCfg          [IN]    PMIC RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetAlarmIntr(void *handle,
                                        uint8_t slaveAddr,
                                        Board_Tps65941RtcTime *timeCfg,
                                        Board_Tps65941RtcDate *dateCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData;

    if((handle == NULL) || (timeCfg == NULL) || (dateCfg == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Writing the seconds */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_SECONDS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_SEC_1_BIT_MASK);
    regData |= ((timeCfg->seconds/10) << BOARD_TPS65941_RTC_ALRM_SEC_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_SEC_0_BIT_MASK);
    regData |= ((timeCfg->seconds%10) << BOARD_TPS65941_RTC_ALRM_SEC_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_SECONDS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the minutes */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_MINUTES,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_MIN_1_BIT_MASK);
    regData |= ((timeCfg->minutes/10) << BOARD_TPS65941_RTC_ALRM_MIN_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_MIN_0_BIT_MASK);
    regData |= ((timeCfg->minutes%10) << BOARD_TPS65941_RTC_ALRM_MIN_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_MINUTES,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the hour mode */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_HOUR_MODE_BIT_MASK);
    regData |= (timeCfg->timeMode << BOARD_TPS65941_HOUR_MODE_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_CTRL_1,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the hour */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_HOURS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_HR_1_BIT_MASK);
    regData |= ((timeCfg->hour/10) << BOARD_TPS65941_RTC_ALRM_HR_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_HR_0_BIT_MASK);
    regData |= ((timeCfg->hour%10) << BOARD_TPS65941_RTC_ALRM_HR_0_SHIFT);
    if(timeCfg->timeMode == BOARD_TPS65941_12_HOUR_MODE)
    {
        regData &= ~(BOARD_TPS65941_RTC_ALRM_AM_PM_BIT_MASK);
        regData |= (timeCfg->meridienMode << BOARD_TPS65941_RTC_ALRM_AM_PM_SHIFT);
    }

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_HOURS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the day */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_DAYS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_DAY_1_BIT_MASK);
    regData |= ((dateCfg->date/10) << BOARD_TPS65941_RTC_ALRM_DAY_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_DAY_0_BIT_MASK);
    regData |= ((dateCfg->date%10) << BOARD_TPS65941_RTC_ALRM_DAY_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_DAYS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the month */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_MONTHS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_MON_1_BIT_MASK);
    regData |= ((dateCfg->month/10) << BOARD_TPS65941_RTC_ALRM_MON_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_MON_0_BIT_MASK);
    regData |= ((dateCfg->month%10) << BOARD_TPS65941_RTC_ALRM_MON_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_MONTHS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Writing the year */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_YEARS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RTC_ALRM_YR_1_BIT_MASK);
    regData |= ((dateCfg->year/10) << BOARD_TPS65941_RTC_ALRM_YR_1_SHIFT);
    regData &= ~(BOARD_TPS65941_RTC_ALRM_YR_0_BIT_MASK);
    regData |= ((dateCfg->year%10) << BOARD_TPS65941_RTC_ALRM_YR_0_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_ALARM_YEARS,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Enabling Alarm Interrupt */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_ALARM_INTR_BIT_MASK);
    regData |= (BOARD_TPS65941_ALARM_INTR_ENABLE << BOARD_TPS65941_ALARM_INTR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Set the timer interrupt in PMIC RTC function.
 *
 * This function is used to set the timer interrupt in RTC present
 * in the PMIC.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   timerPeriod     [IN]    Timer interrupt periods
 *                                  Valid values:
 *                                  BOARD_TPS65941_SECOND_INTR_PERIOD
 *                                  BOARD_TPS65941_MINUTE_INTR_PERIOD
 *                                  BOARD_TPS65941_HOUR_INTR_PERIOD
 *                                  BOARD_TPS65941_DAY_INTR_PERIOD
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetTimerIntr(void *handle,
                                        uint8_t slaveAddr,
                                        uint8_t timerPeriod)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (timerPeriod > BOARD_TPS65941_DAY_INTR_PERIOD))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting timer period for timer interrupt */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_TIMER_PERIOD_BIT_MASK);
    regData |= (timerPeriod << BOARD_TPS65941_TIMER_PERIOD_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Enabling the timer interrupt */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_TIMER_INTR_BIT_MASK);
    regData |= (BOARD_TPS65941_TIMER_INTR_ENABLE << BOARD_TPS65941_TIMER_INTR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RTC_INTR,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Enable/Disable the TPS65941 Watchdog function.
 *
 * This function is used to enable/disable the watchdog function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_DISABLE
 *                                  BOARD_TPS65941_WDT_ENABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdtDisable(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t wdtDisable)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0;

    if((handle == NULL) || 
       (wdtDisable > BOARD_TPS65941_WDT_ENABLE))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Enable/Disable the WDT */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_EN_BIT_MASK);
    regData |= (wdtDisable << BOARD_TPS65941_WDT_EN_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }   

    return boardStatus;
}

Board_STATUS Board_tps65941WdtDisablewithCRC(void *handle,
                                            uint8_t slaveAddr,
                                            uint8_t wdtDisable)
{
    Board_STATUS boardStatus;
    uint8_t regData[2] = {0};

    if((handle == NULL) || 
       (wdtDisable > BOARD_TPS65941_WDT_ENABLE))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Enable/Disable the WDT */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     &regData[0],
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData[0] &= ~(BOARD_TPS65941_WDT_EN_BIT_MASK);
    regData[0] |= (wdtDisable << BOARD_TPS65941_WDT_EN_SHIFT);

    regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_WDT_THR_CFG, regData[0]);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }   

    return boardStatus;
}


/**
 * \brief   TPS65941 watchdog configuration function.
 *
 * This function is used to configure the watchdog function parameters
 * in the TPS65941 in either trigger mode or Q&A (question and answer) mode.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtCfgMode      [IN]    Watchdog configuration mode
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_QA_MODE
 *                                  BOARD_TPS65941_WDT_TRIGGER_MODE
 * \param   wdtCfg          [IN]    TPS65941 watchdog configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdtConfig(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t wdtCfgMode,
                                     Board_Tps65941WdtCfg *wdtCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (wdtCfg == NULL) ||
       (wdtCfgMode > BOARD_TPS65941_WDT_QA_MODE))
    {
        return BOARD_INVALID_PARAM;
    }

    if((wdtCfg->win1Duration > 0x7F) || (wdtCfg->win2Duration > 0x7F))
    {
        return BOARD_INVALID_PARAM;
    }

    if((wdtCfg->failThreshold > 0x7) || (wdtCfg->rstThreshold > 0x7))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Setting Window1 value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_WIN1_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_WIN1_CFG_BIT_MASK);
    regData |= (wdtCfg->win1Duration << BOARD_TPS65941_WDT_WIN1_CFG_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_WIN1_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting Window2 value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_WIN2_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_WIN2_CFG_BIT_MASK);
    regData |= (wdtCfg->win2Duration << BOARD_TPS65941_WDT_WIN2_CFG_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_WIN2_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting Long Window value */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData = wdtCfg->longWinDuration;

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting WDT fail and reset threshold */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_RST_EN_BIT_MASK);
    regData |= (wdtCfg->rstEnable << BOARD_TPS65941_WDT_RST_EN_SHIFT);
    regData &= ~(BOARD_TPS65941_WDT_FAIL_THR_BIT_MASK);
    regData |= (wdtCfg->failThreshold << BOARD_TPS65941_WDT_FAIL_THR_SHIFT);
    regData &= ~(BOARD_TPS65941_WDT_RST_THR_BIT_MASK);
    regData |= (wdtCfg->rstThreshold << BOARD_TPS65941_WDT_RST_THR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_THR_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Setting the WDT mode */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_MODE_BIT_MASK);
    regData |= (wdtCfgMode << BOARD_TPS65941_WDT_MODE_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}


/**
 * \brief   TPS65941 watchdog error status function.
 *
 * This function is used to get the error status from the TPS65941 watchdog.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtErrType      [IN]    TPS65941 Watchdog error type
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_RST_INT
 *                                  BOARD_TPS65941_WDT_FAIL_INT
 *                                  BOARD_TPS65941_WDT_ANSW_ERR
 *                                  BOARD_TPS65941_WDT_SEQ_ERR
 *                                  BOARD_TPS65941_WDT_ANSW_ERLY_ERR
 *                                  BOARD_TPS65941_WDT_TRIG_ERLY_ERR
 *                                  BOARD_TPS65941_WDT_TIMEOUT_ERR
 *                                  BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_ERR
 * \param   wdtErrStat      [OUT]   TPS65941 Watchdog error status
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_ERR_LATCHED
 *                                  BOARD_TPS65941_WDT_NO_ERR
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetWdtStat(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t wdtErrType,
                                      uint8_t *wdtErrStat)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (wdtErrStat == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    *wdtErrStat = BOARD_TPS65941_WDT_NO_ERR;

    /* Reading the WDT Error status */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_ERR_STAT,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if(wdtErrType == BOARD_TPS65941_WDT_RST_INT)
    {
        if((regData & BOARD_TPS65941_WDT_RST_STAT_BIT_MASK) >> BOARD_TPS65941_WDT_RST_STAT_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_FAIL_INT)
    {
        if((regData & BOARD_TPS65941_WDT_FAIL_STAT_BIT_MASK) >> BOARD_TPS65941_WDT_FAIL_STAT_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_ANSW_ERR)
    {
        if((regData & BOARD_TPS65941_WDT_ANSW_ERR_BIT_MASK) >> BOARD_TPS65941_WDT_ANSW_ERR_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_SEQ_ERR)
    {
        if((regData & BOARD_TPS65941_WDT_SEQ_ERR_BIT_MASK) >> BOARD_TPS65941_WDT_SEQ_ERR_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_ANSW_ERLY_ERR)
    {
        if((regData & BOARD_TPS65941_WDT_ANSW_ERLY_BIT_MASK) >> BOARD_TPS65941_WDT_ANSW_ERLY_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_TRIG_ERLY_ERR)
    {
        if((regData & BOARD_TPS65941_WDT_TRIG_ERLY_BIT_MASK) >> BOARD_TPS65941_WDT_TRIG_ERLY_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else if(wdtErrType == BOARD_TPS65941_WDT_TIMEOUT_ERR)
    {
        if((regData & BOARD_TPS65941_WDT_TIMEOUT_BIT_MASK) >> BOARD_TPS65941_WDT_TIMEOUT_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }
    else    /* wdtErrType == BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_ERR */
    {
        if((regData & BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_BIT_MASK) >> BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_SHIFT)
        {
            *wdtErrStat = BOARD_TPS65941_WDT_ERR_LATCHED;
        }
    }

    return boardStatus;
}

/**
 * \brief   Start TPS65941 ESM function.
 *
 * This function is used the start the TPS65941 ESM for SoC or MCU in either
 * level or PWM mode.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmMode     [IN]    ESM configuration mode
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_LEVEL_MODE
 *                              BOARD_TPS65941_ESM_PWM_MODE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941StartEsm(void *handle,
                                    uint8_t slaveAddr,
                                    uint8_t esmCfg,
                                    uint8_t esmMode)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (esmCfg > BOARD_TPS65941_ESM_MCU) ||
       (esmMode > BOARD_TPS65941_ESM_PWM_MODE))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Start the ESM with the configuration mode */
    if(esmCfg == BOARD_TPS65941_ESM_SOC)
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_MODE_CFG,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_MODE_BIT_MASK);
        regData |= (esmMode << BOARD_TPS65941_ESM_MODE_SHIFT);
        regData &= ~(BOARD_TPS65941_ESM_EN_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_ENABLE << BOARD_TPS65941_ESM_EN_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_MODE_CFG,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_START_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_START << BOARD_TPS65941_ESM_START_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    else    /* esmCfg == BOARD_TPS65941_ESM_MCU */
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_MODE_CFG,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_MODE_BIT_MASK);
        regData |= (esmMode << BOARD_TPS65941_ESM_MODE_SHIFT);
        regData &= ~(BOARD_TPS65941_ESM_EN_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_ENABLE << BOARD_TPS65941_ESM_EN_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_MODE_CFG,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_START_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_START << BOARD_TPS65941_ESM_START_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    return boardStatus;
}

/**
 * \brief   Stop TPS65941 ESM function.
 *
 * This function is used the stop the TPS65941 ESM for SoC or MCU.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941StopEsm(void *handle,
                                   uint8_t slaveAddr,
                                   uint8_t esmCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (esmCfg > BOARD_TPS65941_ESM_MCU))
    {
        return BOARD_INVALID_PARAM;
    }

    if(esmCfg == BOARD_TPS65941_ESM_SOC)
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_START_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_STOP << BOARD_TPS65941_ESM_START_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    else    /* esmCfg == BOARD_TPS65941_ESM_MCU */
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData &= ~(BOARD_TPS65941_ESM_START_BIT_MASK);
        regData |= (BOARD_TPS65941_ESM_STOP << BOARD_TPS65941_ESM_START_SHIFT);

        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_START,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    return boardStatus;
}

/**
 * \brief   TPS65941 ESM configuration function.
 *
 * This function is used to configure the TPS65941 ESM parameters.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfgType  [IN]    ESM configuration type
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmCfg      [IN]    TPS65941 ESM configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConfigEsm(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t esmCfgType,
                                     Board_Tps65941EsmCfg *esmCfg)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (esmCfg == NULL) ||
       (esmCfgType > BOARD_TPS65941_ESM_MCU))
    {
        return BOARD_INVALID_PARAM;
    }

    if(esmCfgType == BOARD_TPS65941_ESM_SOC)
    {
        regData = esmCfg->delay1TimeInterval;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_DELAY1,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->delay2TimeInterval;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_DELAY2,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->maxHPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_HMAX,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->minHPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_HMIN,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->maxLPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_LMAX,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->minLPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_LMIN,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    else    /* esmCfgType == BOARD_TPS65941_ESM_MCU */
    {
        regData = esmCfg->delay1TimeInterval;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_DELAY1,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->delay2TimeInterval;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_DELAY2,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->maxHPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_HMAX,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->minHPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_HMIN,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->maxLPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_LMAX,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        regData = esmCfg->minLPTimeThreshold;
        boardStatus = Board_i2c8BitRegWr(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_LMIN,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    return boardStatus;
}

/**
 * \brief   Get the ESM error count function.
 *
 * This function is used to get the number error count events for the
 * TPS65941 ESM for SoC or MCU.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmErrCnt   [OUT]   TPS65941 ESM error count
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetEsmCount(void *handle,
                                       uint8_t slaveAddr,
                                       uint8_t esmCfg,
                                       uint8_t *esmErrCnt)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) || (esmErrCnt == NULL) ||
       (esmCfg > BOARD_TPS65941_ESM_MCU))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Reading the ESM Error count */
    if(esmCfg == BOARD_TPS65941_ESM_SOC)
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_SOC_ERR_CNT,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
        *esmErrCnt = (regData & BOARD_TPS65941_ESM_ERR_CNT_BIT_MASK) >> BOARD_TPS65941_ESM_ERR_CNT_SHIFT;
    }
    else    /* esmCfg == BOARD_TPS65941_ESM_MCU */
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_ESM_MCU_ERR_CNT,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
        *esmErrCnt = (regData & BOARD_TPS65941_ESM_ERR_CNT_BIT_MASK) >> BOARD_TPS65941_ESM_ERR_CNT_SHIFT;
    }

    return boardStatus;
}

/**
 * \brief   PMIC set UV/OV Threshold values.
 *
 * This function is used to set the UV/OV THreshold to the power resource of
 * the PMIC.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    PMIC slave address
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [IN]    Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetUVOVThreshold(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint8_t UVthreshold,
                                      uint8_t OVthreshold)
{

    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if((handle == NULL) ||
        (powerResource > BOARD_TPS65941_LDO4_RESOURCE) ||
        (UVthreshold > 0x07) ||
        (OVthreshold > 0x07))
    {
        return BOARD_INVALID_PARAM;
    }

    regData = (UVthreshold << BOARD_TPS65941_PWR_UV_THR_SHIFT) | (OVthreshold << BOARD_TPS65941_PWR_OV_THR_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     pwrResourceRegCfg[powerResource].pgRegAddr,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   TPS65941 GPIO2_CNF
 *
 * This function is used to configure the TPS65941 GPIO 2 to TRIG MODE or I2C
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   val             [IN]    GPIO2 configuration settings(Reg= 0x34)
 *                                  Valid values:
 *                                  0x00-0xFF
 * \return  BOARD_SOK in case of success or appropriate error code.
 */

Board_STATUS Board_tps65941SetGPIO2(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t val)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    /* GPIO_2 Config */
    boardStatus = Board_i2c8BitRegRd(handle,
                                        slaveAddr,
                                        BOARD_TPS65941_GPIO2_CONF,
                                        &regData,
                                        BOARD_I2C_NUM_OF_BYTES_01,
                                        PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((0x2A == regData) && (0x2A == val))/* GPIO_2 TRIG_MODE*/
    {
        return boardStatus;
    }

    else
    {
        regData = val;
        boardStatus = Board_i2c8BitRegWr(handle,
                                        slaveAddr,
                                        BOARD_TPS65941_GPIO2_CONF,
                                        &regData,
                                        BOARD_I2C_NUM_OF_BYTES_01,
                                        PMIC_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }
    return boardStatus;

}

Board_STATUS Board_tps65941SetGPIO2withCRC(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t val)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData[2] = {0};

    /* GPIO_2 Config */
    boardStatus = Board_i2c8BitRegRd(handle,
                                    slaveAddr,
                                    BOARD_TPS65941_GPIO2_CONF,
                                    &regData[0],
                                    BOARD_I2C_NUM_OF_BYTES_02,
                                    PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    if((0x2A == regData[0]) && (0x2A == val))
    {
        return BOARD_SOK;
    }

    regData[0] = val; /* GPIO_2 TRIG_MODE*/
    regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_GPIO2_CONF, regData[0]);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_GPIO2_CONF,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    /* Read the status */
    boardStatus = Board_i2c8BitRegRd(handle,
                                    slaveAddr,
                                    BOARD_TPS65941_GPIO2_CONF,
                                    &regData[0],
                                    BOARD_I2C_NUM_OF_BYTES_02,
                                    PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;

}

/**
 * \brief  TPS65941 Enter or exit to Long Window
 *
 * This function is used to return to Long Window or exit window
 * In  TPS65941 in either Long Window or exit Window.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   val             [IN]    Valid values:
 *                                  1 - Enter to Long Window
 *                                  0 - Exit from Long Window


 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941RetToLongWin(void *handle,
                                        uint8_t slaveAddr,
                                        uint8_t val)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
         return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_LONGWIN_RET_BIT_MASK);
    regData |= (val << BOARD_TPS65941_WDT_LONGWIN_RET_SHIFT);


    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
         return BOARD_I2C_TRANSFER_FAIL;
    }    

    return boardStatus;
}

Board_STATUS Board_tps65941RetToLongWinwithCRC(void *handle,
                                                uint8_t slaveAddr,
                                                uint8_t val)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData[2] = {0};

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData[0],
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
         return BOARD_I2C_TRANSFER_FAIL;
    }

    regData[0] &= ~(BOARD_TPS65941_WDT_LONGWIN_RET_BIT_MASK);
    regData[0] |= (val << BOARD_TPS65941_WDT_LONGWIN_RET_SHIFT);

    regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_WDT_MODE_REG, regData[0]); 

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData[0],
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
         return BOARD_I2C_TRANSFER_FAIL;
    }    

    return boardStatus;
}

/**
 * \brief   Set/Clear the TPS65941 WDG PWR HOLD register.
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdPwrhold(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t value)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0;

    if((handle == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Set/clear the WDT Power hold*/
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_WDT_PWRHOLD_BIT_MASK);
    regData |= (value << BOARD_TPS65941_WDT_PWRHOLD_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_MODE_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}

/**
 * \brief   Clear the TPS65941 Recovery Counter
 *
 * This function is used to set/clear the watchdog powerhold function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  0
 *                                  1
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941RecovCounterClear(void *handle,uint8_t slaveAddr)
{
    Board_STATUS boardStatus;
    uint8_t regData = 0;

    if((handle == NULL))
    {
        return BOARD_INVALID_PARAM;
    }

    /* Set/clear the WDT Power hold*/
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RECOV_CNT,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData &= ~(BOARD_TPS65941_RECOV_CNT_BIT_MASK);
    regData |= (1U << BOARD_TPS65941_RECOV_CNT_SHIFT);

    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_RECOV_CNT,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;
}
/**
 * \brief   TPS65941 watchdog Long Windows status function.
 *
 * This function is used to get the error status from the TPS65941 watchdog.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtErrStat      [OUT]   TPS65941 Watchdog Long window status
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_ERR_LATCHED
 *                                  BOARD_TPS65941_WDT_NO_ERR
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetWdtFirstOkStat(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t *wdtFirstOK)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    if(handle == NULL)
    {
        return BOARD_INVALID_PARAM;
    }

    *wdtFirstOK = BOARD_TPS65941_WDT_FIRST_OK; //Assuming it will be good in most cases

    /* Reading the WDT Error status */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_FAIL_CNT_REG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    *wdtFirstOK = ((regData & BOARD_TPS65941_WDT_FIRST_OK_BIT_MASK) >> BOARD_TPS65941_WDT_FIRST_OK_SHIFT);

    return boardStatus;
}

/**
 * \brief   TPS65941 watchdog long window configuration function.
 *
 * This function is used to configure the watchdog long window parameter
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtCfglongWin   [IN]    TPS65941 watchdog configuration
 *                                  Long Window Duration: 
 *                                  Ranges->  0x00: 80 ms
 *                                            0x01 - 0x40: 125 ms to 8 sec, in 125 ms steps
 *                                            0x41 - 0xFF: 12 sec to 772 sec, in 4 sec steps
 *                                            0x42: 16 sec  0x43: 20 sec  
 *                                  Observed 1 -> 0xFF: 772 Sec, 0x28: 5 Sec, 0x46: 20 Sec
 *                                  Observed 2 -> 0x4F: 68 Sec, 0x40: 8 Sec, 0x30: 6 Sec
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdtLongWinConfig(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t wdtCfglongWin)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData = 0;

    /* Setting Long Window value */
    /* Reading the long window value from PMIC */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData = wdtCfglongWin;

    /* Writing the long window value to PMIC */
    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }    

    /* Reading the long window value from PMIC after writing */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData,
                                     BOARD_I2C_NUM_OF_BYTES_01,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;                                   
}

Board_STATUS Board_tps65941WdtLongWinConfigwithCRC(void *handle,
                                                    uint8_t slaveAddr,
                                                    uint8_t wdtCfglongWin)
{
    Board_STATUS boardStatus = BOARD_SOK;
    uint8_t regData[2] = {0};

    /* Setting Long Window value */
    /* Reading the long window value from PMIC */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData[0],
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    regData[0] = wdtCfglongWin;
    regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_WDT_LONGWIN_CFG, regData[0]);    

    /* Writing the long window value to PMIC */
    boardStatus = Board_i2c8BitRegWr(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     regData,
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }    

    /* Reading the long window value from PMIC after writing */
    boardStatus = Board_i2c8BitRegRd(handle,
                                     slaveAddr,
                                     BOARD_TPS65941_WDT_LONGWIN_CFG,
                                     &regData[0],
                                     BOARD_I2C_NUM_OF_BYTES_02,
                                     PMIC_I2C_TRANSACTION_TIMEOUT);
    if(boardStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }

    return boardStatus;                                   
}

Board_STATUS Board_PMIC_ReadWdgINTValCRC(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t crc,
                                      uint8_t *intval)
{
    uint8_t regData1 = 0;
    Board_STATUS boardStatus;
    uint8_t regData[2] = {0};

    if(TRUE != crc)
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                        slaveAddr,
                                        BOARD_TPS65941_WDT_ERR_STAT,
                                        &regData1,
                                        BOARD_I2C_NUM_OF_BYTES_01,
                                        BOARD_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        *intval = regData1;                                       
    }
    else
    {
        boardStatus = Board_i2c8BitRegRd(handle,
                                        slaveAddr,
                                        BOARD_TPS65941_WDT_ERR_STAT,
                                        &regData[0],
                                        BOARD_I2C_NUM_OF_BYTES_02,
                                        BOARD_I2C_TRANSACTION_TIMEOUT);
        if(boardStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        *intval = regData[0]; 
    }

    return boardStatus;
}

/*
*   API to Soft Reboot PMIC
*/
void Board_PMIC_SoftReset(void *pmic_handle, uint8_t slaveAddr, uint8_t crc)
{
    uint8_t regData1 = 0;
    uint8_t regData[2] = {0};

    if(TRUE != crc)
    {
        regData1 = BOARD_TPS65941_REG_UNLOCK_KEY;
        /* Unlock the registers */
        Board_i2c8BitRegWr(pmic_handle,
                            slaveAddr,
                            BOARD_TPS65941_REGISTER_LOCK_REG,
                            &regData1,
                            BOARD_I2C_NUM_OF_BYTES_01,
                            BOARD_I2C_TRANSACTION_TIMEOUT);

        regData1 = BOARD_TPS65941_LEOA_SOFT_REBOOT_VAL;
        /* Write this command for PMIC soft reboot */
        Board_i2c8BitRegWr(pmic_handle,
                            slaveAddr,
                            BOARD_TPS65941_LEOA_SOFT_REBOOT_REG,
                            &regData1,
                            BOARD_I2C_NUM_OF_BYTES_01,
                            BOARD_I2C_TRANSACTION_TIMEOUT);
    }
    else
    {
        regData[0] = BOARD_TPS65941_REG_UNLOCK_KEY;
        regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_REGISTER_LOCK_REG, regData[0]);
        /* Unlock the registers */
        Board_i2c8BitRegWr(pmic_handle,
                            slaveAddr,
                            BOARD_TPS65941_REGISTER_LOCK_REG,
                            &regData[0],
                            BOARD_I2C_NUM_OF_BYTES_02,
                            BOARD_I2C_TRANSACTION_TIMEOUT);

        regData[0] = BOARD_TPS65941_LEOA_SOFT_REBOOT_VAL;
        regData[1] = Board_tps65941CalculateCRC(slaveAddr, BOARD_TPS65941_LEOA_SOFT_REBOOT_REG, regData[0]);
        /* Write this command for PMIC soft reboot */
        Board_i2c8BitRegWr(pmic_handle,
                            slaveAddr,
                            BOARD_TPS65941_LEOA_SOFT_REBOOT_REG,
                            &regData[0],
                            BOARD_I2C_NUM_OF_BYTES_02,
                            BOARD_I2C_TRANSACTION_TIMEOUT);
    }
}

