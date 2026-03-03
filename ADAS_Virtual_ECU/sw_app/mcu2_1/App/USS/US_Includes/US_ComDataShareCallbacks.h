#ifndef US_COMDATASHARE_H
#define US_COMDATASHARE_H

#define US_COM_D_INPUT_DATA_PERIODICITY									(4U)

#include "US_ComInputBuffer_Global.h"
#include "USS_Library_Header.h"
typedef enum
{
    VDM_Prndl_Status_Not_Defined =  0x00,
    VDM_Prndl_Status_Park        =  0x01,
    VDM_Prndl_Status_Reverse     =  0x02,
    VDM_Prndl_Status_Neutral     =  0x03,
    VDM_Prndl_Status_Drive       =  0x04,
} VDM_Prndl_Status_e;

typedef struct BCM_EnvironmentStatus_0x247
{
    float    BCM_AmbientAirTemperature;
    uint64_t OneMsCounter;
} BCM_EnvironmentStatus_0x247;

typedef struct VDM_PropStatus_0x150
{
    uint8_t                         VDM_PropStatus_Checksum;
  //  VDM_VehicleSpeedQ_e             VDM_VehicleSpeedQ;
 //   VDM_PropsnActv_e                VDM_PropsnActv;
    uint8_t                         VDM_PropStatus_Counter;
 //   VDM_Prndl_Request_e             VDM_Prndl_Request;
    US_E_App_Prndl_Status_e              VDM_Prndl_Status;
    float                           VDM_AcceleratorPedalPosition;
 //   VDM_AcceleratorPedalPositionQ_e VDM_AcceleratorPedalPositionQ;
    float                           VDM_VehicleSpeed;
    uint64_t                        OneMsCounter;
} VDM_PropStatus_0x150;

typedef struct{
	OutputBuffIndex_t buffIndex; // May not need at this point of time
	uint8_t CallbackPeriodicity;
	fnPtrBuffDataCopy_t fnPtrBuffDataCopy;
}sBuffCallback_t;

/*definition of shared Output data buffers */
//extern ME_US_PointMapOutputBuff_t sUS_PointsMapOutputBuff;
extern ME_US_ObjectMapOutputBuff_t sUS_ObjectMapOutputBuff;

/*definition of shared Input data buffers */
void US_ComShareOutputBuff(void *Data);
void UssCom_F_OutputDataShareMain(void);
void UssCom_F_InputDataShareMain(void);
//void US_ComSharePointsMapOutputBuff(ME_US_PointMapOutputBuff_t * sDistPointmap);
void US_ComShareObjectMapOutputBuff(ME_US_ObjectMapOutputBuff_t* vObjectmap);
void US_ComShareZoneInfoOutputBuff(ME_US_ZoneInfoOutputBuff_t* uZoneInfo);
void US_ComShareSensorFiringModeOutputBuff(ME_US_SensorFiringModeOutputBuff_t* sFiringMode);
void US_ComShareDiagOutputBuff(ME_US_DiagnosticsOutputBuff_t* sDiagnostics);
void US_ComShareBlockageBitOutputBuff(ME_US_BlockageBitOutputBuff_t* uSensorblockBit);
void US_ComSharePointDistOutputBuff(ME_US_PointDistOutputBuff_t* psPointDist);
void US_ComShareFiringSensorsOutputBuff(ME_US_FiringSensorsOutputBuff_t * sFiringSensors);
//void US_ComSharePointMapOutputBuff(ME_US_PointMapOutputBuff_t* psDistPointmap);
void ME_US_F_RegisterDataCopyCallBackInput(void);

#endif
