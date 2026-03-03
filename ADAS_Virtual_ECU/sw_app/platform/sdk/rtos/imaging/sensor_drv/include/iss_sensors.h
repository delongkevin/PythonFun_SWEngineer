#ifndef ISS_SENSORS_H_
#define ISS_SENSORS_H_

#include <TI/tivx.h>
#include "TI/j7_kernels.h"

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>

/*******************************************************************************
 *  Include files
 *******************************************************************************
 */

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */


/**
 *  \brief RPC Commands application can send to sensor driver
 * \ingroup group_vision_function_imaging_sensordrv
 */
#define SENSOR_I2C_TIMEOUT    (5000U)

typedef enum
{
    IM_SENSOR_CMD_ENUMERATE = 0,
    IM_SENSOR_CMD_QUERY,
    IM_SENSOR_CMD_PWRON,
    IM_SENSOR_CMD_CONFIG,
    IM_SENSOR_CMD_STREAM_ON,
    IM_SENSOR_CMD_STREAM_OFF,
    IM_SENSOR_CMD_PWROFF,
    IM_SENSOR_CMD_CTL,
    IM_SENSOR_CMD_DEBUG,
    IM_SENSOR_CMD_DETECT,
    IM_SENSOR_CMD_ENUMERATE2,
    IM_SENSOR_CMD_I2C_EXP_GET_VAL,
    IM_SENSOR_CMD_I2C_EXP_SET_VAL,
    IM_SENSOR_CMD_I2C_EXP_SET_DIR,
    IM_SENSOR_CMD_GET_MIPI_STATUS,
    IM_SENSOR_CMD_GET_CAMERA_PMIC_STATUS,
    IM_SENSOR_CMD_CTL_MAX,
    IM_SENSOR_CMD_CTL_FORCE32BITS          = 0x7FFFFFFF
}IMAGE_SENSOR_COMMAND;

/**
 * \brief Sub-commands supported by IM_SENSOR_CMD_ENUMERATE2 command
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum
{
    IM_SENSOR_CMD_ENUMERATE2_GET_COUNT = 0xFF,
} IM_SENSOR_CMD_ENUMERATE2_SUBCOMMAND;

/**
 *  \brief IOCTLS supported as part of IM_SENSOR_CMD_CTL command
 * \ingroup group_vision_function_imaging_sensordrv
 */

typedef enum
{
    IMAGE_SENSOR_CTRLCMD_GETEXPPRG = 0,
    IMAGE_SENSOR_CTRLCMD_GETWBCFG,
    IMAGE_SENSOR_CTRLCMD_SETEXPGAIN,
    IMAGE_SENSOR_CTRLCMD_GETEXPGAIN,
    IMAGE_SENSOR_CTRLCMD_SETWBGAIN,
    IMAGE_SENSOR_CTRLCMD_GETWBGAIN,
    IMAGE_SENSOR_CTRLCMD_DEBUG,
    IMAGE_SENSOR_CTRLCMD_READ_SENSOR_REG,
    IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_REG,
    IMAGE_SENSOR_CTRLCMD_WRITE_SENSOR_NREGS,
    IMAGE_SENSOR_CTRLCMD_READ_SENSOR_NREGS,
    IMAGE_SENSOR_CTRLCMD_SETFPS,
    IMAGE_SENSOR_CTRLCMD_READ_EEPROM,
    IMAGE_SENSOR_CTRLCMD_MAX,
    IMAGE_SENSOR_CTRLCMD_FORCE32BITS          = 0x7FFFFFFF
}IMAGE_SENSOR_CTRLCMD;


#define IMAGE_SENSOR_REMOTE_SERVICE_NAME  "com.ti.image_sensor"
#define CMD_PARAM_SIZE 384

/* Maximum number of channels supported */
#define ISS_SENSORS_MAX_CHANNEL                 (8U)

/* Max characters in the sensor name */
#define ISS_SENSORS_MAX_NAME                    (32U)

/* Max number of registers for group write */
#define MAX_GROUP_REG_NUMBER			8

/* Supports Sensor's name */
#define SENSOR_SONY_IMX390_UB953_D3             "IMX390-UB953_D3"
#define SENSOR_ONSEMI_AR0233_UB953_MARS         "AR0233-UB953_MARS"
#define SENSOR_ONSEMI_AR0820_UB953_LI         "AR0820-UB953_LI"
#define UB9XX_RAW_TESTPAT                     "UB9xxx_RAW12_TESTPATTERN"
#define UB96X_TESTPATTERN_UYVY                 "UB96x_UYVY_TESTPATTERN"
#define GW_AR0233_UYVY                          "GW_AR0233_UYVY"
#define SENSOR_OV2312_UB953_LI                  "OV2312-UB953_LI"
#define SENSOR_SAMSUNG_S5K2G1_UB971_TIDA        "UB9702_TESTPATTERN"
#define SENSOR_RDACM_OV10640_UB953              "OV10640-UB953_RDACM"
#define SENSOR_SONY_ISX016_UB913              "ISX016-UB913_SONY"
#define SENSOR_AR0147_MANDO                    "AR0147-MANDO"
#define SENSOR_AR0233_ONSEMI                    "AR0233-ONSEMI"
#define SENSOR_PAS_AS0149_MAX96701            "AS0149-MAX96701_PAS"

/*******************************************************************************
 *  Data structure's
 *******************************************************************************
 */

/**
 *  \brief Enum for Sensor Features
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum
{
    ISS_SENSOR_FEATURE_HFLIP                = 0x1,
    /**< Horizontal Flip feature */
    ISS_SENSOR_FEATURE_VFLIP                = 0x2,
    /**< Vertical Flip feature */
    ISS_SENSOR_FEATURE_EMBEDDED_DATA        = 0x4,
    /**< Embedded extra data in the frame feature */
    ISS_SENSOR_FEATURE_MANUAL_EXPOSURE      = 0x8,
    /**< Support for Manual Exposure */
    ISS_SENSOR_FEATURE_MANUAL_GAIN          = 0x10,
    /**< Support for Manual Gain */
    ISS_SENSOR_FEATURE_LINEAR_MODE          = 0x20,
    /**< Support for Linear Mode output */
    ISS_SENSOR_FEATURE_COMB_COMP_WDR_MODE    = 0x40,
    /**< Support for Combined Compressed WDR Mode */
    ISS_SENSOR_FEATURE_TWO_FRAME_WDR_MODE    = 0x80,
    /**< Support for Two Pass WDR Mode */
    ISS_SENSOR_FEATURE_DCC_SUPPORTED        = 0x100,
    /**< DCC Feature */
    ISS_SENSOR_FEATURE_CFG_UC1               = 0x200,
    /**< Advanced sensor configuration for custom usecases.*/
    ISS_SENSOR_FEATURE_CFG_UC2               = 0x400,
    /**< Advanced sensor configuration for custom usecases.*/
    ISS_SENSOR_MAX_FEATURES                 = 0x800,
    /**< Allow driver to update sensors/cameras FW */
    ISS_SENSOR_FEATURE_FW_UPDATE            = 0x1000,
    /**< Allow driver to disable external frame sync */
    ISS_SENSOR_FEATURE_DISABLE_FSYNC        = 0x2000,
    /**< Max Features */
    ISS_SENSOR_FEATURE_FORCE32BITS          = 0x7FFFFFFF
    /**< Last enum to make it int32 */
} IssSensor_Features;


/**
 *  \brief Enum for different sensor exposures in WDR sensor
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum
{
    ISS_SENSOR_EXPOSURE_LONG,
    /**< Long Exposure output from sensor */
    ISS_SENSOR_EXPOSURE_SHORT,
    /**< Short Exposure output from sensor */
    ISS_SENSOR_EXPOSURE_VSHORT,
    /**< Very short Exposure output from sensor */
    ISS_SENSOR_MAX_EXPOSURE,
    ISS_SENSOR_EXPOSURE_FORCE32BITS = 0x7FFFFFFF
} IssSensor_Exposures;

/**
 *  \brief Enum for different sensor <-> serializer MIPI errors
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum
{
    ISS_SENSOR_MIPI_OK          = 0x0,
    ISS_SENSOR_MIPI_1ECC        = 0x1,
    ISS_SENSOR_MIPI_2ECC        = 0x2,
    ISS_SENSOR_MIPI_CHECKSUM    = 0x4,
    ISS_SENSOR_MIPI_MAX,
    ISS_SENSOR_MIPI_FORCE32BITS = 0x7FFFFFFF
} IssSensor_MipiStatus;

/**
 *  \brief Enum for camera PMIC errors (ox03c Stellantis specific)
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum
{
    ISS_SENSOR_PMIC_OK          = 0x0,
    ISS_SENSOR_PMIC_ERR_I2C     = 0x1,
    ISS_SENSOR_PMIC_ERR_ID      = 0x2,
    ISS_SENSOR_PMIC_ERR_BUCK1   = 0x4,
    ISS_SENSOR_PMIC_ERR_BUCK2   = 0x8,
    ISS_SENSOR_PMIC_ERR_BUCK3   = 0x10,
    ISS_SENSOR_PMIC_ERR_LDO     = 0x20,
    ISS_SENSOR_PMIC_ERR_DEV     = 0x40,
    ISS_SENSOR_PMIC_MAX,
    ISS_SENSOR_PMIC_FORCE32BITS = 0x7FFFFFFF
} IssSensor_CameraPmicStatus;

/**
 *  \brief AEWB Algorithm Mode
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum {
    ALGORITHMS_ISS_AEWB_MODE_AWB        = 0,
    /**< Auto White Balance Mode only */
    ALGORITHMS_ISS_AEWB_MODE_AE         = 1,
    /**< Auto Exposure Mode only */
    ALGORITHMS_ISS_AEWB_MODE_AEWB       = 2,
    /**< Auto Exposure and Auto White Balance Mode */
    ALGORITHMS_ISS_AEWB_MODE_NONE       = 3,
    /**< None of AEWB Mode,
         Used when DCC Functionality is required, but not AEWB
         Also used when AEWB is dynamically enabled/disabled using DCC */
    ALGORITHMS_ISS_AEWB_MODE_MAX        = 4,
    /**< Max mode value, used for error checking */
    ALGORITHMS_ISS_AEWB_MODE_FORCE32BITS = 0x7FFFFFFF
    /**< This should be the last value after the max enumeration value.
     *   This is to make sure enum size defaults to 32 bits always regardless
     *   of compiler.
     */
} AlgItt_IssAewbMode;

/**
 *  \brief AE Algorithm SubModes
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum {
    /**< Auto Exposure */
    ALGORITHMS_ISS_AE_AUTO        = 0,
    /**< Manual Exposure */
    ALGORITHMS_ISS_AE_MANUAL        = 1,
    /**< Exposure Control Disabled*/
    ALGORITHMS_ISS_AE_DISABLED        = 2
} AlgItt_IssAeMode;

/**
 *  \brief AWB Algorithm SubModes
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef enum {
    /**< Auto WhiteBalance */
    ALGORITHMS_ISS_AWB_AUTO        = 0,
    /**< Manual Exposure */
    ALGORITHMS_ISS_AWB_MANUAL      = 1,
    /**< Exposure Control Disabled*/
    ALGORITHMS_ISS_AWB_DISABLED    = 2
} AlgItt_IssAwbMode;


/**
 *  \brief For Line Interleaved WDR mode, this structure is used
 *         for specifying position of each exposure frame.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint32_t totalWidth, totalHeight;
    /**< Total Frame size */
    struct {
        uint32_t startx, starty;
        /**< Start position of the exposure frame */
        uint32_t width, height;
        /**< frame size of the exposure frame */
    } info[ISS_SENSOR_MAX_EXPOSURE];
} IssSensor_LineInterleavedExpFrmInfo;

/**
 *  \brief Register address and value pair, with delay.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint16_t nRegAddr;
    /**< Register Address */
    uint16_t nRegValue;
    /**< Slave Address */
    uint32_t nDelay;
    /**< Delay to be applied, after the register is programmed */
} I2cParams;


/**
 *  \brief AutoExposure results data structure
 * \ingroup group_vision_function_imaging_sensordrv
 */

typedef struct
{
    uint32_t chId;
    /**< Channel Id */
    uint32_t expRatio;
    /**< Exposure ratio for WDR output format, not used for linear mode */
    uint32_t exposureTime[ISS_SENSOR_MAX_EXPOSURE];
    /**< Exposure time in ms for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
    uint32_t analogGain[ISS_SENSOR_MAX_EXPOSURE];
    /**< Exposure time in ms for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
} IssSensor_ExposureParams;


/**
 *  \brief AutoWhiteBalance results data structure
 * \ingroup group_vision_function_imaging_sensordrv
 */

typedef struct
{
    uint32_t chId;
    /**< Channel Id */
    uint32_t rGain[ISS_SENSOR_MAX_EXPOSURE];
    /**< Red Gain for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
    uint32_t gGain[ISS_SENSOR_MAX_EXPOSURE];
    /**< Green Gain for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
    uint32_t bGain[ISS_SENSOR_MAX_EXPOSURE];
    /**< Blue Gain for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
    uint32_t colorTemp[ISS_SENSOR_MAX_EXPOSURE];
    /**< Color Temperature estimation for all exposure outputs,
         For Linear mode output, only Long exposure entry is used */
}IssSensor_WhiteBalanceParams;


/**
 *  \brief Structure for setting DCC params
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint32_t chId;
    /**< Channel Id */
    uint8_t *pDccCfg;
    /**< Pointer to DCC config */
    uint32_t dccCfgSize;
    /**< DCC Profile Size */
} IssSensor_DccParams;


/*
 *  \brief Sensor Information structure
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    tivx_raw_image_create_params_t        raw_params;
    /**< raw parameters of the sensor  */
    uint32_t                              features;
    /**< Bitwise list of feature supported by the sensor */
    uint32_t                              aewbMode;
    /**< AEWB mode */
    uint32_t                          fps;
    /**< frame rate */
    uint32_t numDataLanes;
    /**< Number of CSIRX data lanes */
    uint32_t dataLanesMap[4];
    /**< Data Lanes map array */
    uint32_t dataLanesPolarity[4];
    /**< Data Lanes map array */
    uint32_t csi_ddr_clock;      /*!<  */
    /**< CSI clock  */
    uint8_t otp_id[ISS_SENSORS_MAX_CHANNEL][6];
    /**< OTP ID */
    uint32_t bppBypass;
    /**< Enable CSI-2 data filter bypass */
} IssSensor_Info;


/*
 *  \brief Create Time parameters, ISS sensor layer uses these
 *         parameters and configures board module and sensor.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    char                            name[ISS_SENSORS_MAX_NAME];
    /**< Name of the sensor */
    uint16_t                              i2cInstId[2];
    /**< I2C Instance id for the sensor */
    uint8_t                               i2cAddrSensor[ISS_SENSORS_MAX_CHANNEL];
    /**< I2C Address of the sensor */
    uint8_t                               i2cAddrSer[ISS_SENSORS_MAX_CHANNEL];
    /**< I2C Address of the serializer */
    IssSensor_Info                    sensorInfo;
    /**< Sensor Information e.g. width, height, format etc.*/
    uint32_t                          num_channels;
    /**< Number of channels supported */
    uint32_t                           dccId;
    /**< camera identifier  */
} IssSensor_CreateParams;

/*******************************************************************************
 *  Defines
 *******************************************************************************
 */
#define ISS_SENSORS_MAX_SUPPORTED_SENSOR               (24U)


/*******************************************************************************
 *  Data Structures
 *******************************************************************************
 */

/*
 *  \brief CSI-2 COmplex I/O Lane Configuration
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint8_t pol;
    /**< TRUE configures for - / + order of differential signal.
        + / - order otherwise */
    uint8_t position;
    /**< Specify if this lane is to be used, if so, on which position.
        0x0 - Not used / disabled lane
        0x1 - Position 1
        0x2 - Position 2
        0x3 - Position 3
        0x4 - Position 4
        0x5 - Position 5 */
} IssCapture_CmplxIoLaneCfg;


/*  \brief Structure used for describing sensor interfacing.
 *
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint8_t                                isMultiChannel;
    /**< Flag for single/multi channel sensor config */
    uint8_t                               numCSI2Lanes;
    /**< num lanes for CSI*/
    uint32_t                              inCsi2VirtualChanNum;
    /**< CSI2 Virtual Channel Num, must be between 0 to 3 */
    uint8_t                                  isCmplxIoCfgValid;
    /**< Is Complex IO config valid*/
    IssCapture_CmplxIoLaneCfg                 complxIoLaneCfg[5];
    /**< CSI2 lane and polarity config*/
    uint32_t                                 csi2PhyClk;
    /**< Clock provided to CSI2 Phy by the SoC */
    uint8_t                                sensorBroadcast;
    /**< Enable/Disable sensor broadcast */
    uint8_t                                enableFsin;
    /**< Enable/Disable sensor Frame Sync Input (FSIN) */
} IssSensorIntfParams;


/*  \brief Structure used for specifying register configurations of sensor, serializer and deserializer.
 *
 *  desCfgPreScript : Deserializer config script pre-sensor initialization
 *  serCfgPreScript : Serializer config script pre-sensor initialization
 *  sensorCfgPreScript : Sensor config script without starting streaming 
 *  desCfgPostScript : Deserializer script post-sensor initialization
 *  serCfgPostScript : Serializer config script post-sensor initialization
 *  sensorCfgPostScript : Sensor config script after starting streaming
 *
 *
 * Each script is an array of type I2CParams
 * The scripts maybe of variable lengths. Scripts can also be NULL is the config is not needed.
 *
 * Last entry in serailizer and deserializer config script must be {0xFFFF, 0x00, 0x00}
 *
 *
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    I2cParams    * desCfgPreScript;
    I2cParams    * serCfgPreScript;
    I2cParams    * sensorCfgPreScript;
    I2cParams    * desCfgPostScript;
    I2cParams    * serCfgPostScript;
    I2cParams    * sensorCfgPostScript;
} IssSensorConfig;

/**
 *  \brief Min/Max Range, used in AWB calibration data
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct {
    uint32_t min;
    /**< Min Value */
    uint32_t max;
    /**< Max Value */
} IssAeRange;


/**
 *  \brief Maximum number of dynamic parameter configuration 
 *  supported for Auto Exposure Algorithm tuning
 * \ingroup group_vision_function_imaging_sensordrv
 */

#define MAX_AE_DYN_PARAMS       (10U)

/**
 *  \brief Sensor Specific Auto Exposure Dynamic Parameters
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct {
    IssAeRange exposureTimeRange[MAX_AE_DYN_PARAMS];
    /**< range of exposure time in nanoseconds */
    IssAeRange analogGainRange[MAX_AE_DYN_PARAMS];
    /**< range of sensor gain, 1024 = 1x */
    IssAeRange digitalGainRange[MAX_AE_DYN_PARAMS];
    /**< range of ISP Digital gain, 256 = 1x */
    uint32_t                     numAeDynParams;
    /**< Number of Valid Entries in above arrays */
    IssAeRange targetBrightnessRange;
    /**< range of target brightness */
    uint32_t                     targetBrightness;
    /**< target brightness value */
    uint32_t                     threshold;
    /**< threshold for not using history brightness information */
    uint32_t                     exposureTimeStepSize;
    /**< step size of exposure time adjustment */
    uint32_t                     enableBlc;
    /**< TRUE enables Backlight compensation, disabled otherwise */
} IssAeDynamicParams;


/**
 *  \brief Sensor Specific Auto WhiteBalance Dynamic Parameters
 * \ingroup group_vision_function_imaging_sensordrv
 */

typedef struct {
    IssAeRange redGainRange;
    IssAeRange blueGainRange;
    IssAeRange greenGainRange;
    uint32_t   sensor_pre_gain;
    /**< Non-Zero enables applying WB gains in Sensor PreHDR Merge. In ISP otherwise */
} IssAwbDynamicParams;

/**
 *  \brief Callback for sensor probe. Detection of sensor HW using chip ID register
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_ProbeFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for sensor & SerDes configuration.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_ConfigFxn) (uint32_t chId, void *pSensorHdl, uint32_t sensor_features_requested);

/**
 *  \brief Callback for starting streaming.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_StreamOnFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for stopping streaming.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_StreamOffFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for powering ON the sensor and/or configuring the deserialser
 *  so that the sensor is visible to the SoC.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_PowerOnFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for powering OFF the sensor, if applicable.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_PowerOffFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for setting sensor exposure and gain.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_SetAeParamsFxn) (void *pSensorHdl, uint32_t chId, IssSensor_ExposureParams *pExpPrms);

/**
 *  \brief Callback for getting DCC parameters. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_GetDccParamsFxn) (uint32_t chId, void *pSensorHdl, IssSensor_DccParams *pDccPrms);

/**
 *  \brief Callback for getting current exposure settings. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_GetExpParamsFxn) (uint32_t chId, void *pSensorHdl, IssSensor_ExposureParams *pExpPrms);

/**
 *  \brief Callback for setting AEWB specific sensor settings, if applicable. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef void (*IssSensor_InitAewbConfigFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for getting ISP settings specific to the sensor, if applicable. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef void (*IssSensor_GetIspConfigFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for de-initializing the sensor, if applicable. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef void (*IssSensor_DeinitFxn) (uint32_t chId, void *pSensorHdl);

/**
 *  \brief Callback for reading/writing sensor registers from the application. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*I2cRegReadWriteFxn) (uint32_t chId, void *pSensorHdl, uint32_t readWriteFlag, I2cParams *pReg);

/**
 *  \brief Callback for writing sensor registers group from the application. Reserved for future use.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*I2cRegGroupWriteFxn) (uint32_t chId, void *pSensorHdl, uint32_t readWriteFlag, I2cParams *pReg, uint32_t reg_number);

/**
 *  \brief Callback for getting sensor's exposure constraints. Needed for AutoExposure tuning.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_GetExpPrgFxn) (uint32_t chId, void *pSensorHdl, IssAeDynamicParams *p_ae_dynPrms);

/**
 *  \brief Callback for getting sensor's WB constraints. Needed for AutoWhiteBalance tuning.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_GetWbConfigFxn) (uint32_t chId, void *pSensorHdl, IssAwbDynamicParams *p_awb_dynPrms);


/**
 *  \brief Callback for setting WB gains in the sensor.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef int32_t (*IssSensor_SetAwbParamsFxn) (void *pSensorHdl, uint32_t chId, IssSensor_WhiteBalanceParams *pWbPrms);

/**
 *  \brief Structure containins sensor information, used for
 *         registering it to the sensor framework.
 * \ingroup group_vision_function_imaging_sensordrv
 */
struct IssSensorFxns_t {
    IssSensor_ProbeFxn               probe;
    IssSensor_ConfigFxn              config;
    IssSensor_StreamOnFxn            streamOn;
    IssSensor_StreamOffFxn           streamOff;
    IssSensor_PowerOnFxn             powerOn;
    IssSensor_PowerOffFxn            powerOff;
    IssSensor_GetExpParamsFxn        getExpParams;
    IssSensor_SetAeParamsFxn         setAeParams;
    IssSensor_GetDccParamsFxn        getDccParams;
    IssSensor_InitAewbConfigFxn      initAewbConfig;
    IssSensor_GetIspConfigFxn        getIspConfig;
    I2cRegReadWriteFxn                readWriteReg;
    I2cRegGroupWriteFxn              groupWriteReg;
    IssSensor_GetExpPrgFxn           getExpPrg;
    IssSensor_DeinitFxn                deinit;
    IssSensor_GetWbConfigFxn         getWbCfg;
    IssSensor_SetAwbParamsFxn        setAwbParams;
};
/* Forward Declaration of Sensor Params */
typedef struct IssSensorFxns_t IssSensorFxns;

/**
 *  \brief Handle to the sensor driver. Includes all the information about the sensor.
 * \ingroup group_vision_function_imaging_sensordrv
 */
typedef struct
{
    uint32_t                      isUsed;
    /**< Flag to indicate if given instance is free or not */
    IssSensor_CreateParams      * createPrms;
    /**< Create Parameters */
    IssSensorFxns          * sensorFxns;
    /**< Registered Sensor's parameters */
    IssSensorIntfParams      *    sensorIntfPrms;
    /**< Registered Sensor's interface parameters */
} IssSensors_Handle;


/*******************************************************************************
 *  Functions Declarations
 *******************************************************************************
 * \ingroup group_vision_function_imaging_sensordrv
 */


 /**
 *******************************************************************************
 *
 * \brief Function to initialize sensor driver framework.
 * Registers with remote service.
 * Includes init function of supported sensor drivers. This
 * step is critical for registring a sensor driver with the framework
 * @param registeredSensorNames OUT Names of all the registered sensors
 * \return 0 in case of success
 *         error otherwise
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
 */

int32_t IssSensor_EarlyInit();
int32_t IssSensor_Init();

int32_t ImageSensor_RemoteServiceHandler(char *service_name, uint32_t cmd, void *prm, uint32_t prm_size, uint32_t flags);

 /**
 *******************************************************************************
 *
 * \brief Function to de-initialize sensor driver framework.
 * Unregisters remote service.
 * \return 0 in case of success
 *         error otherwise
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
 */

int32_t IssSensor_DeInit();

/**
 *******************************************************************************
 *
 * \brief Creates the sensor, based on the create params, it
 *        searches for the given sensor in the registered sensors,
 *        configures the board module if sensor supports board
 *        module and creates sensor fvid2 driver.
 *        It also configures sensor in the given WDR mode and also sets
 *        the default output resolution in the sensor.
 *
 * @param pCreatePrms       Pointer to the create params
 *
 * \return handle to the created sensor
 *         NULL if there is any error
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
*/
void* IssSensor_Create(char * name);

/**
 *******************************************************************************
 *
 * \brief Used for sending control commands, this layer
 *        supports all configuration using control commants.
 *        For the list of supported control command, see defines
 *        section of this file.
 *
 *        Must be called after Create function
 *
 * @param handle             Handle to the created sensor
 * @param cmd                Control command
 * @param cmdArgs            Pointer to the command specific arguments.
 * @param cmdRetArgs       [OUT] Pointer to the command specific return arguments
 *
 * \return 0 in case of success
 *         error otherwise
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
*/
int32_t IssSensor_Control(void* handle, vx_uint32 cmd, void* cmdArgs,
    uint32_t cmdArgsSize, void* cmdRetArgs);

/**
 *******************************************************************************
 *
 * \brief Function to configure UB953 serializer
 *
 * @param i2cInstId              I2C bus on which the serializer is populated
 * @param i2cAddr                7-bit I2C address, usually alias address as configured in UB960
 * @param script                 Array of type I2CParams with last entry being {0xFFFF, 0x00, 0x00}
 * \return 0 in case of success
 *         error otherwise
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
*/
int32_t ub953_cfgScript(uint8_t  i2cInstId, uint8_t  i2cAddr, I2cParams *script);

/**
 *******************************************************************************
 *
 * \brief Function to map UB960 Instance to channel number 
 * On Fusion board the mapping is as follows
 *  Camera Channel	0 - UB960 Instance 0
 *  Camera Channel	1 - UB960 Instance 0	 
 *  Camera Channel	2 - UB960 Instance 0	 
 *  Camera Channel	3 - UB960 Instance 0	 
 *  Camera Channel	4 - UB960 Instance 1	 
 *  Camera Channel	5 - UB960 Instance 1	 
 *  Camera Channel	6 - UB960 Instance 1	 
 *  Camera Channel	7 - UB960 Instance 1	 
 *
 *
 *  On customer boards, this mapping maybe redefined
 *
 * @param chId              Channel ID of the camera to be configured
 * \return 0 if success
 *         -1 otherwise
 *
 * \ingroup group_vision_function_imaging_sensordrv
 *******************************************************************************
*/
int8_t getUB960InstIdFromChId(uint32_t chId);

int32_t initFusion2_UB97x();
int32_t deInitFusion2_UB97x();

uint8_t getStreamStatus(uint32_t chId);
//float getThermalStatus(uint32_t chId);
uint8_t getPortSts1Reg(uint32_t chId);
int8_t getCamStsReg(uint32_t chId);
uint8_t getPortSts2Reg(uint32_t chId);
#if 0
uint8_t getCamFaultASts(uint32_t chId);
#endif
/*Image frozen check*/
//void GetImgSensorFrameCounter(uint32_t chID, uint32_t *FrameCounter);
uint16_t getCsiFrameCount(void);
uint16_t getCsiFrameCountWithError(void);


#endif /* End of ISS_SENSORS_H_*/

