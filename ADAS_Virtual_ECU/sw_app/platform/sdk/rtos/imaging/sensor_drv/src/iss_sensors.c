#include <iss_sensors.h>
#include <iss_sensor_if.h>
#include <iss_sensor_priv.h>
#include <app_remote_service.h>
#include <app_ipc.h>
#include <app_iss.h>

#include "errno.h"
#include "ub960.h"
#include "ser_camera.h"
#include "type_helpers.h"
#include "epwm_helper.h"
#include "tca9539.h"
#include "tps65033.h"
#include "cam_tools.h"
#include "safety.h"
#include "crc32.h"

#include "stellantis.h"

#include "VoltageCurrent_data.h"
#include "ProxiMgrIpcDataTypes.h"

/* Globals */

IssSensors_Handle *gIssSensorTable[ISS_SENSORS_MAX_SUPPORTED_SENSOR];
extern I2C_Handle gISS_Sensor_I2cHandle[14 + 16]; /* TODO: remove */

/* Externs */
extern u8 csi_frame_count[2], csi_frame_count_error[2];
extern CAM_Curr_Volt_Monitor_t CAM_CurrVoltData[4];
extern u8 CAM_PWR_EN_Sts[4];
extern void SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(ME_ProxiToMCU2_0_Def_t *data);

void getCamCurrVoltData(uint32 chId,CAM_Curr_Volt_Monitor_t *CAM_CurrVoltData_Arg);

/*Static variables*/ 
/* static sizes for the three eeprom data sections
These variable declarations should match with A core declarations in SvsCamTypes.h, if there is a change update at both places*/
static const uint8_t c_EepromDataCrcStartAddress_u8 = 248U;
static const uint32_t c_EepromDataCrcSize_u32 = 4U;
static const uint8_t c_EepromDataProductionStartAddress_u8 = 0U;
/*static const uint32_t c_EepromDataProductionSize_u32 = 64U;
static const uint32_t c_EepromDataIntrinsicSize_u32 = 128U;*/
static const uint8_t c_EepromDataCRCCheckStartAddress_u8 = 2U;
static const uint8_t c_EepromDataCRCCheckSize_u8 = 246u;


#define EEPROM_DATA_SIZE (192U) /* c_EepromDataProductionSize_u32 + c_EepromDataIntrinsicSize_u32*/

/*
 * Global Functions
 */

int32_t IssSensor_EarlyInit()
{
	int32_t ret, i;

	ret = pca953x_bus_init();
	if (ret) {
		appLogPrintf("%s: failed to init i2c exp\n");
		return ret;
	}

	/*
	 * Make sure all cameras, deserializer and serializer
	 * are powered down to properly reset it.
	 * Power will be enabled later during sensor initialization
	 */
	ub960_deser_power(0);
	csitx_ser_power(0);
	iss_board_PoC_disable(0xf);
	cam_common_power(0);
	mdelay(100);

	for (i = 0; i < ISS_SENSORS_MAX_SUPPORTED_SENSOR; i++)
		gIssSensorTable[i] = NULL;

	appInitImageSensor_early("ox03c10", 0, 0x0f);

	return ret;
}

int32_t IssSensor_Init()
{
	int32_t ret;

	ser_camera_eeprom_init();

	ret = appRemoteServiceRegister(IMAGE_SENSOR_REMOTE_SERVICE_NAME,
				       ImageSensor_RemoteServiceHandler);
	if (ret) {
		appLogPrintf("%s: fail to register\n", IMAGE_SENSOR_REMOTE_SERVICE_NAME);
		return ret;
	}

	return ret;
}

int32_t IssSensor_DeInit(void)
{
	int32_t ret;

	ret = appRemoteServiceUnRegister(IMAGE_SENSOR_REMOTE_SERVICE_NAME);
	if (ret)
		appLogPrintf(" %s: fail to unregister\n", IMAGE_SENSOR_REMOTE_SERVICE_NAME);

	return ret;
}

static int32_t IssSensor_EepromRead(uint32_t chId,
                                    uint8_t *ptr,
                                    uint32_t offset,
                                    uint32_t len)
{
	uint8_t EepromI2cAddrs[] = {0x50, 0x54, 0x58, 0x5c};
    I2C_Handle eepromI2cHandle = NULL;

    if (chId >= 4)
	{
        return VX_FAILURE;
	}

    if (camera_is_set_for_action(chId))
    {
        return VX_FAILURE;
    }

    /* out of eerpom */
    if (offset + len > (4 * 256))
	{
        return VX_FAILURE;
	}

	eepromI2cHandle = i2c_get_handle(1);

    while (len) {
        int ret;
        /* offset within 256 bytes */
        uint8_t int_offset = (offset & 0xff);
        /* chunk: whole len or till 256 bytes boundary */
        int chunk = len > (256 - int_offset) ? (256 - int_offset) : len;

        I2C_Transaction transaction;

        I2C_transactionInit(&transaction);

        transaction.slaveAddress = EepromI2cAddrs[chId] + (offset >> 8);
        transaction.writeBuf     = &int_offset;
        transaction.writeCount   = 1;
        transaction.readBuf      = ptr;
        transaction.readCount    = chunk;
        transaction.timeout      = 1000;

        ret = I2C_transfer(eepromI2cHandle, &transaction);
        if(ret != 1u)
        {
            //appLogPrintf("Error reading eeprom chId %d, offset 0x%03x: %d\n ", chId, offset, ret);
            return VX_FAILURE;
        }

        offset += chunk;
        ptr += chunk;
        len -= chunk;
    }

    return VX_SUCCESS;
}

static int32_t IssSensor_GetCameraPmicStatus(uint32_t chId, IssSensor_CameraPmicStatus *pmicSts)
{
	int32_t ret;
	uint8_t PmicI2cAddrs[] = {
		CPMIC_0_I2C_ALIAS,
		CPMIC_1_I2C_ALIAS,
		CPMIC_2_I2C_ALIAS,
		CPMIC_3_I2C_ALIAS,
	};
	I2C_Handle pmicI2cHandle = NULL;

	if (chId >= 4)
	{
		return VX_FAILURE;
	}

	pmicI2cHandle = i2c_get_handle(1);

	ret = tps65033_get_status(pmicI2cHandle, PmicI2cAddrs[chId], pmicSts);

	return ret;
}

int32_t IssSensor_Control(void* handle, uint32_t cmd, void* cmdArgs, uint32_t cmdArgsSize, void* cmdRetArgs)
{
    int32_t status = VX_FAILURE;
    uint32_t chId = 0xFF;
    IMAGE_SENSOR_CTRLCMD ctrlCmd;
    uint8_t * cmd_ptr = (uint8_t *)cmdArgs;

    if(NULL == cmd_ptr)
    {
        appLogPrintf("Error : cmd_ptr is NULL \n");
        return VX_FAILURE;
    }

    cmd_ptr += ISS_SENSORS_MAX_NAME;
	cmdArgsSize -= ISS_SENSORS_MAX_NAME;

    memcpy(&chId, cmd_ptr, sizeof(uint32_t));
    cmd_ptr += sizeof(uint32_t);
	cmdArgsSize -= sizeof(uint32_t);

    memcpy(&ctrlCmd, cmd_ptr, sizeof(IMAGE_SENSOR_CTRLCMD));
    cmd_ptr += sizeof(IMAGE_SENSOR_CTRLCMD);
	cmdArgsSize -= sizeof(IMAGE_SENSOR_CTRLCMD);

    switch(ctrlCmd)
    {
        case IMAGE_SENSOR_CTRLCMD_GETEXPPRG:
        case IMAGE_SENSOR_CTRLCMD_GETWBCFG:
        case IMAGE_SENSOR_CTRLCMD_SETEXPGAIN:
        case IMAGE_SENSOR_CTRLCMD_GETEXPGAIN:
        case IMAGE_SENSOR_CTRLCMD_SETWBGAIN:
        case IMAGE_SENSOR_CTRLCMD_GETWBGAIN:
            status = 0;
            break;
        case IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG:
            {
#if 1
                uint32_t addr;
                uint32_t val = 0xff;
                uint32_t *ptr32 = (uint32_t *)cmd_ptr;

                addr = (uint16_t)(*ptr32);
                ptr32++;
                status = ser_camera_read_reg(chId, addr, &val);
                *ptr32 = val;

//                appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG: "
//                    "0x%0x -> 0x%x\n", __func__, addr, val);
#else
                status = 0;
#endif
            }
            break;
        case IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG:
            {
#if 1
                uint32_t addr;
                uint32_t val;
                uint32_t *ptr32 = (uint32_t *)cmd_ptr;

                addr = (uint16_t)(*ptr32);
                ptr32++;
                val = (uint16_t)(*ptr32);
                status = ser_camera_write_reg(chId, addr, val);

//                appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG: "
//                    "0x%0x <- 0x%x\n", __func__, addr, val);
#else
                status = 0;
#endif
            }
            break;
        case IMAGE_SENSOR_CTRLCMD_READ_SENSOR_NREGS:
            {
                uint8_t buf[MAX_GROUP_REG_NUMBER];
                int numRegs;
                uint8_t *ptr8 = (uint8_t *)cmd_ptr;
                uint16_t addr;

                addr = *ptr8++; // addr msb
                addr = *ptr8++ | (addr << 8); // addr lsb
                numRegs = (int)*ptr8++;
                status = ser_camera_read_nregs(chId, addr, buf, numRegs);
                memcpy(ptr8, buf, numRegs);

                //appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_READ_SENSOR_NREGS: 0x%0x -> 0x%x 0x%x 0x%x 0x%x N=%d\n", __func__, addr, buf[0], buf[1], buf[2], buf[3], numRegs);
                if (status) {
                    appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_READ_SENSOR_NREGS: ch=%d, reg 0x%04x N=%d, failed with status %d\n",
                        __func__, chId, addr, numRegs, status);
                }
            }
            break;
        case IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS:
            {
                uint8_t buf[MAX_GROUP_REG_NUMBER + 2]; // + addr 16bit
                int numRegs;
                uint8_t *ptr8 = (uint8_t *)cmd_ptr;
                uint16_t addr;

                buf[0] = *ptr8++; // addr msb
                buf[1] = *ptr8++; // addr lsb
                addr = buf[0] << 8 | buf[1];
                numRegs = (int)*ptr8++;
                memcpy(buf+2, ptr8, numRegs);
                //appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS: 0x%0x 0x%x  <- 0x%x, 0x%x 0x%x 0x%x N=%d\n", __func__, buf[0], buf[1], buf[2], buf[3], buf[4], buf[5], numRegs);

                status = ser_camera_write_nregs(chId, buf, numRegs + 2);

                if (status) {
                    appLogPrintf("%s: IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS: ch=%d, reg 0x%04x N=%d, failed with status %d\n",
                        __func__, chId, addr, numRegs, status);
                }
            }
            break;
        case IMAGE_SENSOR_CTRLCMD_SETFPS:
            {
                uint8_t fps;
                uint8_t *ptr8 = (uint8_t *)cmd_ptr;

				/* TODO: get mask from command! */
				uint32_t channel_mask = 0xff;
				fps = *ptr8++;

				status = ser_camera_set_fps(channel_mask, fps);
            }
            break;
		case IMAGE_SENSOR_CTRLCMD_READ_EEPROM:
            {
                uint32_t offset;
                uint32_t len;
                uint8_t au8CamEEPROMData_Cmp[EEPROM_DATA_SIZE] = {0};/* buffer with 0's to compare Camera EEPROM Data size excluding CRC*/
                uint32_t v_CrC_u32 = 0;
                uint32_t CamEEPROM_crc = 0;
                ME_ProxiToMCU2_0_Def_t CameraConfig = {0};

                SigMgr_Data_ME_ProxiToMCU2_0_Def_t_Get(&CameraConfig);

                memcpy(&offset, cmd_ptr, sizeof(offset));
                cmd_ptr += sizeof(offset);
                cmdArgsSize -= sizeof(offset);

                memcpy(&len, cmd_ptr, sizeof(len));
                cmd_ptr += sizeof(len);
                cmdArgsSize -= sizeof(len);

                if (len <= cmdArgsSize) {
                    if(FALSE == CameraConfig.PRX_SurroundViewCamera_b)/* Requirement ID:18642819 Single Camera configuration*/
                    {
                        if(chId == 3U)
                        {
                                status = IssSensor_EepromRead(chId, cmd_ptr, offset, len);
                                if(status == VX_SUCCESS)
                                {
                                    /* Comparing the camera intrisic data to check if the data is 0*/
                                    if(0 != memcmp(au8CamEEPROMData_Cmp, &cmd_ptr[c_EepromDataProductionStartAddress_u8], EEPROM_DATA_SIZE))
                                    {
                                        camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 0);/* Clearing the Fault*/
                                    }
                                    else
                                    {
                                        camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 1);/* Setting the Fault*/
                                    }
                                    /*Camera EEPROM data CRC check*/
                                    v_CrC_u32 = crc_calculateCRC32(&cmd_ptr[c_EepromDataCRCCheckStartAddress_u8], c_EepromDataCRCCheckSize_u8, CRC_INITIAL_VALUE32);
                                    memcpy(&CamEEPROM_crc, &cmd_ptr[c_EepromDataCrcStartAddress_u8], c_EepromDataCrcSize_u32);
                                    if(CamEEPROM_crc == v_CrC_u32)
                                    {
                                        camera_report_error_status(chId, ERRMGR_CAM_EEPROM_CRC_FAIL, 0);/*Clearing the Fault*/
                                    }
                                    else
                                    {
                                        camera_report_error_status(chId, ERRMGR_CAM_EEPROM_CRC_FAIL, 1);/*Setting the Fault*/
                                    }
                                
                                }
                                else
                                {
                                        /*Camera EEPROM read failed, setting Intrinsic zero fault*/
                                        /*EEPROM Read failure (I2C Error) results in no data, Here we use default camera intrinsic data on A72 core*/
                                        camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 1);/*Setting the Fault*/
                                }
                            }
                            else
                            {
                                /*Nothing to do*/
                            }
                    }
                    else /* Requirement ID:18768256 Four camera configuration */
                    {
                        status = IssSensor_EepromRead(chId, cmd_ptr, offset, len);
                        if(status == VX_SUCCESS)
                        {
                            /* Comparing the camera intrisic data to check if the data is 0*/
                            if(0 != memcmp(au8CamEEPROMData_Cmp, &cmd_ptr[c_EepromDataProductionStartAddress_u8], EEPROM_DATA_SIZE))
                            {
                                camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 0);/* Clearing the Fault*/
                            }
                            else
                            {
                                camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 1);/* Setting the Fault*/
                            }
                            /*Camera EEPROM data CRC check*/
                            v_CrC_u32 = crc_calculateCRC32(&cmd_ptr[c_EepromDataCRCCheckStartAddress_u8], c_EepromDataCRCCheckSize_u8, CRC_INITIAL_VALUE32);
                            memcpy(&CamEEPROM_crc, &cmd_ptr[c_EepromDataCrcStartAddress_u8], c_EepromDataCrcSize_u32);
                            if(CamEEPROM_crc == v_CrC_u32)
                            {
                                camera_report_error_status(chId, ERRMGR_CAM_EEPROM_CRC_FAIL, 0);/*Clearing the Fault*/
                            }
                            else
                            {
                                camera_report_error_status(chId, ERRMGR_CAM_EEPROM_CRC_FAIL, 1);/*Setting the Fault*/
                            }

                        }
                        else
                        {
                                /*Camera EEPROM read failed, setting Intrinsic zero fault*/
                                /*EEPROM Read failure (I2C Error) results in no data, Here we use default camera intrinsic data on A72 core*/
                                camera_report_error_status(chId, ERRMGR_CAM_INTRINSIC_ZERO, 1);/*Setting the Fault*/
                        }   
                    }
                }
                else {
                    appLogPrintf("IMAGE_SENSOR_CTRLCMD_DEBUG Error : EEPROM read: no enough space\n");
                    status = -1;
                }
            }
            break;
        default:
            status = -1;
            appLogPrintf("IMAGE_SENSOR_CTRLCMD_DEBUG Error: Unknown control command %d \n", ctrlCmd);
            break;
    }

    return (status);
}

/*
 *  Local Functions
 */

int32_t ImageSensor_RemoteServiceHandler(char *service_name, uint32_t cmd,
					 void *prm, uint32_t prm_size, uint32_t flags)
{
	IssSensor_CreateParams *pSenParams = (IssSensor_CreateParams * )NULL;
	uint8_t *cmd_param = (uint8_t * )prm;
	char *sensor_name = NULL;
	uint32_t i, on = 0;
	uint32_t sensor_features_requested = 0;
	uint32_t channel_mask = 0x00;
	int32_t status = -1;

	switch(cmd) {
	case IM_SENSOR_CMD_ENUMERATE:
		appLogPrintf("%s: IM_SENSOR_CMD_ENUMERATE\n", __func__);
		status = ser_camera_get_drv_list((char *)cmd_param, prm_size);
		break;
	case IM_SENSOR_CMD_ENUMERATE2:
		status = ser_camera_get_drv_list2((char *)cmd_param, prm_size);
		break;
	case IM_SENSOR_CMD_QUERY:
		sensor_name = (char *)(cmd_param);
		appLogPrintf("%s: IM_SENSOR_CMD_QUERY: %s\n", __func__, sensor_name);

		pSenParams = (IssSensor_CreateParams * )(cmd_param + ISS_SENSORS_MAX_NAME);
		status = ser_camera_get_sensor_info(sensor_name, pSenParams);
		break;
	case IM_SENSOR_CMD_PWRON:
		sensor_name = (char*)(cmd_param);
		memcpy(&channel_mask, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
		appLogPrintf("%s: IM_SENSOR_CMD_PWRON %s channel_mask=0x%x\n", __func__, sensor_name, channel_mask);

		status = iss_board_PoC_enable(channel_mask);
		break;
	case IM_SENSOR_CMD_PWROFF:
		sensor_name = (char*)(cmd_param);
		memcpy(&channel_mask, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
		appLogPrintf("%s: IM_SENSOR_CMD_PWROFF: %s channel_mask=0x%x\n", __func__, sensor_name, channel_mask);

		/* deinit all! */
		ser_camera_board_deinit(channel_mask);

		status = iss_board_PoC_disable(channel_mask);
		break;
	case IM_SENSOR_CMD_CONFIG:
		sensor_name = (char*)(cmd_param);
		memcpy(&sensor_features_requested, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
		memcpy(&channel_mask,  cmd_param + ISS_SENSORS_MAX_NAME + sizeof(uint32_t), sizeof(uint32_t));
		appLogPrintf("%s: IM_SENSOR_CMD_CONFIG: %s channel_mask=0x%x, features=0x%x\n",
			     __func__, sensor_name, channel_mask, sensor_features_requested);

		/* First configure all enabled cameras */
		for (i = 0; i < ISS_SENSORS_MAX_CHANNEL; i++) {
			if (channel_mask & BIT(i)) {
				/* this will just store sensor_features_requested for further use */
				status = ser_camera_configure(i, sensor_features_requested);
				if (status) {
					status = -1;
					appLogPrintf("ERROR: failed for camera %d: %d\n", i, status);
				}
			}
		}

		/* now do probe */
		if (status == 0) {
			status = ser_camera_board_probe(sensor_name, channel_mask);
		}
		break;
	case IM_SENSOR_CMD_STREAM_ON:
		on = 1;
	case IM_SENSOR_CMD_STREAM_OFF:
		sensor_name = (char*)(cmd_param);
		memcpy(&channel_mask, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
		appLogPrintf("%s: IM_SENSOR_CMD_STREAM_%s: %s channel_mask 0x%x\n", __func__,
			     on ? "ON" : "OFF", sensor_name, channel_mask);

        if (on == 0)
        {
            for (i = 0; i < ISS_SENSORS_MAX_CHANNEL; i++) {
                if (channel_mask & BIT(i)) {
                    ser_camera_hotplug_diag(i, on);
                }
            }
        }

		for (i = 0; i < ISS_SENSORS_MAX_CHANNEL; i++) {
			if (channel_mask & BIT(i)) {
				status = ser_camera_stream(i, on);
				if (status) {
					appLogPrintf("ERROR: failed for camera %d: %d\n", i, status);
					if (on) {
						if (status == -EFAULT) {
							camera_report_otp_fault(i, 1);
							camera_set_for_reset(i);
						} else {
							camera_report_otp_fault(i, 0);
						}
						/* Ignore errors, since this is required for hotplug */
						status = 0;
					} else {
						/* Ignore errors on stream off only */
						status = 0;
					}
				}
			}
		}

        if (on == 1)
        {
            for (i = 0; i < ISS_SENSORS_MAX_CHANNEL; i++) {
                if (channel_mask & BIT(i)) {
                    ser_camera_hotplug_diag(i, on);
                }
            }
        }
		break;
	case IM_SENSOR_CMD_CTL:
		//appLogPrintf("%s: IM_SENSOR_CMD_CTL\n", __func__);
		status = IssSensor_Control(NULL, 0, (void*)cmd_param, prm_size, NULL);
		break;
	case IM_SENSOR_CMD_I2C_EXP_SET_VAL:
		status = pca953x_set_value(*cmd_param, *(cmd_param + 1),
					   *(cmd_param + 2));
		break;
	case IM_SENSOR_CMD_I2C_EXP_SET_DIR:
		{
			uint8_t exp_id = *cmd_param;
			uint8_t pin = *(cmd_param + 1);
			uint8_t dir = *(cmd_param + 2);
			uint8_t val = *(cmd_param + 3);
			status = dir ? pca953x_direction_output(exp_id, pin, val) :
				pca953x_direction_input(exp_id, pin);
		}
		break;
	case IM_SENSOR_CMD_I2C_EXP_GET_VAL:
		{
			status = pca953x_get_value(*cmd_param,
						   *(cmd_param + 1),
						   cmd_param + 2);
		}
		break;
    case IM_SENSOR_CMD_GET_MIPI_STATUS:
        {
            uint32_t channel_id;
            sensor_name = (char*)(cmd_param);
		    memcpy(&channel_id, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
            status = ser_camera_get_mipi_diagnostics(channel_id, (IssSensor_MipiStatus *) (cmd_param + ISS_SENSORS_MAX_NAME + sizeof(uint32_t)));
        }
        break;
	case IM_SENSOR_CMD_GET_CAMERA_PMIC_STATUS:
		{
			uint32_t channel_id;
			sensor_name = (char*)(cmd_param);
			memcpy(&channel_id, cmd_param + ISS_SENSORS_MAX_NAME, sizeof(uint32_t));
			status = IssSensor_GetCameraPmicStatus(channel_id, (IssSensor_CameraPmicStatus *) (cmd_param + ISS_SENSORS_MAX_NAME + sizeof(uint32_t)));
		}
		break;
	default:
		appLogPrintf("%s: Unsupported command : 0x%x\n", __func__, cmd);
		status = -1;
	}

//	if (status)
//		appLogPrintf("%s: status = %d\n", __func__, status);

	return status;
}


/* The following function is not used now for DTC setting but might be required
 * Keep as is from core implementation - Address and values of registers need to be updated
 * TODO : !!Fix before use - for OV cameras!!
 */
uint8_t getStreamStatus(uint32_t chId)
{
   uint8_t streamState =0;
   uint32_t addr = (uint16_t)(0x301A);
   uint32_t buf=0;
   int32_t status = ser_camera_read_reg(chId, addr, &buf);
   if(status == 0)
   {
      if(((buf & 0x001cU) == 0x001cU))
      {
         streamState|=(1<<chId);
      }
      else if(((buf & 0x0018U) == 0x0018U) )
      {
         streamState &=~(1<<chId);
      }
   }
  return streamState;
}

/* Get the value of temperature from Imager (chosen by chId arg) */
#if 0
float getThermalStatus(uint32_t chId)
{
   float tempInC=0; /* TODO : If we are unable to read the value of temp sensors for some reason this is the value we will return*/
   uint32_t TempSensor0_Addr[2] = {0x4D56,0x4D57};
   uint32_t TempSensor1_Addr[2] = {0x4D58,0x4D59};
   /* uint32_t TempAverage_Addr[2] = {0x4D2A,0x4D2B}; */ /* commented code for dev purpose */
   uint32_t buf0_int=0,buf0_dec=0;
   uint32_t buf1_int=0,buf1_dec=0;
   int32_t status;

   status  = ser_camera_read_reg(chId, TempSensor0_Addr[0], &buf0_int);
   status |= ser_camera_read_reg(chId, TempSensor1_Addr[0], &buf1_int);

   if(status == 0)
   {
     status  = ser_camera_read_reg(chId, TempSensor0_Addr[1], &buf0_dec);
     status |= ser_camera_read_reg(chId, TempSensor1_Addr[1], &buf1_dec);
     if((buf0_int<=0xC0) && (buf1_int<=0xC0))
     {
        tempInC = (float)((buf0_int>=buf1_int)?buf0_int:buf1_int);
        if(status == 0)
        {
            tempInC += (float)((buf0_int>=buf1_int)?(float)(buf0_dec/256.0):(float)(buf1_dec/256.0));
        }
     }
     else if((buf0_int>=0xC0) && (buf1_int>=0xC0))
     {
        /* Both Sensors are reading negative value - pick one to minimize decisions/code
         * Thermal shutdown is applicable for high temps only so no need to add logic here
         */
        tempInC = (float)(buf0_int-0xC0) + (float)(buf0_dec/256.0);
     }
     else
     {
        /* If control reaches here, one sensor is reading positive temperature while the other negative
         * Take the higher (+ve) temperature value as the correct one, to be conservative
         */
        if(buf0_int<=0xC0)
        {
            tempInC = (float)(buf0_int) + (float)(buf0_dec/256.0);
        }
        else
        {
            tempInC = (float)(buf1_int) + (float)(buf1_dec/256.0);
        }
     }
   }
  return tempInC;
}

void GetImgSensorFrameCounter(uint32_t chId, uint32_t *FrameCounter)
{
    uint32_t FrameCounter_Local[4];
    ser_camera_read_reg(chId, 0x4623, &FrameCounter_Local[0]); /* VFIFO_FCNT0 : Frame Counter Byte 0*/
    ser_camera_read_reg(chId, 0x4622, &FrameCounter_Local[1]); /* VFIFO_FCNT1 : Frame Counter Byte 1*/
    ser_camera_read_reg(chId, 0x4621, &FrameCounter_Local[2]); /* VFIFO_FCNT2 : Frame Counter Byte 2*/
    ser_camera_read_reg(chId, 0x4620, &FrameCounter_Local[3]); /* VFIFO_FCNT3 : Frame Counter Byte 3*/
    *FrameCounter = (uint32_t)((FrameCounter_Local[3]<<24u) |
                    (FrameCounter_Local[2]<<16u) |
                    (FrameCounter_Local[1]<<8u ) |
                    (FrameCounter_Local[0]));
}
#endif
#if 0
uint8_t getCamFaultASts(uint32 chId)
{
    return CAM_PWR_EN_Sts[chId];
}
#endif
void getCamCurrVoltData(uint32 chId,CAM_Curr_Volt_Monitor_t *CAM_CurrVoltData_Arg)
{
    CAM_CurrVoltData_Arg->CAM_CS_A = CAM_CurrVoltData[chId].CAM_CS_A;
    CAM_CurrVoltData_Arg->CAM_PS_MON = CAM_CurrVoltData[chId].CAM_PS_MON;
    CAM_CurrVoltData_Arg->FreshnessCounter = CAM_CurrVoltData[chId].FreshnessCounter;

}

/*Image frozen check*/
uint16_t getCsiFrameCount(void)
{
   uint16_t upper8Bit = csi_frame_count[1];
    return (uint16_t)((upper8Bit<<8)|(csi_frame_count[0]));
}

uint16_t getCsiFrameCountWithError(void)
{
  uint16_t upper8Bit = csi_frame_count_error[1];
    return (uint16_t)((upper8Bit<<8)|(csi_frame_count_error[0]));

}

