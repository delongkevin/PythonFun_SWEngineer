#ifndef _UB960_H_
#define _UB960_H_

#include <iss_evm.h>

#include "ser_camera.h"

/*******************************************************************************
 *  Global settings
 ******************************************************************************/

#define UB9X4_DEVS              2

/*******************************************************************************
 *  Settings
 ******************************************************************************/

#define FORWARDING_MODE_ROUND_ROBIN	0
#define FORWARDING_MODE_SYNCHRONIZED	1

#define TI933_ID					0x58
#define TI953_ID					0x30 /* or starapped to 0x32 */
#define TESTPATTERN_ID					0x99

#define CPMIC_0_I2C_ALIAS 0x60
#define CPMIC_1_I2C_ALIAS 0x61
#define CPMIC_2_I2C_ALIAS 0x62
#define CPMIC_3_I2C_ALIAS 0x63

#define TI9X4_REMOTE_GPIO_CONST0    (0x0U)
#define TI9X4_REMOTE_GPIO_CONST1    (0x1U)
#define TI9X4_REMOTE_GPIO_FSYNC     (0x2U)

#define TI9X4_BC_FREQ_2P5               (0x0U)
#define TI9X4_BC_FREQ_10                (0x2U)
#define TI9X4_BC_FREQ_50                (0x6U)

#define TI9X3_FC_MODE_OVERRIDE          (1U << 4)
#define TI9X3_FC_MODE_CSI_SYNC          (0x1U)
#define TI9X3_FC_MODE_CSI_NONSYNC_EXT   (0x2U)
#define TI9X3_FC_MODE_CSI_NONSYNC_AON   (0x3U)
#define TI9X3_FC_MODE_CSI_DVP           (0x5U)

struct ti9x4_config {
    int    slot;

    int    links;
    int    lanes;
    int    ser_lanes;
    int    csi_rate;
    int    ref_clk;
    int    is_coax;
    int    dvp_bus;
    int    dvp_lsb;
    int    hsync;
    int    vsync;
    int    fs_time;
    int    forwarding_mode;
    int    ser_id[4];
    int    ti9x3_addr_map[4];
    int    vc_map[4];
    int    gpio[4];
    int    poc_delay;
    int    fc_mode;
    int    bc_freq;
};

#define UB960_VC_MAP(a, b, c, d)		(((a) << 0) | ((b) << 2) | ((c) << 4) | ((d) << 6))

#define DT_GENERIC			0x10
#define DT_GENERIC_1			0x11
#define DT_EMBEDDED			0x12
#define DT_YUV_8			0x1e
#define DT_YUV_10			0x1f
#define DT_RGB565			0x22
#define DT_RGB666			0x23
#define DT_RGB888			0x24
#define DT_RAW8				0x2a
#define DT_RAW10			0x2b
#define DT_RAW12			0x2c
#define DT_RAW14			0x2d
#define DT_RAW16			0x2e
#define DT_RAW20			0x2f
#define DT_YUV12			0x30

/*******************************************************************************
 *  Deserializer Exported Functions Declarations
 ******************************************************************************/
struct i2c_client *ub960_deser_init(void *adapter, uint8_t addr, int slot, uint32_t channel_mask, const struct sensor_drv *drv);
void ub960_deser_eeprom_init(void *adapter, uint8_t addr, int slot);
int ub960_read(struct i2c_client *client, uint8_t reg, uint8_t *val);
int ub960_write(struct i2c_client *client, uint8_t reg, uint8_t val);
int ti9x4_status(struct i2c_client *client, const struct sensor_drv *drv);
int ti9x4_status_chg(struct i2c_client *client, const struct sensor_drv *drv,
                     uint32_t *lock_status, uint32_t *lock_status_chg, uint32_t *bcc_err_status);
int ti9x4_status_chg_by_ser(struct i2c_client *client,
                            uint32_t *lock_status, uint32_t *lock_status_chg,
                            uint32_t *bcc_err_status);
int ti9x4_initialize_channel(struct i2c_client *client, const struct sensor_drv *drv, int channel_mask);
void ti9x4_diag(struct i2c_client *client, const struct sensor_drv *drv);
int ti9x4_wait_for_portpass(struct i2c_client *client, uint32_t ch, int timeout_ms);
int ti9x4_port_forward_en_by_ser(struct i2c_client *ser_client, uint32_t idx);
int ti9x4_port_fwd(struct i2c_client *client, uint32_t idx, int on);
int ti9x4_port_reset(struct i2c_client *client, uint32_t idx);

/*******************************************************************************
 *  Serializer Exported Functions Declarations
 ******************************************************************************/
int ub9x3_i2c_set_mapping(struct i2c_client *client, uint8_t n, uint8_t src, uint8_t dst);
int ub9x3_i2c_forwarding(struct i2c_client *client, uint32_t on);
int ub9x3_PoC_set(struct i2c_client *client, uint32_t on);
int ub9x3_stream(struct i2c_client *client, uint32_t on);
int ub9x3_set_fsync_fps(struct i2c_client *client, uint8_t fps);
int ub9x3_mipi_diagnostics(struct i2c_client *client, IssSensor_MipiStatus *mipi_sts);

/*******************************************************************************
 *  Testpattern camera
 ******************************************************************************/
extern struct sensor_drv ub960_testpattern_drv;

/*******************************************************************************
 *  Debug
 ******************************************************************************/
int ub960_deser_debug(struct i2c_client *client);

void ti9x4_link_boot_shutdown(int ch_mask);

#endif /* _UB960_H_ */
