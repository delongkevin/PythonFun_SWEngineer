/*
 * Copyright CogentEmbedded
 */

#include <utils/sciclient/include/app_sciclient_wrapper_api.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/board/src/devices/board_devices.h>
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_control.h>
#include <ti/board/src/j721s2_hyd/include/board_cfg.h>
#include <ti/board/src/j721s2_hyd/include/board_pinmux.h>
#include <ti/board/src/j721s2_hyd/include/board_i2c_io_exp.h>

#include <utils/misc/include/app_misc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/soc/j721s2/src/cslr_soc.h>
#include <ti/csl/src/ip/gpio/V0/gpio.h>

#include "i2c_helpers.h"

#include "stellantis.h"

void appCsi2TxBoardInit(void)
{
    uint8_t bus;
    I2C_Handle handle;
    struct i2c_client client;

    csitx_ser_power(1);
    appLogWaitMsecs(10);

    if (1)
    {
        bus = 4;
        handle = i2c_get_handle(bus);
        if (handle == NULL) {
            appLogPrintf("Failed to get i2c bus %d\n", bus);
            return;
        }

        client.adapter = handle;
        client.addr = 0x18; // UB935
        
        i2c_set_reg(&client, 0x02, 1, 0x52, 1);
        i2c_set_reg(&client, 0x03, 1, 0x00, 1);        

        i2c_set_reg(&client, 0x0B, 1, 0x13, 1);
        i2c_set_reg(&client, 0x0C, 1, 0x26, 1);

        i2c_set_reg(&client, 0x32, 1, 0x49, 1);
        i2c_set_reg(&client, 0x33, 1, 0x07, 1);
        i2c_set_reg(&client, 0x49, 1, 0x28, 1);

        i2c_put_handle(handle);
    }
}
