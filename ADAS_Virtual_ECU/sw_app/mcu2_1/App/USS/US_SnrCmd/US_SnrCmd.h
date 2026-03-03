/*
 * US_SnrCmd.h
 *
 *  Created on: Apr 6, 2021
 *      Author: jonapais
 */

#ifndef US_SNRPROC_H_
#define US_SNRPROC_H_

#include "US_Data_Typedefs_Global.h"
#include "US_SnrData_Typedefs_Global.h"
#include "US_ME_Typedefs_Global.h"
#include "US_Ctrl_Global.h"

/*
 * US_SnrCmd LOCAL FUNCTION PROTOTYPES
 */
void UssSnrCmd_SetBurstCmdDone(bool_t _bBurstCmdDone);
void UssSnrCmd_StartSnrMeasTimer(void);

void UssSnrCmd_CmdCallback_SendBurst(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData);
void UssSnrCmd_CmdCallback_SnrTempCmd(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData);
void UssSnrCmd_CmdCallback_DiagResultCmd(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData);
void UssSnrCmd_ReqFreqCmdCallback(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData);

void UssSnrCmd_CmdCallback_NotImplemented(uint32_t uErrorCode, uint32_t uCmd, uint32_t uUserData, uint16_t uRcvSize, uint8_t *puRcvData);

uint32_t UssSnrCmd_uGetSendingSensors(void);
US_E_ProfileType_t UssSnrCmd_uGetRcvProfiles(uint8_t uBusNum);
US_E_SendType_t * peGetReqEchoType(void);
US_E_SendType_t * peGetMeasEchoType(void);
US_S_ClusterBurstCmd_t * psGetSendBurstCfg(void);
uint8_t * UssSnrCmd_puGetSpiBurstDataBuff(void);

/*
 * US_SnrCmd LOCAL DATA
 */
#define US_D_SPI_BURST_DATA_BUFF_SIZE (2000u)
#define US_D_CMD_RESP_DATA_BUFF_SIZE (2000u)
#define US_D_SENSORS_FREQ_DATA_BUFF_SIZE (96u)
#define US_D_SENSORS_FREQ_DATA_PWD      (0xA1B2u)

#define US_D_CMD_DATA_GAP   (0xFFu)

/*
 * TYPES FOR PARSING SPI BUFFER DATA
 */

// Echo Type 1
struct US_S_Sensor_Diag_s
{
    uint8_t EvRing_H;
    uint8_t EvRing_L;
    uint8_t DrvFreq_572;    // need to multiply 572
    uint8_t RingFreq_572;   // need to multiply 572
};

// Echo Type 2
struct US_S_Snr_Meas_EchoType2_s
{
    uint8_t Dist_H;
    uint8_t Dist_L;
    uint8_t EchoHeight;
    uint8_t EchoWidth;
};

// Echo Types 3,4,5
struct US_S_Snr_Meas_EchoType345_s
{
    uint8_t Dist_H;
    uint8_t Dist_L;
    uint8_t EchoHeight;
    uint8_t Width_conf;
};

struct US_S_Snr_Meas_NoiseInfo_s
{
    uint8_t uSum_H : 4;
    uint8_t uCount : 4;
    uint8_t uSum_L;
    uint8_t uEchoHeight;
    uint8_t uATG;
};

typedef struct US_S_Sensor_Echo_s
{
    uint8_t uSnrIdx;     // Index of sensor
    uint8_t uEchoIdx;    // Index of Echo

    union US_S_Snr_Meas_Type_Union
    {
        uint8_t uEchoType;      // echo type, see US_E_EchoType_t
        uint8_t DiagStatus;     // Diag status
    } t;

    union US_S_Snr_Meas_Union
    {
        struct US_S_Sensor_Diag_s             diag;
        struct US_S_Snr_Meas_EchoType2_s      fixed;
        struct US_S_Snr_Meas_EchoType345_s    filter;
        struct US_S_Snr_Meas_NoiseInfo_s      noise;
    } d;
} US_S_Sensor_Echo_t;

typedef struct US_S_Snr_Temperature_Fmt_s
{
    uint8_t uSnrIdx;
    uint8_t uTemperatureByteH;
    uint8_t uTemperatureByteL;
} US_S_Snr_Temperature_Fmt_t;

typedef struct US_S_Snr_Diagnostics_F11A_Fmt_s
{
    uint8_t uSnrIdx;
    uint8_t uHardwareDiagFlags_H;
    uint8_t uHardwareDiagFlags_L;
    uint8_t uMeasDiagFlags_H;
    uint8_t uMeasDiagFlags_L;
    uint8_t uCommDiagFlags_H;
    uint8_t uCommDiagFlags_L;
} US_S_Snr_Diagnostics_F11A_Fmt_t;

typedef struct US_S_Snr_Diagnostics_ASIL_Fmt_s
{
    uint8_t uSnrIdx;               // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uHardwareDiagFlags_H;  // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uHardwareDiagFlags_L;  // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uMeasDiagFlags_H;      // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uMeasDiagFlags_L;      // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uCommDiagFlags_H;      // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uCommDiagFlags_L;      // Same as US_S_Snr_Diagnostics_F11A_Fmt_t
    uint8_t uAsilDiagFlags_H;      // Added for ASIL
    uint8_t uAsilDiagFlags_L;      // Added for ASIL
    uint8_t uTemperatureByteH;     // Added for ASIL
    uint8_t uTemperatureByteL;     // Added for ASIL
} US_S_Snr_Diagnostics_ASIL_Fmt_t;

#endif /* US_SNRPROC_H_ */
