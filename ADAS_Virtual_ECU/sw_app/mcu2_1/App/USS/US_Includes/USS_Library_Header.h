/*
 * USS_Library_Header.h
 *
 *  Created on: Jul 16, 2021
 *      Author: e39960
 */

#ifndef INCLUDES_MAGNA_HEADER_H_
#define INCLUDES_MAGNA_HEADER_H_

/*shared file with ECU Application .h*/
#include "US_ME_Typedefs_Global.h"
#include "US_Platform_Global.h"

/**Note : Following MACRO needs to in-line with COM_CONFIG_TX_MSG_MAX in file 'US_Com_Types_Global.h'*/
#define ME_US_TX_MSG_MAX  42

/*This Macro is to enable the CAN output on CAN 0 for testing the shared data*/
#define US_MAGNA_CAN_ENABLE

#define US_COM_D_INPUT_DATA_PERIODICITY									(4U)  /*40 msec = 4*10 */
/*Periodicity of for Callback function invocation*/
#define US_COM_D_POINTMAP_PERIODICITY         	(10U)		/*100msec = 10*10*/
#define US_COM_D_OBJECTMAP_PERIODICITY         	(20U)		/*200msec = 20*10*/
#define US_COM_D_ZONEINFO_PERIODICITY         	(10U)		/*100msec = 20*10*/
#define US_COM_D_SNR_FIRING_MODE_PERIODICITY    (20U)		/*TBD: 200msec = 20*10*/
#define US_COM_D_DIAGNOSTICS_PERIODICITY        (2U)		/*TBD : 20msec = 20*10*/
#define US_COM_D_MINSNRDIST_PERIODICITY			(4U)		/*40 msec = 4*10 */
#define US_COM_D_BLOCKAGE_PERIODICITY			(4U)		/*TBD : 200 msec = 20*10 */
#define US_COM_D_FIRING_SENSOR_PERIODICITY		(4U)		/*TBD : 40 msec = 20*10 */


#define REVIAN_MAX_SENSORS                                              (16U)


#define  US_COM_D_POINTMAP_SIZE                                         (96U)
#define  US_COM_D_OBJECTTMAP_SIZE                                       (48U)
#define  US_COM_D_ZONEINFO_SIZE                                         REVIAN_MAX_SENSORS
#define  US_COM_D_SNR_FIRING_MODE_SIZE                                  (1U)                    /*4bit
                                                                                                   overall*/
#define  US_COM_D_DIAGNOSTICS_SIZE                                      REVIAN_MAX_SENSORS


/*Indices for Output data Buffer*/
typedef enum
{
    ME_US_PointMapOutputBuffIndex = 0,
    ME_US_PointDistOutputBuffIndex,
    ME_US_CurrentFiringSnrOutputBuffIndex,
    ME_US_SensorFiringModeOutputBuffIndex,
    ME_US_ObjectMapOutputBuffIndex,
    ME_US_ZoneInfoOutputBuffIndex,
    ME_US_BlockageBitOutputBuffIndex,
    ME_US_DiagnosticsOutputBuffIndex,
    ME_US_MaxOutputBuffIndex,
} OutputBuffIndex_t;

/*Indices for Input data Buffer*/
typedef enum
{
    ME_US_StatusInputBuffIndex = 0,
    ME_US_DiagnosticsInputBuffIndex,
    ME_US_NextFiringModeInputBuffIndex,
    ME_US_Max_InputBuffIndex
} InputBuffIndex_t;

/*Data Type for Data copy results*/
typedef enum
{
    COPY_SUCCESSFUL = 0,
    COPY_UNSUCCESSFUL,
    BUFFER_BUSY
} BuffCopyResult_t;

/*callback function datatype*/
typedef BuffCopyResult_t (*fnPtrBuffDataCopy_t)(uint8_t *data);

/***********************************************Output Buffer Data structure**************************************/
typedef struct ME_US_S_PointOutputBuff_s
{
    sint16_t x;
    sint16_t y;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
    uint8_t  Reserved;
} ME_US_S_PointOutputBuff_t;

typedef struct ME_US_PointsMapOutputBuff_s
{
    uint32_t timestamp;
    ME_US_S_PointOutputBuff_t pointMap[96];
} ME_US_PointMapOutputBuff_t;

typedef struct ME_US_PointDistOutputBuff_s
{
    uint32_t timestamp;
    uint16_t minDist[16];
    uint16_t midDist[12];
} ME_US_PointDistOutputBuff_t;

typedef struct ME_US_FiringSensorsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t firingSensors;
	uint16_t Rsv;
} ME_US_FiringSensorsOutputBuff_t;

typedef struct ME_US_SensorFiringModeOutputBuff_s
{
    uint32_t timestamp;
    uint8_t  sensorFiringMode;
	uint8_t Rsv[3];
} ME_US_SensorFiringModeOutputBuff_t;

typedef struct ME_US_ObjectDetOutputBuff_s
{
    sint16_t centerX;
    sint16_t centerY;
    sint16_t closeX;
    sint16_t closeY;
    uint8_t  height;
    uint8_t  confidence;
    uint8_t  age;
    uint8_t  diameter;
} ME_US_ObjectDetOutputBuff_t;

typedef struct US_S_ObjList_s
{
    uint32_t timestamp;
    ME_US_ObjectDetOutputBuff_t objects[48];
} ME_US_ObjectMapOutputBuff_t;


typedef struct ME_US_ZoneInfoOutputBuff_s
{
    uint32_t timestamp;
    uint8_t  zoneInfo[SIXTEEN];
} ME_US_ZoneInfoOutputBuff_t;


typedef struct ME_US_BlockageBitOutputBuff_s
{
    uint32_t timestamp;
    uint16_t blockageFlagBits;
	uint16_t Rsv;
} ME_US_BlockageBitOutputBuff_t;

typedef struct ME_US_DiagnosticsOutputBuff_s
{
    uint32_t timestamp;
    uint16_t overTempFault;
    uint16_t commFault;
    uint16_t commUnknown;
    uint16_t hardwareFault;
} ME_US_DiagnosticsOutputBuff_t;


/***********************************************Input Buffer Data structure***************************************/

/*Status data structure*/
typedef struct {
	uint8_t aBCM_bodyStatus[5];
	uint8_t aBCM_bodyStatusStorage[6];
	uint8_t aBCM_EnvironmentStatus[3];
	uint8_t aCGM_adasCstmzSettings[8];
	uint8_t aCGM_clusterInfo[5];
	uint8_t aESP_Status[8];
	uint8_t aESP_Wheel_Pulse[8];
	uint8_t aESP_WSpeed_Front[8];
	uint8_t aESP_WSpeed_Rear[8];
	uint8_t aRCM_IMU_LatAccYaw[8];
	uint8_t aRCM_IMU_LongAcc[8];
	uint8_t aSAS_Status[8];
	uint8_t aVDM_PropStatus[7];
	uint8_t aVehSts[8];
	uint8_t aMPA_FeatureStatus[4];
}ME_US_StatusInputBuff_t;

/*input diagnostics data structure*/
typedef struct {
	uint8_t uPamHWFault;
	uint8_t uCANComFailure;
	uint8_t uSPICANFault;
	uint8_t uMemoryFault;
	uint8_t uDataFault;
}ME_US_DiagnosticsInputBuff_t;

/*Next Mode data structure*/
typedef struct{
	uint8_t uNextMode;
}ME_US_NextFiringModeInputBuff_t;

/********************************************Data Sharing Semaphore**********************************/

extern US_SemaphoreHandle_t US_DistPointMapDataShare_xSemaphore;

/*API provided to ECU Application*/
/* void ME_US_F_RegisterDataCopyCallBack(OutputBuffIndex_t BuffIndex, fnPtrBuffDataCopy_t AppBuffCopyFunction); */
void ME_US_UpdateInputBuff(InputBuffIndex_t BuffIndex,uint8_t* data);

void ME_US_UpdateInputBuff(
    InputBuffIndex_t BuffIndex,
    uint8_t* data);

/* create tasks for USS */
extern void Magna_Tasks_Create( void );

/* DCR ISR */
extern void GPIO_Int8_Dev0_DCR1B(void);
extern void GPIO_Int9_Dev1_DCR1B(void);
extern void GPIO_Int10_Dev1_DCR2B(void);
extern void GPIO_Int11_Dev0_DCR2B(void);

/* intB ISR */
extern void GPIO_Int6_Dev0_INTB(void);
extern void GPIO_Int7_Dev1_INTB(void);
/* DMA complete CALL back */
extern void DMA_Complete_Callback(uint8_t dev);
extern uint32_t US_uGetnumberofSensorsonbus(void);

uint8_t* US_Get_Library_Rev(void);
extern void US_SystemInit(void);
extern void US_SystemCfg(void);
extern void US_DrvTask(void);
extern void US_ControllerTask(void);
extern void US_MgrAndODTask(void);
extern void US_InputOutputBuff_Task(void);
#endif /* INCLUDES_MAGNA_HEADER_H_ */
