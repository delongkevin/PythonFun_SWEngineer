#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>

#include "errno.h"
#include "ub960.h"
#include "tps65033.h"
#include "ser_camera.h"
#include "i2c_helpers.h"
#include "type_helpers.h"
#include "epwm_helper.h"
#include "cam_tools.h"
#include "safety.h"

#include "VoltageCurrent_data.h"

#define EEPROM_0_I2C_ALIAS (0x50U)
#define EEPROM_1_I2C_ALIAS (0x54U)
#define EEPROM_2_I2C_ALIAS (0x58U)
#define EEPROM_3_I2C_ALIAS (0x5CU)

#define CAM_FLT_A_IOEXP_PIN_NUM (12u)
#define CAM_SEH_IOEXP_PIN_NUM (14u)
#define CAM_SEL_IOEXP_PIN_NUM (15u)

#define IOEXP_PIN_DIR_IN (0u)
#define IOEXP_PIN_DIR_OUT (1u)

#define RETRY_SYNC_MAX (2u)

extern I2C_Handle gISS_Sensor_I2cHandle[7];

const char *ti9x4_dev_names[UB9X4_DEVS] = {
    "UB960-A",
    "UB960-B"};

const char *ti9x4_ser_names[UB9X4_DEVS][4] = {
    {"FPD-A-0",
     "FPD-A-1",
     "FPD-A-2",
     "FPD-A-3"},
    {"FPD-B-0",
     "FPD-B-1",
     "FPD-B-2",
     "FPD-B-3"}};

struct ti9x4_priv;

struct ti9x3_priv
{
    struct i2c_client client;

    int idx;

    struct ti9x4_priv *deser;
};

struct ti9x4_priv
{
    struct i2c_client client;

    int slot; /* VB4 VIN slot number */
    int links;
    int channel_mask;
    int lanes;
    int ser_lanes;
    int csi_rate;
    int ref_clk;
    int forwarding_mode;
    int fs_time;
    int fps_numerator;
    int fps_denominator;
    int is_coax;
    int dvp_bus;
    int dvp_lsb;
    int hsync;
    int vsync;
    int poc_delay;
    int fc_mode;
    int bc_freq;
    int use_count;
    int ti9x3_addr_map[4];
    uint8_t chip_id[6];
    /* per-channel settings */
    int ser_id[4];
    int vc_map[4];
    int csi_map;
    int gpio[4];

    struct ti9x3_priv ser[4];
};

struct ub960_reg
{
    uint8_t reg;
    uint8_t val;
    int delay;
};

u8 csi_frame_count[2] = {0, 0}, csi_frame_count_error[2] = {0, 0};
CAM_Curr_Volt_Monitor_t CAM_CurrVoltData[4] = {{0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}, {0u, 0u, 0u}};
//u8 CAM_FAULT_A_Sts[4] = {0, 0, 0, 0};

static SemaphoreP_Handle sem_ub960_port_fwd;
static SemaphoreP_Handle sem_ub960_port_switch;

#if defined BUILD_MCU2_0
extern void SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(CAM_Curr_Volt_Monitor_t *data);
extern bool_t SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(CAM_CS_Curr_Monitor_t *data);
extern bool_t SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(CAM_select_info_t *data);
#endif
extern int32_t appGetI2cExpPinVal(uint8_t exp_id, uint8_t pin, uint8_t *value);
extern int32_t appSetI2cExpPinDir(uint8_t exp_id, uint8_t pin, uint8_t dir, uint8_t val);

static struct ti9x4_priv ti9x4_devs[UB9X4_DEVS];

static int reg8_write_read_retry(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    int ret;
    int count = 3;
    uint8_t read_val;

    while (count-- != 0)
    {
        ret = reg8_write(client, reg, val);
        if (ret) {
            i2c_reset_bus(client);
            appLogWaitMsecs(1);
            continue;
        }

        reg8_read(client, reg, &read_val);
        if (val == read_val)
        {
            break;
        }
        else
        {
            ret = -100;
            appLogWaitMsecs(1);
        }
    }

    return ret;
}

static void ti9x4_read_chipid(struct i2c_client *client)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);

    /* Chip ID */
    reg8_read_retry3(client, 0xf1, &priv->chip_id[0]);
    reg8_read_retry3(client, 0xf2, &priv->chip_id[1]);
    reg8_read_retry3(client, 0xf3, &priv->chip_id[2]);
    reg8_read_retry3(client, 0xf4, &priv->chip_id[3]);
    reg8_read_retry3(client, 0xf5, &priv->chip_id[4]);
    priv->chip_id[5] = '\0';
}

static int ub960_write_regs(struct i2c_client *client, const struct ub960_reg *regs)
{
    int ret = 0;

    if (regs == NULL)
        return -1;

    while (regs->delay >= 0)
    {
        ret = reg8_write_retry3(client, regs->reg, regs->val);
        if (ret < 0)
            break;
        if (regs->delay)
            mdelay(regs->delay);
        regs++;
    }
    return ret;
}

int ub960_eeprom_alias_init(struct i2c_client *client)
{
    dev_info(&client->dev, "%s()\n", __func__);

    uint8_t EepromNativeAddrs[4] = {
        0x50,
        0x51,
        0x52,
        0x53,
    };

    const struct ub960_reg eeprom_alias_regs[] = {
        {0x4C, 0x01, 0x1},                             /* port 0 */
        {0x61, EepromNativeAddrs[0] << 1, 0x1},        /* Slave id 4 */
        {0x69, (EEPROM_0_I2C_ALIAS + 0x00) << 1, 0x1}, /* Slave alias 4 */
        {0x62, EepromNativeAddrs[1] << 1, 0x1},        /* Slave id 5 */
        {0x6A, (EEPROM_0_I2C_ALIAS + 0x01) << 1, 0x1}, /* Slave alias 5 */
        {0x63, EepromNativeAddrs[2] << 1, 0x1},        /* Slave id 6 */
        {0x6B, (EEPROM_0_I2C_ALIAS + 0x02) << 1, 0x1}, /* Slave alias 6 */
        {0x64, EepromNativeAddrs[3] << 1, 0x1},        /* Slave id 7 */
        {0x6C, (EEPROM_0_I2C_ALIAS + 0x03) << 1, 0x1}, /* Slave alias 7 */

        {0x4C, 0x12, 0x1},                             /* port 1 */
        {0x61, EepromNativeAddrs[0] << 1, 0x1},        /* Slave id 4 */
        {0x69, (EEPROM_1_I2C_ALIAS + 0x00) << 1, 0x1}, /* Slave alias 4 */
        {0x62, EepromNativeAddrs[1] << 1, 0x1},        /* Slave id 5 */
        {0x6A, (EEPROM_1_I2C_ALIAS + 0x01) << 1, 0x1}, /* Slave alias 5 */
        {0x63, EepromNativeAddrs[2] << 1, 0x1},        /* Slave id 6 */
        {0x6B, (EEPROM_1_I2C_ALIAS + 0x02) << 1, 0x1}, /* Slave alias 6 */
        {0x64, EepromNativeAddrs[3] << 1, 0x1},        /* Slave id 7 */
        {0x6C, (EEPROM_1_I2C_ALIAS + 0x03) << 1, 0x1}, /* Slave alias 7 */

        {0x4C, 0x24, 0x1},                             /* port 2 */
        {0x61, EepromNativeAddrs[0] << 1, 0x1},        /* Slave id 4 */
        {0x69, (EEPROM_2_I2C_ALIAS + 0x00) << 1, 0x1}, /* Slave alias 4 */
        {0x62, EepromNativeAddrs[1] << 1, 0x1},        /* Slave id 5 */
        {0x6A, (EEPROM_2_I2C_ALIAS + 0x01) << 1, 0x1}, /* Slave alias 5 */
        {0x63, EepromNativeAddrs[2] << 1, 0x1},        /* Slave id 6 */
        {0x6B, (EEPROM_2_I2C_ALIAS + 0x02) << 1, 0x1}, /* Slave alias 6 */
        {0x64, EepromNativeAddrs[3] << 1, 0x1},        /* Slave id 7 */
        {0x6C, (EEPROM_2_I2C_ALIAS + 0x03) << 1, 0x1}, /* Slave alias 7 */

        {0x4C, 0x38, 0x1},                             /* port 3 */
        {0x61, EepromNativeAddrs[0] << 1, 0x1},        /* Slave id 4 */
        {0x69, (EEPROM_3_I2C_ALIAS + 0x00) << 1, 0x1}, /* Slave alias 4 */
        {0x62, EepromNativeAddrs[1] << 1, 0x1},        /* Slave id 5 */
        {0x6A, (EEPROM_3_I2C_ALIAS + 0x01) << 1, 0x1}, /* Slave alias 5 */
        {0x63, EepromNativeAddrs[2] << 1, 0x1},        /* Slave id 6 */
        {0x6B, (EEPROM_3_I2C_ALIAS + 0x02) << 1, 0x1}, /* Slave alias 6 */
        {0x64, EepromNativeAddrs[3] << 1, 0x1},        /* Slave id 7 */
        {0x6C, (EEPROM_3_I2C_ALIAS + 0x03) << 1, 0x1}, /* Slave alias 7 */

        {0x00, 0x00, -1} /* termination */
    };

    return ub960_write_regs(client, eeprom_alias_regs);
}

int ub960_pmic_alias_init(struct i2c_client *client)
{
    uint8_t PMICNativeAddr = 0x60;
    uint8_t PMICAliasAddrs[4] = {
        CPMIC_0_I2C_ALIAS,
        CPMIC_1_I2C_ALIAS,
        CPMIC_2_I2C_ALIAS,
        CPMIC_3_I2C_ALIAS,
    };

    const struct ub960_reg pmic_alias_regs[] = {
        {0x4C, 0x01, 0x1},                   /* port 0 */
        {0x60, PMICNativeAddr << 1, 0x1},    /* Slave id */
        {0x68, PMICAliasAddrs[0] << 1, 0x1}, /* Slave alias */

        {0x4C, 0x12, 0x1},                   /* port 1 */
        {0x60, PMICNativeAddr << 1, 0x1},    /* Slave id */
        {0x68, PMICAliasAddrs[1] << 1, 0x1}, /* Slave alias */

        {0x4C, 0x24, 0x1},                   /* port 2 */
        {0x60, PMICNativeAddr << 1, 0x1},    /* Slave id */
        {0x68, PMICAliasAddrs[2] << 1, 0x1}, /* Slave alias */

        {0x4C, 0x38, 0x1},                   /* port 3 */
        {0x60, PMICNativeAddr << 1, 0x1},    /* Slave id */
        {0x68, PMICAliasAddrs[3] << 1, 0x1}, /* Slave alias */

        {0x00, 0x00, -1} /* termination */
    };

    return ub960_write_regs(client, pmic_alias_regs);
}

static void ti9x4_initial_setup(struct i2c_client *client)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);

    /* Initial setup */
    reg8_write_retry3(client, 0x0d, 0xb9); /* VDDIO 3.3V */
    reg8_write_retry3(client, 0x0a, 0x13); /* I2C high pulse width */
    reg8_write_retry3(client, 0x0b, 0x25); /* I2C low pulse width */
    reg8_write_retry3(client, 0x09, 0x12); /* I2C Bus watchdog timer ~50microseconds */

    switch (priv->csi_rate)
    {
    case 1600:                          /* REFCLK = 25MHZ */
    case 1500:                          /* REFCLK = 23MHZ */
    case 1450:                          /* REFCLK = 22.5MHZ */
        reg8_write_retry3(client, 0x1f, 0x00); /* CSI rate 1.5/1.6Gbps */
        break;
    case 1200:                          /* REFCLK = 25MHZ */
    case 1100:                          /* REFCLK = 22.5MHZ */
        reg8_write_retry3(client, 0x1f, 0x01); /* CSI rate 1.1/1.2Gbps */
        break;
    case 800:                           /* REFCLK = 25MHZ */
    case 700:                           /* REFCLK = 22.5MHZ */
        reg8_write_retry3(client, 0x1f, 0x02); /* CSI rate 700/800Mbps */
        break;
    case 400:                           /* REFCLK = 25MHZ */
    case 350:                           /* REFCLK = 22.5MHZ */
        reg8_write_retry3(client, 0x1f, 0x03); /* CSI rate 350/400Mbps */
        break;
    default:
        dev_err(&client->dev, "unsupported CSI rate %d\n", priv->csi_rate);
    }

    if (priv->forwarding_mode == FORWARDING_MODE_ROUND_ROBIN)
    {
        reg8_write_retry3(client, 0x21, 0x03); /* Round Robin forwarding enable for CSI0/CSI1 */
    }
    else if (priv->forwarding_mode == FORWARDING_MODE_SYNCHRONIZED)
    {
        reg8_write_retry3(client, 0x21, 0x54); /* Basic Syncronized forwarding enable (FrameSync must be enabled!!) for CSI0/CSI1 */
    }

    reg8_write_retry3(client, 0x32, 0x01);                                    /* Select TX for CSI0, RX for CSI0 */
    reg8_write_retry3(client, 0x33, (((priv->lanes - 1) ^ 0x3) << 4) | 0x02); /* disable CSI output, set CSI lane count, continuous CSI mode */
    reg8_write_retry3(client, 0x20, 0xf0 | priv->csi_map);                    /* disable port forwarding */
#ifndef TI960_BOARD_EXT_SYNC
#if 0
    /* FrameSync setup for REFCLK=25MHz,   FPS=30: period_counts=1/2/FPS*25MHz  =1/2/30*25Mhz  =416666 -> FS_TIME=416666 */
    /* FrameSync setup for REFCLK=22.5MHz, FPS=30: period_counts=1/2/FPS*22.5Mhz=1/2/30*22.5Mhz=375000 -> FS_TIME=375000 */
// #define FS_TIME (priv->csi_rate == 1450 ? 376000 : 417666)
#define FS_TIME (priv->csi_rate == 1450 ? 385000 : 428000) // FPS=29.2 (new vendor's firmware AWB restriction?)
    reg8_write_retry3(client, 0x1a, FS_TIME >> 16);        /* FrameSync time 24bit */
    reg8_write_retry3(client, 0x1b, (FS_TIME >> 8) & 0xff);
    reg8_write_retry3(client, 0x1c, FS_TIME & 0xff);
    reg8_write_retry3(client, 0x18, 0x43);             /* Enable FrameSync, 50/50 mode, Frame clock from 25MHz */
#else
    /* FrameSync setup for REFCLK=23.3042MHz, FPS=30: period_counts=REFCLK/FPS/25/12mks=1/30/13.043e-6=2556 -> HI=2, LO=2554 */
    if (priv->fs_time == 0)
        priv->fs_time = priv->ref_clk / 30 / 25 / 12 - 2;

    reg8_write_retry3(client, 0x19, 2 >> 8);               /* FrameSync high time MSB */
    reg8_write_retry3(client, 0x1a, 2 & 0xff);             /* FrameSync high time LSB */
    reg8_write_retry3(client, 0x1b, priv->fs_time >> 8);   /* FrameSync low time MSB */
    reg8_write_retry3(client, 0x1c, priv->fs_time & 0xff); /* FrameSync low time LSB */
    reg8_write_retry3(client, 0x18, 0x00);                 /* Disable FrameSync - must be enabled after all cameras are set up */
#endif
#endif
}

static void ti9x4_select_rx_port(struct i2c_client *client, unsigned int idx)
{
    reg8_write_retry3(client, 0x4c, (idx << 4) | (1 << idx)); /* Select RX port number */
}

/* Must be called with sem_ub960_port_switch locked */
static void ti9x4_fpdlink3_setup(struct i2c_client *client, int idx, const struct sensor_drv *drv)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    u8 port_config = 0;
    u8 port_config2 = 0;

    /* PORT_CONFIG Register has reserved bit that should not be touched */
    //    reg8_read(client, 0x6d, &port_config);
    //    port_config = (port_config & 0x04) | 0x78;

    dev_info(&client->dev, "link%d: setup for %s serializer\n",
             idx,
             priv->ser_id[idx] == TI933_ID ? "TI933" : priv->ser_id[idx] == TI953_ID ? "TI953"
                                                                                     : "unknown");

    /* FPDLinkIII setup */
    ti9x4_select_rx_port(client, idx);
    usleep_range(2000, 2500); /* wait 2ms */

    switch (priv->ser_id[idx])
    {
    case TI933_ID:
        reg8_write_retry3(client, 0x58, 0x58 | TI9X4_BC_FREQ_2P5); /* Back channel: Freq=2.5Mbps */
        break;
    case TI953_ID:
        /* Force BCC freq to 50MHz by default and switch later per config */
        reg8_write_retry3(client, 0x58, 0x58 | TI9X4_BC_FREQ_50); /* Back channel: Freq=50Mbps */
        break;
    default:
        break;
    }

    reg8_write_retry3(client, 0x5c, priv->ti9x3_addr_map[idx] << 1); /* TI9X3 I2C addr */
                                                              //  reg8_write(client, 0x5d, 0x30 << 1);            /* SENSOR I2C native - must be set by sensor driver */
                                                              //  reg8_write(client, 0x65, (0x60 + idx) << 1);        /* SENSOR I2C translated - must be set by sensor driver */

    /* Hardcode Broadcast mapping for AR233 and ov2311 at 0x10 sensor address */
    /* TODO: move to broadcast probe functions */
    if (strcmp(drv->name, "ox03c10") == 0)
        reg8_write_retry3(client, 0x5e, 0x36 << 1); /* SENSOR Broadcast I2C native */
    else
        reg8_write_retry3(client, 0x5e, 0x10 << 1);       /* SENSOR Broadcast I2C native */
    reg8_write_retry3(client, 0x66, ((0x6f) << 1) | 0x0); /* SENSOR Broadcast I2C translated, Disable Auto ACK */

    if (priv->is_coax)
        port_config |= 0x04; /* Coax */
    else
        port_config |= 0x00; /* STP */

    switch (priv->dvp_bus)
    {
    case 8:
        port_config2 |= (priv->dvp_lsb ? 0xC0 : 0x80); /* RAW10 as 8-bit prosessing using LSB/MSB bits  */
        /* fall through */
    case 10:
        port_config |= 0x03; /* DVP over FPDLink (TI933 compatible) RAW10/RAW8 */
        break;
    case 12:
        port_config |= 0x02; /* DVP over FPDLink (TI933 compatible) RAW12 */
        break;
    default:
        port_config |= 0x00; /* CSI over FPDLink (TI953 compatible) */
    }

    if (priv->vsync)
        port_config2 |= 0x01; /* VSYNC acive low */
    if (priv->hsync)
        port_config2 |= 0x02; /* HSYNC acive low */

    //reg8_write_retry3(client, 0x6d, port_config);
    reg8_write_retry3(client, 0x7c, port_config2);
    reg8_write_retry3(client, 0x7d, 0x01u); // Port Pass control reg

    reg8_write_retry3(client, 0x70, ((priv->vc_map[idx] & 0x03) << 6) | DT_RAW8);  /* CSI data type: RAW8, assign first VC */
    reg8_write_retry3(client, 0x71, ((priv->vc_map[idx] & 0x03) << 6) | DT_RAW12); /* CSI data type: RAW12, assign first VC */
    reg8_write_retry3(client, 0xbc, 0x00);                                         /* Setup minimal time between FV and LV to 3 PCLKs */
    reg8_write_retry3(client, 0x72, (priv->vc_map[idx]));                          /* CSI VC MAP */
}

void ti9x4_link_boot_shutdown(int ch_mask)
{
    /*
     * Some camera component initialization failed.
     * Shutdown now to avoid possible clock stretching.
     * Schedule it for reset later.
     */
    if (ch_mask)
    {
        iss_board_PoC_disable(ch_mask);

        for (int idx = 0; idx < 4; idx++)
        {
            if (BIT(idx) & ch_mask)
            {
                camera_set_for_reset(idx);
            }
        }
    }
}

/* Wait for lock on current port (FPD3_PORT_SEL must be set outside) */
static int ti9x4_wait_for_lock(struct i2c_client *client, int timeout_ms)
{
    while (timeout_ms--)
    {
        uint8_t val;
        reg8_read(client, 0x4d, &val);
        if (val & 1)
        {
            break;
        }
        appLogWaitMsecs(1);
    }

    return timeout_ms != -1 ? 0 : -1;
}

/* Wait on port pass */
int ti9x4_wait_for_portpass(struct i2c_client *client, uint32_t ch, int timeout_ms)
{
    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    ti9x4_select_rx_port(client, ch);
    while (timeout_ms--)
    {
        uint8_t val;
        reg8_read(client, 0x4d, &val);
        if (val & 0x2)
        {
            break;
        }
        appLogWaitMsecs(1);
    }

    SemaphoreP_post(sem_ub960_port_switch);

    return timeout_ms != -1 ? 0 : -1;
}

int ti9x4_port_fwd(struct i2c_client *client, uint32_t idx, int on)
{
    uint8_t reg_val;

    SemaphoreP_pend(sem_ub960_port_fwd, SemaphoreP_WAIT_FOREVER);
    if (!on)
    {
        /* Disable port forwarding */
        reg8_read_retry3(client, 0x20, &reg_val);
        dev_info(&client->dev, "PORT FWD DISABLE ch %d: 0x%x -> 0x%x\n", idx, reg_val, reg_val | ((1 << idx) << 4));
        if(reg8_write_retry3(client, 0x20, reg_val | ((1 << idx) << 4))) {
           dev_info(&client->dev,"Disable Port forwarding:%x",(reg_val | ((1 << idx) << 4))); 
        }
    }
    else
    {
        /* Enable port forwarding */
        reg8_read_retry3(client, 0x20, &reg_val);
        dev_info(&client->dev, "PORT FWD ENABLE ch %d: 0x%x -> 0x%x\n", idx, reg_val, reg_val & ~((1 << idx) << 4));
        if(reg8_write_retry3(client, 0x20, reg_val & ~((1 << idx) << 4))) {
            dev_info(&client->dev,"Enable Port Forwarding:%x", (reg_val & ~((1 << idx) << 4)));
        }
    }
    SemaphoreP_post(sem_ub960_port_fwd);

    return 0;
}

int ti9x4_port_forward_en_by_ser(struct i2c_client *ser_client, uint32_t idx)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(ser_client);
    struct ti9x4_priv *deser = ser->deser;
    int timeout_ms = 150;

    if (ti9x4_wait_for_portpass(&deser->client, idx, timeout_ms) != 0)
    {
        return -1;
    }

    ti9x4_port_fwd(&deser->client, idx, 1);

    return 0;
}

int ti9x4_port_reset(struct i2c_client *client, uint32_t idx)
{
    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);    

    ti9x4_select_rx_port(client, idx);
    reg8_write_retry3(client, 0x58, 0x58 | TI9X4_BC_FREQ_50); /* Back channel: Freq=50Mbps */
    reg8_write_retry3(client, 0x6e, 0x88); /* Remote GPIO1/GPIO0 setup */
    reg8_write_retry3(client, 0x6f, 0x88); /* Remote GPIO3/GPIO2 setup */

    SemaphoreP_post(sem_ub960_port_switch);

    return 0;
}

static int ti9x4_initialize(struct i2c_client *client, const struct sensor_drv *drv)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    int idx /*, timeout*/;
    int ret = 0;
    int ser_ret = 0;

    dev_info(&client->dev, "LINKs=%d, LANES=%d, FORWARDING=%s, CABLE=%s, ID=%s\n",
             priv->links, priv->lanes,
             priv->forwarding_mode == FORWARDING_MODE_ROUND_ROBIN ? "round-robin" : "synchronized",
             priv->is_coax ? "coax" : "stp", priv->chip_id);

    SemaphoreP_Params semParams;

    SemaphoreP_Params_init(&semParams);
    semParams.mode = SemaphoreP_Mode_BINARY;
    sem_ub960_port_fwd = SemaphoreP_create(1U, &semParams);
    sem_ub960_port_switch = SemaphoreP_create(1U, &semParams);

    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    ti9x4_initial_setup(client);

    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        ti9x4_fpdlink3_setup(client, idx, drv);
    }

    /* Setup PMIC I2C mapping for ox03c10 Stellantis cameras */
    if (strcmp(drv->name, "ox03c10") == 0)
    {
        ub960_pmic_alias_init(client);
    }

    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        /* init serializer data */
        struct ti9x3_priv *ser = &priv->ser[idx];
        ser->idx = idx;
        ser->deser = priv;
        struct i2c_client *ser_client = &ser->client;
        ser_client->adapter = client->adapter;
        ser_client->addr = priv->ti9x3_addr_map[idx]; /* TI9X3 I2C addr */
        i2c_set_clientdata(ser_client, ser);
        ser_client->dev.name = ti9x4_ser_names[priv->slot][idx];

        ti9x4_select_rx_port(client, idx);
        usleep_range(1000, 1500); /* wait 1ms */

        /*
         * Enable only FSIN for remote gpio, all permanent states (0 or 1) setup on serializer side:
         * this avoids intermittent remote gpio noise (f.e. reset or spuriouse fsin) caused by
         * unstable/bad link, hence unstable backchannel
         */
        switch (priv->ser_id[idx])
        {
        case TI933_ID:
            ser_ret = reg8_write_retry3(ser_client, 0x0d, 0x55); /* Enable remote GPIO0/1 */
            break;
        case TI953_ID:
            ser_ret = reg8_write_retry3(ser_client, 0x0d,
                                        (priv->gpio[0] & 0x1) << 0 |
                                        (priv->gpio[1] & 0x1) << 1 |
                                        (priv->gpio[2] & 0x1) << 2 |
                                        (priv->gpio[3] & 0x1) << 3 |
                                        (priv->gpio[0] & 0x2) << 3 |
                                        (priv->gpio[1] & 0x2) << 4 |
                                        (priv->gpio[2] & 0x2) << 5 |
                                        (priv->gpio[3] & 0x2) << 6); /* Enable FSIN remote GPIOs and set local constant gpios */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0e,
                                        (!!priv->gpio[0] << 4) |
                                        (!!priv->gpio[1] << 5) |
                                        (!!priv->gpio[2] << 6) |
                                        (!!priv->gpio[3] << 7)); /* Enable serializer GPIOs only for output */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0b, 0x13); /* I2C high pulse width */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0c, 0x26); /* I2C low pulse width */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0a, 0x12); /* I2C Bus watchdog timer ~50 microseconds */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x02, 0x3 | ((priv->ser_lanes - 1) << 4));
            if (ser_ret != 0)
                break;

            /* NACK is possible here, so do not retry */
            ser_ret = reg8_write(ser_client, 0x03, TI9X3_FC_MODE_OVERRIDE | priv->fc_mode);
            if (ser_ret == I2C_STS_ERR_NO_ACK)
            {
                ser_ret = 0;
            }
            break;
        }

        if (ser_ret != 0)
        {
            ret |= 1 << idx;
        }

        int des_ret;
        /* This delay is needed as previous write to 0x03 resulting in NACK due to lock loss, 
        leading to i2c errors during bad camera scenario-Dont't remove this delay*/
        appLogWaitMsecs(2U); 
        /* As serializer is configured (e.g. to non-sync AON mode) now switch to requested BCC freq */  
        des_ret=reg8_write_read_retry(client, 0x58, 0x58 | priv->bc_freq);
        if(des_ret) {
            dev_info(&client->dev,"%s - Failed to write Reg 58 of Ser:%x",__FUNCTION__,des_ret);
            /*Store return status in mail box1 of des - for debug purpose */
            reg8_write_retry3(client, 0x79, des_ret); 
        }       

        if (ser_ret == 0)
        {
            /* Wait for link lock */
            if (ti9x4_wait_for_lock(client, 400))
            {
                ret |= 1 << idx;
            }

            /* Make sure Serializer mode was written correctly */
            if (priv->ser_id[idx] == TI953_ID)
            {
                uint8_t val;
                ser_ret = reg8_read_retry3(ser_client, 0x03, &val);
                if ((ser_ret != 0) || ((val & 0x1f) != 0x1b))
                {
                    ret |= 1 << idx;
                }
            }
        }

        reg8_write_retry3(client, 0x07, 0x02); /* Back channel: 2ms watchdog */

        if (!(BIT(idx) & ret))
        {
            reg8_write_retry3(client, 0x6e, 0x88 | (priv->gpio[1] << 4) | priv->gpio[0]); /* Remote GPIO1/GPIO0 setup */
            reg8_write_retry3(client, 0x6f, 0x88 | (priv->gpio[3] << 4) | priv->gpio[2]); /* Remote GPIO3/GPIO2 setup */
        }
    }

    /*
     * Camera serializer initialization failed.
     * Shutdown now to avoid possible clock stretching.
     * Schedule it for reset later.
     */
    if (ret)
    {
        iss_board_PoC_disable(ret);
    }
    for (idx = 0; idx < priv->links; idx++)
    {
        if (BIT(idx) & ret)
        {
            dev_info(&client->dev, "Camera[%d]: Serializer init failed. Shutdown now and bring-up later.\n", idx);
            camera_set_for_reset(idx);
        }
    }

    /* fill sensors structures and mapping for isp-rc */
    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        struct ti9x3_priv *ser = &priv->ser[idx];
        ser->idx = idx;
        ser->deser = priv;
        struct i2c_client *ser_client = &ser->client;
        ser_client->adapter = client->adapter;
        ser_client->addr = priv->ti9x3_addr_map[idx]; /* TI9X3 I2C addr */
        i2c_set_clientdata(ser_client, ser);
        ser_client->dev.name = ti9x4_ser_names[priv->slot][idx];

        if (ser_camera_probe_fpdlink(ser_client, priv->slot, idx, drv, 0))
        {
            ret |= 1 << idx;
            continue;
        }

        /* Setup PMIC I2C mapping for ox03c10 Stellantis cameras */
        if (strcmp(drv->name, "ox03c10") == 0)
        {
            uint8_t PMICAliasAddrs[4] = {
                CPMIC_0_I2C_ALIAS,
                CPMIC_1_I2C_ALIAS,
                CPMIC_2_I2C_ALIAS,
                CPMIC_3_I2C_ALIAS,
            };
            if (tps65033_init(client->adapter, PMICAliasAddrs[idx]))
            {
                ret |= 1 << idx;
                continue;
            }
        }
    }

    /*
     * Camera detection and/or camera PMIC initialization failed.
     * Shutdown now to avoid possible clock stretching.
     * Schedule it for reset later.
     */
    if (ret)
    {
        iss_board_PoC_disable(ret);
    }
    for (idx = 0; idx < priv->links; idx++)
    {
        if (BIT(idx) & ret)
        {
            dev_info(&client->dev, "Camera[%d]: Detection and/or PMIC init failed. Shutdown now and bring-up later.\n", idx);
            camera_set_for_reset(idx);
        }
    }

    for (idx = 0; idx < priv->links; idx++)
    {
        uint8_t tmp;

        if (!(BIT(idx) & priv->channel_mask))
            continue;

        /*
         * Clear BCC errors befor broadcast initialization
         */
        ti9x4_select_rx_port(client, idx);
        //usleep_range(1000, 1500); /* wait 1ms */
        reg8_read_retry3(client, 0x47, &tmp);
        reg8_read_retry3(client, 0x4d, &tmp);
    }

    /* init all sensors using one broadcast callback */
    {
        idx = 0;
        /* init serializer data */
        struct ti9x3_priv *ser = &priv->ser[idx];
        ser->idx = idx;
        ser->deser = priv;
        struct i2c_client *ser_client = &ser->client;
        ser_client->adapter = client->adapter;
        ser_client->addr = priv->ti9x3_addr_map[idx]; /* TI9X3 I2C addr */
        i2c_set_clientdata(ser_client, ser);
        ser_client->dev.name = ti9x4_ser_names[priv->slot][idx];

        /* When broadcasting port status is read to detect faulty cameras */
        SemaphoreP_post(sem_ub960_port_switch);
        ret |= ser_camera_probe_fpdlink_broadcast(ser_client, priv->slot, drv);
        SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);
    }

    /* Enable FrameSync, HI/LO mode, Frame clock from port0 */
#if TI960_BOARD_EXT_SYNC
    reg8_write_retry3(client, 0x18, TI960_BOARD_EXT_SYNC);
#else
    reg8_write_retry3(client, 0x18, 0x01);
#endif

    for (idx = 0; idx < priv->links; idx++)
    {
        uint8_t tmp;

        if (!(BIT(idx) & priv->channel_mask))
            continue;

        /*
         * Link should be locked here so read status to clear LOCK_STS_CHG bit
         * thus avoid re-initialization after hotplug thread start
         */
        ti9x4_select_rx_port(client, idx);
        usleep_range(1000, 1500); /* wait 1ms */
        reg8_read_retry3(client, 0x4d, &tmp);
    }

    /*
     * Check if any sensor reported an error and reset it
     */
    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        if (BIT(idx) & ret)
        {
            dev_info(&client->dev, "CAM[%d]: failed to initialize!\n", idx);
            camera_report_sccb_fault(idx, 1);
            camera_set_for_reset(idx);
        }
        else
        {
            camera_report_sccb_fault(idx, 0);
        }
    }

    SemaphoreP_post(sem_ub960_port_switch);

    /* Ignore ret code here as even if some channel failed to initialize we are still fine */
    return 0;
}

int ti9x4_initialize_channel(struct i2c_client *client, const struct sensor_drv *drv, int channel_mask)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    int idx;
    int ser_ret = 0;
    int ret = 0;

    /* Sleep for 40ms to make sure camera is not accessed early after power cycle */
    appLogWaitMsecs(40);

    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & channel_mask))
            continue;

        /* init serializer data */
        struct ti9x3_priv *ser = &priv->ser[idx];
        ser->idx = idx;
        ser->deser = priv;
        struct i2c_client *ser_client = &ser->client;
        ser_client->adapter = client->adapter;
        ser_client->addr = priv->ti9x3_addr_map[idx]; /* TI9X3 I2C addr */
        i2c_set_clientdata(ser_client, ser);
        ser_client->dev.name = ti9x4_ser_names[priv->slot][idx];

        ti9x4_select_rx_port(client, idx);
        usleep_range(1000, 1500); /* wait 1ms */

        switch (priv->ser_id[idx])
        {
        case TI933_ID:
            reg8_write_retry3(client, 0x58, 0x58 | TI9X4_BC_FREQ_2P5); /* Back channel: Freq=2.5Mbps */
            break;
        case TI953_ID:
            /* Force BCC freq to 50MHz by default and switch later per config */
            reg8_write_retry3(client, 0x58, 0x58 | TI9X4_BC_FREQ_50); /* Back channel: Freq=50Mbps */
            break;
        default:
            break;
        }

        /* Wait for link lock */
        if (ti9x4_wait_for_lock(client, 400))
        {
            ret |= 1 << idx;
            continue;
        }

        /*
         * Enable only FSIN for remote gpio, all permanent states (0 or 1) setup on serializer side:
         * this avoids intermittent remote gpio noise (f.e. reset or spuriouse fsin) caused by
         * unstable/bad link, hence unstable backchannel
         */
        switch (priv->ser_id[idx])
        {
        case TI933_ID:
            ser_ret = reg8_write_retry3(ser_client, 0x0d, 0x55); /* Enable remote GPIO0/1 */
            if (ser_ret != 0)
                break;

            break;
        case TI953_ID:
            ser_ret = reg8_write_retry3(ser_client, 0x0d,
                                        (priv->gpio[0] & 0x1) << 0 |
                                        (priv->gpio[1] & 0x1) << 1 |
                                        (priv->gpio[2] & 0x1) << 2 |
                                        (priv->gpio[3] & 0x1) << 3 |
                                        (priv->gpio[0] & 0x2) << 3 |
                                        (priv->gpio[1] & 0x2) << 4 |
                                        (priv->gpio[2] & 0x2) << 5 |
                                        (priv->gpio[3] & 0x2) << 6); /* Enable FSIN remote GPIOs and set local constant GPIOs */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0e,
                                        (!!priv->gpio[0] << 4) |
                                        (!!priv->gpio[1] << 5) |
                                        (!!priv->gpio[2] << 6) |
                                        (!!priv->gpio[3] << 7)); /* Enable serializer GPIOs only for output */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0b, 0x13); /* I2C high pulse width */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0c, 0x26); /* I2C low pulse width */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x0a, 0x12); /* I2C Bus watchdog timer ~50 microseconds */
            if (ser_ret != 0)
                break;

            ser_ret = reg8_write_retry3(ser_client, 0x02, 0x3 | ((priv->ser_lanes - 1) << 4));
            if (ser_ret != 0)
                break;

            /* NACK is possible here, so do not retry */
            ser_ret = reg8_write(ser_client, 0x03, TI9X3_FC_MODE_OVERRIDE | priv->fc_mode);
            if (ser_ret == I2C_STS_ERR_NO_ACK)
                ser_ret = 0;

            break;
        }

        if (ser_ret != 0)
        {
            ret |= 1 << idx;
            /* Proceed to next camera */
            continue;
        }

        int des_ret;
        /* This delay is needed as previous write to 0x03 resulting in NACK due to lock loss, 
        leading to i2c errors during bad camera scenario-Dont't remove this delay*/
        appLogWaitMsecs(2U); 
        /* As serializer is configured (e.g. to non-sync AON mode) now switch to requested BCC freq */  
        des_ret=reg8_write_read_retry(client, 0x58, 0x58 | priv->bc_freq);
        if(des_ret) {
            dev_info(&client->dev,"%s - Failed to write Reg 58 of Ser:%x",__FUNCTION__,des_ret);
            /*Store return status in mail box1 of des - for debug purpose */
            reg8_write_retry3(client, 0x79, des_ret); 
        }    

        /*
         * Wait for link to be established - otherwise double initialization happens on hotplug/reset
         * Also need to wait for link lock after switching modes before access camera
         */
        if (ti9x4_wait_for_lock(client, 400))
        {
            ret |= 1 << idx;
            continue;
        }

        /* Make sure Serializer mode was written correctly */
        if (priv->ser_id[idx] == TI953_ID)
        {
            uint8_t val;
            ser_ret = reg8_read_retry3(ser_client, 0x03, &val);
            if ((ser_ret != 0) || ((val & 0x1f) != 0x1b))
            {
                ret |= 1 << idx;
                continue;
            }
        }

        ser_ret = ser_camera_probe_fpdlink(ser_client, priv->slot, idx, drv, 1);
        if (ser_ret == -EFAULT)
        {
            camera_report_otp_fault(idx, 1);
            ret |= 1 << idx;
            continue;
        }
        else if (ser_ret)
        {
            camera_report_otp_fault(idx, 0);
            ret |= 1 << idx;
            continue;
        }
        else
        {
            camera_report_otp_fault(idx, 0);
        }

        /* Setup PMIC I2C mapping for ox03c10 Stellantis cameras */
        if (strcmp(drv->name, "ox03c10") == 0)
        {
            uint8_t PMICAliasAddrs[4] = {
                CPMIC_0_I2C_ALIAS,
                CPMIC_1_I2C_ALIAS,
                CPMIC_2_I2C_ALIAS,
                CPMIC_3_I2C_ALIAS,
            };
            ser_ret = tps65033_init(client->adapter, PMICAliasAddrs[idx]);
            if (ser_ret)
                ret |= 1 << idx;
        }

        if (!(BIT(idx) & ret))
        {
            reg8_write_retry3(client, 0x6e, 0x88 | (priv->gpio[1] << 4) | priv->gpio[0]); /* Remote GPIO1/GPIO0 setup */
            reg8_write_retry3(client, 0x6f, 0x88 | (priv->gpio[3] << 4) | priv->gpio[2]); /* Remote GPIO3/GPIO2 setup */
        }
    }

    SemaphoreP_post(sem_ub960_port_switch);

    return ret;
}

void ti9x4_diag(struct i2c_client *client, const struct sensor_drv *drv)
{
#if defined BUILD_MCU2_0    
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    static int camera_idx = 1; //Starting with 2nd CAM channel for sync check on MCU1_0
    static uint8_t Count_u8 = 0;
#if 0
    static uint8_t ErrCnt_u8=0;
#endif
    //uint8_t CamFaultAVal_u8;
    //uint8_t CamSELVal_u8 = 0;
    //uint8_t CamSEHVal_u8 = 0;
    //uint8_t CamPwrEn_u8 = 0;
    // uint8_t CamSelRead_u8=0;
    CAM_Curr_Volt_Monitor_t CAM_CurrVoltData_Local;
    static CAM_CS_Curr_Monitor_t SigMgr_Curr_out;
    static CAM_select_info_t Cam_ChInfo;
    static uint16_t count = 0;
    static uint8_t prev_cam_idx = 0;


    if (Count_u8 % 2 == 0)
    {
        if(prev_cam_idx != camera_idx)
        {
            /* Camera Selection pins for next cycle current read */
            (void)appSetI2cExpPinDir(0u, CAM_SEH_IOEXP_PIN_NUM, IOEXP_PIN_DIR_OUT, (uint8_t)((camera_idx & 0x2u) >> 0x1u)); /* IO1_16 CAM_SEH */
            (void)appSetI2cExpPinDir(0u, CAM_SEL_IOEXP_PIN_NUM, IOEXP_PIN_DIR_OUT, (uint8_t)(camera_idx & 0x1u));           /* IO1_17 CAM_SEL */
            prev_cam_idx = camera_idx;
        }
        Cam_ChInfo.s_Cam_ChId = camera_idx;
        (void)SigMgr_PpCAMSelInfo_CAM_select_info_t_Put(&Cam_ChInfo);
        //dev_info(&client->dev, "Cam_ChInfo.s_Cam_ChId = %d\n",Cam_ChInfo.s_Cam_ChId);
    }
    else
    {
        //(void)appGetI2cExpPinVal(0u, CAM_SEH_IOEXP_PIN_NUM, &CamSEHVal_u8); /* IO1_16 CAM_SEH */
        //(void)appGetI2cExpPinVal(0u, CAM_SEL_IOEXP_PIN_NUM, &CamSELVal_u8); /* IO1_17 CAM_SEL */
        //dev_info(&client->dev, "CamSEHVal_u8=%d,CamSELVal_u8=%d,camera_idx=%d,Count_u8=%d",(CamSEHVal_u8),(CamSELVal_u8),camera_idx,Count_u8);
        if ((!(BIT(camera_idx) & priv->channel_mask)) == 0u) /* Valid Channel */
        {
#if 0
            if(camera_idx == (((CamSEHVal_u8&0x1u)<<0x1u)|(CamSELVal_u8&0x1u)))
            {
                ErrCnt_u8=0;
#endif
            SigMgr_Data_CAM_Curr_Volt_Monitor_t_Get(&CAM_CurrVoltData_Local);
            if(CAM_CurrVoltData_Local.s_Cam_ChId == camera_idx)
            {
            CAM_CurrVoltData[camera_idx].CAM_CS_A = CAM_CurrVoltData_Local.CAM_CS_A;
            CAM_CurrVoltData[camera_idx].CAM_PS_MON = CAM_CurrVoltData_Local.CAM_PS_MON;
            // dev_info(&client->dev, "CAM_CurrVoltData[%d].CAM_CS_A=%d !!!\n", camera_idx, CAM_CurrVoltData[camera_idx].CAM_CS_A);
            camera_idx++;
            }

            if (camera_idx > 3u)
            {
                /* All Cameras */
                CAM_CurrVoltData[0].FreshnessCounter++;
                CAM_CurrVoltData[1].FreshnessCounter++;
                CAM_CurrVoltData[2].FreshnessCounter++;
                CAM_CurrVoltData[3].FreshnessCounter++;
                SigMgr_Curr_out.s_Front_CAM_CS_A = CAM_CurrVoltData[2].CAM_CS_A;
                SigMgr_Curr_out.s_Rear_CAM_CS_A  = CAM_CurrVoltData[3].CAM_CS_A;
                SigMgr_Curr_out.s_Left_CAM_CS_A  = CAM_CurrVoltData[0].CAM_CS_A;
                SigMgr_Curr_out.s_Right_CAM_CS_A = CAM_CurrVoltData[1].CAM_CS_A;
                SigMgr_Curr_out.s_FreshnessCounter++; /* Rollover is intentional - for indicating synchronized data update */
                (void)SigMgr_PpCamCsData_CAM_CS_Curr_Monitor_t_Put(&SigMgr_Curr_out);
                camera_idx = 0u;
            }

#if 0
            }
            else
            {
                /* No Sync. Selected Camera Index is not the same in the next cycle - Retry */
                /* Camera Selection pins for next cycle current read */
                (void)appSetI2cExpPinDir(0u, CAM_SEH_IOEXP_PIN_NUM, IOEXP_PIN_DIR_OUT, (uint8_t)((camera_idx&0x2u)>>0x1u)); /* IO1_16 CAM_SEH */
                (void)appSetI2cExpPinDir(0u, CAM_SEL_IOEXP_PIN_NUM, IOEXP_PIN_DIR_OUT, (uint8_t)(camera_idx&0x1u)); /* IO1_17 CAM_SEL */
                ErrCnt_u8++;
                if(ErrCnt_u8==RETRY_SYNC_MAX) /* Give up in RETRY_SYNC_MAX tries */
                {
                    dev_info(&client->dev, "SYNC FAILED. CamSEHVal_u8=%d,CamSELVal_u8=%d,camera_idx=%d,Count_u8=%d",(CamSEHVal_u8),(CamSELVal_u8),camera_idx,Count_u8);
                    ErrCnt_u8=0;
                    Count_u8++;
                }
            }
#endif
        }
        else
        { /* Control must never reach here - Error : invalid channel configuration */
            dev_info(&client->dev, "ti9x4_diag :: Error - invalid channel configuration");
        }
    }
    Count_u8++; /* Overlfow is intentional */
#endif    
}

#ifdef ENABLE_UART_CLI
int ti9x4_status(struct i2c_client *client, const struct sensor_drv *drv)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    u8 port_sts1[4] = {0, 0, 0, 0}, port_sts2[4] = {0, 0, 0, 0};
    int idx;
    int ret = 0;

    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    /* check lock status */
    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        ti9x4_select_rx_port(client, idx);
        usleep_range(1000, 1500);                           /* wait/sleep 1.5ms */
        reg8_read(client, 0x4d, &port_sts1[idx]);           /* Lock status */
        reg8_read(client, 0x4e, &port_sts2[idx]);           /* Freq stable */
        reg8_read(client, 0x90, &csi_frame_count[1]);       /* Freq stable */
        reg8_read(client, 0x91, &csi_frame_count[0]);       /* Freq stable */
        reg8_read(client, 0x92, &csi_frame_count_error[1]); /* err count */
        reg8_read(client, 0x93, &csi_frame_count_error[0]); /* err count */
    }
#if 0
    dev_info(&client->dev, "Receiver lock status [%d,%d,%d,%d]\n",
                       (port_sts1[0] & 0x1) && (port_sts2[0] & 0x4),
                       (port_sts1[1] & 0x1) && (port_sts2[1] & 0x4),
                       (port_sts1[2] & 0x1) && (port_sts2[2] & 0x4),
                       (port_sts1[3] & 0x1) && (port_sts2[3] & 0x4));
#endif

    ret = (port_sts1[0] & 0x1) && (port_sts2[0] & 0x4) ? 0x1 : 0;
    ret |= (port_sts1[1] & 0x1) && (port_sts2[1] & 0x4) ? 0x2 : 0;
    ret |= (port_sts1[2] & 0x1) && (port_sts2[2] & 0x4) ? 0x4 : 0;
    ret |= (port_sts1[3] & 0x1) && (port_sts2[3] & 0x4) ? 0x8 : 0;

    /* Print status on console when any camera connection is lost*/
    if ((ret & 0x0FU) ^ 0x0FU)
    {
        dev_info(&client->dev, "Receiver lock status [%d,%d,%d,%d]\n",
                 (port_sts1[0] & 0x1) && (port_sts2[0] & 0x4),
                 (port_sts1[1] & 0x1) && (port_sts2[1] & 0x4),
                 (port_sts1[2] & 0x1) && (port_sts2[2] & 0x4),
                 (port_sts1[3] & 0x1) && (port_sts2[3] & 0x4));
    }

    SemaphoreP_post(sem_ub960_port_switch);

    return ret;
}
#endif /* ENABLE_UART_CLI */

int ti9x4_status_chg_by_ser(struct i2c_client *client,
                            uint32_t *lock_status, uint32_t *lock_status_chg,
                            uint32_t *bcc_err_status)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    return ti9x4_status_chg(&deser->client, NULL, lock_status, lock_status_chg, bcc_err_status);
}

int ti9x4_status_chg(struct i2c_client *client, const struct sensor_drv *drv,
                     uint32_t *lock_status, uint32_t *lock_status_chg,
                     uint32_t *bcc_err_status)
{
    struct ti9x4_priv *priv = i2c_get_clientdata(client);
    u8 port_sts1[4] = {0, 0, 0, 0}, port_sts2[4] = {0, 0, 0, 0}, bcc_sts[4] = {0, 0, 0, 0};
    int idx;
    int ret = 0;

    if (!lock_status || !lock_status_chg || !bcc_err_status)
        return -EINVAL;

    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    /* check lock status */
    for (idx = 0; idx < priv->links; idx++)
    {
        if (!(BIT(idx) & priv->channel_mask))
            continue;

        ti9x4_select_rx_port(client, idx);
        //usleep_range(1000, 1500);                        /* wait 1ms */
        ret = reg8_read_retry3(client, 0x4d, &port_sts1[idx]);  /* Lock status */
        ret |= reg8_read_retry3(client, 0x4e, &port_sts2[idx]); /* Freq stable */
        if (port_sts1[idx] & 0x08)
        {
            ret |= reg8_read_retry3(client, 0x47, &bcc_sts[idx]); /* BCC errors: Need to be read to clean BCC_ERROR flag */
        }
    }

    SemaphoreP_post(sem_ub960_port_switch);

    *lock_status  = (port_sts1[0] & 0x1) && (port_sts2[0] & 0x4) ? 0x1 : 0;
    *lock_status |= (port_sts1[1] & 0x1) && (port_sts2[1] & 0x4) ? 0x2 : 0;
    *lock_status |= (port_sts1[2] & 0x1) && (port_sts2[2] & 0x4) ? 0x4 : 0;
    *lock_status |= (port_sts1[3] & 0x1) && (port_sts2[3] & 0x4) ? 0x8 : 0;

    *lock_status_chg  = (port_sts1[0] & 0x10) ? 0x1 : 0;
    *lock_status_chg |= (port_sts1[1] & 0x10) ? 0x2 : 0;
    *lock_status_chg |= (port_sts1[2] & 0x10) ? 0x4 : 0;
    *lock_status_chg |= (port_sts1[3] & 0x10) ? 0x8 : 0;

    if (*lock_status_chg)
    {
        dev_info(&client->dev, "Receiver lock status [%d,%d,%d,%d]\n",
                 (port_sts1[0] & 0x1),
                 (port_sts1[1] & 0x1),
                 (port_sts1[2] & 0x1),
                 (port_sts1[3] & 0x1));
        dev_info(&client->dev, "Receiver frequency status [%d,%d,%d,%d]\n",
         (port_sts2[0] & 0x4),
         (port_sts2[1] & 0x4),
         (port_sts2[2] & 0x4),
         (port_sts2[3] & 0x4));
        dev_info(&client->dev, "Receiver lock status chg [%d,%d,%d,%d]\n",
                 (port_sts1[0] & 0x10) >> 4,
                 (port_sts1[1] & 0x10) >> 4,
                 (port_sts1[2] & 0x10) >> 4,
                 (port_sts1[3] & 0x10) >> 4);
    }

    /*
     * FIXME: BCC_SEQ_ERROR/BCC_ERROR is always 1. Ignored in original Magna code as well.
     */
    *bcc_err_status  = (port_sts1[0] & 0x08) || (port_sts1[0] & 0x20) ? 0x1 : 0;
    *bcc_err_status |= (port_sts1[1] & 0x08) || (port_sts1[1] & 0x20) ? 0x2 : 0;
    *bcc_err_status |= (port_sts1[2] & 0x08) || (port_sts1[2] & 0x20) ? 0x4 : 0;
    *bcc_err_status |= (port_sts1[3] & 0x08) || (port_sts1[3] & 0x20) ? 0x8 : 0;

    if (*bcc_err_status)
    {
        dev_info(&client->dev, "Receiver bcc error status [%d,%d,%d,%d]\n",
                (port_sts1[0] & 0x08) || (port_sts1[0] & 0x20),
                (port_sts1[1] & 0x08) || (port_sts1[1] & 0x20),
                (port_sts1[2] & 0x08) || (port_sts1[2] & 0x20),
                (port_sts1[3] & 0x08) || (port_sts1[3] & 0x20));
        dev_info(&client->dev, "Receiver bcc status [0x%02x,0x%02x,0x%02x,0x%02x]\n",
                (bcc_sts[0]),
                (bcc_sts[1]),
                (bcc_sts[2]),
                (bcc_sts[3]));
    }

    if (ret)
    {
        i2c_reset_bus(client);
        //i2c_recover_bus(client);
    }

    return ret;
}

static int ub960_pattern_generator_init(struct i2c_client *client)
{
    dev_info(&client->dev, "%s()\n", __func__);

    const struct ub960_reg ub960_testpattern_regs[] = {
        /* Patgen Fixed Colorbar 1280x720p30 */
        //{0x32, 0x01}, // # CSI0 sel and CSI0 enable
        //{0x33, 0x01 | 0x02}, //
        {0xB0, 0x00},    // # Indirect Pattern Gen Registers
        {0xB1, 0x01},    // # PGEN_CTL
        {0xB2, 0x01},    //
        {0xB1, 0x02},    // # PGEN_CFG
        {0xB2, 0x33},    //
        {0xB1, 0x03},    // # PGEN_CSI_DI
        {0xB2, 0x24},    //
        {0xB1, 0x04},    // # PGEN_LINE_SIZE1
        {0xB2, 0x0F},    //
        {0xB1, 0x05},    // # PGEN_LINE_SIZE0
        {0xB2, 0x00},    //
        {0xB1, 0x07},    // # PGEN_BAR_SIZE0
        {0xB2, 0xE0},    //
        {0xB1, 0x08},    // # PGEN_ACT_LPF1
        {0xB2, 0x02},    //
        {0xB1, 0x06},    // # PGEN_BAR_SIZE1
        {0xB2, 0x01},    //
        {0xB1, 0x09},    // # PGEN_ACT_LPF0
        {0xB2, 0xD0},    //
        {0xB1, 0x0A},    // # PGEN_TOT_LPF1
        {0xB2, 0x04},    //
        {0xB1, 0x0B},    // # PGEN_TOT_LPF0
        {0xB2, 0x1A},    //
        {0xB1, 0x0C},    // # PGEN_LINE_PD1
        {0xB2, 0x0C},    //
        {0xB1, 0x0D},    // # PGEN_LINE_PD0
        {0xB2, 0x67},    //
        {0xB1, 0x0E},    // # PGEN_VBP
        {0xB2, 0x21},    //
        {0xB1, 0x0F},    // # PGEN_VFP
        {0xB2, 0x0A},    //
        {0x00, 0x00, -1} /* termination */
    };

    return ub960_write_regs(client, ub960_testpattern_regs);
}

static int ub960_parse_config(struct i2c_client *client, const struct ti9x4_config *cfg)
{
    int i;
    struct ti9x4_priv *priv = i2c_get_clientdata(client);

    if (cfg->slot >= UB9X4_DEVS)
    {
        return -1;
    }

    /* apply settings */
    priv->slot = cfg->slot;
    priv->links = 4;
    priv->lanes = cfg->lanes;
    priv->ser_lanes = cfg->ser_lanes;
    priv->csi_rate = cfg->csi_rate;
    priv->ref_clk = cfg->ref_clk;
    priv->is_coax = cfg->is_coax;
    priv->dvp_bus = cfg->dvp_bus;
    priv->dvp_lsb = cfg->dvp_lsb;
    priv->vsync = cfg->vsync;
    priv->hsync = cfg->hsync;
    priv->fs_time = cfg->fs_time;
    priv->forwarding_mode = cfg->forwarding_mode;
    priv->fc_mode = cfg->fc_mode;
    priv->bc_freq = cfg->bc_freq;
    for (i = 0; i < 4; i++)
    {
        priv->gpio[i] = cfg->gpio[i];
    }
    for (i = 0; i < 4; i++)
    {
        priv->ti9x3_addr_map[i] = cfg->ti9x3_addr_map[i];
        priv->vc_map[i] = cfg->vc_map[i];
        priv->ser_id[i] = cfg->ser_id[i];
        if (priv->ser_id[i] == 0x00)
        {
            priv->ser_id[i] = TI933_ID;
        }
    }
    if (priv->lanes == 0)
    {
        priv->lanes = 4;
    }

    /* ??? */
    priv->fps_numerator = 1;
    priv->fps_denominator = 30;

    /* default power on timeout */
    priv->poc_delay = 100; /* mS */
    if (cfg->poc_delay)
        priv->poc_delay = cfg->poc_delay;

    priv->use_count = 0;

    return 0;
}

void ub960_deser_eeprom_init(void *adapter, uint8_t addr, int slot)
{
    struct ti9x4_priv *priv;
    struct i2c_client *client;

    if ((adapter == NULL) || (slot >= UB9X4_DEVS))
        return;

    priv = &ti9x4_devs[slot];
    memset(priv, 0, sizeof(*priv));
    priv->client.adapter = adapter;
    priv->client.addr = addr;
    priv->slot = slot;
    client = &priv->client;
    client->dev.name = ti9x4_dev_names[priv->slot];
    i2c_set_clientdata(client, priv);

    ub960_eeprom_alias_init(client);
}

struct i2c_client *ub960_deser_init(void *adapter, uint8_t addr, int slot, uint32_t channel_mask, const struct sensor_drv *drv)
{
    int32_t ret;
    struct ti9x4_priv *priv;
    struct i2c_client *client;

    if ((adapter == NULL) || (slot >= UB9X4_DEVS) || (drv == NULL))
        return NULL;

    priv = &ti9x4_devs[slot];
    memset(priv, 0, sizeof(*priv));
    priv->client.adapter = adapter;
    priv->client.addr = addr;
    priv->slot = slot;
    client = &priv->client;
    client->dev.name = ti9x4_dev_names[priv->slot];
    i2c_set_clientdata(client, priv);

    if (!drv->ub9x4_cfg)
    {
        dev_err(&client->dev, "%s is not supported for this deser\n", drv->name);
        return NULL;
    }

    ti9x4_read_chipid(client);

    dev_info(&client->dev, "probing for %s, channel_mask = 0x%02x\n",
             drv->name, channel_mask);

    ret = ub960_parse_config(client, &drv->ub9x4_cfg[slot]);
    if (ret < 0)
        return NULL;

    priv->channel_mask = channel_mask;

    ret = ti9x4_initialize(client, drv);
    if (ret)
        return NULL;

    return client;
}

int ub960_read(struct i2c_client *client, uint8_t reg, uint8_t *val)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    return reg8_read_retry3(&deser->client, reg, val);
}

int ub960_write(struct i2c_client *client, uint8_t reg, uint8_t val)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    return reg8_write_retry3(&deser->client, reg, val);
}

/*******************************************************************************
 *  Serializer Exported Functions Declarations
 ******************************************************************************/
int ub9x3_i2c_set_mapping(struct i2c_client *client, uint8_t n, uint8_t src, uint8_t dst)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    if (n >= 8)
        return -1;

    int idx = ser->idx;

    /* Select RX port number */
    reg8_write_retry3(&deser->client, 0x4c, (idx << 4) | (1 << idx));
    /* local address */
    reg8_write_retry3(&deser->client, 0x65 + n, src << 1);
    /* remote address */
    reg8_write_retry3(&deser->client, 0x5d + n, dst << 1);

    usleep_range(2000, 2500);

    return 0;
}

int ub9x3_i2c_forwarding(struct i2c_client *client, uint32_t on)
{
    /* Forwarding is always enabled? */
    return 0;
}

int ub9x3_PoC_set(struct i2c_client *client, uint32_t on)
{
    int ret;
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    ret = iss_board_PoC_channel_set(deser->slot, ser->idx, on);
    if (ret < 0)
        return ret;

    //    mdelay(deser->poc_delay);

    return 0;
}

int ub9x3_stream(struct i2c_client *client, uint32_t on)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;

    if (on)
    {
        if ((++deser->use_count) == 1)
        {
            dev_info(&deser->client.dev, "Starting CSI stream\n");
#if TI960_BOARD_EXT_SYNC
            epwm_init(deser->fps_denominator / deser->fps_numerator);
#else
            /* Enable FrameSync, HI/LO mode, Frame clock from port0 */
            // reg8_write(&deser->client, 0x18, 0x01);
#endif
            /* enable CSI output, set CSI lane count, continuous CSI mode */
            reg8_write_retry3(&deser->client, 0x33, (((deser->lanes - 1) ^ 0x3) << 4) | 0x03);
        }
        if (deser->ser_id[ser->idx] == TESTPATTERN_ID)
        {
            ub960_pattern_generator_init(&deser->client);
        }
    }
    else
    {
        if ((--deser->use_count) == 0)
        {
            dev_info(&deser->client.dev, "Stopping CSI stream\n");
            /* disable CSI output, set CSI lane count, continuous CSI mode */
            reg8_write_retry3(&deser->client, 0x33, ((deser->lanes - 1) ^ 0x3) << 4 | 0x02);
#if TI960_BOARD_EXT_SYNC
            epwm_deinit();
#else
            /* Disable FrameSync */
            // reg8_write(&deser->client, 0x18, 0x00);
#endif
        }
    }

    return 0;
}

int ub9x3_mipi_diagnostics(struct i2c_client *client, IssSensor_MipiStatus *mipi_sts)
{
    uint8_t val;
    int ret;

    ret = reg8_read_retry3(client, 0x5d, &val);

    if (ret == 0)
    {
        *mipi_sts = ISS_SENSOR_MIPI_OK;
        if (val & 0x1)
        {
            *mipi_sts |= ISS_SENSOR_MIPI_1ECC;
            dev_info(&client->dev, "MIPI DIAG ECC 1-bit error; CSI_ERR_STATUS = 0x%x\n", val);
        }
        if (val & 0x2)
        {
            *mipi_sts |= ISS_SENSOR_MIPI_2ECC;
            dev_info(&client->dev, "MIPI DIAG ECC 2-bit error; CSI_ERR_STATUS = 0x%x\n", val);
        }
        if (val & 0x4)
        {
            *mipi_sts |= ISS_SENSOR_MIPI_CHECKSUM;
            dev_info(&client->dev, "MIPI DIAG checksum error; CSI_ERR_STATUS = 0x%x\n", val);
        }
    }

    return ret;
}

int ub9x3_set_fsync_fps(struct i2c_client *client, uint8_t fps)
{
    struct ti9x3_priv *ser = i2c_get_clientdata(client);
    struct ti9x4_priv *deser = ser->deser;
    int ret = 0;

    deser->fps_numerator = 1;
    deser->fps_denominator = fps;
#if TI960_BOARD_EXT_SYNC
    if (deser->use_count)
    {
        epwm_set_fps(deser->fps_denominator / deser->fps_numerator);
    }
#else
    /* TODO: update internal FrameSync here */
    // ret = -EIO;
#endif

    return ret;
}

#define ISS_SENSOR_UB960_TP_FEATURES (ISS_SENSOR_FEATURE_MANUAL_EXPOSURE | \
                                      ISS_SENSOR_FEATURE_MANUAL_GAIN |     \
                                      ISS_SENSOR_FEATURE_LINEAR_MODE)

static IssSensor_CreateParams ub960_testpattern_CreatePrms = {
    .name = "UB960_TESTPATTERN",
    .i2cInstId = {1, 2},
    .i2cAddrSensor = {
        SENSOR_0_I2C_ALIAS, SENSOR_1_I2C_ALIAS, SENSOR_2_I2C_ALIAS, SENSOR_3_I2C_ALIAS,
        SENSOR_4_I2C_ALIAS, SENSOR_5_I2C_ALIAS, SENSOR_6_I2C_ALIAS, SENSOR_7_I2C_ALIAS},
    .i2cAddrSer = {SER_0_I2C_ALIAS, SER_1_I2C_ALIAS, SER_2_I2C_ALIAS, SER_3_I2C_ALIAS, SER_4_I2C_ALIAS, SER_5_I2C_ALIAS, SER_6_I2C_ALIAS, SER_7_I2C_ALIAS},
    /*IssSensor_Info*/
    .sensorInfo = {
        .raw_params = {
            .width = 1280,
            .height = 1080,
            .num_exposures = 1,
            .line_interleaved = vx_false_e,
            .format = {
                [0] = {.pixel_container = TIVX_RAW_IMAGE_16_BIT, .msb = 11},
            },
            .meta_height_before = 0,
            .meta_height_after = 0,
        },
        .features = ISS_SENSOR_UB960_TP_FEATURES,
        .aewbMode = ALGORITHMS_ISS_AEWB_MODE_NONE,
        .fps = 30,
        .numDataLanes = 4,
        .dataLanesMap = {1, 2, 3, 4},
        .dataLanesPolarity = {0, 0, 0, 0},
        .csi_ddr_clock = 1600,
        .otp_id = {
            {'d', 'u', 'm', 'm', 'y', '0'},
            {'d', 'u', 'm', 'm', 'y', '1'},
            {'d', 'u', 'm', 'm', 'y', '2'},
            {'d', 'u', 'm', 'm', 'y', '3'},
            {'d', 'u', 'm', 'm', 'y', '4'},
            {'d', 'u', 'm', 'm', 'y', '5'},
            {'d', 'u', 'm', 'm', 'y', '6'},
            {'d', 'u', 'm', 'm', 'y', '7'},
        },
    },
    .num_channels = 8,
    .dccId = 960,
};

struct ub960_testpattern_priv
{
    void *camera;
};

static struct ub960_testpattern_priv ub960_testpattern_devs[ISS_SENSORS_MAX_CHANNEL];
static int tp_devs = 0;

static int ub960_testpattern_detect(struct i2c_client *client, void *camera)
{
    struct ub960_testpattern_priv *priv;

    priv = &ub960_testpattern_devs[tp_devs];
    priv->camera = camera;
    i2c_set_clientdata(client, priv);
    client->dev.name = ub960_testpattern_drv.name;

    tp_devs++;

    return 0;
}

static int32_t ub960_testpattern_power(struct i2c_client *client, uint32_t on)
{
    dev_info(&client->dev, "%s(%d)\n", __func__, on);

    return 0;
}

static int32_t ub960_testpattern_config(struct i2c_client *client, uint32_t feat)
{
    dev_info(&client->dev, "%s(0x%x)\n", __func__, feat);

    return 0;
}

static int32_t ub960_testpattern_stream(struct i2c_client *client, uint32_t on)
{
    dev_info(&client->dev, "%s(%d)\n", __func__, on);

    return 0;
}

static int32_t ub960_testpattern_rreg(struct i2c_client *client, uint32_t addr, uint32_t *val)
{
    return 0;
}

static int32_t ub960_testpattern_wreg(struct i2c_client *client, uint32_t addr, uint32_t val)
{
    return 0;
}

struct sensor_drv ub960_testpattern_drv = {
    .name = "UB960_TESTPATTERN",
    .params = &ub960_testpattern_CreatePrms,
    .power = ub960_testpattern_power,
    .detect = ub960_testpattern_detect,
    .config = ub960_testpattern_config,
    .stream = ub960_testpattern_stream,
    .rreg = ub960_testpattern_rreg,
    .wreg = ub960_testpattern_wreg,
};

/*******************************************************************************
 *  Debug
 ******************************************************************************/

extern int appCliPrintf(__const char *__restrict __format, ...);

int ub960_deser_debug(struct i2c_client *client)
{
    int idx;
    struct ti9x4_priv *priv = i2c_get_clientdata(client);

    if (priv == NULL)
        return -EINVAL;

    SemaphoreP_pend(sem_ub960_port_switch, SemaphoreP_WAIT_FOREVER);

    /* for all links */
    for (idx = 0; idx < priv->links; idx++)
    {
        u8 reg, reg_hi;
        appCliPrintf("Link %d\n", idx);

        ti9x4_select_rx_port(client, idx);

        if (1)
        {
            uint16_t line_count, line_len;

            reg8_read16(client, 0x73, &line_count);
            reg8_read16(client, 0x75, &line_len);

            appCliPrintf(" res: %dx%d\n", line_len, line_count);
        }

        reg8_read(client, 0x7b, &reg);
        appCliPrintf(" 0x7b CSI errors: %d\n", reg);

        reg8_read(client, 0x7a, &reg);
        appCliPrintf(" 0x7a CSI_RX_STS: 0x%02x: "
                     "%s%s%s%s\n",
                     reg,
                     reg & BIT(3) ? " LENGTH_ERR" : "",
                     reg & BIT(2) ? " CKSUM_ERR" : "",
                     reg & BIT(1) ? " ECC2_ERR" : "",
                     reg & BIT(0) ? " ECC1_ERR" : "");

        reg8_read(client, 0x4d, &reg);
        appCliPrintf(" 0x4d RX_PORT_STS1: 0x%02x: "
                     "%s%s%s%s%s%s\n",
                     reg,
                     reg & BIT(5) ? " BCC_CRC_ERROR" : "",
                     reg & BIT(4) ? " LOCK_STS_CHG" : "",
                     reg & BIT(3) ? " BCC_SEQ_ERROR" : "",
                     reg & BIT(2) ? " PARITY_ERROR" : "",
                     reg & BIT(1) ? " PORT_PASS" : "",
                     reg & BIT(0) ? " LOCK_STS" : "");

        reg8_read(client, 0x4e, &reg);
        appCliPrintf(" 0x4e RX_PORT_STS2: 0x%02x: "
                     "%s%s%s%s%s%s%s%s\n",
                     reg,
                     reg & BIT(7) ? " LINE_LEN_UNSTABLE" : "",
                     reg & BIT(6) ? " LINE_LEN_CHG" : "",
                     reg & BIT(5) ? " FPD3_ENCODE_ERROR" : "",
                     reg & BIT(4) ? " BUFFER_ERROR" : "",
                     reg & BIT(3) ? " CSI_ERROR" : "",
                     reg & BIT(2) ? " FREQ_STABLE" : "",
                     reg & BIT(1) ? " NO_FPD3_CLK" : "",
                     reg & BIT(0) ? " LINE_CNT_CHG" : "");

        reg8_read(client, 0x55, &reg_hi);
        reg8_read(client, 0x56, &reg);
        appCliPrintf(" RX_PAR_ERR: %d\n",
                     reg | (reg_hi << 8));

        reg8_read(client, 0x57, &reg);
        appCliPrintf(" BIST_ERR_COUNT: %d\n",
                     reg);

        reg8_read(client, 0x4f, &reg_hi);
        reg8_read(client, 0x50, &reg);
        appCliPrintf(" RX_FREQ: %d.%03d MHz\n",
                     reg_hi, reg * 1000 / 256);

        if (priv->ser_id[idx] == TI953_ID)
        {
            appCliPrintf(" UB953:\n");

            reg8_read(client, 0x51, &reg);
            appCliPrintf("  0x51 SENSOR_STS_0: 0x%02x: "
                         "%s%s%s%s%s%s\n",
                         reg,
                         reg & BIT(5) ? " CSI_ALARM" : "",
                         reg & BIT(4) ? " BCC_ALARM" : "",
                         reg & BIT(3) ? " LINK_DETECT_ALARM" : "",
                         reg & BIT(2) ? " TEMP_SENSE_ALARM" : "",
                         reg & BIT(1) ? " VOLT1_SENSE_ALARM" : "",
                         reg & BIT(0) ? " VOLT0_SENSE_ALARM" : "");

            reg8_read(client, 0x52, &reg);
            appCliPrintf("  0x52 SENSOR_STS_1: 0x%02x\n", reg);

            reg8_read(client, 0x53, &reg);
            appCliPrintf("  0x53 SENSOR_STS_2: 0x%02x\n", reg);

            reg8_read(client, 0x54, &reg);
            appCliPrintf("  0x54 SENSOR_STS_3: 0x%02x: "
                         "%s%s%s%s%s\n",
                         reg,
                         reg & BIT(4) ? " CSI_ECC_2BIT_ERR" : "",
                         reg & BIT(3) ? " CSI_CHKSUM_ERR" : "",
                         reg & BIT(2) ? " CSI_SOT_ERR" : "",
                         reg & BIT(1) ? " CSI_SYNC_ERR" : "",
                         reg & BIT(0) ? " CSI_CNTRL_ERR" : "");
        }
    }

    SemaphoreP_post(sem_ub960_port_switch);

    appCliPrintf("CSI\n");
    /* for all CSIs */
    for (idx = 0; idx < 2; idx++)
    {
        u8 reg, reg_hi;

        reg8_read(client, 0x90 + (8 * idx), &reg_hi);
        reg8_read(client, 0x91 + (8 * idx), &reg);
        appCliPrintf(" CSI%d_FRAME_COUNT: %d\n",
                     idx, reg | (reg_hi << 8));

        reg8_read(client, 0x94 + (8 * idx), &reg_hi);
        reg8_read(client, 0x95 + (8 * idx), &reg);
        appCliPrintf(" CSI%d_LINE_COUNT: %d\n",
                     idx, reg | (reg_hi << 8));

        reg8_read(client, 0x92 + (8 * idx), &reg_hi);
        reg8_read(client, 0x93 + (8 * idx), &reg);
        appCliPrintf(" CSI%d_FRAME_ERR_COUNT: %d\n",
                     idx, reg | (reg_hi << 8));

        reg8_read(client, 0x96 + (8 * idx), &reg_hi);
        reg8_read(client, 0x97 + (8 * idx), &reg);
        appCliPrintf(" CSI%d_LINE_ERR_COUNT: %d\n",
                     idx, reg | (reg_hi << 8));
    }

    return 0;
}
