/*******************************************************************************
 * eeprom.h
 *
 * EEPROM module interface
 *
 * Copyright (c) 2021 Cogent Embedded Inc.
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

#ifndef __CANGW_TCA9539_H
#define __CANGW_TCA9539_H

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

/*******************************************************************************
 * Global constants definitions
 ******************************************************************************/

#define I2C_TCA9539_SPEED         I2C_400kHz
#define I2C_TCA9539_INSTANCE      (5)
#define I2C_PCA953x_WRITE_TIME    (1) /* 1 ms */

enum i2c_exp_dev {
    I2C_EXP1,
    I2C_EXP2,
    PCA953x_DEV_MAX
};

enum {
    PCA953X_DIRECTION_IN,
    PCA953X_DIRECTION_OUT,
};

#define MAX_BANK 5
#define BANK_SZ 8
#define I2C_TCA9539_MAX_WRITE (BANK_SZ * MAX_BANK * 4) /* 4 regs per port */

/*
 * struct pca953x_info - Data for pca953x
 *
 * @addr: i2c slave address
 * @gpio_count: the number of gpio pins that the device supports
 * @reg_output: array to hold the value of output registers
 * @reg_direction: array to hold the value of direction registers
 */
struct pca953x_info {
    int addr;
    int gpio_count;
    int bank_count;
    uint8_t reg_output[MAX_BANK];
    uint8_t reg_direction[MAX_BANK];
};

/*******************************************************************************
 * Public API
 ******************************************************************************/

int pca953x_bus_init(void);
int pca953x_get_value(enum i2c_exp_dev dev_id, uint32_t offset, uint8_t *value);
int pca953x_set_value(enum i2c_exp_dev dev_id, uint32_t offset, int value);
int pca953x_direction_input(enum i2c_exp_dev dev_id, uint32_t offset);
int pca953x_direction_output(enum i2c_exp_dev dev_id, uint32_t offset, int value);
int pca953x_get_function(enum i2c_exp_dev, uint32_t offset);

#endif  /* __CANGW_MCAN_H */
