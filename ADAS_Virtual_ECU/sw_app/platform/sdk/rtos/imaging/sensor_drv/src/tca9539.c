/*******************************************************************************
 * eeprom.c
 *
 * Copyright (c) 2022 Cogent Embedded Inc.
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

#include "i2c_helpers.h"
#include "tca9539.h"

#define I2C_TCA9539_ADDR_SIZE     2   /* in bytes */
#define I2C_TCA9539_ADDR          0x50

#define I2C_TRANSACTION_TIMEOUT         (1000U)

#define PCA953X_INPUT           0
#define PCA953X_OUTPUT          1
#define PCA953X_INVERT          2
#define PCA953X_DIRECTION       3

#define DIV_ROUND_UP(n,d) (((n) + (d) - 1) / (d))

static I2C_Handle tca9539_i2c_handle = NULL;

static struct pca953x_info i2c_exp_devs[PCA953x_DEV_MAX] =
{
    [I2C_EXP1] = {
        .addr = 0x74,
        .gpio_count = 16,
    },
    [I2C_EXP2] = {
        .addr = 0x75,
        .gpio_count = 16,
    },
};

/*  *     Input port			0x00 + 0 * bank_size	R */
/*  *     Output port			0x00 + 1 * bank_size	RW */
/*  *     Polarity Inversion port		0x00 + 2 * bank_size	RW */
/*  *     Configuration port		0x00 + 3 * bank_size	RW */

/******************************************************************************/
/*                                 PRIVATE                                    */
/******************************************************************************/

/**
 * fls - find last (most-significant) bit set
 * @x: the word to search
 *
 * This is defined the same way as ffs.
 * Note fls(0) = 0, fls(1) = 1, fls(0x80000000) = 32.
 */
#if defined(QNX)
int fls(int x)
#else
static inline int fls(int x)
#endif
{
    int r = 32;

    if (!x)
            return 0;
    if (!(x & 0xffff0000u)) {
            x <<= 16;
            r -= 16;
    }
    if (!(x & 0xff000000u)) {
            x <<= 8;
            r -= 8;
    }
    if (!(x & 0xf0000000u)) {
            x <<= 4;
            r -= 4;
    }
    if (!(x & 0xc0000000u)) {
            x <<= 2;
            r -= 2;
    }
    if (!(x & 0x80000000u)) {
            x <<= 1;
            r -= 1;
    }
    return r;
}

static int i2c_read(struct pca953x_info *info, uint8_t off, uint8_t *rxBuf, size_t len)
{
    struct i2c_client client;
    int res;
    int i;

    client.adapter = tca9539_i2c_handle;
    client.addr = info->addr;

    /* appLogPrintf("I2C read len (%d) %p", len, rxBuf); */

    for (i = 0; i < len; i++)
    {
        /* appLogPrintf("READ i2c_addr(%d) off %x rxbuf %x", client.addr, off+i, (uint32_t*)(rxBuf + i)); */
        res = reg8_read(&client, off + i, rxBuf + i);
        if(res < 0)
        {
            appLogPrintf("I2C read failed (%d)", res);
            return -1;
        }
    }

    return 0;
}

static int pca953x_read_regs(struct pca953x_info *info, int reg, uint8_t *val)
{
    int ret = 0;

    if (info->gpio_count <= 16) {
        ret = i2c_read(info, reg << 1, val, info->bank_count);
    } else {
        appLogPrintf("Error (%s)", __func__);
        return -1;
    }

    return ret;
}

int pca953x_bus_init(void)
{
    int i;

    appLogPrintf("I2C TCA9539: Using Instance %d", I2C_TCA9539_INSTANCE);

    tca9539_i2c_handle = i2c_get_handle(I2C_TCA9539_INSTANCE);

    if (!tca9539_i2c_handle)
    {
        goto rollback_handle;
    }

    for (i = 0; i < PCA953x_DEV_MAX; i++)
    {
        struct pca953x_info *info = &i2c_exp_devs[i];
        int ret;

        info->bank_count = DIV_ROUND_UP(info->gpio_count, BANK_SZ);

        ret = pca953x_read_regs(info, PCA953X_OUTPUT, info->reg_output);
        if (ret) {
            appLogPrintf("Error reading output register (%s)", __func__);
            goto rollback_handle;
        }

        ret = pca953x_read_regs(info, PCA953X_DIRECTION, info->reg_direction);
        if (ret) {
            appLogPrintf("Error reading direction register (%s)", __func__);
            goto rollback_handle;
        }
    }

    appLogPrintf("I2C TCA9539: Using Instance %d complete", I2C_TCA9539_INSTANCE);

    return 0;

rollback_handle:
    appLogPrintf("I2C TCA9539: Using Instance %d failed", I2C_TCA9539_INSTANCE);

    if (tca9539_i2c_handle)
    {
        I2C_close(tca9539_i2c_handle);
        tca9539_i2c_handle = NULL;
    }

    return -1;
}

static int pca953x_write_single(struct pca953x_info *info, int reg, uint8_t val,
				int offset)
{
    int bank_shift = fls((info->gpio_count - 1) / BANK_SZ);
    int off = offset / BANK_SZ;
    int ret = 0;
    struct i2c_client client;

    client.adapter = tca9539_i2c_handle;
    client.addr = info->addr;

    /* appLogPrintf("I2C write single (reg 0x%x val 0x%x off 0x%x)", reg, val, off); */

    ret = reg8_write(&client, (reg << bank_shift) + off, val);
    if (ret)
    {
        appLogPrintf("I2C write failed (%d)", ret);
        return -1;
    }

    return 0;
}

static int pca953x_is_output(struct pca953x_info *info, int offset)
{
    int bank = offset / BANK_SZ;
    int off = offset % BANK_SZ;

    /*0: output; 1: input */
    return !(info->reg_direction[bank] & (1 << off));
}

static int pca953x_set_direction(struct pca953x_info *info, uint32_t offset, int dir)
{
    int bank = offset / BANK_SZ;
    int off = offset % BANK_SZ;
    uint8_t val;
    int ret;

    if (dir == PCA953X_DIRECTION_IN)
        val = info->reg_direction[bank] | (1 << off);
    else
        val = info->reg_direction[bank] & ~(1 << off);

    ret = pca953x_write_single(info, PCA953X_DIRECTION, val, offset);
    if (ret)
        return ret;

    info->reg_direction[bank] = val;

    return 0;
}

/******************************************************************************/
/*                                 PUBLIC                                     */
/******************************************************************************/

int pca953x_get_value(enum i2c_exp_dev dev_id, uint32_t offset, uint8_t *value)
{
    struct pca953x_info *info = &i2c_exp_devs[dev_id];
    uint32_t reg_off = offset / BANK_SZ;
    uint32_t bit_off = offset % BANK_SZ;
    int bank_shift = fls((info->gpio_count - 1) / BANK_SZ);
    int ret;
    uint8_t byte;

    if (!tca9539_i2c_handle)
    {
        return -1;
    }

    ret = i2c_read(info, (PCA953X_INPUT << bank_shift) + reg_off, &byte, 1);
    if (ret) {
        appLogPrintf("I2C error (%s)", __func__);
        return ret;
    }

    *value = (byte >> bit_off) & 0x01;

    return 0;
}

int pca953x_set_value(enum i2c_exp_dev dev_id, uint32_t offset, int value)
{
    struct pca953x_info *info = &i2c_exp_devs[dev_id];
    int bank = offset / BANK_SZ;
    int off = offset % BANK_SZ;
    uint8_t val;
    int ret;

    if (!tca9539_i2c_handle)
    {
        return -1;
    }

    if (value)
        val = info->reg_output[bank] | (1 << off);
    else
        val = info->reg_output[bank] & ~(1 << off);

    ret = pca953x_write_single(info, PCA953X_OUTPUT, val, offset);
    if (ret)
        return ret;

    info->reg_output[bank] = val;

    return 0;
}

int pca953x_direction_input(enum i2c_exp_dev dev_id, uint32_t offset)
{
    struct pca953x_info *info = &i2c_exp_devs[dev_id];

    if (!tca9539_i2c_handle)
    {
        return -1;
    }

    return pca953x_set_direction(info, offset, PCA953X_DIRECTION_IN);
}

int pca953x_direction_output(enum i2c_exp_dev dev_id, uint32_t offset, int value)
{
    int ret;
    struct pca953x_info *info = &i2c_exp_devs[dev_id];

    if (!tca9539_i2c_handle)
    {
        return -1;
    }

    /* Configure output value. */
    ret = pca953x_set_value(dev_id, offset, value);
    if (ret)
    {
        return ret;
    }

    /* Configure direction as output. */
    ret = pca953x_set_direction(info, offset, PCA953X_DIRECTION_OUT);

    return ret;
}

int pca953x_get_function(enum i2c_exp_dev dev_id, uint32_t offset)
{
    struct pca953x_info *info = &i2c_exp_devs[dev_id];

    if (!tca9539_i2c_handle)
    {
        return -1;
    }

    if (pca953x_is_output(info, offset))
        return PCA953X_DIRECTION_OUT;
    else
        return PCA953X_DIRECTION_IN;
}

