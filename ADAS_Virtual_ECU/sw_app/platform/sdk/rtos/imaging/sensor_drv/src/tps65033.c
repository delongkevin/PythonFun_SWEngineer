/*******************************************************************************
 * tps650033.c
 *
 * TPS65033 Camera PMIC module
 *
 * Copyright (c) 2023 Cogent Embedded Inc.
 * ALL RIGHTS RESERVED.
 *
 * The source code contained or described herein and all documents related to the
 * source code("Software") or their modified versions are owned by
 * Cogent Embedded Inc. or its affiliates.
 *
 * No part of the Software may be used, copied, reproduced, modified, published,
 * uploaded, posted, transmitted, distributed, or disclosed in any way without
 * prior express written permission from Cogent Embedded Inc.
 *
 * Cogent Embedded Inc. grants a nonexclusive, non-transferable, royalty-free
 * license to use the Software to Licensee without the right to sublicense.
 * Licensee agrees not to distribute the Software to any third-party without
 * the prior written permission of Cogent Embedded Inc.
 *
 * Unless otherwise agreed by Cogent Embedded Inc. in writing, you may not remove
 * or alter this notice or any other notice embedded in Software in any way.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *******************************************************************************/
#include <iss_sensor_priv.h>

#include "tps65033.h"
#include "i2c_helpers.h"

#include "crc8.h"

#define TPS65033_PID (0xdf)
#define TPS65033_RID (0x19)

#define TPS65033_I2C_READ_CRC_ERR (-100)

/* Registers definitions */

#define TPS65033_PID_REG                    (0x0)

#define TPS65033_RID_REG                    (0x1)

#define TPS65033_CONTROL_LOCK_REG           (0x2)
#define TPS65033_CONTROL_LOCK               (0x0)
#define TPS65033_CONTROL_UNLOCK             (0xdd)

#define TPS65033_GPIO_CTRL_REG              (0x4)
#define TPS65033_GPIO_CTRL_CFG_CRC_EN       (1 << 2)

#define TPS65033_CONFIG_LOCK_REG            (0x5)
#define TPS65033_CONFIG_LOCK                (0x0)
#define TPS65033_CONFIG_UNLOCK              (0xaa)

#define TPS65033_INT_MASK_BUCKX_LDO_REG     (0x1e)

#define TPS65033_FAULT_STATUS_BUCK1         (0x1f)
#define TPS65033_FAULT_STATUS_BUCK1_PVIN_UVLO (1 << 6)
#define TPS65033_FAULT_STATUS_BUCK2         (0x20)
#define TPS65033_FAULT_STATUS_BUCK3         (0x21)
#define TPS65033_FAULT_STATUS_LDO           (0x22)

#define TPS65033_ERR_BUCKX_LDO_CFG_REG      (0x27)

#define TPS65033_CFG_REG_CRC                (0x29)

#define TPS65033_DEV_ERR_ACK1_REG           (0x2b)
#define TPS65033_DEV_ERR_ACK2_REG           (0x2c)
#define TPS65033_DEV_ERR_ACK2_I2C_CRC       (1 << 0)

#define TPS65033_DEV_FAULT_STS1_REG         (0x2d)
#define TPS65033_DEV_FAULT_STS2_REG         (0x2e)
#define TPS65033_DEV_FAULT_STS2_NVM_CRC     (1 << 2)

#define TPS65033_INT_MASK_SAFETY_REG        (0x2f)
#define TPS65033_INT_MASK_SAFETY_I2C_CRC_ERR (1 << 0)

#define CFG_REGS_NUM 27

#define READ_STATUS_RETRY_NUM 3

#define TPS65033_I2C_ADDR                   (0x60)

#define CAMERA_PMIC_ERR_LOGS
#define RETURN_ON_ERROR(err) \
    ({                       \
        if (err != 0)        \
        {                    \
            return err;      \
        }                    \
    })

typedef struct
{
    uint8_t reg;
    uint8_t mask;
} cfg_reg_t;

static cfg_reg_t cfg_regs[CFG_REGS_NUM] = {
    {.reg = 0x06, .mask = 0x3f}, // LDO_GPIO_CFG
    {.reg = 0x07, .mask = 0x1f}, // BUCK1_VOUT
    {.reg = 0x08, .mask = 0x0f}, // BUCK1_UVLO
    {.reg = 0x09, .mask = 0x1f}, // BUCK2_VOUT
    {.reg = 0x0a, .mask = 0x1f}, // BUCK3_VOUT
    {.reg = 0x0b, .mask = 0x1f}, // LDO_VOUT
    {.reg = 0x0c, .mask = 0xff}, // DISCHARGE_SETTING
    {.reg = 0x0d, .mask = 0x3f}, // SEQ_TRIG_BUCK1
    {.reg = 0x0e, .mask = 0x3f}, // SEQ_TRIG_BUCK2
    {.reg = 0x0f, .mask = 0x3f}, // SEQ_TRIG_BUCK3
    {.reg = 0x10, .mask = 0x3f}, // SEQ_TRIG_LDO
    {.reg = 0x11, .mask = 0x7f}, // SEQ_TRIG_nRSTOUT
    {.reg = 0x12, .mask = 0x7f}, // SEQ_TRIG_GPIO
    {.reg = 0x13, .mask = 0xff}, // BUCK1_SEQ_DLY
    {.reg = 0x14, .mask = 0xff}, // BUCK2_SEQ_DLY
    {.reg = 0x15, .mask = 0xff}, // BUCK3_SEQ_DLY
    {.reg = 0x16, .mask = 0xff}, // LDO_SEQ_DLY
    {.reg = 0x17, .mask = 0xff}, // nRSTOUT_SEQ_DLY
    {.reg = 0x18, .mask = 0xff}, // GPIO_SEQ_DLY
    {.reg = 0x1e, .mask = 0xff}, // INT_MASK_BUCKx_LDO
    {.reg = 0x23, .mask = 0x0f}, // VMON_BUCK1_CFG
    {.reg = 0x24, .mask = 0x0f}, // VMON_BUCK2_CFG
    {.reg = 0x25, .mask = 0x0f}, // VMON_BUCK3_CFG
    {.reg = 0x26, .mask = 0x0f}, // VMON_LDO_CFG
    {.reg = 0x27, .mask = 0xff}, // ERR_BUCKx_LDO_CFG
    {.reg = 0x2f, .mask = 0x03}, // INT_MASK_SAFETY
    {.reg = 0x30, .mask = 0x03}, // PIN_MON_ERR_CFG
};

/* Private functions */

static int32_t tps65033_get_reg8_crc(struct i2c_client *client, uint8_t reg, uint8_t *data)
{
    I2C_Transaction transaction;
    int16_t ret;
    crc8_t crc8;
    uint8_t rx[2];
    uint8_t crc_data[4];

    if ((client == NULL) || (client->adapter == NULL))
        return -2;

    /* Initializes the I2C transaction structure */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = &reg;
    transaction.writeCount   = 1;
    transaction.readBuf      = rx;
    transaction.readCount    = 2;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);
    ret = i2c_ret_to_err(ret);
    if (ret)
    {
        appLogPrintf("TPS65033[0x%x] read failure: %d\n", client->addr, ret);
        return ret;
    }

    *data = rx[0];

    /* Calculate expected CRC value */
    /* client->addr is mapped one, but CRC uses original addr */
    crc_data[0] = (TPS65033_I2C_ADDR << 1);
    crc_data[1] = reg;
    crc_data[2] = (TPS65033_I2C_ADDR << 1) | 0x1;
    crc_data[3] = rx[0];
    crc8 = crc8_init();
    crc8 = crc8_update(crc8, crc_data, 4);
    crc8 = crc8_finalize(crc8);

    /* Check CRC */
    if (crc8 != rx[1])
    {
        appLogPrintf("TPS65033[0x%x] read: CRC mismatch: is 0x%x, expected 0x%x\n", client->addr, rx[1], crc8);
        return TPS65033_I2C_READ_CRC_ERR;
    }

    return 0;
}

static uint32_t tps65033_get_reg8_crc_retry3(struct i2c_client *client, uint8_t reg, uint8_t *val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = tps65033_get_reg8_crc(client, reg, val)));

    if (ret) appLogPrintf("%s: client = 0x%x; ret = %d!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n", __FUNCTION__, client->addr, ret);

    return ret;
}

static int32_t tps65033_set_reg8_crc(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    I2C_Transaction transaction;
    int16_t ret;
    crc8_t  crc8;
    uint8_t data[3];

    if ((client == NULL) || (client->adapter == NULL))
        return -2;

    /* Calculate CRC for write command */
    /* client->addr is mapped one, but CRC uses original addr */
    data[0] = TPS65033_I2C_ADDR << 1;
    data[1] = reg;
    data[2] = val;
    crc8 = crc8_init();
    crc8 = crc8_update(crc8, data, 3);
    crc8 = crc8_finalize(crc8);

    /* Prepare write command */
    data[0] = reg;
    data[1] = val;
    data[2] = crc8;

    /* Initializes the I2C transaction structure */
    I2C_transactionInit(&transaction);
    transaction.slaveAddress = client->addr;
    transaction.writeBuf     = data;
    transaction.writeCount   = 3;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;
    transaction.timeout      = DEF_I2C_TIMEOUT;

    ret = I2C_transfer(client->adapter, &transaction);
    ret = i2c_ret_to_err(ret);

    return ret;
}

static int32_t tps65033_set_reg8_crc_retry3(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    int ret;
    int count = 3;

    while ((count-- != 0) && (ret = tps65033_set_reg8_crc(client, reg, val)));

    return ret;
}

static int32_t tps65033_config_crc_calc(struct i2c_client *client, uint8_t *cfg_crc)
{
    int32_t ret;
    uint8_t val;
    crc8_t crc;

    crc = crc8_init();

    for (int i = 0; i < CFG_REGS_NUM; i++)
    {
        ret = tps65033_get_reg8_crc_retry3(client, cfg_regs[i].reg, &val);
        if (ret)
        {
            return ret;
        }
        crc = crc8_update(crc, &val, 1);
    }

    crc = crc8_finalize(crc);

    *cfg_crc = crc;

    return 0;
}

/* Public API Implementation */

int32_t tps65033_init(I2C_Handle i2c_handle, uint8_t i2c_addr)
{
    int32_t ret = 0;
    uint8_t val;
    struct i2c_client tps_client;
    bool reconfig = false;

    tps_client.adapter  = i2c_handle;
    tps_client.addr     = i2c_addr;

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_ERR_BUCKX_LDO_CFG_REG, &val);
    RETURN_ON_ERROR(ret);
    if (val != 0xff)
    {
        reconfig = true;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_INT_MASK_BUCKX_LDO_REG, &val);
    RETURN_ON_ERROR(ret);
    if (val != 0x00)
    {
        reconfig = true;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_GPIO_CTRL_REG, &val);
    RETURN_ON_ERROR(ret);
    if (!(val & TPS65033_GPIO_CTRL_CFG_CRC_EN))
    {
        reconfig = true;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_INT_MASK_SAFETY_REG, &val);
    RETURN_ON_ERROR(ret);
    if (!(val & TPS65033_INT_MASK_SAFETY_I2C_CRC_ERR))
    {
        reconfig = true;
    }

    if (reconfig)
    {
        uint8_t cfg_crc;

        /* No need to check individual I2C CRC errors here as we will check CFG CRC later */

        /* Unlock control and config registers */
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_CONFIG_LOCK_REG, TPS65033_CONFIG_UNLOCK);
        RETURN_ON_ERROR(ret);
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_CONTROL_LOCK_REG, TPS65033_CONTROL_UNLOCK);
        RETURN_ON_ERROR(ret);

        /* Disable config CRC */
        ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_GPIO_CTRL_REG, &val);
        RETURN_ON_ERROR(ret);
        val &= ~TPS65033_GPIO_CTRL_CFG_CRC_EN;
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_GPIO_CTRL_REG, val);
        RETURN_ON_ERROR(ret);

        /* Set UV/OV_RST_EN for all BUCKx and LDO: Enable transition to RESET state per requirements */
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_ERR_BUCKX_LDO_CFG_REG, 0xff);
        RETURN_ON_ERROR(ret);
        /* Unmask OCP and WARM interrupts for all BUCKx and LDO: per requirements */
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_INT_MASK_BUCKX_LDO_REG, 0x00);
        RETURN_ON_ERROR(ret);
        /* Unmask I2C CRC interrupts: per requirements */
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_INT_MASK_SAFETY_REG, 0x00);
        RETURN_ON_ERROR(ret);

        /* Calculate and set config CRC */
        ret = tps65033_config_crc_calc(&tps_client, &cfg_crc);
        RETURN_ON_ERROR(ret);
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_CFG_REG_CRC, cfg_crc);
        RETURN_ON_ERROR(ret);

        /* Enable config CRC */
        val |= TPS65033_GPIO_CTRL_CFG_CRC_EN;
        ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_GPIO_CTRL_REG, val);
        RETURN_ON_ERROR(ret);

        // appLogPrintf("TPS65033 INIT reconfigure!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
    }

    /*
     * PVIN_UVLO_STATUS can be set on startup due to slow ramp
     * Clear it once to avoid safety events in this case
     * If error is persistent (will be set again by HW safety event will be reported)
     */
    ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_FAULT_STATUS_BUCK1, TPS65033_FAULT_STATUS_BUCK1_PVIN_UVLO);
    RETURN_ON_ERROR(ret);

    /* Make sure all locks are enabled */
    ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_CONFIG_LOCK_REG, TPS65033_CONFIG_LOCK);
    RETURN_ON_ERROR(ret);
    ret = tps65033_set_reg8_crc_retry3(&tps_client, TPS65033_CONTROL_LOCK_REG, TPS65033_CONTROL_LOCK);
    RETURN_ON_ERROR(ret);

    /* Check I2C CRC interrupt here to make sure lock is done */
    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_DEV_ERR_ACK2_REG, &val);
    RETURN_ON_ERROR(ret);
    if (val & TPS65033_DEV_ERR_ACK2_I2C_CRC)
    {
        ret = TPS65033_I2C_READ_CRC_ERR;
    }

    appLogPrintf("TPS65033[0x%x] init done; ret = %d!\n", i2c_addr, ret);
    return ret;
}

int32_t tps65033_get_status(I2C_Handle i2c_handle, uint8_t i2c_addr, IssSensor_CameraPmicStatus *pmic_sts)
{
    int32_t ret = 0;
    uint8_t pid, rid, val;
    struct i2c_client tps_client;

    tps_client.adapter  = i2c_handle;
    tps_client.addr     = i2c_addr;

    *pmic_sts = ISS_SENSOR_PMIC_OK;

    ret  = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_PID_REG, &pid);
    ret |= tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_RID_REG, &rid);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("1_ISS_SENSOR_PMIC_ERR_I2C:%x", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }

    if (pid != TPS65033_PID || rid != TPS65033_RID)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_ID;
        if (pid != TPS65033_PID)
        {
        }

        if (rid != TPS65033_RID)
        {
        }
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("ISS_SENSOR_PMIC_ERR_ID:%x", ISS_SENSOR_PMIC_ERR_ID);
#endif
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_FAULT_STATUS_BUCK1, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("2_ISS_SENSOR_PMIC_ERR_I2C:%x", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_BUCK1;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("ISS_SENSOR_PMIC_ERR_BUCK1:%x", ISS_SENSOR_PMIC_ERR_BUCK1);
#endif
        return ret;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_FAULT_STATUS_BUCK2, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("3_ISS_SENSOR_PMIC_ERR_I2C:%x", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_BUCK2;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("ISS_SENSOR_PMIC_ERR_BUCK2:%x", ISS_SENSOR_PMIC_ERR_BUCK2);
#endif
        return ret;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_FAULT_STATUS_BUCK3, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
        appLogPrintf("4_ISS_SENSOR_PMIC_ERR_I2C:%x", ISS_SENSOR_PMIC_ERR_I2C);
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_BUCK3;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("ISS_SENSOR_PMIC_ERR_BUCK3:%x", ISS_SENSOR_PMIC_ERR_BUCK3);
#endif
        return ret;
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_FAULT_STATUS_LDO, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
        appLogPrintf("5_ISS_SENSOR_PMIC_ERR_I2C:%x", ISS_SENSOR_PMIC_ERR_I2C);
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_LDO;
        appLogPrintf("ISS_SENSOR_PMIC_ERR_LDO:%x", ISS_SENSOR_PMIC_ERR_LDO);
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_DEV_FAULT_STS2_REG, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("7_ISS_SENSOR_PMIC_ERR_I2C:%d", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_DEV;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("1_ISS_SENSOR_PMIC_ERR_DEV:%x", ISS_SENSOR_PMIC_ERR_DEV);
#endif
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_DEV_ERR_ACK1_REG, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("8_ISS_SENSOR_PMIC_ERR_I2C:%d", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_DEV;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("2_ISS_SENSOR_PMIC_ERR_DEV:%x", ISS_SENSOR_PMIC_ERR_DEV);
#endif
    }

    ret = tps65033_get_reg8_crc_retry3(&tps_client, TPS65033_DEV_ERR_ACK2_REG, &val);
    if (ret)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("9_ISS_SENSOR_PMIC_ERR_I2C:%d", ISS_SENSOR_PMIC_ERR_I2C);
#endif
        return ret;
    }
    if (val)
    {
        *pmic_sts |= ISS_SENSOR_PMIC_ERR_DEV;
#ifdef CAMERA_PMIC_ERR_LOGS
        appLogPrintf("3_ISS_SENSOR_PMIC_ERR_DEV:%x", ISS_SENSOR_PMIC_ERR_DEV);
#endif
    }

    return ret;
}
