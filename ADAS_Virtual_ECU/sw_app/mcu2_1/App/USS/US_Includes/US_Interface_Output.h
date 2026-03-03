/*
 * USS inteface output data structure.h
 *
 *  Created on: Nov 16, 2021
 *      Author: e39960
 */

#ifndef US_INTERFACE_OUTPUT_H_
#define US_INTERFACE_OUTPUT_H_

/*******************************************************************/
/*                                                                 */
/*        Components Data structure                               */
/*                                                                 */
/*******************************************************************/
/*
 * Zone info List
 */
#if !defined(BUILD_MCU1_0)
typedef enum US_E_ZoneInfo_list_e
{
    US_ZONE_OFF = 0,
    US_ZONE_1 ,
    US_ZONE_2 ,
    US_ZONE_3 ,
    US_ZONE_4 ,
    US_ZONE_5_NOT_USED ,
    US_ZONE_6_NOT_USED ,
    US_ZONE_7_NOT_USED ,
    US_ZONE_8_NOT_USED ,
    US_ZONE_NO_OBSTACLE ,
    US_ZONE_10_NOT_USED,
    US_ZONE_11_NOT_USED,
    US_ZONE_RESERVED_12,    // Not used.
    US_ZONE_RESERVED_13,    // Not used.
    US_ZONE_RESERVED_15, // Not used. 
    US_ZONE_UNSED             // Not used.
} US_E_Zoneinfo_list_t;

/*
 * Sector List
 */
typedef enum US_E_Sector_list_e
{
    US_FRONT_SECTOR_1          = 0,
    US_FRONT_SECTOR_0          = 1,
    US_SIDE_LEFT_SECTOR_0      = 2,
    US_SIDE_LEFT_SECTOR_1      = 3,
    US_SIDE_LEFT_SECTOR_2      = 4,
    US_SIDE_LEFT_SECTOR_3      = 5,
	US_REAR_SECTOR_0           = 6,
	US_REAR_SECTOR_1           = 7,
	US_REAR_SECTOR_2           = 8,
	US_REAR_SECTOR_3           = 9,
    US_SIDE_RIGHT_SECTOR_3     = 10,
    US_SIDE_RIGHT_SECTOR_2     = 11,
    US_SIDE_RIGHT_SECTOR_1     = 12,
    US_SIDE_RIGHT_SECTOR_0     = 13,
    US_FRONT_SECTOR_3          = 14,
    US_FRONT_SECTOR_2          = 15,
 	US_MAX_SECTOR
 } US_E_Sector_list_t;

typedef struct USS_S_PntDebugData_s
{
          uint8_t uPntDebugData[64u];  // Raw bytes for CAN FD output.
} USS_S_PntDebugData_t;

typedef struct US_ME_Diag_1_s
{
   unsigned short Sig_Snr_EEPROM_Fail;
   unsigned short Sig_Snr_High_Voltage;
   unsigned short Sig_Snr_Low_Voltage;
   unsigned short Sig_Snr_RAM_Fail;
}US_ME_Diag_1_t;

typedef struct US_ME_Diag_2_s
{
   unsigned char Sig_Disturbance_Detected;
   unsigned char Sig_FW_Inconsistant_Snr;
   unsigned char Sig_ECU_Invalid_Calibration_Data;
   unsigned char Sig_ECU_Low_Voltage;
   unsigned char Sig_ECU_High_Voltage;
   unsigned char Sig_Comm_Snr_Error;
   unsigned short Sig_Snr_Transducer_Error;
   unsigned short Sig_Snr_Abnormal;
   unsigned short Sig_Snr_Blockage;
   unsigned short Sig_Snr_Disconnect;
   unsigned char reserved[2];
}US_ME_Diag_2_t;

typedef struct US_ME_FiringSensorsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t firingSensors;
	uint16_t rsv;
} US_ME_FiringSensorsOutputBuff_t;

typedef struct US_ME_SensorFiringModeOutputBuff_s
{
    uint32_t timestamp;
    uint8_t  sensorFiringMode;
	uint8_t  rsv[3];
} US_ME_SensorFiringModeOutputBuff_t;

typedef struct US_ME_SnsDat_Front_Direct_s
{
   unsigned short Sig_SnrDat_FSR_Dir1_cm;
   unsigned short Sig_SnrDat_FOR_Dir1_cm;
   unsigned short Sig_SnrDat_FIR_Dir1_cm;
   unsigned short Sig_SnrDat_FIL_Dir1_cm;
   unsigned short Sig_SnrDat_FOL_Dir1_cm;
   unsigned short Sig_SnrDat_FSL_Dir1_cm;
}US_ME_SnsDat_Front_Direct_t;

typedef struct US_ME_SnsDat_Front_Direct_2_s
{
   unsigned short Sig_SnrDat_FSR_Dir2_cm;
   unsigned short Sig_SnrDat_FOR_Dir2_cm;
   unsigned short Sig_SnrDat_FIR_Dir2_cm;
   unsigned short Sig_SnrDat_FIL_Dir2_cm;
   unsigned short Sig_SnrDat_FOL_Dir2_cm;
   unsigned short Sig_SnrDat_FSL_Dir2_cm;
}US_ME_SnsDat_Front_Direct_2_t;

typedef struct US_ME_SnsDat_FrontPSM_Echoes_s
{
   unsigned short Sig_SnsDat_FSL_Timestamp_us;
   unsigned short Sig_SnsDat_FSL_DirEcho1_cm;
   unsigned short Sig_SnsDat_FSL_DirEcho2_cm;
   unsigned short Sig_SnsDat_FSR_Timestamp_us;
   unsigned short Sig_SnsDat_FSR_DirEcho1_cm;
   unsigned short Sig_SnsDat_FSR_DirEcho2_cm;
}US_ME_SnsDat_FrontPSM_Echoes_t;

typedef struct US_ME_SnsDat_Rear_Direct_s
{
   unsigned short Sig_SnrDat_RSR_Dir1_cm;
   unsigned short Sig_SnrDat_ROR_Dir1_cm;
   unsigned short Sig_SnrDat_RIR_Dir1_cm;
   unsigned short Sig_SnrDat_RIL_Dir1_cm;
   unsigned short Sig_SnrDat_ROL_Dir1_cm;
   unsigned short Sig_SnrDat_RSL_Dir1_cm;
}US_ME_SnsDat_Rear_Direct_t;

typedef struct US_ME_SnsDat_Rear_Direct_2_s
{
   unsigned short Sig_SnrDat_RSR_Dir2_cm;
   unsigned short Sig_SnrDat_ROR_Dir2_cm;
   unsigned short Sig_SnrDat_RIR_Dir2_cm;
   unsigned short Sig_SnrDat_RIL_Dir2_cm;
   unsigned short Sig_SnrDat_ROL_Dir2_cm;
   unsigned short Sig_SnrDat_RSL_Dir2_cm;
}US_ME_SnsDat_Rear_Direct_2_t;

typedef struct US_ME_SnsDat_RearSide_Echoes_s
{
   unsigned short Sig_SnsDat_RSL_Timestamp_us;
   unsigned short Sig_SnsDat_RSL_DirEcho1_cm;
   unsigned short Sig_SnsDat_RSL_DirEcho2_cm;
   unsigned short Sig_SnsDat_RSR_Timestamp_us;
   unsigned short Sig_SnsDat_RSR_DirEcho1_cm;
   unsigned short Sig_SnsDat_RSR_DirEcho2_cm;
}US_ME_SnsDat_RearSide_Echoes_t;

typedef struct US_S_PointOutputBuff_s
{
    sint16_t x;
    sint16_t y;
    uint8_t  height;
    uint8_t  Cruising_Age;
    uint8_t  confidence;
    uint8_t  age;
} US_S_PointOutputBuff_t;

typedef struct US_S_PointsMapOutputBuff_s
{
    uint32_t timestamp;
    US_S_PointOutputBuff_t pointMap[96];
}US_S_PointMapOutputBuff_t;

typedef struct US_S_Firing_Sequence_s
{
	uint8_t Sig_Current_Firing_Sequence;
	uint8_t  rsv[3];
}US_S_Firing_Sequence_t;

typedef struct US_S_SnsDat_Front_Indirect_2_s
{
   unsigned short Sig_SnrDat_sFIL_Indir_FOL_cm;
   unsigned short Sig_SnrDat_sFOL_Indir_FIL_cm;
   unsigned short Sig_SnrDat_sFOL_Indir_FSL_cm;
   unsigned short Sig_SnrDat_sFSL_Indir_FOL_cm;
}US_S_SnsDat_Front_Indirect_2_t;

typedef struct US_S_SnsDat_Rear_Indirect_2_s
{
   unsigned short Sig_SnrDat_sRSR_Indir_ROR_cm;
   unsigned short Sig_SnrDat_sROR_Indir_RSR_cm;
   unsigned short Sig_SnrDat_sROR_Indir_RIR_cm;
   unsigned short Sig_SnrDat_sRIR_Indir_ROR_cm;
}US_S_SnsDat_Rear_Indirect_2_t;

typedef struct US_S_SnsDat_Front_Indirect_1_s
{
   unsigned short Sig_SnrDat_sFSR_Indir_FOR_cm;
   unsigned short Sig_SnrDat_sFOR_Indir_FSR_cm;
   unsigned short Sig_SnrDat_sFOR_Indir_FIR_cm;
   unsigned short Sig_SnrDat_sFIR_Indir_FOR_cm;
   unsigned short Sig_SnrDat_sFIR_Indir_FIL_cm;
   unsigned short Sig_SnrDat_sFIL_Indir_FIR_cm;
}US_S_SnsDat_Front_Indirect_1_t;

typedef struct US_S_SnsDat_Rear_Indirect_1_s
{
   unsigned short Sig_SnrDat_sRIR_Indir_RIL_cm;
   unsigned short Sig_SnrDat_sRIL_Indir_RIR_cm;
   unsigned short Sig_SnrDat_sRIL_Indir_ROL_cm;
   unsigned short Sig_SnrDat_sROL_Indir_RIL_cm;
   unsigned short Sig_SnrDat_sROL_Indir_RSL_cm;
   unsigned short Sig_SnrDat_sRSL_Indir_ROL_cm;
}US_S_SnsDat_Rear_Indirect_1_t;

/*******************************************************************/
/*                                                                 */
/*        Interface   Data structure                               */
/*                                                                 */
/*******************************************************************/
typedef struct US_ME_Diag_s
{
  US_ME_Diag_1_t sig_Diag1;
  US_ME_Diag_2_t sig_Diag2;
}US_ME_Diag_t;

typedef struct US_S_SnrDirEcho_s
{
	US_ME_SnsDat_Front_Direct_t     FrontSnrDirEcho1;
	US_ME_SnsDat_Front_Direct_2_t   FrontSnrDirEcho2;
	US_ME_SnsDat_FrontPSM_Echoes_t  FrontPSMEcho;
	US_ME_SnsDat_Rear_Direct_t      RearSnrDirEcho1;
	US_ME_SnsDat_Rear_Direct_2_t    RearSnrDirEcho2;
	US_ME_SnsDat_RearSide_Echoes_t  RearSideEcho;
}US_S_SnrDirEcho_t;

typedef struct US_S_SnrIndirEcho_s
{
	US_S_SnsDat_Front_Indirect_1_t     FrontSnrIndirEcho1;
	US_S_SnsDat_Front_Indirect_2_t     FrontSnrIndirEcho2;
	US_S_SnsDat_Rear_Indirect_1_t      RearSnrIndirEcho1;
	US_S_SnsDat_Rear_Indirect_2_t      RearSnrIndirEcho2;
}US_S_SnrInirEcho_t;


/*Mid Distance & Min Distance*/
typedef struct US_S_PointDistOutputBuff_s
{
    uint32_t timestamp;
    uint16_t minDist[16];
    uint16_t midDist[12];
} US_S_PointDistOutputBuff_t;


typedef struct US_S_PointMapGroup_s
{
	US_ME_FiringSensorsOutputBuff_t FiringSensors;
	US_ME_SensorFiringModeOutputBuff_t FiringMode;
	US_S_PointMapOutputBuff_t  PointMap;
	US_S_Firing_Sequence_t FiringSequence;
}US_S_PointMapGroup_t;

/*Zone Information*/
typedef struct US_S_ZoneInfo_s
{
    uint32_t timestamp;
    US_E_Zoneinfo_list_t  zoneInfo[US_MAX_SECTOR];
} US_S_ZoneInfo_t;


/*Blockage Bits*/
typedef struct US_S_BlockageBit_s
{
    uint32_t timestamp;
    uint16_t blockageFlagBits;
	uint16_t Rsv;
} US_S_BlockageBit_t;

/*Sensor Diagnostics*/
typedef struct US_S_DiagnosticsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t overTempFault;
    uint16_t commFault;
    uint16_t commUnknown;
    uint16_t hardwareFault;
} US_S_DiagnosticsOutputBuff_t;

/*****Structures Shared for Diagnostics*******/
/*Driving Frequency*/
typedef struct US_S_DrivingFrequency_s
{
	uint16_t uDrvFreq_FSR;
	uint16_t uDrvFreq_FOR;
	uint16_t uDrvFreq_FIR;
	uint16_t uDrvFreq_FIL;
	uint16_t uDrvFreq_FOL;
	uint16_t uDrvFreq_FSL;
	uint16_t uDrvFreq_RSR;
	uint16_t uDrvFreq_ROR;
	uint16_t uDrvFreq_RIR;
	uint16_t uDrvFreq_RIL;
	uint16_t uDrvFreq_ROL;
	uint16_t uDrvFreq_RSL;
}US_S_DrivingFrequency_t;


typedef struct US_S_uBlockageSetCnt_s
{
	uint16_t uBlockageSetCnt_FSR;
	uint16_t uBlockageSetCnt_FOR;
	uint16_t uBlockageSetCnt_FIR;
	uint16_t uBlockageSetCnt_FIL;
	uint16_t uBlockageSetCnt_FOL;
	uint16_t uBlockageSetCnt_FSL;
	uint16_t uBlockageSetCnt_RSR;
	uint16_t uBlockageSetCnt_ROR;
	uint16_t uBlockageSetCnt_RIR;
	uint16_t uBlockageSetCnt_RIL;
	uint16_t uBlockageSetCnt_ROL;
	uint16_t uBlockageSetCnt_RSL;
}US_S_uBlockageSetCnt_t;

typedef struct US_S_uBlockageClrCnt_s
{
	uint16_t uBlockageClrCnt_FSR;
	uint16_t uBlockageClrCnt_FOR;
	uint16_t uBlockageClrCnt_FIR;
	uint16_t uBlockageClrCnt_FIL;
	uint16_t uBlockageClrCnt_FOL;
	uint16_t uBlockageClrCnt_FSL;
	uint16_t uBlockageClrCnt_RSR;
	uint16_t uBlockageClrCnt_ROR;
	uint16_t uBlockageClrCnt_RIR;
	uint16_t uBlockageClrCnt_RIL;
	uint16_t uBlockageClrCnt_ROL;
	uint16_t uBlockageClrCnt_RSL;
}US_S_uBlockageClrCnt_t;

/*Ringing Frequency*/
typedef struct US_S_RigningFrequency_s
{
	uint16_t uRingFreq_FSR;
	uint16_t uRingFreq_FOR;
	uint16_t uRingFreq_FIR;
	uint16_t uRingFreq_FIL;
	uint16_t uRingFreq_FOL;
	uint16_t uRingFreq_FSL;
	uint16_t uRingFreq_RSR;
	uint16_t uRingFreq_ROR;
	uint16_t uRingFreq_RIR;
	uint16_t uRingFreq_RIL;
	uint16_t uRingFreq_ROL;
	uint16_t uRingFreq_RSL;
}US_S_RigningFrequency_t;


/*Ringing Time*/
typedef struct US_S_RigningTime_s
{
	uint16_t uRingTime_FSR;
	uint16_t uRingTime_FOR;
	uint16_t uRingTime_FIR;
	uint16_t uRingTime_FIL;
	uint16_t uRingTime_FOL;
	uint16_t uRingTime_FSL;
	uint16_t uRingTime_RSR;
	uint16_t uRingTime_ROR;
	uint16_t uRingTime_RIR;
	uint16_t uRingTime_RIL;
	uint16_t uRingTime_ROL;
	uint16_t uRingTime_RSL;
}US_S_RigningTime_t;

/*Sensor Temperature*/
typedef struct US_S_SensorTemp_s
{
	sint16_t sSensorTemp_FSR;
	sint16_t sSensorTemp_FOR;
	sint16_t sSensorTemp_FIR;
	sint16_t sSensorTemp_FIL;
	sint16_t sSensorTemp_FOL;
	sint16_t sSensorTemp_FSL;
	sint16_t sSensorTemp_RSR;
	sint16_t sSensorTemp_ROR;
	sint16_t sSensorTemp_RIR;
	sint16_t sSensorTemp_RIL;
	sint16_t sSensorTemp_ROL;
	sint16_t sSensorTemp_RSL;
}US_S_SensorTemp_t;

/*Murata Serial Number */
typedef struct US_S_SnrMurataSerialNum_s
{
	uint64_t uSnrMurataSerialNum_FSR;
	uint64_t uSnrMurataSerialNum_FOR;
	uint64_t uSnrMurataSerialNum_FIR;
	uint64_t uSnrMurataSerialNum_FIL;
	uint64_t uSnrMurataSerialNum_FOL;
	uint64_t uSnrMurataSerialNum_FSL;
	uint64_t uSnrMurataSerialNum_RSR;
	uint64_t uSnrMurataSerialNum_ROR;
	uint64_t uSnrMurataSerialNum_RIR;
	uint64_t uSnrMurataSerialNum_RIL;
	uint64_t uSnrMurataSerialNum_ROL;
	uint64_t uSnrMurataSerialNum_RSL;
}US_S_SnrMurataSerialNum_t;

/*Sensor IME Serial Number */
typedef struct US_S_USSVersion_s
{
        uint32_t US_CalVer;
		uint16_t US_SnrVer;
		uint8_t US_ModuleVer_YEAR;
		uint8_t US_ModuleVer_WEEK;
		uint8_t US_ModuleVer_DAY;
		uint8_t US_ModuleVer_BUILD;
        uint8_t Rsv[2];    
}US_S_USSVersion_t;

/*Sensor IME Serial Number */
typedef struct US_S_SnrIMESerialNum_s
{
	uint32_t uSnrIMESerialNum_FSR;
	uint32_t uSnrIMESerialNum_FOR;
	uint32_t uSnrIMESerialNum_FIR;
	uint32_t uSnrIMESerialNum_FIL;
	uint32_t uSnrIMESerialNum_FOL;
	uint32_t uSnrIMESerialNum_FSL;
	uint32_t uSnrIMESerialNum_RSR;
	uint32_t uSnrIMESerialNum_ROR;
	uint32_t uSnrIMESerialNum_RIR;
	uint32_t uSnrIMESerialNum_RIL;
	uint32_t uSnrIMESerialNum_ROL;
	uint32_t uSnrIMESerialNum_RSL;
}US_S_SnrIMESerialNum_t;

/*Sensor Power supply Paramenters*/
typedef struct US_S_SnrPowerSupply_s
{
	uint16_t uUSSPowerAMonVtg;
	uint16_t uUSSPowerBMonVtg;
	uint16_t uUSSPowerCMonVtg;
	uint16_t uUSSPowerIS1Current;
	uint16_t uUSSPowerIS2Current;
	uint16_t Reserved;           /*Reserved for Padding*/
}US_S_SnrPowerSupply_t;

/*Sensor Part Numbers*/
typedef struct US_S_USSPartNumberData_s
{
	uint8_t uUSSPartNum_FSR[13];
	uint8_t uUSSPartNum_FOR[13];
	uint8_t uUSSPartNum_FIR[13];
	uint8_t uUSSPartNum_FIL[13];
	uint8_t uUSSPartNum_FOL[13];
	uint8_t uUSSPartNum_FSL[13];
	uint8_t uUSSPartNum_RSR[13];
	uint8_t uUSSPartNum_ROR[13];
	uint8_t uUSSPartNum_RIR[13];
	uint8_t uUSSPartNum_RIL[13];
	uint8_t uUSSPartNum_ROL[13];
	uint8_t uUSSPartNum_RSL[13];
}US_S_USSPartNumberData_t;

/*Uss static info*/
typedef struct US_S_USSConstantData_s
{
	US_S_USSPartNumberData_t SensorPartNum;
	US_S_SnrIMESerialNum_t SensorIMESerialNum;
	US_S_SnrMurataSerialNum_t SensorMurataSerialNum;
    US_S_USSVersion_t  USS_Ver;
}US_S_USSConstantData_t;
/*Uss Period Diagnostic info*/
typedef struct US_S_USSPeriodDiagData_s
{
	US_S_DrivingFrequency_t SnrDrvFreq;
	US_S_RigningFrequency_t SnrRingFreq;
	US_S_RigningTime_t  SnrRingTime;
	US_S_SensorTemp_t   SnrTemperature;
	US_S_SnrPowerSupply_t SnrPwr;
	US_S_uBlockageSetCnt_t BlockageSetCnt;
	US_S_uBlockageClrCnt_t BlockageClrCnt;
}US_S_USSPeriodDiagData_t;

/*Uss Period Diagnostic info*/
typedef struct US_S_USSErrorDiagData_s
{
	US_S_DiagnosticsOutputBuff_t ErrorMsg;
	uint16 live_detection;
	uint16 rsv_u16;
}US_S_USSErrorDiagData_t;

/*USS Data Collection info*/
typedef struct US_S_USSDataCollectionData_s
{
    uint8_t Log_SnrMeasData_01[64u];
	uint8_t Log_SnrMeasData_02[64u];
	uint8_t Log_SnrMeasData_03[64u];
	uint8_t Log_SnrMeasData_04[64u];
	uint8_t Log_SnrMeasData_05[64u];
	uint8_t Log_SnrMeasData_06[64u];
	uint8_t Log_SnrMeasData_07[64u]; /*This is to include the extended data*/
	sint16_t Log_SnrTemperature[32u];/*US_D_MAX_NUM_SENSORS_CONFIGURABLE =32*/
	uint8_t Log_PackedNoiseMeasData[64u]; /*Packed Noise data along with sequence Number*/
	uint8_t Log_PackedDiagFlagData1_v[64u];/*Packed Diag data along with sequence Number*/
	uint8_t Log_PackedDiagFlagData2_v[64u]; /* remaining Packed Diag data along with sequence Number*/
}US_S_USSDataCollectionData_t;


/*Following Reasons are mapped with sensors */
typedef enum US_E_SnrFaultReason_e
{
	SNR_DIAG_FLG_SNR_TEMPERATURE_OUT_OF_RANGE = 0,                            
	SNR_DIAG_FLG_SENSOR_DISCONNECT,                               
	SNR_DIAG_FLG_RECEIVED_COMMAND_INVALID,                        
	SNR_DIAG_FLG_PDCM_PULSE_INVALID,                              
	SNR_DIAG_FLG_DISCOVERY_PULSE_INVALID,                         
	SNR_DIAG_FLG_FCC_ERROR_STATE,                                 
	SNR_DIAG_FLG_INVALID_START_EDGE_DETECTED,                     
	SNR_DIAG_FLG_SYNCHRONISATION_COUNTER_ERROR_DETECTED,          
	SNR_DIAG_FLG_CRM_TYPE_ERROR,                                  
	SNR_DIAG_FLG_SNR_COMM_UNKNOWN,                                
	SNR_DIAG_FLG_DRV1_FAILURE_DURING_BURST,                       
	SNR_DIAG_FLG_DRV2_FAILURE_DURING_BURST,                       	
	SNR_DIAG_FLG_DRVS_FAILURE_DURING_BURST,                       	
	SNR_DIAG_FLG_BURST_ABORT_DURING_BURST,                        
	SNR_DIAG_FLG_RING_COMPARATOR_ZERO,                            
	SNR_DIAG_FLG_GET_RING_FREQUENCY_FAILURE,                      
	SNR_DIAG_FLG_GET_DRV_FREQUENCY_FAILURE,                       	
	SNR_DIAG_FLG_SRAM_PARITY_ERROR,                               
	SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A1,                      
	SNR_DIAG_FLG_CRC_MISTMATCH_IN_EEPROM_A2,                      
	SNR_DIAG_FLG_ADA_MEASURE_TIMEOUT,                             
	SNR_DIAG_FLG_PROGRAM_EEPROM,                                  
	SNR_DIAG_FLG_VTANK_OVER_VOLTAGE_DURING_BURST,                 
	SNR_DIAG_FLG_VTANK_OVERVOLTAGE,                               
	SNR_DIAG_FLG_VTANK_UNDERVOLTAGE,                              
	SNR_DIAG_FLG_VSUP_OVER_VOLTAGE,                               
	SNR_DIAG_FLG_VSUP_UNDER_VOLTAGE,                              
	SNR_DIAG_FLG_BAD_RING_TIME,                                   
	SNR_DIAG_FLG_TRANSDUCER_ERR,                                  
	SNR_DIAG_FLG_SNR_BLOCKAGE,                                    
	SNR_DIAG_FLG_SNR_FW_MISMATCH,                                 
	SNR_DIAG_FLG_SNR_OPMODE_ERROR,                                
	SNR_DIAG_FLG_SNR_FAIL,                                        
	SNR_DIAG_FLG_SNR_SETUP_SENSOR_FAIL,                           
    SNR_DIAG_FLG_CRC_MISMATCH_IN_OTP,                             	
    SNR_DIAG_FLG_DSP_CONFIG_REGISTER_MISMATCH,                    
    SNR_DIAG_FLG_CPU_CONFIG_REGISTER_MISMATCH,                    
    SNR_DIAG_FLG_NOISE_DURING_BURST,                              
    SNR_DIAG_FLG_VREF_OUT_OF_RANGE,                               
    SNR_DIAG_FLG_VREF_OTP_OUT_OF_RANGE,                           
    SNR_DIAG_FLG_VDDD_OUT_OF_RANGE,                               
    SNR_DIAG_FLG_WD_COUNTER_DESYNC,                               
    SNR_DIAG_FLG_WD_CLOCK_FAIL,                                   							
    SNR_DIAG_FLG_CRC_BLOCK_CFG1,                                  
    SNR_DIAG_FLG_CRC_BLOCK_CFG2,                                  
    SNR_DIAG_FLG_CRC_BLOCK_MFG1,                                  
    SNR_DIAG_FLG_CRC_BLOCK_MFG2,                                  
    SNR_DIAG_FLG_CRC_OP_MODE1,                                    
    SNR_DIAG_FLG_CRC_OP_MODE2,
    SNR_DIAG_FLG_SIGNAL_PATH_FAILURE,
	SNR_DIAG_FLG_SNR_FLAG_MAX_CODE,
	SNR_DIAG_FLG_FLAG_NO_FAULT = 0xFF,  /*To initialize the output structure*/

}US_E_SnrFaultReason_t;

typedef enum US_E_ECUFaultReason_e
{
	DIAG_FLAG_REAR_BUMPER_SHRT_TO_GND = 0,
	DIAG_FLAG_REAR_BUMPER_OOR_LOW,
	DIAG_FLAG_REAR_BUMPER_OOR_HIGH,
	DIAG_FLAG_REAR_BUMPER_SHRT_TO_BAT,
	DIAG_FLAG_REAR_BUMPER_OPEN,
	DIAG_FLAG_FRONT_BUMPER_OOR_LOW,
	DIAG_FLAG_FRONT_BUMPER_OOR_HIGH,
	DIAG_FLAG_FRONT_BUMPER_SHRT_TO_GND,
	DIAG_FLAG_FRONT_BUMPER_SHRT_TO_BAT,
	DIAG_FLAG_FRONT_BUMPER_OPEN,
	DIAG_FLAG_ECU_NO_CALI_DATA,
	DIAG_FLAG_ECU_SPI_DMA_ERR,
	DIAG_FLAG_ECU_CFG_SENSOR_ERR,
	DIAG_FLAG_ECU_GPIO_INT_INITIAL_ERR,
	DIAG_FLAG_ECU_PIN_INITIAL_ERR,
	DIAG_FLAG_ECU_DSI_CLOCK_INITIAL_ERR,
	DIAG_FLAG_ECU_DSI_REF_INITIAL_ERR,
	DIAG_FLAG_ECU_SPI_INITIAL_ERR,
	DIAG_FLAG_ECU_MCAN_INITIAL_ERR,
	DIAG_FLAG_ECU_USS_POWER_ON_ERR,
    DIAG_FLAG_ECU_DSI_OT_ERR,
    DIAG_FLAG_ECU_DSI_CRC_ERR,
    DIAG_FLAG_ECU_DSI_RFC_ERR,
    DIAG_FLAG_ECU_DSI_DSIUV_ERR,
    DIAG_FLAG_ECU_DSI_VCCUV_ERR,
    DIAG_FLAG_ECU_DSI_RAM_BIST_FAIL,
    DIAG_FLAG_ECU_DSI_FSM_RESET,
    DIAG_FLAG_ECU_DSI_CLKREF_ERR,
    DIAG_FLAG_ECU_DSI0_OC_ERR,
    DIAG_FLAG_ECU_DSI1_OC_ERR,
    DIAG_FLAG_ECU_DSI0_UV_ERR,
    DIAG_FLAG_ECU_DSI1_UV_ERR,
    DIAG_FLAG_ECU_COMM_ERR,
	DIAG_FLAG_ECU_DSI3_registers_mismatch,
	DIAG_FLAG_ECU_MAX_CODE,
	DTC_ECU_NO_FAULT = 0xFF
}US_E_ECUFaultReason_t;

typedef struct US_S_MarriageSensorIDs_s
{
	boolean bValid;
    uint32_t uMarriageStatus;
    uint32_t uSavedSensorIDs[12];  //16 need to confirm
} US_S_MarriageSensorIDs_t;

typedef struct 
{
	uint8_t CsmStateCurrent;
	uint8_t CsmStatePreviuos;
	uint8_t CsmLocalModuleId;
	uint8_t CsmLocalModuleInstanceId;
	uint8_t CsmLocalErrOrEventId;
	uint8_t CsmLocalErrOrEventState;
}US_S_CsmStateChangeReason_Type;

typedef struct USS_S_PntDebugDataOutput_s
{
          USS_S_PntDebugData_t PntDebugDataOutput[4];  // Raw bytes for CAN FD output.
} USS_S_PntDebugDataOutput_t;

typedef struct US_S_DebugMsg_s
{ 
   signed short Sig_Debug_Signal[32];
   unsigned short Unsig_Debug_Signal[32];
}US_S_DebugMsg_t;

/* MCU_2_1 to MCU_1_0 */
typedef struct UssTunningData_mcu2_1_s
{
    uint8 UssTunningDataOut[3072];
}UssTunningData_mcu2_1_t;

#endif

#endif /* US_INTERFACE_OUTPUT_H_ */
