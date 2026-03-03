#ifndef CALDATAPROVIDER_DEFS_INCLUDEGUARD
#define CALDATAPROVIDER_DEFS_INCLUDEGUARD

//Need to fix this the right way
#ifndef MAGNA_PLATFORMDATATYPES_bool_t_DEFINED
typedef uint8_t bool_t;
#endif

#if defined(BUILD_MCU1_0)
#include "Rte_Type.h"
#endif
#if defined(BUILD_MCU2_0) || defined(BUILD_MCU2_1) || defined(BUILD_MCUQNX)
#include "ME_CalibSVS.h"
#include "HMI_SVS.h"
#include "THA_SM_VC_Inputs_Outputs.h"
#include "THA_Detection_Inputs_Outputs.h"
#include "FOD_Input_Output.h"
#include "LMD_Input_Output.h"
#include "TRSC_Inputs_Outputs.h"
#include "AutoPark_Input_Output.h"
#endif
/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

typedef struct
{
    uint32_t FreshnessCount;
    TbSVS_S_SVSCamCurrentCalibData_t CalData_SVSCamCurrentCalibData;
    TbSVS_S_SVSCamEOLCalibData_t CalData_SVSCamEOLCalibData;
    TbSVS_S_SVSCamOCCalibData_t CalData_SVSCamOCCalibData;
    TbSVS_S_SVSCamSCCalibData_t CalData_SVSCamSCCalibData;
    bool_t bValid;
}CalDataProvider_MPU_1_0_Def;

#ifndef BUILD_MCU1_0
typedef struct
{
    uint32_t FreshnessCount;
    TbSVS_S_SVSCamCurrentCalibData_t CalData_SVSCamCurrentCalibData;
    TbSVS_S_SVSCamEOLCalibData_t CalData_SVSCamEOLCalibData;
    TbSVS_S_SVSCamOCCalibData_t CalData_SVSCamOCCalibData;
    TbSVS_S_SVSCamSCCalibData_t CalData_SVSCamSCCalibData;
    bool_t bValid;
}CalDataProvider_MCU_1_0_Def;
#endif

typedef struct
{
    uint32_t FreshnessCount;
    TbSVS_S_SVSCamCurrentCalibData_t CalData_SVSCamCurrentCalibData;
    TbSVS_S_SVSCamEOLCalibData_t CalData_SVSCamEOLCalibData;
    TbSVS_S_SVSCamOCCalibData_t CalData_SVSCamOCCalibData;
    TbSVS_S_SVSCamSCCalibData_t CalData_SVSCamSCCalibData;
    bool_t bValid;
}CalDataProvider_MCU_2_0_Def;

typedef struct
{
    uint32_t FreshnessCount;
    TbSVS_S_SVSCamCurrentCalibData_t CalData_SVSCamCurrentCalibData;
    TbSVS_S_SVSCamEOLCalibData_t CalData_SVSCamEOLCalibData;
    TbSVS_S_SVSCamOCCalibData_t CalData_SVSCamOCCalibData;
    TbSVS_S_SVSCamSCCalibData_t CalData_SVSCamSCCalibData;
    bool_t bValid;
}CalDataProvider_MCU_2_1_Def;

/* Feature Calibration IPC Structures */
typedef struct THA_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    TbTHASmVc_VrntTunParam_t CalData1;      //MCU2_1
    THADet_Inputs_from_CalData_t CalData2;  //A72
    uint32_t rsvd;
    uint32_t checksum;
    uint32_t magic_str_end;
}THA_Calibration_data_t;

typedef struct THA_Calibration_MCU2_1_s
{
    uint32_t CalData_Version;
    TbTHASmVc_VrntTunParam_t CalData;//MCU2_1
    bool_t bValid;
}THA_Calibration_data_MCU2_1_t;

typedef struct THA_Calibration_MPU1_0_s
{
    uint32_t CalData_Version;
    THADet_Inputs_from_CalData_t CalData;//A72
    bool_t bValid;
}THA_Calibration_data_MPU1_0_t;

typedef struct TRSC_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    TbTRSCSmVc_TunParam_t CalData1;//MCU2_0
    TRSC_Tunable_Param_t CalData2;//A72
    uint32_t reserved[78];
    uint32_t checksum;
    uint32_t magic_str_end;
}TRSC_Calibration_data_t;
typedef struct TRSC_Calibration_MCU2_1_s
{
    uint32_t CalData_Version;
    TbTRSCSmVc_TunParam_t CalData;//MCU2_0
    bool_t bValid;
}TRSC_Calibration_data_MCU2_1_t;

typedef struct TRSC_Calibration_MPU1_0_s
{
    uint32_t CalData_Version;
    TRSC_Tunable_Param_t CalData;//A72
    bool_t bValid;
}TRSC_Calibration_data_MPU1_0_t;

typedef struct APA_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    TbAP_VrntTunParam_t CalData1;//MCU2_1
    TbAPFPA_AlgoTunParam_t CalData2;//MCU2_1
    TbAPPLD_AlgoTunParam_t CalData3;//A72
    TbAPUSSOM_AlgoTunParam_t CalData4;//MCU2_1
    TbAPNFCD_VrntTunParam_t CalData5;//MCU2_1
    uint32_t rsvd;
    uint32_t checksum;
    uint32_t magic_str_end;
}APA_Calibration_data_t;

typedef struct APA_Calibration_MPU1_0_s
{
    uint32_t CalData_Version;
    TbAPPLD_AlgoTunParam_t CalData;
    bool_t bValid;
}APA_Calibration_data_MPU1_0_t;

typedef struct APA_Calibration_MCU2_1_s
{
    uint32_t CalData_Version;
    TbAP_VrntTunParam_t CalData1;
    TbAPFPA_AlgoTunParam_t CalData2;
    TbAPUSSOM_AlgoTunParam_t CalData3;
    TbAPNFCD_VrntTunParam_t CalData4;
    bool_t bValid;
}APA_Calibration_data_MCU2_1_t;

typedef struct SVS_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    uint32_t CalData[251];
    uint32_t rsvd;
    uint32_t checksum;
    uint32_t magic_str_end;
    bool_t bValid;
}SVS_Calibration_data_t;

typedef struct FOD_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    ITbFOD_VrntTunParam_s CalData;
    uint32_t rsvd[119];
    uint32_t checksum;
    uint32_t magic_str_end;
    bool_t bValid;
}FOD_Calibration_data_t;

typedef struct LMD_Calibration_s
{
    uint32_t magic_str_start;
    uint32_t CalData_Version;
    ITbLMD_VrntTunParam_t CalData;
    uint32_t rsvd[94];
    uint32_t checksum;
    uint32_t magic_str_end;
    bool_t bValid;
}LMD_Calibration_data_t;

typedef struct USS_Calibration_s
{
    uint32_t uss_caldata_start;
    uint32_t CalData[15000];
    bool_t bValid;
    uint8_t rsvd[3];
    uint32_t uss_caldata_end;
}USS_Calibration_Data_t;
typedef struct USS_Calibration_2_s
{
    uint32_t uss_caldata_start;
    uint32_t CalData[2700];
    uint32_t uss_caldata_end;
}USS_Calibration_data_2_t;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */


#endif

