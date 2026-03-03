#ifndef ISS_SENSORS_PRIV_H_
#define ISS_SENSORS_PRIV_H_

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */
#ifndef x86_64
#include <ti/board/src/devices/board_devices.h>
#include <ti/csl/csl_gpio.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/board/src/devices/common/common.h>
#include <ti/board/board.h>
#include <ti/board/src/devices/board_devices.h>
#include <ti/board/src/devices/fpd/ds90ub960.h>
#ifdef j721s2_hyd
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_utils.h>
#include "iss_evm.h"
#endif

#include <app_remote_service.h>
#include <app_ipc.h>

void appLogWaitMsecs(uint32_t time_in_msecs);
void appLogPrintf(const char *format, ...);

int32_t getIssSensorI2cInfo(uint8_t i2cInstId, uint8_t * byteOrder, I2C_Handle * i2cHndl);
int32_t setupI2CInst(uint8_t i2cInstId);

#endif

#endif /* End of ISS_SENSORS_PRIV_H_*/
