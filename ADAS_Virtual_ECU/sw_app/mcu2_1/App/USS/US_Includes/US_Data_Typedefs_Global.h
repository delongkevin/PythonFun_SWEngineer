/*
 * US_Data_Typedefs_Global.h
 *
 *  Created on: Mar 10, 2021
 *      Author: e39960
 */

#ifndef SRC_US_INCLUDES_US_DATA_TYPEDEFS_H_
#define SRC_US_INCLUDES_US_DATA_TYPEDEFS_H_

#include "US_ME_Typedefs_Global.h"

#define US_MAX_SENSOR_PER_BUS                 EIGHT   /*left over stuff - DO NOT USE */
#define US_MAX_ECHOES_BUFF                    TWENTY
#define US_MAX_OBJECT_PER_LIST (10)
#define US_POINT_NUM_MAX (4) /* We will send burst every 30 ~ 34 ms*/
#define US_START_EDGE (0) /* Idx of start edge*/
#define US_END_EDGE (1) /* Idx of end edge*/
#define US_PRLL_PARK (0) /* Idx of Parallel Parking */
#define US_PRPDR_PARK (1) /* Idx of Perpendicular Parking */

#define US_D_NEAR_BURSTNUM     (4)
#define US_D_NFD_BURSTNUM      (8)
#define US_D_FAR_BURSTNUM_CHIRP (64)
#define US_D_FAR_BURSTNUM_FIX  (16)
#define US_D_GANA              (6)
#define US_D_PROFILEb_GANA     (0)
#define US_D_CHIRPCN           (2)
#define US_D_CHIRPCW           (2)
#define pUS_D_Not_Check_Snr_FW_Sync  (0)
#define pUS_D_PreDefine_SnrFWVersion (0xF11A)
#define PROFILETYPE             (1) /*0 = XY, 1 = Corner, 2 = PSM */

#define US_D_MAX_NUM_ZONES      (EIGHT)

/*
 * Platform List
 * Note: Used #define instead of enum so can be used for compiler
 *       preprocessor #if statements.
 *       Will also be used to check if proper calibration is loaded into memory.
 */
#define US_D_PLATFORM_AMAZON     (0x100u)
#define US_D_PLATFORM_RIVIAN     (0x200u)
#define	US_D_PLATFORM_FISKER     (0x300u)
#define	US_D_PLATFORM_DTPAM      (0x400u)
#define	US_D_PLATFORM_DTPAM_HD   (0x401u)
#define	US_D_PLATFORM_DTPAM_BEV  (0x402u)
#define	US_D_PLATFORM_CVADAS     (0x800u)
#define	US_D_PLATFORM_CVADAS_HD  (0x801u)
#define	US_D_PLATFORM_CVADAS_BEV (0x802u)

/*
 * CAN Platform : currently this is temporary since this will be shifted to Calibration
 * 				Note: Following defines should be in bitwise manner, for CAN platform selection
 * */
#define US_D_CAN_PLATFORM_AMAZON  (0x1u)
#define US_D_CAN_PLATFORM_RIVIAN  (0x2u)
#define	US_D_CAN_PLATFORM_FISKER  (0x4u)
#define	US_D_CAN_PLATFORM_DTPAM   (0x10u)
#define	US_D_CAN_PLATFORM_CVADAS  (0x20u)
#define US_D_CAN_PLATFORM_EOL_TESTER  (0x10000u)
#define US_D_CAN_PLATFORM_RIVIAN_PARK_ASSIST  (0x8u)

/* Sensor range filter [cm] */
#define US_D_MAX_SENSOR_RANGE           (450u) /*\TODO jwr - only used in OD, need to replace */
#define US_D_MIN_SENSOR_FIXED_RANGE     (20u)
#define US_D_MAX_SENSOR_FIXED_RANGE     (600u)
#define US_D_MIN_SENSOR_NFD_RANGE       (1u)
#define US_D_MAX_SENSOR_NFD_RANGE       (40u)

/*
 * Operational Mode List
 */
typedef enum US_E_OperationMode_e
{
    US_NORMAL_MODE = 0,
    US_SNR_TEST_MODE,
    US_PLAYBACK_MODE,
    US_DIAGNOSTIC_MODE,
    US_NORMAL_AUTO_MODE
} US_E_OPERATION_MODE_t;
/*
 * This is the total number of sensors our system can allow.
 * Should not be sued other than in very low layers: SnrCmd, Driver, and Calibration.
 * See US_D_MAX_NUM_SENSORS for application layer number of sensors.
 */
#define US_D_MAX_NUM_SENSORS_CONFIGURABLE (32u)

typedef enum US_E_EchoInfoType_e
{
    US_E_FIXPATH = 0,
    US_E_COMBINEPATH,
    US_E_COMBINEPATH_FIL1,   /*Chirp Down */
    US_E_COMBINEPATH_FIL2,   /*Chirp Up */
    US_E_FILTERPATH,
    US_E_FILTERPATH_FIL1,    /*Chirp Down */
    US_E_FILTERPATH_FIL2,     /*Chirp Up */
    US_E_ECHOINFOTYPE_MAX
} US_E_EchoInfoType_t;

#if 0
typedef enum US_E_SENSOR_MAP
{
    US_E_SENSOR_CONFIG_MAP,
	US_E_SENSOR_INSTALL_MAP
};
#endif

typedef enum US_E_UpdateType_e
{
    US_E_UPDATE,
    US_E_NON_UPDATE
} US_E_UpdateType_t;

typedef enum US_E_EnvOutput_e
{
    US_E_ENVOUTDIS = 0,
    US_E_ENVOUTEN = 1
} US_E_EnvOutput_t;

/* ORDER DEPENDANT!!! HAS TO MATCH SENSOR SW.  DO NOT CHANGE! */
enum US_E_SnrErr_MeasErr_e
{
    ERR_DRV1_FAILURE_DURING_BURST        = 0x0001,
    ERR_DRV2_FAILURE_DURING_BURST        = 0x0002,
    ERR_DRVS_FAILURE_DURING_BURST        = 0x0004,
    ERR_VTANK_OVER_VOLTAGE_DURING_BURST  = 0x0008,
    ERR_BURST_ABORT_DURING_BURST         = 0x0010,
    ERR_RING_COMPARATOR_ZERO             = 0x0020,
    ERR_GET_RING_FREQUENCY_FAILURE       = 0x0040,
    ERR_GET_DRV_FREQUENCY_FAILURE        = 0x0080,
    ERR_DRV_FREQUENCY_OUT_OF_RANGE       = 0x0100,
    ERR_RING_FREQUENCY_OUT_OF_RANGE      = 0x0200
};
typedef enum US_E_SnrErr_MeasErr_e US_E_SnrErr_MeasErr_t;

/* ORDER DEPENDANT!!! HAS TO MATCH SENSOR SW.  DO NOT CHANGE! */
enum US_E_SnrErr_HardwareErr_e
{
    ERR_SRAM_PARITY_ERROR              = 0x0001,
    ERR_CRC_MISMATCH_IN_EEPROM_A1      = 0x0002,
    ERR_CRC_MISMATCH_IN_EEPROM_A2      = 0x0004,
    ERR_ADA_MEASURE_TIMEOUT            = 0x0008,
    ERR_VTANK_OVER_VOLTAGE             = 0x0010,
    ERR_VTANK_UNDER_VOLTAGE            = 0x0020,
    ERR_VSUP_OVER_VOLTAGE              = 0x0040,
    ERR_VSUP_UNDER_VOLTAGE             = 0x0080,
    ERR_SNR_TEMPERATURE_OUT_OF_RANGE   = 0x0100,
    ERR_PROGRAM_EEPROM                 = 0x0200
};
typedef enum US_E_SnrErr_HardwareErr_e US_E_SnrErr_HardwareErr_t;

/* ORDER DEPENDANT!!! HAS TO MATCH SENSOR SW.  DO NOT CHANGE! */
enum US_E_SnrErr_CommErr_e
{
    ERR_CRC_OF_RECEIVED_COMMAND_INVALID          = 0x0001,
    ERR_PDCM_PULSE_INVALID                       = 0x0002,
    ERR_DISCOVERY_PULSE_INVALID                  = 0x0004,
    ERR_FCC_ERROR_STATE                          = 0x0008,
    ERR_INVALID_START_EDGE_DETECTED              = 0x0010,
    ERR_SYNCHRONISATION_COUNTER_ERROR_DETECTED   = 0x0020,
    ERR_CRM_TYPE_ERROR                           = 0x0040,
    ERR_COMMAND_NOT_SUPPORTED                    = 0x0080
};

typedef enum US_E_SnrErr_CommErr_e US_E_SnrErr_CommErr_t;

/* ORDER DEPENDANT!!! HAS TO MATCH SENSOR SW.  DO NOT CHANGE! */
enum US_E_SnrErr_AsilErr_e
{
    ERR_CRC_MISMATCH_IN_OTP              = 0x0001,
    ERR_DSP_CONFIG_REGISTER_MISMATCH     = 0x0002,
    ERR_CPU_CONFIG_REGISTER_MISMATCH     = 0x0004,
    ERR_NOISE_DURING_BURST               = 0x0008,
    ERR_VREF_OUT_OF_RANGE                = 0x0010,
    ERR_VREF_OTP_OUT_OF_RANGE            = 0x0020,
    ERR_VDDD_OUT_OF_RANGE                = 0x0040,
    ERR_WD_COUNTER_DESYNC                = 0x0080,
    ERR_WD_CLOCK_FAIL                    = 0x0100,
    ERR_CRC_BLOCK_CFG1                   = 0x0200,
    ERR_CRC_BLOCK_CFG2                   = 0x0400,
    ERR_CRC_BLOCK_MFG1                   = 0x0800,
    ERR_CRC_BLOCK_MFG2                   = 0x1000,
    ERR_CRC_OP_MODE1                     = 0x2000,
    ERR_CRC_OP_MODE2                     = 0x4000,
    ERR_SIGNAL_PATH_FAILURE              = 0x8000
};


typedef enum US_E_SnrErr_AsilErr_e US_E_SnrErr_AsilErr_t;

typedef struct US_S_Sensor_coordinate
{
	float32_t fX;
	float32_t fY;
	float32_t fZ;
	float32_t fAngAlpha;
	float32_t fAngBeta;
	float32_t fAngDeg;
}US_S_Sensor_coordinate_t,*pUS_S_Sensor_coordinate_t;

typedef struct US_S_ZoneBounds_s
{
    uint8_t   uNumZones;
    uint8_t   Rsv[3];
    float32_t fZoneUpperBound[US_D_MAX_NUM_ZONES];
} US_S_ZoneBounds_t;

typedef struct US_S_SectorEdge_s
{
 sint16_t iX;
 sint16_t iY;
 uint16_t uDepthL;
 uint16_t uDepthR;
 float32_t fAngle;
} US_S_SectorEdge_t;

typedef struct US_S_KinematicCfg_s
{
	float32_t whl_Circum;
	float32_t whl_Base;
	float32_t max_Tick;
	float32_t num_Pulses;
	float32_t TestBasedLookupTable_tableData[7];
    float32_t TestBasedLookupTable_bp01Data[7];
} US_S_KinematicCfg_t;


typedef struct US_S_ECU_Operation_s
{
    uint8_t ECU_Operation_Mode;
    uint8_t Reserved[3];
} US_S_ECU_Operation_Mode_t;
typedef struct US_S_SensorsCfg_s
{
    uint16_t PlatformID;
    uint8_t nBusCfg;
    uint8_t Max_nSnr_ON_SINGLE_BUS;
    uint32_t SnrMap;
    uint32_t Snr_Positions[32];
    pUS_S_Sensor_coordinate_t pSnrCoordinate;
} US_S_SensorsCfg_t;
typedef struct US_S_SensorsCfg1_s
{
    uint16_t PlatformID;
    uint8_t nBusCfg;
    uint8_t Max_nSnr_ON_SINGLE_BUS;
    uint32_t SnrMap;
    uint32_t Snr_Positions[32];
    US_S_Sensor_coordinate_t SnrCoordinate[32];
} US_S_SensorsCfg1_t;
typedef struct US_S_TuneFlashCfg_s
{
    uint16_t SizeBufferCmd;
    uint16_t MaxCmds;
    uint16_t AddressType;
    uint16_t DIDType;
    uint32_t StartBlockAddress;
    uint32_t SizeBlock;
    uint32_t SizeEraseBlock;
} US_S_TuneFlashCfg_t;

typedef struct US_S_SendBurst17Cfg_s
{
    uint8_t IsCalibration;
    uint8_t IsNFDMode;
    uint8_t Update;
    uint8_t EnvOutput;
    uint8_t EchoInfo;
    sint8_t CompGain; /*Is MeasureTimeF before 0xF11A */
    uint8_t MaxEchoNum; /*Legacy. Not used since Amazon Scout. */
    uint8_t MeasurementTime;
    uint8_t PreburstNoiseChkTime;
    uint8_t G_digBoost;
} US_S_SendBurst17Cfg_t;

typedef enum US_E_SnrAsicType_e
{
    US_E_09_ID = 0,
    US_E_17_ID = 1,
    US_E_33_ID = 2,
    US_E_MIX_ID = 3,
    US_E_SNR_ASIC_TYPE_MAX = 4
} US_E_SnrAsicType_t;

typedef enum US_E_ProfileType_e
{
    US_E_PROFILE_NONE = 0, /* unused */
  	US_E_PROFILE_A = 1, /*US_E_PROFILE_Fix16 */
    US_E_PROFILE_B = 2, /*US_E_PROFILE_NFD */
    US_E_PROFILE_C = 3, /*US_E_PROFILE_Chirp */
    US_E_PROFILE_A_VARIANT = 4, /*US_E_PROFILE_PLUS_Fix16 */
    US_E_PROFILE_B_VARIANT = 5, /*US_E_PROFILE_PLUS_Fix4 */
    US_E_PROFILE_C_VARIANT = 6, /*US_E_PROFILE_PLUS_Chirp */
    US_E_PROFILE_USER_DEF = 7
} US_E_ProfileType_t;

typedef enum US_E_SendBurstType_e
{
    US_E_SEND_STANDBY,
    US_E_SEND_NORMAL,
    US_E_SEND_CHIRP_UP,
    US_E_SEND_CHIRP_DOWN,
    US_E_RECEIVE
} US_E_SendBurstType_t;

typedef struct US_S_ClusterBurstCmd_s
{
    uint8_t SnrType;   /*remove - not needed */
    uint8_t uNumPDCM[EIGHT];     /* \TODO - find a way to use US_D_MAX_NUM_BUS */
    uint8_t ProfileType[EIGHT];  /* find a way to use US_D_MAX_NUM_BUS */
    uint8_t TypeAry[32];
    US_S_SendBurst17Cfg_t Cfg[EIGHT]; /* find a way to use US_D_MAX_NUM_BUS */
    uint8_t pdcm_period;     /**100us */
} US_S_ClusterBurstCmd_t;

typedef struct US_S_ProfileCfg_s
{
    uint8_t nPulses_N;
    uint8_t nPulses_C;
    uint8_t Current;
    uint8_t G_dig;
    uint8_t G_ana;
    uint8_t BW;
    uint8_t CN1;
    uint8_t CW1;
    uint8_t CN2;
    uint8_t CW2;
    uint8_t ATG_on;
    uint8_t STC_on;
    uint8_t FTC_on;
    uint8_t NFD_on;
    uint16_t Rsv;
} US_S_ProfileCfg_t;

typedef struct US_S_ProfileCfg_Index_s
{
    uint8_t Index;
    uint8_t Rsv0;
    uint8_t ProfileType;
    uint8_t Rsv1;
	US_S_ProfileCfg_t ProfileCfg;
} US_S_ProfileCfg_Index_t;

typedef struct US_S_TemperatureCompensation_s
{
    uint16_t points_temp;
    sint16_t default_temp;
    sint16_t temp_table[20];
 } US_S_TemperatureCompensation_t;

typedef struct US_S_ATGCfg_s
{
    uint8_t Tau;
    uint8_t Alpha;
    uint8_t Int;
    uint8_t On;
} US_S_ATGCfg_t;

typedef struct US_S_AATGCfg_s
{
    uint8_t CN;
    uint8_t CW;
    uint8_t Alpha;
    uint8_t Rsv;
} US_S_AATGCfg_t;

typedef struct US_S_ChirpCfg_s
{
    uint8_t Type;
    uint8_t BurstNum;
    uint8_t BW;
    uint8_t Dsr;
} US_S_ChirpCfg_t;

typedef struct US_S_BurstTypeCCfg_s
{
    uint16_t Code;
    uint8_t CodeLen;
    uint8_t Rsv;
} US_S_BurstTypeCCfg_t;

typedef struct US_S_CurrentCfg_s
{
    uint8_t Idrive;
    uint8_t ReduceCurrent;
    uint16_t Rsv;
} US_S_CurrentCfg_t;

typedef struct US_S_GainCfg_s
{
    uint8_t G_dig;
    uint8_t G_ana;
    uint8_t FCx2;
    uint8_t G_reduce;
} US_S_GainCfg_t;
typedef struct US_S_ProfilePlus_s
{
  uint8_t STGFixValue;
  uint8_t STCShift;
}US_S_ProfilePlusCfg_t;
typedef struct US_S_ProfilePlus_Index_s
{
  uint8_t Profile;
  uint8_t Rsv[3];
  uint8_t STGFixValue;
  uint8_t STCShift;
}US_S_ProfilePlus_IndexCfg_t;

typedef struct US_S_EnvCfg_s
{
    uint8_t AspiSel;
    uint8_t FspiSel;
    uint8_t EnvAfc;
    uint8_t EnvCfg;
} US_S_EnvCfg_t;

typedef struct US_S_EnvFiltCfg_s
{
    uint8_t F2CoeffSel;
    uint8_t F1CoeffSel;
    uint8_t FiltLenCode;
    uint8_t FiltLenFix;
} US_S_EnvFiltCfg_t;

typedef struct US_S_EchoCfg_s
{
    uint8_t MaxNum;
    uint8_t Type;
    uint8_t mode;
    uint8_t Rsv;
} US_S_EchoCfg_t;

typedef struct US_S_FixPathCfg_s
{
    uint8_t EevalSel;
    uint8_t EevalSens;
    uint16_t Rsv;
} US_S_FixPathCfg_t;

typedef struct US_S_NFDCfg_s
{
    uint8_t LimitTime;
    uint8_t Sen;
    uint16_t Th;
    uint8_t RingDev;
    uint8_t Rsv[3];
} US_S_NFDCfg_t;

typedef struct US_S_EDICfg_s
{
    uint16_t StartTime;
    uint8_t Mode;
    uint8_t SampleTime;
} US_S_EDICfg_t;

typedef struct US_S_RegCfg_s
{
    uint8_t ModAddr;
    uint8_t Addr;
    uint16_t Data;
} US_S_RegCfg_t;

typedef struct US_S_EEPROMCfg_s
{
    uint8_t Addr;
    uint8_t length;
    uint16_t Data;
} US_S_EEPROMCfg_t;

typedef struct US_S_FTCfg_s
{
    uint8_t Cfg;
    uint8_t Enable;
    uint8_t Rsv[TWO];
} US_S_FTCfg_t;

typedef struct US_S_StcCfg_s
{
    uint8_t time;
    uint8_t mode;
    uint8_t target;
    uint8_t Rsv;
    uint16_t tb;
} US_S_StcCfg_t;

typedef struct US_S_StcSeg_s
{
    uint8_t start;
    uint8_t rsv[3];
    US_S_StcCfg_t seg[4];
    US_E_ProfileType_t profile;
} US_S_StcSeg_t;

typedef struct US_S_Stc_s
{
	US_S_StcSeg_t US_STC[2];
}US_S_Stc_t;
typedef struct US_S_reqStcStgCfg_s
{
	uint8_t StartSeg;
	uint8_t SegLen;
}US_S_reqStcStgCfg_t;
typedef struct US_S_StgCfg_s
{
    uint8_t time;
    uint8_t th;
   sint8_t step;
    uint8_t Rsv[3];
    uint16_t tb;
} US_S_StgCfg_t;

typedef struct US_S_StgSeg_s
{
    uint8_t start;
    uint8_t Rsv[3];
    US_S_StgCfg_t seg[4];
    US_E_ProfileType_t profile;
} US_S_StgSeg_t;

typedef struct US_S_Stg_s
{
 	US_S_StgSeg_t US_STG[4];
} US_S_Stg_t;

typedef struct US_S_GanaMeasBegin_s
{
    uint16_t EndTime;
    uint8_t Gana_Dig;
    uint8_t Gana;
} US_S_GanaMeasBegin_t;

typedef union US_S_EEVALSENSMEAS_s
{
    uint32_t val;
    struct
    {
        uint32_t reserve :10;
        uint32_t Sen2 :3;
        uint32_t Sen1 :3;
        uint32_t EndTime :15;
        uint32_t Enable :1;
    } bit;
} US_S_EEVALSENSMEAS_t;

typedef union US_S_SensorEEFlagVarCTRL_s
{
    uint32_t val;
    struct
    {
        uint32_t reserve :23;
        uint32_t Auto_ENVP_CFG_Disable :1;
        uint32_t GainCompVolt_EEValue :1;
        uint32_t GainCompVolt_enable :1;
        uint32_t GainCompTemp_EEValue :1;
        uint32_t GainCompTemp_enable :1;
        uint32_t AllFiltEcho_Combine :1;
        uint32_t FreqComp_EEValue :1;
        uint32_t FreqComp_disable :1;
        uint32_t Coeff_EEValue :1;
    } bit;
} US_S_SensorEEFlagVarCTRL_t;


typedef struct US_S_MeasDetailsProf_s
{
    uint8_t NPulses_u3;
    uint8_t ThresScale_u2;
    uint8_t TMeas_u3;
    uint8_t Rsv;
} US_S_MeasDetailsProf_t;

typedef struct US_S_MeasDetailsProf_V_s
{
    uint8_t NPulses_u3;
    uint8_t Thsel_u1;
    uint8_t TMeas_u3;
    uint8_t Rsv;
} US_S_MeasDetailsProf_V_t;

#if 0
typedef struct US_S_RingTime_s
{
    uint16_t EvRing_u16;
    uint16_t DrvFreq_u16;
    uint16_t RingFreq_u16;
    uint8_t Ctype;
    uint8_t Rsv;
}US_S_RingTime_t;

typedef struct US_S_MeasDetails_s
{
    uint8_t firstEchoHeight_u6;
    uint8_t FreqDev_u2;
    uint8_t Noise_b;
    uint8_t ProfRecErr_b;
}US_S_MeasDetails_t;

typedef struct US_S_MeasDetails_V_s
{
    uint8_t FirstEchoHeight_u6;
    uint8_t SecondEchoHeight_u6;
    uint8_t FreqDev_u2;
    uint8_t Noise_u1;
    uint8_t ProfRecErr_u1;
    uint8_t NFD_u1;
    uint8_t Reserved_u1[2];
}US_S_MeasDetails_V_t;

typedef struct pUS_S_Impulse17_s
{
    uint8_t CType_u8; /* US_E_Chirp_t */
    uint8_t LMax_Num_u8; /* local max number*/
    uint8_t Conf_u8; /* CType_u8 == NORMAL -> width*/
    uint8_t Rsv;
    uint16_t EchoHeight_u16;
    uint16_t Width_u16;
    uint16_t Dist_u16;
}US_S_Impulse17_t;

typedef struct pUS_S_Impulse09_s
{
    uint16_t Width_u16;
    uint16_t Dist_u16;
}US_S_Impulse_t;

typedef struct US_S_SensorRec_s
{
    US_S_Impulse_t EchoSet_at[US_MAX_ECHOES_BUFF];
    US_S_MeasDetails_t MeasDetails_t;
    US_S_MeasDetails_V_t MeasDetails_V_t;
    uint8_t NumEchoes_u8;
    US_S_RingTime_t RingingTime_t;
    uint8_t NoEchoInfo_u8;
    uint8_t DiagStatus_u8;
}US_S_SensorRec_t;

#endif

typedef struct US_S_ClusterSerialNum_s
{
    uint8_t NumSensortypedefs_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    uint32_t SensorSerialNum_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterSerialNum_t;

typedef struct US_S_ThresSetup_s
{
    uint8_t ThVal_u5[TWELVE];
    uint8_t ThSftCfg_u2;
    uint8_t ATGCfg_u2;
    uint8_t ATGTau_u2;
    uint8_t ATGAlpha_u1;
    uint8_t ThresScaleRec_u2;
    uint8_t Rsv;
} US_S_ThresSetup_t;

typedef struct US_S_ThresWrite_V_s
{
    uint8_t ThValA_u5[TEN];
    uint8_t ThPosA_u3[TEN];
} US_S_ThresWrite_V_t;

typedef struct US_S_ClusterThresSetup_s
{
    uint8_t ClusterSize_u8;
    uint8_t Rsv;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_ThresSetup_t ThresSetup_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterThresSetup_t;

typedef struct US_S_ClusterThresWrite_V_s
{
    uint8_t ClusterSize_u8;
    uint8_t Rsv;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_ThresWrite_V_t ThresWrite_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterThresWrite_V_t;

typedef struct US_S_MeasSetup_s
{
    uint8_t EPD_u1;
    uint8_t FilterCfg_u1;
    uint8_t FTC_u1;
    uint8_t NFTG_u1;
    uint8_t NoiseCfg_u2;
    US_S_MeasDetailsProf_t ProfileA_t;
    US_S_MeasDetailsProf_t ProfileB_t;
    US_S_MeasDetailsProf_t ProfileC_t;
    uint8_t EchoDeb_u1;
    uint8_t RTCfg_u1;
    uint8_t STCCfg_u2;
    uint8_t STCStart_u2;
} US_S_MeasSetup_t;

typedef struct US_S_MeasWrite_V_s
{
    uint8_t EPD_u1;
    uint8_t FilterCfg_u2;
    uint8_t FTC_u1;
    uint8_t NFTG_u1;
    uint8_t NoiseCfg_u2;
    US_S_MeasDetailsProf_V_t ProfileA_t;
    US_S_MeasDetailsProf_V_t ProfileB_t;
    US_S_MeasDetailsProf_V_t ProfileC_t;
    uint8_t EchoDeb_u1;
    uint8_t RTCfg_u1;
    uint8_t STCPos0_u3;
    uint8_t STCPos1_u3;
    uint8_t STCPos2_u3;
    uint8_t STCPos3_u3;
    uint8_t STCPos4_u3;
    uint8_t STCGain1_u4;
    uint8_t STCGain2_u4;
    uint8_t STCGain3_u4;
    uint8_t STCGain4_u4;
    uint8_t APD_u1;
    uint8_t ATGCfg_u2;
    uint8_t ATGTau_u2;
    uint8_t ATGAlpha_u1;
    uint8_t NSuppCfg_u2;
    uint8_t ThresscaleRec_u2;
    uint8_t StatusCfg_u2;
} US_S_MeasWrite_V_t;

enum US_E_SensorID_e
{
    US_E_FRONT_SIDE_LEFT_ID,
    US_E_FRONT_OUTER_LEFT_ID,
    US_E_FRONT_INNER_LEFT_ID,
    US_E_FRONT_INNER_RIGHT_ID,
    US_E_FRONT_OUTER_RIGHT_ID,
    US_E_FRONT_SIDE_RIGHT_ID,
    US_E_REAR_SIDE_LEFT_ID,
    US_E_REAR_OUTER_LEFT_ID,
    US_E_REAR_INNER_LEFT_ID,
    US_E_REAR_INNER_RIGHT_ID,
    US_E_REAR_OUTER_RIGHT_ID,
    US_E_REAR_SIDE_RIGHT_ID,
    US_E_SENSOR_ID_MAX
};

enum US_E_ParkSpacePointSeq_e
{
    US_E_SRPS_OUTER_F_X = 0,
    US_E_SRPS_OUTER_F_Y,
    US_E_SRPS_INNER_F_X,
    US_E_SRPS_INNER_F_Y,
    US_E_SRPS_INNER_R_X,
    US_E_SRPS_INNER_R_Y,
    US_E_SRPS_OUTER_R_X,
    US_E_SRPS_OUTER_R_Y,
    US_E_SRPS_MAX
};
typedef enum US_E_ParkSpacePointSeq_e US_E_ParkSpacePointSeq_t;

typedef struct US_S_SensorClusterList_s
{
    uint8_t NumSensors_u8;
    uint8_t SensorIDs_at[US_MAX_SENSOR_PER_BUS];
} US_S_SensorClusterList_t;

typedef struct US_S_Calib_s
{
    uint8_t OscTrim_u4;
    uint8_t CustomerBits_u7;
    uint8_t GDig_u7;
    uint8_t GAna_u3;
    uint8_t IDrv_u5;
    uint8_t FDrv_u8;
} US_S_Calib_t;

typedef struct US_S_CalibWrite_V_s
{
    uint8_t TsensTrim_u3;
    uint8_t OscTrim_u4;
    uint8_t Reserved_u1;
    uint8_t NFDWin_u2;
    uint8_t NFDThres_u3;
    uint8_t NFDToff_u3;
    uint8_t GDig_u7;
    uint8_t GAna_u3;
    uint8_t VDrv_u4;
    uint8_t FDrv_u8;
    uint8_t SDamp_u4;
    uint32_t CustomerBits_u32;
} US_S_CalibWrite_V_t;

typedef struct US_S_ClusterCalib_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_Calib_t Calib_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterCalib_t;

typedef struct US_S_ClusterCalibWrite_V_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_CalibWrite_V_t CalibWrite_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterCalibWrite_V_t;

typedef struct US_S_ClusterCalPulses_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    uint16_t Pulse_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterCalPulses_t;

typedef struct US_S_ClusterMeasSetup_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_MeasSetup_t MeasSetup_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterMeasSetup_t;

typedef struct US_S_ClusterMeasWrite_V_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_MeasWrite_V_t MeasWrite_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterMeasWrite_V_t;

typedef struct US_S_ClusterTemp_s
{
    uint8_t NumSensors_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    sint16_t TempArray_as16[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterTemp_t;

typedef struct US_S_ReadStatus_s
{
    uint8_t Undervoltage_u1;
    uint8_t Overvoltage_u1;
    uint8_t MeasSetupOK_u1;
    uint8_t ThresSetupOK_u1;
    uint8_t FreqMeasOK_u1;
    uint8_t FreqDev_u5;
} US_S_ReadStatus_t;

typedef struct US_S_ReadStatus_V_s
{
    uint8_t Reserved_u1;
    uint8_t NFD_u1;
    uint8_t NoiseBeforeMeas_u1;
    uint8_t NoiseInMeas_u1;
    uint8_t TransducerDrvOK_u1;
    uint8_t Overvoltage_VDRV_u1;
    uint8_t Undervoltage_VDRV_u1;
    uint8_t Undervoltage_VSUP_u1;
    uint8_t MeasSetupOK_u1;
    uint8_t ThresBWriteOK_u1;
    uint8_t ThresAWriteOK_u1;
    uint8_t FreqMeasOK_u1;
    uint8_t FreqDev_u5;
} US_S_ReadStatus_V_t;

typedef struct US_S_ReadNFDStatus_V_s
{
    uint16_t Integrator_u13;
    uint16_t TCOMP_u11;
} US_S_ReadNFDStatus_V_t;

typedef struct US_S_ClusterReadStatus_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_ReadStatus_t ReadStatus_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterReadStatus_t;

typedef struct US_S_ClusterReadStatus_V_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_ReadStatus_V_t ReadStatus_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterReadStatus_V_t;

typedef struct US_S_ClusterReadNFDStatus_V_s
{
    uint8_t ClusterSize_u8;
    uint8_t Status_at[US_MAX_SENSOR_PER_BUS];
    US_S_ReadNFDStatus_V_t ReadNFDStatus_at[US_MAX_SENSOR_PER_BUS];
} US_S_ClusterReadNFDStatus_V_t;

/* These types are NOT defined by the RTE. */

typedef struct US_S_Position_s
{
    sint16_t X_s16;
    sint16_t Y_s16;
} US_S_Position_t;

typedef struct US_S_Object_s
{
    US_S_Position_t Pos_t;
    uint8_t Type_u8;
} US_S_Object_t;

typedef struct US_S_ObjectList_s
{
    uint8_t NumObj_u8;
    US_S_Object_t Objects_at[US_MAX_OBJECT_PER_LIST];
    uint32_t TimeStamp_u32;
} US_S_ObjectList_t;

typedef enum US_E_Gear_e
{
    GEAR_P = 0x0,
    GEAR_R = 0x1,
    GEAR_N = 0x2,
    GEAR_D = 0x4,
    GEAR_SNA = 0x7
} US_E_Gear_t;

typedef struct US_S_VehicleInfo_s
{
    float32_t Speed_cm_ms;
    US_E_Gear_t Gear;
    float32_t WheelAngle; /* degree or 2PI system*/
   sint8_t KM_X_cm;
   sint8_t KM_Y_cm;
    float32_t KM_Heading;
    uint32_t KM_TimeStamp;
} US_S_VehicleInfo_t;

typedef enum e_US_ParkSpace_Type_e
{
    US_SPType_None,
    US_SPType_Para_R,
    US_SPType_Para_L,
    US_SPType_Perp_R,
    US_SPType_Perp_L,
    US_SPType_FishForward_R,
    US_SPType_FishForward_L,
    US_SPType_FishBackward_R,
    US_SPType_FishBackward_L
} E_US_ParkSpace_Type_t;

typedef struct US_S_ParkSpaceEdge_s
{
    uint32_t edgePointTimeStamp;   /*Range: 0~65535 ms */
    uint8_t snrNum;
    uint8_t edgeType;             /*Start_Edge or End_Edge, US_START_EDGE or US_END_EDGE */
    E_US_ParkSpace_Type_t parkingScenario;      /*Parallel or Perpendicular Parking, US_PRLL_PARK or US_PRPDR_PARK */
} US_S_ParkSpaceEdge_t;

typedef struct US_S_ParkSpace_s
{
    uint32_t TimeStamp;   /*Range: 0~65535 ms */
    E_US_ParkSpace_Type_t PSType;      /*Parallel or Perpendicular Parking, US_PRLL_PARK or US_PRPDR_PARK */
    sint8_t SpcPnt[US_E_SRPS_MAX];
} US_S_ParkSpace_t;

typedef enum e_US_MultiEcho_Type_e
{
    US_MultiEcho_None,
    US_MultiEcho_Small,
    US_MultiEcho_Big
} E_US_MultiEcho_Type_t;

#define US_MULTI_DEV_LINE        (125)            /*cm, dividing line for deviation in multiple echo deviation algorithm */
#define US_MULTI_DEV_BIG         (90)             /*cm, big deviation for multiple echo deviation algorithm */
#define US_MULTI_DEV_SMALL       (60)             /*cm, small deviation for multiple echo deviation algorithm */

typedef struct US_S_ParkDistanceRaw_s
{
    uint32_t rawDistanceTimeStamp;   /*Range: 0~65535 ms, PointNum means how many bursts send from PSD sensor during 100ms. */
    uint8_t snrNum;
    uint16_t rawDistance[US_MAX_ECHOES_BUFF];            /*Range: 0~500 cm, PointNum means how many bursts send from PSD sensor during 100ms. */
    uint8_t echoNum;
    E_US_MultiEcho_Type_t MET; /*Multiple Echo Type */
} US_S_ParkDistanceRaw_t;

typedef struct US_S_ObjectLoc_s
{
    uint16_t OD_Coll_Dist;
    uint16_t OD_Rearymin;
    sint16_t OD_Rearxmin;
} US_S_ObjectLoc_t;

typedef enum US_E_ParkingMode_e
{
    US_PARKMODE_STANDBY = ZERO,
    US_PARKMODE_SCANNING,
    US_PARKMODE_PARKING,
    US_PARKMODE_TEST, /*KPK-added*/
    US_PARKMODE_MAX
} US_E_ParkingMode_t;

typedef enum US_E_NoiseMitigationMode_e
{
    US_NOISEMIT_NONE = ZERO,
    US_NOISEMIT_FILTER1,
    US_NOISEMIT_FILTER2,
    US_NOISEMIT_CAUTION,
    US_NOISEMIT_LISTEN_ONLY,
    US_NOISEMIT_MAX
} US_E_NoiseMitigationMode_t;

#endif /* SRC_US_INCLUDES_US_DATA_TYPEDEFS_H_ */
