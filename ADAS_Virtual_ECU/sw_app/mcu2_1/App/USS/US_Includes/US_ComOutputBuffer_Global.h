/*
 * US_ComOutputBuffer_Global.h
 *
 *  Created on: Mar 18, 2021
 *      Author: jonapais
 */

#ifndef USSMGR_US_MGROUTPUTBUFF_H_
#define USSMGR_US_MGROUTPUTBUFF_H_

/************************************************************************************************************************
* Include Files
************************************************************************************************************************/
#include "USS_Library_Header.h"
#include "US_ObjDet_Global.h"
#include "US_Interface_Output.h"
#if US_D_CUR_PLATFORM == US_D_PLATFORM_RIVIAN
#include "US_Stub.h"
# define    US_D_DATA_SHARE_CALLBACKS_ENABLE
#endif


/******NOTE : Need to comment out the following #define while releasing SW & this is only for Developers testing ******/
/* comment out #define DEBUG_CAN_MSGS_ENABLE */

/************************************************************************************************************************
* Enum's used in Output buffer
************************************************************************************************************************/
/*Enums Used In Com Output Buffer*/
typedef enum
{
    USSCOM_SYSSTATE_INIT = 0 ,
    USSCOM_SYSSTATE_CONFIG,
    USSCOM_SYSSTATE_CALIBRATION,
    USSCOM_SYSSTATE_DIAGNOSTIC,
    USSCOM_SYSSTATE_READY
} UssCom_E_SystemState_t;

typedef enum
{
    USSCOM_BUMPLOC_FRONT = 0,
    USSCOM_BUMPLOC_REAR,
    USSCOM_BUMPLOC_LEFT_SIDE,
    USSCOM_BUMPLOC_RIGHT_SIDE,
    USSCOM_BUMPLOC_MAX
} UssCom_E_BumperLocation_t;

typedef enum
{
    USSCOM_BUMPSTATE_OFF = 0,
    USSCOM_BUMPSTATE_OK,
    USSCOM_BUMPSTATE_NOISY,
    USSCOM_BUMPSTATE_DEGRADED,
    USSCOM_BUMPSTATE_FAULTED
} UssCom_E_BumperState_t;

/************************************************************************************************************************
* Structure typedefs used in the Output buffer
************************************************************************************************************************/
/*
 * Test Debug data structures
*/

/*Direct/Indirect Test Echo Data*/
typedef struct UssCom_S_SnsDataDirectEco_s
{
    uint16_t SnsDataFSLTimestamp;
    uint16_t SnsDataFSLDirEcho1_cm;
    uint16_t SnsDataFSLDirEcho2_cm;
    uint16_t SnsDataFSRTimestamp;
    uint16_t SnsDataFSRDirEcho1_cm;
    uint16_t SnsDataFSRDirEcho2_cm;
    uint16_t SnsDataRSLTimestamp;
    uint16_t SnsDataRSLDirEcho1_cm;
    uint16_t SnsDataRSLDirEcho2_cm;
    uint16_t SnsDataRSRTimestamp;
    uint16_t SnsDataRSRDirEcho1_cm;
    uint16_t SnsDataRSRDirEcho2_cm;
} UssCom_S_SnsDataDirectEco_t;

/* Indexed Messages */
typedef struct US_S_TestDataMux_s
{
    uint16_t uDirEcho;
    uint16_t uEchoHeight;
    uint16_t uRingTime;
    uint16_t uDrvFreq;
    uint16_t uRingFreq;
    uint8_t uBlockageSetCnt;
    uint8_t uBlockageClrCnt;
} UssCom_S_TestDataMux_t;

/* Direct display messages */
typedef struct US_S_TestDataCluster_s
{
    uint16_t FrontDir_Echo1[6u];
    uint16_t RearDir_Echo1[6u];
    uint16_t FrontDir_Echo2[6u];
    uint16_t RearDir_Echo2[6u];
    uint16_t FirstEchoIdxF[6u];
    uint16_t FirstEchoIdxR[6u];
    uint16_t FrontInDir[10u];
    uint16_t RearInDir[10u];
    UssCom_S_TestDataMux_t sDataMux[US_D_MAX_NUM_SENSORS];
    UssCom_S_SnsDataDirectEco_t US_S_SnsDataDirectEco;
} UssCom_S_TestDataCluster_t;

/*
 *  Data structures
 */
/*Point Map*/






/*Object map*/
typedef struct UssCom_S_ObjectDetOutputBuff_s
{
    sint16_t centerX;
    sint16_t centerY;
    sint16_t closeX;
    sint16_t closeY;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
    uint8_t  diameter;
} UssCom_S_ObjectDetOutputBuff_t;

typedef struct UssCom_S_ObjList_s
{
    uint32_t timestamp;
    UssCom_S_ObjectDetOutputBuff_t objects[48];
} UssCom_S_ObjectMapOutputBuff_t;



/*Left side sensor Panel Echos*/
typedef struct UssCom_S_SnsDatLeftSidePanelEchoesMsg_s
{
	uint16_t Sig_SnrDat_sBOL_Indir_AOL_cm;
	uint16_t Sig_SnrDat_sAOL_Indir_BOL_cm;
	uint16_t Sig_SnrDat_BOL_Dir2_cm;
	uint16_t Sig_SnrDat_BOL_Dir1_cm;
	uint16_t Sig_SnrDat_AOL_Dir2_cm;
	uint16_t Sig_SnrDat_AOL_Dir1_cm;
}UssCom_S_SnsDatLeftSidePanelEchoesMsg_t;

/*Right side sensor Panel Echos*/
typedef struct UssCom_S_SnsDatRightSidePanelEchoesMsg_s
{
	uint16_t Sig_SnrDat_sBOR_Indir_AOR_cm;
	uint16_t Sig_SnrDat_sAOR_Indir_BOR_cm;
	uint16_t Sig_SnrDat_BOR_Dir2_cm;
	uint16_t Sig_SnrDat_BOR_Dir1_cm;
	uint16_t Sig_SnrDat_AOR_Dir2_cm;
	uint16_t Sig_SnrDat_AOR_Dir1_cm;
}UssCom_S_SnsDatRightSidePanelEchoesMsg_t;

#if(QAC_WARNING_FIX == ME_FALSE)
typedef struct UssCom_S_Firing_Sequence_s
{
	uint8_t Sig_Current_Firing_Sequence;
}UssCom_S_Firing_Sequence_t;
#endif
typedef struct UssCom_S_SystemStatusOutputBuff_s
{
    uint32_t timestamp;
    UssCom_E_BumperState_t bumperStatus[USSCOM_BUMPLOC_MAX]; /* indexed with ME_US_E_BumperLocation_t */
    UssCom_E_SystemState_t systemStatus;

    uint16_t systemMode;  /* TBD enum */
} UssCom_S_SystemStatusOutputBuff_t;

typedef struct UssCom_S_SensorSenstivityOutputBuff_s
{
    uint8_t sensor_sensitivity[32];

} UssCom_S_SensorSenstivityOutputBuff_t;


typedef struct UssCom_S_SnsDat_EchoIndex_s
{
   unsigned char Sig_SnrDat_FSR_EchoIndex;
   unsigned char Sig_SnrDat_FOR_EchoIndex;
   unsigned char Sig_SnrDat_FIR_EchoIndex;
   unsigned char Sig_SnrDat_FIL_EchoIndex;
   unsigned char Sig_SnrDat_FOL_EchoIndex;
   unsigned char Sig_SnrDat_FSL_EchoIndex;
   unsigned char Sig_SnrDat_RSR_EchoIndex;
   unsigned char Sig_SnrDat_ROR_EchoIndex;
   unsigned char Sig_SnrDat_RIR_EchoIndex;
   unsigned char Sig_SnrDat_RIL_EchoIndex;
   unsigned char Sig_SnrDat_ROL_EchoIndex;
   unsigned char Sig_SnrDat_RSL_EchoIndex;
}UssCom_S_SnsDat_EchoIndex_t;


/*typedef union US_S_PntDebug_Union
{
     uint8_t uPntDebugData[64u];   Raw bytes for CAN FD output.
comment out     uint8_t Reserved[FOUR][SIXTEEN];
} foo_t;*/

typedef struct UssCom_S_PntDebugData_s
{
    union US_S_PntDebug_Union
    {
         uint8_t uPntDebugData[64u];  /* Raw bytes for CAN FD output.*/
#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
         US_S_PntDebugInfo_t pntDebugInfo[FOUR];
#endif
    } u;
} UssCom_S_PntDebugData_t;

typedef struct UssCom_S_SnrPowerSupply_s
{
	uint16_t uUSSPowerAMonVtg;
	uint16_t uUSSPowerBMonVtg;
	uint16_t uUSSPowerCMonVtg;
	uint16_t uUSSPowerIS1Current;
	uint16_t uUSSPowerIS2Current;
	uint16_t Reserved;           /*Reserved for Padding*/
}UssCom_S_SnrPowerSupply_t;

typedef struct UssCom_S_OdometryData_s
{
    float32_t dx_m;
    float32_t dy_m;
    float32_t dyaw_rad;
    uint32_t timestamp_s;
	float32_t m_Global_dyaw_rad;
}UssCom_S_OdometryData_t;

typedef struct UssMgr_s_OutputSignals_s
{
	/*Revian Specific Data starts*/

    /* Oddometry */
	UssCom_S_OdometryData_t UssOddometry_v;
    /* Point Dist */
	US_S_PointDistOutputBuff_t sPointDistOutputBuff;

    /* Controller */
	US_ME_FiringSensorsOutputBuff_t sFiringSensors;
	US_ME_SensorFiringModeOutputBuff_t sFiringMode;
    /* Point Map */
	US_S_PointMapOutputBuff_t sPointMapOutputBuff;
	US_S_Firing_Sequence_t sFiringSequence;

    /* Object Map */
	UssCom_S_ObjectMapOutputBuff_t sObjectMapOutputBuff;

    /* Zone Info */
	US_S_ZoneInfo_t sZoneInfo;

    /* Blockage */
	US_S_BlockageBit_t sBlockageFlags;

    /* Diagnostics */
	US_S_DiagnosticsOutputBuff_t sDiagnostics;
    /*Rivian Specific Data End*/
    /* Sys Status */
    UssCom_S_SystemStatusOutputBuff_t sSysStatus;

    /* Sensor sensitivity */
    UssCom_S_SensorSenstivityOutputBuff_t sSnrSensitivity;

    /*Amazon/Core Specific Data starts*/
    /* TEST DATA STRUCT */
    UssCom_S_TestDataCluster_t sTestData;
    /*Amazon/core  Specific Data starts*/

    /*Amazon/Core Message Data*/
    UssCom_S_SnsDat_EchoIndex_t           sSnsDat_EchoIndex_v;/*0x19*/
    US_S_SnsDat_Front_Indirect_2_t    sSnsDat_Front_Indirect_2_v;/*1A*/
    US_S_SnsDat_Rear_Indirect_2_t     sSnsDat_Rear_Indirect_2_v;	/*1B*/
    US_S_SnsDat_Front_Indirect_1_t    sSnsDat_Front_Indirect_1_v;/*0x1E*/
    US_S_SnsDat_Rear_Indirect_1_t     sSnsDat_Rear_Indirect_1_v;/*0x1F*/


    US_ME_SnsDat_Front_Direct_t        sSnsDat_Front_Direct_v;   	/*3A*/
    US_ME_SnsDat_Front_Direct_2_t      sSnsDat_Front_Direct_2_v;  /*2A*/
    US_ME_SnsDat_FrontPSM_Echoes_t     sSnsDat_FrontPSM_Echoes_v;/*2D*/
    US_ME_SnsDat_Rear_Direct_t         sSnsDat_Rear_Direct_v;		/*3B*/
    US_ME_SnsDat_Rear_Direct_2_t       sSnsDat_Rear_Direct_2_v;	/*2B*/
    US_ME_SnsDat_RearSide_Echoes_t     sSnsDat_RearSide_Echoes_v;/*2E*/

    /*Side Panel sensor Echoes for Rivian*/
    UssCom_S_SnsDatLeftSidePanelEchoesMsg_t sSnsDat_LeftSidePanel_Echoes_v;
    UssCom_S_SnsDatRightSidePanelEchoesMsg_t sSnsDat_RightSidePanel_Echoes_v;

    /*Data collection Specific Data start*/
    /*Data collection Buffers for Debug messages*/
	US_S_USSDataCollectionData_t USSDataCollectionData;
	 /*Data collection Specific Data End*/

	/*Debug message data*/
	US_S_DebugMsg_t  sDebugMsg_v ;


	UssCom_S_SnrPowerSupply_t sSnrPowerSupply;


	UssCom_S_PntDebugData_t sPntDebugData[FOUR];  /* Four CAN FD messages.*/

} UssMgr_s_OutputSignals_t;

extern UssMgr_s_OutputSignals_t UssCom_sOutputBufferCopy, UssCom_sOutputBuffer;
#ifdef US_D_ENABLE_OVERWRITE_DEBUG_VER_2_X
typedef struct UssDBG_extradata_s
{
    uint32_t uSendingSensors;
    uint32_t uReceivedSensors;
    uint16_t u1stEchoDirDist[US_D_MAX_NUM_SENSORS];
    uint16_t u1stEchoTotalDist[US_D_MAX_NUM_SENSORS];
    uint16_t u3rdEchoTotalDist[US_D_MAX_NUM_SENSORS];
    uint16_t u2ndEchoDirDist[US_D_MAX_NUM_SENSORS];
    uint16_t u3rdEchoDirDist[US_D_MAX_NUM_SENSORS];
    uint16_t u2ndEchoTotalDist[US_D_MAX_NUM_SENSORS];
    uint16_t u2ndEchoStr[US_D_MAX_NUM_SENSORS];
    uint16_t u3rdEchoStr[US_D_MAX_NUM_SENSORS];
    uint16_t u1stEchoWidth[US_D_MAX_NUM_SENSORS];
    uint16_t u2ndEchoWidth[US_D_MAX_NUM_SENSORS];
    uint16_t u3rdEchoWidth[US_D_MAX_NUM_SENSORS];
    uint8_t  u1stEchoLarge[US_D_MAX_NUM_SENSORS];
    uint8_t  u2ndEchoLarge[US_D_MAX_NUM_SENSORS];
} UssDBG_ExtraData_t;

extern UssDBG_ExtraData_t UssDBG_Buffer;
#endif

void USSCom_F_OutputDataBuffer_v(void);

/* Output Buffer Data Protection */
bool_t UssCom_LockOutputDataBuffer(void);
void UssCom_UnlockOutputDataBuffer(void);

/*Interfaces to populate the output Buffer*/
void UssCom_F_PopulateZoneInfo(uint32_t uTimestamp, uint8_t *paZoneInfo);
void UssCom_F_PopulateFiringSensors(void);
void UssCom_F_PopulateBlockageBit(uint32_t uTimestamp);
void UssCom_F_PopulateHardwareDiagnosticsInfo(uint32_t uTimestamp,
                                              uint32_t uHardwareFaultBitMap,
                                              uint32_t uCommFaultInfoBitMap,
                                              uint32_t uCommUnknownBitMap,
                                              uint32_t uOverTempFaultBitMap);
void UssCom_F_PopulateFiringModeInfo(uint32_t timestamp, uint8_t sensorFiringMode);
void UssCom_F_PopulatePointMap(US_S_PointMap_t *psPointMap);
void UssCom_ClearTestDataOutputs(void);

#ifdef DEBUG_VISUAL_TOOL_CAN_MSGS_ENABLE
void UssCom_F_PopulateDebugPntInfo(US_S_PntDebugInfo_t *psDebugPntInfo);
#endif
void UssCom_F_PopulateDebugMsg(void);
void UssCom_F_PopulatePointDist(uint32_t uTimestamp, uint16_t *uPntMinDist, uint16_t *uPntMidDist);
void UssCom_F_PopulateSystemStatusInfo(uint32_t uTimestamp);
void UssCom_F_PopulateTestData(void);
void UssCom_PopulateLogData(void);
void UssCom_PopulateOdometry(float32_t fDx, float32_t fDy, float32_t fDyaw_rad, float32_t fTimestamp_s);


void UssCom_F_PopulateFiringSequence(void);

bool_t UssCom_F_IsNewDataAvailable(void);
void UssCom_F_ClearNewDataFlag(void);
bool_t UssCom_F_Get_OutDataCopiedFlag(void);
void UssCom_F_Clr_OutDataCopiedFlag(void);

/*Debug Value Interface functions*/
void  UssCom_F_PopulateDebugSignedSignal_1(sint16_t value);
void  UssCom_F_PopulateDebugSignedSignal_2(sint16_t value);
void  UssCom_F_PopulateDebugSignedSignal_3(sint16_t value);
void  UssCom_F_PopulateDebugSignedSignal_4(sint16_t value);
void  UssCom_F_PopulateDebugUnsignedSignal_5(uint16_t value);
void  UssCom_F_PopulateDebugUnsignedSignal_6(uint16_t value);
void  UssCom_F_PopulateDebugUnsignedSignal_7(uint16_t value);
void  UssCom_F_PopulateDebugUnsignedSignal_8(uint16_t value);
void UssCom_F_PopulateSensorSensitivityFlagList(void);

#endif /* USSMGR_US_MGROUTPUTBUFF_H_ */
