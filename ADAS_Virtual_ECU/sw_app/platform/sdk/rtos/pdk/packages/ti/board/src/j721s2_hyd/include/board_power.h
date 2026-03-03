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
 *  \file   board_power.h
 *
 *  \brief  Board functions for PMIC
 *
 */

#ifndef _BOARD_POWER_H_
#define _BOARD_POWER_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/board/board.h>
#include <ti/csl/tistdtypes.h>
#include <stdio.h>
#include <stdbool.h>
#include <ti/drv/i2c/I2C.h>

#define BOARD_PMIC_LP87561_I2C_SLAVE_ADDR  (0x61U)
#define BOARD_PMIC_LP87561_I2C_INSTANCE    (0x00U)
#define BOARD_PMIC_LP87561_BUCK0_VOUT_REG  (0x0AU)
#define BOARD_PMIC_LP87561_VOLTAGE_0V9_VAL (0x39U)

#define BOARD_PMIC_I2C_SLAVE_ADDR        (0x58U)
#define BOARD_PMIC_I2C_INSTANCE            (0)
#define BOARD_PMIC_LDO1_CTRL_REG           (0x50U)
#define BOARD_PMIC_LDO1_VOLTAGE_REG        (0x51U)
#define BOARD_PMIC_LDO1_VSEL_3V3           (0x31U)
#define BOARD_PMIC_LDO1_VSEL_1V8           (0x13U)

/* GPIO port and pin numbers for SDIO 1V8 enable */
#define BOARD_SDIO_1V8_EN_PIN_NUM          (26U)
//#define BOARD_SDIO_1V8_EN_PIN_NUM             (8U) //GPIO0_8 - SEL_SDIO_3V3_1V8n //Definition present in board_utils.h file.

/* Fisker Macro */
#define BOARD_HYDRA_I2C_PMIC_MASTER_ADDR     (0x48U)
#define BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR      (0x4CU)
#define BOARD_HYDRA_I2C_PMIC_WDG_SLAVE_ADDR  (0x12U)
#define BOARD_HYDRA_PMIC_I2C_INSTANCE        (0)
#define NUM_PMIC_CONFIG                      (1u) //(18u)
#define BOARD_HYDRA_I2C_PMIC_SLAVE_ADDR_HERA    (0x50U)
#define BOARD_HYDRA_I2C_PMIC_HERA_WDG_SLAVE_ADDR  (0x14U)

/** Board status FAIL */
#define BOARD_REG_CRC_ERR_MASK_READ_FAIL                    (-11)
#define BOARD_REG_CRC_ERR_MASK_WRITE_FAIL                   (-12)
#define BOARD_REG_CRC_LPM_EN_READ_FAIL                      (-13)
#define BOARD_REG_CRC_LPM_EN_WRITE_FAIL                     (-14)
#define BOARD_REG_CRC_READ_FAIL                             (-15)
#define BOARD_REG_CRC_WRITE_FAIL                            (-16)
#define BOARD_REG_WDG_ADDR_READ_FAIL                        (-17)
#define BOARD_REG_WDG_ADDR_WRITE_FAIL                       (-18)

#define BOARD_REG_NVM_UNLOCK_FAILED                         (-19)
#define BOARD_REG_NVM_LOCK_FAILED                           (-20)
#define BOARD_REG_NVM_LOCK_STATUS_READ_FAILED               (-21)

#define PMIC_HERA_SLAVE_ADDRESS                             (0x50U)
#define PMIC_HERA_SLAVE_NVM_ADDRESS                         (0x51U)

/* PMIC HERA Register Address */
#define PMIC_HERA_REG_CRC                                   (0x18U)
#define PMIC_HERA_REG_WDG_ADDR                              (0x23U)
#define PMIC_HERA_REG_CRC_ERR_MASK                          (0x54U)
#define PMIC_HERA_REG_CRC_LPM_EN                            (0x81U)
#define PMIC_HERA_REG_NVM_LOCK                              (0xA2U)
#define PMIC_HERA_REG_NVM_LOCK_STATUS                       (0xA3U)

/* PMIC HERA NvM Unlcok Sequence Macros */
#define PMIC_HERA_NVM_UNLOCK_SEQ_1                          (0x98U)
#define PMIC_HERA_NVM_UNLOCK_SEQ_2                          (0xB8U)
#define PMIC_HERA_NVM_UNLOCK_SEQ_3                          (0x13U)
#define PMIC_HERA_NVM_UNLOCK_SEQ_4                          (0x7DU)
#define PMIC_HERA_NVM_LOCK                                  (0x00U)
#define PMIC_HERA_NVM_LOCK_STATUS                           (0x80U)     

/* PMIC HERA Register Bit & Mask */
#define PMIC_TPS65941_REG_CRC_ERR_MASK_SHIFT                (0x02U)
#define PMIC_TPS65941_REG_CRC_ERR_MASK_BIT_MASK             (uint8_t)(0x01 << PMIC_TPS65941_REG_CRC_ERR_MASK_SHIFT)

#define PMIC_TPS65941_REG_LPM_EN_SHIFT                      (0x02U)
#define PMIC_TPS65941_REG_LPM_EN_BIT_MASK                   (uint8_t)(0x01 << PMIC_TPS65941_REG_LPM_EN_SHIFT)


typedef enum
{
  UV_OV_3_PERCENT = 0u,
  UV_OV_3_5_PERCENT = 1u,
  UV_OV_4_PERCENT = 2u,
  UV_OV_5_PERCENT = 3u,
  UV_OV_6_PERCENT = 4u,
  UV_OV_7_PERCENT = 5u,
  UV_OV_8_PERCENT = 6u,
  UV_OV_10_PERCENT = 7u,
  UV_OV_INVALID = 0x8u,
} PMIC_UV_OV_THRESHOLD_VALUE;

typedef struct pmic_ovuv_threshold_reg {
    uint8_t slaveAddr;
    uint8_t powerResource;
    uint8_t UVthreshold;
    uint8_t OVthreshold;
}pmic_ovuv_threshold_reg;

Board_STATUS Board_PMIC_Init(void);

int32_t PMIC_Read(uint8_t slaveaddr, uint8_t regaddr, uint8_t *regData);
int32_t PMIC_Write(uint8_t slaveaddr, uint8_t regaddr, uint8_t regData);

uint8_t PMIC_Test_Read_Hera(uint8_t regaddr);

void PMIC_EnterLongWindow_DisableWdg(void);

Board_STATUS PMIC_Disable_Wdg(void);

Board_STATUS PMIC_EnterLongWindow_Wdg(uint8_t i2c1CrcStatus);
Board_STATUS PMIC_Cfg_SetGPIO2(uint8_t i2c1CrcStatus);
Board_STATUS PMIC_Cfg_LongWindow_SetGPIO2(uint8_t i2c1CrcStatus);
uint8_t PMIC_ReadWdgINTVal(uint8_t i2c1CrcStatus);
int32_t PMIC_Update_HERA_Wdg_Slave_Addr(void);
uint8_t PMIC_GetCRCStatus(void);

void PMIC_SoftReset(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_POWER_H_ */
