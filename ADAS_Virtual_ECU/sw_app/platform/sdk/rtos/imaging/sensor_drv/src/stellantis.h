/*******************************************************************************
 * stellantis.h
 *
 * Stellantis specific definitions
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

#ifndef _STELLANTIS_H_
#define _STELLANTIS_H_

#include "tca9539.h"
#include "errno.h"

// IO1_4
#define CAM1_PWR_EN_PIN_DEV    (I2C_EXP1)
#define CAM1_PWR_EN_PIN_OFF    (4U)
// IO1_5
#define CAM2_PWR_EN_PIN_DEV    (I2C_EXP1)
#define CAM2_PWR_EN_PIN_OFF    (5U)
// IO1_6
#define CAM3_PWR_EN_PIN_DEV    (I2C_EXP1)
#define CAM3_PWR_EN_PIN_OFF    (6U)
// IO1_7
#define CAM4_PWR_EN_PIN_DEV    (I2C_EXP1)
#define CAM4_PWR_EN_PIN_OFF    (7U)

// IO1_0
#define DES1_PDB_PIN_DEV       (I2C_EXP1)
#define DES1_PDB_PIN_OFF       (0U)

// IO2_0
#define SER_PDB_PIN_DEV        (I2C_EXP2)
#define SER_PDB_PIN_OFF        (0U)

// IO2_14
#define CAM_PS_EN_PIN_DEV      (I2C_EXP2)
#define CAM_PS_EN_PIN_OFF      (12U)

// IO2_15
#define CAM_PS_PGOOD_PIN_DEV   (I2C_EXP2)
#define CAM_PS_PGOOD_PIN_OFF   (13U)

static inline int32_t cam_power(int en)
{
    return pca953x_direction_output(DES1_PDB_PIN_DEV, DES1_PDB_PIN_OFF, en);
}

static inline int32_t cam_common_power(int en)
{
    return pca953x_direction_output(CAM_PS_EN_PIN_DEV, CAM_PS_EN_PIN_OFF, en);
}

static inline int32_t ub960_deser_power(int en)
{
    return pca953x_direction_output(DES1_PDB_PIN_DEV, DES1_PDB_PIN_OFF, en);
}

static inline int32_t csitx_ser_power(int en)
{
    return pca953x_direction_output(SER_PDB_PIN_DEV, SER_PDB_PIN_OFF, en);
}

static inline int32_t cam_common_power_pgood_wait(uint32_t timeout_ms)
{
    volatile uint32_t val = 0U;
    int32_t ret;
    int     i = 0;

    ret = pca953x_direction_input(CAM_PS_PGOOD_PIN_DEV, CAM_PS_PGOOD_PIN_OFF);

    if (ret == 0) {
        appLogWaitMsecs(1);
        while (val == 0U && ret == 0 && i < timeout_ms) {
            ret = pca953x_get_value(CAM_PS_PGOOD_PIN_DEV, CAM_PS_PGOOD_PIN_OFF, (uint8_t*)&val);
            appLogWaitMsecs(1);
            i += 1;
        }
        if (i >= timeout_ms) {
            ret = -ETIMEDOUT;
        }
    }
    if (ret == 0) {
        appLogPrintf("Camera power: CAM_PS_PGOOD in %dms\n", i);
    } else {
        appLogPrintf("Camera power: CAM_PS_PGOOD failed with code %d\n", ret);
    }

    return ret;
}

#endif /* _STELLANTIS_H_ */