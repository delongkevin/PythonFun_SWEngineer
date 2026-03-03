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

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOARD_POWER_H_ */
