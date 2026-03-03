#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>

#include "ser_camera.h"

#include "ub960.h"
#include "i2c_helpers.h"
#include "type_helpers.h"
#include "app_iss.h"
#include "errno.h"
#include "safety.h"
#include "CamTypes.h"

#ifdef j721s2_hyd
#include <ti/board/src/j721s2_hyd/include/board_internal.h>
#endif

#ifdef BUILD_MCU2_0
#include "ErrorManagerDef.h"
#include "ErrorManagerSatellite.h"
#endif

#include <ti/osal/TimerP.h>
#include <ti/osal/TaskP.h>

extern int appCliPrintf(__const char *__restrict __format, ...);
extern struct i2c_client *ti94x_des[2];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
extern bool_t SigMgr_Data_CamHotplugStatus_t_Put(CamHotplugStatus_t *data);


/******************************************************************************
 * Weak definitions to fix standard MCU2_0 build
 *****************************************************************************/
__attribute__((weak)) void camera_report_error_status(uint32_t cam, uint32_t err_num, int err_status)
{
    return;
}

__attribute__((weak)) void camera_report_otp_fault(int cam_num, int err_status)
{
    return;
}

__attribute__((weak)) void camera_report_sccb_fault(int cam_num, int err_status)
{
    return;
}

__attribute__((weak)) void camera_report_lock_fault(uint32_t lock_status)
{
    return;
}

__attribute__((weak)) void camera_report_bcc_fault(uint32_t bcc_err_status)
{
    return;
}

__attribute__((weak)) void camera_set_for_reset(uint32_t cam_num)
{
	return;
}

__attribute__((weak)) void camera_set_for_shutdown(uint32_t cam_num)
{
	return;
}

__attribute__((weak)) bool camera_is_set_for_action(uint32_t cam_num)
{
    return 0;
}

__attribute__((weak)) void deser_report_error_status(uint32_t deser, uint32_t err_num, int err_status)
{
    return;
}


#ifdef BUILD_MCU2_0

void camera_shutdown(uint32_t cam)
{
    appDeInitImageSensor("ox03c10", 1 << cam);
    return;
}

void camera_reset(uint32_t cam)
{
    struct i2c_client *client;
    uint8_t reg_val;

    client = ti94x_des[0];
    /* Disable port forwarding */
    ti9x4_port_fwd(client, cam, 0);
    appLogWaitMsecs(50u);

    appDeInitImageSensor("ox03c10", 1 << cam);

    /* Set channel BCC freq back to 50MHz so when camera is back in Synchronous mode it is good */
    ti9x4_port_reset(client, cam);

    appLogWaitMsecs(100);
    appPowerupImageSensor("ox03c10", 1 << cam);
    return;
}

int32_t get_ser_mipi_status_via_iss(uint32_t channel_id, IssSensor_MipiStatus *mipi_sts)
{
    int32_t status = -1;
    uint8_t  g_cmdPrm[CMD_PARAM_SIZE];
    char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, dummy_name, ISS_SENSORS_MAX_NAME);
    memcpy(g_cmdPrm + ISS_SENSORS_MAX_NAME, &channel_id, sizeof(uint32_t));

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_GET_MIPI_STATUS,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );
    memcpy(mipi_sts, g_cmdPrm + ISS_SENSORS_MAX_NAME + sizeof(uint32_t), sizeof(IssSensor_MipiStatus));

    return status;
}

int32_t get_cam_pmic_status_via_iss(uint32_t channel_id, IssSensor_CameraPmicStatus *pmic_sts)
{
    int32_t status = -1;
    uint8_t  g_cmdPrm[CMD_PARAM_SIZE];
    char dummy_name[ISS_SENSORS_MAX_NAME] = "dummy";

    memset(g_cmdPrm, 0, CMD_PARAM_SIZE);
    memcpy(g_cmdPrm, dummy_name, ISS_SENSORS_MAX_NAME);
    memcpy(g_cmdPrm + ISS_SENSORS_MAX_NAME, &channel_id, sizeof(uint32_t));

    status = appRemoteServiceRun(
        APP_IPC_CPU_MCU2_0 ,
        (char*)IMAGE_SENSOR_REMOTE_SERVICE_NAME,
        IM_SENSOR_CMD_GET_CAMERA_PMIC_STATUS,
        (void*)g_cmdPrm,
        CMD_PARAM_SIZE,
        0
    );
    memcpy(pmic_sts, g_cmdPrm + ISS_SENSORS_MAX_NAME + sizeof(uint32_t), sizeof(IssSensor_CameraPmicStatus));

    return status;
}

static void camera_mipi_pmic_safety_diag(int cam_num)
{
    IssSensor_MipiStatus       mipi_sts;
    IssSensor_CameraPmicStatus pmic_sts;
    static int mipi_err_count[4][2] = {0};
    int32_t    ret;

    ret = get_ser_mipi_status_via_iss(cam_num, &mipi_sts);
    if (ret) {
        /* Should we report error status here? */
        appLogPrintf("CAM[%d]: MIPI I2C fault %d: set for reset\n", cam_num, ret);
        camera_set_for_reset(cam_num);
    }

    if (mipi_sts & ISS_SENSOR_MIPI_2ECC) {
        appLogPrintf("CAM[%d]: MIPI 2-bit ECC fault: mipi status is 0x%x\n", cam_num, mipi_sts);
        camera_report_error_status(cam_num, ERRMGR_CAM_MIPI_2ECC, 1);
        if (++mipi_err_count[cam_num][0] == 3) {
            camera_set_for_reset(cam_num);
            mipi_err_count[cam_num][0] = 0;
        }
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_MIPI_2ECC, 0);
        mipi_err_count[cam_num][0] = 0;
    }
    if (mipi_sts & ISS_SENSOR_MIPI_CHECKSUM) {
        appLogPrintf("CAM[%d]: MIPI CRC fault: mipi status is 0x%x\n", cam_num, mipi_sts);
        camera_report_error_status(cam_num, ERRMGR_CAM_MIPI_CRC, 1);
        if (++mipi_err_count[cam_num][1] == 3) {
            camera_set_for_reset(cam_num);
            mipi_err_count[cam_num][1] = 0;
        }
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_MIPI_CRC, 0);
        mipi_err_count[cam_num][1] = 0;
    }

    ret = get_cam_pmic_status_via_iss(cam_num, &pmic_sts);
    if (ret) {
        appLogPrintf("CAM[%d]: PMIC I2C fault %d: set for reset\n", cam_num, ret);
        /* Should be set, but do it just in case */
        pmic_sts |= ISS_SENSOR_PMIC_ERR_I2C;
    }

    if (pmic_sts & ISS_SENSOR_PMIC_ERR_ID) {
        appLogPrintf("CAM[%d]: PMIC DEVICE ID fault: PMIC status is 0x%x\n", cam_num, pmic_sts);
        camera_report_error_status(cam_num, ERRMGR_CAM_PMIC_ID, 1);
        camera_set_for_shutdown(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_PMIC_ID, 0);
    }

    if (pmic_sts & (ISS_SENSOR_PMIC_ERR_I2C |
                    ISS_SENSOR_PMIC_ERR_BUCK1 |
                    ISS_SENSOR_PMIC_ERR_BUCK2 |
                    ISS_SENSOR_PMIC_ERR_BUCK3 |
                    ISS_SENSOR_PMIC_ERR_LDO |
                    ISS_SENSOR_PMIC_ERR_DEV)) {
        appLogPrintf("CAM[%d]: PMIC fault: PMIC status is 0x%x\n", cam_num, pmic_sts);
        camera_report_error_status(cam_num, ERRMGR_CAM_PMIC, 1);
        camera_set_for_reset(cam_num);
    } else {
        camera_report_error_status(cam_num, ERRMGR_CAM_PMIC, 0);
    }
}
#endif /* BUILD_MCU2_0 */

void cameras_diag_sts(int slot)
{
    struct i2c_client *client;
    const struct sensor_drv *drv;
    int idx;
#ifdef BUILD_MCU2_0
    static uint8_t count = 0;
#endif

#ifdef BUILD_MCU2_0
    if(count % 2 == 0)
    {
        if (count % 20 == 0) {
            //appLogPrintf("MIPI PMIC diagnostics!\n");
        }
        /* Run below function for every 100msec. */
        for (idx = 0; idx < 4; idx++) {
            if (!camera_is_set_for_action(idx))
            {
                camera_mipi_pmic_safety_diag(idx);
            }
        }
    }
    count++;
#endif

    for (idx = 0; idx < 4; idx++) {
        drv = ser_camera_getdrv(slot*4 + idx);
        if (drv != NULL)
            break;
    }

    if ((slot >= UB9X4_DEVS) || (drv == NULL))
        return;

    client = ti94x_des[slot];
    ti9x4_diag(client,drv);
}

int32_t cameras_status_chg(int slot,
                           uint32_t *lock_status,
                           uint32_t *lock_status_chg,
                           uint32_t *bcc_err_status)
{
    struct i2c_client *client;
    const struct sensor_drv *drv;
    int idx;

    for (idx = 0; idx < 4; idx++) {
        drv = ser_camera_getdrv(slot*4 + idx);
        if (drv != NULL)
            break;
    }

    if (drv == NULL)
    {
        return -EHOSTDOWN;
    }

    if (slot >= UB9X4_DEVS)
    {
        return -EINVAL;
    }

    client = ti94x_des[slot];

    return ti9x4_status_chg(client, drv, lock_status, lock_status_chg, bcc_err_status);
}

int32_t cameras_hotplug(int channel_mask, int slot)
{
    struct i2c_client *client;
    const struct sensor_drv *drv;
    uint32_t idx;
    int ret;
    CamHotplugStatus_t cam_status = {{0,0,0,0}};
    static CamHotplugStatus_t prev_cam_status = {{0,0,0,0}};

    for (idx = 0; idx < 4; idx++) {
        drv = ser_camera_getdrv(slot*4 + idx);
        if (drv != NULL)
            break;
    }

    if ((slot >= UB9X4_DEVS) || (drv == NULL))
        return -1;

    client = ti94x_des[slot];

    ret = ti9x4_initialize_channel(client, drv, channel_mask);

    for (idx = 0; idx < 4; idx++) {
        if (!(BIT(idx) & channel_mask))
            continue;
        Safety_Cam_stream_on(idx);
        int timeout_ms = 150;

        if (ti9x4_wait_for_portpass(client, idx, timeout_ms) != 0)
        {
            ret |= 1 << idx;
        }

    }

    for (idx = 0; idx < 4; idx++)
    {
        if (BIT(idx) & ret)
        {
            camera_set_for_reset(idx);
        }
    }

    /* Enable port forwarding */
    for (idx = 0; idx < 4; idx++)
    {
        if ((BIT(idx) & channel_mask) && !camera_is_set_for_action(idx))
        {
            ti9x4_port_fwd(client, idx, 1);
            cam_status.CamStatus[idx] = 1u; /* Camera hotplug status*/
        }
    }

    if((memcmp(&prev_cam_status, &cam_status, sizeof(CamHotplugStatus_t))) != 0u)
    {    
        /*appLogPrintf("\n MCU2_0:Camera EEPROM read on Hotplug:[%u %u %u %u %u]\n",cam_status.CamStatus[0], cam_status.CamStatus[1], cam_status.CamStatus[2], cam_status.CamStatus[3]);*/
        prev_cam_status = cam_status;
        SigMgr_Data_CamHotplugStatus_t_Put(&cam_status); /* Sending cam hotplug status to A72 core to get for cam EEPROM read request*/
    }
    
    return 0;
}

/* Cameras Hotplug task */

static uint8_t cam_hotplug_task_stack[8*1024] __attribute__((aligned(8192)));

static void cam_hotplug_task(void* arg0, void* arg1)
{
    appLogPrintf("APP: Run cameras hotplug ... !!!\n");

    uint32_t is_exit = 0;
    uint32_t lock_status[UB9X4_DEVS] = {0};
    uint32_t lock_status_chg[UB9X4_DEVS] = {0};
    uint32_t bcc_err_status[UB9X4_DEVS] = {0};
    int32_t  ret[UB9X4_DEVS];
    int i;

    while(!is_exit)
    {
        for (i = 0; i < UB9X4_DEVS; i++)
        {
            ret[i] = cameras_status_chg(i, &lock_status[i], &lock_status_chg[i], &bcc_err_status[i]);
            if (ret[i])
            {
                continue;
            }

            if (lock_status[i] > 0)
            {
                if (lock_status_chg[i])
                {
                    ret[i] = cameras_hotplug(lock_status_chg[i] & lock_status[i], i);
                    if (ret[i])
                    {
                        continue;
                    }
                }
            }
        }

        if (ret[0] == 0)
        {
            /* Safety report */
            camera_report_lock_fault(lock_status[0]);
            camera_report_bcc_fault(bcc_err_status[0]);
            deser_report_error_status(0, ERRMGR_DESER_I2C_NAK, 0);

            if (lock_status[0] != 0xf || bcc_err_status[0] != 0U )
            {
                appLogWaitMsecs(150u);
            }
            else
            {
                appLogWaitMsecs(1000u);
            }
        }
        else if (ret[0] == -EHOSTDOWN)
        {
            /* Cameras are not streaming yet. Waiting patiently */
            appLogWaitMsecs(1000u);
        }
        else
        {
            appLogPrintf("Hotplug thread: Failed to read deserializer[0] status: %d!\n", ret[0]);
            deser_report_error_status(0, ERRMGR_DESER_I2C_NAK, 1);
            appLogWaitMsecs(150u);
        }
    }

    appLogPrintf("APP: Run cameras hotplug ... Done !!!\n");
}

static uint8_t cam_diagsts_task_stack[8*1024] __attribute__((aligned(8192)));
static void cam_diagsts_task(void* arg0, void* arg1)
{
    appLogPrintf("APP: Run cameras diag sts ... !!!\n");

    while(TRUE)
    {
            cameras_diag_sts(0);
            appLogWaitMsecs(50u);
    }

}

void appRunCamHotplug(void)
{
    TaskP_Params tskParams;
    TaskP_Handle task;

    TaskP_Params_init(&tskParams);
    tskParams.priority = 8u;
    tskParams.stack = cam_hotplug_task_stack;
    tskParams.stacksize = sizeof(cam_hotplug_task_stack);
    task = TaskP_create(cam_hotplug_task, &tskParams);
    if(NULL == task)
    {
        appLogPrintf("appRunCamHotplug: failed to create task !!!\n");
    }

    TaskP_Params_init(&tskParams);
    tskParams.priority = 8u;
    tskParams.stack = cam_diagsts_task_stack;
    tskParams.stacksize = sizeof(cam_diagsts_task_stack);
    task = TaskP_create(cam_diagsts_task, &tskParams);
    if(NULL == task)
    {
        appLogPrintf("appRunCamDiagStsForHotPlug: failed to create task !!!\n");
    }
}

#ifdef ENABLE_UART_CLI

static int32_t cameras_status(int slot)
{
    struct i2c_client *client;
    const struct sensor_drv *drv;
    int idx;

    for (idx = 0; idx < 4; idx++) {
        drv = ser_camera_getdrv(slot*4 + idx);
        if (drv != NULL)
            break;
    }

    if ((slot >= UB9X4_DEVS) || (drv == NULL))
        return -1;

    client = ti94x_des[slot];

    return ti9x4_status(client, drv);
}

/******************************************************************************
 * Sub commands
******************************************************************************/

static char cam_help_text[] =
    "cam plug cam#          - plug cam[0..3]\n"
    "cam status             - lock status for all connect cam[0..3]\n"
    ;

static int32_t cam_tools_help(int argc, char *argv[])
{
    appCliPrintf("cam command usage:\n%s\n", cam_help_text);

    return 0;
}

static int32_t cam_status(int argc, char *argv[])
{
    return cameras_status(0);
}

static int32_t cam_plug(int argc, char *argv[])
{
    int32_t ret;
    int channel_mask = -1;

    if (argc < 1) {
        appCliPrintf("No enough arguments!\n");
        return -1;
    }

    channel_mask = atoi(argv[0]);
    if (channel_mask < 0 || channel_mask > 3) {
        appCliPrintf("Invalid argument!\n");
        return -1;
    }

    ret = cameras_hotplug(channel_mask, 0);

    return ret;
}

struct cam_command_desc {
    const char *cmd;
    int32_t (*execute)(int argc, char *argv[]);
};

static const struct cam_command_desc commands[] = {
    {"plug", &cam_plug},
    {"status", &cam_status},
    {"help", &cam_tools_help},
    {NULL, NULL},
};

int32_t cam_tools(int argc, char *argv[])
{
    /* first arg is "md" */
    argc--;
    argv++;

    const struct cam_command_desc *desc;
    for (desc = &commands[0]; desc->cmd != NULL; desc++)
    {
        if (strcmp(argv[0], desc->cmd) == 0)
        {
            return desc->execute(argc - 1, argv + 1);
        }
    }

    if (desc->cmd == NULL)
    {
        appCliPrintf("Unknown cam command\n");
    }

    return -1;
}

int cam_tools_complete(char *line, int cursor, int n)
{
    const struct cam_command_desc *desc;
    const struct cam_command_desc *proposed = NULL;
    char *space = strchr(line, ' ');
    int space_pos = -1;
    int shift;
    int len = strlen(line);

    if (space != NULL)
    {
        space_pos = space - line;
    }

    if (cursor < space_pos || space_pos < 0)
    {
        for (desc = &commands[0]; desc->cmd != NULL; desc++)
        {
            if (strncmp(line, desc->cmd, cursor) == 0)
            {
                if (proposed == NULL)
                {
                    proposed = desc;
                }
                else
                {
                    /*.. several commands found, cannot decide which one to choose */
                    proposed = NULL;
                    break;
                }
            }
        }

        if (proposed != NULL)
        {
            int insert_len = strlen(proposed->cmd) - cursor;
            shift = insert_len + 1 + 1; /*.. also a space and a terminator */
            if (len + shift >= n)
            {
                shift = n - len - 1 - 2;
            }

            char *insert_at = line + cursor;

            memmove(insert_at + shift, insert_at, shift);
            strncpy(insert_at, proposed->cmd + cursor, shift - 1);
            strncpy(insert_at + insert_len, " ", 2);

            /*.. terminate anyway */
            line[n - 1] = '\0';

            cursor += shift - 1;
        }
    }

    return cursor;
}
#endif /* ENABLE_UART_CLI */
